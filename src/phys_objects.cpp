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

#include "TMath.h"

#include "cfa_8.hpp"
#include "cfa_13.hpp"
#include "pdtlund.hpp"
#include "utilities.hpp"

namespace{
  const float MinSignalLeptonPt = 20.;
  const float MinVetoLeptonPt = 15.;
  const float MinTrackPt = MinVetoLeptonPt;
  const float fltmax = std::numeric_limits<float>::max();
}

using namespace std;

phys_objects::phys_objects(const std::string &fileName, const bool is_8TeV):
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

  return deta_cut > fabs(els_dEtaIn()->at(iel))
    && dphi_cut > fabs(els_dPhiIn()->at(iel))
    && ieta_cut > els_full5x5_sigmaIetaIeta()->at(iel)
    && hovere_cut > els_hadOverEm()->at(iel)
    && d0_cut > fabs(d0)
    && dz_cut > fabs(dz)
    && ooeminusoop_cut > fabs((1.0-els_eOverPIn()->at(iel))/els_caloEnergy()->at(iel))
    && (!do_iso || reliso_cut>GetElectronIsolation(iel))
    && ((true || vprob_cut) && (Type()!=typeid(cfa_8) || !els_hasMatchedConversion()->at(iel)))//Skip cut in cfa_13; use alternative in cfa_8
    && (!els_n_inner_layer() || misshits_cut >= els_n_inner_layer()->at(iel));//Missing in phys14
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
      + std::max(0.0,
                 els_pfIsolationR03_sumNeutralHadronEt()->at(iel)
                 +els_pfIsolationR03_sumPhotonEt()->at(iel)
                 -0.5*els_pfIsolationR03_sumPUPt()->at(iel));
    return absiso/els_pt()->at(iel);
  }else{
    throw std::logic_error("Unknown type "
                           +std::string(Type().name())
                           +" in phys_objects::GetElectronIsolation");
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

double phys_objects::getDZ(double vx, double vy, double vz, double px, double py, double pz, int firstGoodVertex) const {
  return vz - pv_z()->at(firstGoodVertex)
    -((vx-pv_x()->at(firstGoodVertex))*px+(vy-pv_y()->at(firstGoodVertex))*py)*pz/(px*px+py*py);
}

/////////////////////////////////////////////////////////////////////////
////////////////////////////////  EVENT VARS/////////////////////////////
/////////////////////////////////////////////////////////////////////////

bool phys_objects::IsMC() const {
  return (SampleName().find("Run201") == string::npos);
}

double phys_objects::getDeltaPhiMETN(unsigned goodJetI, float otherpt, float othereta, bool useArcsin) const {
  double deltaT = getDeltaPhiMETN_deltaT(goodJetI, otherpt, othereta);
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

double phys_objects::getDeltaPhiMETN_deltaT(unsigned goodJetI, float otherpt, float othereta) const {
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

double phys_objects::getMinDeltaPhiMETN(unsigned maxjets, float mainpt, float maineta,
                                        float otherpt, float othereta, bool useArcsin) const {
  double mdpN=std::numeric_limits<double>::max();
  unsigned nGoodJets(0);
  for (unsigned i=0; i<jets_pt()->size(); i++) {
    if (!IsGoodJet(i, mainpt, maineta)) continue;
    nGoodJets++;
    double dpN = getDeltaPhiMETN(i, otherpt, othereta, useArcsin);
    if (dpN>=0&&dpN<mdpN) mdpN=dpN;
    if (nGoodJets>=maxjets) break;
  }
  return mdpN;
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
