#include "cfa_8.hpp"

#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>

#include "TChain.h"

cfa_8::cfa_8(const std::string &file):
  cfa_base(file),
  L1trigger_alias_(0),
  b_L1trigger_alias_(NULL),
  c_L1trigger_alias_(false),
  L1trigger_bit_(0),
  b_L1trigger_bit_(NULL),
  c_L1trigger_bit_(false),
  L1trigger_decision_(0),
  b_L1trigger_decision_(NULL),
  c_L1trigger_decision_(false),
  L1trigger_decision_nomask_(0),
  b_L1trigger_decision_nomask_(NULL),
  c_L1trigger_decision_nomask_(false),
  L1trigger_name_(0),
  b_L1trigger_name_(NULL),
  c_L1trigger_name_(false),
  L1trigger_prescalevalue_(0),
  b_L1trigger_prescalevalue_(NULL),
  c_L1trigger_prescalevalue_(false),
  L1trigger_techTrigger_(0),
  b_L1trigger_techTrigger_(NULL),
  c_L1trigger_techTrigger_(false),
  MPT_(0),
  b_MPT_(NULL),
  c_MPT_(false),
  Njets_AK5PF_(0),
  b_Njets_AK5PF_(NULL),
  c_Njets_AK5PF_(false),
  Njets_AK5PFclean_(0),
  b_Njets_AK5PFclean_(NULL),
  c_Njets_AK5PFclean_(false),
  Nmc_pdf_(0),
  b_Nmc_pdf_(NULL),
  c_Nmc_pdf_(false),
  NmetsHO_(0),
  b_NmetsHO_(NULL),
  c_NmetsHO_(false),
  Nmets_AK5_(0),
  b_Nmets_AK5_(NULL),
  c_Nmets_AK5_(false),
  NpfTypeINoXYCorrmets_(0),
  b_NpfTypeINoXYCorrmets_(NULL),
  c_NpfTypeINoXYCorrmets_(false),
  NpfTypeIType0mets_(0),
  b_NpfTypeIType0mets_(NULL),
  c_NpfTypeIType0mets_(false),
  NpfTypeImets_(0),
  b_NpfTypeImets_(NULL),
  c_NpfTypeImets_(false),
  Npf_els_(0),
  b_Npf_els_(NULL),
  c_Npf_els_(false),
  Npf_mus_(0),
  b_Npf_mus_(NULL),
  c_Npf_mus_(false),
  Npf_photons_(0),
  b_Npf_photons_(NULL),
  c_Npf_photons_(false),
  Npfmets_(0),
  b_Npfmets_(NULL),
  c_Npfmets_(false),
  Ntcmets_(0),
  b_Ntcmets_(NULL),
  c_Ntcmets_(false),
  Ntracks_(0),
  b_Ntracks_(NULL),
  c_Ntracks_(false),
  ecalBEfilter_decision_(0),
  b_ecalBEfilter_decision_(NULL),
  c_ecalBEfilter_decision_(false),
  ecalTPfilter_decision_(0),
  b_ecalTPfilter_decision_(NULL),
  c_ecalTPfilter_decision_(false),
  eenoisefilter_decision_(0),
  b_eenoisefilter_decision_(NULL),
  c_eenoisefilter_decision_(false),
  els_PFchargedHadronIsoR03_(0),
  b_els_PFchargedHadronIsoR03_(NULL),
  c_els_PFchargedHadronIsoR03_(false),
  els_PFneutralHadronIsoR03_(0),
  b_els_PFneutralHadronIsoR03_(NULL),
  c_els_PFneutralHadronIsoR03_(false),
  els_PFphotonIsoR03_(0),
  b_els_PFphotonIsoR03_(NULL),
  c_els_PFphotonIsoR03_(false),
  els_conversion_dcot_(0),
  b_els_conversion_dcot_(NULL),
  c_els_conversion_dcot_(false),
  els_conversion_dist_(0),
  b_els_conversion_dist_(NULL),
  c_els_conversion_dist_(false),
  els_hasMatchedConversion_(0),
  b_els_hasMatchedConversion_(NULL),
  c_els_hasMatchedConversion_(false),
  genHT_(0),
  b_genHT_(NULL),
  c_genHT_(false),
  greedymuonfilter_decision_(0),
  b_greedymuonfilter_decision_(NULL),
  c_greedymuonfilter_decision_(false),
  hbhefilter_decision_(0),
  b_hbhefilter_decision_(NULL),
  c_hbhefilter_decision_(false),
  inconsistentPFmuonfilter_decision_(0),
  b_inconsistentPFmuonfilter_decision_(NULL),
  c_inconsistentPFmuonfilter_decision_(false),
  isotk_charge_(0),
  b_isotk_charge_(NULL),
  c_isotk_charge_(false),
  isotk_dzpv_(0),
  b_isotk_dzpv_(NULL),
  c_isotk_dzpv_(false),
  isotk_eta_(0),
  b_isotk_eta_(NULL),
  c_isotk_eta_(false),
  isotk_iso_(0),
  b_isotk_iso_(NULL),
  c_isotk_iso_(false),
  isotk_phi_(0),
  b_isotk_phi_(NULL),
  c_isotk_phi_(false),
  isotk_pt_(0),
  b_isotk_pt_(NULL),
  c_isotk_pt_(false),
  jets_AK5PF_area_(0),
  b_jets_AK5PF_area_(NULL),
  c_jets_AK5PF_area_(false),
  jets_AK5PF_btag_TC_highEff_(0),
  b_jets_AK5PF_btag_TC_highEff_(NULL),
  c_jets_AK5PF_btag_TC_highEff_(false),
  jets_AK5PF_btag_TC_highPur_(0),
  b_jets_AK5PF_btag_TC_highPur_(NULL),
  c_jets_AK5PF_btag_TC_highPur_(false),
  jets_AK5PF_btag_jetBProb_(0),
  b_jets_AK5PF_btag_jetBProb_(NULL),
  c_jets_AK5PF_btag_jetBProb_(false),
  jets_AK5PF_btag_jetProb_(0),
  b_jets_AK5PF_btag_jetProb_(NULL),
  c_jets_AK5PF_btag_jetProb_(false),
  jets_AK5PF_btag_secVertexCombined_(0),
  b_jets_AK5PF_btag_secVertexCombined_(NULL),
  c_jets_AK5PF_btag_secVertexCombined_(false),
  jets_AK5PF_btag_secVertexHighEff_(0),
  b_jets_AK5PF_btag_secVertexHighEff_(NULL),
  c_jets_AK5PF_btag_secVertexHighEff_(false),
  jets_AK5PF_btag_secVertexHighPur_(0),
  b_jets_AK5PF_btag_secVertexHighPur_(NULL),
  c_jets_AK5PF_btag_secVertexHighPur_(false),
  jets_AK5PF_btag_softEle_(0),
  b_jets_AK5PF_btag_softEle_(NULL),
  c_jets_AK5PF_btag_softEle_(false),
  jets_AK5PF_btag_softMuon_(0),
  b_jets_AK5PF_btag_softMuon_(NULL),
  c_jets_AK5PF_btag_softMuon_(false),
  jets_AK5PF_chgEmE_(0),
  b_jets_AK5PF_chgEmE_(NULL),
  c_jets_AK5PF_chgEmE_(false),
  jets_AK5PF_chgHadE_(0),
  b_jets_AK5PF_chgHadE_(NULL),
  c_jets_AK5PF_chgHadE_(false),
  jets_AK5PF_chgMuE_(0),
  b_jets_AK5PF_chgMuE_(NULL),
  c_jets_AK5PF_chgMuE_(false),
  jets_AK5PF_chg_Mult_(0),
  b_jets_AK5PF_chg_Mult_(NULL),
  c_jets_AK5PF_chg_Mult_(false),
  jets_AK5PF_corrFactorRaw_(0),
  b_jets_AK5PF_corrFactorRaw_(NULL),
  c_jets_AK5PF_corrFactorRaw_(false),
  jets_AK5PF_ehf_(0),
  b_jets_AK5PF_ehf_(NULL),
  c_jets_AK5PF_ehf_(false),
  jets_AK5PF_emf_(0),
  b_jets_AK5PF_emf_(NULL),
  c_jets_AK5PF_emf_(false),
  jets_AK5PF_energy_(0),
  b_jets_AK5PF_energy_(NULL),
  c_jets_AK5PF_energy_(false),
  jets_AK5PF_et_(0),
  b_jets_AK5PF_et_(NULL),
  c_jets_AK5PF_et_(false),
  jets_AK5PF_eta_(0),
  b_jets_AK5PF_eta_(NULL),
  c_jets_AK5PF_eta_(false),
  jets_AK5PF_etaetaMoment_(0),
  b_jets_AK5PF_etaetaMoment_(NULL),
  c_jets_AK5PF_etaetaMoment_(false),
  jets_AK5PF_etaphiMoment_(0),
  b_jets_AK5PF_etaphiMoment_(NULL),
  c_jets_AK5PF_etaphiMoment_(false),
  jets_AK5PF_fHPD_(0),
  b_jets_AK5PF_fHPD_(NULL),
  c_jets_AK5PF_fHPD_(false),
  jets_AK5PF_fRBX_(0),
  b_jets_AK5PF_fRBX_(NULL),
  c_jets_AK5PF_fRBX_(false),
  jets_AK5PF_fSubDetector1_(0),
  b_jets_AK5PF_fSubDetector1_(NULL),
  c_jets_AK5PF_fSubDetector1_(false),
  jets_AK5PF_fSubDetector2_(0),
  b_jets_AK5PF_fSubDetector2_(NULL),
  c_jets_AK5PF_fSubDetector2_(false),
  jets_AK5PF_fSubDetector3_(0),
  b_jets_AK5PF_fSubDetector3_(NULL),
  c_jets_AK5PF_fSubDetector3_(false),
  jets_AK5PF_fSubDetector4_(0),
  b_jets_AK5PF_fSubDetector4_(NULL),
  c_jets_AK5PF_fSubDetector4_(false),
  jets_AK5PF_gen_Energy_(0),
  b_jets_AK5PF_gen_Energy_(NULL),
  c_jets_AK5PF_gen_Energy_(false),
  jets_AK5PF_gen_Id_(0),
  b_jets_AK5PF_gen_Id_(NULL),
  c_jets_AK5PF_gen_Id_(false),
  jets_AK5PF_gen_et_(0),
  b_jets_AK5PF_gen_et_(NULL),
  c_jets_AK5PF_gen_et_(false),
  jets_AK5PF_gen_eta_(0),
  b_jets_AK5PF_gen_eta_(NULL),
  c_jets_AK5PF_gen_eta_(false),
  jets_AK5PF_gen_mass_(0),
  b_jets_AK5PF_gen_mass_(NULL),
  c_jets_AK5PF_gen_mass_(false),
  jets_AK5PF_gen_motherID_(0),
  b_jets_AK5PF_gen_motherID_(NULL),
  c_jets_AK5PF_gen_motherID_(false),
  jets_AK5PF_gen_phi_(0),
  b_jets_AK5PF_gen_phi_(NULL),
  c_jets_AK5PF_gen_phi_(false),
  jets_AK5PF_gen_pt_(0),
  b_jets_AK5PF_gen_pt_(NULL),
  c_jets_AK5PF_gen_pt_(false),
  jets_AK5PF_gen_threeCharge_(0),
  b_jets_AK5PF_gen_threeCharge_(NULL),
  c_jets_AK5PF_gen_threeCharge_(false),
  jets_AK5PF_hitsInN90_(0),
  b_jets_AK5PF_hitsInN90_(NULL),
  c_jets_AK5PF_hitsInN90_(false),
  jets_AK5PF_jetCharge_(0),
  b_jets_AK5PF_jetCharge_(NULL),
  c_jets_AK5PF_jetCharge_(false),
  jets_AK5PF_mass_(0),
  b_jets_AK5PF_mass_(NULL),
  c_jets_AK5PF_mass_(false),
  jets_AK5PF_mu_Mult_(0),
  b_jets_AK5PF_mu_Mult_(NULL),
  c_jets_AK5PF_mu_Mult_(false),
  jets_AK5PF_n60_(0),
  b_jets_AK5PF_n60_(NULL),
  c_jets_AK5PF_n60_(false),
  jets_AK5PF_n90_(0),
  b_jets_AK5PF_n90_(NULL),
  c_jets_AK5PF_n90_(false),
  jets_AK5PF_n90Hits_(0),
  b_jets_AK5PF_n90Hits_(NULL),
  c_jets_AK5PF_n90Hits_(false),
  jets_AK5PF_nECALTowers_(0),
  b_jets_AK5PF_nECALTowers_(NULL),
  c_jets_AK5PF_nECALTowers_(false),
  jets_AK5PF_nHCALTowers_(0),
  b_jets_AK5PF_nHCALTowers_(NULL),
  c_jets_AK5PF_nHCALTowers_(false),
  jets_AK5PF_neutralEmE_(0),
  b_jets_AK5PF_neutralEmE_(NULL),
  c_jets_AK5PF_neutralEmE_(false),
  jets_AK5PF_neutralHadE_(0),
  b_jets_AK5PF_neutralHadE_(NULL),
  c_jets_AK5PF_neutralHadE_(false),
  jets_AK5PF_neutral_Mult_(0),
  b_jets_AK5PF_neutral_Mult_(NULL),
  c_jets_AK5PF_neutral_Mult_(false),
  jets_AK5PF_partonFlavour_(0),
  b_jets_AK5PF_partonFlavour_(NULL),
  c_jets_AK5PF_partonFlavour_(false),
  jets_AK5PF_parton_Energy_(0),
  b_jets_AK5PF_parton_Energy_(NULL),
  c_jets_AK5PF_parton_Energy_(false),
  jets_AK5PF_parton_Id_(0),
  b_jets_AK5PF_parton_Id_(NULL),
  c_jets_AK5PF_parton_Id_(false),
  jets_AK5PF_parton_eta_(0),
  b_jets_AK5PF_parton_eta_(NULL),
  c_jets_AK5PF_parton_eta_(false),
  jets_AK5PF_parton_mass_(0),
  b_jets_AK5PF_parton_mass_(NULL),
  c_jets_AK5PF_parton_mass_(false),
  jets_AK5PF_parton_motherId_(0),
  b_jets_AK5PF_parton_motherId_(NULL),
  c_jets_AK5PF_parton_motherId_(false),
  jets_AK5PF_parton_phi_(0),
  b_jets_AK5PF_parton_phi_(NULL),
  c_jets_AK5PF_parton_phi_(false),
  jets_AK5PF_parton_pt_(0),
  b_jets_AK5PF_parton_pt_(NULL),
  c_jets_AK5PF_parton_pt_(false),
  jets_AK5PF_phi_(0),
  b_jets_AK5PF_phi_(NULL),
  c_jets_AK5PF_phi_(false),
  jets_AK5PF_phiphiMoment_(0),
  b_jets_AK5PF_phiphiMoment_(NULL),
  c_jets_AK5PF_phiphiMoment_(false),
  jets_AK5PF_photonEnergy_(0),
  b_jets_AK5PF_photonEnergy_(NULL),
  c_jets_AK5PF_photonEnergy_(false),
  jets_AK5PF_pt_(0),
  b_jets_AK5PF_pt_(NULL),
  c_jets_AK5PF_pt_(false),
  jets_AK5PF_px_(0),
  b_jets_AK5PF_px_(NULL),
  c_jets_AK5PF_px_(false),
  jets_AK5PF_py_(0),
  b_jets_AK5PF_py_(NULL),
  c_jets_AK5PF_py_(false),
  jets_AK5PF_pz_(0),
  b_jets_AK5PF_pz_(NULL),
  c_jets_AK5PF_pz_(false),
  jets_AK5PF_rawPt_(0),
  b_jets_AK5PF_rawPt_(NULL),
  c_jets_AK5PF_rawPt_(false),
  jets_AK5PF_status_(0),
  b_jets_AK5PF_status_(NULL),
  c_jets_AK5PF_status_(false),
  jets_AK5PF_theta_(0),
  b_jets_AK5PF_theta_(NULL),
  c_jets_AK5PF_theta_(false),
  jets_AK5PFclean_Uncert_(0),
  b_jets_AK5PFclean_Uncert_(NULL),
  c_jets_AK5PFclean_Uncert_(false),
  jets_AK5PFclean_area_(0),
  b_jets_AK5PFclean_area_(NULL),
  c_jets_AK5PFclean_area_(false),
  jets_AK5PFclean_btag_TC_highEff_(0),
  b_jets_AK5PFclean_btag_TC_highEff_(NULL),
  c_jets_AK5PFclean_btag_TC_highEff_(false),
  jets_AK5PFclean_btag_TC_highPur_(0),
  b_jets_AK5PFclean_btag_TC_highPur_(NULL),
  c_jets_AK5PFclean_btag_TC_highPur_(false),
  jets_AK5PFclean_btag_jetBProb_(0),
  b_jets_AK5PFclean_btag_jetBProb_(NULL),
  c_jets_AK5PFclean_btag_jetBProb_(false),
  jets_AK5PFclean_btag_jetProb_(0),
  b_jets_AK5PFclean_btag_jetProb_(NULL),
  c_jets_AK5PFclean_btag_jetProb_(false),
  jets_AK5PFclean_btag_secVertexCombined_(0),
  b_jets_AK5PFclean_btag_secVertexCombined_(NULL),
  c_jets_AK5PFclean_btag_secVertexCombined_(false),
  jets_AK5PFclean_btag_secVertexHighEff_(0),
  b_jets_AK5PFclean_btag_secVertexHighEff_(NULL),
  c_jets_AK5PFclean_btag_secVertexHighEff_(false),
  jets_AK5PFclean_btag_secVertexHighPur_(0),
  b_jets_AK5PFclean_btag_secVertexHighPur_(NULL),
  c_jets_AK5PFclean_btag_secVertexHighPur_(false),
  jets_AK5PFclean_btag_softEle_(0),
  b_jets_AK5PFclean_btag_softEle_(NULL),
  c_jets_AK5PFclean_btag_softEle_(false),
  jets_AK5PFclean_btag_softMuon_(0),
  b_jets_AK5PFclean_btag_softMuon_(NULL),
  c_jets_AK5PFclean_btag_softMuon_(false),
  jets_AK5PFclean_chgEmE_(0),
  b_jets_AK5PFclean_chgEmE_(NULL),
  c_jets_AK5PFclean_chgEmE_(false),
  jets_AK5PFclean_chgHadE_(0),
  b_jets_AK5PFclean_chgHadE_(NULL),
  c_jets_AK5PFclean_chgHadE_(false),
  jets_AK5PFclean_chgMuE_(0),
  b_jets_AK5PFclean_chgMuE_(NULL),
  c_jets_AK5PFclean_chgMuE_(false),
  jets_AK5PFclean_chg_Mult_(0),
  b_jets_AK5PFclean_chg_Mult_(NULL),
  c_jets_AK5PFclean_chg_Mult_(false),
  jets_AK5PFclean_corrFactorRaw_(0),
  b_jets_AK5PFclean_corrFactorRaw_(NULL),
  c_jets_AK5PFclean_corrFactorRaw_(false),
  jets_AK5PFclean_corrL1FastL2L3_(0),
  b_jets_AK5PFclean_corrL1FastL2L3_(NULL),
  c_jets_AK5PFclean_corrL1FastL2L3_(false),
  jets_AK5PFclean_corrL1FastL2L3Residual_(0),
  b_jets_AK5PFclean_corrL1FastL2L3Residual_(NULL),
  c_jets_AK5PFclean_corrL1FastL2L3Residual_(false),
  jets_AK5PFclean_corrL1L2L3_(0),
  b_jets_AK5PFclean_corrL1L2L3_(NULL),
  c_jets_AK5PFclean_corrL1L2L3_(false),
  jets_AK5PFclean_corrL1L2L3Residual_(0),
  b_jets_AK5PFclean_corrL1L2L3Residual_(NULL),
  c_jets_AK5PFclean_corrL1L2L3Residual_(false),
  jets_AK5PFclean_corrL2L3_(0),
  b_jets_AK5PFclean_corrL2L3_(NULL),
  c_jets_AK5PFclean_corrL2L3_(false),
  jets_AK5PFclean_corrL2L3Residual_(0),
  b_jets_AK5PFclean_corrL2L3Residual_(NULL),
  c_jets_AK5PFclean_corrL2L3Residual_(false),
  jets_AK5PFclean_ehf_(0),
  b_jets_AK5PFclean_ehf_(NULL),
  c_jets_AK5PFclean_ehf_(false),
  jets_AK5PFclean_emf_(0),
  b_jets_AK5PFclean_emf_(NULL),
  c_jets_AK5PFclean_emf_(false),
  jets_AK5PFclean_energy_(0),
  b_jets_AK5PFclean_energy_(NULL),
  c_jets_AK5PFclean_energy_(false),
  jets_AK5PFclean_et_(0),
  b_jets_AK5PFclean_et_(NULL),
  c_jets_AK5PFclean_et_(false),
  jets_AK5PFclean_eta_(0),
  b_jets_AK5PFclean_eta_(NULL),
  c_jets_AK5PFclean_eta_(false),
  jets_AK5PFclean_etaetaMoment_(0),
  b_jets_AK5PFclean_etaetaMoment_(NULL),
  c_jets_AK5PFclean_etaetaMoment_(false),
  jets_AK5PFclean_etaphiMoment_(0),
  b_jets_AK5PFclean_etaphiMoment_(NULL),
  c_jets_AK5PFclean_etaphiMoment_(false),
  jets_AK5PFclean_fHPD_(0),
  b_jets_AK5PFclean_fHPD_(NULL),
  c_jets_AK5PFclean_fHPD_(false),
  jets_AK5PFclean_fRBX_(0),
  b_jets_AK5PFclean_fRBX_(NULL),
  c_jets_AK5PFclean_fRBX_(false),
  jets_AK5PFclean_fSubDetector1_(0),
  b_jets_AK5PFclean_fSubDetector1_(NULL),
  c_jets_AK5PFclean_fSubDetector1_(false),
  jets_AK5PFclean_fSubDetector2_(0),
  b_jets_AK5PFclean_fSubDetector2_(NULL),
  c_jets_AK5PFclean_fSubDetector2_(false),
  jets_AK5PFclean_fSubDetector3_(0),
  b_jets_AK5PFclean_fSubDetector3_(NULL),
  c_jets_AK5PFclean_fSubDetector3_(false),
  jets_AK5PFclean_fSubDetector4_(0),
  b_jets_AK5PFclean_fSubDetector4_(NULL),
  c_jets_AK5PFclean_fSubDetector4_(false),
  jets_AK5PFclean_gen_Energy_(0),
  b_jets_AK5PFclean_gen_Energy_(NULL),
  c_jets_AK5PFclean_gen_Energy_(false),
  jets_AK5PFclean_gen_Id_(0),
  b_jets_AK5PFclean_gen_Id_(NULL),
  c_jets_AK5PFclean_gen_Id_(false),
  jets_AK5PFclean_gen_et_(0),
  b_jets_AK5PFclean_gen_et_(NULL),
  c_jets_AK5PFclean_gen_et_(false),
  jets_AK5PFclean_gen_eta_(0),
  b_jets_AK5PFclean_gen_eta_(NULL),
  c_jets_AK5PFclean_gen_eta_(false),
  jets_AK5PFclean_gen_mass_(0),
  b_jets_AK5PFclean_gen_mass_(NULL),
  c_jets_AK5PFclean_gen_mass_(false),
  jets_AK5PFclean_gen_phi_(0),
  b_jets_AK5PFclean_gen_phi_(NULL),
  c_jets_AK5PFclean_gen_phi_(false),
  jets_AK5PFclean_gen_pt_(0),
  b_jets_AK5PFclean_gen_pt_(NULL),
  c_jets_AK5PFclean_gen_pt_(false),
  jets_AK5PFclean_hitsInN90_(0),
  b_jets_AK5PFclean_hitsInN90_(NULL),
  c_jets_AK5PFclean_hitsInN90_(false),
  jets_AK5PFclean_jetCharge_(0),
  b_jets_AK5PFclean_jetCharge_(NULL),
  c_jets_AK5PFclean_jetCharge_(false),
  jets_AK5PFclean_mass_(0),
  b_jets_AK5PFclean_mass_(NULL),
  c_jets_AK5PFclean_mass_(false),
  jets_AK5PFclean_mu_Mult_(0),
  b_jets_AK5PFclean_mu_Mult_(NULL),
  c_jets_AK5PFclean_mu_Mult_(false),
  jets_AK5PFclean_n60_(0),
  b_jets_AK5PFclean_n60_(NULL),
  c_jets_AK5PFclean_n60_(false),
  jets_AK5PFclean_n90_(0),
  b_jets_AK5PFclean_n90_(NULL),
  c_jets_AK5PFclean_n90_(false),
  jets_AK5PFclean_n90Hits_(0),
  b_jets_AK5PFclean_n90Hits_(NULL),
  c_jets_AK5PFclean_n90Hits_(false),
  jets_AK5PFclean_nECALTowers_(0),
  b_jets_AK5PFclean_nECALTowers_(NULL),
  c_jets_AK5PFclean_nECALTowers_(false),
  jets_AK5PFclean_nHCALTowers_(0),
  b_jets_AK5PFclean_nHCALTowers_(NULL),
  c_jets_AK5PFclean_nHCALTowers_(false),
  jets_AK5PFclean_neutralEmE_(0),
  b_jets_AK5PFclean_neutralEmE_(NULL),
  c_jets_AK5PFclean_neutralEmE_(false),
  jets_AK5PFclean_neutralHadE_(0),
  b_jets_AK5PFclean_neutralHadE_(NULL),
  c_jets_AK5PFclean_neutralHadE_(false),
  jets_AK5PFclean_neutral_Mult_(0),
  b_jets_AK5PFclean_neutral_Mult_(NULL),
  c_jets_AK5PFclean_neutral_Mult_(false),
  jets_AK5PFclean_partonFlavour_(0),
  b_jets_AK5PFclean_partonFlavour_(NULL),
  c_jets_AK5PFclean_partonFlavour_(false),
  jets_AK5PFclean_parton_Energy_(0),
  b_jets_AK5PFclean_parton_Energy_(NULL),
  c_jets_AK5PFclean_parton_Energy_(false),
  jets_AK5PFclean_parton_Id_(0),
  b_jets_AK5PFclean_parton_Id_(NULL),
  c_jets_AK5PFclean_parton_Id_(false),
  jets_AK5PFclean_parton_eta_(0),
  b_jets_AK5PFclean_parton_eta_(NULL),
  c_jets_AK5PFclean_parton_eta_(false),
  jets_AK5PFclean_parton_mass_(0),
  b_jets_AK5PFclean_parton_mass_(NULL),
  c_jets_AK5PFclean_parton_mass_(false),
  jets_AK5PFclean_parton_motherId_(0),
  b_jets_AK5PFclean_parton_motherId_(NULL),
  c_jets_AK5PFclean_parton_motherId_(false),
  jets_AK5PFclean_parton_phi_(0),
  b_jets_AK5PFclean_parton_phi_(NULL),
  c_jets_AK5PFclean_parton_phi_(false),
  jets_AK5PFclean_parton_pt_(0),
  b_jets_AK5PFclean_parton_pt_(NULL),
  c_jets_AK5PFclean_parton_pt_(false),
  jets_AK5PFclean_phi_(0),
  b_jets_AK5PFclean_phi_(NULL),
  c_jets_AK5PFclean_phi_(false),
  jets_AK5PFclean_phiphiMoment_(0),
  b_jets_AK5PFclean_phiphiMoment_(NULL),
  c_jets_AK5PFclean_phiphiMoment_(false),
  jets_AK5PFclean_photonEnergy_(0),
  b_jets_AK5PFclean_photonEnergy_(NULL),
  c_jets_AK5PFclean_photonEnergy_(false),
  jets_AK5PFclean_pt_(0),
  b_jets_AK5PFclean_pt_(NULL),
  c_jets_AK5PFclean_pt_(false),
  jets_AK5PFclean_px_(0),
  b_jets_AK5PFclean_px_(NULL),
  c_jets_AK5PFclean_px_(false),
  jets_AK5PFclean_py_(0),
  b_jets_AK5PFclean_py_(NULL),
  c_jets_AK5PFclean_py_(false),
  jets_AK5PFclean_pz_(0),
  b_jets_AK5PFclean_pz_(NULL),
  c_jets_AK5PFclean_pz_(false),
  jets_AK5PFclean_rawPt_(0),
  b_jets_AK5PFclean_rawPt_(NULL),
  c_jets_AK5PFclean_rawPt_(false),
  jets_AK5PFclean_status_(0),
  b_jets_AK5PFclean_status_(NULL),
  c_jets_AK5PFclean_status_(false),
  jets_AK5PFclean_theta_(0),
  b_jets_AK5PFclean_theta_(NULL),
  c_jets_AK5PFclean_theta_(false),
  mc_pdf_id1_(0),
  b_mc_pdf_id1_(NULL),
  c_mc_pdf_id1_(false),
  mc_pdf_id2_(0),
  b_mc_pdf_id2_(NULL),
  c_mc_pdf_id2_(false),
  mc_pdf_q_(0),
  b_mc_pdf_q_(NULL),
  c_mc_pdf_q_(false),
  mc_pdf_x1_(0),
  b_mc_pdf_x1_(NULL),
  c_mc_pdf_x1_(false),
  mc_pdf_x2_(0),
  b_mc_pdf_x2_(NULL),
  c_mc_pdf_x2_(false),
  metsHO_et_(0),
  b_metsHO_et_(NULL),
  c_metsHO_et_(false),
  metsHO_ex_(0),
  b_metsHO_ex_(NULL),
  c_metsHO_ex_(false),
  metsHO_ey_(0),
  b_metsHO_ey_(NULL),
  c_metsHO_ey_(false),
  metsHO_phi_(0),
  b_metsHO_phi_(NULL),
  c_metsHO_phi_(false),
  metsHO_sumEt_(0),
  b_metsHO_sumEt_(NULL),
  c_metsHO_sumEt_(false),
  mets_AK5_et_(0),
  b_mets_AK5_et_(NULL),
  c_mets_AK5_et_(false),
  mets_AK5_ex_(0),
  b_mets_AK5_ex_(NULL),
  c_mets_AK5_ex_(false),
  mets_AK5_ey_(0),
  b_mets_AK5_ey_(NULL),
  c_mets_AK5_ey_(false),
  mets_AK5_gen_et_(0),
  b_mets_AK5_gen_et_(NULL),
  c_mets_AK5_gen_et_(false),
  mets_AK5_gen_phi_(0),
  b_mets_AK5_gen_phi_(NULL),
  c_mets_AK5_gen_phi_(false),
  mets_AK5_phi_(0),
  b_mets_AK5_phi_(NULL),
  c_mets_AK5_phi_(false),
  mets_AK5_sign_(0),
  b_mets_AK5_sign_(NULL),
  c_mets_AK5_sign_(false),
  mets_AK5_sumEt_(0),
  b_mets_AK5_sumEt_(NULL),
  c_mets_AK5_sumEt_(false),
  mets_AK5_unCPhi_(0),
  b_mets_AK5_unCPhi_(NULL),
  c_mets_AK5_unCPhi_(false),
  mets_AK5_unCPt_(0),
  b_mets_AK5_unCPt_(NULL),
  c_mets_AK5_unCPt_(false),
  passprescaleHT250filter_decision_(0),
  b_passprescaleHT250filter_decision_(NULL),
  c_passprescaleHT250filter_decision_(false),
  passprescaleHT300filter_decision_(0),
  b_passprescaleHT300filter_decision_(NULL),
  c_passprescaleHT300filter_decision_(false),
  passprescaleHT350filter_decision_(0),
  b_passprescaleHT350filter_decision_(NULL),
  c_passprescaleHT350filter_decision_(false),
  passprescaleHT400filter_decision_(0),
  b_passprescaleHT400filter_decision_(NULL),
  c_passprescaleHT400filter_decision_(false),
  passprescaleHT450filter_decision_(0),
  b_passprescaleHT450filter_decision_(NULL),
  c_passprescaleHT450filter_decision_(false),
  passprescaleJet30MET80filter_decision_(0),
  b_passprescaleJet30MET80filter_decision_(NULL),
  c_passprescaleJet30MET80filter_decision_(false),
  passprescalePFHT350filter_decision_(0),
  b_passprescalePFHT350filter_decision_(NULL),
  c_passprescalePFHT350filter_decision_(false),
  pdfweights_cteq_(0),
  b_pdfweights_cteq_(NULL),
  c_pdfweights_cteq_(false),
  pdfweights_mstw_(0),
  b_pdfweights_mstw_(NULL),
  c_pdfweights_mstw_(false),
  pdfweights_nnpdf_(0),
  b_pdfweights_nnpdf_(NULL),
  c_pdfweights_nnpdf_(false),
  pfTypeINoXYCorrmets_et_(0),
  b_pfTypeINoXYCorrmets_et_(NULL),
  c_pfTypeINoXYCorrmets_et_(false),
  pfTypeINoXYCorrmets_ex_(0),
  b_pfTypeINoXYCorrmets_ex_(NULL),
  c_pfTypeINoXYCorrmets_ex_(false),
  pfTypeINoXYCorrmets_ey_(0),
  b_pfTypeINoXYCorrmets_ey_(NULL),
  c_pfTypeINoXYCorrmets_ey_(false),
  pfTypeINoXYCorrmets_gen_et_(0),
  b_pfTypeINoXYCorrmets_gen_et_(NULL),
  c_pfTypeINoXYCorrmets_gen_et_(false),
  pfTypeINoXYCorrmets_gen_phi_(0),
  b_pfTypeINoXYCorrmets_gen_phi_(NULL),
  c_pfTypeINoXYCorrmets_gen_phi_(false),
  pfTypeINoXYCorrmets_phi_(0),
  b_pfTypeINoXYCorrmets_phi_(NULL),
  c_pfTypeINoXYCorrmets_phi_(false),
  pfTypeINoXYCorrmets_sign_(0),
  b_pfTypeINoXYCorrmets_sign_(NULL),
  c_pfTypeINoXYCorrmets_sign_(false),
  pfTypeINoXYCorrmets_sumEt_(0),
  b_pfTypeINoXYCorrmets_sumEt_(NULL),
  c_pfTypeINoXYCorrmets_sumEt_(false),
  pfTypeINoXYCorrmets_unCPhi_(0),
  b_pfTypeINoXYCorrmets_unCPhi_(NULL),
  c_pfTypeINoXYCorrmets_unCPhi_(false),
  pfTypeINoXYCorrmets_unCPt_(0),
  b_pfTypeINoXYCorrmets_unCPt_(NULL),
  c_pfTypeINoXYCorrmets_unCPt_(false),
  pfTypeIType0mets_et_(0),
  b_pfTypeIType0mets_et_(NULL),
  c_pfTypeIType0mets_et_(false),
  pfTypeIType0mets_ex_(0),
  b_pfTypeIType0mets_ex_(NULL),
  c_pfTypeIType0mets_ex_(false),
  pfTypeIType0mets_ey_(0),
  b_pfTypeIType0mets_ey_(NULL),
  c_pfTypeIType0mets_ey_(false),
  pfTypeIType0mets_gen_et_(0),
  b_pfTypeIType0mets_gen_et_(NULL),
  c_pfTypeIType0mets_gen_et_(false),
  pfTypeIType0mets_gen_phi_(0),
  b_pfTypeIType0mets_gen_phi_(NULL),
  c_pfTypeIType0mets_gen_phi_(false),
  pfTypeIType0mets_phi_(0),
  b_pfTypeIType0mets_phi_(NULL),
  c_pfTypeIType0mets_phi_(false),
  pfTypeIType0mets_sign_(0),
  b_pfTypeIType0mets_sign_(NULL),
  c_pfTypeIType0mets_sign_(false),
  pfTypeIType0mets_sumEt_(0),
  b_pfTypeIType0mets_sumEt_(NULL),
  c_pfTypeIType0mets_sumEt_(false),
  pfTypeIType0mets_unCPhi_(0),
  b_pfTypeIType0mets_unCPhi_(NULL),
  c_pfTypeIType0mets_unCPhi_(false),
  pfTypeIType0mets_unCPt_(0),
  b_pfTypeIType0mets_unCPt_(NULL),
  c_pfTypeIType0mets_unCPt_(false),
  pfTypeImets_et_(0),
  b_pfTypeImets_et_(NULL),
  c_pfTypeImets_et_(false),
  pfTypeImets_ex_(0),
  b_pfTypeImets_ex_(NULL),
  c_pfTypeImets_ex_(false),
  pfTypeImets_ey_(0),
  b_pfTypeImets_ey_(NULL),
  c_pfTypeImets_ey_(false),
  pfTypeImets_gen_et_(0),
  b_pfTypeImets_gen_et_(NULL),
  c_pfTypeImets_gen_et_(false),
  pfTypeImets_gen_phi_(0),
  b_pfTypeImets_gen_phi_(NULL),
  c_pfTypeImets_gen_phi_(false),
  pfTypeImets_phi_(0),
  b_pfTypeImets_phi_(NULL),
  c_pfTypeImets_phi_(false),
  pfTypeImets_sign_(0),
  b_pfTypeImets_sign_(NULL),
  c_pfTypeImets_sign_(false),
  pfTypeImets_sumEt_(0),
  b_pfTypeImets_sumEt_(NULL),
  c_pfTypeImets_sumEt_(false),
  pfTypeImets_unCPhi_(0),
  b_pfTypeImets_unCPhi_(NULL),
  c_pfTypeImets_unCPhi_(false),
  pfTypeImets_unCPt_(0),
  b_pfTypeImets_unCPt_(NULL),
  c_pfTypeImets_unCPt_(false),
  pf_els_PATpassConversionVeto_(0),
  b_pf_els_PATpassConversionVeto_(NULL),
  c_pf_els_PATpassConversionVeto_(false),
  pf_els_PFchargedHadronIsoR03_(0),
  b_pf_els_PFchargedHadronIsoR03_(NULL),
  c_pf_els_PFchargedHadronIsoR03_(false),
  pf_els_PFneutralHadronIsoR03_(0),
  b_pf_els_PFneutralHadronIsoR03_(NULL),
  c_pf_els_PFneutralHadronIsoR03_(false),
  pf_els_PFphotonIsoR03_(0),
  b_pf_els_PFphotonIsoR03_(NULL),
  c_pf_els_PFphotonIsoR03_(false),
  pf_els_basicClustersSize_(0),
  b_pf_els_basicClustersSize_(NULL),
  c_pf_els_basicClustersSize_(false),
  pf_els_cIso_(0),
  b_pf_els_cIso_(NULL),
  c_pf_els_cIso_(false),
  pf_els_caloEnergy_(0),
  b_pf_els_caloEnergy_(NULL),
  c_pf_els_caloEnergy_(false),
  pf_els_charge_(0),
  b_pf_els_charge_(NULL),
  c_pf_els_charge_(false),
  pf_els_chargedHadronIso_(0),
  b_pf_els_chargedHadronIso_(NULL),
  c_pf_els_chargedHadronIso_(false),
  pf_els_chi2_(0),
  b_pf_els_chi2_(NULL),
  c_pf_els_chi2_(false),
  pf_els_core_ecalDrivenSeed_(0),
  b_pf_els_core_ecalDrivenSeed_(NULL),
  c_pf_els_core_ecalDrivenSeed_(false),
  pf_els_cpx_(0),
  b_pf_els_cpx_(NULL),
  c_pf_els_cpx_(false),
  pf_els_cpy_(0),
  b_pf_els_cpy_(NULL),
  c_pf_els_cpy_(false),
  pf_els_cpz_(0),
  b_pf_els_cpz_(NULL),
  c_pf_els_cpz_(false),
  pf_els_ctf_tk_charge_(0),
  b_pf_els_ctf_tk_charge_(NULL),
  c_pf_els_ctf_tk_charge_(false),
  pf_els_ctf_tk_eta_(0),
  b_pf_els_ctf_tk_eta_(NULL),
  c_pf_els_ctf_tk_eta_(false),
  pf_els_ctf_tk_id_(0),
  b_pf_els_ctf_tk_id_(NULL),
  c_pf_els_ctf_tk_id_(false),
  pf_els_ctf_tk_phi_(0),
  b_pf_els_ctf_tk_phi_(NULL),
  c_pf_els_ctf_tk_phi_(false),
  pf_els_cx_(0),
  b_pf_els_cx_(NULL),
  c_pf_els_cx_(false),
  pf_els_cy_(0),
  b_pf_els_cy_(NULL),
  c_pf_els_cy_(false),
  pf_els_cz_(0),
  b_pf_els_cz_(NULL),
  c_pf_els_cz_(false),
  pf_els_d0dum_(0),
  b_pf_els_d0dum_(NULL),
  c_pf_els_d0dum_(false),
  pf_els_d0dumError_(0),
  b_pf_els_d0dumError_(NULL),
  c_pf_els_d0dumError_(false),
  pf_els_dEtaIn_(0),
  b_pf_els_dEtaIn_(NULL),
  c_pf_els_dEtaIn_(false),
  pf_els_dEtaOut_(0),
  b_pf_els_dEtaOut_(NULL),
  c_pf_els_dEtaOut_(false),
  pf_els_dPhiIn_(0),
  b_pf_els_dPhiIn_(NULL),
  c_pf_els_dPhiIn_(false),
  pf_els_dPhiOut_(0),
  b_pf_els_dPhiOut_(NULL),
  c_pf_els_dPhiOut_(false),
  pf_els_dr03EcalRecHitSumEt_(0),
  b_pf_els_dr03EcalRecHitSumEt_(NULL),
  c_pf_els_dr03EcalRecHitSumEt_(false),
  pf_els_dr03HcalDepth1TowerSumEt_(0),
  b_pf_els_dr03HcalDepth1TowerSumEt_(NULL),
  c_pf_els_dr03HcalDepth1TowerSumEt_(false),
  pf_els_dr03HcalDepth2TowerSumEt_(0),
  b_pf_els_dr03HcalDepth2TowerSumEt_(NULL),
  c_pf_els_dr03HcalDepth2TowerSumEt_(false),
  pf_els_dr03HcalTowerSumEt_(0),
  b_pf_els_dr03HcalTowerSumEt_(NULL),
  c_pf_els_dr03HcalTowerSumEt_(false),
  pf_els_dr03TkSumPt_(0),
  b_pf_els_dr03TkSumPt_(NULL),
  c_pf_els_dr03TkSumPt_(false),
  pf_els_dr04EcalRecHitSumEt_(0),
  b_pf_els_dr04EcalRecHitSumEt_(NULL),
  c_pf_els_dr04EcalRecHitSumEt_(false),
  pf_els_dr04HcalDepth1TowerSumEt_(0),
  b_pf_els_dr04HcalDepth1TowerSumEt_(NULL),
  c_pf_els_dr04HcalDepth1TowerSumEt_(false),
  pf_els_dr04HcalDepth2TowerSumEt_(0),
  b_pf_els_dr04HcalDepth2TowerSumEt_(NULL),
  c_pf_els_dr04HcalDepth2TowerSumEt_(false),
  pf_els_dr04HcalTowerSumEt_(0),
  b_pf_els_dr04HcalTowerSumEt_(NULL),
  c_pf_els_dr04HcalTowerSumEt_(false),
  pf_els_dr04TkSumPt_(0),
  b_pf_els_dr04TkSumPt_(NULL),
  c_pf_els_dr04TkSumPt_(false),
  pf_els_dz_(0),
  b_pf_els_dz_(NULL),
  c_pf_els_dz_(false),
  pf_els_dzError_(0),
  b_pf_els_dzError_(NULL),
  c_pf_els_dzError_(false),
  pf_els_eOverPIn_(0),
  b_pf_els_eOverPIn_(NULL),
  c_pf_els_eOverPIn_(false),
  pf_els_eSeedOverPOut_(0),
  b_pf_els_eSeedOverPOut_(NULL),
  c_pf_els_eSeedOverPOut_(false),
  pf_els_ecalIso_(0),
  b_pf_els_ecalIso_(NULL),
  c_pf_els_ecalIso_(false),
  pf_els_energy_(0),
  b_pf_els_energy_(NULL),
  c_pf_els_energy_(false),
  pf_els_et_(0),
  b_pf_els_et_(NULL),
  c_pf_els_et_(false),
  pf_els_eta_(0),
  b_pf_els_eta_(NULL),
  c_pf_els_eta_(false),
  pf_els_etaError_(0),
  b_pf_els_etaError_(NULL),
  c_pf_els_etaError_(false),
  pf_els_fbrem_(0),
  b_pf_els_fbrem_(NULL),
  c_pf_els_fbrem_(false),
  pf_els_gen_et_(0),
  b_pf_els_gen_et_(NULL),
  c_pf_els_gen_et_(false),
  pf_els_gen_eta_(0),
  b_pf_els_gen_eta_(NULL),
  c_pf_els_gen_eta_(false),
  pf_els_gen_id_(0),
  b_pf_els_gen_id_(NULL),
  c_pf_els_gen_id_(false),
  pf_els_gen_mother_et_(0),
  b_pf_els_gen_mother_et_(NULL),
  c_pf_els_gen_mother_et_(false),
  pf_els_gen_mother_eta_(0),
  b_pf_els_gen_mother_eta_(NULL),
  c_pf_els_gen_mother_eta_(false),
  pf_els_gen_mother_id_(0),
  b_pf_els_gen_mother_id_(NULL),
  c_pf_els_gen_mother_id_(false),
  pf_els_gen_mother_phi_(0),
  b_pf_els_gen_mother_phi_(NULL),
  c_pf_els_gen_mother_phi_(false),
  pf_els_gen_mother_pt_(0),
  b_pf_els_gen_mother_pt_(NULL),
  c_pf_els_gen_mother_pt_(false),
  pf_els_gen_mother_px_(0),
  b_pf_els_gen_mother_px_(NULL),
  c_pf_els_gen_mother_px_(false),
  pf_els_gen_mother_py_(0),
  b_pf_els_gen_mother_py_(NULL),
  c_pf_els_gen_mother_py_(false),
  pf_els_gen_mother_pz_(0),
  b_pf_els_gen_mother_pz_(NULL),
  c_pf_els_gen_mother_pz_(false),
  pf_els_gen_mother_theta_(0),
  b_pf_els_gen_mother_theta_(NULL),
  c_pf_els_gen_mother_theta_(false),
  pf_els_gen_phi_(0),
  b_pf_els_gen_phi_(NULL),
  c_pf_els_gen_phi_(false),
  pf_els_gen_pt_(0),
  b_pf_els_gen_pt_(NULL),
  c_pf_els_gen_pt_(false),
  pf_els_gen_px_(0),
  b_pf_els_gen_px_(NULL),
  c_pf_els_gen_px_(false),
  pf_els_gen_py_(0),
  b_pf_els_gen_py_(NULL),
  c_pf_els_gen_py_(false),
  pf_els_gen_pz_(0),
  b_pf_els_gen_pz_(NULL),
  c_pf_els_gen_pz_(false),
  pf_els_gen_theta_(0),
  b_pf_els_gen_theta_(NULL),
  c_pf_els_gen_theta_(false),
  pf_els_hadOverEm_(0),
  b_pf_els_hadOverEm_(NULL),
  c_pf_els_hadOverEm_(false),
  pf_els_hasMatchedConversion_(0),
  b_pf_els_hasMatchedConversion_(NULL),
  c_pf_els_hasMatchedConversion_(false),
  pf_els_hcalIso_(0),
  b_pf_els_hcalIso_(NULL),
  c_pf_els_hcalIso_(false),
  pf_els_hcalOverEcalBc_(0),
  b_pf_els_hcalOverEcalBc_(NULL),
  c_pf_els_hcalOverEcalBc_(false),
  pf_els_isEB_(0),
  b_pf_els_isEB_(NULL),
  c_pf_els_isEB_(false),
  pf_els_isEE_(0),
  b_pf_els_isEE_(NULL),
  c_pf_els_isEE_(false),
  pf_els_looseId_(0),
  b_pf_els_looseId_(NULL),
  c_pf_els_looseId_(false),
  pf_els_n_inner_layer_(0),
  b_pf_els_n_inner_layer_(NULL),
  c_pf_els_n_inner_layer_(false),
  pf_els_n_outer_layer_(0),
  b_pf_els_n_outer_layer_(NULL),
  c_pf_els_n_outer_layer_(false),
  pf_els_ndof_(0),
  b_pf_els_ndof_(NULL),
  c_pf_els_ndof_(false),
  pf_els_neutralHadronIso_(0),
  b_pf_els_neutralHadronIso_(NULL),
  c_pf_els_neutralHadronIso_(false),
  pf_els_numlosthits_(0),
  b_pf_els_numlosthits_(NULL),
  c_pf_els_numlosthits_(false),
  pf_els_numvalhits_(0),
  b_pf_els_numvalhits_(NULL),
  c_pf_els_numvalhits_(false),
  pf_els_phi_(0),
  b_pf_els_phi_(NULL),
  c_pf_els_phi_(false),
  pf_els_phiError_(0),
  b_pf_els_phiError_(NULL),
  c_pf_els_phiError_(false),
  pf_els_photonIso_(0),
  b_pf_els_photonIso_(NULL),
  c_pf_els_photonIso_(false),
  pf_els_pt_(0),
  b_pf_els_pt_(NULL),
  c_pf_els_pt_(false),
  pf_els_ptError_(0),
  b_pf_els_ptError_(NULL),
  c_pf_els_ptError_(false),
  pf_els_px_(0),
  b_pf_els_px_(NULL),
  c_pf_els_px_(false),
  pf_els_py_(0),
  b_pf_els_py_(NULL),
  c_pf_els_py_(false),
  pf_els_pz_(0),
  b_pf_els_pz_(NULL),
  c_pf_els_pz_(false),
  pf_els_robustHighEnergyId_(0),
  b_pf_els_robustHighEnergyId_(NULL),
  c_pf_els_robustHighEnergyId_(false),
  pf_els_robustLooseId_(0),
  b_pf_els_robustLooseId_(NULL),
  c_pf_els_robustLooseId_(false),
  pf_els_robustTightId_(0),
  b_pf_els_robustTightId_(NULL),
  c_pf_els_robustTightId_(false),
  pf_els_scE1x5_(0),
  b_pf_els_scE1x5_(NULL),
  c_pf_els_scE1x5_(false),
  pf_els_scE2x5Max_(0),
  b_pf_els_scE2x5Max_(NULL),
  c_pf_els_scE2x5Max_(false),
  pf_els_scE5x5_(0),
  b_pf_els_scE5x5_(NULL),
  c_pf_els_scE5x5_(false),
  pf_els_scEnergy_(0),
  b_pf_els_scEnergy_(NULL),
  c_pf_els_scEnergy_(false),
  pf_els_scEta_(0),
  b_pf_els_scEta_(NULL),
  c_pf_els_scEta_(false),
  pf_els_scEtaWidth_(0),
  b_pf_els_scEtaWidth_(NULL),
  c_pf_els_scEtaWidth_(false),
  pf_els_scPhi_(0),
  b_pf_els_scPhi_(NULL),
  c_pf_els_scPhi_(false),
  pf_els_scPhiWidth_(0),
  b_pf_els_scPhiWidth_(NULL),
  c_pf_els_scPhiWidth_(false),
  pf_els_scRawEnergy_(0),
  b_pf_els_scRawEnergy_(NULL),
  c_pf_els_scRawEnergy_(false),
  pf_els_scSeedEnergy_(0),
  b_pf_els_scSeedEnergy_(NULL),
  c_pf_els_scSeedEnergy_(false),
  pf_els_shFracInnerHits_(0),
  b_pf_els_shFracInnerHits_(NULL),
  c_pf_els_shFracInnerHits_(false),
  pf_els_sigmaEtaEta_(0),
  b_pf_els_sigmaEtaEta_(NULL),
  c_pf_els_sigmaEtaEta_(false),
  pf_els_sigmaIEtaIEta_(0),
  b_pf_els_sigmaIEtaIEta_(NULL),
  c_pf_els_sigmaIEtaIEta_(false),
  pf_els_simpleEleId60cIso_(0),
  b_pf_els_simpleEleId60cIso_(NULL),
  c_pf_els_simpleEleId60cIso_(false),
  pf_els_simpleEleId60relIso_(0),
  b_pf_els_simpleEleId60relIso_(NULL),
  c_pf_els_simpleEleId60relIso_(false),
  pf_els_simpleEleId70cIso_(0),
  b_pf_els_simpleEleId70cIso_(NULL),
  c_pf_els_simpleEleId70cIso_(false),
  pf_els_simpleEleId70relIso_(0),
  b_pf_els_simpleEleId70relIso_(NULL),
  c_pf_els_simpleEleId70relIso_(false),
  pf_els_simpleEleId80cIso_(0),
  b_pf_els_simpleEleId80cIso_(NULL),
  c_pf_els_simpleEleId80cIso_(false),
  pf_els_simpleEleId80relIso_(0),
  b_pf_els_simpleEleId80relIso_(NULL),
  c_pf_els_simpleEleId80relIso_(false),
  pf_els_simpleEleId85cIso_(0),
  b_pf_els_simpleEleId85cIso_(NULL),
  c_pf_els_simpleEleId85cIso_(false),
  pf_els_simpleEleId85relIso_(0),
  b_pf_els_simpleEleId85relIso_(NULL),
  c_pf_els_simpleEleId85relIso_(false),
  pf_els_simpleEleId90cIso_(0),
  b_pf_els_simpleEleId90cIso_(NULL),
  c_pf_els_simpleEleId90cIso_(false),
  pf_els_simpleEleId90relIso_(0),
  b_pf_els_simpleEleId90relIso_(NULL),
  c_pf_els_simpleEleId90relIso_(false),
  pf_els_simpleEleId95cIso_(0),
  b_pf_els_simpleEleId95cIso_(NULL),
  c_pf_els_simpleEleId95cIso_(false),
  pf_els_simpleEleId95relIso_(0),
  b_pf_els_simpleEleId95relIso_(NULL),
  c_pf_els_simpleEleId95relIso_(false),
  pf_els_status_(0),
  b_pf_els_status_(NULL),
  c_pf_els_status_(false),
  pf_els_tIso_(0),
  b_pf_els_tIso_(NULL),
  c_pf_els_tIso_(false),
  pf_els_theta_(0),
  b_pf_els_theta_(NULL),
  c_pf_els_theta_(false),
  pf_els_tightId_(0),
  b_pf_els_tightId_(NULL),
  c_pf_els_tightId_(false),
  pf_els_tk_charge_(0),
  b_pf_els_tk_charge_(NULL),
  c_pf_els_tk_charge_(false),
  pf_els_tk_eta_(0),
  b_pf_els_tk_eta_(NULL),
  c_pf_els_tk_eta_(false),
  pf_els_tk_phi_(0),
  b_pf_els_tk_phi_(NULL),
  c_pf_els_tk_phi_(false),
  pf_els_tk_pt_(0),
  b_pf_els_tk_pt_(NULL),
  c_pf_els_tk_pt_(false),
  pf_els_tk_pz_(0),
  b_pf_els_tk_pz_(NULL),
  c_pf_els_tk_pz_(false),
  pf_els_vpx_(0),
  b_pf_els_vpx_(NULL),
  c_pf_els_vpx_(false),
  pf_els_vpy_(0),
  b_pf_els_vpy_(NULL),
  c_pf_els_vpy_(false),
  pf_els_vpz_(0),
  b_pf_els_vpz_(NULL),
  c_pf_els_vpz_(false),
  pf_els_vx_(0),
  b_pf_els_vx_(NULL),
  c_pf_els_vx_(false),
  pf_els_vy_(0),
  b_pf_els_vy_(NULL),
  c_pf_els_vy_(false),
  pf_els_vz_(0),
  b_pf_els_vz_(NULL),
  c_pf_els_vz_(false),
  pf_mus_cIso_(0),
  b_pf_mus_cIso_(NULL),
  c_pf_mus_cIso_(false),
  pf_mus_calEnergyEm_(0),
  b_pf_mus_calEnergyEm_(NULL),
  c_pf_mus_calEnergyEm_(false),
  pf_mus_calEnergyEmS9_(0),
  b_pf_mus_calEnergyEmS9_(NULL),
  c_pf_mus_calEnergyEmS9_(false),
  pf_mus_calEnergyHad_(0),
  b_pf_mus_calEnergyHad_(NULL),
  c_pf_mus_calEnergyHad_(false),
  pf_mus_calEnergyHadS9_(0),
  b_pf_mus_calEnergyHadS9_(NULL),
  c_pf_mus_calEnergyHadS9_(false),
  pf_mus_calEnergyHo_(0),
  b_pf_mus_calEnergyHo_(NULL),
  c_pf_mus_calEnergyHo_(false),
  pf_mus_calEnergyHoS9_(0),
  b_pf_mus_calEnergyHoS9_(NULL),
  c_pf_mus_calEnergyHoS9_(false),
  pf_mus_charge_(0),
  b_pf_mus_charge_(NULL),
  c_pf_mus_charge_(false),
  pf_mus_chargedHadronIso_(0),
  b_pf_mus_chargedHadronIso_(NULL),
  c_pf_mus_chargedHadronIso_(false),
  pf_mus_cm_ExpectedHitsInner_(0),
  b_pf_mus_cm_ExpectedHitsInner_(NULL),
  c_pf_mus_cm_ExpectedHitsInner_(false),
  pf_mus_cm_ExpectedHitsOuter_(0),
  b_pf_mus_cm_ExpectedHitsOuter_(NULL),
  c_pf_mus_cm_ExpectedHitsOuter_(false),
  pf_mus_cm_LayersWithMeasurement_(0),
  b_pf_mus_cm_LayersWithMeasurement_(NULL),
  c_pf_mus_cm_LayersWithMeasurement_(false),
  pf_mus_cm_LayersWithoutMeasurement_(0),
  b_pf_mus_cm_LayersWithoutMeasurement_(NULL),
  c_pf_mus_cm_LayersWithoutMeasurement_(false),
  pf_mus_cm_PixelLayersWithMeasurement_(0),
  b_pf_mus_cm_PixelLayersWithMeasurement_(NULL),
  c_pf_mus_cm_PixelLayersWithMeasurement_(false),
  pf_mus_cm_ValidStripLayersWithMonoAndStereoHit_(0),
  b_pf_mus_cm_ValidStripLayersWithMonoAndStereoHit_(NULL),
  c_pf_mus_cm_ValidStripLayersWithMonoAndStereoHit_(false),
  pf_mus_cm_chg_(0),
  b_pf_mus_cm_chg_(NULL),
  c_pf_mus_cm_chg_(false),
  pf_mus_cm_chi2_(0),
  b_pf_mus_cm_chi2_(NULL),
  c_pf_mus_cm_chi2_(false),
  pf_mus_cm_d0dum_(0),
  b_pf_mus_cm_d0dum_(NULL),
  c_pf_mus_cm_d0dum_(false),
  pf_mus_cm_d0dumErr_(0),
  b_pf_mus_cm_d0dumErr_(NULL),
  c_pf_mus_cm_d0dumErr_(false),
  pf_mus_cm_dz_(0),
  b_pf_mus_cm_dz_(NULL),
  c_pf_mus_cm_dz_(false),
  pf_mus_cm_dzErr_(0),
  b_pf_mus_cm_dzErr_(NULL),
  c_pf_mus_cm_dzErr_(false),
  pf_mus_cm_eta_(0),
  b_pf_mus_cm_eta_(NULL),
  c_pf_mus_cm_eta_(false),
  pf_mus_cm_etaErr_(0),
  b_pf_mus_cm_etaErr_(NULL),
  c_pf_mus_cm_etaErr_(false),
  pf_mus_cm_ndof_(0),
  b_pf_mus_cm_ndof_(NULL),
  c_pf_mus_cm_ndof_(false),
  pf_mus_cm_numlosthits_(0),
  b_pf_mus_cm_numlosthits_(NULL),
  c_pf_mus_cm_numlosthits_(false),
  pf_mus_cm_numvalMuonhits_(0),
  b_pf_mus_cm_numvalMuonhits_(NULL),
  c_pf_mus_cm_numvalMuonhits_(false),
  pf_mus_cm_numvalhits_(0),
  b_pf_mus_cm_numvalhits_(NULL),
  c_pf_mus_cm_numvalhits_(false),
  pf_mus_cm_phi_(0),
  b_pf_mus_cm_phi_(NULL),
  c_pf_mus_cm_phi_(false),
  pf_mus_cm_phiErr_(0),
  b_pf_mus_cm_phiErr_(NULL),
  c_pf_mus_cm_phiErr_(false),
  pf_mus_cm_pt_(0),
  b_pf_mus_cm_pt_(NULL),
  c_pf_mus_cm_pt_(false),
  pf_mus_cm_ptErr_(0),
  b_pf_mus_cm_ptErr_(NULL),
  c_pf_mus_cm_ptErr_(false),
  pf_mus_cm_px_(0),
  b_pf_mus_cm_px_(NULL),
  c_pf_mus_cm_px_(false),
  pf_mus_cm_py_(0),
  b_pf_mus_cm_py_(NULL),
  c_pf_mus_cm_py_(false),
  pf_mus_cm_pz_(0),
  b_pf_mus_cm_pz_(NULL),
  c_pf_mus_cm_pz_(false),
  pf_mus_cm_theta_(0),
  b_pf_mus_cm_theta_(NULL),
  c_pf_mus_cm_theta_(false),
  pf_mus_cm_vx_(0),
  b_pf_mus_cm_vx_(NULL),
  c_pf_mus_cm_vx_(false),
  pf_mus_cm_vy_(0),
  b_pf_mus_cm_vy_(NULL),
  c_pf_mus_cm_vy_(false),
  pf_mus_cm_vz_(0),
  b_pf_mus_cm_vz_(NULL),
  c_pf_mus_cm_vz_(false),
  pf_mus_dB_(0),
  b_pf_mus_dB_(NULL),
  c_pf_mus_dB_(false),
  pf_mus_ecalIso_(0),
  b_pf_mus_ecalIso_(NULL),
  c_pf_mus_ecalIso_(false),
  pf_mus_energy_(0),
  b_pf_mus_energy_(NULL),
  c_pf_mus_energy_(false),
  pf_mus_et_(0),
  b_pf_mus_et_(NULL),
  c_pf_mus_et_(false),
  pf_mus_eta_(0),
  b_pf_mus_eta_(NULL),
  c_pf_mus_eta_(false),
  pf_mus_gen_et_(0),
  b_pf_mus_gen_et_(NULL),
  c_pf_mus_gen_et_(false),
  pf_mus_gen_eta_(0),
  b_pf_mus_gen_eta_(NULL),
  c_pf_mus_gen_eta_(false),
  pf_mus_gen_id_(0),
  b_pf_mus_gen_id_(NULL),
  c_pf_mus_gen_id_(false),
  pf_mus_gen_mother_et_(0),
  b_pf_mus_gen_mother_et_(NULL),
  c_pf_mus_gen_mother_et_(false),
  pf_mus_gen_mother_eta_(0),
  b_pf_mus_gen_mother_eta_(NULL),
  c_pf_mus_gen_mother_eta_(false),
  pf_mus_gen_mother_id_(0),
  b_pf_mus_gen_mother_id_(NULL),
  c_pf_mus_gen_mother_id_(false),
  pf_mus_gen_mother_phi_(0),
  b_pf_mus_gen_mother_phi_(NULL),
  c_pf_mus_gen_mother_phi_(false),
  pf_mus_gen_mother_pt_(0),
  b_pf_mus_gen_mother_pt_(NULL),
  c_pf_mus_gen_mother_pt_(false),
  pf_mus_gen_mother_px_(0),
  b_pf_mus_gen_mother_px_(NULL),
  c_pf_mus_gen_mother_px_(false),
  pf_mus_gen_mother_py_(0),
  b_pf_mus_gen_mother_py_(NULL),
  c_pf_mus_gen_mother_py_(false),
  pf_mus_gen_mother_pz_(0),
  b_pf_mus_gen_mother_pz_(NULL),
  c_pf_mus_gen_mother_pz_(false),
  pf_mus_gen_mother_theta_(0),
  b_pf_mus_gen_mother_theta_(NULL),
  c_pf_mus_gen_mother_theta_(false),
  pf_mus_gen_phi_(0),
  b_pf_mus_gen_phi_(NULL),
  c_pf_mus_gen_phi_(false),
  pf_mus_gen_pt_(0),
  b_pf_mus_gen_pt_(NULL),
  c_pf_mus_gen_pt_(false),
  pf_mus_gen_px_(0),
  b_pf_mus_gen_px_(NULL),
  c_pf_mus_gen_px_(false),
  pf_mus_gen_py_(0),
  b_pf_mus_gen_py_(NULL),
  c_pf_mus_gen_py_(false),
  pf_mus_gen_pz_(0),
  b_pf_mus_gen_pz_(NULL),
  c_pf_mus_gen_pz_(false),
  pf_mus_gen_theta_(0),
  b_pf_mus_gen_theta_(NULL),
  c_pf_mus_gen_theta_(false),
  pf_mus_hcalIso_(0),
  b_pf_mus_hcalIso_(NULL),
  c_pf_mus_hcalIso_(false),
  pf_mus_id_All_(0),
  b_pf_mus_id_All_(NULL),
  c_pf_mus_id_All_(false),
  pf_mus_id_AllArbitrated_(0),
  b_pf_mus_id_AllArbitrated_(NULL),
  c_pf_mus_id_AllArbitrated_(false),
  pf_mus_id_AllGlobalMuons_(0),
  b_pf_mus_id_AllGlobalMuons_(NULL),
  c_pf_mus_id_AllGlobalMuons_(false),
  pf_mus_id_AllStandAloneMuons_(0),
  b_pf_mus_id_AllStandAloneMuons_(NULL),
  c_pf_mus_id_AllStandAloneMuons_(false),
  pf_mus_id_AllTrackerMuons_(0),
  b_pf_mus_id_AllTrackerMuons_(NULL),
  c_pf_mus_id_AllTrackerMuons_(false),
  pf_mus_id_GlobalMuonPromptTight_(0),
  b_pf_mus_id_GlobalMuonPromptTight_(NULL),
  c_pf_mus_id_GlobalMuonPromptTight_(false),
  pf_mus_id_TM2DCompatibilityLoose_(0),
  b_pf_mus_id_TM2DCompatibilityLoose_(NULL),
  c_pf_mus_id_TM2DCompatibilityLoose_(false),
  pf_mus_id_TM2DCompatibilityTight_(0),
  b_pf_mus_id_TM2DCompatibilityTight_(NULL),
  c_pf_mus_id_TM2DCompatibilityTight_(false),
  pf_mus_id_TMLastStationLoose_(0),
  b_pf_mus_id_TMLastStationLoose_(NULL),
  c_pf_mus_id_TMLastStationLoose_(false),
  pf_mus_id_TMLastStationOptimizedLowPtLoose_(0),
  b_pf_mus_id_TMLastStationOptimizedLowPtLoose_(NULL),
  c_pf_mus_id_TMLastStationOptimizedLowPtLoose_(false),
  pf_mus_id_TMLastStationOptimizedLowPtTight_(0),
  b_pf_mus_id_TMLastStationOptimizedLowPtTight_(NULL),
  c_pf_mus_id_TMLastStationOptimizedLowPtTight_(false),
  pf_mus_id_TMLastStationTight_(0),
  b_pf_mus_id_TMLastStationTight_(NULL),
  c_pf_mus_id_TMLastStationTight_(false),
  pf_mus_id_TMOneStationLoose_(0),
  b_pf_mus_id_TMOneStationLoose_(NULL),
  c_pf_mus_id_TMOneStationLoose_(false),
  pf_mus_id_TMOneStationTight_(0),
  b_pf_mus_id_TMOneStationTight_(NULL),
  c_pf_mus_id_TMOneStationTight_(false),
  pf_mus_id_TrackerMuonArbitrated_(0),
  b_pf_mus_id_TrackerMuonArbitrated_(NULL),
  c_pf_mus_id_TrackerMuonArbitrated_(false),
  pf_mus_isCaloMuon_(0),
  b_pf_mus_isCaloMuon_(NULL),
  c_pf_mus_isCaloMuon_(false),
  pf_mus_isConvertedPhoton_(0),
  b_pf_mus_isConvertedPhoton_(NULL),
  c_pf_mus_isConvertedPhoton_(false),
  pf_mus_isElectron_(0),
  b_pf_mus_isElectron_(NULL),
  c_pf_mus_isElectron_(false),
  pf_mus_isGlobalMuon_(0),
  b_pf_mus_isGlobalMuon_(NULL),
  c_pf_mus_isGlobalMuon_(false),
  pf_mus_isPFMuon_(0),
  b_pf_mus_isPFMuon_(NULL),
  c_pf_mus_isPFMuon_(false),
  pf_mus_isPhoton_(0),
  b_pf_mus_isPhoton_(NULL),
  c_pf_mus_isPhoton_(false),
  pf_mus_isStandAloneMuon_(0),
  b_pf_mus_isStandAloneMuon_(NULL),
  c_pf_mus_isStandAloneMuon_(false),
  pf_mus_isTrackerMuon_(0),
  b_pf_mus_isTrackerMuon_(NULL),
  c_pf_mus_isTrackerMuon_(false),
  pf_mus_iso03_emEt_(0),
  b_pf_mus_iso03_emEt_(NULL),
  c_pf_mus_iso03_emEt_(false),
  pf_mus_iso03_emVetoEt_(0),
  b_pf_mus_iso03_emVetoEt_(NULL),
  c_pf_mus_iso03_emVetoEt_(false),
  pf_mus_iso03_hadEt_(0),
  b_pf_mus_iso03_hadEt_(NULL),
  c_pf_mus_iso03_hadEt_(false),
  pf_mus_iso03_hadVetoEt_(0),
  b_pf_mus_iso03_hadVetoEt_(NULL),
  c_pf_mus_iso03_hadVetoEt_(false),
  pf_mus_iso03_hoEt_(0),
  b_pf_mus_iso03_hoEt_(NULL),
  c_pf_mus_iso03_hoEt_(false),
  pf_mus_iso03_nTracks_(0),
  b_pf_mus_iso03_nTracks_(NULL),
  c_pf_mus_iso03_nTracks_(false),
  pf_mus_iso03_sumPt_(0),
  b_pf_mus_iso03_sumPt_(NULL),
  c_pf_mus_iso03_sumPt_(false),
  pf_mus_iso05_emEt_(0),
  b_pf_mus_iso05_emEt_(NULL),
  c_pf_mus_iso05_emEt_(false),
  pf_mus_iso05_hadEt_(0),
  b_pf_mus_iso05_hadEt_(NULL),
  c_pf_mus_iso05_hadEt_(false),
  pf_mus_iso05_hoEt_(0),
  b_pf_mus_iso05_hoEt_(NULL),
  c_pf_mus_iso05_hoEt_(false),
  pf_mus_iso05_nTracks_(0),
  b_pf_mus_iso05_nTracks_(NULL),
  c_pf_mus_iso05_nTracks_(false),
  pf_mus_iso05_sumPt_(0),
  b_pf_mus_iso05_sumPt_(NULL),
  c_pf_mus_iso05_sumPt_(false),
  pf_mus_neutralHadronIso_(0),
  b_pf_mus_neutralHadronIso_(NULL),
  c_pf_mus_neutralHadronIso_(false),
  pf_mus_num_matches_(0),
  b_pf_mus_num_matches_(NULL),
  c_pf_mus_num_matches_(false),
  pf_mus_numberOfMatchedStations_(0),
  b_pf_mus_numberOfMatchedStations_(NULL),
  c_pf_mus_numberOfMatchedStations_(false),
  pf_mus_pfIsolationR03_sumChargedHadronPt_(0),
  b_pf_mus_pfIsolationR03_sumChargedHadronPt_(NULL),
  c_pf_mus_pfIsolationR03_sumChargedHadronPt_(false),
  pf_mus_pfIsolationR03_sumChargedParticlePt_(0),
  b_pf_mus_pfIsolationR03_sumChargedParticlePt_(NULL),
  c_pf_mus_pfIsolationR03_sumChargedParticlePt_(false),
  pf_mus_pfIsolationR03_sumNeutralHadronEt_(0),
  b_pf_mus_pfIsolationR03_sumNeutralHadronEt_(NULL),
  c_pf_mus_pfIsolationR03_sumNeutralHadronEt_(false),
  pf_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_(0),
  b_pf_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_(NULL),
  c_pf_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_(false),
  pf_mus_pfIsolationR03_sumPUPt_(0),
  b_pf_mus_pfIsolationR03_sumPUPt_(NULL),
  c_pf_mus_pfIsolationR03_sumPUPt_(false),
  pf_mus_pfIsolationR03_sumPhotonEt_(0),
  b_pf_mus_pfIsolationR03_sumPhotonEt_(NULL),
  c_pf_mus_pfIsolationR03_sumPhotonEt_(false),
  pf_mus_pfIsolationR03_sumPhotonEtHighThreshold_(0),
  b_pf_mus_pfIsolationR03_sumPhotonEtHighThreshold_(NULL),
  c_pf_mus_pfIsolationR03_sumPhotonEtHighThreshold_(false),
  pf_mus_pfIsolationR04_sumChargedHadronPt_(0),
  b_pf_mus_pfIsolationR04_sumChargedHadronPt_(NULL),
  c_pf_mus_pfIsolationR04_sumChargedHadronPt_(false),
  pf_mus_pfIsolationR04_sumChargedParticlePt_(0),
  b_pf_mus_pfIsolationR04_sumChargedParticlePt_(NULL),
  c_pf_mus_pfIsolationR04_sumChargedParticlePt_(false),
  pf_mus_pfIsolationR04_sumNeutralHadronEt_(0),
  b_pf_mus_pfIsolationR04_sumNeutralHadronEt_(NULL),
  c_pf_mus_pfIsolationR04_sumNeutralHadronEt_(false),
  pf_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_(0),
  b_pf_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_(NULL),
  c_pf_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_(false),
  pf_mus_pfIsolationR04_sumPUPt_(0),
  b_pf_mus_pfIsolationR04_sumPUPt_(NULL),
  c_pf_mus_pfIsolationR04_sumPUPt_(false),
  pf_mus_pfIsolationR04_sumPhotonEt_(0),
  b_pf_mus_pfIsolationR04_sumPhotonEt_(NULL),
  c_pf_mus_pfIsolationR04_sumPhotonEt_(false),
  pf_mus_pfIsolationR04_sumPhotonEtHighThreshold_(0),
  b_pf_mus_pfIsolationR04_sumPhotonEtHighThreshold_(NULL),
  c_pf_mus_pfIsolationR04_sumPhotonEtHighThreshold_(false),
  pf_mus_phi_(0),
  b_pf_mus_phi_(NULL),
  c_pf_mus_phi_(false),
  pf_mus_photonIso_(0),
  b_pf_mus_photonIso_(NULL),
  c_pf_mus_photonIso_(false),
  pf_mus_picky_ExpectedHitsInner_(0),
  b_pf_mus_picky_ExpectedHitsInner_(NULL),
  c_pf_mus_picky_ExpectedHitsInner_(false),
  pf_mus_picky_ExpectedHitsOuter_(0),
  b_pf_mus_picky_ExpectedHitsOuter_(NULL),
  c_pf_mus_picky_ExpectedHitsOuter_(false),
  pf_mus_picky_LayersWithMeasurement_(0),
  b_pf_mus_picky_LayersWithMeasurement_(NULL),
  c_pf_mus_picky_LayersWithMeasurement_(false),
  pf_mus_picky_LayersWithoutMeasurement_(0),
  b_pf_mus_picky_LayersWithoutMeasurement_(NULL),
  c_pf_mus_picky_LayersWithoutMeasurement_(false),
  pf_mus_picky_PixelLayersWithMeasurement_(0),
  b_pf_mus_picky_PixelLayersWithMeasurement_(NULL),
  c_pf_mus_picky_PixelLayersWithMeasurement_(false),
  pf_mus_picky_ValidStripLayersWithMonoAndStereoHit_(0),
  b_pf_mus_picky_ValidStripLayersWithMonoAndStereoHit_(NULL),
  c_pf_mus_picky_ValidStripLayersWithMonoAndStereoHit_(false),
  pf_mus_picky_chg_(0),
  b_pf_mus_picky_chg_(NULL),
  c_pf_mus_picky_chg_(false),
  pf_mus_picky_chi2_(0),
  b_pf_mus_picky_chi2_(NULL),
  c_pf_mus_picky_chi2_(false),
  pf_mus_picky_d0dum_(0),
  b_pf_mus_picky_d0dum_(NULL),
  c_pf_mus_picky_d0dum_(false),
  pf_mus_picky_d0dumErr_(0),
  b_pf_mus_picky_d0dumErr_(NULL),
  c_pf_mus_picky_d0dumErr_(false),
  pf_mus_picky_dz_(0),
  b_pf_mus_picky_dz_(NULL),
  c_pf_mus_picky_dz_(false),
  pf_mus_picky_dzErr_(0),
  b_pf_mus_picky_dzErr_(NULL),
  c_pf_mus_picky_dzErr_(false),
  pf_mus_picky_eta_(0),
  b_pf_mus_picky_eta_(NULL),
  c_pf_mus_picky_eta_(false),
  pf_mus_picky_etaErr_(0),
  b_pf_mus_picky_etaErr_(NULL),
  c_pf_mus_picky_etaErr_(false),
  pf_mus_picky_id_(0),
  b_pf_mus_picky_id_(NULL),
  c_pf_mus_picky_id_(false),
  pf_mus_picky_ndof_(0),
  b_pf_mus_picky_ndof_(NULL),
  c_pf_mus_picky_ndof_(false),
  pf_mus_picky_numlosthits_(0),
  b_pf_mus_picky_numlosthits_(NULL),
  c_pf_mus_picky_numlosthits_(false),
  pf_mus_picky_numvalPixelhits_(0),
  b_pf_mus_picky_numvalPixelhits_(NULL),
  c_pf_mus_picky_numvalPixelhits_(false),
  pf_mus_picky_numvalhits_(0),
  b_pf_mus_picky_numvalhits_(NULL),
  c_pf_mus_picky_numvalhits_(false),
  pf_mus_picky_phi_(0),
  b_pf_mus_picky_phi_(NULL),
  c_pf_mus_picky_phi_(false),
  pf_mus_picky_phiErr_(0),
  b_pf_mus_picky_phiErr_(NULL),
  c_pf_mus_picky_phiErr_(false),
  pf_mus_picky_pt_(0),
  b_pf_mus_picky_pt_(NULL),
  c_pf_mus_picky_pt_(false),
  pf_mus_picky_ptErr_(0),
  b_pf_mus_picky_ptErr_(NULL),
  c_pf_mus_picky_ptErr_(false),
  pf_mus_picky_px_(0),
  b_pf_mus_picky_px_(NULL),
  c_pf_mus_picky_px_(false),
  pf_mus_picky_py_(0),
  b_pf_mus_picky_py_(NULL),
  c_pf_mus_picky_py_(false),
  pf_mus_picky_pz_(0),
  b_pf_mus_picky_pz_(NULL),
  c_pf_mus_picky_pz_(false),
  pf_mus_picky_theta_(0),
  b_pf_mus_picky_theta_(NULL),
  c_pf_mus_picky_theta_(false),
  pf_mus_picky_vx_(0),
  b_pf_mus_picky_vx_(NULL),
  c_pf_mus_picky_vx_(false),
  pf_mus_picky_vy_(0),
  b_pf_mus_picky_vy_(NULL),
  c_pf_mus_picky_vy_(false),
  pf_mus_picky_vz_(0),
  b_pf_mus_picky_vz_(NULL),
  c_pf_mus_picky_vz_(false),
  pf_mus_pt_(0),
  b_pf_mus_pt_(NULL),
  c_pf_mus_pt_(false),
  pf_mus_px_(0),
  b_pf_mus_px_(NULL),
  c_pf_mus_px_(false),
  pf_mus_py_(0),
  b_pf_mus_py_(NULL),
  c_pf_mus_py_(false),
  pf_mus_pz_(0),
  b_pf_mus_pz_(NULL),
  c_pf_mus_pz_(false),
  pf_mus_stamu_chg_(0),
  b_pf_mus_stamu_chg_(NULL),
  c_pf_mus_stamu_chg_(false),
  pf_mus_stamu_chi2_(0),
  b_pf_mus_stamu_chi2_(NULL),
  c_pf_mus_stamu_chi2_(false),
  pf_mus_stamu_d0dum_(0),
  b_pf_mus_stamu_d0dum_(NULL),
  c_pf_mus_stamu_d0dum_(false),
  pf_mus_stamu_d0dumErr_(0),
  b_pf_mus_stamu_d0dumErr_(NULL),
  c_pf_mus_stamu_d0dumErr_(false),
  pf_mus_stamu_dz_(0),
  b_pf_mus_stamu_dz_(NULL),
  c_pf_mus_stamu_dz_(false),
  pf_mus_stamu_dzErr_(0),
  b_pf_mus_stamu_dzErr_(NULL),
  c_pf_mus_stamu_dzErr_(false),
  pf_mus_stamu_eta_(0),
  b_pf_mus_stamu_eta_(NULL),
  c_pf_mus_stamu_eta_(false),
  pf_mus_stamu_etaErr_(0),
  b_pf_mus_stamu_etaErr_(NULL),
  c_pf_mus_stamu_etaErr_(false),
  pf_mus_stamu_ndof_(0),
  b_pf_mus_stamu_ndof_(NULL),
  c_pf_mus_stamu_ndof_(false),
  pf_mus_stamu_numlosthits_(0),
  b_pf_mus_stamu_numlosthits_(NULL),
  c_pf_mus_stamu_numlosthits_(false),
  pf_mus_stamu_numvalhits_(0),
  b_pf_mus_stamu_numvalhits_(NULL),
  c_pf_mus_stamu_numvalhits_(false),
  pf_mus_stamu_phi_(0),
  b_pf_mus_stamu_phi_(NULL),
  c_pf_mus_stamu_phi_(false),
  pf_mus_stamu_phiErr_(0),
  b_pf_mus_stamu_phiErr_(NULL),
  c_pf_mus_stamu_phiErr_(false),
  pf_mus_stamu_pt_(0),
  b_pf_mus_stamu_pt_(NULL),
  c_pf_mus_stamu_pt_(false),
  pf_mus_stamu_ptErr_(0),
  b_pf_mus_stamu_ptErr_(NULL),
  c_pf_mus_stamu_ptErr_(false),
  pf_mus_stamu_px_(0),
  b_pf_mus_stamu_px_(NULL),
  c_pf_mus_stamu_px_(false),
  pf_mus_stamu_py_(0),
  b_pf_mus_stamu_py_(NULL),
  c_pf_mus_stamu_py_(false),
  pf_mus_stamu_pz_(0),
  b_pf_mus_stamu_pz_(NULL),
  c_pf_mus_stamu_pz_(false),
  pf_mus_stamu_theta_(0),
  b_pf_mus_stamu_theta_(NULL),
  c_pf_mus_stamu_theta_(false),
  pf_mus_stamu_vx_(0),
  b_pf_mus_stamu_vx_(NULL),
  c_pf_mus_stamu_vx_(false),
  pf_mus_stamu_vy_(0),
  b_pf_mus_stamu_vy_(NULL),
  c_pf_mus_stamu_vy_(false),
  pf_mus_stamu_vz_(0),
  b_pf_mus_stamu_vz_(NULL),
  c_pf_mus_stamu_vz_(false),
  pf_mus_status_(0),
  b_pf_mus_status_(NULL),
  c_pf_mus_status_(false),
  pf_mus_tIso_(0),
  b_pf_mus_tIso_(NULL),
  c_pf_mus_tIso_(false),
  pf_mus_theta_(0),
  b_pf_mus_theta_(NULL),
  c_pf_mus_theta_(false),
  pf_mus_tkHits_(0),
  b_pf_mus_tkHits_(NULL),
  c_pf_mus_tkHits_(false),
  pf_mus_tk_ExpectedHitsInner_(0),
  b_pf_mus_tk_ExpectedHitsInner_(NULL),
  c_pf_mus_tk_ExpectedHitsInner_(false),
  pf_mus_tk_ExpectedHitsOuter_(0),
  b_pf_mus_tk_ExpectedHitsOuter_(NULL),
  c_pf_mus_tk_ExpectedHitsOuter_(false),
  pf_mus_tk_LayersWithMeasurement_(0),
  b_pf_mus_tk_LayersWithMeasurement_(NULL),
  c_pf_mus_tk_LayersWithMeasurement_(false),
  pf_mus_tk_LayersWithoutMeasurement_(0),
  b_pf_mus_tk_LayersWithoutMeasurement_(NULL),
  c_pf_mus_tk_LayersWithoutMeasurement_(false),
  pf_mus_tk_PixelLayersWithMeasurement_(0),
  b_pf_mus_tk_PixelLayersWithMeasurement_(NULL),
  c_pf_mus_tk_PixelLayersWithMeasurement_(false),
  pf_mus_tk_ValidStripLayersWithMonoAndStereoHit_(0),
  b_pf_mus_tk_ValidStripLayersWithMonoAndStereoHit_(NULL),
  c_pf_mus_tk_ValidStripLayersWithMonoAndStereoHit_(false),
  pf_mus_tk_chg_(0),
  b_pf_mus_tk_chg_(NULL),
  c_pf_mus_tk_chg_(false),
  pf_mus_tk_chi2_(0),
  b_pf_mus_tk_chi2_(NULL),
  c_pf_mus_tk_chi2_(false),
  pf_mus_tk_d0dum_(0),
  b_pf_mus_tk_d0dum_(NULL),
  c_pf_mus_tk_d0dum_(false),
  pf_mus_tk_d0dumErr_(0),
  b_pf_mus_tk_d0dumErr_(NULL),
  c_pf_mus_tk_d0dumErr_(false),
  pf_mus_tk_dz_(0),
  b_pf_mus_tk_dz_(NULL),
  c_pf_mus_tk_dz_(false),
  pf_mus_tk_dzErr_(0),
  b_pf_mus_tk_dzErr_(NULL),
  c_pf_mus_tk_dzErr_(false),
  pf_mus_tk_eta_(0),
  b_pf_mus_tk_eta_(NULL),
  c_pf_mus_tk_eta_(false),
  pf_mus_tk_etaErr_(0),
  b_pf_mus_tk_etaErr_(NULL),
  c_pf_mus_tk_etaErr_(false),
  pf_mus_tk_id_(0),
  b_pf_mus_tk_id_(NULL),
  c_pf_mus_tk_id_(false),
  pf_mus_tk_ndof_(0),
  b_pf_mus_tk_ndof_(NULL),
  c_pf_mus_tk_ndof_(false),
  pf_mus_tk_numlosthits_(0),
  b_pf_mus_tk_numlosthits_(NULL),
  c_pf_mus_tk_numlosthits_(false),
  pf_mus_tk_numpixelWthMeasr_(0),
  b_pf_mus_tk_numpixelWthMeasr_(NULL),
  c_pf_mus_tk_numpixelWthMeasr_(false),
  pf_mus_tk_numvalPixelhits_(0),
  b_pf_mus_tk_numvalPixelhits_(NULL),
  c_pf_mus_tk_numvalPixelhits_(false),
  pf_mus_tk_numvalhits_(0),
  b_pf_mus_tk_numvalhits_(NULL),
  c_pf_mus_tk_numvalhits_(false),
  pf_mus_tk_phi_(0),
  b_pf_mus_tk_phi_(NULL),
  c_pf_mus_tk_phi_(false),
  pf_mus_tk_phiErr_(0),
  b_pf_mus_tk_phiErr_(NULL),
  c_pf_mus_tk_phiErr_(false),
  pf_mus_tk_pt_(0),
  b_pf_mus_tk_pt_(NULL),
  c_pf_mus_tk_pt_(false),
  pf_mus_tk_ptErr_(0),
  b_pf_mus_tk_ptErr_(NULL),
  c_pf_mus_tk_ptErr_(false),
  pf_mus_tk_px_(0),
  b_pf_mus_tk_px_(NULL),
  c_pf_mus_tk_px_(false),
  pf_mus_tk_py_(0),
  b_pf_mus_tk_py_(NULL),
  c_pf_mus_tk_py_(false),
  pf_mus_tk_pz_(0),
  b_pf_mus_tk_pz_(NULL),
  c_pf_mus_tk_pz_(false),
  pf_mus_tk_theta_(0),
  b_pf_mus_tk_theta_(NULL),
  c_pf_mus_tk_theta_(false),
  pf_mus_tk_vx_(0),
  b_pf_mus_tk_vx_(NULL),
  c_pf_mus_tk_vx_(false),
  pf_mus_tk_vy_(0),
  b_pf_mus_tk_vy_(NULL),
  c_pf_mus_tk_vy_(false),
  pf_mus_tk_vz_(0),
  b_pf_mus_tk_vz_(NULL),
  c_pf_mus_tk_vz_(false),
  pf_mus_tpfms_ExpectedHitsInner_(0),
  b_pf_mus_tpfms_ExpectedHitsInner_(NULL),
  c_pf_mus_tpfms_ExpectedHitsInner_(false),
  pf_mus_tpfms_ExpectedHitsOuter_(0),
  b_pf_mus_tpfms_ExpectedHitsOuter_(NULL),
  c_pf_mus_tpfms_ExpectedHitsOuter_(false),
  pf_mus_tpfms_LayersWithMeasurement_(0),
  b_pf_mus_tpfms_LayersWithMeasurement_(NULL),
  c_pf_mus_tpfms_LayersWithMeasurement_(false),
  pf_mus_tpfms_LayersWithoutMeasurement_(0),
  b_pf_mus_tpfms_LayersWithoutMeasurement_(NULL),
  c_pf_mus_tpfms_LayersWithoutMeasurement_(false),
  pf_mus_tpfms_PixelLayersWithMeasurement_(0),
  b_pf_mus_tpfms_PixelLayersWithMeasurement_(NULL),
  c_pf_mus_tpfms_PixelLayersWithMeasurement_(false),
  pf_mus_tpfms_ValidStripLayersWithMonoAndStereoHit_(0),
  b_pf_mus_tpfms_ValidStripLayersWithMonoAndStereoHit_(NULL),
  c_pf_mus_tpfms_ValidStripLayersWithMonoAndStereoHit_(false),
  pf_mus_tpfms_chg_(0),
  b_pf_mus_tpfms_chg_(NULL),
  c_pf_mus_tpfms_chg_(false),
  pf_mus_tpfms_chi2_(0),
  b_pf_mus_tpfms_chi2_(NULL),
  c_pf_mus_tpfms_chi2_(false),
  pf_mus_tpfms_d0dum_(0),
  b_pf_mus_tpfms_d0dum_(NULL),
  c_pf_mus_tpfms_d0dum_(false),
  pf_mus_tpfms_d0dumErr_(0),
  b_pf_mus_tpfms_d0dumErr_(NULL),
  c_pf_mus_tpfms_d0dumErr_(false),
  pf_mus_tpfms_dz_(0),
  b_pf_mus_tpfms_dz_(NULL),
  c_pf_mus_tpfms_dz_(false),
  pf_mus_tpfms_dzErr_(0),
  b_pf_mus_tpfms_dzErr_(NULL),
  c_pf_mus_tpfms_dzErr_(false),
  pf_mus_tpfms_eta_(0),
  b_pf_mus_tpfms_eta_(NULL),
  c_pf_mus_tpfms_eta_(false),
  pf_mus_tpfms_etaErr_(0),
  b_pf_mus_tpfms_etaErr_(NULL),
  c_pf_mus_tpfms_etaErr_(false),
  pf_mus_tpfms_id_(0),
  b_pf_mus_tpfms_id_(NULL),
  c_pf_mus_tpfms_id_(false),
  pf_mus_tpfms_ndof_(0),
  b_pf_mus_tpfms_ndof_(NULL),
  c_pf_mus_tpfms_ndof_(false),
  pf_mus_tpfms_numlosthits_(0),
  b_pf_mus_tpfms_numlosthits_(NULL),
  c_pf_mus_tpfms_numlosthits_(false),
  pf_mus_tpfms_numvalPixelhits_(0),
  b_pf_mus_tpfms_numvalPixelhits_(NULL),
  c_pf_mus_tpfms_numvalPixelhits_(false),
  pf_mus_tpfms_numvalhits_(0),
  b_pf_mus_tpfms_numvalhits_(NULL),
  c_pf_mus_tpfms_numvalhits_(false),
  pf_mus_tpfms_phi_(0),
  b_pf_mus_tpfms_phi_(NULL),
  c_pf_mus_tpfms_phi_(false),
  pf_mus_tpfms_phiErr_(0),
  b_pf_mus_tpfms_phiErr_(NULL),
  c_pf_mus_tpfms_phiErr_(false),
  pf_mus_tpfms_pt_(0),
  b_pf_mus_tpfms_pt_(NULL),
  c_pf_mus_tpfms_pt_(false),
  pf_mus_tpfms_ptErr_(0),
  b_pf_mus_tpfms_ptErr_(NULL),
  c_pf_mus_tpfms_ptErr_(false),
  pf_mus_tpfms_px_(0),
  b_pf_mus_tpfms_px_(NULL),
  c_pf_mus_tpfms_px_(false),
  pf_mus_tpfms_py_(0),
  b_pf_mus_tpfms_py_(NULL),
  c_pf_mus_tpfms_py_(false),
  pf_mus_tpfms_pz_(0),
  b_pf_mus_tpfms_pz_(NULL),
  c_pf_mus_tpfms_pz_(false),
  pf_mus_tpfms_theta_(0),
  b_pf_mus_tpfms_theta_(NULL),
  c_pf_mus_tpfms_theta_(false),
  pf_mus_tpfms_vx_(0),
  b_pf_mus_tpfms_vx_(NULL),
  c_pf_mus_tpfms_vx_(false),
  pf_mus_tpfms_vy_(0),
  b_pf_mus_tpfms_vy_(NULL),
  c_pf_mus_tpfms_vy_(false),
  pf_mus_tpfms_vz_(0),
  b_pf_mus_tpfms_vz_(NULL),
  c_pf_mus_tpfms_vz_(false),
  pf_photons_chIso_(0),
  b_pf_photons_chIso_(NULL),
  c_pf_photons_chIso_(false),
  pf_photons_e1x5_(0),
  b_pf_photons_e1x5_(NULL),
  c_pf_photons_e1x5_(false),
  pf_photons_e2x5_(0),
  b_pf_photons_e2x5_(NULL),
  c_pf_photons_e2x5_(false),
  pf_photons_e3x3_(0),
  b_pf_photons_e3x3_(NULL),
  c_pf_photons_e3x3_(false),
  pf_photons_e5x5_(0),
  b_pf_photons_e5x5_(NULL),
  c_pf_photons_e5x5_(false),
  pf_photons_energy_(0),
  b_pf_photons_energy_(NULL),
  c_pf_photons_energy_(false),
  pf_photons_et_(0),
  b_pf_photons_et_(NULL),
  c_pf_photons_et_(false),
  pf_photons_eta_(0),
  b_pf_photons_eta_(NULL),
  c_pf_photons_eta_(false),
  pf_photons_hadOverEM_(0),
  b_pf_photons_hadOverEM_(NULL),
  c_pf_photons_hadOverEM_(false),
  pf_photons_hadTowOverEM_(0),
  b_pf_photons_hadTowOverEM_(NULL),
  c_pf_photons_hadTowOverEM_(false),
  pf_photons_hasPixelSeed_(0),
  b_pf_photons_hasPixelSeed_(NULL),
  c_pf_photons_hasPixelSeed_(false),
  pf_photons_isAlsoElectron_(0),
  b_pf_photons_isAlsoElectron_(NULL),
  c_pf_photons_isAlsoElectron_(false),
  pf_photons_isConverted_(0),
  b_pf_photons_isConverted_(NULL),
  c_pf_photons_isConverted_(false),
  pf_photons_isEBEEGap_(0),
  b_pf_photons_isEBEEGap_(NULL),
  c_pf_photons_isEBEEGap_(false),
  pf_photons_isEBGap_(0),
  b_pf_photons_isEBGap_(NULL),
  c_pf_photons_isEBGap_(false),
  pf_photons_isEBPho_(0),
  b_pf_photons_isEBPho_(NULL),
  c_pf_photons_isEBPho_(false),
  pf_photons_isEEGap_(0),
  b_pf_photons_isEEGap_(NULL),
  c_pf_photons_isEEGap_(false),
  pf_photons_isEEPho_(0),
  b_pf_photons_isEEPho_(NULL),
  c_pf_photons_isEEPho_(false),
  pf_photons_maxEnergyXtal_(0),
  b_pf_photons_maxEnergyXtal_(NULL),
  c_pf_photons_maxEnergyXtal_(false),
  pf_photons_nhIso_(0),
  b_pf_photons_nhIso_(NULL),
  c_pf_photons_nhIso_(false),
  pf_photons_phIso_(0),
  b_pf_photons_phIso_(NULL),
  c_pf_photons_phIso_(false),
  pf_photons_phi_(0),
  b_pf_photons_phi_(NULL),
  c_pf_photons_phi_(false),
  pf_photons_pt_(0),
  b_pf_photons_pt_(NULL),
  c_pf_photons_pt_(false),
  pf_photons_px_(0),
  b_pf_photons_px_(NULL),
  c_pf_photons_px_(false),
  pf_photons_py_(0),
  b_pf_photons_py_(NULL),
  c_pf_photons_py_(false),
  pf_photons_pz_(0),
  b_pf_photons_pz_(NULL),
  c_pf_photons_pz_(false),
  pf_photons_r9_(0),
  b_pf_photons_r9_(NULL),
  c_pf_photons_r9_(false),
  pf_photons_scEnergy_(0),
  b_pf_photons_scEnergy_(NULL),
  c_pf_photons_scEnergy_(false),
  pf_photons_scEta_(0),
  b_pf_photons_scEta_(NULL),
  c_pf_photons_scEta_(false),
  pf_photons_scEtaWidth_(0),
  b_pf_photons_scEtaWidth_(NULL),
  c_pf_photons_scEtaWidth_(false),
  pf_photons_scPhi_(0),
  b_pf_photons_scPhi_(NULL),
  c_pf_photons_scPhi_(false),
  pf_photons_scPhiWidth_(0),
  b_pf_photons_scPhiWidth_(NULL),
  c_pf_photons_scPhiWidth_(false),
  pf_photons_scRawEnergy_(0),
  b_pf_photons_scRawEnergy_(NULL),
  c_pf_photons_scRawEnergy_(false),
  pf_photons_sigmaEtaEta_(0),
  b_pf_photons_sigmaEtaEta_(NULL),
  c_pf_photons_sigmaEtaEta_(false),
  pf_photons_sigmaIetaIeta_(0),
  b_pf_photons_sigmaIetaIeta_(NULL),
  c_pf_photons_sigmaIetaIeta_(false),
  pf_photons_status_(0),
  b_pf_photons_status_(NULL),
  c_pf_photons_status_(false),
  pf_photons_theta_(0),
  b_pf_photons_theta_(NULL),
  c_pf_photons_theta_(false),
  pfcand_particleId_(0),
  b_pfcand_particleId_(NULL),
  c_pfcand_particleId_(false),
  pfmets_et_(0),
  b_pfmets_et_(NULL),
  c_pfmets_et_(false),
  pfmets_ex_(0),
  b_pfmets_ex_(NULL),
  c_pfmets_ex_(false),
  pfmets_ey_(0),
  b_pfmets_ey_(NULL),
  c_pfmets_ey_(false),
  pfmets_fullSignif_(0),
  b_pfmets_fullSignif_(NULL),
  c_pfmets_fullSignif_(false),
  pfmets_fullSignifCov00_(0),
  b_pfmets_fullSignifCov00_(NULL),
  c_pfmets_fullSignifCov00_(false),
  pfmets_fullSignifCov00_2012_(0),
  b_pfmets_fullSignifCov00_2012_(NULL),
  c_pfmets_fullSignifCov00_2012_(false),
  pfmets_fullSignifCov00_2012_dataRes_(0),
  b_pfmets_fullSignifCov00_2012_dataRes_(NULL),
  c_pfmets_fullSignifCov00_2012_dataRes_(false),
  pfmets_fullSignifCov10_(0),
  b_pfmets_fullSignifCov10_(NULL),
  c_pfmets_fullSignifCov10_(false),
  pfmets_fullSignifCov10_2012_(0),
  b_pfmets_fullSignifCov10_2012_(NULL),
  c_pfmets_fullSignifCov10_2012_(false),
  pfmets_fullSignifCov10_2012_dataRes_(0),
  b_pfmets_fullSignifCov10_2012_dataRes_(NULL),
  c_pfmets_fullSignifCov10_2012_dataRes_(false),
  pfmets_fullSignifCov11_(0),
  b_pfmets_fullSignifCov11_(NULL),
  c_pfmets_fullSignifCov11_(false),
  pfmets_fullSignifCov11_2012_(0),
  b_pfmets_fullSignifCov11_2012_(NULL),
  c_pfmets_fullSignifCov11_2012_(false),
  pfmets_fullSignifCov11_2012_dataRes_(0),
  b_pfmets_fullSignifCov11_2012_dataRes_(NULL),
  c_pfmets_fullSignifCov11_2012_dataRes_(false),
  pfmets_fullSignif_2012_(0),
  b_pfmets_fullSignif_2012_(NULL),
  c_pfmets_fullSignif_2012_(false),
  pfmets_fullSignif_2012_dataRes_(0),
  b_pfmets_fullSignif_2012_dataRes_(NULL),
  c_pfmets_fullSignif_2012_dataRes_(false),
  pfmets_gen_et_(0),
  b_pfmets_gen_et_(NULL),
  c_pfmets_gen_et_(false),
  pfmets_gen_phi_(0),
  b_pfmets_gen_phi_(NULL),
  c_pfmets_gen_phi_(false),
  pfmets_phi_(0),
  b_pfmets_phi_(NULL),
  c_pfmets_phi_(false),
  pfmets_sign_(0),
  b_pfmets_sign_(NULL),
  c_pfmets_sign_(false),
  pfmets_sumEt_(0),
  b_pfmets_sumEt_(NULL),
  c_pfmets_sumEt_(false),
  pfmets_unCPhi_(0),
  b_pfmets_unCPhi_(NULL),
  c_pfmets_unCPhi_(false),
  pfmets_unCPt_(0),
  b_pfmets_unCPt_(NULL),
  c_pfmets_unCPt_(false),
  photon_chIsoValues_(0),
  b_photon_chIsoValues_(NULL),
  c_photon_chIsoValues_(false),
  photon_nhIsoValues_(0),
  b_photon_nhIsoValues_(NULL),
  c_photon_nhIsoValues_(false),
  photon_passElectronVeto_(0),
  b_photon_passElectronVeto_(NULL),
  c_photon_passElectronVeto_(false),
  photon_phIsoValues_(0),
  b_photon_phIsoValues_(NULL),
  c_photon_phIsoValues_(false),
  puJet_rejectionBeta_(0),
  b_puJet_rejectionBeta_(NULL),
  c_puJet_rejectionBeta_(false),
  puJet_rejectionMVA_(0),
  b_puJet_rejectionMVA_(NULL),
  c_puJet_rejectionMVA_(false),
  rho_kt6PFJetsForIsolation2011_(0),
  b_rho_kt6PFJetsForIsolation2011_(NULL),
  c_rho_kt6PFJetsForIsolation2011_(false),
  rho_kt6PFJetsForIsolation2012_(0),
  b_rho_kt6PFJetsForIsolation2012_(NULL),
  c_rho_kt6PFJetsForIsolation2012_(false),
  scrapingVeto_decision_(0),
  b_scrapingVeto_decision_(NULL),
  c_scrapingVeto_decision_(false),
  softjetUp_dMEx_(0),
  b_softjetUp_dMEx_(NULL),
  c_softjetUp_dMEx_(false),
  softjetUp_dMEy_(0),
  b_softjetUp_dMEy_(NULL),
  c_softjetUp_dMEy_(false),
  tcmets_et_(0),
  b_tcmets_et_(NULL),
  c_tcmets_et_(false),
  tcmets_ex_(0),
  b_tcmets_ex_(NULL),
  c_tcmets_ex_(false),
  tcmets_ey_(0),
  b_tcmets_ey_(NULL),
  c_tcmets_ey_(false),
  tcmets_phi_(0),
  b_tcmets_phi_(NULL),
  c_tcmets_phi_(false),
  tcmets_sumEt_(0),
  b_tcmets_sumEt_(NULL),
  c_tcmets_sumEt_(false),
  trackercoherentnoisefilter1_decision_(0),
  b_trackercoherentnoisefilter1_decision_(NULL),
  c_trackercoherentnoisefilter1_decision_(false),
  trackercoherentnoisefilter2_decision_(0),
  b_trackercoherentnoisefilter2_decision_(NULL),
  c_trackercoherentnoisefilter2_decision_(false),
  trackertoomanyclustersfilter_decision_(0),
  b_trackertoomanyclustersfilter_decision_(NULL),
  c_trackertoomanyclustersfilter_decision_(false),
  trackertoomanyseedsfilter_decision_(0),
  b_trackertoomanyseedsfilter_decision_(NULL),
  c_trackertoomanyseedsfilter_decision_(false),
  trackertoomanytripletsfilter_decision_(0),
  b_trackertoomanytripletsfilter_decision_(NULL),
  c_trackertoomanytripletsfilter_decision_(false),
  tracks_chg_(0),
  b_tracks_chg_(NULL),
  c_tracks_chg_(false),
  tracks_chi2_(0),
  b_tracks_chi2_(NULL),
  c_tracks_chi2_(false),
  tracks_d0dum_(0),
  b_tracks_d0dum_(NULL),
  c_tracks_d0dum_(false),
  tracks_d0dumErr_(0),
  b_tracks_d0dumErr_(NULL),
  c_tracks_d0dumErr_(false),
  tracks_dz_(0),
  b_tracks_dz_(NULL),
  c_tracks_dz_(false),
  tracks_dzErr_(0),
  b_tracks_dzErr_(NULL),
  c_tracks_dzErr_(false),
  tracks_eta_(0),
  b_tracks_eta_(NULL),
  c_tracks_eta_(false),
  tracks_etaErr_(0),
  b_tracks_etaErr_(NULL),
  c_tracks_etaErr_(false),
  tracks_highPurity_(0),
  b_tracks_highPurity_(NULL),
  c_tracks_highPurity_(false),
  tracks_ndof_(0),
  b_tracks_ndof_(NULL),
  c_tracks_ndof_(false),
  tracks_numlosthits_(0),
  b_tracks_numlosthits_(NULL),
  c_tracks_numlosthits_(false),
  tracks_numvalhits_(0),
  b_tracks_numvalhits_(NULL),
  c_tracks_numvalhits_(false),
  tracks_phi_(0),
  b_tracks_phi_(NULL),
  c_tracks_phi_(false),
  tracks_phiErr_(0),
  b_tracks_phiErr_(NULL),
  c_tracks_phiErr_(false),
  tracks_pt_(0),
  b_tracks_pt_(NULL),
  c_tracks_pt_(false),
  tracks_ptErr_(0),
  b_tracks_ptErr_(NULL),
  c_tracks_ptErr_(false),
  tracks_px_(0),
  b_tracks_px_(NULL),
  c_tracks_px_(false),
  tracks_py_(0),
  b_tracks_py_(NULL),
  c_tracks_py_(false),
  tracks_pz_(0),
  b_tracks_pz_(NULL),
  c_tracks_pz_(false),
  tracks_vx_(0),
  b_tracks_vx_(NULL),
  c_tracks_vx_(false),
  tracks_vy_(0),
  b_tracks_vy_(NULL),
  c_tracks_vy_(false),
  tracks_vz_(0),
  b_tracks_vz_(NULL),
  c_tracks_vz_(false),
  trigger_decision_(0),
  v_trigger_decision_(0),
  b_trigger_decision_(NULL),
  c_trigger_decision_(false),
  trigger_lastfiltername_(0),
  b_trigger_lastfiltername_(NULL),
  c_trigger_lastfiltername_(false),
  triggerobject_collectionname_(0),
  b_triggerobject_collectionname_(NULL),
  c_triggerobject_collectionname_(false),
  triggerobject_energy_(0),
  b_triggerobject_energy_(NULL),
  c_triggerobject_energy_(false),
  triggerobject_et_(0),
  b_triggerobject_et_(NULL),
  c_triggerobject_et_(false),
  triggerobject_eta_(0),
  b_triggerobject_eta_(NULL),
  c_triggerobject_eta_(false),
  triggerobject_phi_(0),
  b_triggerobject_phi_(NULL),
  c_triggerobject_phi_(false),
  triggerobject_pt_(0),
  b_triggerobject_pt_(NULL),
  c_triggerobject_pt_(false),
  triggerobject_px_(0),
  b_triggerobject_px_(NULL),
  c_triggerobject_px_(false),
  triggerobject_py_(0),
  b_triggerobject_py_(NULL),
  c_triggerobject_py_(false),
  triggerobject_pz_(0),
  b_triggerobject_pz_(NULL),
  c_triggerobject_pz_(false),
  trk_nTOBTEC_(0),
  b_trk_nTOBTEC_(NULL),
  c_trk_nTOBTEC_(false),
  trk_ratioAllTOBTEC_(0),
  b_trk_ratioAllTOBTEC_(NULL),
  c_trk_ratioAllTOBTEC_(false),
  trk_ratioJetTOBTEC_(0),
  b_trk_ratioJetTOBTEC_(NULL),
  c_trk_ratioJetTOBTEC_(false){
  PrepareNewChains();
}

void cfa_8::GetEntry(const long entry){
  if(b_L1trigger_alias_ && !b_L1trigger_alias_->TestBit(kDoNotProcess)){
    c_L1trigger_alias_ = true;
  }else{
    c_L1trigger_alias_ = false;
  }
  if(b_L1trigger_bit_ && !b_L1trigger_bit_->TestBit(kDoNotProcess)){
    c_L1trigger_bit_ = true;
  }else{
    c_L1trigger_bit_ = false;
  }
  if(b_L1trigger_decision_ && !b_L1trigger_decision_->TestBit(kDoNotProcess)){
    c_L1trigger_decision_ = true;
  }else{
    c_L1trigger_decision_ = false;
  }
  if(b_L1trigger_decision_nomask_ && !b_L1trigger_decision_nomask_->TestBit(kDoNotProcess)){
    c_L1trigger_decision_nomask_ = true;
  }else{
    c_L1trigger_decision_nomask_ = false;
  }
  if(b_L1trigger_name_ && !b_L1trigger_name_->TestBit(kDoNotProcess)){
    c_L1trigger_name_ = true;
  }else{
    c_L1trigger_name_ = false;
  }
  if(b_L1trigger_prescalevalue_ && !b_L1trigger_prescalevalue_->TestBit(kDoNotProcess)){
    c_L1trigger_prescalevalue_ = true;
  }else{
    c_L1trigger_prescalevalue_ = false;
  }
  if(b_L1trigger_techTrigger_ && !b_L1trigger_techTrigger_->TestBit(kDoNotProcess)){
    c_L1trigger_techTrigger_ = true;
  }else{
    c_L1trigger_techTrigger_ = false;
  }
  if(b_MPT_ && !b_MPT_->TestBit(kDoNotProcess)){
    c_MPT_ = true;
  }else{
    c_MPT_ = false;
  }
  if(b_Njets_AK5PF_ && !b_Njets_AK5PF_->TestBit(kDoNotProcess)){
    c_Njets_AK5PF_ = true;
  }else{
    c_Njets_AK5PF_ = false;
  }
  if(b_Njets_AK5PFclean_ && !b_Njets_AK5PFclean_->TestBit(kDoNotProcess)){
    c_Njets_AK5PFclean_ = true;
  }else{
    c_Njets_AK5PFclean_ = false;
  }
  if(b_Nmc_pdf_ && !b_Nmc_pdf_->TestBit(kDoNotProcess)){
    c_Nmc_pdf_ = true;
  }else{
    c_Nmc_pdf_ = false;
  }
  if(b_NmetsHO_ && !b_NmetsHO_->TestBit(kDoNotProcess)){
    c_NmetsHO_ = true;
  }else{
    c_NmetsHO_ = false;
  }
  if(b_Nmets_AK5_ && !b_Nmets_AK5_->TestBit(kDoNotProcess)){
    c_Nmets_AK5_ = true;
  }else{
    c_Nmets_AK5_ = false;
  }
  if(b_NpfTypeINoXYCorrmets_ && !b_NpfTypeINoXYCorrmets_->TestBit(kDoNotProcess)){
    c_NpfTypeINoXYCorrmets_ = true;
  }else{
    c_NpfTypeINoXYCorrmets_ = false;
  }
  if(b_NpfTypeIType0mets_ && !b_NpfTypeIType0mets_->TestBit(kDoNotProcess)){
    c_NpfTypeIType0mets_ = true;
  }else{
    c_NpfTypeIType0mets_ = false;
  }
  if(b_NpfTypeImets_ && !b_NpfTypeImets_->TestBit(kDoNotProcess)){
    c_NpfTypeImets_ = true;
  }else{
    c_NpfTypeImets_ = false;
  }
  if(b_Npf_els_ && !b_Npf_els_->TestBit(kDoNotProcess)){
    c_Npf_els_ = true;
  }else{
    c_Npf_els_ = false;
  }
  if(b_Npf_mus_ && !b_Npf_mus_->TestBit(kDoNotProcess)){
    c_Npf_mus_ = true;
  }else{
    c_Npf_mus_ = false;
  }
  if(b_Npf_photons_ && !b_Npf_photons_->TestBit(kDoNotProcess)){
    c_Npf_photons_ = true;
  }else{
    c_Npf_photons_ = false;
  }
  if(b_Npfmets_ && !b_Npfmets_->TestBit(kDoNotProcess)){
    c_Npfmets_ = true;
  }else{
    c_Npfmets_ = false;
  }
  if(b_Ntcmets_ && !b_Ntcmets_->TestBit(kDoNotProcess)){
    c_Ntcmets_ = true;
  }else{
    c_Ntcmets_ = false;
  }
  if(b_Ntracks_ && !b_Ntracks_->TestBit(kDoNotProcess)){
    c_Ntracks_ = true;
  }else{
    c_Ntracks_ = false;
  }
  if(b_ecalBEfilter_decision_ && !b_ecalBEfilter_decision_->TestBit(kDoNotProcess)){
    c_ecalBEfilter_decision_ = true;
  }else{
    c_ecalBEfilter_decision_ = false;
  }
  if(b_ecalTPfilter_decision_ && !b_ecalTPfilter_decision_->TestBit(kDoNotProcess)){
    c_ecalTPfilter_decision_ = true;
  }else{
    c_ecalTPfilter_decision_ = false;
  }
  if(b_eenoisefilter_decision_ && !b_eenoisefilter_decision_->TestBit(kDoNotProcess)){
    c_eenoisefilter_decision_ = true;
  }else{
    c_eenoisefilter_decision_ = false;
  }
  if(b_els_PFchargedHadronIsoR03_ && !b_els_PFchargedHadronIsoR03_->TestBit(kDoNotProcess)){
    c_els_PFchargedHadronIsoR03_ = true;
  }else{
    c_els_PFchargedHadronIsoR03_ = false;
  }
  if(b_els_PFneutralHadronIsoR03_ && !b_els_PFneutralHadronIsoR03_->TestBit(kDoNotProcess)){
    c_els_PFneutralHadronIsoR03_ = true;
  }else{
    c_els_PFneutralHadronIsoR03_ = false;
  }
  if(b_els_PFphotonIsoR03_ && !b_els_PFphotonIsoR03_->TestBit(kDoNotProcess)){
    c_els_PFphotonIsoR03_ = true;
  }else{
    c_els_PFphotonIsoR03_ = false;
  }
  if(b_els_conversion_dcot_ && !b_els_conversion_dcot_->TestBit(kDoNotProcess)){
    c_els_conversion_dcot_ = true;
  }else{
    c_els_conversion_dcot_ = false;
  }
  if(b_els_conversion_dist_ && !b_els_conversion_dist_->TestBit(kDoNotProcess)){
    c_els_conversion_dist_ = true;
  }else{
    c_els_conversion_dist_ = false;
  }
  if(b_els_hasMatchedConversion_ && !b_els_hasMatchedConversion_->TestBit(kDoNotProcess)){
    c_els_hasMatchedConversion_ = true;
  }else{
    c_els_hasMatchedConversion_ = false;
  }
  if(b_genHT_ && !b_genHT_->TestBit(kDoNotProcess)){
    c_genHT_ = true;
  }else{
    c_genHT_ = false;
  }
  if(b_greedymuonfilter_decision_ && !b_greedymuonfilter_decision_->TestBit(kDoNotProcess)){
    c_greedymuonfilter_decision_ = true;
  }else{
    c_greedymuonfilter_decision_ = false;
  }
  if(b_hbhefilter_decision_ && !b_hbhefilter_decision_->TestBit(kDoNotProcess)){
    c_hbhefilter_decision_ = true;
  }else{
    c_hbhefilter_decision_ = false;
  }
  if(b_inconsistentPFmuonfilter_decision_ && !b_inconsistentPFmuonfilter_decision_->TestBit(kDoNotProcess)){
    c_inconsistentPFmuonfilter_decision_ = true;
  }else{
    c_inconsistentPFmuonfilter_decision_ = false;
  }
  if(b_isotk_charge_ && !b_isotk_charge_->TestBit(kDoNotProcess)){
    c_isotk_charge_ = true;
  }else{
    c_isotk_charge_ = false;
  }
  if(b_isotk_dzpv_ && !b_isotk_dzpv_->TestBit(kDoNotProcess)){
    c_isotk_dzpv_ = true;
  }else{
    c_isotk_dzpv_ = false;
  }
  if(b_isotk_eta_ && !b_isotk_eta_->TestBit(kDoNotProcess)){
    c_isotk_eta_ = true;
  }else{
    c_isotk_eta_ = false;
  }
  if(b_isotk_iso_ && !b_isotk_iso_->TestBit(kDoNotProcess)){
    c_isotk_iso_ = true;
  }else{
    c_isotk_iso_ = false;
  }
  if(b_isotk_phi_ && !b_isotk_phi_->TestBit(kDoNotProcess)){
    c_isotk_phi_ = true;
  }else{
    c_isotk_phi_ = false;
  }
  if(b_isotk_pt_ && !b_isotk_pt_->TestBit(kDoNotProcess)){
    c_isotk_pt_ = true;
  }else{
    c_isotk_pt_ = false;
  }
  if(b_jets_AK5PF_area_ && !b_jets_AK5PF_area_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_area_ = true;
  }else{
    c_jets_AK5PF_area_ = false;
  }
  if(b_jets_AK5PF_btag_TC_highEff_ && !b_jets_AK5PF_btag_TC_highEff_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_btag_TC_highEff_ = true;
  }else{
    c_jets_AK5PF_btag_TC_highEff_ = false;
  }
  if(b_jets_AK5PF_btag_TC_highPur_ && !b_jets_AK5PF_btag_TC_highPur_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_btag_TC_highPur_ = true;
  }else{
    c_jets_AK5PF_btag_TC_highPur_ = false;
  }
  if(b_jets_AK5PF_btag_jetBProb_ && !b_jets_AK5PF_btag_jetBProb_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_btag_jetBProb_ = true;
  }else{
    c_jets_AK5PF_btag_jetBProb_ = false;
  }
  if(b_jets_AK5PF_btag_jetProb_ && !b_jets_AK5PF_btag_jetProb_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_btag_jetProb_ = true;
  }else{
    c_jets_AK5PF_btag_jetProb_ = false;
  }
  if(b_jets_AK5PF_btag_secVertexCombined_ && !b_jets_AK5PF_btag_secVertexCombined_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_btag_secVertexCombined_ = true;
  }else{
    c_jets_AK5PF_btag_secVertexCombined_ = false;
  }
  if(b_jets_AK5PF_btag_secVertexHighEff_ && !b_jets_AK5PF_btag_secVertexHighEff_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_btag_secVertexHighEff_ = true;
  }else{
    c_jets_AK5PF_btag_secVertexHighEff_ = false;
  }
  if(b_jets_AK5PF_btag_secVertexHighPur_ && !b_jets_AK5PF_btag_secVertexHighPur_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_btag_secVertexHighPur_ = true;
  }else{
    c_jets_AK5PF_btag_secVertexHighPur_ = false;
  }
  if(b_jets_AK5PF_btag_softEle_ && !b_jets_AK5PF_btag_softEle_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_btag_softEle_ = true;
  }else{
    c_jets_AK5PF_btag_softEle_ = false;
  }
  if(b_jets_AK5PF_btag_softMuon_ && !b_jets_AK5PF_btag_softMuon_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_btag_softMuon_ = true;
  }else{
    c_jets_AK5PF_btag_softMuon_ = false;
  }
  if(b_jets_AK5PF_chgEmE_ && !b_jets_AK5PF_chgEmE_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_chgEmE_ = true;
  }else{
    c_jets_AK5PF_chgEmE_ = false;
  }
  if(b_jets_AK5PF_chgHadE_ && !b_jets_AK5PF_chgHadE_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_chgHadE_ = true;
  }else{
    c_jets_AK5PF_chgHadE_ = false;
  }
  if(b_jets_AK5PF_chgMuE_ && !b_jets_AK5PF_chgMuE_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_chgMuE_ = true;
  }else{
    c_jets_AK5PF_chgMuE_ = false;
  }
  if(b_jets_AK5PF_chg_Mult_ && !b_jets_AK5PF_chg_Mult_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_chg_Mult_ = true;
  }else{
    c_jets_AK5PF_chg_Mult_ = false;
  }
  if(b_jets_AK5PF_corrFactorRaw_ && !b_jets_AK5PF_corrFactorRaw_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_corrFactorRaw_ = true;
  }else{
    c_jets_AK5PF_corrFactorRaw_ = false;
  }
  if(b_jets_AK5PF_ehf_ && !b_jets_AK5PF_ehf_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_ehf_ = true;
  }else{
    c_jets_AK5PF_ehf_ = false;
  }
  if(b_jets_AK5PF_emf_ && !b_jets_AK5PF_emf_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_emf_ = true;
  }else{
    c_jets_AK5PF_emf_ = false;
  }
  if(b_jets_AK5PF_energy_ && !b_jets_AK5PF_energy_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_energy_ = true;
  }else{
    c_jets_AK5PF_energy_ = false;
  }
  if(b_jets_AK5PF_et_ && !b_jets_AK5PF_et_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_et_ = true;
  }else{
    c_jets_AK5PF_et_ = false;
  }
  if(b_jets_AK5PF_eta_ && !b_jets_AK5PF_eta_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_eta_ = true;
  }else{
    c_jets_AK5PF_eta_ = false;
  }
  if(b_jets_AK5PF_etaetaMoment_ && !b_jets_AK5PF_etaetaMoment_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_etaetaMoment_ = true;
  }else{
    c_jets_AK5PF_etaetaMoment_ = false;
  }
  if(b_jets_AK5PF_etaphiMoment_ && !b_jets_AK5PF_etaphiMoment_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_etaphiMoment_ = true;
  }else{
    c_jets_AK5PF_etaphiMoment_ = false;
  }
  if(b_jets_AK5PF_fHPD_ && !b_jets_AK5PF_fHPD_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_fHPD_ = true;
  }else{
    c_jets_AK5PF_fHPD_ = false;
  }
  if(b_jets_AK5PF_fRBX_ && !b_jets_AK5PF_fRBX_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_fRBX_ = true;
  }else{
    c_jets_AK5PF_fRBX_ = false;
  }
  if(b_jets_AK5PF_fSubDetector1_ && !b_jets_AK5PF_fSubDetector1_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_fSubDetector1_ = true;
  }else{
    c_jets_AK5PF_fSubDetector1_ = false;
  }
  if(b_jets_AK5PF_fSubDetector2_ && !b_jets_AK5PF_fSubDetector2_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_fSubDetector2_ = true;
  }else{
    c_jets_AK5PF_fSubDetector2_ = false;
  }
  if(b_jets_AK5PF_fSubDetector3_ && !b_jets_AK5PF_fSubDetector3_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_fSubDetector3_ = true;
  }else{
    c_jets_AK5PF_fSubDetector3_ = false;
  }
  if(b_jets_AK5PF_fSubDetector4_ && !b_jets_AK5PF_fSubDetector4_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_fSubDetector4_ = true;
  }else{
    c_jets_AK5PF_fSubDetector4_ = false;
  }
  if(b_jets_AK5PF_gen_Energy_ && !b_jets_AK5PF_gen_Energy_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_gen_Energy_ = true;
  }else{
    c_jets_AK5PF_gen_Energy_ = false;
  }
  if(b_jets_AK5PF_gen_Id_ && !b_jets_AK5PF_gen_Id_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_gen_Id_ = true;
  }else{
    c_jets_AK5PF_gen_Id_ = false;
  }
  if(b_jets_AK5PF_gen_et_ && !b_jets_AK5PF_gen_et_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_gen_et_ = true;
  }else{
    c_jets_AK5PF_gen_et_ = false;
  }
  if(b_jets_AK5PF_gen_eta_ && !b_jets_AK5PF_gen_eta_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_gen_eta_ = true;
  }else{
    c_jets_AK5PF_gen_eta_ = false;
  }
  if(b_jets_AK5PF_gen_mass_ && !b_jets_AK5PF_gen_mass_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_gen_mass_ = true;
  }else{
    c_jets_AK5PF_gen_mass_ = false;
  }
  if(b_jets_AK5PF_gen_motherID_ && !b_jets_AK5PF_gen_motherID_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_gen_motherID_ = true;
  }else{
    c_jets_AK5PF_gen_motherID_ = false;
  }
  if(b_jets_AK5PF_gen_phi_ && !b_jets_AK5PF_gen_phi_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_gen_phi_ = true;
  }else{
    c_jets_AK5PF_gen_phi_ = false;
  }
  if(b_jets_AK5PF_gen_pt_ && !b_jets_AK5PF_gen_pt_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_gen_pt_ = true;
  }else{
    c_jets_AK5PF_gen_pt_ = false;
  }
  if(b_jets_AK5PF_gen_threeCharge_ && !b_jets_AK5PF_gen_threeCharge_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_gen_threeCharge_ = true;
  }else{
    c_jets_AK5PF_gen_threeCharge_ = false;
  }
  if(b_jets_AK5PF_hitsInN90_ && !b_jets_AK5PF_hitsInN90_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_hitsInN90_ = true;
  }else{
    c_jets_AK5PF_hitsInN90_ = false;
  }
  if(b_jets_AK5PF_jetCharge_ && !b_jets_AK5PF_jetCharge_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_jetCharge_ = true;
  }else{
    c_jets_AK5PF_jetCharge_ = false;
  }
  if(b_jets_AK5PF_mass_ && !b_jets_AK5PF_mass_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_mass_ = true;
  }else{
    c_jets_AK5PF_mass_ = false;
  }
  if(b_jets_AK5PF_mu_Mult_ && !b_jets_AK5PF_mu_Mult_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_mu_Mult_ = true;
  }else{
    c_jets_AK5PF_mu_Mult_ = false;
  }
  if(b_jets_AK5PF_n60_ && !b_jets_AK5PF_n60_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_n60_ = true;
  }else{
    c_jets_AK5PF_n60_ = false;
  }
  if(b_jets_AK5PF_n90_ && !b_jets_AK5PF_n90_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_n90_ = true;
  }else{
    c_jets_AK5PF_n90_ = false;
  }
  if(b_jets_AK5PF_n90Hits_ && !b_jets_AK5PF_n90Hits_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_n90Hits_ = true;
  }else{
    c_jets_AK5PF_n90Hits_ = false;
  }
  if(b_jets_AK5PF_nECALTowers_ && !b_jets_AK5PF_nECALTowers_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_nECALTowers_ = true;
  }else{
    c_jets_AK5PF_nECALTowers_ = false;
  }
  if(b_jets_AK5PF_nHCALTowers_ && !b_jets_AK5PF_nHCALTowers_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_nHCALTowers_ = true;
  }else{
    c_jets_AK5PF_nHCALTowers_ = false;
  }
  if(b_jets_AK5PF_neutralEmE_ && !b_jets_AK5PF_neutralEmE_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_neutralEmE_ = true;
  }else{
    c_jets_AK5PF_neutralEmE_ = false;
  }
  if(b_jets_AK5PF_neutralHadE_ && !b_jets_AK5PF_neutralHadE_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_neutralHadE_ = true;
  }else{
    c_jets_AK5PF_neutralHadE_ = false;
  }
  if(b_jets_AK5PF_neutral_Mult_ && !b_jets_AK5PF_neutral_Mult_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_neutral_Mult_ = true;
  }else{
    c_jets_AK5PF_neutral_Mult_ = false;
  }
  if(b_jets_AK5PF_partonFlavour_ && !b_jets_AK5PF_partonFlavour_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_partonFlavour_ = true;
  }else{
    c_jets_AK5PF_partonFlavour_ = false;
  }
  if(b_jets_AK5PF_parton_Energy_ && !b_jets_AK5PF_parton_Energy_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_parton_Energy_ = true;
  }else{
    c_jets_AK5PF_parton_Energy_ = false;
  }
  if(b_jets_AK5PF_parton_Id_ && !b_jets_AK5PF_parton_Id_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_parton_Id_ = true;
  }else{
    c_jets_AK5PF_parton_Id_ = false;
  }
  if(b_jets_AK5PF_parton_eta_ && !b_jets_AK5PF_parton_eta_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_parton_eta_ = true;
  }else{
    c_jets_AK5PF_parton_eta_ = false;
  }
  if(b_jets_AK5PF_parton_mass_ && !b_jets_AK5PF_parton_mass_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_parton_mass_ = true;
  }else{
    c_jets_AK5PF_parton_mass_ = false;
  }
  if(b_jets_AK5PF_parton_motherId_ && !b_jets_AK5PF_parton_motherId_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_parton_motherId_ = true;
  }else{
    c_jets_AK5PF_parton_motherId_ = false;
  }
  if(b_jets_AK5PF_parton_phi_ && !b_jets_AK5PF_parton_phi_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_parton_phi_ = true;
  }else{
    c_jets_AK5PF_parton_phi_ = false;
  }
  if(b_jets_AK5PF_parton_pt_ && !b_jets_AK5PF_parton_pt_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_parton_pt_ = true;
  }else{
    c_jets_AK5PF_parton_pt_ = false;
  }
  if(b_jets_AK5PF_phi_ && !b_jets_AK5PF_phi_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_phi_ = true;
  }else{
    c_jets_AK5PF_phi_ = false;
  }
  if(b_jets_AK5PF_phiphiMoment_ && !b_jets_AK5PF_phiphiMoment_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_phiphiMoment_ = true;
  }else{
    c_jets_AK5PF_phiphiMoment_ = false;
  }
  if(b_jets_AK5PF_photonEnergy_ && !b_jets_AK5PF_photonEnergy_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_photonEnergy_ = true;
  }else{
    c_jets_AK5PF_photonEnergy_ = false;
  }
  if(b_jets_AK5PF_pt_ && !b_jets_AK5PF_pt_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_pt_ = true;
  }else{
    c_jets_AK5PF_pt_ = false;
  }
  if(b_jets_AK5PF_px_ && !b_jets_AK5PF_px_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_px_ = true;
  }else{
    c_jets_AK5PF_px_ = false;
  }
  if(b_jets_AK5PF_py_ && !b_jets_AK5PF_py_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_py_ = true;
  }else{
    c_jets_AK5PF_py_ = false;
  }
  if(b_jets_AK5PF_pz_ && !b_jets_AK5PF_pz_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_pz_ = true;
  }else{
    c_jets_AK5PF_pz_ = false;
  }
  if(b_jets_AK5PF_rawPt_ && !b_jets_AK5PF_rawPt_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_rawPt_ = true;
  }else{
    c_jets_AK5PF_rawPt_ = false;
  }
  if(b_jets_AK5PF_status_ && !b_jets_AK5PF_status_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_status_ = true;
  }else{
    c_jets_AK5PF_status_ = false;
  }
  if(b_jets_AK5PF_theta_ && !b_jets_AK5PF_theta_->TestBit(kDoNotProcess)){
    c_jets_AK5PF_theta_ = true;
  }else{
    c_jets_AK5PF_theta_ = false;
  }
  if(b_jets_AK5PFclean_Uncert_ && !b_jets_AK5PFclean_Uncert_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_Uncert_ = true;
  }else{
    c_jets_AK5PFclean_Uncert_ = false;
  }
  if(b_jets_AK5PFclean_area_ && !b_jets_AK5PFclean_area_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_area_ = true;
  }else{
    c_jets_AK5PFclean_area_ = false;
  }
  if(b_jets_AK5PFclean_btag_TC_highEff_ && !b_jets_AK5PFclean_btag_TC_highEff_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_btag_TC_highEff_ = true;
  }else{
    c_jets_AK5PFclean_btag_TC_highEff_ = false;
  }
  if(b_jets_AK5PFclean_btag_TC_highPur_ && !b_jets_AK5PFclean_btag_TC_highPur_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_btag_TC_highPur_ = true;
  }else{
    c_jets_AK5PFclean_btag_TC_highPur_ = false;
  }
  if(b_jets_AK5PFclean_btag_jetBProb_ && !b_jets_AK5PFclean_btag_jetBProb_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_btag_jetBProb_ = true;
  }else{
    c_jets_AK5PFclean_btag_jetBProb_ = false;
  }
  if(b_jets_AK5PFclean_btag_jetProb_ && !b_jets_AK5PFclean_btag_jetProb_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_btag_jetProb_ = true;
  }else{
    c_jets_AK5PFclean_btag_jetProb_ = false;
  }
  if(b_jets_AK5PFclean_btag_secVertexCombined_ && !b_jets_AK5PFclean_btag_secVertexCombined_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_btag_secVertexCombined_ = true;
  }else{
    c_jets_AK5PFclean_btag_secVertexCombined_ = false;
  }
  if(b_jets_AK5PFclean_btag_secVertexHighEff_ && !b_jets_AK5PFclean_btag_secVertexHighEff_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_btag_secVertexHighEff_ = true;
  }else{
    c_jets_AK5PFclean_btag_secVertexHighEff_ = false;
  }
  if(b_jets_AK5PFclean_btag_secVertexHighPur_ && !b_jets_AK5PFclean_btag_secVertexHighPur_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_btag_secVertexHighPur_ = true;
  }else{
    c_jets_AK5PFclean_btag_secVertexHighPur_ = false;
  }
  if(b_jets_AK5PFclean_btag_softEle_ && !b_jets_AK5PFclean_btag_softEle_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_btag_softEle_ = true;
  }else{
    c_jets_AK5PFclean_btag_softEle_ = false;
  }
  if(b_jets_AK5PFclean_btag_softMuon_ && !b_jets_AK5PFclean_btag_softMuon_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_btag_softMuon_ = true;
  }else{
    c_jets_AK5PFclean_btag_softMuon_ = false;
  }
  if(b_jets_AK5PFclean_chgEmE_ && !b_jets_AK5PFclean_chgEmE_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_chgEmE_ = true;
  }else{
    c_jets_AK5PFclean_chgEmE_ = false;
  }
  if(b_jets_AK5PFclean_chgHadE_ && !b_jets_AK5PFclean_chgHadE_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_chgHadE_ = true;
  }else{
    c_jets_AK5PFclean_chgHadE_ = false;
  }
  if(b_jets_AK5PFclean_chgMuE_ && !b_jets_AK5PFclean_chgMuE_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_chgMuE_ = true;
  }else{
    c_jets_AK5PFclean_chgMuE_ = false;
  }
  if(b_jets_AK5PFclean_chg_Mult_ && !b_jets_AK5PFclean_chg_Mult_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_chg_Mult_ = true;
  }else{
    c_jets_AK5PFclean_chg_Mult_ = false;
  }
  if(b_jets_AK5PFclean_corrFactorRaw_ && !b_jets_AK5PFclean_corrFactorRaw_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_corrFactorRaw_ = true;
  }else{
    c_jets_AK5PFclean_corrFactorRaw_ = false;
  }
  if(b_jets_AK5PFclean_corrL1FastL2L3_ && !b_jets_AK5PFclean_corrL1FastL2L3_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_corrL1FastL2L3_ = true;
  }else{
    c_jets_AK5PFclean_corrL1FastL2L3_ = false;
  }
  if(b_jets_AK5PFclean_corrL1FastL2L3Residual_ && !b_jets_AK5PFclean_corrL1FastL2L3Residual_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_corrL1FastL2L3Residual_ = true;
  }else{
    c_jets_AK5PFclean_corrL1FastL2L3Residual_ = false;
  }
  if(b_jets_AK5PFclean_corrL1L2L3_ && !b_jets_AK5PFclean_corrL1L2L3_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_corrL1L2L3_ = true;
  }else{
    c_jets_AK5PFclean_corrL1L2L3_ = false;
  }
  if(b_jets_AK5PFclean_corrL1L2L3Residual_ && !b_jets_AK5PFclean_corrL1L2L3Residual_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_corrL1L2L3Residual_ = true;
  }else{
    c_jets_AK5PFclean_corrL1L2L3Residual_ = false;
  }
  if(b_jets_AK5PFclean_corrL2L3_ && !b_jets_AK5PFclean_corrL2L3_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_corrL2L3_ = true;
  }else{
    c_jets_AK5PFclean_corrL2L3_ = false;
  }
  if(b_jets_AK5PFclean_corrL2L3Residual_ && !b_jets_AK5PFclean_corrL2L3Residual_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_corrL2L3Residual_ = true;
  }else{
    c_jets_AK5PFclean_corrL2L3Residual_ = false;
  }
  if(b_jets_AK5PFclean_ehf_ && !b_jets_AK5PFclean_ehf_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_ehf_ = true;
  }else{
    c_jets_AK5PFclean_ehf_ = false;
  }
  if(b_jets_AK5PFclean_emf_ && !b_jets_AK5PFclean_emf_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_emf_ = true;
  }else{
    c_jets_AK5PFclean_emf_ = false;
  }
  if(b_jets_AK5PFclean_energy_ && !b_jets_AK5PFclean_energy_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_energy_ = true;
  }else{
    c_jets_AK5PFclean_energy_ = false;
  }
  if(b_jets_AK5PFclean_et_ && !b_jets_AK5PFclean_et_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_et_ = true;
  }else{
    c_jets_AK5PFclean_et_ = false;
  }
  if(b_jets_AK5PFclean_eta_ && !b_jets_AK5PFclean_eta_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_eta_ = true;
  }else{
    c_jets_AK5PFclean_eta_ = false;
  }
  if(b_jets_AK5PFclean_etaetaMoment_ && !b_jets_AK5PFclean_etaetaMoment_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_etaetaMoment_ = true;
  }else{
    c_jets_AK5PFclean_etaetaMoment_ = false;
  }
  if(b_jets_AK5PFclean_etaphiMoment_ && !b_jets_AK5PFclean_etaphiMoment_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_etaphiMoment_ = true;
  }else{
    c_jets_AK5PFclean_etaphiMoment_ = false;
  }
  if(b_jets_AK5PFclean_fHPD_ && !b_jets_AK5PFclean_fHPD_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_fHPD_ = true;
  }else{
    c_jets_AK5PFclean_fHPD_ = false;
  }
  if(b_jets_AK5PFclean_fRBX_ && !b_jets_AK5PFclean_fRBX_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_fRBX_ = true;
  }else{
    c_jets_AK5PFclean_fRBX_ = false;
  }
  if(b_jets_AK5PFclean_fSubDetector1_ && !b_jets_AK5PFclean_fSubDetector1_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_fSubDetector1_ = true;
  }else{
    c_jets_AK5PFclean_fSubDetector1_ = false;
  }
  if(b_jets_AK5PFclean_fSubDetector2_ && !b_jets_AK5PFclean_fSubDetector2_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_fSubDetector2_ = true;
  }else{
    c_jets_AK5PFclean_fSubDetector2_ = false;
  }
  if(b_jets_AK5PFclean_fSubDetector3_ && !b_jets_AK5PFclean_fSubDetector3_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_fSubDetector3_ = true;
  }else{
    c_jets_AK5PFclean_fSubDetector3_ = false;
  }
  if(b_jets_AK5PFclean_fSubDetector4_ && !b_jets_AK5PFclean_fSubDetector4_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_fSubDetector4_ = true;
  }else{
    c_jets_AK5PFclean_fSubDetector4_ = false;
  }
  if(b_jets_AK5PFclean_gen_Energy_ && !b_jets_AK5PFclean_gen_Energy_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_gen_Energy_ = true;
  }else{
    c_jets_AK5PFclean_gen_Energy_ = false;
  }
  if(b_jets_AK5PFclean_gen_Id_ && !b_jets_AK5PFclean_gen_Id_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_gen_Id_ = true;
  }else{
    c_jets_AK5PFclean_gen_Id_ = false;
  }
  if(b_jets_AK5PFclean_gen_et_ && !b_jets_AK5PFclean_gen_et_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_gen_et_ = true;
  }else{
    c_jets_AK5PFclean_gen_et_ = false;
  }
  if(b_jets_AK5PFclean_gen_eta_ && !b_jets_AK5PFclean_gen_eta_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_gen_eta_ = true;
  }else{
    c_jets_AK5PFclean_gen_eta_ = false;
  }
  if(b_jets_AK5PFclean_gen_mass_ && !b_jets_AK5PFclean_gen_mass_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_gen_mass_ = true;
  }else{
    c_jets_AK5PFclean_gen_mass_ = false;
  }
  if(b_jets_AK5PFclean_gen_phi_ && !b_jets_AK5PFclean_gen_phi_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_gen_phi_ = true;
  }else{
    c_jets_AK5PFclean_gen_phi_ = false;
  }
  if(b_jets_AK5PFclean_gen_pt_ && !b_jets_AK5PFclean_gen_pt_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_gen_pt_ = true;
  }else{
    c_jets_AK5PFclean_gen_pt_ = false;
  }
  if(b_jets_AK5PFclean_hitsInN90_ && !b_jets_AK5PFclean_hitsInN90_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_hitsInN90_ = true;
  }else{
    c_jets_AK5PFclean_hitsInN90_ = false;
  }
  if(b_jets_AK5PFclean_jetCharge_ && !b_jets_AK5PFclean_jetCharge_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_jetCharge_ = true;
  }else{
    c_jets_AK5PFclean_jetCharge_ = false;
  }
  if(b_jets_AK5PFclean_mass_ && !b_jets_AK5PFclean_mass_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_mass_ = true;
  }else{
    c_jets_AK5PFclean_mass_ = false;
  }
  if(b_jets_AK5PFclean_mu_Mult_ && !b_jets_AK5PFclean_mu_Mult_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_mu_Mult_ = true;
  }else{
    c_jets_AK5PFclean_mu_Mult_ = false;
  }
  if(b_jets_AK5PFclean_n60_ && !b_jets_AK5PFclean_n60_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_n60_ = true;
  }else{
    c_jets_AK5PFclean_n60_ = false;
  }
  if(b_jets_AK5PFclean_n90_ && !b_jets_AK5PFclean_n90_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_n90_ = true;
  }else{
    c_jets_AK5PFclean_n90_ = false;
  }
  if(b_jets_AK5PFclean_n90Hits_ && !b_jets_AK5PFclean_n90Hits_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_n90Hits_ = true;
  }else{
    c_jets_AK5PFclean_n90Hits_ = false;
  }
  if(b_jets_AK5PFclean_nECALTowers_ && !b_jets_AK5PFclean_nECALTowers_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_nECALTowers_ = true;
  }else{
    c_jets_AK5PFclean_nECALTowers_ = false;
  }
  if(b_jets_AK5PFclean_nHCALTowers_ && !b_jets_AK5PFclean_nHCALTowers_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_nHCALTowers_ = true;
  }else{
    c_jets_AK5PFclean_nHCALTowers_ = false;
  }
  if(b_jets_AK5PFclean_neutralEmE_ && !b_jets_AK5PFclean_neutralEmE_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_neutralEmE_ = true;
  }else{
    c_jets_AK5PFclean_neutralEmE_ = false;
  }
  if(b_jets_AK5PFclean_neutralHadE_ && !b_jets_AK5PFclean_neutralHadE_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_neutralHadE_ = true;
  }else{
    c_jets_AK5PFclean_neutralHadE_ = false;
  }
  if(b_jets_AK5PFclean_neutral_Mult_ && !b_jets_AK5PFclean_neutral_Mult_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_neutral_Mult_ = true;
  }else{
    c_jets_AK5PFclean_neutral_Mult_ = false;
  }
  if(b_jets_AK5PFclean_partonFlavour_ && !b_jets_AK5PFclean_partonFlavour_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_partonFlavour_ = true;
  }else{
    c_jets_AK5PFclean_partonFlavour_ = false;
  }
  if(b_jets_AK5PFclean_parton_Energy_ && !b_jets_AK5PFclean_parton_Energy_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_parton_Energy_ = true;
  }else{
    c_jets_AK5PFclean_parton_Energy_ = false;
  }
  if(b_jets_AK5PFclean_parton_Id_ && !b_jets_AK5PFclean_parton_Id_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_parton_Id_ = true;
  }else{
    c_jets_AK5PFclean_parton_Id_ = false;
  }
  if(b_jets_AK5PFclean_parton_eta_ && !b_jets_AK5PFclean_parton_eta_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_parton_eta_ = true;
  }else{
    c_jets_AK5PFclean_parton_eta_ = false;
  }
  if(b_jets_AK5PFclean_parton_mass_ && !b_jets_AK5PFclean_parton_mass_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_parton_mass_ = true;
  }else{
    c_jets_AK5PFclean_parton_mass_ = false;
  }
  if(b_jets_AK5PFclean_parton_motherId_ && !b_jets_AK5PFclean_parton_motherId_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_parton_motherId_ = true;
  }else{
    c_jets_AK5PFclean_parton_motherId_ = false;
  }
  if(b_jets_AK5PFclean_parton_phi_ && !b_jets_AK5PFclean_parton_phi_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_parton_phi_ = true;
  }else{
    c_jets_AK5PFclean_parton_phi_ = false;
  }
  if(b_jets_AK5PFclean_parton_pt_ && !b_jets_AK5PFclean_parton_pt_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_parton_pt_ = true;
  }else{
    c_jets_AK5PFclean_parton_pt_ = false;
  }
  if(b_jets_AK5PFclean_phi_ && !b_jets_AK5PFclean_phi_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_phi_ = true;
  }else{
    c_jets_AK5PFclean_phi_ = false;
  }
  if(b_jets_AK5PFclean_phiphiMoment_ && !b_jets_AK5PFclean_phiphiMoment_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_phiphiMoment_ = true;
  }else{
    c_jets_AK5PFclean_phiphiMoment_ = false;
  }
  if(b_jets_AK5PFclean_photonEnergy_ && !b_jets_AK5PFclean_photonEnergy_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_photonEnergy_ = true;
  }else{
    c_jets_AK5PFclean_photonEnergy_ = false;
  }
  if(b_jets_AK5PFclean_pt_ && !b_jets_AK5PFclean_pt_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_pt_ = true;
  }else{
    c_jets_AK5PFclean_pt_ = false;
  }
  if(b_jets_AK5PFclean_px_ && !b_jets_AK5PFclean_px_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_px_ = true;
  }else{
    c_jets_AK5PFclean_px_ = false;
  }
  if(b_jets_AK5PFclean_py_ && !b_jets_AK5PFclean_py_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_py_ = true;
  }else{
    c_jets_AK5PFclean_py_ = false;
  }
  if(b_jets_AK5PFclean_pz_ && !b_jets_AK5PFclean_pz_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_pz_ = true;
  }else{
    c_jets_AK5PFclean_pz_ = false;
  }
  if(b_jets_AK5PFclean_rawPt_ && !b_jets_AK5PFclean_rawPt_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_rawPt_ = true;
  }else{
    c_jets_AK5PFclean_rawPt_ = false;
  }
  if(b_jets_AK5PFclean_status_ && !b_jets_AK5PFclean_status_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_status_ = true;
  }else{
    c_jets_AK5PFclean_status_ = false;
  }
  if(b_jets_AK5PFclean_theta_ && !b_jets_AK5PFclean_theta_->TestBit(kDoNotProcess)){
    c_jets_AK5PFclean_theta_ = true;
  }else{
    c_jets_AK5PFclean_theta_ = false;
  }
  if(b_mc_pdf_id1_ && !b_mc_pdf_id1_->TestBit(kDoNotProcess)){
    c_mc_pdf_id1_ = true;
  }else{
    c_mc_pdf_id1_ = false;
  }
  if(b_mc_pdf_id2_ && !b_mc_pdf_id2_->TestBit(kDoNotProcess)){
    c_mc_pdf_id2_ = true;
  }else{
    c_mc_pdf_id2_ = false;
  }
  if(b_mc_pdf_q_ && !b_mc_pdf_q_->TestBit(kDoNotProcess)){
    c_mc_pdf_q_ = true;
  }else{
    c_mc_pdf_q_ = false;
  }
  if(b_mc_pdf_x1_ && !b_mc_pdf_x1_->TestBit(kDoNotProcess)){
    c_mc_pdf_x1_ = true;
  }else{
    c_mc_pdf_x1_ = false;
  }
  if(b_mc_pdf_x2_ && !b_mc_pdf_x2_->TestBit(kDoNotProcess)){
    c_mc_pdf_x2_ = true;
  }else{
    c_mc_pdf_x2_ = false;
  }
  if(b_metsHO_et_ && !b_metsHO_et_->TestBit(kDoNotProcess)){
    c_metsHO_et_ = true;
  }else{
    c_metsHO_et_ = false;
  }
  if(b_metsHO_ex_ && !b_metsHO_ex_->TestBit(kDoNotProcess)){
    c_metsHO_ex_ = true;
  }else{
    c_metsHO_ex_ = false;
  }
  if(b_metsHO_ey_ && !b_metsHO_ey_->TestBit(kDoNotProcess)){
    c_metsHO_ey_ = true;
  }else{
    c_metsHO_ey_ = false;
  }
  if(b_metsHO_phi_ && !b_metsHO_phi_->TestBit(kDoNotProcess)){
    c_metsHO_phi_ = true;
  }else{
    c_metsHO_phi_ = false;
  }
  if(b_metsHO_sumEt_ && !b_metsHO_sumEt_->TestBit(kDoNotProcess)){
    c_metsHO_sumEt_ = true;
  }else{
    c_metsHO_sumEt_ = false;
  }
  if(b_mets_AK5_et_ && !b_mets_AK5_et_->TestBit(kDoNotProcess)){
    c_mets_AK5_et_ = true;
  }else{
    c_mets_AK5_et_ = false;
  }
  if(b_mets_AK5_ex_ && !b_mets_AK5_ex_->TestBit(kDoNotProcess)){
    c_mets_AK5_ex_ = true;
  }else{
    c_mets_AK5_ex_ = false;
  }
  if(b_mets_AK5_ey_ && !b_mets_AK5_ey_->TestBit(kDoNotProcess)){
    c_mets_AK5_ey_ = true;
  }else{
    c_mets_AK5_ey_ = false;
  }
  if(b_mets_AK5_gen_et_ && !b_mets_AK5_gen_et_->TestBit(kDoNotProcess)){
    c_mets_AK5_gen_et_ = true;
  }else{
    c_mets_AK5_gen_et_ = false;
  }
  if(b_mets_AK5_gen_phi_ && !b_mets_AK5_gen_phi_->TestBit(kDoNotProcess)){
    c_mets_AK5_gen_phi_ = true;
  }else{
    c_mets_AK5_gen_phi_ = false;
  }
  if(b_mets_AK5_phi_ && !b_mets_AK5_phi_->TestBit(kDoNotProcess)){
    c_mets_AK5_phi_ = true;
  }else{
    c_mets_AK5_phi_ = false;
  }
  if(b_mets_AK5_sign_ && !b_mets_AK5_sign_->TestBit(kDoNotProcess)){
    c_mets_AK5_sign_ = true;
  }else{
    c_mets_AK5_sign_ = false;
  }
  if(b_mets_AK5_sumEt_ && !b_mets_AK5_sumEt_->TestBit(kDoNotProcess)){
    c_mets_AK5_sumEt_ = true;
  }else{
    c_mets_AK5_sumEt_ = false;
  }
  if(b_mets_AK5_unCPhi_ && !b_mets_AK5_unCPhi_->TestBit(kDoNotProcess)){
    c_mets_AK5_unCPhi_ = true;
  }else{
    c_mets_AK5_unCPhi_ = false;
  }
  if(b_mets_AK5_unCPt_ && !b_mets_AK5_unCPt_->TestBit(kDoNotProcess)){
    c_mets_AK5_unCPt_ = true;
  }else{
    c_mets_AK5_unCPt_ = false;
  }
  if(b_passprescaleHT250filter_decision_ && !b_passprescaleHT250filter_decision_->TestBit(kDoNotProcess)){
    c_passprescaleHT250filter_decision_ = true;
  }else{
    c_passprescaleHT250filter_decision_ = false;
  }
  if(b_passprescaleHT300filter_decision_ && !b_passprescaleHT300filter_decision_->TestBit(kDoNotProcess)){
    c_passprescaleHT300filter_decision_ = true;
  }else{
    c_passprescaleHT300filter_decision_ = false;
  }
  if(b_passprescaleHT350filter_decision_ && !b_passprescaleHT350filter_decision_->TestBit(kDoNotProcess)){
    c_passprescaleHT350filter_decision_ = true;
  }else{
    c_passprescaleHT350filter_decision_ = false;
  }
  if(b_passprescaleHT400filter_decision_ && !b_passprescaleHT400filter_decision_->TestBit(kDoNotProcess)){
    c_passprescaleHT400filter_decision_ = true;
  }else{
    c_passprescaleHT400filter_decision_ = false;
  }
  if(b_passprescaleHT450filter_decision_ && !b_passprescaleHT450filter_decision_->TestBit(kDoNotProcess)){
    c_passprescaleHT450filter_decision_ = true;
  }else{
    c_passprescaleHT450filter_decision_ = false;
  }
  if(b_passprescaleJet30MET80filter_decision_ && !b_passprescaleJet30MET80filter_decision_->TestBit(kDoNotProcess)){
    c_passprescaleJet30MET80filter_decision_ = true;
  }else{
    c_passprescaleJet30MET80filter_decision_ = false;
  }
  if(b_passprescalePFHT350filter_decision_ && !b_passprescalePFHT350filter_decision_->TestBit(kDoNotProcess)){
    c_passprescalePFHT350filter_decision_ = true;
  }else{
    c_passprescalePFHT350filter_decision_ = false;
  }
  if(b_pdfweights_cteq_ && !b_pdfweights_cteq_->TestBit(kDoNotProcess)){
    c_pdfweights_cteq_ = true;
  }else{
    c_pdfweights_cteq_ = false;
  }
  if(b_pdfweights_mstw_ && !b_pdfweights_mstw_->TestBit(kDoNotProcess)){
    c_pdfweights_mstw_ = true;
  }else{
    c_pdfweights_mstw_ = false;
  }
  if(b_pdfweights_nnpdf_ && !b_pdfweights_nnpdf_->TestBit(kDoNotProcess)){
    c_pdfweights_nnpdf_ = true;
  }else{
    c_pdfweights_nnpdf_ = false;
  }
  if(b_pfTypeINoXYCorrmets_et_ && !b_pfTypeINoXYCorrmets_et_->TestBit(kDoNotProcess)){
    c_pfTypeINoXYCorrmets_et_ = true;
  }else{
    c_pfTypeINoXYCorrmets_et_ = false;
  }
  if(b_pfTypeINoXYCorrmets_ex_ && !b_pfTypeINoXYCorrmets_ex_->TestBit(kDoNotProcess)){
    c_pfTypeINoXYCorrmets_ex_ = true;
  }else{
    c_pfTypeINoXYCorrmets_ex_ = false;
  }
  if(b_pfTypeINoXYCorrmets_ey_ && !b_pfTypeINoXYCorrmets_ey_->TestBit(kDoNotProcess)){
    c_pfTypeINoXYCorrmets_ey_ = true;
  }else{
    c_pfTypeINoXYCorrmets_ey_ = false;
  }
  if(b_pfTypeINoXYCorrmets_gen_et_ && !b_pfTypeINoXYCorrmets_gen_et_->TestBit(kDoNotProcess)){
    c_pfTypeINoXYCorrmets_gen_et_ = true;
  }else{
    c_pfTypeINoXYCorrmets_gen_et_ = false;
  }
  if(b_pfTypeINoXYCorrmets_gen_phi_ && !b_pfTypeINoXYCorrmets_gen_phi_->TestBit(kDoNotProcess)){
    c_pfTypeINoXYCorrmets_gen_phi_ = true;
  }else{
    c_pfTypeINoXYCorrmets_gen_phi_ = false;
  }
  if(b_pfTypeINoXYCorrmets_phi_ && !b_pfTypeINoXYCorrmets_phi_->TestBit(kDoNotProcess)){
    c_pfTypeINoXYCorrmets_phi_ = true;
  }else{
    c_pfTypeINoXYCorrmets_phi_ = false;
  }
  if(b_pfTypeINoXYCorrmets_sign_ && !b_pfTypeINoXYCorrmets_sign_->TestBit(kDoNotProcess)){
    c_pfTypeINoXYCorrmets_sign_ = true;
  }else{
    c_pfTypeINoXYCorrmets_sign_ = false;
  }
  if(b_pfTypeINoXYCorrmets_sumEt_ && !b_pfTypeINoXYCorrmets_sumEt_->TestBit(kDoNotProcess)){
    c_pfTypeINoXYCorrmets_sumEt_ = true;
  }else{
    c_pfTypeINoXYCorrmets_sumEt_ = false;
  }
  if(b_pfTypeINoXYCorrmets_unCPhi_ && !b_pfTypeINoXYCorrmets_unCPhi_->TestBit(kDoNotProcess)){
    c_pfTypeINoXYCorrmets_unCPhi_ = true;
  }else{
    c_pfTypeINoXYCorrmets_unCPhi_ = false;
  }
  if(b_pfTypeINoXYCorrmets_unCPt_ && !b_pfTypeINoXYCorrmets_unCPt_->TestBit(kDoNotProcess)){
    c_pfTypeINoXYCorrmets_unCPt_ = true;
  }else{
    c_pfTypeINoXYCorrmets_unCPt_ = false;
  }
  if(b_pfTypeIType0mets_et_ && !b_pfTypeIType0mets_et_->TestBit(kDoNotProcess)){
    c_pfTypeIType0mets_et_ = true;
  }else{
    c_pfTypeIType0mets_et_ = false;
  }
  if(b_pfTypeIType0mets_ex_ && !b_pfTypeIType0mets_ex_->TestBit(kDoNotProcess)){
    c_pfTypeIType0mets_ex_ = true;
  }else{
    c_pfTypeIType0mets_ex_ = false;
  }
  if(b_pfTypeIType0mets_ey_ && !b_pfTypeIType0mets_ey_->TestBit(kDoNotProcess)){
    c_pfTypeIType0mets_ey_ = true;
  }else{
    c_pfTypeIType0mets_ey_ = false;
  }
  if(b_pfTypeIType0mets_gen_et_ && !b_pfTypeIType0mets_gen_et_->TestBit(kDoNotProcess)){
    c_pfTypeIType0mets_gen_et_ = true;
  }else{
    c_pfTypeIType0mets_gen_et_ = false;
  }
  if(b_pfTypeIType0mets_gen_phi_ && !b_pfTypeIType0mets_gen_phi_->TestBit(kDoNotProcess)){
    c_pfTypeIType0mets_gen_phi_ = true;
  }else{
    c_pfTypeIType0mets_gen_phi_ = false;
  }
  if(b_pfTypeIType0mets_phi_ && !b_pfTypeIType0mets_phi_->TestBit(kDoNotProcess)){
    c_pfTypeIType0mets_phi_ = true;
  }else{
    c_pfTypeIType0mets_phi_ = false;
  }
  if(b_pfTypeIType0mets_sign_ && !b_pfTypeIType0mets_sign_->TestBit(kDoNotProcess)){
    c_pfTypeIType0mets_sign_ = true;
  }else{
    c_pfTypeIType0mets_sign_ = false;
  }
  if(b_pfTypeIType0mets_sumEt_ && !b_pfTypeIType0mets_sumEt_->TestBit(kDoNotProcess)){
    c_pfTypeIType0mets_sumEt_ = true;
  }else{
    c_pfTypeIType0mets_sumEt_ = false;
  }
  if(b_pfTypeIType0mets_unCPhi_ && !b_pfTypeIType0mets_unCPhi_->TestBit(kDoNotProcess)){
    c_pfTypeIType0mets_unCPhi_ = true;
  }else{
    c_pfTypeIType0mets_unCPhi_ = false;
  }
  if(b_pfTypeIType0mets_unCPt_ && !b_pfTypeIType0mets_unCPt_->TestBit(kDoNotProcess)){
    c_pfTypeIType0mets_unCPt_ = true;
  }else{
    c_pfTypeIType0mets_unCPt_ = false;
  }
  if(b_pfTypeImets_et_ && !b_pfTypeImets_et_->TestBit(kDoNotProcess)){
    c_pfTypeImets_et_ = true;
  }else{
    c_pfTypeImets_et_ = false;
  }
  if(b_pfTypeImets_ex_ && !b_pfTypeImets_ex_->TestBit(kDoNotProcess)){
    c_pfTypeImets_ex_ = true;
  }else{
    c_pfTypeImets_ex_ = false;
  }
  if(b_pfTypeImets_ey_ && !b_pfTypeImets_ey_->TestBit(kDoNotProcess)){
    c_pfTypeImets_ey_ = true;
  }else{
    c_pfTypeImets_ey_ = false;
  }
  if(b_pfTypeImets_gen_et_ && !b_pfTypeImets_gen_et_->TestBit(kDoNotProcess)){
    c_pfTypeImets_gen_et_ = true;
  }else{
    c_pfTypeImets_gen_et_ = false;
  }
  if(b_pfTypeImets_gen_phi_ && !b_pfTypeImets_gen_phi_->TestBit(kDoNotProcess)){
    c_pfTypeImets_gen_phi_ = true;
  }else{
    c_pfTypeImets_gen_phi_ = false;
  }
  if(b_pfTypeImets_phi_ && !b_pfTypeImets_phi_->TestBit(kDoNotProcess)){
    c_pfTypeImets_phi_ = true;
  }else{
    c_pfTypeImets_phi_ = false;
  }
  if(b_pfTypeImets_sign_ && !b_pfTypeImets_sign_->TestBit(kDoNotProcess)){
    c_pfTypeImets_sign_ = true;
  }else{
    c_pfTypeImets_sign_ = false;
  }
  if(b_pfTypeImets_sumEt_ && !b_pfTypeImets_sumEt_->TestBit(kDoNotProcess)){
    c_pfTypeImets_sumEt_ = true;
  }else{
    c_pfTypeImets_sumEt_ = false;
  }
  if(b_pfTypeImets_unCPhi_ && !b_pfTypeImets_unCPhi_->TestBit(kDoNotProcess)){
    c_pfTypeImets_unCPhi_ = true;
  }else{
    c_pfTypeImets_unCPhi_ = false;
  }
  if(b_pfTypeImets_unCPt_ && !b_pfTypeImets_unCPt_->TestBit(kDoNotProcess)){
    c_pfTypeImets_unCPt_ = true;
  }else{
    c_pfTypeImets_unCPt_ = false;
  }
  if(b_pf_els_PATpassConversionVeto_ && !b_pf_els_PATpassConversionVeto_->TestBit(kDoNotProcess)){
    c_pf_els_PATpassConversionVeto_ = true;
  }else{
    c_pf_els_PATpassConversionVeto_ = false;
  }
  if(b_pf_els_PFchargedHadronIsoR03_ && !b_pf_els_PFchargedHadronIsoR03_->TestBit(kDoNotProcess)){
    c_pf_els_PFchargedHadronIsoR03_ = true;
  }else{
    c_pf_els_PFchargedHadronIsoR03_ = false;
  }
  if(b_pf_els_PFneutralHadronIsoR03_ && !b_pf_els_PFneutralHadronIsoR03_->TestBit(kDoNotProcess)){
    c_pf_els_PFneutralHadronIsoR03_ = true;
  }else{
    c_pf_els_PFneutralHadronIsoR03_ = false;
  }
  if(b_pf_els_PFphotonIsoR03_ && !b_pf_els_PFphotonIsoR03_->TestBit(kDoNotProcess)){
    c_pf_els_PFphotonIsoR03_ = true;
  }else{
    c_pf_els_PFphotonIsoR03_ = false;
  }
  if(b_pf_els_basicClustersSize_ && !b_pf_els_basicClustersSize_->TestBit(kDoNotProcess)){
    c_pf_els_basicClustersSize_ = true;
  }else{
    c_pf_els_basicClustersSize_ = false;
  }
  if(b_pf_els_cIso_ && !b_pf_els_cIso_->TestBit(kDoNotProcess)){
    c_pf_els_cIso_ = true;
  }else{
    c_pf_els_cIso_ = false;
  }
  if(b_pf_els_caloEnergy_ && !b_pf_els_caloEnergy_->TestBit(kDoNotProcess)){
    c_pf_els_caloEnergy_ = true;
  }else{
    c_pf_els_caloEnergy_ = false;
  }
  if(b_pf_els_charge_ && !b_pf_els_charge_->TestBit(kDoNotProcess)){
    c_pf_els_charge_ = true;
  }else{
    c_pf_els_charge_ = false;
  }
  if(b_pf_els_chargedHadronIso_ && !b_pf_els_chargedHadronIso_->TestBit(kDoNotProcess)){
    c_pf_els_chargedHadronIso_ = true;
  }else{
    c_pf_els_chargedHadronIso_ = false;
  }
  if(b_pf_els_chi2_ && !b_pf_els_chi2_->TestBit(kDoNotProcess)){
    c_pf_els_chi2_ = true;
  }else{
    c_pf_els_chi2_ = false;
  }
  if(b_pf_els_core_ecalDrivenSeed_ && !b_pf_els_core_ecalDrivenSeed_->TestBit(kDoNotProcess)){
    c_pf_els_core_ecalDrivenSeed_ = true;
  }else{
    c_pf_els_core_ecalDrivenSeed_ = false;
  }
  if(b_pf_els_cpx_ && !b_pf_els_cpx_->TestBit(kDoNotProcess)){
    c_pf_els_cpx_ = true;
  }else{
    c_pf_els_cpx_ = false;
  }
  if(b_pf_els_cpy_ && !b_pf_els_cpy_->TestBit(kDoNotProcess)){
    c_pf_els_cpy_ = true;
  }else{
    c_pf_els_cpy_ = false;
  }
  if(b_pf_els_cpz_ && !b_pf_els_cpz_->TestBit(kDoNotProcess)){
    c_pf_els_cpz_ = true;
  }else{
    c_pf_els_cpz_ = false;
  }
  if(b_pf_els_ctf_tk_charge_ && !b_pf_els_ctf_tk_charge_->TestBit(kDoNotProcess)){
    c_pf_els_ctf_tk_charge_ = true;
  }else{
    c_pf_els_ctf_tk_charge_ = false;
  }
  if(b_pf_els_ctf_tk_eta_ && !b_pf_els_ctf_tk_eta_->TestBit(kDoNotProcess)){
    c_pf_els_ctf_tk_eta_ = true;
  }else{
    c_pf_els_ctf_tk_eta_ = false;
  }
  if(b_pf_els_ctf_tk_id_ && !b_pf_els_ctf_tk_id_->TestBit(kDoNotProcess)){
    c_pf_els_ctf_tk_id_ = true;
  }else{
    c_pf_els_ctf_tk_id_ = false;
  }
  if(b_pf_els_ctf_tk_phi_ && !b_pf_els_ctf_tk_phi_->TestBit(kDoNotProcess)){
    c_pf_els_ctf_tk_phi_ = true;
  }else{
    c_pf_els_ctf_tk_phi_ = false;
  }
  if(b_pf_els_cx_ && !b_pf_els_cx_->TestBit(kDoNotProcess)){
    c_pf_els_cx_ = true;
  }else{
    c_pf_els_cx_ = false;
  }
  if(b_pf_els_cy_ && !b_pf_els_cy_->TestBit(kDoNotProcess)){
    c_pf_els_cy_ = true;
  }else{
    c_pf_els_cy_ = false;
  }
  if(b_pf_els_cz_ && !b_pf_els_cz_->TestBit(kDoNotProcess)){
    c_pf_els_cz_ = true;
  }else{
    c_pf_els_cz_ = false;
  }
  if(b_pf_els_d0dum_ && !b_pf_els_d0dum_->TestBit(kDoNotProcess)){
    c_pf_els_d0dum_ = true;
  }else{
    c_pf_els_d0dum_ = false;
  }
  if(b_pf_els_d0dumError_ && !b_pf_els_d0dumError_->TestBit(kDoNotProcess)){
    c_pf_els_d0dumError_ = true;
  }else{
    c_pf_els_d0dumError_ = false;
  }
  if(b_pf_els_dEtaIn_ && !b_pf_els_dEtaIn_->TestBit(kDoNotProcess)){
    c_pf_els_dEtaIn_ = true;
  }else{
    c_pf_els_dEtaIn_ = false;
  }
  if(b_pf_els_dEtaOut_ && !b_pf_els_dEtaOut_->TestBit(kDoNotProcess)){
    c_pf_els_dEtaOut_ = true;
  }else{
    c_pf_els_dEtaOut_ = false;
  }
  if(b_pf_els_dPhiIn_ && !b_pf_els_dPhiIn_->TestBit(kDoNotProcess)){
    c_pf_els_dPhiIn_ = true;
  }else{
    c_pf_els_dPhiIn_ = false;
  }
  if(b_pf_els_dPhiOut_ && !b_pf_els_dPhiOut_->TestBit(kDoNotProcess)){
    c_pf_els_dPhiOut_ = true;
  }else{
    c_pf_els_dPhiOut_ = false;
  }
  if(b_pf_els_dr03EcalRecHitSumEt_ && !b_pf_els_dr03EcalRecHitSumEt_->TestBit(kDoNotProcess)){
    c_pf_els_dr03EcalRecHitSumEt_ = true;
  }else{
    c_pf_els_dr03EcalRecHitSumEt_ = false;
  }
  if(b_pf_els_dr03HcalDepth1TowerSumEt_ && !b_pf_els_dr03HcalDepth1TowerSumEt_->TestBit(kDoNotProcess)){
    c_pf_els_dr03HcalDepth1TowerSumEt_ = true;
  }else{
    c_pf_els_dr03HcalDepth1TowerSumEt_ = false;
  }
  if(b_pf_els_dr03HcalDepth2TowerSumEt_ && !b_pf_els_dr03HcalDepth2TowerSumEt_->TestBit(kDoNotProcess)){
    c_pf_els_dr03HcalDepth2TowerSumEt_ = true;
  }else{
    c_pf_els_dr03HcalDepth2TowerSumEt_ = false;
  }
  if(b_pf_els_dr03HcalTowerSumEt_ && !b_pf_els_dr03HcalTowerSumEt_->TestBit(kDoNotProcess)){
    c_pf_els_dr03HcalTowerSumEt_ = true;
  }else{
    c_pf_els_dr03HcalTowerSumEt_ = false;
  }
  if(b_pf_els_dr03TkSumPt_ && !b_pf_els_dr03TkSumPt_->TestBit(kDoNotProcess)){
    c_pf_els_dr03TkSumPt_ = true;
  }else{
    c_pf_els_dr03TkSumPt_ = false;
  }
  if(b_pf_els_dr04EcalRecHitSumEt_ && !b_pf_els_dr04EcalRecHitSumEt_->TestBit(kDoNotProcess)){
    c_pf_els_dr04EcalRecHitSumEt_ = true;
  }else{
    c_pf_els_dr04EcalRecHitSumEt_ = false;
  }
  if(b_pf_els_dr04HcalDepth1TowerSumEt_ && !b_pf_els_dr04HcalDepth1TowerSumEt_->TestBit(kDoNotProcess)){
    c_pf_els_dr04HcalDepth1TowerSumEt_ = true;
  }else{
    c_pf_els_dr04HcalDepth1TowerSumEt_ = false;
  }
  if(b_pf_els_dr04HcalDepth2TowerSumEt_ && !b_pf_els_dr04HcalDepth2TowerSumEt_->TestBit(kDoNotProcess)){
    c_pf_els_dr04HcalDepth2TowerSumEt_ = true;
  }else{
    c_pf_els_dr04HcalDepth2TowerSumEt_ = false;
  }
  if(b_pf_els_dr04HcalTowerSumEt_ && !b_pf_els_dr04HcalTowerSumEt_->TestBit(kDoNotProcess)){
    c_pf_els_dr04HcalTowerSumEt_ = true;
  }else{
    c_pf_els_dr04HcalTowerSumEt_ = false;
  }
  if(b_pf_els_dr04TkSumPt_ && !b_pf_els_dr04TkSumPt_->TestBit(kDoNotProcess)){
    c_pf_els_dr04TkSumPt_ = true;
  }else{
    c_pf_els_dr04TkSumPt_ = false;
  }
  if(b_pf_els_dz_ && !b_pf_els_dz_->TestBit(kDoNotProcess)){
    c_pf_els_dz_ = true;
  }else{
    c_pf_els_dz_ = false;
  }
  if(b_pf_els_dzError_ && !b_pf_els_dzError_->TestBit(kDoNotProcess)){
    c_pf_els_dzError_ = true;
  }else{
    c_pf_els_dzError_ = false;
  }
  if(b_pf_els_eOverPIn_ && !b_pf_els_eOverPIn_->TestBit(kDoNotProcess)){
    c_pf_els_eOverPIn_ = true;
  }else{
    c_pf_els_eOverPIn_ = false;
  }
  if(b_pf_els_eSeedOverPOut_ && !b_pf_els_eSeedOverPOut_->TestBit(kDoNotProcess)){
    c_pf_els_eSeedOverPOut_ = true;
  }else{
    c_pf_els_eSeedOverPOut_ = false;
  }
  if(b_pf_els_ecalIso_ && !b_pf_els_ecalIso_->TestBit(kDoNotProcess)){
    c_pf_els_ecalIso_ = true;
  }else{
    c_pf_els_ecalIso_ = false;
  }
  if(b_pf_els_energy_ && !b_pf_els_energy_->TestBit(kDoNotProcess)){
    c_pf_els_energy_ = true;
  }else{
    c_pf_els_energy_ = false;
  }
  if(b_pf_els_et_ && !b_pf_els_et_->TestBit(kDoNotProcess)){
    c_pf_els_et_ = true;
  }else{
    c_pf_els_et_ = false;
  }
  if(b_pf_els_eta_ && !b_pf_els_eta_->TestBit(kDoNotProcess)){
    c_pf_els_eta_ = true;
  }else{
    c_pf_els_eta_ = false;
  }
  if(b_pf_els_etaError_ && !b_pf_els_etaError_->TestBit(kDoNotProcess)){
    c_pf_els_etaError_ = true;
  }else{
    c_pf_els_etaError_ = false;
  }
  if(b_pf_els_fbrem_ && !b_pf_els_fbrem_->TestBit(kDoNotProcess)){
    c_pf_els_fbrem_ = true;
  }else{
    c_pf_els_fbrem_ = false;
  }
  if(b_pf_els_gen_et_ && !b_pf_els_gen_et_->TestBit(kDoNotProcess)){
    c_pf_els_gen_et_ = true;
  }else{
    c_pf_els_gen_et_ = false;
  }
  if(b_pf_els_gen_eta_ && !b_pf_els_gen_eta_->TestBit(kDoNotProcess)){
    c_pf_els_gen_eta_ = true;
  }else{
    c_pf_els_gen_eta_ = false;
  }
  if(b_pf_els_gen_id_ && !b_pf_els_gen_id_->TestBit(kDoNotProcess)){
    c_pf_els_gen_id_ = true;
  }else{
    c_pf_els_gen_id_ = false;
  }
  if(b_pf_els_gen_mother_et_ && !b_pf_els_gen_mother_et_->TestBit(kDoNotProcess)){
    c_pf_els_gen_mother_et_ = true;
  }else{
    c_pf_els_gen_mother_et_ = false;
  }
  if(b_pf_els_gen_mother_eta_ && !b_pf_els_gen_mother_eta_->TestBit(kDoNotProcess)){
    c_pf_els_gen_mother_eta_ = true;
  }else{
    c_pf_els_gen_mother_eta_ = false;
  }
  if(b_pf_els_gen_mother_id_ && !b_pf_els_gen_mother_id_->TestBit(kDoNotProcess)){
    c_pf_els_gen_mother_id_ = true;
  }else{
    c_pf_els_gen_mother_id_ = false;
  }
  if(b_pf_els_gen_mother_phi_ && !b_pf_els_gen_mother_phi_->TestBit(kDoNotProcess)){
    c_pf_els_gen_mother_phi_ = true;
  }else{
    c_pf_els_gen_mother_phi_ = false;
  }
  if(b_pf_els_gen_mother_pt_ && !b_pf_els_gen_mother_pt_->TestBit(kDoNotProcess)){
    c_pf_els_gen_mother_pt_ = true;
  }else{
    c_pf_els_gen_mother_pt_ = false;
  }
  if(b_pf_els_gen_mother_px_ && !b_pf_els_gen_mother_px_->TestBit(kDoNotProcess)){
    c_pf_els_gen_mother_px_ = true;
  }else{
    c_pf_els_gen_mother_px_ = false;
  }
  if(b_pf_els_gen_mother_py_ && !b_pf_els_gen_mother_py_->TestBit(kDoNotProcess)){
    c_pf_els_gen_mother_py_ = true;
  }else{
    c_pf_els_gen_mother_py_ = false;
  }
  if(b_pf_els_gen_mother_pz_ && !b_pf_els_gen_mother_pz_->TestBit(kDoNotProcess)){
    c_pf_els_gen_mother_pz_ = true;
  }else{
    c_pf_els_gen_mother_pz_ = false;
  }
  if(b_pf_els_gen_mother_theta_ && !b_pf_els_gen_mother_theta_->TestBit(kDoNotProcess)){
    c_pf_els_gen_mother_theta_ = true;
  }else{
    c_pf_els_gen_mother_theta_ = false;
  }
  if(b_pf_els_gen_phi_ && !b_pf_els_gen_phi_->TestBit(kDoNotProcess)){
    c_pf_els_gen_phi_ = true;
  }else{
    c_pf_els_gen_phi_ = false;
  }
  if(b_pf_els_gen_pt_ && !b_pf_els_gen_pt_->TestBit(kDoNotProcess)){
    c_pf_els_gen_pt_ = true;
  }else{
    c_pf_els_gen_pt_ = false;
  }
  if(b_pf_els_gen_px_ && !b_pf_els_gen_px_->TestBit(kDoNotProcess)){
    c_pf_els_gen_px_ = true;
  }else{
    c_pf_els_gen_px_ = false;
  }
  if(b_pf_els_gen_py_ && !b_pf_els_gen_py_->TestBit(kDoNotProcess)){
    c_pf_els_gen_py_ = true;
  }else{
    c_pf_els_gen_py_ = false;
  }
  if(b_pf_els_gen_pz_ && !b_pf_els_gen_pz_->TestBit(kDoNotProcess)){
    c_pf_els_gen_pz_ = true;
  }else{
    c_pf_els_gen_pz_ = false;
  }
  if(b_pf_els_gen_theta_ && !b_pf_els_gen_theta_->TestBit(kDoNotProcess)){
    c_pf_els_gen_theta_ = true;
  }else{
    c_pf_els_gen_theta_ = false;
  }
  if(b_pf_els_hadOverEm_ && !b_pf_els_hadOverEm_->TestBit(kDoNotProcess)){
    c_pf_els_hadOverEm_ = true;
  }else{
    c_pf_els_hadOverEm_ = false;
  }
  if(b_pf_els_hasMatchedConversion_ && !b_pf_els_hasMatchedConversion_->TestBit(kDoNotProcess)){
    c_pf_els_hasMatchedConversion_ = true;
  }else{
    c_pf_els_hasMatchedConversion_ = false;
  }
  if(b_pf_els_hcalIso_ && !b_pf_els_hcalIso_->TestBit(kDoNotProcess)){
    c_pf_els_hcalIso_ = true;
  }else{
    c_pf_els_hcalIso_ = false;
  }
  if(b_pf_els_hcalOverEcalBc_ && !b_pf_els_hcalOverEcalBc_->TestBit(kDoNotProcess)){
    c_pf_els_hcalOverEcalBc_ = true;
  }else{
    c_pf_els_hcalOverEcalBc_ = false;
  }
  if(b_pf_els_isEB_ && !b_pf_els_isEB_->TestBit(kDoNotProcess)){
    c_pf_els_isEB_ = true;
  }else{
    c_pf_els_isEB_ = false;
  }
  if(b_pf_els_isEE_ && !b_pf_els_isEE_->TestBit(kDoNotProcess)){
    c_pf_els_isEE_ = true;
  }else{
    c_pf_els_isEE_ = false;
  }
  if(b_pf_els_looseId_ && !b_pf_els_looseId_->TestBit(kDoNotProcess)){
    c_pf_els_looseId_ = true;
  }else{
    c_pf_els_looseId_ = false;
  }
  if(b_pf_els_n_inner_layer_ && !b_pf_els_n_inner_layer_->TestBit(kDoNotProcess)){
    c_pf_els_n_inner_layer_ = true;
  }else{
    c_pf_els_n_inner_layer_ = false;
  }
  if(b_pf_els_n_outer_layer_ && !b_pf_els_n_outer_layer_->TestBit(kDoNotProcess)){
    c_pf_els_n_outer_layer_ = true;
  }else{
    c_pf_els_n_outer_layer_ = false;
  }
  if(b_pf_els_ndof_ && !b_pf_els_ndof_->TestBit(kDoNotProcess)){
    c_pf_els_ndof_ = true;
  }else{
    c_pf_els_ndof_ = false;
  }
  if(b_pf_els_neutralHadronIso_ && !b_pf_els_neutralHadronIso_->TestBit(kDoNotProcess)){
    c_pf_els_neutralHadronIso_ = true;
  }else{
    c_pf_els_neutralHadronIso_ = false;
  }
  if(b_pf_els_numlosthits_ && !b_pf_els_numlosthits_->TestBit(kDoNotProcess)){
    c_pf_els_numlosthits_ = true;
  }else{
    c_pf_els_numlosthits_ = false;
  }
  if(b_pf_els_numvalhits_ && !b_pf_els_numvalhits_->TestBit(kDoNotProcess)){
    c_pf_els_numvalhits_ = true;
  }else{
    c_pf_els_numvalhits_ = false;
  }
  if(b_pf_els_phi_ && !b_pf_els_phi_->TestBit(kDoNotProcess)){
    c_pf_els_phi_ = true;
  }else{
    c_pf_els_phi_ = false;
  }
  if(b_pf_els_phiError_ && !b_pf_els_phiError_->TestBit(kDoNotProcess)){
    c_pf_els_phiError_ = true;
  }else{
    c_pf_els_phiError_ = false;
  }
  if(b_pf_els_photonIso_ && !b_pf_els_photonIso_->TestBit(kDoNotProcess)){
    c_pf_els_photonIso_ = true;
  }else{
    c_pf_els_photonIso_ = false;
  }
  if(b_pf_els_pt_ && !b_pf_els_pt_->TestBit(kDoNotProcess)){
    c_pf_els_pt_ = true;
  }else{
    c_pf_els_pt_ = false;
  }
  if(b_pf_els_ptError_ && !b_pf_els_ptError_->TestBit(kDoNotProcess)){
    c_pf_els_ptError_ = true;
  }else{
    c_pf_els_ptError_ = false;
  }
  if(b_pf_els_px_ && !b_pf_els_px_->TestBit(kDoNotProcess)){
    c_pf_els_px_ = true;
  }else{
    c_pf_els_px_ = false;
  }
  if(b_pf_els_py_ && !b_pf_els_py_->TestBit(kDoNotProcess)){
    c_pf_els_py_ = true;
  }else{
    c_pf_els_py_ = false;
  }
  if(b_pf_els_pz_ && !b_pf_els_pz_->TestBit(kDoNotProcess)){
    c_pf_els_pz_ = true;
  }else{
    c_pf_els_pz_ = false;
  }
  if(b_pf_els_robustHighEnergyId_ && !b_pf_els_robustHighEnergyId_->TestBit(kDoNotProcess)){
    c_pf_els_robustHighEnergyId_ = true;
  }else{
    c_pf_els_robustHighEnergyId_ = false;
  }
  if(b_pf_els_robustLooseId_ && !b_pf_els_robustLooseId_->TestBit(kDoNotProcess)){
    c_pf_els_robustLooseId_ = true;
  }else{
    c_pf_els_robustLooseId_ = false;
  }
  if(b_pf_els_robustTightId_ && !b_pf_els_robustTightId_->TestBit(kDoNotProcess)){
    c_pf_els_robustTightId_ = true;
  }else{
    c_pf_els_robustTightId_ = false;
  }
  if(b_pf_els_scE1x5_ && !b_pf_els_scE1x5_->TestBit(kDoNotProcess)){
    c_pf_els_scE1x5_ = true;
  }else{
    c_pf_els_scE1x5_ = false;
  }
  if(b_pf_els_scE2x5Max_ && !b_pf_els_scE2x5Max_->TestBit(kDoNotProcess)){
    c_pf_els_scE2x5Max_ = true;
  }else{
    c_pf_els_scE2x5Max_ = false;
  }
  if(b_pf_els_scE5x5_ && !b_pf_els_scE5x5_->TestBit(kDoNotProcess)){
    c_pf_els_scE5x5_ = true;
  }else{
    c_pf_els_scE5x5_ = false;
  }
  if(b_pf_els_scEnergy_ && !b_pf_els_scEnergy_->TestBit(kDoNotProcess)){
    c_pf_els_scEnergy_ = true;
  }else{
    c_pf_els_scEnergy_ = false;
  }
  if(b_pf_els_scEta_ && !b_pf_els_scEta_->TestBit(kDoNotProcess)){
    c_pf_els_scEta_ = true;
  }else{
    c_pf_els_scEta_ = false;
  }
  if(b_pf_els_scEtaWidth_ && !b_pf_els_scEtaWidth_->TestBit(kDoNotProcess)){
    c_pf_els_scEtaWidth_ = true;
  }else{
    c_pf_els_scEtaWidth_ = false;
  }
  if(b_pf_els_scPhi_ && !b_pf_els_scPhi_->TestBit(kDoNotProcess)){
    c_pf_els_scPhi_ = true;
  }else{
    c_pf_els_scPhi_ = false;
  }
  if(b_pf_els_scPhiWidth_ && !b_pf_els_scPhiWidth_->TestBit(kDoNotProcess)){
    c_pf_els_scPhiWidth_ = true;
  }else{
    c_pf_els_scPhiWidth_ = false;
  }
  if(b_pf_els_scRawEnergy_ && !b_pf_els_scRawEnergy_->TestBit(kDoNotProcess)){
    c_pf_els_scRawEnergy_ = true;
  }else{
    c_pf_els_scRawEnergy_ = false;
  }
  if(b_pf_els_scSeedEnergy_ && !b_pf_els_scSeedEnergy_->TestBit(kDoNotProcess)){
    c_pf_els_scSeedEnergy_ = true;
  }else{
    c_pf_els_scSeedEnergy_ = false;
  }
  if(b_pf_els_shFracInnerHits_ && !b_pf_els_shFracInnerHits_->TestBit(kDoNotProcess)){
    c_pf_els_shFracInnerHits_ = true;
  }else{
    c_pf_els_shFracInnerHits_ = false;
  }
  if(b_pf_els_sigmaEtaEta_ && !b_pf_els_sigmaEtaEta_->TestBit(kDoNotProcess)){
    c_pf_els_sigmaEtaEta_ = true;
  }else{
    c_pf_els_sigmaEtaEta_ = false;
  }
  if(b_pf_els_sigmaIEtaIEta_ && !b_pf_els_sigmaIEtaIEta_->TestBit(kDoNotProcess)){
    c_pf_els_sigmaIEtaIEta_ = true;
  }else{
    c_pf_els_sigmaIEtaIEta_ = false;
  }
  if(b_pf_els_simpleEleId60cIso_ && !b_pf_els_simpleEleId60cIso_->TestBit(kDoNotProcess)){
    c_pf_els_simpleEleId60cIso_ = true;
  }else{
    c_pf_els_simpleEleId60cIso_ = false;
  }
  if(b_pf_els_simpleEleId60relIso_ && !b_pf_els_simpleEleId60relIso_->TestBit(kDoNotProcess)){
    c_pf_els_simpleEleId60relIso_ = true;
  }else{
    c_pf_els_simpleEleId60relIso_ = false;
  }
  if(b_pf_els_simpleEleId70cIso_ && !b_pf_els_simpleEleId70cIso_->TestBit(kDoNotProcess)){
    c_pf_els_simpleEleId70cIso_ = true;
  }else{
    c_pf_els_simpleEleId70cIso_ = false;
  }
  if(b_pf_els_simpleEleId70relIso_ && !b_pf_els_simpleEleId70relIso_->TestBit(kDoNotProcess)){
    c_pf_els_simpleEleId70relIso_ = true;
  }else{
    c_pf_els_simpleEleId70relIso_ = false;
  }
  if(b_pf_els_simpleEleId80cIso_ && !b_pf_els_simpleEleId80cIso_->TestBit(kDoNotProcess)){
    c_pf_els_simpleEleId80cIso_ = true;
  }else{
    c_pf_els_simpleEleId80cIso_ = false;
  }
  if(b_pf_els_simpleEleId80relIso_ && !b_pf_els_simpleEleId80relIso_->TestBit(kDoNotProcess)){
    c_pf_els_simpleEleId80relIso_ = true;
  }else{
    c_pf_els_simpleEleId80relIso_ = false;
  }
  if(b_pf_els_simpleEleId85cIso_ && !b_pf_els_simpleEleId85cIso_->TestBit(kDoNotProcess)){
    c_pf_els_simpleEleId85cIso_ = true;
  }else{
    c_pf_els_simpleEleId85cIso_ = false;
  }
  if(b_pf_els_simpleEleId85relIso_ && !b_pf_els_simpleEleId85relIso_->TestBit(kDoNotProcess)){
    c_pf_els_simpleEleId85relIso_ = true;
  }else{
    c_pf_els_simpleEleId85relIso_ = false;
  }
  if(b_pf_els_simpleEleId90cIso_ && !b_pf_els_simpleEleId90cIso_->TestBit(kDoNotProcess)){
    c_pf_els_simpleEleId90cIso_ = true;
  }else{
    c_pf_els_simpleEleId90cIso_ = false;
  }
  if(b_pf_els_simpleEleId90relIso_ && !b_pf_els_simpleEleId90relIso_->TestBit(kDoNotProcess)){
    c_pf_els_simpleEleId90relIso_ = true;
  }else{
    c_pf_els_simpleEleId90relIso_ = false;
  }
  if(b_pf_els_simpleEleId95cIso_ && !b_pf_els_simpleEleId95cIso_->TestBit(kDoNotProcess)){
    c_pf_els_simpleEleId95cIso_ = true;
  }else{
    c_pf_els_simpleEleId95cIso_ = false;
  }
  if(b_pf_els_simpleEleId95relIso_ && !b_pf_els_simpleEleId95relIso_->TestBit(kDoNotProcess)){
    c_pf_els_simpleEleId95relIso_ = true;
  }else{
    c_pf_els_simpleEleId95relIso_ = false;
  }
  if(b_pf_els_status_ && !b_pf_els_status_->TestBit(kDoNotProcess)){
    c_pf_els_status_ = true;
  }else{
    c_pf_els_status_ = false;
  }
  if(b_pf_els_tIso_ && !b_pf_els_tIso_->TestBit(kDoNotProcess)){
    c_pf_els_tIso_ = true;
  }else{
    c_pf_els_tIso_ = false;
  }
  if(b_pf_els_theta_ && !b_pf_els_theta_->TestBit(kDoNotProcess)){
    c_pf_els_theta_ = true;
  }else{
    c_pf_els_theta_ = false;
  }
  if(b_pf_els_tightId_ && !b_pf_els_tightId_->TestBit(kDoNotProcess)){
    c_pf_els_tightId_ = true;
  }else{
    c_pf_els_tightId_ = false;
  }
  if(b_pf_els_tk_charge_ && !b_pf_els_tk_charge_->TestBit(kDoNotProcess)){
    c_pf_els_tk_charge_ = true;
  }else{
    c_pf_els_tk_charge_ = false;
  }
  if(b_pf_els_tk_eta_ && !b_pf_els_tk_eta_->TestBit(kDoNotProcess)){
    c_pf_els_tk_eta_ = true;
  }else{
    c_pf_els_tk_eta_ = false;
  }
  if(b_pf_els_tk_phi_ && !b_pf_els_tk_phi_->TestBit(kDoNotProcess)){
    c_pf_els_tk_phi_ = true;
  }else{
    c_pf_els_tk_phi_ = false;
  }
  if(b_pf_els_tk_pt_ && !b_pf_els_tk_pt_->TestBit(kDoNotProcess)){
    c_pf_els_tk_pt_ = true;
  }else{
    c_pf_els_tk_pt_ = false;
  }
  if(b_pf_els_tk_pz_ && !b_pf_els_tk_pz_->TestBit(kDoNotProcess)){
    c_pf_els_tk_pz_ = true;
  }else{
    c_pf_els_tk_pz_ = false;
  }
  if(b_pf_els_vpx_ && !b_pf_els_vpx_->TestBit(kDoNotProcess)){
    c_pf_els_vpx_ = true;
  }else{
    c_pf_els_vpx_ = false;
  }
  if(b_pf_els_vpy_ && !b_pf_els_vpy_->TestBit(kDoNotProcess)){
    c_pf_els_vpy_ = true;
  }else{
    c_pf_els_vpy_ = false;
  }
  if(b_pf_els_vpz_ && !b_pf_els_vpz_->TestBit(kDoNotProcess)){
    c_pf_els_vpz_ = true;
  }else{
    c_pf_els_vpz_ = false;
  }
  if(b_pf_els_vx_ && !b_pf_els_vx_->TestBit(kDoNotProcess)){
    c_pf_els_vx_ = true;
  }else{
    c_pf_els_vx_ = false;
  }
  if(b_pf_els_vy_ && !b_pf_els_vy_->TestBit(kDoNotProcess)){
    c_pf_els_vy_ = true;
  }else{
    c_pf_els_vy_ = false;
  }
  if(b_pf_els_vz_ && !b_pf_els_vz_->TestBit(kDoNotProcess)){
    c_pf_els_vz_ = true;
  }else{
    c_pf_els_vz_ = false;
  }
  if(b_pf_mus_cIso_ && !b_pf_mus_cIso_->TestBit(kDoNotProcess)){
    c_pf_mus_cIso_ = true;
  }else{
    c_pf_mus_cIso_ = false;
  }
  if(b_pf_mus_calEnergyEm_ && !b_pf_mus_calEnergyEm_->TestBit(kDoNotProcess)){
    c_pf_mus_calEnergyEm_ = true;
  }else{
    c_pf_mus_calEnergyEm_ = false;
  }
  if(b_pf_mus_calEnergyEmS9_ && !b_pf_mus_calEnergyEmS9_->TestBit(kDoNotProcess)){
    c_pf_mus_calEnergyEmS9_ = true;
  }else{
    c_pf_mus_calEnergyEmS9_ = false;
  }
  if(b_pf_mus_calEnergyHad_ && !b_pf_mus_calEnergyHad_->TestBit(kDoNotProcess)){
    c_pf_mus_calEnergyHad_ = true;
  }else{
    c_pf_mus_calEnergyHad_ = false;
  }
  if(b_pf_mus_calEnergyHadS9_ && !b_pf_mus_calEnergyHadS9_->TestBit(kDoNotProcess)){
    c_pf_mus_calEnergyHadS9_ = true;
  }else{
    c_pf_mus_calEnergyHadS9_ = false;
  }
  if(b_pf_mus_calEnergyHo_ && !b_pf_mus_calEnergyHo_->TestBit(kDoNotProcess)){
    c_pf_mus_calEnergyHo_ = true;
  }else{
    c_pf_mus_calEnergyHo_ = false;
  }
  if(b_pf_mus_calEnergyHoS9_ && !b_pf_mus_calEnergyHoS9_->TestBit(kDoNotProcess)){
    c_pf_mus_calEnergyHoS9_ = true;
  }else{
    c_pf_mus_calEnergyHoS9_ = false;
  }
  if(b_pf_mus_charge_ && !b_pf_mus_charge_->TestBit(kDoNotProcess)){
    c_pf_mus_charge_ = true;
  }else{
    c_pf_mus_charge_ = false;
  }
  if(b_pf_mus_chargedHadronIso_ && !b_pf_mus_chargedHadronIso_->TestBit(kDoNotProcess)){
    c_pf_mus_chargedHadronIso_ = true;
  }else{
    c_pf_mus_chargedHadronIso_ = false;
  }
  if(b_pf_mus_cm_ExpectedHitsInner_ && !b_pf_mus_cm_ExpectedHitsInner_->TestBit(kDoNotProcess)){
    c_pf_mus_cm_ExpectedHitsInner_ = true;
  }else{
    c_pf_mus_cm_ExpectedHitsInner_ = false;
  }
  if(b_pf_mus_cm_ExpectedHitsOuter_ && !b_pf_mus_cm_ExpectedHitsOuter_->TestBit(kDoNotProcess)){
    c_pf_mus_cm_ExpectedHitsOuter_ = true;
  }else{
    c_pf_mus_cm_ExpectedHitsOuter_ = false;
  }
  if(b_pf_mus_cm_LayersWithMeasurement_ && !b_pf_mus_cm_LayersWithMeasurement_->TestBit(kDoNotProcess)){
    c_pf_mus_cm_LayersWithMeasurement_ = true;
  }else{
    c_pf_mus_cm_LayersWithMeasurement_ = false;
  }
  if(b_pf_mus_cm_LayersWithoutMeasurement_ && !b_pf_mus_cm_LayersWithoutMeasurement_->TestBit(kDoNotProcess)){
    c_pf_mus_cm_LayersWithoutMeasurement_ = true;
  }else{
    c_pf_mus_cm_LayersWithoutMeasurement_ = false;
  }
  if(b_pf_mus_cm_PixelLayersWithMeasurement_ && !b_pf_mus_cm_PixelLayersWithMeasurement_->TestBit(kDoNotProcess)){
    c_pf_mus_cm_PixelLayersWithMeasurement_ = true;
  }else{
    c_pf_mus_cm_PixelLayersWithMeasurement_ = false;
  }
  if(b_pf_mus_cm_ValidStripLayersWithMonoAndStereoHit_ && !b_pf_mus_cm_ValidStripLayersWithMonoAndStereoHit_->TestBit(kDoNotProcess)){
    c_pf_mus_cm_ValidStripLayersWithMonoAndStereoHit_ = true;
  }else{
    c_pf_mus_cm_ValidStripLayersWithMonoAndStereoHit_ = false;
  }
  if(b_pf_mus_cm_chg_ && !b_pf_mus_cm_chg_->TestBit(kDoNotProcess)){
    c_pf_mus_cm_chg_ = true;
  }else{
    c_pf_mus_cm_chg_ = false;
  }
  if(b_pf_mus_cm_chi2_ && !b_pf_mus_cm_chi2_->TestBit(kDoNotProcess)){
    c_pf_mus_cm_chi2_ = true;
  }else{
    c_pf_mus_cm_chi2_ = false;
  }
  if(b_pf_mus_cm_d0dum_ && !b_pf_mus_cm_d0dum_->TestBit(kDoNotProcess)){
    c_pf_mus_cm_d0dum_ = true;
  }else{
    c_pf_mus_cm_d0dum_ = false;
  }
  if(b_pf_mus_cm_d0dumErr_ && !b_pf_mus_cm_d0dumErr_->TestBit(kDoNotProcess)){
    c_pf_mus_cm_d0dumErr_ = true;
  }else{
    c_pf_mus_cm_d0dumErr_ = false;
  }
  if(b_pf_mus_cm_dz_ && !b_pf_mus_cm_dz_->TestBit(kDoNotProcess)){
    c_pf_mus_cm_dz_ = true;
  }else{
    c_pf_mus_cm_dz_ = false;
  }
  if(b_pf_mus_cm_dzErr_ && !b_pf_mus_cm_dzErr_->TestBit(kDoNotProcess)){
    c_pf_mus_cm_dzErr_ = true;
  }else{
    c_pf_mus_cm_dzErr_ = false;
  }
  if(b_pf_mus_cm_eta_ && !b_pf_mus_cm_eta_->TestBit(kDoNotProcess)){
    c_pf_mus_cm_eta_ = true;
  }else{
    c_pf_mus_cm_eta_ = false;
  }
  if(b_pf_mus_cm_etaErr_ && !b_pf_mus_cm_etaErr_->TestBit(kDoNotProcess)){
    c_pf_mus_cm_etaErr_ = true;
  }else{
    c_pf_mus_cm_etaErr_ = false;
  }
  if(b_pf_mus_cm_ndof_ && !b_pf_mus_cm_ndof_->TestBit(kDoNotProcess)){
    c_pf_mus_cm_ndof_ = true;
  }else{
    c_pf_mus_cm_ndof_ = false;
  }
  if(b_pf_mus_cm_numlosthits_ && !b_pf_mus_cm_numlosthits_->TestBit(kDoNotProcess)){
    c_pf_mus_cm_numlosthits_ = true;
  }else{
    c_pf_mus_cm_numlosthits_ = false;
  }
  if(b_pf_mus_cm_numvalMuonhits_ && !b_pf_mus_cm_numvalMuonhits_->TestBit(kDoNotProcess)){
    c_pf_mus_cm_numvalMuonhits_ = true;
  }else{
    c_pf_mus_cm_numvalMuonhits_ = false;
  }
  if(b_pf_mus_cm_numvalhits_ && !b_pf_mus_cm_numvalhits_->TestBit(kDoNotProcess)){
    c_pf_mus_cm_numvalhits_ = true;
  }else{
    c_pf_mus_cm_numvalhits_ = false;
  }
  if(b_pf_mus_cm_phi_ && !b_pf_mus_cm_phi_->TestBit(kDoNotProcess)){
    c_pf_mus_cm_phi_ = true;
  }else{
    c_pf_mus_cm_phi_ = false;
  }
  if(b_pf_mus_cm_phiErr_ && !b_pf_mus_cm_phiErr_->TestBit(kDoNotProcess)){
    c_pf_mus_cm_phiErr_ = true;
  }else{
    c_pf_mus_cm_phiErr_ = false;
  }
  if(b_pf_mus_cm_pt_ && !b_pf_mus_cm_pt_->TestBit(kDoNotProcess)){
    c_pf_mus_cm_pt_ = true;
  }else{
    c_pf_mus_cm_pt_ = false;
  }
  if(b_pf_mus_cm_ptErr_ && !b_pf_mus_cm_ptErr_->TestBit(kDoNotProcess)){
    c_pf_mus_cm_ptErr_ = true;
  }else{
    c_pf_mus_cm_ptErr_ = false;
  }
  if(b_pf_mus_cm_px_ && !b_pf_mus_cm_px_->TestBit(kDoNotProcess)){
    c_pf_mus_cm_px_ = true;
  }else{
    c_pf_mus_cm_px_ = false;
  }
  if(b_pf_mus_cm_py_ && !b_pf_mus_cm_py_->TestBit(kDoNotProcess)){
    c_pf_mus_cm_py_ = true;
  }else{
    c_pf_mus_cm_py_ = false;
  }
  if(b_pf_mus_cm_pz_ && !b_pf_mus_cm_pz_->TestBit(kDoNotProcess)){
    c_pf_mus_cm_pz_ = true;
  }else{
    c_pf_mus_cm_pz_ = false;
  }
  if(b_pf_mus_cm_theta_ && !b_pf_mus_cm_theta_->TestBit(kDoNotProcess)){
    c_pf_mus_cm_theta_ = true;
  }else{
    c_pf_mus_cm_theta_ = false;
  }
  if(b_pf_mus_cm_vx_ && !b_pf_mus_cm_vx_->TestBit(kDoNotProcess)){
    c_pf_mus_cm_vx_ = true;
  }else{
    c_pf_mus_cm_vx_ = false;
  }
  if(b_pf_mus_cm_vy_ && !b_pf_mus_cm_vy_->TestBit(kDoNotProcess)){
    c_pf_mus_cm_vy_ = true;
  }else{
    c_pf_mus_cm_vy_ = false;
  }
  if(b_pf_mus_cm_vz_ && !b_pf_mus_cm_vz_->TestBit(kDoNotProcess)){
    c_pf_mus_cm_vz_ = true;
  }else{
    c_pf_mus_cm_vz_ = false;
  }
  if(b_pf_mus_dB_ && !b_pf_mus_dB_->TestBit(kDoNotProcess)){
    c_pf_mus_dB_ = true;
  }else{
    c_pf_mus_dB_ = false;
  }
  if(b_pf_mus_ecalIso_ && !b_pf_mus_ecalIso_->TestBit(kDoNotProcess)){
    c_pf_mus_ecalIso_ = true;
  }else{
    c_pf_mus_ecalIso_ = false;
  }
  if(b_pf_mus_energy_ && !b_pf_mus_energy_->TestBit(kDoNotProcess)){
    c_pf_mus_energy_ = true;
  }else{
    c_pf_mus_energy_ = false;
  }
  if(b_pf_mus_et_ && !b_pf_mus_et_->TestBit(kDoNotProcess)){
    c_pf_mus_et_ = true;
  }else{
    c_pf_mus_et_ = false;
  }
  if(b_pf_mus_eta_ && !b_pf_mus_eta_->TestBit(kDoNotProcess)){
    c_pf_mus_eta_ = true;
  }else{
    c_pf_mus_eta_ = false;
  }
  if(b_pf_mus_gen_et_ && !b_pf_mus_gen_et_->TestBit(kDoNotProcess)){
    c_pf_mus_gen_et_ = true;
  }else{
    c_pf_mus_gen_et_ = false;
  }
  if(b_pf_mus_gen_eta_ && !b_pf_mus_gen_eta_->TestBit(kDoNotProcess)){
    c_pf_mus_gen_eta_ = true;
  }else{
    c_pf_mus_gen_eta_ = false;
  }
  if(b_pf_mus_gen_id_ && !b_pf_mus_gen_id_->TestBit(kDoNotProcess)){
    c_pf_mus_gen_id_ = true;
  }else{
    c_pf_mus_gen_id_ = false;
  }
  if(b_pf_mus_gen_mother_et_ && !b_pf_mus_gen_mother_et_->TestBit(kDoNotProcess)){
    c_pf_mus_gen_mother_et_ = true;
  }else{
    c_pf_mus_gen_mother_et_ = false;
  }
  if(b_pf_mus_gen_mother_eta_ && !b_pf_mus_gen_mother_eta_->TestBit(kDoNotProcess)){
    c_pf_mus_gen_mother_eta_ = true;
  }else{
    c_pf_mus_gen_mother_eta_ = false;
  }
  if(b_pf_mus_gen_mother_id_ && !b_pf_mus_gen_mother_id_->TestBit(kDoNotProcess)){
    c_pf_mus_gen_mother_id_ = true;
  }else{
    c_pf_mus_gen_mother_id_ = false;
  }
  if(b_pf_mus_gen_mother_phi_ && !b_pf_mus_gen_mother_phi_->TestBit(kDoNotProcess)){
    c_pf_mus_gen_mother_phi_ = true;
  }else{
    c_pf_mus_gen_mother_phi_ = false;
  }
  if(b_pf_mus_gen_mother_pt_ && !b_pf_mus_gen_mother_pt_->TestBit(kDoNotProcess)){
    c_pf_mus_gen_mother_pt_ = true;
  }else{
    c_pf_mus_gen_mother_pt_ = false;
  }
  if(b_pf_mus_gen_mother_px_ && !b_pf_mus_gen_mother_px_->TestBit(kDoNotProcess)){
    c_pf_mus_gen_mother_px_ = true;
  }else{
    c_pf_mus_gen_mother_px_ = false;
  }
  if(b_pf_mus_gen_mother_py_ && !b_pf_mus_gen_mother_py_->TestBit(kDoNotProcess)){
    c_pf_mus_gen_mother_py_ = true;
  }else{
    c_pf_mus_gen_mother_py_ = false;
  }
  if(b_pf_mus_gen_mother_pz_ && !b_pf_mus_gen_mother_pz_->TestBit(kDoNotProcess)){
    c_pf_mus_gen_mother_pz_ = true;
  }else{
    c_pf_mus_gen_mother_pz_ = false;
  }
  if(b_pf_mus_gen_mother_theta_ && !b_pf_mus_gen_mother_theta_->TestBit(kDoNotProcess)){
    c_pf_mus_gen_mother_theta_ = true;
  }else{
    c_pf_mus_gen_mother_theta_ = false;
  }
  if(b_pf_mus_gen_phi_ && !b_pf_mus_gen_phi_->TestBit(kDoNotProcess)){
    c_pf_mus_gen_phi_ = true;
  }else{
    c_pf_mus_gen_phi_ = false;
  }
  if(b_pf_mus_gen_pt_ && !b_pf_mus_gen_pt_->TestBit(kDoNotProcess)){
    c_pf_mus_gen_pt_ = true;
  }else{
    c_pf_mus_gen_pt_ = false;
  }
  if(b_pf_mus_gen_px_ && !b_pf_mus_gen_px_->TestBit(kDoNotProcess)){
    c_pf_mus_gen_px_ = true;
  }else{
    c_pf_mus_gen_px_ = false;
  }
  if(b_pf_mus_gen_py_ && !b_pf_mus_gen_py_->TestBit(kDoNotProcess)){
    c_pf_mus_gen_py_ = true;
  }else{
    c_pf_mus_gen_py_ = false;
  }
  if(b_pf_mus_gen_pz_ && !b_pf_mus_gen_pz_->TestBit(kDoNotProcess)){
    c_pf_mus_gen_pz_ = true;
  }else{
    c_pf_mus_gen_pz_ = false;
  }
  if(b_pf_mus_gen_theta_ && !b_pf_mus_gen_theta_->TestBit(kDoNotProcess)){
    c_pf_mus_gen_theta_ = true;
  }else{
    c_pf_mus_gen_theta_ = false;
  }
  if(b_pf_mus_hcalIso_ && !b_pf_mus_hcalIso_->TestBit(kDoNotProcess)){
    c_pf_mus_hcalIso_ = true;
  }else{
    c_pf_mus_hcalIso_ = false;
  }
  if(b_pf_mus_id_All_ && !b_pf_mus_id_All_->TestBit(kDoNotProcess)){
    c_pf_mus_id_All_ = true;
  }else{
    c_pf_mus_id_All_ = false;
  }
  if(b_pf_mus_id_AllArbitrated_ && !b_pf_mus_id_AllArbitrated_->TestBit(kDoNotProcess)){
    c_pf_mus_id_AllArbitrated_ = true;
  }else{
    c_pf_mus_id_AllArbitrated_ = false;
  }
  if(b_pf_mus_id_AllGlobalMuons_ && !b_pf_mus_id_AllGlobalMuons_->TestBit(kDoNotProcess)){
    c_pf_mus_id_AllGlobalMuons_ = true;
  }else{
    c_pf_mus_id_AllGlobalMuons_ = false;
  }
  if(b_pf_mus_id_AllStandAloneMuons_ && !b_pf_mus_id_AllStandAloneMuons_->TestBit(kDoNotProcess)){
    c_pf_mus_id_AllStandAloneMuons_ = true;
  }else{
    c_pf_mus_id_AllStandAloneMuons_ = false;
  }
  if(b_pf_mus_id_AllTrackerMuons_ && !b_pf_mus_id_AllTrackerMuons_->TestBit(kDoNotProcess)){
    c_pf_mus_id_AllTrackerMuons_ = true;
  }else{
    c_pf_mus_id_AllTrackerMuons_ = false;
  }
  if(b_pf_mus_id_GlobalMuonPromptTight_ && !b_pf_mus_id_GlobalMuonPromptTight_->TestBit(kDoNotProcess)){
    c_pf_mus_id_GlobalMuonPromptTight_ = true;
  }else{
    c_pf_mus_id_GlobalMuonPromptTight_ = false;
  }
  if(b_pf_mus_id_TM2DCompatibilityLoose_ && !b_pf_mus_id_TM2DCompatibilityLoose_->TestBit(kDoNotProcess)){
    c_pf_mus_id_TM2DCompatibilityLoose_ = true;
  }else{
    c_pf_mus_id_TM2DCompatibilityLoose_ = false;
  }
  if(b_pf_mus_id_TM2DCompatibilityTight_ && !b_pf_mus_id_TM2DCompatibilityTight_->TestBit(kDoNotProcess)){
    c_pf_mus_id_TM2DCompatibilityTight_ = true;
  }else{
    c_pf_mus_id_TM2DCompatibilityTight_ = false;
  }
  if(b_pf_mus_id_TMLastStationLoose_ && !b_pf_mus_id_TMLastStationLoose_->TestBit(kDoNotProcess)){
    c_pf_mus_id_TMLastStationLoose_ = true;
  }else{
    c_pf_mus_id_TMLastStationLoose_ = false;
  }
  if(b_pf_mus_id_TMLastStationOptimizedLowPtLoose_ && !b_pf_mus_id_TMLastStationOptimizedLowPtLoose_->TestBit(kDoNotProcess)){
    c_pf_mus_id_TMLastStationOptimizedLowPtLoose_ = true;
  }else{
    c_pf_mus_id_TMLastStationOptimizedLowPtLoose_ = false;
  }
  if(b_pf_mus_id_TMLastStationOptimizedLowPtTight_ && !b_pf_mus_id_TMLastStationOptimizedLowPtTight_->TestBit(kDoNotProcess)){
    c_pf_mus_id_TMLastStationOptimizedLowPtTight_ = true;
  }else{
    c_pf_mus_id_TMLastStationOptimizedLowPtTight_ = false;
  }
  if(b_pf_mus_id_TMLastStationTight_ && !b_pf_mus_id_TMLastStationTight_->TestBit(kDoNotProcess)){
    c_pf_mus_id_TMLastStationTight_ = true;
  }else{
    c_pf_mus_id_TMLastStationTight_ = false;
  }
  if(b_pf_mus_id_TMOneStationLoose_ && !b_pf_mus_id_TMOneStationLoose_->TestBit(kDoNotProcess)){
    c_pf_mus_id_TMOneStationLoose_ = true;
  }else{
    c_pf_mus_id_TMOneStationLoose_ = false;
  }
  if(b_pf_mus_id_TMOneStationTight_ && !b_pf_mus_id_TMOneStationTight_->TestBit(kDoNotProcess)){
    c_pf_mus_id_TMOneStationTight_ = true;
  }else{
    c_pf_mus_id_TMOneStationTight_ = false;
  }
  if(b_pf_mus_id_TrackerMuonArbitrated_ && !b_pf_mus_id_TrackerMuonArbitrated_->TestBit(kDoNotProcess)){
    c_pf_mus_id_TrackerMuonArbitrated_ = true;
  }else{
    c_pf_mus_id_TrackerMuonArbitrated_ = false;
  }
  if(b_pf_mus_isCaloMuon_ && !b_pf_mus_isCaloMuon_->TestBit(kDoNotProcess)){
    c_pf_mus_isCaloMuon_ = true;
  }else{
    c_pf_mus_isCaloMuon_ = false;
  }
  if(b_pf_mus_isConvertedPhoton_ && !b_pf_mus_isConvertedPhoton_->TestBit(kDoNotProcess)){
    c_pf_mus_isConvertedPhoton_ = true;
  }else{
    c_pf_mus_isConvertedPhoton_ = false;
  }
  if(b_pf_mus_isElectron_ && !b_pf_mus_isElectron_->TestBit(kDoNotProcess)){
    c_pf_mus_isElectron_ = true;
  }else{
    c_pf_mus_isElectron_ = false;
  }
  if(b_pf_mus_isGlobalMuon_ && !b_pf_mus_isGlobalMuon_->TestBit(kDoNotProcess)){
    c_pf_mus_isGlobalMuon_ = true;
  }else{
    c_pf_mus_isGlobalMuon_ = false;
  }
  if(b_pf_mus_isPFMuon_ && !b_pf_mus_isPFMuon_->TestBit(kDoNotProcess)){
    c_pf_mus_isPFMuon_ = true;
  }else{
    c_pf_mus_isPFMuon_ = false;
  }
  if(b_pf_mus_isPhoton_ && !b_pf_mus_isPhoton_->TestBit(kDoNotProcess)){
    c_pf_mus_isPhoton_ = true;
  }else{
    c_pf_mus_isPhoton_ = false;
  }
  if(b_pf_mus_isStandAloneMuon_ && !b_pf_mus_isStandAloneMuon_->TestBit(kDoNotProcess)){
    c_pf_mus_isStandAloneMuon_ = true;
  }else{
    c_pf_mus_isStandAloneMuon_ = false;
  }
  if(b_pf_mus_isTrackerMuon_ && !b_pf_mus_isTrackerMuon_->TestBit(kDoNotProcess)){
    c_pf_mus_isTrackerMuon_ = true;
  }else{
    c_pf_mus_isTrackerMuon_ = false;
  }
  if(b_pf_mus_iso03_emEt_ && !b_pf_mus_iso03_emEt_->TestBit(kDoNotProcess)){
    c_pf_mus_iso03_emEt_ = true;
  }else{
    c_pf_mus_iso03_emEt_ = false;
  }
  if(b_pf_mus_iso03_emVetoEt_ && !b_pf_mus_iso03_emVetoEt_->TestBit(kDoNotProcess)){
    c_pf_mus_iso03_emVetoEt_ = true;
  }else{
    c_pf_mus_iso03_emVetoEt_ = false;
  }
  if(b_pf_mus_iso03_hadEt_ && !b_pf_mus_iso03_hadEt_->TestBit(kDoNotProcess)){
    c_pf_mus_iso03_hadEt_ = true;
  }else{
    c_pf_mus_iso03_hadEt_ = false;
  }
  if(b_pf_mus_iso03_hadVetoEt_ && !b_pf_mus_iso03_hadVetoEt_->TestBit(kDoNotProcess)){
    c_pf_mus_iso03_hadVetoEt_ = true;
  }else{
    c_pf_mus_iso03_hadVetoEt_ = false;
  }
  if(b_pf_mus_iso03_hoEt_ && !b_pf_mus_iso03_hoEt_->TestBit(kDoNotProcess)){
    c_pf_mus_iso03_hoEt_ = true;
  }else{
    c_pf_mus_iso03_hoEt_ = false;
  }
  if(b_pf_mus_iso03_nTracks_ && !b_pf_mus_iso03_nTracks_->TestBit(kDoNotProcess)){
    c_pf_mus_iso03_nTracks_ = true;
  }else{
    c_pf_mus_iso03_nTracks_ = false;
  }
  if(b_pf_mus_iso03_sumPt_ && !b_pf_mus_iso03_sumPt_->TestBit(kDoNotProcess)){
    c_pf_mus_iso03_sumPt_ = true;
  }else{
    c_pf_mus_iso03_sumPt_ = false;
  }
  if(b_pf_mus_iso05_emEt_ && !b_pf_mus_iso05_emEt_->TestBit(kDoNotProcess)){
    c_pf_mus_iso05_emEt_ = true;
  }else{
    c_pf_mus_iso05_emEt_ = false;
  }
  if(b_pf_mus_iso05_hadEt_ && !b_pf_mus_iso05_hadEt_->TestBit(kDoNotProcess)){
    c_pf_mus_iso05_hadEt_ = true;
  }else{
    c_pf_mus_iso05_hadEt_ = false;
  }
  if(b_pf_mus_iso05_hoEt_ && !b_pf_mus_iso05_hoEt_->TestBit(kDoNotProcess)){
    c_pf_mus_iso05_hoEt_ = true;
  }else{
    c_pf_mus_iso05_hoEt_ = false;
  }
  if(b_pf_mus_iso05_nTracks_ && !b_pf_mus_iso05_nTracks_->TestBit(kDoNotProcess)){
    c_pf_mus_iso05_nTracks_ = true;
  }else{
    c_pf_mus_iso05_nTracks_ = false;
  }
  if(b_pf_mus_iso05_sumPt_ && !b_pf_mus_iso05_sumPt_->TestBit(kDoNotProcess)){
    c_pf_mus_iso05_sumPt_ = true;
  }else{
    c_pf_mus_iso05_sumPt_ = false;
  }
  if(b_pf_mus_neutralHadronIso_ && !b_pf_mus_neutralHadronIso_->TestBit(kDoNotProcess)){
    c_pf_mus_neutralHadronIso_ = true;
  }else{
    c_pf_mus_neutralHadronIso_ = false;
  }
  if(b_pf_mus_num_matches_ && !b_pf_mus_num_matches_->TestBit(kDoNotProcess)){
    c_pf_mus_num_matches_ = true;
  }else{
    c_pf_mus_num_matches_ = false;
  }
  if(b_pf_mus_numberOfMatchedStations_ && !b_pf_mus_numberOfMatchedStations_->TestBit(kDoNotProcess)){
    c_pf_mus_numberOfMatchedStations_ = true;
  }else{
    c_pf_mus_numberOfMatchedStations_ = false;
  }
  if(b_pf_mus_pfIsolationR03_sumChargedHadronPt_ && !b_pf_mus_pfIsolationR03_sumChargedHadronPt_->TestBit(kDoNotProcess)){
    c_pf_mus_pfIsolationR03_sumChargedHadronPt_ = true;
  }else{
    c_pf_mus_pfIsolationR03_sumChargedHadronPt_ = false;
  }
  if(b_pf_mus_pfIsolationR03_sumChargedParticlePt_ && !b_pf_mus_pfIsolationR03_sumChargedParticlePt_->TestBit(kDoNotProcess)){
    c_pf_mus_pfIsolationR03_sumChargedParticlePt_ = true;
  }else{
    c_pf_mus_pfIsolationR03_sumChargedParticlePt_ = false;
  }
  if(b_pf_mus_pfIsolationR03_sumNeutralHadronEt_ && !b_pf_mus_pfIsolationR03_sumNeutralHadronEt_->TestBit(kDoNotProcess)){
    c_pf_mus_pfIsolationR03_sumNeutralHadronEt_ = true;
  }else{
    c_pf_mus_pfIsolationR03_sumNeutralHadronEt_ = false;
  }
  if(b_pf_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_ && !b_pf_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_->TestBit(kDoNotProcess)){
    c_pf_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_ = true;
  }else{
    c_pf_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_ = false;
  }
  if(b_pf_mus_pfIsolationR03_sumPUPt_ && !b_pf_mus_pfIsolationR03_sumPUPt_->TestBit(kDoNotProcess)){
    c_pf_mus_pfIsolationR03_sumPUPt_ = true;
  }else{
    c_pf_mus_pfIsolationR03_sumPUPt_ = false;
  }
  if(b_pf_mus_pfIsolationR03_sumPhotonEt_ && !b_pf_mus_pfIsolationR03_sumPhotonEt_->TestBit(kDoNotProcess)){
    c_pf_mus_pfIsolationR03_sumPhotonEt_ = true;
  }else{
    c_pf_mus_pfIsolationR03_sumPhotonEt_ = false;
  }
  if(b_pf_mus_pfIsolationR03_sumPhotonEtHighThreshold_ && !b_pf_mus_pfIsolationR03_sumPhotonEtHighThreshold_->TestBit(kDoNotProcess)){
    c_pf_mus_pfIsolationR03_sumPhotonEtHighThreshold_ = true;
  }else{
    c_pf_mus_pfIsolationR03_sumPhotonEtHighThreshold_ = false;
  }
  if(b_pf_mus_pfIsolationR04_sumChargedHadronPt_ && !b_pf_mus_pfIsolationR04_sumChargedHadronPt_->TestBit(kDoNotProcess)){
    c_pf_mus_pfIsolationR04_sumChargedHadronPt_ = true;
  }else{
    c_pf_mus_pfIsolationR04_sumChargedHadronPt_ = false;
  }
  if(b_pf_mus_pfIsolationR04_sumChargedParticlePt_ && !b_pf_mus_pfIsolationR04_sumChargedParticlePt_->TestBit(kDoNotProcess)){
    c_pf_mus_pfIsolationR04_sumChargedParticlePt_ = true;
  }else{
    c_pf_mus_pfIsolationR04_sumChargedParticlePt_ = false;
  }
  if(b_pf_mus_pfIsolationR04_sumNeutralHadronEt_ && !b_pf_mus_pfIsolationR04_sumNeutralHadronEt_->TestBit(kDoNotProcess)){
    c_pf_mus_pfIsolationR04_sumNeutralHadronEt_ = true;
  }else{
    c_pf_mus_pfIsolationR04_sumNeutralHadronEt_ = false;
  }
  if(b_pf_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_ && !b_pf_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_->TestBit(kDoNotProcess)){
    c_pf_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_ = true;
  }else{
    c_pf_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_ = false;
  }
  if(b_pf_mus_pfIsolationR04_sumPUPt_ && !b_pf_mus_pfIsolationR04_sumPUPt_->TestBit(kDoNotProcess)){
    c_pf_mus_pfIsolationR04_sumPUPt_ = true;
  }else{
    c_pf_mus_pfIsolationR04_sumPUPt_ = false;
  }
  if(b_pf_mus_pfIsolationR04_sumPhotonEt_ && !b_pf_mus_pfIsolationR04_sumPhotonEt_->TestBit(kDoNotProcess)){
    c_pf_mus_pfIsolationR04_sumPhotonEt_ = true;
  }else{
    c_pf_mus_pfIsolationR04_sumPhotonEt_ = false;
  }
  if(b_pf_mus_pfIsolationR04_sumPhotonEtHighThreshold_ && !b_pf_mus_pfIsolationR04_sumPhotonEtHighThreshold_->TestBit(kDoNotProcess)){
    c_pf_mus_pfIsolationR04_sumPhotonEtHighThreshold_ = true;
  }else{
    c_pf_mus_pfIsolationR04_sumPhotonEtHighThreshold_ = false;
  }
  if(b_pf_mus_phi_ && !b_pf_mus_phi_->TestBit(kDoNotProcess)){
    c_pf_mus_phi_ = true;
  }else{
    c_pf_mus_phi_ = false;
  }
  if(b_pf_mus_photonIso_ && !b_pf_mus_photonIso_->TestBit(kDoNotProcess)){
    c_pf_mus_photonIso_ = true;
  }else{
    c_pf_mus_photonIso_ = false;
  }
  if(b_pf_mus_picky_ExpectedHitsInner_ && !b_pf_mus_picky_ExpectedHitsInner_->TestBit(kDoNotProcess)){
    c_pf_mus_picky_ExpectedHitsInner_ = true;
  }else{
    c_pf_mus_picky_ExpectedHitsInner_ = false;
  }
  if(b_pf_mus_picky_ExpectedHitsOuter_ && !b_pf_mus_picky_ExpectedHitsOuter_->TestBit(kDoNotProcess)){
    c_pf_mus_picky_ExpectedHitsOuter_ = true;
  }else{
    c_pf_mus_picky_ExpectedHitsOuter_ = false;
  }
  if(b_pf_mus_picky_LayersWithMeasurement_ && !b_pf_mus_picky_LayersWithMeasurement_->TestBit(kDoNotProcess)){
    c_pf_mus_picky_LayersWithMeasurement_ = true;
  }else{
    c_pf_mus_picky_LayersWithMeasurement_ = false;
  }
  if(b_pf_mus_picky_LayersWithoutMeasurement_ && !b_pf_mus_picky_LayersWithoutMeasurement_->TestBit(kDoNotProcess)){
    c_pf_mus_picky_LayersWithoutMeasurement_ = true;
  }else{
    c_pf_mus_picky_LayersWithoutMeasurement_ = false;
  }
  if(b_pf_mus_picky_PixelLayersWithMeasurement_ && !b_pf_mus_picky_PixelLayersWithMeasurement_->TestBit(kDoNotProcess)){
    c_pf_mus_picky_PixelLayersWithMeasurement_ = true;
  }else{
    c_pf_mus_picky_PixelLayersWithMeasurement_ = false;
  }
  if(b_pf_mus_picky_ValidStripLayersWithMonoAndStereoHit_ && !b_pf_mus_picky_ValidStripLayersWithMonoAndStereoHit_->TestBit(kDoNotProcess)){
    c_pf_mus_picky_ValidStripLayersWithMonoAndStereoHit_ = true;
  }else{
    c_pf_mus_picky_ValidStripLayersWithMonoAndStereoHit_ = false;
  }
  if(b_pf_mus_picky_chg_ && !b_pf_mus_picky_chg_->TestBit(kDoNotProcess)){
    c_pf_mus_picky_chg_ = true;
  }else{
    c_pf_mus_picky_chg_ = false;
  }
  if(b_pf_mus_picky_chi2_ && !b_pf_mus_picky_chi2_->TestBit(kDoNotProcess)){
    c_pf_mus_picky_chi2_ = true;
  }else{
    c_pf_mus_picky_chi2_ = false;
  }
  if(b_pf_mus_picky_d0dum_ && !b_pf_mus_picky_d0dum_->TestBit(kDoNotProcess)){
    c_pf_mus_picky_d0dum_ = true;
  }else{
    c_pf_mus_picky_d0dum_ = false;
  }
  if(b_pf_mus_picky_d0dumErr_ && !b_pf_mus_picky_d0dumErr_->TestBit(kDoNotProcess)){
    c_pf_mus_picky_d0dumErr_ = true;
  }else{
    c_pf_mus_picky_d0dumErr_ = false;
  }
  if(b_pf_mus_picky_dz_ && !b_pf_mus_picky_dz_->TestBit(kDoNotProcess)){
    c_pf_mus_picky_dz_ = true;
  }else{
    c_pf_mus_picky_dz_ = false;
  }
  if(b_pf_mus_picky_dzErr_ && !b_pf_mus_picky_dzErr_->TestBit(kDoNotProcess)){
    c_pf_mus_picky_dzErr_ = true;
  }else{
    c_pf_mus_picky_dzErr_ = false;
  }
  if(b_pf_mus_picky_eta_ && !b_pf_mus_picky_eta_->TestBit(kDoNotProcess)){
    c_pf_mus_picky_eta_ = true;
  }else{
    c_pf_mus_picky_eta_ = false;
  }
  if(b_pf_mus_picky_etaErr_ && !b_pf_mus_picky_etaErr_->TestBit(kDoNotProcess)){
    c_pf_mus_picky_etaErr_ = true;
  }else{
    c_pf_mus_picky_etaErr_ = false;
  }
  if(b_pf_mus_picky_id_ && !b_pf_mus_picky_id_->TestBit(kDoNotProcess)){
    c_pf_mus_picky_id_ = true;
  }else{
    c_pf_mus_picky_id_ = false;
  }
  if(b_pf_mus_picky_ndof_ && !b_pf_mus_picky_ndof_->TestBit(kDoNotProcess)){
    c_pf_mus_picky_ndof_ = true;
  }else{
    c_pf_mus_picky_ndof_ = false;
  }
  if(b_pf_mus_picky_numlosthits_ && !b_pf_mus_picky_numlosthits_->TestBit(kDoNotProcess)){
    c_pf_mus_picky_numlosthits_ = true;
  }else{
    c_pf_mus_picky_numlosthits_ = false;
  }
  if(b_pf_mus_picky_numvalPixelhits_ && !b_pf_mus_picky_numvalPixelhits_->TestBit(kDoNotProcess)){
    c_pf_mus_picky_numvalPixelhits_ = true;
  }else{
    c_pf_mus_picky_numvalPixelhits_ = false;
  }
  if(b_pf_mus_picky_numvalhits_ && !b_pf_mus_picky_numvalhits_->TestBit(kDoNotProcess)){
    c_pf_mus_picky_numvalhits_ = true;
  }else{
    c_pf_mus_picky_numvalhits_ = false;
  }
  if(b_pf_mus_picky_phi_ && !b_pf_mus_picky_phi_->TestBit(kDoNotProcess)){
    c_pf_mus_picky_phi_ = true;
  }else{
    c_pf_mus_picky_phi_ = false;
  }
  if(b_pf_mus_picky_phiErr_ && !b_pf_mus_picky_phiErr_->TestBit(kDoNotProcess)){
    c_pf_mus_picky_phiErr_ = true;
  }else{
    c_pf_mus_picky_phiErr_ = false;
  }
  if(b_pf_mus_picky_pt_ && !b_pf_mus_picky_pt_->TestBit(kDoNotProcess)){
    c_pf_mus_picky_pt_ = true;
  }else{
    c_pf_mus_picky_pt_ = false;
  }
  if(b_pf_mus_picky_ptErr_ && !b_pf_mus_picky_ptErr_->TestBit(kDoNotProcess)){
    c_pf_mus_picky_ptErr_ = true;
  }else{
    c_pf_mus_picky_ptErr_ = false;
  }
  if(b_pf_mus_picky_px_ && !b_pf_mus_picky_px_->TestBit(kDoNotProcess)){
    c_pf_mus_picky_px_ = true;
  }else{
    c_pf_mus_picky_px_ = false;
  }
  if(b_pf_mus_picky_py_ && !b_pf_mus_picky_py_->TestBit(kDoNotProcess)){
    c_pf_mus_picky_py_ = true;
  }else{
    c_pf_mus_picky_py_ = false;
  }
  if(b_pf_mus_picky_pz_ && !b_pf_mus_picky_pz_->TestBit(kDoNotProcess)){
    c_pf_mus_picky_pz_ = true;
  }else{
    c_pf_mus_picky_pz_ = false;
  }
  if(b_pf_mus_picky_theta_ && !b_pf_mus_picky_theta_->TestBit(kDoNotProcess)){
    c_pf_mus_picky_theta_ = true;
  }else{
    c_pf_mus_picky_theta_ = false;
  }
  if(b_pf_mus_picky_vx_ && !b_pf_mus_picky_vx_->TestBit(kDoNotProcess)){
    c_pf_mus_picky_vx_ = true;
  }else{
    c_pf_mus_picky_vx_ = false;
  }
  if(b_pf_mus_picky_vy_ && !b_pf_mus_picky_vy_->TestBit(kDoNotProcess)){
    c_pf_mus_picky_vy_ = true;
  }else{
    c_pf_mus_picky_vy_ = false;
  }
  if(b_pf_mus_picky_vz_ && !b_pf_mus_picky_vz_->TestBit(kDoNotProcess)){
    c_pf_mus_picky_vz_ = true;
  }else{
    c_pf_mus_picky_vz_ = false;
  }
  if(b_pf_mus_pt_ && !b_pf_mus_pt_->TestBit(kDoNotProcess)){
    c_pf_mus_pt_ = true;
  }else{
    c_pf_mus_pt_ = false;
  }
  if(b_pf_mus_px_ && !b_pf_mus_px_->TestBit(kDoNotProcess)){
    c_pf_mus_px_ = true;
  }else{
    c_pf_mus_px_ = false;
  }
  if(b_pf_mus_py_ && !b_pf_mus_py_->TestBit(kDoNotProcess)){
    c_pf_mus_py_ = true;
  }else{
    c_pf_mus_py_ = false;
  }
  if(b_pf_mus_pz_ && !b_pf_mus_pz_->TestBit(kDoNotProcess)){
    c_pf_mus_pz_ = true;
  }else{
    c_pf_mus_pz_ = false;
  }
  if(b_pf_mus_stamu_chg_ && !b_pf_mus_stamu_chg_->TestBit(kDoNotProcess)){
    c_pf_mus_stamu_chg_ = true;
  }else{
    c_pf_mus_stamu_chg_ = false;
  }
  if(b_pf_mus_stamu_chi2_ && !b_pf_mus_stamu_chi2_->TestBit(kDoNotProcess)){
    c_pf_mus_stamu_chi2_ = true;
  }else{
    c_pf_mus_stamu_chi2_ = false;
  }
  if(b_pf_mus_stamu_d0dum_ && !b_pf_mus_stamu_d0dum_->TestBit(kDoNotProcess)){
    c_pf_mus_stamu_d0dum_ = true;
  }else{
    c_pf_mus_stamu_d0dum_ = false;
  }
  if(b_pf_mus_stamu_d0dumErr_ && !b_pf_mus_stamu_d0dumErr_->TestBit(kDoNotProcess)){
    c_pf_mus_stamu_d0dumErr_ = true;
  }else{
    c_pf_mus_stamu_d0dumErr_ = false;
  }
  if(b_pf_mus_stamu_dz_ && !b_pf_mus_stamu_dz_->TestBit(kDoNotProcess)){
    c_pf_mus_stamu_dz_ = true;
  }else{
    c_pf_mus_stamu_dz_ = false;
  }
  if(b_pf_mus_stamu_dzErr_ && !b_pf_mus_stamu_dzErr_->TestBit(kDoNotProcess)){
    c_pf_mus_stamu_dzErr_ = true;
  }else{
    c_pf_mus_stamu_dzErr_ = false;
  }
  if(b_pf_mus_stamu_eta_ && !b_pf_mus_stamu_eta_->TestBit(kDoNotProcess)){
    c_pf_mus_stamu_eta_ = true;
  }else{
    c_pf_mus_stamu_eta_ = false;
  }
  if(b_pf_mus_stamu_etaErr_ && !b_pf_mus_stamu_etaErr_->TestBit(kDoNotProcess)){
    c_pf_mus_stamu_etaErr_ = true;
  }else{
    c_pf_mus_stamu_etaErr_ = false;
  }
  if(b_pf_mus_stamu_ndof_ && !b_pf_mus_stamu_ndof_->TestBit(kDoNotProcess)){
    c_pf_mus_stamu_ndof_ = true;
  }else{
    c_pf_mus_stamu_ndof_ = false;
  }
  if(b_pf_mus_stamu_numlosthits_ && !b_pf_mus_stamu_numlosthits_->TestBit(kDoNotProcess)){
    c_pf_mus_stamu_numlosthits_ = true;
  }else{
    c_pf_mus_stamu_numlosthits_ = false;
  }
  if(b_pf_mus_stamu_numvalhits_ && !b_pf_mus_stamu_numvalhits_->TestBit(kDoNotProcess)){
    c_pf_mus_stamu_numvalhits_ = true;
  }else{
    c_pf_mus_stamu_numvalhits_ = false;
  }
  if(b_pf_mus_stamu_phi_ && !b_pf_mus_stamu_phi_->TestBit(kDoNotProcess)){
    c_pf_mus_stamu_phi_ = true;
  }else{
    c_pf_mus_stamu_phi_ = false;
  }
  if(b_pf_mus_stamu_phiErr_ && !b_pf_mus_stamu_phiErr_->TestBit(kDoNotProcess)){
    c_pf_mus_stamu_phiErr_ = true;
  }else{
    c_pf_mus_stamu_phiErr_ = false;
  }
  if(b_pf_mus_stamu_pt_ && !b_pf_mus_stamu_pt_->TestBit(kDoNotProcess)){
    c_pf_mus_stamu_pt_ = true;
  }else{
    c_pf_mus_stamu_pt_ = false;
  }
  if(b_pf_mus_stamu_ptErr_ && !b_pf_mus_stamu_ptErr_->TestBit(kDoNotProcess)){
    c_pf_mus_stamu_ptErr_ = true;
  }else{
    c_pf_mus_stamu_ptErr_ = false;
  }
  if(b_pf_mus_stamu_px_ && !b_pf_mus_stamu_px_->TestBit(kDoNotProcess)){
    c_pf_mus_stamu_px_ = true;
  }else{
    c_pf_mus_stamu_px_ = false;
  }
  if(b_pf_mus_stamu_py_ && !b_pf_mus_stamu_py_->TestBit(kDoNotProcess)){
    c_pf_mus_stamu_py_ = true;
  }else{
    c_pf_mus_stamu_py_ = false;
  }
  if(b_pf_mus_stamu_pz_ && !b_pf_mus_stamu_pz_->TestBit(kDoNotProcess)){
    c_pf_mus_stamu_pz_ = true;
  }else{
    c_pf_mus_stamu_pz_ = false;
  }
  if(b_pf_mus_stamu_theta_ && !b_pf_mus_stamu_theta_->TestBit(kDoNotProcess)){
    c_pf_mus_stamu_theta_ = true;
  }else{
    c_pf_mus_stamu_theta_ = false;
  }
  if(b_pf_mus_stamu_vx_ && !b_pf_mus_stamu_vx_->TestBit(kDoNotProcess)){
    c_pf_mus_stamu_vx_ = true;
  }else{
    c_pf_mus_stamu_vx_ = false;
  }
  if(b_pf_mus_stamu_vy_ && !b_pf_mus_stamu_vy_->TestBit(kDoNotProcess)){
    c_pf_mus_stamu_vy_ = true;
  }else{
    c_pf_mus_stamu_vy_ = false;
  }
  if(b_pf_mus_stamu_vz_ && !b_pf_mus_stamu_vz_->TestBit(kDoNotProcess)){
    c_pf_mus_stamu_vz_ = true;
  }else{
    c_pf_mus_stamu_vz_ = false;
  }
  if(b_pf_mus_status_ && !b_pf_mus_status_->TestBit(kDoNotProcess)){
    c_pf_mus_status_ = true;
  }else{
    c_pf_mus_status_ = false;
  }
  if(b_pf_mus_tIso_ && !b_pf_mus_tIso_->TestBit(kDoNotProcess)){
    c_pf_mus_tIso_ = true;
  }else{
    c_pf_mus_tIso_ = false;
  }
  if(b_pf_mus_theta_ && !b_pf_mus_theta_->TestBit(kDoNotProcess)){
    c_pf_mus_theta_ = true;
  }else{
    c_pf_mus_theta_ = false;
  }
  if(b_pf_mus_tkHits_ && !b_pf_mus_tkHits_->TestBit(kDoNotProcess)){
    c_pf_mus_tkHits_ = true;
  }else{
    c_pf_mus_tkHits_ = false;
  }
  if(b_pf_mus_tk_ExpectedHitsInner_ && !b_pf_mus_tk_ExpectedHitsInner_->TestBit(kDoNotProcess)){
    c_pf_mus_tk_ExpectedHitsInner_ = true;
  }else{
    c_pf_mus_tk_ExpectedHitsInner_ = false;
  }
  if(b_pf_mus_tk_ExpectedHitsOuter_ && !b_pf_mus_tk_ExpectedHitsOuter_->TestBit(kDoNotProcess)){
    c_pf_mus_tk_ExpectedHitsOuter_ = true;
  }else{
    c_pf_mus_tk_ExpectedHitsOuter_ = false;
  }
  if(b_pf_mus_tk_LayersWithMeasurement_ && !b_pf_mus_tk_LayersWithMeasurement_->TestBit(kDoNotProcess)){
    c_pf_mus_tk_LayersWithMeasurement_ = true;
  }else{
    c_pf_mus_tk_LayersWithMeasurement_ = false;
  }
  if(b_pf_mus_tk_LayersWithoutMeasurement_ && !b_pf_mus_tk_LayersWithoutMeasurement_->TestBit(kDoNotProcess)){
    c_pf_mus_tk_LayersWithoutMeasurement_ = true;
  }else{
    c_pf_mus_tk_LayersWithoutMeasurement_ = false;
  }
  if(b_pf_mus_tk_PixelLayersWithMeasurement_ && !b_pf_mus_tk_PixelLayersWithMeasurement_->TestBit(kDoNotProcess)){
    c_pf_mus_tk_PixelLayersWithMeasurement_ = true;
  }else{
    c_pf_mus_tk_PixelLayersWithMeasurement_ = false;
  }
  if(b_pf_mus_tk_ValidStripLayersWithMonoAndStereoHit_ && !b_pf_mus_tk_ValidStripLayersWithMonoAndStereoHit_->TestBit(kDoNotProcess)){
    c_pf_mus_tk_ValidStripLayersWithMonoAndStereoHit_ = true;
  }else{
    c_pf_mus_tk_ValidStripLayersWithMonoAndStereoHit_ = false;
  }
  if(b_pf_mus_tk_chg_ && !b_pf_mus_tk_chg_->TestBit(kDoNotProcess)){
    c_pf_mus_tk_chg_ = true;
  }else{
    c_pf_mus_tk_chg_ = false;
  }
  if(b_pf_mus_tk_chi2_ && !b_pf_mus_tk_chi2_->TestBit(kDoNotProcess)){
    c_pf_mus_tk_chi2_ = true;
  }else{
    c_pf_mus_tk_chi2_ = false;
  }
  if(b_pf_mus_tk_d0dum_ && !b_pf_mus_tk_d0dum_->TestBit(kDoNotProcess)){
    c_pf_mus_tk_d0dum_ = true;
  }else{
    c_pf_mus_tk_d0dum_ = false;
  }
  if(b_pf_mus_tk_d0dumErr_ && !b_pf_mus_tk_d0dumErr_->TestBit(kDoNotProcess)){
    c_pf_mus_tk_d0dumErr_ = true;
  }else{
    c_pf_mus_tk_d0dumErr_ = false;
  }
  if(b_pf_mus_tk_dz_ && !b_pf_mus_tk_dz_->TestBit(kDoNotProcess)){
    c_pf_mus_tk_dz_ = true;
  }else{
    c_pf_mus_tk_dz_ = false;
  }
  if(b_pf_mus_tk_dzErr_ && !b_pf_mus_tk_dzErr_->TestBit(kDoNotProcess)){
    c_pf_mus_tk_dzErr_ = true;
  }else{
    c_pf_mus_tk_dzErr_ = false;
  }
  if(b_pf_mus_tk_eta_ && !b_pf_mus_tk_eta_->TestBit(kDoNotProcess)){
    c_pf_mus_tk_eta_ = true;
  }else{
    c_pf_mus_tk_eta_ = false;
  }
  if(b_pf_mus_tk_etaErr_ && !b_pf_mus_tk_etaErr_->TestBit(kDoNotProcess)){
    c_pf_mus_tk_etaErr_ = true;
  }else{
    c_pf_mus_tk_etaErr_ = false;
  }
  if(b_pf_mus_tk_id_ && !b_pf_mus_tk_id_->TestBit(kDoNotProcess)){
    c_pf_mus_tk_id_ = true;
  }else{
    c_pf_mus_tk_id_ = false;
  }
  if(b_pf_mus_tk_ndof_ && !b_pf_mus_tk_ndof_->TestBit(kDoNotProcess)){
    c_pf_mus_tk_ndof_ = true;
  }else{
    c_pf_mus_tk_ndof_ = false;
  }
  if(b_pf_mus_tk_numlosthits_ && !b_pf_mus_tk_numlosthits_->TestBit(kDoNotProcess)){
    c_pf_mus_tk_numlosthits_ = true;
  }else{
    c_pf_mus_tk_numlosthits_ = false;
  }
  if(b_pf_mus_tk_numpixelWthMeasr_ && !b_pf_mus_tk_numpixelWthMeasr_->TestBit(kDoNotProcess)){
    c_pf_mus_tk_numpixelWthMeasr_ = true;
  }else{
    c_pf_mus_tk_numpixelWthMeasr_ = false;
  }
  if(b_pf_mus_tk_numvalPixelhits_ && !b_pf_mus_tk_numvalPixelhits_->TestBit(kDoNotProcess)){
    c_pf_mus_tk_numvalPixelhits_ = true;
  }else{
    c_pf_mus_tk_numvalPixelhits_ = false;
  }
  if(b_pf_mus_tk_numvalhits_ && !b_pf_mus_tk_numvalhits_->TestBit(kDoNotProcess)){
    c_pf_mus_tk_numvalhits_ = true;
  }else{
    c_pf_mus_tk_numvalhits_ = false;
  }
  if(b_pf_mus_tk_phi_ && !b_pf_mus_tk_phi_->TestBit(kDoNotProcess)){
    c_pf_mus_tk_phi_ = true;
  }else{
    c_pf_mus_tk_phi_ = false;
  }
  if(b_pf_mus_tk_phiErr_ && !b_pf_mus_tk_phiErr_->TestBit(kDoNotProcess)){
    c_pf_mus_tk_phiErr_ = true;
  }else{
    c_pf_mus_tk_phiErr_ = false;
  }
  if(b_pf_mus_tk_pt_ && !b_pf_mus_tk_pt_->TestBit(kDoNotProcess)){
    c_pf_mus_tk_pt_ = true;
  }else{
    c_pf_mus_tk_pt_ = false;
  }
  if(b_pf_mus_tk_ptErr_ && !b_pf_mus_tk_ptErr_->TestBit(kDoNotProcess)){
    c_pf_mus_tk_ptErr_ = true;
  }else{
    c_pf_mus_tk_ptErr_ = false;
  }
  if(b_pf_mus_tk_px_ && !b_pf_mus_tk_px_->TestBit(kDoNotProcess)){
    c_pf_mus_tk_px_ = true;
  }else{
    c_pf_mus_tk_px_ = false;
  }
  if(b_pf_mus_tk_py_ && !b_pf_mus_tk_py_->TestBit(kDoNotProcess)){
    c_pf_mus_tk_py_ = true;
  }else{
    c_pf_mus_tk_py_ = false;
  }
  if(b_pf_mus_tk_pz_ && !b_pf_mus_tk_pz_->TestBit(kDoNotProcess)){
    c_pf_mus_tk_pz_ = true;
  }else{
    c_pf_mus_tk_pz_ = false;
  }
  if(b_pf_mus_tk_theta_ && !b_pf_mus_tk_theta_->TestBit(kDoNotProcess)){
    c_pf_mus_tk_theta_ = true;
  }else{
    c_pf_mus_tk_theta_ = false;
  }
  if(b_pf_mus_tk_vx_ && !b_pf_mus_tk_vx_->TestBit(kDoNotProcess)){
    c_pf_mus_tk_vx_ = true;
  }else{
    c_pf_mus_tk_vx_ = false;
  }
  if(b_pf_mus_tk_vy_ && !b_pf_mus_tk_vy_->TestBit(kDoNotProcess)){
    c_pf_mus_tk_vy_ = true;
  }else{
    c_pf_mus_tk_vy_ = false;
  }
  if(b_pf_mus_tk_vz_ && !b_pf_mus_tk_vz_->TestBit(kDoNotProcess)){
    c_pf_mus_tk_vz_ = true;
  }else{
    c_pf_mus_tk_vz_ = false;
  }
  if(b_pf_mus_tpfms_ExpectedHitsInner_ && !b_pf_mus_tpfms_ExpectedHitsInner_->TestBit(kDoNotProcess)){
    c_pf_mus_tpfms_ExpectedHitsInner_ = true;
  }else{
    c_pf_mus_tpfms_ExpectedHitsInner_ = false;
  }
  if(b_pf_mus_tpfms_ExpectedHitsOuter_ && !b_pf_mus_tpfms_ExpectedHitsOuter_->TestBit(kDoNotProcess)){
    c_pf_mus_tpfms_ExpectedHitsOuter_ = true;
  }else{
    c_pf_mus_tpfms_ExpectedHitsOuter_ = false;
  }
  if(b_pf_mus_tpfms_LayersWithMeasurement_ && !b_pf_mus_tpfms_LayersWithMeasurement_->TestBit(kDoNotProcess)){
    c_pf_mus_tpfms_LayersWithMeasurement_ = true;
  }else{
    c_pf_mus_tpfms_LayersWithMeasurement_ = false;
  }
  if(b_pf_mus_tpfms_LayersWithoutMeasurement_ && !b_pf_mus_tpfms_LayersWithoutMeasurement_->TestBit(kDoNotProcess)){
    c_pf_mus_tpfms_LayersWithoutMeasurement_ = true;
  }else{
    c_pf_mus_tpfms_LayersWithoutMeasurement_ = false;
  }
  if(b_pf_mus_tpfms_PixelLayersWithMeasurement_ && !b_pf_mus_tpfms_PixelLayersWithMeasurement_->TestBit(kDoNotProcess)){
    c_pf_mus_tpfms_PixelLayersWithMeasurement_ = true;
  }else{
    c_pf_mus_tpfms_PixelLayersWithMeasurement_ = false;
  }
  if(b_pf_mus_tpfms_ValidStripLayersWithMonoAndStereoHit_ && !b_pf_mus_tpfms_ValidStripLayersWithMonoAndStereoHit_->TestBit(kDoNotProcess)){
    c_pf_mus_tpfms_ValidStripLayersWithMonoAndStereoHit_ = true;
  }else{
    c_pf_mus_tpfms_ValidStripLayersWithMonoAndStereoHit_ = false;
  }
  if(b_pf_mus_tpfms_chg_ && !b_pf_mus_tpfms_chg_->TestBit(kDoNotProcess)){
    c_pf_mus_tpfms_chg_ = true;
  }else{
    c_pf_mus_tpfms_chg_ = false;
  }
  if(b_pf_mus_tpfms_chi2_ && !b_pf_mus_tpfms_chi2_->TestBit(kDoNotProcess)){
    c_pf_mus_tpfms_chi2_ = true;
  }else{
    c_pf_mus_tpfms_chi2_ = false;
  }
  if(b_pf_mus_tpfms_d0dum_ && !b_pf_mus_tpfms_d0dum_->TestBit(kDoNotProcess)){
    c_pf_mus_tpfms_d0dum_ = true;
  }else{
    c_pf_mus_tpfms_d0dum_ = false;
  }
  if(b_pf_mus_tpfms_d0dumErr_ && !b_pf_mus_tpfms_d0dumErr_->TestBit(kDoNotProcess)){
    c_pf_mus_tpfms_d0dumErr_ = true;
  }else{
    c_pf_mus_tpfms_d0dumErr_ = false;
  }
  if(b_pf_mus_tpfms_dz_ && !b_pf_mus_tpfms_dz_->TestBit(kDoNotProcess)){
    c_pf_mus_tpfms_dz_ = true;
  }else{
    c_pf_mus_tpfms_dz_ = false;
  }
  if(b_pf_mus_tpfms_dzErr_ && !b_pf_mus_tpfms_dzErr_->TestBit(kDoNotProcess)){
    c_pf_mus_tpfms_dzErr_ = true;
  }else{
    c_pf_mus_tpfms_dzErr_ = false;
  }
  if(b_pf_mus_tpfms_eta_ && !b_pf_mus_tpfms_eta_->TestBit(kDoNotProcess)){
    c_pf_mus_tpfms_eta_ = true;
  }else{
    c_pf_mus_tpfms_eta_ = false;
  }
  if(b_pf_mus_tpfms_etaErr_ && !b_pf_mus_tpfms_etaErr_->TestBit(kDoNotProcess)){
    c_pf_mus_tpfms_etaErr_ = true;
  }else{
    c_pf_mus_tpfms_etaErr_ = false;
  }
  if(b_pf_mus_tpfms_id_ && !b_pf_mus_tpfms_id_->TestBit(kDoNotProcess)){
    c_pf_mus_tpfms_id_ = true;
  }else{
    c_pf_mus_tpfms_id_ = false;
  }
  if(b_pf_mus_tpfms_ndof_ && !b_pf_mus_tpfms_ndof_->TestBit(kDoNotProcess)){
    c_pf_mus_tpfms_ndof_ = true;
  }else{
    c_pf_mus_tpfms_ndof_ = false;
  }
  if(b_pf_mus_tpfms_numlosthits_ && !b_pf_mus_tpfms_numlosthits_->TestBit(kDoNotProcess)){
    c_pf_mus_tpfms_numlosthits_ = true;
  }else{
    c_pf_mus_tpfms_numlosthits_ = false;
  }
  if(b_pf_mus_tpfms_numvalPixelhits_ && !b_pf_mus_tpfms_numvalPixelhits_->TestBit(kDoNotProcess)){
    c_pf_mus_tpfms_numvalPixelhits_ = true;
  }else{
    c_pf_mus_tpfms_numvalPixelhits_ = false;
  }
  if(b_pf_mus_tpfms_numvalhits_ && !b_pf_mus_tpfms_numvalhits_->TestBit(kDoNotProcess)){
    c_pf_mus_tpfms_numvalhits_ = true;
  }else{
    c_pf_mus_tpfms_numvalhits_ = false;
  }
  if(b_pf_mus_tpfms_phi_ && !b_pf_mus_tpfms_phi_->TestBit(kDoNotProcess)){
    c_pf_mus_tpfms_phi_ = true;
  }else{
    c_pf_mus_tpfms_phi_ = false;
  }
  if(b_pf_mus_tpfms_phiErr_ && !b_pf_mus_tpfms_phiErr_->TestBit(kDoNotProcess)){
    c_pf_mus_tpfms_phiErr_ = true;
  }else{
    c_pf_mus_tpfms_phiErr_ = false;
  }
  if(b_pf_mus_tpfms_pt_ && !b_pf_mus_tpfms_pt_->TestBit(kDoNotProcess)){
    c_pf_mus_tpfms_pt_ = true;
  }else{
    c_pf_mus_tpfms_pt_ = false;
  }
  if(b_pf_mus_tpfms_ptErr_ && !b_pf_mus_tpfms_ptErr_->TestBit(kDoNotProcess)){
    c_pf_mus_tpfms_ptErr_ = true;
  }else{
    c_pf_mus_tpfms_ptErr_ = false;
  }
  if(b_pf_mus_tpfms_px_ && !b_pf_mus_tpfms_px_->TestBit(kDoNotProcess)){
    c_pf_mus_tpfms_px_ = true;
  }else{
    c_pf_mus_tpfms_px_ = false;
  }
  if(b_pf_mus_tpfms_py_ && !b_pf_mus_tpfms_py_->TestBit(kDoNotProcess)){
    c_pf_mus_tpfms_py_ = true;
  }else{
    c_pf_mus_tpfms_py_ = false;
  }
  if(b_pf_mus_tpfms_pz_ && !b_pf_mus_tpfms_pz_->TestBit(kDoNotProcess)){
    c_pf_mus_tpfms_pz_ = true;
  }else{
    c_pf_mus_tpfms_pz_ = false;
  }
  if(b_pf_mus_tpfms_theta_ && !b_pf_mus_tpfms_theta_->TestBit(kDoNotProcess)){
    c_pf_mus_tpfms_theta_ = true;
  }else{
    c_pf_mus_tpfms_theta_ = false;
  }
  if(b_pf_mus_tpfms_vx_ && !b_pf_mus_tpfms_vx_->TestBit(kDoNotProcess)){
    c_pf_mus_tpfms_vx_ = true;
  }else{
    c_pf_mus_tpfms_vx_ = false;
  }
  if(b_pf_mus_tpfms_vy_ && !b_pf_mus_tpfms_vy_->TestBit(kDoNotProcess)){
    c_pf_mus_tpfms_vy_ = true;
  }else{
    c_pf_mus_tpfms_vy_ = false;
  }
  if(b_pf_mus_tpfms_vz_ && !b_pf_mus_tpfms_vz_->TestBit(kDoNotProcess)){
    c_pf_mus_tpfms_vz_ = true;
  }else{
    c_pf_mus_tpfms_vz_ = false;
  }
  if(b_pf_photons_chIso_ && !b_pf_photons_chIso_->TestBit(kDoNotProcess)){
    c_pf_photons_chIso_ = true;
  }else{
    c_pf_photons_chIso_ = false;
  }
  if(b_pf_photons_e1x5_ && !b_pf_photons_e1x5_->TestBit(kDoNotProcess)){
    c_pf_photons_e1x5_ = true;
  }else{
    c_pf_photons_e1x5_ = false;
  }
  if(b_pf_photons_e2x5_ && !b_pf_photons_e2x5_->TestBit(kDoNotProcess)){
    c_pf_photons_e2x5_ = true;
  }else{
    c_pf_photons_e2x5_ = false;
  }
  if(b_pf_photons_e3x3_ && !b_pf_photons_e3x3_->TestBit(kDoNotProcess)){
    c_pf_photons_e3x3_ = true;
  }else{
    c_pf_photons_e3x3_ = false;
  }
  if(b_pf_photons_e5x5_ && !b_pf_photons_e5x5_->TestBit(kDoNotProcess)){
    c_pf_photons_e5x5_ = true;
  }else{
    c_pf_photons_e5x5_ = false;
  }
  if(b_pf_photons_energy_ && !b_pf_photons_energy_->TestBit(kDoNotProcess)){
    c_pf_photons_energy_ = true;
  }else{
    c_pf_photons_energy_ = false;
  }
  if(b_pf_photons_et_ && !b_pf_photons_et_->TestBit(kDoNotProcess)){
    c_pf_photons_et_ = true;
  }else{
    c_pf_photons_et_ = false;
  }
  if(b_pf_photons_eta_ && !b_pf_photons_eta_->TestBit(kDoNotProcess)){
    c_pf_photons_eta_ = true;
  }else{
    c_pf_photons_eta_ = false;
  }
  if(b_pf_photons_hadOverEM_ && !b_pf_photons_hadOverEM_->TestBit(kDoNotProcess)){
    c_pf_photons_hadOverEM_ = true;
  }else{
    c_pf_photons_hadOverEM_ = false;
  }
  if(b_pf_photons_hadTowOverEM_ && !b_pf_photons_hadTowOverEM_->TestBit(kDoNotProcess)){
    c_pf_photons_hadTowOverEM_ = true;
  }else{
    c_pf_photons_hadTowOverEM_ = false;
  }
  if(b_pf_photons_hasPixelSeed_ && !b_pf_photons_hasPixelSeed_->TestBit(kDoNotProcess)){
    c_pf_photons_hasPixelSeed_ = true;
  }else{
    c_pf_photons_hasPixelSeed_ = false;
  }
  if(b_pf_photons_isAlsoElectron_ && !b_pf_photons_isAlsoElectron_->TestBit(kDoNotProcess)){
    c_pf_photons_isAlsoElectron_ = true;
  }else{
    c_pf_photons_isAlsoElectron_ = false;
  }
  if(b_pf_photons_isConverted_ && !b_pf_photons_isConverted_->TestBit(kDoNotProcess)){
    c_pf_photons_isConverted_ = true;
  }else{
    c_pf_photons_isConverted_ = false;
  }
  if(b_pf_photons_isEBEEGap_ && !b_pf_photons_isEBEEGap_->TestBit(kDoNotProcess)){
    c_pf_photons_isEBEEGap_ = true;
  }else{
    c_pf_photons_isEBEEGap_ = false;
  }
  if(b_pf_photons_isEBGap_ && !b_pf_photons_isEBGap_->TestBit(kDoNotProcess)){
    c_pf_photons_isEBGap_ = true;
  }else{
    c_pf_photons_isEBGap_ = false;
  }
  if(b_pf_photons_isEBPho_ && !b_pf_photons_isEBPho_->TestBit(kDoNotProcess)){
    c_pf_photons_isEBPho_ = true;
  }else{
    c_pf_photons_isEBPho_ = false;
  }
  if(b_pf_photons_isEEGap_ && !b_pf_photons_isEEGap_->TestBit(kDoNotProcess)){
    c_pf_photons_isEEGap_ = true;
  }else{
    c_pf_photons_isEEGap_ = false;
  }
  if(b_pf_photons_isEEPho_ && !b_pf_photons_isEEPho_->TestBit(kDoNotProcess)){
    c_pf_photons_isEEPho_ = true;
  }else{
    c_pf_photons_isEEPho_ = false;
  }
  if(b_pf_photons_maxEnergyXtal_ && !b_pf_photons_maxEnergyXtal_->TestBit(kDoNotProcess)){
    c_pf_photons_maxEnergyXtal_ = true;
  }else{
    c_pf_photons_maxEnergyXtal_ = false;
  }
  if(b_pf_photons_nhIso_ && !b_pf_photons_nhIso_->TestBit(kDoNotProcess)){
    c_pf_photons_nhIso_ = true;
  }else{
    c_pf_photons_nhIso_ = false;
  }
  if(b_pf_photons_phIso_ && !b_pf_photons_phIso_->TestBit(kDoNotProcess)){
    c_pf_photons_phIso_ = true;
  }else{
    c_pf_photons_phIso_ = false;
  }
  if(b_pf_photons_phi_ && !b_pf_photons_phi_->TestBit(kDoNotProcess)){
    c_pf_photons_phi_ = true;
  }else{
    c_pf_photons_phi_ = false;
  }
  if(b_pf_photons_pt_ && !b_pf_photons_pt_->TestBit(kDoNotProcess)){
    c_pf_photons_pt_ = true;
  }else{
    c_pf_photons_pt_ = false;
  }
  if(b_pf_photons_px_ && !b_pf_photons_px_->TestBit(kDoNotProcess)){
    c_pf_photons_px_ = true;
  }else{
    c_pf_photons_px_ = false;
  }
  if(b_pf_photons_py_ && !b_pf_photons_py_->TestBit(kDoNotProcess)){
    c_pf_photons_py_ = true;
  }else{
    c_pf_photons_py_ = false;
  }
  if(b_pf_photons_pz_ && !b_pf_photons_pz_->TestBit(kDoNotProcess)){
    c_pf_photons_pz_ = true;
  }else{
    c_pf_photons_pz_ = false;
  }
  if(b_pf_photons_r9_ && !b_pf_photons_r9_->TestBit(kDoNotProcess)){
    c_pf_photons_r9_ = true;
  }else{
    c_pf_photons_r9_ = false;
  }
  if(b_pf_photons_scEnergy_ && !b_pf_photons_scEnergy_->TestBit(kDoNotProcess)){
    c_pf_photons_scEnergy_ = true;
  }else{
    c_pf_photons_scEnergy_ = false;
  }
  if(b_pf_photons_scEta_ && !b_pf_photons_scEta_->TestBit(kDoNotProcess)){
    c_pf_photons_scEta_ = true;
  }else{
    c_pf_photons_scEta_ = false;
  }
  if(b_pf_photons_scEtaWidth_ && !b_pf_photons_scEtaWidth_->TestBit(kDoNotProcess)){
    c_pf_photons_scEtaWidth_ = true;
  }else{
    c_pf_photons_scEtaWidth_ = false;
  }
  if(b_pf_photons_scPhi_ && !b_pf_photons_scPhi_->TestBit(kDoNotProcess)){
    c_pf_photons_scPhi_ = true;
  }else{
    c_pf_photons_scPhi_ = false;
  }
  if(b_pf_photons_scPhiWidth_ && !b_pf_photons_scPhiWidth_->TestBit(kDoNotProcess)){
    c_pf_photons_scPhiWidth_ = true;
  }else{
    c_pf_photons_scPhiWidth_ = false;
  }
  if(b_pf_photons_scRawEnergy_ && !b_pf_photons_scRawEnergy_->TestBit(kDoNotProcess)){
    c_pf_photons_scRawEnergy_ = true;
  }else{
    c_pf_photons_scRawEnergy_ = false;
  }
  if(b_pf_photons_sigmaEtaEta_ && !b_pf_photons_sigmaEtaEta_->TestBit(kDoNotProcess)){
    c_pf_photons_sigmaEtaEta_ = true;
  }else{
    c_pf_photons_sigmaEtaEta_ = false;
  }
  if(b_pf_photons_sigmaIetaIeta_ && !b_pf_photons_sigmaIetaIeta_->TestBit(kDoNotProcess)){
    c_pf_photons_sigmaIetaIeta_ = true;
  }else{
    c_pf_photons_sigmaIetaIeta_ = false;
  }
  if(b_pf_photons_status_ && !b_pf_photons_status_->TestBit(kDoNotProcess)){
    c_pf_photons_status_ = true;
  }else{
    c_pf_photons_status_ = false;
  }
  if(b_pf_photons_theta_ && !b_pf_photons_theta_->TestBit(kDoNotProcess)){
    c_pf_photons_theta_ = true;
  }else{
    c_pf_photons_theta_ = false;
  }
  if(b_pfcand_particleId_ && !b_pfcand_particleId_->TestBit(kDoNotProcess)){
    c_pfcand_particleId_ = true;
  }else{
    c_pfcand_particleId_ = false;
  }
  if(b_pfmets_et_ && !b_pfmets_et_->TestBit(kDoNotProcess)){
    c_pfmets_et_ = true;
  }else{
    c_pfmets_et_ = false;
  }
  if(b_pfmets_ex_ && !b_pfmets_ex_->TestBit(kDoNotProcess)){
    c_pfmets_ex_ = true;
  }else{
    c_pfmets_ex_ = false;
  }
  if(b_pfmets_ey_ && !b_pfmets_ey_->TestBit(kDoNotProcess)){
    c_pfmets_ey_ = true;
  }else{
    c_pfmets_ey_ = false;
  }
  if(b_pfmets_fullSignif_ && !b_pfmets_fullSignif_->TestBit(kDoNotProcess)){
    c_pfmets_fullSignif_ = true;
  }else{
    c_pfmets_fullSignif_ = false;
  }
  if(b_pfmets_fullSignifCov00_ && !b_pfmets_fullSignifCov00_->TestBit(kDoNotProcess)){
    c_pfmets_fullSignifCov00_ = true;
  }else{
    c_pfmets_fullSignifCov00_ = false;
  }
  if(b_pfmets_fullSignifCov00_2012_ && !b_pfmets_fullSignifCov00_2012_->TestBit(kDoNotProcess)){
    c_pfmets_fullSignifCov00_2012_ = true;
  }else{
    c_pfmets_fullSignifCov00_2012_ = false;
  }
  if(b_pfmets_fullSignifCov00_2012_dataRes_ && !b_pfmets_fullSignifCov00_2012_dataRes_->TestBit(kDoNotProcess)){
    c_pfmets_fullSignifCov00_2012_dataRes_ = true;
  }else{
    c_pfmets_fullSignifCov00_2012_dataRes_ = false;
  }
  if(b_pfmets_fullSignifCov10_ && !b_pfmets_fullSignifCov10_->TestBit(kDoNotProcess)){
    c_pfmets_fullSignifCov10_ = true;
  }else{
    c_pfmets_fullSignifCov10_ = false;
  }
  if(b_pfmets_fullSignifCov10_2012_ && !b_pfmets_fullSignifCov10_2012_->TestBit(kDoNotProcess)){
    c_pfmets_fullSignifCov10_2012_ = true;
  }else{
    c_pfmets_fullSignifCov10_2012_ = false;
  }
  if(b_pfmets_fullSignifCov10_2012_dataRes_ && !b_pfmets_fullSignifCov10_2012_dataRes_->TestBit(kDoNotProcess)){
    c_pfmets_fullSignifCov10_2012_dataRes_ = true;
  }else{
    c_pfmets_fullSignifCov10_2012_dataRes_ = false;
  }
  if(b_pfmets_fullSignifCov11_ && !b_pfmets_fullSignifCov11_->TestBit(kDoNotProcess)){
    c_pfmets_fullSignifCov11_ = true;
  }else{
    c_pfmets_fullSignifCov11_ = false;
  }
  if(b_pfmets_fullSignifCov11_2012_ && !b_pfmets_fullSignifCov11_2012_->TestBit(kDoNotProcess)){
    c_pfmets_fullSignifCov11_2012_ = true;
  }else{
    c_pfmets_fullSignifCov11_2012_ = false;
  }
  if(b_pfmets_fullSignifCov11_2012_dataRes_ && !b_pfmets_fullSignifCov11_2012_dataRes_->TestBit(kDoNotProcess)){
    c_pfmets_fullSignifCov11_2012_dataRes_ = true;
  }else{
    c_pfmets_fullSignifCov11_2012_dataRes_ = false;
  }
  if(b_pfmets_fullSignif_2012_ && !b_pfmets_fullSignif_2012_->TestBit(kDoNotProcess)){
    c_pfmets_fullSignif_2012_ = true;
  }else{
    c_pfmets_fullSignif_2012_ = false;
  }
  if(b_pfmets_fullSignif_2012_dataRes_ && !b_pfmets_fullSignif_2012_dataRes_->TestBit(kDoNotProcess)){
    c_pfmets_fullSignif_2012_dataRes_ = true;
  }else{
    c_pfmets_fullSignif_2012_dataRes_ = false;
  }
  if(b_pfmets_gen_et_ && !b_pfmets_gen_et_->TestBit(kDoNotProcess)){
    c_pfmets_gen_et_ = true;
  }else{
    c_pfmets_gen_et_ = false;
  }
  if(b_pfmets_gen_phi_ && !b_pfmets_gen_phi_->TestBit(kDoNotProcess)){
    c_pfmets_gen_phi_ = true;
  }else{
    c_pfmets_gen_phi_ = false;
  }
  if(b_pfmets_phi_ && !b_pfmets_phi_->TestBit(kDoNotProcess)){
    c_pfmets_phi_ = true;
  }else{
    c_pfmets_phi_ = false;
  }
  if(b_pfmets_sign_ && !b_pfmets_sign_->TestBit(kDoNotProcess)){
    c_pfmets_sign_ = true;
  }else{
    c_pfmets_sign_ = false;
  }
  if(b_pfmets_sumEt_ && !b_pfmets_sumEt_->TestBit(kDoNotProcess)){
    c_pfmets_sumEt_ = true;
  }else{
    c_pfmets_sumEt_ = false;
  }
  if(b_pfmets_unCPhi_ && !b_pfmets_unCPhi_->TestBit(kDoNotProcess)){
    c_pfmets_unCPhi_ = true;
  }else{
    c_pfmets_unCPhi_ = false;
  }
  if(b_pfmets_unCPt_ && !b_pfmets_unCPt_->TestBit(kDoNotProcess)){
    c_pfmets_unCPt_ = true;
  }else{
    c_pfmets_unCPt_ = false;
  }
  if(b_photon_chIsoValues_ && !b_photon_chIsoValues_->TestBit(kDoNotProcess)){
    c_photon_chIsoValues_ = true;
  }else{
    c_photon_chIsoValues_ = false;
  }
  if(b_photon_nhIsoValues_ && !b_photon_nhIsoValues_->TestBit(kDoNotProcess)){
    c_photon_nhIsoValues_ = true;
  }else{
    c_photon_nhIsoValues_ = false;
  }
  if(b_photon_passElectronVeto_ && !b_photon_passElectronVeto_->TestBit(kDoNotProcess)){
    c_photon_passElectronVeto_ = true;
  }else{
    c_photon_passElectronVeto_ = false;
  }
  if(b_photon_phIsoValues_ && !b_photon_phIsoValues_->TestBit(kDoNotProcess)){
    c_photon_phIsoValues_ = true;
  }else{
    c_photon_phIsoValues_ = false;
  }
  if(b_puJet_rejectionBeta_ && !b_puJet_rejectionBeta_->TestBit(kDoNotProcess)){
    c_puJet_rejectionBeta_ = true;
  }else{
    c_puJet_rejectionBeta_ = false;
  }
  if(b_puJet_rejectionMVA_ && !b_puJet_rejectionMVA_->TestBit(kDoNotProcess)){
    c_puJet_rejectionMVA_ = true;
  }else{
    c_puJet_rejectionMVA_ = false;
  }
  if(b_rho_kt6PFJetsForIsolation2011_ && !b_rho_kt6PFJetsForIsolation2011_->TestBit(kDoNotProcess)){
    c_rho_kt6PFJetsForIsolation2011_ = true;
  }else{
    c_rho_kt6PFJetsForIsolation2011_ = false;
  }
  if(b_rho_kt6PFJetsForIsolation2012_ && !b_rho_kt6PFJetsForIsolation2012_->TestBit(kDoNotProcess)){
    c_rho_kt6PFJetsForIsolation2012_ = true;
  }else{
    c_rho_kt6PFJetsForIsolation2012_ = false;
  }
  if(b_scrapingVeto_decision_ && !b_scrapingVeto_decision_->TestBit(kDoNotProcess)){
    c_scrapingVeto_decision_ = true;
  }else{
    c_scrapingVeto_decision_ = false;
  }
  if(b_softjetUp_dMEx_ && !b_softjetUp_dMEx_->TestBit(kDoNotProcess)){
    c_softjetUp_dMEx_ = true;
  }else{
    c_softjetUp_dMEx_ = false;
  }
  if(b_softjetUp_dMEy_ && !b_softjetUp_dMEy_->TestBit(kDoNotProcess)){
    c_softjetUp_dMEy_ = true;
  }else{
    c_softjetUp_dMEy_ = false;
  }
  if(b_tcmets_et_ && !b_tcmets_et_->TestBit(kDoNotProcess)){
    c_tcmets_et_ = true;
  }else{
    c_tcmets_et_ = false;
  }
  if(b_tcmets_ex_ && !b_tcmets_ex_->TestBit(kDoNotProcess)){
    c_tcmets_ex_ = true;
  }else{
    c_tcmets_ex_ = false;
  }
  if(b_tcmets_ey_ && !b_tcmets_ey_->TestBit(kDoNotProcess)){
    c_tcmets_ey_ = true;
  }else{
    c_tcmets_ey_ = false;
  }
  if(b_tcmets_phi_ && !b_tcmets_phi_->TestBit(kDoNotProcess)){
    c_tcmets_phi_ = true;
  }else{
    c_tcmets_phi_ = false;
  }
  if(b_tcmets_sumEt_ && !b_tcmets_sumEt_->TestBit(kDoNotProcess)){
    c_tcmets_sumEt_ = true;
  }else{
    c_tcmets_sumEt_ = false;
  }
  if(b_trackercoherentnoisefilter1_decision_ && !b_trackercoherentnoisefilter1_decision_->TestBit(kDoNotProcess)){
    c_trackercoherentnoisefilter1_decision_ = true;
  }else{
    c_trackercoherentnoisefilter1_decision_ = false;
  }
  if(b_trackercoherentnoisefilter2_decision_ && !b_trackercoherentnoisefilter2_decision_->TestBit(kDoNotProcess)){
    c_trackercoherentnoisefilter2_decision_ = true;
  }else{
    c_trackercoherentnoisefilter2_decision_ = false;
  }
  if(b_trackertoomanyclustersfilter_decision_ && !b_trackertoomanyclustersfilter_decision_->TestBit(kDoNotProcess)){
    c_trackertoomanyclustersfilter_decision_ = true;
  }else{
    c_trackertoomanyclustersfilter_decision_ = false;
  }
  if(b_trackertoomanyseedsfilter_decision_ && !b_trackertoomanyseedsfilter_decision_->TestBit(kDoNotProcess)){
    c_trackertoomanyseedsfilter_decision_ = true;
  }else{
    c_trackertoomanyseedsfilter_decision_ = false;
  }
  if(b_trackertoomanytripletsfilter_decision_ && !b_trackertoomanytripletsfilter_decision_->TestBit(kDoNotProcess)){
    c_trackertoomanytripletsfilter_decision_ = true;
  }else{
    c_trackertoomanytripletsfilter_decision_ = false;
  }
  if(b_tracks_chg_ && !b_tracks_chg_->TestBit(kDoNotProcess)){
    c_tracks_chg_ = true;
  }else{
    c_tracks_chg_ = false;
  }
  if(b_tracks_chi2_ && !b_tracks_chi2_->TestBit(kDoNotProcess)){
    c_tracks_chi2_ = true;
  }else{
    c_tracks_chi2_ = false;
  }
  if(b_tracks_d0dum_ && !b_tracks_d0dum_->TestBit(kDoNotProcess)){
    c_tracks_d0dum_ = true;
  }else{
    c_tracks_d0dum_ = false;
  }
  if(b_tracks_d0dumErr_ && !b_tracks_d0dumErr_->TestBit(kDoNotProcess)){
    c_tracks_d0dumErr_ = true;
  }else{
    c_tracks_d0dumErr_ = false;
  }
  if(b_tracks_dz_ && !b_tracks_dz_->TestBit(kDoNotProcess)){
    c_tracks_dz_ = true;
  }else{
    c_tracks_dz_ = false;
  }
  if(b_tracks_dzErr_ && !b_tracks_dzErr_->TestBit(kDoNotProcess)){
    c_tracks_dzErr_ = true;
  }else{
    c_tracks_dzErr_ = false;
  }
  if(b_tracks_eta_ && !b_tracks_eta_->TestBit(kDoNotProcess)){
    c_tracks_eta_ = true;
  }else{
    c_tracks_eta_ = false;
  }
  if(b_tracks_etaErr_ && !b_tracks_etaErr_->TestBit(kDoNotProcess)){
    c_tracks_etaErr_ = true;
  }else{
    c_tracks_etaErr_ = false;
  }
  if(b_tracks_highPurity_ && !b_tracks_highPurity_->TestBit(kDoNotProcess)){
    c_tracks_highPurity_ = true;
  }else{
    c_tracks_highPurity_ = false;
  }
  if(b_tracks_ndof_ && !b_tracks_ndof_->TestBit(kDoNotProcess)){
    c_tracks_ndof_ = true;
  }else{
    c_tracks_ndof_ = false;
  }
  if(b_tracks_numlosthits_ && !b_tracks_numlosthits_->TestBit(kDoNotProcess)){
    c_tracks_numlosthits_ = true;
  }else{
    c_tracks_numlosthits_ = false;
  }
  if(b_tracks_numvalhits_ && !b_tracks_numvalhits_->TestBit(kDoNotProcess)){
    c_tracks_numvalhits_ = true;
  }else{
    c_tracks_numvalhits_ = false;
  }
  if(b_tracks_phi_ && !b_tracks_phi_->TestBit(kDoNotProcess)){
    c_tracks_phi_ = true;
  }else{
    c_tracks_phi_ = false;
  }
  if(b_tracks_phiErr_ && !b_tracks_phiErr_->TestBit(kDoNotProcess)){
    c_tracks_phiErr_ = true;
  }else{
    c_tracks_phiErr_ = false;
  }
  if(b_tracks_pt_ && !b_tracks_pt_->TestBit(kDoNotProcess)){
    c_tracks_pt_ = true;
  }else{
    c_tracks_pt_ = false;
  }
  if(b_tracks_ptErr_ && !b_tracks_ptErr_->TestBit(kDoNotProcess)){
    c_tracks_ptErr_ = true;
  }else{
    c_tracks_ptErr_ = false;
  }
  if(b_tracks_px_ && !b_tracks_px_->TestBit(kDoNotProcess)){
    c_tracks_px_ = true;
  }else{
    c_tracks_px_ = false;
  }
  if(b_tracks_py_ && !b_tracks_py_->TestBit(kDoNotProcess)){
    c_tracks_py_ = true;
  }else{
    c_tracks_py_ = false;
  }
  if(b_tracks_pz_ && !b_tracks_pz_->TestBit(kDoNotProcess)){
    c_tracks_pz_ = true;
  }else{
    c_tracks_pz_ = false;
  }
  if(b_tracks_vx_ && !b_tracks_vx_->TestBit(kDoNotProcess)){
    c_tracks_vx_ = true;
  }else{
    c_tracks_vx_ = false;
  }
  if(b_tracks_vy_ && !b_tracks_vy_->TestBit(kDoNotProcess)){
    c_tracks_vy_ = true;
  }else{
    c_tracks_vy_ = false;
  }
  if(b_tracks_vz_ && !b_tracks_vz_->TestBit(kDoNotProcess)){
    c_tracks_vz_ = true;
  }else{
    c_tracks_vz_ = false;
  }
  if(b_trigger_decision_ && !b_trigger_decision_->TestBit(kDoNotProcess)){
    c_trigger_decision_ = true;
  }else{
    c_trigger_decision_ = false;
  }
  if(b_trigger_lastfiltername_ && !b_trigger_lastfiltername_->TestBit(kDoNotProcess)){
    c_trigger_lastfiltername_ = true;
  }else{
    c_trigger_lastfiltername_ = false;
  }
  if(b_triggerobject_collectionname_ && !b_triggerobject_collectionname_->TestBit(kDoNotProcess)){
    c_triggerobject_collectionname_ = true;
  }else{
    c_triggerobject_collectionname_ = false;
  }
  if(b_triggerobject_energy_ && !b_triggerobject_energy_->TestBit(kDoNotProcess)){
    c_triggerobject_energy_ = true;
  }else{
    c_triggerobject_energy_ = false;
  }
  if(b_triggerobject_et_ && !b_triggerobject_et_->TestBit(kDoNotProcess)){
    c_triggerobject_et_ = true;
  }else{
    c_triggerobject_et_ = false;
  }
  if(b_triggerobject_eta_ && !b_triggerobject_eta_->TestBit(kDoNotProcess)){
    c_triggerobject_eta_ = true;
  }else{
    c_triggerobject_eta_ = false;
  }
  if(b_triggerobject_phi_ && !b_triggerobject_phi_->TestBit(kDoNotProcess)){
    c_triggerobject_phi_ = true;
  }else{
    c_triggerobject_phi_ = false;
  }
  if(b_triggerobject_pt_ && !b_triggerobject_pt_->TestBit(kDoNotProcess)){
    c_triggerobject_pt_ = true;
  }else{
    c_triggerobject_pt_ = false;
  }
  if(b_triggerobject_px_ && !b_triggerobject_px_->TestBit(kDoNotProcess)){
    c_triggerobject_px_ = true;
  }else{
    c_triggerobject_px_ = false;
  }
  if(b_triggerobject_py_ && !b_triggerobject_py_->TestBit(kDoNotProcess)){
    c_triggerobject_py_ = true;
  }else{
    c_triggerobject_py_ = false;
  }
  if(b_triggerobject_pz_ && !b_triggerobject_pz_->TestBit(kDoNotProcess)){
    c_triggerobject_pz_ = true;
  }else{
    c_triggerobject_pz_ = false;
  }
  if(b_trk_nTOBTEC_ && !b_trk_nTOBTEC_->TestBit(kDoNotProcess)){
    c_trk_nTOBTEC_ = true;
  }else{
    c_trk_nTOBTEC_ = false;
  }
  if(b_trk_ratioAllTOBTEC_ && !b_trk_ratioAllTOBTEC_->TestBit(kDoNotProcess)){
    c_trk_ratioAllTOBTEC_ = true;
  }else{
    c_trk_ratioAllTOBTEC_ = false;
  }
  if(b_trk_ratioJetTOBTEC_ && !b_trk_ratioJetTOBTEC_->TestBit(kDoNotProcess)){
    c_trk_ratioJetTOBTEC_ = true;
  }else{
    c_trk_ratioJetTOBTEC_ = false;
  }
  cfa_base::GetEntry(entry);
}

void cfa_8::InitializeA(){
  cfa_base::InitializeA();
  chainA_.SetBranchAddress("L1trigger_alias", &L1trigger_alias_, &b_L1trigger_alias_);
  chainA_.SetBranchAddress("L1trigger_bit", &L1trigger_bit_, &b_L1trigger_bit_);
  chainA_.SetBranchAddress("L1trigger_decision", &L1trigger_decision_, &b_L1trigger_decision_);
  chainA_.SetBranchAddress("L1trigger_decision_nomask", &L1trigger_decision_nomask_, &b_L1trigger_decision_nomask_);
  chainA_.SetBranchAddress("L1trigger_name", &L1trigger_name_, &b_L1trigger_name_);
  chainA_.SetBranchAddress("L1trigger_prescalevalue", &L1trigger_prescalevalue_, &b_L1trigger_prescalevalue_);
  chainA_.SetBranchAddress("L1trigger_techTrigger", &L1trigger_techTrigger_, &b_L1trigger_techTrigger_);
  chainA_.SetBranchAddress("MPT", &MPT_, &b_MPT_);
  chainA_.SetBranchAddress("ecalBEfilter_decision", &ecalBEfilter_decision_, &b_ecalBEfilter_decision_);
  chainA_.SetBranchAddress("ecalTPfilter_decision", &ecalTPfilter_decision_, &b_ecalTPfilter_decision_);
  chainA_.SetBranchAddress("eenoisefilter_decision", &eenoisefilter_decision_, &b_eenoisefilter_decision_);
  chainA_.SetBranchAddress("els_PFchargedHadronIsoR03", &els_PFchargedHadronIsoR03_, &b_els_PFchargedHadronIsoR03_);
  chainA_.SetBranchAddress("els_PFneutralHadronIsoR03", &els_PFneutralHadronIsoR03_, &b_els_PFneutralHadronIsoR03_);
  chainA_.SetBranchAddress("els_PFphotonIsoR03", &els_PFphotonIsoR03_, &b_els_PFphotonIsoR03_);
  chainA_.SetBranchAddress("els_conversion_dcot", &els_conversion_dcot_, &b_els_conversion_dcot_);
  chainA_.SetBranchAddress("els_conversion_dist", &els_conversion_dist_, &b_els_conversion_dist_);
  chainA_.SetBranchAddress("els_hasMatchedConversion", &els_hasMatchedConversion_, &b_els_hasMatchedConversion_);
  chainA_.SetBranchAddress("genHT", &genHT_, &b_genHT_);
  chainA_.SetBranchAddress("greedymuonfilter_decision", &greedymuonfilter_decision_, &b_greedymuonfilter_decision_);
  chainA_.SetBranchAddress("hbhefilter_decision", &hbhefilter_decision_, &b_hbhefilter_decision_);
  chainA_.SetBranchAddress("inconsistentPFmuonfilter_decision", &inconsistentPFmuonfilter_decision_, &b_inconsistentPFmuonfilter_decision_);
  chainA_.SetBranchAddress("isotk_charge", &isotk_charge_, &b_isotk_charge_);
  chainA_.SetBranchAddress("isotk_dzpv", &isotk_dzpv_, &b_isotk_dzpv_);
  chainA_.SetBranchAddress("isotk_eta", &isotk_eta_, &b_isotk_eta_);
  chainA_.SetBranchAddress("isotk_iso", &isotk_iso_, &b_isotk_iso_);
  chainA_.SetBranchAddress("isotk_phi", &isotk_phi_, &b_isotk_phi_);
  chainA_.SetBranchAddress("isotk_pt", &isotk_pt_, &b_isotk_pt_);
  chainA_.SetBranchAddress("jets_AK5PFclean_Uncert", &jets_AK5PFclean_Uncert_, &b_jets_AK5PFclean_Uncert_);
  chainA_.SetBranchAddress("jets_AK5PFclean_corrL1FastL2L3", &jets_AK5PFclean_corrL1FastL2L3_, &b_jets_AK5PFclean_corrL1FastL2L3_);
  chainA_.SetBranchAddress("jets_AK5PFclean_corrL1FastL2L3Residual", &jets_AK5PFclean_corrL1FastL2L3Residual_, &b_jets_AK5PFclean_corrL1FastL2L3Residual_);
  chainA_.SetBranchAddress("jets_AK5PFclean_corrL1L2L3", &jets_AK5PFclean_corrL1L2L3_, &b_jets_AK5PFclean_corrL1L2L3_);
  chainA_.SetBranchAddress("jets_AK5PFclean_corrL1L2L3Residual", &jets_AK5PFclean_corrL1L2L3Residual_, &b_jets_AK5PFclean_corrL1L2L3Residual_);
  chainA_.SetBranchAddress("jets_AK5PFclean_corrL2L3", &jets_AK5PFclean_corrL2L3_, &b_jets_AK5PFclean_corrL2L3_);
  chainA_.SetBranchAddress("jets_AK5PFclean_corrL2L3Residual", &jets_AK5PFclean_corrL2L3Residual_, &b_jets_AK5PFclean_corrL2L3Residual_);
  chainA_.SetBranchAddress("passprescaleHT250filter_decision", &passprescaleHT250filter_decision_, &b_passprescaleHT250filter_decision_);
  chainA_.SetBranchAddress("passprescaleHT300filter_decision", &passprescaleHT300filter_decision_, &b_passprescaleHT300filter_decision_);
  chainA_.SetBranchAddress("passprescaleHT350filter_decision", &passprescaleHT350filter_decision_, &b_passprescaleHT350filter_decision_);
  chainA_.SetBranchAddress("passprescaleHT400filter_decision", &passprescaleHT400filter_decision_, &b_passprescaleHT400filter_decision_);
  chainA_.SetBranchAddress("passprescaleHT450filter_decision", &passprescaleHT450filter_decision_, &b_passprescaleHT450filter_decision_);
  chainA_.SetBranchAddress("passprescaleJet30MET80filter_decision", &passprescaleJet30MET80filter_decision_, &b_passprescaleJet30MET80filter_decision_);
  chainA_.SetBranchAddress("passprescalePFHT350filter_decision", &passprescalePFHT350filter_decision_, &b_passprescalePFHT350filter_decision_);
  chainA_.SetBranchAddress("pdfweights_cteq", &pdfweights_cteq_, &b_pdfweights_cteq_);
  chainA_.SetBranchAddress("pdfweights_mstw", &pdfweights_mstw_, &b_pdfweights_mstw_);
  chainA_.SetBranchAddress("pdfweights_nnpdf", &pdfweights_nnpdf_, &b_pdfweights_nnpdf_);
  chainA_.SetBranchAddress("pf_els_PFchargedHadronIsoR03", &pf_els_PFchargedHadronIsoR03_, &b_pf_els_PFchargedHadronIsoR03_);
  chainA_.SetBranchAddress("pf_els_PFneutralHadronIsoR03", &pf_els_PFneutralHadronIsoR03_, &b_pf_els_PFneutralHadronIsoR03_);
  chainA_.SetBranchAddress("pf_els_PFphotonIsoR03", &pf_els_PFphotonIsoR03_, &b_pf_els_PFphotonIsoR03_);
  chainA_.SetBranchAddress("pf_els_hasMatchedConversion", &pf_els_hasMatchedConversion_, &b_pf_els_hasMatchedConversion_);
  chainA_.SetBranchAddress("pfmets_fullSignif", &pfmets_fullSignif_, &b_pfmets_fullSignif_);
  chainA_.SetBranchAddress("pfmets_fullSignifCov00", &pfmets_fullSignifCov00_, &b_pfmets_fullSignifCov00_);
  chainA_.SetBranchAddress("pfmets_fullSignifCov00_2012", &pfmets_fullSignifCov00_2012_, &b_pfmets_fullSignifCov00_2012_);
  chainA_.SetBranchAddress("pfmets_fullSignifCov00_2012_dataRes", &pfmets_fullSignifCov00_2012_dataRes_, &b_pfmets_fullSignifCov00_2012_dataRes_);
  chainA_.SetBranchAddress("pfmets_fullSignifCov10", &pfmets_fullSignifCov10_, &b_pfmets_fullSignifCov10_);
  chainA_.SetBranchAddress("pfmets_fullSignifCov10_2012", &pfmets_fullSignifCov10_2012_, &b_pfmets_fullSignifCov10_2012_);
  chainA_.SetBranchAddress("pfmets_fullSignifCov10_2012_dataRes", &pfmets_fullSignifCov10_2012_dataRes_, &b_pfmets_fullSignifCov10_2012_dataRes_);
  chainA_.SetBranchAddress("pfmets_fullSignifCov11", &pfmets_fullSignifCov11_, &b_pfmets_fullSignifCov11_);
  chainA_.SetBranchAddress("pfmets_fullSignifCov11_2012", &pfmets_fullSignifCov11_2012_, &b_pfmets_fullSignifCov11_2012_);
  chainA_.SetBranchAddress("pfmets_fullSignifCov11_2012_dataRes", &pfmets_fullSignifCov11_2012_dataRes_, &b_pfmets_fullSignifCov11_2012_dataRes_);
  chainA_.SetBranchAddress("pfmets_fullSignif_2012", &pfmets_fullSignif_2012_, &b_pfmets_fullSignif_2012_);
  chainA_.SetBranchAddress("pfmets_fullSignif_2012_dataRes", &pfmets_fullSignif_2012_dataRes_, &b_pfmets_fullSignif_2012_dataRes_);
  chainA_.SetBranchAddress("photon_chIsoValues", &photon_chIsoValues_, &b_photon_chIsoValues_);
  chainA_.SetBranchAddress("photon_nhIsoValues", &photon_nhIsoValues_, &b_photon_nhIsoValues_);
  chainA_.SetBranchAddress("photon_passElectronVeto", &photon_passElectronVeto_, &b_photon_passElectronVeto_);
  chainA_.SetBranchAddress("photon_phIsoValues", &photon_phIsoValues_, &b_photon_phIsoValues_);
  chainA_.SetBranchAddress("puJet_rejectionBeta", &puJet_rejectionBeta_, &b_puJet_rejectionBeta_);
  chainA_.SetBranchAddress("puJet_rejectionMVA", &puJet_rejectionMVA_, &b_puJet_rejectionMVA_);
  chainA_.SetBranchAddress("rho_kt6PFJetsForIsolation2011", &rho_kt6PFJetsForIsolation2011_, &b_rho_kt6PFJetsForIsolation2011_);
  chainA_.SetBranchAddress("rho_kt6PFJetsForIsolation2012", &rho_kt6PFJetsForIsolation2012_, &b_rho_kt6PFJetsForIsolation2012_);
  chainA_.SetBranchAddress("scrapingVeto_decision", &scrapingVeto_decision_, &b_scrapingVeto_decision_);
  chainA_.SetBranchAddress("softjetUp_dMEx", &softjetUp_dMEx_, &b_softjetUp_dMEx_);
  chainA_.SetBranchAddress("softjetUp_dMEy", &softjetUp_dMEy_, &b_softjetUp_dMEy_);
  chainA_.SetBranchAddress("trackercoherentnoisefilter1_decision", &trackercoherentnoisefilter1_decision_, &b_trackercoherentnoisefilter1_decision_);
  chainA_.SetBranchAddress("trackercoherentnoisefilter2_decision", &trackercoherentnoisefilter2_decision_, &b_trackercoherentnoisefilter2_decision_);
  chainA_.SetBranchAddress("trackertoomanyclustersfilter_decision", &trackertoomanyclustersfilter_decision_, &b_trackertoomanyclustersfilter_decision_);
  chainA_.SetBranchAddress("trackertoomanyseedsfilter_decision", &trackertoomanyseedsfilter_decision_, &b_trackertoomanyseedsfilter_decision_);
  chainA_.SetBranchAddress("trackertoomanytripletsfilter_decision", &trackertoomanytripletsfilter_decision_, &b_trackertoomanytripletsfilter_decision_);
  chainA_.SetBranchAddress("trigger_decision", &trigger_decision_, &b_trigger_decision_);
  chainA_.SetBranchAddress("trigger_decision", &v_trigger_decision_, &b_trigger_decision_);
  chainA_.SetBranchAddress("trigger_lastfiltername", &trigger_lastfiltername_, &b_trigger_lastfiltername_);
  chainA_.SetBranchAddress("triggerobject_collectionname", &triggerobject_collectionname_, &b_triggerobject_collectionname_);
  chainA_.SetBranchAddress("triggerobject_energy", &triggerobject_energy_, &b_triggerobject_energy_);
  chainA_.SetBranchAddress("triggerobject_et", &triggerobject_et_, &b_triggerobject_et_);
  chainA_.SetBranchAddress("triggerobject_eta", &triggerobject_eta_, &b_triggerobject_eta_);
  chainA_.SetBranchAddress("triggerobject_phi", &triggerobject_phi_, &b_triggerobject_phi_);
  chainA_.SetBranchAddress("triggerobject_pt", &triggerobject_pt_, &b_triggerobject_pt_);
  chainA_.SetBranchAddress("triggerobject_px", &triggerobject_px_, &b_triggerobject_px_);
  chainA_.SetBranchAddress("triggerobject_py", &triggerobject_py_, &b_triggerobject_py_);
  chainA_.SetBranchAddress("triggerobject_pz", &triggerobject_pz_, &b_triggerobject_pz_);
  chainA_.SetBranchAddress("trk_nTOBTEC", &trk_nTOBTEC_, &b_trk_nTOBTEC_);
  chainA_.SetBranchAddress("trk_ratioAllTOBTEC", &trk_ratioAllTOBTEC_, &b_trk_ratioAllTOBTEC_);
  chainA_.SetBranchAddress("trk_ratioJetTOBTEC", &trk_ratioJetTOBTEC_, &b_trk_ratioJetTOBTEC_);
}

void cfa_8::InitializeB(){
  cfa_base::InitializeB();
  chainB_.SetBranchAddress("Njets_AK5PF", &Njets_AK5PF_, &b_Njets_AK5PF_);
  chainB_.SetBranchAddress("Njets_AK5PFclean", &Njets_AK5PFclean_, &b_Njets_AK5PFclean_);
  chainB_.SetBranchAddress("Nmc_pdf", &Nmc_pdf_, &b_Nmc_pdf_);
  chainB_.SetBranchAddress("NmetsHO", &NmetsHO_, &b_NmetsHO_);
  chainB_.SetBranchAddress("Nmets_AK5", &Nmets_AK5_, &b_Nmets_AK5_);
  chainB_.SetBranchAddress("NpfTypeINoXYCorrmets", &NpfTypeINoXYCorrmets_, &b_NpfTypeINoXYCorrmets_);
  chainB_.SetBranchAddress("NpfTypeIType0mets", &NpfTypeIType0mets_, &b_NpfTypeIType0mets_);
  chainB_.SetBranchAddress("NpfTypeImets", &NpfTypeImets_, &b_NpfTypeImets_);
  chainB_.SetBranchAddress("Npf_els", &Npf_els_, &b_Npf_els_);
  chainB_.SetBranchAddress("Npf_mus", &Npf_mus_, &b_Npf_mus_);
  chainB_.SetBranchAddress("Npf_photons", &Npf_photons_, &b_Npf_photons_);
  chainB_.SetBranchAddress("Npfmets", &Npfmets_, &b_Npfmets_);
  chainB_.SetBranchAddress("Ntcmets", &Ntcmets_, &b_Ntcmets_);
  chainB_.SetBranchAddress("Ntracks", &Ntracks_, &b_Ntracks_);
  chainB_.SetBranchAddress("jets_AK5PF_area", &jets_AK5PF_area_, &b_jets_AK5PF_area_);
  chainB_.SetBranchAddress("jets_AK5PF_btag_TC_highEff", &jets_AK5PF_btag_TC_highEff_, &b_jets_AK5PF_btag_TC_highEff_);
  chainB_.SetBranchAddress("jets_AK5PF_btag_TC_highPur", &jets_AK5PF_btag_TC_highPur_, &b_jets_AK5PF_btag_TC_highPur_);
  chainB_.SetBranchAddress("jets_AK5PF_btag_jetBProb", &jets_AK5PF_btag_jetBProb_, &b_jets_AK5PF_btag_jetBProb_);
  chainB_.SetBranchAddress("jets_AK5PF_btag_jetProb", &jets_AK5PF_btag_jetProb_, &b_jets_AK5PF_btag_jetProb_);
  chainB_.SetBranchAddress("jets_AK5PF_btag_secVertexCombined", &jets_AK5PF_btag_secVertexCombined_, &b_jets_AK5PF_btag_secVertexCombined_);
  chainB_.SetBranchAddress("jets_AK5PF_btag_secVertexHighEff", &jets_AK5PF_btag_secVertexHighEff_, &b_jets_AK5PF_btag_secVertexHighEff_);
  chainB_.SetBranchAddress("jets_AK5PF_btag_secVertexHighPur", &jets_AK5PF_btag_secVertexHighPur_, &b_jets_AK5PF_btag_secVertexHighPur_);
  chainB_.SetBranchAddress("jets_AK5PF_btag_softEle", &jets_AK5PF_btag_softEle_, &b_jets_AK5PF_btag_softEle_);
  chainB_.SetBranchAddress("jets_AK5PF_btag_softMuon", &jets_AK5PF_btag_softMuon_, &b_jets_AK5PF_btag_softMuon_);
  chainB_.SetBranchAddress("jets_AK5PF_chgEmE", &jets_AK5PF_chgEmE_, &b_jets_AK5PF_chgEmE_);
  chainB_.SetBranchAddress("jets_AK5PF_chgHadE", &jets_AK5PF_chgHadE_, &b_jets_AK5PF_chgHadE_);
  chainB_.SetBranchAddress("jets_AK5PF_chgMuE", &jets_AK5PF_chgMuE_, &b_jets_AK5PF_chgMuE_);
  chainB_.SetBranchAddress("jets_AK5PF_chg_Mult", &jets_AK5PF_chg_Mult_, &b_jets_AK5PF_chg_Mult_);
  chainB_.SetBranchAddress("jets_AK5PF_corrFactorRaw", &jets_AK5PF_corrFactorRaw_, &b_jets_AK5PF_corrFactorRaw_);
  chainB_.SetBranchAddress("jets_AK5PF_ehf", &jets_AK5PF_ehf_, &b_jets_AK5PF_ehf_);
  chainB_.SetBranchAddress("jets_AK5PF_emf", &jets_AK5PF_emf_, &b_jets_AK5PF_emf_);
  chainB_.SetBranchAddress("jets_AK5PF_energy", &jets_AK5PF_energy_, &b_jets_AK5PF_energy_);
  chainB_.SetBranchAddress("jets_AK5PF_et", &jets_AK5PF_et_, &b_jets_AK5PF_et_);
  chainB_.SetBranchAddress("jets_AK5PF_eta", &jets_AK5PF_eta_, &b_jets_AK5PF_eta_);
  chainB_.SetBranchAddress("jets_AK5PF_etaetaMoment", &jets_AK5PF_etaetaMoment_, &b_jets_AK5PF_etaetaMoment_);
  chainB_.SetBranchAddress("jets_AK5PF_etaphiMoment", &jets_AK5PF_etaphiMoment_, &b_jets_AK5PF_etaphiMoment_);
  chainB_.SetBranchAddress("jets_AK5PF_fHPD", &jets_AK5PF_fHPD_, &b_jets_AK5PF_fHPD_);
  chainB_.SetBranchAddress("jets_AK5PF_fRBX", &jets_AK5PF_fRBX_, &b_jets_AK5PF_fRBX_);
  chainB_.SetBranchAddress("jets_AK5PF_fSubDetector1", &jets_AK5PF_fSubDetector1_, &b_jets_AK5PF_fSubDetector1_);
  chainB_.SetBranchAddress("jets_AK5PF_fSubDetector2", &jets_AK5PF_fSubDetector2_, &b_jets_AK5PF_fSubDetector2_);
  chainB_.SetBranchAddress("jets_AK5PF_fSubDetector3", &jets_AK5PF_fSubDetector3_, &b_jets_AK5PF_fSubDetector3_);
  chainB_.SetBranchAddress("jets_AK5PF_fSubDetector4", &jets_AK5PF_fSubDetector4_, &b_jets_AK5PF_fSubDetector4_);
  chainB_.SetBranchAddress("jets_AK5PF_gen_Energy", &jets_AK5PF_gen_Energy_, &b_jets_AK5PF_gen_Energy_);
  chainB_.SetBranchAddress("jets_AK5PF_gen_Id", &jets_AK5PF_gen_Id_, &b_jets_AK5PF_gen_Id_);
  chainB_.SetBranchAddress("jets_AK5PF_gen_et", &jets_AK5PF_gen_et_, &b_jets_AK5PF_gen_et_);
  chainB_.SetBranchAddress("jets_AK5PF_gen_eta", &jets_AK5PF_gen_eta_, &b_jets_AK5PF_gen_eta_);
  chainB_.SetBranchAddress("jets_AK5PF_gen_mass", &jets_AK5PF_gen_mass_, &b_jets_AK5PF_gen_mass_);
  chainB_.SetBranchAddress("jets_AK5PF_gen_motherID", &jets_AK5PF_gen_motherID_, &b_jets_AK5PF_gen_motherID_);
  chainB_.SetBranchAddress("jets_AK5PF_gen_phi", &jets_AK5PF_gen_phi_, &b_jets_AK5PF_gen_phi_);
  chainB_.SetBranchAddress("jets_AK5PF_gen_pt", &jets_AK5PF_gen_pt_, &b_jets_AK5PF_gen_pt_);
  chainB_.SetBranchAddress("jets_AK5PF_gen_threeCharge", &jets_AK5PF_gen_threeCharge_, &b_jets_AK5PF_gen_threeCharge_);
  chainB_.SetBranchAddress("jets_AK5PF_hitsInN90", &jets_AK5PF_hitsInN90_, &b_jets_AK5PF_hitsInN90_);
  chainB_.SetBranchAddress("jets_AK5PF_jetCharge", &jets_AK5PF_jetCharge_, &b_jets_AK5PF_jetCharge_);
  chainB_.SetBranchAddress("jets_AK5PF_mass", &jets_AK5PF_mass_, &b_jets_AK5PF_mass_);
  chainB_.SetBranchAddress("jets_AK5PF_mu_Mult", &jets_AK5PF_mu_Mult_, &b_jets_AK5PF_mu_Mult_);
  chainB_.SetBranchAddress("jets_AK5PF_n60", &jets_AK5PF_n60_, &b_jets_AK5PF_n60_);
  chainB_.SetBranchAddress("jets_AK5PF_n90", &jets_AK5PF_n90_, &b_jets_AK5PF_n90_);
  chainB_.SetBranchAddress("jets_AK5PF_n90Hits", &jets_AK5PF_n90Hits_, &b_jets_AK5PF_n90Hits_);
  chainB_.SetBranchAddress("jets_AK5PF_nECALTowers", &jets_AK5PF_nECALTowers_, &b_jets_AK5PF_nECALTowers_);
  chainB_.SetBranchAddress("jets_AK5PF_nHCALTowers", &jets_AK5PF_nHCALTowers_, &b_jets_AK5PF_nHCALTowers_);
  chainB_.SetBranchAddress("jets_AK5PF_neutralEmE", &jets_AK5PF_neutralEmE_, &b_jets_AK5PF_neutralEmE_);
  chainB_.SetBranchAddress("jets_AK5PF_neutralHadE", &jets_AK5PF_neutralHadE_, &b_jets_AK5PF_neutralHadE_);
  chainB_.SetBranchAddress("jets_AK5PF_neutral_Mult", &jets_AK5PF_neutral_Mult_, &b_jets_AK5PF_neutral_Mult_);
  chainB_.SetBranchAddress("jets_AK5PF_partonFlavour", &jets_AK5PF_partonFlavour_, &b_jets_AK5PF_partonFlavour_);
  chainB_.SetBranchAddress("jets_AK5PF_parton_Energy", &jets_AK5PF_parton_Energy_, &b_jets_AK5PF_parton_Energy_);
  chainB_.SetBranchAddress("jets_AK5PF_parton_Id", &jets_AK5PF_parton_Id_, &b_jets_AK5PF_parton_Id_);
  chainB_.SetBranchAddress("jets_AK5PF_parton_eta", &jets_AK5PF_parton_eta_, &b_jets_AK5PF_parton_eta_);
  chainB_.SetBranchAddress("jets_AK5PF_parton_mass", &jets_AK5PF_parton_mass_, &b_jets_AK5PF_parton_mass_);
  chainB_.SetBranchAddress("jets_AK5PF_parton_motherId", &jets_AK5PF_parton_motherId_, &b_jets_AK5PF_parton_motherId_);
  chainB_.SetBranchAddress("jets_AK5PF_parton_phi", &jets_AK5PF_parton_phi_, &b_jets_AK5PF_parton_phi_);
  chainB_.SetBranchAddress("jets_AK5PF_parton_pt", &jets_AK5PF_parton_pt_, &b_jets_AK5PF_parton_pt_);
  chainB_.SetBranchAddress("jets_AK5PF_phi", &jets_AK5PF_phi_, &b_jets_AK5PF_phi_);
  chainB_.SetBranchAddress("jets_AK5PF_phiphiMoment", &jets_AK5PF_phiphiMoment_, &b_jets_AK5PF_phiphiMoment_);
  chainB_.SetBranchAddress("jets_AK5PF_photonEnergy", &jets_AK5PF_photonEnergy_, &b_jets_AK5PF_photonEnergy_);
  chainB_.SetBranchAddress("jets_AK5PF_pt", &jets_AK5PF_pt_, &b_jets_AK5PF_pt_);
  chainB_.SetBranchAddress("jets_AK5PF_px", &jets_AK5PF_px_, &b_jets_AK5PF_px_);
  chainB_.SetBranchAddress("jets_AK5PF_py", &jets_AK5PF_py_, &b_jets_AK5PF_py_);
  chainB_.SetBranchAddress("jets_AK5PF_pz", &jets_AK5PF_pz_, &b_jets_AK5PF_pz_);
  chainB_.SetBranchAddress("jets_AK5PF_rawPt", &jets_AK5PF_rawPt_, &b_jets_AK5PF_rawPt_);
  chainB_.SetBranchAddress("jets_AK5PF_status", &jets_AK5PF_status_, &b_jets_AK5PF_status_);
  chainB_.SetBranchAddress("jets_AK5PF_theta", &jets_AK5PF_theta_, &b_jets_AK5PF_theta_);
  chainB_.SetBranchAddress("jets_AK5PFclean_area", &jets_AK5PFclean_area_, &b_jets_AK5PFclean_area_);
  chainB_.SetBranchAddress("jets_AK5PFclean_btag_TC_highEff", &jets_AK5PFclean_btag_TC_highEff_, &b_jets_AK5PFclean_btag_TC_highEff_);
  chainB_.SetBranchAddress("jets_AK5PFclean_btag_TC_highPur", &jets_AK5PFclean_btag_TC_highPur_, &b_jets_AK5PFclean_btag_TC_highPur_);
  chainB_.SetBranchAddress("jets_AK5PFclean_btag_jetBProb", &jets_AK5PFclean_btag_jetBProb_, &b_jets_AK5PFclean_btag_jetBProb_);
  chainB_.SetBranchAddress("jets_AK5PFclean_btag_jetProb", &jets_AK5PFclean_btag_jetProb_, &b_jets_AK5PFclean_btag_jetProb_);
  chainB_.SetBranchAddress("jets_AK5PFclean_btag_secVertexCombined", &jets_AK5PFclean_btag_secVertexCombined_, &b_jets_AK5PFclean_btag_secVertexCombined_);
  chainB_.SetBranchAddress("jets_AK5PFclean_btag_secVertexHighEff", &jets_AK5PFclean_btag_secVertexHighEff_, &b_jets_AK5PFclean_btag_secVertexHighEff_);
  chainB_.SetBranchAddress("jets_AK5PFclean_btag_secVertexHighPur", &jets_AK5PFclean_btag_secVertexHighPur_, &b_jets_AK5PFclean_btag_secVertexHighPur_);
  chainB_.SetBranchAddress("jets_AK5PFclean_btag_softEle", &jets_AK5PFclean_btag_softEle_, &b_jets_AK5PFclean_btag_softEle_);
  chainB_.SetBranchAddress("jets_AK5PFclean_btag_softMuon", &jets_AK5PFclean_btag_softMuon_, &b_jets_AK5PFclean_btag_softMuon_);
  chainB_.SetBranchAddress("jets_AK5PFclean_chgEmE", &jets_AK5PFclean_chgEmE_, &b_jets_AK5PFclean_chgEmE_);
  chainB_.SetBranchAddress("jets_AK5PFclean_chgHadE", &jets_AK5PFclean_chgHadE_, &b_jets_AK5PFclean_chgHadE_);
  chainB_.SetBranchAddress("jets_AK5PFclean_chgMuE", &jets_AK5PFclean_chgMuE_, &b_jets_AK5PFclean_chgMuE_);
  chainB_.SetBranchAddress("jets_AK5PFclean_chg_Mult", &jets_AK5PFclean_chg_Mult_, &b_jets_AK5PFclean_chg_Mult_);
  chainB_.SetBranchAddress("jets_AK5PFclean_corrFactorRaw", &jets_AK5PFclean_corrFactorRaw_, &b_jets_AK5PFclean_corrFactorRaw_);
  chainB_.SetBranchAddress("jets_AK5PFclean_ehf", &jets_AK5PFclean_ehf_, &b_jets_AK5PFclean_ehf_);
  chainB_.SetBranchAddress("jets_AK5PFclean_emf", &jets_AK5PFclean_emf_, &b_jets_AK5PFclean_emf_);
  chainB_.SetBranchAddress("jets_AK5PFclean_energy", &jets_AK5PFclean_energy_, &b_jets_AK5PFclean_energy_);
  chainB_.SetBranchAddress("jets_AK5PFclean_et", &jets_AK5PFclean_et_, &b_jets_AK5PFclean_et_);
  chainB_.SetBranchAddress("jets_AK5PFclean_eta", &jets_AK5PFclean_eta_, &b_jets_AK5PFclean_eta_);
  chainB_.SetBranchAddress("jets_AK5PFclean_etaetaMoment", &jets_AK5PFclean_etaetaMoment_, &b_jets_AK5PFclean_etaetaMoment_);
  chainB_.SetBranchAddress("jets_AK5PFclean_etaphiMoment", &jets_AK5PFclean_etaphiMoment_, &b_jets_AK5PFclean_etaphiMoment_);
  chainB_.SetBranchAddress("jets_AK5PFclean_fHPD", &jets_AK5PFclean_fHPD_, &b_jets_AK5PFclean_fHPD_);
  chainB_.SetBranchAddress("jets_AK5PFclean_fRBX", &jets_AK5PFclean_fRBX_, &b_jets_AK5PFclean_fRBX_);
  chainB_.SetBranchAddress("jets_AK5PFclean_fSubDetector1", &jets_AK5PFclean_fSubDetector1_, &b_jets_AK5PFclean_fSubDetector1_);
  chainB_.SetBranchAddress("jets_AK5PFclean_fSubDetector2", &jets_AK5PFclean_fSubDetector2_, &b_jets_AK5PFclean_fSubDetector2_);
  chainB_.SetBranchAddress("jets_AK5PFclean_fSubDetector3", &jets_AK5PFclean_fSubDetector3_, &b_jets_AK5PFclean_fSubDetector3_);
  chainB_.SetBranchAddress("jets_AK5PFclean_fSubDetector4", &jets_AK5PFclean_fSubDetector4_, &b_jets_AK5PFclean_fSubDetector4_);
  chainB_.SetBranchAddress("jets_AK5PFclean_gen_Energy", &jets_AK5PFclean_gen_Energy_, &b_jets_AK5PFclean_gen_Energy_);
  chainB_.SetBranchAddress("jets_AK5PFclean_gen_Id", &jets_AK5PFclean_gen_Id_, &b_jets_AK5PFclean_gen_Id_);
  chainB_.SetBranchAddress("jets_AK5PFclean_gen_et", &jets_AK5PFclean_gen_et_, &b_jets_AK5PFclean_gen_et_);
  chainB_.SetBranchAddress("jets_AK5PFclean_gen_eta", &jets_AK5PFclean_gen_eta_, &b_jets_AK5PFclean_gen_eta_);
  chainB_.SetBranchAddress("jets_AK5PFclean_gen_mass", &jets_AK5PFclean_gen_mass_, &b_jets_AK5PFclean_gen_mass_);
  chainB_.SetBranchAddress("jets_AK5PFclean_gen_phi", &jets_AK5PFclean_gen_phi_, &b_jets_AK5PFclean_gen_phi_);
  chainB_.SetBranchAddress("jets_AK5PFclean_gen_pt", &jets_AK5PFclean_gen_pt_, &b_jets_AK5PFclean_gen_pt_);
  chainB_.SetBranchAddress("jets_AK5PFclean_hitsInN90", &jets_AK5PFclean_hitsInN90_, &b_jets_AK5PFclean_hitsInN90_);
  chainB_.SetBranchAddress("jets_AK5PFclean_jetCharge", &jets_AK5PFclean_jetCharge_, &b_jets_AK5PFclean_jetCharge_);
  chainB_.SetBranchAddress("jets_AK5PFclean_mass", &jets_AK5PFclean_mass_, &b_jets_AK5PFclean_mass_);
  chainB_.SetBranchAddress("jets_AK5PFclean_mu_Mult", &jets_AK5PFclean_mu_Mult_, &b_jets_AK5PFclean_mu_Mult_);
  chainB_.SetBranchAddress("jets_AK5PFclean_n60", &jets_AK5PFclean_n60_, &b_jets_AK5PFclean_n60_);
  chainB_.SetBranchAddress("jets_AK5PFclean_n90", &jets_AK5PFclean_n90_, &b_jets_AK5PFclean_n90_);
  chainB_.SetBranchAddress("jets_AK5PFclean_n90Hits", &jets_AK5PFclean_n90Hits_, &b_jets_AK5PFclean_n90Hits_);
  chainB_.SetBranchAddress("jets_AK5PFclean_nECALTowers", &jets_AK5PFclean_nECALTowers_, &b_jets_AK5PFclean_nECALTowers_);
  chainB_.SetBranchAddress("jets_AK5PFclean_nHCALTowers", &jets_AK5PFclean_nHCALTowers_, &b_jets_AK5PFclean_nHCALTowers_);
  chainB_.SetBranchAddress("jets_AK5PFclean_neutralEmE", &jets_AK5PFclean_neutralEmE_, &b_jets_AK5PFclean_neutralEmE_);
  chainB_.SetBranchAddress("jets_AK5PFclean_neutralHadE", &jets_AK5PFclean_neutralHadE_, &b_jets_AK5PFclean_neutralHadE_);
  chainB_.SetBranchAddress("jets_AK5PFclean_neutral_Mult", &jets_AK5PFclean_neutral_Mult_, &b_jets_AK5PFclean_neutral_Mult_);
  chainB_.SetBranchAddress("jets_AK5PFclean_partonFlavour", &jets_AK5PFclean_partonFlavour_, &b_jets_AK5PFclean_partonFlavour_);
  chainB_.SetBranchAddress("jets_AK5PFclean_parton_Energy", &jets_AK5PFclean_parton_Energy_, &b_jets_AK5PFclean_parton_Energy_);
  chainB_.SetBranchAddress("jets_AK5PFclean_parton_Id", &jets_AK5PFclean_parton_Id_, &b_jets_AK5PFclean_parton_Id_);
  chainB_.SetBranchAddress("jets_AK5PFclean_parton_eta", &jets_AK5PFclean_parton_eta_, &b_jets_AK5PFclean_parton_eta_);
  chainB_.SetBranchAddress("jets_AK5PFclean_parton_mass", &jets_AK5PFclean_parton_mass_, &b_jets_AK5PFclean_parton_mass_);
  chainB_.SetBranchAddress("jets_AK5PFclean_parton_motherId", &jets_AK5PFclean_parton_motherId_, &b_jets_AK5PFclean_parton_motherId_);
  chainB_.SetBranchAddress("jets_AK5PFclean_parton_phi", &jets_AK5PFclean_parton_phi_, &b_jets_AK5PFclean_parton_phi_);
  chainB_.SetBranchAddress("jets_AK5PFclean_parton_pt", &jets_AK5PFclean_parton_pt_, &b_jets_AK5PFclean_parton_pt_);
  chainB_.SetBranchAddress("jets_AK5PFclean_phi", &jets_AK5PFclean_phi_, &b_jets_AK5PFclean_phi_);
  chainB_.SetBranchAddress("jets_AK5PFclean_phiphiMoment", &jets_AK5PFclean_phiphiMoment_, &b_jets_AK5PFclean_phiphiMoment_);
  chainB_.SetBranchAddress("jets_AK5PFclean_photonEnergy", &jets_AK5PFclean_photonEnergy_, &b_jets_AK5PFclean_photonEnergy_);
  chainB_.SetBranchAddress("jets_AK5PFclean_pt", &jets_AK5PFclean_pt_, &b_jets_AK5PFclean_pt_);
  chainB_.SetBranchAddress("jets_AK5PFclean_px", &jets_AK5PFclean_px_, &b_jets_AK5PFclean_px_);
  chainB_.SetBranchAddress("jets_AK5PFclean_py", &jets_AK5PFclean_py_, &b_jets_AK5PFclean_py_);
  chainB_.SetBranchAddress("jets_AK5PFclean_pz", &jets_AK5PFclean_pz_, &b_jets_AK5PFclean_pz_);
  chainB_.SetBranchAddress("jets_AK5PFclean_rawPt", &jets_AK5PFclean_rawPt_, &b_jets_AK5PFclean_rawPt_);
  chainB_.SetBranchAddress("jets_AK5PFclean_status", &jets_AK5PFclean_status_, &b_jets_AK5PFclean_status_);
  chainB_.SetBranchAddress("jets_AK5PFclean_theta", &jets_AK5PFclean_theta_, &b_jets_AK5PFclean_theta_);
  chainB_.SetBranchAddress("mc_pdf_id1", &mc_pdf_id1_, &b_mc_pdf_id1_);
  chainB_.SetBranchAddress("mc_pdf_id2", &mc_pdf_id2_, &b_mc_pdf_id2_);
  chainB_.SetBranchAddress("mc_pdf_q", &mc_pdf_q_, &b_mc_pdf_q_);
  chainB_.SetBranchAddress("mc_pdf_x1", &mc_pdf_x1_, &b_mc_pdf_x1_);
  chainB_.SetBranchAddress("mc_pdf_x2", &mc_pdf_x2_, &b_mc_pdf_x2_);
  chainB_.SetBranchAddress("metsHO_et", &metsHO_et_, &b_metsHO_et_);
  chainB_.SetBranchAddress("metsHO_ex", &metsHO_ex_, &b_metsHO_ex_);
  chainB_.SetBranchAddress("metsHO_ey", &metsHO_ey_, &b_metsHO_ey_);
  chainB_.SetBranchAddress("metsHO_phi", &metsHO_phi_, &b_metsHO_phi_);
  chainB_.SetBranchAddress("metsHO_sumEt", &metsHO_sumEt_, &b_metsHO_sumEt_);
  chainB_.SetBranchAddress("mets_AK5_et", &mets_AK5_et_, &b_mets_AK5_et_);
  chainB_.SetBranchAddress("mets_AK5_ex", &mets_AK5_ex_, &b_mets_AK5_ex_);
  chainB_.SetBranchAddress("mets_AK5_ey", &mets_AK5_ey_, &b_mets_AK5_ey_);
  chainB_.SetBranchAddress("mets_AK5_gen_et", &mets_AK5_gen_et_, &b_mets_AK5_gen_et_);
  chainB_.SetBranchAddress("mets_AK5_gen_phi", &mets_AK5_gen_phi_, &b_mets_AK5_gen_phi_);
  chainB_.SetBranchAddress("mets_AK5_phi", &mets_AK5_phi_, &b_mets_AK5_phi_);
  chainB_.SetBranchAddress("mets_AK5_sign", &mets_AK5_sign_, &b_mets_AK5_sign_);
  chainB_.SetBranchAddress("mets_AK5_sumEt", &mets_AK5_sumEt_, &b_mets_AK5_sumEt_);
  chainB_.SetBranchAddress("mets_AK5_unCPhi", &mets_AK5_unCPhi_, &b_mets_AK5_unCPhi_);
  chainB_.SetBranchAddress("mets_AK5_unCPt", &mets_AK5_unCPt_, &b_mets_AK5_unCPt_);
  chainB_.SetBranchAddress("pfTypeINoXYCorrmets_et", &pfTypeINoXYCorrmets_et_, &b_pfTypeINoXYCorrmets_et_);
  chainB_.SetBranchAddress("pfTypeINoXYCorrmets_ex", &pfTypeINoXYCorrmets_ex_, &b_pfTypeINoXYCorrmets_ex_);
  chainB_.SetBranchAddress("pfTypeINoXYCorrmets_ey", &pfTypeINoXYCorrmets_ey_, &b_pfTypeINoXYCorrmets_ey_);
  chainB_.SetBranchAddress("pfTypeINoXYCorrmets_gen_et", &pfTypeINoXYCorrmets_gen_et_, &b_pfTypeINoXYCorrmets_gen_et_);
  chainB_.SetBranchAddress("pfTypeINoXYCorrmets_gen_phi", &pfTypeINoXYCorrmets_gen_phi_, &b_pfTypeINoXYCorrmets_gen_phi_);
  chainB_.SetBranchAddress("pfTypeINoXYCorrmets_phi", &pfTypeINoXYCorrmets_phi_, &b_pfTypeINoXYCorrmets_phi_);
  chainB_.SetBranchAddress("pfTypeINoXYCorrmets_sign", &pfTypeINoXYCorrmets_sign_, &b_pfTypeINoXYCorrmets_sign_);
  chainB_.SetBranchAddress("pfTypeINoXYCorrmets_sumEt", &pfTypeINoXYCorrmets_sumEt_, &b_pfTypeINoXYCorrmets_sumEt_);
  chainB_.SetBranchAddress("pfTypeINoXYCorrmets_unCPhi", &pfTypeINoXYCorrmets_unCPhi_, &b_pfTypeINoXYCorrmets_unCPhi_);
  chainB_.SetBranchAddress("pfTypeINoXYCorrmets_unCPt", &pfTypeINoXYCorrmets_unCPt_, &b_pfTypeINoXYCorrmets_unCPt_);
  chainB_.SetBranchAddress("pfTypeIType0mets_et", &pfTypeIType0mets_et_, &b_pfTypeIType0mets_et_);
  chainB_.SetBranchAddress("pfTypeIType0mets_ex", &pfTypeIType0mets_ex_, &b_pfTypeIType0mets_ex_);
  chainB_.SetBranchAddress("pfTypeIType0mets_ey", &pfTypeIType0mets_ey_, &b_pfTypeIType0mets_ey_);
  chainB_.SetBranchAddress("pfTypeIType0mets_gen_et", &pfTypeIType0mets_gen_et_, &b_pfTypeIType0mets_gen_et_);
  chainB_.SetBranchAddress("pfTypeIType0mets_gen_phi", &pfTypeIType0mets_gen_phi_, &b_pfTypeIType0mets_gen_phi_);
  chainB_.SetBranchAddress("pfTypeIType0mets_phi", &pfTypeIType0mets_phi_, &b_pfTypeIType0mets_phi_);
  chainB_.SetBranchAddress("pfTypeIType0mets_sign", &pfTypeIType0mets_sign_, &b_pfTypeIType0mets_sign_);
  chainB_.SetBranchAddress("pfTypeIType0mets_sumEt", &pfTypeIType0mets_sumEt_, &b_pfTypeIType0mets_sumEt_);
  chainB_.SetBranchAddress("pfTypeIType0mets_unCPhi", &pfTypeIType0mets_unCPhi_, &b_pfTypeIType0mets_unCPhi_);
  chainB_.SetBranchAddress("pfTypeIType0mets_unCPt", &pfTypeIType0mets_unCPt_, &b_pfTypeIType0mets_unCPt_);
  chainB_.SetBranchAddress("pfTypeImets_et", &pfTypeImets_et_, &b_pfTypeImets_et_);
  chainB_.SetBranchAddress("pfTypeImets_ex", &pfTypeImets_ex_, &b_pfTypeImets_ex_);
  chainB_.SetBranchAddress("pfTypeImets_ey", &pfTypeImets_ey_, &b_pfTypeImets_ey_);
  chainB_.SetBranchAddress("pfTypeImets_gen_et", &pfTypeImets_gen_et_, &b_pfTypeImets_gen_et_);
  chainB_.SetBranchAddress("pfTypeImets_gen_phi", &pfTypeImets_gen_phi_, &b_pfTypeImets_gen_phi_);
  chainB_.SetBranchAddress("pfTypeImets_phi", &pfTypeImets_phi_, &b_pfTypeImets_phi_);
  chainB_.SetBranchAddress("pfTypeImets_sign", &pfTypeImets_sign_, &b_pfTypeImets_sign_);
  chainB_.SetBranchAddress("pfTypeImets_sumEt", &pfTypeImets_sumEt_, &b_pfTypeImets_sumEt_);
  chainB_.SetBranchAddress("pfTypeImets_unCPhi", &pfTypeImets_unCPhi_, &b_pfTypeImets_unCPhi_);
  chainB_.SetBranchAddress("pfTypeImets_unCPt", &pfTypeImets_unCPt_, &b_pfTypeImets_unCPt_);
  chainB_.SetBranchAddress("pf_els_PATpassConversionVeto", &pf_els_PATpassConversionVeto_, &b_pf_els_PATpassConversionVeto_);
  chainB_.SetBranchAddress("pf_els_basicClustersSize", &pf_els_basicClustersSize_, &b_pf_els_basicClustersSize_);
  chainB_.SetBranchAddress("pf_els_cIso", &pf_els_cIso_, &b_pf_els_cIso_);
  chainB_.SetBranchAddress("pf_els_caloEnergy", &pf_els_caloEnergy_, &b_pf_els_caloEnergy_);
  chainB_.SetBranchAddress("pf_els_charge", &pf_els_charge_, &b_pf_els_charge_);
  chainB_.SetBranchAddress("pf_els_chargedHadronIso", &pf_els_chargedHadronIso_, &b_pf_els_chargedHadronIso_);
  chainB_.SetBranchAddress("pf_els_chi2", &pf_els_chi2_, &b_pf_els_chi2_);
  chainB_.SetBranchAddress("pf_els_core_ecalDrivenSeed", &pf_els_core_ecalDrivenSeed_, &b_pf_els_core_ecalDrivenSeed_);
  chainB_.SetBranchAddress("pf_els_cpx", &pf_els_cpx_, &b_pf_els_cpx_);
  chainB_.SetBranchAddress("pf_els_cpy", &pf_els_cpy_, &b_pf_els_cpy_);
  chainB_.SetBranchAddress("pf_els_cpz", &pf_els_cpz_, &b_pf_els_cpz_);
  chainB_.SetBranchAddress("pf_els_ctf_tk_charge", &pf_els_ctf_tk_charge_, &b_pf_els_ctf_tk_charge_);
  chainB_.SetBranchAddress("pf_els_ctf_tk_eta", &pf_els_ctf_tk_eta_, &b_pf_els_ctf_tk_eta_);
  chainB_.SetBranchAddress("pf_els_ctf_tk_id", &pf_els_ctf_tk_id_, &b_pf_els_ctf_tk_id_);
  chainB_.SetBranchAddress("pf_els_ctf_tk_phi", &pf_els_ctf_tk_phi_, &b_pf_els_ctf_tk_phi_);
  chainB_.SetBranchAddress("pf_els_cx", &pf_els_cx_, &b_pf_els_cx_);
  chainB_.SetBranchAddress("pf_els_cy", &pf_els_cy_, &b_pf_els_cy_);
  chainB_.SetBranchAddress("pf_els_cz", &pf_els_cz_, &b_pf_els_cz_);
  chainB_.SetBranchAddress("pf_els_d0dum", &pf_els_d0dum_, &b_pf_els_d0dum_);
  chainB_.SetBranchAddress("pf_els_d0dumError", &pf_els_d0dumError_, &b_pf_els_d0dumError_);
  chainB_.SetBranchAddress("pf_els_dEtaIn", &pf_els_dEtaIn_, &b_pf_els_dEtaIn_);
  chainB_.SetBranchAddress("pf_els_dEtaOut", &pf_els_dEtaOut_, &b_pf_els_dEtaOut_);
  chainB_.SetBranchAddress("pf_els_dPhiIn", &pf_els_dPhiIn_, &b_pf_els_dPhiIn_);
  chainB_.SetBranchAddress("pf_els_dPhiOut", &pf_els_dPhiOut_, &b_pf_els_dPhiOut_);
  chainB_.SetBranchAddress("pf_els_dr03EcalRecHitSumEt", &pf_els_dr03EcalRecHitSumEt_, &b_pf_els_dr03EcalRecHitSumEt_);
  chainB_.SetBranchAddress("pf_els_dr03HcalDepth1TowerSumEt", &pf_els_dr03HcalDepth1TowerSumEt_, &b_pf_els_dr03HcalDepth1TowerSumEt_);
  chainB_.SetBranchAddress("pf_els_dr03HcalDepth2TowerSumEt", &pf_els_dr03HcalDepth2TowerSumEt_, &b_pf_els_dr03HcalDepth2TowerSumEt_);
  chainB_.SetBranchAddress("pf_els_dr03HcalTowerSumEt", &pf_els_dr03HcalTowerSumEt_, &b_pf_els_dr03HcalTowerSumEt_);
  chainB_.SetBranchAddress("pf_els_dr03TkSumPt", &pf_els_dr03TkSumPt_, &b_pf_els_dr03TkSumPt_);
  chainB_.SetBranchAddress("pf_els_dr04EcalRecHitSumEt", &pf_els_dr04EcalRecHitSumEt_, &b_pf_els_dr04EcalRecHitSumEt_);
  chainB_.SetBranchAddress("pf_els_dr04HcalDepth1TowerSumEt", &pf_els_dr04HcalDepth1TowerSumEt_, &b_pf_els_dr04HcalDepth1TowerSumEt_);
  chainB_.SetBranchAddress("pf_els_dr04HcalDepth2TowerSumEt", &pf_els_dr04HcalDepth2TowerSumEt_, &b_pf_els_dr04HcalDepth2TowerSumEt_);
  chainB_.SetBranchAddress("pf_els_dr04HcalTowerSumEt", &pf_els_dr04HcalTowerSumEt_, &b_pf_els_dr04HcalTowerSumEt_);
  chainB_.SetBranchAddress("pf_els_dr04TkSumPt", &pf_els_dr04TkSumPt_, &b_pf_els_dr04TkSumPt_);
  chainB_.SetBranchAddress("pf_els_dz", &pf_els_dz_, &b_pf_els_dz_);
  chainB_.SetBranchAddress("pf_els_dzError", &pf_els_dzError_, &b_pf_els_dzError_);
  chainB_.SetBranchAddress("pf_els_eOverPIn", &pf_els_eOverPIn_, &b_pf_els_eOverPIn_);
  chainB_.SetBranchAddress("pf_els_eSeedOverPOut", &pf_els_eSeedOverPOut_, &b_pf_els_eSeedOverPOut_);
  chainB_.SetBranchAddress("pf_els_ecalIso", &pf_els_ecalIso_, &b_pf_els_ecalIso_);
  chainB_.SetBranchAddress("pf_els_energy", &pf_els_energy_, &b_pf_els_energy_);
  chainB_.SetBranchAddress("pf_els_et", &pf_els_et_, &b_pf_els_et_);
  chainB_.SetBranchAddress("pf_els_eta", &pf_els_eta_, &b_pf_els_eta_);
  chainB_.SetBranchAddress("pf_els_etaError", &pf_els_etaError_, &b_pf_els_etaError_);
  chainB_.SetBranchAddress("pf_els_fbrem", &pf_els_fbrem_, &b_pf_els_fbrem_);
  chainB_.SetBranchAddress("pf_els_gen_et", &pf_els_gen_et_, &b_pf_els_gen_et_);
  chainB_.SetBranchAddress("pf_els_gen_eta", &pf_els_gen_eta_, &b_pf_els_gen_eta_);
  chainB_.SetBranchAddress("pf_els_gen_id", &pf_els_gen_id_, &b_pf_els_gen_id_);
  chainB_.SetBranchAddress("pf_els_gen_mother_et", &pf_els_gen_mother_et_, &b_pf_els_gen_mother_et_);
  chainB_.SetBranchAddress("pf_els_gen_mother_eta", &pf_els_gen_mother_eta_, &b_pf_els_gen_mother_eta_);
  chainB_.SetBranchAddress("pf_els_gen_mother_id", &pf_els_gen_mother_id_, &b_pf_els_gen_mother_id_);
  chainB_.SetBranchAddress("pf_els_gen_mother_phi", &pf_els_gen_mother_phi_, &b_pf_els_gen_mother_phi_);
  chainB_.SetBranchAddress("pf_els_gen_mother_pt", &pf_els_gen_mother_pt_, &b_pf_els_gen_mother_pt_);
  chainB_.SetBranchAddress("pf_els_gen_mother_px", &pf_els_gen_mother_px_, &b_pf_els_gen_mother_px_);
  chainB_.SetBranchAddress("pf_els_gen_mother_py", &pf_els_gen_mother_py_, &b_pf_els_gen_mother_py_);
  chainB_.SetBranchAddress("pf_els_gen_mother_pz", &pf_els_gen_mother_pz_, &b_pf_els_gen_mother_pz_);
  chainB_.SetBranchAddress("pf_els_gen_mother_theta", &pf_els_gen_mother_theta_, &b_pf_els_gen_mother_theta_);
  chainB_.SetBranchAddress("pf_els_gen_phi", &pf_els_gen_phi_, &b_pf_els_gen_phi_);
  chainB_.SetBranchAddress("pf_els_gen_pt", &pf_els_gen_pt_, &b_pf_els_gen_pt_);
  chainB_.SetBranchAddress("pf_els_gen_px", &pf_els_gen_px_, &b_pf_els_gen_px_);
  chainB_.SetBranchAddress("pf_els_gen_py", &pf_els_gen_py_, &b_pf_els_gen_py_);
  chainB_.SetBranchAddress("pf_els_gen_pz", &pf_els_gen_pz_, &b_pf_els_gen_pz_);
  chainB_.SetBranchAddress("pf_els_gen_theta", &pf_els_gen_theta_, &b_pf_els_gen_theta_);
  chainB_.SetBranchAddress("pf_els_hadOverEm", &pf_els_hadOverEm_, &b_pf_els_hadOverEm_);
  chainB_.SetBranchAddress("pf_els_hcalIso", &pf_els_hcalIso_, &b_pf_els_hcalIso_);
  chainB_.SetBranchAddress("pf_els_hcalOverEcalBc", &pf_els_hcalOverEcalBc_, &b_pf_els_hcalOverEcalBc_);
  chainB_.SetBranchAddress("pf_els_isEB", &pf_els_isEB_, &b_pf_els_isEB_);
  chainB_.SetBranchAddress("pf_els_isEE", &pf_els_isEE_, &b_pf_els_isEE_);
  chainB_.SetBranchAddress("pf_els_looseId", &pf_els_looseId_, &b_pf_els_looseId_);
  chainB_.SetBranchAddress("pf_els_n_inner_layer", &pf_els_n_inner_layer_, &b_pf_els_n_inner_layer_);
  chainB_.SetBranchAddress("pf_els_n_outer_layer", &pf_els_n_outer_layer_, &b_pf_els_n_outer_layer_);
  chainB_.SetBranchAddress("pf_els_ndof", &pf_els_ndof_, &b_pf_els_ndof_);
  chainB_.SetBranchAddress("pf_els_neutralHadronIso", &pf_els_neutralHadronIso_, &b_pf_els_neutralHadronIso_);
  chainB_.SetBranchAddress("pf_els_numlosthits", &pf_els_numlosthits_, &b_pf_els_numlosthits_);
  chainB_.SetBranchAddress("pf_els_numvalhits", &pf_els_numvalhits_, &b_pf_els_numvalhits_);
  chainB_.SetBranchAddress("pf_els_phi", &pf_els_phi_, &b_pf_els_phi_);
  chainB_.SetBranchAddress("pf_els_phiError", &pf_els_phiError_, &b_pf_els_phiError_);
  chainB_.SetBranchAddress("pf_els_photonIso", &pf_els_photonIso_, &b_pf_els_photonIso_);
  chainB_.SetBranchAddress("pf_els_pt", &pf_els_pt_, &b_pf_els_pt_);
  chainB_.SetBranchAddress("pf_els_ptError", &pf_els_ptError_, &b_pf_els_ptError_);
  chainB_.SetBranchAddress("pf_els_px", &pf_els_px_, &b_pf_els_px_);
  chainB_.SetBranchAddress("pf_els_py", &pf_els_py_, &b_pf_els_py_);
  chainB_.SetBranchAddress("pf_els_pz", &pf_els_pz_, &b_pf_els_pz_);
  chainB_.SetBranchAddress("pf_els_robustHighEnergyId", &pf_els_robustHighEnergyId_, &b_pf_els_robustHighEnergyId_);
  chainB_.SetBranchAddress("pf_els_robustLooseId", &pf_els_robustLooseId_, &b_pf_els_robustLooseId_);
  chainB_.SetBranchAddress("pf_els_robustTightId", &pf_els_robustTightId_, &b_pf_els_robustTightId_);
  chainB_.SetBranchAddress("pf_els_scE1x5", &pf_els_scE1x5_, &b_pf_els_scE1x5_);
  chainB_.SetBranchAddress("pf_els_scE2x5Max", &pf_els_scE2x5Max_, &b_pf_els_scE2x5Max_);
  chainB_.SetBranchAddress("pf_els_scE5x5", &pf_els_scE5x5_, &b_pf_els_scE5x5_);
  chainB_.SetBranchAddress("pf_els_scEnergy", &pf_els_scEnergy_, &b_pf_els_scEnergy_);
  chainB_.SetBranchAddress("pf_els_scEta", &pf_els_scEta_, &b_pf_els_scEta_);
  chainB_.SetBranchAddress("pf_els_scEtaWidth", &pf_els_scEtaWidth_, &b_pf_els_scEtaWidth_);
  chainB_.SetBranchAddress("pf_els_scPhi", &pf_els_scPhi_, &b_pf_els_scPhi_);
  chainB_.SetBranchAddress("pf_els_scPhiWidth", &pf_els_scPhiWidth_, &b_pf_els_scPhiWidth_);
  chainB_.SetBranchAddress("pf_els_scRawEnergy", &pf_els_scRawEnergy_, &b_pf_els_scRawEnergy_);
  chainB_.SetBranchAddress("pf_els_scSeedEnergy", &pf_els_scSeedEnergy_, &b_pf_els_scSeedEnergy_);
  chainB_.SetBranchAddress("pf_els_shFracInnerHits", &pf_els_shFracInnerHits_, &b_pf_els_shFracInnerHits_);
  chainB_.SetBranchAddress("pf_els_sigmaEtaEta", &pf_els_sigmaEtaEta_, &b_pf_els_sigmaEtaEta_);
  chainB_.SetBranchAddress("pf_els_sigmaIEtaIEta", &pf_els_sigmaIEtaIEta_, &b_pf_els_sigmaIEtaIEta_);
  chainB_.SetBranchAddress("pf_els_simpleEleId60cIso", &pf_els_simpleEleId60cIso_, &b_pf_els_simpleEleId60cIso_);
  chainB_.SetBranchAddress("pf_els_simpleEleId60relIso", &pf_els_simpleEleId60relIso_, &b_pf_els_simpleEleId60relIso_);
  chainB_.SetBranchAddress("pf_els_simpleEleId70cIso", &pf_els_simpleEleId70cIso_, &b_pf_els_simpleEleId70cIso_);
  chainB_.SetBranchAddress("pf_els_simpleEleId70relIso", &pf_els_simpleEleId70relIso_, &b_pf_els_simpleEleId70relIso_);
  chainB_.SetBranchAddress("pf_els_simpleEleId80cIso", &pf_els_simpleEleId80cIso_, &b_pf_els_simpleEleId80cIso_);
  chainB_.SetBranchAddress("pf_els_simpleEleId80relIso", &pf_els_simpleEleId80relIso_, &b_pf_els_simpleEleId80relIso_);
  chainB_.SetBranchAddress("pf_els_simpleEleId85cIso", &pf_els_simpleEleId85cIso_, &b_pf_els_simpleEleId85cIso_);
  chainB_.SetBranchAddress("pf_els_simpleEleId85relIso", &pf_els_simpleEleId85relIso_, &b_pf_els_simpleEleId85relIso_);
  chainB_.SetBranchAddress("pf_els_simpleEleId90cIso", &pf_els_simpleEleId90cIso_, &b_pf_els_simpleEleId90cIso_);
  chainB_.SetBranchAddress("pf_els_simpleEleId90relIso", &pf_els_simpleEleId90relIso_, &b_pf_els_simpleEleId90relIso_);
  chainB_.SetBranchAddress("pf_els_simpleEleId95cIso", &pf_els_simpleEleId95cIso_, &b_pf_els_simpleEleId95cIso_);
  chainB_.SetBranchAddress("pf_els_simpleEleId95relIso", &pf_els_simpleEleId95relIso_, &b_pf_els_simpleEleId95relIso_);
  chainB_.SetBranchAddress("pf_els_status", &pf_els_status_, &b_pf_els_status_);
  chainB_.SetBranchAddress("pf_els_tIso", &pf_els_tIso_, &b_pf_els_tIso_);
  chainB_.SetBranchAddress("pf_els_theta", &pf_els_theta_, &b_pf_els_theta_);
  chainB_.SetBranchAddress("pf_els_tightId", &pf_els_tightId_, &b_pf_els_tightId_);
  chainB_.SetBranchAddress("pf_els_tk_charge", &pf_els_tk_charge_, &b_pf_els_tk_charge_);
  chainB_.SetBranchAddress("pf_els_tk_eta", &pf_els_tk_eta_, &b_pf_els_tk_eta_);
  chainB_.SetBranchAddress("pf_els_tk_phi", &pf_els_tk_phi_, &b_pf_els_tk_phi_);
  chainB_.SetBranchAddress("pf_els_tk_pt", &pf_els_tk_pt_, &b_pf_els_tk_pt_);
  chainB_.SetBranchAddress("pf_els_tk_pz", &pf_els_tk_pz_, &b_pf_els_tk_pz_);
  chainB_.SetBranchAddress("pf_els_vpx", &pf_els_vpx_, &b_pf_els_vpx_);
  chainB_.SetBranchAddress("pf_els_vpy", &pf_els_vpy_, &b_pf_els_vpy_);
  chainB_.SetBranchAddress("pf_els_vpz", &pf_els_vpz_, &b_pf_els_vpz_);
  chainB_.SetBranchAddress("pf_els_vx", &pf_els_vx_, &b_pf_els_vx_);
  chainB_.SetBranchAddress("pf_els_vy", &pf_els_vy_, &b_pf_els_vy_);
  chainB_.SetBranchAddress("pf_els_vz", &pf_els_vz_, &b_pf_els_vz_);
  chainB_.SetBranchAddress("pf_mus_cIso", &pf_mus_cIso_, &b_pf_mus_cIso_);
  chainB_.SetBranchAddress("pf_mus_calEnergyEm", &pf_mus_calEnergyEm_, &b_pf_mus_calEnergyEm_);
  chainB_.SetBranchAddress("pf_mus_calEnergyEmS9", &pf_mus_calEnergyEmS9_, &b_pf_mus_calEnergyEmS9_);
  chainB_.SetBranchAddress("pf_mus_calEnergyHad", &pf_mus_calEnergyHad_, &b_pf_mus_calEnergyHad_);
  chainB_.SetBranchAddress("pf_mus_calEnergyHadS9", &pf_mus_calEnergyHadS9_, &b_pf_mus_calEnergyHadS9_);
  chainB_.SetBranchAddress("pf_mus_calEnergyHo", &pf_mus_calEnergyHo_, &b_pf_mus_calEnergyHo_);
  chainB_.SetBranchAddress("pf_mus_calEnergyHoS9", &pf_mus_calEnergyHoS9_, &b_pf_mus_calEnergyHoS9_);
  chainB_.SetBranchAddress("pf_mus_charge", &pf_mus_charge_, &b_pf_mus_charge_);
  chainB_.SetBranchAddress("pf_mus_chargedHadronIso", &pf_mus_chargedHadronIso_, &b_pf_mus_chargedHadronIso_);
  chainB_.SetBranchAddress("pf_mus_cm_ExpectedHitsInner", &pf_mus_cm_ExpectedHitsInner_, &b_pf_mus_cm_ExpectedHitsInner_);
  chainB_.SetBranchAddress("pf_mus_cm_ExpectedHitsOuter", &pf_mus_cm_ExpectedHitsOuter_, &b_pf_mus_cm_ExpectedHitsOuter_);
  chainB_.SetBranchAddress("pf_mus_cm_LayersWithMeasurement", &pf_mus_cm_LayersWithMeasurement_, &b_pf_mus_cm_LayersWithMeasurement_);
  chainB_.SetBranchAddress("pf_mus_cm_LayersWithoutMeasurement", &pf_mus_cm_LayersWithoutMeasurement_, &b_pf_mus_cm_LayersWithoutMeasurement_);
  chainB_.SetBranchAddress("pf_mus_cm_PixelLayersWithMeasurement", &pf_mus_cm_PixelLayersWithMeasurement_, &b_pf_mus_cm_PixelLayersWithMeasurement_);
  chainB_.SetBranchAddress("pf_mus_cm_ValidStripLayersWithMonoAndStereoHit", &pf_mus_cm_ValidStripLayersWithMonoAndStereoHit_, &b_pf_mus_cm_ValidStripLayersWithMonoAndStereoHit_);
  chainB_.SetBranchAddress("pf_mus_cm_chg", &pf_mus_cm_chg_, &b_pf_mus_cm_chg_);
  chainB_.SetBranchAddress("pf_mus_cm_chi2", &pf_mus_cm_chi2_, &b_pf_mus_cm_chi2_);
  chainB_.SetBranchAddress("pf_mus_cm_d0dum", &pf_mus_cm_d0dum_, &b_pf_mus_cm_d0dum_);
  chainB_.SetBranchAddress("pf_mus_cm_d0dumErr", &pf_mus_cm_d0dumErr_, &b_pf_mus_cm_d0dumErr_);
  chainB_.SetBranchAddress("pf_mus_cm_dz", &pf_mus_cm_dz_, &b_pf_mus_cm_dz_);
  chainB_.SetBranchAddress("pf_mus_cm_dzErr", &pf_mus_cm_dzErr_, &b_pf_mus_cm_dzErr_);
  chainB_.SetBranchAddress("pf_mus_cm_eta", &pf_mus_cm_eta_, &b_pf_mus_cm_eta_);
  chainB_.SetBranchAddress("pf_mus_cm_etaErr", &pf_mus_cm_etaErr_, &b_pf_mus_cm_etaErr_);
  chainB_.SetBranchAddress("pf_mus_cm_ndof", &pf_mus_cm_ndof_, &b_pf_mus_cm_ndof_);
  chainB_.SetBranchAddress("pf_mus_cm_numlosthits", &pf_mus_cm_numlosthits_, &b_pf_mus_cm_numlosthits_);
  chainB_.SetBranchAddress("pf_mus_cm_numvalMuonhits", &pf_mus_cm_numvalMuonhits_, &b_pf_mus_cm_numvalMuonhits_);
  chainB_.SetBranchAddress("pf_mus_cm_numvalhits", &pf_mus_cm_numvalhits_, &b_pf_mus_cm_numvalhits_);
  chainB_.SetBranchAddress("pf_mus_cm_phi", &pf_mus_cm_phi_, &b_pf_mus_cm_phi_);
  chainB_.SetBranchAddress("pf_mus_cm_phiErr", &pf_mus_cm_phiErr_, &b_pf_mus_cm_phiErr_);
  chainB_.SetBranchAddress("pf_mus_cm_pt", &pf_mus_cm_pt_, &b_pf_mus_cm_pt_);
  chainB_.SetBranchAddress("pf_mus_cm_ptErr", &pf_mus_cm_ptErr_, &b_pf_mus_cm_ptErr_);
  chainB_.SetBranchAddress("pf_mus_cm_px", &pf_mus_cm_px_, &b_pf_mus_cm_px_);
  chainB_.SetBranchAddress("pf_mus_cm_py", &pf_mus_cm_py_, &b_pf_mus_cm_py_);
  chainB_.SetBranchAddress("pf_mus_cm_pz", &pf_mus_cm_pz_, &b_pf_mus_cm_pz_);
  chainB_.SetBranchAddress("pf_mus_cm_theta", &pf_mus_cm_theta_, &b_pf_mus_cm_theta_);
  chainB_.SetBranchAddress("pf_mus_cm_vx", &pf_mus_cm_vx_, &b_pf_mus_cm_vx_);
  chainB_.SetBranchAddress("pf_mus_cm_vy", &pf_mus_cm_vy_, &b_pf_mus_cm_vy_);
  chainB_.SetBranchAddress("pf_mus_cm_vz", &pf_mus_cm_vz_, &b_pf_mus_cm_vz_);
  chainB_.SetBranchAddress("pf_mus_dB", &pf_mus_dB_, &b_pf_mus_dB_);
  chainB_.SetBranchAddress("pf_mus_ecalIso", &pf_mus_ecalIso_, &b_pf_mus_ecalIso_);
  chainB_.SetBranchAddress("pf_mus_energy", &pf_mus_energy_, &b_pf_mus_energy_);
  chainB_.SetBranchAddress("pf_mus_et", &pf_mus_et_, &b_pf_mus_et_);
  chainB_.SetBranchAddress("pf_mus_eta", &pf_mus_eta_, &b_pf_mus_eta_);
  chainB_.SetBranchAddress("pf_mus_gen_et", &pf_mus_gen_et_, &b_pf_mus_gen_et_);
  chainB_.SetBranchAddress("pf_mus_gen_eta", &pf_mus_gen_eta_, &b_pf_mus_gen_eta_);
  chainB_.SetBranchAddress("pf_mus_gen_id", &pf_mus_gen_id_, &b_pf_mus_gen_id_);
  chainB_.SetBranchAddress("pf_mus_gen_mother_et", &pf_mus_gen_mother_et_, &b_pf_mus_gen_mother_et_);
  chainB_.SetBranchAddress("pf_mus_gen_mother_eta", &pf_mus_gen_mother_eta_, &b_pf_mus_gen_mother_eta_);
  chainB_.SetBranchAddress("pf_mus_gen_mother_id", &pf_mus_gen_mother_id_, &b_pf_mus_gen_mother_id_);
  chainB_.SetBranchAddress("pf_mus_gen_mother_phi", &pf_mus_gen_mother_phi_, &b_pf_mus_gen_mother_phi_);
  chainB_.SetBranchAddress("pf_mus_gen_mother_pt", &pf_mus_gen_mother_pt_, &b_pf_mus_gen_mother_pt_);
  chainB_.SetBranchAddress("pf_mus_gen_mother_px", &pf_mus_gen_mother_px_, &b_pf_mus_gen_mother_px_);
  chainB_.SetBranchAddress("pf_mus_gen_mother_py", &pf_mus_gen_mother_py_, &b_pf_mus_gen_mother_py_);
  chainB_.SetBranchAddress("pf_mus_gen_mother_pz", &pf_mus_gen_mother_pz_, &b_pf_mus_gen_mother_pz_);
  chainB_.SetBranchAddress("pf_mus_gen_mother_theta", &pf_mus_gen_mother_theta_, &b_pf_mus_gen_mother_theta_);
  chainB_.SetBranchAddress("pf_mus_gen_phi", &pf_mus_gen_phi_, &b_pf_mus_gen_phi_);
  chainB_.SetBranchAddress("pf_mus_gen_pt", &pf_mus_gen_pt_, &b_pf_mus_gen_pt_);
  chainB_.SetBranchAddress("pf_mus_gen_px", &pf_mus_gen_px_, &b_pf_mus_gen_px_);
  chainB_.SetBranchAddress("pf_mus_gen_py", &pf_mus_gen_py_, &b_pf_mus_gen_py_);
  chainB_.SetBranchAddress("pf_mus_gen_pz", &pf_mus_gen_pz_, &b_pf_mus_gen_pz_);
  chainB_.SetBranchAddress("pf_mus_gen_theta", &pf_mus_gen_theta_, &b_pf_mus_gen_theta_);
  chainB_.SetBranchAddress("pf_mus_hcalIso", &pf_mus_hcalIso_, &b_pf_mus_hcalIso_);
  chainB_.SetBranchAddress("pf_mus_id_All", &pf_mus_id_All_, &b_pf_mus_id_All_);
  chainB_.SetBranchAddress("pf_mus_id_AllArbitrated", &pf_mus_id_AllArbitrated_, &b_pf_mus_id_AllArbitrated_);
  chainB_.SetBranchAddress("pf_mus_id_AllGlobalMuons", &pf_mus_id_AllGlobalMuons_, &b_pf_mus_id_AllGlobalMuons_);
  chainB_.SetBranchAddress("pf_mus_id_AllStandAloneMuons", &pf_mus_id_AllStandAloneMuons_, &b_pf_mus_id_AllStandAloneMuons_);
  chainB_.SetBranchAddress("pf_mus_id_AllTrackerMuons", &pf_mus_id_AllTrackerMuons_, &b_pf_mus_id_AllTrackerMuons_);
  chainB_.SetBranchAddress("pf_mus_id_GlobalMuonPromptTight", &pf_mus_id_GlobalMuonPromptTight_, &b_pf_mus_id_GlobalMuonPromptTight_);
  chainB_.SetBranchAddress("pf_mus_id_TM2DCompatibilityLoose", &pf_mus_id_TM2DCompatibilityLoose_, &b_pf_mus_id_TM2DCompatibilityLoose_);
  chainB_.SetBranchAddress("pf_mus_id_TM2DCompatibilityTight", &pf_mus_id_TM2DCompatibilityTight_, &b_pf_mus_id_TM2DCompatibilityTight_);
  chainB_.SetBranchAddress("pf_mus_id_TMLastStationLoose", &pf_mus_id_TMLastStationLoose_, &b_pf_mus_id_TMLastStationLoose_);
  chainB_.SetBranchAddress("pf_mus_id_TMLastStationOptimizedLowPtLoose", &pf_mus_id_TMLastStationOptimizedLowPtLoose_, &b_pf_mus_id_TMLastStationOptimizedLowPtLoose_);
  chainB_.SetBranchAddress("pf_mus_id_TMLastStationOptimizedLowPtTight", &pf_mus_id_TMLastStationOptimizedLowPtTight_, &b_pf_mus_id_TMLastStationOptimizedLowPtTight_);
  chainB_.SetBranchAddress("pf_mus_id_TMLastStationTight", &pf_mus_id_TMLastStationTight_, &b_pf_mus_id_TMLastStationTight_);
  chainB_.SetBranchAddress("pf_mus_id_TMOneStationLoose", &pf_mus_id_TMOneStationLoose_, &b_pf_mus_id_TMOneStationLoose_);
  chainB_.SetBranchAddress("pf_mus_id_TMOneStationTight", &pf_mus_id_TMOneStationTight_, &b_pf_mus_id_TMOneStationTight_);
  chainB_.SetBranchAddress("pf_mus_id_TrackerMuonArbitrated", &pf_mus_id_TrackerMuonArbitrated_, &b_pf_mus_id_TrackerMuonArbitrated_);
  chainB_.SetBranchAddress("pf_mus_isCaloMuon", &pf_mus_isCaloMuon_, &b_pf_mus_isCaloMuon_);
  chainB_.SetBranchAddress("pf_mus_isConvertedPhoton", &pf_mus_isConvertedPhoton_, &b_pf_mus_isConvertedPhoton_);
  chainB_.SetBranchAddress("pf_mus_isElectron", &pf_mus_isElectron_, &b_pf_mus_isElectron_);
  chainB_.SetBranchAddress("pf_mus_isGlobalMuon", &pf_mus_isGlobalMuon_, &b_pf_mus_isGlobalMuon_);
  chainB_.SetBranchAddress("pf_mus_isPFMuon", &pf_mus_isPFMuon_, &b_pf_mus_isPFMuon_);
  chainB_.SetBranchAddress("pf_mus_isPhoton", &pf_mus_isPhoton_, &b_pf_mus_isPhoton_);
  chainB_.SetBranchAddress("pf_mus_isStandAloneMuon", &pf_mus_isStandAloneMuon_, &b_pf_mus_isStandAloneMuon_);
  chainB_.SetBranchAddress("pf_mus_isTrackerMuon", &pf_mus_isTrackerMuon_, &b_pf_mus_isTrackerMuon_);
  chainB_.SetBranchAddress("pf_mus_iso03_emEt", &pf_mus_iso03_emEt_, &b_pf_mus_iso03_emEt_);
  chainB_.SetBranchAddress("pf_mus_iso03_emVetoEt", &pf_mus_iso03_emVetoEt_, &b_pf_mus_iso03_emVetoEt_);
  chainB_.SetBranchAddress("pf_mus_iso03_hadEt", &pf_mus_iso03_hadEt_, &b_pf_mus_iso03_hadEt_);
  chainB_.SetBranchAddress("pf_mus_iso03_hadVetoEt", &pf_mus_iso03_hadVetoEt_, &b_pf_mus_iso03_hadVetoEt_);
  chainB_.SetBranchAddress("pf_mus_iso03_hoEt", &pf_mus_iso03_hoEt_, &b_pf_mus_iso03_hoEt_);
  chainB_.SetBranchAddress("pf_mus_iso03_nTracks", &pf_mus_iso03_nTracks_, &b_pf_mus_iso03_nTracks_);
  chainB_.SetBranchAddress("pf_mus_iso03_sumPt", &pf_mus_iso03_sumPt_, &b_pf_mus_iso03_sumPt_);
  chainB_.SetBranchAddress("pf_mus_iso05_emEt", &pf_mus_iso05_emEt_, &b_pf_mus_iso05_emEt_);
  chainB_.SetBranchAddress("pf_mus_iso05_hadEt", &pf_mus_iso05_hadEt_, &b_pf_mus_iso05_hadEt_);
  chainB_.SetBranchAddress("pf_mus_iso05_hoEt", &pf_mus_iso05_hoEt_, &b_pf_mus_iso05_hoEt_);
  chainB_.SetBranchAddress("pf_mus_iso05_nTracks", &pf_mus_iso05_nTracks_, &b_pf_mus_iso05_nTracks_);
  chainB_.SetBranchAddress("pf_mus_iso05_sumPt", &pf_mus_iso05_sumPt_, &b_pf_mus_iso05_sumPt_);
  chainB_.SetBranchAddress("pf_mus_neutralHadronIso", &pf_mus_neutralHadronIso_, &b_pf_mus_neutralHadronIso_);
  chainB_.SetBranchAddress("pf_mus_num_matches", &pf_mus_num_matches_, &b_pf_mus_num_matches_);
  chainB_.SetBranchAddress("pf_mus_numberOfMatchedStations", &pf_mus_numberOfMatchedStations_, &b_pf_mus_numberOfMatchedStations_);
  chainB_.SetBranchAddress("pf_mus_pfIsolationR03_sumChargedHadronPt", &pf_mus_pfIsolationR03_sumChargedHadronPt_, &b_pf_mus_pfIsolationR03_sumChargedHadronPt_);
  chainB_.SetBranchAddress("pf_mus_pfIsolationR03_sumChargedParticlePt", &pf_mus_pfIsolationR03_sumChargedParticlePt_, &b_pf_mus_pfIsolationR03_sumChargedParticlePt_);
  chainB_.SetBranchAddress("pf_mus_pfIsolationR03_sumNeutralHadronEt", &pf_mus_pfIsolationR03_sumNeutralHadronEt_, &b_pf_mus_pfIsolationR03_sumNeutralHadronEt_);
  chainB_.SetBranchAddress("pf_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold", &pf_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_, &b_pf_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_);
  chainB_.SetBranchAddress("pf_mus_pfIsolationR03_sumPUPt", &pf_mus_pfIsolationR03_sumPUPt_, &b_pf_mus_pfIsolationR03_sumPUPt_);
  chainB_.SetBranchAddress("pf_mus_pfIsolationR03_sumPhotonEt", &pf_mus_pfIsolationR03_sumPhotonEt_, &b_pf_mus_pfIsolationR03_sumPhotonEt_);
  chainB_.SetBranchAddress("pf_mus_pfIsolationR03_sumPhotonEtHighThreshold", &pf_mus_pfIsolationR03_sumPhotonEtHighThreshold_, &b_pf_mus_pfIsolationR03_sumPhotonEtHighThreshold_);
  chainB_.SetBranchAddress("pf_mus_pfIsolationR04_sumChargedHadronPt", &pf_mus_pfIsolationR04_sumChargedHadronPt_, &b_pf_mus_pfIsolationR04_sumChargedHadronPt_);
  chainB_.SetBranchAddress("pf_mus_pfIsolationR04_sumChargedParticlePt", &pf_mus_pfIsolationR04_sumChargedParticlePt_, &b_pf_mus_pfIsolationR04_sumChargedParticlePt_);
  chainB_.SetBranchAddress("pf_mus_pfIsolationR04_sumNeutralHadronEt", &pf_mus_pfIsolationR04_sumNeutralHadronEt_, &b_pf_mus_pfIsolationR04_sumNeutralHadronEt_);
  chainB_.SetBranchAddress("pf_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold", &pf_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_, &b_pf_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_);
  chainB_.SetBranchAddress("pf_mus_pfIsolationR04_sumPUPt", &pf_mus_pfIsolationR04_sumPUPt_, &b_pf_mus_pfIsolationR04_sumPUPt_);
  chainB_.SetBranchAddress("pf_mus_pfIsolationR04_sumPhotonEt", &pf_mus_pfIsolationR04_sumPhotonEt_, &b_pf_mus_pfIsolationR04_sumPhotonEt_);
  chainB_.SetBranchAddress("pf_mus_pfIsolationR04_sumPhotonEtHighThreshold", &pf_mus_pfIsolationR04_sumPhotonEtHighThreshold_, &b_pf_mus_pfIsolationR04_sumPhotonEtHighThreshold_);
  chainB_.SetBranchAddress("pf_mus_phi", &pf_mus_phi_, &b_pf_mus_phi_);
  chainB_.SetBranchAddress("pf_mus_photonIso", &pf_mus_photonIso_, &b_pf_mus_photonIso_);
  chainB_.SetBranchAddress("pf_mus_picky_ExpectedHitsInner", &pf_mus_picky_ExpectedHitsInner_, &b_pf_mus_picky_ExpectedHitsInner_);
  chainB_.SetBranchAddress("pf_mus_picky_ExpectedHitsOuter", &pf_mus_picky_ExpectedHitsOuter_, &b_pf_mus_picky_ExpectedHitsOuter_);
  chainB_.SetBranchAddress("pf_mus_picky_LayersWithMeasurement", &pf_mus_picky_LayersWithMeasurement_, &b_pf_mus_picky_LayersWithMeasurement_);
  chainB_.SetBranchAddress("pf_mus_picky_LayersWithoutMeasurement", &pf_mus_picky_LayersWithoutMeasurement_, &b_pf_mus_picky_LayersWithoutMeasurement_);
  chainB_.SetBranchAddress("pf_mus_picky_PixelLayersWithMeasurement", &pf_mus_picky_PixelLayersWithMeasurement_, &b_pf_mus_picky_PixelLayersWithMeasurement_);
  chainB_.SetBranchAddress("pf_mus_picky_ValidStripLayersWithMonoAndStereoHit", &pf_mus_picky_ValidStripLayersWithMonoAndStereoHit_, &b_pf_mus_picky_ValidStripLayersWithMonoAndStereoHit_);
  chainB_.SetBranchAddress("pf_mus_picky_chg", &pf_mus_picky_chg_, &b_pf_mus_picky_chg_);
  chainB_.SetBranchAddress("pf_mus_picky_chi2", &pf_mus_picky_chi2_, &b_pf_mus_picky_chi2_);
  chainB_.SetBranchAddress("pf_mus_picky_d0dum", &pf_mus_picky_d0dum_, &b_pf_mus_picky_d0dum_);
  chainB_.SetBranchAddress("pf_mus_picky_d0dumErr", &pf_mus_picky_d0dumErr_, &b_pf_mus_picky_d0dumErr_);
  chainB_.SetBranchAddress("pf_mus_picky_dz", &pf_mus_picky_dz_, &b_pf_mus_picky_dz_);
  chainB_.SetBranchAddress("pf_mus_picky_dzErr", &pf_mus_picky_dzErr_, &b_pf_mus_picky_dzErr_);
  chainB_.SetBranchAddress("pf_mus_picky_eta", &pf_mus_picky_eta_, &b_pf_mus_picky_eta_);
  chainB_.SetBranchAddress("pf_mus_picky_etaErr", &pf_mus_picky_etaErr_, &b_pf_mus_picky_etaErr_);
  chainB_.SetBranchAddress("pf_mus_picky_id", &pf_mus_picky_id_, &b_pf_mus_picky_id_);
  chainB_.SetBranchAddress("pf_mus_picky_ndof", &pf_mus_picky_ndof_, &b_pf_mus_picky_ndof_);
  chainB_.SetBranchAddress("pf_mus_picky_numlosthits", &pf_mus_picky_numlosthits_, &b_pf_mus_picky_numlosthits_);
  chainB_.SetBranchAddress("pf_mus_picky_numvalPixelhits", &pf_mus_picky_numvalPixelhits_, &b_pf_mus_picky_numvalPixelhits_);
  chainB_.SetBranchAddress("pf_mus_picky_numvalhits", &pf_mus_picky_numvalhits_, &b_pf_mus_picky_numvalhits_);
  chainB_.SetBranchAddress("pf_mus_picky_phi", &pf_mus_picky_phi_, &b_pf_mus_picky_phi_);
  chainB_.SetBranchAddress("pf_mus_picky_phiErr", &pf_mus_picky_phiErr_, &b_pf_mus_picky_phiErr_);
  chainB_.SetBranchAddress("pf_mus_picky_pt", &pf_mus_picky_pt_, &b_pf_mus_picky_pt_);
  chainB_.SetBranchAddress("pf_mus_picky_ptErr", &pf_mus_picky_ptErr_, &b_pf_mus_picky_ptErr_);
  chainB_.SetBranchAddress("pf_mus_picky_px", &pf_mus_picky_px_, &b_pf_mus_picky_px_);
  chainB_.SetBranchAddress("pf_mus_picky_py", &pf_mus_picky_py_, &b_pf_mus_picky_py_);
  chainB_.SetBranchAddress("pf_mus_picky_pz", &pf_mus_picky_pz_, &b_pf_mus_picky_pz_);
  chainB_.SetBranchAddress("pf_mus_picky_theta", &pf_mus_picky_theta_, &b_pf_mus_picky_theta_);
  chainB_.SetBranchAddress("pf_mus_picky_vx", &pf_mus_picky_vx_, &b_pf_mus_picky_vx_);
  chainB_.SetBranchAddress("pf_mus_picky_vy", &pf_mus_picky_vy_, &b_pf_mus_picky_vy_);
  chainB_.SetBranchAddress("pf_mus_picky_vz", &pf_mus_picky_vz_, &b_pf_mus_picky_vz_);
  chainB_.SetBranchAddress("pf_mus_pt", &pf_mus_pt_, &b_pf_mus_pt_);
  chainB_.SetBranchAddress("pf_mus_px", &pf_mus_px_, &b_pf_mus_px_);
  chainB_.SetBranchAddress("pf_mus_py", &pf_mus_py_, &b_pf_mus_py_);
  chainB_.SetBranchAddress("pf_mus_pz", &pf_mus_pz_, &b_pf_mus_pz_);
  chainB_.SetBranchAddress("pf_mus_stamu_chg", &pf_mus_stamu_chg_, &b_pf_mus_stamu_chg_);
  chainB_.SetBranchAddress("pf_mus_stamu_chi2", &pf_mus_stamu_chi2_, &b_pf_mus_stamu_chi2_);
  chainB_.SetBranchAddress("pf_mus_stamu_d0dum", &pf_mus_stamu_d0dum_, &b_pf_mus_stamu_d0dum_);
  chainB_.SetBranchAddress("pf_mus_stamu_d0dumErr", &pf_mus_stamu_d0dumErr_, &b_pf_mus_stamu_d0dumErr_);
  chainB_.SetBranchAddress("pf_mus_stamu_dz", &pf_mus_stamu_dz_, &b_pf_mus_stamu_dz_);
  chainB_.SetBranchAddress("pf_mus_stamu_dzErr", &pf_mus_stamu_dzErr_, &b_pf_mus_stamu_dzErr_);
  chainB_.SetBranchAddress("pf_mus_stamu_eta", &pf_mus_stamu_eta_, &b_pf_mus_stamu_eta_);
  chainB_.SetBranchAddress("pf_mus_stamu_etaErr", &pf_mus_stamu_etaErr_, &b_pf_mus_stamu_etaErr_);
  chainB_.SetBranchAddress("pf_mus_stamu_ndof", &pf_mus_stamu_ndof_, &b_pf_mus_stamu_ndof_);
  chainB_.SetBranchAddress("pf_mus_stamu_numlosthits", &pf_mus_stamu_numlosthits_, &b_pf_mus_stamu_numlosthits_);
  chainB_.SetBranchAddress("pf_mus_stamu_numvalhits", &pf_mus_stamu_numvalhits_, &b_pf_mus_stamu_numvalhits_);
  chainB_.SetBranchAddress("pf_mus_stamu_phi", &pf_mus_stamu_phi_, &b_pf_mus_stamu_phi_);
  chainB_.SetBranchAddress("pf_mus_stamu_phiErr", &pf_mus_stamu_phiErr_, &b_pf_mus_stamu_phiErr_);
  chainB_.SetBranchAddress("pf_mus_stamu_pt", &pf_mus_stamu_pt_, &b_pf_mus_stamu_pt_);
  chainB_.SetBranchAddress("pf_mus_stamu_ptErr", &pf_mus_stamu_ptErr_, &b_pf_mus_stamu_ptErr_);
  chainB_.SetBranchAddress("pf_mus_stamu_px", &pf_mus_stamu_px_, &b_pf_mus_stamu_px_);
  chainB_.SetBranchAddress("pf_mus_stamu_py", &pf_mus_stamu_py_, &b_pf_mus_stamu_py_);
  chainB_.SetBranchAddress("pf_mus_stamu_pz", &pf_mus_stamu_pz_, &b_pf_mus_stamu_pz_);
  chainB_.SetBranchAddress("pf_mus_stamu_theta", &pf_mus_stamu_theta_, &b_pf_mus_stamu_theta_);
  chainB_.SetBranchAddress("pf_mus_stamu_vx", &pf_mus_stamu_vx_, &b_pf_mus_stamu_vx_);
  chainB_.SetBranchAddress("pf_mus_stamu_vy", &pf_mus_stamu_vy_, &b_pf_mus_stamu_vy_);
  chainB_.SetBranchAddress("pf_mus_stamu_vz", &pf_mus_stamu_vz_, &b_pf_mus_stamu_vz_);
  chainB_.SetBranchAddress("pf_mus_status", &pf_mus_status_, &b_pf_mus_status_);
  chainB_.SetBranchAddress("pf_mus_tIso", &pf_mus_tIso_, &b_pf_mus_tIso_);
  chainB_.SetBranchAddress("pf_mus_theta", &pf_mus_theta_, &b_pf_mus_theta_);
  chainB_.SetBranchAddress("pf_mus_tkHits", &pf_mus_tkHits_, &b_pf_mus_tkHits_);
  chainB_.SetBranchAddress("pf_mus_tk_ExpectedHitsInner", &pf_mus_tk_ExpectedHitsInner_, &b_pf_mus_tk_ExpectedHitsInner_);
  chainB_.SetBranchAddress("pf_mus_tk_ExpectedHitsOuter", &pf_mus_tk_ExpectedHitsOuter_, &b_pf_mus_tk_ExpectedHitsOuter_);
  chainB_.SetBranchAddress("pf_mus_tk_LayersWithMeasurement", &pf_mus_tk_LayersWithMeasurement_, &b_pf_mus_tk_LayersWithMeasurement_);
  chainB_.SetBranchAddress("pf_mus_tk_LayersWithoutMeasurement", &pf_mus_tk_LayersWithoutMeasurement_, &b_pf_mus_tk_LayersWithoutMeasurement_);
  chainB_.SetBranchAddress("pf_mus_tk_PixelLayersWithMeasurement", &pf_mus_tk_PixelLayersWithMeasurement_, &b_pf_mus_tk_PixelLayersWithMeasurement_);
  chainB_.SetBranchAddress("pf_mus_tk_ValidStripLayersWithMonoAndStereoHit", &pf_mus_tk_ValidStripLayersWithMonoAndStereoHit_, &b_pf_mus_tk_ValidStripLayersWithMonoAndStereoHit_);
  chainB_.SetBranchAddress("pf_mus_tk_chg", &pf_mus_tk_chg_, &b_pf_mus_tk_chg_);
  chainB_.SetBranchAddress("pf_mus_tk_chi2", &pf_mus_tk_chi2_, &b_pf_mus_tk_chi2_);
  chainB_.SetBranchAddress("pf_mus_tk_d0dum", &pf_mus_tk_d0dum_, &b_pf_mus_tk_d0dum_);
  chainB_.SetBranchAddress("pf_mus_tk_d0dumErr", &pf_mus_tk_d0dumErr_, &b_pf_mus_tk_d0dumErr_);
  chainB_.SetBranchAddress("pf_mus_tk_dz", &pf_mus_tk_dz_, &b_pf_mus_tk_dz_);
  chainB_.SetBranchAddress("pf_mus_tk_dzErr", &pf_mus_tk_dzErr_, &b_pf_mus_tk_dzErr_);
  chainB_.SetBranchAddress("pf_mus_tk_eta", &pf_mus_tk_eta_, &b_pf_mus_tk_eta_);
  chainB_.SetBranchAddress("pf_mus_tk_etaErr", &pf_mus_tk_etaErr_, &b_pf_mus_tk_etaErr_);
  chainB_.SetBranchAddress("pf_mus_tk_id", &pf_mus_tk_id_, &b_pf_mus_tk_id_);
  chainB_.SetBranchAddress("pf_mus_tk_ndof", &pf_mus_tk_ndof_, &b_pf_mus_tk_ndof_);
  chainB_.SetBranchAddress("pf_mus_tk_numlosthits", &pf_mus_tk_numlosthits_, &b_pf_mus_tk_numlosthits_);
  chainB_.SetBranchAddress("pf_mus_tk_numpixelWthMeasr", &pf_mus_tk_numpixelWthMeasr_, &b_pf_mus_tk_numpixelWthMeasr_);
  chainB_.SetBranchAddress("pf_mus_tk_numvalPixelhits", &pf_mus_tk_numvalPixelhits_, &b_pf_mus_tk_numvalPixelhits_);
  chainB_.SetBranchAddress("pf_mus_tk_numvalhits", &pf_mus_tk_numvalhits_, &b_pf_mus_tk_numvalhits_);
  chainB_.SetBranchAddress("pf_mus_tk_phi", &pf_mus_tk_phi_, &b_pf_mus_tk_phi_);
  chainB_.SetBranchAddress("pf_mus_tk_phiErr", &pf_mus_tk_phiErr_, &b_pf_mus_tk_phiErr_);
  chainB_.SetBranchAddress("pf_mus_tk_pt", &pf_mus_tk_pt_, &b_pf_mus_tk_pt_);
  chainB_.SetBranchAddress("pf_mus_tk_ptErr", &pf_mus_tk_ptErr_, &b_pf_mus_tk_ptErr_);
  chainB_.SetBranchAddress("pf_mus_tk_px", &pf_mus_tk_px_, &b_pf_mus_tk_px_);
  chainB_.SetBranchAddress("pf_mus_tk_py", &pf_mus_tk_py_, &b_pf_mus_tk_py_);
  chainB_.SetBranchAddress("pf_mus_tk_pz", &pf_mus_tk_pz_, &b_pf_mus_tk_pz_);
  chainB_.SetBranchAddress("pf_mus_tk_theta", &pf_mus_tk_theta_, &b_pf_mus_tk_theta_);
  chainB_.SetBranchAddress("pf_mus_tk_vx", &pf_mus_tk_vx_, &b_pf_mus_tk_vx_);
  chainB_.SetBranchAddress("pf_mus_tk_vy", &pf_mus_tk_vy_, &b_pf_mus_tk_vy_);
  chainB_.SetBranchAddress("pf_mus_tk_vz", &pf_mus_tk_vz_, &b_pf_mus_tk_vz_);
  chainB_.SetBranchAddress("pf_mus_tpfms_ExpectedHitsInner", &pf_mus_tpfms_ExpectedHitsInner_, &b_pf_mus_tpfms_ExpectedHitsInner_);
  chainB_.SetBranchAddress("pf_mus_tpfms_ExpectedHitsOuter", &pf_mus_tpfms_ExpectedHitsOuter_, &b_pf_mus_tpfms_ExpectedHitsOuter_);
  chainB_.SetBranchAddress("pf_mus_tpfms_LayersWithMeasurement", &pf_mus_tpfms_LayersWithMeasurement_, &b_pf_mus_tpfms_LayersWithMeasurement_);
  chainB_.SetBranchAddress("pf_mus_tpfms_LayersWithoutMeasurement", &pf_mus_tpfms_LayersWithoutMeasurement_, &b_pf_mus_tpfms_LayersWithoutMeasurement_);
  chainB_.SetBranchAddress("pf_mus_tpfms_PixelLayersWithMeasurement", &pf_mus_tpfms_PixelLayersWithMeasurement_, &b_pf_mus_tpfms_PixelLayersWithMeasurement_);
  chainB_.SetBranchAddress("pf_mus_tpfms_ValidStripLayersWithMonoAndStereoHit", &pf_mus_tpfms_ValidStripLayersWithMonoAndStereoHit_, &b_pf_mus_tpfms_ValidStripLayersWithMonoAndStereoHit_);
  chainB_.SetBranchAddress("pf_mus_tpfms_chg", &pf_mus_tpfms_chg_, &b_pf_mus_tpfms_chg_);
  chainB_.SetBranchAddress("pf_mus_tpfms_chi2", &pf_mus_tpfms_chi2_, &b_pf_mus_tpfms_chi2_);
  chainB_.SetBranchAddress("pf_mus_tpfms_d0dum", &pf_mus_tpfms_d0dum_, &b_pf_mus_tpfms_d0dum_);
  chainB_.SetBranchAddress("pf_mus_tpfms_d0dumErr", &pf_mus_tpfms_d0dumErr_, &b_pf_mus_tpfms_d0dumErr_);
  chainB_.SetBranchAddress("pf_mus_tpfms_dz", &pf_mus_tpfms_dz_, &b_pf_mus_tpfms_dz_);
  chainB_.SetBranchAddress("pf_mus_tpfms_dzErr", &pf_mus_tpfms_dzErr_, &b_pf_mus_tpfms_dzErr_);
  chainB_.SetBranchAddress("pf_mus_tpfms_eta", &pf_mus_tpfms_eta_, &b_pf_mus_tpfms_eta_);
  chainB_.SetBranchAddress("pf_mus_tpfms_etaErr", &pf_mus_tpfms_etaErr_, &b_pf_mus_tpfms_etaErr_);
  chainB_.SetBranchAddress("pf_mus_tpfms_id", &pf_mus_tpfms_id_, &b_pf_mus_tpfms_id_);
  chainB_.SetBranchAddress("pf_mus_tpfms_ndof", &pf_mus_tpfms_ndof_, &b_pf_mus_tpfms_ndof_);
  chainB_.SetBranchAddress("pf_mus_tpfms_numlosthits", &pf_mus_tpfms_numlosthits_, &b_pf_mus_tpfms_numlosthits_);
  chainB_.SetBranchAddress("pf_mus_tpfms_numvalPixelhits", &pf_mus_tpfms_numvalPixelhits_, &b_pf_mus_tpfms_numvalPixelhits_);
  chainB_.SetBranchAddress("pf_mus_tpfms_numvalhits", &pf_mus_tpfms_numvalhits_, &b_pf_mus_tpfms_numvalhits_);
  chainB_.SetBranchAddress("pf_mus_tpfms_phi", &pf_mus_tpfms_phi_, &b_pf_mus_tpfms_phi_);
  chainB_.SetBranchAddress("pf_mus_tpfms_phiErr", &pf_mus_tpfms_phiErr_, &b_pf_mus_tpfms_phiErr_);
  chainB_.SetBranchAddress("pf_mus_tpfms_pt", &pf_mus_tpfms_pt_, &b_pf_mus_tpfms_pt_);
  chainB_.SetBranchAddress("pf_mus_tpfms_ptErr", &pf_mus_tpfms_ptErr_, &b_pf_mus_tpfms_ptErr_);
  chainB_.SetBranchAddress("pf_mus_tpfms_px", &pf_mus_tpfms_px_, &b_pf_mus_tpfms_px_);
  chainB_.SetBranchAddress("pf_mus_tpfms_py", &pf_mus_tpfms_py_, &b_pf_mus_tpfms_py_);
  chainB_.SetBranchAddress("pf_mus_tpfms_pz", &pf_mus_tpfms_pz_, &b_pf_mus_tpfms_pz_);
  chainB_.SetBranchAddress("pf_mus_tpfms_theta", &pf_mus_tpfms_theta_, &b_pf_mus_tpfms_theta_);
  chainB_.SetBranchAddress("pf_mus_tpfms_vx", &pf_mus_tpfms_vx_, &b_pf_mus_tpfms_vx_);
  chainB_.SetBranchAddress("pf_mus_tpfms_vy", &pf_mus_tpfms_vy_, &b_pf_mus_tpfms_vy_);
  chainB_.SetBranchAddress("pf_mus_tpfms_vz", &pf_mus_tpfms_vz_, &b_pf_mus_tpfms_vz_);
  chainB_.SetBranchAddress("pf_photons_chIso", &pf_photons_chIso_, &b_pf_photons_chIso_);
  chainB_.SetBranchAddress("pf_photons_e1x5", &pf_photons_e1x5_, &b_pf_photons_e1x5_);
  chainB_.SetBranchAddress("pf_photons_e2x5", &pf_photons_e2x5_, &b_pf_photons_e2x5_);
  chainB_.SetBranchAddress("pf_photons_e3x3", &pf_photons_e3x3_, &b_pf_photons_e3x3_);
  chainB_.SetBranchAddress("pf_photons_e5x5", &pf_photons_e5x5_, &b_pf_photons_e5x5_);
  chainB_.SetBranchAddress("pf_photons_energy", &pf_photons_energy_, &b_pf_photons_energy_);
  chainB_.SetBranchAddress("pf_photons_et", &pf_photons_et_, &b_pf_photons_et_);
  chainB_.SetBranchAddress("pf_photons_eta", &pf_photons_eta_, &b_pf_photons_eta_);
  chainB_.SetBranchAddress("pf_photons_hadOverEM", &pf_photons_hadOverEM_, &b_pf_photons_hadOverEM_);
  chainB_.SetBranchAddress("pf_photons_hadTowOverEM", &pf_photons_hadTowOverEM_, &b_pf_photons_hadTowOverEM_);
  chainB_.SetBranchAddress("pf_photons_hasPixelSeed", &pf_photons_hasPixelSeed_, &b_pf_photons_hasPixelSeed_);
  chainB_.SetBranchAddress("pf_photons_isAlsoElectron", &pf_photons_isAlsoElectron_, &b_pf_photons_isAlsoElectron_);
  chainB_.SetBranchAddress("pf_photons_isConverted", &pf_photons_isConverted_, &b_pf_photons_isConverted_);
  chainB_.SetBranchAddress("pf_photons_isEBEEGap", &pf_photons_isEBEEGap_, &b_pf_photons_isEBEEGap_);
  chainB_.SetBranchAddress("pf_photons_isEBGap", &pf_photons_isEBGap_, &b_pf_photons_isEBGap_);
  chainB_.SetBranchAddress("pf_photons_isEBPho", &pf_photons_isEBPho_, &b_pf_photons_isEBPho_);
  chainB_.SetBranchAddress("pf_photons_isEEGap", &pf_photons_isEEGap_, &b_pf_photons_isEEGap_);
  chainB_.SetBranchAddress("pf_photons_isEEPho", &pf_photons_isEEPho_, &b_pf_photons_isEEPho_);
  chainB_.SetBranchAddress("pf_photons_maxEnergyXtal", &pf_photons_maxEnergyXtal_, &b_pf_photons_maxEnergyXtal_);
  chainB_.SetBranchAddress("pf_photons_nhIso", &pf_photons_nhIso_, &b_pf_photons_nhIso_);
  chainB_.SetBranchAddress("pf_photons_phIso", &pf_photons_phIso_, &b_pf_photons_phIso_);
  chainB_.SetBranchAddress("pf_photons_phi", &pf_photons_phi_, &b_pf_photons_phi_);
  chainB_.SetBranchAddress("pf_photons_pt", &pf_photons_pt_, &b_pf_photons_pt_);
  chainB_.SetBranchAddress("pf_photons_px", &pf_photons_px_, &b_pf_photons_px_);
  chainB_.SetBranchAddress("pf_photons_py", &pf_photons_py_, &b_pf_photons_py_);
  chainB_.SetBranchAddress("pf_photons_pz", &pf_photons_pz_, &b_pf_photons_pz_);
  chainB_.SetBranchAddress("pf_photons_r9", &pf_photons_r9_, &b_pf_photons_r9_);
  chainB_.SetBranchAddress("pf_photons_scEnergy", &pf_photons_scEnergy_, &b_pf_photons_scEnergy_);
  chainB_.SetBranchAddress("pf_photons_scEta", &pf_photons_scEta_, &b_pf_photons_scEta_);
  chainB_.SetBranchAddress("pf_photons_scEtaWidth", &pf_photons_scEtaWidth_, &b_pf_photons_scEtaWidth_);
  chainB_.SetBranchAddress("pf_photons_scPhi", &pf_photons_scPhi_, &b_pf_photons_scPhi_);
  chainB_.SetBranchAddress("pf_photons_scPhiWidth", &pf_photons_scPhiWidth_, &b_pf_photons_scPhiWidth_);
  chainB_.SetBranchAddress("pf_photons_scRawEnergy", &pf_photons_scRawEnergy_, &b_pf_photons_scRawEnergy_);
  chainB_.SetBranchAddress("pf_photons_sigmaEtaEta", &pf_photons_sigmaEtaEta_, &b_pf_photons_sigmaEtaEta_);
  chainB_.SetBranchAddress("pf_photons_sigmaIetaIeta", &pf_photons_sigmaIetaIeta_, &b_pf_photons_sigmaIetaIeta_);
  chainB_.SetBranchAddress("pf_photons_status", &pf_photons_status_, &b_pf_photons_status_);
  chainB_.SetBranchAddress("pf_photons_theta", &pf_photons_theta_, &b_pf_photons_theta_);
  chainB_.SetBranchAddress("pfcand_particleId", &pfcand_particleId_, &b_pfcand_particleId_);
  chainB_.SetBranchAddress("pfmets_et", &pfmets_et_, &b_pfmets_et_);
  chainB_.SetBranchAddress("pfmets_ex", &pfmets_ex_, &b_pfmets_ex_);
  chainB_.SetBranchAddress("pfmets_ey", &pfmets_ey_, &b_pfmets_ey_);
  chainB_.SetBranchAddress("pfmets_gen_et", &pfmets_gen_et_, &b_pfmets_gen_et_);
  chainB_.SetBranchAddress("pfmets_gen_phi", &pfmets_gen_phi_, &b_pfmets_gen_phi_);
  chainB_.SetBranchAddress("pfmets_phi", &pfmets_phi_, &b_pfmets_phi_);
  chainB_.SetBranchAddress("pfmets_sign", &pfmets_sign_, &b_pfmets_sign_);
  chainB_.SetBranchAddress("pfmets_sumEt", &pfmets_sumEt_, &b_pfmets_sumEt_);
  chainB_.SetBranchAddress("pfmets_unCPhi", &pfmets_unCPhi_, &b_pfmets_unCPhi_);
  chainB_.SetBranchAddress("pfmets_unCPt", &pfmets_unCPt_, &b_pfmets_unCPt_);
  chainB_.SetBranchAddress("tcmets_et", &tcmets_et_, &b_tcmets_et_);
  chainB_.SetBranchAddress("tcmets_ex", &tcmets_ex_, &b_tcmets_ex_);
  chainB_.SetBranchAddress("tcmets_ey", &tcmets_ey_, &b_tcmets_ey_);
  chainB_.SetBranchAddress("tcmets_phi", &tcmets_phi_, &b_tcmets_phi_);
  chainB_.SetBranchAddress("tcmets_sumEt", &tcmets_sumEt_, &b_tcmets_sumEt_);
  chainB_.SetBranchAddress("tracks_chg", &tracks_chg_, &b_tracks_chg_);
  chainB_.SetBranchAddress("tracks_chi2", &tracks_chi2_, &b_tracks_chi2_);
  chainB_.SetBranchAddress("tracks_d0dum", &tracks_d0dum_, &b_tracks_d0dum_);
  chainB_.SetBranchAddress("tracks_d0dumErr", &tracks_d0dumErr_, &b_tracks_d0dumErr_);
  chainB_.SetBranchAddress("tracks_dz", &tracks_dz_, &b_tracks_dz_);
  chainB_.SetBranchAddress("tracks_dzErr", &tracks_dzErr_, &b_tracks_dzErr_);
  chainB_.SetBranchAddress("tracks_eta", &tracks_eta_, &b_tracks_eta_);
  chainB_.SetBranchAddress("tracks_etaErr", &tracks_etaErr_, &b_tracks_etaErr_);
  chainB_.SetBranchAddress("tracks_highPurity", &tracks_highPurity_, &b_tracks_highPurity_);
  chainB_.SetBranchAddress("tracks_ndof", &tracks_ndof_, &b_tracks_ndof_);
  chainB_.SetBranchAddress("tracks_numlosthits", &tracks_numlosthits_, &b_tracks_numlosthits_);
  chainB_.SetBranchAddress("tracks_numvalhits", &tracks_numvalhits_, &b_tracks_numvalhits_);
  chainB_.SetBranchAddress("tracks_phi", &tracks_phi_, &b_tracks_phi_);
  chainB_.SetBranchAddress("tracks_phiErr", &tracks_phiErr_, &b_tracks_phiErr_);
  chainB_.SetBranchAddress("tracks_pt", &tracks_pt_, &b_tracks_pt_);
  chainB_.SetBranchAddress("tracks_ptErr", &tracks_ptErr_, &b_tracks_ptErr_);
  chainB_.SetBranchAddress("tracks_px", &tracks_px_, &b_tracks_px_);
  chainB_.SetBranchAddress("tracks_py", &tracks_py_, &b_tracks_py_);
  chainB_.SetBranchAddress("tracks_pz", &tracks_pz_, &b_tracks_pz_);
  chainB_.SetBranchAddress("tracks_vx", &tracks_vx_, &b_tracks_vx_);
  chainB_.SetBranchAddress("tracks_vy", &tracks_vy_, &b_tracks_vy_);
  chainB_.SetBranchAddress("tracks_vz", &tracks_vz_, &b_tracks_vz_);
}

cfa_8::~cfa_8(){
}

std::vector<std::string>* const & cfa_8::L1trigger_alias() const{
  if(!c_L1trigger_alias_ && b_L1trigger_alias_){
    b_L1trigger_alias_->SetStatus(true);
    chainA_.SetBranchAddress("L1trigger_alias", &L1trigger_alias_, &b_L1trigger_alias_);
    b_L1trigger_alias_->GetEntry(entry_);
    c_L1trigger_alias_ = true;
  }
  return L1trigger_alias_;
}

std::vector<float>* const & cfa_8::L1trigger_bit() const{
  if(!c_L1trigger_bit_ && b_L1trigger_bit_){
    b_L1trigger_bit_->SetStatus(true);
    chainA_.SetBranchAddress("L1trigger_bit", &L1trigger_bit_, &b_L1trigger_bit_);
    b_L1trigger_bit_->GetEntry(entry_);
    c_L1trigger_bit_ = true;
  }
  return L1trigger_bit_;
}

std::vector<float>* const & cfa_8::L1trigger_decision() const{
  if(!c_L1trigger_decision_ && b_L1trigger_decision_){
    b_L1trigger_decision_->SetStatus(true);
    chainA_.SetBranchAddress("L1trigger_decision", &L1trigger_decision_, &b_L1trigger_decision_);
    b_L1trigger_decision_->GetEntry(entry_);
    c_L1trigger_decision_ = true;
  }
  return L1trigger_decision_;
}

std::vector<float>* const & cfa_8::L1trigger_decision_nomask() const{
  if(!c_L1trigger_decision_nomask_ && b_L1trigger_decision_nomask_){
    b_L1trigger_decision_nomask_->SetStatus(true);
    chainA_.SetBranchAddress("L1trigger_decision_nomask", &L1trigger_decision_nomask_, &b_L1trigger_decision_nomask_);
    b_L1trigger_decision_nomask_->GetEntry(entry_);
    c_L1trigger_decision_nomask_ = true;
  }
  return L1trigger_decision_nomask_;
}

std::vector<std::string>* const & cfa_8::L1trigger_name() const{
  if(!c_L1trigger_name_ && b_L1trigger_name_){
    b_L1trigger_name_->SetStatus(true);
    chainA_.SetBranchAddress("L1trigger_name", &L1trigger_name_, &b_L1trigger_name_);
    b_L1trigger_name_->GetEntry(entry_);
    c_L1trigger_name_ = true;
  }
  return L1trigger_name_;
}

std::vector<float>* const & cfa_8::L1trigger_prescalevalue() const{
  if(!c_L1trigger_prescalevalue_ && b_L1trigger_prescalevalue_){
    b_L1trigger_prescalevalue_->SetStatus(true);
    chainA_.SetBranchAddress("L1trigger_prescalevalue", &L1trigger_prescalevalue_, &b_L1trigger_prescalevalue_);
    b_L1trigger_prescalevalue_->GetEntry(entry_);
    c_L1trigger_prescalevalue_ = true;
  }
  return L1trigger_prescalevalue_;
}

std::vector<float>* const & cfa_8::L1trigger_techTrigger() const{
  if(!c_L1trigger_techTrigger_ && b_L1trigger_techTrigger_){
    b_L1trigger_techTrigger_->SetStatus(true);
    chainA_.SetBranchAddress("L1trigger_techTrigger", &L1trigger_techTrigger_, &b_L1trigger_techTrigger_);
    b_L1trigger_techTrigger_->GetEntry(entry_);
    c_L1trigger_techTrigger_ = true;
  }
  return L1trigger_techTrigger_;
}

Float_t const & cfa_8::MPT() const{
  if(!c_MPT_ && b_MPT_){
    b_MPT_->SetStatus(true);
    chainA_.SetBranchAddress("MPT", &MPT_, &b_MPT_);
    b_MPT_->GetEntry(entry_);
    c_MPT_ = true;
  }
  return MPT_;
}

UInt_t const & cfa_8::Njets_AK5PF() const{
  if(!c_Njets_AK5PF_ && b_Njets_AK5PF_){
    b_Njets_AK5PF_->SetStatus(true);
    chainB_.SetBranchAddress("Njets_AK5PF", &Njets_AK5PF_, &b_Njets_AK5PF_);
    b_Njets_AK5PF_->GetEntry(entry_);
    c_Njets_AK5PF_ = true;
  }
  return Njets_AK5PF_;
}

UInt_t const & cfa_8::Njets_AK5PFclean() const{
  if(!c_Njets_AK5PFclean_ && b_Njets_AK5PFclean_){
    b_Njets_AK5PFclean_->SetStatus(true);
    chainB_.SetBranchAddress("Njets_AK5PFclean", &Njets_AK5PFclean_, &b_Njets_AK5PFclean_);
    b_Njets_AK5PFclean_->GetEntry(entry_);
    c_Njets_AK5PFclean_ = true;
  }
  return Njets_AK5PFclean_;
}

UInt_t const & cfa_8::Nmc_pdf() const{
  if(!c_Nmc_pdf_ && b_Nmc_pdf_){
    b_Nmc_pdf_->SetStatus(true);
    chainB_.SetBranchAddress("Nmc_pdf", &Nmc_pdf_, &b_Nmc_pdf_);
    b_Nmc_pdf_->GetEntry(entry_);
    c_Nmc_pdf_ = true;
  }
  return Nmc_pdf_;
}

UInt_t const & cfa_8::NmetsHO() const{
  if(!c_NmetsHO_ && b_NmetsHO_){
    b_NmetsHO_->SetStatus(true);
    chainB_.SetBranchAddress("NmetsHO", &NmetsHO_, &b_NmetsHO_);
    b_NmetsHO_->GetEntry(entry_);
    c_NmetsHO_ = true;
  }
  return NmetsHO_;
}

UInt_t const & cfa_8::Nmets_AK5() const{
  if(!c_Nmets_AK5_ && b_Nmets_AK5_){
    b_Nmets_AK5_->SetStatus(true);
    chainB_.SetBranchAddress("Nmets_AK5", &Nmets_AK5_, &b_Nmets_AK5_);
    b_Nmets_AK5_->GetEntry(entry_);
    c_Nmets_AK5_ = true;
  }
  return Nmets_AK5_;
}

UInt_t const & cfa_8::NpfTypeINoXYCorrmets() const{
  if(!c_NpfTypeINoXYCorrmets_ && b_NpfTypeINoXYCorrmets_){
    b_NpfTypeINoXYCorrmets_->SetStatus(true);
    chainB_.SetBranchAddress("NpfTypeINoXYCorrmets", &NpfTypeINoXYCorrmets_, &b_NpfTypeINoXYCorrmets_);
    b_NpfTypeINoXYCorrmets_->GetEntry(entry_);
    c_NpfTypeINoXYCorrmets_ = true;
  }
  return NpfTypeINoXYCorrmets_;
}

UInt_t const & cfa_8::NpfTypeIType0mets() const{
  if(!c_NpfTypeIType0mets_ && b_NpfTypeIType0mets_){
    b_NpfTypeIType0mets_->SetStatus(true);
    chainB_.SetBranchAddress("NpfTypeIType0mets", &NpfTypeIType0mets_, &b_NpfTypeIType0mets_);
    b_NpfTypeIType0mets_->GetEntry(entry_);
    c_NpfTypeIType0mets_ = true;
  }
  return NpfTypeIType0mets_;
}

UInt_t const & cfa_8::NpfTypeImets() const{
  if(!c_NpfTypeImets_ && b_NpfTypeImets_){
    b_NpfTypeImets_->SetStatus(true);
    chainB_.SetBranchAddress("NpfTypeImets", &NpfTypeImets_, &b_NpfTypeImets_);
    b_NpfTypeImets_->GetEntry(entry_);
    c_NpfTypeImets_ = true;
  }
  return NpfTypeImets_;
}

UInt_t const & cfa_8::Npf_els() const{
  if(!c_Npf_els_ && b_Npf_els_){
    b_Npf_els_->SetStatus(true);
    chainB_.SetBranchAddress("Npf_els", &Npf_els_, &b_Npf_els_);
    b_Npf_els_->GetEntry(entry_);
    c_Npf_els_ = true;
  }
  return Npf_els_;
}

UInt_t const & cfa_8::Npf_mus() const{
  if(!c_Npf_mus_ && b_Npf_mus_){
    b_Npf_mus_->SetStatus(true);
    chainB_.SetBranchAddress("Npf_mus", &Npf_mus_, &b_Npf_mus_);
    b_Npf_mus_->GetEntry(entry_);
    c_Npf_mus_ = true;
  }
  return Npf_mus_;
}

UInt_t const & cfa_8::Npf_photons() const{
  if(!c_Npf_photons_ && b_Npf_photons_){
    b_Npf_photons_->SetStatus(true);
    chainB_.SetBranchAddress("Npf_photons", &Npf_photons_, &b_Npf_photons_);
    b_Npf_photons_->GetEntry(entry_);
    c_Npf_photons_ = true;
  }
  return Npf_photons_;
}

UInt_t const & cfa_8::Npfmets() const{
  if(!c_Npfmets_ && b_Npfmets_){
    b_Npfmets_->SetStatus(true);
    chainB_.SetBranchAddress("Npfmets", &Npfmets_, &b_Npfmets_);
    b_Npfmets_->GetEntry(entry_);
    c_Npfmets_ = true;
  }
  return Npfmets_;
}

UInt_t const & cfa_8::Ntcmets() const{
  if(!c_Ntcmets_ && b_Ntcmets_){
    b_Ntcmets_->SetStatus(true);
    chainB_.SetBranchAddress("Ntcmets", &Ntcmets_, &b_Ntcmets_);
    b_Ntcmets_->GetEntry(entry_);
    c_Ntcmets_ = true;
  }
  return Ntcmets_;
}

UInt_t const & cfa_8::Ntracks() const{
  if(!c_Ntracks_ && b_Ntracks_){
    b_Ntracks_->SetStatus(true);
    chainB_.SetBranchAddress("Ntracks", &Ntracks_, &b_Ntracks_);
    b_Ntracks_->GetEntry(entry_);
    c_Ntracks_ = true;
  }
  return Ntracks_;
}

Int_t const & cfa_8::ecalBEfilter_decision() const{
  if(!c_ecalBEfilter_decision_ && b_ecalBEfilter_decision_){
    b_ecalBEfilter_decision_->SetStatus(true);
    chainA_.SetBranchAddress("ecalBEfilter_decision", &ecalBEfilter_decision_, &b_ecalBEfilter_decision_);
    b_ecalBEfilter_decision_->GetEntry(entry_);
    c_ecalBEfilter_decision_ = true;
  }
  return ecalBEfilter_decision_;
}

Int_t const & cfa_8::ecalTPfilter_decision() const{
  if(!c_ecalTPfilter_decision_ && b_ecalTPfilter_decision_){
    b_ecalTPfilter_decision_->SetStatus(true);
    chainA_.SetBranchAddress("ecalTPfilter_decision", &ecalTPfilter_decision_, &b_ecalTPfilter_decision_);
    b_ecalTPfilter_decision_->GetEntry(entry_);
    c_ecalTPfilter_decision_ = true;
  }
  return ecalTPfilter_decision_;
}

Int_t const & cfa_8::eenoisefilter_decision() const{
  if(!c_eenoisefilter_decision_ && b_eenoisefilter_decision_){
    b_eenoisefilter_decision_->SetStatus(true);
    chainA_.SetBranchAddress("eenoisefilter_decision", &eenoisefilter_decision_, &b_eenoisefilter_decision_);
    b_eenoisefilter_decision_->GetEntry(entry_);
    c_eenoisefilter_decision_ = true;
  }
  return eenoisefilter_decision_;
}

std::vector<float>* const & cfa_8::els_PFchargedHadronIsoR03() const{
  if(!c_els_PFchargedHadronIsoR03_ && b_els_PFchargedHadronIsoR03_){
    b_els_PFchargedHadronIsoR03_->SetStatus(true);
    chainA_.SetBranchAddress("els_PFchargedHadronIsoR03", &els_PFchargedHadronIsoR03_, &b_els_PFchargedHadronIsoR03_);
    b_els_PFchargedHadronIsoR03_->GetEntry(entry_);
    c_els_PFchargedHadronIsoR03_ = true;
  }
  return els_PFchargedHadronIsoR03_;
}

std::vector<float>* const & cfa_8::els_PFneutralHadronIsoR03() const{
  if(!c_els_PFneutralHadronIsoR03_ && b_els_PFneutralHadronIsoR03_){
    b_els_PFneutralHadronIsoR03_->SetStatus(true);
    chainA_.SetBranchAddress("els_PFneutralHadronIsoR03", &els_PFneutralHadronIsoR03_, &b_els_PFneutralHadronIsoR03_);
    b_els_PFneutralHadronIsoR03_->GetEntry(entry_);
    c_els_PFneutralHadronIsoR03_ = true;
  }
  return els_PFneutralHadronIsoR03_;
}

std::vector<float>* const & cfa_8::els_PFphotonIsoR03() const{
  if(!c_els_PFphotonIsoR03_ && b_els_PFphotonIsoR03_){
    b_els_PFphotonIsoR03_->SetStatus(true);
    chainA_.SetBranchAddress("els_PFphotonIsoR03", &els_PFphotonIsoR03_, &b_els_PFphotonIsoR03_);
    b_els_PFphotonIsoR03_->GetEntry(entry_);
    c_els_PFphotonIsoR03_ = true;
  }
  return els_PFphotonIsoR03_;
}

std::vector<float>* const & cfa_8::els_conversion_dcot() const{
  if(!c_els_conversion_dcot_ && b_els_conversion_dcot_){
    b_els_conversion_dcot_->SetStatus(true);
    chainA_.SetBranchAddress("els_conversion_dcot", &els_conversion_dcot_, &b_els_conversion_dcot_);
    b_els_conversion_dcot_->GetEntry(entry_);
    c_els_conversion_dcot_ = true;
  }
  return els_conversion_dcot_;
}

std::vector<float>* const & cfa_8::els_conversion_dist() const{
  if(!c_els_conversion_dist_ && b_els_conversion_dist_){
    b_els_conversion_dist_->SetStatus(true);
    chainA_.SetBranchAddress("els_conversion_dist", &els_conversion_dist_, &b_els_conversion_dist_);
    b_els_conversion_dist_->GetEntry(entry_);
    c_els_conversion_dist_ = true;
  }
  return els_conversion_dist_;
}

std::vector<bool>* const & cfa_8::els_hasMatchedConversion() const{
  if(!c_els_hasMatchedConversion_ && b_els_hasMatchedConversion_){
    b_els_hasMatchedConversion_->SetStatus(true);
    chainA_.SetBranchAddress("els_hasMatchedConversion", &els_hasMatchedConversion_, &b_els_hasMatchedConversion_);
    b_els_hasMatchedConversion_->GetEntry(entry_);
    c_els_hasMatchedConversion_ = true;
  }
  return els_hasMatchedConversion_;
}

Float_t const & cfa_8::genHT() const{
  if(!c_genHT_ && b_genHT_){
    b_genHT_->SetStatus(true);
    chainA_.SetBranchAddress("genHT", &genHT_, &b_genHT_);
    b_genHT_->GetEntry(entry_);
    c_genHT_ = true;
  }
  return genHT_;
}

Int_t const & cfa_8::greedymuonfilter_decision() const{
  if(!c_greedymuonfilter_decision_ && b_greedymuonfilter_decision_){
    b_greedymuonfilter_decision_->SetStatus(true);
    chainA_.SetBranchAddress("greedymuonfilter_decision", &greedymuonfilter_decision_, &b_greedymuonfilter_decision_);
    b_greedymuonfilter_decision_->GetEntry(entry_);
    c_greedymuonfilter_decision_ = true;
  }
  return greedymuonfilter_decision_;
}

Int_t const & cfa_8::hbhefilter_decision() const{
  if(!c_hbhefilter_decision_ && b_hbhefilter_decision_){
    b_hbhefilter_decision_->SetStatus(true);
    chainA_.SetBranchAddress("hbhefilter_decision", &hbhefilter_decision_, &b_hbhefilter_decision_);
    b_hbhefilter_decision_->GetEntry(entry_);
    c_hbhefilter_decision_ = true;
  }
  return hbhefilter_decision_;
}

Int_t const & cfa_8::inconsistentPFmuonfilter_decision() const{
  if(!c_inconsistentPFmuonfilter_decision_ && b_inconsistentPFmuonfilter_decision_){
    b_inconsistentPFmuonfilter_decision_->SetStatus(true);
    chainA_.SetBranchAddress("inconsistentPFmuonfilter_decision", &inconsistentPFmuonfilter_decision_, &b_inconsistentPFmuonfilter_decision_);
    b_inconsistentPFmuonfilter_decision_->GetEntry(entry_);
    c_inconsistentPFmuonfilter_decision_ = true;
  }
  return inconsistentPFmuonfilter_decision_;
}

std::vector<int>* const & cfa_8::isotk_charge() const{
  if(!c_isotk_charge_ && b_isotk_charge_){
    b_isotk_charge_->SetStatus(true);
    chainA_.SetBranchAddress("isotk_charge", &isotk_charge_, &b_isotk_charge_);
    b_isotk_charge_->GetEntry(entry_);
    c_isotk_charge_ = true;
  }
  return isotk_charge_;
}

std::vector<float>* const & cfa_8::isotk_dzpv() const{
  if(!c_isotk_dzpv_ && b_isotk_dzpv_){
    b_isotk_dzpv_->SetStatus(true);
    chainA_.SetBranchAddress("isotk_dzpv", &isotk_dzpv_, &b_isotk_dzpv_);
    b_isotk_dzpv_->GetEntry(entry_);
    c_isotk_dzpv_ = true;
  }
  return isotk_dzpv_;
}

std::vector<float>* const & cfa_8::isotk_eta() const{
  if(!c_isotk_eta_ && b_isotk_eta_){
    b_isotk_eta_->SetStatus(true);
    chainA_.SetBranchAddress("isotk_eta", &isotk_eta_, &b_isotk_eta_);
    b_isotk_eta_->GetEntry(entry_);
    c_isotk_eta_ = true;
  }
  return isotk_eta_;
}

std::vector<float>* const & cfa_8::isotk_iso() const{
  if(!c_isotk_iso_ && b_isotk_iso_){
    b_isotk_iso_->SetStatus(true);
    chainA_.SetBranchAddress("isotk_iso", &isotk_iso_, &b_isotk_iso_);
    b_isotk_iso_->GetEntry(entry_);
    c_isotk_iso_ = true;
  }
  return isotk_iso_;
}

std::vector<float>* const & cfa_8::isotk_phi() const{
  if(!c_isotk_phi_ && b_isotk_phi_){
    b_isotk_phi_->SetStatus(true);
    chainA_.SetBranchAddress("isotk_phi", &isotk_phi_, &b_isotk_phi_);
    b_isotk_phi_->GetEntry(entry_);
    c_isotk_phi_ = true;
  }
  return isotk_phi_;
}

std::vector<float>* const & cfa_8::isotk_pt() const{
  if(!c_isotk_pt_ && b_isotk_pt_){
    b_isotk_pt_->SetStatus(true);
    chainA_.SetBranchAddress("isotk_pt", &isotk_pt_, &b_isotk_pt_);
    b_isotk_pt_->GetEntry(entry_);
    c_isotk_pt_ = true;
  }
  return isotk_pt_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_area() const{
  if(!c_jets_AK5PF_area_ && b_jets_AK5PF_area_){
    b_jets_AK5PF_area_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_area", &jets_AK5PF_area_, &b_jets_AK5PF_area_);
    b_jets_AK5PF_area_->GetEntry(entry_);
    c_jets_AK5PF_area_ = true;
  }
  return jets_AK5PF_area_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_btag_TC_highEff() const{
  if(!c_jets_AK5PF_btag_TC_highEff_ && b_jets_AK5PF_btag_TC_highEff_){
    b_jets_AK5PF_btag_TC_highEff_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_btag_TC_highEff", &jets_AK5PF_btag_TC_highEff_, &b_jets_AK5PF_btag_TC_highEff_);
    b_jets_AK5PF_btag_TC_highEff_->GetEntry(entry_);
    c_jets_AK5PF_btag_TC_highEff_ = true;
  }
  return jets_AK5PF_btag_TC_highEff_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_btag_TC_highPur() const{
  if(!c_jets_AK5PF_btag_TC_highPur_ && b_jets_AK5PF_btag_TC_highPur_){
    b_jets_AK5PF_btag_TC_highPur_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_btag_TC_highPur", &jets_AK5PF_btag_TC_highPur_, &b_jets_AK5PF_btag_TC_highPur_);
    b_jets_AK5PF_btag_TC_highPur_->GetEntry(entry_);
    c_jets_AK5PF_btag_TC_highPur_ = true;
  }
  return jets_AK5PF_btag_TC_highPur_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_btag_jetBProb() const{
  if(!c_jets_AK5PF_btag_jetBProb_ && b_jets_AK5PF_btag_jetBProb_){
    b_jets_AK5PF_btag_jetBProb_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_btag_jetBProb", &jets_AK5PF_btag_jetBProb_, &b_jets_AK5PF_btag_jetBProb_);
    b_jets_AK5PF_btag_jetBProb_->GetEntry(entry_);
    c_jets_AK5PF_btag_jetBProb_ = true;
  }
  return jets_AK5PF_btag_jetBProb_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_btag_jetProb() const{
  if(!c_jets_AK5PF_btag_jetProb_ && b_jets_AK5PF_btag_jetProb_){
    b_jets_AK5PF_btag_jetProb_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_btag_jetProb", &jets_AK5PF_btag_jetProb_, &b_jets_AK5PF_btag_jetProb_);
    b_jets_AK5PF_btag_jetProb_->GetEntry(entry_);
    c_jets_AK5PF_btag_jetProb_ = true;
  }
  return jets_AK5PF_btag_jetProb_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_btag_secVertexCombined() const{
  if(!c_jets_AK5PF_btag_secVertexCombined_ && b_jets_AK5PF_btag_secVertexCombined_){
    b_jets_AK5PF_btag_secVertexCombined_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_btag_secVertexCombined", &jets_AK5PF_btag_secVertexCombined_, &b_jets_AK5PF_btag_secVertexCombined_);
    b_jets_AK5PF_btag_secVertexCombined_->GetEntry(entry_);
    c_jets_AK5PF_btag_secVertexCombined_ = true;
  }
  return jets_AK5PF_btag_secVertexCombined_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_btag_secVertexHighEff() const{
  if(!c_jets_AK5PF_btag_secVertexHighEff_ && b_jets_AK5PF_btag_secVertexHighEff_){
    b_jets_AK5PF_btag_secVertexHighEff_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_btag_secVertexHighEff", &jets_AK5PF_btag_secVertexHighEff_, &b_jets_AK5PF_btag_secVertexHighEff_);
    b_jets_AK5PF_btag_secVertexHighEff_->GetEntry(entry_);
    c_jets_AK5PF_btag_secVertexHighEff_ = true;
  }
  return jets_AK5PF_btag_secVertexHighEff_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_btag_secVertexHighPur() const{
  if(!c_jets_AK5PF_btag_secVertexHighPur_ && b_jets_AK5PF_btag_secVertexHighPur_){
    b_jets_AK5PF_btag_secVertexHighPur_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_btag_secVertexHighPur", &jets_AK5PF_btag_secVertexHighPur_, &b_jets_AK5PF_btag_secVertexHighPur_);
    b_jets_AK5PF_btag_secVertexHighPur_->GetEntry(entry_);
    c_jets_AK5PF_btag_secVertexHighPur_ = true;
  }
  return jets_AK5PF_btag_secVertexHighPur_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_btag_softEle() const{
  if(!c_jets_AK5PF_btag_softEle_ && b_jets_AK5PF_btag_softEle_){
    b_jets_AK5PF_btag_softEle_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_btag_softEle", &jets_AK5PF_btag_softEle_, &b_jets_AK5PF_btag_softEle_);
    b_jets_AK5PF_btag_softEle_->GetEntry(entry_);
    c_jets_AK5PF_btag_softEle_ = true;
  }
  return jets_AK5PF_btag_softEle_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_btag_softMuon() const{
  if(!c_jets_AK5PF_btag_softMuon_ && b_jets_AK5PF_btag_softMuon_){
    b_jets_AK5PF_btag_softMuon_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_btag_softMuon", &jets_AK5PF_btag_softMuon_, &b_jets_AK5PF_btag_softMuon_);
    b_jets_AK5PF_btag_softMuon_->GetEntry(entry_);
    c_jets_AK5PF_btag_softMuon_ = true;
  }
  return jets_AK5PF_btag_softMuon_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_chgEmE() const{
  if(!c_jets_AK5PF_chgEmE_ && b_jets_AK5PF_chgEmE_){
    b_jets_AK5PF_chgEmE_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_chgEmE", &jets_AK5PF_chgEmE_, &b_jets_AK5PF_chgEmE_);
    b_jets_AK5PF_chgEmE_->GetEntry(entry_);
    c_jets_AK5PF_chgEmE_ = true;
  }
  return jets_AK5PF_chgEmE_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_chgHadE() const{
  if(!c_jets_AK5PF_chgHadE_ && b_jets_AK5PF_chgHadE_){
    b_jets_AK5PF_chgHadE_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_chgHadE", &jets_AK5PF_chgHadE_, &b_jets_AK5PF_chgHadE_);
    b_jets_AK5PF_chgHadE_->GetEntry(entry_);
    c_jets_AK5PF_chgHadE_ = true;
  }
  return jets_AK5PF_chgHadE_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_chgMuE() const{
  if(!c_jets_AK5PF_chgMuE_ && b_jets_AK5PF_chgMuE_){
    b_jets_AK5PF_chgMuE_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_chgMuE", &jets_AK5PF_chgMuE_, &b_jets_AK5PF_chgMuE_);
    b_jets_AK5PF_chgMuE_->GetEntry(entry_);
    c_jets_AK5PF_chgMuE_ = true;
  }
  return jets_AK5PF_chgMuE_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_chg_Mult() const{
  if(!c_jets_AK5PF_chg_Mult_ && b_jets_AK5PF_chg_Mult_){
    b_jets_AK5PF_chg_Mult_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_chg_Mult", &jets_AK5PF_chg_Mult_, &b_jets_AK5PF_chg_Mult_);
    b_jets_AK5PF_chg_Mult_->GetEntry(entry_);
    c_jets_AK5PF_chg_Mult_ = true;
  }
  return jets_AK5PF_chg_Mult_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_corrFactorRaw() const{
  if(!c_jets_AK5PF_corrFactorRaw_ && b_jets_AK5PF_corrFactorRaw_){
    b_jets_AK5PF_corrFactorRaw_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_corrFactorRaw", &jets_AK5PF_corrFactorRaw_, &b_jets_AK5PF_corrFactorRaw_);
    b_jets_AK5PF_corrFactorRaw_->GetEntry(entry_);
    c_jets_AK5PF_corrFactorRaw_ = true;
  }
  return jets_AK5PF_corrFactorRaw_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_ehf() const{
  if(!c_jets_AK5PF_ehf_ && b_jets_AK5PF_ehf_){
    b_jets_AK5PF_ehf_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_ehf", &jets_AK5PF_ehf_, &b_jets_AK5PF_ehf_);
    b_jets_AK5PF_ehf_->GetEntry(entry_);
    c_jets_AK5PF_ehf_ = true;
  }
  return jets_AK5PF_ehf_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_emf() const{
  if(!c_jets_AK5PF_emf_ && b_jets_AK5PF_emf_){
    b_jets_AK5PF_emf_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_emf", &jets_AK5PF_emf_, &b_jets_AK5PF_emf_);
    b_jets_AK5PF_emf_->GetEntry(entry_);
    c_jets_AK5PF_emf_ = true;
  }
  return jets_AK5PF_emf_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_energy() const{
  if(!c_jets_AK5PF_energy_ && b_jets_AK5PF_energy_){
    b_jets_AK5PF_energy_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_energy", &jets_AK5PF_energy_, &b_jets_AK5PF_energy_);
    b_jets_AK5PF_energy_->GetEntry(entry_);
    c_jets_AK5PF_energy_ = true;
  }
  return jets_AK5PF_energy_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_et() const{
  if(!c_jets_AK5PF_et_ && b_jets_AK5PF_et_){
    b_jets_AK5PF_et_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_et", &jets_AK5PF_et_, &b_jets_AK5PF_et_);
    b_jets_AK5PF_et_->GetEntry(entry_);
    c_jets_AK5PF_et_ = true;
  }
  return jets_AK5PF_et_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_eta() const{
  if(!c_jets_AK5PF_eta_ && b_jets_AK5PF_eta_){
    b_jets_AK5PF_eta_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_eta", &jets_AK5PF_eta_, &b_jets_AK5PF_eta_);
    b_jets_AK5PF_eta_->GetEntry(entry_);
    c_jets_AK5PF_eta_ = true;
  }
  return jets_AK5PF_eta_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_etaetaMoment() const{
  if(!c_jets_AK5PF_etaetaMoment_ && b_jets_AK5PF_etaetaMoment_){
    b_jets_AK5PF_etaetaMoment_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_etaetaMoment", &jets_AK5PF_etaetaMoment_, &b_jets_AK5PF_etaetaMoment_);
    b_jets_AK5PF_etaetaMoment_->GetEntry(entry_);
    c_jets_AK5PF_etaetaMoment_ = true;
  }
  return jets_AK5PF_etaetaMoment_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_etaphiMoment() const{
  if(!c_jets_AK5PF_etaphiMoment_ && b_jets_AK5PF_etaphiMoment_){
    b_jets_AK5PF_etaphiMoment_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_etaphiMoment", &jets_AK5PF_etaphiMoment_, &b_jets_AK5PF_etaphiMoment_);
    b_jets_AK5PF_etaphiMoment_->GetEntry(entry_);
    c_jets_AK5PF_etaphiMoment_ = true;
  }
  return jets_AK5PF_etaphiMoment_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_fHPD() const{
  if(!c_jets_AK5PF_fHPD_ && b_jets_AK5PF_fHPD_){
    b_jets_AK5PF_fHPD_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_fHPD", &jets_AK5PF_fHPD_, &b_jets_AK5PF_fHPD_);
    b_jets_AK5PF_fHPD_->GetEntry(entry_);
    c_jets_AK5PF_fHPD_ = true;
  }
  return jets_AK5PF_fHPD_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_fRBX() const{
  if(!c_jets_AK5PF_fRBX_ && b_jets_AK5PF_fRBX_){
    b_jets_AK5PF_fRBX_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_fRBX", &jets_AK5PF_fRBX_, &b_jets_AK5PF_fRBX_);
    b_jets_AK5PF_fRBX_->GetEntry(entry_);
    c_jets_AK5PF_fRBX_ = true;
  }
  return jets_AK5PF_fRBX_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_fSubDetector1() const{
  if(!c_jets_AK5PF_fSubDetector1_ && b_jets_AK5PF_fSubDetector1_){
    b_jets_AK5PF_fSubDetector1_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_fSubDetector1", &jets_AK5PF_fSubDetector1_, &b_jets_AK5PF_fSubDetector1_);
    b_jets_AK5PF_fSubDetector1_->GetEntry(entry_);
    c_jets_AK5PF_fSubDetector1_ = true;
  }
  return jets_AK5PF_fSubDetector1_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_fSubDetector2() const{
  if(!c_jets_AK5PF_fSubDetector2_ && b_jets_AK5PF_fSubDetector2_){
    b_jets_AK5PF_fSubDetector2_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_fSubDetector2", &jets_AK5PF_fSubDetector2_, &b_jets_AK5PF_fSubDetector2_);
    b_jets_AK5PF_fSubDetector2_->GetEntry(entry_);
    c_jets_AK5PF_fSubDetector2_ = true;
  }
  return jets_AK5PF_fSubDetector2_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_fSubDetector3() const{
  if(!c_jets_AK5PF_fSubDetector3_ && b_jets_AK5PF_fSubDetector3_){
    b_jets_AK5PF_fSubDetector3_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_fSubDetector3", &jets_AK5PF_fSubDetector3_, &b_jets_AK5PF_fSubDetector3_);
    b_jets_AK5PF_fSubDetector3_->GetEntry(entry_);
    c_jets_AK5PF_fSubDetector3_ = true;
  }
  return jets_AK5PF_fSubDetector3_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_fSubDetector4() const{
  if(!c_jets_AK5PF_fSubDetector4_ && b_jets_AK5PF_fSubDetector4_){
    b_jets_AK5PF_fSubDetector4_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_fSubDetector4", &jets_AK5PF_fSubDetector4_, &b_jets_AK5PF_fSubDetector4_);
    b_jets_AK5PF_fSubDetector4_->GetEntry(entry_);
    c_jets_AK5PF_fSubDetector4_ = true;
  }
  return jets_AK5PF_fSubDetector4_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_gen_Energy() const{
  if(!c_jets_AK5PF_gen_Energy_ && b_jets_AK5PF_gen_Energy_){
    b_jets_AK5PF_gen_Energy_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_gen_Energy", &jets_AK5PF_gen_Energy_, &b_jets_AK5PF_gen_Energy_);
    b_jets_AK5PF_gen_Energy_->GetEntry(entry_);
    c_jets_AK5PF_gen_Energy_ = true;
  }
  return jets_AK5PF_gen_Energy_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_gen_Id() const{
  if(!c_jets_AK5PF_gen_Id_ && b_jets_AK5PF_gen_Id_){
    b_jets_AK5PF_gen_Id_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_gen_Id", &jets_AK5PF_gen_Id_, &b_jets_AK5PF_gen_Id_);
    b_jets_AK5PF_gen_Id_->GetEntry(entry_);
    c_jets_AK5PF_gen_Id_ = true;
  }
  return jets_AK5PF_gen_Id_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_gen_et() const{
  if(!c_jets_AK5PF_gen_et_ && b_jets_AK5PF_gen_et_){
    b_jets_AK5PF_gen_et_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_gen_et", &jets_AK5PF_gen_et_, &b_jets_AK5PF_gen_et_);
    b_jets_AK5PF_gen_et_->GetEntry(entry_);
    c_jets_AK5PF_gen_et_ = true;
  }
  return jets_AK5PF_gen_et_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_gen_eta() const{
  if(!c_jets_AK5PF_gen_eta_ && b_jets_AK5PF_gen_eta_){
    b_jets_AK5PF_gen_eta_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_gen_eta", &jets_AK5PF_gen_eta_, &b_jets_AK5PF_gen_eta_);
    b_jets_AK5PF_gen_eta_->GetEntry(entry_);
    c_jets_AK5PF_gen_eta_ = true;
  }
  return jets_AK5PF_gen_eta_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_gen_mass() const{
  if(!c_jets_AK5PF_gen_mass_ && b_jets_AK5PF_gen_mass_){
    b_jets_AK5PF_gen_mass_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_gen_mass", &jets_AK5PF_gen_mass_, &b_jets_AK5PF_gen_mass_);
    b_jets_AK5PF_gen_mass_->GetEntry(entry_);
    c_jets_AK5PF_gen_mass_ = true;
  }
  return jets_AK5PF_gen_mass_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_gen_motherID() const{
  if(!c_jets_AK5PF_gen_motherID_ && b_jets_AK5PF_gen_motherID_){
    b_jets_AK5PF_gen_motherID_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_gen_motherID", &jets_AK5PF_gen_motherID_, &b_jets_AK5PF_gen_motherID_);
    b_jets_AK5PF_gen_motherID_->GetEntry(entry_);
    c_jets_AK5PF_gen_motherID_ = true;
  }
  return jets_AK5PF_gen_motherID_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_gen_phi() const{
  if(!c_jets_AK5PF_gen_phi_ && b_jets_AK5PF_gen_phi_){
    b_jets_AK5PF_gen_phi_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_gen_phi", &jets_AK5PF_gen_phi_, &b_jets_AK5PF_gen_phi_);
    b_jets_AK5PF_gen_phi_->GetEntry(entry_);
    c_jets_AK5PF_gen_phi_ = true;
  }
  return jets_AK5PF_gen_phi_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_gen_pt() const{
  if(!c_jets_AK5PF_gen_pt_ && b_jets_AK5PF_gen_pt_){
    b_jets_AK5PF_gen_pt_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_gen_pt", &jets_AK5PF_gen_pt_, &b_jets_AK5PF_gen_pt_);
    b_jets_AK5PF_gen_pt_->GetEntry(entry_);
    c_jets_AK5PF_gen_pt_ = true;
  }
  return jets_AK5PF_gen_pt_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_gen_threeCharge() const{
  if(!c_jets_AK5PF_gen_threeCharge_ && b_jets_AK5PF_gen_threeCharge_){
    b_jets_AK5PF_gen_threeCharge_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_gen_threeCharge", &jets_AK5PF_gen_threeCharge_, &b_jets_AK5PF_gen_threeCharge_);
    b_jets_AK5PF_gen_threeCharge_->GetEntry(entry_);
    c_jets_AK5PF_gen_threeCharge_ = true;
  }
  return jets_AK5PF_gen_threeCharge_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_hitsInN90() const{
  if(!c_jets_AK5PF_hitsInN90_ && b_jets_AK5PF_hitsInN90_){
    b_jets_AK5PF_hitsInN90_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_hitsInN90", &jets_AK5PF_hitsInN90_, &b_jets_AK5PF_hitsInN90_);
    b_jets_AK5PF_hitsInN90_->GetEntry(entry_);
    c_jets_AK5PF_hitsInN90_ = true;
  }
  return jets_AK5PF_hitsInN90_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_jetCharge() const{
  if(!c_jets_AK5PF_jetCharge_ && b_jets_AK5PF_jetCharge_){
    b_jets_AK5PF_jetCharge_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_jetCharge", &jets_AK5PF_jetCharge_, &b_jets_AK5PF_jetCharge_);
    b_jets_AK5PF_jetCharge_->GetEntry(entry_);
    c_jets_AK5PF_jetCharge_ = true;
  }
  return jets_AK5PF_jetCharge_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_mass() const{
  if(!c_jets_AK5PF_mass_ && b_jets_AK5PF_mass_){
    b_jets_AK5PF_mass_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_mass", &jets_AK5PF_mass_, &b_jets_AK5PF_mass_);
    b_jets_AK5PF_mass_->GetEntry(entry_);
    c_jets_AK5PF_mass_ = true;
  }
  return jets_AK5PF_mass_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_mu_Mult() const{
  if(!c_jets_AK5PF_mu_Mult_ && b_jets_AK5PF_mu_Mult_){
    b_jets_AK5PF_mu_Mult_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_mu_Mult", &jets_AK5PF_mu_Mult_, &b_jets_AK5PF_mu_Mult_);
    b_jets_AK5PF_mu_Mult_->GetEntry(entry_);
    c_jets_AK5PF_mu_Mult_ = true;
  }
  return jets_AK5PF_mu_Mult_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_n60() const{
  if(!c_jets_AK5PF_n60_ && b_jets_AK5PF_n60_){
    b_jets_AK5PF_n60_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_n60", &jets_AK5PF_n60_, &b_jets_AK5PF_n60_);
    b_jets_AK5PF_n60_->GetEntry(entry_);
    c_jets_AK5PF_n60_ = true;
  }
  return jets_AK5PF_n60_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_n90() const{
  if(!c_jets_AK5PF_n90_ && b_jets_AK5PF_n90_){
    b_jets_AK5PF_n90_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_n90", &jets_AK5PF_n90_, &b_jets_AK5PF_n90_);
    b_jets_AK5PF_n90_->GetEntry(entry_);
    c_jets_AK5PF_n90_ = true;
  }
  return jets_AK5PF_n90_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_n90Hits() const{
  if(!c_jets_AK5PF_n90Hits_ && b_jets_AK5PF_n90Hits_){
    b_jets_AK5PF_n90Hits_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_n90Hits", &jets_AK5PF_n90Hits_, &b_jets_AK5PF_n90Hits_);
    b_jets_AK5PF_n90Hits_->GetEntry(entry_);
    c_jets_AK5PF_n90Hits_ = true;
  }
  return jets_AK5PF_n90Hits_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_nECALTowers() const{
  if(!c_jets_AK5PF_nECALTowers_ && b_jets_AK5PF_nECALTowers_){
    b_jets_AK5PF_nECALTowers_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_nECALTowers", &jets_AK5PF_nECALTowers_, &b_jets_AK5PF_nECALTowers_);
    b_jets_AK5PF_nECALTowers_->GetEntry(entry_);
    c_jets_AK5PF_nECALTowers_ = true;
  }
  return jets_AK5PF_nECALTowers_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_nHCALTowers() const{
  if(!c_jets_AK5PF_nHCALTowers_ && b_jets_AK5PF_nHCALTowers_){
    b_jets_AK5PF_nHCALTowers_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_nHCALTowers", &jets_AK5PF_nHCALTowers_, &b_jets_AK5PF_nHCALTowers_);
    b_jets_AK5PF_nHCALTowers_->GetEntry(entry_);
    c_jets_AK5PF_nHCALTowers_ = true;
  }
  return jets_AK5PF_nHCALTowers_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_neutralEmE() const{
  if(!c_jets_AK5PF_neutralEmE_ && b_jets_AK5PF_neutralEmE_){
    b_jets_AK5PF_neutralEmE_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_neutralEmE", &jets_AK5PF_neutralEmE_, &b_jets_AK5PF_neutralEmE_);
    b_jets_AK5PF_neutralEmE_->GetEntry(entry_);
    c_jets_AK5PF_neutralEmE_ = true;
  }
  return jets_AK5PF_neutralEmE_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_neutralHadE() const{
  if(!c_jets_AK5PF_neutralHadE_ && b_jets_AK5PF_neutralHadE_){
    b_jets_AK5PF_neutralHadE_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_neutralHadE", &jets_AK5PF_neutralHadE_, &b_jets_AK5PF_neutralHadE_);
    b_jets_AK5PF_neutralHadE_->GetEntry(entry_);
    c_jets_AK5PF_neutralHadE_ = true;
  }
  return jets_AK5PF_neutralHadE_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_neutral_Mult() const{
  if(!c_jets_AK5PF_neutral_Mult_ && b_jets_AK5PF_neutral_Mult_){
    b_jets_AK5PF_neutral_Mult_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_neutral_Mult", &jets_AK5PF_neutral_Mult_, &b_jets_AK5PF_neutral_Mult_);
    b_jets_AK5PF_neutral_Mult_->GetEntry(entry_);
    c_jets_AK5PF_neutral_Mult_ = true;
  }
  return jets_AK5PF_neutral_Mult_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_partonFlavour() const{
  if(!c_jets_AK5PF_partonFlavour_ && b_jets_AK5PF_partonFlavour_){
    b_jets_AK5PF_partonFlavour_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_partonFlavour", &jets_AK5PF_partonFlavour_, &b_jets_AK5PF_partonFlavour_);
    b_jets_AK5PF_partonFlavour_->GetEntry(entry_);
    c_jets_AK5PF_partonFlavour_ = true;
  }
  return jets_AK5PF_partonFlavour_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_parton_Energy() const{
  if(!c_jets_AK5PF_parton_Energy_ && b_jets_AK5PF_parton_Energy_){
    b_jets_AK5PF_parton_Energy_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_parton_Energy", &jets_AK5PF_parton_Energy_, &b_jets_AK5PF_parton_Energy_);
    b_jets_AK5PF_parton_Energy_->GetEntry(entry_);
    c_jets_AK5PF_parton_Energy_ = true;
  }
  return jets_AK5PF_parton_Energy_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_parton_Id() const{
  if(!c_jets_AK5PF_parton_Id_ && b_jets_AK5PF_parton_Id_){
    b_jets_AK5PF_parton_Id_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_parton_Id", &jets_AK5PF_parton_Id_, &b_jets_AK5PF_parton_Id_);
    b_jets_AK5PF_parton_Id_->GetEntry(entry_);
    c_jets_AK5PF_parton_Id_ = true;
  }
  return jets_AK5PF_parton_Id_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_parton_eta() const{
  if(!c_jets_AK5PF_parton_eta_ && b_jets_AK5PF_parton_eta_){
    b_jets_AK5PF_parton_eta_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_parton_eta", &jets_AK5PF_parton_eta_, &b_jets_AK5PF_parton_eta_);
    b_jets_AK5PF_parton_eta_->GetEntry(entry_);
    c_jets_AK5PF_parton_eta_ = true;
  }
  return jets_AK5PF_parton_eta_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_parton_mass() const{
  if(!c_jets_AK5PF_parton_mass_ && b_jets_AK5PF_parton_mass_){
    b_jets_AK5PF_parton_mass_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_parton_mass", &jets_AK5PF_parton_mass_, &b_jets_AK5PF_parton_mass_);
    b_jets_AK5PF_parton_mass_->GetEntry(entry_);
    c_jets_AK5PF_parton_mass_ = true;
  }
  return jets_AK5PF_parton_mass_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_parton_motherId() const{
  if(!c_jets_AK5PF_parton_motherId_ && b_jets_AK5PF_parton_motherId_){
    b_jets_AK5PF_parton_motherId_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_parton_motherId", &jets_AK5PF_parton_motherId_, &b_jets_AK5PF_parton_motherId_);
    b_jets_AK5PF_parton_motherId_->GetEntry(entry_);
    c_jets_AK5PF_parton_motherId_ = true;
  }
  return jets_AK5PF_parton_motherId_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_parton_phi() const{
  if(!c_jets_AK5PF_parton_phi_ && b_jets_AK5PF_parton_phi_){
    b_jets_AK5PF_parton_phi_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_parton_phi", &jets_AK5PF_parton_phi_, &b_jets_AK5PF_parton_phi_);
    b_jets_AK5PF_parton_phi_->GetEntry(entry_);
    c_jets_AK5PF_parton_phi_ = true;
  }
  return jets_AK5PF_parton_phi_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_parton_pt() const{
  if(!c_jets_AK5PF_parton_pt_ && b_jets_AK5PF_parton_pt_){
    b_jets_AK5PF_parton_pt_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_parton_pt", &jets_AK5PF_parton_pt_, &b_jets_AK5PF_parton_pt_);
    b_jets_AK5PF_parton_pt_->GetEntry(entry_);
    c_jets_AK5PF_parton_pt_ = true;
  }
  return jets_AK5PF_parton_pt_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_phi() const{
  if(!c_jets_AK5PF_phi_ && b_jets_AK5PF_phi_){
    b_jets_AK5PF_phi_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_phi", &jets_AK5PF_phi_, &b_jets_AK5PF_phi_);
    b_jets_AK5PF_phi_->GetEntry(entry_);
    c_jets_AK5PF_phi_ = true;
  }
  return jets_AK5PF_phi_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_phiphiMoment() const{
  if(!c_jets_AK5PF_phiphiMoment_ && b_jets_AK5PF_phiphiMoment_){
    b_jets_AK5PF_phiphiMoment_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_phiphiMoment", &jets_AK5PF_phiphiMoment_, &b_jets_AK5PF_phiphiMoment_);
    b_jets_AK5PF_phiphiMoment_->GetEntry(entry_);
    c_jets_AK5PF_phiphiMoment_ = true;
  }
  return jets_AK5PF_phiphiMoment_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_photonEnergy() const{
  if(!c_jets_AK5PF_photonEnergy_ && b_jets_AK5PF_photonEnergy_){
    b_jets_AK5PF_photonEnergy_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_photonEnergy", &jets_AK5PF_photonEnergy_, &b_jets_AK5PF_photonEnergy_);
    b_jets_AK5PF_photonEnergy_->GetEntry(entry_);
    c_jets_AK5PF_photonEnergy_ = true;
  }
  return jets_AK5PF_photonEnergy_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_pt() const{
  if(!c_jets_AK5PF_pt_ && b_jets_AK5PF_pt_){
    b_jets_AK5PF_pt_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_pt", &jets_AK5PF_pt_, &b_jets_AK5PF_pt_);
    b_jets_AK5PF_pt_->GetEntry(entry_);
    c_jets_AK5PF_pt_ = true;
  }
  return jets_AK5PF_pt_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_px() const{
  if(!c_jets_AK5PF_px_ && b_jets_AK5PF_px_){
    b_jets_AK5PF_px_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_px", &jets_AK5PF_px_, &b_jets_AK5PF_px_);
    b_jets_AK5PF_px_->GetEntry(entry_);
    c_jets_AK5PF_px_ = true;
  }
  return jets_AK5PF_px_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_py() const{
  if(!c_jets_AK5PF_py_ && b_jets_AK5PF_py_){
    b_jets_AK5PF_py_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_py", &jets_AK5PF_py_, &b_jets_AK5PF_py_);
    b_jets_AK5PF_py_->GetEntry(entry_);
    c_jets_AK5PF_py_ = true;
  }
  return jets_AK5PF_py_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_pz() const{
  if(!c_jets_AK5PF_pz_ && b_jets_AK5PF_pz_){
    b_jets_AK5PF_pz_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_pz", &jets_AK5PF_pz_, &b_jets_AK5PF_pz_);
    b_jets_AK5PF_pz_->GetEntry(entry_);
    c_jets_AK5PF_pz_ = true;
  }
  return jets_AK5PF_pz_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_rawPt() const{
  if(!c_jets_AK5PF_rawPt_ && b_jets_AK5PF_rawPt_){
    b_jets_AK5PF_rawPt_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_rawPt", &jets_AK5PF_rawPt_, &b_jets_AK5PF_rawPt_);
    b_jets_AK5PF_rawPt_->GetEntry(entry_);
    c_jets_AK5PF_rawPt_ = true;
  }
  return jets_AK5PF_rawPt_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_status() const{
  if(!c_jets_AK5PF_status_ && b_jets_AK5PF_status_){
    b_jets_AK5PF_status_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_status", &jets_AK5PF_status_, &b_jets_AK5PF_status_);
    b_jets_AK5PF_status_->GetEntry(entry_);
    c_jets_AK5PF_status_ = true;
  }
  return jets_AK5PF_status_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_theta() const{
  if(!c_jets_AK5PF_theta_ && b_jets_AK5PF_theta_){
    b_jets_AK5PF_theta_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PF_theta", &jets_AK5PF_theta_, &b_jets_AK5PF_theta_);
    b_jets_AK5PF_theta_->GetEntry(entry_);
    c_jets_AK5PF_theta_ = true;
  }
  return jets_AK5PF_theta_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_Uncert() const{
  if(!c_jets_AK5PFclean_Uncert_ && b_jets_AK5PFclean_Uncert_){
    b_jets_AK5PFclean_Uncert_->SetStatus(true);
    chainA_.SetBranchAddress("jets_AK5PFclean_Uncert", &jets_AK5PFclean_Uncert_, &b_jets_AK5PFclean_Uncert_);
    b_jets_AK5PFclean_Uncert_->GetEntry(entry_);
    c_jets_AK5PFclean_Uncert_ = true;
  }
  return jets_AK5PFclean_Uncert_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_area() const{
  if(!c_jets_AK5PFclean_area_ && b_jets_AK5PFclean_area_){
    b_jets_AK5PFclean_area_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_area", &jets_AK5PFclean_area_, &b_jets_AK5PFclean_area_);
    b_jets_AK5PFclean_area_->GetEntry(entry_);
    c_jets_AK5PFclean_area_ = true;
  }
  return jets_AK5PFclean_area_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_btag_TC_highEff() const{
  if(!c_jets_AK5PFclean_btag_TC_highEff_ && b_jets_AK5PFclean_btag_TC_highEff_){
    b_jets_AK5PFclean_btag_TC_highEff_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_btag_TC_highEff", &jets_AK5PFclean_btag_TC_highEff_, &b_jets_AK5PFclean_btag_TC_highEff_);
    b_jets_AK5PFclean_btag_TC_highEff_->GetEntry(entry_);
    c_jets_AK5PFclean_btag_TC_highEff_ = true;
  }
  return jets_AK5PFclean_btag_TC_highEff_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_btag_TC_highPur() const{
  if(!c_jets_AK5PFclean_btag_TC_highPur_ && b_jets_AK5PFclean_btag_TC_highPur_){
    b_jets_AK5PFclean_btag_TC_highPur_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_btag_TC_highPur", &jets_AK5PFclean_btag_TC_highPur_, &b_jets_AK5PFclean_btag_TC_highPur_);
    b_jets_AK5PFclean_btag_TC_highPur_->GetEntry(entry_);
    c_jets_AK5PFclean_btag_TC_highPur_ = true;
  }
  return jets_AK5PFclean_btag_TC_highPur_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_btag_jetBProb() const{
  if(!c_jets_AK5PFclean_btag_jetBProb_ && b_jets_AK5PFclean_btag_jetBProb_){
    b_jets_AK5PFclean_btag_jetBProb_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_btag_jetBProb", &jets_AK5PFclean_btag_jetBProb_, &b_jets_AK5PFclean_btag_jetBProb_);
    b_jets_AK5PFclean_btag_jetBProb_->GetEntry(entry_);
    c_jets_AK5PFclean_btag_jetBProb_ = true;
  }
  return jets_AK5PFclean_btag_jetBProb_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_btag_jetProb() const{
  if(!c_jets_AK5PFclean_btag_jetProb_ && b_jets_AK5PFclean_btag_jetProb_){
    b_jets_AK5PFclean_btag_jetProb_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_btag_jetProb", &jets_AK5PFclean_btag_jetProb_, &b_jets_AK5PFclean_btag_jetProb_);
    b_jets_AK5PFclean_btag_jetProb_->GetEntry(entry_);
    c_jets_AK5PFclean_btag_jetProb_ = true;
  }
  return jets_AK5PFclean_btag_jetProb_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_btag_secVertexCombined() const{
  if(!c_jets_AK5PFclean_btag_secVertexCombined_ && b_jets_AK5PFclean_btag_secVertexCombined_){
    b_jets_AK5PFclean_btag_secVertexCombined_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_btag_secVertexCombined", &jets_AK5PFclean_btag_secVertexCombined_, &b_jets_AK5PFclean_btag_secVertexCombined_);
    b_jets_AK5PFclean_btag_secVertexCombined_->GetEntry(entry_);
    c_jets_AK5PFclean_btag_secVertexCombined_ = true;
  }
  return jets_AK5PFclean_btag_secVertexCombined_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_btag_secVertexHighEff() const{
  if(!c_jets_AK5PFclean_btag_secVertexHighEff_ && b_jets_AK5PFclean_btag_secVertexHighEff_){
    b_jets_AK5PFclean_btag_secVertexHighEff_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_btag_secVertexHighEff", &jets_AK5PFclean_btag_secVertexHighEff_, &b_jets_AK5PFclean_btag_secVertexHighEff_);
    b_jets_AK5PFclean_btag_secVertexHighEff_->GetEntry(entry_);
    c_jets_AK5PFclean_btag_secVertexHighEff_ = true;
  }
  return jets_AK5PFclean_btag_secVertexHighEff_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_btag_secVertexHighPur() const{
  if(!c_jets_AK5PFclean_btag_secVertexHighPur_ && b_jets_AK5PFclean_btag_secVertexHighPur_){
    b_jets_AK5PFclean_btag_secVertexHighPur_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_btag_secVertexHighPur", &jets_AK5PFclean_btag_secVertexHighPur_, &b_jets_AK5PFclean_btag_secVertexHighPur_);
    b_jets_AK5PFclean_btag_secVertexHighPur_->GetEntry(entry_);
    c_jets_AK5PFclean_btag_secVertexHighPur_ = true;
  }
  return jets_AK5PFclean_btag_secVertexHighPur_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_btag_softEle() const{
  if(!c_jets_AK5PFclean_btag_softEle_ && b_jets_AK5PFclean_btag_softEle_){
    b_jets_AK5PFclean_btag_softEle_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_btag_softEle", &jets_AK5PFclean_btag_softEle_, &b_jets_AK5PFclean_btag_softEle_);
    b_jets_AK5PFclean_btag_softEle_->GetEntry(entry_);
    c_jets_AK5PFclean_btag_softEle_ = true;
  }
  return jets_AK5PFclean_btag_softEle_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_btag_softMuon() const{
  if(!c_jets_AK5PFclean_btag_softMuon_ && b_jets_AK5PFclean_btag_softMuon_){
    b_jets_AK5PFclean_btag_softMuon_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_btag_softMuon", &jets_AK5PFclean_btag_softMuon_, &b_jets_AK5PFclean_btag_softMuon_);
    b_jets_AK5PFclean_btag_softMuon_->GetEntry(entry_);
    c_jets_AK5PFclean_btag_softMuon_ = true;
  }
  return jets_AK5PFclean_btag_softMuon_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_chgEmE() const{
  if(!c_jets_AK5PFclean_chgEmE_ && b_jets_AK5PFclean_chgEmE_){
    b_jets_AK5PFclean_chgEmE_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_chgEmE", &jets_AK5PFclean_chgEmE_, &b_jets_AK5PFclean_chgEmE_);
    b_jets_AK5PFclean_chgEmE_->GetEntry(entry_);
    c_jets_AK5PFclean_chgEmE_ = true;
  }
  return jets_AK5PFclean_chgEmE_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_chgHadE() const{
  if(!c_jets_AK5PFclean_chgHadE_ && b_jets_AK5PFclean_chgHadE_){
    b_jets_AK5PFclean_chgHadE_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_chgHadE", &jets_AK5PFclean_chgHadE_, &b_jets_AK5PFclean_chgHadE_);
    b_jets_AK5PFclean_chgHadE_->GetEntry(entry_);
    c_jets_AK5PFclean_chgHadE_ = true;
  }
  return jets_AK5PFclean_chgHadE_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_chgMuE() const{
  if(!c_jets_AK5PFclean_chgMuE_ && b_jets_AK5PFclean_chgMuE_){
    b_jets_AK5PFclean_chgMuE_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_chgMuE", &jets_AK5PFclean_chgMuE_, &b_jets_AK5PFclean_chgMuE_);
    b_jets_AK5PFclean_chgMuE_->GetEntry(entry_);
    c_jets_AK5PFclean_chgMuE_ = true;
  }
  return jets_AK5PFclean_chgMuE_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_chg_Mult() const{
  if(!c_jets_AK5PFclean_chg_Mult_ && b_jets_AK5PFclean_chg_Mult_){
    b_jets_AK5PFclean_chg_Mult_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_chg_Mult", &jets_AK5PFclean_chg_Mult_, &b_jets_AK5PFclean_chg_Mult_);
    b_jets_AK5PFclean_chg_Mult_->GetEntry(entry_);
    c_jets_AK5PFclean_chg_Mult_ = true;
  }
  return jets_AK5PFclean_chg_Mult_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_corrFactorRaw() const{
  if(!c_jets_AK5PFclean_corrFactorRaw_ && b_jets_AK5PFclean_corrFactorRaw_){
    b_jets_AK5PFclean_corrFactorRaw_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_corrFactorRaw", &jets_AK5PFclean_corrFactorRaw_, &b_jets_AK5PFclean_corrFactorRaw_);
    b_jets_AK5PFclean_corrFactorRaw_->GetEntry(entry_);
    c_jets_AK5PFclean_corrFactorRaw_ = true;
  }
  return jets_AK5PFclean_corrFactorRaw_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_corrL1FastL2L3() const{
  if(!c_jets_AK5PFclean_corrL1FastL2L3_ && b_jets_AK5PFclean_corrL1FastL2L3_){
    b_jets_AK5PFclean_corrL1FastL2L3_->SetStatus(true);
    chainA_.SetBranchAddress("jets_AK5PFclean_corrL1FastL2L3", &jets_AK5PFclean_corrL1FastL2L3_, &b_jets_AK5PFclean_corrL1FastL2L3_);
    b_jets_AK5PFclean_corrL1FastL2L3_->GetEntry(entry_);
    c_jets_AK5PFclean_corrL1FastL2L3_ = true;
  }
  return jets_AK5PFclean_corrL1FastL2L3_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_corrL1FastL2L3Residual() const{
  if(!c_jets_AK5PFclean_corrL1FastL2L3Residual_ && b_jets_AK5PFclean_corrL1FastL2L3Residual_){
    b_jets_AK5PFclean_corrL1FastL2L3Residual_->SetStatus(true);
    chainA_.SetBranchAddress("jets_AK5PFclean_corrL1FastL2L3Residual", &jets_AK5PFclean_corrL1FastL2L3Residual_, &b_jets_AK5PFclean_corrL1FastL2L3Residual_);
    b_jets_AK5PFclean_corrL1FastL2L3Residual_->GetEntry(entry_);
    c_jets_AK5PFclean_corrL1FastL2L3Residual_ = true;
  }
  return jets_AK5PFclean_corrL1FastL2L3Residual_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_corrL1L2L3() const{
  if(!c_jets_AK5PFclean_corrL1L2L3_ && b_jets_AK5PFclean_corrL1L2L3_){
    b_jets_AK5PFclean_corrL1L2L3_->SetStatus(true);
    chainA_.SetBranchAddress("jets_AK5PFclean_corrL1L2L3", &jets_AK5PFclean_corrL1L2L3_, &b_jets_AK5PFclean_corrL1L2L3_);
    b_jets_AK5PFclean_corrL1L2L3_->GetEntry(entry_);
    c_jets_AK5PFclean_corrL1L2L3_ = true;
  }
  return jets_AK5PFclean_corrL1L2L3_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_corrL1L2L3Residual() const{
  if(!c_jets_AK5PFclean_corrL1L2L3Residual_ && b_jets_AK5PFclean_corrL1L2L3Residual_){
    b_jets_AK5PFclean_corrL1L2L3Residual_->SetStatus(true);
    chainA_.SetBranchAddress("jets_AK5PFclean_corrL1L2L3Residual", &jets_AK5PFclean_corrL1L2L3Residual_, &b_jets_AK5PFclean_corrL1L2L3Residual_);
    b_jets_AK5PFclean_corrL1L2L3Residual_->GetEntry(entry_);
    c_jets_AK5PFclean_corrL1L2L3Residual_ = true;
  }
  return jets_AK5PFclean_corrL1L2L3Residual_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_corrL2L3() const{
  if(!c_jets_AK5PFclean_corrL2L3_ && b_jets_AK5PFclean_corrL2L3_){
    b_jets_AK5PFclean_corrL2L3_->SetStatus(true);
    chainA_.SetBranchAddress("jets_AK5PFclean_corrL2L3", &jets_AK5PFclean_corrL2L3_, &b_jets_AK5PFclean_corrL2L3_);
    b_jets_AK5PFclean_corrL2L3_->GetEntry(entry_);
    c_jets_AK5PFclean_corrL2L3_ = true;
  }
  return jets_AK5PFclean_corrL2L3_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_corrL2L3Residual() const{
  if(!c_jets_AK5PFclean_corrL2L3Residual_ && b_jets_AK5PFclean_corrL2L3Residual_){
    b_jets_AK5PFclean_corrL2L3Residual_->SetStatus(true);
    chainA_.SetBranchAddress("jets_AK5PFclean_corrL2L3Residual", &jets_AK5PFclean_corrL2L3Residual_, &b_jets_AK5PFclean_corrL2L3Residual_);
    b_jets_AK5PFclean_corrL2L3Residual_->GetEntry(entry_);
    c_jets_AK5PFclean_corrL2L3Residual_ = true;
  }
  return jets_AK5PFclean_corrL2L3Residual_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_ehf() const{
  if(!c_jets_AK5PFclean_ehf_ && b_jets_AK5PFclean_ehf_){
    b_jets_AK5PFclean_ehf_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_ehf", &jets_AK5PFclean_ehf_, &b_jets_AK5PFclean_ehf_);
    b_jets_AK5PFclean_ehf_->GetEntry(entry_);
    c_jets_AK5PFclean_ehf_ = true;
  }
  return jets_AK5PFclean_ehf_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_emf() const{
  if(!c_jets_AK5PFclean_emf_ && b_jets_AK5PFclean_emf_){
    b_jets_AK5PFclean_emf_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_emf", &jets_AK5PFclean_emf_, &b_jets_AK5PFclean_emf_);
    b_jets_AK5PFclean_emf_->GetEntry(entry_);
    c_jets_AK5PFclean_emf_ = true;
  }
  return jets_AK5PFclean_emf_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_energy() const{
  if(!c_jets_AK5PFclean_energy_ && b_jets_AK5PFclean_energy_){
    b_jets_AK5PFclean_energy_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_energy", &jets_AK5PFclean_energy_, &b_jets_AK5PFclean_energy_);
    b_jets_AK5PFclean_energy_->GetEntry(entry_);
    c_jets_AK5PFclean_energy_ = true;
  }
  return jets_AK5PFclean_energy_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_et() const{
  if(!c_jets_AK5PFclean_et_ && b_jets_AK5PFclean_et_){
    b_jets_AK5PFclean_et_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_et", &jets_AK5PFclean_et_, &b_jets_AK5PFclean_et_);
    b_jets_AK5PFclean_et_->GetEntry(entry_);
    c_jets_AK5PFclean_et_ = true;
  }
  return jets_AK5PFclean_et_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_eta() const{
  if(!c_jets_AK5PFclean_eta_ && b_jets_AK5PFclean_eta_){
    b_jets_AK5PFclean_eta_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_eta", &jets_AK5PFclean_eta_, &b_jets_AK5PFclean_eta_);
    b_jets_AK5PFclean_eta_->GetEntry(entry_);
    c_jets_AK5PFclean_eta_ = true;
  }
  return jets_AK5PFclean_eta_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_etaetaMoment() const{
  if(!c_jets_AK5PFclean_etaetaMoment_ && b_jets_AK5PFclean_etaetaMoment_){
    b_jets_AK5PFclean_etaetaMoment_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_etaetaMoment", &jets_AK5PFclean_etaetaMoment_, &b_jets_AK5PFclean_etaetaMoment_);
    b_jets_AK5PFclean_etaetaMoment_->GetEntry(entry_);
    c_jets_AK5PFclean_etaetaMoment_ = true;
  }
  return jets_AK5PFclean_etaetaMoment_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_etaphiMoment() const{
  if(!c_jets_AK5PFclean_etaphiMoment_ && b_jets_AK5PFclean_etaphiMoment_){
    b_jets_AK5PFclean_etaphiMoment_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_etaphiMoment", &jets_AK5PFclean_etaphiMoment_, &b_jets_AK5PFclean_etaphiMoment_);
    b_jets_AK5PFclean_etaphiMoment_->GetEntry(entry_);
    c_jets_AK5PFclean_etaphiMoment_ = true;
  }
  return jets_AK5PFclean_etaphiMoment_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_fHPD() const{
  if(!c_jets_AK5PFclean_fHPD_ && b_jets_AK5PFclean_fHPD_){
    b_jets_AK5PFclean_fHPD_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_fHPD", &jets_AK5PFclean_fHPD_, &b_jets_AK5PFclean_fHPD_);
    b_jets_AK5PFclean_fHPD_->GetEntry(entry_);
    c_jets_AK5PFclean_fHPD_ = true;
  }
  return jets_AK5PFclean_fHPD_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_fRBX() const{
  if(!c_jets_AK5PFclean_fRBX_ && b_jets_AK5PFclean_fRBX_){
    b_jets_AK5PFclean_fRBX_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_fRBX", &jets_AK5PFclean_fRBX_, &b_jets_AK5PFclean_fRBX_);
    b_jets_AK5PFclean_fRBX_->GetEntry(entry_);
    c_jets_AK5PFclean_fRBX_ = true;
  }
  return jets_AK5PFclean_fRBX_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_fSubDetector1() const{
  if(!c_jets_AK5PFclean_fSubDetector1_ && b_jets_AK5PFclean_fSubDetector1_){
    b_jets_AK5PFclean_fSubDetector1_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_fSubDetector1", &jets_AK5PFclean_fSubDetector1_, &b_jets_AK5PFclean_fSubDetector1_);
    b_jets_AK5PFclean_fSubDetector1_->GetEntry(entry_);
    c_jets_AK5PFclean_fSubDetector1_ = true;
  }
  return jets_AK5PFclean_fSubDetector1_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_fSubDetector2() const{
  if(!c_jets_AK5PFclean_fSubDetector2_ && b_jets_AK5PFclean_fSubDetector2_){
    b_jets_AK5PFclean_fSubDetector2_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_fSubDetector2", &jets_AK5PFclean_fSubDetector2_, &b_jets_AK5PFclean_fSubDetector2_);
    b_jets_AK5PFclean_fSubDetector2_->GetEntry(entry_);
    c_jets_AK5PFclean_fSubDetector2_ = true;
  }
  return jets_AK5PFclean_fSubDetector2_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_fSubDetector3() const{
  if(!c_jets_AK5PFclean_fSubDetector3_ && b_jets_AK5PFclean_fSubDetector3_){
    b_jets_AK5PFclean_fSubDetector3_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_fSubDetector3", &jets_AK5PFclean_fSubDetector3_, &b_jets_AK5PFclean_fSubDetector3_);
    b_jets_AK5PFclean_fSubDetector3_->GetEntry(entry_);
    c_jets_AK5PFclean_fSubDetector3_ = true;
  }
  return jets_AK5PFclean_fSubDetector3_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_fSubDetector4() const{
  if(!c_jets_AK5PFclean_fSubDetector4_ && b_jets_AK5PFclean_fSubDetector4_){
    b_jets_AK5PFclean_fSubDetector4_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_fSubDetector4", &jets_AK5PFclean_fSubDetector4_, &b_jets_AK5PFclean_fSubDetector4_);
    b_jets_AK5PFclean_fSubDetector4_->GetEntry(entry_);
    c_jets_AK5PFclean_fSubDetector4_ = true;
  }
  return jets_AK5PFclean_fSubDetector4_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_gen_Energy() const{
  if(!c_jets_AK5PFclean_gen_Energy_ && b_jets_AK5PFclean_gen_Energy_){
    b_jets_AK5PFclean_gen_Energy_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_gen_Energy", &jets_AK5PFclean_gen_Energy_, &b_jets_AK5PFclean_gen_Energy_);
    b_jets_AK5PFclean_gen_Energy_->GetEntry(entry_);
    c_jets_AK5PFclean_gen_Energy_ = true;
  }
  return jets_AK5PFclean_gen_Energy_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_gen_Id() const{
  if(!c_jets_AK5PFclean_gen_Id_ && b_jets_AK5PFclean_gen_Id_){
    b_jets_AK5PFclean_gen_Id_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_gen_Id", &jets_AK5PFclean_gen_Id_, &b_jets_AK5PFclean_gen_Id_);
    b_jets_AK5PFclean_gen_Id_->GetEntry(entry_);
    c_jets_AK5PFclean_gen_Id_ = true;
  }
  return jets_AK5PFclean_gen_Id_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_gen_et() const{
  if(!c_jets_AK5PFclean_gen_et_ && b_jets_AK5PFclean_gen_et_){
    b_jets_AK5PFclean_gen_et_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_gen_et", &jets_AK5PFclean_gen_et_, &b_jets_AK5PFclean_gen_et_);
    b_jets_AK5PFclean_gen_et_->GetEntry(entry_);
    c_jets_AK5PFclean_gen_et_ = true;
  }
  return jets_AK5PFclean_gen_et_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_gen_eta() const{
  if(!c_jets_AK5PFclean_gen_eta_ && b_jets_AK5PFclean_gen_eta_){
    b_jets_AK5PFclean_gen_eta_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_gen_eta", &jets_AK5PFclean_gen_eta_, &b_jets_AK5PFclean_gen_eta_);
    b_jets_AK5PFclean_gen_eta_->GetEntry(entry_);
    c_jets_AK5PFclean_gen_eta_ = true;
  }
  return jets_AK5PFclean_gen_eta_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_gen_mass() const{
  if(!c_jets_AK5PFclean_gen_mass_ && b_jets_AK5PFclean_gen_mass_){
    b_jets_AK5PFclean_gen_mass_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_gen_mass", &jets_AK5PFclean_gen_mass_, &b_jets_AK5PFclean_gen_mass_);
    b_jets_AK5PFclean_gen_mass_->GetEntry(entry_);
    c_jets_AK5PFclean_gen_mass_ = true;
  }
  return jets_AK5PFclean_gen_mass_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_gen_phi() const{
  if(!c_jets_AK5PFclean_gen_phi_ && b_jets_AK5PFclean_gen_phi_){
    b_jets_AK5PFclean_gen_phi_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_gen_phi", &jets_AK5PFclean_gen_phi_, &b_jets_AK5PFclean_gen_phi_);
    b_jets_AK5PFclean_gen_phi_->GetEntry(entry_);
    c_jets_AK5PFclean_gen_phi_ = true;
  }
  return jets_AK5PFclean_gen_phi_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_gen_pt() const{
  if(!c_jets_AK5PFclean_gen_pt_ && b_jets_AK5PFclean_gen_pt_){
    b_jets_AK5PFclean_gen_pt_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_gen_pt", &jets_AK5PFclean_gen_pt_, &b_jets_AK5PFclean_gen_pt_);
    b_jets_AK5PFclean_gen_pt_->GetEntry(entry_);
    c_jets_AK5PFclean_gen_pt_ = true;
  }
  return jets_AK5PFclean_gen_pt_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_hitsInN90() const{
  if(!c_jets_AK5PFclean_hitsInN90_ && b_jets_AK5PFclean_hitsInN90_){
    b_jets_AK5PFclean_hitsInN90_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_hitsInN90", &jets_AK5PFclean_hitsInN90_, &b_jets_AK5PFclean_hitsInN90_);
    b_jets_AK5PFclean_hitsInN90_->GetEntry(entry_);
    c_jets_AK5PFclean_hitsInN90_ = true;
  }
  return jets_AK5PFclean_hitsInN90_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_jetCharge() const{
  if(!c_jets_AK5PFclean_jetCharge_ && b_jets_AK5PFclean_jetCharge_){
    b_jets_AK5PFclean_jetCharge_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_jetCharge", &jets_AK5PFclean_jetCharge_, &b_jets_AK5PFclean_jetCharge_);
    b_jets_AK5PFclean_jetCharge_->GetEntry(entry_);
    c_jets_AK5PFclean_jetCharge_ = true;
  }
  return jets_AK5PFclean_jetCharge_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_mass() const{
  if(!c_jets_AK5PFclean_mass_ && b_jets_AK5PFclean_mass_){
    b_jets_AK5PFclean_mass_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_mass", &jets_AK5PFclean_mass_, &b_jets_AK5PFclean_mass_);
    b_jets_AK5PFclean_mass_->GetEntry(entry_);
    c_jets_AK5PFclean_mass_ = true;
  }
  return jets_AK5PFclean_mass_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_mu_Mult() const{
  if(!c_jets_AK5PFclean_mu_Mult_ && b_jets_AK5PFclean_mu_Mult_){
    b_jets_AK5PFclean_mu_Mult_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_mu_Mult", &jets_AK5PFclean_mu_Mult_, &b_jets_AK5PFclean_mu_Mult_);
    b_jets_AK5PFclean_mu_Mult_->GetEntry(entry_);
    c_jets_AK5PFclean_mu_Mult_ = true;
  }
  return jets_AK5PFclean_mu_Mult_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_n60() const{
  if(!c_jets_AK5PFclean_n60_ && b_jets_AK5PFclean_n60_){
    b_jets_AK5PFclean_n60_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_n60", &jets_AK5PFclean_n60_, &b_jets_AK5PFclean_n60_);
    b_jets_AK5PFclean_n60_->GetEntry(entry_);
    c_jets_AK5PFclean_n60_ = true;
  }
  return jets_AK5PFclean_n60_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_n90() const{
  if(!c_jets_AK5PFclean_n90_ && b_jets_AK5PFclean_n90_){
    b_jets_AK5PFclean_n90_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_n90", &jets_AK5PFclean_n90_, &b_jets_AK5PFclean_n90_);
    b_jets_AK5PFclean_n90_->GetEntry(entry_);
    c_jets_AK5PFclean_n90_ = true;
  }
  return jets_AK5PFclean_n90_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_n90Hits() const{
  if(!c_jets_AK5PFclean_n90Hits_ && b_jets_AK5PFclean_n90Hits_){
    b_jets_AK5PFclean_n90Hits_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_n90Hits", &jets_AK5PFclean_n90Hits_, &b_jets_AK5PFclean_n90Hits_);
    b_jets_AK5PFclean_n90Hits_->GetEntry(entry_);
    c_jets_AK5PFclean_n90Hits_ = true;
  }
  return jets_AK5PFclean_n90Hits_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_nECALTowers() const{
  if(!c_jets_AK5PFclean_nECALTowers_ && b_jets_AK5PFclean_nECALTowers_){
    b_jets_AK5PFclean_nECALTowers_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_nECALTowers", &jets_AK5PFclean_nECALTowers_, &b_jets_AK5PFclean_nECALTowers_);
    b_jets_AK5PFclean_nECALTowers_->GetEntry(entry_);
    c_jets_AK5PFclean_nECALTowers_ = true;
  }
  return jets_AK5PFclean_nECALTowers_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_nHCALTowers() const{
  if(!c_jets_AK5PFclean_nHCALTowers_ && b_jets_AK5PFclean_nHCALTowers_){
    b_jets_AK5PFclean_nHCALTowers_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_nHCALTowers", &jets_AK5PFclean_nHCALTowers_, &b_jets_AK5PFclean_nHCALTowers_);
    b_jets_AK5PFclean_nHCALTowers_->GetEntry(entry_);
    c_jets_AK5PFclean_nHCALTowers_ = true;
  }
  return jets_AK5PFclean_nHCALTowers_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_neutralEmE() const{
  if(!c_jets_AK5PFclean_neutralEmE_ && b_jets_AK5PFclean_neutralEmE_){
    b_jets_AK5PFclean_neutralEmE_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_neutralEmE", &jets_AK5PFclean_neutralEmE_, &b_jets_AK5PFclean_neutralEmE_);
    b_jets_AK5PFclean_neutralEmE_->GetEntry(entry_);
    c_jets_AK5PFclean_neutralEmE_ = true;
  }
  return jets_AK5PFclean_neutralEmE_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_neutralHadE() const{
  if(!c_jets_AK5PFclean_neutralHadE_ && b_jets_AK5PFclean_neutralHadE_){
    b_jets_AK5PFclean_neutralHadE_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_neutralHadE", &jets_AK5PFclean_neutralHadE_, &b_jets_AK5PFclean_neutralHadE_);
    b_jets_AK5PFclean_neutralHadE_->GetEntry(entry_);
    c_jets_AK5PFclean_neutralHadE_ = true;
  }
  return jets_AK5PFclean_neutralHadE_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_neutral_Mult() const{
  if(!c_jets_AK5PFclean_neutral_Mult_ && b_jets_AK5PFclean_neutral_Mult_){
    b_jets_AK5PFclean_neutral_Mult_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_neutral_Mult", &jets_AK5PFclean_neutral_Mult_, &b_jets_AK5PFclean_neutral_Mult_);
    b_jets_AK5PFclean_neutral_Mult_->GetEntry(entry_);
    c_jets_AK5PFclean_neutral_Mult_ = true;
  }
  return jets_AK5PFclean_neutral_Mult_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_partonFlavour() const{
  if(!c_jets_AK5PFclean_partonFlavour_ && b_jets_AK5PFclean_partonFlavour_){
    b_jets_AK5PFclean_partonFlavour_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_partonFlavour", &jets_AK5PFclean_partonFlavour_, &b_jets_AK5PFclean_partonFlavour_);
    b_jets_AK5PFclean_partonFlavour_->GetEntry(entry_);
    c_jets_AK5PFclean_partonFlavour_ = true;
  }
  return jets_AK5PFclean_partonFlavour_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_parton_Energy() const{
  if(!c_jets_AK5PFclean_parton_Energy_ && b_jets_AK5PFclean_parton_Energy_){
    b_jets_AK5PFclean_parton_Energy_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_parton_Energy", &jets_AK5PFclean_parton_Energy_, &b_jets_AK5PFclean_parton_Energy_);
    b_jets_AK5PFclean_parton_Energy_->GetEntry(entry_);
    c_jets_AK5PFclean_parton_Energy_ = true;
  }
  return jets_AK5PFclean_parton_Energy_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_parton_Id() const{
  if(!c_jets_AK5PFclean_parton_Id_ && b_jets_AK5PFclean_parton_Id_){
    b_jets_AK5PFclean_parton_Id_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_parton_Id", &jets_AK5PFclean_parton_Id_, &b_jets_AK5PFclean_parton_Id_);
    b_jets_AK5PFclean_parton_Id_->GetEntry(entry_);
    c_jets_AK5PFclean_parton_Id_ = true;
  }
  return jets_AK5PFclean_parton_Id_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_parton_eta() const{
  if(!c_jets_AK5PFclean_parton_eta_ && b_jets_AK5PFclean_parton_eta_){
    b_jets_AK5PFclean_parton_eta_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_parton_eta", &jets_AK5PFclean_parton_eta_, &b_jets_AK5PFclean_parton_eta_);
    b_jets_AK5PFclean_parton_eta_->GetEntry(entry_);
    c_jets_AK5PFclean_parton_eta_ = true;
  }
  return jets_AK5PFclean_parton_eta_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_parton_mass() const{
  if(!c_jets_AK5PFclean_parton_mass_ && b_jets_AK5PFclean_parton_mass_){
    b_jets_AK5PFclean_parton_mass_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_parton_mass", &jets_AK5PFclean_parton_mass_, &b_jets_AK5PFclean_parton_mass_);
    b_jets_AK5PFclean_parton_mass_->GetEntry(entry_);
    c_jets_AK5PFclean_parton_mass_ = true;
  }
  return jets_AK5PFclean_parton_mass_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_parton_motherId() const{
  if(!c_jets_AK5PFclean_parton_motherId_ && b_jets_AK5PFclean_parton_motherId_){
    b_jets_AK5PFclean_parton_motherId_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_parton_motherId", &jets_AK5PFclean_parton_motherId_, &b_jets_AK5PFclean_parton_motherId_);
    b_jets_AK5PFclean_parton_motherId_->GetEntry(entry_);
    c_jets_AK5PFclean_parton_motherId_ = true;
  }
  return jets_AK5PFclean_parton_motherId_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_parton_phi() const{
  if(!c_jets_AK5PFclean_parton_phi_ && b_jets_AK5PFclean_parton_phi_){
    b_jets_AK5PFclean_parton_phi_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_parton_phi", &jets_AK5PFclean_parton_phi_, &b_jets_AK5PFclean_parton_phi_);
    b_jets_AK5PFclean_parton_phi_->GetEntry(entry_);
    c_jets_AK5PFclean_parton_phi_ = true;
  }
  return jets_AK5PFclean_parton_phi_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_parton_pt() const{
  if(!c_jets_AK5PFclean_parton_pt_ && b_jets_AK5PFclean_parton_pt_){
    b_jets_AK5PFclean_parton_pt_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_parton_pt", &jets_AK5PFclean_parton_pt_, &b_jets_AK5PFclean_parton_pt_);
    b_jets_AK5PFclean_parton_pt_->GetEntry(entry_);
    c_jets_AK5PFclean_parton_pt_ = true;
  }
  return jets_AK5PFclean_parton_pt_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_phi() const{
  if(!c_jets_AK5PFclean_phi_ && b_jets_AK5PFclean_phi_){
    b_jets_AK5PFclean_phi_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_phi", &jets_AK5PFclean_phi_, &b_jets_AK5PFclean_phi_);
    b_jets_AK5PFclean_phi_->GetEntry(entry_);
    c_jets_AK5PFclean_phi_ = true;
  }
  return jets_AK5PFclean_phi_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_phiphiMoment() const{
  if(!c_jets_AK5PFclean_phiphiMoment_ && b_jets_AK5PFclean_phiphiMoment_){
    b_jets_AK5PFclean_phiphiMoment_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_phiphiMoment", &jets_AK5PFclean_phiphiMoment_, &b_jets_AK5PFclean_phiphiMoment_);
    b_jets_AK5PFclean_phiphiMoment_->GetEntry(entry_);
    c_jets_AK5PFclean_phiphiMoment_ = true;
  }
  return jets_AK5PFclean_phiphiMoment_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_photonEnergy() const{
  if(!c_jets_AK5PFclean_photonEnergy_ && b_jets_AK5PFclean_photonEnergy_){
    b_jets_AK5PFclean_photonEnergy_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_photonEnergy", &jets_AK5PFclean_photonEnergy_, &b_jets_AK5PFclean_photonEnergy_);
    b_jets_AK5PFclean_photonEnergy_->GetEntry(entry_);
    c_jets_AK5PFclean_photonEnergy_ = true;
  }
  return jets_AK5PFclean_photonEnergy_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_pt() const{
  if(!c_jets_AK5PFclean_pt_ && b_jets_AK5PFclean_pt_){
    b_jets_AK5PFclean_pt_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_pt", &jets_AK5PFclean_pt_, &b_jets_AK5PFclean_pt_);
    b_jets_AK5PFclean_pt_->GetEntry(entry_);
    c_jets_AK5PFclean_pt_ = true;
  }
  return jets_AK5PFclean_pt_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_px() const{
  if(!c_jets_AK5PFclean_px_ && b_jets_AK5PFclean_px_){
    b_jets_AK5PFclean_px_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_px", &jets_AK5PFclean_px_, &b_jets_AK5PFclean_px_);
    b_jets_AK5PFclean_px_->GetEntry(entry_);
    c_jets_AK5PFclean_px_ = true;
  }
  return jets_AK5PFclean_px_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_py() const{
  if(!c_jets_AK5PFclean_py_ && b_jets_AK5PFclean_py_){
    b_jets_AK5PFclean_py_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_py", &jets_AK5PFclean_py_, &b_jets_AK5PFclean_py_);
    b_jets_AK5PFclean_py_->GetEntry(entry_);
    c_jets_AK5PFclean_py_ = true;
  }
  return jets_AK5PFclean_py_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_pz() const{
  if(!c_jets_AK5PFclean_pz_ && b_jets_AK5PFclean_pz_){
    b_jets_AK5PFclean_pz_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_pz", &jets_AK5PFclean_pz_, &b_jets_AK5PFclean_pz_);
    b_jets_AK5PFclean_pz_->GetEntry(entry_);
    c_jets_AK5PFclean_pz_ = true;
  }
  return jets_AK5PFclean_pz_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_rawPt() const{
  if(!c_jets_AK5PFclean_rawPt_ && b_jets_AK5PFclean_rawPt_){
    b_jets_AK5PFclean_rawPt_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_rawPt", &jets_AK5PFclean_rawPt_, &b_jets_AK5PFclean_rawPt_);
    b_jets_AK5PFclean_rawPt_->GetEntry(entry_);
    c_jets_AK5PFclean_rawPt_ = true;
  }
  return jets_AK5PFclean_rawPt_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_status() const{
  if(!c_jets_AK5PFclean_status_ && b_jets_AK5PFclean_status_){
    b_jets_AK5PFclean_status_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_status", &jets_AK5PFclean_status_, &b_jets_AK5PFclean_status_);
    b_jets_AK5PFclean_status_->GetEntry(entry_);
    c_jets_AK5PFclean_status_ = true;
  }
  return jets_AK5PFclean_status_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_theta() const{
  if(!c_jets_AK5PFclean_theta_ && b_jets_AK5PFclean_theta_){
    b_jets_AK5PFclean_theta_->SetStatus(true);
    chainB_.SetBranchAddress("jets_AK5PFclean_theta", &jets_AK5PFclean_theta_, &b_jets_AK5PFclean_theta_);
    b_jets_AK5PFclean_theta_->GetEntry(entry_);
    c_jets_AK5PFclean_theta_ = true;
  }
  return jets_AK5PFclean_theta_;
}

std::vector<float>* const & cfa_8::mc_pdf_id1() const{
  if(!c_mc_pdf_id1_ && b_mc_pdf_id1_){
    b_mc_pdf_id1_->SetStatus(true);
    chainB_.SetBranchAddress("mc_pdf_id1", &mc_pdf_id1_, &b_mc_pdf_id1_);
    b_mc_pdf_id1_->GetEntry(entry_);
    c_mc_pdf_id1_ = true;
  }
  return mc_pdf_id1_;
}

std::vector<float>* const & cfa_8::mc_pdf_id2() const{
  if(!c_mc_pdf_id2_ && b_mc_pdf_id2_){
    b_mc_pdf_id2_->SetStatus(true);
    chainB_.SetBranchAddress("mc_pdf_id2", &mc_pdf_id2_, &b_mc_pdf_id2_);
    b_mc_pdf_id2_->GetEntry(entry_);
    c_mc_pdf_id2_ = true;
  }
  return mc_pdf_id2_;
}

std::vector<float>* const & cfa_8::mc_pdf_q() const{
  if(!c_mc_pdf_q_ && b_mc_pdf_q_){
    b_mc_pdf_q_->SetStatus(true);
    chainB_.SetBranchAddress("mc_pdf_q", &mc_pdf_q_, &b_mc_pdf_q_);
    b_mc_pdf_q_->GetEntry(entry_);
    c_mc_pdf_q_ = true;
  }
  return mc_pdf_q_;
}

std::vector<float>* const & cfa_8::mc_pdf_x1() const{
  if(!c_mc_pdf_x1_ && b_mc_pdf_x1_){
    b_mc_pdf_x1_->SetStatus(true);
    chainB_.SetBranchAddress("mc_pdf_x1", &mc_pdf_x1_, &b_mc_pdf_x1_);
    b_mc_pdf_x1_->GetEntry(entry_);
    c_mc_pdf_x1_ = true;
  }
  return mc_pdf_x1_;
}

std::vector<float>* const & cfa_8::mc_pdf_x2() const{
  if(!c_mc_pdf_x2_ && b_mc_pdf_x2_){
    b_mc_pdf_x2_->SetStatus(true);
    chainB_.SetBranchAddress("mc_pdf_x2", &mc_pdf_x2_, &b_mc_pdf_x2_);
    b_mc_pdf_x2_->GetEntry(entry_);
    c_mc_pdf_x2_ = true;
  }
  return mc_pdf_x2_;
}

std::vector<float>* const & cfa_8::metsHO_et() const{
  if(!c_metsHO_et_ && b_metsHO_et_){
    b_metsHO_et_->SetStatus(true);
    chainB_.SetBranchAddress("metsHO_et", &metsHO_et_, &b_metsHO_et_);
    b_metsHO_et_->GetEntry(entry_);
    c_metsHO_et_ = true;
  }
  return metsHO_et_;
}

std::vector<float>* const & cfa_8::metsHO_ex() const{
  if(!c_metsHO_ex_ && b_metsHO_ex_){
    b_metsHO_ex_->SetStatus(true);
    chainB_.SetBranchAddress("metsHO_ex", &metsHO_ex_, &b_metsHO_ex_);
    b_metsHO_ex_->GetEntry(entry_);
    c_metsHO_ex_ = true;
  }
  return metsHO_ex_;
}

std::vector<float>* const & cfa_8::metsHO_ey() const{
  if(!c_metsHO_ey_ && b_metsHO_ey_){
    b_metsHO_ey_->SetStatus(true);
    chainB_.SetBranchAddress("metsHO_ey", &metsHO_ey_, &b_metsHO_ey_);
    b_metsHO_ey_->GetEntry(entry_);
    c_metsHO_ey_ = true;
  }
  return metsHO_ey_;
}

std::vector<float>* const & cfa_8::metsHO_phi() const{
  if(!c_metsHO_phi_ && b_metsHO_phi_){
    b_metsHO_phi_->SetStatus(true);
    chainB_.SetBranchAddress("metsHO_phi", &metsHO_phi_, &b_metsHO_phi_);
    b_metsHO_phi_->GetEntry(entry_);
    c_metsHO_phi_ = true;
  }
  return metsHO_phi_;
}

std::vector<float>* const & cfa_8::metsHO_sumEt() const{
  if(!c_metsHO_sumEt_ && b_metsHO_sumEt_){
    b_metsHO_sumEt_->SetStatus(true);
    chainB_.SetBranchAddress("metsHO_sumEt", &metsHO_sumEt_, &b_metsHO_sumEt_);
    b_metsHO_sumEt_->GetEntry(entry_);
    c_metsHO_sumEt_ = true;
  }
  return metsHO_sumEt_;
}

std::vector<float>* const & cfa_8::mets_AK5_et() const{
  if(!c_mets_AK5_et_ && b_mets_AK5_et_){
    b_mets_AK5_et_->SetStatus(true);
    chainB_.SetBranchAddress("mets_AK5_et", &mets_AK5_et_, &b_mets_AK5_et_);
    b_mets_AK5_et_->GetEntry(entry_);
    c_mets_AK5_et_ = true;
  }
  return mets_AK5_et_;
}

std::vector<float>* const & cfa_8::mets_AK5_ex() const{
  if(!c_mets_AK5_ex_ && b_mets_AK5_ex_){
    b_mets_AK5_ex_->SetStatus(true);
    chainB_.SetBranchAddress("mets_AK5_ex", &mets_AK5_ex_, &b_mets_AK5_ex_);
    b_mets_AK5_ex_->GetEntry(entry_);
    c_mets_AK5_ex_ = true;
  }
  return mets_AK5_ex_;
}

std::vector<float>* const & cfa_8::mets_AK5_ey() const{
  if(!c_mets_AK5_ey_ && b_mets_AK5_ey_){
    b_mets_AK5_ey_->SetStatus(true);
    chainB_.SetBranchAddress("mets_AK5_ey", &mets_AK5_ey_, &b_mets_AK5_ey_);
    b_mets_AK5_ey_->GetEntry(entry_);
    c_mets_AK5_ey_ = true;
  }
  return mets_AK5_ey_;
}

std::vector<float>* const & cfa_8::mets_AK5_gen_et() const{
  if(!c_mets_AK5_gen_et_ && b_mets_AK5_gen_et_){
    b_mets_AK5_gen_et_->SetStatus(true);
    chainB_.SetBranchAddress("mets_AK5_gen_et", &mets_AK5_gen_et_, &b_mets_AK5_gen_et_);
    b_mets_AK5_gen_et_->GetEntry(entry_);
    c_mets_AK5_gen_et_ = true;
  }
  return mets_AK5_gen_et_;
}

std::vector<float>* const & cfa_8::mets_AK5_gen_phi() const{
  if(!c_mets_AK5_gen_phi_ && b_mets_AK5_gen_phi_){
    b_mets_AK5_gen_phi_->SetStatus(true);
    chainB_.SetBranchAddress("mets_AK5_gen_phi", &mets_AK5_gen_phi_, &b_mets_AK5_gen_phi_);
    b_mets_AK5_gen_phi_->GetEntry(entry_);
    c_mets_AK5_gen_phi_ = true;
  }
  return mets_AK5_gen_phi_;
}

std::vector<float>* const & cfa_8::mets_AK5_phi() const{
  if(!c_mets_AK5_phi_ && b_mets_AK5_phi_){
    b_mets_AK5_phi_->SetStatus(true);
    chainB_.SetBranchAddress("mets_AK5_phi", &mets_AK5_phi_, &b_mets_AK5_phi_);
    b_mets_AK5_phi_->GetEntry(entry_);
    c_mets_AK5_phi_ = true;
  }
  return mets_AK5_phi_;
}

std::vector<float>* const & cfa_8::mets_AK5_sign() const{
  if(!c_mets_AK5_sign_ && b_mets_AK5_sign_){
    b_mets_AK5_sign_->SetStatus(true);
    chainB_.SetBranchAddress("mets_AK5_sign", &mets_AK5_sign_, &b_mets_AK5_sign_);
    b_mets_AK5_sign_->GetEntry(entry_);
    c_mets_AK5_sign_ = true;
  }
  return mets_AK5_sign_;
}

std::vector<float>* const & cfa_8::mets_AK5_sumEt() const{
  if(!c_mets_AK5_sumEt_ && b_mets_AK5_sumEt_){
    b_mets_AK5_sumEt_->SetStatus(true);
    chainB_.SetBranchAddress("mets_AK5_sumEt", &mets_AK5_sumEt_, &b_mets_AK5_sumEt_);
    b_mets_AK5_sumEt_->GetEntry(entry_);
    c_mets_AK5_sumEt_ = true;
  }
  return mets_AK5_sumEt_;
}

std::vector<float>* const & cfa_8::mets_AK5_unCPhi() const{
  if(!c_mets_AK5_unCPhi_ && b_mets_AK5_unCPhi_){
    b_mets_AK5_unCPhi_->SetStatus(true);
    chainB_.SetBranchAddress("mets_AK5_unCPhi", &mets_AK5_unCPhi_, &b_mets_AK5_unCPhi_);
    b_mets_AK5_unCPhi_->GetEntry(entry_);
    c_mets_AK5_unCPhi_ = true;
  }
  return mets_AK5_unCPhi_;
}

std::vector<float>* const & cfa_8::mets_AK5_unCPt() const{
  if(!c_mets_AK5_unCPt_ && b_mets_AK5_unCPt_){
    b_mets_AK5_unCPt_->SetStatus(true);
    chainB_.SetBranchAddress("mets_AK5_unCPt", &mets_AK5_unCPt_, &b_mets_AK5_unCPt_);
    b_mets_AK5_unCPt_->GetEntry(entry_);
    c_mets_AK5_unCPt_ = true;
  }
  return mets_AK5_unCPt_;
}

Int_t const & cfa_8::passprescaleHT250filter_decision() const{
  if(!c_passprescaleHT250filter_decision_ && b_passprescaleHT250filter_decision_){
    b_passprescaleHT250filter_decision_->SetStatus(true);
    chainA_.SetBranchAddress("passprescaleHT250filter_decision", &passprescaleHT250filter_decision_, &b_passprescaleHT250filter_decision_);
    b_passprescaleHT250filter_decision_->GetEntry(entry_);
    c_passprescaleHT250filter_decision_ = true;
  }
  return passprescaleHT250filter_decision_;
}

Int_t const & cfa_8::passprescaleHT300filter_decision() const{
  if(!c_passprescaleHT300filter_decision_ && b_passprescaleHT300filter_decision_){
    b_passprescaleHT300filter_decision_->SetStatus(true);
    chainA_.SetBranchAddress("passprescaleHT300filter_decision", &passprescaleHT300filter_decision_, &b_passprescaleHT300filter_decision_);
    b_passprescaleHT300filter_decision_->GetEntry(entry_);
    c_passprescaleHT300filter_decision_ = true;
  }
  return passprescaleHT300filter_decision_;
}

Int_t const & cfa_8::passprescaleHT350filter_decision() const{
  if(!c_passprescaleHT350filter_decision_ && b_passprescaleHT350filter_decision_){
    b_passprescaleHT350filter_decision_->SetStatus(true);
    chainA_.SetBranchAddress("passprescaleHT350filter_decision", &passprescaleHT350filter_decision_, &b_passprescaleHT350filter_decision_);
    b_passprescaleHT350filter_decision_->GetEntry(entry_);
    c_passprescaleHT350filter_decision_ = true;
  }
  return passprescaleHT350filter_decision_;
}

Int_t const & cfa_8::passprescaleHT400filter_decision() const{
  if(!c_passprescaleHT400filter_decision_ && b_passprescaleHT400filter_decision_){
    b_passprescaleHT400filter_decision_->SetStatus(true);
    chainA_.SetBranchAddress("passprescaleHT400filter_decision", &passprescaleHT400filter_decision_, &b_passprescaleHT400filter_decision_);
    b_passprescaleHT400filter_decision_->GetEntry(entry_);
    c_passprescaleHT400filter_decision_ = true;
  }
  return passprescaleHT400filter_decision_;
}

Int_t const & cfa_8::passprescaleHT450filter_decision() const{
  if(!c_passprescaleHT450filter_decision_ && b_passprescaleHT450filter_decision_){
    b_passprescaleHT450filter_decision_->SetStatus(true);
    chainA_.SetBranchAddress("passprescaleHT450filter_decision", &passprescaleHT450filter_decision_, &b_passprescaleHT450filter_decision_);
    b_passprescaleHT450filter_decision_->GetEntry(entry_);
    c_passprescaleHT450filter_decision_ = true;
  }
  return passprescaleHT450filter_decision_;
}

Int_t const & cfa_8::passprescaleJet30MET80filter_decision() const{
  if(!c_passprescaleJet30MET80filter_decision_ && b_passprescaleJet30MET80filter_decision_){
    b_passprescaleJet30MET80filter_decision_->SetStatus(true);
    chainA_.SetBranchAddress("passprescaleJet30MET80filter_decision", &passprescaleJet30MET80filter_decision_, &b_passprescaleJet30MET80filter_decision_);
    b_passprescaleJet30MET80filter_decision_->GetEntry(entry_);
    c_passprescaleJet30MET80filter_decision_ = true;
  }
  return passprescaleJet30MET80filter_decision_;
}

Int_t const & cfa_8::passprescalePFHT350filter_decision() const{
  if(!c_passprescalePFHT350filter_decision_ && b_passprescalePFHT350filter_decision_){
    b_passprescalePFHT350filter_decision_->SetStatus(true);
    chainA_.SetBranchAddress("passprescalePFHT350filter_decision", &passprescalePFHT350filter_decision_, &b_passprescalePFHT350filter_decision_);
    b_passprescalePFHT350filter_decision_->GetEntry(entry_);
    c_passprescalePFHT350filter_decision_ = true;
  }
  return passprescalePFHT350filter_decision_;
}

std::vector<float>* const & cfa_8::pdfweights_cteq() const{
  if(!c_pdfweights_cteq_ && b_pdfweights_cteq_){
    b_pdfweights_cteq_->SetStatus(true);
    chainA_.SetBranchAddress("pdfweights_cteq", &pdfweights_cteq_, &b_pdfweights_cteq_);
    b_pdfweights_cteq_->GetEntry(entry_);
    c_pdfweights_cteq_ = true;
  }
  return pdfweights_cteq_;
}

std::vector<float>* const & cfa_8::pdfweights_mstw() const{
  if(!c_pdfweights_mstw_ && b_pdfweights_mstw_){
    b_pdfweights_mstw_->SetStatus(true);
    chainA_.SetBranchAddress("pdfweights_mstw", &pdfweights_mstw_, &b_pdfweights_mstw_);
    b_pdfweights_mstw_->GetEntry(entry_);
    c_pdfweights_mstw_ = true;
  }
  return pdfweights_mstw_;
}

std::vector<float>* const & cfa_8::pdfweights_nnpdf() const{
  if(!c_pdfweights_nnpdf_ && b_pdfweights_nnpdf_){
    b_pdfweights_nnpdf_->SetStatus(true);
    chainA_.SetBranchAddress("pdfweights_nnpdf", &pdfweights_nnpdf_, &b_pdfweights_nnpdf_);
    b_pdfweights_nnpdf_->GetEntry(entry_);
    c_pdfweights_nnpdf_ = true;
  }
  return pdfweights_nnpdf_;
}

std::vector<float>* const & cfa_8::pfTypeINoXYCorrmets_et() const{
  if(!c_pfTypeINoXYCorrmets_et_ && b_pfTypeINoXYCorrmets_et_){
    b_pfTypeINoXYCorrmets_et_->SetStatus(true);
    chainB_.SetBranchAddress("pfTypeINoXYCorrmets_et", &pfTypeINoXYCorrmets_et_, &b_pfTypeINoXYCorrmets_et_);
    b_pfTypeINoXYCorrmets_et_->GetEntry(entry_);
    c_pfTypeINoXYCorrmets_et_ = true;
  }
  return pfTypeINoXYCorrmets_et_;
}

std::vector<float>* const & cfa_8::pfTypeINoXYCorrmets_ex() const{
  if(!c_pfTypeINoXYCorrmets_ex_ && b_pfTypeINoXYCorrmets_ex_){
    b_pfTypeINoXYCorrmets_ex_->SetStatus(true);
    chainB_.SetBranchAddress("pfTypeINoXYCorrmets_ex", &pfTypeINoXYCorrmets_ex_, &b_pfTypeINoXYCorrmets_ex_);
    b_pfTypeINoXYCorrmets_ex_->GetEntry(entry_);
    c_pfTypeINoXYCorrmets_ex_ = true;
  }
  return pfTypeINoXYCorrmets_ex_;
}

std::vector<float>* const & cfa_8::pfTypeINoXYCorrmets_ey() const{
  if(!c_pfTypeINoXYCorrmets_ey_ && b_pfTypeINoXYCorrmets_ey_){
    b_pfTypeINoXYCorrmets_ey_->SetStatus(true);
    chainB_.SetBranchAddress("pfTypeINoXYCorrmets_ey", &pfTypeINoXYCorrmets_ey_, &b_pfTypeINoXYCorrmets_ey_);
    b_pfTypeINoXYCorrmets_ey_->GetEntry(entry_);
    c_pfTypeINoXYCorrmets_ey_ = true;
  }
  return pfTypeINoXYCorrmets_ey_;
}

std::vector<float>* const & cfa_8::pfTypeINoXYCorrmets_gen_et() const{
  if(!c_pfTypeINoXYCorrmets_gen_et_ && b_pfTypeINoXYCorrmets_gen_et_){
    b_pfTypeINoXYCorrmets_gen_et_->SetStatus(true);
    chainB_.SetBranchAddress("pfTypeINoXYCorrmets_gen_et", &pfTypeINoXYCorrmets_gen_et_, &b_pfTypeINoXYCorrmets_gen_et_);
    b_pfTypeINoXYCorrmets_gen_et_->GetEntry(entry_);
    c_pfTypeINoXYCorrmets_gen_et_ = true;
  }
  return pfTypeINoXYCorrmets_gen_et_;
}

std::vector<float>* const & cfa_8::pfTypeINoXYCorrmets_gen_phi() const{
  if(!c_pfTypeINoXYCorrmets_gen_phi_ && b_pfTypeINoXYCorrmets_gen_phi_){
    b_pfTypeINoXYCorrmets_gen_phi_->SetStatus(true);
    chainB_.SetBranchAddress("pfTypeINoXYCorrmets_gen_phi", &pfTypeINoXYCorrmets_gen_phi_, &b_pfTypeINoXYCorrmets_gen_phi_);
    b_pfTypeINoXYCorrmets_gen_phi_->GetEntry(entry_);
    c_pfTypeINoXYCorrmets_gen_phi_ = true;
  }
  return pfTypeINoXYCorrmets_gen_phi_;
}

std::vector<float>* const & cfa_8::pfTypeINoXYCorrmets_phi() const{
  if(!c_pfTypeINoXYCorrmets_phi_ && b_pfTypeINoXYCorrmets_phi_){
    b_pfTypeINoXYCorrmets_phi_->SetStatus(true);
    chainB_.SetBranchAddress("pfTypeINoXYCorrmets_phi", &pfTypeINoXYCorrmets_phi_, &b_pfTypeINoXYCorrmets_phi_);
    b_pfTypeINoXYCorrmets_phi_->GetEntry(entry_);
    c_pfTypeINoXYCorrmets_phi_ = true;
  }
  return pfTypeINoXYCorrmets_phi_;
}

std::vector<float>* const & cfa_8::pfTypeINoXYCorrmets_sign() const{
  if(!c_pfTypeINoXYCorrmets_sign_ && b_pfTypeINoXYCorrmets_sign_){
    b_pfTypeINoXYCorrmets_sign_->SetStatus(true);
    chainB_.SetBranchAddress("pfTypeINoXYCorrmets_sign", &pfTypeINoXYCorrmets_sign_, &b_pfTypeINoXYCorrmets_sign_);
    b_pfTypeINoXYCorrmets_sign_->GetEntry(entry_);
    c_pfTypeINoXYCorrmets_sign_ = true;
  }
  return pfTypeINoXYCorrmets_sign_;
}

std::vector<float>* const & cfa_8::pfTypeINoXYCorrmets_sumEt() const{
  if(!c_pfTypeINoXYCorrmets_sumEt_ && b_pfTypeINoXYCorrmets_sumEt_){
    b_pfTypeINoXYCorrmets_sumEt_->SetStatus(true);
    chainB_.SetBranchAddress("pfTypeINoXYCorrmets_sumEt", &pfTypeINoXYCorrmets_sumEt_, &b_pfTypeINoXYCorrmets_sumEt_);
    b_pfTypeINoXYCorrmets_sumEt_->GetEntry(entry_);
    c_pfTypeINoXYCorrmets_sumEt_ = true;
  }
  return pfTypeINoXYCorrmets_sumEt_;
}

std::vector<float>* const & cfa_8::pfTypeINoXYCorrmets_unCPhi() const{
  if(!c_pfTypeINoXYCorrmets_unCPhi_ && b_pfTypeINoXYCorrmets_unCPhi_){
    b_pfTypeINoXYCorrmets_unCPhi_->SetStatus(true);
    chainB_.SetBranchAddress("pfTypeINoXYCorrmets_unCPhi", &pfTypeINoXYCorrmets_unCPhi_, &b_pfTypeINoXYCorrmets_unCPhi_);
    b_pfTypeINoXYCorrmets_unCPhi_->GetEntry(entry_);
    c_pfTypeINoXYCorrmets_unCPhi_ = true;
  }
  return pfTypeINoXYCorrmets_unCPhi_;
}

std::vector<float>* const & cfa_8::pfTypeINoXYCorrmets_unCPt() const{
  if(!c_pfTypeINoXYCorrmets_unCPt_ && b_pfTypeINoXYCorrmets_unCPt_){
    b_pfTypeINoXYCorrmets_unCPt_->SetStatus(true);
    chainB_.SetBranchAddress("pfTypeINoXYCorrmets_unCPt", &pfTypeINoXYCorrmets_unCPt_, &b_pfTypeINoXYCorrmets_unCPt_);
    b_pfTypeINoXYCorrmets_unCPt_->GetEntry(entry_);
    c_pfTypeINoXYCorrmets_unCPt_ = true;
  }
  return pfTypeINoXYCorrmets_unCPt_;
}

std::vector<float>* const & cfa_8::pfTypeIType0mets_et() const{
  if(!c_pfTypeIType0mets_et_ && b_pfTypeIType0mets_et_){
    b_pfTypeIType0mets_et_->SetStatus(true);
    chainB_.SetBranchAddress("pfTypeIType0mets_et", &pfTypeIType0mets_et_, &b_pfTypeIType0mets_et_);
    b_pfTypeIType0mets_et_->GetEntry(entry_);
    c_pfTypeIType0mets_et_ = true;
  }
  return pfTypeIType0mets_et_;
}

std::vector<float>* const & cfa_8::pfTypeIType0mets_ex() const{
  if(!c_pfTypeIType0mets_ex_ && b_pfTypeIType0mets_ex_){
    b_pfTypeIType0mets_ex_->SetStatus(true);
    chainB_.SetBranchAddress("pfTypeIType0mets_ex", &pfTypeIType0mets_ex_, &b_pfTypeIType0mets_ex_);
    b_pfTypeIType0mets_ex_->GetEntry(entry_);
    c_pfTypeIType0mets_ex_ = true;
  }
  return pfTypeIType0mets_ex_;
}

std::vector<float>* const & cfa_8::pfTypeIType0mets_ey() const{
  if(!c_pfTypeIType0mets_ey_ && b_pfTypeIType0mets_ey_){
    b_pfTypeIType0mets_ey_->SetStatus(true);
    chainB_.SetBranchAddress("pfTypeIType0mets_ey", &pfTypeIType0mets_ey_, &b_pfTypeIType0mets_ey_);
    b_pfTypeIType0mets_ey_->GetEntry(entry_);
    c_pfTypeIType0mets_ey_ = true;
  }
  return pfTypeIType0mets_ey_;
}

std::vector<float>* const & cfa_8::pfTypeIType0mets_gen_et() const{
  if(!c_pfTypeIType0mets_gen_et_ && b_pfTypeIType0mets_gen_et_){
    b_pfTypeIType0mets_gen_et_->SetStatus(true);
    chainB_.SetBranchAddress("pfTypeIType0mets_gen_et", &pfTypeIType0mets_gen_et_, &b_pfTypeIType0mets_gen_et_);
    b_pfTypeIType0mets_gen_et_->GetEntry(entry_);
    c_pfTypeIType0mets_gen_et_ = true;
  }
  return pfTypeIType0mets_gen_et_;
}

std::vector<float>* const & cfa_8::pfTypeIType0mets_gen_phi() const{
  if(!c_pfTypeIType0mets_gen_phi_ && b_pfTypeIType0mets_gen_phi_){
    b_pfTypeIType0mets_gen_phi_->SetStatus(true);
    chainB_.SetBranchAddress("pfTypeIType0mets_gen_phi", &pfTypeIType0mets_gen_phi_, &b_pfTypeIType0mets_gen_phi_);
    b_pfTypeIType0mets_gen_phi_->GetEntry(entry_);
    c_pfTypeIType0mets_gen_phi_ = true;
  }
  return pfTypeIType0mets_gen_phi_;
}

std::vector<float>* const & cfa_8::pfTypeIType0mets_phi() const{
  if(!c_pfTypeIType0mets_phi_ && b_pfTypeIType0mets_phi_){
    b_pfTypeIType0mets_phi_->SetStatus(true);
    chainB_.SetBranchAddress("pfTypeIType0mets_phi", &pfTypeIType0mets_phi_, &b_pfTypeIType0mets_phi_);
    b_pfTypeIType0mets_phi_->GetEntry(entry_);
    c_pfTypeIType0mets_phi_ = true;
  }
  return pfTypeIType0mets_phi_;
}

std::vector<float>* const & cfa_8::pfTypeIType0mets_sign() const{
  if(!c_pfTypeIType0mets_sign_ && b_pfTypeIType0mets_sign_){
    b_pfTypeIType0mets_sign_->SetStatus(true);
    chainB_.SetBranchAddress("pfTypeIType0mets_sign", &pfTypeIType0mets_sign_, &b_pfTypeIType0mets_sign_);
    b_pfTypeIType0mets_sign_->GetEntry(entry_);
    c_pfTypeIType0mets_sign_ = true;
  }
  return pfTypeIType0mets_sign_;
}

std::vector<float>* const & cfa_8::pfTypeIType0mets_sumEt() const{
  if(!c_pfTypeIType0mets_sumEt_ && b_pfTypeIType0mets_sumEt_){
    b_pfTypeIType0mets_sumEt_->SetStatus(true);
    chainB_.SetBranchAddress("pfTypeIType0mets_sumEt", &pfTypeIType0mets_sumEt_, &b_pfTypeIType0mets_sumEt_);
    b_pfTypeIType0mets_sumEt_->GetEntry(entry_);
    c_pfTypeIType0mets_sumEt_ = true;
  }
  return pfTypeIType0mets_sumEt_;
}

std::vector<float>* const & cfa_8::pfTypeIType0mets_unCPhi() const{
  if(!c_pfTypeIType0mets_unCPhi_ && b_pfTypeIType0mets_unCPhi_){
    b_pfTypeIType0mets_unCPhi_->SetStatus(true);
    chainB_.SetBranchAddress("pfTypeIType0mets_unCPhi", &pfTypeIType0mets_unCPhi_, &b_pfTypeIType0mets_unCPhi_);
    b_pfTypeIType0mets_unCPhi_->GetEntry(entry_);
    c_pfTypeIType0mets_unCPhi_ = true;
  }
  return pfTypeIType0mets_unCPhi_;
}

std::vector<float>* const & cfa_8::pfTypeIType0mets_unCPt() const{
  if(!c_pfTypeIType0mets_unCPt_ && b_pfTypeIType0mets_unCPt_){
    b_pfTypeIType0mets_unCPt_->SetStatus(true);
    chainB_.SetBranchAddress("pfTypeIType0mets_unCPt", &pfTypeIType0mets_unCPt_, &b_pfTypeIType0mets_unCPt_);
    b_pfTypeIType0mets_unCPt_->GetEntry(entry_);
    c_pfTypeIType0mets_unCPt_ = true;
  }
  return pfTypeIType0mets_unCPt_;
}

std::vector<float>* const & cfa_8::pfTypeImets_et() const{
  if(!c_pfTypeImets_et_ && b_pfTypeImets_et_){
    b_pfTypeImets_et_->SetStatus(true);
    chainB_.SetBranchAddress("pfTypeImets_et", &pfTypeImets_et_, &b_pfTypeImets_et_);
    b_pfTypeImets_et_->GetEntry(entry_);
    c_pfTypeImets_et_ = true;
  }
  return pfTypeImets_et_;
}

std::vector<float>* const & cfa_8::pfTypeImets_ex() const{
  if(!c_pfTypeImets_ex_ && b_pfTypeImets_ex_){
    b_pfTypeImets_ex_->SetStatus(true);
    chainB_.SetBranchAddress("pfTypeImets_ex", &pfTypeImets_ex_, &b_pfTypeImets_ex_);
    b_pfTypeImets_ex_->GetEntry(entry_);
    c_pfTypeImets_ex_ = true;
  }
  return pfTypeImets_ex_;
}

std::vector<float>* const & cfa_8::pfTypeImets_ey() const{
  if(!c_pfTypeImets_ey_ && b_pfTypeImets_ey_){
    b_pfTypeImets_ey_->SetStatus(true);
    chainB_.SetBranchAddress("pfTypeImets_ey", &pfTypeImets_ey_, &b_pfTypeImets_ey_);
    b_pfTypeImets_ey_->GetEntry(entry_);
    c_pfTypeImets_ey_ = true;
  }
  return pfTypeImets_ey_;
}

std::vector<float>* const & cfa_8::pfTypeImets_gen_et() const{
  if(!c_pfTypeImets_gen_et_ && b_pfTypeImets_gen_et_){
    b_pfTypeImets_gen_et_->SetStatus(true);
    chainB_.SetBranchAddress("pfTypeImets_gen_et", &pfTypeImets_gen_et_, &b_pfTypeImets_gen_et_);
    b_pfTypeImets_gen_et_->GetEntry(entry_);
    c_pfTypeImets_gen_et_ = true;
  }
  return pfTypeImets_gen_et_;
}

std::vector<float>* const & cfa_8::pfTypeImets_gen_phi() const{
  if(!c_pfTypeImets_gen_phi_ && b_pfTypeImets_gen_phi_){
    b_pfTypeImets_gen_phi_->SetStatus(true);
    chainB_.SetBranchAddress("pfTypeImets_gen_phi", &pfTypeImets_gen_phi_, &b_pfTypeImets_gen_phi_);
    b_pfTypeImets_gen_phi_->GetEntry(entry_);
    c_pfTypeImets_gen_phi_ = true;
  }
  return pfTypeImets_gen_phi_;
}

std::vector<float>* const & cfa_8::pfTypeImets_phi() const{
  if(!c_pfTypeImets_phi_ && b_pfTypeImets_phi_){
    b_pfTypeImets_phi_->SetStatus(true);
    chainB_.SetBranchAddress("pfTypeImets_phi", &pfTypeImets_phi_, &b_pfTypeImets_phi_);
    b_pfTypeImets_phi_->GetEntry(entry_);
    c_pfTypeImets_phi_ = true;
  }
  return pfTypeImets_phi_;
}

std::vector<float>* const & cfa_8::pfTypeImets_sign() const{
  if(!c_pfTypeImets_sign_ && b_pfTypeImets_sign_){
    b_pfTypeImets_sign_->SetStatus(true);
    chainB_.SetBranchAddress("pfTypeImets_sign", &pfTypeImets_sign_, &b_pfTypeImets_sign_);
    b_pfTypeImets_sign_->GetEntry(entry_);
    c_pfTypeImets_sign_ = true;
  }
  return pfTypeImets_sign_;
}

std::vector<float>* const & cfa_8::pfTypeImets_sumEt() const{
  if(!c_pfTypeImets_sumEt_ && b_pfTypeImets_sumEt_){
    b_pfTypeImets_sumEt_->SetStatus(true);
    chainB_.SetBranchAddress("pfTypeImets_sumEt", &pfTypeImets_sumEt_, &b_pfTypeImets_sumEt_);
    b_pfTypeImets_sumEt_->GetEntry(entry_);
    c_pfTypeImets_sumEt_ = true;
  }
  return pfTypeImets_sumEt_;
}

std::vector<float>* const & cfa_8::pfTypeImets_unCPhi() const{
  if(!c_pfTypeImets_unCPhi_ && b_pfTypeImets_unCPhi_){
    b_pfTypeImets_unCPhi_->SetStatus(true);
    chainB_.SetBranchAddress("pfTypeImets_unCPhi", &pfTypeImets_unCPhi_, &b_pfTypeImets_unCPhi_);
    b_pfTypeImets_unCPhi_->GetEntry(entry_);
    c_pfTypeImets_unCPhi_ = true;
  }
  return pfTypeImets_unCPhi_;
}

std::vector<float>* const & cfa_8::pfTypeImets_unCPt() const{
  if(!c_pfTypeImets_unCPt_ && b_pfTypeImets_unCPt_){
    b_pfTypeImets_unCPt_->SetStatus(true);
    chainB_.SetBranchAddress("pfTypeImets_unCPt", &pfTypeImets_unCPt_, &b_pfTypeImets_unCPt_);
    b_pfTypeImets_unCPt_->GetEntry(entry_);
    c_pfTypeImets_unCPt_ = true;
  }
  return pfTypeImets_unCPt_;
}

std::vector<float>* const & cfa_8::pf_els_PATpassConversionVeto() const{
  if(!c_pf_els_PATpassConversionVeto_ && b_pf_els_PATpassConversionVeto_){
    b_pf_els_PATpassConversionVeto_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_PATpassConversionVeto", &pf_els_PATpassConversionVeto_, &b_pf_els_PATpassConversionVeto_);
    b_pf_els_PATpassConversionVeto_->GetEntry(entry_);
    c_pf_els_PATpassConversionVeto_ = true;
  }
  return pf_els_PATpassConversionVeto_;
}

std::vector<float>* const & cfa_8::pf_els_PFchargedHadronIsoR03() const{
  if(!c_pf_els_PFchargedHadronIsoR03_ && b_pf_els_PFchargedHadronIsoR03_){
    b_pf_els_PFchargedHadronIsoR03_->SetStatus(true);
    chainA_.SetBranchAddress("pf_els_PFchargedHadronIsoR03", &pf_els_PFchargedHadronIsoR03_, &b_pf_els_PFchargedHadronIsoR03_);
    b_pf_els_PFchargedHadronIsoR03_->GetEntry(entry_);
    c_pf_els_PFchargedHadronIsoR03_ = true;
  }
  return pf_els_PFchargedHadronIsoR03_;
}

std::vector<float>* const & cfa_8::pf_els_PFneutralHadronIsoR03() const{
  if(!c_pf_els_PFneutralHadronIsoR03_ && b_pf_els_PFneutralHadronIsoR03_){
    b_pf_els_PFneutralHadronIsoR03_->SetStatus(true);
    chainA_.SetBranchAddress("pf_els_PFneutralHadronIsoR03", &pf_els_PFneutralHadronIsoR03_, &b_pf_els_PFneutralHadronIsoR03_);
    b_pf_els_PFneutralHadronIsoR03_->GetEntry(entry_);
    c_pf_els_PFneutralHadronIsoR03_ = true;
  }
  return pf_els_PFneutralHadronIsoR03_;
}

std::vector<float>* const & cfa_8::pf_els_PFphotonIsoR03() const{
  if(!c_pf_els_PFphotonIsoR03_ && b_pf_els_PFphotonIsoR03_){
    b_pf_els_PFphotonIsoR03_->SetStatus(true);
    chainA_.SetBranchAddress("pf_els_PFphotonIsoR03", &pf_els_PFphotonIsoR03_, &b_pf_els_PFphotonIsoR03_);
    b_pf_els_PFphotonIsoR03_->GetEntry(entry_);
    c_pf_els_PFphotonIsoR03_ = true;
  }
  return pf_els_PFphotonIsoR03_;
}

std::vector<float>* const & cfa_8::pf_els_basicClustersSize() const{
  if(!c_pf_els_basicClustersSize_ && b_pf_els_basicClustersSize_){
    b_pf_els_basicClustersSize_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_basicClustersSize", &pf_els_basicClustersSize_, &b_pf_els_basicClustersSize_);
    b_pf_els_basicClustersSize_->GetEntry(entry_);
    c_pf_els_basicClustersSize_ = true;
  }
  return pf_els_basicClustersSize_;
}

std::vector<float>* const & cfa_8::pf_els_cIso() const{
  if(!c_pf_els_cIso_ && b_pf_els_cIso_){
    b_pf_els_cIso_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_cIso", &pf_els_cIso_, &b_pf_els_cIso_);
    b_pf_els_cIso_->GetEntry(entry_);
    c_pf_els_cIso_ = true;
  }
  return pf_els_cIso_;
}

std::vector<float>* const & cfa_8::pf_els_caloEnergy() const{
  if(!c_pf_els_caloEnergy_ && b_pf_els_caloEnergy_){
    b_pf_els_caloEnergy_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_caloEnergy", &pf_els_caloEnergy_, &b_pf_els_caloEnergy_);
    b_pf_els_caloEnergy_->GetEntry(entry_);
    c_pf_els_caloEnergy_ = true;
  }
  return pf_els_caloEnergy_;
}

std::vector<float>* const & cfa_8::pf_els_charge() const{
  if(!c_pf_els_charge_ && b_pf_els_charge_){
    b_pf_els_charge_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_charge", &pf_els_charge_, &b_pf_els_charge_);
    b_pf_els_charge_->GetEntry(entry_);
    c_pf_els_charge_ = true;
  }
  return pf_els_charge_;
}

std::vector<float>* const & cfa_8::pf_els_chargedHadronIso() const{
  if(!c_pf_els_chargedHadronIso_ && b_pf_els_chargedHadronIso_){
    b_pf_els_chargedHadronIso_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_chargedHadronIso", &pf_els_chargedHadronIso_, &b_pf_els_chargedHadronIso_);
    b_pf_els_chargedHadronIso_->GetEntry(entry_);
    c_pf_els_chargedHadronIso_ = true;
  }
  return pf_els_chargedHadronIso_;
}

std::vector<float>* const & cfa_8::pf_els_chi2() const{
  if(!c_pf_els_chi2_ && b_pf_els_chi2_){
    b_pf_els_chi2_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_chi2", &pf_els_chi2_, &b_pf_els_chi2_);
    b_pf_els_chi2_->GetEntry(entry_);
    c_pf_els_chi2_ = true;
  }
  return pf_els_chi2_;
}

std::vector<float>* const & cfa_8::pf_els_core_ecalDrivenSeed() const{
  if(!c_pf_els_core_ecalDrivenSeed_ && b_pf_els_core_ecalDrivenSeed_){
    b_pf_els_core_ecalDrivenSeed_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_core_ecalDrivenSeed", &pf_els_core_ecalDrivenSeed_, &b_pf_els_core_ecalDrivenSeed_);
    b_pf_els_core_ecalDrivenSeed_->GetEntry(entry_);
    c_pf_els_core_ecalDrivenSeed_ = true;
  }
  return pf_els_core_ecalDrivenSeed_;
}

std::vector<float>* const & cfa_8::pf_els_cpx() const{
  if(!c_pf_els_cpx_ && b_pf_els_cpx_){
    b_pf_els_cpx_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_cpx", &pf_els_cpx_, &b_pf_els_cpx_);
    b_pf_els_cpx_->GetEntry(entry_);
    c_pf_els_cpx_ = true;
  }
  return pf_els_cpx_;
}

std::vector<float>* const & cfa_8::pf_els_cpy() const{
  if(!c_pf_els_cpy_ && b_pf_els_cpy_){
    b_pf_els_cpy_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_cpy", &pf_els_cpy_, &b_pf_els_cpy_);
    b_pf_els_cpy_->GetEntry(entry_);
    c_pf_els_cpy_ = true;
  }
  return pf_els_cpy_;
}

std::vector<float>* const & cfa_8::pf_els_cpz() const{
  if(!c_pf_els_cpz_ && b_pf_els_cpz_){
    b_pf_els_cpz_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_cpz", &pf_els_cpz_, &b_pf_els_cpz_);
    b_pf_els_cpz_->GetEntry(entry_);
    c_pf_els_cpz_ = true;
  }
  return pf_els_cpz_;
}

std::vector<float>* const & cfa_8::pf_els_ctf_tk_charge() const{
  if(!c_pf_els_ctf_tk_charge_ && b_pf_els_ctf_tk_charge_){
    b_pf_els_ctf_tk_charge_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_ctf_tk_charge", &pf_els_ctf_tk_charge_, &b_pf_els_ctf_tk_charge_);
    b_pf_els_ctf_tk_charge_->GetEntry(entry_);
    c_pf_els_ctf_tk_charge_ = true;
  }
  return pf_els_ctf_tk_charge_;
}

std::vector<float>* const & cfa_8::pf_els_ctf_tk_eta() const{
  if(!c_pf_els_ctf_tk_eta_ && b_pf_els_ctf_tk_eta_){
    b_pf_els_ctf_tk_eta_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_ctf_tk_eta", &pf_els_ctf_tk_eta_, &b_pf_els_ctf_tk_eta_);
    b_pf_els_ctf_tk_eta_->GetEntry(entry_);
    c_pf_els_ctf_tk_eta_ = true;
  }
  return pf_els_ctf_tk_eta_;
}

std::vector<float>* const & cfa_8::pf_els_ctf_tk_id() const{
  if(!c_pf_els_ctf_tk_id_ && b_pf_els_ctf_tk_id_){
    b_pf_els_ctf_tk_id_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_ctf_tk_id", &pf_els_ctf_tk_id_, &b_pf_els_ctf_tk_id_);
    b_pf_els_ctf_tk_id_->GetEntry(entry_);
    c_pf_els_ctf_tk_id_ = true;
  }
  return pf_els_ctf_tk_id_;
}

std::vector<float>* const & cfa_8::pf_els_ctf_tk_phi() const{
  if(!c_pf_els_ctf_tk_phi_ && b_pf_els_ctf_tk_phi_){
    b_pf_els_ctf_tk_phi_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_ctf_tk_phi", &pf_els_ctf_tk_phi_, &b_pf_els_ctf_tk_phi_);
    b_pf_els_ctf_tk_phi_->GetEntry(entry_);
    c_pf_els_ctf_tk_phi_ = true;
  }
  return pf_els_ctf_tk_phi_;
}

std::vector<float>* const & cfa_8::pf_els_cx() const{
  if(!c_pf_els_cx_ && b_pf_els_cx_){
    b_pf_els_cx_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_cx", &pf_els_cx_, &b_pf_els_cx_);
    b_pf_els_cx_->GetEntry(entry_);
    c_pf_els_cx_ = true;
  }
  return pf_els_cx_;
}

std::vector<float>* const & cfa_8::pf_els_cy() const{
  if(!c_pf_els_cy_ && b_pf_els_cy_){
    b_pf_els_cy_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_cy", &pf_els_cy_, &b_pf_els_cy_);
    b_pf_els_cy_->GetEntry(entry_);
    c_pf_els_cy_ = true;
  }
  return pf_els_cy_;
}

std::vector<float>* const & cfa_8::pf_els_cz() const{
  if(!c_pf_els_cz_ && b_pf_els_cz_){
    b_pf_els_cz_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_cz", &pf_els_cz_, &b_pf_els_cz_);
    b_pf_els_cz_->GetEntry(entry_);
    c_pf_els_cz_ = true;
  }
  return pf_els_cz_;
}

std::vector<float>* const & cfa_8::pf_els_d0dum() const{
  if(!c_pf_els_d0dum_ && b_pf_els_d0dum_){
    b_pf_els_d0dum_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_d0dum", &pf_els_d0dum_, &b_pf_els_d0dum_);
    b_pf_els_d0dum_->GetEntry(entry_);
    c_pf_els_d0dum_ = true;
  }
  return pf_els_d0dum_;
}

std::vector<float>* const & cfa_8::pf_els_d0dumError() const{
  if(!c_pf_els_d0dumError_ && b_pf_els_d0dumError_){
    b_pf_els_d0dumError_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_d0dumError", &pf_els_d0dumError_, &b_pf_els_d0dumError_);
    b_pf_els_d0dumError_->GetEntry(entry_);
    c_pf_els_d0dumError_ = true;
  }
  return pf_els_d0dumError_;
}

std::vector<float>* const & cfa_8::pf_els_dEtaIn() const{
  if(!c_pf_els_dEtaIn_ && b_pf_els_dEtaIn_){
    b_pf_els_dEtaIn_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_dEtaIn", &pf_els_dEtaIn_, &b_pf_els_dEtaIn_);
    b_pf_els_dEtaIn_->GetEntry(entry_);
    c_pf_els_dEtaIn_ = true;
  }
  return pf_els_dEtaIn_;
}

std::vector<float>* const & cfa_8::pf_els_dEtaOut() const{
  if(!c_pf_els_dEtaOut_ && b_pf_els_dEtaOut_){
    b_pf_els_dEtaOut_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_dEtaOut", &pf_els_dEtaOut_, &b_pf_els_dEtaOut_);
    b_pf_els_dEtaOut_->GetEntry(entry_);
    c_pf_els_dEtaOut_ = true;
  }
  return pf_els_dEtaOut_;
}

std::vector<float>* const & cfa_8::pf_els_dPhiIn() const{
  if(!c_pf_els_dPhiIn_ && b_pf_els_dPhiIn_){
    b_pf_els_dPhiIn_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_dPhiIn", &pf_els_dPhiIn_, &b_pf_els_dPhiIn_);
    b_pf_els_dPhiIn_->GetEntry(entry_);
    c_pf_els_dPhiIn_ = true;
  }
  return pf_els_dPhiIn_;
}

std::vector<float>* const & cfa_8::pf_els_dPhiOut() const{
  if(!c_pf_els_dPhiOut_ && b_pf_els_dPhiOut_){
    b_pf_els_dPhiOut_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_dPhiOut", &pf_els_dPhiOut_, &b_pf_els_dPhiOut_);
    b_pf_els_dPhiOut_->GetEntry(entry_);
    c_pf_els_dPhiOut_ = true;
  }
  return pf_els_dPhiOut_;
}

std::vector<float>* const & cfa_8::pf_els_dr03EcalRecHitSumEt() const{
  if(!c_pf_els_dr03EcalRecHitSumEt_ && b_pf_els_dr03EcalRecHitSumEt_){
    b_pf_els_dr03EcalRecHitSumEt_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_dr03EcalRecHitSumEt", &pf_els_dr03EcalRecHitSumEt_, &b_pf_els_dr03EcalRecHitSumEt_);
    b_pf_els_dr03EcalRecHitSumEt_->GetEntry(entry_);
    c_pf_els_dr03EcalRecHitSumEt_ = true;
  }
  return pf_els_dr03EcalRecHitSumEt_;
}

std::vector<float>* const & cfa_8::pf_els_dr03HcalDepth1TowerSumEt() const{
  if(!c_pf_els_dr03HcalDepth1TowerSumEt_ && b_pf_els_dr03HcalDepth1TowerSumEt_){
    b_pf_els_dr03HcalDepth1TowerSumEt_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_dr03HcalDepth1TowerSumEt", &pf_els_dr03HcalDepth1TowerSumEt_, &b_pf_els_dr03HcalDepth1TowerSumEt_);
    b_pf_els_dr03HcalDepth1TowerSumEt_->GetEntry(entry_);
    c_pf_els_dr03HcalDepth1TowerSumEt_ = true;
  }
  return pf_els_dr03HcalDepth1TowerSumEt_;
}

std::vector<float>* const & cfa_8::pf_els_dr03HcalDepth2TowerSumEt() const{
  if(!c_pf_els_dr03HcalDepth2TowerSumEt_ && b_pf_els_dr03HcalDepth2TowerSumEt_){
    b_pf_els_dr03HcalDepth2TowerSumEt_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_dr03HcalDepth2TowerSumEt", &pf_els_dr03HcalDepth2TowerSumEt_, &b_pf_els_dr03HcalDepth2TowerSumEt_);
    b_pf_els_dr03HcalDepth2TowerSumEt_->GetEntry(entry_);
    c_pf_els_dr03HcalDepth2TowerSumEt_ = true;
  }
  return pf_els_dr03HcalDepth2TowerSumEt_;
}

std::vector<float>* const & cfa_8::pf_els_dr03HcalTowerSumEt() const{
  if(!c_pf_els_dr03HcalTowerSumEt_ && b_pf_els_dr03HcalTowerSumEt_){
    b_pf_els_dr03HcalTowerSumEt_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_dr03HcalTowerSumEt", &pf_els_dr03HcalTowerSumEt_, &b_pf_els_dr03HcalTowerSumEt_);
    b_pf_els_dr03HcalTowerSumEt_->GetEntry(entry_);
    c_pf_els_dr03HcalTowerSumEt_ = true;
  }
  return pf_els_dr03HcalTowerSumEt_;
}

std::vector<float>* const & cfa_8::pf_els_dr03TkSumPt() const{
  if(!c_pf_els_dr03TkSumPt_ && b_pf_els_dr03TkSumPt_){
    b_pf_els_dr03TkSumPt_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_dr03TkSumPt", &pf_els_dr03TkSumPt_, &b_pf_els_dr03TkSumPt_);
    b_pf_els_dr03TkSumPt_->GetEntry(entry_);
    c_pf_els_dr03TkSumPt_ = true;
  }
  return pf_els_dr03TkSumPt_;
}

std::vector<float>* const & cfa_8::pf_els_dr04EcalRecHitSumEt() const{
  if(!c_pf_els_dr04EcalRecHitSumEt_ && b_pf_els_dr04EcalRecHitSumEt_){
    b_pf_els_dr04EcalRecHitSumEt_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_dr04EcalRecHitSumEt", &pf_els_dr04EcalRecHitSumEt_, &b_pf_els_dr04EcalRecHitSumEt_);
    b_pf_els_dr04EcalRecHitSumEt_->GetEntry(entry_);
    c_pf_els_dr04EcalRecHitSumEt_ = true;
  }
  return pf_els_dr04EcalRecHitSumEt_;
}

std::vector<float>* const & cfa_8::pf_els_dr04HcalDepth1TowerSumEt() const{
  if(!c_pf_els_dr04HcalDepth1TowerSumEt_ && b_pf_els_dr04HcalDepth1TowerSumEt_){
    b_pf_els_dr04HcalDepth1TowerSumEt_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_dr04HcalDepth1TowerSumEt", &pf_els_dr04HcalDepth1TowerSumEt_, &b_pf_els_dr04HcalDepth1TowerSumEt_);
    b_pf_els_dr04HcalDepth1TowerSumEt_->GetEntry(entry_);
    c_pf_els_dr04HcalDepth1TowerSumEt_ = true;
  }
  return pf_els_dr04HcalDepth1TowerSumEt_;
}

std::vector<float>* const & cfa_8::pf_els_dr04HcalDepth2TowerSumEt() const{
  if(!c_pf_els_dr04HcalDepth2TowerSumEt_ && b_pf_els_dr04HcalDepth2TowerSumEt_){
    b_pf_els_dr04HcalDepth2TowerSumEt_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_dr04HcalDepth2TowerSumEt", &pf_els_dr04HcalDepth2TowerSumEt_, &b_pf_els_dr04HcalDepth2TowerSumEt_);
    b_pf_els_dr04HcalDepth2TowerSumEt_->GetEntry(entry_);
    c_pf_els_dr04HcalDepth2TowerSumEt_ = true;
  }
  return pf_els_dr04HcalDepth2TowerSumEt_;
}

std::vector<float>* const & cfa_8::pf_els_dr04HcalTowerSumEt() const{
  if(!c_pf_els_dr04HcalTowerSumEt_ && b_pf_els_dr04HcalTowerSumEt_){
    b_pf_els_dr04HcalTowerSumEt_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_dr04HcalTowerSumEt", &pf_els_dr04HcalTowerSumEt_, &b_pf_els_dr04HcalTowerSumEt_);
    b_pf_els_dr04HcalTowerSumEt_->GetEntry(entry_);
    c_pf_els_dr04HcalTowerSumEt_ = true;
  }
  return pf_els_dr04HcalTowerSumEt_;
}

std::vector<float>* const & cfa_8::pf_els_dr04TkSumPt() const{
  if(!c_pf_els_dr04TkSumPt_ && b_pf_els_dr04TkSumPt_){
    b_pf_els_dr04TkSumPt_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_dr04TkSumPt", &pf_els_dr04TkSumPt_, &b_pf_els_dr04TkSumPt_);
    b_pf_els_dr04TkSumPt_->GetEntry(entry_);
    c_pf_els_dr04TkSumPt_ = true;
  }
  return pf_els_dr04TkSumPt_;
}

std::vector<float>* const & cfa_8::pf_els_dz() const{
  if(!c_pf_els_dz_ && b_pf_els_dz_){
    b_pf_els_dz_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_dz", &pf_els_dz_, &b_pf_els_dz_);
    b_pf_els_dz_->GetEntry(entry_);
    c_pf_els_dz_ = true;
  }
  return pf_els_dz_;
}

std::vector<float>* const & cfa_8::pf_els_dzError() const{
  if(!c_pf_els_dzError_ && b_pf_els_dzError_){
    b_pf_els_dzError_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_dzError", &pf_els_dzError_, &b_pf_els_dzError_);
    b_pf_els_dzError_->GetEntry(entry_);
    c_pf_els_dzError_ = true;
  }
  return pf_els_dzError_;
}

std::vector<float>* const & cfa_8::pf_els_eOverPIn() const{
  if(!c_pf_els_eOverPIn_ && b_pf_els_eOverPIn_){
    b_pf_els_eOverPIn_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_eOverPIn", &pf_els_eOverPIn_, &b_pf_els_eOverPIn_);
    b_pf_els_eOverPIn_->GetEntry(entry_);
    c_pf_els_eOverPIn_ = true;
  }
  return pf_els_eOverPIn_;
}

std::vector<float>* const & cfa_8::pf_els_eSeedOverPOut() const{
  if(!c_pf_els_eSeedOverPOut_ && b_pf_els_eSeedOverPOut_){
    b_pf_els_eSeedOverPOut_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_eSeedOverPOut", &pf_els_eSeedOverPOut_, &b_pf_els_eSeedOverPOut_);
    b_pf_els_eSeedOverPOut_->GetEntry(entry_);
    c_pf_els_eSeedOverPOut_ = true;
  }
  return pf_els_eSeedOverPOut_;
}

std::vector<float>* const & cfa_8::pf_els_ecalIso() const{
  if(!c_pf_els_ecalIso_ && b_pf_els_ecalIso_){
    b_pf_els_ecalIso_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_ecalIso", &pf_els_ecalIso_, &b_pf_els_ecalIso_);
    b_pf_els_ecalIso_->GetEntry(entry_);
    c_pf_els_ecalIso_ = true;
  }
  return pf_els_ecalIso_;
}

std::vector<float>* const & cfa_8::pf_els_energy() const{
  if(!c_pf_els_energy_ && b_pf_els_energy_){
    b_pf_els_energy_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_energy", &pf_els_energy_, &b_pf_els_energy_);
    b_pf_els_energy_->GetEntry(entry_);
    c_pf_els_energy_ = true;
  }
  return pf_els_energy_;
}

std::vector<float>* const & cfa_8::pf_els_et() const{
  if(!c_pf_els_et_ && b_pf_els_et_){
    b_pf_els_et_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_et", &pf_els_et_, &b_pf_els_et_);
    b_pf_els_et_->GetEntry(entry_);
    c_pf_els_et_ = true;
  }
  return pf_els_et_;
}

std::vector<float>* const & cfa_8::pf_els_eta() const{
  if(!c_pf_els_eta_ && b_pf_els_eta_){
    b_pf_els_eta_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_eta", &pf_els_eta_, &b_pf_els_eta_);
    b_pf_els_eta_->GetEntry(entry_);
    c_pf_els_eta_ = true;
  }
  return pf_els_eta_;
}

std::vector<float>* const & cfa_8::pf_els_etaError() const{
  if(!c_pf_els_etaError_ && b_pf_els_etaError_){
    b_pf_els_etaError_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_etaError", &pf_els_etaError_, &b_pf_els_etaError_);
    b_pf_els_etaError_->GetEntry(entry_);
    c_pf_els_etaError_ = true;
  }
  return pf_els_etaError_;
}

std::vector<float>* const & cfa_8::pf_els_fbrem() const{
  if(!c_pf_els_fbrem_ && b_pf_els_fbrem_){
    b_pf_els_fbrem_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_fbrem", &pf_els_fbrem_, &b_pf_els_fbrem_);
    b_pf_els_fbrem_->GetEntry(entry_);
    c_pf_els_fbrem_ = true;
  }
  return pf_els_fbrem_;
}

std::vector<float>* const & cfa_8::pf_els_gen_et() const{
  if(!c_pf_els_gen_et_ && b_pf_els_gen_et_){
    b_pf_els_gen_et_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_gen_et", &pf_els_gen_et_, &b_pf_els_gen_et_);
    b_pf_els_gen_et_->GetEntry(entry_);
    c_pf_els_gen_et_ = true;
  }
  return pf_els_gen_et_;
}

std::vector<float>* const & cfa_8::pf_els_gen_eta() const{
  if(!c_pf_els_gen_eta_ && b_pf_els_gen_eta_){
    b_pf_els_gen_eta_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_gen_eta", &pf_els_gen_eta_, &b_pf_els_gen_eta_);
    b_pf_els_gen_eta_->GetEntry(entry_);
    c_pf_els_gen_eta_ = true;
  }
  return pf_els_gen_eta_;
}

std::vector<float>* const & cfa_8::pf_els_gen_id() const{
  if(!c_pf_els_gen_id_ && b_pf_els_gen_id_){
    b_pf_els_gen_id_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_gen_id", &pf_els_gen_id_, &b_pf_els_gen_id_);
    b_pf_els_gen_id_->GetEntry(entry_);
    c_pf_els_gen_id_ = true;
  }
  return pf_els_gen_id_;
}

std::vector<float>* const & cfa_8::pf_els_gen_mother_et() const{
  if(!c_pf_els_gen_mother_et_ && b_pf_els_gen_mother_et_){
    b_pf_els_gen_mother_et_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_gen_mother_et", &pf_els_gen_mother_et_, &b_pf_els_gen_mother_et_);
    b_pf_els_gen_mother_et_->GetEntry(entry_);
    c_pf_els_gen_mother_et_ = true;
  }
  return pf_els_gen_mother_et_;
}

std::vector<float>* const & cfa_8::pf_els_gen_mother_eta() const{
  if(!c_pf_els_gen_mother_eta_ && b_pf_els_gen_mother_eta_){
    b_pf_els_gen_mother_eta_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_gen_mother_eta", &pf_els_gen_mother_eta_, &b_pf_els_gen_mother_eta_);
    b_pf_els_gen_mother_eta_->GetEntry(entry_);
    c_pf_els_gen_mother_eta_ = true;
  }
  return pf_els_gen_mother_eta_;
}

std::vector<float>* const & cfa_8::pf_els_gen_mother_id() const{
  if(!c_pf_els_gen_mother_id_ && b_pf_els_gen_mother_id_){
    b_pf_els_gen_mother_id_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_gen_mother_id", &pf_els_gen_mother_id_, &b_pf_els_gen_mother_id_);
    b_pf_els_gen_mother_id_->GetEntry(entry_);
    c_pf_els_gen_mother_id_ = true;
  }
  return pf_els_gen_mother_id_;
}

std::vector<float>* const & cfa_8::pf_els_gen_mother_phi() const{
  if(!c_pf_els_gen_mother_phi_ && b_pf_els_gen_mother_phi_){
    b_pf_els_gen_mother_phi_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_gen_mother_phi", &pf_els_gen_mother_phi_, &b_pf_els_gen_mother_phi_);
    b_pf_els_gen_mother_phi_->GetEntry(entry_);
    c_pf_els_gen_mother_phi_ = true;
  }
  return pf_els_gen_mother_phi_;
}

std::vector<float>* const & cfa_8::pf_els_gen_mother_pt() const{
  if(!c_pf_els_gen_mother_pt_ && b_pf_els_gen_mother_pt_){
    b_pf_els_gen_mother_pt_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_gen_mother_pt", &pf_els_gen_mother_pt_, &b_pf_els_gen_mother_pt_);
    b_pf_els_gen_mother_pt_->GetEntry(entry_);
    c_pf_els_gen_mother_pt_ = true;
  }
  return pf_els_gen_mother_pt_;
}

std::vector<float>* const & cfa_8::pf_els_gen_mother_px() const{
  if(!c_pf_els_gen_mother_px_ && b_pf_els_gen_mother_px_){
    b_pf_els_gen_mother_px_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_gen_mother_px", &pf_els_gen_mother_px_, &b_pf_els_gen_mother_px_);
    b_pf_els_gen_mother_px_->GetEntry(entry_);
    c_pf_els_gen_mother_px_ = true;
  }
  return pf_els_gen_mother_px_;
}

std::vector<float>* const & cfa_8::pf_els_gen_mother_py() const{
  if(!c_pf_els_gen_mother_py_ && b_pf_els_gen_mother_py_){
    b_pf_els_gen_mother_py_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_gen_mother_py", &pf_els_gen_mother_py_, &b_pf_els_gen_mother_py_);
    b_pf_els_gen_mother_py_->GetEntry(entry_);
    c_pf_els_gen_mother_py_ = true;
  }
  return pf_els_gen_mother_py_;
}

std::vector<float>* const & cfa_8::pf_els_gen_mother_pz() const{
  if(!c_pf_els_gen_mother_pz_ && b_pf_els_gen_mother_pz_){
    b_pf_els_gen_mother_pz_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_gen_mother_pz", &pf_els_gen_mother_pz_, &b_pf_els_gen_mother_pz_);
    b_pf_els_gen_mother_pz_->GetEntry(entry_);
    c_pf_els_gen_mother_pz_ = true;
  }
  return pf_els_gen_mother_pz_;
}

std::vector<float>* const & cfa_8::pf_els_gen_mother_theta() const{
  if(!c_pf_els_gen_mother_theta_ && b_pf_els_gen_mother_theta_){
    b_pf_els_gen_mother_theta_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_gen_mother_theta", &pf_els_gen_mother_theta_, &b_pf_els_gen_mother_theta_);
    b_pf_els_gen_mother_theta_->GetEntry(entry_);
    c_pf_els_gen_mother_theta_ = true;
  }
  return pf_els_gen_mother_theta_;
}

std::vector<float>* const & cfa_8::pf_els_gen_phi() const{
  if(!c_pf_els_gen_phi_ && b_pf_els_gen_phi_){
    b_pf_els_gen_phi_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_gen_phi", &pf_els_gen_phi_, &b_pf_els_gen_phi_);
    b_pf_els_gen_phi_->GetEntry(entry_);
    c_pf_els_gen_phi_ = true;
  }
  return pf_els_gen_phi_;
}

std::vector<float>* const & cfa_8::pf_els_gen_pt() const{
  if(!c_pf_els_gen_pt_ && b_pf_els_gen_pt_){
    b_pf_els_gen_pt_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_gen_pt", &pf_els_gen_pt_, &b_pf_els_gen_pt_);
    b_pf_els_gen_pt_->GetEntry(entry_);
    c_pf_els_gen_pt_ = true;
  }
  return pf_els_gen_pt_;
}

std::vector<float>* const & cfa_8::pf_els_gen_px() const{
  if(!c_pf_els_gen_px_ && b_pf_els_gen_px_){
    b_pf_els_gen_px_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_gen_px", &pf_els_gen_px_, &b_pf_els_gen_px_);
    b_pf_els_gen_px_->GetEntry(entry_);
    c_pf_els_gen_px_ = true;
  }
  return pf_els_gen_px_;
}

std::vector<float>* const & cfa_8::pf_els_gen_py() const{
  if(!c_pf_els_gen_py_ && b_pf_els_gen_py_){
    b_pf_els_gen_py_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_gen_py", &pf_els_gen_py_, &b_pf_els_gen_py_);
    b_pf_els_gen_py_->GetEntry(entry_);
    c_pf_els_gen_py_ = true;
  }
  return pf_els_gen_py_;
}

std::vector<float>* const & cfa_8::pf_els_gen_pz() const{
  if(!c_pf_els_gen_pz_ && b_pf_els_gen_pz_){
    b_pf_els_gen_pz_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_gen_pz", &pf_els_gen_pz_, &b_pf_els_gen_pz_);
    b_pf_els_gen_pz_->GetEntry(entry_);
    c_pf_els_gen_pz_ = true;
  }
  return pf_els_gen_pz_;
}

std::vector<float>* const & cfa_8::pf_els_gen_theta() const{
  if(!c_pf_els_gen_theta_ && b_pf_els_gen_theta_){
    b_pf_els_gen_theta_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_gen_theta", &pf_els_gen_theta_, &b_pf_els_gen_theta_);
    b_pf_els_gen_theta_->GetEntry(entry_);
    c_pf_els_gen_theta_ = true;
  }
  return pf_els_gen_theta_;
}

std::vector<float>* const & cfa_8::pf_els_hadOverEm() const{
  if(!c_pf_els_hadOverEm_ && b_pf_els_hadOverEm_){
    b_pf_els_hadOverEm_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_hadOverEm", &pf_els_hadOverEm_, &b_pf_els_hadOverEm_);
    b_pf_els_hadOverEm_->GetEntry(entry_);
    c_pf_els_hadOverEm_ = true;
  }
  return pf_els_hadOverEm_;
}

std::vector<bool>* const & cfa_8::pf_els_hasMatchedConversion() const{
  if(!c_pf_els_hasMatchedConversion_ && b_pf_els_hasMatchedConversion_){
    b_pf_els_hasMatchedConversion_->SetStatus(true);
    chainA_.SetBranchAddress("pf_els_hasMatchedConversion", &pf_els_hasMatchedConversion_, &b_pf_els_hasMatchedConversion_);
    b_pf_els_hasMatchedConversion_->GetEntry(entry_);
    c_pf_els_hasMatchedConversion_ = true;
  }
  return pf_els_hasMatchedConversion_;
}

std::vector<float>* const & cfa_8::pf_els_hcalIso() const{
  if(!c_pf_els_hcalIso_ && b_pf_els_hcalIso_){
    b_pf_els_hcalIso_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_hcalIso", &pf_els_hcalIso_, &b_pf_els_hcalIso_);
    b_pf_els_hcalIso_->GetEntry(entry_);
    c_pf_els_hcalIso_ = true;
  }
  return pf_els_hcalIso_;
}

std::vector<float>* const & cfa_8::pf_els_hcalOverEcalBc() const{
  if(!c_pf_els_hcalOverEcalBc_ && b_pf_els_hcalOverEcalBc_){
    b_pf_els_hcalOverEcalBc_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_hcalOverEcalBc", &pf_els_hcalOverEcalBc_, &b_pf_els_hcalOverEcalBc_);
    b_pf_els_hcalOverEcalBc_->GetEntry(entry_);
    c_pf_els_hcalOverEcalBc_ = true;
  }
  return pf_els_hcalOverEcalBc_;
}

std::vector<float>* const & cfa_8::pf_els_isEB() const{
  if(!c_pf_els_isEB_ && b_pf_els_isEB_){
    b_pf_els_isEB_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_isEB", &pf_els_isEB_, &b_pf_els_isEB_);
    b_pf_els_isEB_->GetEntry(entry_);
    c_pf_els_isEB_ = true;
  }
  return pf_els_isEB_;
}

std::vector<float>* const & cfa_8::pf_els_isEE() const{
  if(!c_pf_els_isEE_ && b_pf_els_isEE_){
    b_pf_els_isEE_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_isEE", &pf_els_isEE_, &b_pf_els_isEE_);
    b_pf_els_isEE_->GetEntry(entry_);
    c_pf_els_isEE_ = true;
  }
  return pf_els_isEE_;
}

std::vector<float>* const & cfa_8::pf_els_looseId() const{
  if(!c_pf_els_looseId_ && b_pf_els_looseId_){
    b_pf_els_looseId_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_looseId", &pf_els_looseId_, &b_pf_els_looseId_);
    b_pf_els_looseId_->GetEntry(entry_);
    c_pf_els_looseId_ = true;
  }
  return pf_els_looseId_;
}

std::vector<float>* const & cfa_8::pf_els_n_inner_layer() const{
  if(!c_pf_els_n_inner_layer_ && b_pf_els_n_inner_layer_){
    b_pf_els_n_inner_layer_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_n_inner_layer", &pf_els_n_inner_layer_, &b_pf_els_n_inner_layer_);
    b_pf_els_n_inner_layer_->GetEntry(entry_);
    c_pf_els_n_inner_layer_ = true;
  }
  return pf_els_n_inner_layer_;
}

std::vector<float>* const & cfa_8::pf_els_n_outer_layer() const{
  if(!c_pf_els_n_outer_layer_ && b_pf_els_n_outer_layer_){
    b_pf_els_n_outer_layer_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_n_outer_layer", &pf_els_n_outer_layer_, &b_pf_els_n_outer_layer_);
    b_pf_els_n_outer_layer_->GetEntry(entry_);
    c_pf_els_n_outer_layer_ = true;
  }
  return pf_els_n_outer_layer_;
}

std::vector<float>* const & cfa_8::pf_els_ndof() const{
  if(!c_pf_els_ndof_ && b_pf_els_ndof_){
    b_pf_els_ndof_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_ndof", &pf_els_ndof_, &b_pf_els_ndof_);
    b_pf_els_ndof_->GetEntry(entry_);
    c_pf_els_ndof_ = true;
  }
  return pf_els_ndof_;
}

std::vector<float>* const & cfa_8::pf_els_neutralHadronIso() const{
  if(!c_pf_els_neutralHadronIso_ && b_pf_els_neutralHadronIso_){
    b_pf_els_neutralHadronIso_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_neutralHadronIso", &pf_els_neutralHadronIso_, &b_pf_els_neutralHadronIso_);
    b_pf_els_neutralHadronIso_->GetEntry(entry_);
    c_pf_els_neutralHadronIso_ = true;
  }
  return pf_els_neutralHadronIso_;
}

std::vector<float>* const & cfa_8::pf_els_numlosthits() const{
  if(!c_pf_els_numlosthits_ && b_pf_els_numlosthits_){
    b_pf_els_numlosthits_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_numlosthits", &pf_els_numlosthits_, &b_pf_els_numlosthits_);
    b_pf_els_numlosthits_->GetEntry(entry_);
    c_pf_els_numlosthits_ = true;
  }
  return pf_els_numlosthits_;
}

std::vector<float>* const & cfa_8::pf_els_numvalhits() const{
  if(!c_pf_els_numvalhits_ && b_pf_els_numvalhits_){
    b_pf_els_numvalhits_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_numvalhits", &pf_els_numvalhits_, &b_pf_els_numvalhits_);
    b_pf_els_numvalhits_->GetEntry(entry_);
    c_pf_els_numvalhits_ = true;
  }
  return pf_els_numvalhits_;
}

std::vector<float>* const & cfa_8::pf_els_phi() const{
  if(!c_pf_els_phi_ && b_pf_els_phi_){
    b_pf_els_phi_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_phi", &pf_els_phi_, &b_pf_els_phi_);
    b_pf_els_phi_->GetEntry(entry_);
    c_pf_els_phi_ = true;
  }
  return pf_els_phi_;
}

std::vector<float>* const & cfa_8::pf_els_phiError() const{
  if(!c_pf_els_phiError_ && b_pf_els_phiError_){
    b_pf_els_phiError_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_phiError", &pf_els_phiError_, &b_pf_els_phiError_);
    b_pf_els_phiError_->GetEntry(entry_);
    c_pf_els_phiError_ = true;
  }
  return pf_els_phiError_;
}

std::vector<float>* const & cfa_8::pf_els_photonIso() const{
  if(!c_pf_els_photonIso_ && b_pf_els_photonIso_){
    b_pf_els_photonIso_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_photonIso", &pf_els_photonIso_, &b_pf_els_photonIso_);
    b_pf_els_photonIso_->GetEntry(entry_);
    c_pf_els_photonIso_ = true;
  }
  return pf_els_photonIso_;
}

std::vector<float>* const & cfa_8::pf_els_pt() const{
  if(!c_pf_els_pt_ && b_pf_els_pt_){
    b_pf_els_pt_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_pt", &pf_els_pt_, &b_pf_els_pt_);
    b_pf_els_pt_->GetEntry(entry_);
    c_pf_els_pt_ = true;
  }
  return pf_els_pt_;
}

std::vector<float>* const & cfa_8::pf_els_ptError() const{
  if(!c_pf_els_ptError_ && b_pf_els_ptError_){
    b_pf_els_ptError_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_ptError", &pf_els_ptError_, &b_pf_els_ptError_);
    b_pf_els_ptError_->GetEntry(entry_);
    c_pf_els_ptError_ = true;
  }
  return pf_els_ptError_;
}

std::vector<float>* const & cfa_8::pf_els_px() const{
  if(!c_pf_els_px_ && b_pf_els_px_){
    b_pf_els_px_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_px", &pf_els_px_, &b_pf_els_px_);
    b_pf_els_px_->GetEntry(entry_);
    c_pf_els_px_ = true;
  }
  return pf_els_px_;
}

std::vector<float>* const & cfa_8::pf_els_py() const{
  if(!c_pf_els_py_ && b_pf_els_py_){
    b_pf_els_py_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_py", &pf_els_py_, &b_pf_els_py_);
    b_pf_els_py_->GetEntry(entry_);
    c_pf_els_py_ = true;
  }
  return pf_els_py_;
}

std::vector<float>* const & cfa_8::pf_els_pz() const{
  if(!c_pf_els_pz_ && b_pf_els_pz_){
    b_pf_els_pz_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_pz", &pf_els_pz_, &b_pf_els_pz_);
    b_pf_els_pz_->GetEntry(entry_);
    c_pf_els_pz_ = true;
  }
  return pf_els_pz_;
}

std::vector<float>* const & cfa_8::pf_els_robustHighEnergyId() const{
  if(!c_pf_els_robustHighEnergyId_ && b_pf_els_robustHighEnergyId_){
    b_pf_els_robustHighEnergyId_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_robustHighEnergyId", &pf_els_robustHighEnergyId_, &b_pf_els_robustHighEnergyId_);
    b_pf_els_robustHighEnergyId_->GetEntry(entry_);
    c_pf_els_robustHighEnergyId_ = true;
  }
  return pf_els_robustHighEnergyId_;
}

std::vector<float>* const & cfa_8::pf_els_robustLooseId() const{
  if(!c_pf_els_robustLooseId_ && b_pf_els_robustLooseId_){
    b_pf_els_robustLooseId_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_robustLooseId", &pf_els_robustLooseId_, &b_pf_els_robustLooseId_);
    b_pf_els_robustLooseId_->GetEntry(entry_);
    c_pf_els_robustLooseId_ = true;
  }
  return pf_els_robustLooseId_;
}

std::vector<float>* const & cfa_8::pf_els_robustTightId() const{
  if(!c_pf_els_robustTightId_ && b_pf_els_robustTightId_){
    b_pf_els_robustTightId_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_robustTightId", &pf_els_robustTightId_, &b_pf_els_robustTightId_);
    b_pf_els_robustTightId_->GetEntry(entry_);
    c_pf_els_robustTightId_ = true;
  }
  return pf_els_robustTightId_;
}

std::vector<float>* const & cfa_8::pf_els_scE1x5() const{
  if(!c_pf_els_scE1x5_ && b_pf_els_scE1x5_){
    b_pf_els_scE1x5_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_scE1x5", &pf_els_scE1x5_, &b_pf_els_scE1x5_);
    b_pf_els_scE1x5_->GetEntry(entry_);
    c_pf_els_scE1x5_ = true;
  }
  return pf_els_scE1x5_;
}

std::vector<float>* const & cfa_8::pf_els_scE2x5Max() const{
  if(!c_pf_els_scE2x5Max_ && b_pf_els_scE2x5Max_){
    b_pf_els_scE2x5Max_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_scE2x5Max", &pf_els_scE2x5Max_, &b_pf_els_scE2x5Max_);
    b_pf_els_scE2x5Max_->GetEntry(entry_);
    c_pf_els_scE2x5Max_ = true;
  }
  return pf_els_scE2x5Max_;
}

std::vector<float>* const & cfa_8::pf_els_scE5x5() const{
  if(!c_pf_els_scE5x5_ && b_pf_els_scE5x5_){
    b_pf_els_scE5x5_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_scE5x5", &pf_els_scE5x5_, &b_pf_els_scE5x5_);
    b_pf_els_scE5x5_->GetEntry(entry_);
    c_pf_els_scE5x5_ = true;
  }
  return pf_els_scE5x5_;
}

std::vector<float>* const & cfa_8::pf_els_scEnergy() const{
  if(!c_pf_els_scEnergy_ && b_pf_els_scEnergy_){
    b_pf_els_scEnergy_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_scEnergy", &pf_els_scEnergy_, &b_pf_els_scEnergy_);
    b_pf_els_scEnergy_->GetEntry(entry_);
    c_pf_els_scEnergy_ = true;
  }
  return pf_els_scEnergy_;
}

std::vector<float>* const & cfa_8::pf_els_scEta() const{
  if(!c_pf_els_scEta_ && b_pf_els_scEta_){
    b_pf_els_scEta_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_scEta", &pf_els_scEta_, &b_pf_els_scEta_);
    b_pf_els_scEta_->GetEntry(entry_);
    c_pf_els_scEta_ = true;
  }
  return pf_els_scEta_;
}

std::vector<float>* const & cfa_8::pf_els_scEtaWidth() const{
  if(!c_pf_els_scEtaWidth_ && b_pf_els_scEtaWidth_){
    b_pf_els_scEtaWidth_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_scEtaWidth", &pf_els_scEtaWidth_, &b_pf_els_scEtaWidth_);
    b_pf_els_scEtaWidth_->GetEntry(entry_);
    c_pf_els_scEtaWidth_ = true;
  }
  return pf_els_scEtaWidth_;
}

std::vector<float>* const & cfa_8::pf_els_scPhi() const{
  if(!c_pf_els_scPhi_ && b_pf_els_scPhi_){
    b_pf_els_scPhi_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_scPhi", &pf_els_scPhi_, &b_pf_els_scPhi_);
    b_pf_els_scPhi_->GetEntry(entry_);
    c_pf_els_scPhi_ = true;
  }
  return pf_els_scPhi_;
}

std::vector<float>* const & cfa_8::pf_els_scPhiWidth() const{
  if(!c_pf_els_scPhiWidth_ && b_pf_els_scPhiWidth_){
    b_pf_els_scPhiWidth_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_scPhiWidth", &pf_els_scPhiWidth_, &b_pf_els_scPhiWidth_);
    b_pf_els_scPhiWidth_->GetEntry(entry_);
    c_pf_els_scPhiWidth_ = true;
  }
  return pf_els_scPhiWidth_;
}

std::vector<float>* const & cfa_8::pf_els_scRawEnergy() const{
  if(!c_pf_els_scRawEnergy_ && b_pf_els_scRawEnergy_){
    b_pf_els_scRawEnergy_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_scRawEnergy", &pf_els_scRawEnergy_, &b_pf_els_scRawEnergy_);
    b_pf_els_scRawEnergy_->GetEntry(entry_);
    c_pf_els_scRawEnergy_ = true;
  }
  return pf_els_scRawEnergy_;
}

std::vector<float>* const & cfa_8::pf_els_scSeedEnergy() const{
  if(!c_pf_els_scSeedEnergy_ && b_pf_els_scSeedEnergy_){
    b_pf_els_scSeedEnergy_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_scSeedEnergy", &pf_els_scSeedEnergy_, &b_pf_els_scSeedEnergy_);
    b_pf_els_scSeedEnergy_->GetEntry(entry_);
    c_pf_els_scSeedEnergy_ = true;
  }
  return pf_els_scSeedEnergy_;
}

std::vector<float>* const & cfa_8::pf_els_shFracInnerHits() const{
  if(!c_pf_els_shFracInnerHits_ && b_pf_els_shFracInnerHits_){
    b_pf_els_shFracInnerHits_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_shFracInnerHits", &pf_els_shFracInnerHits_, &b_pf_els_shFracInnerHits_);
    b_pf_els_shFracInnerHits_->GetEntry(entry_);
    c_pf_els_shFracInnerHits_ = true;
  }
  return pf_els_shFracInnerHits_;
}

std::vector<float>* const & cfa_8::pf_els_sigmaEtaEta() const{
  if(!c_pf_els_sigmaEtaEta_ && b_pf_els_sigmaEtaEta_){
    b_pf_els_sigmaEtaEta_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_sigmaEtaEta", &pf_els_sigmaEtaEta_, &b_pf_els_sigmaEtaEta_);
    b_pf_els_sigmaEtaEta_->GetEntry(entry_);
    c_pf_els_sigmaEtaEta_ = true;
  }
  return pf_els_sigmaEtaEta_;
}

std::vector<float>* const & cfa_8::pf_els_sigmaIEtaIEta() const{
  if(!c_pf_els_sigmaIEtaIEta_ && b_pf_els_sigmaIEtaIEta_){
    b_pf_els_sigmaIEtaIEta_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_sigmaIEtaIEta", &pf_els_sigmaIEtaIEta_, &b_pf_els_sigmaIEtaIEta_);
    b_pf_els_sigmaIEtaIEta_->GetEntry(entry_);
    c_pf_els_sigmaIEtaIEta_ = true;
  }
  return pf_els_sigmaIEtaIEta_;
}

std::vector<float>* const & cfa_8::pf_els_simpleEleId60cIso() const{
  if(!c_pf_els_simpleEleId60cIso_ && b_pf_els_simpleEleId60cIso_){
    b_pf_els_simpleEleId60cIso_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_simpleEleId60cIso", &pf_els_simpleEleId60cIso_, &b_pf_els_simpleEleId60cIso_);
    b_pf_els_simpleEleId60cIso_->GetEntry(entry_);
    c_pf_els_simpleEleId60cIso_ = true;
  }
  return pf_els_simpleEleId60cIso_;
}

std::vector<float>* const & cfa_8::pf_els_simpleEleId60relIso() const{
  if(!c_pf_els_simpleEleId60relIso_ && b_pf_els_simpleEleId60relIso_){
    b_pf_els_simpleEleId60relIso_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_simpleEleId60relIso", &pf_els_simpleEleId60relIso_, &b_pf_els_simpleEleId60relIso_);
    b_pf_els_simpleEleId60relIso_->GetEntry(entry_);
    c_pf_els_simpleEleId60relIso_ = true;
  }
  return pf_els_simpleEleId60relIso_;
}

std::vector<float>* const & cfa_8::pf_els_simpleEleId70cIso() const{
  if(!c_pf_els_simpleEleId70cIso_ && b_pf_els_simpleEleId70cIso_){
    b_pf_els_simpleEleId70cIso_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_simpleEleId70cIso", &pf_els_simpleEleId70cIso_, &b_pf_els_simpleEleId70cIso_);
    b_pf_els_simpleEleId70cIso_->GetEntry(entry_);
    c_pf_els_simpleEleId70cIso_ = true;
  }
  return pf_els_simpleEleId70cIso_;
}

std::vector<float>* const & cfa_8::pf_els_simpleEleId70relIso() const{
  if(!c_pf_els_simpleEleId70relIso_ && b_pf_els_simpleEleId70relIso_){
    b_pf_els_simpleEleId70relIso_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_simpleEleId70relIso", &pf_els_simpleEleId70relIso_, &b_pf_els_simpleEleId70relIso_);
    b_pf_els_simpleEleId70relIso_->GetEntry(entry_);
    c_pf_els_simpleEleId70relIso_ = true;
  }
  return pf_els_simpleEleId70relIso_;
}

std::vector<float>* const & cfa_8::pf_els_simpleEleId80cIso() const{
  if(!c_pf_els_simpleEleId80cIso_ && b_pf_els_simpleEleId80cIso_){
    b_pf_els_simpleEleId80cIso_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_simpleEleId80cIso", &pf_els_simpleEleId80cIso_, &b_pf_els_simpleEleId80cIso_);
    b_pf_els_simpleEleId80cIso_->GetEntry(entry_);
    c_pf_els_simpleEleId80cIso_ = true;
  }
  return pf_els_simpleEleId80cIso_;
}

std::vector<float>* const & cfa_8::pf_els_simpleEleId80relIso() const{
  if(!c_pf_els_simpleEleId80relIso_ && b_pf_els_simpleEleId80relIso_){
    b_pf_els_simpleEleId80relIso_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_simpleEleId80relIso", &pf_els_simpleEleId80relIso_, &b_pf_els_simpleEleId80relIso_);
    b_pf_els_simpleEleId80relIso_->GetEntry(entry_);
    c_pf_els_simpleEleId80relIso_ = true;
  }
  return pf_els_simpleEleId80relIso_;
}

std::vector<float>* const & cfa_8::pf_els_simpleEleId85cIso() const{
  if(!c_pf_els_simpleEleId85cIso_ && b_pf_els_simpleEleId85cIso_){
    b_pf_els_simpleEleId85cIso_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_simpleEleId85cIso", &pf_els_simpleEleId85cIso_, &b_pf_els_simpleEleId85cIso_);
    b_pf_els_simpleEleId85cIso_->GetEntry(entry_);
    c_pf_els_simpleEleId85cIso_ = true;
  }
  return pf_els_simpleEleId85cIso_;
}

std::vector<float>* const & cfa_8::pf_els_simpleEleId85relIso() const{
  if(!c_pf_els_simpleEleId85relIso_ && b_pf_els_simpleEleId85relIso_){
    b_pf_els_simpleEleId85relIso_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_simpleEleId85relIso", &pf_els_simpleEleId85relIso_, &b_pf_els_simpleEleId85relIso_);
    b_pf_els_simpleEleId85relIso_->GetEntry(entry_);
    c_pf_els_simpleEleId85relIso_ = true;
  }
  return pf_els_simpleEleId85relIso_;
}

std::vector<float>* const & cfa_8::pf_els_simpleEleId90cIso() const{
  if(!c_pf_els_simpleEleId90cIso_ && b_pf_els_simpleEleId90cIso_){
    b_pf_els_simpleEleId90cIso_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_simpleEleId90cIso", &pf_els_simpleEleId90cIso_, &b_pf_els_simpleEleId90cIso_);
    b_pf_els_simpleEleId90cIso_->GetEntry(entry_);
    c_pf_els_simpleEleId90cIso_ = true;
  }
  return pf_els_simpleEleId90cIso_;
}

std::vector<float>* const & cfa_8::pf_els_simpleEleId90relIso() const{
  if(!c_pf_els_simpleEleId90relIso_ && b_pf_els_simpleEleId90relIso_){
    b_pf_els_simpleEleId90relIso_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_simpleEleId90relIso", &pf_els_simpleEleId90relIso_, &b_pf_els_simpleEleId90relIso_);
    b_pf_els_simpleEleId90relIso_->GetEntry(entry_);
    c_pf_els_simpleEleId90relIso_ = true;
  }
  return pf_els_simpleEleId90relIso_;
}

std::vector<float>* const & cfa_8::pf_els_simpleEleId95cIso() const{
  if(!c_pf_els_simpleEleId95cIso_ && b_pf_els_simpleEleId95cIso_){
    b_pf_els_simpleEleId95cIso_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_simpleEleId95cIso", &pf_els_simpleEleId95cIso_, &b_pf_els_simpleEleId95cIso_);
    b_pf_els_simpleEleId95cIso_->GetEntry(entry_);
    c_pf_els_simpleEleId95cIso_ = true;
  }
  return pf_els_simpleEleId95cIso_;
}

std::vector<float>* const & cfa_8::pf_els_simpleEleId95relIso() const{
  if(!c_pf_els_simpleEleId95relIso_ && b_pf_els_simpleEleId95relIso_){
    b_pf_els_simpleEleId95relIso_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_simpleEleId95relIso", &pf_els_simpleEleId95relIso_, &b_pf_els_simpleEleId95relIso_);
    b_pf_els_simpleEleId95relIso_->GetEntry(entry_);
    c_pf_els_simpleEleId95relIso_ = true;
  }
  return pf_els_simpleEleId95relIso_;
}

std::vector<float>* const & cfa_8::pf_els_status() const{
  if(!c_pf_els_status_ && b_pf_els_status_){
    b_pf_els_status_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_status", &pf_els_status_, &b_pf_els_status_);
    b_pf_els_status_->GetEntry(entry_);
    c_pf_els_status_ = true;
  }
  return pf_els_status_;
}

std::vector<float>* const & cfa_8::pf_els_tIso() const{
  if(!c_pf_els_tIso_ && b_pf_els_tIso_){
    b_pf_els_tIso_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_tIso", &pf_els_tIso_, &b_pf_els_tIso_);
    b_pf_els_tIso_->GetEntry(entry_);
    c_pf_els_tIso_ = true;
  }
  return pf_els_tIso_;
}

std::vector<float>* const & cfa_8::pf_els_theta() const{
  if(!c_pf_els_theta_ && b_pf_els_theta_){
    b_pf_els_theta_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_theta", &pf_els_theta_, &b_pf_els_theta_);
    b_pf_els_theta_->GetEntry(entry_);
    c_pf_els_theta_ = true;
  }
  return pf_els_theta_;
}

std::vector<float>* const & cfa_8::pf_els_tightId() const{
  if(!c_pf_els_tightId_ && b_pf_els_tightId_){
    b_pf_els_tightId_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_tightId", &pf_els_tightId_, &b_pf_els_tightId_);
    b_pf_els_tightId_->GetEntry(entry_);
    c_pf_els_tightId_ = true;
  }
  return pf_els_tightId_;
}

std::vector<float>* const & cfa_8::pf_els_tk_charge() const{
  if(!c_pf_els_tk_charge_ && b_pf_els_tk_charge_){
    b_pf_els_tk_charge_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_tk_charge", &pf_els_tk_charge_, &b_pf_els_tk_charge_);
    b_pf_els_tk_charge_->GetEntry(entry_);
    c_pf_els_tk_charge_ = true;
  }
  return pf_els_tk_charge_;
}

std::vector<float>* const & cfa_8::pf_els_tk_eta() const{
  if(!c_pf_els_tk_eta_ && b_pf_els_tk_eta_){
    b_pf_els_tk_eta_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_tk_eta", &pf_els_tk_eta_, &b_pf_els_tk_eta_);
    b_pf_els_tk_eta_->GetEntry(entry_);
    c_pf_els_tk_eta_ = true;
  }
  return pf_els_tk_eta_;
}

std::vector<float>* const & cfa_8::pf_els_tk_phi() const{
  if(!c_pf_els_tk_phi_ && b_pf_els_tk_phi_){
    b_pf_els_tk_phi_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_tk_phi", &pf_els_tk_phi_, &b_pf_els_tk_phi_);
    b_pf_els_tk_phi_->GetEntry(entry_);
    c_pf_els_tk_phi_ = true;
  }
  return pf_els_tk_phi_;
}

std::vector<float>* const & cfa_8::pf_els_tk_pt() const{
  if(!c_pf_els_tk_pt_ && b_pf_els_tk_pt_){
    b_pf_els_tk_pt_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_tk_pt", &pf_els_tk_pt_, &b_pf_els_tk_pt_);
    b_pf_els_tk_pt_->GetEntry(entry_);
    c_pf_els_tk_pt_ = true;
  }
  return pf_els_tk_pt_;
}

std::vector<float>* const & cfa_8::pf_els_tk_pz() const{
  if(!c_pf_els_tk_pz_ && b_pf_els_tk_pz_){
    b_pf_els_tk_pz_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_tk_pz", &pf_els_tk_pz_, &b_pf_els_tk_pz_);
    b_pf_els_tk_pz_->GetEntry(entry_);
    c_pf_els_tk_pz_ = true;
  }
  return pf_els_tk_pz_;
}

std::vector<float>* const & cfa_8::pf_els_vpx() const{
  if(!c_pf_els_vpx_ && b_pf_els_vpx_){
    b_pf_els_vpx_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_vpx", &pf_els_vpx_, &b_pf_els_vpx_);
    b_pf_els_vpx_->GetEntry(entry_);
    c_pf_els_vpx_ = true;
  }
  return pf_els_vpx_;
}

std::vector<float>* const & cfa_8::pf_els_vpy() const{
  if(!c_pf_els_vpy_ && b_pf_els_vpy_){
    b_pf_els_vpy_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_vpy", &pf_els_vpy_, &b_pf_els_vpy_);
    b_pf_els_vpy_->GetEntry(entry_);
    c_pf_els_vpy_ = true;
  }
  return pf_els_vpy_;
}

std::vector<float>* const & cfa_8::pf_els_vpz() const{
  if(!c_pf_els_vpz_ && b_pf_els_vpz_){
    b_pf_els_vpz_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_vpz", &pf_els_vpz_, &b_pf_els_vpz_);
    b_pf_els_vpz_->GetEntry(entry_);
    c_pf_els_vpz_ = true;
  }
  return pf_els_vpz_;
}

std::vector<float>* const & cfa_8::pf_els_vx() const{
  if(!c_pf_els_vx_ && b_pf_els_vx_){
    b_pf_els_vx_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_vx", &pf_els_vx_, &b_pf_els_vx_);
    b_pf_els_vx_->GetEntry(entry_);
    c_pf_els_vx_ = true;
  }
  return pf_els_vx_;
}

std::vector<float>* const & cfa_8::pf_els_vy() const{
  if(!c_pf_els_vy_ && b_pf_els_vy_){
    b_pf_els_vy_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_vy", &pf_els_vy_, &b_pf_els_vy_);
    b_pf_els_vy_->GetEntry(entry_);
    c_pf_els_vy_ = true;
  }
  return pf_els_vy_;
}

std::vector<float>* const & cfa_8::pf_els_vz() const{
  if(!c_pf_els_vz_ && b_pf_els_vz_){
    b_pf_els_vz_->SetStatus(true);
    chainB_.SetBranchAddress("pf_els_vz", &pf_els_vz_, &b_pf_els_vz_);
    b_pf_els_vz_->GetEntry(entry_);
    c_pf_els_vz_ = true;
  }
  return pf_els_vz_;
}

std::vector<float>* const & cfa_8::pf_mus_cIso() const{
  if(!c_pf_mus_cIso_ && b_pf_mus_cIso_){
    b_pf_mus_cIso_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_cIso", &pf_mus_cIso_, &b_pf_mus_cIso_);
    b_pf_mus_cIso_->GetEntry(entry_);
    c_pf_mus_cIso_ = true;
  }
  return pf_mus_cIso_;
}

std::vector<float>* const & cfa_8::pf_mus_calEnergyEm() const{
  if(!c_pf_mus_calEnergyEm_ && b_pf_mus_calEnergyEm_){
    b_pf_mus_calEnergyEm_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_calEnergyEm", &pf_mus_calEnergyEm_, &b_pf_mus_calEnergyEm_);
    b_pf_mus_calEnergyEm_->GetEntry(entry_);
    c_pf_mus_calEnergyEm_ = true;
  }
  return pf_mus_calEnergyEm_;
}

std::vector<float>* const & cfa_8::pf_mus_calEnergyEmS9() const{
  if(!c_pf_mus_calEnergyEmS9_ && b_pf_mus_calEnergyEmS9_){
    b_pf_mus_calEnergyEmS9_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_calEnergyEmS9", &pf_mus_calEnergyEmS9_, &b_pf_mus_calEnergyEmS9_);
    b_pf_mus_calEnergyEmS9_->GetEntry(entry_);
    c_pf_mus_calEnergyEmS9_ = true;
  }
  return pf_mus_calEnergyEmS9_;
}

std::vector<float>* const & cfa_8::pf_mus_calEnergyHad() const{
  if(!c_pf_mus_calEnergyHad_ && b_pf_mus_calEnergyHad_){
    b_pf_mus_calEnergyHad_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_calEnergyHad", &pf_mus_calEnergyHad_, &b_pf_mus_calEnergyHad_);
    b_pf_mus_calEnergyHad_->GetEntry(entry_);
    c_pf_mus_calEnergyHad_ = true;
  }
  return pf_mus_calEnergyHad_;
}

std::vector<float>* const & cfa_8::pf_mus_calEnergyHadS9() const{
  if(!c_pf_mus_calEnergyHadS9_ && b_pf_mus_calEnergyHadS9_){
    b_pf_mus_calEnergyHadS9_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_calEnergyHadS9", &pf_mus_calEnergyHadS9_, &b_pf_mus_calEnergyHadS9_);
    b_pf_mus_calEnergyHadS9_->GetEntry(entry_);
    c_pf_mus_calEnergyHadS9_ = true;
  }
  return pf_mus_calEnergyHadS9_;
}

std::vector<float>* const & cfa_8::pf_mus_calEnergyHo() const{
  if(!c_pf_mus_calEnergyHo_ && b_pf_mus_calEnergyHo_){
    b_pf_mus_calEnergyHo_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_calEnergyHo", &pf_mus_calEnergyHo_, &b_pf_mus_calEnergyHo_);
    b_pf_mus_calEnergyHo_->GetEntry(entry_);
    c_pf_mus_calEnergyHo_ = true;
  }
  return pf_mus_calEnergyHo_;
}

std::vector<float>* const & cfa_8::pf_mus_calEnergyHoS9() const{
  if(!c_pf_mus_calEnergyHoS9_ && b_pf_mus_calEnergyHoS9_){
    b_pf_mus_calEnergyHoS9_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_calEnergyHoS9", &pf_mus_calEnergyHoS9_, &b_pf_mus_calEnergyHoS9_);
    b_pf_mus_calEnergyHoS9_->GetEntry(entry_);
    c_pf_mus_calEnergyHoS9_ = true;
  }
  return pf_mus_calEnergyHoS9_;
}

std::vector<float>* const & cfa_8::pf_mus_charge() const{
  if(!c_pf_mus_charge_ && b_pf_mus_charge_){
    b_pf_mus_charge_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_charge", &pf_mus_charge_, &b_pf_mus_charge_);
    b_pf_mus_charge_->GetEntry(entry_);
    c_pf_mus_charge_ = true;
  }
  return pf_mus_charge_;
}

std::vector<float>* const & cfa_8::pf_mus_chargedHadronIso() const{
  if(!c_pf_mus_chargedHadronIso_ && b_pf_mus_chargedHadronIso_){
    b_pf_mus_chargedHadronIso_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_chargedHadronIso", &pf_mus_chargedHadronIso_, &b_pf_mus_chargedHadronIso_);
    b_pf_mus_chargedHadronIso_->GetEntry(entry_);
    c_pf_mus_chargedHadronIso_ = true;
  }
  return pf_mus_chargedHadronIso_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_ExpectedHitsInner() const{
  if(!c_pf_mus_cm_ExpectedHitsInner_ && b_pf_mus_cm_ExpectedHitsInner_){
    b_pf_mus_cm_ExpectedHitsInner_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_cm_ExpectedHitsInner", &pf_mus_cm_ExpectedHitsInner_, &b_pf_mus_cm_ExpectedHitsInner_);
    b_pf_mus_cm_ExpectedHitsInner_->GetEntry(entry_);
    c_pf_mus_cm_ExpectedHitsInner_ = true;
  }
  return pf_mus_cm_ExpectedHitsInner_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_ExpectedHitsOuter() const{
  if(!c_pf_mus_cm_ExpectedHitsOuter_ && b_pf_mus_cm_ExpectedHitsOuter_){
    b_pf_mus_cm_ExpectedHitsOuter_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_cm_ExpectedHitsOuter", &pf_mus_cm_ExpectedHitsOuter_, &b_pf_mus_cm_ExpectedHitsOuter_);
    b_pf_mus_cm_ExpectedHitsOuter_->GetEntry(entry_);
    c_pf_mus_cm_ExpectedHitsOuter_ = true;
  }
  return pf_mus_cm_ExpectedHitsOuter_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_LayersWithMeasurement() const{
  if(!c_pf_mus_cm_LayersWithMeasurement_ && b_pf_mus_cm_LayersWithMeasurement_){
    b_pf_mus_cm_LayersWithMeasurement_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_cm_LayersWithMeasurement", &pf_mus_cm_LayersWithMeasurement_, &b_pf_mus_cm_LayersWithMeasurement_);
    b_pf_mus_cm_LayersWithMeasurement_->GetEntry(entry_);
    c_pf_mus_cm_LayersWithMeasurement_ = true;
  }
  return pf_mus_cm_LayersWithMeasurement_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_LayersWithoutMeasurement() const{
  if(!c_pf_mus_cm_LayersWithoutMeasurement_ && b_pf_mus_cm_LayersWithoutMeasurement_){
    b_pf_mus_cm_LayersWithoutMeasurement_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_cm_LayersWithoutMeasurement", &pf_mus_cm_LayersWithoutMeasurement_, &b_pf_mus_cm_LayersWithoutMeasurement_);
    b_pf_mus_cm_LayersWithoutMeasurement_->GetEntry(entry_);
    c_pf_mus_cm_LayersWithoutMeasurement_ = true;
  }
  return pf_mus_cm_LayersWithoutMeasurement_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_PixelLayersWithMeasurement() const{
  if(!c_pf_mus_cm_PixelLayersWithMeasurement_ && b_pf_mus_cm_PixelLayersWithMeasurement_){
    b_pf_mus_cm_PixelLayersWithMeasurement_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_cm_PixelLayersWithMeasurement", &pf_mus_cm_PixelLayersWithMeasurement_, &b_pf_mus_cm_PixelLayersWithMeasurement_);
    b_pf_mus_cm_PixelLayersWithMeasurement_->GetEntry(entry_);
    c_pf_mus_cm_PixelLayersWithMeasurement_ = true;
  }
  return pf_mus_cm_PixelLayersWithMeasurement_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_ValidStripLayersWithMonoAndStereoHit() const{
  if(!c_pf_mus_cm_ValidStripLayersWithMonoAndStereoHit_ && b_pf_mus_cm_ValidStripLayersWithMonoAndStereoHit_){
    b_pf_mus_cm_ValidStripLayersWithMonoAndStereoHit_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_cm_ValidStripLayersWithMonoAndStereoHit", &pf_mus_cm_ValidStripLayersWithMonoAndStereoHit_, &b_pf_mus_cm_ValidStripLayersWithMonoAndStereoHit_);
    b_pf_mus_cm_ValidStripLayersWithMonoAndStereoHit_->GetEntry(entry_);
    c_pf_mus_cm_ValidStripLayersWithMonoAndStereoHit_ = true;
  }
  return pf_mus_cm_ValidStripLayersWithMonoAndStereoHit_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_chg() const{
  if(!c_pf_mus_cm_chg_ && b_pf_mus_cm_chg_){
    b_pf_mus_cm_chg_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_cm_chg", &pf_mus_cm_chg_, &b_pf_mus_cm_chg_);
    b_pf_mus_cm_chg_->GetEntry(entry_);
    c_pf_mus_cm_chg_ = true;
  }
  return pf_mus_cm_chg_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_chi2() const{
  if(!c_pf_mus_cm_chi2_ && b_pf_mus_cm_chi2_){
    b_pf_mus_cm_chi2_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_cm_chi2", &pf_mus_cm_chi2_, &b_pf_mus_cm_chi2_);
    b_pf_mus_cm_chi2_->GetEntry(entry_);
    c_pf_mus_cm_chi2_ = true;
  }
  return pf_mus_cm_chi2_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_d0dum() const{
  if(!c_pf_mus_cm_d0dum_ && b_pf_mus_cm_d0dum_){
    b_pf_mus_cm_d0dum_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_cm_d0dum", &pf_mus_cm_d0dum_, &b_pf_mus_cm_d0dum_);
    b_pf_mus_cm_d0dum_->GetEntry(entry_);
    c_pf_mus_cm_d0dum_ = true;
  }
  return pf_mus_cm_d0dum_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_d0dumErr() const{
  if(!c_pf_mus_cm_d0dumErr_ && b_pf_mus_cm_d0dumErr_){
    b_pf_mus_cm_d0dumErr_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_cm_d0dumErr", &pf_mus_cm_d0dumErr_, &b_pf_mus_cm_d0dumErr_);
    b_pf_mus_cm_d0dumErr_->GetEntry(entry_);
    c_pf_mus_cm_d0dumErr_ = true;
  }
  return pf_mus_cm_d0dumErr_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_dz() const{
  if(!c_pf_mus_cm_dz_ && b_pf_mus_cm_dz_){
    b_pf_mus_cm_dz_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_cm_dz", &pf_mus_cm_dz_, &b_pf_mus_cm_dz_);
    b_pf_mus_cm_dz_->GetEntry(entry_);
    c_pf_mus_cm_dz_ = true;
  }
  return pf_mus_cm_dz_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_dzErr() const{
  if(!c_pf_mus_cm_dzErr_ && b_pf_mus_cm_dzErr_){
    b_pf_mus_cm_dzErr_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_cm_dzErr", &pf_mus_cm_dzErr_, &b_pf_mus_cm_dzErr_);
    b_pf_mus_cm_dzErr_->GetEntry(entry_);
    c_pf_mus_cm_dzErr_ = true;
  }
  return pf_mus_cm_dzErr_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_eta() const{
  if(!c_pf_mus_cm_eta_ && b_pf_mus_cm_eta_){
    b_pf_mus_cm_eta_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_cm_eta", &pf_mus_cm_eta_, &b_pf_mus_cm_eta_);
    b_pf_mus_cm_eta_->GetEntry(entry_);
    c_pf_mus_cm_eta_ = true;
  }
  return pf_mus_cm_eta_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_etaErr() const{
  if(!c_pf_mus_cm_etaErr_ && b_pf_mus_cm_etaErr_){
    b_pf_mus_cm_etaErr_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_cm_etaErr", &pf_mus_cm_etaErr_, &b_pf_mus_cm_etaErr_);
    b_pf_mus_cm_etaErr_->GetEntry(entry_);
    c_pf_mus_cm_etaErr_ = true;
  }
  return pf_mus_cm_etaErr_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_ndof() const{
  if(!c_pf_mus_cm_ndof_ && b_pf_mus_cm_ndof_){
    b_pf_mus_cm_ndof_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_cm_ndof", &pf_mus_cm_ndof_, &b_pf_mus_cm_ndof_);
    b_pf_mus_cm_ndof_->GetEntry(entry_);
    c_pf_mus_cm_ndof_ = true;
  }
  return pf_mus_cm_ndof_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_numlosthits() const{
  if(!c_pf_mus_cm_numlosthits_ && b_pf_mus_cm_numlosthits_){
    b_pf_mus_cm_numlosthits_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_cm_numlosthits", &pf_mus_cm_numlosthits_, &b_pf_mus_cm_numlosthits_);
    b_pf_mus_cm_numlosthits_->GetEntry(entry_);
    c_pf_mus_cm_numlosthits_ = true;
  }
  return pf_mus_cm_numlosthits_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_numvalMuonhits() const{
  if(!c_pf_mus_cm_numvalMuonhits_ && b_pf_mus_cm_numvalMuonhits_){
    b_pf_mus_cm_numvalMuonhits_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_cm_numvalMuonhits", &pf_mus_cm_numvalMuonhits_, &b_pf_mus_cm_numvalMuonhits_);
    b_pf_mus_cm_numvalMuonhits_->GetEntry(entry_);
    c_pf_mus_cm_numvalMuonhits_ = true;
  }
  return pf_mus_cm_numvalMuonhits_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_numvalhits() const{
  if(!c_pf_mus_cm_numvalhits_ && b_pf_mus_cm_numvalhits_){
    b_pf_mus_cm_numvalhits_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_cm_numvalhits", &pf_mus_cm_numvalhits_, &b_pf_mus_cm_numvalhits_);
    b_pf_mus_cm_numvalhits_->GetEntry(entry_);
    c_pf_mus_cm_numvalhits_ = true;
  }
  return pf_mus_cm_numvalhits_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_phi() const{
  if(!c_pf_mus_cm_phi_ && b_pf_mus_cm_phi_){
    b_pf_mus_cm_phi_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_cm_phi", &pf_mus_cm_phi_, &b_pf_mus_cm_phi_);
    b_pf_mus_cm_phi_->GetEntry(entry_);
    c_pf_mus_cm_phi_ = true;
  }
  return pf_mus_cm_phi_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_phiErr() const{
  if(!c_pf_mus_cm_phiErr_ && b_pf_mus_cm_phiErr_){
    b_pf_mus_cm_phiErr_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_cm_phiErr", &pf_mus_cm_phiErr_, &b_pf_mus_cm_phiErr_);
    b_pf_mus_cm_phiErr_->GetEntry(entry_);
    c_pf_mus_cm_phiErr_ = true;
  }
  return pf_mus_cm_phiErr_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_pt() const{
  if(!c_pf_mus_cm_pt_ && b_pf_mus_cm_pt_){
    b_pf_mus_cm_pt_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_cm_pt", &pf_mus_cm_pt_, &b_pf_mus_cm_pt_);
    b_pf_mus_cm_pt_->GetEntry(entry_);
    c_pf_mus_cm_pt_ = true;
  }
  return pf_mus_cm_pt_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_ptErr() const{
  if(!c_pf_mus_cm_ptErr_ && b_pf_mus_cm_ptErr_){
    b_pf_mus_cm_ptErr_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_cm_ptErr", &pf_mus_cm_ptErr_, &b_pf_mus_cm_ptErr_);
    b_pf_mus_cm_ptErr_->GetEntry(entry_);
    c_pf_mus_cm_ptErr_ = true;
  }
  return pf_mus_cm_ptErr_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_px() const{
  if(!c_pf_mus_cm_px_ && b_pf_mus_cm_px_){
    b_pf_mus_cm_px_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_cm_px", &pf_mus_cm_px_, &b_pf_mus_cm_px_);
    b_pf_mus_cm_px_->GetEntry(entry_);
    c_pf_mus_cm_px_ = true;
  }
  return pf_mus_cm_px_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_py() const{
  if(!c_pf_mus_cm_py_ && b_pf_mus_cm_py_){
    b_pf_mus_cm_py_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_cm_py", &pf_mus_cm_py_, &b_pf_mus_cm_py_);
    b_pf_mus_cm_py_->GetEntry(entry_);
    c_pf_mus_cm_py_ = true;
  }
  return pf_mus_cm_py_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_pz() const{
  if(!c_pf_mus_cm_pz_ && b_pf_mus_cm_pz_){
    b_pf_mus_cm_pz_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_cm_pz", &pf_mus_cm_pz_, &b_pf_mus_cm_pz_);
    b_pf_mus_cm_pz_->GetEntry(entry_);
    c_pf_mus_cm_pz_ = true;
  }
  return pf_mus_cm_pz_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_theta() const{
  if(!c_pf_mus_cm_theta_ && b_pf_mus_cm_theta_){
    b_pf_mus_cm_theta_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_cm_theta", &pf_mus_cm_theta_, &b_pf_mus_cm_theta_);
    b_pf_mus_cm_theta_->GetEntry(entry_);
    c_pf_mus_cm_theta_ = true;
  }
  return pf_mus_cm_theta_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_vx() const{
  if(!c_pf_mus_cm_vx_ && b_pf_mus_cm_vx_){
    b_pf_mus_cm_vx_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_cm_vx", &pf_mus_cm_vx_, &b_pf_mus_cm_vx_);
    b_pf_mus_cm_vx_->GetEntry(entry_);
    c_pf_mus_cm_vx_ = true;
  }
  return pf_mus_cm_vx_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_vy() const{
  if(!c_pf_mus_cm_vy_ && b_pf_mus_cm_vy_){
    b_pf_mus_cm_vy_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_cm_vy", &pf_mus_cm_vy_, &b_pf_mus_cm_vy_);
    b_pf_mus_cm_vy_->GetEntry(entry_);
    c_pf_mus_cm_vy_ = true;
  }
  return pf_mus_cm_vy_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_vz() const{
  if(!c_pf_mus_cm_vz_ && b_pf_mus_cm_vz_){
    b_pf_mus_cm_vz_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_cm_vz", &pf_mus_cm_vz_, &b_pf_mus_cm_vz_);
    b_pf_mus_cm_vz_->GetEntry(entry_);
    c_pf_mus_cm_vz_ = true;
  }
  return pf_mus_cm_vz_;
}

std::vector<float>* const & cfa_8::pf_mus_dB() const{
  if(!c_pf_mus_dB_ && b_pf_mus_dB_){
    b_pf_mus_dB_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_dB", &pf_mus_dB_, &b_pf_mus_dB_);
    b_pf_mus_dB_->GetEntry(entry_);
    c_pf_mus_dB_ = true;
  }
  return pf_mus_dB_;
}

std::vector<float>* const & cfa_8::pf_mus_ecalIso() const{
  if(!c_pf_mus_ecalIso_ && b_pf_mus_ecalIso_){
    b_pf_mus_ecalIso_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_ecalIso", &pf_mus_ecalIso_, &b_pf_mus_ecalIso_);
    b_pf_mus_ecalIso_->GetEntry(entry_);
    c_pf_mus_ecalIso_ = true;
  }
  return pf_mus_ecalIso_;
}

std::vector<float>* const & cfa_8::pf_mus_energy() const{
  if(!c_pf_mus_energy_ && b_pf_mus_energy_){
    b_pf_mus_energy_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_energy", &pf_mus_energy_, &b_pf_mus_energy_);
    b_pf_mus_energy_->GetEntry(entry_);
    c_pf_mus_energy_ = true;
  }
  return pf_mus_energy_;
}

std::vector<float>* const & cfa_8::pf_mus_et() const{
  if(!c_pf_mus_et_ && b_pf_mus_et_){
    b_pf_mus_et_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_et", &pf_mus_et_, &b_pf_mus_et_);
    b_pf_mus_et_->GetEntry(entry_);
    c_pf_mus_et_ = true;
  }
  return pf_mus_et_;
}

std::vector<float>* const & cfa_8::pf_mus_eta() const{
  if(!c_pf_mus_eta_ && b_pf_mus_eta_){
    b_pf_mus_eta_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_eta", &pf_mus_eta_, &b_pf_mus_eta_);
    b_pf_mus_eta_->GetEntry(entry_);
    c_pf_mus_eta_ = true;
  }
  return pf_mus_eta_;
}

std::vector<float>* const & cfa_8::pf_mus_gen_et() const{
  if(!c_pf_mus_gen_et_ && b_pf_mus_gen_et_){
    b_pf_mus_gen_et_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_gen_et", &pf_mus_gen_et_, &b_pf_mus_gen_et_);
    b_pf_mus_gen_et_->GetEntry(entry_);
    c_pf_mus_gen_et_ = true;
  }
  return pf_mus_gen_et_;
}

std::vector<float>* const & cfa_8::pf_mus_gen_eta() const{
  if(!c_pf_mus_gen_eta_ && b_pf_mus_gen_eta_){
    b_pf_mus_gen_eta_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_gen_eta", &pf_mus_gen_eta_, &b_pf_mus_gen_eta_);
    b_pf_mus_gen_eta_->GetEntry(entry_);
    c_pf_mus_gen_eta_ = true;
  }
  return pf_mus_gen_eta_;
}

std::vector<float>* const & cfa_8::pf_mus_gen_id() const{
  if(!c_pf_mus_gen_id_ && b_pf_mus_gen_id_){
    b_pf_mus_gen_id_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_gen_id", &pf_mus_gen_id_, &b_pf_mus_gen_id_);
    b_pf_mus_gen_id_->GetEntry(entry_);
    c_pf_mus_gen_id_ = true;
  }
  return pf_mus_gen_id_;
}

std::vector<float>* const & cfa_8::pf_mus_gen_mother_et() const{
  if(!c_pf_mus_gen_mother_et_ && b_pf_mus_gen_mother_et_){
    b_pf_mus_gen_mother_et_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_gen_mother_et", &pf_mus_gen_mother_et_, &b_pf_mus_gen_mother_et_);
    b_pf_mus_gen_mother_et_->GetEntry(entry_);
    c_pf_mus_gen_mother_et_ = true;
  }
  return pf_mus_gen_mother_et_;
}

std::vector<float>* const & cfa_8::pf_mus_gen_mother_eta() const{
  if(!c_pf_mus_gen_mother_eta_ && b_pf_mus_gen_mother_eta_){
    b_pf_mus_gen_mother_eta_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_gen_mother_eta", &pf_mus_gen_mother_eta_, &b_pf_mus_gen_mother_eta_);
    b_pf_mus_gen_mother_eta_->GetEntry(entry_);
    c_pf_mus_gen_mother_eta_ = true;
  }
  return pf_mus_gen_mother_eta_;
}

std::vector<float>* const & cfa_8::pf_mus_gen_mother_id() const{
  if(!c_pf_mus_gen_mother_id_ && b_pf_mus_gen_mother_id_){
    b_pf_mus_gen_mother_id_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_gen_mother_id", &pf_mus_gen_mother_id_, &b_pf_mus_gen_mother_id_);
    b_pf_mus_gen_mother_id_->GetEntry(entry_);
    c_pf_mus_gen_mother_id_ = true;
  }
  return pf_mus_gen_mother_id_;
}

std::vector<float>* const & cfa_8::pf_mus_gen_mother_phi() const{
  if(!c_pf_mus_gen_mother_phi_ && b_pf_mus_gen_mother_phi_){
    b_pf_mus_gen_mother_phi_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_gen_mother_phi", &pf_mus_gen_mother_phi_, &b_pf_mus_gen_mother_phi_);
    b_pf_mus_gen_mother_phi_->GetEntry(entry_);
    c_pf_mus_gen_mother_phi_ = true;
  }
  return pf_mus_gen_mother_phi_;
}

std::vector<float>* const & cfa_8::pf_mus_gen_mother_pt() const{
  if(!c_pf_mus_gen_mother_pt_ && b_pf_mus_gen_mother_pt_){
    b_pf_mus_gen_mother_pt_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_gen_mother_pt", &pf_mus_gen_mother_pt_, &b_pf_mus_gen_mother_pt_);
    b_pf_mus_gen_mother_pt_->GetEntry(entry_);
    c_pf_mus_gen_mother_pt_ = true;
  }
  return pf_mus_gen_mother_pt_;
}

std::vector<float>* const & cfa_8::pf_mus_gen_mother_px() const{
  if(!c_pf_mus_gen_mother_px_ && b_pf_mus_gen_mother_px_){
    b_pf_mus_gen_mother_px_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_gen_mother_px", &pf_mus_gen_mother_px_, &b_pf_mus_gen_mother_px_);
    b_pf_mus_gen_mother_px_->GetEntry(entry_);
    c_pf_mus_gen_mother_px_ = true;
  }
  return pf_mus_gen_mother_px_;
}

std::vector<float>* const & cfa_8::pf_mus_gen_mother_py() const{
  if(!c_pf_mus_gen_mother_py_ && b_pf_mus_gen_mother_py_){
    b_pf_mus_gen_mother_py_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_gen_mother_py", &pf_mus_gen_mother_py_, &b_pf_mus_gen_mother_py_);
    b_pf_mus_gen_mother_py_->GetEntry(entry_);
    c_pf_mus_gen_mother_py_ = true;
  }
  return pf_mus_gen_mother_py_;
}

std::vector<float>* const & cfa_8::pf_mus_gen_mother_pz() const{
  if(!c_pf_mus_gen_mother_pz_ && b_pf_mus_gen_mother_pz_){
    b_pf_mus_gen_mother_pz_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_gen_mother_pz", &pf_mus_gen_mother_pz_, &b_pf_mus_gen_mother_pz_);
    b_pf_mus_gen_mother_pz_->GetEntry(entry_);
    c_pf_mus_gen_mother_pz_ = true;
  }
  return pf_mus_gen_mother_pz_;
}

std::vector<float>* const & cfa_8::pf_mus_gen_mother_theta() const{
  if(!c_pf_mus_gen_mother_theta_ && b_pf_mus_gen_mother_theta_){
    b_pf_mus_gen_mother_theta_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_gen_mother_theta", &pf_mus_gen_mother_theta_, &b_pf_mus_gen_mother_theta_);
    b_pf_mus_gen_mother_theta_->GetEntry(entry_);
    c_pf_mus_gen_mother_theta_ = true;
  }
  return pf_mus_gen_mother_theta_;
}

std::vector<float>* const & cfa_8::pf_mus_gen_phi() const{
  if(!c_pf_mus_gen_phi_ && b_pf_mus_gen_phi_){
    b_pf_mus_gen_phi_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_gen_phi", &pf_mus_gen_phi_, &b_pf_mus_gen_phi_);
    b_pf_mus_gen_phi_->GetEntry(entry_);
    c_pf_mus_gen_phi_ = true;
  }
  return pf_mus_gen_phi_;
}

std::vector<float>* const & cfa_8::pf_mus_gen_pt() const{
  if(!c_pf_mus_gen_pt_ && b_pf_mus_gen_pt_){
    b_pf_mus_gen_pt_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_gen_pt", &pf_mus_gen_pt_, &b_pf_mus_gen_pt_);
    b_pf_mus_gen_pt_->GetEntry(entry_);
    c_pf_mus_gen_pt_ = true;
  }
  return pf_mus_gen_pt_;
}

std::vector<float>* const & cfa_8::pf_mus_gen_px() const{
  if(!c_pf_mus_gen_px_ && b_pf_mus_gen_px_){
    b_pf_mus_gen_px_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_gen_px", &pf_mus_gen_px_, &b_pf_mus_gen_px_);
    b_pf_mus_gen_px_->GetEntry(entry_);
    c_pf_mus_gen_px_ = true;
  }
  return pf_mus_gen_px_;
}

std::vector<float>* const & cfa_8::pf_mus_gen_py() const{
  if(!c_pf_mus_gen_py_ && b_pf_mus_gen_py_){
    b_pf_mus_gen_py_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_gen_py", &pf_mus_gen_py_, &b_pf_mus_gen_py_);
    b_pf_mus_gen_py_->GetEntry(entry_);
    c_pf_mus_gen_py_ = true;
  }
  return pf_mus_gen_py_;
}

std::vector<float>* const & cfa_8::pf_mus_gen_pz() const{
  if(!c_pf_mus_gen_pz_ && b_pf_mus_gen_pz_){
    b_pf_mus_gen_pz_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_gen_pz", &pf_mus_gen_pz_, &b_pf_mus_gen_pz_);
    b_pf_mus_gen_pz_->GetEntry(entry_);
    c_pf_mus_gen_pz_ = true;
  }
  return pf_mus_gen_pz_;
}

std::vector<float>* const & cfa_8::pf_mus_gen_theta() const{
  if(!c_pf_mus_gen_theta_ && b_pf_mus_gen_theta_){
    b_pf_mus_gen_theta_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_gen_theta", &pf_mus_gen_theta_, &b_pf_mus_gen_theta_);
    b_pf_mus_gen_theta_->GetEntry(entry_);
    c_pf_mus_gen_theta_ = true;
  }
  return pf_mus_gen_theta_;
}

std::vector<float>* const & cfa_8::pf_mus_hcalIso() const{
  if(!c_pf_mus_hcalIso_ && b_pf_mus_hcalIso_){
    b_pf_mus_hcalIso_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_hcalIso", &pf_mus_hcalIso_, &b_pf_mus_hcalIso_);
    b_pf_mus_hcalIso_->GetEntry(entry_);
    c_pf_mus_hcalIso_ = true;
  }
  return pf_mus_hcalIso_;
}

std::vector<float>* const & cfa_8::pf_mus_id_All() const{
  if(!c_pf_mus_id_All_ && b_pf_mus_id_All_){
    b_pf_mus_id_All_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_id_All", &pf_mus_id_All_, &b_pf_mus_id_All_);
    b_pf_mus_id_All_->GetEntry(entry_);
    c_pf_mus_id_All_ = true;
  }
  return pf_mus_id_All_;
}

std::vector<float>* const & cfa_8::pf_mus_id_AllArbitrated() const{
  if(!c_pf_mus_id_AllArbitrated_ && b_pf_mus_id_AllArbitrated_){
    b_pf_mus_id_AllArbitrated_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_id_AllArbitrated", &pf_mus_id_AllArbitrated_, &b_pf_mus_id_AllArbitrated_);
    b_pf_mus_id_AllArbitrated_->GetEntry(entry_);
    c_pf_mus_id_AllArbitrated_ = true;
  }
  return pf_mus_id_AllArbitrated_;
}

std::vector<float>* const & cfa_8::pf_mus_id_AllGlobalMuons() const{
  if(!c_pf_mus_id_AllGlobalMuons_ && b_pf_mus_id_AllGlobalMuons_){
    b_pf_mus_id_AllGlobalMuons_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_id_AllGlobalMuons", &pf_mus_id_AllGlobalMuons_, &b_pf_mus_id_AllGlobalMuons_);
    b_pf_mus_id_AllGlobalMuons_->GetEntry(entry_);
    c_pf_mus_id_AllGlobalMuons_ = true;
  }
  return pf_mus_id_AllGlobalMuons_;
}

std::vector<float>* const & cfa_8::pf_mus_id_AllStandAloneMuons() const{
  if(!c_pf_mus_id_AllStandAloneMuons_ && b_pf_mus_id_AllStandAloneMuons_){
    b_pf_mus_id_AllStandAloneMuons_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_id_AllStandAloneMuons", &pf_mus_id_AllStandAloneMuons_, &b_pf_mus_id_AllStandAloneMuons_);
    b_pf_mus_id_AllStandAloneMuons_->GetEntry(entry_);
    c_pf_mus_id_AllStandAloneMuons_ = true;
  }
  return pf_mus_id_AllStandAloneMuons_;
}

std::vector<float>* const & cfa_8::pf_mus_id_AllTrackerMuons() const{
  if(!c_pf_mus_id_AllTrackerMuons_ && b_pf_mus_id_AllTrackerMuons_){
    b_pf_mus_id_AllTrackerMuons_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_id_AllTrackerMuons", &pf_mus_id_AllTrackerMuons_, &b_pf_mus_id_AllTrackerMuons_);
    b_pf_mus_id_AllTrackerMuons_->GetEntry(entry_);
    c_pf_mus_id_AllTrackerMuons_ = true;
  }
  return pf_mus_id_AllTrackerMuons_;
}

std::vector<float>* const & cfa_8::pf_mus_id_GlobalMuonPromptTight() const{
  if(!c_pf_mus_id_GlobalMuonPromptTight_ && b_pf_mus_id_GlobalMuonPromptTight_){
    b_pf_mus_id_GlobalMuonPromptTight_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_id_GlobalMuonPromptTight", &pf_mus_id_GlobalMuonPromptTight_, &b_pf_mus_id_GlobalMuonPromptTight_);
    b_pf_mus_id_GlobalMuonPromptTight_->GetEntry(entry_);
    c_pf_mus_id_GlobalMuonPromptTight_ = true;
  }
  return pf_mus_id_GlobalMuonPromptTight_;
}

std::vector<float>* const & cfa_8::pf_mus_id_TM2DCompatibilityLoose() const{
  if(!c_pf_mus_id_TM2DCompatibilityLoose_ && b_pf_mus_id_TM2DCompatibilityLoose_){
    b_pf_mus_id_TM2DCompatibilityLoose_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_id_TM2DCompatibilityLoose", &pf_mus_id_TM2DCompatibilityLoose_, &b_pf_mus_id_TM2DCompatibilityLoose_);
    b_pf_mus_id_TM2DCompatibilityLoose_->GetEntry(entry_);
    c_pf_mus_id_TM2DCompatibilityLoose_ = true;
  }
  return pf_mus_id_TM2DCompatibilityLoose_;
}

std::vector<float>* const & cfa_8::pf_mus_id_TM2DCompatibilityTight() const{
  if(!c_pf_mus_id_TM2DCompatibilityTight_ && b_pf_mus_id_TM2DCompatibilityTight_){
    b_pf_mus_id_TM2DCompatibilityTight_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_id_TM2DCompatibilityTight", &pf_mus_id_TM2DCompatibilityTight_, &b_pf_mus_id_TM2DCompatibilityTight_);
    b_pf_mus_id_TM2DCompatibilityTight_->GetEntry(entry_);
    c_pf_mus_id_TM2DCompatibilityTight_ = true;
  }
  return pf_mus_id_TM2DCompatibilityTight_;
}

std::vector<float>* const & cfa_8::pf_mus_id_TMLastStationLoose() const{
  if(!c_pf_mus_id_TMLastStationLoose_ && b_pf_mus_id_TMLastStationLoose_){
    b_pf_mus_id_TMLastStationLoose_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_id_TMLastStationLoose", &pf_mus_id_TMLastStationLoose_, &b_pf_mus_id_TMLastStationLoose_);
    b_pf_mus_id_TMLastStationLoose_->GetEntry(entry_);
    c_pf_mus_id_TMLastStationLoose_ = true;
  }
  return pf_mus_id_TMLastStationLoose_;
}

std::vector<float>* const & cfa_8::pf_mus_id_TMLastStationOptimizedLowPtLoose() const{
  if(!c_pf_mus_id_TMLastStationOptimizedLowPtLoose_ && b_pf_mus_id_TMLastStationOptimizedLowPtLoose_){
    b_pf_mus_id_TMLastStationOptimizedLowPtLoose_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_id_TMLastStationOptimizedLowPtLoose", &pf_mus_id_TMLastStationOptimizedLowPtLoose_, &b_pf_mus_id_TMLastStationOptimizedLowPtLoose_);
    b_pf_mus_id_TMLastStationOptimizedLowPtLoose_->GetEntry(entry_);
    c_pf_mus_id_TMLastStationOptimizedLowPtLoose_ = true;
  }
  return pf_mus_id_TMLastStationOptimizedLowPtLoose_;
}

std::vector<float>* const & cfa_8::pf_mus_id_TMLastStationOptimizedLowPtTight() const{
  if(!c_pf_mus_id_TMLastStationOptimizedLowPtTight_ && b_pf_mus_id_TMLastStationOptimizedLowPtTight_){
    b_pf_mus_id_TMLastStationOptimizedLowPtTight_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_id_TMLastStationOptimizedLowPtTight", &pf_mus_id_TMLastStationOptimizedLowPtTight_, &b_pf_mus_id_TMLastStationOptimizedLowPtTight_);
    b_pf_mus_id_TMLastStationOptimizedLowPtTight_->GetEntry(entry_);
    c_pf_mus_id_TMLastStationOptimizedLowPtTight_ = true;
  }
  return pf_mus_id_TMLastStationOptimizedLowPtTight_;
}

std::vector<float>* const & cfa_8::pf_mus_id_TMLastStationTight() const{
  if(!c_pf_mus_id_TMLastStationTight_ && b_pf_mus_id_TMLastStationTight_){
    b_pf_mus_id_TMLastStationTight_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_id_TMLastStationTight", &pf_mus_id_TMLastStationTight_, &b_pf_mus_id_TMLastStationTight_);
    b_pf_mus_id_TMLastStationTight_->GetEntry(entry_);
    c_pf_mus_id_TMLastStationTight_ = true;
  }
  return pf_mus_id_TMLastStationTight_;
}

std::vector<float>* const & cfa_8::pf_mus_id_TMOneStationLoose() const{
  if(!c_pf_mus_id_TMOneStationLoose_ && b_pf_mus_id_TMOneStationLoose_){
    b_pf_mus_id_TMOneStationLoose_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_id_TMOneStationLoose", &pf_mus_id_TMOneStationLoose_, &b_pf_mus_id_TMOneStationLoose_);
    b_pf_mus_id_TMOneStationLoose_->GetEntry(entry_);
    c_pf_mus_id_TMOneStationLoose_ = true;
  }
  return pf_mus_id_TMOneStationLoose_;
}

std::vector<float>* const & cfa_8::pf_mus_id_TMOneStationTight() const{
  if(!c_pf_mus_id_TMOneStationTight_ && b_pf_mus_id_TMOneStationTight_){
    b_pf_mus_id_TMOneStationTight_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_id_TMOneStationTight", &pf_mus_id_TMOneStationTight_, &b_pf_mus_id_TMOneStationTight_);
    b_pf_mus_id_TMOneStationTight_->GetEntry(entry_);
    c_pf_mus_id_TMOneStationTight_ = true;
  }
  return pf_mus_id_TMOneStationTight_;
}

std::vector<float>* const & cfa_8::pf_mus_id_TrackerMuonArbitrated() const{
  if(!c_pf_mus_id_TrackerMuonArbitrated_ && b_pf_mus_id_TrackerMuonArbitrated_){
    b_pf_mus_id_TrackerMuonArbitrated_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_id_TrackerMuonArbitrated", &pf_mus_id_TrackerMuonArbitrated_, &b_pf_mus_id_TrackerMuonArbitrated_);
    b_pf_mus_id_TrackerMuonArbitrated_->GetEntry(entry_);
    c_pf_mus_id_TrackerMuonArbitrated_ = true;
  }
  return pf_mus_id_TrackerMuonArbitrated_;
}

std::vector<float>* const & cfa_8::pf_mus_isCaloMuon() const{
  if(!c_pf_mus_isCaloMuon_ && b_pf_mus_isCaloMuon_){
    b_pf_mus_isCaloMuon_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_isCaloMuon", &pf_mus_isCaloMuon_, &b_pf_mus_isCaloMuon_);
    b_pf_mus_isCaloMuon_->GetEntry(entry_);
    c_pf_mus_isCaloMuon_ = true;
  }
  return pf_mus_isCaloMuon_;
}

std::vector<float>* const & cfa_8::pf_mus_isConvertedPhoton() const{
  if(!c_pf_mus_isConvertedPhoton_ && b_pf_mus_isConvertedPhoton_){
    b_pf_mus_isConvertedPhoton_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_isConvertedPhoton", &pf_mus_isConvertedPhoton_, &b_pf_mus_isConvertedPhoton_);
    b_pf_mus_isConvertedPhoton_->GetEntry(entry_);
    c_pf_mus_isConvertedPhoton_ = true;
  }
  return pf_mus_isConvertedPhoton_;
}

std::vector<float>* const & cfa_8::pf_mus_isElectron() const{
  if(!c_pf_mus_isElectron_ && b_pf_mus_isElectron_){
    b_pf_mus_isElectron_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_isElectron", &pf_mus_isElectron_, &b_pf_mus_isElectron_);
    b_pf_mus_isElectron_->GetEntry(entry_);
    c_pf_mus_isElectron_ = true;
  }
  return pf_mus_isElectron_;
}

std::vector<float>* const & cfa_8::pf_mus_isGlobalMuon() const{
  if(!c_pf_mus_isGlobalMuon_ && b_pf_mus_isGlobalMuon_){
    b_pf_mus_isGlobalMuon_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_isGlobalMuon", &pf_mus_isGlobalMuon_, &b_pf_mus_isGlobalMuon_);
    b_pf_mus_isGlobalMuon_->GetEntry(entry_);
    c_pf_mus_isGlobalMuon_ = true;
  }
  return pf_mus_isGlobalMuon_;
}

std::vector<float>* const & cfa_8::pf_mus_isPFMuon() const{
  if(!c_pf_mus_isPFMuon_ && b_pf_mus_isPFMuon_){
    b_pf_mus_isPFMuon_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_isPFMuon", &pf_mus_isPFMuon_, &b_pf_mus_isPFMuon_);
    b_pf_mus_isPFMuon_->GetEntry(entry_);
    c_pf_mus_isPFMuon_ = true;
  }
  return pf_mus_isPFMuon_;
}

std::vector<float>* const & cfa_8::pf_mus_isPhoton() const{
  if(!c_pf_mus_isPhoton_ && b_pf_mus_isPhoton_){
    b_pf_mus_isPhoton_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_isPhoton", &pf_mus_isPhoton_, &b_pf_mus_isPhoton_);
    b_pf_mus_isPhoton_->GetEntry(entry_);
    c_pf_mus_isPhoton_ = true;
  }
  return pf_mus_isPhoton_;
}

std::vector<float>* const & cfa_8::pf_mus_isStandAloneMuon() const{
  if(!c_pf_mus_isStandAloneMuon_ && b_pf_mus_isStandAloneMuon_){
    b_pf_mus_isStandAloneMuon_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_isStandAloneMuon", &pf_mus_isStandAloneMuon_, &b_pf_mus_isStandAloneMuon_);
    b_pf_mus_isStandAloneMuon_->GetEntry(entry_);
    c_pf_mus_isStandAloneMuon_ = true;
  }
  return pf_mus_isStandAloneMuon_;
}

std::vector<float>* const & cfa_8::pf_mus_isTrackerMuon() const{
  if(!c_pf_mus_isTrackerMuon_ && b_pf_mus_isTrackerMuon_){
    b_pf_mus_isTrackerMuon_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_isTrackerMuon", &pf_mus_isTrackerMuon_, &b_pf_mus_isTrackerMuon_);
    b_pf_mus_isTrackerMuon_->GetEntry(entry_);
    c_pf_mus_isTrackerMuon_ = true;
  }
  return pf_mus_isTrackerMuon_;
}

std::vector<float>* const & cfa_8::pf_mus_iso03_emEt() const{
  if(!c_pf_mus_iso03_emEt_ && b_pf_mus_iso03_emEt_){
    b_pf_mus_iso03_emEt_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_iso03_emEt", &pf_mus_iso03_emEt_, &b_pf_mus_iso03_emEt_);
    b_pf_mus_iso03_emEt_->GetEntry(entry_);
    c_pf_mus_iso03_emEt_ = true;
  }
  return pf_mus_iso03_emEt_;
}

std::vector<float>* const & cfa_8::pf_mus_iso03_emVetoEt() const{
  if(!c_pf_mus_iso03_emVetoEt_ && b_pf_mus_iso03_emVetoEt_){
    b_pf_mus_iso03_emVetoEt_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_iso03_emVetoEt", &pf_mus_iso03_emVetoEt_, &b_pf_mus_iso03_emVetoEt_);
    b_pf_mus_iso03_emVetoEt_->GetEntry(entry_);
    c_pf_mus_iso03_emVetoEt_ = true;
  }
  return pf_mus_iso03_emVetoEt_;
}

std::vector<float>* const & cfa_8::pf_mus_iso03_hadEt() const{
  if(!c_pf_mus_iso03_hadEt_ && b_pf_mus_iso03_hadEt_){
    b_pf_mus_iso03_hadEt_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_iso03_hadEt", &pf_mus_iso03_hadEt_, &b_pf_mus_iso03_hadEt_);
    b_pf_mus_iso03_hadEt_->GetEntry(entry_);
    c_pf_mus_iso03_hadEt_ = true;
  }
  return pf_mus_iso03_hadEt_;
}

std::vector<float>* const & cfa_8::pf_mus_iso03_hadVetoEt() const{
  if(!c_pf_mus_iso03_hadVetoEt_ && b_pf_mus_iso03_hadVetoEt_){
    b_pf_mus_iso03_hadVetoEt_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_iso03_hadVetoEt", &pf_mus_iso03_hadVetoEt_, &b_pf_mus_iso03_hadVetoEt_);
    b_pf_mus_iso03_hadVetoEt_->GetEntry(entry_);
    c_pf_mus_iso03_hadVetoEt_ = true;
  }
  return pf_mus_iso03_hadVetoEt_;
}

std::vector<float>* const & cfa_8::pf_mus_iso03_hoEt() const{
  if(!c_pf_mus_iso03_hoEt_ && b_pf_mus_iso03_hoEt_){
    b_pf_mus_iso03_hoEt_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_iso03_hoEt", &pf_mus_iso03_hoEt_, &b_pf_mus_iso03_hoEt_);
    b_pf_mus_iso03_hoEt_->GetEntry(entry_);
    c_pf_mus_iso03_hoEt_ = true;
  }
  return pf_mus_iso03_hoEt_;
}

std::vector<float>* const & cfa_8::pf_mus_iso03_nTracks() const{
  if(!c_pf_mus_iso03_nTracks_ && b_pf_mus_iso03_nTracks_){
    b_pf_mus_iso03_nTracks_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_iso03_nTracks", &pf_mus_iso03_nTracks_, &b_pf_mus_iso03_nTracks_);
    b_pf_mus_iso03_nTracks_->GetEntry(entry_);
    c_pf_mus_iso03_nTracks_ = true;
  }
  return pf_mus_iso03_nTracks_;
}

std::vector<float>* const & cfa_8::pf_mus_iso03_sumPt() const{
  if(!c_pf_mus_iso03_sumPt_ && b_pf_mus_iso03_sumPt_){
    b_pf_mus_iso03_sumPt_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_iso03_sumPt", &pf_mus_iso03_sumPt_, &b_pf_mus_iso03_sumPt_);
    b_pf_mus_iso03_sumPt_->GetEntry(entry_);
    c_pf_mus_iso03_sumPt_ = true;
  }
  return pf_mus_iso03_sumPt_;
}

std::vector<float>* const & cfa_8::pf_mus_iso05_emEt() const{
  if(!c_pf_mus_iso05_emEt_ && b_pf_mus_iso05_emEt_){
    b_pf_mus_iso05_emEt_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_iso05_emEt", &pf_mus_iso05_emEt_, &b_pf_mus_iso05_emEt_);
    b_pf_mus_iso05_emEt_->GetEntry(entry_);
    c_pf_mus_iso05_emEt_ = true;
  }
  return pf_mus_iso05_emEt_;
}

std::vector<float>* const & cfa_8::pf_mus_iso05_hadEt() const{
  if(!c_pf_mus_iso05_hadEt_ && b_pf_mus_iso05_hadEt_){
    b_pf_mus_iso05_hadEt_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_iso05_hadEt", &pf_mus_iso05_hadEt_, &b_pf_mus_iso05_hadEt_);
    b_pf_mus_iso05_hadEt_->GetEntry(entry_);
    c_pf_mus_iso05_hadEt_ = true;
  }
  return pf_mus_iso05_hadEt_;
}

std::vector<float>* const & cfa_8::pf_mus_iso05_hoEt() const{
  if(!c_pf_mus_iso05_hoEt_ && b_pf_mus_iso05_hoEt_){
    b_pf_mus_iso05_hoEt_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_iso05_hoEt", &pf_mus_iso05_hoEt_, &b_pf_mus_iso05_hoEt_);
    b_pf_mus_iso05_hoEt_->GetEntry(entry_);
    c_pf_mus_iso05_hoEt_ = true;
  }
  return pf_mus_iso05_hoEt_;
}

std::vector<float>* const & cfa_8::pf_mus_iso05_nTracks() const{
  if(!c_pf_mus_iso05_nTracks_ && b_pf_mus_iso05_nTracks_){
    b_pf_mus_iso05_nTracks_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_iso05_nTracks", &pf_mus_iso05_nTracks_, &b_pf_mus_iso05_nTracks_);
    b_pf_mus_iso05_nTracks_->GetEntry(entry_);
    c_pf_mus_iso05_nTracks_ = true;
  }
  return pf_mus_iso05_nTracks_;
}

std::vector<float>* const & cfa_8::pf_mus_iso05_sumPt() const{
  if(!c_pf_mus_iso05_sumPt_ && b_pf_mus_iso05_sumPt_){
    b_pf_mus_iso05_sumPt_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_iso05_sumPt", &pf_mus_iso05_sumPt_, &b_pf_mus_iso05_sumPt_);
    b_pf_mus_iso05_sumPt_->GetEntry(entry_);
    c_pf_mus_iso05_sumPt_ = true;
  }
  return pf_mus_iso05_sumPt_;
}

std::vector<float>* const & cfa_8::pf_mus_neutralHadronIso() const{
  if(!c_pf_mus_neutralHadronIso_ && b_pf_mus_neutralHadronIso_){
    b_pf_mus_neutralHadronIso_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_neutralHadronIso", &pf_mus_neutralHadronIso_, &b_pf_mus_neutralHadronIso_);
    b_pf_mus_neutralHadronIso_->GetEntry(entry_);
    c_pf_mus_neutralHadronIso_ = true;
  }
  return pf_mus_neutralHadronIso_;
}

std::vector<float>* const & cfa_8::pf_mus_num_matches() const{
  if(!c_pf_mus_num_matches_ && b_pf_mus_num_matches_){
    b_pf_mus_num_matches_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_num_matches", &pf_mus_num_matches_, &b_pf_mus_num_matches_);
    b_pf_mus_num_matches_->GetEntry(entry_);
    c_pf_mus_num_matches_ = true;
  }
  return pf_mus_num_matches_;
}

std::vector<float>* const & cfa_8::pf_mus_numberOfMatchedStations() const{
  if(!c_pf_mus_numberOfMatchedStations_ && b_pf_mus_numberOfMatchedStations_){
    b_pf_mus_numberOfMatchedStations_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_numberOfMatchedStations", &pf_mus_numberOfMatchedStations_, &b_pf_mus_numberOfMatchedStations_);
    b_pf_mus_numberOfMatchedStations_->GetEntry(entry_);
    c_pf_mus_numberOfMatchedStations_ = true;
  }
  return pf_mus_numberOfMatchedStations_;
}

std::vector<float>* const & cfa_8::pf_mus_pfIsolationR03_sumChargedHadronPt() const{
  if(!c_pf_mus_pfIsolationR03_sumChargedHadronPt_ && b_pf_mus_pfIsolationR03_sumChargedHadronPt_){
    b_pf_mus_pfIsolationR03_sumChargedHadronPt_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_pfIsolationR03_sumChargedHadronPt", &pf_mus_pfIsolationR03_sumChargedHadronPt_, &b_pf_mus_pfIsolationR03_sumChargedHadronPt_);
    b_pf_mus_pfIsolationR03_sumChargedHadronPt_->GetEntry(entry_);
    c_pf_mus_pfIsolationR03_sumChargedHadronPt_ = true;
  }
  return pf_mus_pfIsolationR03_sumChargedHadronPt_;
}

std::vector<float>* const & cfa_8::pf_mus_pfIsolationR03_sumChargedParticlePt() const{
  if(!c_pf_mus_pfIsolationR03_sumChargedParticlePt_ && b_pf_mus_pfIsolationR03_sumChargedParticlePt_){
    b_pf_mus_pfIsolationR03_sumChargedParticlePt_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_pfIsolationR03_sumChargedParticlePt", &pf_mus_pfIsolationR03_sumChargedParticlePt_, &b_pf_mus_pfIsolationR03_sumChargedParticlePt_);
    b_pf_mus_pfIsolationR03_sumChargedParticlePt_->GetEntry(entry_);
    c_pf_mus_pfIsolationR03_sumChargedParticlePt_ = true;
  }
  return pf_mus_pfIsolationR03_sumChargedParticlePt_;
}

std::vector<float>* const & cfa_8::pf_mus_pfIsolationR03_sumNeutralHadronEt() const{
  if(!c_pf_mus_pfIsolationR03_sumNeutralHadronEt_ && b_pf_mus_pfIsolationR03_sumNeutralHadronEt_){
    b_pf_mus_pfIsolationR03_sumNeutralHadronEt_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_pfIsolationR03_sumNeutralHadronEt", &pf_mus_pfIsolationR03_sumNeutralHadronEt_, &b_pf_mus_pfIsolationR03_sumNeutralHadronEt_);
    b_pf_mus_pfIsolationR03_sumNeutralHadronEt_->GetEntry(entry_);
    c_pf_mus_pfIsolationR03_sumNeutralHadronEt_ = true;
  }
  return pf_mus_pfIsolationR03_sumNeutralHadronEt_;
}

std::vector<float>* const & cfa_8::pf_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold() const{
  if(!c_pf_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_ && b_pf_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_){
    b_pf_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold", &pf_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_, &b_pf_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_);
    b_pf_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_->GetEntry(entry_);
    c_pf_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_ = true;
  }
  return pf_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_;
}

std::vector<float>* const & cfa_8::pf_mus_pfIsolationR03_sumPUPt() const{
  if(!c_pf_mus_pfIsolationR03_sumPUPt_ && b_pf_mus_pfIsolationR03_sumPUPt_){
    b_pf_mus_pfIsolationR03_sumPUPt_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_pfIsolationR03_sumPUPt", &pf_mus_pfIsolationR03_sumPUPt_, &b_pf_mus_pfIsolationR03_sumPUPt_);
    b_pf_mus_pfIsolationR03_sumPUPt_->GetEntry(entry_);
    c_pf_mus_pfIsolationR03_sumPUPt_ = true;
  }
  return pf_mus_pfIsolationR03_sumPUPt_;
}

std::vector<float>* const & cfa_8::pf_mus_pfIsolationR03_sumPhotonEt() const{
  if(!c_pf_mus_pfIsolationR03_sumPhotonEt_ && b_pf_mus_pfIsolationR03_sumPhotonEt_){
    b_pf_mus_pfIsolationR03_sumPhotonEt_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_pfIsolationR03_sumPhotonEt", &pf_mus_pfIsolationR03_sumPhotonEt_, &b_pf_mus_pfIsolationR03_sumPhotonEt_);
    b_pf_mus_pfIsolationR03_sumPhotonEt_->GetEntry(entry_);
    c_pf_mus_pfIsolationR03_sumPhotonEt_ = true;
  }
  return pf_mus_pfIsolationR03_sumPhotonEt_;
}

std::vector<float>* const & cfa_8::pf_mus_pfIsolationR03_sumPhotonEtHighThreshold() const{
  if(!c_pf_mus_pfIsolationR03_sumPhotonEtHighThreshold_ && b_pf_mus_pfIsolationR03_sumPhotonEtHighThreshold_){
    b_pf_mus_pfIsolationR03_sumPhotonEtHighThreshold_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_pfIsolationR03_sumPhotonEtHighThreshold", &pf_mus_pfIsolationR03_sumPhotonEtHighThreshold_, &b_pf_mus_pfIsolationR03_sumPhotonEtHighThreshold_);
    b_pf_mus_pfIsolationR03_sumPhotonEtHighThreshold_->GetEntry(entry_);
    c_pf_mus_pfIsolationR03_sumPhotonEtHighThreshold_ = true;
  }
  return pf_mus_pfIsolationR03_sumPhotonEtHighThreshold_;
}

std::vector<float>* const & cfa_8::pf_mus_pfIsolationR04_sumChargedHadronPt() const{
  if(!c_pf_mus_pfIsolationR04_sumChargedHadronPt_ && b_pf_mus_pfIsolationR04_sumChargedHadronPt_){
    b_pf_mus_pfIsolationR04_sumChargedHadronPt_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_pfIsolationR04_sumChargedHadronPt", &pf_mus_pfIsolationR04_sumChargedHadronPt_, &b_pf_mus_pfIsolationR04_sumChargedHadronPt_);
    b_pf_mus_pfIsolationR04_sumChargedHadronPt_->GetEntry(entry_);
    c_pf_mus_pfIsolationR04_sumChargedHadronPt_ = true;
  }
  return pf_mus_pfIsolationR04_sumChargedHadronPt_;
}

std::vector<float>* const & cfa_8::pf_mus_pfIsolationR04_sumChargedParticlePt() const{
  if(!c_pf_mus_pfIsolationR04_sumChargedParticlePt_ && b_pf_mus_pfIsolationR04_sumChargedParticlePt_){
    b_pf_mus_pfIsolationR04_sumChargedParticlePt_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_pfIsolationR04_sumChargedParticlePt", &pf_mus_pfIsolationR04_sumChargedParticlePt_, &b_pf_mus_pfIsolationR04_sumChargedParticlePt_);
    b_pf_mus_pfIsolationR04_sumChargedParticlePt_->GetEntry(entry_);
    c_pf_mus_pfIsolationR04_sumChargedParticlePt_ = true;
  }
  return pf_mus_pfIsolationR04_sumChargedParticlePt_;
}

std::vector<float>* const & cfa_8::pf_mus_pfIsolationR04_sumNeutralHadronEt() const{
  if(!c_pf_mus_pfIsolationR04_sumNeutralHadronEt_ && b_pf_mus_pfIsolationR04_sumNeutralHadronEt_){
    b_pf_mus_pfIsolationR04_sumNeutralHadronEt_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_pfIsolationR04_sumNeutralHadronEt", &pf_mus_pfIsolationR04_sumNeutralHadronEt_, &b_pf_mus_pfIsolationR04_sumNeutralHadronEt_);
    b_pf_mus_pfIsolationR04_sumNeutralHadronEt_->GetEntry(entry_);
    c_pf_mus_pfIsolationR04_sumNeutralHadronEt_ = true;
  }
  return pf_mus_pfIsolationR04_sumNeutralHadronEt_;
}

std::vector<float>* const & cfa_8::pf_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold() const{
  if(!c_pf_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_ && b_pf_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_){
    b_pf_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold", &pf_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_, &b_pf_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_);
    b_pf_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_->GetEntry(entry_);
    c_pf_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_ = true;
  }
  return pf_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_;
}

std::vector<float>* const & cfa_8::pf_mus_pfIsolationR04_sumPUPt() const{
  if(!c_pf_mus_pfIsolationR04_sumPUPt_ && b_pf_mus_pfIsolationR04_sumPUPt_){
    b_pf_mus_pfIsolationR04_sumPUPt_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_pfIsolationR04_sumPUPt", &pf_mus_pfIsolationR04_sumPUPt_, &b_pf_mus_pfIsolationR04_sumPUPt_);
    b_pf_mus_pfIsolationR04_sumPUPt_->GetEntry(entry_);
    c_pf_mus_pfIsolationR04_sumPUPt_ = true;
  }
  return pf_mus_pfIsolationR04_sumPUPt_;
}

std::vector<float>* const & cfa_8::pf_mus_pfIsolationR04_sumPhotonEt() const{
  if(!c_pf_mus_pfIsolationR04_sumPhotonEt_ && b_pf_mus_pfIsolationR04_sumPhotonEt_){
    b_pf_mus_pfIsolationR04_sumPhotonEt_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_pfIsolationR04_sumPhotonEt", &pf_mus_pfIsolationR04_sumPhotonEt_, &b_pf_mus_pfIsolationR04_sumPhotonEt_);
    b_pf_mus_pfIsolationR04_sumPhotonEt_->GetEntry(entry_);
    c_pf_mus_pfIsolationR04_sumPhotonEt_ = true;
  }
  return pf_mus_pfIsolationR04_sumPhotonEt_;
}

std::vector<float>* const & cfa_8::pf_mus_pfIsolationR04_sumPhotonEtHighThreshold() const{
  if(!c_pf_mus_pfIsolationR04_sumPhotonEtHighThreshold_ && b_pf_mus_pfIsolationR04_sumPhotonEtHighThreshold_){
    b_pf_mus_pfIsolationR04_sumPhotonEtHighThreshold_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_pfIsolationR04_sumPhotonEtHighThreshold", &pf_mus_pfIsolationR04_sumPhotonEtHighThreshold_, &b_pf_mus_pfIsolationR04_sumPhotonEtHighThreshold_);
    b_pf_mus_pfIsolationR04_sumPhotonEtHighThreshold_->GetEntry(entry_);
    c_pf_mus_pfIsolationR04_sumPhotonEtHighThreshold_ = true;
  }
  return pf_mus_pfIsolationR04_sumPhotonEtHighThreshold_;
}

std::vector<float>* const & cfa_8::pf_mus_phi() const{
  if(!c_pf_mus_phi_ && b_pf_mus_phi_){
    b_pf_mus_phi_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_phi", &pf_mus_phi_, &b_pf_mus_phi_);
    b_pf_mus_phi_->GetEntry(entry_);
    c_pf_mus_phi_ = true;
  }
  return pf_mus_phi_;
}

std::vector<float>* const & cfa_8::pf_mus_photonIso() const{
  if(!c_pf_mus_photonIso_ && b_pf_mus_photonIso_){
    b_pf_mus_photonIso_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_photonIso", &pf_mus_photonIso_, &b_pf_mus_photonIso_);
    b_pf_mus_photonIso_->GetEntry(entry_);
    c_pf_mus_photonIso_ = true;
  }
  return pf_mus_photonIso_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_ExpectedHitsInner() const{
  if(!c_pf_mus_picky_ExpectedHitsInner_ && b_pf_mus_picky_ExpectedHitsInner_){
    b_pf_mus_picky_ExpectedHitsInner_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_picky_ExpectedHitsInner", &pf_mus_picky_ExpectedHitsInner_, &b_pf_mus_picky_ExpectedHitsInner_);
    b_pf_mus_picky_ExpectedHitsInner_->GetEntry(entry_);
    c_pf_mus_picky_ExpectedHitsInner_ = true;
  }
  return pf_mus_picky_ExpectedHitsInner_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_ExpectedHitsOuter() const{
  if(!c_pf_mus_picky_ExpectedHitsOuter_ && b_pf_mus_picky_ExpectedHitsOuter_){
    b_pf_mus_picky_ExpectedHitsOuter_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_picky_ExpectedHitsOuter", &pf_mus_picky_ExpectedHitsOuter_, &b_pf_mus_picky_ExpectedHitsOuter_);
    b_pf_mus_picky_ExpectedHitsOuter_->GetEntry(entry_);
    c_pf_mus_picky_ExpectedHitsOuter_ = true;
  }
  return pf_mus_picky_ExpectedHitsOuter_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_LayersWithMeasurement() const{
  if(!c_pf_mus_picky_LayersWithMeasurement_ && b_pf_mus_picky_LayersWithMeasurement_){
    b_pf_mus_picky_LayersWithMeasurement_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_picky_LayersWithMeasurement", &pf_mus_picky_LayersWithMeasurement_, &b_pf_mus_picky_LayersWithMeasurement_);
    b_pf_mus_picky_LayersWithMeasurement_->GetEntry(entry_);
    c_pf_mus_picky_LayersWithMeasurement_ = true;
  }
  return pf_mus_picky_LayersWithMeasurement_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_LayersWithoutMeasurement() const{
  if(!c_pf_mus_picky_LayersWithoutMeasurement_ && b_pf_mus_picky_LayersWithoutMeasurement_){
    b_pf_mus_picky_LayersWithoutMeasurement_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_picky_LayersWithoutMeasurement", &pf_mus_picky_LayersWithoutMeasurement_, &b_pf_mus_picky_LayersWithoutMeasurement_);
    b_pf_mus_picky_LayersWithoutMeasurement_->GetEntry(entry_);
    c_pf_mus_picky_LayersWithoutMeasurement_ = true;
  }
  return pf_mus_picky_LayersWithoutMeasurement_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_PixelLayersWithMeasurement() const{
  if(!c_pf_mus_picky_PixelLayersWithMeasurement_ && b_pf_mus_picky_PixelLayersWithMeasurement_){
    b_pf_mus_picky_PixelLayersWithMeasurement_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_picky_PixelLayersWithMeasurement", &pf_mus_picky_PixelLayersWithMeasurement_, &b_pf_mus_picky_PixelLayersWithMeasurement_);
    b_pf_mus_picky_PixelLayersWithMeasurement_->GetEntry(entry_);
    c_pf_mus_picky_PixelLayersWithMeasurement_ = true;
  }
  return pf_mus_picky_PixelLayersWithMeasurement_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_ValidStripLayersWithMonoAndStereoHit() const{
  if(!c_pf_mus_picky_ValidStripLayersWithMonoAndStereoHit_ && b_pf_mus_picky_ValidStripLayersWithMonoAndStereoHit_){
    b_pf_mus_picky_ValidStripLayersWithMonoAndStereoHit_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_picky_ValidStripLayersWithMonoAndStereoHit", &pf_mus_picky_ValidStripLayersWithMonoAndStereoHit_, &b_pf_mus_picky_ValidStripLayersWithMonoAndStereoHit_);
    b_pf_mus_picky_ValidStripLayersWithMonoAndStereoHit_->GetEntry(entry_);
    c_pf_mus_picky_ValidStripLayersWithMonoAndStereoHit_ = true;
  }
  return pf_mus_picky_ValidStripLayersWithMonoAndStereoHit_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_chg() const{
  if(!c_pf_mus_picky_chg_ && b_pf_mus_picky_chg_){
    b_pf_mus_picky_chg_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_picky_chg", &pf_mus_picky_chg_, &b_pf_mus_picky_chg_);
    b_pf_mus_picky_chg_->GetEntry(entry_);
    c_pf_mus_picky_chg_ = true;
  }
  return pf_mus_picky_chg_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_chi2() const{
  if(!c_pf_mus_picky_chi2_ && b_pf_mus_picky_chi2_){
    b_pf_mus_picky_chi2_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_picky_chi2", &pf_mus_picky_chi2_, &b_pf_mus_picky_chi2_);
    b_pf_mus_picky_chi2_->GetEntry(entry_);
    c_pf_mus_picky_chi2_ = true;
  }
  return pf_mus_picky_chi2_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_d0dum() const{
  if(!c_pf_mus_picky_d0dum_ && b_pf_mus_picky_d0dum_){
    b_pf_mus_picky_d0dum_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_picky_d0dum", &pf_mus_picky_d0dum_, &b_pf_mus_picky_d0dum_);
    b_pf_mus_picky_d0dum_->GetEntry(entry_);
    c_pf_mus_picky_d0dum_ = true;
  }
  return pf_mus_picky_d0dum_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_d0dumErr() const{
  if(!c_pf_mus_picky_d0dumErr_ && b_pf_mus_picky_d0dumErr_){
    b_pf_mus_picky_d0dumErr_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_picky_d0dumErr", &pf_mus_picky_d0dumErr_, &b_pf_mus_picky_d0dumErr_);
    b_pf_mus_picky_d0dumErr_->GetEntry(entry_);
    c_pf_mus_picky_d0dumErr_ = true;
  }
  return pf_mus_picky_d0dumErr_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_dz() const{
  if(!c_pf_mus_picky_dz_ && b_pf_mus_picky_dz_){
    b_pf_mus_picky_dz_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_picky_dz", &pf_mus_picky_dz_, &b_pf_mus_picky_dz_);
    b_pf_mus_picky_dz_->GetEntry(entry_);
    c_pf_mus_picky_dz_ = true;
  }
  return pf_mus_picky_dz_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_dzErr() const{
  if(!c_pf_mus_picky_dzErr_ && b_pf_mus_picky_dzErr_){
    b_pf_mus_picky_dzErr_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_picky_dzErr", &pf_mus_picky_dzErr_, &b_pf_mus_picky_dzErr_);
    b_pf_mus_picky_dzErr_->GetEntry(entry_);
    c_pf_mus_picky_dzErr_ = true;
  }
  return pf_mus_picky_dzErr_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_eta() const{
  if(!c_pf_mus_picky_eta_ && b_pf_mus_picky_eta_){
    b_pf_mus_picky_eta_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_picky_eta", &pf_mus_picky_eta_, &b_pf_mus_picky_eta_);
    b_pf_mus_picky_eta_->GetEntry(entry_);
    c_pf_mus_picky_eta_ = true;
  }
  return pf_mus_picky_eta_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_etaErr() const{
  if(!c_pf_mus_picky_etaErr_ && b_pf_mus_picky_etaErr_){
    b_pf_mus_picky_etaErr_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_picky_etaErr", &pf_mus_picky_etaErr_, &b_pf_mus_picky_etaErr_);
    b_pf_mus_picky_etaErr_->GetEntry(entry_);
    c_pf_mus_picky_etaErr_ = true;
  }
  return pf_mus_picky_etaErr_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_id() const{
  if(!c_pf_mus_picky_id_ && b_pf_mus_picky_id_){
    b_pf_mus_picky_id_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_picky_id", &pf_mus_picky_id_, &b_pf_mus_picky_id_);
    b_pf_mus_picky_id_->GetEntry(entry_);
    c_pf_mus_picky_id_ = true;
  }
  return pf_mus_picky_id_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_ndof() const{
  if(!c_pf_mus_picky_ndof_ && b_pf_mus_picky_ndof_){
    b_pf_mus_picky_ndof_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_picky_ndof", &pf_mus_picky_ndof_, &b_pf_mus_picky_ndof_);
    b_pf_mus_picky_ndof_->GetEntry(entry_);
    c_pf_mus_picky_ndof_ = true;
  }
  return pf_mus_picky_ndof_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_numlosthits() const{
  if(!c_pf_mus_picky_numlosthits_ && b_pf_mus_picky_numlosthits_){
    b_pf_mus_picky_numlosthits_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_picky_numlosthits", &pf_mus_picky_numlosthits_, &b_pf_mus_picky_numlosthits_);
    b_pf_mus_picky_numlosthits_->GetEntry(entry_);
    c_pf_mus_picky_numlosthits_ = true;
  }
  return pf_mus_picky_numlosthits_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_numvalPixelhits() const{
  if(!c_pf_mus_picky_numvalPixelhits_ && b_pf_mus_picky_numvalPixelhits_){
    b_pf_mus_picky_numvalPixelhits_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_picky_numvalPixelhits", &pf_mus_picky_numvalPixelhits_, &b_pf_mus_picky_numvalPixelhits_);
    b_pf_mus_picky_numvalPixelhits_->GetEntry(entry_);
    c_pf_mus_picky_numvalPixelhits_ = true;
  }
  return pf_mus_picky_numvalPixelhits_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_numvalhits() const{
  if(!c_pf_mus_picky_numvalhits_ && b_pf_mus_picky_numvalhits_){
    b_pf_mus_picky_numvalhits_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_picky_numvalhits", &pf_mus_picky_numvalhits_, &b_pf_mus_picky_numvalhits_);
    b_pf_mus_picky_numvalhits_->GetEntry(entry_);
    c_pf_mus_picky_numvalhits_ = true;
  }
  return pf_mus_picky_numvalhits_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_phi() const{
  if(!c_pf_mus_picky_phi_ && b_pf_mus_picky_phi_){
    b_pf_mus_picky_phi_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_picky_phi", &pf_mus_picky_phi_, &b_pf_mus_picky_phi_);
    b_pf_mus_picky_phi_->GetEntry(entry_);
    c_pf_mus_picky_phi_ = true;
  }
  return pf_mus_picky_phi_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_phiErr() const{
  if(!c_pf_mus_picky_phiErr_ && b_pf_mus_picky_phiErr_){
    b_pf_mus_picky_phiErr_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_picky_phiErr", &pf_mus_picky_phiErr_, &b_pf_mus_picky_phiErr_);
    b_pf_mus_picky_phiErr_->GetEntry(entry_);
    c_pf_mus_picky_phiErr_ = true;
  }
  return pf_mus_picky_phiErr_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_pt() const{
  if(!c_pf_mus_picky_pt_ && b_pf_mus_picky_pt_){
    b_pf_mus_picky_pt_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_picky_pt", &pf_mus_picky_pt_, &b_pf_mus_picky_pt_);
    b_pf_mus_picky_pt_->GetEntry(entry_);
    c_pf_mus_picky_pt_ = true;
  }
  return pf_mus_picky_pt_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_ptErr() const{
  if(!c_pf_mus_picky_ptErr_ && b_pf_mus_picky_ptErr_){
    b_pf_mus_picky_ptErr_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_picky_ptErr", &pf_mus_picky_ptErr_, &b_pf_mus_picky_ptErr_);
    b_pf_mus_picky_ptErr_->GetEntry(entry_);
    c_pf_mus_picky_ptErr_ = true;
  }
  return pf_mus_picky_ptErr_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_px() const{
  if(!c_pf_mus_picky_px_ && b_pf_mus_picky_px_){
    b_pf_mus_picky_px_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_picky_px", &pf_mus_picky_px_, &b_pf_mus_picky_px_);
    b_pf_mus_picky_px_->GetEntry(entry_);
    c_pf_mus_picky_px_ = true;
  }
  return pf_mus_picky_px_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_py() const{
  if(!c_pf_mus_picky_py_ && b_pf_mus_picky_py_){
    b_pf_mus_picky_py_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_picky_py", &pf_mus_picky_py_, &b_pf_mus_picky_py_);
    b_pf_mus_picky_py_->GetEntry(entry_);
    c_pf_mus_picky_py_ = true;
  }
  return pf_mus_picky_py_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_pz() const{
  if(!c_pf_mus_picky_pz_ && b_pf_mus_picky_pz_){
    b_pf_mus_picky_pz_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_picky_pz", &pf_mus_picky_pz_, &b_pf_mus_picky_pz_);
    b_pf_mus_picky_pz_->GetEntry(entry_);
    c_pf_mus_picky_pz_ = true;
  }
  return pf_mus_picky_pz_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_theta() const{
  if(!c_pf_mus_picky_theta_ && b_pf_mus_picky_theta_){
    b_pf_mus_picky_theta_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_picky_theta", &pf_mus_picky_theta_, &b_pf_mus_picky_theta_);
    b_pf_mus_picky_theta_->GetEntry(entry_);
    c_pf_mus_picky_theta_ = true;
  }
  return pf_mus_picky_theta_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_vx() const{
  if(!c_pf_mus_picky_vx_ && b_pf_mus_picky_vx_){
    b_pf_mus_picky_vx_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_picky_vx", &pf_mus_picky_vx_, &b_pf_mus_picky_vx_);
    b_pf_mus_picky_vx_->GetEntry(entry_);
    c_pf_mus_picky_vx_ = true;
  }
  return pf_mus_picky_vx_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_vy() const{
  if(!c_pf_mus_picky_vy_ && b_pf_mus_picky_vy_){
    b_pf_mus_picky_vy_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_picky_vy", &pf_mus_picky_vy_, &b_pf_mus_picky_vy_);
    b_pf_mus_picky_vy_->GetEntry(entry_);
    c_pf_mus_picky_vy_ = true;
  }
  return pf_mus_picky_vy_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_vz() const{
  if(!c_pf_mus_picky_vz_ && b_pf_mus_picky_vz_){
    b_pf_mus_picky_vz_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_picky_vz", &pf_mus_picky_vz_, &b_pf_mus_picky_vz_);
    b_pf_mus_picky_vz_->GetEntry(entry_);
    c_pf_mus_picky_vz_ = true;
  }
  return pf_mus_picky_vz_;
}

std::vector<float>* const & cfa_8::pf_mus_pt() const{
  if(!c_pf_mus_pt_ && b_pf_mus_pt_){
    b_pf_mus_pt_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_pt", &pf_mus_pt_, &b_pf_mus_pt_);
    b_pf_mus_pt_->GetEntry(entry_);
    c_pf_mus_pt_ = true;
  }
  return pf_mus_pt_;
}

std::vector<float>* const & cfa_8::pf_mus_px() const{
  if(!c_pf_mus_px_ && b_pf_mus_px_){
    b_pf_mus_px_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_px", &pf_mus_px_, &b_pf_mus_px_);
    b_pf_mus_px_->GetEntry(entry_);
    c_pf_mus_px_ = true;
  }
  return pf_mus_px_;
}

std::vector<float>* const & cfa_8::pf_mus_py() const{
  if(!c_pf_mus_py_ && b_pf_mus_py_){
    b_pf_mus_py_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_py", &pf_mus_py_, &b_pf_mus_py_);
    b_pf_mus_py_->GetEntry(entry_);
    c_pf_mus_py_ = true;
  }
  return pf_mus_py_;
}

std::vector<float>* const & cfa_8::pf_mus_pz() const{
  if(!c_pf_mus_pz_ && b_pf_mus_pz_){
    b_pf_mus_pz_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_pz", &pf_mus_pz_, &b_pf_mus_pz_);
    b_pf_mus_pz_->GetEntry(entry_);
    c_pf_mus_pz_ = true;
  }
  return pf_mus_pz_;
}

std::vector<float>* const & cfa_8::pf_mus_stamu_chg() const{
  if(!c_pf_mus_stamu_chg_ && b_pf_mus_stamu_chg_){
    b_pf_mus_stamu_chg_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_stamu_chg", &pf_mus_stamu_chg_, &b_pf_mus_stamu_chg_);
    b_pf_mus_stamu_chg_->GetEntry(entry_);
    c_pf_mus_stamu_chg_ = true;
  }
  return pf_mus_stamu_chg_;
}

std::vector<float>* const & cfa_8::pf_mus_stamu_chi2() const{
  if(!c_pf_mus_stamu_chi2_ && b_pf_mus_stamu_chi2_){
    b_pf_mus_stamu_chi2_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_stamu_chi2", &pf_mus_stamu_chi2_, &b_pf_mus_stamu_chi2_);
    b_pf_mus_stamu_chi2_->GetEntry(entry_);
    c_pf_mus_stamu_chi2_ = true;
  }
  return pf_mus_stamu_chi2_;
}

std::vector<float>* const & cfa_8::pf_mus_stamu_d0dum() const{
  if(!c_pf_mus_stamu_d0dum_ && b_pf_mus_stamu_d0dum_){
    b_pf_mus_stamu_d0dum_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_stamu_d0dum", &pf_mus_stamu_d0dum_, &b_pf_mus_stamu_d0dum_);
    b_pf_mus_stamu_d0dum_->GetEntry(entry_);
    c_pf_mus_stamu_d0dum_ = true;
  }
  return pf_mus_stamu_d0dum_;
}

std::vector<float>* const & cfa_8::pf_mus_stamu_d0dumErr() const{
  if(!c_pf_mus_stamu_d0dumErr_ && b_pf_mus_stamu_d0dumErr_){
    b_pf_mus_stamu_d0dumErr_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_stamu_d0dumErr", &pf_mus_stamu_d0dumErr_, &b_pf_mus_stamu_d0dumErr_);
    b_pf_mus_stamu_d0dumErr_->GetEntry(entry_);
    c_pf_mus_stamu_d0dumErr_ = true;
  }
  return pf_mus_stamu_d0dumErr_;
}

std::vector<float>* const & cfa_8::pf_mus_stamu_dz() const{
  if(!c_pf_mus_stamu_dz_ && b_pf_mus_stamu_dz_){
    b_pf_mus_stamu_dz_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_stamu_dz", &pf_mus_stamu_dz_, &b_pf_mus_stamu_dz_);
    b_pf_mus_stamu_dz_->GetEntry(entry_);
    c_pf_mus_stamu_dz_ = true;
  }
  return pf_mus_stamu_dz_;
}

std::vector<float>* const & cfa_8::pf_mus_stamu_dzErr() const{
  if(!c_pf_mus_stamu_dzErr_ && b_pf_mus_stamu_dzErr_){
    b_pf_mus_stamu_dzErr_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_stamu_dzErr", &pf_mus_stamu_dzErr_, &b_pf_mus_stamu_dzErr_);
    b_pf_mus_stamu_dzErr_->GetEntry(entry_);
    c_pf_mus_stamu_dzErr_ = true;
  }
  return pf_mus_stamu_dzErr_;
}

std::vector<float>* const & cfa_8::pf_mus_stamu_eta() const{
  if(!c_pf_mus_stamu_eta_ && b_pf_mus_stamu_eta_){
    b_pf_mus_stamu_eta_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_stamu_eta", &pf_mus_stamu_eta_, &b_pf_mus_stamu_eta_);
    b_pf_mus_stamu_eta_->GetEntry(entry_);
    c_pf_mus_stamu_eta_ = true;
  }
  return pf_mus_stamu_eta_;
}

std::vector<float>* const & cfa_8::pf_mus_stamu_etaErr() const{
  if(!c_pf_mus_stamu_etaErr_ && b_pf_mus_stamu_etaErr_){
    b_pf_mus_stamu_etaErr_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_stamu_etaErr", &pf_mus_stamu_etaErr_, &b_pf_mus_stamu_etaErr_);
    b_pf_mus_stamu_etaErr_->GetEntry(entry_);
    c_pf_mus_stamu_etaErr_ = true;
  }
  return pf_mus_stamu_etaErr_;
}

std::vector<float>* const & cfa_8::pf_mus_stamu_ndof() const{
  if(!c_pf_mus_stamu_ndof_ && b_pf_mus_stamu_ndof_){
    b_pf_mus_stamu_ndof_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_stamu_ndof", &pf_mus_stamu_ndof_, &b_pf_mus_stamu_ndof_);
    b_pf_mus_stamu_ndof_->GetEntry(entry_);
    c_pf_mus_stamu_ndof_ = true;
  }
  return pf_mus_stamu_ndof_;
}

std::vector<float>* const & cfa_8::pf_mus_stamu_numlosthits() const{
  if(!c_pf_mus_stamu_numlosthits_ && b_pf_mus_stamu_numlosthits_){
    b_pf_mus_stamu_numlosthits_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_stamu_numlosthits", &pf_mus_stamu_numlosthits_, &b_pf_mus_stamu_numlosthits_);
    b_pf_mus_stamu_numlosthits_->GetEntry(entry_);
    c_pf_mus_stamu_numlosthits_ = true;
  }
  return pf_mus_stamu_numlosthits_;
}

std::vector<float>* const & cfa_8::pf_mus_stamu_numvalhits() const{
  if(!c_pf_mus_stamu_numvalhits_ && b_pf_mus_stamu_numvalhits_){
    b_pf_mus_stamu_numvalhits_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_stamu_numvalhits", &pf_mus_stamu_numvalhits_, &b_pf_mus_stamu_numvalhits_);
    b_pf_mus_stamu_numvalhits_->GetEntry(entry_);
    c_pf_mus_stamu_numvalhits_ = true;
  }
  return pf_mus_stamu_numvalhits_;
}

std::vector<float>* const & cfa_8::pf_mus_stamu_phi() const{
  if(!c_pf_mus_stamu_phi_ && b_pf_mus_stamu_phi_){
    b_pf_mus_stamu_phi_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_stamu_phi", &pf_mus_stamu_phi_, &b_pf_mus_stamu_phi_);
    b_pf_mus_stamu_phi_->GetEntry(entry_);
    c_pf_mus_stamu_phi_ = true;
  }
  return pf_mus_stamu_phi_;
}

std::vector<float>* const & cfa_8::pf_mus_stamu_phiErr() const{
  if(!c_pf_mus_stamu_phiErr_ && b_pf_mus_stamu_phiErr_){
    b_pf_mus_stamu_phiErr_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_stamu_phiErr", &pf_mus_stamu_phiErr_, &b_pf_mus_stamu_phiErr_);
    b_pf_mus_stamu_phiErr_->GetEntry(entry_);
    c_pf_mus_stamu_phiErr_ = true;
  }
  return pf_mus_stamu_phiErr_;
}

std::vector<float>* const & cfa_8::pf_mus_stamu_pt() const{
  if(!c_pf_mus_stamu_pt_ && b_pf_mus_stamu_pt_){
    b_pf_mus_stamu_pt_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_stamu_pt", &pf_mus_stamu_pt_, &b_pf_mus_stamu_pt_);
    b_pf_mus_stamu_pt_->GetEntry(entry_);
    c_pf_mus_stamu_pt_ = true;
  }
  return pf_mus_stamu_pt_;
}

std::vector<float>* const & cfa_8::pf_mus_stamu_ptErr() const{
  if(!c_pf_mus_stamu_ptErr_ && b_pf_mus_stamu_ptErr_){
    b_pf_mus_stamu_ptErr_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_stamu_ptErr", &pf_mus_stamu_ptErr_, &b_pf_mus_stamu_ptErr_);
    b_pf_mus_stamu_ptErr_->GetEntry(entry_);
    c_pf_mus_stamu_ptErr_ = true;
  }
  return pf_mus_stamu_ptErr_;
}

std::vector<float>* const & cfa_8::pf_mus_stamu_px() const{
  if(!c_pf_mus_stamu_px_ && b_pf_mus_stamu_px_){
    b_pf_mus_stamu_px_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_stamu_px", &pf_mus_stamu_px_, &b_pf_mus_stamu_px_);
    b_pf_mus_stamu_px_->GetEntry(entry_);
    c_pf_mus_stamu_px_ = true;
  }
  return pf_mus_stamu_px_;
}

std::vector<float>* const & cfa_8::pf_mus_stamu_py() const{
  if(!c_pf_mus_stamu_py_ && b_pf_mus_stamu_py_){
    b_pf_mus_stamu_py_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_stamu_py", &pf_mus_stamu_py_, &b_pf_mus_stamu_py_);
    b_pf_mus_stamu_py_->GetEntry(entry_);
    c_pf_mus_stamu_py_ = true;
  }
  return pf_mus_stamu_py_;
}

std::vector<float>* const & cfa_8::pf_mus_stamu_pz() const{
  if(!c_pf_mus_stamu_pz_ && b_pf_mus_stamu_pz_){
    b_pf_mus_stamu_pz_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_stamu_pz", &pf_mus_stamu_pz_, &b_pf_mus_stamu_pz_);
    b_pf_mus_stamu_pz_->GetEntry(entry_);
    c_pf_mus_stamu_pz_ = true;
  }
  return pf_mus_stamu_pz_;
}

std::vector<float>* const & cfa_8::pf_mus_stamu_theta() const{
  if(!c_pf_mus_stamu_theta_ && b_pf_mus_stamu_theta_){
    b_pf_mus_stamu_theta_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_stamu_theta", &pf_mus_stamu_theta_, &b_pf_mus_stamu_theta_);
    b_pf_mus_stamu_theta_->GetEntry(entry_);
    c_pf_mus_stamu_theta_ = true;
  }
  return pf_mus_stamu_theta_;
}

std::vector<float>* const & cfa_8::pf_mus_stamu_vx() const{
  if(!c_pf_mus_stamu_vx_ && b_pf_mus_stamu_vx_){
    b_pf_mus_stamu_vx_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_stamu_vx", &pf_mus_stamu_vx_, &b_pf_mus_stamu_vx_);
    b_pf_mus_stamu_vx_->GetEntry(entry_);
    c_pf_mus_stamu_vx_ = true;
  }
  return pf_mus_stamu_vx_;
}

std::vector<float>* const & cfa_8::pf_mus_stamu_vy() const{
  if(!c_pf_mus_stamu_vy_ && b_pf_mus_stamu_vy_){
    b_pf_mus_stamu_vy_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_stamu_vy", &pf_mus_stamu_vy_, &b_pf_mus_stamu_vy_);
    b_pf_mus_stamu_vy_->GetEntry(entry_);
    c_pf_mus_stamu_vy_ = true;
  }
  return pf_mus_stamu_vy_;
}

std::vector<float>* const & cfa_8::pf_mus_stamu_vz() const{
  if(!c_pf_mus_stamu_vz_ && b_pf_mus_stamu_vz_){
    b_pf_mus_stamu_vz_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_stamu_vz", &pf_mus_stamu_vz_, &b_pf_mus_stamu_vz_);
    b_pf_mus_stamu_vz_->GetEntry(entry_);
    c_pf_mus_stamu_vz_ = true;
  }
  return pf_mus_stamu_vz_;
}

std::vector<float>* const & cfa_8::pf_mus_status() const{
  if(!c_pf_mus_status_ && b_pf_mus_status_){
    b_pf_mus_status_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_status", &pf_mus_status_, &b_pf_mus_status_);
    b_pf_mus_status_->GetEntry(entry_);
    c_pf_mus_status_ = true;
  }
  return pf_mus_status_;
}

std::vector<float>* const & cfa_8::pf_mus_tIso() const{
  if(!c_pf_mus_tIso_ && b_pf_mus_tIso_){
    b_pf_mus_tIso_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tIso", &pf_mus_tIso_, &b_pf_mus_tIso_);
    b_pf_mus_tIso_->GetEntry(entry_);
    c_pf_mus_tIso_ = true;
  }
  return pf_mus_tIso_;
}

std::vector<float>* const & cfa_8::pf_mus_theta() const{
  if(!c_pf_mus_theta_ && b_pf_mus_theta_){
    b_pf_mus_theta_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_theta", &pf_mus_theta_, &b_pf_mus_theta_);
    b_pf_mus_theta_->GetEntry(entry_);
    c_pf_mus_theta_ = true;
  }
  return pf_mus_theta_;
}

std::vector<float>* const & cfa_8::pf_mus_tkHits() const{
  if(!c_pf_mus_tkHits_ && b_pf_mus_tkHits_){
    b_pf_mus_tkHits_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tkHits", &pf_mus_tkHits_, &b_pf_mus_tkHits_);
    b_pf_mus_tkHits_->GetEntry(entry_);
    c_pf_mus_tkHits_ = true;
  }
  return pf_mus_tkHits_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_ExpectedHitsInner() const{
  if(!c_pf_mus_tk_ExpectedHitsInner_ && b_pf_mus_tk_ExpectedHitsInner_){
    b_pf_mus_tk_ExpectedHitsInner_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tk_ExpectedHitsInner", &pf_mus_tk_ExpectedHitsInner_, &b_pf_mus_tk_ExpectedHitsInner_);
    b_pf_mus_tk_ExpectedHitsInner_->GetEntry(entry_);
    c_pf_mus_tk_ExpectedHitsInner_ = true;
  }
  return pf_mus_tk_ExpectedHitsInner_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_ExpectedHitsOuter() const{
  if(!c_pf_mus_tk_ExpectedHitsOuter_ && b_pf_mus_tk_ExpectedHitsOuter_){
    b_pf_mus_tk_ExpectedHitsOuter_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tk_ExpectedHitsOuter", &pf_mus_tk_ExpectedHitsOuter_, &b_pf_mus_tk_ExpectedHitsOuter_);
    b_pf_mus_tk_ExpectedHitsOuter_->GetEntry(entry_);
    c_pf_mus_tk_ExpectedHitsOuter_ = true;
  }
  return pf_mus_tk_ExpectedHitsOuter_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_LayersWithMeasurement() const{
  if(!c_pf_mus_tk_LayersWithMeasurement_ && b_pf_mus_tk_LayersWithMeasurement_){
    b_pf_mus_tk_LayersWithMeasurement_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tk_LayersWithMeasurement", &pf_mus_tk_LayersWithMeasurement_, &b_pf_mus_tk_LayersWithMeasurement_);
    b_pf_mus_tk_LayersWithMeasurement_->GetEntry(entry_);
    c_pf_mus_tk_LayersWithMeasurement_ = true;
  }
  return pf_mus_tk_LayersWithMeasurement_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_LayersWithoutMeasurement() const{
  if(!c_pf_mus_tk_LayersWithoutMeasurement_ && b_pf_mus_tk_LayersWithoutMeasurement_){
    b_pf_mus_tk_LayersWithoutMeasurement_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tk_LayersWithoutMeasurement", &pf_mus_tk_LayersWithoutMeasurement_, &b_pf_mus_tk_LayersWithoutMeasurement_);
    b_pf_mus_tk_LayersWithoutMeasurement_->GetEntry(entry_);
    c_pf_mus_tk_LayersWithoutMeasurement_ = true;
  }
  return pf_mus_tk_LayersWithoutMeasurement_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_PixelLayersWithMeasurement() const{
  if(!c_pf_mus_tk_PixelLayersWithMeasurement_ && b_pf_mus_tk_PixelLayersWithMeasurement_){
    b_pf_mus_tk_PixelLayersWithMeasurement_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tk_PixelLayersWithMeasurement", &pf_mus_tk_PixelLayersWithMeasurement_, &b_pf_mus_tk_PixelLayersWithMeasurement_);
    b_pf_mus_tk_PixelLayersWithMeasurement_->GetEntry(entry_);
    c_pf_mus_tk_PixelLayersWithMeasurement_ = true;
  }
  return pf_mus_tk_PixelLayersWithMeasurement_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_ValidStripLayersWithMonoAndStereoHit() const{
  if(!c_pf_mus_tk_ValidStripLayersWithMonoAndStereoHit_ && b_pf_mus_tk_ValidStripLayersWithMonoAndStereoHit_){
    b_pf_mus_tk_ValidStripLayersWithMonoAndStereoHit_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tk_ValidStripLayersWithMonoAndStereoHit", &pf_mus_tk_ValidStripLayersWithMonoAndStereoHit_, &b_pf_mus_tk_ValidStripLayersWithMonoAndStereoHit_);
    b_pf_mus_tk_ValidStripLayersWithMonoAndStereoHit_->GetEntry(entry_);
    c_pf_mus_tk_ValidStripLayersWithMonoAndStereoHit_ = true;
  }
  return pf_mus_tk_ValidStripLayersWithMonoAndStereoHit_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_chg() const{
  if(!c_pf_mus_tk_chg_ && b_pf_mus_tk_chg_){
    b_pf_mus_tk_chg_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tk_chg", &pf_mus_tk_chg_, &b_pf_mus_tk_chg_);
    b_pf_mus_tk_chg_->GetEntry(entry_);
    c_pf_mus_tk_chg_ = true;
  }
  return pf_mus_tk_chg_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_chi2() const{
  if(!c_pf_mus_tk_chi2_ && b_pf_mus_tk_chi2_){
    b_pf_mus_tk_chi2_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tk_chi2", &pf_mus_tk_chi2_, &b_pf_mus_tk_chi2_);
    b_pf_mus_tk_chi2_->GetEntry(entry_);
    c_pf_mus_tk_chi2_ = true;
  }
  return pf_mus_tk_chi2_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_d0dum() const{
  if(!c_pf_mus_tk_d0dum_ && b_pf_mus_tk_d0dum_){
    b_pf_mus_tk_d0dum_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tk_d0dum", &pf_mus_tk_d0dum_, &b_pf_mus_tk_d0dum_);
    b_pf_mus_tk_d0dum_->GetEntry(entry_);
    c_pf_mus_tk_d0dum_ = true;
  }
  return pf_mus_tk_d0dum_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_d0dumErr() const{
  if(!c_pf_mus_tk_d0dumErr_ && b_pf_mus_tk_d0dumErr_){
    b_pf_mus_tk_d0dumErr_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tk_d0dumErr", &pf_mus_tk_d0dumErr_, &b_pf_mus_tk_d0dumErr_);
    b_pf_mus_tk_d0dumErr_->GetEntry(entry_);
    c_pf_mus_tk_d0dumErr_ = true;
  }
  return pf_mus_tk_d0dumErr_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_dz() const{
  if(!c_pf_mus_tk_dz_ && b_pf_mus_tk_dz_){
    b_pf_mus_tk_dz_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tk_dz", &pf_mus_tk_dz_, &b_pf_mus_tk_dz_);
    b_pf_mus_tk_dz_->GetEntry(entry_);
    c_pf_mus_tk_dz_ = true;
  }
  return pf_mus_tk_dz_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_dzErr() const{
  if(!c_pf_mus_tk_dzErr_ && b_pf_mus_tk_dzErr_){
    b_pf_mus_tk_dzErr_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tk_dzErr", &pf_mus_tk_dzErr_, &b_pf_mus_tk_dzErr_);
    b_pf_mus_tk_dzErr_->GetEntry(entry_);
    c_pf_mus_tk_dzErr_ = true;
  }
  return pf_mus_tk_dzErr_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_eta() const{
  if(!c_pf_mus_tk_eta_ && b_pf_mus_tk_eta_){
    b_pf_mus_tk_eta_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tk_eta", &pf_mus_tk_eta_, &b_pf_mus_tk_eta_);
    b_pf_mus_tk_eta_->GetEntry(entry_);
    c_pf_mus_tk_eta_ = true;
  }
  return pf_mus_tk_eta_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_etaErr() const{
  if(!c_pf_mus_tk_etaErr_ && b_pf_mus_tk_etaErr_){
    b_pf_mus_tk_etaErr_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tk_etaErr", &pf_mus_tk_etaErr_, &b_pf_mus_tk_etaErr_);
    b_pf_mus_tk_etaErr_->GetEntry(entry_);
    c_pf_mus_tk_etaErr_ = true;
  }
  return pf_mus_tk_etaErr_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_id() const{
  if(!c_pf_mus_tk_id_ && b_pf_mus_tk_id_){
    b_pf_mus_tk_id_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tk_id", &pf_mus_tk_id_, &b_pf_mus_tk_id_);
    b_pf_mus_tk_id_->GetEntry(entry_);
    c_pf_mus_tk_id_ = true;
  }
  return pf_mus_tk_id_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_ndof() const{
  if(!c_pf_mus_tk_ndof_ && b_pf_mus_tk_ndof_){
    b_pf_mus_tk_ndof_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tk_ndof", &pf_mus_tk_ndof_, &b_pf_mus_tk_ndof_);
    b_pf_mus_tk_ndof_->GetEntry(entry_);
    c_pf_mus_tk_ndof_ = true;
  }
  return pf_mus_tk_ndof_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_numlosthits() const{
  if(!c_pf_mus_tk_numlosthits_ && b_pf_mus_tk_numlosthits_){
    b_pf_mus_tk_numlosthits_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tk_numlosthits", &pf_mus_tk_numlosthits_, &b_pf_mus_tk_numlosthits_);
    b_pf_mus_tk_numlosthits_->GetEntry(entry_);
    c_pf_mus_tk_numlosthits_ = true;
  }
  return pf_mus_tk_numlosthits_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_numpixelWthMeasr() const{
  if(!c_pf_mus_tk_numpixelWthMeasr_ && b_pf_mus_tk_numpixelWthMeasr_){
    b_pf_mus_tk_numpixelWthMeasr_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tk_numpixelWthMeasr", &pf_mus_tk_numpixelWthMeasr_, &b_pf_mus_tk_numpixelWthMeasr_);
    b_pf_mus_tk_numpixelWthMeasr_->GetEntry(entry_);
    c_pf_mus_tk_numpixelWthMeasr_ = true;
  }
  return pf_mus_tk_numpixelWthMeasr_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_numvalPixelhits() const{
  if(!c_pf_mus_tk_numvalPixelhits_ && b_pf_mus_tk_numvalPixelhits_){
    b_pf_mus_tk_numvalPixelhits_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tk_numvalPixelhits", &pf_mus_tk_numvalPixelhits_, &b_pf_mus_tk_numvalPixelhits_);
    b_pf_mus_tk_numvalPixelhits_->GetEntry(entry_);
    c_pf_mus_tk_numvalPixelhits_ = true;
  }
  return pf_mus_tk_numvalPixelhits_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_numvalhits() const{
  if(!c_pf_mus_tk_numvalhits_ && b_pf_mus_tk_numvalhits_){
    b_pf_mus_tk_numvalhits_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tk_numvalhits", &pf_mus_tk_numvalhits_, &b_pf_mus_tk_numvalhits_);
    b_pf_mus_tk_numvalhits_->GetEntry(entry_);
    c_pf_mus_tk_numvalhits_ = true;
  }
  return pf_mus_tk_numvalhits_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_phi() const{
  if(!c_pf_mus_tk_phi_ && b_pf_mus_tk_phi_){
    b_pf_mus_tk_phi_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tk_phi", &pf_mus_tk_phi_, &b_pf_mus_tk_phi_);
    b_pf_mus_tk_phi_->GetEntry(entry_);
    c_pf_mus_tk_phi_ = true;
  }
  return pf_mus_tk_phi_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_phiErr() const{
  if(!c_pf_mus_tk_phiErr_ && b_pf_mus_tk_phiErr_){
    b_pf_mus_tk_phiErr_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tk_phiErr", &pf_mus_tk_phiErr_, &b_pf_mus_tk_phiErr_);
    b_pf_mus_tk_phiErr_->GetEntry(entry_);
    c_pf_mus_tk_phiErr_ = true;
  }
  return pf_mus_tk_phiErr_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_pt() const{
  if(!c_pf_mus_tk_pt_ && b_pf_mus_tk_pt_){
    b_pf_mus_tk_pt_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tk_pt", &pf_mus_tk_pt_, &b_pf_mus_tk_pt_);
    b_pf_mus_tk_pt_->GetEntry(entry_);
    c_pf_mus_tk_pt_ = true;
  }
  return pf_mus_tk_pt_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_ptErr() const{
  if(!c_pf_mus_tk_ptErr_ && b_pf_mus_tk_ptErr_){
    b_pf_mus_tk_ptErr_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tk_ptErr", &pf_mus_tk_ptErr_, &b_pf_mus_tk_ptErr_);
    b_pf_mus_tk_ptErr_->GetEntry(entry_);
    c_pf_mus_tk_ptErr_ = true;
  }
  return pf_mus_tk_ptErr_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_px() const{
  if(!c_pf_mus_tk_px_ && b_pf_mus_tk_px_){
    b_pf_mus_tk_px_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tk_px", &pf_mus_tk_px_, &b_pf_mus_tk_px_);
    b_pf_mus_tk_px_->GetEntry(entry_);
    c_pf_mus_tk_px_ = true;
  }
  return pf_mus_tk_px_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_py() const{
  if(!c_pf_mus_tk_py_ && b_pf_mus_tk_py_){
    b_pf_mus_tk_py_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tk_py", &pf_mus_tk_py_, &b_pf_mus_tk_py_);
    b_pf_mus_tk_py_->GetEntry(entry_);
    c_pf_mus_tk_py_ = true;
  }
  return pf_mus_tk_py_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_pz() const{
  if(!c_pf_mus_tk_pz_ && b_pf_mus_tk_pz_){
    b_pf_mus_tk_pz_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tk_pz", &pf_mus_tk_pz_, &b_pf_mus_tk_pz_);
    b_pf_mus_tk_pz_->GetEntry(entry_);
    c_pf_mus_tk_pz_ = true;
  }
  return pf_mus_tk_pz_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_theta() const{
  if(!c_pf_mus_tk_theta_ && b_pf_mus_tk_theta_){
    b_pf_mus_tk_theta_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tk_theta", &pf_mus_tk_theta_, &b_pf_mus_tk_theta_);
    b_pf_mus_tk_theta_->GetEntry(entry_);
    c_pf_mus_tk_theta_ = true;
  }
  return pf_mus_tk_theta_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_vx() const{
  if(!c_pf_mus_tk_vx_ && b_pf_mus_tk_vx_){
    b_pf_mus_tk_vx_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tk_vx", &pf_mus_tk_vx_, &b_pf_mus_tk_vx_);
    b_pf_mus_tk_vx_->GetEntry(entry_);
    c_pf_mus_tk_vx_ = true;
  }
  return pf_mus_tk_vx_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_vy() const{
  if(!c_pf_mus_tk_vy_ && b_pf_mus_tk_vy_){
    b_pf_mus_tk_vy_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tk_vy", &pf_mus_tk_vy_, &b_pf_mus_tk_vy_);
    b_pf_mus_tk_vy_->GetEntry(entry_);
    c_pf_mus_tk_vy_ = true;
  }
  return pf_mus_tk_vy_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_vz() const{
  if(!c_pf_mus_tk_vz_ && b_pf_mus_tk_vz_){
    b_pf_mus_tk_vz_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tk_vz", &pf_mus_tk_vz_, &b_pf_mus_tk_vz_);
    b_pf_mus_tk_vz_->GetEntry(entry_);
    c_pf_mus_tk_vz_ = true;
  }
  return pf_mus_tk_vz_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_ExpectedHitsInner() const{
  if(!c_pf_mus_tpfms_ExpectedHitsInner_ && b_pf_mus_tpfms_ExpectedHitsInner_){
    b_pf_mus_tpfms_ExpectedHitsInner_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tpfms_ExpectedHitsInner", &pf_mus_tpfms_ExpectedHitsInner_, &b_pf_mus_tpfms_ExpectedHitsInner_);
    b_pf_mus_tpfms_ExpectedHitsInner_->GetEntry(entry_);
    c_pf_mus_tpfms_ExpectedHitsInner_ = true;
  }
  return pf_mus_tpfms_ExpectedHitsInner_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_ExpectedHitsOuter() const{
  if(!c_pf_mus_tpfms_ExpectedHitsOuter_ && b_pf_mus_tpfms_ExpectedHitsOuter_){
    b_pf_mus_tpfms_ExpectedHitsOuter_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tpfms_ExpectedHitsOuter", &pf_mus_tpfms_ExpectedHitsOuter_, &b_pf_mus_tpfms_ExpectedHitsOuter_);
    b_pf_mus_tpfms_ExpectedHitsOuter_->GetEntry(entry_);
    c_pf_mus_tpfms_ExpectedHitsOuter_ = true;
  }
  return pf_mus_tpfms_ExpectedHitsOuter_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_LayersWithMeasurement() const{
  if(!c_pf_mus_tpfms_LayersWithMeasurement_ && b_pf_mus_tpfms_LayersWithMeasurement_){
    b_pf_mus_tpfms_LayersWithMeasurement_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tpfms_LayersWithMeasurement", &pf_mus_tpfms_LayersWithMeasurement_, &b_pf_mus_tpfms_LayersWithMeasurement_);
    b_pf_mus_tpfms_LayersWithMeasurement_->GetEntry(entry_);
    c_pf_mus_tpfms_LayersWithMeasurement_ = true;
  }
  return pf_mus_tpfms_LayersWithMeasurement_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_LayersWithoutMeasurement() const{
  if(!c_pf_mus_tpfms_LayersWithoutMeasurement_ && b_pf_mus_tpfms_LayersWithoutMeasurement_){
    b_pf_mus_tpfms_LayersWithoutMeasurement_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tpfms_LayersWithoutMeasurement", &pf_mus_tpfms_LayersWithoutMeasurement_, &b_pf_mus_tpfms_LayersWithoutMeasurement_);
    b_pf_mus_tpfms_LayersWithoutMeasurement_->GetEntry(entry_);
    c_pf_mus_tpfms_LayersWithoutMeasurement_ = true;
  }
  return pf_mus_tpfms_LayersWithoutMeasurement_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_PixelLayersWithMeasurement() const{
  if(!c_pf_mus_tpfms_PixelLayersWithMeasurement_ && b_pf_mus_tpfms_PixelLayersWithMeasurement_){
    b_pf_mus_tpfms_PixelLayersWithMeasurement_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tpfms_PixelLayersWithMeasurement", &pf_mus_tpfms_PixelLayersWithMeasurement_, &b_pf_mus_tpfms_PixelLayersWithMeasurement_);
    b_pf_mus_tpfms_PixelLayersWithMeasurement_->GetEntry(entry_);
    c_pf_mus_tpfms_PixelLayersWithMeasurement_ = true;
  }
  return pf_mus_tpfms_PixelLayersWithMeasurement_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_ValidStripLayersWithMonoAndStereoHit() const{
  if(!c_pf_mus_tpfms_ValidStripLayersWithMonoAndStereoHit_ && b_pf_mus_tpfms_ValidStripLayersWithMonoAndStereoHit_){
    b_pf_mus_tpfms_ValidStripLayersWithMonoAndStereoHit_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tpfms_ValidStripLayersWithMonoAndStereoHit", &pf_mus_tpfms_ValidStripLayersWithMonoAndStereoHit_, &b_pf_mus_tpfms_ValidStripLayersWithMonoAndStereoHit_);
    b_pf_mus_tpfms_ValidStripLayersWithMonoAndStereoHit_->GetEntry(entry_);
    c_pf_mus_tpfms_ValidStripLayersWithMonoAndStereoHit_ = true;
  }
  return pf_mus_tpfms_ValidStripLayersWithMonoAndStereoHit_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_chg() const{
  if(!c_pf_mus_tpfms_chg_ && b_pf_mus_tpfms_chg_){
    b_pf_mus_tpfms_chg_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tpfms_chg", &pf_mus_tpfms_chg_, &b_pf_mus_tpfms_chg_);
    b_pf_mus_tpfms_chg_->GetEntry(entry_);
    c_pf_mus_tpfms_chg_ = true;
  }
  return pf_mus_tpfms_chg_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_chi2() const{
  if(!c_pf_mus_tpfms_chi2_ && b_pf_mus_tpfms_chi2_){
    b_pf_mus_tpfms_chi2_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tpfms_chi2", &pf_mus_tpfms_chi2_, &b_pf_mus_tpfms_chi2_);
    b_pf_mus_tpfms_chi2_->GetEntry(entry_);
    c_pf_mus_tpfms_chi2_ = true;
  }
  return pf_mus_tpfms_chi2_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_d0dum() const{
  if(!c_pf_mus_tpfms_d0dum_ && b_pf_mus_tpfms_d0dum_){
    b_pf_mus_tpfms_d0dum_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tpfms_d0dum", &pf_mus_tpfms_d0dum_, &b_pf_mus_tpfms_d0dum_);
    b_pf_mus_tpfms_d0dum_->GetEntry(entry_);
    c_pf_mus_tpfms_d0dum_ = true;
  }
  return pf_mus_tpfms_d0dum_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_d0dumErr() const{
  if(!c_pf_mus_tpfms_d0dumErr_ && b_pf_mus_tpfms_d0dumErr_){
    b_pf_mus_tpfms_d0dumErr_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tpfms_d0dumErr", &pf_mus_tpfms_d0dumErr_, &b_pf_mus_tpfms_d0dumErr_);
    b_pf_mus_tpfms_d0dumErr_->GetEntry(entry_);
    c_pf_mus_tpfms_d0dumErr_ = true;
  }
  return pf_mus_tpfms_d0dumErr_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_dz() const{
  if(!c_pf_mus_tpfms_dz_ && b_pf_mus_tpfms_dz_){
    b_pf_mus_tpfms_dz_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tpfms_dz", &pf_mus_tpfms_dz_, &b_pf_mus_tpfms_dz_);
    b_pf_mus_tpfms_dz_->GetEntry(entry_);
    c_pf_mus_tpfms_dz_ = true;
  }
  return pf_mus_tpfms_dz_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_dzErr() const{
  if(!c_pf_mus_tpfms_dzErr_ && b_pf_mus_tpfms_dzErr_){
    b_pf_mus_tpfms_dzErr_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tpfms_dzErr", &pf_mus_tpfms_dzErr_, &b_pf_mus_tpfms_dzErr_);
    b_pf_mus_tpfms_dzErr_->GetEntry(entry_);
    c_pf_mus_tpfms_dzErr_ = true;
  }
  return pf_mus_tpfms_dzErr_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_eta() const{
  if(!c_pf_mus_tpfms_eta_ && b_pf_mus_tpfms_eta_){
    b_pf_mus_tpfms_eta_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tpfms_eta", &pf_mus_tpfms_eta_, &b_pf_mus_tpfms_eta_);
    b_pf_mus_tpfms_eta_->GetEntry(entry_);
    c_pf_mus_tpfms_eta_ = true;
  }
  return pf_mus_tpfms_eta_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_etaErr() const{
  if(!c_pf_mus_tpfms_etaErr_ && b_pf_mus_tpfms_etaErr_){
    b_pf_mus_tpfms_etaErr_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tpfms_etaErr", &pf_mus_tpfms_etaErr_, &b_pf_mus_tpfms_etaErr_);
    b_pf_mus_tpfms_etaErr_->GetEntry(entry_);
    c_pf_mus_tpfms_etaErr_ = true;
  }
  return pf_mus_tpfms_etaErr_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_id() const{
  if(!c_pf_mus_tpfms_id_ && b_pf_mus_tpfms_id_){
    b_pf_mus_tpfms_id_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tpfms_id", &pf_mus_tpfms_id_, &b_pf_mus_tpfms_id_);
    b_pf_mus_tpfms_id_->GetEntry(entry_);
    c_pf_mus_tpfms_id_ = true;
  }
  return pf_mus_tpfms_id_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_ndof() const{
  if(!c_pf_mus_tpfms_ndof_ && b_pf_mus_tpfms_ndof_){
    b_pf_mus_tpfms_ndof_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tpfms_ndof", &pf_mus_tpfms_ndof_, &b_pf_mus_tpfms_ndof_);
    b_pf_mus_tpfms_ndof_->GetEntry(entry_);
    c_pf_mus_tpfms_ndof_ = true;
  }
  return pf_mus_tpfms_ndof_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_numlosthits() const{
  if(!c_pf_mus_tpfms_numlosthits_ && b_pf_mus_tpfms_numlosthits_){
    b_pf_mus_tpfms_numlosthits_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tpfms_numlosthits", &pf_mus_tpfms_numlosthits_, &b_pf_mus_tpfms_numlosthits_);
    b_pf_mus_tpfms_numlosthits_->GetEntry(entry_);
    c_pf_mus_tpfms_numlosthits_ = true;
  }
  return pf_mus_tpfms_numlosthits_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_numvalPixelhits() const{
  if(!c_pf_mus_tpfms_numvalPixelhits_ && b_pf_mus_tpfms_numvalPixelhits_){
    b_pf_mus_tpfms_numvalPixelhits_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tpfms_numvalPixelhits", &pf_mus_tpfms_numvalPixelhits_, &b_pf_mus_tpfms_numvalPixelhits_);
    b_pf_mus_tpfms_numvalPixelhits_->GetEntry(entry_);
    c_pf_mus_tpfms_numvalPixelhits_ = true;
  }
  return pf_mus_tpfms_numvalPixelhits_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_numvalhits() const{
  if(!c_pf_mus_tpfms_numvalhits_ && b_pf_mus_tpfms_numvalhits_){
    b_pf_mus_tpfms_numvalhits_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tpfms_numvalhits", &pf_mus_tpfms_numvalhits_, &b_pf_mus_tpfms_numvalhits_);
    b_pf_mus_tpfms_numvalhits_->GetEntry(entry_);
    c_pf_mus_tpfms_numvalhits_ = true;
  }
  return pf_mus_tpfms_numvalhits_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_phi() const{
  if(!c_pf_mus_tpfms_phi_ && b_pf_mus_tpfms_phi_){
    b_pf_mus_tpfms_phi_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tpfms_phi", &pf_mus_tpfms_phi_, &b_pf_mus_tpfms_phi_);
    b_pf_mus_tpfms_phi_->GetEntry(entry_);
    c_pf_mus_tpfms_phi_ = true;
  }
  return pf_mus_tpfms_phi_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_phiErr() const{
  if(!c_pf_mus_tpfms_phiErr_ && b_pf_mus_tpfms_phiErr_){
    b_pf_mus_tpfms_phiErr_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tpfms_phiErr", &pf_mus_tpfms_phiErr_, &b_pf_mus_tpfms_phiErr_);
    b_pf_mus_tpfms_phiErr_->GetEntry(entry_);
    c_pf_mus_tpfms_phiErr_ = true;
  }
  return pf_mus_tpfms_phiErr_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_pt() const{
  if(!c_pf_mus_tpfms_pt_ && b_pf_mus_tpfms_pt_){
    b_pf_mus_tpfms_pt_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tpfms_pt", &pf_mus_tpfms_pt_, &b_pf_mus_tpfms_pt_);
    b_pf_mus_tpfms_pt_->GetEntry(entry_);
    c_pf_mus_tpfms_pt_ = true;
  }
  return pf_mus_tpfms_pt_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_ptErr() const{
  if(!c_pf_mus_tpfms_ptErr_ && b_pf_mus_tpfms_ptErr_){
    b_pf_mus_tpfms_ptErr_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tpfms_ptErr", &pf_mus_tpfms_ptErr_, &b_pf_mus_tpfms_ptErr_);
    b_pf_mus_tpfms_ptErr_->GetEntry(entry_);
    c_pf_mus_tpfms_ptErr_ = true;
  }
  return pf_mus_tpfms_ptErr_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_px() const{
  if(!c_pf_mus_tpfms_px_ && b_pf_mus_tpfms_px_){
    b_pf_mus_tpfms_px_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tpfms_px", &pf_mus_tpfms_px_, &b_pf_mus_tpfms_px_);
    b_pf_mus_tpfms_px_->GetEntry(entry_);
    c_pf_mus_tpfms_px_ = true;
  }
  return pf_mus_tpfms_px_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_py() const{
  if(!c_pf_mus_tpfms_py_ && b_pf_mus_tpfms_py_){
    b_pf_mus_tpfms_py_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tpfms_py", &pf_mus_tpfms_py_, &b_pf_mus_tpfms_py_);
    b_pf_mus_tpfms_py_->GetEntry(entry_);
    c_pf_mus_tpfms_py_ = true;
  }
  return pf_mus_tpfms_py_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_pz() const{
  if(!c_pf_mus_tpfms_pz_ && b_pf_mus_tpfms_pz_){
    b_pf_mus_tpfms_pz_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tpfms_pz", &pf_mus_tpfms_pz_, &b_pf_mus_tpfms_pz_);
    b_pf_mus_tpfms_pz_->GetEntry(entry_);
    c_pf_mus_tpfms_pz_ = true;
  }
  return pf_mus_tpfms_pz_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_theta() const{
  if(!c_pf_mus_tpfms_theta_ && b_pf_mus_tpfms_theta_){
    b_pf_mus_tpfms_theta_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tpfms_theta", &pf_mus_tpfms_theta_, &b_pf_mus_tpfms_theta_);
    b_pf_mus_tpfms_theta_->GetEntry(entry_);
    c_pf_mus_tpfms_theta_ = true;
  }
  return pf_mus_tpfms_theta_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_vx() const{
  if(!c_pf_mus_tpfms_vx_ && b_pf_mus_tpfms_vx_){
    b_pf_mus_tpfms_vx_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tpfms_vx", &pf_mus_tpfms_vx_, &b_pf_mus_tpfms_vx_);
    b_pf_mus_tpfms_vx_->GetEntry(entry_);
    c_pf_mus_tpfms_vx_ = true;
  }
  return pf_mus_tpfms_vx_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_vy() const{
  if(!c_pf_mus_tpfms_vy_ && b_pf_mus_tpfms_vy_){
    b_pf_mus_tpfms_vy_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tpfms_vy", &pf_mus_tpfms_vy_, &b_pf_mus_tpfms_vy_);
    b_pf_mus_tpfms_vy_->GetEntry(entry_);
    c_pf_mus_tpfms_vy_ = true;
  }
  return pf_mus_tpfms_vy_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_vz() const{
  if(!c_pf_mus_tpfms_vz_ && b_pf_mus_tpfms_vz_){
    b_pf_mus_tpfms_vz_->SetStatus(true);
    chainB_.SetBranchAddress("pf_mus_tpfms_vz", &pf_mus_tpfms_vz_, &b_pf_mus_tpfms_vz_);
    b_pf_mus_tpfms_vz_->GetEntry(entry_);
    c_pf_mus_tpfms_vz_ = true;
  }
  return pf_mus_tpfms_vz_;
}

std::vector<float>* const & cfa_8::pf_photons_chIso() const{
  if(!c_pf_photons_chIso_ && b_pf_photons_chIso_){
    b_pf_photons_chIso_->SetStatus(true);
    chainB_.SetBranchAddress("pf_photons_chIso", &pf_photons_chIso_, &b_pf_photons_chIso_);
    b_pf_photons_chIso_->GetEntry(entry_);
    c_pf_photons_chIso_ = true;
  }
  return pf_photons_chIso_;
}

std::vector<float>* const & cfa_8::pf_photons_e1x5() const{
  if(!c_pf_photons_e1x5_ && b_pf_photons_e1x5_){
    b_pf_photons_e1x5_->SetStatus(true);
    chainB_.SetBranchAddress("pf_photons_e1x5", &pf_photons_e1x5_, &b_pf_photons_e1x5_);
    b_pf_photons_e1x5_->GetEntry(entry_);
    c_pf_photons_e1x5_ = true;
  }
  return pf_photons_e1x5_;
}

std::vector<float>* const & cfa_8::pf_photons_e2x5() const{
  if(!c_pf_photons_e2x5_ && b_pf_photons_e2x5_){
    b_pf_photons_e2x5_->SetStatus(true);
    chainB_.SetBranchAddress("pf_photons_e2x5", &pf_photons_e2x5_, &b_pf_photons_e2x5_);
    b_pf_photons_e2x5_->GetEntry(entry_);
    c_pf_photons_e2x5_ = true;
  }
  return pf_photons_e2x5_;
}

std::vector<float>* const & cfa_8::pf_photons_e3x3() const{
  if(!c_pf_photons_e3x3_ && b_pf_photons_e3x3_){
    b_pf_photons_e3x3_->SetStatus(true);
    chainB_.SetBranchAddress("pf_photons_e3x3", &pf_photons_e3x3_, &b_pf_photons_e3x3_);
    b_pf_photons_e3x3_->GetEntry(entry_);
    c_pf_photons_e3x3_ = true;
  }
  return pf_photons_e3x3_;
}

std::vector<float>* const & cfa_8::pf_photons_e5x5() const{
  if(!c_pf_photons_e5x5_ && b_pf_photons_e5x5_){
    b_pf_photons_e5x5_->SetStatus(true);
    chainB_.SetBranchAddress("pf_photons_e5x5", &pf_photons_e5x5_, &b_pf_photons_e5x5_);
    b_pf_photons_e5x5_->GetEntry(entry_);
    c_pf_photons_e5x5_ = true;
  }
  return pf_photons_e5x5_;
}

std::vector<float>* const & cfa_8::pf_photons_energy() const{
  if(!c_pf_photons_energy_ && b_pf_photons_energy_){
    b_pf_photons_energy_->SetStatus(true);
    chainB_.SetBranchAddress("pf_photons_energy", &pf_photons_energy_, &b_pf_photons_energy_);
    b_pf_photons_energy_->GetEntry(entry_);
    c_pf_photons_energy_ = true;
  }
  return pf_photons_energy_;
}

std::vector<float>* const & cfa_8::pf_photons_et() const{
  if(!c_pf_photons_et_ && b_pf_photons_et_){
    b_pf_photons_et_->SetStatus(true);
    chainB_.SetBranchAddress("pf_photons_et", &pf_photons_et_, &b_pf_photons_et_);
    b_pf_photons_et_->GetEntry(entry_);
    c_pf_photons_et_ = true;
  }
  return pf_photons_et_;
}

std::vector<float>* const & cfa_8::pf_photons_eta() const{
  if(!c_pf_photons_eta_ && b_pf_photons_eta_){
    b_pf_photons_eta_->SetStatus(true);
    chainB_.SetBranchAddress("pf_photons_eta", &pf_photons_eta_, &b_pf_photons_eta_);
    b_pf_photons_eta_->GetEntry(entry_);
    c_pf_photons_eta_ = true;
  }
  return pf_photons_eta_;
}

std::vector<float>* const & cfa_8::pf_photons_hadOverEM() const{
  if(!c_pf_photons_hadOverEM_ && b_pf_photons_hadOverEM_){
    b_pf_photons_hadOverEM_->SetStatus(true);
    chainB_.SetBranchAddress("pf_photons_hadOverEM", &pf_photons_hadOverEM_, &b_pf_photons_hadOverEM_);
    b_pf_photons_hadOverEM_->GetEntry(entry_);
    c_pf_photons_hadOverEM_ = true;
  }
  return pf_photons_hadOverEM_;
}

std::vector<float>* const & cfa_8::pf_photons_hadTowOverEM() const{
  if(!c_pf_photons_hadTowOverEM_ && b_pf_photons_hadTowOverEM_){
    b_pf_photons_hadTowOverEM_->SetStatus(true);
    chainB_.SetBranchAddress("pf_photons_hadTowOverEM", &pf_photons_hadTowOverEM_, &b_pf_photons_hadTowOverEM_);
    b_pf_photons_hadTowOverEM_->GetEntry(entry_);
    c_pf_photons_hadTowOverEM_ = true;
  }
  return pf_photons_hadTowOverEM_;
}

std::vector<float>* const & cfa_8::pf_photons_hasPixelSeed() const{
  if(!c_pf_photons_hasPixelSeed_ && b_pf_photons_hasPixelSeed_){
    b_pf_photons_hasPixelSeed_->SetStatus(true);
    chainB_.SetBranchAddress("pf_photons_hasPixelSeed", &pf_photons_hasPixelSeed_, &b_pf_photons_hasPixelSeed_);
    b_pf_photons_hasPixelSeed_->GetEntry(entry_);
    c_pf_photons_hasPixelSeed_ = true;
  }
  return pf_photons_hasPixelSeed_;
}

std::vector<float>* const & cfa_8::pf_photons_isAlsoElectron() const{
  if(!c_pf_photons_isAlsoElectron_ && b_pf_photons_isAlsoElectron_){
    b_pf_photons_isAlsoElectron_->SetStatus(true);
    chainB_.SetBranchAddress("pf_photons_isAlsoElectron", &pf_photons_isAlsoElectron_, &b_pf_photons_isAlsoElectron_);
    b_pf_photons_isAlsoElectron_->GetEntry(entry_);
    c_pf_photons_isAlsoElectron_ = true;
  }
  return pf_photons_isAlsoElectron_;
}

std::vector<float>* const & cfa_8::pf_photons_isConverted() const{
  if(!c_pf_photons_isConverted_ && b_pf_photons_isConverted_){
    b_pf_photons_isConverted_->SetStatus(true);
    chainB_.SetBranchAddress("pf_photons_isConverted", &pf_photons_isConverted_, &b_pf_photons_isConverted_);
    b_pf_photons_isConverted_->GetEntry(entry_);
    c_pf_photons_isConverted_ = true;
  }
  return pf_photons_isConverted_;
}

std::vector<float>* const & cfa_8::pf_photons_isEBEEGap() const{
  if(!c_pf_photons_isEBEEGap_ && b_pf_photons_isEBEEGap_){
    b_pf_photons_isEBEEGap_->SetStatus(true);
    chainB_.SetBranchAddress("pf_photons_isEBEEGap", &pf_photons_isEBEEGap_, &b_pf_photons_isEBEEGap_);
    b_pf_photons_isEBEEGap_->GetEntry(entry_);
    c_pf_photons_isEBEEGap_ = true;
  }
  return pf_photons_isEBEEGap_;
}

std::vector<float>* const & cfa_8::pf_photons_isEBGap() const{
  if(!c_pf_photons_isEBGap_ && b_pf_photons_isEBGap_){
    b_pf_photons_isEBGap_->SetStatus(true);
    chainB_.SetBranchAddress("pf_photons_isEBGap", &pf_photons_isEBGap_, &b_pf_photons_isEBGap_);
    b_pf_photons_isEBGap_->GetEntry(entry_);
    c_pf_photons_isEBGap_ = true;
  }
  return pf_photons_isEBGap_;
}

std::vector<float>* const & cfa_8::pf_photons_isEBPho() const{
  if(!c_pf_photons_isEBPho_ && b_pf_photons_isEBPho_){
    b_pf_photons_isEBPho_->SetStatus(true);
    chainB_.SetBranchAddress("pf_photons_isEBPho", &pf_photons_isEBPho_, &b_pf_photons_isEBPho_);
    b_pf_photons_isEBPho_->GetEntry(entry_);
    c_pf_photons_isEBPho_ = true;
  }
  return pf_photons_isEBPho_;
}

std::vector<float>* const & cfa_8::pf_photons_isEEGap() const{
  if(!c_pf_photons_isEEGap_ && b_pf_photons_isEEGap_){
    b_pf_photons_isEEGap_->SetStatus(true);
    chainB_.SetBranchAddress("pf_photons_isEEGap", &pf_photons_isEEGap_, &b_pf_photons_isEEGap_);
    b_pf_photons_isEEGap_->GetEntry(entry_);
    c_pf_photons_isEEGap_ = true;
  }
  return pf_photons_isEEGap_;
}

std::vector<float>* const & cfa_8::pf_photons_isEEPho() const{
  if(!c_pf_photons_isEEPho_ && b_pf_photons_isEEPho_){
    b_pf_photons_isEEPho_->SetStatus(true);
    chainB_.SetBranchAddress("pf_photons_isEEPho", &pf_photons_isEEPho_, &b_pf_photons_isEEPho_);
    b_pf_photons_isEEPho_->GetEntry(entry_);
    c_pf_photons_isEEPho_ = true;
  }
  return pf_photons_isEEPho_;
}

std::vector<float>* const & cfa_8::pf_photons_maxEnergyXtal() const{
  if(!c_pf_photons_maxEnergyXtal_ && b_pf_photons_maxEnergyXtal_){
    b_pf_photons_maxEnergyXtal_->SetStatus(true);
    chainB_.SetBranchAddress("pf_photons_maxEnergyXtal", &pf_photons_maxEnergyXtal_, &b_pf_photons_maxEnergyXtal_);
    b_pf_photons_maxEnergyXtal_->GetEntry(entry_);
    c_pf_photons_maxEnergyXtal_ = true;
  }
  return pf_photons_maxEnergyXtal_;
}

std::vector<float>* const & cfa_8::pf_photons_nhIso() const{
  if(!c_pf_photons_nhIso_ && b_pf_photons_nhIso_){
    b_pf_photons_nhIso_->SetStatus(true);
    chainB_.SetBranchAddress("pf_photons_nhIso", &pf_photons_nhIso_, &b_pf_photons_nhIso_);
    b_pf_photons_nhIso_->GetEntry(entry_);
    c_pf_photons_nhIso_ = true;
  }
  return pf_photons_nhIso_;
}

std::vector<float>* const & cfa_8::pf_photons_phIso() const{
  if(!c_pf_photons_phIso_ && b_pf_photons_phIso_){
    b_pf_photons_phIso_->SetStatus(true);
    chainB_.SetBranchAddress("pf_photons_phIso", &pf_photons_phIso_, &b_pf_photons_phIso_);
    b_pf_photons_phIso_->GetEntry(entry_);
    c_pf_photons_phIso_ = true;
  }
  return pf_photons_phIso_;
}

std::vector<float>* const & cfa_8::pf_photons_phi() const{
  if(!c_pf_photons_phi_ && b_pf_photons_phi_){
    b_pf_photons_phi_->SetStatus(true);
    chainB_.SetBranchAddress("pf_photons_phi", &pf_photons_phi_, &b_pf_photons_phi_);
    b_pf_photons_phi_->GetEntry(entry_);
    c_pf_photons_phi_ = true;
  }
  return pf_photons_phi_;
}

std::vector<float>* const & cfa_8::pf_photons_pt() const{
  if(!c_pf_photons_pt_ && b_pf_photons_pt_){
    b_pf_photons_pt_->SetStatus(true);
    chainB_.SetBranchAddress("pf_photons_pt", &pf_photons_pt_, &b_pf_photons_pt_);
    b_pf_photons_pt_->GetEntry(entry_);
    c_pf_photons_pt_ = true;
  }
  return pf_photons_pt_;
}

std::vector<float>* const & cfa_8::pf_photons_px() const{
  if(!c_pf_photons_px_ && b_pf_photons_px_){
    b_pf_photons_px_->SetStatus(true);
    chainB_.SetBranchAddress("pf_photons_px", &pf_photons_px_, &b_pf_photons_px_);
    b_pf_photons_px_->GetEntry(entry_);
    c_pf_photons_px_ = true;
  }
  return pf_photons_px_;
}

std::vector<float>* const & cfa_8::pf_photons_py() const{
  if(!c_pf_photons_py_ && b_pf_photons_py_){
    b_pf_photons_py_->SetStatus(true);
    chainB_.SetBranchAddress("pf_photons_py", &pf_photons_py_, &b_pf_photons_py_);
    b_pf_photons_py_->GetEntry(entry_);
    c_pf_photons_py_ = true;
  }
  return pf_photons_py_;
}

std::vector<float>* const & cfa_8::pf_photons_pz() const{
  if(!c_pf_photons_pz_ && b_pf_photons_pz_){
    b_pf_photons_pz_->SetStatus(true);
    chainB_.SetBranchAddress("pf_photons_pz", &pf_photons_pz_, &b_pf_photons_pz_);
    b_pf_photons_pz_->GetEntry(entry_);
    c_pf_photons_pz_ = true;
  }
  return pf_photons_pz_;
}

std::vector<float>* const & cfa_8::pf_photons_r9() const{
  if(!c_pf_photons_r9_ && b_pf_photons_r9_){
    b_pf_photons_r9_->SetStatus(true);
    chainB_.SetBranchAddress("pf_photons_r9", &pf_photons_r9_, &b_pf_photons_r9_);
    b_pf_photons_r9_->GetEntry(entry_);
    c_pf_photons_r9_ = true;
  }
  return pf_photons_r9_;
}

std::vector<float>* const & cfa_8::pf_photons_scEnergy() const{
  if(!c_pf_photons_scEnergy_ && b_pf_photons_scEnergy_){
    b_pf_photons_scEnergy_->SetStatus(true);
    chainB_.SetBranchAddress("pf_photons_scEnergy", &pf_photons_scEnergy_, &b_pf_photons_scEnergy_);
    b_pf_photons_scEnergy_->GetEntry(entry_);
    c_pf_photons_scEnergy_ = true;
  }
  return pf_photons_scEnergy_;
}

std::vector<float>* const & cfa_8::pf_photons_scEta() const{
  if(!c_pf_photons_scEta_ && b_pf_photons_scEta_){
    b_pf_photons_scEta_->SetStatus(true);
    chainB_.SetBranchAddress("pf_photons_scEta", &pf_photons_scEta_, &b_pf_photons_scEta_);
    b_pf_photons_scEta_->GetEntry(entry_);
    c_pf_photons_scEta_ = true;
  }
  return pf_photons_scEta_;
}

std::vector<float>* const & cfa_8::pf_photons_scEtaWidth() const{
  if(!c_pf_photons_scEtaWidth_ && b_pf_photons_scEtaWidth_){
    b_pf_photons_scEtaWidth_->SetStatus(true);
    chainB_.SetBranchAddress("pf_photons_scEtaWidth", &pf_photons_scEtaWidth_, &b_pf_photons_scEtaWidth_);
    b_pf_photons_scEtaWidth_->GetEntry(entry_);
    c_pf_photons_scEtaWidth_ = true;
  }
  return pf_photons_scEtaWidth_;
}

std::vector<float>* const & cfa_8::pf_photons_scPhi() const{
  if(!c_pf_photons_scPhi_ && b_pf_photons_scPhi_){
    b_pf_photons_scPhi_->SetStatus(true);
    chainB_.SetBranchAddress("pf_photons_scPhi", &pf_photons_scPhi_, &b_pf_photons_scPhi_);
    b_pf_photons_scPhi_->GetEntry(entry_);
    c_pf_photons_scPhi_ = true;
  }
  return pf_photons_scPhi_;
}

std::vector<float>* const & cfa_8::pf_photons_scPhiWidth() const{
  if(!c_pf_photons_scPhiWidth_ && b_pf_photons_scPhiWidth_){
    b_pf_photons_scPhiWidth_->SetStatus(true);
    chainB_.SetBranchAddress("pf_photons_scPhiWidth", &pf_photons_scPhiWidth_, &b_pf_photons_scPhiWidth_);
    b_pf_photons_scPhiWidth_->GetEntry(entry_);
    c_pf_photons_scPhiWidth_ = true;
  }
  return pf_photons_scPhiWidth_;
}

std::vector<float>* const & cfa_8::pf_photons_scRawEnergy() const{
  if(!c_pf_photons_scRawEnergy_ && b_pf_photons_scRawEnergy_){
    b_pf_photons_scRawEnergy_->SetStatus(true);
    chainB_.SetBranchAddress("pf_photons_scRawEnergy", &pf_photons_scRawEnergy_, &b_pf_photons_scRawEnergy_);
    b_pf_photons_scRawEnergy_->GetEntry(entry_);
    c_pf_photons_scRawEnergy_ = true;
  }
  return pf_photons_scRawEnergy_;
}

std::vector<float>* const & cfa_8::pf_photons_sigmaEtaEta() const{
  if(!c_pf_photons_sigmaEtaEta_ && b_pf_photons_sigmaEtaEta_){
    b_pf_photons_sigmaEtaEta_->SetStatus(true);
    chainB_.SetBranchAddress("pf_photons_sigmaEtaEta", &pf_photons_sigmaEtaEta_, &b_pf_photons_sigmaEtaEta_);
    b_pf_photons_sigmaEtaEta_->GetEntry(entry_);
    c_pf_photons_sigmaEtaEta_ = true;
  }
  return pf_photons_sigmaEtaEta_;
}

std::vector<float>* const & cfa_8::pf_photons_sigmaIetaIeta() const{
  if(!c_pf_photons_sigmaIetaIeta_ && b_pf_photons_sigmaIetaIeta_){
    b_pf_photons_sigmaIetaIeta_->SetStatus(true);
    chainB_.SetBranchAddress("pf_photons_sigmaIetaIeta", &pf_photons_sigmaIetaIeta_, &b_pf_photons_sigmaIetaIeta_);
    b_pf_photons_sigmaIetaIeta_->GetEntry(entry_);
    c_pf_photons_sigmaIetaIeta_ = true;
  }
  return pf_photons_sigmaIetaIeta_;
}

std::vector<float>* const & cfa_8::pf_photons_status() const{
  if(!c_pf_photons_status_ && b_pf_photons_status_){
    b_pf_photons_status_->SetStatus(true);
    chainB_.SetBranchAddress("pf_photons_status", &pf_photons_status_, &b_pf_photons_status_);
    b_pf_photons_status_->GetEntry(entry_);
    c_pf_photons_status_ = true;
  }
  return pf_photons_status_;
}

std::vector<float>* const & cfa_8::pf_photons_theta() const{
  if(!c_pf_photons_theta_ && b_pf_photons_theta_){
    b_pf_photons_theta_->SetStatus(true);
    chainB_.SetBranchAddress("pf_photons_theta", &pf_photons_theta_, &b_pf_photons_theta_);
    b_pf_photons_theta_->GetEntry(entry_);
    c_pf_photons_theta_ = true;
  }
  return pf_photons_theta_;
}

std::vector<float>* const & cfa_8::pfcand_particleId() const{
  if(!c_pfcand_particleId_ && b_pfcand_particleId_){
    b_pfcand_particleId_->SetStatus(true);
    chainB_.SetBranchAddress("pfcand_particleId", &pfcand_particleId_, &b_pfcand_particleId_);
    b_pfcand_particleId_->GetEntry(entry_);
    c_pfcand_particleId_ = true;
  }
  return pfcand_particleId_;
}

std::vector<float>* const & cfa_8::pfmets_et() const{
  if(!c_pfmets_et_ && b_pfmets_et_){
    b_pfmets_et_->SetStatus(true);
    chainB_.SetBranchAddress("pfmets_et", &pfmets_et_, &b_pfmets_et_);
    b_pfmets_et_->GetEntry(entry_);
    c_pfmets_et_ = true;
  }
  return pfmets_et_;
}

std::vector<float>* const & cfa_8::pfmets_ex() const{
  if(!c_pfmets_ex_ && b_pfmets_ex_){
    b_pfmets_ex_->SetStatus(true);
    chainB_.SetBranchAddress("pfmets_ex", &pfmets_ex_, &b_pfmets_ex_);
    b_pfmets_ex_->GetEntry(entry_);
    c_pfmets_ex_ = true;
  }
  return pfmets_ex_;
}

std::vector<float>* const & cfa_8::pfmets_ey() const{
  if(!c_pfmets_ey_ && b_pfmets_ey_){
    b_pfmets_ey_->SetStatus(true);
    chainB_.SetBranchAddress("pfmets_ey", &pfmets_ey_, &b_pfmets_ey_);
    b_pfmets_ey_->GetEntry(entry_);
    c_pfmets_ey_ = true;
  }
  return pfmets_ey_;
}

Float_t const & cfa_8::pfmets_fullSignif() const{
  if(!c_pfmets_fullSignif_ && b_pfmets_fullSignif_){
    b_pfmets_fullSignif_->SetStatus(true);
    chainA_.SetBranchAddress("pfmets_fullSignif", &pfmets_fullSignif_, &b_pfmets_fullSignif_);
    b_pfmets_fullSignif_->GetEntry(entry_);
    c_pfmets_fullSignif_ = true;
  }
  return pfmets_fullSignif_;
}

Float_t const & cfa_8::pfmets_fullSignifCov00() const{
  if(!c_pfmets_fullSignifCov00_ && b_pfmets_fullSignifCov00_){
    b_pfmets_fullSignifCov00_->SetStatus(true);
    chainA_.SetBranchAddress("pfmets_fullSignifCov00", &pfmets_fullSignifCov00_, &b_pfmets_fullSignifCov00_);
    b_pfmets_fullSignifCov00_->GetEntry(entry_);
    c_pfmets_fullSignifCov00_ = true;
  }
  return pfmets_fullSignifCov00_;
}

Float_t const & cfa_8::pfmets_fullSignifCov00_2012() const{
  if(!c_pfmets_fullSignifCov00_2012_ && b_pfmets_fullSignifCov00_2012_){
    b_pfmets_fullSignifCov00_2012_->SetStatus(true);
    chainA_.SetBranchAddress("pfmets_fullSignifCov00_2012", &pfmets_fullSignifCov00_2012_, &b_pfmets_fullSignifCov00_2012_);
    b_pfmets_fullSignifCov00_2012_->GetEntry(entry_);
    c_pfmets_fullSignifCov00_2012_ = true;
  }
  return pfmets_fullSignifCov00_2012_;
}

Float_t const & cfa_8::pfmets_fullSignifCov00_2012_dataRes() const{
  if(!c_pfmets_fullSignifCov00_2012_dataRes_ && b_pfmets_fullSignifCov00_2012_dataRes_){
    b_pfmets_fullSignifCov00_2012_dataRes_->SetStatus(true);
    chainA_.SetBranchAddress("pfmets_fullSignifCov00_2012_dataRes", &pfmets_fullSignifCov00_2012_dataRes_, &b_pfmets_fullSignifCov00_2012_dataRes_);
    b_pfmets_fullSignifCov00_2012_dataRes_->GetEntry(entry_);
    c_pfmets_fullSignifCov00_2012_dataRes_ = true;
  }
  return pfmets_fullSignifCov00_2012_dataRes_;
}

Float_t const & cfa_8::pfmets_fullSignifCov10() const{
  if(!c_pfmets_fullSignifCov10_ && b_pfmets_fullSignifCov10_){
    b_pfmets_fullSignifCov10_->SetStatus(true);
    chainA_.SetBranchAddress("pfmets_fullSignifCov10", &pfmets_fullSignifCov10_, &b_pfmets_fullSignifCov10_);
    b_pfmets_fullSignifCov10_->GetEntry(entry_);
    c_pfmets_fullSignifCov10_ = true;
  }
  return pfmets_fullSignifCov10_;
}

Float_t const & cfa_8::pfmets_fullSignifCov10_2012() const{
  if(!c_pfmets_fullSignifCov10_2012_ && b_pfmets_fullSignifCov10_2012_){
    b_pfmets_fullSignifCov10_2012_->SetStatus(true);
    chainA_.SetBranchAddress("pfmets_fullSignifCov10_2012", &pfmets_fullSignifCov10_2012_, &b_pfmets_fullSignifCov10_2012_);
    b_pfmets_fullSignifCov10_2012_->GetEntry(entry_);
    c_pfmets_fullSignifCov10_2012_ = true;
  }
  return pfmets_fullSignifCov10_2012_;
}

Float_t const & cfa_8::pfmets_fullSignifCov10_2012_dataRes() const{
  if(!c_pfmets_fullSignifCov10_2012_dataRes_ && b_pfmets_fullSignifCov10_2012_dataRes_){
    b_pfmets_fullSignifCov10_2012_dataRes_->SetStatus(true);
    chainA_.SetBranchAddress("pfmets_fullSignifCov10_2012_dataRes", &pfmets_fullSignifCov10_2012_dataRes_, &b_pfmets_fullSignifCov10_2012_dataRes_);
    b_pfmets_fullSignifCov10_2012_dataRes_->GetEntry(entry_);
    c_pfmets_fullSignifCov10_2012_dataRes_ = true;
  }
  return pfmets_fullSignifCov10_2012_dataRes_;
}

Float_t const & cfa_8::pfmets_fullSignifCov11() const{
  if(!c_pfmets_fullSignifCov11_ && b_pfmets_fullSignifCov11_){
    b_pfmets_fullSignifCov11_->SetStatus(true);
    chainA_.SetBranchAddress("pfmets_fullSignifCov11", &pfmets_fullSignifCov11_, &b_pfmets_fullSignifCov11_);
    b_pfmets_fullSignifCov11_->GetEntry(entry_);
    c_pfmets_fullSignifCov11_ = true;
  }
  return pfmets_fullSignifCov11_;
}

Float_t const & cfa_8::pfmets_fullSignifCov11_2012() const{
  if(!c_pfmets_fullSignifCov11_2012_ && b_pfmets_fullSignifCov11_2012_){
    b_pfmets_fullSignifCov11_2012_->SetStatus(true);
    chainA_.SetBranchAddress("pfmets_fullSignifCov11_2012", &pfmets_fullSignifCov11_2012_, &b_pfmets_fullSignifCov11_2012_);
    b_pfmets_fullSignifCov11_2012_->GetEntry(entry_);
    c_pfmets_fullSignifCov11_2012_ = true;
  }
  return pfmets_fullSignifCov11_2012_;
}

Float_t const & cfa_8::pfmets_fullSignifCov11_2012_dataRes() const{
  if(!c_pfmets_fullSignifCov11_2012_dataRes_ && b_pfmets_fullSignifCov11_2012_dataRes_){
    b_pfmets_fullSignifCov11_2012_dataRes_->SetStatus(true);
    chainA_.SetBranchAddress("pfmets_fullSignifCov11_2012_dataRes", &pfmets_fullSignifCov11_2012_dataRes_, &b_pfmets_fullSignifCov11_2012_dataRes_);
    b_pfmets_fullSignifCov11_2012_dataRes_->GetEntry(entry_);
    c_pfmets_fullSignifCov11_2012_dataRes_ = true;
  }
  return pfmets_fullSignifCov11_2012_dataRes_;
}

Float_t const & cfa_8::pfmets_fullSignif_2012() const{
  if(!c_pfmets_fullSignif_2012_ && b_pfmets_fullSignif_2012_){
    b_pfmets_fullSignif_2012_->SetStatus(true);
    chainA_.SetBranchAddress("pfmets_fullSignif_2012", &pfmets_fullSignif_2012_, &b_pfmets_fullSignif_2012_);
    b_pfmets_fullSignif_2012_->GetEntry(entry_);
    c_pfmets_fullSignif_2012_ = true;
  }
  return pfmets_fullSignif_2012_;
}

Float_t const & cfa_8::pfmets_fullSignif_2012_dataRes() const{
  if(!c_pfmets_fullSignif_2012_dataRes_ && b_pfmets_fullSignif_2012_dataRes_){
    b_pfmets_fullSignif_2012_dataRes_->SetStatus(true);
    chainA_.SetBranchAddress("pfmets_fullSignif_2012_dataRes", &pfmets_fullSignif_2012_dataRes_, &b_pfmets_fullSignif_2012_dataRes_);
    b_pfmets_fullSignif_2012_dataRes_->GetEntry(entry_);
    c_pfmets_fullSignif_2012_dataRes_ = true;
  }
  return pfmets_fullSignif_2012_dataRes_;
}

std::vector<float>* const & cfa_8::pfmets_gen_et() const{
  if(!c_pfmets_gen_et_ && b_pfmets_gen_et_){
    b_pfmets_gen_et_->SetStatus(true);
    chainB_.SetBranchAddress("pfmets_gen_et", &pfmets_gen_et_, &b_pfmets_gen_et_);
    b_pfmets_gen_et_->GetEntry(entry_);
    c_pfmets_gen_et_ = true;
  }
  return pfmets_gen_et_;
}

std::vector<float>* const & cfa_8::pfmets_gen_phi() const{
  if(!c_pfmets_gen_phi_ && b_pfmets_gen_phi_){
    b_pfmets_gen_phi_->SetStatus(true);
    chainB_.SetBranchAddress("pfmets_gen_phi", &pfmets_gen_phi_, &b_pfmets_gen_phi_);
    b_pfmets_gen_phi_->GetEntry(entry_);
    c_pfmets_gen_phi_ = true;
  }
  return pfmets_gen_phi_;
}

std::vector<float>* const & cfa_8::pfmets_phi() const{
  if(!c_pfmets_phi_ && b_pfmets_phi_){
    b_pfmets_phi_->SetStatus(true);
    chainB_.SetBranchAddress("pfmets_phi", &pfmets_phi_, &b_pfmets_phi_);
    b_pfmets_phi_->GetEntry(entry_);
    c_pfmets_phi_ = true;
  }
  return pfmets_phi_;
}

std::vector<float>* const & cfa_8::pfmets_sign() const{
  if(!c_pfmets_sign_ && b_pfmets_sign_){
    b_pfmets_sign_->SetStatus(true);
    chainB_.SetBranchAddress("pfmets_sign", &pfmets_sign_, &b_pfmets_sign_);
    b_pfmets_sign_->GetEntry(entry_);
    c_pfmets_sign_ = true;
  }
  return pfmets_sign_;
}

std::vector<float>* const & cfa_8::pfmets_sumEt() const{
  if(!c_pfmets_sumEt_ && b_pfmets_sumEt_){
    b_pfmets_sumEt_->SetStatus(true);
    chainB_.SetBranchAddress("pfmets_sumEt", &pfmets_sumEt_, &b_pfmets_sumEt_);
    b_pfmets_sumEt_->GetEntry(entry_);
    c_pfmets_sumEt_ = true;
  }
  return pfmets_sumEt_;
}

std::vector<float>* const & cfa_8::pfmets_unCPhi() const{
  if(!c_pfmets_unCPhi_ && b_pfmets_unCPhi_){
    b_pfmets_unCPhi_->SetStatus(true);
    chainB_.SetBranchAddress("pfmets_unCPhi", &pfmets_unCPhi_, &b_pfmets_unCPhi_);
    b_pfmets_unCPhi_->GetEntry(entry_);
    c_pfmets_unCPhi_ = true;
  }
  return pfmets_unCPhi_;
}

std::vector<float>* const & cfa_8::pfmets_unCPt() const{
  if(!c_pfmets_unCPt_ && b_pfmets_unCPt_){
    b_pfmets_unCPt_->SetStatus(true);
    chainB_.SetBranchAddress("pfmets_unCPt", &pfmets_unCPt_, &b_pfmets_unCPt_);
    b_pfmets_unCPt_->GetEntry(entry_);
    c_pfmets_unCPt_ = true;
  }
  return pfmets_unCPt_;
}

std::vector<float>* const & cfa_8::photon_chIsoValues() const{
  if(!c_photon_chIsoValues_ && b_photon_chIsoValues_){
    b_photon_chIsoValues_->SetStatus(true);
    chainA_.SetBranchAddress("photon_chIsoValues", &photon_chIsoValues_, &b_photon_chIsoValues_);
    b_photon_chIsoValues_->GetEntry(entry_);
    c_photon_chIsoValues_ = true;
  }
  return photon_chIsoValues_;
}

std::vector<float>* const & cfa_8::photon_nhIsoValues() const{
  if(!c_photon_nhIsoValues_ && b_photon_nhIsoValues_){
    b_photon_nhIsoValues_->SetStatus(true);
    chainA_.SetBranchAddress("photon_nhIsoValues", &photon_nhIsoValues_, &b_photon_nhIsoValues_);
    b_photon_nhIsoValues_->GetEntry(entry_);
    c_photon_nhIsoValues_ = true;
  }
  return photon_nhIsoValues_;
}

std::vector<bool>* const & cfa_8::photon_passElectronVeto() const{
  if(!c_photon_passElectronVeto_ && b_photon_passElectronVeto_){
    b_photon_passElectronVeto_->SetStatus(true);
    chainA_.SetBranchAddress("photon_passElectronVeto", &photon_passElectronVeto_, &b_photon_passElectronVeto_);
    b_photon_passElectronVeto_->GetEntry(entry_);
    c_photon_passElectronVeto_ = true;
  }
  return photon_passElectronVeto_;
}

std::vector<float>* const & cfa_8::photon_phIsoValues() const{
  if(!c_photon_phIsoValues_ && b_photon_phIsoValues_){
    b_photon_phIsoValues_->SetStatus(true);
    chainA_.SetBranchAddress("photon_phIsoValues", &photon_phIsoValues_, &b_photon_phIsoValues_);
    b_photon_phIsoValues_->GetEntry(entry_);
    c_photon_phIsoValues_ = true;
  }
  return photon_phIsoValues_;
}

std::vector<std::vector<float> >* const & cfa_8::puJet_rejectionBeta() const{
  if(!c_puJet_rejectionBeta_ && b_puJet_rejectionBeta_){
    b_puJet_rejectionBeta_->SetStatus(true);
    chainA_.SetBranchAddress("puJet_rejectionBeta", &puJet_rejectionBeta_, &b_puJet_rejectionBeta_);
    b_puJet_rejectionBeta_->GetEntry(entry_);
    c_puJet_rejectionBeta_ = true;
  }
  return puJet_rejectionBeta_;
}

std::vector<std::vector<float> >* const & cfa_8::puJet_rejectionMVA() const{
  if(!c_puJet_rejectionMVA_ && b_puJet_rejectionMVA_){
    b_puJet_rejectionMVA_->SetStatus(true);
    chainA_.SetBranchAddress("puJet_rejectionMVA", &puJet_rejectionMVA_, &b_puJet_rejectionMVA_);
    b_puJet_rejectionMVA_->GetEntry(entry_);
    c_puJet_rejectionMVA_ = true;
  }
  return puJet_rejectionMVA_;
}

Float_t const & cfa_8::rho_kt6PFJetsForIsolation2011() const{
  if(!c_rho_kt6PFJetsForIsolation2011_ && b_rho_kt6PFJetsForIsolation2011_){
    b_rho_kt6PFJetsForIsolation2011_->SetStatus(true);
    chainA_.SetBranchAddress("rho_kt6PFJetsForIsolation2011", &rho_kt6PFJetsForIsolation2011_, &b_rho_kt6PFJetsForIsolation2011_);
    b_rho_kt6PFJetsForIsolation2011_->GetEntry(entry_);
    c_rho_kt6PFJetsForIsolation2011_ = true;
  }
  return rho_kt6PFJetsForIsolation2011_;
}

Float_t const & cfa_8::rho_kt6PFJetsForIsolation2012() const{
  if(!c_rho_kt6PFJetsForIsolation2012_ && b_rho_kt6PFJetsForIsolation2012_){
    b_rho_kt6PFJetsForIsolation2012_->SetStatus(true);
    chainA_.SetBranchAddress("rho_kt6PFJetsForIsolation2012", &rho_kt6PFJetsForIsolation2012_, &b_rho_kt6PFJetsForIsolation2012_);
    b_rho_kt6PFJetsForIsolation2012_->GetEntry(entry_);
    c_rho_kt6PFJetsForIsolation2012_ = true;
  }
  return rho_kt6PFJetsForIsolation2012_;
}

Int_t const & cfa_8::scrapingVeto_decision() const{
  if(!c_scrapingVeto_decision_ && b_scrapingVeto_decision_){
    b_scrapingVeto_decision_->SetStatus(true);
    chainA_.SetBranchAddress("scrapingVeto_decision", &scrapingVeto_decision_, &b_scrapingVeto_decision_);
    b_scrapingVeto_decision_->GetEntry(entry_);
    c_scrapingVeto_decision_ = true;
  }
  return scrapingVeto_decision_;
}

Float_t const & cfa_8::softjetUp_dMEx() const{
  if(!c_softjetUp_dMEx_ && b_softjetUp_dMEx_){
    b_softjetUp_dMEx_->SetStatus(true);
    chainA_.SetBranchAddress("softjetUp_dMEx", &softjetUp_dMEx_, &b_softjetUp_dMEx_);
    b_softjetUp_dMEx_->GetEntry(entry_);
    c_softjetUp_dMEx_ = true;
  }
  return softjetUp_dMEx_;
}

Float_t const & cfa_8::softjetUp_dMEy() const{
  if(!c_softjetUp_dMEy_ && b_softjetUp_dMEy_){
    b_softjetUp_dMEy_->SetStatus(true);
    chainA_.SetBranchAddress("softjetUp_dMEy", &softjetUp_dMEy_, &b_softjetUp_dMEy_);
    b_softjetUp_dMEy_->GetEntry(entry_);
    c_softjetUp_dMEy_ = true;
  }
  return softjetUp_dMEy_;
}

std::vector<float>* const & cfa_8::tcmets_et() const{
  if(!c_tcmets_et_ && b_tcmets_et_){
    b_tcmets_et_->SetStatus(true);
    chainB_.SetBranchAddress("tcmets_et", &tcmets_et_, &b_tcmets_et_);
    b_tcmets_et_->GetEntry(entry_);
    c_tcmets_et_ = true;
  }
  return tcmets_et_;
}

std::vector<float>* const & cfa_8::tcmets_ex() const{
  if(!c_tcmets_ex_ && b_tcmets_ex_){
    b_tcmets_ex_->SetStatus(true);
    chainB_.SetBranchAddress("tcmets_ex", &tcmets_ex_, &b_tcmets_ex_);
    b_tcmets_ex_->GetEntry(entry_);
    c_tcmets_ex_ = true;
  }
  return tcmets_ex_;
}

std::vector<float>* const & cfa_8::tcmets_ey() const{
  if(!c_tcmets_ey_ && b_tcmets_ey_){
    b_tcmets_ey_->SetStatus(true);
    chainB_.SetBranchAddress("tcmets_ey", &tcmets_ey_, &b_tcmets_ey_);
    b_tcmets_ey_->GetEntry(entry_);
    c_tcmets_ey_ = true;
  }
  return tcmets_ey_;
}

std::vector<float>* const & cfa_8::tcmets_phi() const{
  if(!c_tcmets_phi_ && b_tcmets_phi_){
    b_tcmets_phi_->SetStatus(true);
    chainB_.SetBranchAddress("tcmets_phi", &tcmets_phi_, &b_tcmets_phi_);
    b_tcmets_phi_->GetEntry(entry_);
    c_tcmets_phi_ = true;
  }
  return tcmets_phi_;
}

std::vector<float>* const & cfa_8::tcmets_sumEt() const{
  if(!c_tcmets_sumEt_ && b_tcmets_sumEt_){
    b_tcmets_sumEt_->SetStatus(true);
    chainB_.SetBranchAddress("tcmets_sumEt", &tcmets_sumEt_, &b_tcmets_sumEt_);
    b_tcmets_sumEt_->GetEntry(entry_);
    c_tcmets_sumEt_ = true;
  }
  return tcmets_sumEt_;
}

Int_t const & cfa_8::trackercoherentnoisefilter1_decision() const{
  if(!c_trackercoherentnoisefilter1_decision_ && b_trackercoherentnoisefilter1_decision_){
    b_trackercoherentnoisefilter1_decision_->SetStatus(true);
    chainA_.SetBranchAddress("trackercoherentnoisefilter1_decision", &trackercoherentnoisefilter1_decision_, &b_trackercoherentnoisefilter1_decision_);
    b_trackercoherentnoisefilter1_decision_->GetEntry(entry_);
    c_trackercoherentnoisefilter1_decision_ = true;
  }
  return trackercoherentnoisefilter1_decision_;
}

Int_t const & cfa_8::trackercoherentnoisefilter2_decision() const{
  if(!c_trackercoherentnoisefilter2_decision_ && b_trackercoherentnoisefilter2_decision_){
    b_trackercoherentnoisefilter2_decision_->SetStatus(true);
    chainA_.SetBranchAddress("trackercoherentnoisefilter2_decision", &trackercoherentnoisefilter2_decision_, &b_trackercoherentnoisefilter2_decision_);
    b_trackercoherentnoisefilter2_decision_->GetEntry(entry_);
    c_trackercoherentnoisefilter2_decision_ = true;
  }
  return trackercoherentnoisefilter2_decision_;
}

Int_t const & cfa_8::trackertoomanyclustersfilter_decision() const{
  if(!c_trackertoomanyclustersfilter_decision_ && b_trackertoomanyclustersfilter_decision_){
    b_trackertoomanyclustersfilter_decision_->SetStatus(true);
    chainA_.SetBranchAddress("trackertoomanyclustersfilter_decision", &trackertoomanyclustersfilter_decision_, &b_trackertoomanyclustersfilter_decision_);
    b_trackertoomanyclustersfilter_decision_->GetEntry(entry_);
    c_trackertoomanyclustersfilter_decision_ = true;
  }
  return trackertoomanyclustersfilter_decision_;
}

Int_t const & cfa_8::trackertoomanyseedsfilter_decision() const{
  if(!c_trackertoomanyseedsfilter_decision_ && b_trackertoomanyseedsfilter_decision_){
    b_trackertoomanyseedsfilter_decision_->SetStatus(true);
    chainA_.SetBranchAddress("trackertoomanyseedsfilter_decision", &trackertoomanyseedsfilter_decision_, &b_trackertoomanyseedsfilter_decision_);
    b_trackertoomanyseedsfilter_decision_->GetEntry(entry_);
    c_trackertoomanyseedsfilter_decision_ = true;
  }
  return trackertoomanyseedsfilter_decision_;
}

Int_t const & cfa_8::trackertoomanytripletsfilter_decision() const{
  if(!c_trackertoomanytripletsfilter_decision_ && b_trackertoomanytripletsfilter_decision_){
    b_trackertoomanytripletsfilter_decision_->SetStatus(true);
    chainA_.SetBranchAddress("trackertoomanytripletsfilter_decision", &trackertoomanytripletsfilter_decision_, &b_trackertoomanytripletsfilter_decision_);
    b_trackertoomanytripletsfilter_decision_->GetEntry(entry_);
    c_trackertoomanytripletsfilter_decision_ = true;
  }
  return trackertoomanytripletsfilter_decision_;
}

std::vector<float>* const & cfa_8::tracks_chg() const{
  if(!c_tracks_chg_ && b_tracks_chg_){
    b_tracks_chg_->SetStatus(true);
    chainB_.SetBranchAddress("tracks_chg", &tracks_chg_, &b_tracks_chg_);
    b_tracks_chg_->GetEntry(entry_);
    c_tracks_chg_ = true;
  }
  return tracks_chg_;
}

std::vector<float>* const & cfa_8::tracks_chi2() const{
  if(!c_tracks_chi2_ && b_tracks_chi2_){
    b_tracks_chi2_->SetStatus(true);
    chainB_.SetBranchAddress("tracks_chi2", &tracks_chi2_, &b_tracks_chi2_);
    b_tracks_chi2_->GetEntry(entry_);
    c_tracks_chi2_ = true;
  }
  return tracks_chi2_;
}

std::vector<float>* const & cfa_8::tracks_d0dum() const{
  if(!c_tracks_d0dum_ && b_tracks_d0dum_){
    b_tracks_d0dum_->SetStatus(true);
    chainB_.SetBranchAddress("tracks_d0dum", &tracks_d0dum_, &b_tracks_d0dum_);
    b_tracks_d0dum_->GetEntry(entry_);
    c_tracks_d0dum_ = true;
  }
  return tracks_d0dum_;
}

std::vector<float>* const & cfa_8::tracks_d0dumErr() const{
  if(!c_tracks_d0dumErr_ && b_tracks_d0dumErr_){
    b_tracks_d0dumErr_->SetStatus(true);
    chainB_.SetBranchAddress("tracks_d0dumErr", &tracks_d0dumErr_, &b_tracks_d0dumErr_);
    b_tracks_d0dumErr_->GetEntry(entry_);
    c_tracks_d0dumErr_ = true;
  }
  return tracks_d0dumErr_;
}

std::vector<float>* const & cfa_8::tracks_dz() const{
  if(!c_tracks_dz_ && b_tracks_dz_){
    b_tracks_dz_->SetStatus(true);
    chainB_.SetBranchAddress("tracks_dz", &tracks_dz_, &b_tracks_dz_);
    b_tracks_dz_->GetEntry(entry_);
    c_tracks_dz_ = true;
  }
  return tracks_dz_;
}

std::vector<float>* const & cfa_8::tracks_dzErr() const{
  if(!c_tracks_dzErr_ && b_tracks_dzErr_){
    b_tracks_dzErr_->SetStatus(true);
    chainB_.SetBranchAddress("tracks_dzErr", &tracks_dzErr_, &b_tracks_dzErr_);
    b_tracks_dzErr_->GetEntry(entry_);
    c_tracks_dzErr_ = true;
  }
  return tracks_dzErr_;
}

std::vector<float>* const & cfa_8::tracks_eta() const{
  if(!c_tracks_eta_ && b_tracks_eta_){
    b_tracks_eta_->SetStatus(true);
    chainB_.SetBranchAddress("tracks_eta", &tracks_eta_, &b_tracks_eta_);
    b_tracks_eta_->GetEntry(entry_);
    c_tracks_eta_ = true;
  }
  return tracks_eta_;
}

std::vector<float>* const & cfa_8::tracks_etaErr() const{
  if(!c_tracks_etaErr_ && b_tracks_etaErr_){
    b_tracks_etaErr_->SetStatus(true);
    chainB_.SetBranchAddress("tracks_etaErr", &tracks_etaErr_, &b_tracks_etaErr_);
    b_tracks_etaErr_->GetEntry(entry_);
    c_tracks_etaErr_ = true;
  }
  return tracks_etaErr_;
}

std::vector<float>* const & cfa_8::tracks_highPurity() const{
  if(!c_tracks_highPurity_ && b_tracks_highPurity_){
    b_tracks_highPurity_->SetStatus(true);
    chainB_.SetBranchAddress("tracks_highPurity", &tracks_highPurity_, &b_tracks_highPurity_);
    b_tracks_highPurity_->GetEntry(entry_);
    c_tracks_highPurity_ = true;
  }
  return tracks_highPurity_;
}

std::vector<float>* const & cfa_8::tracks_ndof() const{
  if(!c_tracks_ndof_ && b_tracks_ndof_){
    b_tracks_ndof_->SetStatus(true);
    chainB_.SetBranchAddress("tracks_ndof", &tracks_ndof_, &b_tracks_ndof_);
    b_tracks_ndof_->GetEntry(entry_);
    c_tracks_ndof_ = true;
  }
  return tracks_ndof_;
}

std::vector<float>* const & cfa_8::tracks_numlosthits() const{
  if(!c_tracks_numlosthits_ && b_tracks_numlosthits_){
    b_tracks_numlosthits_->SetStatus(true);
    chainB_.SetBranchAddress("tracks_numlosthits", &tracks_numlosthits_, &b_tracks_numlosthits_);
    b_tracks_numlosthits_->GetEntry(entry_);
    c_tracks_numlosthits_ = true;
  }
  return tracks_numlosthits_;
}

std::vector<float>* const & cfa_8::tracks_numvalhits() const{
  if(!c_tracks_numvalhits_ && b_tracks_numvalhits_){
    b_tracks_numvalhits_->SetStatus(true);
    chainB_.SetBranchAddress("tracks_numvalhits", &tracks_numvalhits_, &b_tracks_numvalhits_);
    b_tracks_numvalhits_->GetEntry(entry_);
    c_tracks_numvalhits_ = true;
  }
  return tracks_numvalhits_;
}

std::vector<float>* const & cfa_8::tracks_phi() const{
  if(!c_tracks_phi_ && b_tracks_phi_){
    b_tracks_phi_->SetStatus(true);
    chainB_.SetBranchAddress("tracks_phi", &tracks_phi_, &b_tracks_phi_);
    b_tracks_phi_->GetEntry(entry_);
    c_tracks_phi_ = true;
  }
  return tracks_phi_;
}

std::vector<float>* const & cfa_8::tracks_phiErr() const{
  if(!c_tracks_phiErr_ && b_tracks_phiErr_){
    b_tracks_phiErr_->SetStatus(true);
    chainB_.SetBranchAddress("tracks_phiErr", &tracks_phiErr_, &b_tracks_phiErr_);
    b_tracks_phiErr_->GetEntry(entry_);
    c_tracks_phiErr_ = true;
  }
  return tracks_phiErr_;
}

std::vector<float>* const & cfa_8::tracks_pt() const{
  if(!c_tracks_pt_ && b_tracks_pt_){
    b_tracks_pt_->SetStatus(true);
    chainB_.SetBranchAddress("tracks_pt", &tracks_pt_, &b_tracks_pt_);
    b_tracks_pt_->GetEntry(entry_);
    c_tracks_pt_ = true;
  }
  return tracks_pt_;
}

std::vector<float>* const & cfa_8::tracks_ptErr() const{
  if(!c_tracks_ptErr_ && b_tracks_ptErr_){
    b_tracks_ptErr_->SetStatus(true);
    chainB_.SetBranchAddress("tracks_ptErr", &tracks_ptErr_, &b_tracks_ptErr_);
    b_tracks_ptErr_->GetEntry(entry_);
    c_tracks_ptErr_ = true;
  }
  return tracks_ptErr_;
}

std::vector<float>* const & cfa_8::tracks_px() const{
  if(!c_tracks_px_ && b_tracks_px_){
    b_tracks_px_->SetStatus(true);
    chainB_.SetBranchAddress("tracks_px", &tracks_px_, &b_tracks_px_);
    b_tracks_px_->GetEntry(entry_);
    c_tracks_px_ = true;
  }
  return tracks_px_;
}

std::vector<float>* const & cfa_8::tracks_py() const{
  if(!c_tracks_py_ && b_tracks_py_){
    b_tracks_py_->SetStatus(true);
    chainB_.SetBranchAddress("tracks_py", &tracks_py_, &b_tracks_py_);
    b_tracks_py_->GetEntry(entry_);
    c_tracks_py_ = true;
  }
  return tracks_py_;
}

std::vector<float>* const & cfa_8::tracks_pz() const{
  if(!c_tracks_pz_ && b_tracks_pz_){
    b_tracks_pz_->SetStatus(true);
    chainB_.SetBranchAddress("tracks_pz", &tracks_pz_, &b_tracks_pz_);
    b_tracks_pz_->GetEntry(entry_);
    c_tracks_pz_ = true;
  }
  return tracks_pz_;
}

std::vector<float>* const & cfa_8::tracks_vx() const{
  if(!c_tracks_vx_ && b_tracks_vx_){
    b_tracks_vx_->SetStatus(true);
    chainB_.SetBranchAddress("tracks_vx", &tracks_vx_, &b_tracks_vx_);
    b_tracks_vx_->GetEntry(entry_);
    c_tracks_vx_ = true;
  }
  return tracks_vx_;
}

std::vector<float>* const & cfa_8::tracks_vy() const{
  if(!c_tracks_vy_ && b_tracks_vy_){
    b_tracks_vy_->SetStatus(true);
    chainB_.SetBranchAddress("tracks_vy", &tracks_vy_, &b_tracks_vy_);
    b_tracks_vy_->GetEntry(entry_);
    c_tracks_vy_ = true;
  }
  return tracks_vy_;
}

std::vector<float>* const & cfa_8::tracks_vz() const{
  if(!c_tracks_vz_ && b_tracks_vz_){
    b_tracks_vz_->SetStatus(true);
    chainB_.SetBranchAddress("tracks_vz", &tracks_vz_, &b_tracks_vz_);
    b_tracks_vz_->GetEntry(entry_);
    c_tracks_vz_ = true;
  }
  return tracks_vz_;
}

std::vector<bool>* const & cfa_8::trigger_decision() const{
  if(!c_trigger_decision_ && b_trigger_decision_){
    b_trigger_decision_->SetStatus(true);
    chainA_.SetBranchAddress("trigger_decision", &v_trigger_decision_, &b_trigger_decision_);
    b_trigger_decision_->GetEntry(entry_);
    trigger_decision_->resize(v_trigger_decision_->size());
    for(size_t i = 0; i < trigger_decision_->size(); ++i){
      trigger_decision_->at(i) = static_cast<bool>(v_trigger_decision_->at(i));
    }
    c_trigger_decision_ = true;
  }
  return trigger_decision_;
}

std::vector<std::string>* const & cfa_8::trigger_lastfiltername() const{
  if(!c_trigger_lastfiltername_ && b_trigger_lastfiltername_){
    b_trigger_lastfiltername_->SetStatus(true);
    chainA_.SetBranchAddress("trigger_lastfiltername", &trigger_lastfiltername_, &b_trigger_lastfiltername_);
    b_trigger_lastfiltername_->GetEntry(entry_);
    c_trigger_lastfiltername_ = true;
  }
  return trigger_lastfiltername_;
}

std::vector<std::vector<std::string> >* const & cfa_8::triggerobject_collectionname() const{
  if(!c_triggerobject_collectionname_ && b_triggerobject_collectionname_){
    b_triggerobject_collectionname_->SetStatus(true);
    chainA_.SetBranchAddress("triggerobject_collectionname", &triggerobject_collectionname_, &b_triggerobject_collectionname_);
    b_triggerobject_collectionname_->GetEntry(entry_);
    c_triggerobject_collectionname_ = true;
  }
  return triggerobject_collectionname_;
}

std::vector<std::vector<float> >* const & cfa_8::triggerobject_energy() const{
  if(!c_triggerobject_energy_ && b_triggerobject_energy_){
    b_triggerobject_energy_->SetStatus(true);
    chainA_.SetBranchAddress("triggerobject_energy", &triggerobject_energy_, &b_triggerobject_energy_);
    b_triggerobject_energy_->GetEntry(entry_);
    c_triggerobject_energy_ = true;
  }
  return triggerobject_energy_;
}

std::vector<std::vector<float> >* const & cfa_8::triggerobject_et() const{
  if(!c_triggerobject_et_ && b_triggerobject_et_){
    b_triggerobject_et_->SetStatus(true);
    chainA_.SetBranchAddress("triggerobject_et", &triggerobject_et_, &b_triggerobject_et_);
    b_triggerobject_et_->GetEntry(entry_);
    c_triggerobject_et_ = true;
  }
  return triggerobject_et_;
}

std::vector<std::vector<float> >* const & cfa_8::triggerobject_eta() const{
  if(!c_triggerobject_eta_ && b_triggerobject_eta_){
    b_triggerobject_eta_->SetStatus(true);
    chainA_.SetBranchAddress("triggerobject_eta", &triggerobject_eta_, &b_triggerobject_eta_);
    b_triggerobject_eta_->GetEntry(entry_);
    c_triggerobject_eta_ = true;
  }
  return triggerobject_eta_;
}

std::vector<std::vector<float> >* const & cfa_8::triggerobject_phi() const{
  if(!c_triggerobject_phi_ && b_triggerobject_phi_){
    b_triggerobject_phi_->SetStatus(true);
    chainA_.SetBranchAddress("triggerobject_phi", &triggerobject_phi_, &b_triggerobject_phi_);
    b_triggerobject_phi_->GetEntry(entry_);
    c_triggerobject_phi_ = true;
  }
  return triggerobject_phi_;
}

std::vector<std::vector<float> >* const & cfa_8::triggerobject_pt() const{
  if(!c_triggerobject_pt_ && b_triggerobject_pt_){
    b_triggerobject_pt_->SetStatus(true);
    chainA_.SetBranchAddress("triggerobject_pt", &triggerobject_pt_, &b_triggerobject_pt_);
    b_triggerobject_pt_->GetEntry(entry_);
    c_triggerobject_pt_ = true;
  }
  return triggerobject_pt_;
}

std::vector<std::vector<float> >* const & cfa_8::triggerobject_px() const{
  if(!c_triggerobject_px_ && b_triggerobject_px_){
    b_triggerobject_px_->SetStatus(true);
    chainA_.SetBranchAddress("triggerobject_px", &triggerobject_px_, &b_triggerobject_px_);
    b_triggerobject_px_->GetEntry(entry_);
    c_triggerobject_px_ = true;
  }
  return triggerobject_px_;
}

std::vector<std::vector<float> >* const & cfa_8::triggerobject_py() const{
  if(!c_triggerobject_py_ && b_triggerobject_py_){
    b_triggerobject_py_->SetStatus(true);
    chainA_.SetBranchAddress("triggerobject_py", &triggerobject_py_, &b_triggerobject_py_);
    b_triggerobject_py_->GetEntry(entry_);
    c_triggerobject_py_ = true;
  }
  return triggerobject_py_;
}

std::vector<std::vector<float> >* const & cfa_8::triggerobject_pz() const{
  if(!c_triggerobject_pz_ && b_triggerobject_pz_){
    b_triggerobject_pz_->SetStatus(true);
    chainA_.SetBranchAddress("triggerobject_pz", &triggerobject_pz_, &b_triggerobject_pz_);
    b_triggerobject_pz_->GetEntry(entry_);
    c_triggerobject_pz_ = true;
  }
  return triggerobject_pz_;
}

Int_t const & cfa_8::trk_nTOBTEC() const{
  if(!c_trk_nTOBTEC_ && b_trk_nTOBTEC_){
    b_trk_nTOBTEC_->SetStatus(true);
    chainA_.SetBranchAddress("trk_nTOBTEC", &trk_nTOBTEC_, &b_trk_nTOBTEC_);
    b_trk_nTOBTEC_->GetEntry(entry_);
    c_trk_nTOBTEC_ = true;
  }
  return trk_nTOBTEC_;
}

Float_t const & cfa_8::trk_ratioAllTOBTEC() const{
  if(!c_trk_ratioAllTOBTEC_ && b_trk_ratioAllTOBTEC_){
    b_trk_ratioAllTOBTEC_->SetStatus(true);
    chainA_.SetBranchAddress("trk_ratioAllTOBTEC", &trk_ratioAllTOBTEC_, &b_trk_ratioAllTOBTEC_);
    b_trk_ratioAllTOBTEC_->GetEntry(entry_);
    c_trk_ratioAllTOBTEC_ = true;
  }
  return trk_ratioAllTOBTEC_;
}

Float_t const & cfa_8::trk_ratioJetTOBTEC() const{
  if(!c_trk_ratioJetTOBTEC_ && b_trk_ratioJetTOBTEC_){
    b_trk_ratioJetTOBTEC_->SetStatus(true);
    chainA_.SetBranchAddress("trk_ratioJetTOBTEC", &trk_ratioJetTOBTEC_, &b_trk_ratioJetTOBTEC_);
    b_trk_ratioJetTOBTEC_->GetEntry(entry_);
    c_trk_ratioJetTOBTEC_ = true;
  }
  return trk_ratioJetTOBTEC_;
}

