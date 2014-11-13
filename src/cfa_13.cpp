#include "cfa_13.hpp"

#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>

#include "TChain.h"

cfa_13::cfa_13(const std::string &file):
  cfa_base(file),
  EcalDeadCellTriggerPrimitivefilter_decision_(0),
  b_EcalDeadCellTriggerPrimitivefilter_decision_(NULL),
  c_EcalDeadCellTriggerPrimitivefilter_decision_(false),
  HBHENoisefilter_decision_(0),
  b_HBHENoisefilter_decision_(NULL),
  c_HBHENoisefilter_decision_(false),
  METFiltersfilter_decision_(0),
  b_METFiltersfilter_decision_(NULL),
  c_METFiltersfilter_decision_(false),
  Njets_AK4_(0),
  b_Njets_AK4_(NULL),
  c_Njets_AK4_(false),
  Nmc_final_(0),
  b_Nmc_final_(NULL),
  c_Nmc_final_(false),
  Nmc_jets_(0),
  b_Nmc_jets_(NULL),
  c_Nmc_jets_(false),
  Nmets_(0),
  b_Nmets_(NULL),
  c_Nmets_(false),
  els_full5x5_sigmaIetaIeta_(0),
  b_els_full5x5_sigmaIetaIeta_(NULL),
  c_els_full5x5_sigmaIetaIeta_(false),
  els_isPF_(0),
  b_els_isPF_(NULL),
  c_els_isPF_(false),
  els_jet_ind_(0),
  b_els_jet_ind_(NULL),
  c_els_jet_ind_(false),
  els_pfIsolationR03_sumChargedHadronPt_(0),
  b_els_pfIsolationR03_sumChargedHadronPt_(NULL),
  c_els_pfIsolationR03_sumChargedHadronPt_(false),
  els_pfIsolationR03_sumNeutralHadronEt_(0),
  b_els_pfIsolationR03_sumNeutralHadronEt_(NULL),
  c_els_pfIsolationR03_sumNeutralHadronEt_(false),
  els_pfIsolationR03_sumPUPt_(0),
  b_els_pfIsolationR03_sumPUPt_(NULL),
  c_els_pfIsolationR03_sumPUPt_(false),
  els_pfIsolationR03_sumPhotonEt_(0),
  b_els_pfIsolationR03_sumPhotonEt_(NULL),
  c_els_pfIsolationR03_sumPhotonEt_(false),
  fastjets_AK4_R1p2_R0p5pT10_energy_(0),
  b_fastjets_AK4_R1p2_R0p5pT10_energy_(NULL),
  c_fastjets_AK4_R1p2_R0p5pT10_energy_(false),
  fastjets_AK4_R1p2_R0p5pT10_eta_(0),
  b_fastjets_AK4_R1p2_R0p5pT10_eta_(NULL),
  c_fastjets_AK4_R1p2_R0p5pT10_eta_(false),
  fastjets_AK4_R1p2_R0p5pT10_index_(0),
  b_fastjets_AK4_R1p2_R0p5pT10_index_(NULL),
  c_fastjets_AK4_R1p2_R0p5pT10_index_(false),
  fastjets_AK4_R1p2_R0p5pT10_nconstituents_(0),
  b_fastjets_AK4_R1p2_R0p5pT10_nconstituents_(NULL),
  c_fastjets_AK4_R1p2_R0p5pT10_nconstituents_(false),
  fastjets_AK4_R1p2_R0p5pT10_phi_(0),
  b_fastjets_AK4_R1p2_R0p5pT10_phi_(NULL),
  c_fastjets_AK4_R1p2_R0p5pT10_phi_(false),
  fastjets_AK4_R1p2_R0p5pT10_px_(0),
  b_fastjets_AK4_R1p2_R0p5pT10_px_(NULL),
  c_fastjets_AK4_R1p2_R0p5pT10_px_(false),
  fastjets_AK4_R1p2_R0p5pT10_py_(0),
  b_fastjets_AK4_R1p2_R0p5pT10_py_(NULL),
  c_fastjets_AK4_R1p2_R0p5pT10_py_(false),
  fastjets_AK4_R1p2_R0p5pT10_pz_(0),
  b_fastjets_AK4_R1p2_R0p5pT10_pz_(NULL),
  c_fastjets_AK4_R1p2_R0p5pT10_pz_(false),
  fastjets_AK4_R1p2_R0p5pT15_energy_(0),
  b_fastjets_AK4_R1p2_R0p5pT15_energy_(NULL),
  c_fastjets_AK4_R1p2_R0p5pT15_energy_(false),
  fastjets_AK4_R1p2_R0p5pT15_eta_(0),
  b_fastjets_AK4_R1p2_R0p5pT15_eta_(NULL),
  c_fastjets_AK4_R1p2_R0p5pT15_eta_(false),
  fastjets_AK4_R1p2_R0p5pT15_index_(0),
  b_fastjets_AK4_R1p2_R0p5pT15_index_(NULL),
  c_fastjets_AK4_R1p2_R0p5pT15_index_(false),
  fastjets_AK4_R1p2_R0p5pT15_nconstituents_(0),
  b_fastjets_AK4_R1p2_R0p5pT15_nconstituents_(NULL),
  c_fastjets_AK4_R1p2_R0p5pT15_nconstituents_(false),
  fastjets_AK4_R1p2_R0p5pT15_phi_(0),
  b_fastjets_AK4_R1p2_R0p5pT15_phi_(NULL),
  c_fastjets_AK4_R1p2_R0p5pT15_phi_(false),
  fastjets_AK4_R1p2_R0p5pT15_px_(0),
  b_fastjets_AK4_R1p2_R0p5pT15_px_(NULL),
  c_fastjets_AK4_R1p2_R0p5pT15_px_(false),
  fastjets_AK4_R1p2_R0p5pT15_py_(0),
  b_fastjets_AK4_R1p2_R0p5pT15_py_(NULL),
  c_fastjets_AK4_R1p2_R0p5pT15_py_(false),
  fastjets_AK4_R1p2_R0p5pT15_pz_(0),
  b_fastjets_AK4_R1p2_R0p5pT15_pz_(NULL),
  c_fastjets_AK4_R1p2_R0p5pT15_pz_(false),
  fastjets_AK4_R1p2_R0p5pT20_energy_(0),
  b_fastjets_AK4_R1p2_R0p5pT20_energy_(NULL),
  c_fastjets_AK4_R1p2_R0p5pT20_energy_(false),
  fastjets_AK4_R1p2_R0p5pT20_eta_(0),
  b_fastjets_AK4_R1p2_R0p5pT20_eta_(NULL),
  c_fastjets_AK4_R1p2_R0p5pT20_eta_(false),
  fastjets_AK4_R1p2_R0p5pT20_index_(0),
  b_fastjets_AK4_R1p2_R0p5pT20_index_(NULL),
  c_fastjets_AK4_R1p2_R0p5pT20_index_(false),
  fastjets_AK4_R1p2_R0p5pT20_nconstituents_(0),
  b_fastjets_AK4_R1p2_R0p5pT20_nconstituents_(NULL),
  c_fastjets_AK4_R1p2_R0p5pT20_nconstituents_(false),
  fastjets_AK4_R1p2_R0p5pT20_phi_(0),
  b_fastjets_AK4_R1p2_R0p5pT20_phi_(NULL),
  c_fastjets_AK4_R1p2_R0p5pT20_phi_(false),
  fastjets_AK4_R1p2_R0p5pT20_px_(0),
  b_fastjets_AK4_R1p2_R0p5pT20_px_(NULL),
  c_fastjets_AK4_R1p2_R0p5pT20_px_(false),
  fastjets_AK4_R1p2_R0p5pT20_py_(0),
  b_fastjets_AK4_R1p2_R0p5pT20_py_(NULL),
  c_fastjets_AK4_R1p2_R0p5pT20_py_(false),
  fastjets_AK4_R1p2_R0p5pT20_pz_(0),
  b_fastjets_AK4_R1p2_R0p5pT20_pz_(NULL),
  c_fastjets_AK4_R1p2_R0p5pT20_pz_(false),
  fastjets_AK4_R1p2_R0p5pT25_energy_(0),
  b_fastjets_AK4_R1p2_R0p5pT25_energy_(NULL),
  c_fastjets_AK4_R1p2_R0p5pT25_energy_(false),
  fastjets_AK4_R1p2_R0p5pT25_eta_(0),
  b_fastjets_AK4_R1p2_R0p5pT25_eta_(NULL),
  c_fastjets_AK4_R1p2_R0p5pT25_eta_(false),
  fastjets_AK4_R1p2_R0p5pT25_index_(0),
  b_fastjets_AK4_R1p2_R0p5pT25_index_(NULL),
  c_fastjets_AK4_R1p2_R0p5pT25_index_(false),
  fastjets_AK4_R1p2_R0p5pT25_nconstituents_(0),
  b_fastjets_AK4_R1p2_R0p5pT25_nconstituents_(NULL),
  c_fastjets_AK4_R1p2_R0p5pT25_nconstituents_(false),
  fastjets_AK4_R1p2_R0p5pT25_phi_(0),
  b_fastjets_AK4_R1p2_R0p5pT25_phi_(NULL),
  c_fastjets_AK4_R1p2_R0p5pT25_phi_(false),
  fastjets_AK4_R1p2_R0p5pT25_px_(0),
  b_fastjets_AK4_R1p2_R0p5pT25_px_(NULL),
  c_fastjets_AK4_R1p2_R0p5pT25_px_(false),
  fastjets_AK4_R1p2_R0p5pT25_py_(0),
  b_fastjets_AK4_R1p2_R0p5pT25_py_(NULL),
  c_fastjets_AK4_R1p2_R0p5pT25_py_(false),
  fastjets_AK4_R1p2_R0p5pT25_pz_(0),
  b_fastjets_AK4_R1p2_R0p5pT25_pz_(NULL),
  c_fastjets_AK4_R1p2_R0p5pT25_pz_(false),
  fastjets_AK4_R1p2_R0p5pT30_energy_(0),
  b_fastjets_AK4_R1p2_R0p5pT30_energy_(NULL),
  c_fastjets_AK4_R1p2_R0p5pT30_energy_(false),
  fastjets_AK4_R1p2_R0p5pT30_eta_(0),
  b_fastjets_AK4_R1p2_R0p5pT30_eta_(NULL),
  c_fastjets_AK4_R1p2_R0p5pT30_eta_(false),
  fastjets_AK4_R1p2_R0p5pT30_index_(0),
  b_fastjets_AK4_R1p2_R0p5pT30_index_(NULL),
  c_fastjets_AK4_R1p2_R0p5pT30_index_(false),
  fastjets_AK4_R1p2_R0p5pT30_nconstituents_(0),
  b_fastjets_AK4_R1p2_R0p5pT30_nconstituents_(NULL),
  c_fastjets_AK4_R1p2_R0p5pT30_nconstituents_(false),
  fastjets_AK4_R1p2_R0p5pT30_phi_(0),
  b_fastjets_AK4_R1p2_R0p5pT30_phi_(NULL),
  c_fastjets_AK4_R1p2_R0p5pT30_phi_(false),
  fastjets_AK4_R1p2_R0p5pT30_px_(0),
  b_fastjets_AK4_R1p2_R0p5pT30_px_(NULL),
  c_fastjets_AK4_R1p2_R0p5pT30_px_(false),
  fastjets_AK4_R1p2_R0p5pT30_py_(0),
  b_fastjets_AK4_R1p2_R0p5pT30_py_(NULL),
  c_fastjets_AK4_R1p2_R0p5pT30_py_(false),
  fastjets_AK4_R1p2_R0p5pT30_pz_(0),
  b_fastjets_AK4_R1p2_R0p5pT30_pz_(NULL),
  c_fastjets_AK4_R1p2_R0p5pT30_pz_(false),
  goodVerticesfilter_decision_(0),
  b_goodVerticesfilter_decision_(NULL),
  c_goodVerticesfilter_decision_(false),
  jets_AK4_area_(0),
  b_jets_AK4_area_(NULL),
  c_jets_AK4_area_(false),
  jets_AK4_btag_TC_highEff_(0),
  b_jets_AK4_btag_TC_highEff_(NULL),
  c_jets_AK4_btag_TC_highEff_(false),
  jets_AK4_btag_TC_highPur_(0),
  b_jets_AK4_btag_TC_highPur_(NULL),
  c_jets_AK4_btag_TC_highPur_(false),
  jets_AK4_btag_jetBProb_(0),
  b_jets_AK4_btag_jetBProb_(NULL),
  c_jets_AK4_btag_jetBProb_(false),
  jets_AK4_btag_jetProb_(0),
  b_jets_AK4_btag_jetProb_(NULL),
  c_jets_AK4_btag_jetProb_(false),
  jets_AK4_btag_secVertexCombined_(0),
  b_jets_AK4_btag_secVertexCombined_(NULL),
  c_jets_AK4_btag_secVertexCombined_(false),
  jets_AK4_btag_secVertexHighEff_(0),
  b_jets_AK4_btag_secVertexHighEff_(NULL),
  c_jets_AK4_btag_secVertexHighEff_(false),
  jets_AK4_btag_secVertexHighPur_(0),
  b_jets_AK4_btag_secVertexHighPur_(NULL),
  c_jets_AK4_btag_secVertexHighPur_(false),
  jets_AK4_btag_softEle_(0),
  b_jets_AK4_btag_softEle_(NULL),
  c_jets_AK4_btag_softEle_(false),
  jets_AK4_btag_softMuon_(0),
  b_jets_AK4_btag_softMuon_(NULL),
  c_jets_AK4_btag_softMuon_(false),
  jets_AK4_chgEmE_(0),
  b_jets_AK4_chgEmE_(NULL),
  c_jets_AK4_chgEmE_(false),
  jets_AK4_chgHadE_(0),
  b_jets_AK4_chgHadE_(NULL),
  c_jets_AK4_chgHadE_(false),
  jets_AK4_chgMuE_(0),
  b_jets_AK4_chgMuE_(NULL),
  c_jets_AK4_chgMuE_(false),
  jets_AK4_chg_Mult_(0),
  b_jets_AK4_chg_Mult_(NULL),
  c_jets_AK4_chg_Mult_(false),
  jets_AK4_corrFactorRaw_(0),
  b_jets_AK4_corrFactorRaw_(NULL),
  c_jets_AK4_corrFactorRaw_(false),
  jets_AK4_ehf_(0),
  b_jets_AK4_ehf_(NULL),
  c_jets_AK4_ehf_(false),
  jets_AK4_el_ind_(0),
  b_jets_AK4_el_ind_(NULL),
  c_jets_AK4_el_ind_(false),
  jets_AK4_emf_(0),
  b_jets_AK4_emf_(NULL),
  c_jets_AK4_emf_(false),
  jets_AK4_energy_(0),
  b_jets_AK4_energy_(NULL),
  c_jets_AK4_energy_(false),
  jets_AK4_et_(0),
  b_jets_AK4_et_(NULL),
  c_jets_AK4_et_(false),
  jets_AK4_eta_(0),
  b_jets_AK4_eta_(NULL),
  c_jets_AK4_eta_(false),
  jets_AK4_etaetaMoment_(0),
  b_jets_AK4_etaetaMoment_(NULL),
  c_jets_AK4_etaetaMoment_(false),
  jets_AK4_etaphiMoment_(0),
  b_jets_AK4_etaphiMoment_(NULL),
  c_jets_AK4_etaphiMoment_(false),
  jets_AK4_fHPD_(0),
  b_jets_AK4_fHPD_(NULL),
  c_jets_AK4_fHPD_(false),
  jets_AK4_fRBX_(0),
  b_jets_AK4_fRBX_(NULL),
  c_jets_AK4_fRBX_(false),
  jets_AK4_fSubDetector1_(0),
  b_jets_AK4_fSubDetector1_(NULL),
  c_jets_AK4_fSubDetector1_(false),
  jets_AK4_fSubDetector2_(0),
  b_jets_AK4_fSubDetector2_(NULL),
  c_jets_AK4_fSubDetector2_(false),
  jets_AK4_fSubDetector3_(0),
  b_jets_AK4_fSubDetector3_(NULL),
  c_jets_AK4_fSubDetector3_(false),
  jets_AK4_fSubDetector4_(0),
  b_jets_AK4_fSubDetector4_(NULL),
  c_jets_AK4_fSubDetector4_(false),
  jets_AK4_gen_Energy_(0),
  b_jets_AK4_gen_Energy_(NULL),
  c_jets_AK4_gen_Energy_(false),
  jets_AK4_gen_Id_(0),
  b_jets_AK4_gen_Id_(NULL),
  c_jets_AK4_gen_Id_(false),
  jets_AK4_gen_et_(0),
  b_jets_AK4_gen_et_(NULL),
  c_jets_AK4_gen_et_(false),
  jets_AK4_gen_eta_(0),
  b_jets_AK4_gen_eta_(NULL),
  c_jets_AK4_gen_eta_(false),
  jets_AK4_gen_mass_(0),
  b_jets_AK4_gen_mass_(NULL),
  c_jets_AK4_gen_mass_(false),
  jets_AK4_gen_motherID_(0),
  b_jets_AK4_gen_motherID_(NULL),
  c_jets_AK4_gen_motherID_(false),
  jets_AK4_gen_phi_(0),
  b_jets_AK4_gen_phi_(NULL),
  c_jets_AK4_gen_phi_(false),
  jets_AK4_gen_pt_(0),
  b_jets_AK4_gen_pt_(NULL),
  c_jets_AK4_gen_pt_(false),
  jets_AK4_gen_threeCharge_(0),
  b_jets_AK4_gen_threeCharge_(NULL),
  c_jets_AK4_gen_threeCharge_(false),
  jets_AK4_hitsInN90_(0),
  b_jets_AK4_hitsInN90_(NULL),
  c_jets_AK4_hitsInN90_(false),
  jets_AK4_jetCharge_(0),
  b_jets_AK4_jetCharge_(NULL),
  c_jets_AK4_jetCharge_(false),
  jets_AK4_mass_(0),
  b_jets_AK4_mass_(NULL),
  c_jets_AK4_mass_(false),
  jets_AK4_maxpt_id_(0),
  b_jets_AK4_maxpt_id_(NULL),
  c_jets_AK4_maxpt_id_(false),
  jets_AK4_mu_Mult_(0),
  b_jets_AK4_mu_Mult_(NULL),
  c_jets_AK4_mu_Mult_(false),
  jets_AK4_mu_ind_(0),
  b_jets_AK4_mu_ind_(NULL),
  c_jets_AK4_mu_ind_(false),
  jets_AK4_n60_(0),
  b_jets_AK4_n60_(NULL),
  c_jets_AK4_n60_(false),
  jets_AK4_n90_(0),
  b_jets_AK4_n90_(NULL),
  c_jets_AK4_n90_(false),
  jets_AK4_n90Hits_(0),
  b_jets_AK4_n90Hits_(NULL),
  c_jets_AK4_n90Hits_(false),
  jets_AK4_nECALTowers_(0),
  b_jets_AK4_nECALTowers_(NULL),
  c_jets_AK4_nECALTowers_(false),
  jets_AK4_nHCALTowers_(0),
  b_jets_AK4_nHCALTowers_(NULL),
  c_jets_AK4_nHCALTowers_(false),
  jets_AK4_neutralEmE_(0),
  b_jets_AK4_neutralEmE_(NULL),
  c_jets_AK4_neutralEmE_(false),
  jets_AK4_neutralHadE_(0),
  b_jets_AK4_neutralHadE_(NULL),
  c_jets_AK4_neutralHadE_(false),
  jets_AK4_neutral_Mult_(0),
  b_jets_AK4_neutral_Mult_(NULL),
  c_jets_AK4_neutral_Mult_(false),
  jets_AK4_partonFlavour_(0),
  b_jets_AK4_partonFlavour_(NULL),
  c_jets_AK4_partonFlavour_(false),
  jets_AK4_parton_Energy_(0),
  b_jets_AK4_parton_Energy_(NULL),
  c_jets_AK4_parton_Energy_(false),
  jets_AK4_parton_Id_(0),
  b_jets_AK4_parton_Id_(NULL),
  c_jets_AK4_parton_Id_(false),
  jets_AK4_parton_eta_(0),
  b_jets_AK4_parton_eta_(NULL),
  c_jets_AK4_parton_eta_(false),
  jets_AK4_parton_mass_(0),
  b_jets_AK4_parton_mass_(NULL),
  c_jets_AK4_parton_mass_(false),
  jets_AK4_parton_motherId_(0),
  b_jets_AK4_parton_motherId_(NULL),
  c_jets_AK4_parton_motherId_(false),
  jets_AK4_parton_phi_(0),
  b_jets_AK4_parton_phi_(NULL),
  c_jets_AK4_parton_phi_(false),
  jets_AK4_parton_pt_(0),
  b_jets_AK4_parton_pt_(NULL),
  c_jets_AK4_parton_pt_(false),
  jets_AK4_phi_(0),
  b_jets_AK4_phi_(NULL),
  c_jets_AK4_phi_(false),
  jets_AK4_phiphiMoment_(0),
  b_jets_AK4_phiphiMoment_(NULL),
  c_jets_AK4_phiphiMoment_(false),
  jets_AK4_photonEnergy_(0),
  b_jets_AK4_photonEnergy_(NULL),
  c_jets_AK4_photonEnergy_(false),
  jets_AK4_pt_(0),
  b_jets_AK4_pt_(NULL),
  c_jets_AK4_pt_(false),
  jets_AK4_px_(0),
  b_jets_AK4_px_(NULL),
  c_jets_AK4_px_(false),
  jets_AK4_py_(0),
  b_jets_AK4_py_(NULL),
  c_jets_AK4_py_(false),
  jets_AK4_pz_(0),
  b_jets_AK4_pz_(NULL),
  c_jets_AK4_pz_(false),
  jets_AK4_rawPt_(0),
  b_jets_AK4_rawPt_(NULL),
  c_jets_AK4_rawPt_(false),
  jets_AK4_status_(0),
  b_jets_AK4_status_(NULL),
  c_jets_AK4_status_(false),
  jets_AK4_theta_(0),
  b_jets_AK4_theta_(NULL),
  c_jets_AK4_theta_(false),
  mc_final_charge_(0),
  b_mc_final_charge_(NULL),
  c_mc_final_charge_(false),
  mc_final_energy_(0),
  b_mc_final_energy_(NULL),
  c_mc_final_energy_(false),
  mc_final_eta_(0),
  b_mc_final_eta_(NULL),
  c_mc_final_eta_(false),
  mc_final_ggrandmother_id_(0),
  b_mc_final_ggrandmother_id_(NULL),
  c_mc_final_ggrandmother_id_(false),
  mc_final_grandmother_id_(0),
  b_mc_final_grandmother_id_(NULL),
  c_mc_final_grandmother_id_(false),
  mc_final_id_(0),
  b_mc_final_id_(NULL),
  c_mc_final_id_(false),
  mc_final_mass_(0),
  b_mc_final_mass_(NULL),
  c_mc_final_mass_(false),
  mc_final_mother_id_(0),
  b_mc_final_mother_id_(NULL),
  c_mc_final_mother_id_(false),
  mc_final_mother_pt_(0),
  b_mc_final_mother_pt_(NULL),
  c_mc_final_mother_pt_(false),
  mc_final_numOfDaughters_(0),
  b_mc_final_numOfDaughters_(NULL),
  c_mc_final_numOfDaughters_(false),
  mc_final_numOfMothers_(0),
  b_mc_final_numOfMothers_(NULL),
  c_mc_final_numOfMothers_(false),
  mc_final_phi_(0),
  b_mc_final_phi_(NULL),
  c_mc_final_phi_(false),
  mc_final_pt_(0),
  b_mc_final_pt_(NULL),
  c_mc_final_pt_(false),
  mc_final_px_(0),
  b_mc_final_px_(NULL),
  c_mc_final_px_(false),
  mc_final_py_(0),
  b_mc_final_py_(NULL),
  c_mc_final_py_(false),
  mc_final_pz_(0),
  b_mc_final_pz_(NULL),
  c_mc_final_pz_(false),
  mc_final_status_(0),
  b_mc_final_status_(NULL),
  c_mc_final_status_(false),
  mc_final_theta_(0),
  b_mc_final_theta_(NULL),
  c_mc_final_theta_(false),
  mc_final_vertex_x_(0),
  b_mc_final_vertex_x_(NULL),
  c_mc_final_vertex_x_(false),
  mc_final_vertex_y_(0),
  b_mc_final_vertex_y_(NULL),
  c_mc_final_vertex_y_(false),
  mc_final_vertex_z_(0),
  b_mc_final_vertex_z_(NULL),
  c_mc_final_vertex_z_(false),
  mc_jets_auxiliaryEnergy_(0),
  b_mc_jets_auxiliaryEnergy_(NULL),
  c_mc_jets_auxiliaryEnergy_(false),
  mc_jets_emEnergy_(0),
  b_mc_jets_emEnergy_(NULL),
  c_mc_jets_emEnergy_(false),
  mc_jets_energy_(0),
  b_mc_jets_energy_(NULL),
  c_mc_jets_energy_(false),
  mc_jets_et_(0),
  b_mc_jets_et_(NULL),
  c_mc_jets_et_(false),
  mc_jets_eta_(0),
  b_mc_jets_eta_(NULL),
  c_mc_jets_eta_(false),
  mc_jets_etaetaMoment_(0),
  b_mc_jets_etaetaMoment_(NULL),
  c_mc_jets_etaetaMoment_(false),
  mc_jets_etaphiMoment_(0),
  b_mc_jets_etaphiMoment_(NULL),
  c_mc_jets_etaphiMoment_(false),
  mc_jets_hadEnergy_(0),
  b_mc_jets_hadEnergy_(NULL),
  c_mc_jets_hadEnergy_(false),
  mc_jets_invisibleEnergy_(0),
  b_mc_jets_invisibleEnergy_(NULL),
  c_mc_jets_invisibleEnergy_(false),
  mc_jets_mass_(0),
  b_mc_jets_mass_(NULL),
  c_mc_jets_mass_(false),
  mc_jets_phi_(0),
  b_mc_jets_phi_(NULL),
  c_mc_jets_phi_(false),
  mc_jets_phiphiMoment_(0),
  b_mc_jets_phiphiMoment_(NULL),
  c_mc_jets_phiphiMoment_(false),
  mc_jets_pt_(0),
  b_mc_jets_pt_(NULL),
  c_mc_jets_pt_(false),
  mc_jets_px_(0),
  b_mc_jets_px_(NULL),
  c_mc_jets_px_(false),
  mc_jets_py_(0),
  b_mc_jets_py_(NULL),
  c_mc_jets_py_(false),
  mc_jets_pz_(0),
  b_mc_jets_pz_(NULL),
  c_mc_jets_pz_(false),
  mc_jets_theta_(0),
  b_mc_jets_theta_(NULL),
  c_mc_jets_theta_(false),
  mets_et_(0),
  b_mets_et_(NULL),
  c_mets_et_(false),
  mets_ex_(0),
  b_mets_ex_(NULL),
  c_mets_ex_(false),
  mets_ey_(0),
  b_mets_ey_(NULL),
  c_mets_ey_(false),
  mets_gen_et_(0),
  b_mets_gen_et_(NULL),
  c_mets_gen_et_(false),
  mets_gen_phi_(0),
  b_mets_gen_phi_(NULL),
  c_mets_gen_phi_(false),
  mets_phi_(0),
  b_mets_phi_(NULL),
  c_mets_phi_(false),
  mets_sign_(0),
  b_mets_sign_(NULL),
  c_mets_sign_(false),
  mets_sumEt_(0),
  b_mets_sumEt_(NULL),
  c_mets_sumEt_(false),
  mets_unCPhi_(0),
  b_mets_unCPhi_(NULL),
  c_mets_unCPhi_(false),
  mets_unCPt_(0),
  b_mets_unCPt_(NULL),
  c_mets_unCPt_(false),
  mus_isPF_(0),
  b_mus_isPF_(NULL),
  c_mus_isPF_(false),
  mus_jet_ind_(0),
  b_mus_jet_ind_(NULL),
  c_mus_jet_ind_(false),
  taus_el_ind_(0),
  b_taus_el_ind_(NULL),
  c_taus_el_ind_(false),
  taus_mu_ind_(0),
  b_taus_mu_ind_(NULL),
  c_taus_mu_ind_(false),
  trigger_decision_(0),
  b_trigger_decision_(NULL),
  c_trigger_decision_(false),
  trkPOG_logErrorTooManyClustersfilter_decision_(0),
  b_trkPOG_logErrorTooManyClustersfilter_decision_(NULL),
  c_trkPOG_logErrorTooManyClustersfilter_decision_(false),
  trkPOG_manystripclus53Xfilter_decision_(0),
  b_trkPOG_manystripclus53Xfilter_decision_(NULL),
  c_trkPOG_manystripclus53Xfilter_decision_(false),
  trkPOG_toomanystripclus53Xfilter_decision_(0),
  b_trkPOG_toomanystripclus53Xfilter_decision_(NULL),
  c_trkPOG_toomanystripclus53Xfilter_decision_(false),
  trkPOGfilter_decision_(0),
  b_trkPOGfilter_decision_(NULL),
  c_trkPOGfilter_decision_(false){
  PrepareNewChains();
}

void cfa_13::GetEntry(const long entry){
  c_EcalDeadCellTriggerPrimitivefilter_decision_ = false;
  c_HBHENoisefilter_decision_ = false;
  c_METFiltersfilter_decision_ = false;
  c_Njets_AK4_ = false;
  c_Nmc_final_ = false;
  c_Nmc_jets_ = false;
  c_Nmets_ = false;
  c_els_full5x5_sigmaIetaIeta_ = false;
  c_els_isPF_ = false;
  c_els_jet_ind_ = false;
  c_els_pfIsolationR03_sumChargedHadronPt_ = false;
  c_els_pfIsolationR03_sumNeutralHadronEt_ = false;
  c_els_pfIsolationR03_sumPUPt_ = false;
  c_els_pfIsolationR03_sumPhotonEt_ = false;
  c_fastjets_AK4_R1p2_R0p5pT10_energy_ = false;
  c_fastjets_AK4_R1p2_R0p5pT10_eta_ = false;
  c_fastjets_AK4_R1p2_R0p5pT10_index_ = false;
  c_fastjets_AK4_R1p2_R0p5pT10_nconstituents_ = false;
  c_fastjets_AK4_R1p2_R0p5pT10_phi_ = false;
  c_fastjets_AK4_R1p2_R0p5pT10_px_ = false;
  c_fastjets_AK4_R1p2_R0p5pT10_py_ = false;
  c_fastjets_AK4_R1p2_R0p5pT10_pz_ = false;
  c_fastjets_AK4_R1p2_R0p5pT15_energy_ = false;
  c_fastjets_AK4_R1p2_R0p5pT15_eta_ = false;
  c_fastjets_AK4_R1p2_R0p5pT15_index_ = false;
  c_fastjets_AK4_R1p2_R0p5pT15_nconstituents_ = false;
  c_fastjets_AK4_R1p2_R0p5pT15_phi_ = false;
  c_fastjets_AK4_R1p2_R0p5pT15_px_ = false;
  c_fastjets_AK4_R1p2_R0p5pT15_py_ = false;
  c_fastjets_AK4_R1p2_R0p5pT15_pz_ = false;
  c_fastjets_AK4_R1p2_R0p5pT20_energy_ = false;
  c_fastjets_AK4_R1p2_R0p5pT20_eta_ = false;
  c_fastjets_AK4_R1p2_R0p5pT20_index_ = false;
  c_fastjets_AK4_R1p2_R0p5pT20_nconstituents_ = false;
  c_fastjets_AK4_R1p2_R0p5pT20_phi_ = false;
  c_fastjets_AK4_R1p2_R0p5pT20_px_ = false;
  c_fastjets_AK4_R1p2_R0p5pT20_py_ = false;
  c_fastjets_AK4_R1p2_R0p5pT20_pz_ = false;
  c_fastjets_AK4_R1p2_R0p5pT25_energy_ = false;
  c_fastjets_AK4_R1p2_R0p5pT25_eta_ = false;
  c_fastjets_AK4_R1p2_R0p5pT25_index_ = false;
  c_fastjets_AK4_R1p2_R0p5pT25_nconstituents_ = false;
  c_fastjets_AK4_R1p2_R0p5pT25_phi_ = false;
  c_fastjets_AK4_R1p2_R0p5pT25_px_ = false;
  c_fastjets_AK4_R1p2_R0p5pT25_py_ = false;
  c_fastjets_AK4_R1p2_R0p5pT25_pz_ = false;
  c_fastjets_AK4_R1p2_R0p5pT30_energy_ = false;
  c_fastjets_AK4_R1p2_R0p5pT30_eta_ = false;
  c_fastjets_AK4_R1p2_R0p5pT30_index_ = false;
  c_fastjets_AK4_R1p2_R0p5pT30_nconstituents_ = false;
  c_fastjets_AK4_R1p2_R0p5pT30_phi_ = false;
  c_fastjets_AK4_R1p2_R0p5pT30_px_ = false;
  c_fastjets_AK4_R1p2_R0p5pT30_py_ = false;
  c_fastjets_AK4_R1p2_R0p5pT30_pz_ = false;
  c_goodVerticesfilter_decision_ = false;
  c_jets_AK4_area_ = false;
  c_jets_AK4_btag_TC_highEff_ = false;
  c_jets_AK4_btag_TC_highPur_ = false;
  c_jets_AK4_btag_jetBProb_ = false;
  c_jets_AK4_btag_jetProb_ = false;
  c_jets_AK4_btag_secVertexCombined_ = false;
  c_jets_AK4_btag_secVertexHighEff_ = false;
  c_jets_AK4_btag_secVertexHighPur_ = false;
  c_jets_AK4_btag_softEle_ = false;
  c_jets_AK4_btag_softMuon_ = false;
  c_jets_AK4_chgEmE_ = false;
  c_jets_AK4_chgHadE_ = false;
  c_jets_AK4_chgMuE_ = false;
  c_jets_AK4_chg_Mult_ = false;
  c_jets_AK4_corrFactorRaw_ = false;
  c_jets_AK4_ehf_ = false;
  c_jets_AK4_el_ind_ = false;
  c_jets_AK4_emf_ = false;
  c_jets_AK4_energy_ = false;
  c_jets_AK4_et_ = false;
  c_jets_AK4_eta_ = false;
  c_jets_AK4_etaetaMoment_ = false;
  c_jets_AK4_etaphiMoment_ = false;
  c_jets_AK4_fHPD_ = false;
  c_jets_AK4_fRBX_ = false;
  c_jets_AK4_fSubDetector1_ = false;
  c_jets_AK4_fSubDetector2_ = false;
  c_jets_AK4_fSubDetector3_ = false;
  c_jets_AK4_fSubDetector4_ = false;
  c_jets_AK4_gen_Energy_ = false;
  c_jets_AK4_gen_Id_ = false;
  c_jets_AK4_gen_et_ = false;
  c_jets_AK4_gen_eta_ = false;
  c_jets_AK4_gen_mass_ = false;
  c_jets_AK4_gen_motherID_ = false;
  c_jets_AK4_gen_phi_ = false;
  c_jets_AK4_gen_pt_ = false;
  c_jets_AK4_gen_threeCharge_ = false;
  c_jets_AK4_hitsInN90_ = false;
  c_jets_AK4_jetCharge_ = false;
  c_jets_AK4_mass_ = false;
  c_jets_AK4_maxpt_id_ = false;
  c_jets_AK4_mu_Mult_ = false;
  c_jets_AK4_mu_ind_ = false;
  c_jets_AK4_n60_ = false;
  c_jets_AK4_n90_ = false;
  c_jets_AK4_n90Hits_ = false;
  c_jets_AK4_nECALTowers_ = false;
  c_jets_AK4_nHCALTowers_ = false;
  c_jets_AK4_neutralEmE_ = false;
  c_jets_AK4_neutralHadE_ = false;
  c_jets_AK4_neutral_Mult_ = false;
  c_jets_AK4_partonFlavour_ = false;
  c_jets_AK4_parton_Energy_ = false;
  c_jets_AK4_parton_Id_ = false;
  c_jets_AK4_parton_eta_ = false;
  c_jets_AK4_parton_mass_ = false;
  c_jets_AK4_parton_motherId_ = false;
  c_jets_AK4_parton_phi_ = false;
  c_jets_AK4_parton_pt_ = false;
  c_jets_AK4_phi_ = false;
  c_jets_AK4_phiphiMoment_ = false;
  c_jets_AK4_photonEnergy_ = false;
  c_jets_AK4_pt_ = false;
  c_jets_AK4_px_ = false;
  c_jets_AK4_py_ = false;
  c_jets_AK4_pz_ = false;
  c_jets_AK4_rawPt_ = false;
  c_jets_AK4_status_ = false;
  c_jets_AK4_theta_ = false;
  c_mc_final_charge_ = false;
  c_mc_final_energy_ = false;
  c_mc_final_eta_ = false;
  c_mc_final_ggrandmother_id_ = false;
  c_mc_final_grandmother_id_ = false;
  c_mc_final_id_ = false;
  c_mc_final_mass_ = false;
  c_mc_final_mother_id_ = false;
  c_mc_final_mother_pt_ = false;
  c_mc_final_numOfDaughters_ = false;
  c_mc_final_numOfMothers_ = false;
  c_mc_final_phi_ = false;
  c_mc_final_pt_ = false;
  c_mc_final_px_ = false;
  c_mc_final_py_ = false;
  c_mc_final_pz_ = false;
  c_mc_final_status_ = false;
  c_mc_final_theta_ = false;
  c_mc_final_vertex_x_ = false;
  c_mc_final_vertex_y_ = false;
  c_mc_final_vertex_z_ = false;
  c_mc_jets_auxiliaryEnergy_ = false;
  c_mc_jets_emEnergy_ = false;
  c_mc_jets_energy_ = false;
  c_mc_jets_et_ = false;
  c_mc_jets_eta_ = false;
  c_mc_jets_etaetaMoment_ = false;
  c_mc_jets_etaphiMoment_ = false;
  c_mc_jets_hadEnergy_ = false;
  c_mc_jets_invisibleEnergy_ = false;
  c_mc_jets_mass_ = false;
  c_mc_jets_phi_ = false;
  c_mc_jets_phiphiMoment_ = false;
  c_mc_jets_pt_ = false;
  c_mc_jets_px_ = false;
  c_mc_jets_py_ = false;
  c_mc_jets_pz_ = false;
  c_mc_jets_theta_ = false;
  c_mets_et_ = false;
  c_mets_ex_ = false;
  c_mets_ey_ = false;
  c_mets_gen_et_ = false;
  c_mets_gen_phi_ = false;
  c_mets_phi_ = false;
  c_mets_sign_ = false;
  c_mets_sumEt_ = false;
  c_mets_unCPhi_ = false;
  c_mets_unCPt_ = false;
  c_mus_isPF_ = false;
  c_mus_jet_ind_ = false;
  c_taus_el_ind_ = false;
  c_taus_mu_ind_ = false;
  c_trigger_decision_ = false;
  c_trkPOG_logErrorTooManyClustersfilter_decision_ = false;
  c_trkPOG_manystripclus53Xfilter_decision_ = false;
  c_trkPOG_toomanystripclus53Xfilter_decision_ = false;
  c_trkPOGfilter_decision_ = false;
  cfa_base::GetEntry(entry);
}

void cfa_13::InitializeA(){
  cfa_base::InitializeA();
  chainA_.SetBranchAddress("EcalDeadCellTriggerPrimitivefilter_decision", &EcalDeadCellTriggerPrimitivefilter_decision_, &b_EcalDeadCellTriggerPrimitivefilter_decision_);
  chainA_.SetBranchAddress("HBHENoisefilter_decision", &HBHENoisefilter_decision_, &b_HBHENoisefilter_decision_);
  chainA_.SetBranchAddress("METFiltersfilter_decision", &METFiltersfilter_decision_, &b_METFiltersfilter_decision_);
  chainA_.SetBranchAddress("els_isPF", &els_isPF_, &b_els_isPF_);
  chainA_.SetBranchAddress("els_jet_ind", &els_jet_ind_, &b_els_jet_ind_);
  chainA_.SetBranchAddress("goodVerticesfilter_decision", &goodVerticesfilter_decision_, &b_goodVerticesfilter_decision_);
  chainA_.SetBranchAddress("jets_AK4_el_ind", &jets_AK4_el_ind_, &b_jets_AK4_el_ind_);
  chainA_.SetBranchAddress("jets_AK4_maxpt_id", &jets_AK4_maxpt_id_, &b_jets_AK4_maxpt_id_);
  chainA_.SetBranchAddress("jets_AK4_mu_ind", &jets_AK4_mu_ind_, &b_jets_AK4_mu_ind_);
  chainA_.SetBranchAddress("mus_isPF", &mus_isPF_, &b_mus_isPF_);
  chainA_.SetBranchAddress("mus_jet_ind", &mus_jet_ind_, &b_mus_jet_ind_);
  chainA_.SetBranchAddress("taus_el_ind", &taus_el_ind_, &b_taus_el_ind_);
  chainA_.SetBranchAddress("taus_mu_ind", &taus_mu_ind_, &b_taus_mu_ind_);
  chainA_.SetBranchAddress("trigger_decision", &trigger_decision_, &b_trigger_decision_);
  chainA_.SetBranchAddress("trkPOG_logErrorTooManyClustersfilter_decision", &trkPOG_logErrorTooManyClustersfilter_decision_, &b_trkPOG_logErrorTooManyClustersfilter_decision_);
  chainA_.SetBranchAddress("trkPOG_manystripclus53Xfilter_decision", &trkPOG_manystripclus53Xfilter_decision_, &b_trkPOG_manystripclus53Xfilter_decision_);
  chainA_.SetBranchAddress("trkPOG_toomanystripclus53Xfilter_decision", &trkPOG_toomanystripclus53Xfilter_decision_, &b_trkPOG_toomanystripclus53Xfilter_decision_);
  chainA_.SetBranchAddress("trkPOGfilter_decision", &trkPOGfilter_decision_, &b_trkPOGfilter_decision_);
}

void cfa_13::InitializeB(){
  cfa_base::InitializeB();
  chainB_.SetBranchAddress("Njets_AK4", &Njets_AK4_, &b_Njets_AK4_);
  chainB_.SetBranchAddress("Nmc_final", &Nmc_final_, &b_Nmc_final_);
  chainB_.SetBranchAddress("Nmc_jets", &Nmc_jets_, &b_Nmc_jets_);
  chainB_.SetBranchAddress("Nmets", &Nmets_, &b_Nmets_);
  chainB_.SetBranchAddress("els_full5x5_sigmaIetaIeta", &els_full5x5_sigmaIetaIeta_, &b_els_full5x5_sigmaIetaIeta_);
  chainB_.SetBranchAddress("els_pfIsolationR03_sumChargedHadronPt", &els_pfIsolationR03_sumChargedHadronPt_, &b_els_pfIsolationR03_sumChargedHadronPt_);
  chainB_.SetBranchAddress("els_pfIsolationR03_sumNeutralHadronEt", &els_pfIsolationR03_sumNeutralHadronEt_, &b_els_pfIsolationR03_sumNeutralHadronEt_);
  chainB_.SetBranchAddress("els_pfIsolationR03_sumPUPt", &els_pfIsolationR03_sumPUPt_, &b_els_pfIsolationR03_sumPUPt_);
  chainB_.SetBranchAddress("els_pfIsolationR03_sumPhotonEt", &els_pfIsolationR03_sumPhotonEt_, &b_els_pfIsolationR03_sumPhotonEt_);
  chainB_.SetBranchAddress("fastjets_AK4_R1p2_R0p5pT10_energy", &fastjets_AK4_R1p2_R0p5pT10_energy_, &b_fastjets_AK4_R1p2_R0p5pT10_energy_);
  chainB_.SetBranchAddress("fastjets_AK4_R1p2_R0p5pT10_eta", &fastjets_AK4_R1p2_R0p5pT10_eta_, &b_fastjets_AK4_R1p2_R0p5pT10_eta_);
  chainB_.SetBranchAddress("fastjets_AK4_R1p2_R0p5pT10_index", &fastjets_AK4_R1p2_R0p5pT10_index_, &b_fastjets_AK4_R1p2_R0p5pT10_index_);
  chainB_.SetBranchAddress("fastjets_AK4_R1p2_R0p5pT10_nconstituents", &fastjets_AK4_R1p2_R0p5pT10_nconstituents_, &b_fastjets_AK4_R1p2_R0p5pT10_nconstituents_);
  chainB_.SetBranchAddress("fastjets_AK4_R1p2_R0p5pT10_phi", &fastjets_AK4_R1p2_R0p5pT10_phi_, &b_fastjets_AK4_R1p2_R0p5pT10_phi_);
  chainB_.SetBranchAddress("fastjets_AK4_R1p2_R0p5pT10_px", &fastjets_AK4_R1p2_R0p5pT10_px_, &b_fastjets_AK4_R1p2_R0p5pT10_px_);
  chainB_.SetBranchAddress("fastjets_AK4_R1p2_R0p5pT10_py", &fastjets_AK4_R1p2_R0p5pT10_py_, &b_fastjets_AK4_R1p2_R0p5pT10_py_);
  chainB_.SetBranchAddress("fastjets_AK4_R1p2_R0p5pT10_pz", &fastjets_AK4_R1p2_R0p5pT10_pz_, &b_fastjets_AK4_R1p2_R0p5pT10_pz_);
  chainB_.SetBranchAddress("fastjets_AK4_R1p2_R0p5pT15_energy", &fastjets_AK4_R1p2_R0p5pT15_energy_, &b_fastjets_AK4_R1p2_R0p5pT15_energy_);
  chainB_.SetBranchAddress("fastjets_AK4_R1p2_R0p5pT15_eta", &fastjets_AK4_R1p2_R0p5pT15_eta_, &b_fastjets_AK4_R1p2_R0p5pT15_eta_);
  chainB_.SetBranchAddress("fastjets_AK4_R1p2_R0p5pT15_index", &fastjets_AK4_R1p2_R0p5pT15_index_, &b_fastjets_AK4_R1p2_R0p5pT15_index_);
  chainB_.SetBranchAddress("fastjets_AK4_R1p2_R0p5pT15_nconstituents", &fastjets_AK4_R1p2_R0p5pT15_nconstituents_, &b_fastjets_AK4_R1p2_R0p5pT15_nconstituents_);
  chainB_.SetBranchAddress("fastjets_AK4_R1p2_R0p5pT15_phi", &fastjets_AK4_R1p2_R0p5pT15_phi_, &b_fastjets_AK4_R1p2_R0p5pT15_phi_);
  chainB_.SetBranchAddress("fastjets_AK4_R1p2_R0p5pT15_px", &fastjets_AK4_R1p2_R0p5pT15_px_, &b_fastjets_AK4_R1p2_R0p5pT15_px_);
  chainB_.SetBranchAddress("fastjets_AK4_R1p2_R0p5pT15_py", &fastjets_AK4_R1p2_R0p5pT15_py_, &b_fastjets_AK4_R1p2_R0p5pT15_py_);
  chainB_.SetBranchAddress("fastjets_AK4_R1p2_R0p5pT15_pz", &fastjets_AK4_R1p2_R0p5pT15_pz_, &b_fastjets_AK4_R1p2_R0p5pT15_pz_);
  chainB_.SetBranchAddress("fastjets_AK4_R1p2_R0p5pT20_energy", &fastjets_AK4_R1p2_R0p5pT20_energy_, &b_fastjets_AK4_R1p2_R0p5pT20_energy_);
  chainB_.SetBranchAddress("fastjets_AK4_R1p2_R0p5pT20_eta", &fastjets_AK4_R1p2_R0p5pT20_eta_, &b_fastjets_AK4_R1p2_R0p5pT20_eta_);
  chainB_.SetBranchAddress("fastjets_AK4_R1p2_R0p5pT20_index", &fastjets_AK4_R1p2_R0p5pT20_index_, &b_fastjets_AK4_R1p2_R0p5pT20_index_);
  chainB_.SetBranchAddress("fastjets_AK4_R1p2_R0p5pT20_nconstituents", &fastjets_AK4_R1p2_R0p5pT20_nconstituents_, &b_fastjets_AK4_R1p2_R0p5pT20_nconstituents_);
  chainB_.SetBranchAddress("fastjets_AK4_R1p2_R0p5pT20_phi", &fastjets_AK4_R1p2_R0p5pT20_phi_, &b_fastjets_AK4_R1p2_R0p5pT20_phi_);
  chainB_.SetBranchAddress("fastjets_AK4_R1p2_R0p5pT20_px", &fastjets_AK4_R1p2_R0p5pT20_px_, &b_fastjets_AK4_R1p2_R0p5pT20_px_);
  chainB_.SetBranchAddress("fastjets_AK4_R1p2_R0p5pT20_py", &fastjets_AK4_R1p2_R0p5pT20_py_, &b_fastjets_AK4_R1p2_R0p5pT20_py_);
  chainB_.SetBranchAddress("fastjets_AK4_R1p2_R0p5pT20_pz", &fastjets_AK4_R1p2_R0p5pT20_pz_, &b_fastjets_AK4_R1p2_R0p5pT20_pz_);
  chainB_.SetBranchAddress("fastjets_AK4_R1p2_R0p5pT25_energy", &fastjets_AK4_R1p2_R0p5pT25_energy_, &b_fastjets_AK4_R1p2_R0p5pT25_energy_);
  chainB_.SetBranchAddress("fastjets_AK4_R1p2_R0p5pT25_eta", &fastjets_AK4_R1p2_R0p5pT25_eta_, &b_fastjets_AK4_R1p2_R0p5pT25_eta_);
  chainB_.SetBranchAddress("fastjets_AK4_R1p2_R0p5pT25_index", &fastjets_AK4_R1p2_R0p5pT25_index_, &b_fastjets_AK4_R1p2_R0p5pT25_index_);
  chainB_.SetBranchAddress("fastjets_AK4_R1p2_R0p5pT25_nconstituents", &fastjets_AK4_R1p2_R0p5pT25_nconstituents_, &b_fastjets_AK4_R1p2_R0p5pT25_nconstituents_);
  chainB_.SetBranchAddress("fastjets_AK4_R1p2_R0p5pT25_phi", &fastjets_AK4_R1p2_R0p5pT25_phi_, &b_fastjets_AK4_R1p2_R0p5pT25_phi_);
  chainB_.SetBranchAddress("fastjets_AK4_R1p2_R0p5pT25_px", &fastjets_AK4_R1p2_R0p5pT25_px_, &b_fastjets_AK4_R1p2_R0p5pT25_px_);
  chainB_.SetBranchAddress("fastjets_AK4_R1p2_R0p5pT25_py", &fastjets_AK4_R1p2_R0p5pT25_py_, &b_fastjets_AK4_R1p2_R0p5pT25_py_);
  chainB_.SetBranchAddress("fastjets_AK4_R1p2_R0p5pT25_pz", &fastjets_AK4_R1p2_R0p5pT25_pz_, &b_fastjets_AK4_R1p2_R0p5pT25_pz_);
  chainB_.SetBranchAddress("fastjets_AK4_R1p2_R0p5pT30_energy", &fastjets_AK4_R1p2_R0p5pT30_energy_, &b_fastjets_AK4_R1p2_R0p5pT30_energy_);
  chainB_.SetBranchAddress("fastjets_AK4_R1p2_R0p5pT30_eta", &fastjets_AK4_R1p2_R0p5pT30_eta_, &b_fastjets_AK4_R1p2_R0p5pT30_eta_);
  chainB_.SetBranchAddress("fastjets_AK4_R1p2_R0p5pT30_index", &fastjets_AK4_R1p2_R0p5pT30_index_, &b_fastjets_AK4_R1p2_R0p5pT30_index_);
  chainB_.SetBranchAddress("fastjets_AK4_R1p2_R0p5pT30_nconstituents", &fastjets_AK4_R1p2_R0p5pT30_nconstituents_, &b_fastjets_AK4_R1p2_R0p5pT30_nconstituents_);
  chainB_.SetBranchAddress("fastjets_AK4_R1p2_R0p5pT30_phi", &fastjets_AK4_R1p2_R0p5pT30_phi_, &b_fastjets_AK4_R1p2_R0p5pT30_phi_);
  chainB_.SetBranchAddress("fastjets_AK4_R1p2_R0p5pT30_px", &fastjets_AK4_R1p2_R0p5pT30_px_, &b_fastjets_AK4_R1p2_R0p5pT30_px_);
  chainB_.SetBranchAddress("fastjets_AK4_R1p2_R0p5pT30_py", &fastjets_AK4_R1p2_R0p5pT30_py_, &b_fastjets_AK4_R1p2_R0p5pT30_py_);
  chainB_.SetBranchAddress("fastjets_AK4_R1p2_R0p5pT30_pz", &fastjets_AK4_R1p2_R0p5pT30_pz_, &b_fastjets_AK4_R1p2_R0p5pT30_pz_);
  chainB_.SetBranchAddress("jets_AK4_area", &jets_AK4_area_, &b_jets_AK4_area_);
  chainB_.SetBranchAddress("jets_AK4_btag_TC_highEff", &jets_AK4_btag_TC_highEff_, &b_jets_AK4_btag_TC_highEff_);
  chainB_.SetBranchAddress("jets_AK4_btag_TC_highPur", &jets_AK4_btag_TC_highPur_, &b_jets_AK4_btag_TC_highPur_);
  chainB_.SetBranchAddress("jets_AK4_btag_jetBProb", &jets_AK4_btag_jetBProb_, &b_jets_AK4_btag_jetBProb_);
  chainB_.SetBranchAddress("jets_AK4_btag_jetProb", &jets_AK4_btag_jetProb_, &b_jets_AK4_btag_jetProb_);
  chainB_.SetBranchAddress("jets_AK4_btag_secVertexCombined", &jets_AK4_btag_secVertexCombined_, &b_jets_AK4_btag_secVertexCombined_);
  chainB_.SetBranchAddress("jets_AK4_btag_secVertexHighEff", &jets_AK4_btag_secVertexHighEff_, &b_jets_AK4_btag_secVertexHighEff_);
  chainB_.SetBranchAddress("jets_AK4_btag_secVertexHighPur", &jets_AK4_btag_secVertexHighPur_, &b_jets_AK4_btag_secVertexHighPur_);
  chainB_.SetBranchAddress("jets_AK4_btag_softEle", &jets_AK4_btag_softEle_, &b_jets_AK4_btag_softEle_);
  chainB_.SetBranchAddress("jets_AK4_btag_softMuon", &jets_AK4_btag_softMuon_, &b_jets_AK4_btag_softMuon_);
  chainB_.SetBranchAddress("jets_AK4_chgEmE", &jets_AK4_chgEmE_, &b_jets_AK4_chgEmE_);
  chainB_.SetBranchAddress("jets_AK4_chgHadE", &jets_AK4_chgHadE_, &b_jets_AK4_chgHadE_);
  chainB_.SetBranchAddress("jets_AK4_chgMuE", &jets_AK4_chgMuE_, &b_jets_AK4_chgMuE_);
  chainB_.SetBranchAddress("jets_AK4_chg_Mult", &jets_AK4_chg_Mult_, &b_jets_AK4_chg_Mult_);
  chainB_.SetBranchAddress("jets_AK4_corrFactorRaw", &jets_AK4_corrFactorRaw_, &b_jets_AK4_corrFactorRaw_);
  chainB_.SetBranchAddress("jets_AK4_ehf", &jets_AK4_ehf_, &b_jets_AK4_ehf_);
  chainB_.SetBranchAddress("jets_AK4_emf", &jets_AK4_emf_, &b_jets_AK4_emf_);
  chainB_.SetBranchAddress("jets_AK4_energy", &jets_AK4_energy_, &b_jets_AK4_energy_);
  chainB_.SetBranchAddress("jets_AK4_et", &jets_AK4_et_, &b_jets_AK4_et_);
  chainB_.SetBranchAddress("jets_AK4_eta", &jets_AK4_eta_, &b_jets_AK4_eta_);
  chainB_.SetBranchAddress("jets_AK4_etaetaMoment", &jets_AK4_etaetaMoment_, &b_jets_AK4_etaetaMoment_);
  chainB_.SetBranchAddress("jets_AK4_etaphiMoment", &jets_AK4_etaphiMoment_, &b_jets_AK4_etaphiMoment_);
  chainB_.SetBranchAddress("jets_AK4_fHPD", &jets_AK4_fHPD_, &b_jets_AK4_fHPD_);
  chainB_.SetBranchAddress("jets_AK4_fRBX", &jets_AK4_fRBX_, &b_jets_AK4_fRBX_);
  chainB_.SetBranchAddress("jets_AK4_fSubDetector1", &jets_AK4_fSubDetector1_, &b_jets_AK4_fSubDetector1_);
  chainB_.SetBranchAddress("jets_AK4_fSubDetector2", &jets_AK4_fSubDetector2_, &b_jets_AK4_fSubDetector2_);
  chainB_.SetBranchAddress("jets_AK4_fSubDetector3", &jets_AK4_fSubDetector3_, &b_jets_AK4_fSubDetector3_);
  chainB_.SetBranchAddress("jets_AK4_fSubDetector4", &jets_AK4_fSubDetector4_, &b_jets_AK4_fSubDetector4_);
  chainB_.SetBranchAddress("jets_AK4_gen_Energy", &jets_AK4_gen_Energy_, &b_jets_AK4_gen_Energy_);
  chainB_.SetBranchAddress("jets_AK4_gen_Id", &jets_AK4_gen_Id_, &b_jets_AK4_gen_Id_);
  chainB_.SetBranchAddress("jets_AK4_gen_et", &jets_AK4_gen_et_, &b_jets_AK4_gen_et_);
  chainB_.SetBranchAddress("jets_AK4_gen_eta", &jets_AK4_gen_eta_, &b_jets_AK4_gen_eta_);
  chainB_.SetBranchAddress("jets_AK4_gen_mass", &jets_AK4_gen_mass_, &b_jets_AK4_gen_mass_);
  chainB_.SetBranchAddress("jets_AK4_gen_motherID", &jets_AK4_gen_motherID_, &b_jets_AK4_gen_motherID_);
  chainB_.SetBranchAddress("jets_AK4_gen_phi", &jets_AK4_gen_phi_, &b_jets_AK4_gen_phi_);
  chainB_.SetBranchAddress("jets_AK4_gen_pt", &jets_AK4_gen_pt_, &b_jets_AK4_gen_pt_);
  chainB_.SetBranchAddress("jets_AK4_gen_threeCharge", &jets_AK4_gen_threeCharge_, &b_jets_AK4_gen_threeCharge_);
  chainB_.SetBranchAddress("jets_AK4_hitsInN90", &jets_AK4_hitsInN90_, &b_jets_AK4_hitsInN90_);
  chainB_.SetBranchAddress("jets_AK4_jetCharge", &jets_AK4_jetCharge_, &b_jets_AK4_jetCharge_);
  chainB_.SetBranchAddress("jets_AK4_mass", &jets_AK4_mass_, &b_jets_AK4_mass_);
  chainB_.SetBranchAddress("jets_AK4_mu_Mult", &jets_AK4_mu_Mult_, &b_jets_AK4_mu_Mult_);
  chainB_.SetBranchAddress("jets_AK4_n60", &jets_AK4_n60_, &b_jets_AK4_n60_);
  chainB_.SetBranchAddress("jets_AK4_n90", &jets_AK4_n90_, &b_jets_AK4_n90_);
  chainB_.SetBranchAddress("jets_AK4_n90Hits", &jets_AK4_n90Hits_, &b_jets_AK4_n90Hits_);
  chainB_.SetBranchAddress("jets_AK4_nECALTowers", &jets_AK4_nECALTowers_, &b_jets_AK4_nECALTowers_);
  chainB_.SetBranchAddress("jets_AK4_nHCALTowers", &jets_AK4_nHCALTowers_, &b_jets_AK4_nHCALTowers_);
  chainB_.SetBranchAddress("jets_AK4_neutralEmE", &jets_AK4_neutralEmE_, &b_jets_AK4_neutralEmE_);
  chainB_.SetBranchAddress("jets_AK4_neutralHadE", &jets_AK4_neutralHadE_, &b_jets_AK4_neutralHadE_);
  chainB_.SetBranchAddress("jets_AK4_neutral_Mult", &jets_AK4_neutral_Mult_, &b_jets_AK4_neutral_Mult_);
  chainB_.SetBranchAddress("jets_AK4_partonFlavour", &jets_AK4_partonFlavour_, &b_jets_AK4_partonFlavour_);
  chainB_.SetBranchAddress("jets_AK4_parton_Energy", &jets_AK4_parton_Energy_, &b_jets_AK4_parton_Energy_);
  chainB_.SetBranchAddress("jets_AK4_parton_Id", &jets_AK4_parton_Id_, &b_jets_AK4_parton_Id_);
  chainB_.SetBranchAddress("jets_AK4_parton_eta", &jets_AK4_parton_eta_, &b_jets_AK4_parton_eta_);
  chainB_.SetBranchAddress("jets_AK4_parton_mass", &jets_AK4_parton_mass_, &b_jets_AK4_parton_mass_);
  chainB_.SetBranchAddress("jets_AK4_parton_motherId", &jets_AK4_parton_motherId_, &b_jets_AK4_parton_motherId_);
  chainB_.SetBranchAddress("jets_AK4_parton_phi", &jets_AK4_parton_phi_, &b_jets_AK4_parton_phi_);
  chainB_.SetBranchAddress("jets_AK4_parton_pt", &jets_AK4_parton_pt_, &b_jets_AK4_parton_pt_);
  chainB_.SetBranchAddress("jets_AK4_phi", &jets_AK4_phi_, &b_jets_AK4_phi_);
  chainB_.SetBranchAddress("jets_AK4_phiphiMoment", &jets_AK4_phiphiMoment_, &b_jets_AK4_phiphiMoment_);
  chainB_.SetBranchAddress("jets_AK4_photonEnergy", &jets_AK4_photonEnergy_, &b_jets_AK4_photonEnergy_);
  chainB_.SetBranchAddress("jets_AK4_pt", &jets_AK4_pt_, &b_jets_AK4_pt_);
  chainB_.SetBranchAddress("jets_AK4_px", &jets_AK4_px_, &b_jets_AK4_px_);
  chainB_.SetBranchAddress("jets_AK4_py", &jets_AK4_py_, &b_jets_AK4_py_);
  chainB_.SetBranchAddress("jets_AK4_pz", &jets_AK4_pz_, &b_jets_AK4_pz_);
  chainB_.SetBranchAddress("jets_AK4_rawPt", &jets_AK4_rawPt_, &b_jets_AK4_rawPt_);
  chainB_.SetBranchAddress("jets_AK4_status", &jets_AK4_status_, &b_jets_AK4_status_);
  chainB_.SetBranchAddress("jets_AK4_theta", &jets_AK4_theta_, &b_jets_AK4_theta_);
  chainB_.SetBranchAddress("mc_final_charge", &mc_final_charge_, &b_mc_final_charge_);
  chainB_.SetBranchAddress("mc_final_energy", &mc_final_energy_, &b_mc_final_energy_);
  chainB_.SetBranchAddress("mc_final_eta", &mc_final_eta_, &b_mc_final_eta_);
  chainB_.SetBranchAddress("mc_final_ggrandmother_id", &mc_final_ggrandmother_id_, &b_mc_final_ggrandmother_id_);
  chainB_.SetBranchAddress("mc_final_grandmother_id", &mc_final_grandmother_id_, &b_mc_final_grandmother_id_);
  chainB_.SetBranchAddress("mc_final_id", &mc_final_id_, &b_mc_final_id_);
  chainB_.SetBranchAddress("mc_final_mass", &mc_final_mass_, &b_mc_final_mass_);
  chainB_.SetBranchAddress("mc_final_mother_id", &mc_final_mother_id_, &b_mc_final_mother_id_);
  chainB_.SetBranchAddress("mc_final_mother_pt", &mc_final_mother_pt_, &b_mc_final_mother_pt_);
  chainB_.SetBranchAddress("mc_final_numOfDaughters", &mc_final_numOfDaughters_, &b_mc_final_numOfDaughters_);
  chainB_.SetBranchAddress("mc_final_numOfMothers", &mc_final_numOfMothers_, &b_mc_final_numOfMothers_);
  chainB_.SetBranchAddress("mc_final_phi", &mc_final_phi_, &b_mc_final_phi_);
  chainB_.SetBranchAddress("mc_final_pt", &mc_final_pt_, &b_mc_final_pt_);
  chainB_.SetBranchAddress("mc_final_px", &mc_final_px_, &b_mc_final_px_);
  chainB_.SetBranchAddress("mc_final_py", &mc_final_py_, &b_mc_final_py_);
  chainB_.SetBranchAddress("mc_final_pz", &mc_final_pz_, &b_mc_final_pz_);
  chainB_.SetBranchAddress("mc_final_status", &mc_final_status_, &b_mc_final_status_);
  chainB_.SetBranchAddress("mc_final_theta", &mc_final_theta_, &b_mc_final_theta_);
  chainB_.SetBranchAddress("mc_final_vertex_x", &mc_final_vertex_x_, &b_mc_final_vertex_x_);
  chainB_.SetBranchAddress("mc_final_vertex_y", &mc_final_vertex_y_, &b_mc_final_vertex_y_);
  chainB_.SetBranchAddress("mc_final_vertex_z", &mc_final_vertex_z_, &b_mc_final_vertex_z_);
  chainB_.SetBranchAddress("mc_jets_auxiliaryEnergy", &mc_jets_auxiliaryEnergy_, &b_mc_jets_auxiliaryEnergy_);
  chainB_.SetBranchAddress("mc_jets_emEnergy", &mc_jets_emEnergy_, &b_mc_jets_emEnergy_);
  chainB_.SetBranchAddress("mc_jets_energy", &mc_jets_energy_, &b_mc_jets_energy_);
  chainB_.SetBranchAddress("mc_jets_et", &mc_jets_et_, &b_mc_jets_et_);
  chainB_.SetBranchAddress("mc_jets_eta", &mc_jets_eta_, &b_mc_jets_eta_);
  chainB_.SetBranchAddress("mc_jets_etaetaMoment", &mc_jets_etaetaMoment_, &b_mc_jets_etaetaMoment_);
  chainB_.SetBranchAddress("mc_jets_etaphiMoment", &mc_jets_etaphiMoment_, &b_mc_jets_etaphiMoment_);
  chainB_.SetBranchAddress("mc_jets_hadEnergy", &mc_jets_hadEnergy_, &b_mc_jets_hadEnergy_);
  chainB_.SetBranchAddress("mc_jets_invisibleEnergy", &mc_jets_invisibleEnergy_, &b_mc_jets_invisibleEnergy_);
  chainB_.SetBranchAddress("mc_jets_mass", &mc_jets_mass_, &b_mc_jets_mass_);
  chainB_.SetBranchAddress("mc_jets_phi", &mc_jets_phi_, &b_mc_jets_phi_);
  chainB_.SetBranchAddress("mc_jets_phiphiMoment", &mc_jets_phiphiMoment_, &b_mc_jets_phiphiMoment_);
  chainB_.SetBranchAddress("mc_jets_pt", &mc_jets_pt_, &b_mc_jets_pt_);
  chainB_.SetBranchAddress("mc_jets_px", &mc_jets_px_, &b_mc_jets_px_);
  chainB_.SetBranchAddress("mc_jets_py", &mc_jets_py_, &b_mc_jets_py_);
  chainB_.SetBranchAddress("mc_jets_pz", &mc_jets_pz_, &b_mc_jets_pz_);
  chainB_.SetBranchAddress("mc_jets_theta", &mc_jets_theta_, &b_mc_jets_theta_);
  chainB_.SetBranchAddress("mets_et", &mets_et_, &b_mets_et_);
  chainB_.SetBranchAddress("mets_ex", &mets_ex_, &b_mets_ex_);
  chainB_.SetBranchAddress("mets_ey", &mets_ey_, &b_mets_ey_);
  chainB_.SetBranchAddress("mets_gen_et", &mets_gen_et_, &b_mets_gen_et_);
  chainB_.SetBranchAddress("mets_gen_phi", &mets_gen_phi_, &b_mets_gen_phi_);
  chainB_.SetBranchAddress("mets_phi", &mets_phi_, &b_mets_phi_);
  chainB_.SetBranchAddress("mets_sign", &mets_sign_, &b_mets_sign_);
  chainB_.SetBranchAddress("mets_sumEt", &mets_sumEt_, &b_mets_sumEt_);
  chainB_.SetBranchAddress("mets_unCPhi", &mets_unCPhi_, &b_mets_unCPhi_);
  chainB_.SetBranchAddress("mets_unCPt", &mets_unCPt_, &b_mets_unCPt_);
}

cfa_13::~cfa_13(){
}

Int_t const & cfa_13::EcalDeadCellTriggerPrimitivefilter_decision() const{
  if(!c_EcalDeadCellTriggerPrimitivefilter_decision_ && b_EcalDeadCellTriggerPrimitivefilter_decision_){
    b_EcalDeadCellTriggerPrimitivefilter_decision_->GetEntry(entry_);
    c_EcalDeadCellTriggerPrimitivefilter_decision_ = true;
  }
  return EcalDeadCellTriggerPrimitivefilter_decision_;
}

Int_t const & cfa_13::HBHENoisefilter_decision() const{
  if(!c_HBHENoisefilter_decision_ && b_HBHENoisefilter_decision_){
    b_HBHENoisefilter_decision_->GetEntry(entry_);
    c_HBHENoisefilter_decision_ = true;
  }
  return HBHENoisefilter_decision_;
}

Int_t const & cfa_13::METFiltersfilter_decision() const{
  if(!c_METFiltersfilter_decision_ && b_METFiltersfilter_decision_){
    b_METFiltersfilter_decision_->GetEntry(entry_);
    c_METFiltersfilter_decision_ = true;
  }
  return METFiltersfilter_decision_;
}

UInt_t const & cfa_13::Njets_AK4() const{
  if(!c_Njets_AK4_ && b_Njets_AK4_){
    b_Njets_AK4_->GetEntry(entry_);
    c_Njets_AK4_ = true;
  }
  return Njets_AK4_;
}

UInt_t const & cfa_13::Nmc_final() const{
  if(!c_Nmc_final_ && b_Nmc_final_){
    b_Nmc_final_->GetEntry(entry_);
    c_Nmc_final_ = true;
  }
  return Nmc_final_;
}

UInt_t const & cfa_13::Nmc_jets() const{
  if(!c_Nmc_jets_ && b_Nmc_jets_){
    b_Nmc_jets_->GetEntry(entry_);
    c_Nmc_jets_ = true;
  }
  return Nmc_jets_;
}

UInt_t const & cfa_13::Nmets() const{
  if(!c_Nmets_ && b_Nmets_){
    b_Nmets_->GetEntry(entry_);
    c_Nmets_ = true;
  }
  return Nmets_;
}

std::vector<float>* const & cfa_13::els_full5x5_sigmaIetaIeta() const{
  if(!c_els_full5x5_sigmaIetaIeta_ && b_els_full5x5_sigmaIetaIeta_){
    b_els_full5x5_sigmaIetaIeta_->GetEntry(entry_);
    c_els_full5x5_sigmaIetaIeta_ = true;
  }
  return els_full5x5_sigmaIetaIeta_;
}

std::vector<bool>* const & cfa_13::els_isPF() const{
  if(!c_els_isPF_ && b_els_isPF_){
    b_els_isPF_->GetEntry(entry_);
    c_els_isPF_ = true;
  }
  return els_isPF_;
}

std::vector<int>* const & cfa_13::els_jet_ind() const{
  if(!c_els_jet_ind_ && b_els_jet_ind_){
    b_els_jet_ind_->GetEntry(entry_);
    c_els_jet_ind_ = true;
  }
  return els_jet_ind_;
}

std::vector<float>* const & cfa_13::els_pfIsolationR03_sumChargedHadronPt() const{
  if(!c_els_pfIsolationR03_sumChargedHadronPt_ && b_els_pfIsolationR03_sumChargedHadronPt_){
    b_els_pfIsolationR03_sumChargedHadronPt_->GetEntry(entry_);
    c_els_pfIsolationR03_sumChargedHadronPt_ = true;
  }
  return els_pfIsolationR03_sumChargedHadronPt_;
}

std::vector<float>* const & cfa_13::els_pfIsolationR03_sumNeutralHadronEt() const{
  if(!c_els_pfIsolationR03_sumNeutralHadronEt_ && b_els_pfIsolationR03_sumNeutralHadronEt_){
    b_els_pfIsolationR03_sumNeutralHadronEt_->GetEntry(entry_);
    c_els_pfIsolationR03_sumNeutralHadronEt_ = true;
  }
  return els_pfIsolationR03_sumNeutralHadronEt_;
}

std::vector<float>* const & cfa_13::els_pfIsolationR03_sumPUPt() const{
  if(!c_els_pfIsolationR03_sumPUPt_ && b_els_pfIsolationR03_sumPUPt_){
    b_els_pfIsolationR03_sumPUPt_->GetEntry(entry_);
    c_els_pfIsolationR03_sumPUPt_ = true;
  }
  return els_pfIsolationR03_sumPUPt_;
}

std::vector<float>* const & cfa_13::els_pfIsolationR03_sumPhotonEt() const{
  if(!c_els_pfIsolationR03_sumPhotonEt_ && b_els_pfIsolationR03_sumPhotonEt_){
    b_els_pfIsolationR03_sumPhotonEt_->GetEntry(entry_);
    c_els_pfIsolationR03_sumPhotonEt_ = true;
  }
  return els_pfIsolationR03_sumPhotonEt_;
}

std::vector<float>* const & cfa_13::fastjets_AK4_R1p2_R0p5pT10_energy() const{
  if(!c_fastjets_AK4_R1p2_R0p5pT10_energy_ && b_fastjets_AK4_R1p2_R0p5pT10_energy_){
    b_fastjets_AK4_R1p2_R0p5pT10_energy_->GetEntry(entry_);
    c_fastjets_AK4_R1p2_R0p5pT10_energy_ = true;
  }
  return fastjets_AK4_R1p2_R0p5pT10_energy_;
}

std::vector<float>* const & cfa_13::fastjets_AK4_R1p2_R0p5pT10_eta() const{
  if(!c_fastjets_AK4_R1p2_R0p5pT10_eta_ && b_fastjets_AK4_R1p2_R0p5pT10_eta_){
    b_fastjets_AK4_R1p2_R0p5pT10_eta_->GetEntry(entry_);
    c_fastjets_AK4_R1p2_R0p5pT10_eta_ = true;
  }
  return fastjets_AK4_R1p2_R0p5pT10_eta_;
}

std::vector<std::vector<int> >* const & cfa_13::fastjets_AK4_R1p2_R0p5pT10_index() const{
  if(!c_fastjets_AK4_R1p2_R0p5pT10_index_ && b_fastjets_AK4_R1p2_R0p5pT10_index_){
    b_fastjets_AK4_R1p2_R0p5pT10_index_->GetEntry(entry_);
    c_fastjets_AK4_R1p2_R0p5pT10_index_ = true;
  }
  return fastjets_AK4_R1p2_R0p5pT10_index_;
}

std::vector<int>* const & cfa_13::fastjets_AK4_R1p2_R0p5pT10_nconstituents() const{
  if(!c_fastjets_AK4_R1p2_R0p5pT10_nconstituents_ && b_fastjets_AK4_R1p2_R0p5pT10_nconstituents_){
    b_fastjets_AK4_R1p2_R0p5pT10_nconstituents_->GetEntry(entry_);
    c_fastjets_AK4_R1p2_R0p5pT10_nconstituents_ = true;
  }
  return fastjets_AK4_R1p2_R0p5pT10_nconstituents_;
}

std::vector<float>* const & cfa_13::fastjets_AK4_R1p2_R0p5pT10_phi() const{
  if(!c_fastjets_AK4_R1p2_R0p5pT10_phi_ && b_fastjets_AK4_R1p2_R0p5pT10_phi_){
    b_fastjets_AK4_R1p2_R0p5pT10_phi_->GetEntry(entry_);
    c_fastjets_AK4_R1p2_R0p5pT10_phi_ = true;
  }
  return fastjets_AK4_R1p2_R0p5pT10_phi_;
}

std::vector<float>* const & cfa_13::fastjets_AK4_R1p2_R0p5pT10_px() const{
  if(!c_fastjets_AK4_R1p2_R0p5pT10_px_ && b_fastjets_AK4_R1p2_R0p5pT10_px_){
    b_fastjets_AK4_R1p2_R0p5pT10_px_->GetEntry(entry_);
    c_fastjets_AK4_R1p2_R0p5pT10_px_ = true;
  }
  return fastjets_AK4_R1p2_R0p5pT10_px_;
}

std::vector<float>* const & cfa_13::fastjets_AK4_R1p2_R0p5pT10_py() const{
  if(!c_fastjets_AK4_R1p2_R0p5pT10_py_ && b_fastjets_AK4_R1p2_R0p5pT10_py_){
    b_fastjets_AK4_R1p2_R0p5pT10_py_->GetEntry(entry_);
    c_fastjets_AK4_R1p2_R0p5pT10_py_ = true;
  }
  return fastjets_AK4_R1p2_R0p5pT10_py_;
}

std::vector<float>* const & cfa_13::fastjets_AK4_R1p2_R0p5pT10_pz() const{
  if(!c_fastjets_AK4_R1p2_R0p5pT10_pz_ && b_fastjets_AK4_R1p2_R0p5pT10_pz_){
    b_fastjets_AK4_R1p2_R0p5pT10_pz_->GetEntry(entry_);
    c_fastjets_AK4_R1p2_R0p5pT10_pz_ = true;
  }
  return fastjets_AK4_R1p2_R0p5pT10_pz_;
}

std::vector<float>* const & cfa_13::fastjets_AK4_R1p2_R0p5pT15_energy() const{
  if(!c_fastjets_AK4_R1p2_R0p5pT15_energy_ && b_fastjets_AK4_R1p2_R0p5pT15_energy_){
    b_fastjets_AK4_R1p2_R0p5pT15_energy_->GetEntry(entry_);
    c_fastjets_AK4_R1p2_R0p5pT15_energy_ = true;
  }
  return fastjets_AK4_R1p2_R0p5pT15_energy_;
}

std::vector<float>* const & cfa_13::fastjets_AK4_R1p2_R0p5pT15_eta() const{
  if(!c_fastjets_AK4_R1p2_R0p5pT15_eta_ && b_fastjets_AK4_R1p2_R0p5pT15_eta_){
    b_fastjets_AK4_R1p2_R0p5pT15_eta_->GetEntry(entry_);
    c_fastjets_AK4_R1p2_R0p5pT15_eta_ = true;
  }
  return fastjets_AK4_R1p2_R0p5pT15_eta_;
}

std::vector<std::vector<int> >* const & cfa_13::fastjets_AK4_R1p2_R0p5pT15_index() const{
  if(!c_fastjets_AK4_R1p2_R0p5pT15_index_ && b_fastjets_AK4_R1p2_R0p5pT15_index_){
    b_fastjets_AK4_R1p2_R0p5pT15_index_->GetEntry(entry_);
    c_fastjets_AK4_R1p2_R0p5pT15_index_ = true;
  }
  return fastjets_AK4_R1p2_R0p5pT15_index_;
}

std::vector<int>* const & cfa_13::fastjets_AK4_R1p2_R0p5pT15_nconstituents() const{
  if(!c_fastjets_AK4_R1p2_R0p5pT15_nconstituents_ && b_fastjets_AK4_R1p2_R0p5pT15_nconstituents_){
    b_fastjets_AK4_R1p2_R0p5pT15_nconstituents_->GetEntry(entry_);
    c_fastjets_AK4_R1p2_R0p5pT15_nconstituents_ = true;
  }
  return fastjets_AK4_R1p2_R0p5pT15_nconstituents_;
}

std::vector<float>* const & cfa_13::fastjets_AK4_R1p2_R0p5pT15_phi() const{
  if(!c_fastjets_AK4_R1p2_R0p5pT15_phi_ && b_fastjets_AK4_R1p2_R0p5pT15_phi_){
    b_fastjets_AK4_R1p2_R0p5pT15_phi_->GetEntry(entry_);
    c_fastjets_AK4_R1p2_R0p5pT15_phi_ = true;
  }
  return fastjets_AK4_R1p2_R0p5pT15_phi_;
}

std::vector<float>* const & cfa_13::fastjets_AK4_R1p2_R0p5pT15_px() const{
  if(!c_fastjets_AK4_R1p2_R0p5pT15_px_ && b_fastjets_AK4_R1p2_R0p5pT15_px_){
    b_fastjets_AK4_R1p2_R0p5pT15_px_->GetEntry(entry_);
    c_fastjets_AK4_R1p2_R0p5pT15_px_ = true;
  }
  return fastjets_AK4_R1p2_R0p5pT15_px_;
}

std::vector<float>* const & cfa_13::fastjets_AK4_R1p2_R0p5pT15_py() const{
  if(!c_fastjets_AK4_R1p2_R0p5pT15_py_ && b_fastjets_AK4_R1p2_R0p5pT15_py_){
    b_fastjets_AK4_R1p2_R0p5pT15_py_->GetEntry(entry_);
    c_fastjets_AK4_R1p2_R0p5pT15_py_ = true;
  }
  return fastjets_AK4_R1p2_R0p5pT15_py_;
}

std::vector<float>* const & cfa_13::fastjets_AK4_R1p2_R0p5pT15_pz() const{
  if(!c_fastjets_AK4_R1p2_R0p5pT15_pz_ && b_fastjets_AK4_R1p2_R0p5pT15_pz_){
    b_fastjets_AK4_R1p2_R0p5pT15_pz_->GetEntry(entry_);
    c_fastjets_AK4_R1p2_R0p5pT15_pz_ = true;
  }
  return fastjets_AK4_R1p2_R0p5pT15_pz_;
}

std::vector<float>* const & cfa_13::fastjets_AK4_R1p2_R0p5pT20_energy() const{
  if(!c_fastjets_AK4_R1p2_R0p5pT20_energy_ && b_fastjets_AK4_R1p2_R0p5pT20_energy_){
    b_fastjets_AK4_R1p2_R0p5pT20_energy_->GetEntry(entry_);
    c_fastjets_AK4_R1p2_R0p5pT20_energy_ = true;
  }
  return fastjets_AK4_R1p2_R0p5pT20_energy_;
}

std::vector<float>* const & cfa_13::fastjets_AK4_R1p2_R0p5pT20_eta() const{
  if(!c_fastjets_AK4_R1p2_R0p5pT20_eta_ && b_fastjets_AK4_R1p2_R0p5pT20_eta_){
    b_fastjets_AK4_R1p2_R0p5pT20_eta_->GetEntry(entry_);
    c_fastjets_AK4_R1p2_R0p5pT20_eta_ = true;
  }
  return fastjets_AK4_R1p2_R0p5pT20_eta_;
}

std::vector<std::vector<int> >* const & cfa_13::fastjets_AK4_R1p2_R0p5pT20_index() const{
  if(!c_fastjets_AK4_R1p2_R0p5pT20_index_ && b_fastjets_AK4_R1p2_R0p5pT20_index_){
    b_fastjets_AK4_R1p2_R0p5pT20_index_->GetEntry(entry_);
    c_fastjets_AK4_R1p2_R0p5pT20_index_ = true;
  }
  return fastjets_AK4_R1p2_R0p5pT20_index_;
}

std::vector<int>* const & cfa_13::fastjets_AK4_R1p2_R0p5pT20_nconstituents() const{
  if(!c_fastjets_AK4_R1p2_R0p5pT20_nconstituents_ && b_fastjets_AK4_R1p2_R0p5pT20_nconstituents_){
    b_fastjets_AK4_R1p2_R0p5pT20_nconstituents_->GetEntry(entry_);
    c_fastjets_AK4_R1p2_R0p5pT20_nconstituents_ = true;
  }
  return fastjets_AK4_R1p2_R0p5pT20_nconstituents_;
}

std::vector<float>* const & cfa_13::fastjets_AK4_R1p2_R0p5pT20_phi() const{
  if(!c_fastjets_AK4_R1p2_R0p5pT20_phi_ && b_fastjets_AK4_R1p2_R0p5pT20_phi_){
    b_fastjets_AK4_R1p2_R0p5pT20_phi_->GetEntry(entry_);
    c_fastjets_AK4_R1p2_R0p5pT20_phi_ = true;
  }
  return fastjets_AK4_R1p2_R0p5pT20_phi_;
}

std::vector<float>* const & cfa_13::fastjets_AK4_R1p2_R0p5pT20_px() const{
  if(!c_fastjets_AK4_R1p2_R0p5pT20_px_ && b_fastjets_AK4_R1p2_R0p5pT20_px_){
    b_fastjets_AK4_R1p2_R0p5pT20_px_->GetEntry(entry_);
    c_fastjets_AK4_R1p2_R0p5pT20_px_ = true;
  }
  return fastjets_AK4_R1p2_R0p5pT20_px_;
}

std::vector<float>* const & cfa_13::fastjets_AK4_R1p2_R0p5pT20_py() const{
  if(!c_fastjets_AK4_R1p2_R0p5pT20_py_ && b_fastjets_AK4_R1p2_R0p5pT20_py_){
    b_fastjets_AK4_R1p2_R0p5pT20_py_->GetEntry(entry_);
    c_fastjets_AK4_R1p2_R0p5pT20_py_ = true;
  }
  return fastjets_AK4_R1p2_R0p5pT20_py_;
}

std::vector<float>* const & cfa_13::fastjets_AK4_R1p2_R0p5pT20_pz() const{
  if(!c_fastjets_AK4_R1p2_R0p5pT20_pz_ && b_fastjets_AK4_R1p2_R0p5pT20_pz_){
    b_fastjets_AK4_R1p2_R0p5pT20_pz_->GetEntry(entry_);
    c_fastjets_AK4_R1p2_R0p5pT20_pz_ = true;
  }
  return fastjets_AK4_R1p2_R0p5pT20_pz_;
}

std::vector<float>* const & cfa_13::fastjets_AK4_R1p2_R0p5pT25_energy() const{
  if(!c_fastjets_AK4_R1p2_R0p5pT25_energy_ && b_fastjets_AK4_R1p2_R0p5pT25_energy_){
    b_fastjets_AK4_R1p2_R0p5pT25_energy_->GetEntry(entry_);
    c_fastjets_AK4_R1p2_R0p5pT25_energy_ = true;
  }
  return fastjets_AK4_R1p2_R0p5pT25_energy_;
}

std::vector<float>* const & cfa_13::fastjets_AK4_R1p2_R0p5pT25_eta() const{
  if(!c_fastjets_AK4_R1p2_R0p5pT25_eta_ && b_fastjets_AK4_R1p2_R0p5pT25_eta_){
    b_fastjets_AK4_R1p2_R0p5pT25_eta_->GetEntry(entry_);
    c_fastjets_AK4_R1p2_R0p5pT25_eta_ = true;
  }
  return fastjets_AK4_R1p2_R0p5pT25_eta_;
}

std::vector<std::vector<int> >* const & cfa_13::fastjets_AK4_R1p2_R0p5pT25_index() const{
  if(!c_fastjets_AK4_R1p2_R0p5pT25_index_ && b_fastjets_AK4_R1p2_R0p5pT25_index_){
    b_fastjets_AK4_R1p2_R0p5pT25_index_->GetEntry(entry_);
    c_fastjets_AK4_R1p2_R0p5pT25_index_ = true;
  }
  return fastjets_AK4_R1p2_R0p5pT25_index_;
}

std::vector<int>* const & cfa_13::fastjets_AK4_R1p2_R0p5pT25_nconstituents() const{
  if(!c_fastjets_AK4_R1p2_R0p5pT25_nconstituents_ && b_fastjets_AK4_R1p2_R0p5pT25_nconstituents_){
    b_fastjets_AK4_R1p2_R0p5pT25_nconstituents_->GetEntry(entry_);
    c_fastjets_AK4_R1p2_R0p5pT25_nconstituents_ = true;
  }
  return fastjets_AK4_R1p2_R0p5pT25_nconstituents_;
}

std::vector<float>* const & cfa_13::fastjets_AK4_R1p2_R0p5pT25_phi() const{
  if(!c_fastjets_AK4_R1p2_R0p5pT25_phi_ && b_fastjets_AK4_R1p2_R0p5pT25_phi_){
    b_fastjets_AK4_R1p2_R0p5pT25_phi_->GetEntry(entry_);
    c_fastjets_AK4_R1p2_R0p5pT25_phi_ = true;
  }
  return fastjets_AK4_R1p2_R0p5pT25_phi_;
}

std::vector<float>* const & cfa_13::fastjets_AK4_R1p2_R0p5pT25_px() const{
  if(!c_fastjets_AK4_R1p2_R0p5pT25_px_ && b_fastjets_AK4_R1p2_R0p5pT25_px_){
    b_fastjets_AK4_R1p2_R0p5pT25_px_->GetEntry(entry_);
    c_fastjets_AK4_R1p2_R0p5pT25_px_ = true;
  }
  return fastjets_AK4_R1p2_R0p5pT25_px_;
}

std::vector<float>* const & cfa_13::fastjets_AK4_R1p2_R0p5pT25_py() const{
  if(!c_fastjets_AK4_R1p2_R0p5pT25_py_ && b_fastjets_AK4_R1p2_R0p5pT25_py_){
    b_fastjets_AK4_R1p2_R0p5pT25_py_->GetEntry(entry_);
    c_fastjets_AK4_R1p2_R0p5pT25_py_ = true;
  }
  return fastjets_AK4_R1p2_R0p5pT25_py_;
}

std::vector<float>* const & cfa_13::fastjets_AK4_R1p2_R0p5pT25_pz() const{
  if(!c_fastjets_AK4_R1p2_R0p5pT25_pz_ && b_fastjets_AK4_R1p2_R0p5pT25_pz_){
    b_fastjets_AK4_R1p2_R0p5pT25_pz_->GetEntry(entry_);
    c_fastjets_AK4_R1p2_R0p5pT25_pz_ = true;
  }
  return fastjets_AK4_R1p2_R0p5pT25_pz_;
}

std::vector<float>* const & cfa_13::fastjets_AK4_R1p2_R0p5pT30_energy() const{
  if(!c_fastjets_AK4_R1p2_R0p5pT30_energy_ && b_fastjets_AK4_R1p2_R0p5pT30_energy_){
    b_fastjets_AK4_R1p2_R0p5pT30_energy_->GetEntry(entry_);
    c_fastjets_AK4_R1p2_R0p5pT30_energy_ = true;
  }
  return fastjets_AK4_R1p2_R0p5pT30_energy_;
}

std::vector<float>* const & cfa_13::fastjets_AK4_R1p2_R0p5pT30_eta() const{
  if(!c_fastjets_AK4_R1p2_R0p5pT30_eta_ && b_fastjets_AK4_R1p2_R0p5pT30_eta_){
    b_fastjets_AK4_R1p2_R0p5pT30_eta_->GetEntry(entry_);
    c_fastjets_AK4_R1p2_R0p5pT30_eta_ = true;
  }
  return fastjets_AK4_R1p2_R0p5pT30_eta_;
}

std::vector<std::vector<int> >* const & cfa_13::fastjets_AK4_R1p2_R0p5pT30_index() const{
  if(!c_fastjets_AK4_R1p2_R0p5pT30_index_ && b_fastjets_AK4_R1p2_R0p5pT30_index_){
    b_fastjets_AK4_R1p2_R0p5pT30_index_->GetEntry(entry_);
    c_fastjets_AK4_R1p2_R0p5pT30_index_ = true;
  }
  return fastjets_AK4_R1p2_R0p5pT30_index_;
}

std::vector<int>* const & cfa_13::fastjets_AK4_R1p2_R0p5pT30_nconstituents() const{
  if(!c_fastjets_AK4_R1p2_R0p5pT30_nconstituents_ && b_fastjets_AK4_R1p2_R0p5pT30_nconstituents_){
    b_fastjets_AK4_R1p2_R0p5pT30_nconstituents_->GetEntry(entry_);
    c_fastjets_AK4_R1p2_R0p5pT30_nconstituents_ = true;
  }
  return fastjets_AK4_R1p2_R0p5pT30_nconstituents_;
}

std::vector<float>* const & cfa_13::fastjets_AK4_R1p2_R0p5pT30_phi() const{
  if(!c_fastjets_AK4_R1p2_R0p5pT30_phi_ && b_fastjets_AK4_R1p2_R0p5pT30_phi_){
    b_fastjets_AK4_R1p2_R0p5pT30_phi_->GetEntry(entry_);
    c_fastjets_AK4_R1p2_R0p5pT30_phi_ = true;
  }
  return fastjets_AK4_R1p2_R0p5pT30_phi_;
}

std::vector<float>* const & cfa_13::fastjets_AK4_R1p2_R0p5pT30_px() const{
  if(!c_fastjets_AK4_R1p2_R0p5pT30_px_ && b_fastjets_AK4_R1p2_R0p5pT30_px_){
    b_fastjets_AK4_R1p2_R0p5pT30_px_->GetEntry(entry_);
    c_fastjets_AK4_R1p2_R0p5pT30_px_ = true;
  }
  return fastjets_AK4_R1p2_R0p5pT30_px_;
}

std::vector<float>* const & cfa_13::fastjets_AK4_R1p2_R0p5pT30_py() const{
  if(!c_fastjets_AK4_R1p2_R0p5pT30_py_ && b_fastjets_AK4_R1p2_R0p5pT30_py_){
    b_fastjets_AK4_R1p2_R0p5pT30_py_->GetEntry(entry_);
    c_fastjets_AK4_R1p2_R0p5pT30_py_ = true;
  }
  return fastjets_AK4_R1p2_R0p5pT30_py_;
}

std::vector<float>* const & cfa_13::fastjets_AK4_R1p2_R0p5pT30_pz() const{
  if(!c_fastjets_AK4_R1p2_R0p5pT30_pz_ && b_fastjets_AK4_R1p2_R0p5pT30_pz_){
    b_fastjets_AK4_R1p2_R0p5pT30_pz_->GetEntry(entry_);
    c_fastjets_AK4_R1p2_R0p5pT30_pz_ = true;
  }
  return fastjets_AK4_R1p2_R0p5pT30_pz_;
}

Int_t const & cfa_13::goodVerticesfilter_decision() const{
  if(!c_goodVerticesfilter_decision_ && b_goodVerticesfilter_decision_){
    b_goodVerticesfilter_decision_->GetEntry(entry_);
    c_goodVerticesfilter_decision_ = true;
  }
  return goodVerticesfilter_decision_;
}

std::vector<float>* const & cfa_13::jets_AK4_area() const{
  if(!c_jets_AK4_area_ && b_jets_AK4_area_){
    b_jets_AK4_area_->GetEntry(entry_);
    c_jets_AK4_area_ = true;
  }
  return jets_AK4_area_;
}

std::vector<float>* const & cfa_13::jets_AK4_btag_TC_highEff() const{
  if(!c_jets_AK4_btag_TC_highEff_ && b_jets_AK4_btag_TC_highEff_){
    b_jets_AK4_btag_TC_highEff_->GetEntry(entry_);
    c_jets_AK4_btag_TC_highEff_ = true;
  }
  return jets_AK4_btag_TC_highEff_;
}

std::vector<float>* const & cfa_13::jets_AK4_btag_TC_highPur() const{
  if(!c_jets_AK4_btag_TC_highPur_ && b_jets_AK4_btag_TC_highPur_){
    b_jets_AK4_btag_TC_highPur_->GetEntry(entry_);
    c_jets_AK4_btag_TC_highPur_ = true;
  }
  return jets_AK4_btag_TC_highPur_;
}

std::vector<float>* const & cfa_13::jets_AK4_btag_jetBProb() const{
  if(!c_jets_AK4_btag_jetBProb_ && b_jets_AK4_btag_jetBProb_){
    b_jets_AK4_btag_jetBProb_->GetEntry(entry_);
    c_jets_AK4_btag_jetBProb_ = true;
  }
  return jets_AK4_btag_jetBProb_;
}

std::vector<float>* const & cfa_13::jets_AK4_btag_jetProb() const{
  if(!c_jets_AK4_btag_jetProb_ && b_jets_AK4_btag_jetProb_){
    b_jets_AK4_btag_jetProb_->GetEntry(entry_);
    c_jets_AK4_btag_jetProb_ = true;
  }
  return jets_AK4_btag_jetProb_;
}

std::vector<float>* const & cfa_13::jets_AK4_btag_secVertexCombined() const{
  if(!c_jets_AK4_btag_secVertexCombined_ && b_jets_AK4_btag_secVertexCombined_){
    b_jets_AK4_btag_secVertexCombined_->GetEntry(entry_);
    c_jets_AK4_btag_secVertexCombined_ = true;
  }
  return jets_AK4_btag_secVertexCombined_;
}

std::vector<float>* const & cfa_13::jets_AK4_btag_secVertexHighEff() const{
  if(!c_jets_AK4_btag_secVertexHighEff_ && b_jets_AK4_btag_secVertexHighEff_){
    b_jets_AK4_btag_secVertexHighEff_->GetEntry(entry_);
    c_jets_AK4_btag_secVertexHighEff_ = true;
  }
  return jets_AK4_btag_secVertexHighEff_;
}

std::vector<float>* const & cfa_13::jets_AK4_btag_secVertexHighPur() const{
  if(!c_jets_AK4_btag_secVertexHighPur_ && b_jets_AK4_btag_secVertexHighPur_){
    b_jets_AK4_btag_secVertexHighPur_->GetEntry(entry_);
    c_jets_AK4_btag_secVertexHighPur_ = true;
  }
  return jets_AK4_btag_secVertexHighPur_;
}

std::vector<float>* const & cfa_13::jets_AK4_btag_softEle() const{
  if(!c_jets_AK4_btag_softEle_ && b_jets_AK4_btag_softEle_){
    b_jets_AK4_btag_softEle_->GetEntry(entry_);
    c_jets_AK4_btag_softEle_ = true;
  }
  return jets_AK4_btag_softEle_;
}

std::vector<float>* const & cfa_13::jets_AK4_btag_softMuon() const{
  if(!c_jets_AK4_btag_softMuon_ && b_jets_AK4_btag_softMuon_){
    b_jets_AK4_btag_softMuon_->GetEntry(entry_);
    c_jets_AK4_btag_softMuon_ = true;
  }
  return jets_AK4_btag_softMuon_;
}

std::vector<float>* const & cfa_13::jets_AK4_chgEmE() const{
  if(!c_jets_AK4_chgEmE_ && b_jets_AK4_chgEmE_){
    b_jets_AK4_chgEmE_->GetEntry(entry_);
    c_jets_AK4_chgEmE_ = true;
  }
  return jets_AK4_chgEmE_;
}

std::vector<float>* const & cfa_13::jets_AK4_chgHadE() const{
  if(!c_jets_AK4_chgHadE_ && b_jets_AK4_chgHadE_){
    b_jets_AK4_chgHadE_->GetEntry(entry_);
    c_jets_AK4_chgHadE_ = true;
  }
  return jets_AK4_chgHadE_;
}

std::vector<float>* const & cfa_13::jets_AK4_chgMuE() const{
  if(!c_jets_AK4_chgMuE_ && b_jets_AK4_chgMuE_){
    b_jets_AK4_chgMuE_->GetEntry(entry_);
    c_jets_AK4_chgMuE_ = true;
  }
  return jets_AK4_chgMuE_;
}

std::vector<float>* const & cfa_13::jets_AK4_chg_Mult() const{
  if(!c_jets_AK4_chg_Mult_ && b_jets_AK4_chg_Mult_){
    b_jets_AK4_chg_Mult_->GetEntry(entry_);
    c_jets_AK4_chg_Mult_ = true;
  }
  return jets_AK4_chg_Mult_;
}

std::vector<float>* const & cfa_13::jets_AK4_corrFactorRaw() const{
  if(!c_jets_AK4_corrFactorRaw_ && b_jets_AK4_corrFactorRaw_){
    b_jets_AK4_corrFactorRaw_->GetEntry(entry_);
    c_jets_AK4_corrFactorRaw_ = true;
  }
  return jets_AK4_corrFactorRaw_;
}

std::vector<float>* const & cfa_13::jets_AK4_ehf() const{
  if(!c_jets_AK4_ehf_ && b_jets_AK4_ehf_){
    b_jets_AK4_ehf_->GetEntry(entry_);
    c_jets_AK4_ehf_ = true;
  }
  return jets_AK4_ehf_;
}

std::vector<int>* const & cfa_13::jets_AK4_el_ind() const{
  if(!c_jets_AK4_el_ind_ && b_jets_AK4_el_ind_){
    b_jets_AK4_el_ind_->GetEntry(entry_);
    c_jets_AK4_el_ind_ = true;
  }
  return jets_AK4_el_ind_;
}

std::vector<float>* const & cfa_13::jets_AK4_emf() const{
  if(!c_jets_AK4_emf_ && b_jets_AK4_emf_){
    b_jets_AK4_emf_->GetEntry(entry_);
    c_jets_AK4_emf_ = true;
  }
  return jets_AK4_emf_;
}

std::vector<float>* const & cfa_13::jets_AK4_energy() const{
  if(!c_jets_AK4_energy_ && b_jets_AK4_energy_){
    b_jets_AK4_energy_->GetEntry(entry_);
    c_jets_AK4_energy_ = true;
  }
  return jets_AK4_energy_;
}

std::vector<float>* const & cfa_13::jets_AK4_et() const{
  if(!c_jets_AK4_et_ && b_jets_AK4_et_){
    b_jets_AK4_et_->GetEntry(entry_);
    c_jets_AK4_et_ = true;
  }
  return jets_AK4_et_;
}

std::vector<float>* const & cfa_13::jets_AK4_eta() const{
  if(!c_jets_AK4_eta_ && b_jets_AK4_eta_){
    b_jets_AK4_eta_->GetEntry(entry_);
    c_jets_AK4_eta_ = true;
  }
  return jets_AK4_eta_;
}

std::vector<float>* const & cfa_13::jets_AK4_etaetaMoment() const{
  if(!c_jets_AK4_etaetaMoment_ && b_jets_AK4_etaetaMoment_){
    b_jets_AK4_etaetaMoment_->GetEntry(entry_);
    c_jets_AK4_etaetaMoment_ = true;
  }
  return jets_AK4_etaetaMoment_;
}

std::vector<float>* const & cfa_13::jets_AK4_etaphiMoment() const{
  if(!c_jets_AK4_etaphiMoment_ && b_jets_AK4_etaphiMoment_){
    b_jets_AK4_etaphiMoment_->GetEntry(entry_);
    c_jets_AK4_etaphiMoment_ = true;
  }
  return jets_AK4_etaphiMoment_;
}

std::vector<float>* const & cfa_13::jets_AK4_fHPD() const{
  if(!c_jets_AK4_fHPD_ && b_jets_AK4_fHPD_){
    b_jets_AK4_fHPD_->GetEntry(entry_);
    c_jets_AK4_fHPD_ = true;
  }
  return jets_AK4_fHPD_;
}

std::vector<float>* const & cfa_13::jets_AK4_fRBX() const{
  if(!c_jets_AK4_fRBX_ && b_jets_AK4_fRBX_){
    b_jets_AK4_fRBX_->GetEntry(entry_);
    c_jets_AK4_fRBX_ = true;
  }
  return jets_AK4_fRBX_;
}

std::vector<float>* const & cfa_13::jets_AK4_fSubDetector1() const{
  if(!c_jets_AK4_fSubDetector1_ && b_jets_AK4_fSubDetector1_){
    b_jets_AK4_fSubDetector1_->GetEntry(entry_);
    c_jets_AK4_fSubDetector1_ = true;
  }
  return jets_AK4_fSubDetector1_;
}

std::vector<float>* const & cfa_13::jets_AK4_fSubDetector2() const{
  if(!c_jets_AK4_fSubDetector2_ && b_jets_AK4_fSubDetector2_){
    b_jets_AK4_fSubDetector2_->GetEntry(entry_);
    c_jets_AK4_fSubDetector2_ = true;
  }
  return jets_AK4_fSubDetector2_;
}

std::vector<float>* const & cfa_13::jets_AK4_fSubDetector3() const{
  if(!c_jets_AK4_fSubDetector3_ && b_jets_AK4_fSubDetector3_){
    b_jets_AK4_fSubDetector3_->GetEntry(entry_);
    c_jets_AK4_fSubDetector3_ = true;
  }
  return jets_AK4_fSubDetector3_;
}

std::vector<float>* const & cfa_13::jets_AK4_fSubDetector4() const{
  if(!c_jets_AK4_fSubDetector4_ && b_jets_AK4_fSubDetector4_){
    b_jets_AK4_fSubDetector4_->GetEntry(entry_);
    c_jets_AK4_fSubDetector4_ = true;
  }
  return jets_AK4_fSubDetector4_;
}

std::vector<float>* const & cfa_13::jets_AK4_gen_Energy() const{
  if(!c_jets_AK4_gen_Energy_ && b_jets_AK4_gen_Energy_){
    b_jets_AK4_gen_Energy_->GetEntry(entry_);
    c_jets_AK4_gen_Energy_ = true;
  }
  return jets_AK4_gen_Energy_;
}

std::vector<float>* const & cfa_13::jets_AK4_gen_Id() const{
  if(!c_jets_AK4_gen_Id_ && b_jets_AK4_gen_Id_){
    b_jets_AK4_gen_Id_->GetEntry(entry_);
    c_jets_AK4_gen_Id_ = true;
  }
  return jets_AK4_gen_Id_;
}

std::vector<float>* const & cfa_13::jets_AK4_gen_et() const{
  if(!c_jets_AK4_gen_et_ && b_jets_AK4_gen_et_){
    b_jets_AK4_gen_et_->GetEntry(entry_);
    c_jets_AK4_gen_et_ = true;
  }
  return jets_AK4_gen_et_;
}

std::vector<float>* const & cfa_13::jets_AK4_gen_eta() const{
  if(!c_jets_AK4_gen_eta_ && b_jets_AK4_gen_eta_){
    b_jets_AK4_gen_eta_->GetEntry(entry_);
    c_jets_AK4_gen_eta_ = true;
  }
  return jets_AK4_gen_eta_;
}

std::vector<float>* const & cfa_13::jets_AK4_gen_mass() const{
  if(!c_jets_AK4_gen_mass_ && b_jets_AK4_gen_mass_){
    b_jets_AK4_gen_mass_->GetEntry(entry_);
    c_jets_AK4_gen_mass_ = true;
  }
  return jets_AK4_gen_mass_;
}

std::vector<float>* const & cfa_13::jets_AK4_gen_motherID() const{
  if(!c_jets_AK4_gen_motherID_ && b_jets_AK4_gen_motherID_){
    b_jets_AK4_gen_motherID_->GetEntry(entry_);
    c_jets_AK4_gen_motherID_ = true;
  }
  return jets_AK4_gen_motherID_;
}

std::vector<float>* const & cfa_13::jets_AK4_gen_phi() const{
  if(!c_jets_AK4_gen_phi_ && b_jets_AK4_gen_phi_){
    b_jets_AK4_gen_phi_->GetEntry(entry_);
    c_jets_AK4_gen_phi_ = true;
  }
  return jets_AK4_gen_phi_;
}

std::vector<float>* const & cfa_13::jets_AK4_gen_pt() const{
  if(!c_jets_AK4_gen_pt_ && b_jets_AK4_gen_pt_){
    b_jets_AK4_gen_pt_->GetEntry(entry_);
    c_jets_AK4_gen_pt_ = true;
  }
  return jets_AK4_gen_pt_;
}

std::vector<float>* const & cfa_13::jets_AK4_gen_threeCharge() const{
  if(!c_jets_AK4_gen_threeCharge_ && b_jets_AK4_gen_threeCharge_){
    b_jets_AK4_gen_threeCharge_->GetEntry(entry_);
    c_jets_AK4_gen_threeCharge_ = true;
  }
  return jets_AK4_gen_threeCharge_;
}

std::vector<float>* const & cfa_13::jets_AK4_hitsInN90() const{
  if(!c_jets_AK4_hitsInN90_ && b_jets_AK4_hitsInN90_){
    b_jets_AK4_hitsInN90_->GetEntry(entry_);
    c_jets_AK4_hitsInN90_ = true;
  }
  return jets_AK4_hitsInN90_;
}

std::vector<float>* const & cfa_13::jets_AK4_jetCharge() const{
  if(!c_jets_AK4_jetCharge_ && b_jets_AK4_jetCharge_){
    b_jets_AK4_jetCharge_->GetEntry(entry_);
    c_jets_AK4_jetCharge_ = true;
  }
  return jets_AK4_jetCharge_;
}

std::vector<float>* const & cfa_13::jets_AK4_mass() const{
  if(!c_jets_AK4_mass_ && b_jets_AK4_mass_){
    b_jets_AK4_mass_->GetEntry(entry_);
    c_jets_AK4_mass_ = true;
  }
  return jets_AK4_mass_;
}

std::vector<int>* const & cfa_13::jets_AK4_maxpt_id() const{
  if(!c_jets_AK4_maxpt_id_ && b_jets_AK4_maxpt_id_){
    b_jets_AK4_maxpt_id_->GetEntry(entry_);
    c_jets_AK4_maxpt_id_ = true;
  }
  return jets_AK4_maxpt_id_;
}

std::vector<float>* const & cfa_13::jets_AK4_mu_Mult() const{
  if(!c_jets_AK4_mu_Mult_ && b_jets_AK4_mu_Mult_){
    b_jets_AK4_mu_Mult_->GetEntry(entry_);
    c_jets_AK4_mu_Mult_ = true;
  }
  return jets_AK4_mu_Mult_;
}

std::vector<int>* const & cfa_13::jets_AK4_mu_ind() const{
  if(!c_jets_AK4_mu_ind_ && b_jets_AK4_mu_ind_){
    b_jets_AK4_mu_ind_->GetEntry(entry_);
    c_jets_AK4_mu_ind_ = true;
  }
  return jets_AK4_mu_ind_;
}

std::vector<float>* const & cfa_13::jets_AK4_n60() const{
  if(!c_jets_AK4_n60_ && b_jets_AK4_n60_){
    b_jets_AK4_n60_->GetEntry(entry_);
    c_jets_AK4_n60_ = true;
  }
  return jets_AK4_n60_;
}

std::vector<float>* const & cfa_13::jets_AK4_n90() const{
  if(!c_jets_AK4_n90_ && b_jets_AK4_n90_){
    b_jets_AK4_n90_->GetEntry(entry_);
    c_jets_AK4_n90_ = true;
  }
  return jets_AK4_n90_;
}

std::vector<float>* const & cfa_13::jets_AK4_n90Hits() const{
  if(!c_jets_AK4_n90Hits_ && b_jets_AK4_n90Hits_){
    b_jets_AK4_n90Hits_->GetEntry(entry_);
    c_jets_AK4_n90Hits_ = true;
  }
  return jets_AK4_n90Hits_;
}

std::vector<float>* const & cfa_13::jets_AK4_nECALTowers() const{
  if(!c_jets_AK4_nECALTowers_ && b_jets_AK4_nECALTowers_){
    b_jets_AK4_nECALTowers_->GetEntry(entry_);
    c_jets_AK4_nECALTowers_ = true;
  }
  return jets_AK4_nECALTowers_;
}

std::vector<float>* const & cfa_13::jets_AK4_nHCALTowers() const{
  if(!c_jets_AK4_nHCALTowers_ && b_jets_AK4_nHCALTowers_){
    b_jets_AK4_nHCALTowers_->GetEntry(entry_);
    c_jets_AK4_nHCALTowers_ = true;
  }
  return jets_AK4_nHCALTowers_;
}

std::vector<float>* const & cfa_13::jets_AK4_neutralEmE() const{
  if(!c_jets_AK4_neutralEmE_ && b_jets_AK4_neutralEmE_){
    b_jets_AK4_neutralEmE_->GetEntry(entry_);
    c_jets_AK4_neutralEmE_ = true;
  }
  return jets_AK4_neutralEmE_;
}

std::vector<float>* const & cfa_13::jets_AK4_neutralHadE() const{
  if(!c_jets_AK4_neutralHadE_ && b_jets_AK4_neutralHadE_){
    b_jets_AK4_neutralHadE_->GetEntry(entry_);
    c_jets_AK4_neutralHadE_ = true;
  }
  return jets_AK4_neutralHadE_;
}

std::vector<float>* const & cfa_13::jets_AK4_neutral_Mult() const{
  if(!c_jets_AK4_neutral_Mult_ && b_jets_AK4_neutral_Mult_){
    b_jets_AK4_neutral_Mult_->GetEntry(entry_);
    c_jets_AK4_neutral_Mult_ = true;
  }
  return jets_AK4_neutral_Mult_;
}

std::vector<float>* const & cfa_13::jets_AK4_partonFlavour() const{
  if(!c_jets_AK4_partonFlavour_ && b_jets_AK4_partonFlavour_){
    b_jets_AK4_partonFlavour_->GetEntry(entry_);
    c_jets_AK4_partonFlavour_ = true;
  }
  return jets_AK4_partonFlavour_;
}

std::vector<float>* const & cfa_13::jets_AK4_parton_Energy() const{
  if(!c_jets_AK4_parton_Energy_ && b_jets_AK4_parton_Energy_){
    b_jets_AK4_parton_Energy_->GetEntry(entry_);
    c_jets_AK4_parton_Energy_ = true;
  }
  return jets_AK4_parton_Energy_;
}

std::vector<float>* const & cfa_13::jets_AK4_parton_Id() const{
  if(!c_jets_AK4_parton_Id_ && b_jets_AK4_parton_Id_){
    b_jets_AK4_parton_Id_->GetEntry(entry_);
    c_jets_AK4_parton_Id_ = true;
  }
  return jets_AK4_parton_Id_;
}

std::vector<float>* const & cfa_13::jets_AK4_parton_eta() const{
  if(!c_jets_AK4_parton_eta_ && b_jets_AK4_parton_eta_){
    b_jets_AK4_parton_eta_->GetEntry(entry_);
    c_jets_AK4_parton_eta_ = true;
  }
  return jets_AK4_parton_eta_;
}

std::vector<float>* const & cfa_13::jets_AK4_parton_mass() const{
  if(!c_jets_AK4_parton_mass_ && b_jets_AK4_parton_mass_){
    b_jets_AK4_parton_mass_->GetEntry(entry_);
    c_jets_AK4_parton_mass_ = true;
  }
  return jets_AK4_parton_mass_;
}

std::vector<float>* const & cfa_13::jets_AK4_parton_motherId() const{
  if(!c_jets_AK4_parton_motherId_ && b_jets_AK4_parton_motherId_){
    b_jets_AK4_parton_motherId_->GetEntry(entry_);
    c_jets_AK4_parton_motherId_ = true;
  }
  return jets_AK4_parton_motherId_;
}

std::vector<float>* const & cfa_13::jets_AK4_parton_phi() const{
  if(!c_jets_AK4_parton_phi_ && b_jets_AK4_parton_phi_){
    b_jets_AK4_parton_phi_->GetEntry(entry_);
    c_jets_AK4_parton_phi_ = true;
  }
  return jets_AK4_parton_phi_;
}

std::vector<float>* const & cfa_13::jets_AK4_parton_pt() const{
  if(!c_jets_AK4_parton_pt_ && b_jets_AK4_parton_pt_){
    b_jets_AK4_parton_pt_->GetEntry(entry_);
    c_jets_AK4_parton_pt_ = true;
  }
  return jets_AK4_parton_pt_;
}

std::vector<float>* const & cfa_13::jets_AK4_phi() const{
  if(!c_jets_AK4_phi_ && b_jets_AK4_phi_){
    b_jets_AK4_phi_->GetEntry(entry_);
    c_jets_AK4_phi_ = true;
  }
  return jets_AK4_phi_;
}

std::vector<float>* const & cfa_13::jets_AK4_phiphiMoment() const{
  if(!c_jets_AK4_phiphiMoment_ && b_jets_AK4_phiphiMoment_){
    b_jets_AK4_phiphiMoment_->GetEntry(entry_);
    c_jets_AK4_phiphiMoment_ = true;
  }
  return jets_AK4_phiphiMoment_;
}

std::vector<float>* const & cfa_13::jets_AK4_photonEnergy() const{
  if(!c_jets_AK4_photonEnergy_ && b_jets_AK4_photonEnergy_){
    b_jets_AK4_photonEnergy_->GetEntry(entry_);
    c_jets_AK4_photonEnergy_ = true;
  }
  return jets_AK4_photonEnergy_;
}

std::vector<float>* const & cfa_13::jets_AK4_pt() const{
  if(!c_jets_AK4_pt_ && b_jets_AK4_pt_){
    b_jets_AK4_pt_->GetEntry(entry_);
    c_jets_AK4_pt_ = true;
  }
  return jets_AK4_pt_;
}

std::vector<float>* const & cfa_13::jets_AK4_px() const{
  if(!c_jets_AK4_px_ && b_jets_AK4_px_){
    b_jets_AK4_px_->GetEntry(entry_);
    c_jets_AK4_px_ = true;
  }
  return jets_AK4_px_;
}

std::vector<float>* const & cfa_13::jets_AK4_py() const{
  if(!c_jets_AK4_py_ && b_jets_AK4_py_){
    b_jets_AK4_py_->GetEntry(entry_);
    c_jets_AK4_py_ = true;
  }
  return jets_AK4_py_;
}

std::vector<float>* const & cfa_13::jets_AK4_pz() const{
  if(!c_jets_AK4_pz_ && b_jets_AK4_pz_){
    b_jets_AK4_pz_->GetEntry(entry_);
    c_jets_AK4_pz_ = true;
  }
  return jets_AK4_pz_;
}

std::vector<float>* const & cfa_13::jets_AK4_rawPt() const{
  if(!c_jets_AK4_rawPt_ && b_jets_AK4_rawPt_){
    b_jets_AK4_rawPt_->GetEntry(entry_);
    c_jets_AK4_rawPt_ = true;
  }
  return jets_AK4_rawPt_;
}

std::vector<float>* const & cfa_13::jets_AK4_status() const{
  if(!c_jets_AK4_status_ && b_jets_AK4_status_){
    b_jets_AK4_status_->GetEntry(entry_);
    c_jets_AK4_status_ = true;
  }
  return jets_AK4_status_;
}

std::vector<float>* const & cfa_13::jets_AK4_theta() const{
  if(!c_jets_AK4_theta_ && b_jets_AK4_theta_){
    b_jets_AK4_theta_->GetEntry(entry_);
    c_jets_AK4_theta_ = true;
  }
  return jets_AK4_theta_;
}

std::vector<float>* const & cfa_13::mc_final_charge() const{
  if(!c_mc_final_charge_ && b_mc_final_charge_){
    b_mc_final_charge_->GetEntry(entry_);
    c_mc_final_charge_ = true;
  }
  return mc_final_charge_;
}

std::vector<float>* const & cfa_13::mc_final_energy() const{
  if(!c_mc_final_energy_ && b_mc_final_energy_){
    b_mc_final_energy_->GetEntry(entry_);
    c_mc_final_energy_ = true;
  }
  return mc_final_energy_;
}

std::vector<float>* const & cfa_13::mc_final_eta() const{
  if(!c_mc_final_eta_ && b_mc_final_eta_){
    b_mc_final_eta_->GetEntry(entry_);
    c_mc_final_eta_ = true;
  }
  return mc_final_eta_;
}

std::vector<float>* const & cfa_13::mc_final_ggrandmother_id() const{
  if(!c_mc_final_ggrandmother_id_ && b_mc_final_ggrandmother_id_){
    b_mc_final_ggrandmother_id_->GetEntry(entry_);
    c_mc_final_ggrandmother_id_ = true;
  }
  return mc_final_ggrandmother_id_;
}

std::vector<float>* const & cfa_13::mc_final_grandmother_id() const{
  if(!c_mc_final_grandmother_id_ && b_mc_final_grandmother_id_){
    b_mc_final_grandmother_id_->GetEntry(entry_);
    c_mc_final_grandmother_id_ = true;
  }
  return mc_final_grandmother_id_;
}

std::vector<float>* const & cfa_13::mc_final_id() const{
  if(!c_mc_final_id_ && b_mc_final_id_){
    b_mc_final_id_->GetEntry(entry_);
    c_mc_final_id_ = true;
  }
  return mc_final_id_;
}

std::vector<float>* const & cfa_13::mc_final_mass() const{
  if(!c_mc_final_mass_ && b_mc_final_mass_){
    b_mc_final_mass_->GetEntry(entry_);
    c_mc_final_mass_ = true;
  }
  return mc_final_mass_;
}

std::vector<float>* const & cfa_13::mc_final_mother_id() const{
  if(!c_mc_final_mother_id_ && b_mc_final_mother_id_){
    b_mc_final_mother_id_->GetEntry(entry_);
    c_mc_final_mother_id_ = true;
  }
  return mc_final_mother_id_;
}

std::vector<float>* const & cfa_13::mc_final_mother_pt() const{
  if(!c_mc_final_mother_pt_ && b_mc_final_mother_pt_){
    b_mc_final_mother_pt_->GetEntry(entry_);
    c_mc_final_mother_pt_ = true;
  }
  return mc_final_mother_pt_;
}

std::vector<float>* const & cfa_13::mc_final_numOfDaughters() const{
  if(!c_mc_final_numOfDaughters_ && b_mc_final_numOfDaughters_){
    b_mc_final_numOfDaughters_->GetEntry(entry_);
    c_mc_final_numOfDaughters_ = true;
  }
  return mc_final_numOfDaughters_;
}

std::vector<float>* const & cfa_13::mc_final_numOfMothers() const{
  if(!c_mc_final_numOfMothers_ && b_mc_final_numOfMothers_){
    b_mc_final_numOfMothers_->GetEntry(entry_);
    c_mc_final_numOfMothers_ = true;
  }
  return mc_final_numOfMothers_;
}

std::vector<float>* const & cfa_13::mc_final_phi() const{
  if(!c_mc_final_phi_ && b_mc_final_phi_){
    b_mc_final_phi_->GetEntry(entry_);
    c_mc_final_phi_ = true;
  }
  return mc_final_phi_;
}

std::vector<float>* const & cfa_13::mc_final_pt() const{
  if(!c_mc_final_pt_ && b_mc_final_pt_){
    b_mc_final_pt_->GetEntry(entry_);
    c_mc_final_pt_ = true;
  }
  return mc_final_pt_;
}

std::vector<float>* const & cfa_13::mc_final_px() const{
  if(!c_mc_final_px_ && b_mc_final_px_){
    b_mc_final_px_->GetEntry(entry_);
    c_mc_final_px_ = true;
  }
  return mc_final_px_;
}

std::vector<float>* const & cfa_13::mc_final_py() const{
  if(!c_mc_final_py_ && b_mc_final_py_){
    b_mc_final_py_->GetEntry(entry_);
    c_mc_final_py_ = true;
  }
  return mc_final_py_;
}

std::vector<float>* const & cfa_13::mc_final_pz() const{
  if(!c_mc_final_pz_ && b_mc_final_pz_){
    b_mc_final_pz_->GetEntry(entry_);
    c_mc_final_pz_ = true;
  }
  return mc_final_pz_;
}

std::vector<float>* const & cfa_13::mc_final_status() const{
  if(!c_mc_final_status_ && b_mc_final_status_){
    b_mc_final_status_->GetEntry(entry_);
    c_mc_final_status_ = true;
  }
  return mc_final_status_;
}

std::vector<float>* const & cfa_13::mc_final_theta() const{
  if(!c_mc_final_theta_ && b_mc_final_theta_){
    b_mc_final_theta_->GetEntry(entry_);
    c_mc_final_theta_ = true;
  }
  return mc_final_theta_;
}

std::vector<float>* const & cfa_13::mc_final_vertex_x() const{
  if(!c_mc_final_vertex_x_ && b_mc_final_vertex_x_){
    b_mc_final_vertex_x_->GetEntry(entry_);
    c_mc_final_vertex_x_ = true;
  }
  return mc_final_vertex_x_;
}

std::vector<float>* const & cfa_13::mc_final_vertex_y() const{
  if(!c_mc_final_vertex_y_ && b_mc_final_vertex_y_){
    b_mc_final_vertex_y_->GetEntry(entry_);
    c_mc_final_vertex_y_ = true;
  }
  return mc_final_vertex_y_;
}

std::vector<float>* const & cfa_13::mc_final_vertex_z() const{
  if(!c_mc_final_vertex_z_ && b_mc_final_vertex_z_){
    b_mc_final_vertex_z_->GetEntry(entry_);
    c_mc_final_vertex_z_ = true;
  }
  return mc_final_vertex_z_;
}

std::vector<float>* const & cfa_13::mc_jets_auxiliaryEnergy() const{
  if(!c_mc_jets_auxiliaryEnergy_ && b_mc_jets_auxiliaryEnergy_){
    b_mc_jets_auxiliaryEnergy_->GetEntry(entry_);
    c_mc_jets_auxiliaryEnergy_ = true;
  }
  return mc_jets_auxiliaryEnergy_;
}

std::vector<float>* const & cfa_13::mc_jets_emEnergy() const{
  if(!c_mc_jets_emEnergy_ && b_mc_jets_emEnergy_){
    b_mc_jets_emEnergy_->GetEntry(entry_);
    c_mc_jets_emEnergy_ = true;
  }
  return mc_jets_emEnergy_;
}

std::vector<float>* const & cfa_13::mc_jets_energy() const{
  if(!c_mc_jets_energy_ && b_mc_jets_energy_){
    b_mc_jets_energy_->GetEntry(entry_);
    c_mc_jets_energy_ = true;
  }
  return mc_jets_energy_;
}

std::vector<float>* const & cfa_13::mc_jets_et() const{
  if(!c_mc_jets_et_ && b_mc_jets_et_){
    b_mc_jets_et_->GetEntry(entry_);
    c_mc_jets_et_ = true;
  }
  return mc_jets_et_;
}

std::vector<float>* const & cfa_13::mc_jets_eta() const{
  if(!c_mc_jets_eta_ && b_mc_jets_eta_){
    b_mc_jets_eta_->GetEntry(entry_);
    c_mc_jets_eta_ = true;
  }
  return mc_jets_eta_;
}

std::vector<float>* const & cfa_13::mc_jets_etaetaMoment() const{
  if(!c_mc_jets_etaetaMoment_ && b_mc_jets_etaetaMoment_){
    b_mc_jets_etaetaMoment_->GetEntry(entry_);
    c_mc_jets_etaetaMoment_ = true;
  }
  return mc_jets_etaetaMoment_;
}

std::vector<float>* const & cfa_13::mc_jets_etaphiMoment() const{
  if(!c_mc_jets_etaphiMoment_ && b_mc_jets_etaphiMoment_){
    b_mc_jets_etaphiMoment_->GetEntry(entry_);
    c_mc_jets_etaphiMoment_ = true;
  }
  return mc_jets_etaphiMoment_;
}

std::vector<float>* const & cfa_13::mc_jets_hadEnergy() const{
  if(!c_mc_jets_hadEnergy_ && b_mc_jets_hadEnergy_){
    b_mc_jets_hadEnergy_->GetEntry(entry_);
    c_mc_jets_hadEnergy_ = true;
  }
  return mc_jets_hadEnergy_;
}

std::vector<float>* const & cfa_13::mc_jets_invisibleEnergy() const{
  if(!c_mc_jets_invisibleEnergy_ && b_mc_jets_invisibleEnergy_){
    b_mc_jets_invisibleEnergy_->GetEntry(entry_);
    c_mc_jets_invisibleEnergy_ = true;
  }
  return mc_jets_invisibleEnergy_;
}

std::vector<float>* const & cfa_13::mc_jets_mass() const{
  if(!c_mc_jets_mass_ && b_mc_jets_mass_){
    b_mc_jets_mass_->GetEntry(entry_);
    c_mc_jets_mass_ = true;
  }
  return mc_jets_mass_;
}

std::vector<float>* const & cfa_13::mc_jets_phi() const{
  if(!c_mc_jets_phi_ && b_mc_jets_phi_){
    b_mc_jets_phi_->GetEntry(entry_);
    c_mc_jets_phi_ = true;
  }
  return mc_jets_phi_;
}

std::vector<float>* const & cfa_13::mc_jets_phiphiMoment() const{
  if(!c_mc_jets_phiphiMoment_ && b_mc_jets_phiphiMoment_){
    b_mc_jets_phiphiMoment_->GetEntry(entry_);
    c_mc_jets_phiphiMoment_ = true;
  }
  return mc_jets_phiphiMoment_;
}

std::vector<float>* const & cfa_13::mc_jets_pt() const{
  if(!c_mc_jets_pt_ && b_mc_jets_pt_){
    b_mc_jets_pt_->GetEntry(entry_);
    c_mc_jets_pt_ = true;
  }
  return mc_jets_pt_;
}

std::vector<float>* const & cfa_13::mc_jets_px() const{
  if(!c_mc_jets_px_ && b_mc_jets_px_){
    b_mc_jets_px_->GetEntry(entry_);
    c_mc_jets_px_ = true;
  }
  return mc_jets_px_;
}

std::vector<float>* const & cfa_13::mc_jets_py() const{
  if(!c_mc_jets_py_ && b_mc_jets_py_){
    b_mc_jets_py_->GetEntry(entry_);
    c_mc_jets_py_ = true;
  }
  return mc_jets_py_;
}

std::vector<float>* const & cfa_13::mc_jets_pz() const{
  if(!c_mc_jets_pz_ && b_mc_jets_pz_){
    b_mc_jets_pz_->GetEntry(entry_);
    c_mc_jets_pz_ = true;
  }
  return mc_jets_pz_;
}

std::vector<float>* const & cfa_13::mc_jets_theta() const{
  if(!c_mc_jets_theta_ && b_mc_jets_theta_){
    b_mc_jets_theta_->GetEntry(entry_);
    c_mc_jets_theta_ = true;
  }
  return mc_jets_theta_;
}

std::vector<float>* const & cfa_13::mets_et() const{
  if(!c_mets_et_ && b_mets_et_){
    b_mets_et_->GetEntry(entry_);
    c_mets_et_ = true;
  }
  return mets_et_;
}

std::vector<float>* const & cfa_13::mets_ex() const{
  if(!c_mets_ex_ && b_mets_ex_){
    b_mets_ex_->GetEntry(entry_);
    c_mets_ex_ = true;
  }
  return mets_ex_;
}

std::vector<float>* const & cfa_13::mets_ey() const{
  if(!c_mets_ey_ && b_mets_ey_){
    b_mets_ey_->GetEntry(entry_);
    c_mets_ey_ = true;
  }
  return mets_ey_;
}

std::vector<float>* const & cfa_13::mets_gen_et() const{
  if(!c_mets_gen_et_ && b_mets_gen_et_){
    b_mets_gen_et_->GetEntry(entry_);
    c_mets_gen_et_ = true;
  }
  return mets_gen_et_;
}

std::vector<float>* const & cfa_13::mets_gen_phi() const{
  if(!c_mets_gen_phi_ && b_mets_gen_phi_){
    b_mets_gen_phi_->GetEntry(entry_);
    c_mets_gen_phi_ = true;
  }
  return mets_gen_phi_;
}

std::vector<float>* const & cfa_13::mets_phi() const{
  if(!c_mets_phi_ && b_mets_phi_){
    b_mets_phi_->GetEntry(entry_);
    c_mets_phi_ = true;
  }
  return mets_phi_;
}

std::vector<float>* const & cfa_13::mets_sign() const{
  if(!c_mets_sign_ && b_mets_sign_){
    b_mets_sign_->GetEntry(entry_);
    c_mets_sign_ = true;
  }
  return mets_sign_;
}

std::vector<float>* const & cfa_13::mets_sumEt() const{
  if(!c_mets_sumEt_ && b_mets_sumEt_){
    b_mets_sumEt_->GetEntry(entry_);
    c_mets_sumEt_ = true;
  }
  return mets_sumEt_;
}

std::vector<float>* const & cfa_13::mets_unCPhi() const{
  if(!c_mets_unCPhi_ && b_mets_unCPhi_){
    b_mets_unCPhi_->GetEntry(entry_);
    c_mets_unCPhi_ = true;
  }
  return mets_unCPhi_;
}

std::vector<float>* const & cfa_13::mets_unCPt() const{
  if(!c_mets_unCPt_ && b_mets_unCPt_){
    b_mets_unCPt_->GetEntry(entry_);
    c_mets_unCPt_ = true;
  }
  return mets_unCPt_;
}

std::vector<bool>* const & cfa_13::mus_isPF() const{
  if(!c_mus_isPF_ && b_mus_isPF_){
    b_mus_isPF_->GetEntry(entry_);
    c_mus_isPF_ = true;
  }
  return mus_isPF_;
}

std::vector<int>* const & cfa_13::mus_jet_ind() const{
  if(!c_mus_jet_ind_ && b_mus_jet_ind_){
    b_mus_jet_ind_->GetEntry(entry_);
    c_mus_jet_ind_ = true;
  }
  return mus_jet_ind_;
}

std::vector<int>* const & cfa_13::taus_el_ind() const{
  if(!c_taus_el_ind_ && b_taus_el_ind_){
    b_taus_el_ind_->GetEntry(entry_);
    c_taus_el_ind_ = true;
  }
  return taus_el_ind_;
}

std::vector<int>* const & cfa_13::taus_mu_ind() const{
  if(!c_taus_mu_ind_ && b_taus_mu_ind_){
    b_taus_mu_ind_->GetEntry(entry_);
    c_taus_mu_ind_ = true;
  }
  return taus_mu_ind_;
}

std::vector<bool>* const & cfa_13::trigger_decision() const{
  if(!c_trigger_decision_ && b_trigger_decision_){
    b_trigger_decision_->GetEntry(entry_);
    c_trigger_decision_ = true;
  }
  return trigger_decision_;
}

Int_t const & cfa_13::trkPOG_logErrorTooManyClustersfilter_decision() const{
  if(!c_trkPOG_logErrorTooManyClustersfilter_decision_ && b_trkPOG_logErrorTooManyClustersfilter_decision_){
    b_trkPOG_logErrorTooManyClustersfilter_decision_->GetEntry(entry_);
    c_trkPOG_logErrorTooManyClustersfilter_decision_ = true;
  }
  return trkPOG_logErrorTooManyClustersfilter_decision_;
}

Int_t const & cfa_13::trkPOG_manystripclus53Xfilter_decision() const{
  if(!c_trkPOG_manystripclus53Xfilter_decision_ && b_trkPOG_manystripclus53Xfilter_decision_){
    b_trkPOG_manystripclus53Xfilter_decision_->GetEntry(entry_);
    c_trkPOG_manystripclus53Xfilter_decision_ = true;
  }
  return trkPOG_manystripclus53Xfilter_decision_;
}

Int_t const & cfa_13::trkPOG_toomanystripclus53Xfilter_decision() const{
  if(!c_trkPOG_toomanystripclus53Xfilter_decision_ && b_trkPOG_toomanystripclus53Xfilter_decision_){
    b_trkPOG_toomanystripclus53Xfilter_decision_->GetEntry(entry_);
    c_trkPOG_toomanystripclus53Xfilter_decision_ = true;
  }
  return trkPOG_toomanystripclus53Xfilter_decision_;
}

Int_t const & cfa_13::trkPOGfilter_decision() const{
  if(!c_trkPOGfilter_decision_ && b_trkPOGfilter_decision_){
    b_trkPOGfilter_decision_->GetEntry(entry_);
    c_trkPOGfilter_decision_ = true;
  }
  return trkPOGfilter_decision_;
}

