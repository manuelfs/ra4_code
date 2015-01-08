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

namespace{
  const float fltmax = numeric_limits<float>::max();
}

event_handler::event_handler(const string &fileName, bool quick_mode):
  phys_objects(fileName),
  skip_slow(quick_mode){
  }

void event_handler::ReduceTree(int Nentries, TString outFilename,
                               int Ntotentries){

  gROOT->ProcessLine("#include <vector>");
  // const float bad_val = -999.;

  TFile outFile(outFilename, "recreate");
  outFile.cd();

  // // Reduced tree
  small_tree tree;
  float xsec(cross_section(outFilename));
  const float luminosity = 1000; // 1 fb^-1
  TLorentzVector lepmax_p4;

  Timer timer(Nentries, 1.);
  timer.Start();
  for(int entry = 0; entry < Nentries; ++entry){
    timer.Iterate();
    GetEntry(entry);

    ////////////////   Provenance   /////////////
    tree.event() = event();
    tree.lumiblock() = lumiblock();
    tree.run() = run();

    for(size_t bc(0); bc<PU_bunchCrossing()->size(); ++bc){
      if(PU_bunchCrossing()->at(bc)==0){
        tree.ntrupv() = PU_NumInteractions()->at(bc);
        tree.ntrupv_mean() = PU_TrueNumInteractions()->at(bc);
        break;
      }
    }
    tree.npv() = Npv();
    tree.weight() = xsec*luminosity / static_cast<double>(Ntotentries);

    tree.met() = mets_et()->at(0);
    tree.met_phi() = mets_phi()->at(0);
    tree.mindphin_metjet() = GetMinDeltaPhiMETN(3, 50.0, 2.4, 30.0, 2.4, true);

    ////////////////   Leptons   ////////////////
    bool fromW(false);
    int mcID, mcmomID;
    float deltaR;
    vector<float> mus_ptrel_0(0), els_ptrel_0(0);
    vector<float> mus_mindr_0(0), els_mindr_0(0);
    vector<float> mus_ptrel_25(0), els_ptrel_25(0);
    vector<float> mus_mindr_25(0), els_mindr_25(0);
    vector<float> mus_ptrel_rem_0(0), els_ptrel_rem_0(0);
    vector<float> mus_mindr_rem_0(0), els_mindr_rem_0(0);
    vector<float> mus_ptrel_rem_25(0), els_ptrel_rem_25(0);
    vector<float> mus_mindr_rem_25(0), els_mindr_rem_25(0);
    lepmax_p4.SetPtEtaPhiE(0,0,0,0);
    if(!skip_slow){
      GetPtRels(els_ptrel_0, els_mindr_0, mus_ptrel_0, mus_mindr_0, 0.0, false);
      GetPtRels(els_ptrel_25, els_mindr_25, mus_ptrel_25, mus_mindr_25, 25.0, false);
      GetPtRels(els_ptrel_rem_0, els_mindr_rem_0, mus_ptrel_rem_0, mus_mindr_rem_0, 0.0, true);
      GetPtRels(els_ptrel_rem_25, els_mindr_rem_25, mus_ptrel_rem_25, mus_mindr_rem_25,
                25.0, true);
    }else{
      els_ptrel_0 = vector<float>(els_pt()->size(), bad_val);
      els_mindr_0 = vector<float>(els_pt()->size(), bad_val);
      mus_ptrel_0 = vector<float>(mus_pt()->size(), bad_val);
      mus_mindr_0 = vector<float>(mus_pt()->size(), bad_val);
      els_ptrel_25 = vector<float>(els_pt()->size(), bad_val);
      els_mindr_25 = vector<float>(els_pt()->size(), bad_val);
      mus_ptrel_25 = vector<float>(mus_pt()->size(), bad_val);
      mus_mindr_25 = vector<float>(mus_pt()->size(), bad_val);
      els_ptrel_rem_0 = vector<float>(els_pt()->size(), bad_val);
      els_mindr_rem_0 = vector<float>(els_pt()->size(), bad_val);
      mus_ptrel_rem_0 = vector<float>(mus_pt()->size(), bad_val);
      mus_mindr_rem_0 = vector<float>(mus_pt()->size(), bad_val);
      els_ptrel_rem_25 = vector<float>(els_pt()->size(), bad_val);
      els_mindr_rem_25 = vector<float>(els_pt()->size(), bad_val);
      mus_ptrel_rem_25 = vector<float>(mus_pt()->size(), bad_val);
      mus_mindr_rem_25 = vector<float>(mus_pt()->size(), bad_val);
    }

    tree.nels() = 0; tree.nvels() = 0; tree.nvels10() = 0;
    for(size_t index(0); index<els_pt()->size(); index++) {
      if (els_pt()->at(index) > 10 && IsVetoIdElectron(index)) {
        tree.els_sigid().push_back(IsSignalIdElectron(index));
        tree.els_ispf().push_back(els_isPF()->at(index));
        tree.els_pt().push_back(els_pt()->at(index));
        tree.els_eta().push_back(els_eta()->at(index));
        tree.els_phi().push_back(els_phi()->at(index));
        tree.els_charge().push_back(TMath::Nint(els_charge()->at(index)));

        // MC truth
        mcID = GetTrueElectron(static_cast<int>(index), mcmomID, fromW, deltaR);
        tree.els_tru_id().push_back(mcID);
        tree.els_tru_momid().push_back(mcmomID);
        tree.els_tru_tm().push_back(abs(mcID)==pdtlund::e_minus && fromW);
        tree.els_tru_dr().push_back(deltaR);

        // Isolation
        tree.els_reliso().push_back(GetElectronIsolation(index));
        SetMiniIso(tree, index, /*isElectron*/ true);
        tree.els_ptrel_0().push_back(els_ptrel_0.at(index));
        tree.els_mindr_0().push_back(els_mindr_0.at(index));
        tree.els_ptrel_25().push_back(els_ptrel_25.at(index));
        tree.els_mindr_25().push_back(els_mindr_25.at(index));
        tree.els_ptrel_rem_0().push_back(els_ptrel_rem_0.at(index));
        tree.els_mindr_rem_0().push_back(els_mindr_rem_0.at(index));
        tree.els_ptrel_rem_25().push_back(els_ptrel_rem_25.at(index));
        tree.els_mindr_rem_25().push_back(els_mindr_rem_25.at(index));

        // Max pT lepton
        if(els_pt()->at(index) > lepmax_p4.Pt() && IsSignalElectron(index))
          lepmax_p4 = TLorentzVector(els_px()->at(index), els_py()->at(index),
                                     els_pz()->at(index), els_energy()->at(index));

        // Number of leptons
        if(IsVetoIdElectron(index, true)) ++(tree.nvels10());
        if(IsVetoElectron(index)) ++(tree.nvels());
        if(IsSignalElectron(index)) ++(tree.nels());
      }
    } // Loop over els

    tree.nmus() = 0; tree.nvmus() = 0; tree.nvmus10() = 0;
    for(size_t index(0); index<mus_pt()->size(); index++) {
      if (mus_pt()->at(index) > 10 && IsVetoIdMuon(index)) {
        tree.mus_sigid().push_back(IsSignalIdMuon(index));
        tree.mus_pt().push_back(mus_pt()->at(index));
        tree.mus_eta().push_back(mus_eta()->at(index));
        tree.mus_phi().push_back(mus_phi()->at(index));
        tree.mus_charge().push_back(TMath::Nint(mus_charge()->at(index)));

        // MC truth
        mcID = GetTrueMuon(static_cast<int>(index), mcmomID, fromW, deltaR);
        tree.mus_tru_id().push_back(mcID);
        tree.mus_tru_momid().push_back(mcmomID);
        tree.mus_tru_tm().push_back(abs(mcID)==pdtlund::mu_minus && fromW);
        tree.mus_tru_dr().push_back(deltaR);

        // Isolation
        tree.mus_reliso().push_back(GetMuonIsolation(index));
        SetMiniIso(tree, index, /*isElectron*/ false);
        tree.mus_ptrel_0().push_back(mus_ptrel_0.at(index));
        tree.mus_mindr_0().push_back(mus_mindr_0.at(index));
        tree.mus_ptrel_25().push_back(mus_ptrel_25.at(index));
        tree.mus_mindr_25().push_back(mus_mindr_25.at(index));
        tree.mus_ptrel_rem_0().push_back(mus_ptrel_rem_0.at(index));
        tree.mus_mindr_rem_0().push_back(mus_mindr_rem_0.at(index));
        tree.mus_ptrel_rem_25().push_back(mus_ptrel_rem_25.at(index));
        tree.mus_mindr_rem_25().push_back(mus_mindr_rem_25.at(index));

        // Max pT lepton
        if(mus_pt()->at(index) > lepmax_p4.Pt() && IsSignalMuon(index))
          lepmax_p4 = TLorentzVector(mus_px()->at(index), mus_py()->at(index),
                                     mus_pz()->at(index), mus_energy()->at(index));

        // Number of leptons
        if(GetMuonIsolation(index) < 0.2) ++(tree.nvmus10());
        if(IsVetoMuon(index)) ++(tree.nvmus());
        if(IsSignalMuon(index)) ++(tree.nmus());
      }
    }
    if(tree.nels()+tree.nmus() == tree.nvels()+tree.nvmus()){
      tree.nleps() = tree.nels()+tree.nmus();
    }else{
      tree.nleps() = static_cast<int>(bad_val);
    }

    // Finding mT and DeltaPhi with respect to highest pT lepton
    tree.mt() = bad_val; tree.dphi_wlep() = bad_val;
    if(lepmax_p4.Pt() > 0){
      double lepmax_phi = atan2(lepmax_p4.Py(), lepmax_p4.Px());
      double Wx = mets_ex()->at(0) + lepmax_p4.Px();
      double Wy = mets_ey()->at(0) + lepmax_p4.Py();
      //tree.dphi_wlep() = abs(atan2(Wy,Wx)-lepmax_p4.Phi());
      tree.dphi_wlep() = abs(atan2(Wy,Wx)-lepmax_phi);
      if(tree.dphi_wlep() > PI) tree.dphi_wlep() = 2*PI-tree.dphi_wlep();
      tree.mt() = sqrt(2*lepmax_p4.Pt()* tree.met()*(1-cos(tree.met_phi()-lepmax_p4.Phi())));
    }

    ////////////////   TRUTH   ////////////////
    // for(size_t igen(0); igen<mc_doc_id()->size(); igen++) {
    //   tree.mc_pt().push_back(mc_doc_pt()->at(igen));
    //   tree.mc_phi().push_back(mc_doc_phi()->at(igen));
    //   tree.mc_eta().push_back(mc_doc_eta()->at(igen));
    //   tree.mc_id().push_back(mc_doc_id()->at(igen));
    //   tree.mc_momid().push_back(mc_doc_mother_id()->at(igen));
    //   tree.mc_gmomid().push_back(mc_doc_grandmother_id()->at(igen));
    // }
    tree.mc_type() = TypeCode();

    ////////////////   Jets   ////////////////
    vector<int> veto_electrons = GetElectrons(false);
    vector<int> veto_muons = GetMuons(false);
    vector<int> good_jets = GetJets(veto_electrons, veto_muons, 20.0, 2.4);

    tree.njets() = GetNumJets(good_jets, MinJetPt);
    tree.nbl() = GetNumJets(good_jets, MinJetPt, CSVCuts[0]);
    tree.nbm() = GetNumJets(good_jets, MinJetPt, CSVCuts[1]);
    tree.nbt() = GetNumJets(good_jets, MinJetPt, CSVCuts[2]);
    tree.ht() = GetHT(good_jets, MinJetPt);

    vector<int> good_jets_ra2 = GetJets(vector<int>(), vector<int>(), 30.0, 2.4);
    tree.njets30() = GetNumJets(good_jets_ra2, 30.0);
    tree.nbl30() = GetNumJets(good_jets_ra2, 30.0, CSVCuts[0]);
    tree.nbm30() = GetNumJets(good_jets_ra2, 30.0, CSVCuts[1]);
    tree.nbt30() = GetNumJets(good_jets_ra2, 30.0, CSVCuts[2]);
    tree.ht30() = GetHT(good_jets_ra2, 30.0);
    tree.mht30() = GetMHT(good_jets_ra2, 30.0);

    for(size_t igoodjet(0); igoodjet<good_jets.size(); igoodjet++){
      int ijet = good_jets.at(igoodjet);
      tree.jets_pt().push_back(jets_AK4_pt()->at(ijet));
      tree.jets_eta().push_back(jets_AK4_eta()->at(ijet));
      tree.jets_phi().push_back(jets_AK4_phi()->at(ijet));
      tree.jets_csv().push_back(jets_AK4_btag_inc_secVertexCombined()->at(ijet));
      tree.jets_id().push_back(jets_AK4_parton_Id()->at(ijet));
    }
    SumDeltaPhiVars(tree, good_jets);

    tree.min_mt_bmet() = GetMinMTWb(good_jets_ra2, 30., CSVCuts[1], false);
    tree.min_mt_bmet_with_w_mass() = GetMinMTWb(good_jets_ra2, 30., CSVCuts[1], true);

    ////////////////   Fat Jets   ////////////////
    WriteFatJets(tree);

    // Taus
    WriteTaus(tree);
    // Isolated Tracks
    WriteIsoTks(tree);

    tree.Fill(); // This method automatically clears all small_tree::vectors
  }
  cout<<"xsec is "<<xsec<<" for a total of "<<Ntotentries<<" entries"<<endl;
  tree.Write();

  // Global tree
  GetEntry(0);
  TString model = model_params()->c_str();
  TString commit = RemoveTrailingNewlines(execute("git rev-parse HEAD"));

  TTree treeglobal("treeglobal", "treeglobal");
  treeglobal.Branch("nev_file", &Nentries);
  treeglobal.Branch("nev_sample", &Ntotentries);
  treeglobal.Branch("commit", &commit);
  treeglobal.Branch("model", &model);

  treeglobal.Fill();
  treeglobal.Write();

  outFile.Close();
  if (skip_slow) cout<<"Reduced tree in "<<outFilename<<endl;
}

void event_handler::WriteTaus(small_tree &tree){
  tree.ntaus()=0;
  tree.ntaus_mt100()=0;
  tree.ntaus_againstEMu()=0;
  tree.ntaus_againstEMu_mt100()=0;
  for (uint itau(0); itau<taus_pt()->size(); itau++) {
    if (taus_pt()->at(itau)<20) continue;
    if (fabs(taus_eta()->at(itau))>2.3) continue;
    if (!taus_byDecayModeFinding()->at(itau)) continue;

    bool againstEMu = taus_againstMuonLoose3()->at(itau)&&taus_againstElectronLooseMVA5()->at(itau);
    tree.taus_pt().push_back(taus_pt()->at(itau));
    tree.taus_againstEMu().push_back(againstEMu);
    tree.taus_eta().push_back(taus_eta()->at(itau));
    tree.taus_phi().push_back(taus_phi()->at(itau));
    tree.taus_chargedIsoPtSum().push_back(taus_chargedIsoPtSum()->at(itau));
    float mt_tau = GetMT(taus_pt()->at(itau), taus_phi()->at(itau),
                         mets_et()->at(0), mets_phi()->at(0));
    tree.taus_mt().push_back(mt_tau);
    tree.taus_n_pfcands().push_back(taus_n_pfcands()->at(itau));
    tree.taus_decayMode().push_back(taus_decayMode()->at(itau));
    tree.taus_CombinedIsolationDeltaBetaCorrRaw3Hits().push_back(taus_CombinedIsolationDeltaBetaCorrRaw3Hits()->at(itau));
    if (taus_chargedIsoPtSum()->at(itau) < 1.) {
      tree.ntaus()++;
      if (mt_tau<100) tree.ntaus_mt100()++;
      if (againstEMu) tree.ntaus_againstEMu()++;
      if (againstEMu && mt_tau<100) tree.ntaus_againstEMu_mt100()++;
    }
  }
}

void event_handler::WriteIsoTks(small_tree &tree){
  tree.nisotk10()=0;
  tree.nisotk15()=0;
  tree.nisotk10_mt100()=0;
  tree.nisotk15_mt100()=0;
  for (uint itrk(0); itrk<isotk_pt()->size(); itrk++) {
    tree.isotk_pt().push_back(isotk_pt()->at(itrk));
    tree.isotk_iso().push_back(isotk_iso()->at(itrk));
    float mt_itrk = GetMT(isotk_pt()->at(itrk), isotk_phi()->at(itrk),
                          mets_et()->at(0), mets_phi()->at(0));
    tree.isotk_mt().push_back(mt_itrk);
    tree.isotk_eta().push_back(isotk_eta()->at(itrk));
    tree.isotk_dzpv().push_back(isotk_dzpv()->at(itrk));
    if (!(isotk_pt()->at(itrk)>=10.
          && (isotk_iso()->at(itrk)/isotk_pt()->at(itrk) < 0.1)
          && (fabs(isotk_dzpv()->at(itrk))<0.05)
          && (fabs(isotk_eta()->at(itrk))<2.4))) continue;
    tree.nisotk10()++;
    if (mt_itrk<100) tree.nisotk10_mt100()++;
    if (isotk_pt()->at(itrk)>15) {
      tree.nisotk15()++;
      if (mt_itrk<100) tree.nisotk15_mt100()++;
    }
  }
}

void event_handler::WriteFatJets(small_tree &tree){
  vector<PseudoJet> fjets_skinny_10(0);
  vector<PseudoJet> fjets_skinny_20(0);
  vector<PseudoJet> fjets_skinny_30(0);
  vector<PseudoJet> fjets_skinny_40(0);
  vector<PseudoJet> fjets_skinny_eta25(0);
  vector<PseudoJet> fjets_skinny_r08(0);
  vector<PseudoJet> fjets_skinny_r10(0);
  vector<PseudoJet> fjets_skinny_r14(0);
  vector<PseudoJet> fjets_skinny_nolep_30(0);
  vector<PseudoJet> fjets_skinny_siglep_30(0);
  vector<PseudoJet> fjets_cands(0);
  vector<PseudoJet> fjets_cands_trim(0);

  vector<PseudoJet> skinny_jets_30, skinny_nolep_jets_pt30, skinny_siglep_jets_pt30, skinny_jets_eta25;
  vector<PseudoJet> skinny_jets_10, skinny_jets_20, skinny_jets_40;
  for(size_t jet = 0; jet<jets_pt()->size(); ++jet){
    if(is_nan(jets_px()->at(jet)) || is_nan(jets_py()->at(jet))
       || is_nan(jets_pz()->at(jet)) || is_nan(jets_energy()->at(jet))) continue;

    if(fabs(jets_eta()->at(jet))>5.) continue;

    const PseudoJet this_pj(jets_px()->at(jet), jets_py()->at(jet),
                            jets_pz()->at(jet), jets_energy()->at(jet));
    const TLorentzVector this_lv(jets_px()->at(jet), jets_py()->at(jet),
                                 jets_pz()->at(jet), jets_energy()->at(jet));
    PseudoJet sig_lepton(0,0,0,0);

    // Finding signal leptons were used in the clustering of the jet
    bool lep_in_jet = false;
    for(size_t iel = 0; iel<els_pt()->size() && !lep_in_jet; ++iel){
      if(static_cast<size_t>(els_jet_ind()->at(iel)) == jet && IsSignalElectron(iel)) {
        lep_in_jet=true;
        sig_lepton.reset(els_px()->at(iel), els_py()->at(iel),
                         els_pz()->at(iel), els_energy()->at(iel));
      }
    }
    for(size_t imu = 0; imu<mus_pt()->size() && !lep_in_jet; ++imu){
      if(static_cast<size_t>(mus_jet_ind()->at(imu)) == jet  && IsSignalMuon(imu)) {
        lep_in_jet=true;
        sig_lepton.reset(mus_px()->at(imu), mus_py()->at(imu),
                         mus_pz()->at(imu), mus_energy()->at(imu));
      }
    } // If both el and mu in jet, just add the mu. Come on, this shouldn't happen!

    if(this_pj.pt()>10.0) skinny_jets_10.push_back(this_pj);
    if(this_pj.pt()>20.0) skinny_jets_20.push_back(this_pj);
    if(this_pj.pt()>30.0) skinny_jets_30.push_back(this_pj);
    if(this_pj.pt()>40.0) skinny_jets_40.push_back(this_pj);
    if(this_pj.pt()>30.0 && fabs(this_pj.eta())<2.5) skinny_jets_eta25.push_back(this_pj);
    if(!lep_in_jet) {
      if(this_pj.pt()>30.0) {
        skinny_nolep_jets_pt30.push_back(this_pj);
        skinny_siglep_jets_pt30.push_back(this_pj);
      }
    } else skinny_siglep_jets_pt30.push_back(sig_lepton);
  }

  JetDefinition jet_def_r08(antikt_algorithm, 0.8);
  JetDefinition jet_def_r10(antikt_algorithm, 1.0);
  JetDefinition jet_def_r12(antikt_algorithm, 1.2);
  JetDefinition jet_def_r14(antikt_algorithm, 1.4);
  ClusterSequence cs_skinny_r08(skinny_jets_30, jet_def_r08);
  ClusterSequence cs_skinny_r10(skinny_jets_30, jet_def_r10);
  ClusterSequence cs_skinny_30(skinny_jets_30, jet_def_r12);
  ClusterSequence cs_skinny_r14(skinny_jets_30, jet_def_r14);
  ClusterSequence cs_skinny_nolep_30(skinny_nolep_jets_pt30, jet_def_r12);
  ClusterSequence cs_skinny_siglep_30(skinny_siglep_jets_pt30, jet_def_r12);
  ClusterSequence cs_skinny_10(skinny_jets_10, jet_def_r12);
  ClusterSequence cs_skinny_20(skinny_jets_20, jet_def_r12);
  ClusterSequence cs_skinny_40(skinny_jets_40, jet_def_r12);
  ClusterSequence cs_skinny_eta25(skinny_jets_eta25, jet_def_r12);

  fjets_skinny_30 = sorted_by_pt(cs_skinny_30.inclusive_jets());
  fjets_skinny_nolep_30 = sorted_by_pt(cs_skinny_nolep_30.inclusive_jets());
  fjets_skinny_siglep_30 = sorted_by_pt(cs_skinny_siglep_30.inclusive_jets());
  fjets_skinny_10 = sorted_by_pt(cs_skinny_10.inclusive_jets());
  fjets_skinny_20 = sorted_by_pt(cs_skinny_20.inclusive_jets());
  fjets_skinny_40 = sorted_by_pt(cs_skinny_40.inclusive_jets());
  fjets_skinny_eta25 = sorted_by_pt(cs_skinny_eta25.inclusive_jets());
  fjets_skinny_r08 = sorted_by_pt(cs_skinny_r08.inclusive_jets());
  fjets_skinny_r10 = sorted_by_pt(cs_skinny_r10.inclusive_jets());
  fjets_skinny_r14 = sorted_by_pt(cs_skinny_r14.inclusive_jets());

  tree.nfjets_30() = 0;
  tree.mj_30() = 0;
  tree.fjets_30_pt().resize(fjets_skinny_30.size());
  tree.fjets_30_eta().resize(fjets_skinny_30.size());
  tree.fjets_30_phi().resize(fjets_skinny_30.size());
  tree.fjets_30_m().resize(fjets_skinny_30.size());
  for(size_t ipj = 0; ipj < fjets_skinny_30.size(); ++ipj){
    const PseudoJet &pj = fjets_skinny_30.at(ipj);
    tree.fjets_30_pt().at(ipj)=pj.pt();
    tree.fjets_30_eta().at(ipj)=pj.eta();
    tree.fjets_30_phi().at(ipj)=pj.phi_std();
    tree.fjets_30_m().at(ipj)=pj.m();
    if(pj.pt()>50.0){
      tree.mj_30() += pj.m();
      ++(tree.nfjets_30());
    }
  }

  tree.nfjets_nolep_30() = 0;
  tree.mj_nolep_30() = 0;
  tree.fjets_nolep_30_pt().resize(fjets_skinny_nolep_30.size());
  tree.fjets_nolep_30_eta().resize(fjets_skinny_nolep_30.size());
  tree.fjets_nolep_30_phi().resize(fjets_skinny_nolep_30.size());
  tree.fjets_nolep_30_m().resize(fjets_skinny_nolep_30.size());
  for(size_t ipj = 0; ipj < fjets_skinny_nolep_30.size(); ++ipj){
    const PseudoJet &pj = fjets_skinny_nolep_30.at(ipj);
    tree.fjets_nolep_30_pt().at(ipj)=pj.pt();
    tree.fjets_nolep_30_eta().at(ipj)=pj.eta();
    tree.fjets_nolep_30_phi().at(ipj)=pj.phi_std();
    tree.fjets_nolep_30_m().at(ipj)=pj.m();
    if(pj.pt()>50.0){
      tree.mj_nolep_30() += pj.m();
      ++(tree.nfjets_nolep_30());
    }
  }

  tree.nfjets_siglep_30() = 0;
  tree.mj_siglep_30() = 0;
  tree.fjets_siglep_30_pt().resize(fjets_skinny_siglep_30.size());
  tree.fjets_siglep_30_eta().resize(fjets_skinny_siglep_30.size());
  tree.fjets_siglep_30_phi().resize(fjets_skinny_siglep_30.size());
  tree.fjets_siglep_30_m().resize(fjets_skinny_siglep_30.size());
  for(size_t ipj = 0; ipj < fjets_skinny_siglep_30.size(); ++ipj){
    const PseudoJet &pj = fjets_skinny_siglep_30.at(ipj);
    tree.fjets_siglep_30_pt().at(ipj)=pj.pt();
    tree.fjets_siglep_30_eta().at(ipj)=pj.eta();
    tree.fjets_siglep_30_phi().at(ipj)=pj.phi_std();
    tree.fjets_siglep_30_m().at(ipj)=pj.m();
    if(pj.pt()>50.0){
      tree.mj_siglep_30() += pj.m();
      ++(tree.nfjets_siglep_30());
    }
  }

  tree.nfjets_10() = 0;
  tree.mj_10() = 0;
  tree.fjets_10_pt().resize(fjets_skinny_10.size());
  tree.fjets_10_eta().resize(fjets_skinny_10.size());
  tree.fjets_10_phi().resize(fjets_skinny_10.size());
  tree.fjets_10_m().resize(fjets_skinny_10.size());
  for(size_t ipj = 0; ipj < fjets_skinny_10.size(); ++ipj){
    const PseudoJet &pj = fjets_skinny_10.at(ipj);
    tree.fjets_10_pt().at(ipj)=pj.pt();
    tree.fjets_10_eta().at(ipj)=pj.eta();
    tree.fjets_10_phi().at(ipj)=pj.phi_std();
    tree.fjets_10_m().at(ipj)=pj.m();
    if(pj.pt()>50.0){
      tree.mj_10() += pj.m();
      ++(tree.nfjets_10());
    }
  }

  tree.nfjets_20() = 0;
  tree.mj_20() = 0;
  tree.fjets_20_pt().resize(fjets_skinny_20.size());
  tree.fjets_20_eta().resize(fjets_skinny_20.size());
  tree.fjets_20_phi().resize(fjets_skinny_20.size());
  tree.fjets_20_m().resize(fjets_skinny_20.size());
  for(size_t ipj = 0; ipj < fjets_skinny_20.size(); ++ipj){
    const PseudoJet &pj = fjets_skinny_20.at(ipj);
    tree.fjets_20_pt().at(ipj)=pj.pt();
    tree.fjets_20_eta().at(ipj)=pj.eta();
    tree.fjets_20_phi().at(ipj)=pj.phi_std();
    tree.fjets_20_m().at(ipj)=pj.m();
    if(pj.pt()>50.0){
      tree.mj_20() += pj.m();
      ++(tree.nfjets_20());
    }
  }

  tree.nfjets_40() = 0;
  tree.mj_40() = 0;
  tree.fjets_40_pt().resize(fjets_skinny_40.size());
  tree.fjets_40_eta().resize(fjets_skinny_40.size());
  tree.fjets_40_phi().resize(fjets_skinny_40.size());
  tree.fjets_40_m().resize(fjets_skinny_40.size());
  for(size_t ipj = 0; ipj < fjets_skinny_40.size(); ++ipj){
    const PseudoJet &pj = fjets_skinny_40.at(ipj);
    tree.fjets_40_pt().at(ipj)=pj.pt();
    tree.fjets_40_eta().at(ipj)=pj.eta();
    tree.fjets_40_phi().at(ipj)=pj.phi_std();
    tree.fjets_40_m().at(ipj)=pj.m();
    if(pj.pt()>50.0){
      tree.mj_40() += pj.m();
      ++(tree.nfjets_40());
    }
  }

  tree.nfjets_eta25() = 0;
  tree.mj_eta25() = 0;
  tree.fjets_eta25_pt().resize(fjets_skinny_eta25.size());
  tree.fjets_eta25_eta().resize(fjets_skinny_eta25.size());
  tree.fjets_eta25_phi().resize(fjets_skinny_eta25.size());
  tree.fjets_eta25_m().resize(fjets_skinny_eta25.size());
  for(size_t ipj = 0; ipj < fjets_skinny_eta25.size(); ++ipj){
    const PseudoJet &pj = fjets_skinny_eta25.at(ipj);
    tree.fjets_eta25_pt().at(ipj)=pj.pt();
    tree.fjets_eta25_eta().at(ipj)=pj.eta();
    tree.fjets_eta25_phi().at(ipj)=pj.phi_std();
    tree.fjets_eta25_m().at(ipj)=pj.m();
    if(pj.pt()>50.0){
      tree.mj_eta25() += pj.m();
      ++(tree.nfjets_eta25());
    }
  }

  tree.nfjets_r08() = 0;
  tree.mj_r08() = 0;
  tree.fjets_r08_pt().resize(fjets_skinny_r08.size());
  tree.fjets_r08_eta().resize(fjets_skinny_r08.size());
  tree.fjets_r08_phi().resize(fjets_skinny_r08.size());
  tree.fjets_r08_m().resize(fjets_skinny_r08.size());
  for(size_t ipj = 0; ipj < fjets_skinny_r08.size(); ++ipj){
    const PseudoJet &pj = fjets_skinny_r08.at(ipj);
    tree.fjets_r08_pt().at(ipj)=pj.pt();
    tree.fjets_r08_eta().at(ipj)=pj.eta();
    tree.fjets_r08_phi().at(ipj)=pj.phi_std();
    tree.fjets_r08_m().at(ipj)=pj.m();
    if(pj.pt()>50.0){
      tree.mj_r08() += pj.m();
      ++(tree.nfjets_r08());
    }
  }

  tree.nfjets_r10() = 0;
  tree.mj_r10() = 0;
  tree.fjets_r10_pt().resize(fjets_skinny_r10.size());
  tree.fjets_r10_eta().resize(fjets_skinny_r10.size());
  tree.fjets_r10_phi().resize(fjets_skinny_r10.size());
  tree.fjets_r10_m().resize(fjets_skinny_r10.size());
  for(size_t ipj = 0; ipj < fjets_skinny_r10.size(); ++ipj){
    const PseudoJet &pj = fjets_skinny_r10.at(ipj);
    tree.fjets_r10_pt().at(ipj)=pj.pt();
    tree.fjets_r10_eta().at(ipj)=pj.eta();
    tree.fjets_r10_phi().at(ipj)=pj.phi_std();
    tree.fjets_r10_m().at(ipj)=pj.m();
    if(pj.pt()>50.0){
      tree.mj_r10() += pj.m();
      ++(tree.nfjets_r10());
    }
  }
  tree.nfjets_r14() = 0;
  tree.mj_r14() = 0;
  tree.fjets_r14_pt().resize(fjets_skinny_r14.size());
  tree.fjets_r14_eta().resize(fjets_skinny_r14.size());
  tree.fjets_r14_phi().resize(fjets_skinny_r14.size());
  tree.fjets_r14_m().resize(fjets_skinny_r14.size());
  for(size_t ipj = 0; ipj < fjets_skinny_r14.size(); ++ipj){
    const PseudoJet &pj = fjets_skinny_r14.at(ipj);
    tree.fjets_r14_pt().at(ipj)=pj.pt();
    tree.fjets_r14_eta().at(ipj)=pj.eta();
    tree.fjets_r14_phi().at(ipj)=pj.phi_std();
    tree.fjets_r14_m().at(ipj)=pj.m();
    if(pj.pt()>50.0){
      tree.mj_r14() += pj.m();
      ++(tree.nfjets_r14());
    }
  }

  tree.nfjets_cands() = static_cast<int>(bad_val);
  tree.mj_cands() = static_cast<int>(bad_val);

  tree.nfjets_cands_trim() = static_cast<int>(bad_val);
  tree.mj_cands_trim() = static_cast<int>(bad_val);
  if(!skip_slow){
    vector<PseudoJet> cands(0);
    TLorentzVector p4cand;
    for(size_t cand = 0; cand < pfcand_pt()->size(); ++cand){
      if((!is_nan(pfcand_pt()->at(cand)) && !is_nan(pfcand_eta()->at(cand))
          && !is_nan(pfcand_phi()->at(cand)) && !is_nan(pfcand_energy()->at(cand)))
         && fabs(pfcand_eta()->at(cand))<3.
         && pfcand_fromPV()->at(cand)){
        p4cand.SetPtEtaPhiE(pfcand_pt()->at(cand), pfcand_eta()->at(cand),
                            pfcand_phi()->at(cand), pfcand_energy()->at(cand));
        cands.push_back(PseudoJet(p4cand.Px(), p4cand.Py(), p4cand.Pz(), p4cand.E()));
      }
    }

    ClusterSequence cs_cands(cands, jet_def_r12);
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
    tree.nfjets_cands() = 0;
    tree.mj_cands() = 0;
    tree.fjets_cands_pt().resize(fjets_cands.size());
    tree.fjets_cands_eta().resize(fjets_cands.size());
    tree.fjets_cands_phi().resize(fjets_cands.size());
    tree.fjets_cands_m().resize(fjets_cands.size());
    for(size_t ipj = 0; ipj < fjets_cands.size(); ++ipj){
      const PseudoJet &pj = fjets_cands.at(ipj);
      tree.fjets_cands_pt().at(ipj)=pj.pt();
      tree.fjets_cands_eta().at(ipj)=pj.eta();
      tree.fjets_cands_phi().at(ipj)=pj.phi_std();
      tree.fjets_cands_m().at(ipj)=pj.m();
      if(pj.pt()>50.0){
        tree.mj_cands() += pj.m();
        ++(tree.nfjets_cands());
      }
    }
    tree.nfjets_cands_trim() = 0;
    tree.mj_cands_trim() = 0;
    tree.fjets_cands_trim_pt().resize(fjets_cands_trim.size());
    tree.fjets_cands_trim_eta().resize(fjets_cands_trim.size());
    tree.fjets_cands_trim_phi().resize(fjets_cands_trim.size());
    tree.fjets_cands_trim_m().resize(fjets_cands_trim.size());
    for(size_t ipj = 0; ipj < fjets_cands_trim.size(); ++ipj){
      const PseudoJet &pj = fjets_cands_trim.at(ipj);
      tree.fjets_cands_trim_pt().at(ipj)=pj.pt();
      tree.fjets_cands_trim_eta().at(ipj)=pj.eta();
      tree.fjets_cands_trim_phi().at(ipj)=pj.phi_std();
      tree.fjets_cands_trim_m().at(ipj)=pj.m();
      if(pj.pt()>50.0){
        tree.mj_cands_trim() += pj.m();
        ++(tree.nfjets_cands_trim());
      }
    } // Loop over trimmed fat jets
  } // If (skip_slow)

}

void event_handler::GetPtRels(std::vector<float> &els_ptrel,
                              std::vector<float> &els_mindr,
                              std::vector<float> &mus_ptrel,
                              std::vector<float> &mus_mindr,
                              float pt_cut,
                              bool remove_isolated,
                              float dr_match_thresh){
  using namespace fastjet;
  els_ptrel.resize(els_pt()->size());
  els_mindr.resize(els_pt()->size());
  mus_ptrel.resize(mus_pt()->size());
  mus_mindr.resize(mus_pt()->size());

  vector<int> els_cand_idx(els_pt()->size());
  vector<int> mus_cand_idx(mus_pt()->size());
  vector<bool> els_removed(els_pt()->size());
  vector<bool> mus_removed(mus_pt()->size());
  set<size_t> to_remove;

  //Find isolated electrons in list of pfcands
  for(size_t el = 0; el < els_pt()->size(); ++el){
    float mindr = numeric_limits<float>::max();
    size_t imatch = 0;

    for(size_t cand = 0; cand < pfcand_pt()->size(); ++cand){
      const float dr = dR(els_eta()->at(el), pfcand_eta()->at(cand),
                          els_phi()->at(el), pfcand_phi()->at(cand));
      if(dr < mindr){
        mindr = dr;
        imatch = cand;
      }
    }
    if(mindr <= dr_match_thresh || dr_match_thresh < 0.){
      els_cand_idx.at(el) = imatch;
      if(remove_isolated && IsSignalElectron(el)){
        els_removed.at(el) = true;
        to_remove.insert(imatch);
      }else{
        els_removed.at(el) = false;
      }
    }else{
      els_cand_idx.at(el) = -1;
      els_removed.at(el) = false;
    }
  }

  //Find isolated muons in list of pfcands
  for(size_t mu = 0; mu < mus_pt()->size(); ++mu){
    float mindr = numeric_limits<float>::max();
    size_t imatch = 0;

    const TLorentzVector p4mu(mus_px()->at(mu), mus_py()->at(mu),
                              mus_pz()->at(mu), mus_energy()->at(mu));

    for(size_t cand = 0; cand < pfcand_pt()->size(); ++cand){
      const float dr = dR(mus_eta()->at(mu), pfcand_eta()->at(cand),
                          mus_phi()->at(mu), pfcand_phi()->at(cand));
      if(dr < mindr){
        mindr = dr;
        imatch = cand;
      }
    }
    if(mindr <= dr_match_thresh || dr_match_thresh < 0.){
      mus_cand_idx.at(mu) = imatch;
      if(remove_isolated && IsSignalMuon(mu)){
        mus_removed.at(mu) = true;
        to_remove.insert(imatch);
      }else{
        mus_removed.at(mu) = false;
      }
    }else{
      mus_cand_idx.at(mu) = -1;
      mus_removed.at(mu) = false;
    }
  }

  //Remove candidates corresponding to isolated leptons
  vector<PseudoJet> pjs(pfcand_pt()->size());
  for(size_t cand = 0; cand < pfcand_pt()->size(); ++cand){
    if(to_remove.find(cand) == to_remove.end()
       && !is_nan(pfcand_pt()->at(cand))
       && !is_nan(pfcand_eta()->at(cand))
       && !is_nan(pfcand_phi()->at(cand))
       && !is_nan(pfcand_energy()->at(cand))){
      TLorentzVector p4cand;
      p4cand.SetPtEtaPhiE(pfcand_pt()->at(cand),
                          pfcand_eta()->at(cand),
                          pfcand_phi()->at(cand),
                          pfcand_energy()->at(cand));
      pjs.at(cand)=PseudoJet(p4cand.Px(), p4cand.Py(), p4cand.Pz(), p4cand.E());
    }else{
      pjs.at(cand)=PseudoJet(0.0, 0.0, 0.0, 0.0);
    }
  }

  JetDefinition jet_def(antikt_algorithm, 0.4);
  ClusterSequence cs(pjs, jet_def);

  vector<PseudoJet> reclustered_jets = cs.inclusive_jets();
  vector<int> indices = cs.particle_jet_indices(reclustered_jets);

  //Compute ptrel for electrons
  for(size_t el = 0; el < els_pt()->size(); ++el){
    if(els_removed.at(el)){
      //Electron was not included in clustering procedure
      els_ptrel.at(el) = -1.;
      els_mindr.at(el) = -1.;
    }else if(indices.at(els_cand_idx.at(el)) < 0){
      //Electron was not clustered
      els_ptrel.at(el) = -2.;
      els_mindr.at(el) = -2.;
    }else{
      //Electron was clustered into a jet. Compute ptrel w.r.t. this jet
      size_t jet_idx = indices.at(els_cand_idx.at(el));
      TLorentzVector p4jet(reclustered_jets.at(jet_idx).px()-els_px()->at(el),
                           reclustered_jets.at(jet_idx).py()-els_py()->at(el),
                           reclustered_jets.at(jet_idx).pz()-els_pz()->at(el),
                           reclustered_jets.at(jet_idx).e()-els_energy()->at(el));
      TLorentzVector p4el(els_px()->at(el), els_py()->at(el),
                          els_pz()->at(el), els_energy()->at(el));

      if(p4jet.Pt()<pt_cut){
        //Jet was below pt threshold; find nearest jet above threshold
        float min_dr=fltmax;
        for(size_t jet = 0; jet < reclustered_jets.size(); ++jet){
          TLorentzVector this_jet(reclustered_jets.at(jet).px(),
                                  reclustered_jets.at(jet).py(),
                                  reclustered_jets.at(jet).pz(),
                                  reclustered_jets.at(jet).e());
          if(jet == jet_idx) this_jet-=p4el;
          if(this_jet.Pt() < pt_cut) continue;
          float this_dr = p4el.DeltaR(this_jet);
          if(this_dr < min_dr){
            min_dr = this_dr;
            p4jet = this_jet;
          }
        }
      }

      els_ptrel.at(el) = p4el.Pt(p4jet.Vect());
      els_mindr.at(el) = p4el.DeltaR(p4jet);
    }
  }

  //Compute ptrel for muons
  for(size_t mu = 0; mu < mus_pt()->size(); ++mu){
    if(mus_removed.at(mu)){
      //Muon was not included in clustering procedure
      mus_ptrel.at(mu) = -1.;
      mus_mindr.at(mu) = -1.;
    }else if(indices.at(mus_cand_idx.at(mu)) < 0){
      //Muon was not clustered
      mus_ptrel.at(mu) = -2.;
      mus_mindr.at(mu) = -2.;
    }else{
      //Muon was clustered into a jet. Compute ptrel w.r.t. this jet
      size_t jet_idx = indices.at(mus_cand_idx.at(mu));
      TLorentzVector p4jet(reclustered_jets.at(jet_idx).px()-mus_px()->at(mu),
                           reclustered_jets.at(jet_idx).py()-mus_py()->at(mu),
                           reclustered_jets.at(jet_idx).pz()-mus_pz()->at(mu),
                           reclustered_jets.at(jet_idx).e()-mus_energy()->at(mu));
      TLorentzVector p4mu(mus_px()->at(mu), mus_py()->at(mu),
                          mus_pz()->at(mu), mus_energy()->at(mu));

      if(p4jet.Pt()<pt_cut){
        //Jet was below pt threshold; find nearest jet above threshold
        float min_dr=fltmax;
        for(size_t jet = 0; jet < reclustered_jets.size(); ++jet){
          TLorentzVector this_jet(reclustered_jets.at(jet).px(),
                                  reclustered_jets.at(jet).py(),
                                  reclustered_jets.at(jet).pz(),
                                  reclustered_jets.at(jet).e());
          if(jet == jet_idx) this_jet-=p4mu;
          if(this_jet.Pt() < pt_cut) continue;
          float this_dr = p4mu.DeltaR(this_jet);
          if(this_dr < min_dr){
            min_dr = this_dr;
            p4jet = this_jet;
          }
        }
      }

      mus_ptrel.at(mu) = p4mu.Pt(p4jet.Vect());
      mus_mindr.at(mu) = p4mu.DeltaR(p4jet);
    }
  }
}

void event_handler::SetMiniIso(small_tree &tree, int ilep, bool isElectron){

  double lep_pt(0.), lep_eta(0.), lep_phi(0.), deadcone_nh(0.), deadcone_ch(0.), deadcone_ph(0.), deadcone_pu(0.);;
  if (isElectron) {
    lep_pt = els_pt()->at(ilep);
    lep_eta = els_eta()->at(ilep);
    lep_phi = els_phi()->at(ilep);
    if (lep_eta>1.479) {deadcone_ch = 0.015; deadcone_pu = 0.015; deadcone_ph = 0.08;}
  } else {
    lep_pt = mus_pt()->at(ilep);
    lep_eta = mus_eta()->at(ilep);
    lep_phi = mus_phi()->at(ilep);
    deadcone_ch = 0.0001; deadcone_pu = 0.01; deadcone_ph = 0.01;deadcone_nh = 0.01;
  }

  std::vector<double> riso;
  riso.push_back(0.2);
  riso.push_back(0.3);
  riso.push_back(0.4);
  riso.push_back(10./lep_pt);
  riso.push_back(max(0.05,min(0.2,10./lep_pt)));
  riso.push_back(max(0.05,min(0.2,15./lep_pt)));
  riso.push_back(15./lep_pt);
  riso.push_back(0.1);
  riso.push_back(0.15);
  size_t nriso = riso.size();
  double riso_max = max(0.4,10./lep_pt);

  // find the PF cands that matches the lepton
  double drmin = fltmax;
  uint match_index = 9999999;
  for (unsigned int icand = 0; icand < pfcand_pt()->size(); icand++) {
    double dr = dR(pfcand_eta()->at(icand), lep_eta, pfcand_phi()->at(icand), lep_phi);
    if (dr < drmin){
      drmin = dr;
      match_index = icand;
    }
  }
  // if (match_index==9999999 || drmin>0.1) printf("Lepton not found!\n");

  // 11, 13, 22 for ele/mu/gamma, 211 for charged hadrons, 130 for neutral hadrons,
  // 1 and 2 for hadronic and em particles in HF
  std::vector<double> iso_nh(nriso,0.); std::vector<double> iso_ch(nriso,0.); std::vector<double> iso_ph(nriso,0.); std::vector<double> iso_pu(nriso,0.);
  double ptThresh(0.5);
  if(isElectron) ptThresh = 0;
  for (unsigned int icand = 0; icand < pfcand_pt()->size(); icand++) {
    if (icand==match_index) continue;
    if (abs(pfcand_pdgId()->at(icand))<7) continue;
    double dr = dR(pfcand_eta()->at(icand), lep_eta, pfcand_phi()->at(icand), lep_phi);
    if (dr > riso_max) continue;

    if (pfcand_charge()->at(icand)==0){
      if (pfcand_pt()->at(icand)>ptThresh) {
        if (abs(pfcand_pdgId()->at(icand))==22) {
          if(dr < deadcone_ph) continue;
          for (uint ir=0; ir<nriso; ir++) {if (dr<riso[ir]) iso_ph[ir] += pfcand_pt()->at(icand);}
        } else if (abs(pfcand_pdgId()->at(icand))==130) {
          if(dr < deadcone_nh) continue;
          for (uint ir=0; ir<nriso; ir++) {if (dr<riso[ir]) iso_nh[ir] += pfcand_pt()->at(icand);}
        }
      }
    } else if (pfcand_fromPV()->at(icand)>1){
      if (abs(pfcand_pdgId()->at(icand))==211) {
        if(dr < deadcone_ch) continue;
        for (uint ir=0; ir<nriso; ir++) {if (dr<riso[ir]) iso_ch[ir] += pfcand_pt()->at(icand);}
      }
    } else {
      if (pfcand_pt()->at(icand)>ptThresh){
        if(dr < deadcone_pu) continue;
        for (uint ir=0; ir<nriso; ir++) {if (dr<riso[ir]) iso_pu[ir] += pfcand_pt()->at(icand);}
      }
    }
  }

  std::vector<double> iso(nriso,0.);
  for (uint ir=0; ir<nriso; ir++) {
    iso[ir] = iso_ph[ir] + iso_nh[ir] - 0.5*iso_pu[ir];
    if (iso[ir]>0) iso[ir] += iso_ch[ir];
    else iso[ir] = iso_ch[ir];
    iso[ir] = iso[ir]/lep_pt;
  }

  if (isElectron){
    tree.els_reliso_r02().push_back(iso[0]);
    tree.els_reliso_r03().push_back(iso[1]);
    tree.els_reliso_r04().push_back(iso[2]);
    tree.els_miniso_10_ch().push_back(iso_ch[3]/lep_pt);
    tree.els_miniso_tr10().push_back(iso[4]);
    tree.els_miniso_tr15().push_back(iso[5]);
    tree.els_miniso_tr15_ch().push_back(iso_ch[5]/lep_pt);
    tree.els_miniso_15().push_back(iso[6]);
    tree.els_reliso_r01().push_back(iso[7]);
    tree.els_reliso_r015().push_back(iso[8]);
  } else {
    tree.mus_reliso_r02().push_back(iso[0]);
    tree.mus_reliso_r03().push_back(iso[1]);
    tree.mus_reliso_r04().push_back(iso[2]);
    tree.mus_miniso_10_ch().push_back(iso_ch[3]/lep_pt);
    tree.mus_miniso_tr10().push_back(iso[4]);
    tree.mus_miniso_tr15().push_back(iso[5]);
    tree.mus_miniso_tr15_ch().push_back(iso_ch[5]/lep_pt);
    tree.mus_miniso_15().push_back(iso[6]);
    tree.mus_reliso_r01().push_back(iso[7]);
    tree.mus_reliso_r015().push_back(iso[8]);
  }

  return;
}

void event_handler::SumDeltaPhiVars(small_tree &tree, const vector<int> &good_jets){
  size_t lep_index;
  bool is_muon;
  GetBestLepton(is_muon, lep_index);
  bool no_lep = lep_index == static_cast<size_t>(-1);
  int bhad = -1;
  int blep = -1;

  vector<long double> jets_sdp(0);
  long double max_sdp = -1.0, max_dp = -1.0;
  long double min_sdp = numeric_limits<long double>::max(), min_dp = min_sdp;
  for(size_t igoodjet = 0; igoodjet < good_jets.size(); ++igoodjet){
    int ijet = good_jets.at(igoodjet);
    long double sdp, dphi_lep;
    if(no_lep){
      sdp = bad_val;
      dphi_lep = bad_val;
    }else if(is_muon){
      sdp = SumDeltaPhi(jets_AK4_phi()->at(ijet),
                        mus_phi()->at(lep_index),
                        mets_phi()->at(0));
      dphi_lep = DeltaPhi(jets_AK4_phi()->at(ijet),
                          mus_phi()->at(lep_index));
    }else{
      sdp = SumDeltaPhi(jets_AK4_phi()->at(ijet),
                        els_phi()->at(lep_index),
                        mets_phi()->at(0));
      dphi_lep = DeltaPhi(jets_AK4_phi()->at(ijet),
                          els_phi()->at(lep_index));
    }
    tree.jets_dphi_met().push_back(DeltaPhi(jets_AK4_phi()->at(ijet),
                                            mets_phi()->at(0)));
    tree.jets_dphi_lep().push_back(dphi_lep);
    tree.jets_dphi_sum().push_back(sdp);

    if(jets_AK4_btag_inc_secVertexCombined()->at(ijet) > CSVCuts[1]){
      if(sdp>4.5 && (sdp > max_sdp || (sdp==max_sdp && dphi_lep>max_dp))){
        max_sdp = sdp;
        max_dp = dphi_lep;
        bhad = igoodjet;
      }
    }
    if(sdp < min_sdp || (sdp==min_sdp && dphi_lep<min_dp)){
      min_sdp = sdp;
      min_dp = dphi_lep;
      blep = igoodjet;
    }
  }

  tree.jets_bhad() = vector<bool>(tree.jets_dphi_met().size(), false);
  tree.jets_blep() = vector<bool>(tree.jets_dphi_met().size(), false);

  if(bhad != -1) tree.jets_bhad().at(bhad) = true;
  if(blep != -1) tree.jets_blep().at(blep) = true;
}

unsigned event_handler::TypeCode() const{
  const string sample_name = SampleName();
  unsigned sample_code = 0xF;
  if(Contains(sample_name, "SMS")){
    sample_code = 0x0;
  }else if(Contains(sample_name, "TTJets")
           || Contains(sample_name, "TT_")){
    sample_code = 0x1;
  }else if(Contains(sample_name, "WJets")){
    sample_code = 0x2;
  }else if(Contains(sample_name, "T_s-channel")
           || Contains(sample_name, "T_tW-channel")
           || Contains(sample_name, "T_t-channel")
           || Contains(sample_name, "Tbar_s-channel")
           || Contains(sample_name, "Tbar_tW-channel")
           || Contains(sample_name, "Tbar_t-channel")){
    sample_code = 0x3;
  }else if(Contains(sample_name, "QCD")){
    sample_code = 0x4;
  }else if(Contains(sample_name, "DY")){
    sample_code = 0x5;
  }else{
    sample_code = 0xF;
  }

  unsigned num_leps = 0, num_tau_to_lep = 0, num_taus = 0, num_conversions = 0;
  bool counting = false;

  for(size_t i = 0; i < mc_doc_id()->size(); ++i){
    const int id = static_cast<int>(floor(fabs(mc_doc_id()->at(i))+0.5));
    const int mom = static_cast<int>(floor(fabs(mc_doc_mother_id()->at(i))+0.5));
    const int gmom = static_cast<int>(floor(fabs(mc_doc_grandmother_id()->at(i))+0.5));
    const int ggmom = static_cast<int>(floor(fabs(mc_doc_ggrandmother_id()->at(i))+0.5));

    if(mom != 15) counting=false;

    if((id == 11 || id == 13) && (mom == 24 || (mom == 15 && (gmom == 24 || (gmom == 15 && ggmom == 24))))){
      ++num_leps;
      if(mom == 15){
        ++num_tau_to_lep;
        if(counting){
          ++num_conversions;
          counting = false;
        }else{
          counting = true;
        }
      }
    }else if(id == 15 && mom == 24){
      ++num_taus;
    }
  }

  num_leps -= 2*num_conversions;
  num_tau_to_lep -= 2*num_conversions;

  if(sample_code > 0xF) sample_code = 0xF;
  if(num_leps > 0xF) num_leps = 0xF;
  if(num_tau_to_lep > 0xF) num_tau_to_lep = 0xF;
  if(num_taus > 0xF) num_taus = 0xF;

  return (sample_code << 12) | (num_leps << 8) | (num_tau_to_lep << 4) | num_taus;
}

float event_handler::GetMinMTWb(vector<int> good_jets, const double pt_cut, const double bTag_req, const bool use_W_mass) const{
  float min_mT(fltmax);
  for (uint ijet(0); ijet<good_jets.size(); ijet++) {
    uint jet = good_jets[ijet];
    if (jets_pt()->at(jet)<pt_cut) continue;
    if (jets_btag_inc_secVertexCombined()->at(jet)<bTag_req) continue;
    float mT = GetMT(use_W_mass ? 80.385 : 0., mets_et()->at(0), mets_phi()->at(0),
                     0., jets_pt()->at(jet), jets_phi()->at(jet));
    if (mT<min_mT) min_mT=mT;
  }
  if (min_mT==fltmax) return bad_val;
  else return min_mT;
}
