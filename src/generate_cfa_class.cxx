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
  if(argc<=2) throw std::runtime_error("Two arguments required.");

  TFile in_file(argv[1], "read");
  if(!in_file.IsOpen() || in_file.IsZombie()) throw std::runtime_error("Could not open file.");

  const std::string base_name = argv[2];
  std::ofstream cpp_file(("src/"+base_name+".cpp").c_str());
  std::ofstream hpp_file(("inc/"+base_name+".hpp").c_str());
  {TTree t("a","b");}//Magically make ROOT link things correctly...

  TChain *chainA(static_cast<TChain*>(in_file.Get("configurableAnalysis/eventA")));
  TChain *chainB(static_cast<TChain*>(in_file.Get("configurableAnalysis/eventB")));

  if(!chainA) throw std::runtime_error("Could not find chainA.");
  if(!chainB) throw std::runtime_error("Could not find chainB.");

  std::set<Var> vars, vars_a, vars_b;
  GetVariables(chainA, vars);
  GetVariables(chainB, vars);
  GetVariables(chainA, vars_a);
  GetVariables(chainB, vars_b);

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
  for(std::set<Var>::const_iterator it = vars.begin();
      it != vars.end();
      ++it){
    const std::string name = it->first;
    const std::string type = it->second;

    hpp_file << "  virtual " << type << " const & " << name << "() const;\n";
  }
  hpp_file << '\n';

  hpp_file << "private:\n";
  hpp_file << "  virtual void InitializeA();\n";
  hpp_file << "  virtual void InitializeB();\n\n";

  //Print member variables
  for(std::set<Var>::const_iterator it = vars.begin();
      it != vars.end();
      ++it){
    hpp_file << "  " << it->second << ' ' << it->first << "_;\n";
  }

  //Print branches for members
  for(std::set<Var>::const_iterator it = vars.begin();
      it != vars.end();
      ++it){
    hpp_file << "  TBranch *b_" << it->first << "_;\n";
  }

  //Print cache check for members
  for(std::set<Var>::const_iterator it = vars.begin();
      it != vars.end();
      ++it){
    hpp_file << "  mutable bool c_" << it->first << "_;\n";
  }
  hpp_file << "};\n\n";

  hpp_file << "#endif\n";

  cpp_file << "#include \"" << base_name << ".hpp\"\n\n";

  cpp_file << "#include <string>\n";
  cpp_file << "#include <vector>\n";
  cpp_file << "#include <sstream>\n";
  cpp_file << "#include <stdexcept>\n\n";

  cpp_file << "#include \"TChain.h\"\n\n";

  cpp_file << base_name << "::" << base_name << "(const std::string &file):\n";
  if(vars.size()){
    cpp_file << "  cfa_base(file),\n";

    //Initialize members
    for(std::set<Var>::const_iterator it = vars.begin();
        it != vars.end();
        ++it){
      cpp_file << "  " << it->first << "_(0),\n";
    }
    
    //Initialize branches
    for(std::set<Var>::const_iterator it = vars.begin();
        it != vars.end();
        ++it){
      cpp_file << "  b_" << it->first << "_(NULL),\n";
    }
    
    //Initialize caching
    for(std::set<Var>::const_iterator it = vars.begin();
	it != (--vars.end());
	++it){
      cpp_file << "  c_" << it->first << "_(false),\n";
    }
    cpp_file << "  c_" << (--vars.end())->first << "_(false){\n";
  }else{
    //Really we should never end up here, but just in case...
    cpp_file << "  cfa_base(file){\n";
  }
  
  cpp_file << "  PrepareNewChains();\n";
  cpp_file << "}\n\n";

  cpp_file << "void " << base_name << "::GetEntry(const long entry){\n";
  for(std::set<Var>::const_iterator it = vars.begin();
      it != vars.end();
      ++it){
    cpp_file << "  c_" << it->first << "_ = false;\n";
  }
  cpp_file << "  entry_ = entry;\n";
  cpp_file << "}\n\n";

  cpp_file << "void " << base_name << "::InitializeA(){\n";
  for(std::set<Var>::const_iterator it = vars_a.begin();
      it != vars_a.end();
      ++it){
    const std::string name = it->first;
    cpp_file << "  chainA_.SetBranchAddress(\"" << name << "\", &" << name << "_, &b_" << name << "_);\n";
  }
  cpp_file << "}\n\n";

  cpp_file << "void " << base_name << "::InitializeB(){\n";
  for(std::set<Var>::const_iterator it = vars_b.begin();
      it != vars_b.end();
      ++it){
    const std::string name = it->first;
    cpp_file << "  chainB_.SetBranchAddress(\"" << name << "\", &" << name << "_, &b_" << name << "_);\n";
  }
  cpp_file << "}\n\n";

  cpp_file << base_name << "::~" << base_name << "(){\n";
  cpp_file << "}\n\n";

  for(std::set<Var>::const_iterator it = vars.begin();
      it != vars.end();
      ++it){
    const std::string name = it->first;
    const std::string type = it->second;

    cpp_file << type << " const & " << base_name << "::" << name << "() const{\n";
    cpp_file << "  if(!c_" << name << "_ && b_" << name << "_){\n";
    cpp_file << "    b_" << name << "_->GetEntry(entry_);\n";
    cpp_file << "    c_" << name << "_ = true;\n";
    cpp_file << "  }\n";
    cpp_file << "  return " << name << "_;\n";
    cpp_file << "}\n\n";
  }

  hpp_file.close();
  cpp_file.close();
  in_file.Close();
}

void GetVariables(TChain *chain, std::set<Var>& vars){
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
    
    vars.insert(std::make_pair(varName, typeName));
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
