#include "cfa_base.hpp"

#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>

#include "TChain.h"

cfa_base::cfa_base(const std::string &file):
  chainA_("chainA"),
  chainB_("chainB"),
  sample_name_(file),
  total_entries_(0),
  cfa_version_(-1),
  cached_total_entries_(false){
  GetVersion();
  AddFiles(file);
}

long cfa_base::TotalEntries() const{
  if(!cached_total_entries_){
    const long nEntriesA(chainA_.GetEntries()), nEntriesB(chainB_.GetEntries());
    if (nEntriesA!=nEntriesB){
      total_entries_=-1;
    }else{
      total_entries_=nEntriesA;
    }
    cached_total_entries_=true;
  }
  return total_entries_;
}

void cfa_base::GetEntry(const long entry){
  const long entry_a = chainA_.LoadTree(entry);
  const long entry_b = chainB_.LoadTree(entry);
  if(entry_a!=entry_b) throw std::runtime_error("Entry is in different trees for chains A and B");
  entry_ = entry_a;
}

short cfa_base::GetVersion() const{
  return cfa_version_;
}

const std::string& cfa_base::SampleName() const{
  return sample_name_;
}

const std::string& cfa_base::SampleName(const std::string &sample_name){
  sample_name_=sample_name;
  return sample_name_;
}

void cfa_base::SetFile(const std::string &file_name){
  cached_total_entries_=false;
  chainA_.Reset(); chainB_.Reset();
  AddFiles(file_name);
}

cfa_base::~cfa_base(){
}

void cfa_base::CalcVersion(){
  size_t pos = sample_name_.rfind("_v");
  if(pos != std::string::npos && pos < sample_name_.size()-2){
    std::istringstream iss(sample_name_.substr(pos+2));
    iss >> cfa_version_;
    if(iss.fail() || iss.bad()){
      cfa_version_ = -1;
    }
  }
}

void cfa_base::AddFiles(const std::string &file_name){
  cached_total_entries_=false;
  chainA_.Add((file_name+"/configurableAnalysis/eventA").c_str());
  chainB_.Add((file_name+"/configurableAnalysis/eventB").c_str());
}

void cfa_base::PrepareNewChains(){
  InitializeA();
  InitializeB();
}

Int_t const & cfa_base::EcalDeadCellTriggerPrimitivefilter_decision() const{
  throw std::runtime_error("EcalDeadCellTriggerPrimitivefilter_decision does not exist in this cfa version.");
}

Int_t const & cfa_base::HBHENoisefilter_decision() const{
  throw std::runtime_error("HBHENoisefilter_decision does not exist in this cfa version.");
}

Int_t const & cfa_base::METFiltersfilter_decision() const{
  throw std::runtime_error("METFiltersfilter_decision does not exist in this cfa version.");
}

UInt_t const & cfa_base::NbeamSpot() const{
  throw std::runtime_error("NbeamSpot does not exist in this cfa version.");
}

UInt_t const & cfa_base::Nels() const{
  throw std::runtime_error("Nels does not exist in this cfa version.");
}

UInt_t const & cfa_base::Njets_AK4() const{
  throw std::runtime_error("Njets_AK4 does not exist in this cfa version.");
}

UInt_t const & cfa_base::Nmc_doc() const{
  throw std::runtime_error("Nmc_doc does not exist in this cfa version.");
}

UInt_t const & cfa_base::Nmc_electrons() const{
  throw std::runtime_error("Nmc_electrons does not exist in this cfa version.");
}

UInt_t const & cfa_base::Nmc_final() const{
  throw std::runtime_error("Nmc_final does not exist in this cfa version.");
}

UInt_t const & cfa_base::Nmc_jets() const{
  throw std::runtime_error("Nmc_jets does not exist in this cfa version.");
}

UInt_t const & cfa_base::Nmc_mus() const{
  throw std::runtime_error("Nmc_mus does not exist in this cfa version.");
}

UInt_t const & cfa_base::Nmc_nues() const{
  throw std::runtime_error("Nmc_nues does not exist in this cfa version.");
}

UInt_t const & cfa_base::Nmc_numus() const{
  throw std::runtime_error("Nmc_numus does not exist in this cfa version.");
}

UInt_t const & cfa_base::Nmc_nutaus() const{
  throw std::runtime_error("Nmc_nutaus does not exist in this cfa version.");
}

UInt_t const & cfa_base::Nmc_photons() const{
  throw std::runtime_error("Nmc_photons does not exist in this cfa version.");
}

UInt_t const & cfa_base::Nmc_taus() const{
  throw std::runtime_error("Nmc_taus does not exist in this cfa version.");
}

UInt_t const & cfa_base::Nmets() const{
  throw std::runtime_error("Nmets does not exist in this cfa version.");
}

UInt_t const & cfa_base::Nmus() const{
  throw std::runtime_error("Nmus does not exist in this cfa version.");
}

UInt_t const & cfa_base::Npfcand() const{
  throw std::runtime_error("Npfcand does not exist in this cfa version.");
}

UInt_t const & cfa_base::Nphotons() const{
  throw std::runtime_error("Nphotons does not exist in this cfa version.");
}

UInt_t const & cfa_base::Npv() const{
  throw std::runtime_error("Npv does not exist in this cfa version.");
}

UInt_t const & cfa_base::Ntaus() const{
  throw std::runtime_error("Ntaus does not exist in this cfa version.");
}

std::vector<int>* const & cfa_base::PU_NumInteractions() const{
  throw std::runtime_error("PU_NumInteractions does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::PU_TrueNumInteractions() const{
  throw std::runtime_error("PU_TrueNumInteractions does not exist in this cfa version.");
}

std::vector<int>* const & cfa_base::PU_bunchCrossing() const{
  throw std::runtime_error("PU_bunchCrossing does not exist in this cfa version.");
}

std::vector<std::vector<int> >* const & cfa_base::PU_ntrks_highpT() const{
  throw std::runtime_error("PU_ntrks_highpT does not exist in this cfa version.");
}

std::vector<std::vector<int> >* const & cfa_base::PU_ntrks_lowpT() const{
  throw std::runtime_error("PU_ntrks_lowpT does not exist in this cfa version.");
}

std::vector<std::vector<float> >* const & cfa_base::PU_sumpT_highpT() const{
  throw std::runtime_error("PU_sumpT_highpT does not exist in this cfa version.");
}

std::vector<std::vector<float> >* const & cfa_base::PU_sumpT_lowpT() const{
  throw std::runtime_error("PU_sumpT_lowpT does not exist in this cfa version.");
}

std::vector<std::vector<float> >* const & cfa_base::PU_zpositions() const{
  throw std::runtime_error("PU_zpositions does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::beamSpot_beamWidthX() const{
  throw std::runtime_error("beamSpot_beamWidthX does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::beamSpot_beamWidthXError() const{
  throw std::runtime_error("beamSpot_beamWidthXError does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::beamSpot_beamWidthY() const{
  throw std::runtime_error("beamSpot_beamWidthY does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::beamSpot_beamWidthYError() const{
  throw std::runtime_error("beamSpot_beamWidthYError does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::beamSpot_dxdz() const{
  throw std::runtime_error("beamSpot_dxdz does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::beamSpot_dxdzError() const{
  throw std::runtime_error("beamSpot_dxdzError does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::beamSpot_dydz() const{
  throw std::runtime_error("beamSpot_dydz does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::beamSpot_dydzError() const{
  throw std::runtime_error("beamSpot_dydzError does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::beamSpot_sigmaZ() const{
  throw std::runtime_error("beamSpot_sigmaZ does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::beamSpot_sigmaZ0Error() const{
  throw std::runtime_error("beamSpot_sigmaZ0Error does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::beamSpot_x() const{
  throw std::runtime_error("beamSpot_x does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::beamSpot_x0Error() const{
  throw std::runtime_error("beamSpot_x0Error does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::beamSpot_y() const{
  throw std::runtime_error("beamSpot_y does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::beamSpot_y0Error() const{
  throw std::runtime_error("beamSpot_y0Error does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::beamSpot_z() const{
  throw std::runtime_error("beamSpot_z does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::beamSpot_z0Error() const{
  throw std::runtime_error("beamSpot_z0Error does not exist in this cfa version.");
}

UInt_t const & cfa_base::bunchCrossing() const{
  throw std::runtime_error("bunchCrossing does not exist in this cfa version.");
}

Int_t const & cfa_base::cschalofilter_decision() const{
  throw std::runtime_error("cschalofilter_decision does not exist in this cfa version.");
}

Int_t const & cfa_base::ecallaserfilter_decision() const{
  throw std::runtime_error("ecallaserfilter_decision does not exist in this cfa version.");
}

Int_t const & cfa_base::eebadscfilter_decision() const{
  throw std::runtime_error("eebadscfilter_decision does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_PATpassConversionVeto() const{
  throw std::runtime_error("els_PATpassConversionVeto does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_basicClustersSize() const{
  throw std::runtime_error("els_basicClustersSize does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_cIso() const{
  throw std::runtime_error("els_cIso does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_caloEnergy() const{
  throw std::runtime_error("els_caloEnergy does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_charge() const{
  throw std::runtime_error("els_charge does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_chi2() const{
  throw std::runtime_error("els_chi2 does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_core_ecalDrivenSeed() const{
  throw std::runtime_error("els_core_ecalDrivenSeed does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_cpx() const{
  throw std::runtime_error("els_cpx does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_cpy() const{
  throw std::runtime_error("els_cpy does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_cpz() const{
  throw std::runtime_error("els_cpz does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_ctf_tk_charge() const{
  throw std::runtime_error("els_ctf_tk_charge does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_ctf_tk_eta() const{
  throw std::runtime_error("els_ctf_tk_eta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_ctf_tk_id() const{
  throw std::runtime_error("els_ctf_tk_id does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_ctf_tk_phi() const{
  throw std::runtime_error("els_ctf_tk_phi does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_cx() const{
  throw std::runtime_error("els_cx does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_cy() const{
  throw std::runtime_error("els_cy does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_cz() const{
  throw std::runtime_error("els_cz does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_d0dum() const{
  throw std::runtime_error("els_d0dum does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_d0dumError() const{
  throw std::runtime_error("els_d0dumError does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_dEtaIn() const{
  throw std::runtime_error("els_dEtaIn does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_dEtaOut() const{
  throw std::runtime_error("els_dEtaOut does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_dPhiIn() const{
  throw std::runtime_error("els_dPhiIn does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_dPhiOut() const{
  throw std::runtime_error("els_dPhiOut does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_dr03EcalRecHitSumEt() const{
  throw std::runtime_error("els_dr03EcalRecHitSumEt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_dr03HcalDepth1TowerSumEt() const{
  throw std::runtime_error("els_dr03HcalDepth1TowerSumEt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_dr03HcalDepth2TowerSumEt() const{
  throw std::runtime_error("els_dr03HcalDepth2TowerSumEt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_dr03HcalTowerSumEt() const{
  throw std::runtime_error("els_dr03HcalTowerSumEt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_dr03TkSumPt() const{
  throw std::runtime_error("els_dr03TkSumPt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_dr04EcalRecHitSumEt() const{
  throw std::runtime_error("els_dr04EcalRecHitSumEt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_dr04HcalDepth1TowerSumEt() const{
  throw std::runtime_error("els_dr04HcalDepth1TowerSumEt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_dr04HcalDepth2TowerSumEt() const{
  throw std::runtime_error("els_dr04HcalDepth2TowerSumEt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_dr04HcalTowerSumEt() const{
  throw std::runtime_error("els_dr04HcalTowerSumEt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_dr04TkSumPt() const{
  throw std::runtime_error("els_dr04TkSumPt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_dz() const{
  throw std::runtime_error("els_dz does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_dzError() const{
  throw std::runtime_error("els_dzError does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_eOverPIn() const{
  throw std::runtime_error("els_eOverPIn does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_eSeedOverPOut() const{
  throw std::runtime_error("els_eSeedOverPOut does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_ecalIso() const{
  throw std::runtime_error("els_ecalIso does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_energy() const{
  throw std::runtime_error("els_energy does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_et() const{
  throw std::runtime_error("els_et does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_eta() const{
  throw std::runtime_error("els_eta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_etaError() const{
  throw std::runtime_error("els_etaError does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_fbrem() const{
  throw std::runtime_error("els_fbrem does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_full5x5_sigmaIetaIeta() const{
  throw std::runtime_error("els_full5x5_sigmaIetaIeta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_gen_et() const{
  throw std::runtime_error("els_gen_et does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_gen_eta() const{
  throw std::runtime_error("els_gen_eta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_gen_id() const{
  throw std::runtime_error("els_gen_id does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_gen_mother_et() const{
  throw std::runtime_error("els_gen_mother_et does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_gen_mother_eta() const{
  throw std::runtime_error("els_gen_mother_eta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_gen_mother_id() const{
  throw std::runtime_error("els_gen_mother_id does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_gen_mother_phi() const{
  throw std::runtime_error("els_gen_mother_phi does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_gen_mother_pt() const{
  throw std::runtime_error("els_gen_mother_pt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_gen_mother_px() const{
  throw std::runtime_error("els_gen_mother_px does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_gen_mother_py() const{
  throw std::runtime_error("els_gen_mother_py does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_gen_mother_pz() const{
  throw std::runtime_error("els_gen_mother_pz does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_gen_mother_theta() const{
  throw std::runtime_error("els_gen_mother_theta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_gen_phi() const{
  throw std::runtime_error("els_gen_phi does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_gen_pt() const{
  throw std::runtime_error("els_gen_pt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_gen_px() const{
  throw std::runtime_error("els_gen_px does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_gen_py() const{
  throw std::runtime_error("els_gen_py does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_gen_pz() const{
  throw std::runtime_error("els_gen_pz does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_gen_theta() const{
  throw std::runtime_error("els_gen_theta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_hadOverEm() const{
  throw std::runtime_error("els_hadOverEm does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_hcalIso() const{
  throw std::runtime_error("els_hcalIso does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_hcalOverEcalBc() const{
  throw std::runtime_error("els_hcalOverEcalBc does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_isEB() const{
  throw std::runtime_error("els_isEB does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_isEE() const{
  throw std::runtime_error("els_isEE does not exist in this cfa version.");
}

std::vector<bool>* const & cfa_base::els_isPF() const{
  throw std::runtime_error("els_isPF does not exist in this cfa version.");
}

std::vector<int>* const & cfa_base::els_jet_ind() const{
  throw std::runtime_error("els_jet_ind does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_looseId() const{
  throw std::runtime_error("els_looseId does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_n_inner_layer() const{
  throw std::runtime_error("els_n_inner_layer does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_n_outer_layer() const{
  throw std::runtime_error("els_n_outer_layer does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_ndof() const{
  throw std::runtime_error("els_ndof does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_numlosthits() const{
  throw std::runtime_error("els_numlosthits does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_numvalhits() const{
  throw std::runtime_error("els_numvalhits does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_pfIsolationR03_sumChargedHadronPt() const{
  throw std::runtime_error("els_pfIsolationR03_sumChargedHadronPt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_pfIsolationR03_sumNeutralHadronEt() const{
  throw std::runtime_error("els_pfIsolationR03_sumNeutralHadronEt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_pfIsolationR03_sumPUPt() const{
  throw std::runtime_error("els_pfIsolationR03_sumPUPt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_pfIsolationR03_sumPhotonEt() const{
  throw std::runtime_error("els_pfIsolationR03_sumPhotonEt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_phi() const{
  throw std::runtime_error("els_phi does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_phiError() const{
  throw std::runtime_error("els_phiError does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_pt() const{
  throw std::runtime_error("els_pt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_ptError() const{
  throw std::runtime_error("els_ptError does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_px() const{
  throw std::runtime_error("els_px does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_py() const{
  throw std::runtime_error("els_py does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_pz() const{
  throw std::runtime_error("els_pz does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_robustHighEnergyId() const{
  throw std::runtime_error("els_robustHighEnergyId does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_robustLooseId() const{
  throw std::runtime_error("els_robustLooseId does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_robustTightId() const{
  throw std::runtime_error("els_robustTightId does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_scE1x5() const{
  throw std::runtime_error("els_scE1x5 does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_scE2x5Max() const{
  throw std::runtime_error("els_scE2x5Max does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_scE5x5() const{
  throw std::runtime_error("els_scE5x5 does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_scEnergy() const{
  throw std::runtime_error("els_scEnergy does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_scEta() const{
  throw std::runtime_error("els_scEta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_scEtaWidth() const{
  throw std::runtime_error("els_scEtaWidth does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_scPhi() const{
  throw std::runtime_error("els_scPhi does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_scPhiWidth() const{
  throw std::runtime_error("els_scPhiWidth does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_scRawEnergy() const{
  throw std::runtime_error("els_scRawEnergy does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_scSeedEnergy() const{
  throw std::runtime_error("els_scSeedEnergy does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_shFracInnerHits() const{
  throw std::runtime_error("els_shFracInnerHits does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_sigmaEtaEta() const{
  throw std::runtime_error("els_sigmaEtaEta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_sigmaIEtaIEta() const{
  throw std::runtime_error("els_sigmaIEtaIEta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_simpleEleId60cIso() const{
  throw std::runtime_error("els_simpleEleId60cIso does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_simpleEleId60relIso() const{
  throw std::runtime_error("els_simpleEleId60relIso does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_simpleEleId70cIso() const{
  throw std::runtime_error("els_simpleEleId70cIso does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_simpleEleId70relIso() const{
  throw std::runtime_error("els_simpleEleId70relIso does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_simpleEleId80cIso() const{
  throw std::runtime_error("els_simpleEleId80cIso does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_simpleEleId80relIso() const{
  throw std::runtime_error("els_simpleEleId80relIso does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_simpleEleId85cIso() const{
  throw std::runtime_error("els_simpleEleId85cIso does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_simpleEleId85relIso() const{
  throw std::runtime_error("els_simpleEleId85relIso does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_simpleEleId90cIso() const{
  throw std::runtime_error("els_simpleEleId90cIso does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_simpleEleId90relIso() const{
  throw std::runtime_error("els_simpleEleId90relIso does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_simpleEleId95cIso() const{
  throw std::runtime_error("els_simpleEleId95cIso does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_simpleEleId95relIso() const{
  throw std::runtime_error("els_simpleEleId95relIso does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_status() const{
  throw std::runtime_error("els_status does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_tIso() const{
  throw std::runtime_error("els_tIso does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_theta() const{
  throw std::runtime_error("els_theta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_tightId() const{
  throw std::runtime_error("els_tightId does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_tk_charge() const{
  throw std::runtime_error("els_tk_charge does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_tk_eta() const{
  throw std::runtime_error("els_tk_eta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_tk_phi() const{
  throw std::runtime_error("els_tk_phi does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_tk_pt() const{
  throw std::runtime_error("els_tk_pt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_tk_pz() const{
  throw std::runtime_error("els_tk_pz does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_vpx() const{
  throw std::runtime_error("els_vpx does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_vpy() const{
  throw std::runtime_error("els_vpy does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_vpz() const{
  throw std::runtime_error("els_vpz does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_vx() const{
  throw std::runtime_error("els_vx does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_vy() const{
  throw std::runtime_error("els_vy does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::els_vz() const{
  throw std::runtime_error("els_vz does not exist in this cfa version.");
}

UInt_t const & cfa_base::event() const{
  throw std::runtime_error("event does not exist in this cfa version.");
}

UInt_t const & cfa_base::experimentType() const{
  throw std::runtime_error("experimentType does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT10_energy() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT10_energy does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT10_eta() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT10_eta does not exist in this cfa version.");
}

std::vector<std::vector<int> >* const & cfa_base::fastjets_AK4_R1p2_R0p5pT10_index() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT10_index does not exist in this cfa version.");
}

std::vector<int>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT10_nconstituents() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT10_nconstituents does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT10_phi() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT10_phi does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT10_px() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT10_px does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT10_py() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT10_py does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT10_pz() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT10_pz does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT15_energy() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT15_energy does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT15_eta() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT15_eta does not exist in this cfa version.");
}

std::vector<std::vector<int> >* const & cfa_base::fastjets_AK4_R1p2_R0p5pT15_index() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT15_index does not exist in this cfa version.");
}

std::vector<int>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT15_nconstituents() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT15_nconstituents does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT15_phi() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT15_phi does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT15_px() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT15_px does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT15_py() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT15_py does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT15_pz() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT15_pz does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT20_energy() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT20_energy does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT20_eta() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT20_eta does not exist in this cfa version.");
}

std::vector<std::vector<int> >* const & cfa_base::fastjets_AK4_R1p2_R0p5pT20_index() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT20_index does not exist in this cfa version.");
}

std::vector<int>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT20_nconstituents() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT20_nconstituents does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT20_phi() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT20_phi does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT20_px() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT20_px does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT20_py() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT20_py does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT20_pz() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT20_pz does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT25_energy() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT25_energy does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT25_eta() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT25_eta does not exist in this cfa version.");
}

std::vector<std::vector<int> >* const & cfa_base::fastjets_AK4_R1p2_R0p5pT25_index() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT25_index does not exist in this cfa version.");
}

std::vector<int>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT25_nconstituents() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT25_nconstituents does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT25_phi() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT25_phi does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT25_px() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT25_px does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT25_py() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT25_py does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT25_pz() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT25_pz does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT30_energy() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT30_energy does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT30_eta() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT30_eta does not exist in this cfa version.");
}

std::vector<std::vector<int> >* const & cfa_base::fastjets_AK4_R1p2_R0p5pT30_index() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT30_index does not exist in this cfa version.");
}

std::vector<int>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT30_nconstituents() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT30_nconstituents does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT30_phi() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT30_phi does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT30_px() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT30_px does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT30_py() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT30_py does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT30_pz() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT30_pz does not exist in this cfa version.");
}

Int_t const & cfa_base::goodVerticesfilter_decision() const{
  throw std::runtime_error("goodVerticesfilter_decision does not exist in this cfa version.");
}

Int_t const & cfa_base::hcallaserfilter_decision() const{
  throw std::runtime_error("hcallaserfilter_decision does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_area() const{
  throw std::runtime_error("jets_AK4_area does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_btag_TC_highEff() const{
  throw std::runtime_error("jets_AK4_btag_TC_highEff does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_btag_TC_highPur() const{
  throw std::runtime_error("jets_AK4_btag_TC_highPur does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_btag_jetBProb() const{
  throw std::runtime_error("jets_AK4_btag_jetBProb does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_btag_jetProb() const{
  throw std::runtime_error("jets_AK4_btag_jetProb does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_btag_secVertexCombined() const{
  throw std::runtime_error("jets_AK4_btag_secVertexCombined does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_btag_secVertexHighEff() const{
  throw std::runtime_error("jets_AK4_btag_secVertexHighEff does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_btag_secVertexHighPur() const{
  throw std::runtime_error("jets_AK4_btag_secVertexHighPur does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_btag_softEle() const{
  throw std::runtime_error("jets_AK4_btag_softEle does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_btag_softMuon() const{
  throw std::runtime_error("jets_AK4_btag_softMuon does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_chgEmE() const{
  throw std::runtime_error("jets_AK4_chgEmE does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_chgHadE() const{
  throw std::runtime_error("jets_AK4_chgHadE does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_chgMuE() const{
  throw std::runtime_error("jets_AK4_chgMuE does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_chg_Mult() const{
  throw std::runtime_error("jets_AK4_chg_Mult does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_corrFactorRaw() const{
  throw std::runtime_error("jets_AK4_corrFactorRaw does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_ehf() const{
  throw std::runtime_error("jets_AK4_ehf does not exist in this cfa version.");
}

std::vector<int>* const & cfa_base::jets_AK4_el_ind() const{
  throw std::runtime_error("jets_AK4_el_ind does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_emf() const{
  throw std::runtime_error("jets_AK4_emf does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_energy() const{
  throw std::runtime_error("jets_AK4_energy does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_et() const{
  throw std::runtime_error("jets_AK4_et does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_eta() const{
  throw std::runtime_error("jets_AK4_eta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_etaetaMoment() const{
  throw std::runtime_error("jets_AK4_etaetaMoment does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_etaphiMoment() const{
  throw std::runtime_error("jets_AK4_etaphiMoment does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_fHPD() const{
  throw std::runtime_error("jets_AK4_fHPD does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_fRBX() const{
  throw std::runtime_error("jets_AK4_fRBX does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_fSubDetector1() const{
  throw std::runtime_error("jets_AK4_fSubDetector1 does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_fSubDetector2() const{
  throw std::runtime_error("jets_AK4_fSubDetector2 does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_fSubDetector3() const{
  throw std::runtime_error("jets_AK4_fSubDetector3 does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_fSubDetector4() const{
  throw std::runtime_error("jets_AK4_fSubDetector4 does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_gen_Energy() const{
  throw std::runtime_error("jets_AK4_gen_Energy does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_gen_Id() const{
  throw std::runtime_error("jets_AK4_gen_Id does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_gen_et() const{
  throw std::runtime_error("jets_AK4_gen_et does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_gen_eta() const{
  throw std::runtime_error("jets_AK4_gen_eta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_gen_mass() const{
  throw std::runtime_error("jets_AK4_gen_mass does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_gen_motherID() const{
  throw std::runtime_error("jets_AK4_gen_motherID does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_gen_phi() const{
  throw std::runtime_error("jets_AK4_gen_phi does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_gen_pt() const{
  throw std::runtime_error("jets_AK4_gen_pt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_gen_threeCharge() const{
  throw std::runtime_error("jets_AK4_gen_threeCharge does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_hitsInN90() const{
  throw std::runtime_error("jets_AK4_hitsInN90 does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_jetCharge() const{
  throw std::runtime_error("jets_AK4_jetCharge does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_mass() const{
  throw std::runtime_error("jets_AK4_mass does not exist in this cfa version.");
}

std::vector<int>* const & cfa_base::jets_AK4_maxpt_id() const{
  throw std::runtime_error("jets_AK4_maxpt_id does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_mu_Mult() const{
  throw std::runtime_error("jets_AK4_mu_Mult does not exist in this cfa version.");
}

std::vector<int>* const & cfa_base::jets_AK4_mu_ind() const{
  throw std::runtime_error("jets_AK4_mu_ind does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_n60() const{
  throw std::runtime_error("jets_AK4_n60 does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_n90() const{
  throw std::runtime_error("jets_AK4_n90 does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_n90Hits() const{
  throw std::runtime_error("jets_AK4_n90Hits does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_nECALTowers() const{
  throw std::runtime_error("jets_AK4_nECALTowers does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_nHCALTowers() const{
  throw std::runtime_error("jets_AK4_nHCALTowers does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_neutralEmE() const{
  throw std::runtime_error("jets_AK4_neutralEmE does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_neutralHadE() const{
  throw std::runtime_error("jets_AK4_neutralHadE does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_neutral_Mult() const{
  throw std::runtime_error("jets_AK4_neutral_Mult does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_partonFlavour() const{
  throw std::runtime_error("jets_AK4_partonFlavour does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_parton_Energy() const{
  throw std::runtime_error("jets_AK4_parton_Energy does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_parton_Id() const{
  throw std::runtime_error("jets_AK4_parton_Id does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_parton_eta() const{
  throw std::runtime_error("jets_AK4_parton_eta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_parton_mass() const{
  throw std::runtime_error("jets_AK4_parton_mass does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_parton_motherId() const{
  throw std::runtime_error("jets_AK4_parton_motherId does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_parton_phi() const{
  throw std::runtime_error("jets_AK4_parton_phi does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_parton_pt() const{
  throw std::runtime_error("jets_AK4_parton_pt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_phi() const{
  throw std::runtime_error("jets_AK4_phi does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_phiphiMoment() const{
  throw std::runtime_error("jets_AK4_phiphiMoment does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_photonEnergy() const{
  throw std::runtime_error("jets_AK4_photonEnergy does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_pt() const{
  throw std::runtime_error("jets_AK4_pt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_px() const{
  throw std::runtime_error("jets_AK4_px does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_py() const{
  throw std::runtime_error("jets_AK4_py does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_pz() const{
  throw std::runtime_error("jets_AK4_pz does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_rawPt() const{
  throw std::runtime_error("jets_AK4_rawPt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_status() const{
  throw std::runtime_error("jets_AK4_status does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::jets_AK4_theta() const{
  throw std::runtime_error("jets_AK4_theta does not exist in this cfa version.");
}

UInt_t const & cfa_base::lumiblock() const{
  throw std::runtime_error("lumiblock does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_doc_charge() const{
  throw std::runtime_error("mc_doc_charge does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_doc_energy() const{
  throw std::runtime_error("mc_doc_energy does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_doc_eta() const{
  throw std::runtime_error("mc_doc_eta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_doc_ggrandmother_id() const{
  throw std::runtime_error("mc_doc_ggrandmother_id does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_doc_grandmother_id() const{
  throw std::runtime_error("mc_doc_grandmother_id does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_doc_id() const{
  throw std::runtime_error("mc_doc_id does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_doc_mass() const{
  throw std::runtime_error("mc_doc_mass does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_doc_mother_id() const{
  throw std::runtime_error("mc_doc_mother_id does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_doc_mother_pt() const{
  throw std::runtime_error("mc_doc_mother_pt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_doc_numOfDaughters() const{
  throw std::runtime_error("mc_doc_numOfDaughters does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_doc_numOfMothers() const{
  throw std::runtime_error("mc_doc_numOfMothers does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_doc_phi() const{
  throw std::runtime_error("mc_doc_phi does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_doc_pt() const{
  throw std::runtime_error("mc_doc_pt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_doc_px() const{
  throw std::runtime_error("mc_doc_px does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_doc_py() const{
  throw std::runtime_error("mc_doc_py does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_doc_pz() const{
  throw std::runtime_error("mc_doc_pz does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_doc_status() const{
  throw std::runtime_error("mc_doc_status does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_doc_theta() const{
  throw std::runtime_error("mc_doc_theta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_doc_vertex_x() const{
  throw std::runtime_error("mc_doc_vertex_x does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_doc_vertex_y() const{
  throw std::runtime_error("mc_doc_vertex_y does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_doc_vertex_z() const{
  throw std::runtime_error("mc_doc_vertex_z does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_electrons_charge() const{
  throw std::runtime_error("mc_electrons_charge does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_electrons_energy() const{
  throw std::runtime_error("mc_electrons_energy does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_electrons_eta() const{
  throw std::runtime_error("mc_electrons_eta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_electrons_ggrandmother_id() const{
  throw std::runtime_error("mc_electrons_ggrandmother_id does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_electrons_grandmother_id() const{
  throw std::runtime_error("mc_electrons_grandmother_id does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_electrons_id() const{
  throw std::runtime_error("mc_electrons_id does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_electrons_mass() const{
  throw std::runtime_error("mc_electrons_mass does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_electrons_mother_id() const{
  throw std::runtime_error("mc_electrons_mother_id does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_electrons_mother_pt() const{
  throw std::runtime_error("mc_electrons_mother_pt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_electrons_numOfDaughters() const{
  throw std::runtime_error("mc_electrons_numOfDaughters does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_electrons_phi() const{
  throw std::runtime_error("mc_electrons_phi does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_electrons_pt() const{
  throw std::runtime_error("mc_electrons_pt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_electrons_px() const{
  throw std::runtime_error("mc_electrons_px does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_electrons_py() const{
  throw std::runtime_error("mc_electrons_py does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_electrons_pz() const{
  throw std::runtime_error("mc_electrons_pz does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_electrons_status() const{
  throw std::runtime_error("mc_electrons_status does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_electrons_theta() const{
  throw std::runtime_error("mc_electrons_theta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_electrons_vertex_x() const{
  throw std::runtime_error("mc_electrons_vertex_x does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_electrons_vertex_y() const{
  throw std::runtime_error("mc_electrons_vertex_y does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_electrons_vertex_z() const{
  throw std::runtime_error("mc_electrons_vertex_z does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_final_charge() const{
  throw std::runtime_error("mc_final_charge does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_final_energy() const{
  throw std::runtime_error("mc_final_energy does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_final_eta() const{
  throw std::runtime_error("mc_final_eta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_final_ggrandmother_id() const{
  throw std::runtime_error("mc_final_ggrandmother_id does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_final_grandmother_id() const{
  throw std::runtime_error("mc_final_grandmother_id does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_final_id() const{
  throw std::runtime_error("mc_final_id does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_final_mass() const{
  throw std::runtime_error("mc_final_mass does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_final_mother_id() const{
  throw std::runtime_error("mc_final_mother_id does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_final_mother_pt() const{
  throw std::runtime_error("mc_final_mother_pt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_final_numOfDaughters() const{
  throw std::runtime_error("mc_final_numOfDaughters does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_final_numOfMothers() const{
  throw std::runtime_error("mc_final_numOfMothers does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_final_phi() const{
  throw std::runtime_error("mc_final_phi does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_final_pt() const{
  throw std::runtime_error("mc_final_pt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_final_px() const{
  throw std::runtime_error("mc_final_px does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_final_py() const{
  throw std::runtime_error("mc_final_py does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_final_pz() const{
  throw std::runtime_error("mc_final_pz does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_final_status() const{
  throw std::runtime_error("mc_final_status does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_final_theta() const{
  throw std::runtime_error("mc_final_theta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_final_vertex_x() const{
  throw std::runtime_error("mc_final_vertex_x does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_final_vertex_y() const{
  throw std::runtime_error("mc_final_vertex_y does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_final_vertex_z() const{
  throw std::runtime_error("mc_final_vertex_z does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_jets_auxiliaryEnergy() const{
  throw std::runtime_error("mc_jets_auxiliaryEnergy does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_jets_emEnergy() const{
  throw std::runtime_error("mc_jets_emEnergy does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_jets_energy() const{
  throw std::runtime_error("mc_jets_energy does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_jets_et() const{
  throw std::runtime_error("mc_jets_et does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_jets_eta() const{
  throw std::runtime_error("mc_jets_eta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_jets_etaetaMoment() const{
  throw std::runtime_error("mc_jets_etaetaMoment does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_jets_etaphiMoment() const{
  throw std::runtime_error("mc_jets_etaphiMoment does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_jets_hadEnergy() const{
  throw std::runtime_error("mc_jets_hadEnergy does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_jets_invisibleEnergy() const{
  throw std::runtime_error("mc_jets_invisibleEnergy does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_jets_mass() const{
  throw std::runtime_error("mc_jets_mass does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_jets_phi() const{
  throw std::runtime_error("mc_jets_phi does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_jets_phiphiMoment() const{
  throw std::runtime_error("mc_jets_phiphiMoment does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_jets_pt() const{
  throw std::runtime_error("mc_jets_pt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_jets_px() const{
  throw std::runtime_error("mc_jets_px does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_jets_py() const{
  throw std::runtime_error("mc_jets_py does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_jets_pz() const{
  throw std::runtime_error("mc_jets_pz does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_jets_theta() const{
  throw std::runtime_error("mc_jets_theta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_mus_charge() const{
  throw std::runtime_error("mc_mus_charge does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_mus_energy() const{
  throw std::runtime_error("mc_mus_energy does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_mus_eta() const{
  throw std::runtime_error("mc_mus_eta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_mus_ggrandmother_id() const{
  throw std::runtime_error("mc_mus_ggrandmother_id does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_mus_grandmother_id() const{
  throw std::runtime_error("mc_mus_grandmother_id does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_mus_id() const{
  throw std::runtime_error("mc_mus_id does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_mus_mass() const{
  throw std::runtime_error("mc_mus_mass does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_mus_mother_id() const{
  throw std::runtime_error("mc_mus_mother_id does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_mus_mother_pt() const{
  throw std::runtime_error("mc_mus_mother_pt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_mus_numOfDaughters() const{
  throw std::runtime_error("mc_mus_numOfDaughters does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_mus_phi() const{
  throw std::runtime_error("mc_mus_phi does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_mus_pt() const{
  throw std::runtime_error("mc_mus_pt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_mus_px() const{
  throw std::runtime_error("mc_mus_px does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_mus_py() const{
  throw std::runtime_error("mc_mus_py does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_mus_pz() const{
  throw std::runtime_error("mc_mus_pz does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_mus_status() const{
  throw std::runtime_error("mc_mus_status does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_mus_theta() const{
  throw std::runtime_error("mc_mus_theta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_mus_vertex_x() const{
  throw std::runtime_error("mc_mus_vertex_x does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_mus_vertex_y() const{
  throw std::runtime_error("mc_mus_vertex_y does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_mus_vertex_z() const{
  throw std::runtime_error("mc_mus_vertex_z does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_nues_charge() const{
  throw std::runtime_error("mc_nues_charge does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_nues_energy() const{
  throw std::runtime_error("mc_nues_energy does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_nues_eta() const{
  throw std::runtime_error("mc_nues_eta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_nues_ggrandmother_id() const{
  throw std::runtime_error("mc_nues_ggrandmother_id does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_nues_grandmother_id() const{
  throw std::runtime_error("mc_nues_grandmother_id does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_nues_id() const{
  throw std::runtime_error("mc_nues_id does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_nues_mass() const{
  throw std::runtime_error("mc_nues_mass does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_nues_mother_id() const{
  throw std::runtime_error("mc_nues_mother_id does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_nues_mother_pt() const{
  throw std::runtime_error("mc_nues_mother_pt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_nues_numOfDaughters() const{
  throw std::runtime_error("mc_nues_numOfDaughters does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_nues_phi() const{
  throw std::runtime_error("mc_nues_phi does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_nues_pt() const{
  throw std::runtime_error("mc_nues_pt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_nues_px() const{
  throw std::runtime_error("mc_nues_px does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_nues_py() const{
  throw std::runtime_error("mc_nues_py does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_nues_pz() const{
  throw std::runtime_error("mc_nues_pz does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_nues_status() const{
  throw std::runtime_error("mc_nues_status does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_nues_theta() const{
  throw std::runtime_error("mc_nues_theta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_nues_vertex_x() const{
  throw std::runtime_error("mc_nues_vertex_x does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_nues_vertex_y() const{
  throw std::runtime_error("mc_nues_vertex_y does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_nues_vertex_z() const{
  throw std::runtime_error("mc_nues_vertex_z does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_numus_charge() const{
  throw std::runtime_error("mc_numus_charge does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_numus_energy() const{
  throw std::runtime_error("mc_numus_energy does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_numus_eta() const{
  throw std::runtime_error("mc_numus_eta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_numus_ggrandmother_id() const{
  throw std::runtime_error("mc_numus_ggrandmother_id does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_numus_grandmother_id() const{
  throw std::runtime_error("mc_numus_grandmother_id does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_numus_id() const{
  throw std::runtime_error("mc_numus_id does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_numus_mass() const{
  throw std::runtime_error("mc_numus_mass does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_numus_mother_id() const{
  throw std::runtime_error("mc_numus_mother_id does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_numus_mother_pt() const{
  throw std::runtime_error("mc_numus_mother_pt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_numus_numOfDaughters() const{
  throw std::runtime_error("mc_numus_numOfDaughters does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_numus_phi() const{
  throw std::runtime_error("mc_numus_phi does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_numus_pt() const{
  throw std::runtime_error("mc_numus_pt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_numus_px() const{
  throw std::runtime_error("mc_numus_px does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_numus_py() const{
  throw std::runtime_error("mc_numus_py does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_numus_pz() const{
  throw std::runtime_error("mc_numus_pz does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_numus_status() const{
  throw std::runtime_error("mc_numus_status does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_numus_theta() const{
  throw std::runtime_error("mc_numus_theta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_numus_vertex_x() const{
  throw std::runtime_error("mc_numus_vertex_x does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_numus_vertex_y() const{
  throw std::runtime_error("mc_numus_vertex_y does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_numus_vertex_z() const{
  throw std::runtime_error("mc_numus_vertex_z does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_nutaus_charge() const{
  throw std::runtime_error("mc_nutaus_charge does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_nutaus_energy() const{
  throw std::runtime_error("mc_nutaus_energy does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_nutaus_eta() const{
  throw std::runtime_error("mc_nutaus_eta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_nutaus_ggrandmother_id() const{
  throw std::runtime_error("mc_nutaus_ggrandmother_id does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_nutaus_grandmother_id() const{
  throw std::runtime_error("mc_nutaus_grandmother_id does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_nutaus_id() const{
  throw std::runtime_error("mc_nutaus_id does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_nutaus_mass() const{
  throw std::runtime_error("mc_nutaus_mass does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_nutaus_mother_id() const{
  throw std::runtime_error("mc_nutaus_mother_id does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_nutaus_mother_pt() const{
  throw std::runtime_error("mc_nutaus_mother_pt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_nutaus_numOfDaughters() const{
  throw std::runtime_error("mc_nutaus_numOfDaughters does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_nutaus_phi() const{
  throw std::runtime_error("mc_nutaus_phi does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_nutaus_pt() const{
  throw std::runtime_error("mc_nutaus_pt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_nutaus_px() const{
  throw std::runtime_error("mc_nutaus_px does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_nutaus_py() const{
  throw std::runtime_error("mc_nutaus_py does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_nutaus_pz() const{
  throw std::runtime_error("mc_nutaus_pz does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_nutaus_status() const{
  throw std::runtime_error("mc_nutaus_status does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_nutaus_theta() const{
  throw std::runtime_error("mc_nutaus_theta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_nutaus_vertex_x() const{
  throw std::runtime_error("mc_nutaus_vertex_x does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_nutaus_vertex_y() const{
  throw std::runtime_error("mc_nutaus_vertex_y does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_nutaus_vertex_z() const{
  throw std::runtime_error("mc_nutaus_vertex_z does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_photons_charge() const{
  throw std::runtime_error("mc_photons_charge does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_photons_energy() const{
  throw std::runtime_error("mc_photons_energy does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_photons_eta() const{
  throw std::runtime_error("mc_photons_eta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_photons_ggrandmother_id() const{
  throw std::runtime_error("mc_photons_ggrandmother_id does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_photons_grandmother_id() const{
  throw std::runtime_error("mc_photons_grandmother_id does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_photons_id() const{
  throw std::runtime_error("mc_photons_id does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_photons_mass() const{
  throw std::runtime_error("mc_photons_mass does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_photons_mother_id() const{
  throw std::runtime_error("mc_photons_mother_id does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_photons_mother_pt() const{
  throw std::runtime_error("mc_photons_mother_pt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_photons_numOfDaughters() const{
  throw std::runtime_error("mc_photons_numOfDaughters does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_photons_phi() const{
  throw std::runtime_error("mc_photons_phi does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_photons_pt() const{
  throw std::runtime_error("mc_photons_pt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_photons_px() const{
  throw std::runtime_error("mc_photons_px does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_photons_py() const{
  throw std::runtime_error("mc_photons_py does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_photons_pz() const{
  throw std::runtime_error("mc_photons_pz does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_photons_status() const{
  throw std::runtime_error("mc_photons_status does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_photons_theta() const{
  throw std::runtime_error("mc_photons_theta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_photons_vertex_x() const{
  throw std::runtime_error("mc_photons_vertex_x does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_photons_vertex_y() const{
  throw std::runtime_error("mc_photons_vertex_y does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_photons_vertex_z() const{
  throw std::runtime_error("mc_photons_vertex_z does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_taus_charge() const{
  throw std::runtime_error("mc_taus_charge does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_taus_energy() const{
  throw std::runtime_error("mc_taus_energy does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_taus_eta() const{
  throw std::runtime_error("mc_taus_eta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_taus_ggrandmother_id() const{
  throw std::runtime_error("mc_taus_ggrandmother_id does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_taus_grandmother_id() const{
  throw std::runtime_error("mc_taus_grandmother_id does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_taus_id() const{
  throw std::runtime_error("mc_taus_id does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_taus_mass() const{
  throw std::runtime_error("mc_taus_mass does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_taus_mother_id() const{
  throw std::runtime_error("mc_taus_mother_id does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_taus_mother_pt() const{
  throw std::runtime_error("mc_taus_mother_pt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_taus_numOfDaughters() const{
  throw std::runtime_error("mc_taus_numOfDaughters does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_taus_phi() const{
  throw std::runtime_error("mc_taus_phi does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_taus_pt() const{
  throw std::runtime_error("mc_taus_pt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_taus_px() const{
  throw std::runtime_error("mc_taus_px does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_taus_py() const{
  throw std::runtime_error("mc_taus_py does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_taus_pz() const{
  throw std::runtime_error("mc_taus_pz does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_taus_status() const{
  throw std::runtime_error("mc_taus_status does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_taus_theta() const{
  throw std::runtime_error("mc_taus_theta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_taus_vertex_x() const{
  throw std::runtime_error("mc_taus_vertex_x does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_taus_vertex_y() const{
  throw std::runtime_error("mc_taus_vertex_y does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mc_taus_vertex_z() const{
  throw std::runtime_error("mc_taus_vertex_z does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mets_et() const{
  throw std::runtime_error("mets_et does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mets_ex() const{
  throw std::runtime_error("mets_ex does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mets_ey() const{
  throw std::runtime_error("mets_ey does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mets_gen_et() const{
  throw std::runtime_error("mets_gen_et does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mets_gen_phi() const{
  throw std::runtime_error("mets_gen_phi does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mets_phi() const{
  throw std::runtime_error("mets_phi does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mets_sign() const{
  throw std::runtime_error("mets_sign does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mets_sumEt() const{
  throw std::runtime_error("mets_sumEt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mets_unCPhi() const{
  throw std::runtime_error("mets_unCPhi does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mets_unCPt() const{
  throw std::runtime_error("mets_unCPt does not exist in this cfa version.");
}

std::string* const & cfa_base::model_params() const{
  throw std::runtime_error("model_params does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_cIso() const{
  throw std::runtime_error("mus_cIso does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_calEnergyEm() const{
  throw std::runtime_error("mus_calEnergyEm does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_calEnergyEmS9() const{
  throw std::runtime_error("mus_calEnergyEmS9 does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_calEnergyHad() const{
  throw std::runtime_error("mus_calEnergyHad does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_calEnergyHadS9() const{
  throw std::runtime_error("mus_calEnergyHadS9 does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_calEnergyHo() const{
  throw std::runtime_error("mus_calEnergyHo does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_calEnergyHoS9() const{
  throw std::runtime_error("mus_calEnergyHoS9 does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_charge() const{
  throw std::runtime_error("mus_charge does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_cm_ExpectedHitsInner() const{
  throw std::runtime_error("mus_cm_ExpectedHitsInner does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_cm_ExpectedHitsOuter() const{
  throw std::runtime_error("mus_cm_ExpectedHitsOuter does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_cm_LayersWithMeasurement() const{
  throw std::runtime_error("mus_cm_LayersWithMeasurement does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_cm_LayersWithoutMeasurement() const{
  throw std::runtime_error("mus_cm_LayersWithoutMeasurement does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_cm_PixelLayersWithMeasurement() const{
  throw std::runtime_error("mus_cm_PixelLayersWithMeasurement does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_cm_ValidStripLayersWithMonoAndStereoHit() const{
  throw std::runtime_error("mus_cm_ValidStripLayersWithMonoAndStereoHit does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_cm_chg() const{
  throw std::runtime_error("mus_cm_chg does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_cm_chi2() const{
  throw std::runtime_error("mus_cm_chi2 does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_cm_d0dum() const{
  throw std::runtime_error("mus_cm_d0dum does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_cm_d0dumErr() const{
  throw std::runtime_error("mus_cm_d0dumErr does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_cm_dz() const{
  throw std::runtime_error("mus_cm_dz does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_cm_dzErr() const{
  throw std::runtime_error("mus_cm_dzErr does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_cm_eta() const{
  throw std::runtime_error("mus_cm_eta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_cm_etaErr() const{
  throw std::runtime_error("mus_cm_etaErr does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_cm_ndof() const{
  throw std::runtime_error("mus_cm_ndof does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_cm_numlosthits() const{
  throw std::runtime_error("mus_cm_numlosthits does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_cm_numvalMuonhits() const{
  throw std::runtime_error("mus_cm_numvalMuonhits does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_cm_numvalhits() const{
  throw std::runtime_error("mus_cm_numvalhits does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_cm_phi() const{
  throw std::runtime_error("mus_cm_phi does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_cm_phiErr() const{
  throw std::runtime_error("mus_cm_phiErr does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_cm_pt() const{
  throw std::runtime_error("mus_cm_pt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_cm_ptErr() const{
  throw std::runtime_error("mus_cm_ptErr does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_cm_px() const{
  throw std::runtime_error("mus_cm_px does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_cm_py() const{
  throw std::runtime_error("mus_cm_py does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_cm_pz() const{
  throw std::runtime_error("mus_cm_pz does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_cm_theta() const{
  throw std::runtime_error("mus_cm_theta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_cm_vx() const{
  throw std::runtime_error("mus_cm_vx does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_cm_vy() const{
  throw std::runtime_error("mus_cm_vy does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_cm_vz() const{
  throw std::runtime_error("mus_cm_vz does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_dB() const{
  throw std::runtime_error("mus_dB does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_ecalIso() const{
  throw std::runtime_error("mus_ecalIso does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_ecalvetoDep() const{
  throw std::runtime_error("mus_ecalvetoDep does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_energy() const{
  throw std::runtime_error("mus_energy does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_et() const{
  throw std::runtime_error("mus_et does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_eta() const{
  throw std::runtime_error("mus_eta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_gen_et() const{
  throw std::runtime_error("mus_gen_et does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_gen_eta() const{
  throw std::runtime_error("mus_gen_eta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_gen_id() const{
  throw std::runtime_error("mus_gen_id does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_gen_mother_et() const{
  throw std::runtime_error("mus_gen_mother_et does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_gen_mother_eta() const{
  throw std::runtime_error("mus_gen_mother_eta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_gen_mother_id() const{
  throw std::runtime_error("mus_gen_mother_id does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_gen_mother_phi() const{
  throw std::runtime_error("mus_gen_mother_phi does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_gen_mother_pt() const{
  throw std::runtime_error("mus_gen_mother_pt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_gen_mother_px() const{
  throw std::runtime_error("mus_gen_mother_px does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_gen_mother_py() const{
  throw std::runtime_error("mus_gen_mother_py does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_gen_mother_pz() const{
  throw std::runtime_error("mus_gen_mother_pz does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_gen_mother_theta() const{
  throw std::runtime_error("mus_gen_mother_theta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_gen_phi() const{
  throw std::runtime_error("mus_gen_phi does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_gen_pt() const{
  throw std::runtime_error("mus_gen_pt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_gen_px() const{
  throw std::runtime_error("mus_gen_px does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_gen_py() const{
  throw std::runtime_error("mus_gen_py does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_gen_pz() const{
  throw std::runtime_error("mus_gen_pz does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_gen_theta() const{
  throw std::runtime_error("mus_gen_theta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_hcalIso() const{
  throw std::runtime_error("mus_hcalIso does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_hcalvetoDep() const{
  throw std::runtime_error("mus_hcalvetoDep does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_id_All() const{
  throw std::runtime_error("mus_id_All does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_id_AllArbitrated() const{
  throw std::runtime_error("mus_id_AllArbitrated does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_id_AllGlobalMuons() const{
  throw std::runtime_error("mus_id_AllGlobalMuons does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_id_AllStandAloneMuons() const{
  throw std::runtime_error("mus_id_AllStandAloneMuons does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_id_AllTrackerMuons() const{
  throw std::runtime_error("mus_id_AllTrackerMuons does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_id_GlobalMuonPromptTight() const{
  throw std::runtime_error("mus_id_GlobalMuonPromptTight does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_id_TM2DCompatibilityLoose() const{
  throw std::runtime_error("mus_id_TM2DCompatibilityLoose does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_id_TM2DCompatibilityTight() const{
  throw std::runtime_error("mus_id_TM2DCompatibilityTight does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_id_TMLastStationLoose() const{
  throw std::runtime_error("mus_id_TMLastStationLoose does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_id_TMLastStationOptimizedLowPtLoose() const{
  throw std::runtime_error("mus_id_TMLastStationOptimizedLowPtLoose does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_id_TMLastStationOptimizedLowPtTight() const{
  throw std::runtime_error("mus_id_TMLastStationOptimizedLowPtTight does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_id_TMLastStationTight() const{
  throw std::runtime_error("mus_id_TMLastStationTight does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_id_TMOneStationLoose() const{
  throw std::runtime_error("mus_id_TMOneStationLoose does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_id_TMOneStationTight() const{
  throw std::runtime_error("mus_id_TMOneStationTight does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_id_TrackerMuonArbitrated() const{
  throw std::runtime_error("mus_id_TrackerMuonArbitrated does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_isCaloMuon() const{
  throw std::runtime_error("mus_isCaloMuon does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_isConvertedPhoton() const{
  throw std::runtime_error("mus_isConvertedPhoton does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_isElectron() const{
  throw std::runtime_error("mus_isElectron does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_isGlobalMuon() const{
  throw std::runtime_error("mus_isGlobalMuon does not exist in this cfa version.");
}

std::vector<bool>* const & cfa_base::mus_isPF() const{
  throw std::runtime_error("mus_isPF does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_isPFMuon() const{
  throw std::runtime_error("mus_isPFMuon does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_isPhoton() const{
  throw std::runtime_error("mus_isPhoton does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_isStandAloneMuon() const{
  throw std::runtime_error("mus_isStandAloneMuon does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_isTrackerMuon() const{
  throw std::runtime_error("mus_isTrackerMuon does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_iso03_emEt() const{
  throw std::runtime_error("mus_iso03_emEt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_iso03_emVetoEt() const{
  throw std::runtime_error("mus_iso03_emVetoEt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_iso03_hadEt() const{
  throw std::runtime_error("mus_iso03_hadEt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_iso03_hadVetoEt() const{
  throw std::runtime_error("mus_iso03_hadVetoEt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_iso03_hoEt() const{
  throw std::runtime_error("mus_iso03_hoEt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_iso03_nTracks() const{
  throw std::runtime_error("mus_iso03_nTracks does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_iso03_sumPt() const{
  throw std::runtime_error("mus_iso03_sumPt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_iso05_emEt() const{
  throw std::runtime_error("mus_iso05_emEt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_iso05_hadEt() const{
  throw std::runtime_error("mus_iso05_hadEt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_iso05_hoEt() const{
  throw std::runtime_error("mus_iso05_hoEt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_iso05_nTracks() const{
  throw std::runtime_error("mus_iso05_nTracks does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_iso05_sumPt() const{
  throw std::runtime_error("mus_iso05_sumPt does not exist in this cfa version.");
}

std::vector<int>* const & cfa_base::mus_jet_ind() const{
  throw std::runtime_error("mus_jet_ind does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_num_matches() const{
  throw std::runtime_error("mus_num_matches does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_numberOfMatchedStations() const{
  throw std::runtime_error("mus_numberOfMatchedStations does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_pfIsolationR03_sumChargedHadronPt() const{
  throw std::runtime_error("mus_pfIsolationR03_sumChargedHadronPt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_pfIsolationR03_sumChargedParticlePt() const{
  throw std::runtime_error("mus_pfIsolationR03_sumChargedParticlePt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_pfIsolationR03_sumNeutralHadronEt() const{
  throw std::runtime_error("mus_pfIsolationR03_sumNeutralHadronEt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_pfIsolationR03_sumNeutralHadronEtHighThreshold() const{
  throw std::runtime_error("mus_pfIsolationR03_sumNeutralHadronEtHighThreshold does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_pfIsolationR03_sumPUPt() const{
  throw std::runtime_error("mus_pfIsolationR03_sumPUPt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_pfIsolationR03_sumPhotonEt() const{
  throw std::runtime_error("mus_pfIsolationR03_sumPhotonEt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_pfIsolationR03_sumPhotonEtHighThreshold() const{
  throw std::runtime_error("mus_pfIsolationR03_sumPhotonEtHighThreshold does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_pfIsolationR04_sumChargedHadronPt() const{
  throw std::runtime_error("mus_pfIsolationR04_sumChargedHadronPt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_pfIsolationR04_sumChargedParticlePt() const{
  throw std::runtime_error("mus_pfIsolationR04_sumChargedParticlePt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_pfIsolationR04_sumNeutralHadronEt() const{
  throw std::runtime_error("mus_pfIsolationR04_sumNeutralHadronEt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_pfIsolationR04_sumNeutralHadronEtHighThreshold() const{
  throw std::runtime_error("mus_pfIsolationR04_sumNeutralHadronEtHighThreshold does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_pfIsolationR04_sumPUPt() const{
  throw std::runtime_error("mus_pfIsolationR04_sumPUPt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_pfIsolationR04_sumPhotonEt() const{
  throw std::runtime_error("mus_pfIsolationR04_sumPhotonEt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_pfIsolationR04_sumPhotonEtHighThreshold() const{
  throw std::runtime_error("mus_pfIsolationR04_sumPhotonEtHighThreshold does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_phi() const{
  throw std::runtime_error("mus_phi does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_picky_ExpectedHitsInner() const{
  throw std::runtime_error("mus_picky_ExpectedHitsInner does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_picky_ExpectedHitsOuter() const{
  throw std::runtime_error("mus_picky_ExpectedHitsOuter does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_picky_LayersWithMeasurement() const{
  throw std::runtime_error("mus_picky_LayersWithMeasurement does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_picky_LayersWithoutMeasurement() const{
  throw std::runtime_error("mus_picky_LayersWithoutMeasurement does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_picky_PixelLayersWithMeasurement() const{
  throw std::runtime_error("mus_picky_PixelLayersWithMeasurement does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_picky_ValidStripLayersWithMonoAndStereoHit() const{
  throw std::runtime_error("mus_picky_ValidStripLayersWithMonoAndStereoHit does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_picky_chg() const{
  throw std::runtime_error("mus_picky_chg does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_picky_chi2() const{
  throw std::runtime_error("mus_picky_chi2 does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_picky_d0dum() const{
  throw std::runtime_error("mus_picky_d0dum does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_picky_d0dumErr() const{
  throw std::runtime_error("mus_picky_d0dumErr does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_picky_dz() const{
  throw std::runtime_error("mus_picky_dz does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_picky_dzErr() const{
  throw std::runtime_error("mus_picky_dzErr does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_picky_eta() const{
  throw std::runtime_error("mus_picky_eta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_picky_etaErr() const{
  throw std::runtime_error("mus_picky_etaErr does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_picky_id() const{
  throw std::runtime_error("mus_picky_id does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_picky_ndof() const{
  throw std::runtime_error("mus_picky_ndof does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_picky_numlosthits() const{
  throw std::runtime_error("mus_picky_numlosthits does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_picky_numvalPixelhits() const{
  throw std::runtime_error("mus_picky_numvalPixelhits does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_picky_numvalhits() const{
  throw std::runtime_error("mus_picky_numvalhits does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_picky_phi() const{
  throw std::runtime_error("mus_picky_phi does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_picky_phiErr() const{
  throw std::runtime_error("mus_picky_phiErr does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_picky_pt() const{
  throw std::runtime_error("mus_picky_pt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_picky_ptErr() const{
  throw std::runtime_error("mus_picky_ptErr does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_picky_px() const{
  throw std::runtime_error("mus_picky_px does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_picky_py() const{
  throw std::runtime_error("mus_picky_py does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_picky_pz() const{
  throw std::runtime_error("mus_picky_pz does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_picky_theta() const{
  throw std::runtime_error("mus_picky_theta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_picky_vx() const{
  throw std::runtime_error("mus_picky_vx does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_picky_vy() const{
  throw std::runtime_error("mus_picky_vy does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_picky_vz() const{
  throw std::runtime_error("mus_picky_vz does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_pt() const{
  throw std::runtime_error("mus_pt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_px() const{
  throw std::runtime_error("mus_px does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_py() const{
  throw std::runtime_error("mus_py does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_pz() const{
  throw std::runtime_error("mus_pz does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_stamu_chg() const{
  throw std::runtime_error("mus_stamu_chg does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_stamu_chi2() const{
  throw std::runtime_error("mus_stamu_chi2 does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_stamu_d0dum() const{
  throw std::runtime_error("mus_stamu_d0dum does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_stamu_d0dumErr() const{
  throw std::runtime_error("mus_stamu_d0dumErr does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_stamu_dz() const{
  throw std::runtime_error("mus_stamu_dz does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_stamu_dzErr() const{
  throw std::runtime_error("mus_stamu_dzErr does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_stamu_eta() const{
  throw std::runtime_error("mus_stamu_eta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_stamu_etaErr() const{
  throw std::runtime_error("mus_stamu_etaErr does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_stamu_ndof() const{
  throw std::runtime_error("mus_stamu_ndof does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_stamu_numlosthits() const{
  throw std::runtime_error("mus_stamu_numlosthits does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_stamu_numvalhits() const{
  throw std::runtime_error("mus_stamu_numvalhits does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_stamu_phi() const{
  throw std::runtime_error("mus_stamu_phi does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_stamu_phiErr() const{
  throw std::runtime_error("mus_stamu_phiErr does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_stamu_pt() const{
  throw std::runtime_error("mus_stamu_pt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_stamu_ptErr() const{
  throw std::runtime_error("mus_stamu_ptErr does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_stamu_px() const{
  throw std::runtime_error("mus_stamu_px does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_stamu_py() const{
  throw std::runtime_error("mus_stamu_py does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_stamu_pz() const{
  throw std::runtime_error("mus_stamu_pz does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_stamu_theta() const{
  throw std::runtime_error("mus_stamu_theta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_stamu_vx() const{
  throw std::runtime_error("mus_stamu_vx does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_stamu_vy() const{
  throw std::runtime_error("mus_stamu_vy does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_stamu_vz() const{
  throw std::runtime_error("mus_stamu_vz does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_status() const{
  throw std::runtime_error("mus_status does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tIso() const{
  throw std::runtime_error("mus_tIso does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_theta() const{
  throw std::runtime_error("mus_theta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tkHits() const{
  throw std::runtime_error("mus_tkHits does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tk_ExpectedHitsInner() const{
  throw std::runtime_error("mus_tk_ExpectedHitsInner does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tk_ExpectedHitsOuter() const{
  throw std::runtime_error("mus_tk_ExpectedHitsOuter does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tk_LayersWithMeasurement() const{
  throw std::runtime_error("mus_tk_LayersWithMeasurement does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tk_LayersWithoutMeasurement() const{
  throw std::runtime_error("mus_tk_LayersWithoutMeasurement does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tk_PixelLayersWithMeasurement() const{
  throw std::runtime_error("mus_tk_PixelLayersWithMeasurement does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tk_ValidStripLayersWithMonoAndStereoHit() const{
  throw std::runtime_error("mus_tk_ValidStripLayersWithMonoAndStereoHit does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tk_chg() const{
  throw std::runtime_error("mus_tk_chg does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tk_chi2() const{
  throw std::runtime_error("mus_tk_chi2 does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tk_d0dum() const{
  throw std::runtime_error("mus_tk_d0dum does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tk_d0dumErr() const{
  throw std::runtime_error("mus_tk_d0dumErr does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tk_dz() const{
  throw std::runtime_error("mus_tk_dz does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tk_dzErr() const{
  throw std::runtime_error("mus_tk_dzErr does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tk_eta() const{
  throw std::runtime_error("mus_tk_eta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tk_etaErr() const{
  throw std::runtime_error("mus_tk_etaErr does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tk_id() const{
  throw std::runtime_error("mus_tk_id does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tk_ndof() const{
  throw std::runtime_error("mus_tk_ndof does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tk_numlosthits() const{
  throw std::runtime_error("mus_tk_numlosthits does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tk_numpixelWthMeasr() const{
  throw std::runtime_error("mus_tk_numpixelWthMeasr does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tk_numvalPixelhits() const{
  throw std::runtime_error("mus_tk_numvalPixelhits does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tk_numvalhits() const{
  throw std::runtime_error("mus_tk_numvalhits does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tk_phi() const{
  throw std::runtime_error("mus_tk_phi does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tk_phiErr() const{
  throw std::runtime_error("mus_tk_phiErr does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tk_pt() const{
  throw std::runtime_error("mus_tk_pt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tk_ptErr() const{
  throw std::runtime_error("mus_tk_ptErr does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tk_px() const{
  throw std::runtime_error("mus_tk_px does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tk_py() const{
  throw std::runtime_error("mus_tk_py does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tk_pz() const{
  throw std::runtime_error("mus_tk_pz does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tk_theta() const{
  throw std::runtime_error("mus_tk_theta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tk_vx() const{
  throw std::runtime_error("mus_tk_vx does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tk_vy() const{
  throw std::runtime_error("mus_tk_vy does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tk_vz() const{
  throw std::runtime_error("mus_tk_vz does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tpfms_ExpectedHitsInner() const{
  throw std::runtime_error("mus_tpfms_ExpectedHitsInner does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tpfms_ExpectedHitsOuter() const{
  throw std::runtime_error("mus_tpfms_ExpectedHitsOuter does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tpfms_LayersWithMeasurement() const{
  throw std::runtime_error("mus_tpfms_LayersWithMeasurement does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tpfms_LayersWithoutMeasurement() const{
  throw std::runtime_error("mus_tpfms_LayersWithoutMeasurement does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tpfms_PixelLayersWithMeasurement() const{
  throw std::runtime_error("mus_tpfms_PixelLayersWithMeasurement does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tpfms_ValidStripLayersWithMonoAndStereoHit() const{
  throw std::runtime_error("mus_tpfms_ValidStripLayersWithMonoAndStereoHit does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tpfms_chg() const{
  throw std::runtime_error("mus_tpfms_chg does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tpfms_chi2() const{
  throw std::runtime_error("mus_tpfms_chi2 does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tpfms_d0dum() const{
  throw std::runtime_error("mus_tpfms_d0dum does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tpfms_d0dumErr() const{
  throw std::runtime_error("mus_tpfms_d0dumErr does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tpfms_dz() const{
  throw std::runtime_error("mus_tpfms_dz does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tpfms_dzErr() const{
  throw std::runtime_error("mus_tpfms_dzErr does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tpfms_eta() const{
  throw std::runtime_error("mus_tpfms_eta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tpfms_etaErr() const{
  throw std::runtime_error("mus_tpfms_etaErr does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tpfms_id() const{
  throw std::runtime_error("mus_tpfms_id does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tpfms_ndof() const{
  throw std::runtime_error("mus_tpfms_ndof does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tpfms_numlosthits() const{
  throw std::runtime_error("mus_tpfms_numlosthits does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tpfms_numvalPixelhits() const{
  throw std::runtime_error("mus_tpfms_numvalPixelhits does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tpfms_numvalhits() const{
  throw std::runtime_error("mus_tpfms_numvalhits does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tpfms_phi() const{
  throw std::runtime_error("mus_tpfms_phi does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tpfms_phiErr() const{
  throw std::runtime_error("mus_tpfms_phiErr does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tpfms_pt() const{
  throw std::runtime_error("mus_tpfms_pt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tpfms_ptErr() const{
  throw std::runtime_error("mus_tpfms_ptErr does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tpfms_px() const{
  throw std::runtime_error("mus_tpfms_px does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tpfms_py() const{
  throw std::runtime_error("mus_tpfms_py does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tpfms_pz() const{
  throw std::runtime_error("mus_tpfms_pz does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tpfms_theta() const{
  throw std::runtime_error("mus_tpfms_theta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tpfms_vx() const{
  throw std::runtime_error("mus_tpfms_vx does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tpfms_vy() const{
  throw std::runtime_error("mus_tpfms_vy does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::mus_tpfms_vz() const{
  throw std::runtime_error("mus_tpfms_vz does not exist in this cfa version.");
}

UInt_t const & cfa_base::orbitNumber() const{
  throw std::runtime_error("orbitNumber does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::pfcand_charge() const{
  throw std::runtime_error("pfcand_charge does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::pfcand_energy() const{
  throw std::runtime_error("pfcand_energy does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::pfcand_eta() const{
  throw std::runtime_error("pfcand_eta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::pfcand_pdgId() const{
  throw std::runtime_error("pfcand_pdgId does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::pfcand_phi() const{
  throw std::runtime_error("pfcand_phi does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::pfcand_pt() const{
  throw std::runtime_error("pfcand_pt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::pfcand_px() const{
  throw std::runtime_error("pfcand_px does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::pfcand_py() const{
  throw std::runtime_error("pfcand_py does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::pfcand_pz() const{
  throw std::runtime_error("pfcand_pz does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::pfcand_theta() const{
  throw std::runtime_error("pfcand_theta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::photons_e1x5() const{
  throw std::runtime_error("photons_e1x5 does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::photons_e2x5() const{
  throw std::runtime_error("photons_e2x5 does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::photons_e3x3() const{
  throw std::runtime_error("photons_e3x3 does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::photons_e5x5() const{
  throw std::runtime_error("photons_e5x5 does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::photons_ecalIso() const{
  throw std::runtime_error("photons_ecalIso does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::photons_energy() const{
  throw std::runtime_error("photons_energy does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::photons_et() const{
  throw std::runtime_error("photons_et does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::photons_eta() const{
  throw std::runtime_error("photons_eta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::photons_gen_et() const{
  throw std::runtime_error("photons_gen_et does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::photons_gen_eta() const{
  throw std::runtime_error("photons_gen_eta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::photons_gen_id() const{
  throw std::runtime_error("photons_gen_id does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::photons_gen_phi() const{
  throw std::runtime_error("photons_gen_phi does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::photons_hadOverEM() const{
  throw std::runtime_error("photons_hadOverEM does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::photons_hadTowOverEM() const{
  throw std::runtime_error("photons_hadTowOverEM does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::photons_hasPixelSeed() const{
  throw std::runtime_error("photons_hasPixelSeed does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::photons_hcalIso() const{
  throw std::runtime_error("photons_hcalIso does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::photons_isAlsoElectron() const{
  throw std::runtime_error("photons_isAlsoElectron does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::photons_isConverted() const{
  throw std::runtime_error("photons_isConverted does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::photons_isEBEEGap() const{
  throw std::runtime_error("photons_isEBEEGap does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::photons_isEBGap() const{
  throw std::runtime_error("photons_isEBGap does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::photons_isEBPho() const{
  throw std::runtime_error("photons_isEBPho does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::photons_isEEGap() const{
  throw std::runtime_error("photons_isEEGap does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::photons_isEEPho() const{
  throw std::runtime_error("photons_isEEPho does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::photons_isLoosePhoton() const{
  throw std::runtime_error("photons_isLoosePhoton does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::photons_isTightPhoton() const{
  throw std::runtime_error("photons_isTightPhoton does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::photons_isoEcalRecHitDR03() const{
  throw std::runtime_error("photons_isoEcalRecHitDR03 does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::photons_isoEcalRecHitDR04() const{
  throw std::runtime_error("photons_isoEcalRecHitDR04 does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::photons_isoHcalRecHitDR03() const{
  throw std::runtime_error("photons_isoHcalRecHitDR03 does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::photons_isoHcalRecHitDR04() const{
  throw std::runtime_error("photons_isoHcalRecHitDR04 does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::photons_isoHollowTrkConeDR03() const{
  throw std::runtime_error("photons_isoHollowTrkConeDR03 does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::photons_isoHollowTrkConeDR04() const{
  throw std::runtime_error("photons_isoHollowTrkConeDR04 does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::photons_isoSolidTrkConeDR03() const{
  throw std::runtime_error("photons_isoSolidTrkConeDR03 does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::photons_isoSolidTrkConeDR04() const{
  throw std::runtime_error("photons_isoSolidTrkConeDR04 does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::photons_maxEnergyXtal() const{
  throw std::runtime_error("photons_maxEnergyXtal does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::photons_nTrkHollowConeDR03() const{
  throw std::runtime_error("photons_nTrkHollowConeDR03 does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::photons_nTrkHollowConeDR04() const{
  throw std::runtime_error("photons_nTrkHollowConeDR04 does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::photons_nTrkSolidConeDR03() const{
  throw std::runtime_error("photons_nTrkSolidConeDR03 does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::photons_nTrkSolidConeDR04() const{
  throw std::runtime_error("photons_nTrkSolidConeDR04 does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::photons_phi() const{
  throw std::runtime_error("photons_phi does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::photons_pt() const{
  throw std::runtime_error("photons_pt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::photons_px() const{
  throw std::runtime_error("photons_px does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::photons_py() const{
  throw std::runtime_error("photons_py does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::photons_pz() const{
  throw std::runtime_error("photons_pz does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::photons_r9() const{
  throw std::runtime_error("photons_r9 does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::photons_scEnergy() const{
  throw std::runtime_error("photons_scEnergy does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::photons_scEta() const{
  throw std::runtime_error("photons_scEta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::photons_scEtaWidth() const{
  throw std::runtime_error("photons_scEtaWidth does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::photons_scPhi() const{
  throw std::runtime_error("photons_scPhi does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::photons_scPhiWidth() const{
  throw std::runtime_error("photons_scPhiWidth does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::photons_scRawEnergy() const{
  throw std::runtime_error("photons_scRawEnergy does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::photons_sigmaEtaEta() const{
  throw std::runtime_error("photons_sigmaEtaEta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::photons_sigmaIetaIeta() const{
  throw std::runtime_error("photons_sigmaIetaIeta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::photons_status() const{
  throw std::runtime_error("photons_status does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::photons_tIso() const{
  throw std::runtime_error("photons_tIso does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::photons_theta() const{
  throw std::runtime_error("photons_theta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::pv_chi2() const{
  throw std::runtime_error("pv_chi2 does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::pv_isFake() const{
  throw std::runtime_error("pv_isFake does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::pv_isValid() const{
  throw std::runtime_error("pv_isValid does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::pv_ndof() const{
  throw std::runtime_error("pv_ndof does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::pv_tracksSize() const{
  throw std::runtime_error("pv_tracksSize does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::pv_x() const{
  throw std::runtime_error("pv_x does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::pv_xErr() const{
  throw std::runtime_error("pv_xErr does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::pv_y() const{
  throw std::runtime_error("pv_y does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::pv_yErr() const{
  throw std::runtime_error("pv_yErr does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::pv_z() const{
  throw std::runtime_error("pv_z does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::pv_zErr() const{
  throw std::runtime_error("pv_zErr does not exist in this cfa version.");
}

UInt_t const & cfa_base::run() const{
  throw std::runtime_error("run does not exist in this cfa version.");
}

std::vector<std::string>* const & cfa_base::standalone_triggerobject_collectionname() const{
  throw std::runtime_error("standalone_triggerobject_collectionname does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::standalone_triggerobject_energy() const{
  throw std::runtime_error("standalone_triggerobject_energy does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::standalone_triggerobject_et() const{
  throw std::runtime_error("standalone_triggerobject_et does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::standalone_triggerobject_eta() const{
  throw std::runtime_error("standalone_triggerobject_eta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::standalone_triggerobject_phi() const{
  throw std::runtime_error("standalone_triggerobject_phi does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::standalone_triggerobject_pt() const{
  throw std::runtime_error("standalone_triggerobject_pt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::standalone_triggerobject_px() const{
  throw std::runtime_error("standalone_triggerobject_px does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::standalone_triggerobject_py() const{
  throw std::runtime_error("standalone_triggerobject_py does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::standalone_triggerobject_pz() const{
  throw std::runtime_error("standalone_triggerobject_pz does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_Nprongs() const{
  throw std::runtime_error("taus_Nprongs does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_againstElectron() const{
  throw std::runtime_error("taus_againstElectron does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_againstElectronLoose() const{
  throw std::runtime_error("taus_againstElectronLoose does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_againstElectronMVA() const{
  throw std::runtime_error("taus_againstElectronMVA does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_againstElectronMedium() const{
  throw std::runtime_error("taus_againstElectronMedium does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_againstElectronTight() const{
  throw std::runtime_error("taus_againstElectronTight does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_againstMuon() const{
  throw std::runtime_error("taus_againstMuon does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_againstMuonLoose() const{
  throw std::runtime_error("taus_againstMuonLoose does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_againstMuonMedium() const{
  throw std::runtime_error("taus_againstMuonMedium does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_againstMuonTight() const{
  throw std::runtime_error("taus_againstMuonTight does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_byIsoUsingLeadingPi() const{
  throw std::runtime_error("taus_byIsoUsingLeadingPi does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_byIsolation() const{
  throw std::runtime_error("taus_byIsolation does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_byLooseIsolation() const{
  throw std::runtime_error("taus_byLooseIsolation does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_byLooseIsolationDeltaBetaCorr() const{
  throw std::runtime_error("taus_byLooseIsolationDeltaBetaCorr does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_byMediumIsolation() const{
  throw std::runtime_error("taus_byMediumIsolation does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_byMediumIsolationDeltaBetaCorr() const{
  throw std::runtime_error("taus_byMediumIsolationDeltaBetaCorr does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_byTightIsolation() const{
  throw std::runtime_error("taus_byTightIsolation does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_byTightIsolationDeltaBetaCorr() const{
  throw std::runtime_error("taus_byTightIsolationDeltaBetaCorr does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_byVLooseIsolation() const{
  throw std::runtime_error("taus_byVLooseIsolation does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_byVLooseIsolationDeltaBetaCorr() const{
  throw std::runtime_error("taus_byVLooseIsolationDeltaBetaCorr does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_charge() const{
  throw std::runtime_error("taus_charge does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_decayModeFinding() const{
  throw std::runtime_error("taus_decayModeFinding does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_ecalIsoUsingLeadingPi() const{
  throw std::runtime_error("taus_ecalIsoUsingLeadingPi does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_ecalIsolation() const{
  throw std::runtime_error("taus_ecalIsolation does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_ecalStripSumEOverPLead() const{
  throw std::runtime_error("taus_ecalStripSumEOverPLead does not exist in this cfa version.");
}

std::vector<int>* const & cfa_base::taus_el_ind() const{
  throw std::runtime_error("taus_el_ind does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_elecPreIdDecision() const{
  throw std::runtime_error("taus_elecPreIdDecision does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_elecPreIdOutput() const{
  throw std::runtime_error("taus_elecPreIdOutput does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_emf() const{
  throw std::runtime_error("taus_emf does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_energy() const{
  throw std::runtime_error("taus_energy does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_et() const{
  throw std::runtime_error("taus_et does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_eta() const{
  throw std::runtime_error("taus_eta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_hcal3x3OverPLead() const{
  throw std::runtime_error("taus_hcal3x3OverPLead does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_hcalMaxOverPLead() const{
  throw std::runtime_error("taus_hcalMaxOverPLead does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_hcalTotOverPLead() const{
  throw std::runtime_error("taus_hcalTotOverPLead does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_isoPFChargedHadrCandsPtSum() const{
  throw std::runtime_error("taus_isoPFChargedHadrCandsPtSum does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_isoPFGammaCandsEtSum() const{
  throw std::runtime_error("taus_isoPFGammaCandsEtSum does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_leadPFChargedHadrCand_ECAL_eta() const{
  throw std::runtime_error("taus_leadPFChargedHadrCand_ECAL_eta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_leadPFChargedHadrCand_charge() const{
  throw std::runtime_error("taus_leadPFChargedHadrCand_charge does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_leadPFChargedHadrCand_eta() const{
  throw std::runtime_error("taus_leadPFChargedHadrCand_eta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_leadPFChargedHadrCand_phi() const{
  throw std::runtime_error("taus_leadPFChargedHadrCand_phi does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_leadPFChargedHadrCand_pt() const{
  throw std::runtime_error("taus_leadPFChargedHadrCand_pt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_leadingTrackFinding() const{
  throw std::runtime_error("taus_leadingTrackFinding does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_leadingTrackPtCut() const{
  throw std::runtime_error("taus_leadingTrackPtCut does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_muDecision() const{
  throw std::runtime_error("taus_muDecision does not exist in this cfa version.");
}

std::vector<int>* const & cfa_base::taus_mu_ind() const{
  throw std::runtime_error("taus_mu_ind does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_phi() const{
  throw std::runtime_error("taus_phi does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_pt() const{
  throw std::runtime_error("taus_pt does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_px() const{
  throw std::runtime_error("taus_px does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_py() const{
  throw std::runtime_error("taus_py does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_pz() const{
  throw std::runtime_error("taus_pz does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_signalPFChargedHadrCandsSize() const{
  throw std::runtime_error("taus_signalPFChargedHadrCandsSize does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_status() const{
  throw std::runtime_error("taus_status does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_taNC() const{
  throw std::runtime_error("taus_taNC does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_taNC_half() const{
  throw std::runtime_error("taus_taNC_half does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_taNC_one() const{
  throw std::runtime_error("taus_taNC_one does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_taNC_quarter() const{
  throw std::runtime_error("taus_taNC_quarter does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_taNC_tenth() const{
  throw std::runtime_error("taus_taNC_tenth does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_theta() const{
  throw std::runtime_error("taus_theta does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_tkIsoUsingLeadingPi() const{
  throw std::runtime_error("taus_tkIsoUsingLeadingPi does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::taus_trackIsolation() const{
  throw std::runtime_error("taus_trackIsolation does not exist in this cfa version.");
}

Int_t const & cfa_base::trackingfailurefilter_decision() const{
  throw std::runtime_error("trackingfailurefilter_decision does not exist in this cfa version.");
}

std::vector<bool>* const & cfa_base::trigger_decision() const{
  throw std::runtime_error("trigger_decision does not exist in this cfa version.");
}

std::vector<std::string>* const & cfa_base::trigger_name() const{
  throw std::runtime_error("trigger_name does not exist in this cfa version.");
}

std::vector<float>* const & cfa_base::trigger_prescalevalue() const{
  throw std::runtime_error("trigger_prescalevalue does not exist in this cfa version.");
}

Int_t const & cfa_base::trkPOG_logErrorTooManyClustersfilter_decision() const{
  throw std::runtime_error("trkPOG_logErrorTooManyClustersfilter_decision does not exist in this cfa version.");
}

Int_t const & cfa_base::trkPOG_manystripclus53Xfilter_decision() const{
  throw std::runtime_error("trkPOG_manystripclus53Xfilter_decision does not exist in this cfa version.");
}

Int_t const & cfa_base::trkPOG_toomanystripclus53Xfilter_decision() const{
  throw std::runtime_error("trkPOG_toomanystripclus53Xfilter_decision does not exist in this cfa version.");
}

Int_t const & cfa_base::trkPOGfilter_decision() const{
  throw std::runtime_error("trkPOGfilter_decision does not exist in this cfa version.");
}

Float_t const & cfa_base::weight() const{
  throw std::runtime_error("weight does not exist in this cfa version.");
}

