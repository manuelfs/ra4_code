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

#include "FactorizedJetCorrector.hpp"
#include "JetCorrector.hpp"

#include "cfa_8.hpp"
#include "cfa_13.hpp"
#include "pdtlund.hpp"
#include "utilities.hpp"


using namespace std;

namespace{
  const float fltmax = numeric_limits<float>::max();
}

float phys_objects::MinJetPt = 30.0;
float phys_objects::MinRA2bJetPt = 30.0;
float phys_objects::MinSignalLeptonPt = 20.0;
float phys_objects::MinVetoLeptonPt = 10.0;
float phys_objects::MinTrackPt = phys_objects::MinVetoLeptonPt;
float phys_objects::bad_val = -999.;

// const std::vector<std::vector<int> > VRunLumiPrompt(MakeVRunLumi("Golden"));
// const std::vector<std::vector<int> > VRunLumi24Aug(MakeVRunLumi("24Aug"));
// const std::vector<std::vector<int> > VRunLumi13Jul(MakeVRunLumi("13Jul"));
const std::vector<std::vector<int> > VRunLumi2015golden(MakeVRunLumi("2015golden"));
const std::vector<std::vector<int> > VRunLumi2015dcs(MakeVRunLumi("2015dcs"));



phys_objects::phys_objects(const std::string &fileName, const bool is_8TeV):
  cfa(fileName, is_8TeV),
  jet_corrector_(NULL),
  jets_corr_p4_(0),
  set_jets_(false),
  met_corr_(bad_val),
  met_phi_corr_(bad_val){
  vector<string> jec_files;
  jec_files.push_back("txt/jec/phys14_v4_mc/PHYS14_V4_MC_L1FastJet_AK4PFchs.txt");
  jec_files.push_back("txt/jec/phys14_v4_mc/PHYS14_V4_MC_L2Relative_AK4PFchs.txt");
  jec_files.push_back("txt/jec/phys14_v4_mc/PHYS14_V4_MC_L3Absolute_AK4PFchs.txt");
  jet_corrector_ = makeJetCorrector(jec_files);

}

phys_objects::~phys_objects(){
  if(jet_corrector_){
    delete jet_corrector_;
    jet_corrector_ = NULL;
  }
}

void phys_objects::GetEntry(const long entry){
  jets_corr_p4_.clear();
  set_jets_ = false;
  cfa::GetEntry(entry);
}


////////// Triggers /////////////
bool phys_objects::GetTriggerInfo(vector<TString> &trig_names, vector<bool> &trig_dec, 
				  vector<float> &trig_prescale){
  bool want_event(yes_trig.size()==0); // If yes_trig is not set up, we keep every event
  bool duplicate(false);
  TString trigname;
  trig_dec.resize(trig_names.size(), false);
  trig_prescale.resize(trig_names.size(), 1.);
  for(int unsigned itrig=0;itrig<trigger_decision()->size();itrig++){
    trigname = trigger_name()->at(itrig);
    bool trigdec = trigger_decision()->at(itrig);
    for(unsigned itn(0); itn < trig_names.size(); itn++){
      if(trigname.Contains(trig_names[itn])){
	trig_dec[itn] = trigdec; 
	trig_prescale[itn] = trigger_prescalevalue()->at(itrig);
      }
    } // Loop over trigger names

    // Checking if the event passes at least one yes_trig and none of no_trig
    for(unsigned ind(0); ind<yes_trig.size() && !want_event && !duplicate; ind++)
      if(trigname.Contains(yes_trig[ind])) want_event = (want_event || trigdec);
    for(unsigned ind(0); ind<no_trig.size() && !duplicate; ind++)
      if(trigname.Contains(no_trig[ind])) duplicate = (duplicate || trigdec);    
  } // Loop over cfA triggers

  return want_event&&!duplicate;
}

bool phys_objects::PassesJSONCut(TString type){
  string sampleName = SampleName();

  if(isData()){
    if(type=="golden") return inJSON(VRunLumi2015golden, run(), lumiblock());
    if(type=="dcs") return inJSON(VRunLumi2015dcs, run(), lumiblock());
  }
  return true;
}



////////////////////////////////////



/////////////////////////////////////////////////////////////////////////
////////////////////////////////  MUONS  ////////////////////////////////
/////////////////////////////////////////////////////////////////////////
vector<int> phys_objects::GetMuons(bool doSignal, bool mini) const {
  vector<int> muons;
  for(unsigned index=0; index<mus_pt()->size(); index++)
    if(doSignal){
      if(IsSignalMuon(index, mini)) muons.push_back(index);
    }else{
      if(IsVetoMuon(index, mini)) muons.push_back(index);
    }
  return muons;
}

bool phys_objects::IsSignalMuon(unsigned imu, bool mini) const {
  if(imu >= mus_pt()->size()) return false;
  return IsSignalIdMuon(imu)
    && 0.2>GetMuonIsolation(imu, mini)
    && mus_pt()->at(imu)>MinSignalLeptonPt;
}

bool phys_objects::IsVetoMuon(unsigned imu, bool mini) const{
  if(imu >= mus_pt()->size()) return false;
  return IsVetoIdMuon(imu)
    && 0.2>GetMuonIsolation(imu, mini)
    && mus_pt()->at(imu)>MinVetoLeptonPt;
}

bool phys_objects::IsSignalIdMuon(unsigned imu) const {
  if(imu >= mus_pt()->size()) return false;
  int version = GetVersion();
  bool dec = false;
  if(version<80) dec = IsIdMuon(imu, kTight);
  else dec =  IsIdMuon(imu, kMedium);
  return dec && fabs(mus_eta()->at(imu))<2.4;
}

bool phys_objects::IsVetoIdMuon(unsigned imu) const {
  if(imu >= mus_pt()->size()) return false;
  int version = GetVersion();
  bool dec = false;
  if(version<80) dec = IsIdMuon(imu, kTight); //Intentionally vetoing on "tight" muons!
  else dec = IsIdMuon(imu, kLoose);
  return dec && fabs(mus_eta()->at(imu))<2.4;
}

bool phys_objects::IsIdMuon(unsigned imu, CutLevel threshold) const{
  if(imu>=mus_pt()->size()) return false;

  bool pf_cut, global_cut, global_or_tracker_cut, globalprompttight_cut;
  double chisq_cut, hits_cut, stations_cut, dxy_cut, dz_cut, pixel_cut, layers_cut;
  const double d0 = mus_tk_d0dum()->at(imu)
    -pv_x()->at(0)*sin(mus_tk_phi()->at(imu))
    +pv_y()->at(0)*cos(mus_tk_phi()->at(imu));
  const double dz = mus_tk_vz()->at(imu)-pv_z()->at(0);

  //See https://twiki.cern.ch/twiki/bin/view/CMSPublic/SWGuideMuonId#Tight_Muon
  switch(threshold){
  default:
  case kVeto:
  case kLoose:
    if(GetVersion()>=80) return mus_isLooseMuon()->at(imu);
    else {
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
    }
    break;
    
  case kMedium:
    return mus_isMediumMuon()->at(imu) && fabs(d0)<=0.2 && fabs(dz)<=0.5;
    break;

    
  case kTight:
    if(GetVersion()>=80) return mus_isTightMuon()->at(imu);
    else {
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
    break;
  }

  bool isPF = true;
  if(Type()==typeid(cfa_8)){
    isPF = mus_isPFMuon()->at(imu);
  }else if(Type()==typeid(cfa_13)){
    isPF = mus_isPF()->at(imu);
  }
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

float phys_objects::GetMuonIsolation(unsigned imu, bool mini) const {
  if(imu >= mus_pt()->size()) return -999;
  if(!mini){
    double sumEt = mus_pfIsolationR04_sumNeutralHadronEt()->at(imu)
      + mus_pfIsolationR04_sumPhotonEt()->at(imu)
      - 0.5*mus_pfIsolationR04_sumPUPt()->at(imu);
    if(sumEt<0.0) sumEt=0.0;
    return (mus_pfIsolationR04_sumChargedHadronPt()->at(imu) + sumEt)/mus_pt()->at(imu);
  }else{
    return mus_miniso()->at(imu);
  }
}

/////////////////////////////////////////////////////////////////////////
//////////////////////////////  ELECTRONS  //////////////////////////////
/////////////////////////////////////////////////////////////////////////
vector<int> phys_objects::GetElectrons(bool doSignal, bool mini) const {
  vector<int> electrons;
  for(unsigned index=0; index<els_pt()->size(); index++)
    if(doSignal){
      if(IsSignalElectron(index, mini)) electrons.push_back(index);
    }else{
      if(IsVetoElectron(index, mini)) electrons.push_back(index);
    }
  return electrons;
}

bool phys_objects::IsSignalElectron(unsigned iel, bool mini) const {
  if(iel >= els_pt()->size()) return false;
  double iso_cut(0.1);
  if (!mini) {
    //can't get this from IsSignalIdElectron since we use kMedium Id but kVeto iso
    bool barrel = false; 
    if(els_isEB()->at(iel) && !els_isEE()->at(iel)){
      barrel = true;
    }else if(els_isEE()->at(iel) && !els_isEB()->at(iel)){
      barrel = false;
    }else{
      return false;
    }
    iso_cut = barrel ? 0.164369 : 0.212604; 
  }
  return IsSignalIdElectron(iel, false)
    && iso_cut>GetElectronIsolation(iel, mini)
    && els_pt()->at(iel)>=MinSignalLeptonPt;
}

bool phys_objects::IsVetoElectron(unsigned iel, bool mini) const {
  if(iel >= els_pt()->size()) return false;
  return IsVetoIdElectron(iel, false)
    && 0.1>GetElectronIsolation(iel, mini)
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
  if(fabs(els_scEta()->at(iel))>2.5) return false;
  if(els_isEB()->at(iel) && !els_isEE()->at(iel)){
    barrel = true;
  }else if(els_isEE()->at(iel) && !els_isEB()->at(iel)){
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

    //https://twiki.cern.ch/twiki/bin/viewauth/CMS/CutBasedElectronIdentificationRun2#Working_points_for_PHYS14_sample
    // Values from May 7th
    if(barrel){
      deta_cut        = chooseVal(threshold, 0.013625	, 0.009277	, 0.008925	, 0.006046);
      dphi_cut        = chooseVal(threshold, 0.230374	, 0.094739	, 0.035973	, 0.028092);
      ieta_cut        = chooseVal(threshold, 0.011586	, 0.010331	, 0.009996	, 0.009947);
      hovere_cut      = chooseVal(threshold, 0.181130	, 0.093068	, 0.050537	, 0.045772);
      d0_cut          = chooseVal(threshold, 0.094095	, 0.035904	, 0.012235	, 0.008790);
      dz_cut          = chooseVal(threshold, 0.713070	, 0.075496	, 0.042020	, 0.021226);
      ooeminusoop_cut = chooseVal(threshold, 0.295751	, 0.189968	, 0.091942	, 0.020118);
      reliso_cut      = chooseVal(threshold, 0.158721	, 0.130136	, 0.107587	, 0.069537);
      misshits_cut    = chooseVal(threshold,  2		,  1		,  1		,  1	  );
      req_conv_veto   = chooseVal(threshold,  true	,  true		,  true		,  true	  );

    } else {
      deta_cut        = chooseVal(threshold,  0.011932	,  0.009833	,  0.007429	, 0.007057);
      dphi_cut        = chooseVal(threshold,  0.255450	,  0.149934	,  0.067879	, 0.030159);
      ieta_cut        = chooseVal(threshold,  0.031849	,  0.031838	,  0.030135	, 0.028237);
      hovere_cut      = chooseVal(threshold,  0.223870	,  0.115754	,  0.086782	, 0.067778);
      d0_cut          = chooseVal(threshold,  0.342293	,  0.099266	,  0.036719	, 0.027984);
      dz_cut          = chooseVal(threshold,  0.953461	,  0.197897	,  0.138142	, 0.133431);
      ooeminusoop_cut = chooseVal(threshold,  0.155501	,  0.140662	,  0.100683	, 0.098919);
      reliso_cut      = chooseVal(threshold,  0.177032	,  0.163368	,  0.113254	, 0.078265);
      misshits_cut    = chooseVal(threshold,  3		,  1		,  1		,  1	  );
      req_conv_veto   = chooseVal(threshold,  true	,  true		,  true		,  true	  );
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

float phys_objects::GetElectronIsolation(unsigned iel, bool mini) const {
  if(!mini){
    if(Type()==typeid(cfa_8)){
      double sumEt = els_PFphotonIsoR03()->at(iel)
        + els_PFneutralHadronIsoR03()->at(iel)
        - rho_kt6PFJetsForIsolation2011() * GetEffectiveArea(els_scEta()->at(iel), !isData());
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
  }else{
    return els_miniso()->at(iel);
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
                      met_corr(), met_phi_corr())>100) return false;

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
                          met_corr(), met_phi_corr())<100 ) ;
}

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////  MET  ////////////////////////////////
/////////////////////////////////////////////////////////////////////////
float phys_objects::met_corr() const{
  CorrectJets();
  return met_corr_;
}

float phys_objects::met_phi_corr() const{
  CorrectJets();
  return met_phi_corr_;
}

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////  JETS  ////////////////////////////////
/////////////////////////////////////////////////////////////////////////
const vector<TLorentzVector> & phys_objects::jets_corr_p4() const{
  CorrectJets();
  return jets_corr_p4_;
}

vector<TLorentzVector> & phys_objects::jets_corr_p4(){
  CorrectJets();
  return jets_corr_p4_;
}

void phys_objects::CorrectJets() const{
  if(set_jets_) return;

  bool do_metcorr(false); // For now we don't correct MET
  //bool do_metcorr(true); 
  jets_corr_p4_.clear();
  int version = GetVersion();
  if(version<78 || version==79) do_metcorr = false; // This is to avoid rounding errors
  TLorentzVector corr_p4, uncorr_p4, miniaod_p4;
  float METx = mets_et()*cos(mets_phi());
  float METy = mets_et()*sin(mets_phi());
  for(size_t ijet = 0; ijet < jets_pt()->size(); ++ijet){
    miniaod_p4.SetPtEtaPhiM(jets_pt()->at(ijet), jets_eta()->at(ijet),
			    jets_phi()->at(ijet), jets_mass()->at(ijet));
    uncorr_p4 = miniaod_p4*jets_corrFactorRaw()->at(ijet);
    corr_p4 = miniaod_p4;
    if(version==78){ //EXCLUDE 79
      corr_p4 *= jets_corrFactorRaw()->at(ijet); // First, uncorrect it

      jet_corrector_->setJetEta(corr_p4.Eta());
      jet_corrector_->setJetPt(corr_p4.Pt());
      jet_corrector_->setJetA(jets_area()->at(ijet));
      jet_corrector_->setRho(fixedGridRhoFastjetAll());

      corr_p4 *= jet_corrector_->getCorrection();
      if(uncorr_p4.Pt() > 10 && do_metcorr) {
	METx += miniaod_p4.Px();
	METy += miniaod_p4.Py();
	METx -= corr_p4.Px();
	METy -= corr_p4.Py();
      }
    } // if version >= 78
    jets_corr_p4_.push_back(corr_p4);
  } // Loop over jets

  if(do_metcorr){
    float correctedMET = sqrt(METx*METx + METy*METy);
    float correctedMETPhi = atan2(METy,METx);
    met_corr_ = correctedMET;
    met_phi_corr_ = TVector2::Phi_mpi_pi(correctedMETPhi); 
  } else {
    met_corr_ = mets_et();
    met_phi_corr_ = mets_phi(); 
  }
  set_jets_ = true;
}

vector<int> phys_objects::GetJets(const vector<int> &VetoEl, const vector<int> &VetoMu,
                                  double pt_thresh, double eta_thresh) const {
  vector<int> jets;
  vector<bool> jet_is_lepton(jets_corr_p4().size(), false);
  map<size_t,vector<size_t> > mu_matches, el_matches;
  GetMatchedLeptons(VetoMu, VetoEl, mu_matches, el_matches);

  for(size_t ijet = 0; ijet < jets_corr_p4().size(); ++ijet){
    if(mu_matches.find(ijet) != mu_matches.end()
       || el_matches.find(ijet) != el_matches.end()){
      jet_is_lepton[ijet] = true;
    }
  }

  // Tau/photon cleaning, and calculation of HT
  for(unsigned ijet = 0; ijet<jets_corr_p4().size(); ijet++) {
    if(!IsGoodJet(ijet, pt_thresh, eta_thresh) || jet_is_lepton[ijet]) continue;

     jets.push_back(ijet);
  } // Loop over jets

  return jets;
}

bool phys_objects::AllGoodJets(const vector<int> &VetoEl, const vector<int> &VetoMu,
                                  double pt_thresh, double eta_thresh) const {
  vector<bool> jet_is_lepton(jets_corr_p4().size(), false);
  map<size_t,vector<size_t> > mu_matches, el_matches;
  GetMatchedLeptons(VetoMu, VetoEl, mu_matches, el_matches);

  for(size_t ijet = 0; ijet < jets_corr_p4().size(); ++ijet){
    if(mu_matches.find(ijet) != mu_matches.end()
       || el_matches.find(ijet) != el_matches.end()){
      jet_is_lepton[ijet] = true;
    }
  }

  bool bad_jets(true);
  for(unsigned ijet = 0; ijet<jets_corr_p4().size(); ijet++) {
    if(!jet_is_lepton[ijet] && jets_corr_p4().at(ijet).Pt()>pt_thresh &&
       fabs(jets_corr_p4().at(ijet).Eta())<eta_thresh && !IsBasicJet(ijet)) {
      bad_jets = false;
      break;
    }
  } // Loop over jets
  return bad_jets;
}

void phys_objects::GetMatchedLeptons(const vector<int> &veto_mu,
                                     const vector<int> &veto_el,
                                     map<size_t,vector<size_t> > &mu_matches,
                                     map<size_t,vector<size_t> > &el_matches) const{
  mu_matches.clear();
  el_matches.clear();
  //Match muons to jets
  for(size_t ivmu = 0; ivmu < veto_mu.size(); ++ivmu){
    int imu = veto_mu.at(ivmu);
    size_t imatch = 0;
    float mindr = numeric_limits<float>::max();
    for(size_t ijet = 0; mindr > 0. && ijet < jets_corr_p4().size(); ++ijet){
      if(mus_isPF()->at(imu) && mus_jet_ind()->at(imu) == static_cast<int>(ijet)){
        imatch = ijet;
        mindr = 0.;
      }else{
        double dr = dR(jets_corr_p4().at(ijet).Eta(), mus_eta()->at(imu),
                       jets_corr_p4().at(ijet).Phi(), mus_phi()->at(imu));
        if(dr<mindr){
          mindr=dr;
          imatch = ijet;
        }
      }
    }
    if(mindr < 0.4) mu_matches[imatch].push_back(imu);
    else cout<<"mus "<<imu<<" not matched. p = ("<<mus_pt()->at(imu)<<","<<mus_eta()->at(imu)
	     <<","<<mus_phi()->at(imu)<<")"<<endl;
  }

  //Match electrons to jets
  for(size_t ivel = 0; ivel < veto_el.size(); ++ivel){
    int iel = veto_el.at(ivel);
    size_t imatch = 0;
    float mindr = numeric_limits<float>::max();
    for(size_t ijet = 0; mindr > 0. && ijet < jets_corr_p4().size(); ++ijet){
      if(els_isPF()->at(iel) && els_jet_ind()->at(iel) == static_cast<int>(ijet)){
        imatch = ijet;
        mindr = 0.;
      }else{
        double dr = dR(jets_corr_p4().at(ijet).Eta(), els_eta()->at(iel),
                       jets_corr_p4().at(ijet).Phi(), els_phi()->at(iel));
        if(dr<mindr){
          mindr=dr;
          imatch = ijet;
        }
      }
    }
    if(mindr < 0.4) el_matches[imatch].push_back(iel);
    else cout<<"els "<<iel<<" not matched. p = ("<<els_pt()->at(iel)<<","<<els_eta()->at(iel)
	     <<","<<els_phi()->at(iel)<<")"<<endl;
  }
}

vector<Jet> phys_objects::GetSubtractedJets(const vector<int> &veto_el, const vector<int> &veto_mu,
                                            double pt_thresh, double eta_thresh) const{
  vector<Jet> jets(0);
  map<size_t,vector<size_t> > mu_matches, el_matches;

  GetMatchedLeptons(veto_mu, veto_el, mu_matches, el_matches);

  //Compute subtracted jets
  for(size_t ijet = 0; ijet < jets_corr_p4().size(); ++ijet){
    if(!IsGoodJet(ijet, 0., 999.)) continue;
    TLorentzVector p4jet(jets_corr_p4().at(ijet)), p4sub;

    int subtracted = 0;
    float mindr = numeric_limits<float>::max();
    //Remove muons
    if(mu_matches.find(ijet) != mu_matches.end()){
      const vector<size_t> &matches = mu_matches.at(ijet);
      for(size_t imatch = 0; imatch < matches.size(); ++imatch){
        size_t imu = matches.at(imatch);
        TLorentzVector p4mu;
        p4mu.SetPtEtaPhiE(mus_pt()->at(imu), mus_eta()->at(imu),
                          mus_phi()->at(imu), mus_energy()->at(imu));
        float dr = p4mu.DeltaR(p4jet);
        if(dr<mindr) mindr = dr;
        p4sub += p4mu;
        ++subtracted;
      }
    }

    //Remove electrons
    if(el_matches.find(ijet) != el_matches.end()){
      const vector<size_t> &matches = el_matches.at(ijet);
      for(size_t imatch = 0; imatch < matches.size(); ++imatch){
        size_t iel = matches.at(imatch);
        TLorentzVector p4el;
        p4el.SetPtEtaPhiE(els_pt()->at(iel), els_eta()->at(iel),
                          els_phi()->at(iel), els_energy()->at(iel));
        float dr = p4el.DeltaR(p4jet);
        if(dr<mindr) mindr = dr;
        p4sub += p4el;
        ++subtracted;
      }
    }
    p4jet -= p4sub;

    //Apply eta and pt cut to subtracted momentum
    if(fabs(p4jet.Eta())>eta_thresh || p4jet.Pt()<pt_thresh) continue;

    //Record subtracted jets passing quality, eta, and pt cuts
    jets.push_back(Jet());
    jets.back().p4 = p4jet;
    jets.back().csv = jets_btag_inc_secVertexCombined()->at(ijet);
    jets.back().nleps = subtracted;
    jets.back().id = TMath::Nint(jets_parton_Id()->at(ijet));
    jets.back().p4sub = p4sub;
    jets.back().mindr = mindr;
  }

  return jets;
}

bool phys_objects::IsGoodJet(unsigned ijet, double ptThresh, double etaThresh) const{
  if(jets_corr_p4().size()<=ijet) return false;
  if(!IsBasicJet(ijet)) return false;
  if(jets_corr_p4().at(ijet).Pt()<ptThresh || fabs(jets_corr_p4().at(ijet).Eta())>etaThresh) return false;
  return true;
}

bool phys_objects::IsBasicJet(unsigned ijet) const{
  //NOTE: This may need to be updated to match:
  //https://twiki.cern.ch/twiki/bin/view/CMS/JetID
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
          && (fabs(jets_corr_p4().at(ijet).Eta())>=2.4 || (CEF < 0.99 && CHF > 0 && chgMult > 0)) );
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

// size_t phys_objects::MatchCandToStatus1(size_t icand,
//                                         const vector<mc_particle> &parts) const{
//   const size_t bad_index = static_cast<size_t>(-1);
//   if(icand >= pfcand_charge()->size()) return bad_index;

//   if(is_nan(pfcand_pt()->at(icand))
//      || is_nan(pfcand_eta()->at(icand))
//      || is_nan(pfcand_phi()->at(icand))) return bad_index;

//   TVector3 p3cand(pfcand_pt()->at(icand)*cos(pfcand_phi()->at(icand)),
//                   pfcand_pt()->at(icand)*sin(pfcand_phi()->at(icand)),
//                   pfcand_pt()->at(icand)*sinh(pfcand_eta()->at(icand)));

//   float best_score = numeric_limits<float>::max();
//   size_t best_part = bad_index;
//   for(size_t imc = parts.size()-1; imc < parts.size(); --imc){
//     const mc_particle &part = parts.at(imc);
//     if(part.status_ != 0) continue;
//     if(fabs(3.*part.charge_)<0.5) continue;
//     float this_score = (part.momentum_.Vect()-p3cand).Mag2();
//     if(this_score < best_score){
//       best_score = this_score;
//       best_part = imc;
//     }
//   }

//   return best_part;
// }

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

bool phys_objects::FromStatus23(size_t index,
                                const vector<mc_particle> &parts,
                                const vector<size_t> &moms){
  if(index >= moms.size()) return false;

  bool found_23 = false;
  while(index < moms.size() && !found_23){
    if(parts.at(index).status_ == 23){
      found_23 = true;
    }
    index = moms.at(index);
  }
  return found_23;
}

bool phys_objects::FromTop(size_t index,
                           const vector<mc_particle> &parts,
                           const vector<size_t> &moms){
  if(index >= moms.size()) return false;

  bool found_top = false;
  while(index < moms.size() && !found_top){
    if(abs(parts.at(index).id_) == 6){
      found_top = true;
    }
    index = moms.at(index);
  }
  return found_top;
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

bool phys_objects::isData() const {
  return (SampleName().find("Run201") != string::npos);
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
  double dp = fabs(DeltaPhi(jets_corr_p4().at(goodJetI).Phi(), met_phi_corr()));
  double dpN = 0.0;
  if(useArcsin) {
    if( deltaT/met_corr() >= 1.0){
      dpN = dp / (PI/2.0);
    }else{
      dpN = dp / asin(deltaT/met_corr());
    }
  }else{
    dpN = dp / atan2(deltaT, static_cast<double>(met_corr()));
  }
  return dpN;
}

double phys_objects::GetDeltaPhiMETN_deltaT(unsigned goodJetI,
                                            float otherpt, float
                                            othereta) const {
  if(goodJetI>=jets_corr_p4().size()) return -99.;

  double sum = 0;
  for (unsigned i=0; i< jets_corr_p4().size(); i++) {
    if(i==goodJetI) continue;
    if(IsGoodJet(i, otherpt, othereta)){
      double jetres = 0.1;
      sum += pow( jetres*(jets_corr_p4().at(goodJetI).Px()*jets_corr_p4().at(i).Py() - jets_corr_p4().at(goodJetI).Py()*jets_corr_p4().at(i).Px()), 2);
    }
  }
  double deltaT = sqrt(sum)/jets_corr_p4().at(goodJetI).Pt();
  return deltaT;
}

double phys_objects::GetMinDeltaPhiMETN(unsigned maxjets, float mainpt, float maineta,
                                        float otherpt, float othereta, bool useArcsin) const {
  double mdpN=std::numeric_limits<double>::max();
  unsigned nGoodJets(0);
  for (unsigned i=0; i<jets_corr_p4().size(); i++) {
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
    const double pt = jets_corr_p4().at(good_jets.at(i)).Pt();
    if(pt>pt_cut) ht += pt;
  }
  return ht;
}

double phys_objects::GetMHT(const vector<int> &good_jets, double pt_cut) const {
  double px(0.), py(0.);
  for(size_t ijet = 0; ijet < good_jets.size(); ++ijet){
    const double pt = jets_corr_p4().at(good_jets.at(ijet)).Pt();
    if(pt>pt_cut){
      px += jets_corr_p4().at(good_jets.at(ijet)).Px();
      py += jets_corr_p4().at(good_jets.at(ijet)).Py();
    }
  }
  return AddInQuadrature(px, py);
}

size_t phys_objects::GetNumJets(const vector<int> &good_jets,
                                double pt_cut,
                                double csv_cut) const{
  size_t num_jets = 0;
  for(size_t i = 0; i < good_jets.size(); ++i){
    if(jets_corr_p4().at(good_jets.at(i)).Pt() > pt_cut
       && jets_btag_inc_secVertexCombined()->at(good_jets.at(i)) > csv_cut){
      ++num_jets;
    }
  }
  return num_jets;
}

double phys_objects::GetSphericity(const std::vector<TLorentzVector> &vs){
  double sumpt = 0.;
  double xx = 0., xy=0., yy =0.;
  for(size_t iv = 0; iv < vs.size(); ++iv){
    const TLorentzVector &v = vs.at(iv);
    sumpt += v.Pt();
    double inv_pt = 1./v.Pt();
    xx += v.Px()*v.Px()*inv_pt;
    xy += v.Px()*v.Py()*inv_pt;
    yy += v.Py()*v.Py()*inv_pt;
  }
  xx/=sumpt;
  xy/=sumpt;
  yy/=sumpt;
  return (xx+yy!=0.)?(xx+yy-AddInQuadrature(xx-yy,2.*xy))/(xx+yy):-1.;
}

/////////////////////////////////////////////////////////////////////////
////////////////////////////////  Utilities//////////////////////////////
/////////////////////////////////////////////////////////////////////////
// bool phys_objects::hasPFMatch(int index, particleId::leptonType type, int &pfIdx) const {
//   double deltaRVal = 999.;
//   double deltaPT = 999.;
//   double leptonEta = 0, leptonPhi = 0, leptonPt = 0;
//   int pdgid = 0;
//   if(type == particleId::muon ) {
//     leptonEta = mus_eta()->at(index);
//     leptonPhi = mus_phi()->at(index);
//     leptonPt = mus_pt()->at(index);
//     pdgid = 13;
//   } else if(type == particleId::electron) {
//     leptonEta = els_eta()->at(index);
//     leptonPhi = els_phi()->at(index);
//     leptonPt = els_pt()->at(index);
//     pdgid = 11;
//   }
//   for(unsigned iCand=0; iCand<pfcand_pt()->size(); iCand++) {
//     if(is_nan(pfcand_pt()->at(iCand))
//        || is_nan(pfcand_eta()->at(iCand))
//        || is_nan(pfcand_phi()->at(iCand))) continue;
//     if(fabs(TMath::Nint(pfcand_pdgId()->at(iCand)))==pdgid) {
//       double tempDeltaR = dR(leptonEta, pfcand_eta()->at(iCand), leptonPhi, pfcand_phi()->at(iCand));
//       if(tempDeltaR < deltaRVal) {
//         deltaRVal = tempDeltaR;
//         deltaPT = fabs(leptonPt-pfcand_pt()->at(iCand));
//         pfIdx=iCand;
//       }
//     }
//   }

//   if(type == particleId::electron) return (deltaPT<10);
//   else return (deltaPT<5);
// }

void phys_objects::GetLeadingBJets(const vector<int> &good_jets,
                                   double pt_cut, double csv_cut,
                                   size_t &lead, size_t &sub){
  lead = -1;
  sub = -1;

  float pt1 = -1., pt2 = -1.;
  for(size_t i = 0; i < good_jets.size(); ++i){
    size_t ijet = good_jets.at(i);
    double pt = jets_corr_p4().at(ijet).Pt();
    if(pt > pt_cut
       && jets_btag_inc_secVertexCombined()->at(ijet) > csv_cut){
      if(pt > pt1){
        pt2 = pt1;
        pt1 = pt;
        sub = lead;
        lead = ijet;
      }else if(pt > pt2){
        pt2 = pt;
        sub = ijet;
      }
    }
  }
}

