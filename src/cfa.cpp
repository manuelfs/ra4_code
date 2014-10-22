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

std::vector<std::string>* const & cfa::L1trigger_alias() const{
  return cfa_->L1trigger_alias();
}

std::vector<float>* const & cfa::L1trigger_bit() const{
  return cfa_->L1trigger_bit();
}

std::vector<float>* const & cfa::L1trigger_decision() const{
  return cfa_->L1trigger_decision();
}

std::vector<float>* const & cfa::L1trigger_decision_nomask() const{
  return cfa_->L1trigger_decision_nomask();
}

std::vector<std::string>* const & cfa::L1trigger_name() const{
  return cfa_->L1trigger_name();
}

std::vector<float>* const & cfa::L1trigger_prescalevalue() const{
  return cfa_->L1trigger_prescalevalue();
}

std::vector<float>* const & cfa::L1trigger_techTrigger() const{
  return cfa_->L1trigger_techTrigger();
}

Int_t const & cfa::METFiltersfilter_decision() const{
  return cfa_->METFiltersfilter_decision();
}

Float_t const & cfa::MPT() const{
  return cfa_->MPT();
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

UInt_t const & cfa::Njets_AK5PF() const{
  return cfa_->Njets_AK5PF();
}

UInt_t const & cfa::Njets_AK5PFclean() const{
  return cfa_->Njets_AK5PFclean();
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

UInt_t const & cfa::Nmc_pdf() const{
  return cfa_->Nmc_pdf();
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

UInt_t const & cfa::NmetsHO() const{
  return cfa_->NmetsHO();
}

UInt_t const & cfa::Nmets_AK5() const{
  return cfa_->Nmets_AK5();
}

UInt_t const & cfa::Nmus() const{
  return cfa_->Nmus();
}

UInt_t const & cfa::NpfTypeINoXYCorrmets() const{
  return cfa_->NpfTypeINoXYCorrmets();
}

UInt_t const & cfa::NpfTypeIType0mets() const{
  return cfa_->NpfTypeIType0mets();
}

UInt_t const & cfa::NpfTypeImets() const{
  return cfa_->NpfTypeImets();
}

UInt_t const & cfa::Npf_els() const{
  return cfa_->Npf_els();
}

UInt_t const & cfa::Npf_mus() const{
  return cfa_->Npf_mus();
}

UInt_t const & cfa::Npf_photons() const{
  return cfa_->Npf_photons();
}

UInt_t const & cfa::Npfcand() const{
  return cfa_->Npfcand();
}

UInt_t const & cfa::Npfmets() const{
  return cfa_->Npfmets();
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

UInt_t const & cfa::Ntcmets() const{
  return cfa_->Ntcmets();
}

UInt_t const & cfa::Ntracks() const{
  return cfa_->Ntracks();
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

Int_t const & cfa::ecalBEfilter_decision() const{
  return cfa_->ecalBEfilter_decision();
}

Int_t const & cfa::ecalTPfilter_decision() const{
  return cfa_->ecalTPfilter_decision();
}

Int_t const & cfa::ecallaserfilter_decision() const{
  return cfa_->ecallaserfilter_decision();
}

Int_t const & cfa::eebadscfilter_decision() const{
  return cfa_->eebadscfilter_decision();
}

Int_t const & cfa::eenoisefilter_decision() const{
  return cfa_->eenoisefilter_decision();
}

std::vector<float>* const & cfa::els_PATpassConversionVeto(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_PATpassConversionVeto();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_PATpassConversionVeto();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_PATpassConversionVeto();
}

std::vector<float>* const & cfa::els_PFchargedHadronIsoR03(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_PFchargedHadronIsoR03();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_PFchargedHadronIsoR03();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_PFchargedHadronIsoR03();
}

std::vector<float>* const & cfa::els_PFneutralHadronIsoR03(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_PFneutralHadronIsoR03();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_PFneutralHadronIsoR03();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_PFneutralHadronIsoR03();
}

std::vector<float>* const & cfa::els_PFphotonIsoR03(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_PFphotonIsoR03();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_PFphotonIsoR03();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_PFphotonIsoR03();
}

std::vector<float>* const & cfa::els_basicClustersSize(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_basicClustersSize();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_basicClustersSize();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_basicClustersSize();
}

std::vector<float>* const & cfa::els_cIso(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_cIso();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_cIso();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_cIso();
}

std::vector<float>* const & cfa::els_caloEnergy(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_caloEnergy();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_caloEnergy();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_caloEnergy();
}

std::vector<float>* const & cfa::els_charge(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_charge();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_charge();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_charge();
}

std::vector<float>* const & cfa::els_chi2(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_chi2();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_chi2();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_chi2();
}

std::vector<float>* const & cfa::els_conversion_dcot(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_conversion_dcot();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_conversion_dcot();
}

std::vector<float>* const & cfa::els_conversion_dist(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_conversion_dist();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_conversion_dist();
}

std::vector<float>* const & cfa::els_core_ecalDrivenSeed(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_core_ecalDrivenSeed();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_core_ecalDrivenSeed();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_core_ecalDrivenSeed();
}

std::vector<float>* const & cfa::els_cpx(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_cpx();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_cpx();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_cpx();
}

std::vector<float>* const & cfa::els_cpy(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_cpy();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_cpy();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_cpy();
}

std::vector<float>* const & cfa::els_cpz(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_cpz();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_cpz();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_cpz();
}

std::vector<float>* const & cfa::els_ctf_tk_charge(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_ctf_tk_charge();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_ctf_tk_charge();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_ctf_tk_charge();
}

std::vector<float>* const & cfa::els_ctf_tk_eta(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_ctf_tk_eta();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_ctf_tk_eta();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_ctf_tk_eta();
}

std::vector<float>* const & cfa::els_ctf_tk_id(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_ctf_tk_id();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_ctf_tk_id();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_ctf_tk_id();
}

std::vector<float>* const & cfa::els_ctf_tk_phi(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_ctf_tk_phi();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_ctf_tk_phi();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_ctf_tk_phi();
}

std::vector<float>* const & cfa::els_cx(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_cx();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_cx();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_cx();
}

std::vector<float>* const & cfa::els_cy(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_cy();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_cy();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_cy();
}

std::vector<float>* const & cfa::els_cz(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_cz();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_cz();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_cz();
}

std::vector<float>* const & cfa::els_d0dum(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_d0dum();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_d0dum();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_d0dum();
}

std::vector<float>* const & cfa::els_d0dumError(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_d0dumError();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_d0dumError();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_d0dumError();
}

std::vector<float>* const & cfa::els_dEtaIn(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_dEtaIn();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_dEtaIn();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_dEtaIn();
}

std::vector<float>* const & cfa::els_dEtaOut(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_dEtaOut();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_dEtaOut();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_dEtaOut();
}

std::vector<float>* const & cfa::els_dPhiIn(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_dPhiIn();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_dPhiIn();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_dPhiIn();
}

std::vector<float>* const & cfa::els_dPhiOut(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_dPhiOut();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_dPhiOut();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_dPhiOut();
}

std::vector<float>* const & cfa::els_dr03EcalRecHitSumEt(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_dr03EcalRecHitSumEt();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_dr03EcalRecHitSumEt();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_dr03EcalRecHitSumEt();
}

std::vector<float>* const & cfa::els_dr03HcalDepth1TowerSumEt(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_dr03HcalDepth1TowerSumEt();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_dr03HcalDepth1TowerSumEt();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_dr03HcalDepth1TowerSumEt();
}

std::vector<float>* const & cfa::els_dr03HcalDepth2TowerSumEt(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_dr03HcalDepth2TowerSumEt();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_dr03HcalDepth2TowerSumEt();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_dr03HcalDepth2TowerSumEt();
}

std::vector<float>* const & cfa::els_dr03HcalTowerSumEt(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_dr03HcalTowerSumEt();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_dr03HcalTowerSumEt();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_dr03HcalTowerSumEt();
}

std::vector<float>* const & cfa::els_dr03TkSumPt(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_dr03TkSumPt();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_dr03TkSumPt();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_dr03TkSumPt();
}

std::vector<float>* const & cfa::els_dr04EcalRecHitSumEt(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_dr04EcalRecHitSumEt();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_dr04EcalRecHitSumEt();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_dr04EcalRecHitSumEt();
}

std::vector<float>* const & cfa::els_dr04HcalDepth1TowerSumEt(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_dr04HcalDepth1TowerSumEt();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_dr04HcalDepth1TowerSumEt();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_dr04HcalDepth1TowerSumEt();
}

std::vector<float>* const & cfa::els_dr04HcalDepth2TowerSumEt(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_dr04HcalDepth2TowerSumEt();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_dr04HcalDepth2TowerSumEt();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_dr04HcalDepth2TowerSumEt();
}

std::vector<float>* const & cfa::els_dr04HcalTowerSumEt(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_dr04HcalTowerSumEt();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_dr04HcalTowerSumEt();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_dr04HcalTowerSumEt();
}

std::vector<float>* const & cfa::els_dr04TkSumPt(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_dr04TkSumPt();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_dr04TkSumPt();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_dr04TkSumPt();
}

std::vector<float>* const & cfa::els_dz(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_dz();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_dz();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_dz();
}

std::vector<float>* const & cfa::els_dzError(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_dzError();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_dzError();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_dzError();
}

std::vector<float>* const & cfa::els_eOverPIn(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_eOverPIn();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_eOverPIn();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_eOverPIn();
}

std::vector<float>* const & cfa::els_eSeedOverPOut(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_eSeedOverPOut();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_eSeedOverPOut();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_eSeedOverPOut();
}

std::vector<float>* const & cfa::els_ecalIso(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_ecalIso();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_ecalIso();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_ecalIso();
}

std::vector<float>* const & cfa::els_energy(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_energy();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_energy();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_energy();
}

std::vector<float>* const & cfa::els_et(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_et();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_et();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_et();
}

std::vector<float>* const & cfa::els_eta(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_eta();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_eta();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_eta();
}

std::vector<float>* const & cfa::els_etaError(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_etaError();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_etaError();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_etaError();
}

std::vector<float>* const & cfa::els_fbrem(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_fbrem();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_fbrem();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_fbrem();
}

std::vector<float>* const & cfa::els_full5x5_sigmaIetaIeta(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_full5x5_sigmaIetaIeta();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_full5x5_sigmaIetaIeta();
}

std::vector<float>* const & cfa::els_gen_et(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_gen_et();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_gen_et();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_gen_et();
}

std::vector<float>* const & cfa::els_gen_eta(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_gen_eta();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_gen_eta();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_gen_eta();
}

std::vector<float>* const & cfa::els_gen_id(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_gen_id();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_gen_id();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_gen_id();
}

std::vector<float>* const & cfa::els_gen_mother_et(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_gen_mother_et();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_gen_mother_et();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_gen_mother_et();
}

std::vector<float>* const & cfa::els_gen_mother_eta(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_gen_mother_eta();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_gen_mother_eta();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_gen_mother_eta();
}

std::vector<float>* const & cfa::els_gen_mother_id(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_gen_mother_id();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_gen_mother_id();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_gen_mother_id();
}

std::vector<float>* const & cfa::els_gen_mother_phi(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_gen_mother_phi();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_gen_mother_phi();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_gen_mother_phi();
}

std::vector<float>* const & cfa::els_gen_mother_pt(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_gen_mother_pt();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_gen_mother_pt();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_gen_mother_pt();
}

std::vector<float>* const & cfa::els_gen_mother_px(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_gen_mother_px();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_gen_mother_px();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_gen_mother_px();
}

std::vector<float>* const & cfa::els_gen_mother_py(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_gen_mother_py();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_gen_mother_py();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_gen_mother_py();
}

std::vector<float>* const & cfa::els_gen_mother_pz(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_gen_mother_pz();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_gen_mother_pz();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_gen_mother_pz();
}

std::vector<float>* const & cfa::els_gen_mother_theta(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_gen_mother_theta();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_gen_mother_theta();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_gen_mother_theta();
}

std::vector<float>* const & cfa::els_gen_phi(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_gen_phi();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_gen_phi();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_gen_phi();
}

std::vector<float>* const & cfa::els_gen_pt(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_gen_pt();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_gen_pt();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_gen_pt();
}

std::vector<float>* const & cfa::els_gen_px(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_gen_px();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_gen_px();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_gen_px();
}

std::vector<float>* const & cfa::els_gen_py(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_gen_py();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_gen_py();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_gen_py();
}

std::vector<float>* const & cfa::els_gen_pz(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_gen_pz();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_gen_pz();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_gen_pz();
}

std::vector<float>* const & cfa::els_gen_theta(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_gen_theta();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_gen_theta();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_gen_theta();
}

std::vector<float>* const & cfa::els_hadOverEm(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_hadOverEm();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_hadOverEm();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_hadOverEm();
}

std::vector<bool>* const & cfa::els_hasMatchedConversion(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_hasMatchedConversion();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_hasMatchedConversion();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_hasMatchedConversion();
}

std::vector<float>* const & cfa::els_hcalIso(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_hcalIso();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_hcalIso();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_hcalIso();
}

std::vector<float>* const & cfa::els_hcalOverEcalBc(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_hcalOverEcalBc();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_hcalOverEcalBc();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_hcalOverEcalBc();
}

std::vector<float>* const & cfa::els_isEB(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_isEB();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_isEB();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_isEB();
}

std::vector<float>* const & cfa::els_isEE(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_isEE();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_isEE();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_isEE();
}

std::vector<bool>* const & cfa::els_isPF(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_isPF();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_isPF();
}

std::vector<int>* const & cfa::els_jet_ind(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_jet_ind();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_jet_ind();
}

std::vector<float>* const & cfa::els_looseId(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_looseId();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_looseId();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_looseId();
}

std::vector<float>* const & cfa::els_n_inner_layer(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_n_inner_layer();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_n_inner_layer();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_n_inner_layer();
}

std::vector<float>* const & cfa::els_n_outer_layer(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_n_outer_layer();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_n_outer_layer();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_n_outer_layer();
}

std::vector<float>* const & cfa::els_ndof(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_ndof();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_ndof();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_ndof();
}

std::vector<float>* const & cfa::els_numlosthits(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_numlosthits();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_numlosthits();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_numlosthits();
}

std::vector<float>* const & cfa::els_numvalhits(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_numvalhits();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_numvalhits();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_numvalhits();
}

std::vector<float>* const & cfa::els_pfIsolationR03_sumChargedHadronPt(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_pfIsolationR03_sumChargedHadronPt();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_pfIsolationR03_sumChargedHadronPt();
}

std::vector<float>* const & cfa::els_pfIsolationR03_sumNeutralHadronEt(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_pfIsolationR03_sumNeutralHadronEt();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_pfIsolationR03_sumNeutralHadronEt();
}

std::vector<float>* const & cfa::els_pfIsolationR03_sumPUPt(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_pfIsolationR03_sumPUPt();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_pfIsolationR03_sumPUPt();
}

std::vector<float>* const & cfa::els_pfIsolationR03_sumPhotonEt(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_pfIsolationR03_sumPhotonEt();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_pfIsolationR03_sumPhotonEt();
}

std::vector<float>* const & cfa::els_phi(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_phi();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_phi();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_phi();
}

std::vector<float>* const & cfa::els_phiError(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_phiError();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_phiError();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_phiError();
}

std::vector<float>* const & cfa::els_pt(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_pt();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_pt();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_pt();
}

std::vector<float>* const & cfa::els_ptError(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_ptError();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_ptError();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_ptError();
}

std::vector<float>* const & cfa::els_px(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_px();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_px();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_px();
}

std::vector<float>* const & cfa::els_py(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_py();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_py();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_py();
}

std::vector<float>* const & cfa::els_pz(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_pz();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_pz();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_pz();
}

std::vector<float>* const & cfa::els_robustHighEnergyId(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_robustHighEnergyId();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_robustHighEnergyId();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_robustHighEnergyId();
}

std::vector<float>* const & cfa::els_robustLooseId(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_robustLooseId();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_robustLooseId();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_robustLooseId();
}

std::vector<float>* const & cfa::els_robustTightId(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_robustTightId();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_robustTightId();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_robustTightId();
}

std::vector<float>* const & cfa::els_scE1x5(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_scE1x5();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_scE1x5();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_scE1x5();
}

std::vector<float>* const & cfa::els_scE2x5Max(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_scE2x5Max();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_scE2x5Max();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_scE2x5Max();
}

std::vector<float>* const & cfa::els_scE5x5(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_scE5x5();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_scE5x5();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_scE5x5();
}

std::vector<float>* const & cfa::els_scEnergy(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_scEnergy();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_scEnergy();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_scEnergy();
}

std::vector<float>* const & cfa::els_scEta(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_scEta();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_scEta();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_scEta();
}

std::vector<float>* const & cfa::els_scEtaWidth(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_scEtaWidth();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_scEtaWidth();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_scEtaWidth();
}

std::vector<float>* const & cfa::els_scPhi(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_scPhi();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_scPhi();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_scPhi();
}

std::vector<float>* const & cfa::els_scPhiWidth(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_scPhiWidth();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_scPhiWidth();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_scPhiWidth();
}

std::vector<float>* const & cfa::els_scRawEnergy(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_scRawEnergy();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_scRawEnergy();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_scRawEnergy();
}

std::vector<float>* const & cfa::els_scSeedEnergy(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_scSeedEnergy();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_scSeedEnergy();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_scSeedEnergy();
}

std::vector<float>* const & cfa::els_shFracInnerHits(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_shFracInnerHits();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_shFracInnerHits();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_shFracInnerHits();
}

std::vector<float>* const & cfa::els_sigmaEtaEta(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_sigmaEtaEta();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_sigmaEtaEta();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_sigmaEtaEta();
}

std::vector<float>* const & cfa::els_sigmaIEtaIEta(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_sigmaIEtaIEta();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_sigmaIEtaIEta();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_sigmaIEtaIEta();
}

std::vector<float>* const & cfa::els_simpleEleId60cIso(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_simpleEleId60cIso();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_simpleEleId60cIso();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_simpleEleId60cIso();
}

std::vector<float>* const & cfa::els_simpleEleId60relIso(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_simpleEleId60relIso();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_simpleEleId60relIso();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_simpleEleId60relIso();
}

std::vector<float>* const & cfa::els_simpleEleId70cIso(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_simpleEleId70cIso();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_simpleEleId70cIso();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_simpleEleId70cIso();
}

std::vector<float>* const & cfa::els_simpleEleId70relIso(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_simpleEleId70relIso();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_simpleEleId70relIso();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_simpleEleId70relIso();
}

std::vector<float>* const & cfa::els_simpleEleId80cIso(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_simpleEleId80cIso();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_simpleEleId80cIso();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_simpleEleId80cIso();
}

std::vector<float>* const & cfa::els_simpleEleId80relIso(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_simpleEleId80relIso();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_simpleEleId80relIso();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_simpleEleId80relIso();
}

std::vector<float>* const & cfa::els_simpleEleId85cIso(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_simpleEleId85cIso();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_simpleEleId85cIso();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_simpleEleId85cIso();
}

std::vector<float>* const & cfa::els_simpleEleId85relIso(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_simpleEleId85relIso();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_simpleEleId85relIso();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_simpleEleId85relIso();
}

std::vector<float>* const & cfa::els_simpleEleId90cIso(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_simpleEleId90cIso();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_simpleEleId90cIso();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_simpleEleId90cIso();
}

std::vector<float>* const & cfa::els_simpleEleId90relIso(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_simpleEleId90relIso();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_simpleEleId90relIso();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_simpleEleId90relIso();
}

std::vector<float>* const & cfa::els_simpleEleId95cIso(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_simpleEleId95cIso();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_simpleEleId95cIso();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_simpleEleId95cIso();
}

std::vector<float>* const & cfa::els_simpleEleId95relIso(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_simpleEleId95relIso();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_simpleEleId95relIso();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_simpleEleId95relIso();
}

std::vector<float>* const & cfa::els_status(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_status();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_status();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_status();
}

std::vector<float>* const & cfa::els_tIso(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_tIso();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_tIso();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_tIso();
}

std::vector<float>* const & cfa::els_theta(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_theta();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_theta();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_theta();
}

std::vector<float>* const & cfa::els_tightId(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_tightId();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_tightId();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_tightId();
}

std::vector<float>* const & cfa::els_tk_charge(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_tk_charge();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_tk_charge();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_tk_charge();
}

std::vector<float>* const & cfa::els_tk_eta(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_tk_eta();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_tk_eta();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_tk_eta();
}

std::vector<float>* const & cfa::els_tk_phi(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_tk_phi();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_tk_phi();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_tk_phi();
}

std::vector<float>* const & cfa::els_tk_pt(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_tk_pt();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_tk_pt();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_tk_pt();
}

std::vector<float>* const & cfa::els_tk_pz(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_tk_pz();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_tk_pz();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_tk_pz();
}

std::vector<float>* const & cfa::els_vpx(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_vpx();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_vpx();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_vpx();
}

std::vector<float>* const & cfa::els_vpy(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_vpy();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_vpy();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_vpy();
}

std::vector<float>* const & cfa::els_vpz(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_vpz();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_vpz();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_vpz();
}

std::vector<float>* const & cfa::els_vx(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_vx();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_vx();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_vx();
}

std::vector<float>* const & cfa::els_vy(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_vy();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_vy();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->els_vy();
}

std::vector<float>* const & cfa::els_vz(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_els_vz();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->els_vz();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
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

Float_t const & cfa::genHT() const{
  return cfa_->genHT();
}

Int_t const & cfa::goodVerticesfilter_decision() const{
  return cfa_->goodVerticesfilter_decision();
}

Int_t const & cfa::greedymuonfilter_decision() const{
  return cfa_->greedymuonfilter_decision();
}

Int_t const & cfa::hbhefilter_decision() const{
  return cfa_->hbhefilter_decision();
}

Int_t const & cfa::hcallaserfilter_decision() const{
  return cfa_->hcallaserfilter_decision();
}

Int_t const & cfa::inconsistentPFmuonfilter_decision() const{
  return cfa_->inconsistentPFmuonfilter_decision();
}

std::vector<int>* const & cfa::isotk_charge() const{
  return cfa_->isotk_charge();
}

std::vector<float>* const & cfa::isotk_dzpv() const{
  return cfa_->isotk_dzpv();
}

std::vector<float>* const & cfa::isotk_eta() const{
  return cfa_->isotk_eta();
}

std::vector<float>* const & cfa::isotk_iso() const{
  return cfa_->isotk_iso();
}

std::vector<float>* const & cfa::isotk_phi() const{
  return cfa_->isotk_phi();
}

std::vector<float>* const & cfa::isotk_pt() const{
  return cfa_->isotk_pt();
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

std::vector<float>* const & cfa::jets_AK5PF_area() const{
  return cfa_->jets_AK5PF_area();
}

std::vector<float>* const & cfa::jets_AK5PF_btag_TC_highEff() const{
  return cfa_->jets_AK5PF_btag_TC_highEff();
}

std::vector<float>* const & cfa::jets_AK5PF_btag_TC_highPur() const{
  return cfa_->jets_AK5PF_btag_TC_highPur();
}

std::vector<float>* const & cfa::jets_AK5PF_btag_jetBProb() const{
  return cfa_->jets_AK5PF_btag_jetBProb();
}

std::vector<float>* const & cfa::jets_AK5PF_btag_jetProb() const{
  return cfa_->jets_AK5PF_btag_jetProb();
}

std::vector<float>* const & cfa::jets_AK5PF_btag_secVertexCombined() const{
  return cfa_->jets_AK5PF_btag_secVertexCombined();
}

std::vector<float>* const & cfa::jets_AK5PF_btag_secVertexHighEff() const{
  return cfa_->jets_AK5PF_btag_secVertexHighEff();
}

std::vector<float>* const & cfa::jets_AK5PF_btag_secVertexHighPur() const{
  return cfa_->jets_AK5PF_btag_secVertexHighPur();
}

std::vector<float>* const & cfa::jets_AK5PF_btag_softEle() const{
  return cfa_->jets_AK5PF_btag_softEle();
}

std::vector<float>* const & cfa::jets_AK5PF_btag_softMuon() const{
  return cfa_->jets_AK5PF_btag_softMuon();
}

std::vector<float>* const & cfa::jets_AK5PF_chgEmE() const{
  return cfa_->jets_AK5PF_chgEmE();
}

std::vector<float>* const & cfa::jets_AK5PF_chgHadE() const{
  return cfa_->jets_AK5PF_chgHadE();
}

std::vector<float>* const & cfa::jets_AK5PF_chgMuE() const{
  return cfa_->jets_AK5PF_chgMuE();
}

std::vector<float>* const & cfa::jets_AK5PF_chg_Mult() const{
  return cfa_->jets_AK5PF_chg_Mult();
}

std::vector<float>* const & cfa::jets_AK5PF_corrFactorRaw() const{
  return cfa_->jets_AK5PF_corrFactorRaw();
}

std::vector<float>* const & cfa::jets_AK5PF_ehf() const{
  return cfa_->jets_AK5PF_ehf();
}

std::vector<float>* const & cfa::jets_AK5PF_emf() const{
  return cfa_->jets_AK5PF_emf();
}

std::vector<float>* const & cfa::jets_AK5PF_energy() const{
  return cfa_->jets_AK5PF_energy();
}

std::vector<float>* const & cfa::jets_AK5PF_et() const{
  return cfa_->jets_AK5PF_et();
}

std::vector<float>* const & cfa::jets_AK5PF_eta() const{
  return cfa_->jets_AK5PF_eta();
}

std::vector<float>* const & cfa::jets_AK5PF_etaetaMoment() const{
  return cfa_->jets_AK5PF_etaetaMoment();
}

std::vector<float>* const & cfa::jets_AK5PF_etaphiMoment() const{
  return cfa_->jets_AK5PF_etaphiMoment();
}

std::vector<float>* const & cfa::jets_AK5PF_fHPD() const{
  return cfa_->jets_AK5PF_fHPD();
}

std::vector<float>* const & cfa::jets_AK5PF_fRBX() const{
  return cfa_->jets_AK5PF_fRBX();
}

std::vector<float>* const & cfa::jets_AK5PF_fSubDetector1() const{
  return cfa_->jets_AK5PF_fSubDetector1();
}

std::vector<float>* const & cfa::jets_AK5PF_fSubDetector2() const{
  return cfa_->jets_AK5PF_fSubDetector2();
}

std::vector<float>* const & cfa::jets_AK5PF_fSubDetector3() const{
  return cfa_->jets_AK5PF_fSubDetector3();
}

std::vector<float>* const & cfa::jets_AK5PF_fSubDetector4() const{
  return cfa_->jets_AK5PF_fSubDetector4();
}

std::vector<float>* const & cfa::jets_AK5PF_gen_Energy() const{
  return cfa_->jets_AK5PF_gen_Energy();
}

std::vector<float>* const & cfa::jets_AK5PF_gen_Id() const{
  return cfa_->jets_AK5PF_gen_Id();
}

std::vector<float>* const & cfa::jets_AK5PF_gen_et() const{
  return cfa_->jets_AK5PF_gen_et();
}

std::vector<float>* const & cfa::jets_AK5PF_gen_eta() const{
  return cfa_->jets_AK5PF_gen_eta();
}

std::vector<float>* const & cfa::jets_AK5PF_gen_mass() const{
  return cfa_->jets_AK5PF_gen_mass();
}

std::vector<float>* const & cfa::jets_AK5PF_gen_motherID() const{
  return cfa_->jets_AK5PF_gen_motherID();
}

std::vector<float>* const & cfa::jets_AK5PF_gen_phi() const{
  return cfa_->jets_AK5PF_gen_phi();
}

std::vector<float>* const & cfa::jets_AK5PF_gen_pt() const{
  return cfa_->jets_AK5PF_gen_pt();
}

std::vector<float>* const & cfa::jets_AK5PF_gen_threeCharge() const{
  return cfa_->jets_AK5PF_gen_threeCharge();
}

std::vector<float>* const & cfa::jets_AK5PF_hitsInN90() const{
  return cfa_->jets_AK5PF_hitsInN90();
}

std::vector<float>* const & cfa::jets_AK5PF_jetCharge() const{
  return cfa_->jets_AK5PF_jetCharge();
}

std::vector<float>* const & cfa::jets_AK5PF_mass() const{
  return cfa_->jets_AK5PF_mass();
}

std::vector<float>* const & cfa::jets_AK5PF_mu_Mult() const{
  return cfa_->jets_AK5PF_mu_Mult();
}

std::vector<float>* const & cfa::jets_AK5PF_n60() const{
  return cfa_->jets_AK5PF_n60();
}

std::vector<float>* const & cfa::jets_AK5PF_n90() const{
  return cfa_->jets_AK5PF_n90();
}

std::vector<float>* const & cfa::jets_AK5PF_n90Hits() const{
  return cfa_->jets_AK5PF_n90Hits();
}

std::vector<float>* const & cfa::jets_AK5PF_nECALTowers() const{
  return cfa_->jets_AK5PF_nECALTowers();
}

std::vector<float>* const & cfa::jets_AK5PF_nHCALTowers() const{
  return cfa_->jets_AK5PF_nHCALTowers();
}

std::vector<float>* const & cfa::jets_AK5PF_neutralEmE() const{
  return cfa_->jets_AK5PF_neutralEmE();
}

std::vector<float>* const & cfa::jets_AK5PF_neutralHadE() const{
  return cfa_->jets_AK5PF_neutralHadE();
}

std::vector<float>* const & cfa::jets_AK5PF_neutral_Mult() const{
  return cfa_->jets_AK5PF_neutral_Mult();
}

std::vector<float>* const & cfa::jets_AK5PF_partonFlavour() const{
  return cfa_->jets_AK5PF_partonFlavour();
}

std::vector<float>* const & cfa::jets_AK5PF_parton_Energy() const{
  return cfa_->jets_AK5PF_parton_Energy();
}

std::vector<float>* const & cfa::jets_AK5PF_parton_Id() const{
  return cfa_->jets_AK5PF_parton_Id();
}

std::vector<float>* const & cfa::jets_AK5PF_parton_eta() const{
  return cfa_->jets_AK5PF_parton_eta();
}

std::vector<float>* const & cfa::jets_AK5PF_parton_mass() const{
  return cfa_->jets_AK5PF_parton_mass();
}

std::vector<float>* const & cfa::jets_AK5PF_parton_motherId() const{
  return cfa_->jets_AK5PF_parton_motherId();
}

std::vector<float>* const & cfa::jets_AK5PF_parton_phi() const{
  return cfa_->jets_AK5PF_parton_phi();
}

std::vector<float>* const & cfa::jets_AK5PF_parton_pt() const{
  return cfa_->jets_AK5PF_parton_pt();
}

std::vector<float>* const & cfa::jets_AK5PF_phi() const{
  return cfa_->jets_AK5PF_phi();
}

std::vector<float>* const & cfa::jets_AK5PF_phiphiMoment() const{
  return cfa_->jets_AK5PF_phiphiMoment();
}

std::vector<float>* const & cfa::jets_AK5PF_photonEnergy() const{
  return cfa_->jets_AK5PF_photonEnergy();
}

std::vector<float>* const & cfa::jets_AK5PF_pt() const{
  return cfa_->jets_AK5PF_pt();
}

std::vector<float>* const & cfa::jets_AK5PF_px() const{
  return cfa_->jets_AK5PF_px();
}

std::vector<float>* const & cfa::jets_AK5PF_py() const{
  return cfa_->jets_AK5PF_py();
}

std::vector<float>* const & cfa::jets_AK5PF_pz() const{
  return cfa_->jets_AK5PF_pz();
}

std::vector<float>* const & cfa::jets_AK5PF_rawPt() const{
  return cfa_->jets_AK5PF_rawPt();
}

std::vector<float>* const & cfa::jets_AK5PF_status() const{
  return cfa_->jets_AK5PF_status();
}

std::vector<float>* const & cfa::jets_AK5PF_theta() const{
  return cfa_->jets_AK5PF_theta();
}

std::vector<float>* const & cfa::jets_AK5PFclean_Uncert() const{
  return cfa_->jets_AK5PFclean_Uncert();
}

std::vector<float>* const & cfa::jets_AK5PFclean_area() const{
  return cfa_->jets_AK5PFclean_area();
}

std::vector<float>* const & cfa::jets_AK5PFclean_btag_TC_highEff() const{
  return cfa_->jets_AK5PFclean_btag_TC_highEff();
}

std::vector<float>* const & cfa::jets_AK5PFclean_btag_TC_highPur() const{
  return cfa_->jets_AK5PFclean_btag_TC_highPur();
}

std::vector<float>* const & cfa::jets_AK5PFclean_btag_jetBProb() const{
  return cfa_->jets_AK5PFclean_btag_jetBProb();
}

std::vector<float>* const & cfa::jets_AK5PFclean_btag_jetProb() const{
  return cfa_->jets_AK5PFclean_btag_jetProb();
}

std::vector<float>* const & cfa::jets_AK5PFclean_btag_secVertexCombined() const{
  return cfa_->jets_AK5PFclean_btag_secVertexCombined();
}

std::vector<float>* const & cfa::jets_AK5PFclean_btag_secVertexHighEff() const{
  return cfa_->jets_AK5PFclean_btag_secVertexHighEff();
}

std::vector<float>* const & cfa::jets_AK5PFclean_btag_secVertexHighPur() const{
  return cfa_->jets_AK5PFclean_btag_secVertexHighPur();
}

std::vector<float>* const & cfa::jets_AK5PFclean_btag_softEle() const{
  return cfa_->jets_AK5PFclean_btag_softEle();
}

std::vector<float>* const & cfa::jets_AK5PFclean_btag_softMuon() const{
  return cfa_->jets_AK5PFclean_btag_softMuon();
}

std::vector<float>* const & cfa::jets_AK5PFclean_chgEmE() const{
  return cfa_->jets_AK5PFclean_chgEmE();
}

std::vector<float>* const & cfa::jets_AK5PFclean_chgHadE() const{
  return cfa_->jets_AK5PFclean_chgHadE();
}

std::vector<float>* const & cfa::jets_AK5PFclean_chgMuE() const{
  return cfa_->jets_AK5PFclean_chgMuE();
}

std::vector<float>* const & cfa::jets_AK5PFclean_chg_Mult() const{
  return cfa_->jets_AK5PFclean_chg_Mult();
}

std::vector<float>* const & cfa::jets_AK5PFclean_corrFactorRaw() const{
  return cfa_->jets_AK5PFclean_corrFactorRaw();
}

std::vector<float>* const & cfa::jets_AK5PFclean_corrL1FastL2L3() const{
  return cfa_->jets_AK5PFclean_corrL1FastL2L3();
}

std::vector<float>* const & cfa::jets_AK5PFclean_corrL1FastL2L3Residual() const{
  return cfa_->jets_AK5PFclean_corrL1FastL2L3Residual();
}

std::vector<float>* const & cfa::jets_AK5PFclean_corrL1L2L3() const{
  return cfa_->jets_AK5PFclean_corrL1L2L3();
}

std::vector<float>* const & cfa::jets_AK5PFclean_corrL1L2L3Residual() const{
  return cfa_->jets_AK5PFclean_corrL1L2L3Residual();
}

std::vector<float>* const & cfa::jets_AK5PFclean_corrL2L3() const{
  return cfa_->jets_AK5PFclean_corrL2L3();
}

std::vector<float>* const & cfa::jets_AK5PFclean_corrL2L3Residual() const{
  return cfa_->jets_AK5PFclean_corrL2L3Residual();
}

std::vector<float>* const & cfa::jets_AK5PFclean_ehf() const{
  return cfa_->jets_AK5PFclean_ehf();
}

std::vector<float>* const & cfa::jets_AK5PFclean_emf() const{
  return cfa_->jets_AK5PFclean_emf();
}

std::vector<float>* const & cfa::jets_AK5PFclean_energy() const{
  return cfa_->jets_AK5PFclean_energy();
}

std::vector<float>* const & cfa::jets_AK5PFclean_et() const{
  return cfa_->jets_AK5PFclean_et();
}

std::vector<float>* const & cfa::jets_AK5PFclean_eta() const{
  return cfa_->jets_AK5PFclean_eta();
}

std::vector<float>* const & cfa::jets_AK5PFclean_etaetaMoment() const{
  return cfa_->jets_AK5PFclean_etaetaMoment();
}

std::vector<float>* const & cfa::jets_AK5PFclean_etaphiMoment() const{
  return cfa_->jets_AK5PFclean_etaphiMoment();
}

std::vector<float>* const & cfa::jets_AK5PFclean_fHPD() const{
  return cfa_->jets_AK5PFclean_fHPD();
}

std::vector<float>* const & cfa::jets_AK5PFclean_fRBX() const{
  return cfa_->jets_AK5PFclean_fRBX();
}

std::vector<float>* const & cfa::jets_AK5PFclean_fSubDetector1() const{
  return cfa_->jets_AK5PFclean_fSubDetector1();
}

std::vector<float>* const & cfa::jets_AK5PFclean_fSubDetector2() const{
  return cfa_->jets_AK5PFclean_fSubDetector2();
}

std::vector<float>* const & cfa::jets_AK5PFclean_fSubDetector3() const{
  return cfa_->jets_AK5PFclean_fSubDetector3();
}

std::vector<float>* const & cfa::jets_AK5PFclean_fSubDetector4() const{
  return cfa_->jets_AK5PFclean_fSubDetector4();
}

std::vector<float>* const & cfa::jets_AK5PFclean_gen_Energy() const{
  return cfa_->jets_AK5PFclean_gen_Energy();
}

std::vector<float>* const & cfa::jets_AK5PFclean_gen_Id() const{
  return cfa_->jets_AK5PFclean_gen_Id();
}

std::vector<float>* const & cfa::jets_AK5PFclean_gen_et() const{
  return cfa_->jets_AK5PFclean_gen_et();
}

std::vector<float>* const & cfa::jets_AK5PFclean_gen_eta() const{
  return cfa_->jets_AK5PFclean_gen_eta();
}

std::vector<float>* const & cfa::jets_AK5PFclean_gen_mass() const{
  return cfa_->jets_AK5PFclean_gen_mass();
}

std::vector<float>* const & cfa::jets_AK5PFclean_gen_phi() const{
  return cfa_->jets_AK5PFclean_gen_phi();
}

std::vector<float>* const & cfa::jets_AK5PFclean_gen_pt() const{
  return cfa_->jets_AK5PFclean_gen_pt();
}

std::vector<float>* const & cfa::jets_AK5PFclean_hitsInN90() const{
  return cfa_->jets_AK5PFclean_hitsInN90();
}

std::vector<float>* const & cfa::jets_AK5PFclean_jetCharge() const{
  return cfa_->jets_AK5PFclean_jetCharge();
}

std::vector<float>* const & cfa::jets_AK5PFclean_mass() const{
  return cfa_->jets_AK5PFclean_mass();
}

std::vector<float>* const & cfa::jets_AK5PFclean_mu_Mult() const{
  return cfa_->jets_AK5PFclean_mu_Mult();
}

std::vector<float>* const & cfa::jets_AK5PFclean_n60() const{
  return cfa_->jets_AK5PFclean_n60();
}

std::vector<float>* const & cfa::jets_AK5PFclean_n90() const{
  return cfa_->jets_AK5PFclean_n90();
}

std::vector<float>* const & cfa::jets_AK5PFclean_n90Hits() const{
  return cfa_->jets_AK5PFclean_n90Hits();
}

std::vector<float>* const & cfa::jets_AK5PFclean_nECALTowers() const{
  return cfa_->jets_AK5PFclean_nECALTowers();
}

std::vector<float>* const & cfa::jets_AK5PFclean_nHCALTowers() const{
  return cfa_->jets_AK5PFclean_nHCALTowers();
}

std::vector<float>* const & cfa::jets_AK5PFclean_neutralEmE() const{
  return cfa_->jets_AK5PFclean_neutralEmE();
}

std::vector<float>* const & cfa::jets_AK5PFclean_neutralHadE() const{
  return cfa_->jets_AK5PFclean_neutralHadE();
}

std::vector<float>* const & cfa::jets_AK5PFclean_neutral_Mult() const{
  return cfa_->jets_AK5PFclean_neutral_Mult();
}

std::vector<float>* const & cfa::jets_AK5PFclean_partonFlavour() const{
  return cfa_->jets_AK5PFclean_partonFlavour();
}

std::vector<float>* const & cfa::jets_AK5PFclean_parton_Energy() const{
  return cfa_->jets_AK5PFclean_parton_Energy();
}

std::vector<float>* const & cfa::jets_AK5PFclean_parton_Id() const{
  return cfa_->jets_AK5PFclean_parton_Id();
}

std::vector<float>* const & cfa::jets_AK5PFclean_parton_eta() const{
  return cfa_->jets_AK5PFclean_parton_eta();
}

std::vector<float>* const & cfa::jets_AK5PFclean_parton_mass() const{
  return cfa_->jets_AK5PFclean_parton_mass();
}

std::vector<float>* const & cfa::jets_AK5PFclean_parton_motherId() const{
  return cfa_->jets_AK5PFclean_parton_motherId();
}

std::vector<float>* const & cfa::jets_AK5PFclean_parton_phi() const{
  return cfa_->jets_AK5PFclean_parton_phi();
}

std::vector<float>* const & cfa::jets_AK5PFclean_parton_pt() const{
  return cfa_->jets_AK5PFclean_parton_pt();
}

std::vector<float>* const & cfa::jets_AK5PFclean_phi() const{
  return cfa_->jets_AK5PFclean_phi();
}

std::vector<float>* const & cfa::jets_AK5PFclean_phiphiMoment() const{
  return cfa_->jets_AK5PFclean_phiphiMoment();
}

std::vector<float>* const & cfa::jets_AK5PFclean_photonEnergy() const{
  return cfa_->jets_AK5PFclean_photonEnergy();
}

std::vector<float>* const & cfa::jets_AK5PFclean_pt() const{
  return cfa_->jets_AK5PFclean_pt();
}

std::vector<float>* const & cfa::jets_AK5PFclean_px() const{
  return cfa_->jets_AK5PFclean_px();
}

std::vector<float>* const & cfa::jets_AK5PFclean_py() const{
  return cfa_->jets_AK5PFclean_py();
}

std::vector<float>* const & cfa::jets_AK5PFclean_pz() const{
  return cfa_->jets_AK5PFclean_pz();
}

std::vector<float>* const & cfa::jets_AK5PFclean_rawPt() const{
  return cfa_->jets_AK5PFclean_rawPt();
}

std::vector<float>* const & cfa::jets_AK5PFclean_status() const{
  return cfa_->jets_AK5PFclean_status();
}

std::vector<float>* const & cfa::jets_AK5PFclean_theta() const{
  return cfa_->jets_AK5PFclean_theta();
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

std::vector<float>* const & cfa::mc_pdf_id1() const{
  return cfa_->mc_pdf_id1();
}

std::vector<float>* const & cfa::mc_pdf_id2() const{
  return cfa_->mc_pdf_id2();
}

std::vector<float>* const & cfa::mc_pdf_q() const{
  return cfa_->mc_pdf_q();
}

std::vector<float>* const & cfa::mc_pdf_x1() const{
  return cfa_->mc_pdf_x1();
}

std::vector<float>* const & cfa::mc_pdf_x2() const{
  return cfa_->mc_pdf_x2();
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

std::vector<float>* const & cfa::metsHO_et() const{
  return cfa_->metsHO_et();
}

std::vector<float>* const & cfa::metsHO_ex() const{
  return cfa_->metsHO_ex();
}

std::vector<float>* const & cfa::metsHO_ey() const{
  return cfa_->metsHO_ey();
}

std::vector<float>* const & cfa::metsHO_phi() const{
  return cfa_->metsHO_phi();
}

std::vector<float>* const & cfa::metsHO_sumEt() const{
  return cfa_->metsHO_sumEt();
}

std::vector<float>* const & cfa::mets_AK5_et() const{
  return cfa_->mets_AK5_et();
}

std::vector<float>* const & cfa::mets_AK5_ex() const{
  return cfa_->mets_AK5_ex();
}

std::vector<float>* const & cfa::mets_AK5_ey() const{
  return cfa_->mets_AK5_ey();
}

std::vector<float>* const & cfa::mets_AK5_gen_et() const{
  return cfa_->mets_AK5_gen_et();
}

std::vector<float>* const & cfa::mets_AK5_gen_phi() const{
  return cfa_->mets_AK5_gen_phi();
}

std::vector<float>* const & cfa::mets_AK5_phi() const{
  return cfa_->mets_AK5_phi();
}

std::vector<float>* const & cfa::mets_AK5_sign() const{
  return cfa_->mets_AK5_sign();
}

std::vector<float>* const & cfa::mets_AK5_sumEt() const{
  return cfa_->mets_AK5_sumEt();
}

std::vector<float>* const & cfa::mets_AK5_unCPhi() const{
  return cfa_->mets_AK5_unCPhi();
}

std::vector<float>* const & cfa::mets_AK5_unCPt() const{
  return cfa_->mets_AK5_unCPt();
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

std::vector<float>* const & cfa::mus_cIso(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_cIso();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_cIso();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_cIso();
}

std::vector<float>* const & cfa::mus_calEnergyEm(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_calEnergyEm();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_calEnergyEm();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_calEnergyEm();
}

std::vector<float>* const & cfa::mus_calEnergyEmS9(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_calEnergyEmS9();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_calEnergyEmS9();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_calEnergyEmS9();
}

std::vector<float>* const & cfa::mus_calEnergyHad(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_calEnergyHad();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_calEnergyHad();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_calEnergyHad();
}

std::vector<float>* const & cfa::mus_calEnergyHadS9(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_calEnergyHadS9();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_calEnergyHadS9();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_calEnergyHadS9();
}

std::vector<float>* const & cfa::mus_calEnergyHo(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_calEnergyHo();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_calEnergyHo();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_calEnergyHo();
}

std::vector<float>* const & cfa::mus_calEnergyHoS9(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_calEnergyHoS9();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_calEnergyHoS9();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_calEnergyHoS9();
}

std::vector<float>* const & cfa::mus_charge(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_charge();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_charge();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_charge();
}

std::vector<float>* const & cfa::mus_cm_ExpectedHitsInner(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_cm_ExpectedHitsInner();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_cm_ExpectedHitsInner();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_cm_ExpectedHitsInner();
}

std::vector<float>* const & cfa::mus_cm_ExpectedHitsOuter(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_cm_ExpectedHitsOuter();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_cm_ExpectedHitsOuter();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_cm_ExpectedHitsOuter();
}

std::vector<float>* const & cfa::mus_cm_LayersWithMeasurement(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_cm_LayersWithMeasurement();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_cm_LayersWithMeasurement();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_cm_LayersWithMeasurement();
}

std::vector<float>* const & cfa::mus_cm_LayersWithoutMeasurement(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_cm_LayersWithoutMeasurement();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_cm_LayersWithoutMeasurement();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_cm_LayersWithoutMeasurement();
}

std::vector<float>* const & cfa::mus_cm_PixelLayersWithMeasurement(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_cm_PixelLayersWithMeasurement();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_cm_PixelLayersWithMeasurement();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_cm_PixelLayersWithMeasurement();
}

std::vector<float>* const & cfa::mus_cm_ValidStripLayersWithMonoAndStereoHit(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_cm_ValidStripLayersWithMonoAndStereoHit();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_cm_ValidStripLayersWithMonoAndStereoHit();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_cm_ValidStripLayersWithMonoAndStereoHit();
}

std::vector<float>* const & cfa::mus_cm_chg(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_cm_chg();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_cm_chg();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_cm_chg();
}

std::vector<float>* const & cfa::mus_cm_chi2(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_cm_chi2();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_cm_chi2();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_cm_chi2();
}

std::vector<float>* const & cfa::mus_cm_d0dum(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_cm_d0dum();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_cm_d0dum();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_cm_d0dum();
}

std::vector<float>* const & cfa::mus_cm_d0dumErr(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_cm_d0dumErr();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_cm_d0dumErr();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_cm_d0dumErr();
}

std::vector<float>* const & cfa::mus_cm_dz(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_cm_dz();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_cm_dz();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_cm_dz();
}

std::vector<float>* const & cfa::mus_cm_dzErr(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_cm_dzErr();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_cm_dzErr();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_cm_dzErr();
}

std::vector<float>* const & cfa::mus_cm_eta(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_cm_eta();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_cm_eta();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_cm_eta();
}

std::vector<float>* const & cfa::mus_cm_etaErr(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_cm_etaErr();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_cm_etaErr();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_cm_etaErr();
}

std::vector<float>* const & cfa::mus_cm_ndof(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_cm_ndof();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_cm_ndof();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_cm_ndof();
}

std::vector<float>* const & cfa::mus_cm_numlosthits(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_cm_numlosthits();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_cm_numlosthits();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_cm_numlosthits();
}

std::vector<float>* const & cfa::mus_cm_numvalMuonhits(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_cm_numvalMuonhits();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_cm_numvalMuonhits();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_cm_numvalMuonhits();
}

std::vector<float>* const & cfa::mus_cm_numvalhits(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_cm_numvalhits();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_cm_numvalhits();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_cm_numvalhits();
}

std::vector<float>* const & cfa::mus_cm_phi(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_cm_phi();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_cm_phi();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_cm_phi();
}

std::vector<float>* const & cfa::mus_cm_phiErr(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_cm_phiErr();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_cm_phiErr();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_cm_phiErr();
}

std::vector<float>* const & cfa::mus_cm_pt(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_cm_pt();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_cm_pt();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_cm_pt();
}

std::vector<float>* const & cfa::mus_cm_ptErr(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_cm_ptErr();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_cm_ptErr();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_cm_ptErr();
}

std::vector<float>* const & cfa::mus_cm_px(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_cm_px();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_cm_px();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_cm_px();
}

std::vector<float>* const & cfa::mus_cm_py(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_cm_py();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_cm_py();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_cm_py();
}

std::vector<float>* const & cfa::mus_cm_pz(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_cm_pz();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_cm_pz();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_cm_pz();
}

std::vector<float>* const & cfa::mus_cm_theta(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_cm_theta();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_cm_theta();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_cm_theta();
}

std::vector<float>* const & cfa::mus_cm_vx(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_cm_vx();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_cm_vx();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_cm_vx();
}

std::vector<float>* const & cfa::mus_cm_vy(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_cm_vy();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_cm_vy();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_cm_vy();
}

std::vector<float>* const & cfa::mus_cm_vz(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_cm_vz();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_cm_vz();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_cm_vz();
}

std::vector<float>* const & cfa::mus_dB(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_dB();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_dB();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_dB();
}

std::vector<float>* const & cfa::mus_ecalIso(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_ecalIso();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_ecalIso();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_ecalIso();
}

std::vector<float>* const & cfa::mus_ecalvetoDep(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_ecalvetoDep();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_ecalvetoDep();
}

std::vector<float>* const & cfa::mus_energy(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_energy();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_energy();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_energy();
}

std::vector<float>* const & cfa::mus_et(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_et();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_et();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_et();
}

std::vector<float>* const & cfa::mus_eta(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_eta();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_eta();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_eta();
}

std::vector<float>* const & cfa::mus_gen_et(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_gen_et();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_gen_et();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_gen_et();
}

std::vector<float>* const & cfa::mus_gen_eta(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_gen_eta();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_gen_eta();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_gen_eta();
}

std::vector<float>* const & cfa::mus_gen_id(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_gen_id();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_gen_id();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_gen_id();
}

std::vector<float>* const & cfa::mus_gen_mother_et(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_gen_mother_et();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_gen_mother_et();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_gen_mother_et();
}

std::vector<float>* const & cfa::mus_gen_mother_eta(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_gen_mother_eta();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_gen_mother_eta();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_gen_mother_eta();
}

std::vector<float>* const & cfa::mus_gen_mother_id(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_gen_mother_id();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_gen_mother_id();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_gen_mother_id();
}

std::vector<float>* const & cfa::mus_gen_mother_phi(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_gen_mother_phi();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_gen_mother_phi();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_gen_mother_phi();
}

std::vector<float>* const & cfa::mus_gen_mother_pt(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_gen_mother_pt();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_gen_mother_pt();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_gen_mother_pt();
}

std::vector<float>* const & cfa::mus_gen_mother_px(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_gen_mother_px();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_gen_mother_px();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_gen_mother_px();
}

std::vector<float>* const & cfa::mus_gen_mother_py(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_gen_mother_py();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_gen_mother_py();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_gen_mother_py();
}

std::vector<float>* const & cfa::mus_gen_mother_pz(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_gen_mother_pz();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_gen_mother_pz();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_gen_mother_pz();
}

std::vector<float>* const & cfa::mus_gen_mother_theta(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_gen_mother_theta();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_gen_mother_theta();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_gen_mother_theta();
}

std::vector<float>* const & cfa::mus_gen_phi(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_gen_phi();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_gen_phi();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_gen_phi();
}

std::vector<float>* const & cfa::mus_gen_pt(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_gen_pt();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_gen_pt();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_gen_pt();
}

std::vector<float>* const & cfa::mus_gen_px(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_gen_px();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_gen_px();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_gen_px();
}

std::vector<float>* const & cfa::mus_gen_py(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_gen_py();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_gen_py();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_gen_py();
}

std::vector<float>* const & cfa::mus_gen_pz(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_gen_pz();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_gen_pz();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_gen_pz();
}

std::vector<float>* const & cfa::mus_gen_theta(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_gen_theta();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_gen_theta();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_gen_theta();
}

std::vector<float>* const & cfa::mus_hcalIso(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_hcalIso();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_hcalIso();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_hcalIso();
}

std::vector<float>* const & cfa::mus_hcalvetoDep(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_hcalvetoDep();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_hcalvetoDep();
}

std::vector<float>* const & cfa::mus_id_All(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_id_All();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_id_All();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_id_All();
}

std::vector<float>* const & cfa::mus_id_AllArbitrated(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_id_AllArbitrated();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_id_AllArbitrated();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_id_AllArbitrated();
}

std::vector<float>* const & cfa::mus_id_AllGlobalMuons(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_id_AllGlobalMuons();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_id_AllGlobalMuons();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_id_AllGlobalMuons();
}

std::vector<float>* const & cfa::mus_id_AllStandAloneMuons(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_id_AllStandAloneMuons();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_id_AllStandAloneMuons();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_id_AllStandAloneMuons();
}

std::vector<float>* const & cfa::mus_id_AllTrackerMuons(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_id_AllTrackerMuons();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_id_AllTrackerMuons();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_id_AllTrackerMuons();
}

std::vector<float>* const & cfa::mus_id_GlobalMuonPromptTight(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_id_GlobalMuonPromptTight();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_id_GlobalMuonPromptTight();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_id_GlobalMuonPromptTight();
}

std::vector<float>* const & cfa::mus_id_TM2DCompatibilityLoose(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_id_TM2DCompatibilityLoose();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_id_TM2DCompatibilityLoose();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_id_TM2DCompatibilityLoose();
}

std::vector<float>* const & cfa::mus_id_TM2DCompatibilityTight(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_id_TM2DCompatibilityTight();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_id_TM2DCompatibilityTight();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_id_TM2DCompatibilityTight();
}

std::vector<float>* const & cfa::mus_id_TMLastStationLoose(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_id_TMLastStationLoose();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_id_TMLastStationLoose();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_id_TMLastStationLoose();
}

std::vector<float>* const & cfa::mus_id_TMLastStationOptimizedLowPtLoose(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_id_TMLastStationOptimizedLowPtLoose();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_id_TMLastStationOptimizedLowPtLoose();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_id_TMLastStationOptimizedLowPtLoose();
}

std::vector<float>* const & cfa::mus_id_TMLastStationOptimizedLowPtTight(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_id_TMLastStationOptimizedLowPtTight();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_id_TMLastStationOptimizedLowPtTight();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_id_TMLastStationOptimizedLowPtTight();
}

std::vector<float>* const & cfa::mus_id_TMLastStationTight(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_id_TMLastStationTight();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_id_TMLastStationTight();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_id_TMLastStationTight();
}

std::vector<float>* const & cfa::mus_id_TMOneStationLoose(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_id_TMOneStationLoose();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_id_TMOneStationLoose();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_id_TMOneStationLoose();
}

std::vector<float>* const & cfa::mus_id_TMOneStationTight(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_id_TMOneStationTight();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_id_TMOneStationTight();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_id_TMOneStationTight();
}

std::vector<float>* const & cfa::mus_id_TrackerMuonArbitrated(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_id_TrackerMuonArbitrated();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_id_TrackerMuonArbitrated();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_id_TrackerMuonArbitrated();
}

std::vector<float>* const & cfa::mus_isCaloMuon(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_isCaloMuon();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_isCaloMuon();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_isCaloMuon();
}

std::vector<float>* const & cfa::mus_isConvertedPhoton(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_isConvertedPhoton();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_isConvertedPhoton();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_isConvertedPhoton();
}

std::vector<float>* const & cfa::mus_isElectron(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_isElectron();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_isElectron();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_isElectron();
}

std::vector<float>* const & cfa::mus_isGlobalMuon(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_isGlobalMuon();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_isGlobalMuon();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_isGlobalMuon();
}

std::vector<bool>* const & cfa::mus_isPF(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_isPF();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_isPF();
}

std::vector<float>* const & cfa::mus_isPFMuon(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_isPFMuon();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_isPFMuon();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_isPFMuon();
}

std::vector<float>* const & cfa::mus_isPhoton(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_isPhoton();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_isPhoton();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_isPhoton();
}

std::vector<float>* const & cfa::mus_isStandAloneMuon(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_isStandAloneMuon();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_isStandAloneMuon();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_isStandAloneMuon();
}

std::vector<float>* const & cfa::mus_isTrackerMuon(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_isTrackerMuon();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_isTrackerMuon();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_isTrackerMuon();
}

std::vector<float>* const & cfa::mus_iso03_emEt(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_iso03_emEt();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_iso03_emEt();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_iso03_emEt();
}

std::vector<float>* const & cfa::mus_iso03_emVetoEt(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_iso03_emVetoEt();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_iso03_emVetoEt();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_iso03_emVetoEt();
}

std::vector<float>* const & cfa::mus_iso03_hadEt(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_iso03_hadEt();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_iso03_hadEt();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_iso03_hadEt();
}

std::vector<float>* const & cfa::mus_iso03_hadVetoEt(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_iso03_hadVetoEt();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_iso03_hadVetoEt();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_iso03_hadVetoEt();
}

std::vector<float>* const & cfa::mus_iso03_hoEt(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_iso03_hoEt();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_iso03_hoEt();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_iso03_hoEt();
}

std::vector<float>* const & cfa::mus_iso03_nTracks(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_iso03_nTracks();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_iso03_nTracks();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_iso03_nTracks();
}

std::vector<float>* const & cfa::mus_iso03_sumPt(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_iso03_sumPt();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_iso03_sumPt();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_iso03_sumPt();
}

std::vector<float>* const & cfa::mus_iso05_emEt(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_iso05_emEt();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_iso05_emEt();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_iso05_emEt();
}

std::vector<float>* const & cfa::mus_iso05_hadEt(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_iso05_hadEt();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_iso05_hadEt();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_iso05_hadEt();
}

std::vector<float>* const & cfa::mus_iso05_hoEt(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_iso05_hoEt();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_iso05_hoEt();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_iso05_hoEt();
}

std::vector<float>* const & cfa::mus_iso05_nTracks(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_iso05_nTracks();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_iso05_nTracks();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_iso05_nTracks();
}

std::vector<float>* const & cfa::mus_iso05_sumPt(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_iso05_sumPt();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_iso05_sumPt();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_iso05_sumPt();
}

std::vector<int>* const & cfa::mus_jet_ind(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_jet_ind();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_jet_ind();
}

std::vector<float>* const & cfa::mus_num_matches(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_num_matches();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_num_matches();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_num_matches();
}

std::vector<float>* const & cfa::mus_numberOfMatchedStations(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_numberOfMatchedStations();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_numberOfMatchedStations();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_numberOfMatchedStations();
}

std::vector<float>* const & cfa::mus_pfIsolationR03_sumChargedHadronPt(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_pfIsolationR03_sumChargedHadronPt();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_pfIsolationR03_sumChargedHadronPt();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_pfIsolationR03_sumChargedHadronPt();
}

std::vector<float>* const & cfa::mus_pfIsolationR03_sumChargedParticlePt(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_pfIsolationR03_sumChargedParticlePt();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_pfIsolationR03_sumChargedParticlePt();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_pfIsolationR03_sumChargedParticlePt();
}

std::vector<float>* const & cfa::mus_pfIsolationR03_sumNeutralHadronEt(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_pfIsolationR03_sumNeutralHadronEt();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_pfIsolationR03_sumNeutralHadronEt();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_pfIsolationR03_sumNeutralHadronEt();
}

std::vector<float>* const & cfa::mus_pfIsolationR03_sumNeutralHadronEtHighThreshold(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_pfIsolationR03_sumNeutralHadronEtHighThreshold();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_pfIsolationR03_sumNeutralHadronEtHighThreshold();
}

std::vector<float>* const & cfa::mus_pfIsolationR03_sumPUPt(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_pfIsolationR03_sumPUPt();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_pfIsolationR03_sumPUPt();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_pfIsolationR03_sumPUPt();
}

std::vector<float>* const & cfa::mus_pfIsolationR03_sumPhotonEt(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_pfIsolationR03_sumPhotonEt();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_pfIsolationR03_sumPhotonEt();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_pfIsolationR03_sumPhotonEt();
}

std::vector<float>* const & cfa::mus_pfIsolationR03_sumPhotonEtHighThreshold(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_pfIsolationR03_sumPhotonEtHighThreshold();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_pfIsolationR03_sumPhotonEtHighThreshold();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_pfIsolationR03_sumPhotonEtHighThreshold();
}

std::vector<float>* const & cfa::mus_pfIsolationR04_sumChargedHadronPt(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_pfIsolationR04_sumChargedHadronPt();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_pfIsolationR04_sumChargedHadronPt();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_pfIsolationR04_sumChargedHadronPt();
}

std::vector<float>* const & cfa::mus_pfIsolationR04_sumChargedParticlePt(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_pfIsolationR04_sumChargedParticlePt();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_pfIsolationR04_sumChargedParticlePt();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_pfIsolationR04_sumChargedParticlePt();
}

std::vector<float>* const & cfa::mus_pfIsolationR04_sumNeutralHadronEt(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_pfIsolationR04_sumNeutralHadronEt();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_pfIsolationR04_sumNeutralHadronEt();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_pfIsolationR04_sumNeutralHadronEt();
}

std::vector<float>* const & cfa::mus_pfIsolationR04_sumNeutralHadronEtHighThreshold(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_pfIsolationR04_sumNeutralHadronEtHighThreshold();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_pfIsolationR04_sumNeutralHadronEtHighThreshold();
}

std::vector<float>* const & cfa::mus_pfIsolationR04_sumPUPt(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_pfIsolationR04_sumPUPt();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_pfIsolationR04_sumPUPt();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_pfIsolationR04_sumPUPt();
}

std::vector<float>* const & cfa::mus_pfIsolationR04_sumPhotonEt(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_pfIsolationR04_sumPhotonEt();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_pfIsolationR04_sumPhotonEt();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_pfIsolationR04_sumPhotonEt();
}

std::vector<float>* const & cfa::mus_pfIsolationR04_sumPhotonEtHighThreshold(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_pfIsolationR04_sumPhotonEtHighThreshold();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_pfIsolationR04_sumPhotonEtHighThreshold();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_pfIsolationR04_sumPhotonEtHighThreshold();
}

std::vector<float>* const & cfa::mus_phi(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_phi();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_phi();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_phi();
}

std::vector<float>* const & cfa::mus_picky_ExpectedHitsInner(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_picky_ExpectedHitsInner();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_picky_ExpectedHitsInner();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_picky_ExpectedHitsInner();
}

std::vector<float>* const & cfa::mus_picky_ExpectedHitsOuter(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_picky_ExpectedHitsOuter();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_picky_ExpectedHitsOuter();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_picky_ExpectedHitsOuter();
}

std::vector<float>* const & cfa::mus_picky_LayersWithMeasurement(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_picky_LayersWithMeasurement();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_picky_LayersWithMeasurement();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_picky_LayersWithMeasurement();
}

std::vector<float>* const & cfa::mus_picky_LayersWithoutMeasurement(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_picky_LayersWithoutMeasurement();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_picky_LayersWithoutMeasurement();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_picky_LayersWithoutMeasurement();
}

std::vector<float>* const & cfa::mus_picky_PixelLayersWithMeasurement(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_picky_PixelLayersWithMeasurement();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_picky_PixelLayersWithMeasurement();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_picky_PixelLayersWithMeasurement();
}

std::vector<float>* const & cfa::mus_picky_ValidStripLayersWithMonoAndStereoHit(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_picky_ValidStripLayersWithMonoAndStereoHit();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_picky_ValidStripLayersWithMonoAndStereoHit();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_picky_ValidStripLayersWithMonoAndStereoHit();
}

std::vector<float>* const & cfa::mus_picky_chg(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_picky_chg();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_picky_chg();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_picky_chg();
}

std::vector<float>* const & cfa::mus_picky_chi2(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_picky_chi2();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_picky_chi2();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_picky_chi2();
}

std::vector<float>* const & cfa::mus_picky_d0dum(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_picky_d0dum();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_picky_d0dum();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_picky_d0dum();
}

std::vector<float>* const & cfa::mus_picky_d0dumErr(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_picky_d0dumErr();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_picky_d0dumErr();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_picky_d0dumErr();
}

std::vector<float>* const & cfa::mus_picky_dz(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_picky_dz();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_picky_dz();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_picky_dz();
}

std::vector<float>* const & cfa::mus_picky_dzErr(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_picky_dzErr();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_picky_dzErr();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_picky_dzErr();
}

std::vector<float>* const & cfa::mus_picky_eta(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_picky_eta();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_picky_eta();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_picky_eta();
}

std::vector<float>* const & cfa::mus_picky_etaErr(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_picky_etaErr();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_picky_etaErr();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_picky_etaErr();
}

std::vector<float>* const & cfa::mus_picky_id(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_picky_id();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_picky_id();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_picky_id();
}

std::vector<float>* const & cfa::mus_picky_ndof(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_picky_ndof();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_picky_ndof();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_picky_ndof();
}

std::vector<float>* const & cfa::mus_picky_numlosthits(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_picky_numlosthits();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_picky_numlosthits();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_picky_numlosthits();
}

std::vector<float>* const & cfa::mus_picky_numvalPixelhits(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_picky_numvalPixelhits();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_picky_numvalPixelhits();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_picky_numvalPixelhits();
}

std::vector<float>* const & cfa::mus_picky_numvalhits(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_picky_numvalhits();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_picky_numvalhits();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_picky_numvalhits();
}

std::vector<float>* const & cfa::mus_picky_phi(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_picky_phi();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_picky_phi();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_picky_phi();
}

std::vector<float>* const & cfa::mus_picky_phiErr(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_picky_phiErr();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_picky_phiErr();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_picky_phiErr();
}

std::vector<float>* const & cfa::mus_picky_pt(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_picky_pt();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_picky_pt();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_picky_pt();
}

std::vector<float>* const & cfa::mus_picky_ptErr(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_picky_ptErr();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_picky_ptErr();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_picky_ptErr();
}

std::vector<float>* const & cfa::mus_picky_px(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_picky_px();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_picky_px();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_picky_px();
}

std::vector<float>* const & cfa::mus_picky_py(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_picky_py();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_picky_py();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_picky_py();
}

std::vector<float>* const & cfa::mus_picky_pz(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_picky_pz();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_picky_pz();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_picky_pz();
}

std::vector<float>* const & cfa::mus_picky_theta(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_picky_theta();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_picky_theta();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_picky_theta();
}

std::vector<float>* const & cfa::mus_picky_vx(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_picky_vx();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_picky_vx();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_picky_vx();
}

std::vector<float>* const & cfa::mus_picky_vy(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_picky_vy();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_picky_vy();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_picky_vy();
}

std::vector<float>* const & cfa::mus_picky_vz(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_picky_vz();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_picky_vz();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_picky_vz();
}

std::vector<float>* const & cfa::mus_pt(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_pt();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_pt();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_pt();
}

std::vector<float>* const & cfa::mus_px(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_px();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_px();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_px();
}

std::vector<float>* const & cfa::mus_py(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_py();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_py();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_py();
}

std::vector<float>* const & cfa::mus_pz(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_pz();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_pz();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_pz();
}

std::vector<float>* const & cfa::mus_stamu_chg(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_stamu_chg();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_stamu_chg();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_stamu_chg();
}

std::vector<float>* const & cfa::mus_stamu_chi2(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_stamu_chi2();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_stamu_chi2();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_stamu_chi2();
}

std::vector<float>* const & cfa::mus_stamu_d0dum(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_stamu_d0dum();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_stamu_d0dum();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_stamu_d0dum();
}

std::vector<float>* const & cfa::mus_stamu_d0dumErr(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_stamu_d0dumErr();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_stamu_d0dumErr();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_stamu_d0dumErr();
}

std::vector<float>* const & cfa::mus_stamu_dz(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_stamu_dz();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_stamu_dz();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_stamu_dz();
}

std::vector<float>* const & cfa::mus_stamu_dzErr(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_stamu_dzErr();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_stamu_dzErr();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_stamu_dzErr();
}

std::vector<float>* const & cfa::mus_stamu_eta(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_stamu_eta();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_stamu_eta();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_stamu_eta();
}

std::vector<float>* const & cfa::mus_stamu_etaErr(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_stamu_etaErr();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_stamu_etaErr();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_stamu_etaErr();
}

std::vector<float>* const & cfa::mus_stamu_ndof(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_stamu_ndof();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_stamu_ndof();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_stamu_ndof();
}

std::vector<float>* const & cfa::mus_stamu_numlosthits(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_stamu_numlosthits();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_stamu_numlosthits();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_stamu_numlosthits();
}

std::vector<float>* const & cfa::mus_stamu_numvalhits(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_stamu_numvalhits();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_stamu_numvalhits();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_stamu_numvalhits();
}

std::vector<float>* const & cfa::mus_stamu_phi(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_stamu_phi();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_stamu_phi();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_stamu_phi();
}

std::vector<float>* const & cfa::mus_stamu_phiErr(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_stamu_phiErr();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_stamu_phiErr();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_stamu_phiErr();
}

std::vector<float>* const & cfa::mus_stamu_pt(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_stamu_pt();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_stamu_pt();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_stamu_pt();
}

std::vector<float>* const & cfa::mus_stamu_ptErr(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_stamu_ptErr();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_stamu_ptErr();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_stamu_ptErr();
}

std::vector<float>* const & cfa::mus_stamu_px(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_stamu_px();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_stamu_px();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_stamu_px();
}

std::vector<float>* const & cfa::mus_stamu_py(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_stamu_py();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_stamu_py();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_stamu_py();
}

std::vector<float>* const & cfa::mus_stamu_pz(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_stamu_pz();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_stamu_pz();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_stamu_pz();
}

std::vector<float>* const & cfa::mus_stamu_theta(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_stamu_theta();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_stamu_theta();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_stamu_theta();
}

std::vector<float>* const & cfa::mus_stamu_vx(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_stamu_vx();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_stamu_vx();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_stamu_vx();
}

std::vector<float>* const & cfa::mus_stamu_vy(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_stamu_vy();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_stamu_vy();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_stamu_vy();
}

std::vector<float>* const & cfa::mus_stamu_vz(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_stamu_vz();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_stamu_vz();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_stamu_vz();
}

std::vector<float>* const & cfa::mus_status(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_status();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_status();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_status();
}

std::vector<float>* const & cfa::mus_tIso(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tIso();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tIso();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tIso();
}

std::vector<float>* const & cfa::mus_theta(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_theta();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_theta();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_theta();
}

std::vector<float>* const & cfa::mus_tkHits(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tkHits();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tkHits();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tkHits();
}

std::vector<float>* const & cfa::mus_tk_ExpectedHitsInner(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tk_ExpectedHitsInner();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tk_ExpectedHitsInner();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tk_ExpectedHitsInner();
}

std::vector<float>* const & cfa::mus_tk_ExpectedHitsOuter(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tk_ExpectedHitsOuter();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tk_ExpectedHitsOuter();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tk_ExpectedHitsOuter();
}

std::vector<float>* const & cfa::mus_tk_LayersWithMeasurement(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tk_LayersWithMeasurement();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tk_LayersWithMeasurement();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tk_LayersWithMeasurement();
}

std::vector<float>* const & cfa::mus_tk_LayersWithoutMeasurement(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tk_LayersWithoutMeasurement();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tk_LayersWithoutMeasurement();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tk_LayersWithoutMeasurement();
}

std::vector<float>* const & cfa::mus_tk_PixelLayersWithMeasurement(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tk_PixelLayersWithMeasurement();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tk_PixelLayersWithMeasurement();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tk_PixelLayersWithMeasurement();
}

std::vector<float>* const & cfa::mus_tk_ValidStripLayersWithMonoAndStereoHit(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tk_ValidStripLayersWithMonoAndStereoHit();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tk_ValidStripLayersWithMonoAndStereoHit();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tk_ValidStripLayersWithMonoAndStereoHit();
}

std::vector<float>* const & cfa::mus_tk_chg(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tk_chg();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tk_chg();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tk_chg();
}

std::vector<float>* const & cfa::mus_tk_chi2(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tk_chi2();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tk_chi2();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tk_chi2();
}

std::vector<float>* const & cfa::mus_tk_d0dum(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tk_d0dum();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tk_d0dum();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tk_d0dum();
}

std::vector<float>* const & cfa::mus_tk_d0dumErr(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tk_d0dumErr();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tk_d0dumErr();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tk_d0dumErr();
}

std::vector<float>* const & cfa::mus_tk_dz(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tk_dz();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tk_dz();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tk_dz();
}

std::vector<float>* const & cfa::mus_tk_dzErr(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tk_dzErr();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tk_dzErr();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tk_dzErr();
}

std::vector<float>* const & cfa::mus_tk_eta(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tk_eta();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tk_eta();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tk_eta();
}

std::vector<float>* const & cfa::mus_tk_etaErr(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tk_etaErr();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tk_etaErr();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tk_etaErr();
}

std::vector<float>* const & cfa::mus_tk_id(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tk_id();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tk_id();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tk_id();
}

std::vector<float>* const & cfa::mus_tk_ndof(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tk_ndof();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tk_ndof();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tk_ndof();
}

std::vector<float>* const & cfa::mus_tk_numlosthits(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tk_numlosthits();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tk_numlosthits();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tk_numlosthits();
}

std::vector<float>* const & cfa::mus_tk_numpixelWthMeasr(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tk_numpixelWthMeasr();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tk_numpixelWthMeasr();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tk_numpixelWthMeasr();
}

std::vector<float>* const & cfa::mus_tk_numvalPixelhits(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tk_numvalPixelhits();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tk_numvalPixelhits();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tk_numvalPixelhits();
}

std::vector<float>* const & cfa::mus_tk_numvalhits(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tk_numvalhits();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tk_numvalhits();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tk_numvalhits();
}

std::vector<float>* const & cfa::mus_tk_phi(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tk_phi();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tk_phi();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tk_phi();
}

std::vector<float>* const & cfa::mus_tk_phiErr(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tk_phiErr();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tk_phiErr();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tk_phiErr();
}

std::vector<float>* const & cfa::mus_tk_pt(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tk_pt();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tk_pt();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tk_pt();
}

std::vector<float>* const & cfa::mus_tk_ptErr(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tk_ptErr();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tk_ptErr();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tk_ptErr();
}

std::vector<float>* const & cfa::mus_tk_px(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tk_px();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tk_px();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tk_px();
}

std::vector<float>* const & cfa::mus_tk_py(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tk_py();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tk_py();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tk_py();
}

std::vector<float>* const & cfa::mus_tk_pz(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tk_pz();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tk_pz();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tk_pz();
}

std::vector<float>* const & cfa::mus_tk_theta(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tk_theta();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tk_theta();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tk_theta();
}

std::vector<float>* const & cfa::mus_tk_vx(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tk_vx();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tk_vx();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tk_vx();
}

std::vector<float>* const & cfa::mus_tk_vy(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tk_vy();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tk_vy();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tk_vy();
}

std::vector<float>* const & cfa::mus_tk_vz(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tk_vz();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tk_vz();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tk_vz();
}

std::vector<float>* const & cfa::mus_tpfms_ExpectedHitsInner(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tpfms_ExpectedHitsInner();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tpfms_ExpectedHitsInner();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tpfms_ExpectedHitsInner();
}

std::vector<float>* const & cfa::mus_tpfms_ExpectedHitsOuter(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tpfms_ExpectedHitsOuter();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tpfms_ExpectedHitsOuter();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tpfms_ExpectedHitsOuter();
}

std::vector<float>* const & cfa::mus_tpfms_LayersWithMeasurement(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tpfms_LayersWithMeasurement();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tpfms_LayersWithMeasurement();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tpfms_LayersWithMeasurement();
}

std::vector<float>* const & cfa::mus_tpfms_LayersWithoutMeasurement(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tpfms_LayersWithoutMeasurement();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tpfms_LayersWithoutMeasurement();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tpfms_LayersWithoutMeasurement();
}

std::vector<float>* const & cfa::mus_tpfms_PixelLayersWithMeasurement(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tpfms_PixelLayersWithMeasurement();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tpfms_PixelLayersWithMeasurement();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tpfms_PixelLayersWithMeasurement();
}

std::vector<float>* const & cfa::mus_tpfms_ValidStripLayersWithMonoAndStereoHit(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tpfms_ValidStripLayersWithMonoAndStereoHit();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tpfms_ValidStripLayersWithMonoAndStereoHit();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tpfms_ValidStripLayersWithMonoAndStereoHit();
}

std::vector<float>* const & cfa::mus_tpfms_chg(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tpfms_chg();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tpfms_chg();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tpfms_chg();
}

std::vector<float>* const & cfa::mus_tpfms_chi2(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tpfms_chi2();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tpfms_chi2();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tpfms_chi2();
}

std::vector<float>* const & cfa::mus_tpfms_d0dum(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tpfms_d0dum();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tpfms_d0dum();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tpfms_d0dum();
}

std::vector<float>* const & cfa::mus_tpfms_d0dumErr(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tpfms_d0dumErr();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tpfms_d0dumErr();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tpfms_d0dumErr();
}

std::vector<float>* const & cfa::mus_tpfms_dz(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tpfms_dz();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tpfms_dz();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tpfms_dz();
}

std::vector<float>* const & cfa::mus_tpfms_dzErr(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tpfms_dzErr();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tpfms_dzErr();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tpfms_dzErr();
}

std::vector<float>* const & cfa::mus_tpfms_eta(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tpfms_eta();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tpfms_eta();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tpfms_eta();
}

std::vector<float>* const & cfa::mus_tpfms_etaErr(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tpfms_etaErr();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tpfms_etaErr();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tpfms_etaErr();
}

std::vector<float>* const & cfa::mus_tpfms_id(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tpfms_id();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tpfms_id();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tpfms_id();
}

std::vector<float>* const & cfa::mus_tpfms_ndof(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tpfms_ndof();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tpfms_ndof();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tpfms_ndof();
}

std::vector<float>* const & cfa::mus_tpfms_numlosthits(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tpfms_numlosthits();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tpfms_numlosthits();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tpfms_numlosthits();
}

std::vector<float>* const & cfa::mus_tpfms_numvalPixelhits(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tpfms_numvalPixelhits();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tpfms_numvalPixelhits();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tpfms_numvalPixelhits();
}

std::vector<float>* const & cfa::mus_tpfms_numvalhits(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tpfms_numvalhits();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tpfms_numvalhits();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tpfms_numvalhits();
}

std::vector<float>* const & cfa::mus_tpfms_phi(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tpfms_phi();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tpfms_phi();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tpfms_phi();
}

std::vector<float>* const & cfa::mus_tpfms_phiErr(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tpfms_phiErr();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tpfms_phiErr();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tpfms_phiErr();
}

std::vector<float>* const & cfa::mus_tpfms_pt(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tpfms_pt();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tpfms_pt();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tpfms_pt();
}

std::vector<float>* const & cfa::mus_tpfms_ptErr(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tpfms_ptErr();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tpfms_ptErr();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tpfms_ptErr();
}

std::vector<float>* const & cfa::mus_tpfms_px(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tpfms_px();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tpfms_px();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tpfms_px();
}

std::vector<float>* const & cfa::mus_tpfms_py(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tpfms_py();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tpfms_py();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tpfms_py();
}

std::vector<float>* const & cfa::mus_tpfms_pz(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tpfms_pz();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tpfms_pz();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tpfms_pz();
}

std::vector<float>* const & cfa::mus_tpfms_theta(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tpfms_theta();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tpfms_theta();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tpfms_theta();
}

std::vector<float>* const & cfa::mus_tpfms_vx(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tpfms_vx();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tpfms_vx();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tpfms_vx();
}

std::vector<float>* const & cfa::mus_tpfms_vy(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tpfms_vy();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tpfms_vy();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tpfms_vy();
}

std::vector<float>* const & cfa::mus_tpfms_vz(const bool mux) const{
  if(mux){
    if(typeid(*cfa_)==typeid(cfa_8)){
      return cfa_->pf_mus_tpfms_vz();
    }else if(typeid(*cfa_)==typeid(cfa_13)){
      return cfa_->mus_tpfms_vz();
    }else{
      throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
    }
  }
  return cfa_->mus_tpfms_vz();
}

UInt_t const & cfa::orbitNumber() const{
  return cfa_->orbitNumber();
}

Int_t const & cfa::passprescaleHT250filter_decision() const{
  return cfa_->passprescaleHT250filter_decision();
}

Int_t const & cfa::passprescaleHT300filter_decision() const{
  return cfa_->passprescaleHT300filter_decision();
}

Int_t const & cfa::passprescaleHT350filter_decision() const{
  return cfa_->passprescaleHT350filter_decision();
}

Int_t const & cfa::passprescaleHT400filter_decision() const{
  return cfa_->passprescaleHT400filter_decision();
}

Int_t const & cfa::passprescaleHT450filter_decision() const{
  return cfa_->passprescaleHT450filter_decision();
}

Int_t const & cfa::passprescaleJet30MET80filter_decision() const{
  return cfa_->passprescaleJet30MET80filter_decision();
}

Int_t const & cfa::passprescalePFHT350filter_decision() const{
  return cfa_->passprescalePFHT350filter_decision();
}

std::vector<float>* const & cfa::pdfweights_cteq() const{
  return cfa_->pdfweights_cteq();
}

std::vector<float>* const & cfa::pdfweights_mstw() const{
  return cfa_->pdfweights_mstw();
}

std::vector<float>* const & cfa::pdfweights_nnpdf() const{
  return cfa_->pdfweights_nnpdf();
}

std::vector<float>* const & cfa::pfTypeINoXYCorrmets_et() const{
  return cfa_->pfTypeINoXYCorrmets_et();
}

std::vector<float>* const & cfa::pfTypeINoXYCorrmets_ex() const{
  return cfa_->pfTypeINoXYCorrmets_ex();
}

std::vector<float>* const & cfa::pfTypeINoXYCorrmets_ey() const{
  return cfa_->pfTypeINoXYCorrmets_ey();
}

std::vector<float>* const & cfa::pfTypeINoXYCorrmets_gen_et() const{
  return cfa_->pfTypeINoXYCorrmets_gen_et();
}

std::vector<float>* const & cfa::pfTypeINoXYCorrmets_gen_phi() const{
  return cfa_->pfTypeINoXYCorrmets_gen_phi();
}

std::vector<float>* const & cfa::pfTypeINoXYCorrmets_phi() const{
  return cfa_->pfTypeINoXYCorrmets_phi();
}

std::vector<float>* const & cfa::pfTypeINoXYCorrmets_sign() const{
  return cfa_->pfTypeINoXYCorrmets_sign();
}

std::vector<float>* const & cfa::pfTypeINoXYCorrmets_sumEt() const{
  return cfa_->pfTypeINoXYCorrmets_sumEt();
}

std::vector<float>* const & cfa::pfTypeINoXYCorrmets_unCPhi() const{
  return cfa_->pfTypeINoXYCorrmets_unCPhi();
}

std::vector<float>* const & cfa::pfTypeINoXYCorrmets_unCPt() const{
  return cfa_->pfTypeINoXYCorrmets_unCPt();
}

std::vector<float>* const & cfa::pfTypeIType0mets_et() const{
  return cfa_->pfTypeIType0mets_et();
}

std::vector<float>* const & cfa::pfTypeIType0mets_ex() const{
  return cfa_->pfTypeIType0mets_ex();
}

std::vector<float>* const & cfa::pfTypeIType0mets_ey() const{
  return cfa_->pfTypeIType0mets_ey();
}

std::vector<float>* const & cfa::pfTypeIType0mets_gen_et() const{
  return cfa_->pfTypeIType0mets_gen_et();
}

std::vector<float>* const & cfa::pfTypeIType0mets_gen_phi() const{
  return cfa_->pfTypeIType0mets_gen_phi();
}

std::vector<float>* const & cfa::pfTypeIType0mets_phi() const{
  return cfa_->pfTypeIType0mets_phi();
}

std::vector<float>* const & cfa::pfTypeIType0mets_sign() const{
  return cfa_->pfTypeIType0mets_sign();
}

std::vector<float>* const & cfa::pfTypeIType0mets_sumEt() const{
  return cfa_->pfTypeIType0mets_sumEt();
}

std::vector<float>* const & cfa::pfTypeIType0mets_unCPhi() const{
  return cfa_->pfTypeIType0mets_unCPhi();
}

std::vector<float>* const & cfa::pfTypeIType0mets_unCPt() const{
  return cfa_->pfTypeIType0mets_unCPt();
}

std::vector<float>* const & cfa::pfTypeImets_et() const{
  return cfa_->pfTypeImets_et();
}

std::vector<float>* const & cfa::pfTypeImets_ex() const{
  return cfa_->pfTypeImets_ex();
}

std::vector<float>* const & cfa::pfTypeImets_ey() const{
  return cfa_->pfTypeImets_ey();
}

std::vector<float>* const & cfa::pfTypeImets_gen_et() const{
  return cfa_->pfTypeImets_gen_et();
}

std::vector<float>* const & cfa::pfTypeImets_gen_phi() const{
  return cfa_->pfTypeImets_gen_phi();
}

std::vector<float>* const & cfa::pfTypeImets_phi() const{
  return cfa_->pfTypeImets_phi();
}

std::vector<float>* const & cfa::pfTypeImets_sign() const{
  return cfa_->pfTypeImets_sign();
}

std::vector<float>* const & cfa::pfTypeImets_sumEt() const{
  return cfa_->pfTypeImets_sumEt();
}

std::vector<float>* const & cfa::pfTypeImets_unCPhi() const{
  return cfa_->pfTypeImets_unCPhi();
}

std::vector<float>* const & cfa::pfTypeImets_unCPt() const{
  return cfa_->pfTypeImets_unCPt();
}

std::vector<float>* const & cfa::pf_els_PATpassConversionVeto() const{
  return cfa_->pf_els_PATpassConversionVeto();
}

std::vector<float>* const & cfa::pf_els_PFchargedHadronIsoR03() const{
  return cfa_->pf_els_PFchargedHadronIsoR03();
}

std::vector<float>* const & cfa::pf_els_PFneutralHadronIsoR03() const{
  return cfa_->pf_els_PFneutralHadronIsoR03();
}

std::vector<float>* const & cfa::pf_els_PFphotonIsoR03() const{
  return cfa_->pf_els_PFphotonIsoR03();
}

std::vector<float>* const & cfa::pf_els_basicClustersSize() const{
  return cfa_->pf_els_basicClustersSize();
}

std::vector<float>* const & cfa::pf_els_cIso() const{
  return cfa_->pf_els_cIso();
}

std::vector<float>* const & cfa::pf_els_caloEnergy() const{
  return cfa_->pf_els_caloEnergy();
}

std::vector<float>* const & cfa::pf_els_charge() const{
  return cfa_->pf_els_charge();
}

std::vector<float>* const & cfa::pf_els_chargedHadronIso() const{
  return cfa_->pf_els_chargedHadronIso();
}

std::vector<float>* const & cfa::pf_els_chi2() const{
  return cfa_->pf_els_chi2();
}

std::vector<float>* const & cfa::pf_els_core_ecalDrivenSeed() const{
  return cfa_->pf_els_core_ecalDrivenSeed();
}

std::vector<float>* const & cfa::pf_els_cpx() const{
  return cfa_->pf_els_cpx();
}

std::vector<float>* const & cfa::pf_els_cpy() const{
  return cfa_->pf_els_cpy();
}

std::vector<float>* const & cfa::pf_els_cpz() const{
  return cfa_->pf_els_cpz();
}

std::vector<float>* const & cfa::pf_els_ctf_tk_charge() const{
  return cfa_->pf_els_ctf_tk_charge();
}

std::vector<float>* const & cfa::pf_els_ctf_tk_eta() const{
  return cfa_->pf_els_ctf_tk_eta();
}

std::vector<float>* const & cfa::pf_els_ctf_tk_id() const{
  return cfa_->pf_els_ctf_tk_id();
}

std::vector<float>* const & cfa::pf_els_ctf_tk_phi() const{
  return cfa_->pf_els_ctf_tk_phi();
}

std::vector<float>* const & cfa::pf_els_cx() const{
  return cfa_->pf_els_cx();
}

std::vector<float>* const & cfa::pf_els_cy() const{
  return cfa_->pf_els_cy();
}

std::vector<float>* const & cfa::pf_els_cz() const{
  return cfa_->pf_els_cz();
}

std::vector<float>* const & cfa::pf_els_d0dum() const{
  return cfa_->pf_els_d0dum();
}

std::vector<float>* const & cfa::pf_els_d0dumError() const{
  return cfa_->pf_els_d0dumError();
}

std::vector<float>* const & cfa::pf_els_dEtaIn() const{
  return cfa_->pf_els_dEtaIn();
}

std::vector<float>* const & cfa::pf_els_dEtaOut() const{
  return cfa_->pf_els_dEtaOut();
}

std::vector<float>* const & cfa::pf_els_dPhiIn() const{
  return cfa_->pf_els_dPhiIn();
}

std::vector<float>* const & cfa::pf_els_dPhiOut() const{
  return cfa_->pf_els_dPhiOut();
}

std::vector<float>* const & cfa::pf_els_dr03EcalRecHitSumEt() const{
  return cfa_->pf_els_dr03EcalRecHitSumEt();
}

std::vector<float>* const & cfa::pf_els_dr03HcalDepth1TowerSumEt() const{
  return cfa_->pf_els_dr03HcalDepth1TowerSumEt();
}

std::vector<float>* const & cfa::pf_els_dr03HcalDepth2TowerSumEt() const{
  return cfa_->pf_els_dr03HcalDepth2TowerSumEt();
}

std::vector<float>* const & cfa::pf_els_dr03HcalTowerSumEt() const{
  return cfa_->pf_els_dr03HcalTowerSumEt();
}

std::vector<float>* const & cfa::pf_els_dr03TkSumPt() const{
  return cfa_->pf_els_dr03TkSumPt();
}

std::vector<float>* const & cfa::pf_els_dr04EcalRecHitSumEt() const{
  return cfa_->pf_els_dr04EcalRecHitSumEt();
}

std::vector<float>* const & cfa::pf_els_dr04HcalDepth1TowerSumEt() const{
  return cfa_->pf_els_dr04HcalDepth1TowerSumEt();
}

std::vector<float>* const & cfa::pf_els_dr04HcalDepth2TowerSumEt() const{
  return cfa_->pf_els_dr04HcalDepth2TowerSumEt();
}

std::vector<float>* const & cfa::pf_els_dr04HcalTowerSumEt() const{
  return cfa_->pf_els_dr04HcalTowerSumEt();
}

std::vector<float>* const & cfa::pf_els_dr04TkSumPt() const{
  return cfa_->pf_els_dr04TkSumPt();
}

std::vector<float>* const & cfa::pf_els_dz() const{
  return cfa_->pf_els_dz();
}

std::vector<float>* const & cfa::pf_els_dzError() const{
  return cfa_->pf_els_dzError();
}

std::vector<float>* const & cfa::pf_els_eOverPIn() const{
  return cfa_->pf_els_eOverPIn();
}

std::vector<float>* const & cfa::pf_els_eSeedOverPOut() const{
  return cfa_->pf_els_eSeedOverPOut();
}

std::vector<float>* const & cfa::pf_els_ecalIso() const{
  return cfa_->pf_els_ecalIso();
}

std::vector<float>* const & cfa::pf_els_energy() const{
  return cfa_->pf_els_energy();
}

std::vector<float>* const & cfa::pf_els_et() const{
  return cfa_->pf_els_et();
}

std::vector<float>* const & cfa::pf_els_eta() const{
  return cfa_->pf_els_eta();
}

std::vector<float>* const & cfa::pf_els_etaError() const{
  return cfa_->pf_els_etaError();
}

std::vector<float>* const & cfa::pf_els_fbrem() const{
  return cfa_->pf_els_fbrem();
}

std::vector<float>* const & cfa::pf_els_gen_et() const{
  return cfa_->pf_els_gen_et();
}

std::vector<float>* const & cfa::pf_els_gen_eta() const{
  return cfa_->pf_els_gen_eta();
}

std::vector<float>* const & cfa::pf_els_gen_id() const{
  return cfa_->pf_els_gen_id();
}

std::vector<float>* const & cfa::pf_els_gen_mother_et() const{
  return cfa_->pf_els_gen_mother_et();
}

std::vector<float>* const & cfa::pf_els_gen_mother_eta() const{
  return cfa_->pf_els_gen_mother_eta();
}

std::vector<float>* const & cfa::pf_els_gen_mother_id() const{
  return cfa_->pf_els_gen_mother_id();
}

std::vector<float>* const & cfa::pf_els_gen_mother_phi() const{
  return cfa_->pf_els_gen_mother_phi();
}

std::vector<float>* const & cfa::pf_els_gen_mother_pt() const{
  return cfa_->pf_els_gen_mother_pt();
}

std::vector<float>* const & cfa::pf_els_gen_mother_px() const{
  return cfa_->pf_els_gen_mother_px();
}

std::vector<float>* const & cfa::pf_els_gen_mother_py() const{
  return cfa_->pf_els_gen_mother_py();
}

std::vector<float>* const & cfa::pf_els_gen_mother_pz() const{
  return cfa_->pf_els_gen_mother_pz();
}

std::vector<float>* const & cfa::pf_els_gen_mother_theta() const{
  return cfa_->pf_els_gen_mother_theta();
}

std::vector<float>* const & cfa::pf_els_gen_phi() const{
  return cfa_->pf_els_gen_phi();
}

std::vector<float>* const & cfa::pf_els_gen_pt() const{
  return cfa_->pf_els_gen_pt();
}

std::vector<float>* const & cfa::pf_els_gen_px() const{
  return cfa_->pf_els_gen_px();
}

std::vector<float>* const & cfa::pf_els_gen_py() const{
  return cfa_->pf_els_gen_py();
}

std::vector<float>* const & cfa::pf_els_gen_pz() const{
  return cfa_->pf_els_gen_pz();
}

std::vector<float>* const & cfa::pf_els_gen_theta() const{
  return cfa_->pf_els_gen_theta();
}

std::vector<float>* const & cfa::pf_els_hadOverEm() const{
  return cfa_->pf_els_hadOverEm();
}

std::vector<bool>* const & cfa::pf_els_hasMatchedConversion() const{
  return cfa_->pf_els_hasMatchedConversion();
}

std::vector<float>* const & cfa::pf_els_hcalIso() const{
  return cfa_->pf_els_hcalIso();
}

std::vector<float>* const & cfa::pf_els_hcalOverEcalBc() const{
  return cfa_->pf_els_hcalOverEcalBc();
}

std::vector<float>* const & cfa::pf_els_isEB() const{
  return cfa_->pf_els_isEB();
}

std::vector<float>* const & cfa::pf_els_isEE() const{
  return cfa_->pf_els_isEE();
}

std::vector<float>* const & cfa::pf_els_looseId() const{
  return cfa_->pf_els_looseId();
}

std::vector<float>* const & cfa::pf_els_n_inner_layer() const{
  return cfa_->pf_els_n_inner_layer();
}

std::vector<float>* const & cfa::pf_els_n_outer_layer() const{
  return cfa_->pf_els_n_outer_layer();
}

std::vector<float>* const & cfa::pf_els_ndof() const{
  return cfa_->pf_els_ndof();
}

std::vector<float>* const & cfa::pf_els_neutralHadronIso() const{
  return cfa_->pf_els_neutralHadronIso();
}

std::vector<float>* const & cfa::pf_els_numlosthits() const{
  return cfa_->pf_els_numlosthits();
}

std::vector<float>* const & cfa::pf_els_numvalhits() const{
  return cfa_->pf_els_numvalhits();
}

std::vector<float>* const & cfa::pf_els_phi() const{
  return cfa_->pf_els_phi();
}

std::vector<float>* const & cfa::pf_els_phiError() const{
  return cfa_->pf_els_phiError();
}

std::vector<float>* const & cfa::pf_els_photonIso() const{
  return cfa_->pf_els_photonIso();
}

std::vector<float>* const & cfa::pf_els_pt() const{
  return cfa_->pf_els_pt();
}

std::vector<float>* const & cfa::pf_els_ptError() const{
  return cfa_->pf_els_ptError();
}

std::vector<float>* const & cfa::pf_els_px() const{
  return cfa_->pf_els_px();
}

std::vector<float>* const & cfa::pf_els_py() const{
  return cfa_->pf_els_py();
}

std::vector<float>* const & cfa::pf_els_pz() const{
  return cfa_->pf_els_pz();
}

std::vector<float>* const & cfa::pf_els_robustHighEnergyId() const{
  return cfa_->pf_els_robustHighEnergyId();
}

std::vector<float>* const & cfa::pf_els_robustLooseId() const{
  return cfa_->pf_els_robustLooseId();
}

std::vector<float>* const & cfa::pf_els_robustTightId() const{
  return cfa_->pf_els_robustTightId();
}

std::vector<float>* const & cfa::pf_els_scE1x5() const{
  return cfa_->pf_els_scE1x5();
}

std::vector<float>* const & cfa::pf_els_scE2x5Max() const{
  return cfa_->pf_els_scE2x5Max();
}

std::vector<float>* const & cfa::pf_els_scE5x5() const{
  return cfa_->pf_els_scE5x5();
}

std::vector<float>* const & cfa::pf_els_scEnergy() const{
  return cfa_->pf_els_scEnergy();
}

std::vector<float>* const & cfa::pf_els_scEta() const{
  return cfa_->pf_els_scEta();
}

std::vector<float>* const & cfa::pf_els_scEtaWidth() const{
  return cfa_->pf_els_scEtaWidth();
}

std::vector<float>* const & cfa::pf_els_scPhi() const{
  return cfa_->pf_els_scPhi();
}

std::vector<float>* const & cfa::pf_els_scPhiWidth() const{
  return cfa_->pf_els_scPhiWidth();
}

std::vector<float>* const & cfa::pf_els_scRawEnergy() const{
  return cfa_->pf_els_scRawEnergy();
}

std::vector<float>* const & cfa::pf_els_scSeedEnergy() const{
  return cfa_->pf_els_scSeedEnergy();
}

std::vector<float>* const & cfa::pf_els_shFracInnerHits() const{
  return cfa_->pf_els_shFracInnerHits();
}

std::vector<float>* const & cfa::pf_els_sigmaEtaEta() const{
  return cfa_->pf_els_sigmaEtaEta();
}

std::vector<float>* const & cfa::pf_els_sigmaIEtaIEta() const{
  return cfa_->pf_els_sigmaIEtaIEta();
}

std::vector<float>* const & cfa::pf_els_simpleEleId60cIso() const{
  return cfa_->pf_els_simpleEleId60cIso();
}

std::vector<float>* const & cfa::pf_els_simpleEleId60relIso() const{
  return cfa_->pf_els_simpleEleId60relIso();
}

std::vector<float>* const & cfa::pf_els_simpleEleId70cIso() const{
  return cfa_->pf_els_simpleEleId70cIso();
}

std::vector<float>* const & cfa::pf_els_simpleEleId70relIso() const{
  return cfa_->pf_els_simpleEleId70relIso();
}

std::vector<float>* const & cfa::pf_els_simpleEleId80cIso() const{
  return cfa_->pf_els_simpleEleId80cIso();
}

std::vector<float>* const & cfa::pf_els_simpleEleId80relIso() const{
  return cfa_->pf_els_simpleEleId80relIso();
}

std::vector<float>* const & cfa::pf_els_simpleEleId85cIso() const{
  return cfa_->pf_els_simpleEleId85cIso();
}

std::vector<float>* const & cfa::pf_els_simpleEleId85relIso() const{
  return cfa_->pf_els_simpleEleId85relIso();
}

std::vector<float>* const & cfa::pf_els_simpleEleId90cIso() const{
  return cfa_->pf_els_simpleEleId90cIso();
}

std::vector<float>* const & cfa::pf_els_simpleEleId90relIso() const{
  return cfa_->pf_els_simpleEleId90relIso();
}

std::vector<float>* const & cfa::pf_els_simpleEleId95cIso() const{
  return cfa_->pf_els_simpleEleId95cIso();
}

std::vector<float>* const & cfa::pf_els_simpleEleId95relIso() const{
  return cfa_->pf_els_simpleEleId95relIso();
}

std::vector<float>* const & cfa::pf_els_status() const{
  return cfa_->pf_els_status();
}

std::vector<float>* const & cfa::pf_els_tIso() const{
  return cfa_->pf_els_tIso();
}

std::vector<float>* const & cfa::pf_els_theta() const{
  return cfa_->pf_els_theta();
}

std::vector<float>* const & cfa::pf_els_tightId() const{
  return cfa_->pf_els_tightId();
}

std::vector<float>* const & cfa::pf_els_tk_charge() const{
  return cfa_->pf_els_tk_charge();
}

std::vector<float>* const & cfa::pf_els_tk_eta() const{
  return cfa_->pf_els_tk_eta();
}

std::vector<float>* const & cfa::pf_els_tk_phi() const{
  return cfa_->pf_els_tk_phi();
}

std::vector<float>* const & cfa::pf_els_tk_pt() const{
  return cfa_->pf_els_tk_pt();
}

std::vector<float>* const & cfa::pf_els_tk_pz() const{
  return cfa_->pf_els_tk_pz();
}

std::vector<float>* const & cfa::pf_els_vpx() const{
  return cfa_->pf_els_vpx();
}

std::vector<float>* const & cfa::pf_els_vpy() const{
  return cfa_->pf_els_vpy();
}

std::vector<float>* const & cfa::pf_els_vpz() const{
  return cfa_->pf_els_vpz();
}

std::vector<float>* const & cfa::pf_els_vx() const{
  return cfa_->pf_els_vx();
}

std::vector<float>* const & cfa::pf_els_vy() const{
  return cfa_->pf_els_vy();
}

std::vector<float>* const & cfa::pf_els_vz() const{
  return cfa_->pf_els_vz();
}

std::vector<float>* const & cfa::pf_mus_cIso() const{
  return cfa_->pf_mus_cIso();
}

std::vector<float>* const & cfa::pf_mus_calEnergyEm() const{
  return cfa_->pf_mus_calEnergyEm();
}

std::vector<float>* const & cfa::pf_mus_calEnergyEmS9() const{
  return cfa_->pf_mus_calEnergyEmS9();
}

std::vector<float>* const & cfa::pf_mus_calEnergyHad() const{
  return cfa_->pf_mus_calEnergyHad();
}

std::vector<float>* const & cfa::pf_mus_calEnergyHadS9() const{
  return cfa_->pf_mus_calEnergyHadS9();
}

std::vector<float>* const & cfa::pf_mus_calEnergyHo() const{
  return cfa_->pf_mus_calEnergyHo();
}

std::vector<float>* const & cfa::pf_mus_calEnergyHoS9() const{
  return cfa_->pf_mus_calEnergyHoS9();
}

std::vector<float>* const & cfa::pf_mus_charge() const{
  return cfa_->pf_mus_charge();
}

std::vector<float>* const & cfa::pf_mus_chargedHadronIso() const{
  return cfa_->pf_mus_chargedHadronIso();
}

std::vector<float>* const & cfa::pf_mus_cm_ExpectedHitsInner() const{
  return cfa_->pf_mus_cm_ExpectedHitsInner();
}

std::vector<float>* const & cfa::pf_mus_cm_ExpectedHitsOuter() const{
  return cfa_->pf_mus_cm_ExpectedHitsOuter();
}

std::vector<float>* const & cfa::pf_mus_cm_LayersWithMeasurement() const{
  return cfa_->pf_mus_cm_LayersWithMeasurement();
}

std::vector<float>* const & cfa::pf_mus_cm_LayersWithoutMeasurement() const{
  return cfa_->pf_mus_cm_LayersWithoutMeasurement();
}

std::vector<float>* const & cfa::pf_mus_cm_PixelLayersWithMeasurement() const{
  return cfa_->pf_mus_cm_PixelLayersWithMeasurement();
}

std::vector<float>* const & cfa::pf_mus_cm_ValidStripLayersWithMonoAndStereoHit() const{
  return cfa_->pf_mus_cm_ValidStripLayersWithMonoAndStereoHit();
}

std::vector<float>* const & cfa::pf_mus_cm_chg() const{
  return cfa_->pf_mus_cm_chg();
}

std::vector<float>* const & cfa::pf_mus_cm_chi2() const{
  return cfa_->pf_mus_cm_chi2();
}

std::vector<float>* const & cfa::pf_mus_cm_d0dum() const{
  return cfa_->pf_mus_cm_d0dum();
}

std::vector<float>* const & cfa::pf_mus_cm_d0dumErr() const{
  return cfa_->pf_mus_cm_d0dumErr();
}

std::vector<float>* const & cfa::pf_mus_cm_dz() const{
  return cfa_->pf_mus_cm_dz();
}

std::vector<float>* const & cfa::pf_mus_cm_dzErr() const{
  return cfa_->pf_mus_cm_dzErr();
}

std::vector<float>* const & cfa::pf_mus_cm_eta() const{
  return cfa_->pf_mus_cm_eta();
}

std::vector<float>* const & cfa::pf_mus_cm_etaErr() const{
  return cfa_->pf_mus_cm_etaErr();
}

std::vector<float>* const & cfa::pf_mus_cm_ndof() const{
  return cfa_->pf_mus_cm_ndof();
}

std::vector<float>* const & cfa::pf_mus_cm_numlosthits() const{
  return cfa_->pf_mus_cm_numlosthits();
}

std::vector<float>* const & cfa::pf_mus_cm_numvalMuonhits() const{
  return cfa_->pf_mus_cm_numvalMuonhits();
}

std::vector<float>* const & cfa::pf_mus_cm_numvalhits() const{
  return cfa_->pf_mus_cm_numvalhits();
}

std::vector<float>* const & cfa::pf_mus_cm_phi() const{
  return cfa_->pf_mus_cm_phi();
}

std::vector<float>* const & cfa::pf_mus_cm_phiErr() const{
  return cfa_->pf_mus_cm_phiErr();
}

std::vector<float>* const & cfa::pf_mus_cm_pt() const{
  return cfa_->pf_mus_cm_pt();
}

std::vector<float>* const & cfa::pf_mus_cm_ptErr() const{
  return cfa_->pf_mus_cm_ptErr();
}

std::vector<float>* const & cfa::pf_mus_cm_px() const{
  return cfa_->pf_mus_cm_px();
}

std::vector<float>* const & cfa::pf_mus_cm_py() const{
  return cfa_->pf_mus_cm_py();
}

std::vector<float>* const & cfa::pf_mus_cm_pz() const{
  return cfa_->pf_mus_cm_pz();
}

std::vector<float>* const & cfa::pf_mus_cm_theta() const{
  return cfa_->pf_mus_cm_theta();
}

std::vector<float>* const & cfa::pf_mus_cm_vx() const{
  return cfa_->pf_mus_cm_vx();
}

std::vector<float>* const & cfa::pf_mus_cm_vy() const{
  return cfa_->pf_mus_cm_vy();
}

std::vector<float>* const & cfa::pf_mus_cm_vz() const{
  return cfa_->pf_mus_cm_vz();
}

std::vector<float>* const & cfa::pf_mus_dB() const{
  return cfa_->pf_mus_dB();
}

std::vector<float>* const & cfa::pf_mus_ecalIso() const{
  return cfa_->pf_mus_ecalIso();
}

std::vector<float>* const & cfa::pf_mus_energy() const{
  return cfa_->pf_mus_energy();
}

std::vector<float>* const & cfa::pf_mus_et() const{
  return cfa_->pf_mus_et();
}

std::vector<float>* const & cfa::pf_mus_eta() const{
  return cfa_->pf_mus_eta();
}

std::vector<float>* const & cfa::pf_mus_gen_et() const{
  return cfa_->pf_mus_gen_et();
}

std::vector<float>* const & cfa::pf_mus_gen_eta() const{
  return cfa_->pf_mus_gen_eta();
}

std::vector<float>* const & cfa::pf_mus_gen_id() const{
  return cfa_->pf_mus_gen_id();
}

std::vector<float>* const & cfa::pf_mus_gen_mother_et() const{
  return cfa_->pf_mus_gen_mother_et();
}

std::vector<float>* const & cfa::pf_mus_gen_mother_eta() const{
  return cfa_->pf_mus_gen_mother_eta();
}

std::vector<float>* const & cfa::pf_mus_gen_mother_id() const{
  return cfa_->pf_mus_gen_mother_id();
}

std::vector<float>* const & cfa::pf_mus_gen_mother_phi() const{
  return cfa_->pf_mus_gen_mother_phi();
}

std::vector<float>* const & cfa::pf_mus_gen_mother_pt() const{
  return cfa_->pf_mus_gen_mother_pt();
}

std::vector<float>* const & cfa::pf_mus_gen_mother_px() const{
  return cfa_->pf_mus_gen_mother_px();
}

std::vector<float>* const & cfa::pf_mus_gen_mother_py() const{
  return cfa_->pf_mus_gen_mother_py();
}

std::vector<float>* const & cfa::pf_mus_gen_mother_pz() const{
  return cfa_->pf_mus_gen_mother_pz();
}

std::vector<float>* const & cfa::pf_mus_gen_mother_theta() const{
  return cfa_->pf_mus_gen_mother_theta();
}

std::vector<float>* const & cfa::pf_mus_gen_phi() const{
  return cfa_->pf_mus_gen_phi();
}

std::vector<float>* const & cfa::pf_mus_gen_pt() const{
  return cfa_->pf_mus_gen_pt();
}

std::vector<float>* const & cfa::pf_mus_gen_px() const{
  return cfa_->pf_mus_gen_px();
}

std::vector<float>* const & cfa::pf_mus_gen_py() const{
  return cfa_->pf_mus_gen_py();
}

std::vector<float>* const & cfa::pf_mus_gen_pz() const{
  return cfa_->pf_mus_gen_pz();
}

std::vector<float>* const & cfa::pf_mus_gen_theta() const{
  return cfa_->pf_mus_gen_theta();
}

std::vector<float>* const & cfa::pf_mus_hcalIso() const{
  return cfa_->pf_mus_hcalIso();
}

std::vector<float>* const & cfa::pf_mus_id_All() const{
  return cfa_->pf_mus_id_All();
}

std::vector<float>* const & cfa::pf_mus_id_AllArbitrated() const{
  return cfa_->pf_mus_id_AllArbitrated();
}

std::vector<float>* const & cfa::pf_mus_id_AllGlobalMuons() const{
  return cfa_->pf_mus_id_AllGlobalMuons();
}

std::vector<float>* const & cfa::pf_mus_id_AllStandAloneMuons() const{
  return cfa_->pf_mus_id_AllStandAloneMuons();
}

std::vector<float>* const & cfa::pf_mus_id_AllTrackerMuons() const{
  return cfa_->pf_mus_id_AllTrackerMuons();
}

std::vector<float>* const & cfa::pf_mus_id_GlobalMuonPromptTight() const{
  return cfa_->pf_mus_id_GlobalMuonPromptTight();
}

std::vector<float>* const & cfa::pf_mus_id_TM2DCompatibilityLoose() const{
  return cfa_->pf_mus_id_TM2DCompatibilityLoose();
}

std::vector<float>* const & cfa::pf_mus_id_TM2DCompatibilityTight() const{
  return cfa_->pf_mus_id_TM2DCompatibilityTight();
}

std::vector<float>* const & cfa::pf_mus_id_TMLastStationLoose() const{
  return cfa_->pf_mus_id_TMLastStationLoose();
}

std::vector<float>* const & cfa::pf_mus_id_TMLastStationOptimizedLowPtLoose() const{
  return cfa_->pf_mus_id_TMLastStationOptimizedLowPtLoose();
}

std::vector<float>* const & cfa::pf_mus_id_TMLastStationOptimizedLowPtTight() const{
  return cfa_->pf_mus_id_TMLastStationOptimizedLowPtTight();
}

std::vector<float>* const & cfa::pf_mus_id_TMLastStationTight() const{
  return cfa_->pf_mus_id_TMLastStationTight();
}

std::vector<float>* const & cfa::pf_mus_id_TMOneStationLoose() const{
  return cfa_->pf_mus_id_TMOneStationLoose();
}

std::vector<float>* const & cfa::pf_mus_id_TMOneStationTight() const{
  return cfa_->pf_mus_id_TMOneStationTight();
}

std::vector<float>* const & cfa::pf_mus_id_TrackerMuonArbitrated() const{
  return cfa_->pf_mus_id_TrackerMuonArbitrated();
}

std::vector<float>* const & cfa::pf_mus_isCaloMuon() const{
  return cfa_->pf_mus_isCaloMuon();
}

std::vector<float>* const & cfa::pf_mus_isConvertedPhoton() const{
  return cfa_->pf_mus_isConvertedPhoton();
}

std::vector<float>* const & cfa::pf_mus_isElectron() const{
  return cfa_->pf_mus_isElectron();
}

std::vector<float>* const & cfa::pf_mus_isGlobalMuon() const{
  return cfa_->pf_mus_isGlobalMuon();
}

std::vector<float>* const & cfa::pf_mus_isPFMuon() const{
  return cfa_->pf_mus_isPFMuon();
}

std::vector<float>* const & cfa::pf_mus_isPhoton() const{
  return cfa_->pf_mus_isPhoton();
}

std::vector<float>* const & cfa::pf_mus_isStandAloneMuon() const{
  return cfa_->pf_mus_isStandAloneMuon();
}

std::vector<float>* const & cfa::pf_mus_isTrackerMuon() const{
  return cfa_->pf_mus_isTrackerMuon();
}

std::vector<float>* const & cfa::pf_mus_iso03_emEt() const{
  return cfa_->pf_mus_iso03_emEt();
}

std::vector<float>* const & cfa::pf_mus_iso03_emVetoEt() const{
  return cfa_->pf_mus_iso03_emVetoEt();
}

std::vector<float>* const & cfa::pf_mus_iso03_hadEt() const{
  return cfa_->pf_mus_iso03_hadEt();
}

std::vector<float>* const & cfa::pf_mus_iso03_hadVetoEt() const{
  return cfa_->pf_mus_iso03_hadVetoEt();
}

std::vector<float>* const & cfa::pf_mus_iso03_hoEt() const{
  return cfa_->pf_mus_iso03_hoEt();
}

std::vector<float>* const & cfa::pf_mus_iso03_nTracks() const{
  return cfa_->pf_mus_iso03_nTracks();
}

std::vector<float>* const & cfa::pf_mus_iso03_sumPt() const{
  return cfa_->pf_mus_iso03_sumPt();
}

std::vector<float>* const & cfa::pf_mus_iso05_emEt() const{
  return cfa_->pf_mus_iso05_emEt();
}

std::vector<float>* const & cfa::pf_mus_iso05_hadEt() const{
  return cfa_->pf_mus_iso05_hadEt();
}

std::vector<float>* const & cfa::pf_mus_iso05_hoEt() const{
  return cfa_->pf_mus_iso05_hoEt();
}

std::vector<float>* const & cfa::pf_mus_iso05_nTracks() const{
  return cfa_->pf_mus_iso05_nTracks();
}

std::vector<float>* const & cfa::pf_mus_iso05_sumPt() const{
  return cfa_->pf_mus_iso05_sumPt();
}

std::vector<float>* const & cfa::pf_mus_neutralHadronIso() const{
  return cfa_->pf_mus_neutralHadronIso();
}

std::vector<float>* const & cfa::pf_mus_num_matches() const{
  return cfa_->pf_mus_num_matches();
}

std::vector<float>* const & cfa::pf_mus_numberOfMatchedStations() const{
  return cfa_->pf_mus_numberOfMatchedStations();
}

std::vector<float>* const & cfa::pf_mus_pfIsolationR03_sumChargedHadronPt() const{
  return cfa_->pf_mus_pfIsolationR03_sumChargedHadronPt();
}

std::vector<float>* const & cfa::pf_mus_pfIsolationR03_sumChargedParticlePt() const{
  return cfa_->pf_mus_pfIsolationR03_sumChargedParticlePt();
}

std::vector<float>* const & cfa::pf_mus_pfIsolationR03_sumNeutralHadronEt() const{
  return cfa_->pf_mus_pfIsolationR03_sumNeutralHadronEt();
}

std::vector<float>* const & cfa::pf_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold() const{
  return cfa_->pf_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold();
}

std::vector<float>* const & cfa::pf_mus_pfIsolationR03_sumPUPt() const{
  return cfa_->pf_mus_pfIsolationR03_sumPUPt();
}

std::vector<float>* const & cfa::pf_mus_pfIsolationR03_sumPhotonEt() const{
  return cfa_->pf_mus_pfIsolationR03_sumPhotonEt();
}

std::vector<float>* const & cfa::pf_mus_pfIsolationR03_sumPhotonEtHighThreshold() const{
  return cfa_->pf_mus_pfIsolationR03_sumPhotonEtHighThreshold();
}

std::vector<float>* const & cfa::pf_mus_pfIsolationR04_sumChargedHadronPt() const{
  return cfa_->pf_mus_pfIsolationR04_sumChargedHadronPt();
}

std::vector<float>* const & cfa::pf_mus_pfIsolationR04_sumChargedParticlePt() const{
  return cfa_->pf_mus_pfIsolationR04_sumChargedParticlePt();
}

std::vector<float>* const & cfa::pf_mus_pfIsolationR04_sumNeutralHadronEt() const{
  return cfa_->pf_mus_pfIsolationR04_sumNeutralHadronEt();
}

std::vector<float>* const & cfa::pf_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold() const{
  return cfa_->pf_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold();
}

std::vector<float>* const & cfa::pf_mus_pfIsolationR04_sumPUPt() const{
  return cfa_->pf_mus_pfIsolationR04_sumPUPt();
}

std::vector<float>* const & cfa::pf_mus_pfIsolationR04_sumPhotonEt() const{
  return cfa_->pf_mus_pfIsolationR04_sumPhotonEt();
}

std::vector<float>* const & cfa::pf_mus_pfIsolationR04_sumPhotonEtHighThreshold() const{
  return cfa_->pf_mus_pfIsolationR04_sumPhotonEtHighThreshold();
}

std::vector<float>* const & cfa::pf_mus_phi() const{
  return cfa_->pf_mus_phi();
}

std::vector<float>* const & cfa::pf_mus_photonIso() const{
  return cfa_->pf_mus_photonIso();
}

std::vector<float>* const & cfa::pf_mus_picky_ExpectedHitsInner() const{
  return cfa_->pf_mus_picky_ExpectedHitsInner();
}

std::vector<float>* const & cfa::pf_mus_picky_ExpectedHitsOuter() const{
  return cfa_->pf_mus_picky_ExpectedHitsOuter();
}

std::vector<float>* const & cfa::pf_mus_picky_LayersWithMeasurement() const{
  return cfa_->pf_mus_picky_LayersWithMeasurement();
}

std::vector<float>* const & cfa::pf_mus_picky_LayersWithoutMeasurement() const{
  return cfa_->pf_mus_picky_LayersWithoutMeasurement();
}

std::vector<float>* const & cfa::pf_mus_picky_PixelLayersWithMeasurement() const{
  return cfa_->pf_mus_picky_PixelLayersWithMeasurement();
}

std::vector<float>* const & cfa::pf_mus_picky_ValidStripLayersWithMonoAndStereoHit() const{
  return cfa_->pf_mus_picky_ValidStripLayersWithMonoAndStereoHit();
}

std::vector<float>* const & cfa::pf_mus_picky_chg() const{
  return cfa_->pf_mus_picky_chg();
}

std::vector<float>* const & cfa::pf_mus_picky_chi2() const{
  return cfa_->pf_mus_picky_chi2();
}

std::vector<float>* const & cfa::pf_mus_picky_d0dum() const{
  return cfa_->pf_mus_picky_d0dum();
}

std::vector<float>* const & cfa::pf_mus_picky_d0dumErr() const{
  return cfa_->pf_mus_picky_d0dumErr();
}

std::vector<float>* const & cfa::pf_mus_picky_dz() const{
  return cfa_->pf_mus_picky_dz();
}

std::vector<float>* const & cfa::pf_mus_picky_dzErr() const{
  return cfa_->pf_mus_picky_dzErr();
}

std::vector<float>* const & cfa::pf_mus_picky_eta() const{
  return cfa_->pf_mus_picky_eta();
}

std::vector<float>* const & cfa::pf_mus_picky_etaErr() const{
  return cfa_->pf_mus_picky_etaErr();
}

std::vector<float>* const & cfa::pf_mus_picky_id() const{
  return cfa_->pf_mus_picky_id();
}

std::vector<float>* const & cfa::pf_mus_picky_ndof() const{
  return cfa_->pf_mus_picky_ndof();
}

std::vector<float>* const & cfa::pf_mus_picky_numlosthits() const{
  return cfa_->pf_mus_picky_numlosthits();
}

std::vector<float>* const & cfa::pf_mus_picky_numvalPixelhits() const{
  return cfa_->pf_mus_picky_numvalPixelhits();
}

std::vector<float>* const & cfa::pf_mus_picky_numvalhits() const{
  return cfa_->pf_mus_picky_numvalhits();
}

std::vector<float>* const & cfa::pf_mus_picky_phi() const{
  return cfa_->pf_mus_picky_phi();
}

std::vector<float>* const & cfa::pf_mus_picky_phiErr() const{
  return cfa_->pf_mus_picky_phiErr();
}

std::vector<float>* const & cfa::pf_mus_picky_pt() const{
  return cfa_->pf_mus_picky_pt();
}

std::vector<float>* const & cfa::pf_mus_picky_ptErr() const{
  return cfa_->pf_mus_picky_ptErr();
}

std::vector<float>* const & cfa::pf_mus_picky_px() const{
  return cfa_->pf_mus_picky_px();
}

std::vector<float>* const & cfa::pf_mus_picky_py() const{
  return cfa_->pf_mus_picky_py();
}

std::vector<float>* const & cfa::pf_mus_picky_pz() const{
  return cfa_->pf_mus_picky_pz();
}

std::vector<float>* const & cfa::pf_mus_picky_theta() const{
  return cfa_->pf_mus_picky_theta();
}

std::vector<float>* const & cfa::pf_mus_picky_vx() const{
  return cfa_->pf_mus_picky_vx();
}

std::vector<float>* const & cfa::pf_mus_picky_vy() const{
  return cfa_->pf_mus_picky_vy();
}

std::vector<float>* const & cfa::pf_mus_picky_vz() const{
  return cfa_->pf_mus_picky_vz();
}

std::vector<float>* const & cfa::pf_mus_pt() const{
  return cfa_->pf_mus_pt();
}

std::vector<float>* const & cfa::pf_mus_px() const{
  return cfa_->pf_mus_px();
}

std::vector<float>* const & cfa::pf_mus_py() const{
  return cfa_->pf_mus_py();
}

std::vector<float>* const & cfa::pf_mus_pz() const{
  return cfa_->pf_mus_pz();
}

std::vector<float>* const & cfa::pf_mus_stamu_chg() const{
  return cfa_->pf_mus_stamu_chg();
}

std::vector<float>* const & cfa::pf_mus_stamu_chi2() const{
  return cfa_->pf_mus_stamu_chi2();
}

std::vector<float>* const & cfa::pf_mus_stamu_d0dum() const{
  return cfa_->pf_mus_stamu_d0dum();
}

std::vector<float>* const & cfa::pf_mus_stamu_d0dumErr() const{
  return cfa_->pf_mus_stamu_d0dumErr();
}

std::vector<float>* const & cfa::pf_mus_stamu_dz() const{
  return cfa_->pf_mus_stamu_dz();
}

std::vector<float>* const & cfa::pf_mus_stamu_dzErr() const{
  return cfa_->pf_mus_stamu_dzErr();
}

std::vector<float>* const & cfa::pf_mus_stamu_eta() const{
  return cfa_->pf_mus_stamu_eta();
}

std::vector<float>* const & cfa::pf_mus_stamu_etaErr() const{
  return cfa_->pf_mus_stamu_etaErr();
}

std::vector<float>* const & cfa::pf_mus_stamu_ndof() const{
  return cfa_->pf_mus_stamu_ndof();
}

std::vector<float>* const & cfa::pf_mus_stamu_numlosthits() const{
  return cfa_->pf_mus_stamu_numlosthits();
}

std::vector<float>* const & cfa::pf_mus_stamu_numvalhits() const{
  return cfa_->pf_mus_stamu_numvalhits();
}

std::vector<float>* const & cfa::pf_mus_stamu_phi() const{
  return cfa_->pf_mus_stamu_phi();
}

std::vector<float>* const & cfa::pf_mus_stamu_phiErr() const{
  return cfa_->pf_mus_stamu_phiErr();
}

std::vector<float>* const & cfa::pf_mus_stamu_pt() const{
  return cfa_->pf_mus_stamu_pt();
}

std::vector<float>* const & cfa::pf_mus_stamu_ptErr() const{
  return cfa_->pf_mus_stamu_ptErr();
}

std::vector<float>* const & cfa::pf_mus_stamu_px() const{
  return cfa_->pf_mus_stamu_px();
}

std::vector<float>* const & cfa::pf_mus_stamu_py() const{
  return cfa_->pf_mus_stamu_py();
}

std::vector<float>* const & cfa::pf_mus_stamu_pz() const{
  return cfa_->pf_mus_stamu_pz();
}

std::vector<float>* const & cfa::pf_mus_stamu_theta() const{
  return cfa_->pf_mus_stamu_theta();
}

std::vector<float>* const & cfa::pf_mus_stamu_vx() const{
  return cfa_->pf_mus_stamu_vx();
}

std::vector<float>* const & cfa::pf_mus_stamu_vy() const{
  return cfa_->pf_mus_stamu_vy();
}

std::vector<float>* const & cfa::pf_mus_stamu_vz() const{
  return cfa_->pf_mus_stamu_vz();
}

std::vector<float>* const & cfa::pf_mus_status() const{
  return cfa_->pf_mus_status();
}

std::vector<float>* const & cfa::pf_mus_tIso() const{
  return cfa_->pf_mus_tIso();
}

std::vector<float>* const & cfa::pf_mus_theta() const{
  return cfa_->pf_mus_theta();
}

std::vector<float>* const & cfa::pf_mus_tkHits() const{
  return cfa_->pf_mus_tkHits();
}

std::vector<float>* const & cfa::pf_mus_tk_ExpectedHitsInner() const{
  return cfa_->pf_mus_tk_ExpectedHitsInner();
}

std::vector<float>* const & cfa::pf_mus_tk_ExpectedHitsOuter() const{
  return cfa_->pf_mus_tk_ExpectedHitsOuter();
}

std::vector<float>* const & cfa::pf_mus_tk_LayersWithMeasurement() const{
  return cfa_->pf_mus_tk_LayersWithMeasurement();
}

std::vector<float>* const & cfa::pf_mus_tk_LayersWithoutMeasurement() const{
  return cfa_->pf_mus_tk_LayersWithoutMeasurement();
}

std::vector<float>* const & cfa::pf_mus_tk_PixelLayersWithMeasurement() const{
  return cfa_->pf_mus_tk_PixelLayersWithMeasurement();
}

std::vector<float>* const & cfa::pf_mus_tk_ValidStripLayersWithMonoAndStereoHit() const{
  return cfa_->pf_mus_tk_ValidStripLayersWithMonoAndStereoHit();
}

std::vector<float>* const & cfa::pf_mus_tk_chg() const{
  return cfa_->pf_mus_tk_chg();
}

std::vector<float>* const & cfa::pf_mus_tk_chi2() const{
  return cfa_->pf_mus_tk_chi2();
}

std::vector<float>* const & cfa::pf_mus_tk_d0dum() const{
  return cfa_->pf_mus_tk_d0dum();
}

std::vector<float>* const & cfa::pf_mus_tk_d0dumErr() const{
  return cfa_->pf_mus_tk_d0dumErr();
}

std::vector<float>* const & cfa::pf_mus_tk_dz() const{
  return cfa_->pf_mus_tk_dz();
}

std::vector<float>* const & cfa::pf_mus_tk_dzErr() const{
  return cfa_->pf_mus_tk_dzErr();
}

std::vector<float>* const & cfa::pf_mus_tk_eta() const{
  return cfa_->pf_mus_tk_eta();
}

std::vector<float>* const & cfa::pf_mus_tk_etaErr() const{
  return cfa_->pf_mus_tk_etaErr();
}

std::vector<float>* const & cfa::pf_mus_tk_id() const{
  return cfa_->pf_mus_tk_id();
}

std::vector<float>* const & cfa::pf_mus_tk_ndof() const{
  return cfa_->pf_mus_tk_ndof();
}

std::vector<float>* const & cfa::pf_mus_tk_numlosthits() const{
  return cfa_->pf_mus_tk_numlosthits();
}

std::vector<float>* const & cfa::pf_mus_tk_numpixelWthMeasr() const{
  return cfa_->pf_mus_tk_numpixelWthMeasr();
}

std::vector<float>* const & cfa::pf_mus_tk_numvalPixelhits() const{
  return cfa_->pf_mus_tk_numvalPixelhits();
}

std::vector<float>* const & cfa::pf_mus_tk_numvalhits() const{
  return cfa_->pf_mus_tk_numvalhits();
}

std::vector<float>* const & cfa::pf_mus_tk_phi() const{
  return cfa_->pf_mus_tk_phi();
}

std::vector<float>* const & cfa::pf_mus_tk_phiErr() const{
  return cfa_->pf_mus_tk_phiErr();
}

std::vector<float>* const & cfa::pf_mus_tk_pt() const{
  return cfa_->pf_mus_tk_pt();
}

std::vector<float>* const & cfa::pf_mus_tk_ptErr() const{
  return cfa_->pf_mus_tk_ptErr();
}

std::vector<float>* const & cfa::pf_mus_tk_px() const{
  return cfa_->pf_mus_tk_px();
}

std::vector<float>* const & cfa::pf_mus_tk_py() const{
  return cfa_->pf_mus_tk_py();
}

std::vector<float>* const & cfa::pf_mus_tk_pz() const{
  return cfa_->pf_mus_tk_pz();
}

std::vector<float>* const & cfa::pf_mus_tk_theta() const{
  return cfa_->pf_mus_tk_theta();
}

std::vector<float>* const & cfa::pf_mus_tk_vx() const{
  return cfa_->pf_mus_tk_vx();
}

std::vector<float>* const & cfa::pf_mus_tk_vy() const{
  return cfa_->pf_mus_tk_vy();
}

std::vector<float>* const & cfa::pf_mus_tk_vz() const{
  return cfa_->pf_mus_tk_vz();
}

std::vector<float>* const & cfa::pf_mus_tpfms_ExpectedHitsInner() const{
  return cfa_->pf_mus_tpfms_ExpectedHitsInner();
}

std::vector<float>* const & cfa::pf_mus_tpfms_ExpectedHitsOuter() const{
  return cfa_->pf_mus_tpfms_ExpectedHitsOuter();
}

std::vector<float>* const & cfa::pf_mus_tpfms_LayersWithMeasurement() const{
  return cfa_->pf_mus_tpfms_LayersWithMeasurement();
}

std::vector<float>* const & cfa::pf_mus_tpfms_LayersWithoutMeasurement() const{
  return cfa_->pf_mus_tpfms_LayersWithoutMeasurement();
}

std::vector<float>* const & cfa::pf_mus_tpfms_PixelLayersWithMeasurement() const{
  return cfa_->pf_mus_tpfms_PixelLayersWithMeasurement();
}

std::vector<float>* const & cfa::pf_mus_tpfms_ValidStripLayersWithMonoAndStereoHit() const{
  return cfa_->pf_mus_tpfms_ValidStripLayersWithMonoAndStereoHit();
}

std::vector<float>* const & cfa::pf_mus_tpfms_chg() const{
  return cfa_->pf_mus_tpfms_chg();
}

std::vector<float>* const & cfa::pf_mus_tpfms_chi2() const{
  return cfa_->pf_mus_tpfms_chi2();
}

std::vector<float>* const & cfa::pf_mus_tpfms_d0dum() const{
  return cfa_->pf_mus_tpfms_d0dum();
}

std::vector<float>* const & cfa::pf_mus_tpfms_d0dumErr() const{
  return cfa_->pf_mus_tpfms_d0dumErr();
}

std::vector<float>* const & cfa::pf_mus_tpfms_dz() const{
  return cfa_->pf_mus_tpfms_dz();
}

std::vector<float>* const & cfa::pf_mus_tpfms_dzErr() const{
  return cfa_->pf_mus_tpfms_dzErr();
}

std::vector<float>* const & cfa::pf_mus_tpfms_eta() const{
  return cfa_->pf_mus_tpfms_eta();
}

std::vector<float>* const & cfa::pf_mus_tpfms_etaErr() const{
  return cfa_->pf_mus_tpfms_etaErr();
}

std::vector<float>* const & cfa::pf_mus_tpfms_id() const{
  return cfa_->pf_mus_tpfms_id();
}

std::vector<float>* const & cfa::pf_mus_tpfms_ndof() const{
  return cfa_->pf_mus_tpfms_ndof();
}

std::vector<float>* const & cfa::pf_mus_tpfms_numlosthits() const{
  return cfa_->pf_mus_tpfms_numlosthits();
}

std::vector<float>* const & cfa::pf_mus_tpfms_numvalPixelhits() const{
  return cfa_->pf_mus_tpfms_numvalPixelhits();
}

std::vector<float>* const & cfa::pf_mus_tpfms_numvalhits() const{
  return cfa_->pf_mus_tpfms_numvalhits();
}

std::vector<float>* const & cfa::pf_mus_tpfms_phi() const{
  return cfa_->pf_mus_tpfms_phi();
}

std::vector<float>* const & cfa::pf_mus_tpfms_phiErr() const{
  return cfa_->pf_mus_tpfms_phiErr();
}

std::vector<float>* const & cfa::pf_mus_tpfms_pt() const{
  return cfa_->pf_mus_tpfms_pt();
}

std::vector<float>* const & cfa::pf_mus_tpfms_ptErr() const{
  return cfa_->pf_mus_tpfms_ptErr();
}

std::vector<float>* const & cfa::pf_mus_tpfms_px() const{
  return cfa_->pf_mus_tpfms_px();
}

std::vector<float>* const & cfa::pf_mus_tpfms_py() const{
  return cfa_->pf_mus_tpfms_py();
}

std::vector<float>* const & cfa::pf_mus_tpfms_pz() const{
  return cfa_->pf_mus_tpfms_pz();
}

std::vector<float>* const & cfa::pf_mus_tpfms_theta() const{
  return cfa_->pf_mus_tpfms_theta();
}

std::vector<float>* const & cfa::pf_mus_tpfms_vx() const{
  return cfa_->pf_mus_tpfms_vx();
}

std::vector<float>* const & cfa::pf_mus_tpfms_vy() const{
  return cfa_->pf_mus_tpfms_vy();
}

std::vector<float>* const & cfa::pf_mus_tpfms_vz() const{
  return cfa_->pf_mus_tpfms_vz();
}

std::vector<float>* const & cfa::pf_photons_chIso() const{
  return cfa_->pf_photons_chIso();
}

std::vector<float>* const & cfa::pf_photons_e1x5() const{
  return cfa_->pf_photons_e1x5();
}

std::vector<float>* const & cfa::pf_photons_e2x5() const{
  return cfa_->pf_photons_e2x5();
}

std::vector<float>* const & cfa::pf_photons_e3x3() const{
  return cfa_->pf_photons_e3x3();
}

std::vector<float>* const & cfa::pf_photons_e5x5() const{
  return cfa_->pf_photons_e5x5();
}

std::vector<float>* const & cfa::pf_photons_energy() const{
  return cfa_->pf_photons_energy();
}

std::vector<float>* const & cfa::pf_photons_et() const{
  return cfa_->pf_photons_et();
}

std::vector<float>* const & cfa::pf_photons_eta() const{
  return cfa_->pf_photons_eta();
}

std::vector<float>* const & cfa::pf_photons_hadOverEM() const{
  return cfa_->pf_photons_hadOverEM();
}

std::vector<float>* const & cfa::pf_photons_hadTowOverEM() const{
  return cfa_->pf_photons_hadTowOverEM();
}

std::vector<float>* const & cfa::pf_photons_hasPixelSeed() const{
  return cfa_->pf_photons_hasPixelSeed();
}

std::vector<float>* const & cfa::pf_photons_isAlsoElectron() const{
  return cfa_->pf_photons_isAlsoElectron();
}

std::vector<float>* const & cfa::pf_photons_isConverted() const{
  return cfa_->pf_photons_isConverted();
}

std::vector<float>* const & cfa::pf_photons_isEBEEGap() const{
  return cfa_->pf_photons_isEBEEGap();
}

std::vector<float>* const & cfa::pf_photons_isEBGap() const{
  return cfa_->pf_photons_isEBGap();
}

std::vector<float>* const & cfa::pf_photons_isEBPho() const{
  return cfa_->pf_photons_isEBPho();
}

std::vector<float>* const & cfa::pf_photons_isEEGap() const{
  return cfa_->pf_photons_isEEGap();
}

std::vector<float>* const & cfa::pf_photons_isEEPho() const{
  return cfa_->pf_photons_isEEPho();
}

std::vector<float>* const & cfa::pf_photons_maxEnergyXtal() const{
  return cfa_->pf_photons_maxEnergyXtal();
}

std::vector<float>* const & cfa::pf_photons_nhIso() const{
  return cfa_->pf_photons_nhIso();
}

std::vector<float>* const & cfa::pf_photons_phIso() const{
  return cfa_->pf_photons_phIso();
}

std::vector<float>* const & cfa::pf_photons_phi() const{
  return cfa_->pf_photons_phi();
}

std::vector<float>* const & cfa::pf_photons_pt() const{
  return cfa_->pf_photons_pt();
}

std::vector<float>* const & cfa::pf_photons_px() const{
  return cfa_->pf_photons_px();
}

std::vector<float>* const & cfa::pf_photons_py() const{
  return cfa_->pf_photons_py();
}

std::vector<float>* const & cfa::pf_photons_pz() const{
  return cfa_->pf_photons_pz();
}

std::vector<float>* const & cfa::pf_photons_r9() const{
  return cfa_->pf_photons_r9();
}

std::vector<float>* const & cfa::pf_photons_scEnergy() const{
  return cfa_->pf_photons_scEnergy();
}

std::vector<float>* const & cfa::pf_photons_scEta() const{
  return cfa_->pf_photons_scEta();
}

std::vector<float>* const & cfa::pf_photons_scEtaWidth() const{
  return cfa_->pf_photons_scEtaWidth();
}

std::vector<float>* const & cfa::pf_photons_scPhi() const{
  return cfa_->pf_photons_scPhi();
}

std::vector<float>* const & cfa::pf_photons_scPhiWidth() const{
  return cfa_->pf_photons_scPhiWidth();
}

std::vector<float>* const & cfa::pf_photons_scRawEnergy() const{
  return cfa_->pf_photons_scRawEnergy();
}

std::vector<float>* const & cfa::pf_photons_sigmaEtaEta() const{
  return cfa_->pf_photons_sigmaEtaEta();
}

std::vector<float>* const & cfa::pf_photons_sigmaIetaIeta() const{
  return cfa_->pf_photons_sigmaIetaIeta();
}

std::vector<float>* const & cfa::pf_photons_status() const{
  return cfa_->pf_photons_status();
}

std::vector<float>* const & cfa::pf_photons_theta() const{
  return cfa_->pf_photons_theta();
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

std::vector<float>* const & cfa::pfcand_particleId() const{
  return cfa_->pfcand_particleId();
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

std::vector<float>* const & cfa::pfmets_et() const{
  return cfa_->pfmets_et();
}

std::vector<float>* const & cfa::pfmets_ex() const{
  return cfa_->pfmets_ex();
}

std::vector<float>* const & cfa::pfmets_ey() const{
  return cfa_->pfmets_ey();
}

Float_t const & cfa::pfmets_fullSignif() const{
  return cfa_->pfmets_fullSignif();
}

Float_t const & cfa::pfmets_fullSignifCov00() const{
  return cfa_->pfmets_fullSignifCov00();
}

Float_t const & cfa::pfmets_fullSignifCov00_2012() const{
  return cfa_->pfmets_fullSignifCov00_2012();
}

Float_t const & cfa::pfmets_fullSignifCov00_2012_dataRes() const{
  return cfa_->pfmets_fullSignifCov00_2012_dataRes();
}

Float_t const & cfa::pfmets_fullSignifCov10() const{
  return cfa_->pfmets_fullSignifCov10();
}

Float_t const & cfa::pfmets_fullSignifCov10_2012() const{
  return cfa_->pfmets_fullSignifCov10_2012();
}

Float_t const & cfa::pfmets_fullSignifCov10_2012_dataRes() const{
  return cfa_->pfmets_fullSignifCov10_2012_dataRes();
}

Float_t const & cfa::pfmets_fullSignifCov11() const{
  return cfa_->pfmets_fullSignifCov11();
}

Float_t const & cfa::pfmets_fullSignifCov11_2012() const{
  return cfa_->pfmets_fullSignifCov11_2012();
}

Float_t const & cfa::pfmets_fullSignifCov11_2012_dataRes() const{
  return cfa_->pfmets_fullSignifCov11_2012_dataRes();
}

Float_t const & cfa::pfmets_fullSignif_2012() const{
  return cfa_->pfmets_fullSignif_2012();
}

Float_t const & cfa::pfmets_fullSignif_2012_dataRes() const{
  return cfa_->pfmets_fullSignif_2012_dataRes();
}

std::vector<float>* const & cfa::pfmets_gen_et() const{
  return cfa_->pfmets_gen_et();
}

std::vector<float>* const & cfa::pfmets_gen_phi() const{
  return cfa_->pfmets_gen_phi();
}

std::vector<float>* const & cfa::pfmets_phi() const{
  return cfa_->pfmets_phi();
}

std::vector<float>* const & cfa::pfmets_sign() const{
  return cfa_->pfmets_sign();
}

std::vector<float>* const & cfa::pfmets_sumEt() const{
  return cfa_->pfmets_sumEt();
}

std::vector<float>* const & cfa::pfmets_unCPhi() const{
  return cfa_->pfmets_unCPhi();
}

std::vector<float>* const & cfa::pfmets_unCPt() const{
  return cfa_->pfmets_unCPt();
}

std::vector<float>* const & cfa::photon_chIsoValues() const{
  return cfa_->photon_chIsoValues();
}

std::vector<float>* const & cfa::photon_nhIsoValues() const{
  return cfa_->photon_nhIsoValues();
}

std::vector<bool>* const & cfa::photon_passElectronVeto() const{
  return cfa_->photon_passElectronVeto();
}

std::vector<float>* const & cfa::photon_phIsoValues() const{
  return cfa_->photon_phIsoValues();
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

std::vector<std::vector<float> >* const & cfa::puJet_rejectionBeta() const{
  return cfa_->puJet_rejectionBeta();
}

std::vector<std::vector<float> >* const & cfa::puJet_rejectionMVA() const{
  return cfa_->puJet_rejectionMVA();
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

Float_t const & cfa::rho_kt6PFJetsForIsolation2011() const{
  return cfa_->rho_kt6PFJetsForIsolation2011();
}

Float_t const & cfa::rho_kt6PFJetsForIsolation2012() const{
  return cfa_->rho_kt6PFJetsForIsolation2012();
}

UInt_t const & cfa::run() const{
  return cfa_->run();
}

Int_t const & cfa::scrapingVeto_decision() const{
  return cfa_->scrapingVeto_decision();
}

Float_t const & cfa::softjetUp_dMEx() const{
  return cfa_->softjetUp_dMEx();
}

Float_t const & cfa::softjetUp_dMEy() const{
  return cfa_->softjetUp_dMEy();
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

std::vector<float>* const & cfa::tcmets_et() const{
  return cfa_->tcmets_et();
}

std::vector<float>* const & cfa::tcmets_ex() const{
  return cfa_->tcmets_ex();
}

std::vector<float>* const & cfa::tcmets_ey() const{
  return cfa_->tcmets_ey();
}

std::vector<float>* const & cfa::tcmets_phi() const{
  return cfa_->tcmets_phi();
}

std::vector<float>* const & cfa::tcmets_sumEt() const{
  return cfa_->tcmets_sumEt();
}

Int_t const & cfa::trackercoherentnoisefilter1_decision() const{
  return cfa_->trackercoherentnoisefilter1_decision();
}

Int_t const & cfa::trackercoherentnoisefilter2_decision() const{
  return cfa_->trackercoherentnoisefilter2_decision();
}

Int_t const & cfa::trackertoomanyclustersfilter_decision() const{
  return cfa_->trackertoomanyclustersfilter_decision();
}

Int_t const & cfa::trackertoomanyseedsfilter_decision() const{
  return cfa_->trackertoomanyseedsfilter_decision();
}

Int_t const & cfa::trackertoomanytripletsfilter_decision() const{
  return cfa_->trackertoomanytripletsfilter_decision();
}

Int_t const & cfa::trackingfailurefilter_decision() const{
  return cfa_->trackingfailurefilter_decision();
}

std::vector<float>* const & cfa::tracks_chg() const{
  return cfa_->tracks_chg();
}

std::vector<float>* const & cfa::tracks_chi2() const{
  return cfa_->tracks_chi2();
}

std::vector<float>* const & cfa::tracks_d0dum() const{
  return cfa_->tracks_d0dum();
}

std::vector<float>* const & cfa::tracks_d0dumErr() const{
  return cfa_->tracks_d0dumErr();
}

std::vector<float>* const & cfa::tracks_dz() const{
  return cfa_->tracks_dz();
}

std::vector<float>* const & cfa::tracks_dzErr() const{
  return cfa_->tracks_dzErr();
}

std::vector<float>* const & cfa::tracks_eta() const{
  return cfa_->tracks_eta();
}

std::vector<float>* const & cfa::tracks_etaErr() const{
  return cfa_->tracks_etaErr();
}

std::vector<float>* const & cfa::tracks_highPurity() const{
  return cfa_->tracks_highPurity();
}

std::vector<float>* const & cfa::tracks_ndof() const{
  return cfa_->tracks_ndof();
}

std::vector<float>* const & cfa::tracks_numlosthits() const{
  return cfa_->tracks_numlosthits();
}

std::vector<float>* const & cfa::tracks_numvalhits() const{
  return cfa_->tracks_numvalhits();
}

std::vector<float>* const & cfa::tracks_phi() const{
  return cfa_->tracks_phi();
}

std::vector<float>* const & cfa::tracks_phiErr() const{
  return cfa_->tracks_phiErr();
}

std::vector<float>* const & cfa::tracks_pt() const{
  return cfa_->tracks_pt();
}

std::vector<float>* const & cfa::tracks_ptErr() const{
  return cfa_->tracks_ptErr();
}

std::vector<float>* const & cfa::tracks_px() const{
  return cfa_->tracks_px();
}

std::vector<float>* const & cfa::tracks_py() const{
  return cfa_->tracks_py();
}

std::vector<float>* const & cfa::tracks_pz() const{
  return cfa_->tracks_pz();
}

std::vector<float>* const & cfa::tracks_vx() const{
  return cfa_->tracks_vx();
}

std::vector<float>* const & cfa::tracks_vy() const{
  return cfa_->tracks_vy();
}

std::vector<float>* const & cfa::tracks_vz() const{
  return cfa_->tracks_vz();
}

std::vector<bool>* const & cfa::trigger_decision() const{
  return cfa_->trigger_decision();
}

std::vector<std::string>* const & cfa::trigger_lastfiltername() const{
  return cfa_->trigger_lastfiltername();
}

std::vector<std::string>* const & cfa::trigger_name() const{
  return cfa_->trigger_name();
}

std::vector<float>* const & cfa::trigger_prescalevalue() const{
  return cfa_->trigger_prescalevalue();
}

std::vector<std::vector<std::string> >* const & cfa::triggerobject_collectionname() const{
  return cfa_->triggerobject_collectionname();
}

std::vector<std::vector<float> >* const & cfa::triggerobject_energy() const{
  return cfa_->triggerobject_energy();
}

std::vector<std::vector<float> >* const & cfa::triggerobject_et() const{
  return cfa_->triggerobject_et();
}

std::vector<std::vector<float> >* const & cfa::triggerobject_eta() const{
  return cfa_->triggerobject_eta();
}

std::vector<std::vector<float> >* const & cfa::triggerobject_phi() const{
  return cfa_->triggerobject_phi();
}

std::vector<std::vector<float> >* const & cfa::triggerobject_pt() const{
  return cfa_->triggerobject_pt();
}

std::vector<std::vector<float> >* const & cfa::triggerobject_px() const{
  return cfa_->triggerobject_px();
}

std::vector<std::vector<float> >* const & cfa::triggerobject_py() const{
  return cfa_->triggerobject_py();
}

std::vector<std::vector<float> >* const & cfa::triggerobject_pz() const{
  return cfa_->triggerobject_pz();
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

Int_t const & cfa::trk_nTOBTEC() const{
  return cfa_->trk_nTOBTEC();
}

Float_t const & cfa::trk_ratioAllTOBTEC() const{
  return cfa_->trk_ratioAllTOBTEC();
}

Float_t const & cfa::trk_ratioJetTOBTEC() const{
  return cfa_->trk_ratioJetTOBTEC();
}

Float_t const & cfa::weight() const{
  return cfa_->weight();
}

std::vector<float>* const & cfa::els_chargedHadronIso() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->pf_els_chargedHadronIso();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->pf_els_chargedHadronIso();
}

std::vector<float>* const & cfa::els_neutralHadronIso() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->pf_els_neutralHadronIso();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->pf_els_neutralHadronIso();
}

std::vector<float>* const & cfa::els_photonIso() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->pf_els_photonIso();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->pf_els_photonIso();
}

std::vector<float>* const & cfa::jets_area() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_area();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_area();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_area();
}

std::vector<float>* const & cfa::jets_btag_TC_highEff() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_btag_TC_highEff();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_btag_TC_highEff();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_btag_TC_highEff();
}

std::vector<float>* const & cfa::jets_btag_TC_highPur() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_btag_TC_highPur();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_btag_TC_highPur();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_btag_TC_highPur();
}

std::vector<float>* const & cfa::jets_btag_jetBProb() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_btag_jetBProb();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_btag_jetBProb();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_btag_jetBProb();
}

std::vector<float>* const & cfa::jets_btag_jetProb() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_btag_jetProb();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_btag_jetProb();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_btag_jetProb();
}

std::vector<float>* const & cfa::jets_btag_secVertexCombined() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_btag_secVertexCombined();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_btag_secVertexCombined();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_btag_secVertexCombined();
}

std::vector<float>* const & cfa::jets_btag_secVertexHighEff() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_btag_secVertexHighEff();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_btag_secVertexHighEff();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_btag_secVertexHighEff();
}

std::vector<float>* const & cfa::jets_btag_secVertexHighPur() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_btag_secVertexHighPur();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_btag_secVertexHighPur();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_btag_secVertexHighPur();
}

std::vector<float>* const & cfa::jets_btag_softEle() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_btag_softEle();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_btag_softEle();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_btag_softEle();
}

std::vector<float>* const & cfa::jets_btag_softMuon() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_btag_softMuon();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_btag_softMuon();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_btag_softMuon();
}

std::vector<float>* const & cfa::jets_chgEmE() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_chgEmE();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_chgEmE();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_chgEmE();
}

std::vector<float>* const & cfa::jets_chgHadE() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_chgHadE();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_chgHadE();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_chgHadE();
}

std::vector<float>* const & cfa::jets_chgMuE() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_chgMuE();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_chgMuE();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_chgMuE();
}

std::vector<float>* const & cfa::jets_chg_Mult() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_chg_Mult();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_chg_Mult();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_chg_Mult();
}

std::vector<float>* const & cfa::jets_corrFactorRaw() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_corrFactorRaw();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_corrFactorRaw();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_corrFactorRaw();
}

std::vector<float>* const & cfa::jets_ehf() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_ehf();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_ehf();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_ehf();
}

std::vector<int>* const & cfa::jets_el_ind() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_el_ind();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK4_el_ind();
}

std::vector<float>* const & cfa::jets_emf() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_emf();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_emf();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_emf();
}

std::vector<float>* const & cfa::jets_energy() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_energy();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_energy();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_energy();
}

std::vector<float>* const & cfa::jets_et() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_et();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_et();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_et();
}

std::vector<float>* const & cfa::jets_eta() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_eta();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_eta();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_eta();
}

std::vector<float>* const & cfa::jets_etaetaMoment() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_etaetaMoment();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_etaetaMoment();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_etaetaMoment();
}

std::vector<float>* const & cfa::jets_etaphiMoment() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_etaphiMoment();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_etaphiMoment();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_etaphiMoment();
}

std::vector<float>* const & cfa::jets_fHPD() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_fHPD();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_fHPD();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_fHPD();
}

std::vector<float>* const & cfa::jets_fRBX() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_fRBX();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_fRBX();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_fRBX();
}

std::vector<float>* const & cfa::jets_fSubDetector1() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_fSubDetector1();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_fSubDetector1();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_fSubDetector1();
}

std::vector<float>* const & cfa::jets_fSubDetector2() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_fSubDetector2();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_fSubDetector2();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_fSubDetector2();
}

std::vector<float>* const & cfa::jets_fSubDetector3() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_fSubDetector3();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_fSubDetector3();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_fSubDetector3();
}

std::vector<float>* const & cfa::jets_fSubDetector4() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_fSubDetector4();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_fSubDetector4();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_fSubDetector4();
}

std::vector<float>* const & cfa::jets_gen_Energy() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_gen_Energy();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_gen_Energy();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_gen_Energy();
}

std::vector<float>* const & cfa::jets_gen_Id() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_gen_Id();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_gen_Id();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_gen_Id();
}

std::vector<float>* const & cfa::jets_gen_et() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_gen_et();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_gen_et();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_gen_et();
}

std::vector<float>* const & cfa::jets_gen_eta() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_gen_eta();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_gen_eta();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_gen_eta();
}

std::vector<float>* const & cfa::jets_gen_mass() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_gen_mass();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_gen_mass();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_gen_mass();
}

std::vector<float>* const & cfa::jets_gen_motherID() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_gen_motherID();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_gen_motherID();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_gen_motherID();
}

std::vector<float>* const & cfa::jets_gen_phi() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_gen_phi();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_gen_phi();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_gen_phi();
}

std::vector<float>* const & cfa::jets_gen_pt() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_gen_pt();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_gen_pt();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_gen_pt();
}

std::vector<float>* const & cfa::jets_gen_threeCharge() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_gen_threeCharge();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_gen_threeCharge();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_gen_threeCharge();
}

std::vector<float>* const & cfa::jets_hitsInN90() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_hitsInN90();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_hitsInN90();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_hitsInN90();
}

std::vector<float>* const & cfa::jets_jetCharge() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_jetCharge();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_jetCharge();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_jetCharge();
}

std::vector<float>* const & cfa::jets_mass() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_mass();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_mass();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_mass();
}

std::vector<int>* const & cfa::jets_maxpt_id() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_maxpt_id();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK4_maxpt_id();
}

std::vector<float>* const & cfa::jets_mu_Mult() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_mu_Mult();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_mu_Mult();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_mu_Mult();
}

std::vector<int>* const & cfa::jets_mu_ind() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_mu_ind();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK4_mu_ind();
}

std::vector<float>* const & cfa::jets_n60() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_n60();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_n60();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_n60();
}

std::vector<float>* const & cfa::jets_n90() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_n90();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_n90();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_n90();
}

std::vector<float>* const & cfa::jets_n90Hits() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_n90Hits();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_n90Hits();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_n90Hits();
}

std::vector<float>* const & cfa::jets_nECALTowers() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_nECALTowers();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_nECALTowers();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_nECALTowers();
}

std::vector<float>* const & cfa::jets_nHCALTowers() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_nHCALTowers();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_nHCALTowers();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_nHCALTowers();
}

std::vector<float>* const & cfa::jets_neutralEmE() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_neutralEmE();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_neutralEmE();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_neutralEmE();
}

std::vector<float>* const & cfa::jets_neutralHadE() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_neutralHadE();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_neutralHadE();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_neutralHadE();
}

std::vector<float>* const & cfa::jets_neutral_Mult() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_neutral_Mult();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_neutral_Mult();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_neutral_Mult();
}

std::vector<float>* const & cfa::jets_partonFlavour() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_partonFlavour();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_partonFlavour();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_partonFlavour();
}

std::vector<float>* const & cfa::jets_parton_Energy() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_parton_Energy();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_parton_Energy();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_parton_Energy();
}

std::vector<float>* const & cfa::jets_parton_Id() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_parton_Id();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_parton_Id();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_parton_Id();
}

std::vector<float>* const & cfa::jets_parton_eta() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_parton_eta();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_parton_eta();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_parton_eta();
}

std::vector<float>* const & cfa::jets_parton_mass() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_parton_mass();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_parton_mass();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_parton_mass();
}

std::vector<float>* const & cfa::jets_parton_motherId() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_parton_motherId();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_parton_motherId();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_parton_motherId();
}

std::vector<float>* const & cfa::jets_parton_phi() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_parton_phi();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_parton_phi();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_parton_phi();
}

std::vector<float>* const & cfa::jets_parton_pt() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_parton_pt();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_parton_pt();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_parton_pt();
}

std::vector<float>* const & cfa::jets_phi() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_phi();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_phi();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_phi();
}

std::vector<float>* const & cfa::jets_phiphiMoment() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_phiphiMoment();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_phiphiMoment();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_phiphiMoment();
}

std::vector<float>* const & cfa::jets_photonEnergy() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_photonEnergy();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_photonEnergy();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_photonEnergy();
}

std::vector<float>* const & cfa::jets_pt() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_pt();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_pt();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_pt();
}

std::vector<float>* const & cfa::jets_px() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_px();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_px();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_px();
}

std::vector<float>* const & cfa::jets_py() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_py();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_py();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_py();
}

std::vector<float>* const & cfa::jets_pz() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_pz();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_pz();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_pz();
}

std::vector<float>* const & cfa::jets_rawPt() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_rawPt();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_rawPt();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_rawPt();
}

std::vector<float>* const & cfa::jets_status() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_status();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_status();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_status();
}

std::vector<float>* const & cfa::jets_theta() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PF_theta();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    return cfa_->jets_AK4_theta();
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PF_theta();
}

std::vector<float>* const & cfa::jetsclean_Uncert() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_Uncert();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_Uncert();
}

std::vector<float>* const & cfa::jetsclean_area() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_area();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_area();
}

std::vector<float>* const & cfa::jetsclean_btag_TC_highEff() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_btag_TC_highEff();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_btag_TC_highEff();
}

std::vector<float>* const & cfa::jetsclean_btag_TC_highPur() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_btag_TC_highPur();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_btag_TC_highPur();
}

std::vector<float>* const & cfa::jetsclean_btag_jetBProb() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_btag_jetBProb();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_btag_jetBProb();
}

std::vector<float>* const & cfa::jetsclean_btag_jetProb() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_btag_jetProb();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_btag_jetProb();
}

std::vector<float>* const & cfa::jetsclean_btag_secVertexCombined() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_btag_secVertexCombined();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_btag_secVertexCombined();
}

std::vector<float>* const & cfa::jetsclean_btag_secVertexHighEff() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_btag_secVertexHighEff();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_btag_secVertexHighEff();
}

std::vector<float>* const & cfa::jetsclean_btag_secVertexHighPur() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_btag_secVertexHighPur();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_btag_secVertexHighPur();
}

std::vector<float>* const & cfa::jetsclean_btag_softEle() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_btag_softEle();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_btag_softEle();
}

std::vector<float>* const & cfa::jetsclean_btag_softMuon() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_btag_softMuon();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_btag_softMuon();
}

std::vector<float>* const & cfa::jetsclean_chgEmE() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_chgEmE();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_chgEmE();
}

std::vector<float>* const & cfa::jetsclean_chgHadE() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_chgHadE();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_chgHadE();
}

std::vector<float>* const & cfa::jetsclean_chgMuE() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_chgMuE();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_chgMuE();
}

std::vector<float>* const & cfa::jetsclean_chg_Mult() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_chg_Mult();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_chg_Mult();
}

std::vector<float>* const & cfa::jetsclean_corrFactorRaw() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_corrFactorRaw();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_corrFactorRaw();
}

std::vector<float>* const & cfa::jetsclean_corrL1FastL2L3() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_corrL1FastL2L3();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_corrL1FastL2L3();
}

std::vector<float>* const & cfa::jetsclean_corrL1FastL2L3Residual() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_corrL1FastL2L3Residual();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_corrL1FastL2L3Residual();
}

std::vector<float>* const & cfa::jetsclean_corrL1L2L3() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_corrL1L2L3();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_corrL1L2L3();
}

std::vector<float>* const & cfa::jetsclean_corrL1L2L3Residual() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_corrL1L2L3Residual();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_corrL1L2L3Residual();
}

std::vector<float>* const & cfa::jetsclean_corrL2L3() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_corrL2L3();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_corrL2L3();
}

std::vector<float>* const & cfa::jetsclean_corrL2L3Residual() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_corrL2L3Residual();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_corrL2L3Residual();
}

std::vector<float>* const & cfa::jetsclean_ehf() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_ehf();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_ehf();
}

std::vector<float>* const & cfa::jetsclean_emf() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_emf();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_emf();
}

std::vector<float>* const & cfa::jetsclean_energy() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_energy();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_energy();
}

std::vector<float>* const & cfa::jetsclean_et() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_et();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_et();
}

std::vector<float>* const & cfa::jetsclean_eta() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_eta();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_eta();
}

std::vector<float>* const & cfa::jetsclean_etaetaMoment() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_etaetaMoment();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_etaetaMoment();
}

std::vector<float>* const & cfa::jetsclean_etaphiMoment() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_etaphiMoment();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_etaphiMoment();
}

std::vector<float>* const & cfa::jetsclean_fHPD() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_fHPD();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_fHPD();
}

std::vector<float>* const & cfa::jetsclean_fRBX() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_fRBX();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_fRBX();
}

std::vector<float>* const & cfa::jetsclean_fSubDetector1() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_fSubDetector1();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_fSubDetector1();
}

std::vector<float>* const & cfa::jetsclean_fSubDetector2() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_fSubDetector2();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_fSubDetector2();
}

std::vector<float>* const & cfa::jetsclean_fSubDetector3() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_fSubDetector3();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_fSubDetector3();
}

std::vector<float>* const & cfa::jetsclean_fSubDetector4() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_fSubDetector4();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_fSubDetector4();
}

std::vector<float>* const & cfa::jetsclean_gen_Energy() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_gen_Energy();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_gen_Energy();
}

std::vector<float>* const & cfa::jetsclean_gen_Id() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_gen_Id();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_gen_Id();
}

std::vector<float>* const & cfa::jetsclean_gen_et() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_gen_et();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_gen_et();
}

std::vector<float>* const & cfa::jetsclean_gen_eta() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_gen_eta();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_gen_eta();
}

std::vector<float>* const & cfa::jetsclean_gen_mass() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_gen_mass();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_gen_mass();
}

std::vector<float>* const & cfa::jetsclean_gen_phi() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_gen_phi();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_gen_phi();
}

std::vector<float>* const & cfa::jetsclean_gen_pt() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_gen_pt();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_gen_pt();
}

std::vector<float>* const & cfa::jetsclean_hitsInN90() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_hitsInN90();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_hitsInN90();
}

std::vector<float>* const & cfa::jetsclean_jetCharge() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_jetCharge();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_jetCharge();
}

std::vector<float>* const & cfa::jetsclean_mass() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_mass();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_mass();
}

std::vector<float>* const & cfa::jetsclean_mu_Mult() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_mu_Mult();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_mu_Mult();
}

std::vector<float>* const & cfa::jetsclean_n60() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_n60();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_n60();
}

std::vector<float>* const & cfa::jetsclean_n90() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_n90();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_n90();
}

std::vector<float>* const & cfa::jetsclean_n90Hits() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_n90Hits();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_n90Hits();
}

std::vector<float>* const & cfa::jetsclean_nECALTowers() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_nECALTowers();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_nECALTowers();
}

std::vector<float>* const & cfa::jetsclean_nHCALTowers() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_nHCALTowers();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_nHCALTowers();
}

std::vector<float>* const & cfa::jetsclean_neutralEmE() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_neutralEmE();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_neutralEmE();
}

std::vector<float>* const & cfa::jetsclean_neutralHadE() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_neutralHadE();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_neutralHadE();
}

std::vector<float>* const & cfa::jetsclean_neutral_Mult() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_neutral_Mult();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_neutral_Mult();
}

std::vector<float>* const & cfa::jetsclean_partonFlavour() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_partonFlavour();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_partonFlavour();
}

std::vector<float>* const & cfa::jetsclean_parton_Energy() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_parton_Energy();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_parton_Energy();
}

std::vector<float>* const & cfa::jetsclean_parton_Id() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_parton_Id();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_parton_Id();
}

std::vector<float>* const & cfa::jetsclean_parton_eta() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_parton_eta();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_parton_eta();
}

std::vector<float>* const & cfa::jetsclean_parton_mass() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_parton_mass();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_parton_mass();
}

std::vector<float>* const & cfa::jetsclean_parton_motherId() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_parton_motherId();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_parton_motherId();
}

std::vector<float>* const & cfa::jetsclean_parton_phi() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_parton_phi();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_parton_phi();
}

std::vector<float>* const & cfa::jetsclean_parton_pt() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_parton_pt();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_parton_pt();
}

std::vector<float>* const & cfa::jetsclean_phi() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_phi();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_phi();
}

std::vector<float>* const & cfa::jetsclean_phiphiMoment() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_phiphiMoment();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_phiphiMoment();
}

std::vector<float>* const & cfa::jetsclean_photonEnergy() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_photonEnergy();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_photonEnergy();
}

std::vector<float>* const & cfa::jetsclean_pt() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_pt();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_pt();
}

std::vector<float>* const & cfa::jetsclean_px() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_px();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_px();
}

std::vector<float>* const & cfa::jetsclean_py() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_py();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_py();
}

std::vector<float>* const & cfa::jetsclean_pz() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_pz();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_pz();
}

std::vector<float>* const & cfa::jetsclean_rawPt() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_rawPt();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_rawPt();
}

std::vector<float>* const & cfa::jetsclean_status() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_status();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_status();
}

std::vector<float>* const & cfa::jetsclean_theta() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->jets_AK5PFclean_theta();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->jets_AK5PFclean_theta();
}

std::vector<float>* const & cfa::mus_chargedHadronIso() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->pf_mus_chargedHadronIso();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->pf_mus_chargedHadronIso();
}

std::vector<float>* const & cfa::mus_neutralHadronIso() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->pf_mus_neutralHadronIso();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->pf_mus_neutralHadronIso();
}

std::vector<float>* const & cfa::mus_photonIso() const{
  if(typeid(*cfa_)==typeid(cfa_8)){
    return cfa_->pf_mus_photonIso();
  }else if(typeid(*cfa_)==typeid(cfa_13)){
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }else{
    throw std::logic_error("Function lookup unknown for class "+std::string(typeid(*cfa_).name()));
  }
  return cfa_->pf_mus_photonIso();
}

