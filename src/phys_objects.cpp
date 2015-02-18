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
#include "TVector3.h"
#include "TLorentzVector.h"

#include "cfa_8.hpp"
#include "cfa_13.hpp"
#include "pdtlund.hpp"
#include "utilities.hpp"

using namespace std;

namespace{
  const float fltmax = numeric_limits<float>::max();
}

float phys_objects::MinJetPt = 40.0;
float phys_objects::MinSignalLeptonPt = 20.0;
float phys_objects::MinVetoLeptonPt = 15.0;
float phys_objects::MinTrackPt = phys_objects::MinVetoLeptonPt;
float phys_objects::bad_val = -999.;

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
    break;
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
    break;
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
    ooeminusoop_cut, reliso_cut, misshits_cut;
  bool req_conv_veto;

  if(Type()==typeid(cfa_8)){
    //See https://twiki.cern.ch/twiki/bin/viewauth/CMS/EgammaCutBasedIdentification#Barrel_Cuts_eta_supercluster_1_4
    //N.B.: vertex fit probability cut for conversion rejection not used (not available in cfA)
    const bool high_pt = els_pt()->at(iel)>20.0;
    switch(threshold){
    default:
    case kVeto:
      deta_cut        = barrel ? 0.007    : 0.01;
      dphi_cut        = barrel ? 0.8      : 0.7;
      ieta_cut        = barrel ? 0.01     : 0.03;
      hovere_cut      = barrel ? 0.15     : fltmax;
      d0_cut          = barrel ? 0.04     : 0.04;
      dz_cut          = barrel ? 0.2      : 0.2;
      ooeminusoop_cut = barrel ? fltmax   : fltmax;
      reliso_cut      = barrel ? 0.15     : 0.15;
      misshits_cut    = barrel ? fltmax   : fltmax;
      req_conv_veto   = barrel ? true     : true;
      break;
    case kLoose:
      deta_cut        = barrel ? 0.007    : 0.009;
      dphi_cut        = barrel ? 0.15     : 0.10;
      ieta_cut        = barrel ? 0.01     : 0.03;
      hovere_cut      = barrel ? 0.12     : 0.10;
      d0_cut          = barrel ? 0.02     : 0.02;
      dz_cut          = barrel ? 0.2      : 0.2;
      ooeminusoop_cut = barrel ? 0.05     : 0.05;
      reliso_cut      = barrel ? 0.15     : (high_pt ? 0.15 : 0.10);
      misshits_cut    = barrel ? 1        : 1;
      req_conv_veto   = barrel ? true     : true;
      break;
    case kMedium:
      deta_cut        = barrel ? 0.004    : 0.007;
      dphi_cut        = barrel ? 0.06     : 0.03;
      ieta_cut        = barrel ? 0.01     : 0.03;
      hovere_cut      = barrel ? 0.12     : 0.1;
      d0_cut          = barrel ? 0.02     : 0.02;
      dz_cut          = barrel ? 0.1      : 0.1;
      ooeminusoop_cut = barrel ? 0.05     : 0.05;
      reliso_cut      = barrel ? 0.15     : (high_pt ? 0.15 : 0.10);
      misshits_cut    = barrel ? 1        : 1;
      req_conv_veto   = barrel ? true     : true;
      break;
    case kTight:
      deta_cut        = barrel ? 0.004    : 0.005;
      dphi_cut        = barrel ? 0.03     : 0.02;
      ieta_cut        = barrel ? 0.01     : 0.03;
      hovere_cut      = barrel ? 0.12     : 0.10;
      d0_cut          = barrel ? 0.02     : 0.02;
      dz_cut          = barrel ? 0.1      : 0.1;
      ooeminusoop_cut = barrel ? 0.05     : 0.05;
      reliso_cut      = barrel ? 0.10     : (high_pt ? 0.10 : 0.07);
      misshits_cut    = barrel ? 1        : 0;
      req_conv_veto   = barrel ? true     : true;
      break;
    }
  }else{
    //See https://twiki.cern.ch/twiki/bin/viewauth/CMS/CutBasedElectronIdentificationRun2#Working_points_for_PHYS14_sample
    switch(threshold){
    default:
    case kVeto:
      ieta_cut        = barrel ? 0.011100 : 0.033987;
      deta_cut        = barrel ? 0.016315 : 0.010671;
      dphi_cut        = barrel ? 0.252044 : 0.245263;
      hovere_cut      = barrel ? 0.345843 : 0.134691;
      reliso_cut      = barrel ? 0.164369 : 0.212604;
      ooeminusoop_cut = barrel ? 0.248070 : 0.157160;
      d0_cut          = barrel ? 0.060279 : 0.273097;
      dz_cut          = barrel ? 0.800538 : 0.885860;
      misshits_cut    = barrel ? 2        : 3;
      req_conv_veto   = barrel ? true     : true;
      break;
    case kLoose:
      ieta_cut        = barrel ? 0.010557 : 0.032602;
      deta_cut        = barrel ? 0.012442 : 0.010654;
      dphi_cut        = barrel ? 0.072624 : 0.145129;
      hovere_cut      = barrel ? 0.121476 : 0.131862;
      reliso_cut      = barrel ? 0.120026 : 0.162914;
      ooeminusoop_cut = barrel ? 0.221803 : 0.142283;
      d0_cut          = barrel ? 0.022664 : 0.097358;
      dz_cut          = barrel ? 0.173670 : 0.198444;
      misshits_cut    = barrel ? 1        : 1;
      req_conv_veto   = barrel ? true     : true;
      break;
    case kMedium:
      ieta_cut        = barrel ? 0.010399 : 0.029524;
      deta_cut        = barrel ? 0.007641 : 0.009285;
      dphi_cut        = barrel ? 0.032643 : 0.042447;
      hovere_cut      = barrel ? 0.060662 : 0.104263;
      reliso_cut      = barrel ? 0.097213 : 0.116708;
      ooeminusoop_cut = barrel ? 0.153897 : 0.137468;
      d0_cut          = barrel ? 0.011811 : 0.051682;
      dz_cut          = barrel ? 0.070775 : 0.180720;
      misshits_cut    = barrel ? 1        : 1;
      req_conv_veto   = barrel ? true     : true;
      break;
    case kTight:
      ieta_cut        = barrel ? 0.010181 : 0.028766;
      deta_cut        = barrel ? 0.006574 : 0.005681;
      dphi_cut        = barrel ? 0.022868 : 0.032046;
      hovere_cut      = barrel ? 0.037553 : 0.081902;
      reliso_cut      = barrel ? 0.074355 : 0.090185;
      ooeminusoop_cut = barrel ? 0.131191 : 0.106055;
      d0_cut          = barrel ? 0.009924 : 0.027261;
      dz_cut          = barrel ? 0.015310 : 0.147154;
      misshits_cut    = barrel ? 1        : 1;
      req_conv_veto   = barrel ? true     : true;
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
    && (!req_conv_veto || els_PATpassConversionVeto()->at(iel))
    && (misshits_cut >= els_expectedMissingInnerHits()->at(iel));
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
/////////////////////////////////  TAUS  //////////////////////////////
/////////////////////////////////////////////////////////////////////////
bool phys_objects::PassPhys14TauID(const int itau, const bool againstEMu, const bool mt_cut) const {
  if (taus_pt()->at(itau) < 20.) return false;
  if (fabs(taus_eta()->at(itau)) > 2.3) //  cout << "pass eta" << endl;
    if (!taus_byDecayModeFinding()->at(itau)) return false;
  if (taus_chargedIsoPtSum()->at(itau) > 1.) return false;
  if (againstEMu && (!taus_againstMuonLoose3()->at(itau) || !taus_againstElectronLooseMVA5()->at(itau))) return false;
  if (mt_cut && GetMT(taus_pt()->at(itau), taus_phi()->at(itau),
                      mets_et()->at(0), mets_phi()->at(0))>100) return false;

  return true;
}

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////  TRACKS  //////////////////////////////
/////////////////////////////////////////////////////////////////////////
bool phys_objects::IsGoodIsoTrack(unsigned itrk, bool mt_cut) const{
  if(itrk>=isotk_pt()->size()) return false;
  return isotk_pt()->at(itrk)>=15.
    && (isotk_iso()->at(itrk)/isotk_pt()->at(itrk) < 0.1)
    && (fabs(isotk_dzpv()->at(itrk))<0.05)
    && (fabs(isotk_eta()->at(itrk))<2.4)
    && ( !mt_cut || GetMT(isotk_pt()->at(itrk), isotk_phi()->at(itrk),
                          mets_et()->at(0), mets_phi()->at(0))<100 ) ;
}

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////  JETS  ////////////////////////////////
/////////////////////////////////////////////////////////////////////////
vector<int> phys_objects::GetJets(const vector<int> &VetoEl, const vector<int> &VetoMu,
                                  double pt_thresh, double eta_thresh) const {
  vector<int> jets;
  vector<bool> jet_is_lepton(jets_pt()->size(), false);

  // Finding jets that contain good leptons
  for(unsigned index = 0; index < VetoEl.size(); index++) {
    int ijet = els_jet_ind()->at(VetoEl[index]);
    if(ijet >= 0) jet_is_lepton[ijet] = true;
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

  return (NEF < 0.99 && NHF < 0.99 && numConst > 1
          && (fabs(jets_eta()->at(ijet))>=2.4 || (CEF < 0.99 && CHF > 0 && chgMult > 0)) );
}

/////////////////////////////////////////////////////////////////////////
////////////////////////////  TRUTH-MATCHING  ///////////////////////////
/////////////////////////////////////////////////////////////////////////
int phys_objects::GetTrueMuon(int index, int &momID, bool &fromW, float &closest_deltaR) const {
  if(index < 0 || index >= static_cast<int>(mus_eta()->size())) return -1;

  closest_deltaR = 9999.; // Old deltaR
  int closest_imc = -1, idLepton = 0;
  float RecPt = mus_pt()->at(index), RecEta = mus_eta()->at(index), RecPhi = mus_phi()->at(index);
  closest_imc = GetTrueParticle(RecPt, RecEta, RecPhi, closest_deltaR, pdtlund::mu_minus);

  closest_deltaR = 9999.;
  if(closest_imc >= 0){
    idLepton = static_cast<int>(mc_doc_id()->at(closest_imc));
    momID = GetMom(mc_doc_id()->at(closest_imc), mc_doc_mother_id()->at(closest_imc),
                   mc_doc_grandmother_id()->at(closest_imc),
                   mc_doc_ggrandmother_id()->at(closest_imc),
                   fromW);
    // Finding mindR with respect to partons from top or W or status 23
    for(unsigned imc=0; imc < mc_doc_id()->size(); imc++){
      if((abs(mc_doc_mother_id()->at(imc)) != 24 && abs(mc_doc_mother_id()->at(imc)) != 6 &&
          mc_doc_status()->at(imc) != 23) || abs(mc_doc_id()->at(imc)) > 5) continue;
      float MCEta = mc_doc_eta()->at(imc); float MCPhi = mc_doc_phi()->at(imc);
      float deltaR = dR(RecEta,MCEta, RecPhi,MCPhi);
      if(deltaR < closest_deltaR) closest_deltaR = deltaR;
    }
  } else {
    closest_imc = GetTrueParticle(RecPt, RecEta, RecPhi, closest_deltaR, 0);
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

int phys_objects::GetTrueElectron(int index, int &momID, bool &fromW, float &closest_deltaR) const {
  if(index < 0 || index >= static_cast<int>(els_eta()->size())) return -1;

  closest_deltaR = 9999.;
  int closest_imc = -1, idLepton = 0;
  float RecPt = els_pt()->at(index), RecEta = els_eta()->at(index), RecPhi = els_phi()->at(index);
  closest_imc = GetTrueParticle(RecPt, RecEta, RecPhi, closest_deltaR, pdtlund::e_minus);

  closest_deltaR = 9999.;
  if(closest_imc >= 0){
    idLepton = static_cast<int>(mc_doc_id()->at(closest_imc));
    momID = GetMom(mc_doc_id()->at(closest_imc), mc_doc_mother_id()->at(closest_imc),
                   mc_doc_grandmother_id()->at(closest_imc),
                   mc_doc_ggrandmother_id()->at(closest_imc),
                   fromW);
    // Finding mindR with respect to partons from top or W or status 23
    for(unsigned imc=0; imc < mc_doc_id()->size(); imc++){
      if((abs(mc_doc_mother_id()->at(imc)) != 24 && abs(mc_doc_mother_id()->at(imc)) != 6 &&
          mc_doc_status()->at(imc) != 23) || abs(mc_doc_id()->at(imc)) > 5) continue;
      float MCEta = mc_doc_eta()->at(imc); float MCPhi = mc_doc_phi()->at(imc);
      float deltaR = dR(RecEta,MCEta, RecPhi,MCPhi);
      if(deltaR < closest_deltaR) closest_deltaR = deltaR;
    }
  } else {
    closest_imc = GetTrueParticle(RecPt, RecEta, RecPhi, closest_deltaR, 0);
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

int phys_objects::GetTrueParticle(float RecPt, float RecEta, float RecPhi,
                                  float &closest_deltaR, int ID) const {
  const float pT_Threshold(0.3), dR_Threshold(0.1);
  int closest_imc = -1;
  float deltaR = 9999.; closest_deltaR = 9999.;
  float MCEta, MCPhi;
  for(unsigned imc=0; imc < mc_doc_id()->size(); imc++){
    if(ID!=0 && abs(mc_doc_id()->at(imc)) != ID) continue;
    MCEta = mc_doc_eta()->at(imc); MCPhi = mc_doc_phi()->at(imc);
    deltaR = dR(RecEta,MCEta, RecPhi,MCPhi);
    if(deltaR > dR_Threshold || abs(mc_doc_pt()->at(imc)-RecPt)/RecPt > pT_Threshold) continue;
    if(deltaR < closest_deltaR && deltaR < dR_Threshold) {
      closest_deltaR = deltaR;
      closest_imc = imc;
    }
  }
  return closest_imc;
}

int phys_objects::GetMom(const float id, const float mom, const float gmom,
                         const float ggmom, bool &fromW){
  const int iid = TMath::Nint(id);
  const int imom = TMath::Nint(mom);
  const int igmom = TMath::Nint(gmom);
  const int iggmom = TMath::Nint(ggmom);

  int ret_mom = 0;
  if(imom != iid)       ret_mom = imom;
  else if(igmom != iid) ret_mom = igmom;
  else                  ret_mom = iggmom;

  // There's various leptons that seem to come from W->udsc->l. We won't call them prompt
  fromW = abs(ret_mom)==24 || (abs(ret_mom)==15 && (abs(igmom)==24 || abs(iggmom)==24));

  return ret_mom;
}

void phys_objects::GetBestLepton(bool &is_muon, size_t &index){
  //Returns index of highest pt signal lepton, if there is one. Falls back to veto leptons if there are no signal leptons and then all leptons if there are no veto leptons.
  is_muon = false;
  index = -1;
  double max_pt = -1.0;
  for(size_t imu = 0; imu < mus_pt()->size(); ++imu){
    if(!IsSignalMuon(imu)) continue;
    if(mus_pt()->at(imu)>max_pt){
      max_pt = mus_pt()->at(imu);
      is_muon = true;
      index = imu;
    }
  }
  for(size_t iel = 0; iel < els_pt()->size(); ++iel){
    if(!IsSignalElectron(iel)) continue;
    if(els_pt()->at(iel)>max_pt){
      max_pt = els_pt()->at(iel);
      is_muon = false;
      index = iel;
    }
  }
  if(max_pt<0.){
    for(size_t imu = 0; imu < mus_pt()->size(); ++imu){
      if(!IsVetoMuon(imu)) continue;
      if(mus_pt()->at(imu)>max_pt){
        max_pt = mus_pt()->at(imu);
        is_muon = true;
        index = imu;
      }
    }
    for(size_t iel = 0; iel < els_pt()->size(); ++iel){
      if(!IsVetoElectron(iel)) continue;
      if(els_pt()->at(iel)>max_pt){
        max_pt = els_pt()->at(iel);
        is_muon = false;
        index = iel;
      }
    }
  }
  if(max_pt<0.){
    for(size_t imu = 0; imu < mus_pt()->size(); ++imu){
      if(mus_pt()->at(imu)>max_pt){
        max_pt = mus_pt()->at(imu);
        is_muon = true;
        index = imu;
      }
    }
    for(size_t iel = 0; iel < els_pt()->size(); ++iel){
      if(els_pt()->at(iel)>max_pt){
        max_pt = els_pt()->at(iel);
        is_muon = false;
        index = iel;
      }
    }
  }
}

vector<mc_particle> phys_objects::GetMCParticles() const{
  vector<mc_particle> parts;
  for(size_t idoc = 0; idoc < mc_doc_id()->size(); ++idoc){
    TLorentzVector v(mc_doc_px()->at(idoc),
                     mc_doc_py()->at(idoc),
                     mc_doc_pz()->at(idoc),
                     mc_doc_energy()->at(idoc));

    parts.push_back(mc_particle(v,
                                mc_doc_charge()->at(idoc),
                                TMath::Nint(mc_doc_id()->at(idoc)),
                                TMath::Nint(mc_doc_mother_id()->at(idoc)),
                                TMath::Nint(mc_doc_grandmother_id()->at(idoc)),
                                TMath::Nint(mc_doc_ggrandmother_id()->at(idoc)),
                                TMath::Nint(mc_doc_status()->at(idoc))));
  }
  size_t to_search = parts.size();

  for(size_t ifinal = 0; ifinal < mc_final_id()->size(); ++ifinal){
    TLorentzVector v;
    v.SetPtEtaPhiE(mc_final_pt()->at(ifinal),
                   mc_final_eta()->at(ifinal),
                   mc_final_phi()->at(ifinal),
                   mc_final_energy()->at(ifinal));
    float charge = mc_final_charge()->at(ifinal);
    int id = TMath::Nint(mc_final_id()->at(ifinal));
    int mom = TMath::Nint(mc_final_mother_id()->at(ifinal));
    int gmom = TMath::Nint(mc_final_grandmother_id()->at(ifinal));
    int ggmom = TMath::Nint(mc_final_ggrandmother_id()->at(ifinal));

    //Comment out next line to avoid appending particles already in mc_doc
    to_search = 0;
    bool skip = false;
    for(size_t i = 0; !skip && i < to_search; ++i){
      mc_particle &part = parts.at(i);
      if(TMath::Nint(3.*charge) == part.charge_
         && id == part.id_
         && mom == part.mom_
         && gmom == part.gmom_
         && ggmom == part.ggmom_
         && (v-part.momentum_).Vect().Mag()<0.01) skip = true;
    }
    if(!skip){
      parts.push_back(mc_particle(v, charge, id, mom, gmom, ggmom, 0));
    }
  }
  return parts;
}

size_t phys_objects::MatchCandToStatus1(size_t icand,
                                        const vector<mc_particle> &parts) const{
  const size_t bad_index = static_cast<size_t>(-1);
  if(icand >= pfcand_charge()->size()) return bad_index;

  if(is_nan(pfcand_pt()->at(icand))
     || is_nan(pfcand_eta()->at(icand))
     || is_nan(pfcand_phi()->at(icand))) return bad_index;

  TVector3 p3cand(pfcand_pt()->at(icand)*cos(pfcand_phi()->at(icand)),
                  pfcand_pt()->at(icand)*sin(pfcand_phi()->at(icand)),
                  pfcand_pt()->at(icand)*sinh(pfcand_eta()->at(icand)));

  float best_score = numeric_limits<float>::max();
  size_t best_part = bad_index;
  for(size_t imc = parts.size()-1; imc < parts.size(); --imc){
    const mc_particle &part = parts.at(imc);
    if(part.status_ != 0) continue;
    if(fabs(3.*part.charge_)<0.5) continue;
    float this_score = (part.momentum_.Vect()-p3cand).Mag2();
    if(this_score < best_score){
      best_score = this_score;
      best_part = imc;
    }
  }

  return best_part;
}

size_t phys_objects::GetMom(size_t index, const vector<mc_particle> &parts){
  const size_t bad_index = static_cast<size_t>(-1);
  if(index >= parts.size()) return bad_index;

  const mc_particle &daughter = parts.at(index);

  size_t low_cousin = index, high_cousin = index;
  bool abort = false;
  for(size_t imc = index - 1 ; !abort && imc < parts.size(); --imc){
    const mc_particle &cousin = parts.at(imc);

    if(cousin.mom_ == daughter.mom_
       && cousin.gmom_ == daughter.gmom_
       && cousin.ggmom_ == daughter.ggmom_){
      low_cousin = imc;
    }else{
      abort = true;
    }
  }

  abort = false;
  for(size_t imc = index + 1 ; !abort && imc < parts.size(); ++imc){
    const mc_particle &cousin = parts.at(imc);

    if(cousin.mom_ == daughter.mom_
       && cousin.gmom_ == daughter.gmom_
       && cousin.ggmom_ == daughter.ggmom_){
      high_cousin = imc;
    }else{
      abort = true;
    }
  }

  float best_score = numeric_limits<float>::max();
  size_t best_parent = bad_index;
  //Loop over possible parents
  for(size_t imc = 0; imc < index; ++imc){
    const mc_particle &mom = parts.at(imc);

    if(!(mom.id_ == daughter.mom_
         && mom.mom_ == daughter.gmom_
         && mom.gmom_ == daughter.ggmom_)) continue;

    //Find parent best momentum matched to sum of consecutive potential daughters
    for(size_t low = low_cousin; low <= index; ++low){
      TVector3 diff = mom.momentum_.Vect();
      for(size_t high = low; high <= high_cousin; ++high){
        const mc_particle &sister = parts.at(high);
        diff -= sister.momentum_.Vect();
        if(high < index) continue;
        float this_score = diff.Mag2();
        if(this_score < best_score){
          best_score = this_score;
          best_parent = imc;
        }
      }
    }
  }

  return best_parent;
}

vector<size_t> phys_objects::GetMoms(const vector<mc_particle> &parts){
  vector<size_t> moms(parts.size());
  for(size_t imc = 0; imc < moms.size(); ++imc){
    moms.at(imc) = GetMom(imc, parts);
  }
  return moms;
}

bool phys_objects::IsBrem(size_t index,
                          const vector<mc_particle> &parts,
                          const vector<size_t> &moms){
  if(index >= moms.size() || moms.at(index) >= moms.size()) return false;
  const mc_particle &part = parts.at(index);
  int id = part.id_;
  if(abs(id) != 11 && abs(id) != 13 && abs(id) != 15) return false;
  int mom = parts.at(moms.at(index)).id_;
  if(abs(mom) != 11 && abs(mom) != 13 && abs(mom) !=15) return false;

  size_t low, high;
  for(low = index; low < moms.size(); --low){
    if(moms.at(low) != moms.at(index)) break;
  }
  ++low;
  for(high = index; high < moms.size(); ++high){
    if(moms.at(high) != moms.at(index)) break;
  }

  unsigned p = 0, n = 0;
  size_t hp = 0, hn = 0;
  float pp = 0, np = 0;
  for(size_t i = low; i < high; ++i){
    float p3 = parts.at(i).momentum_.Vect().Mag2();
    if(parts.at(i).id_ == abs(id)){
      ++p;
      if(p3>pp){
        pp = p3;
        hp = i;
      }
    }else if(parts.at(i).id_ == -abs(id)){
      ++n;
      if(p3>np){
        np = p;
        hn = i;
      }
    }
  }

  if(((p>n && id > 0 && index == hp) || (n>p && id < 0 && index == hn))){
    return false;
  }else{
    return true;
  }
}

bool phys_objects::FromW(size_t index,
                         const vector<mc_particle> &parts,
                         const vector<size_t> &moms){
  if(index >= moms.size()) return false;
  if(IsBrem(index, parts, moms)) return false;

  index = moms.at(index);
  bool found_w = false;
  bool found_bad = false;
  while(index < moms.size()){
    int id = abs(parts.at(index).id_);
    bool bad = (id < 11 || id >16 ) && id != 24;
    if(id == 24){
      if(found_bad){
        return false;
      }else{
        found_w = true;
      }
    }
    if(bad){
      if(found_w){
        found_bad = true;
      }else{
        return false;
      }
    }
    index = moms.at(index);
  }
  return found_w;
}

bool phys_objects::FromTau(size_t index,
                           const vector<mc_particle> &parts,
                           const vector<size_t> &moms){
  if(index >= moms.size()) return false;
  int id = parts.at(index).id_;
  size_t i = moms.at(index);
  while(i < moms.size()){
    if(abs(parts.at(i).id_) == 15 && FromW(i, parts, moms)) return true;
    if(parts.at(i).id_ != id) return false;
    i = moms.at(i);
  }
  return false;
}

void phys_objects::CountLeptons(const vector<mc_particle> &parts,
                                const vector<size_t> &moms,
                                unsigned &nleps,
                                unsigned &ntaus,
                                unsigned &ntauleps){
  nleps = 0;
  ntaus = 0;
  ntauleps = 0;
  set<size_t> used_by_emu, used_by_tau;
  used_by_emu.insert(-1);
  used_by_tau.insert(-1);
  for(size_t i = 0; i < parts.size(); ++i){
    int id = abs(parts.at(i).id_);
    if((id == 11 || id == 13 || id == 15) && FromW(i, parts, moms)){
      size_t parent_w = ParentW(i, parts, moms);
      if(used_by_emu.find(parent_w) == used_by_emu.end()){
        switch(id){
        case 11:
        case 13:
          ++nleps;
          used_by_emu.insert(parent_w);
          if(FromTau(i, parts, moms)){
            ++ ntauleps;
          }
          break;
        case 15:
          if(used_by_tau.find(parent_w) == used_by_tau.end()){
            used_by_tau.insert(parent_w);
            ++ntaus;
          }
          break;
        default:
          break;
        }
      }
    }
  }
}

size_t phys_objects::ParentW(size_t index,
                             const vector<mc_particle> &parts,
                             const vector<size_t> &moms){
  size_t w = static_cast<size_t>(-1);
  while(index < moms.size()){
    if(abs(parts.at(index).id_) == 24) w = index;
    index = moms.at(index);
  }
  return w;
}

size_t phys_objects::ParentTau(size_t index,
                               const vector<mc_particle> &parts,
                               const vector<size_t> &moms){
  size_t tau = static_cast<size_t>(-1);
  while(index < moms.size()){
    if(abs(parts.at(index).id_) == 15 && FromW(index, parts, moms)) tau = index;
    index = moms.at(index);
  }
  return tau;
}

unsigned phys_objects::ParentTauDescendants(size_t index,
                                            const vector<mc_particle> &parts,
                                            const vector<size_t> &moms){
  if(index >= moms.size()) return 0;
  size_t parent_tau = ParentTau(index, parts, moms);
  return NumDescendants(parent_tau, parts, moms, true);
}

bool phys_objects::FromTauLep(size_t index,
                              const vector<mc_particle> &parts,
                              const vector<size_t> &moms){
  if(index >= moms.size()) return false;
  size_t parent_tau = ParentTau(index, parts, moms);
  for(size_t ilep = parts.size()-1; ilep < parts.size(); --ilep){
    const mc_particle &part = parts.at(ilep);
    if((abs(part.id_) == 11 || abs(part.id_) == 13)
       && IsDescendantOf(ilep, parent_tau, moms)
       && NumDescendants(ilep, parts, moms)==0){
      return true;
    }
  }
  return false;
}

unsigned phys_objects::NumChildren(size_t index,
                                   const vector<mc_particle> &parts,
                                   const vector<size_t> &moms,
                                   bool req_chg){
  unsigned num_children = 0;
  for(size_t istart = index + 1; istart < moms.size(); ++istart){
    if(parts.at(istart).status_ == 0
       && (!req_chg || parts.at(istart).charge_!=0)
       && moms.at(istart)==index) ++num_children;
  }
  return num_children;
}

unsigned phys_objects::NumDescendants(size_t index,
                                      const vector<mc_particle> &parts,
                                      const vector<size_t> &moms,
                                      bool req_chg){
  unsigned num_descendants = 0;
  for(size_t istart = index + 1; istart < moms.size(); ++istart){
    if(parts.at(istart).status_ == 0
       && (!req_chg || parts.at(istart).charge_!=0)
       && IsDescendantOf(istart, index, moms)) ++num_descendants;
  }
  return num_descendants;
}

bool phys_objects::IsDescendantOf(size_t descendant, size_t ancestor,
                                  const vector<size_t> &moms){
  if(descendant <= ancestor || descendant >= moms.size()) return false;
  size_t i = moms.at(descendant);
  while(i < moms.size()){
    if(i == ancestor) return true;
    i = moms.at(i);
  }
  return false;
}

/////////////////////////////////////////////////////////////////////////
////////////////////////////  EVENT CLEANING  ///////////////////////////
/////////////////////////////////////////////////////////////////////////
bool phys_objects::PassesPVCut() const{
  if(beamSpot_x()->size()<1 || pv_x()->size()<1) return false;
  const double pv_rho(AddInQuadrature(pv_x()->at(0), pv_y()->at(0)));
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

long double phys_objects::SumDeltaPhi(long double phi_x, long double phi_a, long double phi_b){
  //N.B.: long doubles and checks are necessary! Want to get exact same value of SumDeltaPhi for all jets between the met and lepton or their negatives!
  long double pxa = DeltaPhi(phi_x, phi_a);
  long double pxb = DeltaPhi(phi_x, phi_b);
  long double sdp = pxa + pxb;
  if(Sign(SignedDeltaPhi(phi_x,phi_a))*Sign(SignedDeltaPhi(phi_x,phi_b))<=0){
    long double pab = DeltaPhi(phi_a, phi_b);
    if(sdp>PI){
      return 2.L*PI-pab;
    }else{
      return pab;
    }
  }else{
    return sdp;
  }
}

double phys_objects::GetDeltaPhiMETN(unsigned goodJetI, float otherpt, float othereta, bool useArcsin) const {
  double deltaT = GetDeltaPhiMETN_deltaT(goodJetI, otherpt, othereta);
  double dp = fabs(DeltaPhi(jets_phi()->at(goodJetI), mets_phi()->at(0)));
  double dpN = 0.0;
  if(useArcsin) {
    if( deltaT/mets_et()->at(0) >= 1.0){
      dpN = dp / (PI/2.0);
    }else{
      dpN = dp / asin(deltaT/mets_et()->at(0));
    }
  }else{
    dpN = dp / atan2(deltaT, static_cast<double>(mets_et()->at(0)));
  }
  return dpN;
}

double phys_objects::GetDeltaPhiMETN_deltaT(unsigned goodJetI,
                                            float otherpt, float
                                            othereta) const {
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
  double mdpN=std::numeric_limits<double>::max();
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

double phys_objects::GetMHT(const vector<int> &good_jets, double pt_cut) const {
  double px(0.), py(0.);
  for(size_t ijet = 0; ijet < good_jets.size(); ++ijet){
    const double pt = jets_pt()->at(good_jets.at(ijet));
    if(pt>pt_cut){
      px += jets_px()->at(good_jets.at(ijet));
      py += jets_py()->at(good_jets.at(ijet));
    }
  }
  return AddInQuadrature(px, py);
}

size_t phys_objects::GetNumJets(const vector<int> &good_jets,
                                double pt_cut,
                                double csv_cut) const{
  size_t num_jets = 0;
  for(size_t i = 0; i < good_jets.size(); ++i){
    if(jets_pt()->at(good_jets.at(i)) > pt_cut
       && jets_btag_inc_secVertexCombined()->at(good_jets.at(i)) > csv_cut){
      ++num_jets;
    }
  }
  return num_jets;
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
    if(is_nan(pfcand_pt()->at(iCand))
       || is_nan(pfcand_eta()->at(iCand))
       || is_nan(pfcand_phi()->at(iCand))) continue;
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
