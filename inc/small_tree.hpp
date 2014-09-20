// small_tree: class that contains reduced cfA ntuples
// File generated with generate_small_tree.exe

#ifndef H_SMALL_TREE
#define H_SMALL_TREE

#include <vector>
#include "TChain.h"
#include "TTree.h"

using namespace std;

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
  vector<double>* mus_pt;
  vector<double> v_mus_pt;
  vector<double>* mus_gen_pt;
  vector<double> v_mus_gen_pt;
  vector<double>* mus_eta;
  vector<double> v_mus_eta;
  vector<double>* mus_phi;
  vector<double> v_mus_phi;
  vector<double>* mus_reliso;
  vector<double> v_mus_reliso;
  vector<double>* mus_tru_dr;
  vector<double> v_mus_tru_dr;
  vector<int>* mus_tru_id;
  vector<int> v_mus_tru_id;
  vector<int>* mus_tru_momid;
  vector<int> v_mus_tru_momid;
  int nels;
  int nvels;
  vector<double>* els_pt;
  vector<double> v_els_pt;
  vector<double>* els_gen_pt;
  vector<double> v_els_gen_pt;
  vector<double>* els_eta;
  vector<double> v_els_eta;
  vector<double>* els_phi;
  vector<double> v_els_phi;
  vector<double>* els_reliso;
  vector<double> v_els_reliso;
  vector<double>* els_tru_dr;
  vector<double> v_els_tru_dr;
  vector<int>* els_tru_id;
  vector<int> v_els_tru_id;
  vector<int>* els_tru_momid;
  vector<int> v_els_tru_momid;
  vector<int>* njets;
  vector<int> v_njets;
  vector<int>* nbt;
  vector<int> v_nbt;
  vector<int>* nbm;
  vector<int> v_nbm;
  vector<int>* nbl;
  vector<int> v_nbl;
  vector<double>* jets_pt;
  vector<double> v_jets_pt;
  vector<double>* jets_eta;
  vector<double> v_jets_eta;
  vector<double>* jets_phi;
  vector<double> v_jets_phi;
  vector<double>* jets_csv;
  vector<double> v_jets_csv;
  vector<double>* genmus_pt;
  vector<double> v_genmus_pt;
  vector<double>* genmus_eta;
  vector<double> v_genmus_eta;
  vector<double>* genmus_phi;
  vector<double> v_genmus_phi;
  vector<double>* genels_pt;
  vector<double> v_genels_pt;
  vector<double>* genels_eta;
  vector<double> v_genels_eta;
  vector<double>* genels_phi;
  vector<double> v_genels_phi;
  int npv;
  int ntrupv;
  float weight;
  float ht;
  float mt;
  float met;
  float genmet;
  float genht;
  float met_phi;
  float dphi_wlep;
  float dr_bb;
  float spher;
  float spher_jets;
  float spher_nolin;
  float ntrupv_mean;

  void Fill();
  void Write();
  int GetEntries();
};

#endif
