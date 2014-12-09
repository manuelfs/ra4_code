// phys_objects: Class with the standard physics objects that inherits from the cfa class.
//              Reduced tree makers should inherit from this class

#include "phys_objects.hpp"

#include <cfloat>
#include <cmath>
#include <cstdio>
#include <cstdlib>

#include <iomanip>
#include <fstream>
#include <iostream>
#include <limits>
#include <typeinfo>
#include <stdexcept>
#include <set>

#include "TMath.h"
#include "TLorentzVector.h"

#include "fastjet/ClusterSequence.hh"
#include "fastjet/PseudoJet.hh"

#include "cfa_8.hpp"
#include "cfa_13.hpp"
#include "pdtlund.hpp"
#include "utilities.hpp"

using namespace std;

namespace{
  const float fltmax = numeric_limits<float>::max();
}

float phys_objects::MinSignalLeptonPt = 20.0;
float phys_objects::MinVetoLeptonPt = 15.0;
float phys_objects::MinTrackPt = phys_objects::MinVetoLeptonPt;
float phys_objects::bad_val = -999.;

phys_objects::phys_objects(const string &fileName, const bool is_8TeV):
  cfa(fileName, is_8TeV){
}

/////////////////////////////////////////////////////////////////////////
////////////////////////////////  MUONS  ////////////////////////////////
/////////////////////////////////////////////////////////////////////////
vector<int> phys_objects::GetMuons(bool doSignal) const {
  vector<int> muons;
  for(unsigned index=0; index<mus_pt()->size(); index++)
    if(doSignal){
      if(IsSignalMuon(index)) muons.push_back(index);
    }else{
      if(IsVetoMuon(index)) muons.push_back(index);
    }
  return muons;
}

bool phys_objects::IsSignalMuon(unsigned imu) const {
  if(imu >= mus_pt()->size()) return false;
  return IsSignalIdMuon(imu)
    && 0.12>GetMuonIsolation(imu)
    && mus_pt()->at(imu)>MinSignalLeptonPt;
}

bool phys_objects::IsVetoMuon(unsigned imu) const{
  if(imu >= mus_pt()->size()) return false;
  return IsVetoIdMuon(imu)
    && 0.2>GetMuonIsolation(imu)
    && mus_pt()->at(imu)>MinVetoLeptonPt;
}

bool phys_objects::IsSignalIdMuon(unsigned imu) const {
  if(imu >= mus_pt()->size()) return false;
  return IsIdMuon(imu, kTight)
    && fabs(mus_eta()->at(imu))<2.4;
}

bool phys_objects::IsVetoIdMuon(unsigned imu) const {
  if(imu >= mus_pt()->size()) return false;
  return IsIdMuon(imu, kTight)//Intentionally vetoing on "tight" muons!
    && fabs(mus_eta()->at(imu))<2.4;
}

bool phys_objects::IsIdMuon(unsigned imu, CutLevel threshold) const{
  if(imu>=mus_pt()->size()) return false;

  bool pf_cut, global_cut, global_or_tracker_cut, globalprompttight_cut;
  double chisq_cut, hits_cut, stations_cut, dxy_cut, dz_cut, pixel_cut, layers_cut;
  //See https://twiki.cern.ch/twiki/bin/view/CMSPublic/SWGuideMuonId#Tight_Muon
  switch(threshold){
  default:
  case kVeto:
  case kLoose:
    pf_cut                = true;
    global_or_tracker_cut = true;
    global_cut            = false;
    globalprompttight_cut = false;
    chisq_cut             = fltmax;
    hits_cut              = -fltmax;
    stations_cut          = -fltmax;
    dxy_cut               = fltmax;
    dz_cut                = fltmax;
    pixel_cut             = -fltmax;
    layers_cut            = -fltmax;
  case kMedium:
  case kTight:
    pf_cut                = true;
    global_or_tracker_cut = false;
    global_cut            = true;
    globalprompttight_cut = true;
    chisq_cut             = 10.0;
    hits_cut              = 0.0;
    stations_cut          = 1.0;
    dxy_cut               = 0.2;
    dz_cut                = 0.5;
    pixel_cut             = 0;
    layers_cut            = 5;
  }

  bool isPF = true;
  if(Type()==typeid(cfa_8)){
    isPF = mus_isPFMuon()->at(imu);
  }else if(Type()==typeid(cfa_13)){
    isPF = mus_isPF()->at(imu);
  }
  const double d0 = mus_tk_d0dum()->at(imu)
    -pv_x()->at(0)*sin(mus_tk_phi()->at(imu))
    +pv_y()->at(0)*cos(mus_tk_phi()->at(imu));
  const double dz = mus_tk_vz()->at(imu)-pv_z()->at(0);

  return (!pf_cut || isPF)
    && (!global_or_tracker_cut || mus_isGlobalMuon()->at(imu)>0 || mus_isTrackerMuon()->at(imu)>0)
    && (!global_cut || mus_isGlobalMuon()->at(imu)>0)
    && (!globalprompttight_cut || mus_id_GlobalMuonPromptTight()->at(imu)>0)
    && (true || chisq_cut)//Not available in cfa. Included in isGlobalMuonPromptTight for 2011 at least.
    && (true || hits_cut)//Not available in cfa?
    && mus_numberOfMatchedStations()->at(imu) > stations_cut
    && dxy_cut > fabs(d0)
    && dz_cut > fabs(dz)
    && mus_tk_numvalPixelhits()->at(imu) > pixel_cut
    && mus_tk_LayersWithMeasurement()->at(imu) > layers_cut;
}

float phys_objects::GetMuonIsolation(unsigned imu) const {
  if(imu >= mus_pt()->size()) return -999;
  double sumEt = mus_pfIsolationR04_sumNeutralHadronEt()->at(imu)
    + mus_pfIsolationR04_sumPhotonEt()->at(imu)
    - 0.5*mus_pfIsolationR04_sumPUPt()->at(imu);
  if(sumEt<0.0) sumEt=0.0;
  return (mus_pfIsolationR04_sumChargedHadronPt()->at(imu) + sumEt)/mus_pt()->at(imu);
}

/////////////////////////////////////////////////////////////////////////
//////////////////////////////  ELECTRONS  //////////////////////////////
/////////////////////////////////////////////////////////////////////////
vector<int> phys_objects::GetElectrons(bool doSignal) const {
  vector<int> electrons;
  for(unsigned index=0; index<els_pt()->size(); index++)
    if(doSignal){
      if(IsSignalElectron(index)) electrons.push_back(index);
    }else{
      if(IsVetoElectron(index)) electrons.push_back(index);
    }
  return electrons;
}

bool phys_objects::IsSignalElectron(unsigned iel) const {
  if(iel >= els_pt()->size()) return false;
  return IsSignalIdElectron(iel, true)
    && els_pt()->at(iel)>=MinSignalLeptonPt;
}

bool phys_objects::IsVetoElectron(unsigned iel) const {
  if(iel >= els_pt()->size()) return false;
  return IsVetoIdElectron(iel, true)
    && els_pt()->at(iel)>=MinVetoLeptonPt;
}

bool phys_objects::IsSignalIdElectron(unsigned iel, bool do_iso) const {
  if(iel >= els_pt()->size()) return false;
  return IsIdElectron(iel, kMedium, do_iso);
}

bool phys_objects::IsVetoIdElectron(unsigned iel, bool do_iso) const {
  if(iel >= els_pt()->size()) return false;
  return IsIdElectron(iel, kVeto, do_iso);
}

bool phys_objects::IsIdElectron(unsigned iel, CutLevel threshold, bool do_iso) const{
  if(iel>=els_pt()->size()) return false;
  bool barrel;
  if(fabs(els_scEta()->at(iel))<=1.479){
    barrel = true;
  }else if(fabs(els_scEta()->at(iel))<2.5){
    barrel = false;
  }else{
    return false;
  }

  double deta_cut, dphi_cut, ieta_cut, hovere_cut, d0_cut, dz_cut,
    ooeminusoop_cut, reliso_cut, vprob_cut, misshits_cut;

  if(Type()==typeid(cfa_8)){
    //See https://twiki.cern.ch/twiki/bin/viewauth/CMS/EgammaCutBasedIdentification#Barrel_Cuts_eta_supercluster_1_4
    const bool high_pt = els_pt()->at(iel)>20.0;
    switch(threshold){
    default:
    case kVeto:
      deta_cut        = barrel ? 0.007   : 0.01;
      dphi_cut        = barrel ? 0.8     : 0.7;
      ieta_cut        = barrel ? 0.01    : 0.03;
      hovere_cut      = barrel ? 0.15    : fltmax;
      d0_cut          = barrel ? 0.04    : 0.04;
      dz_cut          = barrel ? 0.2     : 0.2;
      ooeminusoop_cut = barrel ? fltmax  : fltmax;
      reliso_cut      = barrel ? 0.15    : 0.15;
      vprob_cut       = barrel ? fltmax  : fltmax;
      misshits_cut    = barrel ? fltmax  : fltmax;
      break;
    case kLoose:
      deta_cut        = barrel ? 0.007   : 0.009;
      dphi_cut        = barrel ? 0.15    : 0.10;
      ieta_cut        = barrel ? 0.01    : 0.03;
      hovere_cut      = barrel ? 0.12    : 0.10;
      d0_cut          = barrel ? 0.02    : 0.02;
      dz_cut          = barrel ? 0.2     : 0.2;
      ooeminusoop_cut = barrel ? 0.05    : 0.05;
      reliso_cut      = barrel ? 0.15    : (high_pt ? 0.15 : 0.10);
      vprob_cut       = barrel ? 1.e-6   : 1.e-6;
      misshits_cut    = barrel ? 1       : 1;
      break;
    case kMedium:
      deta_cut        = barrel ? 0.004   : 0.007;
      dphi_cut        = barrel ? 0.06    : 0.03;
      ieta_cut        = barrel ? 0.01    : 0.03;
      hovere_cut      = barrel ? 0.12    : 0.1;
      d0_cut          = barrel ? 0.02    : 0.02;
      dz_cut          = barrel ? 0.1     : 0.1;
      ooeminusoop_cut = barrel ? 0.05    : 0.05;
      reliso_cut      = barrel ? 0.15    : (high_pt ? 0.15 : 0.10);
      vprob_cut       = barrel ? 1.e-6   : 1.e-6;
      misshits_cut    = barrel ? 1       : 1;
      break;
    case kTight:
      deta_cut        = barrel ? 0.004   : 0.005;
      dphi_cut        = barrel ? 0.03    : 0.02;
      ieta_cut        = barrel ? 0.01    : 0.03;
      hovere_cut      = barrel ? 0.12    : 0.10;
      d0_cut          = barrel ? 0.02    : 0.02;
      dz_cut          = barrel ? 0.1     : 0.1;
      ooeminusoop_cut = barrel ? 0.05    : 0.05;
      reliso_cut      = barrel ? 0.10    : (high_pt ? 0.10 : 0.07);
      vprob_cut       = barrel ? 1.e-6   : 1.e-6;
      misshits_cut    = barrel ? 1       : 0;
      break;
    }
  }else{
    //See https://twiki.cern.ch/twiki/bin/viewauth/CMS/CutBasedElectronIdentificationRun2#CSA14_selection_conditions_25ns
    switch(threshold){
    default:
    case kVeto:
      deta_cut        = barrel ? 0.02    : 0.0141;
      dphi_cut        = barrel ? 0.2579  : 0.2591;
      ieta_cut        = barrel ? 0.0125  : 0.0371;
      hovere_cut      = barrel ? 0.2564  : 0.1335;
      d0_cut          = barrel ? 0.025   : 0.2232;
      dz_cut          = barrel ? 0.5863  : 0.9513;
      ooeminusoop_cut = barrel ? 0.1508  : 0.1542;
      reliso_cut      = barrel ? 0.3313  : 0.3816;
      vprob_cut       = barrel ? 1.e-6   : 1.e-6;
      misshits_cut    = barrel ? 2       : 3;
      break;
    case kLoose:
      deta_cut        = barrel ? 0.0181  : 0.0124;
      dphi_cut        = barrel ? 0.0936  : 0.0624;
      ieta_cut        = barrel ? 0.0123  : 0.035;
      hovere_cut      = barrel ? 0.141   : 0.1115;
      d0_cut          = barrel ? 0.0166  : 0.098;
      dz_cut          = barrel ? 0.54342 : 0.9187;
      ooeminusoop_cut = barrel ? 0.1353  : 0.1443;
      reliso_cut      = barrel ? 0.24    : 0.3529;
      vprob_cut       = barrel ? 1.e-6   : 1.e-6;
      misshits_cut    = barrel ? 1       : 1;
      break;
    case kMedium:
      deta_cut        = barrel ? 0.0106  : 0.0108;
      dphi_cut        = barrel ? 0.0323  : 0.0455;
      ieta_cut        = barrel ? 0.0107  : 0.0318;
      hovere_cut      = barrel ? 0.067   : 0.097;
      d0_cut          = barrel ? 0.0131  : 0.0845;
      dz_cut          = barrel ? 0.22310 : 0.7523;
      ooeminusoop_cut = barrel ? 0.1043  : 0.1201;
      reliso_cut      = barrel ? 0.2179  : 0.254;
      vprob_cut       = barrel ? 1.e-6   : 1.e-6;
      misshits_cut    = barrel ? 1       : 1;
      break;
    case kTight:
      deta_cut        = barrel ? 0.0091  : 0.0106;
      dphi_cut        = barrel ? 0.031   : 0.0359;
      ieta_cut        = barrel ? 0.0106  : 0.0305;
      hovere_cut      = barrel ? 0.0532  : 0.0835;
      d0_cut          = barrel ? 0.0126  : 0.0163;
      dz_cut          = barrel ? 0.0116  : 0.5999;
      ooeminusoop_cut = barrel ? 0.0609  : 0.1126;
      reliso_cut      = barrel ? 0.1649  : 0.2075;
      vprob_cut       = barrel ? 1.e-6   : 1.e-6;
      misshits_cut    = barrel ? 1       : 1;
      break;
    }
  }

  const double d0 = els_d0dum()->at(iel)
    -pv_x()->at(0)*sin(els_tk_phi()->at(iel))
    +pv_y()->at(0)*cos(els_tk_phi()->at(iel));
  const double dz = fabs(els_vz()->at(iel)-pv_z()->at(0));
  const double sigietaieta = (Type()==typeid(cfa_13)
			      ? els_full5x5_sigmaIetaIeta()->at(iel)
			      : els_sigmaIEtaIEta()->at(iel));

  return deta_cut > fabs(els_dEtaIn()->at(iel))
    && dphi_cut > fabs(els_dPhiIn()->at(iel))
    && ieta_cut > sigietaieta
    && hovere_cut > els_hadOverEm()->at(iel)
    && d0_cut > fabs(d0)
    && dz_cut > fabs(dz)
    && ooeminusoop_cut > fabs((1.0-els_eOverPIn()->at(iel))/els_caloEnergy()->at(iel))
    && (!do_iso || reliso_cut>GetElectronIsolation(iel))
    && ((true || vprob_cut) && (Type()!=typeid(cfa_8) || !els_hasMatchedConversion()->at(iel)))//Skip cut in cfa_13; use alternative in cfa_8
    && (Type()==typeid(cfa_13) || !els_n_inner_layer() || misshits_cut >= els_n_inner_layer()->at(iel));//Missing in phys14
}

float phys_objects::GetElectronIsolation(unsigned iel) const {
  if(Type()==typeid(cfa_8)){
    double sumEt = els_PFphotonIsoR03()->at(iel)
      + els_PFneutralHadronIsoR03()->at(iel)
      - rho_kt6PFJetsForIsolation2011() * GetEffectiveArea(els_scEta()->at(iel), IsMC());
    if(sumEt<0.0) sumEt=0;
    return (els_PFchargedHadronIsoR03()->at(iel) + sumEt)/els_pt()->at(iel);
  }else if(Type()==typeid(cfa_13)){
    float absiso = els_pfIsolationR03_sumChargedHadronPt()->at(iel)
      + max(0.0,
	    els_pfIsolationR03_sumNeutralHadronEt()->at(iel)
	    +els_pfIsolationR03_sumPhotonEt()->at(iel)
	    -0.5*els_pfIsolationR03_sumPUPt()->at(iel));
    return absiso/els_pt()->at(iel);
  }else{
    throw logic_error("Unknown type "
		      + string(Type().name())
		      + " in phys_objects::GetElectronIsolation");
    return 0.0;
  }
}

float phys_objects::GetEffectiveArea(float SCEta, bool isMC) const {
  SCEta = fabs(SCEta);
  if(isMC){
    if(     SCEta < 1.0  ) return 0.110;
    else if(SCEta < 1.479) return 0.130;
    else if(SCEta < 2.0  ) return 0.089;
    else if(SCEta < 2.2  ) return 0.130;
    else if(SCEta < 2.3  ) return 0.150;
    else if(SCEta < 2.4  ) return 0.160;
    else                   return 0.190;
  }else{
    //kEleGammaAndNeutralHadronIso03 from 2011 data
    //obtained from http://cmssw.cvs.cern.ch/cgi-bin/cmssw.cgi/UserCode/EGamma/EGammaAnalysisTools/interface/ElectronEffectiveArea.h?revision=1.3&view=markup
    if(     SCEta < 1.0  ) return 0.100;
    else if(SCEta < 1.479) return 0.120;
    else if(SCEta < 2.0  ) return 0.085;
    else if(SCEta < 2.2  ) return 0.110;
    else if(SCEta < 2.4  ) return 0.120;
    else                   return 0.130;
  }
}

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////  LEPTONS  /////////////////////////////
/////////////////////////////////////////////////////////////////////////
int phys_objects::GetMom(const float id, const float mom, const float gmom,
                         const float ggmom, bool &fromW){
  const int iid = TMath::Nint(id);
  const int imom = TMath::Nint(mom);
  const int igmom = TMath::Nint(gmom);
  const int iggmom = TMath::Nint(ggmom);

  int ret_mom = 0;
  if(imom != iid){
    ret_mom = imom;
  }else if(igmom != iid){
    ret_mom = igmom;
  }else{
    ret_mom = iggmom;
  }

  fromW = (abs(imom)==24 || abs(igmom)==24 || abs(iggmom)==24);

  return ret_mom;
}

void phys_objects::GetPtRels(std::vector<float> &els_ptrel,
			     std::vector<float> &els_mindr,
			     std::vector<float> &mus_ptrel,
			     std::vector<float> &mus_mindr,
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
      if(IsSignalElectron(el)){
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
      if(IsSignalMuon(mu)){
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

      mus_ptrel.at(mu) = p4mu.Pt(p4jet.Vect());
      mus_mindr.at(mu) = p4mu.DeltaR(p4jet);
    }
  }
}

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////  TRACKS  //////////////////////////////
/////////////////////////////////////////////////////////////////////////
bool phys_objects::IsGoodIsoTrack(unsigned itrk) const{
  if(itrk>=isotk_pt()->size()) return false;
  return isotk_pt()->at(itrk)>=MinTrackPt
    && (isotk_iso()->at(itrk)/isotk_pt()->at(itrk) < 0.1)
    && (fabs(isotk_dzpv()->at(itrk))<0.1)
    && (fabs(isotk_eta()->at(itrk))<2.4);
}

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////  JETS  ////////////////////////////////
/////////////////////////////////////////////////////////////////////////
vector<int> phys_objects::GetJets(const vector<int> &SigEl, const vector<int> &SigMu,
                                  const vector<int> &VetoEl, const vector<int> &VetoMu,
                                  double pt_thresh, double eta_thresh) const {
  vector<int> jets;
  vector<bool> jet_is_lepton(jets_pt()->size(), false);

  // Finding jets that contain good leptons
  for(unsigned index = 0; index < SigEl.size(); index++) {
    int ijet = els_jet_ind()->at(SigEl[index]);
    if(ijet >= 0) {jet_is_lepton[ijet] = true;
    }
  }
  for(unsigned index = 0; index < VetoEl.size(); index++) {
    int ijet = els_jet_ind()->at(VetoEl[index]);
    if(ijet >= 0) jet_is_lepton[ijet] = true;
  }

  for(unsigned index = 0; index < SigMu.size(); index++) {
    int ijet = mus_jet_ind()->at(SigMu[index]);
    if(ijet >= 0) {jet_is_lepton[ijet] = true;
    }
  }
  for(unsigned index = 0; index < VetoMu.size(); index++) {
    int ijet = mus_jet_ind()->at(VetoMu[index]);
    if(ijet >= 0) jet_is_lepton[ijet] = true;
  }

  // Tau/photon cleaning, and calculation of HT
  for(unsigned ijet = 0; ijet<jets_pt()->size(); ijet++) {
    if(!IsGoodJet(ijet, pt_thresh, eta_thresh) || jet_is_lepton[ijet]) continue;

    // double tmpdR, partp, jetp = sqrt(pow(jets_px()->at(ijet),2)+pow(jets_py()->at(ijet),2)+pow(jets_pz()->at(ijet),2));
    // bool useJet = true;
    // Tau cleaning: jet rejected if withing deltaR = 0.4 of tau, and momentum at least 60% from tau
    // for(unsigned index = 0; index < taus_pt()->size(); index++) {
    //   tmpdR = dR(jets_eta()->at(ijet), taus_eta()->at(index), jets_phi()->at(ijet), taus_phi()->at(index));
    //   partp = sqrt(pow(taus_px()->at(index),2)+pow(taus_py()->at(index),2)+pow(taus_pz()->at(index),2));
    //   if(tmpdR < 0.4 && partp/jetp >= 0.6){useJet = false; break;}
    // }
    // if(!useJet) continue;

    // // Photon cleaning: jet rejected if withing deltaR = 0.4 of photon, and momentum at least 60% from photon
    // for(unsigned index = 0; index < photons_pt()->size(); index++) {
    //   tmpdR = dR(jets_eta()->at(ijet), photons_eta()->at(index), jets_phi()->at(ijet), photons_phi()->at(index));
    //   partp = sqrt(pow(photons_px()->at(index),2)+pow(photons_py()->at(index),2)+pow(photons_pz()->at(index),2));
    //   if(tmpdR < 0.4 && partp/jetp >= 0.6){useJet = false; break;}
    // }
    // if(!useJet) continue;

    jets.push_back(ijet);
  } // Loop over jets
  return jets;
}

bool phys_objects::IsGoodJet(unsigned ijet, double ptThresh, double etaThresh) const{
  if(jets_pt()->size()<=ijet) return false;
  if(!IsBasicJet(ijet)) return false;
  if(jets_pt()->at(ijet)<ptThresh || fabs(jets_eta()->at(ijet))>etaThresh) return false;
  return true;
}

bool phys_objects::IsBasicJet(unsigned ijet) const{
  double rawRatio =(jets_rawPt()->at(ijet)/jets_pt()->at(ijet)); // Same as jets_corrFactorRaw
  const double jetenergy = jets_energy()->at(ijet) * rawRatio;
  double NEF = -999., CEF = -999., NHF=-999., CHF=-999.;
  double chgMult=jets_chg_Mult()->at(ijet);
  double numConst=jets_mu_Mult()->at(ijet)+jets_neutral_Mult()->at(ijet)+jets_chg_Mult()->at(ijet);

  if(jetenergy > 0){
    NEF = jets_neutralEmE()->at(ijet)/jetenergy;
    CEF = jets_chgEmE()->at(ijet)/jetenergy;
    NHF = jets_neutralHadE()->at(ijet)/jetenergy;
    CHF = jets_chgHadE()->at(ijet)/jetenergy;
  }

  return (NEF < 0.99 && CEF < 0.99 && NHF < 0.99 && CHF > 0 &&
          chgMult > 0 && numConst > 1);
}

/////////////////////////////////////////////////////////////////////////
////////////////////////////  TRUTH-MATCHING  ///////////////////////////
/////////////////////////////////////////////////////////////////////////
int phys_objects::GetTrueMuon(int index, int &momID, bool &fromW, double &closest_dR) const {
  if(index < 0 || index >= static_cast<int>(mus_eta()->size())) return -1;

  int closest_imc = -1, idLepton = 0;
  double dR = 9999.; closest_dR = 9999.;
  double MCEta, MCPhi;
  double RecEta = mus_eta()->at(index), RecPhi = mus_phi()->at(index);
  for(unsigned imc=0; imc < mc_mus_id()->size(); imc++){
    MCEta = mc_mus_eta()->at(imc); MCPhi = mc_mus_phi()->at(imc);
    dR = sqrt(pow(RecEta-MCEta,2) + pow(RecPhi-MCPhi,2));
    if(dR < closest_dR) {
      closest_dR = dR;
      closest_imc = imc;
    }
  }
  if(closest_imc >= 0){
    idLepton = static_cast<int>(mc_mus_id()->at(closest_imc));
    momID = GetMom(mc_mus_id()->at(closest_imc), mc_mus_mother_id()->at(closest_imc),
                   mc_mus_grandmother_id()->at(closest_imc),
                   mc_mus_ggrandmother_id()->at(closest_imc),
                   fromW);
  } else {
    closest_imc = GetTrueParticle(RecEta, RecPhi, closest_dR);
    if(closest_imc >= 0){
      idLepton = static_cast<int>(mc_doc_id()->at(closest_imc));
      momID = GetMom(mc_doc_id()->at(closest_imc), mc_doc_mother_id()->at(closest_imc),
                     mc_doc_grandmother_id()->at(closest_imc),
                     mc_doc_ggrandmother_id()->at(closest_imc),
                     fromW);
    } else {
      momID = 0;
      idLepton = 0;
      fromW = false;
    }
  }
  return idLepton;
}

int phys_objects::GetTrueElectron(int index, int &momID, bool &fromW, double &closest_dR) const {
  if(index < 0 || index >= static_cast<int>(els_eta()->size())) return -1;

  int closest_imc = -1, idLepton = 0;
  double dR = 9999.; closest_dR = 9999.;
  double MCEta, MCPhi;
  double RecEta = els_eta()->at(index), RecPhi = els_phi()->at(index);
  for(unsigned imc=0; imc < mc_electrons_id()->size(); imc++){
    MCEta = mc_electrons_eta()->at(imc); MCPhi = mc_electrons_phi()->at(imc);
    dR = sqrt(pow(RecEta-MCEta,2) + pow(RecPhi-MCPhi,2));
    if(dR < closest_dR) {
      closest_dR = dR;
      closest_imc = imc;
    }
  }
  if(closest_imc >= 0){
    idLepton = static_cast<int>(mc_electrons_id()->at(closest_imc));
    momID = GetMom(mc_electrons_id()->at(closest_imc), mc_electrons_mother_id()->at(closest_imc),
                   mc_electrons_grandmother_id()->at(closest_imc),
                   mc_electrons_ggrandmother_id()->at(closest_imc),
                   fromW);
  } else {
    closest_imc = GetTrueParticle(RecEta, RecPhi, closest_dR);
    if(closest_imc >= 0){
      momID = GetMom(mc_doc_id()->at(closest_imc), mc_doc_mother_id()->at(closest_imc),
                     mc_doc_grandmother_id()->at(closest_imc),
                     mc_doc_ggrandmother_id()->at(closest_imc),
                     fromW);
      idLepton = static_cast<int>(mc_doc_id()->at(closest_imc));
    } else {
      momID = 0;
      idLepton = 0;
      fromW = false;
    }
  }
  return idLepton;
}

int phys_objects::GetTrueParticle(double RecEta, double RecPhi, double &closest_dR) const {
  int closest_imc = -1;
  double dR = 9999.; closest_dR = 9999.;
  double MCEta, MCPhi;
  for(unsigned imc=0; imc < mc_doc_id()->size(); imc++){
    MCEta = mc_doc_eta()->at(imc); MCPhi = mc_doc_phi()->at(imc);
    dR = sqrt(pow(RecEta-MCEta,2) + pow(RecPhi-MCPhi,2));
    if(dR < closest_dR) {
      closest_dR = dR;
      closest_imc = imc;
    }
  }
  return closest_imc;
}

/////////////////////////////////////////////////////////////////////////
////////////////////////////  EVENT CLEANING  ///////////////////////////
/////////////////////////////////////////////////////////////////////////
bool phys_objects::PassesPVCut() const{
  if(beamSpot_x()->size()<1 || pv_x()->size()<1) return false;
  const double pv_rho(sqrt(pv_x()->at(0)*pv_x()->at(0) + pv_y()->at(0)*pv_y()->at(0)));
  if(pv_ndof()->at(0)>4 && fabs(pv_z()->at(0))<24. && pv_rho<2.0 && pv_isFake()->at(0)==0) return true;
  return false;
}

bool phys_objects::PassesMETCleaningCut() const{
  bool hbhe(false), ecalTP(false), scrapingVeto(false);
  if(Type()==typeid(cfa_8)){
    hbhe = hbhefilter_decision();
    ecalTP = ecalTPfilter_decision();
    scrapingVeto = scrapingVeto_decision();
  }else if(Type()==typeid(cfa_13)){
    hbhe = true;
    ecalTP = true;
    scrapingVeto = true;
  }else{
    return false;
  }
  return cschalofilter_decision()
    && hbhe
    && hcallaserfilter_decision()
    && ecalTP
    && trackingfailurefilter_decision()
    && eebadscfilter_decision()
    && scrapingVeto;
}

double phys_objects::GetDZ(double vx, double vy, double vz,
			   double px, double py, double pz,
			   int firstGoodVertex) const {
  return vz - pv_z()->at(firstGoodVertex)
    -((vx-pv_x()->at(firstGoodVertex))*px+(vy-pv_y()->at(firstGoodVertex))*py)*pz/(px*px+py*py);
}

/////////////////////////////////////////////////////////////////////////
////////////////////////////////  EVENT VARS/////////////////////////////
/////////////////////////////////////////////////////////////////////////

bool phys_objects::IsMC() const {
  return (SampleName().find("Run201") == string::npos);
}

double phys_objects::GetDeltaPhiMETN(unsigned goodJetI, float otherpt, float othereta, bool useArcsin) const {
  double deltaT = GetDeltaPhiMETN_deltaT(goodJetI, otherpt, othereta);
  double dp = fabs(deltaphi(jets_phi()->at(goodJetI), mets_phi()->at(0)));
  double dpN = 0.0;
  if(useArcsin) {
    if( deltaT/mets_et()->at(0) >= 1.0){
      dpN = dp / (TMath::Pi()/2.0);
    }else{
      dpN = dp / asin(deltaT/mets_et()->at(0));
    }
  }else{
    dpN = dp / atan2(deltaT, static_cast<double>(mets_et()->at(0)));
  }
  return dpN;
}

double phys_objects::GetDeltaPhiMETN_deltaT(unsigned goodJetI, float otherpt, float othereta) const {
  if(goodJetI>=jets_pt()->size()) return -99.;

  double sum = 0;
  for (unsigned i=0; i< jets_pt()->size(); i++) {
    if(i==goodJetI) continue;
    if(IsGoodJet(i, otherpt, othereta)){
      double jetres = 0.1;
      sum += pow( jetres*(jets_px()->at(goodJetI)*jets_py()->at(i) - jets_py()->at(goodJetI)*jets_px()->at(i)), 2);
    }
  }
  double deltaT = sqrt(sum)/jets_pt()->at(goodJetI);
  return deltaT;
}

double phys_objects::GetMinDeltaPhiMETN(unsigned maxjets, float mainpt, float maineta,
                                        float otherpt, float othereta, bool useArcsin) const {
  double mdpN=numeric_limits<double>::max();
  unsigned nGoodJets(0);
  for (unsigned i=0; i<jets_pt()->size(); i++) {
    if (!IsGoodJet(i, mainpt, maineta)) continue;
    nGoodJets++;
    double dpN = GetDeltaPhiMETN(i, otherpt, othereta, useArcsin);
    if (dpN>=0&&dpN<mdpN) mdpN=dpN;
    if (nGoodJets>=maxjets) break;
  }
  return mdpN;
}

double phys_objects::GetHT(const vector<int> &good_jets, double pt_cut) const{
  double ht = 0.0;
  for(size_t i = 0; i < good_jets.size(); ++i){
    const double pt = jets_pt()->at(good_jets.at(i));
    if(pt>pt_cut) ht += pt;
  }
  return ht;
}

size_t phys_objects::GetNumJets(const vector<int> &good_jets,
				double pt_cut,
				double csv_cut) const{
  size_t num_jets = 0;
  for(size_t i = 0; i < good_jets.size(); ++i){
    if(jets_pt()->at(good_jets.at(i)) > pt_cut
       && jets_btag_secVertexCombined()->at(good_jets.at(i)) > csv_cut){
      ++num_jets;
    }
  }
  return num_jets;
}

float phys_objects::GetSphericity(const vector<int> &good_jets,
				  const vector<int> &good_mus,
				  const vector<int> &good_els,
				  bool linearize){
  float smat[2][2];
  for(size_t i = 0; i < good_jets.size(); ++i){
    const size_t ijet = good_jets.at(i);
    const double px = jets_px()->at(ijet);
    const double py = jets_py()->at(ijet);
    const double ptinv = linearize ? (1.0/jets_pt()->at(ijet)) : 1.0;

    smat[0][0] += px*px*ptinv;
    smat[0][1] += px*py*ptinv;
    smat[1][1] += py*py*ptinv;
  }

  for(size_t i = 0; i < good_mus.size(); ++i){
    const size_t imu = good_mus.at(i);
    const double px = mus_px()->at(imu);
    const double py = mus_py()->at(imu);
    const double ptinv = linearize ? (1.0/mus_pt()->at(imu)) : 1.0;

    smat[0][0] += px*px*ptinv;
    smat[0][1] += px*py*ptinv;
    smat[1][1] += py*py*ptinv;
  }

  for(size_t i = 0; i < good_els.size(); ++i){
    const size_t iel = good_els.at(i);
    const double px = els_px()->at(iel);
    const double py = els_py()->at(iel);
    const double ptinv = linearize ? (1.0/els_pt()->at(iel)) : 1.0;

    smat[0][0] += px*px*ptinv;
    smat[0][1] += px*py*ptinv;
    smat[1][1] += py*py*ptinv;
  }

  smat[1][0] = smat[0][1];
  float eig1, eig2;
  if(eigen2x2(smat, eig1, eig2)) return 2.*eig2/(eig1+eig2);
  else return bad_val;
}

float phys_objects::GetSphericity(const vector<int> &good_jets,
				  bool linearize){
  vector<int> empty_vec(0);
  return GetSphericity(good_jets, empty_vec, empty_vec, linearize);
}

float phys_objects::GetDRHighestCSV(const vector<int> &good_jets){
  float csv1=-fltmax, csv2=-fltmax;
  size_t i1=0, i2=0;
  for(size_t i = 0; i < good_jets.size(); ++i){
    const size_t ijet = good_jets.at(i);
    const float csv = jets_btag_secVertexCombined()->at(ijet);
    if(csv>csv1){
      csv2 = csv1;
      csv1 = csv;
      i2 = i1;
      i1 = ijet;
    }else if(csv>csv2){
      csv2 = csv;
      i2 = ijet;
    }
  }

  if(csv2!=-fltmax){
    return dR(jets_eta()->at(i1), jets_eta()->at(i2),
	      jets_phi()->at(i1), jets_phi()->at(i2));
  }else{
    return bad_val;
  }
}

/////////////////////////////////////////////////////////////////////////
////////////////////////////////  Utilities//////////////////////////////
/////////////////////////////////////////////////////////////////////////
bool phys_objects::hasPFMatch(int index, particleId::leptonType type, int &pfIdx) const {
  double deltaRVal = 999.;
  double deltaPT = 999.;
  double leptonEta = 0, leptonPhi = 0, leptonPt = 0;
  if(type == particleId::muon ) {
    leptonEta = mus_eta()->at(index);
    leptonPhi = mus_phi()->at(index);
    leptonPt = mus_pt()->at(index);
  } else if(type == particleId::electron) {
    leptonEta = els_scEta()->at(index);
    leptonPhi = els_phi()->at(index);
    leptonPt = els_pt()->at(index);
  }
  for(unsigned iCand=0; iCand<pfcand_pt()->size(); iCand++) {
    if(pfcand_particleId()->at(iCand)==type) {
      double tempDeltaR = dR(leptonEta, pfcand_eta()->at(iCand), leptonPhi, pfcand_phi()->at(iCand));
      if(tempDeltaR < deltaRVal) {
        deltaRVal = tempDeltaR;
        deltaPT = fabs(leptonPt-pfcand_pt()->at(iCand));
        pfIdx=iCand;
      }
    }
  }

  if(type == particleId::electron) return (deltaPT<10);
  else return (deltaPT<5);
}
