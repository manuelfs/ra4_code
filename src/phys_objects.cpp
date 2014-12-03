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
  return IsSignalIdMuon(imu) && GetMuonIsolation(imu)<0.12 && mus_pt()->at(imu)>MinSignalLeptonPt;
}

bool phys_objects::IsVetoMuon(unsigned imu) const{
  if(imu >= mus_pt()->size()) return false;
  return IsVetoIdMuon(imu) && GetMuonIsolation(imu)<0.2 && mus_pt()->at(imu)>MinVetoLeptonPt;
}

bool phys_objects::IsVetoIdMuon(unsigned imu) const {
  if(imu >= mus_pt()->size()) return false;

  bool isPF(false);
  if(Type()==typeid(cfa_8)){
    isPF = mus_isPFMuon()->at(imu);
  }else if(Type()==typeid(cfa_13)){
    isPF = mus_isPF()->at(imu);
  }else{
    return false;
  }

  return ((mus_isGlobalMuon()->at(imu) >0 || mus_isTrackerMuon()->at(imu) >0)
          && isPF
          && fabs(getDZ(mus_tk_vx()->at(imu), mus_tk_vy()->at(imu), mus_tk_vz()->at(imu),
                        mus_tk_px()->at(imu), mus_tk_py()->at(imu), mus_tk_pz()->at(imu), 0)) < 0.5
          && fabs(mus_eta()->at(imu)) <= 2.5);
}

bool phys_objects::IsSignalIdMuon(unsigned imu) const {
  if(imu >= mus_pt()->size()) return false;
  float d0PV = mus_tk_d0dum()->at(imu)-pv_x()->at(0)*sin(mus_tk_phi()->at(imu))+pv_y()->at(0)*cos(mus_tk_phi()->at(imu));

  bool isPF(false);
  if(Type()==typeid(cfa_8)){
    isPF = mus_isPFMuon()->at(imu);
  }else if(Type()==typeid(cfa_13)){
    isPF = mus_isPF()->at(imu);
  }else{
    return false;
  }

  return (mus_isGlobalMuon()->at(imu) > 0
          && isPF
          && mus_id_GlobalMuonPromptTight()->at(imu)> 0
          && mus_tk_LayersWithMeasurement()->at(imu) > 5
          && mus_tk_numvalPixelhits()->at(imu) > 0
          && mus_numberOfMatchedStations()->at(imu) > 1
          && fabs(d0PV) < 0.02
          && fabs(getDZ(mus_tk_vx()->at(imu), mus_tk_vy()->at(imu), mus_tk_vz()->at(imu),
                        mus_tk_px()->at(imu), mus_tk_py()->at(imu), mus_tk_pz()->at(imu), 0)) < 0.5
          && fabs(mus_eta()->at(imu)) <= 2.4);
}

float phys_objects::GetMuonIsolation(unsigned imu) const {
  if(imu >= mus_pt()->size()) return -999;
  double sumEt = mus_pfIsolationR03_sumNeutralHadronEt()->at(imu) + mus_pfIsolationR03_sumPhotonEt()->at(imu)
    - 0.5*mus_pfIsolationR03_sumPUPt()->at(imu);
  if(sumEt<0.0) sumEt=0.0;
  return (mus_pfIsolationR03_sumChargedHadronPt()->at(imu) + sumEt)/mus_pt()->at(imu);
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

  return IsSignalIdElectron(iel)
    && els_pt()->at(iel)>=MinSignalLeptonPt
    && GetElectronIsolation(iel)<0.15;
}

bool phys_objects::IsVetoElectron(unsigned iel) const {
  if(iel >= els_pt()->size()) return false;
  return IsVetoIdElectron(iel)
    && els_pt()->at(iel)>=MinVetoLeptonPt
    && GetElectronIsolation(iel)<0.15;
}

bool phys_objects::IsVetoIdElectron(unsigned iel) const {
  if(iel >= els_pt()->size()) return false;

  float d0PV = els_d0dum()->at(iel)-pv_x()->at(0)*sin(els_tk_phi()->at(iel))+pv_y()->at(0)*cos(els_tk_phi()->at(iel));

  return (fabs(els_scEta()->at(iel)) < 2.5
          && fabs(getDZ(els_vx()->at(iel), els_vy()->at(iel), els_vz()->at(iel), cos(els_tk_phi()->at(iel))*els_tk_pt()->at(iel),
                        sin(els_tk_phi()->at(iel))*els_tk_pt()->at(iel), els_tk_pz()->at(iel), 0)) < 0.2
          && fabs(d0PV) < 0.04
          && ((els_isEB()->at(iel) // Endcap selection
               && fabs(els_dEtaIn()->at(iel)) < 0.007
               && fabs(els_dPhiIn()->at(iel)) < 0.8
               && els_sigmaIEtaIEta()->at(iel) < 0.01
               && els_hadOverEm()->at(iel) < 0.15) ||
              (els_isEE()->at(iel)  // Barrel selection
               && fabs(els_dEtaIn()->at(iel)) < 0.01
               && fabs(els_dPhiIn()->at(iel)) < 0.7
               && els_sigmaIEtaIEta()->at(iel) < 0.03))
          );
}

bool phys_objects::IsSignalIdElectron(unsigned iel) const {
  if(iel >= els_pt()->size()) return false;

  float d0PV = els_d0dum()->at(iel)-pv_x()->at(0)*sin(els_tk_phi()->at(iel))+pv_y()->at(0)*cos(els_tk_phi()->at(iel));

  bool no_conversion(false);
  if(Type()==typeid(cfa_8)){
    no_conversion = !els_hasMatchedConversion()->at(iel);
  }else if(Type()==typeid(cfa_13)){
    no_conversion=true;
  }else{
    return false;
  }

  return (fabs(els_scEta()->at(iel)) < 2.5
          && no_conversion
          && (!els_n_inner_layer() || els_n_inner_layer()->at(iel) <= 1)//Temporary (and ugly) fix for phys14 samples where els_n_inner_layer doesn't exist
          && fabs(getDZ(els_vx()->at(iel), els_vy()->at(iel), els_vz()->at(iel),
                        cos(els_tk_phi()->at(iel))*els_tk_pt()->at(iel),
                        sin(els_tk_phi()->at(iel))*els_tk_pt()->at(iel),
                        els_tk_pz()->at(iel), 0)) < 0.1
          && fabs(1./els_caloEnergy()->at(iel) - els_eOverPIn()->at(iel)/els_caloEnergy()->at(iel)) < 0.05
          && fabs(d0PV) < 0.02
          && ((els_isEB()->at(iel) // Endcap selection
               && fabs(els_dEtaIn()->at(iel)) < 0.004
               && fabs(els_dPhiIn()->at(iel)) < 0.06
               && els_sigmaIEtaIEta()->at(iel) < 0.01
               && els_hadOverEm()->at(iel) < 0.12 ) ||
              (els_isEE()->at(iel)  // Barrel selection
               && fabs(els_dEtaIn()->at(iel)) < 0.007
               && fabs(els_dPhiIn()->at(iel)) < 0.03
               && els_sigmaIEtaIEta()->at(iel) < 0.03
               && els_hadOverEm()->at(iel) < 0.10 ))
          );
}


float phys_objects::GetElectronIsolation(unsigned iel) const {
  if(Type()==typeid(cfa_8)){
    double sumEt = els_PFphotonIsoR03()->at(iel) + els_PFneutralHadronIsoR03()->at(iel)
      - rho_kt6PFJetsForIsolation2011() * GetEffectiveArea(els_scEta()->at(iel), IsMC());
    if(sumEt<0.0) sumEt=0;
    return (els_PFchargedHadronIsoR03()->at(iel) + sumEt)/els_pt()->at(iel);
  }else if(Type()==typeid(cfa_13)){
    float absiso = els_pfIsolationR03_sumChargedHadronPt()->at(iel) + std::max(0.0 , els_pfIsolationR03_sumNeutralHadronEt()->at(iel) + els_pfIsolationR03_sumPhotonEt()->at(iel) - 0.5 * els_pfIsolationR03_sumPUPt()->at(iel) );
    return absiso/els_pt()->at(iel);
  }else{
    throw std::logic_error("Unknown type "+std::string(Type().name())+" in phys_objects::GetElectronIsolation");
    return 0.0;
  }
}

float phys_objects::GetEffectiveArea(float SCEta, bool isMC) const {
  float EffectiveArea;
  if(isMC) {
    if (fabs(SCEta) >= 0.0 && fabs(SCEta) < 1.0 ) EffectiveArea = 0.110;
    if (fabs(SCEta) >= 1.0 && fabs(SCEta) < 1.479 ) EffectiveArea = 0.130;
    if (fabs(SCEta) >= 1.479 && fabs(SCEta) < 2.0 ) EffectiveArea = 0.089;
    if (fabs(SCEta) >= 2.0 && fabs(SCEta) < 2.2 ) EffectiveArea = 0.130;
    if (fabs(SCEta) >= 2.2 && fabs(SCEta) < 2.3 ) EffectiveArea = 0.150;
    if (fabs(SCEta) >= 2.3 && fabs(SCEta) < 2.4 ) EffectiveArea = 0.160;
    if (fabs(SCEta) >= 2.4) EffectiveArea = 0.190;
  }
  else {
    //kEleGammaAndNeutralHadronIso03 from 2011 data
    //obtained from http://cmssw.cvs.cern.ch/cgi-bin/cmssw.cgi/UserCode/EGamma/EGammaAnalysisTools/interface/ElectronEffectiveArea.h?revision=1.3&view=markup
    if (fabs(SCEta) >= 0.0 && fabs(SCEta) < 1.0 ) EffectiveArea = 0.100;
    if (fabs(SCEta) >= 1.0 && fabs(SCEta) < 1.479 ) EffectiveArea = 0.120;
    if (fabs(SCEta) >= 1.479 && fabs(SCEta) < 2.0 ) EffectiveArea = 0.085;
    if (fabs(SCEta) >= 2.0 && fabs(SCEta) < 2.2 ) EffectiveArea = 0.110;
    if (fabs(SCEta) >= 2.2 && fabs(SCEta) < 2.3 ) EffectiveArea = 0.120;
    if (fabs(SCEta) >= 2.3 && fabs(SCEta) < 2.4 ) EffectiveArea = 0.120;
    if (fabs(SCEta) >= 2.4) EffectiveArea = 0.130;
  }
  return EffectiveArea;
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
                                  const double pt_thresh, const double eta_thresh) const {
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

bool phys_objects::IsGoodJet(const unsigned ijet, const double ptThresh, const double etaThresh) const{
  if(jets_pt()->size()<=ijet) return false;
  if(!IsBasicJet(ijet)) return false;
  if(jets_pt()->at(ijet)<ptThresh || fabs(jets_eta()->at(ijet))>etaThresh) return false;
  return true;
}

bool phys_objects::IsBasicJet(const unsigned ijet) const{
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
