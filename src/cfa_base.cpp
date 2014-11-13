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
  cached_total_entries_(false),
  NbeamSpot_(0),
  b_NbeamSpot_(NULL),
  c_NbeamSpot_(false),
  Nels_(0),
  b_Nels_(NULL),
  c_Nels_(false),
  Nmc_doc_(0),
  b_Nmc_doc_(NULL),
  c_Nmc_doc_(false),
  Nmc_electrons_(0),
  b_Nmc_electrons_(NULL),
  c_Nmc_electrons_(false),
  Nmc_mus_(0),
  b_Nmc_mus_(NULL),
  c_Nmc_mus_(false),
  Nmc_nues_(0),
  b_Nmc_nues_(NULL),
  c_Nmc_nues_(false),
  Nmc_numus_(0),
  b_Nmc_numus_(NULL),
  c_Nmc_numus_(false),
  Nmc_nutaus_(0),
  b_Nmc_nutaus_(NULL),
  c_Nmc_nutaus_(false),
  Nmc_photons_(0),
  b_Nmc_photons_(NULL),
  c_Nmc_photons_(false),
  Nmc_taus_(0),
  b_Nmc_taus_(NULL),
  c_Nmc_taus_(false),
  Nmus_(0),
  b_Nmus_(NULL),
  c_Nmus_(false),
  Npfcand_(0),
  b_Npfcand_(NULL),
  c_Npfcand_(false),
  Nphotons_(0),
  b_Nphotons_(NULL),
  c_Nphotons_(false),
  Npv_(0),
  b_Npv_(NULL),
  c_Npv_(false),
  Ntaus_(0),
  b_Ntaus_(NULL),
  c_Ntaus_(false),
  PU_NumInteractions_(0),
  b_PU_NumInteractions_(NULL),
  c_PU_NumInteractions_(false),
  PU_TrueNumInteractions_(0),
  b_PU_TrueNumInteractions_(NULL),
  c_PU_TrueNumInteractions_(false),
  PU_bunchCrossing_(0),
  b_PU_bunchCrossing_(NULL),
  c_PU_bunchCrossing_(false),
  PU_ntrks_highpT_(0),
  b_PU_ntrks_highpT_(NULL),
  c_PU_ntrks_highpT_(false),
  PU_ntrks_lowpT_(0),
  b_PU_ntrks_lowpT_(NULL),
  c_PU_ntrks_lowpT_(false),
  PU_sumpT_highpT_(0),
  b_PU_sumpT_highpT_(NULL),
  c_PU_sumpT_highpT_(false),
  PU_sumpT_lowpT_(0),
  b_PU_sumpT_lowpT_(NULL),
  c_PU_sumpT_lowpT_(false),
  PU_zpositions_(0),
  b_PU_zpositions_(NULL),
  c_PU_zpositions_(false),
  beamSpot_beamWidthX_(0),
  b_beamSpot_beamWidthX_(NULL),
  c_beamSpot_beamWidthX_(false),
  beamSpot_beamWidthXError_(0),
  b_beamSpot_beamWidthXError_(NULL),
  c_beamSpot_beamWidthXError_(false),
  beamSpot_beamWidthY_(0),
  b_beamSpot_beamWidthY_(NULL),
  c_beamSpot_beamWidthY_(false),
  beamSpot_beamWidthYError_(0),
  b_beamSpot_beamWidthYError_(NULL),
  c_beamSpot_beamWidthYError_(false),
  beamSpot_dxdz_(0),
  b_beamSpot_dxdz_(NULL),
  c_beamSpot_dxdz_(false),
  beamSpot_dxdzError_(0),
  b_beamSpot_dxdzError_(NULL),
  c_beamSpot_dxdzError_(false),
  beamSpot_dydz_(0),
  b_beamSpot_dydz_(NULL),
  c_beamSpot_dydz_(false),
  beamSpot_dydzError_(0),
  b_beamSpot_dydzError_(NULL),
  c_beamSpot_dydzError_(false),
  beamSpot_sigmaZ_(0),
  b_beamSpot_sigmaZ_(NULL),
  c_beamSpot_sigmaZ_(false),
  beamSpot_sigmaZ0Error_(0),
  b_beamSpot_sigmaZ0Error_(NULL),
  c_beamSpot_sigmaZ0Error_(false),
  beamSpot_x_(0),
  b_beamSpot_x_(NULL),
  c_beamSpot_x_(false),
  beamSpot_x0Error_(0),
  b_beamSpot_x0Error_(NULL),
  c_beamSpot_x0Error_(false),
  beamSpot_y_(0),
  b_beamSpot_y_(NULL),
  c_beamSpot_y_(false),
  beamSpot_y0Error_(0),
  b_beamSpot_y0Error_(NULL),
  c_beamSpot_y0Error_(false),
  beamSpot_z_(0),
  b_beamSpot_z_(NULL),
  c_beamSpot_z_(false),
  beamSpot_z0Error_(0),
  b_beamSpot_z0Error_(NULL),
  c_beamSpot_z0Error_(false),
  bunchCrossing_(0),
  b_bunchCrossing_(NULL),
  c_bunchCrossing_(false),
  cschalofilter_decision_(0),
  b_cschalofilter_decision_(NULL),
  c_cschalofilter_decision_(false),
  ecallaserfilter_decision_(0),
  b_ecallaserfilter_decision_(NULL),
  c_ecallaserfilter_decision_(false),
  eebadscfilter_decision_(0),
  b_eebadscfilter_decision_(NULL),
  c_eebadscfilter_decision_(false),
  els_PATpassConversionVeto_(0),
  b_els_PATpassConversionVeto_(NULL),
  c_els_PATpassConversionVeto_(false),
  els_basicClustersSize_(0),
  b_els_basicClustersSize_(NULL),
  c_els_basicClustersSize_(false),
  els_cIso_(0),
  b_els_cIso_(NULL),
  c_els_cIso_(false),
  els_caloEnergy_(0),
  b_els_caloEnergy_(NULL),
  c_els_caloEnergy_(false),
  els_charge_(0),
  b_els_charge_(NULL),
  c_els_charge_(false),
  els_chi2_(0),
  b_els_chi2_(NULL),
  c_els_chi2_(false),
  els_core_ecalDrivenSeed_(0),
  b_els_core_ecalDrivenSeed_(NULL),
  c_els_core_ecalDrivenSeed_(false),
  els_cpx_(0),
  b_els_cpx_(NULL),
  c_els_cpx_(false),
  els_cpy_(0),
  b_els_cpy_(NULL),
  c_els_cpy_(false),
  els_cpz_(0),
  b_els_cpz_(NULL),
  c_els_cpz_(false),
  els_ctf_tk_charge_(0),
  b_els_ctf_tk_charge_(NULL),
  c_els_ctf_tk_charge_(false),
  els_ctf_tk_eta_(0),
  b_els_ctf_tk_eta_(NULL),
  c_els_ctf_tk_eta_(false),
  els_ctf_tk_id_(0),
  b_els_ctf_tk_id_(NULL),
  c_els_ctf_tk_id_(false),
  els_ctf_tk_phi_(0),
  b_els_ctf_tk_phi_(NULL),
  c_els_ctf_tk_phi_(false),
  els_cx_(0),
  b_els_cx_(NULL),
  c_els_cx_(false),
  els_cy_(0),
  b_els_cy_(NULL),
  c_els_cy_(false),
  els_cz_(0),
  b_els_cz_(NULL),
  c_els_cz_(false),
  els_d0dum_(0),
  b_els_d0dum_(NULL),
  c_els_d0dum_(false),
  els_d0dumError_(0),
  b_els_d0dumError_(NULL),
  c_els_d0dumError_(false),
  els_dEtaIn_(0),
  b_els_dEtaIn_(NULL),
  c_els_dEtaIn_(false),
  els_dEtaOut_(0),
  b_els_dEtaOut_(NULL),
  c_els_dEtaOut_(false),
  els_dPhiIn_(0),
  b_els_dPhiIn_(NULL),
  c_els_dPhiIn_(false),
  els_dPhiOut_(0),
  b_els_dPhiOut_(NULL),
  c_els_dPhiOut_(false),
  els_dr03EcalRecHitSumEt_(0),
  b_els_dr03EcalRecHitSumEt_(NULL),
  c_els_dr03EcalRecHitSumEt_(false),
  els_dr03HcalDepth1TowerSumEt_(0),
  b_els_dr03HcalDepth1TowerSumEt_(NULL),
  c_els_dr03HcalDepth1TowerSumEt_(false),
  els_dr03HcalDepth2TowerSumEt_(0),
  b_els_dr03HcalDepth2TowerSumEt_(NULL),
  c_els_dr03HcalDepth2TowerSumEt_(false),
  els_dr03HcalTowerSumEt_(0),
  b_els_dr03HcalTowerSumEt_(NULL),
  c_els_dr03HcalTowerSumEt_(false),
  els_dr03TkSumPt_(0),
  b_els_dr03TkSumPt_(NULL),
  c_els_dr03TkSumPt_(false),
  els_dr04EcalRecHitSumEt_(0),
  b_els_dr04EcalRecHitSumEt_(NULL),
  c_els_dr04EcalRecHitSumEt_(false),
  els_dr04HcalDepth1TowerSumEt_(0),
  b_els_dr04HcalDepth1TowerSumEt_(NULL),
  c_els_dr04HcalDepth1TowerSumEt_(false),
  els_dr04HcalDepth2TowerSumEt_(0),
  b_els_dr04HcalDepth2TowerSumEt_(NULL),
  c_els_dr04HcalDepth2TowerSumEt_(false),
  els_dr04HcalTowerSumEt_(0),
  b_els_dr04HcalTowerSumEt_(NULL),
  c_els_dr04HcalTowerSumEt_(false),
  els_dr04TkSumPt_(0),
  b_els_dr04TkSumPt_(NULL),
  c_els_dr04TkSumPt_(false),
  els_dz_(0),
  b_els_dz_(NULL),
  c_els_dz_(false),
  els_dzError_(0),
  b_els_dzError_(NULL),
  c_els_dzError_(false),
  els_eOverPIn_(0),
  b_els_eOverPIn_(NULL),
  c_els_eOverPIn_(false),
  els_eSeedOverPOut_(0),
  b_els_eSeedOverPOut_(NULL),
  c_els_eSeedOverPOut_(false),
  els_ecalIso_(0),
  b_els_ecalIso_(NULL),
  c_els_ecalIso_(false),
  els_energy_(0),
  b_els_energy_(NULL),
  c_els_energy_(false),
  els_et_(0),
  b_els_et_(NULL),
  c_els_et_(false),
  els_eta_(0),
  b_els_eta_(NULL),
  c_els_eta_(false),
  els_etaError_(0),
  b_els_etaError_(NULL),
  c_els_etaError_(false),
  els_fbrem_(0),
  b_els_fbrem_(NULL),
  c_els_fbrem_(false),
  els_gen_et_(0),
  b_els_gen_et_(NULL),
  c_els_gen_et_(false),
  els_gen_eta_(0),
  b_els_gen_eta_(NULL),
  c_els_gen_eta_(false),
  els_gen_id_(0),
  b_els_gen_id_(NULL),
  c_els_gen_id_(false),
  els_gen_mother_et_(0),
  b_els_gen_mother_et_(NULL),
  c_els_gen_mother_et_(false),
  els_gen_mother_eta_(0),
  b_els_gen_mother_eta_(NULL),
  c_els_gen_mother_eta_(false),
  els_gen_mother_id_(0),
  b_els_gen_mother_id_(NULL),
  c_els_gen_mother_id_(false),
  els_gen_mother_phi_(0),
  b_els_gen_mother_phi_(NULL),
  c_els_gen_mother_phi_(false),
  els_gen_mother_pt_(0),
  b_els_gen_mother_pt_(NULL),
  c_els_gen_mother_pt_(false),
  els_gen_mother_px_(0),
  b_els_gen_mother_px_(NULL),
  c_els_gen_mother_px_(false),
  els_gen_mother_py_(0),
  b_els_gen_mother_py_(NULL),
  c_els_gen_mother_py_(false),
  els_gen_mother_pz_(0),
  b_els_gen_mother_pz_(NULL),
  c_els_gen_mother_pz_(false),
  els_gen_mother_theta_(0),
  b_els_gen_mother_theta_(NULL),
  c_els_gen_mother_theta_(false),
  els_gen_phi_(0),
  b_els_gen_phi_(NULL),
  c_els_gen_phi_(false),
  els_gen_pt_(0),
  b_els_gen_pt_(NULL),
  c_els_gen_pt_(false),
  els_gen_px_(0),
  b_els_gen_px_(NULL),
  c_els_gen_px_(false),
  els_gen_py_(0),
  b_els_gen_py_(NULL),
  c_els_gen_py_(false),
  els_gen_pz_(0),
  b_els_gen_pz_(NULL),
  c_els_gen_pz_(false),
  els_gen_theta_(0),
  b_els_gen_theta_(NULL),
  c_els_gen_theta_(false),
  els_hadOverEm_(0),
  b_els_hadOverEm_(NULL),
  c_els_hadOverEm_(false),
  els_hcalIso_(0),
  b_els_hcalIso_(NULL),
  c_els_hcalIso_(false),
  els_hcalOverEcalBc_(0),
  b_els_hcalOverEcalBc_(NULL),
  c_els_hcalOverEcalBc_(false),
  els_isEB_(0),
  b_els_isEB_(NULL),
  c_els_isEB_(false),
  els_isEE_(0),
  b_els_isEE_(NULL),
  c_els_isEE_(false),
  els_looseId_(0),
  b_els_looseId_(NULL),
  c_els_looseId_(false),
  els_n_inner_layer_(0),
  b_els_n_inner_layer_(NULL),
  c_els_n_inner_layer_(false),
  els_n_outer_layer_(0),
  b_els_n_outer_layer_(NULL),
  c_els_n_outer_layer_(false),
  els_ndof_(0),
  b_els_ndof_(NULL),
  c_els_ndof_(false),
  els_numlosthits_(0),
  b_els_numlosthits_(NULL),
  c_els_numlosthits_(false),
  els_numvalhits_(0),
  b_els_numvalhits_(NULL),
  c_els_numvalhits_(false),
  els_phi_(0),
  b_els_phi_(NULL),
  c_els_phi_(false),
  els_phiError_(0),
  b_els_phiError_(NULL),
  c_els_phiError_(false),
  els_pt_(0),
  b_els_pt_(NULL),
  c_els_pt_(false),
  els_ptError_(0),
  b_els_ptError_(NULL),
  c_els_ptError_(false),
  els_px_(0),
  b_els_px_(NULL),
  c_els_px_(false),
  els_py_(0),
  b_els_py_(NULL),
  c_els_py_(false),
  els_pz_(0),
  b_els_pz_(NULL),
  c_els_pz_(false),
  els_robustHighEnergyId_(0),
  b_els_robustHighEnergyId_(NULL),
  c_els_robustHighEnergyId_(false),
  els_robustLooseId_(0),
  b_els_robustLooseId_(NULL),
  c_els_robustLooseId_(false),
  els_robustTightId_(0),
  b_els_robustTightId_(NULL),
  c_els_robustTightId_(false),
  els_scE1x5_(0),
  b_els_scE1x5_(NULL),
  c_els_scE1x5_(false),
  els_scE2x5Max_(0),
  b_els_scE2x5Max_(NULL),
  c_els_scE2x5Max_(false),
  els_scE5x5_(0),
  b_els_scE5x5_(NULL),
  c_els_scE5x5_(false),
  els_scEnergy_(0),
  b_els_scEnergy_(NULL),
  c_els_scEnergy_(false),
  els_scEta_(0),
  b_els_scEta_(NULL),
  c_els_scEta_(false),
  els_scEtaWidth_(0),
  b_els_scEtaWidth_(NULL),
  c_els_scEtaWidth_(false),
  els_scPhi_(0),
  b_els_scPhi_(NULL),
  c_els_scPhi_(false),
  els_scPhiWidth_(0),
  b_els_scPhiWidth_(NULL),
  c_els_scPhiWidth_(false),
  els_scRawEnergy_(0),
  b_els_scRawEnergy_(NULL),
  c_els_scRawEnergy_(false),
  els_scSeedEnergy_(0),
  b_els_scSeedEnergy_(NULL),
  c_els_scSeedEnergy_(false),
  els_shFracInnerHits_(0),
  b_els_shFracInnerHits_(NULL),
  c_els_shFracInnerHits_(false),
  els_sigmaEtaEta_(0),
  b_els_sigmaEtaEta_(NULL),
  c_els_sigmaEtaEta_(false),
  els_sigmaIEtaIEta_(0),
  b_els_sigmaIEtaIEta_(NULL),
  c_els_sigmaIEtaIEta_(false),
  els_simpleEleId60cIso_(0),
  b_els_simpleEleId60cIso_(NULL),
  c_els_simpleEleId60cIso_(false),
  els_simpleEleId60relIso_(0),
  b_els_simpleEleId60relIso_(NULL),
  c_els_simpleEleId60relIso_(false),
  els_simpleEleId70cIso_(0),
  b_els_simpleEleId70cIso_(NULL),
  c_els_simpleEleId70cIso_(false),
  els_simpleEleId70relIso_(0),
  b_els_simpleEleId70relIso_(NULL),
  c_els_simpleEleId70relIso_(false),
  els_simpleEleId80cIso_(0),
  b_els_simpleEleId80cIso_(NULL),
  c_els_simpleEleId80cIso_(false),
  els_simpleEleId80relIso_(0),
  b_els_simpleEleId80relIso_(NULL),
  c_els_simpleEleId80relIso_(false),
  els_simpleEleId85cIso_(0),
  b_els_simpleEleId85cIso_(NULL),
  c_els_simpleEleId85cIso_(false),
  els_simpleEleId85relIso_(0),
  b_els_simpleEleId85relIso_(NULL),
  c_els_simpleEleId85relIso_(false),
  els_simpleEleId90cIso_(0),
  b_els_simpleEleId90cIso_(NULL),
  c_els_simpleEleId90cIso_(false),
  els_simpleEleId90relIso_(0),
  b_els_simpleEleId90relIso_(NULL),
  c_els_simpleEleId90relIso_(false),
  els_simpleEleId95cIso_(0),
  b_els_simpleEleId95cIso_(NULL),
  c_els_simpleEleId95cIso_(false),
  els_simpleEleId95relIso_(0),
  b_els_simpleEleId95relIso_(NULL),
  c_els_simpleEleId95relIso_(false),
  els_status_(0),
  b_els_status_(NULL),
  c_els_status_(false),
  els_tIso_(0),
  b_els_tIso_(NULL),
  c_els_tIso_(false),
  els_theta_(0),
  b_els_theta_(NULL),
  c_els_theta_(false),
  els_tightId_(0),
  b_els_tightId_(NULL),
  c_els_tightId_(false),
  els_tk_charge_(0),
  b_els_tk_charge_(NULL),
  c_els_tk_charge_(false),
  els_tk_eta_(0),
  b_els_tk_eta_(NULL),
  c_els_tk_eta_(false),
  els_tk_phi_(0),
  b_els_tk_phi_(NULL),
  c_els_tk_phi_(false),
  els_tk_pt_(0),
  b_els_tk_pt_(NULL),
  c_els_tk_pt_(false),
  els_tk_pz_(0),
  b_els_tk_pz_(NULL),
  c_els_tk_pz_(false),
  els_vpx_(0),
  b_els_vpx_(NULL),
  c_els_vpx_(false),
  els_vpy_(0),
  b_els_vpy_(NULL),
  c_els_vpy_(false),
  els_vpz_(0),
  b_els_vpz_(NULL),
  c_els_vpz_(false),
  els_vx_(0),
  b_els_vx_(NULL),
  c_els_vx_(false),
  els_vy_(0),
  b_els_vy_(NULL),
  c_els_vy_(false),
  els_vz_(0),
  b_els_vz_(NULL),
  c_els_vz_(false),
  event_(0),
  b_event_(NULL),
  c_event_(false),
  experimentType_(0),
  b_experimentType_(NULL),
  c_experimentType_(false),
  hcallaserfilter_decision_(0),
  b_hcallaserfilter_decision_(NULL),
  c_hcallaserfilter_decision_(false),
  lumiblock_(0),
  b_lumiblock_(NULL),
  c_lumiblock_(false),
  mc_doc_charge_(0),
  b_mc_doc_charge_(NULL),
  c_mc_doc_charge_(false),
  mc_doc_energy_(0),
  b_mc_doc_energy_(NULL),
  c_mc_doc_energy_(false),
  mc_doc_eta_(0),
  b_mc_doc_eta_(NULL),
  c_mc_doc_eta_(false),
  mc_doc_ggrandmother_id_(0),
  b_mc_doc_ggrandmother_id_(NULL),
  c_mc_doc_ggrandmother_id_(false),
  mc_doc_grandmother_id_(0),
  b_mc_doc_grandmother_id_(NULL),
  c_mc_doc_grandmother_id_(false),
  mc_doc_id_(0),
  b_mc_doc_id_(NULL),
  c_mc_doc_id_(false),
  mc_doc_mass_(0),
  b_mc_doc_mass_(NULL),
  c_mc_doc_mass_(false),
  mc_doc_mother_id_(0),
  b_mc_doc_mother_id_(NULL),
  c_mc_doc_mother_id_(false),
  mc_doc_mother_pt_(0),
  b_mc_doc_mother_pt_(NULL),
  c_mc_doc_mother_pt_(false),
  mc_doc_numOfDaughters_(0),
  b_mc_doc_numOfDaughters_(NULL),
  c_mc_doc_numOfDaughters_(false),
  mc_doc_numOfMothers_(0),
  b_mc_doc_numOfMothers_(NULL),
  c_mc_doc_numOfMothers_(false),
  mc_doc_phi_(0),
  b_mc_doc_phi_(NULL),
  c_mc_doc_phi_(false),
  mc_doc_pt_(0),
  b_mc_doc_pt_(NULL),
  c_mc_doc_pt_(false),
  mc_doc_px_(0),
  b_mc_doc_px_(NULL),
  c_mc_doc_px_(false),
  mc_doc_py_(0),
  b_mc_doc_py_(NULL),
  c_mc_doc_py_(false),
  mc_doc_pz_(0),
  b_mc_doc_pz_(NULL),
  c_mc_doc_pz_(false),
  mc_doc_status_(0),
  b_mc_doc_status_(NULL),
  c_mc_doc_status_(false),
  mc_doc_theta_(0),
  b_mc_doc_theta_(NULL),
  c_mc_doc_theta_(false),
  mc_doc_vertex_x_(0),
  b_mc_doc_vertex_x_(NULL),
  c_mc_doc_vertex_x_(false),
  mc_doc_vertex_y_(0),
  b_mc_doc_vertex_y_(NULL),
  c_mc_doc_vertex_y_(false),
  mc_doc_vertex_z_(0),
  b_mc_doc_vertex_z_(NULL),
  c_mc_doc_vertex_z_(false),
  mc_electrons_charge_(0),
  b_mc_electrons_charge_(NULL),
  c_mc_electrons_charge_(false),
  mc_electrons_energy_(0),
  b_mc_electrons_energy_(NULL),
  c_mc_electrons_energy_(false),
  mc_electrons_eta_(0),
  b_mc_electrons_eta_(NULL),
  c_mc_electrons_eta_(false),
  mc_electrons_ggrandmother_id_(0),
  b_mc_electrons_ggrandmother_id_(NULL),
  c_mc_electrons_ggrandmother_id_(false),
  mc_electrons_grandmother_id_(0),
  b_mc_electrons_grandmother_id_(NULL),
  c_mc_electrons_grandmother_id_(false),
  mc_electrons_id_(0),
  b_mc_electrons_id_(NULL),
  c_mc_electrons_id_(false),
  mc_electrons_mass_(0),
  b_mc_electrons_mass_(NULL),
  c_mc_electrons_mass_(false),
  mc_electrons_mother_id_(0),
  b_mc_electrons_mother_id_(NULL),
  c_mc_electrons_mother_id_(false),
  mc_electrons_mother_pt_(0),
  b_mc_electrons_mother_pt_(NULL),
  c_mc_electrons_mother_pt_(false),
  mc_electrons_numOfDaughters_(0),
  b_mc_electrons_numOfDaughters_(NULL),
  c_mc_electrons_numOfDaughters_(false),
  mc_electrons_phi_(0),
  b_mc_electrons_phi_(NULL),
  c_mc_electrons_phi_(false),
  mc_electrons_pt_(0),
  b_mc_electrons_pt_(NULL),
  c_mc_electrons_pt_(false),
  mc_electrons_px_(0),
  b_mc_electrons_px_(NULL),
  c_mc_electrons_px_(false),
  mc_electrons_py_(0),
  b_mc_electrons_py_(NULL),
  c_mc_electrons_py_(false),
  mc_electrons_pz_(0),
  b_mc_electrons_pz_(NULL),
  c_mc_electrons_pz_(false),
  mc_electrons_status_(0),
  b_mc_electrons_status_(NULL),
  c_mc_electrons_status_(false),
  mc_electrons_theta_(0),
  b_mc_electrons_theta_(NULL),
  c_mc_electrons_theta_(false),
  mc_electrons_vertex_x_(0),
  b_mc_electrons_vertex_x_(NULL),
  c_mc_electrons_vertex_x_(false),
  mc_electrons_vertex_y_(0),
  b_mc_electrons_vertex_y_(NULL),
  c_mc_electrons_vertex_y_(false),
  mc_electrons_vertex_z_(0),
  b_mc_electrons_vertex_z_(NULL),
  c_mc_electrons_vertex_z_(false),
  mc_mus_charge_(0),
  b_mc_mus_charge_(NULL),
  c_mc_mus_charge_(false),
  mc_mus_energy_(0),
  b_mc_mus_energy_(NULL),
  c_mc_mus_energy_(false),
  mc_mus_eta_(0),
  b_mc_mus_eta_(NULL),
  c_mc_mus_eta_(false),
  mc_mus_ggrandmother_id_(0),
  b_mc_mus_ggrandmother_id_(NULL),
  c_mc_mus_ggrandmother_id_(false),
  mc_mus_grandmother_id_(0),
  b_mc_mus_grandmother_id_(NULL),
  c_mc_mus_grandmother_id_(false),
  mc_mus_id_(0),
  b_mc_mus_id_(NULL),
  c_mc_mus_id_(false),
  mc_mus_mass_(0),
  b_mc_mus_mass_(NULL),
  c_mc_mus_mass_(false),
  mc_mus_mother_id_(0),
  b_mc_mus_mother_id_(NULL),
  c_mc_mus_mother_id_(false),
  mc_mus_mother_pt_(0),
  b_mc_mus_mother_pt_(NULL),
  c_mc_mus_mother_pt_(false),
  mc_mus_numOfDaughters_(0),
  b_mc_mus_numOfDaughters_(NULL),
  c_mc_mus_numOfDaughters_(false),
  mc_mus_phi_(0),
  b_mc_mus_phi_(NULL),
  c_mc_mus_phi_(false),
  mc_mus_pt_(0),
  b_mc_mus_pt_(NULL),
  c_mc_mus_pt_(false),
  mc_mus_px_(0),
  b_mc_mus_px_(NULL),
  c_mc_mus_px_(false),
  mc_mus_py_(0),
  b_mc_mus_py_(NULL),
  c_mc_mus_py_(false),
  mc_mus_pz_(0),
  b_mc_mus_pz_(NULL),
  c_mc_mus_pz_(false),
  mc_mus_status_(0),
  b_mc_mus_status_(NULL),
  c_mc_mus_status_(false),
  mc_mus_theta_(0),
  b_mc_mus_theta_(NULL),
  c_mc_mus_theta_(false),
  mc_mus_vertex_x_(0),
  b_mc_mus_vertex_x_(NULL),
  c_mc_mus_vertex_x_(false),
  mc_mus_vertex_y_(0),
  b_mc_mus_vertex_y_(NULL),
  c_mc_mus_vertex_y_(false),
  mc_mus_vertex_z_(0),
  b_mc_mus_vertex_z_(NULL),
  c_mc_mus_vertex_z_(false),
  mc_nues_charge_(0),
  b_mc_nues_charge_(NULL),
  c_mc_nues_charge_(false),
  mc_nues_energy_(0),
  b_mc_nues_energy_(NULL),
  c_mc_nues_energy_(false),
  mc_nues_eta_(0),
  b_mc_nues_eta_(NULL),
  c_mc_nues_eta_(false),
  mc_nues_ggrandmother_id_(0),
  b_mc_nues_ggrandmother_id_(NULL),
  c_mc_nues_ggrandmother_id_(false),
  mc_nues_grandmother_id_(0),
  b_mc_nues_grandmother_id_(NULL),
  c_mc_nues_grandmother_id_(false),
  mc_nues_id_(0),
  b_mc_nues_id_(NULL),
  c_mc_nues_id_(false),
  mc_nues_mass_(0),
  b_mc_nues_mass_(NULL),
  c_mc_nues_mass_(false),
  mc_nues_mother_id_(0),
  b_mc_nues_mother_id_(NULL),
  c_mc_nues_mother_id_(false),
  mc_nues_mother_pt_(0),
  b_mc_nues_mother_pt_(NULL),
  c_mc_nues_mother_pt_(false),
  mc_nues_numOfDaughters_(0),
  b_mc_nues_numOfDaughters_(NULL),
  c_mc_nues_numOfDaughters_(false),
  mc_nues_phi_(0),
  b_mc_nues_phi_(NULL),
  c_mc_nues_phi_(false),
  mc_nues_pt_(0),
  b_mc_nues_pt_(NULL),
  c_mc_nues_pt_(false),
  mc_nues_px_(0),
  b_mc_nues_px_(NULL),
  c_mc_nues_px_(false),
  mc_nues_py_(0),
  b_mc_nues_py_(NULL),
  c_mc_nues_py_(false),
  mc_nues_pz_(0),
  b_mc_nues_pz_(NULL),
  c_mc_nues_pz_(false),
  mc_nues_status_(0),
  b_mc_nues_status_(NULL),
  c_mc_nues_status_(false),
  mc_nues_theta_(0),
  b_mc_nues_theta_(NULL),
  c_mc_nues_theta_(false),
  mc_nues_vertex_x_(0),
  b_mc_nues_vertex_x_(NULL),
  c_mc_nues_vertex_x_(false),
  mc_nues_vertex_y_(0),
  b_mc_nues_vertex_y_(NULL),
  c_mc_nues_vertex_y_(false),
  mc_nues_vertex_z_(0),
  b_mc_nues_vertex_z_(NULL),
  c_mc_nues_vertex_z_(false),
  mc_numus_charge_(0),
  b_mc_numus_charge_(NULL),
  c_mc_numus_charge_(false),
  mc_numus_energy_(0),
  b_mc_numus_energy_(NULL),
  c_mc_numus_energy_(false),
  mc_numus_eta_(0),
  b_mc_numus_eta_(NULL),
  c_mc_numus_eta_(false),
  mc_numus_ggrandmother_id_(0),
  b_mc_numus_ggrandmother_id_(NULL),
  c_mc_numus_ggrandmother_id_(false),
  mc_numus_grandmother_id_(0),
  b_mc_numus_grandmother_id_(NULL),
  c_mc_numus_grandmother_id_(false),
  mc_numus_id_(0),
  b_mc_numus_id_(NULL),
  c_mc_numus_id_(false),
  mc_numus_mass_(0),
  b_mc_numus_mass_(NULL),
  c_mc_numus_mass_(false),
  mc_numus_mother_id_(0),
  b_mc_numus_mother_id_(NULL),
  c_mc_numus_mother_id_(false),
  mc_numus_mother_pt_(0),
  b_mc_numus_mother_pt_(NULL),
  c_mc_numus_mother_pt_(false),
  mc_numus_numOfDaughters_(0),
  b_mc_numus_numOfDaughters_(NULL),
  c_mc_numus_numOfDaughters_(false),
  mc_numus_phi_(0),
  b_mc_numus_phi_(NULL),
  c_mc_numus_phi_(false),
  mc_numus_pt_(0),
  b_mc_numus_pt_(NULL),
  c_mc_numus_pt_(false),
  mc_numus_px_(0),
  b_mc_numus_px_(NULL),
  c_mc_numus_px_(false),
  mc_numus_py_(0),
  b_mc_numus_py_(NULL),
  c_mc_numus_py_(false),
  mc_numus_pz_(0),
  b_mc_numus_pz_(NULL),
  c_mc_numus_pz_(false),
  mc_numus_status_(0),
  b_mc_numus_status_(NULL),
  c_mc_numus_status_(false),
  mc_numus_theta_(0),
  b_mc_numus_theta_(NULL),
  c_mc_numus_theta_(false),
  mc_numus_vertex_x_(0),
  b_mc_numus_vertex_x_(NULL),
  c_mc_numus_vertex_x_(false),
  mc_numus_vertex_y_(0),
  b_mc_numus_vertex_y_(NULL),
  c_mc_numus_vertex_y_(false),
  mc_numus_vertex_z_(0),
  b_mc_numus_vertex_z_(NULL),
  c_mc_numus_vertex_z_(false),
  mc_nutaus_charge_(0),
  b_mc_nutaus_charge_(NULL),
  c_mc_nutaus_charge_(false),
  mc_nutaus_energy_(0),
  b_mc_nutaus_energy_(NULL),
  c_mc_nutaus_energy_(false),
  mc_nutaus_eta_(0),
  b_mc_nutaus_eta_(NULL),
  c_mc_nutaus_eta_(false),
  mc_nutaus_ggrandmother_id_(0),
  b_mc_nutaus_ggrandmother_id_(NULL),
  c_mc_nutaus_ggrandmother_id_(false),
  mc_nutaus_grandmother_id_(0),
  b_mc_nutaus_grandmother_id_(NULL),
  c_mc_nutaus_grandmother_id_(false),
  mc_nutaus_id_(0),
  b_mc_nutaus_id_(NULL),
  c_mc_nutaus_id_(false),
  mc_nutaus_mass_(0),
  b_mc_nutaus_mass_(NULL),
  c_mc_nutaus_mass_(false),
  mc_nutaus_mother_id_(0),
  b_mc_nutaus_mother_id_(NULL),
  c_mc_nutaus_mother_id_(false),
  mc_nutaus_mother_pt_(0),
  b_mc_nutaus_mother_pt_(NULL),
  c_mc_nutaus_mother_pt_(false),
  mc_nutaus_numOfDaughters_(0),
  b_mc_nutaus_numOfDaughters_(NULL),
  c_mc_nutaus_numOfDaughters_(false),
  mc_nutaus_phi_(0),
  b_mc_nutaus_phi_(NULL),
  c_mc_nutaus_phi_(false),
  mc_nutaus_pt_(0),
  b_mc_nutaus_pt_(NULL),
  c_mc_nutaus_pt_(false),
  mc_nutaus_px_(0),
  b_mc_nutaus_px_(NULL),
  c_mc_nutaus_px_(false),
  mc_nutaus_py_(0),
  b_mc_nutaus_py_(NULL),
  c_mc_nutaus_py_(false),
  mc_nutaus_pz_(0),
  b_mc_nutaus_pz_(NULL),
  c_mc_nutaus_pz_(false),
  mc_nutaus_status_(0),
  b_mc_nutaus_status_(NULL),
  c_mc_nutaus_status_(false),
  mc_nutaus_theta_(0),
  b_mc_nutaus_theta_(NULL),
  c_mc_nutaus_theta_(false),
  mc_nutaus_vertex_x_(0),
  b_mc_nutaus_vertex_x_(NULL),
  c_mc_nutaus_vertex_x_(false),
  mc_nutaus_vertex_y_(0),
  b_mc_nutaus_vertex_y_(NULL),
  c_mc_nutaus_vertex_y_(false),
  mc_nutaus_vertex_z_(0),
  b_mc_nutaus_vertex_z_(NULL),
  c_mc_nutaus_vertex_z_(false),
  mc_photons_charge_(0),
  b_mc_photons_charge_(NULL),
  c_mc_photons_charge_(false),
  mc_photons_energy_(0),
  b_mc_photons_energy_(NULL),
  c_mc_photons_energy_(false),
  mc_photons_eta_(0),
  b_mc_photons_eta_(NULL),
  c_mc_photons_eta_(false),
  mc_photons_ggrandmother_id_(0),
  b_mc_photons_ggrandmother_id_(NULL),
  c_mc_photons_ggrandmother_id_(false),
  mc_photons_grandmother_id_(0),
  b_mc_photons_grandmother_id_(NULL),
  c_mc_photons_grandmother_id_(false),
  mc_photons_id_(0),
  b_mc_photons_id_(NULL),
  c_mc_photons_id_(false),
  mc_photons_mass_(0),
  b_mc_photons_mass_(NULL),
  c_mc_photons_mass_(false),
  mc_photons_mother_id_(0),
  b_mc_photons_mother_id_(NULL),
  c_mc_photons_mother_id_(false),
  mc_photons_mother_pt_(0),
  b_mc_photons_mother_pt_(NULL),
  c_mc_photons_mother_pt_(false),
  mc_photons_numOfDaughters_(0),
  b_mc_photons_numOfDaughters_(NULL),
  c_mc_photons_numOfDaughters_(false),
  mc_photons_phi_(0),
  b_mc_photons_phi_(NULL),
  c_mc_photons_phi_(false),
  mc_photons_pt_(0),
  b_mc_photons_pt_(NULL),
  c_mc_photons_pt_(false),
  mc_photons_px_(0),
  b_mc_photons_px_(NULL),
  c_mc_photons_px_(false),
  mc_photons_py_(0),
  b_mc_photons_py_(NULL),
  c_mc_photons_py_(false),
  mc_photons_pz_(0),
  b_mc_photons_pz_(NULL),
  c_mc_photons_pz_(false),
  mc_photons_status_(0),
  b_mc_photons_status_(NULL),
  c_mc_photons_status_(false),
  mc_photons_theta_(0),
  b_mc_photons_theta_(NULL),
  c_mc_photons_theta_(false),
  mc_photons_vertex_x_(0),
  b_mc_photons_vertex_x_(NULL),
  c_mc_photons_vertex_x_(false),
  mc_photons_vertex_y_(0),
  b_mc_photons_vertex_y_(NULL),
  c_mc_photons_vertex_y_(false),
  mc_photons_vertex_z_(0),
  b_mc_photons_vertex_z_(NULL),
  c_mc_photons_vertex_z_(false),
  mc_taus_charge_(0),
  b_mc_taus_charge_(NULL),
  c_mc_taus_charge_(false),
  mc_taus_energy_(0),
  b_mc_taus_energy_(NULL),
  c_mc_taus_energy_(false),
  mc_taus_eta_(0),
  b_mc_taus_eta_(NULL),
  c_mc_taus_eta_(false),
  mc_taus_ggrandmother_id_(0),
  b_mc_taus_ggrandmother_id_(NULL),
  c_mc_taus_ggrandmother_id_(false),
  mc_taus_grandmother_id_(0),
  b_mc_taus_grandmother_id_(NULL),
  c_mc_taus_grandmother_id_(false),
  mc_taus_id_(0),
  b_mc_taus_id_(NULL),
  c_mc_taus_id_(false),
  mc_taus_mass_(0),
  b_mc_taus_mass_(NULL),
  c_mc_taus_mass_(false),
  mc_taus_mother_id_(0),
  b_mc_taus_mother_id_(NULL),
  c_mc_taus_mother_id_(false),
  mc_taus_mother_pt_(0),
  b_mc_taus_mother_pt_(NULL),
  c_mc_taus_mother_pt_(false),
  mc_taus_numOfDaughters_(0),
  b_mc_taus_numOfDaughters_(NULL),
  c_mc_taus_numOfDaughters_(false),
  mc_taus_phi_(0),
  b_mc_taus_phi_(NULL),
  c_mc_taus_phi_(false),
  mc_taus_pt_(0),
  b_mc_taus_pt_(NULL),
  c_mc_taus_pt_(false),
  mc_taus_px_(0),
  b_mc_taus_px_(NULL),
  c_mc_taus_px_(false),
  mc_taus_py_(0),
  b_mc_taus_py_(NULL),
  c_mc_taus_py_(false),
  mc_taus_pz_(0),
  b_mc_taus_pz_(NULL),
  c_mc_taus_pz_(false),
  mc_taus_status_(0),
  b_mc_taus_status_(NULL),
  c_mc_taus_status_(false),
  mc_taus_theta_(0),
  b_mc_taus_theta_(NULL),
  c_mc_taus_theta_(false),
  mc_taus_vertex_x_(0),
  b_mc_taus_vertex_x_(NULL),
  c_mc_taus_vertex_x_(false),
  mc_taus_vertex_y_(0),
  b_mc_taus_vertex_y_(NULL),
  c_mc_taus_vertex_y_(false),
  mc_taus_vertex_z_(0),
  b_mc_taus_vertex_z_(NULL),
  c_mc_taus_vertex_z_(false),
  model_params_(0),
  b_model_params_(NULL),
  c_model_params_(false),
  mus_cIso_(0),
  b_mus_cIso_(NULL),
  c_mus_cIso_(false),
  mus_calEnergyEm_(0),
  b_mus_calEnergyEm_(NULL),
  c_mus_calEnergyEm_(false),
  mus_calEnergyEmS9_(0),
  b_mus_calEnergyEmS9_(NULL),
  c_mus_calEnergyEmS9_(false),
  mus_calEnergyHad_(0),
  b_mus_calEnergyHad_(NULL),
  c_mus_calEnergyHad_(false),
  mus_calEnergyHadS9_(0),
  b_mus_calEnergyHadS9_(NULL),
  c_mus_calEnergyHadS9_(false),
  mus_calEnergyHo_(0),
  b_mus_calEnergyHo_(NULL),
  c_mus_calEnergyHo_(false),
  mus_calEnergyHoS9_(0),
  b_mus_calEnergyHoS9_(NULL),
  c_mus_calEnergyHoS9_(false),
  mus_charge_(0),
  b_mus_charge_(NULL),
  c_mus_charge_(false),
  mus_cm_ExpectedHitsInner_(0),
  b_mus_cm_ExpectedHitsInner_(NULL),
  c_mus_cm_ExpectedHitsInner_(false),
  mus_cm_ExpectedHitsOuter_(0),
  b_mus_cm_ExpectedHitsOuter_(NULL),
  c_mus_cm_ExpectedHitsOuter_(false),
  mus_cm_LayersWithMeasurement_(0),
  b_mus_cm_LayersWithMeasurement_(NULL),
  c_mus_cm_LayersWithMeasurement_(false),
  mus_cm_LayersWithoutMeasurement_(0),
  b_mus_cm_LayersWithoutMeasurement_(NULL),
  c_mus_cm_LayersWithoutMeasurement_(false),
  mus_cm_PixelLayersWithMeasurement_(0),
  b_mus_cm_PixelLayersWithMeasurement_(NULL),
  c_mus_cm_PixelLayersWithMeasurement_(false),
  mus_cm_ValidStripLayersWithMonoAndStereoHit_(0),
  b_mus_cm_ValidStripLayersWithMonoAndStereoHit_(NULL),
  c_mus_cm_ValidStripLayersWithMonoAndStereoHit_(false),
  mus_cm_chg_(0),
  b_mus_cm_chg_(NULL),
  c_mus_cm_chg_(false),
  mus_cm_chi2_(0),
  b_mus_cm_chi2_(NULL),
  c_mus_cm_chi2_(false),
  mus_cm_d0dum_(0),
  b_mus_cm_d0dum_(NULL),
  c_mus_cm_d0dum_(false),
  mus_cm_d0dumErr_(0),
  b_mus_cm_d0dumErr_(NULL),
  c_mus_cm_d0dumErr_(false),
  mus_cm_dz_(0),
  b_mus_cm_dz_(NULL),
  c_mus_cm_dz_(false),
  mus_cm_dzErr_(0),
  b_mus_cm_dzErr_(NULL),
  c_mus_cm_dzErr_(false),
  mus_cm_eta_(0),
  b_mus_cm_eta_(NULL),
  c_mus_cm_eta_(false),
  mus_cm_etaErr_(0),
  b_mus_cm_etaErr_(NULL),
  c_mus_cm_etaErr_(false),
  mus_cm_ndof_(0),
  b_mus_cm_ndof_(NULL),
  c_mus_cm_ndof_(false),
  mus_cm_numlosthits_(0),
  b_mus_cm_numlosthits_(NULL),
  c_mus_cm_numlosthits_(false),
  mus_cm_numvalMuonhits_(0),
  b_mus_cm_numvalMuonhits_(NULL),
  c_mus_cm_numvalMuonhits_(false),
  mus_cm_numvalhits_(0),
  b_mus_cm_numvalhits_(NULL),
  c_mus_cm_numvalhits_(false),
  mus_cm_phi_(0),
  b_mus_cm_phi_(NULL),
  c_mus_cm_phi_(false),
  mus_cm_phiErr_(0),
  b_mus_cm_phiErr_(NULL),
  c_mus_cm_phiErr_(false),
  mus_cm_pt_(0),
  b_mus_cm_pt_(NULL),
  c_mus_cm_pt_(false),
  mus_cm_ptErr_(0),
  b_mus_cm_ptErr_(NULL),
  c_mus_cm_ptErr_(false),
  mus_cm_px_(0),
  b_mus_cm_px_(NULL),
  c_mus_cm_px_(false),
  mus_cm_py_(0),
  b_mus_cm_py_(NULL),
  c_mus_cm_py_(false),
  mus_cm_pz_(0),
  b_mus_cm_pz_(NULL),
  c_mus_cm_pz_(false),
  mus_cm_theta_(0),
  b_mus_cm_theta_(NULL),
  c_mus_cm_theta_(false),
  mus_cm_vx_(0),
  b_mus_cm_vx_(NULL),
  c_mus_cm_vx_(false),
  mus_cm_vy_(0),
  b_mus_cm_vy_(NULL),
  c_mus_cm_vy_(false),
  mus_cm_vz_(0),
  b_mus_cm_vz_(NULL),
  c_mus_cm_vz_(false),
  mus_dB_(0),
  b_mus_dB_(NULL),
  c_mus_dB_(false),
  mus_ecalIso_(0),
  b_mus_ecalIso_(NULL),
  c_mus_ecalIso_(false),
  mus_ecalvetoDep_(0),
  b_mus_ecalvetoDep_(NULL),
  c_mus_ecalvetoDep_(false),
  mus_energy_(0),
  b_mus_energy_(NULL),
  c_mus_energy_(false),
  mus_et_(0),
  b_mus_et_(NULL),
  c_mus_et_(false),
  mus_eta_(0),
  b_mus_eta_(NULL),
  c_mus_eta_(false),
  mus_gen_et_(0),
  b_mus_gen_et_(NULL),
  c_mus_gen_et_(false),
  mus_gen_eta_(0),
  b_mus_gen_eta_(NULL),
  c_mus_gen_eta_(false),
  mus_gen_id_(0),
  b_mus_gen_id_(NULL),
  c_mus_gen_id_(false),
  mus_gen_mother_et_(0),
  b_mus_gen_mother_et_(NULL),
  c_mus_gen_mother_et_(false),
  mus_gen_mother_eta_(0),
  b_mus_gen_mother_eta_(NULL),
  c_mus_gen_mother_eta_(false),
  mus_gen_mother_id_(0),
  b_mus_gen_mother_id_(NULL),
  c_mus_gen_mother_id_(false),
  mus_gen_mother_phi_(0),
  b_mus_gen_mother_phi_(NULL),
  c_mus_gen_mother_phi_(false),
  mus_gen_mother_pt_(0),
  b_mus_gen_mother_pt_(NULL),
  c_mus_gen_mother_pt_(false),
  mus_gen_mother_px_(0),
  b_mus_gen_mother_px_(NULL),
  c_mus_gen_mother_px_(false),
  mus_gen_mother_py_(0),
  b_mus_gen_mother_py_(NULL),
  c_mus_gen_mother_py_(false),
  mus_gen_mother_pz_(0),
  b_mus_gen_mother_pz_(NULL),
  c_mus_gen_mother_pz_(false),
  mus_gen_mother_theta_(0),
  b_mus_gen_mother_theta_(NULL),
  c_mus_gen_mother_theta_(false),
  mus_gen_phi_(0),
  b_mus_gen_phi_(NULL),
  c_mus_gen_phi_(false),
  mus_gen_pt_(0),
  b_mus_gen_pt_(NULL),
  c_mus_gen_pt_(false),
  mus_gen_px_(0),
  b_mus_gen_px_(NULL),
  c_mus_gen_px_(false),
  mus_gen_py_(0),
  b_mus_gen_py_(NULL),
  c_mus_gen_py_(false),
  mus_gen_pz_(0),
  b_mus_gen_pz_(NULL),
  c_mus_gen_pz_(false),
  mus_gen_theta_(0),
  b_mus_gen_theta_(NULL),
  c_mus_gen_theta_(false),
  mus_hcalIso_(0),
  b_mus_hcalIso_(NULL),
  c_mus_hcalIso_(false),
  mus_hcalvetoDep_(0),
  b_mus_hcalvetoDep_(NULL),
  c_mus_hcalvetoDep_(false),
  mus_id_All_(0),
  b_mus_id_All_(NULL),
  c_mus_id_All_(false),
  mus_id_AllArbitrated_(0),
  b_mus_id_AllArbitrated_(NULL),
  c_mus_id_AllArbitrated_(false),
  mus_id_AllGlobalMuons_(0),
  b_mus_id_AllGlobalMuons_(NULL),
  c_mus_id_AllGlobalMuons_(false),
  mus_id_AllStandAloneMuons_(0),
  b_mus_id_AllStandAloneMuons_(NULL),
  c_mus_id_AllStandAloneMuons_(false),
  mus_id_AllTrackerMuons_(0),
  b_mus_id_AllTrackerMuons_(NULL),
  c_mus_id_AllTrackerMuons_(false),
  mus_id_GlobalMuonPromptTight_(0),
  b_mus_id_GlobalMuonPromptTight_(NULL),
  c_mus_id_GlobalMuonPromptTight_(false),
  mus_id_TM2DCompatibilityLoose_(0),
  b_mus_id_TM2DCompatibilityLoose_(NULL),
  c_mus_id_TM2DCompatibilityLoose_(false),
  mus_id_TM2DCompatibilityTight_(0),
  b_mus_id_TM2DCompatibilityTight_(NULL),
  c_mus_id_TM2DCompatibilityTight_(false),
  mus_id_TMLastStationLoose_(0),
  b_mus_id_TMLastStationLoose_(NULL),
  c_mus_id_TMLastStationLoose_(false),
  mus_id_TMLastStationOptimizedLowPtLoose_(0),
  b_mus_id_TMLastStationOptimizedLowPtLoose_(NULL),
  c_mus_id_TMLastStationOptimizedLowPtLoose_(false),
  mus_id_TMLastStationOptimizedLowPtTight_(0),
  b_mus_id_TMLastStationOptimizedLowPtTight_(NULL),
  c_mus_id_TMLastStationOptimizedLowPtTight_(false),
  mus_id_TMLastStationTight_(0),
  b_mus_id_TMLastStationTight_(NULL),
  c_mus_id_TMLastStationTight_(false),
  mus_id_TMOneStationLoose_(0),
  b_mus_id_TMOneStationLoose_(NULL),
  c_mus_id_TMOneStationLoose_(false),
  mus_id_TMOneStationTight_(0),
  b_mus_id_TMOneStationTight_(NULL),
  c_mus_id_TMOneStationTight_(false),
  mus_id_TrackerMuonArbitrated_(0),
  b_mus_id_TrackerMuonArbitrated_(NULL),
  c_mus_id_TrackerMuonArbitrated_(false),
  mus_isCaloMuon_(0),
  b_mus_isCaloMuon_(NULL),
  c_mus_isCaloMuon_(false),
  mus_isConvertedPhoton_(0),
  b_mus_isConvertedPhoton_(NULL),
  c_mus_isConvertedPhoton_(false),
  mus_isElectron_(0),
  b_mus_isElectron_(NULL),
  c_mus_isElectron_(false),
  mus_isGlobalMuon_(0),
  b_mus_isGlobalMuon_(NULL),
  c_mus_isGlobalMuon_(false),
  mus_isPFMuon_(0),
  b_mus_isPFMuon_(NULL),
  c_mus_isPFMuon_(false),
  mus_isPhoton_(0),
  b_mus_isPhoton_(NULL),
  c_mus_isPhoton_(false),
  mus_isStandAloneMuon_(0),
  b_mus_isStandAloneMuon_(NULL),
  c_mus_isStandAloneMuon_(false),
  mus_isTrackerMuon_(0),
  b_mus_isTrackerMuon_(NULL),
  c_mus_isTrackerMuon_(false),
  mus_iso03_emEt_(0),
  b_mus_iso03_emEt_(NULL),
  c_mus_iso03_emEt_(false),
  mus_iso03_emVetoEt_(0),
  b_mus_iso03_emVetoEt_(NULL),
  c_mus_iso03_emVetoEt_(false),
  mus_iso03_hadEt_(0),
  b_mus_iso03_hadEt_(NULL),
  c_mus_iso03_hadEt_(false),
  mus_iso03_hadVetoEt_(0),
  b_mus_iso03_hadVetoEt_(NULL),
  c_mus_iso03_hadVetoEt_(false),
  mus_iso03_hoEt_(0),
  b_mus_iso03_hoEt_(NULL),
  c_mus_iso03_hoEt_(false),
  mus_iso03_nTracks_(0),
  b_mus_iso03_nTracks_(NULL),
  c_mus_iso03_nTracks_(false),
  mus_iso03_sumPt_(0),
  b_mus_iso03_sumPt_(NULL),
  c_mus_iso03_sumPt_(false),
  mus_iso05_emEt_(0),
  b_mus_iso05_emEt_(NULL),
  c_mus_iso05_emEt_(false),
  mus_iso05_hadEt_(0),
  b_mus_iso05_hadEt_(NULL),
  c_mus_iso05_hadEt_(false),
  mus_iso05_hoEt_(0),
  b_mus_iso05_hoEt_(NULL),
  c_mus_iso05_hoEt_(false),
  mus_iso05_nTracks_(0),
  b_mus_iso05_nTracks_(NULL),
  c_mus_iso05_nTracks_(false),
  mus_iso05_sumPt_(0),
  b_mus_iso05_sumPt_(NULL),
  c_mus_iso05_sumPt_(false),
  mus_num_matches_(0),
  b_mus_num_matches_(NULL),
  c_mus_num_matches_(false),
  mus_numberOfMatchedStations_(0),
  b_mus_numberOfMatchedStations_(NULL),
  c_mus_numberOfMatchedStations_(false),
  mus_pfIsolationR03_sumChargedHadronPt_(0),
  b_mus_pfIsolationR03_sumChargedHadronPt_(NULL),
  c_mus_pfIsolationR03_sumChargedHadronPt_(false),
  mus_pfIsolationR03_sumChargedParticlePt_(0),
  b_mus_pfIsolationR03_sumChargedParticlePt_(NULL),
  c_mus_pfIsolationR03_sumChargedParticlePt_(false),
  mus_pfIsolationR03_sumNeutralHadronEt_(0),
  b_mus_pfIsolationR03_sumNeutralHadronEt_(NULL),
  c_mus_pfIsolationR03_sumNeutralHadronEt_(false),
  mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_(0),
  b_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_(NULL),
  c_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_(false),
  mus_pfIsolationR03_sumPUPt_(0),
  b_mus_pfIsolationR03_sumPUPt_(NULL),
  c_mus_pfIsolationR03_sumPUPt_(false),
  mus_pfIsolationR03_sumPhotonEt_(0),
  b_mus_pfIsolationR03_sumPhotonEt_(NULL),
  c_mus_pfIsolationR03_sumPhotonEt_(false),
  mus_pfIsolationR03_sumPhotonEtHighThreshold_(0),
  b_mus_pfIsolationR03_sumPhotonEtHighThreshold_(NULL),
  c_mus_pfIsolationR03_sumPhotonEtHighThreshold_(false),
  mus_pfIsolationR04_sumChargedHadronPt_(0),
  b_mus_pfIsolationR04_sumChargedHadronPt_(NULL),
  c_mus_pfIsolationR04_sumChargedHadronPt_(false),
  mus_pfIsolationR04_sumChargedParticlePt_(0),
  b_mus_pfIsolationR04_sumChargedParticlePt_(NULL),
  c_mus_pfIsolationR04_sumChargedParticlePt_(false),
  mus_pfIsolationR04_sumNeutralHadronEt_(0),
  b_mus_pfIsolationR04_sumNeutralHadronEt_(NULL),
  c_mus_pfIsolationR04_sumNeutralHadronEt_(false),
  mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_(0),
  b_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_(NULL),
  c_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_(false),
  mus_pfIsolationR04_sumPUPt_(0),
  b_mus_pfIsolationR04_sumPUPt_(NULL),
  c_mus_pfIsolationR04_sumPUPt_(false),
  mus_pfIsolationR04_sumPhotonEt_(0),
  b_mus_pfIsolationR04_sumPhotonEt_(NULL),
  c_mus_pfIsolationR04_sumPhotonEt_(false),
  mus_pfIsolationR04_sumPhotonEtHighThreshold_(0),
  b_mus_pfIsolationR04_sumPhotonEtHighThreshold_(NULL),
  c_mus_pfIsolationR04_sumPhotonEtHighThreshold_(false),
  mus_phi_(0),
  b_mus_phi_(NULL),
  c_mus_phi_(false),
  mus_picky_ExpectedHitsInner_(0),
  b_mus_picky_ExpectedHitsInner_(NULL),
  c_mus_picky_ExpectedHitsInner_(false),
  mus_picky_ExpectedHitsOuter_(0),
  b_mus_picky_ExpectedHitsOuter_(NULL),
  c_mus_picky_ExpectedHitsOuter_(false),
  mus_picky_LayersWithMeasurement_(0),
  b_mus_picky_LayersWithMeasurement_(NULL),
  c_mus_picky_LayersWithMeasurement_(false),
  mus_picky_LayersWithoutMeasurement_(0),
  b_mus_picky_LayersWithoutMeasurement_(NULL),
  c_mus_picky_LayersWithoutMeasurement_(false),
  mus_picky_PixelLayersWithMeasurement_(0),
  b_mus_picky_PixelLayersWithMeasurement_(NULL),
  c_mus_picky_PixelLayersWithMeasurement_(false),
  mus_picky_ValidStripLayersWithMonoAndStereoHit_(0),
  b_mus_picky_ValidStripLayersWithMonoAndStereoHit_(NULL),
  c_mus_picky_ValidStripLayersWithMonoAndStereoHit_(false),
  mus_picky_chg_(0),
  b_mus_picky_chg_(NULL),
  c_mus_picky_chg_(false),
  mus_picky_chi2_(0),
  b_mus_picky_chi2_(NULL),
  c_mus_picky_chi2_(false),
  mus_picky_d0dum_(0),
  b_mus_picky_d0dum_(NULL),
  c_mus_picky_d0dum_(false),
  mus_picky_d0dumErr_(0),
  b_mus_picky_d0dumErr_(NULL),
  c_mus_picky_d0dumErr_(false),
  mus_picky_dz_(0),
  b_mus_picky_dz_(NULL),
  c_mus_picky_dz_(false),
  mus_picky_dzErr_(0),
  b_mus_picky_dzErr_(NULL),
  c_mus_picky_dzErr_(false),
  mus_picky_eta_(0),
  b_mus_picky_eta_(NULL),
  c_mus_picky_eta_(false),
  mus_picky_etaErr_(0),
  b_mus_picky_etaErr_(NULL),
  c_mus_picky_etaErr_(false),
  mus_picky_id_(0),
  b_mus_picky_id_(NULL),
  c_mus_picky_id_(false),
  mus_picky_ndof_(0),
  b_mus_picky_ndof_(NULL),
  c_mus_picky_ndof_(false),
  mus_picky_numlosthits_(0),
  b_mus_picky_numlosthits_(NULL),
  c_mus_picky_numlosthits_(false),
  mus_picky_numvalPixelhits_(0),
  b_mus_picky_numvalPixelhits_(NULL),
  c_mus_picky_numvalPixelhits_(false),
  mus_picky_numvalhits_(0),
  b_mus_picky_numvalhits_(NULL),
  c_mus_picky_numvalhits_(false),
  mus_picky_phi_(0),
  b_mus_picky_phi_(NULL),
  c_mus_picky_phi_(false),
  mus_picky_phiErr_(0),
  b_mus_picky_phiErr_(NULL),
  c_mus_picky_phiErr_(false),
  mus_picky_pt_(0),
  b_mus_picky_pt_(NULL),
  c_mus_picky_pt_(false),
  mus_picky_ptErr_(0),
  b_mus_picky_ptErr_(NULL),
  c_mus_picky_ptErr_(false),
  mus_picky_px_(0),
  b_mus_picky_px_(NULL),
  c_mus_picky_px_(false),
  mus_picky_py_(0),
  b_mus_picky_py_(NULL),
  c_mus_picky_py_(false),
  mus_picky_pz_(0),
  b_mus_picky_pz_(NULL),
  c_mus_picky_pz_(false),
  mus_picky_theta_(0),
  b_mus_picky_theta_(NULL),
  c_mus_picky_theta_(false),
  mus_picky_vx_(0),
  b_mus_picky_vx_(NULL),
  c_mus_picky_vx_(false),
  mus_picky_vy_(0),
  b_mus_picky_vy_(NULL),
  c_mus_picky_vy_(false),
  mus_picky_vz_(0),
  b_mus_picky_vz_(NULL),
  c_mus_picky_vz_(false),
  mus_pt_(0),
  b_mus_pt_(NULL),
  c_mus_pt_(false),
  mus_px_(0),
  b_mus_px_(NULL),
  c_mus_px_(false),
  mus_py_(0),
  b_mus_py_(NULL),
  c_mus_py_(false),
  mus_pz_(0),
  b_mus_pz_(NULL),
  c_mus_pz_(false),
  mus_stamu_chg_(0),
  b_mus_stamu_chg_(NULL),
  c_mus_stamu_chg_(false),
  mus_stamu_chi2_(0),
  b_mus_stamu_chi2_(NULL),
  c_mus_stamu_chi2_(false),
  mus_stamu_d0dum_(0),
  b_mus_stamu_d0dum_(NULL),
  c_mus_stamu_d0dum_(false),
  mus_stamu_d0dumErr_(0),
  b_mus_stamu_d0dumErr_(NULL),
  c_mus_stamu_d0dumErr_(false),
  mus_stamu_dz_(0),
  b_mus_stamu_dz_(NULL),
  c_mus_stamu_dz_(false),
  mus_stamu_dzErr_(0),
  b_mus_stamu_dzErr_(NULL),
  c_mus_stamu_dzErr_(false),
  mus_stamu_eta_(0),
  b_mus_stamu_eta_(NULL),
  c_mus_stamu_eta_(false),
  mus_stamu_etaErr_(0),
  b_mus_stamu_etaErr_(NULL),
  c_mus_stamu_etaErr_(false),
  mus_stamu_ndof_(0),
  b_mus_stamu_ndof_(NULL),
  c_mus_stamu_ndof_(false),
  mus_stamu_numlosthits_(0),
  b_mus_stamu_numlosthits_(NULL),
  c_mus_stamu_numlosthits_(false),
  mus_stamu_numvalhits_(0),
  b_mus_stamu_numvalhits_(NULL),
  c_mus_stamu_numvalhits_(false),
  mus_stamu_phi_(0),
  b_mus_stamu_phi_(NULL),
  c_mus_stamu_phi_(false),
  mus_stamu_phiErr_(0),
  b_mus_stamu_phiErr_(NULL),
  c_mus_stamu_phiErr_(false),
  mus_stamu_pt_(0),
  b_mus_stamu_pt_(NULL),
  c_mus_stamu_pt_(false),
  mus_stamu_ptErr_(0),
  b_mus_stamu_ptErr_(NULL),
  c_mus_stamu_ptErr_(false),
  mus_stamu_px_(0),
  b_mus_stamu_px_(NULL),
  c_mus_stamu_px_(false),
  mus_stamu_py_(0),
  b_mus_stamu_py_(NULL),
  c_mus_stamu_py_(false),
  mus_stamu_pz_(0),
  b_mus_stamu_pz_(NULL),
  c_mus_stamu_pz_(false),
  mus_stamu_theta_(0),
  b_mus_stamu_theta_(NULL),
  c_mus_stamu_theta_(false),
  mus_stamu_vx_(0),
  b_mus_stamu_vx_(NULL),
  c_mus_stamu_vx_(false),
  mus_stamu_vy_(0),
  b_mus_stamu_vy_(NULL),
  c_mus_stamu_vy_(false),
  mus_stamu_vz_(0),
  b_mus_stamu_vz_(NULL),
  c_mus_stamu_vz_(false),
  mus_status_(0),
  b_mus_status_(NULL),
  c_mus_status_(false),
  mus_tIso_(0),
  b_mus_tIso_(NULL),
  c_mus_tIso_(false),
  mus_theta_(0),
  b_mus_theta_(NULL),
  c_mus_theta_(false),
  mus_tkHits_(0),
  b_mus_tkHits_(NULL),
  c_mus_tkHits_(false),
  mus_tk_ExpectedHitsInner_(0),
  b_mus_tk_ExpectedHitsInner_(NULL),
  c_mus_tk_ExpectedHitsInner_(false),
  mus_tk_ExpectedHitsOuter_(0),
  b_mus_tk_ExpectedHitsOuter_(NULL),
  c_mus_tk_ExpectedHitsOuter_(false),
  mus_tk_LayersWithMeasurement_(0),
  b_mus_tk_LayersWithMeasurement_(NULL),
  c_mus_tk_LayersWithMeasurement_(false),
  mus_tk_LayersWithoutMeasurement_(0),
  b_mus_tk_LayersWithoutMeasurement_(NULL),
  c_mus_tk_LayersWithoutMeasurement_(false),
  mus_tk_PixelLayersWithMeasurement_(0),
  b_mus_tk_PixelLayersWithMeasurement_(NULL),
  c_mus_tk_PixelLayersWithMeasurement_(false),
  mus_tk_ValidStripLayersWithMonoAndStereoHit_(0),
  b_mus_tk_ValidStripLayersWithMonoAndStereoHit_(NULL),
  c_mus_tk_ValidStripLayersWithMonoAndStereoHit_(false),
  mus_tk_chg_(0),
  b_mus_tk_chg_(NULL),
  c_mus_tk_chg_(false),
  mus_tk_chi2_(0),
  b_mus_tk_chi2_(NULL),
  c_mus_tk_chi2_(false),
  mus_tk_d0dum_(0),
  b_mus_tk_d0dum_(NULL),
  c_mus_tk_d0dum_(false),
  mus_tk_d0dumErr_(0),
  b_mus_tk_d0dumErr_(NULL),
  c_mus_tk_d0dumErr_(false),
  mus_tk_dz_(0),
  b_mus_tk_dz_(NULL),
  c_mus_tk_dz_(false),
  mus_tk_dzErr_(0),
  b_mus_tk_dzErr_(NULL),
  c_mus_tk_dzErr_(false),
  mus_tk_eta_(0),
  b_mus_tk_eta_(NULL),
  c_mus_tk_eta_(false),
  mus_tk_etaErr_(0),
  b_mus_tk_etaErr_(NULL),
  c_mus_tk_etaErr_(false),
  mus_tk_id_(0),
  b_mus_tk_id_(NULL),
  c_mus_tk_id_(false),
  mus_tk_ndof_(0),
  b_mus_tk_ndof_(NULL),
  c_mus_tk_ndof_(false),
  mus_tk_numlosthits_(0),
  b_mus_tk_numlosthits_(NULL),
  c_mus_tk_numlosthits_(false),
  mus_tk_numpixelWthMeasr_(0),
  b_mus_tk_numpixelWthMeasr_(NULL),
  c_mus_tk_numpixelWthMeasr_(false),
  mus_tk_numvalPixelhits_(0),
  b_mus_tk_numvalPixelhits_(NULL),
  c_mus_tk_numvalPixelhits_(false),
  mus_tk_numvalhits_(0),
  b_mus_tk_numvalhits_(NULL),
  c_mus_tk_numvalhits_(false),
  mus_tk_phi_(0),
  b_mus_tk_phi_(NULL),
  c_mus_tk_phi_(false),
  mus_tk_phiErr_(0),
  b_mus_tk_phiErr_(NULL),
  c_mus_tk_phiErr_(false),
  mus_tk_pt_(0),
  b_mus_tk_pt_(NULL),
  c_mus_tk_pt_(false),
  mus_tk_ptErr_(0),
  b_mus_tk_ptErr_(NULL),
  c_mus_tk_ptErr_(false),
  mus_tk_px_(0),
  b_mus_tk_px_(NULL),
  c_mus_tk_px_(false),
  mus_tk_py_(0),
  b_mus_tk_py_(NULL),
  c_mus_tk_py_(false),
  mus_tk_pz_(0),
  b_mus_tk_pz_(NULL),
  c_mus_tk_pz_(false),
  mus_tk_theta_(0),
  b_mus_tk_theta_(NULL),
  c_mus_tk_theta_(false),
  mus_tk_vx_(0),
  b_mus_tk_vx_(NULL),
  c_mus_tk_vx_(false),
  mus_tk_vy_(0),
  b_mus_tk_vy_(NULL),
  c_mus_tk_vy_(false),
  mus_tk_vz_(0),
  b_mus_tk_vz_(NULL),
  c_mus_tk_vz_(false),
  mus_tpfms_ExpectedHitsInner_(0),
  b_mus_tpfms_ExpectedHitsInner_(NULL),
  c_mus_tpfms_ExpectedHitsInner_(false),
  mus_tpfms_ExpectedHitsOuter_(0),
  b_mus_tpfms_ExpectedHitsOuter_(NULL),
  c_mus_tpfms_ExpectedHitsOuter_(false),
  mus_tpfms_LayersWithMeasurement_(0),
  b_mus_tpfms_LayersWithMeasurement_(NULL),
  c_mus_tpfms_LayersWithMeasurement_(false),
  mus_tpfms_LayersWithoutMeasurement_(0),
  b_mus_tpfms_LayersWithoutMeasurement_(NULL),
  c_mus_tpfms_LayersWithoutMeasurement_(false),
  mus_tpfms_PixelLayersWithMeasurement_(0),
  b_mus_tpfms_PixelLayersWithMeasurement_(NULL),
  c_mus_tpfms_PixelLayersWithMeasurement_(false),
  mus_tpfms_ValidStripLayersWithMonoAndStereoHit_(0),
  b_mus_tpfms_ValidStripLayersWithMonoAndStereoHit_(NULL),
  c_mus_tpfms_ValidStripLayersWithMonoAndStereoHit_(false),
  mus_tpfms_chg_(0),
  b_mus_tpfms_chg_(NULL),
  c_mus_tpfms_chg_(false),
  mus_tpfms_chi2_(0),
  b_mus_tpfms_chi2_(NULL),
  c_mus_tpfms_chi2_(false),
  mus_tpfms_d0dum_(0),
  b_mus_tpfms_d0dum_(NULL),
  c_mus_tpfms_d0dum_(false),
  mus_tpfms_d0dumErr_(0),
  b_mus_tpfms_d0dumErr_(NULL),
  c_mus_tpfms_d0dumErr_(false),
  mus_tpfms_dz_(0),
  b_mus_tpfms_dz_(NULL),
  c_mus_tpfms_dz_(false),
  mus_tpfms_dzErr_(0),
  b_mus_tpfms_dzErr_(NULL),
  c_mus_tpfms_dzErr_(false),
  mus_tpfms_eta_(0),
  b_mus_tpfms_eta_(NULL),
  c_mus_tpfms_eta_(false),
  mus_tpfms_etaErr_(0),
  b_mus_tpfms_etaErr_(NULL),
  c_mus_tpfms_etaErr_(false),
  mus_tpfms_id_(0),
  b_mus_tpfms_id_(NULL),
  c_mus_tpfms_id_(false),
  mus_tpfms_ndof_(0),
  b_mus_tpfms_ndof_(NULL),
  c_mus_tpfms_ndof_(false),
  mus_tpfms_numlosthits_(0),
  b_mus_tpfms_numlosthits_(NULL),
  c_mus_tpfms_numlosthits_(false),
  mus_tpfms_numvalPixelhits_(0),
  b_mus_tpfms_numvalPixelhits_(NULL),
  c_mus_tpfms_numvalPixelhits_(false),
  mus_tpfms_numvalhits_(0),
  b_mus_tpfms_numvalhits_(NULL),
  c_mus_tpfms_numvalhits_(false),
  mus_tpfms_phi_(0),
  b_mus_tpfms_phi_(NULL),
  c_mus_tpfms_phi_(false),
  mus_tpfms_phiErr_(0),
  b_mus_tpfms_phiErr_(NULL),
  c_mus_tpfms_phiErr_(false),
  mus_tpfms_pt_(0),
  b_mus_tpfms_pt_(NULL),
  c_mus_tpfms_pt_(false),
  mus_tpfms_ptErr_(0),
  b_mus_tpfms_ptErr_(NULL),
  c_mus_tpfms_ptErr_(false),
  mus_tpfms_px_(0),
  b_mus_tpfms_px_(NULL),
  c_mus_tpfms_px_(false),
  mus_tpfms_py_(0),
  b_mus_tpfms_py_(NULL),
  c_mus_tpfms_py_(false),
  mus_tpfms_pz_(0),
  b_mus_tpfms_pz_(NULL),
  c_mus_tpfms_pz_(false),
  mus_tpfms_theta_(0),
  b_mus_tpfms_theta_(NULL),
  c_mus_tpfms_theta_(false),
  mus_tpfms_vx_(0),
  b_mus_tpfms_vx_(NULL),
  c_mus_tpfms_vx_(false),
  mus_tpfms_vy_(0),
  b_mus_tpfms_vy_(NULL),
  c_mus_tpfms_vy_(false),
  mus_tpfms_vz_(0),
  b_mus_tpfms_vz_(NULL),
  c_mus_tpfms_vz_(false),
  orbitNumber_(0),
  b_orbitNumber_(NULL),
  c_orbitNumber_(false),
  pfcand_charge_(0),
  b_pfcand_charge_(NULL),
  c_pfcand_charge_(false),
  pfcand_energy_(0),
  b_pfcand_energy_(NULL),
  c_pfcand_energy_(false),
  pfcand_eta_(0),
  b_pfcand_eta_(NULL),
  c_pfcand_eta_(false),
  pfcand_pdgId_(0),
  b_pfcand_pdgId_(NULL),
  c_pfcand_pdgId_(false),
  pfcand_phi_(0),
  b_pfcand_phi_(NULL),
  c_pfcand_phi_(false),
  pfcand_pt_(0),
  b_pfcand_pt_(NULL),
  c_pfcand_pt_(false),
  pfcand_px_(0),
  b_pfcand_px_(NULL),
  c_pfcand_px_(false),
  pfcand_py_(0),
  b_pfcand_py_(NULL),
  c_pfcand_py_(false),
  pfcand_pz_(0),
  b_pfcand_pz_(NULL),
  c_pfcand_pz_(false),
  pfcand_theta_(0),
  b_pfcand_theta_(NULL),
  c_pfcand_theta_(false),
  photons_e1x5_(0),
  b_photons_e1x5_(NULL),
  c_photons_e1x5_(false),
  photons_e2x5_(0),
  b_photons_e2x5_(NULL),
  c_photons_e2x5_(false),
  photons_e3x3_(0),
  b_photons_e3x3_(NULL),
  c_photons_e3x3_(false),
  photons_e5x5_(0),
  b_photons_e5x5_(NULL),
  c_photons_e5x5_(false),
  photons_ecalIso_(0),
  b_photons_ecalIso_(NULL),
  c_photons_ecalIso_(false),
  photons_energy_(0),
  b_photons_energy_(NULL),
  c_photons_energy_(false),
  photons_et_(0),
  b_photons_et_(NULL),
  c_photons_et_(false),
  photons_eta_(0),
  b_photons_eta_(NULL),
  c_photons_eta_(false),
  photons_gen_et_(0),
  b_photons_gen_et_(NULL),
  c_photons_gen_et_(false),
  photons_gen_eta_(0),
  b_photons_gen_eta_(NULL),
  c_photons_gen_eta_(false),
  photons_gen_id_(0),
  b_photons_gen_id_(NULL),
  c_photons_gen_id_(false),
  photons_gen_phi_(0),
  b_photons_gen_phi_(NULL),
  c_photons_gen_phi_(false),
  photons_hadOverEM_(0),
  b_photons_hadOverEM_(NULL),
  c_photons_hadOverEM_(false),
  photons_hadTowOverEM_(0),
  b_photons_hadTowOverEM_(NULL),
  c_photons_hadTowOverEM_(false),
  photons_hasPixelSeed_(0),
  b_photons_hasPixelSeed_(NULL),
  c_photons_hasPixelSeed_(false),
  photons_hcalIso_(0),
  b_photons_hcalIso_(NULL),
  c_photons_hcalIso_(false),
  photons_isAlsoElectron_(0),
  b_photons_isAlsoElectron_(NULL),
  c_photons_isAlsoElectron_(false),
  photons_isConverted_(0),
  b_photons_isConverted_(NULL),
  c_photons_isConverted_(false),
  photons_isEBEEGap_(0),
  b_photons_isEBEEGap_(NULL),
  c_photons_isEBEEGap_(false),
  photons_isEBGap_(0),
  b_photons_isEBGap_(NULL),
  c_photons_isEBGap_(false),
  photons_isEBPho_(0),
  b_photons_isEBPho_(NULL),
  c_photons_isEBPho_(false),
  photons_isEEGap_(0),
  b_photons_isEEGap_(NULL),
  c_photons_isEEGap_(false),
  photons_isEEPho_(0),
  b_photons_isEEPho_(NULL),
  c_photons_isEEPho_(false),
  photons_isLoosePhoton_(0),
  b_photons_isLoosePhoton_(NULL),
  c_photons_isLoosePhoton_(false),
  photons_isTightPhoton_(0),
  b_photons_isTightPhoton_(NULL),
  c_photons_isTightPhoton_(false),
  photons_isoEcalRecHitDR03_(0),
  b_photons_isoEcalRecHitDR03_(NULL),
  c_photons_isoEcalRecHitDR03_(false),
  photons_isoEcalRecHitDR04_(0),
  b_photons_isoEcalRecHitDR04_(NULL),
  c_photons_isoEcalRecHitDR04_(false),
  photons_isoHcalRecHitDR03_(0),
  b_photons_isoHcalRecHitDR03_(NULL),
  c_photons_isoHcalRecHitDR03_(false),
  photons_isoHcalRecHitDR04_(0),
  b_photons_isoHcalRecHitDR04_(NULL),
  c_photons_isoHcalRecHitDR04_(false),
  photons_isoHollowTrkConeDR03_(0),
  b_photons_isoHollowTrkConeDR03_(NULL),
  c_photons_isoHollowTrkConeDR03_(false),
  photons_isoHollowTrkConeDR04_(0),
  b_photons_isoHollowTrkConeDR04_(NULL),
  c_photons_isoHollowTrkConeDR04_(false),
  photons_isoSolidTrkConeDR03_(0),
  b_photons_isoSolidTrkConeDR03_(NULL),
  c_photons_isoSolidTrkConeDR03_(false),
  photons_isoSolidTrkConeDR04_(0),
  b_photons_isoSolidTrkConeDR04_(NULL),
  c_photons_isoSolidTrkConeDR04_(false),
  photons_maxEnergyXtal_(0),
  b_photons_maxEnergyXtal_(NULL),
  c_photons_maxEnergyXtal_(false),
  photons_nTrkHollowConeDR03_(0),
  b_photons_nTrkHollowConeDR03_(NULL),
  c_photons_nTrkHollowConeDR03_(false),
  photons_nTrkHollowConeDR04_(0),
  b_photons_nTrkHollowConeDR04_(NULL),
  c_photons_nTrkHollowConeDR04_(false),
  photons_nTrkSolidConeDR03_(0),
  b_photons_nTrkSolidConeDR03_(NULL),
  c_photons_nTrkSolidConeDR03_(false),
  photons_nTrkSolidConeDR04_(0),
  b_photons_nTrkSolidConeDR04_(NULL),
  c_photons_nTrkSolidConeDR04_(false),
  photons_phi_(0),
  b_photons_phi_(NULL),
  c_photons_phi_(false),
  photons_pt_(0),
  b_photons_pt_(NULL),
  c_photons_pt_(false),
  photons_px_(0),
  b_photons_px_(NULL),
  c_photons_px_(false),
  photons_py_(0),
  b_photons_py_(NULL),
  c_photons_py_(false),
  photons_pz_(0),
  b_photons_pz_(NULL),
  c_photons_pz_(false),
  photons_r9_(0),
  b_photons_r9_(NULL),
  c_photons_r9_(false),
  photons_scEnergy_(0),
  b_photons_scEnergy_(NULL),
  c_photons_scEnergy_(false),
  photons_scEta_(0),
  b_photons_scEta_(NULL),
  c_photons_scEta_(false),
  photons_scEtaWidth_(0),
  b_photons_scEtaWidth_(NULL),
  c_photons_scEtaWidth_(false),
  photons_scPhi_(0),
  b_photons_scPhi_(NULL),
  c_photons_scPhi_(false),
  photons_scPhiWidth_(0),
  b_photons_scPhiWidth_(NULL),
  c_photons_scPhiWidth_(false),
  photons_scRawEnergy_(0),
  b_photons_scRawEnergy_(NULL),
  c_photons_scRawEnergy_(false),
  photons_sigmaEtaEta_(0),
  b_photons_sigmaEtaEta_(NULL),
  c_photons_sigmaEtaEta_(false),
  photons_sigmaIetaIeta_(0),
  b_photons_sigmaIetaIeta_(NULL),
  c_photons_sigmaIetaIeta_(false),
  photons_status_(0),
  b_photons_status_(NULL),
  c_photons_status_(false),
  photons_tIso_(0),
  b_photons_tIso_(NULL),
  c_photons_tIso_(false),
  photons_theta_(0),
  b_photons_theta_(NULL),
  c_photons_theta_(false),
  pv_chi2_(0),
  b_pv_chi2_(NULL),
  c_pv_chi2_(false),
  pv_isFake_(0),
  b_pv_isFake_(NULL),
  c_pv_isFake_(false),
  pv_isValid_(0),
  b_pv_isValid_(NULL),
  c_pv_isValid_(false),
  pv_ndof_(0),
  b_pv_ndof_(NULL),
  c_pv_ndof_(false),
  pv_tracksSize_(0),
  b_pv_tracksSize_(NULL),
  c_pv_tracksSize_(false),
  pv_x_(0),
  b_pv_x_(NULL),
  c_pv_x_(false),
  pv_xErr_(0),
  b_pv_xErr_(NULL),
  c_pv_xErr_(false),
  pv_y_(0),
  b_pv_y_(NULL),
  c_pv_y_(false),
  pv_yErr_(0),
  b_pv_yErr_(NULL),
  c_pv_yErr_(false),
  pv_z_(0),
  b_pv_z_(NULL),
  c_pv_z_(false),
  pv_zErr_(0),
  b_pv_zErr_(NULL),
  c_pv_zErr_(false),
  run_(0),
  b_run_(NULL),
  c_run_(false),
  standalone_triggerobject_collectionname_(0),
  b_standalone_triggerobject_collectionname_(NULL),
  c_standalone_triggerobject_collectionname_(false),
  standalone_triggerobject_energy_(0),
  b_standalone_triggerobject_energy_(NULL),
  c_standalone_triggerobject_energy_(false),
  standalone_triggerobject_et_(0),
  b_standalone_triggerobject_et_(NULL),
  c_standalone_triggerobject_et_(false),
  standalone_triggerobject_eta_(0),
  b_standalone_triggerobject_eta_(NULL),
  c_standalone_triggerobject_eta_(false),
  standalone_triggerobject_phi_(0),
  b_standalone_triggerobject_phi_(NULL),
  c_standalone_triggerobject_phi_(false),
  standalone_triggerobject_pt_(0),
  b_standalone_triggerobject_pt_(NULL),
  c_standalone_triggerobject_pt_(false),
  standalone_triggerobject_px_(0),
  b_standalone_triggerobject_px_(NULL),
  c_standalone_triggerobject_px_(false),
  standalone_triggerobject_py_(0),
  b_standalone_triggerobject_py_(NULL),
  c_standalone_triggerobject_py_(false),
  standalone_triggerobject_pz_(0),
  b_standalone_triggerobject_pz_(NULL),
  c_standalone_triggerobject_pz_(false),
  taus_Nprongs_(0),
  b_taus_Nprongs_(NULL),
  c_taus_Nprongs_(false),
  taus_againstElectron_(0),
  b_taus_againstElectron_(NULL),
  c_taus_againstElectron_(false),
  taus_againstElectronLoose_(0),
  b_taus_againstElectronLoose_(NULL),
  c_taus_againstElectronLoose_(false),
  taus_againstElectronMVA_(0),
  b_taus_againstElectronMVA_(NULL),
  c_taus_againstElectronMVA_(false),
  taus_againstElectronMedium_(0),
  b_taus_againstElectronMedium_(NULL),
  c_taus_againstElectronMedium_(false),
  taus_againstElectronTight_(0),
  b_taus_againstElectronTight_(NULL),
  c_taus_againstElectronTight_(false),
  taus_againstMuon_(0),
  b_taus_againstMuon_(NULL),
  c_taus_againstMuon_(false),
  taus_againstMuonLoose_(0),
  b_taus_againstMuonLoose_(NULL),
  c_taus_againstMuonLoose_(false),
  taus_againstMuonMedium_(0),
  b_taus_againstMuonMedium_(NULL),
  c_taus_againstMuonMedium_(false),
  taus_againstMuonTight_(0),
  b_taus_againstMuonTight_(NULL),
  c_taus_againstMuonTight_(false),
  taus_byIsoUsingLeadingPi_(0),
  b_taus_byIsoUsingLeadingPi_(NULL),
  c_taus_byIsoUsingLeadingPi_(false),
  taus_byIsolation_(0),
  b_taus_byIsolation_(NULL),
  c_taus_byIsolation_(false),
  taus_byLooseIsolation_(0),
  b_taus_byLooseIsolation_(NULL),
  c_taus_byLooseIsolation_(false),
  taus_byLooseIsolationDeltaBetaCorr_(0),
  b_taus_byLooseIsolationDeltaBetaCorr_(NULL),
  c_taus_byLooseIsolationDeltaBetaCorr_(false),
  taus_byMediumIsolation_(0),
  b_taus_byMediumIsolation_(NULL),
  c_taus_byMediumIsolation_(false),
  taus_byMediumIsolationDeltaBetaCorr_(0),
  b_taus_byMediumIsolationDeltaBetaCorr_(NULL),
  c_taus_byMediumIsolationDeltaBetaCorr_(false),
  taus_byTightIsolation_(0),
  b_taus_byTightIsolation_(NULL),
  c_taus_byTightIsolation_(false),
  taus_byTightIsolationDeltaBetaCorr_(0),
  b_taus_byTightIsolationDeltaBetaCorr_(NULL),
  c_taus_byTightIsolationDeltaBetaCorr_(false),
  taus_byVLooseIsolation_(0),
  b_taus_byVLooseIsolation_(NULL),
  c_taus_byVLooseIsolation_(false),
  taus_byVLooseIsolationDeltaBetaCorr_(0),
  b_taus_byVLooseIsolationDeltaBetaCorr_(NULL),
  c_taus_byVLooseIsolationDeltaBetaCorr_(false),
  taus_charge_(0),
  b_taus_charge_(NULL),
  c_taus_charge_(false),
  taus_decayModeFinding_(0),
  b_taus_decayModeFinding_(NULL),
  c_taus_decayModeFinding_(false),
  taus_ecalIsoUsingLeadingPi_(0),
  b_taus_ecalIsoUsingLeadingPi_(NULL),
  c_taus_ecalIsoUsingLeadingPi_(false),
  taus_ecalIsolation_(0),
  b_taus_ecalIsolation_(NULL),
  c_taus_ecalIsolation_(false),
  taus_ecalStripSumEOverPLead_(0),
  b_taus_ecalStripSumEOverPLead_(NULL),
  c_taus_ecalStripSumEOverPLead_(false),
  taus_elecPreIdDecision_(0),
  b_taus_elecPreIdDecision_(NULL),
  c_taus_elecPreIdDecision_(false),
  taus_elecPreIdOutput_(0),
  b_taus_elecPreIdOutput_(NULL),
  c_taus_elecPreIdOutput_(false),
  taus_emf_(0),
  b_taus_emf_(NULL),
  c_taus_emf_(false),
  taus_energy_(0),
  b_taus_energy_(NULL),
  c_taus_energy_(false),
  taus_et_(0),
  b_taus_et_(NULL),
  c_taus_et_(false),
  taus_eta_(0),
  b_taus_eta_(NULL),
  c_taus_eta_(false),
  taus_hcal3x3OverPLead_(0),
  b_taus_hcal3x3OverPLead_(NULL),
  c_taus_hcal3x3OverPLead_(false),
  taus_hcalMaxOverPLead_(0),
  b_taus_hcalMaxOverPLead_(NULL),
  c_taus_hcalMaxOverPLead_(false),
  taus_hcalTotOverPLead_(0),
  b_taus_hcalTotOverPLead_(NULL),
  c_taus_hcalTotOverPLead_(false),
  taus_isoPFChargedHadrCandsPtSum_(0),
  b_taus_isoPFChargedHadrCandsPtSum_(NULL),
  c_taus_isoPFChargedHadrCandsPtSum_(false),
  taus_isoPFGammaCandsEtSum_(0),
  b_taus_isoPFGammaCandsEtSum_(NULL),
  c_taus_isoPFGammaCandsEtSum_(false),
  taus_leadPFChargedHadrCand_ECAL_eta_(0),
  b_taus_leadPFChargedHadrCand_ECAL_eta_(NULL),
  c_taus_leadPFChargedHadrCand_ECAL_eta_(false),
  taus_leadPFChargedHadrCand_charge_(0),
  b_taus_leadPFChargedHadrCand_charge_(NULL),
  c_taus_leadPFChargedHadrCand_charge_(false),
  taus_leadPFChargedHadrCand_eta_(0),
  b_taus_leadPFChargedHadrCand_eta_(NULL),
  c_taus_leadPFChargedHadrCand_eta_(false),
  taus_leadPFChargedHadrCand_phi_(0),
  b_taus_leadPFChargedHadrCand_phi_(NULL),
  c_taus_leadPFChargedHadrCand_phi_(false),
  taus_leadPFChargedHadrCand_pt_(0),
  b_taus_leadPFChargedHadrCand_pt_(NULL),
  c_taus_leadPFChargedHadrCand_pt_(false),
  taus_leadingTrackFinding_(0),
  b_taus_leadingTrackFinding_(NULL),
  c_taus_leadingTrackFinding_(false),
  taus_leadingTrackPtCut_(0),
  b_taus_leadingTrackPtCut_(NULL),
  c_taus_leadingTrackPtCut_(false),
  taus_muDecision_(0),
  b_taus_muDecision_(NULL),
  c_taus_muDecision_(false),
  taus_phi_(0),
  b_taus_phi_(NULL),
  c_taus_phi_(false),
  taus_pt_(0),
  b_taus_pt_(NULL),
  c_taus_pt_(false),
  taus_px_(0),
  b_taus_px_(NULL),
  c_taus_px_(false),
  taus_py_(0),
  b_taus_py_(NULL),
  c_taus_py_(false),
  taus_pz_(0),
  b_taus_pz_(NULL),
  c_taus_pz_(false),
  taus_signalPFChargedHadrCandsSize_(0),
  b_taus_signalPFChargedHadrCandsSize_(NULL),
  c_taus_signalPFChargedHadrCandsSize_(false),
  taus_status_(0),
  b_taus_status_(NULL),
  c_taus_status_(false),
  taus_taNC_(0),
  b_taus_taNC_(NULL),
  c_taus_taNC_(false),
  taus_taNC_half_(0),
  b_taus_taNC_half_(NULL),
  c_taus_taNC_half_(false),
  taus_taNC_one_(0),
  b_taus_taNC_one_(NULL),
  c_taus_taNC_one_(false),
  taus_taNC_quarter_(0),
  b_taus_taNC_quarter_(NULL),
  c_taus_taNC_quarter_(false),
  taus_taNC_tenth_(0),
  b_taus_taNC_tenth_(NULL),
  c_taus_taNC_tenth_(false),
  taus_theta_(0),
  b_taus_theta_(NULL),
  c_taus_theta_(false),
  taus_tkIsoUsingLeadingPi_(0),
  b_taus_tkIsoUsingLeadingPi_(NULL),
  c_taus_tkIsoUsingLeadingPi_(false),
  taus_trackIsolation_(0),
  b_taus_trackIsolation_(NULL),
  c_taus_trackIsolation_(false),
  trackingfailurefilter_decision_(0),
  b_trackingfailurefilter_decision_(NULL),
  c_trackingfailurefilter_decision_(false),
  trigger_name_(0),
  b_trigger_name_(NULL),
  c_trigger_name_(false),
  trigger_prescalevalue_(0),
  b_trigger_prescalevalue_(NULL),
  c_trigger_prescalevalue_(false),
  weight_(0),
  b_weight_(NULL),
  c_weight_(false){
  GetVersion();
  AddFiles(file);
  PrepareNewChains();
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
  if(b_NbeamSpot_ && !b_NbeamSpot_->TestBit(kDoNotProcess)){
    c_NbeamSpot_ = true;
  }else{
    c_NbeamSpot_ = false;
  }
  if(b_Nels_ && !b_Nels_->TestBit(kDoNotProcess)){
    c_Nels_ = true;
  }else{
    c_Nels_ = false;
  }
  if(b_Nmc_doc_ && !b_Nmc_doc_->TestBit(kDoNotProcess)){
    c_Nmc_doc_ = true;
  }else{
    c_Nmc_doc_ = false;
  }
  if(b_Nmc_electrons_ && !b_Nmc_electrons_->TestBit(kDoNotProcess)){
    c_Nmc_electrons_ = true;
  }else{
    c_Nmc_electrons_ = false;
  }
  if(b_Nmc_mus_ && !b_Nmc_mus_->TestBit(kDoNotProcess)){
    c_Nmc_mus_ = true;
  }else{
    c_Nmc_mus_ = false;
  }
  if(b_Nmc_nues_ && !b_Nmc_nues_->TestBit(kDoNotProcess)){
    c_Nmc_nues_ = true;
  }else{
    c_Nmc_nues_ = false;
  }
  if(b_Nmc_numus_ && !b_Nmc_numus_->TestBit(kDoNotProcess)){
    c_Nmc_numus_ = true;
  }else{
    c_Nmc_numus_ = false;
  }
  if(b_Nmc_nutaus_ && !b_Nmc_nutaus_->TestBit(kDoNotProcess)){
    c_Nmc_nutaus_ = true;
  }else{
    c_Nmc_nutaus_ = false;
  }
  if(b_Nmc_photons_ && !b_Nmc_photons_->TestBit(kDoNotProcess)){
    c_Nmc_photons_ = true;
  }else{
    c_Nmc_photons_ = false;
  }
  if(b_Nmc_taus_ && !b_Nmc_taus_->TestBit(kDoNotProcess)){
    c_Nmc_taus_ = true;
  }else{
    c_Nmc_taus_ = false;
  }
  if(b_Nmus_ && !b_Nmus_->TestBit(kDoNotProcess)){
    c_Nmus_ = true;
  }else{
    c_Nmus_ = false;
  }
  if(b_Npfcand_ && !b_Npfcand_->TestBit(kDoNotProcess)){
    c_Npfcand_ = true;
  }else{
    c_Npfcand_ = false;
  }
  if(b_Nphotons_ && !b_Nphotons_->TestBit(kDoNotProcess)){
    c_Nphotons_ = true;
  }else{
    c_Nphotons_ = false;
  }
  if(b_Npv_ && !b_Npv_->TestBit(kDoNotProcess)){
    c_Npv_ = true;
  }else{
    c_Npv_ = false;
  }
  if(b_Ntaus_ && !b_Ntaus_->TestBit(kDoNotProcess)){
    c_Ntaus_ = true;
  }else{
    c_Ntaus_ = false;
  }
  if(b_PU_NumInteractions_ && !b_PU_NumInteractions_->TestBit(kDoNotProcess)){
    c_PU_NumInteractions_ = true;
  }else{
    c_PU_NumInteractions_ = false;
  }
  if(b_PU_TrueNumInteractions_ && !b_PU_TrueNumInteractions_->TestBit(kDoNotProcess)){
    c_PU_TrueNumInteractions_ = true;
  }else{
    c_PU_TrueNumInteractions_ = false;
  }
  if(b_PU_bunchCrossing_ && !b_PU_bunchCrossing_->TestBit(kDoNotProcess)){
    c_PU_bunchCrossing_ = true;
  }else{
    c_PU_bunchCrossing_ = false;
  }
  if(b_PU_ntrks_highpT_ && !b_PU_ntrks_highpT_->TestBit(kDoNotProcess)){
    c_PU_ntrks_highpT_ = true;
  }else{
    c_PU_ntrks_highpT_ = false;
  }
  if(b_PU_ntrks_lowpT_ && !b_PU_ntrks_lowpT_->TestBit(kDoNotProcess)){
    c_PU_ntrks_lowpT_ = true;
  }else{
    c_PU_ntrks_lowpT_ = false;
  }
  if(b_PU_sumpT_highpT_ && !b_PU_sumpT_highpT_->TestBit(kDoNotProcess)){
    c_PU_sumpT_highpT_ = true;
  }else{
    c_PU_sumpT_highpT_ = false;
  }
  if(b_PU_sumpT_lowpT_ && !b_PU_sumpT_lowpT_->TestBit(kDoNotProcess)){
    c_PU_sumpT_lowpT_ = true;
  }else{
    c_PU_sumpT_lowpT_ = false;
  }
  if(b_PU_zpositions_ && !b_PU_zpositions_->TestBit(kDoNotProcess)){
    c_PU_zpositions_ = true;
  }else{
    c_PU_zpositions_ = false;
  }
  if(b_beamSpot_beamWidthX_ && !b_beamSpot_beamWidthX_->TestBit(kDoNotProcess)){
    c_beamSpot_beamWidthX_ = true;
  }else{
    c_beamSpot_beamWidthX_ = false;
  }
  if(b_beamSpot_beamWidthXError_ && !b_beamSpot_beamWidthXError_->TestBit(kDoNotProcess)){
    c_beamSpot_beamWidthXError_ = true;
  }else{
    c_beamSpot_beamWidthXError_ = false;
  }
  if(b_beamSpot_beamWidthY_ && !b_beamSpot_beamWidthY_->TestBit(kDoNotProcess)){
    c_beamSpot_beamWidthY_ = true;
  }else{
    c_beamSpot_beamWidthY_ = false;
  }
  if(b_beamSpot_beamWidthYError_ && !b_beamSpot_beamWidthYError_->TestBit(kDoNotProcess)){
    c_beamSpot_beamWidthYError_ = true;
  }else{
    c_beamSpot_beamWidthYError_ = false;
  }
  if(b_beamSpot_dxdz_ && !b_beamSpot_dxdz_->TestBit(kDoNotProcess)){
    c_beamSpot_dxdz_ = true;
  }else{
    c_beamSpot_dxdz_ = false;
  }
  if(b_beamSpot_dxdzError_ && !b_beamSpot_dxdzError_->TestBit(kDoNotProcess)){
    c_beamSpot_dxdzError_ = true;
  }else{
    c_beamSpot_dxdzError_ = false;
  }
  if(b_beamSpot_dydz_ && !b_beamSpot_dydz_->TestBit(kDoNotProcess)){
    c_beamSpot_dydz_ = true;
  }else{
    c_beamSpot_dydz_ = false;
  }
  if(b_beamSpot_dydzError_ && !b_beamSpot_dydzError_->TestBit(kDoNotProcess)){
    c_beamSpot_dydzError_ = true;
  }else{
    c_beamSpot_dydzError_ = false;
  }
  if(b_beamSpot_sigmaZ_ && !b_beamSpot_sigmaZ_->TestBit(kDoNotProcess)){
    c_beamSpot_sigmaZ_ = true;
  }else{
    c_beamSpot_sigmaZ_ = false;
  }
  if(b_beamSpot_sigmaZ0Error_ && !b_beamSpot_sigmaZ0Error_->TestBit(kDoNotProcess)){
    c_beamSpot_sigmaZ0Error_ = true;
  }else{
    c_beamSpot_sigmaZ0Error_ = false;
  }
  if(b_beamSpot_x_ && !b_beamSpot_x_->TestBit(kDoNotProcess)){
    c_beamSpot_x_ = true;
  }else{
    c_beamSpot_x_ = false;
  }
  if(b_beamSpot_x0Error_ && !b_beamSpot_x0Error_->TestBit(kDoNotProcess)){
    c_beamSpot_x0Error_ = true;
  }else{
    c_beamSpot_x0Error_ = false;
  }
  if(b_beamSpot_y_ && !b_beamSpot_y_->TestBit(kDoNotProcess)){
    c_beamSpot_y_ = true;
  }else{
    c_beamSpot_y_ = false;
  }
  if(b_beamSpot_y0Error_ && !b_beamSpot_y0Error_->TestBit(kDoNotProcess)){
    c_beamSpot_y0Error_ = true;
  }else{
    c_beamSpot_y0Error_ = false;
  }
  if(b_beamSpot_z_ && !b_beamSpot_z_->TestBit(kDoNotProcess)){
    c_beamSpot_z_ = true;
  }else{
    c_beamSpot_z_ = false;
  }
  if(b_beamSpot_z0Error_ && !b_beamSpot_z0Error_->TestBit(kDoNotProcess)){
    c_beamSpot_z0Error_ = true;
  }else{
    c_beamSpot_z0Error_ = false;
  }
  if(b_bunchCrossing_ && !b_bunchCrossing_->TestBit(kDoNotProcess)){
    c_bunchCrossing_ = true;
  }else{
    c_bunchCrossing_ = false;
  }
  if(b_cschalofilter_decision_ && !b_cschalofilter_decision_->TestBit(kDoNotProcess)){
    c_cschalofilter_decision_ = true;
  }else{
    c_cschalofilter_decision_ = false;
  }
  if(b_ecallaserfilter_decision_ && !b_ecallaserfilter_decision_->TestBit(kDoNotProcess)){
    c_ecallaserfilter_decision_ = true;
  }else{
    c_ecallaserfilter_decision_ = false;
  }
  if(b_eebadscfilter_decision_ && !b_eebadscfilter_decision_->TestBit(kDoNotProcess)){
    c_eebadscfilter_decision_ = true;
  }else{
    c_eebadscfilter_decision_ = false;
  }
  if(b_els_PATpassConversionVeto_ && !b_els_PATpassConversionVeto_->TestBit(kDoNotProcess)){
    c_els_PATpassConversionVeto_ = true;
  }else{
    c_els_PATpassConversionVeto_ = false;
  }
  if(b_els_basicClustersSize_ && !b_els_basicClustersSize_->TestBit(kDoNotProcess)){
    c_els_basicClustersSize_ = true;
  }else{
    c_els_basicClustersSize_ = false;
  }
  if(b_els_cIso_ && !b_els_cIso_->TestBit(kDoNotProcess)){
    c_els_cIso_ = true;
  }else{
    c_els_cIso_ = false;
  }
  if(b_els_caloEnergy_ && !b_els_caloEnergy_->TestBit(kDoNotProcess)){
    c_els_caloEnergy_ = true;
  }else{
    c_els_caloEnergy_ = false;
  }
  if(b_els_charge_ && !b_els_charge_->TestBit(kDoNotProcess)){
    c_els_charge_ = true;
  }else{
    c_els_charge_ = false;
  }
  if(b_els_chi2_ && !b_els_chi2_->TestBit(kDoNotProcess)){
    c_els_chi2_ = true;
  }else{
    c_els_chi2_ = false;
  }
  if(b_els_core_ecalDrivenSeed_ && !b_els_core_ecalDrivenSeed_->TestBit(kDoNotProcess)){
    c_els_core_ecalDrivenSeed_ = true;
  }else{
    c_els_core_ecalDrivenSeed_ = false;
  }
  if(b_els_cpx_ && !b_els_cpx_->TestBit(kDoNotProcess)){
    c_els_cpx_ = true;
  }else{
    c_els_cpx_ = false;
  }
  if(b_els_cpy_ && !b_els_cpy_->TestBit(kDoNotProcess)){
    c_els_cpy_ = true;
  }else{
    c_els_cpy_ = false;
  }
  if(b_els_cpz_ && !b_els_cpz_->TestBit(kDoNotProcess)){
    c_els_cpz_ = true;
  }else{
    c_els_cpz_ = false;
  }
  if(b_els_ctf_tk_charge_ && !b_els_ctf_tk_charge_->TestBit(kDoNotProcess)){
    c_els_ctf_tk_charge_ = true;
  }else{
    c_els_ctf_tk_charge_ = false;
  }
  if(b_els_ctf_tk_eta_ && !b_els_ctf_tk_eta_->TestBit(kDoNotProcess)){
    c_els_ctf_tk_eta_ = true;
  }else{
    c_els_ctf_tk_eta_ = false;
  }
  if(b_els_ctf_tk_id_ && !b_els_ctf_tk_id_->TestBit(kDoNotProcess)){
    c_els_ctf_tk_id_ = true;
  }else{
    c_els_ctf_tk_id_ = false;
  }
  if(b_els_ctf_tk_phi_ && !b_els_ctf_tk_phi_->TestBit(kDoNotProcess)){
    c_els_ctf_tk_phi_ = true;
  }else{
    c_els_ctf_tk_phi_ = false;
  }
  if(b_els_cx_ && !b_els_cx_->TestBit(kDoNotProcess)){
    c_els_cx_ = true;
  }else{
    c_els_cx_ = false;
  }
  if(b_els_cy_ && !b_els_cy_->TestBit(kDoNotProcess)){
    c_els_cy_ = true;
  }else{
    c_els_cy_ = false;
  }
  if(b_els_cz_ && !b_els_cz_->TestBit(kDoNotProcess)){
    c_els_cz_ = true;
  }else{
    c_els_cz_ = false;
  }
  if(b_els_d0dum_ && !b_els_d0dum_->TestBit(kDoNotProcess)){
    c_els_d0dum_ = true;
  }else{
    c_els_d0dum_ = false;
  }
  if(b_els_d0dumError_ && !b_els_d0dumError_->TestBit(kDoNotProcess)){
    c_els_d0dumError_ = true;
  }else{
    c_els_d0dumError_ = false;
  }
  if(b_els_dEtaIn_ && !b_els_dEtaIn_->TestBit(kDoNotProcess)){
    c_els_dEtaIn_ = true;
  }else{
    c_els_dEtaIn_ = false;
  }
  if(b_els_dEtaOut_ && !b_els_dEtaOut_->TestBit(kDoNotProcess)){
    c_els_dEtaOut_ = true;
  }else{
    c_els_dEtaOut_ = false;
  }
  if(b_els_dPhiIn_ && !b_els_dPhiIn_->TestBit(kDoNotProcess)){
    c_els_dPhiIn_ = true;
  }else{
    c_els_dPhiIn_ = false;
  }
  if(b_els_dPhiOut_ && !b_els_dPhiOut_->TestBit(kDoNotProcess)){
    c_els_dPhiOut_ = true;
  }else{
    c_els_dPhiOut_ = false;
  }
  if(b_els_dr03EcalRecHitSumEt_ && !b_els_dr03EcalRecHitSumEt_->TestBit(kDoNotProcess)){
    c_els_dr03EcalRecHitSumEt_ = true;
  }else{
    c_els_dr03EcalRecHitSumEt_ = false;
  }
  if(b_els_dr03HcalDepth1TowerSumEt_ && !b_els_dr03HcalDepth1TowerSumEt_->TestBit(kDoNotProcess)){
    c_els_dr03HcalDepth1TowerSumEt_ = true;
  }else{
    c_els_dr03HcalDepth1TowerSumEt_ = false;
  }
  if(b_els_dr03HcalDepth2TowerSumEt_ && !b_els_dr03HcalDepth2TowerSumEt_->TestBit(kDoNotProcess)){
    c_els_dr03HcalDepth2TowerSumEt_ = true;
  }else{
    c_els_dr03HcalDepth2TowerSumEt_ = false;
  }
  if(b_els_dr03HcalTowerSumEt_ && !b_els_dr03HcalTowerSumEt_->TestBit(kDoNotProcess)){
    c_els_dr03HcalTowerSumEt_ = true;
  }else{
    c_els_dr03HcalTowerSumEt_ = false;
  }
  if(b_els_dr03TkSumPt_ && !b_els_dr03TkSumPt_->TestBit(kDoNotProcess)){
    c_els_dr03TkSumPt_ = true;
  }else{
    c_els_dr03TkSumPt_ = false;
  }
  if(b_els_dr04EcalRecHitSumEt_ && !b_els_dr04EcalRecHitSumEt_->TestBit(kDoNotProcess)){
    c_els_dr04EcalRecHitSumEt_ = true;
  }else{
    c_els_dr04EcalRecHitSumEt_ = false;
  }
  if(b_els_dr04HcalDepth1TowerSumEt_ && !b_els_dr04HcalDepth1TowerSumEt_->TestBit(kDoNotProcess)){
    c_els_dr04HcalDepth1TowerSumEt_ = true;
  }else{
    c_els_dr04HcalDepth1TowerSumEt_ = false;
  }
  if(b_els_dr04HcalDepth2TowerSumEt_ && !b_els_dr04HcalDepth2TowerSumEt_->TestBit(kDoNotProcess)){
    c_els_dr04HcalDepth2TowerSumEt_ = true;
  }else{
    c_els_dr04HcalDepth2TowerSumEt_ = false;
  }
  if(b_els_dr04HcalTowerSumEt_ && !b_els_dr04HcalTowerSumEt_->TestBit(kDoNotProcess)){
    c_els_dr04HcalTowerSumEt_ = true;
  }else{
    c_els_dr04HcalTowerSumEt_ = false;
  }
  if(b_els_dr04TkSumPt_ && !b_els_dr04TkSumPt_->TestBit(kDoNotProcess)){
    c_els_dr04TkSumPt_ = true;
  }else{
    c_els_dr04TkSumPt_ = false;
  }
  if(b_els_dz_ && !b_els_dz_->TestBit(kDoNotProcess)){
    c_els_dz_ = true;
  }else{
    c_els_dz_ = false;
  }
  if(b_els_dzError_ && !b_els_dzError_->TestBit(kDoNotProcess)){
    c_els_dzError_ = true;
  }else{
    c_els_dzError_ = false;
  }
  if(b_els_eOverPIn_ && !b_els_eOverPIn_->TestBit(kDoNotProcess)){
    c_els_eOverPIn_ = true;
  }else{
    c_els_eOverPIn_ = false;
  }
  if(b_els_eSeedOverPOut_ && !b_els_eSeedOverPOut_->TestBit(kDoNotProcess)){
    c_els_eSeedOverPOut_ = true;
  }else{
    c_els_eSeedOverPOut_ = false;
  }
  if(b_els_ecalIso_ && !b_els_ecalIso_->TestBit(kDoNotProcess)){
    c_els_ecalIso_ = true;
  }else{
    c_els_ecalIso_ = false;
  }
  if(b_els_energy_ && !b_els_energy_->TestBit(kDoNotProcess)){
    c_els_energy_ = true;
  }else{
    c_els_energy_ = false;
  }
  if(b_els_et_ && !b_els_et_->TestBit(kDoNotProcess)){
    c_els_et_ = true;
  }else{
    c_els_et_ = false;
  }
  if(b_els_eta_ && !b_els_eta_->TestBit(kDoNotProcess)){
    c_els_eta_ = true;
  }else{
    c_els_eta_ = false;
  }
  if(b_els_etaError_ && !b_els_etaError_->TestBit(kDoNotProcess)){
    c_els_etaError_ = true;
  }else{
    c_els_etaError_ = false;
  }
  if(b_els_fbrem_ && !b_els_fbrem_->TestBit(kDoNotProcess)){
    c_els_fbrem_ = true;
  }else{
    c_els_fbrem_ = false;
  }
  if(b_els_gen_et_ && !b_els_gen_et_->TestBit(kDoNotProcess)){
    c_els_gen_et_ = true;
  }else{
    c_els_gen_et_ = false;
  }
  if(b_els_gen_eta_ && !b_els_gen_eta_->TestBit(kDoNotProcess)){
    c_els_gen_eta_ = true;
  }else{
    c_els_gen_eta_ = false;
  }
  if(b_els_gen_id_ && !b_els_gen_id_->TestBit(kDoNotProcess)){
    c_els_gen_id_ = true;
  }else{
    c_els_gen_id_ = false;
  }
  if(b_els_gen_mother_et_ && !b_els_gen_mother_et_->TestBit(kDoNotProcess)){
    c_els_gen_mother_et_ = true;
  }else{
    c_els_gen_mother_et_ = false;
  }
  if(b_els_gen_mother_eta_ && !b_els_gen_mother_eta_->TestBit(kDoNotProcess)){
    c_els_gen_mother_eta_ = true;
  }else{
    c_els_gen_mother_eta_ = false;
  }
  if(b_els_gen_mother_id_ && !b_els_gen_mother_id_->TestBit(kDoNotProcess)){
    c_els_gen_mother_id_ = true;
  }else{
    c_els_gen_mother_id_ = false;
  }
  if(b_els_gen_mother_phi_ && !b_els_gen_mother_phi_->TestBit(kDoNotProcess)){
    c_els_gen_mother_phi_ = true;
  }else{
    c_els_gen_mother_phi_ = false;
  }
  if(b_els_gen_mother_pt_ && !b_els_gen_mother_pt_->TestBit(kDoNotProcess)){
    c_els_gen_mother_pt_ = true;
  }else{
    c_els_gen_mother_pt_ = false;
  }
  if(b_els_gen_mother_px_ && !b_els_gen_mother_px_->TestBit(kDoNotProcess)){
    c_els_gen_mother_px_ = true;
  }else{
    c_els_gen_mother_px_ = false;
  }
  if(b_els_gen_mother_py_ && !b_els_gen_mother_py_->TestBit(kDoNotProcess)){
    c_els_gen_mother_py_ = true;
  }else{
    c_els_gen_mother_py_ = false;
  }
  if(b_els_gen_mother_pz_ && !b_els_gen_mother_pz_->TestBit(kDoNotProcess)){
    c_els_gen_mother_pz_ = true;
  }else{
    c_els_gen_mother_pz_ = false;
  }
  if(b_els_gen_mother_theta_ && !b_els_gen_mother_theta_->TestBit(kDoNotProcess)){
    c_els_gen_mother_theta_ = true;
  }else{
    c_els_gen_mother_theta_ = false;
  }
  if(b_els_gen_phi_ && !b_els_gen_phi_->TestBit(kDoNotProcess)){
    c_els_gen_phi_ = true;
  }else{
    c_els_gen_phi_ = false;
  }
  if(b_els_gen_pt_ && !b_els_gen_pt_->TestBit(kDoNotProcess)){
    c_els_gen_pt_ = true;
  }else{
    c_els_gen_pt_ = false;
  }
  if(b_els_gen_px_ && !b_els_gen_px_->TestBit(kDoNotProcess)){
    c_els_gen_px_ = true;
  }else{
    c_els_gen_px_ = false;
  }
  if(b_els_gen_py_ && !b_els_gen_py_->TestBit(kDoNotProcess)){
    c_els_gen_py_ = true;
  }else{
    c_els_gen_py_ = false;
  }
  if(b_els_gen_pz_ && !b_els_gen_pz_->TestBit(kDoNotProcess)){
    c_els_gen_pz_ = true;
  }else{
    c_els_gen_pz_ = false;
  }
  if(b_els_gen_theta_ && !b_els_gen_theta_->TestBit(kDoNotProcess)){
    c_els_gen_theta_ = true;
  }else{
    c_els_gen_theta_ = false;
  }
  if(b_els_hadOverEm_ && !b_els_hadOverEm_->TestBit(kDoNotProcess)){
    c_els_hadOverEm_ = true;
  }else{
    c_els_hadOverEm_ = false;
  }
  if(b_els_hcalIso_ && !b_els_hcalIso_->TestBit(kDoNotProcess)){
    c_els_hcalIso_ = true;
  }else{
    c_els_hcalIso_ = false;
  }
  if(b_els_hcalOverEcalBc_ && !b_els_hcalOverEcalBc_->TestBit(kDoNotProcess)){
    c_els_hcalOverEcalBc_ = true;
  }else{
    c_els_hcalOverEcalBc_ = false;
  }
  if(b_els_isEB_ && !b_els_isEB_->TestBit(kDoNotProcess)){
    c_els_isEB_ = true;
  }else{
    c_els_isEB_ = false;
  }
  if(b_els_isEE_ && !b_els_isEE_->TestBit(kDoNotProcess)){
    c_els_isEE_ = true;
  }else{
    c_els_isEE_ = false;
  }
  if(b_els_looseId_ && !b_els_looseId_->TestBit(kDoNotProcess)){
    c_els_looseId_ = true;
  }else{
    c_els_looseId_ = false;
  }
  if(b_els_n_inner_layer_ && !b_els_n_inner_layer_->TestBit(kDoNotProcess)){
    c_els_n_inner_layer_ = true;
  }else{
    c_els_n_inner_layer_ = false;
  }
  if(b_els_n_outer_layer_ && !b_els_n_outer_layer_->TestBit(kDoNotProcess)){
    c_els_n_outer_layer_ = true;
  }else{
    c_els_n_outer_layer_ = false;
  }
  if(b_els_ndof_ && !b_els_ndof_->TestBit(kDoNotProcess)){
    c_els_ndof_ = true;
  }else{
    c_els_ndof_ = false;
  }
  if(b_els_numlosthits_ && !b_els_numlosthits_->TestBit(kDoNotProcess)){
    c_els_numlosthits_ = true;
  }else{
    c_els_numlosthits_ = false;
  }
  if(b_els_numvalhits_ && !b_els_numvalhits_->TestBit(kDoNotProcess)){
    c_els_numvalhits_ = true;
  }else{
    c_els_numvalhits_ = false;
  }
  if(b_els_phi_ && !b_els_phi_->TestBit(kDoNotProcess)){
    c_els_phi_ = true;
  }else{
    c_els_phi_ = false;
  }
  if(b_els_phiError_ && !b_els_phiError_->TestBit(kDoNotProcess)){
    c_els_phiError_ = true;
  }else{
    c_els_phiError_ = false;
  }
  if(b_els_pt_ && !b_els_pt_->TestBit(kDoNotProcess)){
    c_els_pt_ = true;
  }else{
    c_els_pt_ = false;
  }
  if(b_els_ptError_ && !b_els_ptError_->TestBit(kDoNotProcess)){
    c_els_ptError_ = true;
  }else{
    c_els_ptError_ = false;
  }
  if(b_els_px_ && !b_els_px_->TestBit(kDoNotProcess)){
    c_els_px_ = true;
  }else{
    c_els_px_ = false;
  }
  if(b_els_py_ && !b_els_py_->TestBit(kDoNotProcess)){
    c_els_py_ = true;
  }else{
    c_els_py_ = false;
  }
  if(b_els_pz_ && !b_els_pz_->TestBit(kDoNotProcess)){
    c_els_pz_ = true;
  }else{
    c_els_pz_ = false;
  }
  if(b_els_robustHighEnergyId_ && !b_els_robustHighEnergyId_->TestBit(kDoNotProcess)){
    c_els_robustHighEnergyId_ = true;
  }else{
    c_els_robustHighEnergyId_ = false;
  }
  if(b_els_robustLooseId_ && !b_els_robustLooseId_->TestBit(kDoNotProcess)){
    c_els_robustLooseId_ = true;
  }else{
    c_els_robustLooseId_ = false;
  }
  if(b_els_robustTightId_ && !b_els_robustTightId_->TestBit(kDoNotProcess)){
    c_els_robustTightId_ = true;
  }else{
    c_els_robustTightId_ = false;
  }
  if(b_els_scE1x5_ && !b_els_scE1x5_->TestBit(kDoNotProcess)){
    c_els_scE1x5_ = true;
  }else{
    c_els_scE1x5_ = false;
  }
  if(b_els_scE2x5Max_ && !b_els_scE2x5Max_->TestBit(kDoNotProcess)){
    c_els_scE2x5Max_ = true;
  }else{
    c_els_scE2x5Max_ = false;
  }
  if(b_els_scE5x5_ && !b_els_scE5x5_->TestBit(kDoNotProcess)){
    c_els_scE5x5_ = true;
  }else{
    c_els_scE5x5_ = false;
  }
  if(b_els_scEnergy_ && !b_els_scEnergy_->TestBit(kDoNotProcess)){
    c_els_scEnergy_ = true;
  }else{
    c_els_scEnergy_ = false;
  }
  if(b_els_scEta_ && !b_els_scEta_->TestBit(kDoNotProcess)){
    c_els_scEta_ = true;
  }else{
    c_els_scEta_ = false;
  }
  if(b_els_scEtaWidth_ && !b_els_scEtaWidth_->TestBit(kDoNotProcess)){
    c_els_scEtaWidth_ = true;
  }else{
    c_els_scEtaWidth_ = false;
  }
  if(b_els_scPhi_ && !b_els_scPhi_->TestBit(kDoNotProcess)){
    c_els_scPhi_ = true;
  }else{
    c_els_scPhi_ = false;
  }
  if(b_els_scPhiWidth_ && !b_els_scPhiWidth_->TestBit(kDoNotProcess)){
    c_els_scPhiWidth_ = true;
  }else{
    c_els_scPhiWidth_ = false;
  }
  if(b_els_scRawEnergy_ && !b_els_scRawEnergy_->TestBit(kDoNotProcess)){
    c_els_scRawEnergy_ = true;
  }else{
    c_els_scRawEnergy_ = false;
  }
  if(b_els_scSeedEnergy_ && !b_els_scSeedEnergy_->TestBit(kDoNotProcess)){
    c_els_scSeedEnergy_ = true;
  }else{
    c_els_scSeedEnergy_ = false;
  }
  if(b_els_shFracInnerHits_ && !b_els_shFracInnerHits_->TestBit(kDoNotProcess)){
    c_els_shFracInnerHits_ = true;
  }else{
    c_els_shFracInnerHits_ = false;
  }
  if(b_els_sigmaEtaEta_ && !b_els_sigmaEtaEta_->TestBit(kDoNotProcess)){
    c_els_sigmaEtaEta_ = true;
  }else{
    c_els_sigmaEtaEta_ = false;
  }
  if(b_els_sigmaIEtaIEta_ && !b_els_sigmaIEtaIEta_->TestBit(kDoNotProcess)){
    c_els_sigmaIEtaIEta_ = true;
  }else{
    c_els_sigmaIEtaIEta_ = false;
  }
  if(b_els_simpleEleId60cIso_ && !b_els_simpleEleId60cIso_->TestBit(kDoNotProcess)){
    c_els_simpleEleId60cIso_ = true;
  }else{
    c_els_simpleEleId60cIso_ = false;
  }
  if(b_els_simpleEleId60relIso_ && !b_els_simpleEleId60relIso_->TestBit(kDoNotProcess)){
    c_els_simpleEleId60relIso_ = true;
  }else{
    c_els_simpleEleId60relIso_ = false;
  }
  if(b_els_simpleEleId70cIso_ && !b_els_simpleEleId70cIso_->TestBit(kDoNotProcess)){
    c_els_simpleEleId70cIso_ = true;
  }else{
    c_els_simpleEleId70cIso_ = false;
  }
  if(b_els_simpleEleId70relIso_ && !b_els_simpleEleId70relIso_->TestBit(kDoNotProcess)){
    c_els_simpleEleId70relIso_ = true;
  }else{
    c_els_simpleEleId70relIso_ = false;
  }
  if(b_els_simpleEleId80cIso_ && !b_els_simpleEleId80cIso_->TestBit(kDoNotProcess)){
    c_els_simpleEleId80cIso_ = true;
  }else{
    c_els_simpleEleId80cIso_ = false;
  }
  if(b_els_simpleEleId80relIso_ && !b_els_simpleEleId80relIso_->TestBit(kDoNotProcess)){
    c_els_simpleEleId80relIso_ = true;
  }else{
    c_els_simpleEleId80relIso_ = false;
  }
  if(b_els_simpleEleId85cIso_ && !b_els_simpleEleId85cIso_->TestBit(kDoNotProcess)){
    c_els_simpleEleId85cIso_ = true;
  }else{
    c_els_simpleEleId85cIso_ = false;
  }
  if(b_els_simpleEleId85relIso_ && !b_els_simpleEleId85relIso_->TestBit(kDoNotProcess)){
    c_els_simpleEleId85relIso_ = true;
  }else{
    c_els_simpleEleId85relIso_ = false;
  }
  if(b_els_simpleEleId90cIso_ && !b_els_simpleEleId90cIso_->TestBit(kDoNotProcess)){
    c_els_simpleEleId90cIso_ = true;
  }else{
    c_els_simpleEleId90cIso_ = false;
  }
  if(b_els_simpleEleId90relIso_ && !b_els_simpleEleId90relIso_->TestBit(kDoNotProcess)){
    c_els_simpleEleId90relIso_ = true;
  }else{
    c_els_simpleEleId90relIso_ = false;
  }
  if(b_els_simpleEleId95cIso_ && !b_els_simpleEleId95cIso_->TestBit(kDoNotProcess)){
    c_els_simpleEleId95cIso_ = true;
  }else{
    c_els_simpleEleId95cIso_ = false;
  }
  if(b_els_simpleEleId95relIso_ && !b_els_simpleEleId95relIso_->TestBit(kDoNotProcess)){
    c_els_simpleEleId95relIso_ = true;
  }else{
    c_els_simpleEleId95relIso_ = false;
  }
  if(b_els_status_ && !b_els_status_->TestBit(kDoNotProcess)){
    c_els_status_ = true;
  }else{
    c_els_status_ = false;
  }
  if(b_els_tIso_ && !b_els_tIso_->TestBit(kDoNotProcess)){
    c_els_tIso_ = true;
  }else{
    c_els_tIso_ = false;
  }
  if(b_els_theta_ && !b_els_theta_->TestBit(kDoNotProcess)){
    c_els_theta_ = true;
  }else{
    c_els_theta_ = false;
  }
  if(b_els_tightId_ && !b_els_tightId_->TestBit(kDoNotProcess)){
    c_els_tightId_ = true;
  }else{
    c_els_tightId_ = false;
  }
  if(b_els_tk_charge_ && !b_els_tk_charge_->TestBit(kDoNotProcess)){
    c_els_tk_charge_ = true;
  }else{
    c_els_tk_charge_ = false;
  }
  if(b_els_tk_eta_ && !b_els_tk_eta_->TestBit(kDoNotProcess)){
    c_els_tk_eta_ = true;
  }else{
    c_els_tk_eta_ = false;
  }
  if(b_els_tk_phi_ && !b_els_tk_phi_->TestBit(kDoNotProcess)){
    c_els_tk_phi_ = true;
  }else{
    c_els_tk_phi_ = false;
  }
  if(b_els_tk_pt_ && !b_els_tk_pt_->TestBit(kDoNotProcess)){
    c_els_tk_pt_ = true;
  }else{
    c_els_tk_pt_ = false;
  }
  if(b_els_tk_pz_ && !b_els_tk_pz_->TestBit(kDoNotProcess)){
    c_els_tk_pz_ = true;
  }else{
    c_els_tk_pz_ = false;
  }
  if(b_els_vpx_ && !b_els_vpx_->TestBit(kDoNotProcess)){
    c_els_vpx_ = true;
  }else{
    c_els_vpx_ = false;
  }
  if(b_els_vpy_ && !b_els_vpy_->TestBit(kDoNotProcess)){
    c_els_vpy_ = true;
  }else{
    c_els_vpy_ = false;
  }
  if(b_els_vpz_ && !b_els_vpz_->TestBit(kDoNotProcess)){
    c_els_vpz_ = true;
  }else{
    c_els_vpz_ = false;
  }
  if(b_els_vx_ && !b_els_vx_->TestBit(kDoNotProcess)){
    c_els_vx_ = true;
  }else{
    c_els_vx_ = false;
  }
  if(b_els_vy_ && !b_els_vy_->TestBit(kDoNotProcess)){
    c_els_vy_ = true;
  }else{
    c_els_vy_ = false;
  }
  if(b_els_vz_ && !b_els_vz_->TestBit(kDoNotProcess)){
    c_els_vz_ = true;
  }else{
    c_els_vz_ = false;
  }
  if(b_event_ && !b_event_->TestBit(kDoNotProcess)){
    c_event_ = true;
  }else{
    c_event_ = false;
  }
  if(b_experimentType_ && !b_experimentType_->TestBit(kDoNotProcess)){
    c_experimentType_ = true;
  }else{
    c_experimentType_ = false;
  }
  if(b_hcallaserfilter_decision_ && !b_hcallaserfilter_decision_->TestBit(kDoNotProcess)){
    c_hcallaserfilter_decision_ = true;
  }else{
    c_hcallaserfilter_decision_ = false;
  }
  if(b_lumiblock_ && !b_lumiblock_->TestBit(kDoNotProcess)){
    c_lumiblock_ = true;
  }else{
    c_lumiblock_ = false;
  }
  if(b_mc_doc_charge_ && !b_mc_doc_charge_->TestBit(kDoNotProcess)){
    c_mc_doc_charge_ = true;
  }else{
    c_mc_doc_charge_ = false;
  }
  if(b_mc_doc_energy_ && !b_mc_doc_energy_->TestBit(kDoNotProcess)){
    c_mc_doc_energy_ = true;
  }else{
    c_mc_doc_energy_ = false;
  }
  if(b_mc_doc_eta_ && !b_mc_doc_eta_->TestBit(kDoNotProcess)){
    c_mc_doc_eta_ = true;
  }else{
    c_mc_doc_eta_ = false;
  }
  if(b_mc_doc_ggrandmother_id_ && !b_mc_doc_ggrandmother_id_->TestBit(kDoNotProcess)){
    c_mc_doc_ggrandmother_id_ = true;
  }else{
    c_mc_doc_ggrandmother_id_ = false;
  }
  if(b_mc_doc_grandmother_id_ && !b_mc_doc_grandmother_id_->TestBit(kDoNotProcess)){
    c_mc_doc_grandmother_id_ = true;
  }else{
    c_mc_doc_grandmother_id_ = false;
  }
  if(b_mc_doc_id_ && !b_mc_doc_id_->TestBit(kDoNotProcess)){
    c_mc_doc_id_ = true;
  }else{
    c_mc_doc_id_ = false;
  }
  if(b_mc_doc_mass_ && !b_mc_doc_mass_->TestBit(kDoNotProcess)){
    c_mc_doc_mass_ = true;
  }else{
    c_mc_doc_mass_ = false;
  }
  if(b_mc_doc_mother_id_ && !b_mc_doc_mother_id_->TestBit(kDoNotProcess)){
    c_mc_doc_mother_id_ = true;
  }else{
    c_mc_doc_mother_id_ = false;
  }
  if(b_mc_doc_mother_pt_ && !b_mc_doc_mother_pt_->TestBit(kDoNotProcess)){
    c_mc_doc_mother_pt_ = true;
  }else{
    c_mc_doc_mother_pt_ = false;
  }
  if(b_mc_doc_numOfDaughters_ && !b_mc_doc_numOfDaughters_->TestBit(kDoNotProcess)){
    c_mc_doc_numOfDaughters_ = true;
  }else{
    c_mc_doc_numOfDaughters_ = false;
  }
  if(b_mc_doc_numOfMothers_ && !b_mc_doc_numOfMothers_->TestBit(kDoNotProcess)){
    c_mc_doc_numOfMothers_ = true;
  }else{
    c_mc_doc_numOfMothers_ = false;
  }
  if(b_mc_doc_phi_ && !b_mc_doc_phi_->TestBit(kDoNotProcess)){
    c_mc_doc_phi_ = true;
  }else{
    c_mc_doc_phi_ = false;
  }
  if(b_mc_doc_pt_ && !b_mc_doc_pt_->TestBit(kDoNotProcess)){
    c_mc_doc_pt_ = true;
  }else{
    c_mc_doc_pt_ = false;
  }
  if(b_mc_doc_px_ && !b_mc_doc_px_->TestBit(kDoNotProcess)){
    c_mc_doc_px_ = true;
  }else{
    c_mc_doc_px_ = false;
  }
  if(b_mc_doc_py_ && !b_mc_doc_py_->TestBit(kDoNotProcess)){
    c_mc_doc_py_ = true;
  }else{
    c_mc_doc_py_ = false;
  }
  if(b_mc_doc_pz_ && !b_mc_doc_pz_->TestBit(kDoNotProcess)){
    c_mc_doc_pz_ = true;
  }else{
    c_mc_doc_pz_ = false;
  }
  if(b_mc_doc_status_ && !b_mc_doc_status_->TestBit(kDoNotProcess)){
    c_mc_doc_status_ = true;
  }else{
    c_mc_doc_status_ = false;
  }
  if(b_mc_doc_theta_ && !b_mc_doc_theta_->TestBit(kDoNotProcess)){
    c_mc_doc_theta_ = true;
  }else{
    c_mc_doc_theta_ = false;
  }
  if(b_mc_doc_vertex_x_ && !b_mc_doc_vertex_x_->TestBit(kDoNotProcess)){
    c_mc_doc_vertex_x_ = true;
  }else{
    c_mc_doc_vertex_x_ = false;
  }
  if(b_mc_doc_vertex_y_ && !b_mc_doc_vertex_y_->TestBit(kDoNotProcess)){
    c_mc_doc_vertex_y_ = true;
  }else{
    c_mc_doc_vertex_y_ = false;
  }
  if(b_mc_doc_vertex_z_ && !b_mc_doc_vertex_z_->TestBit(kDoNotProcess)){
    c_mc_doc_vertex_z_ = true;
  }else{
    c_mc_doc_vertex_z_ = false;
  }
  if(b_mc_electrons_charge_ && !b_mc_electrons_charge_->TestBit(kDoNotProcess)){
    c_mc_electrons_charge_ = true;
  }else{
    c_mc_electrons_charge_ = false;
  }
  if(b_mc_electrons_energy_ && !b_mc_electrons_energy_->TestBit(kDoNotProcess)){
    c_mc_electrons_energy_ = true;
  }else{
    c_mc_electrons_energy_ = false;
  }
  if(b_mc_electrons_eta_ && !b_mc_electrons_eta_->TestBit(kDoNotProcess)){
    c_mc_electrons_eta_ = true;
  }else{
    c_mc_electrons_eta_ = false;
  }
  if(b_mc_electrons_ggrandmother_id_ && !b_mc_electrons_ggrandmother_id_->TestBit(kDoNotProcess)){
    c_mc_electrons_ggrandmother_id_ = true;
  }else{
    c_mc_electrons_ggrandmother_id_ = false;
  }
  if(b_mc_electrons_grandmother_id_ && !b_mc_electrons_grandmother_id_->TestBit(kDoNotProcess)){
    c_mc_electrons_grandmother_id_ = true;
  }else{
    c_mc_electrons_grandmother_id_ = false;
  }
  if(b_mc_electrons_id_ && !b_mc_electrons_id_->TestBit(kDoNotProcess)){
    c_mc_electrons_id_ = true;
  }else{
    c_mc_electrons_id_ = false;
  }
  if(b_mc_electrons_mass_ && !b_mc_electrons_mass_->TestBit(kDoNotProcess)){
    c_mc_electrons_mass_ = true;
  }else{
    c_mc_electrons_mass_ = false;
  }
  if(b_mc_electrons_mother_id_ && !b_mc_electrons_mother_id_->TestBit(kDoNotProcess)){
    c_mc_electrons_mother_id_ = true;
  }else{
    c_mc_electrons_mother_id_ = false;
  }
  if(b_mc_electrons_mother_pt_ && !b_mc_electrons_mother_pt_->TestBit(kDoNotProcess)){
    c_mc_electrons_mother_pt_ = true;
  }else{
    c_mc_electrons_mother_pt_ = false;
  }
  if(b_mc_electrons_numOfDaughters_ && !b_mc_electrons_numOfDaughters_->TestBit(kDoNotProcess)){
    c_mc_electrons_numOfDaughters_ = true;
  }else{
    c_mc_electrons_numOfDaughters_ = false;
  }
  if(b_mc_electrons_phi_ && !b_mc_electrons_phi_->TestBit(kDoNotProcess)){
    c_mc_electrons_phi_ = true;
  }else{
    c_mc_electrons_phi_ = false;
  }
  if(b_mc_electrons_pt_ && !b_mc_electrons_pt_->TestBit(kDoNotProcess)){
    c_mc_electrons_pt_ = true;
  }else{
    c_mc_electrons_pt_ = false;
  }
  if(b_mc_electrons_px_ && !b_mc_electrons_px_->TestBit(kDoNotProcess)){
    c_mc_electrons_px_ = true;
  }else{
    c_mc_electrons_px_ = false;
  }
  if(b_mc_electrons_py_ && !b_mc_electrons_py_->TestBit(kDoNotProcess)){
    c_mc_electrons_py_ = true;
  }else{
    c_mc_electrons_py_ = false;
  }
  if(b_mc_electrons_pz_ && !b_mc_electrons_pz_->TestBit(kDoNotProcess)){
    c_mc_electrons_pz_ = true;
  }else{
    c_mc_electrons_pz_ = false;
  }
  if(b_mc_electrons_status_ && !b_mc_electrons_status_->TestBit(kDoNotProcess)){
    c_mc_electrons_status_ = true;
  }else{
    c_mc_electrons_status_ = false;
  }
  if(b_mc_electrons_theta_ && !b_mc_electrons_theta_->TestBit(kDoNotProcess)){
    c_mc_electrons_theta_ = true;
  }else{
    c_mc_electrons_theta_ = false;
  }
  if(b_mc_electrons_vertex_x_ && !b_mc_electrons_vertex_x_->TestBit(kDoNotProcess)){
    c_mc_electrons_vertex_x_ = true;
  }else{
    c_mc_electrons_vertex_x_ = false;
  }
  if(b_mc_electrons_vertex_y_ && !b_mc_electrons_vertex_y_->TestBit(kDoNotProcess)){
    c_mc_electrons_vertex_y_ = true;
  }else{
    c_mc_electrons_vertex_y_ = false;
  }
  if(b_mc_electrons_vertex_z_ && !b_mc_electrons_vertex_z_->TestBit(kDoNotProcess)){
    c_mc_electrons_vertex_z_ = true;
  }else{
    c_mc_electrons_vertex_z_ = false;
  }
  if(b_mc_mus_charge_ && !b_mc_mus_charge_->TestBit(kDoNotProcess)){
    c_mc_mus_charge_ = true;
  }else{
    c_mc_mus_charge_ = false;
  }
  if(b_mc_mus_energy_ && !b_mc_mus_energy_->TestBit(kDoNotProcess)){
    c_mc_mus_energy_ = true;
  }else{
    c_mc_mus_energy_ = false;
  }
  if(b_mc_mus_eta_ && !b_mc_mus_eta_->TestBit(kDoNotProcess)){
    c_mc_mus_eta_ = true;
  }else{
    c_mc_mus_eta_ = false;
  }
  if(b_mc_mus_ggrandmother_id_ && !b_mc_mus_ggrandmother_id_->TestBit(kDoNotProcess)){
    c_mc_mus_ggrandmother_id_ = true;
  }else{
    c_mc_mus_ggrandmother_id_ = false;
  }
  if(b_mc_mus_grandmother_id_ && !b_mc_mus_grandmother_id_->TestBit(kDoNotProcess)){
    c_mc_mus_grandmother_id_ = true;
  }else{
    c_mc_mus_grandmother_id_ = false;
  }
  if(b_mc_mus_id_ && !b_mc_mus_id_->TestBit(kDoNotProcess)){
    c_mc_mus_id_ = true;
  }else{
    c_mc_mus_id_ = false;
  }
  if(b_mc_mus_mass_ && !b_mc_mus_mass_->TestBit(kDoNotProcess)){
    c_mc_mus_mass_ = true;
  }else{
    c_mc_mus_mass_ = false;
  }
  if(b_mc_mus_mother_id_ && !b_mc_mus_mother_id_->TestBit(kDoNotProcess)){
    c_mc_mus_mother_id_ = true;
  }else{
    c_mc_mus_mother_id_ = false;
  }
  if(b_mc_mus_mother_pt_ && !b_mc_mus_mother_pt_->TestBit(kDoNotProcess)){
    c_mc_mus_mother_pt_ = true;
  }else{
    c_mc_mus_mother_pt_ = false;
  }
  if(b_mc_mus_numOfDaughters_ && !b_mc_mus_numOfDaughters_->TestBit(kDoNotProcess)){
    c_mc_mus_numOfDaughters_ = true;
  }else{
    c_mc_mus_numOfDaughters_ = false;
  }
  if(b_mc_mus_phi_ && !b_mc_mus_phi_->TestBit(kDoNotProcess)){
    c_mc_mus_phi_ = true;
  }else{
    c_mc_mus_phi_ = false;
  }
  if(b_mc_mus_pt_ && !b_mc_mus_pt_->TestBit(kDoNotProcess)){
    c_mc_mus_pt_ = true;
  }else{
    c_mc_mus_pt_ = false;
  }
  if(b_mc_mus_px_ && !b_mc_mus_px_->TestBit(kDoNotProcess)){
    c_mc_mus_px_ = true;
  }else{
    c_mc_mus_px_ = false;
  }
  if(b_mc_mus_py_ && !b_mc_mus_py_->TestBit(kDoNotProcess)){
    c_mc_mus_py_ = true;
  }else{
    c_mc_mus_py_ = false;
  }
  if(b_mc_mus_pz_ && !b_mc_mus_pz_->TestBit(kDoNotProcess)){
    c_mc_mus_pz_ = true;
  }else{
    c_mc_mus_pz_ = false;
  }
  if(b_mc_mus_status_ && !b_mc_mus_status_->TestBit(kDoNotProcess)){
    c_mc_mus_status_ = true;
  }else{
    c_mc_mus_status_ = false;
  }
  if(b_mc_mus_theta_ && !b_mc_mus_theta_->TestBit(kDoNotProcess)){
    c_mc_mus_theta_ = true;
  }else{
    c_mc_mus_theta_ = false;
  }
  if(b_mc_mus_vertex_x_ && !b_mc_mus_vertex_x_->TestBit(kDoNotProcess)){
    c_mc_mus_vertex_x_ = true;
  }else{
    c_mc_mus_vertex_x_ = false;
  }
  if(b_mc_mus_vertex_y_ && !b_mc_mus_vertex_y_->TestBit(kDoNotProcess)){
    c_mc_mus_vertex_y_ = true;
  }else{
    c_mc_mus_vertex_y_ = false;
  }
  if(b_mc_mus_vertex_z_ && !b_mc_mus_vertex_z_->TestBit(kDoNotProcess)){
    c_mc_mus_vertex_z_ = true;
  }else{
    c_mc_mus_vertex_z_ = false;
  }
  if(b_mc_nues_charge_ && !b_mc_nues_charge_->TestBit(kDoNotProcess)){
    c_mc_nues_charge_ = true;
  }else{
    c_mc_nues_charge_ = false;
  }
  if(b_mc_nues_energy_ && !b_mc_nues_energy_->TestBit(kDoNotProcess)){
    c_mc_nues_energy_ = true;
  }else{
    c_mc_nues_energy_ = false;
  }
  if(b_mc_nues_eta_ && !b_mc_nues_eta_->TestBit(kDoNotProcess)){
    c_mc_nues_eta_ = true;
  }else{
    c_mc_nues_eta_ = false;
  }
  if(b_mc_nues_ggrandmother_id_ && !b_mc_nues_ggrandmother_id_->TestBit(kDoNotProcess)){
    c_mc_nues_ggrandmother_id_ = true;
  }else{
    c_mc_nues_ggrandmother_id_ = false;
  }
  if(b_mc_nues_grandmother_id_ && !b_mc_nues_grandmother_id_->TestBit(kDoNotProcess)){
    c_mc_nues_grandmother_id_ = true;
  }else{
    c_mc_nues_grandmother_id_ = false;
  }
  if(b_mc_nues_id_ && !b_mc_nues_id_->TestBit(kDoNotProcess)){
    c_mc_nues_id_ = true;
  }else{
    c_mc_nues_id_ = false;
  }
  if(b_mc_nues_mass_ && !b_mc_nues_mass_->TestBit(kDoNotProcess)){
    c_mc_nues_mass_ = true;
  }else{
    c_mc_nues_mass_ = false;
  }
  if(b_mc_nues_mother_id_ && !b_mc_nues_mother_id_->TestBit(kDoNotProcess)){
    c_mc_nues_mother_id_ = true;
  }else{
    c_mc_nues_mother_id_ = false;
  }
  if(b_mc_nues_mother_pt_ && !b_mc_nues_mother_pt_->TestBit(kDoNotProcess)){
    c_mc_nues_mother_pt_ = true;
  }else{
    c_mc_nues_mother_pt_ = false;
  }
  if(b_mc_nues_numOfDaughters_ && !b_mc_nues_numOfDaughters_->TestBit(kDoNotProcess)){
    c_mc_nues_numOfDaughters_ = true;
  }else{
    c_mc_nues_numOfDaughters_ = false;
  }
  if(b_mc_nues_phi_ && !b_mc_nues_phi_->TestBit(kDoNotProcess)){
    c_mc_nues_phi_ = true;
  }else{
    c_mc_nues_phi_ = false;
  }
  if(b_mc_nues_pt_ && !b_mc_nues_pt_->TestBit(kDoNotProcess)){
    c_mc_nues_pt_ = true;
  }else{
    c_mc_nues_pt_ = false;
  }
  if(b_mc_nues_px_ && !b_mc_nues_px_->TestBit(kDoNotProcess)){
    c_mc_nues_px_ = true;
  }else{
    c_mc_nues_px_ = false;
  }
  if(b_mc_nues_py_ && !b_mc_nues_py_->TestBit(kDoNotProcess)){
    c_mc_nues_py_ = true;
  }else{
    c_mc_nues_py_ = false;
  }
  if(b_mc_nues_pz_ && !b_mc_nues_pz_->TestBit(kDoNotProcess)){
    c_mc_nues_pz_ = true;
  }else{
    c_mc_nues_pz_ = false;
  }
  if(b_mc_nues_status_ && !b_mc_nues_status_->TestBit(kDoNotProcess)){
    c_mc_nues_status_ = true;
  }else{
    c_mc_nues_status_ = false;
  }
  if(b_mc_nues_theta_ && !b_mc_nues_theta_->TestBit(kDoNotProcess)){
    c_mc_nues_theta_ = true;
  }else{
    c_mc_nues_theta_ = false;
  }
  if(b_mc_nues_vertex_x_ && !b_mc_nues_vertex_x_->TestBit(kDoNotProcess)){
    c_mc_nues_vertex_x_ = true;
  }else{
    c_mc_nues_vertex_x_ = false;
  }
  if(b_mc_nues_vertex_y_ && !b_mc_nues_vertex_y_->TestBit(kDoNotProcess)){
    c_mc_nues_vertex_y_ = true;
  }else{
    c_mc_nues_vertex_y_ = false;
  }
  if(b_mc_nues_vertex_z_ && !b_mc_nues_vertex_z_->TestBit(kDoNotProcess)){
    c_mc_nues_vertex_z_ = true;
  }else{
    c_mc_nues_vertex_z_ = false;
  }
  if(b_mc_numus_charge_ && !b_mc_numus_charge_->TestBit(kDoNotProcess)){
    c_mc_numus_charge_ = true;
  }else{
    c_mc_numus_charge_ = false;
  }
  if(b_mc_numus_energy_ && !b_mc_numus_energy_->TestBit(kDoNotProcess)){
    c_mc_numus_energy_ = true;
  }else{
    c_mc_numus_energy_ = false;
  }
  if(b_mc_numus_eta_ && !b_mc_numus_eta_->TestBit(kDoNotProcess)){
    c_mc_numus_eta_ = true;
  }else{
    c_mc_numus_eta_ = false;
  }
  if(b_mc_numus_ggrandmother_id_ && !b_mc_numus_ggrandmother_id_->TestBit(kDoNotProcess)){
    c_mc_numus_ggrandmother_id_ = true;
  }else{
    c_mc_numus_ggrandmother_id_ = false;
  }
  if(b_mc_numus_grandmother_id_ && !b_mc_numus_grandmother_id_->TestBit(kDoNotProcess)){
    c_mc_numus_grandmother_id_ = true;
  }else{
    c_mc_numus_grandmother_id_ = false;
  }
  if(b_mc_numus_id_ && !b_mc_numus_id_->TestBit(kDoNotProcess)){
    c_mc_numus_id_ = true;
  }else{
    c_mc_numus_id_ = false;
  }
  if(b_mc_numus_mass_ && !b_mc_numus_mass_->TestBit(kDoNotProcess)){
    c_mc_numus_mass_ = true;
  }else{
    c_mc_numus_mass_ = false;
  }
  if(b_mc_numus_mother_id_ && !b_mc_numus_mother_id_->TestBit(kDoNotProcess)){
    c_mc_numus_mother_id_ = true;
  }else{
    c_mc_numus_mother_id_ = false;
  }
  if(b_mc_numus_mother_pt_ && !b_mc_numus_mother_pt_->TestBit(kDoNotProcess)){
    c_mc_numus_mother_pt_ = true;
  }else{
    c_mc_numus_mother_pt_ = false;
  }
  if(b_mc_numus_numOfDaughters_ && !b_mc_numus_numOfDaughters_->TestBit(kDoNotProcess)){
    c_mc_numus_numOfDaughters_ = true;
  }else{
    c_mc_numus_numOfDaughters_ = false;
  }
  if(b_mc_numus_phi_ && !b_mc_numus_phi_->TestBit(kDoNotProcess)){
    c_mc_numus_phi_ = true;
  }else{
    c_mc_numus_phi_ = false;
  }
  if(b_mc_numus_pt_ && !b_mc_numus_pt_->TestBit(kDoNotProcess)){
    c_mc_numus_pt_ = true;
  }else{
    c_mc_numus_pt_ = false;
  }
  if(b_mc_numus_px_ && !b_mc_numus_px_->TestBit(kDoNotProcess)){
    c_mc_numus_px_ = true;
  }else{
    c_mc_numus_px_ = false;
  }
  if(b_mc_numus_py_ && !b_mc_numus_py_->TestBit(kDoNotProcess)){
    c_mc_numus_py_ = true;
  }else{
    c_mc_numus_py_ = false;
  }
  if(b_mc_numus_pz_ && !b_mc_numus_pz_->TestBit(kDoNotProcess)){
    c_mc_numus_pz_ = true;
  }else{
    c_mc_numus_pz_ = false;
  }
  if(b_mc_numus_status_ && !b_mc_numus_status_->TestBit(kDoNotProcess)){
    c_mc_numus_status_ = true;
  }else{
    c_mc_numus_status_ = false;
  }
  if(b_mc_numus_theta_ && !b_mc_numus_theta_->TestBit(kDoNotProcess)){
    c_mc_numus_theta_ = true;
  }else{
    c_mc_numus_theta_ = false;
  }
  if(b_mc_numus_vertex_x_ && !b_mc_numus_vertex_x_->TestBit(kDoNotProcess)){
    c_mc_numus_vertex_x_ = true;
  }else{
    c_mc_numus_vertex_x_ = false;
  }
  if(b_mc_numus_vertex_y_ && !b_mc_numus_vertex_y_->TestBit(kDoNotProcess)){
    c_mc_numus_vertex_y_ = true;
  }else{
    c_mc_numus_vertex_y_ = false;
  }
  if(b_mc_numus_vertex_z_ && !b_mc_numus_vertex_z_->TestBit(kDoNotProcess)){
    c_mc_numus_vertex_z_ = true;
  }else{
    c_mc_numus_vertex_z_ = false;
  }
  if(b_mc_nutaus_charge_ && !b_mc_nutaus_charge_->TestBit(kDoNotProcess)){
    c_mc_nutaus_charge_ = true;
  }else{
    c_mc_nutaus_charge_ = false;
  }
  if(b_mc_nutaus_energy_ && !b_mc_nutaus_energy_->TestBit(kDoNotProcess)){
    c_mc_nutaus_energy_ = true;
  }else{
    c_mc_nutaus_energy_ = false;
  }
  if(b_mc_nutaus_eta_ && !b_mc_nutaus_eta_->TestBit(kDoNotProcess)){
    c_mc_nutaus_eta_ = true;
  }else{
    c_mc_nutaus_eta_ = false;
  }
  if(b_mc_nutaus_ggrandmother_id_ && !b_mc_nutaus_ggrandmother_id_->TestBit(kDoNotProcess)){
    c_mc_nutaus_ggrandmother_id_ = true;
  }else{
    c_mc_nutaus_ggrandmother_id_ = false;
  }
  if(b_mc_nutaus_grandmother_id_ && !b_mc_nutaus_grandmother_id_->TestBit(kDoNotProcess)){
    c_mc_nutaus_grandmother_id_ = true;
  }else{
    c_mc_nutaus_grandmother_id_ = false;
  }
  if(b_mc_nutaus_id_ && !b_mc_nutaus_id_->TestBit(kDoNotProcess)){
    c_mc_nutaus_id_ = true;
  }else{
    c_mc_nutaus_id_ = false;
  }
  if(b_mc_nutaus_mass_ && !b_mc_nutaus_mass_->TestBit(kDoNotProcess)){
    c_mc_nutaus_mass_ = true;
  }else{
    c_mc_nutaus_mass_ = false;
  }
  if(b_mc_nutaus_mother_id_ && !b_mc_nutaus_mother_id_->TestBit(kDoNotProcess)){
    c_mc_nutaus_mother_id_ = true;
  }else{
    c_mc_nutaus_mother_id_ = false;
  }
  if(b_mc_nutaus_mother_pt_ && !b_mc_nutaus_mother_pt_->TestBit(kDoNotProcess)){
    c_mc_nutaus_mother_pt_ = true;
  }else{
    c_mc_nutaus_mother_pt_ = false;
  }
  if(b_mc_nutaus_numOfDaughters_ && !b_mc_nutaus_numOfDaughters_->TestBit(kDoNotProcess)){
    c_mc_nutaus_numOfDaughters_ = true;
  }else{
    c_mc_nutaus_numOfDaughters_ = false;
  }
  if(b_mc_nutaus_phi_ && !b_mc_nutaus_phi_->TestBit(kDoNotProcess)){
    c_mc_nutaus_phi_ = true;
  }else{
    c_mc_nutaus_phi_ = false;
  }
  if(b_mc_nutaus_pt_ && !b_mc_nutaus_pt_->TestBit(kDoNotProcess)){
    c_mc_nutaus_pt_ = true;
  }else{
    c_mc_nutaus_pt_ = false;
  }
  if(b_mc_nutaus_px_ && !b_mc_nutaus_px_->TestBit(kDoNotProcess)){
    c_mc_nutaus_px_ = true;
  }else{
    c_mc_nutaus_px_ = false;
  }
  if(b_mc_nutaus_py_ && !b_mc_nutaus_py_->TestBit(kDoNotProcess)){
    c_mc_nutaus_py_ = true;
  }else{
    c_mc_nutaus_py_ = false;
  }
  if(b_mc_nutaus_pz_ && !b_mc_nutaus_pz_->TestBit(kDoNotProcess)){
    c_mc_nutaus_pz_ = true;
  }else{
    c_mc_nutaus_pz_ = false;
  }
  if(b_mc_nutaus_status_ && !b_mc_nutaus_status_->TestBit(kDoNotProcess)){
    c_mc_nutaus_status_ = true;
  }else{
    c_mc_nutaus_status_ = false;
  }
  if(b_mc_nutaus_theta_ && !b_mc_nutaus_theta_->TestBit(kDoNotProcess)){
    c_mc_nutaus_theta_ = true;
  }else{
    c_mc_nutaus_theta_ = false;
  }
  if(b_mc_nutaus_vertex_x_ && !b_mc_nutaus_vertex_x_->TestBit(kDoNotProcess)){
    c_mc_nutaus_vertex_x_ = true;
  }else{
    c_mc_nutaus_vertex_x_ = false;
  }
  if(b_mc_nutaus_vertex_y_ && !b_mc_nutaus_vertex_y_->TestBit(kDoNotProcess)){
    c_mc_nutaus_vertex_y_ = true;
  }else{
    c_mc_nutaus_vertex_y_ = false;
  }
  if(b_mc_nutaus_vertex_z_ && !b_mc_nutaus_vertex_z_->TestBit(kDoNotProcess)){
    c_mc_nutaus_vertex_z_ = true;
  }else{
    c_mc_nutaus_vertex_z_ = false;
  }
  if(b_mc_photons_charge_ && !b_mc_photons_charge_->TestBit(kDoNotProcess)){
    c_mc_photons_charge_ = true;
  }else{
    c_mc_photons_charge_ = false;
  }
  if(b_mc_photons_energy_ && !b_mc_photons_energy_->TestBit(kDoNotProcess)){
    c_mc_photons_energy_ = true;
  }else{
    c_mc_photons_energy_ = false;
  }
  if(b_mc_photons_eta_ && !b_mc_photons_eta_->TestBit(kDoNotProcess)){
    c_mc_photons_eta_ = true;
  }else{
    c_mc_photons_eta_ = false;
  }
  if(b_mc_photons_ggrandmother_id_ && !b_mc_photons_ggrandmother_id_->TestBit(kDoNotProcess)){
    c_mc_photons_ggrandmother_id_ = true;
  }else{
    c_mc_photons_ggrandmother_id_ = false;
  }
  if(b_mc_photons_grandmother_id_ && !b_mc_photons_grandmother_id_->TestBit(kDoNotProcess)){
    c_mc_photons_grandmother_id_ = true;
  }else{
    c_mc_photons_grandmother_id_ = false;
  }
  if(b_mc_photons_id_ && !b_mc_photons_id_->TestBit(kDoNotProcess)){
    c_mc_photons_id_ = true;
  }else{
    c_mc_photons_id_ = false;
  }
  if(b_mc_photons_mass_ && !b_mc_photons_mass_->TestBit(kDoNotProcess)){
    c_mc_photons_mass_ = true;
  }else{
    c_mc_photons_mass_ = false;
  }
  if(b_mc_photons_mother_id_ && !b_mc_photons_mother_id_->TestBit(kDoNotProcess)){
    c_mc_photons_mother_id_ = true;
  }else{
    c_mc_photons_mother_id_ = false;
  }
  if(b_mc_photons_mother_pt_ && !b_mc_photons_mother_pt_->TestBit(kDoNotProcess)){
    c_mc_photons_mother_pt_ = true;
  }else{
    c_mc_photons_mother_pt_ = false;
  }
  if(b_mc_photons_numOfDaughters_ && !b_mc_photons_numOfDaughters_->TestBit(kDoNotProcess)){
    c_mc_photons_numOfDaughters_ = true;
  }else{
    c_mc_photons_numOfDaughters_ = false;
  }
  if(b_mc_photons_phi_ && !b_mc_photons_phi_->TestBit(kDoNotProcess)){
    c_mc_photons_phi_ = true;
  }else{
    c_mc_photons_phi_ = false;
  }
  if(b_mc_photons_pt_ && !b_mc_photons_pt_->TestBit(kDoNotProcess)){
    c_mc_photons_pt_ = true;
  }else{
    c_mc_photons_pt_ = false;
  }
  if(b_mc_photons_px_ && !b_mc_photons_px_->TestBit(kDoNotProcess)){
    c_mc_photons_px_ = true;
  }else{
    c_mc_photons_px_ = false;
  }
  if(b_mc_photons_py_ && !b_mc_photons_py_->TestBit(kDoNotProcess)){
    c_mc_photons_py_ = true;
  }else{
    c_mc_photons_py_ = false;
  }
  if(b_mc_photons_pz_ && !b_mc_photons_pz_->TestBit(kDoNotProcess)){
    c_mc_photons_pz_ = true;
  }else{
    c_mc_photons_pz_ = false;
  }
  if(b_mc_photons_status_ && !b_mc_photons_status_->TestBit(kDoNotProcess)){
    c_mc_photons_status_ = true;
  }else{
    c_mc_photons_status_ = false;
  }
  if(b_mc_photons_theta_ && !b_mc_photons_theta_->TestBit(kDoNotProcess)){
    c_mc_photons_theta_ = true;
  }else{
    c_mc_photons_theta_ = false;
  }
  if(b_mc_photons_vertex_x_ && !b_mc_photons_vertex_x_->TestBit(kDoNotProcess)){
    c_mc_photons_vertex_x_ = true;
  }else{
    c_mc_photons_vertex_x_ = false;
  }
  if(b_mc_photons_vertex_y_ && !b_mc_photons_vertex_y_->TestBit(kDoNotProcess)){
    c_mc_photons_vertex_y_ = true;
  }else{
    c_mc_photons_vertex_y_ = false;
  }
  if(b_mc_photons_vertex_z_ && !b_mc_photons_vertex_z_->TestBit(kDoNotProcess)){
    c_mc_photons_vertex_z_ = true;
  }else{
    c_mc_photons_vertex_z_ = false;
  }
  if(b_mc_taus_charge_ && !b_mc_taus_charge_->TestBit(kDoNotProcess)){
    c_mc_taus_charge_ = true;
  }else{
    c_mc_taus_charge_ = false;
  }
  if(b_mc_taus_energy_ && !b_mc_taus_energy_->TestBit(kDoNotProcess)){
    c_mc_taus_energy_ = true;
  }else{
    c_mc_taus_energy_ = false;
  }
  if(b_mc_taus_eta_ && !b_mc_taus_eta_->TestBit(kDoNotProcess)){
    c_mc_taus_eta_ = true;
  }else{
    c_mc_taus_eta_ = false;
  }
  if(b_mc_taus_ggrandmother_id_ && !b_mc_taus_ggrandmother_id_->TestBit(kDoNotProcess)){
    c_mc_taus_ggrandmother_id_ = true;
  }else{
    c_mc_taus_ggrandmother_id_ = false;
  }
  if(b_mc_taus_grandmother_id_ && !b_mc_taus_grandmother_id_->TestBit(kDoNotProcess)){
    c_mc_taus_grandmother_id_ = true;
  }else{
    c_mc_taus_grandmother_id_ = false;
  }
  if(b_mc_taus_id_ && !b_mc_taus_id_->TestBit(kDoNotProcess)){
    c_mc_taus_id_ = true;
  }else{
    c_mc_taus_id_ = false;
  }
  if(b_mc_taus_mass_ && !b_mc_taus_mass_->TestBit(kDoNotProcess)){
    c_mc_taus_mass_ = true;
  }else{
    c_mc_taus_mass_ = false;
  }
  if(b_mc_taus_mother_id_ && !b_mc_taus_mother_id_->TestBit(kDoNotProcess)){
    c_mc_taus_mother_id_ = true;
  }else{
    c_mc_taus_mother_id_ = false;
  }
  if(b_mc_taus_mother_pt_ && !b_mc_taus_mother_pt_->TestBit(kDoNotProcess)){
    c_mc_taus_mother_pt_ = true;
  }else{
    c_mc_taus_mother_pt_ = false;
  }
  if(b_mc_taus_numOfDaughters_ && !b_mc_taus_numOfDaughters_->TestBit(kDoNotProcess)){
    c_mc_taus_numOfDaughters_ = true;
  }else{
    c_mc_taus_numOfDaughters_ = false;
  }
  if(b_mc_taus_phi_ && !b_mc_taus_phi_->TestBit(kDoNotProcess)){
    c_mc_taus_phi_ = true;
  }else{
    c_mc_taus_phi_ = false;
  }
  if(b_mc_taus_pt_ && !b_mc_taus_pt_->TestBit(kDoNotProcess)){
    c_mc_taus_pt_ = true;
  }else{
    c_mc_taus_pt_ = false;
  }
  if(b_mc_taus_px_ && !b_mc_taus_px_->TestBit(kDoNotProcess)){
    c_mc_taus_px_ = true;
  }else{
    c_mc_taus_px_ = false;
  }
  if(b_mc_taus_py_ && !b_mc_taus_py_->TestBit(kDoNotProcess)){
    c_mc_taus_py_ = true;
  }else{
    c_mc_taus_py_ = false;
  }
  if(b_mc_taus_pz_ && !b_mc_taus_pz_->TestBit(kDoNotProcess)){
    c_mc_taus_pz_ = true;
  }else{
    c_mc_taus_pz_ = false;
  }
  if(b_mc_taus_status_ && !b_mc_taus_status_->TestBit(kDoNotProcess)){
    c_mc_taus_status_ = true;
  }else{
    c_mc_taus_status_ = false;
  }
  if(b_mc_taus_theta_ && !b_mc_taus_theta_->TestBit(kDoNotProcess)){
    c_mc_taus_theta_ = true;
  }else{
    c_mc_taus_theta_ = false;
  }
  if(b_mc_taus_vertex_x_ && !b_mc_taus_vertex_x_->TestBit(kDoNotProcess)){
    c_mc_taus_vertex_x_ = true;
  }else{
    c_mc_taus_vertex_x_ = false;
  }
  if(b_mc_taus_vertex_y_ && !b_mc_taus_vertex_y_->TestBit(kDoNotProcess)){
    c_mc_taus_vertex_y_ = true;
  }else{
    c_mc_taus_vertex_y_ = false;
  }
  if(b_mc_taus_vertex_z_ && !b_mc_taus_vertex_z_->TestBit(kDoNotProcess)){
    c_mc_taus_vertex_z_ = true;
  }else{
    c_mc_taus_vertex_z_ = false;
  }
  if(b_model_params_ && !b_model_params_->TestBit(kDoNotProcess)){
    c_model_params_ = true;
  }else{
    c_model_params_ = false;
  }
  if(b_mus_cIso_ && !b_mus_cIso_->TestBit(kDoNotProcess)){
    c_mus_cIso_ = true;
  }else{
    c_mus_cIso_ = false;
  }
  if(b_mus_calEnergyEm_ && !b_mus_calEnergyEm_->TestBit(kDoNotProcess)){
    c_mus_calEnergyEm_ = true;
  }else{
    c_mus_calEnergyEm_ = false;
  }
  if(b_mus_calEnergyEmS9_ && !b_mus_calEnergyEmS9_->TestBit(kDoNotProcess)){
    c_mus_calEnergyEmS9_ = true;
  }else{
    c_mus_calEnergyEmS9_ = false;
  }
  if(b_mus_calEnergyHad_ && !b_mus_calEnergyHad_->TestBit(kDoNotProcess)){
    c_mus_calEnergyHad_ = true;
  }else{
    c_mus_calEnergyHad_ = false;
  }
  if(b_mus_calEnergyHadS9_ && !b_mus_calEnergyHadS9_->TestBit(kDoNotProcess)){
    c_mus_calEnergyHadS9_ = true;
  }else{
    c_mus_calEnergyHadS9_ = false;
  }
  if(b_mus_calEnergyHo_ && !b_mus_calEnergyHo_->TestBit(kDoNotProcess)){
    c_mus_calEnergyHo_ = true;
  }else{
    c_mus_calEnergyHo_ = false;
  }
  if(b_mus_calEnergyHoS9_ && !b_mus_calEnergyHoS9_->TestBit(kDoNotProcess)){
    c_mus_calEnergyHoS9_ = true;
  }else{
    c_mus_calEnergyHoS9_ = false;
  }
  if(b_mus_charge_ && !b_mus_charge_->TestBit(kDoNotProcess)){
    c_mus_charge_ = true;
  }else{
    c_mus_charge_ = false;
  }
  if(b_mus_cm_ExpectedHitsInner_ && !b_mus_cm_ExpectedHitsInner_->TestBit(kDoNotProcess)){
    c_mus_cm_ExpectedHitsInner_ = true;
  }else{
    c_mus_cm_ExpectedHitsInner_ = false;
  }
  if(b_mus_cm_ExpectedHitsOuter_ && !b_mus_cm_ExpectedHitsOuter_->TestBit(kDoNotProcess)){
    c_mus_cm_ExpectedHitsOuter_ = true;
  }else{
    c_mus_cm_ExpectedHitsOuter_ = false;
  }
  if(b_mus_cm_LayersWithMeasurement_ && !b_mus_cm_LayersWithMeasurement_->TestBit(kDoNotProcess)){
    c_mus_cm_LayersWithMeasurement_ = true;
  }else{
    c_mus_cm_LayersWithMeasurement_ = false;
  }
  if(b_mus_cm_LayersWithoutMeasurement_ && !b_mus_cm_LayersWithoutMeasurement_->TestBit(kDoNotProcess)){
    c_mus_cm_LayersWithoutMeasurement_ = true;
  }else{
    c_mus_cm_LayersWithoutMeasurement_ = false;
  }
  if(b_mus_cm_PixelLayersWithMeasurement_ && !b_mus_cm_PixelLayersWithMeasurement_->TestBit(kDoNotProcess)){
    c_mus_cm_PixelLayersWithMeasurement_ = true;
  }else{
    c_mus_cm_PixelLayersWithMeasurement_ = false;
  }
  if(b_mus_cm_ValidStripLayersWithMonoAndStereoHit_ && !b_mus_cm_ValidStripLayersWithMonoAndStereoHit_->TestBit(kDoNotProcess)){
    c_mus_cm_ValidStripLayersWithMonoAndStereoHit_ = true;
  }else{
    c_mus_cm_ValidStripLayersWithMonoAndStereoHit_ = false;
  }
  if(b_mus_cm_chg_ && !b_mus_cm_chg_->TestBit(kDoNotProcess)){
    c_mus_cm_chg_ = true;
  }else{
    c_mus_cm_chg_ = false;
  }
  if(b_mus_cm_chi2_ && !b_mus_cm_chi2_->TestBit(kDoNotProcess)){
    c_mus_cm_chi2_ = true;
  }else{
    c_mus_cm_chi2_ = false;
  }
  if(b_mus_cm_d0dum_ && !b_mus_cm_d0dum_->TestBit(kDoNotProcess)){
    c_mus_cm_d0dum_ = true;
  }else{
    c_mus_cm_d0dum_ = false;
  }
  if(b_mus_cm_d0dumErr_ && !b_mus_cm_d0dumErr_->TestBit(kDoNotProcess)){
    c_mus_cm_d0dumErr_ = true;
  }else{
    c_mus_cm_d0dumErr_ = false;
  }
  if(b_mus_cm_dz_ && !b_mus_cm_dz_->TestBit(kDoNotProcess)){
    c_mus_cm_dz_ = true;
  }else{
    c_mus_cm_dz_ = false;
  }
  if(b_mus_cm_dzErr_ && !b_mus_cm_dzErr_->TestBit(kDoNotProcess)){
    c_mus_cm_dzErr_ = true;
  }else{
    c_mus_cm_dzErr_ = false;
  }
  if(b_mus_cm_eta_ && !b_mus_cm_eta_->TestBit(kDoNotProcess)){
    c_mus_cm_eta_ = true;
  }else{
    c_mus_cm_eta_ = false;
  }
  if(b_mus_cm_etaErr_ && !b_mus_cm_etaErr_->TestBit(kDoNotProcess)){
    c_mus_cm_etaErr_ = true;
  }else{
    c_mus_cm_etaErr_ = false;
  }
  if(b_mus_cm_ndof_ && !b_mus_cm_ndof_->TestBit(kDoNotProcess)){
    c_mus_cm_ndof_ = true;
  }else{
    c_mus_cm_ndof_ = false;
  }
  if(b_mus_cm_numlosthits_ && !b_mus_cm_numlosthits_->TestBit(kDoNotProcess)){
    c_mus_cm_numlosthits_ = true;
  }else{
    c_mus_cm_numlosthits_ = false;
  }
  if(b_mus_cm_numvalMuonhits_ && !b_mus_cm_numvalMuonhits_->TestBit(kDoNotProcess)){
    c_mus_cm_numvalMuonhits_ = true;
  }else{
    c_mus_cm_numvalMuonhits_ = false;
  }
  if(b_mus_cm_numvalhits_ && !b_mus_cm_numvalhits_->TestBit(kDoNotProcess)){
    c_mus_cm_numvalhits_ = true;
  }else{
    c_mus_cm_numvalhits_ = false;
  }
  if(b_mus_cm_phi_ && !b_mus_cm_phi_->TestBit(kDoNotProcess)){
    c_mus_cm_phi_ = true;
  }else{
    c_mus_cm_phi_ = false;
  }
  if(b_mus_cm_phiErr_ && !b_mus_cm_phiErr_->TestBit(kDoNotProcess)){
    c_mus_cm_phiErr_ = true;
  }else{
    c_mus_cm_phiErr_ = false;
  }
  if(b_mus_cm_pt_ && !b_mus_cm_pt_->TestBit(kDoNotProcess)){
    c_mus_cm_pt_ = true;
  }else{
    c_mus_cm_pt_ = false;
  }
  if(b_mus_cm_ptErr_ && !b_mus_cm_ptErr_->TestBit(kDoNotProcess)){
    c_mus_cm_ptErr_ = true;
  }else{
    c_mus_cm_ptErr_ = false;
  }
  if(b_mus_cm_px_ && !b_mus_cm_px_->TestBit(kDoNotProcess)){
    c_mus_cm_px_ = true;
  }else{
    c_mus_cm_px_ = false;
  }
  if(b_mus_cm_py_ && !b_mus_cm_py_->TestBit(kDoNotProcess)){
    c_mus_cm_py_ = true;
  }else{
    c_mus_cm_py_ = false;
  }
  if(b_mus_cm_pz_ && !b_mus_cm_pz_->TestBit(kDoNotProcess)){
    c_mus_cm_pz_ = true;
  }else{
    c_mus_cm_pz_ = false;
  }
  if(b_mus_cm_theta_ && !b_mus_cm_theta_->TestBit(kDoNotProcess)){
    c_mus_cm_theta_ = true;
  }else{
    c_mus_cm_theta_ = false;
  }
  if(b_mus_cm_vx_ && !b_mus_cm_vx_->TestBit(kDoNotProcess)){
    c_mus_cm_vx_ = true;
  }else{
    c_mus_cm_vx_ = false;
  }
  if(b_mus_cm_vy_ && !b_mus_cm_vy_->TestBit(kDoNotProcess)){
    c_mus_cm_vy_ = true;
  }else{
    c_mus_cm_vy_ = false;
  }
  if(b_mus_cm_vz_ && !b_mus_cm_vz_->TestBit(kDoNotProcess)){
    c_mus_cm_vz_ = true;
  }else{
    c_mus_cm_vz_ = false;
  }
  if(b_mus_dB_ && !b_mus_dB_->TestBit(kDoNotProcess)){
    c_mus_dB_ = true;
  }else{
    c_mus_dB_ = false;
  }
  if(b_mus_ecalIso_ && !b_mus_ecalIso_->TestBit(kDoNotProcess)){
    c_mus_ecalIso_ = true;
  }else{
    c_mus_ecalIso_ = false;
  }
  if(b_mus_ecalvetoDep_ && !b_mus_ecalvetoDep_->TestBit(kDoNotProcess)){
    c_mus_ecalvetoDep_ = true;
  }else{
    c_mus_ecalvetoDep_ = false;
  }
  if(b_mus_energy_ && !b_mus_energy_->TestBit(kDoNotProcess)){
    c_mus_energy_ = true;
  }else{
    c_mus_energy_ = false;
  }
  if(b_mus_et_ && !b_mus_et_->TestBit(kDoNotProcess)){
    c_mus_et_ = true;
  }else{
    c_mus_et_ = false;
  }
  if(b_mus_eta_ && !b_mus_eta_->TestBit(kDoNotProcess)){
    c_mus_eta_ = true;
  }else{
    c_mus_eta_ = false;
  }
  if(b_mus_gen_et_ && !b_mus_gen_et_->TestBit(kDoNotProcess)){
    c_mus_gen_et_ = true;
  }else{
    c_mus_gen_et_ = false;
  }
  if(b_mus_gen_eta_ && !b_mus_gen_eta_->TestBit(kDoNotProcess)){
    c_mus_gen_eta_ = true;
  }else{
    c_mus_gen_eta_ = false;
  }
  if(b_mus_gen_id_ && !b_mus_gen_id_->TestBit(kDoNotProcess)){
    c_mus_gen_id_ = true;
  }else{
    c_mus_gen_id_ = false;
  }
  if(b_mus_gen_mother_et_ && !b_mus_gen_mother_et_->TestBit(kDoNotProcess)){
    c_mus_gen_mother_et_ = true;
  }else{
    c_mus_gen_mother_et_ = false;
  }
  if(b_mus_gen_mother_eta_ && !b_mus_gen_mother_eta_->TestBit(kDoNotProcess)){
    c_mus_gen_mother_eta_ = true;
  }else{
    c_mus_gen_mother_eta_ = false;
  }
  if(b_mus_gen_mother_id_ && !b_mus_gen_mother_id_->TestBit(kDoNotProcess)){
    c_mus_gen_mother_id_ = true;
  }else{
    c_mus_gen_mother_id_ = false;
  }
  if(b_mus_gen_mother_phi_ && !b_mus_gen_mother_phi_->TestBit(kDoNotProcess)){
    c_mus_gen_mother_phi_ = true;
  }else{
    c_mus_gen_mother_phi_ = false;
  }
  if(b_mus_gen_mother_pt_ && !b_mus_gen_mother_pt_->TestBit(kDoNotProcess)){
    c_mus_gen_mother_pt_ = true;
  }else{
    c_mus_gen_mother_pt_ = false;
  }
  if(b_mus_gen_mother_px_ && !b_mus_gen_mother_px_->TestBit(kDoNotProcess)){
    c_mus_gen_mother_px_ = true;
  }else{
    c_mus_gen_mother_px_ = false;
  }
  if(b_mus_gen_mother_py_ && !b_mus_gen_mother_py_->TestBit(kDoNotProcess)){
    c_mus_gen_mother_py_ = true;
  }else{
    c_mus_gen_mother_py_ = false;
  }
  if(b_mus_gen_mother_pz_ && !b_mus_gen_mother_pz_->TestBit(kDoNotProcess)){
    c_mus_gen_mother_pz_ = true;
  }else{
    c_mus_gen_mother_pz_ = false;
  }
  if(b_mus_gen_mother_theta_ && !b_mus_gen_mother_theta_->TestBit(kDoNotProcess)){
    c_mus_gen_mother_theta_ = true;
  }else{
    c_mus_gen_mother_theta_ = false;
  }
  if(b_mus_gen_phi_ && !b_mus_gen_phi_->TestBit(kDoNotProcess)){
    c_mus_gen_phi_ = true;
  }else{
    c_mus_gen_phi_ = false;
  }
  if(b_mus_gen_pt_ && !b_mus_gen_pt_->TestBit(kDoNotProcess)){
    c_mus_gen_pt_ = true;
  }else{
    c_mus_gen_pt_ = false;
  }
  if(b_mus_gen_px_ && !b_mus_gen_px_->TestBit(kDoNotProcess)){
    c_mus_gen_px_ = true;
  }else{
    c_mus_gen_px_ = false;
  }
  if(b_mus_gen_py_ && !b_mus_gen_py_->TestBit(kDoNotProcess)){
    c_mus_gen_py_ = true;
  }else{
    c_mus_gen_py_ = false;
  }
  if(b_mus_gen_pz_ && !b_mus_gen_pz_->TestBit(kDoNotProcess)){
    c_mus_gen_pz_ = true;
  }else{
    c_mus_gen_pz_ = false;
  }
  if(b_mus_gen_theta_ && !b_mus_gen_theta_->TestBit(kDoNotProcess)){
    c_mus_gen_theta_ = true;
  }else{
    c_mus_gen_theta_ = false;
  }
  if(b_mus_hcalIso_ && !b_mus_hcalIso_->TestBit(kDoNotProcess)){
    c_mus_hcalIso_ = true;
  }else{
    c_mus_hcalIso_ = false;
  }
  if(b_mus_hcalvetoDep_ && !b_mus_hcalvetoDep_->TestBit(kDoNotProcess)){
    c_mus_hcalvetoDep_ = true;
  }else{
    c_mus_hcalvetoDep_ = false;
  }
  if(b_mus_id_All_ && !b_mus_id_All_->TestBit(kDoNotProcess)){
    c_mus_id_All_ = true;
  }else{
    c_mus_id_All_ = false;
  }
  if(b_mus_id_AllArbitrated_ && !b_mus_id_AllArbitrated_->TestBit(kDoNotProcess)){
    c_mus_id_AllArbitrated_ = true;
  }else{
    c_mus_id_AllArbitrated_ = false;
  }
  if(b_mus_id_AllGlobalMuons_ && !b_mus_id_AllGlobalMuons_->TestBit(kDoNotProcess)){
    c_mus_id_AllGlobalMuons_ = true;
  }else{
    c_mus_id_AllGlobalMuons_ = false;
  }
  if(b_mus_id_AllStandAloneMuons_ && !b_mus_id_AllStandAloneMuons_->TestBit(kDoNotProcess)){
    c_mus_id_AllStandAloneMuons_ = true;
  }else{
    c_mus_id_AllStandAloneMuons_ = false;
  }
  if(b_mus_id_AllTrackerMuons_ && !b_mus_id_AllTrackerMuons_->TestBit(kDoNotProcess)){
    c_mus_id_AllTrackerMuons_ = true;
  }else{
    c_mus_id_AllTrackerMuons_ = false;
  }
  if(b_mus_id_GlobalMuonPromptTight_ && !b_mus_id_GlobalMuonPromptTight_->TestBit(kDoNotProcess)){
    c_mus_id_GlobalMuonPromptTight_ = true;
  }else{
    c_mus_id_GlobalMuonPromptTight_ = false;
  }
  if(b_mus_id_TM2DCompatibilityLoose_ && !b_mus_id_TM2DCompatibilityLoose_->TestBit(kDoNotProcess)){
    c_mus_id_TM2DCompatibilityLoose_ = true;
  }else{
    c_mus_id_TM2DCompatibilityLoose_ = false;
  }
  if(b_mus_id_TM2DCompatibilityTight_ && !b_mus_id_TM2DCompatibilityTight_->TestBit(kDoNotProcess)){
    c_mus_id_TM2DCompatibilityTight_ = true;
  }else{
    c_mus_id_TM2DCompatibilityTight_ = false;
  }
  if(b_mus_id_TMLastStationLoose_ && !b_mus_id_TMLastStationLoose_->TestBit(kDoNotProcess)){
    c_mus_id_TMLastStationLoose_ = true;
  }else{
    c_mus_id_TMLastStationLoose_ = false;
  }
  if(b_mus_id_TMLastStationOptimizedLowPtLoose_ && !b_mus_id_TMLastStationOptimizedLowPtLoose_->TestBit(kDoNotProcess)){
    c_mus_id_TMLastStationOptimizedLowPtLoose_ = true;
  }else{
    c_mus_id_TMLastStationOptimizedLowPtLoose_ = false;
  }
  if(b_mus_id_TMLastStationOptimizedLowPtTight_ && !b_mus_id_TMLastStationOptimizedLowPtTight_->TestBit(kDoNotProcess)){
    c_mus_id_TMLastStationOptimizedLowPtTight_ = true;
  }else{
    c_mus_id_TMLastStationOptimizedLowPtTight_ = false;
  }
  if(b_mus_id_TMLastStationTight_ && !b_mus_id_TMLastStationTight_->TestBit(kDoNotProcess)){
    c_mus_id_TMLastStationTight_ = true;
  }else{
    c_mus_id_TMLastStationTight_ = false;
  }
  if(b_mus_id_TMOneStationLoose_ && !b_mus_id_TMOneStationLoose_->TestBit(kDoNotProcess)){
    c_mus_id_TMOneStationLoose_ = true;
  }else{
    c_mus_id_TMOneStationLoose_ = false;
  }
  if(b_mus_id_TMOneStationTight_ && !b_mus_id_TMOneStationTight_->TestBit(kDoNotProcess)){
    c_mus_id_TMOneStationTight_ = true;
  }else{
    c_mus_id_TMOneStationTight_ = false;
  }
  if(b_mus_id_TrackerMuonArbitrated_ && !b_mus_id_TrackerMuonArbitrated_->TestBit(kDoNotProcess)){
    c_mus_id_TrackerMuonArbitrated_ = true;
  }else{
    c_mus_id_TrackerMuonArbitrated_ = false;
  }
  if(b_mus_isCaloMuon_ && !b_mus_isCaloMuon_->TestBit(kDoNotProcess)){
    c_mus_isCaloMuon_ = true;
  }else{
    c_mus_isCaloMuon_ = false;
  }
  if(b_mus_isConvertedPhoton_ && !b_mus_isConvertedPhoton_->TestBit(kDoNotProcess)){
    c_mus_isConvertedPhoton_ = true;
  }else{
    c_mus_isConvertedPhoton_ = false;
  }
  if(b_mus_isElectron_ && !b_mus_isElectron_->TestBit(kDoNotProcess)){
    c_mus_isElectron_ = true;
  }else{
    c_mus_isElectron_ = false;
  }
  if(b_mus_isGlobalMuon_ && !b_mus_isGlobalMuon_->TestBit(kDoNotProcess)){
    c_mus_isGlobalMuon_ = true;
  }else{
    c_mus_isGlobalMuon_ = false;
  }
  if(b_mus_isPFMuon_ && !b_mus_isPFMuon_->TestBit(kDoNotProcess)){
    c_mus_isPFMuon_ = true;
  }else{
    c_mus_isPFMuon_ = false;
  }
  if(b_mus_isPhoton_ && !b_mus_isPhoton_->TestBit(kDoNotProcess)){
    c_mus_isPhoton_ = true;
  }else{
    c_mus_isPhoton_ = false;
  }
  if(b_mus_isStandAloneMuon_ && !b_mus_isStandAloneMuon_->TestBit(kDoNotProcess)){
    c_mus_isStandAloneMuon_ = true;
  }else{
    c_mus_isStandAloneMuon_ = false;
  }
  if(b_mus_isTrackerMuon_ && !b_mus_isTrackerMuon_->TestBit(kDoNotProcess)){
    c_mus_isTrackerMuon_ = true;
  }else{
    c_mus_isTrackerMuon_ = false;
  }
  if(b_mus_iso03_emEt_ && !b_mus_iso03_emEt_->TestBit(kDoNotProcess)){
    c_mus_iso03_emEt_ = true;
  }else{
    c_mus_iso03_emEt_ = false;
  }
  if(b_mus_iso03_emVetoEt_ && !b_mus_iso03_emVetoEt_->TestBit(kDoNotProcess)){
    c_mus_iso03_emVetoEt_ = true;
  }else{
    c_mus_iso03_emVetoEt_ = false;
  }
  if(b_mus_iso03_hadEt_ && !b_mus_iso03_hadEt_->TestBit(kDoNotProcess)){
    c_mus_iso03_hadEt_ = true;
  }else{
    c_mus_iso03_hadEt_ = false;
  }
  if(b_mus_iso03_hadVetoEt_ && !b_mus_iso03_hadVetoEt_->TestBit(kDoNotProcess)){
    c_mus_iso03_hadVetoEt_ = true;
  }else{
    c_mus_iso03_hadVetoEt_ = false;
  }
  if(b_mus_iso03_hoEt_ && !b_mus_iso03_hoEt_->TestBit(kDoNotProcess)){
    c_mus_iso03_hoEt_ = true;
  }else{
    c_mus_iso03_hoEt_ = false;
  }
  if(b_mus_iso03_nTracks_ && !b_mus_iso03_nTracks_->TestBit(kDoNotProcess)){
    c_mus_iso03_nTracks_ = true;
  }else{
    c_mus_iso03_nTracks_ = false;
  }
  if(b_mus_iso03_sumPt_ && !b_mus_iso03_sumPt_->TestBit(kDoNotProcess)){
    c_mus_iso03_sumPt_ = true;
  }else{
    c_mus_iso03_sumPt_ = false;
  }
  if(b_mus_iso05_emEt_ && !b_mus_iso05_emEt_->TestBit(kDoNotProcess)){
    c_mus_iso05_emEt_ = true;
  }else{
    c_mus_iso05_emEt_ = false;
  }
  if(b_mus_iso05_hadEt_ && !b_mus_iso05_hadEt_->TestBit(kDoNotProcess)){
    c_mus_iso05_hadEt_ = true;
  }else{
    c_mus_iso05_hadEt_ = false;
  }
  if(b_mus_iso05_hoEt_ && !b_mus_iso05_hoEt_->TestBit(kDoNotProcess)){
    c_mus_iso05_hoEt_ = true;
  }else{
    c_mus_iso05_hoEt_ = false;
  }
  if(b_mus_iso05_nTracks_ && !b_mus_iso05_nTracks_->TestBit(kDoNotProcess)){
    c_mus_iso05_nTracks_ = true;
  }else{
    c_mus_iso05_nTracks_ = false;
  }
  if(b_mus_iso05_sumPt_ && !b_mus_iso05_sumPt_->TestBit(kDoNotProcess)){
    c_mus_iso05_sumPt_ = true;
  }else{
    c_mus_iso05_sumPt_ = false;
  }
  if(b_mus_num_matches_ && !b_mus_num_matches_->TestBit(kDoNotProcess)){
    c_mus_num_matches_ = true;
  }else{
    c_mus_num_matches_ = false;
  }
  if(b_mus_numberOfMatchedStations_ && !b_mus_numberOfMatchedStations_->TestBit(kDoNotProcess)){
    c_mus_numberOfMatchedStations_ = true;
  }else{
    c_mus_numberOfMatchedStations_ = false;
  }
  if(b_mus_pfIsolationR03_sumChargedHadronPt_ && !b_mus_pfIsolationR03_sumChargedHadronPt_->TestBit(kDoNotProcess)){
    c_mus_pfIsolationR03_sumChargedHadronPt_ = true;
  }else{
    c_mus_pfIsolationR03_sumChargedHadronPt_ = false;
  }
  if(b_mus_pfIsolationR03_sumChargedParticlePt_ && !b_mus_pfIsolationR03_sumChargedParticlePt_->TestBit(kDoNotProcess)){
    c_mus_pfIsolationR03_sumChargedParticlePt_ = true;
  }else{
    c_mus_pfIsolationR03_sumChargedParticlePt_ = false;
  }
  if(b_mus_pfIsolationR03_sumNeutralHadronEt_ && !b_mus_pfIsolationR03_sumNeutralHadronEt_->TestBit(kDoNotProcess)){
    c_mus_pfIsolationR03_sumNeutralHadronEt_ = true;
  }else{
    c_mus_pfIsolationR03_sumNeutralHadronEt_ = false;
  }
  if(b_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_ && !b_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_->TestBit(kDoNotProcess)){
    c_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_ = true;
  }else{
    c_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_ = false;
  }
  if(b_mus_pfIsolationR03_sumPUPt_ && !b_mus_pfIsolationR03_sumPUPt_->TestBit(kDoNotProcess)){
    c_mus_pfIsolationR03_sumPUPt_ = true;
  }else{
    c_mus_pfIsolationR03_sumPUPt_ = false;
  }
  if(b_mus_pfIsolationR03_sumPhotonEt_ && !b_mus_pfIsolationR03_sumPhotonEt_->TestBit(kDoNotProcess)){
    c_mus_pfIsolationR03_sumPhotonEt_ = true;
  }else{
    c_mus_pfIsolationR03_sumPhotonEt_ = false;
  }
  if(b_mus_pfIsolationR03_sumPhotonEtHighThreshold_ && !b_mus_pfIsolationR03_sumPhotonEtHighThreshold_->TestBit(kDoNotProcess)){
    c_mus_pfIsolationR03_sumPhotonEtHighThreshold_ = true;
  }else{
    c_mus_pfIsolationR03_sumPhotonEtHighThreshold_ = false;
  }
  if(b_mus_pfIsolationR04_sumChargedHadronPt_ && !b_mus_pfIsolationR04_sumChargedHadronPt_->TestBit(kDoNotProcess)){
    c_mus_pfIsolationR04_sumChargedHadronPt_ = true;
  }else{
    c_mus_pfIsolationR04_sumChargedHadronPt_ = false;
  }
  if(b_mus_pfIsolationR04_sumChargedParticlePt_ && !b_mus_pfIsolationR04_sumChargedParticlePt_->TestBit(kDoNotProcess)){
    c_mus_pfIsolationR04_sumChargedParticlePt_ = true;
  }else{
    c_mus_pfIsolationR04_sumChargedParticlePt_ = false;
  }
  if(b_mus_pfIsolationR04_sumNeutralHadronEt_ && !b_mus_pfIsolationR04_sumNeutralHadronEt_->TestBit(kDoNotProcess)){
    c_mus_pfIsolationR04_sumNeutralHadronEt_ = true;
  }else{
    c_mus_pfIsolationR04_sumNeutralHadronEt_ = false;
  }
  if(b_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_ && !b_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_->TestBit(kDoNotProcess)){
    c_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_ = true;
  }else{
    c_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_ = false;
  }
  if(b_mus_pfIsolationR04_sumPUPt_ && !b_mus_pfIsolationR04_sumPUPt_->TestBit(kDoNotProcess)){
    c_mus_pfIsolationR04_sumPUPt_ = true;
  }else{
    c_mus_pfIsolationR04_sumPUPt_ = false;
  }
  if(b_mus_pfIsolationR04_sumPhotonEt_ && !b_mus_pfIsolationR04_sumPhotonEt_->TestBit(kDoNotProcess)){
    c_mus_pfIsolationR04_sumPhotonEt_ = true;
  }else{
    c_mus_pfIsolationR04_sumPhotonEt_ = false;
  }
  if(b_mus_pfIsolationR04_sumPhotonEtHighThreshold_ && !b_mus_pfIsolationR04_sumPhotonEtHighThreshold_->TestBit(kDoNotProcess)){
    c_mus_pfIsolationR04_sumPhotonEtHighThreshold_ = true;
  }else{
    c_mus_pfIsolationR04_sumPhotonEtHighThreshold_ = false;
  }
  if(b_mus_phi_ && !b_mus_phi_->TestBit(kDoNotProcess)){
    c_mus_phi_ = true;
  }else{
    c_mus_phi_ = false;
  }
  if(b_mus_picky_ExpectedHitsInner_ && !b_mus_picky_ExpectedHitsInner_->TestBit(kDoNotProcess)){
    c_mus_picky_ExpectedHitsInner_ = true;
  }else{
    c_mus_picky_ExpectedHitsInner_ = false;
  }
  if(b_mus_picky_ExpectedHitsOuter_ && !b_mus_picky_ExpectedHitsOuter_->TestBit(kDoNotProcess)){
    c_mus_picky_ExpectedHitsOuter_ = true;
  }else{
    c_mus_picky_ExpectedHitsOuter_ = false;
  }
  if(b_mus_picky_LayersWithMeasurement_ && !b_mus_picky_LayersWithMeasurement_->TestBit(kDoNotProcess)){
    c_mus_picky_LayersWithMeasurement_ = true;
  }else{
    c_mus_picky_LayersWithMeasurement_ = false;
  }
  if(b_mus_picky_LayersWithoutMeasurement_ && !b_mus_picky_LayersWithoutMeasurement_->TestBit(kDoNotProcess)){
    c_mus_picky_LayersWithoutMeasurement_ = true;
  }else{
    c_mus_picky_LayersWithoutMeasurement_ = false;
  }
  if(b_mus_picky_PixelLayersWithMeasurement_ && !b_mus_picky_PixelLayersWithMeasurement_->TestBit(kDoNotProcess)){
    c_mus_picky_PixelLayersWithMeasurement_ = true;
  }else{
    c_mus_picky_PixelLayersWithMeasurement_ = false;
  }
  if(b_mus_picky_ValidStripLayersWithMonoAndStereoHit_ && !b_mus_picky_ValidStripLayersWithMonoAndStereoHit_->TestBit(kDoNotProcess)){
    c_mus_picky_ValidStripLayersWithMonoAndStereoHit_ = true;
  }else{
    c_mus_picky_ValidStripLayersWithMonoAndStereoHit_ = false;
  }
  if(b_mus_picky_chg_ && !b_mus_picky_chg_->TestBit(kDoNotProcess)){
    c_mus_picky_chg_ = true;
  }else{
    c_mus_picky_chg_ = false;
  }
  if(b_mus_picky_chi2_ && !b_mus_picky_chi2_->TestBit(kDoNotProcess)){
    c_mus_picky_chi2_ = true;
  }else{
    c_mus_picky_chi2_ = false;
  }
  if(b_mus_picky_d0dum_ && !b_mus_picky_d0dum_->TestBit(kDoNotProcess)){
    c_mus_picky_d0dum_ = true;
  }else{
    c_mus_picky_d0dum_ = false;
  }
  if(b_mus_picky_d0dumErr_ && !b_mus_picky_d0dumErr_->TestBit(kDoNotProcess)){
    c_mus_picky_d0dumErr_ = true;
  }else{
    c_mus_picky_d0dumErr_ = false;
  }
  if(b_mus_picky_dz_ && !b_mus_picky_dz_->TestBit(kDoNotProcess)){
    c_mus_picky_dz_ = true;
  }else{
    c_mus_picky_dz_ = false;
  }
  if(b_mus_picky_dzErr_ && !b_mus_picky_dzErr_->TestBit(kDoNotProcess)){
    c_mus_picky_dzErr_ = true;
  }else{
    c_mus_picky_dzErr_ = false;
  }
  if(b_mus_picky_eta_ && !b_mus_picky_eta_->TestBit(kDoNotProcess)){
    c_mus_picky_eta_ = true;
  }else{
    c_mus_picky_eta_ = false;
  }
  if(b_mus_picky_etaErr_ && !b_mus_picky_etaErr_->TestBit(kDoNotProcess)){
    c_mus_picky_etaErr_ = true;
  }else{
    c_mus_picky_etaErr_ = false;
  }
  if(b_mus_picky_id_ && !b_mus_picky_id_->TestBit(kDoNotProcess)){
    c_mus_picky_id_ = true;
  }else{
    c_mus_picky_id_ = false;
  }
  if(b_mus_picky_ndof_ && !b_mus_picky_ndof_->TestBit(kDoNotProcess)){
    c_mus_picky_ndof_ = true;
  }else{
    c_mus_picky_ndof_ = false;
  }
  if(b_mus_picky_numlosthits_ && !b_mus_picky_numlosthits_->TestBit(kDoNotProcess)){
    c_mus_picky_numlosthits_ = true;
  }else{
    c_mus_picky_numlosthits_ = false;
  }
  if(b_mus_picky_numvalPixelhits_ && !b_mus_picky_numvalPixelhits_->TestBit(kDoNotProcess)){
    c_mus_picky_numvalPixelhits_ = true;
  }else{
    c_mus_picky_numvalPixelhits_ = false;
  }
  if(b_mus_picky_numvalhits_ && !b_mus_picky_numvalhits_->TestBit(kDoNotProcess)){
    c_mus_picky_numvalhits_ = true;
  }else{
    c_mus_picky_numvalhits_ = false;
  }
  if(b_mus_picky_phi_ && !b_mus_picky_phi_->TestBit(kDoNotProcess)){
    c_mus_picky_phi_ = true;
  }else{
    c_mus_picky_phi_ = false;
  }
  if(b_mus_picky_phiErr_ && !b_mus_picky_phiErr_->TestBit(kDoNotProcess)){
    c_mus_picky_phiErr_ = true;
  }else{
    c_mus_picky_phiErr_ = false;
  }
  if(b_mus_picky_pt_ && !b_mus_picky_pt_->TestBit(kDoNotProcess)){
    c_mus_picky_pt_ = true;
  }else{
    c_mus_picky_pt_ = false;
  }
  if(b_mus_picky_ptErr_ && !b_mus_picky_ptErr_->TestBit(kDoNotProcess)){
    c_mus_picky_ptErr_ = true;
  }else{
    c_mus_picky_ptErr_ = false;
  }
  if(b_mus_picky_px_ && !b_mus_picky_px_->TestBit(kDoNotProcess)){
    c_mus_picky_px_ = true;
  }else{
    c_mus_picky_px_ = false;
  }
  if(b_mus_picky_py_ && !b_mus_picky_py_->TestBit(kDoNotProcess)){
    c_mus_picky_py_ = true;
  }else{
    c_mus_picky_py_ = false;
  }
  if(b_mus_picky_pz_ && !b_mus_picky_pz_->TestBit(kDoNotProcess)){
    c_mus_picky_pz_ = true;
  }else{
    c_mus_picky_pz_ = false;
  }
  if(b_mus_picky_theta_ && !b_mus_picky_theta_->TestBit(kDoNotProcess)){
    c_mus_picky_theta_ = true;
  }else{
    c_mus_picky_theta_ = false;
  }
  if(b_mus_picky_vx_ && !b_mus_picky_vx_->TestBit(kDoNotProcess)){
    c_mus_picky_vx_ = true;
  }else{
    c_mus_picky_vx_ = false;
  }
  if(b_mus_picky_vy_ && !b_mus_picky_vy_->TestBit(kDoNotProcess)){
    c_mus_picky_vy_ = true;
  }else{
    c_mus_picky_vy_ = false;
  }
  if(b_mus_picky_vz_ && !b_mus_picky_vz_->TestBit(kDoNotProcess)){
    c_mus_picky_vz_ = true;
  }else{
    c_mus_picky_vz_ = false;
  }
  if(b_mus_pt_ && !b_mus_pt_->TestBit(kDoNotProcess)){
    c_mus_pt_ = true;
  }else{
    c_mus_pt_ = false;
  }
  if(b_mus_px_ && !b_mus_px_->TestBit(kDoNotProcess)){
    c_mus_px_ = true;
  }else{
    c_mus_px_ = false;
  }
  if(b_mus_py_ && !b_mus_py_->TestBit(kDoNotProcess)){
    c_mus_py_ = true;
  }else{
    c_mus_py_ = false;
  }
  if(b_mus_pz_ && !b_mus_pz_->TestBit(kDoNotProcess)){
    c_mus_pz_ = true;
  }else{
    c_mus_pz_ = false;
  }
  if(b_mus_stamu_chg_ && !b_mus_stamu_chg_->TestBit(kDoNotProcess)){
    c_mus_stamu_chg_ = true;
  }else{
    c_mus_stamu_chg_ = false;
  }
  if(b_mus_stamu_chi2_ && !b_mus_stamu_chi2_->TestBit(kDoNotProcess)){
    c_mus_stamu_chi2_ = true;
  }else{
    c_mus_stamu_chi2_ = false;
  }
  if(b_mus_stamu_d0dum_ && !b_mus_stamu_d0dum_->TestBit(kDoNotProcess)){
    c_mus_stamu_d0dum_ = true;
  }else{
    c_mus_stamu_d0dum_ = false;
  }
  if(b_mus_stamu_d0dumErr_ && !b_mus_stamu_d0dumErr_->TestBit(kDoNotProcess)){
    c_mus_stamu_d0dumErr_ = true;
  }else{
    c_mus_stamu_d0dumErr_ = false;
  }
  if(b_mus_stamu_dz_ && !b_mus_stamu_dz_->TestBit(kDoNotProcess)){
    c_mus_stamu_dz_ = true;
  }else{
    c_mus_stamu_dz_ = false;
  }
  if(b_mus_stamu_dzErr_ && !b_mus_stamu_dzErr_->TestBit(kDoNotProcess)){
    c_mus_stamu_dzErr_ = true;
  }else{
    c_mus_stamu_dzErr_ = false;
  }
  if(b_mus_stamu_eta_ && !b_mus_stamu_eta_->TestBit(kDoNotProcess)){
    c_mus_stamu_eta_ = true;
  }else{
    c_mus_stamu_eta_ = false;
  }
  if(b_mus_stamu_etaErr_ && !b_mus_stamu_etaErr_->TestBit(kDoNotProcess)){
    c_mus_stamu_etaErr_ = true;
  }else{
    c_mus_stamu_etaErr_ = false;
  }
  if(b_mus_stamu_ndof_ && !b_mus_stamu_ndof_->TestBit(kDoNotProcess)){
    c_mus_stamu_ndof_ = true;
  }else{
    c_mus_stamu_ndof_ = false;
  }
  if(b_mus_stamu_numlosthits_ && !b_mus_stamu_numlosthits_->TestBit(kDoNotProcess)){
    c_mus_stamu_numlosthits_ = true;
  }else{
    c_mus_stamu_numlosthits_ = false;
  }
  if(b_mus_stamu_numvalhits_ && !b_mus_stamu_numvalhits_->TestBit(kDoNotProcess)){
    c_mus_stamu_numvalhits_ = true;
  }else{
    c_mus_stamu_numvalhits_ = false;
  }
  if(b_mus_stamu_phi_ && !b_mus_stamu_phi_->TestBit(kDoNotProcess)){
    c_mus_stamu_phi_ = true;
  }else{
    c_mus_stamu_phi_ = false;
  }
  if(b_mus_stamu_phiErr_ && !b_mus_stamu_phiErr_->TestBit(kDoNotProcess)){
    c_mus_stamu_phiErr_ = true;
  }else{
    c_mus_stamu_phiErr_ = false;
  }
  if(b_mus_stamu_pt_ && !b_mus_stamu_pt_->TestBit(kDoNotProcess)){
    c_mus_stamu_pt_ = true;
  }else{
    c_mus_stamu_pt_ = false;
  }
  if(b_mus_stamu_ptErr_ && !b_mus_stamu_ptErr_->TestBit(kDoNotProcess)){
    c_mus_stamu_ptErr_ = true;
  }else{
    c_mus_stamu_ptErr_ = false;
  }
  if(b_mus_stamu_px_ && !b_mus_stamu_px_->TestBit(kDoNotProcess)){
    c_mus_stamu_px_ = true;
  }else{
    c_mus_stamu_px_ = false;
  }
  if(b_mus_stamu_py_ && !b_mus_stamu_py_->TestBit(kDoNotProcess)){
    c_mus_stamu_py_ = true;
  }else{
    c_mus_stamu_py_ = false;
  }
  if(b_mus_stamu_pz_ && !b_mus_stamu_pz_->TestBit(kDoNotProcess)){
    c_mus_stamu_pz_ = true;
  }else{
    c_mus_stamu_pz_ = false;
  }
  if(b_mus_stamu_theta_ && !b_mus_stamu_theta_->TestBit(kDoNotProcess)){
    c_mus_stamu_theta_ = true;
  }else{
    c_mus_stamu_theta_ = false;
  }
  if(b_mus_stamu_vx_ && !b_mus_stamu_vx_->TestBit(kDoNotProcess)){
    c_mus_stamu_vx_ = true;
  }else{
    c_mus_stamu_vx_ = false;
  }
  if(b_mus_stamu_vy_ && !b_mus_stamu_vy_->TestBit(kDoNotProcess)){
    c_mus_stamu_vy_ = true;
  }else{
    c_mus_stamu_vy_ = false;
  }
  if(b_mus_stamu_vz_ && !b_mus_stamu_vz_->TestBit(kDoNotProcess)){
    c_mus_stamu_vz_ = true;
  }else{
    c_mus_stamu_vz_ = false;
  }
  if(b_mus_status_ && !b_mus_status_->TestBit(kDoNotProcess)){
    c_mus_status_ = true;
  }else{
    c_mus_status_ = false;
  }
  if(b_mus_tIso_ && !b_mus_tIso_->TestBit(kDoNotProcess)){
    c_mus_tIso_ = true;
  }else{
    c_mus_tIso_ = false;
  }
  if(b_mus_theta_ && !b_mus_theta_->TestBit(kDoNotProcess)){
    c_mus_theta_ = true;
  }else{
    c_mus_theta_ = false;
  }
  if(b_mus_tkHits_ && !b_mus_tkHits_->TestBit(kDoNotProcess)){
    c_mus_tkHits_ = true;
  }else{
    c_mus_tkHits_ = false;
  }
  if(b_mus_tk_ExpectedHitsInner_ && !b_mus_tk_ExpectedHitsInner_->TestBit(kDoNotProcess)){
    c_mus_tk_ExpectedHitsInner_ = true;
  }else{
    c_mus_tk_ExpectedHitsInner_ = false;
  }
  if(b_mus_tk_ExpectedHitsOuter_ && !b_mus_tk_ExpectedHitsOuter_->TestBit(kDoNotProcess)){
    c_mus_tk_ExpectedHitsOuter_ = true;
  }else{
    c_mus_tk_ExpectedHitsOuter_ = false;
  }
  if(b_mus_tk_LayersWithMeasurement_ && !b_mus_tk_LayersWithMeasurement_->TestBit(kDoNotProcess)){
    c_mus_tk_LayersWithMeasurement_ = true;
  }else{
    c_mus_tk_LayersWithMeasurement_ = false;
  }
  if(b_mus_tk_LayersWithoutMeasurement_ && !b_mus_tk_LayersWithoutMeasurement_->TestBit(kDoNotProcess)){
    c_mus_tk_LayersWithoutMeasurement_ = true;
  }else{
    c_mus_tk_LayersWithoutMeasurement_ = false;
  }
  if(b_mus_tk_PixelLayersWithMeasurement_ && !b_mus_tk_PixelLayersWithMeasurement_->TestBit(kDoNotProcess)){
    c_mus_tk_PixelLayersWithMeasurement_ = true;
  }else{
    c_mus_tk_PixelLayersWithMeasurement_ = false;
  }
  if(b_mus_tk_ValidStripLayersWithMonoAndStereoHit_ && !b_mus_tk_ValidStripLayersWithMonoAndStereoHit_->TestBit(kDoNotProcess)){
    c_mus_tk_ValidStripLayersWithMonoAndStereoHit_ = true;
  }else{
    c_mus_tk_ValidStripLayersWithMonoAndStereoHit_ = false;
  }
  if(b_mus_tk_chg_ && !b_mus_tk_chg_->TestBit(kDoNotProcess)){
    c_mus_tk_chg_ = true;
  }else{
    c_mus_tk_chg_ = false;
  }
  if(b_mus_tk_chi2_ && !b_mus_tk_chi2_->TestBit(kDoNotProcess)){
    c_mus_tk_chi2_ = true;
  }else{
    c_mus_tk_chi2_ = false;
  }
  if(b_mus_tk_d0dum_ && !b_mus_tk_d0dum_->TestBit(kDoNotProcess)){
    c_mus_tk_d0dum_ = true;
  }else{
    c_mus_tk_d0dum_ = false;
  }
  if(b_mus_tk_d0dumErr_ && !b_mus_tk_d0dumErr_->TestBit(kDoNotProcess)){
    c_mus_tk_d0dumErr_ = true;
  }else{
    c_mus_tk_d0dumErr_ = false;
  }
  if(b_mus_tk_dz_ && !b_mus_tk_dz_->TestBit(kDoNotProcess)){
    c_mus_tk_dz_ = true;
  }else{
    c_mus_tk_dz_ = false;
  }
  if(b_mus_tk_dzErr_ && !b_mus_tk_dzErr_->TestBit(kDoNotProcess)){
    c_mus_tk_dzErr_ = true;
  }else{
    c_mus_tk_dzErr_ = false;
  }
  if(b_mus_tk_eta_ && !b_mus_tk_eta_->TestBit(kDoNotProcess)){
    c_mus_tk_eta_ = true;
  }else{
    c_mus_tk_eta_ = false;
  }
  if(b_mus_tk_etaErr_ && !b_mus_tk_etaErr_->TestBit(kDoNotProcess)){
    c_mus_tk_etaErr_ = true;
  }else{
    c_mus_tk_etaErr_ = false;
  }
  if(b_mus_tk_id_ && !b_mus_tk_id_->TestBit(kDoNotProcess)){
    c_mus_tk_id_ = true;
  }else{
    c_mus_tk_id_ = false;
  }
  if(b_mus_tk_ndof_ && !b_mus_tk_ndof_->TestBit(kDoNotProcess)){
    c_mus_tk_ndof_ = true;
  }else{
    c_mus_tk_ndof_ = false;
  }
  if(b_mus_tk_numlosthits_ && !b_mus_tk_numlosthits_->TestBit(kDoNotProcess)){
    c_mus_tk_numlosthits_ = true;
  }else{
    c_mus_tk_numlosthits_ = false;
  }
  if(b_mus_tk_numpixelWthMeasr_ && !b_mus_tk_numpixelWthMeasr_->TestBit(kDoNotProcess)){
    c_mus_tk_numpixelWthMeasr_ = true;
  }else{
    c_mus_tk_numpixelWthMeasr_ = false;
  }
  if(b_mus_tk_numvalPixelhits_ && !b_mus_tk_numvalPixelhits_->TestBit(kDoNotProcess)){
    c_mus_tk_numvalPixelhits_ = true;
  }else{
    c_mus_tk_numvalPixelhits_ = false;
  }
  if(b_mus_tk_numvalhits_ && !b_mus_tk_numvalhits_->TestBit(kDoNotProcess)){
    c_mus_tk_numvalhits_ = true;
  }else{
    c_mus_tk_numvalhits_ = false;
  }
  if(b_mus_tk_phi_ && !b_mus_tk_phi_->TestBit(kDoNotProcess)){
    c_mus_tk_phi_ = true;
  }else{
    c_mus_tk_phi_ = false;
  }
  if(b_mus_tk_phiErr_ && !b_mus_tk_phiErr_->TestBit(kDoNotProcess)){
    c_mus_tk_phiErr_ = true;
  }else{
    c_mus_tk_phiErr_ = false;
  }
  if(b_mus_tk_pt_ && !b_mus_tk_pt_->TestBit(kDoNotProcess)){
    c_mus_tk_pt_ = true;
  }else{
    c_mus_tk_pt_ = false;
  }
  if(b_mus_tk_ptErr_ && !b_mus_tk_ptErr_->TestBit(kDoNotProcess)){
    c_mus_tk_ptErr_ = true;
  }else{
    c_mus_tk_ptErr_ = false;
  }
  if(b_mus_tk_px_ && !b_mus_tk_px_->TestBit(kDoNotProcess)){
    c_mus_tk_px_ = true;
  }else{
    c_mus_tk_px_ = false;
  }
  if(b_mus_tk_py_ && !b_mus_tk_py_->TestBit(kDoNotProcess)){
    c_mus_tk_py_ = true;
  }else{
    c_mus_tk_py_ = false;
  }
  if(b_mus_tk_pz_ && !b_mus_tk_pz_->TestBit(kDoNotProcess)){
    c_mus_tk_pz_ = true;
  }else{
    c_mus_tk_pz_ = false;
  }
  if(b_mus_tk_theta_ && !b_mus_tk_theta_->TestBit(kDoNotProcess)){
    c_mus_tk_theta_ = true;
  }else{
    c_mus_tk_theta_ = false;
  }
  if(b_mus_tk_vx_ && !b_mus_tk_vx_->TestBit(kDoNotProcess)){
    c_mus_tk_vx_ = true;
  }else{
    c_mus_tk_vx_ = false;
  }
  if(b_mus_tk_vy_ && !b_mus_tk_vy_->TestBit(kDoNotProcess)){
    c_mus_tk_vy_ = true;
  }else{
    c_mus_tk_vy_ = false;
  }
  if(b_mus_tk_vz_ && !b_mus_tk_vz_->TestBit(kDoNotProcess)){
    c_mus_tk_vz_ = true;
  }else{
    c_mus_tk_vz_ = false;
  }
  if(b_mus_tpfms_ExpectedHitsInner_ && !b_mus_tpfms_ExpectedHitsInner_->TestBit(kDoNotProcess)){
    c_mus_tpfms_ExpectedHitsInner_ = true;
  }else{
    c_mus_tpfms_ExpectedHitsInner_ = false;
  }
  if(b_mus_tpfms_ExpectedHitsOuter_ && !b_mus_tpfms_ExpectedHitsOuter_->TestBit(kDoNotProcess)){
    c_mus_tpfms_ExpectedHitsOuter_ = true;
  }else{
    c_mus_tpfms_ExpectedHitsOuter_ = false;
  }
  if(b_mus_tpfms_LayersWithMeasurement_ && !b_mus_tpfms_LayersWithMeasurement_->TestBit(kDoNotProcess)){
    c_mus_tpfms_LayersWithMeasurement_ = true;
  }else{
    c_mus_tpfms_LayersWithMeasurement_ = false;
  }
  if(b_mus_tpfms_LayersWithoutMeasurement_ && !b_mus_tpfms_LayersWithoutMeasurement_->TestBit(kDoNotProcess)){
    c_mus_tpfms_LayersWithoutMeasurement_ = true;
  }else{
    c_mus_tpfms_LayersWithoutMeasurement_ = false;
  }
  if(b_mus_tpfms_PixelLayersWithMeasurement_ && !b_mus_tpfms_PixelLayersWithMeasurement_->TestBit(kDoNotProcess)){
    c_mus_tpfms_PixelLayersWithMeasurement_ = true;
  }else{
    c_mus_tpfms_PixelLayersWithMeasurement_ = false;
  }
  if(b_mus_tpfms_ValidStripLayersWithMonoAndStereoHit_ && !b_mus_tpfms_ValidStripLayersWithMonoAndStereoHit_->TestBit(kDoNotProcess)){
    c_mus_tpfms_ValidStripLayersWithMonoAndStereoHit_ = true;
  }else{
    c_mus_tpfms_ValidStripLayersWithMonoAndStereoHit_ = false;
  }
  if(b_mus_tpfms_chg_ && !b_mus_tpfms_chg_->TestBit(kDoNotProcess)){
    c_mus_tpfms_chg_ = true;
  }else{
    c_mus_tpfms_chg_ = false;
  }
  if(b_mus_tpfms_chi2_ && !b_mus_tpfms_chi2_->TestBit(kDoNotProcess)){
    c_mus_tpfms_chi2_ = true;
  }else{
    c_mus_tpfms_chi2_ = false;
  }
  if(b_mus_tpfms_d0dum_ && !b_mus_tpfms_d0dum_->TestBit(kDoNotProcess)){
    c_mus_tpfms_d0dum_ = true;
  }else{
    c_mus_tpfms_d0dum_ = false;
  }
  if(b_mus_tpfms_d0dumErr_ && !b_mus_tpfms_d0dumErr_->TestBit(kDoNotProcess)){
    c_mus_tpfms_d0dumErr_ = true;
  }else{
    c_mus_tpfms_d0dumErr_ = false;
  }
  if(b_mus_tpfms_dz_ && !b_mus_tpfms_dz_->TestBit(kDoNotProcess)){
    c_mus_tpfms_dz_ = true;
  }else{
    c_mus_tpfms_dz_ = false;
  }
  if(b_mus_tpfms_dzErr_ && !b_mus_tpfms_dzErr_->TestBit(kDoNotProcess)){
    c_mus_tpfms_dzErr_ = true;
  }else{
    c_mus_tpfms_dzErr_ = false;
  }
  if(b_mus_tpfms_eta_ && !b_mus_tpfms_eta_->TestBit(kDoNotProcess)){
    c_mus_tpfms_eta_ = true;
  }else{
    c_mus_tpfms_eta_ = false;
  }
  if(b_mus_tpfms_etaErr_ && !b_mus_tpfms_etaErr_->TestBit(kDoNotProcess)){
    c_mus_tpfms_etaErr_ = true;
  }else{
    c_mus_tpfms_etaErr_ = false;
  }
  if(b_mus_tpfms_id_ && !b_mus_tpfms_id_->TestBit(kDoNotProcess)){
    c_mus_tpfms_id_ = true;
  }else{
    c_mus_tpfms_id_ = false;
  }
  if(b_mus_tpfms_ndof_ && !b_mus_tpfms_ndof_->TestBit(kDoNotProcess)){
    c_mus_tpfms_ndof_ = true;
  }else{
    c_mus_tpfms_ndof_ = false;
  }
  if(b_mus_tpfms_numlosthits_ && !b_mus_tpfms_numlosthits_->TestBit(kDoNotProcess)){
    c_mus_tpfms_numlosthits_ = true;
  }else{
    c_mus_tpfms_numlosthits_ = false;
  }
  if(b_mus_tpfms_numvalPixelhits_ && !b_mus_tpfms_numvalPixelhits_->TestBit(kDoNotProcess)){
    c_mus_tpfms_numvalPixelhits_ = true;
  }else{
    c_mus_tpfms_numvalPixelhits_ = false;
  }
  if(b_mus_tpfms_numvalhits_ && !b_mus_tpfms_numvalhits_->TestBit(kDoNotProcess)){
    c_mus_tpfms_numvalhits_ = true;
  }else{
    c_mus_tpfms_numvalhits_ = false;
  }
  if(b_mus_tpfms_phi_ && !b_mus_tpfms_phi_->TestBit(kDoNotProcess)){
    c_mus_tpfms_phi_ = true;
  }else{
    c_mus_tpfms_phi_ = false;
  }
  if(b_mus_tpfms_phiErr_ && !b_mus_tpfms_phiErr_->TestBit(kDoNotProcess)){
    c_mus_tpfms_phiErr_ = true;
  }else{
    c_mus_tpfms_phiErr_ = false;
  }
  if(b_mus_tpfms_pt_ && !b_mus_tpfms_pt_->TestBit(kDoNotProcess)){
    c_mus_tpfms_pt_ = true;
  }else{
    c_mus_tpfms_pt_ = false;
  }
  if(b_mus_tpfms_ptErr_ && !b_mus_tpfms_ptErr_->TestBit(kDoNotProcess)){
    c_mus_tpfms_ptErr_ = true;
  }else{
    c_mus_tpfms_ptErr_ = false;
  }
  if(b_mus_tpfms_px_ && !b_mus_tpfms_px_->TestBit(kDoNotProcess)){
    c_mus_tpfms_px_ = true;
  }else{
    c_mus_tpfms_px_ = false;
  }
  if(b_mus_tpfms_py_ && !b_mus_tpfms_py_->TestBit(kDoNotProcess)){
    c_mus_tpfms_py_ = true;
  }else{
    c_mus_tpfms_py_ = false;
  }
  if(b_mus_tpfms_pz_ && !b_mus_tpfms_pz_->TestBit(kDoNotProcess)){
    c_mus_tpfms_pz_ = true;
  }else{
    c_mus_tpfms_pz_ = false;
  }
  if(b_mus_tpfms_theta_ && !b_mus_tpfms_theta_->TestBit(kDoNotProcess)){
    c_mus_tpfms_theta_ = true;
  }else{
    c_mus_tpfms_theta_ = false;
  }
  if(b_mus_tpfms_vx_ && !b_mus_tpfms_vx_->TestBit(kDoNotProcess)){
    c_mus_tpfms_vx_ = true;
  }else{
    c_mus_tpfms_vx_ = false;
  }
  if(b_mus_tpfms_vy_ && !b_mus_tpfms_vy_->TestBit(kDoNotProcess)){
    c_mus_tpfms_vy_ = true;
  }else{
    c_mus_tpfms_vy_ = false;
  }
  if(b_mus_tpfms_vz_ && !b_mus_tpfms_vz_->TestBit(kDoNotProcess)){
    c_mus_tpfms_vz_ = true;
  }else{
    c_mus_tpfms_vz_ = false;
  }
  if(b_orbitNumber_ && !b_orbitNumber_->TestBit(kDoNotProcess)){
    c_orbitNumber_ = true;
  }else{
    c_orbitNumber_ = false;
  }
  if(b_pfcand_charge_ && !b_pfcand_charge_->TestBit(kDoNotProcess)){
    c_pfcand_charge_ = true;
  }else{
    c_pfcand_charge_ = false;
  }
  if(b_pfcand_energy_ && !b_pfcand_energy_->TestBit(kDoNotProcess)){
    c_pfcand_energy_ = true;
  }else{
    c_pfcand_energy_ = false;
  }
  if(b_pfcand_eta_ && !b_pfcand_eta_->TestBit(kDoNotProcess)){
    c_pfcand_eta_ = true;
  }else{
    c_pfcand_eta_ = false;
  }
  if(b_pfcand_pdgId_ && !b_pfcand_pdgId_->TestBit(kDoNotProcess)){
    c_pfcand_pdgId_ = true;
  }else{
    c_pfcand_pdgId_ = false;
  }
  if(b_pfcand_phi_ && !b_pfcand_phi_->TestBit(kDoNotProcess)){
    c_pfcand_phi_ = true;
  }else{
    c_pfcand_phi_ = false;
  }
  if(b_pfcand_pt_ && !b_pfcand_pt_->TestBit(kDoNotProcess)){
    c_pfcand_pt_ = true;
  }else{
    c_pfcand_pt_ = false;
  }
  if(b_pfcand_px_ && !b_pfcand_px_->TestBit(kDoNotProcess)){
    c_pfcand_px_ = true;
  }else{
    c_pfcand_px_ = false;
  }
  if(b_pfcand_py_ && !b_pfcand_py_->TestBit(kDoNotProcess)){
    c_pfcand_py_ = true;
  }else{
    c_pfcand_py_ = false;
  }
  if(b_pfcand_pz_ && !b_pfcand_pz_->TestBit(kDoNotProcess)){
    c_pfcand_pz_ = true;
  }else{
    c_pfcand_pz_ = false;
  }
  if(b_pfcand_theta_ && !b_pfcand_theta_->TestBit(kDoNotProcess)){
    c_pfcand_theta_ = true;
  }else{
    c_pfcand_theta_ = false;
  }
  if(b_photons_e1x5_ && !b_photons_e1x5_->TestBit(kDoNotProcess)){
    c_photons_e1x5_ = true;
  }else{
    c_photons_e1x5_ = false;
  }
  if(b_photons_e2x5_ && !b_photons_e2x5_->TestBit(kDoNotProcess)){
    c_photons_e2x5_ = true;
  }else{
    c_photons_e2x5_ = false;
  }
  if(b_photons_e3x3_ && !b_photons_e3x3_->TestBit(kDoNotProcess)){
    c_photons_e3x3_ = true;
  }else{
    c_photons_e3x3_ = false;
  }
  if(b_photons_e5x5_ && !b_photons_e5x5_->TestBit(kDoNotProcess)){
    c_photons_e5x5_ = true;
  }else{
    c_photons_e5x5_ = false;
  }
  if(b_photons_ecalIso_ && !b_photons_ecalIso_->TestBit(kDoNotProcess)){
    c_photons_ecalIso_ = true;
  }else{
    c_photons_ecalIso_ = false;
  }
  if(b_photons_energy_ && !b_photons_energy_->TestBit(kDoNotProcess)){
    c_photons_energy_ = true;
  }else{
    c_photons_energy_ = false;
  }
  if(b_photons_et_ && !b_photons_et_->TestBit(kDoNotProcess)){
    c_photons_et_ = true;
  }else{
    c_photons_et_ = false;
  }
  if(b_photons_eta_ && !b_photons_eta_->TestBit(kDoNotProcess)){
    c_photons_eta_ = true;
  }else{
    c_photons_eta_ = false;
  }
  if(b_photons_gen_et_ && !b_photons_gen_et_->TestBit(kDoNotProcess)){
    c_photons_gen_et_ = true;
  }else{
    c_photons_gen_et_ = false;
  }
  if(b_photons_gen_eta_ && !b_photons_gen_eta_->TestBit(kDoNotProcess)){
    c_photons_gen_eta_ = true;
  }else{
    c_photons_gen_eta_ = false;
  }
  if(b_photons_gen_id_ && !b_photons_gen_id_->TestBit(kDoNotProcess)){
    c_photons_gen_id_ = true;
  }else{
    c_photons_gen_id_ = false;
  }
  if(b_photons_gen_phi_ && !b_photons_gen_phi_->TestBit(kDoNotProcess)){
    c_photons_gen_phi_ = true;
  }else{
    c_photons_gen_phi_ = false;
  }
  if(b_photons_hadOverEM_ && !b_photons_hadOverEM_->TestBit(kDoNotProcess)){
    c_photons_hadOverEM_ = true;
  }else{
    c_photons_hadOverEM_ = false;
  }
  if(b_photons_hadTowOverEM_ && !b_photons_hadTowOverEM_->TestBit(kDoNotProcess)){
    c_photons_hadTowOverEM_ = true;
  }else{
    c_photons_hadTowOverEM_ = false;
  }
  if(b_photons_hasPixelSeed_ && !b_photons_hasPixelSeed_->TestBit(kDoNotProcess)){
    c_photons_hasPixelSeed_ = true;
  }else{
    c_photons_hasPixelSeed_ = false;
  }
  if(b_photons_hcalIso_ && !b_photons_hcalIso_->TestBit(kDoNotProcess)){
    c_photons_hcalIso_ = true;
  }else{
    c_photons_hcalIso_ = false;
  }
  if(b_photons_isAlsoElectron_ && !b_photons_isAlsoElectron_->TestBit(kDoNotProcess)){
    c_photons_isAlsoElectron_ = true;
  }else{
    c_photons_isAlsoElectron_ = false;
  }
  if(b_photons_isConverted_ && !b_photons_isConverted_->TestBit(kDoNotProcess)){
    c_photons_isConverted_ = true;
  }else{
    c_photons_isConverted_ = false;
  }
  if(b_photons_isEBEEGap_ && !b_photons_isEBEEGap_->TestBit(kDoNotProcess)){
    c_photons_isEBEEGap_ = true;
  }else{
    c_photons_isEBEEGap_ = false;
  }
  if(b_photons_isEBGap_ && !b_photons_isEBGap_->TestBit(kDoNotProcess)){
    c_photons_isEBGap_ = true;
  }else{
    c_photons_isEBGap_ = false;
  }
  if(b_photons_isEBPho_ && !b_photons_isEBPho_->TestBit(kDoNotProcess)){
    c_photons_isEBPho_ = true;
  }else{
    c_photons_isEBPho_ = false;
  }
  if(b_photons_isEEGap_ && !b_photons_isEEGap_->TestBit(kDoNotProcess)){
    c_photons_isEEGap_ = true;
  }else{
    c_photons_isEEGap_ = false;
  }
  if(b_photons_isEEPho_ && !b_photons_isEEPho_->TestBit(kDoNotProcess)){
    c_photons_isEEPho_ = true;
  }else{
    c_photons_isEEPho_ = false;
  }
  if(b_photons_isLoosePhoton_ && !b_photons_isLoosePhoton_->TestBit(kDoNotProcess)){
    c_photons_isLoosePhoton_ = true;
  }else{
    c_photons_isLoosePhoton_ = false;
  }
  if(b_photons_isTightPhoton_ && !b_photons_isTightPhoton_->TestBit(kDoNotProcess)){
    c_photons_isTightPhoton_ = true;
  }else{
    c_photons_isTightPhoton_ = false;
  }
  if(b_photons_isoEcalRecHitDR03_ && !b_photons_isoEcalRecHitDR03_->TestBit(kDoNotProcess)){
    c_photons_isoEcalRecHitDR03_ = true;
  }else{
    c_photons_isoEcalRecHitDR03_ = false;
  }
  if(b_photons_isoEcalRecHitDR04_ && !b_photons_isoEcalRecHitDR04_->TestBit(kDoNotProcess)){
    c_photons_isoEcalRecHitDR04_ = true;
  }else{
    c_photons_isoEcalRecHitDR04_ = false;
  }
  if(b_photons_isoHcalRecHitDR03_ && !b_photons_isoHcalRecHitDR03_->TestBit(kDoNotProcess)){
    c_photons_isoHcalRecHitDR03_ = true;
  }else{
    c_photons_isoHcalRecHitDR03_ = false;
  }
  if(b_photons_isoHcalRecHitDR04_ && !b_photons_isoHcalRecHitDR04_->TestBit(kDoNotProcess)){
    c_photons_isoHcalRecHitDR04_ = true;
  }else{
    c_photons_isoHcalRecHitDR04_ = false;
  }
  if(b_photons_isoHollowTrkConeDR03_ && !b_photons_isoHollowTrkConeDR03_->TestBit(kDoNotProcess)){
    c_photons_isoHollowTrkConeDR03_ = true;
  }else{
    c_photons_isoHollowTrkConeDR03_ = false;
  }
  if(b_photons_isoHollowTrkConeDR04_ && !b_photons_isoHollowTrkConeDR04_->TestBit(kDoNotProcess)){
    c_photons_isoHollowTrkConeDR04_ = true;
  }else{
    c_photons_isoHollowTrkConeDR04_ = false;
  }
  if(b_photons_isoSolidTrkConeDR03_ && !b_photons_isoSolidTrkConeDR03_->TestBit(kDoNotProcess)){
    c_photons_isoSolidTrkConeDR03_ = true;
  }else{
    c_photons_isoSolidTrkConeDR03_ = false;
  }
  if(b_photons_isoSolidTrkConeDR04_ && !b_photons_isoSolidTrkConeDR04_->TestBit(kDoNotProcess)){
    c_photons_isoSolidTrkConeDR04_ = true;
  }else{
    c_photons_isoSolidTrkConeDR04_ = false;
  }
  if(b_photons_maxEnergyXtal_ && !b_photons_maxEnergyXtal_->TestBit(kDoNotProcess)){
    c_photons_maxEnergyXtal_ = true;
  }else{
    c_photons_maxEnergyXtal_ = false;
  }
  if(b_photons_nTrkHollowConeDR03_ && !b_photons_nTrkHollowConeDR03_->TestBit(kDoNotProcess)){
    c_photons_nTrkHollowConeDR03_ = true;
  }else{
    c_photons_nTrkHollowConeDR03_ = false;
  }
  if(b_photons_nTrkHollowConeDR04_ && !b_photons_nTrkHollowConeDR04_->TestBit(kDoNotProcess)){
    c_photons_nTrkHollowConeDR04_ = true;
  }else{
    c_photons_nTrkHollowConeDR04_ = false;
  }
  if(b_photons_nTrkSolidConeDR03_ && !b_photons_nTrkSolidConeDR03_->TestBit(kDoNotProcess)){
    c_photons_nTrkSolidConeDR03_ = true;
  }else{
    c_photons_nTrkSolidConeDR03_ = false;
  }
  if(b_photons_nTrkSolidConeDR04_ && !b_photons_nTrkSolidConeDR04_->TestBit(kDoNotProcess)){
    c_photons_nTrkSolidConeDR04_ = true;
  }else{
    c_photons_nTrkSolidConeDR04_ = false;
  }
  if(b_photons_phi_ && !b_photons_phi_->TestBit(kDoNotProcess)){
    c_photons_phi_ = true;
  }else{
    c_photons_phi_ = false;
  }
  if(b_photons_pt_ && !b_photons_pt_->TestBit(kDoNotProcess)){
    c_photons_pt_ = true;
  }else{
    c_photons_pt_ = false;
  }
  if(b_photons_px_ && !b_photons_px_->TestBit(kDoNotProcess)){
    c_photons_px_ = true;
  }else{
    c_photons_px_ = false;
  }
  if(b_photons_py_ && !b_photons_py_->TestBit(kDoNotProcess)){
    c_photons_py_ = true;
  }else{
    c_photons_py_ = false;
  }
  if(b_photons_pz_ && !b_photons_pz_->TestBit(kDoNotProcess)){
    c_photons_pz_ = true;
  }else{
    c_photons_pz_ = false;
  }
  if(b_photons_r9_ && !b_photons_r9_->TestBit(kDoNotProcess)){
    c_photons_r9_ = true;
  }else{
    c_photons_r9_ = false;
  }
  if(b_photons_scEnergy_ && !b_photons_scEnergy_->TestBit(kDoNotProcess)){
    c_photons_scEnergy_ = true;
  }else{
    c_photons_scEnergy_ = false;
  }
  if(b_photons_scEta_ && !b_photons_scEta_->TestBit(kDoNotProcess)){
    c_photons_scEta_ = true;
  }else{
    c_photons_scEta_ = false;
  }
  if(b_photons_scEtaWidth_ && !b_photons_scEtaWidth_->TestBit(kDoNotProcess)){
    c_photons_scEtaWidth_ = true;
  }else{
    c_photons_scEtaWidth_ = false;
  }
  if(b_photons_scPhi_ && !b_photons_scPhi_->TestBit(kDoNotProcess)){
    c_photons_scPhi_ = true;
  }else{
    c_photons_scPhi_ = false;
  }
  if(b_photons_scPhiWidth_ && !b_photons_scPhiWidth_->TestBit(kDoNotProcess)){
    c_photons_scPhiWidth_ = true;
  }else{
    c_photons_scPhiWidth_ = false;
  }
  if(b_photons_scRawEnergy_ && !b_photons_scRawEnergy_->TestBit(kDoNotProcess)){
    c_photons_scRawEnergy_ = true;
  }else{
    c_photons_scRawEnergy_ = false;
  }
  if(b_photons_sigmaEtaEta_ && !b_photons_sigmaEtaEta_->TestBit(kDoNotProcess)){
    c_photons_sigmaEtaEta_ = true;
  }else{
    c_photons_sigmaEtaEta_ = false;
  }
  if(b_photons_sigmaIetaIeta_ && !b_photons_sigmaIetaIeta_->TestBit(kDoNotProcess)){
    c_photons_sigmaIetaIeta_ = true;
  }else{
    c_photons_sigmaIetaIeta_ = false;
  }
  if(b_photons_status_ && !b_photons_status_->TestBit(kDoNotProcess)){
    c_photons_status_ = true;
  }else{
    c_photons_status_ = false;
  }
  if(b_photons_tIso_ && !b_photons_tIso_->TestBit(kDoNotProcess)){
    c_photons_tIso_ = true;
  }else{
    c_photons_tIso_ = false;
  }
  if(b_photons_theta_ && !b_photons_theta_->TestBit(kDoNotProcess)){
    c_photons_theta_ = true;
  }else{
    c_photons_theta_ = false;
  }
  if(b_pv_chi2_ && !b_pv_chi2_->TestBit(kDoNotProcess)){
    c_pv_chi2_ = true;
  }else{
    c_pv_chi2_ = false;
  }
  if(b_pv_isFake_ && !b_pv_isFake_->TestBit(kDoNotProcess)){
    c_pv_isFake_ = true;
  }else{
    c_pv_isFake_ = false;
  }
  if(b_pv_isValid_ && !b_pv_isValid_->TestBit(kDoNotProcess)){
    c_pv_isValid_ = true;
  }else{
    c_pv_isValid_ = false;
  }
  if(b_pv_ndof_ && !b_pv_ndof_->TestBit(kDoNotProcess)){
    c_pv_ndof_ = true;
  }else{
    c_pv_ndof_ = false;
  }
  if(b_pv_tracksSize_ && !b_pv_tracksSize_->TestBit(kDoNotProcess)){
    c_pv_tracksSize_ = true;
  }else{
    c_pv_tracksSize_ = false;
  }
  if(b_pv_x_ && !b_pv_x_->TestBit(kDoNotProcess)){
    c_pv_x_ = true;
  }else{
    c_pv_x_ = false;
  }
  if(b_pv_xErr_ && !b_pv_xErr_->TestBit(kDoNotProcess)){
    c_pv_xErr_ = true;
  }else{
    c_pv_xErr_ = false;
  }
  if(b_pv_y_ && !b_pv_y_->TestBit(kDoNotProcess)){
    c_pv_y_ = true;
  }else{
    c_pv_y_ = false;
  }
  if(b_pv_yErr_ && !b_pv_yErr_->TestBit(kDoNotProcess)){
    c_pv_yErr_ = true;
  }else{
    c_pv_yErr_ = false;
  }
  if(b_pv_z_ && !b_pv_z_->TestBit(kDoNotProcess)){
    c_pv_z_ = true;
  }else{
    c_pv_z_ = false;
  }
  if(b_pv_zErr_ && !b_pv_zErr_->TestBit(kDoNotProcess)){
    c_pv_zErr_ = true;
  }else{
    c_pv_zErr_ = false;
  }
  if(b_run_ && !b_run_->TestBit(kDoNotProcess)){
    c_run_ = true;
  }else{
    c_run_ = false;
  }
  if(b_standalone_triggerobject_collectionname_ && !b_standalone_triggerobject_collectionname_->TestBit(kDoNotProcess)){
    c_standalone_triggerobject_collectionname_ = true;
  }else{
    c_standalone_triggerobject_collectionname_ = false;
  }
  if(b_standalone_triggerobject_energy_ && !b_standalone_triggerobject_energy_->TestBit(kDoNotProcess)){
    c_standalone_triggerobject_energy_ = true;
  }else{
    c_standalone_triggerobject_energy_ = false;
  }
  if(b_standalone_triggerobject_et_ && !b_standalone_triggerobject_et_->TestBit(kDoNotProcess)){
    c_standalone_triggerobject_et_ = true;
  }else{
    c_standalone_triggerobject_et_ = false;
  }
  if(b_standalone_triggerobject_eta_ && !b_standalone_triggerobject_eta_->TestBit(kDoNotProcess)){
    c_standalone_triggerobject_eta_ = true;
  }else{
    c_standalone_triggerobject_eta_ = false;
  }
  if(b_standalone_triggerobject_phi_ && !b_standalone_triggerobject_phi_->TestBit(kDoNotProcess)){
    c_standalone_triggerobject_phi_ = true;
  }else{
    c_standalone_triggerobject_phi_ = false;
  }
  if(b_standalone_triggerobject_pt_ && !b_standalone_triggerobject_pt_->TestBit(kDoNotProcess)){
    c_standalone_triggerobject_pt_ = true;
  }else{
    c_standalone_triggerobject_pt_ = false;
  }
  if(b_standalone_triggerobject_px_ && !b_standalone_triggerobject_px_->TestBit(kDoNotProcess)){
    c_standalone_triggerobject_px_ = true;
  }else{
    c_standalone_triggerobject_px_ = false;
  }
  if(b_standalone_triggerobject_py_ && !b_standalone_triggerobject_py_->TestBit(kDoNotProcess)){
    c_standalone_triggerobject_py_ = true;
  }else{
    c_standalone_triggerobject_py_ = false;
  }
  if(b_standalone_triggerobject_pz_ && !b_standalone_triggerobject_pz_->TestBit(kDoNotProcess)){
    c_standalone_triggerobject_pz_ = true;
  }else{
    c_standalone_triggerobject_pz_ = false;
  }
  if(b_taus_Nprongs_ && !b_taus_Nprongs_->TestBit(kDoNotProcess)){
    c_taus_Nprongs_ = true;
  }else{
    c_taus_Nprongs_ = false;
  }
  if(b_taus_againstElectron_ && !b_taus_againstElectron_->TestBit(kDoNotProcess)){
    c_taus_againstElectron_ = true;
  }else{
    c_taus_againstElectron_ = false;
  }
  if(b_taus_againstElectronLoose_ && !b_taus_againstElectronLoose_->TestBit(kDoNotProcess)){
    c_taus_againstElectronLoose_ = true;
  }else{
    c_taus_againstElectronLoose_ = false;
  }
  if(b_taus_againstElectronMVA_ && !b_taus_againstElectronMVA_->TestBit(kDoNotProcess)){
    c_taus_againstElectronMVA_ = true;
  }else{
    c_taus_againstElectronMVA_ = false;
  }
  if(b_taus_againstElectronMedium_ && !b_taus_againstElectronMedium_->TestBit(kDoNotProcess)){
    c_taus_againstElectronMedium_ = true;
  }else{
    c_taus_againstElectronMedium_ = false;
  }
  if(b_taus_againstElectronTight_ && !b_taus_againstElectronTight_->TestBit(kDoNotProcess)){
    c_taus_againstElectronTight_ = true;
  }else{
    c_taus_againstElectronTight_ = false;
  }
  if(b_taus_againstMuon_ && !b_taus_againstMuon_->TestBit(kDoNotProcess)){
    c_taus_againstMuon_ = true;
  }else{
    c_taus_againstMuon_ = false;
  }
  if(b_taus_againstMuonLoose_ && !b_taus_againstMuonLoose_->TestBit(kDoNotProcess)){
    c_taus_againstMuonLoose_ = true;
  }else{
    c_taus_againstMuonLoose_ = false;
  }
  if(b_taus_againstMuonMedium_ && !b_taus_againstMuonMedium_->TestBit(kDoNotProcess)){
    c_taus_againstMuonMedium_ = true;
  }else{
    c_taus_againstMuonMedium_ = false;
  }
  if(b_taus_againstMuonTight_ && !b_taus_againstMuonTight_->TestBit(kDoNotProcess)){
    c_taus_againstMuonTight_ = true;
  }else{
    c_taus_againstMuonTight_ = false;
  }
  if(b_taus_byIsoUsingLeadingPi_ && !b_taus_byIsoUsingLeadingPi_->TestBit(kDoNotProcess)){
    c_taus_byIsoUsingLeadingPi_ = true;
  }else{
    c_taus_byIsoUsingLeadingPi_ = false;
  }
  if(b_taus_byIsolation_ && !b_taus_byIsolation_->TestBit(kDoNotProcess)){
    c_taus_byIsolation_ = true;
  }else{
    c_taus_byIsolation_ = false;
  }
  if(b_taus_byLooseIsolation_ && !b_taus_byLooseIsolation_->TestBit(kDoNotProcess)){
    c_taus_byLooseIsolation_ = true;
  }else{
    c_taus_byLooseIsolation_ = false;
  }
  if(b_taus_byLooseIsolationDeltaBetaCorr_ && !b_taus_byLooseIsolationDeltaBetaCorr_->TestBit(kDoNotProcess)){
    c_taus_byLooseIsolationDeltaBetaCorr_ = true;
  }else{
    c_taus_byLooseIsolationDeltaBetaCorr_ = false;
  }
  if(b_taus_byMediumIsolation_ && !b_taus_byMediumIsolation_->TestBit(kDoNotProcess)){
    c_taus_byMediumIsolation_ = true;
  }else{
    c_taus_byMediumIsolation_ = false;
  }
  if(b_taus_byMediumIsolationDeltaBetaCorr_ && !b_taus_byMediumIsolationDeltaBetaCorr_->TestBit(kDoNotProcess)){
    c_taus_byMediumIsolationDeltaBetaCorr_ = true;
  }else{
    c_taus_byMediumIsolationDeltaBetaCorr_ = false;
  }
  if(b_taus_byTightIsolation_ && !b_taus_byTightIsolation_->TestBit(kDoNotProcess)){
    c_taus_byTightIsolation_ = true;
  }else{
    c_taus_byTightIsolation_ = false;
  }
  if(b_taus_byTightIsolationDeltaBetaCorr_ && !b_taus_byTightIsolationDeltaBetaCorr_->TestBit(kDoNotProcess)){
    c_taus_byTightIsolationDeltaBetaCorr_ = true;
  }else{
    c_taus_byTightIsolationDeltaBetaCorr_ = false;
  }
  if(b_taus_byVLooseIsolation_ && !b_taus_byVLooseIsolation_->TestBit(kDoNotProcess)){
    c_taus_byVLooseIsolation_ = true;
  }else{
    c_taus_byVLooseIsolation_ = false;
  }
  if(b_taus_byVLooseIsolationDeltaBetaCorr_ && !b_taus_byVLooseIsolationDeltaBetaCorr_->TestBit(kDoNotProcess)){
    c_taus_byVLooseIsolationDeltaBetaCorr_ = true;
  }else{
    c_taus_byVLooseIsolationDeltaBetaCorr_ = false;
  }
  if(b_taus_charge_ && !b_taus_charge_->TestBit(kDoNotProcess)){
    c_taus_charge_ = true;
  }else{
    c_taus_charge_ = false;
  }
  if(b_taus_decayModeFinding_ && !b_taus_decayModeFinding_->TestBit(kDoNotProcess)){
    c_taus_decayModeFinding_ = true;
  }else{
    c_taus_decayModeFinding_ = false;
  }
  if(b_taus_ecalIsoUsingLeadingPi_ && !b_taus_ecalIsoUsingLeadingPi_->TestBit(kDoNotProcess)){
    c_taus_ecalIsoUsingLeadingPi_ = true;
  }else{
    c_taus_ecalIsoUsingLeadingPi_ = false;
  }
  if(b_taus_ecalIsolation_ && !b_taus_ecalIsolation_->TestBit(kDoNotProcess)){
    c_taus_ecalIsolation_ = true;
  }else{
    c_taus_ecalIsolation_ = false;
  }
  if(b_taus_ecalStripSumEOverPLead_ && !b_taus_ecalStripSumEOverPLead_->TestBit(kDoNotProcess)){
    c_taus_ecalStripSumEOverPLead_ = true;
  }else{
    c_taus_ecalStripSumEOverPLead_ = false;
  }
  if(b_taus_elecPreIdDecision_ && !b_taus_elecPreIdDecision_->TestBit(kDoNotProcess)){
    c_taus_elecPreIdDecision_ = true;
  }else{
    c_taus_elecPreIdDecision_ = false;
  }
  if(b_taus_elecPreIdOutput_ && !b_taus_elecPreIdOutput_->TestBit(kDoNotProcess)){
    c_taus_elecPreIdOutput_ = true;
  }else{
    c_taus_elecPreIdOutput_ = false;
  }
  if(b_taus_emf_ && !b_taus_emf_->TestBit(kDoNotProcess)){
    c_taus_emf_ = true;
  }else{
    c_taus_emf_ = false;
  }
  if(b_taus_energy_ && !b_taus_energy_->TestBit(kDoNotProcess)){
    c_taus_energy_ = true;
  }else{
    c_taus_energy_ = false;
  }
  if(b_taus_et_ && !b_taus_et_->TestBit(kDoNotProcess)){
    c_taus_et_ = true;
  }else{
    c_taus_et_ = false;
  }
  if(b_taus_eta_ && !b_taus_eta_->TestBit(kDoNotProcess)){
    c_taus_eta_ = true;
  }else{
    c_taus_eta_ = false;
  }
  if(b_taus_hcal3x3OverPLead_ && !b_taus_hcal3x3OverPLead_->TestBit(kDoNotProcess)){
    c_taus_hcal3x3OverPLead_ = true;
  }else{
    c_taus_hcal3x3OverPLead_ = false;
  }
  if(b_taus_hcalMaxOverPLead_ && !b_taus_hcalMaxOverPLead_->TestBit(kDoNotProcess)){
    c_taus_hcalMaxOverPLead_ = true;
  }else{
    c_taus_hcalMaxOverPLead_ = false;
  }
  if(b_taus_hcalTotOverPLead_ && !b_taus_hcalTotOverPLead_->TestBit(kDoNotProcess)){
    c_taus_hcalTotOverPLead_ = true;
  }else{
    c_taus_hcalTotOverPLead_ = false;
  }
  if(b_taus_isoPFChargedHadrCandsPtSum_ && !b_taus_isoPFChargedHadrCandsPtSum_->TestBit(kDoNotProcess)){
    c_taus_isoPFChargedHadrCandsPtSum_ = true;
  }else{
    c_taus_isoPFChargedHadrCandsPtSum_ = false;
  }
  if(b_taus_isoPFGammaCandsEtSum_ && !b_taus_isoPFGammaCandsEtSum_->TestBit(kDoNotProcess)){
    c_taus_isoPFGammaCandsEtSum_ = true;
  }else{
    c_taus_isoPFGammaCandsEtSum_ = false;
  }
  if(b_taus_leadPFChargedHadrCand_ECAL_eta_ && !b_taus_leadPFChargedHadrCand_ECAL_eta_->TestBit(kDoNotProcess)){
    c_taus_leadPFChargedHadrCand_ECAL_eta_ = true;
  }else{
    c_taus_leadPFChargedHadrCand_ECAL_eta_ = false;
  }
  if(b_taus_leadPFChargedHadrCand_charge_ && !b_taus_leadPFChargedHadrCand_charge_->TestBit(kDoNotProcess)){
    c_taus_leadPFChargedHadrCand_charge_ = true;
  }else{
    c_taus_leadPFChargedHadrCand_charge_ = false;
  }
  if(b_taus_leadPFChargedHadrCand_eta_ && !b_taus_leadPFChargedHadrCand_eta_->TestBit(kDoNotProcess)){
    c_taus_leadPFChargedHadrCand_eta_ = true;
  }else{
    c_taus_leadPFChargedHadrCand_eta_ = false;
  }
  if(b_taus_leadPFChargedHadrCand_phi_ && !b_taus_leadPFChargedHadrCand_phi_->TestBit(kDoNotProcess)){
    c_taus_leadPFChargedHadrCand_phi_ = true;
  }else{
    c_taus_leadPFChargedHadrCand_phi_ = false;
  }
  if(b_taus_leadPFChargedHadrCand_pt_ && !b_taus_leadPFChargedHadrCand_pt_->TestBit(kDoNotProcess)){
    c_taus_leadPFChargedHadrCand_pt_ = true;
  }else{
    c_taus_leadPFChargedHadrCand_pt_ = false;
  }
  if(b_taus_leadingTrackFinding_ && !b_taus_leadingTrackFinding_->TestBit(kDoNotProcess)){
    c_taus_leadingTrackFinding_ = true;
  }else{
    c_taus_leadingTrackFinding_ = false;
  }
  if(b_taus_leadingTrackPtCut_ && !b_taus_leadingTrackPtCut_->TestBit(kDoNotProcess)){
    c_taus_leadingTrackPtCut_ = true;
  }else{
    c_taus_leadingTrackPtCut_ = false;
  }
  if(b_taus_muDecision_ && !b_taus_muDecision_->TestBit(kDoNotProcess)){
    c_taus_muDecision_ = true;
  }else{
    c_taus_muDecision_ = false;
  }
  if(b_taus_phi_ && !b_taus_phi_->TestBit(kDoNotProcess)){
    c_taus_phi_ = true;
  }else{
    c_taus_phi_ = false;
  }
  if(b_taus_pt_ && !b_taus_pt_->TestBit(kDoNotProcess)){
    c_taus_pt_ = true;
  }else{
    c_taus_pt_ = false;
  }
  if(b_taus_px_ && !b_taus_px_->TestBit(kDoNotProcess)){
    c_taus_px_ = true;
  }else{
    c_taus_px_ = false;
  }
  if(b_taus_py_ && !b_taus_py_->TestBit(kDoNotProcess)){
    c_taus_py_ = true;
  }else{
    c_taus_py_ = false;
  }
  if(b_taus_pz_ && !b_taus_pz_->TestBit(kDoNotProcess)){
    c_taus_pz_ = true;
  }else{
    c_taus_pz_ = false;
  }
  if(b_taus_signalPFChargedHadrCandsSize_ && !b_taus_signalPFChargedHadrCandsSize_->TestBit(kDoNotProcess)){
    c_taus_signalPFChargedHadrCandsSize_ = true;
  }else{
    c_taus_signalPFChargedHadrCandsSize_ = false;
  }
  if(b_taus_status_ && !b_taus_status_->TestBit(kDoNotProcess)){
    c_taus_status_ = true;
  }else{
    c_taus_status_ = false;
  }
  if(b_taus_taNC_ && !b_taus_taNC_->TestBit(kDoNotProcess)){
    c_taus_taNC_ = true;
  }else{
    c_taus_taNC_ = false;
  }
  if(b_taus_taNC_half_ && !b_taus_taNC_half_->TestBit(kDoNotProcess)){
    c_taus_taNC_half_ = true;
  }else{
    c_taus_taNC_half_ = false;
  }
  if(b_taus_taNC_one_ && !b_taus_taNC_one_->TestBit(kDoNotProcess)){
    c_taus_taNC_one_ = true;
  }else{
    c_taus_taNC_one_ = false;
  }
  if(b_taus_taNC_quarter_ && !b_taus_taNC_quarter_->TestBit(kDoNotProcess)){
    c_taus_taNC_quarter_ = true;
  }else{
    c_taus_taNC_quarter_ = false;
  }
  if(b_taus_taNC_tenth_ && !b_taus_taNC_tenth_->TestBit(kDoNotProcess)){
    c_taus_taNC_tenth_ = true;
  }else{
    c_taus_taNC_tenth_ = false;
  }
  if(b_taus_theta_ && !b_taus_theta_->TestBit(kDoNotProcess)){
    c_taus_theta_ = true;
  }else{
    c_taus_theta_ = false;
  }
  if(b_taus_tkIsoUsingLeadingPi_ && !b_taus_tkIsoUsingLeadingPi_->TestBit(kDoNotProcess)){
    c_taus_tkIsoUsingLeadingPi_ = true;
  }else{
    c_taus_tkIsoUsingLeadingPi_ = false;
  }
  if(b_taus_trackIsolation_ && !b_taus_trackIsolation_->TestBit(kDoNotProcess)){
    c_taus_trackIsolation_ = true;
  }else{
    c_taus_trackIsolation_ = false;
  }
  if(b_trackingfailurefilter_decision_ && !b_trackingfailurefilter_decision_->TestBit(kDoNotProcess)){
    c_trackingfailurefilter_decision_ = true;
  }else{
    c_trackingfailurefilter_decision_ = false;
  }
  if(b_trigger_name_ && !b_trigger_name_->TestBit(kDoNotProcess)){
    c_trigger_name_ = true;
  }else{
    c_trigger_name_ = false;
  }
  if(b_trigger_prescalevalue_ && !b_trigger_prescalevalue_->TestBit(kDoNotProcess)){
    c_trigger_prescalevalue_ = true;
  }else{
    c_trigger_prescalevalue_ = false;
  }
  if(b_weight_ && !b_weight_->TestBit(kDoNotProcess)){
    c_weight_ = true;
  }else{
    c_weight_ = false;
  }
  chainA_.GetEntry(entry);
  chainB_.GetEntry(entry);
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

void cfa_base::InitializeA(){
  chainA_.SetMakeClass(true);
  chainA_.SetBranchStatus("*",0);
  chainA_.SetBranchAddress("PU_NumInteractions", &PU_NumInteractions_, &b_PU_NumInteractions_);
  chainA_.SetBranchAddress("PU_TrueNumInteractions", &PU_TrueNumInteractions_, &b_PU_TrueNumInteractions_);
  chainA_.SetBranchAddress("PU_bunchCrossing", &PU_bunchCrossing_, &b_PU_bunchCrossing_);
  chainA_.SetBranchAddress("PU_ntrks_highpT", &PU_ntrks_highpT_, &b_PU_ntrks_highpT_);
  chainA_.SetBranchAddress("PU_ntrks_lowpT", &PU_ntrks_lowpT_, &b_PU_ntrks_lowpT_);
  chainA_.SetBranchAddress("PU_sumpT_highpT", &PU_sumpT_highpT_, &b_PU_sumpT_highpT_);
  chainA_.SetBranchAddress("PU_sumpT_lowpT", &PU_sumpT_lowpT_, &b_PU_sumpT_lowpT_);
  chainA_.SetBranchAddress("PU_zpositions", &PU_zpositions_, &b_PU_zpositions_);
  chainA_.SetBranchAddress("cschalofilter_decision", &cschalofilter_decision_, &b_cschalofilter_decision_);
  chainA_.SetBranchAddress("ecallaserfilter_decision", &ecallaserfilter_decision_, &b_ecallaserfilter_decision_);
  chainA_.SetBranchAddress("eebadscfilter_decision", &eebadscfilter_decision_, &b_eebadscfilter_decision_);
  chainA_.SetBranchAddress("hcallaserfilter_decision", &hcallaserfilter_decision_, &b_hcallaserfilter_decision_);
  chainA_.SetBranchAddress("standalone_triggerobject_collectionname", &standalone_triggerobject_collectionname_, &b_standalone_triggerobject_collectionname_);
  chainA_.SetBranchAddress("standalone_triggerobject_energy", &standalone_triggerobject_energy_, &b_standalone_triggerobject_energy_);
  chainA_.SetBranchAddress("standalone_triggerobject_et", &standalone_triggerobject_et_, &b_standalone_triggerobject_et_);
  chainA_.SetBranchAddress("standalone_triggerobject_eta", &standalone_triggerobject_eta_, &b_standalone_triggerobject_eta_);
  chainA_.SetBranchAddress("standalone_triggerobject_phi", &standalone_triggerobject_phi_, &b_standalone_triggerobject_phi_);
  chainA_.SetBranchAddress("standalone_triggerobject_pt", &standalone_triggerobject_pt_, &b_standalone_triggerobject_pt_);
  chainA_.SetBranchAddress("standalone_triggerobject_px", &standalone_triggerobject_px_, &b_standalone_triggerobject_px_);
  chainA_.SetBranchAddress("standalone_triggerobject_py", &standalone_triggerobject_py_, &b_standalone_triggerobject_py_);
  chainA_.SetBranchAddress("standalone_triggerobject_pz", &standalone_triggerobject_pz_, &b_standalone_triggerobject_pz_);
  chainA_.SetBranchAddress("trackingfailurefilter_decision", &trackingfailurefilter_decision_, &b_trackingfailurefilter_decision_);
  chainA_.SetBranchAddress("trigger_name", &trigger_name_, &b_trigger_name_);
  chainA_.SetBranchAddress("trigger_prescalevalue", &trigger_prescalevalue_, &b_trigger_prescalevalue_);
}

void cfa_base::InitializeB(){
  chainB_.SetMakeClass(true);
  chainB_.SetBranchStatus("*",0);
  chainB_.SetBranchAddress("NbeamSpot", &NbeamSpot_, &b_NbeamSpot_);
  chainB_.SetBranchAddress("Nels", &Nels_, &b_Nels_);
  chainB_.SetBranchAddress("Nmc_doc", &Nmc_doc_, &b_Nmc_doc_);
  chainB_.SetBranchAddress("Nmc_electrons", &Nmc_electrons_, &b_Nmc_electrons_);
  chainB_.SetBranchAddress("Nmc_mus", &Nmc_mus_, &b_Nmc_mus_);
  chainB_.SetBranchAddress("Nmc_nues", &Nmc_nues_, &b_Nmc_nues_);
  chainB_.SetBranchAddress("Nmc_numus", &Nmc_numus_, &b_Nmc_numus_);
  chainB_.SetBranchAddress("Nmc_nutaus", &Nmc_nutaus_, &b_Nmc_nutaus_);
  chainB_.SetBranchAddress("Nmc_photons", &Nmc_photons_, &b_Nmc_photons_);
  chainB_.SetBranchAddress("Nmc_taus", &Nmc_taus_, &b_Nmc_taus_);
  chainB_.SetBranchAddress("Nmus", &Nmus_, &b_Nmus_);
  chainB_.SetBranchAddress("Npfcand", &Npfcand_, &b_Npfcand_);
  chainB_.SetBranchAddress("Nphotons", &Nphotons_, &b_Nphotons_);
  chainB_.SetBranchAddress("Npv", &Npv_, &b_Npv_);
  chainB_.SetBranchAddress("Ntaus", &Ntaus_, &b_Ntaus_);
  chainB_.SetBranchAddress("beamSpot_beamWidthX", &beamSpot_beamWidthX_, &b_beamSpot_beamWidthX_);
  chainB_.SetBranchAddress("beamSpot_beamWidthXError", &beamSpot_beamWidthXError_, &b_beamSpot_beamWidthXError_);
  chainB_.SetBranchAddress("beamSpot_beamWidthY", &beamSpot_beamWidthY_, &b_beamSpot_beamWidthY_);
  chainB_.SetBranchAddress("beamSpot_beamWidthYError", &beamSpot_beamWidthYError_, &b_beamSpot_beamWidthYError_);
  chainB_.SetBranchAddress("beamSpot_dxdz", &beamSpot_dxdz_, &b_beamSpot_dxdz_);
  chainB_.SetBranchAddress("beamSpot_dxdzError", &beamSpot_dxdzError_, &b_beamSpot_dxdzError_);
  chainB_.SetBranchAddress("beamSpot_dydz", &beamSpot_dydz_, &b_beamSpot_dydz_);
  chainB_.SetBranchAddress("beamSpot_dydzError", &beamSpot_dydzError_, &b_beamSpot_dydzError_);
  chainB_.SetBranchAddress("beamSpot_sigmaZ", &beamSpot_sigmaZ_, &b_beamSpot_sigmaZ_);
  chainB_.SetBranchAddress("beamSpot_sigmaZ0Error", &beamSpot_sigmaZ0Error_, &b_beamSpot_sigmaZ0Error_);
  chainB_.SetBranchAddress("beamSpot_x", &beamSpot_x_, &b_beamSpot_x_);
  chainB_.SetBranchAddress("beamSpot_x0Error", &beamSpot_x0Error_, &b_beamSpot_x0Error_);
  chainB_.SetBranchAddress("beamSpot_y", &beamSpot_y_, &b_beamSpot_y_);
  chainB_.SetBranchAddress("beamSpot_y0Error", &beamSpot_y0Error_, &b_beamSpot_y0Error_);
  chainB_.SetBranchAddress("beamSpot_z", &beamSpot_z_, &b_beamSpot_z_);
  chainB_.SetBranchAddress("beamSpot_z0Error", &beamSpot_z0Error_, &b_beamSpot_z0Error_);
  chainB_.SetBranchAddress("bunchCrossing", &bunchCrossing_, &b_bunchCrossing_);
  chainB_.SetBranchAddress("els_PATpassConversionVeto", &els_PATpassConversionVeto_, &b_els_PATpassConversionVeto_);
  chainB_.SetBranchAddress("els_basicClustersSize", &els_basicClustersSize_, &b_els_basicClustersSize_);
  chainB_.SetBranchAddress("els_cIso", &els_cIso_, &b_els_cIso_);
  chainB_.SetBranchAddress("els_caloEnergy", &els_caloEnergy_, &b_els_caloEnergy_);
  chainB_.SetBranchAddress("els_charge", &els_charge_, &b_els_charge_);
  chainB_.SetBranchAddress("els_chi2", &els_chi2_, &b_els_chi2_);
  chainB_.SetBranchAddress("els_core_ecalDrivenSeed", &els_core_ecalDrivenSeed_, &b_els_core_ecalDrivenSeed_);
  chainB_.SetBranchAddress("els_cpx", &els_cpx_, &b_els_cpx_);
  chainB_.SetBranchAddress("els_cpy", &els_cpy_, &b_els_cpy_);
  chainB_.SetBranchAddress("els_cpz", &els_cpz_, &b_els_cpz_);
  chainB_.SetBranchAddress("els_ctf_tk_charge", &els_ctf_tk_charge_, &b_els_ctf_tk_charge_);
  chainB_.SetBranchAddress("els_ctf_tk_eta", &els_ctf_tk_eta_, &b_els_ctf_tk_eta_);
  chainB_.SetBranchAddress("els_ctf_tk_id", &els_ctf_tk_id_, &b_els_ctf_tk_id_);
  chainB_.SetBranchAddress("els_ctf_tk_phi", &els_ctf_tk_phi_, &b_els_ctf_tk_phi_);
  chainB_.SetBranchAddress("els_cx", &els_cx_, &b_els_cx_);
  chainB_.SetBranchAddress("els_cy", &els_cy_, &b_els_cy_);
  chainB_.SetBranchAddress("els_cz", &els_cz_, &b_els_cz_);
  chainB_.SetBranchAddress("els_d0dum", &els_d0dum_, &b_els_d0dum_);
  chainB_.SetBranchAddress("els_d0dumError", &els_d0dumError_, &b_els_d0dumError_);
  chainB_.SetBranchAddress("els_dEtaIn", &els_dEtaIn_, &b_els_dEtaIn_);
  chainB_.SetBranchAddress("els_dEtaOut", &els_dEtaOut_, &b_els_dEtaOut_);
  chainB_.SetBranchAddress("els_dPhiIn", &els_dPhiIn_, &b_els_dPhiIn_);
  chainB_.SetBranchAddress("els_dPhiOut", &els_dPhiOut_, &b_els_dPhiOut_);
  chainB_.SetBranchAddress("els_dr03EcalRecHitSumEt", &els_dr03EcalRecHitSumEt_, &b_els_dr03EcalRecHitSumEt_);
  chainB_.SetBranchAddress("els_dr03HcalDepth1TowerSumEt", &els_dr03HcalDepth1TowerSumEt_, &b_els_dr03HcalDepth1TowerSumEt_);
  chainB_.SetBranchAddress("els_dr03HcalDepth2TowerSumEt", &els_dr03HcalDepth2TowerSumEt_, &b_els_dr03HcalDepth2TowerSumEt_);
  chainB_.SetBranchAddress("els_dr03HcalTowerSumEt", &els_dr03HcalTowerSumEt_, &b_els_dr03HcalTowerSumEt_);
  chainB_.SetBranchAddress("els_dr03TkSumPt", &els_dr03TkSumPt_, &b_els_dr03TkSumPt_);
  chainB_.SetBranchAddress("els_dr04EcalRecHitSumEt", &els_dr04EcalRecHitSumEt_, &b_els_dr04EcalRecHitSumEt_);
  chainB_.SetBranchAddress("els_dr04HcalDepth1TowerSumEt", &els_dr04HcalDepth1TowerSumEt_, &b_els_dr04HcalDepth1TowerSumEt_);
  chainB_.SetBranchAddress("els_dr04HcalDepth2TowerSumEt", &els_dr04HcalDepth2TowerSumEt_, &b_els_dr04HcalDepth2TowerSumEt_);
  chainB_.SetBranchAddress("els_dr04HcalTowerSumEt", &els_dr04HcalTowerSumEt_, &b_els_dr04HcalTowerSumEt_);
  chainB_.SetBranchAddress("els_dr04TkSumPt", &els_dr04TkSumPt_, &b_els_dr04TkSumPt_);
  chainB_.SetBranchAddress("els_dz", &els_dz_, &b_els_dz_);
  chainB_.SetBranchAddress("els_dzError", &els_dzError_, &b_els_dzError_);
  chainB_.SetBranchAddress("els_eOverPIn", &els_eOverPIn_, &b_els_eOverPIn_);
  chainB_.SetBranchAddress("els_eSeedOverPOut", &els_eSeedOverPOut_, &b_els_eSeedOverPOut_);
  chainB_.SetBranchAddress("els_ecalIso", &els_ecalIso_, &b_els_ecalIso_);
  chainB_.SetBranchAddress("els_energy", &els_energy_, &b_els_energy_);
  chainB_.SetBranchAddress("els_et", &els_et_, &b_els_et_);
  chainB_.SetBranchAddress("els_eta", &els_eta_, &b_els_eta_);
  chainB_.SetBranchAddress("els_etaError", &els_etaError_, &b_els_etaError_);
  chainB_.SetBranchAddress("els_fbrem", &els_fbrem_, &b_els_fbrem_);
  chainB_.SetBranchAddress("els_gen_et", &els_gen_et_, &b_els_gen_et_);
  chainB_.SetBranchAddress("els_gen_eta", &els_gen_eta_, &b_els_gen_eta_);
  chainB_.SetBranchAddress("els_gen_id", &els_gen_id_, &b_els_gen_id_);
  chainB_.SetBranchAddress("els_gen_mother_et", &els_gen_mother_et_, &b_els_gen_mother_et_);
  chainB_.SetBranchAddress("els_gen_mother_eta", &els_gen_mother_eta_, &b_els_gen_mother_eta_);
  chainB_.SetBranchAddress("els_gen_mother_id", &els_gen_mother_id_, &b_els_gen_mother_id_);
  chainB_.SetBranchAddress("els_gen_mother_phi", &els_gen_mother_phi_, &b_els_gen_mother_phi_);
  chainB_.SetBranchAddress("els_gen_mother_pt", &els_gen_mother_pt_, &b_els_gen_mother_pt_);
  chainB_.SetBranchAddress("els_gen_mother_px", &els_gen_mother_px_, &b_els_gen_mother_px_);
  chainB_.SetBranchAddress("els_gen_mother_py", &els_gen_mother_py_, &b_els_gen_mother_py_);
  chainB_.SetBranchAddress("els_gen_mother_pz", &els_gen_mother_pz_, &b_els_gen_mother_pz_);
  chainB_.SetBranchAddress("els_gen_mother_theta", &els_gen_mother_theta_, &b_els_gen_mother_theta_);
  chainB_.SetBranchAddress("els_gen_phi", &els_gen_phi_, &b_els_gen_phi_);
  chainB_.SetBranchAddress("els_gen_pt", &els_gen_pt_, &b_els_gen_pt_);
  chainB_.SetBranchAddress("els_gen_px", &els_gen_px_, &b_els_gen_px_);
  chainB_.SetBranchAddress("els_gen_py", &els_gen_py_, &b_els_gen_py_);
  chainB_.SetBranchAddress("els_gen_pz", &els_gen_pz_, &b_els_gen_pz_);
  chainB_.SetBranchAddress("els_gen_theta", &els_gen_theta_, &b_els_gen_theta_);
  chainB_.SetBranchAddress("els_hadOverEm", &els_hadOverEm_, &b_els_hadOverEm_);
  chainB_.SetBranchAddress("els_hcalIso", &els_hcalIso_, &b_els_hcalIso_);
  chainB_.SetBranchAddress("els_hcalOverEcalBc", &els_hcalOverEcalBc_, &b_els_hcalOverEcalBc_);
  chainB_.SetBranchAddress("els_isEB", &els_isEB_, &b_els_isEB_);
  chainB_.SetBranchAddress("els_isEE", &els_isEE_, &b_els_isEE_);
  chainB_.SetBranchAddress("els_looseId", &els_looseId_, &b_els_looseId_);
  chainB_.SetBranchAddress("els_n_inner_layer", &els_n_inner_layer_, &b_els_n_inner_layer_);
  chainB_.SetBranchAddress("els_n_outer_layer", &els_n_outer_layer_, &b_els_n_outer_layer_);
  chainB_.SetBranchAddress("els_ndof", &els_ndof_, &b_els_ndof_);
  chainB_.SetBranchAddress("els_numlosthits", &els_numlosthits_, &b_els_numlosthits_);
  chainB_.SetBranchAddress("els_numvalhits", &els_numvalhits_, &b_els_numvalhits_);
  chainB_.SetBranchAddress("els_phi", &els_phi_, &b_els_phi_);
  chainB_.SetBranchAddress("els_phiError", &els_phiError_, &b_els_phiError_);
  chainB_.SetBranchAddress("els_pt", &els_pt_, &b_els_pt_);
  chainB_.SetBranchAddress("els_ptError", &els_ptError_, &b_els_ptError_);
  chainB_.SetBranchAddress("els_px", &els_px_, &b_els_px_);
  chainB_.SetBranchAddress("els_py", &els_py_, &b_els_py_);
  chainB_.SetBranchAddress("els_pz", &els_pz_, &b_els_pz_);
  chainB_.SetBranchAddress("els_robustHighEnergyId", &els_robustHighEnergyId_, &b_els_robustHighEnergyId_);
  chainB_.SetBranchAddress("els_robustLooseId", &els_robustLooseId_, &b_els_robustLooseId_);
  chainB_.SetBranchAddress("els_robustTightId", &els_robustTightId_, &b_els_robustTightId_);
  chainB_.SetBranchAddress("els_scE1x5", &els_scE1x5_, &b_els_scE1x5_);
  chainB_.SetBranchAddress("els_scE2x5Max", &els_scE2x5Max_, &b_els_scE2x5Max_);
  chainB_.SetBranchAddress("els_scE5x5", &els_scE5x5_, &b_els_scE5x5_);
  chainB_.SetBranchAddress("els_scEnergy", &els_scEnergy_, &b_els_scEnergy_);
  chainB_.SetBranchAddress("els_scEta", &els_scEta_, &b_els_scEta_);
  chainB_.SetBranchAddress("els_scEtaWidth", &els_scEtaWidth_, &b_els_scEtaWidth_);
  chainB_.SetBranchAddress("els_scPhi", &els_scPhi_, &b_els_scPhi_);
  chainB_.SetBranchAddress("els_scPhiWidth", &els_scPhiWidth_, &b_els_scPhiWidth_);
  chainB_.SetBranchAddress("els_scRawEnergy", &els_scRawEnergy_, &b_els_scRawEnergy_);
  chainB_.SetBranchAddress("els_scSeedEnergy", &els_scSeedEnergy_, &b_els_scSeedEnergy_);
  chainB_.SetBranchAddress("els_shFracInnerHits", &els_shFracInnerHits_, &b_els_shFracInnerHits_);
  chainB_.SetBranchAddress("els_sigmaEtaEta", &els_sigmaEtaEta_, &b_els_sigmaEtaEta_);
  chainB_.SetBranchAddress("els_sigmaIEtaIEta", &els_sigmaIEtaIEta_, &b_els_sigmaIEtaIEta_);
  chainB_.SetBranchAddress("els_simpleEleId60cIso", &els_simpleEleId60cIso_, &b_els_simpleEleId60cIso_);
  chainB_.SetBranchAddress("els_simpleEleId60relIso", &els_simpleEleId60relIso_, &b_els_simpleEleId60relIso_);
  chainB_.SetBranchAddress("els_simpleEleId70cIso", &els_simpleEleId70cIso_, &b_els_simpleEleId70cIso_);
  chainB_.SetBranchAddress("els_simpleEleId70relIso", &els_simpleEleId70relIso_, &b_els_simpleEleId70relIso_);
  chainB_.SetBranchAddress("els_simpleEleId80cIso", &els_simpleEleId80cIso_, &b_els_simpleEleId80cIso_);
  chainB_.SetBranchAddress("els_simpleEleId80relIso", &els_simpleEleId80relIso_, &b_els_simpleEleId80relIso_);
  chainB_.SetBranchAddress("els_simpleEleId85cIso", &els_simpleEleId85cIso_, &b_els_simpleEleId85cIso_);
  chainB_.SetBranchAddress("els_simpleEleId85relIso", &els_simpleEleId85relIso_, &b_els_simpleEleId85relIso_);
  chainB_.SetBranchAddress("els_simpleEleId90cIso", &els_simpleEleId90cIso_, &b_els_simpleEleId90cIso_);
  chainB_.SetBranchAddress("els_simpleEleId90relIso", &els_simpleEleId90relIso_, &b_els_simpleEleId90relIso_);
  chainB_.SetBranchAddress("els_simpleEleId95cIso", &els_simpleEleId95cIso_, &b_els_simpleEleId95cIso_);
  chainB_.SetBranchAddress("els_simpleEleId95relIso", &els_simpleEleId95relIso_, &b_els_simpleEleId95relIso_);
  chainB_.SetBranchAddress("els_status", &els_status_, &b_els_status_);
  chainB_.SetBranchAddress("els_tIso", &els_tIso_, &b_els_tIso_);
  chainB_.SetBranchAddress("els_theta", &els_theta_, &b_els_theta_);
  chainB_.SetBranchAddress("els_tightId", &els_tightId_, &b_els_tightId_);
  chainB_.SetBranchAddress("els_tk_charge", &els_tk_charge_, &b_els_tk_charge_);
  chainB_.SetBranchAddress("els_tk_eta", &els_tk_eta_, &b_els_tk_eta_);
  chainB_.SetBranchAddress("els_tk_phi", &els_tk_phi_, &b_els_tk_phi_);
  chainB_.SetBranchAddress("els_tk_pt", &els_tk_pt_, &b_els_tk_pt_);
  chainB_.SetBranchAddress("els_tk_pz", &els_tk_pz_, &b_els_tk_pz_);
  chainB_.SetBranchAddress("els_vpx", &els_vpx_, &b_els_vpx_);
  chainB_.SetBranchAddress("els_vpy", &els_vpy_, &b_els_vpy_);
  chainB_.SetBranchAddress("els_vpz", &els_vpz_, &b_els_vpz_);
  chainB_.SetBranchAddress("els_vx", &els_vx_, &b_els_vx_);
  chainB_.SetBranchAddress("els_vy", &els_vy_, &b_els_vy_);
  chainB_.SetBranchAddress("els_vz", &els_vz_, &b_els_vz_);
  chainB_.SetBranchAddress("event", &event_, &b_event_);
  chainB_.SetBranchAddress("experimentType", &experimentType_, &b_experimentType_);
  chainB_.SetBranchAddress("lumiblock", &lumiblock_, &b_lumiblock_);
  chainB_.SetBranchAddress("mc_doc_charge", &mc_doc_charge_, &b_mc_doc_charge_);
  chainB_.SetBranchAddress("mc_doc_energy", &mc_doc_energy_, &b_mc_doc_energy_);
  chainB_.SetBranchAddress("mc_doc_eta", &mc_doc_eta_, &b_mc_doc_eta_);
  chainB_.SetBranchAddress("mc_doc_ggrandmother_id", &mc_doc_ggrandmother_id_, &b_mc_doc_ggrandmother_id_);
  chainB_.SetBranchAddress("mc_doc_grandmother_id", &mc_doc_grandmother_id_, &b_mc_doc_grandmother_id_);
  chainB_.SetBranchAddress("mc_doc_id", &mc_doc_id_, &b_mc_doc_id_);
  chainB_.SetBranchAddress("mc_doc_mass", &mc_doc_mass_, &b_mc_doc_mass_);
  chainB_.SetBranchAddress("mc_doc_mother_id", &mc_doc_mother_id_, &b_mc_doc_mother_id_);
  chainB_.SetBranchAddress("mc_doc_mother_pt", &mc_doc_mother_pt_, &b_mc_doc_mother_pt_);
  chainB_.SetBranchAddress("mc_doc_numOfDaughters", &mc_doc_numOfDaughters_, &b_mc_doc_numOfDaughters_);
  chainB_.SetBranchAddress("mc_doc_numOfMothers", &mc_doc_numOfMothers_, &b_mc_doc_numOfMothers_);
  chainB_.SetBranchAddress("mc_doc_phi", &mc_doc_phi_, &b_mc_doc_phi_);
  chainB_.SetBranchAddress("mc_doc_pt", &mc_doc_pt_, &b_mc_doc_pt_);
  chainB_.SetBranchAddress("mc_doc_px", &mc_doc_px_, &b_mc_doc_px_);
  chainB_.SetBranchAddress("mc_doc_py", &mc_doc_py_, &b_mc_doc_py_);
  chainB_.SetBranchAddress("mc_doc_pz", &mc_doc_pz_, &b_mc_doc_pz_);
  chainB_.SetBranchAddress("mc_doc_status", &mc_doc_status_, &b_mc_doc_status_);
  chainB_.SetBranchAddress("mc_doc_theta", &mc_doc_theta_, &b_mc_doc_theta_);
  chainB_.SetBranchAddress("mc_doc_vertex_x", &mc_doc_vertex_x_, &b_mc_doc_vertex_x_);
  chainB_.SetBranchAddress("mc_doc_vertex_y", &mc_doc_vertex_y_, &b_mc_doc_vertex_y_);
  chainB_.SetBranchAddress("mc_doc_vertex_z", &mc_doc_vertex_z_, &b_mc_doc_vertex_z_);
  chainB_.SetBranchAddress("mc_electrons_charge", &mc_electrons_charge_, &b_mc_electrons_charge_);
  chainB_.SetBranchAddress("mc_electrons_energy", &mc_electrons_energy_, &b_mc_electrons_energy_);
  chainB_.SetBranchAddress("mc_electrons_eta", &mc_electrons_eta_, &b_mc_electrons_eta_);
  chainB_.SetBranchAddress("mc_electrons_ggrandmother_id", &mc_electrons_ggrandmother_id_, &b_mc_electrons_ggrandmother_id_);
  chainB_.SetBranchAddress("mc_electrons_grandmother_id", &mc_electrons_grandmother_id_, &b_mc_electrons_grandmother_id_);
  chainB_.SetBranchAddress("mc_electrons_id", &mc_electrons_id_, &b_mc_electrons_id_);
  chainB_.SetBranchAddress("mc_electrons_mass", &mc_electrons_mass_, &b_mc_electrons_mass_);
  chainB_.SetBranchAddress("mc_electrons_mother_id", &mc_electrons_mother_id_, &b_mc_electrons_mother_id_);
  chainB_.SetBranchAddress("mc_electrons_mother_pt", &mc_electrons_mother_pt_, &b_mc_electrons_mother_pt_);
  chainB_.SetBranchAddress("mc_electrons_numOfDaughters", &mc_electrons_numOfDaughters_, &b_mc_electrons_numOfDaughters_);
  chainB_.SetBranchAddress("mc_electrons_phi", &mc_electrons_phi_, &b_mc_electrons_phi_);
  chainB_.SetBranchAddress("mc_electrons_pt", &mc_electrons_pt_, &b_mc_electrons_pt_);
  chainB_.SetBranchAddress("mc_electrons_px", &mc_electrons_px_, &b_mc_electrons_px_);
  chainB_.SetBranchAddress("mc_electrons_py", &mc_electrons_py_, &b_mc_electrons_py_);
  chainB_.SetBranchAddress("mc_electrons_pz", &mc_electrons_pz_, &b_mc_electrons_pz_);
  chainB_.SetBranchAddress("mc_electrons_status", &mc_electrons_status_, &b_mc_electrons_status_);
  chainB_.SetBranchAddress("mc_electrons_theta", &mc_electrons_theta_, &b_mc_electrons_theta_);
  chainB_.SetBranchAddress("mc_electrons_vertex_x", &mc_electrons_vertex_x_, &b_mc_electrons_vertex_x_);
  chainB_.SetBranchAddress("mc_electrons_vertex_y", &mc_electrons_vertex_y_, &b_mc_electrons_vertex_y_);
  chainB_.SetBranchAddress("mc_electrons_vertex_z", &mc_electrons_vertex_z_, &b_mc_electrons_vertex_z_);
  chainB_.SetBranchAddress("mc_mus_charge", &mc_mus_charge_, &b_mc_mus_charge_);
  chainB_.SetBranchAddress("mc_mus_energy", &mc_mus_energy_, &b_mc_mus_energy_);
  chainB_.SetBranchAddress("mc_mus_eta", &mc_mus_eta_, &b_mc_mus_eta_);
  chainB_.SetBranchAddress("mc_mus_ggrandmother_id", &mc_mus_ggrandmother_id_, &b_mc_mus_ggrandmother_id_);
  chainB_.SetBranchAddress("mc_mus_grandmother_id", &mc_mus_grandmother_id_, &b_mc_mus_grandmother_id_);
  chainB_.SetBranchAddress("mc_mus_id", &mc_mus_id_, &b_mc_mus_id_);
  chainB_.SetBranchAddress("mc_mus_mass", &mc_mus_mass_, &b_mc_mus_mass_);
  chainB_.SetBranchAddress("mc_mus_mother_id", &mc_mus_mother_id_, &b_mc_mus_mother_id_);
  chainB_.SetBranchAddress("mc_mus_mother_pt", &mc_mus_mother_pt_, &b_mc_mus_mother_pt_);
  chainB_.SetBranchAddress("mc_mus_numOfDaughters", &mc_mus_numOfDaughters_, &b_mc_mus_numOfDaughters_);
  chainB_.SetBranchAddress("mc_mus_phi", &mc_mus_phi_, &b_mc_mus_phi_);
  chainB_.SetBranchAddress("mc_mus_pt", &mc_mus_pt_, &b_mc_mus_pt_);
  chainB_.SetBranchAddress("mc_mus_px", &mc_mus_px_, &b_mc_mus_px_);
  chainB_.SetBranchAddress("mc_mus_py", &mc_mus_py_, &b_mc_mus_py_);
  chainB_.SetBranchAddress("mc_mus_pz", &mc_mus_pz_, &b_mc_mus_pz_);
  chainB_.SetBranchAddress("mc_mus_status", &mc_mus_status_, &b_mc_mus_status_);
  chainB_.SetBranchAddress("mc_mus_theta", &mc_mus_theta_, &b_mc_mus_theta_);
  chainB_.SetBranchAddress("mc_mus_vertex_x", &mc_mus_vertex_x_, &b_mc_mus_vertex_x_);
  chainB_.SetBranchAddress("mc_mus_vertex_y", &mc_mus_vertex_y_, &b_mc_mus_vertex_y_);
  chainB_.SetBranchAddress("mc_mus_vertex_z", &mc_mus_vertex_z_, &b_mc_mus_vertex_z_);
  chainB_.SetBranchAddress("mc_nues_charge", &mc_nues_charge_, &b_mc_nues_charge_);
  chainB_.SetBranchAddress("mc_nues_energy", &mc_nues_energy_, &b_mc_nues_energy_);
  chainB_.SetBranchAddress("mc_nues_eta", &mc_nues_eta_, &b_mc_nues_eta_);
  chainB_.SetBranchAddress("mc_nues_ggrandmother_id", &mc_nues_ggrandmother_id_, &b_mc_nues_ggrandmother_id_);
  chainB_.SetBranchAddress("mc_nues_grandmother_id", &mc_nues_grandmother_id_, &b_mc_nues_grandmother_id_);
  chainB_.SetBranchAddress("mc_nues_id", &mc_nues_id_, &b_mc_nues_id_);
  chainB_.SetBranchAddress("mc_nues_mass", &mc_nues_mass_, &b_mc_nues_mass_);
  chainB_.SetBranchAddress("mc_nues_mother_id", &mc_nues_mother_id_, &b_mc_nues_mother_id_);
  chainB_.SetBranchAddress("mc_nues_mother_pt", &mc_nues_mother_pt_, &b_mc_nues_mother_pt_);
  chainB_.SetBranchAddress("mc_nues_numOfDaughters", &mc_nues_numOfDaughters_, &b_mc_nues_numOfDaughters_);
  chainB_.SetBranchAddress("mc_nues_phi", &mc_nues_phi_, &b_mc_nues_phi_);
  chainB_.SetBranchAddress("mc_nues_pt", &mc_nues_pt_, &b_mc_nues_pt_);
  chainB_.SetBranchAddress("mc_nues_px", &mc_nues_px_, &b_mc_nues_px_);
  chainB_.SetBranchAddress("mc_nues_py", &mc_nues_py_, &b_mc_nues_py_);
  chainB_.SetBranchAddress("mc_nues_pz", &mc_nues_pz_, &b_mc_nues_pz_);
  chainB_.SetBranchAddress("mc_nues_status", &mc_nues_status_, &b_mc_nues_status_);
  chainB_.SetBranchAddress("mc_nues_theta", &mc_nues_theta_, &b_mc_nues_theta_);
  chainB_.SetBranchAddress("mc_nues_vertex_x", &mc_nues_vertex_x_, &b_mc_nues_vertex_x_);
  chainB_.SetBranchAddress("mc_nues_vertex_y", &mc_nues_vertex_y_, &b_mc_nues_vertex_y_);
  chainB_.SetBranchAddress("mc_nues_vertex_z", &mc_nues_vertex_z_, &b_mc_nues_vertex_z_);
  chainB_.SetBranchAddress("mc_numus_charge", &mc_numus_charge_, &b_mc_numus_charge_);
  chainB_.SetBranchAddress("mc_numus_energy", &mc_numus_energy_, &b_mc_numus_energy_);
  chainB_.SetBranchAddress("mc_numus_eta", &mc_numus_eta_, &b_mc_numus_eta_);
  chainB_.SetBranchAddress("mc_numus_ggrandmother_id", &mc_numus_ggrandmother_id_, &b_mc_numus_ggrandmother_id_);
  chainB_.SetBranchAddress("mc_numus_grandmother_id", &mc_numus_grandmother_id_, &b_mc_numus_grandmother_id_);
  chainB_.SetBranchAddress("mc_numus_id", &mc_numus_id_, &b_mc_numus_id_);
  chainB_.SetBranchAddress("mc_numus_mass", &mc_numus_mass_, &b_mc_numus_mass_);
  chainB_.SetBranchAddress("mc_numus_mother_id", &mc_numus_mother_id_, &b_mc_numus_mother_id_);
  chainB_.SetBranchAddress("mc_numus_mother_pt", &mc_numus_mother_pt_, &b_mc_numus_mother_pt_);
  chainB_.SetBranchAddress("mc_numus_numOfDaughters", &mc_numus_numOfDaughters_, &b_mc_numus_numOfDaughters_);
  chainB_.SetBranchAddress("mc_numus_phi", &mc_numus_phi_, &b_mc_numus_phi_);
  chainB_.SetBranchAddress("mc_numus_pt", &mc_numus_pt_, &b_mc_numus_pt_);
  chainB_.SetBranchAddress("mc_numus_px", &mc_numus_px_, &b_mc_numus_px_);
  chainB_.SetBranchAddress("mc_numus_py", &mc_numus_py_, &b_mc_numus_py_);
  chainB_.SetBranchAddress("mc_numus_pz", &mc_numus_pz_, &b_mc_numus_pz_);
  chainB_.SetBranchAddress("mc_numus_status", &mc_numus_status_, &b_mc_numus_status_);
  chainB_.SetBranchAddress("mc_numus_theta", &mc_numus_theta_, &b_mc_numus_theta_);
  chainB_.SetBranchAddress("mc_numus_vertex_x", &mc_numus_vertex_x_, &b_mc_numus_vertex_x_);
  chainB_.SetBranchAddress("mc_numus_vertex_y", &mc_numus_vertex_y_, &b_mc_numus_vertex_y_);
  chainB_.SetBranchAddress("mc_numus_vertex_z", &mc_numus_vertex_z_, &b_mc_numus_vertex_z_);
  chainB_.SetBranchAddress("mc_nutaus_charge", &mc_nutaus_charge_, &b_mc_nutaus_charge_);
  chainB_.SetBranchAddress("mc_nutaus_energy", &mc_nutaus_energy_, &b_mc_nutaus_energy_);
  chainB_.SetBranchAddress("mc_nutaus_eta", &mc_nutaus_eta_, &b_mc_nutaus_eta_);
  chainB_.SetBranchAddress("mc_nutaus_ggrandmother_id", &mc_nutaus_ggrandmother_id_, &b_mc_nutaus_ggrandmother_id_);
  chainB_.SetBranchAddress("mc_nutaus_grandmother_id", &mc_nutaus_grandmother_id_, &b_mc_nutaus_grandmother_id_);
  chainB_.SetBranchAddress("mc_nutaus_id", &mc_nutaus_id_, &b_mc_nutaus_id_);
  chainB_.SetBranchAddress("mc_nutaus_mass", &mc_nutaus_mass_, &b_mc_nutaus_mass_);
  chainB_.SetBranchAddress("mc_nutaus_mother_id", &mc_nutaus_mother_id_, &b_mc_nutaus_mother_id_);
  chainB_.SetBranchAddress("mc_nutaus_mother_pt", &mc_nutaus_mother_pt_, &b_mc_nutaus_mother_pt_);
  chainB_.SetBranchAddress("mc_nutaus_numOfDaughters", &mc_nutaus_numOfDaughters_, &b_mc_nutaus_numOfDaughters_);
  chainB_.SetBranchAddress("mc_nutaus_phi", &mc_nutaus_phi_, &b_mc_nutaus_phi_);
  chainB_.SetBranchAddress("mc_nutaus_pt", &mc_nutaus_pt_, &b_mc_nutaus_pt_);
  chainB_.SetBranchAddress("mc_nutaus_px", &mc_nutaus_px_, &b_mc_nutaus_px_);
  chainB_.SetBranchAddress("mc_nutaus_py", &mc_nutaus_py_, &b_mc_nutaus_py_);
  chainB_.SetBranchAddress("mc_nutaus_pz", &mc_nutaus_pz_, &b_mc_nutaus_pz_);
  chainB_.SetBranchAddress("mc_nutaus_status", &mc_nutaus_status_, &b_mc_nutaus_status_);
  chainB_.SetBranchAddress("mc_nutaus_theta", &mc_nutaus_theta_, &b_mc_nutaus_theta_);
  chainB_.SetBranchAddress("mc_nutaus_vertex_x", &mc_nutaus_vertex_x_, &b_mc_nutaus_vertex_x_);
  chainB_.SetBranchAddress("mc_nutaus_vertex_y", &mc_nutaus_vertex_y_, &b_mc_nutaus_vertex_y_);
  chainB_.SetBranchAddress("mc_nutaus_vertex_z", &mc_nutaus_vertex_z_, &b_mc_nutaus_vertex_z_);
  chainB_.SetBranchAddress("mc_photons_charge", &mc_photons_charge_, &b_mc_photons_charge_);
  chainB_.SetBranchAddress("mc_photons_energy", &mc_photons_energy_, &b_mc_photons_energy_);
  chainB_.SetBranchAddress("mc_photons_eta", &mc_photons_eta_, &b_mc_photons_eta_);
  chainB_.SetBranchAddress("mc_photons_ggrandmother_id", &mc_photons_ggrandmother_id_, &b_mc_photons_ggrandmother_id_);
  chainB_.SetBranchAddress("mc_photons_grandmother_id", &mc_photons_grandmother_id_, &b_mc_photons_grandmother_id_);
  chainB_.SetBranchAddress("mc_photons_id", &mc_photons_id_, &b_mc_photons_id_);
  chainB_.SetBranchAddress("mc_photons_mass", &mc_photons_mass_, &b_mc_photons_mass_);
  chainB_.SetBranchAddress("mc_photons_mother_id", &mc_photons_mother_id_, &b_mc_photons_mother_id_);
  chainB_.SetBranchAddress("mc_photons_mother_pt", &mc_photons_mother_pt_, &b_mc_photons_mother_pt_);
  chainB_.SetBranchAddress("mc_photons_numOfDaughters", &mc_photons_numOfDaughters_, &b_mc_photons_numOfDaughters_);
  chainB_.SetBranchAddress("mc_photons_phi", &mc_photons_phi_, &b_mc_photons_phi_);
  chainB_.SetBranchAddress("mc_photons_pt", &mc_photons_pt_, &b_mc_photons_pt_);
  chainB_.SetBranchAddress("mc_photons_px", &mc_photons_px_, &b_mc_photons_px_);
  chainB_.SetBranchAddress("mc_photons_py", &mc_photons_py_, &b_mc_photons_py_);
  chainB_.SetBranchAddress("mc_photons_pz", &mc_photons_pz_, &b_mc_photons_pz_);
  chainB_.SetBranchAddress("mc_photons_status", &mc_photons_status_, &b_mc_photons_status_);
  chainB_.SetBranchAddress("mc_photons_theta", &mc_photons_theta_, &b_mc_photons_theta_);
  chainB_.SetBranchAddress("mc_photons_vertex_x", &mc_photons_vertex_x_, &b_mc_photons_vertex_x_);
  chainB_.SetBranchAddress("mc_photons_vertex_y", &mc_photons_vertex_y_, &b_mc_photons_vertex_y_);
  chainB_.SetBranchAddress("mc_photons_vertex_z", &mc_photons_vertex_z_, &b_mc_photons_vertex_z_);
  chainB_.SetBranchAddress("mc_taus_charge", &mc_taus_charge_, &b_mc_taus_charge_);
  chainB_.SetBranchAddress("mc_taus_energy", &mc_taus_energy_, &b_mc_taus_energy_);
  chainB_.SetBranchAddress("mc_taus_eta", &mc_taus_eta_, &b_mc_taus_eta_);
  chainB_.SetBranchAddress("mc_taus_ggrandmother_id", &mc_taus_ggrandmother_id_, &b_mc_taus_ggrandmother_id_);
  chainB_.SetBranchAddress("mc_taus_grandmother_id", &mc_taus_grandmother_id_, &b_mc_taus_grandmother_id_);
  chainB_.SetBranchAddress("mc_taus_id", &mc_taus_id_, &b_mc_taus_id_);
  chainB_.SetBranchAddress("mc_taus_mass", &mc_taus_mass_, &b_mc_taus_mass_);
  chainB_.SetBranchAddress("mc_taus_mother_id", &mc_taus_mother_id_, &b_mc_taus_mother_id_);
  chainB_.SetBranchAddress("mc_taus_mother_pt", &mc_taus_mother_pt_, &b_mc_taus_mother_pt_);
  chainB_.SetBranchAddress("mc_taus_numOfDaughters", &mc_taus_numOfDaughters_, &b_mc_taus_numOfDaughters_);
  chainB_.SetBranchAddress("mc_taus_phi", &mc_taus_phi_, &b_mc_taus_phi_);
  chainB_.SetBranchAddress("mc_taus_pt", &mc_taus_pt_, &b_mc_taus_pt_);
  chainB_.SetBranchAddress("mc_taus_px", &mc_taus_px_, &b_mc_taus_px_);
  chainB_.SetBranchAddress("mc_taus_py", &mc_taus_py_, &b_mc_taus_py_);
  chainB_.SetBranchAddress("mc_taus_pz", &mc_taus_pz_, &b_mc_taus_pz_);
  chainB_.SetBranchAddress("mc_taus_status", &mc_taus_status_, &b_mc_taus_status_);
  chainB_.SetBranchAddress("mc_taus_theta", &mc_taus_theta_, &b_mc_taus_theta_);
  chainB_.SetBranchAddress("mc_taus_vertex_x", &mc_taus_vertex_x_, &b_mc_taus_vertex_x_);
  chainB_.SetBranchAddress("mc_taus_vertex_y", &mc_taus_vertex_y_, &b_mc_taus_vertex_y_);
  chainB_.SetBranchAddress("mc_taus_vertex_z", &mc_taus_vertex_z_, &b_mc_taus_vertex_z_);
  chainB_.SetBranchAddress("model_params", &model_params_, &b_model_params_);
  chainB_.SetBranchAddress("mus_cIso", &mus_cIso_, &b_mus_cIso_);
  chainB_.SetBranchAddress("mus_calEnergyEm", &mus_calEnergyEm_, &b_mus_calEnergyEm_);
  chainB_.SetBranchAddress("mus_calEnergyEmS9", &mus_calEnergyEmS9_, &b_mus_calEnergyEmS9_);
  chainB_.SetBranchAddress("mus_calEnergyHad", &mus_calEnergyHad_, &b_mus_calEnergyHad_);
  chainB_.SetBranchAddress("mus_calEnergyHadS9", &mus_calEnergyHadS9_, &b_mus_calEnergyHadS9_);
  chainB_.SetBranchAddress("mus_calEnergyHo", &mus_calEnergyHo_, &b_mus_calEnergyHo_);
  chainB_.SetBranchAddress("mus_calEnergyHoS9", &mus_calEnergyHoS9_, &b_mus_calEnergyHoS9_);
  chainB_.SetBranchAddress("mus_charge", &mus_charge_, &b_mus_charge_);
  chainB_.SetBranchAddress("mus_cm_ExpectedHitsInner", &mus_cm_ExpectedHitsInner_, &b_mus_cm_ExpectedHitsInner_);
  chainB_.SetBranchAddress("mus_cm_ExpectedHitsOuter", &mus_cm_ExpectedHitsOuter_, &b_mus_cm_ExpectedHitsOuter_);
  chainB_.SetBranchAddress("mus_cm_LayersWithMeasurement", &mus_cm_LayersWithMeasurement_, &b_mus_cm_LayersWithMeasurement_);
  chainB_.SetBranchAddress("mus_cm_LayersWithoutMeasurement", &mus_cm_LayersWithoutMeasurement_, &b_mus_cm_LayersWithoutMeasurement_);
  chainB_.SetBranchAddress("mus_cm_PixelLayersWithMeasurement", &mus_cm_PixelLayersWithMeasurement_, &b_mus_cm_PixelLayersWithMeasurement_);
  chainB_.SetBranchAddress("mus_cm_ValidStripLayersWithMonoAndStereoHit", &mus_cm_ValidStripLayersWithMonoAndStereoHit_, &b_mus_cm_ValidStripLayersWithMonoAndStereoHit_);
  chainB_.SetBranchAddress("mus_cm_chg", &mus_cm_chg_, &b_mus_cm_chg_);
  chainB_.SetBranchAddress("mus_cm_chi2", &mus_cm_chi2_, &b_mus_cm_chi2_);
  chainB_.SetBranchAddress("mus_cm_d0dum", &mus_cm_d0dum_, &b_mus_cm_d0dum_);
  chainB_.SetBranchAddress("mus_cm_d0dumErr", &mus_cm_d0dumErr_, &b_mus_cm_d0dumErr_);
  chainB_.SetBranchAddress("mus_cm_dz", &mus_cm_dz_, &b_mus_cm_dz_);
  chainB_.SetBranchAddress("mus_cm_dzErr", &mus_cm_dzErr_, &b_mus_cm_dzErr_);
  chainB_.SetBranchAddress("mus_cm_eta", &mus_cm_eta_, &b_mus_cm_eta_);
  chainB_.SetBranchAddress("mus_cm_etaErr", &mus_cm_etaErr_, &b_mus_cm_etaErr_);
  chainB_.SetBranchAddress("mus_cm_ndof", &mus_cm_ndof_, &b_mus_cm_ndof_);
  chainB_.SetBranchAddress("mus_cm_numlosthits", &mus_cm_numlosthits_, &b_mus_cm_numlosthits_);
  chainB_.SetBranchAddress("mus_cm_numvalMuonhits", &mus_cm_numvalMuonhits_, &b_mus_cm_numvalMuonhits_);
  chainB_.SetBranchAddress("mus_cm_numvalhits", &mus_cm_numvalhits_, &b_mus_cm_numvalhits_);
  chainB_.SetBranchAddress("mus_cm_phi", &mus_cm_phi_, &b_mus_cm_phi_);
  chainB_.SetBranchAddress("mus_cm_phiErr", &mus_cm_phiErr_, &b_mus_cm_phiErr_);
  chainB_.SetBranchAddress("mus_cm_pt", &mus_cm_pt_, &b_mus_cm_pt_);
  chainB_.SetBranchAddress("mus_cm_ptErr", &mus_cm_ptErr_, &b_mus_cm_ptErr_);
  chainB_.SetBranchAddress("mus_cm_px", &mus_cm_px_, &b_mus_cm_px_);
  chainB_.SetBranchAddress("mus_cm_py", &mus_cm_py_, &b_mus_cm_py_);
  chainB_.SetBranchAddress("mus_cm_pz", &mus_cm_pz_, &b_mus_cm_pz_);
  chainB_.SetBranchAddress("mus_cm_theta", &mus_cm_theta_, &b_mus_cm_theta_);
  chainB_.SetBranchAddress("mus_cm_vx", &mus_cm_vx_, &b_mus_cm_vx_);
  chainB_.SetBranchAddress("mus_cm_vy", &mus_cm_vy_, &b_mus_cm_vy_);
  chainB_.SetBranchAddress("mus_cm_vz", &mus_cm_vz_, &b_mus_cm_vz_);
  chainB_.SetBranchAddress("mus_dB", &mus_dB_, &b_mus_dB_);
  chainB_.SetBranchAddress("mus_ecalIso", &mus_ecalIso_, &b_mus_ecalIso_);
  chainB_.SetBranchAddress("mus_ecalvetoDep", &mus_ecalvetoDep_, &b_mus_ecalvetoDep_);
  chainB_.SetBranchAddress("mus_energy", &mus_energy_, &b_mus_energy_);
  chainB_.SetBranchAddress("mus_et", &mus_et_, &b_mus_et_);
  chainB_.SetBranchAddress("mus_eta", &mus_eta_, &b_mus_eta_);
  chainB_.SetBranchAddress("mus_gen_et", &mus_gen_et_, &b_mus_gen_et_);
  chainB_.SetBranchAddress("mus_gen_eta", &mus_gen_eta_, &b_mus_gen_eta_);
  chainB_.SetBranchAddress("mus_gen_id", &mus_gen_id_, &b_mus_gen_id_);
  chainB_.SetBranchAddress("mus_gen_mother_et", &mus_gen_mother_et_, &b_mus_gen_mother_et_);
  chainB_.SetBranchAddress("mus_gen_mother_eta", &mus_gen_mother_eta_, &b_mus_gen_mother_eta_);
  chainB_.SetBranchAddress("mus_gen_mother_id", &mus_gen_mother_id_, &b_mus_gen_mother_id_);
  chainB_.SetBranchAddress("mus_gen_mother_phi", &mus_gen_mother_phi_, &b_mus_gen_mother_phi_);
  chainB_.SetBranchAddress("mus_gen_mother_pt", &mus_gen_mother_pt_, &b_mus_gen_mother_pt_);
  chainB_.SetBranchAddress("mus_gen_mother_px", &mus_gen_mother_px_, &b_mus_gen_mother_px_);
  chainB_.SetBranchAddress("mus_gen_mother_py", &mus_gen_mother_py_, &b_mus_gen_mother_py_);
  chainB_.SetBranchAddress("mus_gen_mother_pz", &mus_gen_mother_pz_, &b_mus_gen_mother_pz_);
  chainB_.SetBranchAddress("mus_gen_mother_theta", &mus_gen_mother_theta_, &b_mus_gen_mother_theta_);
  chainB_.SetBranchAddress("mus_gen_phi", &mus_gen_phi_, &b_mus_gen_phi_);
  chainB_.SetBranchAddress("mus_gen_pt", &mus_gen_pt_, &b_mus_gen_pt_);
  chainB_.SetBranchAddress("mus_gen_px", &mus_gen_px_, &b_mus_gen_px_);
  chainB_.SetBranchAddress("mus_gen_py", &mus_gen_py_, &b_mus_gen_py_);
  chainB_.SetBranchAddress("mus_gen_pz", &mus_gen_pz_, &b_mus_gen_pz_);
  chainB_.SetBranchAddress("mus_gen_theta", &mus_gen_theta_, &b_mus_gen_theta_);
  chainB_.SetBranchAddress("mus_hcalIso", &mus_hcalIso_, &b_mus_hcalIso_);
  chainB_.SetBranchAddress("mus_hcalvetoDep", &mus_hcalvetoDep_, &b_mus_hcalvetoDep_);
  chainB_.SetBranchAddress("mus_id_All", &mus_id_All_, &b_mus_id_All_);
  chainB_.SetBranchAddress("mus_id_AllArbitrated", &mus_id_AllArbitrated_, &b_mus_id_AllArbitrated_);
  chainB_.SetBranchAddress("mus_id_AllGlobalMuons", &mus_id_AllGlobalMuons_, &b_mus_id_AllGlobalMuons_);
  chainB_.SetBranchAddress("mus_id_AllStandAloneMuons", &mus_id_AllStandAloneMuons_, &b_mus_id_AllStandAloneMuons_);
  chainB_.SetBranchAddress("mus_id_AllTrackerMuons", &mus_id_AllTrackerMuons_, &b_mus_id_AllTrackerMuons_);
  chainB_.SetBranchAddress("mus_id_GlobalMuonPromptTight", &mus_id_GlobalMuonPromptTight_, &b_mus_id_GlobalMuonPromptTight_);
  chainB_.SetBranchAddress("mus_id_TM2DCompatibilityLoose", &mus_id_TM2DCompatibilityLoose_, &b_mus_id_TM2DCompatibilityLoose_);
  chainB_.SetBranchAddress("mus_id_TM2DCompatibilityTight", &mus_id_TM2DCompatibilityTight_, &b_mus_id_TM2DCompatibilityTight_);
  chainB_.SetBranchAddress("mus_id_TMLastStationLoose", &mus_id_TMLastStationLoose_, &b_mus_id_TMLastStationLoose_);
  chainB_.SetBranchAddress("mus_id_TMLastStationOptimizedLowPtLoose", &mus_id_TMLastStationOptimizedLowPtLoose_, &b_mus_id_TMLastStationOptimizedLowPtLoose_);
  chainB_.SetBranchAddress("mus_id_TMLastStationOptimizedLowPtTight", &mus_id_TMLastStationOptimizedLowPtTight_, &b_mus_id_TMLastStationOptimizedLowPtTight_);
  chainB_.SetBranchAddress("mus_id_TMLastStationTight", &mus_id_TMLastStationTight_, &b_mus_id_TMLastStationTight_);
  chainB_.SetBranchAddress("mus_id_TMOneStationLoose", &mus_id_TMOneStationLoose_, &b_mus_id_TMOneStationLoose_);
  chainB_.SetBranchAddress("mus_id_TMOneStationTight", &mus_id_TMOneStationTight_, &b_mus_id_TMOneStationTight_);
  chainB_.SetBranchAddress("mus_id_TrackerMuonArbitrated", &mus_id_TrackerMuonArbitrated_, &b_mus_id_TrackerMuonArbitrated_);
  chainB_.SetBranchAddress("mus_isCaloMuon", &mus_isCaloMuon_, &b_mus_isCaloMuon_);
  chainB_.SetBranchAddress("mus_isConvertedPhoton", &mus_isConvertedPhoton_, &b_mus_isConvertedPhoton_);
  chainB_.SetBranchAddress("mus_isElectron", &mus_isElectron_, &b_mus_isElectron_);
  chainB_.SetBranchAddress("mus_isGlobalMuon", &mus_isGlobalMuon_, &b_mus_isGlobalMuon_);
  chainB_.SetBranchAddress("mus_isPFMuon", &mus_isPFMuon_, &b_mus_isPFMuon_);
  chainB_.SetBranchAddress("mus_isPhoton", &mus_isPhoton_, &b_mus_isPhoton_);
  chainB_.SetBranchAddress("mus_isStandAloneMuon", &mus_isStandAloneMuon_, &b_mus_isStandAloneMuon_);
  chainB_.SetBranchAddress("mus_isTrackerMuon", &mus_isTrackerMuon_, &b_mus_isTrackerMuon_);
  chainB_.SetBranchAddress("mus_iso03_emEt", &mus_iso03_emEt_, &b_mus_iso03_emEt_);
  chainB_.SetBranchAddress("mus_iso03_emVetoEt", &mus_iso03_emVetoEt_, &b_mus_iso03_emVetoEt_);
  chainB_.SetBranchAddress("mus_iso03_hadEt", &mus_iso03_hadEt_, &b_mus_iso03_hadEt_);
  chainB_.SetBranchAddress("mus_iso03_hadVetoEt", &mus_iso03_hadVetoEt_, &b_mus_iso03_hadVetoEt_);
  chainB_.SetBranchAddress("mus_iso03_hoEt", &mus_iso03_hoEt_, &b_mus_iso03_hoEt_);
  chainB_.SetBranchAddress("mus_iso03_nTracks", &mus_iso03_nTracks_, &b_mus_iso03_nTracks_);
  chainB_.SetBranchAddress("mus_iso03_sumPt", &mus_iso03_sumPt_, &b_mus_iso03_sumPt_);
  chainB_.SetBranchAddress("mus_iso05_emEt", &mus_iso05_emEt_, &b_mus_iso05_emEt_);
  chainB_.SetBranchAddress("mus_iso05_hadEt", &mus_iso05_hadEt_, &b_mus_iso05_hadEt_);
  chainB_.SetBranchAddress("mus_iso05_hoEt", &mus_iso05_hoEt_, &b_mus_iso05_hoEt_);
  chainB_.SetBranchAddress("mus_iso05_nTracks", &mus_iso05_nTracks_, &b_mus_iso05_nTracks_);
  chainB_.SetBranchAddress("mus_iso05_sumPt", &mus_iso05_sumPt_, &b_mus_iso05_sumPt_);
  chainB_.SetBranchAddress("mus_num_matches", &mus_num_matches_, &b_mus_num_matches_);
  chainB_.SetBranchAddress("mus_numberOfMatchedStations", &mus_numberOfMatchedStations_, &b_mus_numberOfMatchedStations_);
  chainB_.SetBranchAddress("mus_pfIsolationR03_sumChargedHadronPt", &mus_pfIsolationR03_sumChargedHadronPt_, &b_mus_pfIsolationR03_sumChargedHadronPt_);
  chainB_.SetBranchAddress("mus_pfIsolationR03_sumChargedParticlePt", &mus_pfIsolationR03_sumChargedParticlePt_, &b_mus_pfIsolationR03_sumChargedParticlePt_);
  chainB_.SetBranchAddress("mus_pfIsolationR03_sumNeutralHadronEt", &mus_pfIsolationR03_sumNeutralHadronEt_, &b_mus_pfIsolationR03_sumNeutralHadronEt_);
  chainB_.SetBranchAddress("mus_pfIsolationR03_sumNeutralHadronEtHighThreshold", &mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_, &b_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_);
  chainB_.SetBranchAddress("mus_pfIsolationR03_sumPUPt", &mus_pfIsolationR03_sumPUPt_, &b_mus_pfIsolationR03_sumPUPt_);
  chainB_.SetBranchAddress("mus_pfIsolationR03_sumPhotonEt", &mus_pfIsolationR03_sumPhotonEt_, &b_mus_pfIsolationR03_sumPhotonEt_);
  chainB_.SetBranchAddress("mus_pfIsolationR03_sumPhotonEtHighThreshold", &mus_pfIsolationR03_sumPhotonEtHighThreshold_, &b_mus_pfIsolationR03_sumPhotonEtHighThreshold_);
  chainB_.SetBranchAddress("mus_pfIsolationR04_sumChargedHadronPt", &mus_pfIsolationR04_sumChargedHadronPt_, &b_mus_pfIsolationR04_sumChargedHadronPt_);
  chainB_.SetBranchAddress("mus_pfIsolationR04_sumChargedParticlePt", &mus_pfIsolationR04_sumChargedParticlePt_, &b_mus_pfIsolationR04_sumChargedParticlePt_);
  chainB_.SetBranchAddress("mus_pfIsolationR04_sumNeutralHadronEt", &mus_pfIsolationR04_sumNeutralHadronEt_, &b_mus_pfIsolationR04_sumNeutralHadronEt_);
  chainB_.SetBranchAddress("mus_pfIsolationR04_sumNeutralHadronEtHighThreshold", &mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_, &b_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_);
  chainB_.SetBranchAddress("mus_pfIsolationR04_sumPUPt", &mus_pfIsolationR04_sumPUPt_, &b_mus_pfIsolationR04_sumPUPt_);
  chainB_.SetBranchAddress("mus_pfIsolationR04_sumPhotonEt", &mus_pfIsolationR04_sumPhotonEt_, &b_mus_pfIsolationR04_sumPhotonEt_);
  chainB_.SetBranchAddress("mus_pfIsolationR04_sumPhotonEtHighThreshold", &mus_pfIsolationR04_sumPhotonEtHighThreshold_, &b_mus_pfIsolationR04_sumPhotonEtHighThreshold_);
  chainB_.SetBranchAddress("mus_phi", &mus_phi_, &b_mus_phi_);
  chainB_.SetBranchAddress("mus_picky_ExpectedHitsInner", &mus_picky_ExpectedHitsInner_, &b_mus_picky_ExpectedHitsInner_);
  chainB_.SetBranchAddress("mus_picky_ExpectedHitsOuter", &mus_picky_ExpectedHitsOuter_, &b_mus_picky_ExpectedHitsOuter_);
  chainB_.SetBranchAddress("mus_picky_LayersWithMeasurement", &mus_picky_LayersWithMeasurement_, &b_mus_picky_LayersWithMeasurement_);
  chainB_.SetBranchAddress("mus_picky_LayersWithoutMeasurement", &mus_picky_LayersWithoutMeasurement_, &b_mus_picky_LayersWithoutMeasurement_);
  chainB_.SetBranchAddress("mus_picky_PixelLayersWithMeasurement", &mus_picky_PixelLayersWithMeasurement_, &b_mus_picky_PixelLayersWithMeasurement_);
  chainB_.SetBranchAddress("mus_picky_ValidStripLayersWithMonoAndStereoHit", &mus_picky_ValidStripLayersWithMonoAndStereoHit_, &b_mus_picky_ValidStripLayersWithMonoAndStereoHit_);
  chainB_.SetBranchAddress("mus_picky_chg", &mus_picky_chg_, &b_mus_picky_chg_);
  chainB_.SetBranchAddress("mus_picky_chi2", &mus_picky_chi2_, &b_mus_picky_chi2_);
  chainB_.SetBranchAddress("mus_picky_d0dum", &mus_picky_d0dum_, &b_mus_picky_d0dum_);
  chainB_.SetBranchAddress("mus_picky_d0dumErr", &mus_picky_d0dumErr_, &b_mus_picky_d0dumErr_);
  chainB_.SetBranchAddress("mus_picky_dz", &mus_picky_dz_, &b_mus_picky_dz_);
  chainB_.SetBranchAddress("mus_picky_dzErr", &mus_picky_dzErr_, &b_mus_picky_dzErr_);
  chainB_.SetBranchAddress("mus_picky_eta", &mus_picky_eta_, &b_mus_picky_eta_);
  chainB_.SetBranchAddress("mus_picky_etaErr", &mus_picky_etaErr_, &b_mus_picky_etaErr_);
  chainB_.SetBranchAddress("mus_picky_id", &mus_picky_id_, &b_mus_picky_id_);
  chainB_.SetBranchAddress("mus_picky_ndof", &mus_picky_ndof_, &b_mus_picky_ndof_);
  chainB_.SetBranchAddress("mus_picky_numlosthits", &mus_picky_numlosthits_, &b_mus_picky_numlosthits_);
  chainB_.SetBranchAddress("mus_picky_numvalPixelhits", &mus_picky_numvalPixelhits_, &b_mus_picky_numvalPixelhits_);
  chainB_.SetBranchAddress("mus_picky_numvalhits", &mus_picky_numvalhits_, &b_mus_picky_numvalhits_);
  chainB_.SetBranchAddress("mus_picky_phi", &mus_picky_phi_, &b_mus_picky_phi_);
  chainB_.SetBranchAddress("mus_picky_phiErr", &mus_picky_phiErr_, &b_mus_picky_phiErr_);
  chainB_.SetBranchAddress("mus_picky_pt", &mus_picky_pt_, &b_mus_picky_pt_);
  chainB_.SetBranchAddress("mus_picky_ptErr", &mus_picky_ptErr_, &b_mus_picky_ptErr_);
  chainB_.SetBranchAddress("mus_picky_px", &mus_picky_px_, &b_mus_picky_px_);
  chainB_.SetBranchAddress("mus_picky_py", &mus_picky_py_, &b_mus_picky_py_);
  chainB_.SetBranchAddress("mus_picky_pz", &mus_picky_pz_, &b_mus_picky_pz_);
  chainB_.SetBranchAddress("mus_picky_theta", &mus_picky_theta_, &b_mus_picky_theta_);
  chainB_.SetBranchAddress("mus_picky_vx", &mus_picky_vx_, &b_mus_picky_vx_);
  chainB_.SetBranchAddress("mus_picky_vy", &mus_picky_vy_, &b_mus_picky_vy_);
  chainB_.SetBranchAddress("mus_picky_vz", &mus_picky_vz_, &b_mus_picky_vz_);
  chainB_.SetBranchAddress("mus_pt", &mus_pt_, &b_mus_pt_);
  chainB_.SetBranchAddress("mus_px", &mus_px_, &b_mus_px_);
  chainB_.SetBranchAddress("mus_py", &mus_py_, &b_mus_py_);
  chainB_.SetBranchAddress("mus_pz", &mus_pz_, &b_mus_pz_);
  chainB_.SetBranchAddress("mus_stamu_chg", &mus_stamu_chg_, &b_mus_stamu_chg_);
  chainB_.SetBranchAddress("mus_stamu_chi2", &mus_stamu_chi2_, &b_mus_stamu_chi2_);
  chainB_.SetBranchAddress("mus_stamu_d0dum", &mus_stamu_d0dum_, &b_mus_stamu_d0dum_);
  chainB_.SetBranchAddress("mus_stamu_d0dumErr", &mus_stamu_d0dumErr_, &b_mus_stamu_d0dumErr_);
  chainB_.SetBranchAddress("mus_stamu_dz", &mus_stamu_dz_, &b_mus_stamu_dz_);
  chainB_.SetBranchAddress("mus_stamu_dzErr", &mus_stamu_dzErr_, &b_mus_stamu_dzErr_);
  chainB_.SetBranchAddress("mus_stamu_eta", &mus_stamu_eta_, &b_mus_stamu_eta_);
  chainB_.SetBranchAddress("mus_stamu_etaErr", &mus_stamu_etaErr_, &b_mus_stamu_etaErr_);
  chainB_.SetBranchAddress("mus_stamu_ndof", &mus_stamu_ndof_, &b_mus_stamu_ndof_);
  chainB_.SetBranchAddress("mus_stamu_numlosthits", &mus_stamu_numlosthits_, &b_mus_stamu_numlosthits_);
  chainB_.SetBranchAddress("mus_stamu_numvalhits", &mus_stamu_numvalhits_, &b_mus_stamu_numvalhits_);
  chainB_.SetBranchAddress("mus_stamu_phi", &mus_stamu_phi_, &b_mus_stamu_phi_);
  chainB_.SetBranchAddress("mus_stamu_phiErr", &mus_stamu_phiErr_, &b_mus_stamu_phiErr_);
  chainB_.SetBranchAddress("mus_stamu_pt", &mus_stamu_pt_, &b_mus_stamu_pt_);
  chainB_.SetBranchAddress("mus_stamu_ptErr", &mus_stamu_ptErr_, &b_mus_stamu_ptErr_);
  chainB_.SetBranchAddress("mus_stamu_px", &mus_stamu_px_, &b_mus_stamu_px_);
  chainB_.SetBranchAddress("mus_stamu_py", &mus_stamu_py_, &b_mus_stamu_py_);
  chainB_.SetBranchAddress("mus_stamu_pz", &mus_stamu_pz_, &b_mus_stamu_pz_);
  chainB_.SetBranchAddress("mus_stamu_theta", &mus_stamu_theta_, &b_mus_stamu_theta_);
  chainB_.SetBranchAddress("mus_stamu_vx", &mus_stamu_vx_, &b_mus_stamu_vx_);
  chainB_.SetBranchAddress("mus_stamu_vy", &mus_stamu_vy_, &b_mus_stamu_vy_);
  chainB_.SetBranchAddress("mus_stamu_vz", &mus_stamu_vz_, &b_mus_stamu_vz_);
  chainB_.SetBranchAddress("mus_status", &mus_status_, &b_mus_status_);
  chainB_.SetBranchAddress("mus_tIso", &mus_tIso_, &b_mus_tIso_);
  chainB_.SetBranchAddress("mus_theta", &mus_theta_, &b_mus_theta_);
  chainB_.SetBranchAddress("mus_tkHits", &mus_tkHits_, &b_mus_tkHits_);
  chainB_.SetBranchAddress("mus_tk_ExpectedHitsInner", &mus_tk_ExpectedHitsInner_, &b_mus_tk_ExpectedHitsInner_);
  chainB_.SetBranchAddress("mus_tk_ExpectedHitsOuter", &mus_tk_ExpectedHitsOuter_, &b_mus_tk_ExpectedHitsOuter_);
  chainB_.SetBranchAddress("mus_tk_LayersWithMeasurement", &mus_tk_LayersWithMeasurement_, &b_mus_tk_LayersWithMeasurement_);
  chainB_.SetBranchAddress("mus_tk_LayersWithoutMeasurement", &mus_tk_LayersWithoutMeasurement_, &b_mus_tk_LayersWithoutMeasurement_);
  chainB_.SetBranchAddress("mus_tk_PixelLayersWithMeasurement", &mus_tk_PixelLayersWithMeasurement_, &b_mus_tk_PixelLayersWithMeasurement_);
  chainB_.SetBranchAddress("mus_tk_ValidStripLayersWithMonoAndStereoHit", &mus_tk_ValidStripLayersWithMonoAndStereoHit_, &b_mus_tk_ValidStripLayersWithMonoAndStereoHit_);
  chainB_.SetBranchAddress("mus_tk_chg", &mus_tk_chg_, &b_mus_tk_chg_);
  chainB_.SetBranchAddress("mus_tk_chi2", &mus_tk_chi2_, &b_mus_tk_chi2_);
  chainB_.SetBranchAddress("mus_tk_d0dum", &mus_tk_d0dum_, &b_mus_tk_d0dum_);
  chainB_.SetBranchAddress("mus_tk_d0dumErr", &mus_tk_d0dumErr_, &b_mus_tk_d0dumErr_);
  chainB_.SetBranchAddress("mus_tk_dz", &mus_tk_dz_, &b_mus_tk_dz_);
  chainB_.SetBranchAddress("mus_tk_dzErr", &mus_tk_dzErr_, &b_mus_tk_dzErr_);
  chainB_.SetBranchAddress("mus_tk_eta", &mus_tk_eta_, &b_mus_tk_eta_);
  chainB_.SetBranchAddress("mus_tk_etaErr", &mus_tk_etaErr_, &b_mus_tk_etaErr_);
  chainB_.SetBranchAddress("mus_tk_id", &mus_tk_id_, &b_mus_tk_id_);
  chainB_.SetBranchAddress("mus_tk_ndof", &mus_tk_ndof_, &b_mus_tk_ndof_);
  chainB_.SetBranchAddress("mus_tk_numlosthits", &mus_tk_numlosthits_, &b_mus_tk_numlosthits_);
  chainB_.SetBranchAddress("mus_tk_numpixelWthMeasr", &mus_tk_numpixelWthMeasr_, &b_mus_tk_numpixelWthMeasr_);
  chainB_.SetBranchAddress("mus_tk_numvalPixelhits", &mus_tk_numvalPixelhits_, &b_mus_tk_numvalPixelhits_);
  chainB_.SetBranchAddress("mus_tk_numvalhits", &mus_tk_numvalhits_, &b_mus_tk_numvalhits_);
  chainB_.SetBranchAddress("mus_tk_phi", &mus_tk_phi_, &b_mus_tk_phi_);
  chainB_.SetBranchAddress("mus_tk_phiErr", &mus_tk_phiErr_, &b_mus_tk_phiErr_);
  chainB_.SetBranchAddress("mus_tk_pt", &mus_tk_pt_, &b_mus_tk_pt_);
  chainB_.SetBranchAddress("mus_tk_ptErr", &mus_tk_ptErr_, &b_mus_tk_ptErr_);
  chainB_.SetBranchAddress("mus_tk_px", &mus_tk_px_, &b_mus_tk_px_);
  chainB_.SetBranchAddress("mus_tk_py", &mus_tk_py_, &b_mus_tk_py_);
  chainB_.SetBranchAddress("mus_tk_pz", &mus_tk_pz_, &b_mus_tk_pz_);
  chainB_.SetBranchAddress("mus_tk_theta", &mus_tk_theta_, &b_mus_tk_theta_);
  chainB_.SetBranchAddress("mus_tk_vx", &mus_tk_vx_, &b_mus_tk_vx_);
  chainB_.SetBranchAddress("mus_tk_vy", &mus_tk_vy_, &b_mus_tk_vy_);
  chainB_.SetBranchAddress("mus_tk_vz", &mus_tk_vz_, &b_mus_tk_vz_);
  chainB_.SetBranchAddress("mus_tpfms_ExpectedHitsInner", &mus_tpfms_ExpectedHitsInner_, &b_mus_tpfms_ExpectedHitsInner_);
  chainB_.SetBranchAddress("mus_tpfms_ExpectedHitsOuter", &mus_tpfms_ExpectedHitsOuter_, &b_mus_tpfms_ExpectedHitsOuter_);
  chainB_.SetBranchAddress("mus_tpfms_LayersWithMeasurement", &mus_tpfms_LayersWithMeasurement_, &b_mus_tpfms_LayersWithMeasurement_);
  chainB_.SetBranchAddress("mus_tpfms_LayersWithoutMeasurement", &mus_tpfms_LayersWithoutMeasurement_, &b_mus_tpfms_LayersWithoutMeasurement_);
  chainB_.SetBranchAddress("mus_tpfms_PixelLayersWithMeasurement", &mus_tpfms_PixelLayersWithMeasurement_, &b_mus_tpfms_PixelLayersWithMeasurement_);
  chainB_.SetBranchAddress("mus_tpfms_ValidStripLayersWithMonoAndStereoHit", &mus_tpfms_ValidStripLayersWithMonoAndStereoHit_, &b_mus_tpfms_ValidStripLayersWithMonoAndStereoHit_);
  chainB_.SetBranchAddress("mus_tpfms_chg", &mus_tpfms_chg_, &b_mus_tpfms_chg_);
  chainB_.SetBranchAddress("mus_tpfms_chi2", &mus_tpfms_chi2_, &b_mus_tpfms_chi2_);
  chainB_.SetBranchAddress("mus_tpfms_d0dum", &mus_tpfms_d0dum_, &b_mus_tpfms_d0dum_);
  chainB_.SetBranchAddress("mus_tpfms_d0dumErr", &mus_tpfms_d0dumErr_, &b_mus_tpfms_d0dumErr_);
  chainB_.SetBranchAddress("mus_tpfms_dz", &mus_tpfms_dz_, &b_mus_tpfms_dz_);
  chainB_.SetBranchAddress("mus_tpfms_dzErr", &mus_tpfms_dzErr_, &b_mus_tpfms_dzErr_);
  chainB_.SetBranchAddress("mus_tpfms_eta", &mus_tpfms_eta_, &b_mus_tpfms_eta_);
  chainB_.SetBranchAddress("mus_tpfms_etaErr", &mus_tpfms_etaErr_, &b_mus_tpfms_etaErr_);
  chainB_.SetBranchAddress("mus_tpfms_id", &mus_tpfms_id_, &b_mus_tpfms_id_);
  chainB_.SetBranchAddress("mus_tpfms_ndof", &mus_tpfms_ndof_, &b_mus_tpfms_ndof_);
  chainB_.SetBranchAddress("mus_tpfms_numlosthits", &mus_tpfms_numlosthits_, &b_mus_tpfms_numlosthits_);
  chainB_.SetBranchAddress("mus_tpfms_numvalPixelhits", &mus_tpfms_numvalPixelhits_, &b_mus_tpfms_numvalPixelhits_);
  chainB_.SetBranchAddress("mus_tpfms_numvalhits", &mus_tpfms_numvalhits_, &b_mus_tpfms_numvalhits_);
  chainB_.SetBranchAddress("mus_tpfms_phi", &mus_tpfms_phi_, &b_mus_tpfms_phi_);
  chainB_.SetBranchAddress("mus_tpfms_phiErr", &mus_tpfms_phiErr_, &b_mus_tpfms_phiErr_);
  chainB_.SetBranchAddress("mus_tpfms_pt", &mus_tpfms_pt_, &b_mus_tpfms_pt_);
  chainB_.SetBranchAddress("mus_tpfms_ptErr", &mus_tpfms_ptErr_, &b_mus_tpfms_ptErr_);
  chainB_.SetBranchAddress("mus_tpfms_px", &mus_tpfms_px_, &b_mus_tpfms_px_);
  chainB_.SetBranchAddress("mus_tpfms_py", &mus_tpfms_py_, &b_mus_tpfms_py_);
  chainB_.SetBranchAddress("mus_tpfms_pz", &mus_tpfms_pz_, &b_mus_tpfms_pz_);
  chainB_.SetBranchAddress("mus_tpfms_theta", &mus_tpfms_theta_, &b_mus_tpfms_theta_);
  chainB_.SetBranchAddress("mus_tpfms_vx", &mus_tpfms_vx_, &b_mus_tpfms_vx_);
  chainB_.SetBranchAddress("mus_tpfms_vy", &mus_tpfms_vy_, &b_mus_tpfms_vy_);
  chainB_.SetBranchAddress("mus_tpfms_vz", &mus_tpfms_vz_, &b_mus_tpfms_vz_);
  chainB_.SetBranchAddress("orbitNumber", &orbitNumber_, &b_orbitNumber_);
  chainB_.SetBranchAddress("pfcand_charge", &pfcand_charge_, &b_pfcand_charge_);
  chainB_.SetBranchAddress("pfcand_energy", &pfcand_energy_, &b_pfcand_energy_);
  chainB_.SetBranchAddress("pfcand_eta", &pfcand_eta_, &b_pfcand_eta_);
  chainB_.SetBranchAddress("pfcand_pdgId", &pfcand_pdgId_, &b_pfcand_pdgId_);
  chainB_.SetBranchAddress("pfcand_phi", &pfcand_phi_, &b_pfcand_phi_);
  chainB_.SetBranchAddress("pfcand_pt", &pfcand_pt_, &b_pfcand_pt_);
  chainB_.SetBranchAddress("pfcand_px", &pfcand_px_, &b_pfcand_px_);
  chainB_.SetBranchAddress("pfcand_py", &pfcand_py_, &b_pfcand_py_);
  chainB_.SetBranchAddress("pfcand_pz", &pfcand_pz_, &b_pfcand_pz_);
  chainB_.SetBranchAddress("pfcand_theta", &pfcand_theta_, &b_pfcand_theta_);
  chainB_.SetBranchAddress("photons_e1x5", &photons_e1x5_, &b_photons_e1x5_);
  chainB_.SetBranchAddress("photons_e2x5", &photons_e2x5_, &b_photons_e2x5_);
  chainB_.SetBranchAddress("photons_e3x3", &photons_e3x3_, &b_photons_e3x3_);
  chainB_.SetBranchAddress("photons_e5x5", &photons_e5x5_, &b_photons_e5x5_);
  chainB_.SetBranchAddress("photons_ecalIso", &photons_ecalIso_, &b_photons_ecalIso_);
  chainB_.SetBranchAddress("photons_energy", &photons_energy_, &b_photons_energy_);
  chainB_.SetBranchAddress("photons_et", &photons_et_, &b_photons_et_);
  chainB_.SetBranchAddress("photons_eta", &photons_eta_, &b_photons_eta_);
  chainB_.SetBranchAddress("photons_gen_et", &photons_gen_et_, &b_photons_gen_et_);
  chainB_.SetBranchAddress("photons_gen_eta", &photons_gen_eta_, &b_photons_gen_eta_);
  chainB_.SetBranchAddress("photons_gen_id", &photons_gen_id_, &b_photons_gen_id_);
  chainB_.SetBranchAddress("photons_gen_phi", &photons_gen_phi_, &b_photons_gen_phi_);
  chainB_.SetBranchAddress("photons_hadOverEM", &photons_hadOverEM_, &b_photons_hadOverEM_);
  chainB_.SetBranchAddress("photons_hadTowOverEM", &photons_hadTowOverEM_, &b_photons_hadTowOverEM_);
  chainB_.SetBranchAddress("photons_hasPixelSeed", &photons_hasPixelSeed_, &b_photons_hasPixelSeed_);
  chainB_.SetBranchAddress("photons_hcalIso", &photons_hcalIso_, &b_photons_hcalIso_);
  chainB_.SetBranchAddress("photons_isAlsoElectron", &photons_isAlsoElectron_, &b_photons_isAlsoElectron_);
  chainB_.SetBranchAddress("photons_isConverted", &photons_isConverted_, &b_photons_isConverted_);
  chainB_.SetBranchAddress("photons_isEBEEGap", &photons_isEBEEGap_, &b_photons_isEBEEGap_);
  chainB_.SetBranchAddress("photons_isEBGap", &photons_isEBGap_, &b_photons_isEBGap_);
  chainB_.SetBranchAddress("photons_isEBPho", &photons_isEBPho_, &b_photons_isEBPho_);
  chainB_.SetBranchAddress("photons_isEEGap", &photons_isEEGap_, &b_photons_isEEGap_);
  chainB_.SetBranchAddress("photons_isEEPho", &photons_isEEPho_, &b_photons_isEEPho_);
  chainB_.SetBranchAddress("photons_isLoosePhoton", &photons_isLoosePhoton_, &b_photons_isLoosePhoton_);
  chainB_.SetBranchAddress("photons_isTightPhoton", &photons_isTightPhoton_, &b_photons_isTightPhoton_);
  chainB_.SetBranchAddress("photons_isoEcalRecHitDR03", &photons_isoEcalRecHitDR03_, &b_photons_isoEcalRecHitDR03_);
  chainB_.SetBranchAddress("photons_isoEcalRecHitDR04", &photons_isoEcalRecHitDR04_, &b_photons_isoEcalRecHitDR04_);
  chainB_.SetBranchAddress("photons_isoHcalRecHitDR03", &photons_isoHcalRecHitDR03_, &b_photons_isoHcalRecHitDR03_);
  chainB_.SetBranchAddress("photons_isoHcalRecHitDR04", &photons_isoHcalRecHitDR04_, &b_photons_isoHcalRecHitDR04_);
  chainB_.SetBranchAddress("photons_isoHollowTrkConeDR03", &photons_isoHollowTrkConeDR03_, &b_photons_isoHollowTrkConeDR03_);
  chainB_.SetBranchAddress("photons_isoHollowTrkConeDR04", &photons_isoHollowTrkConeDR04_, &b_photons_isoHollowTrkConeDR04_);
  chainB_.SetBranchAddress("photons_isoSolidTrkConeDR03", &photons_isoSolidTrkConeDR03_, &b_photons_isoSolidTrkConeDR03_);
  chainB_.SetBranchAddress("photons_isoSolidTrkConeDR04", &photons_isoSolidTrkConeDR04_, &b_photons_isoSolidTrkConeDR04_);
  chainB_.SetBranchAddress("photons_maxEnergyXtal", &photons_maxEnergyXtal_, &b_photons_maxEnergyXtal_);
  chainB_.SetBranchAddress("photons_nTrkHollowConeDR03", &photons_nTrkHollowConeDR03_, &b_photons_nTrkHollowConeDR03_);
  chainB_.SetBranchAddress("photons_nTrkHollowConeDR04", &photons_nTrkHollowConeDR04_, &b_photons_nTrkHollowConeDR04_);
  chainB_.SetBranchAddress("photons_nTrkSolidConeDR03", &photons_nTrkSolidConeDR03_, &b_photons_nTrkSolidConeDR03_);
  chainB_.SetBranchAddress("photons_nTrkSolidConeDR04", &photons_nTrkSolidConeDR04_, &b_photons_nTrkSolidConeDR04_);
  chainB_.SetBranchAddress("photons_phi", &photons_phi_, &b_photons_phi_);
  chainB_.SetBranchAddress("photons_pt", &photons_pt_, &b_photons_pt_);
  chainB_.SetBranchAddress("photons_px", &photons_px_, &b_photons_px_);
  chainB_.SetBranchAddress("photons_py", &photons_py_, &b_photons_py_);
  chainB_.SetBranchAddress("photons_pz", &photons_pz_, &b_photons_pz_);
  chainB_.SetBranchAddress("photons_r9", &photons_r9_, &b_photons_r9_);
  chainB_.SetBranchAddress("photons_scEnergy", &photons_scEnergy_, &b_photons_scEnergy_);
  chainB_.SetBranchAddress("photons_scEta", &photons_scEta_, &b_photons_scEta_);
  chainB_.SetBranchAddress("photons_scEtaWidth", &photons_scEtaWidth_, &b_photons_scEtaWidth_);
  chainB_.SetBranchAddress("photons_scPhi", &photons_scPhi_, &b_photons_scPhi_);
  chainB_.SetBranchAddress("photons_scPhiWidth", &photons_scPhiWidth_, &b_photons_scPhiWidth_);
  chainB_.SetBranchAddress("photons_scRawEnergy", &photons_scRawEnergy_, &b_photons_scRawEnergy_);
  chainB_.SetBranchAddress("photons_sigmaEtaEta", &photons_sigmaEtaEta_, &b_photons_sigmaEtaEta_);
  chainB_.SetBranchAddress("photons_sigmaIetaIeta", &photons_sigmaIetaIeta_, &b_photons_sigmaIetaIeta_);
  chainB_.SetBranchAddress("photons_status", &photons_status_, &b_photons_status_);
  chainB_.SetBranchAddress("photons_tIso", &photons_tIso_, &b_photons_tIso_);
  chainB_.SetBranchAddress("photons_theta", &photons_theta_, &b_photons_theta_);
  chainB_.SetBranchAddress("pv_chi2", &pv_chi2_, &b_pv_chi2_);
  chainB_.SetBranchAddress("pv_isFake", &pv_isFake_, &b_pv_isFake_);
  chainB_.SetBranchAddress("pv_isValid", &pv_isValid_, &b_pv_isValid_);
  chainB_.SetBranchAddress("pv_ndof", &pv_ndof_, &b_pv_ndof_);
  chainB_.SetBranchAddress("pv_tracksSize", &pv_tracksSize_, &b_pv_tracksSize_);
  chainB_.SetBranchAddress("pv_x", &pv_x_, &b_pv_x_);
  chainB_.SetBranchAddress("pv_xErr", &pv_xErr_, &b_pv_xErr_);
  chainB_.SetBranchAddress("pv_y", &pv_y_, &b_pv_y_);
  chainB_.SetBranchAddress("pv_yErr", &pv_yErr_, &b_pv_yErr_);
  chainB_.SetBranchAddress("pv_z", &pv_z_, &b_pv_z_);
  chainB_.SetBranchAddress("pv_zErr", &pv_zErr_, &b_pv_zErr_);
  chainB_.SetBranchAddress("run", &run_, &b_run_);
  chainB_.SetBranchAddress("taus_Nprongs", &taus_Nprongs_, &b_taus_Nprongs_);
  chainB_.SetBranchAddress("taus_againstElectron", &taus_againstElectron_, &b_taus_againstElectron_);
  chainB_.SetBranchAddress("taus_againstElectronLoose", &taus_againstElectronLoose_, &b_taus_againstElectronLoose_);
  chainB_.SetBranchAddress("taus_againstElectronMVA", &taus_againstElectronMVA_, &b_taus_againstElectronMVA_);
  chainB_.SetBranchAddress("taus_againstElectronMedium", &taus_againstElectronMedium_, &b_taus_againstElectronMedium_);
  chainB_.SetBranchAddress("taus_againstElectronTight", &taus_againstElectronTight_, &b_taus_againstElectronTight_);
  chainB_.SetBranchAddress("taus_againstMuon", &taus_againstMuon_, &b_taus_againstMuon_);
  chainB_.SetBranchAddress("taus_againstMuonLoose", &taus_againstMuonLoose_, &b_taus_againstMuonLoose_);
  chainB_.SetBranchAddress("taus_againstMuonMedium", &taus_againstMuonMedium_, &b_taus_againstMuonMedium_);
  chainB_.SetBranchAddress("taus_againstMuonTight", &taus_againstMuonTight_, &b_taus_againstMuonTight_);
  chainB_.SetBranchAddress("taus_byIsoUsingLeadingPi", &taus_byIsoUsingLeadingPi_, &b_taus_byIsoUsingLeadingPi_);
  chainB_.SetBranchAddress("taus_byIsolation", &taus_byIsolation_, &b_taus_byIsolation_);
  chainB_.SetBranchAddress("taus_byLooseIsolation", &taus_byLooseIsolation_, &b_taus_byLooseIsolation_);
  chainB_.SetBranchAddress("taus_byLooseIsolationDeltaBetaCorr", &taus_byLooseIsolationDeltaBetaCorr_, &b_taus_byLooseIsolationDeltaBetaCorr_);
  chainB_.SetBranchAddress("taus_byMediumIsolation", &taus_byMediumIsolation_, &b_taus_byMediumIsolation_);
  chainB_.SetBranchAddress("taus_byMediumIsolationDeltaBetaCorr", &taus_byMediumIsolationDeltaBetaCorr_, &b_taus_byMediumIsolationDeltaBetaCorr_);
  chainB_.SetBranchAddress("taus_byTightIsolation", &taus_byTightIsolation_, &b_taus_byTightIsolation_);
  chainB_.SetBranchAddress("taus_byTightIsolationDeltaBetaCorr", &taus_byTightIsolationDeltaBetaCorr_, &b_taus_byTightIsolationDeltaBetaCorr_);
  chainB_.SetBranchAddress("taus_byVLooseIsolation", &taus_byVLooseIsolation_, &b_taus_byVLooseIsolation_);
  chainB_.SetBranchAddress("taus_byVLooseIsolationDeltaBetaCorr", &taus_byVLooseIsolationDeltaBetaCorr_, &b_taus_byVLooseIsolationDeltaBetaCorr_);
  chainB_.SetBranchAddress("taus_charge", &taus_charge_, &b_taus_charge_);
  chainB_.SetBranchAddress("taus_decayModeFinding", &taus_decayModeFinding_, &b_taus_decayModeFinding_);
  chainB_.SetBranchAddress("taus_ecalIsoUsingLeadingPi", &taus_ecalIsoUsingLeadingPi_, &b_taus_ecalIsoUsingLeadingPi_);
  chainB_.SetBranchAddress("taus_ecalIsolation", &taus_ecalIsolation_, &b_taus_ecalIsolation_);
  chainB_.SetBranchAddress("taus_ecalStripSumEOverPLead", &taus_ecalStripSumEOverPLead_, &b_taus_ecalStripSumEOverPLead_);
  chainB_.SetBranchAddress("taus_elecPreIdDecision", &taus_elecPreIdDecision_, &b_taus_elecPreIdDecision_);
  chainB_.SetBranchAddress("taus_elecPreIdOutput", &taus_elecPreIdOutput_, &b_taus_elecPreIdOutput_);
  chainB_.SetBranchAddress("taus_emf", &taus_emf_, &b_taus_emf_);
  chainB_.SetBranchAddress("taus_energy", &taus_energy_, &b_taus_energy_);
  chainB_.SetBranchAddress("taus_et", &taus_et_, &b_taus_et_);
  chainB_.SetBranchAddress("taus_eta", &taus_eta_, &b_taus_eta_);
  chainB_.SetBranchAddress("taus_hcal3x3OverPLead", &taus_hcal3x3OverPLead_, &b_taus_hcal3x3OverPLead_);
  chainB_.SetBranchAddress("taus_hcalMaxOverPLead", &taus_hcalMaxOverPLead_, &b_taus_hcalMaxOverPLead_);
  chainB_.SetBranchAddress("taus_hcalTotOverPLead", &taus_hcalTotOverPLead_, &b_taus_hcalTotOverPLead_);
  chainB_.SetBranchAddress("taus_isoPFChargedHadrCandsPtSum", &taus_isoPFChargedHadrCandsPtSum_, &b_taus_isoPFChargedHadrCandsPtSum_);
  chainB_.SetBranchAddress("taus_isoPFGammaCandsEtSum", &taus_isoPFGammaCandsEtSum_, &b_taus_isoPFGammaCandsEtSum_);
  chainB_.SetBranchAddress("taus_leadPFChargedHadrCand_ECAL_eta", &taus_leadPFChargedHadrCand_ECAL_eta_, &b_taus_leadPFChargedHadrCand_ECAL_eta_);
  chainB_.SetBranchAddress("taus_leadPFChargedHadrCand_charge", &taus_leadPFChargedHadrCand_charge_, &b_taus_leadPFChargedHadrCand_charge_);
  chainB_.SetBranchAddress("taus_leadPFChargedHadrCand_eta", &taus_leadPFChargedHadrCand_eta_, &b_taus_leadPFChargedHadrCand_eta_);
  chainB_.SetBranchAddress("taus_leadPFChargedHadrCand_phi", &taus_leadPFChargedHadrCand_phi_, &b_taus_leadPFChargedHadrCand_phi_);
  chainB_.SetBranchAddress("taus_leadPFChargedHadrCand_pt", &taus_leadPFChargedHadrCand_pt_, &b_taus_leadPFChargedHadrCand_pt_);
  chainB_.SetBranchAddress("taus_leadingTrackFinding", &taus_leadingTrackFinding_, &b_taus_leadingTrackFinding_);
  chainB_.SetBranchAddress("taus_leadingTrackPtCut", &taus_leadingTrackPtCut_, &b_taus_leadingTrackPtCut_);
  chainB_.SetBranchAddress("taus_muDecision", &taus_muDecision_, &b_taus_muDecision_);
  chainB_.SetBranchAddress("taus_phi", &taus_phi_, &b_taus_phi_);
  chainB_.SetBranchAddress("taus_pt", &taus_pt_, &b_taus_pt_);
  chainB_.SetBranchAddress("taus_px", &taus_px_, &b_taus_px_);
  chainB_.SetBranchAddress("taus_py", &taus_py_, &b_taus_py_);
  chainB_.SetBranchAddress("taus_pz", &taus_pz_, &b_taus_pz_);
  chainB_.SetBranchAddress("taus_signalPFChargedHadrCandsSize", &taus_signalPFChargedHadrCandsSize_, &b_taus_signalPFChargedHadrCandsSize_);
  chainB_.SetBranchAddress("taus_status", &taus_status_, &b_taus_status_);
  chainB_.SetBranchAddress("taus_taNC", &taus_taNC_, &b_taus_taNC_);
  chainB_.SetBranchAddress("taus_taNC_half", &taus_taNC_half_, &b_taus_taNC_half_);
  chainB_.SetBranchAddress("taus_taNC_one", &taus_taNC_one_, &b_taus_taNC_one_);
  chainB_.SetBranchAddress("taus_taNC_quarter", &taus_taNC_quarter_, &b_taus_taNC_quarter_);
  chainB_.SetBranchAddress("taus_taNC_tenth", &taus_taNC_tenth_, &b_taus_taNC_tenth_);
  chainB_.SetBranchAddress("taus_theta", &taus_theta_, &b_taus_theta_);
  chainB_.SetBranchAddress("taus_tkIsoUsingLeadingPi", &taus_tkIsoUsingLeadingPi_, &b_taus_tkIsoUsingLeadingPi_);
  chainB_.SetBranchAddress("taus_trackIsolation", &taus_trackIsolation_, &b_taus_trackIsolation_);
  chainB_.SetBranchAddress("weight", &weight_, &b_weight_);
}

UInt_t const & cfa_base::NbeamSpot() const{
  if(!c_NbeamSpot_ && b_NbeamSpot_){
    b_NbeamSpot_->SetStatus(true);
    chainB_.SetBranchAddress("NbeamSpot", &NbeamSpot_, &b_NbeamSpot_);
    b_NbeamSpot_->GetEntry(entry_);
    c_NbeamSpot_ = true;
  }
  return NbeamSpot_;
}

UInt_t const & cfa_base::Nels() const{
  if(!c_Nels_ && b_Nels_){
    b_Nels_->SetStatus(true);
    chainB_.SetBranchAddress("Nels", &Nels_, &b_Nels_);
    b_Nels_->GetEntry(entry_);
    c_Nels_ = true;
  }
  return Nels_;
}

UInt_t const & cfa_base::Nmc_doc() const{
  if(!c_Nmc_doc_ && b_Nmc_doc_){
    b_Nmc_doc_->SetStatus(true);
    chainB_.SetBranchAddress("Nmc_doc", &Nmc_doc_, &b_Nmc_doc_);
    b_Nmc_doc_->GetEntry(entry_);
    c_Nmc_doc_ = true;
  }
  return Nmc_doc_;
}

UInt_t const & cfa_base::Nmc_electrons() const{
  if(!c_Nmc_electrons_ && b_Nmc_electrons_){
    b_Nmc_electrons_->SetStatus(true);
    chainB_.SetBranchAddress("Nmc_electrons", &Nmc_electrons_, &b_Nmc_electrons_);
    b_Nmc_electrons_->GetEntry(entry_);
    c_Nmc_electrons_ = true;
  }
  return Nmc_electrons_;
}

UInt_t const & cfa_base::Nmc_mus() const{
  if(!c_Nmc_mus_ && b_Nmc_mus_){
    b_Nmc_mus_->SetStatus(true);
    chainB_.SetBranchAddress("Nmc_mus", &Nmc_mus_, &b_Nmc_mus_);
    b_Nmc_mus_->GetEntry(entry_);
    c_Nmc_mus_ = true;
  }
  return Nmc_mus_;
}

UInt_t const & cfa_base::Nmc_nues() const{
  if(!c_Nmc_nues_ && b_Nmc_nues_){
    b_Nmc_nues_->SetStatus(true);
    chainB_.SetBranchAddress("Nmc_nues", &Nmc_nues_, &b_Nmc_nues_);
    b_Nmc_nues_->GetEntry(entry_);
    c_Nmc_nues_ = true;
  }
  return Nmc_nues_;
}

UInt_t const & cfa_base::Nmc_numus() const{
  if(!c_Nmc_numus_ && b_Nmc_numus_){
    b_Nmc_numus_->SetStatus(true);
    chainB_.SetBranchAddress("Nmc_numus", &Nmc_numus_, &b_Nmc_numus_);
    b_Nmc_numus_->GetEntry(entry_);
    c_Nmc_numus_ = true;
  }
  return Nmc_numus_;
}

UInt_t const & cfa_base::Nmc_nutaus() const{
  if(!c_Nmc_nutaus_ && b_Nmc_nutaus_){
    b_Nmc_nutaus_->SetStatus(true);
    chainB_.SetBranchAddress("Nmc_nutaus", &Nmc_nutaus_, &b_Nmc_nutaus_);
    b_Nmc_nutaus_->GetEntry(entry_);
    c_Nmc_nutaus_ = true;
  }
  return Nmc_nutaus_;
}

UInt_t const & cfa_base::Nmc_photons() const{
  if(!c_Nmc_photons_ && b_Nmc_photons_){
    b_Nmc_photons_->SetStatus(true);
    chainB_.SetBranchAddress("Nmc_photons", &Nmc_photons_, &b_Nmc_photons_);
    b_Nmc_photons_->GetEntry(entry_);
    c_Nmc_photons_ = true;
  }
  return Nmc_photons_;
}

UInt_t const & cfa_base::Nmc_taus() const{
  if(!c_Nmc_taus_ && b_Nmc_taus_){
    b_Nmc_taus_->SetStatus(true);
    chainB_.SetBranchAddress("Nmc_taus", &Nmc_taus_, &b_Nmc_taus_);
    b_Nmc_taus_->GetEntry(entry_);
    c_Nmc_taus_ = true;
  }
  return Nmc_taus_;
}

UInt_t const & cfa_base::Nmus() const{
  if(!c_Nmus_ && b_Nmus_){
    b_Nmus_->SetStatus(true);
    chainB_.SetBranchAddress("Nmus", &Nmus_, &b_Nmus_);
    b_Nmus_->GetEntry(entry_);
    c_Nmus_ = true;
  }
  return Nmus_;
}

UInt_t const & cfa_base::Npfcand() const{
  if(!c_Npfcand_ && b_Npfcand_){
    b_Npfcand_->SetStatus(true);
    chainB_.SetBranchAddress("Npfcand", &Npfcand_, &b_Npfcand_);
    b_Npfcand_->GetEntry(entry_);
    c_Npfcand_ = true;
  }
  return Npfcand_;
}

UInt_t const & cfa_base::Nphotons() const{
  if(!c_Nphotons_ && b_Nphotons_){
    b_Nphotons_->SetStatus(true);
    chainB_.SetBranchAddress("Nphotons", &Nphotons_, &b_Nphotons_);
    b_Nphotons_->GetEntry(entry_);
    c_Nphotons_ = true;
  }
  return Nphotons_;
}

UInt_t const & cfa_base::Npv() const{
  if(!c_Npv_ && b_Npv_){
    b_Npv_->SetStatus(true);
    chainB_.SetBranchAddress("Npv", &Npv_, &b_Npv_);
    b_Npv_->GetEntry(entry_);
    c_Npv_ = true;
  }
  return Npv_;
}

UInt_t const & cfa_base::Ntaus() const{
  if(!c_Ntaus_ && b_Ntaus_){
    b_Ntaus_->SetStatus(true);
    chainB_.SetBranchAddress("Ntaus", &Ntaus_, &b_Ntaus_);
    b_Ntaus_->GetEntry(entry_);
    c_Ntaus_ = true;
  }
  return Ntaus_;
}

std::vector<int>* const & cfa_base::PU_NumInteractions() const{
  if(!c_PU_NumInteractions_ && b_PU_NumInteractions_){
    b_PU_NumInteractions_->SetStatus(true);
    chainA_.SetBranchAddress("PU_NumInteractions", &PU_NumInteractions_, &b_PU_NumInteractions_);
    b_PU_NumInteractions_->GetEntry(entry_);
    c_PU_NumInteractions_ = true;
  }
  return PU_NumInteractions_;
}

std::vector<float>* const & cfa_base::PU_TrueNumInteractions() const{
  if(!c_PU_TrueNumInteractions_ && b_PU_TrueNumInteractions_){
    b_PU_TrueNumInteractions_->SetStatus(true);
    chainA_.SetBranchAddress("PU_TrueNumInteractions", &PU_TrueNumInteractions_, &b_PU_TrueNumInteractions_);
    b_PU_TrueNumInteractions_->GetEntry(entry_);
    c_PU_TrueNumInteractions_ = true;
  }
  return PU_TrueNumInteractions_;
}

std::vector<int>* const & cfa_base::PU_bunchCrossing() const{
  if(!c_PU_bunchCrossing_ && b_PU_bunchCrossing_){
    b_PU_bunchCrossing_->SetStatus(true);
    chainA_.SetBranchAddress("PU_bunchCrossing", &PU_bunchCrossing_, &b_PU_bunchCrossing_);
    b_PU_bunchCrossing_->GetEntry(entry_);
    c_PU_bunchCrossing_ = true;
  }
  return PU_bunchCrossing_;
}

std::vector<std::vector<int> >* const & cfa_base::PU_ntrks_highpT() const{
  if(!c_PU_ntrks_highpT_ && b_PU_ntrks_highpT_){
    b_PU_ntrks_highpT_->SetStatus(true);
    chainA_.SetBranchAddress("PU_ntrks_highpT", &PU_ntrks_highpT_, &b_PU_ntrks_highpT_);
    b_PU_ntrks_highpT_->GetEntry(entry_);
    c_PU_ntrks_highpT_ = true;
  }
  return PU_ntrks_highpT_;
}

std::vector<std::vector<int> >* const & cfa_base::PU_ntrks_lowpT() const{
  if(!c_PU_ntrks_lowpT_ && b_PU_ntrks_lowpT_){
    b_PU_ntrks_lowpT_->SetStatus(true);
    chainA_.SetBranchAddress("PU_ntrks_lowpT", &PU_ntrks_lowpT_, &b_PU_ntrks_lowpT_);
    b_PU_ntrks_lowpT_->GetEntry(entry_);
    c_PU_ntrks_lowpT_ = true;
  }
  return PU_ntrks_lowpT_;
}

std::vector<std::vector<float> >* const & cfa_base::PU_sumpT_highpT() const{
  if(!c_PU_sumpT_highpT_ && b_PU_sumpT_highpT_){
    b_PU_sumpT_highpT_->SetStatus(true);
    chainA_.SetBranchAddress("PU_sumpT_highpT", &PU_sumpT_highpT_, &b_PU_sumpT_highpT_);
    b_PU_sumpT_highpT_->GetEntry(entry_);
    c_PU_sumpT_highpT_ = true;
  }
  return PU_sumpT_highpT_;
}

std::vector<std::vector<float> >* const & cfa_base::PU_sumpT_lowpT() const{
  if(!c_PU_sumpT_lowpT_ && b_PU_sumpT_lowpT_){
    b_PU_sumpT_lowpT_->SetStatus(true);
    chainA_.SetBranchAddress("PU_sumpT_lowpT", &PU_sumpT_lowpT_, &b_PU_sumpT_lowpT_);
    b_PU_sumpT_lowpT_->GetEntry(entry_);
    c_PU_sumpT_lowpT_ = true;
  }
  return PU_sumpT_lowpT_;
}

std::vector<std::vector<float> >* const & cfa_base::PU_zpositions() const{
  if(!c_PU_zpositions_ && b_PU_zpositions_){
    b_PU_zpositions_->SetStatus(true);
    chainA_.SetBranchAddress("PU_zpositions", &PU_zpositions_, &b_PU_zpositions_);
    b_PU_zpositions_->GetEntry(entry_);
    c_PU_zpositions_ = true;
  }
  return PU_zpositions_;
}

std::vector<float>* const & cfa_base::beamSpot_beamWidthX() const{
  if(!c_beamSpot_beamWidthX_ && b_beamSpot_beamWidthX_){
    b_beamSpot_beamWidthX_->SetStatus(true);
    chainB_.SetBranchAddress("beamSpot_beamWidthX", &beamSpot_beamWidthX_, &b_beamSpot_beamWidthX_);
    b_beamSpot_beamWidthX_->GetEntry(entry_);
    c_beamSpot_beamWidthX_ = true;
  }
  return beamSpot_beamWidthX_;
}

std::vector<float>* const & cfa_base::beamSpot_beamWidthXError() const{
  if(!c_beamSpot_beamWidthXError_ && b_beamSpot_beamWidthXError_){
    b_beamSpot_beamWidthXError_->SetStatus(true);
    chainB_.SetBranchAddress("beamSpot_beamWidthXError", &beamSpot_beamWidthXError_, &b_beamSpot_beamWidthXError_);
    b_beamSpot_beamWidthXError_->GetEntry(entry_);
    c_beamSpot_beamWidthXError_ = true;
  }
  return beamSpot_beamWidthXError_;
}

std::vector<float>* const & cfa_base::beamSpot_beamWidthY() const{
  if(!c_beamSpot_beamWidthY_ && b_beamSpot_beamWidthY_){
    b_beamSpot_beamWidthY_->SetStatus(true);
    chainB_.SetBranchAddress("beamSpot_beamWidthY", &beamSpot_beamWidthY_, &b_beamSpot_beamWidthY_);
    b_beamSpot_beamWidthY_->GetEntry(entry_);
    c_beamSpot_beamWidthY_ = true;
  }
  return beamSpot_beamWidthY_;
}

std::vector<float>* const & cfa_base::beamSpot_beamWidthYError() const{
  if(!c_beamSpot_beamWidthYError_ && b_beamSpot_beamWidthYError_){
    b_beamSpot_beamWidthYError_->SetStatus(true);
    chainB_.SetBranchAddress("beamSpot_beamWidthYError", &beamSpot_beamWidthYError_, &b_beamSpot_beamWidthYError_);
    b_beamSpot_beamWidthYError_->GetEntry(entry_);
    c_beamSpot_beamWidthYError_ = true;
  }
  return beamSpot_beamWidthYError_;
}

std::vector<float>* const & cfa_base::beamSpot_dxdz() const{
  if(!c_beamSpot_dxdz_ && b_beamSpot_dxdz_){
    b_beamSpot_dxdz_->SetStatus(true);
    chainB_.SetBranchAddress("beamSpot_dxdz", &beamSpot_dxdz_, &b_beamSpot_dxdz_);
    b_beamSpot_dxdz_->GetEntry(entry_);
    c_beamSpot_dxdz_ = true;
  }
  return beamSpot_dxdz_;
}

std::vector<float>* const & cfa_base::beamSpot_dxdzError() const{
  if(!c_beamSpot_dxdzError_ && b_beamSpot_dxdzError_){
    b_beamSpot_dxdzError_->SetStatus(true);
    chainB_.SetBranchAddress("beamSpot_dxdzError", &beamSpot_dxdzError_, &b_beamSpot_dxdzError_);
    b_beamSpot_dxdzError_->GetEntry(entry_);
    c_beamSpot_dxdzError_ = true;
  }
  return beamSpot_dxdzError_;
}

std::vector<float>* const & cfa_base::beamSpot_dydz() const{
  if(!c_beamSpot_dydz_ && b_beamSpot_dydz_){
    b_beamSpot_dydz_->SetStatus(true);
    chainB_.SetBranchAddress("beamSpot_dydz", &beamSpot_dydz_, &b_beamSpot_dydz_);
    b_beamSpot_dydz_->GetEntry(entry_);
    c_beamSpot_dydz_ = true;
  }
  return beamSpot_dydz_;
}

std::vector<float>* const & cfa_base::beamSpot_dydzError() const{
  if(!c_beamSpot_dydzError_ && b_beamSpot_dydzError_){
    b_beamSpot_dydzError_->SetStatus(true);
    chainB_.SetBranchAddress("beamSpot_dydzError", &beamSpot_dydzError_, &b_beamSpot_dydzError_);
    b_beamSpot_dydzError_->GetEntry(entry_);
    c_beamSpot_dydzError_ = true;
  }
  return beamSpot_dydzError_;
}

std::vector<float>* const & cfa_base::beamSpot_sigmaZ() const{
  if(!c_beamSpot_sigmaZ_ && b_beamSpot_sigmaZ_){
    b_beamSpot_sigmaZ_->SetStatus(true);
    chainB_.SetBranchAddress("beamSpot_sigmaZ", &beamSpot_sigmaZ_, &b_beamSpot_sigmaZ_);
    b_beamSpot_sigmaZ_->GetEntry(entry_);
    c_beamSpot_sigmaZ_ = true;
  }
  return beamSpot_sigmaZ_;
}

std::vector<float>* const & cfa_base::beamSpot_sigmaZ0Error() const{
  if(!c_beamSpot_sigmaZ0Error_ && b_beamSpot_sigmaZ0Error_){
    b_beamSpot_sigmaZ0Error_->SetStatus(true);
    chainB_.SetBranchAddress("beamSpot_sigmaZ0Error", &beamSpot_sigmaZ0Error_, &b_beamSpot_sigmaZ0Error_);
    b_beamSpot_sigmaZ0Error_->GetEntry(entry_);
    c_beamSpot_sigmaZ0Error_ = true;
  }
  return beamSpot_sigmaZ0Error_;
}

std::vector<float>* const & cfa_base::beamSpot_x() const{
  if(!c_beamSpot_x_ && b_beamSpot_x_){
    b_beamSpot_x_->SetStatus(true);
    chainB_.SetBranchAddress("beamSpot_x", &beamSpot_x_, &b_beamSpot_x_);
    b_beamSpot_x_->GetEntry(entry_);
    c_beamSpot_x_ = true;
  }
  return beamSpot_x_;
}

std::vector<float>* const & cfa_base::beamSpot_x0Error() const{
  if(!c_beamSpot_x0Error_ && b_beamSpot_x0Error_){
    b_beamSpot_x0Error_->SetStatus(true);
    chainB_.SetBranchAddress("beamSpot_x0Error", &beamSpot_x0Error_, &b_beamSpot_x0Error_);
    b_beamSpot_x0Error_->GetEntry(entry_);
    c_beamSpot_x0Error_ = true;
  }
  return beamSpot_x0Error_;
}

std::vector<float>* const & cfa_base::beamSpot_y() const{
  if(!c_beamSpot_y_ && b_beamSpot_y_){
    b_beamSpot_y_->SetStatus(true);
    chainB_.SetBranchAddress("beamSpot_y", &beamSpot_y_, &b_beamSpot_y_);
    b_beamSpot_y_->GetEntry(entry_);
    c_beamSpot_y_ = true;
  }
  return beamSpot_y_;
}

std::vector<float>* const & cfa_base::beamSpot_y0Error() const{
  if(!c_beamSpot_y0Error_ && b_beamSpot_y0Error_){
    b_beamSpot_y0Error_->SetStatus(true);
    chainB_.SetBranchAddress("beamSpot_y0Error", &beamSpot_y0Error_, &b_beamSpot_y0Error_);
    b_beamSpot_y0Error_->GetEntry(entry_);
    c_beamSpot_y0Error_ = true;
  }
  return beamSpot_y0Error_;
}

std::vector<float>* const & cfa_base::beamSpot_z() const{
  if(!c_beamSpot_z_ && b_beamSpot_z_){
    b_beamSpot_z_->SetStatus(true);
    chainB_.SetBranchAddress("beamSpot_z", &beamSpot_z_, &b_beamSpot_z_);
    b_beamSpot_z_->GetEntry(entry_);
    c_beamSpot_z_ = true;
  }
  return beamSpot_z_;
}

std::vector<float>* const & cfa_base::beamSpot_z0Error() const{
  if(!c_beamSpot_z0Error_ && b_beamSpot_z0Error_){
    b_beamSpot_z0Error_->SetStatus(true);
    chainB_.SetBranchAddress("beamSpot_z0Error", &beamSpot_z0Error_, &b_beamSpot_z0Error_);
    b_beamSpot_z0Error_->GetEntry(entry_);
    c_beamSpot_z0Error_ = true;
  }
  return beamSpot_z0Error_;
}

UInt_t const & cfa_base::bunchCrossing() const{
  if(!c_bunchCrossing_ && b_bunchCrossing_){
    b_bunchCrossing_->SetStatus(true);
    chainB_.SetBranchAddress("bunchCrossing", &bunchCrossing_, &b_bunchCrossing_);
    b_bunchCrossing_->GetEntry(entry_);
    c_bunchCrossing_ = true;
  }
  return bunchCrossing_;
}

Int_t const & cfa_base::cschalofilter_decision() const{
  if(!c_cschalofilter_decision_ && b_cschalofilter_decision_){
    b_cschalofilter_decision_->SetStatus(true);
    chainA_.SetBranchAddress("cschalofilter_decision", &cschalofilter_decision_, &b_cschalofilter_decision_);
    b_cschalofilter_decision_->GetEntry(entry_);
    c_cschalofilter_decision_ = true;
  }
  return cschalofilter_decision_;
}

Int_t const & cfa_base::ecallaserfilter_decision() const{
  if(!c_ecallaserfilter_decision_ && b_ecallaserfilter_decision_){
    b_ecallaserfilter_decision_->SetStatus(true);
    chainA_.SetBranchAddress("ecallaserfilter_decision", &ecallaserfilter_decision_, &b_ecallaserfilter_decision_);
    b_ecallaserfilter_decision_->GetEntry(entry_);
    c_ecallaserfilter_decision_ = true;
  }
  return ecallaserfilter_decision_;
}

Int_t const & cfa_base::eebadscfilter_decision() const{
  if(!c_eebadscfilter_decision_ && b_eebadscfilter_decision_){
    b_eebadscfilter_decision_->SetStatus(true);
    chainA_.SetBranchAddress("eebadscfilter_decision", &eebadscfilter_decision_, &b_eebadscfilter_decision_);
    b_eebadscfilter_decision_->GetEntry(entry_);
    c_eebadscfilter_decision_ = true;
  }
  return eebadscfilter_decision_;
}

std::vector<float>* const & cfa_base::els_PATpassConversionVeto() const{
  if(!c_els_PATpassConversionVeto_ && b_els_PATpassConversionVeto_){
    b_els_PATpassConversionVeto_->SetStatus(true);
    chainB_.SetBranchAddress("els_PATpassConversionVeto", &els_PATpassConversionVeto_, &b_els_PATpassConversionVeto_);
    b_els_PATpassConversionVeto_->GetEntry(entry_);
    c_els_PATpassConversionVeto_ = true;
  }
  return els_PATpassConversionVeto_;
}

std::vector<float>* const & cfa_base::els_basicClustersSize() const{
  if(!c_els_basicClustersSize_ && b_els_basicClustersSize_){
    b_els_basicClustersSize_->SetStatus(true);
    chainB_.SetBranchAddress("els_basicClustersSize", &els_basicClustersSize_, &b_els_basicClustersSize_);
    b_els_basicClustersSize_->GetEntry(entry_);
    c_els_basicClustersSize_ = true;
  }
  return els_basicClustersSize_;
}

std::vector<float>* const & cfa_base::els_cIso() const{
  if(!c_els_cIso_ && b_els_cIso_){
    b_els_cIso_->SetStatus(true);
    chainB_.SetBranchAddress("els_cIso", &els_cIso_, &b_els_cIso_);
    b_els_cIso_->GetEntry(entry_);
    c_els_cIso_ = true;
  }
  return els_cIso_;
}

std::vector<float>* const & cfa_base::els_caloEnergy() const{
  if(!c_els_caloEnergy_ && b_els_caloEnergy_){
    b_els_caloEnergy_->SetStatus(true);
    chainB_.SetBranchAddress("els_caloEnergy", &els_caloEnergy_, &b_els_caloEnergy_);
    b_els_caloEnergy_->GetEntry(entry_);
    c_els_caloEnergy_ = true;
  }
  return els_caloEnergy_;
}

std::vector<float>* const & cfa_base::els_charge() const{
  if(!c_els_charge_ && b_els_charge_){
    b_els_charge_->SetStatus(true);
    chainB_.SetBranchAddress("els_charge", &els_charge_, &b_els_charge_);
    b_els_charge_->GetEntry(entry_);
    c_els_charge_ = true;
  }
  return els_charge_;
}

std::vector<float>* const & cfa_base::els_chi2() const{
  if(!c_els_chi2_ && b_els_chi2_){
    b_els_chi2_->SetStatus(true);
    chainB_.SetBranchAddress("els_chi2", &els_chi2_, &b_els_chi2_);
    b_els_chi2_->GetEntry(entry_);
    c_els_chi2_ = true;
  }
  return els_chi2_;
}

std::vector<float>* const & cfa_base::els_core_ecalDrivenSeed() const{
  if(!c_els_core_ecalDrivenSeed_ && b_els_core_ecalDrivenSeed_){
    b_els_core_ecalDrivenSeed_->SetStatus(true);
    chainB_.SetBranchAddress("els_core_ecalDrivenSeed", &els_core_ecalDrivenSeed_, &b_els_core_ecalDrivenSeed_);
    b_els_core_ecalDrivenSeed_->GetEntry(entry_);
    c_els_core_ecalDrivenSeed_ = true;
  }
  return els_core_ecalDrivenSeed_;
}

std::vector<float>* const & cfa_base::els_cpx() const{
  if(!c_els_cpx_ && b_els_cpx_){
    b_els_cpx_->SetStatus(true);
    chainB_.SetBranchAddress("els_cpx", &els_cpx_, &b_els_cpx_);
    b_els_cpx_->GetEntry(entry_);
    c_els_cpx_ = true;
  }
  return els_cpx_;
}

std::vector<float>* const & cfa_base::els_cpy() const{
  if(!c_els_cpy_ && b_els_cpy_){
    b_els_cpy_->SetStatus(true);
    chainB_.SetBranchAddress("els_cpy", &els_cpy_, &b_els_cpy_);
    b_els_cpy_->GetEntry(entry_);
    c_els_cpy_ = true;
  }
  return els_cpy_;
}

std::vector<float>* const & cfa_base::els_cpz() const{
  if(!c_els_cpz_ && b_els_cpz_){
    b_els_cpz_->SetStatus(true);
    chainB_.SetBranchAddress("els_cpz", &els_cpz_, &b_els_cpz_);
    b_els_cpz_->GetEntry(entry_);
    c_els_cpz_ = true;
  }
  return els_cpz_;
}

std::vector<float>* const & cfa_base::els_ctf_tk_charge() const{
  if(!c_els_ctf_tk_charge_ && b_els_ctf_tk_charge_){
    b_els_ctf_tk_charge_->SetStatus(true);
    chainB_.SetBranchAddress("els_ctf_tk_charge", &els_ctf_tk_charge_, &b_els_ctf_tk_charge_);
    b_els_ctf_tk_charge_->GetEntry(entry_);
    c_els_ctf_tk_charge_ = true;
  }
  return els_ctf_tk_charge_;
}

std::vector<float>* const & cfa_base::els_ctf_tk_eta() const{
  if(!c_els_ctf_tk_eta_ && b_els_ctf_tk_eta_){
    b_els_ctf_tk_eta_->SetStatus(true);
    chainB_.SetBranchAddress("els_ctf_tk_eta", &els_ctf_tk_eta_, &b_els_ctf_tk_eta_);
    b_els_ctf_tk_eta_->GetEntry(entry_);
    c_els_ctf_tk_eta_ = true;
  }
  return els_ctf_tk_eta_;
}

std::vector<float>* const & cfa_base::els_ctf_tk_id() const{
  if(!c_els_ctf_tk_id_ && b_els_ctf_tk_id_){
    b_els_ctf_tk_id_->SetStatus(true);
    chainB_.SetBranchAddress("els_ctf_tk_id", &els_ctf_tk_id_, &b_els_ctf_tk_id_);
    b_els_ctf_tk_id_->GetEntry(entry_);
    c_els_ctf_tk_id_ = true;
  }
  return els_ctf_tk_id_;
}

std::vector<float>* const & cfa_base::els_ctf_tk_phi() const{
  if(!c_els_ctf_tk_phi_ && b_els_ctf_tk_phi_){
    b_els_ctf_tk_phi_->SetStatus(true);
    chainB_.SetBranchAddress("els_ctf_tk_phi", &els_ctf_tk_phi_, &b_els_ctf_tk_phi_);
    b_els_ctf_tk_phi_->GetEntry(entry_);
    c_els_ctf_tk_phi_ = true;
  }
  return els_ctf_tk_phi_;
}

std::vector<float>* const & cfa_base::els_cx() const{
  if(!c_els_cx_ && b_els_cx_){
    b_els_cx_->SetStatus(true);
    chainB_.SetBranchAddress("els_cx", &els_cx_, &b_els_cx_);
    b_els_cx_->GetEntry(entry_);
    c_els_cx_ = true;
  }
  return els_cx_;
}

std::vector<float>* const & cfa_base::els_cy() const{
  if(!c_els_cy_ && b_els_cy_){
    b_els_cy_->SetStatus(true);
    chainB_.SetBranchAddress("els_cy", &els_cy_, &b_els_cy_);
    b_els_cy_->GetEntry(entry_);
    c_els_cy_ = true;
  }
  return els_cy_;
}

std::vector<float>* const & cfa_base::els_cz() const{
  if(!c_els_cz_ && b_els_cz_){
    b_els_cz_->SetStatus(true);
    chainB_.SetBranchAddress("els_cz", &els_cz_, &b_els_cz_);
    b_els_cz_->GetEntry(entry_);
    c_els_cz_ = true;
  }
  return els_cz_;
}

std::vector<float>* const & cfa_base::els_d0dum() const{
  if(!c_els_d0dum_ && b_els_d0dum_){
    b_els_d0dum_->SetStatus(true);
    chainB_.SetBranchAddress("els_d0dum", &els_d0dum_, &b_els_d0dum_);
    b_els_d0dum_->GetEntry(entry_);
    c_els_d0dum_ = true;
  }
  return els_d0dum_;
}

std::vector<float>* const & cfa_base::els_d0dumError() const{
  if(!c_els_d0dumError_ && b_els_d0dumError_){
    b_els_d0dumError_->SetStatus(true);
    chainB_.SetBranchAddress("els_d0dumError", &els_d0dumError_, &b_els_d0dumError_);
    b_els_d0dumError_->GetEntry(entry_);
    c_els_d0dumError_ = true;
  }
  return els_d0dumError_;
}

std::vector<float>* const & cfa_base::els_dEtaIn() const{
  if(!c_els_dEtaIn_ && b_els_dEtaIn_){
    b_els_dEtaIn_->SetStatus(true);
    chainB_.SetBranchAddress("els_dEtaIn", &els_dEtaIn_, &b_els_dEtaIn_);
    b_els_dEtaIn_->GetEntry(entry_);
    c_els_dEtaIn_ = true;
  }
  return els_dEtaIn_;
}

std::vector<float>* const & cfa_base::els_dEtaOut() const{
  if(!c_els_dEtaOut_ && b_els_dEtaOut_){
    b_els_dEtaOut_->SetStatus(true);
    chainB_.SetBranchAddress("els_dEtaOut", &els_dEtaOut_, &b_els_dEtaOut_);
    b_els_dEtaOut_->GetEntry(entry_);
    c_els_dEtaOut_ = true;
  }
  return els_dEtaOut_;
}

std::vector<float>* const & cfa_base::els_dPhiIn() const{
  if(!c_els_dPhiIn_ && b_els_dPhiIn_){
    b_els_dPhiIn_->SetStatus(true);
    chainB_.SetBranchAddress("els_dPhiIn", &els_dPhiIn_, &b_els_dPhiIn_);
    b_els_dPhiIn_->GetEntry(entry_);
    c_els_dPhiIn_ = true;
  }
  return els_dPhiIn_;
}

std::vector<float>* const & cfa_base::els_dPhiOut() const{
  if(!c_els_dPhiOut_ && b_els_dPhiOut_){
    b_els_dPhiOut_->SetStatus(true);
    chainB_.SetBranchAddress("els_dPhiOut", &els_dPhiOut_, &b_els_dPhiOut_);
    b_els_dPhiOut_->GetEntry(entry_);
    c_els_dPhiOut_ = true;
  }
  return els_dPhiOut_;
}

std::vector<float>* const & cfa_base::els_dr03EcalRecHitSumEt() const{
  if(!c_els_dr03EcalRecHitSumEt_ && b_els_dr03EcalRecHitSumEt_){
    b_els_dr03EcalRecHitSumEt_->SetStatus(true);
    chainB_.SetBranchAddress("els_dr03EcalRecHitSumEt", &els_dr03EcalRecHitSumEt_, &b_els_dr03EcalRecHitSumEt_);
    b_els_dr03EcalRecHitSumEt_->GetEntry(entry_);
    c_els_dr03EcalRecHitSumEt_ = true;
  }
  return els_dr03EcalRecHitSumEt_;
}

std::vector<float>* const & cfa_base::els_dr03HcalDepth1TowerSumEt() const{
  if(!c_els_dr03HcalDepth1TowerSumEt_ && b_els_dr03HcalDepth1TowerSumEt_){
    b_els_dr03HcalDepth1TowerSumEt_->SetStatus(true);
    chainB_.SetBranchAddress("els_dr03HcalDepth1TowerSumEt", &els_dr03HcalDepth1TowerSumEt_, &b_els_dr03HcalDepth1TowerSumEt_);
    b_els_dr03HcalDepth1TowerSumEt_->GetEntry(entry_);
    c_els_dr03HcalDepth1TowerSumEt_ = true;
  }
  return els_dr03HcalDepth1TowerSumEt_;
}

std::vector<float>* const & cfa_base::els_dr03HcalDepth2TowerSumEt() const{
  if(!c_els_dr03HcalDepth2TowerSumEt_ && b_els_dr03HcalDepth2TowerSumEt_){
    b_els_dr03HcalDepth2TowerSumEt_->SetStatus(true);
    chainB_.SetBranchAddress("els_dr03HcalDepth2TowerSumEt", &els_dr03HcalDepth2TowerSumEt_, &b_els_dr03HcalDepth2TowerSumEt_);
    b_els_dr03HcalDepth2TowerSumEt_->GetEntry(entry_);
    c_els_dr03HcalDepth2TowerSumEt_ = true;
  }
  return els_dr03HcalDepth2TowerSumEt_;
}

std::vector<float>* const & cfa_base::els_dr03HcalTowerSumEt() const{
  if(!c_els_dr03HcalTowerSumEt_ && b_els_dr03HcalTowerSumEt_){
    b_els_dr03HcalTowerSumEt_->SetStatus(true);
    chainB_.SetBranchAddress("els_dr03HcalTowerSumEt", &els_dr03HcalTowerSumEt_, &b_els_dr03HcalTowerSumEt_);
    b_els_dr03HcalTowerSumEt_->GetEntry(entry_);
    c_els_dr03HcalTowerSumEt_ = true;
  }
  return els_dr03HcalTowerSumEt_;
}

std::vector<float>* const & cfa_base::els_dr03TkSumPt() const{
  if(!c_els_dr03TkSumPt_ && b_els_dr03TkSumPt_){
    b_els_dr03TkSumPt_->SetStatus(true);
    chainB_.SetBranchAddress("els_dr03TkSumPt", &els_dr03TkSumPt_, &b_els_dr03TkSumPt_);
    b_els_dr03TkSumPt_->GetEntry(entry_);
    c_els_dr03TkSumPt_ = true;
  }
  return els_dr03TkSumPt_;
}

std::vector<float>* const & cfa_base::els_dr04EcalRecHitSumEt() const{
  if(!c_els_dr04EcalRecHitSumEt_ && b_els_dr04EcalRecHitSumEt_){
    b_els_dr04EcalRecHitSumEt_->SetStatus(true);
    chainB_.SetBranchAddress("els_dr04EcalRecHitSumEt", &els_dr04EcalRecHitSumEt_, &b_els_dr04EcalRecHitSumEt_);
    b_els_dr04EcalRecHitSumEt_->GetEntry(entry_);
    c_els_dr04EcalRecHitSumEt_ = true;
  }
  return els_dr04EcalRecHitSumEt_;
}

std::vector<float>* const & cfa_base::els_dr04HcalDepth1TowerSumEt() const{
  if(!c_els_dr04HcalDepth1TowerSumEt_ && b_els_dr04HcalDepth1TowerSumEt_){
    b_els_dr04HcalDepth1TowerSumEt_->SetStatus(true);
    chainB_.SetBranchAddress("els_dr04HcalDepth1TowerSumEt", &els_dr04HcalDepth1TowerSumEt_, &b_els_dr04HcalDepth1TowerSumEt_);
    b_els_dr04HcalDepth1TowerSumEt_->GetEntry(entry_);
    c_els_dr04HcalDepth1TowerSumEt_ = true;
  }
  return els_dr04HcalDepth1TowerSumEt_;
}

std::vector<float>* const & cfa_base::els_dr04HcalDepth2TowerSumEt() const{
  if(!c_els_dr04HcalDepth2TowerSumEt_ && b_els_dr04HcalDepth2TowerSumEt_){
    b_els_dr04HcalDepth2TowerSumEt_->SetStatus(true);
    chainB_.SetBranchAddress("els_dr04HcalDepth2TowerSumEt", &els_dr04HcalDepth2TowerSumEt_, &b_els_dr04HcalDepth2TowerSumEt_);
    b_els_dr04HcalDepth2TowerSumEt_->GetEntry(entry_);
    c_els_dr04HcalDepth2TowerSumEt_ = true;
  }
  return els_dr04HcalDepth2TowerSumEt_;
}

std::vector<float>* const & cfa_base::els_dr04HcalTowerSumEt() const{
  if(!c_els_dr04HcalTowerSumEt_ && b_els_dr04HcalTowerSumEt_){
    b_els_dr04HcalTowerSumEt_->SetStatus(true);
    chainB_.SetBranchAddress("els_dr04HcalTowerSumEt", &els_dr04HcalTowerSumEt_, &b_els_dr04HcalTowerSumEt_);
    b_els_dr04HcalTowerSumEt_->GetEntry(entry_);
    c_els_dr04HcalTowerSumEt_ = true;
  }
  return els_dr04HcalTowerSumEt_;
}

std::vector<float>* const & cfa_base::els_dr04TkSumPt() const{
  if(!c_els_dr04TkSumPt_ && b_els_dr04TkSumPt_){
    b_els_dr04TkSumPt_->SetStatus(true);
    chainB_.SetBranchAddress("els_dr04TkSumPt", &els_dr04TkSumPt_, &b_els_dr04TkSumPt_);
    b_els_dr04TkSumPt_->GetEntry(entry_);
    c_els_dr04TkSumPt_ = true;
  }
  return els_dr04TkSumPt_;
}

std::vector<float>* const & cfa_base::els_dz() const{
  if(!c_els_dz_ && b_els_dz_){
    b_els_dz_->SetStatus(true);
    chainB_.SetBranchAddress("els_dz", &els_dz_, &b_els_dz_);
    b_els_dz_->GetEntry(entry_);
    c_els_dz_ = true;
  }
  return els_dz_;
}

std::vector<float>* const & cfa_base::els_dzError() const{
  if(!c_els_dzError_ && b_els_dzError_){
    b_els_dzError_->SetStatus(true);
    chainB_.SetBranchAddress("els_dzError", &els_dzError_, &b_els_dzError_);
    b_els_dzError_->GetEntry(entry_);
    c_els_dzError_ = true;
  }
  return els_dzError_;
}

std::vector<float>* const & cfa_base::els_eOverPIn() const{
  if(!c_els_eOverPIn_ && b_els_eOverPIn_){
    b_els_eOverPIn_->SetStatus(true);
    chainB_.SetBranchAddress("els_eOverPIn", &els_eOverPIn_, &b_els_eOverPIn_);
    b_els_eOverPIn_->GetEntry(entry_);
    c_els_eOverPIn_ = true;
  }
  return els_eOverPIn_;
}

std::vector<float>* const & cfa_base::els_eSeedOverPOut() const{
  if(!c_els_eSeedOverPOut_ && b_els_eSeedOverPOut_){
    b_els_eSeedOverPOut_->SetStatus(true);
    chainB_.SetBranchAddress("els_eSeedOverPOut", &els_eSeedOverPOut_, &b_els_eSeedOverPOut_);
    b_els_eSeedOverPOut_->GetEntry(entry_);
    c_els_eSeedOverPOut_ = true;
  }
  return els_eSeedOverPOut_;
}

std::vector<float>* const & cfa_base::els_ecalIso() const{
  if(!c_els_ecalIso_ && b_els_ecalIso_){
    b_els_ecalIso_->SetStatus(true);
    chainB_.SetBranchAddress("els_ecalIso", &els_ecalIso_, &b_els_ecalIso_);
    b_els_ecalIso_->GetEntry(entry_);
    c_els_ecalIso_ = true;
  }
  return els_ecalIso_;
}

std::vector<float>* const & cfa_base::els_energy() const{
  if(!c_els_energy_ && b_els_energy_){
    b_els_energy_->SetStatus(true);
    chainB_.SetBranchAddress("els_energy", &els_energy_, &b_els_energy_);
    b_els_energy_->GetEntry(entry_);
    c_els_energy_ = true;
  }
  return els_energy_;
}

std::vector<float>* const & cfa_base::els_et() const{
  if(!c_els_et_ && b_els_et_){
    b_els_et_->SetStatus(true);
    chainB_.SetBranchAddress("els_et", &els_et_, &b_els_et_);
    b_els_et_->GetEntry(entry_);
    c_els_et_ = true;
  }
  return els_et_;
}

std::vector<float>* const & cfa_base::els_eta() const{
  if(!c_els_eta_ && b_els_eta_){
    b_els_eta_->SetStatus(true);
    chainB_.SetBranchAddress("els_eta", &els_eta_, &b_els_eta_);
    b_els_eta_->GetEntry(entry_);
    c_els_eta_ = true;
  }
  return els_eta_;
}

std::vector<float>* const & cfa_base::els_etaError() const{
  if(!c_els_etaError_ && b_els_etaError_){
    b_els_etaError_->SetStatus(true);
    chainB_.SetBranchAddress("els_etaError", &els_etaError_, &b_els_etaError_);
    b_els_etaError_->GetEntry(entry_);
    c_els_etaError_ = true;
  }
  return els_etaError_;
}

std::vector<float>* const & cfa_base::els_fbrem() const{
  if(!c_els_fbrem_ && b_els_fbrem_){
    b_els_fbrem_->SetStatus(true);
    chainB_.SetBranchAddress("els_fbrem", &els_fbrem_, &b_els_fbrem_);
    b_els_fbrem_->GetEntry(entry_);
    c_els_fbrem_ = true;
  }
  return els_fbrem_;
}

std::vector<float>* const & cfa_base::els_gen_et() const{
  if(!c_els_gen_et_ && b_els_gen_et_){
    b_els_gen_et_->SetStatus(true);
    chainB_.SetBranchAddress("els_gen_et", &els_gen_et_, &b_els_gen_et_);
    b_els_gen_et_->GetEntry(entry_);
    c_els_gen_et_ = true;
  }
  return els_gen_et_;
}

std::vector<float>* const & cfa_base::els_gen_eta() const{
  if(!c_els_gen_eta_ && b_els_gen_eta_){
    b_els_gen_eta_->SetStatus(true);
    chainB_.SetBranchAddress("els_gen_eta", &els_gen_eta_, &b_els_gen_eta_);
    b_els_gen_eta_->GetEntry(entry_);
    c_els_gen_eta_ = true;
  }
  return els_gen_eta_;
}

std::vector<float>* const & cfa_base::els_gen_id() const{
  if(!c_els_gen_id_ && b_els_gen_id_){
    b_els_gen_id_->SetStatus(true);
    chainB_.SetBranchAddress("els_gen_id", &els_gen_id_, &b_els_gen_id_);
    b_els_gen_id_->GetEntry(entry_);
    c_els_gen_id_ = true;
  }
  return els_gen_id_;
}

std::vector<float>* const & cfa_base::els_gen_mother_et() const{
  if(!c_els_gen_mother_et_ && b_els_gen_mother_et_){
    b_els_gen_mother_et_->SetStatus(true);
    chainB_.SetBranchAddress("els_gen_mother_et", &els_gen_mother_et_, &b_els_gen_mother_et_);
    b_els_gen_mother_et_->GetEntry(entry_);
    c_els_gen_mother_et_ = true;
  }
  return els_gen_mother_et_;
}

std::vector<float>* const & cfa_base::els_gen_mother_eta() const{
  if(!c_els_gen_mother_eta_ && b_els_gen_mother_eta_){
    b_els_gen_mother_eta_->SetStatus(true);
    chainB_.SetBranchAddress("els_gen_mother_eta", &els_gen_mother_eta_, &b_els_gen_mother_eta_);
    b_els_gen_mother_eta_->GetEntry(entry_);
    c_els_gen_mother_eta_ = true;
  }
  return els_gen_mother_eta_;
}

std::vector<float>* const & cfa_base::els_gen_mother_id() const{
  if(!c_els_gen_mother_id_ && b_els_gen_mother_id_){
    b_els_gen_mother_id_->SetStatus(true);
    chainB_.SetBranchAddress("els_gen_mother_id", &els_gen_mother_id_, &b_els_gen_mother_id_);
    b_els_gen_mother_id_->GetEntry(entry_);
    c_els_gen_mother_id_ = true;
  }
  return els_gen_mother_id_;
}

std::vector<float>* const & cfa_base::els_gen_mother_phi() const{
  if(!c_els_gen_mother_phi_ && b_els_gen_mother_phi_){
    b_els_gen_mother_phi_->SetStatus(true);
    chainB_.SetBranchAddress("els_gen_mother_phi", &els_gen_mother_phi_, &b_els_gen_mother_phi_);
    b_els_gen_mother_phi_->GetEntry(entry_);
    c_els_gen_mother_phi_ = true;
  }
  return els_gen_mother_phi_;
}

std::vector<float>* const & cfa_base::els_gen_mother_pt() const{
  if(!c_els_gen_mother_pt_ && b_els_gen_mother_pt_){
    b_els_gen_mother_pt_->SetStatus(true);
    chainB_.SetBranchAddress("els_gen_mother_pt", &els_gen_mother_pt_, &b_els_gen_mother_pt_);
    b_els_gen_mother_pt_->GetEntry(entry_);
    c_els_gen_mother_pt_ = true;
  }
  return els_gen_mother_pt_;
}

std::vector<float>* const & cfa_base::els_gen_mother_px() const{
  if(!c_els_gen_mother_px_ && b_els_gen_mother_px_){
    b_els_gen_mother_px_->SetStatus(true);
    chainB_.SetBranchAddress("els_gen_mother_px", &els_gen_mother_px_, &b_els_gen_mother_px_);
    b_els_gen_mother_px_->GetEntry(entry_);
    c_els_gen_mother_px_ = true;
  }
  return els_gen_mother_px_;
}

std::vector<float>* const & cfa_base::els_gen_mother_py() const{
  if(!c_els_gen_mother_py_ && b_els_gen_mother_py_){
    b_els_gen_mother_py_->SetStatus(true);
    chainB_.SetBranchAddress("els_gen_mother_py", &els_gen_mother_py_, &b_els_gen_mother_py_);
    b_els_gen_mother_py_->GetEntry(entry_);
    c_els_gen_mother_py_ = true;
  }
  return els_gen_mother_py_;
}

std::vector<float>* const & cfa_base::els_gen_mother_pz() const{
  if(!c_els_gen_mother_pz_ && b_els_gen_mother_pz_){
    b_els_gen_mother_pz_->SetStatus(true);
    chainB_.SetBranchAddress("els_gen_mother_pz", &els_gen_mother_pz_, &b_els_gen_mother_pz_);
    b_els_gen_mother_pz_->GetEntry(entry_);
    c_els_gen_mother_pz_ = true;
  }
  return els_gen_mother_pz_;
}

std::vector<float>* const & cfa_base::els_gen_mother_theta() const{
  if(!c_els_gen_mother_theta_ && b_els_gen_mother_theta_){
    b_els_gen_mother_theta_->SetStatus(true);
    chainB_.SetBranchAddress("els_gen_mother_theta", &els_gen_mother_theta_, &b_els_gen_mother_theta_);
    b_els_gen_mother_theta_->GetEntry(entry_);
    c_els_gen_mother_theta_ = true;
  }
  return els_gen_mother_theta_;
}

std::vector<float>* const & cfa_base::els_gen_phi() const{
  if(!c_els_gen_phi_ && b_els_gen_phi_){
    b_els_gen_phi_->SetStatus(true);
    chainB_.SetBranchAddress("els_gen_phi", &els_gen_phi_, &b_els_gen_phi_);
    b_els_gen_phi_->GetEntry(entry_);
    c_els_gen_phi_ = true;
  }
  return els_gen_phi_;
}

std::vector<float>* const & cfa_base::els_gen_pt() const{
  if(!c_els_gen_pt_ && b_els_gen_pt_){
    b_els_gen_pt_->SetStatus(true);
    chainB_.SetBranchAddress("els_gen_pt", &els_gen_pt_, &b_els_gen_pt_);
    b_els_gen_pt_->GetEntry(entry_);
    c_els_gen_pt_ = true;
  }
  return els_gen_pt_;
}

std::vector<float>* const & cfa_base::els_gen_px() const{
  if(!c_els_gen_px_ && b_els_gen_px_){
    b_els_gen_px_->SetStatus(true);
    chainB_.SetBranchAddress("els_gen_px", &els_gen_px_, &b_els_gen_px_);
    b_els_gen_px_->GetEntry(entry_);
    c_els_gen_px_ = true;
  }
  return els_gen_px_;
}

std::vector<float>* const & cfa_base::els_gen_py() const{
  if(!c_els_gen_py_ && b_els_gen_py_){
    b_els_gen_py_->SetStatus(true);
    chainB_.SetBranchAddress("els_gen_py", &els_gen_py_, &b_els_gen_py_);
    b_els_gen_py_->GetEntry(entry_);
    c_els_gen_py_ = true;
  }
  return els_gen_py_;
}

std::vector<float>* const & cfa_base::els_gen_pz() const{
  if(!c_els_gen_pz_ && b_els_gen_pz_){
    b_els_gen_pz_->SetStatus(true);
    chainB_.SetBranchAddress("els_gen_pz", &els_gen_pz_, &b_els_gen_pz_);
    b_els_gen_pz_->GetEntry(entry_);
    c_els_gen_pz_ = true;
  }
  return els_gen_pz_;
}

std::vector<float>* const & cfa_base::els_gen_theta() const{
  if(!c_els_gen_theta_ && b_els_gen_theta_){
    b_els_gen_theta_->SetStatus(true);
    chainB_.SetBranchAddress("els_gen_theta", &els_gen_theta_, &b_els_gen_theta_);
    b_els_gen_theta_->GetEntry(entry_);
    c_els_gen_theta_ = true;
  }
  return els_gen_theta_;
}

std::vector<float>* const & cfa_base::els_hadOverEm() const{
  if(!c_els_hadOverEm_ && b_els_hadOverEm_){
    b_els_hadOverEm_->SetStatus(true);
    chainB_.SetBranchAddress("els_hadOverEm", &els_hadOverEm_, &b_els_hadOverEm_);
    b_els_hadOverEm_->GetEntry(entry_);
    c_els_hadOverEm_ = true;
  }
  return els_hadOverEm_;
}

std::vector<float>* const & cfa_base::els_hcalIso() const{
  if(!c_els_hcalIso_ && b_els_hcalIso_){
    b_els_hcalIso_->SetStatus(true);
    chainB_.SetBranchAddress("els_hcalIso", &els_hcalIso_, &b_els_hcalIso_);
    b_els_hcalIso_->GetEntry(entry_);
    c_els_hcalIso_ = true;
  }
  return els_hcalIso_;
}

std::vector<float>* const & cfa_base::els_hcalOverEcalBc() const{
  if(!c_els_hcalOverEcalBc_ && b_els_hcalOverEcalBc_){
    b_els_hcalOverEcalBc_->SetStatus(true);
    chainB_.SetBranchAddress("els_hcalOverEcalBc", &els_hcalOverEcalBc_, &b_els_hcalOverEcalBc_);
    b_els_hcalOverEcalBc_->GetEntry(entry_);
    c_els_hcalOverEcalBc_ = true;
  }
  return els_hcalOverEcalBc_;
}

std::vector<float>* const & cfa_base::els_isEB() const{
  if(!c_els_isEB_ && b_els_isEB_){
    b_els_isEB_->SetStatus(true);
    chainB_.SetBranchAddress("els_isEB", &els_isEB_, &b_els_isEB_);
    b_els_isEB_->GetEntry(entry_);
    c_els_isEB_ = true;
  }
  return els_isEB_;
}

std::vector<float>* const & cfa_base::els_isEE() const{
  if(!c_els_isEE_ && b_els_isEE_){
    b_els_isEE_->SetStatus(true);
    chainB_.SetBranchAddress("els_isEE", &els_isEE_, &b_els_isEE_);
    b_els_isEE_->GetEntry(entry_);
    c_els_isEE_ = true;
  }
  return els_isEE_;
}

std::vector<float>* const & cfa_base::els_looseId() const{
  if(!c_els_looseId_ && b_els_looseId_){
    b_els_looseId_->SetStatus(true);
    chainB_.SetBranchAddress("els_looseId", &els_looseId_, &b_els_looseId_);
    b_els_looseId_->GetEntry(entry_);
    c_els_looseId_ = true;
  }
  return els_looseId_;
}

std::vector<float>* const & cfa_base::els_n_inner_layer() const{
  if(!c_els_n_inner_layer_ && b_els_n_inner_layer_){
    b_els_n_inner_layer_->SetStatus(true);
    chainB_.SetBranchAddress("els_n_inner_layer", &els_n_inner_layer_, &b_els_n_inner_layer_);
    b_els_n_inner_layer_->GetEntry(entry_);
    c_els_n_inner_layer_ = true;
  }
  return els_n_inner_layer_;
}

std::vector<float>* const & cfa_base::els_n_outer_layer() const{
  if(!c_els_n_outer_layer_ && b_els_n_outer_layer_){
    b_els_n_outer_layer_->SetStatus(true);
    chainB_.SetBranchAddress("els_n_outer_layer", &els_n_outer_layer_, &b_els_n_outer_layer_);
    b_els_n_outer_layer_->GetEntry(entry_);
    c_els_n_outer_layer_ = true;
  }
  return els_n_outer_layer_;
}

std::vector<float>* const & cfa_base::els_ndof() const{
  if(!c_els_ndof_ && b_els_ndof_){
    b_els_ndof_->SetStatus(true);
    chainB_.SetBranchAddress("els_ndof", &els_ndof_, &b_els_ndof_);
    b_els_ndof_->GetEntry(entry_);
    c_els_ndof_ = true;
  }
  return els_ndof_;
}

std::vector<float>* const & cfa_base::els_numlosthits() const{
  if(!c_els_numlosthits_ && b_els_numlosthits_){
    b_els_numlosthits_->SetStatus(true);
    chainB_.SetBranchAddress("els_numlosthits", &els_numlosthits_, &b_els_numlosthits_);
    b_els_numlosthits_->GetEntry(entry_);
    c_els_numlosthits_ = true;
  }
  return els_numlosthits_;
}

std::vector<float>* const & cfa_base::els_numvalhits() const{
  if(!c_els_numvalhits_ && b_els_numvalhits_){
    b_els_numvalhits_->SetStatus(true);
    chainB_.SetBranchAddress("els_numvalhits", &els_numvalhits_, &b_els_numvalhits_);
    b_els_numvalhits_->GetEntry(entry_);
    c_els_numvalhits_ = true;
  }
  return els_numvalhits_;
}

std::vector<float>* const & cfa_base::els_phi() const{
  if(!c_els_phi_ && b_els_phi_){
    b_els_phi_->SetStatus(true);
    chainB_.SetBranchAddress("els_phi", &els_phi_, &b_els_phi_);
    b_els_phi_->GetEntry(entry_);
    c_els_phi_ = true;
  }
  return els_phi_;
}

std::vector<float>* const & cfa_base::els_phiError() const{
  if(!c_els_phiError_ && b_els_phiError_){
    b_els_phiError_->SetStatus(true);
    chainB_.SetBranchAddress("els_phiError", &els_phiError_, &b_els_phiError_);
    b_els_phiError_->GetEntry(entry_);
    c_els_phiError_ = true;
  }
  return els_phiError_;
}

std::vector<float>* const & cfa_base::els_pt() const{
  if(!c_els_pt_ && b_els_pt_){
    b_els_pt_->SetStatus(true);
    chainB_.SetBranchAddress("els_pt", &els_pt_, &b_els_pt_);
    b_els_pt_->GetEntry(entry_);
    c_els_pt_ = true;
  }
  return els_pt_;
}

std::vector<float>* const & cfa_base::els_ptError() const{
  if(!c_els_ptError_ && b_els_ptError_){
    b_els_ptError_->SetStatus(true);
    chainB_.SetBranchAddress("els_ptError", &els_ptError_, &b_els_ptError_);
    b_els_ptError_->GetEntry(entry_);
    c_els_ptError_ = true;
  }
  return els_ptError_;
}

std::vector<float>* const & cfa_base::els_px() const{
  if(!c_els_px_ && b_els_px_){
    b_els_px_->SetStatus(true);
    chainB_.SetBranchAddress("els_px", &els_px_, &b_els_px_);
    b_els_px_->GetEntry(entry_);
    c_els_px_ = true;
  }
  return els_px_;
}

std::vector<float>* const & cfa_base::els_py() const{
  if(!c_els_py_ && b_els_py_){
    b_els_py_->SetStatus(true);
    chainB_.SetBranchAddress("els_py", &els_py_, &b_els_py_);
    b_els_py_->GetEntry(entry_);
    c_els_py_ = true;
  }
  return els_py_;
}

std::vector<float>* const & cfa_base::els_pz() const{
  if(!c_els_pz_ && b_els_pz_){
    b_els_pz_->SetStatus(true);
    chainB_.SetBranchAddress("els_pz", &els_pz_, &b_els_pz_);
    b_els_pz_->GetEntry(entry_);
    c_els_pz_ = true;
  }
  return els_pz_;
}

std::vector<float>* const & cfa_base::els_robustHighEnergyId() const{
  if(!c_els_robustHighEnergyId_ && b_els_robustHighEnergyId_){
    b_els_robustHighEnergyId_->SetStatus(true);
    chainB_.SetBranchAddress("els_robustHighEnergyId", &els_robustHighEnergyId_, &b_els_robustHighEnergyId_);
    b_els_robustHighEnergyId_->GetEntry(entry_);
    c_els_robustHighEnergyId_ = true;
  }
  return els_robustHighEnergyId_;
}

std::vector<float>* const & cfa_base::els_robustLooseId() const{
  if(!c_els_robustLooseId_ && b_els_robustLooseId_){
    b_els_robustLooseId_->SetStatus(true);
    chainB_.SetBranchAddress("els_robustLooseId", &els_robustLooseId_, &b_els_robustLooseId_);
    b_els_robustLooseId_->GetEntry(entry_);
    c_els_robustLooseId_ = true;
  }
  return els_robustLooseId_;
}

std::vector<float>* const & cfa_base::els_robustTightId() const{
  if(!c_els_robustTightId_ && b_els_robustTightId_){
    b_els_robustTightId_->SetStatus(true);
    chainB_.SetBranchAddress("els_robustTightId", &els_robustTightId_, &b_els_robustTightId_);
    b_els_robustTightId_->GetEntry(entry_);
    c_els_robustTightId_ = true;
  }
  return els_robustTightId_;
}

std::vector<float>* const & cfa_base::els_scE1x5() const{
  if(!c_els_scE1x5_ && b_els_scE1x5_){
    b_els_scE1x5_->SetStatus(true);
    chainB_.SetBranchAddress("els_scE1x5", &els_scE1x5_, &b_els_scE1x5_);
    b_els_scE1x5_->GetEntry(entry_);
    c_els_scE1x5_ = true;
  }
  return els_scE1x5_;
}

std::vector<float>* const & cfa_base::els_scE2x5Max() const{
  if(!c_els_scE2x5Max_ && b_els_scE2x5Max_){
    b_els_scE2x5Max_->SetStatus(true);
    chainB_.SetBranchAddress("els_scE2x5Max", &els_scE2x5Max_, &b_els_scE2x5Max_);
    b_els_scE2x5Max_->GetEntry(entry_);
    c_els_scE2x5Max_ = true;
  }
  return els_scE2x5Max_;
}

std::vector<float>* const & cfa_base::els_scE5x5() const{
  if(!c_els_scE5x5_ && b_els_scE5x5_){
    b_els_scE5x5_->SetStatus(true);
    chainB_.SetBranchAddress("els_scE5x5", &els_scE5x5_, &b_els_scE5x5_);
    b_els_scE5x5_->GetEntry(entry_);
    c_els_scE5x5_ = true;
  }
  return els_scE5x5_;
}

std::vector<float>* const & cfa_base::els_scEnergy() const{
  if(!c_els_scEnergy_ && b_els_scEnergy_){
    b_els_scEnergy_->SetStatus(true);
    chainB_.SetBranchAddress("els_scEnergy", &els_scEnergy_, &b_els_scEnergy_);
    b_els_scEnergy_->GetEntry(entry_);
    c_els_scEnergy_ = true;
  }
  return els_scEnergy_;
}

std::vector<float>* const & cfa_base::els_scEta() const{
  if(!c_els_scEta_ && b_els_scEta_){
    b_els_scEta_->SetStatus(true);
    chainB_.SetBranchAddress("els_scEta", &els_scEta_, &b_els_scEta_);
    b_els_scEta_->GetEntry(entry_);
    c_els_scEta_ = true;
  }
  return els_scEta_;
}

std::vector<float>* const & cfa_base::els_scEtaWidth() const{
  if(!c_els_scEtaWidth_ && b_els_scEtaWidth_){
    b_els_scEtaWidth_->SetStatus(true);
    chainB_.SetBranchAddress("els_scEtaWidth", &els_scEtaWidth_, &b_els_scEtaWidth_);
    b_els_scEtaWidth_->GetEntry(entry_);
    c_els_scEtaWidth_ = true;
  }
  return els_scEtaWidth_;
}

std::vector<float>* const & cfa_base::els_scPhi() const{
  if(!c_els_scPhi_ && b_els_scPhi_){
    b_els_scPhi_->SetStatus(true);
    chainB_.SetBranchAddress("els_scPhi", &els_scPhi_, &b_els_scPhi_);
    b_els_scPhi_->GetEntry(entry_);
    c_els_scPhi_ = true;
  }
  return els_scPhi_;
}

std::vector<float>* const & cfa_base::els_scPhiWidth() const{
  if(!c_els_scPhiWidth_ && b_els_scPhiWidth_){
    b_els_scPhiWidth_->SetStatus(true);
    chainB_.SetBranchAddress("els_scPhiWidth", &els_scPhiWidth_, &b_els_scPhiWidth_);
    b_els_scPhiWidth_->GetEntry(entry_);
    c_els_scPhiWidth_ = true;
  }
  return els_scPhiWidth_;
}

std::vector<float>* const & cfa_base::els_scRawEnergy() const{
  if(!c_els_scRawEnergy_ && b_els_scRawEnergy_){
    b_els_scRawEnergy_->SetStatus(true);
    chainB_.SetBranchAddress("els_scRawEnergy", &els_scRawEnergy_, &b_els_scRawEnergy_);
    b_els_scRawEnergy_->GetEntry(entry_);
    c_els_scRawEnergy_ = true;
  }
  return els_scRawEnergy_;
}

std::vector<float>* const & cfa_base::els_scSeedEnergy() const{
  if(!c_els_scSeedEnergy_ && b_els_scSeedEnergy_){
    b_els_scSeedEnergy_->SetStatus(true);
    chainB_.SetBranchAddress("els_scSeedEnergy", &els_scSeedEnergy_, &b_els_scSeedEnergy_);
    b_els_scSeedEnergy_->GetEntry(entry_);
    c_els_scSeedEnergy_ = true;
  }
  return els_scSeedEnergy_;
}

std::vector<float>* const & cfa_base::els_shFracInnerHits() const{
  if(!c_els_shFracInnerHits_ && b_els_shFracInnerHits_){
    b_els_shFracInnerHits_->SetStatus(true);
    chainB_.SetBranchAddress("els_shFracInnerHits", &els_shFracInnerHits_, &b_els_shFracInnerHits_);
    b_els_shFracInnerHits_->GetEntry(entry_);
    c_els_shFracInnerHits_ = true;
  }
  return els_shFracInnerHits_;
}

std::vector<float>* const & cfa_base::els_sigmaEtaEta() const{
  if(!c_els_sigmaEtaEta_ && b_els_sigmaEtaEta_){
    b_els_sigmaEtaEta_->SetStatus(true);
    chainB_.SetBranchAddress("els_sigmaEtaEta", &els_sigmaEtaEta_, &b_els_sigmaEtaEta_);
    b_els_sigmaEtaEta_->GetEntry(entry_);
    c_els_sigmaEtaEta_ = true;
  }
  return els_sigmaEtaEta_;
}

std::vector<float>* const & cfa_base::els_sigmaIEtaIEta() const{
  if(!c_els_sigmaIEtaIEta_ && b_els_sigmaIEtaIEta_){
    b_els_sigmaIEtaIEta_->SetStatus(true);
    chainB_.SetBranchAddress("els_sigmaIEtaIEta", &els_sigmaIEtaIEta_, &b_els_sigmaIEtaIEta_);
    b_els_sigmaIEtaIEta_->GetEntry(entry_);
    c_els_sigmaIEtaIEta_ = true;
  }
  return els_sigmaIEtaIEta_;
}

std::vector<float>* const & cfa_base::els_simpleEleId60cIso() const{
  if(!c_els_simpleEleId60cIso_ && b_els_simpleEleId60cIso_){
    b_els_simpleEleId60cIso_->SetStatus(true);
    chainB_.SetBranchAddress("els_simpleEleId60cIso", &els_simpleEleId60cIso_, &b_els_simpleEleId60cIso_);
    b_els_simpleEleId60cIso_->GetEntry(entry_);
    c_els_simpleEleId60cIso_ = true;
  }
  return els_simpleEleId60cIso_;
}

std::vector<float>* const & cfa_base::els_simpleEleId60relIso() const{
  if(!c_els_simpleEleId60relIso_ && b_els_simpleEleId60relIso_){
    b_els_simpleEleId60relIso_->SetStatus(true);
    chainB_.SetBranchAddress("els_simpleEleId60relIso", &els_simpleEleId60relIso_, &b_els_simpleEleId60relIso_);
    b_els_simpleEleId60relIso_->GetEntry(entry_);
    c_els_simpleEleId60relIso_ = true;
  }
  return els_simpleEleId60relIso_;
}

std::vector<float>* const & cfa_base::els_simpleEleId70cIso() const{
  if(!c_els_simpleEleId70cIso_ && b_els_simpleEleId70cIso_){
    b_els_simpleEleId70cIso_->SetStatus(true);
    chainB_.SetBranchAddress("els_simpleEleId70cIso", &els_simpleEleId70cIso_, &b_els_simpleEleId70cIso_);
    b_els_simpleEleId70cIso_->GetEntry(entry_);
    c_els_simpleEleId70cIso_ = true;
  }
  return els_simpleEleId70cIso_;
}

std::vector<float>* const & cfa_base::els_simpleEleId70relIso() const{
  if(!c_els_simpleEleId70relIso_ && b_els_simpleEleId70relIso_){
    b_els_simpleEleId70relIso_->SetStatus(true);
    chainB_.SetBranchAddress("els_simpleEleId70relIso", &els_simpleEleId70relIso_, &b_els_simpleEleId70relIso_);
    b_els_simpleEleId70relIso_->GetEntry(entry_);
    c_els_simpleEleId70relIso_ = true;
  }
  return els_simpleEleId70relIso_;
}

std::vector<float>* const & cfa_base::els_simpleEleId80cIso() const{
  if(!c_els_simpleEleId80cIso_ && b_els_simpleEleId80cIso_){
    b_els_simpleEleId80cIso_->SetStatus(true);
    chainB_.SetBranchAddress("els_simpleEleId80cIso", &els_simpleEleId80cIso_, &b_els_simpleEleId80cIso_);
    b_els_simpleEleId80cIso_->GetEntry(entry_);
    c_els_simpleEleId80cIso_ = true;
  }
  return els_simpleEleId80cIso_;
}

std::vector<float>* const & cfa_base::els_simpleEleId80relIso() const{
  if(!c_els_simpleEleId80relIso_ && b_els_simpleEleId80relIso_){
    b_els_simpleEleId80relIso_->SetStatus(true);
    chainB_.SetBranchAddress("els_simpleEleId80relIso", &els_simpleEleId80relIso_, &b_els_simpleEleId80relIso_);
    b_els_simpleEleId80relIso_->GetEntry(entry_);
    c_els_simpleEleId80relIso_ = true;
  }
  return els_simpleEleId80relIso_;
}

std::vector<float>* const & cfa_base::els_simpleEleId85cIso() const{
  if(!c_els_simpleEleId85cIso_ && b_els_simpleEleId85cIso_){
    b_els_simpleEleId85cIso_->SetStatus(true);
    chainB_.SetBranchAddress("els_simpleEleId85cIso", &els_simpleEleId85cIso_, &b_els_simpleEleId85cIso_);
    b_els_simpleEleId85cIso_->GetEntry(entry_);
    c_els_simpleEleId85cIso_ = true;
  }
  return els_simpleEleId85cIso_;
}

std::vector<float>* const & cfa_base::els_simpleEleId85relIso() const{
  if(!c_els_simpleEleId85relIso_ && b_els_simpleEleId85relIso_){
    b_els_simpleEleId85relIso_->SetStatus(true);
    chainB_.SetBranchAddress("els_simpleEleId85relIso", &els_simpleEleId85relIso_, &b_els_simpleEleId85relIso_);
    b_els_simpleEleId85relIso_->GetEntry(entry_);
    c_els_simpleEleId85relIso_ = true;
  }
  return els_simpleEleId85relIso_;
}

std::vector<float>* const & cfa_base::els_simpleEleId90cIso() const{
  if(!c_els_simpleEleId90cIso_ && b_els_simpleEleId90cIso_){
    b_els_simpleEleId90cIso_->SetStatus(true);
    chainB_.SetBranchAddress("els_simpleEleId90cIso", &els_simpleEleId90cIso_, &b_els_simpleEleId90cIso_);
    b_els_simpleEleId90cIso_->GetEntry(entry_);
    c_els_simpleEleId90cIso_ = true;
  }
  return els_simpleEleId90cIso_;
}

std::vector<float>* const & cfa_base::els_simpleEleId90relIso() const{
  if(!c_els_simpleEleId90relIso_ && b_els_simpleEleId90relIso_){
    b_els_simpleEleId90relIso_->SetStatus(true);
    chainB_.SetBranchAddress("els_simpleEleId90relIso", &els_simpleEleId90relIso_, &b_els_simpleEleId90relIso_);
    b_els_simpleEleId90relIso_->GetEntry(entry_);
    c_els_simpleEleId90relIso_ = true;
  }
  return els_simpleEleId90relIso_;
}

std::vector<float>* const & cfa_base::els_simpleEleId95cIso() const{
  if(!c_els_simpleEleId95cIso_ && b_els_simpleEleId95cIso_){
    b_els_simpleEleId95cIso_->SetStatus(true);
    chainB_.SetBranchAddress("els_simpleEleId95cIso", &els_simpleEleId95cIso_, &b_els_simpleEleId95cIso_);
    b_els_simpleEleId95cIso_->GetEntry(entry_);
    c_els_simpleEleId95cIso_ = true;
  }
  return els_simpleEleId95cIso_;
}

std::vector<float>* const & cfa_base::els_simpleEleId95relIso() const{
  if(!c_els_simpleEleId95relIso_ && b_els_simpleEleId95relIso_){
    b_els_simpleEleId95relIso_->SetStatus(true);
    chainB_.SetBranchAddress("els_simpleEleId95relIso", &els_simpleEleId95relIso_, &b_els_simpleEleId95relIso_);
    b_els_simpleEleId95relIso_->GetEntry(entry_);
    c_els_simpleEleId95relIso_ = true;
  }
  return els_simpleEleId95relIso_;
}

std::vector<float>* const & cfa_base::els_status() const{
  if(!c_els_status_ && b_els_status_){
    b_els_status_->SetStatus(true);
    chainB_.SetBranchAddress("els_status", &els_status_, &b_els_status_);
    b_els_status_->GetEntry(entry_);
    c_els_status_ = true;
  }
  return els_status_;
}

std::vector<float>* const & cfa_base::els_tIso() const{
  if(!c_els_tIso_ && b_els_tIso_){
    b_els_tIso_->SetStatus(true);
    chainB_.SetBranchAddress("els_tIso", &els_tIso_, &b_els_tIso_);
    b_els_tIso_->GetEntry(entry_);
    c_els_tIso_ = true;
  }
  return els_tIso_;
}

std::vector<float>* const & cfa_base::els_theta() const{
  if(!c_els_theta_ && b_els_theta_){
    b_els_theta_->SetStatus(true);
    chainB_.SetBranchAddress("els_theta", &els_theta_, &b_els_theta_);
    b_els_theta_->GetEntry(entry_);
    c_els_theta_ = true;
  }
  return els_theta_;
}

std::vector<float>* const & cfa_base::els_tightId() const{
  if(!c_els_tightId_ && b_els_tightId_){
    b_els_tightId_->SetStatus(true);
    chainB_.SetBranchAddress("els_tightId", &els_tightId_, &b_els_tightId_);
    b_els_tightId_->GetEntry(entry_);
    c_els_tightId_ = true;
  }
  return els_tightId_;
}

std::vector<float>* const & cfa_base::els_tk_charge() const{
  if(!c_els_tk_charge_ && b_els_tk_charge_){
    b_els_tk_charge_->SetStatus(true);
    chainB_.SetBranchAddress("els_tk_charge", &els_tk_charge_, &b_els_tk_charge_);
    b_els_tk_charge_->GetEntry(entry_);
    c_els_tk_charge_ = true;
  }
  return els_tk_charge_;
}

std::vector<float>* const & cfa_base::els_tk_eta() const{
  if(!c_els_tk_eta_ && b_els_tk_eta_){
    b_els_tk_eta_->SetStatus(true);
    chainB_.SetBranchAddress("els_tk_eta", &els_tk_eta_, &b_els_tk_eta_);
    b_els_tk_eta_->GetEntry(entry_);
    c_els_tk_eta_ = true;
  }
  return els_tk_eta_;
}

std::vector<float>* const & cfa_base::els_tk_phi() const{
  if(!c_els_tk_phi_ && b_els_tk_phi_){
    b_els_tk_phi_->SetStatus(true);
    chainB_.SetBranchAddress("els_tk_phi", &els_tk_phi_, &b_els_tk_phi_);
    b_els_tk_phi_->GetEntry(entry_);
    c_els_tk_phi_ = true;
  }
  return els_tk_phi_;
}

std::vector<float>* const & cfa_base::els_tk_pt() const{
  if(!c_els_tk_pt_ && b_els_tk_pt_){
    b_els_tk_pt_->SetStatus(true);
    chainB_.SetBranchAddress("els_tk_pt", &els_tk_pt_, &b_els_tk_pt_);
    b_els_tk_pt_->GetEntry(entry_);
    c_els_tk_pt_ = true;
  }
  return els_tk_pt_;
}

std::vector<float>* const & cfa_base::els_tk_pz() const{
  if(!c_els_tk_pz_ && b_els_tk_pz_){
    b_els_tk_pz_->SetStatus(true);
    chainB_.SetBranchAddress("els_tk_pz", &els_tk_pz_, &b_els_tk_pz_);
    b_els_tk_pz_->GetEntry(entry_);
    c_els_tk_pz_ = true;
  }
  return els_tk_pz_;
}

std::vector<float>* const & cfa_base::els_vpx() const{
  if(!c_els_vpx_ && b_els_vpx_){
    b_els_vpx_->SetStatus(true);
    chainB_.SetBranchAddress("els_vpx", &els_vpx_, &b_els_vpx_);
    b_els_vpx_->GetEntry(entry_);
    c_els_vpx_ = true;
  }
  return els_vpx_;
}

std::vector<float>* const & cfa_base::els_vpy() const{
  if(!c_els_vpy_ && b_els_vpy_){
    b_els_vpy_->SetStatus(true);
    chainB_.SetBranchAddress("els_vpy", &els_vpy_, &b_els_vpy_);
    b_els_vpy_->GetEntry(entry_);
    c_els_vpy_ = true;
  }
  return els_vpy_;
}

std::vector<float>* const & cfa_base::els_vpz() const{
  if(!c_els_vpz_ && b_els_vpz_){
    b_els_vpz_->SetStatus(true);
    chainB_.SetBranchAddress("els_vpz", &els_vpz_, &b_els_vpz_);
    b_els_vpz_->GetEntry(entry_);
    c_els_vpz_ = true;
  }
  return els_vpz_;
}

std::vector<float>* const & cfa_base::els_vx() const{
  if(!c_els_vx_ && b_els_vx_){
    b_els_vx_->SetStatus(true);
    chainB_.SetBranchAddress("els_vx", &els_vx_, &b_els_vx_);
    b_els_vx_->GetEntry(entry_);
    c_els_vx_ = true;
  }
  return els_vx_;
}

std::vector<float>* const & cfa_base::els_vy() const{
  if(!c_els_vy_ && b_els_vy_){
    b_els_vy_->SetStatus(true);
    chainB_.SetBranchAddress("els_vy", &els_vy_, &b_els_vy_);
    b_els_vy_->GetEntry(entry_);
    c_els_vy_ = true;
  }
  return els_vy_;
}

std::vector<float>* const & cfa_base::els_vz() const{
  if(!c_els_vz_ && b_els_vz_){
    b_els_vz_->SetStatus(true);
    chainB_.SetBranchAddress("els_vz", &els_vz_, &b_els_vz_);
    b_els_vz_->GetEntry(entry_);
    c_els_vz_ = true;
  }
  return els_vz_;
}

UInt_t const & cfa_base::event() const{
  if(!c_event_ && b_event_){
    b_event_->SetStatus(true);
    chainB_.SetBranchAddress("event", &event_, &b_event_);
    b_event_->GetEntry(entry_);
    c_event_ = true;
  }
  return event_;
}

UInt_t const & cfa_base::experimentType() const{
  if(!c_experimentType_ && b_experimentType_){
    b_experimentType_->SetStatus(true);
    chainB_.SetBranchAddress("experimentType", &experimentType_, &b_experimentType_);
    b_experimentType_->GetEntry(entry_);
    c_experimentType_ = true;
  }
  return experimentType_;
}

Int_t const & cfa_base::hcallaserfilter_decision() const{
  if(!c_hcallaserfilter_decision_ && b_hcallaserfilter_decision_){
    b_hcallaserfilter_decision_->SetStatus(true);
    chainA_.SetBranchAddress("hcallaserfilter_decision", &hcallaserfilter_decision_, &b_hcallaserfilter_decision_);
    b_hcallaserfilter_decision_->GetEntry(entry_);
    c_hcallaserfilter_decision_ = true;
  }
  return hcallaserfilter_decision_;
}

UInt_t const & cfa_base::lumiblock() const{
  if(!c_lumiblock_ && b_lumiblock_){
    b_lumiblock_->SetStatus(true);
    chainB_.SetBranchAddress("lumiblock", &lumiblock_, &b_lumiblock_);
    b_lumiblock_->GetEntry(entry_);
    c_lumiblock_ = true;
  }
  return lumiblock_;
}

std::vector<float>* const & cfa_base::mc_doc_charge() const{
  if(!c_mc_doc_charge_ && b_mc_doc_charge_){
    b_mc_doc_charge_->SetStatus(true);
    chainB_.SetBranchAddress("mc_doc_charge", &mc_doc_charge_, &b_mc_doc_charge_);
    b_mc_doc_charge_->GetEntry(entry_);
    c_mc_doc_charge_ = true;
  }
  return mc_doc_charge_;
}

std::vector<float>* const & cfa_base::mc_doc_energy() const{
  if(!c_mc_doc_energy_ && b_mc_doc_energy_){
    b_mc_doc_energy_->SetStatus(true);
    chainB_.SetBranchAddress("mc_doc_energy", &mc_doc_energy_, &b_mc_doc_energy_);
    b_mc_doc_energy_->GetEntry(entry_);
    c_mc_doc_energy_ = true;
  }
  return mc_doc_energy_;
}

std::vector<float>* const & cfa_base::mc_doc_eta() const{
  if(!c_mc_doc_eta_ && b_mc_doc_eta_){
    b_mc_doc_eta_->SetStatus(true);
    chainB_.SetBranchAddress("mc_doc_eta", &mc_doc_eta_, &b_mc_doc_eta_);
    b_mc_doc_eta_->GetEntry(entry_);
    c_mc_doc_eta_ = true;
  }
  return mc_doc_eta_;
}

std::vector<float>* const & cfa_base::mc_doc_ggrandmother_id() const{
  if(!c_mc_doc_ggrandmother_id_ && b_mc_doc_ggrandmother_id_){
    b_mc_doc_ggrandmother_id_->SetStatus(true);
    chainB_.SetBranchAddress("mc_doc_ggrandmother_id", &mc_doc_ggrandmother_id_, &b_mc_doc_ggrandmother_id_);
    b_mc_doc_ggrandmother_id_->GetEntry(entry_);
    c_mc_doc_ggrandmother_id_ = true;
  }
  return mc_doc_ggrandmother_id_;
}

std::vector<float>* const & cfa_base::mc_doc_grandmother_id() const{
  if(!c_mc_doc_grandmother_id_ && b_mc_doc_grandmother_id_){
    b_mc_doc_grandmother_id_->SetStatus(true);
    chainB_.SetBranchAddress("mc_doc_grandmother_id", &mc_doc_grandmother_id_, &b_mc_doc_grandmother_id_);
    b_mc_doc_grandmother_id_->GetEntry(entry_);
    c_mc_doc_grandmother_id_ = true;
  }
  return mc_doc_grandmother_id_;
}

std::vector<float>* const & cfa_base::mc_doc_id() const{
  if(!c_mc_doc_id_ && b_mc_doc_id_){
    b_mc_doc_id_->SetStatus(true);
    chainB_.SetBranchAddress("mc_doc_id", &mc_doc_id_, &b_mc_doc_id_);
    b_mc_doc_id_->GetEntry(entry_);
    c_mc_doc_id_ = true;
  }
  return mc_doc_id_;
}

std::vector<float>* const & cfa_base::mc_doc_mass() const{
  if(!c_mc_doc_mass_ && b_mc_doc_mass_){
    b_mc_doc_mass_->SetStatus(true);
    chainB_.SetBranchAddress("mc_doc_mass", &mc_doc_mass_, &b_mc_doc_mass_);
    b_mc_doc_mass_->GetEntry(entry_);
    c_mc_doc_mass_ = true;
  }
  return mc_doc_mass_;
}

std::vector<float>* const & cfa_base::mc_doc_mother_id() const{
  if(!c_mc_doc_mother_id_ && b_mc_doc_mother_id_){
    b_mc_doc_mother_id_->SetStatus(true);
    chainB_.SetBranchAddress("mc_doc_mother_id", &mc_doc_mother_id_, &b_mc_doc_mother_id_);
    b_mc_doc_mother_id_->GetEntry(entry_);
    c_mc_doc_mother_id_ = true;
  }
  return mc_doc_mother_id_;
}

std::vector<float>* const & cfa_base::mc_doc_mother_pt() const{
  if(!c_mc_doc_mother_pt_ && b_mc_doc_mother_pt_){
    b_mc_doc_mother_pt_->SetStatus(true);
    chainB_.SetBranchAddress("mc_doc_mother_pt", &mc_doc_mother_pt_, &b_mc_doc_mother_pt_);
    b_mc_doc_mother_pt_->GetEntry(entry_);
    c_mc_doc_mother_pt_ = true;
  }
  return mc_doc_mother_pt_;
}

std::vector<float>* const & cfa_base::mc_doc_numOfDaughters() const{
  if(!c_mc_doc_numOfDaughters_ && b_mc_doc_numOfDaughters_){
    b_mc_doc_numOfDaughters_->SetStatus(true);
    chainB_.SetBranchAddress("mc_doc_numOfDaughters", &mc_doc_numOfDaughters_, &b_mc_doc_numOfDaughters_);
    b_mc_doc_numOfDaughters_->GetEntry(entry_);
    c_mc_doc_numOfDaughters_ = true;
  }
  return mc_doc_numOfDaughters_;
}

std::vector<float>* const & cfa_base::mc_doc_numOfMothers() const{
  if(!c_mc_doc_numOfMothers_ && b_mc_doc_numOfMothers_){
    b_mc_doc_numOfMothers_->SetStatus(true);
    chainB_.SetBranchAddress("mc_doc_numOfMothers", &mc_doc_numOfMothers_, &b_mc_doc_numOfMothers_);
    b_mc_doc_numOfMothers_->GetEntry(entry_);
    c_mc_doc_numOfMothers_ = true;
  }
  return mc_doc_numOfMothers_;
}

std::vector<float>* const & cfa_base::mc_doc_phi() const{
  if(!c_mc_doc_phi_ && b_mc_doc_phi_){
    b_mc_doc_phi_->SetStatus(true);
    chainB_.SetBranchAddress("mc_doc_phi", &mc_doc_phi_, &b_mc_doc_phi_);
    b_mc_doc_phi_->GetEntry(entry_);
    c_mc_doc_phi_ = true;
  }
  return mc_doc_phi_;
}

std::vector<float>* const & cfa_base::mc_doc_pt() const{
  if(!c_mc_doc_pt_ && b_mc_doc_pt_){
    b_mc_doc_pt_->SetStatus(true);
    chainB_.SetBranchAddress("mc_doc_pt", &mc_doc_pt_, &b_mc_doc_pt_);
    b_mc_doc_pt_->GetEntry(entry_);
    c_mc_doc_pt_ = true;
  }
  return mc_doc_pt_;
}

std::vector<float>* const & cfa_base::mc_doc_px() const{
  if(!c_mc_doc_px_ && b_mc_doc_px_){
    b_mc_doc_px_->SetStatus(true);
    chainB_.SetBranchAddress("mc_doc_px", &mc_doc_px_, &b_mc_doc_px_);
    b_mc_doc_px_->GetEntry(entry_);
    c_mc_doc_px_ = true;
  }
  return mc_doc_px_;
}

std::vector<float>* const & cfa_base::mc_doc_py() const{
  if(!c_mc_doc_py_ && b_mc_doc_py_){
    b_mc_doc_py_->SetStatus(true);
    chainB_.SetBranchAddress("mc_doc_py", &mc_doc_py_, &b_mc_doc_py_);
    b_mc_doc_py_->GetEntry(entry_);
    c_mc_doc_py_ = true;
  }
  return mc_doc_py_;
}

std::vector<float>* const & cfa_base::mc_doc_pz() const{
  if(!c_mc_doc_pz_ && b_mc_doc_pz_){
    b_mc_doc_pz_->SetStatus(true);
    chainB_.SetBranchAddress("mc_doc_pz", &mc_doc_pz_, &b_mc_doc_pz_);
    b_mc_doc_pz_->GetEntry(entry_);
    c_mc_doc_pz_ = true;
  }
  return mc_doc_pz_;
}

std::vector<float>* const & cfa_base::mc_doc_status() const{
  if(!c_mc_doc_status_ && b_mc_doc_status_){
    b_mc_doc_status_->SetStatus(true);
    chainB_.SetBranchAddress("mc_doc_status", &mc_doc_status_, &b_mc_doc_status_);
    b_mc_doc_status_->GetEntry(entry_);
    c_mc_doc_status_ = true;
  }
  return mc_doc_status_;
}

std::vector<float>* const & cfa_base::mc_doc_theta() const{
  if(!c_mc_doc_theta_ && b_mc_doc_theta_){
    b_mc_doc_theta_->SetStatus(true);
    chainB_.SetBranchAddress("mc_doc_theta", &mc_doc_theta_, &b_mc_doc_theta_);
    b_mc_doc_theta_->GetEntry(entry_);
    c_mc_doc_theta_ = true;
  }
  return mc_doc_theta_;
}

std::vector<float>* const & cfa_base::mc_doc_vertex_x() const{
  if(!c_mc_doc_vertex_x_ && b_mc_doc_vertex_x_){
    b_mc_doc_vertex_x_->SetStatus(true);
    chainB_.SetBranchAddress("mc_doc_vertex_x", &mc_doc_vertex_x_, &b_mc_doc_vertex_x_);
    b_mc_doc_vertex_x_->GetEntry(entry_);
    c_mc_doc_vertex_x_ = true;
  }
  return mc_doc_vertex_x_;
}

std::vector<float>* const & cfa_base::mc_doc_vertex_y() const{
  if(!c_mc_doc_vertex_y_ && b_mc_doc_vertex_y_){
    b_mc_doc_vertex_y_->SetStatus(true);
    chainB_.SetBranchAddress("mc_doc_vertex_y", &mc_doc_vertex_y_, &b_mc_doc_vertex_y_);
    b_mc_doc_vertex_y_->GetEntry(entry_);
    c_mc_doc_vertex_y_ = true;
  }
  return mc_doc_vertex_y_;
}

std::vector<float>* const & cfa_base::mc_doc_vertex_z() const{
  if(!c_mc_doc_vertex_z_ && b_mc_doc_vertex_z_){
    b_mc_doc_vertex_z_->SetStatus(true);
    chainB_.SetBranchAddress("mc_doc_vertex_z", &mc_doc_vertex_z_, &b_mc_doc_vertex_z_);
    b_mc_doc_vertex_z_->GetEntry(entry_);
    c_mc_doc_vertex_z_ = true;
  }
  return mc_doc_vertex_z_;
}

std::vector<float>* const & cfa_base::mc_electrons_charge() const{
  if(!c_mc_electrons_charge_ && b_mc_electrons_charge_){
    b_mc_electrons_charge_->SetStatus(true);
    chainB_.SetBranchAddress("mc_electrons_charge", &mc_electrons_charge_, &b_mc_electrons_charge_);
    b_mc_electrons_charge_->GetEntry(entry_);
    c_mc_electrons_charge_ = true;
  }
  return mc_electrons_charge_;
}

std::vector<float>* const & cfa_base::mc_electrons_energy() const{
  if(!c_mc_electrons_energy_ && b_mc_electrons_energy_){
    b_mc_electrons_energy_->SetStatus(true);
    chainB_.SetBranchAddress("mc_electrons_energy", &mc_electrons_energy_, &b_mc_electrons_energy_);
    b_mc_electrons_energy_->GetEntry(entry_);
    c_mc_electrons_energy_ = true;
  }
  return mc_electrons_energy_;
}

std::vector<float>* const & cfa_base::mc_electrons_eta() const{
  if(!c_mc_electrons_eta_ && b_mc_electrons_eta_){
    b_mc_electrons_eta_->SetStatus(true);
    chainB_.SetBranchAddress("mc_electrons_eta", &mc_electrons_eta_, &b_mc_electrons_eta_);
    b_mc_electrons_eta_->GetEntry(entry_);
    c_mc_electrons_eta_ = true;
  }
  return mc_electrons_eta_;
}

std::vector<float>* const & cfa_base::mc_electrons_ggrandmother_id() const{
  if(!c_mc_electrons_ggrandmother_id_ && b_mc_electrons_ggrandmother_id_){
    b_mc_electrons_ggrandmother_id_->SetStatus(true);
    chainB_.SetBranchAddress("mc_electrons_ggrandmother_id", &mc_electrons_ggrandmother_id_, &b_mc_electrons_ggrandmother_id_);
    b_mc_electrons_ggrandmother_id_->GetEntry(entry_);
    c_mc_electrons_ggrandmother_id_ = true;
  }
  return mc_electrons_ggrandmother_id_;
}

std::vector<float>* const & cfa_base::mc_electrons_grandmother_id() const{
  if(!c_mc_electrons_grandmother_id_ && b_mc_electrons_grandmother_id_){
    b_mc_electrons_grandmother_id_->SetStatus(true);
    chainB_.SetBranchAddress("mc_electrons_grandmother_id", &mc_electrons_grandmother_id_, &b_mc_electrons_grandmother_id_);
    b_mc_electrons_grandmother_id_->GetEntry(entry_);
    c_mc_electrons_grandmother_id_ = true;
  }
  return mc_electrons_grandmother_id_;
}

std::vector<float>* const & cfa_base::mc_electrons_id() const{
  if(!c_mc_electrons_id_ && b_mc_electrons_id_){
    b_mc_electrons_id_->SetStatus(true);
    chainB_.SetBranchAddress("mc_electrons_id", &mc_electrons_id_, &b_mc_electrons_id_);
    b_mc_electrons_id_->GetEntry(entry_);
    c_mc_electrons_id_ = true;
  }
  return mc_electrons_id_;
}

std::vector<float>* const & cfa_base::mc_electrons_mass() const{
  if(!c_mc_electrons_mass_ && b_mc_electrons_mass_){
    b_mc_electrons_mass_->SetStatus(true);
    chainB_.SetBranchAddress("mc_electrons_mass", &mc_electrons_mass_, &b_mc_electrons_mass_);
    b_mc_electrons_mass_->GetEntry(entry_);
    c_mc_electrons_mass_ = true;
  }
  return mc_electrons_mass_;
}

std::vector<float>* const & cfa_base::mc_electrons_mother_id() const{
  if(!c_mc_electrons_mother_id_ && b_mc_electrons_mother_id_){
    b_mc_electrons_mother_id_->SetStatus(true);
    chainB_.SetBranchAddress("mc_electrons_mother_id", &mc_electrons_mother_id_, &b_mc_electrons_mother_id_);
    b_mc_electrons_mother_id_->GetEntry(entry_);
    c_mc_electrons_mother_id_ = true;
  }
  return mc_electrons_mother_id_;
}

std::vector<float>* const & cfa_base::mc_electrons_mother_pt() const{
  if(!c_mc_electrons_mother_pt_ && b_mc_electrons_mother_pt_){
    b_mc_electrons_mother_pt_->SetStatus(true);
    chainB_.SetBranchAddress("mc_electrons_mother_pt", &mc_electrons_mother_pt_, &b_mc_electrons_mother_pt_);
    b_mc_electrons_mother_pt_->GetEntry(entry_);
    c_mc_electrons_mother_pt_ = true;
  }
  return mc_electrons_mother_pt_;
}

std::vector<float>* const & cfa_base::mc_electrons_numOfDaughters() const{
  if(!c_mc_electrons_numOfDaughters_ && b_mc_electrons_numOfDaughters_){
    b_mc_electrons_numOfDaughters_->SetStatus(true);
    chainB_.SetBranchAddress("mc_electrons_numOfDaughters", &mc_electrons_numOfDaughters_, &b_mc_electrons_numOfDaughters_);
    b_mc_electrons_numOfDaughters_->GetEntry(entry_);
    c_mc_electrons_numOfDaughters_ = true;
  }
  return mc_electrons_numOfDaughters_;
}

std::vector<float>* const & cfa_base::mc_electrons_phi() const{
  if(!c_mc_electrons_phi_ && b_mc_electrons_phi_){
    b_mc_electrons_phi_->SetStatus(true);
    chainB_.SetBranchAddress("mc_electrons_phi", &mc_electrons_phi_, &b_mc_electrons_phi_);
    b_mc_electrons_phi_->GetEntry(entry_);
    c_mc_electrons_phi_ = true;
  }
  return mc_electrons_phi_;
}

std::vector<float>* const & cfa_base::mc_electrons_pt() const{
  if(!c_mc_electrons_pt_ && b_mc_electrons_pt_){
    b_mc_electrons_pt_->SetStatus(true);
    chainB_.SetBranchAddress("mc_electrons_pt", &mc_electrons_pt_, &b_mc_electrons_pt_);
    b_mc_electrons_pt_->GetEntry(entry_);
    c_mc_electrons_pt_ = true;
  }
  return mc_electrons_pt_;
}

std::vector<float>* const & cfa_base::mc_electrons_px() const{
  if(!c_mc_electrons_px_ && b_mc_electrons_px_){
    b_mc_electrons_px_->SetStatus(true);
    chainB_.SetBranchAddress("mc_electrons_px", &mc_electrons_px_, &b_mc_electrons_px_);
    b_mc_electrons_px_->GetEntry(entry_);
    c_mc_electrons_px_ = true;
  }
  return mc_electrons_px_;
}

std::vector<float>* const & cfa_base::mc_electrons_py() const{
  if(!c_mc_electrons_py_ && b_mc_electrons_py_){
    b_mc_electrons_py_->SetStatus(true);
    chainB_.SetBranchAddress("mc_electrons_py", &mc_electrons_py_, &b_mc_electrons_py_);
    b_mc_electrons_py_->GetEntry(entry_);
    c_mc_electrons_py_ = true;
  }
  return mc_electrons_py_;
}

std::vector<float>* const & cfa_base::mc_electrons_pz() const{
  if(!c_mc_electrons_pz_ && b_mc_electrons_pz_){
    b_mc_electrons_pz_->SetStatus(true);
    chainB_.SetBranchAddress("mc_electrons_pz", &mc_electrons_pz_, &b_mc_electrons_pz_);
    b_mc_electrons_pz_->GetEntry(entry_);
    c_mc_electrons_pz_ = true;
  }
  return mc_electrons_pz_;
}

std::vector<float>* const & cfa_base::mc_electrons_status() const{
  if(!c_mc_electrons_status_ && b_mc_electrons_status_){
    b_mc_electrons_status_->SetStatus(true);
    chainB_.SetBranchAddress("mc_electrons_status", &mc_electrons_status_, &b_mc_electrons_status_);
    b_mc_electrons_status_->GetEntry(entry_);
    c_mc_electrons_status_ = true;
  }
  return mc_electrons_status_;
}

std::vector<float>* const & cfa_base::mc_electrons_theta() const{
  if(!c_mc_electrons_theta_ && b_mc_electrons_theta_){
    b_mc_electrons_theta_->SetStatus(true);
    chainB_.SetBranchAddress("mc_electrons_theta", &mc_electrons_theta_, &b_mc_electrons_theta_);
    b_mc_electrons_theta_->GetEntry(entry_);
    c_mc_electrons_theta_ = true;
  }
  return mc_electrons_theta_;
}

std::vector<float>* const & cfa_base::mc_electrons_vertex_x() const{
  if(!c_mc_electrons_vertex_x_ && b_mc_electrons_vertex_x_){
    b_mc_electrons_vertex_x_->SetStatus(true);
    chainB_.SetBranchAddress("mc_electrons_vertex_x", &mc_electrons_vertex_x_, &b_mc_electrons_vertex_x_);
    b_mc_electrons_vertex_x_->GetEntry(entry_);
    c_mc_electrons_vertex_x_ = true;
  }
  return mc_electrons_vertex_x_;
}

std::vector<float>* const & cfa_base::mc_electrons_vertex_y() const{
  if(!c_mc_electrons_vertex_y_ && b_mc_electrons_vertex_y_){
    b_mc_electrons_vertex_y_->SetStatus(true);
    chainB_.SetBranchAddress("mc_electrons_vertex_y", &mc_electrons_vertex_y_, &b_mc_electrons_vertex_y_);
    b_mc_electrons_vertex_y_->GetEntry(entry_);
    c_mc_electrons_vertex_y_ = true;
  }
  return mc_electrons_vertex_y_;
}

std::vector<float>* const & cfa_base::mc_electrons_vertex_z() const{
  if(!c_mc_electrons_vertex_z_ && b_mc_electrons_vertex_z_){
    b_mc_electrons_vertex_z_->SetStatus(true);
    chainB_.SetBranchAddress("mc_electrons_vertex_z", &mc_electrons_vertex_z_, &b_mc_electrons_vertex_z_);
    b_mc_electrons_vertex_z_->GetEntry(entry_);
    c_mc_electrons_vertex_z_ = true;
  }
  return mc_electrons_vertex_z_;
}

std::vector<float>* const & cfa_base::mc_mus_charge() const{
  if(!c_mc_mus_charge_ && b_mc_mus_charge_){
    b_mc_mus_charge_->SetStatus(true);
    chainB_.SetBranchAddress("mc_mus_charge", &mc_mus_charge_, &b_mc_mus_charge_);
    b_mc_mus_charge_->GetEntry(entry_);
    c_mc_mus_charge_ = true;
  }
  return mc_mus_charge_;
}

std::vector<float>* const & cfa_base::mc_mus_energy() const{
  if(!c_mc_mus_energy_ && b_mc_mus_energy_){
    b_mc_mus_energy_->SetStatus(true);
    chainB_.SetBranchAddress("mc_mus_energy", &mc_mus_energy_, &b_mc_mus_energy_);
    b_mc_mus_energy_->GetEntry(entry_);
    c_mc_mus_energy_ = true;
  }
  return mc_mus_energy_;
}

std::vector<float>* const & cfa_base::mc_mus_eta() const{
  if(!c_mc_mus_eta_ && b_mc_mus_eta_){
    b_mc_mus_eta_->SetStatus(true);
    chainB_.SetBranchAddress("mc_mus_eta", &mc_mus_eta_, &b_mc_mus_eta_);
    b_mc_mus_eta_->GetEntry(entry_);
    c_mc_mus_eta_ = true;
  }
  return mc_mus_eta_;
}

std::vector<float>* const & cfa_base::mc_mus_ggrandmother_id() const{
  if(!c_mc_mus_ggrandmother_id_ && b_mc_mus_ggrandmother_id_){
    b_mc_mus_ggrandmother_id_->SetStatus(true);
    chainB_.SetBranchAddress("mc_mus_ggrandmother_id", &mc_mus_ggrandmother_id_, &b_mc_mus_ggrandmother_id_);
    b_mc_mus_ggrandmother_id_->GetEntry(entry_);
    c_mc_mus_ggrandmother_id_ = true;
  }
  return mc_mus_ggrandmother_id_;
}

std::vector<float>* const & cfa_base::mc_mus_grandmother_id() const{
  if(!c_mc_mus_grandmother_id_ && b_mc_mus_grandmother_id_){
    b_mc_mus_grandmother_id_->SetStatus(true);
    chainB_.SetBranchAddress("mc_mus_grandmother_id", &mc_mus_grandmother_id_, &b_mc_mus_grandmother_id_);
    b_mc_mus_grandmother_id_->GetEntry(entry_);
    c_mc_mus_grandmother_id_ = true;
  }
  return mc_mus_grandmother_id_;
}

std::vector<float>* const & cfa_base::mc_mus_id() const{
  if(!c_mc_mus_id_ && b_mc_mus_id_){
    b_mc_mus_id_->SetStatus(true);
    chainB_.SetBranchAddress("mc_mus_id", &mc_mus_id_, &b_mc_mus_id_);
    b_mc_mus_id_->GetEntry(entry_);
    c_mc_mus_id_ = true;
  }
  return mc_mus_id_;
}

std::vector<float>* const & cfa_base::mc_mus_mass() const{
  if(!c_mc_mus_mass_ && b_mc_mus_mass_){
    b_mc_mus_mass_->SetStatus(true);
    chainB_.SetBranchAddress("mc_mus_mass", &mc_mus_mass_, &b_mc_mus_mass_);
    b_mc_mus_mass_->GetEntry(entry_);
    c_mc_mus_mass_ = true;
  }
  return mc_mus_mass_;
}

std::vector<float>* const & cfa_base::mc_mus_mother_id() const{
  if(!c_mc_mus_mother_id_ && b_mc_mus_mother_id_){
    b_mc_mus_mother_id_->SetStatus(true);
    chainB_.SetBranchAddress("mc_mus_mother_id", &mc_mus_mother_id_, &b_mc_mus_mother_id_);
    b_mc_mus_mother_id_->GetEntry(entry_);
    c_mc_mus_mother_id_ = true;
  }
  return mc_mus_mother_id_;
}

std::vector<float>* const & cfa_base::mc_mus_mother_pt() const{
  if(!c_mc_mus_mother_pt_ && b_mc_mus_mother_pt_){
    b_mc_mus_mother_pt_->SetStatus(true);
    chainB_.SetBranchAddress("mc_mus_mother_pt", &mc_mus_mother_pt_, &b_mc_mus_mother_pt_);
    b_mc_mus_mother_pt_->GetEntry(entry_);
    c_mc_mus_mother_pt_ = true;
  }
  return mc_mus_mother_pt_;
}

std::vector<float>* const & cfa_base::mc_mus_numOfDaughters() const{
  if(!c_mc_mus_numOfDaughters_ && b_mc_mus_numOfDaughters_){
    b_mc_mus_numOfDaughters_->SetStatus(true);
    chainB_.SetBranchAddress("mc_mus_numOfDaughters", &mc_mus_numOfDaughters_, &b_mc_mus_numOfDaughters_);
    b_mc_mus_numOfDaughters_->GetEntry(entry_);
    c_mc_mus_numOfDaughters_ = true;
  }
  return mc_mus_numOfDaughters_;
}

std::vector<float>* const & cfa_base::mc_mus_phi() const{
  if(!c_mc_mus_phi_ && b_mc_mus_phi_){
    b_mc_mus_phi_->SetStatus(true);
    chainB_.SetBranchAddress("mc_mus_phi", &mc_mus_phi_, &b_mc_mus_phi_);
    b_mc_mus_phi_->GetEntry(entry_);
    c_mc_mus_phi_ = true;
  }
  return mc_mus_phi_;
}

std::vector<float>* const & cfa_base::mc_mus_pt() const{
  if(!c_mc_mus_pt_ && b_mc_mus_pt_){
    b_mc_mus_pt_->SetStatus(true);
    chainB_.SetBranchAddress("mc_mus_pt", &mc_mus_pt_, &b_mc_mus_pt_);
    b_mc_mus_pt_->GetEntry(entry_);
    c_mc_mus_pt_ = true;
  }
  return mc_mus_pt_;
}

std::vector<float>* const & cfa_base::mc_mus_px() const{
  if(!c_mc_mus_px_ && b_mc_mus_px_){
    b_mc_mus_px_->SetStatus(true);
    chainB_.SetBranchAddress("mc_mus_px", &mc_mus_px_, &b_mc_mus_px_);
    b_mc_mus_px_->GetEntry(entry_);
    c_mc_mus_px_ = true;
  }
  return mc_mus_px_;
}

std::vector<float>* const & cfa_base::mc_mus_py() const{
  if(!c_mc_mus_py_ && b_mc_mus_py_){
    b_mc_mus_py_->SetStatus(true);
    chainB_.SetBranchAddress("mc_mus_py", &mc_mus_py_, &b_mc_mus_py_);
    b_mc_mus_py_->GetEntry(entry_);
    c_mc_mus_py_ = true;
  }
  return mc_mus_py_;
}

std::vector<float>* const & cfa_base::mc_mus_pz() const{
  if(!c_mc_mus_pz_ && b_mc_mus_pz_){
    b_mc_mus_pz_->SetStatus(true);
    chainB_.SetBranchAddress("mc_mus_pz", &mc_mus_pz_, &b_mc_mus_pz_);
    b_mc_mus_pz_->GetEntry(entry_);
    c_mc_mus_pz_ = true;
  }
  return mc_mus_pz_;
}

std::vector<float>* const & cfa_base::mc_mus_status() const{
  if(!c_mc_mus_status_ && b_mc_mus_status_){
    b_mc_mus_status_->SetStatus(true);
    chainB_.SetBranchAddress("mc_mus_status", &mc_mus_status_, &b_mc_mus_status_);
    b_mc_mus_status_->GetEntry(entry_);
    c_mc_mus_status_ = true;
  }
  return mc_mus_status_;
}

std::vector<float>* const & cfa_base::mc_mus_theta() const{
  if(!c_mc_mus_theta_ && b_mc_mus_theta_){
    b_mc_mus_theta_->SetStatus(true);
    chainB_.SetBranchAddress("mc_mus_theta", &mc_mus_theta_, &b_mc_mus_theta_);
    b_mc_mus_theta_->GetEntry(entry_);
    c_mc_mus_theta_ = true;
  }
  return mc_mus_theta_;
}

std::vector<float>* const & cfa_base::mc_mus_vertex_x() const{
  if(!c_mc_mus_vertex_x_ && b_mc_mus_vertex_x_){
    b_mc_mus_vertex_x_->SetStatus(true);
    chainB_.SetBranchAddress("mc_mus_vertex_x", &mc_mus_vertex_x_, &b_mc_mus_vertex_x_);
    b_mc_mus_vertex_x_->GetEntry(entry_);
    c_mc_mus_vertex_x_ = true;
  }
  return mc_mus_vertex_x_;
}

std::vector<float>* const & cfa_base::mc_mus_vertex_y() const{
  if(!c_mc_mus_vertex_y_ && b_mc_mus_vertex_y_){
    b_mc_mus_vertex_y_->SetStatus(true);
    chainB_.SetBranchAddress("mc_mus_vertex_y", &mc_mus_vertex_y_, &b_mc_mus_vertex_y_);
    b_mc_mus_vertex_y_->GetEntry(entry_);
    c_mc_mus_vertex_y_ = true;
  }
  return mc_mus_vertex_y_;
}

std::vector<float>* const & cfa_base::mc_mus_vertex_z() const{
  if(!c_mc_mus_vertex_z_ && b_mc_mus_vertex_z_){
    b_mc_mus_vertex_z_->SetStatus(true);
    chainB_.SetBranchAddress("mc_mus_vertex_z", &mc_mus_vertex_z_, &b_mc_mus_vertex_z_);
    b_mc_mus_vertex_z_->GetEntry(entry_);
    c_mc_mus_vertex_z_ = true;
  }
  return mc_mus_vertex_z_;
}

std::vector<float>* const & cfa_base::mc_nues_charge() const{
  if(!c_mc_nues_charge_ && b_mc_nues_charge_){
    b_mc_nues_charge_->SetStatus(true);
    chainB_.SetBranchAddress("mc_nues_charge", &mc_nues_charge_, &b_mc_nues_charge_);
    b_mc_nues_charge_->GetEntry(entry_);
    c_mc_nues_charge_ = true;
  }
  return mc_nues_charge_;
}

std::vector<float>* const & cfa_base::mc_nues_energy() const{
  if(!c_mc_nues_energy_ && b_mc_nues_energy_){
    b_mc_nues_energy_->SetStatus(true);
    chainB_.SetBranchAddress("mc_nues_energy", &mc_nues_energy_, &b_mc_nues_energy_);
    b_mc_nues_energy_->GetEntry(entry_);
    c_mc_nues_energy_ = true;
  }
  return mc_nues_energy_;
}

std::vector<float>* const & cfa_base::mc_nues_eta() const{
  if(!c_mc_nues_eta_ && b_mc_nues_eta_){
    b_mc_nues_eta_->SetStatus(true);
    chainB_.SetBranchAddress("mc_nues_eta", &mc_nues_eta_, &b_mc_nues_eta_);
    b_mc_nues_eta_->GetEntry(entry_);
    c_mc_nues_eta_ = true;
  }
  return mc_nues_eta_;
}

std::vector<float>* const & cfa_base::mc_nues_ggrandmother_id() const{
  if(!c_mc_nues_ggrandmother_id_ && b_mc_nues_ggrandmother_id_){
    b_mc_nues_ggrandmother_id_->SetStatus(true);
    chainB_.SetBranchAddress("mc_nues_ggrandmother_id", &mc_nues_ggrandmother_id_, &b_mc_nues_ggrandmother_id_);
    b_mc_nues_ggrandmother_id_->GetEntry(entry_);
    c_mc_nues_ggrandmother_id_ = true;
  }
  return mc_nues_ggrandmother_id_;
}

std::vector<float>* const & cfa_base::mc_nues_grandmother_id() const{
  if(!c_mc_nues_grandmother_id_ && b_mc_nues_grandmother_id_){
    b_mc_nues_grandmother_id_->SetStatus(true);
    chainB_.SetBranchAddress("mc_nues_grandmother_id", &mc_nues_grandmother_id_, &b_mc_nues_grandmother_id_);
    b_mc_nues_grandmother_id_->GetEntry(entry_);
    c_mc_nues_grandmother_id_ = true;
  }
  return mc_nues_grandmother_id_;
}

std::vector<float>* const & cfa_base::mc_nues_id() const{
  if(!c_mc_nues_id_ && b_mc_nues_id_){
    b_mc_nues_id_->SetStatus(true);
    chainB_.SetBranchAddress("mc_nues_id", &mc_nues_id_, &b_mc_nues_id_);
    b_mc_nues_id_->GetEntry(entry_);
    c_mc_nues_id_ = true;
  }
  return mc_nues_id_;
}

std::vector<float>* const & cfa_base::mc_nues_mass() const{
  if(!c_mc_nues_mass_ && b_mc_nues_mass_){
    b_mc_nues_mass_->SetStatus(true);
    chainB_.SetBranchAddress("mc_nues_mass", &mc_nues_mass_, &b_mc_nues_mass_);
    b_mc_nues_mass_->GetEntry(entry_);
    c_mc_nues_mass_ = true;
  }
  return mc_nues_mass_;
}

std::vector<float>* const & cfa_base::mc_nues_mother_id() const{
  if(!c_mc_nues_mother_id_ && b_mc_nues_mother_id_){
    b_mc_nues_mother_id_->SetStatus(true);
    chainB_.SetBranchAddress("mc_nues_mother_id", &mc_nues_mother_id_, &b_mc_nues_mother_id_);
    b_mc_nues_mother_id_->GetEntry(entry_);
    c_mc_nues_mother_id_ = true;
  }
  return mc_nues_mother_id_;
}

std::vector<float>* const & cfa_base::mc_nues_mother_pt() const{
  if(!c_mc_nues_mother_pt_ && b_mc_nues_mother_pt_){
    b_mc_nues_mother_pt_->SetStatus(true);
    chainB_.SetBranchAddress("mc_nues_mother_pt", &mc_nues_mother_pt_, &b_mc_nues_mother_pt_);
    b_mc_nues_mother_pt_->GetEntry(entry_);
    c_mc_nues_mother_pt_ = true;
  }
  return mc_nues_mother_pt_;
}

std::vector<float>* const & cfa_base::mc_nues_numOfDaughters() const{
  if(!c_mc_nues_numOfDaughters_ && b_mc_nues_numOfDaughters_){
    b_mc_nues_numOfDaughters_->SetStatus(true);
    chainB_.SetBranchAddress("mc_nues_numOfDaughters", &mc_nues_numOfDaughters_, &b_mc_nues_numOfDaughters_);
    b_mc_nues_numOfDaughters_->GetEntry(entry_);
    c_mc_nues_numOfDaughters_ = true;
  }
  return mc_nues_numOfDaughters_;
}

std::vector<float>* const & cfa_base::mc_nues_phi() const{
  if(!c_mc_nues_phi_ && b_mc_nues_phi_){
    b_mc_nues_phi_->SetStatus(true);
    chainB_.SetBranchAddress("mc_nues_phi", &mc_nues_phi_, &b_mc_nues_phi_);
    b_mc_nues_phi_->GetEntry(entry_);
    c_mc_nues_phi_ = true;
  }
  return mc_nues_phi_;
}

std::vector<float>* const & cfa_base::mc_nues_pt() const{
  if(!c_mc_nues_pt_ && b_mc_nues_pt_){
    b_mc_nues_pt_->SetStatus(true);
    chainB_.SetBranchAddress("mc_nues_pt", &mc_nues_pt_, &b_mc_nues_pt_);
    b_mc_nues_pt_->GetEntry(entry_);
    c_mc_nues_pt_ = true;
  }
  return mc_nues_pt_;
}

std::vector<float>* const & cfa_base::mc_nues_px() const{
  if(!c_mc_nues_px_ && b_mc_nues_px_){
    b_mc_nues_px_->SetStatus(true);
    chainB_.SetBranchAddress("mc_nues_px", &mc_nues_px_, &b_mc_nues_px_);
    b_mc_nues_px_->GetEntry(entry_);
    c_mc_nues_px_ = true;
  }
  return mc_nues_px_;
}

std::vector<float>* const & cfa_base::mc_nues_py() const{
  if(!c_mc_nues_py_ && b_mc_nues_py_){
    b_mc_nues_py_->SetStatus(true);
    chainB_.SetBranchAddress("mc_nues_py", &mc_nues_py_, &b_mc_nues_py_);
    b_mc_nues_py_->GetEntry(entry_);
    c_mc_nues_py_ = true;
  }
  return mc_nues_py_;
}

std::vector<float>* const & cfa_base::mc_nues_pz() const{
  if(!c_mc_nues_pz_ && b_mc_nues_pz_){
    b_mc_nues_pz_->SetStatus(true);
    chainB_.SetBranchAddress("mc_nues_pz", &mc_nues_pz_, &b_mc_nues_pz_);
    b_mc_nues_pz_->GetEntry(entry_);
    c_mc_nues_pz_ = true;
  }
  return mc_nues_pz_;
}

std::vector<float>* const & cfa_base::mc_nues_status() const{
  if(!c_mc_nues_status_ && b_mc_nues_status_){
    b_mc_nues_status_->SetStatus(true);
    chainB_.SetBranchAddress("mc_nues_status", &mc_nues_status_, &b_mc_nues_status_);
    b_mc_nues_status_->GetEntry(entry_);
    c_mc_nues_status_ = true;
  }
  return mc_nues_status_;
}

std::vector<float>* const & cfa_base::mc_nues_theta() const{
  if(!c_mc_nues_theta_ && b_mc_nues_theta_){
    b_mc_nues_theta_->SetStatus(true);
    chainB_.SetBranchAddress("mc_nues_theta", &mc_nues_theta_, &b_mc_nues_theta_);
    b_mc_nues_theta_->GetEntry(entry_);
    c_mc_nues_theta_ = true;
  }
  return mc_nues_theta_;
}

std::vector<float>* const & cfa_base::mc_nues_vertex_x() const{
  if(!c_mc_nues_vertex_x_ && b_mc_nues_vertex_x_){
    b_mc_nues_vertex_x_->SetStatus(true);
    chainB_.SetBranchAddress("mc_nues_vertex_x", &mc_nues_vertex_x_, &b_mc_nues_vertex_x_);
    b_mc_nues_vertex_x_->GetEntry(entry_);
    c_mc_nues_vertex_x_ = true;
  }
  return mc_nues_vertex_x_;
}

std::vector<float>* const & cfa_base::mc_nues_vertex_y() const{
  if(!c_mc_nues_vertex_y_ && b_mc_nues_vertex_y_){
    b_mc_nues_vertex_y_->SetStatus(true);
    chainB_.SetBranchAddress("mc_nues_vertex_y", &mc_nues_vertex_y_, &b_mc_nues_vertex_y_);
    b_mc_nues_vertex_y_->GetEntry(entry_);
    c_mc_nues_vertex_y_ = true;
  }
  return mc_nues_vertex_y_;
}

std::vector<float>* const & cfa_base::mc_nues_vertex_z() const{
  if(!c_mc_nues_vertex_z_ && b_mc_nues_vertex_z_){
    b_mc_nues_vertex_z_->SetStatus(true);
    chainB_.SetBranchAddress("mc_nues_vertex_z", &mc_nues_vertex_z_, &b_mc_nues_vertex_z_);
    b_mc_nues_vertex_z_->GetEntry(entry_);
    c_mc_nues_vertex_z_ = true;
  }
  return mc_nues_vertex_z_;
}

std::vector<float>* const & cfa_base::mc_numus_charge() const{
  if(!c_mc_numus_charge_ && b_mc_numus_charge_){
    b_mc_numus_charge_->SetStatus(true);
    chainB_.SetBranchAddress("mc_numus_charge", &mc_numus_charge_, &b_mc_numus_charge_);
    b_mc_numus_charge_->GetEntry(entry_);
    c_mc_numus_charge_ = true;
  }
  return mc_numus_charge_;
}

std::vector<float>* const & cfa_base::mc_numus_energy() const{
  if(!c_mc_numus_energy_ && b_mc_numus_energy_){
    b_mc_numus_energy_->SetStatus(true);
    chainB_.SetBranchAddress("mc_numus_energy", &mc_numus_energy_, &b_mc_numus_energy_);
    b_mc_numus_energy_->GetEntry(entry_);
    c_mc_numus_energy_ = true;
  }
  return mc_numus_energy_;
}

std::vector<float>* const & cfa_base::mc_numus_eta() const{
  if(!c_mc_numus_eta_ && b_mc_numus_eta_){
    b_mc_numus_eta_->SetStatus(true);
    chainB_.SetBranchAddress("mc_numus_eta", &mc_numus_eta_, &b_mc_numus_eta_);
    b_mc_numus_eta_->GetEntry(entry_);
    c_mc_numus_eta_ = true;
  }
  return mc_numus_eta_;
}

std::vector<float>* const & cfa_base::mc_numus_ggrandmother_id() const{
  if(!c_mc_numus_ggrandmother_id_ && b_mc_numus_ggrandmother_id_){
    b_mc_numus_ggrandmother_id_->SetStatus(true);
    chainB_.SetBranchAddress("mc_numus_ggrandmother_id", &mc_numus_ggrandmother_id_, &b_mc_numus_ggrandmother_id_);
    b_mc_numus_ggrandmother_id_->GetEntry(entry_);
    c_mc_numus_ggrandmother_id_ = true;
  }
  return mc_numus_ggrandmother_id_;
}

std::vector<float>* const & cfa_base::mc_numus_grandmother_id() const{
  if(!c_mc_numus_grandmother_id_ && b_mc_numus_grandmother_id_){
    b_mc_numus_grandmother_id_->SetStatus(true);
    chainB_.SetBranchAddress("mc_numus_grandmother_id", &mc_numus_grandmother_id_, &b_mc_numus_grandmother_id_);
    b_mc_numus_grandmother_id_->GetEntry(entry_);
    c_mc_numus_grandmother_id_ = true;
  }
  return mc_numus_grandmother_id_;
}

std::vector<float>* const & cfa_base::mc_numus_id() const{
  if(!c_mc_numus_id_ && b_mc_numus_id_){
    b_mc_numus_id_->SetStatus(true);
    chainB_.SetBranchAddress("mc_numus_id", &mc_numus_id_, &b_mc_numus_id_);
    b_mc_numus_id_->GetEntry(entry_);
    c_mc_numus_id_ = true;
  }
  return mc_numus_id_;
}

std::vector<float>* const & cfa_base::mc_numus_mass() const{
  if(!c_mc_numus_mass_ && b_mc_numus_mass_){
    b_mc_numus_mass_->SetStatus(true);
    chainB_.SetBranchAddress("mc_numus_mass", &mc_numus_mass_, &b_mc_numus_mass_);
    b_mc_numus_mass_->GetEntry(entry_);
    c_mc_numus_mass_ = true;
  }
  return mc_numus_mass_;
}

std::vector<float>* const & cfa_base::mc_numus_mother_id() const{
  if(!c_mc_numus_mother_id_ && b_mc_numus_mother_id_){
    b_mc_numus_mother_id_->SetStatus(true);
    chainB_.SetBranchAddress("mc_numus_mother_id", &mc_numus_mother_id_, &b_mc_numus_mother_id_);
    b_mc_numus_mother_id_->GetEntry(entry_);
    c_mc_numus_mother_id_ = true;
  }
  return mc_numus_mother_id_;
}

std::vector<float>* const & cfa_base::mc_numus_mother_pt() const{
  if(!c_mc_numus_mother_pt_ && b_mc_numus_mother_pt_){
    b_mc_numus_mother_pt_->SetStatus(true);
    chainB_.SetBranchAddress("mc_numus_mother_pt", &mc_numus_mother_pt_, &b_mc_numus_mother_pt_);
    b_mc_numus_mother_pt_->GetEntry(entry_);
    c_mc_numus_mother_pt_ = true;
  }
  return mc_numus_mother_pt_;
}

std::vector<float>* const & cfa_base::mc_numus_numOfDaughters() const{
  if(!c_mc_numus_numOfDaughters_ && b_mc_numus_numOfDaughters_){
    b_mc_numus_numOfDaughters_->SetStatus(true);
    chainB_.SetBranchAddress("mc_numus_numOfDaughters", &mc_numus_numOfDaughters_, &b_mc_numus_numOfDaughters_);
    b_mc_numus_numOfDaughters_->GetEntry(entry_);
    c_mc_numus_numOfDaughters_ = true;
  }
  return mc_numus_numOfDaughters_;
}

std::vector<float>* const & cfa_base::mc_numus_phi() const{
  if(!c_mc_numus_phi_ && b_mc_numus_phi_){
    b_mc_numus_phi_->SetStatus(true);
    chainB_.SetBranchAddress("mc_numus_phi", &mc_numus_phi_, &b_mc_numus_phi_);
    b_mc_numus_phi_->GetEntry(entry_);
    c_mc_numus_phi_ = true;
  }
  return mc_numus_phi_;
}

std::vector<float>* const & cfa_base::mc_numus_pt() const{
  if(!c_mc_numus_pt_ && b_mc_numus_pt_){
    b_mc_numus_pt_->SetStatus(true);
    chainB_.SetBranchAddress("mc_numus_pt", &mc_numus_pt_, &b_mc_numus_pt_);
    b_mc_numus_pt_->GetEntry(entry_);
    c_mc_numus_pt_ = true;
  }
  return mc_numus_pt_;
}

std::vector<float>* const & cfa_base::mc_numus_px() const{
  if(!c_mc_numus_px_ && b_mc_numus_px_){
    b_mc_numus_px_->SetStatus(true);
    chainB_.SetBranchAddress("mc_numus_px", &mc_numus_px_, &b_mc_numus_px_);
    b_mc_numus_px_->GetEntry(entry_);
    c_mc_numus_px_ = true;
  }
  return mc_numus_px_;
}

std::vector<float>* const & cfa_base::mc_numus_py() const{
  if(!c_mc_numus_py_ && b_mc_numus_py_){
    b_mc_numus_py_->SetStatus(true);
    chainB_.SetBranchAddress("mc_numus_py", &mc_numus_py_, &b_mc_numus_py_);
    b_mc_numus_py_->GetEntry(entry_);
    c_mc_numus_py_ = true;
  }
  return mc_numus_py_;
}

std::vector<float>* const & cfa_base::mc_numus_pz() const{
  if(!c_mc_numus_pz_ && b_mc_numus_pz_){
    b_mc_numus_pz_->SetStatus(true);
    chainB_.SetBranchAddress("mc_numus_pz", &mc_numus_pz_, &b_mc_numus_pz_);
    b_mc_numus_pz_->GetEntry(entry_);
    c_mc_numus_pz_ = true;
  }
  return mc_numus_pz_;
}

std::vector<float>* const & cfa_base::mc_numus_status() const{
  if(!c_mc_numus_status_ && b_mc_numus_status_){
    b_mc_numus_status_->SetStatus(true);
    chainB_.SetBranchAddress("mc_numus_status", &mc_numus_status_, &b_mc_numus_status_);
    b_mc_numus_status_->GetEntry(entry_);
    c_mc_numus_status_ = true;
  }
  return mc_numus_status_;
}

std::vector<float>* const & cfa_base::mc_numus_theta() const{
  if(!c_mc_numus_theta_ && b_mc_numus_theta_){
    b_mc_numus_theta_->SetStatus(true);
    chainB_.SetBranchAddress("mc_numus_theta", &mc_numus_theta_, &b_mc_numus_theta_);
    b_mc_numus_theta_->GetEntry(entry_);
    c_mc_numus_theta_ = true;
  }
  return mc_numus_theta_;
}

std::vector<float>* const & cfa_base::mc_numus_vertex_x() const{
  if(!c_mc_numus_vertex_x_ && b_mc_numus_vertex_x_){
    b_mc_numus_vertex_x_->SetStatus(true);
    chainB_.SetBranchAddress("mc_numus_vertex_x", &mc_numus_vertex_x_, &b_mc_numus_vertex_x_);
    b_mc_numus_vertex_x_->GetEntry(entry_);
    c_mc_numus_vertex_x_ = true;
  }
  return mc_numus_vertex_x_;
}

std::vector<float>* const & cfa_base::mc_numus_vertex_y() const{
  if(!c_mc_numus_vertex_y_ && b_mc_numus_vertex_y_){
    b_mc_numus_vertex_y_->SetStatus(true);
    chainB_.SetBranchAddress("mc_numus_vertex_y", &mc_numus_vertex_y_, &b_mc_numus_vertex_y_);
    b_mc_numus_vertex_y_->GetEntry(entry_);
    c_mc_numus_vertex_y_ = true;
  }
  return mc_numus_vertex_y_;
}

std::vector<float>* const & cfa_base::mc_numus_vertex_z() const{
  if(!c_mc_numus_vertex_z_ && b_mc_numus_vertex_z_){
    b_mc_numus_vertex_z_->SetStatus(true);
    chainB_.SetBranchAddress("mc_numus_vertex_z", &mc_numus_vertex_z_, &b_mc_numus_vertex_z_);
    b_mc_numus_vertex_z_->GetEntry(entry_);
    c_mc_numus_vertex_z_ = true;
  }
  return mc_numus_vertex_z_;
}

std::vector<float>* const & cfa_base::mc_nutaus_charge() const{
  if(!c_mc_nutaus_charge_ && b_mc_nutaus_charge_){
    b_mc_nutaus_charge_->SetStatus(true);
    chainB_.SetBranchAddress("mc_nutaus_charge", &mc_nutaus_charge_, &b_mc_nutaus_charge_);
    b_mc_nutaus_charge_->GetEntry(entry_);
    c_mc_nutaus_charge_ = true;
  }
  return mc_nutaus_charge_;
}

std::vector<float>* const & cfa_base::mc_nutaus_energy() const{
  if(!c_mc_nutaus_energy_ && b_mc_nutaus_energy_){
    b_mc_nutaus_energy_->SetStatus(true);
    chainB_.SetBranchAddress("mc_nutaus_energy", &mc_nutaus_energy_, &b_mc_nutaus_energy_);
    b_mc_nutaus_energy_->GetEntry(entry_);
    c_mc_nutaus_energy_ = true;
  }
  return mc_nutaus_energy_;
}

std::vector<float>* const & cfa_base::mc_nutaus_eta() const{
  if(!c_mc_nutaus_eta_ && b_mc_nutaus_eta_){
    b_mc_nutaus_eta_->SetStatus(true);
    chainB_.SetBranchAddress("mc_nutaus_eta", &mc_nutaus_eta_, &b_mc_nutaus_eta_);
    b_mc_nutaus_eta_->GetEntry(entry_);
    c_mc_nutaus_eta_ = true;
  }
  return mc_nutaus_eta_;
}

std::vector<float>* const & cfa_base::mc_nutaus_ggrandmother_id() const{
  if(!c_mc_nutaus_ggrandmother_id_ && b_mc_nutaus_ggrandmother_id_){
    b_mc_nutaus_ggrandmother_id_->SetStatus(true);
    chainB_.SetBranchAddress("mc_nutaus_ggrandmother_id", &mc_nutaus_ggrandmother_id_, &b_mc_nutaus_ggrandmother_id_);
    b_mc_nutaus_ggrandmother_id_->GetEntry(entry_);
    c_mc_nutaus_ggrandmother_id_ = true;
  }
  return mc_nutaus_ggrandmother_id_;
}

std::vector<float>* const & cfa_base::mc_nutaus_grandmother_id() const{
  if(!c_mc_nutaus_grandmother_id_ && b_mc_nutaus_grandmother_id_){
    b_mc_nutaus_grandmother_id_->SetStatus(true);
    chainB_.SetBranchAddress("mc_nutaus_grandmother_id", &mc_nutaus_grandmother_id_, &b_mc_nutaus_grandmother_id_);
    b_mc_nutaus_grandmother_id_->GetEntry(entry_);
    c_mc_nutaus_grandmother_id_ = true;
  }
  return mc_nutaus_grandmother_id_;
}

std::vector<float>* const & cfa_base::mc_nutaus_id() const{
  if(!c_mc_nutaus_id_ && b_mc_nutaus_id_){
    b_mc_nutaus_id_->SetStatus(true);
    chainB_.SetBranchAddress("mc_nutaus_id", &mc_nutaus_id_, &b_mc_nutaus_id_);
    b_mc_nutaus_id_->GetEntry(entry_);
    c_mc_nutaus_id_ = true;
  }
  return mc_nutaus_id_;
}

std::vector<float>* const & cfa_base::mc_nutaus_mass() const{
  if(!c_mc_nutaus_mass_ && b_mc_nutaus_mass_){
    b_mc_nutaus_mass_->SetStatus(true);
    chainB_.SetBranchAddress("mc_nutaus_mass", &mc_nutaus_mass_, &b_mc_nutaus_mass_);
    b_mc_nutaus_mass_->GetEntry(entry_);
    c_mc_nutaus_mass_ = true;
  }
  return mc_nutaus_mass_;
}

std::vector<float>* const & cfa_base::mc_nutaus_mother_id() const{
  if(!c_mc_nutaus_mother_id_ && b_mc_nutaus_mother_id_){
    b_mc_nutaus_mother_id_->SetStatus(true);
    chainB_.SetBranchAddress("mc_nutaus_mother_id", &mc_nutaus_mother_id_, &b_mc_nutaus_mother_id_);
    b_mc_nutaus_mother_id_->GetEntry(entry_);
    c_mc_nutaus_mother_id_ = true;
  }
  return mc_nutaus_mother_id_;
}

std::vector<float>* const & cfa_base::mc_nutaus_mother_pt() const{
  if(!c_mc_nutaus_mother_pt_ && b_mc_nutaus_mother_pt_){
    b_mc_nutaus_mother_pt_->SetStatus(true);
    chainB_.SetBranchAddress("mc_nutaus_mother_pt", &mc_nutaus_mother_pt_, &b_mc_nutaus_mother_pt_);
    b_mc_nutaus_mother_pt_->GetEntry(entry_);
    c_mc_nutaus_mother_pt_ = true;
  }
  return mc_nutaus_mother_pt_;
}

std::vector<float>* const & cfa_base::mc_nutaus_numOfDaughters() const{
  if(!c_mc_nutaus_numOfDaughters_ && b_mc_nutaus_numOfDaughters_){
    b_mc_nutaus_numOfDaughters_->SetStatus(true);
    chainB_.SetBranchAddress("mc_nutaus_numOfDaughters", &mc_nutaus_numOfDaughters_, &b_mc_nutaus_numOfDaughters_);
    b_mc_nutaus_numOfDaughters_->GetEntry(entry_);
    c_mc_nutaus_numOfDaughters_ = true;
  }
  return mc_nutaus_numOfDaughters_;
}

std::vector<float>* const & cfa_base::mc_nutaus_phi() const{
  if(!c_mc_nutaus_phi_ && b_mc_nutaus_phi_){
    b_mc_nutaus_phi_->SetStatus(true);
    chainB_.SetBranchAddress("mc_nutaus_phi", &mc_nutaus_phi_, &b_mc_nutaus_phi_);
    b_mc_nutaus_phi_->GetEntry(entry_);
    c_mc_nutaus_phi_ = true;
  }
  return mc_nutaus_phi_;
}

std::vector<float>* const & cfa_base::mc_nutaus_pt() const{
  if(!c_mc_nutaus_pt_ && b_mc_nutaus_pt_){
    b_mc_nutaus_pt_->SetStatus(true);
    chainB_.SetBranchAddress("mc_nutaus_pt", &mc_nutaus_pt_, &b_mc_nutaus_pt_);
    b_mc_nutaus_pt_->GetEntry(entry_);
    c_mc_nutaus_pt_ = true;
  }
  return mc_nutaus_pt_;
}

std::vector<float>* const & cfa_base::mc_nutaus_px() const{
  if(!c_mc_nutaus_px_ && b_mc_nutaus_px_){
    b_mc_nutaus_px_->SetStatus(true);
    chainB_.SetBranchAddress("mc_nutaus_px", &mc_nutaus_px_, &b_mc_nutaus_px_);
    b_mc_nutaus_px_->GetEntry(entry_);
    c_mc_nutaus_px_ = true;
  }
  return mc_nutaus_px_;
}

std::vector<float>* const & cfa_base::mc_nutaus_py() const{
  if(!c_mc_nutaus_py_ && b_mc_nutaus_py_){
    b_mc_nutaus_py_->SetStatus(true);
    chainB_.SetBranchAddress("mc_nutaus_py", &mc_nutaus_py_, &b_mc_nutaus_py_);
    b_mc_nutaus_py_->GetEntry(entry_);
    c_mc_nutaus_py_ = true;
  }
  return mc_nutaus_py_;
}

std::vector<float>* const & cfa_base::mc_nutaus_pz() const{
  if(!c_mc_nutaus_pz_ && b_mc_nutaus_pz_){
    b_mc_nutaus_pz_->SetStatus(true);
    chainB_.SetBranchAddress("mc_nutaus_pz", &mc_nutaus_pz_, &b_mc_nutaus_pz_);
    b_mc_nutaus_pz_->GetEntry(entry_);
    c_mc_nutaus_pz_ = true;
  }
  return mc_nutaus_pz_;
}

std::vector<float>* const & cfa_base::mc_nutaus_status() const{
  if(!c_mc_nutaus_status_ && b_mc_nutaus_status_){
    b_mc_nutaus_status_->SetStatus(true);
    chainB_.SetBranchAddress("mc_nutaus_status", &mc_nutaus_status_, &b_mc_nutaus_status_);
    b_mc_nutaus_status_->GetEntry(entry_);
    c_mc_nutaus_status_ = true;
  }
  return mc_nutaus_status_;
}

std::vector<float>* const & cfa_base::mc_nutaus_theta() const{
  if(!c_mc_nutaus_theta_ && b_mc_nutaus_theta_){
    b_mc_nutaus_theta_->SetStatus(true);
    chainB_.SetBranchAddress("mc_nutaus_theta", &mc_nutaus_theta_, &b_mc_nutaus_theta_);
    b_mc_nutaus_theta_->GetEntry(entry_);
    c_mc_nutaus_theta_ = true;
  }
  return mc_nutaus_theta_;
}

std::vector<float>* const & cfa_base::mc_nutaus_vertex_x() const{
  if(!c_mc_nutaus_vertex_x_ && b_mc_nutaus_vertex_x_){
    b_mc_nutaus_vertex_x_->SetStatus(true);
    chainB_.SetBranchAddress("mc_nutaus_vertex_x", &mc_nutaus_vertex_x_, &b_mc_nutaus_vertex_x_);
    b_mc_nutaus_vertex_x_->GetEntry(entry_);
    c_mc_nutaus_vertex_x_ = true;
  }
  return mc_nutaus_vertex_x_;
}

std::vector<float>* const & cfa_base::mc_nutaus_vertex_y() const{
  if(!c_mc_nutaus_vertex_y_ && b_mc_nutaus_vertex_y_){
    b_mc_nutaus_vertex_y_->SetStatus(true);
    chainB_.SetBranchAddress("mc_nutaus_vertex_y", &mc_nutaus_vertex_y_, &b_mc_nutaus_vertex_y_);
    b_mc_nutaus_vertex_y_->GetEntry(entry_);
    c_mc_nutaus_vertex_y_ = true;
  }
  return mc_nutaus_vertex_y_;
}

std::vector<float>* const & cfa_base::mc_nutaus_vertex_z() const{
  if(!c_mc_nutaus_vertex_z_ && b_mc_nutaus_vertex_z_){
    b_mc_nutaus_vertex_z_->SetStatus(true);
    chainB_.SetBranchAddress("mc_nutaus_vertex_z", &mc_nutaus_vertex_z_, &b_mc_nutaus_vertex_z_);
    b_mc_nutaus_vertex_z_->GetEntry(entry_);
    c_mc_nutaus_vertex_z_ = true;
  }
  return mc_nutaus_vertex_z_;
}

std::vector<float>* const & cfa_base::mc_photons_charge() const{
  if(!c_mc_photons_charge_ && b_mc_photons_charge_){
    b_mc_photons_charge_->SetStatus(true);
    chainB_.SetBranchAddress("mc_photons_charge", &mc_photons_charge_, &b_mc_photons_charge_);
    b_mc_photons_charge_->GetEntry(entry_);
    c_mc_photons_charge_ = true;
  }
  return mc_photons_charge_;
}

std::vector<float>* const & cfa_base::mc_photons_energy() const{
  if(!c_mc_photons_energy_ && b_mc_photons_energy_){
    b_mc_photons_energy_->SetStatus(true);
    chainB_.SetBranchAddress("mc_photons_energy", &mc_photons_energy_, &b_mc_photons_energy_);
    b_mc_photons_energy_->GetEntry(entry_);
    c_mc_photons_energy_ = true;
  }
  return mc_photons_energy_;
}

std::vector<float>* const & cfa_base::mc_photons_eta() const{
  if(!c_mc_photons_eta_ && b_mc_photons_eta_){
    b_mc_photons_eta_->SetStatus(true);
    chainB_.SetBranchAddress("mc_photons_eta", &mc_photons_eta_, &b_mc_photons_eta_);
    b_mc_photons_eta_->GetEntry(entry_);
    c_mc_photons_eta_ = true;
  }
  return mc_photons_eta_;
}

std::vector<float>* const & cfa_base::mc_photons_ggrandmother_id() const{
  if(!c_mc_photons_ggrandmother_id_ && b_mc_photons_ggrandmother_id_){
    b_mc_photons_ggrandmother_id_->SetStatus(true);
    chainB_.SetBranchAddress("mc_photons_ggrandmother_id", &mc_photons_ggrandmother_id_, &b_mc_photons_ggrandmother_id_);
    b_mc_photons_ggrandmother_id_->GetEntry(entry_);
    c_mc_photons_ggrandmother_id_ = true;
  }
  return mc_photons_ggrandmother_id_;
}

std::vector<float>* const & cfa_base::mc_photons_grandmother_id() const{
  if(!c_mc_photons_grandmother_id_ && b_mc_photons_grandmother_id_){
    b_mc_photons_grandmother_id_->SetStatus(true);
    chainB_.SetBranchAddress("mc_photons_grandmother_id", &mc_photons_grandmother_id_, &b_mc_photons_grandmother_id_);
    b_mc_photons_grandmother_id_->GetEntry(entry_);
    c_mc_photons_grandmother_id_ = true;
  }
  return mc_photons_grandmother_id_;
}

std::vector<float>* const & cfa_base::mc_photons_id() const{
  if(!c_mc_photons_id_ && b_mc_photons_id_){
    b_mc_photons_id_->SetStatus(true);
    chainB_.SetBranchAddress("mc_photons_id", &mc_photons_id_, &b_mc_photons_id_);
    b_mc_photons_id_->GetEntry(entry_);
    c_mc_photons_id_ = true;
  }
  return mc_photons_id_;
}

std::vector<float>* const & cfa_base::mc_photons_mass() const{
  if(!c_mc_photons_mass_ && b_mc_photons_mass_){
    b_mc_photons_mass_->SetStatus(true);
    chainB_.SetBranchAddress("mc_photons_mass", &mc_photons_mass_, &b_mc_photons_mass_);
    b_mc_photons_mass_->GetEntry(entry_);
    c_mc_photons_mass_ = true;
  }
  return mc_photons_mass_;
}

std::vector<float>* const & cfa_base::mc_photons_mother_id() const{
  if(!c_mc_photons_mother_id_ && b_mc_photons_mother_id_){
    b_mc_photons_mother_id_->SetStatus(true);
    chainB_.SetBranchAddress("mc_photons_mother_id", &mc_photons_mother_id_, &b_mc_photons_mother_id_);
    b_mc_photons_mother_id_->GetEntry(entry_);
    c_mc_photons_mother_id_ = true;
  }
  return mc_photons_mother_id_;
}

std::vector<float>* const & cfa_base::mc_photons_mother_pt() const{
  if(!c_mc_photons_mother_pt_ && b_mc_photons_mother_pt_){
    b_mc_photons_mother_pt_->SetStatus(true);
    chainB_.SetBranchAddress("mc_photons_mother_pt", &mc_photons_mother_pt_, &b_mc_photons_mother_pt_);
    b_mc_photons_mother_pt_->GetEntry(entry_);
    c_mc_photons_mother_pt_ = true;
  }
  return mc_photons_mother_pt_;
}

std::vector<float>* const & cfa_base::mc_photons_numOfDaughters() const{
  if(!c_mc_photons_numOfDaughters_ && b_mc_photons_numOfDaughters_){
    b_mc_photons_numOfDaughters_->SetStatus(true);
    chainB_.SetBranchAddress("mc_photons_numOfDaughters", &mc_photons_numOfDaughters_, &b_mc_photons_numOfDaughters_);
    b_mc_photons_numOfDaughters_->GetEntry(entry_);
    c_mc_photons_numOfDaughters_ = true;
  }
  return mc_photons_numOfDaughters_;
}

std::vector<float>* const & cfa_base::mc_photons_phi() const{
  if(!c_mc_photons_phi_ && b_mc_photons_phi_){
    b_mc_photons_phi_->SetStatus(true);
    chainB_.SetBranchAddress("mc_photons_phi", &mc_photons_phi_, &b_mc_photons_phi_);
    b_mc_photons_phi_->GetEntry(entry_);
    c_mc_photons_phi_ = true;
  }
  return mc_photons_phi_;
}

std::vector<float>* const & cfa_base::mc_photons_pt() const{
  if(!c_mc_photons_pt_ && b_mc_photons_pt_){
    b_mc_photons_pt_->SetStatus(true);
    chainB_.SetBranchAddress("mc_photons_pt", &mc_photons_pt_, &b_mc_photons_pt_);
    b_mc_photons_pt_->GetEntry(entry_);
    c_mc_photons_pt_ = true;
  }
  return mc_photons_pt_;
}

std::vector<float>* const & cfa_base::mc_photons_px() const{
  if(!c_mc_photons_px_ && b_mc_photons_px_){
    b_mc_photons_px_->SetStatus(true);
    chainB_.SetBranchAddress("mc_photons_px", &mc_photons_px_, &b_mc_photons_px_);
    b_mc_photons_px_->GetEntry(entry_);
    c_mc_photons_px_ = true;
  }
  return mc_photons_px_;
}

std::vector<float>* const & cfa_base::mc_photons_py() const{
  if(!c_mc_photons_py_ && b_mc_photons_py_){
    b_mc_photons_py_->SetStatus(true);
    chainB_.SetBranchAddress("mc_photons_py", &mc_photons_py_, &b_mc_photons_py_);
    b_mc_photons_py_->GetEntry(entry_);
    c_mc_photons_py_ = true;
  }
  return mc_photons_py_;
}

std::vector<float>* const & cfa_base::mc_photons_pz() const{
  if(!c_mc_photons_pz_ && b_mc_photons_pz_){
    b_mc_photons_pz_->SetStatus(true);
    chainB_.SetBranchAddress("mc_photons_pz", &mc_photons_pz_, &b_mc_photons_pz_);
    b_mc_photons_pz_->GetEntry(entry_);
    c_mc_photons_pz_ = true;
  }
  return mc_photons_pz_;
}

std::vector<float>* const & cfa_base::mc_photons_status() const{
  if(!c_mc_photons_status_ && b_mc_photons_status_){
    b_mc_photons_status_->SetStatus(true);
    chainB_.SetBranchAddress("mc_photons_status", &mc_photons_status_, &b_mc_photons_status_);
    b_mc_photons_status_->GetEntry(entry_);
    c_mc_photons_status_ = true;
  }
  return mc_photons_status_;
}

std::vector<float>* const & cfa_base::mc_photons_theta() const{
  if(!c_mc_photons_theta_ && b_mc_photons_theta_){
    b_mc_photons_theta_->SetStatus(true);
    chainB_.SetBranchAddress("mc_photons_theta", &mc_photons_theta_, &b_mc_photons_theta_);
    b_mc_photons_theta_->GetEntry(entry_);
    c_mc_photons_theta_ = true;
  }
  return mc_photons_theta_;
}

std::vector<float>* const & cfa_base::mc_photons_vertex_x() const{
  if(!c_mc_photons_vertex_x_ && b_mc_photons_vertex_x_){
    b_mc_photons_vertex_x_->SetStatus(true);
    chainB_.SetBranchAddress("mc_photons_vertex_x", &mc_photons_vertex_x_, &b_mc_photons_vertex_x_);
    b_mc_photons_vertex_x_->GetEntry(entry_);
    c_mc_photons_vertex_x_ = true;
  }
  return mc_photons_vertex_x_;
}

std::vector<float>* const & cfa_base::mc_photons_vertex_y() const{
  if(!c_mc_photons_vertex_y_ && b_mc_photons_vertex_y_){
    b_mc_photons_vertex_y_->SetStatus(true);
    chainB_.SetBranchAddress("mc_photons_vertex_y", &mc_photons_vertex_y_, &b_mc_photons_vertex_y_);
    b_mc_photons_vertex_y_->GetEntry(entry_);
    c_mc_photons_vertex_y_ = true;
  }
  return mc_photons_vertex_y_;
}

std::vector<float>* const & cfa_base::mc_photons_vertex_z() const{
  if(!c_mc_photons_vertex_z_ && b_mc_photons_vertex_z_){
    b_mc_photons_vertex_z_->SetStatus(true);
    chainB_.SetBranchAddress("mc_photons_vertex_z", &mc_photons_vertex_z_, &b_mc_photons_vertex_z_);
    b_mc_photons_vertex_z_->GetEntry(entry_);
    c_mc_photons_vertex_z_ = true;
  }
  return mc_photons_vertex_z_;
}

std::vector<float>* const & cfa_base::mc_taus_charge() const{
  if(!c_mc_taus_charge_ && b_mc_taus_charge_){
    b_mc_taus_charge_->SetStatus(true);
    chainB_.SetBranchAddress("mc_taus_charge", &mc_taus_charge_, &b_mc_taus_charge_);
    b_mc_taus_charge_->GetEntry(entry_);
    c_mc_taus_charge_ = true;
  }
  return mc_taus_charge_;
}

std::vector<float>* const & cfa_base::mc_taus_energy() const{
  if(!c_mc_taus_energy_ && b_mc_taus_energy_){
    b_mc_taus_energy_->SetStatus(true);
    chainB_.SetBranchAddress("mc_taus_energy", &mc_taus_energy_, &b_mc_taus_energy_);
    b_mc_taus_energy_->GetEntry(entry_);
    c_mc_taus_energy_ = true;
  }
  return mc_taus_energy_;
}

std::vector<float>* const & cfa_base::mc_taus_eta() const{
  if(!c_mc_taus_eta_ && b_mc_taus_eta_){
    b_mc_taus_eta_->SetStatus(true);
    chainB_.SetBranchAddress("mc_taus_eta", &mc_taus_eta_, &b_mc_taus_eta_);
    b_mc_taus_eta_->GetEntry(entry_);
    c_mc_taus_eta_ = true;
  }
  return mc_taus_eta_;
}

std::vector<float>* const & cfa_base::mc_taus_ggrandmother_id() const{
  if(!c_mc_taus_ggrandmother_id_ && b_mc_taus_ggrandmother_id_){
    b_mc_taus_ggrandmother_id_->SetStatus(true);
    chainB_.SetBranchAddress("mc_taus_ggrandmother_id", &mc_taus_ggrandmother_id_, &b_mc_taus_ggrandmother_id_);
    b_mc_taus_ggrandmother_id_->GetEntry(entry_);
    c_mc_taus_ggrandmother_id_ = true;
  }
  return mc_taus_ggrandmother_id_;
}

std::vector<float>* const & cfa_base::mc_taus_grandmother_id() const{
  if(!c_mc_taus_grandmother_id_ && b_mc_taus_grandmother_id_){
    b_mc_taus_grandmother_id_->SetStatus(true);
    chainB_.SetBranchAddress("mc_taus_grandmother_id", &mc_taus_grandmother_id_, &b_mc_taus_grandmother_id_);
    b_mc_taus_grandmother_id_->GetEntry(entry_);
    c_mc_taus_grandmother_id_ = true;
  }
  return mc_taus_grandmother_id_;
}

std::vector<float>* const & cfa_base::mc_taus_id() const{
  if(!c_mc_taus_id_ && b_mc_taus_id_){
    b_mc_taus_id_->SetStatus(true);
    chainB_.SetBranchAddress("mc_taus_id", &mc_taus_id_, &b_mc_taus_id_);
    b_mc_taus_id_->GetEntry(entry_);
    c_mc_taus_id_ = true;
  }
  return mc_taus_id_;
}

std::vector<float>* const & cfa_base::mc_taus_mass() const{
  if(!c_mc_taus_mass_ && b_mc_taus_mass_){
    b_mc_taus_mass_->SetStatus(true);
    chainB_.SetBranchAddress("mc_taus_mass", &mc_taus_mass_, &b_mc_taus_mass_);
    b_mc_taus_mass_->GetEntry(entry_);
    c_mc_taus_mass_ = true;
  }
  return mc_taus_mass_;
}

std::vector<float>* const & cfa_base::mc_taus_mother_id() const{
  if(!c_mc_taus_mother_id_ && b_mc_taus_mother_id_){
    b_mc_taus_mother_id_->SetStatus(true);
    chainB_.SetBranchAddress("mc_taus_mother_id", &mc_taus_mother_id_, &b_mc_taus_mother_id_);
    b_mc_taus_mother_id_->GetEntry(entry_);
    c_mc_taus_mother_id_ = true;
  }
  return mc_taus_mother_id_;
}

std::vector<float>* const & cfa_base::mc_taus_mother_pt() const{
  if(!c_mc_taus_mother_pt_ && b_mc_taus_mother_pt_){
    b_mc_taus_mother_pt_->SetStatus(true);
    chainB_.SetBranchAddress("mc_taus_mother_pt", &mc_taus_mother_pt_, &b_mc_taus_mother_pt_);
    b_mc_taus_mother_pt_->GetEntry(entry_);
    c_mc_taus_mother_pt_ = true;
  }
  return mc_taus_mother_pt_;
}

std::vector<float>* const & cfa_base::mc_taus_numOfDaughters() const{
  if(!c_mc_taus_numOfDaughters_ && b_mc_taus_numOfDaughters_){
    b_mc_taus_numOfDaughters_->SetStatus(true);
    chainB_.SetBranchAddress("mc_taus_numOfDaughters", &mc_taus_numOfDaughters_, &b_mc_taus_numOfDaughters_);
    b_mc_taus_numOfDaughters_->GetEntry(entry_);
    c_mc_taus_numOfDaughters_ = true;
  }
  return mc_taus_numOfDaughters_;
}

std::vector<float>* const & cfa_base::mc_taus_phi() const{
  if(!c_mc_taus_phi_ && b_mc_taus_phi_){
    b_mc_taus_phi_->SetStatus(true);
    chainB_.SetBranchAddress("mc_taus_phi", &mc_taus_phi_, &b_mc_taus_phi_);
    b_mc_taus_phi_->GetEntry(entry_);
    c_mc_taus_phi_ = true;
  }
  return mc_taus_phi_;
}

std::vector<float>* const & cfa_base::mc_taus_pt() const{
  if(!c_mc_taus_pt_ && b_mc_taus_pt_){
    b_mc_taus_pt_->SetStatus(true);
    chainB_.SetBranchAddress("mc_taus_pt", &mc_taus_pt_, &b_mc_taus_pt_);
    b_mc_taus_pt_->GetEntry(entry_);
    c_mc_taus_pt_ = true;
  }
  return mc_taus_pt_;
}

std::vector<float>* const & cfa_base::mc_taus_px() const{
  if(!c_mc_taus_px_ && b_mc_taus_px_){
    b_mc_taus_px_->SetStatus(true);
    chainB_.SetBranchAddress("mc_taus_px", &mc_taus_px_, &b_mc_taus_px_);
    b_mc_taus_px_->GetEntry(entry_);
    c_mc_taus_px_ = true;
  }
  return mc_taus_px_;
}

std::vector<float>* const & cfa_base::mc_taus_py() const{
  if(!c_mc_taus_py_ && b_mc_taus_py_){
    b_mc_taus_py_->SetStatus(true);
    chainB_.SetBranchAddress("mc_taus_py", &mc_taus_py_, &b_mc_taus_py_);
    b_mc_taus_py_->GetEntry(entry_);
    c_mc_taus_py_ = true;
  }
  return mc_taus_py_;
}

std::vector<float>* const & cfa_base::mc_taus_pz() const{
  if(!c_mc_taus_pz_ && b_mc_taus_pz_){
    b_mc_taus_pz_->SetStatus(true);
    chainB_.SetBranchAddress("mc_taus_pz", &mc_taus_pz_, &b_mc_taus_pz_);
    b_mc_taus_pz_->GetEntry(entry_);
    c_mc_taus_pz_ = true;
  }
  return mc_taus_pz_;
}

std::vector<float>* const & cfa_base::mc_taus_status() const{
  if(!c_mc_taus_status_ && b_mc_taus_status_){
    b_mc_taus_status_->SetStatus(true);
    chainB_.SetBranchAddress("mc_taus_status", &mc_taus_status_, &b_mc_taus_status_);
    b_mc_taus_status_->GetEntry(entry_);
    c_mc_taus_status_ = true;
  }
  return mc_taus_status_;
}

std::vector<float>* const & cfa_base::mc_taus_theta() const{
  if(!c_mc_taus_theta_ && b_mc_taus_theta_){
    b_mc_taus_theta_->SetStatus(true);
    chainB_.SetBranchAddress("mc_taus_theta", &mc_taus_theta_, &b_mc_taus_theta_);
    b_mc_taus_theta_->GetEntry(entry_);
    c_mc_taus_theta_ = true;
  }
  return mc_taus_theta_;
}

std::vector<float>* const & cfa_base::mc_taus_vertex_x() const{
  if(!c_mc_taus_vertex_x_ && b_mc_taus_vertex_x_){
    b_mc_taus_vertex_x_->SetStatus(true);
    chainB_.SetBranchAddress("mc_taus_vertex_x", &mc_taus_vertex_x_, &b_mc_taus_vertex_x_);
    b_mc_taus_vertex_x_->GetEntry(entry_);
    c_mc_taus_vertex_x_ = true;
  }
  return mc_taus_vertex_x_;
}

std::vector<float>* const & cfa_base::mc_taus_vertex_y() const{
  if(!c_mc_taus_vertex_y_ && b_mc_taus_vertex_y_){
    b_mc_taus_vertex_y_->SetStatus(true);
    chainB_.SetBranchAddress("mc_taus_vertex_y", &mc_taus_vertex_y_, &b_mc_taus_vertex_y_);
    b_mc_taus_vertex_y_->GetEntry(entry_);
    c_mc_taus_vertex_y_ = true;
  }
  return mc_taus_vertex_y_;
}

std::vector<float>* const & cfa_base::mc_taus_vertex_z() const{
  if(!c_mc_taus_vertex_z_ && b_mc_taus_vertex_z_){
    b_mc_taus_vertex_z_->SetStatus(true);
    chainB_.SetBranchAddress("mc_taus_vertex_z", &mc_taus_vertex_z_, &b_mc_taus_vertex_z_);
    b_mc_taus_vertex_z_->GetEntry(entry_);
    c_mc_taus_vertex_z_ = true;
  }
  return mc_taus_vertex_z_;
}

std::string* const & cfa_base::model_params() const{
  if(!c_model_params_ && b_model_params_){
    b_model_params_->SetStatus(true);
    chainB_.SetBranchAddress("model_params", &model_params_, &b_model_params_);
    b_model_params_->GetEntry(entry_);
    c_model_params_ = true;
  }
  return model_params_;
}

std::vector<float>* const & cfa_base::mus_cIso() const{
  if(!c_mus_cIso_ && b_mus_cIso_){
    b_mus_cIso_->SetStatus(true);
    chainB_.SetBranchAddress("mus_cIso", &mus_cIso_, &b_mus_cIso_);
    b_mus_cIso_->GetEntry(entry_);
    c_mus_cIso_ = true;
  }
  return mus_cIso_;
}

std::vector<float>* const & cfa_base::mus_calEnergyEm() const{
  if(!c_mus_calEnergyEm_ && b_mus_calEnergyEm_){
    b_mus_calEnergyEm_->SetStatus(true);
    chainB_.SetBranchAddress("mus_calEnergyEm", &mus_calEnergyEm_, &b_mus_calEnergyEm_);
    b_mus_calEnergyEm_->GetEntry(entry_);
    c_mus_calEnergyEm_ = true;
  }
  return mus_calEnergyEm_;
}

std::vector<float>* const & cfa_base::mus_calEnergyEmS9() const{
  if(!c_mus_calEnergyEmS9_ && b_mus_calEnergyEmS9_){
    b_mus_calEnergyEmS9_->SetStatus(true);
    chainB_.SetBranchAddress("mus_calEnergyEmS9", &mus_calEnergyEmS9_, &b_mus_calEnergyEmS9_);
    b_mus_calEnergyEmS9_->GetEntry(entry_);
    c_mus_calEnergyEmS9_ = true;
  }
  return mus_calEnergyEmS9_;
}

std::vector<float>* const & cfa_base::mus_calEnergyHad() const{
  if(!c_mus_calEnergyHad_ && b_mus_calEnergyHad_){
    b_mus_calEnergyHad_->SetStatus(true);
    chainB_.SetBranchAddress("mus_calEnergyHad", &mus_calEnergyHad_, &b_mus_calEnergyHad_);
    b_mus_calEnergyHad_->GetEntry(entry_);
    c_mus_calEnergyHad_ = true;
  }
  return mus_calEnergyHad_;
}

std::vector<float>* const & cfa_base::mus_calEnergyHadS9() const{
  if(!c_mus_calEnergyHadS9_ && b_mus_calEnergyHadS9_){
    b_mus_calEnergyHadS9_->SetStatus(true);
    chainB_.SetBranchAddress("mus_calEnergyHadS9", &mus_calEnergyHadS9_, &b_mus_calEnergyHadS9_);
    b_mus_calEnergyHadS9_->GetEntry(entry_);
    c_mus_calEnergyHadS9_ = true;
  }
  return mus_calEnergyHadS9_;
}

std::vector<float>* const & cfa_base::mus_calEnergyHo() const{
  if(!c_mus_calEnergyHo_ && b_mus_calEnergyHo_){
    b_mus_calEnergyHo_->SetStatus(true);
    chainB_.SetBranchAddress("mus_calEnergyHo", &mus_calEnergyHo_, &b_mus_calEnergyHo_);
    b_mus_calEnergyHo_->GetEntry(entry_);
    c_mus_calEnergyHo_ = true;
  }
  return mus_calEnergyHo_;
}

std::vector<float>* const & cfa_base::mus_calEnergyHoS9() const{
  if(!c_mus_calEnergyHoS9_ && b_mus_calEnergyHoS9_){
    b_mus_calEnergyHoS9_->SetStatus(true);
    chainB_.SetBranchAddress("mus_calEnergyHoS9", &mus_calEnergyHoS9_, &b_mus_calEnergyHoS9_);
    b_mus_calEnergyHoS9_->GetEntry(entry_);
    c_mus_calEnergyHoS9_ = true;
  }
  return mus_calEnergyHoS9_;
}

std::vector<float>* const & cfa_base::mus_charge() const{
  if(!c_mus_charge_ && b_mus_charge_){
    b_mus_charge_->SetStatus(true);
    chainB_.SetBranchAddress("mus_charge", &mus_charge_, &b_mus_charge_);
    b_mus_charge_->GetEntry(entry_);
    c_mus_charge_ = true;
  }
  return mus_charge_;
}

std::vector<float>* const & cfa_base::mus_cm_ExpectedHitsInner() const{
  if(!c_mus_cm_ExpectedHitsInner_ && b_mus_cm_ExpectedHitsInner_){
    b_mus_cm_ExpectedHitsInner_->SetStatus(true);
    chainB_.SetBranchAddress("mus_cm_ExpectedHitsInner", &mus_cm_ExpectedHitsInner_, &b_mus_cm_ExpectedHitsInner_);
    b_mus_cm_ExpectedHitsInner_->GetEntry(entry_);
    c_mus_cm_ExpectedHitsInner_ = true;
  }
  return mus_cm_ExpectedHitsInner_;
}

std::vector<float>* const & cfa_base::mus_cm_ExpectedHitsOuter() const{
  if(!c_mus_cm_ExpectedHitsOuter_ && b_mus_cm_ExpectedHitsOuter_){
    b_mus_cm_ExpectedHitsOuter_->SetStatus(true);
    chainB_.SetBranchAddress("mus_cm_ExpectedHitsOuter", &mus_cm_ExpectedHitsOuter_, &b_mus_cm_ExpectedHitsOuter_);
    b_mus_cm_ExpectedHitsOuter_->GetEntry(entry_);
    c_mus_cm_ExpectedHitsOuter_ = true;
  }
  return mus_cm_ExpectedHitsOuter_;
}

std::vector<float>* const & cfa_base::mus_cm_LayersWithMeasurement() const{
  if(!c_mus_cm_LayersWithMeasurement_ && b_mus_cm_LayersWithMeasurement_){
    b_mus_cm_LayersWithMeasurement_->SetStatus(true);
    chainB_.SetBranchAddress("mus_cm_LayersWithMeasurement", &mus_cm_LayersWithMeasurement_, &b_mus_cm_LayersWithMeasurement_);
    b_mus_cm_LayersWithMeasurement_->GetEntry(entry_);
    c_mus_cm_LayersWithMeasurement_ = true;
  }
  return mus_cm_LayersWithMeasurement_;
}

std::vector<float>* const & cfa_base::mus_cm_LayersWithoutMeasurement() const{
  if(!c_mus_cm_LayersWithoutMeasurement_ && b_mus_cm_LayersWithoutMeasurement_){
    b_mus_cm_LayersWithoutMeasurement_->SetStatus(true);
    chainB_.SetBranchAddress("mus_cm_LayersWithoutMeasurement", &mus_cm_LayersWithoutMeasurement_, &b_mus_cm_LayersWithoutMeasurement_);
    b_mus_cm_LayersWithoutMeasurement_->GetEntry(entry_);
    c_mus_cm_LayersWithoutMeasurement_ = true;
  }
  return mus_cm_LayersWithoutMeasurement_;
}

std::vector<float>* const & cfa_base::mus_cm_PixelLayersWithMeasurement() const{
  if(!c_mus_cm_PixelLayersWithMeasurement_ && b_mus_cm_PixelLayersWithMeasurement_){
    b_mus_cm_PixelLayersWithMeasurement_->SetStatus(true);
    chainB_.SetBranchAddress("mus_cm_PixelLayersWithMeasurement", &mus_cm_PixelLayersWithMeasurement_, &b_mus_cm_PixelLayersWithMeasurement_);
    b_mus_cm_PixelLayersWithMeasurement_->GetEntry(entry_);
    c_mus_cm_PixelLayersWithMeasurement_ = true;
  }
  return mus_cm_PixelLayersWithMeasurement_;
}

std::vector<float>* const & cfa_base::mus_cm_ValidStripLayersWithMonoAndStereoHit() const{
  if(!c_mus_cm_ValidStripLayersWithMonoAndStereoHit_ && b_mus_cm_ValidStripLayersWithMonoAndStereoHit_){
    b_mus_cm_ValidStripLayersWithMonoAndStereoHit_->SetStatus(true);
    chainB_.SetBranchAddress("mus_cm_ValidStripLayersWithMonoAndStereoHit", &mus_cm_ValidStripLayersWithMonoAndStereoHit_, &b_mus_cm_ValidStripLayersWithMonoAndStereoHit_);
    b_mus_cm_ValidStripLayersWithMonoAndStereoHit_->GetEntry(entry_);
    c_mus_cm_ValidStripLayersWithMonoAndStereoHit_ = true;
  }
  return mus_cm_ValidStripLayersWithMonoAndStereoHit_;
}

std::vector<float>* const & cfa_base::mus_cm_chg() const{
  if(!c_mus_cm_chg_ && b_mus_cm_chg_){
    b_mus_cm_chg_->SetStatus(true);
    chainB_.SetBranchAddress("mus_cm_chg", &mus_cm_chg_, &b_mus_cm_chg_);
    b_mus_cm_chg_->GetEntry(entry_);
    c_mus_cm_chg_ = true;
  }
  return mus_cm_chg_;
}

std::vector<float>* const & cfa_base::mus_cm_chi2() const{
  if(!c_mus_cm_chi2_ && b_mus_cm_chi2_){
    b_mus_cm_chi2_->SetStatus(true);
    chainB_.SetBranchAddress("mus_cm_chi2", &mus_cm_chi2_, &b_mus_cm_chi2_);
    b_mus_cm_chi2_->GetEntry(entry_);
    c_mus_cm_chi2_ = true;
  }
  return mus_cm_chi2_;
}

std::vector<float>* const & cfa_base::mus_cm_d0dum() const{
  if(!c_mus_cm_d0dum_ && b_mus_cm_d0dum_){
    b_mus_cm_d0dum_->SetStatus(true);
    chainB_.SetBranchAddress("mus_cm_d0dum", &mus_cm_d0dum_, &b_mus_cm_d0dum_);
    b_mus_cm_d0dum_->GetEntry(entry_);
    c_mus_cm_d0dum_ = true;
  }
  return mus_cm_d0dum_;
}

std::vector<float>* const & cfa_base::mus_cm_d0dumErr() const{
  if(!c_mus_cm_d0dumErr_ && b_mus_cm_d0dumErr_){
    b_mus_cm_d0dumErr_->SetStatus(true);
    chainB_.SetBranchAddress("mus_cm_d0dumErr", &mus_cm_d0dumErr_, &b_mus_cm_d0dumErr_);
    b_mus_cm_d0dumErr_->GetEntry(entry_);
    c_mus_cm_d0dumErr_ = true;
  }
  return mus_cm_d0dumErr_;
}

std::vector<float>* const & cfa_base::mus_cm_dz() const{
  if(!c_mus_cm_dz_ && b_mus_cm_dz_){
    b_mus_cm_dz_->SetStatus(true);
    chainB_.SetBranchAddress("mus_cm_dz", &mus_cm_dz_, &b_mus_cm_dz_);
    b_mus_cm_dz_->GetEntry(entry_);
    c_mus_cm_dz_ = true;
  }
  return mus_cm_dz_;
}

std::vector<float>* const & cfa_base::mus_cm_dzErr() const{
  if(!c_mus_cm_dzErr_ && b_mus_cm_dzErr_){
    b_mus_cm_dzErr_->SetStatus(true);
    chainB_.SetBranchAddress("mus_cm_dzErr", &mus_cm_dzErr_, &b_mus_cm_dzErr_);
    b_mus_cm_dzErr_->GetEntry(entry_);
    c_mus_cm_dzErr_ = true;
  }
  return mus_cm_dzErr_;
}

std::vector<float>* const & cfa_base::mus_cm_eta() const{
  if(!c_mus_cm_eta_ && b_mus_cm_eta_){
    b_mus_cm_eta_->SetStatus(true);
    chainB_.SetBranchAddress("mus_cm_eta", &mus_cm_eta_, &b_mus_cm_eta_);
    b_mus_cm_eta_->GetEntry(entry_);
    c_mus_cm_eta_ = true;
  }
  return mus_cm_eta_;
}

std::vector<float>* const & cfa_base::mus_cm_etaErr() const{
  if(!c_mus_cm_etaErr_ && b_mus_cm_etaErr_){
    b_mus_cm_etaErr_->SetStatus(true);
    chainB_.SetBranchAddress("mus_cm_etaErr", &mus_cm_etaErr_, &b_mus_cm_etaErr_);
    b_mus_cm_etaErr_->GetEntry(entry_);
    c_mus_cm_etaErr_ = true;
  }
  return mus_cm_etaErr_;
}

std::vector<float>* const & cfa_base::mus_cm_ndof() const{
  if(!c_mus_cm_ndof_ && b_mus_cm_ndof_){
    b_mus_cm_ndof_->SetStatus(true);
    chainB_.SetBranchAddress("mus_cm_ndof", &mus_cm_ndof_, &b_mus_cm_ndof_);
    b_mus_cm_ndof_->GetEntry(entry_);
    c_mus_cm_ndof_ = true;
  }
  return mus_cm_ndof_;
}

std::vector<float>* const & cfa_base::mus_cm_numlosthits() const{
  if(!c_mus_cm_numlosthits_ && b_mus_cm_numlosthits_){
    b_mus_cm_numlosthits_->SetStatus(true);
    chainB_.SetBranchAddress("mus_cm_numlosthits", &mus_cm_numlosthits_, &b_mus_cm_numlosthits_);
    b_mus_cm_numlosthits_->GetEntry(entry_);
    c_mus_cm_numlosthits_ = true;
  }
  return mus_cm_numlosthits_;
}

std::vector<float>* const & cfa_base::mus_cm_numvalMuonhits() const{
  if(!c_mus_cm_numvalMuonhits_ && b_mus_cm_numvalMuonhits_){
    b_mus_cm_numvalMuonhits_->SetStatus(true);
    chainB_.SetBranchAddress("mus_cm_numvalMuonhits", &mus_cm_numvalMuonhits_, &b_mus_cm_numvalMuonhits_);
    b_mus_cm_numvalMuonhits_->GetEntry(entry_);
    c_mus_cm_numvalMuonhits_ = true;
  }
  return mus_cm_numvalMuonhits_;
}

std::vector<float>* const & cfa_base::mus_cm_numvalhits() const{
  if(!c_mus_cm_numvalhits_ && b_mus_cm_numvalhits_){
    b_mus_cm_numvalhits_->SetStatus(true);
    chainB_.SetBranchAddress("mus_cm_numvalhits", &mus_cm_numvalhits_, &b_mus_cm_numvalhits_);
    b_mus_cm_numvalhits_->GetEntry(entry_);
    c_mus_cm_numvalhits_ = true;
  }
  return mus_cm_numvalhits_;
}

std::vector<float>* const & cfa_base::mus_cm_phi() const{
  if(!c_mus_cm_phi_ && b_mus_cm_phi_){
    b_mus_cm_phi_->SetStatus(true);
    chainB_.SetBranchAddress("mus_cm_phi", &mus_cm_phi_, &b_mus_cm_phi_);
    b_mus_cm_phi_->GetEntry(entry_);
    c_mus_cm_phi_ = true;
  }
  return mus_cm_phi_;
}

std::vector<float>* const & cfa_base::mus_cm_phiErr() const{
  if(!c_mus_cm_phiErr_ && b_mus_cm_phiErr_){
    b_mus_cm_phiErr_->SetStatus(true);
    chainB_.SetBranchAddress("mus_cm_phiErr", &mus_cm_phiErr_, &b_mus_cm_phiErr_);
    b_mus_cm_phiErr_->GetEntry(entry_);
    c_mus_cm_phiErr_ = true;
  }
  return mus_cm_phiErr_;
}

std::vector<float>* const & cfa_base::mus_cm_pt() const{
  if(!c_mus_cm_pt_ && b_mus_cm_pt_){
    b_mus_cm_pt_->SetStatus(true);
    chainB_.SetBranchAddress("mus_cm_pt", &mus_cm_pt_, &b_mus_cm_pt_);
    b_mus_cm_pt_->GetEntry(entry_);
    c_mus_cm_pt_ = true;
  }
  return mus_cm_pt_;
}

std::vector<float>* const & cfa_base::mus_cm_ptErr() const{
  if(!c_mus_cm_ptErr_ && b_mus_cm_ptErr_){
    b_mus_cm_ptErr_->SetStatus(true);
    chainB_.SetBranchAddress("mus_cm_ptErr", &mus_cm_ptErr_, &b_mus_cm_ptErr_);
    b_mus_cm_ptErr_->GetEntry(entry_);
    c_mus_cm_ptErr_ = true;
  }
  return mus_cm_ptErr_;
}

std::vector<float>* const & cfa_base::mus_cm_px() const{
  if(!c_mus_cm_px_ && b_mus_cm_px_){
    b_mus_cm_px_->SetStatus(true);
    chainB_.SetBranchAddress("mus_cm_px", &mus_cm_px_, &b_mus_cm_px_);
    b_mus_cm_px_->GetEntry(entry_);
    c_mus_cm_px_ = true;
  }
  return mus_cm_px_;
}

std::vector<float>* const & cfa_base::mus_cm_py() const{
  if(!c_mus_cm_py_ && b_mus_cm_py_){
    b_mus_cm_py_->SetStatus(true);
    chainB_.SetBranchAddress("mus_cm_py", &mus_cm_py_, &b_mus_cm_py_);
    b_mus_cm_py_->GetEntry(entry_);
    c_mus_cm_py_ = true;
  }
  return mus_cm_py_;
}

std::vector<float>* const & cfa_base::mus_cm_pz() const{
  if(!c_mus_cm_pz_ && b_mus_cm_pz_){
    b_mus_cm_pz_->SetStatus(true);
    chainB_.SetBranchAddress("mus_cm_pz", &mus_cm_pz_, &b_mus_cm_pz_);
    b_mus_cm_pz_->GetEntry(entry_);
    c_mus_cm_pz_ = true;
  }
  return mus_cm_pz_;
}

std::vector<float>* const & cfa_base::mus_cm_theta() const{
  if(!c_mus_cm_theta_ && b_mus_cm_theta_){
    b_mus_cm_theta_->SetStatus(true);
    chainB_.SetBranchAddress("mus_cm_theta", &mus_cm_theta_, &b_mus_cm_theta_);
    b_mus_cm_theta_->GetEntry(entry_);
    c_mus_cm_theta_ = true;
  }
  return mus_cm_theta_;
}

std::vector<float>* const & cfa_base::mus_cm_vx() const{
  if(!c_mus_cm_vx_ && b_mus_cm_vx_){
    b_mus_cm_vx_->SetStatus(true);
    chainB_.SetBranchAddress("mus_cm_vx", &mus_cm_vx_, &b_mus_cm_vx_);
    b_mus_cm_vx_->GetEntry(entry_);
    c_mus_cm_vx_ = true;
  }
  return mus_cm_vx_;
}

std::vector<float>* const & cfa_base::mus_cm_vy() const{
  if(!c_mus_cm_vy_ && b_mus_cm_vy_){
    b_mus_cm_vy_->SetStatus(true);
    chainB_.SetBranchAddress("mus_cm_vy", &mus_cm_vy_, &b_mus_cm_vy_);
    b_mus_cm_vy_->GetEntry(entry_);
    c_mus_cm_vy_ = true;
  }
  return mus_cm_vy_;
}

std::vector<float>* const & cfa_base::mus_cm_vz() const{
  if(!c_mus_cm_vz_ && b_mus_cm_vz_){
    b_mus_cm_vz_->SetStatus(true);
    chainB_.SetBranchAddress("mus_cm_vz", &mus_cm_vz_, &b_mus_cm_vz_);
    b_mus_cm_vz_->GetEntry(entry_);
    c_mus_cm_vz_ = true;
  }
  return mus_cm_vz_;
}

std::vector<float>* const & cfa_base::mus_dB() const{
  if(!c_mus_dB_ && b_mus_dB_){
    b_mus_dB_->SetStatus(true);
    chainB_.SetBranchAddress("mus_dB", &mus_dB_, &b_mus_dB_);
    b_mus_dB_->GetEntry(entry_);
    c_mus_dB_ = true;
  }
  return mus_dB_;
}

std::vector<float>* const & cfa_base::mus_ecalIso() const{
  if(!c_mus_ecalIso_ && b_mus_ecalIso_){
    b_mus_ecalIso_->SetStatus(true);
    chainB_.SetBranchAddress("mus_ecalIso", &mus_ecalIso_, &b_mus_ecalIso_);
    b_mus_ecalIso_->GetEntry(entry_);
    c_mus_ecalIso_ = true;
  }
  return mus_ecalIso_;
}

std::vector<float>* const & cfa_base::mus_ecalvetoDep() const{
  if(!c_mus_ecalvetoDep_ && b_mus_ecalvetoDep_){
    b_mus_ecalvetoDep_->SetStatus(true);
    chainB_.SetBranchAddress("mus_ecalvetoDep", &mus_ecalvetoDep_, &b_mus_ecalvetoDep_);
    b_mus_ecalvetoDep_->GetEntry(entry_);
    c_mus_ecalvetoDep_ = true;
  }
  return mus_ecalvetoDep_;
}

std::vector<float>* const & cfa_base::mus_energy() const{
  if(!c_mus_energy_ && b_mus_energy_){
    b_mus_energy_->SetStatus(true);
    chainB_.SetBranchAddress("mus_energy", &mus_energy_, &b_mus_energy_);
    b_mus_energy_->GetEntry(entry_);
    c_mus_energy_ = true;
  }
  return mus_energy_;
}

std::vector<float>* const & cfa_base::mus_et() const{
  if(!c_mus_et_ && b_mus_et_){
    b_mus_et_->SetStatus(true);
    chainB_.SetBranchAddress("mus_et", &mus_et_, &b_mus_et_);
    b_mus_et_->GetEntry(entry_);
    c_mus_et_ = true;
  }
  return mus_et_;
}

std::vector<float>* const & cfa_base::mus_eta() const{
  if(!c_mus_eta_ && b_mus_eta_){
    b_mus_eta_->SetStatus(true);
    chainB_.SetBranchAddress("mus_eta", &mus_eta_, &b_mus_eta_);
    b_mus_eta_->GetEntry(entry_);
    c_mus_eta_ = true;
  }
  return mus_eta_;
}

std::vector<float>* const & cfa_base::mus_gen_et() const{
  if(!c_mus_gen_et_ && b_mus_gen_et_){
    b_mus_gen_et_->SetStatus(true);
    chainB_.SetBranchAddress("mus_gen_et", &mus_gen_et_, &b_mus_gen_et_);
    b_mus_gen_et_->GetEntry(entry_);
    c_mus_gen_et_ = true;
  }
  return mus_gen_et_;
}

std::vector<float>* const & cfa_base::mus_gen_eta() const{
  if(!c_mus_gen_eta_ && b_mus_gen_eta_){
    b_mus_gen_eta_->SetStatus(true);
    chainB_.SetBranchAddress("mus_gen_eta", &mus_gen_eta_, &b_mus_gen_eta_);
    b_mus_gen_eta_->GetEntry(entry_);
    c_mus_gen_eta_ = true;
  }
  return mus_gen_eta_;
}

std::vector<float>* const & cfa_base::mus_gen_id() const{
  if(!c_mus_gen_id_ && b_mus_gen_id_){
    b_mus_gen_id_->SetStatus(true);
    chainB_.SetBranchAddress("mus_gen_id", &mus_gen_id_, &b_mus_gen_id_);
    b_mus_gen_id_->GetEntry(entry_);
    c_mus_gen_id_ = true;
  }
  return mus_gen_id_;
}

std::vector<float>* const & cfa_base::mus_gen_mother_et() const{
  if(!c_mus_gen_mother_et_ && b_mus_gen_mother_et_){
    b_mus_gen_mother_et_->SetStatus(true);
    chainB_.SetBranchAddress("mus_gen_mother_et", &mus_gen_mother_et_, &b_mus_gen_mother_et_);
    b_mus_gen_mother_et_->GetEntry(entry_);
    c_mus_gen_mother_et_ = true;
  }
  return mus_gen_mother_et_;
}

std::vector<float>* const & cfa_base::mus_gen_mother_eta() const{
  if(!c_mus_gen_mother_eta_ && b_mus_gen_mother_eta_){
    b_mus_gen_mother_eta_->SetStatus(true);
    chainB_.SetBranchAddress("mus_gen_mother_eta", &mus_gen_mother_eta_, &b_mus_gen_mother_eta_);
    b_mus_gen_mother_eta_->GetEntry(entry_);
    c_mus_gen_mother_eta_ = true;
  }
  return mus_gen_mother_eta_;
}

std::vector<float>* const & cfa_base::mus_gen_mother_id() const{
  if(!c_mus_gen_mother_id_ && b_mus_gen_mother_id_){
    b_mus_gen_mother_id_->SetStatus(true);
    chainB_.SetBranchAddress("mus_gen_mother_id", &mus_gen_mother_id_, &b_mus_gen_mother_id_);
    b_mus_gen_mother_id_->GetEntry(entry_);
    c_mus_gen_mother_id_ = true;
  }
  return mus_gen_mother_id_;
}

std::vector<float>* const & cfa_base::mus_gen_mother_phi() const{
  if(!c_mus_gen_mother_phi_ && b_mus_gen_mother_phi_){
    b_mus_gen_mother_phi_->SetStatus(true);
    chainB_.SetBranchAddress("mus_gen_mother_phi", &mus_gen_mother_phi_, &b_mus_gen_mother_phi_);
    b_mus_gen_mother_phi_->GetEntry(entry_);
    c_mus_gen_mother_phi_ = true;
  }
  return mus_gen_mother_phi_;
}

std::vector<float>* const & cfa_base::mus_gen_mother_pt() const{
  if(!c_mus_gen_mother_pt_ && b_mus_gen_mother_pt_){
    b_mus_gen_mother_pt_->SetStatus(true);
    chainB_.SetBranchAddress("mus_gen_mother_pt", &mus_gen_mother_pt_, &b_mus_gen_mother_pt_);
    b_mus_gen_mother_pt_->GetEntry(entry_);
    c_mus_gen_mother_pt_ = true;
  }
  return mus_gen_mother_pt_;
}

std::vector<float>* const & cfa_base::mus_gen_mother_px() const{
  if(!c_mus_gen_mother_px_ && b_mus_gen_mother_px_){
    b_mus_gen_mother_px_->SetStatus(true);
    chainB_.SetBranchAddress("mus_gen_mother_px", &mus_gen_mother_px_, &b_mus_gen_mother_px_);
    b_mus_gen_mother_px_->GetEntry(entry_);
    c_mus_gen_mother_px_ = true;
  }
  return mus_gen_mother_px_;
}

std::vector<float>* const & cfa_base::mus_gen_mother_py() const{
  if(!c_mus_gen_mother_py_ && b_mus_gen_mother_py_){
    b_mus_gen_mother_py_->SetStatus(true);
    chainB_.SetBranchAddress("mus_gen_mother_py", &mus_gen_mother_py_, &b_mus_gen_mother_py_);
    b_mus_gen_mother_py_->GetEntry(entry_);
    c_mus_gen_mother_py_ = true;
  }
  return mus_gen_mother_py_;
}

std::vector<float>* const & cfa_base::mus_gen_mother_pz() const{
  if(!c_mus_gen_mother_pz_ && b_mus_gen_mother_pz_){
    b_mus_gen_mother_pz_->SetStatus(true);
    chainB_.SetBranchAddress("mus_gen_mother_pz", &mus_gen_mother_pz_, &b_mus_gen_mother_pz_);
    b_mus_gen_mother_pz_->GetEntry(entry_);
    c_mus_gen_mother_pz_ = true;
  }
  return mus_gen_mother_pz_;
}

std::vector<float>* const & cfa_base::mus_gen_mother_theta() const{
  if(!c_mus_gen_mother_theta_ && b_mus_gen_mother_theta_){
    b_mus_gen_mother_theta_->SetStatus(true);
    chainB_.SetBranchAddress("mus_gen_mother_theta", &mus_gen_mother_theta_, &b_mus_gen_mother_theta_);
    b_mus_gen_mother_theta_->GetEntry(entry_);
    c_mus_gen_mother_theta_ = true;
  }
  return mus_gen_mother_theta_;
}

std::vector<float>* const & cfa_base::mus_gen_phi() const{
  if(!c_mus_gen_phi_ && b_mus_gen_phi_){
    b_mus_gen_phi_->SetStatus(true);
    chainB_.SetBranchAddress("mus_gen_phi", &mus_gen_phi_, &b_mus_gen_phi_);
    b_mus_gen_phi_->GetEntry(entry_);
    c_mus_gen_phi_ = true;
  }
  return mus_gen_phi_;
}

std::vector<float>* const & cfa_base::mus_gen_pt() const{
  if(!c_mus_gen_pt_ && b_mus_gen_pt_){
    b_mus_gen_pt_->SetStatus(true);
    chainB_.SetBranchAddress("mus_gen_pt", &mus_gen_pt_, &b_mus_gen_pt_);
    b_mus_gen_pt_->GetEntry(entry_);
    c_mus_gen_pt_ = true;
  }
  return mus_gen_pt_;
}

std::vector<float>* const & cfa_base::mus_gen_px() const{
  if(!c_mus_gen_px_ && b_mus_gen_px_){
    b_mus_gen_px_->SetStatus(true);
    chainB_.SetBranchAddress("mus_gen_px", &mus_gen_px_, &b_mus_gen_px_);
    b_mus_gen_px_->GetEntry(entry_);
    c_mus_gen_px_ = true;
  }
  return mus_gen_px_;
}

std::vector<float>* const & cfa_base::mus_gen_py() const{
  if(!c_mus_gen_py_ && b_mus_gen_py_){
    b_mus_gen_py_->SetStatus(true);
    chainB_.SetBranchAddress("mus_gen_py", &mus_gen_py_, &b_mus_gen_py_);
    b_mus_gen_py_->GetEntry(entry_);
    c_mus_gen_py_ = true;
  }
  return mus_gen_py_;
}

std::vector<float>* const & cfa_base::mus_gen_pz() const{
  if(!c_mus_gen_pz_ && b_mus_gen_pz_){
    b_mus_gen_pz_->SetStatus(true);
    chainB_.SetBranchAddress("mus_gen_pz", &mus_gen_pz_, &b_mus_gen_pz_);
    b_mus_gen_pz_->GetEntry(entry_);
    c_mus_gen_pz_ = true;
  }
  return mus_gen_pz_;
}

std::vector<float>* const & cfa_base::mus_gen_theta() const{
  if(!c_mus_gen_theta_ && b_mus_gen_theta_){
    b_mus_gen_theta_->SetStatus(true);
    chainB_.SetBranchAddress("mus_gen_theta", &mus_gen_theta_, &b_mus_gen_theta_);
    b_mus_gen_theta_->GetEntry(entry_);
    c_mus_gen_theta_ = true;
  }
  return mus_gen_theta_;
}

std::vector<float>* const & cfa_base::mus_hcalIso() const{
  if(!c_mus_hcalIso_ && b_mus_hcalIso_){
    b_mus_hcalIso_->SetStatus(true);
    chainB_.SetBranchAddress("mus_hcalIso", &mus_hcalIso_, &b_mus_hcalIso_);
    b_mus_hcalIso_->GetEntry(entry_);
    c_mus_hcalIso_ = true;
  }
  return mus_hcalIso_;
}

std::vector<float>* const & cfa_base::mus_hcalvetoDep() const{
  if(!c_mus_hcalvetoDep_ && b_mus_hcalvetoDep_){
    b_mus_hcalvetoDep_->SetStatus(true);
    chainB_.SetBranchAddress("mus_hcalvetoDep", &mus_hcalvetoDep_, &b_mus_hcalvetoDep_);
    b_mus_hcalvetoDep_->GetEntry(entry_);
    c_mus_hcalvetoDep_ = true;
  }
  return mus_hcalvetoDep_;
}

std::vector<float>* const & cfa_base::mus_id_All() const{
  if(!c_mus_id_All_ && b_mus_id_All_){
    b_mus_id_All_->SetStatus(true);
    chainB_.SetBranchAddress("mus_id_All", &mus_id_All_, &b_mus_id_All_);
    b_mus_id_All_->GetEntry(entry_);
    c_mus_id_All_ = true;
  }
  return mus_id_All_;
}

std::vector<float>* const & cfa_base::mus_id_AllArbitrated() const{
  if(!c_mus_id_AllArbitrated_ && b_mus_id_AllArbitrated_){
    b_mus_id_AllArbitrated_->SetStatus(true);
    chainB_.SetBranchAddress("mus_id_AllArbitrated", &mus_id_AllArbitrated_, &b_mus_id_AllArbitrated_);
    b_mus_id_AllArbitrated_->GetEntry(entry_);
    c_mus_id_AllArbitrated_ = true;
  }
  return mus_id_AllArbitrated_;
}

std::vector<float>* const & cfa_base::mus_id_AllGlobalMuons() const{
  if(!c_mus_id_AllGlobalMuons_ && b_mus_id_AllGlobalMuons_){
    b_mus_id_AllGlobalMuons_->SetStatus(true);
    chainB_.SetBranchAddress("mus_id_AllGlobalMuons", &mus_id_AllGlobalMuons_, &b_mus_id_AllGlobalMuons_);
    b_mus_id_AllGlobalMuons_->GetEntry(entry_);
    c_mus_id_AllGlobalMuons_ = true;
  }
  return mus_id_AllGlobalMuons_;
}

std::vector<float>* const & cfa_base::mus_id_AllStandAloneMuons() const{
  if(!c_mus_id_AllStandAloneMuons_ && b_mus_id_AllStandAloneMuons_){
    b_mus_id_AllStandAloneMuons_->SetStatus(true);
    chainB_.SetBranchAddress("mus_id_AllStandAloneMuons", &mus_id_AllStandAloneMuons_, &b_mus_id_AllStandAloneMuons_);
    b_mus_id_AllStandAloneMuons_->GetEntry(entry_);
    c_mus_id_AllStandAloneMuons_ = true;
  }
  return mus_id_AllStandAloneMuons_;
}

std::vector<float>* const & cfa_base::mus_id_AllTrackerMuons() const{
  if(!c_mus_id_AllTrackerMuons_ && b_mus_id_AllTrackerMuons_){
    b_mus_id_AllTrackerMuons_->SetStatus(true);
    chainB_.SetBranchAddress("mus_id_AllTrackerMuons", &mus_id_AllTrackerMuons_, &b_mus_id_AllTrackerMuons_);
    b_mus_id_AllTrackerMuons_->GetEntry(entry_);
    c_mus_id_AllTrackerMuons_ = true;
  }
  return mus_id_AllTrackerMuons_;
}

std::vector<float>* const & cfa_base::mus_id_GlobalMuonPromptTight() const{
  if(!c_mus_id_GlobalMuonPromptTight_ && b_mus_id_GlobalMuonPromptTight_){
    b_mus_id_GlobalMuonPromptTight_->SetStatus(true);
    chainB_.SetBranchAddress("mus_id_GlobalMuonPromptTight", &mus_id_GlobalMuonPromptTight_, &b_mus_id_GlobalMuonPromptTight_);
    b_mus_id_GlobalMuonPromptTight_->GetEntry(entry_);
    c_mus_id_GlobalMuonPromptTight_ = true;
  }
  return mus_id_GlobalMuonPromptTight_;
}

std::vector<float>* const & cfa_base::mus_id_TM2DCompatibilityLoose() const{
  if(!c_mus_id_TM2DCompatibilityLoose_ && b_mus_id_TM2DCompatibilityLoose_){
    b_mus_id_TM2DCompatibilityLoose_->SetStatus(true);
    chainB_.SetBranchAddress("mus_id_TM2DCompatibilityLoose", &mus_id_TM2DCompatibilityLoose_, &b_mus_id_TM2DCompatibilityLoose_);
    b_mus_id_TM2DCompatibilityLoose_->GetEntry(entry_);
    c_mus_id_TM2DCompatibilityLoose_ = true;
  }
  return mus_id_TM2DCompatibilityLoose_;
}

std::vector<float>* const & cfa_base::mus_id_TM2DCompatibilityTight() const{
  if(!c_mus_id_TM2DCompatibilityTight_ && b_mus_id_TM2DCompatibilityTight_){
    b_mus_id_TM2DCompatibilityTight_->SetStatus(true);
    chainB_.SetBranchAddress("mus_id_TM2DCompatibilityTight", &mus_id_TM2DCompatibilityTight_, &b_mus_id_TM2DCompatibilityTight_);
    b_mus_id_TM2DCompatibilityTight_->GetEntry(entry_);
    c_mus_id_TM2DCompatibilityTight_ = true;
  }
  return mus_id_TM2DCompatibilityTight_;
}

std::vector<float>* const & cfa_base::mus_id_TMLastStationLoose() const{
  if(!c_mus_id_TMLastStationLoose_ && b_mus_id_TMLastStationLoose_){
    b_mus_id_TMLastStationLoose_->SetStatus(true);
    chainB_.SetBranchAddress("mus_id_TMLastStationLoose", &mus_id_TMLastStationLoose_, &b_mus_id_TMLastStationLoose_);
    b_mus_id_TMLastStationLoose_->GetEntry(entry_);
    c_mus_id_TMLastStationLoose_ = true;
  }
  return mus_id_TMLastStationLoose_;
}

std::vector<float>* const & cfa_base::mus_id_TMLastStationOptimizedLowPtLoose() const{
  if(!c_mus_id_TMLastStationOptimizedLowPtLoose_ && b_mus_id_TMLastStationOptimizedLowPtLoose_){
    b_mus_id_TMLastStationOptimizedLowPtLoose_->SetStatus(true);
    chainB_.SetBranchAddress("mus_id_TMLastStationOptimizedLowPtLoose", &mus_id_TMLastStationOptimizedLowPtLoose_, &b_mus_id_TMLastStationOptimizedLowPtLoose_);
    b_mus_id_TMLastStationOptimizedLowPtLoose_->GetEntry(entry_);
    c_mus_id_TMLastStationOptimizedLowPtLoose_ = true;
  }
  return mus_id_TMLastStationOptimizedLowPtLoose_;
}

std::vector<float>* const & cfa_base::mus_id_TMLastStationOptimizedLowPtTight() const{
  if(!c_mus_id_TMLastStationOptimizedLowPtTight_ && b_mus_id_TMLastStationOptimizedLowPtTight_){
    b_mus_id_TMLastStationOptimizedLowPtTight_->SetStatus(true);
    chainB_.SetBranchAddress("mus_id_TMLastStationOptimizedLowPtTight", &mus_id_TMLastStationOptimizedLowPtTight_, &b_mus_id_TMLastStationOptimizedLowPtTight_);
    b_mus_id_TMLastStationOptimizedLowPtTight_->GetEntry(entry_);
    c_mus_id_TMLastStationOptimizedLowPtTight_ = true;
  }
  return mus_id_TMLastStationOptimizedLowPtTight_;
}

std::vector<float>* const & cfa_base::mus_id_TMLastStationTight() const{
  if(!c_mus_id_TMLastStationTight_ && b_mus_id_TMLastStationTight_){
    b_mus_id_TMLastStationTight_->SetStatus(true);
    chainB_.SetBranchAddress("mus_id_TMLastStationTight", &mus_id_TMLastStationTight_, &b_mus_id_TMLastStationTight_);
    b_mus_id_TMLastStationTight_->GetEntry(entry_);
    c_mus_id_TMLastStationTight_ = true;
  }
  return mus_id_TMLastStationTight_;
}

std::vector<float>* const & cfa_base::mus_id_TMOneStationLoose() const{
  if(!c_mus_id_TMOneStationLoose_ && b_mus_id_TMOneStationLoose_){
    b_mus_id_TMOneStationLoose_->SetStatus(true);
    chainB_.SetBranchAddress("mus_id_TMOneStationLoose", &mus_id_TMOneStationLoose_, &b_mus_id_TMOneStationLoose_);
    b_mus_id_TMOneStationLoose_->GetEntry(entry_);
    c_mus_id_TMOneStationLoose_ = true;
  }
  return mus_id_TMOneStationLoose_;
}

std::vector<float>* const & cfa_base::mus_id_TMOneStationTight() const{
  if(!c_mus_id_TMOneStationTight_ && b_mus_id_TMOneStationTight_){
    b_mus_id_TMOneStationTight_->SetStatus(true);
    chainB_.SetBranchAddress("mus_id_TMOneStationTight", &mus_id_TMOneStationTight_, &b_mus_id_TMOneStationTight_);
    b_mus_id_TMOneStationTight_->GetEntry(entry_);
    c_mus_id_TMOneStationTight_ = true;
  }
  return mus_id_TMOneStationTight_;
}

std::vector<float>* const & cfa_base::mus_id_TrackerMuonArbitrated() const{
  if(!c_mus_id_TrackerMuonArbitrated_ && b_mus_id_TrackerMuonArbitrated_){
    b_mus_id_TrackerMuonArbitrated_->SetStatus(true);
    chainB_.SetBranchAddress("mus_id_TrackerMuonArbitrated", &mus_id_TrackerMuonArbitrated_, &b_mus_id_TrackerMuonArbitrated_);
    b_mus_id_TrackerMuonArbitrated_->GetEntry(entry_);
    c_mus_id_TrackerMuonArbitrated_ = true;
  }
  return mus_id_TrackerMuonArbitrated_;
}

std::vector<float>* const & cfa_base::mus_isCaloMuon() const{
  if(!c_mus_isCaloMuon_ && b_mus_isCaloMuon_){
    b_mus_isCaloMuon_->SetStatus(true);
    chainB_.SetBranchAddress("mus_isCaloMuon", &mus_isCaloMuon_, &b_mus_isCaloMuon_);
    b_mus_isCaloMuon_->GetEntry(entry_);
    c_mus_isCaloMuon_ = true;
  }
  return mus_isCaloMuon_;
}

std::vector<float>* const & cfa_base::mus_isConvertedPhoton() const{
  if(!c_mus_isConvertedPhoton_ && b_mus_isConvertedPhoton_){
    b_mus_isConvertedPhoton_->SetStatus(true);
    chainB_.SetBranchAddress("mus_isConvertedPhoton", &mus_isConvertedPhoton_, &b_mus_isConvertedPhoton_);
    b_mus_isConvertedPhoton_->GetEntry(entry_);
    c_mus_isConvertedPhoton_ = true;
  }
  return mus_isConvertedPhoton_;
}

std::vector<float>* const & cfa_base::mus_isElectron() const{
  if(!c_mus_isElectron_ && b_mus_isElectron_){
    b_mus_isElectron_->SetStatus(true);
    chainB_.SetBranchAddress("mus_isElectron", &mus_isElectron_, &b_mus_isElectron_);
    b_mus_isElectron_->GetEntry(entry_);
    c_mus_isElectron_ = true;
  }
  return mus_isElectron_;
}

std::vector<float>* const & cfa_base::mus_isGlobalMuon() const{
  if(!c_mus_isGlobalMuon_ && b_mus_isGlobalMuon_){
    b_mus_isGlobalMuon_->SetStatus(true);
    chainB_.SetBranchAddress("mus_isGlobalMuon", &mus_isGlobalMuon_, &b_mus_isGlobalMuon_);
    b_mus_isGlobalMuon_->GetEntry(entry_);
    c_mus_isGlobalMuon_ = true;
  }
  return mus_isGlobalMuon_;
}

std::vector<float>* const & cfa_base::mus_isPFMuon() const{
  if(!c_mus_isPFMuon_ && b_mus_isPFMuon_){
    b_mus_isPFMuon_->SetStatus(true);
    chainB_.SetBranchAddress("mus_isPFMuon", &mus_isPFMuon_, &b_mus_isPFMuon_);
    b_mus_isPFMuon_->GetEntry(entry_);
    c_mus_isPFMuon_ = true;
  }
  return mus_isPFMuon_;
}

std::vector<float>* const & cfa_base::mus_isPhoton() const{
  if(!c_mus_isPhoton_ && b_mus_isPhoton_){
    b_mus_isPhoton_->SetStatus(true);
    chainB_.SetBranchAddress("mus_isPhoton", &mus_isPhoton_, &b_mus_isPhoton_);
    b_mus_isPhoton_->GetEntry(entry_);
    c_mus_isPhoton_ = true;
  }
  return mus_isPhoton_;
}

std::vector<float>* const & cfa_base::mus_isStandAloneMuon() const{
  if(!c_mus_isStandAloneMuon_ && b_mus_isStandAloneMuon_){
    b_mus_isStandAloneMuon_->SetStatus(true);
    chainB_.SetBranchAddress("mus_isStandAloneMuon", &mus_isStandAloneMuon_, &b_mus_isStandAloneMuon_);
    b_mus_isStandAloneMuon_->GetEntry(entry_);
    c_mus_isStandAloneMuon_ = true;
  }
  return mus_isStandAloneMuon_;
}

std::vector<float>* const & cfa_base::mus_isTrackerMuon() const{
  if(!c_mus_isTrackerMuon_ && b_mus_isTrackerMuon_){
    b_mus_isTrackerMuon_->SetStatus(true);
    chainB_.SetBranchAddress("mus_isTrackerMuon", &mus_isTrackerMuon_, &b_mus_isTrackerMuon_);
    b_mus_isTrackerMuon_->GetEntry(entry_);
    c_mus_isTrackerMuon_ = true;
  }
  return mus_isTrackerMuon_;
}

std::vector<float>* const & cfa_base::mus_iso03_emEt() const{
  if(!c_mus_iso03_emEt_ && b_mus_iso03_emEt_){
    b_mus_iso03_emEt_->SetStatus(true);
    chainB_.SetBranchAddress("mus_iso03_emEt", &mus_iso03_emEt_, &b_mus_iso03_emEt_);
    b_mus_iso03_emEt_->GetEntry(entry_);
    c_mus_iso03_emEt_ = true;
  }
  return mus_iso03_emEt_;
}

std::vector<float>* const & cfa_base::mus_iso03_emVetoEt() const{
  if(!c_mus_iso03_emVetoEt_ && b_mus_iso03_emVetoEt_){
    b_mus_iso03_emVetoEt_->SetStatus(true);
    chainB_.SetBranchAddress("mus_iso03_emVetoEt", &mus_iso03_emVetoEt_, &b_mus_iso03_emVetoEt_);
    b_mus_iso03_emVetoEt_->GetEntry(entry_);
    c_mus_iso03_emVetoEt_ = true;
  }
  return mus_iso03_emVetoEt_;
}

std::vector<float>* const & cfa_base::mus_iso03_hadEt() const{
  if(!c_mus_iso03_hadEt_ && b_mus_iso03_hadEt_){
    b_mus_iso03_hadEt_->SetStatus(true);
    chainB_.SetBranchAddress("mus_iso03_hadEt", &mus_iso03_hadEt_, &b_mus_iso03_hadEt_);
    b_mus_iso03_hadEt_->GetEntry(entry_);
    c_mus_iso03_hadEt_ = true;
  }
  return mus_iso03_hadEt_;
}

std::vector<float>* const & cfa_base::mus_iso03_hadVetoEt() const{
  if(!c_mus_iso03_hadVetoEt_ && b_mus_iso03_hadVetoEt_){
    b_mus_iso03_hadVetoEt_->SetStatus(true);
    chainB_.SetBranchAddress("mus_iso03_hadVetoEt", &mus_iso03_hadVetoEt_, &b_mus_iso03_hadVetoEt_);
    b_mus_iso03_hadVetoEt_->GetEntry(entry_);
    c_mus_iso03_hadVetoEt_ = true;
  }
  return mus_iso03_hadVetoEt_;
}

std::vector<float>* const & cfa_base::mus_iso03_hoEt() const{
  if(!c_mus_iso03_hoEt_ && b_mus_iso03_hoEt_){
    b_mus_iso03_hoEt_->SetStatus(true);
    chainB_.SetBranchAddress("mus_iso03_hoEt", &mus_iso03_hoEt_, &b_mus_iso03_hoEt_);
    b_mus_iso03_hoEt_->GetEntry(entry_);
    c_mus_iso03_hoEt_ = true;
  }
  return mus_iso03_hoEt_;
}

std::vector<float>* const & cfa_base::mus_iso03_nTracks() const{
  if(!c_mus_iso03_nTracks_ && b_mus_iso03_nTracks_){
    b_mus_iso03_nTracks_->SetStatus(true);
    chainB_.SetBranchAddress("mus_iso03_nTracks", &mus_iso03_nTracks_, &b_mus_iso03_nTracks_);
    b_mus_iso03_nTracks_->GetEntry(entry_);
    c_mus_iso03_nTracks_ = true;
  }
  return mus_iso03_nTracks_;
}

std::vector<float>* const & cfa_base::mus_iso03_sumPt() const{
  if(!c_mus_iso03_sumPt_ && b_mus_iso03_sumPt_){
    b_mus_iso03_sumPt_->SetStatus(true);
    chainB_.SetBranchAddress("mus_iso03_sumPt", &mus_iso03_sumPt_, &b_mus_iso03_sumPt_);
    b_mus_iso03_sumPt_->GetEntry(entry_);
    c_mus_iso03_sumPt_ = true;
  }
  return mus_iso03_sumPt_;
}

std::vector<float>* const & cfa_base::mus_iso05_emEt() const{
  if(!c_mus_iso05_emEt_ && b_mus_iso05_emEt_){
    b_mus_iso05_emEt_->SetStatus(true);
    chainB_.SetBranchAddress("mus_iso05_emEt", &mus_iso05_emEt_, &b_mus_iso05_emEt_);
    b_mus_iso05_emEt_->GetEntry(entry_);
    c_mus_iso05_emEt_ = true;
  }
  return mus_iso05_emEt_;
}

std::vector<float>* const & cfa_base::mus_iso05_hadEt() const{
  if(!c_mus_iso05_hadEt_ && b_mus_iso05_hadEt_){
    b_mus_iso05_hadEt_->SetStatus(true);
    chainB_.SetBranchAddress("mus_iso05_hadEt", &mus_iso05_hadEt_, &b_mus_iso05_hadEt_);
    b_mus_iso05_hadEt_->GetEntry(entry_);
    c_mus_iso05_hadEt_ = true;
  }
  return mus_iso05_hadEt_;
}

std::vector<float>* const & cfa_base::mus_iso05_hoEt() const{
  if(!c_mus_iso05_hoEt_ && b_mus_iso05_hoEt_){
    b_mus_iso05_hoEt_->SetStatus(true);
    chainB_.SetBranchAddress("mus_iso05_hoEt", &mus_iso05_hoEt_, &b_mus_iso05_hoEt_);
    b_mus_iso05_hoEt_->GetEntry(entry_);
    c_mus_iso05_hoEt_ = true;
  }
  return mus_iso05_hoEt_;
}

std::vector<float>* const & cfa_base::mus_iso05_nTracks() const{
  if(!c_mus_iso05_nTracks_ && b_mus_iso05_nTracks_){
    b_mus_iso05_nTracks_->SetStatus(true);
    chainB_.SetBranchAddress("mus_iso05_nTracks", &mus_iso05_nTracks_, &b_mus_iso05_nTracks_);
    b_mus_iso05_nTracks_->GetEntry(entry_);
    c_mus_iso05_nTracks_ = true;
  }
  return mus_iso05_nTracks_;
}

std::vector<float>* const & cfa_base::mus_iso05_sumPt() const{
  if(!c_mus_iso05_sumPt_ && b_mus_iso05_sumPt_){
    b_mus_iso05_sumPt_->SetStatus(true);
    chainB_.SetBranchAddress("mus_iso05_sumPt", &mus_iso05_sumPt_, &b_mus_iso05_sumPt_);
    b_mus_iso05_sumPt_->GetEntry(entry_);
    c_mus_iso05_sumPt_ = true;
  }
  return mus_iso05_sumPt_;
}

std::vector<float>* const & cfa_base::mus_num_matches() const{
  if(!c_mus_num_matches_ && b_mus_num_matches_){
    b_mus_num_matches_->SetStatus(true);
    chainB_.SetBranchAddress("mus_num_matches", &mus_num_matches_, &b_mus_num_matches_);
    b_mus_num_matches_->GetEntry(entry_);
    c_mus_num_matches_ = true;
  }
  return mus_num_matches_;
}

std::vector<float>* const & cfa_base::mus_numberOfMatchedStations() const{
  if(!c_mus_numberOfMatchedStations_ && b_mus_numberOfMatchedStations_){
    b_mus_numberOfMatchedStations_->SetStatus(true);
    chainB_.SetBranchAddress("mus_numberOfMatchedStations", &mus_numberOfMatchedStations_, &b_mus_numberOfMatchedStations_);
    b_mus_numberOfMatchedStations_->GetEntry(entry_);
    c_mus_numberOfMatchedStations_ = true;
  }
  return mus_numberOfMatchedStations_;
}

std::vector<float>* const & cfa_base::mus_pfIsolationR03_sumChargedHadronPt() const{
  if(!c_mus_pfIsolationR03_sumChargedHadronPt_ && b_mus_pfIsolationR03_sumChargedHadronPt_){
    b_mus_pfIsolationR03_sumChargedHadronPt_->SetStatus(true);
    chainB_.SetBranchAddress("mus_pfIsolationR03_sumChargedHadronPt", &mus_pfIsolationR03_sumChargedHadronPt_, &b_mus_pfIsolationR03_sumChargedHadronPt_);
    b_mus_pfIsolationR03_sumChargedHadronPt_->GetEntry(entry_);
    c_mus_pfIsolationR03_sumChargedHadronPt_ = true;
  }
  return mus_pfIsolationR03_sumChargedHadronPt_;
}

std::vector<float>* const & cfa_base::mus_pfIsolationR03_sumChargedParticlePt() const{
  if(!c_mus_pfIsolationR03_sumChargedParticlePt_ && b_mus_pfIsolationR03_sumChargedParticlePt_){
    b_mus_pfIsolationR03_sumChargedParticlePt_->SetStatus(true);
    chainB_.SetBranchAddress("mus_pfIsolationR03_sumChargedParticlePt", &mus_pfIsolationR03_sumChargedParticlePt_, &b_mus_pfIsolationR03_sumChargedParticlePt_);
    b_mus_pfIsolationR03_sumChargedParticlePt_->GetEntry(entry_);
    c_mus_pfIsolationR03_sumChargedParticlePt_ = true;
  }
  return mus_pfIsolationR03_sumChargedParticlePt_;
}

std::vector<float>* const & cfa_base::mus_pfIsolationR03_sumNeutralHadronEt() const{
  if(!c_mus_pfIsolationR03_sumNeutralHadronEt_ && b_mus_pfIsolationR03_sumNeutralHadronEt_){
    b_mus_pfIsolationR03_sumNeutralHadronEt_->SetStatus(true);
    chainB_.SetBranchAddress("mus_pfIsolationR03_sumNeutralHadronEt", &mus_pfIsolationR03_sumNeutralHadronEt_, &b_mus_pfIsolationR03_sumNeutralHadronEt_);
    b_mus_pfIsolationR03_sumNeutralHadronEt_->GetEntry(entry_);
    c_mus_pfIsolationR03_sumNeutralHadronEt_ = true;
  }
  return mus_pfIsolationR03_sumNeutralHadronEt_;
}

std::vector<float>* const & cfa_base::mus_pfIsolationR03_sumNeutralHadronEtHighThreshold() const{
  if(!c_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_ && b_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_){
    b_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_->SetStatus(true);
    chainB_.SetBranchAddress("mus_pfIsolationR03_sumNeutralHadronEtHighThreshold", &mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_, &b_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_);
    b_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_->GetEntry(entry_);
    c_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_ = true;
  }
  return mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_;
}

std::vector<float>* const & cfa_base::mus_pfIsolationR03_sumPUPt() const{
  if(!c_mus_pfIsolationR03_sumPUPt_ && b_mus_pfIsolationR03_sumPUPt_){
    b_mus_pfIsolationR03_sumPUPt_->SetStatus(true);
    chainB_.SetBranchAddress("mus_pfIsolationR03_sumPUPt", &mus_pfIsolationR03_sumPUPt_, &b_mus_pfIsolationR03_sumPUPt_);
    b_mus_pfIsolationR03_sumPUPt_->GetEntry(entry_);
    c_mus_pfIsolationR03_sumPUPt_ = true;
  }
  return mus_pfIsolationR03_sumPUPt_;
}

std::vector<float>* const & cfa_base::mus_pfIsolationR03_sumPhotonEt() const{
  if(!c_mus_pfIsolationR03_sumPhotonEt_ && b_mus_pfIsolationR03_sumPhotonEt_){
    b_mus_pfIsolationR03_sumPhotonEt_->SetStatus(true);
    chainB_.SetBranchAddress("mus_pfIsolationR03_sumPhotonEt", &mus_pfIsolationR03_sumPhotonEt_, &b_mus_pfIsolationR03_sumPhotonEt_);
    b_mus_pfIsolationR03_sumPhotonEt_->GetEntry(entry_);
    c_mus_pfIsolationR03_sumPhotonEt_ = true;
  }
  return mus_pfIsolationR03_sumPhotonEt_;
}

std::vector<float>* const & cfa_base::mus_pfIsolationR03_sumPhotonEtHighThreshold() const{
  if(!c_mus_pfIsolationR03_sumPhotonEtHighThreshold_ && b_mus_pfIsolationR03_sumPhotonEtHighThreshold_){
    b_mus_pfIsolationR03_sumPhotonEtHighThreshold_->SetStatus(true);
    chainB_.SetBranchAddress("mus_pfIsolationR03_sumPhotonEtHighThreshold", &mus_pfIsolationR03_sumPhotonEtHighThreshold_, &b_mus_pfIsolationR03_sumPhotonEtHighThreshold_);
    b_mus_pfIsolationR03_sumPhotonEtHighThreshold_->GetEntry(entry_);
    c_mus_pfIsolationR03_sumPhotonEtHighThreshold_ = true;
  }
  return mus_pfIsolationR03_sumPhotonEtHighThreshold_;
}

std::vector<float>* const & cfa_base::mus_pfIsolationR04_sumChargedHadronPt() const{
  if(!c_mus_pfIsolationR04_sumChargedHadronPt_ && b_mus_pfIsolationR04_sumChargedHadronPt_){
    b_mus_pfIsolationR04_sumChargedHadronPt_->SetStatus(true);
    chainB_.SetBranchAddress("mus_pfIsolationR04_sumChargedHadronPt", &mus_pfIsolationR04_sumChargedHadronPt_, &b_mus_pfIsolationR04_sumChargedHadronPt_);
    b_mus_pfIsolationR04_sumChargedHadronPt_->GetEntry(entry_);
    c_mus_pfIsolationR04_sumChargedHadronPt_ = true;
  }
  return mus_pfIsolationR04_sumChargedHadronPt_;
}

std::vector<float>* const & cfa_base::mus_pfIsolationR04_sumChargedParticlePt() const{
  if(!c_mus_pfIsolationR04_sumChargedParticlePt_ && b_mus_pfIsolationR04_sumChargedParticlePt_){
    b_mus_pfIsolationR04_sumChargedParticlePt_->SetStatus(true);
    chainB_.SetBranchAddress("mus_pfIsolationR04_sumChargedParticlePt", &mus_pfIsolationR04_sumChargedParticlePt_, &b_mus_pfIsolationR04_sumChargedParticlePt_);
    b_mus_pfIsolationR04_sumChargedParticlePt_->GetEntry(entry_);
    c_mus_pfIsolationR04_sumChargedParticlePt_ = true;
  }
  return mus_pfIsolationR04_sumChargedParticlePt_;
}

std::vector<float>* const & cfa_base::mus_pfIsolationR04_sumNeutralHadronEt() const{
  if(!c_mus_pfIsolationR04_sumNeutralHadronEt_ && b_mus_pfIsolationR04_sumNeutralHadronEt_){
    b_mus_pfIsolationR04_sumNeutralHadronEt_->SetStatus(true);
    chainB_.SetBranchAddress("mus_pfIsolationR04_sumNeutralHadronEt", &mus_pfIsolationR04_sumNeutralHadronEt_, &b_mus_pfIsolationR04_sumNeutralHadronEt_);
    b_mus_pfIsolationR04_sumNeutralHadronEt_->GetEntry(entry_);
    c_mus_pfIsolationR04_sumNeutralHadronEt_ = true;
  }
  return mus_pfIsolationR04_sumNeutralHadronEt_;
}

std::vector<float>* const & cfa_base::mus_pfIsolationR04_sumNeutralHadronEtHighThreshold() const{
  if(!c_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_ && b_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_){
    b_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_->SetStatus(true);
    chainB_.SetBranchAddress("mus_pfIsolationR04_sumNeutralHadronEtHighThreshold", &mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_, &b_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_);
    b_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_->GetEntry(entry_);
    c_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_ = true;
  }
  return mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_;
}

std::vector<float>* const & cfa_base::mus_pfIsolationR04_sumPUPt() const{
  if(!c_mus_pfIsolationR04_sumPUPt_ && b_mus_pfIsolationR04_sumPUPt_){
    b_mus_pfIsolationR04_sumPUPt_->SetStatus(true);
    chainB_.SetBranchAddress("mus_pfIsolationR04_sumPUPt", &mus_pfIsolationR04_sumPUPt_, &b_mus_pfIsolationR04_sumPUPt_);
    b_mus_pfIsolationR04_sumPUPt_->GetEntry(entry_);
    c_mus_pfIsolationR04_sumPUPt_ = true;
  }
  return mus_pfIsolationR04_sumPUPt_;
}

std::vector<float>* const & cfa_base::mus_pfIsolationR04_sumPhotonEt() const{
  if(!c_mus_pfIsolationR04_sumPhotonEt_ && b_mus_pfIsolationR04_sumPhotonEt_){
    b_mus_pfIsolationR04_sumPhotonEt_->SetStatus(true);
    chainB_.SetBranchAddress("mus_pfIsolationR04_sumPhotonEt", &mus_pfIsolationR04_sumPhotonEt_, &b_mus_pfIsolationR04_sumPhotonEt_);
    b_mus_pfIsolationR04_sumPhotonEt_->GetEntry(entry_);
    c_mus_pfIsolationR04_sumPhotonEt_ = true;
  }
  return mus_pfIsolationR04_sumPhotonEt_;
}

std::vector<float>* const & cfa_base::mus_pfIsolationR04_sumPhotonEtHighThreshold() const{
  if(!c_mus_pfIsolationR04_sumPhotonEtHighThreshold_ && b_mus_pfIsolationR04_sumPhotonEtHighThreshold_){
    b_mus_pfIsolationR04_sumPhotonEtHighThreshold_->SetStatus(true);
    chainB_.SetBranchAddress("mus_pfIsolationR04_sumPhotonEtHighThreshold", &mus_pfIsolationR04_sumPhotonEtHighThreshold_, &b_mus_pfIsolationR04_sumPhotonEtHighThreshold_);
    b_mus_pfIsolationR04_sumPhotonEtHighThreshold_->GetEntry(entry_);
    c_mus_pfIsolationR04_sumPhotonEtHighThreshold_ = true;
  }
  return mus_pfIsolationR04_sumPhotonEtHighThreshold_;
}

std::vector<float>* const & cfa_base::mus_phi() const{
  if(!c_mus_phi_ && b_mus_phi_){
    b_mus_phi_->SetStatus(true);
    chainB_.SetBranchAddress("mus_phi", &mus_phi_, &b_mus_phi_);
    b_mus_phi_->GetEntry(entry_);
    c_mus_phi_ = true;
  }
  return mus_phi_;
}

std::vector<float>* const & cfa_base::mus_picky_ExpectedHitsInner() const{
  if(!c_mus_picky_ExpectedHitsInner_ && b_mus_picky_ExpectedHitsInner_){
    b_mus_picky_ExpectedHitsInner_->SetStatus(true);
    chainB_.SetBranchAddress("mus_picky_ExpectedHitsInner", &mus_picky_ExpectedHitsInner_, &b_mus_picky_ExpectedHitsInner_);
    b_mus_picky_ExpectedHitsInner_->GetEntry(entry_);
    c_mus_picky_ExpectedHitsInner_ = true;
  }
  return mus_picky_ExpectedHitsInner_;
}

std::vector<float>* const & cfa_base::mus_picky_ExpectedHitsOuter() const{
  if(!c_mus_picky_ExpectedHitsOuter_ && b_mus_picky_ExpectedHitsOuter_){
    b_mus_picky_ExpectedHitsOuter_->SetStatus(true);
    chainB_.SetBranchAddress("mus_picky_ExpectedHitsOuter", &mus_picky_ExpectedHitsOuter_, &b_mus_picky_ExpectedHitsOuter_);
    b_mus_picky_ExpectedHitsOuter_->GetEntry(entry_);
    c_mus_picky_ExpectedHitsOuter_ = true;
  }
  return mus_picky_ExpectedHitsOuter_;
}

std::vector<float>* const & cfa_base::mus_picky_LayersWithMeasurement() const{
  if(!c_mus_picky_LayersWithMeasurement_ && b_mus_picky_LayersWithMeasurement_){
    b_mus_picky_LayersWithMeasurement_->SetStatus(true);
    chainB_.SetBranchAddress("mus_picky_LayersWithMeasurement", &mus_picky_LayersWithMeasurement_, &b_mus_picky_LayersWithMeasurement_);
    b_mus_picky_LayersWithMeasurement_->GetEntry(entry_);
    c_mus_picky_LayersWithMeasurement_ = true;
  }
  return mus_picky_LayersWithMeasurement_;
}

std::vector<float>* const & cfa_base::mus_picky_LayersWithoutMeasurement() const{
  if(!c_mus_picky_LayersWithoutMeasurement_ && b_mus_picky_LayersWithoutMeasurement_){
    b_mus_picky_LayersWithoutMeasurement_->SetStatus(true);
    chainB_.SetBranchAddress("mus_picky_LayersWithoutMeasurement", &mus_picky_LayersWithoutMeasurement_, &b_mus_picky_LayersWithoutMeasurement_);
    b_mus_picky_LayersWithoutMeasurement_->GetEntry(entry_);
    c_mus_picky_LayersWithoutMeasurement_ = true;
  }
  return mus_picky_LayersWithoutMeasurement_;
}

std::vector<float>* const & cfa_base::mus_picky_PixelLayersWithMeasurement() const{
  if(!c_mus_picky_PixelLayersWithMeasurement_ && b_mus_picky_PixelLayersWithMeasurement_){
    b_mus_picky_PixelLayersWithMeasurement_->SetStatus(true);
    chainB_.SetBranchAddress("mus_picky_PixelLayersWithMeasurement", &mus_picky_PixelLayersWithMeasurement_, &b_mus_picky_PixelLayersWithMeasurement_);
    b_mus_picky_PixelLayersWithMeasurement_->GetEntry(entry_);
    c_mus_picky_PixelLayersWithMeasurement_ = true;
  }
  return mus_picky_PixelLayersWithMeasurement_;
}

std::vector<float>* const & cfa_base::mus_picky_ValidStripLayersWithMonoAndStereoHit() const{
  if(!c_mus_picky_ValidStripLayersWithMonoAndStereoHit_ && b_mus_picky_ValidStripLayersWithMonoAndStereoHit_){
    b_mus_picky_ValidStripLayersWithMonoAndStereoHit_->SetStatus(true);
    chainB_.SetBranchAddress("mus_picky_ValidStripLayersWithMonoAndStereoHit", &mus_picky_ValidStripLayersWithMonoAndStereoHit_, &b_mus_picky_ValidStripLayersWithMonoAndStereoHit_);
    b_mus_picky_ValidStripLayersWithMonoAndStereoHit_->GetEntry(entry_);
    c_mus_picky_ValidStripLayersWithMonoAndStereoHit_ = true;
  }
  return mus_picky_ValidStripLayersWithMonoAndStereoHit_;
}

std::vector<float>* const & cfa_base::mus_picky_chg() const{
  if(!c_mus_picky_chg_ && b_mus_picky_chg_){
    b_mus_picky_chg_->SetStatus(true);
    chainB_.SetBranchAddress("mus_picky_chg", &mus_picky_chg_, &b_mus_picky_chg_);
    b_mus_picky_chg_->GetEntry(entry_);
    c_mus_picky_chg_ = true;
  }
  return mus_picky_chg_;
}

std::vector<float>* const & cfa_base::mus_picky_chi2() const{
  if(!c_mus_picky_chi2_ && b_mus_picky_chi2_){
    b_mus_picky_chi2_->SetStatus(true);
    chainB_.SetBranchAddress("mus_picky_chi2", &mus_picky_chi2_, &b_mus_picky_chi2_);
    b_mus_picky_chi2_->GetEntry(entry_);
    c_mus_picky_chi2_ = true;
  }
  return mus_picky_chi2_;
}

std::vector<float>* const & cfa_base::mus_picky_d0dum() const{
  if(!c_mus_picky_d0dum_ && b_mus_picky_d0dum_){
    b_mus_picky_d0dum_->SetStatus(true);
    chainB_.SetBranchAddress("mus_picky_d0dum", &mus_picky_d0dum_, &b_mus_picky_d0dum_);
    b_mus_picky_d0dum_->GetEntry(entry_);
    c_mus_picky_d0dum_ = true;
  }
  return mus_picky_d0dum_;
}

std::vector<float>* const & cfa_base::mus_picky_d0dumErr() const{
  if(!c_mus_picky_d0dumErr_ && b_mus_picky_d0dumErr_){
    b_mus_picky_d0dumErr_->SetStatus(true);
    chainB_.SetBranchAddress("mus_picky_d0dumErr", &mus_picky_d0dumErr_, &b_mus_picky_d0dumErr_);
    b_mus_picky_d0dumErr_->GetEntry(entry_);
    c_mus_picky_d0dumErr_ = true;
  }
  return mus_picky_d0dumErr_;
}

std::vector<float>* const & cfa_base::mus_picky_dz() const{
  if(!c_mus_picky_dz_ && b_mus_picky_dz_){
    b_mus_picky_dz_->SetStatus(true);
    chainB_.SetBranchAddress("mus_picky_dz", &mus_picky_dz_, &b_mus_picky_dz_);
    b_mus_picky_dz_->GetEntry(entry_);
    c_mus_picky_dz_ = true;
  }
  return mus_picky_dz_;
}

std::vector<float>* const & cfa_base::mus_picky_dzErr() const{
  if(!c_mus_picky_dzErr_ && b_mus_picky_dzErr_){
    b_mus_picky_dzErr_->SetStatus(true);
    chainB_.SetBranchAddress("mus_picky_dzErr", &mus_picky_dzErr_, &b_mus_picky_dzErr_);
    b_mus_picky_dzErr_->GetEntry(entry_);
    c_mus_picky_dzErr_ = true;
  }
  return mus_picky_dzErr_;
}

std::vector<float>* const & cfa_base::mus_picky_eta() const{
  if(!c_mus_picky_eta_ && b_mus_picky_eta_){
    b_mus_picky_eta_->SetStatus(true);
    chainB_.SetBranchAddress("mus_picky_eta", &mus_picky_eta_, &b_mus_picky_eta_);
    b_mus_picky_eta_->GetEntry(entry_);
    c_mus_picky_eta_ = true;
  }
  return mus_picky_eta_;
}

std::vector<float>* const & cfa_base::mus_picky_etaErr() const{
  if(!c_mus_picky_etaErr_ && b_mus_picky_etaErr_){
    b_mus_picky_etaErr_->SetStatus(true);
    chainB_.SetBranchAddress("mus_picky_etaErr", &mus_picky_etaErr_, &b_mus_picky_etaErr_);
    b_mus_picky_etaErr_->GetEntry(entry_);
    c_mus_picky_etaErr_ = true;
  }
  return mus_picky_etaErr_;
}

std::vector<float>* const & cfa_base::mus_picky_id() const{
  if(!c_mus_picky_id_ && b_mus_picky_id_){
    b_mus_picky_id_->SetStatus(true);
    chainB_.SetBranchAddress("mus_picky_id", &mus_picky_id_, &b_mus_picky_id_);
    b_mus_picky_id_->GetEntry(entry_);
    c_mus_picky_id_ = true;
  }
  return mus_picky_id_;
}

std::vector<float>* const & cfa_base::mus_picky_ndof() const{
  if(!c_mus_picky_ndof_ && b_mus_picky_ndof_){
    b_mus_picky_ndof_->SetStatus(true);
    chainB_.SetBranchAddress("mus_picky_ndof", &mus_picky_ndof_, &b_mus_picky_ndof_);
    b_mus_picky_ndof_->GetEntry(entry_);
    c_mus_picky_ndof_ = true;
  }
  return mus_picky_ndof_;
}

std::vector<float>* const & cfa_base::mus_picky_numlosthits() const{
  if(!c_mus_picky_numlosthits_ && b_mus_picky_numlosthits_){
    b_mus_picky_numlosthits_->SetStatus(true);
    chainB_.SetBranchAddress("mus_picky_numlosthits", &mus_picky_numlosthits_, &b_mus_picky_numlosthits_);
    b_mus_picky_numlosthits_->GetEntry(entry_);
    c_mus_picky_numlosthits_ = true;
  }
  return mus_picky_numlosthits_;
}

std::vector<float>* const & cfa_base::mus_picky_numvalPixelhits() const{
  if(!c_mus_picky_numvalPixelhits_ && b_mus_picky_numvalPixelhits_){
    b_mus_picky_numvalPixelhits_->SetStatus(true);
    chainB_.SetBranchAddress("mus_picky_numvalPixelhits", &mus_picky_numvalPixelhits_, &b_mus_picky_numvalPixelhits_);
    b_mus_picky_numvalPixelhits_->GetEntry(entry_);
    c_mus_picky_numvalPixelhits_ = true;
  }
  return mus_picky_numvalPixelhits_;
}

std::vector<float>* const & cfa_base::mus_picky_numvalhits() const{
  if(!c_mus_picky_numvalhits_ && b_mus_picky_numvalhits_){
    b_mus_picky_numvalhits_->SetStatus(true);
    chainB_.SetBranchAddress("mus_picky_numvalhits", &mus_picky_numvalhits_, &b_mus_picky_numvalhits_);
    b_mus_picky_numvalhits_->GetEntry(entry_);
    c_mus_picky_numvalhits_ = true;
  }
  return mus_picky_numvalhits_;
}

std::vector<float>* const & cfa_base::mus_picky_phi() const{
  if(!c_mus_picky_phi_ && b_mus_picky_phi_){
    b_mus_picky_phi_->SetStatus(true);
    chainB_.SetBranchAddress("mus_picky_phi", &mus_picky_phi_, &b_mus_picky_phi_);
    b_mus_picky_phi_->GetEntry(entry_);
    c_mus_picky_phi_ = true;
  }
  return mus_picky_phi_;
}

std::vector<float>* const & cfa_base::mus_picky_phiErr() const{
  if(!c_mus_picky_phiErr_ && b_mus_picky_phiErr_){
    b_mus_picky_phiErr_->SetStatus(true);
    chainB_.SetBranchAddress("mus_picky_phiErr", &mus_picky_phiErr_, &b_mus_picky_phiErr_);
    b_mus_picky_phiErr_->GetEntry(entry_);
    c_mus_picky_phiErr_ = true;
  }
  return mus_picky_phiErr_;
}

std::vector<float>* const & cfa_base::mus_picky_pt() const{
  if(!c_mus_picky_pt_ && b_mus_picky_pt_){
    b_mus_picky_pt_->SetStatus(true);
    chainB_.SetBranchAddress("mus_picky_pt", &mus_picky_pt_, &b_mus_picky_pt_);
    b_mus_picky_pt_->GetEntry(entry_);
    c_mus_picky_pt_ = true;
  }
  return mus_picky_pt_;
}

std::vector<float>* const & cfa_base::mus_picky_ptErr() const{
  if(!c_mus_picky_ptErr_ && b_mus_picky_ptErr_){
    b_mus_picky_ptErr_->SetStatus(true);
    chainB_.SetBranchAddress("mus_picky_ptErr", &mus_picky_ptErr_, &b_mus_picky_ptErr_);
    b_mus_picky_ptErr_->GetEntry(entry_);
    c_mus_picky_ptErr_ = true;
  }
  return mus_picky_ptErr_;
}

std::vector<float>* const & cfa_base::mus_picky_px() const{
  if(!c_mus_picky_px_ && b_mus_picky_px_){
    b_mus_picky_px_->SetStatus(true);
    chainB_.SetBranchAddress("mus_picky_px", &mus_picky_px_, &b_mus_picky_px_);
    b_mus_picky_px_->GetEntry(entry_);
    c_mus_picky_px_ = true;
  }
  return mus_picky_px_;
}

std::vector<float>* const & cfa_base::mus_picky_py() const{
  if(!c_mus_picky_py_ && b_mus_picky_py_){
    b_mus_picky_py_->SetStatus(true);
    chainB_.SetBranchAddress("mus_picky_py", &mus_picky_py_, &b_mus_picky_py_);
    b_mus_picky_py_->GetEntry(entry_);
    c_mus_picky_py_ = true;
  }
  return mus_picky_py_;
}

std::vector<float>* const & cfa_base::mus_picky_pz() const{
  if(!c_mus_picky_pz_ && b_mus_picky_pz_){
    b_mus_picky_pz_->SetStatus(true);
    chainB_.SetBranchAddress("mus_picky_pz", &mus_picky_pz_, &b_mus_picky_pz_);
    b_mus_picky_pz_->GetEntry(entry_);
    c_mus_picky_pz_ = true;
  }
  return mus_picky_pz_;
}

std::vector<float>* const & cfa_base::mus_picky_theta() const{
  if(!c_mus_picky_theta_ && b_mus_picky_theta_){
    b_mus_picky_theta_->SetStatus(true);
    chainB_.SetBranchAddress("mus_picky_theta", &mus_picky_theta_, &b_mus_picky_theta_);
    b_mus_picky_theta_->GetEntry(entry_);
    c_mus_picky_theta_ = true;
  }
  return mus_picky_theta_;
}

std::vector<float>* const & cfa_base::mus_picky_vx() const{
  if(!c_mus_picky_vx_ && b_mus_picky_vx_){
    b_mus_picky_vx_->SetStatus(true);
    chainB_.SetBranchAddress("mus_picky_vx", &mus_picky_vx_, &b_mus_picky_vx_);
    b_mus_picky_vx_->GetEntry(entry_);
    c_mus_picky_vx_ = true;
  }
  return mus_picky_vx_;
}

std::vector<float>* const & cfa_base::mus_picky_vy() const{
  if(!c_mus_picky_vy_ && b_mus_picky_vy_){
    b_mus_picky_vy_->SetStatus(true);
    chainB_.SetBranchAddress("mus_picky_vy", &mus_picky_vy_, &b_mus_picky_vy_);
    b_mus_picky_vy_->GetEntry(entry_);
    c_mus_picky_vy_ = true;
  }
  return mus_picky_vy_;
}

std::vector<float>* const & cfa_base::mus_picky_vz() const{
  if(!c_mus_picky_vz_ && b_mus_picky_vz_){
    b_mus_picky_vz_->SetStatus(true);
    chainB_.SetBranchAddress("mus_picky_vz", &mus_picky_vz_, &b_mus_picky_vz_);
    b_mus_picky_vz_->GetEntry(entry_);
    c_mus_picky_vz_ = true;
  }
  return mus_picky_vz_;
}

std::vector<float>* const & cfa_base::mus_pt() const{
  if(!c_mus_pt_ && b_mus_pt_){
    b_mus_pt_->SetStatus(true);
    chainB_.SetBranchAddress("mus_pt", &mus_pt_, &b_mus_pt_);
    b_mus_pt_->GetEntry(entry_);
    c_mus_pt_ = true;
  }
  return mus_pt_;
}

std::vector<float>* const & cfa_base::mus_px() const{
  if(!c_mus_px_ && b_mus_px_){
    b_mus_px_->SetStatus(true);
    chainB_.SetBranchAddress("mus_px", &mus_px_, &b_mus_px_);
    b_mus_px_->GetEntry(entry_);
    c_mus_px_ = true;
  }
  return mus_px_;
}

std::vector<float>* const & cfa_base::mus_py() const{
  if(!c_mus_py_ && b_mus_py_){
    b_mus_py_->SetStatus(true);
    chainB_.SetBranchAddress("mus_py", &mus_py_, &b_mus_py_);
    b_mus_py_->GetEntry(entry_);
    c_mus_py_ = true;
  }
  return mus_py_;
}

std::vector<float>* const & cfa_base::mus_pz() const{
  if(!c_mus_pz_ && b_mus_pz_){
    b_mus_pz_->SetStatus(true);
    chainB_.SetBranchAddress("mus_pz", &mus_pz_, &b_mus_pz_);
    b_mus_pz_->GetEntry(entry_);
    c_mus_pz_ = true;
  }
  return mus_pz_;
}

std::vector<float>* const & cfa_base::mus_stamu_chg() const{
  if(!c_mus_stamu_chg_ && b_mus_stamu_chg_){
    b_mus_stamu_chg_->SetStatus(true);
    chainB_.SetBranchAddress("mus_stamu_chg", &mus_stamu_chg_, &b_mus_stamu_chg_);
    b_mus_stamu_chg_->GetEntry(entry_);
    c_mus_stamu_chg_ = true;
  }
  return mus_stamu_chg_;
}

std::vector<float>* const & cfa_base::mus_stamu_chi2() const{
  if(!c_mus_stamu_chi2_ && b_mus_stamu_chi2_){
    b_mus_stamu_chi2_->SetStatus(true);
    chainB_.SetBranchAddress("mus_stamu_chi2", &mus_stamu_chi2_, &b_mus_stamu_chi2_);
    b_mus_stamu_chi2_->GetEntry(entry_);
    c_mus_stamu_chi2_ = true;
  }
  return mus_stamu_chi2_;
}

std::vector<float>* const & cfa_base::mus_stamu_d0dum() const{
  if(!c_mus_stamu_d0dum_ && b_mus_stamu_d0dum_){
    b_mus_stamu_d0dum_->SetStatus(true);
    chainB_.SetBranchAddress("mus_stamu_d0dum", &mus_stamu_d0dum_, &b_mus_stamu_d0dum_);
    b_mus_stamu_d0dum_->GetEntry(entry_);
    c_mus_stamu_d0dum_ = true;
  }
  return mus_stamu_d0dum_;
}

std::vector<float>* const & cfa_base::mus_stamu_d0dumErr() const{
  if(!c_mus_stamu_d0dumErr_ && b_mus_stamu_d0dumErr_){
    b_mus_stamu_d0dumErr_->SetStatus(true);
    chainB_.SetBranchAddress("mus_stamu_d0dumErr", &mus_stamu_d0dumErr_, &b_mus_stamu_d0dumErr_);
    b_mus_stamu_d0dumErr_->GetEntry(entry_);
    c_mus_stamu_d0dumErr_ = true;
  }
  return mus_stamu_d0dumErr_;
}

std::vector<float>* const & cfa_base::mus_stamu_dz() const{
  if(!c_mus_stamu_dz_ && b_mus_stamu_dz_){
    b_mus_stamu_dz_->SetStatus(true);
    chainB_.SetBranchAddress("mus_stamu_dz", &mus_stamu_dz_, &b_mus_stamu_dz_);
    b_mus_stamu_dz_->GetEntry(entry_);
    c_mus_stamu_dz_ = true;
  }
  return mus_stamu_dz_;
}

std::vector<float>* const & cfa_base::mus_stamu_dzErr() const{
  if(!c_mus_stamu_dzErr_ && b_mus_stamu_dzErr_){
    b_mus_stamu_dzErr_->SetStatus(true);
    chainB_.SetBranchAddress("mus_stamu_dzErr", &mus_stamu_dzErr_, &b_mus_stamu_dzErr_);
    b_mus_stamu_dzErr_->GetEntry(entry_);
    c_mus_stamu_dzErr_ = true;
  }
  return mus_stamu_dzErr_;
}

std::vector<float>* const & cfa_base::mus_stamu_eta() const{
  if(!c_mus_stamu_eta_ && b_mus_stamu_eta_){
    b_mus_stamu_eta_->SetStatus(true);
    chainB_.SetBranchAddress("mus_stamu_eta", &mus_stamu_eta_, &b_mus_stamu_eta_);
    b_mus_stamu_eta_->GetEntry(entry_);
    c_mus_stamu_eta_ = true;
  }
  return mus_stamu_eta_;
}

std::vector<float>* const & cfa_base::mus_stamu_etaErr() const{
  if(!c_mus_stamu_etaErr_ && b_mus_stamu_etaErr_){
    b_mus_stamu_etaErr_->SetStatus(true);
    chainB_.SetBranchAddress("mus_stamu_etaErr", &mus_stamu_etaErr_, &b_mus_stamu_etaErr_);
    b_mus_stamu_etaErr_->GetEntry(entry_);
    c_mus_stamu_etaErr_ = true;
  }
  return mus_stamu_etaErr_;
}

std::vector<float>* const & cfa_base::mus_stamu_ndof() const{
  if(!c_mus_stamu_ndof_ && b_mus_stamu_ndof_){
    b_mus_stamu_ndof_->SetStatus(true);
    chainB_.SetBranchAddress("mus_stamu_ndof", &mus_stamu_ndof_, &b_mus_stamu_ndof_);
    b_mus_stamu_ndof_->GetEntry(entry_);
    c_mus_stamu_ndof_ = true;
  }
  return mus_stamu_ndof_;
}

std::vector<float>* const & cfa_base::mus_stamu_numlosthits() const{
  if(!c_mus_stamu_numlosthits_ && b_mus_stamu_numlosthits_){
    b_mus_stamu_numlosthits_->SetStatus(true);
    chainB_.SetBranchAddress("mus_stamu_numlosthits", &mus_stamu_numlosthits_, &b_mus_stamu_numlosthits_);
    b_mus_stamu_numlosthits_->GetEntry(entry_);
    c_mus_stamu_numlosthits_ = true;
  }
  return mus_stamu_numlosthits_;
}

std::vector<float>* const & cfa_base::mus_stamu_numvalhits() const{
  if(!c_mus_stamu_numvalhits_ && b_mus_stamu_numvalhits_){
    b_mus_stamu_numvalhits_->SetStatus(true);
    chainB_.SetBranchAddress("mus_stamu_numvalhits", &mus_stamu_numvalhits_, &b_mus_stamu_numvalhits_);
    b_mus_stamu_numvalhits_->GetEntry(entry_);
    c_mus_stamu_numvalhits_ = true;
  }
  return mus_stamu_numvalhits_;
}

std::vector<float>* const & cfa_base::mus_stamu_phi() const{
  if(!c_mus_stamu_phi_ && b_mus_stamu_phi_){
    b_mus_stamu_phi_->SetStatus(true);
    chainB_.SetBranchAddress("mus_stamu_phi", &mus_stamu_phi_, &b_mus_stamu_phi_);
    b_mus_stamu_phi_->GetEntry(entry_);
    c_mus_stamu_phi_ = true;
  }
  return mus_stamu_phi_;
}

std::vector<float>* const & cfa_base::mus_stamu_phiErr() const{
  if(!c_mus_stamu_phiErr_ && b_mus_stamu_phiErr_){
    b_mus_stamu_phiErr_->SetStatus(true);
    chainB_.SetBranchAddress("mus_stamu_phiErr", &mus_stamu_phiErr_, &b_mus_stamu_phiErr_);
    b_mus_stamu_phiErr_->GetEntry(entry_);
    c_mus_stamu_phiErr_ = true;
  }
  return mus_stamu_phiErr_;
}

std::vector<float>* const & cfa_base::mus_stamu_pt() const{
  if(!c_mus_stamu_pt_ && b_mus_stamu_pt_){
    b_mus_stamu_pt_->SetStatus(true);
    chainB_.SetBranchAddress("mus_stamu_pt", &mus_stamu_pt_, &b_mus_stamu_pt_);
    b_mus_stamu_pt_->GetEntry(entry_);
    c_mus_stamu_pt_ = true;
  }
  return mus_stamu_pt_;
}

std::vector<float>* const & cfa_base::mus_stamu_ptErr() const{
  if(!c_mus_stamu_ptErr_ && b_mus_stamu_ptErr_){
    b_mus_stamu_ptErr_->SetStatus(true);
    chainB_.SetBranchAddress("mus_stamu_ptErr", &mus_stamu_ptErr_, &b_mus_stamu_ptErr_);
    b_mus_stamu_ptErr_->GetEntry(entry_);
    c_mus_stamu_ptErr_ = true;
  }
  return mus_stamu_ptErr_;
}

std::vector<float>* const & cfa_base::mus_stamu_px() const{
  if(!c_mus_stamu_px_ && b_mus_stamu_px_){
    b_mus_stamu_px_->SetStatus(true);
    chainB_.SetBranchAddress("mus_stamu_px", &mus_stamu_px_, &b_mus_stamu_px_);
    b_mus_stamu_px_->GetEntry(entry_);
    c_mus_stamu_px_ = true;
  }
  return mus_stamu_px_;
}

std::vector<float>* const & cfa_base::mus_stamu_py() const{
  if(!c_mus_stamu_py_ && b_mus_stamu_py_){
    b_mus_stamu_py_->SetStatus(true);
    chainB_.SetBranchAddress("mus_stamu_py", &mus_stamu_py_, &b_mus_stamu_py_);
    b_mus_stamu_py_->GetEntry(entry_);
    c_mus_stamu_py_ = true;
  }
  return mus_stamu_py_;
}

std::vector<float>* const & cfa_base::mus_stamu_pz() const{
  if(!c_mus_stamu_pz_ && b_mus_stamu_pz_){
    b_mus_stamu_pz_->SetStatus(true);
    chainB_.SetBranchAddress("mus_stamu_pz", &mus_stamu_pz_, &b_mus_stamu_pz_);
    b_mus_stamu_pz_->GetEntry(entry_);
    c_mus_stamu_pz_ = true;
  }
  return mus_stamu_pz_;
}

std::vector<float>* const & cfa_base::mus_stamu_theta() const{
  if(!c_mus_stamu_theta_ && b_mus_stamu_theta_){
    b_mus_stamu_theta_->SetStatus(true);
    chainB_.SetBranchAddress("mus_stamu_theta", &mus_stamu_theta_, &b_mus_stamu_theta_);
    b_mus_stamu_theta_->GetEntry(entry_);
    c_mus_stamu_theta_ = true;
  }
  return mus_stamu_theta_;
}

std::vector<float>* const & cfa_base::mus_stamu_vx() const{
  if(!c_mus_stamu_vx_ && b_mus_stamu_vx_){
    b_mus_stamu_vx_->SetStatus(true);
    chainB_.SetBranchAddress("mus_stamu_vx", &mus_stamu_vx_, &b_mus_stamu_vx_);
    b_mus_stamu_vx_->GetEntry(entry_);
    c_mus_stamu_vx_ = true;
  }
  return mus_stamu_vx_;
}

std::vector<float>* const & cfa_base::mus_stamu_vy() const{
  if(!c_mus_stamu_vy_ && b_mus_stamu_vy_){
    b_mus_stamu_vy_->SetStatus(true);
    chainB_.SetBranchAddress("mus_stamu_vy", &mus_stamu_vy_, &b_mus_stamu_vy_);
    b_mus_stamu_vy_->GetEntry(entry_);
    c_mus_stamu_vy_ = true;
  }
  return mus_stamu_vy_;
}

std::vector<float>* const & cfa_base::mus_stamu_vz() const{
  if(!c_mus_stamu_vz_ && b_mus_stamu_vz_){
    b_mus_stamu_vz_->SetStatus(true);
    chainB_.SetBranchAddress("mus_stamu_vz", &mus_stamu_vz_, &b_mus_stamu_vz_);
    b_mus_stamu_vz_->GetEntry(entry_);
    c_mus_stamu_vz_ = true;
  }
  return mus_stamu_vz_;
}

std::vector<float>* const & cfa_base::mus_status() const{
  if(!c_mus_status_ && b_mus_status_){
    b_mus_status_->SetStatus(true);
    chainB_.SetBranchAddress("mus_status", &mus_status_, &b_mus_status_);
    b_mus_status_->GetEntry(entry_);
    c_mus_status_ = true;
  }
  return mus_status_;
}

std::vector<float>* const & cfa_base::mus_tIso() const{
  if(!c_mus_tIso_ && b_mus_tIso_){
    b_mus_tIso_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tIso", &mus_tIso_, &b_mus_tIso_);
    b_mus_tIso_->GetEntry(entry_);
    c_mus_tIso_ = true;
  }
  return mus_tIso_;
}

std::vector<float>* const & cfa_base::mus_theta() const{
  if(!c_mus_theta_ && b_mus_theta_){
    b_mus_theta_->SetStatus(true);
    chainB_.SetBranchAddress("mus_theta", &mus_theta_, &b_mus_theta_);
    b_mus_theta_->GetEntry(entry_);
    c_mus_theta_ = true;
  }
  return mus_theta_;
}

std::vector<float>* const & cfa_base::mus_tkHits() const{
  if(!c_mus_tkHits_ && b_mus_tkHits_){
    b_mus_tkHits_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tkHits", &mus_tkHits_, &b_mus_tkHits_);
    b_mus_tkHits_->GetEntry(entry_);
    c_mus_tkHits_ = true;
  }
  return mus_tkHits_;
}

std::vector<float>* const & cfa_base::mus_tk_ExpectedHitsInner() const{
  if(!c_mus_tk_ExpectedHitsInner_ && b_mus_tk_ExpectedHitsInner_){
    b_mus_tk_ExpectedHitsInner_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tk_ExpectedHitsInner", &mus_tk_ExpectedHitsInner_, &b_mus_tk_ExpectedHitsInner_);
    b_mus_tk_ExpectedHitsInner_->GetEntry(entry_);
    c_mus_tk_ExpectedHitsInner_ = true;
  }
  return mus_tk_ExpectedHitsInner_;
}

std::vector<float>* const & cfa_base::mus_tk_ExpectedHitsOuter() const{
  if(!c_mus_tk_ExpectedHitsOuter_ && b_mus_tk_ExpectedHitsOuter_){
    b_mus_tk_ExpectedHitsOuter_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tk_ExpectedHitsOuter", &mus_tk_ExpectedHitsOuter_, &b_mus_tk_ExpectedHitsOuter_);
    b_mus_tk_ExpectedHitsOuter_->GetEntry(entry_);
    c_mus_tk_ExpectedHitsOuter_ = true;
  }
  return mus_tk_ExpectedHitsOuter_;
}

std::vector<float>* const & cfa_base::mus_tk_LayersWithMeasurement() const{
  if(!c_mus_tk_LayersWithMeasurement_ && b_mus_tk_LayersWithMeasurement_){
    b_mus_tk_LayersWithMeasurement_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tk_LayersWithMeasurement", &mus_tk_LayersWithMeasurement_, &b_mus_tk_LayersWithMeasurement_);
    b_mus_tk_LayersWithMeasurement_->GetEntry(entry_);
    c_mus_tk_LayersWithMeasurement_ = true;
  }
  return mus_tk_LayersWithMeasurement_;
}

std::vector<float>* const & cfa_base::mus_tk_LayersWithoutMeasurement() const{
  if(!c_mus_tk_LayersWithoutMeasurement_ && b_mus_tk_LayersWithoutMeasurement_){
    b_mus_tk_LayersWithoutMeasurement_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tk_LayersWithoutMeasurement", &mus_tk_LayersWithoutMeasurement_, &b_mus_tk_LayersWithoutMeasurement_);
    b_mus_tk_LayersWithoutMeasurement_->GetEntry(entry_);
    c_mus_tk_LayersWithoutMeasurement_ = true;
  }
  return mus_tk_LayersWithoutMeasurement_;
}

std::vector<float>* const & cfa_base::mus_tk_PixelLayersWithMeasurement() const{
  if(!c_mus_tk_PixelLayersWithMeasurement_ && b_mus_tk_PixelLayersWithMeasurement_){
    b_mus_tk_PixelLayersWithMeasurement_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tk_PixelLayersWithMeasurement", &mus_tk_PixelLayersWithMeasurement_, &b_mus_tk_PixelLayersWithMeasurement_);
    b_mus_tk_PixelLayersWithMeasurement_->GetEntry(entry_);
    c_mus_tk_PixelLayersWithMeasurement_ = true;
  }
  return mus_tk_PixelLayersWithMeasurement_;
}

std::vector<float>* const & cfa_base::mus_tk_ValidStripLayersWithMonoAndStereoHit() const{
  if(!c_mus_tk_ValidStripLayersWithMonoAndStereoHit_ && b_mus_tk_ValidStripLayersWithMonoAndStereoHit_){
    b_mus_tk_ValidStripLayersWithMonoAndStereoHit_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tk_ValidStripLayersWithMonoAndStereoHit", &mus_tk_ValidStripLayersWithMonoAndStereoHit_, &b_mus_tk_ValidStripLayersWithMonoAndStereoHit_);
    b_mus_tk_ValidStripLayersWithMonoAndStereoHit_->GetEntry(entry_);
    c_mus_tk_ValidStripLayersWithMonoAndStereoHit_ = true;
  }
  return mus_tk_ValidStripLayersWithMonoAndStereoHit_;
}

std::vector<float>* const & cfa_base::mus_tk_chg() const{
  if(!c_mus_tk_chg_ && b_mus_tk_chg_){
    b_mus_tk_chg_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tk_chg", &mus_tk_chg_, &b_mus_tk_chg_);
    b_mus_tk_chg_->GetEntry(entry_);
    c_mus_tk_chg_ = true;
  }
  return mus_tk_chg_;
}

std::vector<float>* const & cfa_base::mus_tk_chi2() const{
  if(!c_mus_tk_chi2_ && b_mus_tk_chi2_){
    b_mus_tk_chi2_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tk_chi2", &mus_tk_chi2_, &b_mus_tk_chi2_);
    b_mus_tk_chi2_->GetEntry(entry_);
    c_mus_tk_chi2_ = true;
  }
  return mus_tk_chi2_;
}

std::vector<float>* const & cfa_base::mus_tk_d0dum() const{
  if(!c_mus_tk_d0dum_ && b_mus_tk_d0dum_){
    b_mus_tk_d0dum_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tk_d0dum", &mus_tk_d0dum_, &b_mus_tk_d0dum_);
    b_mus_tk_d0dum_->GetEntry(entry_);
    c_mus_tk_d0dum_ = true;
  }
  return mus_tk_d0dum_;
}

std::vector<float>* const & cfa_base::mus_tk_d0dumErr() const{
  if(!c_mus_tk_d0dumErr_ && b_mus_tk_d0dumErr_){
    b_mus_tk_d0dumErr_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tk_d0dumErr", &mus_tk_d0dumErr_, &b_mus_tk_d0dumErr_);
    b_mus_tk_d0dumErr_->GetEntry(entry_);
    c_mus_tk_d0dumErr_ = true;
  }
  return mus_tk_d0dumErr_;
}

std::vector<float>* const & cfa_base::mus_tk_dz() const{
  if(!c_mus_tk_dz_ && b_mus_tk_dz_){
    b_mus_tk_dz_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tk_dz", &mus_tk_dz_, &b_mus_tk_dz_);
    b_mus_tk_dz_->GetEntry(entry_);
    c_mus_tk_dz_ = true;
  }
  return mus_tk_dz_;
}

std::vector<float>* const & cfa_base::mus_tk_dzErr() const{
  if(!c_mus_tk_dzErr_ && b_mus_tk_dzErr_){
    b_mus_tk_dzErr_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tk_dzErr", &mus_tk_dzErr_, &b_mus_tk_dzErr_);
    b_mus_tk_dzErr_->GetEntry(entry_);
    c_mus_tk_dzErr_ = true;
  }
  return mus_tk_dzErr_;
}

std::vector<float>* const & cfa_base::mus_tk_eta() const{
  if(!c_mus_tk_eta_ && b_mus_tk_eta_){
    b_mus_tk_eta_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tk_eta", &mus_tk_eta_, &b_mus_tk_eta_);
    b_mus_tk_eta_->GetEntry(entry_);
    c_mus_tk_eta_ = true;
  }
  return mus_tk_eta_;
}

std::vector<float>* const & cfa_base::mus_tk_etaErr() const{
  if(!c_mus_tk_etaErr_ && b_mus_tk_etaErr_){
    b_mus_tk_etaErr_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tk_etaErr", &mus_tk_etaErr_, &b_mus_tk_etaErr_);
    b_mus_tk_etaErr_->GetEntry(entry_);
    c_mus_tk_etaErr_ = true;
  }
  return mus_tk_etaErr_;
}

std::vector<float>* const & cfa_base::mus_tk_id() const{
  if(!c_mus_tk_id_ && b_mus_tk_id_){
    b_mus_tk_id_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tk_id", &mus_tk_id_, &b_mus_tk_id_);
    b_mus_tk_id_->GetEntry(entry_);
    c_mus_tk_id_ = true;
  }
  return mus_tk_id_;
}

std::vector<float>* const & cfa_base::mus_tk_ndof() const{
  if(!c_mus_tk_ndof_ && b_mus_tk_ndof_){
    b_mus_tk_ndof_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tk_ndof", &mus_tk_ndof_, &b_mus_tk_ndof_);
    b_mus_tk_ndof_->GetEntry(entry_);
    c_mus_tk_ndof_ = true;
  }
  return mus_tk_ndof_;
}

std::vector<float>* const & cfa_base::mus_tk_numlosthits() const{
  if(!c_mus_tk_numlosthits_ && b_mus_tk_numlosthits_){
    b_mus_tk_numlosthits_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tk_numlosthits", &mus_tk_numlosthits_, &b_mus_tk_numlosthits_);
    b_mus_tk_numlosthits_->GetEntry(entry_);
    c_mus_tk_numlosthits_ = true;
  }
  return mus_tk_numlosthits_;
}

std::vector<float>* const & cfa_base::mus_tk_numpixelWthMeasr() const{
  if(!c_mus_tk_numpixelWthMeasr_ && b_mus_tk_numpixelWthMeasr_){
    b_mus_tk_numpixelWthMeasr_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tk_numpixelWthMeasr", &mus_tk_numpixelWthMeasr_, &b_mus_tk_numpixelWthMeasr_);
    b_mus_tk_numpixelWthMeasr_->GetEntry(entry_);
    c_mus_tk_numpixelWthMeasr_ = true;
  }
  return mus_tk_numpixelWthMeasr_;
}

std::vector<float>* const & cfa_base::mus_tk_numvalPixelhits() const{
  if(!c_mus_tk_numvalPixelhits_ && b_mus_tk_numvalPixelhits_){
    b_mus_tk_numvalPixelhits_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tk_numvalPixelhits", &mus_tk_numvalPixelhits_, &b_mus_tk_numvalPixelhits_);
    b_mus_tk_numvalPixelhits_->GetEntry(entry_);
    c_mus_tk_numvalPixelhits_ = true;
  }
  return mus_tk_numvalPixelhits_;
}

std::vector<float>* const & cfa_base::mus_tk_numvalhits() const{
  if(!c_mus_tk_numvalhits_ && b_mus_tk_numvalhits_){
    b_mus_tk_numvalhits_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tk_numvalhits", &mus_tk_numvalhits_, &b_mus_tk_numvalhits_);
    b_mus_tk_numvalhits_->GetEntry(entry_);
    c_mus_tk_numvalhits_ = true;
  }
  return mus_tk_numvalhits_;
}

std::vector<float>* const & cfa_base::mus_tk_phi() const{
  if(!c_mus_tk_phi_ && b_mus_tk_phi_){
    b_mus_tk_phi_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tk_phi", &mus_tk_phi_, &b_mus_tk_phi_);
    b_mus_tk_phi_->GetEntry(entry_);
    c_mus_tk_phi_ = true;
  }
  return mus_tk_phi_;
}

std::vector<float>* const & cfa_base::mus_tk_phiErr() const{
  if(!c_mus_tk_phiErr_ && b_mus_tk_phiErr_){
    b_mus_tk_phiErr_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tk_phiErr", &mus_tk_phiErr_, &b_mus_tk_phiErr_);
    b_mus_tk_phiErr_->GetEntry(entry_);
    c_mus_tk_phiErr_ = true;
  }
  return mus_tk_phiErr_;
}

std::vector<float>* const & cfa_base::mus_tk_pt() const{
  if(!c_mus_tk_pt_ && b_mus_tk_pt_){
    b_mus_tk_pt_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tk_pt", &mus_tk_pt_, &b_mus_tk_pt_);
    b_mus_tk_pt_->GetEntry(entry_);
    c_mus_tk_pt_ = true;
  }
  return mus_tk_pt_;
}

std::vector<float>* const & cfa_base::mus_tk_ptErr() const{
  if(!c_mus_tk_ptErr_ && b_mus_tk_ptErr_){
    b_mus_tk_ptErr_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tk_ptErr", &mus_tk_ptErr_, &b_mus_tk_ptErr_);
    b_mus_tk_ptErr_->GetEntry(entry_);
    c_mus_tk_ptErr_ = true;
  }
  return mus_tk_ptErr_;
}

std::vector<float>* const & cfa_base::mus_tk_px() const{
  if(!c_mus_tk_px_ && b_mus_tk_px_){
    b_mus_tk_px_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tk_px", &mus_tk_px_, &b_mus_tk_px_);
    b_mus_tk_px_->GetEntry(entry_);
    c_mus_tk_px_ = true;
  }
  return mus_tk_px_;
}

std::vector<float>* const & cfa_base::mus_tk_py() const{
  if(!c_mus_tk_py_ && b_mus_tk_py_){
    b_mus_tk_py_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tk_py", &mus_tk_py_, &b_mus_tk_py_);
    b_mus_tk_py_->GetEntry(entry_);
    c_mus_tk_py_ = true;
  }
  return mus_tk_py_;
}

std::vector<float>* const & cfa_base::mus_tk_pz() const{
  if(!c_mus_tk_pz_ && b_mus_tk_pz_){
    b_mus_tk_pz_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tk_pz", &mus_tk_pz_, &b_mus_tk_pz_);
    b_mus_tk_pz_->GetEntry(entry_);
    c_mus_tk_pz_ = true;
  }
  return mus_tk_pz_;
}

std::vector<float>* const & cfa_base::mus_tk_theta() const{
  if(!c_mus_tk_theta_ && b_mus_tk_theta_){
    b_mus_tk_theta_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tk_theta", &mus_tk_theta_, &b_mus_tk_theta_);
    b_mus_tk_theta_->GetEntry(entry_);
    c_mus_tk_theta_ = true;
  }
  return mus_tk_theta_;
}

std::vector<float>* const & cfa_base::mus_tk_vx() const{
  if(!c_mus_tk_vx_ && b_mus_tk_vx_){
    b_mus_tk_vx_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tk_vx", &mus_tk_vx_, &b_mus_tk_vx_);
    b_mus_tk_vx_->GetEntry(entry_);
    c_mus_tk_vx_ = true;
  }
  return mus_tk_vx_;
}

std::vector<float>* const & cfa_base::mus_tk_vy() const{
  if(!c_mus_tk_vy_ && b_mus_tk_vy_){
    b_mus_tk_vy_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tk_vy", &mus_tk_vy_, &b_mus_tk_vy_);
    b_mus_tk_vy_->GetEntry(entry_);
    c_mus_tk_vy_ = true;
  }
  return mus_tk_vy_;
}

std::vector<float>* const & cfa_base::mus_tk_vz() const{
  if(!c_mus_tk_vz_ && b_mus_tk_vz_){
    b_mus_tk_vz_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tk_vz", &mus_tk_vz_, &b_mus_tk_vz_);
    b_mus_tk_vz_->GetEntry(entry_);
    c_mus_tk_vz_ = true;
  }
  return mus_tk_vz_;
}

std::vector<float>* const & cfa_base::mus_tpfms_ExpectedHitsInner() const{
  if(!c_mus_tpfms_ExpectedHitsInner_ && b_mus_tpfms_ExpectedHitsInner_){
    b_mus_tpfms_ExpectedHitsInner_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tpfms_ExpectedHitsInner", &mus_tpfms_ExpectedHitsInner_, &b_mus_tpfms_ExpectedHitsInner_);
    b_mus_tpfms_ExpectedHitsInner_->GetEntry(entry_);
    c_mus_tpfms_ExpectedHitsInner_ = true;
  }
  return mus_tpfms_ExpectedHitsInner_;
}

std::vector<float>* const & cfa_base::mus_tpfms_ExpectedHitsOuter() const{
  if(!c_mus_tpfms_ExpectedHitsOuter_ && b_mus_tpfms_ExpectedHitsOuter_){
    b_mus_tpfms_ExpectedHitsOuter_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tpfms_ExpectedHitsOuter", &mus_tpfms_ExpectedHitsOuter_, &b_mus_tpfms_ExpectedHitsOuter_);
    b_mus_tpfms_ExpectedHitsOuter_->GetEntry(entry_);
    c_mus_tpfms_ExpectedHitsOuter_ = true;
  }
  return mus_tpfms_ExpectedHitsOuter_;
}

std::vector<float>* const & cfa_base::mus_tpfms_LayersWithMeasurement() const{
  if(!c_mus_tpfms_LayersWithMeasurement_ && b_mus_tpfms_LayersWithMeasurement_){
    b_mus_tpfms_LayersWithMeasurement_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tpfms_LayersWithMeasurement", &mus_tpfms_LayersWithMeasurement_, &b_mus_tpfms_LayersWithMeasurement_);
    b_mus_tpfms_LayersWithMeasurement_->GetEntry(entry_);
    c_mus_tpfms_LayersWithMeasurement_ = true;
  }
  return mus_tpfms_LayersWithMeasurement_;
}

std::vector<float>* const & cfa_base::mus_tpfms_LayersWithoutMeasurement() const{
  if(!c_mus_tpfms_LayersWithoutMeasurement_ && b_mus_tpfms_LayersWithoutMeasurement_){
    b_mus_tpfms_LayersWithoutMeasurement_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tpfms_LayersWithoutMeasurement", &mus_tpfms_LayersWithoutMeasurement_, &b_mus_tpfms_LayersWithoutMeasurement_);
    b_mus_tpfms_LayersWithoutMeasurement_->GetEntry(entry_);
    c_mus_tpfms_LayersWithoutMeasurement_ = true;
  }
  return mus_tpfms_LayersWithoutMeasurement_;
}

std::vector<float>* const & cfa_base::mus_tpfms_PixelLayersWithMeasurement() const{
  if(!c_mus_tpfms_PixelLayersWithMeasurement_ && b_mus_tpfms_PixelLayersWithMeasurement_){
    b_mus_tpfms_PixelLayersWithMeasurement_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tpfms_PixelLayersWithMeasurement", &mus_tpfms_PixelLayersWithMeasurement_, &b_mus_tpfms_PixelLayersWithMeasurement_);
    b_mus_tpfms_PixelLayersWithMeasurement_->GetEntry(entry_);
    c_mus_tpfms_PixelLayersWithMeasurement_ = true;
  }
  return mus_tpfms_PixelLayersWithMeasurement_;
}

std::vector<float>* const & cfa_base::mus_tpfms_ValidStripLayersWithMonoAndStereoHit() const{
  if(!c_mus_tpfms_ValidStripLayersWithMonoAndStereoHit_ && b_mus_tpfms_ValidStripLayersWithMonoAndStereoHit_){
    b_mus_tpfms_ValidStripLayersWithMonoAndStereoHit_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tpfms_ValidStripLayersWithMonoAndStereoHit", &mus_tpfms_ValidStripLayersWithMonoAndStereoHit_, &b_mus_tpfms_ValidStripLayersWithMonoAndStereoHit_);
    b_mus_tpfms_ValidStripLayersWithMonoAndStereoHit_->GetEntry(entry_);
    c_mus_tpfms_ValidStripLayersWithMonoAndStereoHit_ = true;
  }
  return mus_tpfms_ValidStripLayersWithMonoAndStereoHit_;
}

std::vector<float>* const & cfa_base::mus_tpfms_chg() const{
  if(!c_mus_tpfms_chg_ && b_mus_tpfms_chg_){
    b_mus_tpfms_chg_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tpfms_chg", &mus_tpfms_chg_, &b_mus_tpfms_chg_);
    b_mus_tpfms_chg_->GetEntry(entry_);
    c_mus_tpfms_chg_ = true;
  }
  return mus_tpfms_chg_;
}

std::vector<float>* const & cfa_base::mus_tpfms_chi2() const{
  if(!c_mus_tpfms_chi2_ && b_mus_tpfms_chi2_){
    b_mus_tpfms_chi2_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tpfms_chi2", &mus_tpfms_chi2_, &b_mus_tpfms_chi2_);
    b_mus_tpfms_chi2_->GetEntry(entry_);
    c_mus_tpfms_chi2_ = true;
  }
  return mus_tpfms_chi2_;
}

std::vector<float>* const & cfa_base::mus_tpfms_d0dum() const{
  if(!c_mus_tpfms_d0dum_ && b_mus_tpfms_d0dum_){
    b_mus_tpfms_d0dum_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tpfms_d0dum", &mus_tpfms_d0dum_, &b_mus_tpfms_d0dum_);
    b_mus_tpfms_d0dum_->GetEntry(entry_);
    c_mus_tpfms_d0dum_ = true;
  }
  return mus_tpfms_d0dum_;
}

std::vector<float>* const & cfa_base::mus_tpfms_d0dumErr() const{
  if(!c_mus_tpfms_d0dumErr_ && b_mus_tpfms_d0dumErr_){
    b_mus_tpfms_d0dumErr_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tpfms_d0dumErr", &mus_tpfms_d0dumErr_, &b_mus_tpfms_d0dumErr_);
    b_mus_tpfms_d0dumErr_->GetEntry(entry_);
    c_mus_tpfms_d0dumErr_ = true;
  }
  return mus_tpfms_d0dumErr_;
}

std::vector<float>* const & cfa_base::mus_tpfms_dz() const{
  if(!c_mus_tpfms_dz_ && b_mus_tpfms_dz_){
    b_mus_tpfms_dz_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tpfms_dz", &mus_tpfms_dz_, &b_mus_tpfms_dz_);
    b_mus_tpfms_dz_->GetEntry(entry_);
    c_mus_tpfms_dz_ = true;
  }
  return mus_tpfms_dz_;
}

std::vector<float>* const & cfa_base::mus_tpfms_dzErr() const{
  if(!c_mus_tpfms_dzErr_ && b_mus_tpfms_dzErr_){
    b_mus_tpfms_dzErr_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tpfms_dzErr", &mus_tpfms_dzErr_, &b_mus_tpfms_dzErr_);
    b_mus_tpfms_dzErr_->GetEntry(entry_);
    c_mus_tpfms_dzErr_ = true;
  }
  return mus_tpfms_dzErr_;
}

std::vector<float>* const & cfa_base::mus_tpfms_eta() const{
  if(!c_mus_tpfms_eta_ && b_mus_tpfms_eta_){
    b_mus_tpfms_eta_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tpfms_eta", &mus_tpfms_eta_, &b_mus_tpfms_eta_);
    b_mus_tpfms_eta_->GetEntry(entry_);
    c_mus_tpfms_eta_ = true;
  }
  return mus_tpfms_eta_;
}

std::vector<float>* const & cfa_base::mus_tpfms_etaErr() const{
  if(!c_mus_tpfms_etaErr_ && b_mus_tpfms_etaErr_){
    b_mus_tpfms_etaErr_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tpfms_etaErr", &mus_tpfms_etaErr_, &b_mus_tpfms_etaErr_);
    b_mus_tpfms_etaErr_->GetEntry(entry_);
    c_mus_tpfms_etaErr_ = true;
  }
  return mus_tpfms_etaErr_;
}

std::vector<float>* const & cfa_base::mus_tpfms_id() const{
  if(!c_mus_tpfms_id_ && b_mus_tpfms_id_){
    b_mus_tpfms_id_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tpfms_id", &mus_tpfms_id_, &b_mus_tpfms_id_);
    b_mus_tpfms_id_->GetEntry(entry_);
    c_mus_tpfms_id_ = true;
  }
  return mus_tpfms_id_;
}

std::vector<float>* const & cfa_base::mus_tpfms_ndof() const{
  if(!c_mus_tpfms_ndof_ && b_mus_tpfms_ndof_){
    b_mus_tpfms_ndof_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tpfms_ndof", &mus_tpfms_ndof_, &b_mus_tpfms_ndof_);
    b_mus_tpfms_ndof_->GetEntry(entry_);
    c_mus_tpfms_ndof_ = true;
  }
  return mus_tpfms_ndof_;
}

std::vector<float>* const & cfa_base::mus_tpfms_numlosthits() const{
  if(!c_mus_tpfms_numlosthits_ && b_mus_tpfms_numlosthits_){
    b_mus_tpfms_numlosthits_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tpfms_numlosthits", &mus_tpfms_numlosthits_, &b_mus_tpfms_numlosthits_);
    b_mus_tpfms_numlosthits_->GetEntry(entry_);
    c_mus_tpfms_numlosthits_ = true;
  }
  return mus_tpfms_numlosthits_;
}

std::vector<float>* const & cfa_base::mus_tpfms_numvalPixelhits() const{
  if(!c_mus_tpfms_numvalPixelhits_ && b_mus_tpfms_numvalPixelhits_){
    b_mus_tpfms_numvalPixelhits_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tpfms_numvalPixelhits", &mus_tpfms_numvalPixelhits_, &b_mus_tpfms_numvalPixelhits_);
    b_mus_tpfms_numvalPixelhits_->GetEntry(entry_);
    c_mus_tpfms_numvalPixelhits_ = true;
  }
  return mus_tpfms_numvalPixelhits_;
}

std::vector<float>* const & cfa_base::mus_tpfms_numvalhits() const{
  if(!c_mus_tpfms_numvalhits_ && b_mus_tpfms_numvalhits_){
    b_mus_tpfms_numvalhits_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tpfms_numvalhits", &mus_tpfms_numvalhits_, &b_mus_tpfms_numvalhits_);
    b_mus_tpfms_numvalhits_->GetEntry(entry_);
    c_mus_tpfms_numvalhits_ = true;
  }
  return mus_tpfms_numvalhits_;
}

std::vector<float>* const & cfa_base::mus_tpfms_phi() const{
  if(!c_mus_tpfms_phi_ && b_mus_tpfms_phi_){
    b_mus_tpfms_phi_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tpfms_phi", &mus_tpfms_phi_, &b_mus_tpfms_phi_);
    b_mus_tpfms_phi_->GetEntry(entry_);
    c_mus_tpfms_phi_ = true;
  }
  return mus_tpfms_phi_;
}

std::vector<float>* const & cfa_base::mus_tpfms_phiErr() const{
  if(!c_mus_tpfms_phiErr_ && b_mus_tpfms_phiErr_){
    b_mus_tpfms_phiErr_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tpfms_phiErr", &mus_tpfms_phiErr_, &b_mus_tpfms_phiErr_);
    b_mus_tpfms_phiErr_->GetEntry(entry_);
    c_mus_tpfms_phiErr_ = true;
  }
  return mus_tpfms_phiErr_;
}

std::vector<float>* const & cfa_base::mus_tpfms_pt() const{
  if(!c_mus_tpfms_pt_ && b_mus_tpfms_pt_){
    b_mus_tpfms_pt_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tpfms_pt", &mus_tpfms_pt_, &b_mus_tpfms_pt_);
    b_mus_tpfms_pt_->GetEntry(entry_);
    c_mus_tpfms_pt_ = true;
  }
  return mus_tpfms_pt_;
}

std::vector<float>* const & cfa_base::mus_tpfms_ptErr() const{
  if(!c_mus_tpfms_ptErr_ && b_mus_tpfms_ptErr_){
    b_mus_tpfms_ptErr_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tpfms_ptErr", &mus_tpfms_ptErr_, &b_mus_tpfms_ptErr_);
    b_mus_tpfms_ptErr_->GetEntry(entry_);
    c_mus_tpfms_ptErr_ = true;
  }
  return mus_tpfms_ptErr_;
}

std::vector<float>* const & cfa_base::mus_tpfms_px() const{
  if(!c_mus_tpfms_px_ && b_mus_tpfms_px_){
    b_mus_tpfms_px_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tpfms_px", &mus_tpfms_px_, &b_mus_tpfms_px_);
    b_mus_tpfms_px_->GetEntry(entry_);
    c_mus_tpfms_px_ = true;
  }
  return mus_tpfms_px_;
}

std::vector<float>* const & cfa_base::mus_tpfms_py() const{
  if(!c_mus_tpfms_py_ && b_mus_tpfms_py_){
    b_mus_tpfms_py_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tpfms_py", &mus_tpfms_py_, &b_mus_tpfms_py_);
    b_mus_tpfms_py_->GetEntry(entry_);
    c_mus_tpfms_py_ = true;
  }
  return mus_tpfms_py_;
}

std::vector<float>* const & cfa_base::mus_tpfms_pz() const{
  if(!c_mus_tpfms_pz_ && b_mus_tpfms_pz_){
    b_mus_tpfms_pz_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tpfms_pz", &mus_tpfms_pz_, &b_mus_tpfms_pz_);
    b_mus_tpfms_pz_->GetEntry(entry_);
    c_mus_tpfms_pz_ = true;
  }
  return mus_tpfms_pz_;
}

std::vector<float>* const & cfa_base::mus_tpfms_theta() const{
  if(!c_mus_tpfms_theta_ && b_mus_tpfms_theta_){
    b_mus_tpfms_theta_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tpfms_theta", &mus_tpfms_theta_, &b_mus_tpfms_theta_);
    b_mus_tpfms_theta_->GetEntry(entry_);
    c_mus_tpfms_theta_ = true;
  }
  return mus_tpfms_theta_;
}

std::vector<float>* const & cfa_base::mus_tpfms_vx() const{
  if(!c_mus_tpfms_vx_ && b_mus_tpfms_vx_){
    b_mus_tpfms_vx_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tpfms_vx", &mus_tpfms_vx_, &b_mus_tpfms_vx_);
    b_mus_tpfms_vx_->GetEntry(entry_);
    c_mus_tpfms_vx_ = true;
  }
  return mus_tpfms_vx_;
}

std::vector<float>* const & cfa_base::mus_tpfms_vy() const{
  if(!c_mus_tpfms_vy_ && b_mus_tpfms_vy_){
    b_mus_tpfms_vy_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tpfms_vy", &mus_tpfms_vy_, &b_mus_tpfms_vy_);
    b_mus_tpfms_vy_->GetEntry(entry_);
    c_mus_tpfms_vy_ = true;
  }
  return mus_tpfms_vy_;
}

std::vector<float>* const & cfa_base::mus_tpfms_vz() const{
  if(!c_mus_tpfms_vz_ && b_mus_tpfms_vz_){
    b_mus_tpfms_vz_->SetStatus(true);
    chainB_.SetBranchAddress("mus_tpfms_vz", &mus_tpfms_vz_, &b_mus_tpfms_vz_);
    b_mus_tpfms_vz_->GetEntry(entry_);
    c_mus_tpfms_vz_ = true;
  }
  return mus_tpfms_vz_;
}

UInt_t const & cfa_base::orbitNumber() const{
  if(!c_orbitNumber_ && b_orbitNumber_){
    b_orbitNumber_->SetStatus(true);
    chainB_.SetBranchAddress("orbitNumber", &orbitNumber_, &b_orbitNumber_);
    b_orbitNumber_->GetEntry(entry_);
    c_orbitNumber_ = true;
  }
  return orbitNumber_;
}

std::vector<float>* const & cfa_base::pfcand_charge() const{
  if(!c_pfcand_charge_ && b_pfcand_charge_){
    b_pfcand_charge_->SetStatus(true);
    chainB_.SetBranchAddress("pfcand_charge", &pfcand_charge_, &b_pfcand_charge_);
    b_pfcand_charge_->GetEntry(entry_);
    c_pfcand_charge_ = true;
  }
  return pfcand_charge_;
}

std::vector<float>* const & cfa_base::pfcand_energy() const{
  if(!c_pfcand_energy_ && b_pfcand_energy_){
    b_pfcand_energy_->SetStatus(true);
    chainB_.SetBranchAddress("pfcand_energy", &pfcand_energy_, &b_pfcand_energy_);
    b_pfcand_energy_->GetEntry(entry_);
    c_pfcand_energy_ = true;
  }
  return pfcand_energy_;
}

std::vector<float>* const & cfa_base::pfcand_eta() const{
  if(!c_pfcand_eta_ && b_pfcand_eta_){
    b_pfcand_eta_->SetStatus(true);
    chainB_.SetBranchAddress("pfcand_eta", &pfcand_eta_, &b_pfcand_eta_);
    b_pfcand_eta_->GetEntry(entry_);
    c_pfcand_eta_ = true;
  }
  return pfcand_eta_;
}

std::vector<float>* const & cfa_base::pfcand_pdgId() const{
  if(!c_pfcand_pdgId_ && b_pfcand_pdgId_){
    b_pfcand_pdgId_->SetStatus(true);
    chainB_.SetBranchAddress("pfcand_pdgId", &pfcand_pdgId_, &b_pfcand_pdgId_);
    b_pfcand_pdgId_->GetEntry(entry_);
    c_pfcand_pdgId_ = true;
  }
  return pfcand_pdgId_;
}

std::vector<float>* const & cfa_base::pfcand_phi() const{
  if(!c_pfcand_phi_ && b_pfcand_phi_){
    b_pfcand_phi_->SetStatus(true);
    chainB_.SetBranchAddress("pfcand_phi", &pfcand_phi_, &b_pfcand_phi_);
    b_pfcand_phi_->GetEntry(entry_);
    c_pfcand_phi_ = true;
  }
  return pfcand_phi_;
}

std::vector<float>* const & cfa_base::pfcand_pt() const{
  if(!c_pfcand_pt_ && b_pfcand_pt_){
    b_pfcand_pt_->SetStatus(true);
    chainB_.SetBranchAddress("pfcand_pt", &pfcand_pt_, &b_pfcand_pt_);
    b_pfcand_pt_->GetEntry(entry_);
    c_pfcand_pt_ = true;
  }
  return pfcand_pt_;
}

std::vector<float>* const & cfa_base::pfcand_px() const{
  if(!c_pfcand_px_ && b_pfcand_px_){
    b_pfcand_px_->SetStatus(true);
    chainB_.SetBranchAddress("pfcand_px", &pfcand_px_, &b_pfcand_px_);
    b_pfcand_px_->GetEntry(entry_);
    c_pfcand_px_ = true;
  }
  return pfcand_px_;
}

std::vector<float>* const & cfa_base::pfcand_py() const{
  if(!c_pfcand_py_ && b_pfcand_py_){
    b_pfcand_py_->SetStatus(true);
    chainB_.SetBranchAddress("pfcand_py", &pfcand_py_, &b_pfcand_py_);
    b_pfcand_py_->GetEntry(entry_);
    c_pfcand_py_ = true;
  }
  return pfcand_py_;
}

std::vector<float>* const & cfa_base::pfcand_pz() const{
  if(!c_pfcand_pz_ && b_pfcand_pz_){
    b_pfcand_pz_->SetStatus(true);
    chainB_.SetBranchAddress("pfcand_pz", &pfcand_pz_, &b_pfcand_pz_);
    b_pfcand_pz_->GetEntry(entry_);
    c_pfcand_pz_ = true;
  }
  return pfcand_pz_;
}

std::vector<float>* const & cfa_base::pfcand_theta() const{
  if(!c_pfcand_theta_ && b_pfcand_theta_){
    b_pfcand_theta_->SetStatus(true);
    chainB_.SetBranchAddress("pfcand_theta", &pfcand_theta_, &b_pfcand_theta_);
    b_pfcand_theta_->GetEntry(entry_);
    c_pfcand_theta_ = true;
  }
  return pfcand_theta_;
}

std::vector<float>* const & cfa_base::photons_e1x5() const{
  if(!c_photons_e1x5_ && b_photons_e1x5_){
    b_photons_e1x5_->SetStatus(true);
    chainB_.SetBranchAddress("photons_e1x5", &photons_e1x5_, &b_photons_e1x5_);
    b_photons_e1x5_->GetEntry(entry_);
    c_photons_e1x5_ = true;
  }
  return photons_e1x5_;
}

std::vector<float>* const & cfa_base::photons_e2x5() const{
  if(!c_photons_e2x5_ && b_photons_e2x5_){
    b_photons_e2x5_->SetStatus(true);
    chainB_.SetBranchAddress("photons_e2x5", &photons_e2x5_, &b_photons_e2x5_);
    b_photons_e2x5_->GetEntry(entry_);
    c_photons_e2x5_ = true;
  }
  return photons_e2x5_;
}

std::vector<float>* const & cfa_base::photons_e3x3() const{
  if(!c_photons_e3x3_ && b_photons_e3x3_){
    b_photons_e3x3_->SetStatus(true);
    chainB_.SetBranchAddress("photons_e3x3", &photons_e3x3_, &b_photons_e3x3_);
    b_photons_e3x3_->GetEntry(entry_);
    c_photons_e3x3_ = true;
  }
  return photons_e3x3_;
}

std::vector<float>* const & cfa_base::photons_e5x5() const{
  if(!c_photons_e5x5_ && b_photons_e5x5_){
    b_photons_e5x5_->SetStatus(true);
    chainB_.SetBranchAddress("photons_e5x5", &photons_e5x5_, &b_photons_e5x5_);
    b_photons_e5x5_->GetEntry(entry_);
    c_photons_e5x5_ = true;
  }
  return photons_e5x5_;
}

std::vector<float>* const & cfa_base::photons_ecalIso() const{
  if(!c_photons_ecalIso_ && b_photons_ecalIso_){
    b_photons_ecalIso_->SetStatus(true);
    chainB_.SetBranchAddress("photons_ecalIso", &photons_ecalIso_, &b_photons_ecalIso_);
    b_photons_ecalIso_->GetEntry(entry_);
    c_photons_ecalIso_ = true;
  }
  return photons_ecalIso_;
}

std::vector<float>* const & cfa_base::photons_energy() const{
  if(!c_photons_energy_ && b_photons_energy_){
    b_photons_energy_->SetStatus(true);
    chainB_.SetBranchAddress("photons_energy", &photons_energy_, &b_photons_energy_);
    b_photons_energy_->GetEntry(entry_);
    c_photons_energy_ = true;
  }
  return photons_energy_;
}

std::vector<float>* const & cfa_base::photons_et() const{
  if(!c_photons_et_ && b_photons_et_){
    b_photons_et_->SetStatus(true);
    chainB_.SetBranchAddress("photons_et", &photons_et_, &b_photons_et_);
    b_photons_et_->GetEntry(entry_);
    c_photons_et_ = true;
  }
  return photons_et_;
}

std::vector<float>* const & cfa_base::photons_eta() const{
  if(!c_photons_eta_ && b_photons_eta_){
    b_photons_eta_->SetStatus(true);
    chainB_.SetBranchAddress("photons_eta", &photons_eta_, &b_photons_eta_);
    b_photons_eta_->GetEntry(entry_);
    c_photons_eta_ = true;
  }
  return photons_eta_;
}

std::vector<float>* const & cfa_base::photons_gen_et() const{
  if(!c_photons_gen_et_ && b_photons_gen_et_){
    b_photons_gen_et_->SetStatus(true);
    chainB_.SetBranchAddress("photons_gen_et", &photons_gen_et_, &b_photons_gen_et_);
    b_photons_gen_et_->GetEntry(entry_);
    c_photons_gen_et_ = true;
  }
  return photons_gen_et_;
}

std::vector<float>* const & cfa_base::photons_gen_eta() const{
  if(!c_photons_gen_eta_ && b_photons_gen_eta_){
    b_photons_gen_eta_->SetStatus(true);
    chainB_.SetBranchAddress("photons_gen_eta", &photons_gen_eta_, &b_photons_gen_eta_);
    b_photons_gen_eta_->GetEntry(entry_);
    c_photons_gen_eta_ = true;
  }
  return photons_gen_eta_;
}

std::vector<float>* const & cfa_base::photons_gen_id() const{
  if(!c_photons_gen_id_ && b_photons_gen_id_){
    b_photons_gen_id_->SetStatus(true);
    chainB_.SetBranchAddress("photons_gen_id", &photons_gen_id_, &b_photons_gen_id_);
    b_photons_gen_id_->GetEntry(entry_);
    c_photons_gen_id_ = true;
  }
  return photons_gen_id_;
}

std::vector<float>* const & cfa_base::photons_gen_phi() const{
  if(!c_photons_gen_phi_ && b_photons_gen_phi_){
    b_photons_gen_phi_->SetStatus(true);
    chainB_.SetBranchAddress("photons_gen_phi", &photons_gen_phi_, &b_photons_gen_phi_);
    b_photons_gen_phi_->GetEntry(entry_);
    c_photons_gen_phi_ = true;
  }
  return photons_gen_phi_;
}

std::vector<float>* const & cfa_base::photons_hadOverEM() const{
  if(!c_photons_hadOverEM_ && b_photons_hadOverEM_){
    b_photons_hadOverEM_->SetStatus(true);
    chainB_.SetBranchAddress("photons_hadOverEM", &photons_hadOverEM_, &b_photons_hadOverEM_);
    b_photons_hadOverEM_->GetEntry(entry_);
    c_photons_hadOverEM_ = true;
  }
  return photons_hadOverEM_;
}

std::vector<float>* const & cfa_base::photons_hadTowOverEM() const{
  if(!c_photons_hadTowOverEM_ && b_photons_hadTowOverEM_){
    b_photons_hadTowOverEM_->SetStatus(true);
    chainB_.SetBranchAddress("photons_hadTowOverEM", &photons_hadTowOverEM_, &b_photons_hadTowOverEM_);
    b_photons_hadTowOverEM_->GetEntry(entry_);
    c_photons_hadTowOverEM_ = true;
  }
  return photons_hadTowOverEM_;
}

std::vector<float>* const & cfa_base::photons_hasPixelSeed() const{
  if(!c_photons_hasPixelSeed_ && b_photons_hasPixelSeed_){
    b_photons_hasPixelSeed_->SetStatus(true);
    chainB_.SetBranchAddress("photons_hasPixelSeed", &photons_hasPixelSeed_, &b_photons_hasPixelSeed_);
    b_photons_hasPixelSeed_->GetEntry(entry_);
    c_photons_hasPixelSeed_ = true;
  }
  return photons_hasPixelSeed_;
}

std::vector<float>* const & cfa_base::photons_hcalIso() const{
  if(!c_photons_hcalIso_ && b_photons_hcalIso_){
    b_photons_hcalIso_->SetStatus(true);
    chainB_.SetBranchAddress("photons_hcalIso", &photons_hcalIso_, &b_photons_hcalIso_);
    b_photons_hcalIso_->GetEntry(entry_);
    c_photons_hcalIso_ = true;
  }
  return photons_hcalIso_;
}

std::vector<float>* const & cfa_base::photons_isAlsoElectron() const{
  if(!c_photons_isAlsoElectron_ && b_photons_isAlsoElectron_){
    b_photons_isAlsoElectron_->SetStatus(true);
    chainB_.SetBranchAddress("photons_isAlsoElectron", &photons_isAlsoElectron_, &b_photons_isAlsoElectron_);
    b_photons_isAlsoElectron_->GetEntry(entry_);
    c_photons_isAlsoElectron_ = true;
  }
  return photons_isAlsoElectron_;
}

std::vector<float>* const & cfa_base::photons_isConverted() const{
  if(!c_photons_isConverted_ && b_photons_isConverted_){
    b_photons_isConverted_->SetStatus(true);
    chainB_.SetBranchAddress("photons_isConverted", &photons_isConverted_, &b_photons_isConverted_);
    b_photons_isConverted_->GetEntry(entry_);
    c_photons_isConverted_ = true;
  }
  return photons_isConverted_;
}

std::vector<float>* const & cfa_base::photons_isEBEEGap() const{
  if(!c_photons_isEBEEGap_ && b_photons_isEBEEGap_){
    b_photons_isEBEEGap_->SetStatus(true);
    chainB_.SetBranchAddress("photons_isEBEEGap", &photons_isEBEEGap_, &b_photons_isEBEEGap_);
    b_photons_isEBEEGap_->GetEntry(entry_);
    c_photons_isEBEEGap_ = true;
  }
  return photons_isEBEEGap_;
}

std::vector<float>* const & cfa_base::photons_isEBGap() const{
  if(!c_photons_isEBGap_ && b_photons_isEBGap_){
    b_photons_isEBGap_->SetStatus(true);
    chainB_.SetBranchAddress("photons_isEBGap", &photons_isEBGap_, &b_photons_isEBGap_);
    b_photons_isEBGap_->GetEntry(entry_);
    c_photons_isEBGap_ = true;
  }
  return photons_isEBGap_;
}

std::vector<float>* const & cfa_base::photons_isEBPho() const{
  if(!c_photons_isEBPho_ && b_photons_isEBPho_){
    b_photons_isEBPho_->SetStatus(true);
    chainB_.SetBranchAddress("photons_isEBPho", &photons_isEBPho_, &b_photons_isEBPho_);
    b_photons_isEBPho_->GetEntry(entry_);
    c_photons_isEBPho_ = true;
  }
  return photons_isEBPho_;
}

std::vector<float>* const & cfa_base::photons_isEEGap() const{
  if(!c_photons_isEEGap_ && b_photons_isEEGap_){
    b_photons_isEEGap_->SetStatus(true);
    chainB_.SetBranchAddress("photons_isEEGap", &photons_isEEGap_, &b_photons_isEEGap_);
    b_photons_isEEGap_->GetEntry(entry_);
    c_photons_isEEGap_ = true;
  }
  return photons_isEEGap_;
}

std::vector<float>* const & cfa_base::photons_isEEPho() const{
  if(!c_photons_isEEPho_ && b_photons_isEEPho_){
    b_photons_isEEPho_->SetStatus(true);
    chainB_.SetBranchAddress("photons_isEEPho", &photons_isEEPho_, &b_photons_isEEPho_);
    b_photons_isEEPho_->GetEntry(entry_);
    c_photons_isEEPho_ = true;
  }
  return photons_isEEPho_;
}

std::vector<float>* const & cfa_base::photons_isLoosePhoton() const{
  if(!c_photons_isLoosePhoton_ && b_photons_isLoosePhoton_){
    b_photons_isLoosePhoton_->SetStatus(true);
    chainB_.SetBranchAddress("photons_isLoosePhoton", &photons_isLoosePhoton_, &b_photons_isLoosePhoton_);
    b_photons_isLoosePhoton_->GetEntry(entry_);
    c_photons_isLoosePhoton_ = true;
  }
  return photons_isLoosePhoton_;
}

std::vector<float>* const & cfa_base::photons_isTightPhoton() const{
  if(!c_photons_isTightPhoton_ && b_photons_isTightPhoton_){
    b_photons_isTightPhoton_->SetStatus(true);
    chainB_.SetBranchAddress("photons_isTightPhoton", &photons_isTightPhoton_, &b_photons_isTightPhoton_);
    b_photons_isTightPhoton_->GetEntry(entry_);
    c_photons_isTightPhoton_ = true;
  }
  return photons_isTightPhoton_;
}

std::vector<float>* const & cfa_base::photons_isoEcalRecHitDR03() const{
  if(!c_photons_isoEcalRecHitDR03_ && b_photons_isoEcalRecHitDR03_){
    b_photons_isoEcalRecHitDR03_->SetStatus(true);
    chainB_.SetBranchAddress("photons_isoEcalRecHitDR03", &photons_isoEcalRecHitDR03_, &b_photons_isoEcalRecHitDR03_);
    b_photons_isoEcalRecHitDR03_->GetEntry(entry_);
    c_photons_isoEcalRecHitDR03_ = true;
  }
  return photons_isoEcalRecHitDR03_;
}

std::vector<float>* const & cfa_base::photons_isoEcalRecHitDR04() const{
  if(!c_photons_isoEcalRecHitDR04_ && b_photons_isoEcalRecHitDR04_){
    b_photons_isoEcalRecHitDR04_->SetStatus(true);
    chainB_.SetBranchAddress("photons_isoEcalRecHitDR04", &photons_isoEcalRecHitDR04_, &b_photons_isoEcalRecHitDR04_);
    b_photons_isoEcalRecHitDR04_->GetEntry(entry_);
    c_photons_isoEcalRecHitDR04_ = true;
  }
  return photons_isoEcalRecHitDR04_;
}

std::vector<float>* const & cfa_base::photons_isoHcalRecHitDR03() const{
  if(!c_photons_isoHcalRecHitDR03_ && b_photons_isoHcalRecHitDR03_){
    b_photons_isoHcalRecHitDR03_->SetStatus(true);
    chainB_.SetBranchAddress("photons_isoHcalRecHitDR03", &photons_isoHcalRecHitDR03_, &b_photons_isoHcalRecHitDR03_);
    b_photons_isoHcalRecHitDR03_->GetEntry(entry_);
    c_photons_isoHcalRecHitDR03_ = true;
  }
  return photons_isoHcalRecHitDR03_;
}

std::vector<float>* const & cfa_base::photons_isoHcalRecHitDR04() const{
  if(!c_photons_isoHcalRecHitDR04_ && b_photons_isoHcalRecHitDR04_){
    b_photons_isoHcalRecHitDR04_->SetStatus(true);
    chainB_.SetBranchAddress("photons_isoHcalRecHitDR04", &photons_isoHcalRecHitDR04_, &b_photons_isoHcalRecHitDR04_);
    b_photons_isoHcalRecHitDR04_->GetEntry(entry_);
    c_photons_isoHcalRecHitDR04_ = true;
  }
  return photons_isoHcalRecHitDR04_;
}

std::vector<float>* const & cfa_base::photons_isoHollowTrkConeDR03() const{
  if(!c_photons_isoHollowTrkConeDR03_ && b_photons_isoHollowTrkConeDR03_){
    b_photons_isoHollowTrkConeDR03_->SetStatus(true);
    chainB_.SetBranchAddress("photons_isoHollowTrkConeDR03", &photons_isoHollowTrkConeDR03_, &b_photons_isoHollowTrkConeDR03_);
    b_photons_isoHollowTrkConeDR03_->GetEntry(entry_);
    c_photons_isoHollowTrkConeDR03_ = true;
  }
  return photons_isoHollowTrkConeDR03_;
}

std::vector<float>* const & cfa_base::photons_isoHollowTrkConeDR04() const{
  if(!c_photons_isoHollowTrkConeDR04_ && b_photons_isoHollowTrkConeDR04_){
    b_photons_isoHollowTrkConeDR04_->SetStatus(true);
    chainB_.SetBranchAddress("photons_isoHollowTrkConeDR04", &photons_isoHollowTrkConeDR04_, &b_photons_isoHollowTrkConeDR04_);
    b_photons_isoHollowTrkConeDR04_->GetEntry(entry_);
    c_photons_isoHollowTrkConeDR04_ = true;
  }
  return photons_isoHollowTrkConeDR04_;
}

std::vector<float>* const & cfa_base::photons_isoSolidTrkConeDR03() const{
  if(!c_photons_isoSolidTrkConeDR03_ && b_photons_isoSolidTrkConeDR03_){
    b_photons_isoSolidTrkConeDR03_->SetStatus(true);
    chainB_.SetBranchAddress("photons_isoSolidTrkConeDR03", &photons_isoSolidTrkConeDR03_, &b_photons_isoSolidTrkConeDR03_);
    b_photons_isoSolidTrkConeDR03_->GetEntry(entry_);
    c_photons_isoSolidTrkConeDR03_ = true;
  }
  return photons_isoSolidTrkConeDR03_;
}

std::vector<float>* const & cfa_base::photons_isoSolidTrkConeDR04() const{
  if(!c_photons_isoSolidTrkConeDR04_ && b_photons_isoSolidTrkConeDR04_){
    b_photons_isoSolidTrkConeDR04_->SetStatus(true);
    chainB_.SetBranchAddress("photons_isoSolidTrkConeDR04", &photons_isoSolidTrkConeDR04_, &b_photons_isoSolidTrkConeDR04_);
    b_photons_isoSolidTrkConeDR04_->GetEntry(entry_);
    c_photons_isoSolidTrkConeDR04_ = true;
  }
  return photons_isoSolidTrkConeDR04_;
}

std::vector<float>* const & cfa_base::photons_maxEnergyXtal() const{
  if(!c_photons_maxEnergyXtal_ && b_photons_maxEnergyXtal_){
    b_photons_maxEnergyXtal_->SetStatus(true);
    chainB_.SetBranchAddress("photons_maxEnergyXtal", &photons_maxEnergyXtal_, &b_photons_maxEnergyXtal_);
    b_photons_maxEnergyXtal_->GetEntry(entry_);
    c_photons_maxEnergyXtal_ = true;
  }
  return photons_maxEnergyXtal_;
}

std::vector<float>* const & cfa_base::photons_nTrkHollowConeDR03() const{
  if(!c_photons_nTrkHollowConeDR03_ && b_photons_nTrkHollowConeDR03_){
    b_photons_nTrkHollowConeDR03_->SetStatus(true);
    chainB_.SetBranchAddress("photons_nTrkHollowConeDR03", &photons_nTrkHollowConeDR03_, &b_photons_nTrkHollowConeDR03_);
    b_photons_nTrkHollowConeDR03_->GetEntry(entry_);
    c_photons_nTrkHollowConeDR03_ = true;
  }
  return photons_nTrkHollowConeDR03_;
}

std::vector<float>* const & cfa_base::photons_nTrkHollowConeDR04() const{
  if(!c_photons_nTrkHollowConeDR04_ && b_photons_nTrkHollowConeDR04_){
    b_photons_nTrkHollowConeDR04_->SetStatus(true);
    chainB_.SetBranchAddress("photons_nTrkHollowConeDR04", &photons_nTrkHollowConeDR04_, &b_photons_nTrkHollowConeDR04_);
    b_photons_nTrkHollowConeDR04_->GetEntry(entry_);
    c_photons_nTrkHollowConeDR04_ = true;
  }
  return photons_nTrkHollowConeDR04_;
}

std::vector<float>* const & cfa_base::photons_nTrkSolidConeDR03() const{
  if(!c_photons_nTrkSolidConeDR03_ && b_photons_nTrkSolidConeDR03_){
    b_photons_nTrkSolidConeDR03_->SetStatus(true);
    chainB_.SetBranchAddress("photons_nTrkSolidConeDR03", &photons_nTrkSolidConeDR03_, &b_photons_nTrkSolidConeDR03_);
    b_photons_nTrkSolidConeDR03_->GetEntry(entry_);
    c_photons_nTrkSolidConeDR03_ = true;
  }
  return photons_nTrkSolidConeDR03_;
}

std::vector<float>* const & cfa_base::photons_nTrkSolidConeDR04() const{
  if(!c_photons_nTrkSolidConeDR04_ && b_photons_nTrkSolidConeDR04_){
    b_photons_nTrkSolidConeDR04_->SetStatus(true);
    chainB_.SetBranchAddress("photons_nTrkSolidConeDR04", &photons_nTrkSolidConeDR04_, &b_photons_nTrkSolidConeDR04_);
    b_photons_nTrkSolidConeDR04_->GetEntry(entry_);
    c_photons_nTrkSolidConeDR04_ = true;
  }
  return photons_nTrkSolidConeDR04_;
}

std::vector<float>* const & cfa_base::photons_phi() const{
  if(!c_photons_phi_ && b_photons_phi_){
    b_photons_phi_->SetStatus(true);
    chainB_.SetBranchAddress("photons_phi", &photons_phi_, &b_photons_phi_);
    b_photons_phi_->GetEntry(entry_);
    c_photons_phi_ = true;
  }
  return photons_phi_;
}

std::vector<float>* const & cfa_base::photons_pt() const{
  if(!c_photons_pt_ && b_photons_pt_){
    b_photons_pt_->SetStatus(true);
    chainB_.SetBranchAddress("photons_pt", &photons_pt_, &b_photons_pt_);
    b_photons_pt_->GetEntry(entry_);
    c_photons_pt_ = true;
  }
  return photons_pt_;
}

std::vector<float>* const & cfa_base::photons_px() const{
  if(!c_photons_px_ && b_photons_px_){
    b_photons_px_->SetStatus(true);
    chainB_.SetBranchAddress("photons_px", &photons_px_, &b_photons_px_);
    b_photons_px_->GetEntry(entry_);
    c_photons_px_ = true;
  }
  return photons_px_;
}

std::vector<float>* const & cfa_base::photons_py() const{
  if(!c_photons_py_ && b_photons_py_){
    b_photons_py_->SetStatus(true);
    chainB_.SetBranchAddress("photons_py", &photons_py_, &b_photons_py_);
    b_photons_py_->GetEntry(entry_);
    c_photons_py_ = true;
  }
  return photons_py_;
}

std::vector<float>* const & cfa_base::photons_pz() const{
  if(!c_photons_pz_ && b_photons_pz_){
    b_photons_pz_->SetStatus(true);
    chainB_.SetBranchAddress("photons_pz", &photons_pz_, &b_photons_pz_);
    b_photons_pz_->GetEntry(entry_);
    c_photons_pz_ = true;
  }
  return photons_pz_;
}

std::vector<float>* const & cfa_base::photons_r9() const{
  if(!c_photons_r9_ && b_photons_r9_){
    b_photons_r9_->SetStatus(true);
    chainB_.SetBranchAddress("photons_r9", &photons_r9_, &b_photons_r9_);
    b_photons_r9_->GetEntry(entry_);
    c_photons_r9_ = true;
  }
  return photons_r9_;
}

std::vector<float>* const & cfa_base::photons_scEnergy() const{
  if(!c_photons_scEnergy_ && b_photons_scEnergy_){
    b_photons_scEnergy_->SetStatus(true);
    chainB_.SetBranchAddress("photons_scEnergy", &photons_scEnergy_, &b_photons_scEnergy_);
    b_photons_scEnergy_->GetEntry(entry_);
    c_photons_scEnergy_ = true;
  }
  return photons_scEnergy_;
}

std::vector<float>* const & cfa_base::photons_scEta() const{
  if(!c_photons_scEta_ && b_photons_scEta_){
    b_photons_scEta_->SetStatus(true);
    chainB_.SetBranchAddress("photons_scEta", &photons_scEta_, &b_photons_scEta_);
    b_photons_scEta_->GetEntry(entry_);
    c_photons_scEta_ = true;
  }
  return photons_scEta_;
}

std::vector<float>* const & cfa_base::photons_scEtaWidth() const{
  if(!c_photons_scEtaWidth_ && b_photons_scEtaWidth_){
    b_photons_scEtaWidth_->SetStatus(true);
    chainB_.SetBranchAddress("photons_scEtaWidth", &photons_scEtaWidth_, &b_photons_scEtaWidth_);
    b_photons_scEtaWidth_->GetEntry(entry_);
    c_photons_scEtaWidth_ = true;
  }
  return photons_scEtaWidth_;
}

std::vector<float>* const & cfa_base::photons_scPhi() const{
  if(!c_photons_scPhi_ && b_photons_scPhi_){
    b_photons_scPhi_->SetStatus(true);
    chainB_.SetBranchAddress("photons_scPhi", &photons_scPhi_, &b_photons_scPhi_);
    b_photons_scPhi_->GetEntry(entry_);
    c_photons_scPhi_ = true;
  }
  return photons_scPhi_;
}

std::vector<float>* const & cfa_base::photons_scPhiWidth() const{
  if(!c_photons_scPhiWidth_ && b_photons_scPhiWidth_){
    b_photons_scPhiWidth_->SetStatus(true);
    chainB_.SetBranchAddress("photons_scPhiWidth", &photons_scPhiWidth_, &b_photons_scPhiWidth_);
    b_photons_scPhiWidth_->GetEntry(entry_);
    c_photons_scPhiWidth_ = true;
  }
  return photons_scPhiWidth_;
}

std::vector<float>* const & cfa_base::photons_scRawEnergy() const{
  if(!c_photons_scRawEnergy_ && b_photons_scRawEnergy_){
    b_photons_scRawEnergy_->SetStatus(true);
    chainB_.SetBranchAddress("photons_scRawEnergy", &photons_scRawEnergy_, &b_photons_scRawEnergy_);
    b_photons_scRawEnergy_->GetEntry(entry_);
    c_photons_scRawEnergy_ = true;
  }
  return photons_scRawEnergy_;
}

std::vector<float>* const & cfa_base::photons_sigmaEtaEta() const{
  if(!c_photons_sigmaEtaEta_ && b_photons_sigmaEtaEta_){
    b_photons_sigmaEtaEta_->SetStatus(true);
    chainB_.SetBranchAddress("photons_sigmaEtaEta", &photons_sigmaEtaEta_, &b_photons_sigmaEtaEta_);
    b_photons_sigmaEtaEta_->GetEntry(entry_);
    c_photons_sigmaEtaEta_ = true;
  }
  return photons_sigmaEtaEta_;
}

std::vector<float>* const & cfa_base::photons_sigmaIetaIeta() const{
  if(!c_photons_sigmaIetaIeta_ && b_photons_sigmaIetaIeta_){
    b_photons_sigmaIetaIeta_->SetStatus(true);
    chainB_.SetBranchAddress("photons_sigmaIetaIeta", &photons_sigmaIetaIeta_, &b_photons_sigmaIetaIeta_);
    b_photons_sigmaIetaIeta_->GetEntry(entry_);
    c_photons_sigmaIetaIeta_ = true;
  }
  return photons_sigmaIetaIeta_;
}

std::vector<float>* const & cfa_base::photons_status() const{
  if(!c_photons_status_ && b_photons_status_){
    b_photons_status_->SetStatus(true);
    chainB_.SetBranchAddress("photons_status", &photons_status_, &b_photons_status_);
    b_photons_status_->GetEntry(entry_);
    c_photons_status_ = true;
  }
  return photons_status_;
}

std::vector<float>* const & cfa_base::photons_tIso() const{
  if(!c_photons_tIso_ && b_photons_tIso_){
    b_photons_tIso_->SetStatus(true);
    chainB_.SetBranchAddress("photons_tIso", &photons_tIso_, &b_photons_tIso_);
    b_photons_tIso_->GetEntry(entry_);
    c_photons_tIso_ = true;
  }
  return photons_tIso_;
}

std::vector<float>* const & cfa_base::photons_theta() const{
  if(!c_photons_theta_ && b_photons_theta_){
    b_photons_theta_->SetStatus(true);
    chainB_.SetBranchAddress("photons_theta", &photons_theta_, &b_photons_theta_);
    b_photons_theta_->GetEntry(entry_);
    c_photons_theta_ = true;
  }
  return photons_theta_;
}

std::vector<float>* const & cfa_base::pv_chi2() const{
  if(!c_pv_chi2_ && b_pv_chi2_){
    b_pv_chi2_->SetStatus(true);
    chainB_.SetBranchAddress("pv_chi2", &pv_chi2_, &b_pv_chi2_);
    b_pv_chi2_->GetEntry(entry_);
    c_pv_chi2_ = true;
  }
  return pv_chi2_;
}

std::vector<float>* const & cfa_base::pv_isFake() const{
  if(!c_pv_isFake_ && b_pv_isFake_){
    b_pv_isFake_->SetStatus(true);
    chainB_.SetBranchAddress("pv_isFake", &pv_isFake_, &b_pv_isFake_);
    b_pv_isFake_->GetEntry(entry_);
    c_pv_isFake_ = true;
  }
  return pv_isFake_;
}

std::vector<float>* const & cfa_base::pv_isValid() const{
  if(!c_pv_isValid_ && b_pv_isValid_){
    b_pv_isValid_->SetStatus(true);
    chainB_.SetBranchAddress("pv_isValid", &pv_isValid_, &b_pv_isValid_);
    b_pv_isValid_->GetEntry(entry_);
    c_pv_isValid_ = true;
  }
  return pv_isValid_;
}

std::vector<float>* const & cfa_base::pv_ndof() const{
  if(!c_pv_ndof_ && b_pv_ndof_){
    b_pv_ndof_->SetStatus(true);
    chainB_.SetBranchAddress("pv_ndof", &pv_ndof_, &b_pv_ndof_);
    b_pv_ndof_->GetEntry(entry_);
    c_pv_ndof_ = true;
  }
  return pv_ndof_;
}

std::vector<float>* const & cfa_base::pv_tracksSize() const{
  if(!c_pv_tracksSize_ && b_pv_tracksSize_){
    b_pv_tracksSize_->SetStatus(true);
    chainB_.SetBranchAddress("pv_tracksSize", &pv_tracksSize_, &b_pv_tracksSize_);
    b_pv_tracksSize_->GetEntry(entry_);
    c_pv_tracksSize_ = true;
  }
  return pv_tracksSize_;
}

std::vector<float>* const & cfa_base::pv_x() const{
  if(!c_pv_x_ && b_pv_x_){
    b_pv_x_->SetStatus(true);
    chainB_.SetBranchAddress("pv_x", &pv_x_, &b_pv_x_);
    b_pv_x_->GetEntry(entry_);
    c_pv_x_ = true;
  }
  return pv_x_;
}

std::vector<float>* const & cfa_base::pv_xErr() const{
  if(!c_pv_xErr_ && b_pv_xErr_){
    b_pv_xErr_->SetStatus(true);
    chainB_.SetBranchAddress("pv_xErr", &pv_xErr_, &b_pv_xErr_);
    b_pv_xErr_->GetEntry(entry_);
    c_pv_xErr_ = true;
  }
  return pv_xErr_;
}

std::vector<float>* const & cfa_base::pv_y() const{
  if(!c_pv_y_ && b_pv_y_){
    b_pv_y_->SetStatus(true);
    chainB_.SetBranchAddress("pv_y", &pv_y_, &b_pv_y_);
    b_pv_y_->GetEntry(entry_);
    c_pv_y_ = true;
  }
  return pv_y_;
}

std::vector<float>* const & cfa_base::pv_yErr() const{
  if(!c_pv_yErr_ && b_pv_yErr_){
    b_pv_yErr_->SetStatus(true);
    chainB_.SetBranchAddress("pv_yErr", &pv_yErr_, &b_pv_yErr_);
    b_pv_yErr_->GetEntry(entry_);
    c_pv_yErr_ = true;
  }
  return pv_yErr_;
}

std::vector<float>* const & cfa_base::pv_z() const{
  if(!c_pv_z_ && b_pv_z_){
    b_pv_z_->SetStatus(true);
    chainB_.SetBranchAddress("pv_z", &pv_z_, &b_pv_z_);
    b_pv_z_->GetEntry(entry_);
    c_pv_z_ = true;
  }
  return pv_z_;
}

std::vector<float>* const & cfa_base::pv_zErr() const{
  if(!c_pv_zErr_ && b_pv_zErr_){
    b_pv_zErr_->SetStatus(true);
    chainB_.SetBranchAddress("pv_zErr", &pv_zErr_, &b_pv_zErr_);
    b_pv_zErr_->GetEntry(entry_);
    c_pv_zErr_ = true;
  }
  return pv_zErr_;
}

UInt_t const & cfa_base::run() const{
  if(!c_run_ && b_run_){
    b_run_->SetStatus(true);
    chainB_.SetBranchAddress("run", &run_, &b_run_);
    b_run_->GetEntry(entry_);
    c_run_ = true;
  }
  return run_;
}

std::vector<std::string>* const & cfa_base::standalone_triggerobject_collectionname() const{
  if(!c_standalone_triggerobject_collectionname_ && b_standalone_triggerobject_collectionname_){
    b_standalone_triggerobject_collectionname_->SetStatus(true);
    chainA_.SetBranchAddress("standalone_triggerobject_collectionname", &standalone_triggerobject_collectionname_, &b_standalone_triggerobject_collectionname_);
    b_standalone_triggerobject_collectionname_->GetEntry(entry_);
    c_standalone_triggerobject_collectionname_ = true;
  }
  return standalone_triggerobject_collectionname_;
}

std::vector<float>* const & cfa_base::standalone_triggerobject_energy() const{
  if(!c_standalone_triggerobject_energy_ && b_standalone_triggerobject_energy_){
    b_standalone_triggerobject_energy_->SetStatus(true);
    chainA_.SetBranchAddress("standalone_triggerobject_energy", &standalone_triggerobject_energy_, &b_standalone_triggerobject_energy_);
    b_standalone_triggerobject_energy_->GetEntry(entry_);
    c_standalone_triggerobject_energy_ = true;
  }
  return standalone_triggerobject_energy_;
}

std::vector<float>* const & cfa_base::standalone_triggerobject_et() const{
  if(!c_standalone_triggerobject_et_ && b_standalone_triggerobject_et_){
    b_standalone_triggerobject_et_->SetStatus(true);
    chainA_.SetBranchAddress("standalone_triggerobject_et", &standalone_triggerobject_et_, &b_standalone_triggerobject_et_);
    b_standalone_triggerobject_et_->GetEntry(entry_);
    c_standalone_triggerobject_et_ = true;
  }
  return standalone_triggerobject_et_;
}

std::vector<float>* const & cfa_base::standalone_triggerobject_eta() const{
  if(!c_standalone_triggerobject_eta_ && b_standalone_triggerobject_eta_){
    b_standalone_triggerobject_eta_->SetStatus(true);
    chainA_.SetBranchAddress("standalone_triggerobject_eta", &standalone_triggerobject_eta_, &b_standalone_triggerobject_eta_);
    b_standalone_triggerobject_eta_->GetEntry(entry_);
    c_standalone_triggerobject_eta_ = true;
  }
  return standalone_triggerobject_eta_;
}

std::vector<float>* const & cfa_base::standalone_triggerobject_phi() const{
  if(!c_standalone_triggerobject_phi_ && b_standalone_triggerobject_phi_){
    b_standalone_triggerobject_phi_->SetStatus(true);
    chainA_.SetBranchAddress("standalone_triggerobject_phi", &standalone_triggerobject_phi_, &b_standalone_triggerobject_phi_);
    b_standalone_triggerobject_phi_->GetEntry(entry_);
    c_standalone_triggerobject_phi_ = true;
  }
  return standalone_triggerobject_phi_;
}

std::vector<float>* const & cfa_base::standalone_triggerobject_pt() const{
  if(!c_standalone_triggerobject_pt_ && b_standalone_triggerobject_pt_){
    b_standalone_triggerobject_pt_->SetStatus(true);
    chainA_.SetBranchAddress("standalone_triggerobject_pt", &standalone_triggerobject_pt_, &b_standalone_triggerobject_pt_);
    b_standalone_triggerobject_pt_->GetEntry(entry_);
    c_standalone_triggerobject_pt_ = true;
  }
  return standalone_triggerobject_pt_;
}

std::vector<float>* const & cfa_base::standalone_triggerobject_px() const{
  if(!c_standalone_triggerobject_px_ && b_standalone_triggerobject_px_){
    b_standalone_triggerobject_px_->SetStatus(true);
    chainA_.SetBranchAddress("standalone_triggerobject_px", &standalone_triggerobject_px_, &b_standalone_triggerobject_px_);
    b_standalone_triggerobject_px_->GetEntry(entry_);
    c_standalone_triggerobject_px_ = true;
  }
  return standalone_triggerobject_px_;
}

std::vector<float>* const & cfa_base::standalone_triggerobject_py() const{
  if(!c_standalone_triggerobject_py_ && b_standalone_triggerobject_py_){
    b_standalone_triggerobject_py_->SetStatus(true);
    chainA_.SetBranchAddress("standalone_triggerobject_py", &standalone_triggerobject_py_, &b_standalone_triggerobject_py_);
    b_standalone_triggerobject_py_->GetEntry(entry_);
    c_standalone_triggerobject_py_ = true;
  }
  return standalone_triggerobject_py_;
}

std::vector<float>* const & cfa_base::standalone_triggerobject_pz() const{
  if(!c_standalone_triggerobject_pz_ && b_standalone_triggerobject_pz_){
    b_standalone_triggerobject_pz_->SetStatus(true);
    chainA_.SetBranchAddress("standalone_triggerobject_pz", &standalone_triggerobject_pz_, &b_standalone_triggerobject_pz_);
    b_standalone_triggerobject_pz_->GetEntry(entry_);
    c_standalone_triggerobject_pz_ = true;
  }
  return standalone_triggerobject_pz_;
}

std::vector<float>* const & cfa_base::taus_Nprongs() const{
  if(!c_taus_Nprongs_ && b_taus_Nprongs_){
    b_taus_Nprongs_->SetStatus(true);
    chainB_.SetBranchAddress("taus_Nprongs", &taus_Nprongs_, &b_taus_Nprongs_);
    b_taus_Nprongs_->GetEntry(entry_);
    c_taus_Nprongs_ = true;
  }
  return taus_Nprongs_;
}

std::vector<float>* const & cfa_base::taus_againstElectron() const{
  if(!c_taus_againstElectron_ && b_taus_againstElectron_){
    b_taus_againstElectron_->SetStatus(true);
    chainB_.SetBranchAddress("taus_againstElectron", &taus_againstElectron_, &b_taus_againstElectron_);
    b_taus_againstElectron_->GetEntry(entry_);
    c_taus_againstElectron_ = true;
  }
  return taus_againstElectron_;
}

std::vector<float>* const & cfa_base::taus_againstElectronLoose() const{
  if(!c_taus_againstElectronLoose_ && b_taus_againstElectronLoose_){
    b_taus_againstElectronLoose_->SetStatus(true);
    chainB_.SetBranchAddress("taus_againstElectronLoose", &taus_againstElectronLoose_, &b_taus_againstElectronLoose_);
    b_taus_againstElectronLoose_->GetEntry(entry_);
    c_taus_againstElectronLoose_ = true;
  }
  return taus_againstElectronLoose_;
}

std::vector<float>* const & cfa_base::taus_againstElectronMVA() const{
  if(!c_taus_againstElectronMVA_ && b_taus_againstElectronMVA_){
    b_taus_againstElectronMVA_->SetStatus(true);
    chainB_.SetBranchAddress("taus_againstElectronMVA", &taus_againstElectronMVA_, &b_taus_againstElectronMVA_);
    b_taus_againstElectronMVA_->GetEntry(entry_);
    c_taus_againstElectronMVA_ = true;
  }
  return taus_againstElectronMVA_;
}

std::vector<float>* const & cfa_base::taus_againstElectronMedium() const{
  if(!c_taus_againstElectronMedium_ && b_taus_againstElectronMedium_){
    b_taus_againstElectronMedium_->SetStatus(true);
    chainB_.SetBranchAddress("taus_againstElectronMedium", &taus_againstElectronMedium_, &b_taus_againstElectronMedium_);
    b_taus_againstElectronMedium_->GetEntry(entry_);
    c_taus_againstElectronMedium_ = true;
  }
  return taus_againstElectronMedium_;
}

std::vector<float>* const & cfa_base::taus_againstElectronTight() const{
  if(!c_taus_againstElectronTight_ && b_taus_againstElectronTight_){
    b_taus_againstElectronTight_->SetStatus(true);
    chainB_.SetBranchAddress("taus_againstElectronTight", &taus_againstElectronTight_, &b_taus_againstElectronTight_);
    b_taus_againstElectronTight_->GetEntry(entry_);
    c_taus_againstElectronTight_ = true;
  }
  return taus_againstElectronTight_;
}

std::vector<float>* const & cfa_base::taus_againstMuon() const{
  if(!c_taus_againstMuon_ && b_taus_againstMuon_){
    b_taus_againstMuon_->SetStatus(true);
    chainB_.SetBranchAddress("taus_againstMuon", &taus_againstMuon_, &b_taus_againstMuon_);
    b_taus_againstMuon_->GetEntry(entry_);
    c_taus_againstMuon_ = true;
  }
  return taus_againstMuon_;
}

std::vector<float>* const & cfa_base::taus_againstMuonLoose() const{
  if(!c_taus_againstMuonLoose_ && b_taus_againstMuonLoose_){
    b_taus_againstMuonLoose_->SetStatus(true);
    chainB_.SetBranchAddress("taus_againstMuonLoose", &taus_againstMuonLoose_, &b_taus_againstMuonLoose_);
    b_taus_againstMuonLoose_->GetEntry(entry_);
    c_taus_againstMuonLoose_ = true;
  }
  return taus_againstMuonLoose_;
}

std::vector<float>* const & cfa_base::taus_againstMuonMedium() const{
  if(!c_taus_againstMuonMedium_ && b_taus_againstMuonMedium_){
    b_taus_againstMuonMedium_->SetStatus(true);
    chainB_.SetBranchAddress("taus_againstMuonMedium", &taus_againstMuonMedium_, &b_taus_againstMuonMedium_);
    b_taus_againstMuonMedium_->GetEntry(entry_);
    c_taus_againstMuonMedium_ = true;
  }
  return taus_againstMuonMedium_;
}

std::vector<float>* const & cfa_base::taus_againstMuonTight() const{
  if(!c_taus_againstMuonTight_ && b_taus_againstMuonTight_){
    b_taus_againstMuonTight_->SetStatus(true);
    chainB_.SetBranchAddress("taus_againstMuonTight", &taus_againstMuonTight_, &b_taus_againstMuonTight_);
    b_taus_againstMuonTight_->GetEntry(entry_);
    c_taus_againstMuonTight_ = true;
  }
  return taus_againstMuonTight_;
}

std::vector<float>* const & cfa_base::taus_byIsoUsingLeadingPi() const{
  if(!c_taus_byIsoUsingLeadingPi_ && b_taus_byIsoUsingLeadingPi_){
    b_taus_byIsoUsingLeadingPi_->SetStatus(true);
    chainB_.SetBranchAddress("taus_byIsoUsingLeadingPi", &taus_byIsoUsingLeadingPi_, &b_taus_byIsoUsingLeadingPi_);
    b_taus_byIsoUsingLeadingPi_->GetEntry(entry_);
    c_taus_byIsoUsingLeadingPi_ = true;
  }
  return taus_byIsoUsingLeadingPi_;
}

std::vector<float>* const & cfa_base::taus_byIsolation() const{
  if(!c_taus_byIsolation_ && b_taus_byIsolation_){
    b_taus_byIsolation_->SetStatus(true);
    chainB_.SetBranchAddress("taus_byIsolation", &taus_byIsolation_, &b_taus_byIsolation_);
    b_taus_byIsolation_->GetEntry(entry_);
    c_taus_byIsolation_ = true;
  }
  return taus_byIsolation_;
}

std::vector<float>* const & cfa_base::taus_byLooseIsolation() const{
  if(!c_taus_byLooseIsolation_ && b_taus_byLooseIsolation_){
    b_taus_byLooseIsolation_->SetStatus(true);
    chainB_.SetBranchAddress("taus_byLooseIsolation", &taus_byLooseIsolation_, &b_taus_byLooseIsolation_);
    b_taus_byLooseIsolation_->GetEntry(entry_);
    c_taus_byLooseIsolation_ = true;
  }
  return taus_byLooseIsolation_;
}

std::vector<float>* const & cfa_base::taus_byLooseIsolationDeltaBetaCorr() const{
  if(!c_taus_byLooseIsolationDeltaBetaCorr_ && b_taus_byLooseIsolationDeltaBetaCorr_){
    b_taus_byLooseIsolationDeltaBetaCorr_->SetStatus(true);
    chainB_.SetBranchAddress("taus_byLooseIsolationDeltaBetaCorr", &taus_byLooseIsolationDeltaBetaCorr_, &b_taus_byLooseIsolationDeltaBetaCorr_);
    b_taus_byLooseIsolationDeltaBetaCorr_->GetEntry(entry_);
    c_taus_byLooseIsolationDeltaBetaCorr_ = true;
  }
  return taus_byLooseIsolationDeltaBetaCorr_;
}

std::vector<float>* const & cfa_base::taus_byMediumIsolation() const{
  if(!c_taus_byMediumIsolation_ && b_taus_byMediumIsolation_){
    b_taus_byMediumIsolation_->SetStatus(true);
    chainB_.SetBranchAddress("taus_byMediumIsolation", &taus_byMediumIsolation_, &b_taus_byMediumIsolation_);
    b_taus_byMediumIsolation_->GetEntry(entry_);
    c_taus_byMediumIsolation_ = true;
  }
  return taus_byMediumIsolation_;
}

std::vector<float>* const & cfa_base::taus_byMediumIsolationDeltaBetaCorr() const{
  if(!c_taus_byMediumIsolationDeltaBetaCorr_ && b_taus_byMediumIsolationDeltaBetaCorr_){
    b_taus_byMediumIsolationDeltaBetaCorr_->SetStatus(true);
    chainB_.SetBranchAddress("taus_byMediumIsolationDeltaBetaCorr", &taus_byMediumIsolationDeltaBetaCorr_, &b_taus_byMediumIsolationDeltaBetaCorr_);
    b_taus_byMediumIsolationDeltaBetaCorr_->GetEntry(entry_);
    c_taus_byMediumIsolationDeltaBetaCorr_ = true;
  }
  return taus_byMediumIsolationDeltaBetaCorr_;
}

std::vector<float>* const & cfa_base::taus_byTightIsolation() const{
  if(!c_taus_byTightIsolation_ && b_taus_byTightIsolation_){
    b_taus_byTightIsolation_->SetStatus(true);
    chainB_.SetBranchAddress("taus_byTightIsolation", &taus_byTightIsolation_, &b_taus_byTightIsolation_);
    b_taus_byTightIsolation_->GetEntry(entry_);
    c_taus_byTightIsolation_ = true;
  }
  return taus_byTightIsolation_;
}

std::vector<float>* const & cfa_base::taus_byTightIsolationDeltaBetaCorr() const{
  if(!c_taus_byTightIsolationDeltaBetaCorr_ && b_taus_byTightIsolationDeltaBetaCorr_){
    b_taus_byTightIsolationDeltaBetaCorr_->SetStatus(true);
    chainB_.SetBranchAddress("taus_byTightIsolationDeltaBetaCorr", &taus_byTightIsolationDeltaBetaCorr_, &b_taus_byTightIsolationDeltaBetaCorr_);
    b_taus_byTightIsolationDeltaBetaCorr_->GetEntry(entry_);
    c_taus_byTightIsolationDeltaBetaCorr_ = true;
  }
  return taus_byTightIsolationDeltaBetaCorr_;
}

std::vector<float>* const & cfa_base::taus_byVLooseIsolation() const{
  if(!c_taus_byVLooseIsolation_ && b_taus_byVLooseIsolation_){
    b_taus_byVLooseIsolation_->SetStatus(true);
    chainB_.SetBranchAddress("taus_byVLooseIsolation", &taus_byVLooseIsolation_, &b_taus_byVLooseIsolation_);
    b_taus_byVLooseIsolation_->GetEntry(entry_);
    c_taus_byVLooseIsolation_ = true;
  }
  return taus_byVLooseIsolation_;
}

std::vector<float>* const & cfa_base::taus_byVLooseIsolationDeltaBetaCorr() const{
  if(!c_taus_byVLooseIsolationDeltaBetaCorr_ && b_taus_byVLooseIsolationDeltaBetaCorr_){
    b_taus_byVLooseIsolationDeltaBetaCorr_->SetStatus(true);
    chainB_.SetBranchAddress("taus_byVLooseIsolationDeltaBetaCorr", &taus_byVLooseIsolationDeltaBetaCorr_, &b_taus_byVLooseIsolationDeltaBetaCorr_);
    b_taus_byVLooseIsolationDeltaBetaCorr_->GetEntry(entry_);
    c_taus_byVLooseIsolationDeltaBetaCorr_ = true;
  }
  return taus_byVLooseIsolationDeltaBetaCorr_;
}

std::vector<float>* const & cfa_base::taus_charge() const{
  if(!c_taus_charge_ && b_taus_charge_){
    b_taus_charge_->SetStatus(true);
    chainB_.SetBranchAddress("taus_charge", &taus_charge_, &b_taus_charge_);
    b_taus_charge_->GetEntry(entry_);
    c_taus_charge_ = true;
  }
  return taus_charge_;
}

std::vector<float>* const & cfa_base::taus_decayModeFinding() const{
  if(!c_taus_decayModeFinding_ && b_taus_decayModeFinding_){
    b_taus_decayModeFinding_->SetStatus(true);
    chainB_.SetBranchAddress("taus_decayModeFinding", &taus_decayModeFinding_, &b_taus_decayModeFinding_);
    b_taus_decayModeFinding_->GetEntry(entry_);
    c_taus_decayModeFinding_ = true;
  }
  return taus_decayModeFinding_;
}

std::vector<float>* const & cfa_base::taus_ecalIsoUsingLeadingPi() const{
  if(!c_taus_ecalIsoUsingLeadingPi_ && b_taus_ecalIsoUsingLeadingPi_){
    b_taus_ecalIsoUsingLeadingPi_->SetStatus(true);
    chainB_.SetBranchAddress("taus_ecalIsoUsingLeadingPi", &taus_ecalIsoUsingLeadingPi_, &b_taus_ecalIsoUsingLeadingPi_);
    b_taus_ecalIsoUsingLeadingPi_->GetEntry(entry_);
    c_taus_ecalIsoUsingLeadingPi_ = true;
  }
  return taus_ecalIsoUsingLeadingPi_;
}

std::vector<float>* const & cfa_base::taus_ecalIsolation() const{
  if(!c_taus_ecalIsolation_ && b_taus_ecalIsolation_){
    b_taus_ecalIsolation_->SetStatus(true);
    chainB_.SetBranchAddress("taus_ecalIsolation", &taus_ecalIsolation_, &b_taus_ecalIsolation_);
    b_taus_ecalIsolation_->GetEntry(entry_);
    c_taus_ecalIsolation_ = true;
  }
  return taus_ecalIsolation_;
}

std::vector<float>* const & cfa_base::taus_ecalStripSumEOverPLead() const{
  if(!c_taus_ecalStripSumEOverPLead_ && b_taus_ecalStripSumEOverPLead_){
    b_taus_ecalStripSumEOverPLead_->SetStatus(true);
    chainB_.SetBranchAddress("taus_ecalStripSumEOverPLead", &taus_ecalStripSumEOverPLead_, &b_taus_ecalStripSumEOverPLead_);
    b_taus_ecalStripSumEOverPLead_->GetEntry(entry_);
    c_taus_ecalStripSumEOverPLead_ = true;
  }
  return taus_ecalStripSumEOverPLead_;
}

std::vector<float>* const & cfa_base::taus_elecPreIdDecision() const{
  if(!c_taus_elecPreIdDecision_ && b_taus_elecPreIdDecision_){
    b_taus_elecPreIdDecision_->SetStatus(true);
    chainB_.SetBranchAddress("taus_elecPreIdDecision", &taus_elecPreIdDecision_, &b_taus_elecPreIdDecision_);
    b_taus_elecPreIdDecision_->GetEntry(entry_);
    c_taus_elecPreIdDecision_ = true;
  }
  return taus_elecPreIdDecision_;
}

std::vector<float>* const & cfa_base::taus_elecPreIdOutput() const{
  if(!c_taus_elecPreIdOutput_ && b_taus_elecPreIdOutput_){
    b_taus_elecPreIdOutput_->SetStatus(true);
    chainB_.SetBranchAddress("taus_elecPreIdOutput", &taus_elecPreIdOutput_, &b_taus_elecPreIdOutput_);
    b_taus_elecPreIdOutput_->GetEntry(entry_);
    c_taus_elecPreIdOutput_ = true;
  }
  return taus_elecPreIdOutput_;
}

std::vector<float>* const & cfa_base::taus_emf() const{
  if(!c_taus_emf_ && b_taus_emf_){
    b_taus_emf_->SetStatus(true);
    chainB_.SetBranchAddress("taus_emf", &taus_emf_, &b_taus_emf_);
    b_taus_emf_->GetEntry(entry_);
    c_taus_emf_ = true;
  }
  return taus_emf_;
}

std::vector<float>* const & cfa_base::taus_energy() const{
  if(!c_taus_energy_ && b_taus_energy_){
    b_taus_energy_->SetStatus(true);
    chainB_.SetBranchAddress("taus_energy", &taus_energy_, &b_taus_energy_);
    b_taus_energy_->GetEntry(entry_);
    c_taus_energy_ = true;
  }
  return taus_energy_;
}

std::vector<float>* const & cfa_base::taus_et() const{
  if(!c_taus_et_ && b_taus_et_){
    b_taus_et_->SetStatus(true);
    chainB_.SetBranchAddress("taus_et", &taus_et_, &b_taus_et_);
    b_taus_et_->GetEntry(entry_);
    c_taus_et_ = true;
  }
  return taus_et_;
}

std::vector<float>* const & cfa_base::taus_eta() const{
  if(!c_taus_eta_ && b_taus_eta_){
    b_taus_eta_->SetStatus(true);
    chainB_.SetBranchAddress("taus_eta", &taus_eta_, &b_taus_eta_);
    b_taus_eta_->GetEntry(entry_);
    c_taus_eta_ = true;
  }
  return taus_eta_;
}

std::vector<float>* const & cfa_base::taus_hcal3x3OverPLead() const{
  if(!c_taus_hcal3x3OverPLead_ && b_taus_hcal3x3OverPLead_){
    b_taus_hcal3x3OverPLead_->SetStatus(true);
    chainB_.SetBranchAddress("taus_hcal3x3OverPLead", &taus_hcal3x3OverPLead_, &b_taus_hcal3x3OverPLead_);
    b_taus_hcal3x3OverPLead_->GetEntry(entry_);
    c_taus_hcal3x3OverPLead_ = true;
  }
  return taus_hcal3x3OverPLead_;
}

std::vector<float>* const & cfa_base::taus_hcalMaxOverPLead() const{
  if(!c_taus_hcalMaxOverPLead_ && b_taus_hcalMaxOverPLead_){
    b_taus_hcalMaxOverPLead_->SetStatus(true);
    chainB_.SetBranchAddress("taus_hcalMaxOverPLead", &taus_hcalMaxOverPLead_, &b_taus_hcalMaxOverPLead_);
    b_taus_hcalMaxOverPLead_->GetEntry(entry_);
    c_taus_hcalMaxOverPLead_ = true;
  }
  return taus_hcalMaxOverPLead_;
}

std::vector<float>* const & cfa_base::taus_hcalTotOverPLead() const{
  if(!c_taus_hcalTotOverPLead_ && b_taus_hcalTotOverPLead_){
    b_taus_hcalTotOverPLead_->SetStatus(true);
    chainB_.SetBranchAddress("taus_hcalTotOverPLead", &taus_hcalTotOverPLead_, &b_taus_hcalTotOverPLead_);
    b_taus_hcalTotOverPLead_->GetEntry(entry_);
    c_taus_hcalTotOverPLead_ = true;
  }
  return taus_hcalTotOverPLead_;
}

std::vector<float>* const & cfa_base::taus_isoPFChargedHadrCandsPtSum() const{
  if(!c_taus_isoPFChargedHadrCandsPtSum_ && b_taus_isoPFChargedHadrCandsPtSum_){
    b_taus_isoPFChargedHadrCandsPtSum_->SetStatus(true);
    chainB_.SetBranchAddress("taus_isoPFChargedHadrCandsPtSum", &taus_isoPFChargedHadrCandsPtSum_, &b_taus_isoPFChargedHadrCandsPtSum_);
    b_taus_isoPFChargedHadrCandsPtSum_->GetEntry(entry_);
    c_taus_isoPFChargedHadrCandsPtSum_ = true;
  }
  return taus_isoPFChargedHadrCandsPtSum_;
}

std::vector<float>* const & cfa_base::taus_isoPFGammaCandsEtSum() const{
  if(!c_taus_isoPFGammaCandsEtSum_ && b_taus_isoPFGammaCandsEtSum_){
    b_taus_isoPFGammaCandsEtSum_->SetStatus(true);
    chainB_.SetBranchAddress("taus_isoPFGammaCandsEtSum", &taus_isoPFGammaCandsEtSum_, &b_taus_isoPFGammaCandsEtSum_);
    b_taus_isoPFGammaCandsEtSum_->GetEntry(entry_);
    c_taus_isoPFGammaCandsEtSum_ = true;
  }
  return taus_isoPFGammaCandsEtSum_;
}

std::vector<float>* const & cfa_base::taus_leadPFChargedHadrCand_ECAL_eta() const{
  if(!c_taus_leadPFChargedHadrCand_ECAL_eta_ && b_taus_leadPFChargedHadrCand_ECAL_eta_){
    b_taus_leadPFChargedHadrCand_ECAL_eta_->SetStatus(true);
    chainB_.SetBranchAddress("taus_leadPFChargedHadrCand_ECAL_eta", &taus_leadPFChargedHadrCand_ECAL_eta_, &b_taus_leadPFChargedHadrCand_ECAL_eta_);
    b_taus_leadPFChargedHadrCand_ECAL_eta_->GetEntry(entry_);
    c_taus_leadPFChargedHadrCand_ECAL_eta_ = true;
  }
  return taus_leadPFChargedHadrCand_ECAL_eta_;
}

std::vector<float>* const & cfa_base::taus_leadPFChargedHadrCand_charge() const{
  if(!c_taus_leadPFChargedHadrCand_charge_ && b_taus_leadPFChargedHadrCand_charge_){
    b_taus_leadPFChargedHadrCand_charge_->SetStatus(true);
    chainB_.SetBranchAddress("taus_leadPFChargedHadrCand_charge", &taus_leadPFChargedHadrCand_charge_, &b_taus_leadPFChargedHadrCand_charge_);
    b_taus_leadPFChargedHadrCand_charge_->GetEntry(entry_);
    c_taus_leadPFChargedHadrCand_charge_ = true;
  }
  return taus_leadPFChargedHadrCand_charge_;
}

std::vector<float>* const & cfa_base::taus_leadPFChargedHadrCand_eta() const{
  if(!c_taus_leadPFChargedHadrCand_eta_ && b_taus_leadPFChargedHadrCand_eta_){
    b_taus_leadPFChargedHadrCand_eta_->SetStatus(true);
    chainB_.SetBranchAddress("taus_leadPFChargedHadrCand_eta", &taus_leadPFChargedHadrCand_eta_, &b_taus_leadPFChargedHadrCand_eta_);
    b_taus_leadPFChargedHadrCand_eta_->GetEntry(entry_);
    c_taus_leadPFChargedHadrCand_eta_ = true;
  }
  return taus_leadPFChargedHadrCand_eta_;
}

std::vector<float>* const & cfa_base::taus_leadPFChargedHadrCand_phi() const{
  if(!c_taus_leadPFChargedHadrCand_phi_ && b_taus_leadPFChargedHadrCand_phi_){
    b_taus_leadPFChargedHadrCand_phi_->SetStatus(true);
    chainB_.SetBranchAddress("taus_leadPFChargedHadrCand_phi", &taus_leadPFChargedHadrCand_phi_, &b_taus_leadPFChargedHadrCand_phi_);
    b_taus_leadPFChargedHadrCand_phi_->GetEntry(entry_);
    c_taus_leadPFChargedHadrCand_phi_ = true;
  }
  return taus_leadPFChargedHadrCand_phi_;
}

std::vector<float>* const & cfa_base::taus_leadPFChargedHadrCand_pt() const{
  if(!c_taus_leadPFChargedHadrCand_pt_ && b_taus_leadPFChargedHadrCand_pt_){
    b_taus_leadPFChargedHadrCand_pt_->SetStatus(true);
    chainB_.SetBranchAddress("taus_leadPFChargedHadrCand_pt", &taus_leadPFChargedHadrCand_pt_, &b_taus_leadPFChargedHadrCand_pt_);
    b_taus_leadPFChargedHadrCand_pt_->GetEntry(entry_);
    c_taus_leadPFChargedHadrCand_pt_ = true;
  }
  return taus_leadPFChargedHadrCand_pt_;
}

std::vector<float>* const & cfa_base::taus_leadingTrackFinding() const{
  if(!c_taus_leadingTrackFinding_ && b_taus_leadingTrackFinding_){
    b_taus_leadingTrackFinding_->SetStatus(true);
    chainB_.SetBranchAddress("taus_leadingTrackFinding", &taus_leadingTrackFinding_, &b_taus_leadingTrackFinding_);
    b_taus_leadingTrackFinding_->GetEntry(entry_);
    c_taus_leadingTrackFinding_ = true;
  }
  return taus_leadingTrackFinding_;
}

std::vector<float>* const & cfa_base::taus_leadingTrackPtCut() const{
  if(!c_taus_leadingTrackPtCut_ && b_taus_leadingTrackPtCut_){
    b_taus_leadingTrackPtCut_->SetStatus(true);
    chainB_.SetBranchAddress("taus_leadingTrackPtCut", &taus_leadingTrackPtCut_, &b_taus_leadingTrackPtCut_);
    b_taus_leadingTrackPtCut_->GetEntry(entry_);
    c_taus_leadingTrackPtCut_ = true;
  }
  return taus_leadingTrackPtCut_;
}

std::vector<float>* const & cfa_base::taus_muDecision() const{
  if(!c_taus_muDecision_ && b_taus_muDecision_){
    b_taus_muDecision_->SetStatus(true);
    chainB_.SetBranchAddress("taus_muDecision", &taus_muDecision_, &b_taus_muDecision_);
    b_taus_muDecision_->GetEntry(entry_);
    c_taus_muDecision_ = true;
  }
  return taus_muDecision_;
}

std::vector<float>* const & cfa_base::taus_phi() const{
  if(!c_taus_phi_ && b_taus_phi_){
    b_taus_phi_->SetStatus(true);
    chainB_.SetBranchAddress("taus_phi", &taus_phi_, &b_taus_phi_);
    b_taus_phi_->GetEntry(entry_);
    c_taus_phi_ = true;
  }
  return taus_phi_;
}

std::vector<float>* const & cfa_base::taus_pt() const{
  if(!c_taus_pt_ && b_taus_pt_){
    b_taus_pt_->SetStatus(true);
    chainB_.SetBranchAddress("taus_pt", &taus_pt_, &b_taus_pt_);
    b_taus_pt_->GetEntry(entry_);
    c_taus_pt_ = true;
  }
  return taus_pt_;
}

std::vector<float>* const & cfa_base::taus_px() const{
  if(!c_taus_px_ && b_taus_px_){
    b_taus_px_->SetStatus(true);
    chainB_.SetBranchAddress("taus_px", &taus_px_, &b_taus_px_);
    b_taus_px_->GetEntry(entry_);
    c_taus_px_ = true;
  }
  return taus_px_;
}

std::vector<float>* const & cfa_base::taus_py() const{
  if(!c_taus_py_ && b_taus_py_){
    b_taus_py_->SetStatus(true);
    chainB_.SetBranchAddress("taus_py", &taus_py_, &b_taus_py_);
    b_taus_py_->GetEntry(entry_);
    c_taus_py_ = true;
  }
  return taus_py_;
}

std::vector<float>* const & cfa_base::taus_pz() const{
  if(!c_taus_pz_ && b_taus_pz_){
    b_taus_pz_->SetStatus(true);
    chainB_.SetBranchAddress("taus_pz", &taus_pz_, &b_taus_pz_);
    b_taus_pz_->GetEntry(entry_);
    c_taus_pz_ = true;
  }
  return taus_pz_;
}

std::vector<float>* const & cfa_base::taus_signalPFChargedHadrCandsSize() const{
  if(!c_taus_signalPFChargedHadrCandsSize_ && b_taus_signalPFChargedHadrCandsSize_){
    b_taus_signalPFChargedHadrCandsSize_->SetStatus(true);
    chainB_.SetBranchAddress("taus_signalPFChargedHadrCandsSize", &taus_signalPFChargedHadrCandsSize_, &b_taus_signalPFChargedHadrCandsSize_);
    b_taus_signalPFChargedHadrCandsSize_->GetEntry(entry_);
    c_taus_signalPFChargedHadrCandsSize_ = true;
  }
  return taus_signalPFChargedHadrCandsSize_;
}

std::vector<float>* const & cfa_base::taus_status() const{
  if(!c_taus_status_ && b_taus_status_){
    b_taus_status_->SetStatus(true);
    chainB_.SetBranchAddress("taus_status", &taus_status_, &b_taus_status_);
    b_taus_status_->GetEntry(entry_);
    c_taus_status_ = true;
  }
  return taus_status_;
}

std::vector<float>* const & cfa_base::taus_taNC() const{
  if(!c_taus_taNC_ && b_taus_taNC_){
    b_taus_taNC_->SetStatus(true);
    chainB_.SetBranchAddress("taus_taNC", &taus_taNC_, &b_taus_taNC_);
    b_taus_taNC_->GetEntry(entry_);
    c_taus_taNC_ = true;
  }
  return taus_taNC_;
}

std::vector<float>* const & cfa_base::taus_taNC_half() const{
  if(!c_taus_taNC_half_ && b_taus_taNC_half_){
    b_taus_taNC_half_->SetStatus(true);
    chainB_.SetBranchAddress("taus_taNC_half", &taus_taNC_half_, &b_taus_taNC_half_);
    b_taus_taNC_half_->GetEntry(entry_);
    c_taus_taNC_half_ = true;
  }
  return taus_taNC_half_;
}

std::vector<float>* const & cfa_base::taus_taNC_one() const{
  if(!c_taus_taNC_one_ && b_taus_taNC_one_){
    b_taus_taNC_one_->SetStatus(true);
    chainB_.SetBranchAddress("taus_taNC_one", &taus_taNC_one_, &b_taus_taNC_one_);
    b_taus_taNC_one_->GetEntry(entry_);
    c_taus_taNC_one_ = true;
  }
  return taus_taNC_one_;
}

std::vector<float>* const & cfa_base::taus_taNC_quarter() const{
  if(!c_taus_taNC_quarter_ && b_taus_taNC_quarter_){
    b_taus_taNC_quarter_->SetStatus(true);
    chainB_.SetBranchAddress("taus_taNC_quarter", &taus_taNC_quarter_, &b_taus_taNC_quarter_);
    b_taus_taNC_quarter_->GetEntry(entry_);
    c_taus_taNC_quarter_ = true;
  }
  return taus_taNC_quarter_;
}

std::vector<float>* const & cfa_base::taus_taNC_tenth() const{
  if(!c_taus_taNC_tenth_ && b_taus_taNC_tenth_){
    b_taus_taNC_tenth_->SetStatus(true);
    chainB_.SetBranchAddress("taus_taNC_tenth", &taus_taNC_tenth_, &b_taus_taNC_tenth_);
    b_taus_taNC_tenth_->GetEntry(entry_);
    c_taus_taNC_tenth_ = true;
  }
  return taus_taNC_tenth_;
}

std::vector<float>* const & cfa_base::taus_theta() const{
  if(!c_taus_theta_ && b_taus_theta_){
    b_taus_theta_->SetStatus(true);
    chainB_.SetBranchAddress("taus_theta", &taus_theta_, &b_taus_theta_);
    b_taus_theta_->GetEntry(entry_);
    c_taus_theta_ = true;
  }
  return taus_theta_;
}

std::vector<float>* const & cfa_base::taus_tkIsoUsingLeadingPi() const{
  if(!c_taus_tkIsoUsingLeadingPi_ && b_taus_tkIsoUsingLeadingPi_){
    b_taus_tkIsoUsingLeadingPi_->SetStatus(true);
    chainB_.SetBranchAddress("taus_tkIsoUsingLeadingPi", &taus_tkIsoUsingLeadingPi_, &b_taus_tkIsoUsingLeadingPi_);
    b_taus_tkIsoUsingLeadingPi_->GetEntry(entry_);
    c_taus_tkIsoUsingLeadingPi_ = true;
  }
  return taus_tkIsoUsingLeadingPi_;
}

std::vector<float>* const & cfa_base::taus_trackIsolation() const{
  if(!c_taus_trackIsolation_ && b_taus_trackIsolation_){
    b_taus_trackIsolation_->SetStatus(true);
    chainB_.SetBranchAddress("taus_trackIsolation", &taus_trackIsolation_, &b_taus_trackIsolation_);
    b_taus_trackIsolation_->GetEntry(entry_);
    c_taus_trackIsolation_ = true;
  }
  return taus_trackIsolation_;
}

Int_t const & cfa_base::trackingfailurefilter_decision() const{
  if(!c_trackingfailurefilter_decision_ && b_trackingfailurefilter_decision_){
    b_trackingfailurefilter_decision_->SetStatus(true);
    chainA_.SetBranchAddress("trackingfailurefilter_decision", &trackingfailurefilter_decision_, &b_trackingfailurefilter_decision_);
    b_trackingfailurefilter_decision_->GetEntry(entry_);
    c_trackingfailurefilter_decision_ = true;
  }
  return trackingfailurefilter_decision_;
}

std::vector<std::string>* const & cfa_base::trigger_name() const{
  if(!c_trigger_name_ && b_trigger_name_){
    b_trigger_name_->SetStatus(true);
    chainA_.SetBranchAddress("trigger_name", &trigger_name_, &b_trigger_name_);
    b_trigger_name_->GetEntry(entry_);
    c_trigger_name_ = true;
  }
  return trigger_name_;
}

std::vector<float>* const & cfa_base::trigger_prescalevalue() const{
  if(!c_trigger_prescalevalue_ && b_trigger_prescalevalue_){
    b_trigger_prescalevalue_->SetStatus(true);
    chainA_.SetBranchAddress("trigger_prescalevalue", &trigger_prescalevalue_, &b_trigger_prescalevalue_);
    b_trigger_prescalevalue_->GetEntry(entry_);
    c_trigger_prescalevalue_ = true;
  }
  return trigger_prescalevalue_;
}

Float_t const & cfa_base::weight() const{
  if(!c_weight_ && b_weight_){
    b_weight_->SetStatus(true);
    chainB_.SetBranchAddress("weight", &weight_, &b_weight_);
    b_weight_->GetEntry(entry_);
    c_weight_ = true;
  }
  return weight_;
}

Int_t const & cfa_base::EcalDeadCellTriggerPrimitivefilter_decision() const{
  throw std::runtime_error("EcalDeadCellTriggerPrimitivefilter_decision does not exist in this cfA version.");
}

Int_t const & cfa_base::HBHENoisefilter_decision() const{
  throw std::runtime_error("HBHENoisefilter_decision does not exist in this cfA version.");
}

std::vector<std::string>* const & cfa_base::L1trigger_alias() const{
  throw std::runtime_error("L1trigger_alias does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::L1trigger_bit() const{
  throw std::runtime_error("L1trigger_bit does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::L1trigger_decision() const{
  throw std::runtime_error("L1trigger_decision does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::L1trigger_decision_nomask() const{
  throw std::runtime_error("L1trigger_decision_nomask does not exist in this cfA version.");
}

std::vector<std::string>* const & cfa_base::L1trigger_name() const{
  throw std::runtime_error("L1trigger_name does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::L1trigger_prescalevalue() const{
  throw std::runtime_error("L1trigger_prescalevalue does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::L1trigger_techTrigger() const{
  throw std::runtime_error("L1trigger_techTrigger does not exist in this cfA version.");
}

Int_t const & cfa_base::METFiltersfilter_decision() const{
  throw std::runtime_error("METFiltersfilter_decision does not exist in this cfA version.");
}

Float_t const & cfa_base::MPT() const{
  throw std::runtime_error("MPT does not exist in this cfA version.");
}

UInt_t const & cfa_base::Njets_AK4() const{
  throw std::runtime_error("Njets_AK4 does not exist in this cfA version.");
}

UInt_t const & cfa_base::Njets_AK5PF() const{
  throw std::runtime_error("Njets_AK5PF does not exist in this cfA version.");
}

UInt_t const & cfa_base::Njets_AK5PFclean() const{
  throw std::runtime_error("Njets_AK5PFclean does not exist in this cfA version.");
}

UInt_t const & cfa_base::Nmc_final() const{
  throw std::runtime_error("Nmc_final does not exist in this cfA version.");
}

UInt_t const & cfa_base::Nmc_jets() const{
  throw std::runtime_error("Nmc_jets does not exist in this cfA version.");
}

UInt_t const & cfa_base::Nmc_pdf() const{
  throw std::runtime_error("Nmc_pdf does not exist in this cfA version.");
}

UInt_t const & cfa_base::Nmets() const{
  throw std::runtime_error("Nmets does not exist in this cfA version.");
}

UInt_t const & cfa_base::NmetsHO() const{
  throw std::runtime_error("NmetsHO does not exist in this cfA version.");
}

UInt_t const & cfa_base::Nmets_AK5() const{
  throw std::runtime_error("Nmets_AK5 does not exist in this cfA version.");
}

UInt_t const & cfa_base::NpfTypeINoXYCorrmets() const{
  throw std::runtime_error("NpfTypeINoXYCorrmets does not exist in this cfA version.");
}

UInt_t const & cfa_base::NpfTypeIType0mets() const{
  throw std::runtime_error("NpfTypeIType0mets does not exist in this cfA version.");
}

UInt_t const & cfa_base::NpfTypeImets() const{
  throw std::runtime_error("NpfTypeImets does not exist in this cfA version.");
}

UInt_t const & cfa_base::Npf_els() const{
  throw std::runtime_error("Npf_els does not exist in this cfA version.");
}

UInt_t const & cfa_base::Npf_mus() const{
  throw std::runtime_error("Npf_mus does not exist in this cfA version.");
}

UInt_t const & cfa_base::Npf_photons() const{
  throw std::runtime_error("Npf_photons does not exist in this cfA version.");
}

UInt_t const & cfa_base::Npfmets() const{
  throw std::runtime_error("Npfmets does not exist in this cfA version.");
}

UInt_t const & cfa_base::Ntcmets() const{
  throw std::runtime_error("Ntcmets does not exist in this cfA version.");
}

UInt_t const & cfa_base::Ntracks() const{
  throw std::runtime_error("Ntracks does not exist in this cfA version.");
}

Int_t const & cfa_base::ecalBEfilter_decision() const{
  throw std::runtime_error("ecalBEfilter_decision does not exist in this cfA version.");
}

Int_t const & cfa_base::ecalTPfilter_decision() const{
  throw std::runtime_error("ecalTPfilter_decision does not exist in this cfA version.");
}

Int_t const & cfa_base::eenoisefilter_decision() const{
  throw std::runtime_error("eenoisefilter_decision does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::els_PFchargedHadronIsoR03() const{
  throw std::runtime_error("els_PFchargedHadronIsoR03 does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::els_PFneutralHadronIsoR03() const{
  throw std::runtime_error("els_PFneutralHadronIsoR03 does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::els_PFphotonIsoR03() const{
  throw std::runtime_error("els_PFphotonIsoR03 does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::els_conversion_dcot() const{
  throw std::runtime_error("els_conversion_dcot does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::els_conversion_dist() const{
  throw std::runtime_error("els_conversion_dist does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::els_full5x5_sigmaIetaIeta() const{
  throw std::runtime_error("els_full5x5_sigmaIetaIeta does not exist in this cfA version.");
}

std::vector<bool>* const & cfa_base::els_hasMatchedConversion() const{
  throw std::runtime_error("els_hasMatchedConversion does not exist in this cfA version.");
}

std::vector<bool>* const & cfa_base::els_isPF() const{
  throw std::runtime_error("els_isPF does not exist in this cfA version.");
}

std::vector<int>* const & cfa_base::els_jet_ind() const{
  throw std::runtime_error("els_jet_ind does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::els_pfIsolationR03_sumChargedHadronPt() const{
  throw std::runtime_error("els_pfIsolationR03_sumChargedHadronPt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::els_pfIsolationR03_sumNeutralHadronEt() const{
  throw std::runtime_error("els_pfIsolationR03_sumNeutralHadronEt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::els_pfIsolationR03_sumPUPt() const{
  throw std::runtime_error("els_pfIsolationR03_sumPUPt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::els_pfIsolationR03_sumPhotonEt() const{
  throw std::runtime_error("els_pfIsolationR03_sumPhotonEt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT10_energy() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT10_energy does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT10_eta() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT10_eta does not exist in this cfA version.");
}

std::vector<std::vector<int> >* const & cfa_base::fastjets_AK4_R1p2_R0p5pT10_index() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT10_index does not exist in this cfA version.");
}

std::vector<int>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT10_nconstituents() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT10_nconstituents does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT10_phi() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT10_phi does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT10_px() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT10_px does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT10_py() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT10_py does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT10_pz() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT10_pz does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT15_energy() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT15_energy does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT15_eta() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT15_eta does not exist in this cfA version.");
}

std::vector<std::vector<int> >* const & cfa_base::fastjets_AK4_R1p2_R0p5pT15_index() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT15_index does not exist in this cfA version.");
}

std::vector<int>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT15_nconstituents() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT15_nconstituents does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT15_phi() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT15_phi does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT15_px() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT15_px does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT15_py() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT15_py does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT15_pz() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT15_pz does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT20_energy() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT20_energy does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT20_eta() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT20_eta does not exist in this cfA version.");
}

std::vector<std::vector<int> >* const & cfa_base::fastjets_AK4_R1p2_R0p5pT20_index() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT20_index does not exist in this cfA version.");
}

std::vector<int>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT20_nconstituents() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT20_nconstituents does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT20_phi() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT20_phi does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT20_px() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT20_px does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT20_py() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT20_py does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT20_pz() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT20_pz does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT25_energy() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT25_energy does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT25_eta() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT25_eta does not exist in this cfA version.");
}

std::vector<std::vector<int> >* const & cfa_base::fastjets_AK4_R1p2_R0p5pT25_index() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT25_index does not exist in this cfA version.");
}

std::vector<int>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT25_nconstituents() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT25_nconstituents does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT25_phi() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT25_phi does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT25_px() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT25_px does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT25_py() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT25_py does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT25_pz() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT25_pz does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT30_energy() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT30_energy does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT30_eta() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT30_eta does not exist in this cfA version.");
}

std::vector<std::vector<int> >* const & cfa_base::fastjets_AK4_R1p2_R0p5pT30_index() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT30_index does not exist in this cfA version.");
}

std::vector<int>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT30_nconstituents() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT30_nconstituents does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT30_phi() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT30_phi does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT30_px() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT30_px does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT30_py() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT30_py does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::fastjets_AK4_R1p2_R0p5pT30_pz() const{
  throw std::runtime_error("fastjets_AK4_R1p2_R0p5pT30_pz does not exist in this cfA version.");
}

Float_t const & cfa_base::genHT() const{
  throw std::runtime_error("genHT does not exist in this cfA version.");
}

Int_t const & cfa_base::goodVerticesfilter_decision() const{
  throw std::runtime_error("goodVerticesfilter_decision does not exist in this cfA version.");
}

Int_t const & cfa_base::greedymuonfilter_decision() const{
  throw std::runtime_error("greedymuonfilter_decision does not exist in this cfA version.");
}

Int_t const & cfa_base::hbhefilter_decision() const{
  throw std::runtime_error("hbhefilter_decision does not exist in this cfA version.");
}

Int_t const & cfa_base::inconsistentPFmuonfilter_decision() const{
  throw std::runtime_error("inconsistentPFmuonfilter_decision does not exist in this cfA version.");
}

std::vector<int>* const & cfa_base::isotk_charge() const{
  throw std::runtime_error("isotk_charge does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::isotk_dzpv() const{
  throw std::runtime_error("isotk_dzpv does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::isotk_eta() const{
  throw std::runtime_error("isotk_eta does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::isotk_iso() const{
  throw std::runtime_error("isotk_iso does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::isotk_phi() const{
  throw std::runtime_error("isotk_phi does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::isotk_pt() const{
  throw std::runtime_error("isotk_pt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_area() const{
  throw std::runtime_error("jets_AK4_area does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_btag_TC_highEff() const{
  throw std::runtime_error("jets_AK4_btag_TC_highEff does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_btag_TC_highPur() const{
  throw std::runtime_error("jets_AK4_btag_TC_highPur does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_btag_jetBProb() const{
  throw std::runtime_error("jets_AK4_btag_jetBProb does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_btag_jetProb() const{
  throw std::runtime_error("jets_AK4_btag_jetProb does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_btag_secVertexCombined() const{
  throw std::runtime_error("jets_AK4_btag_secVertexCombined does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_btag_secVertexHighEff() const{
  throw std::runtime_error("jets_AK4_btag_secVertexHighEff does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_btag_secVertexHighPur() const{
  throw std::runtime_error("jets_AK4_btag_secVertexHighPur does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_btag_softEle() const{
  throw std::runtime_error("jets_AK4_btag_softEle does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_btag_softMuon() const{
  throw std::runtime_error("jets_AK4_btag_softMuon does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_chgEmE() const{
  throw std::runtime_error("jets_AK4_chgEmE does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_chgHadE() const{
  throw std::runtime_error("jets_AK4_chgHadE does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_chgMuE() const{
  throw std::runtime_error("jets_AK4_chgMuE does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_chg_Mult() const{
  throw std::runtime_error("jets_AK4_chg_Mult does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_corrFactorRaw() const{
  throw std::runtime_error("jets_AK4_corrFactorRaw does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_ehf() const{
  throw std::runtime_error("jets_AK4_ehf does not exist in this cfA version.");
}

std::vector<int>* const & cfa_base::jets_AK4_el_ind() const{
  throw std::runtime_error("jets_AK4_el_ind does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_emf() const{
  throw std::runtime_error("jets_AK4_emf does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_energy() const{
  throw std::runtime_error("jets_AK4_energy does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_et() const{
  throw std::runtime_error("jets_AK4_et does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_eta() const{
  throw std::runtime_error("jets_AK4_eta does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_etaetaMoment() const{
  throw std::runtime_error("jets_AK4_etaetaMoment does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_etaphiMoment() const{
  throw std::runtime_error("jets_AK4_etaphiMoment does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_fHPD() const{
  throw std::runtime_error("jets_AK4_fHPD does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_fRBX() const{
  throw std::runtime_error("jets_AK4_fRBX does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_fSubDetector1() const{
  throw std::runtime_error("jets_AK4_fSubDetector1 does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_fSubDetector2() const{
  throw std::runtime_error("jets_AK4_fSubDetector2 does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_fSubDetector3() const{
  throw std::runtime_error("jets_AK4_fSubDetector3 does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_fSubDetector4() const{
  throw std::runtime_error("jets_AK4_fSubDetector4 does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_gen_Energy() const{
  throw std::runtime_error("jets_AK4_gen_Energy does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_gen_Id() const{
  throw std::runtime_error("jets_AK4_gen_Id does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_gen_et() const{
  throw std::runtime_error("jets_AK4_gen_et does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_gen_eta() const{
  throw std::runtime_error("jets_AK4_gen_eta does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_gen_mass() const{
  throw std::runtime_error("jets_AK4_gen_mass does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_gen_motherID() const{
  throw std::runtime_error("jets_AK4_gen_motherID does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_gen_phi() const{
  throw std::runtime_error("jets_AK4_gen_phi does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_gen_pt() const{
  throw std::runtime_error("jets_AK4_gen_pt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_gen_threeCharge() const{
  throw std::runtime_error("jets_AK4_gen_threeCharge does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_hitsInN90() const{
  throw std::runtime_error("jets_AK4_hitsInN90 does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_jetCharge() const{
  throw std::runtime_error("jets_AK4_jetCharge does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_mass() const{
  throw std::runtime_error("jets_AK4_mass does not exist in this cfA version.");
}

std::vector<int>* const & cfa_base::jets_AK4_maxpt_id() const{
  throw std::runtime_error("jets_AK4_maxpt_id does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_mu_Mult() const{
  throw std::runtime_error("jets_AK4_mu_Mult does not exist in this cfA version.");
}

std::vector<int>* const & cfa_base::jets_AK4_mu_ind() const{
  throw std::runtime_error("jets_AK4_mu_ind does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_n60() const{
  throw std::runtime_error("jets_AK4_n60 does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_n90() const{
  throw std::runtime_error("jets_AK4_n90 does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_n90Hits() const{
  throw std::runtime_error("jets_AK4_n90Hits does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_nECALTowers() const{
  throw std::runtime_error("jets_AK4_nECALTowers does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_nHCALTowers() const{
  throw std::runtime_error("jets_AK4_nHCALTowers does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_neutralEmE() const{
  throw std::runtime_error("jets_AK4_neutralEmE does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_neutralHadE() const{
  throw std::runtime_error("jets_AK4_neutralHadE does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_neutral_Mult() const{
  throw std::runtime_error("jets_AK4_neutral_Mult does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_partonFlavour() const{
  throw std::runtime_error("jets_AK4_partonFlavour does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_parton_Energy() const{
  throw std::runtime_error("jets_AK4_parton_Energy does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_parton_Id() const{
  throw std::runtime_error("jets_AK4_parton_Id does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_parton_eta() const{
  throw std::runtime_error("jets_AK4_parton_eta does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_parton_mass() const{
  throw std::runtime_error("jets_AK4_parton_mass does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_parton_motherId() const{
  throw std::runtime_error("jets_AK4_parton_motherId does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_parton_phi() const{
  throw std::runtime_error("jets_AK4_parton_phi does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_parton_pt() const{
  throw std::runtime_error("jets_AK4_parton_pt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_phi() const{
  throw std::runtime_error("jets_AK4_phi does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_phiphiMoment() const{
  throw std::runtime_error("jets_AK4_phiphiMoment does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_photonEnergy() const{
  throw std::runtime_error("jets_AK4_photonEnergy does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_pt() const{
  throw std::runtime_error("jets_AK4_pt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_px() const{
  throw std::runtime_error("jets_AK4_px does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_py() const{
  throw std::runtime_error("jets_AK4_py does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_pz() const{
  throw std::runtime_error("jets_AK4_pz does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_rawPt() const{
  throw std::runtime_error("jets_AK4_rawPt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_status() const{
  throw std::runtime_error("jets_AK4_status does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK4_theta() const{
  throw std::runtime_error("jets_AK4_theta does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_area() const{
  throw std::runtime_error("jets_AK5PF_area does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_btag_TC_highEff() const{
  throw std::runtime_error("jets_AK5PF_btag_TC_highEff does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_btag_TC_highPur() const{
  throw std::runtime_error("jets_AK5PF_btag_TC_highPur does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_btag_jetBProb() const{
  throw std::runtime_error("jets_AK5PF_btag_jetBProb does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_btag_jetProb() const{
  throw std::runtime_error("jets_AK5PF_btag_jetProb does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_btag_secVertexCombined() const{
  throw std::runtime_error("jets_AK5PF_btag_secVertexCombined does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_btag_secVertexHighEff() const{
  throw std::runtime_error("jets_AK5PF_btag_secVertexHighEff does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_btag_secVertexHighPur() const{
  throw std::runtime_error("jets_AK5PF_btag_secVertexHighPur does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_btag_softEle() const{
  throw std::runtime_error("jets_AK5PF_btag_softEle does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_btag_softMuon() const{
  throw std::runtime_error("jets_AK5PF_btag_softMuon does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_chgEmE() const{
  throw std::runtime_error("jets_AK5PF_chgEmE does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_chgHadE() const{
  throw std::runtime_error("jets_AK5PF_chgHadE does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_chgMuE() const{
  throw std::runtime_error("jets_AK5PF_chgMuE does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_chg_Mult() const{
  throw std::runtime_error("jets_AK5PF_chg_Mult does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_corrFactorRaw() const{
  throw std::runtime_error("jets_AK5PF_corrFactorRaw does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_ehf() const{
  throw std::runtime_error("jets_AK5PF_ehf does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_emf() const{
  throw std::runtime_error("jets_AK5PF_emf does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_energy() const{
  throw std::runtime_error("jets_AK5PF_energy does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_et() const{
  throw std::runtime_error("jets_AK5PF_et does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_eta() const{
  throw std::runtime_error("jets_AK5PF_eta does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_etaetaMoment() const{
  throw std::runtime_error("jets_AK5PF_etaetaMoment does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_etaphiMoment() const{
  throw std::runtime_error("jets_AK5PF_etaphiMoment does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_fHPD() const{
  throw std::runtime_error("jets_AK5PF_fHPD does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_fRBX() const{
  throw std::runtime_error("jets_AK5PF_fRBX does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_fSubDetector1() const{
  throw std::runtime_error("jets_AK5PF_fSubDetector1 does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_fSubDetector2() const{
  throw std::runtime_error("jets_AK5PF_fSubDetector2 does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_fSubDetector3() const{
  throw std::runtime_error("jets_AK5PF_fSubDetector3 does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_fSubDetector4() const{
  throw std::runtime_error("jets_AK5PF_fSubDetector4 does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_gen_Energy() const{
  throw std::runtime_error("jets_AK5PF_gen_Energy does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_gen_Id() const{
  throw std::runtime_error("jets_AK5PF_gen_Id does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_gen_et() const{
  throw std::runtime_error("jets_AK5PF_gen_et does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_gen_eta() const{
  throw std::runtime_error("jets_AK5PF_gen_eta does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_gen_mass() const{
  throw std::runtime_error("jets_AK5PF_gen_mass does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_gen_motherID() const{
  throw std::runtime_error("jets_AK5PF_gen_motherID does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_gen_phi() const{
  throw std::runtime_error("jets_AK5PF_gen_phi does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_gen_pt() const{
  throw std::runtime_error("jets_AK5PF_gen_pt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_gen_threeCharge() const{
  throw std::runtime_error("jets_AK5PF_gen_threeCharge does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_hitsInN90() const{
  throw std::runtime_error("jets_AK5PF_hitsInN90 does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_jetCharge() const{
  throw std::runtime_error("jets_AK5PF_jetCharge does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_mass() const{
  throw std::runtime_error("jets_AK5PF_mass does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_mu_Mult() const{
  throw std::runtime_error("jets_AK5PF_mu_Mult does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_n60() const{
  throw std::runtime_error("jets_AK5PF_n60 does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_n90() const{
  throw std::runtime_error("jets_AK5PF_n90 does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_n90Hits() const{
  throw std::runtime_error("jets_AK5PF_n90Hits does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_nECALTowers() const{
  throw std::runtime_error("jets_AK5PF_nECALTowers does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_nHCALTowers() const{
  throw std::runtime_error("jets_AK5PF_nHCALTowers does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_neutralEmE() const{
  throw std::runtime_error("jets_AK5PF_neutralEmE does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_neutralHadE() const{
  throw std::runtime_error("jets_AK5PF_neutralHadE does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_neutral_Mult() const{
  throw std::runtime_error("jets_AK5PF_neutral_Mult does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_partonFlavour() const{
  throw std::runtime_error("jets_AK5PF_partonFlavour does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_parton_Energy() const{
  throw std::runtime_error("jets_AK5PF_parton_Energy does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_parton_Id() const{
  throw std::runtime_error("jets_AK5PF_parton_Id does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_parton_eta() const{
  throw std::runtime_error("jets_AK5PF_parton_eta does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_parton_mass() const{
  throw std::runtime_error("jets_AK5PF_parton_mass does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_parton_motherId() const{
  throw std::runtime_error("jets_AK5PF_parton_motherId does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_parton_phi() const{
  throw std::runtime_error("jets_AK5PF_parton_phi does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_parton_pt() const{
  throw std::runtime_error("jets_AK5PF_parton_pt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_phi() const{
  throw std::runtime_error("jets_AK5PF_phi does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_phiphiMoment() const{
  throw std::runtime_error("jets_AK5PF_phiphiMoment does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_photonEnergy() const{
  throw std::runtime_error("jets_AK5PF_photonEnergy does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_pt() const{
  throw std::runtime_error("jets_AK5PF_pt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_px() const{
  throw std::runtime_error("jets_AK5PF_px does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_py() const{
  throw std::runtime_error("jets_AK5PF_py does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_pz() const{
  throw std::runtime_error("jets_AK5PF_pz does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_rawPt() const{
  throw std::runtime_error("jets_AK5PF_rawPt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_status() const{
  throw std::runtime_error("jets_AK5PF_status does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PF_theta() const{
  throw std::runtime_error("jets_AK5PF_theta does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_Uncert() const{
  throw std::runtime_error("jets_AK5PFclean_Uncert does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_area() const{
  throw std::runtime_error("jets_AK5PFclean_area does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_btag_TC_highEff() const{
  throw std::runtime_error("jets_AK5PFclean_btag_TC_highEff does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_btag_TC_highPur() const{
  throw std::runtime_error("jets_AK5PFclean_btag_TC_highPur does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_btag_jetBProb() const{
  throw std::runtime_error("jets_AK5PFclean_btag_jetBProb does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_btag_jetProb() const{
  throw std::runtime_error("jets_AK5PFclean_btag_jetProb does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_btag_secVertexCombined() const{
  throw std::runtime_error("jets_AK5PFclean_btag_secVertexCombined does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_btag_secVertexHighEff() const{
  throw std::runtime_error("jets_AK5PFclean_btag_secVertexHighEff does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_btag_secVertexHighPur() const{
  throw std::runtime_error("jets_AK5PFclean_btag_secVertexHighPur does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_btag_softEle() const{
  throw std::runtime_error("jets_AK5PFclean_btag_softEle does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_btag_softMuon() const{
  throw std::runtime_error("jets_AK5PFclean_btag_softMuon does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_chgEmE() const{
  throw std::runtime_error("jets_AK5PFclean_chgEmE does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_chgHadE() const{
  throw std::runtime_error("jets_AK5PFclean_chgHadE does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_chgMuE() const{
  throw std::runtime_error("jets_AK5PFclean_chgMuE does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_chg_Mult() const{
  throw std::runtime_error("jets_AK5PFclean_chg_Mult does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_corrFactorRaw() const{
  throw std::runtime_error("jets_AK5PFclean_corrFactorRaw does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_corrL1FastL2L3() const{
  throw std::runtime_error("jets_AK5PFclean_corrL1FastL2L3 does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_corrL1FastL2L3Residual() const{
  throw std::runtime_error("jets_AK5PFclean_corrL1FastL2L3Residual does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_corrL1L2L3() const{
  throw std::runtime_error("jets_AK5PFclean_corrL1L2L3 does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_corrL1L2L3Residual() const{
  throw std::runtime_error("jets_AK5PFclean_corrL1L2L3Residual does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_corrL2L3() const{
  throw std::runtime_error("jets_AK5PFclean_corrL2L3 does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_corrL2L3Residual() const{
  throw std::runtime_error("jets_AK5PFclean_corrL2L3Residual does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_ehf() const{
  throw std::runtime_error("jets_AK5PFclean_ehf does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_emf() const{
  throw std::runtime_error("jets_AK5PFclean_emf does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_energy() const{
  throw std::runtime_error("jets_AK5PFclean_energy does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_et() const{
  throw std::runtime_error("jets_AK5PFclean_et does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_eta() const{
  throw std::runtime_error("jets_AK5PFclean_eta does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_etaetaMoment() const{
  throw std::runtime_error("jets_AK5PFclean_etaetaMoment does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_etaphiMoment() const{
  throw std::runtime_error("jets_AK5PFclean_etaphiMoment does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_fHPD() const{
  throw std::runtime_error("jets_AK5PFclean_fHPD does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_fRBX() const{
  throw std::runtime_error("jets_AK5PFclean_fRBX does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_fSubDetector1() const{
  throw std::runtime_error("jets_AK5PFclean_fSubDetector1 does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_fSubDetector2() const{
  throw std::runtime_error("jets_AK5PFclean_fSubDetector2 does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_fSubDetector3() const{
  throw std::runtime_error("jets_AK5PFclean_fSubDetector3 does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_fSubDetector4() const{
  throw std::runtime_error("jets_AK5PFclean_fSubDetector4 does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_gen_Energy() const{
  throw std::runtime_error("jets_AK5PFclean_gen_Energy does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_gen_Id() const{
  throw std::runtime_error("jets_AK5PFclean_gen_Id does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_gen_et() const{
  throw std::runtime_error("jets_AK5PFclean_gen_et does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_gen_eta() const{
  throw std::runtime_error("jets_AK5PFclean_gen_eta does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_gen_mass() const{
  throw std::runtime_error("jets_AK5PFclean_gen_mass does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_gen_phi() const{
  throw std::runtime_error("jets_AK5PFclean_gen_phi does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_gen_pt() const{
  throw std::runtime_error("jets_AK5PFclean_gen_pt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_hitsInN90() const{
  throw std::runtime_error("jets_AK5PFclean_hitsInN90 does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_jetCharge() const{
  throw std::runtime_error("jets_AK5PFclean_jetCharge does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_mass() const{
  throw std::runtime_error("jets_AK5PFclean_mass does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_mu_Mult() const{
  throw std::runtime_error("jets_AK5PFclean_mu_Mult does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_n60() const{
  throw std::runtime_error("jets_AK5PFclean_n60 does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_n90() const{
  throw std::runtime_error("jets_AK5PFclean_n90 does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_n90Hits() const{
  throw std::runtime_error("jets_AK5PFclean_n90Hits does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_nECALTowers() const{
  throw std::runtime_error("jets_AK5PFclean_nECALTowers does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_nHCALTowers() const{
  throw std::runtime_error("jets_AK5PFclean_nHCALTowers does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_neutralEmE() const{
  throw std::runtime_error("jets_AK5PFclean_neutralEmE does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_neutralHadE() const{
  throw std::runtime_error("jets_AK5PFclean_neutralHadE does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_neutral_Mult() const{
  throw std::runtime_error("jets_AK5PFclean_neutral_Mult does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_partonFlavour() const{
  throw std::runtime_error("jets_AK5PFclean_partonFlavour does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_parton_Energy() const{
  throw std::runtime_error("jets_AK5PFclean_parton_Energy does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_parton_Id() const{
  throw std::runtime_error("jets_AK5PFclean_parton_Id does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_parton_eta() const{
  throw std::runtime_error("jets_AK5PFclean_parton_eta does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_parton_mass() const{
  throw std::runtime_error("jets_AK5PFclean_parton_mass does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_parton_motherId() const{
  throw std::runtime_error("jets_AK5PFclean_parton_motherId does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_parton_phi() const{
  throw std::runtime_error("jets_AK5PFclean_parton_phi does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_parton_pt() const{
  throw std::runtime_error("jets_AK5PFclean_parton_pt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_phi() const{
  throw std::runtime_error("jets_AK5PFclean_phi does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_phiphiMoment() const{
  throw std::runtime_error("jets_AK5PFclean_phiphiMoment does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_photonEnergy() const{
  throw std::runtime_error("jets_AK5PFclean_photonEnergy does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_pt() const{
  throw std::runtime_error("jets_AK5PFclean_pt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_px() const{
  throw std::runtime_error("jets_AK5PFclean_px does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_py() const{
  throw std::runtime_error("jets_AK5PFclean_py does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_pz() const{
  throw std::runtime_error("jets_AK5PFclean_pz does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_rawPt() const{
  throw std::runtime_error("jets_AK5PFclean_rawPt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_status() const{
  throw std::runtime_error("jets_AK5PFclean_status does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::jets_AK5PFclean_theta() const{
  throw std::runtime_error("jets_AK5PFclean_theta does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mc_final_charge() const{
  throw std::runtime_error("mc_final_charge does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mc_final_energy() const{
  throw std::runtime_error("mc_final_energy does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mc_final_eta() const{
  throw std::runtime_error("mc_final_eta does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mc_final_ggrandmother_id() const{
  throw std::runtime_error("mc_final_ggrandmother_id does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mc_final_grandmother_id() const{
  throw std::runtime_error("mc_final_grandmother_id does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mc_final_id() const{
  throw std::runtime_error("mc_final_id does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mc_final_mass() const{
  throw std::runtime_error("mc_final_mass does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mc_final_mother_id() const{
  throw std::runtime_error("mc_final_mother_id does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mc_final_mother_pt() const{
  throw std::runtime_error("mc_final_mother_pt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mc_final_numOfDaughters() const{
  throw std::runtime_error("mc_final_numOfDaughters does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mc_final_numOfMothers() const{
  throw std::runtime_error("mc_final_numOfMothers does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mc_final_phi() const{
  throw std::runtime_error("mc_final_phi does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mc_final_pt() const{
  throw std::runtime_error("mc_final_pt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mc_final_px() const{
  throw std::runtime_error("mc_final_px does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mc_final_py() const{
  throw std::runtime_error("mc_final_py does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mc_final_pz() const{
  throw std::runtime_error("mc_final_pz does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mc_final_status() const{
  throw std::runtime_error("mc_final_status does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mc_final_theta() const{
  throw std::runtime_error("mc_final_theta does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mc_final_vertex_x() const{
  throw std::runtime_error("mc_final_vertex_x does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mc_final_vertex_y() const{
  throw std::runtime_error("mc_final_vertex_y does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mc_final_vertex_z() const{
  throw std::runtime_error("mc_final_vertex_z does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mc_jets_auxiliaryEnergy() const{
  throw std::runtime_error("mc_jets_auxiliaryEnergy does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mc_jets_emEnergy() const{
  throw std::runtime_error("mc_jets_emEnergy does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mc_jets_energy() const{
  throw std::runtime_error("mc_jets_energy does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mc_jets_et() const{
  throw std::runtime_error("mc_jets_et does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mc_jets_eta() const{
  throw std::runtime_error("mc_jets_eta does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mc_jets_etaetaMoment() const{
  throw std::runtime_error("mc_jets_etaetaMoment does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mc_jets_etaphiMoment() const{
  throw std::runtime_error("mc_jets_etaphiMoment does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mc_jets_hadEnergy() const{
  throw std::runtime_error("mc_jets_hadEnergy does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mc_jets_invisibleEnergy() const{
  throw std::runtime_error("mc_jets_invisibleEnergy does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mc_jets_mass() const{
  throw std::runtime_error("mc_jets_mass does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mc_jets_phi() const{
  throw std::runtime_error("mc_jets_phi does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mc_jets_phiphiMoment() const{
  throw std::runtime_error("mc_jets_phiphiMoment does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mc_jets_pt() const{
  throw std::runtime_error("mc_jets_pt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mc_jets_px() const{
  throw std::runtime_error("mc_jets_px does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mc_jets_py() const{
  throw std::runtime_error("mc_jets_py does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mc_jets_pz() const{
  throw std::runtime_error("mc_jets_pz does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mc_jets_theta() const{
  throw std::runtime_error("mc_jets_theta does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mc_pdf_id1() const{
  throw std::runtime_error("mc_pdf_id1 does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mc_pdf_id2() const{
  throw std::runtime_error("mc_pdf_id2 does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mc_pdf_q() const{
  throw std::runtime_error("mc_pdf_q does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mc_pdf_x1() const{
  throw std::runtime_error("mc_pdf_x1 does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mc_pdf_x2() const{
  throw std::runtime_error("mc_pdf_x2 does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::metsHO_et() const{
  throw std::runtime_error("metsHO_et does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::metsHO_ex() const{
  throw std::runtime_error("metsHO_ex does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::metsHO_ey() const{
  throw std::runtime_error("metsHO_ey does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::metsHO_phi() const{
  throw std::runtime_error("metsHO_phi does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::metsHO_sumEt() const{
  throw std::runtime_error("metsHO_sumEt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mets_AK5_et() const{
  throw std::runtime_error("mets_AK5_et does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mets_AK5_ex() const{
  throw std::runtime_error("mets_AK5_ex does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mets_AK5_ey() const{
  throw std::runtime_error("mets_AK5_ey does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mets_AK5_gen_et() const{
  throw std::runtime_error("mets_AK5_gen_et does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mets_AK5_gen_phi() const{
  throw std::runtime_error("mets_AK5_gen_phi does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mets_AK5_phi() const{
  throw std::runtime_error("mets_AK5_phi does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mets_AK5_sign() const{
  throw std::runtime_error("mets_AK5_sign does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mets_AK5_sumEt() const{
  throw std::runtime_error("mets_AK5_sumEt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mets_AK5_unCPhi() const{
  throw std::runtime_error("mets_AK5_unCPhi does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mets_AK5_unCPt() const{
  throw std::runtime_error("mets_AK5_unCPt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mets_et() const{
  throw std::runtime_error("mets_et does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mets_ex() const{
  throw std::runtime_error("mets_ex does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mets_ey() const{
  throw std::runtime_error("mets_ey does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mets_gen_et() const{
  throw std::runtime_error("mets_gen_et does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mets_gen_phi() const{
  throw std::runtime_error("mets_gen_phi does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mets_phi() const{
  throw std::runtime_error("mets_phi does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mets_sign() const{
  throw std::runtime_error("mets_sign does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mets_sumEt() const{
  throw std::runtime_error("mets_sumEt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mets_unCPhi() const{
  throw std::runtime_error("mets_unCPhi does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::mets_unCPt() const{
  throw std::runtime_error("mets_unCPt does not exist in this cfA version.");
}

std::vector<bool>* const & cfa_base::mus_isPF() const{
  throw std::runtime_error("mus_isPF does not exist in this cfA version.");
}

std::vector<int>* const & cfa_base::mus_jet_ind() const{
  throw std::runtime_error("mus_jet_ind does not exist in this cfA version.");
}

Int_t const & cfa_base::passprescaleHT250filter_decision() const{
  throw std::runtime_error("passprescaleHT250filter_decision does not exist in this cfA version.");
}

Int_t const & cfa_base::passprescaleHT300filter_decision() const{
  throw std::runtime_error("passprescaleHT300filter_decision does not exist in this cfA version.");
}

Int_t const & cfa_base::passprescaleHT350filter_decision() const{
  throw std::runtime_error("passprescaleHT350filter_decision does not exist in this cfA version.");
}

Int_t const & cfa_base::passprescaleHT400filter_decision() const{
  throw std::runtime_error("passprescaleHT400filter_decision does not exist in this cfA version.");
}

Int_t const & cfa_base::passprescaleHT450filter_decision() const{
  throw std::runtime_error("passprescaleHT450filter_decision does not exist in this cfA version.");
}

Int_t const & cfa_base::passprescaleJet30MET80filter_decision() const{
  throw std::runtime_error("passprescaleJet30MET80filter_decision does not exist in this cfA version.");
}

Int_t const & cfa_base::passprescalePFHT350filter_decision() const{
  throw std::runtime_error("passprescalePFHT350filter_decision does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pdfweights_cteq() const{
  throw std::runtime_error("pdfweights_cteq does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pdfweights_mstw() const{
  throw std::runtime_error("pdfweights_mstw does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pdfweights_nnpdf() const{
  throw std::runtime_error("pdfweights_nnpdf does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pfTypeINoXYCorrmets_et() const{
  throw std::runtime_error("pfTypeINoXYCorrmets_et does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pfTypeINoXYCorrmets_ex() const{
  throw std::runtime_error("pfTypeINoXYCorrmets_ex does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pfTypeINoXYCorrmets_ey() const{
  throw std::runtime_error("pfTypeINoXYCorrmets_ey does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pfTypeINoXYCorrmets_gen_et() const{
  throw std::runtime_error("pfTypeINoXYCorrmets_gen_et does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pfTypeINoXYCorrmets_gen_phi() const{
  throw std::runtime_error("pfTypeINoXYCorrmets_gen_phi does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pfTypeINoXYCorrmets_phi() const{
  throw std::runtime_error("pfTypeINoXYCorrmets_phi does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pfTypeINoXYCorrmets_sign() const{
  throw std::runtime_error("pfTypeINoXYCorrmets_sign does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pfTypeINoXYCorrmets_sumEt() const{
  throw std::runtime_error("pfTypeINoXYCorrmets_sumEt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pfTypeINoXYCorrmets_unCPhi() const{
  throw std::runtime_error("pfTypeINoXYCorrmets_unCPhi does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pfTypeINoXYCorrmets_unCPt() const{
  throw std::runtime_error("pfTypeINoXYCorrmets_unCPt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pfTypeIType0mets_et() const{
  throw std::runtime_error("pfTypeIType0mets_et does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pfTypeIType0mets_ex() const{
  throw std::runtime_error("pfTypeIType0mets_ex does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pfTypeIType0mets_ey() const{
  throw std::runtime_error("pfTypeIType0mets_ey does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pfTypeIType0mets_gen_et() const{
  throw std::runtime_error("pfTypeIType0mets_gen_et does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pfTypeIType0mets_gen_phi() const{
  throw std::runtime_error("pfTypeIType0mets_gen_phi does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pfTypeIType0mets_phi() const{
  throw std::runtime_error("pfTypeIType0mets_phi does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pfTypeIType0mets_sign() const{
  throw std::runtime_error("pfTypeIType0mets_sign does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pfTypeIType0mets_sumEt() const{
  throw std::runtime_error("pfTypeIType0mets_sumEt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pfTypeIType0mets_unCPhi() const{
  throw std::runtime_error("pfTypeIType0mets_unCPhi does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pfTypeIType0mets_unCPt() const{
  throw std::runtime_error("pfTypeIType0mets_unCPt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pfTypeImets_et() const{
  throw std::runtime_error("pfTypeImets_et does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pfTypeImets_ex() const{
  throw std::runtime_error("pfTypeImets_ex does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pfTypeImets_ey() const{
  throw std::runtime_error("pfTypeImets_ey does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pfTypeImets_gen_et() const{
  throw std::runtime_error("pfTypeImets_gen_et does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pfTypeImets_gen_phi() const{
  throw std::runtime_error("pfTypeImets_gen_phi does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pfTypeImets_phi() const{
  throw std::runtime_error("pfTypeImets_phi does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pfTypeImets_sign() const{
  throw std::runtime_error("pfTypeImets_sign does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pfTypeImets_sumEt() const{
  throw std::runtime_error("pfTypeImets_sumEt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pfTypeImets_unCPhi() const{
  throw std::runtime_error("pfTypeImets_unCPhi does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pfTypeImets_unCPt() const{
  throw std::runtime_error("pfTypeImets_unCPt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_PATpassConversionVeto() const{
  throw std::runtime_error("pf_els_PATpassConversionVeto does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_PFchargedHadronIsoR03() const{
  throw std::runtime_error("pf_els_PFchargedHadronIsoR03 does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_PFneutralHadronIsoR03() const{
  throw std::runtime_error("pf_els_PFneutralHadronIsoR03 does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_PFphotonIsoR03() const{
  throw std::runtime_error("pf_els_PFphotonIsoR03 does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_basicClustersSize() const{
  throw std::runtime_error("pf_els_basicClustersSize does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_cIso() const{
  throw std::runtime_error("pf_els_cIso does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_caloEnergy() const{
  throw std::runtime_error("pf_els_caloEnergy does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_charge() const{
  throw std::runtime_error("pf_els_charge does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_chargedHadronIso() const{
  throw std::runtime_error("pf_els_chargedHadronIso does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_chi2() const{
  throw std::runtime_error("pf_els_chi2 does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_core_ecalDrivenSeed() const{
  throw std::runtime_error("pf_els_core_ecalDrivenSeed does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_cpx() const{
  throw std::runtime_error("pf_els_cpx does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_cpy() const{
  throw std::runtime_error("pf_els_cpy does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_cpz() const{
  throw std::runtime_error("pf_els_cpz does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_ctf_tk_charge() const{
  throw std::runtime_error("pf_els_ctf_tk_charge does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_ctf_tk_eta() const{
  throw std::runtime_error("pf_els_ctf_tk_eta does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_ctf_tk_id() const{
  throw std::runtime_error("pf_els_ctf_tk_id does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_ctf_tk_phi() const{
  throw std::runtime_error("pf_els_ctf_tk_phi does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_cx() const{
  throw std::runtime_error("pf_els_cx does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_cy() const{
  throw std::runtime_error("pf_els_cy does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_cz() const{
  throw std::runtime_error("pf_els_cz does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_d0dum() const{
  throw std::runtime_error("pf_els_d0dum does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_d0dumError() const{
  throw std::runtime_error("pf_els_d0dumError does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_dEtaIn() const{
  throw std::runtime_error("pf_els_dEtaIn does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_dEtaOut() const{
  throw std::runtime_error("pf_els_dEtaOut does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_dPhiIn() const{
  throw std::runtime_error("pf_els_dPhiIn does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_dPhiOut() const{
  throw std::runtime_error("pf_els_dPhiOut does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_dr03EcalRecHitSumEt() const{
  throw std::runtime_error("pf_els_dr03EcalRecHitSumEt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_dr03HcalDepth1TowerSumEt() const{
  throw std::runtime_error("pf_els_dr03HcalDepth1TowerSumEt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_dr03HcalDepth2TowerSumEt() const{
  throw std::runtime_error("pf_els_dr03HcalDepth2TowerSumEt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_dr03HcalTowerSumEt() const{
  throw std::runtime_error("pf_els_dr03HcalTowerSumEt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_dr03TkSumPt() const{
  throw std::runtime_error("pf_els_dr03TkSumPt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_dr04EcalRecHitSumEt() const{
  throw std::runtime_error("pf_els_dr04EcalRecHitSumEt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_dr04HcalDepth1TowerSumEt() const{
  throw std::runtime_error("pf_els_dr04HcalDepth1TowerSumEt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_dr04HcalDepth2TowerSumEt() const{
  throw std::runtime_error("pf_els_dr04HcalDepth2TowerSumEt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_dr04HcalTowerSumEt() const{
  throw std::runtime_error("pf_els_dr04HcalTowerSumEt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_dr04TkSumPt() const{
  throw std::runtime_error("pf_els_dr04TkSumPt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_dz() const{
  throw std::runtime_error("pf_els_dz does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_dzError() const{
  throw std::runtime_error("pf_els_dzError does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_eOverPIn() const{
  throw std::runtime_error("pf_els_eOverPIn does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_eSeedOverPOut() const{
  throw std::runtime_error("pf_els_eSeedOverPOut does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_ecalIso() const{
  throw std::runtime_error("pf_els_ecalIso does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_energy() const{
  throw std::runtime_error("pf_els_energy does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_et() const{
  throw std::runtime_error("pf_els_et does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_eta() const{
  throw std::runtime_error("pf_els_eta does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_etaError() const{
  throw std::runtime_error("pf_els_etaError does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_fbrem() const{
  throw std::runtime_error("pf_els_fbrem does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_gen_et() const{
  throw std::runtime_error("pf_els_gen_et does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_gen_eta() const{
  throw std::runtime_error("pf_els_gen_eta does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_gen_id() const{
  throw std::runtime_error("pf_els_gen_id does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_gen_mother_et() const{
  throw std::runtime_error("pf_els_gen_mother_et does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_gen_mother_eta() const{
  throw std::runtime_error("pf_els_gen_mother_eta does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_gen_mother_id() const{
  throw std::runtime_error("pf_els_gen_mother_id does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_gen_mother_phi() const{
  throw std::runtime_error("pf_els_gen_mother_phi does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_gen_mother_pt() const{
  throw std::runtime_error("pf_els_gen_mother_pt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_gen_mother_px() const{
  throw std::runtime_error("pf_els_gen_mother_px does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_gen_mother_py() const{
  throw std::runtime_error("pf_els_gen_mother_py does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_gen_mother_pz() const{
  throw std::runtime_error("pf_els_gen_mother_pz does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_gen_mother_theta() const{
  throw std::runtime_error("pf_els_gen_mother_theta does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_gen_phi() const{
  throw std::runtime_error("pf_els_gen_phi does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_gen_pt() const{
  throw std::runtime_error("pf_els_gen_pt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_gen_px() const{
  throw std::runtime_error("pf_els_gen_px does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_gen_py() const{
  throw std::runtime_error("pf_els_gen_py does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_gen_pz() const{
  throw std::runtime_error("pf_els_gen_pz does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_gen_theta() const{
  throw std::runtime_error("pf_els_gen_theta does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_hadOverEm() const{
  throw std::runtime_error("pf_els_hadOverEm does not exist in this cfA version.");
}

std::vector<bool>* const & cfa_base::pf_els_hasMatchedConversion() const{
  throw std::runtime_error("pf_els_hasMatchedConversion does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_hcalIso() const{
  throw std::runtime_error("pf_els_hcalIso does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_hcalOverEcalBc() const{
  throw std::runtime_error("pf_els_hcalOverEcalBc does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_isEB() const{
  throw std::runtime_error("pf_els_isEB does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_isEE() const{
  throw std::runtime_error("pf_els_isEE does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_looseId() const{
  throw std::runtime_error("pf_els_looseId does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_n_inner_layer() const{
  throw std::runtime_error("pf_els_n_inner_layer does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_n_outer_layer() const{
  throw std::runtime_error("pf_els_n_outer_layer does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_ndof() const{
  throw std::runtime_error("pf_els_ndof does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_neutralHadronIso() const{
  throw std::runtime_error("pf_els_neutralHadronIso does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_numlosthits() const{
  throw std::runtime_error("pf_els_numlosthits does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_numvalhits() const{
  throw std::runtime_error("pf_els_numvalhits does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_phi() const{
  throw std::runtime_error("pf_els_phi does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_phiError() const{
  throw std::runtime_error("pf_els_phiError does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_photonIso() const{
  throw std::runtime_error("pf_els_photonIso does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_pt() const{
  throw std::runtime_error("pf_els_pt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_ptError() const{
  throw std::runtime_error("pf_els_ptError does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_px() const{
  throw std::runtime_error("pf_els_px does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_py() const{
  throw std::runtime_error("pf_els_py does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_pz() const{
  throw std::runtime_error("pf_els_pz does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_robustHighEnergyId() const{
  throw std::runtime_error("pf_els_robustHighEnergyId does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_robustLooseId() const{
  throw std::runtime_error("pf_els_robustLooseId does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_robustTightId() const{
  throw std::runtime_error("pf_els_robustTightId does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_scE1x5() const{
  throw std::runtime_error("pf_els_scE1x5 does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_scE2x5Max() const{
  throw std::runtime_error("pf_els_scE2x5Max does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_scE5x5() const{
  throw std::runtime_error("pf_els_scE5x5 does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_scEnergy() const{
  throw std::runtime_error("pf_els_scEnergy does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_scEta() const{
  throw std::runtime_error("pf_els_scEta does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_scEtaWidth() const{
  throw std::runtime_error("pf_els_scEtaWidth does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_scPhi() const{
  throw std::runtime_error("pf_els_scPhi does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_scPhiWidth() const{
  throw std::runtime_error("pf_els_scPhiWidth does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_scRawEnergy() const{
  throw std::runtime_error("pf_els_scRawEnergy does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_scSeedEnergy() const{
  throw std::runtime_error("pf_els_scSeedEnergy does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_shFracInnerHits() const{
  throw std::runtime_error("pf_els_shFracInnerHits does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_sigmaEtaEta() const{
  throw std::runtime_error("pf_els_sigmaEtaEta does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_sigmaIEtaIEta() const{
  throw std::runtime_error("pf_els_sigmaIEtaIEta does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_simpleEleId60cIso() const{
  throw std::runtime_error("pf_els_simpleEleId60cIso does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_simpleEleId60relIso() const{
  throw std::runtime_error("pf_els_simpleEleId60relIso does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_simpleEleId70cIso() const{
  throw std::runtime_error("pf_els_simpleEleId70cIso does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_simpleEleId70relIso() const{
  throw std::runtime_error("pf_els_simpleEleId70relIso does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_simpleEleId80cIso() const{
  throw std::runtime_error("pf_els_simpleEleId80cIso does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_simpleEleId80relIso() const{
  throw std::runtime_error("pf_els_simpleEleId80relIso does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_simpleEleId85cIso() const{
  throw std::runtime_error("pf_els_simpleEleId85cIso does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_simpleEleId85relIso() const{
  throw std::runtime_error("pf_els_simpleEleId85relIso does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_simpleEleId90cIso() const{
  throw std::runtime_error("pf_els_simpleEleId90cIso does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_simpleEleId90relIso() const{
  throw std::runtime_error("pf_els_simpleEleId90relIso does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_simpleEleId95cIso() const{
  throw std::runtime_error("pf_els_simpleEleId95cIso does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_simpleEleId95relIso() const{
  throw std::runtime_error("pf_els_simpleEleId95relIso does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_status() const{
  throw std::runtime_error("pf_els_status does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_tIso() const{
  throw std::runtime_error("pf_els_tIso does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_theta() const{
  throw std::runtime_error("pf_els_theta does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_tightId() const{
  throw std::runtime_error("pf_els_tightId does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_tk_charge() const{
  throw std::runtime_error("pf_els_tk_charge does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_tk_eta() const{
  throw std::runtime_error("pf_els_tk_eta does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_tk_phi() const{
  throw std::runtime_error("pf_els_tk_phi does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_tk_pt() const{
  throw std::runtime_error("pf_els_tk_pt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_tk_pz() const{
  throw std::runtime_error("pf_els_tk_pz does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_vpx() const{
  throw std::runtime_error("pf_els_vpx does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_vpy() const{
  throw std::runtime_error("pf_els_vpy does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_vpz() const{
  throw std::runtime_error("pf_els_vpz does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_vx() const{
  throw std::runtime_error("pf_els_vx does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_vy() const{
  throw std::runtime_error("pf_els_vy does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_els_vz() const{
  throw std::runtime_error("pf_els_vz does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_cIso() const{
  throw std::runtime_error("pf_mus_cIso does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_calEnergyEm() const{
  throw std::runtime_error("pf_mus_calEnergyEm does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_calEnergyEmS9() const{
  throw std::runtime_error("pf_mus_calEnergyEmS9 does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_calEnergyHad() const{
  throw std::runtime_error("pf_mus_calEnergyHad does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_calEnergyHadS9() const{
  throw std::runtime_error("pf_mus_calEnergyHadS9 does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_calEnergyHo() const{
  throw std::runtime_error("pf_mus_calEnergyHo does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_calEnergyHoS9() const{
  throw std::runtime_error("pf_mus_calEnergyHoS9 does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_charge() const{
  throw std::runtime_error("pf_mus_charge does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_chargedHadronIso() const{
  throw std::runtime_error("pf_mus_chargedHadronIso does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_cm_ExpectedHitsInner() const{
  throw std::runtime_error("pf_mus_cm_ExpectedHitsInner does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_cm_ExpectedHitsOuter() const{
  throw std::runtime_error("pf_mus_cm_ExpectedHitsOuter does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_cm_LayersWithMeasurement() const{
  throw std::runtime_error("pf_mus_cm_LayersWithMeasurement does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_cm_LayersWithoutMeasurement() const{
  throw std::runtime_error("pf_mus_cm_LayersWithoutMeasurement does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_cm_PixelLayersWithMeasurement() const{
  throw std::runtime_error("pf_mus_cm_PixelLayersWithMeasurement does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_cm_ValidStripLayersWithMonoAndStereoHit() const{
  throw std::runtime_error("pf_mus_cm_ValidStripLayersWithMonoAndStereoHit does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_cm_chg() const{
  throw std::runtime_error("pf_mus_cm_chg does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_cm_chi2() const{
  throw std::runtime_error("pf_mus_cm_chi2 does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_cm_d0dum() const{
  throw std::runtime_error("pf_mus_cm_d0dum does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_cm_d0dumErr() const{
  throw std::runtime_error("pf_mus_cm_d0dumErr does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_cm_dz() const{
  throw std::runtime_error("pf_mus_cm_dz does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_cm_dzErr() const{
  throw std::runtime_error("pf_mus_cm_dzErr does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_cm_eta() const{
  throw std::runtime_error("pf_mus_cm_eta does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_cm_etaErr() const{
  throw std::runtime_error("pf_mus_cm_etaErr does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_cm_ndof() const{
  throw std::runtime_error("pf_mus_cm_ndof does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_cm_numlosthits() const{
  throw std::runtime_error("pf_mus_cm_numlosthits does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_cm_numvalMuonhits() const{
  throw std::runtime_error("pf_mus_cm_numvalMuonhits does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_cm_numvalhits() const{
  throw std::runtime_error("pf_mus_cm_numvalhits does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_cm_phi() const{
  throw std::runtime_error("pf_mus_cm_phi does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_cm_phiErr() const{
  throw std::runtime_error("pf_mus_cm_phiErr does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_cm_pt() const{
  throw std::runtime_error("pf_mus_cm_pt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_cm_ptErr() const{
  throw std::runtime_error("pf_mus_cm_ptErr does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_cm_px() const{
  throw std::runtime_error("pf_mus_cm_px does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_cm_py() const{
  throw std::runtime_error("pf_mus_cm_py does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_cm_pz() const{
  throw std::runtime_error("pf_mus_cm_pz does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_cm_theta() const{
  throw std::runtime_error("pf_mus_cm_theta does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_cm_vx() const{
  throw std::runtime_error("pf_mus_cm_vx does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_cm_vy() const{
  throw std::runtime_error("pf_mus_cm_vy does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_cm_vz() const{
  throw std::runtime_error("pf_mus_cm_vz does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_dB() const{
  throw std::runtime_error("pf_mus_dB does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_ecalIso() const{
  throw std::runtime_error("pf_mus_ecalIso does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_energy() const{
  throw std::runtime_error("pf_mus_energy does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_et() const{
  throw std::runtime_error("pf_mus_et does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_eta() const{
  throw std::runtime_error("pf_mus_eta does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_gen_et() const{
  throw std::runtime_error("pf_mus_gen_et does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_gen_eta() const{
  throw std::runtime_error("pf_mus_gen_eta does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_gen_id() const{
  throw std::runtime_error("pf_mus_gen_id does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_gen_mother_et() const{
  throw std::runtime_error("pf_mus_gen_mother_et does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_gen_mother_eta() const{
  throw std::runtime_error("pf_mus_gen_mother_eta does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_gen_mother_id() const{
  throw std::runtime_error("pf_mus_gen_mother_id does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_gen_mother_phi() const{
  throw std::runtime_error("pf_mus_gen_mother_phi does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_gen_mother_pt() const{
  throw std::runtime_error("pf_mus_gen_mother_pt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_gen_mother_px() const{
  throw std::runtime_error("pf_mus_gen_mother_px does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_gen_mother_py() const{
  throw std::runtime_error("pf_mus_gen_mother_py does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_gen_mother_pz() const{
  throw std::runtime_error("pf_mus_gen_mother_pz does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_gen_mother_theta() const{
  throw std::runtime_error("pf_mus_gen_mother_theta does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_gen_phi() const{
  throw std::runtime_error("pf_mus_gen_phi does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_gen_pt() const{
  throw std::runtime_error("pf_mus_gen_pt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_gen_px() const{
  throw std::runtime_error("pf_mus_gen_px does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_gen_py() const{
  throw std::runtime_error("pf_mus_gen_py does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_gen_pz() const{
  throw std::runtime_error("pf_mus_gen_pz does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_gen_theta() const{
  throw std::runtime_error("pf_mus_gen_theta does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_hcalIso() const{
  throw std::runtime_error("pf_mus_hcalIso does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_id_All() const{
  throw std::runtime_error("pf_mus_id_All does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_id_AllArbitrated() const{
  throw std::runtime_error("pf_mus_id_AllArbitrated does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_id_AllGlobalMuons() const{
  throw std::runtime_error("pf_mus_id_AllGlobalMuons does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_id_AllStandAloneMuons() const{
  throw std::runtime_error("pf_mus_id_AllStandAloneMuons does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_id_AllTrackerMuons() const{
  throw std::runtime_error("pf_mus_id_AllTrackerMuons does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_id_GlobalMuonPromptTight() const{
  throw std::runtime_error("pf_mus_id_GlobalMuonPromptTight does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_id_TM2DCompatibilityLoose() const{
  throw std::runtime_error("pf_mus_id_TM2DCompatibilityLoose does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_id_TM2DCompatibilityTight() const{
  throw std::runtime_error("pf_mus_id_TM2DCompatibilityTight does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_id_TMLastStationLoose() const{
  throw std::runtime_error("pf_mus_id_TMLastStationLoose does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_id_TMLastStationOptimizedLowPtLoose() const{
  throw std::runtime_error("pf_mus_id_TMLastStationOptimizedLowPtLoose does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_id_TMLastStationOptimizedLowPtTight() const{
  throw std::runtime_error("pf_mus_id_TMLastStationOptimizedLowPtTight does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_id_TMLastStationTight() const{
  throw std::runtime_error("pf_mus_id_TMLastStationTight does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_id_TMOneStationLoose() const{
  throw std::runtime_error("pf_mus_id_TMOneStationLoose does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_id_TMOneStationTight() const{
  throw std::runtime_error("pf_mus_id_TMOneStationTight does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_id_TrackerMuonArbitrated() const{
  throw std::runtime_error("pf_mus_id_TrackerMuonArbitrated does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_isCaloMuon() const{
  throw std::runtime_error("pf_mus_isCaloMuon does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_isConvertedPhoton() const{
  throw std::runtime_error("pf_mus_isConvertedPhoton does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_isElectron() const{
  throw std::runtime_error("pf_mus_isElectron does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_isGlobalMuon() const{
  throw std::runtime_error("pf_mus_isGlobalMuon does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_isPFMuon() const{
  throw std::runtime_error("pf_mus_isPFMuon does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_isPhoton() const{
  throw std::runtime_error("pf_mus_isPhoton does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_isStandAloneMuon() const{
  throw std::runtime_error("pf_mus_isStandAloneMuon does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_isTrackerMuon() const{
  throw std::runtime_error("pf_mus_isTrackerMuon does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_iso03_emEt() const{
  throw std::runtime_error("pf_mus_iso03_emEt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_iso03_emVetoEt() const{
  throw std::runtime_error("pf_mus_iso03_emVetoEt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_iso03_hadEt() const{
  throw std::runtime_error("pf_mus_iso03_hadEt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_iso03_hadVetoEt() const{
  throw std::runtime_error("pf_mus_iso03_hadVetoEt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_iso03_hoEt() const{
  throw std::runtime_error("pf_mus_iso03_hoEt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_iso03_nTracks() const{
  throw std::runtime_error("pf_mus_iso03_nTracks does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_iso03_sumPt() const{
  throw std::runtime_error("pf_mus_iso03_sumPt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_iso05_emEt() const{
  throw std::runtime_error("pf_mus_iso05_emEt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_iso05_hadEt() const{
  throw std::runtime_error("pf_mus_iso05_hadEt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_iso05_hoEt() const{
  throw std::runtime_error("pf_mus_iso05_hoEt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_iso05_nTracks() const{
  throw std::runtime_error("pf_mus_iso05_nTracks does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_iso05_sumPt() const{
  throw std::runtime_error("pf_mus_iso05_sumPt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_neutralHadronIso() const{
  throw std::runtime_error("pf_mus_neutralHadronIso does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_num_matches() const{
  throw std::runtime_error("pf_mus_num_matches does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_numberOfMatchedStations() const{
  throw std::runtime_error("pf_mus_numberOfMatchedStations does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_pfIsolationR03_sumChargedHadronPt() const{
  throw std::runtime_error("pf_mus_pfIsolationR03_sumChargedHadronPt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_pfIsolationR03_sumChargedParticlePt() const{
  throw std::runtime_error("pf_mus_pfIsolationR03_sumChargedParticlePt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_pfIsolationR03_sumNeutralHadronEt() const{
  throw std::runtime_error("pf_mus_pfIsolationR03_sumNeutralHadronEt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold() const{
  throw std::runtime_error("pf_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_pfIsolationR03_sumPUPt() const{
  throw std::runtime_error("pf_mus_pfIsolationR03_sumPUPt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_pfIsolationR03_sumPhotonEt() const{
  throw std::runtime_error("pf_mus_pfIsolationR03_sumPhotonEt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_pfIsolationR03_sumPhotonEtHighThreshold() const{
  throw std::runtime_error("pf_mus_pfIsolationR03_sumPhotonEtHighThreshold does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_pfIsolationR04_sumChargedHadronPt() const{
  throw std::runtime_error("pf_mus_pfIsolationR04_sumChargedHadronPt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_pfIsolationR04_sumChargedParticlePt() const{
  throw std::runtime_error("pf_mus_pfIsolationR04_sumChargedParticlePt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_pfIsolationR04_sumNeutralHadronEt() const{
  throw std::runtime_error("pf_mus_pfIsolationR04_sumNeutralHadronEt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold() const{
  throw std::runtime_error("pf_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_pfIsolationR04_sumPUPt() const{
  throw std::runtime_error("pf_mus_pfIsolationR04_sumPUPt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_pfIsolationR04_sumPhotonEt() const{
  throw std::runtime_error("pf_mus_pfIsolationR04_sumPhotonEt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_pfIsolationR04_sumPhotonEtHighThreshold() const{
  throw std::runtime_error("pf_mus_pfIsolationR04_sumPhotonEtHighThreshold does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_phi() const{
  throw std::runtime_error("pf_mus_phi does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_photonIso() const{
  throw std::runtime_error("pf_mus_photonIso does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_picky_ExpectedHitsInner() const{
  throw std::runtime_error("pf_mus_picky_ExpectedHitsInner does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_picky_ExpectedHitsOuter() const{
  throw std::runtime_error("pf_mus_picky_ExpectedHitsOuter does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_picky_LayersWithMeasurement() const{
  throw std::runtime_error("pf_mus_picky_LayersWithMeasurement does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_picky_LayersWithoutMeasurement() const{
  throw std::runtime_error("pf_mus_picky_LayersWithoutMeasurement does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_picky_PixelLayersWithMeasurement() const{
  throw std::runtime_error("pf_mus_picky_PixelLayersWithMeasurement does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_picky_ValidStripLayersWithMonoAndStereoHit() const{
  throw std::runtime_error("pf_mus_picky_ValidStripLayersWithMonoAndStereoHit does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_picky_chg() const{
  throw std::runtime_error("pf_mus_picky_chg does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_picky_chi2() const{
  throw std::runtime_error("pf_mus_picky_chi2 does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_picky_d0dum() const{
  throw std::runtime_error("pf_mus_picky_d0dum does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_picky_d0dumErr() const{
  throw std::runtime_error("pf_mus_picky_d0dumErr does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_picky_dz() const{
  throw std::runtime_error("pf_mus_picky_dz does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_picky_dzErr() const{
  throw std::runtime_error("pf_mus_picky_dzErr does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_picky_eta() const{
  throw std::runtime_error("pf_mus_picky_eta does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_picky_etaErr() const{
  throw std::runtime_error("pf_mus_picky_etaErr does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_picky_id() const{
  throw std::runtime_error("pf_mus_picky_id does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_picky_ndof() const{
  throw std::runtime_error("pf_mus_picky_ndof does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_picky_numlosthits() const{
  throw std::runtime_error("pf_mus_picky_numlosthits does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_picky_numvalPixelhits() const{
  throw std::runtime_error("pf_mus_picky_numvalPixelhits does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_picky_numvalhits() const{
  throw std::runtime_error("pf_mus_picky_numvalhits does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_picky_phi() const{
  throw std::runtime_error("pf_mus_picky_phi does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_picky_phiErr() const{
  throw std::runtime_error("pf_mus_picky_phiErr does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_picky_pt() const{
  throw std::runtime_error("pf_mus_picky_pt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_picky_ptErr() const{
  throw std::runtime_error("pf_mus_picky_ptErr does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_picky_px() const{
  throw std::runtime_error("pf_mus_picky_px does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_picky_py() const{
  throw std::runtime_error("pf_mus_picky_py does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_picky_pz() const{
  throw std::runtime_error("pf_mus_picky_pz does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_picky_theta() const{
  throw std::runtime_error("pf_mus_picky_theta does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_picky_vx() const{
  throw std::runtime_error("pf_mus_picky_vx does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_picky_vy() const{
  throw std::runtime_error("pf_mus_picky_vy does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_picky_vz() const{
  throw std::runtime_error("pf_mus_picky_vz does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_pt() const{
  throw std::runtime_error("pf_mus_pt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_px() const{
  throw std::runtime_error("pf_mus_px does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_py() const{
  throw std::runtime_error("pf_mus_py does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_pz() const{
  throw std::runtime_error("pf_mus_pz does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_stamu_chg() const{
  throw std::runtime_error("pf_mus_stamu_chg does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_stamu_chi2() const{
  throw std::runtime_error("pf_mus_stamu_chi2 does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_stamu_d0dum() const{
  throw std::runtime_error("pf_mus_stamu_d0dum does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_stamu_d0dumErr() const{
  throw std::runtime_error("pf_mus_stamu_d0dumErr does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_stamu_dz() const{
  throw std::runtime_error("pf_mus_stamu_dz does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_stamu_dzErr() const{
  throw std::runtime_error("pf_mus_stamu_dzErr does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_stamu_eta() const{
  throw std::runtime_error("pf_mus_stamu_eta does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_stamu_etaErr() const{
  throw std::runtime_error("pf_mus_stamu_etaErr does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_stamu_ndof() const{
  throw std::runtime_error("pf_mus_stamu_ndof does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_stamu_numlosthits() const{
  throw std::runtime_error("pf_mus_stamu_numlosthits does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_stamu_numvalhits() const{
  throw std::runtime_error("pf_mus_stamu_numvalhits does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_stamu_phi() const{
  throw std::runtime_error("pf_mus_stamu_phi does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_stamu_phiErr() const{
  throw std::runtime_error("pf_mus_stamu_phiErr does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_stamu_pt() const{
  throw std::runtime_error("pf_mus_stamu_pt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_stamu_ptErr() const{
  throw std::runtime_error("pf_mus_stamu_ptErr does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_stamu_px() const{
  throw std::runtime_error("pf_mus_stamu_px does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_stamu_py() const{
  throw std::runtime_error("pf_mus_stamu_py does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_stamu_pz() const{
  throw std::runtime_error("pf_mus_stamu_pz does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_stamu_theta() const{
  throw std::runtime_error("pf_mus_stamu_theta does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_stamu_vx() const{
  throw std::runtime_error("pf_mus_stamu_vx does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_stamu_vy() const{
  throw std::runtime_error("pf_mus_stamu_vy does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_stamu_vz() const{
  throw std::runtime_error("pf_mus_stamu_vz does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_status() const{
  throw std::runtime_error("pf_mus_status does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tIso() const{
  throw std::runtime_error("pf_mus_tIso does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_theta() const{
  throw std::runtime_error("pf_mus_theta does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tkHits() const{
  throw std::runtime_error("pf_mus_tkHits does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tk_ExpectedHitsInner() const{
  throw std::runtime_error("pf_mus_tk_ExpectedHitsInner does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tk_ExpectedHitsOuter() const{
  throw std::runtime_error("pf_mus_tk_ExpectedHitsOuter does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tk_LayersWithMeasurement() const{
  throw std::runtime_error("pf_mus_tk_LayersWithMeasurement does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tk_LayersWithoutMeasurement() const{
  throw std::runtime_error("pf_mus_tk_LayersWithoutMeasurement does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tk_PixelLayersWithMeasurement() const{
  throw std::runtime_error("pf_mus_tk_PixelLayersWithMeasurement does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tk_ValidStripLayersWithMonoAndStereoHit() const{
  throw std::runtime_error("pf_mus_tk_ValidStripLayersWithMonoAndStereoHit does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tk_chg() const{
  throw std::runtime_error("pf_mus_tk_chg does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tk_chi2() const{
  throw std::runtime_error("pf_mus_tk_chi2 does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tk_d0dum() const{
  throw std::runtime_error("pf_mus_tk_d0dum does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tk_d0dumErr() const{
  throw std::runtime_error("pf_mus_tk_d0dumErr does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tk_dz() const{
  throw std::runtime_error("pf_mus_tk_dz does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tk_dzErr() const{
  throw std::runtime_error("pf_mus_tk_dzErr does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tk_eta() const{
  throw std::runtime_error("pf_mus_tk_eta does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tk_etaErr() const{
  throw std::runtime_error("pf_mus_tk_etaErr does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tk_id() const{
  throw std::runtime_error("pf_mus_tk_id does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tk_ndof() const{
  throw std::runtime_error("pf_mus_tk_ndof does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tk_numlosthits() const{
  throw std::runtime_error("pf_mus_tk_numlosthits does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tk_numpixelWthMeasr() const{
  throw std::runtime_error("pf_mus_tk_numpixelWthMeasr does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tk_numvalPixelhits() const{
  throw std::runtime_error("pf_mus_tk_numvalPixelhits does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tk_numvalhits() const{
  throw std::runtime_error("pf_mus_tk_numvalhits does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tk_phi() const{
  throw std::runtime_error("pf_mus_tk_phi does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tk_phiErr() const{
  throw std::runtime_error("pf_mus_tk_phiErr does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tk_pt() const{
  throw std::runtime_error("pf_mus_tk_pt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tk_ptErr() const{
  throw std::runtime_error("pf_mus_tk_ptErr does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tk_px() const{
  throw std::runtime_error("pf_mus_tk_px does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tk_py() const{
  throw std::runtime_error("pf_mus_tk_py does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tk_pz() const{
  throw std::runtime_error("pf_mus_tk_pz does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tk_theta() const{
  throw std::runtime_error("pf_mus_tk_theta does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tk_vx() const{
  throw std::runtime_error("pf_mus_tk_vx does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tk_vy() const{
  throw std::runtime_error("pf_mus_tk_vy does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tk_vz() const{
  throw std::runtime_error("pf_mus_tk_vz does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tpfms_ExpectedHitsInner() const{
  throw std::runtime_error("pf_mus_tpfms_ExpectedHitsInner does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tpfms_ExpectedHitsOuter() const{
  throw std::runtime_error("pf_mus_tpfms_ExpectedHitsOuter does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tpfms_LayersWithMeasurement() const{
  throw std::runtime_error("pf_mus_tpfms_LayersWithMeasurement does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tpfms_LayersWithoutMeasurement() const{
  throw std::runtime_error("pf_mus_tpfms_LayersWithoutMeasurement does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tpfms_PixelLayersWithMeasurement() const{
  throw std::runtime_error("pf_mus_tpfms_PixelLayersWithMeasurement does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tpfms_ValidStripLayersWithMonoAndStereoHit() const{
  throw std::runtime_error("pf_mus_tpfms_ValidStripLayersWithMonoAndStereoHit does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tpfms_chg() const{
  throw std::runtime_error("pf_mus_tpfms_chg does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tpfms_chi2() const{
  throw std::runtime_error("pf_mus_tpfms_chi2 does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tpfms_d0dum() const{
  throw std::runtime_error("pf_mus_tpfms_d0dum does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tpfms_d0dumErr() const{
  throw std::runtime_error("pf_mus_tpfms_d0dumErr does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tpfms_dz() const{
  throw std::runtime_error("pf_mus_tpfms_dz does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tpfms_dzErr() const{
  throw std::runtime_error("pf_mus_tpfms_dzErr does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tpfms_eta() const{
  throw std::runtime_error("pf_mus_tpfms_eta does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tpfms_etaErr() const{
  throw std::runtime_error("pf_mus_tpfms_etaErr does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tpfms_id() const{
  throw std::runtime_error("pf_mus_tpfms_id does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tpfms_ndof() const{
  throw std::runtime_error("pf_mus_tpfms_ndof does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tpfms_numlosthits() const{
  throw std::runtime_error("pf_mus_tpfms_numlosthits does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tpfms_numvalPixelhits() const{
  throw std::runtime_error("pf_mus_tpfms_numvalPixelhits does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tpfms_numvalhits() const{
  throw std::runtime_error("pf_mus_tpfms_numvalhits does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tpfms_phi() const{
  throw std::runtime_error("pf_mus_tpfms_phi does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tpfms_phiErr() const{
  throw std::runtime_error("pf_mus_tpfms_phiErr does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tpfms_pt() const{
  throw std::runtime_error("pf_mus_tpfms_pt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tpfms_ptErr() const{
  throw std::runtime_error("pf_mus_tpfms_ptErr does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tpfms_px() const{
  throw std::runtime_error("pf_mus_tpfms_px does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tpfms_py() const{
  throw std::runtime_error("pf_mus_tpfms_py does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tpfms_pz() const{
  throw std::runtime_error("pf_mus_tpfms_pz does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tpfms_theta() const{
  throw std::runtime_error("pf_mus_tpfms_theta does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tpfms_vx() const{
  throw std::runtime_error("pf_mus_tpfms_vx does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tpfms_vy() const{
  throw std::runtime_error("pf_mus_tpfms_vy does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_mus_tpfms_vz() const{
  throw std::runtime_error("pf_mus_tpfms_vz does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_photons_chIso() const{
  throw std::runtime_error("pf_photons_chIso does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_photons_e1x5() const{
  throw std::runtime_error("pf_photons_e1x5 does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_photons_e2x5() const{
  throw std::runtime_error("pf_photons_e2x5 does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_photons_e3x3() const{
  throw std::runtime_error("pf_photons_e3x3 does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_photons_e5x5() const{
  throw std::runtime_error("pf_photons_e5x5 does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_photons_energy() const{
  throw std::runtime_error("pf_photons_energy does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_photons_et() const{
  throw std::runtime_error("pf_photons_et does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_photons_eta() const{
  throw std::runtime_error("pf_photons_eta does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_photons_hadOverEM() const{
  throw std::runtime_error("pf_photons_hadOverEM does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_photons_hadTowOverEM() const{
  throw std::runtime_error("pf_photons_hadTowOverEM does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_photons_hasPixelSeed() const{
  throw std::runtime_error("pf_photons_hasPixelSeed does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_photons_isAlsoElectron() const{
  throw std::runtime_error("pf_photons_isAlsoElectron does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_photons_isConverted() const{
  throw std::runtime_error("pf_photons_isConverted does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_photons_isEBEEGap() const{
  throw std::runtime_error("pf_photons_isEBEEGap does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_photons_isEBGap() const{
  throw std::runtime_error("pf_photons_isEBGap does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_photons_isEBPho() const{
  throw std::runtime_error("pf_photons_isEBPho does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_photons_isEEGap() const{
  throw std::runtime_error("pf_photons_isEEGap does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_photons_isEEPho() const{
  throw std::runtime_error("pf_photons_isEEPho does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_photons_maxEnergyXtal() const{
  throw std::runtime_error("pf_photons_maxEnergyXtal does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_photons_nhIso() const{
  throw std::runtime_error("pf_photons_nhIso does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_photons_phIso() const{
  throw std::runtime_error("pf_photons_phIso does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_photons_phi() const{
  throw std::runtime_error("pf_photons_phi does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_photons_pt() const{
  throw std::runtime_error("pf_photons_pt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_photons_px() const{
  throw std::runtime_error("pf_photons_px does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_photons_py() const{
  throw std::runtime_error("pf_photons_py does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_photons_pz() const{
  throw std::runtime_error("pf_photons_pz does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_photons_r9() const{
  throw std::runtime_error("pf_photons_r9 does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_photons_scEnergy() const{
  throw std::runtime_error("pf_photons_scEnergy does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_photons_scEta() const{
  throw std::runtime_error("pf_photons_scEta does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_photons_scEtaWidth() const{
  throw std::runtime_error("pf_photons_scEtaWidth does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_photons_scPhi() const{
  throw std::runtime_error("pf_photons_scPhi does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_photons_scPhiWidth() const{
  throw std::runtime_error("pf_photons_scPhiWidth does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_photons_scRawEnergy() const{
  throw std::runtime_error("pf_photons_scRawEnergy does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_photons_sigmaEtaEta() const{
  throw std::runtime_error("pf_photons_sigmaEtaEta does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_photons_sigmaIetaIeta() const{
  throw std::runtime_error("pf_photons_sigmaIetaIeta does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_photons_status() const{
  throw std::runtime_error("pf_photons_status does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pf_photons_theta() const{
  throw std::runtime_error("pf_photons_theta does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pfcand_particleId() const{
  throw std::runtime_error("pfcand_particleId does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pfmets_et() const{
  throw std::runtime_error("pfmets_et does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pfmets_ex() const{
  throw std::runtime_error("pfmets_ex does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pfmets_ey() const{
  throw std::runtime_error("pfmets_ey does not exist in this cfA version.");
}

Float_t const & cfa_base::pfmets_fullSignif() const{
  throw std::runtime_error("pfmets_fullSignif does not exist in this cfA version.");
}

Float_t const & cfa_base::pfmets_fullSignifCov00() const{
  throw std::runtime_error("pfmets_fullSignifCov00 does not exist in this cfA version.");
}

Float_t const & cfa_base::pfmets_fullSignifCov00_2012() const{
  throw std::runtime_error("pfmets_fullSignifCov00_2012 does not exist in this cfA version.");
}

Float_t const & cfa_base::pfmets_fullSignifCov00_2012_dataRes() const{
  throw std::runtime_error("pfmets_fullSignifCov00_2012_dataRes does not exist in this cfA version.");
}

Float_t const & cfa_base::pfmets_fullSignifCov10() const{
  throw std::runtime_error("pfmets_fullSignifCov10 does not exist in this cfA version.");
}

Float_t const & cfa_base::pfmets_fullSignifCov10_2012() const{
  throw std::runtime_error("pfmets_fullSignifCov10_2012 does not exist in this cfA version.");
}

Float_t const & cfa_base::pfmets_fullSignifCov10_2012_dataRes() const{
  throw std::runtime_error("pfmets_fullSignifCov10_2012_dataRes does not exist in this cfA version.");
}

Float_t const & cfa_base::pfmets_fullSignifCov11() const{
  throw std::runtime_error("pfmets_fullSignifCov11 does not exist in this cfA version.");
}

Float_t const & cfa_base::pfmets_fullSignifCov11_2012() const{
  throw std::runtime_error("pfmets_fullSignifCov11_2012 does not exist in this cfA version.");
}

Float_t const & cfa_base::pfmets_fullSignifCov11_2012_dataRes() const{
  throw std::runtime_error("pfmets_fullSignifCov11_2012_dataRes does not exist in this cfA version.");
}

Float_t const & cfa_base::pfmets_fullSignif_2012() const{
  throw std::runtime_error("pfmets_fullSignif_2012 does not exist in this cfA version.");
}

Float_t const & cfa_base::pfmets_fullSignif_2012_dataRes() const{
  throw std::runtime_error("pfmets_fullSignif_2012_dataRes does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pfmets_gen_et() const{
  throw std::runtime_error("pfmets_gen_et does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pfmets_gen_phi() const{
  throw std::runtime_error("pfmets_gen_phi does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pfmets_phi() const{
  throw std::runtime_error("pfmets_phi does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pfmets_sign() const{
  throw std::runtime_error("pfmets_sign does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pfmets_sumEt() const{
  throw std::runtime_error("pfmets_sumEt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pfmets_unCPhi() const{
  throw std::runtime_error("pfmets_unCPhi does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::pfmets_unCPt() const{
  throw std::runtime_error("pfmets_unCPt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::photon_chIsoValues() const{
  throw std::runtime_error("photon_chIsoValues does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::photon_nhIsoValues() const{
  throw std::runtime_error("photon_nhIsoValues does not exist in this cfA version.");
}

std::vector<bool>* const & cfa_base::photon_passElectronVeto() const{
  throw std::runtime_error("photon_passElectronVeto does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::photon_phIsoValues() const{
  throw std::runtime_error("photon_phIsoValues does not exist in this cfA version.");
}

std::vector<std::vector<float> >* const & cfa_base::puJet_rejectionBeta() const{
  throw std::runtime_error("puJet_rejectionBeta does not exist in this cfA version.");
}

std::vector<std::vector<float> >* const & cfa_base::puJet_rejectionMVA() const{
  throw std::runtime_error("puJet_rejectionMVA does not exist in this cfA version.");
}

Float_t const & cfa_base::rho_kt6PFJetsForIsolation2011() const{
  throw std::runtime_error("rho_kt6PFJetsForIsolation2011 does not exist in this cfA version.");
}

Float_t const & cfa_base::rho_kt6PFJetsForIsolation2012() const{
  throw std::runtime_error("rho_kt6PFJetsForIsolation2012 does not exist in this cfA version.");
}

Int_t const & cfa_base::scrapingVeto_decision() const{
  throw std::runtime_error("scrapingVeto_decision does not exist in this cfA version.");
}

Float_t const & cfa_base::softjetUp_dMEx() const{
  throw std::runtime_error("softjetUp_dMEx does not exist in this cfA version.");
}

Float_t const & cfa_base::softjetUp_dMEy() const{
  throw std::runtime_error("softjetUp_dMEy does not exist in this cfA version.");
}

std::vector<int>* const & cfa_base::taus_el_ind() const{
  throw std::runtime_error("taus_el_ind does not exist in this cfA version.");
}

std::vector<int>* const & cfa_base::taus_mu_ind() const{
  throw std::runtime_error("taus_mu_ind does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::tcmets_et() const{
  throw std::runtime_error("tcmets_et does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::tcmets_ex() const{
  throw std::runtime_error("tcmets_ex does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::tcmets_ey() const{
  throw std::runtime_error("tcmets_ey does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::tcmets_phi() const{
  throw std::runtime_error("tcmets_phi does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::tcmets_sumEt() const{
  throw std::runtime_error("tcmets_sumEt does not exist in this cfA version.");
}

Int_t const & cfa_base::trackercoherentnoisefilter1_decision() const{
  throw std::runtime_error("trackercoherentnoisefilter1_decision does not exist in this cfA version.");
}

Int_t const & cfa_base::trackercoherentnoisefilter2_decision() const{
  throw std::runtime_error("trackercoherentnoisefilter2_decision does not exist in this cfA version.");
}

Int_t const & cfa_base::trackertoomanyclustersfilter_decision() const{
  throw std::runtime_error("trackertoomanyclustersfilter_decision does not exist in this cfA version.");
}

Int_t const & cfa_base::trackertoomanyseedsfilter_decision() const{
  throw std::runtime_error("trackertoomanyseedsfilter_decision does not exist in this cfA version.");
}

Int_t const & cfa_base::trackertoomanytripletsfilter_decision() const{
  throw std::runtime_error("trackertoomanytripletsfilter_decision does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::tracks_chg() const{
  throw std::runtime_error("tracks_chg does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::tracks_chi2() const{
  throw std::runtime_error("tracks_chi2 does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::tracks_d0dum() const{
  throw std::runtime_error("tracks_d0dum does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::tracks_d0dumErr() const{
  throw std::runtime_error("tracks_d0dumErr does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::tracks_dz() const{
  throw std::runtime_error("tracks_dz does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::tracks_dzErr() const{
  throw std::runtime_error("tracks_dzErr does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::tracks_eta() const{
  throw std::runtime_error("tracks_eta does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::tracks_etaErr() const{
  throw std::runtime_error("tracks_etaErr does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::tracks_highPurity() const{
  throw std::runtime_error("tracks_highPurity does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::tracks_ndof() const{
  throw std::runtime_error("tracks_ndof does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::tracks_numlosthits() const{
  throw std::runtime_error("tracks_numlosthits does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::tracks_numvalhits() const{
  throw std::runtime_error("tracks_numvalhits does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::tracks_phi() const{
  throw std::runtime_error("tracks_phi does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::tracks_phiErr() const{
  throw std::runtime_error("tracks_phiErr does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::tracks_pt() const{
  throw std::runtime_error("tracks_pt does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::tracks_ptErr() const{
  throw std::runtime_error("tracks_ptErr does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::tracks_px() const{
  throw std::runtime_error("tracks_px does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::tracks_py() const{
  throw std::runtime_error("tracks_py does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::tracks_pz() const{
  throw std::runtime_error("tracks_pz does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::tracks_vx() const{
  throw std::runtime_error("tracks_vx does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::tracks_vy() const{
  throw std::runtime_error("tracks_vy does not exist in this cfA version.");
}

std::vector<float>* const & cfa_base::tracks_vz() const{
  throw std::runtime_error("tracks_vz does not exist in this cfA version.");
}

std::vector<bool>* const & cfa_base::trigger_decision() const{
  throw std::runtime_error("trigger_decision does not exist in this cfA version.");
}

std::vector<std::string>* const & cfa_base::trigger_lastfiltername() const{
  throw std::runtime_error("trigger_lastfiltername does not exist in this cfA version.");
}

std::vector<std::vector<std::string> >* const & cfa_base::triggerobject_collectionname() const{
  throw std::runtime_error("triggerobject_collectionname does not exist in this cfA version.");
}

std::vector<std::vector<float> >* const & cfa_base::triggerobject_energy() const{
  throw std::runtime_error("triggerobject_energy does not exist in this cfA version.");
}

std::vector<std::vector<float> >* const & cfa_base::triggerobject_et() const{
  throw std::runtime_error("triggerobject_et does not exist in this cfA version.");
}

std::vector<std::vector<float> >* const & cfa_base::triggerobject_eta() const{
  throw std::runtime_error("triggerobject_eta does not exist in this cfA version.");
}

std::vector<std::vector<float> >* const & cfa_base::triggerobject_phi() const{
  throw std::runtime_error("triggerobject_phi does not exist in this cfA version.");
}

std::vector<std::vector<float> >* const & cfa_base::triggerobject_pt() const{
  throw std::runtime_error("triggerobject_pt does not exist in this cfA version.");
}

std::vector<std::vector<float> >* const & cfa_base::triggerobject_px() const{
  throw std::runtime_error("triggerobject_px does not exist in this cfA version.");
}

std::vector<std::vector<float> >* const & cfa_base::triggerobject_py() const{
  throw std::runtime_error("triggerobject_py does not exist in this cfA version.");
}

std::vector<std::vector<float> >* const & cfa_base::triggerobject_pz() const{
  throw std::runtime_error("triggerobject_pz does not exist in this cfA version.");
}

Int_t const & cfa_base::trkPOG_logErrorTooManyClustersfilter_decision() const{
  throw std::runtime_error("trkPOG_logErrorTooManyClustersfilter_decision does not exist in this cfA version.");
}

Int_t const & cfa_base::trkPOG_manystripclus53Xfilter_decision() const{
  throw std::runtime_error("trkPOG_manystripclus53Xfilter_decision does not exist in this cfA version.");
}

Int_t const & cfa_base::trkPOG_toomanystripclus53Xfilter_decision() const{
  throw std::runtime_error("trkPOG_toomanystripclus53Xfilter_decision does not exist in this cfA version.");
}

Int_t const & cfa_base::trkPOGfilter_decision() const{
  throw std::runtime_error("trkPOGfilter_decision does not exist in this cfA version.");
}

Int_t const & cfa_base::trk_nTOBTEC() const{
  throw std::runtime_error("trk_nTOBTEC does not exist in this cfA version.");
}

Float_t const & cfa_base::trk_ratioAllTOBTEC() const{
  throw std::runtime_error("trk_ratioAllTOBTEC does not exist in this cfA version.");
}

Float_t const & cfa_base::trk_ratioJetTOBTEC() const{
  throw std::runtime_error("trk_ratioJetTOBTEC does not exist in this cfA version.");
}

