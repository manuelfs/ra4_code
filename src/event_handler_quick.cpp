#include "event_handler_quick.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>

#include "TString.h"
#include "TFile.h"

#include "fastjet/ClusterSequence.hh"

#include "event_handler_base.hpp"
#include "phys_objects.hpp"
#include "utilities.hpp"
#include "small_tree_quick.hpp"
#include "timer.hpp"

using namespace std;
using namespace fastjet;

//const double CSVCuts[] = {0.244, 0.679, 0.898}; //Run 1 CSV
const double CSVCuts[] = {0.423, 0.814, 0.941};   //Run 2 CSV+IVF

namespace{
  const float fltmax = numeric_limits<float>::max();
}

event_handler_quick::event_handler_quick(const string &file_name):
  event_handler_base(file_name){
}

void event_handler_quick::ReduceTree(int num_entries, const TString &out_file_name, int num_total_entries){
  cout << "Good?" << endl;
  TFile out_file(out_file_name, "recreate");
  out_file.cd();

  small_tree_quick tree;
  float xsec = cross_section(out_file_name);
  float luminosity = 1000.;

  Timer timer(num_entries, 1.);
  timer.Start();
  for(int entry = 0; entry < num_entries; ++entry){
    timer.Iterate();
    GetEntry(entry);

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
    tree.weight() = xsec*luminosity / static_cast<double>(num_total_entries);
    tree.met() = mets_et()->at(0);
    tree.met_phi() = mets_phi()->at(0);
    tree.mindphin_metjet() = GetMinDeltaPhiMETN(3, 50., 2.4, 30., 2.4, true);

    TLorentzVector lepmax_p4(0., 0., 0., 0.), lepmax_p4_reliso(0., 0., 0., 0.);
    tree.nels() = 0; tree.nvels() = 0;
    tree.nels_reliso() = 0; tree.nvels_reliso() = 0;
    for(size_t index(0); index<els_pt()->size(); index++) {
      if (els_pt()->at(index) > 10 && IsVetoIdElectron(index)) {
        tree.els_sigid().push_back(IsSignalIdElectron(index));
        tree.els_ispf().push_back(els_isPF()->at(index));
        tree.els_pt().push_back(els_pt()->at(index));
        tree.els_eta().push_back(els_eta()->at(index));
        tree.els_phi().push_back(els_phi()->at(index));
        tree.els_charge().push_back(TMath::Nint(els_charge()->at(index)));
        tree.els_mt().push_back(GetMT(els_pt()->at(index), els_phi()->at(index),
                                      mets_et()->at(0), mets_phi()->at(0)));
        tree.els_d0().push_back(els_d0dum()->at(index)
                                -pv_x()->at(0)*sin(els_tk_phi()->at(index))
                                +pv_y()->at(0)*cos(els_tk_phi()->at(index)));
        tree.els_dz().push_back(els_vz()->at(index)-pv_z()->at(0));

        // MC truth
        bool fromW = false;
        int mcmomID;
        float deltaR;
        int mcID = GetTrueElectron(static_cast<int>(index), mcmomID, fromW, deltaR);
        tree.els_tru_id().push_back(mcID);
        tree.els_tru_momid().push_back(mcmomID);
        tree.els_tru_tm().push_back(abs(mcID)==pdtlund::e_minus && fromW);
        tree.els_tru_dr().push_back(deltaR);

        // Isolation
        tree.els_reliso().push_back(GetElectronIsolation(index));
        SetMiniIso(tree, index, 11);

        // Max pT lepton
        if(els_pt()->at(index) > lepmax_p4.Pt() && IsSignalIdElectron(index) && tree.els_miniso_tr10().back()<0.1)
          lepmax_p4 = TLorentzVector(els_px()->at(index), els_py()->at(index),
                                     els_pz()->at(index), els_energy()->at(index));
        if(els_pt()->at(index) > lepmax_p4_reliso.Pt() && IsSignalElectron(index))
          lepmax_p4_reliso = TLorentzVector(els_px()->at(index), els_py()->at(index),
                                            els_pz()->at(index), els_energy()->at(index));
        // Number of leptons
        if(IsVetoElectron(index)) ++(tree.nvels_reliso());
        if(IsSignalElectron(index)) ++(tree.nels_reliso());
        if(IsVetoIdElectron(index) && tree.els_miniso_tr10().back()<0.1) ++(tree.nvels());
        if(IsSignalIdElectron(index) && tree.els_miniso_tr10().back()<0.1) ++(tree.nels());
      }
    } // Loop over els

    tree.nmus() = 0; tree.nvmus() = 0;
    tree.nmus_reliso() = 0; tree.nvmus_reliso() = 0;
    for(size_t index(0); index<mus_pt()->size(); index++) {
      if (mus_pt()->at(index) > 10 && IsVetoIdMuon(index)) {
        tree.mus_sigid().push_back(IsSignalIdMuon(index));
        tree.mus_pt().push_back(mus_pt()->at(index));
        tree.mus_eta().push_back(mus_eta()->at(index));
        tree.mus_phi().push_back(mus_phi()->at(index));
        tree.mus_charge().push_back(TMath::Nint(mus_charge()->at(index)));
        tree.mus_mt().push_back(GetMT(mus_pt()->at(index), mus_phi()->at(index),
                                      mets_et()->at(0), mets_phi()->at(0)));
        tree.mus_d0().push_back(mus_tk_d0dum()->at(index)
                                -pv_x()->at(0)*sin(mus_tk_phi()->at(index))
                                +pv_y()->at(0)*cos(mus_tk_phi()->at(index)));
        tree.mus_dz().push_back(mus_tk_vz()->at(index)-pv_z()->at(0));
        // MC truth
        bool fromW = false;
        int mcmomID;
        float deltaR;
        int mcID = GetTrueMuon(static_cast<int>(index), mcmomID, fromW, deltaR);
        tree.mus_tru_id().push_back(mcID);
        tree.mus_tru_momid().push_back(mcmomID);
        tree.mus_tru_tm().push_back(abs(mcID)==pdtlund::mu_minus && fromW);
        tree.mus_tru_dr().push_back(deltaR);

        // Isolation
        tree.mus_reliso().push_back(GetMuonIsolation(index));
        SetMiniIso(tree, index, 13);

        // Max pT lepton
        if(mus_pt()->at(index) > lepmax_p4.Pt() && IsSignalIdMuon(index) && tree.mus_miniso_tr10().back()<0.4)
          lepmax_p4 = TLorentzVector(mus_px()->at(index), mus_py()->at(index),
                                     mus_pz()->at(index), mus_energy()->at(index));
        if(mus_pt()->at(index) > lepmax_p4_reliso.Pt() && IsSignalMuon(index))
          lepmax_p4_reliso = TLorentzVector(mus_px()->at(index), mus_py()->at(index),
                                            mus_pz()->at(index), mus_energy()->at(index));
        // Number of leptons
        if(IsVetoMuon(index)) ++(tree.nvmus_reliso());
        if(IsSignalMuon(index)) ++(tree.nmus_reliso());
        if(IsVetoIdMuon(index) && tree.mus_miniso_tr10().back()<0.4) ++(tree.nvmus());
        if(IsSignalIdMuon(index) && tree.mus_miniso_tr10().back()<0.4) ++(tree.nmus());
      }
    } // Loop over mus

    tree.nleps() = static_cast<int>(bad_val);
    if(tree.nels()+tree.nmus() == tree.nvels()+tree.nvmus()){
      tree.nleps() = tree.nels() + tree.nmus();
    }

    tree.nleps_reliso() = static_cast<int>(bad_val);
    if(tree.nels_reliso()+tree.nmus_reliso() == tree.nvels_reliso()+tree.nvmus_reliso()){
      tree.nleps_reliso() = tree.nels_reliso() + tree.nmus_reliso();
    }

    if(lepmax_p4.Pt()>0.){
      tree.lep_pt() = lepmax_p4.Pt();
      tree.st() = lepmax_p4.Pt()+mets_et()->at(0);

      float wx = mets_ex()->at(0) + lepmax_p4.Px();
      float wy = mets_ey()->at(0) + lepmax_p4.Py();
      float wphi = atan2(wy, wx);

      tree.dphi_wlep() = DeltaPhi(wphi, lepmax_p4.Phi());
      tree.mt() = GetMT(lepmax_p4.Pt(), lepmax_p4.Phi(), mets_et()->at(0), mets_phi()->at(0));
    }

    if(lepmax_p4_reliso.Pt()>0.){
      tree.lep_pt_reliso() = lepmax_p4_reliso.Pt();
      tree.st_reliso() = lepmax_p4_reliso.Pt()+mets_et()->at(0);

      float wx = mets_ex()->at(0) + lepmax_p4_reliso.Px();
      float wy = mets_ey()->at(0) + lepmax_p4_reliso.Py();
      float wphi = atan2(wy, wx);

      tree.dphi_wlep_reliso() = DeltaPhi(wphi, lepmax_p4_reliso.Phi());
      tree.mt_reliso() = GetMT(lepmax_p4_reliso.Pt(), lepmax_p4_reliso.Phi(), mets_et()->at(0), mets_phi()->at(0));
    }

    vector<mc_particle> parts = GetMCParticles();
    vector<size_t> moms = GetMoms(parts);
    tree.mc_type() = TypeCode(parts, moms);

    vector<int> veto_electrons = GetElectrons(false);
    vector<int> veto_muons = GetMuons(false);
    vector<int> good_jets = GetJets(veto_electrons, veto_muons, 20., 2.4);

    tree.njets() = GetNumJets(good_jets, MinJetPt);
    tree.nbl() = GetNumJets(good_jets, MinJetPt, CSVCuts[0]);
    tree.nbm() = GetNumJets(good_jets, MinJetPt, CSVCuts[1]);
    tree.nbt() = GetNumJets(good_jets, MinJetPt, CSVCuts[2]);
    tree.ht() = GetHT(good_jets, MinJetPt);
    tree.mht() = GetMHT(good_jets, MinJetPt);
    tree.min_mt_bmet() = GetMinMTWb(good_jets, MinJetPt, CSVCuts[0], false);
    tree.min_mt_bmet_with_w_mass() = GetMinMTWb(good_jets, MinJetPt, CSVCuts[0], true);

    vector<int> dirty_jets = GetJets(vector<int>(0), vector<int>(0), 20., 2.4);
    tree.jets_pt().resize(dirty_jets.size());
    tree.jets_eta().resize(dirty_jets.size());
    tree.jets_phi().resize(dirty_jets.size());
    tree.jets_csv().resize(dirty_jets.size());
    tree.jets_id().resize(dirty_jets.size());
    tree.jets_islep().resize(dirty_jets.size());
    for(size_t idirty = 0; idirty < dirty_jets.size(); ++idirty){
      int ijet = dirty_jets.at(idirty);
      tree.jets_pt().at(idirty) = jets_AK4_pt()->at(ijet);
      tree.jets_eta().at(idirty) = jets_AK4_eta()->at(ijet);
      tree.jets_phi().at(idirty) = jets_AK4_phi()->at(ijet);
      tree.jets_csv().at(idirty) = jets_AK4_btag_inc_secVertexCombined()->at(ijet);
      tree.jets_id().at(idirty) = jets_AK4_parton_Id()->at(ijet);
      tree.jets_islep().at(idirty) = (find(good_jets.begin(), good_jets.end(), ijet) != good_jets.end());
    }

    vector<PseudoJet> sjets(0);
    for(size_t jet = 0; jet<jets_pt()->size(); ++jet){
      if(is_nan(jets_px()->at(jet)) || is_nan(jets_py()->at(jet))
         || is_nan(jets_pz()->at(jet)) || is_nan(jets_energy()->at(jet))) continue;
      if(fabs(jets_eta()->at(jet))>5.) continue;
      const PseudoJet this_pj(jets_px()->at(jet), jets_py()->at(jet),
                              jets_pz()->at(jet), jets_energy()->at(jet));
      if(this_pj.pt()>30.0) sjets.push_back(this_pj);
    }
    JetDefinition jet_def(antikt_algorithm, 1.2);
    ClusterSequence cs(sjets, jet_def);
    vector<PseudoJet> fjets = sorted_by_m(cs.inclusive_jets());

    tree.nfjets() = 0;
    tree.mj() = 0.;
    tree.fjets_pt().resize(fjets.size());
    tree.fjets_eta().resize(fjets.size());
    tree.fjets_phi().resize(fjets.size());
    tree.fjets_m().resize(fjets.size());
    tree.fjets_nconst().resize(fjets.size());
    for(size_t ipj = 0; ipj < fjets.size(); ++ipj){
      const PseudoJet &pj = fjets.at(ipj);
      tree.fjets_pt().at(ipj) = pj.pt();
      tree.fjets_eta().at(ipj) = pj.eta();
      tree.fjets_phi().at(ipj) = pj.phi_std();
      tree.fjets_m().at(ipj) = pj.m();
      tree.fjets_nconst().at(ipj) = pj.constituents().size();
      if(pj.pt()>50.){
        tree.mj() += pj.m();
        ++(tree.nfjets());
      }
    }
    WriteTks(tree, parts, moms);

    tree.Fill();
  }

  tree.Write();

  TString model = model_params()->c_str();
  TString commit = RemoveTrailingNewlines(execute("git rev-parse HEAD"));
  TString type = tree.Type();
  TTree treeglobal("treeglobal", "treeglobal");
  treeglobal.Branch("nev_file", &num_entries);
  treeglobal.Branch("nev_sample", &num_total_entries);
  treeglobal.Branch("commit", &commit);
  treeglobal.Branch("model", &model);
  treeglobal.Branch("type", &type);
  treeglobal.Fill();
  treeglobal.Write();
  out_file.Close();
}

event_handler_quick::~event_handler_quick(){
}

void event_handler_quick::WriteTks(small_tree_quick &tree,
                                   const vector<mc_particle> &parts,
                                   const vector<size_t> &moms){
  tree.nisotks() = 0;
  for(size_t cand = 0; cand < pfcand_pt()->size(); ++cand){
    if(is_nan(pfcand_pt()->at(cand))
       || is_nan(pfcand_eta()->at(cand))
       || is_nan(pfcand_phi()->at(cand))
       || is_nan(pfcand_energy()->at(cand))) continue;
    int absid = abs(TMath::Nint(pfcand_pdgId()->at(cand)));
    bool islep = ((absid == 11) || (absid == 13));
    if (pfcand_charge()->at(cand)==0 || pfcand_fromPV()->at(cand)<2 ||
        (pfcand_pt()->at(cand)<5 || (pfcand_pt()->at(cand)<10 && !islep))) continue;
    TLorentzVector vcand;
    vcand.SetPtEtaPhiE(pfcand_pt()->at(cand), pfcand_eta()->at(cand),
                       pfcand_phi()->at(cand), pfcand_energy()->at(cand));
    tree.tks_pt().push_back(pfcand_pt()->at(cand));
    tree.tks_eta().push_back(pfcand_eta()->at(cand));
    tree.tks_phi().push_back(pfcand_phi()->at(cand));
    tree.tks_id().push_back(TMath::Nint(pfcand_pdgId()->at(cand)));
    tree.tks_mt().push_back(GetMT(pfcand_pt()->at(cand), pfcand_phi()->at(cand),
                                  mets_et()->at(0), mets_phi()->at(0)));
    tree.tks_from_pv().push_back(TMath::Nint(pfcand_fromPV()->at(cand)));
    size_t ipart = MatchCandToStatus1(cand, parts);
    tree.tks_tru_id().push_back(ipart<parts.size()?parts.at(ipart).id_:0);
    tree.tks_tru_dr().push_back(ipart<parts.size()
                                ?vcand.DeltaR(parts.at(ipart).momentum_)
                                :fltmax);
    tree.tks_tru_dp().push_back(ipart<parts.size()
                                ?(vcand-parts.at(ipart).momentum_).Vect().Mag()
                                :fltmax);
    tree.tks_from_w().push_back(FromW(ipart, parts, moms));
    tree.tks_from_tau().push_back(FromTau(ipart, parts, moms));
    tree.tks_from_taulep().push_back(FromTauLep(ipart, parts, moms));
    tree.tks_from_tauhad().push_back(tree.tks_from_tau().back()
                                     && !tree.tks_from_taulep().back());
    tree.tks_num_prongs().push_back(ParentTauDescendants(ipart, parts, moms));
    SetMiniIso(tree,cand,0);

    if(abs(tree.tks_id().back()) == 11 || abs(tree.tks_id().back()) == 13){
      if(tree.tks_pt().back()>5. && tree.tks_r03_ch().back()) ++(tree.nisotks());
    }else{
      if(tree.tks_pt().back()>10. && tree.tks_r03_ch().back()<0.1) ++(tree.nisotks());
    }
  } // Loop over pfcands
}

void event_handler_quick::SetMiniIso(small_tree_quick &tree, int ilep, int ParticleType){
  vector<iso_class> isos;
  double ptThresh(0.5);
  double lep_pt(0.), lep_eta(0.), lep_phi(0.), deadcone_nh(0.), deadcone_ch(0.), deadcone_ph(0.), deadcone_pu(0.);;
  if(ParticleType==11) {
    lep_pt = els_pt()->at(ilep);
    lep_eta = els_eta()->at(ilep);
    lep_phi = els_phi()->at(ilep);
    ptThresh = 0;
    if (fabs(lep_eta)>1.479) {deadcone_ch = 0.015; deadcone_pu = 0.015; deadcone_ph = 0.08;}
    isos.push_back(iso_class(&tree, &small_tree_quick::els_reliso_r01, 0.1));
    isos.push_back(iso_class(&tree, &small_tree_quick::els_reliso_r015, 0.15));
    isos.push_back(iso_class(&tree, &small_tree_quick::els_reliso_r02, 0.2));
    isos.push_back(iso_class(&tree, &small_tree_quick::els_reliso_r03, 0.3));
    isos.push_back(iso_class(&tree, &small_tree_quick::els_reliso_r04, 0.4));
    isos.push_back(iso_class(&tree, &small_tree_quick::els_miniso_10, max(0.05, 10./lep_pt)));
    isos.push_back(iso_class(&tree, &small_tree_quick::els_miniso_tr10, max(0.05, min(0.2, 10./lep_pt))));
    isos.push_back(iso_class(&tree, &small_tree_quick::els_miniso_10_ch, max(0.05, 10./lep_pt), false, false));
    isos.push_back(iso_class(&tree, &small_tree_quick::els_miniso_tr10_ch, max(0.05, min(0.2, 10./lep_pt)), false, false));
    isos.push_back(iso_class(&tree, &small_tree_quick::els_miniso_10_pfpu, max(0.05, 10./lep_pt), true, true, true, true));
    isos.push_back(iso_class(&tree, &small_tree_quick::els_miniso_tr10_pfpu, max(0.05, min(0.2, 10./lep_pt)), true, true, true, true));
  }else if(ParticleType==13){
    lep_pt = mus_pt()->at(ilep);
    lep_eta = mus_eta()->at(ilep);
    lep_phi = mus_phi()->at(ilep);
    deadcone_ch = 0.0001; deadcone_pu = 0.01; deadcone_ph = 0.01;deadcone_nh = 0.01;
    isos.push_back(iso_class(&tree, &small_tree_quick::mus_reliso_r01, 0.1));
    isos.push_back(iso_class(&tree, &small_tree_quick::mus_reliso_r015, 0.15));
    isos.push_back(iso_class(&tree, &small_tree_quick::mus_reliso_r02, 0.2));
    isos.push_back(iso_class(&tree, &small_tree_quick::mus_reliso_r03, 0.3));
    isos.push_back(iso_class(&tree, &small_tree_quick::mus_reliso_r04, 0.4));
    isos.push_back(iso_class(&tree, &small_tree_quick::mus_miniso_10, max(0.05, 10./lep_pt)));
    isos.push_back(iso_class(&tree, &small_tree_quick::mus_miniso_tr10, max(0.05, min(0.2, 10./lep_pt))));
    isos.push_back(iso_class(&tree, &small_tree_quick::mus_miniso_10_ch, max(0.05, 10./lep_pt), false, false));
    isos.push_back(iso_class(&tree, &small_tree_quick::mus_miniso_tr10_ch, max(0.05, min(0.2, 10./lep_pt)), false, false));
    isos.push_back(iso_class(&tree, &small_tree_quick::mus_miniso_10_pfpu, max(0.05, 10./lep_pt), true, true, true, true));
    isos.push_back(iso_class(&tree, &small_tree_quick::mus_miniso_tr10_pfpu, max(0.05, min(0.2, 10./lep_pt)), true, true, true, true));
  }else{
    if(is_nan(pfcand_pt()->at(ilep))
       || is_nan(pfcand_eta()->at(ilep))
       || is_nan(pfcand_phi()->at(ilep))){
      for(size_t i = 0; i < isos.size(); ++i){
        iso_class &iso = isos.at(i);
        if(iso.branch){
          ((iso.tree)->*(iso.branch))().push_back(numeric_limits<float>::quiet_NaN());
        }
      }
      return;
    }
    lep_pt = pfcand_pt()->at(ilep);
    lep_eta = pfcand_eta()->at(ilep);
    lep_phi = pfcand_phi()->at(ilep);
    deadcone_ch = 0.0001; deadcone_pu = 0.01; deadcone_ph = 0.01;deadcone_nh = 0.01; // Using muon cones
    isos.push_back(iso_class(&tree, &small_tree_quick::tks_r03_ch, 0.3,false,false,true));
  }
  bool need_pfweight = false;
  for(size_t iso = 0; !need_pfweight && iso < isos.size(); ++iso){
    if(isos.at(iso).usePFweight) need_pfweight = true;
  }
  size_t nriso = isos.size();
  double riso_max = max(0.4,10./lep_pt);
  // find the PF cands that matches the lepton
  double drmin = fltmax;
  uint match_index = 9999999;
  for (unsigned int icand = 0; icand < pfcand_pt()->size(); icand++) {
    if(is_nan(pfcand_eta()->at(icand))
       || is_nan(pfcand_phi()->at(icand))) continue;
    double dr = dR(pfcand_eta()->at(icand), lep_eta, pfcand_phi()->at(icand), lep_phi);
    if (dr < drmin){
      drmin = dr;
      match_index = icand;
    }
  }
  // 11, 13, 22 for ele/mu/gamma, 211 for charged hadrons, 130 for neutral hadrons,
  // 1 and 2 for hadronic and em particles in HF
  for (unsigned int icand = 0; icand < pfcand_pt()->size(); icand++) {
    if (icand==match_index) continue;
    if (abs(pfcand_pdgId()->at(icand))<7) continue;
    if(is_nan(pfcand_pt()->at(icand))
       || is_nan(pfcand_eta()->at(icand))
       || is_nan(pfcand_phi()->at(icand))) continue;
    double dr = dR(pfcand_eta()->at(icand), lep_eta, pfcand_phi()->at(icand), lep_phi);
    if (dr > riso_max) continue;
    ////////////////// NEUTRALS /////////////////////////
    if (pfcand_charge()->at(icand)==0){
      if (pfcand_pt()->at(icand)>ptThresh) {
        double wpv(0.), wpu(0.), wpf(1.);
        for (unsigned int jcand = 0; need_pfweight && jcand < pfcand_pt()->size(); jcand++) {
          if (pfcand_charge()->at(icand)!=0 || icand==jcand) continue;
          double jpt = pfcand_pt()->at(jcand);
          double jdr = dR(pfcand_eta()->at(icand), pfcand_eta()->at(jcand),
                          pfcand_phi()->at(icand), pfcand_phi()->at(jcand));
          if(jdr<=0) continue; // We can either not count it, or count it infinitely...
          if (pfcand_fromPV()->at(icand)>1) wpv += log(jpt/jdr);
          else wpu += log(jpt/jdr);
        }
        /////////// PHOTONS ////////////
        if (abs(pfcand_pdgId()->at(icand))==22) {
          if(dr < deadcone_ph) continue;
          for (uint ir=0; ir<nriso; ir++) {
            wpf = (isos[ir].usePFweight)?(wpv/(wpv+wpu)):1.;
            if (dr<isos[ir].R) isos[ir].iso_ph += wpf*pfcand_pt()->at(icand);
          }
          /////////// NEUTRAL HADRONS ////////////
        } else if (abs(pfcand_pdgId()->at(icand))==130) {
          if(dr < deadcone_nh) continue;
          for (uint ir=0; ir<nriso; ir++) {
            wpf = (isos[ir].usePFweight)?(wpv/(wpv+wpu)):1.;
            if (dr<isos[ir].R) isos[ir].iso_nh += wpf*pfcand_pt()->at(icand);
          }
        }
      }
      ////////////////// CHARGED from PV /////////////////////////
    } else if (pfcand_fromPV()->at(icand)>1){
      if (abs(pfcand_pdgId()->at(icand))==211) {
        if(dr < deadcone_ch) continue;
        for (uint ir=0; ir<nriso; ir++) {if (dr<isos[ir].R) isos[ir].iso_ch += pfcand_pt()->at(icand);}
      }
      ////////////////// CHARGED from PU /////////////////////////
    } else {
      if (pfcand_pt()->at(icand)>ptThresh){
        if(dr < deadcone_pu) continue;
        for (uint ir=0; ir<nriso; ir++) {if (dr<isos[ir].R) isos[ir].iso_pu += pfcand_pt()->at(icand);}
      }
    }
  }
  for (uint ir=0; ir<nriso; ir++) isos[ir].SetIso(lep_pt);
}

float event_handler_quick::GetMinMTWb(const vector<int> &good_jets,
                                      const double pt_cut,
                                      const double bTag_req,
                                      const bool use_W_mass) const{
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
unsigned event_handler_quick::TypeCode(const vector<mc_particle> &parts,
                                       const vector<size_t> &moms){
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
  unsigned nlep, ntau, ntaul;
  CountLeptons(parts, moms, nlep, ntau, ntaul);
  if(nlep > 0xF) nlep = 0xF;
  if(ntau > 0xF) ntau = 0xF;
  if(ntaul > 0xF) ntaul = 0xF;
  return (sample_code << 12) | (nlep << 8) | (ntaul << 4) | ntau;
}

// Class to have in one place the parameters of each iso calculation
iso_class::iso_class(small_tree_quick *itree, st_branch ibranch, double iR,
                     bool iaddPH, bool iaddNH, bool iaddCH, bool iusePFweight):
  tree(itree),
  branch(ibranch),
  R(iR),
  addPH(iaddPH),
  addNH(iaddNH),
  addCH(iaddCH),
  usePFweight(iusePFweight){
  iso_ch = 0;
  iso_ph = 0;
  iso_nh = 0;
  iso_pu = 0;
  }

void iso_class::SetIso(float lep_pt){
  if(branch==NULL) return;
  float isolation(0.);
  if(addPH) isolation += iso_ph;
  if(addNH) isolation += iso_nh;
  if(addPH && addNH && !usePFweight) isolation -= iso_pu/2.;
  if(isolation < 0) isolation = 0;
  if(addCH) isolation += iso_ch;
  (tree->*branch)().push_back(isolation/lep_pt);
}

bool greater_m(const PseudoJet &a, const PseudoJet &b){
  return a.m() > b.m();
}

vector<PseudoJet> sorted_by_m(vector<PseudoJet> pjs){
  sort(pjs.begin(), pjs.end(), greater_m);
  return pjs;
}
