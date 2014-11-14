// small_tree: class that contains reduced cfA ntuples
// File generated with generate_small_tree.exe

#include "small_tree.hpp"
#include <iostream>

using namespace std;
using std::cout;
using std::endl;

small_tree::small_tree():
  tree("tree", "tree"){
  tree.Branch("nleps", &nleps);
  tree.Branch("nmus", &nmus);
  tree.Branch("nvmus", &nvmus);
  tree.Branch("mus_pt", &mus_pt);
  mus_pt = &v_mus_pt;
  tree.Branch("mus_gen_pt", &mus_gen_pt);
  mus_gen_pt = &v_mus_gen_pt;
  tree.Branch("mus_eta", &mus_eta);
  mus_eta = &v_mus_eta;
  tree.Branch("mus_phi", &mus_phi);
  mus_phi = &v_mus_phi;
  tree.Branch("mus_charge", &mus_charge);
  mus_charge = &v_mus_charge;
  tree.Branch("mus_reliso", &mus_reliso);
  mus_reliso = &v_mus_reliso;
  tree.Branch("mus_sigid", &mus_sigid);
  mus_sigid = &v_mus_sigid;
  tree.Branch("mus_tru_dr", &mus_tru_dr);
  mus_tru_dr = &v_mus_tru_dr;
  tree.Branch("mus_tru_id", &mus_tru_id);
  mus_tru_id = &v_mus_tru_id;
  tree.Branch("mus_tru_momid", &mus_tru_momid);
  mus_tru_momid = &v_mus_tru_momid;
  tree.Branch("mus_tru_tm", &mus_tru_tm);
  mus_tru_tm = &v_mus_tru_tm;
  tree.Branch("nels", &nels);
  tree.Branch("nvels", &nvels);
  tree.Branch("els_pt", &els_pt);
  els_pt = &v_els_pt;
  tree.Branch("els_gen_pt", &els_gen_pt);
  els_gen_pt = &v_els_gen_pt;
  tree.Branch("els_eta", &els_eta);
  els_eta = &v_els_eta;
  tree.Branch("els_phi", &els_phi);
  els_phi = &v_els_phi;
  tree.Branch("els_charge", &els_charge);
  els_charge = &v_els_charge;
  tree.Branch("els_reliso", &els_reliso);
  els_reliso = &v_els_reliso;
  tree.Branch("els_sigid", &els_sigid);
  els_sigid = &v_els_sigid;
  tree.Branch("els_tru_dr", &els_tru_dr);
  els_tru_dr = &v_els_tru_dr;
  tree.Branch("els_tru_id", &els_tru_id);
  els_tru_id = &v_els_tru_id;
  tree.Branch("els_tru_momid", &els_tru_momid);
  els_tru_momid = &v_els_tru_momid;
  tree.Branch("els_tru_tm", &els_tru_tm);
  els_tru_tm = &v_els_tru_tm;
  tree.Branch("nisotrks", &nisotrks);
  tree.Branch("njets", &njets);
  tree.Branch("nbt", &nbt);
  tree.Branch("nbm", &nbm);
  tree.Branch("nbl", &nbl);
  tree.Branch("jets_pt", &jets_pt);
  jets_pt = &v_jets_pt;
  tree.Branch("jets_eta", &jets_eta);
  jets_eta = &v_jets_eta;
  tree.Branch("jets_phi", &jets_phi);
  jets_phi = &v_jets_phi;
  tree.Branch("jets_csv", &jets_csv);
  jets_csv = &v_jets_csv;
  tree.Branch("nfjets", &nfjets);
  tree.Branch("mj", &mj);
  tree.Branch("fjets_pt", &fjets_pt);
  fjets_pt = &v_fjets_pt;
  tree.Branch("fjets_eta", &fjets_eta);
  fjets_eta = &v_fjets_eta;
  tree.Branch("fjets_phi", &fjets_phi);
  fjets_phi = &v_fjets_phi;
  tree.Branch("fjets_mj", &fjets_mj);
  fjets_mj = &v_fjets_mj;
  tree.Branch("ncfjets", &ncfjets);
  tree.Branch("cmj", &cmj);
  tree.Branch("cfjets_pt", &cfjets_pt);
  cfjets_pt = &v_cfjets_pt;
  tree.Branch("cfjets_eta", &cfjets_eta);
  cfjets_eta = &v_cfjets_eta;
  tree.Branch("cfjets_phi", &cfjets_phi);
  cfjets_phi = &v_cfjets_phi;
  tree.Branch("cfjets_mj", &cfjets_mj);
  cfjets_mj = &v_cfjets_mj;
  tree.Branch("nrcfjets", &nrcfjets);
  tree.Branch("rcmj", &rcmj);
  tree.Branch("rcfjets_pt", &rcfjets_pt);
  rcfjets_pt = &v_rcfjets_pt;
  tree.Branch("rcfjets_eta", &rcfjets_eta);
  rcfjets_eta = &v_rcfjets_eta;
  tree.Branch("rcfjets_phi", &rcfjets_phi);
  rcfjets_phi = &v_rcfjets_phi;
  tree.Branch("rcfjets_mj", &rcfjets_mj);
  rcfjets_mj = &v_rcfjets_mj;
  tree.Branch("mc_type", &mc_type);
  tree.Branch("mc_pt", &mc_pt);
  mc_pt = &v_mc_pt;
  tree.Branch("mc_eta", &mc_eta);
  mc_eta = &v_mc_eta;
  tree.Branch("mc_phi", &mc_phi);
  mc_phi = &v_mc_phi;
  tree.Branch("mc_id", &mc_id);
  mc_id = &v_mc_id;
  tree.Branch("mc_momid", &mc_momid);
  mc_momid = &v_mc_momid;
  tree.Branch("genmet", &genmet);
  tree.Branch("genht", &genht);
  tree.Branch("ntrupv_mean", &ntrupv_mean);
  tree.Branch("ntrupv", &ntrupv);
  tree.Branch("weight", &weight);
  tree.Branch("wlumi", &wlumi);
  tree.Branch("wl1", &wl1);
  tree.Branch("npv", &npv);
  tree.Branch("ht", &ht);
  tree.Branch("mt", &mt);
  tree.Branch("met", &met);
  tree.Branch("met_phi", &met_phi);
  tree.Branch("dphi_wlep", &dphi_wlep);
  tree.Branch("mindphin_metjet", &mindphin_metjet);
  tree.Branch("dr_bb", &dr_bb);
  tree.Branch("spher", &spher);
  tree.Branch("spher_jets", &spher_jets);
  tree.Branch("spher_nolin", &spher_nolin);
  tree.Branch("mt2_max", &mt2_max);
  tree.Branch("mt2_min", &mt2_min);
  tree.Branch("mt2_ref_max", &mt2_ref_max);
  tree.Branch("mt2_ref_min", &mt2_ref_min);
  tree.Branch("mt2_high_pt", &mt2_high_pt);
  tree.Branch("mt2_high_csv", &mt2_high_csv);
  tree.Branch("mt2w_max", &mt2w_max);
  tree.Branch("mt2w_min", &mt2w_min);
  tree.Branch("mt2w_ref_max", &mt2w_ref_max);
  tree.Branch("mt2w_ref_min", &mt2w_ref_min);
  tree.Branch("mt2w_high_pt", &mt2w_high_pt);
  tree.Branch("mt2w_high_csv", &mt2w_high_csv);
  tree.Branch("mbl_max", &mbl_max);
  tree.Branch("mbl_subleading", &mbl_subleading);
  tree.Branch("mbl_min", &mbl_min);
  tree.Branch("mbl_high_pt", &mbl_high_pt);
  tree.Branch("mbl_high_csv", &mbl_high_csv);
  tree.Branch("mblnu_max", &mblnu_max);
  tree.Branch("mblnu_subleading", &mblnu_subleading);
  tree.Branch("mblnu_min", &mblnu_min);
  tree.Branch("mblnu_high_pt", &mblnu_high_pt);
  tree.Branch("mblnu_high_csv", &mblnu_high_csv);
  isReadOnly = false;
}

small_tree::small_tree(TString filename):
  chain("tree"){
  chain.Add(filename);
  chain.SetBranchAddress("nleps", &nleps);
  chain.SetBranchAddress("nmus", &nmus);
  chain.SetBranchAddress("nvmus", &nvmus);
  chain.SetBranchAddress("mus_pt", &mus_pt);
  chain.SetBranchAddress("mus_gen_pt", &mus_gen_pt);
  chain.SetBranchAddress("mus_eta", &mus_eta);
  chain.SetBranchAddress("mus_phi", &mus_phi);
  chain.SetBranchAddress("mus_charge", &mus_charge);
  chain.SetBranchAddress("mus_reliso", &mus_reliso);
  chain.SetBranchAddress("mus_sigid", &mus_sigid);
  chain.SetBranchAddress("mus_tru_dr", &mus_tru_dr);
  chain.SetBranchAddress("mus_tru_id", &mus_tru_id);
  chain.SetBranchAddress("mus_tru_momid", &mus_tru_momid);
  chain.SetBranchAddress("mus_tru_tm", &mus_tru_tm);
  chain.SetBranchAddress("nels", &nels);
  chain.SetBranchAddress("nvels", &nvels);
  chain.SetBranchAddress("els_pt", &els_pt);
  chain.SetBranchAddress("els_gen_pt", &els_gen_pt);
  chain.SetBranchAddress("els_eta", &els_eta);
  chain.SetBranchAddress("els_phi", &els_phi);
  chain.SetBranchAddress("els_charge", &els_charge);
  chain.SetBranchAddress("els_reliso", &els_reliso);
  chain.SetBranchAddress("els_sigid", &els_sigid);
  chain.SetBranchAddress("els_tru_dr", &els_tru_dr);
  chain.SetBranchAddress("els_tru_id", &els_tru_id);
  chain.SetBranchAddress("els_tru_momid", &els_tru_momid);
  chain.SetBranchAddress("els_tru_tm", &els_tru_tm);
  chain.SetBranchAddress("nisotrks", &nisotrks);
  chain.SetBranchAddress("njets", &njets);
  chain.SetBranchAddress("nbt", &nbt);
  chain.SetBranchAddress("nbm", &nbm);
  chain.SetBranchAddress("nbl", &nbl);
  chain.SetBranchAddress("jets_pt", &jets_pt);
  chain.SetBranchAddress("jets_eta", &jets_eta);
  chain.SetBranchAddress("jets_phi", &jets_phi);
  chain.SetBranchAddress("jets_csv", &jets_csv);
  chain.SetBranchAddress("nfjets", &nfjets);
  chain.SetBranchAddress("mj", &mj);
  chain.SetBranchAddress("fjets_pt", &fjets_pt);
  chain.SetBranchAddress("fjets_eta", &fjets_eta);
  chain.SetBranchAddress("fjets_phi", &fjets_phi);
  chain.SetBranchAddress("fjets_mj", &fjets_mj);
  chain.SetBranchAddress("ncfjets", &ncfjets);
  chain.SetBranchAddress("cmj", &cmj);
  chain.SetBranchAddress("cfjets_pt", &cfjets_pt);
  chain.SetBranchAddress("cfjets_eta", &cfjets_eta);
  chain.SetBranchAddress("cfjets_phi", &cfjets_phi);
  chain.SetBranchAddress("cfjets_mj", &cfjets_mj);
  chain.SetBranchAddress("nrcfjets", &nrcfjets);
  chain.SetBranchAddress("rcmj", &rcmj);
  chain.SetBranchAddress("rcfjets_pt", &rcfjets_pt);
  chain.SetBranchAddress("rcfjets_eta", &rcfjets_eta);
  chain.SetBranchAddress("rcfjets_phi", &rcfjets_phi);
  chain.SetBranchAddress("rcfjets_mj", &rcfjets_mj);
  chain.SetBranchAddress("mc_type", &mc_type);
  chain.SetBranchAddress("mc_pt", &mc_pt);
  chain.SetBranchAddress("mc_eta", &mc_eta);
  chain.SetBranchAddress("mc_phi", &mc_phi);
  chain.SetBranchAddress("mc_id", &mc_id);
  chain.SetBranchAddress("mc_momid", &mc_momid);
  chain.SetBranchAddress("genmet", &genmet);
  chain.SetBranchAddress("genht", &genht);
  chain.SetBranchAddress("ntrupv_mean", &ntrupv_mean);
  chain.SetBranchAddress("ntrupv", &ntrupv);
  chain.SetBranchAddress("weight", &weight);
  chain.SetBranchAddress("wlumi", &wlumi);
  chain.SetBranchAddress("wl1", &wl1);
  chain.SetBranchAddress("npv", &npv);
  chain.SetBranchAddress("ht", &ht);
  chain.SetBranchAddress("mt", &mt);
  chain.SetBranchAddress("met", &met);
  chain.SetBranchAddress("met_phi", &met_phi);
  chain.SetBranchAddress("dphi_wlep", &dphi_wlep);
  chain.SetBranchAddress("mindphin_metjet", &mindphin_metjet);
  chain.SetBranchAddress("dr_bb", &dr_bb);
  chain.SetBranchAddress("spher", &spher);
  chain.SetBranchAddress("spher_jets", &spher_jets);
  chain.SetBranchAddress("spher_nolin", &spher_nolin);
  chain.SetBranchAddress("mt2_max", &mt2_max);
  chain.SetBranchAddress("mt2_min", &mt2_min);
  chain.SetBranchAddress("mt2_ref_max", &mt2_ref_max);
  chain.SetBranchAddress("mt2_ref_min", &mt2_ref_min);
  chain.SetBranchAddress("mt2_high_pt", &mt2_high_pt);
  chain.SetBranchAddress("mt2_high_csv", &mt2_high_csv);
  chain.SetBranchAddress("mt2w_max", &mt2w_max);
  chain.SetBranchAddress("mt2w_min", &mt2w_min);
  chain.SetBranchAddress("mt2w_ref_max", &mt2w_ref_max);
  chain.SetBranchAddress("mt2w_ref_min", &mt2w_ref_min);
  chain.SetBranchAddress("mt2w_high_pt", &mt2w_high_pt);
  chain.SetBranchAddress("mt2w_high_csv", &mt2w_high_csv);
  chain.SetBranchAddress("mbl_max", &mbl_max);
  chain.SetBranchAddress("mbl_subleading", &mbl_subleading);
  chain.SetBranchAddress("mbl_min", &mbl_min);
  chain.SetBranchAddress("mbl_high_pt", &mbl_high_pt);
  chain.SetBranchAddress("mbl_high_csv", &mbl_high_csv);
  chain.SetBranchAddress("mblnu_max", &mblnu_max);
  chain.SetBranchAddress("mblnu_subleading", &mblnu_subleading);
  chain.SetBranchAddress("mblnu_min", &mblnu_min);
  chain.SetBranchAddress("mblnu_high_pt", &mblnu_high_pt);
  chain.SetBranchAddress("mblnu_high_csv", &mblnu_high_csv);
  isReadOnly = true;
}

void small_tree::Fill(){
  if(isReadOnly) cout<<"Tree is read only"<<endl;
  else tree.Fill();
}

void small_tree::Write(){
  if(isReadOnly) chain.Write();
  else tree.Write();
}

int small_tree::GetEntries(){
  if(isReadOnly) return chain.GetEntries();
  else return tree.GetEntries();
}

