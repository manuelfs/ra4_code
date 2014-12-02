#include <iostream>
#include <fstream>
#include <vector>
#include "TString.h"
 
using namespace std;

int main(){
  TString name, copy;
  vector<TString> variables;

  ////////////////   Provenance   /////////////
  variables.push_back("unsigned run");  
  variables.push_back("unsigned lumiblock");  
  variables.push_back("unsigned event");  

  ////////////////   Leptons   ////////////////
  variables.push_back("int nleps");
  variables.push_back("int nmus");
  variables.push_back("int nvmus");
  variables.push_back("std::vector<double>* mus_pt");
  variables.push_back("std::vector<double>* mus_gen_pt");
  variables.push_back("std::vector<double>* mus_eta");
  variables.push_back("std::vector<double>* mus_phi");
  variables.push_back("std::vector<double>* mus_charge");
  variables.push_back("std::vector<double>* mus_reliso");
  variables.push_back("std::vector<double>* mus_sigid");
  variables.push_back("std::vector<double>* mus_tru_dr");
  variables.push_back("std::vector<int>* mus_tru_id");
  variables.push_back("std::vector<int>* mus_tru_momid");
  variables.push_back("std::vector<bool>* mus_tru_tm");
  variables.push_back("std::vector<double>* mus_mindr");
  variables.push_back("std::vector<double>* mus_ptrel");
  variables.push_back("std::vector<double>* mus_mindr_sub");
  variables.push_back("std::vector<double>* mus_ptrel_sub");
  variables.push_back("int nels");
  variables.push_back("int nvels");
  variables.push_back("std::vector<double>* els_pt");
  variables.push_back("std::vector<double>* els_gen_pt");
  variables.push_back("std::vector<double>* els_eta");
  variables.push_back("std::vector<double>* els_phi");
  variables.push_back("std::vector<double>* els_charge");
  variables.push_back("std::vector<double>* els_reliso");
  variables.push_back("std::vector<double>* els_sigid");
  variables.push_back("std::vector<double>* els_tru_dr");
  variables.push_back("std::vector<int>* els_tru_id");
  variables.push_back("std::vector<int>* els_tru_momid");
  variables.push_back("std::vector<bool>* els_tru_tm");
  variables.push_back("std::vector<double>* els_mindr");
  variables.push_back("std::vector<double>* els_ptrel");
  variables.push_back("std::vector<double>* els_mindr_sub");
  variables.push_back("std::vector<double>* els_ptrel_sub");

  /////////////////   Tracks   ////////////////
  variables.push_back("int nisotrks");

  /////////////////   Jets   //////////////////
  variables.push_back("int njets");  
  variables.push_back("int nbt");    
  variables.push_back("int nbm");    
  variables.push_back("int nbl");    
  variables.push_back("std::vector<double>* jets_pt");
  variables.push_back("std::vector<double>* jets_eta");
  variables.push_back("std::vector<double>* jets_phi");
  variables.push_back("std::vector<double>* jets_csv");

  /////////////////   Fat Jets   //////////////
  variables.push_back("int nfjets_30");  // for fjets_pt>50, all with skinny jets pt>30
  variables.push_back("float mj_30");    // for fjets_pt>50, all with skinny jets pt>30
  variables.push_back("std::vector<double>* fjets_30_pt");
  variables.push_back("std::vector<double>* fjets_30_eta");
  variables.push_back("std::vector<double>* fjets_30_phi");
  variables.push_back("std::vector<double>* fjets_30_mj");

  variables.push_back("int nfjets_scln_30");  // for fjets_pt>50, all with skinny jets pt>30
  variables.push_back("float mj_scln_30");    // for fjets_pt>50, all with skinny jets pt>30
  variables.push_back("std::vector<double>* fjets_scln_30_pt");
  variables.push_back("std::vector<double>* fjets_scln_30_eta");
  variables.push_back("std::vector<double>* fjets_scln_30_phi");
  variables.push_back("std::vector<double>* fjets_scln_30_mj");

  variables.push_back("int nfjets_vcln_30");  // for fjets_pt>50, all with skinny jets pt>30
  variables.push_back("float mj_vcln_30");    // for fjets_pt>50, all with skinny jets pt>30
  variables.push_back("std::vector<double>* fjets_vcln_30_pt");
  variables.push_back("std::vector<double>* fjets_vcln_30_eta");
  variables.push_back("std::vector<double>* fjets_vcln_30_phi");
  variables.push_back("std::vector<double>* fjets_vcln_30_mj");
  
  variables.push_back("int nfjets_0");  // for fjets_pt>50, all with skinny jets pt>0
  variables.push_back("float mj_0");    // for fjets_pt>50, all with skinny jets pt>0
  variables.push_back("std::vector<double>* fjets_0_pt");
  variables.push_back("std::vector<double>* fjets_0_eta");
  variables.push_back("std::vector<double>* fjets_0_phi");
  variables.push_back("std::vector<double>* fjets_0_mj");

  variables.push_back("int nfjets_scln_0");  // for fjets_pt>50, all with skinny jets pt>0
  variables.push_back("float mj_scln_0");    // for fjets_pt>50, all with skinny jets pt>0
  variables.push_back("std::vector<double>* fjets_scln_0_pt");
  variables.push_back("std::vector<double>* fjets_scln_0_eta");
  variables.push_back("std::vector<double>* fjets_scln_0_phi");
  variables.push_back("std::vector<double>* fjets_scln_0_mj");

  variables.push_back("int nfjets_vcln_0");  // for fjets_pt>50, all with skinny jets pt>0
  variables.push_back("float mj_vcln_0");    // for fjets_pt>50, all with skinny jets pt>0
  variables.push_back("std::vector<double>* fjets_vcln_0_pt");
  variables.push_back("std::vector<double>* fjets_vcln_0_eta");
  variables.push_back("std::vector<double>* fjets_vcln_0_phi");
  variables.push_back("std::vector<double>* fjets_vcln_0_mj");

  variables.push_back("int nfjets_cands");  // for fjets_pt>50, all pfcands
  variables.push_back("float mj_cands");    // for fjets_pt>50, all pfcands
  variables.push_back("std::vector<double>* fjets_cands_pt");
  variables.push_back("std::vector<double>* fjets_cands_eta");
  variables.push_back("std::vector<double>* fjets_cands_phi");
  variables.push_back("std::vector<double>* fjets_cands_mj");
  
  variables.push_back("int nfjets_cands_trim");  // for fjets_pt>50, all pfcands
  variables.push_back("float mj_cands_trim");    // for fjets_pt>50, all pfcands
  variables.push_back("std::vector<double>* fjets_cands_trim_pt");
  variables.push_back("std::vector<double>* fjets_cands_trim_eta");
  variables.push_back("std::vector<double>* fjets_cands_trim_phi");
  variables.push_back("std::vector<double>* fjets_cands_trim_mj");
  
  //////////////////   MC   ///////////////////
  variables.push_back("unsigned mc_type");
  variables.push_back("std::vector<double>* mc_pt");
  variables.push_back("std::vector<double>* mc_eta");
  variables.push_back("std::vector<double>* mc_phi");
  variables.push_back("std::vector<int>* mc_id");
  variables.push_back("std::vector<int>* mc_momid");
  variables.push_back("float genmet");
  variables.push_back("float genmetphi");
  variables.push_back("float genht");
  variables.push_back("float ntrupv_mean"); 
  variables.push_back("int ntrupv");

  //////////////////   Global   ///////////////////
  variables.push_back("float weight");
  variables.push_back("float wlumi");
  variables.push_back("float wl1");
  variables.push_back("int npv");
  variables.push_back("float ht");
  variables.push_back("float met");
  variables.push_back("float met_phi");
  variables.push_back("float dphi_wlep");
  variables.push_back("float mindphin_metjet");
  variables.push_back("float dr_bb");
  variables.push_back("float spher");
  variables.push_back("float spher_jets");
  variables.push_back("float spher_nolin");

  //Transverse mass variables
  variables.push_back("float mt");
  variables.push_back("float mt_genmet");

  variables.push_back("float mt2_max");
  variables.push_back("float mt2_min");
  variables.push_back("float mt2_ref_max");
  variables.push_back("float mt2_ref_min");
  variables.push_back("float mt2_high_pt");
  variables.push_back("float mt2_high_csv");

  variables.push_back("float mt2w_max");
  variables.push_back("float mt2w_min");
  variables.push_back("float mt2w_ref_max");
  variables.push_back("float mt2w_ref_min");
  variables.push_back("float mt2w_high_pt");
  variables.push_back("float mt2w_high_csv");

  variables.push_back("float mbl_max");
  variables.push_back("float mbl_subleading");
  variables.push_back("float mbl_min");
  variables.push_back("float mbl_high_pt");
  variables.push_back("float mbl_high_csv");

  variables.push_back("float mblnu_max");
  variables.push_back("float mblnu_subleading");
  variables.push_back("float mblnu_min");
  variables.push_back("float mblnu_high_pt");
  variables.push_back("float mblnu_high_csv");

  variables.push_back("float mt_bmet_min");

  std::ofstream cppFile("src/small_tree.cpp"), hppFile("inc/small_tree.hpp");
  
  //////////  hpp file  ///////////////////
  hppFile << "// small_tree: class that contains reduced cfA ntuples\n";
  hppFile << "// File generated with generate_small_tree.exe\n\n";
  hppFile << "#ifndef H_SMALL_TREE\n";
  hppFile << "#define H_SMALL_TREE\n\n";
  hppFile << "#include <vector>\n";
  hppFile << "#include \"TChain.h\"\n";
  hppFile << "#include \"TTree.h\"\n\n";

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
