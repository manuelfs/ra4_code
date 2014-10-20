#include "generate_cfa_class.hpp"

#include <cctype>

#include <utility>
#include <string>
#include <set>
#include <fstream>
#include <iostream>
#include <stdexcept>

#include "TFile.h"
#include "TChain.h"
#include "TLeafObject.h"

int main(int argc, char *argv[]){
  try{
    if(argc<=2) throw std::runtime_error("At least two arguments required.");
    if(!(argc & 1)) throw std::runtime_error("Even number of arguments required.");

    {TTree t("a","b");}//Magically make ROOT link things correctly...

    std::vector<std::pair<std::string, VarSet> > individual_varset_a(0), individual_varset_b(0), individual_varset(0);
    VarSet full_varset;

    for(int arg = 1; (arg+1) < argc; arg+=2){
      TFile in_file(argv[arg], "read");
      if(!in_file.IsOpen() || in_file.IsZombie()) throw std::runtime_error("Could not open file.");

      TChain *chainA(static_cast<TChain*>(in_file.Get("configurableAnalysis/eventA")));
      if(!chainA) throw std::runtime_error("Could not find chainA.");

      TChain *chainB(static_cast<TChain*>(in_file.Get("configurableAnalysis/eventB")));
      if(!chainB) throw std::runtime_error("Could not find chainB.");
    
      GetVariables(chainA, full_varset);
      GetVariables(chainB, full_varset);

      individual_varset.push_back(std::make_pair(std::string(argv[arg+1]), VarSet()));
      GetVariables(chainA, individual_varset.back().second);
      GetVariables(chainB, individual_varset.back().second);

      individual_varset_a.push_back(std::make_pair(std::string(argv[arg+1]), VarSet()));
      GetVariables(chainA, individual_varset_a.back().second);

      individual_varset_b.push_back(std::make_pair(std::string(argv[arg+1]), VarSet()));
      GetVariables(chainB, individual_varset_b.back().second);

      in_file.Close();
    }

    WriteBaseHeader(full_varset);
    WriteBaseSource(full_varset);

    for(unsigned i = 0; i < individual_varset_a.size(); ++i){
      WriteDerivedHeader(full_varset, individual_varset.at(i));
      WriteDerivedSource(full_varset, individual_varset.at(i), individual_varset_a.at(i), individual_varset_b.at(i));
    }

    WriteMergedHeader(full_varset);
    WriteMergedSource(full_varset);
  }
  catch(std::exception& ex){
    std::cerr << "An exception occurred: " << ex.what() << std::endl;
    return EXIT_FAILURE;
  }
  catch(...){
    std::cerr << "An unknown exception occurred." << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

void GetVariables(TChain *chain, VarSet& vars){
  for(int i =0; i < chain->GetListOfLeaves()->GetSize(); ++i){
    std::string typeName(static_cast<TLeafObject*>((chain->GetListOfLeaves()->At(i)))->GetTypeName());
    std::string varName(static_cast<TLeaf*>((chain->GetListOfLeaves()->At(i)))->GetBranch()->GetName());
    
    bool nonSimp(false);
    for(unsigned long j(typeName.find("vector")); j!=std::string::npos; j=typeName.find("vector",j+6)){
      typeName.replace(j,6,"std::vector");
      nonSimp=true;
    }
    for(unsigned long j(typeName.find("string")); j!=std::string::npos; j=typeName.find("string",j+6)){
      typeName.replace(j,6,"std::string");
      nonSimp=true;
    }
    if(nonSimp) typeName = typeName + "*";
    
    if(vars.find(varName) == vars.end()){
      vars.insert(std::make_pair(varName, std::set<std::string>()));
    }
    vars[varName].insert(typeName);
  }
}

std::string AllCaps(std::string str){
  for(std::string::iterator it = str.begin();
      it != str.end();
      ++it){
    *it = toupper(*it);
  }
  return str;
}

void GetTypes(const VarSet &full_varset,
              const VarSet::const_iterator &variable,
              std::string &from_type,
              std::string &to_type){
  from_type = "";
  to_type = "";

  if(variable->second.size()==0) throw std::runtime_error("Could not find type for variable in this file.");
  if(variable->second.size()>=2) throw std::runtime_error("Multiple types found for variable in this file.");

  const std::string name = variable->first;
  VarSet::const_iterator var = full_varset.find(name);
  if(var == full_varset.end()) throw std::runtime_error("Failed to find variable in full dictionary.");
  switch(var->second.size()){
  case 0:
    throw std::runtime_error("Could not find type for variable in full dictionary.");
    break;
  case 1:
    from_type = *(var->second.begin());
    to_type = from_type;
    break;
  case 2:
    if(var->second.find("std::vector<float>*") != var->second.end()
       && var->second.find("std::vector<bool>*") != var->second.end()){
      from_type = "std::vector<float>*";
      to_type = "std::vector<bool>*";
    }else{
      throw std::runtime_error("Unknown conversion requested.");
    }
    break;
  default:
    throw std::runtime_error("Too many types found in full dictionary.");
    break;
  }
}

std::string GetType(const VarSet::const_iterator &variable){
  switch(variable->second.size()){
    case 0:
      throw std::runtime_error("Could not find a valid variable type");
      break;
    case 1:
      return *(variable->second.begin());
    case 2:
      if(variable->second.find("std::vector<float>*") != variable->second.end()
	 && variable->second.find("std::vector<bool>*") != variable->second.end()){
	return "std::vector<bool>*";
      }else{
	throw std::runtime_error("Unknown conversion requested.");
      }
      break;
    default:
      throw std::runtime_error("Too many types found for variable.");
      break;
  }
}

void WriteBaseHeader(const VarSet& full_varset){
  std::ofstream hpp_file("inc/cfa_base.hpp");
  hpp_file << "#ifndef H_CFA_BASE\n";
  hpp_file << "#define H_CFA_BASE\n\n";

  hpp_file << "#include <vector>\n";
  hpp_file << "#include <string>\n\n";

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

  //Print accessor function declarations
  for(VarSet::const_iterator it = full_varset.begin();
      it != full_varset.end();
      ++it){
    const std::string name = it->first;
    const std::string type = GetType(it);

    hpp_file << "  __attribute__((noreturn)) virtual " << type << " const & " << name << "() const;\n";
  }
  hpp_file << "\n";

  hpp_file << "protected:\n";
  hpp_file << "  void PrepareNewChains();\n";
  hpp_file << "  virtual void InitializeA() = 0;\n";
  hpp_file << "  virtual void InitializeB() = 0;\n\n";

  hpp_file << "  TChain chainA_, chainB_;\n";
  hpp_file << "  long entry_;\n\n";

  hpp_file << "private:\n";
  hpp_file << "  void CalcVersion();\n\n";

  hpp_file << "  std::string sample_name_;\n";
  hpp_file << "  mutable long total_entries_;\n";
  hpp_file << "  short cfa_version_;\n";
  hpp_file << "  mutable bool cached_total_entries_;\n";
  hpp_file << "};\n\n";

  hpp_file << "#endif\n";

  hpp_file.close();
}

void WriteBaseSource(const VarSet &full_varset){
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
  cpp_file << "  cached_total_entries_(false){\n";
  cpp_file << "  GetVersion();\n";
  cpp_file << "  AddFiles(file);\n";
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

  //Print base implementation (intended to be overriden in child classes)
  for(VarSet::const_iterator it = full_varset.begin();
      it != full_varset.end();
      ++it){
    const std::string name = it->first;
    const std::string type = GetType(it);

    cpp_file << type << " const & cfa_base::" << name << "() const{\n";
    cpp_file << "  throw std::runtime_error(\"" << name << " does not exist in this cfa version.\");\n";
    cpp_file << "}\n\n";
  }

  cpp_file.close();
}

void WriteDerivedHeader(const VarSet &full_varset,
                        const std::pair<std::string, VarSet> &individual_varset){
  const std::string base_name = individual_varset.first;
  std::ofstream hpp_file(("inc/"+base_name+".hpp").c_str());

  hpp_file << "#ifndef H_" << AllCaps(base_name) << "\n";
  hpp_file << "#define H_" << AllCaps(base_name) << "\n\n";

  hpp_file << "#include \"cfa_base.hpp\"\n\n";

  hpp_file << "#include <vector>\n";
  hpp_file << "#include <string>\n\n";

  hpp_file << "#include \"TChain.h\"\n\n";

  hpp_file << "class " << base_name << ": public cfa_base{\n";
  hpp_file << "public:\n";
  hpp_file << "  explicit " << base_name << "(const std::string &file);\n\n";

  hpp_file << "  virtual void GetEntry(const long entry);\n\n";

  hpp_file << "  virtual ~" << base_name << "();\n\n";

  //Print accessor functions
  for(VarSet::const_iterator it = individual_varset.second.begin();
      it != individual_varset.second.end();
      ++it){
    const std::string name = it->first;

    std::string from_type = "", to_type = "";
    GetTypes(full_varset, it, from_type, to_type);
    hpp_file << "  virtual " << to_type << " const & " << name << "() const;\n";
  }
  hpp_file << '\n';

  hpp_file << "private:\n";
  hpp_file << "  virtual void InitializeA();\n";
  hpp_file << "  virtual void InitializeB();\n\n";

  //Print member variables
  for(VarSet::const_iterator it = individual_varset.second.begin();
      it != individual_varset.second.end();
      ++it){
    std::string name = it->first;

    std::string from_type = "", to_type = "";
    GetTypes(full_varset, it, from_type, to_type);
    if(from_type == to_type){
      hpp_file << "  " << to_type << ' ' << name << "_;\n";
    }else if(from_type == "std::vector<float>*"
             && to_type == "std::vector<bool>*"){
      hpp_file << "  " << from_type << " v_" << name << "_;\n";
      hpp_file << "  " << to_type << ' ' << name << "_;\n";
    }
  }

  //Print branches for members
  for(VarSet::const_iterator it = individual_varset.second.begin();
      it != individual_varset.second.end();
      ++it){
    hpp_file << "  TBranch *b_" << it->first << "_;\n";
  }

  //Print cache check for members
  for(VarSet::const_iterator it = individual_varset.second.begin();
      it != individual_varset.second.end();
      ++it){
    hpp_file << "  mutable bool c_" << it->first << "_;\n";
  }
  hpp_file << "};\n\n";

  hpp_file << "#endif\n";

  hpp_file.close();
}

void WriteDerivedSource(const VarSet &full_varset,
                        const std::pair<std::string, VarSet> &individual_varset,
                        const std::pair<std::string, VarSet> &individual_varset_a,
                        const std::pair<std::string, VarSet> &individual_varset_b){
  const std::string base_name = individual_varset.first;
  std::ofstream cpp_file(("src/"+base_name+".cpp").c_str());

  cpp_file << "#include \"" << base_name << ".hpp\"\n\n";

  cpp_file << "#include <string>\n";
  cpp_file << "#include <vector>\n";
  cpp_file << "#include <sstream>\n";
  cpp_file << "#include <stdexcept>\n\n";

  cpp_file << "#include \"TChain.h\"\n\n";

  cpp_file << base_name << "::" << base_name << "(const std::string &file):\n";
  if(individual_varset.second.size()){
    cpp_file << "  cfa_base(file),\n";

    //Initialize members
    for(VarSet::const_iterator it = individual_varset.second.begin();
        it != individual_varset.second.end();
        ++it){
      cpp_file << "  " << it->first << "_(0),\n";
    }
    
    //Initialize branches
    for(VarSet::const_iterator it = individual_varset.second.begin();
        it != individual_varset.second.end();
        ++it){
      cpp_file << "  b_" << it->first << "_(NULL),\n";
    }
    
    //Initialize caching
    for(VarSet::const_iterator it = individual_varset.second.begin();
        it != (--individual_varset.second.end());
        ++it){
      cpp_file << "  c_" << it->first << "_(false),\n";
    }
    cpp_file << "  c_" << (--individual_varset.second.end())->first << "_(false){\n";
  }else{
    //Really we should never end up here, but just in case...
    cpp_file << "  cfa_base(file){\n";
  }
  
  cpp_file << "  PrepareNewChains();\n";
  cpp_file << "}\n\n";

  cpp_file << "void " << base_name << "::GetEntry(const long entry){\n";
  //Reset cache
  for(VarSet::const_iterator it = individual_varset.second.begin();
      it != individual_varset.second.end();
      ++it){
    cpp_file << "  c_" << it->first << "_ = false;\n";
  }
  cpp_file << "  const long entry_a = chainA_.LoadTree(entry);\n";
  cpp_file << "  const long entry_b = chainB_.LoadTree(entry);\n";
  cpp_file << "  if(entry_a!=entry_b) throw std::runtime_error(\"Entry is in different trees for chains A and B\");\n";
  cpp_file << "  entry_ = entry_a;\n";
  cpp_file << "}\n\n";

  cpp_file << "void " << base_name << "::InitializeA(){\n";
  //Set chainA branch addresses
  for(VarSet::const_iterator it = individual_varset_a.second.begin();
      it != individual_varset_a.second.end();
      ++it){
    const std::string name = it->first;

    std::string from_type = "", to_type = "";
    GetTypes(full_varset, it, from_type, to_type);

    if(from_type == to_type){
      cpp_file << "  chainA_.SetBranchAddress(\"" << name << "\", &" << name << "_, &b_" << name << "_);\n";
    }else{
      cpp_file << "  chainA_.SetBranchAddress(\"" << name << "\", &v_" << name << "_, &b_" << name << "_);\n";
    }
  }
  cpp_file << "}\n\n";

  cpp_file << "void " << base_name << "::InitializeB(){\n";
  //Set chainB branch addresses
  for(VarSet::const_iterator it = individual_varset_b.second.begin();
      it != individual_varset_b.second.end();
      ++it){
    const std::string name = it->first;

    std::string from_type = "", to_type = "";
    GetTypes(full_varset, it, from_type, to_type);

    if(from_type == to_type){
      cpp_file << "  chainB_.SetBranchAddress(\"" << name << "\", &" << name << "_, &b_" << name << "_);\n";
    }else{
      cpp_file << "  chainB_.SetBranchAddress(\"" << name << "\", &v_" << name << "_, &b_" << name << "_);\n";
    }
  }
  cpp_file << "}\n\n";

  cpp_file << base_name << "::~" << base_name << "(){\n";
  cpp_file << "}\n\n";

  //Define accessor functions
  for(VarSet::const_iterator it = individual_varset.second.begin();
      it != individual_varset.second.end();
      ++it){
    const std::string name = it->first;

    std::string from_type = "", to_type = "";
    GetTypes(full_varset, it, from_type, to_type);

    cpp_file << to_type << " const & " << base_name << "::" << name << "() const{\n";
    cpp_file << "  if(!c_" << name << "_ && b_" << name << "_){\n";
    cpp_file << "    b_" << name << "_->GetEntry(entry_);\n";

    if(from_type == "std::vector<float>*"
       && to_type == "std::vector<bool>*"){
      cpp_file << "    " << name << "_->resize(v_" << name << "_->size());\n";
      cpp_file << "    for(unsigned i = 0; i < " << name << "_->size(); ++i){\n";
      cpp_file << "      " << name << "_->at(i) = static_cast<bool>(v_" << name << "_->at(i));\n";
      cpp_file << "    }\n";
    }

    cpp_file << "    c_" << name << "_ = true;\n";
    cpp_file << "  }\n";
    cpp_file << "  return " << name << "_;\n";
    cpp_file << "}\n\n";
  }

  cpp_file.close();
}

void WriteMergedHeader(const VarSet &full_varset){
  std::ofstream hpp_file("inc/cfa.hpp");

  hpp_file << "#ifndef H_CFA_MERGED\n";
  hpp_file << "#define H_CFA_MERGED\n\n";

  hpp_file << "#include <vector>\n";
  hpp_file << "#include <string>\n\n";

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
  hpp_file << "  void AddFiles(const std::string &file);\n\n";

  hpp_file << "  ~cfa();\n\n";

  //Print accessor function declarations
  for(VarSet::const_iterator it = full_varset.begin();
      it != full_varset.end();
      ++it){
    const std::string name = it->first;
    const std::string type = GetType(it);

    hpp_file << "  " << type << " const & " << name << "() const;\n";
  }
  hpp_file << "\n";

  hpp_file << "private:\n";
  hpp_file << "  cfa_base* cfa_;\n";
  hpp_file << "};\n\n";

  hpp_file << "#endif\n";

  hpp_file.close();
}

void WriteMergedSource(const VarSet &full_varset){
  std::ofstream cpp_file("src/cfa.cpp");

  cpp_file << "#include \"cfa.hpp\"\n\n";

  cpp_file << "#include <string>\n";
  cpp_file << "#include <vector>\n";
  cpp_file << "#include <sstream>\n";
  cpp_file << "#include <stdexcept>\n\n";

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

  cpp_file << "cfa::~cfa(){\n";
  cpp_file << "  delete cfa_; cfa_=NULL;\n";
  cpp_file << "}\n\n";

  //Print base implementation (intended to be overriden in child classes)
  for(VarSet::const_iterator it = full_varset.begin();
      it != full_varset.end();
      ++it){
    const std::string name = it->first;
    const std::string type = GetType(it);

    cpp_file << type << " const & cfa::" << name << "() const{\n";
    cpp_file << "  return cfa_->" << name << "();\n";
    cpp_file << "}\n\n";
  }

  cpp_file.close();
}
