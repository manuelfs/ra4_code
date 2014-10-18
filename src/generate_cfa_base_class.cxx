#include "generate_cfa_base_class.hpp"

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

  std::ofstream cpp_file("src/cfa_base.cpp"), hpp_file("inc/cfa_base.hpp");
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
  for(std::set<Var>::const_iterator it = vars.begin();
      it != vars.end();
      ++it){
    const std::string name = it->first;
    const std::string type = it->second;

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
  cpp_file << "  entry_ = entry;\n";
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
  for(std::set<Var>::const_iterator it = vars.begin();
      it != vars.end();
      ++it){
    const std::string name = it->first;
    const std::string type = it->second;

    cpp_file << type << " const & cfa_base::" << name << "() const{\n";
    cpp_file << "  throw std::runtime_error(\"" << name << " does not exist in this cfa version.\");\n";
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
