#include "generate_cfa_merged_class.hpp"

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

  TFile file_8(argv[1], "read");
  TFile file_13(argv[2], "read");
  if(!file_8.IsOpen() || file_8.IsZombie()) throw std::runtime_error("Could not open 8 TeV file.");
  if(!file_13.IsOpen() || file_13.IsZombie()) throw std::runtime_error("Could not open 13 TeV file.");

  std::ofstream cpp_file("src/cfa.cpp"), hpp_file("inc/cfa.hpp");
  {TTree t("a","b");}//Magically make ROOT link things correctly...

  TChain *chainA_8(static_cast<TChain*>(file_8.Get("configurableAnalysis/eventA")));
  TChain *chainB_8(static_cast<TChain*>(file_8.Get("configurableAnalysis/eventB")));
  TChain *chainA_13(static_cast<TChain*>(file_13.Get("configurableAnalysis/eventA")));
  TChain *chainB_13(static_cast<TChain*>(file_13.Get("configurableAnalysis/eventB")));

  if(!chainA_8) throw std::runtime_error("Could not find chainA in 8 TeV file.");
  if(!chainB_8) throw std::runtime_error("Could not find chainB in 8 TeV file.");
  if(!chainA_13) throw std::runtime_error("Could not find chainA in 13 TeV file.");
  if(!chainB_13) throw std::runtime_error("Could not find chainB in 13 TeV file.");

  std::set<Var> vars;
  GetVariables(chainA_8, vars);
  GetVariables(chainB_8, vars);
  GetVariables(chainA_13, vars);
  GetVariables(chainB_13, vars);

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
  for(std::set<Var>::const_iterator it = vars.begin();
      it != vars.end();
      ++it){
    const std::string name = it->first;
    const std::string type = it->second;

    hpp_file << "  " << type << " const & " << name << "() const;\n";
  }
  hpp_file << "\n";

  hpp_file << "private:\n";
  hpp_file << "  cfa_base* cfa_;\n";
  hpp_file << "};\n\n";

  hpp_file << "#endif\n";

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
  for(std::set<Var>::const_iterator it = vars.begin();
      it != vars.end();
      ++it){
    const std::string name = it->first;
    const std::string type = it->second;

    cpp_file << type << " const & cfa::" << name << "() const{\n";
    cpp_file << "  return cfa_->" << name << "();\n";
    cpp_file << "}\n\n";
  }

  hpp_file.close();
  cpp_file.close();
  file_8.Close();
  file_13.Close();
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
