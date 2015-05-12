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
#include "TROOT.h"

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
    tree.weight() = weight()*xsec*luminosity / static_cast<double>(num_total_entries);

    tree.npv() = Npv();
    for(size_t bc(0); bc<PU_bunchCrossing()->size(); ++bc){
      if(PU_bunchCrossing()->at(bc)==0){
        tree.ntrupv() = PU_NumInteractions()->at(bc);
        tree.ntrupv_mean() = PU_TrueNumInteractions()->at(bc);
        break;
      }
    }

    ///////////// MET //////////////////
    tree.met() = met_corr();
    tree.met_phi() = met_phi_corr();
    tree.mindphin_metjet() = GetMinDeltaPhiMETN(3, 50., 2.4, 30., 2.4, true);

    size_t primary_lep=static_cast<size_t>(-1);
    size_t primary_lep_reliso = primary_lep;
    vector<size_t> sigleps;
    TLorentzVector lepmax_p4(0., 0., 0., 0.), lepmax_p4_reliso(0., 0., 0., 0.);
    short lepmax_chg = 0, lepmax_chg_reliso = 0;
    tree.nels() = 0; tree.nvels() = 0;
    tree.nels_reliso() = 0; tree.nvels_reliso() = 0;
    vector<int> sig_electrons = GetElectrons(true, true);
    vector<int> sig_muons = GetMuons(true, true);
    vector<int> sig_electrons_reliso = GetElectrons(true, false);
    vector<int> sig_muons_reliso = GetMuons(true, false);

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
                                      met_corr(), met_phi_corr()));
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
                                      met_corr(), met_phi_corr()));
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
      tree.st() = lepmax_p4.Pt()+met_corr();

      float wx = mets_ex()->at(0) + lepmax_p4.Px();
      float wy = mets_ey()->at(0) + lepmax_p4.Py();
      float wphi = atan2(wy, wx);

      tree.dphi_wlep() = DeltaPhi(wphi, lepmax_p4.Phi());
      tree.mt() = GetMT(lepmax_p4.Pt(), lepmax_p4.Phi(), met_corr(), met_phi_corr());
    }

    if(lepmax_p4_reliso.Pt()>0.){
      tree.lep_pt_reliso() = lepmax_p4_reliso.Pt();
      tree.lep_phi_reliso() = lepmax_p4_reliso.Phi();
      tree.lep_eta_reliso() = lepmax_p4_reliso.Eta();
      tree.lep_charge_reliso() = lepmax_chg_reliso;
      tree.st_reliso() = lepmax_p4_reliso.Pt()+met_corr();

      float wx = mets_ex()->at(0) + lepmax_p4_reliso.Px();
      float wy = mets_ey()->at(0) + lepmax_p4_reliso.Py();
      float wphi = atan2(wy, wx);

      tree.dphi_wlep_reliso() = DeltaPhi(wphi, lepmax_p4_reliso.Phi());
      tree.mt_reliso() = GetMT(lepmax_p4_reliso.Pt(), lepmax_p4_reliso.Phi(), met_corr(), met_phi_corr());
    }

    // vector<mc_particle> parts = GetMCParticles();
    // vector<size_t> moms = GetMoms(parts);
    // tree.mc_type() = TypeCode(parts, moms);

    vector<int> good_jets = GetJets(sig_electrons, sig_muons, 20., 2.4);
    vector<int> good_jets_reliso = GetJets(sig_electrons_reliso, sig_muons_reliso, 20., 2.4);
    tree.njets() = GetNumJets(good_jets, MinJetPt);
    tree.nbl() = GetNumJets(good_jets, MinJetPt, CSVCuts[0]);
    tree.nbm() = GetNumJets(good_jets, MinJetPt, CSVCuts[1]);
    tree.nbt() = GetNumJets(good_jets, MinJetPt, CSVCuts[2]);
    tree.ht() = GetHT(good_jets, MinJetPt);
    tree.ht_reliso() = GetHT(good_jets_reliso, MinJetPt);
    tree.mht() = GetMHT(good_jets, MinJetPt);

    vector<int> dirty_jets = GetJets(vector<int>(0), vector<int>(0), 30., 5.0);
    tree.jets_pt().resize(dirty_jets.size());
    tree.jets_eta().resize(dirty_jets.size());
    tree.jets_phi().resize(dirty_jets.size());
    tree.jets_m().resize(dirty_jets.size());
    tree.jets_csv().resize(dirty_jets.size());
    tree.jets_id().resize(dirty_jets.size());
    tree.jets_islep().resize(dirty_jets.size());
    for(size_t idirty = 0; idirty < dirty_jets.size(); ++idirty){
      int ijet = dirty_jets.at(idirty);
      tree.jets_pt().at(idirty) = jets_corr_p4().at(ijet).Pt();
      tree.jets_eta().at(idirty) = jets_corr_p4().at(ijet).Eta();
      tree.jets_phi().at(idirty) = jets_corr_p4().at(ijet).Phi();
      tree.jets_m().at(idirty) = jets_corr_p4().at(ijet).M();
      tree.jets_csv().at(idirty) = jets_btag_inc_secVertexCombined()->at(ijet);
      tree.jets_id().at(idirty) = jets_parton_Id()->at(ijet);
      tree.jets_islep().at(idirty) = !(find(good_jets.begin(), good_jets.end(), ijet) != good_jets.end());
    }

    vector<int> alljets;
    vector<bool> alljets_islep;
    for(unsigned ijet(0); ijet<jets_corr_p4().size(); ijet++) {
      alljets.push_back(static_cast<int>(ijet));
      alljets_islep.push_back(!(find(good_jets.begin(), good_jets.end(), static_cast<int>(ijet)) 
				!= good_jets.end()));      
    }
    WriteFatJets(tree.nfjets(), tree.mj(),
                 tree.fjets_pt(), tree.fjets_eta(),
                 tree.fjets_phi(), tree.fjets_m(),
                 tree.fjets_nconst(),
                 tree.fjets_sumcsv(), tree.fjets_poscsv(),
                 tree.fjets_btags(), tree.jets_fjet_index(),
                 1.2, alljets);

    tree.Fill();
  }

  tree.Write();

  TString model = model_params()->c_str();
  TString commit = RemoveTrailingNewlines(execute("git rev-parse HEAD"));
  TString type = tree.Type();
  TString root_version = gROOT->GetVersion();
  TString root_tutorial_dir = gROOT->GetTutorialsDir();
  TTree treeglobal("treeglobal", "treeglobal");
  treeglobal.Branch("nev_file", &num_entries);
  treeglobal.Branch("nev_sample", &num_total_entries);
  treeglobal.Branch("commit", &commit);
  treeglobal.Branch("model", &model);
  treeglobal.Branch("type", &type);
  treeglobal.Branch("root_version", &root_version);
  treeglobal.Branch("root_tutorial_dir", &root_tutorial_dir);
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
  const float EtaThresh(5.);
  jets_fjet_index = vector<int>(jets.size(), -1);

  if(gen){
    for(size_t idirty = 0; idirty<jets.size(); ++idirty){
      int jet = jets.at(idirty);
      TLorentzVector v;
      v.SetPtEtaPhiE(mc_jets_pt()->at(jet), mc_jets_eta()->at(jet),
                     mc_jets_phi()->at(jet), mc_jets_energy()->at(jet));
      const PseudoJet this_pj(v.Px(), v.Py(), v.Pz(), v.E());
      if(this_pj.pt()>30.0 && fabs(v.Eta()) <= EtaThresh){
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

      if(this_pj.pt()>30.0 && fabs(this_lv.Eta()) <= EtaThresh){
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

void event_handler_quick::SetMiniIso(small_tree_quick &tree, int ilep, int ParticleType){
  // double bignum = std::numeric_limits<double>::max();
  switch(ParticleType){
  case 11:
    tree.els_miniso_tr10().push_back(GetMiniIsolation(ParticleType, ilep, 0.05, 0.2));
    break;
  case 13:
    tree.mus_miniso_tr10().push_back(GetMiniIsolation(ParticleType, ilep, 0.05, 0.2));
    break;
  default:
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
    float mT = GetMT(use_W_mass ? 80.385 : 0., met_corr(), met_phi_corr(),
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
