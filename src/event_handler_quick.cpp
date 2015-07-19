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

  vector<TString> trig_name;
  trig_name.push_back("PFHT350_PFMET100_NoiseCleaned_v");
  trig_name.push_back("Mu15_IsoVVVL_PFHT350_PFMET70_v");
  trig_name.push_back("Mu15_IsoVVVL_PFHT600_v");
  trig_name.push_back("Mu15_IsoVVVL_BTagCSV0p72_PFHT400_v");
  trig_name.push_back("Mu15_PFHT300_v");
  trig_name.push_back("Ele15_IsoVVVL_PFHT350_PFMET70_v");
  trig_name.push_back("Ele15_IsoVVVL_PFHT600_v");
  trig_name.push_back("Ele15_IsoVVVL_BTagCSV0p72_PFHT400_v");
  trig_name.push_back("Ele15_PFHT300_v");
  trig_name.push_back("DoubleMu8_Mass8_PFHT300_v");
  trig_name.push_back("DoubleEle8_CaloIdM_TrackIdM_Mass8_PFHT300_v");
  trig_name.push_back("PFHT475_v");
  trig_name.push_back("PFHT800_v");
  trig_name.push_back("PFMET120_NoiseCleaned_Mu5_v");
  trig_name.push_back("PFMET170_NoiseCleaned_v");
  trig_name.push_back("Mu17_v");
  trig_name.push_back("Mu17_TrkIsoVVL_v");
  trig_name.push_back("IsoMu17_eta2p1_v");
  trig_name.push_back("IsoMu20_v");
  trig_name.push_back("IsoMu24_eta2p1_v");
  trig_name.push_back("IsoMu27_v");
  trig_name.push_back("Mu50_v");
  trig_name.push_back("Ele27_eta2p1_WPLoose_Gsf_v");
  trig_name.push_back("Ele32_eta2p1_WPLoose_Gsf_v");
  trig_name.push_back("Ele105_CaloIdVT_GsfTrkIdT_v");
  

  Timer timer(num_entries, 1.);
  timer.Start();
  for(int entry = 0; entry < num_entries; ++entry){
    timer.Iterate();
    GetEntry(entry);

    tree.event() = event();
    tree.lumiblock() = lumiblock();
    tree.run() = run();
    if(out_file_name.Contains("Run2015")) tree.weight() = 1.;
    else tree.weight() = Sign(weight())*xsec*luminosity / static_cast<double>(num_total_entries);

    tree.npv() = Npv();
    for(size_t bc(0); bc<PU_bunchCrossing()->size(); ++bc){
      if(PU_bunchCrossing()->at(bc)==0){
        tree.ntrupv() = PU_NumInteractions()->at(bc);
        tree.ntrupv_mean() = PU_TrueNumInteractions()->at(bc);
        break;
      }
    }


     ///////// Triggers ///////
    vector<bool> trig_decision;
    vector<float> trig_prescale;
    if(!GetTriggerInfo(trig_name, trig_decision, trig_prescale)) continue;
    tree.trig()=trig_decision;
    tree.trig_prescale()=trig_prescale;


    /////////JSON////////
    tree.json_golden()=PassesJSONCut("golden"); //defined in phys_objects
    tree.json_dcs()=PassesJSONCut("dcs"); //defined in phys_objects

    ///////////// MET //////////////////
    tree.met() = met_corr();
    tree.met_phi() = met_phi_corr();
    tree.mindphin_metjet() = GetMinDeltaPhiMETN(3, 50., 2.4, 30., 2.4, true);

    TLorentzVector lepmax_p4(0., 0., 0., 0.), lepmax_p4_reliso(0., 0., 0., 0.);
    short lepmax_chg = 0, lepmax_chg_reliso = 0;
    vector<int> sig_electrons = GetElectrons(true, true);
    vector<int> sig_muons = GetMuons(true, true);
    vector<int> sig_electrons_reliso = GetElectrons(true, false);
    vector<int> sig_muons_reliso = GetMuons(true, false);
    vector<int> veto_electrons = GetElectrons(false, true);
    vector<int> veto_muons = GetMuons(false, true);
    vector<int> veto_electrons_reliso = GetElectrons(false, false);
    vector<int> veto_muons_reliso = GetMuons(false, false);
    tree.nels() = sig_electrons.size(); tree.nvels() = veto_electrons.size();
    tree.nels_reliso() = sig_electrons_reliso.size(); tree.nvels_reliso() = veto_electrons_reliso.size();
    tree.nmus() = sig_muons.size(); tree.nvmus() = veto_muons.size();
    tree.nmus_reliso() = sig_muons_reliso.size(); tree.nvmus_reliso() = veto_muons_reliso.size();

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

        // Max pT lepton
        if(els_pt()->at(index) > lepmax_p4.Pt() && IsSignalIdElectron(index) && tree.els_miniso().back()<0.1){
          lepmax_chg = Sign(els_charge()->at(index));
          lepmax_p4 = TLorentzVector(els_px()->at(index), els_py()->at(index),
                                     els_pz()->at(index), els_energy()->at(index));
        }
        if(els_pt()->at(index) > lepmax_p4_reliso.Pt() && IsSignalElectron(index)){
          lepmax_chg_reliso = Sign(els_charge()->at(index));
          lepmax_p4_reliso = TLorentzVector(els_px()->at(index), els_py()->at(index),
                                            els_pz()->at(index), els_energy()->at(index));
        }
      }
    } // Loop over els

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

        // Max pT lepton
        if(mus_pt()->at(index) > lepmax_p4.Pt() && IsSignalIdMuon(index) && tree.mus_miniso().back()<0.2){
          lepmax_chg = Sign(mus_charge()->at(index));
          lepmax_p4 = TLorentzVector(mus_px()->at(index), mus_py()->at(index),
                                     mus_pz()->at(index), mus_energy()->at(index));
        }
        if(mus_pt()->at(index) > lepmax_p4_reliso.Pt() && IsSignalMuon(index)){
          lepmax_chg_reliso = Sign(mus_charge()->at(index));
          lepmax_p4_reliso = TLorentzVector(mus_px()->at(index), mus_py()->at(index),
                                            mus_pz()->at(index), mus_energy()->at(index));
        }
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

    vector<int> good_jets = GetJets(sig_electrons, sig_muons, phys_objects::MinJetPt , 2.4);
    vector<int> good_jets_reliso = GetJets(sig_electrons_reliso, sig_muons_reliso, phys_objects::MinJetPt , 2.4);
    tree.njets() = GetNumJets(good_jets, MinJetPt);
    tree.nbl() = GetNumJets(good_jets, MinJetPt, CSVCuts[0]);
    tree.nbm() = GetNumJets(good_jets, MinJetPt, CSVCuts[1]);
    tree.nbt() = GetNumJets(good_jets, MinJetPt, CSVCuts[2]);
    tree.ht() = GetHT(good_jets, MinJetPt);
    tree.ht_reliso() = GetHT(good_jets_reliso, MinJetPt);
    tree.mht() = GetMHT(good_jets, MinJetPt);

    vector<int> good_jets40 = GetJets(sig_electrons, sig_muons, 40. , 2.4);
    tree.njets40() = GetNumJets(good_jets40, MinJetPt);
    tree.nbl40() = GetNumJets(good_jets40, MinJetPt, CSVCuts[0]);
    tree.nbm40() = GetNumJets(good_jets40, MinJetPt, CSVCuts[1]);
    tree.nbt40() = GetNumJets(good_jets40, MinJetPt, CSVCuts[2]);
    tree.ht40() = GetHT(good_jets40, MinJetPt);

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

    vector<int> mj_jets;
    vector<bool> mj_jets_islep;
    map<size_t,vector<size_t> > mu_matches, el_matches;
    GetMatchedLeptons(sig_muons, sig_electrons, mu_matches, el_matches);
    for(unsigned ijet(0); ijet<jets_corr_p4().size(); ijet++) {
      if(mu_matches.find(ijet) != mu_matches.end() || el_matches.find(ijet) != el_matches.end()){
	mj_jets.push_back(static_cast<int>(ijet));
	mj_jets_islep.push_back(true);
      } // If lepton in jet
      // if(mu_matches.find(ijet) != mu_matches.end() && el_matches.find(ijet) != el_matches.end()) {
      // 	size_t iel = el_matches[ijet][0];
      // 	size_t imu = mu_matches[ijet][0];
      // 	cout<<entry<<": Both els and mus match: jet p=("<<jets_pt()->at(ijet)<<","<<jets_eta()->at(ijet)
      // 	    <<","<<jets_phi()->at(ijet)<<"). el p = ("<<els_pt()->at(iel)<<","<<els_eta()->at(iel)
      // 	    <<","<<els_phi()->at(iel)<<"). mu p = ("<<mus_pt()->at(imu)<<","<<mus_eta()->at(imu)
      // 	    <<","<<mus_phi()->at(imu)<<")"<<endl;
      // }
    } // Loop over all jets
    // Adding all clean jets
    for(unsigned ijet(0); ijet<good_jets.size(); ijet++) {
      mj_jets.push_back(static_cast<int>(ijet));
      mj_jets_islep.push_back(false);      
    } // Loop over good jets

    WriteFatJets(tree.nfjets(), tree.mj(),
                 tree.fjets_pt(), tree.fjets_eta(),
                 tree.fjets_phi(), tree.fjets_m(),
                 tree.fjets_nconst(),
                 tree.fjets_sumcsv(), tree.fjets_poscsv(),
                 tree.fjets_btags(), tree.jets_fjet_index(),
                 1.2, mj_jets);
    WriteFatJets(tree.nfjets08(), tree.mj08(),
                 tree.fjets08_pt(), tree.fjets08_eta(),
                 tree.fjets08_phi(), tree.fjets08_m(),
                 tree.fjets08_nconst(),
                 tree.fjets08_sumcsv(), tree.fjets08_poscsv(),
                 tree.fjets08_btags(), tree.jets_fjet08_index(),
                 0.8, mj_jets);

    /////////////////////////////////  MC  ///////////////////////////////
    std::vector<int> mc_mus, mc_els, mc_taush, mc_tausl;
    GetTrueLeptons(mc_els, mc_mus, mc_taush, mc_tausl);
    tree.ntrumus()   = mc_mus.size();
    tree.ntruels()   = mc_els.size();
    tree.ntrutaush() = mc_taush.size();
    tree.ntrutausl() = mc_tausl.size();
    tree.ntruleps()  = tree.ntrumus()+tree.ntruels()+tree.ntrutaush()+tree.ntrutausl();

    //for systematics:
    float toppt1(0),toppt2(0),topphi1(0),topphi2(0);
    int nisr(0);
    for(unsigned i = 0; i < mc_doc_id()->size(); ++i){
      const int id = static_cast<int>(floor(fabs(mc_doc_id()->at(i))+0.5));
      const int mom = static_cast<int>(floor(fabs(mc_doc_mother_id()->at(i))+0.5));
      const int gmom = static_cast<int>(floor(fabs(mc_doc_grandmother_id()->at(i))+0.5));
      const int ggmom = static_cast<int>(floor(fabs(mc_doc_ggrandmother_id()->at(i))+0.5));
      if(mc_doc_id()->at(i)==6) {toppt1 = mc_doc_pt()->at(i); topphi1 = mc_doc_phi()->at(i);}
      if(mc_doc_id()->at(i)==(-6)){ toppt2 = mc_doc_pt()->at(i); topphi2 = mc_doc_phi()->at(i);}
      if(mc_doc_status()->at(i)==23 && id!=6 && mom!=6 && mom!=24 && gmom!=6 && ggmom!=6) nisr++;
    }
    tree.trutop1_pt() = toppt1;
    tree.trutop2_pt() = toppt2;
    tree.trutop1_phi() = topphi1;
    tree.trutop2_phi() = topphi2;
    tree.ntrumeisr() = nisr;
    
 
    // int nobj = tree.njets() + tree.nmus() + tree.nels();
    // int nobj_mj(0);
    // //int nobj_list(mj_jets.size());
    // for(unsigned ijet(0); ijet < tree.fjets_nconst().size(); ijet++)
    //   nobj_mj += tree.fjets_nconst().at(ijet);
    // if(nobj != nobj_mj) cout<<entry<<": nobj "<<nobj<<", nobj_mj "<<nobj_mj<<endl;

    // if(tree.njets() != static_cast<int>(good_jets.size())) 
    //   cout<<entry<<": njets "<<tree.njets()<<", gj_size "<<good_jets.size()<<endl;

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
  treeglobal.Branch("trig_name", &trig_name);
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
  jets_fjet_index = vector<int>(jets.size(), -1);

  if(gen){
    for(size_t idirty = 0; idirty<jets.size(); ++idirty){
      int jet = jets.at(idirty);
      TLorentzVector v;
      v.SetPtEtaPhiE(mc_jets_pt()->at(jet), mc_jets_eta()->at(jet),
                     mc_jets_phi()->at(jet), mc_jets_energy()->at(jet));
      const PseudoJet this_pj(v.Px(), v.Py(), v.Pz(), v.E());
      sjets.push_back(this_pj);
      ijets.push_back(idirty);
      csvs.push_back(0.);
    }
  }else{
    for(size_t idirty = 0; idirty<jets.size(); ++idirty){

      int jet = jets.at(idirty);
      if(is_nan(jets_corr_p4().at(jet).Px()) || is_nan(jets_corr_p4().at(jet).Py())
         || is_nan(jets_corr_p4().at(jet).Pz()) || is_nan(jets_corr_p4().at(jet).E())
         || (clean && to_clean.at(idirty))) continue;
      const TLorentzVector &this_lv = jets_corr_p4().at(jet);
      const PseudoJet this_pj(this_lv.Px(), this_lv.Py(), this_lv.Pz(), this_lv.E());

      sjets.push_back(this_pj);
      ijets.push_back(idirty);
      csvs.push_back(jets_btag_inc_secVertexCombined()->at(jet));
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
    mj += pj.m();
    ++nfjets;
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
    tree.els_miniso().push_back(els_miniso()->at(ilep));
    break;
  case 13:
    tree.mus_miniso().push_back(mus_miniso()->at(ilep));
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

// MC lepton counting without building the whole tree
void event_handler_quick::GetTrueLeptons(vector<int> &true_electrons, vector<int> &true_muons,
				   vector<int> &true_had_taus, vector<int> &true_lep_taus) {
  true_electrons.clear();
  true_muons.clear();
  true_had_taus.clear();
  true_lep_taus.clear();
  bool tau_to_3tau(false);
  vector<int> lep_from_tau;
  for(unsigned i = 0; i < mc_doc_id()->size(); ++i){
    const int id = static_cast<int>(floor(fabs(mc_doc_id()->at(i))+0.5));
    const int mom = static_cast<int>(floor(fabs(mc_doc_mother_id()->at(i))+0.5));
    const int gmom = static_cast<int>(floor(fabs(mc_doc_grandmother_id()->at(i))+0.5));
    const int ggmom = static_cast<int>(floor(fabs(mc_doc_ggrandmother_id()->at(i))+0.5));
  
    
    if((id == 11 || id == 13) && (mom == 24 || (mom == 15 && (gmom == 24 || (gmom == 15 && ggmom == 24))))){
      if (mom == 24) { // Lep from W
	if (id==11) true_electrons.push_back(i);
	else if (id==13) true_muons.push_back(i);
      } else if(!tau_to_3tau) { // Lep from tau, check for Brem
	uint nlep(1);
	for(uint j=i+1; j<mc_doc_id()->size(); ++j) {
	  const int idb = static_cast<int>(floor(fabs(mc_doc_id()->at(j))+0.5));
	  const int momb = static_cast<int>(floor(fabs(mc_doc_mother_id()->at(j))+0.5));
	  if(momb==15 && (idb==11 || idb==13)) nlep++;
	  if(momb!=15 || (momb==15&&idb==16) || j==mc_doc_id()->size()-1){
	    if(nlep==1){
	      // if (id==11) true_electrons.push_back(i); // If we want to count isolated leptons
	      // else if (id==13) true_muons.push_back(i);
	      lep_from_tau.push_back(i);
	    }
	    i = j-1; // Moving index to first particle after tau daughters
	    break;
	  }
	} // Loop over tau daughters
      } // if lepton comes from tau
    }
    if(id == 15 && mom == 24){
      true_had_taus.push_back(i);
    }
    // Counting number of tau->tautautau
    if((id == 15) && (mom == 15 && (gmom == 24 || (gmom == 15 && ggmom == 24)))){
      uint nlep(1);
      for(uint j=i+1; j<mc_doc_id()->size(); ++j) {
	const int idb = static_cast<int>(floor(fabs(mc_doc_id()->at(j))+0.5));
	const int momb = static_cast<int>(floor(fabs(mc_doc_mother_id()->at(j))+0.5));
	if(momb==15 && idb==15) nlep++;
	if(momb!=15 || (momb==15&&idb==16) || j==mc_doc_id()->size()-1){
	  if(nlep>1) tau_to_3tau = true;
	  i = j-1; // Moving index to first particle after tau daughters
	  break;
	}
      } // Loop over tau daughters
    } // if tau comes from prompt tau
  } // Loop over mc_doc
  // Removing leptonic taus from tau list by finding smallest DeltaR(lep,tau)
  for(unsigned ind = 0; ind < lep_from_tau.size(); ++ind){
    float minDr(9999.), lepEta(mc_doc_eta()->at(lep_from_tau[ind])), lepPhi(mc_doc_phi()->at(lep_from_tau[ind]));
    int imintau(-1);
    for(unsigned itau=0; itau < true_had_taus.size(); itau++){
      if(mc_doc_mother_id()->at(lep_from_tau[ind]) != mc_doc_id()->at(true_had_taus[itau])) continue;
      float tauEta(mc_doc_eta()->at(true_had_taus[itau])), tauPhi(mc_doc_phi()->at(true_had_taus[itau]));
      float tauDr(dR(tauEta,lepEta, tauPhi,lepPhi));
      if(tauDr < minDr) {
	minDr = tauDr;
	imintau = itau;
      }
    }
    if(imintau>=0) {
      true_lep_taus.push_back(imintau);
      true_had_taus.erase(true_had_taus.begin()+imintau);
    } else cout<<"Not found a tau match for lepton "<<ind<<endl; // Should not happen
  } // Loop over leptons from taus
  return;
}

bool event_handler_quick::greater_m(const fastjet::PseudoJet &a, const fastjet::PseudoJet &b){
  return a.m() > b.m();
}

vector<fastjet::PseudoJet> event_handler_quick::sorted_by_m(vector<fastjet::PseudoJet> pjs){
  sort(pjs.begin(), pjs.end(), greater_m);
  return pjs;
}
