#include "event_handler_quick.hpp"

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>

#include "TString.h"
#include "TLorentzVector.h"
#include "TVector3.h"
#include "TVector2.h"
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
    tree.weight() = xsec*luminosity / static_cast<double>(num_total_entries);

    tree.npv() = Npv();
    for(size_t bc(0); bc<PU_bunchCrossing()->size(); ++bc){
      if(PU_bunchCrossing()->at(bc)==0){
        tree.ntrupv() = PU_NumInteractions()->at(bc);
        tree.ntrupv_mean() = PU_TrueNumInteractions()->at(bc);
        break;
      }
    }

    tree.met() = mets_et()->at(0);
    tree.met_phi() = mets_phi()->at(0);
    tree.mindphin_metjet() = GetMinDeltaPhiMETN(3, 50., 2.4, 30., 2.4, true);

    size_t primary_lep=static_cast<size_t>(-1);
    size_t primary_lep_reliso = primary_lep;
    vector<size_t> sigleps;
    TLorentzVector lepmax_p4(0., 0., 0., 0.), lepmax_p4_reliso(0., 0., 0., 0.);
    short lepmax_chg = 0, lepmax_chg_reliso = 0;
    tree.nels() = 0; tree.nvels() = 0;
    tree.nels_reliso() = 0; tree.nvels_reliso() = 0;
    vector<int> sig_electrons = GetElectrons(true);
    vector<int> sig_muons = GetMuons(true);

    for(size_t index(0); index<els_pt()->size(); index++) {
      if (els_pt()->at(index) > MinVetoLeptonPt && IsVetoIdElectron(index)) {
        tree.els_sigid().push_back(IsSignalIdElectron(index));
        tree.els_ispf().push_back(els_isPF()->at(index));
        tree.els_pt().push_back(els_pt()->at(index));
        tree.els_eta().push_back(els_eta()->at(index));
        tree.els_sceta().push_back(els_scEta()->at(index));
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
        tree.els_reliso().push_back(GetElectronIsolation(index, false));
        SetMiniIso(tree, index, 11);

        int the_cand;
        bool has_match = phys_objects::hasPFMatch(index, particleId::electron, the_cand);
        if(tree.els_sigid().back() && tree.els_pt().back()>MinSignalLeptonPt && has_match){
          sigleps.push_back(the_cand);
        }

        // Max pT lepton
        if(els_pt()->at(index) > lepmax_p4.Pt() && IsSignalIdElectron(index) && tree.els_miniso_tr10().back()<0.1){
          lepmax_chg = Sign(els_charge()->at(index));
          lepmax_p4 = TLorentzVector(els_px()->at(index), els_py()->at(index),
                                     els_pz()->at(index), els_energy()->at(index));
          if(has_match) primary_lep = the_cand;
        }
        if(els_pt()->at(index) > lepmax_p4_reliso.Pt() && IsSignalElectron(index)){
          lepmax_chg_reliso = Sign(els_charge()->at(index));
          lepmax_p4_reliso = TLorentzVector(els_px()->at(index), els_py()->at(index),
                                            els_pz()->at(index), els_energy()->at(index));
          if(has_match) primary_lep_reliso = the_cand;
        }
        // Number of leptons
        if(IsVetoElectron(index)) ++(tree.nvels_reliso());
        if(IsSignalElectron(index)) ++(tree.nels_reliso());
        if(IsVetoIdElectron(index) && tree.els_miniso_tr10().back()<0.1) ++(tree.nvels());
        if(IsSignalIdElectron(index) && tree.els_pt().back()>MinSignalLeptonPt && tree.els_miniso_tr10().back()<0.1) ++(tree.nels());
      }
    } // Loop over els

    tree.nmus() = 0; tree.nvmus() = 0;
    tree.nmus_reliso() = 0; tree.nvmus_reliso() = 0;
    for(size_t index(0); index<mus_pt()->size(); index++) {
      if (mus_pt()->at(index) > MinVetoLeptonPt && IsVetoIdMuon(index)) {
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
        tree.mus_reliso().push_back(GetMuonIsolation(index, false));
        SetMiniIso(tree, index, 13);

        int the_cand;
        bool has_match = hasPFMatch(index, particleId::muon, the_cand);
        if(tree.mus_sigid().back() && tree.mus_pt().back()>MinSignalLeptonPt && has_match){
          sigleps.push_back(the_cand);
        }

        // Max pT lepton
        if(mus_pt()->at(index) > lepmax_p4.Pt() && IsSignalIdMuon(index) && tree.mus_miniso_tr10().back()<0.2){
          lepmax_chg = Sign(mus_charge()->at(index));
          lepmax_p4 = TLorentzVector(mus_px()->at(index), mus_py()->at(index),
                                     mus_pz()->at(index), mus_energy()->at(index));
          if(has_match) primary_lep = the_cand;
        }
        if(mus_pt()->at(index) > lepmax_p4_reliso.Pt() && IsSignalMuon(index)){
          lepmax_chg_reliso = Sign(mus_charge()->at(index));
          lepmax_p4_reliso = TLorentzVector(mus_px()->at(index), mus_py()->at(index),
                                            mus_pz()->at(index), mus_energy()->at(index));
          if(has_match) primary_lep_reliso = the_cand;
        }
        // Number of leptons
        if(IsVetoMuon(index)) ++(tree.nvmus_reliso());
        if(IsSignalMuon(index)) ++(tree.nmus_reliso());
        if(IsVetoIdMuon(index) && tree.mus_miniso_tr10().back()<0.2) ++(tree.nvmus());
        if(IsSignalIdMuon(index) && tree.mus_pt().back()>MinSignalLeptonPt && tree.mus_miniso_tr10().back()<0.2) ++(tree.nmus());
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
      tree.lep_phi() = lepmax_p4.Phi();
      tree.lep_eta() = lepmax_p4.Eta();
      tree.lep_charge() = lepmax_chg;
      tree.st() = lepmax_p4.Pt()+mets_et()->at(0);

      float wx = mets_ex()->at(0) + lepmax_p4.Px();
      float wy = mets_ey()->at(0) + lepmax_p4.Py();
      float wphi = atan2(wy, wx);

      tree.dphi_wlep() = DeltaPhi(wphi, lepmax_p4.Phi());
      tree.mt() = GetMT(lepmax_p4.Pt(), lepmax_p4.Phi(), mets_et()->at(0), mets_phi()->at(0));
    }

    if(lepmax_p4_reliso.Pt()>0.){
      tree.lep_pt_reliso() = lepmax_p4_reliso.Pt();
      tree.lep_phi_reliso() = lepmax_p4_reliso.Phi();
      tree.lep_eta_reliso() = lepmax_p4_reliso.Eta();
      tree.lep_charge_reliso() = lepmax_chg_reliso;
      tree.st_reliso() = lepmax_p4_reliso.Pt()+mets_et()->at(0);

      float wx = mets_ex()->at(0) + lepmax_p4_reliso.Px();
      float wy = mets_ey()->at(0) + lepmax_p4_reliso.Py();
      float wphi = atan2(wy, wx);

      tree.dphi_wlep_reliso() = DeltaPhi(wphi, lepmax_p4_reliso.Phi());
      tree.mt_reliso() = GetMT(lepmax_p4_reliso.Pt(), lepmax_p4_reliso.Phi(), mets_et()->at(0), mets_phi()->at(0));
    }

    vector<mc_particle> parts = GetMCParticles();
    vector<size_t> moms = GetMoms(parts);
    vector<size_t> indices;
    for(size_t imc = 0; imc < parts.size(); ++imc){
      mc_particle &part = parts.at(imc);

      //save last top before decay
      if ((abs(part.id_)==5 || abs(part.id_)==24) && (abs(part.mom_)==6) ){
        size_t last_top = moms.at(imc);
        //make sure we didn't already save it
        bool already_saved = false;
        for(size_t i = 0; i < indices.size() && !already_saved; i++){
          if(indices.at(i) == last_top) already_saved = true;
        }

        if (!already_saved){
          if (abs(parts.at(last_top).id_) == 6){ //save decaying tops
            tree.mc_pt().push_back(parts.at(last_top).momentum_.Pt());
            tree.mc_phi().push_back(parts.at(last_top).momentum_.Phi());
            tree.mc_eta().push_back(parts.at(last_top).momentum_.Eta());
            tree.mc_id().push_back(parts.at(last_top).id_);
            tree.mc_status().push_back(parts.at(last_top).status_);
            indices.push_back(last_top);
          }

          bool found_mom = false;
          size_t imom = last_top;
          while (imom < moms.size() && !found_mom){
            imom = moms.at(imom);
            for(size_t i = 0; i < indices.size() && !found_mom; i++){
              if(indices.at(i) == imom){
                imom = i;
                found_mom = true;
              }
            }
          }
          if(found_mom) tree.mc_mom().push_back(imom);
          else tree.mc_mom().push_back(part.mom_+10000);
        }
      }

      //other categories to be saved
      bool hardscatter(false), isr(false), fsr(false);
      if(part.status_ == 22 || part.status_ == 23 || FromW(imc, parts, moms)) hardscatter = true;
      if(abs(part.id_)!=6 && abs(part.id_)!=5 && abs(part.id_)!=24 && abs(part.mom_)==6 && part.momentum_.Pt()>10.) fsr = true;
      if(abs(part.id_)!=6 && abs(part.mom_)==2212 && part.momentum_.Pt()>10.) isr = true;

      if((hardscatter || isr || fsr) && (part.status_>9 || part.status_==1 || part.status_<0)){
        tree.mc_pt().push_back(part.momentum_.Pt());
        tree.mc_phi().push_back(part.momentum_.Phi());
        tree.mc_eta().push_back(part.momentum_.Eta());
        tree.mc_id().push_back(part.id_);
        tree.mc_status().push_back(part.status_);
        indices.push_back(imc);

        bool found_mom = false;
        size_t imom = imc;
        while (imom < moms.size() && !found_mom){
          imom = moms.at(imom);
          for(size_t i = 0; i < indices.size() && !found_mom; i++){
            if(indices.at(i) == imom){
              imom = i;
              found_mom = true;
            }
          }
        }
        if(found_mom) tree.mc_mom().push_back(imom);
        else tree.mc_mom().push_back(part.mom_+10000);
      }
    }
    tree.mc_type() = TypeCode(parts, moms);

    vector<int> good_jets = GetJets(sig_electrons, sig_muons, 20., 2.4);
    vector<Jet> subtracted_jets = GetSubtractedJets(sig_electrons, sig_muons, 20., 2.4);

    tree.nsubjets() = 0;
    tree.nbl_sub() = 0;
    tree.nbm_sub() = 0;
    tree.nbt_sub() = 0;
    tree.ht_sub() = 0.;
    tree.subjets_pt().resize(subtracted_jets.size());
    tree.subjets_eta().resize(subtracted_jets.size());
    tree.subjets_phi().resize(subtracted_jets.size());
    tree.subjets_m().resize(subtracted_jets.size());
    tree.subjets_csv().resize(subtracted_jets.size());
    tree.subjets_id().resize(subtracted_jets.size());
    tree.subjets_nsub().resize(subtracted_jets.size());
    tree.subjets_mindr().resize(subtracted_jets.size());
    tree.subjets_subpt().resize(subtracted_jets.size());
    tree.subjets_subeta().resize(subtracted_jets.size());
    tree.subjets_subphi().resize(subtracted_jets.size());
    tree.subjets_subm().resize(subtracted_jets.size());
    tree.subjets_fsubjet_index() = vector<int>(subtracted_jets.size(), -1);
    double pxsub = 0., pysub = 0.;
    for(size_t ijet = 0; ijet < subtracted_jets.size(); ++ijet){
      const Jet &jet = subtracted_jets.at(ijet);

      tree.subjets_pt().at(ijet) = jet.p4.Pt();
      tree.subjets_eta().at(ijet) = jet.p4.Eta();
      tree.subjets_phi().at(ijet) = jet.p4.Phi();
      tree.subjets_m().at(ijet) = jet.p4.M();
      tree.subjets_csv().at(ijet) = jet.csv;
      tree.subjets_id().at(ijet) = jet.id;
      tree.subjets_nsub().at(ijet) = jet.nleps;
      tree.subjets_mindr().at(ijet) = jet.mindr;
      tree.subjets_subpt().at(ijet) = jet.p4sub.Pt();
      tree.subjets_subeta().at(ijet) = jet.p4sub.Eta();
      tree.subjets_subphi().at(ijet) = jet.p4sub.Phi();
      tree.subjets_subm().at(ijet) = jet.p4sub.M();

      if(jet.p4.Pt() < MinJetPt) continue;
      ++(tree.nsubjets());
      if(jet.csv > CSVCuts[0]) ++(tree.nbl_sub());
      if(jet.csv > CSVCuts[1]) ++(tree.nbm_sub());
      if(jet.csv > CSVCuts[2]) ++(tree.nbt_sub());
      tree.ht_sub() += jet.p4.Pt();
      pxsub += jet.p4.Px();
      pysub += jet.p4.Py();
    }
    tree.mht_sub() = AddInQuadrature(pxsub, pysub);

    vector<PseudoJet> sjets(0);
    vector<int> ijets(0);
    vector<float> csvs(0);
    for(size_t ijet = 0; ijet < subtracted_jets.size(); ++ijet){
      const Jet &jet = subtracted_jets.at(ijet);
      const PseudoJet pj(jet.p4.Px(), jet.p4.Py(), jet.p4.Pz(), jet.p4.Energy());
      if(pj.pt()>30.){
        sjets.push_back(pj);
        ijets.push_back(ijet);
        csvs.push_back(jet.csv);
      }
    }
    JetDefinition jet_def(antikt_algorithm, 1.2);
    ClusterSequence cs(sjets, jet_def);
    vector<PseudoJet> fjets = sorted_by_m(cs.inclusive_jets());
    tree.nfsubjets() = 0;
    tree.mj_sub() = 0.;
    tree.fsubjets_pt().resize(fjets.size());
    tree.fsubjets_eta().resize(fjets.size());
    tree.fsubjets_phi().resize(fjets.size());
    tree.fsubjets_m().resize(fjets.size());
    tree.fsubjets_nconst().resize(fjets.size());
    tree.fsubjets_sumcsv().resize(fjets.size());
    tree.fsubjets_poscsv().resize(fjets.size());
    tree.fsubjets_btags().resize(fjets.size());
    for(size_t ipj = 0; ipj < fjets.size(); ++ipj){
      const PseudoJet &pj = fjets.at(ipj);
      tree.fsubjets_pt().at(ipj) = pj.pt();
      tree.fsubjets_eta().at(ipj) = pj.eta();
      tree.fsubjets_phi().at(ipj) = pj.phi_std();
      tree.fsubjets_m().at(ipj) = pj.m();
      const vector<PseudoJet> &cjets = pj.constituents();
      tree.fsubjets_nconst().at(ipj) = cjets.size();
      if(pj.pt()>50.){
        tree.mj_sub() += pj.m();
        ++(tree.nfsubjets());
      }
      tree.fsubjets_btags().at(ipj) = 0;
      tree.fsubjets_sumcsv().at(ipj) = 0.;
      tree.fsubjets_poscsv().at(ipj) = 0.;
      for(size_t ijet = 0; ijet < ijets.size(); ++ijet){
        size_t i = ijets.at(ijet);
        for(size_t cjet = 0; cjet < cjets.size(); ++ cjet){
          if((cjets.at(cjet) - sjets.at(ijet)).pt() < 0.0001){
            tree.subjets_fsubjet_index().at(i) = ipj;
            tree.fsubjets_sumcsv().at(ipj) += csvs.at(ijet);
            if(csvs.at(ijet) > 0.){
              tree.fsubjets_poscsv().at(ipj) += csvs.at(ijet);
            }
            if(csvs.at(ijet) > CSVCuts[1]){
              ++(tree.fsubjets_btags().at(ipj));
            }
          }
        }
      }
    }

    tree.njets() = GetNumJets(good_jets, MinJetPt);
    tree.nbl() = GetNumJets(good_jets, MinJetPt, CSVCuts[0]);
    tree.nbm() = GetNumJets(good_jets, MinJetPt, CSVCuts[1]);
    tree.nbt() = GetNumJets(good_jets, MinJetPt, CSVCuts[2]);
    tree.ht() = GetHT(good_jets, MinJetPt);
    tree.mht() = GetMHT(good_jets, MinJetPt);
    tree.min_mt_bmet() = GetMinMTWb(good_jets, MinJetPt, CSVCuts[1], false);
    tree.min_mt_bmet_with_w_mass() = GetMinMTWb(good_jets, MinJetPt, CSVCuts[1], true);

    double genmetx = 0., genmety = 0.;
    for(size_t imc = 0; imc < mc_final_id()->size(); ++imc){
      int id = abs(TMath::Nint(mc_final_id()->at(imc)));
      double px = mc_final_pt()->at(imc)*cos(mc_final_phi()->at(imc));
      double py = mc_final_pt()->at(imc)*sin(mc_final_phi()->at(imc));
      if(id==12 || id==14 || id==16 || id==18
         || id==1000012 || id==1000014 || id==1000016
         || id==1000022 || id==1000023 || id==1000025 || id==1000035 || id==1000039){
        genmetx += px;
        genmety += py;
      }
    }
    tree.gen_met() = AddInQuadrature(genmetx, genmety);
    tree.gen_met_phi() = atan2(genmety, genmetx);

    tree.ht_nonb() = 0.;
    size_t lead_b, sub_b;
    GetLeadingBJets(good_jets, MinJetPt, CSVCuts[1], lead_b, sub_b);
    for(size_t i = 0; i < good_jets.size(); ++i){
      size_t ijet = good_jets.at(i);
      if(jets_corr_p4().at(ijet).Pt()>MinJetPt
         && fabs(jets_corr_p4().at(ijet).Eta() < 2.4)
         && ijet!=lead_b && ijet!=sub_b){
        tree.ht_nonb()+=jets_corr_p4().at(ijet).Pt();
      }
    }
    vector<int> dirty_jets = GetJets(vector<int>(0), vector<int>(0), 20., 5.0);
    tree.jets_pt().resize(dirty_jets.size());
    tree.jets_eta().resize(dirty_jets.size());
    tree.jets_phi().resize(dirty_jets.size());
    tree.jets_m().resize(dirty_jets.size());
    tree.jets_uncor_pt().resize(dirty_jets.size());
    tree.jets_csv().resize(dirty_jets.size());
    tree.jets_id().resize(dirty_jets.size());
    tree.jets_islep().resize(dirty_jets.size());
    tree.jets_fjet_index() = vector<int>(dirty_jets.size(), -1);
    tree.jets_fjet15_index() = vector<int>(dirty_jets.size(), -1);
    tree.jets_fjet20_index() = vector<int>(dirty_jets.size(), -1);
    tree.jets_fjet30_index() = vector<int>(dirty_jets.size(), -1);
    tree.jets_fjetinf_index() = vector<int>(dirty_jets.size(), -1);
    tree.jets_fjet_nl_index() = vector<int>(dirty_jets.size(), -1);
    tree.jets_fjet15_nl_index() = vector<int>(dirty_jets.size(), -1);
    tree.jets_gen_pt().resize(dirty_jets.size());
    tree.jets_parton_pt().resize(dirty_jets.size());
    tree.jets_isr_code().resize(dirty_jets.size());
    tree.ht_isr() = 0.;
    for(size_t idirty = 0; idirty < dirty_jets.size(); ++idirty){
      int ijet = dirty_jets.at(idirty);
      tree.jets_pt().at(idirty) = jets_corr_p4().at(ijet).Pt();
      tree.jets_eta().at(idirty) = jets_corr_p4().at(ijet).Eta();
      tree.jets_phi().at(idirty) = jets_corr_p4().at(ijet).Phi();
      tree.jets_m().at(idirty) = jets_corr_p4().at(ijet).M();
      tree.jets_uncor_pt().at(idirty) = jets_pt()->at(ijet);
      tree.jets_csv().at(idirty) = jets_btag_inc_secVertexCombined()->at(ijet);
      tree.jets_id().at(idirty) = jets_parton_Id()->at(ijet);
      tree.jets_islep().at(idirty) = !(find(good_jets.begin(), good_jets.end(), ijet) != good_jets.end());
      tree.jets_gen_pt().at(idirty) = jets_gen_pt()->at(ijet);
      tree.jets_parton_pt().at(idirty) = jets_parton_pt()->at(ijet);

      float min_dpt = numeric_limits<float>::max();
      size_t match_jet = 0;
      for(size_t genjet = 0; genjet < mc_jets_pt()->size(); ++genjet){
        float dpt = fabs(jets_gen_pt()->at(ijet)-mc_jets_pt()->at(genjet));
        if(dpt < min_dpt){
          min_dpt = dpt;
          match_jet = genjet;
        }
      }

      if(min_dpt > 0.001){
        tree.jets_isr_code().at(idirty) = 0;//PU
      }else{
        min_dpt = numeric_limits<float>::max();
        size_t match_mc = 0;
        if(jets_parton_pt()->at(ijet)>0.){
          for(size_t mc = 0; mc < parts.size(); ++mc){
            float dpt = fabs(parts.at(mc).momentum_.Pt() - jets_parton_pt()->at(ijet));
            if(dpt < min_dpt){
              min_dpt = dpt;
              match_mc = mc;
            }
          }
          if(min_dpt != numeric_limits<float>::max()){
            if(FromTop(match_mc, parts, moms)){
              tree.jets_isr_code().at(idirty) = 1;//top
            }else{
              tree.jets_isr_code().at(idirty) = 2;//ISR MG
            }
          }else{
            tree.jets_isr_code().at(idirty) = 3;//ISR non-MG
          }
        }else{
          tree.jets_isr_code().at(idirty) = 3;//ISR non-MG
        }
      }

      if(!tree.jets_islep().at(idirty)
         && tree.jets_pt().at(idirty) > MinJetPt
         && fabs(tree.jets_eta().at(idirty))<2.4
         && tree.jets_isr_code().at(idirty)>1.5){
        tree.ht_isr() += tree.jets_pt().at(idirty);
      }
    }

    tree.ht_isr_me() = 0.;
    tree.n_isr_me() = 0;
    tree.ht_isr_nonme() = 0;
    tree.n_isr_nonme() = 0;
    vector<TLorentzVector> p4s;
    for(size_t i = 0; i < parts.size(); ++i){
      if(parts.at(i).status_== 23 && !FromTop(i, parts, moms)){
        tree.ht_isr_me() += parts.at(i).momentum_.Pt();
        ++(tree.n_isr_me());
      }else if(!FromTop(i, parts, moms) && !NumChildren(i, parts, moms)){
        bool found = false;
        for(size_t j = 0; j < p4s.size() && !found; ++j){
          if((p4s.at(j)-parts.at(i).momentum_).Vect().Mag()<0.001){
            found = true;
          }
        }
        if(!found){
          p4s.push_back(parts.at(i).momentum_);
          tree.ht_isr_nonme() += parts.at(i).momentum_.Pt();
          ++(tree.n_isr_nonme());
        }
      }
    }

    tree.ngenjets() = 0;
    tree.ht_isr_tru() = 0.;
    tree.gen_ht() = 0.;
    vector<int> good_mc_jets(0);
    for(size_t jet = 0; jet < mc_jets_pt()->size(); ++jet){
      if(is_nan(mc_jets_pt()->at(jet)) || is_nan(mc_jets_eta()->at(jet))
         || is_nan(mc_jets_phi()->at(jet)) || is_nan(mc_jets_energy()->at(jet))) continue;
      if(mc_jets_pt()->at(jet)<20. || fabs(mc_jets_eta()->at(jet))>5.) continue;
      good_mc_jets.push_back(jet);
      tree.genjets_pt().push_back(mc_jets_pt()->at(jet));
      tree.genjets_eta().push_back(mc_jets_eta()->at(jet));
      tree.genjets_phi().push_back(mc_jets_phi()->at(jet));
      tree.genjets_m().push_back(mc_jets_mass()->at(jet));
      tree.genjets_genfjet_index().push_back(-1);
      if(mc_jets_pt()->at(jet)>MinJetPt){
        ++(tree.ngenjets());
        tree.gen_ht() += mc_jets_pt()->at(jet);
      }

      TLorentzVector v;
      v.SetPtEtaPhiE(mc_jets_pt()->at(jet), mc_jets_eta()->at(jet),
                     mc_jets_phi()->at(jet), mc_jets_mass()->at(jet));

      float mindr = numeric_limits<float>::max();
      size_t match_mc = 0;
      bool found_match = false;
      for(size_t mc = 0; mc < parts.size(); ++mc){
        mc_particle &part = parts.at(mc);
        if(is_nan(part.momentum_.Px()) || is_nan(part.momentum_.Py())
           || is_nan(part.momentum_.Pz()) || is_nan(part.momentum_.E())
           || part.momentum_.Pt() <= std::numeric_limits<float>::epsilon()) continue;
        float dr = v.DeltaR(part.momentum_);
        if(dr<mindr){
          mindr = dr;
          match_mc = mc;
          found_match = true;
        }
      }

      if(found_match){
        if(FromTop(match_mc, parts, moms)){
          tree.genjets_isr_code().push_back(1);//top
        }else if(FromStatus23(match_mc, parts, moms)){
          tree.genjets_isr_code().push_back(2);//ISR MG
        }else{
          tree.genjets_isr_code().push_back(3);//ISR non-MG
        }
      }else{
        tree.genjets_isr_code().push_back(3);//ISR non-MG
      }

      if(tree.genjets_pt().back() > MinJetPt
         && fabs(tree.genjets_eta().back())<2.4
         && tree.genjets_isr_code().back()>1.5){
        tree.ht_isr_tru() += tree.genjets_pt().back();
      }
    }

    tree.min_dphi_bb() = numeric_limits<float>::max();
    tree.max_dphi_bb() = -numeric_limits<float>::max();
    tree.min_dr_bb() = numeric_limits<float>::max();
    tree.max_dr_bb() = -numeric_limits<float>::max();
    tree.min_m_bb() = numeric_limits<float>::max();
    tree.max_m_bb() = -numeric_limits<float>::max();
    tree.min_pt_bb() = numeric_limits<float>::max();
    tree.max_pt_bb() = -numeric_limits<float>::max();

    tree.min_dphi_blep() = numeric_limits<float>::max();
    tree.max_dphi_blep() = -numeric_limits<float>::max();
    tree.min_dr_blep() = numeric_limits<float>::max();
    tree.max_dr_blep() = -numeric_limits<float>::max();
    tree.min_m_blep() = numeric_limits<float>::max();
    tree.max_m_blep() = -numeric_limits<float>::max();
    tree.min_pt_blep() = numeric_limits<float>::max();
    tree.max_pt_blep() = -numeric_limits<float>::max();

    tree.min_dphi_bmet() = numeric_limits<float>::max();
    tree.max_dphi_bmet() = -numeric_limits<float>::max();
    tree.min_mt_bmet() = numeric_limits<float>::max();
    tree.max_mt_bmet() = -numeric_limits<float>::max();
    tree.min_pt_bmet() = numeric_limits<float>::max();
    tree.max_pt_bmet() = -numeric_limits<float>::max();
    for(size_t ib1 = 0; ib1 < good_jets.size(); ++ib1){
      size_t b1 = good_jets.at(ib1);
      if(jets_corr_p4().at(b1).Pt()<MinJetPt || jets_btag_inc_secVertexCombined()->at(b1)<CSVCuts[1]) continue;
      TLorentzVector vb1(jets_corr_p4().at(b1)), vmet;
      vmet.SetPtEtaPhiM(mets_et()->at(0), 0., mets_phi()->at(0), 0.);

      float dphi_blep = DeltaPhi(vb1.Phi(), lepmax_p4.Phi());
      if(dphi_blep < tree.min_dphi_blep()) tree.min_dphi_blep() = dphi_blep;
      if(dphi_blep > tree.max_dphi_blep()) tree.max_dphi_blep() = dphi_blep;
      float dr_blep = vb1.DeltaR(lepmax_p4);
      if(dr_blep < tree.min_dr_blep()) tree.min_dr_blep() = dr_blep;
      if(dr_blep > tree.max_dr_blep()) tree.max_dr_blep() = dr_blep;
      float m_blep = (vb1+lepmax_p4).M();
      if(m_blep < tree.min_m_blep()) tree.min_m_blep() = m_blep;
      if(m_blep > tree.max_m_blep()) tree.max_m_blep() = m_blep;
      float pt_blep = (vb1+lepmax_p4).Pt();
      if(pt_blep < tree.min_pt_blep()) tree.min_pt_blep() = pt_blep;
      if(pt_blep > tree.max_pt_blep()) tree.max_pt_blep() = pt_blep;

      float dphi_bmet = DeltaPhi(vb1.Phi(), vmet.Phi());
      if(dphi_bmet < tree.min_dphi_bmet()) tree.min_dphi_bmet() = dphi_bmet;
      if(dphi_bmet > tree.max_dphi_bmet()) tree.max_dphi_bmet() = dphi_bmet;
      float mt_bmet = GetMT(vb1.M(), vb1.Pt(), vb1.Phi(),
                            0., mets_et()->at(0), mets_phi()->at(0));
      if(mt_bmet < tree.min_mt_bmet()) tree.min_mt_bmet() = mt_bmet;
      if(mt_bmet > tree.max_mt_bmet()) tree.max_mt_bmet() = mt_bmet;
      float pt_bmet = (vb1+vmet).Pt();
      if(pt_bmet < tree.min_pt_bmet()) tree.min_pt_bmet() = pt_bmet;
      if(pt_bmet > tree.max_pt_bmet()) tree.max_pt_bmet() = pt_bmet;

      for(size_t ib2 = ib1+1; ib2 < good_jets.size(); ++ib2){
        size_t b2 = good_jets.at(ib2);
        if(jets_corr_p4().at(b2).Pt()<MinJetPt || jets_btag_inc_secVertexCombined()->at(b2)<CSVCuts[1]) continue;

        TLorentzVector vb2(jets_corr_p4().at(b2));

        float dphi_bb = DeltaPhi(vb1.Phi(), vb2.Phi());
        if(dphi_bb < tree.min_dphi_bb()) tree.min_dphi_bb() = dphi_bb;
        if(dphi_bb > tree.max_dphi_bb()) tree.max_dphi_bb() = dphi_bb;
        float dr_bb = vb1.DeltaR(vb2);
        if(dr_bb < tree.min_dr_bb()) tree.min_dr_bb() = dr_bb;
        if(dr_bb > tree.max_dr_bb()) tree.max_dr_bb() = dr_bb;
        float m_bb = (vb1+vb2).M();
        if(m_bb < tree.min_m_bb()) tree.min_m_bb() = m_bb;
        if(m_bb > tree.max_m_bb()) tree.max_m_bb() = m_bb;
        float pt_bb = (vb1+vb2).Pt();
        if(pt_bb < tree.min_pt_bb()) tree.min_pt_bb() = pt_bb;
        if(pt_bb > tree.max_pt_bb()) tree.max_pt_bb() = pt_bb;
      }
    }

    size_t it1 = 0, it2 = 0;
    bool found_top = false, found_antitop = false;
    for(size_t it = parts.size()-1; it < parts.size() && !(found_top && found_antitop); --it){
      if(parts.at(it).status_==0) continue;
      if(parts.at(it).id_ == 6 && !found_top){
        found_top = true;
        it1 = it;
      }else if(parts.at(it).id_ == -6 && !found_antitop){
        found_antitop = true;
        it2 = it;
      }
    }
    if(found_top && found_antitop){
      tree.tru_tt_dphi() = DeltaPhi(parts.at(it1).momentum_.Phi(), parts.at(it2).momentum_.Phi());
      TLorentzVector sum = parts.at(it1).momentum_+parts.at(it2).momentum_;
      TLorentzVector diff = parts.at(it1).momentum_-parts.at(it2).momentum_;
      tree.tru_tt_m() = sum.M();
      tree.tru_tt_pt() = sum.Pt();
      tree.tru_tt_ptdiff() = diff.Pt();
    }

    size_t ig1 = 0, ig2 = 0;
    bool found_g1 = false, found_g2 = false;
    for(size_t it = parts.size()-1; it < parts.size() && !(found_g1 && found_g2); --it){
      if(parts.at(it).id_ == 1000021 && parts.at(it).mom_ != 1000021){
        if(!found_g2){
          ig2 = it;
          found_g2 = true;
        }else if(!found_g1){
          ig1 = it;
          found_g1 = true;
        }
      }
    }
    if(found_g1 && found_g2){
      tree.tru_gluglu_dphi() = DeltaPhi(parts.at(ig1).momentum_.Phi(), parts.at(ig2).momentum_.Phi());
      TLorentzVector sum = parts.at(ig1).momentum_+parts.at(ig2).momentum_;
      TLorentzVector diff = parts.at(ig1).momentum_-parts.at(ig2).momentum_;
      tree.tru_gluglu_m() = sum.M();
      tree.tru_gluglu_pt() = sum.Pt();
      tree.tru_gluglu_ptdiff() = diff.Pt();
    }

    size_t in1 = 0, in2 = 0;
    bool found_n1 = false, found_n2 = false;
    for(size_t it = 0; it < parts.size() && !(found_n1 && found_n2); ++it){
      if(parts.at(it).id_ != 1000022 || parts.at(it).mom_ != 1000021) continue;
      if(!found_n1){
        in1 = it;
        found_n1 = true;
      }else if(!found_n2){
        in2 = it;
        found_n2 = true;
      }
    }
    tree.glu_proj_frac().clear();
    if(found_n1 && found_n2){
      tree.dphi_neutralinos() = DeltaPhi(parts.at(in1).momentum_.Phi(), parts.at(in2).momentum_.Phi());
      if(in2+2 < parts.size()
         && abs(parts.at(in1+1).id_)==6 && parts.at(in1+1).mom_==1000021
         && abs(parts.at(in1+2).id_)==6 && parts.at(in1+2).mom_==1000021
         && abs(parts.at(in2+1).id_)==6 && parts.at(in2+1).mom_==1000021
         && abs(parts.at(in2+2).id_)==6 && parts.at(in2+2).mom_==1000021){
        ig1 = GetMom(in1, parts);
        ig2 = GetMom(in2, parts);
        if(ig1<parts.size() && ig2<parts.size()){
          const TLorentzVector &vg1 = parts.at(ig1).momentum_;
          const TLorentzVector &vg2 = parts.at(ig2).momentum_;
          TLorentzVector vs1 = parts.at(in1).momentum_ + parts.at(in1+1).momentum_ + parts.at(in1+2).momentum_;
          TLorentzVector vs2 = parts.at(in2).momentum_ + parts.at(in2+1).momentum_ + parts.at(in2+2).momentum_;
          float dra1 = vg1.DeltaR(vs1);
          float dra2 = vg2.DeltaR(vs2);
          float drb1 = vg1.DeltaR(vs2);
          float drb2 = vg2.DeltaR(vs1);
          float dra = AddInQuadrature(dra1, dra2);
          float drb = AddInQuadrature(drb1, drb2);
          if(drb<dra){
            size_t intemp = in2;
            in2 = in1;
            in1 = intemp;
            TLorentzVector vstemp = vs2;
            vs2 = vs1;
            vs1 = vstemp;
          }
          TVector2 v2g1(vg1.Vect().XYvector().Unit());
          TVector2 v2g2(vg2.Vect().XYvector().Unit());
          double proj1[3], proj2[3];
          double sum1 = 0., sum2 = 0.;
          tree.glu_proj_frac() = vector<float>(2, 0.);
          for(size_t i = 0; i < 3; ++i){
            proj1[i] = v2g1.Px()*parts.at(in2+i).momentum_.Px()+v2g1.Py()*parts.at(in2+i).momentum_.Py();
            proj2[i] = v2g2.Px()*parts.at(in1+i).momentum_.Px()+v2g2.Py()*parts.at(in1+i).momentum_.Py();
            sum1 += fabs(proj1[i]);
            sum2 += fabs(proj2[i]);
            if(proj1[i]>0.) tree.glu_proj_frac().at(0) += proj1[i];
            if(proj2[i]>0.) tree.glu_proj_frac().at(1) += proj2[i];
          }
          tree.glu_proj_frac().at(0)/=sum1;
          tree.glu_proj_frac().at(1)/=sum2;

          vector<TLorentzVector> vs;
          vs.push_back(parts.at(in1).momentum_);
          vs.push_back(parts.at(in1+1).momentum_);
          vs.push_back(parts.at(in1+2).momentum_);
          vs.push_back(parts.at(in2).momentum_);
          vs.push_back(parts.at(in2+1).momentum_);
          vs.push_back(parts.at(in2+2).momentum_);
          tree.tru_sphericity() = GetSphericity(vs);
        }
      }
    }

    WriteFatJets(tree.nfjets(), tree.mj(),
                 tree.fjets_pt(), tree.fjets_eta(),
                 tree.fjets_phi(), tree.fjets_m(),
                 tree.fjets_nconst(),
                 tree.fjets_sumcsv(), tree.fjets_poscsv(),
                 tree.fjets_btags(), tree.jets_fjet_index(),
                 1.2, dirty_jets);
    WriteFatJets(tree.nfjets15(), tree.mj15(),
                 tree.fjets15_pt(), tree.fjets15_eta(),
                 tree.fjets15_phi(), tree.fjets15_m(),
                 tree.fjets15_nconst(),
                 tree.fjets15_sumcsv(), tree.fjets15_poscsv(),
                 tree.fjets15_btags(), tree.jets_fjet15_index(),
                 1.5, dirty_jets);
    WriteFatJets(tree.nfjets20(), tree.mj20(),
                 tree.fjets20_pt(), tree.fjets20_eta(),
                 tree.fjets20_phi(), tree.fjets20_m(),
                 tree.fjets20_nconst(),
                 tree.fjets20_sumcsv(), tree.fjets20_poscsv(),
                 tree.fjets20_btags(), tree.jets_fjet20_index(),
                 2.0, dirty_jets);
    WriteFatJets(tree.nfjets30(), tree.mj30(),
                 tree.fjets30_pt(), tree.fjets30_eta(),
                 tree.fjets30_phi(), tree.fjets30_m(),
                 tree.fjets30_nconst(),
                 tree.fjets30_sumcsv(), tree.fjets30_poscsv(),
                 tree.fjets30_btags(), tree.jets_fjet30_index(),
                 3.0, dirty_jets);
    WriteFatJets(tree.nfjetsinf(), tree.mjinf(),
                 tree.fjetsinf_pt(), tree.fjetsinf_eta(),
                 tree.fjetsinf_phi(), tree.fjetsinf_m(),
                 tree.fjetsinf_nconst(),
                 tree.fjetsinf_sumcsv(), tree.fjetsinf_poscsv(),
                 tree.fjetsinf_btags(), tree.jets_fjetinf_index(),
                 1000.0, dirty_jets);
    WriteFatJets(tree.nfjets_nl(), tree.mj_nl(),
                 tree.fjets_nl_pt(), tree.fjets_nl_eta(),
                 tree.fjets_nl_phi(), tree.fjets_nl_m(),
                 tree.fjets_nl_nconst(),
                 tree.fjets_nl_sumcsv(), tree.fjets_nl_poscsv(),
                 tree.fjets_nl_btags(), tree.jets_fjet_nl_index(),
                 1.2, dirty_jets, false,
                 true, tree.jets_islep());
    WriteFatJets(tree.nfjets15_nl(), tree.mj15_nl(),
                 tree.fjets15_nl_pt(), tree.fjets15_nl_eta(),
                 tree.fjets15_nl_phi(), tree.fjets15_nl_m(),
                 tree.fjets15_nl_nconst(),
                 tree.fjets15_nl_sumcsv(), tree.fjets15_nl_poscsv(),
                 tree.fjets15_nl_btags(), tree.jets_fjet15_nl_index(),
                 1.5, dirty_jets, false,
                 true, tree.jets_islep());
    vector<float> genfjets_csv(tree.genfjets_pt().size());
    vector<int> genfjets_btags(tree.genfjets_pt().size());
    WriteFatJets(tree.ngenfjets(), tree.gen_mj(),
                 tree.genfjets_pt(), tree.genfjets_eta(),
                 tree.genfjets_phi(), tree.genfjets_m(),
                 tree.genfjets_nconst(),
                 genfjets_csv, genfjets_csv,
                 genfjets_btags, tree.genjets_genfjet_index(),
                 1.2, good_mc_jets, true);

    WriteTks(tree, parts, moms, lepmax_chg, lepmax_chg_reliso, sigleps, primary_lep, primary_lep_reliso);

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

void event_handler_quick::WriteFatJets(int &nfjets,
                                       float &mj,
                                       vector<float> &fjets_pt,
                                       vector<float> &fjets_eta,
                                       vector<float> &fjets_phi,
                                       vector<float> &fjets_m,
                                       vector<int> &fjets_nconst,
                                       vector<float> &fjets_sumcsv,
                                       vector<float> &fjets_poscsv,
                                       vector<int> &fjets_btags,
                                       vector<int> &jets_fjet_index,
                                       double radius,
                                       const vector<int> &jets,
                                       bool gen,
                                       bool clean,
                                       const vector<bool> &to_clean){
  vector<PseudoJet> sjets(0);
  vector<int> ijets(0);
  vector<float> csvs(0);

  if(gen){
    for(size_t idirty = 0; idirty<jets.size(); ++idirty){
      int jet = jets.at(idirty);
      TLorentzVector v;
      v.SetPtEtaPhiE(mc_jets_pt()->at(jet), mc_jets_eta()->at(jet),
                     mc_jets_phi()->at(jet), mc_jets_energy()->at(jet));
      const PseudoJet this_pj(v.Px(), v.Py(), v.Pz(), v.E());
      if(this_pj.pt()>30.0){
        sjets.push_back(this_pj);
        ijets.push_back(idirty);
        csvs.push_back(0.);
      }
    }
  }else{
    for(size_t idirty = 0; idirty<jets.size(); ++idirty){

      int jet = jets.at(idirty);
      if(is_nan(jets_corr_p4().at(jet).Px()) || is_nan(jets_corr_p4().at(jet).Py())
         || is_nan(jets_corr_p4().at(jet).Pz()) || is_nan(jets_corr_p4().at(jet).E())
         || (clean && to_clean.at(idirty))) continue;
      const TLorentzVector &this_lv = jets_corr_p4().at(jet);
      const PseudoJet this_pj(this_lv.Px(), this_lv.Py(), this_lv.Pz(), this_lv.E());

      if(this_pj.pt()>30.0){
        sjets.push_back(this_pj);
        ijets.push_back(idirty);
        csvs.push_back(jets_btag_inc_secVertexCombined()->at(jet));
      }
    }
  }

  JetDefinition jet_def(antikt_algorithm, radius);
  ClusterSequence cs(sjets, jet_def);
  vector<PseudoJet> fjets = sorted_by_m(cs.inclusive_jets());
  nfjets = 0;
  mj = 0.;
  fjets_pt.resize(fjets.size());
  fjets_eta.resize(fjets.size());
  fjets_phi.resize(fjets.size());
  fjets_m.resize(fjets.size());
  fjets_nconst.resize(fjets.size());
  fjets_sumcsv.resize(fjets.size());
  fjets_poscsv.resize(fjets.size());
  fjets_btags.resize(fjets.size());

  for(size_t ipj = 0; ipj < fjets.size(); ++ipj){
    const PseudoJet &pj = fjets.at(ipj);
    fjets_pt.at(ipj) = pj.pt();
    fjets_eta.at(ipj) = pj.eta();
    fjets_phi.at(ipj) = pj.phi_std();
    fjets_m.at(ipj) = pj.m();
    const vector<PseudoJet> &cjets = pj.constituents();
    fjets_nconst.at(ipj) = cjets.size();
    if(pj.pt()>50.){
      mj += pj.m();
      ++nfjets;
    }
    fjets_btags.at(ipj) = 0;
    fjets_sumcsv.at(ipj) = 0.;
    fjets_poscsv.at(ipj) = 0.;
    for(size_t ijet = 0; ijet < ijets.size(); ++ijet){
      size_t i = ijets.at(ijet);
      for(size_t cjet = 0; cjet < cjets.size(); ++ cjet){
        if((cjets.at(cjet) - sjets.at(ijet)).pt() < 0.0001){
          jets_fjet_index.at(i) = ipj;
          fjets_sumcsv.at(ipj) += csvs.at(ijet);
          if(csvs.at(ijet) > 0.){
            fjets_poscsv.at(ipj) += csvs.at(ijet);
          }
          if(csvs.at(ijet) > CSVCuts[1]){
            ++(fjets_btags.at(ipj));
          }
        }
      }
    }
  }
}

void event_handler_quick::WriteTks(small_tree_quick &tree,
                                   const vector<mc_particle> &parts,
                                   const vector<size_t> &moms,
                                   short lepmax_chg,
                                   short lepmax_chg_reliso,
                                   const vector<size_t> &sigleps,
                                   size_t primary_lep,
                                   size_t primary_lep_reliso){
  tree.ntks() = 0;
  tree.ntks_chg() = 0;
  tree.ntks_chg_reliso() = 0;
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
    tree.tks_charge().push_back(TMath::Nint(pfcand_charge()->at(cand)));
    if(cand == primary_lep){
      tree.tks_is_primary().push_back(true);
    }else{
      tree.tks_is_primary().push_back(false);
    }
    if(cand == primary_lep_reliso){
      tree.tks_is_primary_reliso().push_back(true);
    }else{
      tree.tks_is_primary_reliso().push_back(false);
    }
    if(find(sigleps.begin(), sigleps.end(), cand)!=sigleps.end()){
      tree.tks_is_sig_lep().push_back(true);
    }else{
      tree.tks_is_sig_lep().push_back(false);
    }

    SetMiniIso(tree,cand,0);

    if(abs(tree.tks_id().back()) == 11 || abs(tree.tks_id().back()) == 13){
      if(tree.tks_pt().back()>5. && tree.tks_r03_ch().back()<0.2){
        ++(tree.ntks());
        if(Sign(tree.tks_id().back())*lepmax_chg>0) ++(tree.ntks_chg());
        if(Sign(tree.tks_id().back())*lepmax_chg_reliso>0) ++(tree.ntks_chg_reliso());
      }
    }else{
      if(tree.tks_pt().back()>10. && tree.tks_r03_ch().back()<0.1){
        ++(tree.ntks());
        if(Sign(tree.tks_id().back())*lepmax_chg<0) ++(tree.ntks_chg());
        if(Sign(tree.tks_id().back())*lepmax_chg_reliso<0) ++(tree.ntks_chg_reliso());
      }
    }
  } // Loop over pfcands
}

void event_handler_quick::SetMiniIso(small_tree_quick &tree, int ilep, int ParticleType){
  double bignum = std::numeric_limits<double>::max();
  switch(ParticleType){
  case 11:
    tree.els_reliso_r01().push_back(GetMiniIsolation(ParticleType, ilep, 0.1, 0.1));
    tree.els_reliso_r015().push_back(GetMiniIsolation(ParticleType, ilep, 0.15, 0.15));
    tree.els_reliso_r02().push_back(GetMiniIsolation(ParticleType, ilep, 0.2, 0.2));
    tree.els_reliso_r03().push_back(GetMiniIsolation(ParticleType, ilep, 0.3, 0.3));
    tree.els_reliso_r04().push_back(GetMiniIsolation(ParticleType, ilep, 0.4, 0.4));
    tree.els_miniso_10().push_back(GetMiniIsolation(ParticleType, ilep, 0.05, bignum));
    tree.els_miniso_tr10().push_back(GetMiniIsolation(ParticleType, ilep, 0.05, 0.2));
    tree.els_miniso_10_ch().push_back(GetMiniIsolation(ParticleType, ilep, 0.05, bignum, false, false));
    tree.els_miniso_tr10_ch().push_back(GetMiniIsolation(ParticleType, ilep, 0.05, 0.2, false, false));
    break;
  case 13:
    tree.mus_reliso_r01().push_back(GetMiniIsolation(ParticleType, ilep, 0.1, 0.1));
    tree.mus_reliso_r015().push_back(GetMiniIsolation(ParticleType, ilep, 0.15, 0.15));
    tree.mus_reliso_r02().push_back(GetMiniIsolation(ParticleType, ilep, 0.2, 0.2));
    tree.mus_reliso_r03().push_back(GetMiniIsolation(ParticleType, ilep, 0.3, 0.3));
    tree.mus_reliso_r04().push_back(GetMiniIsolation(ParticleType, ilep, 0.4, 0.4));
    tree.mus_miniso_10().push_back(GetMiniIsolation(ParticleType, ilep, 0.05, bignum));
    tree.mus_miniso_tr10().push_back(GetMiniIsolation(ParticleType, ilep, 0.05, 0.2));
    tree.mus_miniso_10_ch().push_back(GetMiniIsolation(ParticleType, ilep, 0.05, bignum, false, false));
    tree.mus_miniso_tr10_ch().push_back(GetMiniIsolation(ParticleType, ilep, 0.05, 0.2, false, false));
    break;
  default:
    tree.tks_r03_ch().push_back(GetMiniIsolation(ParticleType, ilep, 0.3, 0.3, false, false, true));
    tree.tks_r02_ch().push_back(GetMiniIsolation(ParticleType, ilep, 0.2, 0.2, false, false, true));
    tree.tks_mini_ch().push_back(GetMiniIsolation(ParticleType, ilep, 0.05, bignum, false, false, true));
    tree.tks_r03_ne().push_back(GetMiniIsolation(ParticleType, ilep, 0.3, 0.3, true, true, false));
    tree.tks_r02_ne().push_back(GetMiniIsolation(ParticleType, ilep, 0.2, 0.2, true, true, false));
    tree.tks_mini_ne().push_back(GetMiniIsolation(ParticleType, ilep, 0.05, bignum, true, true, false));
    break;
  }
}

float event_handler_quick::GetMinMTWb(const vector<int> &good_jets,
                                      const double pt_cut,
                                      const double bTag_req,
                                      const bool use_W_mass) const{
  float min_mT(fltmax);
  for (uint ijet(0); ijet<good_jets.size(); ijet++) {
    uint jet = good_jets[ijet];
    if (jets_corr_p4().at(jet).Pt()<pt_cut) continue;
    if (jets_btag_inc_secVertexCombined()->at(jet)<bTag_req) continue;
    float mT = GetMT(use_W_mass ? 80.385 : 0., mets_et()->at(0), mets_phi()->at(0),
                     0., jets_corr_p4().at(jet).Pt(), jets_corr_p4().at(jet).Phi());
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

bool greater_m(const PseudoJet &a, const PseudoJet &b){
  return a.m() > b.m();
}

vector<PseudoJet> sorted_by_m(vector<PseudoJet> pjs){
  sort(pjs.begin(), pjs.end(), greater_m);
  return pjs;
}
