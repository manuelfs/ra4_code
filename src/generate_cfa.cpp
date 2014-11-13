#include "generate_cfa.hpp"

#include <stdexcept>
#include <string>
#include <vector>
#include <fstream>

#include "TLeafObject.h"
#include "TChain.h"

namespace{
  std::string AllCaps(std::string str){
    for(std::string::iterator it = str.begin();
	it != str.end();
	++it){
      *it = toupper(*it);
    }
    return str;
  }
}

Variable::Variable():
  name_(),
  to_type_(),
  from_type_(),
  from_chain_a_(){
}

Variable::Variable(const std::string &name, const bool from_chain_a,
		   const std::string &to_type, const std::string &from_type):
  name_(name),
  to_type_(to_type),
  from_type_(from_type),
  from_chain_a_(from_chain_a){
  }

Variable::Variable(const std::string &name, const bool from_chain_a,
		   const std::string &to_type):
  name_(name),
  to_type_(to_type),
  from_type_(""),
  from_chain_a_(from_chain_a){
  }

const std::string &Variable::Name() const{
  return name_;
}

Variable &Variable::Name(const std::string &name){
  name_=name;
  return *this;
}

const std::string &Variable::FromType() const{
  return from_type_;
}

Variable &Variable::FromType(const std::string &from_type){
  from_type_=from_type;
  return *this;
}

const std::string &Variable::ToType() const{
  return to_type_;
}

Variable &Variable::ToType(const std::string &to_type){
  to_type_=to_type;
  return *this;
}

const bool &Variable::FromChainA() const{
  return from_chain_a_;
}

Variable &Variable::FromChainA(const bool from_chain_a){
  from_chain_a_=from_chain_a;
  return *this;
}

bool Variable::Converted() const{
  return from_type_!="" && from_type_!=to_type_;
}

void GetVariables(TChain &chain, const bool is_chain_a,
		  const size_t file, const size_t num_files,
		  Dictionary &vars){
  if(file>=num_files) throw std::logic_error("Bad file number");
  for(int i = 0; i < chain.GetListOfLeaves()->GetSize(); ++i){
    std::string type_name(static_cast<TLeafObject*>((chain.GetListOfLeaves()->At(i)))->GetTypeName());
    const std::string var_name(static_cast<TLeaf*>((chain.GetListOfLeaves()->At(i)))->GetBranch()->GetName());

    //Vector and strings need special treatment
    bool needs_ptr(false);
    for(size_t j(type_name.find("vector"));
	j!=std::string::npos;
	j=type_name.find("vector",j+6)){
      type_name.replace(j,6,"std::vector");
      needs_ptr=true;
    }
    for(size_t j(type_name.find("string"));
	j!=std::string::npos;
	j=type_name.find("string",j+6)){
      type_name.replace(j,6,"std::string");
      needs_ptr=true;
    }
    if(needs_ptr) type_name = type_name + "*";

    if(vars.find(var_name) == vars.end()){
      //Need to make the vector the right size
      typedef std::vector<std::pair<bool, std::string> > OneVar;
      typedef std::pair<std::string, OneVar > Inserter;
      vars.insert(Inserter(var_name, OneVar(num_files)));
    }

    if(vars[var_name].size()!=num_files){
      throw std::logic_error("Number of files does not match.");
    }

    if(vars[var_name].at(file)!=std::pair<bool, std::string>(false, "")
       && vars[var_name].at(file)!=std::pair<bool, std::string>(is_chain_a, type_name)){
      throw std::runtime_error("Conflicting definition found for "
			       +type_name+" "+var_name+" in this file.");
    }

    vars[var_name].at(file)=std::pair<bool, std::string>(is_chain_a, type_name);
  }
}

void ClassifyVariables(const Dictionary &all_vars,
		       std::vector<Variable> &base_vars, std::vector<Variable> &virtual_vars,
		       std::vector<std::vector<Variable> > &file_vars){
  file_vars.clear();
  if(all_vars.size()) file_vars.resize(all_vars.begin()->second.size());
  for(Dictionary::const_iterator var = all_vars.begin(); var!= all_vars.end(); ++var){
    const std::string &name = var->first;
    if(var->second.size() == 0) throw std::logic_error("No variable definitions found!");

    const bool base_is_chain_a = var->second.at(0).first;
    std::string best_type = var->second.at(0).second;

    bool all_same_chain = true, all_same_type = true;
    for(size_t idef = 0; idef < var->second.size(); ++idef){
      const bool this_is_chain_a = var->second.at(idef).first;
      const std::string this_type = var->second.at(idef).second;

      if(this_is_chain_a!=base_is_chain_a){
	all_same_chain = false;
      }

      if(this_type != best_type){
	all_same_type = false;
	if(best_type == ""){
	  best_type = this_type;
	}else if(this_type==""){
	  //Don't need to do anything
	}else if((best_type=="std::vector<float>*" && this_type=="std::vector<bool>*")
		 || (best_type=="std::vector<bool>*" && this_type=="std:vector<float>*")){
	  best_type = "std::vector<bool>*";
	}else{
	  throw std::runtime_error("Unknown type preference.");
	}
      }
    }
  
    if(all_same_chain && all_same_type){
      base_vars.push_back(Variable(name, base_is_chain_a, best_type));
    }else{
      //Don't care which chain for virtual function declarations, so just use true
      virtual_vars.push_back(Variable(name, true, best_type));

      for(size_t idef = 0; idef < var->second.size(); ++idef){
	const bool this_is_chain_a = var->second.at(idef).first;
	const std::string this_type = var->second.at(idef).second;
      
	if(this_type != ""){
	  Variable this_var(name, this_is_chain_a, best_type, this_type);
	  file_vars.at(idef).push_back(this_var);
	}
      }
    }
  }
}

void WriteBaseHeader(const std::vector<Variable> &base_vars,
		     const std::vector<Variable> &virtual_vars){
  std::ofstream hpp_file("inc/cfa_base.hpp");
  hpp_file << "#ifndef H_CFA_BASE\n";
  hpp_file << "#define H_CFA_BASE\n\n";

  hpp_file << "#include <vector>\n";
  hpp_file << "#include <string>\n\n";
  hpp_file << "#include <iostream>\n\n";
  
  hpp_file << "#include \"TChain.h\"\n\n";

  hpp_file << "class cfa_base{\n";
  hpp_file << "public:\n";
  hpp_file << "  explicit cfa_base(const std::string &file);\n\n";

  hpp_file << "  long TotalEntries() const;\n";
  hpp_file << "  virtual void GetEntry(const long entry);\n";
  hpp_file << "  short GetVersion() const;\n";
  hpp_file << "  const std::string& SampleName() const;\n";
  hpp_file << "  const std::string& SampleName(const std::string &sample_name);\n";
  hpp_file << "  void SetFile(const std::string &file_name);\n";
  hpp_file << "  void AddFiles(const std::string& files);\n\n";

  hpp_file << "  virtual ~cfa_base();\n\n";

  //Print accessor function declarations for variables common to all cfA versions
  for(std::vector<Variable>::const_iterator var = base_vars.begin();
      var != base_vars.end();
      ++var){
    if(var->Converted()){
      throw std::logic_error("Should not have converted variables in base class");
    }
    hpp_file << "  " << var->ToType() << " const & " << var->Name() << "() const;\n";
  }
  hpp_file << '\n';
  

  //Print accessor function declarations for variables that change across cfA versions
  for(std::vector<Variable>::const_iterator var = virtual_vars.begin();
      var != virtual_vars.end();
      ++var){
    hpp_file << "  __attribute__((noreturn)) virtual " << var->ToType() << " const & "
	     << var->Name() << "() const;\n";
  }
  hpp_file << '\n';
 
  hpp_file << "protected:\n";
  hpp_file << "  void PrepareNewChains();\n";
  hpp_file << "  virtual void InitializeA();\n";
  hpp_file << "  virtual void InitializeB();\n\n";

  hpp_file << "  mutable TChain chainA_;\n";
  hpp_file << "  mutable TChain chainB_;\n";
  hpp_file << "  long entry_;\n\n";

  hpp_file << "private:\n";
  hpp_file << "  void CalcVersion();\n\n";

  hpp_file << "  std::string sample_name_;\n";
  hpp_file << "  mutable long total_entries_;\n";
  hpp_file << "  short cfa_version_;\n";
  hpp_file << "  mutable bool cached_total_entries_;\n\n";

  for(std::vector<Variable>::const_iterator var = base_vars.begin();
      var != base_vars.end();
      ++var){
    hpp_file << "  mutable " << var->ToType() << ' ' << var->Name() << "_;\n";
    if(var->Converted()){
      throw std::runtime_error("Converted variable in base class.");
    }
    hpp_file << "  mutable TBranch *b_" << var->Name() << "_;\n";
    hpp_file << "  mutable bool c_" << var->Name() << "_;\n";
  }
  hpp_file << '\n';

  hpp_file << "};\n\n";

  hpp_file << "#endif\n";

  hpp_file.close();
}

void WriteBaseSource(const std::vector<Variable> &base_vars,
		     const std::vector<Variable> &virtual_vars){
  std::ofstream cpp_file("src/cfa_base.cpp");

  cpp_file << "#include \"cfa_base.hpp\"\n\n";

  cpp_file << "#include <string>\n";
  cpp_file << "#include <vector>\n";
  cpp_file << "#include <sstream>\n";
  cpp_file << "#include <stdexcept>\n\n";

  cpp_file << "#include \"TChain.h\"\n\n";

  cpp_file << "cfa_base::cfa_base(const std::string &file):\n";
  cpp_file << "  chainA_(\"chainA\"),\n";
  cpp_file << "  chainB_(\"chainB\"),\n";
  cpp_file << "  sample_name_(file),\n";
  cpp_file << "  total_entries_(0),\n";
  cpp_file << "  cfa_version_(-1),\n";
  if(base_vars.size()){
    cpp_file << "  cached_total_entries_(false),\n";
    std::vector<Variable>::const_iterator last(base_vars.end());
    --last;
    for(std::vector<Variable>::const_iterator var = base_vars.begin();
	var != last;
	++var){
      cpp_file << "  " << var->Name() << "_(0),\n";
      if(var->Converted()){
	cpp_file << "  v_" << var->Name() << "_(0),\n";
      }
      cpp_file << "  b_" << var->Name() << "_(NULL),\n";
      cpp_file << "  c_" << var->Name() << "_(false),\n";
    }
    cpp_file << "  " << base_vars.back().Name() << "_(0),\n";
    if(base_vars.back().Converted()){
      cpp_file << "  v_" << base_vars.back().Name() << "_(0),\n";
    }
    cpp_file << "  b_" << base_vars.back().Name() << "_(NULL),\n";
    cpp_file << "  c_" << base_vars.back().Name() << "_(false){\n";
  }else{
    cpp_file << "  cached_total_entries_(false){\n";
  }
  cpp_file << "  GetVersion();\n";
  cpp_file << "  AddFiles(file);\n";
  cpp_file << "  PrepareNewChains();\n";
  cpp_file << "}\n\n";

  cpp_file << "long cfa_base::TotalEntries() const{\n";
  cpp_file << "  if(!cached_total_entries_){\n";
  cpp_file << "    const long nEntriesA(chainA_.GetEntries()), nEntriesB(chainB_.GetEntries());\n";
  cpp_file << "    if (nEntriesA!=nEntriesB){\n";
  cpp_file << "      total_entries_=-1;\n";
  cpp_file << "    }else{\n";
  cpp_file << "      total_entries_=nEntriesA;\n";
  cpp_file << "    }\n";
  cpp_file << "    cached_total_entries_=true;\n";
  cpp_file << "  }\n";
  cpp_file << "  return total_entries_;\n";
  cpp_file << "}\n\n";

  cpp_file << "void cfa_base::GetEntry(const long entry){\n";
  cpp_file << "  const long entry_a = chainA_.LoadTree(entry);\n";
  cpp_file << "  const long entry_b = chainB_.LoadTree(entry);\n";
  cpp_file << "  if(entry_a!=entry_b) throw std::runtime_error(\"Entry is in different trees for chains A and B\");\n";
  cpp_file << "  entry_ = entry_a;\n";
  //Reset cache
  for(std::vector<Variable>::const_iterator var = base_vars.begin();
      var != base_vars.end();
      ++var){
    cpp_file << "  if(b_" << var->Name() << "_ && !b_"
	     << var->Name() << "_->TestBit(kDoNotProcess)){\n";
    cpp_file << "    c_" << var->Name() << "_ = true;\n";
    cpp_file << "  }else{\n";
    cpp_file << "    c_" << var->Name() << "_ = false;\n";
    cpp_file << "  }\n";
  }
  cpp_file << "  chainA_.GetEntry(entry);\n";
  cpp_file << "  chainB_.GetEntry(entry);\n";
  cpp_file << "}\n\n";

  cpp_file << "short cfa_base::GetVersion() const{\n";
  cpp_file << "  return cfa_version_;\n";
  cpp_file << "}\n\n";

  cpp_file << "const std::string& cfa_base::SampleName() const{\n";
  cpp_file << "  return sample_name_;\n";
  cpp_file << "}\n\n";

  cpp_file << "const std::string& cfa_base::SampleName(const std::string &sample_name){\n";
  cpp_file << "  sample_name_=sample_name;\n";
  cpp_file << "  return sample_name_;\n";
  cpp_file << "}\n\n";

  cpp_file << "void cfa_base::SetFile(const std::string &file_name){\n";
  cpp_file << "  cached_total_entries_=false;\n";
  cpp_file << "  chainA_.Reset(); chainB_.Reset();\n";
  cpp_file << "  AddFiles(file_name);\n";
  cpp_file << "}\n\n";

  cpp_file << "cfa_base::~cfa_base(){\n";
  cpp_file << "}\n\n";

  cpp_file << "void cfa_base::CalcVersion(){\n";
  cpp_file << "  size_t pos = sample_name_.rfind(\"_v\");\n";
  cpp_file << "  if(pos != std::string::npos && pos < sample_name_.size()-2){\n";
  cpp_file << "    std::istringstream iss(sample_name_.substr(pos+2));\n";
  cpp_file << "    iss >> cfa_version_;\n";
  cpp_file << "    if(iss.fail() || iss.bad()){\n";
  cpp_file << "      cfa_version_ = -1;\n";
  cpp_file << "    }\n";
  cpp_file << "  }\n";
  cpp_file << "}\n\n";

  cpp_file << "void cfa_base::AddFiles(const std::string &file_name){\n";
  cpp_file << "  cached_total_entries_=false;\n";
  cpp_file << "  chainA_.Add((file_name+\"/configurableAnalysis/eventA\").c_str());\n";
  cpp_file << "  chainB_.Add((file_name+\"/configurableAnalysis/eventB\").c_str());\n";
  cpp_file << "}\n\n";
  
  cpp_file << "void cfa_base::PrepareNewChains(){\n";
  cpp_file << "  InitializeA();\n";
  cpp_file << "  InitializeB();\n";
  cpp_file << "}\n\n";

  cpp_file << "void cfa_base::InitializeA(){\n";
  cpp_file << "  chainA_.SetMakeClass(true);\n";
  cpp_file << "  chainA_.SetBranchStatus(\"*\",0);\n";
  //Set chainA branch addresses
  for(std::vector<Variable>::const_iterator var = base_vars.begin();
      var != base_vars.end();
      ++var){
    
    if(var->FromChainA()){
      cpp_file << "  chainA_.SetBranchAddress(\"" << var->Name() << "\", &"
	       << var->Name() << "_, &b_" << var->Name() << "_);\n";
      if(var->Converted()){
	cpp_file << "  chainA_.SetBranchAddress(\"" << var->Name() << "\", &v_" 
		 << var->Name() << "_, &b_" << var->Name() << "_);\n";
      }
    }
  }
  cpp_file << "}\n\n";

  cpp_file << "void cfa_base::InitializeB(){\n";
  cpp_file << "  chainB_.SetMakeClass(true);\n";
  cpp_file << "  chainB_.SetBranchStatus(\"*\",0);\n";
  //Set chainB branch addresses
  for(std::vector<Variable>::const_iterator var = base_vars.begin();
      var != base_vars.end();
      ++var){

    if(!var->FromChainA()){
      cpp_file << "  chainB_.SetBranchAddress(\"" << var->Name() << "\", &"
	       << var->Name() << "_, &b_" << var->Name() << "_);\n";
      if(var->Converted()){
	cpp_file << "  chainB_.SetBranchAddress(\"" << var->Name() << "\", &v_" 
		 << var->Name() << "_, &b_" << var->Name() << "_);\n";
      }
    }
  }
  cpp_file << "}\n\n";

  //Write implementation for common variable accessors
  for(std::vector<Variable>::const_iterator var = base_vars.begin();
      var != base_vars.end();
      ++var){
    if(var->Converted()){
      throw("Should not have converted variables in base class");
    }
    PrintAccessor(*var, cpp_file, "cfa_base");
  }

  //Write virtual base for variables differing across cfA versions
  for(std::vector<Variable>::const_iterator var = virtual_vars.begin();
      var!=virtual_vars.end();
      ++var){
    cpp_file << var->ToType() << " const & cfa_base::" << var->Name() << "() const{\n";
    cpp_file << "  throw std::runtime_error(\"" << var->Name()
	     << " does not exist in this cfA version.\");\n";
    cpp_file << "}\n\n";
  }
  
  cpp_file.close();
}

void WriteDerivedHeader(const std::string &class_name,
			const std::vector<Variable> &vars){
  std::ofstream hpp_file(("inc/"+class_name+".hpp").c_str());

  hpp_file << "#ifndef H_" << AllCaps(class_name) << "\n";
  hpp_file << "#define H_" << AllCaps(class_name) << "\n\n";

  hpp_file << "#include \"cfa_base.hpp\"\n\n";

  hpp_file << "#include <vector>\n";
  hpp_file << "#include <string>\n\n";

  hpp_file << "#include \"TChain.h\"\n\n";

  hpp_file << "class " << class_name << ": public cfa_base{\n";
  hpp_file << "public:\n";
  hpp_file << "  explicit " << class_name << "(const std::string &file);\n\n";

  hpp_file << "  virtual void GetEntry(const long entry);\n\n";

  hpp_file << "  virtual ~" << class_name << "();\n\n";

  //Print accessor functions
  for(std::vector<Variable>::const_iterator var = vars.begin();
      var!=vars.end();
      ++var){
    hpp_file << "  virtual " << var->ToType() << " const & " << var->Name() << "() const;\n";
  }
  hpp_file << '\n';

  hpp_file << "private:\n";
  hpp_file << "  virtual void InitializeA();\n";
  hpp_file << "  virtual void InitializeB();\n\n";

  //Print member variables
  for(std::vector<Variable>::const_iterator var = vars.begin();
      var!=vars.end();
      ++var){
    hpp_file << "  mutable " << var->ToType() << ' ' << var->Name() << "_;\n";
    if(var->Converted()){
      hpp_file << "  mutable " << var->FromType() << " v_" << var->Name() << "_;\n";
    }
    hpp_file << "  mutable TBranch *b_" << var->Name() << "_;\n";
    hpp_file << "  mutable bool c_" << var->Name() << "_;\n";
  }
  hpp_file << "};\n\n";

  hpp_file << "#endif\n";

  hpp_file.close();
}

void WriteDerivedSource(const std::string &class_name,
			const std::vector<Variable> &vars){
  std::ofstream cpp_file(("src/"+class_name+".cpp").c_str());

  cpp_file << "#include \"" << class_name << ".hpp\"\n\n";

  cpp_file << "#include <string>\n";
  cpp_file << "#include <vector>\n";
  cpp_file << "#include <sstream>\n";
  cpp_file << "#include <stdexcept>\n\n";

  cpp_file << "#include \"TChain.h\"\n\n";

  cpp_file << class_name << "::" << class_name << "(const std::string &file):\n";
  if(vars.size()){
    cpp_file << "  cfa_base(file),\n";

    std::vector<Variable>::const_iterator last(vars.end());
    --last;
    for(std::vector<Variable>::const_iterator var = vars.begin();
	var != last;
	++var){
      cpp_file << "  " << var->Name() << "_(0),\n";
      if(var->Converted()){
	cpp_file << "  v_" << var->Name() << "_(0),\n";
      }
      cpp_file << "  b_" << var->Name() << "_(NULL),\n";
      cpp_file << "  c_" << var->Name() << "_(false),\n";
    }
    cpp_file << "  " << vars.back().Name() << "_(0),\n";
    if(vars.back().Converted()){
      cpp_file << "  v_" << vars.back().Name() << "_(0),\n";
    }
    cpp_file << "  b_" << vars.back().Name() << "_(NULL),\n";
    cpp_file << "  c_" << vars.back().Name() << "_(false){\n";
  }else{
    cpp_file << "  cfa_base(file){\n";
  }
  
  cpp_file << "  PrepareNewChains();\n";
  cpp_file << "}\n\n";

  cpp_file << "void " << class_name << "::GetEntry(const long entry){\n";
  //Reset cache
  for(std::vector<Variable>::const_iterator var = vars.begin();
      var != vars.end();
      ++var){
    const std::string chain = var->FromChainA()?"chainA_":"chainB_";
    cpp_file << "  if(b_" << var->Name() << "_ && !b_"
	     << var->Name() << "_->TestBit(kDoNotProcess)){\n";
    cpp_file << "    c_" << var->Name() << "_ = true;\n";
    cpp_file << "  }else{\n";
    cpp_file << "    c_" << var->Name() << "_ = false;\n";
    cpp_file << "  }\n";
  }
  cpp_file << "  cfa_base::GetEntry(entry);\n";
  cpp_file << "}\n\n";

  cpp_file << "void " << class_name << "::InitializeA(){\n";
  cpp_file << "  cfa_base::InitializeA();\n";
  //Set chainA branch addresses
  for(std::vector<Variable>::const_iterator var = vars.begin();
      var != vars.end();
      ++var){

    if(var->FromChainA()){
      cpp_file << "  chainA_.SetBranchAddress(\"" << var->Name() << "\", &"
	       << var->Name() << "_, &b_" << var->Name() << "_);\n";
      if(var->Converted()){
	cpp_file << "  chainA_.SetBranchAddress(\"" << var->Name() << "\", &v_" 
		 << var->Name() << "_, &b_" << var->Name() << "_);\n";
      }
    }
  }
  cpp_file << "}\n\n";

  cpp_file << "void " << class_name << "::InitializeB(){\n";
  cpp_file << "  cfa_base::InitializeB();\n";
  //Set chainB branch addresses
  for(std::vector<Variable>::const_iterator var = vars.begin();
      var != vars.end();
      ++var){

    if(!var->FromChainA()){
      cpp_file << "  chainB_.SetBranchAddress(\"" << var->Name() << "\", &"
	       << var->Name() << "_, &b_" << var->Name() << "_);\n";
      if(var->Converted()){
	cpp_file << "  chainB_.SetBranchAddress(\"" << var->Name() << "\", &v_" 
		 << var->Name() << "_, &b_" << var->Name() << "_);\n";
      }
    }
  }
  cpp_file << "}\n\n";

  cpp_file << class_name << "::~" << class_name << "(){\n";
  cpp_file << "}\n\n";

  //Define accessor functions
  for(std::vector<Variable>::const_iterator var = vars.begin();
      var != vars.end();
      ++var){
    PrintAccessor(*var, cpp_file, class_name);
  }

  cpp_file.close();
}

void AddToTypelist(const std::vector<Variable> &vars,
		   Typelist &typelist){
  for(std::vector<Variable>::const_iterator var = vars.begin();
      var != vars.end();
      ++var){
    typelist.insert(std::pair<std::string, std::string>(var->Name(), var->ToType()));
  }
}

void PrintAccessor(const Variable &var, std::ofstream &file, const std::string &class_name){
  file << var.ToType() << " const & " << class_name << "::" << var.Name() << "() const{\n";
  file << "  if(!c_" << var.Name() << "_ && b_"<< var.Name() << "_){\n";
  file << "    b_" << var.Name() << "_->SetStatus(true);\n";
  const std::string chain = var.FromChainA()?"chainA_":"chainB_";
  const std::string v = var.Converted()?"v_":"";
  file << "    " << chain << ".SetBranchAddress(\"" << var.Name() << "\", &" << v 
       << var.Name() << "_, &b_" << var.Name() << "_);\n";
  file << "    b_" << var.Name() << "_->GetEntry(entry_);\n";
  if(var.Converted()){
    if(var.FromType()=="std::vector<float>*" && var.ToType()=="std::vector<bool>*"){
      file << "    " << var.Name() << "_->resize(v_" << var.Name() << "_->size());\n";
      file << "    for(size_t i = 0; i < " << var.Name() << "_->size(); ++i){\n";
      file << "      " << var.Name() << "_->at(i) = static_cast<bool>(v_"
	   << var.Name() << "_->at(i));\n";
      file << "    }\n";
    }else{
      throw std::logic_error("Cannot write accessor for requested type conversion");
    }
  }
  file << "    c_" << var.Name() << "_ = true;\n";
  file << "  }\n";
  file << "  return " << var.Name() << "_;\n";
  file << "}\n\n";
}

void GetRules(RepList &reps){
  reps.clear();

  std::string new_word;
  std::vector<std::string> rep_list;
  std::ifstream file("txt/mux_rules.cfg");
  while(file >> new_word){
    if(new_word.find("--") != std::string::npos) break;
  }

  while(file >> new_word){
    rep_list.clear();
    //2 here is the number of cfa versions. Should improve this to use number of example files read in
    std::string temp;
    for(unsigned i = 0; i < 2 && file >> temp; ++i){
      rep_list.push_back(temp);
    }

    reps.push_back(std::make_pair(new_word, rep_list));
  }
}

void GetReplacements(const Typelist &typelist, const RepList &pats, RepMap &reps){
  reps.clear();
  //Loop over all variables
  for(Typelist::const_iterator var = typelist.begin();
      var != typelist.end();
      ++var){
    const std::string& name = var->first;
    const std::string& type = var->second;
    //Loop over replacement rules
    for(RepList::const_iterator pat = pats.begin();
        pat != pats.end();
        ++pat){
      //Loop over words to replace in this rule
      for(std::vector<std::string>::const_iterator to_match = pat->second.begin();
          to_match != pat->second.end();
          ++to_match){
        const std::string::size_type match_loc = name.find(*to_match);
        //if(match_loc != std::string::npos){ //Use this to search whole string (dangerous, maybe not working)
        if(match_loc == 0){ // Use this to search at beginning of string
          //Variable matches this replacement rule!
          const std::string prefix = name.substr(0, match_loc);
          const std::string suffix = name.substr(match_loc+to_match->size(), name.size());
          
          //Get the name of the function we're producing
          const std::string out_name = prefix + pat->first + suffix;
          const std::pair<std::string, std::string> key_val(out_name, type);

          //Lookup all the replacements for this new function
          std::vector<std::string> out_vars(pat->second.size(), "");
          for(unsigned i = 0; i < out_vars.size(); ++i){
            const std::string test_name = prefix + pat->second.at(i) + suffix;
            if(typelist.find(std::make_pair(test_name, type)) != typelist.end()){
              //Found a valid match
              out_vars.at(i) = test_name;
            }
          }

          //Make sure we haven't already defined the function
          if(reps.find(key_val) != reps.end() && reps.find(key_val)->second!=out_vars){
            throw std::runtime_error("Auto-generating the same function in multiple ways ("+type+" "+out_name+")");
          }

          reps.insert(std::make_pair(key_val, out_vars));
        }
      }
    }
  }
}

void GetOverwritten(const Typelist &typelist, const RepMap &replacements,
                    RepMap &overwritten, RepMap &new_funcs){
  overwritten.clear();
  new_funcs.clear();
  for(RepMap::const_iterator it = replacements.begin();
      it != replacements.end();
      ++it){
    if(typelist.find(it->first) != typelist.end()){
      overwritten.insert(*it);
    }else{
      new_funcs.insert(*it);
    }
  }
}

void WriteMergedHeader(const Typelist &typelist, const RepMap &overwritten, const RepMap &new_funcs){
  std::ofstream hpp_file("inc/cfa.hpp");

  hpp_file << "#ifndef H_CFA_MERGED\n";
  hpp_file << "#define H_CFA_MERGED\n\n";

  hpp_file << "#include <vector>\n";
  hpp_file << "#include <string>\n";
  hpp_file << "#include <typeinfo>\n\n";

  hpp_file << "#include \"TChain.h\"\n\n";

  hpp_file << "class cfa_base;\n\n";

  hpp_file << "class cfa{\n";
  hpp_file << "public:\n";
  hpp_file << "  explicit cfa(const std::string &file, const bool is_8TeV = false);\n\n";

  hpp_file << "  long TotalEntries() const;\n";
  hpp_file << "  void GetEntry(const long entry);\n";
  hpp_file << "  short GetVersion() const;\n";
  hpp_file << "  const std::string& SampleName() const;\n";
  hpp_file << "  const std::string& SampleName(const std::string &sample_name);\n";
  hpp_file << "  void SetFile(const std::string &file, bool is_8TeV = false);\n";
  hpp_file << "  void AddFiles(const std::string &file);\n";
  hpp_file << "  const std::type_info& Type() const;\n\n";

  hpp_file << "  ~cfa();\n\n";

  //Print accessor function declarations
  for(Typelist::const_iterator it = typelist.begin();
      it != typelist.end();
      ++it){
    const std::string name = it->first;
    const std::string type = it->second;

    if(overwritten.find(*it) != overwritten.end()){
      hpp_file << "  " << type << " const & " << name << "(const bool mux = true) const;\n";
    }else{
      hpp_file << "  " << type << " const & " << name << "() const;\n";
    }
  }

  for(RepMap::const_iterator it = new_funcs.begin();
      it != new_funcs.end();
      ++it){
    hpp_file << "  " << it->first.second << " const & " << it->first.first << "() const;\n";
  }
  hpp_file << "\n";

  hpp_file << "private:\n";
  hpp_file << "  cfa_base* cfa_;\n";
  hpp_file << "};\n\n";

  hpp_file << "#endif\n";

  hpp_file.close();
}

void WriteMergedSource(const Typelist &typelist, const RepMap &overwritten, const RepMap &new_funcs,
                       const std::vector<std::string>& class_names){
  std::ofstream cpp_file("src/cfa.cpp");

  cpp_file << "#include \"cfa.hpp\"\n\n";

  cpp_file << "#include <string>\n";
  cpp_file << "#include <vector>\n";
  cpp_file << "#include <sstream>\n";
  cpp_file << "#include <stdexcept>\n";
  cpp_file << "#include <typeinfo>\n\n";

  cpp_file << "#include \"TChain.h\"\n\n";

  cpp_file << "#include \"cfa_base.hpp\"\n";
  cpp_file << "#include \"cfa_8.hpp\"\n";
  cpp_file << "#include \"cfa_13.hpp\"\n\n";

  cpp_file << "cfa::cfa(const std::string &file, const bool is_8TeV):\n";
  cpp_file << "  cfa_( is_8TeV ? static_cast<cfa_base*>(new cfa_8(file)) : static_cast<cfa_base*>(new cfa_13(file)) ){\n";
  cpp_file << "}\n\n";

  cpp_file << "long cfa::TotalEntries() const{\n";
  cpp_file << "  return cfa_->TotalEntries();\n";
  cpp_file << "}\n\n";

  cpp_file << "void cfa::GetEntry(const long entry){\n";
  cpp_file << "  cfa_->GetEntry(entry);\n";
  cpp_file << "}\n\n";

  cpp_file << "short cfa::GetVersion() const{\n";
  cpp_file << "  return cfa_->GetVersion();\n";
  cpp_file << "}\n\n";

  cpp_file << "const std::string& cfa::SampleName() const{\n";
  cpp_file << "  return cfa_->SampleName();\n";
  cpp_file << "}\n\n";

  cpp_file << "const std::string& cfa::SampleName(const std::string &sample_name){\n";
  cpp_file << "  return cfa_->SampleName(sample_name);\n";
  cpp_file << "}\n\n";

  cpp_file << "void cfa::SetFile(const std::string &file, const bool is_8TeV){\n";
  cpp_file << "  delete cfa_; cfa_=NULL;\n";
  cpp_file << "  cfa_ = ( is_8TeV ? static_cast<cfa_base*>(new cfa_8(file)) : static_cast<cfa_base*>(new cfa_13(file)) );\n";
  cpp_file << "}\n\n";

  cpp_file << "void cfa::AddFiles(const std::string &file){\n";
  cpp_file << "  cfa_->AddFiles(file);\n";
  cpp_file << "}\n\n";

  cpp_file << "const std::type_info& cfa::Type() const{\n";
  cpp_file << "  return typeid(*cfa_);\n";
  cpp_file << "}\n\n";

  cpp_file << "cfa::~cfa(){\n";
  cpp_file << "  delete cfa_; cfa_=NULL;\n";
  cpp_file << "}\n\n";

  //Print accessor implementation for variables
  for(Typelist::const_iterator it = typelist.begin();
      it != typelist.end();
      ++it){
    const std::string name = it->first;
    const std::string type = it->second;

    const RepMap::const_iterator over_it = overwritten.find(*it);
    if(over_it == overwritten.end()){
      //Function does not conflict with a mux name and just does polymorphic call
      cpp_file << type << " const & cfa::" << name << "() const{\n";
      cpp_file << "  return cfa_->" << name << "();\n";
      cpp_file << "}\n\n";
    }else{
      //Function conflicts with a mux name and needs special treatment
      const std::vector<std::string>& funcs = over_it->second;
      if(funcs.size() != class_names.size()) throw std::runtime_error("Could not match class names to muxes");

      cpp_file << type << " const & cfa::" << name << "(const bool mux) const{\n";
      if(funcs.size()){
        cpp_file << "  if(mux){\n";
        for(unsigned i = 0; i < funcs.size(); ++i){
          cpp_file << "    " << (i?"}else ":"") << "if(typeid(*cfa_)==typeid(" << class_names.at(i) << ")){\n";
          if(funcs.at(i)!=""){
            cpp_file << "      return cfa_->" << funcs.at(i) << "();\n";
          }else{
            cpp_file << "      throw std::logic_error(\"Function lookup unknown for class \"+std::string(typeid(*cfa_).name()));\n";
          }
        }
        cpp_file << "    }else{\n";
        cpp_file << "      throw std::logic_error(\"Function lookup unknown for class \"+std::string(typeid(*cfa_).name()));\n";
        cpp_file << "    }\n";
        cpp_file << "  }\n";
      }
      cpp_file << "  return cfa_->" << name << "();\n";
      cpp_file << "}\n\n";
    }
  }

  //Print functions that only exist as a result of muxing
  for(RepMap::const_iterator it = new_funcs.begin();
      it != new_funcs.end();
      ++it){
    const std::string& name = it->first.first;
    const std::string& type = it->first.second;
    const std::vector<std::string>& funcs = it->second;
    if(funcs.size() != class_names.size()) throw std::runtime_error("Could not match class names to muxes");

    bool all_blank = true;
    std::string good_name = "";

    cpp_file << type << " const & cfa::" << name << "() const{\n";
    for(unsigned i = 0; i < funcs.size(); ++i){
      if(all_blank && funcs.at(i)!=""){
        all_blank = false;
        good_name = funcs.at(i);
      }
      cpp_file << "  " << (i?"}else ":"") << "if(typeid(*cfa_)==typeid(" << class_names.at(i) << ")){\n";
      if(funcs.at(i)!=""){
        cpp_file << "    return cfa_->" << funcs.at(i) << "();\n";
      }else{
        cpp_file << "    throw std::logic_error(\"Function lookup unknown for class \"+std::string(typeid(*cfa_).name()));\n";
      }
    }
    cpp_file << "  }else{\n";
    cpp_file << "    throw std::logic_error(\"Function lookup unknown for class \"+std::string(typeid(*cfa_).name()));\n";
    cpp_file << "  }\n";
    cpp_file << "  return cfa_->" << good_name << "();\n";
    cpp_file << "}\n\n";

    //Make sure we found at least one valid function to call
    if(all_blank) throw std::runtime_error("No valid function call available for "+type+name);
  }

  cpp_file.close();
}
