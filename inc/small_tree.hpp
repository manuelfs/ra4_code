// small_tree: class that contains reduced cfA ntuples
// File generated with generate_small_tree.exe

#ifndef H_SMALL_TREE
#define H_SMALL_TREE

#include <vector>
#include "TChain.h"
#include "TTree.h"

class small_tree{
public:
  small_tree(); // Constructor to create tree
  small_tree(TString filename); // Constructor to read tree

  bool isReadOnly;
  TChain chain;
  TTree tree;
  int nleps;
  int nmus;
  int nvmus;
  std::vector<double>* mus_pt;
  std::vector<double> v_mus_pt;
  std::vector<double>* mus_gen_pt;
  std::vector<double> v_mus_gen_pt;
  std::vector<double>* mus_eta;
  std::vector<double> v_mus_eta;
  std::vector<double>* mus_phi;
  std::vector<double> v_mus_phi;
  std::vector<double>* mus_reliso;
  std::vector<double> v_mus_reliso;
  std::vector<double>* mus_tru_dr;
  std::vector<double> v_mus_tru_dr;
  std::vector<int>* mus_tru_id;
  std::vector<int> v_mus_tru_id;
  std::vector<int>* mus_tru_momid;
  std::vector<int> v_mus_tru_momid;
  int nels;
  int nvels;
  std::vector<double>* els_pt;
  std::vector<double> v_els_pt;
  std::vector<double>* els_gen_pt;
  std::vector<double> v_els_gen_pt;
  std::vector<double>* els_eta;
  std::vector<double> v_els_eta;
  std::vector<double>* els_phi;
  std::vector<double> v_els_phi;
  std::vector<double>* els_reliso;
  std::vector<double> v_els_reliso;
  std::vector<double>* els_tru_dr;
  std::vector<double> v_els_tru_dr;
  std::vector<int>* els_tru_id;
  std::vector<int> v_els_tru_id;
  std::vector<int>* els_tru_momid;
  std::vector<int> v_els_tru_momid;
  int njets;
  int nbt;
  int nbm;
  int nbl;
  std::vector<double>* jets_pt;
  std::vector<double> v_jets_pt;
  std::vector<double>* jets_eta;
  std::vector<double> v_jets_eta;
  std::vector<double>* jets_phi;
  std::vector<double> v_jets_phi;
  std::vector<double>* jets_csv;
  std::vector<double> v_jets_csv;
  int nfjets;
  float mj;
  std::vector<double>* fjets_pt;
  std::vector<double> v_fjets_pt;
  std::vector<double>* fjets_eta;
  std::vector<double> v_fjets_eta;
  std::vector<double>* fjets_phi;
  std::vector<double> v_fjets_phi;
  std::vector<double>* fjets_mj;
  std::vector<double> v_fjets_mj;
  unsigned mc_type;
  std::vector<double>* mc_pt;
  std::vector<double> v_mc_pt;
  std::vector<double>* mc_eta;
  std::vector<double> v_mc_eta;
  std::vector<double>* mc_phi;
  std::vector<double> v_mc_phi;
  std::vector<int>* mc_id;
  std::vector<int> v_mc_id;
  std::vector<int>* mc_momid;
  std::vector<int> v_mc_momid;
  float genmet;
  float genht;
  float ntrupv_mean;
  int ntrupv;
  float weight;
  float wlumi;
  float wl1;
  int npv;
  float ht;
  float mt;
  float met;
  float met_phi;
  float dphi_wlep;
  float mindphi_metjet;
  float dr_bb;
  float spher;
  float spher_jets;
  float spher_nolin;
  float mt2_max;
  float mt2_min;
  float mt2_ref_max;
  float mt2_ref_min;
  float mt2_highPt;
  float mt2_highCSV;
  float mt2w_max;
  float mt2w_min;
  float mt2w_ref_max;
  float mt2w_ref_min;
  float mt2w_highPt;
  float mt2w_highCSV;
  float mbl_max;
  float mbl_subleading;
  float mbl_min;
  float mbl_highPt;
  float mbl_highCSV;

  void Fill();
  void Write();
  int GetEntries();
};

#endif
