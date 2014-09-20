#include <iostream>
#include <fstream>
#include <vector>
#include "TString.h"

 
using namespace std;

int main(){
  TString name, copy;
  vector<TString> variables;

  ////////////////   Leptons   ////////////////
  variables.push_back("int nleps");
  variables.push_back("int nmus");
  variables.push_back("int nvmus");
  variables.push_back("vector<double>* mus_pt");
  variables.push_back("vector<double>* mus_gen_pt");
  variables.push_back("vector<double>* mus_eta");
  variables.push_back("vector<double>* mus_phi");
  variables.push_back("vector<double>* mus_reliso");
  variables.push_back("vector<double>* mus_tru_dr");
  variables.push_back("vector<int>* mus_tru_id");
  variables.push_back("vector<int>* mus_tru_momid");
  variables.push_back("int nels");
  variables.push_back("int nvels");
  variables.push_back("vector<double>* els_pt");
  variables.push_back("vector<double>* els_gen_pt");
  variables.push_back("vector<double>* els_eta");
  variables.push_back("vector<double>* els_phi");
  variables.push_back("vector<double>* els_reliso");
  variables.push_back("vector<double>* els_tru_dr");
  variables.push_back("vector<int>* els_tru_id");
  variables.push_back("vector<int>* els_tru_momid");

  /////////////////   Jets   //////////////////
  variables.push_back("vector<int>* njets");  // Number of jets for different pT thresholds
  variables.push_back("vector<int>* nbt");    // Number of tight b-tags for different pT thresholds
  variables.push_back("vector<int>* nbm");    // Number of medium b-tags for different pT thresholds
  variables.push_back("vector<int>* nbl");    // Number of loose b-tags for different pT thresholds
  variables.push_back("vector<double>* jets_pt");
  variables.push_back("vector<double>* jets_eta");
  variables.push_back("vector<double>* jets_phi");
  variables.push_back("vector<double>* jets_csv");
  
  //////////////////   MC   ///////////////////
  variables.push_back("vector<double>* genmus_pt");
  variables.push_back("vector<double>* genmus_eta");
  variables.push_back("vector<double>* genmus_phi");
  variables.push_back("vector<double>* genels_pt");
  variables.push_back("vector<double>* genels_eta");
  variables.push_back("vector<double>* genels_phi");

  //////////////////   Global   ///////////////////
  variables.push_back("int npv");
  variables.push_back("int ntrupv");
  variables.push_back("float weight");
  variables.push_back("float ht");
  variables.push_back("float mt");
  variables.push_back("float met");
  variables.push_back("float genmet");
  variables.push_back("float genht");
  variables.push_back("float met_phi");
  variables.push_back("float dphi_wlep");
  variables.push_back("float dr_bb");
  variables.push_back("float spher");
  variables.push_back("float spher_jets");
  variables.push_back("float spher_nolin");
  variables.push_back("float ntrupv_mean"); 

  std::ofstream cppFile("src/small_tree.cpp"), hppFile("inc/small_tree.hpp");
  
  //////////  hpp file  ///////////////////
  hppFile << "// small_tree: class that contains reduced cfA ntuples\n";
  hppFile << "// File generated with generate_small_tree.exe\n\n";
  hppFile << "#ifndef H_SMALL_TREE\n";
  hppFile << "#define H_SMALL_TREE\n\n";
  hppFile << "#include <vector>\n";
  hppFile << "#include \"TChain.h\"\n";
  hppFile << "#include \"TTree.h\"\n\n";
  hppFile << "using namespace std;\n\n";

  hppFile << "class small_tree{\n";
  hppFile << "public:\n";
  hppFile << "  small_tree(); // Constructor to create tree\n";
  hppFile << "  small_tree(TString filename); // Constructor to read tree\n\n";
  hppFile << "  bool isReadOnly;\n";
  hppFile << "  TChain chain;\n";
  hppFile << "  TTree tree;\n";
  for(unsigned int var(0); var<variables.size(); var++){
    hppFile << "  "<<variables[var]<<";\n";
    if(variables[var].Contains("*")){
      copy = variables[var]; 
      copy.ReplaceAll("* "," v_"); 
      hppFile << "  "<<copy<<";\n";
    }
  }

  hppFile << "\n  void Fill();\n";
  hppFile << "  void Write();\n";
  hppFile << "  int GetEntries();\n";

  hppFile << "};\n\n";
  hppFile << "#endif" << endl;

  //////////  cpp file  ///////////////////
  cppFile << "// small_tree: class that contains reduced cfA ntuples\n";
  cppFile << "// File generated with generate_small_tree.exe\n\n";
  cppFile << "#include \"small_tree.hpp\"\n";
  cppFile << "#include <iostream>\n\n";
  cppFile << "using namespace std;\n";
  cppFile << "using std::cout;\n";
  cppFile << "using std::endl;\n\n";

  cppFile << "small_tree::small_tree():\n";
  cppFile << "  tree(\"tree\", \"tree\"){\n";
  for(unsigned int var(0); var<variables.size(); var++){
    name = variables[var];
    name.Remove(0, name.Last(' ')+1);
    cppFile << "  tree.Branch(\""<<name<<"\", &"<<name<<");\n";
    copy = "v_"; copy += name;
    if(variables[var].Contains("*")) cppFile << "  " << name <<" = &"<< copy << ";\n";
  }
  cppFile << "  isReadOnly = false;\n";
  cppFile << "}\n\n";

  cppFile << "small_tree::small_tree(TString filename):\n";
  cppFile << "  chain(\"tree\"){\n";
  cppFile << "  chain.Add(filename);\n";
  for(unsigned int var(0); var<variables.size(); var++){
    name = variables[var];
    name.Remove(0, name.Last(' ')+1);
    cppFile << "  chain.SetBranchAddress(\""<<name<<"\", &"<<name<<");\n";
  }
  cppFile << "  isReadOnly = true;\n";
  cppFile << "}\n\n";

  cppFile << "void small_tree::Fill(){\n";
  cppFile << "  if(isReadOnly) cout<<\"Tree is read only\"<<endl;\n";
  cppFile << "  else tree.Fill();\n";
  cppFile << "}\n\n";
  cppFile << "void small_tree::Write(){\n";
  cppFile << "  if(isReadOnly) chain.Write();\n";
  cppFile << "  else tree.Write();\n";
  cppFile << "}\n\n";
  cppFile << "int small_tree::GetEntries(){\n";
  cppFile << "  if(isReadOnly) return chain.GetEntries();\n";
  cppFile << "  else return tree.GetEntries();\n";
  cppFile << "}\n\n";

  cout<<"Written src/small_tree.cpp and inc/small_tree.hpp"<<endl;
  
  cppFile.close();
  hppFile.close();
  return 0;
}
