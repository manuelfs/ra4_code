#include "cfa.hpp"

#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>

#include "TChain.h"

#include "cfa_base.hpp"
#include "cfa_8.hpp"
#include "cfa_13.hpp"

cfa::cfa(const std::string &file, const bool is_8TeV):
  cfa_( is_8TeV ? static_cast<cfa_base*>(new cfa_8(file)) : static_cast<cfa_base*>(new cfa_13(file)) ){
}

long cfa::TotalEntries() const{
  return cfa_->TotalEntries();
}

void cfa::GetEntry(const long entry){
  cfa_->GetEntry(entry);
}

short cfa::GetVersion() const{
  return cfa_->GetVersion();
}

const std::string& cfa::SampleName() const{
  return cfa_->SampleName();
}

const std::string& cfa::SampleName(const std::string &sample_name){
  return cfa_->SampleName(sample_name);
}

void cfa::SetFile(const std::string &file, const bool is_8TeV){
  delete cfa_; cfa_=NULL;
  cfa_ = ( is_8TeV ? static_cast<cfa_base*>(new cfa_8(file)) : static_cast<cfa_base*>(new cfa_13(file)) );
}

void cfa::AddFiles(const std::string &file){
  cfa_->AddFiles(file);
}

cfa::~cfa(){
  delete cfa_; cfa_=NULL;
}

Int_t const & cfa::EcalDeadCellTriggerPrimitivefilter_decision() const{
  return cfa_->EcalDeadCellTriggerPrimitivefilter_decision();
}

Int_t const & cfa::HBHENoisefilter_decision() const{
  return cfa_->HBHENoisefilter_decision();
}

Int_t const & cfa::METFiltersfilter_decision() const{
  return cfa_->METFiltersfilter_decision();
}

UInt_t const & cfa::NbeamSpot() const{
  return cfa_->NbeamSpot();
}

UInt_t const & cfa::Nels() const{
  return cfa_->Nels();
}

UInt_t const & cfa::Njets_AK4() const{
  return cfa_->Njets_AK4();
}

UInt_t const & cfa::Nmc_doc() const{
  return cfa_->Nmc_doc();
}

UInt_t const & cfa::Nmc_electrons() const{
  return cfa_->Nmc_electrons();
}

UInt_t const & cfa::Nmc_final() const{
  return cfa_->Nmc_final();
}

UInt_t const & cfa::Nmc_jets() const{
  return cfa_->Nmc_jets();
}

UInt_t const & cfa::Nmc_mus() const{
  return cfa_->Nmc_mus();
}

UInt_t const & cfa::Nmc_nues() const{
  return cfa_->Nmc_nues();
}

UInt_t const & cfa::Nmc_numus() const{
  return cfa_->Nmc_numus();
}

UInt_t const & cfa::Nmc_nutaus() const{
  return cfa_->Nmc_nutaus();
}

UInt_t const & cfa::Nmc_photons() const{
  return cfa_->Nmc_photons();
}

UInt_t const & cfa::Nmc_taus() const{
  return cfa_->Nmc_taus();
}

UInt_t const & cfa::Nmets() const{
  return cfa_->Nmets();
}

UInt_t const & cfa::Nmus() const{
  return cfa_->Nmus();
}

UInt_t const & cfa::Npfcand() const{
  return cfa_->Npfcand();
}

UInt_t const & cfa::Nphotons() const{
  return cfa_->Nphotons();
}

UInt_t const & cfa::Npv() const{
  return cfa_->Npv();
}

UInt_t const & cfa::Ntaus() const{
  return cfa_->Ntaus();
}

std::vector<int>* const & cfa::PU_NumInteractions() const{
  return cfa_->PU_NumInteractions();
}

std::vector<float>* const & cfa::PU_TrueNumInteractions() const{
  return cfa_->PU_TrueNumInteractions();
}

std::vector<int>* const & cfa::PU_bunchCrossing() const{
  return cfa_->PU_bunchCrossing();
}

std::vector<std::vector<int> >* const & cfa::PU_ntrks_highpT() const{
  return cfa_->PU_ntrks_highpT();
}

std::vector<std::vector<int> >* const & cfa::PU_ntrks_lowpT() const{
  return cfa_->PU_ntrks_lowpT();
}

std::vector<std::vector<float> >* const & cfa::PU_sumpT_highpT() const{
  return cfa_->PU_sumpT_highpT();
}

std::vector<std::vector<float> >* const & cfa::PU_sumpT_lowpT() const{
  return cfa_->PU_sumpT_lowpT();
}

std::vector<std::vector<float> >* const & cfa::PU_zpositions() const{
  return cfa_->PU_zpositions();
}

std::vector<float>* const & cfa::beamSpot_beamWidthX() const{
  return cfa_->beamSpot_beamWidthX();
}

std::vector<float>* const & cfa::beamSpot_beamWidthXError() const{
  return cfa_->beamSpot_beamWidthXError();
}

std::vector<float>* const & cfa::beamSpot_beamWidthY() const{
  return cfa_->beamSpot_beamWidthY();
}

std::vector<float>* const & cfa::beamSpot_beamWidthYError() const{
  return cfa_->beamSpot_beamWidthYError();
}

std::vector<float>* const & cfa::beamSpot_dxdz() const{
  return cfa_->beamSpot_dxdz();
}

std::vector<float>* const & cfa::beamSpot_dxdzError() const{
  return cfa_->beamSpot_dxdzError();
}

std::vector<float>* const & cfa::beamSpot_dydz() const{
  return cfa_->beamSpot_dydz();
}

std::vector<float>* const & cfa::beamSpot_dydzError() const{
  return cfa_->beamSpot_dydzError();
}

std::vector<float>* const & cfa::beamSpot_sigmaZ() const{
  return cfa_->beamSpot_sigmaZ();
}

std::vector<float>* const & cfa::beamSpot_sigmaZ0Error() const{
  return cfa_->beamSpot_sigmaZ0Error();
}

std::vector<float>* const & cfa::beamSpot_x() const{
  return cfa_->beamSpot_x();
}

std::vector<float>* const & cfa::beamSpot_x0Error() const{
  return cfa_->beamSpot_x0Error();
}

std::vector<float>* const & cfa::beamSpot_y() const{
  return cfa_->beamSpot_y();
}

std::vector<float>* const & cfa::beamSpot_y0Error() const{
  return cfa_->beamSpot_y0Error();
}

std::vector<float>* const & cfa::beamSpot_z() const{
  return cfa_->beamSpot_z();
}

std::vector<float>* const & cfa::beamSpot_z0Error() const{
  return cfa_->beamSpot_z0Error();
}

UInt_t const & cfa::bunchCrossing() const{
  return cfa_->bunchCrossing();
}

Int_t const & cfa::cschalofilter_decision() const{
  return cfa_->cschalofilter_decision();
}

Int_t const & cfa::ecallaserfilter_decision() const{
  return cfa_->ecallaserfilter_decision();
}

Int_t const & cfa::eebadscfilter_decision() const{
  return cfa_->eebadscfilter_decision();
}

std::vector<float>* const & cfa::els_PATpassConversionVeto() const{
  return cfa_->els_PATpassConversionVeto();
}

std::vector<float>* const & cfa::els_basicClustersSize() const{
  return cfa_->els_basicClustersSize();
}

std::vector<float>* const & cfa::els_cIso() const{
  return cfa_->els_cIso();
}

std::vector<float>* const & cfa::els_caloEnergy() const{
  return cfa_->els_caloEnergy();
}

std::vector<float>* const & cfa::els_charge() const{
  return cfa_->els_charge();
}

std::vector<float>* const & cfa::els_chi2() const{
  return cfa_->els_chi2();
}

std::vector<float>* const & cfa::els_core_ecalDrivenSeed() const{
  return cfa_->els_core_ecalDrivenSeed();
}

std::vector<float>* const & cfa::els_cpx() const{
  return cfa_->els_cpx();
}

std::vector<float>* const & cfa::els_cpy() const{
  return cfa_->els_cpy();
}

std::vector<float>* const & cfa::els_cpz() const{
  return cfa_->els_cpz();
}

std::vector<float>* const & cfa::els_ctf_tk_charge() const{
  return cfa_->els_ctf_tk_charge();
}

std::vector<float>* const & cfa::els_ctf_tk_eta() const{
  return cfa_->els_ctf_tk_eta();
}

std::vector<float>* const & cfa::els_ctf_tk_id() const{
  return cfa_->els_ctf_tk_id();
}

std::vector<float>* const & cfa::els_ctf_tk_phi() const{
  return cfa_->els_ctf_tk_phi();
}

std::vector<float>* const & cfa::els_cx() const{
  return cfa_->els_cx();
}

std::vector<float>* const & cfa::els_cy() const{
  return cfa_->els_cy();
}

std::vector<float>* const & cfa::els_cz() const{
  return cfa_->els_cz();
}

std::vector<float>* const & cfa::els_d0dum() const{
  return cfa_->els_d0dum();
}

std::vector<float>* const & cfa::els_d0dumError() const{
  return cfa_->els_d0dumError();
}

std::vector<float>* const & cfa::els_dEtaIn() const{
  return cfa_->els_dEtaIn();
}

std::vector<float>* const & cfa::els_dEtaOut() const{
  return cfa_->els_dEtaOut();
}

std::vector<float>* const & cfa::els_dPhiIn() const{
  return cfa_->els_dPhiIn();
}

std::vector<float>* const & cfa::els_dPhiOut() const{
  return cfa_->els_dPhiOut();
}

std::vector<float>* const & cfa::els_dr03EcalRecHitSumEt() const{
  return cfa_->els_dr03EcalRecHitSumEt();
}

std::vector<float>* const & cfa::els_dr03HcalDepth1TowerSumEt() const{
  return cfa_->els_dr03HcalDepth1TowerSumEt();
}

std::vector<float>* const & cfa::els_dr03HcalDepth2TowerSumEt() const{
  return cfa_->els_dr03HcalDepth2TowerSumEt();
}

std::vector<float>* const & cfa::els_dr03HcalTowerSumEt() const{
  return cfa_->els_dr03HcalTowerSumEt();
}

std::vector<float>* const & cfa::els_dr03TkSumPt() const{
  return cfa_->els_dr03TkSumPt();
}

std::vector<float>* const & cfa::els_dr04EcalRecHitSumEt() const{
  return cfa_->els_dr04EcalRecHitSumEt();
}

std::vector<float>* const & cfa::els_dr04HcalDepth1TowerSumEt() const{
  return cfa_->els_dr04HcalDepth1TowerSumEt();
}

std::vector<float>* const & cfa::els_dr04HcalDepth2TowerSumEt() const{
  return cfa_->els_dr04HcalDepth2TowerSumEt();
}

std::vector<float>* const & cfa::els_dr04HcalTowerSumEt() const{
  return cfa_->els_dr04HcalTowerSumEt();
}

std::vector<float>* const & cfa::els_dr04TkSumPt() const{
  return cfa_->els_dr04TkSumPt();
}

std::vector<float>* const & cfa::els_dz() const{
  return cfa_->els_dz();
}

std::vector<float>* const & cfa::els_dzError() const{
  return cfa_->els_dzError();
}

std::vector<float>* const & cfa::els_eOverPIn() const{
  return cfa_->els_eOverPIn();
}

std::vector<float>* const & cfa::els_eSeedOverPOut() const{
  return cfa_->els_eSeedOverPOut();
}

std::vector<float>* const & cfa::els_ecalIso() const{
  return cfa_->els_ecalIso();
}

std::vector<float>* const & cfa::els_energy() const{
  return cfa_->els_energy();
}

std::vector<float>* const & cfa::els_et() const{
  return cfa_->els_et();
}

std::vector<float>* const & cfa::els_eta() const{
  return cfa_->els_eta();
}

std::vector<float>* const & cfa::els_etaError() const{
  return cfa_->els_etaError();
}

std::vector<float>* const & cfa::els_fbrem() const{
  return cfa_->els_fbrem();
}

std::vector<float>* const & cfa::els_full5x5_sigmaIetaIeta() const{
  return cfa_->els_full5x5_sigmaIetaIeta();
}

std::vector<float>* const & cfa::els_gen_et() const{
  return cfa_->els_gen_et();
}

std::vector<float>* const & cfa::els_gen_eta() const{
  return cfa_->els_gen_eta();
}

std::vector<float>* const & cfa::els_gen_id() const{
  return cfa_->els_gen_id();
}

std::vector<float>* const & cfa::els_gen_mother_et() const{
  return cfa_->els_gen_mother_et();
}

std::vector<float>* const & cfa::els_gen_mother_eta() const{
  return cfa_->els_gen_mother_eta();
}

std::vector<float>* const & cfa::els_gen_mother_id() const{
  return cfa_->els_gen_mother_id();
}

std::vector<float>* const & cfa::els_gen_mother_phi() const{
  return cfa_->els_gen_mother_phi();
}

std::vector<float>* const & cfa::els_gen_mother_pt() const{
  return cfa_->els_gen_mother_pt();
}

std::vector<float>* const & cfa::els_gen_mother_px() const{
  return cfa_->els_gen_mother_px();
}

std::vector<float>* const & cfa::els_gen_mother_py() const{
  return cfa_->els_gen_mother_py();
}

std::vector<float>* const & cfa::els_gen_mother_pz() const{
  return cfa_->els_gen_mother_pz();
}

std::vector<float>* const & cfa::els_gen_mother_theta() const{
  return cfa_->els_gen_mother_theta();
}

std::vector<float>* const & cfa::els_gen_phi() const{
  return cfa_->els_gen_phi();
}

std::vector<float>* const & cfa::els_gen_pt() const{
  return cfa_->els_gen_pt();
}

std::vector<float>* const & cfa::els_gen_px() const{
  return cfa_->els_gen_px();
}

std::vector<float>* const & cfa::els_gen_py() const{
  return cfa_->els_gen_py();
}

std::vector<float>* const & cfa::els_gen_pz() const{
  return cfa_->els_gen_pz();
}

std::vector<float>* const & cfa::els_gen_theta() const{
  return cfa_->els_gen_theta();
}

std::vector<float>* const & cfa::els_hadOverEm() const{
  return cfa_->els_hadOverEm();
}

std::vector<float>* const & cfa::els_hcalIso() const{
  return cfa_->els_hcalIso();
}

std::vector<float>* const & cfa::els_hcalOverEcalBc() const{
  return cfa_->els_hcalOverEcalBc();
}

std::vector<float>* const & cfa::els_isEB() const{
  return cfa_->els_isEB();
}

std::vector<float>* const & cfa::els_isEE() const{
  return cfa_->els_isEE();
}

std::vector<bool>* const & cfa::els_isPF() const{
  return cfa_->els_isPF();
}

std::vector<int>* const & cfa::els_jet_ind() const{
  return cfa_->els_jet_ind();
}

std::vector<float>* const & cfa::els_looseId() const{
  return cfa_->els_looseId();
}

std::vector<float>* const & cfa::els_n_inner_layer() const{
  return cfa_->els_n_inner_layer();
}

std::vector<float>* const & cfa::els_n_outer_layer() const{
  return cfa_->els_n_outer_layer();
}

std::vector<float>* const & cfa::els_ndof() const{
  return cfa_->els_ndof();
}

std::vector<float>* const & cfa::els_numlosthits() const{
  return cfa_->els_numlosthits();
}

std::vector<float>* const & cfa::els_numvalhits() const{
  return cfa_->els_numvalhits();
}

std::vector<float>* const & cfa::els_pfIsolationR03_sumChargedHadronPt() const{
  return cfa_->els_pfIsolationR03_sumChargedHadronPt();
}

std::vector<float>* const & cfa::els_pfIsolationR03_sumNeutralHadronEt() const{
  return cfa_->els_pfIsolationR03_sumNeutralHadronEt();
}

std::vector<float>* const & cfa::els_pfIsolationR03_sumPUPt() const{
  return cfa_->els_pfIsolationR03_sumPUPt();
}

std::vector<float>* const & cfa::els_pfIsolationR03_sumPhotonEt() const{
  return cfa_->els_pfIsolationR03_sumPhotonEt();
}

std::vector<float>* const & cfa::els_phi() const{
  return cfa_->els_phi();
}

std::vector<float>* const & cfa::els_phiError() const{
  return cfa_->els_phiError();
}

std::vector<float>* const & cfa::els_pt() const{
  return cfa_->els_pt();
}

std::vector<float>* const & cfa::els_ptError() const{
  return cfa_->els_ptError();
}

std::vector<float>* const & cfa::els_px() const{
  return cfa_->els_px();
}

std::vector<float>* const & cfa::els_py() const{
  return cfa_->els_py();
}

std::vector<float>* const & cfa::els_pz() const{
  return cfa_->els_pz();
}

std::vector<float>* const & cfa::els_robustHighEnergyId() const{
  return cfa_->els_robustHighEnergyId();
}

std::vector<float>* const & cfa::els_robustLooseId() const{
  return cfa_->els_robustLooseId();
}

std::vector<float>* const & cfa::els_robustTightId() const{
  return cfa_->els_robustTightId();
}

std::vector<float>* const & cfa::els_scE1x5() const{
  return cfa_->els_scE1x5();
}

std::vector<float>* const & cfa::els_scE2x5Max() const{
  return cfa_->els_scE2x5Max();
}

std::vector<float>* const & cfa::els_scE5x5() const{
  return cfa_->els_scE5x5();
}

std::vector<float>* const & cfa::els_scEnergy() const{
  return cfa_->els_scEnergy();
}

std::vector<float>* const & cfa::els_scEta() const{
  return cfa_->els_scEta();
}

std::vector<float>* const & cfa::els_scEtaWidth() const{
  return cfa_->els_scEtaWidth();
}

std::vector<float>* const & cfa::els_scPhi() const{
  return cfa_->els_scPhi();
}

std::vector<float>* const & cfa::els_scPhiWidth() const{
  return cfa_->els_scPhiWidth();
}

std::vector<float>* const & cfa::els_scRawEnergy() const{
  return cfa_->els_scRawEnergy();
}

std::vector<float>* const & cfa::els_scSeedEnergy() const{
  return cfa_->els_scSeedEnergy();
}

std::vector<float>* const & cfa::els_shFracInnerHits() const{
  return cfa_->els_shFracInnerHits();
}

std::vector<float>* const & cfa::els_sigmaEtaEta() const{
  return cfa_->els_sigmaEtaEta();
}

std::vector<float>* const & cfa::els_sigmaIEtaIEta() const{
  return cfa_->els_sigmaIEtaIEta();
}

std::vector<float>* const & cfa::els_simpleEleId60cIso() const{
  return cfa_->els_simpleEleId60cIso();
}

std::vector<float>* const & cfa::els_simpleEleId60relIso() const{
  return cfa_->els_simpleEleId60relIso();
}

std::vector<float>* const & cfa::els_simpleEleId70cIso() const{
  return cfa_->els_simpleEleId70cIso();
}

std::vector<float>* const & cfa::els_simpleEleId70relIso() const{
  return cfa_->els_simpleEleId70relIso();
}

std::vector<float>* const & cfa::els_simpleEleId80cIso() const{
  return cfa_->els_simpleEleId80cIso();
}

std::vector<float>* const & cfa::els_simpleEleId80relIso() const{
  return cfa_->els_simpleEleId80relIso();
}

std::vector<float>* const & cfa::els_simpleEleId85cIso() const{
  return cfa_->els_simpleEleId85cIso();
}

std::vector<float>* const & cfa::els_simpleEleId85relIso() const{
  return cfa_->els_simpleEleId85relIso();
}

std::vector<float>* const & cfa::els_simpleEleId90cIso() const{
  return cfa_->els_simpleEleId90cIso();
}

std::vector<float>* const & cfa::els_simpleEleId90relIso() const{
  return cfa_->els_simpleEleId90relIso();
}

std::vector<float>* const & cfa::els_simpleEleId95cIso() const{
  return cfa_->els_simpleEleId95cIso();
}

std::vector<float>* const & cfa::els_simpleEleId95relIso() const{
  return cfa_->els_simpleEleId95relIso();
}

std::vector<float>* const & cfa::els_status() const{
  return cfa_->els_status();
}

std::vector<float>* const & cfa::els_tIso() const{
  return cfa_->els_tIso();
}

std::vector<float>* const & cfa::els_theta() const{
  return cfa_->els_theta();
}

std::vector<float>* const & cfa::els_tightId() const{
  return cfa_->els_tightId();
}

std::vector<float>* const & cfa::els_tk_charge() const{
  return cfa_->els_tk_charge();
}

std::vector<float>* const & cfa::els_tk_eta() const{
  return cfa_->els_tk_eta();
}

std::vector<float>* const & cfa::els_tk_phi() const{
  return cfa_->els_tk_phi();
}

std::vector<float>* const & cfa::els_tk_pt() const{
  return cfa_->els_tk_pt();
}

std::vector<float>* const & cfa::els_tk_pz() const{
  return cfa_->els_tk_pz();
}

std::vector<float>* const & cfa::els_vpx() const{
  return cfa_->els_vpx();
}

std::vector<float>* const & cfa::els_vpy() const{
  return cfa_->els_vpy();
}

std::vector<float>* const & cfa::els_vpz() const{
  return cfa_->els_vpz();
}

std::vector<float>* const & cfa::els_vx() const{
  return cfa_->els_vx();
}

std::vector<float>* const & cfa::els_vy() const{
  return cfa_->els_vy();
}

std::vector<float>* const & cfa::els_vz() const{
  return cfa_->els_vz();
}

UInt_t const & cfa::event() const{
  return cfa_->event();
}

UInt_t const & cfa::experimentType() const{
  return cfa_->experimentType();
}

std::vector<float>* const & cfa::fastjets_AK4_R1p2_R0p5pT10_energy() const{
  return cfa_->fastjets_AK4_R1p2_R0p5pT10_energy();
}

std::vector<float>* const & cfa::fastjets_AK4_R1p2_R0p5pT10_eta() const{
  return cfa_->fastjets_AK4_R1p2_R0p5pT10_eta();
}

std::vector<std::vector<int> >* const & cfa::fastjets_AK4_R1p2_R0p5pT10_index() const{
  return cfa_->fastjets_AK4_R1p2_R0p5pT10_index();
}

std::vector<int>* const & cfa::fastjets_AK4_R1p2_R0p5pT10_nconstituents() const{
  return cfa_->fastjets_AK4_R1p2_R0p5pT10_nconstituents();
}

std::vector<float>* const & cfa::fastjets_AK4_R1p2_R0p5pT10_phi() const{
  return cfa_->fastjets_AK4_R1p2_R0p5pT10_phi();
}

std::vector<float>* const & cfa::fastjets_AK4_R1p2_R0p5pT10_px() const{
  return cfa_->fastjets_AK4_R1p2_R0p5pT10_px();
}

std::vector<float>* const & cfa::fastjets_AK4_R1p2_R0p5pT10_py() const{
  return cfa_->fastjets_AK4_R1p2_R0p5pT10_py();
}

std::vector<float>* const & cfa::fastjets_AK4_R1p2_R0p5pT10_pz() const{
  return cfa_->fastjets_AK4_R1p2_R0p5pT10_pz();
}

std::vector<float>* const & cfa::fastjets_AK4_R1p2_R0p5pT15_energy() const{
  return cfa_->fastjets_AK4_R1p2_R0p5pT15_energy();
}

std::vector<float>* const & cfa::fastjets_AK4_R1p2_R0p5pT15_eta() const{
  return cfa_->fastjets_AK4_R1p2_R0p5pT15_eta();
}

std::vector<std::vector<int> >* const & cfa::fastjets_AK4_R1p2_R0p5pT15_index() const{
  return cfa_->fastjets_AK4_R1p2_R0p5pT15_index();
}

std::vector<int>* const & cfa::fastjets_AK4_R1p2_R0p5pT15_nconstituents() const{
  return cfa_->fastjets_AK4_R1p2_R0p5pT15_nconstituents();
}

std::vector<float>* const & cfa::fastjets_AK4_R1p2_R0p5pT15_phi() const{
  return cfa_->fastjets_AK4_R1p2_R0p5pT15_phi();
}

std::vector<float>* const & cfa::fastjets_AK4_R1p2_R0p5pT15_px() const{
  return cfa_->fastjets_AK4_R1p2_R0p5pT15_px();
}

std::vector<float>* const & cfa::fastjets_AK4_R1p2_R0p5pT15_py() const{
  return cfa_->fastjets_AK4_R1p2_R0p5pT15_py();
}

std::vector<float>* const & cfa::fastjets_AK4_R1p2_R0p5pT15_pz() const{
  return cfa_->fastjets_AK4_R1p2_R0p5pT15_pz();
}

std::vector<float>* const & cfa::fastjets_AK4_R1p2_R0p5pT20_energy() const{
  return cfa_->fastjets_AK4_R1p2_R0p5pT20_energy();
}

std::vector<float>* const & cfa::fastjets_AK4_R1p2_R0p5pT20_eta() const{
  return cfa_->fastjets_AK4_R1p2_R0p5pT20_eta();
}

std::vector<std::vector<int> >* const & cfa::fastjets_AK4_R1p2_R0p5pT20_index() const{
  return cfa_->fastjets_AK4_R1p2_R0p5pT20_index();
}

std::vector<int>* const & cfa::fastjets_AK4_R1p2_R0p5pT20_nconstituents() const{
  return cfa_->fastjets_AK4_R1p2_R0p5pT20_nconstituents();
}

std::vector<float>* const & cfa::fastjets_AK4_R1p2_R0p5pT20_phi() const{
  return cfa_->fastjets_AK4_R1p2_R0p5pT20_phi();
}

std::vector<float>* const & cfa::fastjets_AK4_R1p2_R0p5pT20_px() const{
  return cfa_->fastjets_AK4_R1p2_R0p5pT20_px();
}

std::vector<float>* const & cfa::fastjets_AK4_R1p2_R0p5pT20_py() const{
  return cfa_->fastjets_AK4_R1p2_R0p5pT20_py();
}

std::vector<float>* const & cfa::fastjets_AK4_R1p2_R0p5pT20_pz() const{
  return cfa_->fastjets_AK4_R1p2_R0p5pT20_pz();
}

std::vector<float>* const & cfa::fastjets_AK4_R1p2_R0p5pT25_energy() const{
  return cfa_->fastjets_AK4_R1p2_R0p5pT25_energy();
}

std::vector<float>* const & cfa::fastjets_AK4_R1p2_R0p5pT25_eta() const{
  return cfa_->fastjets_AK4_R1p2_R0p5pT25_eta();
}

std::vector<std::vector<int> >* const & cfa::fastjets_AK4_R1p2_R0p5pT25_index() const{
  return cfa_->fastjets_AK4_R1p2_R0p5pT25_index();
}

std::vector<int>* const & cfa::fastjets_AK4_R1p2_R0p5pT25_nconstituents() const{
  return cfa_->fastjets_AK4_R1p2_R0p5pT25_nconstituents();
}

std::vector<float>* const & cfa::fastjets_AK4_R1p2_R0p5pT25_phi() const{
  return cfa_->fastjets_AK4_R1p2_R0p5pT25_phi();
}

std::vector<float>* const & cfa::fastjets_AK4_R1p2_R0p5pT25_px() const{
  return cfa_->fastjets_AK4_R1p2_R0p5pT25_px();
}

std::vector<float>* const & cfa::fastjets_AK4_R1p2_R0p5pT25_py() const{
  return cfa_->fastjets_AK4_R1p2_R0p5pT25_py();
}

std::vector<float>* const & cfa::fastjets_AK4_R1p2_R0p5pT25_pz() const{
  return cfa_->fastjets_AK4_R1p2_R0p5pT25_pz();
}

std::vector<float>* const & cfa::fastjets_AK4_R1p2_R0p5pT30_energy() const{
  return cfa_->fastjets_AK4_R1p2_R0p5pT30_energy();
}

std::vector<float>* const & cfa::fastjets_AK4_R1p2_R0p5pT30_eta() const{
  return cfa_->fastjets_AK4_R1p2_R0p5pT30_eta();
}

std::vector<std::vector<int> >* const & cfa::fastjets_AK4_R1p2_R0p5pT30_index() const{
  return cfa_->fastjets_AK4_R1p2_R0p5pT30_index();
}

std::vector<int>* const & cfa::fastjets_AK4_R1p2_R0p5pT30_nconstituents() const{
  return cfa_->fastjets_AK4_R1p2_R0p5pT30_nconstituents();
}

std::vector<float>* const & cfa::fastjets_AK4_R1p2_R0p5pT30_phi() const{
  return cfa_->fastjets_AK4_R1p2_R0p5pT30_phi();
}

std::vector<float>* const & cfa::fastjets_AK4_R1p2_R0p5pT30_px() const{
  return cfa_->fastjets_AK4_R1p2_R0p5pT30_px();
}

std::vector<float>* const & cfa::fastjets_AK4_R1p2_R0p5pT30_py() const{
  return cfa_->fastjets_AK4_R1p2_R0p5pT30_py();
}

std::vector<float>* const & cfa::fastjets_AK4_R1p2_R0p5pT30_pz() const{
  return cfa_->fastjets_AK4_R1p2_R0p5pT30_pz();
}

Int_t const & cfa::goodVerticesfilter_decision() const{
  return cfa_->goodVerticesfilter_decision();
}

Int_t const & cfa::hcallaserfilter_decision() const{
  return cfa_->hcallaserfilter_decision();
}

std::vector<float>* const & cfa::jets_AK4_area() const{
  return cfa_->jets_AK4_area();
}

std::vector<float>* const & cfa::jets_AK4_btag_TC_highEff() const{
  return cfa_->jets_AK4_btag_TC_highEff();
}

std::vector<float>* const & cfa::jets_AK4_btag_TC_highPur() const{
  return cfa_->jets_AK4_btag_TC_highPur();
}

std::vector<float>* const & cfa::jets_AK4_btag_jetBProb() const{
  return cfa_->jets_AK4_btag_jetBProb();
}

std::vector<float>* const & cfa::jets_AK4_btag_jetProb() const{
  return cfa_->jets_AK4_btag_jetProb();
}

std::vector<float>* const & cfa::jets_AK4_btag_secVertexCombined() const{
  return cfa_->jets_AK4_btag_secVertexCombined();
}

std::vector<float>* const & cfa::jets_AK4_btag_secVertexHighEff() const{
  return cfa_->jets_AK4_btag_secVertexHighEff();
}

std::vector<float>* const & cfa::jets_AK4_btag_secVertexHighPur() const{
  return cfa_->jets_AK4_btag_secVertexHighPur();
}

std::vector<float>* const & cfa::jets_AK4_btag_softEle() const{
  return cfa_->jets_AK4_btag_softEle();
}

std::vector<float>* const & cfa::jets_AK4_btag_softMuon() const{
  return cfa_->jets_AK4_btag_softMuon();
}

std::vector<float>* const & cfa::jets_AK4_chgEmE() const{
  return cfa_->jets_AK4_chgEmE();
}

std::vector<float>* const & cfa::jets_AK4_chgHadE() const{
  return cfa_->jets_AK4_chgHadE();
}

std::vector<float>* const & cfa::jets_AK4_chgMuE() const{
  return cfa_->jets_AK4_chgMuE();
}

std::vector<float>* const & cfa::jets_AK4_chg_Mult() const{
  return cfa_->jets_AK4_chg_Mult();
}

std::vector<float>* const & cfa::jets_AK4_corrFactorRaw() const{
  return cfa_->jets_AK4_corrFactorRaw();
}

std::vector<float>* const & cfa::jets_AK4_ehf() const{
  return cfa_->jets_AK4_ehf();
}

std::vector<int>* const & cfa::jets_AK4_el_ind() const{
  return cfa_->jets_AK4_el_ind();
}

std::vector<float>* const & cfa::jets_AK4_emf() const{
  return cfa_->jets_AK4_emf();
}

std::vector<float>* const & cfa::jets_AK4_energy() const{
  return cfa_->jets_AK4_energy();
}

std::vector<float>* const & cfa::jets_AK4_et() const{
  return cfa_->jets_AK4_et();
}

std::vector<float>* const & cfa::jets_AK4_eta() const{
  return cfa_->jets_AK4_eta();
}

std::vector<float>* const & cfa::jets_AK4_etaetaMoment() const{
  return cfa_->jets_AK4_etaetaMoment();
}

std::vector<float>* const & cfa::jets_AK4_etaphiMoment() const{
  return cfa_->jets_AK4_etaphiMoment();
}

std::vector<float>* const & cfa::jets_AK4_fHPD() const{
  return cfa_->jets_AK4_fHPD();
}

std::vector<float>* const & cfa::jets_AK4_fRBX() const{
  return cfa_->jets_AK4_fRBX();
}

std::vector<float>* const & cfa::jets_AK4_fSubDetector1() const{
  return cfa_->jets_AK4_fSubDetector1();
}

std::vector<float>* const & cfa::jets_AK4_fSubDetector2() const{
  return cfa_->jets_AK4_fSubDetector2();
}

std::vector<float>* const & cfa::jets_AK4_fSubDetector3() const{
  return cfa_->jets_AK4_fSubDetector3();
}

std::vector<float>* const & cfa::jets_AK4_fSubDetector4() const{
  return cfa_->jets_AK4_fSubDetector4();
}

std::vector<float>* const & cfa::jets_AK4_gen_Energy() const{
  return cfa_->jets_AK4_gen_Energy();
}

std::vector<float>* const & cfa::jets_AK4_gen_Id() const{
  return cfa_->jets_AK4_gen_Id();
}

std::vector<float>* const & cfa::jets_AK4_gen_et() const{
  return cfa_->jets_AK4_gen_et();
}

std::vector<float>* const & cfa::jets_AK4_gen_eta() const{
  return cfa_->jets_AK4_gen_eta();
}

std::vector<float>* const & cfa::jets_AK4_gen_mass() const{
  return cfa_->jets_AK4_gen_mass();
}

std::vector<float>* const & cfa::jets_AK4_gen_motherID() const{
  return cfa_->jets_AK4_gen_motherID();
}

std::vector<float>* const & cfa::jets_AK4_gen_phi() const{
  return cfa_->jets_AK4_gen_phi();
}

std::vector<float>* const & cfa::jets_AK4_gen_pt() const{
  return cfa_->jets_AK4_gen_pt();
}

std::vector<float>* const & cfa::jets_AK4_gen_threeCharge() const{
  return cfa_->jets_AK4_gen_threeCharge();
}

std::vector<float>* const & cfa::jets_AK4_hitsInN90() const{
  return cfa_->jets_AK4_hitsInN90();
}

std::vector<float>* const & cfa::jets_AK4_jetCharge() const{
  return cfa_->jets_AK4_jetCharge();
}

std::vector<float>* const & cfa::jets_AK4_mass() const{
  return cfa_->jets_AK4_mass();
}

std::vector<int>* const & cfa::jets_AK4_maxpt_id() const{
  return cfa_->jets_AK4_maxpt_id();
}

std::vector<float>* const & cfa::jets_AK4_mu_Mult() const{
  return cfa_->jets_AK4_mu_Mult();
}

std::vector<int>* const & cfa::jets_AK4_mu_ind() const{
  return cfa_->jets_AK4_mu_ind();
}

std::vector<float>* const & cfa::jets_AK4_n60() const{
  return cfa_->jets_AK4_n60();
}

std::vector<float>* const & cfa::jets_AK4_n90() const{
  return cfa_->jets_AK4_n90();
}

std::vector<float>* const & cfa::jets_AK4_n90Hits() const{
  return cfa_->jets_AK4_n90Hits();
}

std::vector<float>* const & cfa::jets_AK4_nECALTowers() const{
  return cfa_->jets_AK4_nECALTowers();
}

std::vector<float>* const & cfa::jets_AK4_nHCALTowers() const{
  return cfa_->jets_AK4_nHCALTowers();
}

std::vector<float>* const & cfa::jets_AK4_neutralEmE() const{
  return cfa_->jets_AK4_neutralEmE();
}

std::vector<float>* const & cfa::jets_AK4_neutralHadE() const{
  return cfa_->jets_AK4_neutralHadE();
}

std::vector<float>* const & cfa::jets_AK4_neutral_Mult() const{
  return cfa_->jets_AK4_neutral_Mult();
}

std::vector<float>* const & cfa::jets_AK4_partonFlavour() const{
  return cfa_->jets_AK4_partonFlavour();
}

std::vector<float>* const & cfa::jets_AK4_parton_Energy() const{
  return cfa_->jets_AK4_parton_Energy();
}

std::vector<float>* const & cfa::jets_AK4_parton_Id() const{
  return cfa_->jets_AK4_parton_Id();
}

std::vector<float>* const & cfa::jets_AK4_parton_eta() const{
  return cfa_->jets_AK4_parton_eta();
}

std::vector<float>* const & cfa::jets_AK4_parton_mass() const{
  return cfa_->jets_AK4_parton_mass();
}

std::vector<float>* const & cfa::jets_AK4_parton_motherId() const{
  return cfa_->jets_AK4_parton_motherId();
}

std::vector<float>* const & cfa::jets_AK4_parton_phi() const{
  return cfa_->jets_AK4_parton_phi();
}

std::vector<float>* const & cfa::jets_AK4_parton_pt() const{
  return cfa_->jets_AK4_parton_pt();
}

std::vector<float>* const & cfa::jets_AK4_phi() const{
  return cfa_->jets_AK4_phi();
}

std::vector<float>* const & cfa::jets_AK4_phiphiMoment() const{
  return cfa_->jets_AK4_phiphiMoment();
}

std::vector<float>* const & cfa::jets_AK4_photonEnergy() const{
  return cfa_->jets_AK4_photonEnergy();
}

std::vector<float>* const & cfa::jets_AK4_pt() const{
  return cfa_->jets_AK4_pt();
}

std::vector<float>* const & cfa::jets_AK4_px() const{
  return cfa_->jets_AK4_px();
}

std::vector<float>* const & cfa::jets_AK4_py() const{
  return cfa_->jets_AK4_py();
}

std::vector<float>* const & cfa::jets_AK4_pz() const{
  return cfa_->jets_AK4_pz();
}

std::vector<float>* const & cfa::jets_AK4_rawPt() const{
  return cfa_->jets_AK4_rawPt();
}

std::vector<float>* const & cfa::jets_AK4_status() const{
  return cfa_->jets_AK4_status();
}

std::vector<float>* const & cfa::jets_AK4_theta() const{
  return cfa_->jets_AK4_theta();
}

UInt_t const & cfa::lumiblock() const{
  return cfa_->lumiblock();
}

std::vector<float>* const & cfa::mc_doc_charge() const{
  return cfa_->mc_doc_charge();
}

std::vector<float>* const & cfa::mc_doc_energy() const{
  return cfa_->mc_doc_energy();
}

std::vector<float>* const & cfa::mc_doc_eta() const{
  return cfa_->mc_doc_eta();
}

std::vector<float>* const & cfa::mc_doc_ggrandmother_id() const{
  return cfa_->mc_doc_ggrandmother_id();
}

std::vector<float>* const & cfa::mc_doc_grandmother_id() const{
  return cfa_->mc_doc_grandmother_id();
}

std::vector<float>* const & cfa::mc_doc_id() const{
  return cfa_->mc_doc_id();
}

std::vector<float>* const & cfa::mc_doc_mass() const{
  return cfa_->mc_doc_mass();
}

std::vector<float>* const & cfa::mc_doc_mother_id() const{
  return cfa_->mc_doc_mother_id();
}

std::vector<float>* const & cfa::mc_doc_mother_pt() const{
  return cfa_->mc_doc_mother_pt();
}

std::vector<float>* const & cfa::mc_doc_numOfDaughters() const{
  return cfa_->mc_doc_numOfDaughters();
}

std::vector<float>* const & cfa::mc_doc_numOfMothers() const{
  return cfa_->mc_doc_numOfMothers();
}

std::vector<float>* const & cfa::mc_doc_phi() const{
  return cfa_->mc_doc_phi();
}

std::vector<float>* const & cfa::mc_doc_pt() const{
  return cfa_->mc_doc_pt();
}

std::vector<float>* const & cfa::mc_doc_px() const{
  return cfa_->mc_doc_px();
}

std::vector<float>* const & cfa::mc_doc_py() const{
  return cfa_->mc_doc_py();
}

std::vector<float>* const & cfa::mc_doc_pz() const{
  return cfa_->mc_doc_pz();
}

std::vector<float>* const & cfa::mc_doc_status() const{
  return cfa_->mc_doc_status();
}

std::vector<float>* const & cfa::mc_doc_theta() const{
  return cfa_->mc_doc_theta();
}

std::vector<float>* const & cfa::mc_doc_vertex_x() const{
  return cfa_->mc_doc_vertex_x();
}

std::vector<float>* const & cfa::mc_doc_vertex_y() const{
  return cfa_->mc_doc_vertex_y();
}

std::vector<float>* const & cfa::mc_doc_vertex_z() const{
  return cfa_->mc_doc_vertex_z();
}

std::vector<float>* const & cfa::mc_electrons_charge() const{
  return cfa_->mc_electrons_charge();
}

std::vector<float>* const & cfa::mc_electrons_energy() const{
  return cfa_->mc_electrons_energy();
}

std::vector<float>* const & cfa::mc_electrons_eta() const{
  return cfa_->mc_electrons_eta();
}

std::vector<float>* const & cfa::mc_electrons_ggrandmother_id() const{
  return cfa_->mc_electrons_ggrandmother_id();
}

std::vector<float>* const & cfa::mc_electrons_grandmother_id() const{
  return cfa_->mc_electrons_grandmother_id();
}

std::vector<float>* const & cfa::mc_electrons_id() const{
  return cfa_->mc_electrons_id();
}

std::vector<float>* const & cfa::mc_electrons_mass() const{
  return cfa_->mc_electrons_mass();
}

std::vector<float>* const & cfa::mc_electrons_mother_id() const{
  return cfa_->mc_electrons_mother_id();
}

std::vector<float>* const & cfa::mc_electrons_mother_pt() const{
  return cfa_->mc_electrons_mother_pt();
}

std::vector<float>* const & cfa::mc_electrons_numOfDaughters() const{
  return cfa_->mc_electrons_numOfDaughters();
}

std::vector<float>* const & cfa::mc_electrons_phi() const{
  return cfa_->mc_electrons_phi();
}

std::vector<float>* const & cfa::mc_electrons_pt() const{
  return cfa_->mc_electrons_pt();
}

std::vector<float>* const & cfa::mc_electrons_px() const{
  return cfa_->mc_electrons_px();
}

std::vector<float>* const & cfa::mc_electrons_py() const{
  return cfa_->mc_electrons_py();
}

std::vector<float>* const & cfa::mc_electrons_pz() const{
  return cfa_->mc_electrons_pz();
}

std::vector<float>* const & cfa::mc_electrons_status() const{
  return cfa_->mc_electrons_status();
}

std::vector<float>* const & cfa::mc_electrons_theta() const{
  return cfa_->mc_electrons_theta();
}

std::vector<float>* const & cfa::mc_electrons_vertex_x() const{
  return cfa_->mc_electrons_vertex_x();
}

std::vector<float>* const & cfa::mc_electrons_vertex_y() const{
  return cfa_->mc_electrons_vertex_y();
}

std::vector<float>* const & cfa::mc_electrons_vertex_z() const{
  return cfa_->mc_electrons_vertex_z();
}

std::vector<float>* const & cfa::mc_final_charge() const{
  return cfa_->mc_final_charge();
}

std::vector<float>* const & cfa::mc_final_energy() const{
  return cfa_->mc_final_energy();
}

std::vector<float>* const & cfa::mc_final_eta() const{
  return cfa_->mc_final_eta();
}

std::vector<float>* const & cfa::mc_final_ggrandmother_id() const{
  return cfa_->mc_final_ggrandmother_id();
}

std::vector<float>* const & cfa::mc_final_grandmother_id() const{
  return cfa_->mc_final_grandmother_id();
}

std::vector<float>* const & cfa::mc_final_id() const{
  return cfa_->mc_final_id();
}

std::vector<float>* const & cfa::mc_final_mass() const{
  return cfa_->mc_final_mass();
}

std::vector<float>* const & cfa::mc_final_mother_id() const{
  return cfa_->mc_final_mother_id();
}

std::vector<float>* const & cfa::mc_final_mother_pt() const{
  return cfa_->mc_final_mother_pt();
}

std::vector<float>* const & cfa::mc_final_numOfDaughters() const{
  return cfa_->mc_final_numOfDaughters();
}

std::vector<float>* const & cfa::mc_final_numOfMothers() const{
  return cfa_->mc_final_numOfMothers();
}

std::vector<float>* const & cfa::mc_final_phi() const{
  return cfa_->mc_final_phi();
}

std::vector<float>* const & cfa::mc_final_pt() const{
  return cfa_->mc_final_pt();
}

std::vector<float>* const & cfa::mc_final_px() const{
  return cfa_->mc_final_px();
}

std::vector<float>* const & cfa::mc_final_py() const{
  return cfa_->mc_final_py();
}

std::vector<float>* const & cfa::mc_final_pz() const{
  return cfa_->mc_final_pz();
}

std::vector<float>* const & cfa::mc_final_status() const{
  return cfa_->mc_final_status();
}

std::vector<float>* const & cfa::mc_final_theta() const{
  return cfa_->mc_final_theta();
}

std::vector<float>* const & cfa::mc_final_vertex_x() const{
  return cfa_->mc_final_vertex_x();
}

std::vector<float>* const & cfa::mc_final_vertex_y() const{
  return cfa_->mc_final_vertex_y();
}

std::vector<float>* const & cfa::mc_final_vertex_z() const{
  return cfa_->mc_final_vertex_z();
}

std::vector<float>* const & cfa::mc_jets_auxiliaryEnergy() const{
  return cfa_->mc_jets_auxiliaryEnergy();
}

std::vector<float>* const & cfa::mc_jets_emEnergy() const{
  return cfa_->mc_jets_emEnergy();
}

std::vector<float>* const & cfa::mc_jets_energy() const{
  return cfa_->mc_jets_energy();
}

std::vector<float>* const & cfa::mc_jets_et() const{
  return cfa_->mc_jets_et();
}

std::vector<float>* const & cfa::mc_jets_eta() const{
  return cfa_->mc_jets_eta();
}

std::vector<float>* const & cfa::mc_jets_etaetaMoment() const{
  return cfa_->mc_jets_etaetaMoment();
}

std::vector<float>* const & cfa::mc_jets_etaphiMoment() const{
  return cfa_->mc_jets_etaphiMoment();
}

std::vector<float>* const & cfa::mc_jets_hadEnergy() const{
  return cfa_->mc_jets_hadEnergy();
}

std::vector<float>* const & cfa::mc_jets_invisibleEnergy() const{
  return cfa_->mc_jets_invisibleEnergy();
}

std::vector<float>* const & cfa::mc_jets_mass() const{
  return cfa_->mc_jets_mass();
}

std::vector<float>* const & cfa::mc_jets_phi() const{
  return cfa_->mc_jets_phi();
}

std::vector<float>* const & cfa::mc_jets_phiphiMoment() const{
  return cfa_->mc_jets_phiphiMoment();
}

std::vector<float>* const & cfa::mc_jets_pt() const{
  return cfa_->mc_jets_pt();
}

std::vector<float>* const & cfa::mc_jets_px() const{
  return cfa_->mc_jets_px();
}

std::vector<float>* const & cfa::mc_jets_py() const{
  return cfa_->mc_jets_py();
}

std::vector<float>* const & cfa::mc_jets_pz() const{
  return cfa_->mc_jets_pz();
}

std::vector<float>* const & cfa::mc_jets_theta() const{
  return cfa_->mc_jets_theta();
}

std::vector<float>* const & cfa::mc_mus_charge() const{
  return cfa_->mc_mus_charge();
}

std::vector<float>* const & cfa::mc_mus_energy() const{
  return cfa_->mc_mus_energy();
}

std::vector<float>* const & cfa::mc_mus_eta() const{
  return cfa_->mc_mus_eta();
}

std::vector<float>* const & cfa::mc_mus_ggrandmother_id() const{
  return cfa_->mc_mus_ggrandmother_id();
}

std::vector<float>* const & cfa::mc_mus_grandmother_id() const{
  return cfa_->mc_mus_grandmother_id();
}

std::vector<float>* const & cfa::mc_mus_id() const{
  return cfa_->mc_mus_id();
}

std::vector<float>* const & cfa::mc_mus_mass() const{
  return cfa_->mc_mus_mass();
}

std::vector<float>* const & cfa::mc_mus_mother_id() const{
  return cfa_->mc_mus_mother_id();
}

std::vector<float>* const & cfa::mc_mus_mother_pt() const{
  return cfa_->mc_mus_mother_pt();
}

std::vector<float>* const & cfa::mc_mus_numOfDaughters() const{
  return cfa_->mc_mus_numOfDaughters();
}

std::vector<float>* const & cfa::mc_mus_phi() const{
  return cfa_->mc_mus_phi();
}

std::vector<float>* const & cfa::mc_mus_pt() const{
  return cfa_->mc_mus_pt();
}

std::vector<float>* const & cfa::mc_mus_px() const{
  return cfa_->mc_mus_px();
}

std::vector<float>* const & cfa::mc_mus_py() const{
  return cfa_->mc_mus_py();
}

std::vector<float>* const & cfa::mc_mus_pz() const{
  return cfa_->mc_mus_pz();
}

std::vector<float>* const & cfa::mc_mus_status() const{
  return cfa_->mc_mus_status();
}

std::vector<float>* const & cfa::mc_mus_theta() const{
  return cfa_->mc_mus_theta();
}

std::vector<float>* const & cfa::mc_mus_vertex_x() const{
  return cfa_->mc_mus_vertex_x();
}

std::vector<float>* const & cfa::mc_mus_vertex_y() const{
  return cfa_->mc_mus_vertex_y();
}

std::vector<float>* const & cfa::mc_mus_vertex_z() const{
  return cfa_->mc_mus_vertex_z();
}

std::vector<float>* const & cfa::mc_nues_charge() const{
  return cfa_->mc_nues_charge();
}

std::vector<float>* const & cfa::mc_nues_energy() const{
  return cfa_->mc_nues_energy();
}

std::vector<float>* const & cfa::mc_nues_eta() const{
  return cfa_->mc_nues_eta();
}

std::vector<float>* const & cfa::mc_nues_ggrandmother_id() const{
  return cfa_->mc_nues_ggrandmother_id();
}

std::vector<float>* const & cfa::mc_nues_grandmother_id() const{
  return cfa_->mc_nues_grandmother_id();
}

std::vector<float>* const & cfa::mc_nues_id() const{
  return cfa_->mc_nues_id();
}

std::vector<float>* const & cfa::mc_nues_mass() const{
  return cfa_->mc_nues_mass();
}

std::vector<float>* const & cfa::mc_nues_mother_id() const{
  return cfa_->mc_nues_mother_id();
}

std::vector<float>* const & cfa::mc_nues_mother_pt() const{
  return cfa_->mc_nues_mother_pt();
}

std::vector<float>* const & cfa::mc_nues_numOfDaughters() const{
  return cfa_->mc_nues_numOfDaughters();
}

std::vector<float>* const & cfa::mc_nues_phi() const{
  return cfa_->mc_nues_phi();
}

std::vector<float>* const & cfa::mc_nues_pt() const{
  return cfa_->mc_nues_pt();
}

std::vector<float>* const & cfa::mc_nues_px() const{
  return cfa_->mc_nues_px();
}

std::vector<float>* const & cfa::mc_nues_py() const{
  return cfa_->mc_nues_py();
}

std::vector<float>* const & cfa::mc_nues_pz() const{
  return cfa_->mc_nues_pz();
}

std::vector<float>* const & cfa::mc_nues_status() const{
  return cfa_->mc_nues_status();
}

std::vector<float>* const & cfa::mc_nues_theta() const{
  return cfa_->mc_nues_theta();
}

std::vector<float>* const & cfa::mc_nues_vertex_x() const{
  return cfa_->mc_nues_vertex_x();
}

std::vector<float>* const & cfa::mc_nues_vertex_y() const{
  return cfa_->mc_nues_vertex_y();
}

std::vector<float>* const & cfa::mc_nues_vertex_z() const{
  return cfa_->mc_nues_vertex_z();
}

std::vector<float>* const & cfa::mc_numus_charge() const{
  return cfa_->mc_numus_charge();
}

std::vector<float>* const & cfa::mc_numus_energy() const{
  return cfa_->mc_numus_energy();
}

std::vector<float>* const & cfa::mc_numus_eta() const{
  return cfa_->mc_numus_eta();
}

std::vector<float>* const & cfa::mc_numus_ggrandmother_id() const{
  return cfa_->mc_numus_ggrandmother_id();
}

std::vector<float>* const & cfa::mc_numus_grandmother_id() const{
  return cfa_->mc_numus_grandmother_id();
}

std::vector<float>* const & cfa::mc_numus_id() const{
  return cfa_->mc_numus_id();
}

std::vector<float>* const & cfa::mc_numus_mass() const{
  return cfa_->mc_numus_mass();
}

std::vector<float>* const & cfa::mc_numus_mother_id() const{
  return cfa_->mc_numus_mother_id();
}

std::vector<float>* const & cfa::mc_numus_mother_pt() const{
  return cfa_->mc_numus_mother_pt();
}

std::vector<float>* const & cfa::mc_numus_numOfDaughters() const{
  return cfa_->mc_numus_numOfDaughters();
}

std::vector<float>* const & cfa::mc_numus_phi() const{
  return cfa_->mc_numus_phi();
}

std::vector<float>* const & cfa::mc_numus_pt() const{
  return cfa_->mc_numus_pt();
}

std::vector<float>* const & cfa::mc_numus_px() const{
  return cfa_->mc_numus_px();
}

std::vector<float>* const & cfa::mc_numus_py() const{
  return cfa_->mc_numus_py();
}

std::vector<float>* const & cfa::mc_numus_pz() const{
  return cfa_->mc_numus_pz();
}

std::vector<float>* const & cfa::mc_numus_status() const{
  return cfa_->mc_numus_status();
}

std::vector<float>* const & cfa::mc_numus_theta() const{
  return cfa_->mc_numus_theta();
}

std::vector<float>* const & cfa::mc_numus_vertex_x() const{
  return cfa_->mc_numus_vertex_x();
}

std::vector<float>* const & cfa::mc_numus_vertex_y() const{
  return cfa_->mc_numus_vertex_y();
}

std::vector<float>* const & cfa::mc_numus_vertex_z() const{
  return cfa_->mc_numus_vertex_z();
}

std::vector<float>* const & cfa::mc_nutaus_charge() const{
  return cfa_->mc_nutaus_charge();
}

std::vector<float>* const & cfa::mc_nutaus_energy() const{
  return cfa_->mc_nutaus_energy();
}

std::vector<float>* const & cfa::mc_nutaus_eta() const{
  return cfa_->mc_nutaus_eta();
}

std::vector<float>* const & cfa::mc_nutaus_ggrandmother_id() const{
  return cfa_->mc_nutaus_ggrandmother_id();
}

std::vector<float>* const & cfa::mc_nutaus_grandmother_id() const{
  return cfa_->mc_nutaus_grandmother_id();
}

std::vector<float>* const & cfa::mc_nutaus_id() const{
  return cfa_->mc_nutaus_id();
}

std::vector<float>* const & cfa::mc_nutaus_mass() const{
  return cfa_->mc_nutaus_mass();
}

std::vector<float>* const & cfa::mc_nutaus_mother_id() const{
  return cfa_->mc_nutaus_mother_id();
}

std::vector<float>* const & cfa::mc_nutaus_mother_pt() const{
  return cfa_->mc_nutaus_mother_pt();
}

std::vector<float>* const & cfa::mc_nutaus_numOfDaughters() const{
  return cfa_->mc_nutaus_numOfDaughters();
}

std::vector<float>* const & cfa::mc_nutaus_phi() const{
  return cfa_->mc_nutaus_phi();
}

std::vector<float>* const & cfa::mc_nutaus_pt() const{
  return cfa_->mc_nutaus_pt();
}

std::vector<float>* const & cfa::mc_nutaus_px() const{
  return cfa_->mc_nutaus_px();
}

std::vector<float>* const & cfa::mc_nutaus_py() const{
  return cfa_->mc_nutaus_py();
}

std::vector<float>* const & cfa::mc_nutaus_pz() const{
  return cfa_->mc_nutaus_pz();
}

std::vector<float>* const & cfa::mc_nutaus_status() const{
  return cfa_->mc_nutaus_status();
}

std::vector<float>* const & cfa::mc_nutaus_theta() const{
  return cfa_->mc_nutaus_theta();
}

std::vector<float>* const & cfa::mc_nutaus_vertex_x() const{
  return cfa_->mc_nutaus_vertex_x();
}

std::vector<float>* const & cfa::mc_nutaus_vertex_y() const{
  return cfa_->mc_nutaus_vertex_y();
}

std::vector<float>* const & cfa::mc_nutaus_vertex_z() const{
  return cfa_->mc_nutaus_vertex_z();
}

std::vector<float>* const & cfa::mc_photons_charge() const{
  return cfa_->mc_photons_charge();
}

std::vector<float>* const & cfa::mc_photons_energy() const{
  return cfa_->mc_photons_energy();
}

std::vector<float>* const & cfa::mc_photons_eta() const{
  return cfa_->mc_photons_eta();
}

std::vector<float>* const & cfa::mc_photons_ggrandmother_id() const{
  return cfa_->mc_photons_ggrandmother_id();
}

std::vector<float>* const & cfa::mc_photons_grandmother_id() const{
  return cfa_->mc_photons_grandmother_id();
}

std::vector<float>* const & cfa::mc_photons_id() const{
  return cfa_->mc_photons_id();
}

std::vector<float>* const & cfa::mc_photons_mass() const{
  return cfa_->mc_photons_mass();
}

std::vector<float>* const & cfa::mc_photons_mother_id() const{
  return cfa_->mc_photons_mother_id();
}

std::vector<float>* const & cfa::mc_photons_mother_pt() const{
  return cfa_->mc_photons_mother_pt();
}

std::vector<float>* const & cfa::mc_photons_numOfDaughters() const{
  return cfa_->mc_photons_numOfDaughters();
}

std::vector<float>* const & cfa::mc_photons_phi() const{
  return cfa_->mc_photons_phi();
}

std::vector<float>* const & cfa::mc_photons_pt() const{
  return cfa_->mc_photons_pt();
}

std::vector<float>* const & cfa::mc_photons_px() const{
  return cfa_->mc_photons_px();
}

std::vector<float>* const & cfa::mc_photons_py() const{
  return cfa_->mc_photons_py();
}

std::vector<float>* const & cfa::mc_photons_pz() const{
  return cfa_->mc_photons_pz();
}

std::vector<float>* const & cfa::mc_photons_status() const{
  return cfa_->mc_photons_status();
}

std::vector<float>* const & cfa::mc_photons_theta() const{
  return cfa_->mc_photons_theta();
}

std::vector<float>* const & cfa::mc_photons_vertex_x() const{
  return cfa_->mc_photons_vertex_x();
}

std::vector<float>* const & cfa::mc_photons_vertex_y() const{
  return cfa_->mc_photons_vertex_y();
}

std::vector<float>* const & cfa::mc_photons_vertex_z() const{
  return cfa_->mc_photons_vertex_z();
}

std::vector<float>* const & cfa::mc_taus_charge() const{
  return cfa_->mc_taus_charge();
}

std::vector<float>* const & cfa::mc_taus_energy() const{
  return cfa_->mc_taus_energy();
}

std::vector<float>* const & cfa::mc_taus_eta() const{
  return cfa_->mc_taus_eta();
}

std::vector<float>* const & cfa::mc_taus_ggrandmother_id() const{
  return cfa_->mc_taus_ggrandmother_id();
}

std::vector<float>* const & cfa::mc_taus_grandmother_id() const{
  return cfa_->mc_taus_grandmother_id();
}

std::vector<float>* const & cfa::mc_taus_id() const{
  return cfa_->mc_taus_id();
}

std::vector<float>* const & cfa::mc_taus_mass() const{
  return cfa_->mc_taus_mass();
}

std::vector<float>* const & cfa::mc_taus_mother_id() const{
  return cfa_->mc_taus_mother_id();
}

std::vector<float>* const & cfa::mc_taus_mother_pt() const{
  return cfa_->mc_taus_mother_pt();
}

std::vector<float>* const & cfa::mc_taus_numOfDaughters() const{
  return cfa_->mc_taus_numOfDaughters();
}

std::vector<float>* const & cfa::mc_taus_phi() const{
  return cfa_->mc_taus_phi();
}

std::vector<float>* const & cfa::mc_taus_pt() const{
  return cfa_->mc_taus_pt();
}

std::vector<float>* const & cfa::mc_taus_px() const{
  return cfa_->mc_taus_px();
}

std::vector<float>* const & cfa::mc_taus_py() const{
  return cfa_->mc_taus_py();
}

std::vector<float>* const & cfa::mc_taus_pz() const{
  return cfa_->mc_taus_pz();
}

std::vector<float>* const & cfa::mc_taus_status() const{
  return cfa_->mc_taus_status();
}

std::vector<float>* const & cfa::mc_taus_theta() const{
  return cfa_->mc_taus_theta();
}

std::vector<float>* const & cfa::mc_taus_vertex_x() const{
  return cfa_->mc_taus_vertex_x();
}

std::vector<float>* const & cfa::mc_taus_vertex_y() const{
  return cfa_->mc_taus_vertex_y();
}

std::vector<float>* const & cfa::mc_taus_vertex_z() const{
  return cfa_->mc_taus_vertex_z();
}

std::vector<float>* const & cfa::mets_et() const{
  return cfa_->mets_et();
}

std::vector<float>* const & cfa::mets_ex() const{
  return cfa_->mets_ex();
}

std::vector<float>* const & cfa::mets_ey() const{
  return cfa_->mets_ey();
}

std::vector<float>* const & cfa::mets_gen_et() const{
  return cfa_->mets_gen_et();
}

std::vector<float>* const & cfa::mets_gen_phi() const{
  return cfa_->mets_gen_phi();
}

std::vector<float>* const & cfa::mets_phi() const{
  return cfa_->mets_phi();
}

std::vector<float>* const & cfa::mets_sign() const{
  return cfa_->mets_sign();
}

std::vector<float>* const & cfa::mets_sumEt() const{
  return cfa_->mets_sumEt();
}

std::vector<float>* const & cfa::mets_unCPhi() const{
  return cfa_->mets_unCPhi();
}

std::vector<float>* const & cfa::mets_unCPt() const{
  return cfa_->mets_unCPt();
}

std::string* const & cfa::model_params() const{
  return cfa_->model_params();
}

std::vector<float>* const & cfa::mus_cIso() const{
  return cfa_->mus_cIso();
}

std::vector<float>* const & cfa::mus_calEnergyEm() const{
  return cfa_->mus_calEnergyEm();
}

std::vector<float>* const & cfa::mus_calEnergyEmS9() const{
  return cfa_->mus_calEnergyEmS9();
}

std::vector<float>* const & cfa::mus_calEnergyHad() const{
  return cfa_->mus_calEnergyHad();
}

std::vector<float>* const & cfa::mus_calEnergyHadS9() const{
  return cfa_->mus_calEnergyHadS9();
}

std::vector<float>* const & cfa::mus_calEnergyHo() const{
  return cfa_->mus_calEnergyHo();
}

std::vector<float>* const & cfa::mus_calEnergyHoS9() const{
  return cfa_->mus_calEnergyHoS9();
}

std::vector<float>* const & cfa::mus_charge() const{
  return cfa_->mus_charge();
}

std::vector<float>* const & cfa::mus_cm_ExpectedHitsInner() const{
  return cfa_->mus_cm_ExpectedHitsInner();
}

std::vector<float>* const & cfa::mus_cm_ExpectedHitsOuter() const{
  return cfa_->mus_cm_ExpectedHitsOuter();
}

std::vector<float>* const & cfa::mus_cm_LayersWithMeasurement() const{
  return cfa_->mus_cm_LayersWithMeasurement();
}

std::vector<float>* const & cfa::mus_cm_LayersWithoutMeasurement() const{
  return cfa_->mus_cm_LayersWithoutMeasurement();
}

std::vector<float>* const & cfa::mus_cm_PixelLayersWithMeasurement() const{
  return cfa_->mus_cm_PixelLayersWithMeasurement();
}

std::vector<float>* const & cfa::mus_cm_ValidStripLayersWithMonoAndStereoHit() const{
  return cfa_->mus_cm_ValidStripLayersWithMonoAndStereoHit();
}

std::vector<float>* const & cfa::mus_cm_chg() const{
  return cfa_->mus_cm_chg();
}

std::vector<float>* const & cfa::mus_cm_chi2() const{
  return cfa_->mus_cm_chi2();
}

std::vector<float>* const & cfa::mus_cm_d0dum() const{
  return cfa_->mus_cm_d0dum();
}

std::vector<float>* const & cfa::mus_cm_d0dumErr() const{
  return cfa_->mus_cm_d0dumErr();
}

std::vector<float>* const & cfa::mus_cm_dz() const{
  return cfa_->mus_cm_dz();
}

std::vector<float>* const & cfa::mus_cm_dzErr() const{
  return cfa_->mus_cm_dzErr();
}

std::vector<float>* const & cfa::mus_cm_eta() const{
  return cfa_->mus_cm_eta();
}

std::vector<float>* const & cfa::mus_cm_etaErr() const{
  return cfa_->mus_cm_etaErr();
}

std::vector<float>* const & cfa::mus_cm_ndof() const{
  return cfa_->mus_cm_ndof();
}

std::vector<float>* const & cfa::mus_cm_numlosthits() const{
  return cfa_->mus_cm_numlosthits();
}

std::vector<float>* const & cfa::mus_cm_numvalMuonhits() const{
  return cfa_->mus_cm_numvalMuonhits();
}

std::vector<float>* const & cfa::mus_cm_numvalhits() const{
  return cfa_->mus_cm_numvalhits();
}

std::vector<float>* const & cfa::mus_cm_phi() const{
  return cfa_->mus_cm_phi();
}

std::vector<float>* const & cfa::mus_cm_phiErr() const{
  return cfa_->mus_cm_phiErr();
}

std::vector<float>* const & cfa::mus_cm_pt() const{
  return cfa_->mus_cm_pt();
}

std::vector<float>* const & cfa::mus_cm_ptErr() const{
  return cfa_->mus_cm_ptErr();
}

std::vector<float>* const & cfa::mus_cm_px() const{
  return cfa_->mus_cm_px();
}

std::vector<float>* const & cfa::mus_cm_py() const{
  return cfa_->mus_cm_py();
}

std::vector<float>* const & cfa::mus_cm_pz() const{
  return cfa_->mus_cm_pz();
}

std::vector<float>* const & cfa::mus_cm_theta() const{
  return cfa_->mus_cm_theta();
}

std::vector<float>* const & cfa::mus_cm_vx() const{
  return cfa_->mus_cm_vx();
}

std::vector<float>* const & cfa::mus_cm_vy() const{
  return cfa_->mus_cm_vy();
}

std::vector<float>* const & cfa::mus_cm_vz() const{
  return cfa_->mus_cm_vz();
}

std::vector<float>* const & cfa::mus_dB() const{
  return cfa_->mus_dB();
}

std::vector<float>* const & cfa::mus_ecalIso() const{
  return cfa_->mus_ecalIso();
}

std::vector<float>* const & cfa::mus_ecalvetoDep() const{
  return cfa_->mus_ecalvetoDep();
}

std::vector<float>* const & cfa::mus_energy() const{
  return cfa_->mus_energy();
}

std::vector<float>* const & cfa::mus_et() const{
  return cfa_->mus_et();
}

std::vector<float>* const & cfa::mus_eta() const{
  return cfa_->mus_eta();
}

std::vector<float>* const & cfa::mus_gen_et() const{
  return cfa_->mus_gen_et();
}

std::vector<float>* const & cfa::mus_gen_eta() const{
  return cfa_->mus_gen_eta();
}

std::vector<float>* const & cfa::mus_gen_id() const{
  return cfa_->mus_gen_id();
}

std::vector<float>* const & cfa::mus_gen_mother_et() const{
  return cfa_->mus_gen_mother_et();
}

std::vector<float>* const & cfa::mus_gen_mother_eta() const{
  return cfa_->mus_gen_mother_eta();
}

std::vector<float>* const & cfa::mus_gen_mother_id() const{
  return cfa_->mus_gen_mother_id();
}

std::vector<float>* const & cfa::mus_gen_mother_phi() const{
  return cfa_->mus_gen_mother_phi();
}

std::vector<float>* const & cfa::mus_gen_mother_pt() const{
  return cfa_->mus_gen_mother_pt();
}

std::vector<float>* const & cfa::mus_gen_mother_px() const{
  return cfa_->mus_gen_mother_px();
}

std::vector<float>* const & cfa::mus_gen_mother_py() const{
  return cfa_->mus_gen_mother_py();
}

std::vector<float>* const & cfa::mus_gen_mother_pz() const{
  return cfa_->mus_gen_mother_pz();
}

std::vector<float>* const & cfa::mus_gen_mother_theta() const{
  return cfa_->mus_gen_mother_theta();
}

std::vector<float>* const & cfa::mus_gen_phi() const{
  return cfa_->mus_gen_phi();
}

std::vector<float>* const & cfa::mus_gen_pt() const{
  return cfa_->mus_gen_pt();
}

std::vector<float>* const & cfa::mus_gen_px() const{
  return cfa_->mus_gen_px();
}

std::vector<float>* const & cfa::mus_gen_py() const{
  return cfa_->mus_gen_py();
}

std::vector<float>* const & cfa::mus_gen_pz() const{
  return cfa_->mus_gen_pz();
}

std::vector<float>* const & cfa::mus_gen_theta() const{
  return cfa_->mus_gen_theta();
}

std::vector<float>* const & cfa::mus_hcalIso() const{
  return cfa_->mus_hcalIso();
}

std::vector<float>* const & cfa::mus_hcalvetoDep() const{
  return cfa_->mus_hcalvetoDep();
}

std::vector<float>* const & cfa::mus_id_All() const{
  return cfa_->mus_id_All();
}

std::vector<float>* const & cfa::mus_id_AllArbitrated() const{
  return cfa_->mus_id_AllArbitrated();
}

std::vector<float>* const & cfa::mus_id_AllGlobalMuons() const{
  return cfa_->mus_id_AllGlobalMuons();
}

std::vector<float>* const & cfa::mus_id_AllStandAloneMuons() const{
  return cfa_->mus_id_AllStandAloneMuons();
}

std::vector<float>* const & cfa::mus_id_AllTrackerMuons() const{
  return cfa_->mus_id_AllTrackerMuons();
}

std::vector<float>* const & cfa::mus_id_GlobalMuonPromptTight() const{
  return cfa_->mus_id_GlobalMuonPromptTight();
}

std::vector<float>* const & cfa::mus_id_TM2DCompatibilityLoose() const{
  return cfa_->mus_id_TM2DCompatibilityLoose();
}

std::vector<float>* const & cfa::mus_id_TM2DCompatibilityTight() const{
  return cfa_->mus_id_TM2DCompatibilityTight();
}

std::vector<float>* const & cfa::mus_id_TMLastStationLoose() const{
  return cfa_->mus_id_TMLastStationLoose();
}

std::vector<float>* const & cfa::mus_id_TMLastStationOptimizedLowPtLoose() const{
  return cfa_->mus_id_TMLastStationOptimizedLowPtLoose();
}

std::vector<float>* const & cfa::mus_id_TMLastStationOptimizedLowPtTight() const{
  return cfa_->mus_id_TMLastStationOptimizedLowPtTight();
}

std::vector<float>* const & cfa::mus_id_TMLastStationTight() const{
  return cfa_->mus_id_TMLastStationTight();
}

std::vector<float>* const & cfa::mus_id_TMOneStationLoose() const{
  return cfa_->mus_id_TMOneStationLoose();
}

std::vector<float>* const & cfa::mus_id_TMOneStationTight() const{
  return cfa_->mus_id_TMOneStationTight();
}

std::vector<float>* const & cfa::mus_id_TrackerMuonArbitrated() const{
  return cfa_->mus_id_TrackerMuonArbitrated();
}

std::vector<float>* const & cfa::mus_isCaloMuon() const{
  return cfa_->mus_isCaloMuon();
}

std::vector<float>* const & cfa::mus_isConvertedPhoton() const{
  return cfa_->mus_isConvertedPhoton();
}

std::vector<float>* const & cfa::mus_isElectron() const{
  return cfa_->mus_isElectron();
}

std::vector<float>* const & cfa::mus_isGlobalMuon() const{
  return cfa_->mus_isGlobalMuon();
}

std::vector<bool>* const & cfa::mus_isPF() const{
  return cfa_->mus_isPF();
}

std::vector<float>* const & cfa::mus_isPFMuon() const{
  return cfa_->mus_isPFMuon();
}

std::vector<float>* const & cfa::mus_isPhoton() const{
  return cfa_->mus_isPhoton();
}

std::vector<float>* const & cfa::mus_isStandAloneMuon() const{
  return cfa_->mus_isStandAloneMuon();
}

std::vector<float>* const & cfa::mus_isTrackerMuon() const{
  return cfa_->mus_isTrackerMuon();
}

std::vector<float>* const & cfa::mus_iso03_emEt() const{
  return cfa_->mus_iso03_emEt();
}

std::vector<float>* const & cfa::mus_iso03_emVetoEt() const{
  return cfa_->mus_iso03_emVetoEt();
}

std::vector<float>* const & cfa::mus_iso03_hadEt() const{
  return cfa_->mus_iso03_hadEt();
}

std::vector<float>* const & cfa::mus_iso03_hadVetoEt() const{
  return cfa_->mus_iso03_hadVetoEt();
}

std::vector<float>* const & cfa::mus_iso03_hoEt() const{
  return cfa_->mus_iso03_hoEt();
}

std::vector<float>* const & cfa::mus_iso03_nTracks() const{
  return cfa_->mus_iso03_nTracks();
}

std::vector<float>* const & cfa::mus_iso03_sumPt() const{
  return cfa_->mus_iso03_sumPt();
}

std::vector<float>* const & cfa::mus_iso05_emEt() const{
  return cfa_->mus_iso05_emEt();
}

std::vector<float>* const & cfa::mus_iso05_hadEt() const{
  return cfa_->mus_iso05_hadEt();
}

std::vector<float>* const & cfa::mus_iso05_hoEt() const{
  return cfa_->mus_iso05_hoEt();
}

std::vector<float>* const & cfa::mus_iso05_nTracks() const{
  return cfa_->mus_iso05_nTracks();
}

std::vector<float>* const & cfa::mus_iso05_sumPt() const{
  return cfa_->mus_iso05_sumPt();
}

std::vector<int>* const & cfa::mus_jet_ind() const{
  return cfa_->mus_jet_ind();
}

std::vector<float>* const & cfa::mus_num_matches() const{
  return cfa_->mus_num_matches();
}

std::vector<float>* const & cfa::mus_numberOfMatchedStations() const{
  return cfa_->mus_numberOfMatchedStations();
}

std::vector<float>* const & cfa::mus_pfIsolationR03_sumChargedHadronPt() const{
  return cfa_->mus_pfIsolationR03_sumChargedHadronPt();
}

std::vector<float>* const & cfa::mus_pfIsolationR03_sumChargedParticlePt() const{
  return cfa_->mus_pfIsolationR03_sumChargedParticlePt();
}

std::vector<float>* const & cfa::mus_pfIsolationR03_sumNeutralHadronEt() const{
  return cfa_->mus_pfIsolationR03_sumNeutralHadronEt();
}

std::vector<float>* const & cfa::mus_pfIsolationR03_sumNeutralHadronEtHighThreshold() const{
  return cfa_->mus_pfIsolationR03_sumNeutralHadronEtHighThreshold();
}

std::vector<float>* const & cfa::mus_pfIsolationR03_sumPUPt() const{
  return cfa_->mus_pfIsolationR03_sumPUPt();
}

std::vector<float>* const & cfa::mus_pfIsolationR03_sumPhotonEt() const{
  return cfa_->mus_pfIsolationR03_sumPhotonEt();
}

std::vector<float>* const & cfa::mus_pfIsolationR03_sumPhotonEtHighThreshold() const{
  return cfa_->mus_pfIsolationR03_sumPhotonEtHighThreshold();
}

std::vector<float>* const & cfa::mus_pfIsolationR04_sumChargedHadronPt() const{
  return cfa_->mus_pfIsolationR04_sumChargedHadronPt();
}

std::vector<float>* const & cfa::mus_pfIsolationR04_sumChargedParticlePt() const{
  return cfa_->mus_pfIsolationR04_sumChargedParticlePt();
}

std::vector<float>* const & cfa::mus_pfIsolationR04_sumNeutralHadronEt() const{
  return cfa_->mus_pfIsolationR04_sumNeutralHadronEt();
}

std::vector<float>* const & cfa::mus_pfIsolationR04_sumNeutralHadronEtHighThreshold() const{
  return cfa_->mus_pfIsolationR04_sumNeutralHadronEtHighThreshold();
}

std::vector<float>* const & cfa::mus_pfIsolationR04_sumPUPt() const{
  return cfa_->mus_pfIsolationR04_sumPUPt();
}

std::vector<float>* const & cfa::mus_pfIsolationR04_sumPhotonEt() const{
  return cfa_->mus_pfIsolationR04_sumPhotonEt();
}

std::vector<float>* const & cfa::mus_pfIsolationR04_sumPhotonEtHighThreshold() const{
  return cfa_->mus_pfIsolationR04_sumPhotonEtHighThreshold();
}

std::vector<float>* const & cfa::mus_phi() const{
  return cfa_->mus_phi();
}

std::vector<float>* const & cfa::mus_picky_ExpectedHitsInner() const{
  return cfa_->mus_picky_ExpectedHitsInner();
}

std::vector<float>* const & cfa::mus_picky_ExpectedHitsOuter() const{
  return cfa_->mus_picky_ExpectedHitsOuter();
}

std::vector<float>* const & cfa::mus_picky_LayersWithMeasurement() const{
  return cfa_->mus_picky_LayersWithMeasurement();
}

std::vector<float>* const & cfa::mus_picky_LayersWithoutMeasurement() const{
  return cfa_->mus_picky_LayersWithoutMeasurement();
}

std::vector<float>* const & cfa::mus_picky_PixelLayersWithMeasurement() const{
  return cfa_->mus_picky_PixelLayersWithMeasurement();
}

std::vector<float>* const & cfa::mus_picky_ValidStripLayersWithMonoAndStereoHit() const{
  return cfa_->mus_picky_ValidStripLayersWithMonoAndStereoHit();
}

std::vector<float>* const & cfa::mus_picky_chg() const{
  return cfa_->mus_picky_chg();
}

std::vector<float>* const & cfa::mus_picky_chi2() const{
  return cfa_->mus_picky_chi2();
}

std::vector<float>* const & cfa::mus_picky_d0dum() const{
  return cfa_->mus_picky_d0dum();
}

std::vector<float>* const & cfa::mus_picky_d0dumErr() const{
  return cfa_->mus_picky_d0dumErr();
}

std::vector<float>* const & cfa::mus_picky_dz() const{
  return cfa_->mus_picky_dz();
}

std::vector<float>* const & cfa::mus_picky_dzErr() const{
  return cfa_->mus_picky_dzErr();
}

std::vector<float>* const & cfa::mus_picky_eta() const{
  return cfa_->mus_picky_eta();
}

std::vector<float>* const & cfa::mus_picky_etaErr() const{
  return cfa_->mus_picky_etaErr();
}

std::vector<float>* const & cfa::mus_picky_id() const{
  return cfa_->mus_picky_id();
}

std::vector<float>* const & cfa::mus_picky_ndof() const{
  return cfa_->mus_picky_ndof();
}

std::vector<float>* const & cfa::mus_picky_numlosthits() const{
  return cfa_->mus_picky_numlosthits();
}

std::vector<float>* const & cfa::mus_picky_numvalPixelhits() const{
  return cfa_->mus_picky_numvalPixelhits();
}

std::vector<float>* const & cfa::mus_picky_numvalhits() const{
  return cfa_->mus_picky_numvalhits();
}

std::vector<float>* const & cfa::mus_picky_phi() const{
  return cfa_->mus_picky_phi();
}

std::vector<float>* const & cfa::mus_picky_phiErr() const{
  return cfa_->mus_picky_phiErr();
}

std::vector<float>* const & cfa::mus_picky_pt() const{
  return cfa_->mus_picky_pt();
}

std::vector<float>* const & cfa::mus_picky_ptErr() const{
  return cfa_->mus_picky_ptErr();
}

std::vector<float>* const & cfa::mus_picky_px() const{
  return cfa_->mus_picky_px();
}

std::vector<float>* const & cfa::mus_picky_py() const{
  return cfa_->mus_picky_py();
}

std::vector<float>* const & cfa::mus_picky_pz() const{
  return cfa_->mus_picky_pz();
}

std::vector<float>* const & cfa::mus_picky_theta() const{
  return cfa_->mus_picky_theta();
}

std::vector<float>* const & cfa::mus_picky_vx() const{
  return cfa_->mus_picky_vx();
}

std::vector<float>* const & cfa::mus_picky_vy() const{
  return cfa_->mus_picky_vy();
}

std::vector<float>* const & cfa::mus_picky_vz() const{
  return cfa_->mus_picky_vz();
}

std::vector<float>* const & cfa::mus_pt() const{
  return cfa_->mus_pt();
}

std::vector<float>* const & cfa::mus_px() const{
  return cfa_->mus_px();
}

std::vector<float>* const & cfa::mus_py() const{
  return cfa_->mus_py();
}

std::vector<float>* const & cfa::mus_pz() const{
  return cfa_->mus_pz();
}

std::vector<float>* const & cfa::mus_stamu_chg() const{
  return cfa_->mus_stamu_chg();
}

std::vector<float>* const & cfa::mus_stamu_chi2() const{
  return cfa_->mus_stamu_chi2();
}

std::vector<float>* const & cfa::mus_stamu_d0dum() const{
  return cfa_->mus_stamu_d0dum();
}

std::vector<float>* const & cfa::mus_stamu_d0dumErr() const{
  return cfa_->mus_stamu_d0dumErr();
}

std::vector<float>* const & cfa::mus_stamu_dz() const{
  return cfa_->mus_stamu_dz();
}

std::vector<float>* const & cfa::mus_stamu_dzErr() const{
  return cfa_->mus_stamu_dzErr();
}

std::vector<float>* const & cfa::mus_stamu_eta() const{
  return cfa_->mus_stamu_eta();
}

std::vector<float>* const & cfa::mus_stamu_etaErr() const{
  return cfa_->mus_stamu_etaErr();
}

std::vector<float>* const & cfa::mus_stamu_ndof() const{
  return cfa_->mus_stamu_ndof();
}

std::vector<float>* const & cfa::mus_stamu_numlosthits() const{
  return cfa_->mus_stamu_numlosthits();
}

std::vector<float>* const & cfa::mus_stamu_numvalhits() const{
  return cfa_->mus_stamu_numvalhits();
}

std::vector<float>* const & cfa::mus_stamu_phi() const{
  return cfa_->mus_stamu_phi();
}

std::vector<float>* const & cfa::mus_stamu_phiErr() const{
  return cfa_->mus_stamu_phiErr();
}

std::vector<float>* const & cfa::mus_stamu_pt() const{
  return cfa_->mus_stamu_pt();
}

std::vector<float>* const & cfa::mus_stamu_ptErr() const{
  return cfa_->mus_stamu_ptErr();
}

std::vector<float>* const & cfa::mus_stamu_px() const{
  return cfa_->mus_stamu_px();
}

std::vector<float>* const & cfa::mus_stamu_py() const{
  return cfa_->mus_stamu_py();
}

std::vector<float>* const & cfa::mus_stamu_pz() const{
  return cfa_->mus_stamu_pz();
}

std::vector<float>* const & cfa::mus_stamu_theta() const{
  return cfa_->mus_stamu_theta();
}

std::vector<float>* const & cfa::mus_stamu_vx() const{
  return cfa_->mus_stamu_vx();
}

std::vector<float>* const & cfa::mus_stamu_vy() const{
  return cfa_->mus_stamu_vy();
}

std::vector<float>* const & cfa::mus_stamu_vz() const{
  return cfa_->mus_stamu_vz();
}

std::vector<float>* const & cfa::mus_status() const{
  return cfa_->mus_status();
}

std::vector<float>* const & cfa::mus_tIso() const{
  return cfa_->mus_tIso();
}

std::vector<float>* const & cfa::mus_theta() const{
  return cfa_->mus_theta();
}

std::vector<float>* const & cfa::mus_tkHits() const{
  return cfa_->mus_tkHits();
}

std::vector<float>* const & cfa::mus_tk_ExpectedHitsInner() const{
  return cfa_->mus_tk_ExpectedHitsInner();
}

std::vector<float>* const & cfa::mus_tk_ExpectedHitsOuter() const{
  return cfa_->mus_tk_ExpectedHitsOuter();
}

std::vector<float>* const & cfa::mus_tk_LayersWithMeasurement() const{
  return cfa_->mus_tk_LayersWithMeasurement();
}

std::vector<float>* const & cfa::mus_tk_LayersWithoutMeasurement() const{
  return cfa_->mus_tk_LayersWithoutMeasurement();
}

std::vector<float>* const & cfa::mus_tk_PixelLayersWithMeasurement() const{
  return cfa_->mus_tk_PixelLayersWithMeasurement();
}

std::vector<float>* const & cfa::mus_tk_ValidStripLayersWithMonoAndStereoHit() const{
  return cfa_->mus_tk_ValidStripLayersWithMonoAndStereoHit();
}

std::vector<float>* const & cfa::mus_tk_chg() const{
  return cfa_->mus_tk_chg();
}

std::vector<float>* const & cfa::mus_tk_chi2() const{
  return cfa_->mus_tk_chi2();
}

std::vector<float>* const & cfa::mus_tk_d0dum() const{
  return cfa_->mus_tk_d0dum();
}

std::vector<float>* const & cfa::mus_tk_d0dumErr() const{
  return cfa_->mus_tk_d0dumErr();
}

std::vector<float>* const & cfa::mus_tk_dz() const{
  return cfa_->mus_tk_dz();
}

std::vector<float>* const & cfa::mus_tk_dzErr() const{
  return cfa_->mus_tk_dzErr();
}

std::vector<float>* const & cfa::mus_tk_eta() const{
  return cfa_->mus_tk_eta();
}

std::vector<float>* const & cfa::mus_tk_etaErr() const{
  return cfa_->mus_tk_etaErr();
}

std::vector<float>* const & cfa::mus_tk_id() const{
  return cfa_->mus_tk_id();
}

std::vector<float>* const & cfa::mus_tk_ndof() const{
  return cfa_->mus_tk_ndof();
}

std::vector<float>* const & cfa::mus_tk_numlosthits() const{
  return cfa_->mus_tk_numlosthits();
}

std::vector<float>* const & cfa::mus_tk_numpixelWthMeasr() const{
  return cfa_->mus_tk_numpixelWthMeasr();
}

std::vector<float>* const & cfa::mus_tk_numvalPixelhits() const{
  return cfa_->mus_tk_numvalPixelhits();
}

std::vector<float>* const & cfa::mus_tk_numvalhits() const{
  return cfa_->mus_tk_numvalhits();
}

std::vector<float>* const & cfa::mus_tk_phi() const{
  return cfa_->mus_tk_phi();
}

std::vector<float>* const & cfa::mus_tk_phiErr() const{
  return cfa_->mus_tk_phiErr();
}

std::vector<float>* const & cfa::mus_tk_pt() const{
  return cfa_->mus_tk_pt();
}

std::vector<float>* const & cfa::mus_tk_ptErr() const{
  return cfa_->mus_tk_ptErr();
}

std::vector<float>* const & cfa::mus_tk_px() const{
  return cfa_->mus_tk_px();
}

std::vector<float>* const & cfa::mus_tk_py() const{
  return cfa_->mus_tk_py();
}

std::vector<float>* const & cfa::mus_tk_pz() const{
  return cfa_->mus_tk_pz();
}

std::vector<float>* const & cfa::mus_tk_theta() const{
  return cfa_->mus_tk_theta();
}

std::vector<float>* const & cfa::mus_tk_vx() const{
  return cfa_->mus_tk_vx();
}

std::vector<float>* const & cfa::mus_tk_vy() const{
  return cfa_->mus_tk_vy();
}

std::vector<float>* const & cfa::mus_tk_vz() const{
  return cfa_->mus_tk_vz();
}

std::vector<float>* const & cfa::mus_tpfms_ExpectedHitsInner() const{
  return cfa_->mus_tpfms_ExpectedHitsInner();
}

std::vector<float>* const & cfa::mus_tpfms_ExpectedHitsOuter() const{
  return cfa_->mus_tpfms_ExpectedHitsOuter();
}

std::vector<float>* const & cfa::mus_tpfms_LayersWithMeasurement() const{
  return cfa_->mus_tpfms_LayersWithMeasurement();
}

std::vector<float>* const & cfa::mus_tpfms_LayersWithoutMeasurement() const{
  return cfa_->mus_tpfms_LayersWithoutMeasurement();
}

std::vector<float>* const & cfa::mus_tpfms_PixelLayersWithMeasurement() const{
  return cfa_->mus_tpfms_PixelLayersWithMeasurement();
}

std::vector<float>* const & cfa::mus_tpfms_ValidStripLayersWithMonoAndStereoHit() const{
  return cfa_->mus_tpfms_ValidStripLayersWithMonoAndStereoHit();
}

std::vector<float>* const & cfa::mus_tpfms_chg() const{
  return cfa_->mus_tpfms_chg();
}

std::vector<float>* const & cfa::mus_tpfms_chi2() const{
  return cfa_->mus_tpfms_chi2();
}

std::vector<float>* const & cfa::mus_tpfms_d0dum() const{
  return cfa_->mus_tpfms_d0dum();
}

std::vector<float>* const & cfa::mus_tpfms_d0dumErr() const{
  return cfa_->mus_tpfms_d0dumErr();
}

std::vector<float>* const & cfa::mus_tpfms_dz() const{
  return cfa_->mus_tpfms_dz();
}

std::vector<float>* const & cfa::mus_tpfms_dzErr() const{
  return cfa_->mus_tpfms_dzErr();
}

std::vector<float>* const & cfa::mus_tpfms_eta() const{
  return cfa_->mus_tpfms_eta();
}

std::vector<float>* const & cfa::mus_tpfms_etaErr() const{
  return cfa_->mus_tpfms_etaErr();
}

std::vector<float>* const & cfa::mus_tpfms_id() const{
  return cfa_->mus_tpfms_id();
}

std::vector<float>* const & cfa::mus_tpfms_ndof() const{
  return cfa_->mus_tpfms_ndof();
}

std::vector<float>* const & cfa::mus_tpfms_numlosthits() const{
  return cfa_->mus_tpfms_numlosthits();
}

std::vector<float>* const & cfa::mus_tpfms_numvalPixelhits() const{
  return cfa_->mus_tpfms_numvalPixelhits();
}

std::vector<float>* const & cfa::mus_tpfms_numvalhits() const{
  return cfa_->mus_tpfms_numvalhits();
}

std::vector<float>* const & cfa::mus_tpfms_phi() const{
  return cfa_->mus_tpfms_phi();
}

std::vector<float>* const & cfa::mus_tpfms_phiErr() const{
  return cfa_->mus_tpfms_phiErr();
}

std::vector<float>* const & cfa::mus_tpfms_pt() const{
  return cfa_->mus_tpfms_pt();
}

std::vector<float>* const & cfa::mus_tpfms_ptErr() const{
  return cfa_->mus_tpfms_ptErr();
}

std::vector<float>* const & cfa::mus_tpfms_px() const{
  return cfa_->mus_tpfms_px();
}

std::vector<float>* const & cfa::mus_tpfms_py() const{
  return cfa_->mus_tpfms_py();
}

std::vector<float>* const & cfa::mus_tpfms_pz() const{
  return cfa_->mus_tpfms_pz();
}

std::vector<float>* const & cfa::mus_tpfms_theta() const{
  return cfa_->mus_tpfms_theta();
}

std::vector<float>* const & cfa::mus_tpfms_vx() const{
  return cfa_->mus_tpfms_vx();
}

std::vector<float>* const & cfa::mus_tpfms_vy() const{
  return cfa_->mus_tpfms_vy();
}

std::vector<float>* const & cfa::mus_tpfms_vz() const{
  return cfa_->mus_tpfms_vz();
}

UInt_t const & cfa::orbitNumber() const{
  return cfa_->orbitNumber();
}

std::vector<float>* const & cfa::pfcand_charge() const{
  return cfa_->pfcand_charge();
}

std::vector<float>* const & cfa::pfcand_energy() const{
  return cfa_->pfcand_energy();
}

std::vector<float>* const & cfa::pfcand_eta() const{
  return cfa_->pfcand_eta();
}

std::vector<float>* const & cfa::pfcand_pdgId() const{
  return cfa_->pfcand_pdgId();
}

std::vector<float>* const & cfa::pfcand_phi() const{
  return cfa_->pfcand_phi();
}

std::vector<float>* const & cfa::pfcand_pt() const{
  return cfa_->pfcand_pt();
}

std::vector<float>* const & cfa::pfcand_px() const{
  return cfa_->pfcand_px();
}

std::vector<float>* const & cfa::pfcand_py() const{
  return cfa_->pfcand_py();
}

std::vector<float>* const & cfa::pfcand_pz() const{
  return cfa_->pfcand_pz();
}

std::vector<float>* const & cfa::pfcand_theta() const{
  return cfa_->pfcand_theta();
}

std::vector<float>* const & cfa::photons_e1x5() const{
  return cfa_->photons_e1x5();
}

std::vector<float>* const & cfa::photons_e2x5() const{
  return cfa_->photons_e2x5();
}

std::vector<float>* const & cfa::photons_e3x3() const{
  return cfa_->photons_e3x3();
}

std::vector<float>* const & cfa::photons_e5x5() const{
  return cfa_->photons_e5x5();
}

std::vector<float>* const & cfa::photons_ecalIso() const{
  return cfa_->photons_ecalIso();
}

std::vector<float>* const & cfa::photons_energy() const{
  return cfa_->photons_energy();
}

std::vector<float>* const & cfa::photons_et() const{
  return cfa_->photons_et();
}

std::vector<float>* const & cfa::photons_eta() const{
  return cfa_->photons_eta();
}

std::vector<float>* const & cfa::photons_gen_et() const{
  return cfa_->photons_gen_et();
}

std::vector<float>* const & cfa::photons_gen_eta() const{
  return cfa_->photons_gen_eta();
}

std::vector<float>* const & cfa::photons_gen_id() const{
  return cfa_->photons_gen_id();
}

std::vector<float>* const & cfa::photons_gen_phi() const{
  return cfa_->photons_gen_phi();
}

std::vector<float>* const & cfa::photons_hadOverEM() const{
  return cfa_->photons_hadOverEM();
}

std::vector<float>* const & cfa::photons_hadTowOverEM() const{
  return cfa_->photons_hadTowOverEM();
}

std::vector<float>* const & cfa::photons_hasPixelSeed() const{
  return cfa_->photons_hasPixelSeed();
}

std::vector<float>* const & cfa::photons_hcalIso() const{
  return cfa_->photons_hcalIso();
}

std::vector<float>* const & cfa::photons_isAlsoElectron() const{
  return cfa_->photons_isAlsoElectron();
}

std::vector<float>* const & cfa::photons_isConverted() const{
  return cfa_->photons_isConverted();
}

std::vector<float>* const & cfa::photons_isEBEEGap() const{
  return cfa_->photons_isEBEEGap();
}

std::vector<float>* const & cfa::photons_isEBGap() const{
  return cfa_->photons_isEBGap();
}

std::vector<float>* const & cfa::photons_isEBPho() const{
  return cfa_->photons_isEBPho();
}

std::vector<float>* const & cfa::photons_isEEGap() const{
  return cfa_->photons_isEEGap();
}

std::vector<float>* const & cfa::photons_isEEPho() const{
  return cfa_->photons_isEEPho();
}

std::vector<float>* const & cfa::photons_isLoosePhoton() const{
  return cfa_->photons_isLoosePhoton();
}

std::vector<float>* const & cfa::photons_isTightPhoton() const{
  return cfa_->photons_isTightPhoton();
}

std::vector<float>* const & cfa::photons_isoEcalRecHitDR03() const{
  return cfa_->photons_isoEcalRecHitDR03();
}

std::vector<float>* const & cfa::photons_isoEcalRecHitDR04() const{
  return cfa_->photons_isoEcalRecHitDR04();
}

std::vector<float>* const & cfa::photons_isoHcalRecHitDR03() const{
  return cfa_->photons_isoHcalRecHitDR03();
}

std::vector<float>* const & cfa::photons_isoHcalRecHitDR04() const{
  return cfa_->photons_isoHcalRecHitDR04();
}

std::vector<float>* const & cfa::photons_isoHollowTrkConeDR03() const{
  return cfa_->photons_isoHollowTrkConeDR03();
}

std::vector<float>* const & cfa::photons_isoHollowTrkConeDR04() const{
  return cfa_->photons_isoHollowTrkConeDR04();
}

std::vector<float>* const & cfa::photons_isoSolidTrkConeDR03() const{
  return cfa_->photons_isoSolidTrkConeDR03();
}

std::vector<float>* const & cfa::photons_isoSolidTrkConeDR04() const{
  return cfa_->photons_isoSolidTrkConeDR04();
}

std::vector<float>* const & cfa::photons_maxEnergyXtal() const{
  return cfa_->photons_maxEnergyXtal();
}

std::vector<float>* const & cfa::photons_nTrkHollowConeDR03() const{
  return cfa_->photons_nTrkHollowConeDR03();
}

std::vector<float>* const & cfa::photons_nTrkHollowConeDR04() const{
  return cfa_->photons_nTrkHollowConeDR04();
}

std::vector<float>* const & cfa::photons_nTrkSolidConeDR03() const{
  return cfa_->photons_nTrkSolidConeDR03();
}

std::vector<float>* const & cfa::photons_nTrkSolidConeDR04() const{
  return cfa_->photons_nTrkSolidConeDR04();
}

std::vector<float>* const & cfa::photons_phi() const{
  return cfa_->photons_phi();
}

std::vector<float>* const & cfa::photons_pt() const{
  return cfa_->photons_pt();
}

std::vector<float>* const & cfa::photons_px() const{
  return cfa_->photons_px();
}

std::vector<float>* const & cfa::photons_py() const{
  return cfa_->photons_py();
}

std::vector<float>* const & cfa::photons_pz() const{
  return cfa_->photons_pz();
}

std::vector<float>* const & cfa::photons_r9() const{
  return cfa_->photons_r9();
}

std::vector<float>* const & cfa::photons_scEnergy() const{
  return cfa_->photons_scEnergy();
}

std::vector<float>* const & cfa::photons_scEta() const{
  return cfa_->photons_scEta();
}

std::vector<float>* const & cfa::photons_scEtaWidth() const{
  return cfa_->photons_scEtaWidth();
}

std::vector<float>* const & cfa::photons_scPhi() const{
  return cfa_->photons_scPhi();
}

std::vector<float>* const & cfa::photons_scPhiWidth() const{
  return cfa_->photons_scPhiWidth();
}

std::vector<float>* const & cfa::photons_scRawEnergy() const{
  return cfa_->photons_scRawEnergy();
}

std::vector<float>* const & cfa::photons_sigmaEtaEta() const{
  return cfa_->photons_sigmaEtaEta();
}

std::vector<float>* const & cfa::photons_sigmaIetaIeta() const{
  return cfa_->photons_sigmaIetaIeta();
}

std::vector<float>* const & cfa::photons_status() const{
  return cfa_->photons_status();
}

std::vector<float>* const & cfa::photons_tIso() const{
  return cfa_->photons_tIso();
}

std::vector<float>* const & cfa::photons_theta() const{
  return cfa_->photons_theta();
}

std::vector<float>* const & cfa::pv_chi2() const{
  return cfa_->pv_chi2();
}

std::vector<float>* const & cfa::pv_isFake() const{
  return cfa_->pv_isFake();
}

std::vector<float>* const & cfa::pv_isValid() const{
  return cfa_->pv_isValid();
}

std::vector<float>* const & cfa::pv_ndof() const{
  return cfa_->pv_ndof();
}

std::vector<float>* const & cfa::pv_tracksSize() const{
  return cfa_->pv_tracksSize();
}

std::vector<float>* const & cfa::pv_x() const{
  return cfa_->pv_x();
}

std::vector<float>* const & cfa::pv_xErr() const{
  return cfa_->pv_xErr();
}

std::vector<float>* const & cfa::pv_y() const{
  return cfa_->pv_y();
}

std::vector<float>* const & cfa::pv_yErr() const{
  return cfa_->pv_yErr();
}

std::vector<float>* const & cfa::pv_z() const{
  return cfa_->pv_z();
}

std::vector<float>* const & cfa::pv_zErr() const{
  return cfa_->pv_zErr();
}

UInt_t const & cfa::run() const{
  return cfa_->run();
}

std::vector<std::string>* const & cfa::standalone_triggerobject_collectionname() const{
  return cfa_->standalone_triggerobject_collectionname();
}

std::vector<float>* const & cfa::standalone_triggerobject_energy() const{
  return cfa_->standalone_triggerobject_energy();
}

std::vector<float>* const & cfa::standalone_triggerobject_et() const{
  return cfa_->standalone_triggerobject_et();
}

std::vector<float>* const & cfa::standalone_triggerobject_eta() const{
  return cfa_->standalone_triggerobject_eta();
}

std::vector<float>* const & cfa::standalone_triggerobject_phi() const{
  return cfa_->standalone_triggerobject_phi();
}

std::vector<float>* const & cfa::standalone_triggerobject_pt() const{
  return cfa_->standalone_triggerobject_pt();
}

std::vector<float>* const & cfa::standalone_triggerobject_px() const{
  return cfa_->standalone_triggerobject_px();
}

std::vector<float>* const & cfa::standalone_triggerobject_py() const{
  return cfa_->standalone_triggerobject_py();
}

std::vector<float>* const & cfa::standalone_triggerobject_pz() const{
  return cfa_->standalone_triggerobject_pz();
}

std::vector<float>* const & cfa::taus_Nprongs() const{
  return cfa_->taus_Nprongs();
}

std::vector<float>* const & cfa::taus_againstElectron() const{
  return cfa_->taus_againstElectron();
}

std::vector<float>* const & cfa::taus_againstElectronLoose() const{
  return cfa_->taus_againstElectronLoose();
}

std::vector<float>* const & cfa::taus_againstElectronMVA() const{
  return cfa_->taus_againstElectronMVA();
}

std::vector<float>* const & cfa::taus_againstElectronMedium() const{
  return cfa_->taus_againstElectronMedium();
}

std::vector<float>* const & cfa::taus_againstElectronTight() const{
  return cfa_->taus_againstElectronTight();
}

std::vector<float>* const & cfa::taus_againstMuon() const{
  return cfa_->taus_againstMuon();
}

std::vector<float>* const & cfa::taus_againstMuonLoose() const{
  return cfa_->taus_againstMuonLoose();
}

std::vector<float>* const & cfa::taus_againstMuonMedium() const{
  return cfa_->taus_againstMuonMedium();
}

std::vector<float>* const & cfa::taus_againstMuonTight() const{
  return cfa_->taus_againstMuonTight();
}

std::vector<float>* const & cfa::taus_byIsoUsingLeadingPi() const{
  return cfa_->taus_byIsoUsingLeadingPi();
}

std::vector<float>* const & cfa::taus_byIsolation() const{
  return cfa_->taus_byIsolation();
}

std::vector<float>* const & cfa::taus_byLooseIsolation() const{
  return cfa_->taus_byLooseIsolation();
}

std::vector<float>* const & cfa::taus_byLooseIsolationDeltaBetaCorr() const{
  return cfa_->taus_byLooseIsolationDeltaBetaCorr();
}

std::vector<float>* const & cfa::taus_byMediumIsolation() const{
  return cfa_->taus_byMediumIsolation();
}

std::vector<float>* const & cfa::taus_byMediumIsolationDeltaBetaCorr() const{
  return cfa_->taus_byMediumIsolationDeltaBetaCorr();
}

std::vector<float>* const & cfa::taus_byTightIsolation() const{
  return cfa_->taus_byTightIsolation();
}

std::vector<float>* const & cfa::taus_byTightIsolationDeltaBetaCorr() const{
  return cfa_->taus_byTightIsolationDeltaBetaCorr();
}

std::vector<float>* const & cfa::taus_byVLooseIsolation() const{
  return cfa_->taus_byVLooseIsolation();
}

std::vector<float>* const & cfa::taus_byVLooseIsolationDeltaBetaCorr() const{
  return cfa_->taus_byVLooseIsolationDeltaBetaCorr();
}

std::vector<float>* const & cfa::taus_charge() const{
  return cfa_->taus_charge();
}

std::vector<float>* const & cfa::taus_decayModeFinding() const{
  return cfa_->taus_decayModeFinding();
}

std::vector<float>* const & cfa::taus_ecalIsoUsingLeadingPi() const{
  return cfa_->taus_ecalIsoUsingLeadingPi();
}

std::vector<float>* const & cfa::taus_ecalIsolation() const{
  return cfa_->taus_ecalIsolation();
}

std::vector<float>* const & cfa::taus_ecalStripSumEOverPLead() const{
  return cfa_->taus_ecalStripSumEOverPLead();
}

std::vector<int>* const & cfa::taus_el_ind() const{
  return cfa_->taus_el_ind();
}

std::vector<float>* const & cfa::taus_elecPreIdDecision() const{
  return cfa_->taus_elecPreIdDecision();
}

std::vector<float>* const & cfa::taus_elecPreIdOutput() const{
  return cfa_->taus_elecPreIdOutput();
}

std::vector<float>* const & cfa::taus_emf() const{
  return cfa_->taus_emf();
}

std::vector<float>* const & cfa::taus_energy() const{
  return cfa_->taus_energy();
}

std::vector<float>* const & cfa::taus_et() const{
  return cfa_->taus_et();
}

std::vector<float>* const & cfa::taus_eta() const{
  return cfa_->taus_eta();
}

std::vector<float>* const & cfa::taus_hcal3x3OverPLead() const{
  return cfa_->taus_hcal3x3OverPLead();
}

std::vector<float>* const & cfa::taus_hcalMaxOverPLead() const{
  return cfa_->taus_hcalMaxOverPLead();
}

std::vector<float>* const & cfa::taus_hcalTotOverPLead() const{
  return cfa_->taus_hcalTotOverPLead();
}

std::vector<float>* const & cfa::taus_isoPFChargedHadrCandsPtSum() const{
  return cfa_->taus_isoPFChargedHadrCandsPtSum();
}

std::vector<float>* const & cfa::taus_isoPFGammaCandsEtSum() const{
  return cfa_->taus_isoPFGammaCandsEtSum();
}

std::vector<float>* const & cfa::taus_leadPFChargedHadrCand_ECAL_eta() const{
  return cfa_->taus_leadPFChargedHadrCand_ECAL_eta();
}

std::vector<float>* const & cfa::taus_leadPFChargedHadrCand_charge() const{
  return cfa_->taus_leadPFChargedHadrCand_charge();
}

std::vector<float>* const & cfa::taus_leadPFChargedHadrCand_eta() const{
  return cfa_->taus_leadPFChargedHadrCand_eta();
}

std::vector<float>* const & cfa::taus_leadPFChargedHadrCand_phi() const{
  return cfa_->taus_leadPFChargedHadrCand_phi();
}

std::vector<float>* const & cfa::taus_leadPFChargedHadrCand_pt() const{
  return cfa_->taus_leadPFChargedHadrCand_pt();
}

std::vector<float>* const & cfa::taus_leadingTrackFinding() const{
  return cfa_->taus_leadingTrackFinding();
}

std::vector<float>* const & cfa::taus_leadingTrackPtCut() const{
  return cfa_->taus_leadingTrackPtCut();
}

std::vector<float>* const & cfa::taus_muDecision() const{
  return cfa_->taus_muDecision();
}

std::vector<int>* const & cfa::taus_mu_ind() const{
  return cfa_->taus_mu_ind();
}

std::vector<float>* const & cfa::taus_phi() const{
  return cfa_->taus_phi();
}

std::vector<float>* const & cfa::taus_pt() const{
  return cfa_->taus_pt();
}

std::vector<float>* const & cfa::taus_px() const{
  return cfa_->taus_px();
}

std::vector<float>* const & cfa::taus_py() const{
  return cfa_->taus_py();
}

std::vector<float>* const & cfa::taus_pz() const{
  return cfa_->taus_pz();
}

std::vector<float>* const & cfa::taus_signalPFChargedHadrCandsSize() const{
  return cfa_->taus_signalPFChargedHadrCandsSize();
}

std::vector<float>* const & cfa::taus_status() const{
  return cfa_->taus_status();
}

std::vector<float>* const & cfa::taus_taNC() const{
  return cfa_->taus_taNC();
}

std::vector<float>* const & cfa::taus_taNC_half() const{
  return cfa_->taus_taNC_half();
}

std::vector<float>* const & cfa::taus_taNC_one() const{
  return cfa_->taus_taNC_one();
}

std::vector<float>* const & cfa::taus_taNC_quarter() const{
  return cfa_->taus_taNC_quarter();
}

std::vector<float>* const & cfa::taus_taNC_tenth() const{
  return cfa_->taus_taNC_tenth();
}

std::vector<float>* const & cfa::taus_theta() const{
  return cfa_->taus_theta();
}

std::vector<float>* const & cfa::taus_tkIsoUsingLeadingPi() const{
  return cfa_->taus_tkIsoUsingLeadingPi();
}

std::vector<float>* const & cfa::taus_trackIsolation() const{
  return cfa_->taus_trackIsolation();
}

Int_t const & cfa::trackingfailurefilter_decision() const{
  return cfa_->trackingfailurefilter_decision();
}

std::vector<bool>* const & cfa::trigger_decision() const{
  return cfa_->trigger_decision();
}

std::vector<std::string>* const & cfa::trigger_name() const{
  return cfa_->trigger_name();
}

std::vector<float>* const & cfa::trigger_prescalevalue() const{
  return cfa_->trigger_prescalevalue();
}

Int_t const & cfa::trkPOG_logErrorTooManyClustersfilter_decision() const{
  return cfa_->trkPOG_logErrorTooManyClustersfilter_decision();
}

Int_t const & cfa::trkPOG_manystripclus53Xfilter_decision() const{
  return cfa_->trkPOG_manystripclus53Xfilter_decision();
}

Int_t const & cfa::trkPOG_toomanystripclus53Xfilter_decision() const{
  return cfa_->trkPOG_toomanystripclus53Xfilter_decision();
}

Int_t const & cfa::trkPOGfilter_decision() const{
  return cfa_->trkPOGfilter_decision();
}

Float_t const & cfa::weight() const{
  return cfa_->weight();
}

