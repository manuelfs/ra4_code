// event_handler: Defines reduced tree with RA4 variables

#include "event_handler.hpp"

#include <cfloat>
#include <ctime>
#include <cmath>
#include <cstdio>

#include <utility>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <limits>

#include "TMath.h"
#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TLorentzVector.h"

#include "fastjet/ClusterSequence.hh"

#include "utilities.hpp"
#include "timer.hpp"
#include "mt2_bisect.hpp"
#include "mt2w_bisect.hpp"
#include "cfa_8.hpp"
#include "cfa_13.hpp"

using namespace std;
using namespace fastjet;
// const double CSVCuts[] = {0.244, 0.679, 0.898}; // Run1 CSV
const double CSVCuts[] = {0.423, 0.814, 0.941};    // Run2 CSV+IVF

// namespace{
//   const float floatmax = numeric_limits<float>::max();
// }

event_handler::event_handler(const string &fileName):
  phys_objects(fileName){
}

void event_handler::ReduceTree(int Nentries, TString outFilename,
                               int Ntotentries, bool skip_slow){

  gROOT->ProcessLine("#include <vector>"); 
  // const float bad_val = -999.;

  TFile outFile(outFilename, "recreate");
  outFile.cd();

  // // Reduced tree
  small_tree tree;
  float xsec(cross_section(outFilename));
  const float luminosity = 1000; // 1 fb^-1

  Timer timer(Nentries);
  timer.Start();
  for(int entry(0); entry < Nentries; entry++) {
    if(entry%1000==0 && entry!=0){
      timer.PrintRemainingTime();
    }
    timer.Iterate();
    GetEntry(entry);

    tree.event = event();
    tree.lumiblock = lumiblock();
    tree.run = run();

    for(size_t bc(0); bc<PU_bunchCrossing()->size(); ++bc){
      if(PU_bunchCrossing()->at(bc)==0){
        tree.ntrupv = PU_NumInteractions()->at(bc);
        tree.ntrupv_mean = PU_TrueNumInteractions()->at(bc);
        break;
      }
    }
    tree.npv = Npv();
    tree.weight = xsec*luminosity / static_cast<double>(Ntotentries);

    tree.met = mets_et()->at(0);
    tree.met_phi = mets_phi()->at(0);


    tree.els_pt.clear();
    tree.els_eta.clear();
    tree.els_phi.clear();
    tree.els_reliso.clear();
    tree.els_miniso.clear();
    tree.els_miniso_ch.clear();
    tree.els_miniso_chx.clear();
    for(size_t index(0); index<els_pt()->size(); index++) {
      if (els_pt()->at(index) > 10 && IsVetoIdElectron(index)) {
        tree.els_sigid.push_back(IsSignalIdElectron(index));
        tree.els_pt.push_back(els_pt()->at(index));
        tree.els_eta.push_back(els_eta()->at(index));
        tree.els_phi.push_back(els_phi()->at(index));
        tree.els_reliso.push_back(GetElectronIsolation(index));
        SetMiniIso(tree, index, /*isElectron*/ true);
      }
    }

    tree.mus_pt.clear();
    tree.mus_eta.clear();
    tree.mus_phi.clear();
    tree.mus_reliso.clear();
    tree.mus_miniso.clear();
    tree.mus_miniso_ch.clear();
    tree.mus_miniso_chx.clear();
    for(size_t index(0); index<mus_pt()->size(); index++) {
      if (mus_pt()->at(index) > 10 && IsVetoIdMuon(index)) {
        tree.mus_sigid.push_back(IsSignalIdMuon(index));
        tree.mus_pt.push_back(mus_pt()->at(index));
        tree.mus_eta.push_back(mus_eta()->at(index));
        tree.mus_phi.push_back(mus_phi()->at(index));
        tree.mus_reliso.push_back(GetMuonIsolation(index));
        SetMiniIso(tree, index, /*isElectron*/ false);
      }
    }


    tree.mc_pt.clear();
    tree.mc_phi.clear();
    tree.mc_eta.clear();
    tree.mc_id.clear();
    tree.mc_momid.clear();
    tree.mc_gmomid.clear();
    for(size_t igen(0); igen<mc_doc_id()->size(); igen++) { 
      tree.mc_pt.push_back(mc_doc_pt()->at(igen));  
      tree.mc_phi.push_back(mc_doc_phi()->at(igen));  
      tree.mc_eta.push_back(mc_doc_eta()->at(igen));  
      tree.mc_id.push_back(mc_doc_id()->at(igen));  
      tree.mc_momid.push_back(mc_doc_mother_id()->at(igen));  
      tree.mc_gmomid.push_back(mc_doc_grandmother_id()->at(igen));  
    }

    tree.jets_pt.clear();
    tree.jets_eta.clear();
    tree.jets_phi.clear();
    tree.jets_csv.clear();
    tree.njets = 0;
    tree.ncsvm = 0;
    tree.ht = 0.;
    vector<int> veto_electrons = GetElectrons(false);
    vector<int> veto_muons = GetMuons(false);
    vector<int> good_jets = GetJets(veto_electrons, veto_muons, 40.0, 2.4);
    for(size_t igoodjet(0); igoodjet<good_jets.size(); igoodjet++) {
      int ijet = good_jets.at(igoodjet); 
      tree.jets_pt.push_back(jets_AK4_pt()->at(ijet)); 
      tree.jets_eta.push_back(jets_AK4_eta()->at(ijet)); 
      tree.jets_phi.push_back(jets_AK4_phi()->at(ijet)); 
      tree.jets_csv.push_back(jets_AK4_btag_inc_secVertexCombined()->at(ijet)); 

      tree.njets++;
      tree.ht += jets_AK4_pt()->at(ijet);
      if (jets_AK4_btag_inc_secVertexCombined()->at(ijet) >= CSVCuts[1]) tree.ncsvm++;
    }

    WriteFatJets(tree);


    tree.Fill();
  }
  cout<<"xsec is "<<xsec<<" for a total of "<<Ntotentries<<" entries"<<endl;
  tree.Write();

  // Global tree
  GetEntry(0);
  TString model = model_params()->c_str();
  TString commit = RemoveTrailingNewlines(execute("git rev-parse HEAD"));

  TTree treeglobal("treeglobal", "treeglobal");
  treeglobal.Branch("noriginal", &Nentries);
  treeglobal.Branch("commit", &commit);
  treeglobal.Branch("model", &model);

  treeglobal.Fill();
  treeglobal.Write();


  outFile.Close();
  if (skip_slow) cout<<"Reduced tree in "<<outFilename<<endl;
}

void event_handler::SetMiniIso(small_tree &tree, int ilep, bool isElectron){

  if (isElectron && ilep==0) tree.els_miniso.push_back(0);

  return;
}


void event_handler::WriteFatJets(small_tree &tree){

  ////////////////   Fat Jets   ////////////////
  vector<PseudoJet> fjets_skinny_30(0);
  vector<PseudoJet> fjets_skinny_eta25(0);
  vector<PseudoJet> fjets_skinny_r10(0);
  vector<PseudoJet> fjets_skinny_r15(0);
  vector<PseudoJet> fjets_sig_clean_30(0);
  vector<PseudoJet> fjets_skinny_0(0);
  vector<PseudoJet> fjets_cands(0);
  vector<PseudoJet> fjets_cands_trim(0);

  vector<PseudoJet> skinny_jets_pt30, sig_clean_jets_pt30;
  vector<PseudoJet> skinny_jets_pt0, skinny_jets_eta25;
  for(size_t jet = 0; jet<jets_pt()->size(); ++jet){
    if(is_nan(jets_px()->at(jet)) || is_nan(jets_py()->at(jet))
       || is_nan(jets_pz()->at(jet)) || is_nan(jets_energy()->at(jet))) continue;

    const PseudoJet this_pj(jets_px()->at(jet), jets_py()->at(jet),
			    jets_pz()->at(jet), jets_energy()->at(jet));
    const TLorentzVector this_lv(jets_px()->at(jet), jets_py()->at(jet),
				 jets_pz()->at(jet), jets_energy()->at(jet));

    bool sig_add = true;
    for(size_t iel = 0; iel<els_pt()->size() && sig_add; ++iel){
      //Make sure skinny jet is not matched to veto electron
      if(static_cast<size_t>(els_jet_ind()->at(iel)) != jet) continue;
      if(!IsSignalElectron(iel)) continue;
      const TLorentzVector p4el(els_px()->at(iel), els_py()->at(iel),
				els_pz()->at(iel), els_energy()->at(iel));
      if(p4el.DeltaR(this_lv)<0.3){
	sig_add=false;
      }
    }
    for(size_t imu = 0; imu<mus_pt()->size() && sig_add; ++imu){
      //Make sure skinny jet is not matched to veto muon
      if(static_cast<size_t>(mus_jet_ind()->at(imu)) != jet) continue;
      if(!IsSignalMuon(imu)) continue;
      const TLorentzVector p4mu(mus_px()->at(imu), mus_py()->at(imu),
				mus_pz()->at(imu), mus_energy()->at(imu));
      if(p4mu.DeltaR(this_lv)<0.3){
	sig_add=false;
      }
    }

    skinny_jets_pt0.push_back(this_pj);
    if(this_pj.pt()>30.0) skinny_jets_pt30.push_back(this_pj);
    if(this_pj.pt()>30.0 && this_pj.eta()<2.5) skinny_jets_eta25.push_back(this_pj);
    if(sig_add && this_pj.pt()>30.0) sig_clean_jets_pt30.push_back(this_pj);
  }

  JetDefinition jet_def_10(antikt_algorithm, 1.0);
  JetDefinition jet_def_12(antikt_algorithm, 1.2);
  JetDefinition jet_def_15(antikt_algorithm, 1.5);
  ClusterSequence cs_skinny_r10(skinny_jets_pt30, jet_def_10);
  ClusterSequence cs_skinny_30(skinny_jets_pt30, jet_def_12);
  ClusterSequence cs_skinny_r15(skinny_jets_pt30, jet_def_15);
  ClusterSequence cs_sig_clean_30(sig_clean_jets_pt30, jet_def_12);
  ClusterSequence cs_skinny_0(skinny_jets_pt0, jet_def_12);
  ClusterSequence cs_skinny_eta25(skinny_jets_eta25, jet_def_12);

  fjets_skinny_30 = sorted_by_pt(cs_skinny_30.inclusive_jets());
  fjets_sig_clean_30 = sorted_by_pt(cs_sig_clean_30.inclusive_jets());
  fjets_skinny_0 = sorted_by_pt(cs_skinny_0.inclusive_jets());
  fjets_skinny_eta25 = sorted_by_pt(cs_skinny_eta25.inclusive_jets());
  fjets_skinny_r10 = sorted_by_pt(cs_skinny_r10.inclusive_jets());
  fjets_skinny_r15 = sorted_by_pt(cs_skinny_r15.inclusive_jets());

  tree.nfjets_30 = 0;
  tree.mj_30 = 0;
  tree.fjets_30_pt.resize(fjets_skinny_30.size());
  tree.fjets_30_eta.resize(fjets_skinny_30.size());
  tree.fjets_30_phi.resize(fjets_skinny_30.size());
  tree.fjets_30_m.resize(fjets_skinny_30.size());
  for(size_t ipj = 0; ipj < fjets_skinny_30.size(); ++ipj){
    const PseudoJet &pj = fjets_skinny_30.at(ipj);
    tree.fjets_30_pt.at(ipj)=pj.pt();
    tree.fjets_30_eta.at(ipj)=pj.eta();
    tree.fjets_30_phi.at(ipj)=pj.phi_std();
    tree.fjets_30_m.at(ipj)=pj.m();
    if(pj.pt()>50.0){
      tree.mj_30 += pj.m();
      ++tree.nfjets_30;
    }
  }
  tree.nfjets_scln_30 = 0;
  tree.mj_scln_30 = 0;
  tree.fjets_scln_30_pt.resize(fjets_sig_clean_30.size());
  tree.fjets_scln_30_eta.resize(fjets_sig_clean_30.size());
  tree.fjets_scln_30_phi.resize(fjets_sig_clean_30.size());
  tree.fjets_scln_30_m.resize(fjets_sig_clean_30.size());
  for(size_t ipj = 0; ipj < fjets_sig_clean_30.size(); ++ipj){
    const PseudoJet &pj = fjets_sig_clean_30.at(ipj);
    tree.fjets_scln_30_pt.at(ipj)=pj.pt();
    tree.fjets_scln_30_eta.at(ipj)=pj.eta();
    tree.fjets_scln_30_phi.at(ipj)=pj.phi_std();
    tree.fjets_scln_30_m.at(ipj)=pj.m();
    if(pj.pt()>50.0){
      tree.mj_scln_30 += pj.m();
      ++tree.nfjets_scln_30;
    }
  }
  tree.nfjets_0 = 0;
  tree.mj_0 = 0;
  tree.fjets_0_pt.resize(fjets_skinny_0.size());
  tree.fjets_0_eta.resize(fjets_skinny_0.size());
  tree.fjets_0_phi.resize(fjets_skinny_0.size());
  tree.fjets_0_m.resize(fjets_skinny_0.size());
  for(size_t ipj = 0; ipj < fjets_skinny_0.size(); ++ipj){
    const PseudoJet &pj = fjets_skinny_0.at(ipj);
    tree.fjets_0_pt.at(ipj)=pj.pt();
    tree.fjets_0_eta.at(ipj)=pj.eta();
    tree.fjets_0_phi.at(ipj)=pj.phi_std();
    tree.fjets_0_m.at(ipj)=pj.m();
    if(pj.pt()>50.0){
      tree.mj_0 += pj.m();
      ++tree.nfjets_0;
    }
  }
  tree.nfjets_eta25 = 0;
  tree.mj_eta25 = 0;
  tree.fjets_eta25_pt.resize(fjets_skinny_eta25.size());
  tree.fjets_eta25_eta.resize(fjets_skinny_eta25.size());
  tree.fjets_eta25_phi.resize(fjets_skinny_eta25.size());
  tree.fjets_eta25_m.resize(fjets_skinny_eta25.size());
  for(size_t ipj = 0; ipj < fjets_skinny_eta25.size(); ++ipj){
    const PseudoJet &pj = fjets_skinny_eta25.at(ipj);
    tree.fjets_eta25_pt.at(ipj)=pj.pt();
    tree.fjets_eta25_eta.at(ipj)=pj.eta();
    tree.fjets_eta25_phi.at(ipj)=pj.phi_std();
    tree.fjets_eta25_m.at(ipj)=pj.m();
    if(pj.pt()>50.0){
      tree.mj_eta25 += pj.m();
      ++tree.nfjets_eta25;
    }
  }
  tree.nfjets_r10 = 0;
  tree.mj_r10 = 0;
  tree.fjets_r10_pt.resize(fjets_skinny_r10.size());
  tree.fjets_r10_eta.resize(fjets_skinny_r10.size());
  tree.fjets_r10_phi.resize(fjets_skinny_r10.size());
  tree.fjets_r10_m.resize(fjets_skinny_r10.size());
  for(size_t ipj = 0; ipj < fjets_skinny_r10.size(); ++ipj){
    const PseudoJet &pj = fjets_skinny_r10.at(ipj);
    tree.fjets_r10_pt.at(ipj)=pj.pt();
    tree.fjets_r10_eta.at(ipj)=pj.eta();
    tree.fjets_r10_phi.at(ipj)=pj.phi_std();
    tree.fjets_r10_m.at(ipj)=pj.m();
    if(pj.pt()>50.0){
      tree.mj_r10 += pj.m();
      ++tree.nfjets_r10;
    }
  }
  tree.nfjets_r15 = 0;
  tree.mj_r15 = 0;
  tree.fjets_r15_pt.resize(fjets_skinny_r15.size());
  tree.fjets_r15_eta.resize(fjets_skinny_r15.size());
  tree.fjets_r15_phi.resize(fjets_skinny_r15.size());
  tree.fjets_r15_m.resize(fjets_skinny_r15.size());
  for(size_t ipj = 0; ipj < fjets_skinny_r15.size(); ++ipj){
    const PseudoJet &pj = fjets_skinny_r15.at(ipj);
    tree.fjets_r15_pt.at(ipj)=pj.pt();
    tree.fjets_r15_eta.at(ipj)=pj.eta();
    tree.fjets_r15_phi.at(ipj)=pj.phi_std();
    tree.fjets_r15_m.at(ipj)=pj.m();
    if(pj.pt()>50.0){
      tree.mj_r15 += pj.m();
      ++tree.nfjets_r15;
    }
  }

  tree.nfjets_cands = static_cast<int>(bad_val);
  tree.mj_cands = static_cast<int>(bad_val);
  tree.fjets_cands_pt.clear();
  tree.fjets_cands_eta.clear();
  tree.fjets_cands_phi.clear();
  tree.fjets_cands_m.clear();

  tree.nfjets_cands_trim = static_cast<int>(bad_val);
  tree.mj_cands_trim = static_cast<int>(bad_val);
  tree.fjets_cands_trim_pt.clear();
  tree.fjets_cands_trim_eta.clear();
  tree.fjets_cands_trim_phi.clear();
  tree.fjets_cands_trim_m.clear();
  vector<PseudoJet> cands(pfcand_pt()->size());
  TLorentzVector p4cand;
  for(size_t cand = 0; cand < pfcand_pt()->size(); ++cand){
    if(!is_nan(pfcand_pt()->at(cand)) && !is_nan(pfcand_eta()->at(cand))
       && !is_nan(pfcand_phi()->at(cand)) && !is_nan(pfcand_energy()->at(cand))){
      p4cand.SetPtEtaPhiE(pfcand_pt()->at(cand), pfcand_eta()->at(cand),
			  pfcand_phi()->at(cand), pfcand_energy()->at(cand));
      cands.at(cand)=PseudoJet(p4cand.Px(), p4cand.Py(), p4cand.Pz(), p4cand.E());
    }else{
      //Bad. We read nan for one of the momentum components. Filling with null 4-vector.
      cands.at(cand)=PseudoJet(0.0, 0.0, 0.0, 0.0);
    }
  }

  ClusterSequence cs_cands(cands, jet_def_12);
  fjets_cands = sorted_by_pt(cs_cands.inclusive_jets());

  vector<int> fj_owner = cs_cands.particle_jet_indices(fjets_cands);
  fjets_cands_trim.resize(fjets_cands.size());
  for(size_t fj = 0; fj < fjets_cands.size(); ++fj){
    vector<PseudoJet> pjs;
    for(size_t sj = 0; sj < cands.size(); ++sj){
      if(static_cast<size_t>(fj_owner.at(sj)) == fj) pjs.push_back(cands.at(sj));
    }
    ClusterSequence cs(pjs, JetDefinition(kt_algorithm, 0.2));
    pjs = cs.inclusive_jets();

    //Sum the fat jet components in place
    fjets_cands_trim.at(fj)=PseudoJet(0.0, 0.0, 0.0, 0.0);
    for(size_t pj = 0; pj < pjs.size(); ++pj){
      fjets_cands_trim.at(fj) += pjs.at(pj);
    }
    const double sumpt = fjets_cands_trim.at(fj).pt();
    fjets_cands_trim.at(fj)=PseudoJet(0.0,0.0,0.0,0.0);
    //Trim the low momentum-fraction components
    for(size_t pj = 0; pj < pjs.size(); ++pj){
      if(pjs.at(pj).pt()>0.03*sumpt){
	fjets_cands_trim.at(fj) += pjs.at(pj);
      }
    }
  } // Loop over fat jets from pfcands
  tree.nfjets_cands = 0;
  tree.mj_cands = 0;
  tree.fjets_cands_pt.resize(fjets_cands.size());
  tree.fjets_cands_eta.resize(fjets_cands.size());
  tree.fjets_cands_phi.resize(fjets_cands.size());
  tree.fjets_cands_m.resize(fjets_cands.size());
  for(size_t ipj = 0; ipj < fjets_cands.size(); ++ipj){
    const PseudoJet &pj = fjets_cands.at(ipj);
    tree.fjets_cands_pt.at(ipj)=pj.pt();
    tree.fjets_cands_eta.at(ipj)=pj.eta();
    tree.fjets_cands_phi.at(ipj)=pj.phi_std();
    tree.fjets_cands_m.at(ipj)=pj.m();
    if(pj.pt()>50.0){
      tree.mj_cands += pj.m();
      ++tree.nfjets_cands;
    }
  }
  tree.nfjets_cands_trim = 0;
  tree.mj_cands_trim = 0;
  tree.fjets_cands_trim_pt.resize(fjets_cands_trim.size());
  tree.fjets_cands_trim_eta.resize(fjets_cands_trim.size());
  tree.fjets_cands_trim_phi.resize(fjets_cands_trim.size());
  tree.fjets_cands_trim_m.resize(fjets_cands_trim.size());
  for(size_t ipj = 0; ipj < fjets_cands_trim.size(); ++ipj){
    const PseudoJet &pj = fjets_cands_trim.at(ipj);
    tree.fjets_cands_trim_pt.at(ipj)=pj.pt();
    tree.fjets_cands_trim_eta.at(ipj)=pj.eta();
    tree.fjets_cands_trim_phi.at(ipj)=pj.phi_std();
    tree.fjets_cands_trim_m.at(ipj)=pj.m();
    if(pj.pt()>50.0){
      tree.mj_cands_trim += pj.m();
      ++tree.nfjets_cands_trim;
    }
  } // Loop over trimmed fat jets


}
