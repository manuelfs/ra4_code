#include "cfa_13.hpp"

#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>

#include "TChain.h"

cfa_13::cfa_13(const std::string &file):
  cfa_base(file),
  EcalDeadCellTriggerPrimitivefilter_decision_(0),
  HBHENoisefilter_decision_(0),
  METFiltersfilter_decision_(0),
  NbeamSpot_(0),
  Nels_(0),
  Njets_AK4_(0),
  Nmc_doc_(0),
  Nmc_electrons_(0),
  Nmc_final_(0),
  Nmc_jets_(0),
  Nmc_mus_(0),
  Nmc_nues_(0),
  Nmc_numus_(0),
  Nmc_nutaus_(0),
  Nmc_photons_(0),
  Nmc_taus_(0),
  Nmets_(0),
  Nmus_(0),
  Npfcand_(0),
  Nphotons_(0),
  Npv_(0),
  Ntaus_(0),
  PU_NumInteractions_(0),
  PU_TrueNumInteractions_(0),
  PU_bunchCrossing_(0),
  PU_ntrks_highpT_(0),
  PU_ntrks_lowpT_(0),
  PU_sumpT_highpT_(0),
  PU_sumpT_lowpT_(0),
  PU_zpositions_(0),
  beamSpot_beamWidthX_(0),
  beamSpot_beamWidthXError_(0),
  beamSpot_beamWidthY_(0),
  beamSpot_beamWidthYError_(0),
  beamSpot_dxdz_(0),
  beamSpot_dxdzError_(0),
  beamSpot_dydz_(0),
  beamSpot_dydzError_(0),
  beamSpot_sigmaZ_(0),
  beamSpot_sigmaZ0Error_(0),
  beamSpot_x_(0),
  beamSpot_x0Error_(0),
  beamSpot_y_(0),
  beamSpot_y0Error_(0),
  beamSpot_z_(0),
  beamSpot_z0Error_(0),
  bunchCrossing_(0),
  cschalofilter_decision_(0),
  ecallaserfilter_decision_(0),
  eebadscfilter_decision_(0),
  els_PATpassConversionVeto_(0),
  els_basicClustersSize_(0),
  els_cIso_(0),
  els_caloEnergy_(0),
  els_charge_(0),
  els_chi2_(0),
  els_core_ecalDrivenSeed_(0),
  els_cpx_(0),
  els_cpy_(0),
  els_cpz_(0),
  els_ctf_tk_charge_(0),
  els_ctf_tk_eta_(0),
  els_ctf_tk_id_(0),
  els_ctf_tk_phi_(0),
  els_cx_(0),
  els_cy_(0),
  els_cz_(0),
  els_d0dum_(0),
  els_d0dumError_(0),
  els_dEtaIn_(0),
  els_dEtaOut_(0),
  els_dPhiIn_(0),
  els_dPhiOut_(0),
  els_dr03EcalRecHitSumEt_(0),
  els_dr03HcalDepth1TowerSumEt_(0),
  els_dr03HcalDepth2TowerSumEt_(0),
  els_dr03HcalTowerSumEt_(0),
  els_dr03TkSumPt_(0),
  els_dr04EcalRecHitSumEt_(0),
  els_dr04HcalDepth1TowerSumEt_(0),
  els_dr04HcalDepth2TowerSumEt_(0),
  els_dr04HcalTowerSumEt_(0),
  els_dr04TkSumPt_(0),
  els_dz_(0),
  els_dzError_(0),
  els_eOverPIn_(0),
  els_eSeedOverPOut_(0),
  els_ecalIso_(0),
  els_energy_(0),
  els_et_(0),
  els_eta_(0),
  els_etaError_(0),
  els_fbrem_(0),
  els_full5x5_sigmaIetaIeta_(0),
  els_gen_et_(0),
  els_gen_eta_(0),
  els_gen_id_(0),
  els_gen_mother_et_(0),
  els_gen_mother_eta_(0),
  els_gen_mother_id_(0),
  els_gen_mother_phi_(0),
  els_gen_mother_pt_(0),
  els_gen_mother_px_(0),
  els_gen_mother_py_(0),
  els_gen_mother_pz_(0),
  els_gen_mother_theta_(0),
  els_gen_phi_(0),
  els_gen_pt_(0),
  els_gen_px_(0),
  els_gen_py_(0),
  els_gen_pz_(0),
  els_gen_theta_(0),
  els_hadOverEm_(0),
  els_hcalIso_(0),
  els_hcalOverEcalBc_(0),
  els_isEB_(0),
  els_isEE_(0),
  els_isPF_(0),
  els_jet_ind_(0),
  els_looseId_(0),
  els_n_inner_layer_(0),
  els_n_outer_layer_(0),
  els_ndof_(0),
  els_numlosthits_(0),
  els_numvalhits_(0),
  els_pfIsolationR03_sumChargedHadronPt_(0),
  els_pfIsolationR03_sumNeutralHadronEt_(0),
  els_pfIsolationR03_sumPUPt_(0),
  els_pfIsolationR03_sumPhotonEt_(0),
  els_phi_(0),
  els_phiError_(0),
  els_pt_(0),
  els_ptError_(0),
  els_px_(0),
  els_py_(0),
  els_pz_(0),
  els_robustHighEnergyId_(0),
  els_robustLooseId_(0),
  els_robustTightId_(0),
  els_scE1x5_(0),
  els_scE2x5Max_(0),
  els_scE5x5_(0),
  els_scEnergy_(0),
  els_scEta_(0),
  els_scEtaWidth_(0),
  els_scPhi_(0),
  els_scPhiWidth_(0),
  els_scRawEnergy_(0),
  els_scSeedEnergy_(0),
  els_shFracInnerHits_(0),
  els_sigmaEtaEta_(0),
  els_sigmaIEtaIEta_(0),
  els_simpleEleId60cIso_(0),
  els_simpleEleId60relIso_(0),
  els_simpleEleId70cIso_(0),
  els_simpleEleId70relIso_(0),
  els_simpleEleId80cIso_(0),
  els_simpleEleId80relIso_(0),
  els_simpleEleId85cIso_(0),
  els_simpleEleId85relIso_(0),
  els_simpleEleId90cIso_(0),
  els_simpleEleId90relIso_(0),
  els_simpleEleId95cIso_(0),
  els_simpleEleId95relIso_(0),
  els_status_(0),
  els_tIso_(0),
  els_theta_(0),
  els_tightId_(0),
  els_tk_charge_(0),
  els_tk_eta_(0),
  els_tk_phi_(0),
  els_tk_pt_(0),
  els_tk_pz_(0),
  els_vpx_(0),
  els_vpy_(0),
  els_vpz_(0),
  els_vx_(0),
  els_vy_(0),
  els_vz_(0),
  event_(0),
  experimentType_(0),
  fastjets_AK4_R1p2_R0p5pT10_energy_(0),
  fastjets_AK4_R1p2_R0p5pT10_eta_(0),
  fastjets_AK4_R1p2_R0p5pT10_index_(0),
  fastjets_AK4_R1p2_R0p5pT10_nconstituents_(0),
  fastjets_AK4_R1p2_R0p5pT10_phi_(0),
  fastjets_AK4_R1p2_R0p5pT10_px_(0),
  fastjets_AK4_R1p2_R0p5pT10_py_(0),
  fastjets_AK4_R1p2_R0p5pT10_pz_(0),
  fastjets_AK4_R1p2_R0p5pT15_energy_(0),
  fastjets_AK4_R1p2_R0p5pT15_eta_(0),
  fastjets_AK4_R1p2_R0p5pT15_index_(0),
  fastjets_AK4_R1p2_R0p5pT15_nconstituents_(0),
  fastjets_AK4_R1p2_R0p5pT15_phi_(0),
  fastjets_AK4_R1p2_R0p5pT15_px_(0),
  fastjets_AK4_R1p2_R0p5pT15_py_(0),
  fastjets_AK4_R1p2_R0p5pT15_pz_(0),
  fastjets_AK4_R1p2_R0p5pT20_energy_(0),
  fastjets_AK4_R1p2_R0p5pT20_eta_(0),
  fastjets_AK4_R1p2_R0p5pT20_index_(0),
  fastjets_AK4_R1p2_R0p5pT20_nconstituents_(0),
  fastjets_AK4_R1p2_R0p5pT20_phi_(0),
  fastjets_AK4_R1p2_R0p5pT20_px_(0),
  fastjets_AK4_R1p2_R0p5pT20_py_(0),
  fastjets_AK4_R1p2_R0p5pT20_pz_(0),
  fastjets_AK4_R1p2_R0p5pT25_energy_(0),
  fastjets_AK4_R1p2_R0p5pT25_eta_(0),
  fastjets_AK4_R1p2_R0p5pT25_index_(0),
  fastjets_AK4_R1p2_R0p5pT25_nconstituents_(0),
  fastjets_AK4_R1p2_R0p5pT25_phi_(0),
  fastjets_AK4_R1p2_R0p5pT25_px_(0),
  fastjets_AK4_R1p2_R0p5pT25_py_(0),
  fastjets_AK4_R1p2_R0p5pT25_pz_(0),
  fastjets_AK4_R1p2_R0p5pT30_energy_(0),
  fastjets_AK4_R1p2_R0p5pT30_eta_(0),
  fastjets_AK4_R1p2_R0p5pT30_index_(0),
  fastjets_AK4_R1p2_R0p5pT30_nconstituents_(0),
  fastjets_AK4_R1p2_R0p5pT30_phi_(0),
  fastjets_AK4_R1p2_R0p5pT30_px_(0),
  fastjets_AK4_R1p2_R0p5pT30_py_(0),
  fastjets_AK4_R1p2_R0p5pT30_pz_(0),
  goodVerticesfilter_decision_(0),
  hcallaserfilter_decision_(0),
  jets_AK4_area_(0),
  jets_AK4_btag_TC_highEff_(0),
  jets_AK4_btag_TC_highPur_(0),
  jets_AK4_btag_jetBProb_(0),
  jets_AK4_btag_jetProb_(0),
  jets_AK4_btag_secVertexCombined_(0),
  jets_AK4_btag_secVertexHighEff_(0),
  jets_AK4_btag_secVertexHighPur_(0),
  jets_AK4_btag_softEle_(0),
  jets_AK4_btag_softMuon_(0),
  jets_AK4_chgEmE_(0),
  jets_AK4_chgHadE_(0),
  jets_AK4_chgMuE_(0),
  jets_AK4_chg_Mult_(0),
  jets_AK4_corrFactorRaw_(0),
  jets_AK4_ehf_(0),
  jets_AK4_el_ind_(0),
  jets_AK4_emf_(0),
  jets_AK4_energy_(0),
  jets_AK4_et_(0),
  jets_AK4_eta_(0),
  jets_AK4_etaetaMoment_(0),
  jets_AK4_etaphiMoment_(0),
  jets_AK4_fHPD_(0),
  jets_AK4_fRBX_(0),
  jets_AK4_fSubDetector1_(0),
  jets_AK4_fSubDetector2_(0),
  jets_AK4_fSubDetector3_(0),
  jets_AK4_fSubDetector4_(0),
  jets_AK4_gen_Energy_(0),
  jets_AK4_gen_Id_(0),
  jets_AK4_gen_et_(0),
  jets_AK4_gen_eta_(0),
  jets_AK4_gen_mass_(0),
  jets_AK4_gen_motherID_(0),
  jets_AK4_gen_phi_(0),
  jets_AK4_gen_pt_(0),
  jets_AK4_gen_threeCharge_(0),
  jets_AK4_hitsInN90_(0),
  jets_AK4_jetCharge_(0),
  jets_AK4_mass_(0),
  jets_AK4_maxpt_id_(0),
  jets_AK4_mu_Mult_(0),
  jets_AK4_mu_ind_(0),
  jets_AK4_n60_(0),
  jets_AK4_n90_(0),
  jets_AK4_n90Hits_(0),
  jets_AK4_nECALTowers_(0),
  jets_AK4_nHCALTowers_(0),
  jets_AK4_neutralEmE_(0),
  jets_AK4_neutralHadE_(0),
  jets_AK4_neutral_Mult_(0),
  jets_AK4_partonFlavour_(0),
  jets_AK4_parton_Energy_(0),
  jets_AK4_parton_Id_(0),
  jets_AK4_parton_eta_(0),
  jets_AK4_parton_mass_(0),
  jets_AK4_parton_motherId_(0),
  jets_AK4_parton_phi_(0),
  jets_AK4_parton_pt_(0),
  jets_AK4_phi_(0),
  jets_AK4_phiphiMoment_(0),
  jets_AK4_photonEnergy_(0),
  jets_AK4_pt_(0),
  jets_AK4_px_(0),
  jets_AK4_py_(0),
  jets_AK4_pz_(0),
  jets_AK4_rawPt_(0),
  jets_AK4_status_(0),
  jets_AK4_theta_(0),
  lumiblock_(0),
  mc_doc_charge_(0),
  mc_doc_energy_(0),
  mc_doc_eta_(0),
  mc_doc_ggrandmother_id_(0),
  mc_doc_grandmother_id_(0),
  mc_doc_id_(0),
  mc_doc_mass_(0),
  mc_doc_mother_id_(0),
  mc_doc_mother_pt_(0),
  mc_doc_numOfDaughters_(0),
  mc_doc_numOfMothers_(0),
  mc_doc_phi_(0),
  mc_doc_pt_(0),
  mc_doc_px_(0),
  mc_doc_py_(0),
  mc_doc_pz_(0),
  mc_doc_status_(0),
  mc_doc_theta_(0),
  mc_doc_vertex_x_(0),
  mc_doc_vertex_y_(0),
  mc_doc_vertex_z_(0),
  mc_electrons_charge_(0),
  mc_electrons_energy_(0),
  mc_electrons_eta_(0),
  mc_electrons_ggrandmother_id_(0),
  mc_electrons_grandmother_id_(0),
  mc_electrons_id_(0),
  mc_electrons_mass_(0),
  mc_electrons_mother_id_(0),
  mc_electrons_mother_pt_(0),
  mc_electrons_numOfDaughters_(0),
  mc_electrons_phi_(0),
  mc_electrons_pt_(0),
  mc_electrons_px_(0),
  mc_electrons_py_(0),
  mc_electrons_pz_(0),
  mc_electrons_status_(0),
  mc_electrons_theta_(0),
  mc_electrons_vertex_x_(0),
  mc_electrons_vertex_y_(0),
  mc_electrons_vertex_z_(0),
  mc_final_charge_(0),
  mc_final_energy_(0),
  mc_final_eta_(0),
  mc_final_ggrandmother_id_(0),
  mc_final_grandmother_id_(0),
  mc_final_id_(0),
  mc_final_mass_(0),
  mc_final_mother_id_(0),
  mc_final_mother_pt_(0),
  mc_final_numOfDaughters_(0),
  mc_final_numOfMothers_(0),
  mc_final_phi_(0),
  mc_final_pt_(0),
  mc_final_px_(0),
  mc_final_py_(0),
  mc_final_pz_(0),
  mc_final_status_(0),
  mc_final_theta_(0),
  mc_final_vertex_x_(0),
  mc_final_vertex_y_(0),
  mc_final_vertex_z_(0),
  mc_jets_auxiliaryEnergy_(0),
  mc_jets_emEnergy_(0),
  mc_jets_energy_(0),
  mc_jets_et_(0),
  mc_jets_eta_(0),
  mc_jets_etaetaMoment_(0),
  mc_jets_etaphiMoment_(0),
  mc_jets_hadEnergy_(0),
  mc_jets_invisibleEnergy_(0),
  mc_jets_mass_(0),
  mc_jets_phi_(0),
  mc_jets_phiphiMoment_(0),
  mc_jets_pt_(0),
  mc_jets_px_(0),
  mc_jets_py_(0),
  mc_jets_pz_(0),
  mc_jets_theta_(0),
  mc_mus_charge_(0),
  mc_mus_energy_(0),
  mc_mus_eta_(0),
  mc_mus_ggrandmother_id_(0),
  mc_mus_grandmother_id_(0),
  mc_mus_id_(0),
  mc_mus_mass_(0),
  mc_mus_mother_id_(0),
  mc_mus_mother_pt_(0),
  mc_mus_numOfDaughters_(0),
  mc_mus_phi_(0),
  mc_mus_pt_(0),
  mc_mus_px_(0),
  mc_mus_py_(0),
  mc_mus_pz_(0),
  mc_mus_status_(0),
  mc_mus_theta_(0),
  mc_mus_vertex_x_(0),
  mc_mus_vertex_y_(0),
  mc_mus_vertex_z_(0),
  mc_nues_charge_(0),
  mc_nues_energy_(0),
  mc_nues_eta_(0),
  mc_nues_ggrandmother_id_(0),
  mc_nues_grandmother_id_(0),
  mc_nues_id_(0),
  mc_nues_mass_(0),
  mc_nues_mother_id_(0),
  mc_nues_mother_pt_(0),
  mc_nues_numOfDaughters_(0),
  mc_nues_phi_(0),
  mc_nues_pt_(0),
  mc_nues_px_(0),
  mc_nues_py_(0),
  mc_nues_pz_(0),
  mc_nues_status_(0),
  mc_nues_theta_(0),
  mc_nues_vertex_x_(0),
  mc_nues_vertex_y_(0),
  mc_nues_vertex_z_(0),
  mc_numus_charge_(0),
  mc_numus_energy_(0),
  mc_numus_eta_(0),
  mc_numus_ggrandmother_id_(0),
  mc_numus_grandmother_id_(0),
  mc_numus_id_(0),
  mc_numus_mass_(0),
  mc_numus_mother_id_(0),
  mc_numus_mother_pt_(0),
  mc_numus_numOfDaughters_(0),
  mc_numus_phi_(0),
  mc_numus_pt_(0),
  mc_numus_px_(0),
  mc_numus_py_(0),
  mc_numus_pz_(0),
  mc_numus_status_(0),
  mc_numus_theta_(0),
  mc_numus_vertex_x_(0),
  mc_numus_vertex_y_(0),
  mc_numus_vertex_z_(0),
  mc_nutaus_charge_(0),
  mc_nutaus_energy_(0),
  mc_nutaus_eta_(0),
  mc_nutaus_ggrandmother_id_(0),
  mc_nutaus_grandmother_id_(0),
  mc_nutaus_id_(0),
  mc_nutaus_mass_(0),
  mc_nutaus_mother_id_(0),
  mc_nutaus_mother_pt_(0),
  mc_nutaus_numOfDaughters_(0),
  mc_nutaus_phi_(0),
  mc_nutaus_pt_(0),
  mc_nutaus_px_(0),
  mc_nutaus_py_(0),
  mc_nutaus_pz_(0),
  mc_nutaus_status_(0),
  mc_nutaus_theta_(0),
  mc_nutaus_vertex_x_(0),
  mc_nutaus_vertex_y_(0),
  mc_nutaus_vertex_z_(0),
  mc_photons_charge_(0),
  mc_photons_energy_(0),
  mc_photons_eta_(0),
  mc_photons_ggrandmother_id_(0),
  mc_photons_grandmother_id_(0),
  mc_photons_id_(0),
  mc_photons_mass_(0),
  mc_photons_mother_id_(0),
  mc_photons_mother_pt_(0),
  mc_photons_numOfDaughters_(0),
  mc_photons_phi_(0),
  mc_photons_pt_(0),
  mc_photons_px_(0),
  mc_photons_py_(0),
  mc_photons_pz_(0),
  mc_photons_status_(0),
  mc_photons_theta_(0),
  mc_photons_vertex_x_(0),
  mc_photons_vertex_y_(0),
  mc_photons_vertex_z_(0),
  mc_taus_charge_(0),
  mc_taus_energy_(0),
  mc_taus_eta_(0),
  mc_taus_ggrandmother_id_(0),
  mc_taus_grandmother_id_(0),
  mc_taus_id_(0),
  mc_taus_mass_(0),
  mc_taus_mother_id_(0),
  mc_taus_mother_pt_(0),
  mc_taus_numOfDaughters_(0),
  mc_taus_phi_(0),
  mc_taus_pt_(0),
  mc_taus_px_(0),
  mc_taus_py_(0),
  mc_taus_pz_(0),
  mc_taus_status_(0),
  mc_taus_theta_(0),
  mc_taus_vertex_x_(0),
  mc_taus_vertex_y_(0),
  mc_taus_vertex_z_(0),
  mets_et_(0),
  mets_ex_(0),
  mets_ey_(0),
  mets_gen_et_(0),
  mets_gen_phi_(0),
  mets_phi_(0),
  mets_sign_(0),
  mets_sumEt_(0),
  mets_unCPhi_(0),
  mets_unCPt_(0),
  model_params_(0),
  mus_cIso_(0),
  mus_calEnergyEm_(0),
  mus_calEnergyEmS9_(0),
  mus_calEnergyHad_(0),
  mus_calEnergyHadS9_(0),
  mus_calEnergyHo_(0),
  mus_calEnergyHoS9_(0),
  mus_charge_(0),
  mus_cm_ExpectedHitsInner_(0),
  mus_cm_ExpectedHitsOuter_(0),
  mus_cm_LayersWithMeasurement_(0),
  mus_cm_LayersWithoutMeasurement_(0),
  mus_cm_PixelLayersWithMeasurement_(0),
  mus_cm_ValidStripLayersWithMonoAndStereoHit_(0),
  mus_cm_chg_(0),
  mus_cm_chi2_(0),
  mus_cm_d0dum_(0),
  mus_cm_d0dumErr_(0),
  mus_cm_dz_(0),
  mus_cm_dzErr_(0),
  mus_cm_eta_(0),
  mus_cm_etaErr_(0),
  mus_cm_ndof_(0),
  mus_cm_numlosthits_(0),
  mus_cm_numvalMuonhits_(0),
  mus_cm_numvalhits_(0),
  mus_cm_phi_(0),
  mus_cm_phiErr_(0),
  mus_cm_pt_(0),
  mus_cm_ptErr_(0),
  mus_cm_px_(0),
  mus_cm_py_(0),
  mus_cm_pz_(0),
  mus_cm_theta_(0),
  mus_cm_vx_(0),
  mus_cm_vy_(0),
  mus_cm_vz_(0),
  mus_dB_(0),
  mus_ecalIso_(0),
  mus_ecalvetoDep_(0),
  mus_energy_(0),
  mus_et_(0),
  mus_eta_(0),
  mus_gen_et_(0),
  mus_gen_eta_(0),
  mus_gen_id_(0),
  mus_gen_mother_et_(0),
  mus_gen_mother_eta_(0),
  mus_gen_mother_id_(0),
  mus_gen_mother_phi_(0),
  mus_gen_mother_pt_(0),
  mus_gen_mother_px_(0),
  mus_gen_mother_py_(0),
  mus_gen_mother_pz_(0),
  mus_gen_mother_theta_(0),
  mus_gen_phi_(0),
  mus_gen_pt_(0),
  mus_gen_px_(0),
  mus_gen_py_(0),
  mus_gen_pz_(0),
  mus_gen_theta_(0),
  mus_hcalIso_(0),
  mus_hcalvetoDep_(0),
  mus_id_All_(0),
  mus_id_AllArbitrated_(0),
  mus_id_AllGlobalMuons_(0),
  mus_id_AllStandAloneMuons_(0),
  mus_id_AllTrackerMuons_(0),
  mus_id_GlobalMuonPromptTight_(0),
  mus_id_TM2DCompatibilityLoose_(0),
  mus_id_TM2DCompatibilityTight_(0),
  mus_id_TMLastStationLoose_(0),
  mus_id_TMLastStationOptimizedLowPtLoose_(0),
  mus_id_TMLastStationOptimizedLowPtTight_(0),
  mus_id_TMLastStationTight_(0),
  mus_id_TMOneStationLoose_(0),
  mus_id_TMOneStationTight_(0),
  mus_id_TrackerMuonArbitrated_(0),
  mus_isCaloMuon_(0),
  mus_isConvertedPhoton_(0),
  mus_isElectron_(0),
  mus_isGlobalMuon_(0),
  mus_isPF_(0),
  mus_isPFMuon_(0),
  mus_isPhoton_(0),
  mus_isStandAloneMuon_(0),
  mus_isTrackerMuon_(0),
  mus_iso03_emEt_(0),
  mus_iso03_emVetoEt_(0),
  mus_iso03_hadEt_(0),
  mus_iso03_hadVetoEt_(0),
  mus_iso03_hoEt_(0),
  mus_iso03_nTracks_(0),
  mus_iso03_sumPt_(0),
  mus_iso05_emEt_(0),
  mus_iso05_hadEt_(0),
  mus_iso05_hoEt_(0),
  mus_iso05_nTracks_(0),
  mus_iso05_sumPt_(0),
  mus_jet_ind_(0),
  mus_num_matches_(0),
  mus_numberOfMatchedStations_(0),
  mus_pfIsolationR03_sumChargedHadronPt_(0),
  mus_pfIsolationR03_sumChargedParticlePt_(0),
  mus_pfIsolationR03_sumNeutralHadronEt_(0),
  mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_(0),
  mus_pfIsolationR03_sumPUPt_(0),
  mus_pfIsolationR03_sumPhotonEt_(0),
  mus_pfIsolationR03_sumPhotonEtHighThreshold_(0),
  mus_pfIsolationR04_sumChargedHadronPt_(0),
  mus_pfIsolationR04_sumChargedParticlePt_(0),
  mus_pfIsolationR04_sumNeutralHadronEt_(0),
  mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_(0),
  mus_pfIsolationR04_sumPUPt_(0),
  mus_pfIsolationR04_sumPhotonEt_(0),
  mus_pfIsolationR04_sumPhotonEtHighThreshold_(0),
  mus_phi_(0),
  mus_picky_ExpectedHitsInner_(0),
  mus_picky_ExpectedHitsOuter_(0),
  mus_picky_LayersWithMeasurement_(0),
  mus_picky_LayersWithoutMeasurement_(0),
  mus_picky_PixelLayersWithMeasurement_(0),
  mus_picky_ValidStripLayersWithMonoAndStereoHit_(0),
  mus_picky_chg_(0),
  mus_picky_chi2_(0),
  mus_picky_d0dum_(0),
  mus_picky_d0dumErr_(0),
  mus_picky_dz_(0),
  mus_picky_dzErr_(0),
  mus_picky_eta_(0),
  mus_picky_etaErr_(0),
  mus_picky_id_(0),
  mus_picky_ndof_(0),
  mus_picky_numlosthits_(0),
  mus_picky_numvalPixelhits_(0),
  mus_picky_numvalhits_(0),
  mus_picky_phi_(0),
  mus_picky_phiErr_(0),
  mus_picky_pt_(0),
  mus_picky_ptErr_(0),
  mus_picky_px_(0),
  mus_picky_py_(0),
  mus_picky_pz_(0),
  mus_picky_theta_(0),
  mus_picky_vx_(0),
  mus_picky_vy_(0),
  mus_picky_vz_(0),
  mus_pt_(0),
  mus_px_(0),
  mus_py_(0),
  mus_pz_(0),
  mus_stamu_chg_(0),
  mus_stamu_chi2_(0),
  mus_stamu_d0dum_(0),
  mus_stamu_d0dumErr_(0),
  mus_stamu_dz_(0),
  mus_stamu_dzErr_(0),
  mus_stamu_eta_(0),
  mus_stamu_etaErr_(0),
  mus_stamu_ndof_(0),
  mus_stamu_numlosthits_(0),
  mus_stamu_numvalhits_(0),
  mus_stamu_phi_(0),
  mus_stamu_phiErr_(0),
  mus_stamu_pt_(0),
  mus_stamu_ptErr_(0),
  mus_stamu_px_(0),
  mus_stamu_py_(0),
  mus_stamu_pz_(0),
  mus_stamu_theta_(0),
  mus_stamu_vx_(0),
  mus_stamu_vy_(0),
  mus_stamu_vz_(0),
  mus_status_(0),
  mus_tIso_(0),
  mus_theta_(0),
  mus_tkHits_(0),
  mus_tk_ExpectedHitsInner_(0),
  mus_tk_ExpectedHitsOuter_(0),
  mus_tk_LayersWithMeasurement_(0),
  mus_tk_LayersWithoutMeasurement_(0),
  mus_tk_PixelLayersWithMeasurement_(0),
  mus_tk_ValidStripLayersWithMonoAndStereoHit_(0),
  mus_tk_chg_(0),
  mus_tk_chi2_(0),
  mus_tk_d0dum_(0),
  mus_tk_d0dumErr_(0),
  mus_tk_dz_(0),
  mus_tk_dzErr_(0),
  mus_tk_eta_(0),
  mus_tk_etaErr_(0),
  mus_tk_id_(0),
  mus_tk_ndof_(0),
  mus_tk_numlosthits_(0),
  mus_tk_numpixelWthMeasr_(0),
  mus_tk_numvalPixelhits_(0),
  mus_tk_numvalhits_(0),
  mus_tk_phi_(0),
  mus_tk_phiErr_(0),
  mus_tk_pt_(0),
  mus_tk_ptErr_(0),
  mus_tk_px_(0),
  mus_tk_py_(0),
  mus_tk_pz_(0),
  mus_tk_theta_(0),
  mus_tk_vx_(0),
  mus_tk_vy_(0),
  mus_tk_vz_(0),
  mus_tpfms_ExpectedHitsInner_(0),
  mus_tpfms_ExpectedHitsOuter_(0),
  mus_tpfms_LayersWithMeasurement_(0),
  mus_tpfms_LayersWithoutMeasurement_(0),
  mus_tpfms_PixelLayersWithMeasurement_(0),
  mus_tpfms_ValidStripLayersWithMonoAndStereoHit_(0),
  mus_tpfms_chg_(0),
  mus_tpfms_chi2_(0),
  mus_tpfms_d0dum_(0),
  mus_tpfms_d0dumErr_(0),
  mus_tpfms_dz_(0),
  mus_tpfms_dzErr_(0),
  mus_tpfms_eta_(0),
  mus_tpfms_etaErr_(0),
  mus_tpfms_id_(0),
  mus_tpfms_ndof_(0),
  mus_tpfms_numlosthits_(0),
  mus_tpfms_numvalPixelhits_(0),
  mus_tpfms_numvalhits_(0),
  mus_tpfms_phi_(0),
  mus_tpfms_phiErr_(0),
  mus_tpfms_pt_(0),
  mus_tpfms_ptErr_(0),
  mus_tpfms_px_(0),
  mus_tpfms_py_(0),
  mus_tpfms_pz_(0),
  mus_tpfms_theta_(0),
  mus_tpfms_vx_(0),
  mus_tpfms_vy_(0),
  mus_tpfms_vz_(0),
  orbitNumber_(0),
  pfcand_charge_(0),
  pfcand_energy_(0),
  pfcand_eta_(0),
  pfcand_pdgId_(0),
  pfcand_phi_(0),
  pfcand_pt_(0),
  pfcand_px_(0),
  pfcand_py_(0),
  pfcand_pz_(0),
  pfcand_theta_(0),
  photons_e1x5_(0),
  photons_e2x5_(0),
  photons_e3x3_(0),
  photons_e5x5_(0),
  photons_ecalIso_(0),
  photons_energy_(0),
  photons_et_(0),
  photons_eta_(0),
  photons_gen_et_(0),
  photons_gen_eta_(0),
  photons_gen_id_(0),
  photons_gen_phi_(0),
  photons_hadOverEM_(0),
  photons_hadTowOverEM_(0),
  photons_hasPixelSeed_(0),
  photons_hcalIso_(0),
  photons_isAlsoElectron_(0),
  photons_isConverted_(0),
  photons_isEBEEGap_(0),
  photons_isEBGap_(0),
  photons_isEBPho_(0),
  photons_isEEGap_(0),
  photons_isEEPho_(0),
  photons_isLoosePhoton_(0),
  photons_isTightPhoton_(0),
  photons_isoEcalRecHitDR03_(0),
  photons_isoEcalRecHitDR04_(0),
  photons_isoHcalRecHitDR03_(0),
  photons_isoHcalRecHitDR04_(0),
  photons_isoHollowTrkConeDR03_(0),
  photons_isoHollowTrkConeDR04_(0),
  photons_isoSolidTrkConeDR03_(0),
  photons_isoSolidTrkConeDR04_(0),
  photons_maxEnergyXtal_(0),
  photons_nTrkHollowConeDR03_(0),
  photons_nTrkHollowConeDR04_(0),
  photons_nTrkSolidConeDR03_(0),
  photons_nTrkSolidConeDR04_(0),
  photons_phi_(0),
  photons_pt_(0),
  photons_px_(0),
  photons_py_(0),
  photons_pz_(0),
  photons_r9_(0),
  photons_scEnergy_(0),
  photons_scEta_(0),
  photons_scEtaWidth_(0),
  photons_scPhi_(0),
  photons_scPhiWidth_(0),
  photons_scRawEnergy_(0),
  photons_sigmaEtaEta_(0),
  photons_sigmaIetaIeta_(0),
  photons_status_(0),
  photons_tIso_(0),
  photons_theta_(0),
  pv_chi2_(0),
  pv_isFake_(0),
  pv_isValid_(0),
  pv_ndof_(0),
  pv_tracksSize_(0),
  pv_x_(0),
  pv_xErr_(0),
  pv_y_(0),
  pv_yErr_(0),
  pv_z_(0),
  pv_zErr_(0),
  run_(0),
  standalone_triggerobject_collectionname_(0),
  standalone_triggerobject_energy_(0),
  standalone_triggerobject_et_(0),
  standalone_triggerobject_eta_(0),
  standalone_triggerobject_phi_(0),
  standalone_triggerobject_pt_(0),
  standalone_triggerobject_px_(0),
  standalone_triggerobject_py_(0),
  standalone_triggerobject_pz_(0),
  taus_Nprongs_(0),
  taus_againstElectron_(0),
  taus_againstElectronLoose_(0),
  taus_againstElectronMVA_(0),
  taus_againstElectronMedium_(0),
  taus_againstElectronTight_(0),
  taus_againstMuon_(0),
  taus_againstMuonLoose_(0),
  taus_againstMuonMedium_(0),
  taus_againstMuonTight_(0),
  taus_byIsoUsingLeadingPi_(0),
  taus_byIsolation_(0),
  taus_byLooseIsolation_(0),
  taus_byLooseIsolationDeltaBetaCorr_(0),
  taus_byMediumIsolation_(0),
  taus_byMediumIsolationDeltaBetaCorr_(0),
  taus_byTightIsolation_(0),
  taus_byTightIsolationDeltaBetaCorr_(0),
  taus_byVLooseIsolation_(0),
  taus_byVLooseIsolationDeltaBetaCorr_(0),
  taus_charge_(0),
  taus_decayModeFinding_(0),
  taus_ecalIsoUsingLeadingPi_(0),
  taus_ecalIsolation_(0),
  taus_ecalStripSumEOverPLead_(0),
  taus_el_ind_(0),
  taus_elecPreIdDecision_(0),
  taus_elecPreIdOutput_(0),
  taus_emf_(0),
  taus_energy_(0),
  taus_et_(0),
  taus_eta_(0),
  taus_hcal3x3OverPLead_(0),
  taus_hcalMaxOverPLead_(0),
  taus_hcalTotOverPLead_(0),
  taus_isoPFChargedHadrCandsPtSum_(0),
  taus_isoPFGammaCandsEtSum_(0),
  taus_leadPFChargedHadrCand_ECAL_eta_(0),
  taus_leadPFChargedHadrCand_charge_(0),
  taus_leadPFChargedHadrCand_eta_(0),
  taus_leadPFChargedHadrCand_phi_(0),
  taus_leadPFChargedHadrCand_pt_(0),
  taus_leadingTrackFinding_(0),
  taus_leadingTrackPtCut_(0),
  taus_muDecision_(0),
  taus_mu_ind_(0),
  taus_phi_(0),
  taus_pt_(0),
  taus_px_(0),
  taus_py_(0),
  taus_pz_(0),
  taus_signalPFChargedHadrCandsSize_(0),
  taus_status_(0),
  taus_taNC_(0),
  taus_taNC_half_(0),
  taus_taNC_one_(0),
  taus_taNC_quarter_(0),
  taus_taNC_tenth_(0),
  taus_theta_(0),
  taus_tkIsoUsingLeadingPi_(0),
  taus_trackIsolation_(0),
  trackingfailurefilter_decision_(0),
  trigger_decision_(0),
  trigger_name_(0),
  trigger_prescalevalue_(0),
  trkPOG_logErrorTooManyClustersfilter_decision_(0),
  trkPOG_manystripclus53Xfilter_decision_(0),
  trkPOG_toomanystripclus53Xfilter_decision_(0),
  trkPOGfilter_decision_(0),
  weight_(0),
  b_EcalDeadCellTriggerPrimitivefilter_decision_(NULL),
  b_HBHENoisefilter_decision_(NULL),
  b_METFiltersfilter_decision_(NULL),
  b_NbeamSpot_(NULL),
  b_Nels_(NULL),
  b_Njets_AK4_(NULL),
  b_Nmc_doc_(NULL),
  b_Nmc_electrons_(NULL),
  b_Nmc_final_(NULL),
  b_Nmc_jets_(NULL),
  b_Nmc_mus_(NULL),
  b_Nmc_nues_(NULL),
  b_Nmc_numus_(NULL),
  b_Nmc_nutaus_(NULL),
  b_Nmc_photons_(NULL),
  b_Nmc_taus_(NULL),
  b_Nmets_(NULL),
  b_Nmus_(NULL),
  b_Npfcand_(NULL),
  b_Nphotons_(NULL),
  b_Npv_(NULL),
  b_Ntaus_(NULL),
  b_PU_NumInteractions_(NULL),
  b_PU_TrueNumInteractions_(NULL),
  b_PU_bunchCrossing_(NULL),
  b_PU_ntrks_highpT_(NULL),
  b_PU_ntrks_lowpT_(NULL),
  b_PU_sumpT_highpT_(NULL),
  b_PU_sumpT_lowpT_(NULL),
  b_PU_zpositions_(NULL),
  b_beamSpot_beamWidthX_(NULL),
  b_beamSpot_beamWidthXError_(NULL),
  b_beamSpot_beamWidthY_(NULL),
  b_beamSpot_beamWidthYError_(NULL),
  b_beamSpot_dxdz_(NULL),
  b_beamSpot_dxdzError_(NULL),
  b_beamSpot_dydz_(NULL),
  b_beamSpot_dydzError_(NULL),
  b_beamSpot_sigmaZ_(NULL),
  b_beamSpot_sigmaZ0Error_(NULL),
  b_beamSpot_x_(NULL),
  b_beamSpot_x0Error_(NULL),
  b_beamSpot_y_(NULL),
  b_beamSpot_y0Error_(NULL),
  b_beamSpot_z_(NULL),
  b_beamSpot_z0Error_(NULL),
  b_bunchCrossing_(NULL),
  b_cschalofilter_decision_(NULL),
  b_ecallaserfilter_decision_(NULL),
  b_eebadscfilter_decision_(NULL),
  b_els_PATpassConversionVeto_(NULL),
  b_els_basicClustersSize_(NULL),
  b_els_cIso_(NULL),
  b_els_caloEnergy_(NULL),
  b_els_charge_(NULL),
  b_els_chi2_(NULL),
  b_els_core_ecalDrivenSeed_(NULL),
  b_els_cpx_(NULL),
  b_els_cpy_(NULL),
  b_els_cpz_(NULL),
  b_els_ctf_tk_charge_(NULL),
  b_els_ctf_tk_eta_(NULL),
  b_els_ctf_tk_id_(NULL),
  b_els_ctf_tk_phi_(NULL),
  b_els_cx_(NULL),
  b_els_cy_(NULL),
  b_els_cz_(NULL),
  b_els_d0dum_(NULL),
  b_els_d0dumError_(NULL),
  b_els_dEtaIn_(NULL),
  b_els_dEtaOut_(NULL),
  b_els_dPhiIn_(NULL),
  b_els_dPhiOut_(NULL),
  b_els_dr03EcalRecHitSumEt_(NULL),
  b_els_dr03HcalDepth1TowerSumEt_(NULL),
  b_els_dr03HcalDepth2TowerSumEt_(NULL),
  b_els_dr03HcalTowerSumEt_(NULL),
  b_els_dr03TkSumPt_(NULL),
  b_els_dr04EcalRecHitSumEt_(NULL),
  b_els_dr04HcalDepth1TowerSumEt_(NULL),
  b_els_dr04HcalDepth2TowerSumEt_(NULL),
  b_els_dr04HcalTowerSumEt_(NULL),
  b_els_dr04TkSumPt_(NULL),
  b_els_dz_(NULL),
  b_els_dzError_(NULL),
  b_els_eOverPIn_(NULL),
  b_els_eSeedOverPOut_(NULL),
  b_els_ecalIso_(NULL),
  b_els_energy_(NULL),
  b_els_et_(NULL),
  b_els_eta_(NULL),
  b_els_etaError_(NULL),
  b_els_fbrem_(NULL),
  b_els_full5x5_sigmaIetaIeta_(NULL),
  b_els_gen_et_(NULL),
  b_els_gen_eta_(NULL),
  b_els_gen_id_(NULL),
  b_els_gen_mother_et_(NULL),
  b_els_gen_mother_eta_(NULL),
  b_els_gen_mother_id_(NULL),
  b_els_gen_mother_phi_(NULL),
  b_els_gen_mother_pt_(NULL),
  b_els_gen_mother_px_(NULL),
  b_els_gen_mother_py_(NULL),
  b_els_gen_mother_pz_(NULL),
  b_els_gen_mother_theta_(NULL),
  b_els_gen_phi_(NULL),
  b_els_gen_pt_(NULL),
  b_els_gen_px_(NULL),
  b_els_gen_py_(NULL),
  b_els_gen_pz_(NULL),
  b_els_gen_theta_(NULL),
  b_els_hadOverEm_(NULL),
  b_els_hcalIso_(NULL),
  b_els_hcalOverEcalBc_(NULL),
  b_els_isEB_(NULL),
  b_els_isEE_(NULL),
  b_els_isPF_(NULL),
  b_els_jet_ind_(NULL),
  b_els_looseId_(NULL),
  b_els_n_inner_layer_(NULL),
  b_els_n_outer_layer_(NULL),
  b_els_ndof_(NULL),
  b_els_numlosthits_(NULL),
  b_els_numvalhits_(NULL),
  b_els_pfIsolationR03_sumChargedHadronPt_(NULL),
  b_els_pfIsolationR03_sumNeutralHadronEt_(NULL),
  b_els_pfIsolationR03_sumPUPt_(NULL),
  b_els_pfIsolationR03_sumPhotonEt_(NULL),
  b_els_phi_(NULL),
  b_els_phiError_(NULL),
  b_els_pt_(NULL),
  b_els_ptError_(NULL),
  b_els_px_(NULL),
  b_els_py_(NULL),
  b_els_pz_(NULL),
  b_els_robustHighEnergyId_(NULL),
  b_els_robustLooseId_(NULL),
  b_els_robustTightId_(NULL),
  b_els_scE1x5_(NULL),
  b_els_scE2x5Max_(NULL),
  b_els_scE5x5_(NULL),
  b_els_scEnergy_(NULL),
  b_els_scEta_(NULL),
  b_els_scEtaWidth_(NULL),
  b_els_scPhi_(NULL),
  b_els_scPhiWidth_(NULL),
  b_els_scRawEnergy_(NULL),
  b_els_scSeedEnergy_(NULL),
  b_els_shFracInnerHits_(NULL),
  b_els_sigmaEtaEta_(NULL),
  b_els_sigmaIEtaIEta_(NULL),
  b_els_simpleEleId60cIso_(NULL),
  b_els_simpleEleId60relIso_(NULL),
  b_els_simpleEleId70cIso_(NULL),
  b_els_simpleEleId70relIso_(NULL),
  b_els_simpleEleId80cIso_(NULL),
  b_els_simpleEleId80relIso_(NULL),
  b_els_simpleEleId85cIso_(NULL),
  b_els_simpleEleId85relIso_(NULL),
  b_els_simpleEleId90cIso_(NULL),
  b_els_simpleEleId90relIso_(NULL),
  b_els_simpleEleId95cIso_(NULL),
  b_els_simpleEleId95relIso_(NULL),
  b_els_status_(NULL),
  b_els_tIso_(NULL),
  b_els_theta_(NULL),
  b_els_tightId_(NULL),
  b_els_tk_charge_(NULL),
  b_els_tk_eta_(NULL),
  b_els_tk_phi_(NULL),
  b_els_tk_pt_(NULL),
  b_els_tk_pz_(NULL),
  b_els_vpx_(NULL),
  b_els_vpy_(NULL),
  b_els_vpz_(NULL),
  b_els_vx_(NULL),
  b_els_vy_(NULL),
  b_els_vz_(NULL),
  b_event_(NULL),
  b_experimentType_(NULL),
  b_fastjets_AK4_R1p2_R0p5pT10_energy_(NULL),
  b_fastjets_AK4_R1p2_R0p5pT10_eta_(NULL),
  b_fastjets_AK4_R1p2_R0p5pT10_index_(NULL),
  b_fastjets_AK4_R1p2_R0p5pT10_nconstituents_(NULL),
  b_fastjets_AK4_R1p2_R0p5pT10_phi_(NULL),
  b_fastjets_AK4_R1p2_R0p5pT10_px_(NULL),
  b_fastjets_AK4_R1p2_R0p5pT10_py_(NULL),
  b_fastjets_AK4_R1p2_R0p5pT10_pz_(NULL),
  b_fastjets_AK4_R1p2_R0p5pT15_energy_(NULL),
  b_fastjets_AK4_R1p2_R0p5pT15_eta_(NULL),
  b_fastjets_AK4_R1p2_R0p5pT15_index_(NULL),
  b_fastjets_AK4_R1p2_R0p5pT15_nconstituents_(NULL),
  b_fastjets_AK4_R1p2_R0p5pT15_phi_(NULL),
  b_fastjets_AK4_R1p2_R0p5pT15_px_(NULL),
  b_fastjets_AK4_R1p2_R0p5pT15_py_(NULL),
  b_fastjets_AK4_R1p2_R0p5pT15_pz_(NULL),
  b_fastjets_AK4_R1p2_R0p5pT20_energy_(NULL),
  b_fastjets_AK4_R1p2_R0p5pT20_eta_(NULL),
  b_fastjets_AK4_R1p2_R0p5pT20_index_(NULL),
  b_fastjets_AK4_R1p2_R0p5pT20_nconstituents_(NULL),
  b_fastjets_AK4_R1p2_R0p5pT20_phi_(NULL),
  b_fastjets_AK4_R1p2_R0p5pT20_px_(NULL),
  b_fastjets_AK4_R1p2_R0p5pT20_py_(NULL),
  b_fastjets_AK4_R1p2_R0p5pT20_pz_(NULL),
  b_fastjets_AK4_R1p2_R0p5pT25_energy_(NULL),
  b_fastjets_AK4_R1p2_R0p5pT25_eta_(NULL),
  b_fastjets_AK4_R1p2_R0p5pT25_index_(NULL),
  b_fastjets_AK4_R1p2_R0p5pT25_nconstituents_(NULL),
  b_fastjets_AK4_R1p2_R0p5pT25_phi_(NULL),
  b_fastjets_AK4_R1p2_R0p5pT25_px_(NULL),
  b_fastjets_AK4_R1p2_R0p5pT25_py_(NULL),
  b_fastjets_AK4_R1p2_R0p5pT25_pz_(NULL),
  b_fastjets_AK4_R1p2_R0p5pT30_energy_(NULL),
  b_fastjets_AK4_R1p2_R0p5pT30_eta_(NULL),
  b_fastjets_AK4_R1p2_R0p5pT30_index_(NULL),
  b_fastjets_AK4_R1p2_R0p5pT30_nconstituents_(NULL),
  b_fastjets_AK4_R1p2_R0p5pT30_phi_(NULL),
  b_fastjets_AK4_R1p2_R0p5pT30_px_(NULL),
  b_fastjets_AK4_R1p2_R0p5pT30_py_(NULL),
  b_fastjets_AK4_R1p2_R0p5pT30_pz_(NULL),
  b_goodVerticesfilter_decision_(NULL),
  b_hcallaserfilter_decision_(NULL),
  b_jets_AK4_area_(NULL),
  b_jets_AK4_btag_TC_highEff_(NULL),
  b_jets_AK4_btag_TC_highPur_(NULL),
  b_jets_AK4_btag_jetBProb_(NULL),
  b_jets_AK4_btag_jetProb_(NULL),
  b_jets_AK4_btag_secVertexCombined_(NULL),
  b_jets_AK4_btag_secVertexHighEff_(NULL),
  b_jets_AK4_btag_secVertexHighPur_(NULL),
  b_jets_AK4_btag_softEle_(NULL),
  b_jets_AK4_btag_softMuon_(NULL),
  b_jets_AK4_chgEmE_(NULL),
  b_jets_AK4_chgHadE_(NULL),
  b_jets_AK4_chgMuE_(NULL),
  b_jets_AK4_chg_Mult_(NULL),
  b_jets_AK4_corrFactorRaw_(NULL),
  b_jets_AK4_ehf_(NULL),
  b_jets_AK4_el_ind_(NULL),
  b_jets_AK4_emf_(NULL),
  b_jets_AK4_energy_(NULL),
  b_jets_AK4_et_(NULL),
  b_jets_AK4_eta_(NULL),
  b_jets_AK4_etaetaMoment_(NULL),
  b_jets_AK4_etaphiMoment_(NULL),
  b_jets_AK4_fHPD_(NULL),
  b_jets_AK4_fRBX_(NULL),
  b_jets_AK4_fSubDetector1_(NULL),
  b_jets_AK4_fSubDetector2_(NULL),
  b_jets_AK4_fSubDetector3_(NULL),
  b_jets_AK4_fSubDetector4_(NULL),
  b_jets_AK4_gen_Energy_(NULL),
  b_jets_AK4_gen_Id_(NULL),
  b_jets_AK4_gen_et_(NULL),
  b_jets_AK4_gen_eta_(NULL),
  b_jets_AK4_gen_mass_(NULL),
  b_jets_AK4_gen_motherID_(NULL),
  b_jets_AK4_gen_phi_(NULL),
  b_jets_AK4_gen_pt_(NULL),
  b_jets_AK4_gen_threeCharge_(NULL),
  b_jets_AK4_hitsInN90_(NULL),
  b_jets_AK4_jetCharge_(NULL),
  b_jets_AK4_mass_(NULL),
  b_jets_AK4_maxpt_id_(NULL),
  b_jets_AK4_mu_Mult_(NULL),
  b_jets_AK4_mu_ind_(NULL),
  b_jets_AK4_n60_(NULL),
  b_jets_AK4_n90_(NULL),
  b_jets_AK4_n90Hits_(NULL),
  b_jets_AK4_nECALTowers_(NULL),
  b_jets_AK4_nHCALTowers_(NULL),
  b_jets_AK4_neutralEmE_(NULL),
  b_jets_AK4_neutralHadE_(NULL),
  b_jets_AK4_neutral_Mult_(NULL),
  b_jets_AK4_partonFlavour_(NULL),
  b_jets_AK4_parton_Energy_(NULL),
  b_jets_AK4_parton_Id_(NULL),
  b_jets_AK4_parton_eta_(NULL),
  b_jets_AK4_parton_mass_(NULL),
  b_jets_AK4_parton_motherId_(NULL),
  b_jets_AK4_parton_phi_(NULL),
  b_jets_AK4_parton_pt_(NULL),
  b_jets_AK4_phi_(NULL),
  b_jets_AK4_phiphiMoment_(NULL),
  b_jets_AK4_photonEnergy_(NULL),
  b_jets_AK4_pt_(NULL),
  b_jets_AK4_px_(NULL),
  b_jets_AK4_py_(NULL),
  b_jets_AK4_pz_(NULL),
  b_jets_AK4_rawPt_(NULL),
  b_jets_AK4_status_(NULL),
  b_jets_AK4_theta_(NULL),
  b_lumiblock_(NULL),
  b_mc_doc_charge_(NULL),
  b_mc_doc_energy_(NULL),
  b_mc_doc_eta_(NULL),
  b_mc_doc_ggrandmother_id_(NULL),
  b_mc_doc_grandmother_id_(NULL),
  b_mc_doc_id_(NULL),
  b_mc_doc_mass_(NULL),
  b_mc_doc_mother_id_(NULL),
  b_mc_doc_mother_pt_(NULL),
  b_mc_doc_numOfDaughters_(NULL),
  b_mc_doc_numOfMothers_(NULL),
  b_mc_doc_phi_(NULL),
  b_mc_doc_pt_(NULL),
  b_mc_doc_px_(NULL),
  b_mc_doc_py_(NULL),
  b_mc_doc_pz_(NULL),
  b_mc_doc_status_(NULL),
  b_mc_doc_theta_(NULL),
  b_mc_doc_vertex_x_(NULL),
  b_mc_doc_vertex_y_(NULL),
  b_mc_doc_vertex_z_(NULL),
  b_mc_electrons_charge_(NULL),
  b_mc_electrons_energy_(NULL),
  b_mc_electrons_eta_(NULL),
  b_mc_electrons_ggrandmother_id_(NULL),
  b_mc_electrons_grandmother_id_(NULL),
  b_mc_electrons_id_(NULL),
  b_mc_electrons_mass_(NULL),
  b_mc_electrons_mother_id_(NULL),
  b_mc_electrons_mother_pt_(NULL),
  b_mc_electrons_numOfDaughters_(NULL),
  b_mc_electrons_phi_(NULL),
  b_mc_electrons_pt_(NULL),
  b_mc_electrons_px_(NULL),
  b_mc_electrons_py_(NULL),
  b_mc_electrons_pz_(NULL),
  b_mc_electrons_status_(NULL),
  b_mc_electrons_theta_(NULL),
  b_mc_electrons_vertex_x_(NULL),
  b_mc_electrons_vertex_y_(NULL),
  b_mc_electrons_vertex_z_(NULL),
  b_mc_final_charge_(NULL),
  b_mc_final_energy_(NULL),
  b_mc_final_eta_(NULL),
  b_mc_final_ggrandmother_id_(NULL),
  b_mc_final_grandmother_id_(NULL),
  b_mc_final_id_(NULL),
  b_mc_final_mass_(NULL),
  b_mc_final_mother_id_(NULL),
  b_mc_final_mother_pt_(NULL),
  b_mc_final_numOfDaughters_(NULL),
  b_mc_final_numOfMothers_(NULL),
  b_mc_final_phi_(NULL),
  b_mc_final_pt_(NULL),
  b_mc_final_px_(NULL),
  b_mc_final_py_(NULL),
  b_mc_final_pz_(NULL),
  b_mc_final_status_(NULL),
  b_mc_final_theta_(NULL),
  b_mc_final_vertex_x_(NULL),
  b_mc_final_vertex_y_(NULL),
  b_mc_final_vertex_z_(NULL),
  b_mc_jets_auxiliaryEnergy_(NULL),
  b_mc_jets_emEnergy_(NULL),
  b_mc_jets_energy_(NULL),
  b_mc_jets_et_(NULL),
  b_mc_jets_eta_(NULL),
  b_mc_jets_etaetaMoment_(NULL),
  b_mc_jets_etaphiMoment_(NULL),
  b_mc_jets_hadEnergy_(NULL),
  b_mc_jets_invisibleEnergy_(NULL),
  b_mc_jets_mass_(NULL),
  b_mc_jets_phi_(NULL),
  b_mc_jets_phiphiMoment_(NULL),
  b_mc_jets_pt_(NULL),
  b_mc_jets_px_(NULL),
  b_mc_jets_py_(NULL),
  b_mc_jets_pz_(NULL),
  b_mc_jets_theta_(NULL),
  b_mc_mus_charge_(NULL),
  b_mc_mus_energy_(NULL),
  b_mc_mus_eta_(NULL),
  b_mc_mus_ggrandmother_id_(NULL),
  b_mc_mus_grandmother_id_(NULL),
  b_mc_mus_id_(NULL),
  b_mc_mus_mass_(NULL),
  b_mc_mus_mother_id_(NULL),
  b_mc_mus_mother_pt_(NULL),
  b_mc_mus_numOfDaughters_(NULL),
  b_mc_mus_phi_(NULL),
  b_mc_mus_pt_(NULL),
  b_mc_mus_px_(NULL),
  b_mc_mus_py_(NULL),
  b_mc_mus_pz_(NULL),
  b_mc_mus_status_(NULL),
  b_mc_mus_theta_(NULL),
  b_mc_mus_vertex_x_(NULL),
  b_mc_mus_vertex_y_(NULL),
  b_mc_mus_vertex_z_(NULL),
  b_mc_nues_charge_(NULL),
  b_mc_nues_energy_(NULL),
  b_mc_nues_eta_(NULL),
  b_mc_nues_ggrandmother_id_(NULL),
  b_mc_nues_grandmother_id_(NULL),
  b_mc_nues_id_(NULL),
  b_mc_nues_mass_(NULL),
  b_mc_nues_mother_id_(NULL),
  b_mc_nues_mother_pt_(NULL),
  b_mc_nues_numOfDaughters_(NULL),
  b_mc_nues_phi_(NULL),
  b_mc_nues_pt_(NULL),
  b_mc_nues_px_(NULL),
  b_mc_nues_py_(NULL),
  b_mc_nues_pz_(NULL),
  b_mc_nues_status_(NULL),
  b_mc_nues_theta_(NULL),
  b_mc_nues_vertex_x_(NULL),
  b_mc_nues_vertex_y_(NULL),
  b_mc_nues_vertex_z_(NULL),
  b_mc_numus_charge_(NULL),
  b_mc_numus_energy_(NULL),
  b_mc_numus_eta_(NULL),
  b_mc_numus_ggrandmother_id_(NULL),
  b_mc_numus_grandmother_id_(NULL),
  b_mc_numus_id_(NULL),
  b_mc_numus_mass_(NULL),
  b_mc_numus_mother_id_(NULL),
  b_mc_numus_mother_pt_(NULL),
  b_mc_numus_numOfDaughters_(NULL),
  b_mc_numus_phi_(NULL),
  b_mc_numus_pt_(NULL),
  b_mc_numus_px_(NULL),
  b_mc_numus_py_(NULL),
  b_mc_numus_pz_(NULL),
  b_mc_numus_status_(NULL),
  b_mc_numus_theta_(NULL),
  b_mc_numus_vertex_x_(NULL),
  b_mc_numus_vertex_y_(NULL),
  b_mc_numus_vertex_z_(NULL),
  b_mc_nutaus_charge_(NULL),
  b_mc_nutaus_energy_(NULL),
  b_mc_nutaus_eta_(NULL),
  b_mc_nutaus_ggrandmother_id_(NULL),
  b_mc_nutaus_grandmother_id_(NULL),
  b_mc_nutaus_id_(NULL),
  b_mc_nutaus_mass_(NULL),
  b_mc_nutaus_mother_id_(NULL),
  b_mc_nutaus_mother_pt_(NULL),
  b_mc_nutaus_numOfDaughters_(NULL),
  b_mc_nutaus_phi_(NULL),
  b_mc_nutaus_pt_(NULL),
  b_mc_nutaus_px_(NULL),
  b_mc_nutaus_py_(NULL),
  b_mc_nutaus_pz_(NULL),
  b_mc_nutaus_status_(NULL),
  b_mc_nutaus_theta_(NULL),
  b_mc_nutaus_vertex_x_(NULL),
  b_mc_nutaus_vertex_y_(NULL),
  b_mc_nutaus_vertex_z_(NULL),
  b_mc_photons_charge_(NULL),
  b_mc_photons_energy_(NULL),
  b_mc_photons_eta_(NULL),
  b_mc_photons_ggrandmother_id_(NULL),
  b_mc_photons_grandmother_id_(NULL),
  b_mc_photons_id_(NULL),
  b_mc_photons_mass_(NULL),
  b_mc_photons_mother_id_(NULL),
  b_mc_photons_mother_pt_(NULL),
  b_mc_photons_numOfDaughters_(NULL),
  b_mc_photons_phi_(NULL),
  b_mc_photons_pt_(NULL),
  b_mc_photons_px_(NULL),
  b_mc_photons_py_(NULL),
  b_mc_photons_pz_(NULL),
  b_mc_photons_status_(NULL),
  b_mc_photons_theta_(NULL),
  b_mc_photons_vertex_x_(NULL),
  b_mc_photons_vertex_y_(NULL),
  b_mc_photons_vertex_z_(NULL),
  b_mc_taus_charge_(NULL),
  b_mc_taus_energy_(NULL),
  b_mc_taus_eta_(NULL),
  b_mc_taus_ggrandmother_id_(NULL),
  b_mc_taus_grandmother_id_(NULL),
  b_mc_taus_id_(NULL),
  b_mc_taus_mass_(NULL),
  b_mc_taus_mother_id_(NULL),
  b_mc_taus_mother_pt_(NULL),
  b_mc_taus_numOfDaughters_(NULL),
  b_mc_taus_phi_(NULL),
  b_mc_taus_pt_(NULL),
  b_mc_taus_px_(NULL),
  b_mc_taus_py_(NULL),
  b_mc_taus_pz_(NULL),
  b_mc_taus_status_(NULL),
  b_mc_taus_theta_(NULL),
  b_mc_taus_vertex_x_(NULL),
  b_mc_taus_vertex_y_(NULL),
  b_mc_taus_vertex_z_(NULL),
  b_mets_et_(NULL),
  b_mets_ex_(NULL),
  b_mets_ey_(NULL),
  b_mets_gen_et_(NULL),
  b_mets_gen_phi_(NULL),
  b_mets_phi_(NULL),
  b_mets_sign_(NULL),
  b_mets_sumEt_(NULL),
  b_mets_unCPhi_(NULL),
  b_mets_unCPt_(NULL),
  b_model_params_(NULL),
  b_mus_cIso_(NULL),
  b_mus_calEnergyEm_(NULL),
  b_mus_calEnergyEmS9_(NULL),
  b_mus_calEnergyHad_(NULL),
  b_mus_calEnergyHadS9_(NULL),
  b_mus_calEnergyHo_(NULL),
  b_mus_calEnergyHoS9_(NULL),
  b_mus_charge_(NULL),
  b_mus_cm_ExpectedHitsInner_(NULL),
  b_mus_cm_ExpectedHitsOuter_(NULL),
  b_mus_cm_LayersWithMeasurement_(NULL),
  b_mus_cm_LayersWithoutMeasurement_(NULL),
  b_mus_cm_PixelLayersWithMeasurement_(NULL),
  b_mus_cm_ValidStripLayersWithMonoAndStereoHit_(NULL),
  b_mus_cm_chg_(NULL),
  b_mus_cm_chi2_(NULL),
  b_mus_cm_d0dum_(NULL),
  b_mus_cm_d0dumErr_(NULL),
  b_mus_cm_dz_(NULL),
  b_mus_cm_dzErr_(NULL),
  b_mus_cm_eta_(NULL),
  b_mus_cm_etaErr_(NULL),
  b_mus_cm_ndof_(NULL),
  b_mus_cm_numlosthits_(NULL),
  b_mus_cm_numvalMuonhits_(NULL),
  b_mus_cm_numvalhits_(NULL),
  b_mus_cm_phi_(NULL),
  b_mus_cm_phiErr_(NULL),
  b_mus_cm_pt_(NULL),
  b_mus_cm_ptErr_(NULL),
  b_mus_cm_px_(NULL),
  b_mus_cm_py_(NULL),
  b_mus_cm_pz_(NULL),
  b_mus_cm_theta_(NULL),
  b_mus_cm_vx_(NULL),
  b_mus_cm_vy_(NULL),
  b_mus_cm_vz_(NULL),
  b_mus_dB_(NULL),
  b_mus_ecalIso_(NULL),
  b_mus_ecalvetoDep_(NULL),
  b_mus_energy_(NULL),
  b_mus_et_(NULL),
  b_mus_eta_(NULL),
  b_mus_gen_et_(NULL),
  b_mus_gen_eta_(NULL),
  b_mus_gen_id_(NULL),
  b_mus_gen_mother_et_(NULL),
  b_mus_gen_mother_eta_(NULL),
  b_mus_gen_mother_id_(NULL),
  b_mus_gen_mother_phi_(NULL),
  b_mus_gen_mother_pt_(NULL),
  b_mus_gen_mother_px_(NULL),
  b_mus_gen_mother_py_(NULL),
  b_mus_gen_mother_pz_(NULL),
  b_mus_gen_mother_theta_(NULL),
  b_mus_gen_phi_(NULL),
  b_mus_gen_pt_(NULL),
  b_mus_gen_px_(NULL),
  b_mus_gen_py_(NULL),
  b_mus_gen_pz_(NULL),
  b_mus_gen_theta_(NULL),
  b_mus_hcalIso_(NULL),
  b_mus_hcalvetoDep_(NULL),
  b_mus_id_All_(NULL),
  b_mus_id_AllArbitrated_(NULL),
  b_mus_id_AllGlobalMuons_(NULL),
  b_mus_id_AllStandAloneMuons_(NULL),
  b_mus_id_AllTrackerMuons_(NULL),
  b_mus_id_GlobalMuonPromptTight_(NULL),
  b_mus_id_TM2DCompatibilityLoose_(NULL),
  b_mus_id_TM2DCompatibilityTight_(NULL),
  b_mus_id_TMLastStationLoose_(NULL),
  b_mus_id_TMLastStationOptimizedLowPtLoose_(NULL),
  b_mus_id_TMLastStationOptimizedLowPtTight_(NULL),
  b_mus_id_TMLastStationTight_(NULL),
  b_mus_id_TMOneStationLoose_(NULL),
  b_mus_id_TMOneStationTight_(NULL),
  b_mus_id_TrackerMuonArbitrated_(NULL),
  b_mus_isCaloMuon_(NULL),
  b_mus_isConvertedPhoton_(NULL),
  b_mus_isElectron_(NULL),
  b_mus_isGlobalMuon_(NULL),
  b_mus_isPF_(NULL),
  b_mus_isPFMuon_(NULL),
  b_mus_isPhoton_(NULL),
  b_mus_isStandAloneMuon_(NULL),
  b_mus_isTrackerMuon_(NULL),
  b_mus_iso03_emEt_(NULL),
  b_mus_iso03_emVetoEt_(NULL),
  b_mus_iso03_hadEt_(NULL),
  b_mus_iso03_hadVetoEt_(NULL),
  b_mus_iso03_hoEt_(NULL),
  b_mus_iso03_nTracks_(NULL),
  b_mus_iso03_sumPt_(NULL),
  b_mus_iso05_emEt_(NULL),
  b_mus_iso05_hadEt_(NULL),
  b_mus_iso05_hoEt_(NULL),
  b_mus_iso05_nTracks_(NULL),
  b_mus_iso05_sumPt_(NULL),
  b_mus_jet_ind_(NULL),
  b_mus_num_matches_(NULL),
  b_mus_numberOfMatchedStations_(NULL),
  b_mus_pfIsolationR03_sumChargedHadronPt_(NULL),
  b_mus_pfIsolationR03_sumChargedParticlePt_(NULL),
  b_mus_pfIsolationR03_sumNeutralHadronEt_(NULL),
  b_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_(NULL),
  b_mus_pfIsolationR03_sumPUPt_(NULL),
  b_mus_pfIsolationR03_sumPhotonEt_(NULL),
  b_mus_pfIsolationR03_sumPhotonEtHighThreshold_(NULL),
  b_mus_pfIsolationR04_sumChargedHadronPt_(NULL),
  b_mus_pfIsolationR04_sumChargedParticlePt_(NULL),
  b_mus_pfIsolationR04_sumNeutralHadronEt_(NULL),
  b_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_(NULL),
  b_mus_pfIsolationR04_sumPUPt_(NULL),
  b_mus_pfIsolationR04_sumPhotonEt_(NULL),
  b_mus_pfIsolationR04_sumPhotonEtHighThreshold_(NULL),
  b_mus_phi_(NULL),
  b_mus_picky_ExpectedHitsInner_(NULL),
  b_mus_picky_ExpectedHitsOuter_(NULL),
  b_mus_picky_LayersWithMeasurement_(NULL),
  b_mus_picky_LayersWithoutMeasurement_(NULL),
  b_mus_picky_PixelLayersWithMeasurement_(NULL),
  b_mus_picky_ValidStripLayersWithMonoAndStereoHit_(NULL),
  b_mus_picky_chg_(NULL),
  b_mus_picky_chi2_(NULL),
  b_mus_picky_d0dum_(NULL),
  b_mus_picky_d0dumErr_(NULL),
  b_mus_picky_dz_(NULL),
  b_mus_picky_dzErr_(NULL),
  b_mus_picky_eta_(NULL),
  b_mus_picky_etaErr_(NULL),
  b_mus_picky_id_(NULL),
  b_mus_picky_ndof_(NULL),
  b_mus_picky_numlosthits_(NULL),
  b_mus_picky_numvalPixelhits_(NULL),
  b_mus_picky_numvalhits_(NULL),
  b_mus_picky_phi_(NULL),
  b_mus_picky_phiErr_(NULL),
  b_mus_picky_pt_(NULL),
  b_mus_picky_ptErr_(NULL),
  b_mus_picky_px_(NULL),
  b_mus_picky_py_(NULL),
  b_mus_picky_pz_(NULL),
  b_mus_picky_theta_(NULL),
  b_mus_picky_vx_(NULL),
  b_mus_picky_vy_(NULL),
  b_mus_picky_vz_(NULL),
  b_mus_pt_(NULL),
  b_mus_px_(NULL),
  b_mus_py_(NULL),
  b_mus_pz_(NULL),
  b_mus_stamu_chg_(NULL),
  b_mus_stamu_chi2_(NULL),
  b_mus_stamu_d0dum_(NULL),
  b_mus_stamu_d0dumErr_(NULL),
  b_mus_stamu_dz_(NULL),
  b_mus_stamu_dzErr_(NULL),
  b_mus_stamu_eta_(NULL),
  b_mus_stamu_etaErr_(NULL),
  b_mus_stamu_ndof_(NULL),
  b_mus_stamu_numlosthits_(NULL),
  b_mus_stamu_numvalhits_(NULL),
  b_mus_stamu_phi_(NULL),
  b_mus_stamu_phiErr_(NULL),
  b_mus_stamu_pt_(NULL),
  b_mus_stamu_ptErr_(NULL),
  b_mus_stamu_px_(NULL),
  b_mus_stamu_py_(NULL),
  b_mus_stamu_pz_(NULL),
  b_mus_stamu_theta_(NULL),
  b_mus_stamu_vx_(NULL),
  b_mus_stamu_vy_(NULL),
  b_mus_stamu_vz_(NULL),
  b_mus_status_(NULL),
  b_mus_tIso_(NULL),
  b_mus_theta_(NULL),
  b_mus_tkHits_(NULL),
  b_mus_tk_ExpectedHitsInner_(NULL),
  b_mus_tk_ExpectedHitsOuter_(NULL),
  b_mus_tk_LayersWithMeasurement_(NULL),
  b_mus_tk_LayersWithoutMeasurement_(NULL),
  b_mus_tk_PixelLayersWithMeasurement_(NULL),
  b_mus_tk_ValidStripLayersWithMonoAndStereoHit_(NULL),
  b_mus_tk_chg_(NULL),
  b_mus_tk_chi2_(NULL),
  b_mus_tk_d0dum_(NULL),
  b_mus_tk_d0dumErr_(NULL),
  b_mus_tk_dz_(NULL),
  b_mus_tk_dzErr_(NULL),
  b_mus_tk_eta_(NULL),
  b_mus_tk_etaErr_(NULL),
  b_mus_tk_id_(NULL),
  b_mus_tk_ndof_(NULL),
  b_mus_tk_numlosthits_(NULL),
  b_mus_tk_numpixelWthMeasr_(NULL),
  b_mus_tk_numvalPixelhits_(NULL),
  b_mus_tk_numvalhits_(NULL),
  b_mus_tk_phi_(NULL),
  b_mus_tk_phiErr_(NULL),
  b_mus_tk_pt_(NULL),
  b_mus_tk_ptErr_(NULL),
  b_mus_tk_px_(NULL),
  b_mus_tk_py_(NULL),
  b_mus_tk_pz_(NULL),
  b_mus_tk_theta_(NULL),
  b_mus_tk_vx_(NULL),
  b_mus_tk_vy_(NULL),
  b_mus_tk_vz_(NULL),
  b_mus_tpfms_ExpectedHitsInner_(NULL),
  b_mus_tpfms_ExpectedHitsOuter_(NULL),
  b_mus_tpfms_LayersWithMeasurement_(NULL),
  b_mus_tpfms_LayersWithoutMeasurement_(NULL),
  b_mus_tpfms_PixelLayersWithMeasurement_(NULL),
  b_mus_tpfms_ValidStripLayersWithMonoAndStereoHit_(NULL),
  b_mus_tpfms_chg_(NULL),
  b_mus_tpfms_chi2_(NULL),
  b_mus_tpfms_d0dum_(NULL),
  b_mus_tpfms_d0dumErr_(NULL),
  b_mus_tpfms_dz_(NULL),
  b_mus_tpfms_dzErr_(NULL),
  b_mus_tpfms_eta_(NULL),
  b_mus_tpfms_etaErr_(NULL),
  b_mus_tpfms_id_(NULL),
  b_mus_tpfms_ndof_(NULL),
  b_mus_tpfms_numlosthits_(NULL),
  b_mus_tpfms_numvalPixelhits_(NULL),
  b_mus_tpfms_numvalhits_(NULL),
  b_mus_tpfms_phi_(NULL),
  b_mus_tpfms_phiErr_(NULL),
  b_mus_tpfms_pt_(NULL),
  b_mus_tpfms_ptErr_(NULL),
  b_mus_tpfms_px_(NULL),
  b_mus_tpfms_py_(NULL),
  b_mus_tpfms_pz_(NULL),
  b_mus_tpfms_theta_(NULL),
  b_mus_tpfms_vx_(NULL),
  b_mus_tpfms_vy_(NULL),
  b_mus_tpfms_vz_(NULL),
  b_orbitNumber_(NULL),
  b_pfcand_charge_(NULL),
  b_pfcand_energy_(NULL),
  b_pfcand_eta_(NULL),
  b_pfcand_pdgId_(NULL),
  b_pfcand_phi_(NULL),
  b_pfcand_pt_(NULL),
  b_pfcand_px_(NULL),
  b_pfcand_py_(NULL),
  b_pfcand_pz_(NULL),
  b_pfcand_theta_(NULL),
  b_photons_e1x5_(NULL),
  b_photons_e2x5_(NULL),
  b_photons_e3x3_(NULL),
  b_photons_e5x5_(NULL),
  b_photons_ecalIso_(NULL),
  b_photons_energy_(NULL),
  b_photons_et_(NULL),
  b_photons_eta_(NULL),
  b_photons_gen_et_(NULL),
  b_photons_gen_eta_(NULL),
  b_photons_gen_id_(NULL),
  b_photons_gen_phi_(NULL),
  b_photons_hadOverEM_(NULL),
  b_photons_hadTowOverEM_(NULL),
  b_photons_hasPixelSeed_(NULL),
  b_photons_hcalIso_(NULL),
  b_photons_isAlsoElectron_(NULL),
  b_photons_isConverted_(NULL),
  b_photons_isEBEEGap_(NULL),
  b_photons_isEBGap_(NULL),
  b_photons_isEBPho_(NULL),
  b_photons_isEEGap_(NULL),
  b_photons_isEEPho_(NULL),
  b_photons_isLoosePhoton_(NULL),
  b_photons_isTightPhoton_(NULL),
  b_photons_isoEcalRecHitDR03_(NULL),
  b_photons_isoEcalRecHitDR04_(NULL),
  b_photons_isoHcalRecHitDR03_(NULL),
  b_photons_isoHcalRecHitDR04_(NULL),
  b_photons_isoHollowTrkConeDR03_(NULL),
  b_photons_isoHollowTrkConeDR04_(NULL),
  b_photons_isoSolidTrkConeDR03_(NULL),
  b_photons_isoSolidTrkConeDR04_(NULL),
  b_photons_maxEnergyXtal_(NULL),
  b_photons_nTrkHollowConeDR03_(NULL),
  b_photons_nTrkHollowConeDR04_(NULL),
  b_photons_nTrkSolidConeDR03_(NULL),
  b_photons_nTrkSolidConeDR04_(NULL),
  b_photons_phi_(NULL),
  b_photons_pt_(NULL),
  b_photons_px_(NULL),
  b_photons_py_(NULL),
  b_photons_pz_(NULL),
  b_photons_r9_(NULL),
  b_photons_scEnergy_(NULL),
  b_photons_scEta_(NULL),
  b_photons_scEtaWidth_(NULL),
  b_photons_scPhi_(NULL),
  b_photons_scPhiWidth_(NULL),
  b_photons_scRawEnergy_(NULL),
  b_photons_sigmaEtaEta_(NULL),
  b_photons_sigmaIetaIeta_(NULL),
  b_photons_status_(NULL),
  b_photons_tIso_(NULL),
  b_photons_theta_(NULL),
  b_pv_chi2_(NULL),
  b_pv_isFake_(NULL),
  b_pv_isValid_(NULL),
  b_pv_ndof_(NULL),
  b_pv_tracksSize_(NULL),
  b_pv_x_(NULL),
  b_pv_xErr_(NULL),
  b_pv_y_(NULL),
  b_pv_yErr_(NULL),
  b_pv_z_(NULL),
  b_pv_zErr_(NULL),
  b_run_(NULL),
  b_standalone_triggerobject_collectionname_(NULL),
  b_standalone_triggerobject_energy_(NULL),
  b_standalone_triggerobject_et_(NULL),
  b_standalone_triggerobject_eta_(NULL),
  b_standalone_triggerobject_phi_(NULL),
  b_standalone_triggerobject_pt_(NULL),
  b_standalone_triggerobject_px_(NULL),
  b_standalone_triggerobject_py_(NULL),
  b_standalone_triggerobject_pz_(NULL),
  b_taus_Nprongs_(NULL),
  b_taus_againstElectron_(NULL),
  b_taus_againstElectronLoose_(NULL),
  b_taus_againstElectronMVA_(NULL),
  b_taus_againstElectronMedium_(NULL),
  b_taus_againstElectronTight_(NULL),
  b_taus_againstMuon_(NULL),
  b_taus_againstMuonLoose_(NULL),
  b_taus_againstMuonMedium_(NULL),
  b_taus_againstMuonTight_(NULL),
  b_taus_byIsoUsingLeadingPi_(NULL),
  b_taus_byIsolation_(NULL),
  b_taus_byLooseIsolation_(NULL),
  b_taus_byLooseIsolationDeltaBetaCorr_(NULL),
  b_taus_byMediumIsolation_(NULL),
  b_taus_byMediumIsolationDeltaBetaCorr_(NULL),
  b_taus_byTightIsolation_(NULL),
  b_taus_byTightIsolationDeltaBetaCorr_(NULL),
  b_taus_byVLooseIsolation_(NULL),
  b_taus_byVLooseIsolationDeltaBetaCorr_(NULL),
  b_taus_charge_(NULL),
  b_taus_decayModeFinding_(NULL),
  b_taus_ecalIsoUsingLeadingPi_(NULL),
  b_taus_ecalIsolation_(NULL),
  b_taus_ecalStripSumEOverPLead_(NULL),
  b_taus_el_ind_(NULL),
  b_taus_elecPreIdDecision_(NULL),
  b_taus_elecPreIdOutput_(NULL),
  b_taus_emf_(NULL),
  b_taus_energy_(NULL),
  b_taus_et_(NULL),
  b_taus_eta_(NULL),
  b_taus_hcal3x3OverPLead_(NULL),
  b_taus_hcalMaxOverPLead_(NULL),
  b_taus_hcalTotOverPLead_(NULL),
  b_taus_isoPFChargedHadrCandsPtSum_(NULL),
  b_taus_isoPFGammaCandsEtSum_(NULL),
  b_taus_leadPFChargedHadrCand_ECAL_eta_(NULL),
  b_taus_leadPFChargedHadrCand_charge_(NULL),
  b_taus_leadPFChargedHadrCand_eta_(NULL),
  b_taus_leadPFChargedHadrCand_phi_(NULL),
  b_taus_leadPFChargedHadrCand_pt_(NULL),
  b_taus_leadingTrackFinding_(NULL),
  b_taus_leadingTrackPtCut_(NULL),
  b_taus_muDecision_(NULL),
  b_taus_mu_ind_(NULL),
  b_taus_phi_(NULL),
  b_taus_pt_(NULL),
  b_taus_px_(NULL),
  b_taus_py_(NULL),
  b_taus_pz_(NULL),
  b_taus_signalPFChargedHadrCandsSize_(NULL),
  b_taus_status_(NULL),
  b_taus_taNC_(NULL),
  b_taus_taNC_half_(NULL),
  b_taus_taNC_one_(NULL),
  b_taus_taNC_quarter_(NULL),
  b_taus_taNC_tenth_(NULL),
  b_taus_theta_(NULL),
  b_taus_tkIsoUsingLeadingPi_(NULL),
  b_taus_trackIsolation_(NULL),
  b_trackingfailurefilter_decision_(NULL),
  b_trigger_decision_(NULL),
  b_trigger_name_(NULL),
  b_trigger_prescalevalue_(NULL),
  b_trkPOG_logErrorTooManyClustersfilter_decision_(NULL),
  b_trkPOG_manystripclus53Xfilter_decision_(NULL),
  b_trkPOG_toomanystripclus53Xfilter_decision_(NULL),
  b_trkPOGfilter_decision_(NULL),
  b_weight_(NULL),
  c_EcalDeadCellTriggerPrimitivefilter_decision_(false),
  c_HBHENoisefilter_decision_(false),
  c_METFiltersfilter_decision_(false),
  c_NbeamSpot_(false),
  c_Nels_(false),
  c_Njets_AK4_(false),
  c_Nmc_doc_(false),
  c_Nmc_electrons_(false),
  c_Nmc_final_(false),
  c_Nmc_jets_(false),
  c_Nmc_mus_(false),
  c_Nmc_nues_(false),
  c_Nmc_numus_(false),
  c_Nmc_nutaus_(false),
  c_Nmc_photons_(false),
  c_Nmc_taus_(false),
  c_Nmets_(false),
  c_Nmus_(false),
  c_Npfcand_(false),
  c_Nphotons_(false),
  c_Npv_(false),
  c_Ntaus_(false),
  c_PU_NumInteractions_(false),
  c_PU_TrueNumInteractions_(false),
  c_PU_bunchCrossing_(false),
  c_PU_ntrks_highpT_(false),
  c_PU_ntrks_lowpT_(false),
  c_PU_sumpT_highpT_(false),
  c_PU_sumpT_lowpT_(false),
  c_PU_zpositions_(false),
  c_beamSpot_beamWidthX_(false),
  c_beamSpot_beamWidthXError_(false),
  c_beamSpot_beamWidthY_(false),
  c_beamSpot_beamWidthYError_(false),
  c_beamSpot_dxdz_(false),
  c_beamSpot_dxdzError_(false),
  c_beamSpot_dydz_(false),
  c_beamSpot_dydzError_(false),
  c_beamSpot_sigmaZ_(false),
  c_beamSpot_sigmaZ0Error_(false),
  c_beamSpot_x_(false),
  c_beamSpot_x0Error_(false),
  c_beamSpot_y_(false),
  c_beamSpot_y0Error_(false),
  c_beamSpot_z_(false),
  c_beamSpot_z0Error_(false),
  c_bunchCrossing_(false),
  c_cschalofilter_decision_(false),
  c_ecallaserfilter_decision_(false),
  c_eebadscfilter_decision_(false),
  c_els_PATpassConversionVeto_(false),
  c_els_basicClustersSize_(false),
  c_els_cIso_(false),
  c_els_caloEnergy_(false),
  c_els_charge_(false),
  c_els_chi2_(false),
  c_els_core_ecalDrivenSeed_(false),
  c_els_cpx_(false),
  c_els_cpy_(false),
  c_els_cpz_(false),
  c_els_ctf_tk_charge_(false),
  c_els_ctf_tk_eta_(false),
  c_els_ctf_tk_id_(false),
  c_els_ctf_tk_phi_(false),
  c_els_cx_(false),
  c_els_cy_(false),
  c_els_cz_(false),
  c_els_d0dum_(false),
  c_els_d0dumError_(false),
  c_els_dEtaIn_(false),
  c_els_dEtaOut_(false),
  c_els_dPhiIn_(false),
  c_els_dPhiOut_(false),
  c_els_dr03EcalRecHitSumEt_(false),
  c_els_dr03HcalDepth1TowerSumEt_(false),
  c_els_dr03HcalDepth2TowerSumEt_(false),
  c_els_dr03HcalTowerSumEt_(false),
  c_els_dr03TkSumPt_(false),
  c_els_dr04EcalRecHitSumEt_(false),
  c_els_dr04HcalDepth1TowerSumEt_(false),
  c_els_dr04HcalDepth2TowerSumEt_(false),
  c_els_dr04HcalTowerSumEt_(false),
  c_els_dr04TkSumPt_(false),
  c_els_dz_(false),
  c_els_dzError_(false),
  c_els_eOverPIn_(false),
  c_els_eSeedOverPOut_(false),
  c_els_ecalIso_(false),
  c_els_energy_(false),
  c_els_et_(false),
  c_els_eta_(false),
  c_els_etaError_(false),
  c_els_fbrem_(false),
  c_els_full5x5_sigmaIetaIeta_(false),
  c_els_gen_et_(false),
  c_els_gen_eta_(false),
  c_els_gen_id_(false),
  c_els_gen_mother_et_(false),
  c_els_gen_mother_eta_(false),
  c_els_gen_mother_id_(false),
  c_els_gen_mother_phi_(false),
  c_els_gen_mother_pt_(false),
  c_els_gen_mother_px_(false),
  c_els_gen_mother_py_(false),
  c_els_gen_mother_pz_(false),
  c_els_gen_mother_theta_(false),
  c_els_gen_phi_(false),
  c_els_gen_pt_(false),
  c_els_gen_px_(false),
  c_els_gen_py_(false),
  c_els_gen_pz_(false),
  c_els_gen_theta_(false),
  c_els_hadOverEm_(false),
  c_els_hcalIso_(false),
  c_els_hcalOverEcalBc_(false),
  c_els_isEB_(false),
  c_els_isEE_(false),
  c_els_isPF_(false),
  c_els_jet_ind_(false),
  c_els_looseId_(false),
  c_els_n_inner_layer_(false),
  c_els_n_outer_layer_(false),
  c_els_ndof_(false),
  c_els_numlosthits_(false),
  c_els_numvalhits_(false),
  c_els_pfIsolationR03_sumChargedHadronPt_(false),
  c_els_pfIsolationR03_sumNeutralHadronEt_(false),
  c_els_pfIsolationR03_sumPUPt_(false),
  c_els_pfIsolationR03_sumPhotonEt_(false),
  c_els_phi_(false),
  c_els_phiError_(false),
  c_els_pt_(false),
  c_els_ptError_(false),
  c_els_px_(false),
  c_els_py_(false),
  c_els_pz_(false),
  c_els_robustHighEnergyId_(false),
  c_els_robustLooseId_(false),
  c_els_robustTightId_(false),
  c_els_scE1x5_(false),
  c_els_scE2x5Max_(false),
  c_els_scE5x5_(false),
  c_els_scEnergy_(false),
  c_els_scEta_(false),
  c_els_scEtaWidth_(false),
  c_els_scPhi_(false),
  c_els_scPhiWidth_(false),
  c_els_scRawEnergy_(false),
  c_els_scSeedEnergy_(false),
  c_els_shFracInnerHits_(false),
  c_els_sigmaEtaEta_(false),
  c_els_sigmaIEtaIEta_(false),
  c_els_simpleEleId60cIso_(false),
  c_els_simpleEleId60relIso_(false),
  c_els_simpleEleId70cIso_(false),
  c_els_simpleEleId70relIso_(false),
  c_els_simpleEleId80cIso_(false),
  c_els_simpleEleId80relIso_(false),
  c_els_simpleEleId85cIso_(false),
  c_els_simpleEleId85relIso_(false),
  c_els_simpleEleId90cIso_(false),
  c_els_simpleEleId90relIso_(false),
  c_els_simpleEleId95cIso_(false),
  c_els_simpleEleId95relIso_(false),
  c_els_status_(false),
  c_els_tIso_(false),
  c_els_theta_(false),
  c_els_tightId_(false),
  c_els_tk_charge_(false),
  c_els_tk_eta_(false),
  c_els_tk_phi_(false),
  c_els_tk_pt_(false),
  c_els_tk_pz_(false),
  c_els_vpx_(false),
  c_els_vpy_(false),
  c_els_vpz_(false),
  c_els_vx_(false),
  c_els_vy_(false),
  c_els_vz_(false),
  c_event_(false),
  c_experimentType_(false),
  c_fastjets_AK4_R1p2_R0p5pT10_energy_(false),
  c_fastjets_AK4_R1p2_R0p5pT10_eta_(false),
  c_fastjets_AK4_R1p2_R0p5pT10_index_(false),
  c_fastjets_AK4_R1p2_R0p5pT10_nconstituents_(false),
  c_fastjets_AK4_R1p2_R0p5pT10_phi_(false),
  c_fastjets_AK4_R1p2_R0p5pT10_px_(false),
  c_fastjets_AK4_R1p2_R0p5pT10_py_(false),
  c_fastjets_AK4_R1p2_R0p5pT10_pz_(false),
  c_fastjets_AK4_R1p2_R0p5pT15_energy_(false),
  c_fastjets_AK4_R1p2_R0p5pT15_eta_(false),
  c_fastjets_AK4_R1p2_R0p5pT15_index_(false),
  c_fastjets_AK4_R1p2_R0p5pT15_nconstituents_(false),
  c_fastjets_AK4_R1p2_R0p5pT15_phi_(false),
  c_fastjets_AK4_R1p2_R0p5pT15_px_(false),
  c_fastjets_AK4_R1p2_R0p5pT15_py_(false),
  c_fastjets_AK4_R1p2_R0p5pT15_pz_(false),
  c_fastjets_AK4_R1p2_R0p5pT20_energy_(false),
  c_fastjets_AK4_R1p2_R0p5pT20_eta_(false),
  c_fastjets_AK4_R1p2_R0p5pT20_index_(false),
  c_fastjets_AK4_R1p2_R0p5pT20_nconstituents_(false),
  c_fastjets_AK4_R1p2_R0p5pT20_phi_(false),
  c_fastjets_AK4_R1p2_R0p5pT20_px_(false),
  c_fastjets_AK4_R1p2_R0p5pT20_py_(false),
  c_fastjets_AK4_R1p2_R0p5pT20_pz_(false),
  c_fastjets_AK4_R1p2_R0p5pT25_energy_(false),
  c_fastjets_AK4_R1p2_R0p5pT25_eta_(false),
  c_fastjets_AK4_R1p2_R0p5pT25_index_(false),
  c_fastjets_AK4_R1p2_R0p5pT25_nconstituents_(false),
  c_fastjets_AK4_R1p2_R0p5pT25_phi_(false),
  c_fastjets_AK4_R1p2_R0p5pT25_px_(false),
  c_fastjets_AK4_R1p2_R0p5pT25_py_(false),
  c_fastjets_AK4_R1p2_R0p5pT25_pz_(false),
  c_fastjets_AK4_R1p2_R0p5pT30_energy_(false),
  c_fastjets_AK4_R1p2_R0p5pT30_eta_(false),
  c_fastjets_AK4_R1p2_R0p5pT30_index_(false),
  c_fastjets_AK4_R1p2_R0p5pT30_nconstituents_(false),
  c_fastjets_AK4_R1p2_R0p5pT30_phi_(false),
  c_fastjets_AK4_R1p2_R0p5pT30_px_(false),
  c_fastjets_AK4_R1p2_R0p5pT30_py_(false),
  c_fastjets_AK4_R1p2_R0p5pT30_pz_(false),
  c_goodVerticesfilter_decision_(false),
  c_hcallaserfilter_decision_(false),
  c_jets_AK4_area_(false),
  c_jets_AK4_btag_TC_highEff_(false),
  c_jets_AK4_btag_TC_highPur_(false),
  c_jets_AK4_btag_jetBProb_(false),
  c_jets_AK4_btag_jetProb_(false),
  c_jets_AK4_btag_secVertexCombined_(false),
  c_jets_AK4_btag_secVertexHighEff_(false),
  c_jets_AK4_btag_secVertexHighPur_(false),
  c_jets_AK4_btag_softEle_(false),
  c_jets_AK4_btag_softMuon_(false),
  c_jets_AK4_chgEmE_(false),
  c_jets_AK4_chgHadE_(false),
  c_jets_AK4_chgMuE_(false),
  c_jets_AK4_chg_Mult_(false),
  c_jets_AK4_corrFactorRaw_(false),
  c_jets_AK4_ehf_(false),
  c_jets_AK4_el_ind_(false),
  c_jets_AK4_emf_(false),
  c_jets_AK4_energy_(false),
  c_jets_AK4_et_(false),
  c_jets_AK4_eta_(false),
  c_jets_AK4_etaetaMoment_(false),
  c_jets_AK4_etaphiMoment_(false),
  c_jets_AK4_fHPD_(false),
  c_jets_AK4_fRBX_(false),
  c_jets_AK4_fSubDetector1_(false),
  c_jets_AK4_fSubDetector2_(false),
  c_jets_AK4_fSubDetector3_(false),
  c_jets_AK4_fSubDetector4_(false),
  c_jets_AK4_gen_Energy_(false),
  c_jets_AK4_gen_Id_(false),
  c_jets_AK4_gen_et_(false),
  c_jets_AK4_gen_eta_(false),
  c_jets_AK4_gen_mass_(false),
  c_jets_AK4_gen_motherID_(false),
  c_jets_AK4_gen_phi_(false),
  c_jets_AK4_gen_pt_(false),
  c_jets_AK4_gen_threeCharge_(false),
  c_jets_AK4_hitsInN90_(false),
  c_jets_AK4_jetCharge_(false),
  c_jets_AK4_mass_(false),
  c_jets_AK4_maxpt_id_(false),
  c_jets_AK4_mu_Mult_(false),
  c_jets_AK4_mu_ind_(false),
  c_jets_AK4_n60_(false),
  c_jets_AK4_n90_(false),
  c_jets_AK4_n90Hits_(false),
  c_jets_AK4_nECALTowers_(false),
  c_jets_AK4_nHCALTowers_(false),
  c_jets_AK4_neutralEmE_(false),
  c_jets_AK4_neutralHadE_(false),
  c_jets_AK4_neutral_Mult_(false),
  c_jets_AK4_partonFlavour_(false),
  c_jets_AK4_parton_Energy_(false),
  c_jets_AK4_parton_Id_(false),
  c_jets_AK4_parton_eta_(false),
  c_jets_AK4_parton_mass_(false),
  c_jets_AK4_parton_motherId_(false),
  c_jets_AK4_parton_phi_(false),
  c_jets_AK4_parton_pt_(false),
  c_jets_AK4_phi_(false),
  c_jets_AK4_phiphiMoment_(false),
  c_jets_AK4_photonEnergy_(false),
  c_jets_AK4_pt_(false),
  c_jets_AK4_px_(false),
  c_jets_AK4_py_(false),
  c_jets_AK4_pz_(false),
  c_jets_AK4_rawPt_(false),
  c_jets_AK4_status_(false),
  c_jets_AK4_theta_(false),
  c_lumiblock_(false),
  c_mc_doc_charge_(false),
  c_mc_doc_energy_(false),
  c_mc_doc_eta_(false),
  c_mc_doc_ggrandmother_id_(false),
  c_mc_doc_grandmother_id_(false),
  c_mc_doc_id_(false),
  c_mc_doc_mass_(false),
  c_mc_doc_mother_id_(false),
  c_mc_doc_mother_pt_(false),
  c_mc_doc_numOfDaughters_(false),
  c_mc_doc_numOfMothers_(false),
  c_mc_doc_phi_(false),
  c_mc_doc_pt_(false),
  c_mc_doc_px_(false),
  c_mc_doc_py_(false),
  c_mc_doc_pz_(false),
  c_mc_doc_status_(false),
  c_mc_doc_theta_(false),
  c_mc_doc_vertex_x_(false),
  c_mc_doc_vertex_y_(false),
  c_mc_doc_vertex_z_(false),
  c_mc_electrons_charge_(false),
  c_mc_electrons_energy_(false),
  c_mc_electrons_eta_(false),
  c_mc_electrons_ggrandmother_id_(false),
  c_mc_electrons_grandmother_id_(false),
  c_mc_electrons_id_(false),
  c_mc_electrons_mass_(false),
  c_mc_electrons_mother_id_(false),
  c_mc_electrons_mother_pt_(false),
  c_mc_electrons_numOfDaughters_(false),
  c_mc_electrons_phi_(false),
  c_mc_electrons_pt_(false),
  c_mc_electrons_px_(false),
  c_mc_electrons_py_(false),
  c_mc_electrons_pz_(false),
  c_mc_electrons_status_(false),
  c_mc_electrons_theta_(false),
  c_mc_electrons_vertex_x_(false),
  c_mc_electrons_vertex_y_(false),
  c_mc_electrons_vertex_z_(false),
  c_mc_final_charge_(false),
  c_mc_final_energy_(false),
  c_mc_final_eta_(false),
  c_mc_final_ggrandmother_id_(false),
  c_mc_final_grandmother_id_(false),
  c_mc_final_id_(false),
  c_mc_final_mass_(false),
  c_mc_final_mother_id_(false),
  c_mc_final_mother_pt_(false),
  c_mc_final_numOfDaughters_(false),
  c_mc_final_numOfMothers_(false),
  c_mc_final_phi_(false),
  c_mc_final_pt_(false),
  c_mc_final_px_(false),
  c_mc_final_py_(false),
  c_mc_final_pz_(false),
  c_mc_final_status_(false),
  c_mc_final_theta_(false),
  c_mc_final_vertex_x_(false),
  c_mc_final_vertex_y_(false),
  c_mc_final_vertex_z_(false),
  c_mc_jets_auxiliaryEnergy_(false),
  c_mc_jets_emEnergy_(false),
  c_mc_jets_energy_(false),
  c_mc_jets_et_(false),
  c_mc_jets_eta_(false),
  c_mc_jets_etaetaMoment_(false),
  c_mc_jets_etaphiMoment_(false),
  c_mc_jets_hadEnergy_(false),
  c_mc_jets_invisibleEnergy_(false),
  c_mc_jets_mass_(false),
  c_mc_jets_phi_(false),
  c_mc_jets_phiphiMoment_(false),
  c_mc_jets_pt_(false),
  c_mc_jets_px_(false),
  c_mc_jets_py_(false),
  c_mc_jets_pz_(false),
  c_mc_jets_theta_(false),
  c_mc_mus_charge_(false),
  c_mc_mus_energy_(false),
  c_mc_mus_eta_(false),
  c_mc_mus_ggrandmother_id_(false),
  c_mc_mus_grandmother_id_(false),
  c_mc_mus_id_(false),
  c_mc_mus_mass_(false),
  c_mc_mus_mother_id_(false),
  c_mc_mus_mother_pt_(false),
  c_mc_mus_numOfDaughters_(false),
  c_mc_mus_phi_(false),
  c_mc_mus_pt_(false),
  c_mc_mus_px_(false),
  c_mc_mus_py_(false),
  c_mc_mus_pz_(false),
  c_mc_mus_status_(false),
  c_mc_mus_theta_(false),
  c_mc_mus_vertex_x_(false),
  c_mc_mus_vertex_y_(false),
  c_mc_mus_vertex_z_(false),
  c_mc_nues_charge_(false),
  c_mc_nues_energy_(false),
  c_mc_nues_eta_(false),
  c_mc_nues_ggrandmother_id_(false),
  c_mc_nues_grandmother_id_(false),
  c_mc_nues_id_(false),
  c_mc_nues_mass_(false),
  c_mc_nues_mother_id_(false),
  c_mc_nues_mother_pt_(false),
  c_mc_nues_numOfDaughters_(false),
  c_mc_nues_phi_(false),
  c_mc_nues_pt_(false),
  c_mc_nues_px_(false),
  c_mc_nues_py_(false),
  c_mc_nues_pz_(false),
  c_mc_nues_status_(false),
  c_mc_nues_theta_(false),
  c_mc_nues_vertex_x_(false),
  c_mc_nues_vertex_y_(false),
  c_mc_nues_vertex_z_(false),
  c_mc_numus_charge_(false),
  c_mc_numus_energy_(false),
  c_mc_numus_eta_(false),
  c_mc_numus_ggrandmother_id_(false),
  c_mc_numus_grandmother_id_(false),
  c_mc_numus_id_(false),
  c_mc_numus_mass_(false),
  c_mc_numus_mother_id_(false),
  c_mc_numus_mother_pt_(false),
  c_mc_numus_numOfDaughters_(false),
  c_mc_numus_phi_(false),
  c_mc_numus_pt_(false),
  c_mc_numus_px_(false),
  c_mc_numus_py_(false),
  c_mc_numus_pz_(false),
  c_mc_numus_status_(false),
  c_mc_numus_theta_(false),
  c_mc_numus_vertex_x_(false),
  c_mc_numus_vertex_y_(false),
  c_mc_numus_vertex_z_(false),
  c_mc_nutaus_charge_(false),
  c_mc_nutaus_energy_(false),
  c_mc_nutaus_eta_(false),
  c_mc_nutaus_ggrandmother_id_(false),
  c_mc_nutaus_grandmother_id_(false),
  c_mc_nutaus_id_(false),
  c_mc_nutaus_mass_(false),
  c_mc_nutaus_mother_id_(false),
  c_mc_nutaus_mother_pt_(false),
  c_mc_nutaus_numOfDaughters_(false),
  c_mc_nutaus_phi_(false),
  c_mc_nutaus_pt_(false),
  c_mc_nutaus_px_(false),
  c_mc_nutaus_py_(false),
  c_mc_nutaus_pz_(false),
  c_mc_nutaus_status_(false),
  c_mc_nutaus_theta_(false),
  c_mc_nutaus_vertex_x_(false),
  c_mc_nutaus_vertex_y_(false),
  c_mc_nutaus_vertex_z_(false),
  c_mc_photons_charge_(false),
  c_mc_photons_energy_(false),
  c_mc_photons_eta_(false),
  c_mc_photons_ggrandmother_id_(false),
  c_mc_photons_grandmother_id_(false),
  c_mc_photons_id_(false),
  c_mc_photons_mass_(false),
  c_mc_photons_mother_id_(false),
  c_mc_photons_mother_pt_(false),
  c_mc_photons_numOfDaughters_(false),
  c_mc_photons_phi_(false),
  c_mc_photons_pt_(false),
  c_mc_photons_px_(false),
  c_mc_photons_py_(false),
  c_mc_photons_pz_(false),
  c_mc_photons_status_(false),
  c_mc_photons_theta_(false),
  c_mc_photons_vertex_x_(false),
  c_mc_photons_vertex_y_(false),
  c_mc_photons_vertex_z_(false),
  c_mc_taus_charge_(false),
  c_mc_taus_energy_(false),
  c_mc_taus_eta_(false),
  c_mc_taus_ggrandmother_id_(false),
  c_mc_taus_grandmother_id_(false),
  c_mc_taus_id_(false),
  c_mc_taus_mass_(false),
  c_mc_taus_mother_id_(false),
  c_mc_taus_mother_pt_(false),
  c_mc_taus_numOfDaughters_(false),
  c_mc_taus_phi_(false),
  c_mc_taus_pt_(false),
  c_mc_taus_px_(false),
  c_mc_taus_py_(false),
  c_mc_taus_pz_(false),
  c_mc_taus_status_(false),
  c_mc_taus_theta_(false),
  c_mc_taus_vertex_x_(false),
  c_mc_taus_vertex_y_(false),
  c_mc_taus_vertex_z_(false),
  c_mets_et_(false),
  c_mets_ex_(false),
  c_mets_ey_(false),
  c_mets_gen_et_(false),
  c_mets_gen_phi_(false),
  c_mets_phi_(false),
  c_mets_sign_(false),
  c_mets_sumEt_(false),
  c_mets_unCPhi_(false),
  c_mets_unCPt_(false),
  c_model_params_(false),
  c_mus_cIso_(false),
  c_mus_calEnergyEm_(false),
  c_mus_calEnergyEmS9_(false),
  c_mus_calEnergyHad_(false),
  c_mus_calEnergyHadS9_(false),
  c_mus_calEnergyHo_(false),
  c_mus_calEnergyHoS9_(false),
  c_mus_charge_(false),
  c_mus_cm_ExpectedHitsInner_(false),
  c_mus_cm_ExpectedHitsOuter_(false),
  c_mus_cm_LayersWithMeasurement_(false),
  c_mus_cm_LayersWithoutMeasurement_(false),
  c_mus_cm_PixelLayersWithMeasurement_(false),
  c_mus_cm_ValidStripLayersWithMonoAndStereoHit_(false),
  c_mus_cm_chg_(false),
  c_mus_cm_chi2_(false),
  c_mus_cm_d0dum_(false),
  c_mus_cm_d0dumErr_(false),
  c_mus_cm_dz_(false),
  c_mus_cm_dzErr_(false),
  c_mus_cm_eta_(false),
  c_mus_cm_etaErr_(false),
  c_mus_cm_ndof_(false),
  c_mus_cm_numlosthits_(false),
  c_mus_cm_numvalMuonhits_(false),
  c_mus_cm_numvalhits_(false),
  c_mus_cm_phi_(false),
  c_mus_cm_phiErr_(false),
  c_mus_cm_pt_(false),
  c_mus_cm_ptErr_(false),
  c_mus_cm_px_(false),
  c_mus_cm_py_(false),
  c_mus_cm_pz_(false),
  c_mus_cm_theta_(false),
  c_mus_cm_vx_(false),
  c_mus_cm_vy_(false),
  c_mus_cm_vz_(false),
  c_mus_dB_(false),
  c_mus_ecalIso_(false),
  c_mus_ecalvetoDep_(false),
  c_mus_energy_(false),
  c_mus_et_(false),
  c_mus_eta_(false),
  c_mus_gen_et_(false),
  c_mus_gen_eta_(false),
  c_mus_gen_id_(false),
  c_mus_gen_mother_et_(false),
  c_mus_gen_mother_eta_(false),
  c_mus_gen_mother_id_(false),
  c_mus_gen_mother_phi_(false),
  c_mus_gen_mother_pt_(false),
  c_mus_gen_mother_px_(false),
  c_mus_gen_mother_py_(false),
  c_mus_gen_mother_pz_(false),
  c_mus_gen_mother_theta_(false),
  c_mus_gen_phi_(false),
  c_mus_gen_pt_(false),
  c_mus_gen_px_(false),
  c_mus_gen_py_(false),
  c_mus_gen_pz_(false),
  c_mus_gen_theta_(false),
  c_mus_hcalIso_(false),
  c_mus_hcalvetoDep_(false),
  c_mus_id_All_(false),
  c_mus_id_AllArbitrated_(false),
  c_mus_id_AllGlobalMuons_(false),
  c_mus_id_AllStandAloneMuons_(false),
  c_mus_id_AllTrackerMuons_(false),
  c_mus_id_GlobalMuonPromptTight_(false),
  c_mus_id_TM2DCompatibilityLoose_(false),
  c_mus_id_TM2DCompatibilityTight_(false),
  c_mus_id_TMLastStationLoose_(false),
  c_mus_id_TMLastStationOptimizedLowPtLoose_(false),
  c_mus_id_TMLastStationOptimizedLowPtTight_(false),
  c_mus_id_TMLastStationTight_(false),
  c_mus_id_TMOneStationLoose_(false),
  c_mus_id_TMOneStationTight_(false),
  c_mus_id_TrackerMuonArbitrated_(false),
  c_mus_isCaloMuon_(false),
  c_mus_isConvertedPhoton_(false),
  c_mus_isElectron_(false),
  c_mus_isGlobalMuon_(false),
  c_mus_isPF_(false),
  c_mus_isPFMuon_(false),
  c_mus_isPhoton_(false),
  c_mus_isStandAloneMuon_(false),
  c_mus_isTrackerMuon_(false),
  c_mus_iso03_emEt_(false),
  c_mus_iso03_emVetoEt_(false),
  c_mus_iso03_hadEt_(false),
  c_mus_iso03_hadVetoEt_(false),
  c_mus_iso03_hoEt_(false),
  c_mus_iso03_nTracks_(false),
  c_mus_iso03_sumPt_(false),
  c_mus_iso05_emEt_(false),
  c_mus_iso05_hadEt_(false),
  c_mus_iso05_hoEt_(false),
  c_mus_iso05_nTracks_(false),
  c_mus_iso05_sumPt_(false),
  c_mus_jet_ind_(false),
  c_mus_num_matches_(false),
  c_mus_numberOfMatchedStations_(false),
  c_mus_pfIsolationR03_sumChargedHadronPt_(false),
  c_mus_pfIsolationR03_sumChargedParticlePt_(false),
  c_mus_pfIsolationR03_sumNeutralHadronEt_(false),
  c_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_(false),
  c_mus_pfIsolationR03_sumPUPt_(false),
  c_mus_pfIsolationR03_sumPhotonEt_(false),
  c_mus_pfIsolationR03_sumPhotonEtHighThreshold_(false),
  c_mus_pfIsolationR04_sumChargedHadronPt_(false),
  c_mus_pfIsolationR04_sumChargedParticlePt_(false),
  c_mus_pfIsolationR04_sumNeutralHadronEt_(false),
  c_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_(false),
  c_mus_pfIsolationR04_sumPUPt_(false),
  c_mus_pfIsolationR04_sumPhotonEt_(false),
  c_mus_pfIsolationR04_sumPhotonEtHighThreshold_(false),
  c_mus_phi_(false),
  c_mus_picky_ExpectedHitsInner_(false),
  c_mus_picky_ExpectedHitsOuter_(false),
  c_mus_picky_LayersWithMeasurement_(false),
  c_mus_picky_LayersWithoutMeasurement_(false),
  c_mus_picky_PixelLayersWithMeasurement_(false),
  c_mus_picky_ValidStripLayersWithMonoAndStereoHit_(false),
  c_mus_picky_chg_(false),
  c_mus_picky_chi2_(false),
  c_mus_picky_d0dum_(false),
  c_mus_picky_d0dumErr_(false),
  c_mus_picky_dz_(false),
  c_mus_picky_dzErr_(false),
  c_mus_picky_eta_(false),
  c_mus_picky_etaErr_(false),
  c_mus_picky_id_(false),
  c_mus_picky_ndof_(false),
  c_mus_picky_numlosthits_(false),
  c_mus_picky_numvalPixelhits_(false),
  c_mus_picky_numvalhits_(false),
  c_mus_picky_phi_(false),
  c_mus_picky_phiErr_(false),
  c_mus_picky_pt_(false),
  c_mus_picky_ptErr_(false),
  c_mus_picky_px_(false),
  c_mus_picky_py_(false),
  c_mus_picky_pz_(false),
  c_mus_picky_theta_(false),
  c_mus_picky_vx_(false),
  c_mus_picky_vy_(false),
  c_mus_picky_vz_(false),
  c_mus_pt_(false),
  c_mus_px_(false),
  c_mus_py_(false),
  c_mus_pz_(false),
  c_mus_stamu_chg_(false),
  c_mus_stamu_chi2_(false),
  c_mus_stamu_d0dum_(false),
  c_mus_stamu_d0dumErr_(false),
  c_mus_stamu_dz_(false),
  c_mus_stamu_dzErr_(false),
  c_mus_stamu_eta_(false),
  c_mus_stamu_etaErr_(false),
  c_mus_stamu_ndof_(false),
  c_mus_stamu_numlosthits_(false),
  c_mus_stamu_numvalhits_(false),
  c_mus_stamu_phi_(false),
  c_mus_stamu_phiErr_(false),
  c_mus_stamu_pt_(false),
  c_mus_stamu_ptErr_(false),
  c_mus_stamu_px_(false),
  c_mus_stamu_py_(false),
  c_mus_stamu_pz_(false),
  c_mus_stamu_theta_(false),
  c_mus_stamu_vx_(false),
  c_mus_stamu_vy_(false),
  c_mus_stamu_vz_(false),
  c_mus_status_(false),
  c_mus_tIso_(false),
  c_mus_theta_(false),
  c_mus_tkHits_(false),
  c_mus_tk_ExpectedHitsInner_(false),
  c_mus_tk_ExpectedHitsOuter_(false),
  c_mus_tk_LayersWithMeasurement_(false),
  c_mus_tk_LayersWithoutMeasurement_(false),
  c_mus_tk_PixelLayersWithMeasurement_(false),
  c_mus_tk_ValidStripLayersWithMonoAndStereoHit_(false),
  c_mus_tk_chg_(false),
  c_mus_tk_chi2_(false),
  c_mus_tk_d0dum_(false),
  c_mus_tk_d0dumErr_(false),
  c_mus_tk_dz_(false),
  c_mus_tk_dzErr_(false),
  c_mus_tk_eta_(false),
  c_mus_tk_etaErr_(false),
  c_mus_tk_id_(false),
  c_mus_tk_ndof_(false),
  c_mus_tk_numlosthits_(false),
  c_mus_tk_numpixelWthMeasr_(false),
  c_mus_tk_numvalPixelhits_(false),
  c_mus_tk_numvalhits_(false),
  c_mus_tk_phi_(false),
  c_mus_tk_phiErr_(false),
  c_mus_tk_pt_(false),
  c_mus_tk_ptErr_(false),
  c_mus_tk_px_(false),
  c_mus_tk_py_(false),
  c_mus_tk_pz_(false),
  c_mus_tk_theta_(false),
  c_mus_tk_vx_(false),
  c_mus_tk_vy_(false),
  c_mus_tk_vz_(false),
  c_mus_tpfms_ExpectedHitsInner_(false),
  c_mus_tpfms_ExpectedHitsOuter_(false),
  c_mus_tpfms_LayersWithMeasurement_(false),
  c_mus_tpfms_LayersWithoutMeasurement_(false),
  c_mus_tpfms_PixelLayersWithMeasurement_(false),
  c_mus_tpfms_ValidStripLayersWithMonoAndStereoHit_(false),
  c_mus_tpfms_chg_(false),
  c_mus_tpfms_chi2_(false),
  c_mus_tpfms_d0dum_(false),
  c_mus_tpfms_d0dumErr_(false),
  c_mus_tpfms_dz_(false),
  c_mus_tpfms_dzErr_(false),
  c_mus_tpfms_eta_(false),
  c_mus_tpfms_etaErr_(false),
  c_mus_tpfms_id_(false),
  c_mus_tpfms_ndof_(false),
  c_mus_tpfms_numlosthits_(false),
  c_mus_tpfms_numvalPixelhits_(false),
  c_mus_tpfms_numvalhits_(false),
  c_mus_tpfms_phi_(false),
  c_mus_tpfms_phiErr_(false),
  c_mus_tpfms_pt_(false),
  c_mus_tpfms_ptErr_(false),
  c_mus_tpfms_px_(false),
  c_mus_tpfms_py_(false),
  c_mus_tpfms_pz_(false),
  c_mus_tpfms_theta_(false),
  c_mus_tpfms_vx_(false),
  c_mus_tpfms_vy_(false),
  c_mus_tpfms_vz_(false),
  c_orbitNumber_(false),
  c_pfcand_charge_(false),
  c_pfcand_energy_(false),
  c_pfcand_eta_(false),
  c_pfcand_pdgId_(false),
  c_pfcand_phi_(false),
  c_pfcand_pt_(false),
  c_pfcand_px_(false),
  c_pfcand_py_(false),
  c_pfcand_pz_(false),
  c_pfcand_theta_(false),
  c_photons_e1x5_(false),
  c_photons_e2x5_(false),
  c_photons_e3x3_(false),
  c_photons_e5x5_(false),
  c_photons_ecalIso_(false),
  c_photons_energy_(false),
  c_photons_et_(false),
  c_photons_eta_(false),
  c_photons_gen_et_(false),
  c_photons_gen_eta_(false),
  c_photons_gen_id_(false),
  c_photons_gen_phi_(false),
  c_photons_hadOverEM_(false),
  c_photons_hadTowOverEM_(false),
  c_photons_hasPixelSeed_(false),
  c_photons_hcalIso_(false),
  c_photons_isAlsoElectron_(false),
  c_photons_isConverted_(false),
  c_photons_isEBEEGap_(false),
  c_photons_isEBGap_(false),
  c_photons_isEBPho_(false),
  c_photons_isEEGap_(false),
  c_photons_isEEPho_(false),
  c_photons_isLoosePhoton_(false),
  c_photons_isTightPhoton_(false),
  c_photons_isoEcalRecHitDR03_(false),
  c_photons_isoEcalRecHitDR04_(false),
  c_photons_isoHcalRecHitDR03_(false),
  c_photons_isoHcalRecHitDR04_(false),
  c_photons_isoHollowTrkConeDR03_(false),
  c_photons_isoHollowTrkConeDR04_(false),
  c_photons_isoSolidTrkConeDR03_(false),
  c_photons_isoSolidTrkConeDR04_(false),
  c_photons_maxEnergyXtal_(false),
  c_photons_nTrkHollowConeDR03_(false),
  c_photons_nTrkHollowConeDR04_(false),
  c_photons_nTrkSolidConeDR03_(false),
  c_photons_nTrkSolidConeDR04_(false),
  c_photons_phi_(false),
  c_photons_pt_(false),
  c_photons_px_(false),
  c_photons_py_(false),
  c_photons_pz_(false),
  c_photons_r9_(false),
  c_photons_scEnergy_(false),
  c_photons_scEta_(false),
  c_photons_scEtaWidth_(false),
  c_photons_scPhi_(false),
  c_photons_scPhiWidth_(false),
  c_photons_scRawEnergy_(false),
  c_photons_sigmaEtaEta_(false),
  c_photons_sigmaIetaIeta_(false),
  c_photons_status_(false),
  c_photons_tIso_(false),
  c_photons_theta_(false),
  c_pv_chi2_(false),
  c_pv_isFake_(false),
  c_pv_isValid_(false),
  c_pv_ndof_(false),
  c_pv_tracksSize_(false),
  c_pv_x_(false),
  c_pv_xErr_(false),
  c_pv_y_(false),
  c_pv_yErr_(false),
  c_pv_z_(false),
  c_pv_zErr_(false),
  c_run_(false),
  c_standalone_triggerobject_collectionname_(false),
  c_standalone_triggerobject_energy_(false),
  c_standalone_triggerobject_et_(false),
  c_standalone_triggerobject_eta_(false),
  c_standalone_triggerobject_phi_(false),
  c_standalone_triggerobject_pt_(false),
  c_standalone_triggerobject_px_(false),
  c_standalone_triggerobject_py_(false),
  c_standalone_triggerobject_pz_(false),
  c_taus_Nprongs_(false),
  c_taus_againstElectron_(false),
  c_taus_againstElectronLoose_(false),
  c_taus_againstElectronMVA_(false),
  c_taus_againstElectronMedium_(false),
  c_taus_againstElectronTight_(false),
  c_taus_againstMuon_(false),
  c_taus_againstMuonLoose_(false),
  c_taus_againstMuonMedium_(false),
  c_taus_againstMuonTight_(false),
  c_taus_byIsoUsingLeadingPi_(false),
  c_taus_byIsolation_(false),
  c_taus_byLooseIsolation_(false),
  c_taus_byLooseIsolationDeltaBetaCorr_(false),
  c_taus_byMediumIsolation_(false),
  c_taus_byMediumIsolationDeltaBetaCorr_(false),
  c_taus_byTightIsolation_(false),
  c_taus_byTightIsolationDeltaBetaCorr_(false),
  c_taus_byVLooseIsolation_(false),
  c_taus_byVLooseIsolationDeltaBetaCorr_(false),
  c_taus_charge_(false),
  c_taus_decayModeFinding_(false),
  c_taus_ecalIsoUsingLeadingPi_(false),
  c_taus_ecalIsolation_(false),
  c_taus_ecalStripSumEOverPLead_(false),
  c_taus_el_ind_(false),
  c_taus_elecPreIdDecision_(false),
  c_taus_elecPreIdOutput_(false),
  c_taus_emf_(false),
  c_taus_energy_(false),
  c_taus_et_(false),
  c_taus_eta_(false),
  c_taus_hcal3x3OverPLead_(false),
  c_taus_hcalMaxOverPLead_(false),
  c_taus_hcalTotOverPLead_(false),
  c_taus_isoPFChargedHadrCandsPtSum_(false),
  c_taus_isoPFGammaCandsEtSum_(false),
  c_taus_leadPFChargedHadrCand_ECAL_eta_(false),
  c_taus_leadPFChargedHadrCand_charge_(false),
  c_taus_leadPFChargedHadrCand_eta_(false),
  c_taus_leadPFChargedHadrCand_phi_(false),
  c_taus_leadPFChargedHadrCand_pt_(false),
  c_taus_leadingTrackFinding_(false),
  c_taus_leadingTrackPtCut_(false),
  c_taus_muDecision_(false),
  c_taus_mu_ind_(false),
  c_taus_phi_(false),
  c_taus_pt_(false),
  c_taus_px_(false),
  c_taus_py_(false),
  c_taus_pz_(false),
  c_taus_signalPFChargedHadrCandsSize_(false),
  c_taus_status_(false),
  c_taus_taNC_(false),
  c_taus_taNC_half_(false),
  c_taus_taNC_one_(false),
  c_taus_taNC_quarter_(false),
  c_taus_taNC_tenth_(false),
  c_taus_theta_(false),
  c_taus_tkIsoUsingLeadingPi_(false),
  c_taus_trackIsolation_(false),
  c_trackingfailurefilter_decision_(false),
  c_trigger_decision_(false),
  c_trigger_name_(false),
  c_trigger_prescalevalue_(false),
  c_trkPOG_logErrorTooManyClustersfilter_decision_(false),
  c_trkPOG_manystripclus53Xfilter_decision_(false),
  c_trkPOG_toomanystripclus53Xfilter_decision_(false),
  c_trkPOGfilter_decision_(false),
  c_weight_(false){
  PrepareNewChains();
}

void cfa_13::GetEntry(const long entry){
  c_EcalDeadCellTriggerPrimitivefilter_decision_ = false;
  c_HBHENoisefilter_decision_ = false;
  c_METFiltersfilter_decision_ = false;
  c_NbeamSpot_ = false;
  c_Nels_ = false;
  c_Njets_AK4_ = false;
  c_Nmc_doc_ = false;
  c_Nmc_electrons_ = false;
  c_Nmc_final_ = false;
  c_Nmc_jets_ = false;
  c_Nmc_mus_ = false;
  c_Nmc_nues_ = false;
  c_Nmc_numus_ = false;
  c_Nmc_nutaus_ = false;
  c_Nmc_photons_ = false;
  c_Nmc_taus_ = false;
  c_Nmets_ = false;
  c_Nmus_ = false;
  c_Npfcand_ = false;
  c_Nphotons_ = false;
  c_Npv_ = false;
  c_Ntaus_ = false;
  c_PU_NumInteractions_ = false;
  c_PU_TrueNumInteractions_ = false;
  c_PU_bunchCrossing_ = false;
  c_PU_ntrks_highpT_ = false;
  c_PU_ntrks_lowpT_ = false;
  c_PU_sumpT_highpT_ = false;
  c_PU_sumpT_lowpT_ = false;
  c_PU_zpositions_ = false;
  c_beamSpot_beamWidthX_ = false;
  c_beamSpot_beamWidthXError_ = false;
  c_beamSpot_beamWidthY_ = false;
  c_beamSpot_beamWidthYError_ = false;
  c_beamSpot_dxdz_ = false;
  c_beamSpot_dxdzError_ = false;
  c_beamSpot_dydz_ = false;
  c_beamSpot_dydzError_ = false;
  c_beamSpot_sigmaZ_ = false;
  c_beamSpot_sigmaZ0Error_ = false;
  c_beamSpot_x_ = false;
  c_beamSpot_x0Error_ = false;
  c_beamSpot_y_ = false;
  c_beamSpot_y0Error_ = false;
  c_beamSpot_z_ = false;
  c_beamSpot_z0Error_ = false;
  c_bunchCrossing_ = false;
  c_cschalofilter_decision_ = false;
  c_ecallaserfilter_decision_ = false;
  c_eebadscfilter_decision_ = false;
  c_els_PATpassConversionVeto_ = false;
  c_els_basicClustersSize_ = false;
  c_els_cIso_ = false;
  c_els_caloEnergy_ = false;
  c_els_charge_ = false;
  c_els_chi2_ = false;
  c_els_core_ecalDrivenSeed_ = false;
  c_els_cpx_ = false;
  c_els_cpy_ = false;
  c_els_cpz_ = false;
  c_els_ctf_tk_charge_ = false;
  c_els_ctf_tk_eta_ = false;
  c_els_ctf_tk_id_ = false;
  c_els_ctf_tk_phi_ = false;
  c_els_cx_ = false;
  c_els_cy_ = false;
  c_els_cz_ = false;
  c_els_d0dum_ = false;
  c_els_d0dumError_ = false;
  c_els_dEtaIn_ = false;
  c_els_dEtaOut_ = false;
  c_els_dPhiIn_ = false;
  c_els_dPhiOut_ = false;
  c_els_dr03EcalRecHitSumEt_ = false;
  c_els_dr03HcalDepth1TowerSumEt_ = false;
  c_els_dr03HcalDepth2TowerSumEt_ = false;
  c_els_dr03HcalTowerSumEt_ = false;
  c_els_dr03TkSumPt_ = false;
  c_els_dr04EcalRecHitSumEt_ = false;
  c_els_dr04HcalDepth1TowerSumEt_ = false;
  c_els_dr04HcalDepth2TowerSumEt_ = false;
  c_els_dr04HcalTowerSumEt_ = false;
  c_els_dr04TkSumPt_ = false;
  c_els_dz_ = false;
  c_els_dzError_ = false;
  c_els_eOverPIn_ = false;
  c_els_eSeedOverPOut_ = false;
  c_els_ecalIso_ = false;
  c_els_energy_ = false;
  c_els_et_ = false;
  c_els_eta_ = false;
  c_els_etaError_ = false;
  c_els_fbrem_ = false;
  c_els_full5x5_sigmaIetaIeta_ = false;
  c_els_gen_et_ = false;
  c_els_gen_eta_ = false;
  c_els_gen_id_ = false;
  c_els_gen_mother_et_ = false;
  c_els_gen_mother_eta_ = false;
  c_els_gen_mother_id_ = false;
  c_els_gen_mother_phi_ = false;
  c_els_gen_mother_pt_ = false;
  c_els_gen_mother_px_ = false;
  c_els_gen_mother_py_ = false;
  c_els_gen_mother_pz_ = false;
  c_els_gen_mother_theta_ = false;
  c_els_gen_phi_ = false;
  c_els_gen_pt_ = false;
  c_els_gen_px_ = false;
  c_els_gen_py_ = false;
  c_els_gen_pz_ = false;
  c_els_gen_theta_ = false;
  c_els_hadOverEm_ = false;
  c_els_hcalIso_ = false;
  c_els_hcalOverEcalBc_ = false;
  c_els_isEB_ = false;
  c_els_isEE_ = false;
  c_els_isPF_ = false;
  c_els_jet_ind_ = false;
  c_els_looseId_ = false;
  c_els_n_inner_layer_ = false;
  c_els_n_outer_layer_ = false;
  c_els_ndof_ = false;
  c_els_numlosthits_ = false;
  c_els_numvalhits_ = false;
  c_els_pfIsolationR03_sumChargedHadronPt_ = false;
  c_els_pfIsolationR03_sumNeutralHadronEt_ = false;
  c_els_pfIsolationR03_sumPUPt_ = false;
  c_els_pfIsolationR03_sumPhotonEt_ = false;
  c_els_phi_ = false;
  c_els_phiError_ = false;
  c_els_pt_ = false;
  c_els_ptError_ = false;
  c_els_px_ = false;
  c_els_py_ = false;
  c_els_pz_ = false;
  c_els_robustHighEnergyId_ = false;
  c_els_robustLooseId_ = false;
  c_els_robustTightId_ = false;
  c_els_scE1x5_ = false;
  c_els_scE2x5Max_ = false;
  c_els_scE5x5_ = false;
  c_els_scEnergy_ = false;
  c_els_scEta_ = false;
  c_els_scEtaWidth_ = false;
  c_els_scPhi_ = false;
  c_els_scPhiWidth_ = false;
  c_els_scRawEnergy_ = false;
  c_els_scSeedEnergy_ = false;
  c_els_shFracInnerHits_ = false;
  c_els_sigmaEtaEta_ = false;
  c_els_sigmaIEtaIEta_ = false;
  c_els_simpleEleId60cIso_ = false;
  c_els_simpleEleId60relIso_ = false;
  c_els_simpleEleId70cIso_ = false;
  c_els_simpleEleId70relIso_ = false;
  c_els_simpleEleId80cIso_ = false;
  c_els_simpleEleId80relIso_ = false;
  c_els_simpleEleId85cIso_ = false;
  c_els_simpleEleId85relIso_ = false;
  c_els_simpleEleId90cIso_ = false;
  c_els_simpleEleId90relIso_ = false;
  c_els_simpleEleId95cIso_ = false;
  c_els_simpleEleId95relIso_ = false;
  c_els_status_ = false;
  c_els_tIso_ = false;
  c_els_theta_ = false;
  c_els_tightId_ = false;
  c_els_tk_charge_ = false;
  c_els_tk_eta_ = false;
  c_els_tk_phi_ = false;
  c_els_tk_pt_ = false;
  c_els_tk_pz_ = false;
  c_els_vpx_ = false;
  c_els_vpy_ = false;
  c_els_vpz_ = false;
  c_els_vx_ = false;
  c_els_vy_ = false;
  c_els_vz_ = false;
  c_event_ = false;
  c_experimentType_ = false;
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
  c_hcallaserfilter_decision_ = false;
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
  c_lumiblock_ = false;
  c_mc_doc_charge_ = false;
  c_mc_doc_energy_ = false;
  c_mc_doc_eta_ = false;
  c_mc_doc_ggrandmother_id_ = false;
  c_mc_doc_grandmother_id_ = false;
  c_mc_doc_id_ = false;
  c_mc_doc_mass_ = false;
  c_mc_doc_mother_id_ = false;
  c_mc_doc_mother_pt_ = false;
  c_mc_doc_numOfDaughters_ = false;
  c_mc_doc_numOfMothers_ = false;
  c_mc_doc_phi_ = false;
  c_mc_doc_pt_ = false;
  c_mc_doc_px_ = false;
  c_mc_doc_py_ = false;
  c_mc_doc_pz_ = false;
  c_mc_doc_status_ = false;
  c_mc_doc_theta_ = false;
  c_mc_doc_vertex_x_ = false;
  c_mc_doc_vertex_y_ = false;
  c_mc_doc_vertex_z_ = false;
  c_mc_electrons_charge_ = false;
  c_mc_electrons_energy_ = false;
  c_mc_electrons_eta_ = false;
  c_mc_electrons_ggrandmother_id_ = false;
  c_mc_electrons_grandmother_id_ = false;
  c_mc_electrons_id_ = false;
  c_mc_electrons_mass_ = false;
  c_mc_electrons_mother_id_ = false;
  c_mc_electrons_mother_pt_ = false;
  c_mc_electrons_numOfDaughters_ = false;
  c_mc_electrons_phi_ = false;
  c_mc_electrons_pt_ = false;
  c_mc_electrons_px_ = false;
  c_mc_electrons_py_ = false;
  c_mc_electrons_pz_ = false;
  c_mc_electrons_status_ = false;
  c_mc_electrons_theta_ = false;
  c_mc_electrons_vertex_x_ = false;
  c_mc_electrons_vertex_y_ = false;
  c_mc_electrons_vertex_z_ = false;
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
  c_mc_mus_charge_ = false;
  c_mc_mus_energy_ = false;
  c_mc_mus_eta_ = false;
  c_mc_mus_ggrandmother_id_ = false;
  c_mc_mus_grandmother_id_ = false;
  c_mc_mus_id_ = false;
  c_mc_mus_mass_ = false;
  c_mc_mus_mother_id_ = false;
  c_mc_mus_mother_pt_ = false;
  c_mc_mus_numOfDaughters_ = false;
  c_mc_mus_phi_ = false;
  c_mc_mus_pt_ = false;
  c_mc_mus_px_ = false;
  c_mc_mus_py_ = false;
  c_mc_mus_pz_ = false;
  c_mc_mus_status_ = false;
  c_mc_mus_theta_ = false;
  c_mc_mus_vertex_x_ = false;
  c_mc_mus_vertex_y_ = false;
  c_mc_mus_vertex_z_ = false;
  c_mc_nues_charge_ = false;
  c_mc_nues_energy_ = false;
  c_mc_nues_eta_ = false;
  c_mc_nues_ggrandmother_id_ = false;
  c_mc_nues_grandmother_id_ = false;
  c_mc_nues_id_ = false;
  c_mc_nues_mass_ = false;
  c_mc_nues_mother_id_ = false;
  c_mc_nues_mother_pt_ = false;
  c_mc_nues_numOfDaughters_ = false;
  c_mc_nues_phi_ = false;
  c_mc_nues_pt_ = false;
  c_mc_nues_px_ = false;
  c_mc_nues_py_ = false;
  c_mc_nues_pz_ = false;
  c_mc_nues_status_ = false;
  c_mc_nues_theta_ = false;
  c_mc_nues_vertex_x_ = false;
  c_mc_nues_vertex_y_ = false;
  c_mc_nues_vertex_z_ = false;
  c_mc_numus_charge_ = false;
  c_mc_numus_energy_ = false;
  c_mc_numus_eta_ = false;
  c_mc_numus_ggrandmother_id_ = false;
  c_mc_numus_grandmother_id_ = false;
  c_mc_numus_id_ = false;
  c_mc_numus_mass_ = false;
  c_mc_numus_mother_id_ = false;
  c_mc_numus_mother_pt_ = false;
  c_mc_numus_numOfDaughters_ = false;
  c_mc_numus_phi_ = false;
  c_mc_numus_pt_ = false;
  c_mc_numus_px_ = false;
  c_mc_numus_py_ = false;
  c_mc_numus_pz_ = false;
  c_mc_numus_status_ = false;
  c_mc_numus_theta_ = false;
  c_mc_numus_vertex_x_ = false;
  c_mc_numus_vertex_y_ = false;
  c_mc_numus_vertex_z_ = false;
  c_mc_nutaus_charge_ = false;
  c_mc_nutaus_energy_ = false;
  c_mc_nutaus_eta_ = false;
  c_mc_nutaus_ggrandmother_id_ = false;
  c_mc_nutaus_grandmother_id_ = false;
  c_mc_nutaus_id_ = false;
  c_mc_nutaus_mass_ = false;
  c_mc_nutaus_mother_id_ = false;
  c_mc_nutaus_mother_pt_ = false;
  c_mc_nutaus_numOfDaughters_ = false;
  c_mc_nutaus_phi_ = false;
  c_mc_nutaus_pt_ = false;
  c_mc_nutaus_px_ = false;
  c_mc_nutaus_py_ = false;
  c_mc_nutaus_pz_ = false;
  c_mc_nutaus_status_ = false;
  c_mc_nutaus_theta_ = false;
  c_mc_nutaus_vertex_x_ = false;
  c_mc_nutaus_vertex_y_ = false;
  c_mc_nutaus_vertex_z_ = false;
  c_mc_photons_charge_ = false;
  c_mc_photons_energy_ = false;
  c_mc_photons_eta_ = false;
  c_mc_photons_ggrandmother_id_ = false;
  c_mc_photons_grandmother_id_ = false;
  c_mc_photons_id_ = false;
  c_mc_photons_mass_ = false;
  c_mc_photons_mother_id_ = false;
  c_mc_photons_mother_pt_ = false;
  c_mc_photons_numOfDaughters_ = false;
  c_mc_photons_phi_ = false;
  c_mc_photons_pt_ = false;
  c_mc_photons_px_ = false;
  c_mc_photons_py_ = false;
  c_mc_photons_pz_ = false;
  c_mc_photons_status_ = false;
  c_mc_photons_theta_ = false;
  c_mc_photons_vertex_x_ = false;
  c_mc_photons_vertex_y_ = false;
  c_mc_photons_vertex_z_ = false;
  c_mc_taus_charge_ = false;
  c_mc_taus_energy_ = false;
  c_mc_taus_eta_ = false;
  c_mc_taus_ggrandmother_id_ = false;
  c_mc_taus_grandmother_id_ = false;
  c_mc_taus_id_ = false;
  c_mc_taus_mass_ = false;
  c_mc_taus_mother_id_ = false;
  c_mc_taus_mother_pt_ = false;
  c_mc_taus_numOfDaughters_ = false;
  c_mc_taus_phi_ = false;
  c_mc_taus_pt_ = false;
  c_mc_taus_px_ = false;
  c_mc_taus_py_ = false;
  c_mc_taus_pz_ = false;
  c_mc_taus_status_ = false;
  c_mc_taus_theta_ = false;
  c_mc_taus_vertex_x_ = false;
  c_mc_taus_vertex_y_ = false;
  c_mc_taus_vertex_z_ = false;
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
  c_model_params_ = false;
  c_mus_cIso_ = false;
  c_mus_calEnergyEm_ = false;
  c_mus_calEnergyEmS9_ = false;
  c_mus_calEnergyHad_ = false;
  c_mus_calEnergyHadS9_ = false;
  c_mus_calEnergyHo_ = false;
  c_mus_calEnergyHoS9_ = false;
  c_mus_charge_ = false;
  c_mus_cm_ExpectedHitsInner_ = false;
  c_mus_cm_ExpectedHitsOuter_ = false;
  c_mus_cm_LayersWithMeasurement_ = false;
  c_mus_cm_LayersWithoutMeasurement_ = false;
  c_mus_cm_PixelLayersWithMeasurement_ = false;
  c_mus_cm_ValidStripLayersWithMonoAndStereoHit_ = false;
  c_mus_cm_chg_ = false;
  c_mus_cm_chi2_ = false;
  c_mus_cm_d0dum_ = false;
  c_mus_cm_d0dumErr_ = false;
  c_mus_cm_dz_ = false;
  c_mus_cm_dzErr_ = false;
  c_mus_cm_eta_ = false;
  c_mus_cm_etaErr_ = false;
  c_mus_cm_ndof_ = false;
  c_mus_cm_numlosthits_ = false;
  c_mus_cm_numvalMuonhits_ = false;
  c_mus_cm_numvalhits_ = false;
  c_mus_cm_phi_ = false;
  c_mus_cm_phiErr_ = false;
  c_mus_cm_pt_ = false;
  c_mus_cm_ptErr_ = false;
  c_mus_cm_px_ = false;
  c_mus_cm_py_ = false;
  c_mus_cm_pz_ = false;
  c_mus_cm_theta_ = false;
  c_mus_cm_vx_ = false;
  c_mus_cm_vy_ = false;
  c_mus_cm_vz_ = false;
  c_mus_dB_ = false;
  c_mus_ecalIso_ = false;
  c_mus_ecalvetoDep_ = false;
  c_mus_energy_ = false;
  c_mus_et_ = false;
  c_mus_eta_ = false;
  c_mus_gen_et_ = false;
  c_mus_gen_eta_ = false;
  c_mus_gen_id_ = false;
  c_mus_gen_mother_et_ = false;
  c_mus_gen_mother_eta_ = false;
  c_mus_gen_mother_id_ = false;
  c_mus_gen_mother_phi_ = false;
  c_mus_gen_mother_pt_ = false;
  c_mus_gen_mother_px_ = false;
  c_mus_gen_mother_py_ = false;
  c_mus_gen_mother_pz_ = false;
  c_mus_gen_mother_theta_ = false;
  c_mus_gen_phi_ = false;
  c_mus_gen_pt_ = false;
  c_mus_gen_px_ = false;
  c_mus_gen_py_ = false;
  c_mus_gen_pz_ = false;
  c_mus_gen_theta_ = false;
  c_mus_hcalIso_ = false;
  c_mus_hcalvetoDep_ = false;
  c_mus_id_All_ = false;
  c_mus_id_AllArbitrated_ = false;
  c_mus_id_AllGlobalMuons_ = false;
  c_mus_id_AllStandAloneMuons_ = false;
  c_mus_id_AllTrackerMuons_ = false;
  c_mus_id_GlobalMuonPromptTight_ = false;
  c_mus_id_TM2DCompatibilityLoose_ = false;
  c_mus_id_TM2DCompatibilityTight_ = false;
  c_mus_id_TMLastStationLoose_ = false;
  c_mus_id_TMLastStationOptimizedLowPtLoose_ = false;
  c_mus_id_TMLastStationOptimizedLowPtTight_ = false;
  c_mus_id_TMLastStationTight_ = false;
  c_mus_id_TMOneStationLoose_ = false;
  c_mus_id_TMOneStationTight_ = false;
  c_mus_id_TrackerMuonArbitrated_ = false;
  c_mus_isCaloMuon_ = false;
  c_mus_isConvertedPhoton_ = false;
  c_mus_isElectron_ = false;
  c_mus_isGlobalMuon_ = false;
  c_mus_isPF_ = false;
  c_mus_isPFMuon_ = false;
  c_mus_isPhoton_ = false;
  c_mus_isStandAloneMuon_ = false;
  c_mus_isTrackerMuon_ = false;
  c_mus_iso03_emEt_ = false;
  c_mus_iso03_emVetoEt_ = false;
  c_mus_iso03_hadEt_ = false;
  c_mus_iso03_hadVetoEt_ = false;
  c_mus_iso03_hoEt_ = false;
  c_mus_iso03_nTracks_ = false;
  c_mus_iso03_sumPt_ = false;
  c_mus_iso05_emEt_ = false;
  c_mus_iso05_hadEt_ = false;
  c_mus_iso05_hoEt_ = false;
  c_mus_iso05_nTracks_ = false;
  c_mus_iso05_sumPt_ = false;
  c_mus_jet_ind_ = false;
  c_mus_num_matches_ = false;
  c_mus_numberOfMatchedStations_ = false;
  c_mus_pfIsolationR03_sumChargedHadronPt_ = false;
  c_mus_pfIsolationR03_sumChargedParticlePt_ = false;
  c_mus_pfIsolationR03_sumNeutralHadronEt_ = false;
  c_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_ = false;
  c_mus_pfIsolationR03_sumPUPt_ = false;
  c_mus_pfIsolationR03_sumPhotonEt_ = false;
  c_mus_pfIsolationR03_sumPhotonEtHighThreshold_ = false;
  c_mus_pfIsolationR04_sumChargedHadronPt_ = false;
  c_mus_pfIsolationR04_sumChargedParticlePt_ = false;
  c_mus_pfIsolationR04_sumNeutralHadronEt_ = false;
  c_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_ = false;
  c_mus_pfIsolationR04_sumPUPt_ = false;
  c_mus_pfIsolationR04_sumPhotonEt_ = false;
  c_mus_pfIsolationR04_sumPhotonEtHighThreshold_ = false;
  c_mus_phi_ = false;
  c_mus_picky_ExpectedHitsInner_ = false;
  c_mus_picky_ExpectedHitsOuter_ = false;
  c_mus_picky_LayersWithMeasurement_ = false;
  c_mus_picky_LayersWithoutMeasurement_ = false;
  c_mus_picky_PixelLayersWithMeasurement_ = false;
  c_mus_picky_ValidStripLayersWithMonoAndStereoHit_ = false;
  c_mus_picky_chg_ = false;
  c_mus_picky_chi2_ = false;
  c_mus_picky_d0dum_ = false;
  c_mus_picky_d0dumErr_ = false;
  c_mus_picky_dz_ = false;
  c_mus_picky_dzErr_ = false;
  c_mus_picky_eta_ = false;
  c_mus_picky_etaErr_ = false;
  c_mus_picky_id_ = false;
  c_mus_picky_ndof_ = false;
  c_mus_picky_numlosthits_ = false;
  c_mus_picky_numvalPixelhits_ = false;
  c_mus_picky_numvalhits_ = false;
  c_mus_picky_phi_ = false;
  c_mus_picky_phiErr_ = false;
  c_mus_picky_pt_ = false;
  c_mus_picky_ptErr_ = false;
  c_mus_picky_px_ = false;
  c_mus_picky_py_ = false;
  c_mus_picky_pz_ = false;
  c_mus_picky_theta_ = false;
  c_mus_picky_vx_ = false;
  c_mus_picky_vy_ = false;
  c_mus_picky_vz_ = false;
  c_mus_pt_ = false;
  c_mus_px_ = false;
  c_mus_py_ = false;
  c_mus_pz_ = false;
  c_mus_stamu_chg_ = false;
  c_mus_stamu_chi2_ = false;
  c_mus_stamu_d0dum_ = false;
  c_mus_stamu_d0dumErr_ = false;
  c_mus_stamu_dz_ = false;
  c_mus_stamu_dzErr_ = false;
  c_mus_stamu_eta_ = false;
  c_mus_stamu_etaErr_ = false;
  c_mus_stamu_ndof_ = false;
  c_mus_stamu_numlosthits_ = false;
  c_mus_stamu_numvalhits_ = false;
  c_mus_stamu_phi_ = false;
  c_mus_stamu_phiErr_ = false;
  c_mus_stamu_pt_ = false;
  c_mus_stamu_ptErr_ = false;
  c_mus_stamu_px_ = false;
  c_mus_stamu_py_ = false;
  c_mus_stamu_pz_ = false;
  c_mus_stamu_theta_ = false;
  c_mus_stamu_vx_ = false;
  c_mus_stamu_vy_ = false;
  c_mus_stamu_vz_ = false;
  c_mus_status_ = false;
  c_mus_tIso_ = false;
  c_mus_theta_ = false;
  c_mus_tkHits_ = false;
  c_mus_tk_ExpectedHitsInner_ = false;
  c_mus_tk_ExpectedHitsOuter_ = false;
  c_mus_tk_LayersWithMeasurement_ = false;
  c_mus_tk_LayersWithoutMeasurement_ = false;
  c_mus_tk_PixelLayersWithMeasurement_ = false;
  c_mus_tk_ValidStripLayersWithMonoAndStereoHit_ = false;
  c_mus_tk_chg_ = false;
  c_mus_tk_chi2_ = false;
  c_mus_tk_d0dum_ = false;
  c_mus_tk_d0dumErr_ = false;
  c_mus_tk_dz_ = false;
  c_mus_tk_dzErr_ = false;
  c_mus_tk_eta_ = false;
  c_mus_tk_etaErr_ = false;
  c_mus_tk_id_ = false;
  c_mus_tk_ndof_ = false;
  c_mus_tk_numlosthits_ = false;
  c_mus_tk_numpixelWthMeasr_ = false;
  c_mus_tk_numvalPixelhits_ = false;
  c_mus_tk_numvalhits_ = false;
  c_mus_tk_phi_ = false;
  c_mus_tk_phiErr_ = false;
  c_mus_tk_pt_ = false;
  c_mus_tk_ptErr_ = false;
  c_mus_tk_px_ = false;
  c_mus_tk_py_ = false;
  c_mus_tk_pz_ = false;
  c_mus_tk_theta_ = false;
  c_mus_tk_vx_ = false;
  c_mus_tk_vy_ = false;
  c_mus_tk_vz_ = false;
  c_mus_tpfms_ExpectedHitsInner_ = false;
  c_mus_tpfms_ExpectedHitsOuter_ = false;
  c_mus_tpfms_LayersWithMeasurement_ = false;
  c_mus_tpfms_LayersWithoutMeasurement_ = false;
  c_mus_tpfms_PixelLayersWithMeasurement_ = false;
  c_mus_tpfms_ValidStripLayersWithMonoAndStereoHit_ = false;
  c_mus_tpfms_chg_ = false;
  c_mus_tpfms_chi2_ = false;
  c_mus_tpfms_d0dum_ = false;
  c_mus_tpfms_d0dumErr_ = false;
  c_mus_tpfms_dz_ = false;
  c_mus_tpfms_dzErr_ = false;
  c_mus_tpfms_eta_ = false;
  c_mus_tpfms_etaErr_ = false;
  c_mus_tpfms_id_ = false;
  c_mus_tpfms_ndof_ = false;
  c_mus_tpfms_numlosthits_ = false;
  c_mus_tpfms_numvalPixelhits_ = false;
  c_mus_tpfms_numvalhits_ = false;
  c_mus_tpfms_phi_ = false;
  c_mus_tpfms_phiErr_ = false;
  c_mus_tpfms_pt_ = false;
  c_mus_tpfms_ptErr_ = false;
  c_mus_tpfms_px_ = false;
  c_mus_tpfms_py_ = false;
  c_mus_tpfms_pz_ = false;
  c_mus_tpfms_theta_ = false;
  c_mus_tpfms_vx_ = false;
  c_mus_tpfms_vy_ = false;
  c_mus_tpfms_vz_ = false;
  c_orbitNumber_ = false;
  c_pfcand_charge_ = false;
  c_pfcand_energy_ = false;
  c_pfcand_eta_ = false;
  c_pfcand_pdgId_ = false;
  c_pfcand_phi_ = false;
  c_pfcand_pt_ = false;
  c_pfcand_px_ = false;
  c_pfcand_py_ = false;
  c_pfcand_pz_ = false;
  c_pfcand_theta_ = false;
  c_photons_e1x5_ = false;
  c_photons_e2x5_ = false;
  c_photons_e3x3_ = false;
  c_photons_e5x5_ = false;
  c_photons_ecalIso_ = false;
  c_photons_energy_ = false;
  c_photons_et_ = false;
  c_photons_eta_ = false;
  c_photons_gen_et_ = false;
  c_photons_gen_eta_ = false;
  c_photons_gen_id_ = false;
  c_photons_gen_phi_ = false;
  c_photons_hadOverEM_ = false;
  c_photons_hadTowOverEM_ = false;
  c_photons_hasPixelSeed_ = false;
  c_photons_hcalIso_ = false;
  c_photons_isAlsoElectron_ = false;
  c_photons_isConverted_ = false;
  c_photons_isEBEEGap_ = false;
  c_photons_isEBGap_ = false;
  c_photons_isEBPho_ = false;
  c_photons_isEEGap_ = false;
  c_photons_isEEPho_ = false;
  c_photons_isLoosePhoton_ = false;
  c_photons_isTightPhoton_ = false;
  c_photons_isoEcalRecHitDR03_ = false;
  c_photons_isoEcalRecHitDR04_ = false;
  c_photons_isoHcalRecHitDR03_ = false;
  c_photons_isoHcalRecHitDR04_ = false;
  c_photons_isoHollowTrkConeDR03_ = false;
  c_photons_isoHollowTrkConeDR04_ = false;
  c_photons_isoSolidTrkConeDR03_ = false;
  c_photons_isoSolidTrkConeDR04_ = false;
  c_photons_maxEnergyXtal_ = false;
  c_photons_nTrkHollowConeDR03_ = false;
  c_photons_nTrkHollowConeDR04_ = false;
  c_photons_nTrkSolidConeDR03_ = false;
  c_photons_nTrkSolidConeDR04_ = false;
  c_photons_phi_ = false;
  c_photons_pt_ = false;
  c_photons_px_ = false;
  c_photons_py_ = false;
  c_photons_pz_ = false;
  c_photons_r9_ = false;
  c_photons_scEnergy_ = false;
  c_photons_scEta_ = false;
  c_photons_scEtaWidth_ = false;
  c_photons_scPhi_ = false;
  c_photons_scPhiWidth_ = false;
  c_photons_scRawEnergy_ = false;
  c_photons_sigmaEtaEta_ = false;
  c_photons_sigmaIetaIeta_ = false;
  c_photons_status_ = false;
  c_photons_tIso_ = false;
  c_photons_theta_ = false;
  c_pv_chi2_ = false;
  c_pv_isFake_ = false;
  c_pv_isValid_ = false;
  c_pv_ndof_ = false;
  c_pv_tracksSize_ = false;
  c_pv_x_ = false;
  c_pv_xErr_ = false;
  c_pv_y_ = false;
  c_pv_yErr_ = false;
  c_pv_z_ = false;
  c_pv_zErr_ = false;
  c_run_ = false;
  c_standalone_triggerobject_collectionname_ = false;
  c_standalone_triggerobject_energy_ = false;
  c_standalone_triggerobject_et_ = false;
  c_standalone_triggerobject_eta_ = false;
  c_standalone_triggerobject_phi_ = false;
  c_standalone_triggerobject_pt_ = false;
  c_standalone_triggerobject_px_ = false;
  c_standalone_triggerobject_py_ = false;
  c_standalone_triggerobject_pz_ = false;
  c_taus_Nprongs_ = false;
  c_taus_againstElectron_ = false;
  c_taus_againstElectronLoose_ = false;
  c_taus_againstElectronMVA_ = false;
  c_taus_againstElectronMedium_ = false;
  c_taus_againstElectronTight_ = false;
  c_taus_againstMuon_ = false;
  c_taus_againstMuonLoose_ = false;
  c_taus_againstMuonMedium_ = false;
  c_taus_againstMuonTight_ = false;
  c_taus_byIsoUsingLeadingPi_ = false;
  c_taus_byIsolation_ = false;
  c_taus_byLooseIsolation_ = false;
  c_taus_byLooseIsolationDeltaBetaCorr_ = false;
  c_taus_byMediumIsolation_ = false;
  c_taus_byMediumIsolationDeltaBetaCorr_ = false;
  c_taus_byTightIsolation_ = false;
  c_taus_byTightIsolationDeltaBetaCorr_ = false;
  c_taus_byVLooseIsolation_ = false;
  c_taus_byVLooseIsolationDeltaBetaCorr_ = false;
  c_taus_charge_ = false;
  c_taus_decayModeFinding_ = false;
  c_taus_ecalIsoUsingLeadingPi_ = false;
  c_taus_ecalIsolation_ = false;
  c_taus_ecalStripSumEOverPLead_ = false;
  c_taus_el_ind_ = false;
  c_taus_elecPreIdDecision_ = false;
  c_taus_elecPreIdOutput_ = false;
  c_taus_emf_ = false;
  c_taus_energy_ = false;
  c_taus_et_ = false;
  c_taus_eta_ = false;
  c_taus_hcal3x3OverPLead_ = false;
  c_taus_hcalMaxOverPLead_ = false;
  c_taus_hcalTotOverPLead_ = false;
  c_taus_isoPFChargedHadrCandsPtSum_ = false;
  c_taus_isoPFGammaCandsEtSum_ = false;
  c_taus_leadPFChargedHadrCand_ECAL_eta_ = false;
  c_taus_leadPFChargedHadrCand_charge_ = false;
  c_taus_leadPFChargedHadrCand_eta_ = false;
  c_taus_leadPFChargedHadrCand_phi_ = false;
  c_taus_leadPFChargedHadrCand_pt_ = false;
  c_taus_leadingTrackFinding_ = false;
  c_taus_leadingTrackPtCut_ = false;
  c_taus_muDecision_ = false;
  c_taus_mu_ind_ = false;
  c_taus_phi_ = false;
  c_taus_pt_ = false;
  c_taus_px_ = false;
  c_taus_py_ = false;
  c_taus_pz_ = false;
  c_taus_signalPFChargedHadrCandsSize_ = false;
  c_taus_status_ = false;
  c_taus_taNC_ = false;
  c_taus_taNC_half_ = false;
  c_taus_taNC_one_ = false;
  c_taus_taNC_quarter_ = false;
  c_taus_taNC_tenth_ = false;
  c_taus_theta_ = false;
  c_taus_tkIsoUsingLeadingPi_ = false;
  c_taus_trackIsolation_ = false;
  c_trackingfailurefilter_decision_ = false;
  c_trigger_decision_ = false;
  c_trigger_name_ = false;
  c_trigger_prescalevalue_ = false;
  c_trkPOG_logErrorTooManyClustersfilter_decision_ = false;
  c_trkPOG_manystripclus53Xfilter_decision_ = false;
  c_trkPOG_toomanystripclus53Xfilter_decision_ = false;
  c_trkPOGfilter_decision_ = false;
  c_weight_ = false;
  entry_ = entry;
}

void cfa_13::InitializeA(){
  chainA_.SetBranchAddress("EcalDeadCellTriggerPrimitivefilter_decision", &EcalDeadCellTriggerPrimitivefilter_decision_, &b_EcalDeadCellTriggerPrimitivefilter_decision_);
  chainA_.SetBranchAddress("HBHENoisefilter_decision", &HBHENoisefilter_decision_, &b_HBHENoisefilter_decision_);
  chainA_.SetBranchAddress("METFiltersfilter_decision", &METFiltersfilter_decision_, &b_METFiltersfilter_decision_);
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
  chainA_.SetBranchAddress("els_isPF", &els_isPF_, &b_els_isPF_);
  chainA_.SetBranchAddress("els_jet_ind", &els_jet_ind_, &b_els_jet_ind_);
  chainA_.SetBranchAddress("goodVerticesfilter_decision", &goodVerticesfilter_decision_, &b_goodVerticesfilter_decision_);
  chainA_.SetBranchAddress("hcallaserfilter_decision", &hcallaserfilter_decision_, &b_hcallaserfilter_decision_);
  chainA_.SetBranchAddress("jets_AK4_el_ind", &jets_AK4_el_ind_, &b_jets_AK4_el_ind_);
  chainA_.SetBranchAddress("jets_AK4_maxpt_id", &jets_AK4_maxpt_id_, &b_jets_AK4_maxpt_id_);
  chainA_.SetBranchAddress("jets_AK4_mu_ind", &jets_AK4_mu_ind_, &b_jets_AK4_mu_ind_);
  chainA_.SetBranchAddress("mus_isPF", &mus_isPF_, &b_mus_isPF_);
  chainA_.SetBranchAddress("mus_jet_ind", &mus_jet_ind_, &b_mus_jet_ind_);
  chainA_.SetBranchAddress("standalone_triggerobject_collectionname", &standalone_triggerobject_collectionname_, &b_standalone_triggerobject_collectionname_);
  chainA_.SetBranchAddress("standalone_triggerobject_energy", &standalone_triggerobject_energy_, &b_standalone_triggerobject_energy_);
  chainA_.SetBranchAddress("standalone_triggerobject_et", &standalone_triggerobject_et_, &b_standalone_triggerobject_et_);
  chainA_.SetBranchAddress("standalone_triggerobject_eta", &standalone_triggerobject_eta_, &b_standalone_triggerobject_eta_);
  chainA_.SetBranchAddress("standalone_triggerobject_phi", &standalone_triggerobject_phi_, &b_standalone_triggerobject_phi_);
  chainA_.SetBranchAddress("standalone_triggerobject_pt", &standalone_triggerobject_pt_, &b_standalone_triggerobject_pt_);
  chainA_.SetBranchAddress("standalone_triggerobject_px", &standalone_triggerobject_px_, &b_standalone_triggerobject_px_);
  chainA_.SetBranchAddress("standalone_triggerobject_py", &standalone_triggerobject_py_, &b_standalone_triggerobject_py_);
  chainA_.SetBranchAddress("standalone_triggerobject_pz", &standalone_triggerobject_pz_, &b_standalone_triggerobject_pz_);
  chainA_.SetBranchAddress("taus_el_ind", &taus_el_ind_, &b_taus_el_ind_);
  chainA_.SetBranchAddress("taus_mu_ind", &taus_mu_ind_, &b_taus_mu_ind_);
  chainA_.SetBranchAddress("trackingfailurefilter_decision", &trackingfailurefilter_decision_, &b_trackingfailurefilter_decision_);
  chainA_.SetBranchAddress("trigger_decision", &trigger_decision_, &b_trigger_decision_);
  chainA_.SetBranchAddress("trigger_name", &trigger_name_, &b_trigger_name_);
  chainA_.SetBranchAddress("trigger_prescalevalue", &trigger_prescalevalue_, &b_trigger_prescalevalue_);
  chainA_.SetBranchAddress("trkPOG_logErrorTooManyClustersfilter_decision", &trkPOG_logErrorTooManyClustersfilter_decision_, &b_trkPOG_logErrorTooManyClustersfilter_decision_);
  chainA_.SetBranchAddress("trkPOG_manystripclus53Xfilter_decision", &trkPOG_manystripclus53Xfilter_decision_, &b_trkPOG_manystripclus53Xfilter_decision_);
  chainA_.SetBranchAddress("trkPOG_toomanystripclus53Xfilter_decision", &trkPOG_toomanystripclus53Xfilter_decision_, &b_trkPOG_toomanystripclus53Xfilter_decision_);
  chainA_.SetBranchAddress("trkPOGfilter_decision", &trkPOGfilter_decision_, &b_trkPOGfilter_decision_);
}

void cfa_13::InitializeB(){
  chainB_.SetBranchAddress("NbeamSpot", &NbeamSpot_, &b_NbeamSpot_);
  chainB_.SetBranchAddress("Nels", &Nels_, &b_Nels_);
  chainB_.SetBranchAddress("Njets_AK4", &Njets_AK4_, &b_Njets_AK4_);
  chainB_.SetBranchAddress("Nmc_doc", &Nmc_doc_, &b_Nmc_doc_);
  chainB_.SetBranchAddress("Nmc_electrons", &Nmc_electrons_, &b_Nmc_electrons_);
  chainB_.SetBranchAddress("Nmc_final", &Nmc_final_, &b_Nmc_final_);
  chainB_.SetBranchAddress("Nmc_jets", &Nmc_jets_, &b_Nmc_jets_);
  chainB_.SetBranchAddress("Nmc_mus", &Nmc_mus_, &b_Nmc_mus_);
  chainB_.SetBranchAddress("Nmc_nues", &Nmc_nues_, &b_Nmc_nues_);
  chainB_.SetBranchAddress("Nmc_numus", &Nmc_numus_, &b_Nmc_numus_);
  chainB_.SetBranchAddress("Nmc_nutaus", &Nmc_nutaus_, &b_Nmc_nutaus_);
  chainB_.SetBranchAddress("Nmc_photons", &Nmc_photons_, &b_Nmc_photons_);
  chainB_.SetBranchAddress("Nmc_taus", &Nmc_taus_, &b_Nmc_taus_);
  chainB_.SetBranchAddress("Nmets", &Nmets_, &b_Nmets_);
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
  chainB_.SetBranchAddress("els_full5x5_sigmaIetaIeta", &els_full5x5_sigmaIetaIeta_, &b_els_full5x5_sigmaIetaIeta_);
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
  chainB_.SetBranchAddress("els_pfIsolationR03_sumChargedHadronPt", &els_pfIsolationR03_sumChargedHadronPt_, &b_els_pfIsolationR03_sumChargedHadronPt_);
  chainB_.SetBranchAddress("els_pfIsolationR03_sumNeutralHadronEt", &els_pfIsolationR03_sumNeutralHadronEt_, &b_els_pfIsolationR03_sumNeutralHadronEt_);
  chainB_.SetBranchAddress("els_pfIsolationR03_sumPUPt", &els_pfIsolationR03_sumPUPt_, &b_els_pfIsolationR03_sumPUPt_);
  chainB_.SetBranchAddress("els_pfIsolationR03_sumPhotonEt", &els_pfIsolationR03_sumPhotonEt_, &b_els_pfIsolationR03_sumPhotonEt_);
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

UInt_t const & cfa_13::NbeamSpot() const{
  if(!c_NbeamSpot_ && b_NbeamSpot_){
    b_NbeamSpot_->GetEntry(entry_);
    c_NbeamSpot_ = true;
  }
  return NbeamSpot_;
}

UInt_t const & cfa_13::Nels() const{
  if(!c_Nels_ && b_Nels_){
    b_Nels_->GetEntry(entry_);
    c_Nels_ = true;
  }
  return Nels_;
}

UInt_t const & cfa_13::Njets_AK4() const{
  if(!c_Njets_AK4_ && b_Njets_AK4_){
    b_Njets_AK4_->GetEntry(entry_);
    c_Njets_AK4_ = true;
  }
  return Njets_AK4_;
}

UInt_t const & cfa_13::Nmc_doc() const{
  if(!c_Nmc_doc_ && b_Nmc_doc_){
    b_Nmc_doc_->GetEntry(entry_);
    c_Nmc_doc_ = true;
  }
  return Nmc_doc_;
}

UInt_t const & cfa_13::Nmc_electrons() const{
  if(!c_Nmc_electrons_ && b_Nmc_electrons_){
    b_Nmc_electrons_->GetEntry(entry_);
    c_Nmc_electrons_ = true;
  }
  return Nmc_electrons_;
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

UInt_t const & cfa_13::Nmc_mus() const{
  if(!c_Nmc_mus_ && b_Nmc_mus_){
    b_Nmc_mus_->GetEntry(entry_);
    c_Nmc_mus_ = true;
  }
  return Nmc_mus_;
}

UInt_t const & cfa_13::Nmc_nues() const{
  if(!c_Nmc_nues_ && b_Nmc_nues_){
    b_Nmc_nues_->GetEntry(entry_);
    c_Nmc_nues_ = true;
  }
  return Nmc_nues_;
}

UInt_t const & cfa_13::Nmc_numus() const{
  if(!c_Nmc_numus_ && b_Nmc_numus_){
    b_Nmc_numus_->GetEntry(entry_);
    c_Nmc_numus_ = true;
  }
  return Nmc_numus_;
}

UInt_t const & cfa_13::Nmc_nutaus() const{
  if(!c_Nmc_nutaus_ && b_Nmc_nutaus_){
    b_Nmc_nutaus_->GetEntry(entry_);
    c_Nmc_nutaus_ = true;
  }
  return Nmc_nutaus_;
}

UInt_t const & cfa_13::Nmc_photons() const{
  if(!c_Nmc_photons_ && b_Nmc_photons_){
    b_Nmc_photons_->GetEntry(entry_);
    c_Nmc_photons_ = true;
  }
  return Nmc_photons_;
}

UInt_t const & cfa_13::Nmc_taus() const{
  if(!c_Nmc_taus_ && b_Nmc_taus_){
    b_Nmc_taus_->GetEntry(entry_);
    c_Nmc_taus_ = true;
  }
  return Nmc_taus_;
}

UInt_t const & cfa_13::Nmets() const{
  if(!c_Nmets_ && b_Nmets_){
    b_Nmets_->GetEntry(entry_);
    c_Nmets_ = true;
  }
  return Nmets_;
}

UInt_t const & cfa_13::Nmus() const{
  if(!c_Nmus_ && b_Nmus_){
    b_Nmus_->GetEntry(entry_);
    c_Nmus_ = true;
  }
  return Nmus_;
}

UInt_t const & cfa_13::Npfcand() const{
  if(!c_Npfcand_ && b_Npfcand_){
    b_Npfcand_->GetEntry(entry_);
    c_Npfcand_ = true;
  }
  return Npfcand_;
}

UInt_t const & cfa_13::Nphotons() const{
  if(!c_Nphotons_ && b_Nphotons_){
    b_Nphotons_->GetEntry(entry_);
    c_Nphotons_ = true;
  }
  return Nphotons_;
}

UInt_t const & cfa_13::Npv() const{
  if(!c_Npv_ && b_Npv_){
    b_Npv_->GetEntry(entry_);
    c_Npv_ = true;
  }
  return Npv_;
}

UInt_t const & cfa_13::Ntaus() const{
  if(!c_Ntaus_ && b_Ntaus_){
    b_Ntaus_->GetEntry(entry_);
    c_Ntaus_ = true;
  }
  return Ntaus_;
}

std::vector<int>* const & cfa_13::PU_NumInteractions() const{
  if(!c_PU_NumInteractions_ && b_PU_NumInteractions_){
    b_PU_NumInteractions_->GetEntry(entry_);
    c_PU_NumInteractions_ = true;
  }
  return PU_NumInteractions_;
}

std::vector<float>* const & cfa_13::PU_TrueNumInteractions() const{
  if(!c_PU_TrueNumInteractions_ && b_PU_TrueNumInteractions_){
    b_PU_TrueNumInteractions_->GetEntry(entry_);
    c_PU_TrueNumInteractions_ = true;
  }
  return PU_TrueNumInteractions_;
}

std::vector<int>* const & cfa_13::PU_bunchCrossing() const{
  if(!c_PU_bunchCrossing_ && b_PU_bunchCrossing_){
    b_PU_bunchCrossing_->GetEntry(entry_);
    c_PU_bunchCrossing_ = true;
  }
  return PU_bunchCrossing_;
}

std::vector<std::vector<int> >* const & cfa_13::PU_ntrks_highpT() const{
  if(!c_PU_ntrks_highpT_ && b_PU_ntrks_highpT_){
    b_PU_ntrks_highpT_->GetEntry(entry_);
    c_PU_ntrks_highpT_ = true;
  }
  return PU_ntrks_highpT_;
}

std::vector<std::vector<int> >* const & cfa_13::PU_ntrks_lowpT() const{
  if(!c_PU_ntrks_lowpT_ && b_PU_ntrks_lowpT_){
    b_PU_ntrks_lowpT_->GetEntry(entry_);
    c_PU_ntrks_lowpT_ = true;
  }
  return PU_ntrks_lowpT_;
}

std::vector<std::vector<float> >* const & cfa_13::PU_sumpT_highpT() const{
  if(!c_PU_sumpT_highpT_ && b_PU_sumpT_highpT_){
    b_PU_sumpT_highpT_->GetEntry(entry_);
    c_PU_sumpT_highpT_ = true;
  }
  return PU_sumpT_highpT_;
}

std::vector<std::vector<float> >* const & cfa_13::PU_sumpT_lowpT() const{
  if(!c_PU_sumpT_lowpT_ && b_PU_sumpT_lowpT_){
    b_PU_sumpT_lowpT_->GetEntry(entry_);
    c_PU_sumpT_lowpT_ = true;
  }
  return PU_sumpT_lowpT_;
}

std::vector<std::vector<float> >* const & cfa_13::PU_zpositions() const{
  if(!c_PU_zpositions_ && b_PU_zpositions_){
    b_PU_zpositions_->GetEntry(entry_);
    c_PU_zpositions_ = true;
  }
  return PU_zpositions_;
}

std::vector<float>* const & cfa_13::beamSpot_beamWidthX() const{
  if(!c_beamSpot_beamWidthX_ && b_beamSpot_beamWidthX_){
    b_beamSpot_beamWidthX_->GetEntry(entry_);
    c_beamSpot_beamWidthX_ = true;
  }
  return beamSpot_beamWidthX_;
}

std::vector<float>* const & cfa_13::beamSpot_beamWidthXError() const{
  if(!c_beamSpot_beamWidthXError_ && b_beamSpot_beamWidthXError_){
    b_beamSpot_beamWidthXError_->GetEntry(entry_);
    c_beamSpot_beamWidthXError_ = true;
  }
  return beamSpot_beamWidthXError_;
}

std::vector<float>* const & cfa_13::beamSpot_beamWidthY() const{
  if(!c_beamSpot_beamWidthY_ && b_beamSpot_beamWidthY_){
    b_beamSpot_beamWidthY_->GetEntry(entry_);
    c_beamSpot_beamWidthY_ = true;
  }
  return beamSpot_beamWidthY_;
}

std::vector<float>* const & cfa_13::beamSpot_beamWidthYError() const{
  if(!c_beamSpot_beamWidthYError_ && b_beamSpot_beamWidthYError_){
    b_beamSpot_beamWidthYError_->GetEntry(entry_);
    c_beamSpot_beamWidthYError_ = true;
  }
  return beamSpot_beamWidthYError_;
}

std::vector<float>* const & cfa_13::beamSpot_dxdz() const{
  if(!c_beamSpot_dxdz_ && b_beamSpot_dxdz_){
    b_beamSpot_dxdz_->GetEntry(entry_);
    c_beamSpot_dxdz_ = true;
  }
  return beamSpot_dxdz_;
}

std::vector<float>* const & cfa_13::beamSpot_dxdzError() const{
  if(!c_beamSpot_dxdzError_ && b_beamSpot_dxdzError_){
    b_beamSpot_dxdzError_->GetEntry(entry_);
    c_beamSpot_dxdzError_ = true;
  }
  return beamSpot_dxdzError_;
}

std::vector<float>* const & cfa_13::beamSpot_dydz() const{
  if(!c_beamSpot_dydz_ && b_beamSpot_dydz_){
    b_beamSpot_dydz_->GetEntry(entry_);
    c_beamSpot_dydz_ = true;
  }
  return beamSpot_dydz_;
}

std::vector<float>* const & cfa_13::beamSpot_dydzError() const{
  if(!c_beamSpot_dydzError_ && b_beamSpot_dydzError_){
    b_beamSpot_dydzError_->GetEntry(entry_);
    c_beamSpot_dydzError_ = true;
  }
  return beamSpot_dydzError_;
}

std::vector<float>* const & cfa_13::beamSpot_sigmaZ() const{
  if(!c_beamSpot_sigmaZ_ && b_beamSpot_sigmaZ_){
    b_beamSpot_sigmaZ_->GetEntry(entry_);
    c_beamSpot_sigmaZ_ = true;
  }
  return beamSpot_sigmaZ_;
}

std::vector<float>* const & cfa_13::beamSpot_sigmaZ0Error() const{
  if(!c_beamSpot_sigmaZ0Error_ && b_beamSpot_sigmaZ0Error_){
    b_beamSpot_sigmaZ0Error_->GetEntry(entry_);
    c_beamSpot_sigmaZ0Error_ = true;
  }
  return beamSpot_sigmaZ0Error_;
}

std::vector<float>* const & cfa_13::beamSpot_x() const{
  if(!c_beamSpot_x_ && b_beamSpot_x_){
    b_beamSpot_x_->GetEntry(entry_);
    c_beamSpot_x_ = true;
  }
  return beamSpot_x_;
}

std::vector<float>* const & cfa_13::beamSpot_x0Error() const{
  if(!c_beamSpot_x0Error_ && b_beamSpot_x0Error_){
    b_beamSpot_x0Error_->GetEntry(entry_);
    c_beamSpot_x0Error_ = true;
  }
  return beamSpot_x0Error_;
}

std::vector<float>* const & cfa_13::beamSpot_y() const{
  if(!c_beamSpot_y_ && b_beamSpot_y_){
    b_beamSpot_y_->GetEntry(entry_);
    c_beamSpot_y_ = true;
  }
  return beamSpot_y_;
}

std::vector<float>* const & cfa_13::beamSpot_y0Error() const{
  if(!c_beamSpot_y0Error_ && b_beamSpot_y0Error_){
    b_beamSpot_y0Error_->GetEntry(entry_);
    c_beamSpot_y0Error_ = true;
  }
  return beamSpot_y0Error_;
}

std::vector<float>* const & cfa_13::beamSpot_z() const{
  if(!c_beamSpot_z_ && b_beamSpot_z_){
    b_beamSpot_z_->GetEntry(entry_);
    c_beamSpot_z_ = true;
  }
  return beamSpot_z_;
}

std::vector<float>* const & cfa_13::beamSpot_z0Error() const{
  if(!c_beamSpot_z0Error_ && b_beamSpot_z0Error_){
    b_beamSpot_z0Error_->GetEntry(entry_);
    c_beamSpot_z0Error_ = true;
  }
  return beamSpot_z0Error_;
}

UInt_t const & cfa_13::bunchCrossing() const{
  if(!c_bunchCrossing_ && b_bunchCrossing_){
    b_bunchCrossing_->GetEntry(entry_);
    c_bunchCrossing_ = true;
  }
  return bunchCrossing_;
}

Int_t const & cfa_13::cschalofilter_decision() const{
  if(!c_cschalofilter_decision_ && b_cschalofilter_decision_){
    b_cschalofilter_decision_->GetEntry(entry_);
    c_cschalofilter_decision_ = true;
  }
  return cschalofilter_decision_;
}

Int_t const & cfa_13::ecallaserfilter_decision() const{
  if(!c_ecallaserfilter_decision_ && b_ecallaserfilter_decision_){
    b_ecallaserfilter_decision_->GetEntry(entry_);
    c_ecallaserfilter_decision_ = true;
  }
  return ecallaserfilter_decision_;
}

Int_t const & cfa_13::eebadscfilter_decision() const{
  if(!c_eebadscfilter_decision_ && b_eebadscfilter_decision_){
    b_eebadscfilter_decision_->GetEntry(entry_);
    c_eebadscfilter_decision_ = true;
  }
  return eebadscfilter_decision_;
}

std::vector<float>* const & cfa_13::els_PATpassConversionVeto() const{
  if(!c_els_PATpassConversionVeto_ && b_els_PATpassConversionVeto_){
    b_els_PATpassConversionVeto_->GetEntry(entry_);
    c_els_PATpassConversionVeto_ = true;
  }
  return els_PATpassConversionVeto_;
}

std::vector<float>* const & cfa_13::els_basicClustersSize() const{
  if(!c_els_basicClustersSize_ && b_els_basicClustersSize_){
    b_els_basicClustersSize_->GetEntry(entry_);
    c_els_basicClustersSize_ = true;
  }
  return els_basicClustersSize_;
}

std::vector<float>* const & cfa_13::els_cIso() const{
  if(!c_els_cIso_ && b_els_cIso_){
    b_els_cIso_->GetEntry(entry_);
    c_els_cIso_ = true;
  }
  return els_cIso_;
}

std::vector<float>* const & cfa_13::els_caloEnergy() const{
  if(!c_els_caloEnergy_ && b_els_caloEnergy_){
    b_els_caloEnergy_->GetEntry(entry_);
    c_els_caloEnergy_ = true;
  }
  return els_caloEnergy_;
}

std::vector<float>* const & cfa_13::els_charge() const{
  if(!c_els_charge_ && b_els_charge_){
    b_els_charge_->GetEntry(entry_);
    c_els_charge_ = true;
  }
  return els_charge_;
}

std::vector<float>* const & cfa_13::els_chi2() const{
  if(!c_els_chi2_ && b_els_chi2_){
    b_els_chi2_->GetEntry(entry_);
    c_els_chi2_ = true;
  }
  return els_chi2_;
}

std::vector<float>* const & cfa_13::els_core_ecalDrivenSeed() const{
  if(!c_els_core_ecalDrivenSeed_ && b_els_core_ecalDrivenSeed_){
    b_els_core_ecalDrivenSeed_->GetEntry(entry_);
    c_els_core_ecalDrivenSeed_ = true;
  }
  return els_core_ecalDrivenSeed_;
}

std::vector<float>* const & cfa_13::els_cpx() const{
  if(!c_els_cpx_ && b_els_cpx_){
    b_els_cpx_->GetEntry(entry_);
    c_els_cpx_ = true;
  }
  return els_cpx_;
}

std::vector<float>* const & cfa_13::els_cpy() const{
  if(!c_els_cpy_ && b_els_cpy_){
    b_els_cpy_->GetEntry(entry_);
    c_els_cpy_ = true;
  }
  return els_cpy_;
}

std::vector<float>* const & cfa_13::els_cpz() const{
  if(!c_els_cpz_ && b_els_cpz_){
    b_els_cpz_->GetEntry(entry_);
    c_els_cpz_ = true;
  }
  return els_cpz_;
}

std::vector<float>* const & cfa_13::els_ctf_tk_charge() const{
  if(!c_els_ctf_tk_charge_ && b_els_ctf_tk_charge_){
    b_els_ctf_tk_charge_->GetEntry(entry_);
    c_els_ctf_tk_charge_ = true;
  }
  return els_ctf_tk_charge_;
}

std::vector<float>* const & cfa_13::els_ctf_tk_eta() const{
  if(!c_els_ctf_tk_eta_ && b_els_ctf_tk_eta_){
    b_els_ctf_tk_eta_->GetEntry(entry_);
    c_els_ctf_tk_eta_ = true;
  }
  return els_ctf_tk_eta_;
}

std::vector<float>* const & cfa_13::els_ctf_tk_id() const{
  if(!c_els_ctf_tk_id_ && b_els_ctf_tk_id_){
    b_els_ctf_tk_id_->GetEntry(entry_);
    c_els_ctf_tk_id_ = true;
  }
  return els_ctf_tk_id_;
}

std::vector<float>* const & cfa_13::els_ctf_tk_phi() const{
  if(!c_els_ctf_tk_phi_ && b_els_ctf_tk_phi_){
    b_els_ctf_tk_phi_->GetEntry(entry_);
    c_els_ctf_tk_phi_ = true;
  }
  return els_ctf_tk_phi_;
}

std::vector<float>* const & cfa_13::els_cx() const{
  if(!c_els_cx_ && b_els_cx_){
    b_els_cx_->GetEntry(entry_);
    c_els_cx_ = true;
  }
  return els_cx_;
}

std::vector<float>* const & cfa_13::els_cy() const{
  if(!c_els_cy_ && b_els_cy_){
    b_els_cy_->GetEntry(entry_);
    c_els_cy_ = true;
  }
  return els_cy_;
}

std::vector<float>* const & cfa_13::els_cz() const{
  if(!c_els_cz_ && b_els_cz_){
    b_els_cz_->GetEntry(entry_);
    c_els_cz_ = true;
  }
  return els_cz_;
}

std::vector<float>* const & cfa_13::els_d0dum() const{
  if(!c_els_d0dum_ && b_els_d0dum_){
    b_els_d0dum_->GetEntry(entry_);
    c_els_d0dum_ = true;
  }
  return els_d0dum_;
}

std::vector<float>* const & cfa_13::els_d0dumError() const{
  if(!c_els_d0dumError_ && b_els_d0dumError_){
    b_els_d0dumError_->GetEntry(entry_);
    c_els_d0dumError_ = true;
  }
  return els_d0dumError_;
}

std::vector<float>* const & cfa_13::els_dEtaIn() const{
  if(!c_els_dEtaIn_ && b_els_dEtaIn_){
    b_els_dEtaIn_->GetEntry(entry_);
    c_els_dEtaIn_ = true;
  }
  return els_dEtaIn_;
}

std::vector<float>* const & cfa_13::els_dEtaOut() const{
  if(!c_els_dEtaOut_ && b_els_dEtaOut_){
    b_els_dEtaOut_->GetEntry(entry_);
    c_els_dEtaOut_ = true;
  }
  return els_dEtaOut_;
}

std::vector<float>* const & cfa_13::els_dPhiIn() const{
  if(!c_els_dPhiIn_ && b_els_dPhiIn_){
    b_els_dPhiIn_->GetEntry(entry_);
    c_els_dPhiIn_ = true;
  }
  return els_dPhiIn_;
}

std::vector<float>* const & cfa_13::els_dPhiOut() const{
  if(!c_els_dPhiOut_ && b_els_dPhiOut_){
    b_els_dPhiOut_->GetEntry(entry_);
    c_els_dPhiOut_ = true;
  }
  return els_dPhiOut_;
}

std::vector<float>* const & cfa_13::els_dr03EcalRecHitSumEt() const{
  if(!c_els_dr03EcalRecHitSumEt_ && b_els_dr03EcalRecHitSumEt_){
    b_els_dr03EcalRecHitSumEt_->GetEntry(entry_);
    c_els_dr03EcalRecHitSumEt_ = true;
  }
  return els_dr03EcalRecHitSumEt_;
}

std::vector<float>* const & cfa_13::els_dr03HcalDepth1TowerSumEt() const{
  if(!c_els_dr03HcalDepth1TowerSumEt_ && b_els_dr03HcalDepth1TowerSumEt_){
    b_els_dr03HcalDepth1TowerSumEt_->GetEntry(entry_);
    c_els_dr03HcalDepth1TowerSumEt_ = true;
  }
  return els_dr03HcalDepth1TowerSumEt_;
}

std::vector<float>* const & cfa_13::els_dr03HcalDepth2TowerSumEt() const{
  if(!c_els_dr03HcalDepth2TowerSumEt_ && b_els_dr03HcalDepth2TowerSumEt_){
    b_els_dr03HcalDepth2TowerSumEt_->GetEntry(entry_);
    c_els_dr03HcalDepth2TowerSumEt_ = true;
  }
  return els_dr03HcalDepth2TowerSumEt_;
}

std::vector<float>* const & cfa_13::els_dr03HcalTowerSumEt() const{
  if(!c_els_dr03HcalTowerSumEt_ && b_els_dr03HcalTowerSumEt_){
    b_els_dr03HcalTowerSumEt_->GetEntry(entry_);
    c_els_dr03HcalTowerSumEt_ = true;
  }
  return els_dr03HcalTowerSumEt_;
}

std::vector<float>* const & cfa_13::els_dr03TkSumPt() const{
  if(!c_els_dr03TkSumPt_ && b_els_dr03TkSumPt_){
    b_els_dr03TkSumPt_->GetEntry(entry_);
    c_els_dr03TkSumPt_ = true;
  }
  return els_dr03TkSumPt_;
}

std::vector<float>* const & cfa_13::els_dr04EcalRecHitSumEt() const{
  if(!c_els_dr04EcalRecHitSumEt_ && b_els_dr04EcalRecHitSumEt_){
    b_els_dr04EcalRecHitSumEt_->GetEntry(entry_);
    c_els_dr04EcalRecHitSumEt_ = true;
  }
  return els_dr04EcalRecHitSumEt_;
}

std::vector<float>* const & cfa_13::els_dr04HcalDepth1TowerSumEt() const{
  if(!c_els_dr04HcalDepth1TowerSumEt_ && b_els_dr04HcalDepth1TowerSumEt_){
    b_els_dr04HcalDepth1TowerSumEt_->GetEntry(entry_);
    c_els_dr04HcalDepth1TowerSumEt_ = true;
  }
  return els_dr04HcalDepth1TowerSumEt_;
}

std::vector<float>* const & cfa_13::els_dr04HcalDepth2TowerSumEt() const{
  if(!c_els_dr04HcalDepth2TowerSumEt_ && b_els_dr04HcalDepth2TowerSumEt_){
    b_els_dr04HcalDepth2TowerSumEt_->GetEntry(entry_);
    c_els_dr04HcalDepth2TowerSumEt_ = true;
  }
  return els_dr04HcalDepth2TowerSumEt_;
}

std::vector<float>* const & cfa_13::els_dr04HcalTowerSumEt() const{
  if(!c_els_dr04HcalTowerSumEt_ && b_els_dr04HcalTowerSumEt_){
    b_els_dr04HcalTowerSumEt_->GetEntry(entry_);
    c_els_dr04HcalTowerSumEt_ = true;
  }
  return els_dr04HcalTowerSumEt_;
}

std::vector<float>* const & cfa_13::els_dr04TkSumPt() const{
  if(!c_els_dr04TkSumPt_ && b_els_dr04TkSumPt_){
    b_els_dr04TkSumPt_->GetEntry(entry_);
    c_els_dr04TkSumPt_ = true;
  }
  return els_dr04TkSumPt_;
}

std::vector<float>* const & cfa_13::els_dz() const{
  if(!c_els_dz_ && b_els_dz_){
    b_els_dz_->GetEntry(entry_);
    c_els_dz_ = true;
  }
  return els_dz_;
}

std::vector<float>* const & cfa_13::els_dzError() const{
  if(!c_els_dzError_ && b_els_dzError_){
    b_els_dzError_->GetEntry(entry_);
    c_els_dzError_ = true;
  }
  return els_dzError_;
}

std::vector<float>* const & cfa_13::els_eOverPIn() const{
  if(!c_els_eOverPIn_ && b_els_eOverPIn_){
    b_els_eOverPIn_->GetEntry(entry_);
    c_els_eOverPIn_ = true;
  }
  return els_eOverPIn_;
}

std::vector<float>* const & cfa_13::els_eSeedOverPOut() const{
  if(!c_els_eSeedOverPOut_ && b_els_eSeedOverPOut_){
    b_els_eSeedOverPOut_->GetEntry(entry_);
    c_els_eSeedOverPOut_ = true;
  }
  return els_eSeedOverPOut_;
}

std::vector<float>* const & cfa_13::els_ecalIso() const{
  if(!c_els_ecalIso_ && b_els_ecalIso_){
    b_els_ecalIso_->GetEntry(entry_);
    c_els_ecalIso_ = true;
  }
  return els_ecalIso_;
}

std::vector<float>* const & cfa_13::els_energy() const{
  if(!c_els_energy_ && b_els_energy_){
    b_els_energy_->GetEntry(entry_);
    c_els_energy_ = true;
  }
  return els_energy_;
}

std::vector<float>* const & cfa_13::els_et() const{
  if(!c_els_et_ && b_els_et_){
    b_els_et_->GetEntry(entry_);
    c_els_et_ = true;
  }
  return els_et_;
}

std::vector<float>* const & cfa_13::els_eta() const{
  if(!c_els_eta_ && b_els_eta_){
    b_els_eta_->GetEntry(entry_);
    c_els_eta_ = true;
  }
  return els_eta_;
}

std::vector<float>* const & cfa_13::els_etaError() const{
  if(!c_els_etaError_ && b_els_etaError_){
    b_els_etaError_->GetEntry(entry_);
    c_els_etaError_ = true;
  }
  return els_etaError_;
}

std::vector<float>* const & cfa_13::els_fbrem() const{
  if(!c_els_fbrem_ && b_els_fbrem_){
    b_els_fbrem_->GetEntry(entry_);
    c_els_fbrem_ = true;
  }
  return els_fbrem_;
}

std::vector<float>* const & cfa_13::els_full5x5_sigmaIetaIeta() const{
  if(!c_els_full5x5_sigmaIetaIeta_ && b_els_full5x5_sigmaIetaIeta_){
    b_els_full5x5_sigmaIetaIeta_->GetEntry(entry_);
    c_els_full5x5_sigmaIetaIeta_ = true;
  }
  return els_full5x5_sigmaIetaIeta_;
}

std::vector<float>* const & cfa_13::els_gen_et() const{
  if(!c_els_gen_et_ && b_els_gen_et_){
    b_els_gen_et_->GetEntry(entry_);
    c_els_gen_et_ = true;
  }
  return els_gen_et_;
}

std::vector<float>* const & cfa_13::els_gen_eta() const{
  if(!c_els_gen_eta_ && b_els_gen_eta_){
    b_els_gen_eta_->GetEntry(entry_);
    c_els_gen_eta_ = true;
  }
  return els_gen_eta_;
}

std::vector<float>* const & cfa_13::els_gen_id() const{
  if(!c_els_gen_id_ && b_els_gen_id_){
    b_els_gen_id_->GetEntry(entry_);
    c_els_gen_id_ = true;
  }
  return els_gen_id_;
}

std::vector<float>* const & cfa_13::els_gen_mother_et() const{
  if(!c_els_gen_mother_et_ && b_els_gen_mother_et_){
    b_els_gen_mother_et_->GetEntry(entry_);
    c_els_gen_mother_et_ = true;
  }
  return els_gen_mother_et_;
}

std::vector<float>* const & cfa_13::els_gen_mother_eta() const{
  if(!c_els_gen_mother_eta_ && b_els_gen_mother_eta_){
    b_els_gen_mother_eta_->GetEntry(entry_);
    c_els_gen_mother_eta_ = true;
  }
  return els_gen_mother_eta_;
}

std::vector<float>* const & cfa_13::els_gen_mother_id() const{
  if(!c_els_gen_mother_id_ && b_els_gen_mother_id_){
    b_els_gen_mother_id_->GetEntry(entry_);
    c_els_gen_mother_id_ = true;
  }
  return els_gen_mother_id_;
}

std::vector<float>* const & cfa_13::els_gen_mother_phi() const{
  if(!c_els_gen_mother_phi_ && b_els_gen_mother_phi_){
    b_els_gen_mother_phi_->GetEntry(entry_);
    c_els_gen_mother_phi_ = true;
  }
  return els_gen_mother_phi_;
}

std::vector<float>* const & cfa_13::els_gen_mother_pt() const{
  if(!c_els_gen_mother_pt_ && b_els_gen_mother_pt_){
    b_els_gen_mother_pt_->GetEntry(entry_);
    c_els_gen_mother_pt_ = true;
  }
  return els_gen_mother_pt_;
}

std::vector<float>* const & cfa_13::els_gen_mother_px() const{
  if(!c_els_gen_mother_px_ && b_els_gen_mother_px_){
    b_els_gen_mother_px_->GetEntry(entry_);
    c_els_gen_mother_px_ = true;
  }
  return els_gen_mother_px_;
}

std::vector<float>* const & cfa_13::els_gen_mother_py() const{
  if(!c_els_gen_mother_py_ && b_els_gen_mother_py_){
    b_els_gen_mother_py_->GetEntry(entry_);
    c_els_gen_mother_py_ = true;
  }
  return els_gen_mother_py_;
}

std::vector<float>* const & cfa_13::els_gen_mother_pz() const{
  if(!c_els_gen_mother_pz_ && b_els_gen_mother_pz_){
    b_els_gen_mother_pz_->GetEntry(entry_);
    c_els_gen_mother_pz_ = true;
  }
  return els_gen_mother_pz_;
}

std::vector<float>* const & cfa_13::els_gen_mother_theta() const{
  if(!c_els_gen_mother_theta_ && b_els_gen_mother_theta_){
    b_els_gen_mother_theta_->GetEntry(entry_);
    c_els_gen_mother_theta_ = true;
  }
  return els_gen_mother_theta_;
}

std::vector<float>* const & cfa_13::els_gen_phi() const{
  if(!c_els_gen_phi_ && b_els_gen_phi_){
    b_els_gen_phi_->GetEntry(entry_);
    c_els_gen_phi_ = true;
  }
  return els_gen_phi_;
}

std::vector<float>* const & cfa_13::els_gen_pt() const{
  if(!c_els_gen_pt_ && b_els_gen_pt_){
    b_els_gen_pt_->GetEntry(entry_);
    c_els_gen_pt_ = true;
  }
  return els_gen_pt_;
}

std::vector<float>* const & cfa_13::els_gen_px() const{
  if(!c_els_gen_px_ && b_els_gen_px_){
    b_els_gen_px_->GetEntry(entry_);
    c_els_gen_px_ = true;
  }
  return els_gen_px_;
}

std::vector<float>* const & cfa_13::els_gen_py() const{
  if(!c_els_gen_py_ && b_els_gen_py_){
    b_els_gen_py_->GetEntry(entry_);
    c_els_gen_py_ = true;
  }
  return els_gen_py_;
}

std::vector<float>* const & cfa_13::els_gen_pz() const{
  if(!c_els_gen_pz_ && b_els_gen_pz_){
    b_els_gen_pz_->GetEntry(entry_);
    c_els_gen_pz_ = true;
  }
  return els_gen_pz_;
}

std::vector<float>* const & cfa_13::els_gen_theta() const{
  if(!c_els_gen_theta_ && b_els_gen_theta_){
    b_els_gen_theta_->GetEntry(entry_);
    c_els_gen_theta_ = true;
  }
  return els_gen_theta_;
}

std::vector<float>* const & cfa_13::els_hadOverEm() const{
  if(!c_els_hadOverEm_ && b_els_hadOverEm_){
    b_els_hadOverEm_->GetEntry(entry_);
    c_els_hadOverEm_ = true;
  }
  return els_hadOverEm_;
}

std::vector<float>* const & cfa_13::els_hcalIso() const{
  if(!c_els_hcalIso_ && b_els_hcalIso_){
    b_els_hcalIso_->GetEntry(entry_);
    c_els_hcalIso_ = true;
  }
  return els_hcalIso_;
}

std::vector<float>* const & cfa_13::els_hcalOverEcalBc() const{
  if(!c_els_hcalOverEcalBc_ && b_els_hcalOverEcalBc_){
    b_els_hcalOverEcalBc_->GetEntry(entry_);
    c_els_hcalOverEcalBc_ = true;
  }
  return els_hcalOverEcalBc_;
}

std::vector<float>* const & cfa_13::els_isEB() const{
  if(!c_els_isEB_ && b_els_isEB_){
    b_els_isEB_->GetEntry(entry_);
    c_els_isEB_ = true;
  }
  return els_isEB_;
}

std::vector<float>* const & cfa_13::els_isEE() const{
  if(!c_els_isEE_ && b_els_isEE_){
    b_els_isEE_->GetEntry(entry_);
    c_els_isEE_ = true;
  }
  return els_isEE_;
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

std::vector<float>* const & cfa_13::els_looseId() const{
  if(!c_els_looseId_ && b_els_looseId_){
    b_els_looseId_->GetEntry(entry_);
    c_els_looseId_ = true;
  }
  return els_looseId_;
}

std::vector<float>* const & cfa_13::els_n_inner_layer() const{
  if(!c_els_n_inner_layer_ && b_els_n_inner_layer_){
    b_els_n_inner_layer_->GetEntry(entry_);
    c_els_n_inner_layer_ = true;
  }
  return els_n_inner_layer_;
}

std::vector<float>* const & cfa_13::els_n_outer_layer() const{
  if(!c_els_n_outer_layer_ && b_els_n_outer_layer_){
    b_els_n_outer_layer_->GetEntry(entry_);
    c_els_n_outer_layer_ = true;
  }
  return els_n_outer_layer_;
}

std::vector<float>* const & cfa_13::els_ndof() const{
  if(!c_els_ndof_ && b_els_ndof_){
    b_els_ndof_->GetEntry(entry_);
    c_els_ndof_ = true;
  }
  return els_ndof_;
}

std::vector<float>* const & cfa_13::els_numlosthits() const{
  if(!c_els_numlosthits_ && b_els_numlosthits_){
    b_els_numlosthits_->GetEntry(entry_);
    c_els_numlosthits_ = true;
  }
  return els_numlosthits_;
}

std::vector<float>* const & cfa_13::els_numvalhits() const{
  if(!c_els_numvalhits_ && b_els_numvalhits_){
    b_els_numvalhits_->GetEntry(entry_);
    c_els_numvalhits_ = true;
  }
  return els_numvalhits_;
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

std::vector<float>* const & cfa_13::els_phi() const{
  if(!c_els_phi_ && b_els_phi_){
    b_els_phi_->GetEntry(entry_);
    c_els_phi_ = true;
  }
  return els_phi_;
}

std::vector<float>* const & cfa_13::els_phiError() const{
  if(!c_els_phiError_ && b_els_phiError_){
    b_els_phiError_->GetEntry(entry_);
    c_els_phiError_ = true;
  }
  return els_phiError_;
}

std::vector<float>* const & cfa_13::els_pt() const{
  if(!c_els_pt_ && b_els_pt_){
    b_els_pt_->GetEntry(entry_);
    c_els_pt_ = true;
  }
  return els_pt_;
}

std::vector<float>* const & cfa_13::els_ptError() const{
  if(!c_els_ptError_ && b_els_ptError_){
    b_els_ptError_->GetEntry(entry_);
    c_els_ptError_ = true;
  }
  return els_ptError_;
}

std::vector<float>* const & cfa_13::els_px() const{
  if(!c_els_px_ && b_els_px_){
    b_els_px_->GetEntry(entry_);
    c_els_px_ = true;
  }
  return els_px_;
}

std::vector<float>* const & cfa_13::els_py() const{
  if(!c_els_py_ && b_els_py_){
    b_els_py_->GetEntry(entry_);
    c_els_py_ = true;
  }
  return els_py_;
}

std::vector<float>* const & cfa_13::els_pz() const{
  if(!c_els_pz_ && b_els_pz_){
    b_els_pz_->GetEntry(entry_);
    c_els_pz_ = true;
  }
  return els_pz_;
}

std::vector<float>* const & cfa_13::els_robustHighEnergyId() const{
  if(!c_els_robustHighEnergyId_ && b_els_robustHighEnergyId_){
    b_els_robustHighEnergyId_->GetEntry(entry_);
    c_els_robustHighEnergyId_ = true;
  }
  return els_robustHighEnergyId_;
}

std::vector<float>* const & cfa_13::els_robustLooseId() const{
  if(!c_els_robustLooseId_ && b_els_robustLooseId_){
    b_els_robustLooseId_->GetEntry(entry_);
    c_els_robustLooseId_ = true;
  }
  return els_robustLooseId_;
}

std::vector<float>* const & cfa_13::els_robustTightId() const{
  if(!c_els_robustTightId_ && b_els_robustTightId_){
    b_els_robustTightId_->GetEntry(entry_);
    c_els_robustTightId_ = true;
  }
  return els_robustTightId_;
}

std::vector<float>* const & cfa_13::els_scE1x5() const{
  if(!c_els_scE1x5_ && b_els_scE1x5_){
    b_els_scE1x5_->GetEntry(entry_);
    c_els_scE1x5_ = true;
  }
  return els_scE1x5_;
}

std::vector<float>* const & cfa_13::els_scE2x5Max() const{
  if(!c_els_scE2x5Max_ && b_els_scE2x5Max_){
    b_els_scE2x5Max_->GetEntry(entry_);
    c_els_scE2x5Max_ = true;
  }
  return els_scE2x5Max_;
}

std::vector<float>* const & cfa_13::els_scE5x5() const{
  if(!c_els_scE5x5_ && b_els_scE5x5_){
    b_els_scE5x5_->GetEntry(entry_);
    c_els_scE5x5_ = true;
  }
  return els_scE5x5_;
}

std::vector<float>* const & cfa_13::els_scEnergy() const{
  if(!c_els_scEnergy_ && b_els_scEnergy_){
    b_els_scEnergy_->GetEntry(entry_);
    c_els_scEnergy_ = true;
  }
  return els_scEnergy_;
}

std::vector<float>* const & cfa_13::els_scEta() const{
  if(!c_els_scEta_ && b_els_scEta_){
    b_els_scEta_->GetEntry(entry_);
    c_els_scEta_ = true;
  }
  return els_scEta_;
}

std::vector<float>* const & cfa_13::els_scEtaWidth() const{
  if(!c_els_scEtaWidth_ && b_els_scEtaWidth_){
    b_els_scEtaWidth_->GetEntry(entry_);
    c_els_scEtaWidth_ = true;
  }
  return els_scEtaWidth_;
}

std::vector<float>* const & cfa_13::els_scPhi() const{
  if(!c_els_scPhi_ && b_els_scPhi_){
    b_els_scPhi_->GetEntry(entry_);
    c_els_scPhi_ = true;
  }
  return els_scPhi_;
}

std::vector<float>* const & cfa_13::els_scPhiWidth() const{
  if(!c_els_scPhiWidth_ && b_els_scPhiWidth_){
    b_els_scPhiWidth_->GetEntry(entry_);
    c_els_scPhiWidth_ = true;
  }
  return els_scPhiWidth_;
}

std::vector<float>* const & cfa_13::els_scRawEnergy() const{
  if(!c_els_scRawEnergy_ && b_els_scRawEnergy_){
    b_els_scRawEnergy_->GetEntry(entry_);
    c_els_scRawEnergy_ = true;
  }
  return els_scRawEnergy_;
}

std::vector<float>* const & cfa_13::els_scSeedEnergy() const{
  if(!c_els_scSeedEnergy_ && b_els_scSeedEnergy_){
    b_els_scSeedEnergy_->GetEntry(entry_);
    c_els_scSeedEnergy_ = true;
  }
  return els_scSeedEnergy_;
}

std::vector<float>* const & cfa_13::els_shFracInnerHits() const{
  if(!c_els_shFracInnerHits_ && b_els_shFracInnerHits_){
    b_els_shFracInnerHits_->GetEntry(entry_);
    c_els_shFracInnerHits_ = true;
  }
  return els_shFracInnerHits_;
}

std::vector<float>* const & cfa_13::els_sigmaEtaEta() const{
  if(!c_els_sigmaEtaEta_ && b_els_sigmaEtaEta_){
    b_els_sigmaEtaEta_->GetEntry(entry_);
    c_els_sigmaEtaEta_ = true;
  }
  return els_sigmaEtaEta_;
}

std::vector<float>* const & cfa_13::els_sigmaIEtaIEta() const{
  if(!c_els_sigmaIEtaIEta_ && b_els_sigmaIEtaIEta_){
    b_els_sigmaIEtaIEta_->GetEntry(entry_);
    c_els_sigmaIEtaIEta_ = true;
  }
  return els_sigmaIEtaIEta_;
}

std::vector<float>* const & cfa_13::els_simpleEleId60cIso() const{
  if(!c_els_simpleEleId60cIso_ && b_els_simpleEleId60cIso_){
    b_els_simpleEleId60cIso_->GetEntry(entry_);
    c_els_simpleEleId60cIso_ = true;
  }
  return els_simpleEleId60cIso_;
}

std::vector<float>* const & cfa_13::els_simpleEleId60relIso() const{
  if(!c_els_simpleEleId60relIso_ && b_els_simpleEleId60relIso_){
    b_els_simpleEleId60relIso_->GetEntry(entry_);
    c_els_simpleEleId60relIso_ = true;
  }
  return els_simpleEleId60relIso_;
}

std::vector<float>* const & cfa_13::els_simpleEleId70cIso() const{
  if(!c_els_simpleEleId70cIso_ && b_els_simpleEleId70cIso_){
    b_els_simpleEleId70cIso_->GetEntry(entry_);
    c_els_simpleEleId70cIso_ = true;
  }
  return els_simpleEleId70cIso_;
}

std::vector<float>* const & cfa_13::els_simpleEleId70relIso() const{
  if(!c_els_simpleEleId70relIso_ && b_els_simpleEleId70relIso_){
    b_els_simpleEleId70relIso_->GetEntry(entry_);
    c_els_simpleEleId70relIso_ = true;
  }
  return els_simpleEleId70relIso_;
}

std::vector<float>* const & cfa_13::els_simpleEleId80cIso() const{
  if(!c_els_simpleEleId80cIso_ && b_els_simpleEleId80cIso_){
    b_els_simpleEleId80cIso_->GetEntry(entry_);
    c_els_simpleEleId80cIso_ = true;
  }
  return els_simpleEleId80cIso_;
}

std::vector<float>* const & cfa_13::els_simpleEleId80relIso() const{
  if(!c_els_simpleEleId80relIso_ && b_els_simpleEleId80relIso_){
    b_els_simpleEleId80relIso_->GetEntry(entry_);
    c_els_simpleEleId80relIso_ = true;
  }
  return els_simpleEleId80relIso_;
}

std::vector<float>* const & cfa_13::els_simpleEleId85cIso() const{
  if(!c_els_simpleEleId85cIso_ && b_els_simpleEleId85cIso_){
    b_els_simpleEleId85cIso_->GetEntry(entry_);
    c_els_simpleEleId85cIso_ = true;
  }
  return els_simpleEleId85cIso_;
}

std::vector<float>* const & cfa_13::els_simpleEleId85relIso() const{
  if(!c_els_simpleEleId85relIso_ && b_els_simpleEleId85relIso_){
    b_els_simpleEleId85relIso_->GetEntry(entry_);
    c_els_simpleEleId85relIso_ = true;
  }
  return els_simpleEleId85relIso_;
}

std::vector<float>* const & cfa_13::els_simpleEleId90cIso() const{
  if(!c_els_simpleEleId90cIso_ && b_els_simpleEleId90cIso_){
    b_els_simpleEleId90cIso_->GetEntry(entry_);
    c_els_simpleEleId90cIso_ = true;
  }
  return els_simpleEleId90cIso_;
}

std::vector<float>* const & cfa_13::els_simpleEleId90relIso() const{
  if(!c_els_simpleEleId90relIso_ && b_els_simpleEleId90relIso_){
    b_els_simpleEleId90relIso_->GetEntry(entry_);
    c_els_simpleEleId90relIso_ = true;
  }
  return els_simpleEleId90relIso_;
}

std::vector<float>* const & cfa_13::els_simpleEleId95cIso() const{
  if(!c_els_simpleEleId95cIso_ && b_els_simpleEleId95cIso_){
    b_els_simpleEleId95cIso_->GetEntry(entry_);
    c_els_simpleEleId95cIso_ = true;
  }
  return els_simpleEleId95cIso_;
}

std::vector<float>* const & cfa_13::els_simpleEleId95relIso() const{
  if(!c_els_simpleEleId95relIso_ && b_els_simpleEleId95relIso_){
    b_els_simpleEleId95relIso_->GetEntry(entry_);
    c_els_simpleEleId95relIso_ = true;
  }
  return els_simpleEleId95relIso_;
}

std::vector<float>* const & cfa_13::els_status() const{
  if(!c_els_status_ && b_els_status_){
    b_els_status_->GetEntry(entry_);
    c_els_status_ = true;
  }
  return els_status_;
}

std::vector<float>* const & cfa_13::els_tIso() const{
  if(!c_els_tIso_ && b_els_tIso_){
    b_els_tIso_->GetEntry(entry_);
    c_els_tIso_ = true;
  }
  return els_tIso_;
}

std::vector<float>* const & cfa_13::els_theta() const{
  if(!c_els_theta_ && b_els_theta_){
    b_els_theta_->GetEntry(entry_);
    c_els_theta_ = true;
  }
  return els_theta_;
}

std::vector<float>* const & cfa_13::els_tightId() const{
  if(!c_els_tightId_ && b_els_tightId_){
    b_els_tightId_->GetEntry(entry_);
    c_els_tightId_ = true;
  }
  return els_tightId_;
}

std::vector<float>* const & cfa_13::els_tk_charge() const{
  if(!c_els_tk_charge_ && b_els_tk_charge_){
    b_els_tk_charge_->GetEntry(entry_);
    c_els_tk_charge_ = true;
  }
  return els_tk_charge_;
}

std::vector<float>* const & cfa_13::els_tk_eta() const{
  if(!c_els_tk_eta_ && b_els_tk_eta_){
    b_els_tk_eta_->GetEntry(entry_);
    c_els_tk_eta_ = true;
  }
  return els_tk_eta_;
}

std::vector<float>* const & cfa_13::els_tk_phi() const{
  if(!c_els_tk_phi_ && b_els_tk_phi_){
    b_els_tk_phi_->GetEntry(entry_);
    c_els_tk_phi_ = true;
  }
  return els_tk_phi_;
}

std::vector<float>* const & cfa_13::els_tk_pt() const{
  if(!c_els_tk_pt_ && b_els_tk_pt_){
    b_els_tk_pt_->GetEntry(entry_);
    c_els_tk_pt_ = true;
  }
  return els_tk_pt_;
}

std::vector<float>* const & cfa_13::els_tk_pz() const{
  if(!c_els_tk_pz_ && b_els_tk_pz_){
    b_els_tk_pz_->GetEntry(entry_);
    c_els_tk_pz_ = true;
  }
  return els_tk_pz_;
}

std::vector<float>* const & cfa_13::els_vpx() const{
  if(!c_els_vpx_ && b_els_vpx_){
    b_els_vpx_->GetEntry(entry_);
    c_els_vpx_ = true;
  }
  return els_vpx_;
}

std::vector<float>* const & cfa_13::els_vpy() const{
  if(!c_els_vpy_ && b_els_vpy_){
    b_els_vpy_->GetEntry(entry_);
    c_els_vpy_ = true;
  }
  return els_vpy_;
}

std::vector<float>* const & cfa_13::els_vpz() const{
  if(!c_els_vpz_ && b_els_vpz_){
    b_els_vpz_->GetEntry(entry_);
    c_els_vpz_ = true;
  }
  return els_vpz_;
}

std::vector<float>* const & cfa_13::els_vx() const{
  if(!c_els_vx_ && b_els_vx_){
    b_els_vx_->GetEntry(entry_);
    c_els_vx_ = true;
  }
  return els_vx_;
}

std::vector<float>* const & cfa_13::els_vy() const{
  if(!c_els_vy_ && b_els_vy_){
    b_els_vy_->GetEntry(entry_);
    c_els_vy_ = true;
  }
  return els_vy_;
}

std::vector<float>* const & cfa_13::els_vz() const{
  if(!c_els_vz_ && b_els_vz_){
    b_els_vz_->GetEntry(entry_);
    c_els_vz_ = true;
  }
  return els_vz_;
}

UInt_t const & cfa_13::event() const{
  if(!c_event_ && b_event_){
    b_event_->GetEntry(entry_);
    c_event_ = true;
  }
  return event_;
}

UInt_t const & cfa_13::experimentType() const{
  if(!c_experimentType_ && b_experimentType_){
    b_experimentType_->GetEntry(entry_);
    c_experimentType_ = true;
  }
  return experimentType_;
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

Int_t const & cfa_13::hcallaserfilter_decision() const{
  if(!c_hcallaserfilter_decision_ && b_hcallaserfilter_decision_){
    b_hcallaserfilter_decision_->GetEntry(entry_);
    c_hcallaserfilter_decision_ = true;
  }
  return hcallaserfilter_decision_;
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

UInt_t const & cfa_13::lumiblock() const{
  if(!c_lumiblock_ && b_lumiblock_){
    b_lumiblock_->GetEntry(entry_);
    c_lumiblock_ = true;
  }
  return lumiblock_;
}

std::vector<float>* const & cfa_13::mc_doc_charge() const{
  if(!c_mc_doc_charge_ && b_mc_doc_charge_){
    b_mc_doc_charge_->GetEntry(entry_);
    c_mc_doc_charge_ = true;
  }
  return mc_doc_charge_;
}

std::vector<float>* const & cfa_13::mc_doc_energy() const{
  if(!c_mc_doc_energy_ && b_mc_doc_energy_){
    b_mc_doc_energy_->GetEntry(entry_);
    c_mc_doc_energy_ = true;
  }
  return mc_doc_energy_;
}

std::vector<float>* const & cfa_13::mc_doc_eta() const{
  if(!c_mc_doc_eta_ && b_mc_doc_eta_){
    b_mc_doc_eta_->GetEntry(entry_);
    c_mc_doc_eta_ = true;
  }
  return mc_doc_eta_;
}

std::vector<float>* const & cfa_13::mc_doc_ggrandmother_id() const{
  if(!c_mc_doc_ggrandmother_id_ && b_mc_doc_ggrandmother_id_){
    b_mc_doc_ggrandmother_id_->GetEntry(entry_);
    c_mc_doc_ggrandmother_id_ = true;
  }
  return mc_doc_ggrandmother_id_;
}

std::vector<float>* const & cfa_13::mc_doc_grandmother_id() const{
  if(!c_mc_doc_grandmother_id_ && b_mc_doc_grandmother_id_){
    b_mc_doc_grandmother_id_->GetEntry(entry_);
    c_mc_doc_grandmother_id_ = true;
  }
  return mc_doc_grandmother_id_;
}

std::vector<float>* const & cfa_13::mc_doc_id() const{
  if(!c_mc_doc_id_ && b_mc_doc_id_){
    b_mc_doc_id_->GetEntry(entry_);
    c_mc_doc_id_ = true;
  }
  return mc_doc_id_;
}

std::vector<float>* const & cfa_13::mc_doc_mass() const{
  if(!c_mc_doc_mass_ && b_mc_doc_mass_){
    b_mc_doc_mass_->GetEntry(entry_);
    c_mc_doc_mass_ = true;
  }
  return mc_doc_mass_;
}

std::vector<float>* const & cfa_13::mc_doc_mother_id() const{
  if(!c_mc_doc_mother_id_ && b_mc_doc_mother_id_){
    b_mc_doc_mother_id_->GetEntry(entry_);
    c_mc_doc_mother_id_ = true;
  }
  return mc_doc_mother_id_;
}

std::vector<float>* const & cfa_13::mc_doc_mother_pt() const{
  if(!c_mc_doc_mother_pt_ && b_mc_doc_mother_pt_){
    b_mc_doc_mother_pt_->GetEntry(entry_);
    c_mc_doc_mother_pt_ = true;
  }
  return mc_doc_mother_pt_;
}

std::vector<float>* const & cfa_13::mc_doc_numOfDaughters() const{
  if(!c_mc_doc_numOfDaughters_ && b_mc_doc_numOfDaughters_){
    b_mc_doc_numOfDaughters_->GetEntry(entry_);
    c_mc_doc_numOfDaughters_ = true;
  }
  return mc_doc_numOfDaughters_;
}

std::vector<float>* const & cfa_13::mc_doc_numOfMothers() const{
  if(!c_mc_doc_numOfMothers_ && b_mc_doc_numOfMothers_){
    b_mc_doc_numOfMothers_->GetEntry(entry_);
    c_mc_doc_numOfMothers_ = true;
  }
  return mc_doc_numOfMothers_;
}

std::vector<float>* const & cfa_13::mc_doc_phi() const{
  if(!c_mc_doc_phi_ && b_mc_doc_phi_){
    b_mc_doc_phi_->GetEntry(entry_);
    c_mc_doc_phi_ = true;
  }
  return mc_doc_phi_;
}

std::vector<float>* const & cfa_13::mc_doc_pt() const{
  if(!c_mc_doc_pt_ && b_mc_doc_pt_){
    b_mc_doc_pt_->GetEntry(entry_);
    c_mc_doc_pt_ = true;
  }
  return mc_doc_pt_;
}

std::vector<float>* const & cfa_13::mc_doc_px() const{
  if(!c_mc_doc_px_ && b_mc_doc_px_){
    b_mc_doc_px_->GetEntry(entry_);
    c_mc_doc_px_ = true;
  }
  return mc_doc_px_;
}

std::vector<float>* const & cfa_13::mc_doc_py() const{
  if(!c_mc_doc_py_ && b_mc_doc_py_){
    b_mc_doc_py_->GetEntry(entry_);
    c_mc_doc_py_ = true;
  }
  return mc_doc_py_;
}

std::vector<float>* const & cfa_13::mc_doc_pz() const{
  if(!c_mc_doc_pz_ && b_mc_doc_pz_){
    b_mc_doc_pz_->GetEntry(entry_);
    c_mc_doc_pz_ = true;
  }
  return mc_doc_pz_;
}

std::vector<float>* const & cfa_13::mc_doc_status() const{
  if(!c_mc_doc_status_ && b_mc_doc_status_){
    b_mc_doc_status_->GetEntry(entry_);
    c_mc_doc_status_ = true;
  }
  return mc_doc_status_;
}

std::vector<float>* const & cfa_13::mc_doc_theta() const{
  if(!c_mc_doc_theta_ && b_mc_doc_theta_){
    b_mc_doc_theta_->GetEntry(entry_);
    c_mc_doc_theta_ = true;
  }
  return mc_doc_theta_;
}

std::vector<float>* const & cfa_13::mc_doc_vertex_x() const{
  if(!c_mc_doc_vertex_x_ && b_mc_doc_vertex_x_){
    b_mc_doc_vertex_x_->GetEntry(entry_);
    c_mc_doc_vertex_x_ = true;
  }
  return mc_doc_vertex_x_;
}

std::vector<float>* const & cfa_13::mc_doc_vertex_y() const{
  if(!c_mc_doc_vertex_y_ && b_mc_doc_vertex_y_){
    b_mc_doc_vertex_y_->GetEntry(entry_);
    c_mc_doc_vertex_y_ = true;
  }
  return mc_doc_vertex_y_;
}

std::vector<float>* const & cfa_13::mc_doc_vertex_z() const{
  if(!c_mc_doc_vertex_z_ && b_mc_doc_vertex_z_){
    b_mc_doc_vertex_z_->GetEntry(entry_);
    c_mc_doc_vertex_z_ = true;
  }
  return mc_doc_vertex_z_;
}

std::vector<float>* const & cfa_13::mc_electrons_charge() const{
  if(!c_mc_electrons_charge_ && b_mc_electrons_charge_){
    b_mc_electrons_charge_->GetEntry(entry_);
    c_mc_electrons_charge_ = true;
  }
  return mc_electrons_charge_;
}

std::vector<float>* const & cfa_13::mc_electrons_energy() const{
  if(!c_mc_electrons_energy_ && b_mc_electrons_energy_){
    b_mc_electrons_energy_->GetEntry(entry_);
    c_mc_electrons_energy_ = true;
  }
  return mc_electrons_energy_;
}

std::vector<float>* const & cfa_13::mc_electrons_eta() const{
  if(!c_mc_electrons_eta_ && b_mc_electrons_eta_){
    b_mc_electrons_eta_->GetEntry(entry_);
    c_mc_electrons_eta_ = true;
  }
  return mc_electrons_eta_;
}

std::vector<float>* const & cfa_13::mc_electrons_ggrandmother_id() const{
  if(!c_mc_electrons_ggrandmother_id_ && b_mc_electrons_ggrandmother_id_){
    b_mc_electrons_ggrandmother_id_->GetEntry(entry_);
    c_mc_electrons_ggrandmother_id_ = true;
  }
  return mc_electrons_ggrandmother_id_;
}

std::vector<float>* const & cfa_13::mc_electrons_grandmother_id() const{
  if(!c_mc_electrons_grandmother_id_ && b_mc_electrons_grandmother_id_){
    b_mc_electrons_grandmother_id_->GetEntry(entry_);
    c_mc_electrons_grandmother_id_ = true;
  }
  return mc_electrons_grandmother_id_;
}

std::vector<float>* const & cfa_13::mc_electrons_id() const{
  if(!c_mc_electrons_id_ && b_mc_electrons_id_){
    b_mc_electrons_id_->GetEntry(entry_);
    c_mc_electrons_id_ = true;
  }
  return mc_electrons_id_;
}

std::vector<float>* const & cfa_13::mc_electrons_mass() const{
  if(!c_mc_electrons_mass_ && b_mc_electrons_mass_){
    b_mc_electrons_mass_->GetEntry(entry_);
    c_mc_electrons_mass_ = true;
  }
  return mc_electrons_mass_;
}

std::vector<float>* const & cfa_13::mc_electrons_mother_id() const{
  if(!c_mc_electrons_mother_id_ && b_mc_electrons_mother_id_){
    b_mc_electrons_mother_id_->GetEntry(entry_);
    c_mc_electrons_mother_id_ = true;
  }
  return mc_electrons_mother_id_;
}

std::vector<float>* const & cfa_13::mc_electrons_mother_pt() const{
  if(!c_mc_electrons_mother_pt_ && b_mc_electrons_mother_pt_){
    b_mc_electrons_mother_pt_->GetEntry(entry_);
    c_mc_electrons_mother_pt_ = true;
  }
  return mc_electrons_mother_pt_;
}

std::vector<float>* const & cfa_13::mc_electrons_numOfDaughters() const{
  if(!c_mc_electrons_numOfDaughters_ && b_mc_electrons_numOfDaughters_){
    b_mc_electrons_numOfDaughters_->GetEntry(entry_);
    c_mc_electrons_numOfDaughters_ = true;
  }
  return mc_electrons_numOfDaughters_;
}

std::vector<float>* const & cfa_13::mc_electrons_phi() const{
  if(!c_mc_electrons_phi_ && b_mc_electrons_phi_){
    b_mc_electrons_phi_->GetEntry(entry_);
    c_mc_electrons_phi_ = true;
  }
  return mc_electrons_phi_;
}

std::vector<float>* const & cfa_13::mc_electrons_pt() const{
  if(!c_mc_electrons_pt_ && b_mc_electrons_pt_){
    b_mc_electrons_pt_->GetEntry(entry_);
    c_mc_electrons_pt_ = true;
  }
  return mc_electrons_pt_;
}

std::vector<float>* const & cfa_13::mc_electrons_px() const{
  if(!c_mc_electrons_px_ && b_mc_electrons_px_){
    b_mc_electrons_px_->GetEntry(entry_);
    c_mc_electrons_px_ = true;
  }
  return mc_electrons_px_;
}

std::vector<float>* const & cfa_13::mc_electrons_py() const{
  if(!c_mc_electrons_py_ && b_mc_electrons_py_){
    b_mc_electrons_py_->GetEntry(entry_);
    c_mc_electrons_py_ = true;
  }
  return mc_electrons_py_;
}

std::vector<float>* const & cfa_13::mc_electrons_pz() const{
  if(!c_mc_electrons_pz_ && b_mc_electrons_pz_){
    b_mc_electrons_pz_->GetEntry(entry_);
    c_mc_electrons_pz_ = true;
  }
  return mc_electrons_pz_;
}

std::vector<float>* const & cfa_13::mc_electrons_status() const{
  if(!c_mc_electrons_status_ && b_mc_electrons_status_){
    b_mc_electrons_status_->GetEntry(entry_);
    c_mc_electrons_status_ = true;
  }
  return mc_electrons_status_;
}

std::vector<float>* const & cfa_13::mc_electrons_theta() const{
  if(!c_mc_electrons_theta_ && b_mc_electrons_theta_){
    b_mc_electrons_theta_->GetEntry(entry_);
    c_mc_electrons_theta_ = true;
  }
  return mc_electrons_theta_;
}

std::vector<float>* const & cfa_13::mc_electrons_vertex_x() const{
  if(!c_mc_electrons_vertex_x_ && b_mc_electrons_vertex_x_){
    b_mc_electrons_vertex_x_->GetEntry(entry_);
    c_mc_electrons_vertex_x_ = true;
  }
  return mc_electrons_vertex_x_;
}

std::vector<float>* const & cfa_13::mc_electrons_vertex_y() const{
  if(!c_mc_electrons_vertex_y_ && b_mc_electrons_vertex_y_){
    b_mc_electrons_vertex_y_->GetEntry(entry_);
    c_mc_electrons_vertex_y_ = true;
  }
  return mc_electrons_vertex_y_;
}

std::vector<float>* const & cfa_13::mc_electrons_vertex_z() const{
  if(!c_mc_electrons_vertex_z_ && b_mc_electrons_vertex_z_){
    b_mc_electrons_vertex_z_->GetEntry(entry_);
    c_mc_electrons_vertex_z_ = true;
  }
  return mc_electrons_vertex_z_;
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

std::vector<float>* const & cfa_13::mc_mus_charge() const{
  if(!c_mc_mus_charge_ && b_mc_mus_charge_){
    b_mc_mus_charge_->GetEntry(entry_);
    c_mc_mus_charge_ = true;
  }
  return mc_mus_charge_;
}

std::vector<float>* const & cfa_13::mc_mus_energy() const{
  if(!c_mc_mus_energy_ && b_mc_mus_energy_){
    b_mc_mus_energy_->GetEntry(entry_);
    c_mc_mus_energy_ = true;
  }
  return mc_mus_energy_;
}

std::vector<float>* const & cfa_13::mc_mus_eta() const{
  if(!c_mc_mus_eta_ && b_mc_mus_eta_){
    b_mc_mus_eta_->GetEntry(entry_);
    c_mc_mus_eta_ = true;
  }
  return mc_mus_eta_;
}

std::vector<float>* const & cfa_13::mc_mus_ggrandmother_id() const{
  if(!c_mc_mus_ggrandmother_id_ && b_mc_mus_ggrandmother_id_){
    b_mc_mus_ggrandmother_id_->GetEntry(entry_);
    c_mc_mus_ggrandmother_id_ = true;
  }
  return mc_mus_ggrandmother_id_;
}

std::vector<float>* const & cfa_13::mc_mus_grandmother_id() const{
  if(!c_mc_mus_grandmother_id_ && b_mc_mus_grandmother_id_){
    b_mc_mus_grandmother_id_->GetEntry(entry_);
    c_mc_mus_grandmother_id_ = true;
  }
  return mc_mus_grandmother_id_;
}

std::vector<float>* const & cfa_13::mc_mus_id() const{
  if(!c_mc_mus_id_ && b_mc_mus_id_){
    b_mc_mus_id_->GetEntry(entry_);
    c_mc_mus_id_ = true;
  }
  return mc_mus_id_;
}

std::vector<float>* const & cfa_13::mc_mus_mass() const{
  if(!c_mc_mus_mass_ && b_mc_mus_mass_){
    b_mc_mus_mass_->GetEntry(entry_);
    c_mc_mus_mass_ = true;
  }
  return mc_mus_mass_;
}

std::vector<float>* const & cfa_13::mc_mus_mother_id() const{
  if(!c_mc_mus_mother_id_ && b_mc_mus_mother_id_){
    b_mc_mus_mother_id_->GetEntry(entry_);
    c_mc_mus_mother_id_ = true;
  }
  return mc_mus_mother_id_;
}

std::vector<float>* const & cfa_13::mc_mus_mother_pt() const{
  if(!c_mc_mus_mother_pt_ && b_mc_mus_mother_pt_){
    b_mc_mus_mother_pt_->GetEntry(entry_);
    c_mc_mus_mother_pt_ = true;
  }
  return mc_mus_mother_pt_;
}

std::vector<float>* const & cfa_13::mc_mus_numOfDaughters() const{
  if(!c_mc_mus_numOfDaughters_ && b_mc_mus_numOfDaughters_){
    b_mc_mus_numOfDaughters_->GetEntry(entry_);
    c_mc_mus_numOfDaughters_ = true;
  }
  return mc_mus_numOfDaughters_;
}

std::vector<float>* const & cfa_13::mc_mus_phi() const{
  if(!c_mc_mus_phi_ && b_mc_mus_phi_){
    b_mc_mus_phi_->GetEntry(entry_);
    c_mc_mus_phi_ = true;
  }
  return mc_mus_phi_;
}

std::vector<float>* const & cfa_13::mc_mus_pt() const{
  if(!c_mc_mus_pt_ && b_mc_mus_pt_){
    b_mc_mus_pt_->GetEntry(entry_);
    c_mc_mus_pt_ = true;
  }
  return mc_mus_pt_;
}

std::vector<float>* const & cfa_13::mc_mus_px() const{
  if(!c_mc_mus_px_ && b_mc_mus_px_){
    b_mc_mus_px_->GetEntry(entry_);
    c_mc_mus_px_ = true;
  }
  return mc_mus_px_;
}

std::vector<float>* const & cfa_13::mc_mus_py() const{
  if(!c_mc_mus_py_ && b_mc_mus_py_){
    b_mc_mus_py_->GetEntry(entry_);
    c_mc_mus_py_ = true;
  }
  return mc_mus_py_;
}

std::vector<float>* const & cfa_13::mc_mus_pz() const{
  if(!c_mc_mus_pz_ && b_mc_mus_pz_){
    b_mc_mus_pz_->GetEntry(entry_);
    c_mc_mus_pz_ = true;
  }
  return mc_mus_pz_;
}

std::vector<float>* const & cfa_13::mc_mus_status() const{
  if(!c_mc_mus_status_ && b_mc_mus_status_){
    b_mc_mus_status_->GetEntry(entry_);
    c_mc_mus_status_ = true;
  }
  return mc_mus_status_;
}

std::vector<float>* const & cfa_13::mc_mus_theta() const{
  if(!c_mc_mus_theta_ && b_mc_mus_theta_){
    b_mc_mus_theta_->GetEntry(entry_);
    c_mc_mus_theta_ = true;
  }
  return mc_mus_theta_;
}

std::vector<float>* const & cfa_13::mc_mus_vertex_x() const{
  if(!c_mc_mus_vertex_x_ && b_mc_mus_vertex_x_){
    b_mc_mus_vertex_x_->GetEntry(entry_);
    c_mc_mus_vertex_x_ = true;
  }
  return mc_mus_vertex_x_;
}

std::vector<float>* const & cfa_13::mc_mus_vertex_y() const{
  if(!c_mc_mus_vertex_y_ && b_mc_mus_vertex_y_){
    b_mc_mus_vertex_y_->GetEntry(entry_);
    c_mc_mus_vertex_y_ = true;
  }
  return mc_mus_vertex_y_;
}

std::vector<float>* const & cfa_13::mc_mus_vertex_z() const{
  if(!c_mc_mus_vertex_z_ && b_mc_mus_vertex_z_){
    b_mc_mus_vertex_z_->GetEntry(entry_);
    c_mc_mus_vertex_z_ = true;
  }
  return mc_mus_vertex_z_;
}

std::vector<float>* const & cfa_13::mc_nues_charge() const{
  if(!c_mc_nues_charge_ && b_mc_nues_charge_){
    b_mc_nues_charge_->GetEntry(entry_);
    c_mc_nues_charge_ = true;
  }
  return mc_nues_charge_;
}

std::vector<float>* const & cfa_13::mc_nues_energy() const{
  if(!c_mc_nues_energy_ && b_mc_nues_energy_){
    b_mc_nues_energy_->GetEntry(entry_);
    c_mc_nues_energy_ = true;
  }
  return mc_nues_energy_;
}

std::vector<float>* const & cfa_13::mc_nues_eta() const{
  if(!c_mc_nues_eta_ && b_mc_nues_eta_){
    b_mc_nues_eta_->GetEntry(entry_);
    c_mc_nues_eta_ = true;
  }
  return mc_nues_eta_;
}

std::vector<float>* const & cfa_13::mc_nues_ggrandmother_id() const{
  if(!c_mc_nues_ggrandmother_id_ && b_mc_nues_ggrandmother_id_){
    b_mc_nues_ggrandmother_id_->GetEntry(entry_);
    c_mc_nues_ggrandmother_id_ = true;
  }
  return mc_nues_ggrandmother_id_;
}

std::vector<float>* const & cfa_13::mc_nues_grandmother_id() const{
  if(!c_mc_nues_grandmother_id_ && b_mc_nues_grandmother_id_){
    b_mc_nues_grandmother_id_->GetEntry(entry_);
    c_mc_nues_grandmother_id_ = true;
  }
  return mc_nues_grandmother_id_;
}

std::vector<float>* const & cfa_13::mc_nues_id() const{
  if(!c_mc_nues_id_ && b_mc_nues_id_){
    b_mc_nues_id_->GetEntry(entry_);
    c_mc_nues_id_ = true;
  }
  return mc_nues_id_;
}

std::vector<float>* const & cfa_13::mc_nues_mass() const{
  if(!c_mc_nues_mass_ && b_mc_nues_mass_){
    b_mc_nues_mass_->GetEntry(entry_);
    c_mc_nues_mass_ = true;
  }
  return mc_nues_mass_;
}

std::vector<float>* const & cfa_13::mc_nues_mother_id() const{
  if(!c_mc_nues_mother_id_ && b_mc_nues_mother_id_){
    b_mc_nues_mother_id_->GetEntry(entry_);
    c_mc_nues_mother_id_ = true;
  }
  return mc_nues_mother_id_;
}

std::vector<float>* const & cfa_13::mc_nues_mother_pt() const{
  if(!c_mc_nues_mother_pt_ && b_mc_nues_mother_pt_){
    b_mc_nues_mother_pt_->GetEntry(entry_);
    c_mc_nues_mother_pt_ = true;
  }
  return mc_nues_mother_pt_;
}

std::vector<float>* const & cfa_13::mc_nues_numOfDaughters() const{
  if(!c_mc_nues_numOfDaughters_ && b_mc_nues_numOfDaughters_){
    b_mc_nues_numOfDaughters_->GetEntry(entry_);
    c_mc_nues_numOfDaughters_ = true;
  }
  return mc_nues_numOfDaughters_;
}

std::vector<float>* const & cfa_13::mc_nues_phi() const{
  if(!c_mc_nues_phi_ && b_mc_nues_phi_){
    b_mc_nues_phi_->GetEntry(entry_);
    c_mc_nues_phi_ = true;
  }
  return mc_nues_phi_;
}

std::vector<float>* const & cfa_13::mc_nues_pt() const{
  if(!c_mc_nues_pt_ && b_mc_nues_pt_){
    b_mc_nues_pt_->GetEntry(entry_);
    c_mc_nues_pt_ = true;
  }
  return mc_nues_pt_;
}

std::vector<float>* const & cfa_13::mc_nues_px() const{
  if(!c_mc_nues_px_ && b_mc_nues_px_){
    b_mc_nues_px_->GetEntry(entry_);
    c_mc_nues_px_ = true;
  }
  return mc_nues_px_;
}

std::vector<float>* const & cfa_13::mc_nues_py() const{
  if(!c_mc_nues_py_ && b_mc_nues_py_){
    b_mc_nues_py_->GetEntry(entry_);
    c_mc_nues_py_ = true;
  }
  return mc_nues_py_;
}

std::vector<float>* const & cfa_13::mc_nues_pz() const{
  if(!c_mc_nues_pz_ && b_mc_nues_pz_){
    b_mc_nues_pz_->GetEntry(entry_);
    c_mc_nues_pz_ = true;
  }
  return mc_nues_pz_;
}

std::vector<float>* const & cfa_13::mc_nues_status() const{
  if(!c_mc_nues_status_ && b_mc_nues_status_){
    b_mc_nues_status_->GetEntry(entry_);
    c_mc_nues_status_ = true;
  }
  return mc_nues_status_;
}

std::vector<float>* const & cfa_13::mc_nues_theta() const{
  if(!c_mc_nues_theta_ && b_mc_nues_theta_){
    b_mc_nues_theta_->GetEntry(entry_);
    c_mc_nues_theta_ = true;
  }
  return mc_nues_theta_;
}

std::vector<float>* const & cfa_13::mc_nues_vertex_x() const{
  if(!c_mc_nues_vertex_x_ && b_mc_nues_vertex_x_){
    b_mc_nues_vertex_x_->GetEntry(entry_);
    c_mc_nues_vertex_x_ = true;
  }
  return mc_nues_vertex_x_;
}

std::vector<float>* const & cfa_13::mc_nues_vertex_y() const{
  if(!c_mc_nues_vertex_y_ && b_mc_nues_vertex_y_){
    b_mc_nues_vertex_y_->GetEntry(entry_);
    c_mc_nues_vertex_y_ = true;
  }
  return mc_nues_vertex_y_;
}

std::vector<float>* const & cfa_13::mc_nues_vertex_z() const{
  if(!c_mc_nues_vertex_z_ && b_mc_nues_vertex_z_){
    b_mc_nues_vertex_z_->GetEntry(entry_);
    c_mc_nues_vertex_z_ = true;
  }
  return mc_nues_vertex_z_;
}

std::vector<float>* const & cfa_13::mc_numus_charge() const{
  if(!c_mc_numus_charge_ && b_mc_numus_charge_){
    b_mc_numus_charge_->GetEntry(entry_);
    c_mc_numus_charge_ = true;
  }
  return mc_numus_charge_;
}

std::vector<float>* const & cfa_13::mc_numus_energy() const{
  if(!c_mc_numus_energy_ && b_mc_numus_energy_){
    b_mc_numus_energy_->GetEntry(entry_);
    c_mc_numus_energy_ = true;
  }
  return mc_numus_energy_;
}

std::vector<float>* const & cfa_13::mc_numus_eta() const{
  if(!c_mc_numus_eta_ && b_mc_numus_eta_){
    b_mc_numus_eta_->GetEntry(entry_);
    c_mc_numus_eta_ = true;
  }
  return mc_numus_eta_;
}

std::vector<float>* const & cfa_13::mc_numus_ggrandmother_id() const{
  if(!c_mc_numus_ggrandmother_id_ && b_mc_numus_ggrandmother_id_){
    b_mc_numus_ggrandmother_id_->GetEntry(entry_);
    c_mc_numus_ggrandmother_id_ = true;
  }
  return mc_numus_ggrandmother_id_;
}

std::vector<float>* const & cfa_13::mc_numus_grandmother_id() const{
  if(!c_mc_numus_grandmother_id_ && b_mc_numus_grandmother_id_){
    b_mc_numus_grandmother_id_->GetEntry(entry_);
    c_mc_numus_grandmother_id_ = true;
  }
  return mc_numus_grandmother_id_;
}

std::vector<float>* const & cfa_13::mc_numus_id() const{
  if(!c_mc_numus_id_ && b_mc_numus_id_){
    b_mc_numus_id_->GetEntry(entry_);
    c_mc_numus_id_ = true;
  }
  return mc_numus_id_;
}

std::vector<float>* const & cfa_13::mc_numus_mass() const{
  if(!c_mc_numus_mass_ && b_mc_numus_mass_){
    b_mc_numus_mass_->GetEntry(entry_);
    c_mc_numus_mass_ = true;
  }
  return mc_numus_mass_;
}

std::vector<float>* const & cfa_13::mc_numus_mother_id() const{
  if(!c_mc_numus_mother_id_ && b_mc_numus_mother_id_){
    b_mc_numus_mother_id_->GetEntry(entry_);
    c_mc_numus_mother_id_ = true;
  }
  return mc_numus_mother_id_;
}

std::vector<float>* const & cfa_13::mc_numus_mother_pt() const{
  if(!c_mc_numus_mother_pt_ && b_mc_numus_mother_pt_){
    b_mc_numus_mother_pt_->GetEntry(entry_);
    c_mc_numus_mother_pt_ = true;
  }
  return mc_numus_mother_pt_;
}

std::vector<float>* const & cfa_13::mc_numus_numOfDaughters() const{
  if(!c_mc_numus_numOfDaughters_ && b_mc_numus_numOfDaughters_){
    b_mc_numus_numOfDaughters_->GetEntry(entry_);
    c_mc_numus_numOfDaughters_ = true;
  }
  return mc_numus_numOfDaughters_;
}

std::vector<float>* const & cfa_13::mc_numus_phi() const{
  if(!c_mc_numus_phi_ && b_mc_numus_phi_){
    b_mc_numus_phi_->GetEntry(entry_);
    c_mc_numus_phi_ = true;
  }
  return mc_numus_phi_;
}

std::vector<float>* const & cfa_13::mc_numus_pt() const{
  if(!c_mc_numus_pt_ && b_mc_numus_pt_){
    b_mc_numus_pt_->GetEntry(entry_);
    c_mc_numus_pt_ = true;
  }
  return mc_numus_pt_;
}

std::vector<float>* const & cfa_13::mc_numus_px() const{
  if(!c_mc_numus_px_ && b_mc_numus_px_){
    b_mc_numus_px_->GetEntry(entry_);
    c_mc_numus_px_ = true;
  }
  return mc_numus_px_;
}

std::vector<float>* const & cfa_13::mc_numus_py() const{
  if(!c_mc_numus_py_ && b_mc_numus_py_){
    b_mc_numus_py_->GetEntry(entry_);
    c_mc_numus_py_ = true;
  }
  return mc_numus_py_;
}

std::vector<float>* const & cfa_13::mc_numus_pz() const{
  if(!c_mc_numus_pz_ && b_mc_numus_pz_){
    b_mc_numus_pz_->GetEntry(entry_);
    c_mc_numus_pz_ = true;
  }
  return mc_numus_pz_;
}

std::vector<float>* const & cfa_13::mc_numus_status() const{
  if(!c_mc_numus_status_ && b_mc_numus_status_){
    b_mc_numus_status_->GetEntry(entry_);
    c_mc_numus_status_ = true;
  }
  return mc_numus_status_;
}

std::vector<float>* const & cfa_13::mc_numus_theta() const{
  if(!c_mc_numus_theta_ && b_mc_numus_theta_){
    b_mc_numus_theta_->GetEntry(entry_);
    c_mc_numus_theta_ = true;
  }
  return mc_numus_theta_;
}

std::vector<float>* const & cfa_13::mc_numus_vertex_x() const{
  if(!c_mc_numus_vertex_x_ && b_mc_numus_vertex_x_){
    b_mc_numus_vertex_x_->GetEntry(entry_);
    c_mc_numus_vertex_x_ = true;
  }
  return mc_numus_vertex_x_;
}

std::vector<float>* const & cfa_13::mc_numus_vertex_y() const{
  if(!c_mc_numus_vertex_y_ && b_mc_numus_vertex_y_){
    b_mc_numus_vertex_y_->GetEntry(entry_);
    c_mc_numus_vertex_y_ = true;
  }
  return mc_numus_vertex_y_;
}

std::vector<float>* const & cfa_13::mc_numus_vertex_z() const{
  if(!c_mc_numus_vertex_z_ && b_mc_numus_vertex_z_){
    b_mc_numus_vertex_z_->GetEntry(entry_);
    c_mc_numus_vertex_z_ = true;
  }
  return mc_numus_vertex_z_;
}

std::vector<float>* const & cfa_13::mc_nutaus_charge() const{
  if(!c_mc_nutaus_charge_ && b_mc_nutaus_charge_){
    b_mc_nutaus_charge_->GetEntry(entry_);
    c_mc_nutaus_charge_ = true;
  }
  return mc_nutaus_charge_;
}

std::vector<float>* const & cfa_13::mc_nutaus_energy() const{
  if(!c_mc_nutaus_energy_ && b_mc_nutaus_energy_){
    b_mc_nutaus_energy_->GetEntry(entry_);
    c_mc_nutaus_energy_ = true;
  }
  return mc_nutaus_energy_;
}

std::vector<float>* const & cfa_13::mc_nutaus_eta() const{
  if(!c_mc_nutaus_eta_ && b_mc_nutaus_eta_){
    b_mc_nutaus_eta_->GetEntry(entry_);
    c_mc_nutaus_eta_ = true;
  }
  return mc_nutaus_eta_;
}

std::vector<float>* const & cfa_13::mc_nutaus_ggrandmother_id() const{
  if(!c_mc_nutaus_ggrandmother_id_ && b_mc_nutaus_ggrandmother_id_){
    b_mc_nutaus_ggrandmother_id_->GetEntry(entry_);
    c_mc_nutaus_ggrandmother_id_ = true;
  }
  return mc_nutaus_ggrandmother_id_;
}

std::vector<float>* const & cfa_13::mc_nutaus_grandmother_id() const{
  if(!c_mc_nutaus_grandmother_id_ && b_mc_nutaus_grandmother_id_){
    b_mc_nutaus_grandmother_id_->GetEntry(entry_);
    c_mc_nutaus_grandmother_id_ = true;
  }
  return mc_nutaus_grandmother_id_;
}

std::vector<float>* const & cfa_13::mc_nutaus_id() const{
  if(!c_mc_nutaus_id_ && b_mc_nutaus_id_){
    b_mc_nutaus_id_->GetEntry(entry_);
    c_mc_nutaus_id_ = true;
  }
  return mc_nutaus_id_;
}

std::vector<float>* const & cfa_13::mc_nutaus_mass() const{
  if(!c_mc_nutaus_mass_ && b_mc_nutaus_mass_){
    b_mc_nutaus_mass_->GetEntry(entry_);
    c_mc_nutaus_mass_ = true;
  }
  return mc_nutaus_mass_;
}

std::vector<float>* const & cfa_13::mc_nutaus_mother_id() const{
  if(!c_mc_nutaus_mother_id_ && b_mc_nutaus_mother_id_){
    b_mc_nutaus_mother_id_->GetEntry(entry_);
    c_mc_nutaus_mother_id_ = true;
  }
  return mc_nutaus_mother_id_;
}

std::vector<float>* const & cfa_13::mc_nutaus_mother_pt() const{
  if(!c_mc_nutaus_mother_pt_ && b_mc_nutaus_mother_pt_){
    b_mc_nutaus_mother_pt_->GetEntry(entry_);
    c_mc_nutaus_mother_pt_ = true;
  }
  return mc_nutaus_mother_pt_;
}

std::vector<float>* const & cfa_13::mc_nutaus_numOfDaughters() const{
  if(!c_mc_nutaus_numOfDaughters_ && b_mc_nutaus_numOfDaughters_){
    b_mc_nutaus_numOfDaughters_->GetEntry(entry_);
    c_mc_nutaus_numOfDaughters_ = true;
  }
  return mc_nutaus_numOfDaughters_;
}

std::vector<float>* const & cfa_13::mc_nutaus_phi() const{
  if(!c_mc_nutaus_phi_ && b_mc_nutaus_phi_){
    b_mc_nutaus_phi_->GetEntry(entry_);
    c_mc_nutaus_phi_ = true;
  }
  return mc_nutaus_phi_;
}

std::vector<float>* const & cfa_13::mc_nutaus_pt() const{
  if(!c_mc_nutaus_pt_ && b_mc_nutaus_pt_){
    b_mc_nutaus_pt_->GetEntry(entry_);
    c_mc_nutaus_pt_ = true;
  }
  return mc_nutaus_pt_;
}

std::vector<float>* const & cfa_13::mc_nutaus_px() const{
  if(!c_mc_nutaus_px_ && b_mc_nutaus_px_){
    b_mc_nutaus_px_->GetEntry(entry_);
    c_mc_nutaus_px_ = true;
  }
  return mc_nutaus_px_;
}

std::vector<float>* const & cfa_13::mc_nutaus_py() const{
  if(!c_mc_nutaus_py_ && b_mc_nutaus_py_){
    b_mc_nutaus_py_->GetEntry(entry_);
    c_mc_nutaus_py_ = true;
  }
  return mc_nutaus_py_;
}

std::vector<float>* const & cfa_13::mc_nutaus_pz() const{
  if(!c_mc_nutaus_pz_ && b_mc_nutaus_pz_){
    b_mc_nutaus_pz_->GetEntry(entry_);
    c_mc_nutaus_pz_ = true;
  }
  return mc_nutaus_pz_;
}

std::vector<float>* const & cfa_13::mc_nutaus_status() const{
  if(!c_mc_nutaus_status_ && b_mc_nutaus_status_){
    b_mc_nutaus_status_->GetEntry(entry_);
    c_mc_nutaus_status_ = true;
  }
  return mc_nutaus_status_;
}

std::vector<float>* const & cfa_13::mc_nutaus_theta() const{
  if(!c_mc_nutaus_theta_ && b_mc_nutaus_theta_){
    b_mc_nutaus_theta_->GetEntry(entry_);
    c_mc_nutaus_theta_ = true;
  }
  return mc_nutaus_theta_;
}

std::vector<float>* const & cfa_13::mc_nutaus_vertex_x() const{
  if(!c_mc_nutaus_vertex_x_ && b_mc_nutaus_vertex_x_){
    b_mc_nutaus_vertex_x_->GetEntry(entry_);
    c_mc_nutaus_vertex_x_ = true;
  }
  return mc_nutaus_vertex_x_;
}

std::vector<float>* const & cfa_13::mc_nutaus_vertex_y() const{
  if(!c_mc_nutaus_vertex_y_ && b_mc_nutaus_vertex_y_){
    b_mc_nutaus_vertex_y_->GetEntry(entry_);
    c_mc_nutaus_vertex_y_ = true;
  }
  return mc_nutaus_vertex_y_;
}

std::vector<float>* const & cfa_13::mc_nutaus_vertex_z() const{
  if(!c_mc_nutaus_vertex_z_ && b_mc_nutaus_vertex_z_){
    b_mc_nutaus_vertex_z_->GetEntry(entry_);
    c_mc_nutaus_vertex_z_ = true;
  }
  return mc_nutaus_vertex_z_;
}

std::vector<float>* const & cfa_13::mc_photons_charge() const{
  if(!c_mc_photons_charge_ && b_mc_photons_charge_){
    b_mc_photons_charge_->GetEntry(entry_);
    c_mc_photons_charge_ = true;
  }
  return mc_photons_charge_;
}

std::vector<float>* const & cfa_13::mc_photons_energy() const{
  if(!c_mc_photons_energy_ && b_mc_photons_energy_){
    b_mc_photons_energy_->GetEntry(entry_);
    c_mc_photons_energy_ = true;
  }
  return mc_photons_energy_;
}

std::vector<float>* const & cfa_13::mc_photons_eta() const{
  if(!c_mc_photons_eta_ && b_mc_photons_eta_){
    b_mc_photons_eta_->GetEntry(entry_);
    c_mc_photons_eta_ = true;
  }
  return mc_photons_eta_;
}

std::vector<float>* const & cfa_13::mc_photons_ggrandmother_id() const{
  if(!c_mc_photons_ggrandmother_id_ && b_mc_photons_ggrandmother_id_){
    b_mc_photons_ggrandmother_id_->GetEntry(entry_);
    c_mc_photons_ggrandmother_id_ = true;
  }
  return mc_photons_ggrandmother_id_;
}

std::vector<float>* const & cfa_13::mc_photons_grandmother_id() const{
  if(!c_mc_photons_grandmother_id_ && b_mc_photons_grandmother_id_){
    b_mc_photons_grandmother_id_->GetEntry(entry_);
    c_mc_photons_grandmother_id_ = true;
  }
  return mc_photons_grandmother_id_;
}

std::vector<float>* const & cfa_13::mc_photons_id() const{
  if(!c_mc_photons_id_ && b_mc_photons_id_){
    b_mc_photons_id_->GetEntry(entry_);
    c_mc_photons_id_ = true;
  }
  return mc_photons_id_;
}

std::vector<float>* const & cfa_13::mc_photons_mass() const{
  if(!c_mc_photons_mass_ && b_mc_photons_mass_){
    b_mc_photons_mass_->GetEntry(entry_);
    c_mc_photons_mass_ = true;
  }
  return mc_photons_mass_;
}

std::vector<float>* const & cfa_13::mc_photons_mother_id() const{
  if(!c_mc_photons_mother_id_ && b_mc_photons_mother_id_){
    b_mc_photons_mother_id_->GetEntry(entry_);
    c_mc_photons_mother_id_ = true;
  }
  return mc_photons_mother_id_;
}

std::vector<float>* const & cfa_13::mc_photons_mother_pt() const{
  if(!c_mc_photons_mother_pt_ && b_mc_photons_mother_pt_){
    b_mc_photons_mother_pt_->GetEntry(entry_);
    c_mc_photons_mother_pt_ = true;
  }
  return mc_photons_mother_pt_;
}

std::vector<float>* const & cfa_13::mc_photons_numOfDaughters() const{
  if(!c_mc_photons_numOfDaughters_ && b_mc_photons_numOfDaughters_){
    b_mc_photons_numOfDaughters_->GetEntry(entry_);
    c_mc_photons_numOfDaughters_ = true;
  }
  return mc_photons_numOfDaughters_;
}

std::vector<float>* const & cfa_13::mc_photons_phi() const{
  if(!c_mc_photons_phi_ && b_mc_photons_phi_){
    b_mc_photons_phi_->GetEntry(entry_);
    c_mc_photons_phi_ = true;
  }
  return mc_photons_phi_;
}

std::vector<float>* const & cfa_13::mc_photons_pt() const{
  if(!c_mc_photons_pt_ && b_mc_photons_pt_){
    b_mc_photons_pt_->GetEntry(entry_);
    c_mc_photons_pt_ = true;
  }
  return mc_photons_pt_;
}

std::vector<float>* const & cfa_13::mc_photons_px() const{
  if(!c_mc_photons_px_ && b_mc_photons_px_){
    b_mc_photons_px_->GetEntry(entry_);
    c_mc_photons_px_ = true;
  }
  return mc_photons_px_;
}

std::vector<float>* const & cfa_13::mc_photons_py() const{
  if(!c_mc_photons_py_ && b_mc_photons_py_){
    b_mc_photons_py_->GetEntry(entry_);
    c_mc_photons_py_ = true;
  }
  return mc_photons_py_;
}

std::vector<float>* const & cfa_13::mc_photons_pz() const{
  if(!c_mc_photons_pz_ && b_mc_photons_pz_){
    b_mc_photons_pz_->GetEntry(entry_);
    c_mc_photons_pz_ = true;
  }
  return mc_photons_pz_;
}

std::vector<float>* const & cfa_13::mc_photons_status() const{
  if(!c_mc_photons_status_ && b_mc_photons_status_){
    b_mc_photons_status_->GetEntry(entry_);
    c_mc_photons_status_ = true;
  }
  return mc_photons_status_;
}

std::vector<float>* const & cfa_13::mc_photons_theta() const{
  if(!c_mc_photons_theta_ && b_mc_photons_theta_){
    b_mc_photons_theta_->GetEntry(entry_);
    c_mc_photons_theta_ = true;
  }
  return mc_photons_theta_;
}

std::vector<float>* const & cfa_13::mc_photons_vertex_x() const{
  if(!c_mc_photons_vertex_x_ && b_mc_photons_vertex_x_){
    b_mc_photons_vertex_x_->GetEntry(entry_);
    c_mc_photons_vertex_x_ = true;
  }
  return mc_photons_vertex_x_;
}

std::vector<float>* const & cfa_13::mc_photons_vertex_y() const{
  if(!c_mc_photons_vertex_y_ && b_mc_photons_vertex_y_){
    b_mc_photons_vertex_y_->GetEntry(entry_);
    c_mc_photons_vertex_y_ = true;
  }
  return mc_photons_vertex_y_;
}

std::vector<float>* const & cfa_13::mc_photons_vertex_z() const{
  if(!c_mc_photons_vertex_z_ && b_mc_photons_vertex_z_){
    b_mc_photons_vertex_z_->GetEntry(entry_);
    c_mc_photons_vertex_z_ = true;
  }
  return mc_photons_vertex_z_;
}

std::vector<float>* const & cfa_13::mc_taus_charge() const{
  if(!c_mc_taus_charge_ && b_mc_taus_charge_){
    b_mc_taus_charge_->GetEntry(entry_);
    c_mc_taus_charge_ = true;
  }
  return mc_taus_charge_;
}

std::vector<float>* const & cfa_13::mc_taus_energy() const{
  if(!c_mc_taus_energy_ && b_mc_taus_energy_){
    b_mc_taus_energy_->GetEntry(entry_);
    c_mc_taus_energy_ = true;
  }
  return mc_taus_energy_;
}

std::vector<float>* const & cfa_13::mc_taus_eta() const{
  if(!c_mc_taus_eta_ && b_mc_taus_eta_){
    b_mc_taus_eta_->GetEntry(entry_);
    c_mc_taus_eta_ = true;
  }
  return mc_taus_eta_;
}

std::vector<float>* const & cfa_13::mc_taus_ggrandmother_id() const{
  if(!c_mc_taus_ggrandmother_id_ && b_mc_taus_ggrandmother_id_){
    b_mc_taus_ggrandmother_id_->GetEntry(entry_);
    c_mc_taus_ggrandmother_id_ = true;
  }
  return mc_taus_ggrandmother_id_;
}

std::vector<float>* const & cfa_13::mc_taus_grandmother_id() const{
  if(!c_mc_taus_grandmother_id_ && b_mc_taus_grandmother_id_){
    b_mc_taus_grandmother_id_->GetEntry(entry_);
    c_mc_taus_grandmother_id_ = true;
  }
  return mc_taus_grandmother_id_;
}

std::vector<float>* const & cfa_13::mc_taus_id() const{
  if(!c_mc_taus_id_ && b_mc_taus_id_){
    b_mc_taus_id_->GetEntry(entry_);
    c_mc_taus_id_ = true;
  }
  return mc_taus_id_;
}

std::vector<float>* const & cfa_13::mc_taus_mass() const{
  if(!c_mc_taus_mass_ && b_mc_taus_mass_){
    b_mc_taus_mass_->GetEntry(entry_);
    c_mc_taus_mass_ = true;
  }
  return mc_taus_mass_;
}

std::vector<float>* const & cfa_13::mc_taus_mother_id() const{
  if(!c_mc_taus_mother_id_ && b_mc_taus_mother_id_){
    b_mc_taus_mother_id_->GetEntry(entry_);
    c_mc_taus_mother_id_ = true;
  }
  return mc_taus_mother_id_;
}

std::vector<float>* const & cfa_13::mc_taus_mother_pt() const{
  if(!c_mc_taus_mother_pt_ && b_mc_taus_mother_pt_){
    b_mc_taus_mother_pt_->GetEntry(entry_);
    c_mc_taus_mother_pt_ = true;
  }
  return mc_taus_mother_pt_;
}

std::vector<float>* const & cfa_13::mc_taus_numOfDaughters() const{
  if(!c_mc_taus_numOfDaughters_ && b_mc_taus_numOfDaughters_){
    b_mc_taus_numOfDaughters_->GetEntry(entry_);
    c_mc_taus_numOfDaughters_ = true;
  }
  return mc_taus_numOfDaughters_;
}

std::vector<float>* const & cfa_13::mc_taus_phi() const{
  if(!c_mc_taus_phi_ && b_mc_taus_phi_){
    b_mc_taus_phi_->GetEntry(entry_);
    c_mc_taus_phi_ = true;
  }
  return mc_taus_phi_;
}

std::vector<float>* const & cfa_13::mc_taus_pt() const{
  if(!c_mc_taus_pt_ && b_mc_taus_pt_){
    b_mc_taus_pt_->GetEntry(entry_);
    c_mc_taus_pt_ = true;
  }
  return mc_taus_pt_;
}

std::vector<float>* const & cfa_13::mc_taus_px() const{
  if(!c_mc_taus_px_ && b_mc_taus_px_){
    b_mc_taus_px_->GetEntry(entry_);
    c_mc_taus_px_ = true;
  }
  return mc_taus_px_;
}

std::vector<float>* const & cfa_13::mc_taus_py() const{
  if(!c_mc_taus_py_ && b_mc_taus_py_){
    b_mc_taus_py_->GetEntry(entry_);
    c_mc_taus_py_ = true;
  }
  return mc_taus_py_;
}

std::vector<float>* const & cfa_13::mc_taus_pz() const{
  if(!c_mc_taus_pz_ && b_mc_taus_pz_){
    b_mc_taus_pz_->GetEntry(entry_);
    c_mc_taus_pz_ = true;
  }
  return mc_taus_pz_;
}

std::vector<float>* const & cfa_13::mc_taus_status() const{
  if(!c_mc_taus_status_ && b_mc_taus_status_){
    b_mc_taus_status_->GetEntry(entry_);
    c_mc_taus_status_ = true;
  }
  return mc_taus_status_;
}

std::vector<float>* const & cfa_13::mc_taus_theta() const{
  if(!c_mc_taus_theta_ && b_mc_taus_theta_){
    b_mc_taus_theta_->GetEntry(entry_);
    c_mc_taus_theta_ = true;
  }
  return mc_taus_theta_;
}

std::vector<float>* const & cfa_13::mc_taus_vertex_x() const{
  if(!c_mc_taus_vertex_x_ && b_mc_taus_vertex_x_){
    b_mc_taus_vertex_x_->GetEntry(entry_);
    c_mc_taus_vertex_x_ = true;
  }
  return mc_taus_vertex_x_;
}

std::vector<float>* const & cfa_13::mc_taus_vertex_y() const{
  if(!c_mc_taus_vertex_y_ && b_mc_taus_vertex_y_){
    b_mc_taus_vertex_y_->GetEntry(entry_);
    c_mc_taus_vertex_y_ = true;
  }
  return mc_taus_vertex_y_;
}

std::vector<float>* const & cfa_13::mc_taus_vertex_z() const{
  if(!c_mc_taus_vertex_z_ && b_mc_taus_vertex_z_){
    b_mc_taus_vertex_z_->GetEntry(entry_);
    c_mc_taus_vertex_z_ = true;
  }
  return mc_taus_vertex_z_;
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

std::string* const & cfa_13::model_params() const{
  if(!c_model_params_ && b_model_params_){
    b_model_params_->GetEntry(entry_);
    c_model_params_ = true;
  }
  return model_params_;
}

std::vector<float>* const & cfa_13::mus_cIso() const{
  if(!c_mus_cIso_ && b_mus_cIso_){
    b_mus_cIso_->GetEntry(entry_);
    c_mus_cIso_ = true;
  }
  return mus_cIso_;
}

std::vector<float>* const & cfa_13::mus_calEnergyEm() const{
  if(!c_mus_calEnergyEm_ && b_mus_calEnergyEm_){
    b_mus_calEnergyEm_->GetEntry(entry_);
    c_mus_calEnergyEm_ = true;
  }
  return mus_calEnergyEm_;
}

std::vector<float>* const & cfa_13::mus_calEnergyEmS9() const{
  if(!c_mus_calEnergyEmS9_ && b_mus_calEnergyEmS9_){
    b_mus_calEnergyEmS9_->GetEntry(entry_);
    c_mus_calEnergyEmS9_ = true;
  }
  return mus_calEnergyEmS9_;
}

std::vector<float>* const & cfa_13::mus_calEnergyHad() const{
  if(!c_mus_calEnergyHad_ && b_mus_calEnergyHad_){
    b_mus_calEnergyHad_->GetEntry(entry_);
    c_mus_calEnergyHad_ = true;
  }
  return mus_calEnergyHad_;
}

std::vector<float>* const & cfa_13::mus_calEnergyHadS9() const{
  if(!c_mus_calEnergyHadS9_ && b_mus_calEnergyHadS9_){
    b_mus_calEnergyHadS9_->GetEntry(entry_);
    c_mus_calEnergyHadS9_ = true;
  }
  return mus_calEnergyHadS9_;
}

std::vector<float>* const & cfa_13::mus_calEnergyHo() const{
  if(!c_mus_calEnergyHo_ && b_mus_calEnergyHo_){
    b_mus_calEnergyHo_->GetEntry(entry_);
    c_mus_calEnergyHo_ = true;
  }
  return mus_calEnergyHo_;
}

std::vector<float>* const & cfa_13::mus_calEnergyHoS9() const{
  if(!c_mus_calEnergyHoS9_ && b_mus_calEnergyHoS9_){
    b_mus_calEnergyHoS9_->GetEntry(entry_);
    c_mus_calEnergyHoS9_ = true;
  }
  return mus_calEnergyHoS9_;
}

std::vector<float>* const & cfa_13::mus_charge() const{
  if(!c_mus_charge_ && b_mus_charge_){
    b_mus_charge_->GetEntry(entry_);
    c_mus_charge_ = true;
  }
  return mus_charge_;
}

std::vector<float>* const & cfa_13::mus_cm_ExpectedHitsInner() const{
  if(!c_mus_cm_ExpectedHitsInner_ && b_mus_cm_ExpectedHitsInner_){
    b_mus_cm_ExpectedHitsInner_->GetEntry(entry_);
    c_mus_cm_ExpectedHitsInner_ = true;
  }
  return mus_cm_ExpectedHitsInner_;
}

std::vector<float>* const & cfa_13::mus_cm_ExpectedHitsOuter() const{
  if(!c_mus_cm_ExpectedHitsOuter_ && b_mus_cm_ExpectedHitsOuter_){
    b_mus_cm_ExpectedHitsOuter_->GetEntry(entry_);
    c_mus_cm_ExpectedHitsOuter_ = true;
  }
  return mus_cm_ExpectedHitsOuter_;
}

std::vector<float>* const & cfa_13::mus_cm_LayersWithMeasurement() const{
  if(!c_mus_cm_LayersWithMeasurement_ && b_mus_cm_LayersWithMeasurement_){
    b_mus_cm_LayersWithMeasurement_->GetEntry(entry_);
    c_mus_cm_LayersWithMeasurement_ = true;
  }
  return mus_cm_LayersWithMeasurement_;
}

std::vector<float>* const & cfa_13::mus_cm_LayersWithoutMeasurement() const{
  if(!c_mus_cm_LayersWithoutMeasurement_ && b_mus_cm_LayersWithoutMeasurement_){
    b_mus_cm_LayersWithoutMeasurement_->GetEntry(entry_);
    c_mus_cm_LayersWithoutMeasurement_ = true;
  }
  return mus_cm_LayersWithoutMeasurement_;
}

std::vector<float>* const & cfa_13::mus_cm_PixelLayersWithMeasurement() const{
  if(!c_mus_cm_PixelLayersWithMeasurement_ && b_mus_cm_PixelLayersWithMeasurement_){
    b_mus_cm_PixelLayersWithMeasurement_->GetEntry(entry_);
    c_mus_cm_PixelLayersWithMeasurement_ = true;
  }
  return mus_cm_PixelLayersWithMeasurement_;
}

std::vector<float>* const & cfa_13::mus_cm_ValidStripLayersWithMonoAndStereoHit() const{
  if(!c_mus_cm_ValidStripLayersWithMonoAndStereoHit_ && b_mus_cm_ValidStripLayersWithMonoAndStereoHit_){
    b_mus_cm_ValidStripLayersWithMonoAndStereoHit_->GetEntry(entry_);
    c_mus_cm_ValidStripLayersWithMonoAndStereoHit_ = true;
  }
  return mus_cm_ValidStripLayersWithMonoAndStereoHit_;
}

std::vector<float>* const & cfa_13::mus_cm_chg() const{
  if(!c_mus_cm_chg_ && b_mus_cm_chg_){
    b_mus_cm_chg_->GetEntry(entry_);
    c_mus_cm_chg_ = true;
  }
  return mus_cm_chg_;
}

std::vector<float>* const & cfa_13::mus_cm_chi2() const{
  if(!c_mus_cm_chi2_ && b_mus_cm_chi2_){
    b_mus_cm_chi2_->GetEntry(entry_);
    c_mus_cm_chi2_ = true;
  }
  return mus_cm_chi2_;
}

std::vector<float>* const & cfa_13::mus_cm_d0dum() const{
  if(!c_mus_cm_d0dum_ && b_mus_cm_d0dum_){
    b_mus_cm_d0dum_->GetEntry(entry_);
    c_mus_cm_d0dum_ = true;
  }
  return mus_cm_d0dum_;
}

std::vector<float>* const & cfa_13::mus_cm_d0dumErr() const{
  if(!c_mus_cm_d0dumErr_ && b_mus_cm_d0dumErr_){
    b_mus_cm_d0dumErr_->GetEntry(entry_);
    c_mus_cm_d0dumErr_ = true;
  }
  return mus_cm_d0dumErr_;
}

std::vector<float>* const & cfa_13::mus_cm_dz() const{
  if(!c_mus_cm_dz_ && b_mus_cm_dz_){
    b_mus_cm_dz_->GetEntry(entry_);
    c_mus_cm_dz_ = true;
  }
  return mus_cm_dz_;
}

std::vector<float>* const & cfa_13::mus_cm_dzErr() const{
  if(!c_mus_cm_dzErr_ && b_mus_cm_dzErr_){
    b_mus_cm_dzErr_->GetEntry(entry_);
    c_mus_cm_dzErr_ = true;
  }
  return mus_cm_dzErr_;
}

std::vector<float>* const & cfa_13::mus_cm_eta() const{
  if(!c_mus_cm_eta_ && b_mus_cm_eta_){
    b_mus_cm_eta_->GetEntry(entry_);
    c_mus_cm_eta_ = true;
  }
  return mus_cm_eta_;
}

std::vector<float>* const & cfa_13::mus_cm_etaErr() const{
  if(!c_mus_cm_etaErr_ && b_mus_cm_etaErr_){
    b_mus_cm_etaErr_->GetEntry(entry_);
    c_mus_cm_etaErr_ = true;
  }
  return mus_cm_etaErr_;
}

std::vector<float>* const & cfa_13::mus_cm_ndof() const{
  if(!c_mus_cm_ndof_ && b_mus_cm_ndof_){
    b_mus_cm_ndof_->GetEntry(entry_);
    c_mus_cm_ndof_ = true;
  }
  return mus_cm_ndof_;
}

std::vector<float>* const & cfa_13::mus_cm_numlosthits() const{
  if(!c_mus_cm_numlosthits_ && b_mus_cm_numlosthits_){
    b_mus_cm_numlosthits_->GetEntry(entry_);
    c_mus_cm_numlosthits_ = true;
  }
  return mus_cm_numlosthits_;
}

std::vector<float>* const & cfa_13::mus_cm_numvalMuonhits() const{
  if(!c_mus_cm_numvalMuonhits_ && b_mus_cm_numvalMuonhits_){
    b_mus_cm_numvalMuonhits_->GetEntry(entry_);
    c_mus_cm_numvalMuonhits_ = true;
  }
  return mus_cm_numvalMuonhits_;
}

std::vector<float>* const & cfa_13::mus_cm_numvalhits() const{
  if(!c_mus_cm_numvalhits_ && b_mus_cm_numvalhits_){
    b_mus_cm_numvalhits_->GetEntry(entry_);
    c_mus_cm_numvalhits_ = true;
  }
  return mus_cm_numvalhits_;
}

std::vector<float>* const & cfa_13::mus_cm_phi() const{
  if(!c_mus_cm_phi_ && b_mus_cm_phi_){
    b_mus_cm_phi_->GetEntry(entry_);
    c_mus_cm_phi_ = true;
  }
  return mus_cm_phi_;
}

std::vector<float>* const & cfa_13::mus_cm_phiErr() const{
  if(!c_mus_cm_phiErr_ && b_mus_cm_phiErr_){
    b_mus_cm_phiErr_->GetEntry(entry_);
    c_mus_cm_phiErr_ = true;
  }
  return mus_cm_phiErr_;
}

std::vector<float>* const & cfa_13::mus_cm_pt() const{
  if(!c_mus_cm_pt_ && b_mus_cm_pt_){
    b_mus_cm_pt_->GetEntry(entry_);
    c_mus_cm_pt_ = true;
  }
  return mus_cm_pt_;
}

std::vector<float>* const & cfa_13::mus_cm_ptErr() const{
  if(!c_mus_cm_ptErr_ && b_mus_cm_ptErr_){
    b_mus_cm_ptErr_->GetEntry(entry_);
    c_mus_cm_ptErr_ = true;
  }
  return mus_cm_ptErr_;
}

std::vector<float>* const & cfa_13::mus_cm_px() const{
  if(!c_mus_cm_px_ && b_mus_cm_px_){
    b_mus_cm_px_->GetEntry(entry_);
    c_mus_cm_px_ = true;
  }
  return mus_cm_px_;
}

std::vector<float>* const & cfa_13::mus_cm_py() const{
  if(!c_mus_cm_py_ && b_mus_cm_py_){
    b_mus_cm_py_->GetEntry(entry_);
    c_mus_cm_py_ = true;
  }
  return mus_cm_py_;
}

std::vector<float>* const & cfa_13::mus_cm_pz() const{
  if(!c_mus_cm_pz_ && b_mus_cm_pz_){
    b_mus_cm_pz_->GetEntry(entry_);
    c_mus_cm_pz_ = true;
  }
  return mus_cm_pz_;
}

std::vector<float>* const & cfa_13::mus_cm_theta() const{
  if(!c_mus_cm_theta_ && b_mus_cm_theta_){
    b_mus_cm_theta_->GetEntry(entry_);
    c_mus_cm_theta_ = true;
  }
  return mus_cm_theta_;
}

std::vector<float>* const & cfa_13::mus_cm_vx() const{
  if(!c_mus_cm_vx_ && b_mus_cm_vx_){
    b_mus_cm_vx_->GetEntry(entry_);
    c_mus_cm_vx_ = true;
  }
  return mus_cm_vx_;
}

std::vector<float>* const & cfa_13::mus_cm_vy() const{
  if(!c_mus_cm_vy_ && b_mus_cm_vy_){
    b_mus_cm_vy_->GetEntry(entry_);
    c_mus_cm_vy_ = true;
  }
  return mus_cm_vy_;
}

std::vector<float>* const & cfa_13::mus_cm_vz() const{
  if(!c_mus_cm_vz_ && b_mus_cm_vz_){
    b_mus_cm_vz_->GetEntry(entry_);
    c_mus_cm_vz_ = true;
  }
  return mus_cm_vz_;
}

std::vector<float>* const & cfa_13::mus_dB() const{
  if(!c_mus_dB_ && b_mus_dB_){
    b_mus_dB_->GetEntry(entry_);
    c_mus_dB_ = true;
  }
  return mus_dB_;
}

std::vector<float>* const & cfa_13::mus_ecalIso() const{
  if(!c_mus_ecalIso_ && b_mus_ecalIso_){
    b_mus_ecalIso_->GetEntry(entry_);
    c_mus_ecalIso_ = true;
  }
  return mus_ecalIso_;
}

std::vector<float>* const & cfa_13::mus_ecalvetoDep() const{
  if(!c_mus_ecalvetoDep_ && b_mus_ecalvetoDep_){
    b_mus_ecalvetoDep_->GetEntry(entry_);
    c_mus_ecalvetoDep_ = true;
  }
  return mus_ecalvetoDep_;
}

std::vector<float>* const & cfa_13::mus_energy() const{
  if(!c_mus_energy_ && b_mus_energy_){
    b_mus_energy_->GetEntry(entry_);
    c_mus_energy_ = true;
  }
  return mus_energy_;
}

std::vector<float>* const & cfa_13::mus_et() const{
  if(!c_mus_et_ && b_mus_et_){
    b_mus_et_->GetEntry(entry_);
    c_mus_et_ = true;
  }
  return mus_et_;
}

std::vector<float>* const & cfa_13::mus_eta() const{
  if(!c_mus_eta_ && b_mus_eta_){
    b_mus_eta_->GetEntry(entry_);
    c_mus_eta_ = true;
  }
  return mus_eta_;
}

std::vector<float>* const & cfa_13::mus_gen_et() const{
  if(!c_mus_gen_et_ && b_mus_gen_et_){
    b_mus_gen_et_->GetEntry(entry_);
    c_mus_gen_et_ = true;
  }
  return mus_gen_et_;
}

std::vector<float>* const & cfa_13::mus_gen_eta() const{
  if(!c_mus_gen_eta_ && b_mus_gen_eta_){
    b_mus_gen_eta_->GetEntry(entry_);
    c_mus_gen_eta_ = true;
  }
  return mus_gen_eta_;
}

std::vector<float>* const & cfa_13::mus_gen_id() const{
  if(!c_mus_gen_id_ && b_mus_gen_id_){
    b_mus_gen_id_->GetEntry(entry_);
    c_mus_gen_id_ = true;
  }
  return mus_gen_id_;
}

std::vector<float>* const & cfa_13::mus_gen_mother_et() const{
  if(!c_mus_gen_mother_et_ && b_mus_gen_mother_et_){
    b_mus_gen_mother_et_->GetEntry(entry_);
    c_mus_gen_mother_et_ = true;
  }
  return mus_gen_mother_et_;
}

std::vector<float>* const & cfa_13::mus_gen_mother_eta() const{
  if(!c_mus_gen_mother_eta_ && b_mus_gen_mother_eta_){
    b_mus_gen_mother_eta_->GetEntry(entry_);
    c_mus_gen_mother_eta_ = true;
  }
  return mus_gen_mother_eta_;
}

std::vector<float>* const & cfa_13::mus_gen_mother_id() const{
  if(!c_mus_gen_mother_id_ && b_mus_gen_mother_id_){
    b_mus_gen_mother_id_->GetEntry(entry_);
    c_mus_gen_mother_id_ = true;
  }
  return mus_gen_mother_id_;
}

std::vector<float>* const & cfa_13::mus_gen_mother_phi() const{
  if(!c_mus_gen_mother_phi_ && b_mus_gen_mother_phi_){
    b_mus_gen_mother_phi_->GetEntry(entry_);
    c_mus_gen_mother_phi_ = true;
  }
  return mus_gen_mother_phi_;
}

std::vector<float>* const & cfa_13::mus_gen_mother_pt() const{
  if(!c_mus_gen_mother_pt_ && b_mus_gen_mother_pt_){
    b_mus_gen_mother_pt_->GetEntry(entry_);
    c_mus_gen_mother_pt_ = true;
  }
  return mus_gen_mother_pt_;
}

std::vector<float>* const & cfa_13::mus_gen_mother_px() const{
  if(!c_mus_gen_mother_px_ && b_mus_gen_mother_px_){
    b_mus_gen_mother_px_->GetEntry(entry_);
    c_mus_gen_mother_px_ = true;
  }
  return mus_gen_mother_px_;
}

std::vector<float>* const & cfa_13::mus_gen_mother_py() const{
  if(!c_mus_gen_mother_py_ && b_mus_gen_mother_py_){
    b_mus_gen_mother_py_->GetEntry(entry_);
    c_mus_gen_mother_py_ = true;
  }
  return mus_gen_mother_py_;
}

std::vector<float>* const & cfa_13::mus_gen_mother_pz() const{
  if(!c_mus_gen_mother_pz_ && b_mus_gen_mother_pz_){
    b_mus_gen_mother_pz_->GetEntry(entry_);
    c_mus_gen_mother_pz_ = true;
  }
  return mus_gen_mother_pz_;
}

std::vector<float>* const & cfa_13::mus_gen_mother_theta() const{
  if(!c_mus_gen_mother_theta_ && b_mus_gen_mother_theta_){
    b_mus_gen_mother_theta_->GetEntry(entry_);
    c_mus_gen_mother_theta_ = true;
  }
  return mus_gen_mother_theta_;
}

std::vector<float>* const & cfa_13::mus_gen_phi() const{
  if(!c_mus_gen_phi_ && b_mus_gen_phi_){
    b_mus_gen_phi_->GetEntry(entry_);
    c_mus_gen_phi_ = true;
  }
  return mus_gen_phi_;
}

std::vector<float>* const & cfa_13::mus_gen_pt() const{
  if(!c_mus_gen_pt_ && b_mus_gen_pt_){
    b_mus_gen_pt_->GetEntry(entry_);
    c_mus_gen_pt_ = true;
  }
  return mus_gen_pt_;
}

std::vector<float>* const & cfa_13::mus_gen_px() const{
  if(!c_mus_gen_px_ && b_mus_gen_px_){
    b_mus_gen_px_->GetEntry(entry_);
    c_mus_gen_px_ = true;
  }
  return mus_gen_px_;
}

std::vector<float>* const & cfa_13::mus_gen_py() const{
  if(!c_mus_gen_py_ && b_mus_gen_py_){
    b_mus_gen_py_->GetEntry(entry_);
    c_mus_gen_py_ = true;
  }
  return mus_gen_py_;
}

std::vector<float>* const & cfa_13::mus_gen_pz() const{
  if(!c_mus_gen_pz_ && b_mus_gen_pz_){
    b_mus_gen_pz_->GetEntry(entry_);
    c_mus_gen_pz_ = true;
  }
  return mus_gen_pz_;
}

std::vector<float>* const & cfa_13::mus_gen_theta() const{
  if(!c_mus_gen_theta_ && b_mus_gen_theta_){
    b_mus_gen_theta_->GetEntry(entry_);
    c_mus_gen_theta_ = true;
  }
  return mus_gen_theta_;
}

std::vector<float>* const & cfa_13::mus_hcalIso() const{
  if(!c_mus_hcalIso_ && b_mus_hcalIso_){
    b_mus_hcalIso_->GetEntry(entry_);
    c_mus_hcalIso_ = true;
  }
  return mus_hcalIso_;
}

std::vector<float>* const & cfa_13::mus_hcalvetoDep() const{
  if(!c_mus_hcalvetoDep_ && b_mus_hcalvetoDep_){
    b_mus_hcalvetoDep_->GetEntry(entry_);
    c_mus_hcalvetoDep_ = true;
  }
  return mus_hcalvetoDep_;
}

std::vector<float>* const & cfa_13::mus_id_All() const{
  if(!c_mus_id_All_ && b_mus_id_All_){
    b_mus_id_All_->GetEntry(entry_);
    c_mus_id_All_ = true;
  }
  return mus_id_All_;
}

std::vector<float>* const & cfa_13::mus_id_AllArbitrated() const{
  if(!c_mus_id_AllArbitrated_ && b_mus_id_AllArbitrated_){
    b_mus_id_AllArbitrated_->GetEntry(entry_);
    c_mus_id_AllArbitrated_ = true;
  }
  return mus_id_AllArbitrated_;
}

std::vector<float>* const & cfa_13::mus_id_AllGlobalMuons() const{
  if(!c_mus_id_AllGlobalMuons_ && b_mus_id_AllGlobalMuons_){
    b_mus_id_AllGlobalMuons_->GetEntry(entry_);
    c_mus_id_AllGlobalMuons_ = true;
  }
  return mus_id_AllGlobalMuons_;
}

std::vector<float>* const & cfa_13::mus_id_AllStandAloneMuons() const{
  if(!c_mus_id_AllStandAloneMuons_ && b_mus_id_AllStandAloneMuons_){
    b_mus_id_AllStandAloneMuons_->GetEntry(entry_);
    c_mus_id_AllStandAloneMuons_ = true;
  }
  return mus_id_AllStandAloneMuons_;
}

std::vector<float>* const & cfa_13::mus_id_AllTrackerMuons() const{
  if(!c_mus_id_AllTrackerMuons_ && b_mus_id_AllTrackerMuons_){
    b_mus_id_AllTrackerMuons_->GetEntry(entry_);
    c_mus_id_AllTrackerMuons_ = true;
  }
  return mus_id_AllTrackerMuons_;
}

std::vector<float>* const & cfa_13::mus_id_GlobalMuonPromptTight() const{
  if(!c_mus_id_GlobalMuonPromptTight_ && b_mus_id_GlobalMuonPromptTight_){
    b_mus_id_GlobalMuonPromptTight_->GetEntry(entry_);
    c_mus_id_GlobalMuonPromptTight_ = true;
  }
  return mus_id_GlobalMuonPromptTight_;
}

std::vector<float>* const & cfa_13::mus_id_TM2DCompatibilityLoose() const{
  if(!c_mus_id_TM2DCompatibilityLoose_ && b_mus_id_TM2DCompatibilityLoose_){
    b_mus_id_TM2DCompatibilityLoose_->GetEntry(entry_);
    c_mus_id_TM2DCompatibilityLoose_ = true;
  }
  return mus_id_TM2DCompatibilityLoose_;
}

std::vector<float>* const & cfa_13::mus_id_TM2DCompatibilityTight() const{
  if(!c_mus_id_TM2DCompatibilityTight_ && b_mus_id_TM2DCompatibilityTight_){
    b_mus_id_TM2DCompatibilityTight_->GetEntry(entry_);
    c_mus_id_TM2DCompatibilityTight_ = true;
  }
  return mus_id_TM2DCompatibilityTight_;
}

std::vector<float>* const & cfa_13::mus_id_TMLastStationLoose() const{
  if(!c_mus_id_TMLastStationLoose_ && b_mus_id_TMLastStationLoose_){
    b_mus_id_TMLastStationLoose_->GetEntry(entry_);
    c_mus_id_TMLastStationLoose_ = true;
  }
  return mus_id_TMLastStationLoose_;
}

std::vector<float>* const & cfa_13::mus_id_TMLastStationOptimizedLowPtLoose() const{
  if(!c_mus_id_TMLastStationOptimizedLowPtLoose_ && b_mus_id_TMLastStationOptimizedLowPtLoose_){
    b_mus_id_TMLastStationOptimizedLowPtLoose_->GetEntry(entry_);
    c_mus_id_TMLastStationOptimizedLowPtLoose_ = true;
  }
  return mus_id_TMLastStationOptimizedLowPtLoose_;
}

std::vector<float>* const & cfa_13::mus_id_TMLastStationOptimizedLowPtTight() const{
  if(!c_mus_id_TMLastStationOptimizedLowPtTight_ && b_mus_id_TMLastStationOptimizedLowPtTight_){
    b_mus_id_TMLastStationOptimizedLowPtTight_->GetEntry(entry_);
    c_mus_id_TMLastStationOptimizedLowPtTight_ = true;
  }
  return mus_id_TMLastStationOptimizedLowPtTight_;
}

std::vector<float>* const & cfa_13::mus_id_TMLastStationTight() const{
  if(!c_mus_id_TMLastStationTight_ && b_mus_id_TMLastStationTight_){
    b_mus_id_TMLastStationTight_->GetEntry(entry_);
    c_mus_id_TMLastStationTight_ = true;
  }
  return mus_id_TMLastStationTight_;
}

std::vector<float>* const & cfa_13::mus_id_TMOneStationLoose() const{
  if(!c_mus_id_TMOneStationLoose_ && b_mus_id_TMOneStationLoose_){
    b_mus_id_TMOneStationLoose_->GetEntry(entry_);
    c_mus_id_TMOneStationLoose_ = true;
  }
  return mus_id_TMOneStationLoose_;
}

std::vector<float>* const & cfa_13::mus_id_TMOneStationTight() const{
  if(!c_mus_id_TMOneStationTight_ && b_mus_id_TMOneStationTight_){
    b_mus_id_TMOneStationTight_->GetEntry(entry_);
    c_mus_id_TMOneStationTight_ = true;
  }
  return mus_id_TMOneStationTight_;
}

std::vector<float>* const & cfa_13::mus_id_TrackerMuonArbitrated() const{
  if(!c_mus_id_TrackerMuonArbitrated_ && b_mus_id_TrackerMuonArbitrated_){
    b_mus_id_TrackerMuonArbitrated_->GetEntry(entry_);
    c_mus_id_TrackerMuonArbitrated_ = true;
  }
  return mus_id_TrackerMuonArbitrated_;
}

std::vector<float>* const & cfa_13::mus_isCaloMuon() const{
  if(!c_mus_isCaloMuon_ && b_mus_isCaloMuon_){
    b_mus_isCaloMuon_->GetEntry(entry_);
    c_mus_isCaloMuon_ = true;
  }
  return mus_isCaloMuon_;
}

std::vector<float>* const & cfa_13::mus_isConvertedPhoton() const{
  if(!c_mus_isConvertedPhoton_ && b_mus_isConvertedPhoton_){
    b_mus_isConvertedPhoton_->GetEntry(entry_);
    c_mus_isConvertedPhoton_ = true;
  }
  return mus_isConvertedPhoton_;
}

std::vector<float>* const & cfa_13::mus_isElectron() const{
  if(!c_mus_isElectron_ && b_mus_isElectron_){
    b_mus_isElectron_->GetEntry(entry_);
    c_mus_isElectron_ = true;
  }
  return mus_isElectron_;
}

std::vector<float>* const & cfa_13::mus_isGlobalMuon() const{
  if(!c_mus_isGlobalMuon_ && b_mus_isGlobalMuon_){
    b_mus_isGlobalMuon_->GetEntry(entry_);
    c_mus_isGlobalMuon_ = true;
  }
  return mus_isGlobalMuon_;
}

std::vector<bool>* const & cfa_13::mus_isPF() const{
  if(!c_mus_isPF_ && b_mus_isPF_){
    b_mus_isPF_->GetEntry(entry_);
    c_mus_isPF_ = true;
  }
  return mus_isPF_;
}

std::vector<float>* const & cfa_13::mus_isPFMuon() const{
  if(!c_mus_isPFMuon_ && b_mus_isPFMuon_){
    b_mus_isPFMuon_->GetEntry(entry_);
    c_mus_isPFMuon_ = true;
  }
  return mus_isPFMuon_;
}

std::vector<float>* const & cfa_13::mus_isPhoton() const{
  if(!c_mus_isPhoton_ && b_mus_isPhoton_){
    b_mus_isPhoton_->GetEntry(entry_);
    c_mus_isPhoton_ = true;
  }
  return mus_isPhoton_;
}

std::vector<float>* const & cfa_13::mus_isStandAloneMuon() const{
  if(!c_mus_isStandAloneMuon_ && b_mus_isStandAloneMuon_){
    b_mus_isStandAloneMuon_->GetEntry(entry_);
    c_mus_isStandAloneMuon_ = true;
  }
  return mus_isStandAloneMuon_;
}

std::vector<float>* const & cfa_13::mus_isTrackerMuon() const{
  if(!c_mus_isTrackerMuon_ && b_mus_isTrackerMuon_){
    b_mus_isTrackerMuon_->GetEntry(entry_);
    c_mus_isTrackerMuon_ = true;
  }
  return mus_isTrackerMuon_;
}

std::vector<float>* const & cfa_13::mus_iso03_emEt() const{
  if(!c_mus_iso03_emEt_ && b_mus_iso03_emEt_){
    b_mus_iso03_emEt_->GetEntry(entry_);
    c_mus_iso03_emEt_ = true;
  }
  return mus_iso03_emEt_;
}

std::vector<float>* const & cfa_13::mus_iso03_emVetoEt() const{
  if(!c_mus_iso03_emVetoEt_ && b_mus_iso03_emVetoEt_){
    b_mus_iso03_emVetoEt_->GetEntry(entry_);
    c_mus_iso03_emVetoEt_ = true;
  }
  return mus_iso03_emVetoEt_;
}

std::vector<float>* const & cfa_13::mus_iso03_hadEt() const{
  if(!c_mus_iso03_hadEt_ && b_mus_iso03_hadEt_){
    b_mus_iso03_hadEt_->GetEntry(entry_);
    c_mus_iso03_hadEt_ = true;
  }
  return mus_iso03_hadEt_;
}

std::vector<float>* const & cfa_13::mus_iso03_hadVetoEt() const{
  if(!c_mus_iso03_hadVetoEt_ && b_mus_iso03_hadVetoEt_){
    b_mus_iso03_hadVetoEt_->GetEntry(entry_);
    c_mus_iso03_hadVetoEt_ = true;
  }
  return mus_iso03_hadVetoEt_;
}

std::vector<float>* const & cfa_13::mus_iso03_hoEt() const{
  if(!c_mus_iso03_hoEt_ && b_mus_iso03_hoEt_){
    b_mus_iso03_hoEt_->GetEntry(entry_);
    c_mus_iso03_hoEt_ = true;
  }
  return mus_iso03_hoEt_;
}

std::vector<float>* const & cfa_13::mus_iso03_nTracks() const{
  if(!c_mus_iso03_nTracks_ && b_mus_iso03_nTracks_){
    b_mus_iso03_nTracks_->GetEntry(entry_);
    c_mus_iso03_nTracks_ = true;
  }
  return mus_iso03_nTracks_;
}

std::vector<float>* const & cfa_13::mus_iso03_sumPt() const{
  if(!c_mus_iso03_sumPt_ && b_mus_iso03_sumPt_){
    b_mus_iso03_sumPt_->GetEntry(entry_);
    c_mus_iso03_sumPt_ = true;
  }
  return mus_iso03_sumPt_;
}

std::vector<float>* const & cfa_13::mus_iso05_emEt() const{
  if(!c_mus_iso05_emEt_ && b_mus_iso05_emEt_){
    b_mus_iso05_emEt_->GetEntry(entry_);
    c_mus_iso05_emEt_ = true;
  }
  return mus_iso05_emEt_;
}

std::vector<float>* const & cfa_13::mus_iso05_hadEt() const{
  if(!c_mus_iso05_hadEt_ && b_mus_iso05_hadEt_){
    b_mus_iso05_hadEt_->GetEntry(entry_);
    c_mus_iso05_hadEt_ = true;
  }
  return mus_iso05_hadEt_;
}

std::vector<float>* const & cfa_13::mus_iso05_hoEt() const{
  if(!c_mus_iso05_hoEt_ && b_mus_iso05_hoEt_){
    b_mus_iso05_hoEt_->GetEntry(entry_);
    c_mus_iso05_hoEt_ = true;
  }
  return mus_iso05_hoEt_;
}

std::vector<float>* const & cfa_13::mus_iso05_nTracks() const{
  if(!c_mus_iso05_nTracks_ && b_mus_iso05_nTracks_){
    b_mus_iso05_nTracks_->GetEntry(entry_);
    c_mus_iso05_nTracks_ = true;
  }
  return mus_iso05_nTracks_;
}

std::vector<float>* const & cfa_13::mus_iso05_sumPt() const{
  if(!c_mus_iso05_sumPt_ && b_mus_iso05_sumPt_){
    b_mus_iso05_sumPt_->GetEntry(entry_);
    c_mus_iso05_sumPt_ = true;
  }
  return mus_iso05_sumPt_;
}

std::vector<int>* const & cfa_13::mus_jet_ind() const{
  if(!c_mus_jet_ind_ && b_mus_jet_ind_){
    b_mus_jet_ind_->GetEntry(entry_);
    c_mus_jet_ind_ = true;
  }
  return mus_jet_ind_;
}

std::vector<float>* const & cfa_13::mus_num_matches() const{
  if(!c_mus_num_matches_ && b_mus_num_matches_){
    b_mus_num_matches_->GetEntry(entry_);
    c_mus_num_matches_ = true;
  }
  return mus_num_matches_;
}

std::vector<float>* const & cfa_13::mus_numberOfMatchedStations() const{
  if(!c_mus_numberOfMatchedStations_ && b_mus_numberOfMatchedStations_){
    b_mus_numberOfMatchedStations_->GetEntry(entry_);
    c_mus_numberOfMatchedStations_ = true;
  }
  return mus_numberOfMatchedStations_;
}

std::vector<float>* const & cfa_13::mus_pfIsolationR03_sumChargedHadronPt() const{
  if(!c_mus_pfIsolationR03_sumChargedHadronPt_ && b_mus_pfIsolationR03_sumChargedHadronPt_){
    b_mus_pfIsolationR03_sumChargedHadronPt_->GetEntry(entry_);
    c_mus_pfIsolationR03_sumChargedHadronPt_ = true;
  }
  return mus_pfIsolationR03_sumChargedHadronPt_;
}

std::vector<float>* const & cfa_13::mus_pfIsolationR03_sumChargedParticlePt() const{
  if(!c_mus_pfIsolationR03_sumChargedParticlePt_ && b_mus_pfIsolationR03_sumChargedParticlePt_){
    b_mus_pfIsolationR03_sumChargedParticlePt_->GetEntry(entry_);
    c_mus_pfIsolationR03_sumChargedParticlePt_ = true;
  }
  return mus_pfIsolationR03_sumChargedParticlePt_;
}

std::vector<float>* const & cfa_13::mus_pfIsolationR03_sumNeutralHadronEt() const{
  if(!c_mus_pfIsolationR03_sumNeutralHadronEt_ && b_mus_pfIsolationR03_sumNeutralHadronEt_){
    b_mus_pfIsolationR03_sumNeutralHadronEt_->GetEntry(entry_);
    c_mus_pfIsolationR03_sumNeutralHadronEt_ = true;
  }
  return mus_pfIsolationR03_sumNeutralHadronEt_;
}

std::vector<float>* const & cfa_13::mus_pfIsolationR03_sumNeutralHadronEtHighThreshold() const{
  if(!c_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_ && b_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_){
    b_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_->GetEntry(entry_);
    c_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_ = true;
  }
  return mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_;
}

std::vector<float>* const & cfa_13::mus_pfIsolationR03_sumPUPt() const{
  if(!c_mus_pfIsolationR03_sumPUPt_ && b_mus_pfIsolationR03_sumPUPt_){
    b_mus_pfIsolationR03_sumPUPt_->GetEntry(entry_);
    c_mus_pfIsolationR03_sumPUPt_ = true;
  }
  return mus_pfIsolationR03_sumPUPt_;
}

std::vector<float>* const & cfa_13::mus_pfIsolationR03_sumPhotonEt() const{
  if(!c_mus_pfIsolationR03_sumPhotonEt_ && b_mus_pfIsolationR03_sumPhotonEt_){
    b_mus_pfIsolationR03_sumPhotonEt_->GetEntry(entry_);
    c_mus_pfIsolationR03_sumPhotonEt_ = true;
  }
  return mus_pfIsolationR03_sumPhotonEt_;
}

std::vector<float>* const & cfa_13::mus_pfIsolationR03_sumPhotonEtHighThreshold() const{
  if(!c_mus_pfIsolationR03_sumPhotonEtHighThreshold_ && b_mus_pfIsolationR03_sumPhotonEtHighThreshold_){
    b_mus_pfIsolationR03_sumPhotonEtHighThreshold_->GetEntry(entry_);
    c_mus_pfIsolationR03_sumPhotonEtHighThreshold_ = true;
  }
  return mus_pfIsolationR03_sumPhotonEtHighThreshold_;
}

std::vector<float>* const & cfa_13::mus_pfIsolationR04_sumChargedHadronPt() const{
  if(!c_mus_pfIsolationR04_sumChargedHadronPt_ && b_mus_pfIsolationR04_sumChargedHadronPt_){
    b_mus_pfIsolationR04_sumChargedHadronPt_->GetEntry(entry_);
    c_mus_pfIsolationR04_sumChargedHadronPt_ = true;
  }
  return mus_pfIsolationR04_sumChargedHadronPt_;
}

std::vector<float>* const & cfa_13::mus_pfIsolationR04_sumChargedParticlePt() const{
  if(!c_mus_pfIsolationR04_sumChargedParticlePt_ && b_mus_pfIsolationR04_sumChargedParticlePt_){
    b_mus_pfIsolationR04_sumChargedParticlePt_->GetEntry(entry_);
    c_mus_pfIsolationR04_sumChargedParticlePt_ = true;
  }
  return mus_pfIsolationR04_sumChargedParticlePt_;
}

std::vector<float>* const & cfa_13::mus_pfIsolationR04_sumNeutralHadronEt() const{
  if(!c_mus_pfIsolationR04_sumNeutralHadronEt_ && b_mus_pfIsolationR04_sumNeutralHadronEt_){
    b_mus_pfIsolationR04_sumNeutralHadronEt_->GetEntry(entry_);
    c_mus_pfIsolationR04_sumNeutralHadronEt_ = true;
  }
  return mus_pfIsolationR04_sumNeutralHadronEt_;
}

std::vector<float>* const & cfa_13::mus_pfIsolationR04_sumNeutralHadronEtHighThreshold() const{
  if(!c_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_ && b_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_){
    b_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_->GetEntry(entry_);
    c_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_ = true;
  }
  return mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_;
}

std::vector<float>* const & cfa_13::mus_pfIsolationR04_sumPUPt() const{
  if(!c_mus_pfIsolationR04_sumPUPt_ && b_mus_pfIsolationR04_sumPUPt_){
    b_mus_pfIsolationR04_sumPUPt_->GetEntry(entry_);
    c_mus_pfIsolationR04_sumPUPt_ = true;
  }
  return mus_pfIsolationR04_sumPUPt_;
}

std::vector<float>* const & cfa_13::mus_pfIsolationR04_sumPhotonEt() const{
  if(!c_mus_pfIsolationR04_sumPhotonEt_ && b_mus_pfIsolationR04_sumPhotonEt_){
    b_mus_pfIsolationR04_sumPhotonEt_->GetEntry(entry_);
    c_mus_pfIsolationR04_sumPhotonEt_ = true;
  }
  return mus_pfIsolationR04_sumPhotonEt_;
}

std::vector<float>* const & cfa_13::mus_pfIsolationR04_sumPhotonEtHighThreshold() const{
  if(!c_mus_pfIsolationR04_sumPhotonEtHighThreshold_ && b_mus_pfIsolationR04_sumPhotonEtHighThreshold_){
    b_mus_pfIsolationR04_sumPhotonEtHighThreshold_->GetEntry(entry_);
    c_mus_pfIsolationR04_sumPhotonEtHighThreshold_ = true;
  }
  return mus_pfIsolationR04_sumPhotonEtHighThreshold_;
}

std::vector<float>* const & cfa_13::mus_phi() const{
  if(!c_mus_phi_ && b_mus_phi_){
    b_mus_phi_->GetEntry(entry_);
    c_mus_phi_ = true;
  }
  return mus_phi_;
}

std::vector<float>* const & cfa_13::mus_picky_ExpectedHitsInner() const{
  if(!c_mus_picky_ExpectedHitsInner_ && b_mus_picky_ExpectedHitsInner_){
    b_mus_picky_ExpectedHitsInner_->GetEntry(entry_);
    c_mus_picky_ExpectedHitsInner_ = true;
  }
  return mus_picky_ExpectedHitsInner_;
}

std::vector<float>* const & cfa_13::mus_picky_ExpectedHitsOuter() const{
  if(!c_mus_picky_ExpectedHitsOuter_ && b_mus_picky_ExpectedHitsOuter_){
    b_mus_picky_ExpectedHitsOuter_->GetEntry(entry_);
    c_mus_picky_ExpectedHitsOuter_ = true;
  }
  return mus_picky_ExpectedHitsOuter_;
}

std::vector<float>* const & cfa_13::mus_picky_LayersWithMeasurement() const{
  if(!c_mus_picky_LayersWithMeasurement_ && b_mus_picky_LayersWithMeasurement_){
    b_mus_picky_LayersWithMeasurement_->GetEntry(entry_);
    c_mus_picky_LayersWithMeasurement_ = true;
  }
  return mus_picky_LayersWithMeasurement_;
}

std::vector<float>* const & cfa_13::mus_picky_LayersWithoutMeasurement() const{
  if(!c_mus_picky_LayersWithoutMeasurement_ && b_mus_picky_LayersWithoutMeasurement_){
    b_mus_picky_LayersWithoutMeasurement_->GetEntry(entry_);
    c_mus_picky_LayersWithoutMeasurement_ = true;
  }
  return mus_picky_LayersWithoutMeasurement_;
}

std::vector<float>* const & cfa_13::mus_picky_PixelLayersWithMeasurement() const{
  if(!c_mus_picky_PixelLayersWithMeasurement_ && b_mus_picky_PixelLayersWithMeasurement_){
    b_mus_picky_PixelLayersWithMeasurement_->GetEntry(entry_);
    c_mus_picky_PixelLayersWithMeasurement_ = true;
  }
  return mus_picky_PixelLayersWithMeasurement_;
}

std::vector<float>* const & cfa_13::mus_picky_ValidStripLayersWithMonoAndStereoHit() const{
  if(!c_mus_picky_ValidStripLayersWithMonoAndStereoHit_ && b_mus_picky_ValidStripLayersWithMonoAndStereoHit_){
    b_mus_picky_ValidStripLayersWithMonoAndStereoHit_->GetEntry(entry_);
    c_mus_picky_ValidStripLayersWithMonoAndStereoHit_ = true;
  }
  return mus_picky_ValidStripLayersWithMonoAndStereoHit_;
}

std::vector<float>* const & cfa_13::mus_picky_chg() const{
  if(!c_mus_picky_chg_ && b_mus_picky_chg_){
    b_mus_picky_chg_->GetEntry(entry_);
    c_mus_picky_chg_ = true;
  }
  return mus_picky_chg_;
}

std::vector<float>* const & cfa_13::mus_picky_chi2() const{
  if(!c_mus_picky_chi2_ && b_mus_picky_chi2_){
    b_mus_picky_chi2_->GetEntry(entry_);
    c_mus_picky_chi2_ = true;
  }
  return mus_picky_chi2_;
}

std::vector<float>* const & cfa_13::mus_picky_d0dum() const{
  if(!c_mus_picky_d0dum_ && b_mus_picky_d0dum_){
    b_mus_picky_d0dum_->GetEntry(entry_);
    c_mus_picky_d0dum_ = true;
  }
  return mus_picky_d0dum_;
}

std::vector<float>* const & cfa_13::mus_picky_d0dumErr() const{
  if(!c_mus_picky_d0dumErr_ && b_mus_picky_d0dumErr_){
    b_mus_picky_d0dumErr_->GetEntry(entry_);
    c_mus_picky_d0dumErr_ = true;
  }
  return mus_picky_d0dumErr_;
}

std::vector<float>* const & cfa_13::mus_picky_dz() const{
  if(!c_mus_picky_dz_ && b_mus_picky_dz_){
    b_mus_picky_dz_->GetEntry(entry_);
    c_mus_picky_dz_ = true;
  }
  return mus_picky_dz_;
}

std::vector<float>* const & cfa_13::mus_picky_dzErr() const{
  if(!c_mus_picky_dzErr_ && b_mus_picky_dzErr_){
    b_mus_picky_dzErr_->GetEntry(entry_);
    c_mus_picky_dzErr_ = true;
  }
  return mus_picky_dzErr_;
}

std::vector<float>* const & cfa_13::mus_picky_eta() const{
  if(!c_mus_picky_eta_ && b_mus_picky_eta_){
    b_mus_picky_eta_->GetEntry(entry_);
    c_mus_picky_eta_ = true;
  }
  return mus_picky_eta_;
}

std::vector<float>* const & cfa_13::mus_picky_etaErr() const{
  if(!c_mus_picky_etaErr_ && b_mus_picky_etaErr_){
    b_mus_picky_etaErr_->GetEntry(entry_);
    c_mus_picky_etaErr_ = true;
  }
  return mus_picky_etaErr_;
}

std::vector<float>* const & cfa_13::mus_picky_id() const{
  if(!c_mus_picky_id_ && b_mus_picky_id_){
    b_mus_picky_id_->GetEntry(entry_);
    c_mus_picky_id_ = true;
  }
  return mus_picky_id_;
}

std::vector<float>* const & cfa_13::mus_picky_ndof() const{
  if(!c_mus_picky_ndof_ && b_mus_picky_ndof_){
    b_mus_picky_ndof_->GetEntry(entry_);
    c_mus_picky_ndof_ = true;
  }
  return mus_picky_ndof_;
}

std::vector<float>* const & cfa_13::mus_picky_numlosthits() const{
  if(!c_mus_picky_numlosthits_ && b_mus_picky_numlosthits_){
    b_mus_picky_numlosthits_->GetEntry(entry_);
    c_mus_picky_numlosthits_ = true;
  }
  return mus_picky_numlosthits_;
}

std::vector<float>* const & cfa_13::mus_picky_numvalPixelhits() const{
  if(!c_mus_picky_numvalPixelhits_ && b_mus_picky_numvalPixelhits_){
    b_mus_picky_numvalPixelhits_->GetEntry(entry_);
    c_mus_picky_numvalPixelhits_ = true;
  }
  return mus_picky_numvalPixelhits_;
}

std::vector<float>* const & cfa_13::mus_picky_numvalhits() const{
  if(!c_mus_picky_numvalhits_ && b_mus_picky_numvalhits_){
    b_mus_picky_numvalhits_->GetEntry(entry_);
    c_mus_picky_numvalhits_ = true;
  }
  return mus_picky_numvalhits_;
}

std::vector<float>* const & cfa_13::mus_picky_phi() const{
  if(!c_mus_picky_phi_ && b_mus_picky_phi_){
    b_mus_picky_phi_->GetEntry(entry_);
    c_mus_picky_phi_ = true;
  }
  return mus_picky_phi_;
}

std::vector<float>* const & cfa_13::mus_picky_phiErr() const{
  if(!c_mus_picky_phiErr_ && b_mus_picky_phiErr_){
    b_mus_picky_phiErr_->GetEntry(entry_);
    c_mus_picky_phiErr_ = true;
  }
  return mus_picky_phiErr_;
}

std::vector<float>* const & cfa_13::mus_picky_pt() const{
  if(!c_mus_picky_pt_ && b_mus_picky_pt_){
    b_mus_picky_pt_->GetEntry(entry_);
    c_mus_picky_pt_ = true;
  }
  return mus_picky_pt_;
}

std::vector<float>* const & cfa_13::mus_picky_ptErr() const{
  if(!c_mus_picky_ptErr_ && b_mus_picky_ptErr_){
    b_mus_picky_ptErr_->GetEntry(entry_);
    c_mus_picky_ptErr_ = true;
  }
  return mus_picky_ptErr_;
}

std::vector<float>* const & cfa_13::mus_picky_px() const{
  if(!c_mus_picky_px_ && b_mus_picky_px_){
    b_mus_picky_px_->GetEntry(entry_);
    c_mus_picky_px_ = true;
  }
  return mus_picky_px_;
}

std::vector<float>* const & cfa_13::mus_picky_py() const{
  if(!c_mus_picky_py_ && b_mus_picky_py_){
    b_mus_picky_py_->GetEntry(entry_);
    c_mus_picky_py_ = true;
  }
  return mus_picky_py_;
}

std::vector<float>* const & cfa_13::mus_picky_pz() const{
  if(!c_mus_picky_pz_ && b_mus_picky_pz_){
    b_mus_picky_pz_->GetEntry(entry_);
    c_mus_picky_pz_ = true;
  }
  return mus_picky_pz_;
}

std::vector<float>* const & cfa_13::mus_picky_theta() const{
  if(!c_mus_picky_theta_ && b_mus_picky_theta_){
    b_mus_picky_theta_->GetEntry(entry_);
    c_mus_picky_theta_ = true;
  }
  return mus_picky_theta_;
}

std::vector<float>* const & cfa_13::mus_picky_vx() const{
  if(!c_mus_picky_vx_ && b_mus_picky_vx_){
    b_mus_picky_vx_->GetEntry(entry_);
    c_mus_picky_vx_ = true;
  }
  return mus_picky_vx_;
}

std::vector<float>* const & cfa_13::mus_picky_vy() const{
  if(!c_mus_picky_vy_ && b_mus_picky_vy_){
    b_mus_picky_vy_->GetEntry(entry_);
    c_mus_picky_vy_ = true;
  }
  return mus_picky_vy_;
}

std::vector<float>* const & cfa_13::mus_picky_vz() const{
  if(!c_mus_picky_vz_ && b_mus_picky_vz_){
    b_mus_picky_vz_->GetEntry(entry_);
    c_mus_picky_vz_ = true;
  }
  return mus_picky_vz_;
}

std::vector<float>* const & cfa_13::mus_pt() const{
  if(!c_mus_pt_ && b_mus_pt_){
    b_mus_pt_->GetEntry(entry_);
    c_mus_pt_ = true;
  }
  return mus_pt_;
}

std::vector<float>* const & cfa_13::mus_px() const{
  if(!c_mus_px_ && b_mus_px_){
    b_mus_px_->GetEntry(entry_);
    c_mus_px_ = true;
  }
  return mus_px_;
}

std::vector<float>* const & cfa_13::mus_py() const{
  if(!c_mus_py_ && b_mus_py_){
    b_mus_py_->GetEntry(entry_);
    c_mus_py_ = true;
  }
  return mus_py_;
}

std::vector<float>* const & cfa_13::mus_pz() const{
  if(!c_mus_pz_ && b_mus_pz_){
    b_mus_pz_->GetEntry(entry_);
    c_mus_pz_ = true;
  }
  return mus_pz_;
}

std::vector<float>* const & cfa_13::mus_stamu_chg() const{
  if(!c_mus_stamu_chg_ && b_mus_stamu_chg_){
    b_mus_stamu_chg_->GetEntry(entry_);
    c_mus_stamu_chg_ = true;
  }
  return mus_stamu_chg_;
}

std::vector<float>* const & cfa_13::mus_stamu_chi2() const{
  if(!c_mus_stamu_chi2_ && b_mus_stamu_chi2_){
    b_mus_stamu_chi2_->GetEntry(entry_);
    c_mus_stamu_chi2_ = true;
  }
  return mus_stamu_chi2_;
}

std::vector<float>* const & cfa_13::mus_stamu_d0dum() const{
  if(!c_mus_stamu_d0dum_ && b_mus_stamu_d0dum_){
    b_mus_stamu_d0dum_->GetEntry(entry_);
    c_mus_stamu_d0dum_ = true;
  }
  return mus_stamu_d0dum_;
}

std::vector<float>* const & cfa_13::mus_stamu_d0dumErr() const{
  if(!c_mus_stamu_d0dumErr_ && b_mus_stamu_d0dumErr_){
    b_mus_stamu_d0dumErr_->GetEntry(entry_);
    c_mus_stamu_d0dumErr_ = true;
  }
  return mus_stamu_d0dumErr_;
}

std::vector<float>* const & cfa_13::mus_stamu_dz() const{
  if(!c_mus_stamu_dz_ && b_mus_stamu_dz_){
    b_mus_stamu_dz_->GetEntry(entry_);
    c_mus_stamu_dz_ = true;
  }
  return mus_stamu_dz_;
}

std::vector<float>* const & cfa_13::mus_stamu_dzErr() const{
  if(!c_mus_stamu_dzErr_ && b_mus_stamu_dzErr_){
    b_mus_stamu_dzErr_->GetEntry(entry_);
    c_mus_stamu_dzErr_ = true;
  }
  return mus_stamu_dzErr_;
}

std::vector<float>* const & cfa_13::mus_stamu_eta() const{
  if(!c_mus_stamu_eta_ && b_mus_stamu_eta_){
    b_mus_stamu_eta_->GetEntry(entry_);
    c_mus_stamu_eta_ = true;
  }
  return mus_stamu_eta_;
}

std::vector<float>* const & cfa_13::mus_stamu_etaErr() const{
  if(!c_mus_stamu_etaErr_ && b_mus_stamu_etaErr_){
    b_mus_stamu_etaErr_->GetEntry(entry_);
    c_mus_stamu_etaErr_ = true;
  }
  return mus_stamu_etaErr_;
}

std::vector<float>* const & cfa_13::mus_stamu_ndof() const{
  if(!c_mus_stamu_ndof_ && b_mus_stamu_ndof_){
    b_mus_stamu_ndof_->GetEntry(entry_);
    c_mus_stamu_ndof_ = true;
  }
  return mus_stamu_ndof_;
}

std::vector<float>* const & cfa_13::mus_stamu_numlosthits() const{
  if(!c_mus_stamu_numlosthits_ && b_mus_stamu_numlosthits_){
    b_mus_stamu_numlosthits_->GetEntry(entry_);
    c_mus_stamu_numlosthits_ = true;
  }
  return mus_stamu_numlosthits_;
}

std::vector<float>* const & cfa_13::mus_stamu_numvalhits() const{
  if(!c_mus_stamu_numvalhits_ && b_mus_stamu_numvalhits_){
    b_mus_stamu_numvalhits_->GetEntry(entry_);
    c_mus_stamu_numvalhits_ = true;
  }
  return mus_stamu_numvalhits_;
}

std::vector<float>* const & cfa_13::mus_stamu_phi() const{
  if(!c_mus_stamu_phi_ && b_mus_stamu_phi_){
    b_mus_stamu_phi_->GetEntry(entry_);
    c_mus_stamu_phi_ = true;
  }
  return mus_stamu_phi_;
}

std::vector<float>* const & cfa_13::mus_stamu_phiErr() const{
  if(!c_mus_stamu_phiErr_ && b_mus_stamu_phiErr_){
    b_mus_stamu_phiErr_->GetEntry(entry_);
    c_mus_stamu_phiErr_ = true;
  }
  return mus_stamu_phiErr_;
}

std::vector<float>* const & cfa_13::mus_stamu_pt() const{
  if(!c_mus_stamu_pt_ && b_mus_stamu_pt_){
    b_mus_stamu_pt_->GetEntry(entry_);
    c_mus_stamu_pt_ = true;
  }
  return mus_stamu_pt_;
}

std::vector<float>* const & cfa_13::mus_stamu_ptErr() const{
  if(!c_mus_stamu_ptErr_ && b_mus_stamu_ptErr_){
    b_mus_stamu_ptErr_->GetEntry(entry_);
    c_mus_stamu_ptErr_ = true;
  }
  return mus_stamu_ptErr_;
}

std::vector<float>* const & cfa_13::mus_stamu_px() const{
  if(!c_mus_stamu_px_ && b_mus_stamu_px_){
    b_mus_stamu_px_->GetEntry(entry_);
    c_mus_stamu_px_ = true;
  }
  return mus_stamu_px_;
}

std::vector<float>* const & cfa_13::mus_stamu_py() const{
  if(!c_mus_stamu_py_ && b_mus_stamu_py_){
    b_mus_stamu_py_->GetEntry(entry_);
    c_mus_stamu_py_ = true;
  }
  return mus_stamu_py_;
}

std::vector<float>* const & cfa_13::mus_stamu_pz() const{
  if(!c_mus_stamu_pz_ && b_mus_stamu_pz_){
    b_mus_stamu_pz_->GetEntry(entry_);
    c_mus_stamu_pz_ = true;
  }
  return mus_stamu_pz_;
}

std::vector<float>* const & cfa_13::mus_stamu_theta() const{
  if(!c_mus_stamu_theta_ && b_mus_stamu_theta_){
    b_mus_stamu_theta_->GetEntry(entry_);
    c_mus_stamu_theta_ = true;
  }
  return mus_stamu_theta_;
}

std::vector<float>* const & cfa_13::mus_stamu_vx() const{
  if(!c_mus_stamu_vx_ && b_mus_stamu_vx_){
    b_mus_stamu_vx_->GetEntry(entry_);
    c_mus_stamu_vx_ = true;
  }
  return mus_stamu_vx_;
}

std::vector<float>* const & cfa_13::mus_stamu_vy() const{
  if(!c_mus_stamu_vy_ && b_mus_stamu_vy_){
    b_mus_stamu_vy_->GetEntry(entry_);
    c_mus_stamu_vy_ = true;
  }
  return mus_stamu_vy_;
}

std::vector<float>* const & cfa_13::mus_stamu_vz() const{
  if(!c_mus_stamu_vz_ && b_mus_stamu_vz_){
    b_mus_stamu_vz_->GetEntry(entry_);
    c_mus_stamu_vz_ = true;
  }
  return mus_stamu_vz_;
}

std::vector<float>* const & cfa_13::mus_status() const{
  if(!c_mus_status_ && b_mus_status_){
    b_mus_status_->GetEntry(entry_);
    c_mus_status_ = true;
  }
  return mus_status_;
}

std::vector<float>* const & cfa_13::mus_tIso() const{
  if(!c_mus_tIso_ && b_mus_tIso_){
    b_mus_tIso_->GetEntry(entry_);
    c_mus_tIso_ = true;
  }
  return mus_tIso_;
}

std::vector<float>* const & cfa_13::mus_theta() const{
  if(!c_mus_theta_ && b_mus_theta_){
    b_mus_theta_->GetEntry(entry_);
    c_mus_theta_ = true;
  }
  return mus_theta_;
}

std::vector<float>* const & cfa_13::mus_tkHits() const{
  if(!c_mus_tkHits_ && b_mus_tkHits_){
    b_mus_tkHits_->GetEntry(entry_);
    c_mus_tkHits_ = true;
  }
  return mus_tkHits_;
}

std::vector<float>* const & cfa_13::mus_tk_ExpectedHitsInner() const{
  if(!c_mus_tk_ExpectedHitsInner_ && b_mus_tk_ExpectedHitsInner_){
    b_mus_tk_ExpectedHitsInner_->GetEntry(entry_);
    c_mus_tk_ExpectedHitsInner_ = true;
  }
  return mus_tk_ExpectedHitsInner_;
}

std::vector<float>* const & cfa_13::mus_tk_ExpectedHitsOuter() const{
  if(!c_mus_tk_ExpectedHitsOuter_ && b_mus_tk_ExpectedHitsOuter_){
    b_mus_tk_ExpectedHitsOuter_->GetEntry(entry_);
    c_mus_tk_ExpectedHitsOuter_ = true;
  }
  return mus_tk_ExpectedHitsOuter_;
}

std::vector<float>* const & cfa_13::mus_tk_LayersWithMeasurement() const{
  if(!c_mus_tk_LayersWithMeasurement_ && b_mus_tk_LayersWithMeasurement_){
    b_mus_tk_LayersWithMeasurement_->GetEntry(entry_);
    c_mus_tk_LayersWithMeasurement_ = true;
  }
  return mus_tk_LayersWithMeasurement_;
}

std::vector<float>* const & cfa_13::mus_tk_LayersWithoutMeasurement() const{
  if(!c_mus_tk_LayersWithoutMeasurement_ && b_mus_tk_LayersWithoutMeasurement_){
    b_mus_tk_LayersWithoutMeasurement_->GetEntry(entry_);
    c_mus_tk_LayersWithoutMeasurement_ = true;
  }
  return mus_tk_LayersWithoutMeasurement_;
}

std::vector<float>* const & cfa_13::mus_tk_PixelLayersWithMeasurement() const{
  if(!c_mus_tk_PixelLayersWithMeasurement_ && b_mus_tk_PixelLayersWithMeasurement_){
    b_mus_tk_PixelLayersWithMeasurement_->GetEntry(entry_);
    c_mus_tk_PixelLayersWithMeasurement_ = true;
  }
  return mus_tk_PixelLayersWithMeasurement_;
}

std::vector<float>* const & cfa_13::mus_tk_ValidStripLayersWithMonoAndStereoHit() const{
  if(!c_mus_tk_ValidStripLayersWithMonoAndStereoHit_ && b_mus_tk_ValidStripLayersWithMonoAndStereoHit_){
    b_mus_tk_ValidStripLayersWithMonoAndStereoHit_->GetEntry(entry_);
    c_mus_tk_ValidStripLayersWithMonoAndStereoHit_ = true;
  }
  return mus_tk_ValidStripLayersWithMonoAndStereoHit_;
}

std::vector<float>* const & cfa_13::mus_tk_chg() const{
  if(!c_mus_tk_chg_ && b_mus_tk_chg_){
    b_mus_tk_chg_->GetEntry(entry_);
    c_mus_tk_chg_ = true;
  }
  return mus_tk_chg_;
}

std::vector<float>* const & cfa_13::mus_tk_chi2() const{
  if(!c_mus_tk_chi2_ && b_mus_tk_chi2_){
    b_mus_tk_chi2_->GetEntry(entry_);
    c_mus_tk_chi2_ = true;
  }
  return mus_tk_chi2_;
}

std::vector<float>* const & cfa_13::mus_tk_d0dum() const{
  if(!c_mus_tk_d0dum_ && b_mus_tk_d0dum_){
    b_mus_tk_d0dum_->GetEntry(entry_);
    c_mus_tk_d0dum_ = true;
  }
  return mus_tk_d0dum_;
}

std::vector<float>* const & cfa_13::mus_tk_d0dumErr() const{
  if(!c_mus_tk_d0dumErr_ && b_mus_tk_d0dumErr_){
    b_mus_tk_d0dumErr_->GetEntry(entry_);
    c_mus_tk_d0dumErr_ = true;
  }
  return mus_tk_d0dumErr_;
}

std::vector<float>* const & cfa_13::mus_tk_dz() const{
  if(!c_mus_tk_dz_ && b_mus_tk_dz_){
    b_mus_tk_dz_->GetEntry(entry_);
    c_mus_tk_dz_ = true;
  }
  return mus_tk_dz_;
}

std::vector<float>* const & cfa_13::mus_tk_dzErr() const{
  if(!c_mus_tk_dzErr_ && b_mus_tk_dzErr_){
    b_mus_tk_dzErr_->GetEntry(entry_);
    c_mus_tk_dzErr_ = true;
  }
  return mus_tk_dzErr_;
}

std::vector<float>* const & cfa_13::mus_tk_eta() const{
  if(!c_mus_tk_eta_ && b_mus_tk_eta_){
    b_mus_tk_eta_->GetEntry(entry_);
    c_mus_tk_eta_ = true;
  }
  return mus_tk_eta_;
}

std::vector<float>* const & cfa_13::mus_tk_etaErr() const{
  if(!c_mus_tk_etaErr_ && b_mus_tk_etaErr_){
    b_mus_tk_etaErr_->GetEntry(entry_);
    c_mus_tk_etaErr_ = true;
  }
  return mus_tk_etaErr_;
}

std::vector<float>* const & cfa_13::mus_tk_id() const{
  if(!c_mus_tk_id_ && b_mus_tk_id_){
    b_mus_tk_id_->GetEntry(entry_);
    c_mus_tk_id_ = true;
  }
  return mus_tk_id_;
}

std::vector<float>* const & cfa_13::mus_tk_ndof() const{
  if(!c_mus_tk_ndof_ && b_mus_tk_ndof_){
    b_mus_tk_ndof_->GetEntry(entry_);
    c_mus_tk_ndof_ = true;
  }
  return mus_tk_ndof_;
}

std::vector<float>* const & cfa_13::mus_tk_numlosthits() const{
  if(!c_mus_tk_numlosthits_ && b_mus_tk_numlosthits_){
    b_mus_tk_numlosthits_->GetEntry(entry_);
    c_mus_tk_numlosthits_ = true;
  }
  return mus_tk_numlosthits_;
}

std::vector<float>* const & cfa_13::mus_tk_numpixelWthMeasr() const{
  if(!c_mus_tk_numpixelWthMeasr_ && b_mus_tk_numpixelWthMeasr_){
    b_mus_tk_numpixelWthMeasr_->GetEntry(entry_);
    c_mus_tk_numpixelWthMeasr_ = true;
  }
  return mus_tk_numpixelWthMeasr_;
}

std::vector<float>* const & cfa_13::mus_tk_numvalPixelhits() const{
  if(!c_mus_tk_numvalPixelhits_ && b_mus_tk_numvalPixelhits_){
    b_mus_tk_numvalPixelhits_->GetEntry(entry_);
    c_mus_tk_numvalPixelhits_ = true;
  }
  return mus_tk_numvalPixelhits_;
}

std::vector<float>* const & cfa_13::mus_tk_numvalhits() const{
  if(!c_mus_tk_numvalhits_ && b_mus_tk_numvalhits_){
    b_mus_tk_numvalhits_->GetEntry(entry_);
    c_mus_tk_numvalhits_ = true;
  }
  return mus_tk_numvalhits_;
}

std::vector<float>* const & cfa_13::mus_tk_phi() const{
  if(!c_mus_tk_phi_ && b_mus_tk_phi_){
    b_mus_tk_phi_->GetEntry(entry_);
    c_mus_tk_phi_ = true;
  }
  return mus_tk_phi_;
}

std::vector<float>* const & cfa_13::mus_tk_phiErr() const{
  if(!c_mus_tk_phiErr_ && b_mus_tk_phiErr_){
    b_mus_tk_phiErr_->GetEntry(entry_);
    c_mus_tk_phiErr_ = true;
  }
  return mus_tk_phiErr_;
}

std::vector<float>* const & cfa_13::mus_tk_pt() const{
  if(!c_mus_tk_pt_ && b_mus_tk_pt_){
    b_mus_tk_pt_->GetEntry(entry_);
    c_mus_tk_pt_ = true;
  }
  return mus_tk_pt_;
}

std::vector<float>* const & cfa_13::mus_tk_ptErr() const{
  if(!c_mus_tk_ptErr_ && b_mus_tk_ptErr_){
    b_mus_tk_ptErr_->GetEntry(entry_);
    c_mus_tk_ptErr_ = true;
  }
  return mus_tk_ptErr_;
}

std::vector<float>* const & cfa_13::mus_tk_px() const{
  if(!c_mus_tk_px_ && b_mus_tk_px_){
    b_mus_tk_px_->GetEntry(entry_);
    c_mus_tk_px_ = true;
  }
  return mus_tk_px_;
}

std::vector<float>* const & cfa_13::mus_tk_py() const{
  if(!c_mus_tk_py_ && b_mus_tk_py_){
    b_mus_tk_py_->GetEntry(entry_);
    c_mus_tk_py_ = true;
  }
  return mus_tk_py_;
}

std::vector<float>* const & cfa_13::mus_tk_pz() const{
  if(!c_mus_tk_pz_ && b_mus_tk_pz_){
    b_mus_tk_pz_->GetEntry(entry_);
    c_mus_tk_pz_ = true;
  }
  return mus_tk_pz_;
}

std::vector<float>* const & cfa_13::mus_tk_theta() const{
  if(!c_mus_tk_theta_ && b_mus_tk_theta_){
    b_mus_tk_theta_->GetEntry(entry_);
    c_mus_tk_theta_ = true;
  }
  return mus_tk_theta_;
}

std::vector<float>* const & cfa_13::mus_tk_vx() const{
  if(!c_mus_tk_vx_ && b_mus_tk_vx_){
    b_mus_tk_vx_->GetEntry(entry_);
    c_mus_tk_vx_ = true;
  }
  return mus_tk_vx_;
}

std::vector<float>* const & cfa_13::mus_tk_vy() const{
  if(!c_mus_tk_vy_ && b_mus_tk_vy_){
    b_mus_tk_vy_->GetEntry(entry_);
    c_mus_tk_vy_ = true;
  }
  return mus_tk_vy_;
}

std::vector<float>* const & cfa_13::mus_tk_vz() const{
  if(!c_mus_tk_vz_ && b_mus_tk_vz_){
    b_mus_tk_vz_->GetEntry(entry_);
    c_mus_tk_vz_ = true;
  }
  return mus_tk_vz_;
}

std::vector<float>* const & cfa_13::mus_tpfms_ExpectedHitsInner() const{
  if(!c_mus_tpfms_ExpectedHitsInner_ && b_mus_tpfms_ExpectedHitsInner_){
    b_mus_tpfms_ExpectedHitsInner_->GetEntry(entry_);
    c_mus_tpfms_ExpectedHitsInner_ = true;
  }
  return mus_tpfms_ExpectedHitsInner_;
}

std::vector<float>* const & cfa_13::mus_tpfms_ExpectedHitsOuter() const{
  if(!c_mus_tpfms_ExpectedHitsOuter_ && b_mus_tpfms_ExpectedHitsOuter_){
    b_mus_tpfms_ExpectedHitsOuter_->GetEntry(entry_);
    c_mus_tpfms_ExpectedHitsOuter_ = true;
  }
  return mus_tpfms_ExpectedHitsOuter_;
}

std::vector<float>* const & cfa_13::mus_tpfms_LayersWithMeasurement() const{
  if(!c_mus_tpfms_LayersWithMeasurement_ && b_mus_tpfms_LayersWithMeasurement_){
    b_mus_tpfms_LayersWithMeasurement_->GetEntry(entry_);
    c_mus_tpfms_LayersWithMeasurement_ = true;
  }
  return mus_tpfms_LayersWithMeasurement_;
}

std::vector<float>* const & cfa_13::mus_tpfms_LayersWithoutMeasurement() const{
  if(!c_mus_tpfms_LayersWithoutMeasurement_ && b_mus_tpfms_LayersWithoutMeasurement_){
    b_mus_tpfms_LayersWithoutMeasurement_->GetEntry(entry_);
    c_mus_tpfms_LayersWithoutMeasurement_ = true;
  }
  return mus_tpfms_LayersWithoutMeasurement_;
}

std::vector<float>* const & cfa_13::mus_tpfms_PixelLayersWithMeasurement() const{
  if(!c_mus_tpfms_PixelLayersWithMeasurement_ && b_mus_tpfms_PixelLayersWithMeasurement_){
    b_mus_tpfms_PixelLayersWithMeasurement_->GetEntry(entry_);
    c_mus_tpfms_PixelLayersWithMeasurement_ = true;
  }
  return mus_tpfms_PixelLayersWithMeasurement_;
}

std::vector<float>* const & cfa_13::mus_tpfms_ValidStripLayersWithMonoAndStereoHit() const{
  if(!c_mus_tpfms_ValidStripLayersWithMonoAndStereoHit_ && b_mus_tpfms_ValidStripLayersWithMonoAndStereoHit_){
    b_mus_tpfms_ValidStripLayersWithMonoAndStereoHit_->GetEntry(entry_);
    c_mus_tpfms_ValidStripLayersWithMonoAndStereoHit_ = true;
  }
  return mus_tpfms_ValidStripLayersWithMonoAndStereoHit_;
}

std::vector<float>* const & cfa_13::mus_tpfms_chg() const{
  if(!c_mus_tpfms_chg_ && b_mus_tpfms_chg_){
    b_mus_tpfms_chg_->GetEntry(entry_);
    c_mus_tpfms_chg_ = true;
  }
  return mus_tpfms_chg_;
}

std::vector<float>* const & cfa_13::mus_tpfms_chi2() const{
  if(!c_mus_tpfms_chi2_ && b_mus_tpfms_chi2_){
    b_mus_tpfms_chi2_->GetEntry(entry_);
    c_mus_tpfms_chi2_ = true;
  }
  return mus_tpfms_chi2_;
}

std::vector<float>* const & cfa_13::mus_tpfms_d0dum() const{
  if(!c_mus_tpfms_d0dum_ && b_mus_tpfms_d0dum_){
    b_mus_tpfms_d0dum_->GetEntry(entry_);
    c_mus_tpfms_d0dum_ = true;
  }
  return mus_tpfms_d0dum_;
}

std::vector<float>* const & cfa_13::mus_tpfms_d0dumErr() const{
  if(!c_mus_tpfms_d0dumErr_ && b_mus_tpfms_d0dumErr_){
    b_mus_tpfms_d0dumErr_->GetEntry(entry_);
    c_mus_tpfms_d0dumErr_ = true;
  }
  return mus_tpfms_d0dumErr_;
}

std::vector<float>* const & cfa_13::mus_tpfms_dz() const{
  if(!c_mus_tpfms_dz_ && b_mus_tpfms_dz_){
    b_mus_tpfms_dz_->GetEntry(entry_);
    c_mus_tpfms_dz_ = true;
  }
  return mus_tpfms_dz_;
}

std::vector<float>* const & cfa_13::mus_tpfms_dzErr() const{
  if(!c_mus_tpfms_dzErr_ && b_mus_tpfms_dzErr_){
    b_mus_tpfms_dzErr_->GetEntry(entry_);
    c_mus_tpfms_dzErr_ = true;
  }
  return mus_tpfms_dzErr_;
}

std::vector<float>* const & cfa_13::mus_tpfms_eta() const{
  if(!c_mus_tpfms_eta_ && b_mus_tpfms_eta_){
    b_mus_tpfms_eta_->GetEntry(entry_);
    c_mus_tpfms_eta_ = true;
  }
  return mus_tpfms_eta_;
}

std::vector<float>* const & cfa_13::mus_tpfms_etaErr() const{
  if(!c_mus_tpfms_etaErr_ && b_mus_tpfms_etaErr_){
    b_mus_tpfms_etaErr_->GetEntry(entry_);
    c_mus_tpfms_etaErr_ = true;
  }
  return mus_tpfms_etaErr_;
}

std::vector<float>* const & cfa_13::mus_tpfms_id() const{
  if(!c_mus_tpfms_id_ && b_mus_tpfms_id_){
    b_mus_tpfms_id_->GetEntry(entry_);
    c_mus_tpfms_id_ = true;
  }
  return mus_tpfms_id_;
}

std::vector<float>* const & cfa_13::mus_tpfms_ndof() const{
  if(!c_mus_tpfms_ndof_ && b_mus_tpfms_ndof_){
    b_mus_tpfms_ndof_->GetEntry(entry_);
    c_mus_tpfms_ndof_ = true;
  }
  return mus_tpfms_ndof_;
}

std::vector<float>* const & cfa_13::mus_tpfms_numlosthits() const{
  if(!c_mus_tpfms_numlosthits_ && b_mus_tpfms_numlosthits_){
    b_mus_tpfms_numlosthits_->GetEntry(entry_);
    c_mus_tpfms_numlosthits_ = true;
  }
  return mus_tpfms_numlosthits_;
}

std::vector<float>* const & cfa_13::mus_tpfms_numvalPixelhits() const{
  if(!c_mus_tpfms_numvalPixelhits_ && b_mus_tpfms_numvalPixelhits_){
    b_mus_tpfms_numvalPixelhits_->GetEntry(entry_);
    c_mus_tpfms_numvalPixelhits_ = true;
  }
  return mus_tpfms_numvalPixelhits_;
}

std::vector<float>* const & cfa_13::mus_tpfms_numvalhits() const{
  if(!c_mus_tpfms_numvalhits_ && b_mus_tpfms_numvalhits_){
    b_mus_tpfms_numvalhits_->GetEntry(entry_);
    c_mus_tpfms_numvalhits_ = true;
  }
  return mus_tpfms_numvalhits_;
}

std::vector<float>* const & cfa_13::mus_tpfms_phi() const{
  if(!c_mus_tpfms_phi_ && b_mus_tpfms_phi_){
    b_mus_tpfms_phi_->GetEntry(entry_);
    c_mus_tpfms_phi_ = true;
  }
  return mus_tpfms_phi_;
}

std::vector<float>* const & cfa_13::mus_tpfms_phiErr() const{
  if(!c_mus_tpfms_phiErr_ && b_mus_tpfms_phiErr_){
    b_mus_tpfms_phiErr_->GetEntry(entry_);
    c_mus_tpfms_phiErr_ = true;
  }
  return mus_tpfms_phiErr_;
}

std::vector<float>* const & cfa_13::mus_tpfms_pt() const{
  if(!c_mus_tpfms_pt_ && b_mus_tpfms_pt_){
    b_mus_tpfms_pt_->GetEntry(entry_);
    c_mus_tpfms_pt_ = true;
  }
  return mus_tpfms_pt_;
}

std::vector<float>* const & cfa_13::mus_tpfms_ptErr() const{
  if(!c_mus_tpfms_ptErr_ && b_mus_tpfms_ptErr_){
    b_mus_tpfms_ptErr_->GetEntry(entry_);
    c_mus_tpfms_ptErr_ = true;
  }
  return mus_tpfms_ptErr_;
}

std::vector<float>* const & cfa_13::mus_tpfms_px() const{
  if(!c_mus_tpfms_px_ && b_mus_tpfms_px_){
    b_mus_tpfms_px_->GetEntry(entry_);
    c_mus_tpfms_px_ = true;
  }
  return mus_tpfms_px_;
}

std::vector<float>* const & cfa_13::mus_tpfms_py() const{
  if(!c_mus_tpfms_py_ && b_mus_tpfms_py_){
    b_mus_tpfms_py_->GetEntry(entry_);
    c_mus_tpfms_py_ = true;
  }
  return mus_tpfms_py_;
}

std::vector<float>* const & cfa_13::mus_tpfms_pz() const{
  if(!c_mus_tpfms_pz_ && b_mus_tpfms_pz_){
    b_mus_tpfms_pz_->GetEntry(entry_);
    c_mus_tpfms_pz_ = true;
  }
  return mus_tpfms_pz_;
}

std::vector<float>* const & cfa_13::mus_tpfms_theta() const{
  if(!c_mus_tpfms_theta_ && b_mus_tpfms_theta_){
    b_mus_tpfms_theta_->GetEntry(entry_);
    c_mus_tpfms_theta_ = true;
  }
  return mus_tpfms_theta_;
}

std::vector<float>* const & cfa_13::mus_tpfms_vx() const{
  if(!c_mus_tpfms_vx_ && b_mus_tpfms_vx_){
    b_mus_tpfms_vx_->GetEntry(entry_);
    c_mus_tpfms_vx_ = true;
  }
  return mus_tpfms_vx_;
}

std::vector<float>* const & cfa_13::mus_tpfms_vy() const{
  if(!c_mus_tpfms_vy_ && b_mus_tpfms_vy_){
    b_mus_tpfms_vy_->GetEntry(entry_);
    c_mus_tpfms_vy_ = true;
  }
  return mus_tpfms_vy_;
}

std::vector<float>* const & cfa_13::mus_tpfms_vz() const{
  if(!c_mus_tpfms_vz_ && b_mus_tpfms_vz_){
    b_mus_tpfms_vz_->GetEntry(entry_);
    c_mus_tpfms_vz_ = true;
  }
  return mus_tpfms_vz_;
}

UInt_t const & cfa_13::orbitNumber() const{
  if(!c_orbitNumber_ && b_orbitNumber_){
    b_orbitNumber_->GetEntry(entry_);
    c_orbitNumber_ = true;
  }
  return orbitNumber_;
}

std::vector<float>* const & cfa_13::pfcand_charge() const{
  if(!c_pfcand_charge_ && b_pfcand_charge_){
    b_pfcand_charge_->GetEntry(entry_);
    c_pfcand_charge_ = true;
  }
  return pfcand_charge_;
}

std::vector<float>* const & cfa_13::pfcand_energy() const{
  if(!c_pfcand_energy_ && b_pfcand_energy_){
    b_pfcand_energy_->GetEntry(entry_);
    c_pfcand_energy_ = true;
  }
  return pfcand_energy_;
}

std::vector<float>* const & cfa_13::pfcand_eta() const{
  if(!c_pfcand_eta_ && b_pfcand_eta_){
    b_pfcand_eta_->GetEntry(entry_);
    c_pfcand_eta_ = true;
  }
  return pfcand_eta_;
}

std::vector<float>* const & cfa_13::pfcand_pdgId() const{
  if(!c_pfcand_pdgId_ && b_pfcand_pdgId_){
    b_pfcand_pdgId_->GetEntry(entry_);
    c_pfcand_pdgId_ = true;
  }
  return pfcand_pdgId_;
}

std::vector<float>* const & cfa_13::pfcand_phi() const{
  if(!c_pfcand_phi_ && b_pfcand_phi_){
    b_pfcand_phi_->GetEntry(entry_);
    c_pfcand_phi_ = true;
  }
  return pfcand_phi_;
}

std::vector<float>* const & cfa_13::pfcand_pt() const{
  if(!c_pfcand_pt_ && b_pfcand_pt_){
    b_pfcand_pt_->GetEntry(entry_);
    c_pfcand_pt_ = true;
  }
  return pfcand_pt_;
}

std::vector<float>* const & cfa_13::pfcand_px() const{
  if(!c_pfcand_px_ && b_pfcand_px_){
    b_pfcand_px_->GetEntry(entry_);
    c_pfcand_px_ = true;
  }
  return pfcand_px_;
}

std::vector<float>* const & cfa_13::pfcand_py() const{
  if(!c_pfcand_py_ && b_pfcand_py_){
    b_pfcand_py_->GetEntry(entry_);
    c_pfcand_py_ = true;
  }
  return pfcand_py_;
}

std::vector<float>* const & cfa_13::pfcand_pz() const{
  if(!c_pfcand_pz_ && b_pfcand_pz_){
    b_pfcand_pz_->GetEntry(entry_);
    c_pfcand_pz_ = true;
  }
  return pfcand_pz_;
}

std::vector<float>* const & cfa_13::pfcand_theta() const{
  if(!c_pfcand_theta_ && b_pfcand_theta_){
    b_pfcand_theta_->GetEntry(entry_);
    c_pfcand_theta_ = true;
  }
  return pfcand_theta_;
}

std::vector<float>* const & cfa_13::photons_e1x5() const{
  if(!c_photons_e1x5_ && b_photons_e1x5_){
    b_photons_e1x5_->GetEntry(entry_);
    c_photons_e1x5_ = true;
  }
  return photons_e1x5_;
}

std::vector<float>* const & cfa_13::photons_e2x5() const{
  if(!c_photons_e2x5_ && b_photons_e2x5_){
    b_photons_e2x5_->GetEntry(entry_);
    c_photons_e2x5_ = true;
  }
  return photons_e2x5_;
}

std::vector<float>* const & cfa_13::photons_e3x3() const{
  if(!c_photons_e3x3_ && b_photons_e3x3_){
    b_photons_e3x3_->GetEntry(entry_);
    c_photons_e3x3_ = true;
  }
  return photons_e3x3_;
}

std::vector<float>* const & cfa_13::photons_e5x5() const{
  if(!c_photons_e5x5_ && b_photons_e5x5_){
    b_photons_e5x5_->GetEntry(entry_);
    c_photons_e5x5_ = true;
  }
  return photons_e5x5_;
}

std::vector<float>* const & cfa_13::photons_ecalIso() const{
  if(!c_photons_ecalIso_ && b_photons_ecalIso_){
    b_photons_ecalIso_->GetEntry(entry_);
    c_photons_ecalIso_ = true;
  }
  return photons_ecalIso_;
}

std::vector<float>* const & cfa_13::photons_energy() const{
  if(!c_photons_energy_ && b_photons_energy_){
    b_photons_energy_->GetEntry(entry_);
    c_photons_energy_ = true;
  }
  return photons_energy_;
}

std::vector<float>* const & cfa_13::photons_et() const{
  if(!c_photons_et_ && b_photons_et_){
    b_photons_et_->GetEntry(entry_);
    c_photons_et_ = true;
  }
  return photons_et_;
}

std::vector<float>* const & cfa_13::photons_eta() const{
  if(!c_photons_eta_ && b_photons_eta_){
    b_photons_eta_->GetEntry(entry_);
    c_photons_eta_ = true;
  }
  return photons_eta_;
}

std::vector<float>* const & cfa_13::photons_gen_et() const{
  if(!c_photons_gen_et_ && b_photons_gen_et_){
    b_photons_gen_et_->GetEntry(entry_);
    c_photons_gen_et_ = true;
  }
  return photons_gen_et_;
}

std::vector<float>* const & cfa_13::photons_gen_eta() const{
  if(!c_photons_gen_eta_ && b_photons_gen_eta_){
    b_photons_gen_eta_->GetEntry(entry_);
    c_photons_gen_eta_ = true;
  }
  return photons_gen_eta_;
}

std::vector<float>* const & cfa_13::photons_gen_id() const{
  if(!c_photons_gen_id_ && b_photons_gen_id_){
    b_photons_gen_id_->GetEntry(entry_);
    c_photons_gen_id_ = true;
  }
  return photons_gen_id_;
}

std::vector<float>* const & cfa_13::photons_gen_phi() const{
  if(!c_photons_gen_phi_ && b_photons_gen_phi_){
    b_photons_gen_phi_->GetEntry(entry_);
    c_photons_gen_phi_ = true;
  }
  return photons_gen_phi_;
}

std::vector<float>* const & cfa_13::photons_hadOverEM() const{
  if(!c_photons_hadOverEM_ && b_photons_hadOverEM_){
    b_photons_hadOverEM_->GetEntry(entry_);
    c_photons_hadOverEM_ = true;
  }
  return photons_hadOverEM_;
}

std::vector<float>* const & cfa_13::photons_hadTowOverEM() const{
  if(!c_photons_hadTowOverEM_ && b_photons_hadTowOverEM_){
    b_photons_hadTowOverEM_->GetEntry(entry_);
    c_photons_hadTowOverEM_ = true;
  }
  return photons_hadTowOverEM_;
}

std::vector<float>* const & cfa_13::photons_hasPixelSeed() const{
  if(!c_photons_hasPixelSeed_ && b_photons_hasPixelSeed_){
    b_photons_hasPixelSeed_->GetEntry(entry_);
    c_photons_hasPixelSeed_ = true;
  }
  return photons_hasPixelSeed_;
}

std::vector<float>* const & cfa_13::photons_hcalIso() const{
  if(!c_photons_hcalIso_ && b_photons_hcalIso_){
    b_photons_hcalIso_->GetEntry(entry_);
    c_photons_hcalIso_ = true;
  }
  return photons_hcalIso_;
}

std::vector<float>* const & cfa_13::photons_isAlsoElectron() const{
  if(!c_photons_isAlsoElectron_ && b_photons_isAlsoElectron_){
    b_photons_isAlsoElectron_->GetEntry(entry_);
    c_photons_isAlsoElectron_ = true;
  }
  return photons_isAlsoElectron_;
}

std::vector<float>* const & cfa_13::photons_isConverted() const{
  if(!c_photons_isConverted_ && b_photons_isConverted_){
    b_photons_isConverted_->GetEntry(entry_);
    c_photons_isConverted_ = true;
  }
  return photons_isConverted_;
}

std::vector<float>* const & cfa_13::photons_isEBEEGap() const{
  if(!c_photons_isEBEEGap_ && b_photons_isEBEEGap_){
    b_photons_isEBEEGap_->GetEntry(entry_);
    c_photons_isEBEEGap_ = true;
  }
  return photons_isEBEEGap_;
}

std::vector<float>* const & cfa_13::photons_isEBGap() const{
  if(!c_photons_isEBGap_ && b_photons_isEBGap_){
    b_photons_isEBGap_->GetEntry(entry_);
    c_photons_isEBGap_ = true;
  }
  return photons_isEBGap_;
}

std::vector<float>* const & cfa_13::photons_isEBPho() const{
  if(!c_photons_isEBPho_ && b_photons_isEBPho_){
    b_photons_isEBPho_->GetEntry(entry_);
    c_photons_isEBPho_ = true;
  }
  return photons_isEBPho_;
}

std::vector<float>* const & cfa_13::photons_isEEGap() const{
  if(!c_photons_isEEGap_ && b_photons_isEEGap_){
    b_photons_isEEGap_->GetEntry(entry_);
    c_photons_isEEGap_ = true;
  }
  return photons_isEEGap_;
}

std::vector<float>* const & cfa_13::photons_isEEPho() const{
  if(!c_photons_isEEPho_ && b_photons_isEEPho_){
    b_photons_isEEPho_->GetEntry(entry_);
    c_photons_isEEPho_ = true;
  }
  return photons_isEEPho_;
}

std::vector<float>* const & cfa_13::photons_isLoosePhoton() const{
  if(!c_photons_isLoosePhoton_ && b_photons_isLoosePhoton_){
    b_photons_isLoosePhoton_->GetEntry(entry_);
    c_photons_isLoosePhoton_ = true;
  }
  return photons_isLoosePhoton_;
}

std::vector<float>* const & cfa_13::photons_isTightPhoton() const{
  if(!c_photons_isTightPhoton_ && b_photons_isTightPhoton_){
    b_photons_isTightPhoton_->GetEntry(entry_);
    c_photons_isTightPhoton_ = true;
  }
  return photons_isTightPhoton_;
}

std::vector<float>* const & cfa_13::photons_isoEcalRecHitDR03() const{
  if(!c_photons_isoEcalRecHitDR03_ && b_photons_isoEcalRecHitDR03_){
    b_photons_isoEcalRecHitDR03_->GetEntry(entry_);
    c_photons_isoEcalRecHitDR03_ = true;
  }
  return photons_isoEcalRecHitDR03_;
}

std::vector<float>* const & cfa_13::photons_isoEcalRecHitDR04() const{
  if(!c_photons_isoEcalRecHitDR04_ && b_photons_isoEcalRecHitDR04_){
    b_photons_isoEcalRecHitDR04_->GetEntry(entry_);
    c_photons_isoEcalRecHitDR04_ = true;
  }
  return photons_isoEcalRecHitDR04_;
}

std::vector<float>* const & cfa_13::photons_isoHcalRecHitDR03() const{
  if(!c_photons_isoHcalRecHitDR03_ && b_photons_isoHcalRecHitDR03_){
    b_photons_isoHcalRecHitDR03_->GetEntry(entry_);
    c_photons_isoHcalRecHitDR03_ = true;
  }
  return photons_isoHcalRecHitDR03_;
}

std::vector<float>* const & cfa_13::photons_isoHcalRecHitDR04() const{
  if(!c_photons_isoHcalRecHitDR04_ && b_photons_isoHcalRecHitDR04_){
    b_photons_isoHcalRecHitDR04_->GetEntry(entry_);
    c_photons_isoHcalRecHitDR04_ = true;
  }
  return photons_isoHcalRecHitDR04_;
}

std::vector<float>* const & cfa_13::photons_isoHollowTrkConeDR03() const{
  if(!c_photons_isoHollowTrkConeDR03_ && b_photons_isoHollowTrkConeDR03_){
    b_photons_isoHollowTrkConeDR03_->GetEntry(entry_);
    c_photons_isoHollowTrkConeDR03_ = true;
  }
  return photons_isoHollowTrkConeDR03_;
}

std::vector<float>* const & cfa_13::photons_isoHollowTrkConeDR04() const{
  if(!c_photons_isoHollowTrkConeDR04_ && b_photons_isoHollowTrkConeDR04_){
    b_photons_isoHollowTrkConeDR04_->GetEntry(entry_);
    c_photons_isoHollowTrkConeDR04_ = true;
  }
  return photons_isoHollowTrkConeDR04_;
}

std::vector<float>* const & cfa_13::photons_isoSolidTrkConeDR03() const{
  if(!c_photons_isoSolidTrkConeDR03_ && b_photons_isoSolidTrkConeDR03_){
    b_photons_isoSolidTrkConeDR03_->GetEntry(entry_);
    c_photons_isoSolidTrkConeDR03_ = true;
  }
  return photons_isoSolidTrkConeDR03_;
}

std::vector<float>* const & cfa_13::photons_isoSolidTrkConeDR04() const{
  if(!c_photons_isoSolidTrkConeDR04_ && b_photons_isoSolidTrkConeDR04_){
    b_photons_isoSolidTrkConeDR04_->GetEntry(entry_);
    c_photons_isoSolidTrkConeDR04_ = true;
  }
  return photons_isoSolidTrkConeDR04_;
}

std::vector<float>* const & cfa_13::photons_maxEnergyXtal() const{
  if(!c_photons_maxEnergyXtal_ && b_photons_maxEnergyXtal_){
    b_photons_maxEnergyXtal_->GetEntry(entry_);
    c_photons_maxEnergyXtal_ = true;
  }
  return photons_maxEnergyXtal_;
}

std::vector<float>* const & cfa_13::photons_nTrkHollowConeDR03() const{
  if(!c_photons_nTrkHollowConeDR03_ && b_photons_nTrkHollowConeDR03_){
    b_photons_nTrkHollowConeDR03_->GetEntry(entry_);
    c_photons_nTrkHollowConeDR03_ = true;
  }
  return photons_nTrkHollowConeDR03_;
}

std::vector<float>* const & cfa_13::photons_nTrkHollowConeDR04() const{
  if(!c_photons_nTrkHollowConeDR04_ && b_photons_nTrkHollowConeDR04_){
    b_photons_nTrkHollowConeDR04_->GetEntry(entry_);
    c_photons_nTrkHollowConeDR04_ = true;
  }
  return photons_nTrkHollowConeDR04_;
}

std::vector<float>* const & cfa_13::photons_nTrkSolidConeDR03() const{
  if(!c_photons_nTrkSolidConeDR03_ && b_photons_nTrkSolidConeDR03_){
    b_photons_nTrkSolidConeDR03_->GetEntry(entry_);
    c_photons_nTrkSolidConeDR03_ = true;
  }
  return photons_nTrkSolidConeDR03_;
}

std::vector<float>* const & cfa_13::photons_nTrkSolidConeDR04() const{
  if(!c_photons_nTrkSolidConeDR04_ && b_photons_nTrkSolidConeDR04_){
    b_photons_nTrkSolidConeDR04_->GetEntry(entry_);
    c_photons_nTrkSolidConeDR04_ = true;
  }
  return photons_nTrkSolidConeDR04_;
}

std::vector<float>* const & cfa_13::photons_phi() const{
  if(!c_photons_phi_ && b_photons_phi_){
    b_photons_phi_->GetEntry(entry_);
    c_photons_phi_ = true;
  }
  return photons_phi_;
}

std::vector<float>* const & cfa_13::photons_pt() const{
  if(!c_photons_pt_ && b_photons_pt_){
    b_photons_pt_->GetEntry(entry_);
    c_photons_pt_ = true;
  }
  return photons_pt_;
}

std::vector<float>* const & cfa_13::photons_px() const{
  if(!c_photons_px_ && b_photons_px_){
    b_photons_px_->GetEntry(entry_);
    c_photons_px_ = true;
  }
  return photons_px_;
}

std::vector<float>* const & cfa_13::photons_py() const{
  if(!c_photons_py_ && b_photons_py_){
    b_photons_py_->GetEntry(entry_);
    c_photons_py_ = true;
  }
  return photons_py_;
}

std::vector<float>* const & cfa_13::photons_pz() const{
  if(!c_photons_pz_ && b_photons_pz_){
    b_photons_pz_->GetEntry(entry_);
    c_photons_pz_ = true;
  }
  return photons_pz_;
}

std::vector<float>* const & cfa_13::photons_r9() const{
  if(!c_photons_r9_ && b_photons_r9_){
    b_photons_r9_->GetEntry(entry_);
    c_photons_r9_ = true;
  }
  return photons_r9_;
}

std::vector<float>* const & cfa_13::photons_scEnergy() const{
  if(!c_photons_scEnergy_ && b_photons_scEnergy_){
    b_photons_scEnergy_->GetEntry(entry_);
    c_photons_scEnergy_ = true;
  }
  return photons_scEnergy_;
}

std::vector<float>* const & cfa_13::photons_scEta() const{
  if(!c_photons_scEta_ && b_photons_scEta_){
    b_photons_scEta_->GetEntry(entry_);
    c_photons_scEta_ = true;
  }
  return photons_scEta_;
}

std::vector<float>* const & cfa_13::photons_scEtaWidth() const{
  if(!c_photons_scEtaWidth_ && b_photons_scEtaWidth_){
    b_photons_scEtaWidth_->GetEntry(entry_);
    c_photons_scEtaWidth_ = true;
  }
  return photons_scEtaWidth_;
}

std::vector<float>* const & cfa_13::photons_scPhi() const{
  if(!c_photons_scPhi_ && b_photons_scPhi_){
    b_photons_scPhi_->GetEntry(entry_);
    c_photons_scPhi_ = true;
  }
  return photons_scPhi_;
}

std::vector<float>* const & cfa_13::photons_scPhiWidth() const{
  if(!c_photons_scPhiWidth_ && b_photons_scPhiWidth_){
    b_photons_scPhiWidth_->GetEntry(entry_);
    c_photons_scPhiWidth_ = true;
  }
  return photons_scPhiWidth_;
}

std::vector<float>* const & cfa_13::photons_scRawEnergy() const{
  if(!c_photons_scRawEnergy_ && b_photons_scRawEnergy_){
    b_photons_scRawEnergy_->GetEntry(entry_);
    c_photons_scRawEnergy_ = true;
  }
  return photons_scRawEnergy_;
}

std::vector<float>* const & cfa_13::photons_sigmaEtaEta() const{
  if(!c_photons_sigmaEtaEta_ && b_photons_sigmaEtaEta_){
    b_photons_sigmaEtaEta_->GetEntry(entry_);
    c_photons_sigmaEtaEta_ = true;
  }
  return photons_sigmaEtaEta_;
}

std::vector<float>* const & cfa_13::photons_sigmaIetaIeta() const{
  if(!c_photons_sigmaIetaIeta_ && b_photons_sigmaIetaIeta_){
    b_photons_sigmaIetaIeta_->GetEntry(entry_);
    c_photons_sigmaIetaIeta_ = true;
  }
  return photons_sigmaIetaIeta_;
}

std::vector<float>* const & cfa_13::photons_status() const{
  if(!c_photons_status_ && b_photons_status_){
    b_photons_status_->GetEntry(entry_);
    c_photons_status_ = true;
  }
  return photons_status_;
}

std::vector<float>* const & cfa_13::photons_tIso() const{
  if(!c_photons_tIso_ && b_photons_tIso_){
    b_photons_tIso_->GetEntry(entry_);
    c_photons_tIso_ = true;
  }
  return photons_tIso_;
}

std::vector<float>* const & cfa_13::photons_theta() const{
  if(!c_photons_theta_ && b_photons_theta_){
    b_photons_theta_->GetEntry(entry_);
    c_photons_theta_ = true;
  }
  return photons_theta_;
}

std::vector<float>* const & cfa_13::pv_chi2() const{
  if(!c_pv_chi2_ && b_pv_chi2_){
    b_pv_chi2_->GetEntry(entry_);
    c_pv_chi2_ = true;
  }
  return pv_chi2_;
}

std::vector<float>* const & cfa_13::pv_isFake() const{
  if(!c_pv_isFake_ && b_pv_isFake_){
    b_pv_isFake_->GetEntry(entry_);
    c_pv_isFake_ = true;
  }
  return pv_isFake_;
}

std::vector<float>* const & cfa_13::pv_isValid() const{
  if(!c_pv_isValid_ && b_pv_isValid_){
    b_pv_isValid_->GetEntry(entry_);
    c_pv_isValid_ = true;
  }
  return pv_isValid_;
}

std::vector<float>* const & cfa_13::pv_ndof() const{
  if(!c_pv_ndof_ && b_pv_ndof_){
    b_pv_ndof_->GetEntry(entry_);
    c_pv_ndof_ = true;
  }
  return pv_ndof_;
}

std::vector<float>* const & cfa_13::pv_tracksSize() const{
  if(!c_pv_tracksSize_ && b_pv_tracksSize_){
    b_pv_tracksSize_->GetEntry(entry_);
    c_pv_tracksSize_ = true;
  }
  return pv_tracksSize_;
}

std::vector<float>* const & cfa_13::pv_x() const{
  if(!c_pv_x_ && b_pv_x_){
    b_pv_x_->GetEntry(entry_);
    c_pv_x_ = true;
  }
  return pv_x_;
}

std::vector<float>* const & cfa_13::pv_xErr() const{
  if(!c_pv_xErr_ && b_pv_xErr_){
    b_pv_xErr_->GetEntry(entry_);
    c_pv_xErr_ = true;
  }
  return pv_xErr_;
}

std::vector<float>* const & cfa_13::pv_y() const{
  if(!c_pv_y_ && b_pv_y_){
    b_pv_y_->GetEntry(entry_);
    c_pv_y_ = true;
  }
  return pv_y_;
}

std::vector<float>* const & cfa_13::pv_yErr() const{
  if(!c_pv_yErr_ && b_pv_yErr_){
    b_pv_yErr_->GetEntry(entry_);
    c_pv_yErr_ = true;
  }
  return pv_yErr_;
}

std::vector<float>* const & cfa_13::pv_z() const{
  if(!c_pv_z_ && b_pv_z_){
    b_pv_z_->GetEntry(entry_);
    c_pv_z_ = true;
  }
  return pv_z_;
}

std::vector<float>* const & cfa_13::pv_zErr() const{
  if(!c_pv_zErr_ && b_pv_zErr_){
    b_pv_zErr_->GetEntry(entry_);
    c_pv_zErr_ = true;
  }
  return pv_zErr_;
}

UInt_t const & cfa_13::run() const{
  if(!c_run_ && b_run_){
    b_run_->GetEntry(entry_);
    c_run_ = true;
  }
  return run_;
}

std::vector<std::string>* const & cfa_13::standalone_triggerobject_collectionname() const{
  if(!c_standalone_triggerobject_collectionname_ && b_standalone_triggerobject_collectionname_){
    b_standalone_triggerobject_collectionname_->GetEntry(entry_);
    c_standalone_triggerobject_collectionname_ = true;
  }
  return standalone_triggerobject_collectionname_;
}

std::vector<float>* const & cfa_13::standalone_triggerobject_energy() const{
  if(!c_standalone_triggerobject_energy_ && b_standalone_triggerobject_energy_){
    b_standalone_triggerobject_energy_->GetEntry(entry_);
    c_standalone_triggerobject_energy_ = true;
  }
  return standalone_triggerobject_energy_;
}

std::vector<float>* const & cfa_13::standalone_triggerobject_et() const{
  if(!c_standalone_triggerobject_et_ && b_standalone_triggerobject_et_){
    b_standalone_triggerobject_et_->GetEntry(entry_);
    c_standalone_triggerobject_et_ = true;
  }
  return standalone_triggerobject_et_;
}

std::vector<float>* const & cfa_13::standalone_triggerobject_eta() const{
  if(!c_standalone_triggerobject_eta_ && b_standalone_triggerobject_eta_){
    b_standalone_triggerobject_eta_->GetEntry(entry_);
    c_standalone_triggerobject_eta_ = true;
  }
  return standalone_triggerobject_eta_;
}

std::vector<float>* const & cfa_13::standalone_triggerobject_phi() const{
  if(!c_standalone_triggerobject_phi_ && b_standalone_triggerobject_phi_){
    b_standalone_triggerobject_phi_->GetEntry(entry_);
    c_standalone_triggerobject_phi_ = true;
  }
  return standalone_triggerobject_phi_;
}

std::vector<float>* const & cfa_13::standalone_triggerobject_pt() const{
  if(!c_standalone_triggerobject_pt_ && b_standalone_triggerobject_pt_){
    b_standalone_triggerobject_pt_->GetEntry(entry_);
    c_standalone_triggerobject_pt_ = true;
  }
  return standalone_triggerobject_pt_;
}

std::vector<float>* const & cfa_13::standalone_triggerobject_px() const{
  if(!c_standalone_triggerobject_px_ && b_standalone_triggerobject_px_){
    b_standalone_triggerobject_px_->GetEntry(entry_);
    c_standalone_triggerobject_px_ = true;
  }
  return standalone_triggerobject_px_;
}

std::vector<float>* const & cfa_13::standalone_triggerobject_py() const{
  if(!c_standalone_triggerobject_py_ && b_standalone_triggerobject_py_){
    b_standalone_triggerobject_py_->GetEntry(entry_);
    c_standalone_triggerobject_py_ = true;
  }
  return standalone_triggerobject_py_;
}

std::vector<float>* const & cfa_13::standalone_triggerobject_pz() const{
  if(!c_standalone_triggerobject_pz_ && b_standalone_triggerobject_pz_){
    b_standalone_triggerobject_pz_->GetEntry(entry_);
    c_standalone_triggerobject_pz_ = true;
  }
  return standalone_triggerobject_pz_;
}

std::vector<float>* const & cfa_13::taus_Nprongs() const{
  if(!c_taus_Nprongs_ && b_taus_Nprongs_){
    b_taus_Nprongs_->GetEntry(entry_);
    c_taus_Nprongs_ = true;
  }
  return taus_Nprongs_;
}

std::vector<float>* const & cfa_13::taus_againstElectron() const{
  if(!c_taus_againstElectron_ && b_taus_againstElectron_){
    b_taus_againstElectron_->GetEntry(entry_);
    c_taus_againstElectron_ = true;
  }
  return taus_againstElectron_;
}

std::vector<float>* const & cfa_13::taus_againstElectronLoose() const{
  if(!c_taus_againstElectronLoose_ && b_taus_againstElectronLoose_){
    b_taus_againstElectronLoose_->GetEntry(entry_);
    c_taus_againstElectronLoose_ = true;
  }
  return taus_againstElectronLoose_;
}

std::vector<float>* const & cfa_13::taus_againstElectronMVA() const{
  if(!c_taus_againstElectronMVA_ && b_taus_againstElectronMVA_){
    b_taus_againstElectronMVA_->GetEntry(entry_);
    c_taus_againstElectronMVA_ = true;
  }
  return taus_againstElectronMVA_;
}

std::vector<float>* const & cfa_13::taus_againstElectronMedium() const{
  if(!c_taus_againstElectronMedium_ && b_taus_againstElectronMedium_){
    b_taus_againstElectronMedium_->GetEntry(entry_);
    c_taus_againstElectronMedium_ = true;
  }
  return taus_againstElectronMedium_;
}

std::vector<float>* const & cfa_13::taus_againstElectronTight() const{
  if(!c_taus_againstElectronTight_ && b_taus_againstElectronTight_){
    b_taus_againstElectronTight_->GetEntry(entry_);
    c_taus_againstElectronTight_ = true;
  }
  return taus_againstElectronTight_;
}

std::vector<float>* const & cfa_13::taus_againstMuon() const{
  if(!c_taus_againstMuon_ && b_taus_againstMuon_){
    b_taus_againstMuon_->GetEntry(entry_);
    c_taus_againstMuon_ = true;
  }
  return taus_againstMuon_;
}

std::vector<float>* const & cfa_13::taus_againstMuonLoose() const{
  if(!c_taus_againstMuonLoose_ && b_taus_againstMuonLoose_){
    b_taus_againstMuonLoose_->GetEntry(entry_);
    c_taus_againstMuonLoose_ = true;
  }
  return taus_againstMuonLoose_;
}

std::vector<float>* const & cfa_13::taus_againstMuonMedium() const{
  if(!c_taus_againstMuonMedium_ && b_taus_againstMuonMedium_){
    b_taus_againstMuonMedium_->GetEntry(entry_);
    c_taus_againstMuonMedium_ = true;
  }
  return taus_againstMuonMedium_;
}

std::vector<float>* const & cfa_13::taus_againstMuonTight() const{
  if(!c_taus_againstMuonTight_ && b_taus_againstMuonTight_){
    b_taus_againstMuonTight_->GetEntry(entry_);
    c_taus_againstMuonTight_ = true;
  }
  return taus_againstMuonTight_;
}

std::vector<float>* const & cfa_13::taus_byIsoUsingLeadingPi() const{
  if(!c_taus_byIsoUsingLeadingPi_ && b_taus_byIsoUsingLeadingPi_){
    b_taus_byIsoUsingLeadingPi_->GetEntry(entry_);
    c_taus_byIsoUsingLeadingPi_ = true;
  }
  return taus_byIsoUsingLeadingPi_;
}

std::vector<float>* const & cfa_13::taus_byIsolation() const{
  if(!c_taus_byIsolation_ && b_taus_byIsolation_){
    b_taus_byIsolation_->GetEntry(entry_);
    c_taus_byIsolation_ = true;
  }
  return taus_byIsolation_;
}

std::vector<float>* const & cfa_13::taus_byLooseIsolation() const{
  if(!c_taus_byLooseIsolation_ && b_taus_byLooseIsolation_){
    b_taus_byLooseIsolation_->GetEntry(entry_);
    c_taus_byLooseIsolation_ = true;
  }
  return taus_byLooseIsolation_;
}

std::vector<float>* const & cfa_13::taus_byLooseIsolationDeltaBetaCorr() const{
  if(!c_taus_byLooseIsolationDeltaBetaCorr_ && b_taus_byLooseIsolationDeltaBetaCorr_){
    b_taus_byLooseIsolationDeltaBetaCorr_->GetEntry(entry_);
    c_taus_byLooseIsolationDeltaBetaCorr_ = true;
  }
  return taus_byLooseIsolationDeltaBetaCorr_;
}

std::vector<float>* const & cfa_13::taus_byMediumIsolation() const{
  if(!c_taus_byMediumIsolation_ && b_taus_byMediumIsolation_){
    b_taus_byMediumIsolation_->GetEntry(entry_);
    c_taus_byMediumIsolation_ = true;
  }
  return taus_byMediumIsolation_;
}

std::vector<float>* const & cfa_13::taus_byMediumIsolationDeltaBetaCorr() const{
  if(!c_taus_byMediumIsolationDeltaBetaCorr_ && b_taus_byMediumIsolationDeltaBetaCorr_){
    b_taus_byMediumIsolationDeltaBetaCorr_->GetEntry(entry_);
    c_taus_byMediumIsolationDeltaBetaCorr_ = true;
  }
  return taus_byMediumIsolationDeltaBetaCorr_;
}

std::vector<float>* const & cfa_13::taus_byTightIsolation() const{
  if(!c_taus_byTightIsolation_ && b_taus_byTightIsolation_){
    b_taus_byTightIsolation_->GetEntry(entry_);
    c_taus_byTightIsolation_ = true;
  }
  return taus_byTightIsolation_;
}

std::vector<float>* const & cfa_13::taus_byTightIsolationDeltaBetaCorr() const{
  if(!c_taus_byTightIsolationDeltaBetaCorr_ && b_taus_byTightIsolationDeltaBetaCorr_){
    b_taus_byTightIsolationDeltaBetaCorr_->GetEntry(entry_);
    c_taus_byTightIsolationDeltaBetaCorr_ = true;
  }
  return taus_byTightIsolationDeltaBetaCorr_;
}

std::vector<float>* const & cfa_13::taus_byVLooseIsolation() const{
  if(!c_taus_byVLooseIsolation_ && b_taus_byVLooseIsolation_){
    b_taus_byVLooseIsolation_->GetEntry(entry_);
    c_taus_byVLooseIsolation_ = true;
  }
  return taus_byVLooseIsolation_;
}

std::vector<float>* const & cfa_13::taus_byVLooseIsolationDeltaBetaCorr() const{
  if(!c_taus_byVLooseIsolationDeltaBetaCorr_ && b_taus_byVLooseIsolationDeltaBetaCorr_){
    b_taus_byVLooseIsolationDeltaBetaCorr_->GetEntry(entry_);
    c_taus_byVLooseIsolationDeltaBetaCorr_ = true;
  }
  return taus_byVLooseIsolationDeltaBetaCorr_;
}

std::vector<float>* const & cfa_13::taus_charge() const{
  if(!c_taus_charge_ && b_taus_charge_){
    b_taus_charge_->GetEntry(entry_);
    c_taus_charge_ = true;
  }
  return taus_charge_;
}

std::vector<float>* const & cfa_13::taus_decayModeFinding() const{
  if(!c_taus_decayModeFinding_ && b_taus_decayModeFinding_){
    b_taus_decayModeFinding_->GetEntry(entry_);
    c_taus_decayModeFinding_ = true;
  }
  return taus_decayModeFinding_;
}

std::vector<float>* const & cfa_13::taus_ecalIsoUsingLeadingPi() const{
  if(!c_taus_ecalIsoUsingLeadingPi_ && b_taus_ecalIsoUsingLeadingPi_){
    b_taus_ecalIsoUsingLeadingPi_->GetEntry(entry_);
    c_taus_ecalIsoUsingLeadingPi_ = true;
  }
  return taus_ecalIsoUsingLeadingPi_;
}

std::vector<float>* const & cfa_13::taus_ecalIsolation() const{
  if(!c_taus_ecalIsolation_ && b_taus_ecalIsolation_){
    b_taus_ecalIsolation_->GetEntry(entry_);
    c_taus_ecalIsolation_ = true;
  }
  return taus_ecalIsolation_;
}

std::vector<float>* const & cfa_13::taus_ecalStripSumEOverPLead() const{
  if(!c_taus_ecalStripSumEOverPLead_ && b_taus_ecalStripSumEOverPLead_){
    b_taus_ecalStripSumEOverPLead_->GetEntry(entry_);
    c_taus_ecalStripSumEOverPLead_ = true;
  }
  return taus_ecalStripSumEOverPLead_;
}

std::vector<int>* const & cfa_13::taus_el_ind() const{
  if(!c_taus_el_ind_ && b_taus_el_ind_){
    b_taus_el_ind_->GetEntry(entry_);
    c_taus_el_ind_ = true;
  }
  return taus_el_ind_;
}

std::vector<float>* const & cfa_13::taus_elecPreIdDecision() const{
  if(!c_taus_elecPreIdDecision_ && b_taus_elecPreIdDecision_){
    b_taus_elecPreIdDecision_->GetEntry(entry_);
    c_taus_elecPreIdDecision_ = true;
  }
  return taus_elecPreIdDecision_;
}

std::vector<float>* const & cfa_13::taus_elecPreIdOutput() const{
  if(!c_taus_elecPreIdOutput_ && b_taus_elecPreIdOutput_){
    b_taus_elecPreIdOutput_->GetEntry(entry_);
    c_taus_elecPreIdOutput_ = true;
  }
  return taus_elecPreIdOutput_;
}

std::vector<float>* const & cfa_13::taus_emf() const{
  if(!c_taus_emf_ && b_taus_emf_){
    b_taus_emf_->GetEntry(entry_);
    c_taus_emf_ = true;
  }
  return taus_emf_;
}

std::vector<float>* const & cfa_13::taus_energy() const{
  if(!c_taus_energy_ && b_taus_energy_){
    b_taus_energy_->GetEntry(entry_);
    c_taus_energy_ = true;
  }
  return taus_energy_;
}

std::vector<float>* const & cfa_13::taus_et() const{
  if(!c_taus_et_ && b_taus_et_){
    b_taus_et_->GetEntry(entry_);
    c_taus_et_ = true;
  }
  return taus_et_;
}

std::vector<float>* const & cfa_13::taus_eta() const{
  if(!c_taus_eta_ && b_taus_eta_){
    b_taus_eta_->GetEntry(entry_);
    c_taus_eta_ = true;
  }
  return taus_eta_;
}

std::vector<float>* const & cfa_13::taus_hcal3x3OverPLead() const{
  if(!c_taus_hcal3x3OverPLead_ && b_taus_hcal3x3OverPLead_){
    b_taus_hcal3x3OverPLead_->GetEntry(entry_);
    c_taus_hcal3x3OverPLead_ = true;
  }
  return taus_hcal3x3OverPLead_;
}

std::vector<float>* const & cfa_13::taus_hcalMaxOverPLead() const{
  if(!c_taus_hcalMaxOverPLead_ && b_taus_hcalMaxOverPLead_){
    b_taus_hcalMaxOverPLead_->GetEntry(entry_);
    c_taus_hcalMaxOverPLead_ = true;
  }
  return taus_hcalMaxOverPLead_;
}

std::vector<float>* const & cfa_13::taus_hcalTotOverPLead() const{
  if(!c_taus_hcalTotOverPLead_ && b_taus_hcalTotOverPLead_){
    b_taus_hcalTotOverPLead_->GetEntry(entry_);
    c_taus_hcalTotOverPLead_ = true;
  }
  return taus_hcalTotOverPLead_;
}

std::vector<float>* const & cfa_13::taus_isoPFChargedHadrCandsPtSum() const{
  if(!c_taus_isoPFChargedHadrCandsPtSum_ && b_taus_isoPFChargedHadrCandsPtSum_){
    b_taus_isoPFChargedHadrCandsPtSum_->GetEntry(entry_);
    c_taus_isoPFChargedHadrCandsPtSum_ = true;
  }
  return taus_isoPFChargedHadrCandsPtSum_;
}

std::vector<float>* const & cfa_13::taus_isoPFGammaCandsEtSum() const{
  if(!c_taus_isoPFGammaCandsEtSum_ && b_taus_isoPFGammaCandsEtSum_){
    b_taus_isoPFGammaCandsEtSum_->GetEntry(entry_);
    c_taus_isoPFGammaCandsEtSum_ = true;
  }
  return taus_isoPFGammaCandsEtSum_;
}

std::vector<float>* const & cfa_13::taus_leadPFChargedHadrCand_ECAL_eta() const{
  if(!c_taus_leadPFChargedHadrCand_ECAL_eta_ && b_taus_leadPFChargedHadrCand_ECAL_eta_){
    b_taus_leadPFChargedHadrCand_ECAL_eta_->GetEntry(entry_);
    c_taus_leadPFChargedHadrCand_ECAL_eta_ = true;
  }
  return taus_leadPFChargedHadrCand_ECAL_eta_;
}

std::vector<float>* const & cfa_13::taus_leadPFChargedHadrCand_charge() const{
  if(!c_taus_leadPFChargedHadrCand_charge_ && b_taus_leadPFChargedHadrCand_charge_){
    b_taus_leadPFChargedHadrCand_charge_->GetEntry(entry_);
    c_taus_leadPFChargedHadrCand_charge_ = true;
  }
  return taus_leadPFChargedHadrCand_charge_;
}

std::vector<float>* const & cfa_13::taus_leadPFChargedHadrCand_eta() const{
  if(!c_taus_leadPFChargedHadrCand_eta_ && b_taus_leadPFChargedHadrCand_eta_){
    b_taus_leadPFChargedHadrCand_eta_->GetEntry(entry_);
    c_taus_leadPFChargedHadrCand_eta_ = true;
  }
  return taus_leadPFChargedHadrCand_eta_;
}

std::vector<float>* const & cfa_13::taus_leadPFChargedHadrCand_phi() const{
  if(!c_taus_leadPFChargedHadrCand_phi_ && b_taus_leadPFChargedHadrCand_phi_){
    b_taus_leadPFChargedHadrCand_phi_->GetEntry(entry_);
    c_taus_leadPFChargedHadrCand_phi_ = true;
  }
  return taus_leadPFChargedHadrCand_phi_;
}

std::vector<float>* const & cfa_13::taus_leadPFChargedHadrCand_pt() const{
  if(!c_taus_leadPFChargedHadrCand_pt_ && b_taus_leadPFChargedHadrCand_pt_){
    b_taus_leadPFChargedHadrCand_pt_->GetEntry(entry_);
    c_taus_leadPFChargedHadrCand_pt_ = true;
  }
  return taus_leadPFChargedHadrCand_pt_;
}

std::vector<float>* const & cfa_13::taus_leadingTrackFinding() const{
  if(!c_taus_leadingTrackFinding_ && b_taus_leadingTrackFinding_){
    b_taus_leadingTrackFinding_->GetEntry(entry_);
    c_taus_leadingTrackFinding_ = true;
  }
  return taus_leadingTrackFinding_;
}

std::vector<float>* const & cfa_13::taus_leadingTrackPtCut() const{
  if(!c_taus_leadingTrackPtCut_ && b_taus_leadingTrackPtCut_){
    b_taus_leadingTrackPtCut_->GetEntry(entry_);
    c_taus_leadingTrackPtCut_ = true;
  }
  return taus_leadingTrackPtCut_;
}

std::vector<float>* const & cfa_13::taus_muDecision() const{
  if(!c_taus_muDecision_ && b_taus_muDecision_){
    b_taus_muDecision_->GetEntry(entry_);
    c_taus_muDecision_ = true;
  }
  return taus_muDecision_;
}

std::vector<int>* const & cfa_13::taus_mu_ind() const{
  if(!c_taus_mu_ind_ && b_taus_mu_ind_){
    b_taus_mu_ind_->GetEntry(entry_);
    c_taus_mu_ind_ = true;
  }
  return taus_mu_ind_;
}

std::vector<float>* const & cfa_13::taus_phi() const{
  if(!c_taus_phi_ && b_taus_phi_){
    b_taus_phi_->GetEntry(entry_);
    c_taus_phi_ = true;
  }
  return taus_phi_;
}

std::vector<float>* const & cfa_13::taus_pt() const{
  if(!c_taus_pt_ && b_taus_pt_){
    b_taus_pt_->GetEntry(entry_);
    c_taus_pt_ = true;
  }
  return taus_pt_;
}

std::vector<float>* const & cfa_13::taus_px() const{
  if(!c_taus_px_ && b_taus_px_){
    b_taus_px_->GetEntry(entry_);
    c_taus_px_ = true;
  }
  return taus_px_;
}

std::vector<float>* const & cfa_13::taus_py() const{
  if(!c_taus_py_ && b_taus_py_){
    b_taus_py_->GetEntry(entry_);
    c_taus_py_ = true;
  }
  return taus_py_;
}

std::vector<float>* const & cfa_13::taus_pz() const{
  if(!c_taus_pz_ && b_taus_pz_){
    b_taus_pz_->GetEntry(entry_);
    c_taus_pz_ = true;
  }
  return taus_pz_;
}

std::vector<float>* const & cfa_13::taus_signalPFChargedHadrCandsSize() const{
  if(!c_taus_signalPFChargedHadrCandsSize_ && b_taus_signalPFChargedHadrCandsSize_){
    b_taus_signalPFChargedHadrCandsSize_->GetEntry(entry_);
    c_taus_signalPFChargedHadrCandsSize_ = true;
  }
  return taus_signalPFChargedHadrCandsSize_;
}

std::vector<float>* const & cfa_13::taus_status() const{
  if(!c_taus_status_ && b_taus_status_){
    b_taus_status_->GetEntry(entry_);
    c_taus_status_ = true;
  }
  return taus_status_;
}

std::vector<float>* const & cfa_13::taus_taNC() const{
  if(!c_taus_taNC_ && b_taus_taNC_){
    b_taus_taNC_->GetEntry(entry_);
    c_taus_taNC_ = true;
  }
  return taus_taNC_;
}

std::vector<float>* const & cfa_13::taus_taNC_half() const{
  if(!c_taus_taNC_half_ && b_taus_taNC_half_){
    b_taus_taNC_half_->GetEntry(entry_);
    c_taus_taNC_half_ = true;
  }
  return taus_taNC_half_;
}

std::vector<float>* const & cfa_13::taus_taNC_one() const{
  if(!c_taus_taNC_one_ && b_taus_taNC_one_){
    b_taus_taNC_one_->GetEntry(entry_);
    c_taus_taNC_one_ = true;
  }
  return taus_taNC_one_;
}

std::vector<float>* const & cfa_13::taus_taNC_quarter() const{
  if(!c_taus_taNC_quarter_ && b_taus_taNC_quarter_){
    b_taus_taNC_quarter_->GetEntry(entry_);
    c_taus_taNC_quarter_ = true;
  }
  return taus_taNC_quarter_;
}

std::vector<float>* const & cfa_13::taus_taNC_tenth() const{
  if(!c_taus_taNC_tenth_ && b_taus_taNC_tenth_){
    b_taus_taNC_tenth_->GetEntry(entry_);
    c_taus_taNC_tenth_ = true;
  }
  return taus_taNC_tenth_;
}

std::vector<float>* const & cfa_13::taus_theta() const{
  if(!c_taus_theta_ && b_taus_theta_){
    b_taus_theta_->GetEntry(entry_);
    c_taus_theta_ = true;
  }
  return taus_theta_;
}

std::vector<float>* const & cfa_13::taus_tkIsoUsingLeadingPi() const{
  if(!c_taus_tkIsoUsingLeadingPi_ && b_taus_tkIsoUsingLeadingPi_){
    b_taus_tkIsoUsingLeadingPi_->GetEntry(entry_);
    c_taus_tkIsoUsingLeadingPi_ = true;
  }
  return taus_tkIsoUsingLeadingPi_;
}

std::vector<float>* const & cfa_13::taus_trackIsolation() const{
  if(!c_taus_trackIsolation_ && b_taus_trackIsolation_){
    b_taus_trackIsolation_->GetEntry(entry_);
    c_taus_trackIsolation_ = true;
  }
  return taus_trackIsolation_;
}

Int_t const & cfa_13::trackingfailurefilter_decision() const{
  if(!c_trackingfailurefilter_decision_ && b_trackingfailurefilter_decision_){
    b_trackingfailurefilter_decision_->GetEntry(entry_);
    c_trackingfailurefilter_decision_ = true;
  }
  return trackingfailurefilter_decision_;
}

std::vector<bool>* const & cfa_13::trigger_decision() const{
  if(!c_trigger_decision_ && b_trigger_decision_){
    b_trigger_decision_->GetEntry(entry_);
    c_trigger_decision_ = true;
  }
  return trigger_decision_;
}

std::vector<std::string>* const & cfa_13::trigger_name() const{
  if(!c_trigger_name_ && b_trigger_name_){
    b_trigger_name_->GetEntry(entry_);
    c_trigger_name_ = true;
  }
  return trigger_name_;
}

std::vector<float>* const & cfa_13::trigger_prescalevalue() const{
  if(!c_trigger_prescalevalue_ && b_trigger_prescalevalue_){
    b_trigger_prescalevalue_->GetEntry(entry_);
    c_trigger_prescalevalue_ = true;
  }
  return trigger_prescalevalue_;
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

Float_t const & cfa_13::weight() const{
  if(!c_weight_ && b_weight_){
    b_weight_->GetEntry(entry_);
    c_weight_ = true;
  }
  return weight_;
}

