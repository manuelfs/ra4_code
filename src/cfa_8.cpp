#include "cfa_8.hpp"

#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>

#include "TChain.h"

cfa_8::cfa_8(const std::string &file):
  cfa_base(file),
  L1trigger_alias_(0),
  L1trigger_bit_(0),
  L1trigger_decision_(0),
  L1trigger_decision_nomask_(0),
  L1trigger_name_(0),
  L1trigger_prescalevalue_(0),
  L1trigger_techTrigger_(0),
  MPT_(0),
  NbeamSpot_(0),
  Nels_(0),
  Njets_AK5PF_(0),
  Njets_AK5PFclean_(0),
  Nmc_doc_(0),
  Nmc_electrons_(0),
  Nmc_mus_(0),
  Nmc_nues_(0),
  Nmc_numus_(0),
  Nmc_nutaus_(0),
  Nmc_pdf_(0),
  Nmc_photons_(0),
  Nmc_taus_(0),
  NmetsHO_(0),
  Nmets_AK5_(0),
  Nmus_(0),
  NpfTypeINoXYCorrmets_(0),
  NpfTypeIType0mets_(0),
  NpfTypeImets_(0),
  Npf_els_(0),
  Npf_mus_(0),
  Npf_photons_(0),
  Npfcand_(0),
  Npfmets_(0),
  Nphotons_(0),
  Npv_(0),
  Ntaus_(0),
  Ntcmets_(0),
  Ntracks_(0),
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
  ecalBEfilter_decision_(0),
  ecalTPfilter_decision_(0),
  ecallaserfilter_decision_(0),
  eebadscfilter_decision_(0),
  eenoisefilter_decision_(0),
  els_PATpassConversionVeto_(0),
  els_PFchargedHadronIsoR03_(0),
  els_PFneutralHadronIsoR03_(0),
  els_PFphotonIsoR03_(0),
  els_basicClustersSize_(0),
  els_cIso_(0),
  els_caloEnergy_(0),
  els_charge_(0),
  els_chi2_(0),
  els_conversion_dcot_(0),
  els_conversion_dist_(0),
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
  els_hasMatchedConversion_(0),
  els_hcalIso_(0),
  els_hcalOverEcalBc_(0),
  els_isEB_(0),
  els_isEE_(0),
  els_looseId_(0),
  els_n_inner_layer_(0),
  els_n_outer_layer_(0),
  els_ndof_(0),
  els_numlosthits_(0),
  els_numvalhits_(0),
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
  genHT_(0),
  greedymuonfilter_decision_(0),
  hbhefilter_decision_(0),
  hcallaserfilter_decision_(0),
  inconsistentPFmuonfilter_decision_(0),
  isotk_charge_(0),
  isotk_dzpv_(0),
  isotk_eta_(0),
  isotk_iso_(0),
  isotk_phi_(0),
  isotk_pt_(0),
  jets_AK5PF_area_(0),
  jets_AK5PF_btag_TC_highEff_(0),
  jets_AK5PF_btag_TC_highPur_(0),
  jets_AK5PF_btag_jetBProb_(0),
  jets_AK5PF_btag_jetProb_(0),
  jets_AK5PF_btag_secVertexCombined_(0),
  jets_AK5PF_btag_secVertexHighEff_(0),
  jets_AK5PF_btag_secVertexHighPur_(0),
  jets_AK5PF_btag_softEle_(0),
  jets_AK5PF_btag_softMuon_(0),
  jets_AK5PF_chgEmE_(0),
  jets_AK5PF_chgHadE_(0),
  jets_AK5PF_chgMuE_(0),
  jets_AK5PF_chg_Mult_(0),
  jets_AK5PF_corrFactorRaw_(0),
  jets_AK5PF_ehf_(0),
  jets_AK5PF_emf_(0),
  jets_AK5PF_energy_(0),
  jets_AK5PF_et_(0),
  jets_AK5PF_eta_(0),
  jets_AK5PF_etaetaMoment_(0),
  jets_AK5PF_etaphiMoment_(0),
  jets_AK5PF_fHPD_(0),
  jets_AK5PF_fRBX_(0),
  jets_AK5PF_fSubDetector1_(0),
  jets_AK5PF_fSubDetector2_(0),
  jets_AK5PF_fSubDetector3_(0),
  jets_AK5PF_fSubDetector4_(0),
  jets_AK5PF_gen_Energy_(0),
  jets_AK5PF_gen_Id_(0),
  jets_AK5PF_gen_et_(0),
  jets_AK5PF_gen_eta_(0),
  jets_AK5PF_gen_mass_(0),
  jets_AK5PF_gen_motherID_(0),
  jets_AK5PF_gen_phi_(0),
  jets_AK5PF_gen_pt_(0),
  jets_AK5PF_gen_threeCharge_(0),
  jets_AK5PF_hitsInN90_(0),
  jets_AK5PF_jetCharge_(0),
  jets_AK5PF_mass_(0),
  jets_AK5PF_mu_Mult_(0),
  jets_AK5PF_n60_(0),
  jets_AK5PF_n90_(0),
  jets_AK5PF_n90Hits_(0),
  jets_AK5PF_nECALTowers_(0),
  jets_AK5PF_nHCALTowers_(0),
  jets_AK5PF_neutralEmE_(0),
  jets_AK5PF_neutralHadE_(0),
  jets_AK5PF_neutral_Mult_(0),
  jets_AK5PF_partonFlavour_(0),
  jets_AK5PF_parton_Energy_(0),
  jets_AK5PF_parton_Id_(0),
  jets_AK5PF_parton_eta_(0),
  jets_AK5PF_parton_mass_(0),
  jets_AK5PF_parton_motherId_(0),
  jets_AK5PF_parton_phi_(0),
  jets_AK5PF_parton_pt_(0),
  jets_AK5PF_phi_(0),
  jets_AK5PF_phiphiMoment_(0),
  jets_AK5PF_photonEnergy_(0),
  jets_AK5PF_pt_(0),
  jets_AK5PF_px_(0),
  jets_AK5PF_py_(0),
  jets_AK5PF_pz_(0),
  jets_AK5PF_rawPt_(0),
  jets_AK5PF_status_(0),
  jets_AK5PF_theta_(0),
  jets_AK5PFclean_Uncert_(0),
  jets_AK5PFclean_area_(0),
  jets_AK5PFclean_btag_TC_highEff_(0),
  jets_AK5PFclean_btag_TC_highPur_(0),
  jets_AK5PFclean_btag_jetBProb_(0),
  jets_AK5PFclean_btag_jetProb_(0),
  jets_AK5PFclean_btag_secVertexCombined_(0),
  jets_AK5PFclean_btag_secVertexHighEff_(0),
  jets_AK5PFclean_btag_secVertexHighPur_(0),
  jets_AK5PFclean_btag_softEle_(0),
  jets_AK5PFclean_btag_softMuon_(0),
  jets_AK5PFclean_chgEmE_(0),
  jets_AK5PFclean_chgHadE_(0),
  jets_AK5PFclean_chgMuE_(0),
  jets_AK5PFclean_chg_Mult_(0),
  jets_AK5PFclean_corrFactorRaw_(0),
  jets_AK5PFclean_corrL1FastL2L3_(0),
  jets_AK5PFclean_corrL1FastL2L3Residual_(0),
  jets_AK5PFclean_corrL1L2L3_(0),
  jets_AK5PFclean_corrL1L2L3Residual_(0),
  jets_AK5PFclean_corrL2L3_(0),
  jets_AK5PFclean_corrL2L3Residual_(0),
  jets_AK5PFclean_ehf_(0),
  jets_AK5PFclean_emf_(0),
  jets_AK5PFclean_energy_(0),
  jets_AK5PFclean_et_(0),
  jets_AK5PFclean_eta_(0),
  jets_AK5PFclean_etaetaMoment_(0),
  jets_AK5PFclean_etaphiMoment_(0),
  jets_AK5PFclean_fHPD_(0),
  jets_AK5PFclean_fRBX_(0),
  jets_AK5PFclean_fSubDetector1_(0),
  jets_AK5PFclean_fSubDetector2_(0),
  jets_AK5PFclean_fSubDetector3_(0),
  jets_AK5PFclean_fSubDetector4_(0),
  jets_AK5PFclean_gen_Energy_(0),
  jets_AK5PFclean_gen_Id_(0),
  jets_AK5PFclean_gen_et_(0),
  jets_AK5PFclean_gen_eta_(0),
  jets_AK5PFclean_gen_mass_(0),
  jets_AK5PFclean_gen_phi_(0),
  jets_AK5PFclean_gen_pt_(0),
  jets_AK5PFclean_hitsInN90_(0),
  jets_AK5PFclean_jetCharge_(0),
  jets_AK5PFclean_mass_(0),
  jets_AK5PFclean_mu_Mult_(0),
  jets_AK5PFclean_n60_(0),
  jets_AK5PFclean_n90_(0),
  jets_AK5PFclean_n90Hits_(0),
  jets_AK5PFclean_nECALTowers_(0),
  jets_AK5PFclean_nHCALTowers_(0),
  jets_AK5PFclean_neutralEmE_(0),
  jets_AK5PFclean_neutralHadE_(0),
  jets_AK5PFclean_neutral_Mult_(0),
  jets_AK5PFclean_partonFlavour_(0),
  jets_AK5PFclean_parton_Energy_(0),
  jets_AK5PFclean_parton_Id_(0),
  jets_AK5PFclean_parton_eta_(0),
  jets_AK5PFclean_parton_mass_(0),
  jets_AK5PFclean_parton_motherId_(0),
  jets_AK5PFclean_parton_phi_(0),
  jets_AK5PFclean_parton_pt_(0),
  jets_AK5PFclean_phi_(0),
  jets_AK5PFclean_phiphiMoment_(0),
  jets_AK5PFclean_photonEnergy_(0),
  jets_AK5PFclean_pt_(0),
  jets_AK5PFclean_px_(0),
  jets_AK5PFclean_py_(0),
  jets_AK5PFclean_pz_(0),
  jets_AK5PFclean_rawPt_(0),
  jets_AK5PFclean_status_(0),
  jets_AK5PFclean_theta_(0),
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
  mc_pdf_id1_(0),
  mc_pdf_id2_(0),
  mc_pdf_q_(0),
  mc_pdf_x1_(0),
  mc_pdf_x2_(0),
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
  metsHO_et_(0),
  metsHO_ex_(0),
  metsHO_ey_(0),
  metsHO_phi_(0),
  metsHO_sumEt_(0),
  mets_AK5_et_(0),
  mets_AK5_ex_(0),
  mets_AK5_ey_(0),
  mets_AK5_gen_et_(0),
  mets_AK5_gen_phi_(0),
  mets_AK5_phi_(0),
  mets_AK5_sign_(0),
  mets_AK5_sumEt_(0),
  mets_AK5_unCPhi_(0),
  mets_AK5_unCPt_(0),
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
  passprescaleHT250filter_decision_(0),
  passprescaleHT300filter_decision_(0),
  passprescaleHT350filter_decision_(0),
  passprescaleHT400filter_decision_(0),
  passprescaleHT450filter_decision_(0),
  passprescaleJet30MET80filter_decision_(0),
  passprescalePFHT350filter_decision_(0),
  pdfweights_cteq_(0),
  pdfweights_mstw_(0),
  pdfweights_nnpdf_(0),
  pfTypeINoXYCorrmets_et_(0),
  pfTypeINoXYCorrmets_ex_(0),
  pfTypeINoXYCorrmets_ey_(0),
  pfTypeINoXYCorrmets_gen_et_(0),
  pfTypeINoXYCorrmets_gen_phi_(0),
  pfTypeINoXYCorrmets_phi_(0),
  pfTypeINoXYCorrmets_sign_(0),
  pfTypeINoXYCorrmets_sumEt_(0),
  pfTypeINoXYCorrmets_unCPhi_(0),
  pfTypeINoXYCorrmets_unCPt_(0),
  pfTypeIType0mets_et_(0),
  pfTypeIType0mets_ex_(0),
  pfTypeIType0mets_ey_(0),
  pfTypeIType0mets_gen_et_(0),
  pfTypeIType0mets_gen_phi_(0),
  pfTypeIType0mets_phi_(0),
  pfTypeIType0mets_sign_(0),
  pfTypeIType0mets_sumEt_(0),
  pfTypeIType0mets_unCPhi_(0),
  pfTypeIType0mets_unCPt_(0),
  pfTypeImets_et_(0),
  pfTypeImets_ex_(0),
  pfTypeImets_ey_(0),
  pfTypeImets_gen_et_(0),
  pfTypeImets_gen_phi_(0),
  pfTypeImets_phi_(0),
  pfTypeImets_sign_(0),
  pfTypeImets_sumEt_(0),
  pfTypeImets_unCPhi_(0),
  pfTypeImets_unCPt_(0),
  pf_els_PATpassConversionVeto_(0),
  pf_els_PFchargedHadronIsoR03_(0),
  pf_els_PFneutralHadronIsoR03_(0),
  pf_els_PFphotonIsoR03_(0),
  pf_els_basicClustersSize_(0),
  pf_els_cIso_(0),
  pf_els_caloEnergy_(0),
  pf_els_charge_(0),
  pf_els_chargedHadronIso_(0),
  pf_els_chi2_(0),
  pf_els_core_ecalDrivenSeed_(0),
  pf_els_cpx_(0),
  pf_els_cpy_(0),
  pf_els_cpz_(0),
  pf_els_ctf_tk_charge_(0),
  pf_els_ctf_tk_eta_(0),
  pf_els_ctf_tk_id_(0),
  pf_els_ctf_tk_phi_(0),
  pf_els_cx_(0),
  pf_els_cy_(0),
  pf_els_cz_(0),
  pf_els_d0dum_(0),
  pf_els_d0dumError_(0),
  pf_els_dEtaIn_(0),
  pf_els_dEtaOut_(0),
  pf_els_dPhiIn_(0),
  pf_els_dPhiOut_(0),
  pf_els_dr03EcalRecHitSumEt_(0),
  pf_els_dr03HcalDepth1TowerSumEt_(0),
  pf_els_dr03HcalDepth2TowerSumEt_(0),
  pf_els_dr03HcalTowerSumEt_(0),
  pf_els_dr03TkSumPt_(0),
  pf_els_dr04EcalRecHitSumEt_(0),
  pf_els_dr04HcalDepth1TowerSumEt_(0),
  pf_els_dr04HcalDepth2TowerSumEt_(0),
  pf_els_dr04HcalTowerSumEt_(0),
  pf_els_dr04TkSumPt_(0),
  pf_els_dz_(0),
  pf_els_dzError_(0),
  pf_els_eOverPIn_(0),
  pf_els_eSeedOverPOut_(0),
  pf_els_ecalIso_(0),
  pf_els_energy_(0),
  pf_els_et_(0),
  pf_els_eta_(0),
  pf_els_etaError_(0),
  pf_els_fbrem_(0),
  pf_els_gen_et_(0),
  pf_els_gen_eta_(0),
  pf_els_gen_id_(0),
  pf_els_gen_mother_et_(0),
  pf_els_gen_mother_eta_(0),
  pf_els_gen_mother_id_(0),
  pf_els_gen_mother_phi_(0),
  pf_els_gen_mother_pt_(0),
  pf_els_gen_mother_px_(0),
  pf_els_gen_mother_py_(0),
  pf_els_gen_mother_pz_(0),
  pf_els_gen_mother_theta_(0),
  pf_els_gen_phi_(0),
  pf_els_gen_pt_(0),
  pf_els_gen_px_(0),
  pf_els_gen_py_(0),
  pf_els_gen_pz_(0),
  pf_els_gen_theta_(0),
  pf_els_hadOverEm_(0),
  pf_els_hasMatchedConversion_(0),
  pf_els_hcalIso_(0),
  pf_els_hcalOverEcalBc_(0),
  pf_els_isEB_(0),
  pf_els_isEE_(0),
  pf_els_looseId_(0),
  pf_els_n_inner_layer_(0),
  pf_els_n_outer_layer_(0),
  pf_els_ndof_(0),
  pf_els_neutralHadronIso_(0),
  pf_els_numlosthits_(0),
  pf_els_numvalhits_(0),
  pf_els_phi_(0),
  pf_els_phiError_(0),
  pf_els_photonIso_(0),
  pf_els_pt_(0),
  pf_els_ptError_(0),
  pf_els_px_(0),
  pf_els_py_(0),
  pf_els_pz_(0),
  pf_els_robustHighEnergyId_(0),
  pf_els_robustLooseId_(0),
  pf_els_robustTightId_(0),
  pf_els_scE1x5_(0),
  pf_els_scE2x5Max_(0),
  pf_els_scE5x5_(0),
  pf_els_scEnergy_(0),
  pf_els_scEta_(0),
  pf_els_scEtaWidth_(0),
  pf_els_scPhi_(0),
  pf_els_scPhiWidth_(0),
  pf_els_scRawEnergy_(0),
  pf_els_scSeedEnergy_(0),
  pf_els_shFracInnerHits_(0),
  pf_els_sigmaEtaEta_(0),
  pf_els_sigmaIEtaIEta_(0),
  pf_els_simpleEleId60cIso_(0),
  pf_els_simpleEleId60relIso_(0),
  pf_els_simpleEleId70cIso_(0),
  pf_els_simpleEleId70relIso_(0),
  pf_els_simpleEleId80cIso_(0),
  pf_els_simpleEleId80relIso_(0),
  pf_els_simpleEleId85cIso_(0),
  pf_els_simpleEleId85relIso_(0),
  pf_els_simpleEleId90cIso_(0),
  pf_els_simpleEleId90relIso_(0),
  pf_els_simpleEleId95cIso_(0),
  pf_els_simpleEleId95relIso_(0),
  pf_els_status_(0),
  pf_els_tIso_(0),
  pf_els_theta_(0),
  pf_els_tightId_(0),
  pf_els_tk_charge_(0),
  pf_els_tk_eta_(0),
  pf_els_tk_phi_(0),
  pf_els_tk_pt_(0),
  pf_els_tk_pz_(0),
  pf_els_vpx_(0),
  pf_els_vpy_(0),
  pf_els_vpz_(0),
  pf_els_vx_(0),
  pf_els_vy_(0),
  pf_els_vz_(0),
  pf_mus_cIso_(0),
  pf_mus_calEnergyEm_(0),
  pf_mus_calEnergyEmS9_(0),
  pf_mus_calEnergyHad_(0),
  pf_mus_calEnergyHadS9_(0),
  pf_mus_calEnergyHo_(0),
  pf_mus_calEnergyHoS9_(0),
  pf_mus_charge_(0),
  pf_mus_chargedHadronIso_(0),
  pf_mus_cm_ExpectedHitsInner_(0),
  pf_mus_cm_ExpectedHitsOuter_(0),
  pf_mus_cm_LayersWithMeasurement_(0),
  pf_mus_cm_LayersWithoutMeasurement_(0),
  pf_mus_cm_PixelLayersWithMeasurement_(0),
  pf_mus_cm_ValidStripLayersWithMonoAndStereoHit_(0),
  pf_mus_cm_chg_(0),
  pf_mus_cm_chi2_(0),
  pf_mus_cm_d0dum_(0),
  pf_mus_cm_d0dumErr_(0),
  pf_mus_cm_dz_(0),
  pf_mus_cm_dzErr_(0),
  pf_mus_cm_eta_(0),
  pf_mus_cm_etaErr_(0),
  pf_mus_cm_ndof_(0),
  pf_mus_cm_numlosthits_(0),
  pf_mus_cm_numvalMuonhits_(0),
  pf_mus_cm_numvalhits_(0),
  pf_mus_cm_phi_(0),
  pf_mus_cm_phiErr_(0),
  pf_mus_cm_pt_(0),
  pf_mus_cm_ptErr_(0),
  pf_mus_cm_px_(0),
  pf_mus_cm_py_(0),
  pf_mus_cm_pz_(0),
  pf_mus_cm_theta_(0),
  pf_mus_cm_vx_(0),
  pf_mus_cm_vy_(0),
  pf_mus_cm_vz_(0),
  pf_mus_dB_(0),
  pf_mus_ecalIso_(0),
  pf_mus_energy_(0),
  pf_mus_et_(0),
  pf_mus_eta_(0),
  pf_mus_gen_et_(0),
  pf_mus_gen_eta_(0),
  pf_mus_gen_id_(0),
  pf_mus_gen_mother_et_(0),
  pf_mus_gen_mother_eta_(0),
  pf_mus_gen_mother_id_(0),
  pf_mus_gen_mother_phi_(0),
  pf_mus_gen_mother_pt_(0),
  pf_mus_gen_mother_px_(0),
  pf_mus_gen_mother_py_(0),
  pf_mus_gen_mother_pz_(0),
  pf_mus_gen_mother_theta_(0),
  pf_mus_gen_phi_(0),
  pf_mus_gen_pt_(0),
  pf_mus_gen_px_(0),
  pf_mus_gen_py_(0),
  pf_mus_gen_pz_(0),
  pf_mus_gen_theta_(0),
  pf_mus_hcalIso_(0),
  pf_mus_id_All_(0),
  pf_mus_id_AllArbitrated_(0),
  pf_mus_id_AllGlobalMuons_(0),
  pf_mus_id_AllStandAloneMuons_(0),
  pf_mus_id_AllTrackerMuons_(0),
  pf_mus_id_GlobalMuonPromptTight_(0),
  pf_mus_id_TM2DCompatibilityLoose_(0),
  pf_mus_id_TM2DCompatibilityTight_(0),
  pf_mus_id_TMLastStationLoose_(0),
  pf_mus_id_TMLastStationOptimizedLowPtLoose_(0),
  pf_mus_id_TMLastStationOptimizedLowPtTight_(0),
  pf_mus_id_TMLastStationTight_(0),
  pf_mus_id_TMOneStationLoose_(0),
  pf_mus_id_TMOneStationTight_(0),
  pf_mus_id_TrackerMuonArbitrated_(0),
  pf_mus_isCaloMuon_(0),
  pf_mus_isConvertedPhoton_(0),
  pf_mus_isElectron_(0),
  pf_mus_isGlobalMuon_(0),
  pf_mus_isPFMuon_(0),
  pf_mus_isPhoton_(0),
  pf_mus_isStandAloneMuon_(0),
  pf_mus_isTrackerMuon_(0),
  pf_mus_iso03_emEt_(0),
  pf_mus_iso03_emVetoEt_(0),
  pf_mus_iso03_hadEt_(0),
  pf_mus_iso03_hadVetoEt_(0),
  pf_mus_iso03_hoEt_(0),
  pf_mus_iso03_nTracks_(0),
  pf_mus_iso03_sumPt_(0),
  pf_mus_iso05_emEt_(0),
  pf_mus_iso05_hadEt_(0),
  pf_mus_iso05_hoEt_(0),
  pf_mus_iso05_nTracks_(0),
  pf_mus_iso05_sumPt_(0),
  pf_mus_neutralHadronIso_(0),
  pf_mus_num_matches_(0),
  pf_mus_numberOfMatchedStations_(0),
  pf_mus_pfIsolationR03_sumChargedHadronPt_(0),
  pf_mus_pfIsolationR03_sumChargedParticlePt_(0),
  pf_mus_pfIsolationR03_sumNeutralHadronEt_(0),
  pf_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_(0),
  pf_mus_pfIsolationR03_sumPUPt_(0),
  pf_mus_pfIsolationR03_sumPhotonEt_(0),
  pf_mus_pfIsolationR03_sumPhotonEtHighThreshold_(0),
  pf_mus_pfIsolationR04_sumChargedHadronPt_(0),
  pf_mus_pfIsolationR04_sumChargedParticlePt_(0),
  pf_mus_pfIsolationR04_sumNeutralHadronEt_(0),
  pf_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_(0),
  pf_mus_pfIsolationR04_sumPUPt_(0),
  pf_mus_pfIsolationR04_sumPhotonEt_(0),
  pf_mus_pfIsolationR04_sumPhotonEtHighThreshold_(0),
  pf_mus_phi_(0),
  pf_mus_photonIso_(0),
  pf_mus_picky_ExpectedHitsInner_(0),
  pf_mus_picky_ExpectedHitsOuter_(0),
  pf_mus_picky_LayersWithMeasurement_(0),
  pf_mus_picky_LayersWithoutMeasurement_(0),
  pf_mus_picky_PixelLayersWithMeasurement_(0),
  pf_mus_picky_ValidStripLayersWithMonoAndStereoHit_(0),
  pf_mus_picky_chg_(0),
  pf_mus_picky_chi2_(0),
  pf_mus_picky_d0dum_(0),
  pf_mus_picky_d0dumErr_(0),
  pf_mus_picky_dz_(0),
  pf_mus_picky_dzErr_(0),
  pf_mus_picky_eta_(0),
  pf_mus_picky_etaErr_(0),
  pf_mus_picky_id_(0),
  pf_mus_picky_ndof_(0),
  pf_mus_picky_numlosthits_(0),
  pf_mus_picky_numvalPixelhits_(0),
  pf_mus_picky_numvalhits_(0),
  pf_mus_picky_phi_(0),
  pf_mus_picky_phiErr_(0),
  pf_mus_picky_pt_(0),
  pf_mus_picky_ptErr_(0),
  pf_mus_picky_px_(0),
  pf_mus_picky_py_(0),
  pf_mus_picky_pz_(0),
  pf_mus_picky_theta_(0),
  pf_mus_picky_vx_(0),
  pf_mus_picky_vy_(0),
  pf_mus_picky_vz_(0),
  pf_mus_pt_(0),
  pf_mus_px_(0),
  pf_mus_py_(0),
  pf_mus_pz_(0),
  pf_mus_stamu_chg_(0),
  pf_mus_stamu_chi2_(0),
  pf_mus_stamu_d0dum_(0),
  pf_mus_stamu_d0dumErr_(0),
  pf_mus_stamu_dz_(0),
  pf_mus_stamu_dzErr_(0),
  pf_mus_stamu_eta_(0),
  pf_mus_stamu_etaErr_(0),
  pf_mus_stamu_ndof_(0),
  pf_mus_stamu_numlosthits_(0),
  pf_mus_stamu_numvalhits_(0),
  pf_mus_stamu_phi_(0),
  pf_mus_stamu_phiErr_(0),
  pf_mus_stamu_pt_(0),
  pf_mus_stamu_ptErr_(0),
  pf_mus_stamu_px_(0),
  pf_mus_stamu_py_(0),
  pf_mus_stamu_pz_(0),
  pf_mus_stamu_theta_(0),
  pf_mus_stamu_vx_(0),
  pf_mus_stamu_vy_(0),
  pf_mus_stamu_vz_(0),
  pf_mus_status_(0),
  pf_mus_tIso_(0),
  pf_mus_theta_(0),
  pf_mus_tkHits_(0),
  pf_mus_tk_ExpectedHitsInner_(0),
  pf_mus_tk_ExpectedHitsOuter_(0),
  pf_mus_tk_LayersWithMeasurement_(0),
  pf_mus_tk_LayersWithoutMeasurement_(0),
  pf_mus_tk_PixelLayersWithMeasurement_(0),
  pf_mus_tk_ValidStripLayersWithMonoAndStereoHit_(0),
  pf_mus_tk_chg_(0),
  pf_mus_tk_chi2_(0),
  pf_mus_tk_d0dum_(0),
  pf_mus_tk_d0dumErr_(0),
  pf_mus_tk_dz_(0),
  pf_mus_tk_dzErr_(0),
  pf_mus_tk_eta_(0),
  pf_mus_tk_etaErr_(0),
  pf_mus_tk_id_(0),
  pf_mus_tk_ndof_(0),
  pf_mus_tk_numlosthits_(0),
  pf_mus_tk_numpixelWthMeasr_(0),
  pf_mus_tk_numvalPixelhits_(0),
  pf_mus_tk_numvalhits_(0),
  pf_mus_tk_phi_(0),
  pf_mus_tk_phiErr_(0),
  pf_mus_tk_pt_(0),
  pf_mus_tk_ptErr_(0),
  pf_mus_tk_px_(0),
  pf_mus_tk_py_(0),
  pf_mus_tk_pz_(0),
  pf_mus_tk_theta_(0),
  pf_mus_tk_vx_(0),
  pf_mus_tk_vy_(0),
  pf_mus_tk_vz_(0),
  pf_mus_tpfms_ExpectedHitsInner_(0),
  pf_mus_tpfms_ExpectedHitsOuter_(0),
  pf_mus_tpfms_LayersWithMeasurement_(0),
  pf_mus_tpfms_LayersWithoutMeasurement_(0),
  pf_mus_tpfms_PixelLayersWithMeasurement_(0),
  pf_mus_tpfms_ValidStripLayersWithMonoAndStereoHit_(0),
  pf_mus_tpfms_chg_(0),
  pf_mus_tpfms_chi2_(0),
  pf_mus_tpfms_d0dum_(0),
  pf_mus_tpfms_d0dumErr_(0),
  pf_mus_tpfms_dz_(0),
  pf_mus_tpfms_dzErr_(0),
  pf_mus_tpfms_eta_(0),
  pf_mus_tpfms_etaErr_(0),
  pf_mus_tpfms_id_(0),
  pf_mus_tpfms_ndof_(0),
  pf_mus_tpfms_numlosthits_(0),
  pf_mus_tpfms_numvalPixelhits_(0),
  pf_mus_tpfms_numvalhits_(0),
  pf_mus_tpfms_phi_(0),
  pf_mus_tpfms_phiErr_(0),
  pf_mus_tpfms_pt_(0),
  pf_mus_tpfms_ptErr_(0),
  pf_mus_tpfms_px_(0),
  pf_mus_tpfms_py_(0),
  pf_mus_tpfms_pz_(0),
  pf_mus_tpfms_theta_(0),
  pf_mus_tpfms_vx_(0),
  pf_mus_tpfms_vy_(0),
  pf_mus_tpfms_vz_(0),
  pf_photons_chIso_(0),
  pf_photons_e1x5_(0),
  pf_photons_e2x5_(0),
  pf_photons_e3x3_(0),
  pf_photons_e5x5_(0),
  pf_photons_energy_(0),
  pf_photons_et_(0),
  pf_photons_eta_(0),
  pf_photons_hadOverEM_(0),
  pf_photons_hadTowOverEM_(0),
  pf_photons_hasPixelSeed_(0),
  pf_photons_isAlsoElectron_(0),
  pf_photons_isConverted_(0),
  pf_photons_isEBEEGap_(0),
  pf_photons_isEBGap_(0),
  pf_photons_isEBPho_(0),
  pf_photons_isEEGap_(0),
  pf_photons_isEEPho_(0),
  pf_photons_maxEnergyXtal_(0),
  pf_photons_nhIso_(0),
  pf_photons_phIso_(0),
  pf_photons_phi_(0),
  pf_photons_pt_(0),
  pf_photons_px_(0),
  pf_photons_py_(0),
  pf_photons_pz_(0),
  pf_photons_r9_(0),
  pf_photons_scEnergy_(0),
  pf_photons_scEta_(0),
  pf_photons_scEtaWidth_(0),
  pf_photons_scPhi_(0),
  pf_photons_scPhiWidth_(0),
  pf_photons_scRawEnergy_(0),
  pf_photons_sigmaEtaEta_(0),
  pf_photons_sigmaIetaIeta_(0),
  pf_photons_status_(0),
  pf_photons_theta_(0),
  pfcand_charge_(0),
  pfcand_energy_(0),
  pfcand_eta_(0),
  pfcand_particleId_(0),
  pfcand_pdgId_(0),
  pfcand_phi_(0),
  pfcand_pt_(0),
  pfcand_px_(0),
  pfcand_py_(0),
  pfcand_pz_(0),
  pfcand_theta_(0),
  pfmets_et_(0),
  pfmets_ex_(0),
  pfmets_ey_(0),
  pfmets_fullSignif_(0),
  pfmets_fullSignifCov00_(0),
  pfmets_fullSignifCov00_2012_(0),
  pfmets_fullSignifCov00_2012_dataRes_(0),
  pfmets_fullSignifCov10_(0),
  pfmets_fullSignifCov10_2012_(0),
  pfmets_fullSignifCov10_2012_dataRes_(0),
  pfmets_fullSignifCov11_(0),
  pfmets_fullSignifCov11_2012_(0),
  pfmets_fullSignifCov11_2012_dataRes_(0),
  pfmets_fullSignif_2012_(0),
  pfmets_fullSignif_2012_dataRes_(0),
  pfmets_gen_et_(0),
  pfmets_gen_phi_(0),
  pfmets_phi_(0),
  pfmets_sign_(0),
  pfmets_sumEt_(0),
  pfmets_unCPhi_(0),
  pfmets_unCPt_(0),
  photon_chIsoValues_(0),
  photon_nhIsoValues_(0),
  photon_passElectronVeto_(0),
  photon_phIsoValues_(0),
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
  puJet_rejectionBeta_(0),
  puJet_rejectionMVA_(0),
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
  rho_kt6PFJetsForIsolation2011_(0),
  rho_kt6PFJetsForIsolation2012_(0),
  run_(0),
  scrapingVeto_decision_(0),
  softjetUp_dMEx_(0),
  softjetUp_dMEy_(0),
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
  tcmets_et_(0),
  tcmets_ex_(0),
  tcmets_ey_(0),
  tcmets_phi_(0),
  tcmets_sumEt_(0),
  trackercoherentnoisefilter1_decision_(0),
  trackercoherentnoisefilter2_decision_(0),
  trackertoomanyclustersfilter_decision_(0),
  trackertoomanyseedsfilter_decision_(0),
  trackertoomanytripletsfilter_decision_(0),
  trackingfailurefilter_decision_(0),
  tracks_chg_(0),
  tracks_chi2_(0),
  tracks_d0dum_(0),
  tracks_d0dumErr_(0),
  tracks_dz_(0),
  tracks_dzErr_(0),
  tracks_eta_(0),
  tracks_etaErr_(0),
  tracks_highPurity_(0),
  tracks_ndof_(0),
  tracks_numlosthits_(0),
  tracks_numvalhits_(0),
  tracks_phi_(0),
  tracks_phiErr_(0),
  tracks_pt_(0),
  tracks_ptErr_(0),
  tracks_px_(0),
  tracks_py_(0),
  tracks_pz_(0),
  tracks_vx_(0),
  tracks_vy_(0),
  tracks_vz_(0),
  trigger_decision_(0),
  trigger_lastfiltername_(0),
  trigger_name_(0),
  trigger_prescalevalue_(0),
  triggerobject_collectionname_(0),
  triggerobject_energy_(0),
  triggerobject_et_(0),
  triggerobject_eta_(0),
  triggerobject_phi_(0),
  triggerobject_pt_(0),
  triggerobject_px_(0),
  triggerobject_py_(0),
  triggerobject_pz_(0),
  trk_nTOBTEC_(0),
  trk_ratioAllTOBTEC_(0),
  trk_ratioJetTOBTEC_(0),
  weight_(0),
  b_L1trigger_alias_(NULL),
  b_L1trigger_bit_(NULL),
  b_L1trigger_decision_(NULL),
  b_L1trigger_decision_nomask_(NULL),
  b_L1trigger_name_(NULL),
  b_L1trigger_prescalevalue_(NULL),
  b_L1trigger_techTrigger_(NULL),
  b_MPT_(NULL),
  b_NbeamSpot_(NULL),
  b_Nels_(NULL),
  b_Njets_AK5PF_(NULL),
  b_Njets_AK5PFclean_(NULL),
  b_Nmc_doc_(NULL),
  b_Nmc_electrons_(NULL),
  b_Nmc_mus_(NULL),
  b_Nmc_nues_(NULL),
  b_Nmc_numus_(NULL),
  b_Nmc_nutaus_(NULL),
  b_Nmc_pdf_(NULL),
  b_Nmc_photons_(NULL),
  b_Nmc_taus_(NULL),
  b_NmetsHO_(NULL),
  b_Nmets_AK5_(NULL),
  b_Nmus_(NULL),
  b_NpfTypeINoXYCorrmets_(NULL),
  b_NpfTypeIType0mets_(NULL),
  b_NpfTypeImets_(NULL),
  b_Npf_els_(NULL),
  b_Npf_mus_(NULL),
  b_Npf_photons_(NULL),
  b_Npfcand_(NULL),
  b_Npfmets_(NULL),
  b_Nphotons_(NULL),
  b_Npv_(NULL),
  b_Ntaus_(NULL),
  b_Ntcmets_(NULL),
  b_Ntracks_(NULL),
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
  b_ecalBEfilter_decision_(NULL),
  b_ecalTPfilter_decision_(NULL),
  b_ecallaserfilter_decision_(NULL),
  b_eebadscfilter_decision_(NULL),
  b_eenoisefilter_decision_(NULL),
  b_els_PATpassConversionVeto_(NULL),
  b_els_PFchargedHadronIsoR03_(NULL),
  b_els_PFneutralHadronIsoR03_(NULL),
  b_els_PFphotonIsoR03_(NULL),
  b_els_basicClustersSize_(NULL),
  b_els_cIso_(NULL),
  b_els_caloEnergy_(NULL),
  b_els_charge_(NULL),
  b_els_chi2_(NULL),
  b_els_conversion_dcot_(NULL),
  b_els_conversion_dist_(NULL),
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
  b_els_hasMatchedConversion_(NULL),
  b_els_hcalIso_(NULL),
  b_els_hcalOverEcalBc_(NULL),
  b_els_isEB_(NULL),
  b_els_isEE_(NULL),
  b_els_looseId_(NULL),
  b_els_n_inner_layer_(NULL),
  b_els_n_outer_layer_(NULL),
  b_els_ndof_(NULL),
  b_els_numlosthits_(NULL),
  b_els_numvalhits_(NULL),
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
  b_genHT_(NULL),
  b_greedymuonfilter_decision_(NULL),
  b_hbhefilter_decision_(NULL),
  b_hcallaserfilter_decision_(NULL),
  b_inconsistentPFmuonfilter_decision_(NULL),
  b_isotk_charge_(NULL),
  b_isotk_dzpv_(NULL),
  b_isotk_eta_(NULL),
  b_isotk_iso_(NULL),
  b_isotk_phi_(NULL),
  b_isotk_pt_(NULL),
  b_jets_AK5PF_area_(NULL),
  b_jets_AK5PF_btag_TC_highEff_(NULL),
  b_jets_AK5PF_btag_TC_highPur_(NULL),
  b_jets_AK5PF_btag_jetBProb_(NULL),
  b_jets_AK5PF_btag_jetProb_(NULL),
  b_jets_AK5PF_btag_secVertexCombined_(NULL),
  b_jets_AK5PF_btag_secVertexHighEff_(NULL),
  b_jets_AK5PF_btag_secVertexHighPur_(NULL),
  b_jets_AK5PF_btag_softEle_(NULL),
  b_jets_AK5PF_btag_softMuon_(NULL),
  b_jets_AK5PF_chgEmE_(NULL),
  b_jets_AK5PF_chgHadE_(NULL),
  b_jets_AK5PF_chgMuE_(NULL),
  b_jets_AK5PF_chg_Mult_(NULL),
  b_jets_AK5PF_corrFactorRaw_(NULL),
  b_jets_AK5PF_ehf_(NULL),
  b_jets_AK5PF_emf_(NULL),
  b_jets_AK5PF_energy_(NULL),
  b_jets_AK5PF_et_(NULL),
  b_jets_AK5PF_eta_(NULL),
  b_jets_AK5PF_etaetaMoment_(NULL),
  b_jets_AK5PF_etaphiMoment_(NULL),
  b_jets_AK5PF_fHPD_(NULL),
  b_jets_AK5PF_fRBX_(NULL),
  b_jets_AK5PF_fSubDetector1_(NULL),
  b_jets_AK5PF_fSubDetector2_(NULL),
  b_jets_AK5PF_fSubDetector3_(NULL),
  b_jets_AK5PF_fSubDetector4_(NULL),
  b_jets_AK5PF_gen_Energy_(NULL),
  b_jets_AK5PF_gen_Id_(NULL),
  b_jets_AK5PF_gen_et_(NULL),
  b_jets_AK5PF_gen_eta_(NULL),
  b_jets_AK5PF_gen_mass_(NULL),
  b_jets_AK5PF_gen_motherID_(NULL),
  b_jets_AK5PF_gen_phi_(NULL),
  b_jets_AK5PF_gen_pt_(NULL),
  b_jets_AK5PF_gen_threeCharge_(NULL),
  b_jets_AK5PF_hitsInN90_(NULL),
  b_jets_AK5PF_jetCharge_(NULL),
  b_jets_AK5PF_mass_(NULL),
  b_jets_AK5PF_mu_Mult_(NULL),
  b_jets_AK5PF_n60_(NULL),
  b_jets_AK5PF_n90_(NULL),
  b_jets_AK5PF_n90Hits_(NULL),
  b_jets_AK5PF_nECALTowers_(NULL),
  b_jets_AK5PF_nHCALTowers_(NULL),
  b_jets_AK5PF_neutralEmE_(NULL),
  b_jets_AK5PF_neutralHadE_(NULL),
  b_jets_AK5PF_neutral_Mult_(NULL),
  b_jets_AK5PF_partonFlavour_(NULL),
  b_jets_AK5PF_parton_Energy_(NULL),
  b_jets_AK5PF_parton_Id_(NULL),
  b_jets_AK5PF_parton_eta_(NULL),
  b_jets_AK5PF_parton_mass_(NULL),
  b_jets_AK5PF_parton_motherId_(NULL),
  b_jets_AK5PF_parton_phi_(NULL),
  b_jets_AK5PF_parton_pt_(NULL),
  b_jets_AK5PF_phi_(NULL),
  b_jets_AK5PF_phiphiMoment_(NULL),
  b_jets_AK5PF_photonEnergy_(NULL),
  b_jets_AK5PF_pt_(NULL),
  b_jets_AK5PF_px_(NULL),
  b_jets_AK5PF_py_(NULL),
  b_jets_AK5PF_pz_(NULL),
  b_jets_AK5PF_rawPt_(NULL),
  b_jets_AK5PF_status_(NULL),
  b_jets_AK5PF_theta_(NULL),
  b_jets_AK5PFclean_Uncert_(NULL),
  b_jets_AK5PFclean_area_(NULL),
  b_jets_AK5PFclean_btag_TC_highEff_(NULL),
  b_jets_AK5PFclean_btag_TC_highPur_(NULL),
  b_jets_AK5PFclean_btag_jetBProb_(NULL),
  b_jets_AK5PFclean_btag_jetProb_(NULL),
  b_jets_AK5PFclean_btag_secVertexCombined_(NULL),
  b_jets_AK5PFclean_btag_secVertexHighEff_(NULL),
  b_jets_AK5PFclean_btag_secVertexHighPur_(NULL),
  b_jets_AK5PFclean_btag_softEle_(NULL),
  b_jets_AK5PFclean_btag_softMuon_(NULL),
  b_jets_AK5PFclean_chgEmE_(NULL),
  b_jets_AK5PFclean_chgHadE_(NULL),
  b_jets_AK5PFclean_chgMuE_(NULL),
  b_jets_AK5PFclean_chg_Mult_(NULL),
  b_jets_AK5PFclean_corrFactorRaw_(NULL),
  b_jets_AK5PFclean_corrL1FastL2L3_(NULL),
  b_jets_AK5PFclean_corrL1FastL2L3Residual_(NULL),
  b_jets_AK5PFclean_corrL1L2L3_(NULL),
  b_jets_AK5PFclean_corrL1L2L3Residual_(NULL),
  b_jets_AK5PFclean_corrL2L3_(NULL),
  b_jets_AK5PFclean_corrL2L3Residual_(NULL),
  b_jets_AK5PFclean_ehf_(NULL),
  b_jets_AK5PFclean_emf_(NULL),
  b_jets_AK5PFclean_energy_(NULL),
  b_jets_AK5PFclean_et_(NULL),
  b_jets_AK5PFclean_eta_(NULL),
  b_jets_AK5PFclean_etaetaMoment_(NULL),
  b_jets_AK5PFclean_etaphiMoment_(NULL),
  b_jets_AK5PFclean_fHPD_(NULL),
  b_jets_AK5PFclean_fRBX_(NULL),
  b_jets_AK5PFclean_fSubDetector1_(NULL),
  b_jets_AK5PFclean_fSubDetector2_(NULL),
  b_jets_AK5PFclean_fSubDetector3_(NULL),
  b_jets_AK5PFclean_fSubDetector4_(NULL),
  b_jets_AK5PFclean_gen_Energy_(NULL),
  b_jets_AK5PFclean_gen_Id_(NULL),
  b_jets_AK5PFclean_gen_et_(NULL),
  b_jets_AK5PFclean_gen_eta_(NULL),
  b_jets_AK5PFclean_gen_mass_(NULL),
  b_jets_AK5PFclean_gen_phi_(NULL),
  b_jets_AK5PFclean_gen_pt_(NULL),
  b_jets_AK5PFclean_hitsInN90_(NULL),
  b_jets_AK5PFclean_jetCharge_(NULL),
  b_jets_AK5PFclean_mass_(NULL),
  b_jets_AK5PFclean_mu_Mult_(NULL),
  b_jets_AK5PFclean_n60_(NULL),
  b_jets_AK5PFclean_n90_(NULL),
  b_jets_AK5PFclean_n90Hits_(NULL),
  b_jets_AK5PFclean_nECALTowers_(NULL),
  b_jets_AK5PFclean_nHCALTowers_(NULL),
  b_jets_AK5PFclean_neutralEmE_(NULL),
  b_jets_AK5PFclean_neutralHadE_(NULL),
  b_jets_AK5PFclean_neutral_Mult_(NULL),
  b_jets_AK5PFclean_partonFlavour_(NULL),
  b_jets_AK5PFclean_parton_Energy_(NULL),
  b_jets_AK5PFclean_parton_Id_(NULL),
  b_jets_AK5PFclean_parton_eta_(NULL),
  b_jets_AK5PFclean_parton_mass_(NULL),
  b_jets_AK5PFclean_parton_motherId_(NULL),
  b_jets_AK5PFclean_parton_phi_(NULL),
  b_jets_AK5PFclean_parton_pt_(NULL),
  b_jets_AK5PFclean_phi_(NULL),
  b_jets_AK5PFclean_phiphiMoment_(NULL),
  b_jets_AK5PFclean_photonEnergy_(NULL),
  b_jets_AK5PFclean_pt_(NULL),
  b_jets_AK5PFclean_px_(NULL),
  b_jets_AK5PFclean_py_(NULL),
  b_jets_AK5PFclean_pz_(NULL),
  b_jets_AK5PFclean_rawPt_(NULL),
  b_jets_AK5PFclean_status_(NULL),
  b_jets_AK5PFclean_theta_(NULL),
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
  b_mc_pdf_id1_(NULL),
  b_mc_pdf_id2_(NULL),
  b_mc_pdf_q_(NULL),
  b_mc_pdf_x1_(NULL),
  b_mc_pdf_x2_(NULL),
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
  b_metsHO_et_(NULL),
  b_metsHO_ex_(NULL),
  b_metsHO_ey_(NULL),
  b_metsHO_phi_(NULL),
  b_metsHO_sumEt_(NULL),
  b_mets_AK5_et_(NULL),
  b_mets_AK5_ex_(NULL),
  b_mets_AK5_ey_(NULL),
  b_mets_AK5_gen_et_(NULL),
  b_mets_AK5_gen_phi_(NULL),
  b_mets_AK5_phi_(NULL),
  b_mets_AK5_sign_(NULL),
  b_mets_AK5_sumEt_(NULL),
  b_mets_AK5_unCPhi_(NULL),
  b_mets_AK5_unCPt_(NULL),
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
  b_passprescaleHT250filter_decision_(NULL),
  b_passprescaleHT300filter_decision_(NULL),
  b_passprescaleHT350filter_decision_(NULL),
  b_passprescaleHT400filter_decision_(NULL),
  b_passprescaleHT450filter_decision_(NULL),
  b_passprescaleJet30MET80filter_decision_(NULL),
  b_passprescalePFHT350filter_decision_(NULL),
  b_pdfweights_cteq_(NULL),
  b_pdfweights_mstw_(NULL),
  b_pdfweights_nnpdf_(NULL),
  b_pfTypeINoXYCorrmets_et_(NULL),
  b_pfTypeINoXYCorrmets_ex_(NULL),
  b_pfTypeINoXYCorrmets_ey_(NULL),
  b_pfTypeINoXYCorrmets_gen_et_(NULL),
  b_pfTypeINoXYCorrmets_gen_phi_(NULL),
  b_pfTypeINoXYCorrmets_phi_(NULL),
  b_pfTypeINoXYCorrmets_sign_(NULL),
  b_pfTypeINoXYCorrmets_sumEt_(NULL),
  b_pfTypeINoXYCorrmets_unCPhi_(NULL),
  b_pfTypeINoXYCorrmets_unCPt_(NULL),
  b_pfTypeIType0mets_et_(NULL),
  b_pfTypeIType0mets_ex_(NULL),
  b_pfTypeIType0mets_ey_(NULL),
  b_pfTypeIType0mets_gen_et_(NULL),
  b_pfTypeIType0mets_gen_phi_(NULL),
  b_pfTypeIType0mets_phi_(NULL),
  b_pfTypeIType0mets_sign_(NULL),
  b_pfTypeIType0mets_sumEt_(NULL),
  b_pfTypeIType0mets_unCPhi_(NULL),
  b_pfTypeIType0mets_unCPt_(NULL),
  b_pfTypeImets_et_(NULL),
  b_pfTypeImets_ex_(NULL),
  b_pfTypeImets_ey_(NULL),
  b_pfTypeImets_gen_et_(NULL),
  b_pfTypeImets_gen_phi_(NULL),
  b_pfTypeImets_phi_(NULL),
  b_pfTypeImets_sign_(NULL),
  b_pfTypeImets_sumEt_(NULL),
  b_pfTypeImets_unCPhi_(NULL),
  b_pfTypeImets_unCPt_(NULL),
  b_pf_els_PATpassConversionVeto_(NULL),
  b_pf_els_PFchargedHadronIsoR03_(NULL),
  b_pf_els_PFneutralHadronIsoR03_(NULL),
  b_pf_els_PFphotonIsoR03_(NULL),
  b_pf_els_basicClustersSize_(NULL),
  b_pf_els_cIso_(NULL),
  b_pf_els_caloEnergy_(NULL),
  b_pf_els_charge_(NULL),
  b_pf_els_chargedHadronIso_(NULL),
  b_pf_els_chi2_(NULL),
  b_pf_els_core_ecalDrivenSeed_(NULL),
  b_pf_els_cpx_(NULL),
  b_pf_els_cpy_(NULL),
  b_pf_els_cpz_(NULL),
  b_pf_els_ctf_tk_charge_(NULL),
  b_pf_els_ctf_tk_eta_(NULL),
  b_pf_els_ctf_tk_id_(NULL),
  b_pf_els_ctf_tk_phi_(NULL),
  b_pf_els_cx_(NULL),
  b_pf_els_cy_(NULL),
  b_pf_els_cz_(NULL),
  b_pf_els_d0dum_(NULL),
  b_pf_els_d0dumError_(NULL),
  b_pf_els_dEtaIn_(NULL),
  b_pf_els_dEtaOut_(NULL),
  b_pf_els_dPhiIn_(NULL),
  b_pf_els_dPhiOut_(NULL),
  b_pf_els_dr03EcalRecHitSumEt_(NULL),
  b_pf_els_dr03HcalDepth1TowerSumEt_(NULL),
  b_pf_els_dr03HcalDepth2TowerSumEt_(NULL),
  b_pf_els_dr03HcalTowerSumEt_(NULL),
  b_pf_els_dr03TkSumPt_(NULL),
  b_pf_els_dr04EcalRecHitSumEt_(NULL),
  b_pf_els_dr04HcalDepth1TowerSumEt_(NULL),
  b_pf_els_dr04HcalDepth2TowerSumEt_(NULL),
  b_pf_els_dr04HcalTowerSumEt_(NULL),
  b_pf_els_dr04TkSumPt_(NULL),
  b_pf_els_dz_(NULL),
  b_pf_els_dzError_(NULL),
  b_pf_els_eOverPIn_(NULL),
  b_pf_els_eSeedOverPOut_(NULL),
  b_pf_els_ecalIso_(NULL),
  b_pf_els_energy_(NULL),
  b_pf_els_et_(NULL),
  b_pf_els_eta_(NULL),
  b_pf_els_etaError_(NULL),
  b_pf_els_fbrem_(NULL),
  b_pf_els_gen_et_(NULL),
  b_pf_els_gen_eta_(NULL),
  b_pf_els_gen_id_(NULL),
  b_pf_els_gen_mother_et_(NULL),
  b_pf_els_gen_mother_eta_(NULL),
  b_pf_els_gen_mother_id_(NULL),
  b_pf_els_gen_mother_phi_(NULL),
  b_pf_els_gen_mother_pt_(NULL),
  b_pf_els_gen_mother_px_(NULL),
  b_pf_els_gen_mother_py_(NULL),
  b_pf_els_gen_mother_pz_(NULL),
  b_pf_els_gen_mother_theta_(NULL),
  b_pf_els_gen_phi_(NULL),
  b_pf_els_gen_pt_(NULL),
  b_pf_els_gen_px_(NULL),
  b_pf_els_gen_py_(NULL),
  b_pf_els_gen_pz_(NULL),
  b_pf_els_gen_theta_(NULL),
  b_pf_els_hadOverEm_(NULL),
  b_pf_els_hasMatchedConversion_(NULL),
  b_pf_els_hcalIso_(NULL),
  b_pf_els_hcalOverEcalBc_(NULL),
  b_pf_els_isEB_(NULL),
  b_pf_els_isEE_(NULL),
  b_pf_els_looseId_(NULL),
  b_pf_els_n_inner_layer_(NULL),
  b_pf_els_n_outer_layer_(NULL),
  b_pf_els_ndof_(NULL),
  b_pf_els_neutralHadronIso_(NULL),
  b_pf_els_numlosthits_(NULL),
  b_pf_els_numvalhits_(NULL),
  b_pf_els_phi_(NULL),
  b_pf_els_phiError_(NULL),
  b_pf_els_photonIso_(NULL),
  b_pf_els_pt_(NULL),
  b_pf_els_ptError_(NULL),
  b_pf_els_px_(NULL),
  b_pf_els_py_(NULL),
  b_pf_els_pz_(NULL),
  b_pf_els_robustHighEnergyId_(NULL),
  b_pf_els_robustLooseId_(NULL),
  b_pf_els_robustTightId_(NULL),
  b_pf_els_scE1x5_(NULL),
  b_pf_els_scE2x5Max_(NULL),
  b_pf_els_scE5x5_(NULL),
  b_pf_els_scEnergy_(NULL),
  b_pf_els_scEta_(NULL),
  b_pf_els_scEtaWidth_(NULL),
  b_pf_els_scPhi_(NULL),
  b_pf_els_scPhiWidth_(NULL),
  b_pf_els_scRawEnergy_(NULL),
  b_pf_els_scSeedEnergy_(NULL),
  b_pf_els_shFracInnerHits_(NULL),
  b_pf_els_sigmaEtaEta_(NULL),
  b_pf_els_sigmaIEtaIEta_(NULL),
  b_pf_els_simpleEleId60cIso_(NULL),
  b_pf_els_simpleEleId60relIso_(NULL),
  b_pf_els_simpleEleId70cIso_(NULL),
  b_pf_els_simpleEleId70relIso_(NULL),
  b_pf_els_simpleEleId80cIso_(NULL),
  b_pf_els_simpleEleId80relIso_(NULL),
  b_pf_els_simpleEleId85cIso_(NULL),
  b_pf_els_simpleEleId85relIso_(NULL),
  b_pf_els_simpleEleId90cIso_(NULL),
  b_pf_els_simpleEleId90relIso_(NULL),
  b_pf_els_simpleEleId95cIso_(NULL),
  b_pf_els_simpleEleId95relIso_(NULL),
  b_pf_els_status_(NULL),
  b_pf_els_tIso_(NULL),
  b_pf_els_theta_(NULL),
  b_pf_els_tightId_(NULL),
  b_pf_els_tk_charge_(NULL),
  b_pf_els_tk_eta_(NULL),
  b_pf_els_tk_phi_(NULL),
  b_pf_els_tk_pt_(NULL),
  b_pf_els_tk_pz_(NULL),
  b_pf_els_vpx_(NULL),
  b_pf_els_vpy_(NULL),
  b_pf_els_vpz_(NULL),
  b_pf_els_vx_(NULL),
  b_pf_els_vy_(NULL),
  b_pf_els_vz_(NULL),
  b_pf_mus_cIso_(NULL),
  b_pf_mus_calEnergyEm_(NULL),
  b_pf_mus_calEnergyEmS9_(NULL),
  b_pf_mus_calEnergyHad_(NULL),
  b_pf_mus_calEnergyHadS9_(NULL),
  b_pf_mus_calEnergyHo_(NULL),
  b_pf_mus_calEnergyHoS9_(NULL),
  b_pf_mus_charge_(NULL),
  b_pf_mus_chargedHadronIso_(NULL),
  b_pf_mus_cm_ExpectedHitsInner_(NULL),
  b_pf_mus_cm_ExpectedHitsOuter_(NULL),
  b_pf_mus_cm_LayersWithMeasurement_(NULL),
  b_pf_mus_cm_LayersWithoutMeasurement_(NULL),
  b_pf_mus_cm_PixelLayersWithMeasurement_(NULL),
  b_pf_mus_cm_ValidStripLayersWithMonoAndStereoHit_(NULL),
  b_pf_mus_cm_chg_(NULL),
  b_pf_mus_cm_chi2_(NULL),
  b_pf_mus_cm_d0dum_(NULL),
  b_pf_mus_cm_d0dumErr_(NULL),
  b_pf_mus_cm_dz_(NULL),
  b_pf_mus_cm_dzErr_(NULL),
  b_pf_mus_cm_eta_(NULL),
  b_pf_mus_cm_etaErr_(NULL),
  b_pf_mus_cm_ndof_(NULL),
  b_pf_mus_cm_numlosthits_(NULL),
  b_pf_mus_cm_numvalMuonhits_(NULL),
  b_pf_mus_cm_numvalhits_(NULL),
  b_pf_mus_cm_phi_(NULL),
  b_pf_mus_cm_phiErr_(NULL),
  b_pf_mus_cm_pt_(NULL),
  b_pf_mus_cm_ptErr_(NULL),
  b_pf_mus_cm_px_(NULL),
  b_pf_mus_cm_py_(NULL),
  b_pf_mus_cm_pz_(NULL),
  b_pf_mus_cm_theta_(NULL),
  b_pf_mus_cm_vx_(NULL),
  b_pf_mus_cm_vy_(NULL),
  b_pf_mus_cm_vz_(NULL),
  b_pf_mus_dB_(NULL),
  b_pf_mus_ecalIso_(NULL),
  b_pf_mus_energy_(NULL),
  b_pf_mus_et_(NULL),
  b_pf_mus_eta_(NULL),
  b_pf_mus_gen_et_(NULL),
  b_pf_mus_gen_eta_(NULL),
  b_pf_mus_gen_id_(NULL),
  b_pf_mus_gen_mother_et_(NULL),
  b_pf_mus_gen_mother_eta_(NULL),
  b_pf_mus_gen_mother_id_(NULL),
  b_pf_mus_gen_mother_phi_(NULL),
  b_pf_mus_gen_mother_pt_(NULL),
  b_pf_mus_gen_mother_px_(NULL),
  b_pf_mus_gen_mother_py_(NULL),
  b_pf_mus_gen_mother_pz_(NULL),
  b_pf_mus_gen_mother_theta_(NULL),
  b_pf_mus_gen_phi_(NULL),
  b_pf_mus_gen_pt_(NULL),
  b_pf_mus_gen_px_(NULL),
  b_pf_mus_gen_py_(NULL),
  b_pf_mus_gen_pz_(NULL),
  b_pf_mus_gen_theta_(NULL),
  b_pf_mus_hcalIso_(NULL),
  b_pf_mus_id_All_(NULL),
  b_pf_mus_id_AllArbitrated_(NULL),
  b_pf_mus_id_AllGlobalMuons_(NULL),
  b_pf_mus_id_AllStandAloneMuons_(NULL),
  b_pf_mus_id_AllTrackerMuons_(NULL),
  b_pf_mus_id_GlobalMuonPromptTight_(NULL),
  b_pf_mus_id_TM2DCompatibilityLoose_(NULL),
  b_pf_mus_id_TM2DCompatibilityTight_(NULL),
  b_pf_mus_id_TMLastStationLoose_(NULL),
  b_pf_mus_id_TMLastStationOptimizedLowPtLoose_(NULL),
  b_pf_mus_id_TMLastStationOptimizedLowPtTight_(NULL),
  b_pf_mus_id_TMLastStationTight_(NULL),
  b_pf_mus_id_TMOneStationLoose_(NULL),
  b_pf_mus_id_TMOneStationTight_(NULL),
  b_pf_mus_id_TrackerMuonArbitrated_(NULL),
  b_pf_mus_isCaloMuon_(NULL),
  b_pf_mus_isConvertedPhoton_(NULL),
  b_pf_mus_isElectron_(NULL),
  b_pf_mus_isGlobalMuon_(NULL),
  b_pf_mus_isPFMuon_(NULL),
  b_pf_mus_isPhoton_(NULL),
  b_pf_mus_isStandAloneMuon_(NULL),
  b_pf_mus_isTrackerMuon_(NULL),
  b_pf_mus_iso03_emEt_(NULL),
  b_pf_mus_iso03_emVetoEt_(NULL),
  b_pf_mus_iso03_hadEt_(NULL),
  b_pf_mus_iso03_hadVetoEt_(NULL),
  b_pf_mus_iso03_hoEt_(NULL),
  b_pf_mus_iso03_nTracks_(NULL),
  b_pf_mus_iso03_sumPt_(NULL),
  b_pf_mus_iso05_emEt_(NULL),
  b_pf_mus_iso05_hadEt_(NULL),
  b_pf_mus_iso05_hoEt_(NULL),
  b_pf_mus_iso05_nTracks_(NULL),
  b_pf_mus_iso05_sumPt_(NULL),
  b_pf_mus_neutralHadronIso_(NULL),
  b_pf_mus_num_matches_(NULL),
  b_pf_mus_numberOfMatchedStations_(NULL),
  b_pf_mus_pfIsolationR03_sumChargedHadronPt_(NULL),
  b_pf_mus_pfIsolationR03_sumChargedParticlePt_(NULL),
  b_pf_mus_pfIsolationR03_sumNeutralHadronEt_(NULL),
  b_pf_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_(NULL),
  b_pf_mus_pfIsolationR03_sumPUPt_(NULL),
  b_pf_mus_pfIsolationR03_sumPhotonEt_(NULL),
  b_pf_mus_pfIsolationR03_sumPhotonEtHighThreshold_(NULL),
  b_pf_mus_pfIsolationR04_sumChargedHadronPt_(NULL),
  b_pf_mus_pfIsolationR04_sumChargedParticlePt_(NULL),
  b_pf_mus_pfIsolationR04_sumNeutralHadronEt_(NULL),
  b_pf_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_(NULL),
  b_pf_mus_pfIsolationR04_sumPUPt_(NULL),
  b_pf_mus_pfIsolationR04_sumPhotonEt_(NULL),
  b_pf_mus_pfIsolationR04_sumPhotonEtHighThreshold_(NULL),
  b_pf_mus_phi_(NULL),
  b_pf_mus_photonIso_(NULL),
  b_pf_mus_picky_ExpectedHitsInner_(NULL),
  b_pf_mus_picky_ExpectedHitsOuter_(NULL),
  b_pf_mus_picky_LayersWithMeasurement_(NULL),
  b_pf_mus_picky_LayersWithoutMeasurement_(NULL),
  b_pf_mus_picky_PixelLayersWithMeasurement_(NULL),
  b_pf_mus_picky_ValidStripLayersWithMonoAndStereoHit_(NULL),
  b_pf_mus_picky_chg_(NULL),
  b_pf_mus_picky_chi2_(NULL),
  b_pf_mus_picky_d0dum_(NULL),
  b_pf_mus_picky_d0dumErr_(NULL),
  b_pf_mus_picky_dz_(NULL),
  b_pf_mus_picky_dzErr_(NULL),
  b_pf_mus_picky_eta_(NULL),
  b_pf_mus_picky_etaErr_(NULL),
  b_pf_mus_picky_id_(NULL),
  b_pf_mus_picky_ndof_(NULL),
  b_pf_mus_picky_numlosthits_(NULL),
  b_pf_mus_picky_numvalPixelhits_(NULL),
  b_pf_mus_picky_numvalhits_(NULL),
  b_pf_mus_picky_phi_(NULL),
  b_pf_mus_picky_phiErr_(NULL),
  b_pf_mus_picky_pt_(NULL),
  b_pf_mus_picky_ptErr_(NULL),
  b_pf_mus_picky_px_(NULL),
  b_pf_mus_picky_py_(NULL),
  b_pf_mus_picky_pz_(NULL),
  b_pf_mus_picky_theta_(NULL),
  b_pf_mus_picky_vx_(NULL),
  b_pf_mus_picky_vy_(NULL),
  b_pf_mus_picky_vz_(NULL),
  b_pf_mus_pt_(NULL),
  b_pf_mus_px_(NULL),
  b_pf_mus_py_(NULL),
  b_pf_mus_pz_(NULL),
  b_pf_mus_stamu_chg_(NULL),
  b_pf_mus_stamu_chi2_(NULL),
  b_pf_mus_stamu_d0dum_(NULL),
  b_pf_mus_stamu_d0dumErr_(NULL),
  b_pf_mus_stamu_dz_(NULL),
  b_pf_mus_stamu_dzErr_(NULL),
  b_pf_mus_stamu_eta_(NULL),
  b_pf_mus_stamu_etaErr_(NULL),
  b_pf_mus_stamu_ndof_(NULL),
  b_pf_mus_stamu_numlosthits_(NULL),
  b_pf_mus_stamu_numvalhits_(NULL),
  b_pf_mus_stamu_phi_(NULL),
  b_pf_mus_stamu_phiErr_(NULL),
  b_pf_mus_stamu_pt_(NULL),
  b_pf_mus_stamu_ptErr_(NULL),
  b_pf_mus_stamu_px_(NULL),
  b_pf_mus_stamu_py_(NULL),
  b_pf_mus_stamu_pz_(NULL),
  b_pf_mus_stamu_theta_(NULL),
  b_pf_mus_stamu_vx_(NULL),
  b_pf_mus_stamu_vy_(NULL),
  b_pf_mus_stamu_vz_(NULL),
  b_pf_mus_status_(NULL),
  b_pf_mus_tIso_(NULL),
  b_pf_mus_theta_(NULL),
  b_pf_mus_tkHits_(NULL),
  b_pf_mus_tk_ExpectedHitsInner_(NULL),
  b_pf_mus_tk_ExpectedHitsOuter_(NULL),
  b_pf_mus_tk_LayersWithMeasurement_(NULL),
  b_pf_mus_tk_LayersWithoutMeasurement_(NULL),
  b_pf_mus_tk_PixelLayersWithMeasurement_(NULL),
  b_pf_mus_tk_ValidStripLayersWithMonoAndStereoHit_(NULL),
  b_pf_mus_tk_chg_(NULL),
  b_pf_mus_tk_chi2_(NULL),
  b_pf_mus_tk_d0dum_(NULL),
  b_pf_mus_tk_d0dumErr_(NULL),
  b_pf_mus_tk_dz_(NULL),
  b_pf_mus_tk_dzErr_(NULL),
  b_pf_mus_tk_eta_(NULL),
  b_pf_mus_tk_etaErr_(NULL),
  b_pf_mus_tk_id_(NULL),
  b_pf_mus_tk_ndof_(NULL),
  b_pf_mus_tk_numlosthits_(NULL),
  b_pf_mus_tk_numpixelWthMeasr_(NULL),
  b_pf_mus_tk_numvalPixelhits_(NULL),
  b_pf_mus_tk_numvalhits_(NULL),
  b_pf_mus_tk_phi_(NULL),
  b_pf_mus_tk_phiErr_(NULL),
  b_pf_mus_tk_pt_(NULL),
  b_pf_mus_tk_ptErr_(NULL),
  b_pf_mus_tk_px_(NULL),
  b_pf_mus_tk_py_(NULL),
  b_pf_mus_tk_pz_(NULL),
  b_pf_mus_tk_theta_(NULL),
  b_pf_mus_tk_vx_(NULL),
  b_pf_mus_tk_vy_(NULL),
  b_pf_mus_tk_vz_(NULL),
  b_pf_mus_tpfms_ExpectedHitsInner_(NULL),
  b_pf_mus_tpfms_ExpectedHitsOuter_(NULL),
  b_pf_mus_tpfms_LayersWithMeasurement_(NULL),
  b_pf_mus_tpfms_LayersWithoutMeasurement_(NULL),
  b_pf_mus_tpfms_PixelLayersWithMeasurement_(NULL),
  b_pf_mus_tpfms_ValidStripLayersWithMonoAndStereoHit_(NULL),
  b_pf_mus_tpfms_chg_(NULL),
  b_pf_mus_tpfms_chi2_(NULL),
  b_pf_mus_tpfms_d0dum_(NULL),
  b_pf_mus_tpfms_d0dumErr_(NULL),
  b_pf_mus_tpfms_dz_(NULL),
  b_pf_mus_tpfms_dzErr_(NULL),
  b_pf_mus_tpfms_eta_(NULL),
  b_pf_mus_tpfms_etaErr_(NULL),
  b_pf_mus_tpfms_id_(NULL),
  b_pf_mus_tpfms_ndof_(NULL),
  b_pf_mus_tpfms_numlosthits_(NULL),
  b_pf_mus_tpfms_numvalPixelhits_(NULL),
  b_pf_mus_tpfms_numvalhits_(NULL),
  b_pf_mus_tpfms_phi_(NULL),
  b_pf_mus_tpfms_phiErr_(NULL),
  b_pf_mus_tpfms_pt_(NULL),
  b_pf_mus_tpfms_ptErr_(NULL),
  b_pf_mus_tpfms_px_(NULL),
  b_pf_mus_tpfms_py_(NULL),
  b_pf_mus_tpfms_pz_(NULL),
  b_pf_mus_tpfms_theta_(NULL),
  b_pf_mus_tpfms_vx_(NULL),
  b_pf_mus_tpfms_vy_(NULL),
  b_pf_mus_tpfms_vz_(NULL),
  b_pf_photons_chIso_(NULL),
  b_pf_photons_e1x5_(NULL),
  b_pf_photons_e2x5_(NULL),
  b_pf_photons_e3x3_(NULL),
  b_pf_photons_e5x5_(NULL),
  b_pf_photons_energy_(NULL),
  b_pf_photons_et_(NULL),
  b_pf_photons_eta_(NULL),
  b_pf_photons_hadOverEM_(NULL),
  b_pf_photons_hadTowOverEM_(NULL),
  b_pf_photons_hasPixelSeed_(NULL),
  b_pf_photons_isAlsoElectron_(NULL),
  b_pf_photons_isConverted_(NULL),
  b_pf_photons_isEBEEGap_(NULL),
  b_pf_photons_isEBGap_(NULL),
  b_pf_photons_isEBPho_(NULL),
  b_pf_photons_isEEGap_(NULL),
  b_pf_photons_isEEPho_(NULL),
  b_pf_photons_maxEnergyXtal_(NULL),
  b_pf_photons_nhIso_(NULL),
  b_pf_photons_phIso_(NULL),
  b_pf_photons_phi_(NULL),
  b_pf_photons_pt_(NULL),
  b_pf_photons_px_(NULL),
  b_pf_photons_py_(NULL),
  b_pf_photons_pz_(NULL),
  b_pf_photons_r9_(NULL),
  b_pf_photons_scEnergy_(NULL),
  b_pf_photons_scEta_(NULL),
  b_pf_photons_scEtaWidth_(NULL),
  b_pf_photons_scPhi_(NULL),
  b_pf_photons_scPhiWidth_(NULL),
  b_pf_photons_scRawEnergy_(NULL),
  b_pf_photons_sigmaEtaEta_(NULL),
  b_pf_photons_sigmaIetaIeta_(NULL),
  b_pf_photons_status_(NULL),
  b_pf_photons_theta_(NULL),
  b_pfcand_charge_(NULL),
  b_pfcand_energy_(NULL),
  b_pfcand_eta_(NULL),
  b_pfcand_particleId_(NULL),
  b_pfcand_pdgId_(NULL),
  b_pfcand_phi_(NULL),
  b_pfcand_pt_(NULL),
  b_pfcand_px_(NULL),
  b_pfcand_py_(NULL),
  b_pfcand_pz_(NULL),
  b_pfcand_theta_(NULL),
  b_pfmets_et_(NULL),
  b_pfmets_ex_(NULL),
  b_pfmets_ey_(NULL),
  b_pfmets_fullSignif_(NULL),
  b_pfmets_fullSignifCov00_(NULL),
  b_pfmets_fullSignifCov00_2012_(NULL),
  b_pfmets_fullSignifCov00_2012_dataRes_(NULL),
  b_pfmets_fullSignifCov10_(NULL),
  b_pfmets_fullSignifCov10_2012_(NULL),
  b_pfmets_fullSignifCov10_2012_dataRes_(NULL),
  b_pfmets_fullSignifCov11_(NULL),
  b_pfmets_fullSignifCov11_2012_(NULL),
  b_pfmets_fullSignifCov11_2012_dataRes_(NULL),
  b_pfmets_fullSignif_2012_(NULL),
  b_pfmets_fullSignif_2012_dataRes_(NULL),
  b_pfmets_gen_et_(NULL),
  b_pfmets_gen_phi_(NULL),
  b_pfmets_phi_(NULL),
  b_pfmets_sign_(NULL),
  b_pfmets_sumEt_(NULL),
  b_pfmets_unCPhi_(NULL),
  b_pfmets_unCPt_(NULL),
  b_photon_chIsoValues_(NULL),
  b_photon_nhIsoValues_(NULL),
  b_photon_passElectronVeto_(NULL),
  b_photon_phIsoValues_(NULL),
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
  b_puJet_rejectionBeta_(NULL),
  b_puJet_rejectionMVA_(NULL),
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
  b_rho_kt6PFJetsForIsolation2011_(NULL),
  b_rho_kt6PFJetsForIsolation2012_(NULL),
  b_run_(NULL),
  b_scrapingVeto_decision_(NULL),
  b_softjetUp_dMEx_(NULL),
  b_softjetUp_dMEy_(NULL),
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
  b_tcmets_et_(NULL),
  b_tcmets_ex_(NULL),
  b_tcmets_ey_(NULL),
  b_tcmets_phi_(NULL),
  b_tcmets_sumEt_(NULL),
  b_trackercoherentnoisefilter1_decision_(NULL),
  b_trackercoherentnoisefilter2_decision_(NULL),
  b_trackertoomanyclustersfilter_decision_(NULL),
  b_trackertoomanyseedsfilter_decision_(NULL),
  b_trackertoomanytripletsfilter_decision_(NULL),
  b_trackingfailurefilter_decision_(NULL),
  b_tracks_chg_(NULL),
  b_tracks_chi2_(NULL),
  b_tracks_d0dum_(NULL),
  b_tracks_d0dumErr_(NULL),
  b_tracks_dz_(NULL),
  b_tracks_dzErr_(NULL),
  b_tracks_eta_(NULL),
  b_tracks_etaErr_(NULL),
  b_tracks_highPurity_(NULL),
  b_tracks_ndof_(NULL),
  b_tracks_numlosthits_(NULL),
  b_tracks_numvalhits_(NULL),
  b_tracks_phi_(NULL),
  b_tracks_phiErr_(NULL),
  b_tracks_pt_(NULL),
  b_tracks_ptErr_(NULL),
  b_tracks_px_(NULL),
  b_tracks_py_(NULL),
  b_tracks_pz_(NULL),
  b_tracks_vx_(NULL),
  b_tracks_vy_(NULL),
  b_tracks_vz_(NULL),
  b_trigger_decision_(NULL),
  b_trigger_lastfiltername_(NULL),
  b_trigger_name_(NULL),
  b_trigger_prescalevalue_(NULL),
  b_triggerobject_collectionname_(NULL),
  b_triggerobject_energy_(NULL),
  b_triggerobject_et_(NULL),
  b_triggerobject_eta_(NULL),
  b_triggerobject_phi_(NULL),
  b_triggerobject_pt_(NULL),
  b_triggerobject_px_(NULL),
  b_triggerobject_py_(NULL),
  b_triggerobject_pz_(NULL),
  b_trk_nTOBTEC_(NULL),
  b_trk_ratioAllTOBTEC_(NULL),
  b_trk_ratioJetTOBTEC_(NULL),
  b_weight_(NULL),
  c_L1trigger_alias_(false),
  c_L1trigger_bit_(false),
  c_L1trigger_decision_(false),
  c_L1trigger_decision_nomask_(false),
  c_L1trigger_name_(false),
  c_L1trigger_prescalevalue_(false),
  c_L1trigger_techTrigger_(false),
  c_MPT_(false),
  c_NbeamSpot_(false),
  c_Nels_(false),
  c_Njets_AK5PF_(false),
  c_Njets_AK5PFclean_(false),
  c_Nmc_doc_(false),
  c_Nmc_electrons_(false),
  c_Nmc_mus_(false),
  c_Nmc_nues_(false),
  c_Nmc_numus_(false),
  c_Nmc_nutaus_(false),
  c_Nmc_pdf_(false),
  c_Nmc_photons_(false),
  c_Nmc_taus_(false),
  c_NmetsHO_(false),
  c_Nmets_AK5_(false),
  c_Nmus_(false),
  c_NpfTypeINoXYCorrmets_(false),
  c_NpfTypeIType0mets_(false),
  c_NpfTypeImets_(false),
  c_Npf_els_(false),
  c_Npf_mus_(false),
  c_Npf_photons_(false),
  c_Npfcand_(false),
  c_Npfmets_(false),
  c_Nphotons_(false),
  c_Npv_(false),
  c_Ntaus_(false),
  c_Ntcmets_(false),
  c_Ntracks_(false),
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
  c_ecalBEfilter_decision_(false),
  c_ecalTPfilter_decision_(false),
  c_ecallaserfilter_decision_(false),
  c_eebadscfilter_decision_(false),
  c_eenoisefilter_decision_(false),
  c_els_PATpassConversionVeto_(false),
  c_els_PFchargedHadronIsoR03_(false),
  c_els_PFneutralHadronIsoR03_(false),
  c_els_PFphotonIsoR03_(false),
  c_els_basicClustersSize_(false),
  c_els_cIso_(false),
  c_els_caloEnergy_(false),
  c_els_charge_(false),
  c_els_chi2_(false),
  c_els_conversion_dcot_(false),
  c_els_conversion_dist_(false),
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
  c_els_hasMatchedConversion_(false),
  c_els_hcalIso_(false),
  c_els_hcalOverEcalBc_(false),
  c_els_isEB_(false),
  c_els_isEE_(false),
  c_els_looseId_(false),
  c_els_n_inner_layer_(false),
  c_els_n_outer_layer_(false),
  c_els_ndof_(false),
  c_els_numlosthits_(false),
  c_els_numvalhits_(false),
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
  c_genHT_(false),
  c_greedymuonfilter_decision_(false),
  c_hbhefilter_decision_(false),
  c_hcallaserfilter_decision_(false),
  c_inconsistentPFmuonfilter_decision_(false),
  c_isotk_charge_(false),
  c_isotk_dzpv_(false),
  c_isotk_eta_(false),
  c_isotk_iso_(false),
  c_isotk_phi_(false),
  c_isotk_pt_(false),
  c_jets_AK5PF_area_(false),
  c_jets_AK5PF_btag_TC_highEff_(false),
  c_jets_AK5PF_btag_TC_highPur_(false),
  c_jets_AK5PF_btag_jetBProb_(false),
  c_jets_AK5PF_btag_jetProb_(false),
  c_jets_AK5PF_btag_secVertexCombined_(false),
  c_jets_AK5PF_btag_secVertexHighEff_(false),
  c_jets_AK5PF_btag_secVertexHighPur_(false),
  c_jets_AK5PF_btag_softEle_(false),
  c_jets_AK5PF_btag_softMuon_(false),
  c_jets_AK5PF_chgEmE_(false),
  c_jets_AK5PF_chgHadE_(false),
  c_jets_AK5PF_chgMuE_(false),
  c_jets_AK5PF_chg_Mult_(false),
  c_jets_AK5PF_corrFactorRaw_(false),
  c_jets_AK5PF_ehf_(false),
  c_jets_AK5PF_emf_(false),
  c_jets_AK5PF_energy_(false),
  c_jets_AK5PF_et_(false),
  c_jets_AK5PF_eta_(false),
  c_jets_AK5PF_etaetaMoment_(false),
  c_jets_AK5PF_etaphiMoment_(false),
  c_jets_AK5PF_fHPD_(false),
  c_jets_AK5PF_fRBX_(false),
  c_jets_AK5PF_fSubDetector1_(false),
  c_jets_AK5PF_fSubDetector2_(false),
  c_jets_AK5PF_fSubDetector3_(false),
  c_jets_AK5PF_fSubDetector4_(false),
  c_jets_AK5PF_gen_Energy_(false),
  c_jets_AK5PF_gen_Id_(false),
  c_jets_AK5PF_gen_et_(false),
  c_jets_AK5PF_gen_eta_(false),
  c_jets_AK5PF_gen_mass_(false),
  c_jets_AK5PF_gen_motherID_(false),
  c_jets_AK5PF_gen_phi_(false),
  c_jets_AK5PF_gen_pt_(false),
  c_jets_AK5PF_gen_threeCharge_(false),
  c_jets_AK5PF_hitsInN90_(false),
  c_jets_AK5PF_jetCharge_(false),
  c_jets_AK5PF_mass_(false),
  c_jets_AK5PF_mu_Mult_(false),
  c_jets_AK5PF_n60_(false),
  c_jets_AK5PF_n90_(false),
  c_jets_AK5PF_n90Hits_(false),
  c_jets_AK5PF_nECALTowers_(false),
  c_jets_AK5PF_nHCALTowers_(false),
  c_jets_AK5PF_neutralEmE_(false),
  c_jets_AK5PF_neutralHadE_(false),
  c_jets_AK5PF_neutral_Mult_(false),
  c_jets_AK5PF_partonFlavour_(false),
  c_jets_AK5PF_parton_Energy_(false),
  c_jets_AK5PF_parton_Id_(false),
  c_jets_AK5PF_parton_eta_(false),
  c_jets_AK5PF_parton_mass_(false),
  c_jets_AK5PF_parton_motherId_(false),
  c_jets_AK5PF_parton_phi_(false),
  c_jets_AK5PF_parton_pt_(false),
  c_jets_AK5PF_phi_(false),
  c_jets_AK5PF_phiphiMoment_(false),
  c_jets_AK5PF_photonEnergy_(false),
  c_jets_AK5PF_pt_(false),
  c_jets_AK5PF_px_(false),
  c_jets_AK5PF_py_(false),
  c_jets_AK5PF_pz_(false),
  c_jets_AK5PF_rawPt_(false),
  c_jets_AK5PF_status_(false),
  c_jets_AK5PF_theta_(false),
  c_jets_AK5PFclean_Uncert_(false),
  c_jets_AK5PFclean_area_(false),
  c_jets_AK5PFclean_btag_TC_highEff_(false),
  c_jets_AK5PFclean_btag_TC_highPur_(false),
  c_jets_AK5PFclean_btag_jetBProb_(false),
  c_jets_AK5PFclean_btag_jetProb_(false),
  c_jets_AK5PFclean_btag_secVertexCombined_(false),
  c_jets_AK5PFclean_btag_secVertexHighEff_(false),
  c_jets_AK5PFclean_btag_secVertexHighPur_(false),
  c_jets_AK5PFclean_btag_softEle_(false),
  c_jets_AK5PFclean_btag_softMuon_(false),
  c_jets_AK5PFclean_chgEmE_(false),
  c_jets_AK5PFclean_chgHadE_(false),
  c_jets_AK5PFclean_chgMuE_(false),
  c_jets_AK5PFclean_chg_Mult_(false),
  c_jets_AK5PFclean_corrFactorRaw_(false),
  c_jets_AK5PFclean_corrL1FastL2L3_(false),
  c_jets_AK5PFclean_corrL1FastL2L3Residual_(false),
  c_jets_AK5PFclean_corrL1L2L3_(false),
  c_jets_AK5PFclean_corrL1L2L3Residual_(false),
  c_jets_AK5PFclean_corrL2L3_(false),
  c_jets_AK5PFclean_corrL2L3Residual_(false),
  c_jets_AK5PFclean_ehf_(false),
  c_jets_AK5PFclean_emf_(false),
  c_jets_AK5PFclean_energy_(false),
  c_jets_AK5PFclean_et_(false),
  c_jets_AK5PFclean_eta_(false),
  c_jets_AK5PFclean_etaetaMoment_(false),
  c_jets_AK5PFclean_etaphiMoment_(false),
  c_jets_AK5PFclean_fHPD_(false),
  c_jets_AK5PFclean_fRBX_(false),
  c_jets_AK5PFclean_fSubDetector1_(false),
  c_jets_AK5PFclean_fSubDetector2_(false),
  c_jets_AK5PFclean_fSubDetector3_(false),
  c_jets_AK5PFclean_fSubDetector4_(false),
  c_jets_AK5PFclean_gen_Energy_(false),
  c_jets_AK5PFclean_gen_Id_(false),
  c_jets_AK5PFclean_gen_et_(false),
  c_jets_AK5PFclean_gen_eta_(false),
  c_jets_AK5PFclean_gen_mass_(false),
  c_jets_AK5PFclean_gen_phi_(false),
  c_jets_AK5PFclean_gen_pt_(false),
  c_jets_AK5PFclean_hitsInN90_(false),
  c_jets_AK5PFclean_jetCharge_(false),
  c_jets_AK5PFclean_mass_(false),
  c_jets_AK5PFclean_mu_Mult_(false),
  c_jets_AK5PFclean_n60_(false),
  c_jets_AK5PFclean_n90_(false),
  c_jets_AK5PFclean_n90Hits_(false),
  c_jets_AK5PFclean_nECALTowers_(false),
  c_jets_AK5PFclean_nHCALTowers_(false),
  c_jets_AK5PFclean_neutralEmE_(false),
  c_jets_AK5PFclean_neutralHadE_(false),
  c_jets_AK5PFclean_neutral_Mult_(false),
  c_jets_AK5PFclean_partonFlavour_(false),
  c_jets_AK5PFclean_parton_Energy_(false),
  c_jets_AK5PFclean_parton_Id_(false),
  c_jets_AK5PFclean_parton_eta_(false),
  c_jets_AK5PFclean_parton_mass_(false),
  c_jets_AK5PFclean_parton_motherId_(false),
  c_jets_AK5PFclean_parton_phi_(false),
  c_jets_AK5PFclean_parton_pt_(false),
  c_jets_AK5PFclean_phi_(false),
  c_jets_AK5PFclean_phiphiMoment_(false),
  c_jets_AK5PFclean_photonEnergy_(false),
  c_jets_AK5PFclean_pt_(false),
  c_jets_AK5PFclean_px_(false),
  c_jets_AK5PFclean_py_(false),
  c_jets_AK5PFclean_pz_(false),
  c_jets_AK5PFclean_rawPt_(false),
  c_jets_AK5PFclean_status_(false),
  c_jets_AK5PFclean_theta_(false),
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
  c_mc_pdf_id1_(false),
  c_mc_pdf_id2_(false),
  c_mc_pdf_q_(false),
  c_mc_pdf_x1_(false),
  c_mc_pdf_x2_(false),
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
  c_metsHO_et_(false),
  c_metsHO_ex_(false),
  c_metsHO_ey_(false),
  c_metsHO_phi_(false),
  c_metsHO_sumEt_(false),
  c_mets_AK5_et_(false),
  c_mets_AK5_ex_(false),
  c_mets_AK5_ey_(false),
  c_mets_AK5_gen_et_(false),
  c_mets_AK5_gen_phi_(false),
  c_mets_AK5_phi_(false),
  c_mets_AK5_sign_(false),
  c_mets_AK5_sumEt_(false),
  c_mets_AK5_unCPhi_(false),
  c_mets_AK5_unCPt_(false),
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
  c_passprescaleHT250filter_decision_(false),
  c_passprescaleHT300filter_decision_(false),
  c_passprescaleHT350filter_decision_(false),
  c_passprescaleHT400filter_decision_(false),
  c_passprescaleHT450filter_decision_(false),
  c_passprescaleJet30MET80filter_decision_(false),
  c_passprescalePFHT350filter_decision_(false),
  c_pdfweights_cteq_(false),
  c_pdfweights_mstw_(false),
  c_pdfweights_nnpdf_(false),
  c_pfTypeINoXYCorrmets_et_(false),
  c_pfTypeINoXYCorrmets_ex_(false),
  c_pfTypeINoXYCorrmets_ey_(false),
  c_pfTypeINoXYCorrmets_gen_et_(false),
  c_pfTypeINoXYCorrmets_gen_phi_(false),
  c_pfTypeINoXYCorrmets_phi_(false),
  c_pfTypeINoXYCorrmets_sign_(false),
  c_pfTypeINoXYCorrmets_sumEt_(false),
  c_pfTypeINoXYCorrmets_unCPhi_(false),
  c_pfTypeINoXYCorrmets_unCPt_(false),
  c_pfTypeIType0mets_et_(false),
  c_pfTypeIType0mets_ex_(false),
  c_pfTypeIType0mets_ey_(false),
  c_pfTypeIType0mets_gen_et_(false),
  c_pfTypeIType0mets_gen_phi_(false),
  c_pfTypeIType0mets_phi_(false),
  c_pfTypeIType0mets_sign_(false),
  c_pfTypeIType0mets_sumEt_(false),
  c_pfTypeIType0mets_unCPhi_(false),
  c_pfTypeIType0mets_unCPt_(false),
  c_pfTypeImets_et_(false),
  c_pfTypeImets_ex_(false),
  c_pfTypeImets_ey_(false),
  c_pfTypeImets_gen_et_(false),
  c_pfTypeImets_gen_phi_(false),
  c_pfTypeImets_phi_(false),
  c_pfTypeImets_sign_(false),
  c_pfTypeImets_sumEt_(false),
  c_pfTypeImets_unCPhi_(false),
  c_pfTypeImets_unCPt_(false),
  c_pf_els_PATpassConversionVeto_(false),
  c_pf_els_PFchargedHadronIsoR03_(false),
  c_pf_els_PFneutralHadronIsoR03_(false),
  c_pf_els_PFphotonIsoR03_(false),
  c_pf_els_basicClustersSize_(false),
  c_pf_els_cIso_(false),
  c_pf_els_caloEnergy_(false),
  c_pf_els_charge_(false),
  c_pf_els_chargedHadronIso_(false),
  c_pf_els_chi2_(false),
  c_pf_els_core_ecalDrivenSeed_(false),
  c_pf_els_cpx_(false),
  c_pf_els_cpy_(false),
  c_pf_els_cpz_(false),
  c_pf_els_ctf_tk_charge_(false),
  c_pf_els_ctf_tk_eta_(false),
  c_pf_els_ctf_tk_id_(false),
  c_pf_els_ctf_tk_phi_(false),
  c_pf_els_cx_(false),
  c_pf_els_cy_(false),
  c_pf_els_cz_(false),
  c_pf_els_d0dum_(false),
  c_pf_els_d0dumError_(false),
  c_pf_els_dEtaIn_(false),
  c_pf_els_dEtaOut_(false),
  c_pf_els_dPhiIn_(false),
  c_pf_els_dPhiOut_(false),
  c_pf_els_dr03EcalRecHitSumEt_(false),
  c_pf_els_dr03HcalDepth1TowerSumEt_(false),
  c_pf_els_dr03HcalDepth2TowerSumEt_(false),
  c_pf_els_dr03HcalTowerSumEt_(false),
  c_pf_els_dr03TkSumPt_(false),
  c_pf_els_dr04EcalRecHitSumEt_(false),
  c_pf_els_dr04HcalDepth1TowerSumEt_(false),
  c_pf_els_dr04HcalDepth2TowerSumEt_(false),
  c_pf_els_dr04HcalTowerSumEt_(false),
  c_pf_els_dr04TkSumPt_(false),
  c_pf_els_dz_(false),
  c_pf_els_dzError_(false),
  c_pf_els_eOverPIn_(false),
  c_pf_els_eSeedOverPOut_(false),
  c_pf_els_ecalIso_(false),
  c_pf_els_energy_(false),
  c_pf_els_et_(false),
  c_pf_els_eta_(false),
  c_pf_els_etaError_(false),
  c_pf_els_fbrem_(false),
  c_pf_els_gen_et_(false),
  c_pf_els_gen_eta_(false),
  c_pf_els_gen_id_(false),
  c_pf_els_gen_mother_et_(false),
  c_pf_els_gen_mother_eta_(false),
  c_pf_els_gen_mother_id_(false),
  c_pf_els_gen_mother_phi_(false),
  c_pf_els_gen_mother_pt_(false),
  c_pf_els_gen_mother_px_(false),
  c_pf_els_gen_mother_py_(false),
  c_pf_els_gen_mother_pz_(false),
  c_pf_els_gen_mother_theta_(false),
  c_pf_els_gen_phi_(false),
  c_pf_els_gen_pt_(false),
  c_pf_els_gen_px_(false),
  c_pf_els_gen_py_(false),
  c_pf_els_gen_pz_(false),
  c_pf_els_gen_theta_(false),
  c_pf_els_hadOverEm_(false),
  c_pf_els_hasMatchedConversion_(false),
  c_pf_els_hcalIso_(false),
  c_pf_els_hcalOverEcalBc_(false),
  c_pf_els_isEB_(false),
  c_pf_els_isEE_(false),
  c_pf_els_looseId_(false),
  c_pf_els_n_inner_layer_(false),
  c_pf_els_n_outer_layer_(false),
  c_pf_els_ndof_(false),
  c_pf_els_neutralHadronIso_(false),
  c_pf_els_numlosthits_(false),
  c_pf_els_numvalhits_(false),
  c_pf_els_phi_(false),
  c_pf_els_phiError_(false),
  c_pf_els_photonIso_(false),
  c_pf_els_pt_(false),
  c_pf_els_ptError_(false),
  c_pf_els_px_(false),
  c_pf_els_py_(false),
  c_pf_els_pz_(false),
  c_pf_els_robustHighEnergyId_(false),
  c_pf_els_robustLooseId_(false),
  c_pf_els_robustTightId_(false),
  c_pf_els_scE1x5_(false),
  c_pf_els_scE2x5Max_(false),
  c_pf_els_scE5x5_(false),
  c_pf_els_scEnergy_(false),
  c_pf_els_scEta_(false),
  c_pf_els_scEtaWidth_(false),
  c_pf_els_scPhi_(false),
  c_pf_els_scPhiWidth_(false),
  c_pf_els_scRawEnergy_(false),
  c_pf_els_scSeedEnergy_(false),
  c_pf_els_shFracInnerHits_(false),
  c_pf_els_sigmaEtaEta_(false),
  c_pf_els_sigmaIEtaIEta_(false),
  c_pf_els_simpleEleId60cIso_(false),
  c_pf_els_simpleEleId60relIso_(false),
  c_pf_els_simpleEleId70cIso_(false),
  c_pf_els_simpleEleId70relIso_(false),
  c_pf_els_simpleEleId80cIso_(false),
  c_pf_els_simpleEleId80relIso_(false),
  c_pf_els_simpleEleId85cIso_(false),
  c_pf_els_simpleEleId85relIso_(false),
  c_pf_els_simpleEleId90cIso_(false),
  c_pf_els_simpleEleId90relIso_(false),
  c_pf_els_simpleEleId95cIso_(false),
  c_pf_els_simpleEleId95relIso_(false),
  c_pf_els_status_(false),
  c_pf_els_tIso_(false),
  c_pf_els_theta_(false),
  c_pf_els_tightId_(false),
  c_pf_els_tk_charge_(false),
  c_pf_els_tk_eta_(false),
  c_pf_els_tk_phi_(false),
  c_pf_els_tk_pt_(false),
  c_pf_els_tk_pz_(false),
  c_pf_els_vpx_(false),
  c_pf_els_vpy_(false),
  c_pf_els_vpz_(false),
  c_pf_els_vx_(false),
  c_pf_els_vy_(false),
  c_pf_els_vz_(false),
  c_pf_mus_cIso_(false),
  c_pf_mus_calEnergyEm_(false),
  c_pf_mus_calEnergyEmS9_(false),
  c_pf_mus_calEnergyHad_(false),
  c_pf_mus_calEnergyHadS9_(false),
  c_pf_mus_calEnergyHo_(false),
  c_pf_mus_calEnergyHoS9_(false),
  c_pf_mus_charge_(false),
  c_pf_mus_chargedHadronIso_(false),
  c_pf_mus_cm_ExpectedHitsInner_(false),
  c_pf_mus_cm_ExpectedHitsOuter_(false),
  c_pf_mus_cm_LayersWithMeasurement_(false),
  c_pf_mus_cm_LayersWithoutMeasurement_(false),
  c_pf_mus_cm_PixelLayersWithMeasurement_(false),
  c_pf_mus_cm_ValidStripLayersWithMonoAndStereoHit_(false),
  c_pf_mus_cm_chg_(false),
  c_pf_mus_cm_chi2_(false),
  c_pf_mus_cm_d0dum_(false),
  c_pf_mus_cm_d0dumErr_(false),
  c_pf_mus_cm_dz_(false),
  c_pf_mus_cm_dzErr_(false),
  c_pf_mus_cm_eta_(false),
  c_pf_mus_cm_etaErr_(false),
  c_pf_mus_cm_ndof_(false),
  c_pf_mus_cm_numlosthits_(false),
  c_pf_mus_cm_numvalMuonhits_(false),
  c_pf_mus_cm_numvalhits_(false),
  c_pf_mus_cm_phi_(false),
  c_pf_mus_cm_phiErr_(false),
  c_pf_mus_cm_pt_(false),
  c_pf_mus_cm_ptErr_(false),
  c_pf_mus_cm_px_(false),
  c_pf_mus_cm_py_(false),
  c_pf_mus_cm_pz_(false),
  c_pf_mus_cm_theta_(false),
  c_pf_mus_cm_vx_(false),
  c_pf_mus_cm_vy_(false),
  c_pf_mus_cm_vz_(false),
  c_pf_mus_dB_(false),
  c_pf_mus_ecalIso_(false),
  c_pf_mus_energy_(false),
  c_pf_mus_et_(false),
  c_pf_mus_eta_(false),
  c_pf_mus_gen_et_(false),
  c_pf_mus_gen_eta_(false),
  c_pf_mus_gen_id_(false),
  c_pf_mus_gen_mother_et_(false),
  c_pf_mus_gen_mother_eta_(false),
  c_pf_mus_gen_mother_id_(false),
  c_pf_mus_gen_mother_phi_(false),
  c_pf_mus_gen_mother_pt_(false),
  c_pf_mus_gen_mother_px_(false),
  c_pf_mus_gen_mother_py_(false),
  c_pf_mus_gen_mother_pz_(false),
  c_pf_mus_gen_mother_theta_(false),
  c_pf_mus_gen_phi_(false),
  c_pf_mus_gen_pt_(false),
  c_pf_mus_gen_px_(false),
  c_pf_mus_gen_py_(false),
  c_pf_mus_gen_pz_(false),
  c_pf_mus_gen_theta_(false),
  c_pf_mus_hcalIso_(false),
  c_pf_mus_id_All_(false),
  c_pf_mus_id_AllArbitrated_(false),
  c_pf_mus_id_AllGlobalMuons_(false),
  c_pf_mus_id_AllStandAloneMuons_(false),
  c_pf_mus_id_AllTrackerMuons_(false),
  c_pf_mus_id_GlobalMuonPromptTight_(false),
  c_pf_mus_id_TM2DCompatibilityLoose_(false),
  c_pf_mus_id_TM2DCompatibilityTight_(false),
  c_pf_mus_id_TMLastStationLoose_(false),
  c_pf_mus_id_TMLastStationOptimizedLowPtLoose_(false),
  c_pf_mus_id_TMLastStationOptimizedLowPtTight_(false),
  c_pf_mus_id_TMLastStationTight_(false),
  c_pf_mus_id_TMOneStationLoose_(false),
  c_pf_mus_id_TMOneStationTight_(false),
  c_pf_mus_id_TrackerMuonArbitrated_(false),
  c_pf_mus_isCaloMuon_(false),
  c_pf_mus_isConvertedPhoton_(false),
  c_pf_mus_isElectron_(false),
  c_pf_mus_isGlobalMuon_(false),
  c_pf_mus_isPFMuon_(false),
  c_pf_mus_isPhoton_(false),
  c_pf_mus_isStandAloneMuon_(false),
  c_pf_mus_isTrackerMuon_(false),
  c_pf_mus_iso03_emEt_(false),
  c_pf_mus_iso03_emVetoEt_(false),
  c_pf_mus_iso03_hadEt_(false),
  c_pf_mus_iso03_hadVetoEt_(false),
  c_pf_mus_iso03_hoEt_(false),
  c_pf_mus_iso03_nTracks_(false),
  c_pf_mus_iso03_sumPt_(false),
  c_pf_mus_iso05_emEt_(false),
  c_pf_mus_iso05_hadEt_(false),
  c_pf_mus_iso05_hoEt_(false),
  c_pf_mus_iso05_nTracks_(false),
  c_pf_mus_iso05_sumPt_(false),
  c_pf_mus_neutralHadronIso_(false),
  c_pf_mus_num_matches_(false),
  c_pf_mus_numberOfMatchedStations_(false),
  c_pf_mus_pfIsolationR03_sumChargedHadronPt_(false),
  c_pf_mus_pfIsolationR03_sumChargedParticlePt_(false),
  c_pf_mus_pfIsolationR03_sumNeutralHadronEt_(false),
  c_pf_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_(false),
  c_pf_mus_pfIsolationR03_sumPUPt_(false),
  c_pf_mus_pfIsolationR03_sumPhotonEt_(false),
  c_pf_mus_pfIsolationR03_sumPhotonEtHighThreshold_(false),
  c_pf_mus_pfIsolationR04_sumChargedHadronPt_(false),
  c_pf_mus_pfIsolationR04_sumChargedParticlePt_(false),
  c_pf_mus_pfIsolationR04_sumNeutralHadronEt_(false),
  c_pf_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_(false),
  c_pf_mus_pfIsolationR04_sumPUPt_(false),
  c_pf_mus_pfIsolationR04_sumPhotonEt_(false),
  c_pf_mus_pfIsolationR04_sumPhotonEtHighThreshold_(false),
  c_pf_mus_phi_(false),
  c_pf_mus_photonIso_(false),
  c_pf_mus_picky_ExpectedHitsInner_(false),
  c_pf_mus_picky_ExpectedHitsOuter_(false),
  c_pf_mus_picky_LayersWithMeasurement_(false),
  c_pf_mus_picky_LayersWithoutMeasurement_(false),
  c_pf_mus_picky_PixelLayersWithMeasurement_(false),
  c_pf_mus_picky_ValidStripLayersWithMonoAndStereoHit_(false),
  c_pf_mus_picky_chg_(false),
  c_pf_mus_picky_chi2_(false),
  c_pf_mus_picky_d0dum_(false),
  c_pf_mus_picky_d0dumErr_(false),
  c_pf_mus_picky_dz_(false),
  c_pf_mus_picky_dzErr_(false),
  c_pf_mus_picky_eta_(false),
  c_pf_mus_picky_etaErr_(false),
  c_pf_mus_picky_id_(false),
  c_pf_mus_picky_ndof_(false),
  c_pf_mus_picky_numlosthits_(false),
  c_pf_mus_picky_numvalPixelhits_(false),
  c_pf_mus_picky_numvalhits_(false),
  c_pf_mus_picky_phi_(false),
  c_pf_mus_picky_phiErr_(false),
  c_pf_mus_picky_pt_(false),
  c_pf_mus_picky_ptErr_(false),
  c_pf_mus_picky_px_(false),
  c_pf_mus_picky_py_(false),
  c_pf_mus_picky_pz_(false),
  c_pf_mus_picky_theta_(false),
  c_pf_mus_picky_vx_(false),
  c_pf_mus_picky_vy_(false),
  c_pf_mus_picky_vz_(false),
  c_pf_mus_pt_(false),
  c_pf_mus_px_(false),
  c_pf_mus_py_(false),
  c_pf_mus_pz_(false),
  c_pf_mus_stamu_chg_(false),
  c_pf_mus_stamu_chi2_(false),
  c_pf_mus_stamu_d0dum_(false),
  c_pf_mus_stamu_d0dumErr_(false),
  c_pf_mus_stamu_dz_(false),
  c_pf_mus_stamu_dzErr_(false),
  c_pf_mus_stamu_eta_(false),
  c_pf_mus_stamu_etaErr_(false),
  c_pf_mus_stamu_ndof_(false),
  c_pf_mus_stamu_numlosthits_(false),
  c_pf_mus_stamu_numvalhits_(false),
  c_pf_mus_stamu_phi_(false),
  c_pf_mus_stamu_phiErr_(false),
  c_pf_mus_stamu_pt_(false),
  c_pf_mus_stamu_ptErr_(false),
  c_pf_mus_stamu_px_(false),
  c_pf_mus_stamu_py_(false),
  c_pf_mus_stamu_pz_(false),
  c_pf_mus_stamu_theta_(false),
  c_pf_mus_stamu_vx_(false),
  c_pf_mus_stamu_vy_(false),
  c_pf_mus_stamu_vz_(false),
  c_pf_mus_status_(false),
  c_pf_mus_tIso_(false),
  c_pf_mus_theta_(false),
  c_pf_mus_tkHits_(false),
  c_pf_mus_tk_ExpectedHitsInner_(false),
  c_pf_mus_tk_ExpectedHitsOuter_(false),
  c_pf_mus_tk_LayersWithMeasurement_(false),
  c_pf_mus_tk_LayersWithoutMeasurement_(false),
  c_pf_mus_tk_PixelLayersWithMeasurement_(false),
  c_pf_mus_tk_ValidStripLayersWithMonoAndStereoHit_(false),
  c_pf_mus_tk_chg_(false),
  c_pf_mus_tk_chi2_(false),
  c_pf_mus_tk_d0dum_(false),
  c_pf_mus_tk_d0dumErr_(false),
  c_pf_mus_tk_dz_(false),
  c_pf_mus_tk_dzErr_(false),
  c_pf_mus_tk_eta_(false),
  c_pf_mus_tk_etaErr_(false),
  c_pf_mus_tk_id_(false),
  c_pf_mus_tk_ndof_(false),
  c_pf_mus_tk_numlosthits_(false),
  c_pf_mus_tk_numpixelWthMeasr_(false),
  c_pf_mus_tk_numvalPixelhits_(false),
  c_pf_mus_tk_numvalhits_(false),
  c_pf_mus_tk_phi_(false),
  c_pf_mus_tk_phiErr_(false),
  c_pf_mus_tk_pt_(false),
  c_pf_mus_tk_ptErr_(false),
  c_pf_mus_tk_px_(false),
  c_pf_mus_tk_py_(false),
  c_pf_mus_tk_pz_(false),
  c_pf_mus_tk_theta_(false),
  c_pf_mus_tk_vx_(false),
  c_pf_mus_tk_vy_(false),
  c_pf_mus_tk_vz_(false),
  c_pf_mus_tpfms_ExpectedHitsInner_(false),
  c_pf_mus_tpfms_ExpectedHitsOuter_(false),
  c_pf_mus_tpfms_LayersWithMeasurement_(false),
  c_pf_mus_tpfms_LayersWithoutMeasurement_(false),
  c_pf_mus_tpfms_PixelLayersWithMeasurement_(false),
  c_pf_mus_tpfms_ValidStripLayersWithMonoAndStereoHit_(false),
  c_pf_mus_tpfms_chg_(false),
  c_pf_mus_tpfms_chi2_(false),
  c_pf_mus_tpfms_d0dum_(false),
  c_pf_mus_tpfms_d0dumErr_(false),
  c_pf_mus_tpfms_dz_(false),
  c_pf_mus_tpfms_dzErr_(false),
  c_pf_mus_tpfms_eta_(false),
  c_pf_mus_tpfms_etaErr_(false),
  c_pf_mus_tpfms_id_(false),
  c_pf_mus_tpfms_ndof_(false),
  c_pf_mus_tpfms_numlosthits_(false),
  c_pf_mus_tpfms_numvalPixelhits_(false),
  c_pf_mus_tpfms_numvalhits_(false),
  c_pf_mus_tpfms_phi_(false),
  c_pf_mus_tpfms_phiErr_(false),
  c_pf_mus_tpfms_pt_(false),
  c_pf_mus_tpfms_ptErr_(false),
  c_pf_mus_tpfms_px_(false),
  c_pf_mus_tpfms_py_(false),
  c_pf_mus_tpfms_pz_(false),
  c_pf_mus_tpfms_theta_(false),
  c_pf_mus_tpfms_vx_(false),
  c_pf_mus_tpfms_vy_(false),
  c_pf_mus_tpfms_vz_(false),
  c_pf_photons_chIso_(false),
  c_pf_photons_e1x5_(false),
  c_pf_photons_e2x5_(false),
  c_pf_photons_e3x3_(false),
  c_pf_photons_e5x5_(false),
  c_pf_photons_energy_(false),
  c_pf_photons_et_(false),
  c_pf_photons_eta_(false),
  c_pf_photons_hadOverEM_(false),
  c_pf_photons_hadTowOverEM_(false),
  c_pf_photons_hasPixelSeed_(false),
  c_pf_photons_isAlsoElectron_(false),
  c_pf_photons_isConverted_(false),
  c_pf_photons_isEBEEGap_(false),
  c_pf_photons_isEBGap_(false),
  c_pf_photons_isEBPho_(false),
  c_pf_photons_isEEGap_(false),
  c_pf_photons_isEEPho_(false),
  c_pf_photons_maxEnergyXtal_(false),
  c_pf_photons_nhIso_(false),
  c_pf_photons_phIso_(false),
  c_pf_photons_phi_(false),
  c_pf_photons_pt_(false),
  c_pf_photons_px_(false),
  c_pf_photons_py_(false),
  c_pf_photons_pz_(false),
  c_pf_photons_r9_(false),
  c_pf_photons_scEnergy_(false),
  c_pf_photons_scEta_(false),
  c_pf_photons_scEtaWidth_(false),
  c_pf_photons_scPhi_(false),
  c_pf_photons_scPhiWidth_(false),
  c_pf_photons_scRawEnergy_(false),
  c_pf_photons_sigmaEtaEta_(false),
  c_pf_photons_sigmaIetaIeta_(false),
  c_pf_photons_status_(false),
  c_pf_photons_theta_(false),
  c_pfcand_charge_(false),
  c_pfcand_energy_(false),
  c_pfcand_eta_(false),
  c_pfcand_particleId_(false),
  c_pfcand_pdgId_(false),
  c_pfcand_phi_(false),
  c_pfcand_pt_(false),
  c_pfcand_px_(false),
  c_pfcand_py_(false),
  c_pfcand_pz_(false),
  c_pfcand_theta_(false),
  c_pfmets_et_(false),
  c_pfmets_ex_(false),
  c_pfmets_ey_(false),
  c_pfmets_fullSignif_(false),
  c_pfmets_fullSignifCov00_(false),
  c_pfmets_fullSignifCov00_2012_(false),
  c_pfmets_fullSignifCov00_2012_dataRes_(false),
  c_pfmets_fullSignifCov10_(false),
  c_pfmets_fullSignifCov10_2012_(false),
  c_pfmets_fullSignifCov10_2012_dataRes_(false),
  c_pfmets_fullSignifCov11_(false),
  c_pfmets_fullSignifCov11_2012_(false),
  c_pfmets_fullSignifCov11_2012_dataRes_(false),
  c_pfmets_fullSignif_2012_(false),
  c_pfmets_fullSignif_2012_dataRes_(false),
  c_pfmets_gen_et_(false),
  c_pfmets_gen_phi_(false),
  c_pfmets_phi_(false),
  c_pfmets_sign_(false),
  c_pfmets_sumEt_(false),
  c_pfmets_unCPhi_(false),
  c_pfmets_unCPt_(false),
  c_photon_chIsoValues_(false),
  c_photon_nhIsoValues_(false),
  c_photon_passElectronVeto_(false),
  c_photon_phIsoValues_(false),
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
  c_puJet_rejectionBeta_(false),
  c_puJet_rejectionMVA_(false),
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
  c_rho_kt6PFJetsForIsolation2011_(false),
  c_rho_kt6PFJetsForIsolation2012_(false),
  c_run_(false),
  c_scrapingVeto_decision_(false),
  c_softjetUp_dMEx_(false),
  c_softjetUp_dMEy_(false),
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
  c_tcmets_et_(false),
  c_tcmets_ex_(false),
  c_tcmets_ey_(false),
  c_tcmets_phi_(false),
  c_tcmets_sumEt_(false),
  c_trackercoherentnoisefilter1_decision_(false),
  c_trackercoherentnoisefilter2_decision_(false),
  c_trackertoomanyclustersfilter_decision_(false),
  c_trackertoomanyseedsfilter_decision_(false),
  c_trackertoomanytripletsfilter_decision_(false),
  c_trackingfailurefilter_decision_(false),
  c_tracks_chg_(false),
  c_tracks_chi2_(false),
  c_tracks_d0dum_(false),
  c_tracks_d0dumErr_(false),
  c_tracks_dz_(false),
  c_tracks_dzErr_(false),
  c_tracks_eta_(false),
  c_tracks_etaErr_(false),
  c_tracks_highPurity_(false),
  c_tracks_ndof_(false),
  c_tracks_numlosthits_(false),
  c_tracks_numvalhits_(false),
  c_tracks_phi_(false),
  c_tracks_phiErr_(false),
  c_tracks_pt_(false),
  c_tracks_ptErr_(false),
  c_tracks_px_(false),
  c_tracks_py_(false),
  c_tracks_pz_(false),
  c_tracks_vx_(false),
  c_tracks_vy_(false),
  c_tracks_vz_(false),
  c_trigger_decision_(false),
  c_trigger_lastfiltername_(false),
  c_trigger_name_(false),
  c_trigger_prescalevalue_(false),
  c_triggerobject_collectionname_(false),
  c_triggerobject_energy_(false),
  c_triggerobject_et_(false),
  c_triggerobject_eta_(false),
  c_triggerobject_phi_(false),
  c_triggerobject_pt_(false),
  c_triggerobject_px_(false),
  c_triggerobject_py_(false),
  c_triggerobject_pz_(false),
  c_trk_nTOBTEC_(false),
  c_trk_ratioAllTOBTEC_(false),
  c_trk_ratioJetTOBTEC_(false),
  c_weight_(false){
  PrepareNewChains();
}

void cfa_8::GetEntry(const long entry){
  c_L1trigger_alias_ = false;
  c_L1trigger_bit_ = false;
  c_L1trigger_decision_ = false;
  c_L1trigger_decision_nomask_ = false;
  c_L1trigger_name_ = false;
  c_L1trigger_prescalevalue_ = false;
  c_L1trigger_techTrigger_ = false;
  c_MPT_ = false;
  c_NbeamSpot_ = false;
  c_Nels_ = false;
  c_Njets_AK5PF_ = false;
  c_Njets_AK5PFclean_ = false;
  c_Nmc_doc_ = false;
  c_Nmc_electrons_ = false;
  c_Nmc_mus_ = false;
  c_Nmc_nues_ = false;
  c_Nmc_numus_ = false;
  c_Nmc_nutaus_ = false;
  c_Nmc_pdf_ = false;
  c_Nmc_photons_ = false;
  c_Nmc_taus_ = false;
  c_NmetsHO_ = false;
  c_Nmets_AK5_ = false;
  c_Nmus_ = false;
  c_NpfTypeINoXYCorrmets_ = false;
  c_NpfTypeIType0mets_ = false;
  c_NpfTypeImets_ = false;
  c_Npf_els_ = false;
  c_Npf_mus_ = false;
  c_Npf_photons_ = false;
  c_Npfcand_ = false;
  c_Npfmets_ = false;
  c_Nphotons_ = false;
  c_Npv_ = false;
  c_Ntaus_ = false;
  c_Ntcmets_ = false;
  c_Ntracks_ = false;
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
  c_ecalBEfilter_decision_ = false;
  c_ecalTPfilter_decision_ = false;
  c_ecallaserfilter_decision_ = false;
  c_eebadscfilter_decision_ = false;
  c_eenoisefilter_decision_ = false;
  c_els_PATpassConversionVeto_ = false;
  c_els_PFchargedHadronIsoR03_ = false;
  c_els_PFneutralHadronIsoR03_ = false;
  c_els_PFphotonIsoR03_ = false;
  c_els_basicClustersSize_ = false;
  c_els_cIso_ = false;
  c_els_caloEnergy_ = false;
  c_els_charge_ = false;
  c_els_chi2_ = false;
  c_els_conversion_dcot_ = false;
  c_els_conversion_dist_ = false;
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
  c_els_hasMatchedConversion_ = false;
  c_els_hcalIso_ = false;
  c_els_hcalOverEcalBc_ = false;
  c_els_isEB_ = false;
  c_els_isEE_ = false;
  c_els_looseId_ = false;
  c_els_n_inner_layer_ = false;
  c_els_n_outer_layer_ = false;
  c_els_ndof_ = false;
  c_els_numlosthits_ = false;
  c_els_numvalhits_ = false;
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
  c_genHT_ = false;
  c_greedymuonfilter_decision_ = false;
  c_hbhefilter_decision_ = false;
  c_hcallaserfilter_decision_ = false;
  c_inconsistentPFmuonfilter_decision_ = false;
  c_isotk_charge_ = false;
  c_isotk_dzpv_ = false;
  c_isotk_eta_ = false;
  c_isotk_iso_ = false;
  c_isotk_phi_ = false;
  c_isotk_pt_ = false;
  c_jets_AK5PF_area_ = false;
  c_jets_AK5PF_btag_TC_highEff_ = false;
  c_jets_AK5PF_btag_TC_highPur_ = false;
  c_jets_AK5PF_btag_jetBProb_ = false;
  c_jets_AK5PF_btag_jetProb_ = false;
  c_jets_AK5PF_btag_secVertexCombined_ = false;
  c_jets_AK5PF_btag_secVertexHighEff_ = false;
  c_jets_AK5PF_btag_secVertexHighPur_ = false;
  c_jets_AK5PF_btag_softEle_ = false;
  c_jets_AK5PF_btag_softMuon_ = false;
  c_jets_AK5PF_chgEmE_ = false;
  c_jets_AK5PF_chgHadE_ = false;
  c_jets_AK5PF_chgMuE_ = false;
  c_jets_AK5PF_chg_Mult_ = false;
  c_jets_AK5PF_corrFactorRaw_ = false;
  c_jets_AK5PF_ehf_ = false;
  c_jets_AK5PF_emf_ = false;
  c_jets_AK5PF_energy_ = false;
  c_jets_AK5PF_et_ = false;
  c_jets_AK5PF_eta_ = false;
  c_jets_AK5PF_etaetaMoment_ = false;
  c_jets_AK5PF_etaphiMoment_ = false;
  c_jets_AK5PF_fHPD_ = false;
  c_jets_AK5PF_fRBX_ = false;
  c_jets_AK5PF_fSubDetector1_ = false;
  c_jets_AK5PF_fSubDetector2_ = false;
  c_jets_AK5PF_fSubDetector3_ = false;
  c_jets_AK5PF_fSubDetector4_ = false;
  c_jets_AK5PF_gen_Energy_ = false;
  c_jets_AK5PF_gen_Id_ = false;
  c_jets_AK5PF_gen_et_ = false;
  c_jets_AK5PF_gen_eta_ = false;
  c_jets_AK5PF_gen_mass_ = false;
  c_jets_AK5PF_gen_motherID_ = false;
  c_jets_AK5PF_gen_phi_ = false;
  c_jets_AK5PF_gen_pt_ = false;
  c_jets_AK5PF_gen_threeCharge_ = false;
  c_jets_AK5PF_hitsInN90_ = false;
  c_jets_AK5PF_jetCharge_ = false;
  c_jets_AK5PF_mass_ = false;
  c_jets_AK5PF_mu_Mult_ = false;
  c_jets_AK5PF_n60_ = false;
  c_jets_AK5PF_n90_ = false;
  c_jets_AK5PF_n90Hits_ = false;
  c_jets_AK5PF_nECALTowers_ = false;
  c_jets_AK5PF_nHCALTowers_ = false;
  c_jets_AK5PF_neutralEmE_ = false;
  c_jets_AK5PF_neutralHadE_ = false;
  c_jets_AK5PF_neutral_Mult_ = false;
  c_jets_AK5PF_partonFlavour_ = false;
  c_jets_AK5PF_parton_Energy_ = false;
  c_jets_AK5PF_parton_Id_ = false;
  c_jets_AK5PF_parton_eta_ = false;
  c_jets_AK5PF_parton_mass_ = false;
  c_jets_AK5PF_parton_motherId_ = false;
  c_jets_AK5PF_parton_phi_ = false;
  c_jets_AK5PF_parton_pt_ = false;
  c_jets_AK5PF_phi_ = false;
  c_jets_AK5PF_phiphiMoment_ = false;
  c_jets_AK5PF_photonEnergy_ = false;
  c_jets_AK5PF_pt_ = false;
  c_jets_AK5PF_px_ = false;
  c_jets_AK5PF_py_ = false;
  c_jets_AK5PF_pz_ = false;
  c_jets_AK5PF_rawPt_ = false;
  c_jets_AK5PF_status_ = false;
  c_jets_AK5PF_theta_ = false;
  c_jets_AK5PFclean_Uncert_ = false;
  c_jets_AK5PFclean_area_ = false;
  c_jets_AK5PFclean_btag_TC_highEff_ = false;
  c_jets_AK5PFclean_btag_TC_highPur_ = false;
  c_jets_AK5PFclean_btag_jetBProb_ = false;
  c_jets_AK5PFclean_btag_jetProb_ = false;
  c_jets_AK5PFclean_btag_secVertexCombined_ = false;
  c_jets_AK5PFclean_btag_secVertexHighEff_ = false;
  c_jets_AK5PFclean_btag_secVertexHighPur_ = false;
  c_jets_AK5PFclean_btag_softEle_ = false;
  c_jets_AK5PFclean_btag_softMuon_ = false;
  c_jets_AK5PFclean_chgEmE_ = false;
  c_jets_AK5PFclean_chgHadE_ = false;
  c_jets_AK5PFclean_chgMuE_ = false;
  c_jets_AK5PFclean_chg_Mult_ = false;
  c_jets_AK5PFclean_corrFactorRaw_ = false;
  c_jets_AK5PFclean_corrL1FastL2L3_ = false;
  c_jets_AK5PFclean_corrL1FastL2L3Residual_ = false;
  c_jets_AK5PFclean_corrL1L2L3_ = false;
  c_jets_AK5PFclean_corrL1L2L3Residual_ = false;
  c_jets_AK5PFclean_corrL2L3_ = false;
  c_jets_AK5PFclean_corrL2L3Residual_ = false;
  c_jets_AK5PFclean_ehf_ = false;
  c_jets_AK5PFclean_emf_ = false;
  c_jets_AK5PFclean_energy_ = false;
  c_jets_AK5PFclean_et_ = false;
  c_jets_AK5PFclean_eta_ = false;
  c_jets_AK5PFclean_etaetaMoment_ = false;
  c_jets_AK5PFclean_etaphiMoment_ = false;
  c_jets_AK5PFclean_fHPD_ = false;
  c_jets_AK5PFclean_fRBX_ = false;
  c_jets_AK5PFclean_fSubDetector1_ = false;
  c_jets_AK5PFclean_fSubDetector2_ = false;
  c_jets_AK5PFclean_fSubDetector3_ = false;
  c_jets_AK5PFclean_fSubDetector4_ = false;
  c_jets_AK5PFclean_gen_Energy_ = false;
  c_jets_AK5PFclean_gen_Id_ = false;
  c_jets_AK5PFclean_gen_et_ = false;
  c_jets_AK5PFclean_gen_eta_ = false;
  c_jets_AK5PFclean_gen_mass_ = false;
  c_jets_AK5PFclean_gen_phi_ = false;
  c_jets_AK5PFclean_gen_pt_ = false;
  c_jets_AK5PFclean_hitsInN90_ = false;
  c_jets_AK5PFclean_jetCharge_ = false;
  c_jets_AK5PFclean_mass_ = false;
  c_jets_AK5PFclean_mu_Mult_ = false;
  c_jets_AK5PFclean_n60_ = false;
  c_jets_AK5PFclean_n90_ = false;
  c_jets_AK5PFclean_n90Hits_ = false;
  c_jets_AK5PFclean_nECALTowers_ = false;
  c_jets_AK5PFclean_nHCALTowers_ = false;
  c_jets_AK5PFclean_neutralEmE_ = false;
  c_jets_AK5PFclean_neutralHadE_ = false;
  c_jets_AK5PFclean_neutral_Mult_ = false;
  c_jets_AK5PFclean_partonFlavour_ = false;
  c_jets_AK5PFclean_parton_Energy_ = false;
  c_jets_AK5PFclean_parton_Id_ = false;
  c_jets_AK5PFclean_parton_eta_ = false;
  c_jets_AK5PFclean_parton_mass_ = false;
  c_jets_AK5PFclean_parton_motherId_ = false;
  c_jets_AK5PFclean_parton_phi_ = false;
  c_jets_AK5PFclean_parton_pt_ = false;
  c_jets_AK5PFclean_phi_ = false;
  c_jets_AK5PFclean_phiphiMoment_ = false;
  c_jets_AK5PFclean_photonEnergy_ = false;
  c_jets_AK5PFclean_pt_ = false;
  c_jets_AK5PFclean_px_ = false;
  c_jets_AK5PFclean_py_ = false;
  c_jets_AK5PFclean_pz_ = false;
  c_jets_AK5PFclean_rawPt_ = false;
  c_jets_AK5PFclean_status_ = false;
  c_jets_AK5PFclean_theta_ = false;
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
  c_mc_pdf_id1_ = false;
  c_mc_pdf_id2_ = false;
  c_mc_pdf_q_ = false;
  c_mc_pdf_x1_ = false;
  c_mc_pdf_x2_ = false;
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
  c_metsHO_et_ = false;
  c_metsHO_ex_ = false;
  c_metsHO_ey_ = false;
  c_metsHO_phi_ = false;
  c_metsHO_sumEt_ = false;
  c_mets_AK5_et_ = false;
  c_mets_AK5_ex_ = false;
  c_mets_AK5_ey_ = false;
  c_mets_AK5_gen_et_ = false;
  c_mets_AK5_gen_phi_ = false;
  c_mets_AK5_phi_ = false;
  c_mets_AK5_sign_ = false;
  c_mets_AK5_sumEt_ = false;
  c_mets_AK5_unCPhi_ = false;
  c_mets_AK5_unCPt_ = false;
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
  c_passprescaleHT250filter_decision_ = false;
  c_passprescaleHT300filter_decision_ = false;
  c_passprescaleHT350filter_decision_ = false;
  c_passprescaleHT400filter_decision_ = false;
  c_passprescaleHT450filter_decision_ = false;
  c_passprescaleJet30MET80filter_decision_ = false;
  c_passprescalePFHT350filter_decision_ = false;
  c_pdfweights_cteq_ = false;
  c_pdfweights_mstw_ = false;
  c_pdfweights_nnpdf_ = false;
  c_pfTypeINoXYCorrmets_et_ = false;
  c_pfTypeINoXYCorrmets_ex_ = false;
  c_pfTypeINoXYCorrmets_ey_ = false;
  c_pfTypeINoXYCorrmets_gen_et_ = false;
  c_pfTypeINoXYCorrmets_gen_phi_ = false;
  c_pfTypeINoXYCorrmets_phi_ = false;
  c_pfTypeINoXYCorrmets_sign_ = false;
  c_pfTypeINoXYCorrmets_sumEt_ = false;
  c_pfTypeINoXYCorrmets_unCPhi_ = false;
  c_pfTypeINoXYCorrmets_unCPt_ = false;
  c_pfTypeIType0mets_et_ = false;
  c_pfTypeIType0mets_ex_ = false;
  c_pfTypeIType0mets_ey_ = false;
  c_pfTypeIType0mets_gen_et_ = false;
  c_pfTypeIType0mets_gen_phi_ = false;
  c_pfTypeIType0mets_phi_ = false;
  c_pfTypeIType0mets_sign_ = false;
  c_pfTypeIType0mets_sumEt_ = false;
  c_pfTypeIType0mets_unCPhi_ = false;
  c_pfTypeIType0mets_unCPt_ = false;
  c_pfTypeImets_et_ = false;
  c_pfTypeImets_ex_ = false;
  c_pfTypeImets_ey_ = false;
  c_pfTypeImets_gen_et_ = false;
  c_pfTypeImets_gen_phi_ = false;
  c_pfTypeImets_phi_ = false;
  c_pfTypeImets_sign_ = false;
  c_pfTypeImets_sumEt_ = false;
  c_pfTypeImets_unCPhi_ = false;
  c_pfTypeImets_unCPt_ = false;
  c_pf_els_PATpassConversionVeto_ = false;
  c_pf_els_PFchargedHadronIsoR03_ = false;
  c_pf_els_PFneutralHadronIsoR03_ = false;
  c_pf_els_PFphotonIsoR03_ = false;
  c_pf_els_basicClustersSize_ = false;
  c_pf_els_cIso_ = false;
  c_pf_els_caloEnergy_ = false;
  c_pf_els_charge_ = false;
  c_pf_els_chargedHadronIso_ = false;
  c_pf_els_chi2_ = false;
  c_pf_els_core_ecalDrivenSeed_ = false;
  c_pf_els_cpx_ = false;
  c_pf_els_cpy_ = false;
  c_pf_els_cpz_ = false;
  c_pf_els_ctf_tk_charge_ = false;
  c_pf_els_ctf_tk_eta_ = false;
  c_pf_els_ctf_tk_id_ = false;
  c_pf_els_ctf_tk_phi_ = false;
  c_pf_els_cx_ = false;
  c_pf_els_cy_ = false;
  c_pf_els_cz_ = false;
  c_pf_els_d0dum_ = false;
  c_pf_els_d0dumError_ = false;
  c_pf_els_dEtaIn_ = false;
  c_pf_els_dEtaOut_ = false;
  c_pf_els_dPhiIn_ = false;
  c_pf_els_dPhiOut_ = false;
  c_pf_els_dr03EcalRecHitSumEt_ = false;
  c_pf_els_dr03HcalDepth1TowerSumEt_ = false;
  c_pf_els_dr03HcalDepth2TowerSumEt_ = false;
  c_pf_els_dr03HcalTowerSumEt_ = false;
  c_pf_els_dr03TkSumPt_ = false;
  c_pf_els_dr04EcalRecHitSumEt_ = false;
  c_pf_els_dr04HcalDepth1TowerSumEt_ = false;
  c_pf_els_dr04HcalDepth2TowerSumEt_ = false;
  c_pf_els_dr04HcalTowerSumEt_ = false;
  c_pf_els_dr04TkSumPt_ = false;
  c_pf_els_dz_ = false;
  c_pf_els_dzError_ = false;
  c_pf_els_eOverPIn_ = false;
  c_pf_els_eSeedOverPOut_ = false;
  c_pf_els_ecalIso_ = false;
  c_pf_els_energy_ = false;
  c_pf_els_et_ = false;
  c_pf_els_eta_ = false;
  c_pf_els_etaError_ = false;
  c_pf_els_fbrem_ = false;
  c_pf_els_gen_et_ = false;
  c_pf_els_gen_eta_ = false;
  c_pf_els_gen_id_ = false;
  c_pf_els_gen_mother_et_ = false;
  c_pf_els_gen_mother_eta_ = false;
  c_pf_els_gen_mother_id_ = false;
  c_pf_els_gen_mother_phi_ = false;
  c_pf_els_gen_mother_pt_ = false;
  c_pf_els_gen_mother_px_ = false;
  c_pf_els_gen_mother_py_ = false;
  c_pf_els_gen_mother_pz_ = false;
  c_pf_els_gen_mother_theta_ = false;
  c_pf_els_gen_phi_ = false;
  c_pf_els_gen_pt_ = false;
  c_pf_els_gen_px_ = false;
  c_pf_els_gen_py_ = false;
  c_pf_els_gen_pz_ = false;
  c_pf_els_gen_theta_ = false;
  c_pf_els_hadOverEm_ = false;
  c_pf_els_hasMatchedConversion_ = false;
  c_pf_els_hcalIso_ = false;
  c_pf_els_hcalOverEcalBc_ = false;
  c_pf_els_isEB_ = false;
  c_pf_els_isEE_ = false;
  c_pf_els_looseId_ = false;
  c_pf_els_n_inner_layer_ = false;
  c_pf_els_n_outer_layer_ = false;
  c_pf_els_ndof_ = false;
  c_pf_els_neutralHadronIso_ = false;
  c_pf_els_numlosthits_ = false;
  c_pf_els_numvalhits_ = false;
  c_pf_els_phi_ = false;
  c_pf_els_phiError_ = false;
  c_pf_els_photonIso_ = false;
  c_pf_els_pt_ = false;
  c_pf_els_ptError_ = false;
  c_pf_els_px_ = false;
  c_pf_els_py_ = false;
  c_pf_els_pz_ = false;
  c_pf_els_robustHighEnergyId_ = false;
  c_pf_els_robustLooseId_ = false;
  c_pf_els_robustTightId_ = false;
  c_pf_els_scE1x5_ = false;
  c_pf_els_scE2x5Max_ = false;
  c_pf_els_scE5x5_ = false;
  c_pf_els_scEnergy_ = false;
  c_pf_els_scEta_ = false;
  c_pf_els_scEtaWidth_ = false;
  c_pf_els_scPhi_ = false;
  c_pf_els_scPhiWidth_ = false;
  c_pf_els_scRawEnergy_ = false;
  c_pf_els_scSeedEnergy_ = false;
  c_pf_els_shFracInnerHits_ = false;
  c_pf_els_sigmaEtaEta_ = false;
  c_pf_els_sigmaIEtaIEta_ = false;
  c_pf_els_simpleEleId60cIso_ = false;
  c_pf_els_simpleEleId60relIso_ = false;
  c_pf_els_simpleEleId70cIso_ = false;
  c_pf_els_simpleEleId70relIso_ = false;
  c_pf_els_simpleEleId80cIso_ = false;
  c_pf_els_simpleEleId80relIso_ = false;
  c_pf_els_simpleEleId85cIso_ = false;
  c_pf_els_simpleEleId85relIso_ = false;
  c_pf_els_simpleEleId90cIso_ = false;
  c_pf_els_simpleEleId90relIso_ = false;
  c_pf_els_simpleEleId95cIso_ = false;
  c_pf_els_simpleEleId95relIso_ = false;
  c_pf_els_status_ = false;
  c_pf_els_tIso_ = false;
  c_pf_els_theta_ = false;
  c_pf_els_tightId_ = false;
  c_pf_els_tk_charge_ = false;
  c_pf_els_tk_eta_ = false;
  c_pf_els_tk_phi_ = false;
  c_pf_els_tk_pt_ = false;
  c_pf_els_tk_pz_ = false;
  c_pf_els_vpx_ = false;
  c_pf_els_vpy_ = false;
  c_pf_els_vpz_ = false;
  c_pf_els_vx_ = false;
  c_pf_els_vy_ = false;
  c_pf_els_vz_ = false;
  c_pf_mus_cIso_ = false;
  c_pf_mus_calEnergyEm_ = false;
  c_pf_mus_calEnergyEmS9_ = false;
  c_pf_mus_calEnergyHad_ = false;
  c_pf_mus_calEnergyHadS9_ = false;
  c_pf_mus_calEnergyHo_ = false;
  c_pf_mus_calEnergyHoS9_ = false;
  c_pf_mus_charge_ = false;
  c_pf_mus_chargedHadronIso_ = false;
  c_pf_mus_cm_ExpectedHitsInner_ = false;
  c_pf_mus_cm_ExpectedHitsOuter_ = false;
  c_pf_mus_cm_LayersWithMeasurement_ = false;
  c_pf_mus_cm_LayersWithoutMeasurement_ = false;
  c_pf_mus_cm_PixelLayersWithMeasurement_ = false;
  c_pf_mus_cm_ValidStripLayersWithMonoAndStereoHit_ = false;
  c_pf_mus_cm_chg_ = false;
  c_pf_mus_cm_chi2_ = false;
  c_pf_mus_cm_d0dum_ = false;
  c_pf_mus_cm_d0dumErr_ = false;
  c_pf_mus_cm_dz_ = false;
  c_pf_mus_cm_dzErr_ = false;
  c_pf_mus_cm_eta_ = false;
  c_pf_mus_cm_etaErr_ = false;
  c_pf_mus_cm_ndof_ = false;
  c_pf_mus_cm_numlosthits_ = false;
  c_pf_mus_cm_numvalMuonhits_ = false;
  c_pf_mus_cm_numvalhits_ = false;
  c_pf_mus_cm_phi_ = false;
  c_pf_mus_cm_phiErr_ = false;
  c_pf_mus_cm_pt_ = false;
  c_pf_mus_cm_ptErr_ = false;
  c_pf_mus_cm_px_ = false;
  c_pf_mus_cm_py_ = false;
  c_pf_mus_cm_pz_ = false;
  c_pf_mus_cm_theta_ = false;
  c_pf_mus_cm_vx_ = false;
  c_pf_mus_cm_vy_ = false;
  c_pf_mus_cm_vz_ = false;
  c_pf_mus_dB_ = false;
  c_pf_mus_ecalIso_ = false;
  c_pf_mus_energy_ = false;
  c_pf_mus_et_ = false;
  c_pf_mus_eta_ = false;
  c_pf_mus_gen_et_ = false;
  c_pf_mus_gen_eta_ = false;
  c_pf_mus_gen_id_ = false;
  c_pf_mus_gen_mother_et_ = false;
  c_pf_mus_gen_mother_eta_ = false;
  c_pf_mus_gen_mother_id_ = false;
  c_pf_mus_gen_mother_phi_ = false;
  c_pf_mus_gen_mother_pt_ = false;
  c_pf_mus_gen_mother_px_ = false;
  c_pf_mus_gen_mother_py_ = false;
  c_pf_mus_gen_mother_pz_ = false;
  c_pf_mus_gen_mother_theta_ = false;
  c_pf_mus_gen_phi_ = false;
  c_pf_mus_gen_pt_ = false;
  c_pf_mus_gen_px_ = false;
  c_pf_mus_gen_py_ = false;
  c_pf_mus_gen_pz_ = false;
  c_pf_mus_gen_theta_ = false;
  c_pf_mus_hcalIso_ = false;
  c_pf_mus_id_All_ = false;
  c_pf_mus_id_AllArbitrated_ = false;
  c_pf_mus_id_AllGlobalMuons_ = false;
  c_pf_mus_id_AllStandAloneMuons_ = false;
  c_pf_mus_id_AllTrackerMuons_ = false;
  c_pf_mus_id_GlobalMuonPromptTight_ = false;
  c_pf_mus_id_TM2DCompatibilityLoose_ = false;
  c_pf_mus_id_TM2DCompatibilityTight_ = false;
  c_pf_mus_id_TMLastStationLoose_ = false;
  c_pf_mus_id_TMLastStationOptimizedLowPtLoose_ = false;
  c_pf_mus_id_TMLastStationOptimizedLowPtTight_ = false;
  c_pf_mus_id_TMLastStationTight_ = false;
  c_pf_mus_id_TMOneStationLoose_ = false;
  c_pf_mus_id_TMOneStationTight_ = false;
  c_pf_mus_id_TrackerMuonArbitrated_ = false;
  c_pf_mus_isCaloMuon_ = false;
  c_pf_mus_isConvertedPhoton_ = false;
  c_pf_mus_isElectron_ = false;
  c_pf_mus_isGlobalMuon_ = false;
  c_pf_mus_isPFMuon_ = false;
  c_pf_mus_isPhoton_ = false;
  c_pf_mus_isStandAloneMuon_ = false;
  c_pf_mus_isTrackerMuon_ = false;
  c_pf_mus_iso03_emEt_ = false;
  c_pf_mus_iso03_emVetoEt_ = false;
  c_pf_mus_iso03_hadEt_ = false;
  c_pf_mus_iso03_hadVetoEt_ = false;
  c_pf_mus_iso03_hoEt_ = false;
  c_pf_mus_iso03_nTracks_ = false;
  c_pf_mus_iso03_sumPt_ = false;
  c_pf_mus_iso05_emEt_ = false;
  c_pf_mus_iso05_hadEt_ = false;
  c_pf_mus_iso05_hoEt_ = false;
  c_pf_mus_iso05_nTracks_ = false;
  c_pf_mus_iso05_sumPt_ = false;
  c_pf_mus_neutralHadronIso_ = false;
  c_pf_mus_num_matches_ = false;
  c_pf_mus_numberOfMatchedStations_ = false;
  c_pf_mus_pfIsolationR03_sumChargedHadronPt_ = false;
  c_pf_mus_pfIsolationR03_sumChargedParticlePt_ = false;
  c_pf_mus_pfIsolationR03_sumNeutralHadronEt_ = false;
  c_pf_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_ = false;
  c_pf_mus_pfIsolationR03_sumPUPt_ = false;
  c_pf_mus_pfIsolationR03_sumPhotonEt_ = false;
  c_pf_mus_pfIsolationR03_sumPhotonEtHighThreshold_ = false;
  c_pf_mus_pfIsolationR04_sumChargedHadronPt_ = false;
  c_pf_mus_pfIsolationR04_sumChargedParticlePt_ = false;
  c_pf_mus_pfIsolationR04_sumNeutralHadronEt_ = false;
  c_pf_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_ = false;
  c_pf_mus_pfIsolationR04_sumPUPt_ = false;
  c_pf_mus_pfIsolationR04_sumPhotonEt_ = false;
  c_pf_mus_pfIsolationR04_sumPhotonEtHighThreshold_ = false;
  c_pf_mus_phi_ = false;
  c_pf_mus_photonIso_ = false;
  c_pf_mus_picky_ExpectedHitsInner_ = false;
  c_pf_mus_picky_ExpectedHitsOuter_ = false;
  c_pf_mus_picky_LayersWithMeasurement_ = false;
  c_pf_mus_picky_LayersWithoutMeasurement_ = false;
  c_pf_mus_picky_PixelLayersWithMeasurement_ = false;
  c_pf_mus_picky_ValidStripLayersWithMonoAndStereoHit_ = false;
  c_pf_mus_picky_chg_ = false;
  c_pf_mus_picky_chi2_ = false;
  c_pf_mus_picky_d0dum_ = false;
  c_pf_mus_picky_d0dumErr_ = false;
  c_pf_mus_picky_dz_ = false;
  c_pf_mus_picky_dzErr_ = false;
  c_pf_mus_picky_eta_ = false;
  c_pf_mus_picky_etaErr_ = false;
  c_pf_mus_picky_id_ = false;
  c_pf_mus_picky_ndof_ = false;
  c_pf_mus_picky_numlosthits_ = false;
  c_pf_mus_picky_numvalPixelhits_ = false;
  c_pf_mus_picky_numvalhits_ = false;
  c_pf_mus_picky_phi_ = false;
  c_pf_mus_picky_phiErr_ = false;
  c_pf_mus_picky_pt_ = false;
  c_pf_mus_picky_ptErr_ = false;
  c_pf_mus_picky_px_ = false;
  c_pf_mus_picky_py_ = false;
  c_pf_mus_picky_pz_ = false;
  c_pf_mus_picky_theta_ = false;
  c_pf_mus_picky_vx_ = false;
  c_pf_mus_picky_vy_ = false;
  c_pf_mus_picky_vz_ = false;
  c_pf_mus_pt_ = false;
  c_pf_mus_px_ = false;
  c_pf_mus_py_ = false;
  c_pf_mus_pz_ = false;
  c_pf_mus_stamu_chg_ = false;
  c_pf_mus_stamu_chi2_ = false;
  c_pf_mus_stamu_d0dum_ = false;
  c_pf_mus_stamu_d0dumErr_ = false;
  c_pf_mus_stamu_dz_ = false;
  c_pf_mus_stamu_dzErr_ = false;
  c_pf_mus_stamu_eta_ = false;
  c_pf_mus_stamu_etaErr_ = false;
  c_pf_mus_stamu_ndof_ = false;
  c_pf_mus_stamu_numlosthits_ = false;
  c_pf_mus_stamu_numvalhits_ = false;
  c_pf_mus_stamu_phi_ = false;
  c_pf_mus_stamu_phiErr_ = false;
  c_pf_mus_stamu_pt_ = false;
  c_pf_mus_stamu_ptErr_ = false;
  c_pf_mus_stamu_px_ = false;
  c_pf_mus_stamu_py_ = false;
  c_pf_mus_stamu_pz_ = false;
  c_pf_mus_stamu_theta_ = false;
  c_pf_mus_stamu_vx_ = false;
  c_pf_mus_stamu_vy_ = false;
  c_pf_mus_stamu_vz_ = false;
  c_pf_mus_status_ = false;
  c_pf_mus_tIso_ = false;
  c_pf_mus_theta_ = false;
  c_pf_mus_tkHits_ = false;
  c_pf_mus_tk_ExpectedHitsInner_ = false;
  c_pf_mus_tk_ExpectedHitsOuter_ = false;
  c_pf_mus_tk_LayersWithMeasurement_ = false;
  c_pf_mus_tk_LayersWithoutMeasurement_ = false;
  c_pf_mus_tk_PixelLayersWithMeasurement_ = false;
  c_pf_mus_tk_ValidStripLayersWithMonoAndStereoHit_ = false;
  c_pf_mus_tk_chg_ = false;
  c_pf_mus_tk_chi2_ = false;
  c_pf_mus_tk_d0dum_ = false;
  c_pf_mus_tk_d0dumErr_ = false;
  c_pf_mus_tk_dz_ = false;
  c_pf_mus_tk_dzErr_ = false;
  c_pf_mus_tk_eta_ = false;
  c_pf_mus_tk_etaErr_ = false;
  c_pf_mus_tk_id_ = false;
  c_pf_mus_tk_ndof_ = false;
  c_pf_mus_tk_numlosthits_ = false;
  c_pf_mus_tk_numpixelWthMeasr_ = false;
  c_pf_mus_tk_numvalPixelhits_ = false;
  c_pf_mus_tk_numvalhits_ = false;
  c_pf_mus_tk_phi_ = false;
  c_pf_mus_tk_phiErr_ = false;
  c_pf_mus_tk_pt_ = false;
  c_pf_mus_tk_ptErr_ = false;
  c_pf_mus_tk_px_ = false;
  c_pf_mus_tk_py_ = false;
  c_pf_mus_tk_pz_ = false;
  c_pf_mus_tk_theta_ = false;
  c_pf_mus_tk_vx_ = false;
  c_pf_mus_tk_vy_ = false;
  c_pf_mus_tk_vz_ = false;
  c_pf_mus_tpfms_ExpectedHitsInner_ = false;
  c_pf_mus_tpfms_ExpectedHitsOuter_ = false;
  c_pf_mus_tpfms_LayersWithMeasurement_ = false;
  c_pf_mus_tpfms_LayersWithoutMeasurement_ = false;
  c_pf_mus_tpfms_PixelLayersWithMeasurement_ = false;
  c_pf_mus_tpfms_ValidStripLayersWithMonoAndStereoHit_ = false;
  c_pf_mus_tpfms_chg_ = false;
  c_pf_mus_tpfms_chi2_ = false;
  c_pf_mus_tpfms_d0dum_ = false;
  c_pf_mus_tpfms_d0dumErr_ = false;
  c_pf_mus_tpfms_dz_ = false;
  c_pf_mus_tpfms_dzErr_ = false;
  c_pf_mus_tpfms_eta_ = false;
  c_pf_mus_tpfms_etaErr_ = false;
  c_pf_mus_tpfms_id_ = false;
  c_pf_mus_tpfms_ndof_ = false;
  c_pf_mus_tpfms_numlosthits_ = false;
  c_pf_mus_tpfms_numvalPixelhits_ = false;
  c_pf_mus_tpfms_numvalhits_ = false;
  c_pf_mus_tpfms_phi_ = false;
  c_pf_mus_tpfms_phiErr_ = false;
  c_pf_mus_tpfms_pt_ = false;
  c_pf_mus_tpfms_ptErr_ = false;
  c_pf_mus_tpfms_px_ = false;
  c_pf_mus_tpfms_py_ = false;
  c_pf_mus_tpfms_pz_ = false;
  c_pf_mus_tpfms_theta_ = false;
  c_pf_mus_tpfms_vx_ = false;
  c_pf_mus_tpfms_vy_ = false;
  c_pf_mus_tpfms_vz_ = false;
  c_pf_photons_chIso_ = false;
  c_pf_photons_e1x5_ = false;
  c_pf_photons_e2x5_ = false;
  c_pf_photons_e3x3_ = false;
  c_pf_photons_e5x5_ = false;
  c_pf_photons_energy_ = false;
  c_pf_photons_et_ = false;
  c_pf_photons_eta_ = false;
  c_pf_photons_hadOverEM_ = false;
  c_pf_photons_hadTowOverEM_ = false;
  c_pf_photons_hasPixelSeed_ = false;
  c_pf_photons_isAlsoElectron_ = false;
  c_pf_photons_isConverted_ = false;
  c_pf_photons_isEBEEGap_ = false;
  c_pf_photons_isEBGap_ = false;
  c_pf_photons_isEBPho_ = false;
  c_pf_photons_isEEGap_ = false;
  c_pf_photons_isEEPho_ = false;
  c_pf_photons_maxEnergyXtal_ = false;
  c_pf_photons_nhIso_ = false;
  c_pf_photons_phIso_ = false;
  c_pf_photons_phi_ = false;
  c_pf_photons_pt_ = false;
  c_pf_photons_px_ = false;
  c_pf_photons_py_ = false;
  c_pf_photons_pz_ = false;
  c_pf_photons_r9_ = false;
  c_pf_photons_scEnergy_ = false;
  c_pf_photons_scEta_ = false;
  c_pf_photons_scEtaWidth_ = false;
  c_pf_photons_scPhi_ = false;
  c_pf_photons_scPhiWidth_ = false;
  c_pf_photons_scRawEnergy_ = false;
  c_pf_photons_sigmaEtaEta_ = false;
  c_pf_photons_sigmaIetaIeta_ = false;
  c_pf_photons_status_ = false;
  c_pf_photons_theta_ = false;
  c_pfcand_charge_ = false;
  c_pfcand_energy_ = false;
  c_pfcand_eta_ = false;
  c_pfcand_particleId_ = false;
  c_pfcand_pdgId_ = false;
  c_pfcand_phi_ = false;
  c_pfcand_pt_ = false;
  c_pfcand_px_ = false;
  c_pfcand_py_ = false;
  c_pfcand_pz_ = false;
  c_pfcand_theta_ = false;
  c_pfmets_et_ = false;
  c_pfmets_ex_ = false;
  c_pfmets_ey_ = false;
  c_pfmets_fullSignif_ = false;
  c_pfmets_fullSignifCov00_ = false;
  c_pfmets_fullSignifCov00_2012_ = false;
  c_pfmets_fullSignifCov00_2012_dataRes_ = false;
  c_pfmets_fullSignifCov10_ = false;
  c_pfmets_fullSignifCov10_2012_ = false;
  c_pfmets_fullSignifCov10_2012_dataRes_ = false;
  c_pfmets_fullSignifCov11_ = false;
  c_pfmets_fullSignifCov11_2012_ = false;
  c_pfmets_fullSignifCov11_2012_dataRes_ = false;
  c_pfmets_fullSignif_2012_ = false;
  c_pfmets_fullSignif_2012_dataRes_ = false;
  c_pfmets_gen_et_ = false;
  c_pfmets_gen_phi_ = false;
  c_pfmets_phi_ = false;
  c_pfmets_sign_ = false;
  c_pfmets_sumEt_ = false;
  c_pfmets_unCPhi_ = false;
  c_pfmets_unCPt_ = false;
  c_photon_chIsoValues_ = false;
  c_photon_nhIsoValues_ = false;
  c_photon_passElectronVeto_ = false;
  c_photon_phIsoValues_ = false;
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
  c_puJet_rejectionBeta_ = false;
  c_puJet_rejectionMVA_ = false;
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
  c_rho_kt6PFJetsForIsolation2011_ = false;
  c_rho_kt6PFJetsForIsolation2012_ = false;
  c_run_ = false;
  c_scrapingVeto_decision_ = false;
  c_softjetUp_dMEx_ = false;
  c_softjetUp_dMEy_ = false;
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
  c_tcmets_et_ = false;
  c_tcmets_ex_ = false;
  c_tcmets_ey_ = false;
  c_tcmets_phi_ = false;
  c_tcmets_sumEt_ = false;
  c_trackercoherentnoisefilter1_decision_ = false;
  c_trackercoherentnoisefilter2_decision_ = false;
  c_trackertoomanyclustersfilter_decision_ = false;
  c_trackertoomanyseedsfilter_decision_ = false;
  c_trackertoomanytripletsfilter_decision_ = false;
  c_trackingfailurefilter_decision_ = false;
  c_tracks_chg_ = false;
  c_tracks_chi2_ = false;
  c_tracks_d0dum_ = false;
  c_tracks_d0dumErr_ = false;
  c_tracks_dz_ = false;
  c_tracks_dzErr_ = false;
  c_tracks_eta_ = false;
  c_tracks_etaErr_ = false;
  c_tracks_highPurity_ = false;
  c_tracks_ndof_ = false;
  c_tracks_numlosthits_ = false;
  c_tracks_numvalhits_ = false;
  c_tracks_phi_ = false;
  c_tracks_phiErr_ = false;
  c_tracks_pt_ = false;
  c_tracks_ptErr_ = false;
  c_tracks_px_ = false;
  c_tracks_py_ = false;
  c_tracks_pz_ = false;
  c_tracks_vx_ = false;
  c_tracks_vy_ = false;
  c_tracks_vz_ = false;
  c_trigger_decision_ = false;
  c_trigger_lastfiltername_ = false;
  c_trigger_name_ = false;
  c_trigger_prescalevalue_ = false;
  c_triggerobject_collectionname_ = false;
  c_triggerobject_energy_ = false;
  c_triggerobject_et_ = false;
  c_triggerobject_eta_ = false;
  c_triggerobject_phi_ = false;
  c_triggerobject_pt_ = false;
  c_triggerobject_px_ = false;
  c_triggerobject_py_ = false;
  c_triggerobject_pz_ = false;
  c_trk_nTOBTEC_ = false;
  c_trk_ratioAllTOBTEC_ = false;
  c_trk_ratioJetTOBTEC_ = false;
  c_weight_ = false;
  const long entry_a = chainA_.LoadTree(entry);
  const long entry_b = chainB_.LoadTree(entry);
  if(entry_a!=entry_b) throw std::runtime_error("Entry is in different trees for chains A and B");
  entry_ = entry_a;
}

void cfa_8::InitializeA(){
  chainA_.SetBranchAddress("L1trigger_alias", &L1trigger_alias_, &b_L1trigger_alias_);
  chainA_.SetBranchAddress("L1trigger_bit", &L1trigger_bit_, &b_L1trigger_bit_);
  chainA_.SetBranchAddress("L1trigger_decision", &L1trigger_decision_, &b_L1trigger_decision_);
  chainA_.SetBranchAddress("L1trigger_decision_nomask", &L1trigger_decision_nomask_, &b_L1trigger_decision_nomask_);
  chainA_.SetBranchAddress("L1trigger_name", &L1trigger_name_, &b_L1trigger_name_);
  chainA_.SetBranchAddress("L1trigger_prescalevalue", &L1trigger_prescalevalue_, &b_L1trigger_prescalevalue_);
  chainA_.SetBranchAddress("L1trigger_techTrigger", &L1trigger_techTrigger_, &b_L1trigger_techTrigger_);
  chainA_.SetBranchAddress("MPT", &MPT_, &b_MPT_);
  chainA_.SetBranchAddress("PU_NumInteractions", &PU_NumInteractions_, &b_PU_NumInteractions_);
  chainA_.SetBranchAddress("PU_TrueNumInteractions", &PU_TrueNumInteractions_, &b_PU_TrueNumInteractions_);
  chainA_.SetBranchAddress("PU_bunchCrossing", &PU_bunchCrossing_, &b_PU_bunchCrossing_);
  chainA_.SetBranchAddress("PU_ntrks_highpT", &PU_ntrks_highpT_, &b_PU_ntrks_highpT_);
  chainA_.SetBranchAddress("PU_ntrks_lowpT", &PU_ntrks_lowpT_, &b_PU_ntrks_lowpT_);
  chainA_.SetBranchAddress("PU_sumpT_highpT", &PU_sumpT_highpT_, &b_PU_sumpT_highpT_);
  chainA_.SetBranchAddress("PU_sumpT_lowpT", &PU_sumpT_lowpT_, &b_PU_sumpT_lowpT_);
  chainA_.SetBranchAddress("PU_zpositions", &PU_zpositions_, &b_PU_zpositions_);
  chainA_.SetBranchAddress("cschalofilter_decision", &cschalofilter_decision_, &b_cschalofilter_decision_);
  chainA_.SetBranchAddress("ecalBEfilter_decision", &ecalBEfilter_decision_, &b_ecalBEfilter_decision_);
  chainA_.SetBranchAddress("ecalTPfilter_decision", &ecalTPfilter_decision_, &b_ecalTPfilter_decision_);
  chainA_.SetBranchAddress("ecallaserfilter_decision", &ecallaserfilter_decision_, &b_ecallaserfilter_decision_);
  chainA_.SetBranchAddress("eebadscfilter_decision", &eebadscfilter_decision_, &b_eebadscfilter_decision_);
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
  chainA_.SetBranchAddress("hcallaserfilter_decision", &hcallaserfilter_decision_, &b_hcallaserfilter_decision_);
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
  chainA_.SetBranchAddress("standalone_triggerobject_collectionname", &standalone_triggerobject_collectionname_, &b_standalone_triggerobject_collectionname_);
  chainA_.SetBranchAddress("standalone_triggerobject_energy", &standalone_triggerobject_energy_, &b_standalone_triggerobject_energy_);
  chainA_.SetBranchAddress("standalone_triggerobject_et", &standalone_triggerobject_et_, &b_standalone_triggerobject_et_);
  chainA_.SetBranchAddress("standalone_triggerobject_eta", &standalone_triggerobject_eta_, &b_standalone_triggerobject_eta_);
  chainA_.SetBranchAddress("standalone_triggerobject_phi", &standalone_triggerobject_phi_, &b_standalone_triggerobject_phi_);
  chainA_.SetBranchAddress("standalone_triggerobject_pt", &standalone_triggerobject_pt_, &b_standalone_triggerobject_pt_);
  chainA_.SetBranchAddress("standalone_triggerobject_px", &standalone_triggerobject_px_, &b_standalone_triggerobject_px_);
  chainA_.SetBranchAddress("standalone_triggerobject_py", &standalone_triggerobject_py_, &b_standalone_triggerobject_py_);
  chainA_.SetBranchAddress("standalone_triggerobject_pz", &standalone_triggerobject_pz_, &b_standalone_triggerobject_pz_);
  chainA_.SetBranchAddress("trackercoherentnoisefilter1_decision", &trackercoherentnoisefilter1_decision_, &b_trackercoherentnoisefilter1_decision_);
  chainA_.SetBranchAddress("trackercoherentnoisefilter2_decision", &trackercoherentnoisefilter2_decision_, &b_trackercoherentnoisefilter2_decision_);
  chainA_.SetBranchAddress("trackertoomanyclustersfilter_decision", &trackertoomanyclustersfilter_decision_, &b_trackertoomanyclustersfilter_decision_);
  chainA_.SetBranchAddress("trackertoomanyseedsfilter_decision", &trackertoomanyseedsfilter_decision_, &b_trackertoomanyseedsfilter_decision_);
  chainA_.SetBranchAddress("trackertoomanytripletsfilter_decision", &trackertoomanytripletsfilter_decision_, &b_trackertoomanytripletsfilter_decision_);
  chainA_.SetBranchAddress("trackingfailurefilter_decision", &trackingfailurefilter_decision_, &b_trackingfailurefilter_decision_);
  chainA_.SetBranchAddress("trigger_decision", &v_trigger_decision_, &b_trigger_decision_);
  chainA_.SetBranchAddress("trigger_lastfiltername", &trigger_lastfiltername_, &b_trigger_lastfiltername_);
  chainA_.SetBranchAddress("trigger_name", &trigger_name_, &b_trigger_name_);
  chainA_.SetBranchAddress("trigger_prescalevalue", &trigger_prescalevalue_, &b_trigger_prescalevalue_);
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
  chainB_.SetBranchAddress("NbeamSpot", &NbeamSpot_, &b_NbeamSpot_);
  chainB_.SetBranchAddress("Nels", &Nels_, &b_Nels_);
  chainB_.SetBranchAddress("Njets_AK5PF", &Njets_AK5PF_, &b_Njets_AK5PF_);
  chainB_.SetBranchAddress("Njets_AK5PFclean", &Njets_AK5PFclean_, &b_Njets_AK5PFclean_);
  chainB_.SetBranchAddress("Nmc_doc", &Nmc_doc_, &b_Nmc_doc_);
  chainB_.SetBranchAddress("Nmc_electrons", &Nmc_electrons_, &b_Nmc_electrons_);
  chainB_.SetBranchAddress("Nmc_mus", &Nmc_mus_, &b_Nmc_mus_);
  chainB_.SetBranchAddress("Nmc_nues", &Nmc_nues_, &b_Nmc_nues_);
  chainB_.SetBranchAddress("Nmc_numus", &Nmc_numus_, &b_Nmc_numus_);
  chainB_.SetBranchAddress("Nmc_nutaus", &Nmc_nutaus_, &b_Nmc_nutaus_);
  chainB_.SetBranchAddress("Nmc_pdf", &Nmc_pdf_, &b_Nmc_pdf_);
  chainB_.SetBranchAddress("Nmc_photons", &Nmc_photons_, &b_Nmc_photons_);
  chainB_.SetBranchAddress("Nmc_taus", &Nmc_taus_, &b_Nmc_taus_);
  chainB_.SetBranchAddress("NmetsHO", &NmetsHO_, &b_NmetsHO_);
  chainB_.SetBranchAddress("Nmets_AK5", &Nmets_AK5_, &b_Nmets_AK5_);
  chainB_.SetBranchAddress("Nmus", &Nmus_, &b_Nmus_);
  chainB_.SetBranchAddress("NpfTypeINoXYCorrmets", &NpfTypeINoXYCorrmets_, &b_NpfTypeINoXYCorrmets_);
  chainB_.SetBranchAddress("NpfTypeIType0mets", &NpfTypeIType0mets_, &b_NpfTypeIType0mets_);
  chainB_.SetBranchAddress("NpfTypeImets", &NpfTypeImets_, &b_NpfTypeImets_);
  chainB_.SetBranchAddress("Npf_els", &Npf_els_, &b_Npf_els_);
  chainB_.SetBranchAddress("Npf_mus", &Npf_mus_, &b_Npf_mus_);
  chainB_.SetBranchAddress("Npf_photons", &Npf_photons_, &b_Npf_photons_);
  chainB_.SetBranchAddress("Npfcand", &Npfcand_, &b_Npfcand_);
  chainB_.SetBranchAddress("Npfmets", &Npfmets_, &b_Npfmets_);
  chainB_.SetBranchAddress("Nphotons", &Nphotons_, &b_Nphotons_);
  chainB_.SetBranchAddress("Npv", &Npv_, &b_Npv_);
  chainB_.SetBranchAddress("Ntaus", &Ntaus_, &b_Ntaus_);
  chainB_.SetBranchAddress("Ntcmets", &Ntcmets_, &b_Ntcmets_);
  chainB_.SetBranchAddress("Ntracks", &Ntracks_, &b_Ntracks_);
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
  chainB_.SetBranchAddress("mc_pdf_id1", &mc_pdf_id1_, &b_mc_pdf_id1_);
  chainB_.SetBranchAddress("mc_pdf_id2", &mc_pdf_id2_, &b_mc_pdf_id2_);
  chainB_.SetBranchAddress("mc_pdf_q", &mc_pdf_q_, &b_mc_pdf_q_);
  chainB_.SetBranchAddress("mc_pdf_x1", &mc_pdf_x1_, &b_mc_pdf_x1_);
  chainB_.SetBranchAddress("mc_pdf_x2", &mc_pdf_x2_, &b_mc_pdf_x2_);
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
  chainB_.SetBranchAddress("pfcand_charge", &pfcand_charge_, &b_pfcand_charge_);
  chainB_.SetBranchAddress("pfcand_energy", &pfcand_energy_, &b_pfcand_energy_);
  chainB_.SetBranchAddress("pfcand_eta", &pfcand_eta_, &b_pfcand_eta_);
  chainB_.SetBranchAddress("pfcand_particleId", &pfcand_particleId_, &b_pfcand_particleId_);
  chainB_.SetBranchAddress("pfcand_pdgId", &pfcand_pdgId_, &b_pfcand_pdgId_);
  chainB_.SetBranchAddress("pfcand_phi", &pfcand_phi_, &b_pfcand_phi_);
  chainB_.SetBranchAddress("pfcand_pt", &pfcand_pt_, &b_pfcand_pt_);
  chainB_.SetBranchAddress("pfcand_px", &pfcand_px_, &b_pfcand_px_);
  chainB_.SetBranchAddress("pfcand_py", &pfcand_py_, &b_pfcand_py_);
  chainB_.SetBranchAddress("pfcand_pz", &pfcand_pz_, &b_pfcand_pz_);
  chainB_.SetBranchAddress("pfcand_theta", &pfcand_theta_, &b_pfcand_theta_);
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
  chainB_.SetBranchAddress("weight", &weight_, &b_weight_);
}

cfa_8::~cfa_8(){
}

std::vector<std::string>* const & cfa_8::L1trigger_alias() const{
  if(!c_L1trigger_alias_ && b_L1trigger_alias_){
    b_L1trigger_alias_->GetEntry(entry_);
    c_L1trigger_alias_ = true;
  }
  return L1trigger_alias_;
}

std::vector<float>* const & cfa_8::L1trigger_bit() const{
  if(!c_L1trigger_bit_ && b_L1trigger_bit_){
    b_L1trigger_bit_->GetEntry(entry_);
    c_L1trigger_bit_ = true;
  }
  return L1trigger_bit_;
}

std::vector<float>* const & cfa_8::L1trigger_decision() const{
  if(!c_L1trigger_decision_ && b_L1trigger_decision_){
    b_L1trigger_decision_->GetEntry(entry_);
    c_L1trigger_decision_ = true;
  }
  return L1trigger_decision_;
}

std::vector<float>* const & cfa_8::L1trigger_decision_nomask() const{
  if(!c_L1trigger_decision_nomask_ && b_L1trigger_decision_nomask_){
    b_L1trigger_decision_nomask_->GetEntry(entry_);
    c_L1trigger_decision_nomask_ = true;
  }
  return L1trigger_decision_nomask_;
}

std::vector<std::string>* const & cfa_8::L1trigger_name() const{
  if(!c_L1trigger_name_ && b_L1trigger_name_){
    b_L1trigger_name_->GetEntry(entry_);
    c_L1trigger_name_ = true;
  }
  return L1trigger_name_;
}

std::vector<float>* const & cfa_8::L1trigger_prescalevalue() const{
  if(!c_L1trigger_prescalevalue_ && b_L1trigger_prescalevalue_){
    b_L1trigger_prescalevalue_->GetEntry(entry_);
    c_L1trigger_prescalevalue_ = true;
  }
  return L1trigger_prescalevalue_;
}

std::vector<float>* const & cfa_8::L1trigger_techTrigger() const{
  if(!c_L1trigger_techTrigger_ && b_L1trigger_techTrigger_){
    b_L1trigger_techTrigger_->GetEntry(entry_);
    c_L1trigger_techTrigger_ = true;
  }
  return L1trigger_techTrigger_;
}

Float_t const & cfa_8::MPT() const{
  if(!c_MPT_ && b_MPT_){
    b_MPT_->GetEntry(entry_);
    c_MPT_ = true;
  }
  return MPT_;
}

UInt_t const & cfa_8::NbeamSpot() const{
  if(!c_NbeamSpot_ && b_NbeamSpot_){
    b_NbeamSpot_->GetEntry(entry_);
    c_NbeamSpot_ = true;
  }
  return NbeamSpot_;
}

UInt_t const & cfa_8::Nels() const{
  if(!c_Nels_ && b_Nels_){
    b_Nels_->GetEntry(entry_);
    c_Nels_ = true;
  }
  return Nels_;
}

UInt_t const & cfa_8::Njets_AK5PF() const{
  if(!c_Njets_AK5PF_ && b_Njets_AK5PF_){
    b_Njets_AK5PF_->GetEntry(entry_);
    c_Njets_AK5PF_ = true;
  }
  return Njets_AK5PF_;
}

UInt_t const & cfa_8::Njets_AK5PFclean() const{
  if(!c_Njets_AK5PFclean_ && b_Njets_AK5PFclean_){
    b_Njets_AK5PFclean_->GetEntry(entry_);
    c_Njets_AK5PFclean_ = true;
  }
  return Njets_AK5PFclean_;
}

UInt_t const & cfa_8::Nmc_doc() const{
  if(!c_Nmc_doc_ && b_Nmc_doc_){
    b_Nmc_doc_->GetEntry(entry_);
    c_Nmc_doc_ = true;
  }
  return Nmc_doc_;
}

UInt_t const & cfa_8::Nmc_electrons() const{
  if(!c_Nmc_electrons_ && b_Nmc_electrons_){
    b_Nmc_electrons_->GetEntry(entry_);
    c_Nmc_electrons_ = true;
  }
  return Nmc_electrons_;
}

UInt_t const & cfa_8::Nmc_mus() const{
  if(!c_Nmc_mus_ && b_Nmc_mus_){
    b_Nmc_mus_->GetEntry(entry_);
    c_Nmc_mus_ = true;
  }
  return Nmc_mus_;
}

UInt_t const & cfa_8::Nmc_nues() const{
  if(!c_Nmc_nues_ && b_Nmc_nues_){
    b_Nmc_nues_->GetEntry(entry_);
    c_Nmc_nues_ = true;
  }
  return Nmc_nues_;
}

UInt_t const & cfa_8::Nmc_numus() const{
  if(!c_Nmc_numus_ && b_Nmc_numus_){
    b_Nmc_numus_->GetEntry(entry_);
    c_Nmc_numus_ = true;
  }
  return Nmc_numus_;
}

UInt_t const & cfa_8::Nmc_nutaus() const{
  if(!c_Nmc_nutaus_ && b_Nmc_nutaus_){
    b_Nmc_nutaus_->GetEntry(entry_);
    c_Nmc_nutaus_ = true;
  }
  return Nmc_nutaus_;
}

UInt_t const & cfa_8::Nmc_pdf() const{
  if(!c_Nmc_pdf_ && b_Nmc_pdf_){
    b_Nmc_pdf_->GetEntry(entry_);
    c_Nmc_pdf_ = true;
  }
  return Nmc_pdf_;
}

UInt_t const & cfa_8::Nmc_photons() const{
  if(!c_Nmc_photons_ && b_Nmc_photons_){
    b_Nmc_photons_->GetEntry(entry_);
    c_Nmc_photons_ = true;
  }
  return Nmc_photons_;
}

UInt_t const & cfa_8::Nmc_taus() const{
  if(!c_Nmc_taus_ && b_Nmc_taus_){
    b_Nmc_taus_->GetEntry(entry_);
    c_Nmc_taus_ = true;
  }
  return Nmc_taus_;
}

UInt_t const & cfa_8::NmetsHO() const{
  if(!c_NmetsHO_ && b_NmetsHO_){
    b_NmetsHO_->GetEntry(entry_);
    c_NmetsHO_ = true;
  }
  return NmetsHO_;
}

UInt_t const & cfa_8::Nmets_AK5() const{
  if(!c_Nmets_AK5_ && b_Nmets_AK5_){
    b_Nmets_AK5_->GetEntry(entry_);
    c_Nmets_AK5_ = true;
  }
  return Nmets_AK5_;
}

UInt_t const & cfa_8::Nmus() const{
  if(!c_Nmus_ && b_Nmus_){
    b_Nmus_->GetEntry(entry_);
    c_Nmus_ = true;
  }
  return Nmus_;
}

UInt_t const & cfa_8::NpfTypeINoXYCorrmets() const{
  if(!c_NpfTypeINoXYCorrmets_ && b_NpfTypeINoXYCorrmets_){
    b_NpfTypeINoXYCorrmets_->GetEntry(entry_);
    c_NpfTypeINoXYCorrmets_ = true;
  }
  return NpfTypeINoXYCorrmets_;
}

UInt_t const & cfa_8::NpfTypeIType0mets() const{
  if(!c_NpfTypeIType0mets_ && b_NpfTypeIType0mets_){
    b_NpfTypeIType0mets_->GetEntry(entry_);
    c_NpfTypeIType0mets_ = true;
  }
  return NpfTypeIType0mets_;
}

UInt_t const & cfa_8::NpfTypeImets() const{
  if(!c_NpfTypeImets_ && b_NpfTypeImets_){
    b_NpfTypeImets_->GetEntry(entry_);
    c_NpfTypeImets_ = true;
  }
  return NpfTypeImets_;
}

UInt_t const & cfa_8::Npf_els() const{
  if(!c_Npf_els_ && b_Npf_els_){
    b_Npf_els_->GetEntry(entry_);
    c_Npf_els_ = true;
  }
  return Npf_els_;
}

UInt_t const & cfa_8::Npf_mus() const{
  if(!c_Npf_mus_ && b_Npf_mus_){
    b_Npf_mus_->GetEntry(entry_);
    c_Npf_mus_ = true;
  }
  return Npf_mus_;
}

UInt_t const & cfa_8::Npf_photons() const{
  if(!c_Npf_photons_ && b_Npf_photons_){
    b_Npf_photons_->GetEntry(entry_);
    c_Npf_photons_ = true;
  }
  return Npf_photons_;
}

UInt_t const & cfa_8::Npfcand() const{
  if(!c_Npfcand_ && b_Npfcand_){
    b_Npfcand_->GetEntry(entry_);
    c_Npfcand_ = true;
  }
  return Npfcand_;
}

UInt_t const & cfa_8::Npfmets() const{
  if(!c_Npfmets_ && b_Npfmets_){
    b_Npfmets_->GetEntry(entry_);
    c_Npfmets_ = true;
  }
  return Npfmets_;
}

UInt_t const & cfa_8::Nphotons() const{
  if(!c_Nphotons_ && b_Nphotons_){
    b_Nphotons_->GetEntry(entry_);
    c_Nphotons_ = true;
  }
  return Nphotons_;
}

UInt_t const & cfa_8::Npv() const{
  if(!c_Npv_ && b_Npv_){
    b_Npv_->GetEntry(entry_);
    c_Npv_ = true;
  }
  return Npv_;
}

UInt_t const & cfa_8::Ntaus() const{
  if(!c_Ntaus_ && b_Ntaus_){
    b_Ntaus_->GetEntry(entry_);
    c_Ntaus_ = true;
  }
  return Ntaus_;
}

UInt_t const & cfa_8::Ntcmets() const{
  if(!c_Ntcmets_ && b_Ntcmets_){
    b_Ntcmets_->GetEntry(entry_);
    c_Ntcmets_ = true;
  }
  return Ntcmets_;
}

UInt_t const & cfa_8::Ntracks() const{
  if(!c_Ntracks_ && b_Ntracks_){
    b_Ntracks_->GetEntry(entry_);
    c_Ntracks_ = true;
  }
  return Ntracks_;
}

std::vector<int>* const & cfa_8::PU_NumInteractions() const{
  if(!c_PU_NumInteractions_ && b_PU_NumInteractions_){
    b_PU_NumInteractions_->GetEntry(entry_);
    c_PU_NumInteractions_ = true;
  }
  return PU_NumInteractions_;
}

std::vector<float>* const & cfa_8::PU_TrueNumInteractions() const{
  if(!c_PU_TrueNumInteractions_ && b_PU_TrueNumInteractions_){
    b_PU_TrueNumInteractions_->GetEntry(entry_);
    c_PU_TrueNumInteractions_ = true;
  }
  return PU_TrueNumInteractions_;
}

std::vector<int>* const & cfa_8::PU_bunchCrossing() const{
  if(!c_PU_bunchCrossing_ && b_PU_bunchCrossing_){
    b_PU_bunchCrossing_->GetEntry(entry_);
    c_PU_bunchCrossing_ = true;
  }
  return PU_bunchCrossing_;
}

std::vector<std::vector<int> >* const & cfa_8::PU_ntrks_highpT() const{
  if(!c_PU_ntrks_highpT_ && b_PU_ntrks_highpT_){
    b_PU_ntrks_highpT_->GetEntry(entry_);
    c_PU_ntrks_highpT_ = true;
  }
  return PU_ntrks_highpT_;
}

std::vector<std::vector<int> >* const & cfa_8::PU_ntrks_lowpT() const{
  if(!c_PU_ntrks_lowpT_ && b_PU_ntrks_lowpT_){
    b_PU_ntrks_lowpT_->GetEntry(entry_);
    c_PU_ntrks_lowpT_ = true;
  }
  return PU_ntrks_lowpT_;
}

std::vector<std::vector<float> >* const & cfa_8::PU_sumpT_highpT() const{
  if(!c_PU_sumpT_highpT_ && b_PU_sumpT_highpT_){
    b_PU_sumpT_highpT_->GetEntry(entry_);
    c_PU_sumpT_highpT_ = true;
  }
  return PU_sumpT_highpT_;
}

std::vector<std::vector<float> >* const & cfa_8::PU_sumpT_lowpT() const{
  if(!c_PU_sumpT_lowpT_ && b_PU_sumpT_lowpT_){
    b_PU_sumpT_lowpT_->GetEntry(entry_);
    c_PU_sumpT_lowpT_ = true;
  }
  return PU_sumpT_lowpT_;
}

std::vector<std::vector<float> >* const & cfa_8::PU_zpositions() const{
  if(!c_PU_zpositions_ && b_PU_zpositions_){
    b_PU_zpositions_->GetEntry(entry_);
    c_PU_zpositions_ = true;
  }
  return PU_zpositions_;
}

std::vector<float>* const & cfa_8::beamSpot_beamWidthX() const{
  if(!c_beamSpot_beamWidthX_ && b_beamSpot_beamWidthX_){
    b_beamSpot_beamWidthX_->GetEntry(entry_);
    c_beamSpot_beamWidthX_ = true;
  }
  return beamSpot_beamWidthX_;
}

std::vector<float>* const & cfa_8::beamSpot_beamWidthXError() const{
  if(!c_beamSpot_beamWidthXError_ && b_beamSpot_beamWidthXError_){
    b_beamSpot_beamWidthXError_->GetEntry(entry_);
    c_beamSpot_beamWidthXError_ = true;
  }
  return beamSpot_beamWidthXError_;
}

std::vector<float>* const & cfa_8::beamSpot_beamWidthY() const{
  if(!c_beamSpot_beamWidthY_ && b_beamSpot_beamWidthY_){
    b_beamSpot_beamWidthY_->GetEntry(entry_);
    c_beamSpot_beamWidthY_ = true;
  }
  return beamSpot_beamWidthY_;
}

std::vector<float>* const & cfa_8::beamSpot_beamWidthYError() const{
  if(!c_beamSpot_beamWidthYError_ && b_beamSpot_beamWidthYError_){
    b_beamSpot_beamWidthYError_->GetEntry(entry_);
    c_beamSpot_beamWidthYError_ = true;
  }
  return beamSpot_beamWidthYError_;
}

std::vector<float>* const & cfa_8::beamSpot_dxdz() const{
  if(!c_beamSpot_dxdz_ && b_beamSpot_dxdz_){
    b_beamSpot_dxdz_->GetEntry(entry_);
    c_beamSpot_dxdz_ = true;
  }
  return beamSpot_dxdz_;
}

std::vector<float>* const & cfa_8::beamSpot_dxdzError() const{
  if(!c_beamSpot_dxdzError_ && b_beamSpot_dxdzError_){
    b_beamSpot_dxdzError_->GetEntry(entry_);
    c_beamSpot_dxdzError_ = true;
  }
  return beamSpot_dxdzError_;
}

std::vector<float>* const & cfa_8::beamSpot_dydz() const{
  if(!c_beamSpot_dydz_ && b_beamSpot_dydz_){
    b_beamSpot_dydz_->GetEntry(entry_);
    c_beamSpot_dydz_ = true;
  }
  return beamSpot_dydz_;
}

std::vector<float>* const & cfa_8::beamSpot_dydzError() const{
  if(!c_beamSpot_dydzError_ && b_beamSpot_dydzError_){
    b_beamSpot_dydzError_->GetEntry(entry_);
    c_beamSpot_dydzError_ = true;
  }
  return beamSpot_dydzError_;
}

std::vector<float>* const & cfa_8::beamSpot_sigmaZ() const{
  if(!c_beamSpot_sigmaZ_ && b_beamSpot_sigmaZ_){
    b_beamSpot_sigmaZ_->GetEntry(entry_);
    c_beamSpot_sigmaZ_ = true;
  }
  return beamSpot_sigmaZ_;
}

std::vector<float>* const & cfa_8::beamSpot_sigmaZ0Error() const{
  if(!c_beamSpot_sigmaZ0Error_ && b_beamSpot_sigmaZ0Error_){
    b_beamSpot_sigmaZ0Error_->GetEntry(entry_);
    c_beamSpot_sigmaZ0Error_ = true;
  }
  return beamSpot_sigmaZ0Error_;
}

std::vector<float>* const & cfa_8::beamSpot_x() const{
  if(!c_beamSpot_x_ && b_beamSpot_x_){
    b_beamSpot_x_->GetEntry(entry_);
    c_beamSpot_x_ = true;
  }
  return beamSpot_x_;
}

std::vector<float>* const & cfa_8::beamSpot_x0Error() const{
  if(!c_beamSpot_x0Error_ && b_beamSpot_x0Error_){
    b_beamSpot_x0Error_->GetEntry(entry_);
    c_beamSpot_x0Error_ = true;
  }
  return beamSpot_x0Error_;
}

std::vector<float>* const & cfa_8::beamSpot_y() const{
  if(!c_beamSpot_y_ && b_beamSpot_y_){
    b_beamSpot_y_->GetEntry(entry_);
    c_beamSpot_y_ = true;
  }
  return beamSpot_y_;
}

std::vector<float>* const & cfa_8::beamSpot_y0Error() const{
  if(!c_beamSpot_y0Error_ && b_beamSpot_y0Error_){
    b_beamSpot_y0Error_->GetEntry(entry_);
    c_beamSpot_y0Error_ = true;
  }
  return beamSpot_y0Error_;
}

std::vector<float>* const & cfa_8::beamSpot_z() const{
  if(!c_beamSpot_z_ && b_beamSpot_z_){
    b_beamSpot_z_->GetEntry(entry_);
    c_beamSpot_z_ = true;
  }
  return beamSpot_z_;
}

std::vector<float>* const & cfa_8::beamSpot_z0Error() const{
  if(!c_beamSpot_z0Error_ && b_beamSpot_z0Error_){
    b_beamSpot_z0Error_->GetEntry(entry_);
    c_beamSpot_z0Error_ = true;
  }
  return beamSpot_z0Error_;
}

UInt_t const & cfa_8::bunchCrossing() const{
  if(!c_bunchCrossing_ && b_bunchCrossing_){
    b_bunchCrossing_->GetEntry(entry_);
    c_bunchCrossing_ = true;
  }
  return bunchCrossing_;
}

Int_t const & cfa_8::cschalofilter_decision() const{
  if(!c_cschalofilter_decision_ && b_cschalofilter_decision_){
    b_cschalofilter_decision_->GetEntry(entry_);
    c_cschalofilter_decision_ = true;
  }
  return cschalofilter_decision_;
}

Int_t const & cfa_8::ecalBEfilter_decision() const{
  if(!c_ecalBEfilter_decision_ && b_ecalBEfilter_decision_){
    b_ecalBEfilter_decision_->GetEntry(entry_);
    c_ecalBEfilter_decision_ = true;
  }
  return ecalBEfilter_decision_;
}

Int_t const & cfa_8::ecalTPfilter_decision() const{
  if(!c_ecalTPfilter_decision_ && b_ecalTPfilter_decision_){
    b_ecalTPfilter_decision_->GetEntry(entry_);
    c_ecalTPfilter_decision_ = true;
  }
  return ecalTPfilter_decision_;
}

Int_t const & cfa_8::ecallaserfilter_decision() const{
  if(!c_ecallaserfilter_decision_ && b_ecallaserfilter_decision_){
    b_ecallaserfilter_decision_->GetEntry(entry_);
    c_ecallaserfilter_decision_ = true;
  }
  return ecallaserfilter_decision_;
}

Int_t const & cfa_8::eebadscfilter_decision() const{
  if(!c_eebadscfilter_decision_ && b_eebadscfilter_decision_){
    b_eebadscfilter_decision_->GetEntry(entry_);
    c_eebadscfilter_decision_ = true;
  }
  return eebadscfilter_decision_;
}

Int_t const & cfa_8::eenoisefilter_decision() const{
  if(!c_eenoisefilter_decision_ && b_eenoisefilter_decision_){
    b_eenoisefilter_decision_->GetEntry(entry_);
    c_eenoisefilter_decision_ = true;
  }
  return eenoisefilter_decision_;
}

std::vector<float>* const & cfa_8::els_PATpassConversionVeto() const{
  if(!c_els_PATpassConversionVeto_ && b_els_PATpassConversionVeto_){
    b_els_PATpassConversionVeto_->GetEntry(entry_);
    c_els_PATpassConversionVeto_ = true;
  }
  return els_PATpassConversionVeto_;
}

std::vector<float>* const & cfa_8::els_PFchargedHadronIsoR03() const{
  if(!c_els_PFchargedHadronIsoR03_ && b_els_PFchargedHadronIsoR03_){
    b_els_PFchargedHadronIsoR03_->GetEntry(entry_);
    c_els_PFchargedHadronIsoR03_ = true;
  }
  return els_PFchargedHadronIsoR03_;
}

std::vector<float>* const & cfa_8::els_PFneutralHadronIsoR03() const{
  if(!c_els_PFneutralHadronIsoR03_ && b_els_PFneutralHadronIsoR03_){
    b_els_PFneutralHadronIsoR03_->GetEntry(entry_);
    c_els_PFneutralHadronIsoR03_ = true;
  }
  return els_PFneutralHadronIsoR03_;
}

std::vector<float>* const & cfa_8::els_PFphotonIsoR03() const{
  if(!c_els_PFphotonIsoR03_ && b_els_PFphotonIsoR03_){
    b_els_PFphotonIsoR03_->GetEntry(entry_);
    c_els_PFphotonIsoR03_ = true;
  }
  return els_PFphotonIsoR03_;
}

std::vector<float>* const & cfa_8::els_basicClustersSize() const{
  if(!c_els_basicClustersSize_ && b_els_basicClustersSize_){
    b_els_basicClustersSize_->GetEntry(entry_);
    c_els_basicClustersSize_ = true;
  }
  return els_basicClustersSize_;
}

std::vector<float>* const & cfa_8::els_cIso() const{
  if(!c_els_cIso_ && b_els_cIso_){
    b_els_cIso_->GetEntry(entry_);
    c_els_cIso_ = true;
  }
  return els_cIso_;
}

std::vector<float>* const & cfa_8::els_caloEnergy() const{
  if(!c_els_caloEnergy_ && b_els_caloEnergy_){
    b_els_caloEnergy_->GetEntry(entry_);
    c_els_caloEnergy_ = true;
  }
  return els_caloEnergy_;
}

std::vector<float>* const & cfa_8::els_charge() const{
  if(!c_els_charge_ && b_els_charge_){
    b_els_charge_->GetEntry(entry_);
    c_els_charge_ = true;
  }
  return els_charge_;
}

std::vector<float>* const & cfa_8::els_chi2() const{
  if(!c_els_chi2_ && b_els_chi2_){
    b_els_chi2_->GetEntry(entry_);
    c_els_chi2_ = true;
  }
  return els_chi2_;
}

std::vector<float>* const & cfa_8::els_conversion_dcot() const{
  if(!c_els_conversion_dcot_ && b_els_conversion_dcot_){
    b_els_conversion_dcot_->GetEntry(entry_);
    c_els_conversion_dcot_ = true;
  }
  return els_conversion_dcot_;
}

std::vector<float>* const & cfa_8::els_conversion_dist() const{
  if(!c_els_conversion_dist_ && b_els_conversion_dist_){
    b_els_conversion_dist_->GetEntry(entry_);
    c_els_conversion_dist_ = true;
  }
  return els_conversion_dist_;
}

std::vector<float>* const & cfa_8::els_core_ecalDrivenSeed() const{
  if(!c_els_core_ecalDrivenSeed_ && b_els_core_ecalDrivenSeed_){
    b_els_core_ecalDrivenSeed_->GetEntry(entry_);
    c_els_core_ecalDrivenSeed_ = true;
  }
  return els_core_ecalDrivenSeed_;
}

std::vector<float>* const & cfa_8::els_cpx() const{
  if(!c_els_cpx_ && b_els_cpx_){
    b_els_cpx_->GetEntry(entry_);
    c_els_cpx_ = true;
  }
  return els_cpx_;
}

std::vector<float>* const & cfa_8::els_cpy() const{
  if(!c_els_cpy_ && b_els_cpy_){
    b_els_cpy_->GetEntry(entry_);
    c_els_cpy_ = true;
  }
  return els_cpy_;
}

std::vector<float>* const & cfa_8::els_cpz() const{
  if(!c_els_cpz_ && b_els_cpz_){
    b_els_cpz_->GetEntry(entry_);
    c_els_cpz_ = true;
  }
  return els_cpz_;
}

std::vector<float>* const & cfa_8::els_ctf_tk_charge() const{
  if(!c_els_ctf_tk_charge_ && b_els_ctf_tk_charge_){
    b_els_ctf_tk_charge_->GetEntry(entry_);
    c_els_ctf_tk_charge_ = true;
  }
  return els_ctf_tk_charge_;
}

std::vector<float>* const & cfa_8::els_ctf_tk_eta() const{
  if(!c_els_ctf_tk_eta_ && b_els_ctf_tk_eta_){
    b_els_ctf_tk_eta_->GetEntry(entry_);
    c_els_ctf_tk_eta_ = true;
  }
  return els_ctf_tk_eta_;
}

std::vector<float>* const & cfa_8::els_ctf_tk_id() const{
  if(!c_els_ctf_tk_id_ && b_els_ctf_tk_id_){
    b_els_ctf_tk_id_->GetEntry(entry_);
    c_els_ctf_tk_id_ = true;
  }
  return els_ctf_tk_id_;
}

std::vector<float>* const & cfa_8::els_ctf_tk_phi() const{
  if(!c_els_ctf_tk_phi_ && b_els_ctf_tk_phi_){
    b_els_ctf_tk_phi_->GetEntry(entry_);
    c_els_ctf_tk_phi_ = true;
  }
  return els_ctf_tk_phi_;
}

std::vector<float>* const & cfa_8::els_cx() const{
  if(!c_els_cx_ && b_els_cx_){
    b_els_cx_->GetEntry(entry_);
    c_els_cx_ = true;
  }
  return els_cx_;
}

std::vector<float>* const & cfa_8::els_cy() const{
  if(!c_els_cy_ && b_els_cy_){
    b_els_cy_->GetEntry(entry_);
    c_els_cy_ = true;
  }
  return els_cy_;
}

std::vector<float>* const & cfa_8::els_cz() const{
  if(!c_els_cz_ && b_els_cz_){
    b_els_cz_->GetEntry(entry_);
    c_els_cz_ = true;
  }
  return els_cz_;
}

std::vector<float>* const & cfa_8::els_d0dum() const{
  if(!c_els_d0dum_ && b_els_d0dum_){
    b_els_d0dum_->GetEntry(entry_);
    c_els_d0dum_ = true;
  }
  return els_d0dum_;
}

std::vector<float>* const & cfa_8::els_d0dumError() const{
  if(!c_els_d0dumError_ && b_els_d0dumError_){
    b_els_d0dumError_->GetEntry(entry_);
    c_els_d0dumError_ = true;
  }
  return els_d0dumError_;
}

std::vector<float>* const & cfa_8::els_dEtaIn() const{
  if(!c_els_dEtaIn_ && b_els_dEtaIn_){
    b_els_dEtaIn_->GetEntry(entry_);
    c_els_dEtaIn_ = true;
  }
  return els_dEtaIn_;
}

std::vector<float>* const & cfa_8::els_dEtaOut() const{
  if(!c_els_dEtaOut_ && b_els_dEtaOut_){
    b_els_dEtaOut_->GetEntry(entry_);
    c_els_dEtaOut_ = true;
  }
  return els_dEtaOut_;
}

std::vector<float>* const & cfa_8::els_dPhiIn() const{
  if(!c_els_dPhiIn_ && b_els_dPhiIn_){
    b_els_dPhiIn_->GetEntry(entry_);
    c_els_dPhiIn_ = true;
  }
  return els_dPhiIn_;
}

std::vector<float>* const & cfa_8::els_dPhiOut() const{
  if(!c_els_dPhiOut_ && b_els_dPhiOut_){
    b_els_dPhiOut_->GetEntry(entry_);
    c_els_dPhiOut_ = true;
  }
  return els_dPhiOut_;
}

std::vector<float>* const & cfa_8::els_dr03EcalRecHitSumEt() const{
  if(!c_els_dr03EcalRecHitSumEt_ && b_els_dr03EcalRecHitSumEt_){
    b_els_dr03EcalRecHitSumEt_->GetEntry(entry_);
    c_els_dr03EcalRecHitSumEt_ = true;
  }
  return els_dr03EcalRecHitSumEt_;
}

std::vector<float>* const & cfa_8::els_dr03HcalDepth1TowerSumEt() const{
  if(!c_els_dr03HcalDepth1TowerSumEt_ && b_els_dr03HcalDepth1TowerSumEt_){
    b_els_dr03HcalDepth1TowerSumEt_->GetEntry(entry_);
    c_els_dr03HcalDepth1TowerSumEt_ = true;
  }
  return els_dr03HcalDepth1TowerSumEt_;
}

std::vector<float>* const & cfa_8::els_dr03HcalDepth2TowerSumEt() const{
  if(!c_els_dr03HcalDepth2TowerSumEt_ && b_els_dr03HcalDepth2TowerSumEt_){
    b_els_dr03HcalDepth2TowerSumEt_->GetEntry(entry_);
    c_els_dr03HcalDepth2TowerSumEt_ = true;
  }
  return els_dr03HcalDepth2TowerSumEt_;
}

std::vector<float>* const & cfa_8::els_dr03HcalTowerSumEt() const{
  if(!c_els_dr03HcalTowerSumEt_ && b_els_dr03HcalTowerSumEt_){
    b_els_dr03HcalTowerSumEt_->GetEntry(entry_);
    c_els_dr03HcalTowerSumEt_ = true;
  }
  return els_dr03HcalTowerSumEt_;
}

std::vector<float>* const & cfa_8::els_dr03TkSumPt() const{
  if(!c_els_dr03TkSumPt_ && b_els_dr03TkSumPt_){
    b_els_dr03TkSumPt_->GetEntry(entry_);
    c_els_dr03TkSumPt_ = true;
  }
  return els_dr03TkSumPt_;
}

std::vector<float>* const & cfa_8::els_dr04EcalRecHitSumEt() const{
  if(!c_els_dr04EcalRecHitSumEt_ && b_els_dr04EcalRecHitSumEt_){
    b_els_dr04EcalRecHitSumEt_->GetEntry(entry_);
    c_els_dr04EcalRecHitSumEt_ = true;
  }
  return els_dr04EcalRecHitSumEt_;
}

std::vector<float>* const & cfa_8::els_dr04HcalDepth1TowerSumEt() const{
  if(!c_els_dr04HcalDepth1TowerSumEt_ && b_els_dr04HcalDepth1TowerSumEt_){
    b_els_dr04HcalDepth1TowerSumEt_->GetEntry(entry_);
    c_els_dr04HcalDepth1TowerSumEt_ = true;
  }
  return els_dr04HcalDepth1TowerSumEt_;
}

std::vector<float>* const & cfa_8::els_dr04HcalDepth2TowerSumEt() const{
  if(!c_els_dr04HcalDepth2TowerSumEt_ && b_els_dr04HcalDepth2TowerSumEt_){
    b_els_dr04HcalDepth2TowerSumEt_->GetEntry(entry_);
    c_els_dr04HcalDepth2TowerSumEt_ = true;
  }
  return els_dr04HcalDepth2TowerSumEt_;
}

std::vector<float>* const & cfa_8::els_dr04HcalTowerSumEt() const{
  if(!c_els_dr04HcalTowerSumEt_ && b_els_dr04HcalTowerSumEt_){
    b_els_dr04HcalTowerSumEt_->GetEntry(entry_);
    c_els_dr04HcalTowerSumEt_ = true;
  }
  return els_dr04HcalTowerSumEt_;
}

std::vector<float>* const & cfa_8::els_dr04TkSumPt() const{
  if(!c_els_dr04TkSumPt_ && b_els_dr04TkSumPt_){
    b_els_dr04TkSumPt_->GetEntry(entry_);
    c_els_dr04TkSumPt_ = true;
  }
  return els_dr04TkSumPt_;
}

std::vector<float>* const & cfa_8::els_dz() const{
  if(!c_els_dz_ && b_els_dz_){
    b_els_dz_->GetEntry(entry_);
    c_els_dz_ = true;
  }
  return els_dz_;
}

std::vector<float>* const & cfa_8::els_dzError() const{
  if(!c_els_dzError_ && b_els_dzError_){
    b_els_dzError_->GetEntry(entry_);
    c_els_dzError_ = true;
  }
  return els_dzError_;
}

std::vector<float>* const & cfa_8::els_eOverPIn() const{
  if(!c_els_eOverPIn_ && b_els_eOverPIn_){
    b_els_eOverPIn_->GetEntry(entry_);
    c_els_eOverPIn_ = true;
  }
  return els_eOverPIn_;
}

std::vector<float>* const & cfa_8::els_eSeedOverPOut() const{
  if(!c_els_eSeedOverPOut_ && b_els_eSeedOverPOut_){
    b_els_eSeedOverPOut_->GetEntry(entry_);
    c_els_eSeedOverPOut_ = true;
  }
  return els_eSeedOverPOut_;
}

std::vector<float>* const & cfa_8::els_ecalIso() const{
  if(!c_els_ecalIso_ && b_els_ecalIso_){
    b_els_ecalIso_->GetEntry(entry_);
    c_els_ecalIso_ = true;
  }
  return els_ecalIso_;
}

std::vector<float>* const & cfa_8::els_energy() const{
  if(!c_els_energy_ && b_els_energy_){
    b_els_energy_->GetEntry(entry_);
    c_els_energy_ = true;
  }
  return els_energy_;
}

std::vector<float>* const & cfa_8::els_et() const{
  if(!c_els_et_ && b_els_et_){
    b_els_et_->GetEntry(entry_);
    c_els_et_ = true;
  }
  return els_et_;
}

std::vector<float>* const & cfa_8::els_eta() const{
  if(!c_els_eta_ && b_els_eta_){
    b_els_eta_->GetEntry(entry_);
    c_els_eta_ = true;
  }
  return els_eta_;
}

std::vector<float>* const & cfa_8::els_etaError() const{
  if(!c_els_etaError_ && b_els_etaError_){
    b_els_etaError_->GetEntry(entry_);
    c_els_etaError_ = true;
  }
  return els_etaError_;
}

std::vector<float>* const & cfa_8::els_fbrem() const{
  if(!c_els_fbrem_ && b_els_fbrem_){
    b_els_fbrem_->GetEntry(entry_);
    c_els_fbrem_ = true;
  }
  return els_fbrem_;
}

std::vector<float>* const & cfa_8::els_gen_et() const{
  if(!c_els_gen_et_ && b_els_gen_et_){
    b_els_gen_et_->GetEntry(entry_);
    c_els_gen_et_ = true;
  }
  return els_gen_et_;
}

std::vector<float>* const & cfa_8::els_gen_eta() const{
  if(!c_els_gen_eta_ && b_els_gen_eta_){
    b_els_gen_eta_->GetEntry(entry_);
    c_els_gen_eta_ = true;
  }
  return els_gen_eta_;
}

std::vector<float>* const & cfa_8::els_gen_id() const{
  if(!c_els_gen_id_ && b_els_gen_id_){
    b_els_gen_id_->GetEntry(entry_);
    c_els_gen_id_ = true;
  }
  return els_gen_id_;
}

std::vector<float>* const & cfa_8::els_gen_mother_et() const{
  if(!c_els_gen_mother_et_ && b_els_gen_mother_et_){
    b_els_gen_mother_et_->GetEntry(entry_);
    c_els_gen_mother_et_ = true;
  }
  return els_gen_mother_et_;
}

std::vector<float>* const & cfa_8::els_gen_mother_eta() const{
  if(!c_els_gen_mother_eta_ && b_els_gen_mother_eta_){
    b_els_gen_mother_eta_->GetEntry(entry_);
    c_els_gen_mother_eta_ = true;
  }
  return els_gen_mother_eta_;
}

std::vector<float>* const & cfa_8::els_gen_mother_id() const{
  if(!c_els_gen_mother_id_ && b_els_gen_mother_id_){
    b_els_gen_mother_id_->GetEntry(entry_);
    c_els_gen_mother_id_ = true;
  }
  return els_gen_mother_id_;
}

std::vector<float>* const & cfa_8::els_gen_mother_phi() const{
  if(!c_els_gen_mother_phi_ && b_els_gen_mother_phi_){
    b_els_gen_mother_phi_->GetEntry(entry_);
    c_els_gen_mother_phi_ = true;
  }
  return els_gen_mother_phi_;
}

std::vector<float>* const & cfa_8::els_gen_mother_pt() const{
  if(!c_els_gen_mother_pt_ && b_els_gen_mother_pt_){
    b_els_gen_mother_pt_->GetEntry(entry_);
    c_els_gen_mother_pt_ = true;
  }
  return els_gen_mother_pt_;
}

std::vector<float>* const & cfa_8::els_gen_mother_px() const{
  if(!c_els_gen_mother_px_ && b_els_gen_mother_px_){
    b_els_gen_mother_px_->GetEntry(entry_);
    c_els_gen_mother_px_ = true;
  }
  return els_gen_mother_px_;
}

std::vector<float>* const & cfa_8::els_gen_mother_py() const{
  if(!c_els_gen_mother_py_ && b_els_gen_mother_py_){
    b_els_gen_mother_py_->GetEntry(entry_);
    c_els_gen_mother_py_ = true;
  }
  return els_gen_mother_py_;
}

std::vector<float>* const & cfa_8::els_gen_mother_pz() const{
  if(!c_els_gen_mother_pz_ && b_els_gen_mother_pz_){
    b_els_gen_mother_pz_->GetEntry(entry_);
    c_els_gen_mother_pz_ = true;
  }
  return els_gen_mother_pz_;
}

std::vector<float>* const & cfa_8::els_gen_mother_theta() const{
  if(!c_els_gen_mother_theta_ && b_els_gen_mother_theta_){
    b_els_gen_mother_theta_->GetEntry(entry_);
    c_els_gen_mother_theta_ = true;
  }
  return els_gen_mother_theta_;
}

std::vector<float>* const & cfa_8::els_gen_phi() const{
  if(!c_els_gen_phi_ && b_els_gen_phi_){
    b_els_gen_phi_->GetEntry(entry_);
    c_els_gen_phi_ = true;
  }
  return els_gen_phi_;
}

std::vector<float>* const & cfa_8::els_gen_pt() const{
  if(!c_els_gen_pt_ && b_els_gen_pt_){
    b_els_gen_pt_->GetEntry(entry_);
    c_els_gen_pt_ = true;
  }
  return els_gen_pt_;
}

std::vector<float>* const & cfa_8::els_gen_px() const{
  if(!c_els_gen_px_ && b_els_gen_px_){
    b_els_gen_px_->GetEntry(entry_);
    c_els_gen_px_ = true;
  }
  return els_gen_px_;
}

std::vector<float>* const & cfa_8::els_gen_py() const{
  if(!c_els_gen_py_ && b_els_gen_py_){
    b_els_gen_py_->GetEntry(entry_);
    c_els_gen_py_ = true;
  }
  return els_gen_py_;
}

std::vector<float>* const & cfa_8::els_gen_pz() const{
  if(!c_els_gen_pz_ && b_els_gen_pz_){
    b_els_gen_pz_->GetEntry(entry_);
    c_els_gen_pz_ = true;
  }
  return els_gen_pz_;
}

std::vector<float>* const & cfa_8::els_gen_theta() const{
  if(!c_els_gen_theta_ && b_els_gen_theta_){
    b_els_gen_theta_->GetEntry(entry_);
    c_els_gen_theta_ = true;
  }
  return els_gen_theta_;
}

std::vector<float>* const & cfa_8::els_hadOverEm() const{
  if(!c_els_hadOverEm_ && b_els_hadOverEm_){
    b_els_hadOverEm_->GetEntry(entry_);
    c_els_hadOverEm_ = true;
  }
  return els_hadOverEm_;
}

std::vector<bool>* const & cfa_8::els_hasMatchedConversion() const{
  if(!c_els_hasMatchedConversion_ && b_els_hasMatchedConversion_){
    b_els_hasMatchedConversion_->GetEntry(entry_);
    c_els_hasMatchedConversion_ = true;
  }
  return els_hasMatchedConversion_;
}

std::vector<float>* const & cfa_8::els_hcalIso() const{
  if(!c_els_hcalIso_ && b_els_hcalIso_){
    b_els_hcalIso_->GetEntry(entry_);
    c_els_hcalIso_ = true;
  }
  return els_hcalIso_;
}

std::vector<float>* const & cfa_8::els_hcalOverEcalBc() const{
  if(!c_els_hcalOverEcalBc_ && b_els_hcalOverEcalBc_){
    b_els_hcalOverEcalBc_->GetEntry(entry_);
    c_els_hcalOverEcalBc_ = true;
  }
  return els_hcalOverEcalBc_;
}

std::vector<float>* const & cfa_8::els_isEB() const{
  if(!c_els_isEB_ && b_els_isEB_){
    b_els_isEB_->GetEntry(entry_);
    c_els_isEB_ = true;
  }
  return els_isEB_;
}

std::vector<float>* const & cfa_8::els_isEE() const{
  if(!c_els_isEE_ && b_els_isEE_){
    b_els_isEE_->GetEntry(entry_);
    c_els_isEE_ = true;
  }
  return els_isEE_;
}

std::vector<float>* const & cfa_8::els_looseId() const{
  if(!c_els_looseId_ && b_els_looseId_){
    b_els_looseId_->GetEntry(entry_);
    c_els_looseId_ = true;
  }
  return els_looseId_;
}

std::vector<float>* const & cfa_8::els_n_inner_layer() const{
  if(!c_els_n_inner_layer_ && b_els_n_inner_layer_){
    b_els_n_inner_layer_->GetEntry(entry_);
    c_els_n_inner_layer_ = true;
  }
  return els_n_inner_layer_;
}

std::vector<float>* const & cfa_8::els_n_outer_layer() const{
  if(!c_els_n_outer_layer_ && b_els_n_outer_layer_){
    b_els_n_outer_layer_->GetEntry(entry_);
    c_els_n_outer_layer_ = true;
  }
  return els_n_outer_layer_;
}

std::vector<float>* const & cfa_8::els_ndof() const{
  if(!c_els_ndof_ && b_els_ndof_){
    b_els_ndof_->GetEntry(entry_);
    c_els_ndof_ = true;
  }
  return els_ndof_;
}

std::vector<float>* const & cfa_8::els_numlosthits() const{
  if(!c_els_numlosthits_ && b_els_numlosthits_){
    b_els_numlosthits_->GetEntry(entry_);
    c_els_numlosthits_ = true;
  }
  return els_numlosthits_;
}

std::vector<float>* const & cfa_8::els_numvalhits() const{
  if(!c_els_numvalhits_ && b_els_numvalhits_){
    b_els_numvalhits_->GetEntry(entry_);
    c_els_numvalhits_ = true;
  }
  return els_numvalhits_;
}

std::vector<float>* const & cfa_8::els_phi() const{
  if(!c_els_phi_ && b_els_phi_){
    b_els_phi_->GetEntry(entry_);
    c_els_phi_ = true;
  }
  return els_phi_;
}

std::vector<float>* const & cfa_8::els_phiError() const{
  if(!c_els_phiError_ && b_els_phiError_){
    b_els_phiError_->GetEntry(entry_);
    c_els_phiError_ = true;
  }
  return els_phiError_;
}

std::vector<float>* const & cfa_8::els_pt() const{
  if(!c_els_pt_ && b_els_pt_){
    b_els_pt_->GetEntry(entry_);
    c_els_pt_ = true;
  }
  return els_pt_;
}

std::vector<float>* const & cfa_8::els_ptError() const{
  if(!c_els_ptError_ && b_els_ptError_){
    b_els_ptError_->GetEntry(entry_);
    c_els_ptError_ = true;
  }
  return els_ptError_;
}

std::vector<float>* const & cfa_8::els_px() const{
  if(!c_els_px_ && b_els_px_){
    b_els_px_->GetEntry(entry_);
    c_els_px_ = true;
  }
  return els_px_;
}

std::vector<float>* const & cfa_8::els_py() const{
  if(!c_els_py_ && b_els_py_){
    b_els_py_->GetEntry(entry_);
    c_els_py_ = true;
  }
  return els_py_;
}

std::vector<float>* const & cfa_8::els_pz() const{
  if(!c_els_pz_ && b_els_pz_){
    b_els_pz_->GetEntry(entry_);
    c_els_pz_ = true;
  }
  return els_pz_;
}

std::vector<float>* const & cfa_8::els_robustHighEnergyId() const{
  if(!c_els_robustHighEnergyId_ && b_els_robustHighEnergyId_){
    b_els_robustHighEnergyId_->GetEntry(entry_);
    c_els_robustHighEnergyId_ = true;
  }
  return els_robustHighEnergyId_;
}

std::vector<float>* const & cfa_8::els_robustLooseId() const{
  if(!c_els_robustLooseId_ && b_els_robustLooseId_){
    b_els_robustLooseId_->GetEntry(entry_);
    c_els_robustLooseId_ = true;
  }
  return els_robustLooseId_;
}

std::vector<float>* const & cfa_8::els_robustTightId() const{
  if(!c_els_robustTightId_ && b_els_robustTightId_){
    b_els_robustTightId_->GetEntry(entry_);
    c_els_robustTightId_ = true;
  }
  return els_robustTightId_;
}

std::vector<float>* const & cfa_8::els_scE1x5() const{
  if(!c_els_scE1x5_ && b_els_scE1x5_){
    b_els_scE1x5_->GetEntry(entry_);
    c_els_scE1x5_ = true;
  }
  return els_scE1x5_;
}

std::vector<float>* const & cfa_8::els_scE2x5Max() const{
  if(!c_els_scE2x5Max_ && b_els_scE2x5Max_){
    b_els_scE2x5Max_->GetEntry(entry_);
    c_els_scE2x5Max_ = true;
  }
  return els_scE2x5Max_;
}

std::vector<float>* const & cfa_8::els_scE5x5() const{
  if(!c_els_scE5x5_ && b_els_scE5x5_){
    b_els_scE5x5_->GetEntry(entry_);
    c_els_scE5x5_ = true;
  }
  return els_scE5x5_;
}

std::vector<float>* const & cfa_8::els_scEnergy() const{
  if(!c_els_scEnergy_ && b_els_scEnergy_){
    b_els_scEnergy_->GetEntry(entry_);
    c_els_scEnergy_ = true;
  }
  return els_scEnergy_;
}

std::vector<float>* const & cfa_8::els_scEta() const{
  if(!c_els_scEta_ && b_els_scEta_){
    b_els_scEta_->GetEntry(entry_);
    c_els_scEta_ = true;
  }
  return els_scEta_;
}

std::vector<float>* const & cfa_8::els_scEtaWidth() const{
  if(!c_els_scEtaWidth_ && b_els_scEtaWidth_){
    b_els_scEtaWidth_->GetEntry(entry_);
    c_els_scEtaWidth_ = true;
  }
  return els_scEtaWidth_;
}

std::vector<float>* const & cfa_8::els_scPhi() const{
  if(!c_els_scPhi_ && b_els_scPhi_){
    b_els_scPhi_->GetEntry(entry_);
    c_els_scPhi_ = true;
  }
  return els_scPhi_;
}

std::vector<float>* const & cfa_8::els_scPhiWidth() const{
  if(!c_els_scPhiWidth_ && b_els_scPhiWidth_){
    b_els_scPhiWidth_->GetEntry(entry_);
    c_els_scPhiWidth_ = true;
  }
  return els_scPhiWidth_;
}

std::vector<float>* const & cfa_8::els_scRawEnergy() const{
  if(!c_els_scRawEnergy_ && b_els_scRawEnergy_){
    b_els_scRawEnergy_->GetEntry(entry_);
    c_els_scRawEnergy_ = true;
  }
  return els_scRawEnergy_;
}

std::vector<float>* const & cfa_8::els_scSeedEnergy() const{
  if(!c_els_scSeedEnergy_ && b_els_scSeedEnergy_){
    b_els_scSeedEnergy_->GetEntry(entry_);
    c_els_scSeedEnergy_ = true;
  }
  return els_scSeedEnergy_;
}

std::vector<float>* const & cfa_8::els_shFracInnerHits() const{
  if(!c_els_shFracInnerHits_ && b_els_shFracInnerHits_){
    b_els_shFracInnerHits_->GetEntry(entry_);
    c_els_shFracInnerHits_ = true;
  }
  return els_shFracInnerHits_;
}

std::vector<float>* const & cfa_8::els_sigmaEtaEta() const{
  if(!c_els_sigmaEtaEta_ && b_els_sigmaEtaEta_){
    b_els_sigmaEtaEta_->GetEntry(entry_);
    c_els_sigmaEtaEta_ = true;
  }
  return els_sigmaEtaEta_;
}

std::vector<float>* const & cfa_8::els_sigmaIEtaIEta() const{
  if(!c_els_sigmaIEtaIEta_ && b_els_sigmaIEtaIEta_){
    b_els_sigmaIEtaIEta_->GetEntry(entry_);
    c_els_sigmaIEtaIEta_ = true;
  }
  return els_sigmaIEtaIEta_;
}

std::vector<float>* const & cfa_8::els_simpleEleId60cIso() const{
  if(!c_els_simpleEleId60cIso_ && b_els_simpleEleId60cIso_){
    b_els_simpleEleId60cIso_->GetEntry(entry_);
    c_els_simpleEleId60cIso_ = true;
  }
  return els_simpleEleId60cIso_;
}

std::vector<float>* const & cfa_8::els_simpleEleId60relIso() const{
  if(!c_els_simpleEleId60relIso_ && b_els_simpleEleId60relIso_){
    b_els_simpleEleId60relIso_->GetEntry(entry_);
    c_els_simpleEleId60relIso_ = true;
  }
  return els_simpleEleId60relIso_;
}

std::vector<float>* const & cfa_8::els_simpleEleId70cIso() const{
  if(!c_els_simpleEleId70cIso_ && b_els_simpleEleId70cIso_){
    b_els_simpleEleId70cIso_->GetEntry(entry_);
    c_els_simpleEleId70cIso_ = true;
  }
  return els_simpleEleId70cIso_;
}

std::vector<float>* const & cfa_8::els_simpleEleId70relIso() const{
  if(!c_els_simpleEleId70relIso_ && b_els_simpleEleId70relIso_){
    b_els_simpleEleId70relIso_->GetEntry(entry_);
    c_els_simpleEleId70relIso_ = true;
  }
  return els_simpleEleId70relIso_;
}

std::vector<float>* const & cfa_8::els_simpleEleId80cIso() const{
  if(!c_els_simpleEleId80cIso_ && b_els_simpleEleId80cIso_){
    b_els_simpleEleId80cIso_->GetEntry(entry_);
    c_els_simpleEleId80cIso_ = true;
  }
  return els_simpleEleId80cIso_;
}

std::vector<float>* const & cfa_8::els_simpleEleId80relIso() const{
  if(!c_els_simpleEleId80relIso_ && b_els_simpleEleId80relIso_){
    b_els_simpleEleId80relIso_->GetEntry(entry_);
    c_els_simpleEleId80relIso_ = true;
  }
  return els_simpleEleId80relIso_;
}

std::vector<float>* const & cfa_8::els_simpleEleId85cIso() const{
  if(!c_els_simpleEleId85cIso_ && b_els_simpleEleId85cIso_){
    b_els_simpleEleId85cIso_->GetEntry(entry_);
    c_els_simpleEleId85cIso_ = true;
  }
  return els_simpleEleId85cIso_;
}

std::vector<float>* const & cfa_8::els_simpleEleId85relIso() const{
  if(!c_els_simpleEleId85relIso_ && b_els_simpleEleId85relIso_){
    b_els_simpleEleId85relIso_->GetEntry(entry_);
    c_els_simpleEleId85relIso_ = true;
  }
  return els_simpleEleId85relIso_;
}

std::vector<float>* const & cfa_8::els_simpleEleId90cIso() const{
  if(!c_els_simpleEleId90cIso_ && b_els_simpleEleId90cIso_){
    b_els_simpleEleId90cIso_->GetEntry(entry_);
    c_els_simpleEleId90cIso_ = true;
  }
  return els_simpleEleId90cIso_;
}

std::vector<float>* const & cfa_8::els_simpleEleId90relIso() const{
  if(!c_els_simpleEleId90relIso_ && b_els_simpleEleId90relIso_){
    b_els_simpleEleId90relIso_->GetEntry(entry_);
    c_els_simpleEleId90relIso_ = true;
  }
  return els_simpleEleId90relIso_;
}

std::vector<float>* const & cfa_8::els_simpleEleId95cIso() const{
  if(!c_els_simpleEleId95cIso_ && b_els_simpleEleId95cIso_){
    b_els_simpleEleId95cIso_->GetEntry(entry_);
    c_els_simpleEleId95cIso_ = true;
  }
  return els_simpleEleId95cIso_;
}

std::vector<float>* const & cfa_8::els_simpleEleId95relIso() const{
  if(!c_els_simpleEleId95relIso_ && b_els_simpleEleId95relIso_){
    b_els_simpleEleId95relIso_->GetEntry(entry_);
    c_els_simpleEleId95relIso_ = true;
  }
  return els_simpleEleId95relIso_;
}

std::vector<float>* const & cfa_8::els_status() const{
  if(!c_els_status_ && b_els_status_){
    b_els_status_->GetEntry(entry_);
    c_els_status_ = true;
  }
  return els_status_;
}

std::vector<float>* const & cfa_8::els_tIso() const{
  if(!c_els_tIso_ && b_els_tIso_){
    b_els_tIso_->GetEntry(entry_);
    c_els_tIso_ = true;
  }
  return els_tIso_;
}

std::vector<float>* const & cfa_8::els_theta() const{
  if(!c_els_theta_ && b_els_theta_){
    b_els_theta_->GetEntry(entry_);
    c_els_theta_ = true;
  }
  return els_theta_;
}

std::vector<float>* const & cfa_8::els_tightId() const{
  if(!c_els_tightId_ && b_els_tightId_){
    b_els_tightId_->GetEntry(entry_);
    c_els_tightId_ = true;
  }
  return els_tightId_;
}

std::vector<float>* const & cfa_8::els_tk_charge() const{
  if(!c_els_tk_charge_ && b_els_tk_charge_){
    b_els_tk_charge_->GetEntry(entry_);
    c_els_tk_charge_ = true;
  }
  return els_tk_charge_;
}

std::vector<float>* const & cfa_8::els_tk_eta() const{
  if(!c_els_tk_eta_ && b_els_tk_eta_){
    b_els_tk_eta_->GetEntry(entry_);
    c_els_tk_eta_ = true;
  }
  return els_tk_eta_;
}

std::vector<float>* const & cfa_8::els_tk_phi() const{
  if(!c_els_tk_phi_ && b_els_tk_phi_){
    b_els_tk_phi_->GetEntry(entry_);
    c_els_tk_phi_ = true;
  }
  return els_tk_phi_;
}

std::vector<float>* const & cfa_8::els_tk_pt() const{
  if(!c_els_tk_pt_ && b_els_tk_pt_){
    b_els_tk_pt_->GetEntry(entry_);
    c_els_tk_pt_ = true;
  }
  return els_tk_pt_;
}

std::vector<float>* const & cfa_8::els_tk_pz() const{
  if(!c_els_tk_pz_ && b_els_tk_pz_){
    b_els_tk_pz_->GetEntry(entry_);
    c_els_tk_pz_ = true;
  }
  return els_tk_pz_;
}

std::vector<float>* const & cfa_8::els_vpx() const{
  if(!c_els_vpx_ && b_els_vpx_){
    b_els_vpx_->GetEntry(entry_);
    c_els_vpx_ = true;
  }
  return els_vpx_;
}

std::vector<float>* const & cfa_8::els_vpy() const{
  if(!c_els_vpy_ && b_els_vpy_){
    b_els_vpy_->GetEntry(entry_);
    c_els_vpy_ = true;
  }
  return els_vpy_;
}

std::vector<float>* const & cfa_8::els_vpz() const{
  if(!c_els_vpz_ && b_els_vpz_){
    b_els_vpz_->GetEntry(entry_);
    c_els_vpz_ = true;
  }
  return els_vpz_;
}

std::vector<float>* const & cfa_8::els_vx() const{
  if(!c_els_vx_ && b_els_vx_){
    b_els_vx_->GetEntry(entry_);
    c_els_vx_ = true;
  }
  return els_vx_;
}

std::vector<float>* const & cfa_8::els_vy() const{
  if(!c_els_vy_ && b_els_vy_){
    b_els_vy_->GetEntry(entry_);
    c_els_vy_ = true;
  }
  return els_vy_;
}

std::vector<float>* const & cfa_8::els_vz() const{
  if(!c_els_vz_ && b_els_vz_){
    b_els_vz_->GetEntry(entry_);
    c_els_vz_ = true;
  }
  return els_vz_;
}

UInt_t const & cfa_8::event() const{
  if(!c_event_ && b_event_){
    b_event_->GetEntry(entry_);
    c_event_ = true;
  }
  return event_;
}

UInt_t const & cfa_8::experimentType() const{
  if(!c_experimentType_ && b_experimentType_){
    b_experimentType_->GetEntry(entry_);
    c_experimentType_ = true;
  }
  return experimentType_;
}

Float_t const & cfa_8::genHT() const{
  if(!c_genHT_ && b_genHT_){
    b_genHT_->GetEntry(entry_);
    c_genHT_ = true;
  }
  return genHT_;
}

Int_t const & cfa_8::greedymuonfilter_decision() const{
  if(!c_greedymuonfilter_decision_ && b_greedymuonfilter_decision_){
    b_greedymuonfilter_decision_->GetEntry(entry_);
    c_greedymuonfilter_decision_ = true;
  }
  return greedymuonfilter_decision_;
}

Int_t const & cfa_8::hbhefilter_decision() const{
  if(!c_hbhefilter_decision_ && b_hbhefilter_decision_){
    b_hbhefilter_decision_->GetEntry(entry_);
    c_hbhefilter_decision_ = true;
  }
  return hbhefilter_decision_;
}

Int_t const & cfa_8::hcallaserfilter_decision() const{
  if(!c_hcallaserfilter_decision_ && b_hcallaserfilter_decision_){
    b_hcallaserfilter_decision_->GetEntry(entry_);
    c_hcallaserfilter_decision_ = true;
  }
  return hcallaserfilter_decision_;
}

Int_t const & cfa_8::inconsistentPFmuonfilter_decision() const{
  if(!c_inconsistentPFmuonfilter_decision_ && b_inconsistentPFmuonfilter_decision_){
    b_inconsistentPFmuonfilter_decision_->GetEntry(entry_);
    c_inconsistentPFmuonfilter_decision_ = true;
  }
  return inconsistentPFmuonfilter_decision_;
}

std::vector<int>* const & cfa_8::isotk_charge() const{
  if(!c_isotk_charge_ && b_isotk_charge_){
    b_isotk_charge_->GetEntry(entry_);
    c_isotk_charge_ = true;
  }
  return isotk_charge_;
}

std::vector<float>* const & cfa_8::isotk_dzpv() const{
  if(!c_isotk_dzpv_ && b_isotk_dzpv_){
    b_isotk_dzpv_->GetEntry(entry_);
    c_isotk_dzpv_ = true;
  }
  return isotk_dzpv_;
}

std::vector<float>* const & cfa_8::isotk_eta() const{
  if(!c_isotk_eta_ && b_isotk_eta_){
    b_isotk_eta_->GetEntry(entry_);
    c_isotk_eta_ = true;
  }
  return isotk_eta_;
}

std::vector<float>* const & cfa_8::isotk_iso() const{
  if(!c_isotk_iso_ && b_isotk_iso_){
    b_isotk_iso_->GetEntry(entry_);
    c_isotk_iso_ = true;
  }
  return isotk_iso_;
}

std::vector<float>* const & cfa_8::isotk_phi() const{
  if(!c_isotk_phi_ && b_isotk_phi_){
    b_isotk_phi_->GetEntry(entry_);
    c_isotk_phi_ = true;
  }
  return isotk_phi_;
}

std::vector<float>* const & cfa_8::isotk_pt() const{
  if(!c_isotk_pt_ && b_isotk_pt_){
    b_isotk_pt_->GetEntry(entry_);
    c_isotk_pt_ = true;
  }
  return isotk_pt_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_area() const{
  if(!c_jets_AK5PF_area_ && b_jets_AK5PF_area_){
    b_jets_AK5PF_area_->GetEntry(entry_);
    c_jets_AK5PF_area_ = true;
  }
  return jets_AK5PF_area_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_btag_TC_highEff() const{
  if(!c_jets_AK5PF_btag_TC_highEff_ && b_jets_AK5PF_btag_TC_highEff_){
    b_jets_AK5PF_btag_TC_highEff_->GetEntry(entry_);
    c_jets_AK5PF_btag_TC_highEff_ = true;
  }
  return jets_AK5PF_btag_TC_highEff_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_btag_TC_highPur() const{
  if(!c_jets_AK5PF_btag_TC_highPur_ && b_jets_AK5PF_btag_TC_highPur_){
    b_jets_AK5PF_btag_TC_highPur_->GetEntry(entry_);
    c_jets_AK5PF_btag_TC_highPur_ = true;
  }
  return jets_AK5PF_btag_TC_highPur_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_btag_jetBProb() const{
  if(!c_jets_AK5PF_btag_jetBProb_ && b_jets_AK5PF_btag_jetBProb_){
    b_jets_AK5PF_btag_jetBProb_->GetEntry(entry_);
    c_jets_AK5PF_btag_jetBProb_ = true;
  }
  return jets_AK5PF_btag_jetBProb_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_btag_jetProb() const{
  if(!c_jets_AK5PF_btag_jetProb_ && b_jets_AK5PF_btag_jetProb_){
    b_jets_AK5PF_btag_jetProb_->GetEntry(entry_);
    c_jets_AK5PF_btag_jetProb_ = true;
  }
  return jets_AK5PF_btag_jetProb_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_btag_secVertexCombined() const{
  if(!c_jets_AK5PF_btag_secVertexCombined_ && b_jets_AK5PF_btag_secVertexCombined_){
    b_jets_AK5PF_btag_secVertexCombined_->GetEntry(entry_);
    c_jets_AK5PF_btag_secVertexCombined_ = true;
  }
  return jets_AK5PF_btag_secVertexCombined_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_btag_secVertexHighEff() const{
  if(!c_jets_AK5PF_btag_secVertexHighEff_ && b_jets_AK5PF_btag_secVertexHighEff_){
    b_jets_AK5PF_btag_secVertexHighEff_->GetEntry(entry_);
    c_jets_AK5PF_btag_secVertexHighEff_ = true;
  }
  return jets_AK5PF_btag_secVertexHighEff_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_btag_secVertexHighPur() const{
  if(!c_jets_AK5PF_btag_secVertexHighPur_ && b_jets_AK5PF_btag_secVertexHighPur_){
    b_jets_AK5PF_btag_secVertexHighPur_->GetEntry(entry_);
    c_jets_AK5PF_btag_secVertexHighPur_ = true;
  }
  return jets_AK5PF_btag_secVertexHighPur_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_btag_softEle() const{
  if(!c_jets_AK5PF_btag_softEle_ && b_jets_AK5PF_btag_softEle_){
    b_jets_AK5PF_btag_softEle_->GetEntry(entry_);
    c_jets_AK5PF_btag_softEle_ = true;
  }
  return jets_AK5PF_btag_softEle_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_btag_softMuon() const{
  if(!c_jets_AK5PF_btag_softMuon_ && b_jets_AK5PF_btag_softMuon_){
    b_jets_AK5PF_btag_softMuon_->GetEntry(entry_);
    c_jets_AK5PF_btag_softMuon_ = true;
  }
  return jets_AK5PF_btag_softMuon_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_chgEmE() const{
  if(!c_jets_AK5PF_chgEmE_ && b_jets_AK5PF_chgEmE_){
    b_jets_AK5PF_chgEmE_->GetEntry(entry_);
    c_jets_AK5PF_chgEmE_ = true;
  }
  return jets_AK5PF_chgEmE_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_chgHadE() const{
  if(!c_jets_AK5PF_chgHadE_ && b_jets_AK5PF_chgHadE_){
    b_jets_AK5PF_chgHadE_->GetEntry(entry_);
    c_jets_AK5PF_chgHadE_ = true;
  }
  return jets_AK5PF_chgHadE_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_chgMuE() const{
  if(!c_jets_AK5PF_chgMuE_ && b_jets_AK5PF_chgMuE_){
    b_jets_AK5PF_chgMuE_->GetEntry(entry_);
    c_jets_AK5PF_chgMuE_ = true;
  }
  return jets_AK5PF_chgMuE_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_chg_Mult() const{
  if(!c_jets_AK5PF_chg_Mult_ && b_jets_AK5PF_chg_Mult_){
    b_jets_AK5PF_chg_Mult_->GetEntry(entry_);
    c_jets_AK5PF_chg_Mult_ = true;
  }
  return jets_AK5PF_chg_Mult_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_corrFactorRaw() const{
  if(!c_jets_AK5PF_corrFactorRaw_ && b_jets_AK5PF_corrFactorRaw_){
    b_jets_AK5PF_corrFactorRaw_->GetEntry(entry_);
    c_jets_AK5PF_corrFactorRaw_ = true;
  }
  return jets_AK5PF_corrFactorRaw_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_ehf() const{
  if(!c_jets_AK5PF_ehf_ && b_jets_AK5PF_ehf_){
    b_jets_AK5PF_ehf_->GetEntry(entry_);
    c_jets_AK5PF_ehf_ = true;
  }
  return jets_AK5PF_ehf_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_emf() const{
  if(!c_jets_AK5PF_emf_ && b_jets_AK5PF_emf_){
    b_jets_AK5PF_emf_->GetEntry(entry_);
    c_jets_AK5PF_emf_ = true;
  }
  return jets_AK5PF_emf_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_energy() const{
  if(!c_jets_AK5PF_energy_ && b_jets_AK5PF_energy_){
    b_jets_AK5PF_energy_->GetEntry(entry_);
    c_jets_AK5PF_energy_ = true;
  }
  return jets_AK5PF_energy_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_et() const{
  if(!c_jets_AK5PF_et_ && b_jets_AK5PF_et_){
    b_jets_AK5PF_et_->GetEntry(entry_);
    c_jets_AK5PF_et_ = true;
  }
  return jets_AK5PF_et_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_eta() const{
  if(!c_jets_AK5PF_eta_ && b_jets_AK5PF_eta_){
    b_jets_AK5PF_eta_->GetEntry(entry_);
    c_jets_AK5PF_eta_ = true;
  }
  return jets_AK5PF_eta_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_etaetaMoment() const{
  if(!c_jets_AK5PF_etaetaMoment_ && b_jets_AK5PF_etaetaMoment_){
    b_jets_AK5PF_etaetaMoment_->GetEntry(entry_);
    c_jets_AK5PF_etaetaMoment_ = true;
  }
  return jets_AK5PF_etaetaMoment_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_etaphiMoment() const{
  if(!c_jets_AK5PF_etaphiMoment_ && b_jets_AK5PF_etaphiMoment_){
    b_jets_AK5PF_etaphiMoment_->GetEntry(entry_);
    c_jets_AK5PF_etaphiMoment_ = true;
  }
  return jets_AK5PF_etaphiMoment_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_fHPD() const{
  if(!c_jets_AK5PF_fHPD_ && b_jets_AK5PF_fHPD_){
    b_jets_AK5PF_fHPD_->GetEntry(entry_);
    c_jets_AK5PF_fHPD_ = true;
  }
  return jets_AK5PF_fHPD_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_fRBX() const{
  if(!c_jets_AK5PF_fRBX_ && b_jets_AK5PF_fRBX_){
    b_jets_AK5PF_fRBX_->GetEntry(entry_);
    c_jets_AK5PF_fRBX_ = true;
  }
  return jets_AK5PF_fRBX_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_fSubDetector1() const{
  if(!c_jets_AK5PF_fSubDetector1_ && b_jets_AK5PF_fSubDetector1_){
    b_jets_AK5PF_fSubDetector1_->GetEntry(entry_);
    c_jets_AK5PF_fSubDetector1_ = true;
  }
  return jets_AK5PF_fSubDetector1_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_fSubDetector2() const{
  if(!c_jets_AK5PF_fSubDetector2_ && b_jets_AK5PF_fSubDetector2_){
    b_jets_AK5PF_fSubDetector2_->GetEntry(entry_);
    c_jets_AK5PF_fSubDetector2_ = true;
  }
  return jets_AK5PF_fSubDetector2_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_fSubDetector3() const{
  if(!c_jets_AK5PF_fSubDetector3_ && b_jets_AK5PF_fSubDetector3_){
    b_jets_AK5PF_fSubDetector3_->GetEntry(entry_);
    c_jets_AK5PF_fSubDetector3_ = true;
  }
  return jets_AK5PF_fSubDetector3_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_fSubDetector4() const{
  if(!c_jets_AK5PF_fSubDetector4_ && b_jets_AK5PF_fSubDetector4_){
    b_jets_AK5PF_fSubDetector4_->GetEntry(entry_);
    c_jets_AK5PF_fSubDetector4_ = true;
  }
  return jets_AK5PF_fSubDetector4_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_gen_Energy() const{
  if(!c_jets_AK5PF_gen_Energy_ && b_jets_AK5PF_gen_Energy_){
    b_jets_AK5PF_gen_Energy_->GetEntry(entry_);
    c_jets_AK5PF_gen_Energy_ = true;
  }
  return jets_AK5PF_gen_Energy_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_gen_Id() const{
  if(!c_jets_AK5PF_gen_Id_ && b_jets_AK5PF_gen_Id_){
    b_jets_AK5PF_gen_Id_->GetEntry(entry_);
    c_jets_AK5PF_gen_Id_ = true;
  }
  return jets_AK5PF_gen_Id_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_gen_et() const{
  if(!c_jets_AK5PF_gen_et_ && b_jets_AK5PF_gen_et_){
    b_jets_AK5PF_gen_et_->GetEntry(entry_);
    c_jets_AK5PF_gen_et_ = true;
  }
  return jets_AK5PF_gen_et_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_gen_eta() const{
  if(!c_jets_AK5PF_gen_eta_ && b_jets_AK5PF_gen_eta_){
    b_jets_AK5PF_gen_eta_->GetEntry(entry_);
    c_jets_AK5PF_gen_eta_ = true;
  }
  return jets_AK5PF_gen_eta_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_gen_mass() const{
  if(!c_jets_AK5PF_gen_mass_ && b_jets_AK5PF_gen_mass_){
    b_jets_AK5PF_gen_mass_->GetEntry(entry_);
    c_jets_AK5PF_gen_mass_ = true;
  }
  return jets_AK5PF_gen_mass_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_gen_motherID() const{
  if(!c_jets_AK5PF_gen_motherID_ && b_jets_AK5PF_gen_motherID_){
    b_jets_AK5PF_gen_motherID_->GetEntry(entry_);
    c_jets_AK5PF_gen_motherID_ = true;
  }
  return jets_AK5PF_gen_motherID_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_gen_phi() const{
  if(!c_jets_AK5PF_gen_phi_ && b_jets_AK5PF_gen_phi_){
    b_jets_AK5PF_gen_phi_->GetEntry(entry_);
    c_jets_AK5PF_gen_phi_ = true;
  }
  return jets_AK5PF_gen_phi_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_gen_pt() const{
  if(!c_jets_AK5PF_gen_pt_ && b_jets_AK5PF_gen_pt_){
    b_jets_AK5PF_gen_pt_->GetEntry(entry_);
    c_jets_AK5PF_gen_pt_ = true;
  }
  return jets_AK5PF_gen_pt_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_gen_threeCharge() const{
  if(!c_jets_AK5PF_gen_threeCharge_ && b_jets_AK5PF_gen_threeCharge_){
    b_jets_AK5PF_gen_threeCharge_->GetEntry(entry_);
    c_jets_AK5PF_gen_threeCharge_ = true;
  }
  return jets_AK5PF_gen_threeCharge_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_hitsInN90() const{
  if(!c_jets_AK5PF_hitsInN90_ && b_jets_AK5PF_hitsInN90_){
    b_jets_AK5PF_hitsInN90_->GetEntry(entry_);
    c_jets_AK5PF_hitsInN90_ = true;
  }
  return jets_AK5PF_hitsInN90_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_jetCharge() const{
  if(!c_jets_AK5PF_jetCharge_ && b_jets_AK5PF_jetCharge_){
    b_jets_AK5PF_jetCharge_->GetEntry(entry_);
    c_jets_AK5PF_jetCharge_ = true;
  }
  return jets_AK5PF_jetCharge_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_mass() const{
  if(!c_jets_AK5PF_mass_ && b_jets_AK5PF_mass_){
    b_jets_AK5PF_mass_->GetEntry(entry_);
    c_jets_AK5PF_mass_ = true;
  }
  return jets_AK5PF_mass_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_mu_Mult() const{
  if(!c_jets_AK5PF_mu_Mult_ && b_jets_AK5PF_mu_Mult_){
    b_jets_AK5PF_mu_Mult_->GetEntry(entry_);
    c_jets_AK5PF_mu_Mult_ = true;
  }
  return jets_AK5PF_mu_Mult_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_n60() const{
  if(!c_jets_AK5PF_n60_ && b_jets_AK5PF_n60_){
    b_jets_AK5PF_n60_->GetEntry(entry_);
    c_jets_AK5PF_n60_ = true;
  }
  return jets_AK5PF_n60_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_n90() const{
  if(!c_jets_AK5PF_n90_ && b_jets_AK5PF_n90_){
    b_jets_AK5PF_n90_->GetEntry(entry_);
    c_jets_AK5PF_n90_ = true;
  }
  return jets_AK5PF_n90_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_n90Hits() const{
  if(!c_jets_AK5PF_n90Hits_ && b_jets_AK5PF_n90Hits_){
    b_jets_AK5PF_n90Hits_->GetEntry(entry_);
    c_jets_AK5PF_n90Hits_ = true;
  }
  return jets_AK5PF_n90Hits_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_nECALTowers() const{
  if(!c_jets_AK5PF_nECALTowers_ && b_jets_AK5PF_nECALTowers_){
    b_jets_AK5PF_nECALTowers_->GetEntry(entry_);
    c_jets_AK5PF_nECALTowers_ = true;
  }
  return jets_AK5PF_nECALTowers_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_nHCALTowers() const{
  if(!c_jets_AK5PF_nHCALTowers_ && b_jets_AK5PF_nHCALTowers_){
    b_jets_AK5PF_nHCALTowers_->GetEntry(entry_);
    c_jets_AK5PF_nHCALTowers_ = true;
  }
  return jets_AK5PF_nHCALTowers_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_neutralEmE() const{
  if(!c_jets_AK5PF_neutralEmE_ && b_jets_AK5PF_neutralEmE_){
    b_jets_AK5PF_neutralEmE_->GetEntry(entry_);
    c_jets_AK5PF_neutralEmE_ = true;
  }
  return jets_AK5PF_neutralEmE_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_neutralHadE() const{
  if(!c_jets_AK5PF_neutralHadE_ && b_jets_AK5PF_neutralHadE_){
    b_jets_AK5PF_neutralHadE_->GetEntry(entry_);
    c_jets_AK5PF_neutralHadE_ = true;
  }
  return jets_AK5PF_neutralHadE_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_neutral_Mult() const{
  if(!c_jets_AK5PF_neutral_Mult_ && b_jets_AK5PF_neutral_Mult_){
    b_jets_AK5PF_neutral_Mult_->GetEntry(entry_);
    c_jets_AK5PF_neutral_Mult_ = true;
  }
  return jets_AK5PF_neutral_Mult_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_partonFlavour() const{
  if(!c_jets_AK5PF_partonFlavour_ && b_jets_AK5PF_partonFlavour_){
    b_jets_AK5PF_partonFlavour_->GetEntry(entry_);
    c_jets_AK5PF_partonFlavour_ = true;
  }
  return jets_AK5PF_partonFlavour_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_parton_Energy() const{
  if(!c_jets_AK5PF_parton_Energy_ && b_jets_AK5PF_parton_Energy_){
    b_jets_AK5PF_parton_Energy_->GetEntry(entry_);
    c_jets_AK5PF_parton_Energy_ = true;
  }
  return jets_AK5PF_parton_Energy_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_parton_Id() const{
  if(!c_jets_AK5PF_parton_Id_ && b_jets_AK5PF_parton_Id_){
    b_jets_AK5PF_parton_Id_->GetEntry(entry_);
    c_jets_AK5PF_parton_Id_ = true;
  }
  return jets_AK5PF_parton_Id_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_parton_eta() const{
  if(!c_jets_AK5PF_parton_eta_ && b_jets_AK5PF_parton_eta_){
    b_jets_AK5PF_parton_eta_->GetEntry(entry_);
    c_jets_AK5PF_parton_eta_ = true;
  }
  return jets_AK5PF_parton_eta_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_parton_mass() const{
  if(!c_jets_AK5PF_parton_mass_ && b_jets_AK5PF_parton_mass_){
    b_jets_AK5PF_parton_mass_->GetEntry(entry_);
    c_jets_AK5PF_parton_mass_ = true;
  }
  return jets_AK5PF_parton_mass_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_parton_motherId() const{
  if(!c_jets_AK5PF_parton_motherId_ && b_jets_AK5PF_parton_motherId_){
    b_jets_AK5PF_parton_motherId_->GetEntry(entry_);
    c_jets_AK5PF_parton_motherId_ = true;
  }
  return jets_AK5PF_parton_motherId_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_parton_phi() const{
  if(!c_jets_AK5PF_parton_phi_ && b_jets_AK5PF_parton_phi_){
    b_jets_AK5PF_parton_phi_->GetEntry(entry_);
    c_jets_AK5PF_parton_phi_ = true;
  }
  return jets_AK5PF_parton_phi_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_parton_pt() const{
  if(!c_jets_AK5PF_parton_pt_ && b_jets_AK5PF_parton_pt_){
    b_jets_AK5PF_parton_pt_->GetEntry(entry_);
    c_jets_AK5PF_parton_pt_ = true;
  }
  return jets_AK5PF_parton_pt_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_phi() const{
  if(!c_jets_AK5PF_phi_ && b_jets_AK5PF_phi_){
    b_jets_AK5PF_phi_->GetEntry(entry_);
    c_jets_AK5PF_phi_ = true;
  }
  return jets_AK5PF_phi_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_phiphiMoment() const{
  if(!c_jets_AK5PF_phiphiMoment_ && b_jets_AK5PF_phiphiMoment_){
    b_jets_AK5PF_phiphiMoment_->GetEntry(entry_);
    c_jets_AK5PF_phiphiMoment_ = true;
  }
  return jets_AK5PF_phiphiMoment_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_photonEnergy() const{
  if(!c_jets_AK5PF_photonEnergy_ && b_jets_AK5PF_photonEnergy_){
    b_jets_AK5PF_photonEnergy_->GetEntry(entry_);
    c_jets_AK5PF_photonEnergy_ = true;
  }
  return jets_AK5PF_photonEnergy_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_pt() const{
  if(!c_jets_AK5PF_pt_ && b_jets_AK5PF_pt_){
    b_jets_AK5PF_pt_->GetEntry(entry_);
    c_jets_AK5PF_pt_ = true;
  }
  return jets_AK5PF_pt_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_px() const{
  if(!c_jets_AK5PF_px_ && b_jets_AK5PF_px_){
    b_jets_AK5PF_px_->GetEntry(entry_);
    c_jets_AK5PF_px_ = true;
  }
  return jets_AK5PF_px_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_py() const{
  if(!c_jets_AK5PF_py_ && b_jets_AK5PF_py_){
    b_jets_AK5PF_py_->GetEntry(entry_);
    c_jets_AK5PF_py_ = true;
  }
  return jets_AK5PF_py_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_pz() const{
  if(!c_jets_AK5PF_pz_ && b_jets_AK5PF_pz_){
    b_jets_AK5PF_pz_->GetEntry(entry_);
    c_jets_AK5PF_pz_ = true;
  }
  return jets_AK5PF_pz_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_rawPt() const{
  if(!c_jets_AK5PF_rawPt_ && b_jets_AK5PF_rawPt_){
    b_jets_AK5PF_rawPt_->GetEntry(entry_);
    c_jets_AK5PF_rawPt_ = true;
  }
  return jets_AK5PF_rawPt_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_status() const{
  if(!c_jets_AK5PF_status_ && b_jets_AK5PF_status_){
    b_jets_AK5PF_status_->GetEntry(entry_);
    c_jets_AK5PF_status_ = true;
  }
  return jets_AK5PF_status_;
}

std::vector<float>* const & cfa_8::jets_AK5PF_theta() const{
  if(!c_jets_AK5PF_theta_ && b_jets_AK5PF_theta_){
    b_jets_AK5PF_theta_->GetEntry(entry_);
    c_jets_AK5PF_theta_ = true;
  }
  return jets_AK5PF_theta_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_Uncert() const{
  if(!c_jets_AK5PFclean_Uncert_ && b_jets_AK5PFclean_Uncert_){
    b_jets_AK5PFclean_Uncert_->GetEntry(entry_);
    c_jets_AK5PFclean_Uncert_ = true;
  }
  return jets_AK5PFclean_Uncert_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_area() const{
  if(!c_jets_AK5PFclean_area_ && b_jets_AK5PFclean_area_){
    b_jets_AK5PFclean_area_->GetEntry(entry_);
    c_jets_AK5PFclean_area_ = true;
  }
  return jets_AK5PFclean_area_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_btag_TC_highEff() const{
  if(!c_jets_AK5PFclean_btag_TC_highEff_ && b_jets_AK5PFclean_btag_TC_highEff_){
    b_jets_AK5PFclean_btag_TC_highEff_->GetEntry(entry_);
    c_jets_AK5PFclean_btag_TC_highEff_ = true;
  }
  return jets_AK5PFclean_btag_TC_highEff_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_btag_TC_highPur() const{
  if(!c_jets_AK5PFclean_btag_TC_highPur_ && b_jets_AK5PFclean_btag_TC_highPur_){
    b_jets_AK5PFclean_btag_TC_highPur_->GetEntry(entry_);
    c_jets_AK5PFclean_btag_TC_highPur_ = true;
  }
  return jets_AK5PFclean_btag_TC_highPur_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_btag_jetBProb() const{
  if(!c_jets_AK5PFclean_btag_jetBProb_ && b_jets_AK5PFclean_btag_jetBProb_){
    b_jets_AK5PFclean_btag_jetBProb_->GetEntry(entry_);
    c_jets_AK5PFclean_btag_jetBProb_ = true;
  }
  return jets_AK5PFclean_btag_jetBProb_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_btag_jetProb() const{
  if(!c_jets_AK5PFclean_btag_jetProb_ && b_jets_AK5PFclean_btag_jetProb_){
    b_jets_AK5PFclean_btag_jetProb_->GetEntry(entry_);
    c_jets_AK5PFclean_btag_jetProb_ = true;
  }
  return jets_AK5PFclean_btag_jetProb_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_btag_secVertexCombined() const{
  if(!c_jets_AK5PFclean_btag_secVertexCombined_ && b_jets_AK5PFclean_btag_secVertexCombined_){
    b_jets_AK5PFclean_btag_secVertexCombined_->GetEntry(entry_);
    c_jets_AK5PFclean_btag_secVertexCombined_ = true;
  }
  return jets_AK5PFclean_btag_secVertexCombined_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_btag_secVertexHighEff() const{
  if(!c_jets_AK5PFclean_btag_secVertexHighEff_ && b_jets_AK5PFclean_btag_secVertexHighEff_){
    b_jets_AK5PFclean_btag_secVertexHighEff_->GetEntry(entry_);
    c_jets_AK5PFclean_btag_secVertexHighEff_ = true;
  }
  return jets_AK5PFclean_btag_secVertexHighEff_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_btag_secVertexHighPur() const{
  if(!c_jets_AK5PFclean_btag_secVertexHighPur_ && b_jets_AK5PFclean_btag_secVertexHighPur_){
    b_jets_AK5PFclean_btag_secVertexHighPur_->GetEntry(entry_);
    c_jets_AK5PFclean_btag_secVertexHighPur_ = true;
  }
  return jets_AK5PFclean_btag_secVertexHighPur_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_btag_softEle() const{
  if(!c_jets_AK5PFclean_btag_softEle_ && b_jets_AK5PFclean_btag_softEle_){
    b_jets_AK5PFclean_btag_softEle_->GetEntry(entry_);
    c_jets_AK5PFclean_btag_softEle_ = true;
  }
  return jets_AK5PFclean_btag_softEle_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_btag_softMuon() const{
  if(!c_jets_AK5PFclean_btag_softMuon_ && b_jets_AK5PFclean_btag_softMuon_){
    b_jets_AK5PFclean_btag_softMuon_->GetEntry(entry_);
    c_jets_AK5PFclean_btag_softMuon_ = true;
  }
  return jets_AK5PFclean_btag_softMuon_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_chgEmE() const{
  if(!c_jets_AK5PFclean_chgEmE_ && b_jets_AK5PFclean_chgEmE_){
    b_jets_AK5PFclean_chgEmE_->GetEntry(entry_);
    c_jets_AK5PFclean_chgEmE_ = true;
  }
  return jets_AK5PFclean_chgEmE_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_chgHadE() const{
  if(!c_jets_AK5PFclean_chgHadE_ && b_jets_AK5PFclean_chgHadE_){
    b_jets_AK5PFclean_chgHadE_->GetEntry(entry_);
    c_jets_AK5PFclean_chgHadE_ = true;
  }
  return jets_AK5PFclean_chgHadE_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_chgMuE() const{
  if(!c_jets_AK5PFclean_chgMuE_ && b_jets_AK5PFclean_chgMuE_){
    b_jets_AK5PFclean_chgMuE_->GetEntry(entry_);
    c_jets_AK5PFclean_chgMuE_ = true;
  }
  return jets_AK5PFclean_chgMuE_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_chg_Mult() const{
  if(!c_jets_AK5PFclean_chg_Mult_ && b_jets_AK5PFclean_chg_Mult_){
    b_jets_AK5PFclean_chg_Mult_->GetEntry(entry_);
    c_jets_AK5PFclean_chg_Mult_ = true;
  }
  return jets_AK5PFclean_chg_Mult_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_corrFactorRaw() const{
  if(!c_jets_AK5PFclean_corrFactorRaw_ && b_jets_AK5PFclean_corrFactorRaw_){
    b_jets_AK5PFclean_corrFactorRaw_->GetEntry(entry_);
    c_jets_AK5PFclean_corrFactorRaw_ = true;
  }
  return jets_AK5PFclean_corrFactorRaw_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_corrL1FastL2L3() const{
  if(!c_jets_AK5PFclean_corrL1FastL2L3_ && b_jets_AK5PFclean_corrL1FastL2L3_){
    b_jets_AK5PFclean_corrL1FastL2L3_->GetEntry(entry_);
    c_jets_AK5PFclean_corrL1FastL2L3_ = true;
  }
  return jets_AK5PFclean_corrL1FastL2L3_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_corrL1FastL2L3Residual() const{
  if(!c_jets_AK5PFclean_corrL1FastL2L3Residual_ && b_jets_AK5PFclean_corrL1FastL2L3Residual_){
    b_jets_AK5PFclean_corrL1FastL2L3Residual_->GetEntry(entry_);
    c_jets_AK5PFclean_corrL1FastL2L3Residual_ = true;
  }
  return jets_AK5PFclean_corrL1FastL2L3Residual_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_corrL1L2L3() const{
  if(!c_jets_AK5PFclean_corrL1L2L3_ && b_jets_AK5PFclean_corrL1L2L3_){
    b_jets_AK5PFclean_corrL1L2L3_->GetEntry(entry_);
    c_jets_AK5PFclean_corrL1L2L3_ = true;
  }
  return jets_AK5PFclean_corrL1L2L3_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_corrL1L2L3Residual() const{
  if(!c_jets_AK5PFclean_corrL1L2L3Residual_ && b_jets_AK5PFclean_corrL1L2L3Residual_){
    b_jets_AK5PFclean_corrL1L2L3Residual_->GetEntry(entry_);
    c_jets_AK5PFclean_corrL1L2L3Residual_ = true;
  }
  return jets_AK5PFclean_corrL1L2L3Residual_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_corrL2L3() const{
  if(!c_jets_AK5PFclean_corrL2L3_ && b_jets_AK5PFclean_corrL2L3_){
    b_jets_AK5PFclean_corrL2L3_->GetEntry(entry_);
    c_jets_AK5PFclean_corrL2L3_ = true;
  }
  return jets_AK5PFclean_corrL2L3_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_corrL2L3Residual() const{
  if(!c_jets_AK5PFclean_corrL2L3Residual_ && b_jets_AK5PFclean_corrL2L3Residual_){
    b_jets_AK5PFclean_corrL2L3Residual_->GetEntry(entry_);
    c_jets_AK5PFclean_corrL2L3Residual_ = true;
  }
  return jets_AK5PFclean_corrL2L3Residual_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_ehf() const{
  if(!c_jets_AK5PFclean_ehf_ && b_jets_AK5PFclean_ehf_){
    b_jets_AK5PFclean_ehf_->GetEntry(entry_);
    c_jets_AK5PFclean_ehf_ = true;
  }
  return jets_AK5PFclean_ehf_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_emf() const{
  if(!c_jets_AK5PFclean_emf_ && b_jets_AK5PFclean_emf_){
    b_jets_AK5PFclean_emf_->GetEntry(entry_);
    c_jets_AK5PFclean_emf_ = true;
  }
  return jets_AK5PFclean_emf_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_energy() const{
  if(!c_jets_AK5PFclean_energy_ && b_jets_AK5PFclean_energy_){
    b_jets_AK5PFclean_energy_->GetEntry(entry_);
    c_jets_AK5PFclean_energy_ = true;
  }
  return jets_AK5PFclean_energy_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_et() const{
  if(!c_jets_AK5PFclean_et_ && b_jets_AK5PFclean_et_){
    b_jets_AK5PFclean_et_->GetEntry(entry_);
    c_jets_AK5PFclean_et_ = true;
  }
  return jets_AK5PFclean_et_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_eta() const{
  if(!c_jets_AK5PFclean_eta_ && b_jets_AK5PFclean_eta_){
    b_jets_AK5PFclean_eta_->GetEntry(entry_);
    c_jets_AK5PFclean_eta_ = true;
  }
  return jets_AK5PFclean_eta_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_etaetaMoment() const{
  if(!c_jets_AK5PFclean_etaetaMoment_ && b_jets_AK5PFclean_etaetaMoment_){
    b_jets_AK5PFclean_etaetaMoment_->GetEntry(entry_);
    c_jets_AK5PFclean_etaetaMoment_ = true;
  }
  return jets_AK5PFclean_etaetaMoment_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_etaphiMoment() const{
  if(!c_jets_AK5PFclean_etaphiMoment_ && b_jets_AK5PFclean_etaphiMoment_){
    b_jets_AK5PFclean_etaphiMoment_->GetEntry(entry_);
    c_jets_AK5PFclean_etaphiMoment_ = true;
  }
  return jets_AK5PFclean_etaphiMoment_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_fHPD() const{
  if(!c_jets_AK5PFclean_fHPD_ && b_jets_AK5PFclean_fHPD_){
    b_jets_AK5PFclean_fHPD_->GetEntry(entry_);
    c_jets_AK5PFclean_fHPD_ = true;
  }
  return jets_AK5PFclean_fHPD_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_fRBX() const{
  if(!c_jets_AK5PFclean_fRBX_ && b_jets_AK5PFclean_fRBX_){
    b_jets_AK5PFclean_fRBX_->GetEntry(entry_);
    c_jets_AK5PFclean_fRBX_ = true;
  }
  return jets_AK5PFclean_fRBX_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_fSubDetector1() const{
  if(!c_jets_AK5PFclean_fSubDetector1_ && b_jets_AK5PFclean_fSubDetector1_){
    b_jets_AK5PFclean_fSubDetector1_->GetEntry(entry_);
    c_jets_AK5PFclean_fSubDetector1_ = true;
  }
  return jets_AK5PFclean_fSubDetector1_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_fSubDetector2() const{
  if(!c_jets_AK5PFclean_fSubDetector2_ && b_jets_AK5PFclean_fSubDetector2_){
    b_jets_AK5PFclean_fSubDetector2_->GetEntry(entry_);
    c_jets_AK5PFclean_fSubDetector2_ = true;
  }
  return jets_AK5PFclean_fSubDetector2_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_fSubDetector3() const{
  if(!c_jets_AK5PFclean_fSubDetector3_ && b_jets_AK5PFclean_fSubDetector3_){
    b_jets_AK5PFclean_fSubDetector3_->GetEntry(entry_);
    c_jets_AK5PFclean_fSubDetector3_ = true;
  }
  return jets_AK5PFclean_fSubDetector3_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_fSubDetector4() const{
  if(!c_jets_AK5PFclean_fSubDetector4_ && b_jets_AK5PFclean_fSubDetector4_){
    b_jets_AK5PFclean_fSubDetector4_->GetEntry(entry_);
    c_jets_AK5PFclean_fSubDetector4_ = true;
  }
  return jets_AK5PFclean_fSubDetector4_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_gen_Energy() const{
  if(!c_jets_AK5PFclean_gen_Energy_ && b_jets_AK5PFclean_gen_Energy_){
    b_jets_AK5PFclean_gen_Energy_->GetEntry(entry_);
    c_jets_AK5PFclean_gen_Energy_ = true;
  }
  return jets_AK5PFclean_gen_Energy_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_gen_Id() const{
  if(!c_jets_AK5PFclean_gen_Id_ && b_jets_AK5PFclean_gen_Id_){
    b_jets_AK5PFclean_gen_Id_->GetEntry(entry_);
    c_jets_AK5PFclean_gen_Id_ = true;
  }
  return jets_AK5PFclean_gen_Id_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_gen_et() const{
  if(!c_jets_AK5PFclean_gen_et_ && b_jets_AK5PFclean_gen_et_){
    b_jets_AK5PFclean_gen_et_->GetEntry(entry_);
    c_jets_AK5PFclean_gen_et_ = true;
  }
  return jets_AK5PFclean_gen_et_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_gen_eta() const{
  if(!c_jets_AK5PFclean_gen_eta_ && b_jets_AK5PFclean_gen_eta_){
    b_jets_AK5PFclean_gen_eta_->GetEntry(entry_);
    c_jets_AK5PFclean_gen_eta_ = true;
  }
  return jets_AK5PFclean_gen_eta_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_gen_mass() const{
  if(!c_jets_AK5PFclean_gen_mass_ && b_jets_AK5PFclean_gen_mass_){
    b_jets_AK5PFclean_gen_mass_->GetEntry(entry_);
    c_jets_AK5PFclean_gen_mass_ = true;
  }
  return jets_AK5PFclean_gen_mass_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_gen_phi() const{
  if(!c_jets_AK5PFclean_gen_phi_ && b_jets_AK5PFclean_gen_phi_){
    b_jets_AK5PFclean_gen_phi_->GetEntry(entry_);
    c_jets_AK5PFclean_gen_phi_ = true;
  }
  return jets_AK5PFclean_gen_phi_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_gen_pt() const{
  if(!c_jets_AK5PFclean_gen_pt_ && b_jets_AK5PFclean_gen_pt_){
    b_jets_AK5PFclean_gen_pt_->GetEntry(entry_);
    c_jets_AK5PFclean_gen_pt_ = true;
  }
  return jets_AK5PFclean_gen_pt_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_hitsInN90() const{
  if(!c_jets_AK5PFclean_hitsInN90_ && b_jets_AK5PFclean_hitsInN90_){
    b_jets_AK5PFclean_hitsInN90_->GetEntry(entry_);
    c_jets_AK5PFclean_hitsInN90_ = true;
  }
  return jets_AK5PFclean_hitsInN90_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_jetCharge() const{
  if(!c_jets_AK5PFclean_jetCharge_ && b_jets_AK5PFclean_jetCharge_){
    b_jets_AK5PFclean_jetCharge_->GetEntry(entry_);
    c_jets_AK5PFclean_jetCharge_ = true;
  }
  return jets_AK5PFclean_jetCharge_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_mass() const{
  if(!c_jets_AK5PFclean_mass_ && b_jets_AK5PFclean_mass_){
    b_jets_AK5PFclean_mass_->GetEntry(entry_);
    c_jets_AK5PFclean_mass_ = true;
  }
  return jets_AK5PFclean_mass_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_mu_Mult() const{
  if(!c_jets_AK5PFclean_mu_Mult_ && b_jets_AK5PFclean_mu_Mult_){
    b_jets_AK5PFclean_mu_Mult_->GetEntry(entry_);
    c_jets_AK5PFclean_mu_Mult_ = true;
  }
  return jets_AK5PFclean_mu_Mult_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_n60() const{
  if(!c_jets_AK5PFclean_n60_ && b_jets_AK5PFclean_n60_){
    b_jets_AK5PFclean_n60_->GetEntry(entry_);
    c_jets_AK5PFclean_n60_ = true;
  }
  return jets_AK5PFclean_n60_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_n90() const{
  if(!c_jets_AK5PFclean_n90_ && b_jets_AK5PFclean_n90_){
    b_jets_AK5PFclean_n90_->GetEntry(entry_);
    c_jets_AK5PFclean_n90_ = true;
  }
  return jets_AK5PFclean_n90_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_n90Hits() const{
  if(!c_jets_AK5PFclean_n90Hits_ && b_jets_AK5PFclean_n90Hits_){
    b_jets_AK5PFclean_n90Hits_->GetEntry(entry_);
    c_jets_AK5PFclean_n90Hits_ = true;
  }
  return jets_AK5PFclean_n90Hits_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_nECALTowers() const{
  if(!c_jets_AK5PFclean_nECALTowers_ && b_jets_AK5PFclean_nECALTowers_){
    b_jets_AK5PFclean_nECALTowers_->GetEntry(entry_);
    c_jets_AK5PFclean_nECALTowers_ = true;
  }
  return jets_AK5PFclean_nECALTowers_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_nHCALTowers() const{
  if(!c_jets_AK5PFclean_nHCALTowers_ && b_jets_AK5PFclean_nHCALTowers_){
    b_jets_AK5PFclean_nHCALTowers_->GetEntry(entry_);
    c_jets_AK5PFclean_nHCALTowers_ = true;
  }
  return jets_AK5PFclean_nHCALTowers_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_neutralEmE() const{
  if(!c_jets_AK5PFclean_neutralEmE_ && b_jets_AK5PFclean_neutralEmE_){
    b_jets_AK5PFclean_neutralEmE_->GetEntry(entry_);
    c_jets_AK5PFclean_neutralEmE_ = true;
  }
  return jets_AK5PFclean_neutralEmE_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_neutralHadE() const{
  if(!c_jets_AK5PFclean_neutralHadE_ && b_jets_AK5PFclean_neutralHadE_){
    b_jets_AK5PFclean_neutralHadE_->GetEntry(entry_);
    c_jets_AK5PFclean_neutralHadE_ = true;
  }
  return jets_AK5PFclean_neutralHadE_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_neutral_Mult() const{
  if(!c_jets_AK5PFclean_neutral_Mult_ && b_jets_AK5PFclean_neutral_Mult_){
    b_jets_AK5PFclean_neutral_Mult_->GetEntry(entry_);
    c_jets_AK5PFclean_neutral_Mult_ = true;
  }
  return jets_AK5PFclean_neutral_Mult_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_partonFlavour() const{
  if(!c_jets_AK5PFclean_partonFlavour_ && b_jets_AK5PFclean_partonFlavour_){
    b_jets_AK5PFclean_partonFlavour_->GetEntry(entry_);
    c_jets_AK5PFclean_partonFlavour_ = true;
  }
  return jets_AK5PFclean_partonFlavour_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_parton_Energy() const{
  if(!c_jets_AK5PFclean_parton_Energy_ && b_jets_AK5PFclean_parton_Energy_){
    b_jets_AK5PFclean_parton_Energy_->GetEntry(entry_);
    c_jets_AK5PFclean_parton_Energy_ = true;
  }
  return jets_AK5PFclean_parton_Energy_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_parton_Id() const{
  if(!c_jets_AK5PFclean_parton_Id_ && b_jets_AK5PFclean_parton_Id_){
    b_jets_AK5PFclean_parton_Id_->GetEntry(entry_);
    c_jets_AK5PFclean_parton_Id_ = true;
  }
  return jets_AK5PFclean_parton_Id_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_parton_eta() const{
  if(!c_jets_AK5PFclean_parton_eta_ && b_jets_AK5PFclean_parton_eta_){
    b_jets_AK5PFclean_parton_eta_->GetEntry(entry_);
    c_jets_AK5PFclean_parton_eta_ = true;
  }
  return jets_AK5PFclean_parton_eta_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_parton_mass() const{
  if(!c_jets_AK5PFclean_parton_mass_ && b_jets_AK5PFclean_parton_mass_){
    b_jets_AK5PFclean_parton_mass_->GetEntry(entry_);
    c_jets_AK5PFclean_parton_mass_ = true;
  }
  return jets_AK5PFclean_parton_mass_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_parton_motherId() const{
  if(!c_jets_AK5PFclean_parton_motherId_ && b_jets_AK5PFclean_parton_motherId_){
    b_jets_AK5PFclean_parton_motherId_->GetEntry(entry_);
    c_jets_AK5PFclean_parton_motherId_ = true;
  }
  return jets_AK5PFclean_parton_motherId_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_parton_phi() const{
  if(!c_jets_AK5PFclean_parton_phi_ && b_jets_AK5PFclean_parton_phi_){
    b_jets_AK5PFclean_parton_phi_->GetEntry(entry_);
    c_jets_AK5PFclean_parton_phi_ = true;
  }
  return jets_AK5PFclean_parton_phi_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_parton_pt() const{
  if(!c_jets_AK5PFclean_parton_pt_ && b_jets_AK5PFclean_parton_pt_){
    b_jets_AK5PFclean_parton_pt_->GetEntry(entry_);
    c_jets_AK5PFclean_parton_pt_ = true;
  }
  return jets_AK5PFclean_parton_pt_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_phi() const{
  if(!c_jets_AK5PFclean_phi_ && b_jets_AK5PFclean_phi_){
    b_jets_AK5PFclean_phi_->GetEntry(entry_);
    c_jets_AK5PFclean_phi_ = true;
  }
  return jets_AK5PFclean_phi_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_phiphiMoment() const{
  if(!c_jets_AK5PFclean_phiphiMoment_ && b_jets_AK5PFclean_phiphiMoment_){
    b_jets_AK5PFclean_phiphiMoment_->GetEntry(entry_);
    c_jets_AK5PFclean_phiphiMoment_ = true;
  }
  return jets_AK5PFclean_phiphiMoment_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_photonEnergy() const{
  if(!c_jets_AK5PFclean_photonEnergy_ && b_jets_AK5PFclean_photonEnergy_){
    b_jets_AK5PFclean_photonEnergy_->GetEntry(entry_);
    c_jets_AK5PFclean_photonEnergy_ = true;
  }
  return jets_AK5PFclean_photonEnergy_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_pt() const{
  if(!c_jets_AK5PFclean_pt_ && b_jets_AK5PFclean_pt_){
    b_jets_AK5PFclean_pt_->GetEntry(entry_);
    c_jets_AK5PFclean_pt_ = true;
  }
  return jets_AK5PFclean_pt_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_px() const{
  if(!c_jets_AK5PFclean_px_ && b_jets_AK5PFclean_px_){
    b_jets_AK5PFclean_px_->GetEntry(entry_);
    c_jets_AK5PFclean_px_ = true;
  }
  return jets_AK5PFclean_px_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_py() const{
  if(!c_jets_AK5PFclean_py_ && b_jets_AK5PFclean_py_){
    b_jets_AK5PFclean_py_->GetEntry(entry_);
    c_jets_AK5PFclean_py_ = true;
  }
  return jets_AK5PFclean_py_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_pz() const{
  if(!c_jets_AK5PFclean_pz_ && b_jets_AK5PFclean_pz_){
    b_jets_AK5PFclean_pz_->GetEntry(entry_);
    c_jets_AK5PFclean_pz_ = true;
  }
  return jets_AK5PFclean_pz_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_rawPt() const{
  if(!c_jets_AK5PFclean_rawPt_ && b_jets_AK5PFclean_rawPt_){
    b_jets_AK5PFclean_rawPt_->GetEntry(entry_);
    c_jets_AK5PFclean_rawPt_ = true;
  }
  return jets_AK5PFclean_rawPt_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_status() const{
  if(!c_jets_AK5PFclean_status_ && b_jets_AK5PFclean_status_){
    b_jets_AK5PFclean_status_->GetEntry(entry_);
    c_jets_AK5PFclean_status_ = true;
  }
  return jets_AK5PFclean_status_;
}

std::vector<float>* const & cfa_8::jets_AK5PFclean_theta() const{
  if(!c_jets_AK5PFclean_theta_ && b_jets_AK5PFclean_theta_){
    b_jets_AK5PFclean_theta_->GetEntry(entry_);
    c_jets_AK5PFclean_theta_ = true;
  }
  return jets_AK5PFclean_theta_;
}

UInt_t const & cfa_8::lumiblock() const{
  if(!c_lumiblock_ && b_lumiblock_){
    b_lumiblock_->GetEntry(entry_);
    c_lumiblock_ = true;
  }
  return lumiblock_;
}

std::vector<float>* const & cfa_8::mc_doc_charge() const{
  if(!c_mc_doc_charge_ && b_mc_doc_charge_){
    b_mc_doc_charge_->GetEntry(entry_);
    c_mc_doc_charge_ = true;
  }
  return mc_doc_charge_;
}

std::vector<float>* const & cfa_8::mc_doc_energy() const{
  if(!c_mc_doc_energy_ && b_mc_doc_energy_){
    b_mc_doc_energy_->GetEntry(entry_);
    c_mc_doc_energy_ = true;
  }
  return mc_doc_energy_;
}

std::vector<float>* const & cfa_8::mc_doc_eta() const{
  if(!c_mc_doc_eta_ && b_mc_doc_eta_){
    b_mc_doc_eta_->GetEntry(entry_);
    c_mc_doc_eta_ = true;
  }
  return mc_doc_eta_;
}

std::vector<float>* const & cfa_8::mc_doc_ggrandmother_id() const{
  if(!c_mc_doc_ggrandmother_id_ && b_mc_doc_ggrandmother_id_){
    b_mc_doc_ggrandmother_id_->GetEntry(entry_);
    c_mc_doc_ggrandmother_id_ = true;
  }
  return mc_doc_ggrandmother_id_;
}

std::vector<float>* const & cfa_8::mc_doc_grandmother_id() const{
  if(!c_mc_doc_grandmother_id_ && b_mc_doc_grandmother_id_){
    b_mc_doc_grandmother_id_->GetEntry(entry_);
    c_mc_doc_grandmother_id_ = true;
  }
  return mc_doc_grandmother_id_;
}

std::vector<float>* const & cfa_8::mc_doc_id() const{
  if(!c_mc_doc_id_ && b_mc_doc_id_){
    b_mc_doc_id_->GetEntry(entry_);
    c_mc_doc_id_ = true;
  }
  return mc_doc_id_;
}

std::vector<float>* const & cfa_8::mc_doc_mass() const{
  if(!c_mc_doc_mass_ && b_mc_doc_mass_){
    b_mc_doc_mass_->GetEntry(entry_);
    c_mc_doc_mass_ = true;
  }
  return mc_doc_mass_;
}

std::vector<float>* const & cfa_8::mc_doc_mother_id() const{
  if(!c_mc_doc_mother_id_ && b_mc_doc_mother_id_){
    b_mc_doc_mother_id_->GetEntry(entry_);
    c_mc_doc_mother_id_ = true;
  }
  return mc_doc_mother_id_;
}

std::vector<float>* const & cfa_8::mc_doc_mother_pt() const{
  if(!c_mc_doc_mother_pt_ && b_mc_doc_mother_pt_){
    b_mc_doc_mother_pt_->GetEntry(entry_);
    c_mc_doc_mother_pt_ = true;
  }
  return mc_doc_mother_pt_;
}

std::vector<float>* const & cfa_8::mc_doc_numOfDaughters() const{
  if(!c_mc_doc_numOfDaughters_ && b_mc_doc_numOfDaughters_){
    b_mc_doc_numOfDaughters_->GetEntry(entry_);
    c_mc_doc_numOfDaughters_ = true;
  }
  return mc_doc_numOfDaughters_;
}

std::vector<float>* const & cfa_8::mc_doc_numOfMothers() const{
  if(!c_mc_doc_numOfMothers_ && b_mc_doc_numOfMothers_){
    b_mc_doc_numOfMothers_->GetEntry(entry_);
    c_mc_doc_numOfMothers_ = true;
  }
  return mc_doc_numOfMothers_;
}

std::vector<float>* const & cfa_8::mc_doc_phi() const{
  if(!c_mc_doc_phi_ && b_mc_doc_phi_){
    b_mc_doc_phi_->GetEntry(entry_);
    c_mc_doc_phi_ = true;
  }
  return mc_doc_phi_;
}

std::vector<float>* const & cfa_8::mc_doc_pt() const{
  if(!c_mc_doc_pt_ && b_mc_doc_pt_){
    b_mc_doc_pt_->GetEntry(entry_);
    c_mc_doc_pt_ = true;
  }
  return mc_doc_pt_;
}

std::vector<float>* const & cfa_8::mc_doc_px() const{
  if(!c_mc_doc_px_ && b_mc_doc_px_){
    b_mc_doc_px_->GetEntry(entry_);
    c_mc_doc_px_ = true;
  }
  return mc_doc_px_;
}

std::vector<float>* const & cfa_8::mc_doc_py() const{
  if(!c_mc_doc_py_ && b_mc_doc_py_){
    b_mc_doc_py_->GetEntry(entry_);
    c_mc_doc_py_ = true;
  }
  return mc_doc_py_;
}

std::vector<float>* const & cfa_8::mc_doc_pz() const{
  if(!c_mc_doc_pz_ && b_mc_doc_pz_){
    b_mc_doc_pz_->GetEntry(entry_);
    c_mc_doc_pz_ = true;
  }
  return mc_doc_pz_;
}

std::vector<float>* const & cfa_8::mc_doc_status() const{
  if(!c_mc_doc_status_ && b_mc_doc_status_){
    b_mc_doc_status_->GetEntry(entry_);
    c_mc_doc_status_ = true;
  }
  return mc_doc_status_;
}

std::vector<float>* const & cfa_8::mc_doc_theta() const{
  if(!c_mc_doc_theta_ && b_mc_doc_theta_){
    b_mc_doc_theta_->GetEntry(entry_);
    c_mc_doc_theta_ = true;
  }
  return mc_doc_theta_;
}

std::vector<float>* const & cfa_8::mc_doc_vertex_x() const{
  if(!c_mc_doc_vertex_x_ && b_mc_doc_vertex_x_){
    b_mc_doc_vertex_x_->GetEntry(entry_);
    c_mc_doc_vertex_x_ = true;
  }
  return mc_doc_vertex_x_;
}

std::vector<float>* const & cfa_8::mc_doc_vertex_y() const{
  if(!c_mc_doc_vertex_y_ && b_mc_doc_vertex_y_){
    b_mc_doc_vertex_y_->GetEntry(entry_);
    c_mc_doc_vertex_y_ = true;
  }
  return mc_doc_vertex_y_;
}

std::vector<float>* const & cfa_8::mc_doc_vertex_z() const{
  if(!c_mc_doc_vertex_z_ && b_mc_doc_vertex_z_){
    b_mc_doc_vertex_z_->GetEntry(entry_);
    c_mc_doc_vertex_z_ = true;
  }
  return mc_doc_vertex_z_;
}

std::vector<float>* const & cfa_8::mc_electrons_charge() const{
  if(!c_mc_electrons_charge_ && b_mc_electrons_charge_){
    b_mc_electrons_charge_->GetEntry(entry_);
    c_mc_electrons_charge_ = true;
  }
  return mc_electrons_charge_;
}

std::vector<float>* const & cfa_8::mc_electrons_energy() const{
  if(!c_mc_electrons_energy_ && b_mc_electrons_energy_){
    b_mc_electrons_energy_->GetEntry(entry_);
    c_mc_electrons_energy_ = true;
  }
  return mc_electrons_energy_;
}

std::vector<float>* const & cfa_8::mc_electrons_eta() const{
  if(!c_mc_electrons_eta_ && b_mc_electrons_eta_){
    b_mc_electrons_eta_->GetEntry(entry_);
    c_mc_electrons_eta_ = true;
  }
  return mc_electrons_eta_;
}

std::vector<float>* const & cfa_8::mc_electrons_ggrandmother_id() const{
  if(!c_mc_electrons_ggrandmother_id_ && b_mc_electrons_ggrandmother_id_){
    b_mc_electrons_ggrandmother_id_->GetEntry(entry_);
    c_mc_electrons_ggrandmother_id_ = true;
  }
  return mc_electrons_ggrandmother_id_;
}

std::vector<float>* const & cfa_8::mc_electrons_grandmother_id() const{
  if(!c_mc_electrons_grandmother_id_ && b_mc_electrons_grandmother_id_){
    b_mc_electrons_grandmother_id_->GetEntry(entry_);
    c_mc_electrons_grandmother_id_ = true;
  }
  return mc_electrons_grandmother_id_;
}

std::vector<float>* const & cfa_8::mc_electrons_id() const{
  if(!c_mc_electrons_id_ && b_mc_electrons_id_){
    b_mc_electrons_id_->GetEntry(entry_);
    c_mc_electrons_id_ = true;
  }
  return mc_electrons_id_;
}

std::vector<float>* const & cfa_8::mc_electrons_mass() const{
  if(!c_mc_electrons_mass_ && b_mc_electrons_mass_){
    b_mc_electrons_mass_->GetEntry(entry_);
    c_mc_electrons_mass_ = true;
  }
  return mc_electrons_mass_;
}

std::vector<float>* const & cfa_8::mc_electrons_mother_id() const{
  if(!c_mc_electrons_mother_id_ && b_mc_electrons_mother_id_){
    b_mc_electrons_mother_id_->GetEntry(entry_);
    c_mc_electrons_mother_id_ = true;
  }
  return mc_electrons_mother_id_;
}

std::vector<float>* const & cfa_8::mc_electrons_mother_pt() const{
  if(!c_mc_electrons_mother_pt_ && b_mc_electrons_mother_pt_){
    b_mc_electrons_mother_pt_->GetEntry(entry_);
    c_mc_electrons_mother_pt_ = true;
  }
  return mc_electrons_mother_pt_;
}

std::vector<float>* const & cfa_8::mc_electrons_numOfDaughters() const{
  if(!c_mc_electrons_numOfDaughters_ && b_mc_electrons_numOfDaughters_){
    b_mc_electrons_numOfDaughters_->GetEntry(entry_);
    c_mc_electrons_numOfDaughters_ = true;
  }
  return mc_electrons_numOfDaughters_;
}

std::vector<float>* const & cfa_8::mc_electrons_phi() const{
  if(!c_mc_electrons_phi_ && b_mc_electrons_phi_){
    b_mc_electrons_phi_->GetEntry(entry_);
    c_mc_electrons_phi_ = true;
  }
  return mc_electrons_phi_;
}

std::vector<float>* const & cfa_8::mc_electrons_pt() const{
  if(!c_mc_electrons_pt_ && b_mc_electrons_pt_){
    b_mc_electrons_pt_->GetEntry(entry_);
    c_mc_electrons_pt_ = true;
  }
  return mc_electrons_pt_;
}

std::vector<float>* const & cfa_8::mc_electrons_px() const{
  if(!c_mc_electrons_px_ && b_mc_electrons_px_){
    b_mc_electrons_px_->GetEntry(entry_);
    c_mc_electrons_px_ = true;
  }
  return mc_electrons_px_;
}

std::vector<float>* const & cfa_8::mc_electrons_py() const{
  if(!c_mc_electrons_py_ && b_mc_electrons_py_){
    b_mc_electrons_py_->GetEntry(entry_);
    c_mc_electrons_py_ = true;
  }
  return mc_electrons_py_;
}

std::vector<float>* const & cfa_8::mc_electrons_pz() const{
  if(!c_mc_electrons_pz_ && b_mc_electrons_pz_){
    b_mc_electrons_pz_->GetEntry(entry_);
    c_mc_electrons_pz_ = true;
  }
  return mc_electrons_pz_;
}

std::vector<float>* const & cfa_8::mc_electrons_status() const{
  if(!c_mc_electrons_status_ && b_mc_electrons_status_){
    b_mc_electrons_status_->GetEntry(entry_);
    c_mc_electrons_status_ = true;
  }
  return mc_electrons_status_;
}

std::vector<float>* const & cfa_8::mc_electrons_theta() const{
  if(!c_mc_electrons_theta_ && b_mc_electrons_theta_){
    b_mc_electrons_theta_->GetEntry(entry_);
    c_mc_electrons_theta_ = true;
  }
  return mc_electrons_theta_;
}

std::vector<float>* const & cfa_8::mc_electrons_vertex_x() const{
  if(!c_mc_electrons_vertex_x_ && b_mc_electrons_vertex_x_){
    b_mc_electrons_vertex_x_->GetEntry(entry_);
    c_mc_electrons_vertex_x_ = true;
  }
  return mc_electrons_vertex_x_;
}

std::vector<float>* const & cfa_8::mc_electrons_vertex_y() const{
  if(!c_mc_electrons_vertex_y_ && b_mc_electrons_vertex_y_){
    b_mc_electrons_vertex_y_->GetEntry(entry_);
    c_mc_electrons_vertex_y_ = true;
  }
  return mc_electrons_vertex_y_;
}

std::vector<float>* const & cfa_8::mc_electrons_vertex_z() const{
  if(!c_mc_electrons_vertex_z_ && b_mc_electrons_vertex_z_){
    b_mc_electrons_vertex_z_->GetEntry(entry_);
    c_mc_electrons_vertex_z_ = true;
  }
  return mc_electrons_vertex_z_;
}

std::vector<float>* const & cfa_8::mc_mus_charge() const{
  if(!c_mc_mus_charge_ && b_mc_mus_charge_){
    b_mc_mus_charge_->GetEntry(entry_);
    c_mc_mus_charge_ = true;
  }
  return mc_mus_charge_;
}

std::vector<float>* const & cfa_8::mc_mus_energy() const{
  if(!c_mc_mus_energy_ && b_mc_mus_energy_){
    b_mc_mus_energy_->GetEntry(entry_);
    c_mc_mus_energy_ = true;
  }
  return mc_mus_energy_;
}

std::vector<float>* const & cfa_8::mc_mus_eta() const{
  if(!c_mc_mus_eta_ && b_mc_mus_eta_){
    b_mc_mus_eta_->GetEntry(entry_);
    c_mc_mus_eta_ = true;
  }
  return mc_mus_eta_;
}

std::vector<float>* const & cfa_8::mc_mus_ggrandmother_id() const{
  if(!c_mc_mus_ggrandmother_id_ && b_mc_mus_ggrandmother_id_){
    b_mc_mus_ggrandmother_id_->GetEntry(entry_);
    c_mc_mus_ggrandmother_id_ = true;
  }
  return mc_mus_ggrandmother_id_;
}

std::vector<float>* const & cfa_8::mc_mus_grandmother_id() const{
  if(!c_mc_mus_grandmother_id_ && b_mc_mus_grandmother_id_){
    b_mc_mus_grandmother_id_->GetEntry(entry_);
    c_mc_mus_grandmother_id_ = true;
  }
  return mc_mus_grandmother_id_;
}

std::vector<float>* const & cfa_8::mc_mus_id() const{
  if(!c_mc_mus_id_ && b_mc_mus_id_){
    b_mc_mus_id_->GetEntry(entry_);
    c_mc_mus_id_ = true;
  }
  return mc_mus_id_;
}

std::vector<float>* const & cfa_8::mc_mus_mass() const{
  if(!c_mc_mus_mass_ && b_mc_mus_mass_){
    b_mc_mus_mass_->GetEntry(entry_);
    c_mc_mus_mass_ = true;
  }
  return mc_mus_mass_;
}

std::vector<float>* const & cfa_8::mc_mus_mother_id() const{
  if(!c_mc_mus_mother_id_ && b_mc_mus_mother_id_){
    b_mc_mus_mother_id_->GetEntry(entry_);
    c_mc_mus_mother_id_ = true;
  }
  return mc_mus_mother_id_;
}

std::vector<float>* const & cfa_8::mc_mus_mother_pt() const{
  if(!c_mc_mus_mother_pt_ && b_mc_mus_mother_pt_){
    b_mc_mus_mother_pt_->GetEntry(entry_);
    c_mc_mus_mother_pt_ = true;
  }
  return mc_mus_mother_pt_;
}

std::vector<float>* const & cfa_8::mc_mus_numOfDaughters() const{
  if(!c_mc_mus_numOfDaughters_ && b_mc_mus_numOfDaughters_){
    b_mc_mus_numOfDaughters_->GetEntry(entry_);
    c_mc_mus_numOfDaughters_ = true;
  }
  return mc_mus_numOfDaughters_;
}

std::vector<float>* const & cfa_8::mc_mus_phi() const{
  if(!c_mc_mus_phi_ && b_mc_mus_phi_){
    b_mc_mus_phi_->GetEntry(entry_);
    c_mc_mus_phi_ = true;
  }
  return mc_mus_phi_;
}

std::vector<float>* const & cfa_8::mc_mus_pt() const{
  if(!c_mc_mus_pt_ && b_mc_mus_pt_){
    b_mc_mus_pt_->GetEntry(entry_);
    c_mc_mus_pt_ = true;
  }
  return mc_mus_pt_;
}

std::vector<float>* const & cfa_8::mc_mus_px() const{
  if(!c_mc_mus_px_ && b_mc_mus_px_){
    b_mc_mus_px_->GetEntry(entry_);
    c_mc_mus_px_ = true;
  }
  return mc_mus_px_;
}

std::vector<float>* const & cfa_8::mc_mus_py() const{
  if(!c_mc_mus_py_ && b_mc_mus_py_){
    b_mc_mus_py_->GetEntry(entry_);
    c_mc_mus_py_ = true;
  }
  return mc_mus_py_;
}

std::vector<float>* const & cfa_8::mc_mus_pz() const{
  if(!c_mc_mus_pz_ && b_mc_mus_pz_){
    b_mc_mus_pz_->GetEntry(entry_);
    c_mc_mus_pz_ = true;
  }
  return mc_mus_pz_;
}

std::vector<float>* const & cfa_8::mc_mus_status() const{
  if(!c_mc_mus_status_ && b_mc_mus_status_){
    b_mc_mus_status_->GetEntry(entry_);
    c_mc_mus_status_ = true;
  }
  return mc_mus_status_;
}

std::vector<float>* const & cfa_8::mc_mus_theta() const{
  if(!c_mc_mus_theta_ && b_mc_mus_theta_){
    b_mc_mus_theta_->GetEntry(entry_);
    c_mc_mus_theta_ = true;
  }
  return mc_mus_theta_;
}

std::vector<float>* const & cfa_8::mc_mus_vertex_x() const{
  if(!c_mc_mus_vertex_x_ && b_mc_mus_vertex_x_){
    b_mc_mus_vertex_x_->GetEntry(entry_);
    c_mc_mus_vertex_x_ = true;
  }
  return mc_mus_vertex_x_;
}

std::vector<float>* const & cfa_8::mc_mus_vertex_y() const{
  if(!c_mc_mus_vertex_y_ && b_mc_mus_vertex_y_){
    b_mc_mus_vertex_y_->GetEntry(entry_);
    c_mc_mus_vertex_y_ = true;
  }
  return mc_mus_vertex_y_;
}

std::vector<float>* const & cfa_8::mc_mus_vertex_z() const{
  if(!c_mc_mus_vertex_z_ && b_mc_mus_vertex_z_){
    b_mc_mus_vertex_z_->GetEntry(entry_);
    c_mc_mus_vertex_z_ = true;
  }
  return mc_mus_vertex_z_;
}

std::vector<float>* const & cfa_8::mc_nues_charge() const{
  if(!c_mc_nues_charge_ && b_mc_nues_charge_){
    b_mc_nues_charge_->GetEntry(entry_);
    c_mc_nues_charge_ = true;
  }
  return mc_nues_charge_;
}

std::vector<float>* const & cfa_8::mc_nues_energy() const{
  if(!c_mc_nues_energy_ && b_mc_nues_energy_){
    b_mc_nues_energy_->GetEntry(entry_);
    c_mc_nues_energy_ = true;
  }
  return mc_nues_energy_;
}

std::vector<float>* const & cfa_8::mc_nues_eta() const{
  if(!c_mc_nues_eta_ && b_mc_nues_eta_){
    b_mc_nues_eta_->GetEntry(entry_);
    c_mc_nues_eta_ = true;
  }
  return mc_nues_eta_;
}

std::vector<float>* const & cfa_8::mc_nues_ggrandmother_id() const{
  if(!c_mc_nues_ggrandmother_id_ && b_mc_nues_ggrandmother_id_){
    b_mc_nues_ggrandmother_id_->GetEntry(entry_);
    c_mc_nues_ggrandmother_id_ = true;
  }
  return mc_nues_ggrandmother_id_;
}

std::vector<float>* const & cfa_8::mc_nues_grandmother_id() const{
  if(!c_mc_nues_grandmother_id_ && b_mc_nues_grandmother_id_){
    b_mc_nues_grandmother_id_->GetEntry(entry_);
    c_mc_nues_grandmother_id_ = true;
  }
  return mc_nues_grandmother_id_;
}

std::vector<float>* const & cfa_8::mc_nues_id() const{
  if(!c_mc_nues_id_ && b_mc_nues_id_){
    b_mc_nues_id_->GetEntry(entry_);
    c_mc_nues_id_ = true;
  }
  return mc_nues_id_;
}

std::vector<float>* const & cfa_8::mc_nues_mass() const{
  if(!c_mc_nues_mass_ && b_mc_nues_mass_){
    b_mc_nues_mass_->GetEntry(entry_);
    c_mc_nues_mass_ = true;
  }
  return mc_nues_mass_;
}

std::vector<float>* const & cfa_8::mc_nues_mother_id() const{
  if(!c_mc_nues_mother_id_ && b_mc_nues_mother_id_){
    b_mc_nues_mother_id_->GetEntry(entry_);
    c_mc_nues_mother_id_ = true;
  }
  return mc_nues_mother_id_;
}

std::vector<float>* const & cfa_8::mc_nues_mother_pt() const{
  if(!c_mc_nues_mother_pt_ && b_mc_nues_mother_pt_){
    b_mc_nues_mother_pt_->GetEntry(entry_);
    c_mc_nues_mother_pt_ = true;
  }
  return mc_nues_mother_pt_;
}

std::vector<float>* const & cfa_8::mc_nues_numOfDaughters() const{
  if(!c_mc_nues_numOfDaughters_ && b_mc_nues_numOfDaughters_){
    b_mc_nues_numOfDaughters_->GetEntry(entry_);
    c_mc_nues_numOfDaughters_ = true;
  }
  return mc_nues_numOfDaughters_;
}

std::vector<float>* const & cfa_8::mc_nues_phi() const{
  if(!c_mc_nues_phi_ && b_mc_nues_phi_){
    b_mc_nues_phi_->GetEntry(entry_);
    c_mc_nues_phi_ = true;
  }
  return mc_nues_phi_;
}

std::vector<float>* const & cfa_8::mc_nues_pt() const{
  if(!c_mc_nues_pt_ && b_mc_nues_pt_){
    b_mc_nues_pt_->GetEntry(entry_);
    c_mc_nues_pt_ = true;
  }
  return mc_nues_pt_;
}

std::vector<float>* const & cfa_8::mc_nues_px() const{
  if(!c_mc_nues_px_ && b_mc_nues_px_){
    b_mc_nues_px_->GetEntry(entry_);
    c_mc_nues_px_ = true;
  }
  return mc_nues_px_;
}

std::vector<float>* const & cfa_8::mc_nues_py() const{
  if(!c_mc_nues_py_ && b_mc_nues_py_){
    b_mc_nues_py_->GetEntry(entry_);
    c_mc_nues_py_ = true;
  }
  return mc_nues_py_;
}

std::vector<float>* const & cfa_8::mc_nues_pz() const{
  if(!c_mc_nues_pz_ && b_mc_nues_pz_){
    b_mc_nues_pz_->GetEntry(entry_);
    c_mc_nues_pz_ = true;
  }
  return mc_nues_pz_;
}

std::vector<float>* const & cfa_8::mc_nues_status() const{
  if(!c_mc_nues_status_ && b_mc_nues_status_){
    b_mc_nues_status_->GetEntry(entry_);
    c_mc_nues_status_ = true;
  }
  return mc_nues_status_;
}

std::vector<float>* const & cfa_8::mc_nues_theta() const{
  if(!c_mc_nues_theta_ && b_mc_nues_theta_){
    b_mc_nues_theta_->GetEntry(entry_);
    c_mc_nues_theta_ = true;
  }
  return mc_nues_theta_;
}

std::vector<float>* const & cfa_8::mc_nues_vertex_x() const{
  if(!c_mc_nues_vertex_x_ && b_mc_nues_vertex_x_){
    b_mc_nues_vertex_x_->GetEntry(entry_);
    c_mc_nues_vertex_x_ = true;
  }
  return mc_nues_vertex_x_;
}

std::vector<float>* const & cfa_8::mc_nues_vertex_y() const{
  if(!c_mc_nues_vertex_y_ && b_mc_nues_vertex_y_){
    b_mc_nues_vertex_y_->GetEntry(entry_);
    c_mc_nues_vertex_y_ = true;
  }
  return mc_nues_vertex_y_;
}

std::vector<float>* const & cfa_8::mc_nues_vertex_z() const{
  if(!c_mc_nues_vertex_z_ && b_mc_nues_vertex_z_){
    b_mc_nues_vertex_z_->GetEntry(entry_);
    c_mc_nues_vertex_z_ = true;
  }
  return mc_nues_vertex_z_;
}

std::vector<float>* const & cfa_8::mc_numus_charge() const{
  if(!c_mc_numus_charge_ && b_mc_numus_charge_){
    b_mc_numus_charge_->GetEntry(entry_);
    c_mc_numus_charge_ = true;
  }
  return mc_numus_charge_;
}

std::vector<float>* const & cfa_8::mc_numus_energy() const{
  if(!c_mc_numus_energy_ && b_mc_numus_energy_){
    b_mc_numus_energy_->GetEntry(entry_);
    c_mc_numus_energy_ = true;
  }
  return mc_numus_energy_;
}

std::vector<float>* const & cfa_8::mc_numus_eta() const{
  if(!c_mc_numus_eta_ && b_mc_numus_eta_){
    b_mc_numus_eta_->GetEntry(entry_);
    c_mc_numus_eta_ = true;
  }
  return mc_numus_eta_;
}

std::vector<float>* const & cfa_8::mc_numus_ggrandmother_id() const{
  if(!c_mc_numus_ggrandmother_id_ && b_mc_numus_ggrandmother_id_){
    b_mc_numus_ggrandmother_id_->GetEntry(entry_);
    c_mc_numus_ggrandmother_id_ = true;
  }
  return mc_numus_ggrandmother_id_;
}

std::vector<float>* const & cfa_8::mc_numus_grandmother_id() const{
  if(!c_mc_numus_grandmother_id_ && b_mc_numus_grandmother_id_){
    b_mc_numus_grandmother_id_->GetEntry(entry_);
    c_mc_numus_grandmother_id_ = true;
  }
  return mc_numus_grandmother_id_;
}

std::vector<float>* const & cfa_8::mc_numus_id() const{
  if(!c_mc_numus_id_ && b_mc_numus_id_){
    b_mc_numus_id_->GetEntry(entry_);
    c_mc_numus_id_ = true;
  }
  return mc_numus_id_;
}

std::vector<float>* const & cfa_8::mc_numus_mass() const{
  if(!c_mc_numus_mass_ && b_mc_numus_mass_){
    b_mc_numus_mass_->GetEntry(entry_);
    c_mc_numus_mass_ = true;
  }
  return mc_numus_mass_;
}

std::vector<float>* const & cfa_8::mc_numus_mother_id() const{
  if(!c_mc_numus_mother_id_ && b_mc_numus_mother_id_){
    b_mc_numus_mother_id_->GetEntry(entry_);
    c_mc_numus_mother_id_ = true;
  }
  return mc_numus_mother_id_;
}

std::vector<float>* const & cfa_8::mc_numus_mother_pt() const{
  if(!c_mc_numus_mother_pt_ && b_mc_numus_mother_pt_){
    b_mc_numus_mother_pt_->GetEntry(entry_);
    c_mc_numus_mother_pt_ = true;
  }
  return mc_numus_mother_pt_;
}

std::vector<float>* const & cfa_8::mc_numus_numOfDaughters() const{
  if(!c_mc_numus_numOfDaughters_ && b_mc_numus_numOfDaughters_){
    b_mc_numus_numOfDaughters_->GetEntry(entry_);
    c_mc_numus_numOfDaughters_ = true;
  }
  return mc_numus_numOfDaughters_;
}

std::vector<float>* const & cfa_8::mc_numus_phi() const{
  if(!c_mc_numus_phi_ && b_mc_numus_phi_){
    b_mc_numus_phi_->GetEntry(entry_);
    c_mc_numus_phi_ = true;
  }
  return mc_numus_phi_;
}

std::vector<float>* const & cfa_8::mc_numus_pt() const{
  if(!c_mc_numus_pt_ && b_mc_numus_pt_){
    b_mc_numus_pt_->GetEntry(entry_);
    c_mc_numus_pt_ = true;
  }
  return mc_numus_pt_;
}

std::vector<float>* const & cfa_8::mc_numus_px() const{
  if(!c_mc_numus_px_ && b_mc_numus_px_){
    b_mc_numus_px_->GetEntry(entry_);
    c_mc_numus_px_ = true;
  }
  return mc_numus_px_;
}

std::vector<float>* const & cfa_8::mc_numus_py() const{
  if(!c_mc_numus_py_ && b_mc_numus_py_){
    b_mc_numus_py_->GetEntry(entry_);
    c_mc_numus_py_ = true;
  }
  return mc_numus_py_;
}

std::vector<float>* const & cfa_8::mc_numus_pz() const{
  if(!c_mc_numus_pz_ && b_mc_numus_pz_){
    b_mc_numus_pz_->GetEntry(entry_);
    c_mc_numus_pz_ = true;
  }
  return mc_numus_pz_;
}

std::vector<float>* const & cfa_8::mc_numus_status() const{
  if(!c_mc_numus_status_ && b_mc_numus_status_){
    b_mc_numus_status_->GetEntry(entry_);
    c_mc_numus_status_ = true;
  }
  return mc_numus_status_;
}

std::vector<float>* const & cfa_8::mc_numus_theta() const{
  if(!c_mc_numus_theta_ && b_mc_numus_theta_){
    b_mc_numus_theta_->GetEntry(entry_);
    c_mc_numus_theta_ = true;
  }
  return mc_numus_theta_;
}

std::vector<float>* const & cfa_8::mc_numus_vertex_x() const{
  if(!c_mc_numus_vertex_x_ && b_mc_numus_vertex_x_){
    b_mc_numus_vertex_x_->GetEntry(entry_);
    c_mc_numus_vertex_x_ = true;
  }
  return mc_numus_vertex_x_;
}

std::vector<float>* const & cfa_8::mc_numus_vertex_y() const{
  if(!c_mc_numus_vertex_y_ && b_mc_numus_vertex_y_){
    b_mc_numus_vertex_y_->GetEntry(entry_);
    c_mc_numus_vertex_y_ = true;
  }
  return mc_numus_vertex_y_;
}

std::vector<float>* const & cfa_8::mc_numus_vertex_z() const{
  if(!c_mc_numus_vertex_z_ && b_mc_numus_vertex_z_){
    b_mc_numus_vertex_z_->GetEntry(entry_);
    c_mc_numus_vertex_z_ = true;
  }
  return mc_numus_vertex_z_;
}

std::vector<float>* const & cfa_8::mc_nutaus_charge() const{
  if(!c_mc_nutaus_charge_ && b_mc_nutaus_charge_){
    b_mc_nutaus_charge_->GetEntry(entry_);
    c_mc_nutaus_charge_ = true;
  }
  return mc_nutaus_charge_;
}

std::vector<float>* const & cfa_8::mc_nutaus_energy() const{
  if(!c_mc_nutaus_energy_ && b_mc_nutaus_energy_){
    b_mc_nutaus_energy_->GetEntry(entry_);
    c_mc_nutaus_energy_ = true;
  }
  return mc_nutaus_energy_;
}

std::vector<float>* const & cfa_8::mc_nutaus_eta() const{
  if(!c_mc_nutaus_eta_ && b_mc_nutaus_eta_){
    b_mc_nutaus_eta_->GetEntry(entry_);
    c_mc_nutaus_eta_ = true;
  }
  return mc_nutaus_eta_;
}

std::vector<float>* const & cfa_8::mc_nutaus_ggrandmother_id() const{
  if(!c_mc_nutaus_ggrandmother_id_ && b_mc_nutaus_ggrandmother_id_){
    b_mc_nutaus_ggrandmother_id_->GetEntry(entry_);
    c_mc_nutaus_ggrandmother_id_ = true;
  }
  return mc_nutaus_ggrandmother_id_;
}

std::vector<float>* const & cfa_8::mc_nutaus_grandmother_id() const{
  if(!c_mc_nutaus_grandmother_id_ && b_mc_nutaus_grandmother_id_){
    b_mc_nutaus_grandmother_id_->GetEntry(entry_);
    c_mc_nutaus_grandmother_id_ = true;
  }
  return mc_nutaus_grandmother_id_;
}

std::vector<float>* const & cfa_8::mc_nutaus_id() const{
  if(!c_mc_nutaus_id_ && b_mc_nutaus_id_){
    b_mc_nutaus_id_->GetEntry(entry_);
    c_mc_nutaus_id_ = true;
  }
  return mc_nutaus_id_;
}

std::vector<float>* const & cfa_8::mc_nutaus_mass() const{
  if(!c_mc_nutaus_mass_ && b_mc_nutaus_mass_){
    b_mc_nutaus_mass_->GetEntry(entry_);
    c_mc_nutaus_mass_ = true;
  }
  return mc_nutaus_mass_;
}

std::vector<float>* const & cfa_8::mc_nutaus_mother_id() const{
  if(!c_mc_nutaus_mother_id_ && b_mc_nutaus_mother_id_){
    b_mc_nutaus_mother_id_->GetEntry(entry_);
    c_mc_nutaus_mother_id_ = true;
  }
  return mc_nutaus_mother_id_;
}

std::vector<float>* const & cfa_8::mc_nutaus_mother_pt() const{
  if(!c_mc_nutaus_mother_pt_ && b_mc_nutaus_mother_pt_){
    b_mc_nutaus_mother_pt_->GetEntry(entry_);
    c_mc_nutaus_mother_pt_ = true;
  }
  return mc_nutaus_mother_pt_;
}

std::vector<float>* const & cfa_8::mc_nutaus_numOfDaughters() const{
  if(!c_mc_nutaus_numOfDaughters_ && b_mc_nutaus_numOfDaughters_){
    b_mc_nutaus_numOfDaughters_->GetEntry(entry_);
    c_mc_nutaus_numOfDaughters_ = true;
  }
  return mc_nutaus_numOfDaughters_;
}

std::vector<float>* const & cfa_8::mc_nutaus_phi() const{
  if(!c_mc_nutaus_phi_ && b_mc_nutaus_phi_){
    b_mc_nutaus_phi_->GetEntry(entry_);
    c_mc_nutaus_phi_ = true;
  }
  return mc_nutaus_phi_;
}

std::vector<float>* const & cfa_8::mc_nutaus_pt() const{
  if(!c_mc_nutaus_pt_ && b_mc_nutaus_pt_){
    b_mc_nutaus_pt_->GetEntry(entry_);
    c_mc_nutaus_pt_ = true;
  }
  return mc_nutaus_pt_;
}

std::vector<float>* const & cfa_8::mc_nutaus_px() const{
  if(!c_mc_nutaus_px_ && b_mc_nutaus_px_){
    b_mc_nutaus_px_->GetEntry(entry_);
    c_mc_nutaus_px_ = true;
  }
  return mc_nutaus_px_;
}

std::vector<float>* const & cfa_8::mc_nutaus_py() const{
  if(!c_mc_nutaus_py_ && b_mc_nutaus_py_){
    b_mc_nutaus_py_->GetEntry(entry_);
    c_mc_nutaus_py_ = true;
  }
  return mc_nutaus_py_;
}

std::vector<float>* const & cfa_8::mc_nutaus_pz() const{
  if(!c_mc_nutaus_pz_ && b_mc_nutaus_pz_){
    b_mc_nutaus_pz_->GetEntry(entry_);
    c_mc_nutaus_pz_ = true;
  }
  return mc_nutaus_pz_;
}

std::vector<float>* const & cfa_8::mc_nutaus_status() const{
  if(!c_mc_nutaus_status_ && b_mc_nutaus_status_){
    b_mc_nutaus_status_->GetEntry(entry_);
    c_mc_nutaus_status_ = true;
  }
  return mc_nutaus_status_;
}

std::vector<float>* const & cfa_8::mc_nutaus_theta() const{
  if(!c_mc_nutaus_theta_ && b_mc_nutaus_theta_){
    b_mc_nutaus_theta_->GetEntry(entry_);
    c_mc_nutaus_theta_ = true;
  }
  return mc_nutaus_theta_;
}

std::vector<float>* const & cfa_8::mc_nutaus_vertex_x() const{
  if(!c_mc_nutaus_vertex_x_ && b_mc_nutaus_vertex_x_){
    b_mc_nutaus_vertex_x_->GetEntry(entry_);
    c_mc_nutaus_vertex_x_ = true;
  }
  return mc_nutaus_vertex_x_;
}

std::vector<float>* const & cfa_8::mc_nutaus_vertex_y() const{
  if(!c_mc_nutaus_vertex_y_ && b_mc_nutaus_vertex_y_){
    b_mc_nutaus_vertex_y_->GetEntry(entry_);
    c_mc_nutaus_vertex_y_ = true;
  }
  return mc_nutaus_vertex_y_;
}

std::vector<float>* const & cfa_8::mc_nutaus_vertex_z() const{
  if(!c_mc_nutaus_vertex_z_ && b_mc_nutaus_vertex_z_){
    b_mc_nutaus_vertex_z_->GetEntry(entry_);
    c_mc_nutaus_vertex_z_ = true;
  }
  return mc_nutaus_vertex_z_;
}

std::vector<float>* const & cfa_8::mc_pdf_id1() const{
  if(!c_mc_pdf_id1_ && b_mc_pdf_id1_){
    b_mc_pdf_id1_->GetEntry(entry_);
    c_mc_pdf_id1_ = true;
  }
  return mc_pdf_id1_;
}

std::vector<float>* const & cfa_8::mc_pdf_id2() const{
  if(!c_mc_pdf_id2_ && b_mc_pdf_id2_){
    b_mc_pdf_id2_->GetEntry(entry_);
    c_mc_pdf_id2_ = true;
  }
  return mc_pdf_id2_;
}

std::vector<float>* const & cfa_8::mc_pdf_q() const{
  if(!c_mc_pdf_q_ && b_mc_pdf_q_){
    b_mc_pdf_q_->GetEntry(entry_);
    c_mc_pdf_q_ = true;
  }
  return mc_pdf_q_;
}

std::vector<float>* const & cfa_8::mc_pdf_x1() const{
  if(!c_mc_pdf_x1_ && b_mc_pdf_x1_){
    b_mc_pdf_x1_->GetEntry(entry_);
    c_mc_pdf_x1_ = true;
  }
  return mc_pdf_x1_;
}

std::vector<float>* const & cfa_8::mc_pdf_x2() const{
  if(!c_mc_pdf_x2_ && b_mc_pdf_x2_){
    b_mc_pdf_x2_->GetEntry(entry_);
    c_mc_pdf_x2_ = true;
  }
  return mc_pdf_x2_;
}

std::vector<float>* const & cfa_8::mc_photons_charge() const{
  if(!c_mc_photons_charge_ && b_mc_photons_charge_){
    b_mc_photons_charge_->GetEntry(entry_);
    c_mc_photons_charge_ = true;
  }
  return mc_photons_charge_;
}

std::vector<float>* const & cfa_8::mc_photons_energy() const{
  if(!c_mc_photons_energy_ && b_mc_photons_energy_){
    b_mc_photons_energy_->GetEntry(entry_);
    c_mc_photons_energy_ = true;
  }
  return mc_photons_energy_;
}

std::vector<float>* const & cfa_8::mc_photons_eta() const{
  if(!c_mc_photons_eta_ && b_mc_photons_eta_){
    b_mc_photons_eta_->GetEntry(entry_);
    c_mc_photons_eta_ = true;
  }
  return mc_photons_eta_;
}

std::vector<float>* const & cfa_8::mc_photons_ggrandmother_id() const{
  if(!c_mc_photons_ggrandmother_id_ && b_mc_photons_ggrandmother_id_){
    b_mc_photons_ggrandmother_id_->GetEntry(entry_);
    c_mc_photons_ggrandmother_id_ = true;
  }
  return mc_photons_ggrandmother_id_;
}

std::vector<float>* const & cfa_8::mc_photons_grandmother_id() const{
  if(!c_mc_photons_grandmother_id_ && b_mc_photons_grandmother_id_){
    b_mc_photons_grandmother_id_->GetEntry(entry_);
    c_mc_photons_grandmother_id_ = true;
  }
  return mc_photons_grandmother_id_;
}

std::vector<float>* const & cfa_8::mc_photons_id() const{
  if(!c_mc_photons_id_ && b_mc_photons_id_){
    b_mc_photons_id_->GetEntry(entry_);
    c_mc_photons_id_ = true;
  }
  return mc_photons_id_;
}

std::vector<float>* const & cfa_8::mc_photons_mass() const{
  if(!c_mc_photons_mass_ && b_mc_photons_mass_){
    b_mc_photons_mass_->GetEntry(entry_);
    c_mc_photons_mass_ = true;
  }
  return mc_photons_mass_;
}

std::vector<float>* const & cfa_8::mc_photons_mother_id() const{
  if(!c_mc_photons_mother_id_ && b_mc_photons_mother_id_){
    b_mc_photons_mother_id_->GetEntry(entry_);
    c_mc_photons_mother_id_ = true;
  }
  return mc_photons_mother_id_;
}

std::vector<float>* const & cfa_8::mc_photons_mother_pt() const{
  if(!c_mc_photons_mother_pt_ && b_mc_photons_mother_pt_){
    b_mc_photons_mother_pt_->GetEntry(entry_);
    c_mc_photons_mother_pt_ = true;
  }
  return mc_photons_mother_pt_;
}

std::vector<float>* const & cfa_8::mc_photons_numOfDaughters() const{
  if(!c_mc_photons_numOfDaughters_ && b_mc_photons_numOfDaughters_){
    b_mc_photons_numOfDaughters_->GetEntry(entry_);
    c_mc_photons_numOfDaughters_ = true;
  }
  return mc_photons_numOfDaughters_;
}

std::vector<float>* const & cfa_8::mc_photons_phi() const{
  if(!c_mc_photons_phi_ && b_mc_photons_phi_){
    b_mc_photons_phi_->GetEntry(entry_);
    c_mc_photons_phi_ = true;
  }
  return mc_photons_phi_;
}

std::vector<float>* const & cfa_8::mc_photons_pt() const{
  if(!c_mc_photons_pt_ && b_mc_photons_pt_){
    b_mc_photons_pt_->GetEntry(entry_);
    c_mc_photons_pt_ = true;
  }
  return mc_photons_pt_;
}

std::vector<float>* const & cfa_8::mc_photons_px() const{
  if(!c_mc_photons_px_ && b_mc_photons_px_){
    b_mc_photons_px_->GetEntry(entry_);
    c_mc_photons_px_ = true;
  }
  return mc_photons_px_;
}

std::vector<float>* const & cfa_8::mc_photons_py() const{
  if(!c_mc_photons_py_ && b_mc_photons_py_){
    b_mc_photons_py_->GetEntry(entry_);
    c_mc_photons_py_ = true;
  }
  return mc_photons_py_;
}

std::vector<float>* const & cfa_8::mc_photons_pz() const{
  if(!c_mc_photons_pz_ && b_mc_photons_pz_){
    b_mc_photons_pz_->GetEntry(entry_);
    c_mc_photons_pz_ = true;
  }
  return mc_photons_pz_;
}

std::vector<float>* const & cfa_8::mc_photons_status() const{
  if(!c_mc_photons_status_ && b_mc_photons_status_){
    b_mc_photons_status_->GetEntry(entry_);
    c_mc_photons_status_ = true;
  }
  return mc_photons_status_;
}

std::vector<float>* const & cfa_8::mc_photons_theta() const{
  if(!c_mc_photons_theta_ && b_mc_photons_theta_){
    b_mc_photons_theta_->GetEntry(entry_);
    c_mc_photons_theta_ = true;
  }
  return mc_photons_theta_;
}

std::vector<float>* const & cfa_8::mc_photons_vertex_x() const{
  if(!c_mc_photons_vertex_x_ && b_mc_photons_vertex_x_){
    b_mc_photons_vertex_x_->GetEntry(entry_);
    c_mc_photons_vertex_x_ = true;
  }
  return mc_photons_vertex_x_;
}

std::vector<float>* const & cfa_8::mc_photons_vertex_y() const{
  if(!c_mc_photons_vertex_y_ && b_mc_photons_vertex_y_){
    b_mc_photons_vertex_y_->GetEntry(entry_);
    c_mc_photons_vertex_y_ = true;
  }
  return mc_photons_vertex_y_;
}

std::vector<float>* const & cfa_8::mc_photons_vertex_z() const{
  if(!c_mc_photons_vertex_z_ && b_mc_photons_vertex_z_){
    b_mc_photons_vertex_z_->GetEntry(entry_);
    c_mc_photons_vertex_z_ = true;
  }
  return mc_photons_vertex_z_;
}

std::vector<float>* const & cfa_8::mc_taus_charge() const{
  if(!c_mc_taus_charge_ && b_mc_taus_charge_){
    b_mc_taus_charge_->GetEntry(entry_);
    c_mc_taus_charge_ = true;
  }
  return mc_taus_charge_;
}

std::vector<float>* const & cfa_8::mc_taus_energy() const{
  if(!c_mc_taus_energy_ && b_mc_taus_energy_){
    b_mc_taus_energy_->GetEntry(entry_);
    c_mc_taus_energy_ = true;
  }
  return mc_taus_energy_;
}

std::vector<float>* const & cfa_8::mc_taus_eta() const{
  if(!c_mc_taus_eta_ && b_mc_taus_eta_){
    b_mc_taus_eta_->GetEntry(entry_);
    c_mc_taus_eta_ = true;
  }
  return mc_taus_eta_;
}

std::vector<float>* const & cfa_8::mc_taus_ggrandmother_id() const{
  if(!c_mc_taus_ggrandmother_id_ && b_mc_taus_ggrandmother_id_){
    b_mc_taus_ggrandmother_id_->GetEntry(entry_);
    c_mc_taus_ggrandmother_id_ = true;
  }
  return mc_taus_ggrandmother_id_;
}

std::vector<float>* const & cfa_8::mc_taus_grandmother_id() const{
  if(!c_mc_taus_grandmother_id_ && b_mc_taus_grandmother_id_){
    b_mc_taus_grandmother_id_->GetEntry(entry_);
    c_mc_taus_grandmother_id_ = true;
  }
  return mc_taus_grandmother_id_;
}

std::vector<float>* const & cfa_8::mc_taus_id() const{
  if(!c_mc_taus_id_ && b_mc_taus_id_){
    b_mc_taus_id_->GetEntry(entry_);
    c_mc_taus_id_ = true;
  }
  return mc_taus_id_;
}

std::vector<float>* const & cfa_8::mc_taus_mass() const{
  if(!c_mc_taus_mass_ && b_mc_taus_mass_){
    b_mc_taus_mass_->GetEntry(entry_);
    c_mc_taus_mass_ = true;
  }
  return mc_taus_mass_;
}

std::vector<float>* const & cfa_8::mc_taus_mother_id() const{
  if(!c_mc_taus_mother_id_ && b_mc_taus_mother_id_){
    b_mc_taus_mother_id_->GetEntry(entry_);
    c_mc_taus_mother_id_ = true;
  }
  return mc_taus_mother_id_;
}

std::vector<float>* const & cfa_8::mc_taus_mother_pt() const{
  if(!c_mc_taus_mother_pt_ && b_mc_taus_mother_pt_){
    b_mc_taus_mother_pt_->GetEntry(entry_);
    c_mc_taus_mother_pt_ = true;
  }
  return mc_taus_mother_pt_;
}

std::vector<float>* const & cfa_8::mc_taus_numOfDaughters() const{
  if(!c_mc_taus_numOfDaughters_ && b_mc_taus_numOfDaughters_){
    b_mc_taus_numOfDaughters_->GetEntry(entry_);
    c_mc_taus_numOfDaughters_ = true;
  }
  return mc_taus_numOfDaughters_;
}

std::vector<float>* const & cfa_8::mc_taus_phi() const{
  if(!c_mc_taus_phi_ && b_mc_taus_phi_){
    b_mc_taus_phi_->GetEntry(entry_);
    c_mc_taus_phi_ = true;
  }
  return mc_taus_phi_;
}

std::vector<float>* const & cfa_8::mc_taus_pt() const{
  if(!c_mc_taus_pt_ && b_mc_taus_pt_){
    b_mc_taus_pt_->GetEntry(entry_);
    c_mc_taus_pt_ = true;
  }
  return mc_taus_pt_;
}

std::vector<float>* const & cfa_8::mc_taus_px() const{
  if(!c_mc_taus_px_ && b_mc_taus_px_){
    b_mc_taus_px_->GetEntry(entry_);
    c_mc_taus_px_ = true;
  }
  return mc_taus_px_;
}

std::vector<float>* const & cfa_8::mc_taus_py() const{
  if(!c_mc_taus_py_ && b_mc_taus_py_){
    b_mc_taus_py_->GetEntry(entry_);
    c_mc_taus_py_ = true;
  }
  return mc_taus_py_;
}

std::vector<float>* const & cfa_8::mc_taus_pz() const{
  if(!c_mc_taus_pz_ && b_mc_taus_pz_){
    b_mc_taus_pz_->GetEntry(entry_);
    c_mc_taus_pz_ = true;
  }
  return mc_taus_pz_;
}

std::vector<float>* const & cfa_8::mc_taus_status() const{
  if(!c_mc_taus_status_ && b_mc_taus_status_){
    b_mc_taus_status_->GetEntry(entry_);
    c_mc_taus_status_ = true;
  }
  return mc_taus_status_;
}

std::vector<float>* const & cfa_8::mc_taus_theta() const{
  if(!c_mc_taus_theta_ && b_mc_taus_theta_){
    b_mc_taus_theta_->GetEntry(entry_);
    c_mc_taus_theta_ = true;
  }
  return mc_taus_theta_;
}

std::vector<float>* const & cfa_8::mc_taus_vertex_x() const{
  if(!c_mc_taus_vertex_x_ && b_mc_taus_vertex_x_){
    b_mc_taus_vertex_x_->GetEntry(entry_);
    c_mc_taus_vertex_x_ = true;
  }
  return mc_taus_vertex_x_;
}

std::vector<float>* const & cfa_8::mc_taus_vertex_y() const{
  if(!c_mc_taus_vertex_y_ && b_mc_taus_vertex_y_){
    b_mc_taus_vertex_y_->GetEntry(entry_);
    c_mc_taus_vertex_y_ = true;
  }
  return mc_taus_vertex_y_;
}

std::vector<float>* const & cfa_8::mc_taus_vertex_z() const{
  if(!c_mc_taus_vertex_z_ && b_mc_taus_vertex_z_){
    b_mc_taus_vertex_z_->GetEntry(entry_);
    c_mc_taus_vertex_z_ = true;
  }
  return mc_taus_vertex_z_;
}

std::vector<float>* const & cfa_8::metsHO_et() const{
  if(!c_metsHO_et_ && b_metsHO_et_){
    b_metsHO_et_->GetEntry(entry_);
    c_metsHO_et_ = true;
  }
  return metsHO_et_;
}

std::vector<float>* const & cfa_8::metsHO_ex() const{
  if(!c_metsHO_ex_ && b_metsHO_ex_){
    b_metsHO_ex_->GetEntry(entry_);
    c_metsHO_ex_ = true;
  }
  return metsHO_ex_;
}

std::vector<float>* const & cfa_8::metsHO_ey() const{
  if(!c_metsHO_ey_ && b_metsHO_ey_){
    b_metsHO_ey_->GetEntry(entry_);
    c_metsHO_ey_ = true;
  }
  return metsHO_ey_;
}

std::vector<float>* const & cfa_8::metsHO_phi() const{
  if(!c_metsHO_phi_ && b_metsHO_phi_){
    b_metsHO_phi_->GetEntry(entry_);
    c_metsHO_phi_ = true;
  }
  return metsHO_phi_;
}

std::vector<float>* const & cfa_8::metsHO_sumEt() const{
  if(!c_metsHO_sumEt_ && b_metsHO_sumEt_){
    b_metsHO_sumEt_->GetEntry(entry_);
    c_metsHO_sumEt_ = true;
  }
  return metsHO_sumEt_;
}

std::vector<float>* const & cfa_8::mets_AK5_et() const{
  if(!c_mets_AK5_et_ && b_mets_AK5_et_){
    b_mets_AK5_et_->GetEntry(entry_);
    c_mets_AK5_et_ = true;
  }
  return mets_AK5_et_;
}

std::vector<float>* const & cfa_8::mets_AK5_ex() const{
  if(!c_mets_AK5_ex_ && b_mets_AK5_ex_){
    b_mets_AK5_ex_->GetEntry(entry_);
    c_mets_AK5_ex_ = true;
  }
  return mets_AK5_ex_;
}

std::vector<float>* const & cfa_8::mets_AK5_ey() const{
  if(!c_mets_AK5_ey_ && b_mets_AK5_ey_){
    b_mets_AK5_ey_->GetEntry(entry_);
    c_mets_AK5_ey_ = true;
  }
  return mets_AK5_ey_;
}

std::vector<float>* const & cfa_8::mets_AK5_gen_et() const{
  if(!c_mets_AK5_gen_et_ && b_mets_AK5_gen_et_){
    b_mets_AK5_gen_et_->GetEntry(entry_);
    c_mets_AK5_gen_et_ = true;
  }
  return mets_AK5_gen_et_;
}

std::vector<float>* const & cfa_8::mets_AK5_gen_phi() const{
  if(!c_mets_AK5_gen_phi_ && b_mets_AK5_gen_phi_){
    b_mets_AK5_gen_phi_->GetEntry(entry_);
    c_mets_AK5_gen_phi_ = true;
  }
  return mets_AK5_gen_phi_;
}

std::vector<float>* const & cfa_8::mets_AK5_phi() const{
  if(!c_mets_AK5_phi_ && b_mets_AK5_phi_){
    b_mets_AK5_phi_->GetEntry(entry_);
    c_mets_AK5_phi_ = true;
  }
  return mets_AK5_phi_;
}

std::vector<float>* const & cfa_8::mets_AK5_sign() const{
  if(!c_mets_AK5_sign_ && b_mets_AK5_sign_){
    b_mets_AK5_sign_->GetEntry(entry_);
    c_mets_AK5_sign_ = true;
  }
  return mets_AK5_sign_;
}

std::vector<float>* const & cfa_8::mets_AK5_sumEt() const{
  if(!c_mets_AK5_sumEt_ && b_mets_AK5_sumEt_){
    b_mets_AK5_sumEt_->GetEntry(entry_);
    c_mets_AK5_sumEt_ = true;
  }
  return mets_AK5_sumEt_;
}

std::vector<float>* const & cfa_8::mets_AK5_unCPhi() const{
  if(!c_mets_AK5_unCPhi_ && b_mets_AK5_unCPhi_){
    b_mets_AK5_unCPhi_->GetEntry(entry_);
    c_mets_AK5_unCPhi_ = true;
  }
  return mets_AK5_unCPhi_;
}

std::vector<float>* const & cfa_8::mets_AK5_unCPt() const{
  if(!c_mets_AK5_unCPt_ && b_mets_AK5_unCPt_){
    b_mets_AK5_unCPt_->GetEntry(entry_);
    c_mets_AK5_unCPt_ = true;
  }
  return mets_AK5_unCPt_;
}

std::string* const & cfa_8::model_params() const{
  if(!c_model_params_ && b_model_params_){
    b_model_params_->GetEntry(entry_);
    c_model_params_ = true;
  }
  return model_params_;
}

std::vector<float>* const & cfa_8::mus_cIso() const{
  if(!c_mus_cIso_ && b_mus_cIso_){
    b_mus_cIso_->GetEntry(entry_);
    c_mus_cIso_ = true;
  }
  return mus_cIso_;
}

std::vector<float>* const & cfa_8::mus_calEnergyEm() const{
  if(!c_mus_calEnergyEm_ && b_mus_calEnergyEm_){
    b_mus_calEnergyEm_->GetEntry(entry_);
    c_mus_calEnergyEm_ = true;
  }
  return mus_calEnergyEm_;
}

std::vector<float>* const & cfa_8::mus_calEnergyEmS9() const{
  if(!c_mus_calEnergyEmS9_ && b_mus_calEnergyEmS9_){
    b_mus_calEnergyEmS9_->GetEntry(entry_);
    c_mus_calEnergyEmS9_ = true;
  }
  return mus_calEnergyEmS9_;
}

std::vector<float>* const & cfa_8::mus_calEnergyHad() const{
  if(!c_mus_calEnergyHad_ && b_mus_calEnergyHad_){
    b_mus_calEnergyHad_->GetEntry(entry_);
    c_mus_calEnergyHad_ = true;
  }
  return mus_calEnergyHad_;
}

std::vector<float>* const & cfa_8::mus_calEnergyHadS9() const{
  if(!c_mus_calEnergyHadS9_ && b_mus_calEnergyHadS9_){
    b_mus_calEnergyHadS9_->GetEntry(entry_);
    c_mus_calEnergyHadS9_ = true;
  }
  return mus_calEnergyHadS9_;
}

std::vector<float>* const & cfa_8::mus_calEnergyHo() const{
  if(!c_mus_calEnergyHo_ && b_mus_calEnergyHo_){
    b_mus_calEnergyHo_->GetEntry(entry_);
    c_mus_calEnergyHo_ = true;
  }
  return mus_calEnergyHo_;
}

std::vector<float>* const & cfa_8::mus_calEnergyHoS9() const{
  if(!c_mus_calEnergyHoS9_ && b_mus_calEnergyHoS9_){
    b_mus_calEnergyHoS9_->GetEntry(entry_);
    c_mus_calEnergyHoS9_ = true;
  }
  return mus_calEnergyHoS9_;
}

std::vector<float>* const & cfa_8::mus_charge() const{
  if(!c_mus_charge_ && b_mus_charge_){
    b_mus_charge_->GetEntry(entry_);
    c_mus_charge_ = true;
  }
  return mus_charge_;
}

std::vector<float>* const & cfa_8::mus_cm_ExpectedHitsInner() const{
  if(!c_mus_cm_ExpectedHitsInner_ && b_mus_cm_ExpectedHitsInner_){
    b_mus_cm_ExpectedHitsInner_->GetEntry(entry_);
    c_mus_cm_ExpectedHitsInner_ = true;
  }
  return mus_cm_ExpectedHitsInner_;
}

std::vector<float>* const & cfa_8::mus_cm_ExpectedHitsOuter() const{
  if(!c_mus_cm_ExpectedHitsOuter_ && b_mus_cm_ExpectedHitsOuter_){
    b_mus_cm_ExpectedHitsOuter_->GetEntry(entry_);
    c_mus_cm_ExpectedHitsOuter_ = true;
  }
  return mus_cm_ExpectedHitsOuter_;
}

std::vector<float>* const & cfa_8::mus_cm_LayersWithMeasurement() const{
  if(!c_mus_cm_LayersWithMeasurement_ && b_mus_cm_LayersWithMeasurement_){
    b_mus_cm_LayersWithMeasurement_->GetEntry(entry_);
    c_mus_cm_LayersWithMeasurement_ = true;
  }
  return mus_cm_LayersWithMeasurement_;
}

std::vector<float>* const & cfa_8::mus_cm_LayersWithoutMeasurement() const{
  if(!c_mus_cm_LayersWithoutMeasurement_ && b_mus_cm_LayersWithoutMeasurement_){
    b_mus_cm_LayersWithoutMeasurement_->GetEntry(entry_);
    c_mus_cm_LayersWithoutMeasurement_ = true;
  }
  return mus_cm_LayersWithoutMeasurement_;
}

std::vector<float>* const & cfa_8::mus_cm_PixelLayersWithMeasurement() const{
  if(!c_mus_cm_PixelLayersWithMeasurement_ && b_mus_cm_PixelLayersWithMeasurement_){
    b_mus_cm_PixelLayersWithMeasurement_->GetEntry(entry_);
    c_mus_cm_PixelLayersWithMeasurement_ = true;
  }
  return mus_cm_PixelLayersWithMeasurement_;
}

std::vector<float>* const & cfa_8::mus_cm_ValidStripLayersWithMonoAndStereoHit() const{
  if(!c_mus_cm_ValidStripLayersWithMonoAndStereoHit_ && b_mus_cm_ValidStripLayersWithMonoAndStereoHit_){
    b_mus_cm_ValidStripLayersWithMonoAndStereoHit_->GetEntry(entry_);
    c_mus_cm_ValidStripLayersWithMonoAndStereoHit_ = true;
  }
  return mus_cm_ValidStripLayersWithMonoAndStereoHit_;
}

std::vector<float>* const & cfa_8::mus_cm_chg() const{
  if(!c_mus_cm_chg_ && b_mus_cm_chg_){
    b_mus_cm_chg_->GetEntry(entry_);
    c_mus_cm_chg_ = true;
  }
  return mus_cm_chg_;
}

std::vector<float>* const & cfa_8::mus_cm_chi2() const{
  if(!c_mus_cm_chi2_ && b_mus_cm_chi2_){
    b_mus_cm_chi2_->GetEntry(entry_);
    c_mus_cm_chi2_ = true;
  }
  return mus_cm_chi2_;
}

std::vector<float>* const & cfa_8::mus_cm_d0dum() const{
  if(!c_mus_cm_d0dum_ && b_mus_cm_d0dum_){
    b_mus_cm_d0dum_->GetEntry(entry_);
    c_mus_cm_d0dum_ = true;
  }
  return mus_cm_d0dum_;
}

std::vector<float>* const & cfa_8::mus_cm_d0dumErr() const{
  if(!c_mus_cm_d0dumErr_ && b_mus_cm_d0dumErr_){
    b_mus_cm_d0dumErr_->GetEntry(entry_);
    c_mus_cm_d0dumErr_ = true;
  }
  return mus_cm_d0dumErr_;
}

std::vector<float>* const & cfa_8::mus_cm_dz() const{
  if(!c_mus_cm_dz_ && b_mus_cm_dz_){
    b_mus_cm_dz_->GetEntry(entry_);
    c_mus_cm_dz_ = true;
  }
  return mus_cm_dz_;
}

std::vector<float>* const & cfa_8::mus_cm_dzErr() const{
  if(!c_mus_cm_dzErr_ && b_mus_cm_dzErr_){
    b_mus_cm_dzErr_->GetEntry(entry_);
    c_mus_cm_dzErr_ = true;
  }
  return mus_cm_dzErr_;
}

std::vector<float>* const & cfa_8::mus_cm_eta() const{
  if(!c_mus_cm_eta_ && b_mus_cm_eta_){
    b_mus_cm_eta_->GetEntry(entry_);
    c_mus_cm_eta_ = true;
  }
  return mus_cm_eta_;
}

std::vector<float>* const & cfa_8::mus_cm_etaErr() const{
  if(!c_mus_cm_etaErr_ && b_mus_cm_etaErr_){
    b_mus_cm_etaErr_->GetEntry(entry_);
    c_mus_cm_etaErr_ = true;
  }
  return mus_cm_etaErr_;
}

std::vector<float>* const & cfa_8::mus_cm_ndof() const{
  if(!c_mus_cm_ndof_ && b_mus_cm_ndof_){
    b_mus_cm_ndof_->GetEntry(entry_);
    c_mus_cm_ndof_ = true;
  }
  return mus_cm_ndof_;
}

std::vector<float>* const & cfa_8::mus_cm_numlosthits() const{
  if(!c_mus_cm_numlosthits_ && b_mus_cm_numlosthits_){
    b_mus_cm_numlosthits_->GetEntry(entry_);
    c_mus_cm_numlosthits_ = true;
  }
  return mus_cm_numlosthits_;
}

std::vector<float>* const & cfa_8::mus_cm_numvalMuonhits() const{
  if(!c_mus_cm_numvalMuonhits_ && b_mus_cm_numvalMuonhits_){
    b_mus_cm_numvalMuonhits_->GetEntry(entry_);
    c_mus_cm_numvalMuonhits_ = true;
  }
  return mus_cm_numvalMuonhits_;
}

std::vector<float>* const & cfa_8::mus_cm_numvalhits() const{
  if(!c_mus_cm_numvalhits_ && b_mus_cm_numvalhits_){
    b_mus_cm_numvalhits_->GetEntry(entry_);
    c_mus_cm_numvalhits_ = true;
  }
  return mus_cm_numvalhits_;
}

std::vector<float>* const & cfa_8::mus_cm_phi() const{
  if(!c_mus_cm_phi_ && b_mus_cm_phi_){
    b_mus_cm_phi_->GetEntry(entry_);
    c_mus_cm_phi_ = true;
  }
  return mus_cm_phi_;
}

std::vector<float>* const & cfa_8::mus_cm_phiErr() const{
  if(!c_mus_cm_phiErr_ && b_mus_cm_phiErr_){
    b_mus_cm_phiErr_->GetEntry(entry_);
    c_mus_cm_phiErr_ = true;
  }
  return mus_cm_phiErr_;
}

std::vector<float>* const & cfa_8::mus_cm_pt() const{
  if(!c_mus_cm_pt_ && b_mus_cm_pt_){
    b_mus_cm_pt_->GetEntry(entry_);
    c_mus_cm_pt_ = true;
  }
  return mus_cm_pt_;
}

std::vector<float>* const & cfa_8::mus_cm_ptErr() const{
  if(!c_mus_cm_ptErr_ && b_mus_cm_ptErr_){
    b_mus_cm_ptErr_->GetEntry(entry_);
    c_mus_cm_ptErr_ = true;
  }
  return mus_cm_ptErr_;
}

std::vector<float>* const & cfa_8::mus_cm_px() const{
  if(!c_mus_cm_px_ && b_mus_cm_px_){
    b_mus_cm_px_->GetEntry(entry_);
    c_mus_cm_px_ = true;
  }
  return mus_cm_px_;
}

std::vector<float>* const & cfa_8::mus_cm_py() const{
  if(!c_mus_cm_py_ && b_mus_cm_py_){
    b_mus_cm_py_->GetEntry(entry_);
    c_mus_cm_py_ = true;
  }
  return mus_cm_py_;
}

std::vector<float>* const & cfa_8::mus_cm_pz() const{
  if(!c_mus_cm_pz_ && b_mus_cm_pz_){
    b_mus_cm_pz_->GetEntry(entry_);
    c_mus_cm_pz_ = true;
  }
  return mus_cm_pz_;
}

std::vector<float>* const & cfa_8::mus_cm_theta() const{
  if(!c_mus_cm_theta_ && b_mus_cm_theta_){
    b_mus_cm_theta_->GetEntry(entry_);
    c_mus_cm_theta_ = true;
  }
  return mus_cm_theta_;
}

std::vector<float>* const & cfa_8::mus_cm_vx() const{
  if(!c_mus_cm_vx_ && b_mus_cm_vx_){
    b_mus_cm_vx_->GetEntry(entry_);
    c_mus_cm_vx_ = true;
  }
  return mus_cm_vx_;
}

std::vector<float>* const & cfa_8::mus_cm_vy() const{
  if(!c_mus_cm_vy_ && b_mus_cm_vy_){
    b_mus_cm_vy_->GetEntry(entry_);
    c_mus_cm_vy_ = true;
  }
  return mus_cm_vy_;
}

std::vector<float>* const & cfa_8::mus_cm_vz() const{
  if(!c_mus_cm_vz_ && b_mus_cm_vz_){
    b_mus_cm_vz_->GetEntry(entry_);
    c_mus_cm_vz_ = true;
  }
  return mus_cm_vz_;
}

std::vector<float>* const & cfa_8::mus_dB() const{
  if(!c_mus_dB_ && b_mus_dB_){
    b_mus_dB_->GetEntry(entry_);
    c_mus_dB_ = true;
  }
  return mus_dB_;
}

std::vector<float>* const & cfa_8::mus_ecalIso() const{
  if(!c_mus_ecalIso_ && b_mus_ecalIso_){
    b_mus_ecalIso_->GetEntry(entry_);
    c_mus_ecalIso_ = true;
  }
  return mus_ecalIso_;
}

std::vector<float>* const & cfa_8::mus_ecalvetoDep() const{
  if(!c_mus_ecalvetoDep_ && b_mus_ecalvetoDep_){
    b_mus_ecalvetoDep_->GetEntry(entry_);
    c_mus_ecalvetoDep_ = true;
  }
  return mus_ecalvetoDep_;
}

std::vector<float>* const & cfa_8::mus_energy() const{
  if(!c_mus_energy_ && b_mus_energy_){
    b_mus_energy_->GetEntry(entry_);
    c_mus_energy_ = true;
  }
  return mus_energy_;
}

std::vector<float>* const & cfa_8::mus_et() const{
  if(!c_mus_et_ && b_mus_et_){
    b_mus_et_->GetEntry(entry_);
    c_mus_et_ = true;
  }
  return mus_et_;
}

std::vector<float>* const & cfa_8::mus_eta() const{
  if(!c_mus_eta_ && b_mus_eta_){
    b_mus_eta_->GetEntry(entry_);
    c_mus_eta_ = true;
  }
  return mus_eta_;
}

std::vector<float>* const & cfa_8::mus_gen_et() const{
  if(!c_mus_gen_et_ && b_mus_gen_et_){
    b_mus_gen_et_->GetEntry(entry_);
    c_mus_gen_et_ = true;
  }
  return mus_gen_et_;
}

std::vector<float>* const & cfa_8::mus_gen_eta() const{
  if(!c_mus_gen_eta_ && b_mus_gen_eta_){
    b_mus_gen_eta_->GetEntry(entry_);
    c_mus_gen_eta_ = true;
  }
  return mus_gen_eta_;
}

std::vector<float>* const & cfa_8::mus_gen_id() const{
  if(!c_mus_gen_id_ && b_mus_gen_id_){
    b_mus_gen_id_->GetEntry(entry_);
    c_mus_gen_id_ = true;
  }
  return mus_gen_id_;
}

std::vector<float>* const & cfa_8::mus_gen_mother_et() const{
  if(!c_mus_gen_mother_et_ && b_mus_gen_mother_et_){
    b_mus_gen_mother_et_->GetEntry(entry_);
    c_mus_gen_mother_et_ = true;
  }
  return mus_gen_mother_et_;
}

std::vector<float>* const & cfa_8::mus_gen_mother_eta() const{
  if(!c_mus_gen_mother_eta_ && b_mus_gen_mother_eta_){
    b_mus_gen_mother_eta_->GetEntry(entry_);
    c_mus_gen_mother_eta_ = true;
  }
  return mus_gen_mother_eta_;
}

std::vector<float>* const & cfa_8::mus_gen_mother_id() const{
  if(!c_mus_gen_mother_id_ && b_mus_gen_mother_id_){
    b_mus_gen_mother_id_->GetEntry(entry_);
    c_mus_gen_mother_id_ = true;
  }
  return mus_gen_mother_id_;
}

std::vector<float>* const & cfa_8::mus_gen_mother_phi() const{
  if(!c_mus_gen_mother_phi_ && b_mus_gen_mother_phi_){
    b_mus_gen_mother_phi_->GetEntry(entry_);
    c_mus_gen_mother_phi_ = true;
  }
  return mus_gen_mother_phi_;
}

std::vector<float>* const & cfa_8::mus_gen_mother_pt() const{
  if(!c_mus_gen_mother_pt_ && b_mus_gen_mother_pt_){
    b_mus_gen_mother_pt_->GetEntry(entry_);
    c_mus_gen_mother_pt_ = true;
  }
  return mus_gen_mother_pt_;
}

std::vector<float>* const & cfa_8::mus_gen_mother_px() const{
  if(!c_mus_gen_mother_px_ && b_mus_gen_mother_px_){
    b_mus_gen_mother_px_->GetEntry(entry_);
    c_mus_gen_mother_px_ = true;
  }
  return mus_gen_mother_px_;
}

std::vector<float>* const & cfa_8::mus_gen_mother_py() const{
  if(!c_mus_gen_mother_py_ && b_mus_gen_mother_py_){
    b_mus_gen_mother_py_->GetEntry(entry_);
    c_mus_gen_mother_py_ = true;
  }
  return mus_gen_mother_py_;
}

std::vector<float>* const & cfa_8::mus_gen_mother_pz() const{
  if(!c_mus_gen_mother_pz_ && b_mus_gen_mother_pz_){
    b_mus_gen_mother_pz_->GetEntry(entry_);
    c_mus_gen_mother_pz_ = true;
  }
  return mus_gen_mother_pz_;
}

std::vector<float>* const & cfa_8::mus_gen_mother_theta() const{
  if(!c_mus_gen_mother_theta_ && b_mus_gen_mother_theta_){
    b_mus_gen_mother_theta_->GetEntry(entry_);
    c_mus_gen_mother_theta_ = true;
  }
  return mus_gen_mother_theta_;
}

std::vector<float>* const & cfa_8::mus_gen_phi() const{
  if(!c_mus_gen_phi_ && b_mus_gen_phi_){
    b_mus_gen_phi_->GetEntry(entry_);
    c_mus_gen_phi_ = true;
  }
  return mus_gen_phi_;
}

std::vector<float>* const & cfa_8::mus_gen_pt() const{
  if(!c_mus_gen_pt_ && b_mus_gen_pt_){
    b_mus_gen_pt_->GetEntry(entry_);
    c_mus_gen_pt_ = true;
  }
  return mus_gen_pt_;
}

std::vector<float>* const & cfa_8::mus_gen_px() const{
  if(!c_mus_gen_px_ && b_mus_gen_px_){
    b_mus_gen_px_->GetEntry(entry_);
    c_mus_gen_px_ = true;
  }
  return mus_gen_px_;
}

std::vector<float>* const & cfa_8::mus_gen_py() const{
  if(!c_mus_gen_py_ && b_mus_gen_py_){
    b_mus_gen_py_->GetEntry(entry_);
    c_mus_gen_py_ = true;
  }
  return mus_gen_py_;
}

std::vector<float>* const & cfa_8::mus_gen_pz() const{
  if(!c_mus_gen_pz_ && b_mus_gen_pz_){
    b_mus_gen_pz_->GetEntry(entry_);
    c_mus_gen_pz_ = true;
  }
  return mus_gen_pz_;
}

std::vector<float>* const & cfa_8::mus_gen_theta() const{
  if(!c_mus_gen_theta_ && b_mus_gen_theta_){
    b_mus_gen_theta_->GetEntry(entry_);
    c_mus_gen_theta_ = true;
  }
  return mus_gen_theta_;
}

std::vector<float>* const & cfa_8::mus_hcalIso() const{
  if(!c_mus_hcalIso_ && b_mus_hcalIso_){
    b_mus_hcalIso_->GetEntry(entry_);
    c_mus_hcalIso_ = true;
  }
  return mus_hcalIso_;
}

std::vector<float>* const & cfa_8::mus_hcalvetoDep() const{
  if(!c_mus_hcalvetoDep_ && b_mus_hcalvetoDep_){
    b_mus_hcalvetoDep_->GetEntry(entry_);
    c_mus_hcalvetoDep_ = true;
  }
  return mus_hcalvetoDep_;
}

std::vector<float>* const & cfa_8::mus_id_All() const{
  if(!c_mus_id_All_ && b_mus_id_All_){
    b_mus_id_All_->GetEntry(entry_);
    c_mus_id_All_ = true;
  }
  return mus_id_All_;
}

std::vector<float>* const & cfa_8::mus_id_AllArbitrated() const{
  if(!c_mus_id_AllArbitrated_ && b_mus_id_AllArbitrated_){
    b_mus_id_AllArbitrated_->GetEntry(entry_);
    c_mus_id_AllArbitrated_ = true;
  }
  return mus_id_AllArbitrated_;
}

std::vector<float>* const & cfa_8::mus_id_AllGlobalMuons() const{
  if(!c_mus_id_AllGlobalMuons_ && b_mus_id_AllGlobalMuons_){
    b_mus_id_AllGlobalMuons_->GetEntry(entry_);
    c_mus_id_AllGlobalMuons_ = true;
  }
  return mus_id_AllGlobalMuons_;
}

std::vector<float>* const & cfa_8::mus_id_AllStandAloneMuons() const{
  if(!c_mus_id_AllStandAloneMuons_ && b_mus_id_AllStandAloneMuons_){
    b_mus_id_AllStandAloneMuons_->GetEntry(entry_);
    c_mus_id_AllStandAloneMuons_ = true;
  }
  return mus_id_AllStandAloneMuons_;
}

std::vector<float>* const & cfa_8::mus_id_AllTrackerMuons() const{
  if(!c_mus_id_AllTrackerMuons_ && b_mus_id_AllTrackerMuons_){
    b_mus_id_AllTrackerMuons_->GetEntry(entry_);
    c_mus_id_AllTrackerMuons_ = true;
  }
  return mus_id_AllTrackerMuons_;
}

std::vector<float>* const & cfa_8::mus_id_GlobalMuonPromptTight() const{
  if(!c_mus_id_GlobalMuonPromptTight_ && b_mus_id_GlobalMuonPromptTight_){
    b_mus_id_GlobalMuonPromptTight_->GetEntry(entry_);
    c_mus_id_GlobalMuonPromptTight_ = true;
  }
  return mus_id_GlobalMuonPromptTight_;
}

std::vector<float>* const & cfa_8::mus_id_TM2DCompatibilityLoose() const{
  if(!c_mus_id_TM2DCompatibilityLoose_ && b_mus_id_TM2DCompatibilityLoose_){
    b_mus_id_TM2DCompatibilityLoose_->GetEntry(entry_);
    c_mus_id_TM2DCompatibilityLoose_ = true;
  }
  return mus_id_TM2DCompatibilityLoose_;
}

std::vector<float>* const & cfa_8::mus_id_TM2DCompatibilityTight() const{
  if(!c_mus_id_TM2DCompatibilityTight_ && b_mus_id_TM2DCompatibilityTight_){
    b_mus_id_TM2DCompatibilityTight_->GetEntry(entry_);
    c_mus_id_TM2DCompatibilityTight_ = true;
  }
  return mus_id_TM2DCompatibilityTight_;
}

std::vector<float>* const & cfa_8::mus_id_TMLastStationLoose() const{
  if(!c_mus_id_TMLastStationLoose_ && b_mus_id_TMLastStationLoose_){
    b_mus_id_TMLastStationLoose_->GetEntry(entry_);
    c_mus_id_TMLastStationLoose_ = true;
  }
  return mus_id_TMLastStationLoose_;
}

std::vector<float>* const & cfa_8::mus_id_TMLastStationOptimizedLowPtLoose() const{
  if(!c_mus_id_TMLastStationOptimizedLowPtLoose_ && b_mus_id_TMLastStationOptimizedLowPtLoose_){
    b_mus_id_TMLastStationOptimizedLowPtLoose_->GetEntry(entry_);
    c_mus_id_TMLastStationOptimizedLowPtLoose_ = true;
  }
  return mus_id_TMLastStationOptimizedLowPtLoose_;
}

std::vector<float>* const & cfa_8::mus_id_TMLastStationOptimizedLowPtTight() const{
  if(!c_mus_id_TMLastStationOptimizedLowPtTight_ && b_mus_id_TMLastStationOptimizedLowPtTight_){
    b_mus_id_TMLastStationOptimizedLowPtTight_->GetEntry(entry_);
    c_mus_id_TMLastStationOptimizedLowPtTight_ = true;
  }
  return mus_id_TMLastStationOptimizedLowPtTight_;
}

std::vector<float>* const & cfa_8::mus_id_TMLastStationTight() const{
  if(!c_mus_id_TMLastStationTight_ && b_mus_id_TMLastStationTight_){
    b_mus_id_TMLastStationTight_->GetEntry(entry_);
    c_mus_id_TMLastStationTight_ = true;
  }
  return mus_id_TMLastStationTight_;
}

std::vector<float>* const & cfa_8::mus_id_TMOneStationLoose() const{
  if(!c_mus_id_TMOneStationLoose_ && b_mus_id_TMOneStationLoose_){
    b_mus_id_TMOneStationLoose_->GetEntry(entry_);
    c_mus_id_TMOneStationLoose_ = true;
  }
  return mus_id_TMOneStationLoose_;
}

std::vector<float>* const & cfa_8::mus_id_TMOneStationTight() const{
  if(!c_mus_id_TMOneStationTight_ && b_mus_id_TMOneStationTight_){
    b_mus_id_TMOneStationTight_->GetEntry(entry_);
    c_mus_id_TMOneStationTight_ = true;
  }
  return mus_id_TMOneStationTight_;
}

std::vector<float>* const & cfa_8::mus_id_TrackerMuonArbitrated() const{
  if(!c_mus_id_TrackerMuonArbitrated_ && b_mus_id_TrackerMuonArbitrated_){
    b_mus_id_TrackerMuonArbitrated_->GetEntry(entry_);
    c_mus_id_TrackerMuonArbitrated_ = true;
  }
  return mus_id_TrackerMuonArbitrated_;
}

std::vector<float>* const & cfa_8::mus_isCaloMuon() const{
  if(!c_mus_isCaloMuon_ && b_mus_isCaloMuon_){
    b_mus_isCaloMuon_->GetEntry(entry_);
    c_mus_isCaloMuon_ = true;
  }
  return mus_isCaloMuon_;
}

std::vector<float>* const & cfa_8::mus_isConvertedPhoton() const{
  if(!c_mus_isConvertedPhoton_ && b_mus_isConvertedPhoton_){
    b_mus_isConvertedPhoton_->GetEntry(entry_);
    c_mus_isConvertedPhoton_ = true;
  }
  return mus_isConvertedPhoton_;
}

std::vector<float>* const & cfa_8::mus_isElectron() const{
  if(!c_mus_isElectron_ && b_mus_isElectron_){
    b_mus_isElectron_->GetEntry(entry_);
    c_mus_isElectron_ = true;
  }
  return mus_isElectron_;
}

std::vector<float>* const & cfa_8::mus_isGlobalMuon() const{
  if(!c_mus_isGlobalMuon_ && b_mus_isGlobalMuon_){
    b_mus_isGlobalMuon_->GetEntry(entry_);
    c_mus_isGlobalMuon_ = true;
  }
  return mus_isGlobalMuon_;
}

std::vector<float>* const & cfa_8::mus_isPFMuon() const{
  if(!c_mus_isPFMuon_ && b_mus_isPFMuon_){
    b_mus_isPFMuon_->GetEntry(entry_);
    c_mus_isPFMuon_ = true;
  }
  return mus_isPFMuon_;
}

std::vector<float>* const & cfa_8::mus_isPhoton() const{
  if(!c_mus_isPhoton_ && b_mus_isPhoton_){
    b_mus_isPhoton_->GetEntry(entry_);
    c_mus_isPhoton_ = true;
  }
  return mus_isPhoton_;
}

std::vector<float>* const & cfa_8::mus_isStandAloneMuon() const{
  if(!c_mus_isStandAloneMuon_ && b_mus_isStandAloneMuon_){
    b_mus_isStandAloneMuon_->GetEntry(entry_);
    c_mus_isStandAloneMuon_ = true;
  }
  return mus_isStandAloneMuon_;
}

std::vector<float>* const & cfa_8::mus_isTrackerMuon() const{
  if(!c_mus_isTrackerMuon_ && b_mus_isTrackerMuon_){
    b_mus_isTrackerMuon_->GetEntry(entry_);
    c_mus_isTrackerMuon_ = true;
  }
  return mus_isTrackerMuon_;
}

std::vector<float>* const & cfa_8::mus_iso03_emEt() const{
  if(!c_mus_iso03_emEt_ && b_mus_iso03_emEt_){
    b_mus_iso03_emEt_->GetEntry(entry_);
    c_mus_iso03_emEt_ = true;
  }
  return mus_iso03_emEt_;
}

std::vector<float>* const & cfa_8::mus_iso03_emVetoEt() const{
  if(!c_mus_iso03_emVetoEt_ && b_mus_iso03_emVetoEt_){
    b_mus_iso03_emVetoEt_->GetEntry(entry_);
    c_mus_iso03_emVetoEt_ = true;
  }
  return mus_iso03_emVetoEt_;
}

std::vector<float>* const & cfa_8::mus_iso03_hadEt() const{
  if(!c_mus_iso03_hadEt_ && b_mus_iso03_hadEt_){
    b_mus_iso03_hadEt_->GetEntry(entry_);
    c_mus_iso03_hadEt_ = true;
  }
  return mus_iso03_hadEt_;
}

std::vector<float>* const & cfa_8::mus_iso03_hadVetoEt() const{
  if(!c_mus_iso03_hadVetoEt_ && b_mus_iso03_hadVetoEt_){
    b_mus_iso03_hadVetoEt_->GetEntry(entry_);
    c_mus_iso03_hadVetoEt_ = true;
  }
  return mus_iso03_hadVetoEt_;
}

std::vector<float>* const & cfa_8::mus_iso03_hoEt() const{
  if(!c_mus_iso03_hoEt_ && b_mus_iso03_hoEt_){
    b_mus_iso03_hoEt_->GetEntry(entry_);
    c_mus_iso03_hoEt_ = true;
  }
  return mus_iso03_hoEt_;
}

std::vector<float>* const & cfa_8::mus_iso03_nTracks() const{
  if(!c_mus_iso03_nTracks_ && b_mus_iso03_nTracks_){
    b_mus_iso03_nTracks_->GetEntry(entry_);
    c_mus_iso03_nTracks_ = true;
  }
  return mus_iso03_nTracks_;
}

std::vector<float>* const & cfa_8::mus_iso03_sumPt() const{
  if(!c_mus_iso03_sumPt_ && b_mus_iso03_sumPt_){
    b_mus_iso03_sumPt_->GetEntry(entry_);
    c_mus_iso03_sumPt_ = true;
  }
  return mus_iso03_sumPt_;
}

std::vector<float>* const & cfa_8::mus_iso05_emEt() const{
  if(!c_mus_iso05_emEt_ && b_mus_iso05_emEt_){
    b_mus_iso05_emEt_->GetEntry(entry_);
    c_mus_iso05_emEt_ = true;
  }
  return mus_iso05_emEt_;
}

std::vector<float>* const & cfa_8::mus_iso05_hadEt() const{
  if(!c_mus_iso05_hadEt_ && b_mus_iso05_hadEt_){
    b_mus_iso05_hadEt_->GetEntry(entry_);
    c_mus_iso05_hadEt_ = true;
  }
  return mus_iso05_hadEt_;
}

std::vector<float>* const & cfa_8::mus_iso05_hoEt() const{
  if(!c_mus_iso05_hoEt_ && b_mus_iso05_hoEt_){
    b_mus_iso05_hoEt_->GetEntry(entry_);
    c_mus_iso05_hoEt_ = true;
  }
  return mus_iso05_hoEt_;
}

std::vector<float>* const & cfa_8::mus_iso05_nTracks() const{
  if(!c_mus_iso05_nTracks_ && b_mus_iso05_nTracks_){
    b_mus_iso05_nTracks_->GetEntry(entry_);
    c_mus_iso05_nTracks_ = true;
  }
  return mus_iso05_nTracks_;
}

std::vector<float>* const & cfa_8::mus_iso05_sumPt() const{
  if(!c_mus_iso05_sumPt_ && b_mus_iso05_sumPt_){
    b_mus_iso05_sumPt_->GetEntry(entry_);
    c_mus_iso05_sumPt_ = true;
  }
  return mus_iso05_sumPt_;
}

std::vector<float>* const & cfa_8::mus_num_matches() const{
  if(!c_mus_num_matches_ && b_mus_num_matches_){
    b_mus_num_matches_->GetEntry(entry_);
    c_mus_num_matches_ = true;
  }
  return mus_num_matches_;
}

std::vector<float>* const & cfa_8::mus_numberOfMatchedStations() const{
  if(!c_mus_numberOfMatchedStations_ && b_mus_numberOfMatchedStations_){
    b_mus_numberOfMatchedStations_->GetEntry(entry_);
    c_mus_numberOfMatchedStations_ = true;
  }
  return mus_numberOfMatchedStations_;
}

std::vector<float>* const & cfa_8::mus_pfIsolationR03_sumChargedHadronPt() const{
  if(!c_mus_pfIsolationR03_sumChargedHadronPt_ && b_mus_pfIsolationR03_sumChargedHadronPt_){
    b_mus_pfIsolationR03_sumChargedHadronPt_->GetEntry(entry_);
    c_mus_pfIsolationR03_sumChargedHadronPt_ = true;
  }
  return mus_pfIsolationR03_sumChargedHadronPt_;
}

std::vector<float>* const & cfa_8::mus_pfIsolationR03_sumChargedParticlePt() const{
  if(!c_mus_pfIsolationR03_sumChargedParticlePt_ && b_mus_pfIsolationR03_sumChargedParticlePt_){
    b_mus_pfIsolationR03_sumChargedParticlePt_->GetEntry(entry_);
    c_mus_pfIsolationR03_sumChargedParticlePt_ = true;
  }
  return mus_pfIsolationR03_sumChargedParticlePt_;
}

std::vector<float>* const & cfa_8::mus_pfIsolationR03_sumNeutralHadronEt() const{
  if(!c_mus_pfIsolationR03_sumNeutralHadronEt_ && b_mus_pfIsolationR03_sumNeutralHadronEt_){
    b_mus_pfIsolationR03_sumNeutralHadronEt_->GetEntry(entry_);
    c_mus_pfIsolationR03_sumNeutralHadronEt_ = true;
  }
  return mus_pfIsolationR03_sumNeutralHadronEt_;
}

std::vector<float>* const & cfa_8::mus_pfIsolationR03_sumNeutralHadronEtHighThreshold() const{
  if(!c_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_ && b_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_){
    b_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_->GetEntry(entry_);
    c_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_ = true;
  }
  return mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_;
}

std::vector<float>* const & cfa_8::mus_pfIsolationR03_sumPUPt() const{
  if(!c_mus_pfIsolationR03_sumPUPt_ && b_mus_pfIsolationR03_sumPUPt_){
    b_mus_pfIsolationR03_sumPUPt_->GetEntry(entry_);
    c_mus_pfIsolationR03_sumPUPt_ = true;
  }
  return mus_pfIsolationR03_sumPUPt_;
}

std::vector<float>* const & cfa_8::mus_pfIsolationR03_sumPhotonEt() const{
  if(!c_mus_pfIsolationR03_sumPhotonEt_ && b_mus_pfIsolationR03_sumPhotonEt_){
    b_mus_pfIsolationR03_sumPhotonEt_->GetEntry(entry_);
    c_mus_pfIsolationR03_sumPhotonEt_ = true;
  }
  return mus_pfIsolationR03_sumPhotonEt_;
}

std::vector<float>* const & cfa_8::mus_pfIsolationR03_sumPhotonEtHighThreshold() const{
  if(!c_mus_pfIsolationR03_sumPhotonEtHighThreshold_ && b_mus_pfIsolationR03_sumPhotonEtHighThreshold_){
    b_mus_pfIsolationR03_sumPhotonEtHighThreshold_->GetEntry(entry_);
    c_mus_pfIsolationR03_sumPhotonEtHighThreshold_ = true;
  }
  return mus_pfIsolationR03_sumPhotonEtHighThreshold_;
}

std::vector<float>* const & cfa_8::mus_pfIsolationR04_sumChargedHadronPt() const{
  if(!c_mus_pfIsolationR04_sumChargedHadronPt_ && b_mus_pfIsolationR04_sumChargedHadronPt_){
    b_mus_pfIsolationR04_sumChargedHadronPt_->GetEntry(entry_);
    c_mus_pfIsolationR04_sumChargedHadronPt_ = true;
  }
  return mus_pfIsolationR04_sumChargedHadronPt_;
}

std::vector<float>* const & cfa_8::mus_pfIsolationR04_sumChargedParticlePt() const{
  if(!c_mus_pfIsolationR04_sumChargedParticlePt_ && b_mus_pfIsolationR04_sumChargedParticlePt_){
    b_mus_pfIsolationR04_sumChargedParticlePt_->GetEntry(entry_);
    c_mus_pfIsolationR04_sumChargedParticlePt_ = true;
  }
  return mus_pfIsolationR04_sumChargedParticlePt_;
}

std::vector<float>* const & cfa_8::mus_pfIsolationR04_sumNeutralHadronEt() const{
  if(!c_mus_pfIsolationR04_sumNeutralHadronEt_ && b_mus_pfIsolationR04_sumNeutralHadronEt_){
    b_mus_pfIsolationR04_sumNeutralHadronEt_->GetEntry(entry_);
    c_mus_pfIsolationR04_sumNeutralHadronEt_ = true;
  }
  return mus_pfIsolationR04_sumNeutralHadronEt_;
}

std::vector<float>* const & cfa_8::mus_pfIsolationR04_sumNeutralHadronEtHighThreshold() const{
  if(!c_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_ && b_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_){
    b_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_->GetEntry(entry_);
    c_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_ = true;
  }
  return mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_;
}

std::vector<float>* const & cfa_8::mus_pfIsolationR04_sumPUPt() const{
  if(!c_mus_pfIsolationR04_sumPUPt_ && b_mus_pfIsolationR04_sumPUPt_){
    b_mus_pfIsolationR04_sumPUPt_->GetEntry(entry_);
    c_mus_pfIsolationR04_sumPUPt_ = true;
  }
  return mus_pfIsolationR04_sumPUPt_;
}

std::vector<float>* const & cfa_8::mus_pfIsolationR04_sumPhotonEt() const{
  if(!c_mus_pfIsolationR04_sumPhotonEt_ && b_mus_pfIsolationR04_sumPhotonEt_){
    b_mus_pfIsolationR04_sumPhotonEt_->GetEntry(entry_);
    c_mus_pfIsolationR04_sumPhotonEt_ = true;
  }
  return mus_pfIsolationR04_sumPhotonEt_;
}

std::vector<float>* const & cfa_8::mus_pfIsolationR04_sumPhotonEtHighThreshold() const{
  if(!c_mus_pfIsolationR04_sumPhotonEtHighThreshold_ && b_mus_pfIsolationR04_sumPhotonEtHighThreshold_){
    b_mus_pfIsolationR04_sumPhotonEtHighThreshold_->GetEntry(entry_);
    c_mus_pfIsolationR04_sumPhotonEtHighThreshold_ = true;
  }
  return mus_pfIsolationR04_sumPhotonEtHighThreshold_;
}

std::vector<float>* const & cfa_8::mus_phi() const{
  if(!c_mus_phi_ && b_mus_phi_){
    b_mus_phi_->GetEntry(entry_);
    c_mus_phi_ = true;
  }
  return mus_phi_;
}

std::vector<float>* const & cfa_8::mus_picky_ExpectedHitsInner() const{
  if(!c_mus_picky_ExpectedHitsInner_ && b_mus_picky_ExpectedHitsInner_){
    b_mus_picky_ExpectedHitsInner_->GetEntry(entry_);
    c_mus_picky_ExpectedHitsInner_ = true;
  }
  return mus_picky_ExpectedHitsInner_;
}

std::vector<float>* const & cfa_8::mus_picky_ExpectedHitsOuter() const{
  if(!c_mus_picky_ExpectedHitsOuter_ && b_mus_picky_ExpectedHitsOuter_){
    b_mus_picky_ExpectedHitsOuter_->GetEntry(entry_);
    c_mus_picky_ExpectedHitsOuter_ = true;
  }
  return mus_picky_ExpectedHitsOuter_;
}

std::vector<float>* const & cfa_8::mus_picky_LayersWithMeasurement() const{
  if(!c_mus_picky_LayersWithMeasurement_ && b_mus_picky_LayersWithMeasurement_){
    b_mus_picky_LayersWithMeasurement_->GetEntry(entry_);
    c_mus_picky_LayersWithMeasurement_ = true;
  }
  return mus_picky_LayersWithMeasurement_;
}

std::vector<float>* const & cfa_8::mus_picky_LayersWithoutMeasurement() const{
  if(!c_mus_picky_LayersWithoutMeasurement_ && b_mus_picky_LayersWithoutMeasurement_){
    b_mus_picky_LayersWithoutMeasurement_->GetEntry(entry_);
    c_mus_picky_LayersWithoutMeasurement_ = true;
  }
  return mus_picky_LayersWithoutMeasurement_;
}

std::vector<float>* const & cfa_8::mus_picky_PixelLayersWithMeasurement() const{
  if(!c_mus_picky_PixelLayersWithMeasurement_ && b_mus_picky_PixelLayersWithMeasurement_){
    b_mus_picky_PixelLayersWithMeasurement_->GetEntry(entry_);
    c_mus_picky_PixelLayersWithMeasurement_ = true;
  }
  return mus_picky_PixelLayersWithMeasurement_;
}

std::vector<float>* const & cfa_8::mus_picky_ValidStripLayersWithMonoAndStereoHit() const{
  if(!c_mus_picky_ValidStripLayersWithMonoAndStereoHit_ && b_mus_picky_ValidStripLayersWithMonoAndStereoHit_){
    b_mus_picky_ValidStripLayersWithMonoAndStereoHit_->GetEntry(entry_);
    c_mus_picky_ValidStripLayersWithMonoAndStereoHit_ = true;
  }
  return mus_picky_ValidStripLayersWithMonoAndStereoHit_;
}

std::vector<float>* const & cfa_8::mus_picky_chg() const{
  if(!c_mus_picky_chg_ && b_mus_picky_chg_){
    b_mus_picky_chg_->GetEntry(entry_);
    c_mus_picky_chg_ = true;
  }
  return mus_picky_chg_;
}

std::vector<float>* const & cfa_8::mus_picky_chi2() const{
  if(!c_mus_picky_chi2_ && b_mus_picky_chi2_){
    b_mus_picky_chi2_->GetEntry(entry_);
    c_mus_picky_chi2_ = true;
  }
  return mus_picky_chi2_;
}

std::vector<float>* const & cfa_8::mus_picky_d0dum() const{
  if(!c_mus_picky_d0dum_ && b_mus_picky_d0dum_){
    b_mus_picky_d0dum_->GetEntry(entry_);
    c_mus_picky_d0dum_ = true;
  }
  return mus_picky_d0dum_;
}

std::vector<float>* const & cfa_8::mus_picky_d0dumErr() const{
  if(!c_mus_picky_d0dumErr_ && b_mus_picky_d0dumErr_){
    b_mus_picky_d0dumErr_->GetEntry(entry_);
    c_mus_picky_d0dumErr_ = true;
  }
  return mus_picky_d0dumErr_;
}

std::vector<float>* const & cfa_8::mus_picky_dz() const{
  if(!c_mus_picky_dz_ && b_mus_picky_dz_){
    b_mus_picky_dz_->GetEntry(entry_);
    c_mus_picky_dz_ = true;
  }
  return mus_picky_dz_;
}

std::vector<float>* const & cfa_8::mus_picky_dzErr() const{
  if(!c_mus_picky_dzErr_ && b_mus_picky_dzErr_){
    b_mus_picky_dzErr_->GetEntry(entry_);
    c_mus_picky_dzErr_ = true;
  }
  return mus_picky_dzErr_;
}

std::vector<float>* const & cfa_8::mus_picky_eta() const{
  if(!c_mus_picky_eta_ && b_mus_picky_eta_){
    b_mus_picky_eta_->GetEntry(entry_);
    c_mus_picky_eta_ = true;
  }
  return mus_picky_eta_;
}

std::vector<float>* const & cfa_8::mus_picky_etaErr() const{
  if(!c_mus_picky_etaErr_ && b_mus_picky_etaErr_){
    b_mus_picky_etaErr_->GetEntry(entry_);
    c_mus_picky_etaErr_ = true;
  }
  return mus_picky_etaErr_;
}

std::vector<float>* const & cfa_8::mus_picky_id() const{
  if(!c_mus_picky_id_ && b_mus_picky_id_){
    b_mus_picky_id_->GetEntry(entry_);
    c_mus_picky_id_ = true;
  }
  return mus_picky_id_;
}

std::vector<float>* const & cfa_8::mus_picky_ndof() const{
  if(!c_mus_picky_ndof_ && b_mus_picky_ndof_){
    b_mus_picky_ndof_->GetEntry(entry_);
    c_mus_picky_ndof_ = true;
  }
  return mus_picky_ndof_;
}

std::vector<float>* const & cfa_8::mus_picky_numlosthits() const{
  if(!c_mus_picky_numlosthits_ && b_mus_picky_numlosthits_){
    b_mus_picky_numlosthits_->GetEntry(entry_);
    c_mus_picky_numlosthits_ = true;
  }
  return mus_picky_numlosthits_;
}

std::vector<float>* const & cfa_8::mus_picky_numvalPixelhits() const{
  if(!c_mus_picky_numvalPixelhits_ && b_mus_picky_numvalPixelhits_){
    b_mus_picky_numvalPixelhits_->GetEntry(entry_);
    c_mus_picky_numvalPixelhits_ = true;
  }
  return mus_picky_numvalPixelhits_;
}

std::vector<float>* const & cfa_8::mus_picky_numvalhits() const{
  if(!c_mus_picky_numvalhits_ && b_mus_picky_numvalhits_){
    b_mus_picky_numvalhits_->GetEntry(entry_);
    c_mus_picky_numvalhits_ = true;
  }
  return mus_picky_numvalhits_;
}

std::vector<float>* const & cfa_8::mus_picky_phi() const{
  if(!c_mus_picky_phi_ && b_mus_picky_phi_){
    b_mus_picky_phi_->GetEntry(entry_);
    c_mus_picky_phi_ = true;
  }
  return mus_picky_phi_;
}

std::vector<float>* const & cfa_8::mus_picky_phiErr() const{
  if(!c_mus_picky_phiErr_ && b_mus_picky_phiErr_){
    b_mus_picky_phiErr_->GetEntry(entry_);
    c_mus_picky_phiErr_ = true;
  }
  return mus_picky_phiErr_;
}

std::vector<float>* const & cfa_8::mus_picky_pt() const{
  if(!c_mus_picky_pt_ && b_mus_picky_pt_){
    b_mus_picky_pt_->GetEntry(entry_);
    c_mus_picky_pt_ = true;
  }
  return mus_picky_pt_;
}

std::vector<float>* const & cfa_8::mus_picky_ptErr() const{
  if(!c_mus_picky_ptErr_ && b_mus_picky_ptErr_){
    b_mus_picky_ptErr_->GetEntry(entry_);
    c_mus_picky_ptErr_ = true;
  }
  return mus_picky_ptErr_;
}

std::vector<float>* const & cfa_8::mus_picky_px() const{
  if(!c_mus_picky_px_ && b_mus_picky_px_){
    b_mus_picky_px_->GetEntry(entry_);
    c_mus_picky_px_ = true;
  }
  return mus_picky_px_;
}

std::vector<float>* const & cfa_8::mus_picky_py() const{
  if(!c_mus_picky_py_ && b_mus_picky_py_){
    b_mus_picky_py_->GetEntry(entry_);
    c_mus_picky_py_ = true;
  }
  return mus_picky_py_;
}

std::vector<float>* const & cfa_8::mus_picky_pz() const{
  if(!c_mus_picky_pz_ && b_mus_picky_pz_){
    b_mus_picky_pz_->GetEntry(entry_);
    c_mus_picky_pz_ = true;
  }
  return mus_picky_pz_;
}

std::vector<float>* const & cfa_8::mus_picky_theta() const{
  if(!c_mus_picky_theta_ && b_mus_picky_theta_){
    b_mus_picky_theta_->GetEntry(entry_);
    c_mus_picky_theta_ = true;
  }
  return mus_picky_theta_;
}

std::vector<float>* const & cfa_8::mus_picky_vx() const{
  if(!c_mus_picky_vx_ && b_mus_picky_vx_){
    b_mus_picky_vx_->GetEntry(entry_);
    c_mus_picky_vx_ = true;
  }
  return mus_picky_vx_;
}

std::vector<float>* const & cfa_8::mus_picky_vy() const{
  if(!c_mus_picky_vy_ && b_mus_picky_vy_){
    b_mus_picky_vy_->GetEntry(entry_);
    c_mus_picky_vy_ = true;
  }
  return mus_picky_vy_;
}

std::vector<float>* const & cfa_8::mus_picky_vz() const{
  if(!c_mus_picky_vz_ && b_mus_picky_vz_){
    b_mus_picky_vz_->GetEntry(entry_);
    c_mus_picky_vz_ = true;
  }
  return mus_picky_vz_;
}

std::vector<float>* const & cfa_8::mus_pt() const{
  if(!c_mus_pt_ && b_mus_pt_){
    b_mus_pt_->GetEntry(entry_);
    c_mus_pt_ = true;
  }
  return mus_pt_;
}

std::vector<float>* const & cfa_8::mus_px() const{
  if(!c_mus_px_ && b_mus_px_){
    b_mus_px_->GetEntry(entry_);
    c_mus_px_ = true;
  }
  return mus_px_;
}

std::vector<float>* const & cfa_8::mus_py() const{
  if(!c_mus_py_ && b_mus_py_){
    b_mus_py_->GetEntry(entry_);
    c_mus_py_ = true;
  }
  return mus_py_;
}

std::vector<float>* const & cfa_8::mus_pz() const{
  if(!c_mus_pz_ && b_mus_pz_){
    b_mus_pz_->GetEntry(entry_);
    c_mus_pz_ = true;
  }
  return mus_pz_;
}

std::vector<float>* const & cfa_8::mus_stamu_chg() const{
  if(!c_mus_stamu_chg_ && b_mus_stamu_chg_){
    b_mus_stamu_chg_->GetEntry(entry_);
    c_mus_stamu_chg_ = true;
  }
  return mus_stamu_chg_;
}

std::vector<float>* const & cfa_8::mus_stamu_chi2() const{
  if(!c_mus_stamu_chi2_ && b_mus_stamu_chi2_){
    b_mus_stamu_chi2_->GetEntry(entry_);
    c_mus_stamu_chi2_ = true;
  }
  return mus_stamu_chi2_;
}

std::vector<float>* const & cfa_8::mus_stamu_d0dum() const{
  if(!c_mus_stamu_d0dum_ && b_mus_stamu_d0dum_){
    b_mus_stamu_d0dum_->GetEntry(entry_);
    c_mus_stamu_d0dum_ = true;
  }
  return mus_stamu_d0dum_;
}

std::vector<float>* const & cfa_8::mus_stamu_d0dumErr() const{
  if(!c_mus_stamu_d0dumErr_ && b_mus_stamu_d0dumErr_){
    b_mus_stamu_d0dumErr_->GetEntry(entry_);
    c_mus_stamu_d0dumErr_ = true;
  }
  return mus_stamu_d0dumErr_;
}

std::vector<float>* const & cfa_8::mus_stamu_dz() const{
  if(!c_mus_stamu_dz_ && b_mus_stamu_dz_){
    b_mus_stamu_dz_->GetEntry(entry_);
    c_mus_stamu_dz_ = true;
  }
  return mus_stamu_dz_;
}

std::vector<float>* const & cfa_8::mus_stamu_dzErr() const{
  if(!c_mus_stamu_dzErr_ && b_mus_stamu_dzErr_){
    b_mus_stamu_dzErr_->GetEntry(entry_);
    c_mus_stamu_dzErr_ = true;
  }
  return mus_stamu_dzErr_;
}

std::vector<float>* const & cfa_8::mus_stamu_eta() const{
  if(!c_mus_stamu_eta_ && b_mus_stamu_eta_){
    b_mus_stamu_eta_->GetEntry(entry_);
    c_mus_stamu_eta_ = true;
  }
  return mus_stamu_eta_;
}

std::vector<float>* const & cfa_8::mus_stamu_etaErr() const{
  if(!c_mus_stamu_etaErr_ && b_mus_stamu_etaErr_){
    b_mus_stamu_etaErr_->GetEntry(entry_);
    c_mus_stamu_etaErr_ = true;
  }
  return mus_stamu_etaErr_;
}

std::vector<float>* const & cfa_8::mus_stamu_ndof() const{
  if(!c_mus_stamu_ndof_ && b_mus_stamu_ndof_){
    b_mus_stamu_ndof_->GetEntry(entry_);
    c_mus_stamu_ndof_ = true;
  }
  return mus_stamu_ndof_;
}

std::vector<float>* const & cfa_8::mus_stamu_numlosthits() const{
  if(!c_mus_stamu_numlosthits_ && b_mus_stamu_numlosthits_){
    b_mus_stamu_numlosthits_->GetEntry(entry_);
    c_mus_stamu_numlosthits_ = true;
  }
  return mus_stamu_numlosthits_;
}

std::vector<float>* const & cfa_8::mus_stamu_numvalhits() const{
  if(!c_mus_stamu_numvalhits_ && b_mus_stamu_numvalhits_){
    b_mus_stamu_numvalhits_->GetEntry(entry_);
    c_mus_stamu_numvalhits_ = true;
  }
  return mus_stamu_numvalhits_;
}

std::vector<float>* const & cfa_8::mus_stamu_phi() const{
  if(!c_mus_stamu_phi_ && b_mus_stamu_phi_){
    b_mus_stamu_phi_->GetEntry(entry_);
    c_mus_stamu_phi_ = true;
  }
  return mus_stamu_phi_;
}

std::vector<float>* const & cfa_8::mus_stamu_phiErr() const{
  if(!c_mus_stamu_phiErr_ && b_mus_stamu_phiErr_){
    b_mus_stamu_phiErr_->GetEntry(entry_);
    c_mus_stamu_phiErr_ = true;
  }
  return mus_stamu_phiErr_;
}

std::vector<float>* const & cfa_8::mus_stamu_pt() const{
  if(!c_mus_stamu_pt_ && b_mus_stamu_pt_){
    b_mus_stamu_pt_->GetEntry(entry_);
    c_mus_stamu_pt_ = true;
  }
  return mus_stamu_pt_;
}

std::vector<float>* const & cfa_8::mus_stamu_ptErr() const{
  if(!c_mus_stamu_ptErr_ && b_mus_stamu_ptErr_){
    b_mus_stamu_ptErr_->GetEntry(entry_);
    c_mus_stamu_ptErr_ = true;
  }
  return mus_stamu_ptErr_;
}

std::vector<float>* const & cfa_8::mus_stamu_px() const{
  if(!c_mus_stamu_px_ && b_mus_stamu_px_){
    b_mus_stamu_px_->GetEntry(entry_);
    c_mus_stamu_px_ = true;
  }
  return mus_stamu_px_;
}

std::vector<float>* const & cfa_8::mus_stamu_py() const{
  if(!c_mus_stamu_py_ && b_mus_stamu_py_){
    b_mus_stamu_py_->GetEntry(entry_);
    c_mus_stamu_py_ = true;
  }
  return mus_stamu_py_;
}

std::vector<float>* const & cfa_8::mus_stamu_pz() const{
  if(!c_mus_stamu_pz_ && b_mus_stamu_pz_){
    b_mus_stamu_pz_->GetEntry(entry_);
    c_mus_stamu_pz_ = true;
  }
  return mus_stamu_pz_;
}

std::vector<float>* const & cfa_8::mus_stamu_theta() const{
  if(!c_mus_stamu_theta_ && b_mus_stamu_theta_){
    b_mus_stamu_theta_->GetEntry(entry_);
    c_mus_stamu_theta_ = true;
  }
  return mus_stamu_theta_;
}

std::vector<float>* const & cfa_8::mus_stamu_vx() const{
  if(!c_mus_stamu_vx_ && b_mus_stamu_vx_){
    b_mus_stamu_vx_->GetEntry(entry_);
    c_mus_stamu_vx_ = true;
  }
  return mus_stamu_vx_;
}

std::vector<float>* const & cfa_8::mus_stamu_vy() const{
  if(!c_mus_stamu_vy_ && b_mus_stamu_vy_){
    b_mus_stamu_vy_->GetEntry(entry_);
    c_mus_stamu_vy_ = true;
  }
  return mus_stamu_vy_;
}

std::vector<float>* const & cfa_8::mus_stamu_vz() const{
  if(!c_mus_stamu_vz_ && b_mus_stamu_vz_){
    b_mus_stamu_vz_->GetEntry(entry_);
    c_mus_stamu_vz_ = true;
  }
  return mus_stamu_vz_;
}

std::vector<float>* const & cfa_8::mus_status() const{
  if(!c_mus_status_ && b_mus_status_){
    b_mus_status_->GetEntry(entry_);
    c_mus_status_ = true;
  }
  return mus_status_;
}

std::vector<float>* const & cfa_8::mus_tIso() const{
  if(!c_mus_tIso_ && b_mus_tIso_){
    b_mus_tIso_->GetEntry(entry_);
    c_mus_tIso_ = true;
  }
  return mus_tIso_;
}

std::vector<float>* const & cfa_8::mus_theta() const{
  if(!c_mus_theta_ && b_mus_theta_){
    b_mus_theta_->GetEntry(entry_);
    c_mus_theta_ = true;
  }
  return mus_theta_;
}

std::vector<float>* const & cfa_8::mus_tkHits() const{
  if(!c_mus_tkHits_ && b_mus_tkHits_){
    b_mus_tkHits_->GetEntry(entry_);
    c_mus_tkHits_ = true;
  }
  return mus_tkHits_;
}

std::vector<float>* const & cfa_8::mus_tk_ExpectedHitsInner() const{
  if(!c_mus_tk_ExpectedHitsInner_ && b_mus_tk_ExpectedHitsInner_){
    b_mus_tk_ExpectedHitsInner_->GetEntry(entry_);
    c_mus_tk_ExpectedHitsInner_ = true;
  }
  return mus_tk_ExpectedHitsInner_;
}

std::vector<float>* const & cfa_8::mus_tk_ExpectedHitsOuter() const{
  if(!c_mus_tk_ExpectedHitsOuter_ && b_mus_tk_ExpectedHitsOuter_){
    b_mus_tk_ExpectedHitsOuter_->GetEntry(entry_);
    c_mus_tk_ExpectedHitsOuter_ = true;
  }
  return mus_tk_ExpectedHitsOuter_;
}

std::vector<float>* const & cfa_8::mus_tk_LayersWithMeasurement() const{
  if(!c_mus_tk_LayersWithMeasurement_ && b_mus_tk_LayersWithMeasurement_){
    b_mus_tk_LayersWithMeasurement_->GetEntry(entry_);
    c_mus_tk_LayersWithMeasurement_ = true;
  }
  return mus_tk_LayersWithMeasurement_;
}

std::vector<float>* const & cfa_8::mus_tk_LayersWithoutMeasurement() const{
  if(!c_mus_tk_LayersWithoutMeasurement_ && b_mus_tk_LayersWithoutMeasurement_){
    b_mus_tk_LayersWithoutMeasurement_->GetEntry(entry_);
    c_mus_tk_LayersWithoutMeasurement_ = true;
  }
  return mus_tk_LayersWithoutMeasurement_;
}

std::vector<float>* const & cfa_8::mus_tk_PixelLayersWithMeasurement() const{
  if(!c_mus_tk_PixelLayersWithMeasurement_ && b_mus_tk_PixelLayersWithMeasurement_){
    b_mus_tk_PixelLayersWithMeasurement_->GetEntry(entry_);
    c_mus_tk_PixelLayersWithMeasurement_ = true;
  }
  return mus_tk_PixelLayersWithMeasurement_;
}

std::vector<float>* const & cfa_8::mus_tk_ValidStripLayersWithMonoAndStereoHit() const{
  if(!c_mus_tk_ValidStripLayersWithMonoAndStereoHit_ && b_mus_tk_ValidStripLayersWithMonoAndStereoHit_){
    b_mus_tk_ValidStripLayersWithMonoAndStereoHit_->GetEntry(entry_);
    c_mus_tk_ValidStripLayersWithMonoAndStereoHit_ = true;
  }
  return mus_tk_ValidStripLayersWithMonoAndStereoHit_;
}

std::vector<float>* const & cfa_8::mus_tk_chg() const{
  if(!c_mus_tk_chg_ && b_mus_tk_chg_){
    b_mus_tk_chg_->GetEntry(entry_);
    c_mus_tk_chg_ = true;
  }
  return mus_tk_chg_;
}

std::vector<float>* const & cfa_8::mus_tk_chi2() const{
  if(!c_mus_tk_chi2_ && b_mus_tk_chi2_){
    b_mus_tk_chi2_->GetEntry(entry_);
    c_mus_tk_chi2_ = true;
  }
  return mus_tk_chi2_;
}

std::vector<float>* const & cfa_8::mus_tk_d0dum() const{
  if(!c_mus_tk_d0dum_ && b_mus_tk_d0dum_){
    b_mus_tk_d0dum_->GetEntry(entry_);
    c_mus_tk_d0dum_ = true;
  }
  return mus_tk_d0dum_;
}

std::vector<float>* const & cfa_8::mus_tk_d0dumErr() const{
  if(!c_mus_tk_d0dumErr_ && b_mus_tk_d0dumErr_){
    b_mus_tk_d0dumErr_->GetEntry(entry_);
    c_mus_tk_d0dumErr_ = true;
  }
  return mus_tk_d0dumErr_;
}

std::vector<float>* const & cfa_8::mus_tk_dz() const{
  if(!c_mus_tk_dz_ && b_mus_tk_dz_){
    b_mus_tk_dz_->GetEntry(entry_);
    c_mus_tk_dz_ = true;
  }
  return mus_tk_dz_;
}

std::vector<float>* const & cfa_8::mus_tk_dzErr() const{
  if(!c_mus_tk_dzErr_ && b_mus_tk_dzErr_){
    b_mus_tk_dzErr_->GetEntry(entry_);
    c_mus_tk_dzErr_ = true;
  }
  return mus_tk_dzErr_;
}

std::vector<float>* const & cfa_8::mus_tk_eta() const{
  if(!c_mus_tk_eta_ && b_mus_tk_eta_){
    b_mus_tk_eta_->GetEntry(entry_);
    c_mus_tk_eta_ = true;
  }
  return mus_tk_eta_;
}

std::vector<float>* const & cfa_8::mus_tk_etaErr() const{
  if(!c_mus_tk_etaErr_ && b_mus_tk_etaErr_){
    b_mus_tk_etaErr_->GetEntry(entry_);
    c_mus_tk_etaErr_ = true;
  }
  return mus_tk_etaErr_;
}

std::vector<float>* const & cfa_8::mus_tk_id() const{
  if(!c_mus_tk_id_ && b_mus_tk_id_){
    b_mus_tk_id_->GetEntry(entry_);
    c_mus_tk_id_ = true;
  }
  return mus_tk_id_;
}

std::vector<float>* const & cfa_8::mus_tk_ndof() const{
  if(!c_mus_tk_ndof_ && b_mus_tk_ndof_){
    b_mus_tk_ndof_->GetEntry(entry_);
    c_mus_tk_ndof_ = true;
  }
  return mus_tk_ndof_;
}

std::vector<float>* const & cfa_8::mus_tk_numlosthits() const{
  if(!c_mus_tk_numlosthits_ && b_mus_tk_numlosthits_){
    b_mus_tk_numlosthits_->GetEntry(entry_);
    c_mus_tk_numlosthits_ = true;
  }
  return mus_tk_numlosthits_;
}

std::vector<float>* const & cfa_8::mus_tk_numpixelWthMeasr() const{
  if(!c_mus_tk_numpixelWthMeasr_ && b_mus_tk_numpixelWthMeasr_){
    b_mus_tk_numpixelWthMeasr_->GetEntry(entry_);
    c_mus_tk_numpixelWthMeasr_ = true;
  }
  return mus_tk_numpixelWthMeasr_;
}

std::vector<float>* const & cfa_8::mus_tk_numvalPixelhits() const{
  if(!c_mus_tk_numvalPixelhits_ && b_mus_tk_numvalPixelhits_){
    b_mus_tk_numvalPixelhits_->GetEntry(entry_);
    c_mus_tk_numvalPixelhits_ = true;
  }
  return mus_tk_numvalPixelhits_;
}

std::vector<float>* const & cfa_8::mus_tk_numvalhits() const{
  if(!c_mus_tk_numvalhits_ && b_mus_tk_numvalhits_){
    b_mus_tk_numvalhits_->GetEntry(entry_);
    c_mus_tk_numvalhits_ = true;
  }
  return mus_tk_numvalhits_;
}

std::vector<float>* const & cfa_8::mus_tk_phi() const{
  if(!c_mus_tk_phi_ && b_mus_tk_phi_){
    b_mus_tk_phi_->GetEntry(entry_);
    c_mus_tk_phi_ = true;
  }
  return mus_tk_phi_;
}

std::vector<float>* const & cfa_8::mus_tk_phiErr() const{
  if(!c_mus_tk_phiErr_ && b_mus_tk_phiErr_){
    b_mus_tk_phiErr_->GetEntry(entry_);
    c_mus_tk_phiErr_ = true;
  }
  return mus_tk_phiErr_;
}

std::vector<float>* const & cfa_8::mus_tk_pt() const{
  if(!c_mus_tk_pt_ && b_mus_tk_pt_){
    b_mus_tk_pt_->GetEntry(entry_);
    c_mus_tk_pt_ = true;
  }
  return mus_tk_pt_;
}

std::vector<float>* const & cfa_8::mus_tk_ptErr() const{
  if(!c_mus_tk_ptErr_ && b_mus_tk_ptErr_){
    b_mus_tk_ptErr_->GetEntry(entry_);
    c_mus_tk_ptErr_ = true;
  }
  return mus_tk_ptErr_;
}

std::vector<float>* const & cfa_8::mus_tk_px() const{
  if(!c_mus_tk_px_ && b_mus_tk_px_){
    b_mus_tk_px_->GetEntry(entry_);
    c_mus_tk_px_ = true;
  }
  return mus_tk_px_;
}

std::vector<float>* const & cfa_8::mus_tk_py() const{
  if(!c_mus_tk_py_ && b_mus_tk_py_){
    b_mus_tk_py_->GetEntry(entry_);
    c_mus_tk_py_ = true;
  }
  return mus_tk_py_;
}

std::vector<float>* const & cfa_8::mus_tk_pz() const{
  if(!c_mus_tk_pz_ && b_mus_tk_pz_){
    b_mus_tk_pz_->GetEntry(entry_);
    c_mus_tk_pz_ = true;
  }
  return mus_tk_pz_;
}

std::vector<float>* const & cfa_8::mus_tk_theta() const{
  if(!c_mus_tk_theta_ && b_mus_tk_theta_){
    b_mus_tk_theta_->GetEntry(entry_);
    c_mus_tk_theta_ = true;
  }
  return mus_tk_theta_;
}

std::vector<float>* const & cfa_8::mus_tk_vx() const{
  if(!c_mus_tk_vx_ && b_mus_tk_vx_){
    b_mus_tk_vx_->GetEntry(entry_);
    c_mus_tk_vx_ = true;
  }
  return mus_tk_vx_;
}

std::vector<float>* const & cfa_8::mus_tk_vy() const{
  if(!c_mus_tk_vy_ && b_mus_tk_vy_){
    b_mus_tk_vy_->GetEntry(entry_);
    c_mus_tk_vy_ = true;
  }
  return mus_tk_vy_;
}

std::vector<float>* const & cfa_8::mus_tk_vz() const{
  if(!c_mus_tk_vz_ && b_mus_tk_vz_){
    b_mus_tk_vz_->GetEntry(entry_);
    c_mus_tk_vz_ = true;
  }
  return mus_tk_vz_;
}

std::vector<float>* const & cfa_8::mus_tpfms_ExpectedHitsInner() const{
  if(!c_mus_tpfms_ExpectedHitsInner_ && b_mus_tpfms_ExpectedHitsInner_){
    b_mus_tpfms_ExpectedHitsInner_->GetEntry(entry_);
    c_mus_tpfms_ExpectedHitsInner_ = true;
  }
  return mus_tpfms_ExpectedHitsInner_;
}

std::vector<float>* const & cfa_8::mus_tpfms_ExpectedHitsOuter() const{
  if(!c_mus_tpfms_ExpectedHitsOuter_ && b_mus_tpfms_ExpectedHitsOuter_){
    b_mus_tpfms_ExpectedHitsOuter_->GetEntry(entry_);
    c_mus_tpfms_ExpectedHitsOuter_ = true;
  }
  return mus_tpfms_ExpectedHitsOuter_;
}

std::vector<float>* const & cfa_8::mus_tpfms_LayersWithMeasurement() const{
  if(!c_mus_tpfms_LayersWithMeasurement_ && b_mus_tpfms_LayersWithMeasurement_){
    b_mus_tpfms_LayersWithMeasurement_->GetEntry(entry_);
    c_mus_tpfms_LayersWithMeasurement_ = true;
  }
  return mus_tpfms_LayersWithMeasurement_;
}

std::vector<float>* const & cfa_8::mus_tpfms_LayersWithoutMeasurement() const{
  if(!c_mus_tpfms_LayersWithoutMeasurement_ && b_mus_tpfms_LayersWithoutMeasurement_){
    b_mus_tpfms_LayersWithoutMeasurement_->GetEntry(entry_);
    c_mus_tpfms_LayersWithoutMeasurement_ = true;
  }
  return mus_tpfms_LayersWithoutMeasurement_;
}

std::vector<float>* const & cfa_8::mus_tpfms_PixelLayersWithMeasurement() const{
  if(!c_mus_tpfms_PixelLayersWithMeasurement_ && b_mus_tpfms_PixelLayersWithMeasurement_){
    b_mus_tpfms_PixelLayersWithMeasurement_->GetEntry(entry_);
    c_mus_tpfms_PixelLayersWithMeasurement_ = true;
  }
  return mus_tpfms_PixelLayersWithMeasurement_;
}

std::vector<float>* const & cfa_8::mus_tpfms_ValidStripLayersWithMonoAndStereoHit() const{
  if(!c_mus_tpfms_ValidStripLayersWithMonoAndStereoHit_ && b_mus_tpfms_ValidStripLayersWithMonoAndStereoHit_){
    b_mus_tpfms_ValidStripLayersWithMonoAndStereoHit_->GetEntry(entry_);
    c_mus_tpfms_ValidStripLayersWithMonoAndStereoHit_ = true;
  }
  return mus_tpfms_ValidStripLayersWithMonoAndStereoHit_;
}

std::vector<float>* const & cfa_8::mus_tpfms_chg() const{
  if(!c_mus_tpfms_chg_ && b_mus_tpfms_chg_){
    b_mus_tpfms_chg_->GetEntry(entry_);
    c_mus_tpfms_chg_ = true;
  }
  return mus_tpfms_chg_;
}

std::vector<float>* const & cfa_8::mus_tpfms_chi2() const{
  if(!c_mus_tpfms_chi2_ && b_mus_tpfms_chi2_){
    b_mus_tpfms_chi2_->GetEntry(entry_);
    c_mus_tpfms_chi2_ = true;
  }
  return mus_tpfms_chi2_;
}

std::vector<float>* const & cfa_8::mus_tpfms_d0dum() const{
  if(!c_mus_tpfms_d0dum_ && b_mus_tpfms_d0dum_){
    b_mus_tpfms_d0dum_->GetEntry(entry_);
    c_mus_tpfms_d0dum_ = true;
  }
  return mus_tpfms_d0dum_;
}

std::vector<float>* const & cfa_8::mus_tpfms_d0dumErr() const{
  if(!c_mus_tpfms_d0dumErr_ && b_mus_tpfms_d0dumErr_){
    b_mus_tpfms_d0dumErr_->GetEntry(entry_);
    c_mus_tpfms_d0dumErr_ = true;
  }
  return mus_tpfms_d0dumErr_;
}

std::vector<float>* const & cfa_8::mus_tpfms_dz() const{
  if(!c_mus_tpfms_dz_ && b_mus_tpfms_dz_){
    b_mus_tpfms_dz_->GetEntry(entry_);
    c_mus_tpfms_dz_ = true;
  }
  return mus_tpfms_dz_;
}

std::vector<float>* const & cfa_8::mus_tpfms_dzErr() const{
  if(!c_mus_tpfms_dzErr_ && b_mus_tpfms_dzErr_){
    b_mus_tpfms_dzErr_->GetEntry(entry_);
    c_mus_tpfms_dzErr_ = true;
  }
  return mus_tpfms_dzErr_;
}

std::vector<float>* const & cfa_8::mus_tpfms_eta() const{
  if(!c_mus_tpfms_eta_ && b_mus_tpfms_eta_){
    b_mus_tpfms_eta_->GetEntry(entry_);
    c_mus_tpfms_eta_ = true;
  }
  return mus_tpfms_eta_;
}

std::vector<float>* const & cfa_8::mus_tpfms_etaErr() const{
  if(!c_mus_tpfms_etaErr_ && b_mus_tpfms_etaErr_){
    b_mus_tpfms_etaErr_->GetEntry(entry_);
    c_mus_tpfms_etaErr_ = true;
  }
  return mus_tpfms_etaErr_;
}

std::vector<float>* const & cfa_8::mus_tpfms_id() const{
  if(!c_mus_tpfms_id_ && b_mus_tpfms_id_){
    b_mus_tpfms_id_->GetEntry(entry_);
    c_mus_tpfms_id_ = true;
  }
  return mus_tpfms_id_;
}

std::vector<float>* const & cfa_8::mus_tpfms_ndof() const{
  if(!c_mus_tpfms_ndof_ && b_mus_tpfms_ndof_){
    b_mus_tpfms_ndof_->GetEntry(entry_);
    c_mus_tpfms_ndof_ = true;
  }
  return mus_tpfms_ndof_;
}

std::vector<float>* const & cfa_8::mus_tpfms_numlosthits() const{
  if(!c_mus_tpfms_numlosthits_ && b_mus_tpfms_numlosthits_){
    b_mus_tpfms_numlosthits_->GetEntry(entry_);
    c_mus_tpfms_numlosthits_ = true;
  }
  return mus_tpfms_numlosthits_;
}

std::vector<float>* const & cfa_8::mus_tpfms_numvalPixelhits() const{
  if(!c_mus_tpfms_numvalPixelhits_ && b_mus_tpfms_numvalPixelhits_){
    b_mus_tpfms_numvalPixelhits_->GetEntry(entry_);
    c_mus_tpfms_numvalPixelhits_ = true;
  }
  return mus_tpfms_numvalPixelhits_;
}

std::vector<float>* const & cfa_8::mus_tpfms_numvalhits() const{
  if(!c_mus_tpfms_numvalhits_ && b_mus_tpfms_numvalhits_){
    b_mus_tpfms_numvalhits_->GetEntry(entry_);
    c_mus_tpfms_numvalhits_ = true;
  }
  return mus_tpfms_numvalhits_;
}

std::vector<float>* const & cfa_8::mus_tpfms_phi() const{
  if(!c_mus_tpfms_phi_ && b_mus_tpfms_phi_){
    b_mus_tpfms_phi_->GetEntry(entry_);
    c_mus_tpfms_phi_ = true;
  }
  return mus_tpfms_phi_;
}

std::vector<float>* const & cfa_8::mus_tpfms_phiErr() const{
  if(!c_mus_tpfms_phiErr_ && b_mus_tpfms_phiErr_){
    b_mus_tpfms_phiErr_->GetEntry(entry_);
    c_mus_tpfms_phiErr_ = true;
  }
  return mus_tpfms_phiErr_;
}

std::vector<float>* const & cfa_8::mus_tpfms_pt() const{
  if(!c_mus_tpfms_pt_ && b_mus_tpfms_pt_){
    b_mus_tpfms_pt_->GetEntry(entry_);
    c_mus_tpfms_pt_ = true;
  }
  return mus_tpfms_pt_;
}

std::vector<float>* const & cfa_8::mus_tpfms_ptErr() const{
  if(!c_mus_tpfms_ptErr_ && b_mus_tpfms_ptErr_){
    b_mus_tpfms_ptErr_->GetEntry(entry_);
    c_mus_tpfms_ptErr_ = true;
  }
  return mus_tpfms_ptErr_;
}

std::vector<float>* const & cfa_8::mus_tpfms_px() const{
  if(!c_mus_tpfms_px_ && b_mus_tpfms_px_){
    b_mus_tpfms_px_->GetEntry(entry_);
    c_mus_tpfms_px_ = true;
  }
  return mus_tpfms_px_;
}

std::vector<float>* const & cfa_8::mus_tpfms_py() const{
  if(!c_mus_tpfms_py_ && b_mus_tpfms_py_){
    b_mus_tpfms_py_->GetEntry(entry_);
    c_mus_tpfms_py_ = true;
  }
  return mus_tpfms_py_;
}

std::vector<float>* const & cfa_8::mus_tpfms_pz() const{
  if(!c_mus_tpfms_pz_ && b_mus_tpfms_pz_){
    b_mus_tpfms_pz_->GetEntry(entry_);
    c_mus_tpfms_pz_ = true;
  }
  return mus_tpfms_pz_;
}

std::vector<float>* const & cfa_8::mus_tpfms_theta() const{
  if(!c_mus_tpfms_theta_ && b_mus_tpfms_theta_){
    b_mus_tpfms_theta_->GetEntry(entry_);
    c_mus_tpfms_theta_ = true;
  }
  return mus_tpfms_theta_;
}

std::vector<float>* const & cfa_8::mus_tpfms_vx() const{
  if(!c_mus_tpfms_vx_ && b_mus_tpfms_vx_){
    b_mus_tpfms_vx_->GetEntry(entry_);
    c_mus_tpfms_vx_ = true;
  }
  return mus_tpfms_vx_;
}

std::vector<float>* const & cfa_8::mus_tpfms_vy() const{
  if(!c_mus_tpfms_vy_ && b_mus_tpfms_vy_){
    b_mus_tpfms_vy_->GetEntry(entry_);
    c_mus_tpfms_vy_ = true;
  }
  return mus_tpfms_vy_;
}

std::vector<float>* const & cfa_8::mus_tpfms_vz() const{
  if(!c_mus_tpfms_vz_ && b_mus_tpfms_vz_){
    b_mus_tpfms_vz_->GetEntry(entry_);
    c_mus_tpfms_vz_ = true;
  }
  return mus_tpfms_vz_;
}

UInt_t const & cfa_8::orbitNumber() const{
  if(!c_orbitNumber_ && b_orbitNumber_){
    b_orbitNumber_->GetEntry(entry_);
    c_orbitNumber_ = true;
  }
  return orbitNumber_;
}

Int_t const & cfa_8::passprescaleHT250filter_decision() const{
  if(!c_passprescaleHT250filter_decision_ && b_passprescaleHT250filter_decision_){
    b_passprescaleHT250filter_decision_->GetEntry(entry_);
    c_passprescaleHT250filter_decision_ = true;
  }
  return passprescaleHT250filter_decision_;
}

Int_t const & cfa_8::passprescaleHT300filter_decision() const{
  if(!c_passprescaleHT300filter_decision_ && b_passprescaleHT300filter_decision_){
    b_passprescaleHT300filter_decision_->GetEntry(entry_);
    c_passprescaleHT300filter_decision_ = true;
  }
  return passprescaleHT300filter_decision_;
}

Int_t const & cfa_8::passprescaleHT350filter_decision() const{
  if(!c_passprescaleHT350filter_decision_ && b_passprescaleHT350filter_decision_){
    b_passprescaleHT350filter_decision_->GetEntry(entry_);
    c_passprescaleHT350filter_decision_ = true;
  }
  return passprescaleHT350filter_decision_;
}

Int_t const & cfa_8::passprescaleHT400filter_decision() const{
  if(!c_passprescaleHT400filter_decision_ && b_passprescaleHT400filter_decision_){
    b_passprescaleHT400filter_decision_->GetEntry(entry_);
    c_passprescaleHT400filter_decision_ = true;
  }
  return passprescaleHT400filter_decision_;
}

Int_t const & cfa_8::passprescaleHT450filter_decision() const{
  if(!c_passprescaleHT450filter_decision_ && b_passprescaleHT450filter_decision_){
    b_passprescaleHT450filter_decision_->GetEntry(entry_);
    c_passprescaleHT450filter_decision_ = true;
  }
  return passprescaleHT450filter_decision_;
}

Int_t const & cfa_8::passprescaleJet30MET80filter_decision() const{
  if(!c_passprescaleJet30MET80filter_decision_ && b_passprescaleJet30MET80filter_decision_){
    b_passprescaleJet30MET80filter_decision_->GetEntry(entry_);
    c_passprescaleJet30MET80filter_decision_ = true;
  }
  return passprescaleJet30MET80filter_decision_;
}

Int_t const & cfa_8::passprescalePFHT350filter_decision() const{
  if(!c_passprescalePFHT350filter_decision_ && b_passprescalePFHT350filter_decision_){
    b_passprescalePFHT350filter_decision_->GetEntry(entry_);
    c_passprescalePFHT350filter_decision_ = true;
  }
  return passprescalePFHT350filter_decision_;
}

std::vector<float>* const & cfa_8::pdfweights_cteq() const{
  if(!c_pdfweights_cteq_ && b_pdfweights_cteq_){
    b_pdfweights_cteq_->GetEntry(entry_);
    c_pdfweights_cteq_ = true;
  }
  return pdfweights_cteq_;
}

std::vector<float>* const & cfa_8::pdfweights_mstw() const{
  if(!c_pdfweights_mstw_ && b_pdfweights_mstw_){
    b_pdfweights_mstw_->GetEntry(entry_);
    c_pdfweights_mstw_ = true;
  }
  return pdfweights_mstw_;
}

std::vector<float>* const & cfa_8::pdfweights_nnpdf() const{
  if(!c_pdfweights_nnpdf_ && b_pdfweights_nnpdf_){
    b_pdfweights_nnpdf_->GetEntry(entry_);
    c_pdfweights_nnpdf_ = true;
  }
  return pdfweights_nnpdf_;
}

std::vector<float>* const & cfa_8::pfTypeINoXYCorrmets_et() const{
  if(!c_pfTypeINoXYCorrmets_et_ && b_pfTypeINoXYCorrmets_et_){
    b_pfTypeINoXYCorrmets_et_->GetEntry(entry_);
    c_pfTypeINoXYCorrmets_et_ = true;
  }
  return pfTypeINoXYCorrmets_et_;
}

std::vector<float>* const & cfa_8::pfTypeINoXYCorrmets_ex() const{
  if(!c_pfTypeINoXYCorrmets_ex_ && b_pfTypeINoXYCorrmets_ex_){
    b_pfTypeINoXYCorrmets_ex_->GetEntry(entry_);
    c_pfTypeINoXYCorrmets_ex_ = true;
  }
  return pfTypeINoXYCorrmets_ex_;
}

std::vector<float>* const & cfa_8::pfTypeINoXYCorrmets_ey() const{
  if(!c_pfTypeINoXYCorrmets_ey_ && b_pfTypeINoXYCorrmets_ey_){
    b_pfTypeINoXYCorrmets_ey_->GetEntry(entry_);
    c_pfTypeINoXYCorrmets_ey_ = true;
  }
  return pfTypeINoXYCorrmets_ey_;
}

std::vector<float>* const & cfa_8::pfTypeINoXYCorrmets_gen_et() const{
  if(!c_pfTypeINoXYCorrmets_gen_et_ && b_pfTypeINoXYCorrmets_gen_et_){
    b_pfTypeINoXYCorrmets_gen_et_->GetEntry(entry_);
    c_pfTypeINoXYCorrmets_gen_et_ = true;
  }
  return pfTypeINoXYCorrmets_gen_et_;
}

std::vector<float>* const & cfa_8::pfTypeINoXYCorrmets_gen_phi() const{
  if(!c_pfTypeINoXYCorrmets_gen_phi_ && b_pfTypeINoXYCorrmets_gen_phi_){
    b_pfTypeINoXYCorrmets_gen_phi_->GetEntry(entry_);
    c_pfTypeINoXYCorrmets_gen_phi_ = true;
  }
  return pfTypeINoXYCorrmets_gen_phi_;
}

std::vector<float>* const & cfa_8::pfTypeINoXYCorrmets_phi() const{
  if(!c_pfTypeINoXYCorrmets_phi_ && b_pfTypeINoXYCorrmets_phi_){
    b_pfTypeINoXYCorrmets_phi_->GetEntry(entry_);
    c_pfTypeINoXYCorrmets_phi_ = true;
  }
  return pfTypeINoXYCorrmets_phi_;
}

std::vector<float>* const & cfa_8::pfTypeINoXYCorrmets_sign() const{
  if(!c_pfTypeINoXYCorrmets_sign_ && b_pfTypeINoXYCorrmets_sign_){
    b_pfTypeINoXYCorrmets_sign_->GetEntry(entry_);
    c_pfTypeINoXYCorrmets_sign_ = true;
  }
  return pfTypeINoXYCorrmets_sign_;
}

std::vector<float>* const & cfa_8::pfTypeINoXYCorrmets_sumEt() const{
  if(!c_pfTypeINoXYCorrmets_sumEt_ && b_pfTypeINoXYCorrmets_sumEt_){
    b_pfTypeINoXYCorrmets_sumEt_->GetEntry(entry_);
    c_pfTypeINoXYCorrmets_sumEt_ = true;
  }
  return pfTypeINoXYCorrmets_sumEt_;
}

std::vector<float>* const & cfa_8::pfTypeINoXYCorrmets_unCPhi() const{
  if(!c_pfTypeINoXYCorrmets_unCPhi_ && b_pfTypeINoXYCorrmets_unCPhi_){
    b_pfTypeINoXYCorrmets_unCPhi_->GetEntry(entry_);
    c_pfTypeINoXYCorrmets_unCPhi_ = true;
  }
  return pfTypeINoXYCorrmets_unCPhi_;
}

std::vector<float>* const & cfa_8::pfTypeINoXYCorrmets_unCPt() const{
  if(!c_pfTypeINoXYCorrmets_unCPt_ && b_pfTypeINoXYCorrmets_unCPt_){
    b_pfTypeINoXYCorrmets_unCPt_->GetEntry(entry_);
    c_pfTypeINoXYCorrmets_unCPt_ = true;
  }
  return pfTypeINoXYCorrmets_unCPt_;
}

std::vector<float>* const & cfa_8::pfTypeIType0mets_et() const{
  if(!c_pfTypeIType0mets_et_ && b_pfTypeIType0mets_et_){
    b_pfTypeIType0mets_et_->GetEntry(entry_);
    c_pfTypeIType0mets_et_ = true;
  }
  return pfTypeIType0mets_et_;
}

std::vector<float>* const & cfa_8::pfTypeIType0mets_ex() const{
  if(!c_pfTypeIType0mets_ex_ && b_pfTypeIType0mets_ex_){
    b_pfTypeIType0mets_ex_->GetEntry(entry_);
    c_pfTypeIType0mets_ex_ = true;
  }
  return pfTypeIType0mets_ex_;
}

std::vector<float>* const & cfa_8::pfTypeIType0mets_ey() const{
  if(!c_pfTypeIType0mets_ey_ && b_pfTypeIType0mets_ey_){
    b_pfTypeIType0mets_ey_->GetEntry(entry_);
    c_pfTypeIType0mets_ey_ = true;
  }
  return pfTypeIType0mets_ey_;
}

std::vector<float>* const & cfa_8::pfTypeIType0mets_gen_et() const{
  if(!c_pfTypeIType0mets_gen_et_ && b_pfTypeIType0mets_gen_et_){
    b_pfTypeIType0mets_gen_et_->GetEntry(entry_);
    c_pfTypeIType0mets_gen_et_ = true;
  }
  return pfTypeIType0mets_gen_et_;
}

std::vector<float>* const & cfa_8::pfTypeIType0mets_gen_phi() const{
  if(!c_pfTypeIType0mets_gen_phi_ && b_pfTypeIType0mets_gen_phi_){
    b_pfTypeIType0mets_gen_phi_->GetEntry(entry_);
    c_pfTypeIType0mets_gen_phi_ = true;
  }
  return pfTypeIType0mets_gen_phi_;
}

std::vector<float>* const & cfa_8::pfTypeIType0mets_phi() const{
  if(!c_pfTypeIType0mets_phi_ && b_pfTypeIType0mets_phi_){
    b_pfTypeIType0mets_phi_->GetEntry(entry_);
    c_pfTypeIType0mets_phi_ = true;
  }
  return pfTypeIType0mets_phi_;
}

std::vector<float>* const & cfa_8::pfTypeIType0mets_sign() const{
  if(!c_pfTypeIType0mets_sign_ && b_pfTypeIType0mets_sign_){
    b_pfTypeIType0mets_sign_->GetEntry(entry_);
    c_pfTypeIType0mets_sign_ = true;
  }
  return pfTypeIType0mets_sign_;
}

std::vector<float>* const & cfa_8::pfTypeIType0mets_sumEt() const{
  if(!c_pfTypeIType0mets_sumEt_ && b_pfTypeIType0mets_sumEt_){
    b_pfTypeIType0mets_sumEt_->GetEntry(entry_);
    c_pfTypeIType0mets_sumEt_ = true;
  }
  return pfTypeIType0mets_sumEt_;
}

std::vector<float>* const & cfa_8::pfTypeIType0mets_unCPhi() const{
  if(!c_pfTypeIType0mets_unCPhi_ && b_pfTypeIType0mets_unCPhi_){
    b_pfTypeIType0mets_unCPhi_->GetEntry(entry_);
    c_pfTypeIType0mets_unCPhi_ = true;
  }
  return pfTypeIType0mets_unCPhi_;
}

std::vector<float>* const & cfa_8::pfTypeIType0mets_unCPt() const{
  if(!c_pfTypeIType0mets_unCPt_ && b_pfTypeIType0mets_unCPt_){
    b_pfTypeIType0mets_unCPt_->GetEntry(entry_);
    c_pfTypeIType0mets_unCPt_ = true;
  }
  return pfTypeIType0mets_unCPt_;
}

std::vector<float>* const & cfa_8::pfTypeImets_et() const{
  if(!c_pfTypeImets_et_ && b_pfTypeImets_et_){
    b_pfTypeImets_et_->GetEntry(entry_);
    c_pfTypeImets_et_ = true;
  }
  return pfTypeImets_et_;
}

std::vector<float>* const & cfa_8::pfTypeImets_ex() const{
  if(!c_pfTypeImets_ex_ && b_pfTypeImets_ex_){
    b_pfTypeImets_ex_->GetEntry(entry_);
    c_pfTypeImets_ex_ = true;
  }
  return pfTypeImets_ex_;
}

std::vector<float>* const & cfa_8::pfTypeImets_ey() const{
  if(!c_pfTypeImets_ey_ && b_pfTypeImets_ey_){
    b_pfTypeImets_ey_->GetEntry(entry_);
    c_pfTypeImets_ey_ = true;
  }
  return pfTypeImets_ey_;
}

std::vector<float>* const & cfa_8::pfTypeImets_gen_et() const{
  if(!c_pfTypeImets_gen_et_ && b_pfTypeImets_gen_et_){
    b_pfTypeImets_gen_et_->GetEntry(entry_);
    c_pfTypeImets_gen_et_ = true;
  }
  return pfTypeImets_gen_et_;
}

std::vector<float>* const & cfa_8::pfTypeImets_gen_phi() const{
  if(!c_pfTypeImets_gen_phi_ && b_pfTypeImets_gen_phi_){
    b_pfTypeImets_gen_phi_->GetEntry(entry_);
    c_pfTypeImets_gen_phi_ = true;
  }
  return pfTypeImets_gen_phi_;
}

std::vector<float>* const & cfa_8::pfTypeImets_phi() const{
  if(!c_pfTypeImets_phi_ && b_pfTypeImets_phi_){
    b_pfTypeImets_phi_->GetEntry(entry_);
    c_pfTypeImets_phi_ = true;
  }
  return pfTypeImets_phi_;
}

std::vector<float>* const & cfa_8::pfTypeImets_sign() const{
  if(!c_pfTypeImets_sign_ && b_pfTypeImets_sign_){
    b_pfTypeImets_sign_->GetEntry(entry_);
    c_pfTypeImets_sign_ = true;
  }
  return pfTypeImets_sign_;
}

std::vector<float>* const & cfa_8::pfTypeImets_sumEt() const{
  if(!c_pfTypeImets_sumEt_ && b_pfTypeImets_sumEt_){
    b_pfTypeImets_sumEt_->GetEntry(entry_);
    c_pfTypeImets_sumEt_ = true;
  }
  return pfTypeImets_sumEt_;
}

std::vector<float>* const & cfa_8::pfTypeImets_unCPhi() const{
  if(!c_pfTypeImets_unCPhi_ && b_pfTypeImets_unCPhi_){
    b_pfTypeImets_unCPhi_->GetEntry(entry_);
    c_pfTypeImets_unCPhi_ = true;
  }
  return pfTypeImets_unCPhi_;
}

std::vector<float>* const & cfa_8::pfTypeImets_unCPt() const{
  if(!c_pfTypeImets_unCPt_ && b_pfTypeImets_unCPt_){
    b_pfTypeImets_unCPt_->GetEntry(entry_);
    c_pfTypeImets_unCPt_ = true;
  }
  return pfTypeImets_unCPt_;
}

std::vector<float>* const & cfa_8::pf_els_PATpassConversionVeto() const{
  if(!c_pf_els_PATpassConversionVeto_ && b_pf_els_PATpassConversionVeto_){
    b_pf_els_PATpassConversionVeto_->GetEntry(entry_);
    c_pf_els_PATpassConversionVeto_ = true;
  }
  return pf_els_PATpassConversionVeto_;
}

std::vector<float>* const & cfa_8::pf_els_PFchargedHadronIsoR03() const{
  if(!c_pf_els_PFchargedHadronIsoR03_ && b_pf_els_PFchargedHadronIsoR03_){
    b_pf_els_PFchargedHadronIsoR03_->GetEntry(entry_);
    c_pf_els_PFchargedHadronIsoR03_ = true;
  }
  return pf_els_PFchargedHadronIsoR03_;
}

std::vector<float>* const & cfa_8::pf_els_PFneutralHadronIsoR03() const{
  if(!c_pf_els_PFneutralHadronIsoR03_ && b_pf_els_PFneutralHadronIsoR03_){
    b_pf_els_PFneutralHadronIsoR03_->GetEntry(entry_);
    c_pf_els_PFneutralHadronIsoR03_ = true;
  }
  return pf_els_PFneutralHadronIsoR03_;
}

std::vector<float>* const & cfa_8::pf_els_PFphotonIsoR03() const{
  if(!c_pf_els_PFphotonIsoR03_ && b_pf_els_PFphotonIsoR03_){
    b_pf_els_PFphotonIsoR03_->GetEntry(entry_);
    c_pf_els_PFphotonIsoR03_ = true;
  }
  return pf_els_PFphotonIsoR03_;
}

std::vector<float>* const & cfa_8::pf_els_basicClustersSize() const{
  if(!c_pf_els_basicClustersSize_ && b_pf_els_basicClustersSize_){
    b_pf_els_basicClustersSize_->GetEntry(entry_);
    c_pf_els_basicClustersSize_ = true;
  }
  return pf_els_basicClustersSize_;
}

std::vector<float>* const & cfa_8::pf_els_cIso() const{
  if(!c_pf_els_cIso_ && b_pf_els_cIso_){
    b_pf_els_cIso_->GetEntry(entry_);
    c_pf_els_cIso_ = true;
  }
  return pf_els_cIso_;
}

std::vector<float>* const & cfa_8::pf_els_caloEnergy() const{
  if(!c_pf_els_caloEnergy_ && b_pf_els_caloEnergy_){
    b_pf_els_caloEnergy_->GetEntry(entry_);
    c_pf_els_caloEnergy_ = true;
  }
  return pf_els_caloEnergy_;
}

std::vector<float>* const & cfa_8::pf_els_charge() const{
  if(!c_pf_els_charge_ && b_pf_els_charge_){
    b_pf_els_charge_->GetEntry(entry_);
    c_pf_els_charge_ = true;
  }
  return pf_els_charge_;
}

std::vector<float>* const & cfa_8::pf_els_chargedHadronIso() const{
  if(!c_pf_els_chargedHadronIso_ && b_pf_els_chargedHadronIso_){
    b_pf_els_chargedHadronIso_->GetEntry(entry_);
    c_pf_els_chargedHadronIso_ = true;
  }
  return pf_els_chargedHadronIso_;
}

std::vector<float>* const & cfa_8::pf_els_chi2() const{
  if(!c_pf_els_chi2_ && b_pf_els_chi2_){
    b_pf_els_chi2_->GetEntry(entry_);
    c_pf_els_chi2_ = true;
  }
  return pf_els_chi2_;
}

std::vector<float>* const & cfa_8::pf_els_core_ecalDrivenSeed() const{
  if(!c_pf_els_core_ecalDrivenSeed_ && b_pf_els_core_ecalDrivenSeed_){
    b_pf_els_core_ecalDrivenSeed_->GetEntry(entry_);
    c_pf_els_core_ecalDrivenSeed_ = true;
  }
  return pf_els_core_ecalDrivenSeed_;
}

std::vector<float>* const & cfa_8::pf_els_cpx() const{
  if(!c_pf_els_cpx_ && b_pf_els_cpx_){
    b_pf_els_cpx_->GetEntry(entry_);
    c_pf_els_cpx_ = true;
  }
  return pf_els_cpx_;
}

std::vector<float>* const & cfa_8::pf_els_cpy() const{
  if(!c_pf_els_cpy_ && b_pf_els_cpy_){
    b_pf_els_cpy_->GetEntry(entry_);
    c_pf_els_cpy_ = true;
  }
  return pf_els_cpy_;
}

std::vector<float>* const & cfa_8::pf_els_cpz() const{
  if(!c_pf_els_cpz_ && b_pf_els_cpz_){
    b_pf_els_cpz_->GetEntry(entry_);
    c_pf_els_cpz_ = true;
  }
  return pf_els_cpz_;
}

std::vector<float>* const & cfa_8::pf_els_ctf_tk_charge() const{
  if(!c_pf_els_ctf_tk_charge_ && b_pf_els_ctf_tk_charge_){
    b_pf_els_ctf_tk_charge_->GetEntry(entry_);
    c_pf_els_ctf_tk_charge_ = true;
  }
  return pf_els_ctf_tk_charge_;
}

std::vector<float>* const & cfa_8::pf_els_ctf_tk_eta() const{
  if(!c_pf_els_ctf_tk_eta_ && b_pf_els_ctf_tk_eta_){
    b_pf_els_ctf_tk_eta_->GetEntry(entry_);
    c_pf_els_ctf_tk_eta_ = true;
  }
  return pf_els_ctf_tk_eta_;
}

std::vector<float>* const & cfa_8::pf_els_ctf_tk_id() const{
  if(!c_pf_els_ctf_tk_id_ && b_pf_els_ctf_tk_id_){
    b_pf_els_ctf_tk_id_->GetEntry(entry_);
    c_pf_els_ctf_tk_id_ = true;
  }
  return pf_els_ctf_tk_id_;
}

std::vector<float>* const & cfa_8::pf_els_ctf_tk_phi() const{
  if(!c_pf_els_ctf_tk_phi_ && b_pf_els_ctf_tk_phi_){
    b_pf_els_ctf_tk_phi_->GetEntry(entry_);
    c_pf_els_ctf_tk_phi_ = true;
  }
  return pf_els_ctf_tk_phi_;
}

std::vector<float>* const & cfa_8::pf_els_cx() const{
  if(!c_pf_els_cx_ && b_pf_els_cx_){
    b_pf_els_cx_->GetEntry(entry_);
    c_pf_els_cx_ = true;
  }
  return pf_els_cx_;
}

std::vector<float>* const & cfa_8::pf_els_cy() const{
  if(!c_pf_els_cy_ && b_pf_els_cy_){
    b_pf_els_cy_->GetEntry(entry_);
    c_pf_els_cy_ = true;
  }
  return pf_els_cy_;
}

std::vector<float>* const & cfa_8::pf_els_cz() const{
  if(!c_pf_els_cz_ && b_pf_els_cz_){
    b_pf_els_cz_->GetEntry(entry_);
    c_pf_els_cz_ = true;
  }
  return pf_els_cz_;
}

std::vector<float>* const & cfa_8::pf_els_d0dum() const{
  if(!c_pf_els_d0dum_ && b_pf_els_d0dum_){
    b_pf_els_d0dum_->GetEntry(entry_);
    c_pf_els_d0dum_ = true;
  }
  return pf_els_d0dum_;
}

std::vector<float>* const & cfa_8::pf_els_d0dumError() const{
  if(!c_pf_els_d0dumError_ && b_pf_els_d0dumError_){
    b_pf_els_d0dumError_->GetEntry(entry_);
    c_pf_els_d0dumError_ = true;
  }
  return pf_els_d0dumError_;
}

std::vector<float>* const & cfa_8::pf_els_dEtaIn() const{
  if(!c_pf_els_dEtaIn_ && b_pf_els_dEtaIn_){
    b_pf_els_dEtaIn_->GetEntry(entry_);
    c_pf_els_dEtaIn_ = true;
  }
  return pf_els_dEtaIn_;
}

std::vector<float>* const & cfa_8::pf_els_dEtaOut() const{
  if(!c_pf_els_dEtaOut_ && b_pf_els_dEtaOut_){
    b_pf_els_dEtaOut_->GetEntry(entry_);
    c_pf_els_dEtaOut_ = true;
  }
  return pf_els_dEtaOut_;
}

std::vector<float>* const & cfa_8::pf_els_dPhiIn() const{
  if(!c_pf_els_dPhiIn_ && b_pf_els_dPhiIn_){
    b_pf_els_dPhiIn_->GetEntry(entry_);
    c_pf_els_dPhiIn_ = true;
  }
  return pf_els_dPhiIn_;
}

std::vector<float>* const & cfa_8::pf_els_dPhiOut() const{
  if(!c_pf_els_dPhiOut_ && b_pf_els_dPhiOut_){
    b_pf_els_dPhiOut_->GetEntry(entry_);
    c_pf_els_dPhiOut_ = true;
  }
  return pf_els_dPhiOut_;
}

std::vector<float>* const & cfa_8::pf_els_dr03EcalRecHitSumEt() const{
  if(!c_pf_els_dr03EcalRecHitSumEt_ && b_pf_els_dr03EcalRecHitSumEt_){
    b_pf_els_dr03EcalRecHitSumEt_->GetEntry(entry_);
    c_pf_els_dr03EcalRecHitSumEt_ = true;
  }
  return pf_els_dr03EcalRecHitSumEt_;
}

std::vector<float>* const & cfa_8::pf_els_dr03HcalDepth1TowerSumEt() const{
  if(!c_pf_els_dr03HcalDepth1TowerSumEt_ && b_pf_els_dr03HcalDepth1TowerSumEt_){
    b_pf_els_dr03HcalDepth1TowerSumEt_->GetEntry(entry_);
    c_pf_els_dr03HcalDepth1TowerSumEt_ = true;
  }
  return pf_els_dr03HcalDepth1TowerSumEt_;
}

std::vector<float>* const & cfa_8::pf_els_dr03HcalDepth2TowerSumEt() const{
  if(!c_pf_els_dr03HcalDepth2TowerSumEt_ && b_pf_els_dr03HcalDepth2TowerSumEt_){
    b_pf_els_dr03HcalDepth2TowerSumEt_->GetEntry(entry_);
    c_pf_els_dr03HcalDepth2TowerSumEt_ = true;
  }
  return pf_els_dr03HcalDepth2TowerSumEt_;
}

std::vector<float>* const & cfa_8::pf_els_dr03HcalTowerSumEt() const{
  if(!c_pf_els_dr03HcalTowerSumEt_ && b_pf_els_dr03HcalTowerSumEt_){
    b_pf_els_dr03HcalTowerSumEt_->GetEntry(entry_);
    c_pf_els_dr03HcalTowerSumEt_ = true;
  }
  return pf_els_dr03HcalTowerSumEt_;
}

std::vector<float>* const & cfa_8::pf_els_dr03TkSumPt() const{
  if(!c_pf_els_dr03TkSumPt_ && b_pf_els_dr03TkSumPt_){
    b_pf_els_dr03TkSumPt_->GetEntry(entry_);
    c_pf_els_dr03TkSumPt_ = true;
  }
  return pf_els_dr03TkSumPt_;
}

std::vector<float>* const & cfa_8::pf_els_dr04EcalRecHitSumEt() const{
  if(!c_pf_els_dr04EcalRecHitSumEt_ && b_pf_els_dr04EcalRecHitSumEt_){
    b_pf_els_dr04EcalRecHitSumEt_->GetEntry(entry_);
    c_pf_els_dr04EcalRecHitSumEt_ = true;
  }
  return pf_els_dr04EcalRecHitSumEt_;
}

std::vector<float>* const & cfa_8::pf_els_dr04HcalDepth1TowerSumEt() const{
  if(!c_pf_els_dr04HcalDepth1TowerSumEt_ && b_pf_els_dr04HcalDepth1TowerSumEt_){
    b_pf_els_dr04HcalDepth1TowerSumEt_->GetEntry(entry_);
    c_pf_els_dr04HcalDepth1TowerSumEt_ = true;
  }
  return pf_els_dr04HcalDepth1TowerSumEt_;
}

std::vector<float>* const & cfa_8::pf_els_dr04HcalDepth2TowerSumEt() const{
  if(!c_pf_els_dr04HcalDepth2TowerSumEt_ && b_pf_els_dr04HcalDepth2TowerSumEt_){
    b_pf_els_dr04HcalDepth2TowerSumEt_->GetEntry(entry_);
    c_pf_els_dr04HcalDepth2TowerSumEt_ = true;
  }
  return pf_els_dr04HcalDepth2TowerSumEt_;
}

std::vector<float>* const & cfa_8::pf_els_dr04HcalTowerSumEt() const{
  if(!c_pf_els_dr04HcalTowerSumEt_ && b_pf_els_dr04HcalTowerSumEt_){
    b_pf_els_dr04HcalTowerSumEt_->GetEntry(entry_);
    c_pf_els_dr04HcalTowerSumEt_ = true;
  }
  return pf_els_dr04HcalTowerSumEt_;
}

std::vector<float>* const & cfa_8::pf_els_dr04TkSumPt() const{
  if(!c_pf_els_dr04TkSumPt_ && b_pf_els_dr04TkSumPt_){
    b_pf_els_dr04TkSumPt_->GetEntry(entry_);
    c_pf_els_dr04TkSumPt_ = true;
  }
  return pf_els_dr04TkSumPt_;
}

std::vector<float>* const & cfa_8::pf_els_dz() const{
  if(!c_pf_els_dz_ && b_pf_els_dz_){
    b_pf_els_dz_->GetEntry(entry_);
    c_pf_els_dz_ = true;
  }
  return pf_els_dz_;
}

std::vector<float>* const & cfa_8::pf_els_dzError() const{
  if(!c_pf_els_dzError_ && b_pf_els_dzError_){
    b_pf_els_dzError_->GetEntry(entry_);
    c_pf_els_dzError_ = true;
  }
  return pf_els_dzError_;
}

std::vector<float>* const & cfa_8::pf_els_eOverPIn() const{
  if(!c_pf_els_eOverPIn_ && b_pf_els_eOverPIn_){
    b_pf_els_eOverPIn_->GetEntry(entry_);
    c_pf_els_eOverPIn_ = true;
  }
  return pf_els_eOverPIn_;
}

std::vector<float>* const & cfa_8::pf_els_eSeedOverPOut() const{
  if(!c_pf_els_eSeedOverPOut_ && b_pf_els_eSeedOverPOut_){
    b_pf_els_eSeedOverPOut_->GetEntry(entry_);
    c_pf_els_eSeedOverPOut_ = true;
  }
  return pf_els_eSeedOverPOut_;
}

std::vector<float>* const & cfa_8::pf_els_ecalIso() const{
  if(!c_pf_els_ecalIso_ && b_pf_els_ecalIso_){
    b_pf_els_ecalIso_->GetEntry(entry_);
    c_pf_els_ecalIso_ = true;
  }
  return pf_els_ecalIso_;
}

std::vector<float>* const & cfa_8::pf_els_energy() const{
  if(!c_pf_els_energy_ && b_pf_els_energy_){
    b_pf_els_energy_->GetEntry(entry_);
    c_pf_els_energy_ = true;
  }
  return pf_els_energy_;
}

std::vector<float>* const & cfa_8::pf_els_et() const{
  if(!c_pf_els_et_ && b_pf_els_et_){
    b_pf_els_et_->GetEntry(entry_);
    c_pf_els_et_ = true;
  }
  return pf_els_et_;
}

std::vector<float>* const & cfa_8::pf_els_eta() const{
  if(!c_pf_els_eta_ && b_pf_els_eta_){
    b_pf_els_eta_->GetEntry(entry_);
    c_pf_els_eta_ = true;
  }
  return pf_els_eta_;
}

std::vector<float>* const & cfa_8::pf_els_etaError() const{
  if(!c_pf_els_etaError_ && b_pf_els_etaError_){
    b_pf_els_etaError_->GetEntry(entry_);
    c_pf_els_etaError_ = true;
  }
  return pf_els_etaError_;
}

std::vector<float>* const & cfa_8::pf_els_fbrem() const{
  if(!c_pf_els_fbrem_ && b_pf_els_fbrem_){
    b_pf_els_fbrem_->GetEntry(entry_);
    c_pf_els_fbrem_ = true;
  }
  return pf_els_fbrem_;
}

std::vector<float>* const & cfa_8::pf_els_gen_et() const{
  if(!c_pf_els_gen_et_ && b_pf_els_gen_et_){
    b_pf_els_gen_et_->GetEntry(entry_);
    c_pf_els_gen_et_ = true;
  }
  return pf_els_gen_et_;
}

std::vector<float>* const & cfa_8::pf_els_gen_eta() const{
  if(!c_pf_els_gen_eta_ && b_pf_els_gen_eta_){
    b_pf_els_gen_eta_->GetEntry(entry_);
    c_pf_els_gen_eta_ = true;
  }
  return pf_els_gen_eta_;
}

std::vector<float>* const & cfa_8::pf_els_gen_id() const{
  if(!c_pf_els_gen_id_ && b_pf_els_gen_id_){
    b_pf_els_gen_id_->GetEntry(entry_);
    c_pf_els_gen_id_ = true;
  }
  return pf_els_gen_id_;
}

std::vector<float>* const & cfa_8::pf_els_gen_mother_et() const{
  if(!c_pf_els_gen_mother_et_ && b_pf_els_gen_mother_et_){
    b_pf_els_gen_mother_et_->GetEntry(entry_);
    c_pf_els_gen_mother_et_ = true;
  }
  return pf_els_gen_mother_et_;
}

std::vector<float>* const & cfa_8::pf_els_gen_mother_eta() const{
  if(!c_pf_els_gen_mother_eta_ && b_pf_els_gen_mother_eta_){
    b_pf_els_gen_mother_eta_->GetEntry(entry_);
    c_pf_els_gen_mother_eta_ = true;
  }
  return pf_els_gen_mother_eta_;
}

std::vector<float>* const & cfa_8::pf_els_gen_mother_id() const{
  if(!c_pf_els_gen_mother_id_ && b_pf_els_gen_mother_id_){
    b_pf_els_gen_mother_id_->GetEntry(entry_);
    c_pf_els_gen_mother_id_ = true;
  }
  return pf_els_gen_mother_id_;
}

std::vector<float>* const & cfa_8::pf_els_gen_mother_phi() const{
  if(!c_pf_els_gen_mother_phi_ && b_pf_els_gen_mother_phi_){
    b_pf_els_gen_mother_phi_->GetEntry(entry_);
    c_pf_els_gen_mother_phi_ = true;
  }
  return pf_els_gen_mother_phi_;
}

std::vector<float>* const & cfa_8::pf_els_gen_mother_pt() const{
  if(!c_pf_els_gen_mother_pt_ && b_pf_els_gen_mother_pt_){
    b_pf_els_gen_mother_pt_->GetEntry(entry_);
    c_pf_els_gen_mother_pt_ = true;
  }
  return pf_els_gen_mother_pt_;
}

std::vector<float>* const & cfa_8::pf_els_gen_mother_px() const{
  if(!c_pf_els_gen_mother_px_ && b_pf_els_gen_mother_px_){
    b_pf_els_gen_mother_px_->GetEntry(entry_);
    c_pf_els_gen_mother_px_ = true;
  }
  return pf_els_gen_mother_px_;
}

std::vector<float>* const & cfa_8::pf_els_gen_mother_py() const{
  if(!c_pf_els_gen_mother_py_ && b_pf_els_gen_mother_py_){
    b_pf_els_gen_mother_py_->GetEntry(entry_);
    c_pf_els_gen_mother_py_ = true;
  }
  return pf_els_gen_mother_py_;
}

std::vector<float>* const & cfa_8::pf_els_gen_mother_pz() const{
  if(!c_pf_els_gen_mother_pz_ && b_pf_els_gen_mother_pz_){
    b_pf_els_gen_mother_pz_->GetEntry(entry_);
    c_pf_els_gen_mother_pz_ = true;
  }
  return pf_els_gen_mother_pz_;
}

std::vector<float>* const & cfa_8::pf_els_gen_mother_theta() const{
  if(!c_pf_els_gen_mother_theta_ && b_pf_els_gen_mother_theta_){
    b_pf_els_gen_mother_theta_->GetEntry(entry_);
    c_pf_els_gen_mother_theta_ = true;
  }
  return pf_els_gen_mother_theta_;
}

std::vector<float>* const & cfa_8::pf_els_gen_phi() const{
  if(!c_pf_els_gen_phi_ && b_pf_els_gen_phi_){
    b_pf_els_gen_phi_->GetEntry(entry_);
    c_pf_els_gen_phi_ = true;
  }
  return pf_els_gen_phi_;
}

std::vector<float>* const & cfa_8::pf_els_gen_pt() const{
  if(!c_pf_els_gen_pt_ && b_pf_els_gen_pt_){
    b_pf_els_gen_pt_->GetEntry(entry_);
    c_pf_els_gen_pt_ = true;
  }
  return pf_els_gen_pt_;
}

std::vector<float>* const & cfa_8::pf_els_gen_px() const{
  if(!c_pf_els_gen_px_ && b_pf_els_gen_px_){
    b_pf_els_gen_px_->GetEntry(entry_);
    c_pf_els_gen_px_ = true;
  }
  return pf_els_gen_px_;
}

std::vector<float>* const & cfa_8::pf_els_gen_py() const{
  if(!c_pf_els_gen_py_ && b_pf_els_gen_py_){
    b_pf_els_gen_py_->GetEntry(entry_);
    c_pf_els_gen_py_ = true;
  }
  return pf_els_gen_py_;
}

std::vector<float>* const & cfa_8::pf_els_gen_pz() const{
  if(!c_pf_els_gen_pz_ && b_pf_els_gen_pz_){
    b_pf_els_gen_pz_->GetEntry(entry_);
    c_pf_els_gen_pz_ = true;
  }
  return pf_els_gen_pz_;
}

std::vector<float>* const & cfa_8::pf_els_gen_theta() const{
  if(!c_pf_els_gen_theta_ && b_pf_els_gen_theta_){
    b_pf_els_gen_theta_->GetEntry(entry_);
    c_pf_els_gen_theta_ = true;
  }
  return pf_els_gen_theta_;
}

std::vector<float>* const & cfa_8::pf_els_hadOverEm() const{
  if(!c_pf_els_hadOverEm_ && b_pf_els_hadOverEm_){
    b_pf_els_hadOverEm_->GetEntry(entry_);
    c_pf_els_hadOverEm_ = true;
  }
  return pf_els_hadOverEm_;
}

std::vector<bool>* const & cfa_8::pf_els_hasMatchedConversion() const{
  if(!c_pf_els_hasMatchedConversion_ && b_pf_els_hasMatchedConversion_){
    b_pf_els_hasMatchedConversion_->GetEntry(entry_);
    c_pf_els_hasMatchedConversion_ = true;
  }
  return pf_els_hasMatchedConversion_;
}

std::vector<float>* const & cfa_8::pf_els_hcalIso() const{
  if(!c_pf_els_hcalIso_ && b_pf_els_hcalIso_){
    b_pf_els_hcalIso_->GetEntry(entry_);
    c_pf_els_hcalIso_ = true;
  }
  return pf_els_hcalIso_;
}

std::vector<float>* const & cfa_8::pf_els_hcalOverEcalBc() const{
  if(!c_pf_els_hcalOverEcalBc_ && b_pf_els_hcalOverEcalBc_){
    b_pf_els_hcalOverEcalBc_->GetEntry(entry_);
    c_pf_els_hcalOverEcalBc_ = true;
  }
  return pf_els_hcalOverEcalBc_;
}

std::vector<float>* const & cfa_8::pf_els_isEB() const{
  if(!c_pf_els_isEB_ && b_pf_els_isEB_){
    b_pf_els_isEB_->GetEntry(entry_);
    c_pf_els_isEB_ = true;
  }
  return pf_els_isEB_;
}

std::vector<float>* const & cfa_8::pf_els_isEE() const{
  if(!c_pf_els_isEE_ && b_pf_els_isEE_){
    b_pf_els_isEE_->GetEntry(entry_);
    c_pf_els_isEE_ = true;
  }
  return pf_els_isEE_;
}

std::vector<float>* const & cfa_8::pf_els_looseId() const{
  if(!c_pf_els_looseId_ && b_pf_els_looseId_){
    b_pf_els_looseId_->GetEntry(entry_);
    c_pf_els_looseId_ = true;
  }
  return pf_els_looseId_;
}

std::vector<float>* const & cfa_8::pf_els_n_inner_layer() const{
  if(!c_pf_els_n_inner_layer_ && b_pf_els_n_inner_layer_){
    b_pf_els_n_inner_layer_->GetEntry(entry_);
    c_pf_els_n_inner_layer_ = true;
  }
  return pf_els_n_inner_layer_;
}

std::vector<float>* const & cfa_8::pf_els_n_outer_layer() const{
  if(!c_pf_els_n_outer_layer_ && b_pf_els_n_outer_layer_){
    b_pf_els_n_outer_layer_->GetEntry(entry_);
    c_pf_els_n_outer_layer_ = true;
  }
  return pf_els_n_outer_layer_;
}

std::vector<float>* const & cfa_8::pf_els_ndof() const{
  if(!c_pf_els_ndof_ && b_pf_els_ndof_){
    b_pf_els_ndof_->GetEntry(entry_);
    c_pf_els_ndof_ = true;
  }
  return pf_els_ndof_;
}

std::vector<float>* const & cfa_8::pf_els_neutralHadronIso() const{
  if(!c_pf_els_neutralHadronIso_ && b_pf_els_neutralHadronIso_){
    b_pf_els_neutralHadronIso_->GetEntry(entry_);
    c_pf_els_neutralHadronIso_ = true;
  }
  return pf_els_neutralHadronIso_;
}

std::vector<float>* const & cfa_8::pf_els_numlosthits() const{
  if(!c_pf_els_numlosthits_ && b_pf_els_numlosthits_){
    b_pf_els_numlosthits_->GetEntry(entry_);
    c_pf_els_numlosthits_ = true;
  }
  return pf_els_numlosthits_;
}

std::vector<float>* const & cfa_8::pf_els_numvalhits() const{
  if(!c_pf_els_numvalhits_ && b_pf_els_numvalhits_){
    b_pf_els_numvalhits_->GetEntry(entry_);
    c_pf_els_numvalhits_ = true;
  }
  return pf_els_numvalhits_;
}

std::vector<float>* const & cfa_8::pf_els_phi() const{
  if(!c_pf_els_phi_ && b_pf_els_phi_){
    b_pf_els_phi_->GetEntry(entry_);
    c_pf_els_phi_ = true;
  }
  return pf_els_phi_;
}

std::vector<float>* const & cfa_8::pf_els_phiError() const{
  if(!c_pf_els_phiError_ && b_pf_els_phiError_){
    b_pf_els_phiError_->GetEntry(entry_);
    c_pf_els_phiError_ = true;
  }
  return pf_els_phiError_;
}

std::vector<float>* const & cfa_8::pf_els_photonIso() const{
  if(!c_pf_els_photonIso_ && b_pf_els_photonIso_){
    b_pf_els_photonIso_->GetEntry(entry_);
    c_pf_els_photonIso_ = true;
  }
  return pf_els_photonIso_;
}

std::vector<float>* const & cfa_8::pf_els_pt() const{
  if(!c_pf_els_pt_ && b_pf_els_pt_){
    b_pf_els_pt_->GetEntry(entry_);
    c_pf_els_pt_ = true;
  }
  return pf_els_pt_;
}

std::vector<float>* const & cfa_8::pf_els_ptError() const{
  if(!c_pf_els_ptError_ && b_pf_els_ptError_){
    b_pf_els_ptError_->GetEntry(entry_);
    c_pf_els_ptError_ = true;
  }
  return pf_els_ptError_;
}

std::vector<float>* const & cfa_8::pf_els_px() const{
  if(!c_pf_els_px_ && b_pf_els_px_){
    b_pf_els_px_->GetEntry(entry_);
    c_pf_els_px_ = true;
  }
  return pf_els_px_;
}

std::vector<float>* const & cfa_8::pf_els_py() const{
  if(!c_pf_els_py_ && b_pf_els_py_){
    b_pf_els_py_->GetEntry(entry_);
    c_pf_els_py_ = true;
  }
  return pf_els_py_;
}

std::vector<float>* const & cfa_8::pf_els_pz() const{
  if(!c_pf_els_pz_ && b_pf_els_pz_){
    b_pf_els_pz_->GetEntry(entry_);
    c_pf_els_pz_ = true;
  }
  return pf_els_pz_;
}

std::vector<float>* const & cfa_8::pf_els_robustHighEnergyId() const{
  if(!c_pf_els_robustHighEnergyId_ && b_pf_els_robustHighEnergyId_){
    b_pf_els_robustHighEnergyId_->GetEntry(entry_);
    c_pf_els_robustHighEnergyId_ = true;
  }
  return pf_els_robustHighEnergyId_;
}

std::vector<float>* const & cfa_8::pf_els_robustLooseId() const{
  if(!c_pf_els_robustLooseId_ && b_pf_els_robustLooseId_){
    b_pf_els_robustLooseId_->GetEntry(entry_);
    c_pf_els_robustLooseId_ = true;
  }
  return pf_els_robustLooseId_;
}

std::vector<float>* const & cfa_8::pf_els_robustTightId() const{
  if(!c_pf_els_robustTightId_ && b_pf_els_robustTightId_){
    b_pf_els_robustTightId_->GetEntry(entry_);
    c_pf_els_robustTightId_ = true;
  }
  return pf_els_robustTightId_;
}

std::vector<float>* const & cfa_8::pf_els_scE1x5() const{
  if(!c_pf_els_scE1x5_ && b_pf_els_scE1x5_){
    b_pf_els_scE1x5_->GetEntry(entry_);
    c_pf_els_scE1x5_ = true;
  }
  return pf_els_scE1x5_;
}

std::vector<float>* const & cfa_8::pf_els_scE2x5Max() const{
  if(!c_pf_els_scE2x5Max_ && b_pf_els_scE2x5Max_){
    b_pf_els_scE2x5Max_->GetEntry(entry_);
    c_pf_els_scE2x5Max_ = true;
  }
  return pf_els_scE2x5Max_;
}

std::vector<float>* const & cfa_8::pf_els_scE5x5() const{
  if(!c_pf_els_scE5x5_ && b_pf_els_scE5x5_){
    b_pf_els_scE5x5_->GetEntry(entry_);
    c_pf_els_scE5x5_ = true;
  }
  return pf_els_scE5x5_;
}

std::vector<float>* const & cfa_8::pf_els_scEnergy() const{
  if(!c_pf_els_scEnergy_ && b_pf_els_scEnergy_){
    b_pf_els_scEnergy_->GetEntry(entry_);
    c_pf_els_scEnergy_ = true;
  }
  return pf_els_scEnergy_;
}

std::vector<float>* const & cfa_8::pf_els_scEta() const{
  if(!c_pf_els_scEta_ && b_pf_els_scEta_){
    b_pf_els_scEta_->GetEntry(entry_);
    c_pf_els_scEta_ = true;
  }
  return pf_els_scEta_;
}

std::vector<float>* const & cfa_8::pf_els_scEtaWidth() const{
  if(!c_pf_els_scEtaWidth_ && b_pf_els_scEtaWidth_){
    b_pf_els_scEtaWidth_->GetEntry(entry_);
    c_pf_els_scEtaWidth_ = true;
  }
  return pf_els_scEtaWidth_;
}

std::vector<float>* const & cfa_8::pf_els_scPhi() const{
  if(!c_pf_els_scPhi_ && b_pf_els_scPhi_){
    b_pf_els_scPhi_->GetEntry(entry_);
    c_pf_els_scPhi_ = true;
  }
  return pf_els_scPhi_;
}

std::vector<float>* const & cfa_8::pf_els_scPhiWidth() const{
  if(!c_pf_els_scPhiWidth_ && b_pf_els_scPhiWidth_){
    b_pf_els_scPhiWidth_->GetEntry(entry_);
    c_pf_els_scPhiWidth_ = true;
  }
  return pf_els_scPhiWidth_;
}

std::vector<float>* const & cfa_8::pf_els_scRawEnergy() const{
  if(!c_pf_els_scRawEnergy_ && b_pf_els_scRawEnergy_){
    b_pf_els_scRawEnergy_->GetEntry(entry_);
    c_pf_els_scRawEnergy_ = true;
  }
  return pf_els_scRawEnergy_;
}

std::vector<float>* const & cfa_8::pf_els_scSeedEnergy() const{
  if(!c_pf_els_scSeedEnergy_ && b_pf_els_scSeedEnergy_){
    b_pf_els_scSeedEnergy_->GetEntry(entry_);
    c_pf_els_scSeedEnergy_ = true;
  }
  return pf_els_scSeedEnergy_;
}

std::vector<float>* const & cfa_8::pf_els_shFracInnerHits() const{
  if(!c_pf_els_shFracInnerHits_ && b_pf_els_shFracInnerHits_){
    b_pf_els_shFracInnerHits_->GetEntry(entry_);
    c_pf_els_shFracInnerHits_ = true;
  }
  return pf_els_shFracInnerHits_;
}

std::vector<float>* const & cfa_8::pf_els_sigmaEtaEta() const{
  if(!c_pf_els_sigmaEtaEta_ && b_pf_els_sigmaEtaEta_){
    b_pf_els_sigmaEtaEta_->GetEntry(entry_);
    c_pf_els_sigmaEtaEta_ = true;
  }
  return pf_els_sigmaEtaEta_;
}

std::vector<float>* const & cfa_8::pf_els_sigmaIEtaIEta() const{
  if(!c_pf_els_sigmaIEtaIEta_ && b_pf_els_sigmaIEtaIEta_){
    b_pf_els_sigmaIEtaIEta_->GetEntry(entry_);
    c_pf_els_sigmaIEtaIEta_ = true;
  }
  return pf_els_sigmaIEtaIEta_;
}

std::vector<float>* const & cfa_8::pf_els_simpleEleId60cIso() const{
  if(!c_pf_els_simpleEleId60cIso_ && b_pf_els_simpleEleId60cIso_){
    b_pf_els_simpleEleId60cIso_->GetEntry(entry_);
    c_pf_els_simpleEleId60cIso_ = true;
  }
  return pf_els_simpleEleId60cIso_;
}

std::vector<float>* const & cfa_8::pf_els_simpleEleId60relIso() const{
  if(!c_pf_els_simpleEleId60relIso_ && b_pf_els_simpleEleId60relIso_){
    b_pf_els_simpleEleId60relIso_->GetEntry(entry_);
    c_pf_els_simpleEleId60relIso_ = true;
  }
  return pf_els_simpleEleId60relIso_;
}

std::vector<float>* const & cfa_8::pf_els_simpleEleId70cIso() const{
  if(!c_pf_els_simpleEleId70cIso_ && b_pf_els_simpleEleId70cIso_){
    b_pf_els_simpleEleId70cIso_->GetEntry(entry_);
    c_pf_els_simpleEleId70cIso_ = true;
  }
  return pf_els_simpleEleId70cIso_;
}

std::vector<float>* const & cfa_8::pf_els_simpleEleId70relIso() const{
  if(!c_pf_els_simpleEleId70relIso_ && b_pf_els_simpleEleId70relIso_){
    b_pf_els_simpleEleId70relIso_->GetEntry(entry_);
    c_pf_els_simpleEleId70relIso_ = true;
  }
  return pf_els_simpleEleId70relIso_;
}

std::vector<float>* const & cfa_8::pf_els_simpleEleId80cIso() const{
  if(!c_pf_els_simpleEleId80cIso_ && b_pf_els_simpleEleId80cIso_){
    b_pf_els_simpleEleId80cIso_->GetEntry(entry_);
    c_pf_els_simpleEleId80cIso_ = true;
  }
  return pf_els_simpleEleId80cIso_;
}

std::vector<float>* const & cfa_8::pf_els_simpleEleId80relIso() const{
  if(!c_pf_els_simpleEleId80relIso_ && b_pf_els_simpleEleId80relIso_){
    b_pf_els_simpleEleId80relIso_->GetEntry(entry_);
    c_pf_els_simpleEleId80relIso_ = true;
  }
  return pf_els_simpleEleId80relIso_;
}

std::vector<float>* const & cfa_8::pf_els_simpleEleId85cIso() const{
  if(!c_pf_els_simpleEleId85cIso_ && b_pf_els_simpleEleId85cIso_){
    b_pf_els_simpleEleId85cIso_->GetEntry(entry_);
    c_pf_els_simpleEleId85cIso_ = true;
  }
  return pf_els_simpleEleId85cIso_;
}

std::vector<float>* const & cfa_8::pf_els_simpleEleId85relIso() const{
  if(!c_pf_els_simpleEleId85relIso_ && b_pf_els_simpleEleId85relIso_){
    b_pf_els_simpleEleId85relIso_->GetEntry(entry_);
    c_pf_els_simpleEleId85relIso_ = true;
  }
  return pf_els_simpleEleId85relIso_;
}

std::vector<float>* const & cfa_8::pf_els_simpleEleId90cIso() const{
  if(!c_pf_els_simpleEleId90cIso_ && b_pf_els_simpleEleId90cIso_){
    b_pf_els_simpleEleId90cIso_->GetEntry(entry_);
    c_pf_els_simpleEleId90cIso_ = true;
  }
  return pf_els_simpleEleId90cIso_;
}

std::vector<float>* const & cfa_8::pf_els_simpleEleId90relIso() const{
  if(!c_pf_els_simpleEleId90relIso_ && b_pf_els_simpleEleId90relIso_){
    b_pf_els_simpleEleId90relIso_->GetEntry(entry_);
    c_pf_els_simpleEleId90relIso_ = true;
  }
  return pf_els_simpleEleId90relIso_;
}

std::vector<float>* const & cfa_8::pf_els_simpleEleId95cIso() const{
  if(!c_pf_els_simpleEleId95cIso_ && b_pf_els_simpleEleId95cIso_){
    b_pf_els_simpleEleId95cIso_->GetEntry(entry_);
    c_pf_els_simpleEleId95cIso_ = true;
  }
  return pf_els_simpleEleId95cIso_;
}

std::vector<float>* const & cfa_8::pf_els_simpleEleId95relIso() const{
  if(!c_pf_els_simpleEleId95relIso_ && b_pf_els_simpleEleId95relIso_){
    b_pf_els_simpleEleId95relIso_->GetEntry(entry_);
    c_pf_els_simpleEleId95relIso_ = true;
  }
  return pf_els_simpleEleId95relIso_;
}

std::vector<float>* const & cfa_8::pf_els_status() const{
  if(!c_pf_els_status_ && b_pf_els_status_){
    b_pf_els_status_->GetEntry(entry_);
    c_pf_els_status_ = true;
  }
  return pf_els_status_;
}

std::vector<float>* const & cfa_8::pf_els_tIso() const{
  if(!c_pf_els_tIso_ && b_pf_els_tIso_){
    b_pf_els_tIso_->GetEntry(entry_);
    c_pf_els_tIso_ = true;
  }
  return pf_els_tIso_;
}

std::vector<float>* const & cfa_8::pf_els_theta() const{
  if(!c_pf_els_theta_ && b_pf_els_theta_){
    b_pf_els_theta_->GetEntry(entry_);
    c_pf_els_theta_ = true;
  }
  return pf_els_theta_;
}

std::vector<float>* const & cfa_8::pf_els_tightId() const{
  if(!c_pf_els_tightId_ && b_pf_els_tightId_){
    b_pf_els_tightId_->GetEntry(entry_);
    c_pf_els_tightId_ = true;
  }
  return pf_els_tightId_;
}

std::vector<float>* const & cfa_8::pf_els_tk_charge() const{
  if(!c_pf_els_tk_charge_ && b_pf_els_tk_charge_){
    b_pf_els_tk_charge_->GetEntry(entry_);
    c_pf_els_tk_charge_ = true;
  }
  return pf_els_tk_charge_;
}

std::vector<float>* const & cfa_8::pf_els_tk_eta() const{
  if(!c_pf_els_tk_eta_ && b_pf_els_tk_eta_){
    b_pf_els_tk_eta_->GetEntry(entry_);
    c_pf_els_tk_eta_ = true;
  }
  return pf_els_tk_eta_;
}

std::vector<float>* const & cfa_8::pf_els_tk_phi() const{
  if(!c_pf_els_tk_phi_ && b_pf_els_tk_phi_){
    b_pf_els_tk_phi_->GetEntry(entry_);
    c_pf_els_tk_phi_ = true;
  }
  return pf_els_tk_phi_;
}

std::vector<float>* const & cfa_8::pf_els_tk_pt() const{
  if(!c_pf_els_tk_pt_ && b_pf_els_tk_pt_){
    b_pf_els_tk_pt_->GetEntry(entry_);
    c_pf_els_tk_pt_ = true;
  }
  return pf_els_tk_pt_;
}

std::vector<float>* const & cfa_8::pf_els_tk_pz() const{
  if(!c_pf_els_tk_pz_ && b_pf_els_tk_pz_){
    b_pf_els_tk_pz_->GetEntry(entry_);
    c_pf_els_tk_pz_ = true;
  }
  return pf_els_tk_pz_;
}

std::vector<float>* const & cfa_8::pf_els_vpx() const{
  if(!c_pf_els_vpx_ && b_pf_els_vpx_){
    b_pf_els_vpx_->GetEntry(entry_);
    c_pf_els_vpx_ = true;
  }
  return pf_els_vpx_;
}

std::vector<float>* const & cfa_8::pf_els_vpy() const{
  if(!c_pf_els_vpy_ && b_pf_els_vpy_){
    b_pf_els_vpy_->GetEntry(entry_);
    c_pf_els_vpy_ = true;
  }
  return pf_els_vpy_;
}

std::vector<float>* const & cfa_8::pf_els_vpz() const{
  if(!c_pf_els_vpz_ && b_pf_els_vpz_){
    b_pf_els_vpz_->GetEntry(entry_);
    c_pf_els_vpz_ = true;
  }
  return pf_els_vpz_;
}

std::vector<float>* const & cfa_8::pf_els_vx() const{
  if(!c_pf_els_vx_ && b_pf_els_vx_){
    b_pf_els_vx_->GetEntry(entry_);
    c_pf_els_vx_ = true;
  }
  return pf_els_vx_;
}

std::vector<float>* const & cfa_8::pf_els_vy() const{
  if(!c_pf_els_vy_ && b_pf_els_vy_){
    b_pf_els_vy_->GetEntry(entry_);
    c_pf_els_vy_ = true;
  }
  return pf_els_vy_;
}

std::vector<float>* const & cfa_8::pf_els_vz() const{
  if(!c_pf_els_vz_ && b_pf_els_vz_){
    b_pf_els_vz_->GetEntry(entry_);
    c_pf_els_vz_ = true;
  }
  return pf_els_vz_;
}

std::vector<float>* const & cfa_8::pf_mus_cIso() const{
  if(!c_pf_mus_cIso_ && b_pf_mus_cIso_){
    b_pf_mus_cIso_->GetEntry(entry_);
    c_pf_mus_cIso_ = true;
  }
  return pf_mus_cIso_;
}

std::vector<float>* const & cfa_8::pf_mus_calEnergyEm() const{
  if(!c_pf_mus_calEnergyEm_ && b_pf_mus_calEnergyEm_){
    b_pf_mus_calEnergyEm_->GetEntry(entry_);
    c_pf_mus_calEnergyEm_ = true;
  }
  return pf_mus_calEnergyEm_;
}

std::vector<float>* const & cfa_8::pf_mus_calEnergyEmS9() const{
  if(!c_pf_mus_calEnergyEmS9_ && b_pf_mus_calEnergyEmS9_){
    b_pf_mus_calEnergyEmS9_->GetEntry(entry_);
    c_pf_mus_calEnergyEmS9_ = true;
  }
  return pf_mus_calEnergyEmS9_;
}

std::vector<float>* const & cfa_8::pf_mus_calEnergyHad() const{
  if(!c_pf_mus_calEnergyHad_ && b_pf_mus_calEnergyHad_){
    b_pf_mus_calEnergyHad_->GetEntry(entry_);
    c_pf_mus_calEnergyHad_ = true;
  }
  return pf_mus_calEnergyHad_;
}

std::vector<float>* const & cfa_8::pf_mus_calEnergyHadS9() const{
  if(!c_pf_mus_calEnergyHadS9_ && b_pf_mus_calEnergyHadS9_){
    b_pf_mus_calEnergyHadS9_->GetEntry(entry_);
    c_pf_mus_calEnergyHadS9_ = true;
  }
  return pf_mus_calEnergyHadS9_;
}

std::vector<float>* const & cfa_8::pf_mus_calEnergyHo() const{
  if(!c_pf_mus_calEnergyHo_ && b_pf_mus_calEnergyHo_){
    b_pf_mus_calEnergyHo_->GetEntry(entry_);
    c_pf_mus_calEnergyHo_ = true;
  }
  return pf_mus_calEnergyHo_;
}

std::vector<float>* const & cfa_8::pf_mus_calEnergyHoS9() const{
  if(!c_pf_mus_calEnergyHoS9_ && b_pf_mus_calEnergyHoS9_){
    b_pf_mus_calEnergyHoS9_->GetEntry(entry_);
    c_pf_mus_calEnergyHoS9_ = true;
  }
  return pf_mus_calEnergyHoS9_;
}

std::vector<float>* const & cfa_8::pf_mus_charge() const{
  if(!c_pf_mus_charge_ && b_pf_mus_charge_){
    b_pf_mus_charge_->GetEntry(entry_);
    c_pf_mus_charge_ = true;
  }
  return pf_mus_charge_;
}

std::vector<float>* const & cfa_8::pf_mus_chargedHadronIso() const{
  if(!c_pf_mus_chargedHadronIso_ && b_pf_mus_chargedHadronIso_){
    b_pf_mus_chargedHadronIso_->GetEntry(entry_);
    c_pf_mus_chargedHadronIso_ = true;
  }
  return pf_mus_chargedHadronIso_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_ExpectedHitsInner() const{
  if(!c_pf_mus_cm_ExpectedHitsInner_ && b_pf_mus_cm_ExpectedHitsInner_){
    b_pf_mus_cm_ExpectedHitsInner_->GetEntry(entry_);
    c_pf_mus_cm_ExpectedHitsInner_ = true;
  }
  return pf_mus_cm_ExpectedHitsInner_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_ExpectedHitsOuter() const{
  if(!c_pf_mus_cm_ExpectedHitsOuter_ && b_pf_mus_cm_ExpectedHitsOuter_){
    b_pf_mus_cm_ExpectedHitsOuter_->GetEntry(entry_);
    c_pf_mus_cm_ExpectedHitsOuter_ = true;
  }
  return pf_mus_cm_ExpectedHitsOuter_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_LayersWithMeasurement() const{
  if(!c_pf_mus_cm_LayersWithMeasurement_ && b_pf_mus_cm_LayersWithMeasurement_){
    b_pf_mus_cm_LayersWithMeasurement_->GetEntry(entry_);
    c_pf_mus_cm_LayersWithMeasurement_ = true;
  }
  return pf_mus_cm_LayersWithMeasurement_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_LayersWithoutMeasurement() const{
  if(!c_pf_mus_cm_LayersWithoutMeasurement_ && b_pf_mus_cm_LayersWithoutMeasurement_){
    b_pf_mus_cm_LayersWithoutMeasurement_->GetEntry(entry_);
    c_pf_mus_cm_LayersWithoutMeasurement_ = true;
  }
  return pf_mus_cm_LayersWithoutMeasurement_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_PixelLayersWithMeasurement() const{
  if(!c_pf_mus_cm_PixelLayersWithMeasurement_ && b_pf_mus_cm_PixelLayersWithMeasurement_){
    b_pf_mus_cm_PixelLayersWithMeasurement_->GetEntry(entry_);
    c_pf_mus_cm_PixelLayersWithMeasurement_ = true;
  }
  return pf_mus_cm_PixelLayersWithMeasurement_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_ValidStripLayersWithMonoAndStereoHit() const{
  if(!c_pf_mus_cm_ValidStripLayersWithMonoAndStereoHit_ && b_pf_mus_cm_ValidStripLayersWithMonoAndStereoHit_){
    b_pf_mus_cm_ValidStripLayersWithMonoAndStereoHit_->GetEntry(entry_);
    c_pf_mus_cm_ValidStripLayersWithMonoAndStereoHit_ = true;
  }
  return pf_mus_cm_ValidStripLayersWithMonoAndStereoHit_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_chg() const{
  if(!c_pf_mus_cm_chg_ && b_pf_mus_cm_chg_){
    b_pf_mus_cm_chg_->GetEntry(entry_);
    c_pf_mus_cm_chg_ = true;
  }
  return pf_mus_cm_chg_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_chi2() const{
  if(!c_pf_mus_cm_chi2_ && b_pf_mus_cm_chi2_){
    b_pf_mus_cm_chi2_->GetEntry(entry_);
    c_pf_mus_cm_chi2_ = true;
  }
  return pf_mus_cm_chi2_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_d0dum() const{
  if(!c_pf_mus_cm_d0dum_ && b_pf_mus_cm_d0dum_){
    b_pf_mus_cm_d0dum_->GetEntry(entry_);
    c_pf_mus_cm_d0dum_ = true;
  }
  return pf_mus_cm_d0dum_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_d0dumErr() const{
  if(!c_pf_mus_cm_d0dumErr_ && b_pf_mus_cm_d0dumErr_){
    b_pf_mus_cm_d0dumErr_->GetEntry(entry_);
    c_pf_mus_cm_d0dumErr_ = true;
  }
  return pf_mus_cm_d0dumErr_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_dz() const{
  if(!c_pf_mus_cm_dz_ && b_pf_mus_cm_dz_){
    b_pf_mus_cm_dz_->GetEntry(entry_);
    c_pf_mus_cm_dz_ = true;
  }
  return pf_mus_cm_dz_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_dzErr() const{
  if(!c_pf_mus_cm_dzErr_ && b_pf_mus_cm_dzErr_){
    b_pf_mus_cm_dzErr_->GetEntry(entry_);
    c_pf_mus_cm_dzErr_ = true;
  }
  return pf_mus_cm_dzErr_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_eta() const{
  if(!c_pf_mus_cm_eta_ && b_pf_mus_cm_eta_){
    b_pf_mus_cm_eta_->GetEntry(entry_);
    c_pf_mus_cm_eta_ = true;
  }
  return pf_mus_cm_eta_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_etaErr() const{
  if(!c_pf_mus_cm_etaErr_ && b_pf_mus_cm_etaErr_){
    b_pf_mus_cm_etaErr_->GetEntry(entry_);
    c_pf_mus_cm_etaErr_ = true;
  }
  return pf_mus_cm_etaErr_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_ndof() const{
  if(!c_pf_mus_cm_ndof_ && b_pf_mus_cm_ndof_){
    b_pf_mus_cm_ndof_->GetEntry(entry_);
    c_pf_mus_cm_ndof_ = true;
  }
  return pf_mus_cm_ndof_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_numlosthits() const{
  if(!c_pf_mus_cm_numlosthits_ && b_pf_mus_cm_numlosthits_){
    b_pf_mus_cm_numlosthits_->GetEntry(entry_);
    c_pf_mus_cm_numlosthits_ = true;
  }
  return pf_mus_cm_numlosthits_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_numvalMuonhits() const{
  if(!c_pf_mus_cm_numvalMuonhits_ && b_pf_mus_cm_numvalMuonhits_){
    b_pf_mus_cm_numvalMuonhits_->GetEntry(entry_);
    c_pf_mus_cm_numvalMuonhits_ = true;
  }
  return pf_mus_cm_numvalMuonhits_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_numvalhits() const{
  if(!c_pf_mus_cm_numvalhits_ && b_pf_mus_cm_numvalhits_){
    b_pf_mus_cm_numvalhits_->GetEntry(entry_);
    c_pf_mus_cm_numvalhits_ = true;
  }
  return pf_mus_cm_numvalhits_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_phi() const{
  if(!c_pf_mus_cm_phi_ && b_pf_mus_cm_phi_){
    b_pf_mus_cm_phi_->GetEntry(entry_);
    c_pf_mus_cm_phi_ = true;
  }
  return pf_mus_cm_phi_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_phiErr() const{
  if(!c_pf_mus_cm_phiErr_ && b_pf_mus_cm_phiErr_){
    b_pf_mus_cm_phiErr_->GetEntry(entry_);
    c_pf_mus_cm_phiErr_ = true;
  }
  return pf_mus_cm_phiErr_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_pt() const{
  if(!c_pf_mus_cm_pt_ && b_pf_mus_cm_pt_){
    b_pf_mus_cm_pt_->GetEntry(entry_);
    c_pf_mus_cm_pt_ = true;
  }
  return pf_mus_cm_pt_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_ptErr() const{
  if(!c_pf_mus_cm_ptErr_ && b_pf_mus_cm_ptErr_){
    b_pf_mus_cm_ptErr_->GetEntry(entry_);
    c_pf_mus_cm_ptErr_ = true;
  }
  return pf_mus_cm_ptErr_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_px() const{
  if(!c_pf_mus_cm_px_ && b_pf_mus_cm_px_){
    b_pf_mus_cm_px_->GetEntry(entry_);
    c_pf_mus_cm_px_ = true;
  }
  return pf_mus_cm_px_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_py() const{
  if(!c_pf_mus_cm_py_ && b_pf_mus_cm_py_){
    b_pf_mus_cm_py_->GetEntry(entry_);
    c_pf_mus_cm_py_ = true;
  }
  return pf_mus_cm_py_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_pz() const{
  if(!c_pf_mus_cm_pz_ && b_pf_mus_cm_pz_){
    b_pf_mus_cm_pz_->GetEntry(entry_);
    c_pf_mus_cm_pz_ = true;
  }
  return pf_mus_cm_pz_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_theta() const{
  if(!c_pf_mus_cm_theta_ && b_pf_mus_cm_theta_){
    b_pf_mus_cm_theta_->GetEntry(entry_);
    c_pf_mus_cm_theta_ = true;
  }
  return pf_mus_cm_theta_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_vx() const{
  if(!c_pf_mus_cm_vx_ && b_pf_mus_cm_vx_){
    b_pf_mus_cm_vx_->GetEntry(entry_);
    c_pf_mus_cm_vx_ = true;
  }
  return pf_mus_cm_vx_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_vy() const{
  if(!c_pf_mus_cm_vy_ && b_pf_mus_cm_vy_){
    b_pf_mus_cm_vy_->GetEntry(entry_);
    c_pf_mus_cm_vy_ = true;
  }
  return pf_mus_cm_vy_;
}

std::vector<float>* const & cfa_8::pf_mus_cm_vz() const{
  if(!c_pf_mus_cm_vz_ && b_pf_mus_cm_vz_){
    b_pf_mus_cm_vz_->GetEntry(entry_);
    c_pf_mus_cm_vz_ = true;
  }
  return pf_mus_cm_vz_;
}

std::vector<float>* const & cfa_8::pf_mus_dB() const{
  if(!c_pf_mus_dB_ && b_pf_mus_dB_){
    b_pf_mus_dB_->GetEntry(entry_);
    c_pf_mus_dB_ = true;
  }
  return pf_mus_dB_;
}

std::vector<float>* const & cfa_8::pf_mus_ecalIso() const{
  if(!c_pf_mus_ecalIso_ && b_pf_mus_ecalIso_){
    b_pf_mus_ecalIso_->GetEntry(entry_);
    c_pf_mus_ecalIso_ = true;
  }
  return pf_mus_ecalIso_;
}

std::vector<float>* const & cfa_8::pf_mus_energy() const{
  if(!c_pf_mus_energy_ && b_pf_mus_energy_){
    b_pf_mus_energy_->GetEntry(entry_);
    c_pf_mus_energy_ = true;
  }
  return pf_mus_energy_;
}

std::vector<float>* const & cfa_8::pf_mus_et() const{
  if(!c_pf_mus_et_ && b_pf_mus_et_){
    b_pf_mus_et_->GetEntry(entry_);
    c_pf_mus_et_ = true;
  }
  return pf_mus_et_;
}

std::vector<float>* const & cfa_8::pf_mus_eta() const{
  if(!c_pf_mus_eta_ && b_pf_mus_eta_){
    b_pf_mus_eta_->GetEntry(entry_);
    c_pf_mus_eta_ = true;
  }
  return pf_mus_eta_;
}

std::vector<float>* const & cfa_8::pf_mus_gen_et() const{
  if(!c_pf_mus_gen_et_ && b_pf_mus_gen_et_){
    b_pf_mus_gen_et_->GetEntry(entry_);
    c_pf_mus_gen_et_ = true;
  }
  return pf_mus_gen_et_;
}

std::vector<float>* const & cfa_8::pf_mus_gen_eta() const{
  if(!c_pf_mus_gen_eta_ && b_pf_mus_gen_eta_){
    b_pf_mus_gen_eta_->GetEntry(entry_);
    c_pf_mus_gen_eta_ = true;
  }
  return pf_mus_gen_eta_;
}

std::vector<float>* const & cfa_8::pf_mus_gen_id() const{
  if(!c_pf_mus_gen_id_ && b_pf_mus_gen_id_){
    b_pf_mus_gen_id_->GetEntry(entry_);
    c_pf_mus_gen_id_ = true;
  }
  return pf_mus_gen_id_;
}

std::vector<float>* const & cfa_8::pf_mus_gen_mother_et() const{
  if(!c_pf_mus_gen_mother_et_ && b_pf_mus_gen_mother_et_){
    b_pf_mus_gen_mother_et_->GetEntry(entry_);
    c_pf_mus_gen_mother_et_ = true;
  }
  return pf_mus_gen_mother_et_;
}

std::vector<float>* const & cfa_8::pf_mus_gen_mother_eta() const{
  if(!c_pf_mus_gen_mother_eta_ && b_pf_mus_gen_mother_eta_){
    b_pf_mus_gen_mother_eta_->GetEntry(entry_);
    c_pf_mus_gen_mother_eta_ = true;
  }
  return pf_mus_gen_mother_eta_;
}

std::vector<float>* const & cfa_8::pf_mus_gen_mother_id() const{
  if(!c_pf_mus_gen_mother_id_ && b_pf_mus_gen_mother_id_){
    b_pf_mus_gen_mother_id_->GetEntry(entry_);
    c_pf_mus_gen_mother_id_ = true;
  }
  return pf_mus_gen_mother_id_;
}

std::vector<float>* const & cfa_8::pf_mus_gen_mother_phi() const{
  if(!c_pf_mus_gen_mother_phi_ && b_pf_mus_gen_mother_phi_){
    b_pf_mus_gen_mother_phi_->GetEntry(entry_);
    c_pf_mus_gen_mother_phi_ = true;
  }
  return pf_mus_gen_mother_phi_;
}

std::vector<float>* const & cfa_8::pf_mus_gen_mother_pt() const{
  if(!c_pf_mus_gen_mother_pt_ && b_pf_mus_gen_mother_pt_){
    b_pf_mus_gen_mother_pt_->GetEntry(entry_);
    c_pf_mus_gen_mother_pt_ = true;
  }
  return pf_mus_gen_mother_pt_;
}

std::vector<float>* const & cfa_8::pf_mus_gen_mother_px() const{
  if(!c_pf_mus_gen_mother_px_ && b_pf_mus_gen_mother_px_){
    b_pf_mus_gen_mother_px_->GetEntry(entry_);
    c_pf_mus_gen_mother_px_ = true;
  }
  return pf_mus_gen_mother_px_;
}

std::vector<float>* const & cfa_8::pf_mus_gen_mother_py() const{
  if(!c_pf_mus_gen_mother_py_ && b_pf_mus_gen_mother_py_){
    b_pf_mus_gen_mother_py_->GetEntry(entry_);
    c_pf_mus_gen_mother_py_ = true;
  }
  return pf_mus_gen_mother_py_;
}

std::vector<float>* const & cfa_8::pf_mus_gen_mother_pz() const{
  if(!c_pf_mus_gen_mother_pz_ && b_pf_mus_gen_mother_pz_){
    b_pf_mus_gen_mother_pz_->GetEntry(entry_);
    c_pf_mus_gen_mother_pz_ = true;
  }
  return pf_mus_gen_mother_pz_;
}

std::vector<float>* const & cfa_8::pf_mus_gen_mother_theta() const{
  if(!c_pf_mus_gen_mother_theta_ && b_pf_mus_gen_mother_theta_){
    b_pf_mus_gen_mother_theta_->GetEntry(entry_);
    c_pf_mus_gen_mother_theta_ = true;
  }
  return pf_mus_gen_mother_theta_;
}

std::vector<float>* const & cfa_8::pf_mus_gen_phi() const{
  if(!c_pf_mus_gen_phi_ && b_pf_mus_gen_phi_){
    b_pf_mus_gen_phi_->GetEntry(entry_);
    c_pf_mus_gen_phi_ = true;
  }
  return pf_mus_gen_phi_;
}

std::vector<float>* const & cfa_8::pf_mus_gen_pt() const{
  if(!c_pf_mus_gen_pt_ && b_pf_mus_gen_pt_){
    b_pf_mus_gen_pt_->GetEntry(entry_);
    c_pf_mus_gen_pt_ = true;
  }
  return pf_mus_gen_pt_;
}

std::vector<float>* const & cfa_8::pf_mus_gen_px() const{
  if(!c_pf_mus_gen_px_ && b_pf_mus_gen_px_){
    b_pf_mus_gen_px_->GetEntry(entry_);
    c_pf_mus_gen_px_ = true;
  }
  return pf_mus_gen_px_;
}

std::vector<float>* const & cfa_8::pf_mus_gen_py() const{
  if(!c_pf_mus_gen_py_ && b_pf_mus_gen_py_){
    b_pf_mus_gen_py_->GetEntry(entry_);
    c_pf_mus_gen_py_ = true;
  }
  return pf_mus_gen_py_;
}

std::vector<float>* const & cfa_8::pf_mus_gen_pz() const{
  if(!c_pf_mus_gen_pz_ && b_pf_mus_gen_pz_){
    b_pf_mus_gen_pz_->GetEntry(entry_);
    c_pf_mus_gen_pz_ = true;
  }
  return pf_mus_gen_pz_;
}

std::vector<float>* const & cfa_8::pf_mus_gen_theta() const{
  if(!c_pf_mus_gen_theta_ && b_pf_mus_gen_theta_){
    b_pf_mus_gen_theta_->GetEntry(entry_);
    c_pf_mus_gen_theta_ = true;
  }
  return pf_mus_gen_theta_;
}

std::vector<float>* const & cfa_8::pf_mus_hcalIso() const{
  if(!c_pf_mus_hcalIso_ && b_pf_mus_hcalIso_){
    b_pf_mus_hcalIso_->GetEntry(entry_);
    c_pf_mus_hcalIso_ = true;
  }
  return pf_mus_hcalIso_;
}

std::vector<float>* const & cfa_8::pf_mus_id_All() const{
  if(!c_pf_mus_id_All_ && b_pf_mus_id_All_){
    b_pf_mus_id_All_->GetEntry(entry_);
    c_pf_mus_id_All_ = true;
  }
  return pf_mus_id_All_;
}

std::vector<float>* const & cfa_8::pf_mus_id_AllArbitrated() const{
  if(!c_pf_mus_id_AllArbitrated_ && b_pf_mus_id_AllArbitrated_){
    b_pf_mus_id_AllArbitrated_->GetEntry(entry_);
    c_pf_mus_id_AllArbitrated_ = true;
  }
  return pf_mus_id_AllArbitrated_;
}

std::vector<float>* const & cfa_8::pf_mus_id_AllGlobalMuons() const{
  if(!c_pf_mus_id_AllGlobalMuons_ && b_pf_mus_id_AllGlobalMuons_){
    b_pf_mus_id_AllGlobalMuons_->GetEntry(entry_);
    c_pf_mus_id_AllGlobalMuons_ = true;
  }
  return pf_mus_id_AllGlobalMuons_;
}

std::vector<float>* const & cfa_8::pf_mus_id_AllStandAloneMuons() const{
  if(!c_pf_mus_id_AllStandAloneMuons_ && b_pf_mus_id_AllStandAloneMuons_){
    b_pf_mus_id_AllStandAloneMuons_->GetEntry(entry_);
    c_pf_mus_id_AllStandAloneMuons_ = true;
  }
  return pf_mus_id_AllStandAloneMuons_;
}

std::vector<float>* const & cfa_8::pf_mus_id_AllTrackerMuons() const{
  if(!c_pf_mus_id_AllTrackerMuons_ && b_pf_mus_id_AllTrackerMuons_){
    b_pf_mus_id_AllTrackerMuons_->GetEntry(entry_);
    c_pf_mus_id_AllTrackerMuons_ = true;
  }
  return pf_mus_id_AllTrackerMuons_;
}

std::vector<float>* const & cfa_8::pf_mus_id_GlobalMuonPromptTight() const{
  if(!c_pf_mus_id_GlobalMuonPromptTight_ && b_pf_mus_id_GlobalMuonPromptTight_){
    b_pf_mus_id_GlobalMuonPromptTight_->GetEntry(entry_);
    c_pf_mus_id_GlobalMuonPromptTight_ = true;
  }
  return pf_mus_id_GlobalMuonPromptTight_;
}

std::vector<float>* const & cfa_8::pf_mus_id_TM2DCompatibilityLoose() const{
  if(!c_pf_mus_id_TM2DCompatibilityLoose_ && b_pf_mus_id_TM2DCompatibilityLoose_){
    b_pf_mus_id_TM2DCompatibilityLoose_->GetEntry(entry_);
    c_pf_mus_id_TM2DCompatibilityLoose_ = true;
  }
  return pf_mus_id_TM2DCompatibilityLoose_;
}

std::vector<float>* const & cfa_8::pf_mus_id_TM2DCompatibilityTight() const{
  if(!c_pf_mus_id_TM2DCompatibilityTight_ && b_pf_mus_id_TM2DCompatibilityTight_){
    b_pf_mus_id_TM2DCompatibilityTight_->GetEntry(entry_);
    c_pf_mus_id_TM2DCompatibilityTight_ = true;
  }
  return pf_mus_id_TM2DCompatibilityTight_;
}

std::vector<float>* const & cfa_8::pf_mus_id_TMLastStationLoose() const{
  if(!c_pf_mus_id_TMLastStationLoose_ && b_pf_mus_id_TMLastStationLoose_){
    b_pf_mus_id_TMLastStationLoose_->GetEntry(entry_);
    c_pf_mus_id_TMLastStationLoose_ = true;
  }
  return pf_mus_id_TMLastStationLoose_;
}

std::vector<float>* const & cfa_8::pf_mus_id_TMLastStationOptimizedLowPtLoose() const{
  if(!c_pf_mus_id_TMLastStationOptimizedLowPtLoose_ && b_pf_mus_id_TMLastStationOptimizedLowPtLoose_){
    b_pf_mus_id_TMLastStationOptimizedLowPtLoose_->GetEntry(entry_);
    c_pf_mus_id_TMLastStationOptimizedLowPtLoose_ = true;
  }
  return pf_mus_id_TMLastStationOptimizedLowPtLoose_;
}

std::vector<float>* const & cfa_8::pf_mus_id_TMLastStationOptimizedLowPtTight() const{
  if(!c_pf_mus_id_TMLastStationOptimizedLowPtTight_ && b_pf_mus_id_TMLastStationOptimizedLowPtTight_){
    b_pf_mus_id_TMLastStationOptimizedLowPtTight_->GetEntry(entry_);
    c_pf_mus_id_TMLastStationOptimizedLowPtTight_ = true;
  }
  return pf_mus_id_TMLastStationOptimizedLowPtTight_;
}

std::vector<float>* const & cfa_8::pf_mus_id_TMLastStationTight() const{
  if(!c_pf_mus_id_TMLastStationTight_ && b_pf_mus_id_TMLastStationTight_){
    b_pf_mus_id_TMLastStationTight_->GetEntry(entry_);
    c_pf_mus_id_TMLastStationTight_ = true;
  }
  return pf_mus_id_TMLastStationTight_;
}

std::vector<float>* const & cfa_8::pf_mus_id_TMOneStationLoose() const{
  if(!c_pf_mus_id_TMOneStationLoose_ && b_pf_mus_id_TMOneStationLoose_){
    b_pf_mus_id_TMOneStationLoose_->GetEntry(entry_);
    c_pf_mus_id_TMOneStationLoose_ = true;
  }
  return pf_mus_id_TMOneStationLoose_;
}

std::vector<float>* const & cfa_8::pf_mus_id_TMOneStationTight() const{
  if(!c_pf_mus_id_TMOneStationTight_ && b_pf_mus_id_TMOneStationTight_){
    b_pf_mus_id_TMOneStationTight_->GetEntry(entry_);
    c_pf_mus_id_TMOneStationTight_ = true;
  }
  return pf_mus_id_TMOneStationTight_;
}

std::vector<float>* const & cfa_8::pf_mus_id_TrackerMuonArbitrated() const{
  if(!c_pf_mus_id_TrackerMuonArbitrated_ && b_pf_mus_id_TrackerMuonArbitrated_){
    b_pf_mus_id_TrackerMuonArbitrated_->GetEntry(entry_);
    c_pf_mus_id_TrackerMuonArbitrated_ = true;
  }
  return pf_mus_id_TrackerMuonArbitrated_;
}

std::vector<float>* const & cfa_8::pf_mus_isCaloMuon() const{
  if(!c_pf_mus_isCaloMuon_ && b_pf_mus_isCaloMuon_){
    b_pf_mus_isCaloMuon_->GetEntry(entry_);
    c_pf_mus_isCaloMuon_ = true;
  }
  return pf_mus_isCaloMuon_;
}

std::vector<float>* const & cfa_8::pf_mus_isConvertedPhoton() const{
  if(!c_pf_mus_isConvertedPhoton_ && b_pf_mus_isConvertedPhoton_){
    b_pf_mus_isConvertedPhoton_->GetEntry(entry_);
    c_pf_mus_isConvertedPhoton_ = true;
  }
  return pf_mus_isConvertedPhoton_;
}

std::vector<float>* const & cfa_8::pf_mus_isElectron() const{
  if(!c_pf_mus_isElectron_ && b_pf_mus_isElectron_){
    b_pf_mus_isElectron_->GetEntry(entry_);
    c_pf_mus_isElectron_ = true;
  }
  return pf_mus_isElectron_;
}

std::vector<float>* const & cfa_8::pf_mus_isGlobalMuon() const{
  if(!c_pf_mus_isGlobalMuon_ && b_pf_mus_isGlobalMuon_){
    b_pf_mus_isGlobalMuon_->GetEntry(entry_);
    c_pf_mus_isGlobalMuon_ = true;
  }
  return pf_mus_isGlobalMuon_;
}

std::vector<float>* const & cfa_8::pf_mus_isPFMuon() const{
  if(!c_pf_mus_isPFMuon_ && b_pf_mus_isPFMuon_){
    b_pf_mus_isPFMuon_->GetEntry(entry_);
    c_pf_mus_isPFMuon_ = true;
  }
  return pf_mus_isPFMuon_;
}

std::vector<float>* const & cfa_8::pf_mus_isPhoton() const{
  if(!c_pf_mus_isPhoton_ && b_pf_mus_isPhoton_){
    b_pf_mus_isPhoton_->GetEntry(entry_);
    c_pf_mus_isPhoton_ = true;
  }
  return pf_mus_isPhoton_;
}

std::vector<float>* const & cfa_8::pf_mus_isStandAloneMuon() const{
  if(!c_pf_mus_isStandAloneMuon_ && b_pf_mus_isStandAloneMuon_){
    b_pf_mus_isStandAloneMuon_->GetEntry(entry_);
    c_pf_mus_isStandAloneMuon_ = true;
  }
  return pf_mus_isStandAloneMuon_;
}

std::vector<float>* const & cfa_8::pf_mus_isTrackerMuon() const{
  if(!c_pf_mus_isTrackerMuon_ && b_pf_mus_isTrackerMuon_){
    b_pf_mus_isTrackerMuon_->GetEntry(entry_);
    c_pf_mus_isTrackerMuon_ = true;
  }
  return pf_mus_isTrackerMuon_;
}

std::vector<float>* const & cfa_8::pf_mus_iso03_emEt() const{
  if(!c_pf_mus_iso03_emEt_ && b_pf_mus_iso03_emEt_){
    b_pf_mus_iso03_emEt_->GetEntry(entry_);
    c_pf_mus_iso03_emEt_ = true;
  }
  return pf_mus_iso03_emEt_;
}

std::vector<float>* const & cfa_8::pf_mus_iso03_emVetoEt() const{
  if(!c_pf_mus_iso03_emVetoEt_ && b_pf_mus_iso03_emVetoEt_){
    b_pf_mus_iso03_emVetoEt_->GetEntry(entry_);
    c_pf_mus_iso03_emVetoEt_ = true;
  }
  return pf_mus_iso03_emVetoEt_;
}

std::vector<float>* const & cfa_8::pf_mus_iso03_hadEt() const{
  if(!c_pf_mus_iso03_hadEt_ && b_pf_mus_iso03_hadEt_){
    b_pf_mus_iso03_hadEt_->GetEntry(entry_);
    c_pf_mus_iso03_hadEt_ = true;
  }
  return pf_mus_iso03_hadEt_;
}

std::vector<float>* const & cfa_8::pf_mus_iso03_hadVetoEt() const{
  if(!c_pf_mus_iso03_hadVetoEt_ && b_pf_mus_iso03_hadVetoEt_){
    b_pf_mus_iso03_hadVetoEt_->GetEntry(entry_);
    c_pf_mus_iso03_hadVetoEt_ = true;
  }
  return pf_mus_iso03_hadVetoEt_;
}

std::vector<float>* const & cfa_8::pf_mus_iso03_hoEt() const{
  if(!c_pf_mus_iso03_hoEt_ && b_pf_mus_iso03_hoEt_){
    b_pf_mus_iso03_hoEt_->GetEntry(entry_);
    c_pf_mus_iso03_hoEt_ = true;
  }
  return pf_mus_iso03_hoEt_;
}

std::vector<float>* const & cfa_8::pf_mus_iso03_nTracks() const{
  if(!c_pf_mus_iso03_nTracks_ && b_pf_mus_iso03_nTracks_){
    b_pf_mus_iso03_nTracks_->GetEntry(entry_);
    c_pf_mus_iso03_nTracks_ = true;
  }
  return pf_mus_iso03_nTracks_;
}

std::vector<float>* const & cfa_8::pf_mus_iso03_sumPt() const{
  if(!c_pf_mus_iso03_sumPt_ && b_pf_mus_iso03_sumPt_){
    b_pf_mus_iso03_sumPt_->GetEntry(entry_);
    c_pf_mus_iso03_sumPt_ = true;
  }
  return pf_mus_iso03_sumPt_;
}

std::vector<float>* const & cfa_8::pf_mus_iso05_emEt() const{
  if(!c_pf_mus_iso05_emEt_ && b_pf_mus_iso05_emEt_){
    b_pf_mus_iso05_emEt_->GetEntry(entry_);
    c_pf_mus_iso05_emEt_ = true;
  }
  return pf_mus_iso05_emEt_;
}

std::vector<float>* const & cfa_8::pf_mus_iso05_hadEt() const{
  if(!c_pf_mus_iso05_hadEt_ && b_pf_mus_iso05_hadEt_){
    b_pf_mus_iso05_hadEt_->GetEntry(entry_);
    c_pf_mus_iso05_hadEt_ = true;
  }
  return pf_mus_iso05_hadEt_;
}

std::vector<float>* const & cfa_8::pf_mus_iso05_hoEt() const{
  if(!c_pf_mus_iso05_hoEt_ && b_pf_mus_iso05_hoEt_){
    b_pf_mus_iso05_hoEt_->GetEntry(entry_);
    c_pf_mus_iso05_hoEt_ = true;
  }
  return pf_mus_iso05_hoEt_;
}

std::vector<float>* const & cfa_8::pf_mus_iso05_nTracks() const{
  if(!c_pf_mus_iso05_nTracks_ && b_pf_mus_iso05_nTracks_){
    b_pf_mus_iso05_nTracks_->GetEntry(entry_);
    c_pf_mus_iso05_nTracks_ = true;
  }
  return pf_mus_iso05_nTracks_;
}

std::vector<float>* const & cfa_8::pf_mus_iso05_sumPt() const{
  if(!c_pf_mus_iso05_sumPt_ && b_pf_mus_iso05_sumPt_){
    b_pf_mus_iso05_sumPt_->GetEntry(entry_);
    c_pf_mus_iso05_sumPt_ = true;
  }
  return pf_mus_iso05_sumPt_;
}

std::vector<float>* const & cfa_8::pf_mus_neutralHadronIso() const{
  if(!c_pf_mus_neutralHadronIso_ && b_pf_mus_neutralHadronIso_){
    b_pf_mus_neutralHadronIso_->GetEntry(entry_);
    c_pf_mus_neutralHadronIso_ = true;
  }
  return pf_mus_neutralHadronIso_;
}

std::vector<float>* const & cfa_8::pf_mus_num_matches() const{
  if(!c_pf_mus_num_matches_ && b_pf_mus_num_matches_){
    b_pf_mus_num_matches_->GetEntry(entry_);
    c_pf_mus_num_matches_ = true;
  }
  return pf_mus_num_matches_;
}

std::vector<float>* const & cfa_8::pf_mus_numberOfMatchedStations() const{
  if(!c_pf_mus_numberOfMatchedStations_ && b_pf_mus_numberOfMatchedStations_){
    b_pf_mus_numberOfMatchedStations_->GetEntry(entry_);
    c_pf_mus_numberOfMatchedStations_ = true;
  }
  return pf_mus_numberOfMatchedStations_;
}

std::vector<float>* const & cfa_8::pf_mus_pfIsolationR03_sumChargedHadronPt() const{
  if(!c_pf_mus_pfIsolationR03_sumChargedHadronPt_ && b_pf_mus_pfIsolationR03_sumChargedHadronPt_){
    b_pf_mus_pfIsolationR03_sumChargedHadronPt_->GetEntry(entry_);
    c_pf_mus_pfIsolationR03_sumChargedHadronPt_ = true;
  }
  return pf_mus_pfIsolationR03_sumChargedHadronPt_;
}

std::vector<float>* const & cfa_8::pf_mus_pfIsolationR03_sumChargedParticlePt() const{
  if(!c_pf_mus_pfIsolationR03_sumChargedParticlePt_ && b_pf_mus_pfIsolationR03_sumChargedParticlePt_){
    b_pf_mus_pfIsolationR03_sumChargedParticlePt_->GetEntry(entry_);
    c_pf_mus_pfIsolationR03_sumChargedParticlePt_ = true;
  }
  return pf_mus_pfIsolationR03_sumChargedParticlePt_;
}

std::vector<float>* const & cfa_8::pf_mus_pfIsolationR03_sumNeutralHadronEt() const{
  if(!c_pf_mus_pfIsolationR03_sumNeutralHadronEt_ && b_pf_mus_pfIsolationR03_sumNeutralHadronEt_){
    b_pf_mus_pfIsolationR03_sumNeutralHadronEt_->GetEntry(entry_);
    c_pf_mus_pfIsolationR03_sumNeutralHadronEt_ = true;
  }
  return pf_mus_pfIsolationR03_sumNeutralHadronEt_;
}

std::vector<float>* const & cfa_8::pf_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold() const{
  if(!c_pf_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_ && b_pf_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_){
    b_pf_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_->GetEntry(entry_);
    c_pf_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_ = true;
  }
  return pf_mus_pfIsolationR03_sumNeutralHadronEtHighThreshold_;
}

std::vector<float>* const & cfa_8::pf_mus_pfIsolationR03_sumPUPt() const{
  if(!c_pf_mus_pfIsolationR03_sumPUPt_ && b_pf_mus_pfIsolationR03_sumPUPt_){
    b_pf_mus_pfIsolationR03_sumPUPt_->GetEntry(entry_);
    c_pf_mus_pfIsolationR03_sumPUPt_ = true;
  }
  return pf_mus_pfIsolationR03_sumPUPt_;
}

std::vector<float>* const & cfa_8::pf_mus_pfIsolationR03_sumPhotonEt() const{
  if(!c_pf_mus_pfIsolationR03_sumPhotonEt_ && b_pf_mus_pfIsolationR03_sumPhotonEt_){
    b_pf_mus_pfIsolationR03_sumPhotonEt_->GetEntry(entry_);
    c_pf_mus_pfIsolationR03_sumPhotonEt_ = true;
  }
  return pf_mus_pfIsolationR03_sumPhotonEt_;
}

std::vector<float>* const & cfa_8::pf_mus_pfIsolationR03_sumPhotonEtHighThreshold() const{
  if(!c_pf_mus_pfIsolationR03_sumPhotonEtHighThreshold_ && b_pf_mus_pfIsolationR03_sumPhotonEtHighThreshold_){
    b_pf_mus_pfIsolationR03_sumPhotonEtHighThreshold_->GetEntry(entry_);
    c_pf_mus_pfIsolationR03_sumPhotonEtHighThreshold_ = true;
  }
  return pf_mus_pfIsolationR03_sumPhotonEtHighThreshold_;
}

std::vector<float>* const & cfa_8::pf_mus_pfIsolationR04_sumChargedHadronPt() const{
  if(!c_pf_mus_pfIsolationR04_sumChargedHadronPt_ && b_pf_mus_pfIsolationR04_sumChargedHadronPt_){
    b_pf_mus_pfIsolationR04_sumChargedHadronPt_->GetEntry(entry_);
    c_pf_mus_pfIsolationR04_sumChargedHadronPt_ = true;
  }
  return pf_mus_pfIsolationR04_sumChargedHadronPt_;
}

std::vector<float>* const & cfa_8::pf_mus_pfIsolationR04_sumChargedParticlePt() const{
  if(!c_pf_mus_pfIsolationR04_sumChargedParticlePt_ && b_pf_mus_pfIsolationR04_sumChargedParticlePt_){
    b_pf_mus_pfIsolationR04_sumChargedParticlePt_->GetEntry(entry_);
    c_pf_mus_pfIsolationR04_sumChargedParticlePt_ = true;
  }
  return pf_mus_pfIsolationR04_sumChargedParticlePt_;
}

std::vector<float>* const & cfa_8::pf_mus_pfIsolationR04_sumNeutralHadronEt() const{
  if(!c_pf_mus_pfIsolationR04_sumNeutralHadronEt_ && b_pf_mus_pfIsolationR04_sumNeutralHadronEt_){
    b_pf_mus_pfIsolationR04_sumNeutralHadronEt_->GetEntry(entry_);
    c_pf_mus_pfIsolationR04_sumNeutralHadronEt_ = true;
  }
  return pf_mus_pfIsolationR04_sumNeutralHadronEt_;
}

std::vector<float>* const & cfa_8::pf_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold() const{
  if(!c_pf_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_ && b_pf_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_){
    b_pf_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_->GetEntry(entry_);
    c_pf_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_ = true;
  }
  return pf_mus_pfIsolationR04_sumNeutralHadronEtHighThreshold_;
}

std::vector<float>* const & cfa_8::pf_mus_pfIsolationR04_sumPUPt() const{
  if(!c_pf_mus_pfIsolationR04_sumPUPt_ && b_pf_mus_pfIsolationR04_sumPUPt_){
    b_pf_mus_pfIsolationR04_sumPUPt_->GetEntry(entry_);
    c_pf_mus_pfIsolationR04_sumPUPt_ = true;
  }
  return pf_mus_pfIsolationR04_sumPUPt_;
}

std::vector<float>* const & cfa_8::pf_mus_pfIsolationR04_sumPhotonEt() const{
  if(!c_pf_mus_pfIsolationR04_sumPhotonEt_ && b_pf_mus_pfIsolationR04_sumPhotonEt_){
    b_pf_mus_pfIsolationR04_sumPhotonEt_->GetEntry(entry_);
    c_pf_mus_pfIsolationR04_sumPhotonEt_ = true;
  }
  return pf_mus_pfIsolationR04_sumPhotonEt_;
}

std::vector<float>* const & cfa_8::pf_mus_pfIsolationR04_sumPhotonEtHighThreshold() const{
  if(!c_pf_mus_pfIsolationR04_sumPhotonEtHighThreshold_ && b_pf_mus_pfIsolationR04_sumPhotonEtHighThreshold_){
    b_pf_mus_pfIsolationR04_sumPhotonEtHighThreshold_->GetEntry(entry_);
    c_pf_mus_pfIsolationR04_sumPhotonEtHighThreshold_ = true;
  }
  return pf_mus_pfIsolationR04_sumPhotonEtHighThreshold_;
}

std::vector<float>* const & cfa_8::pf_mus_phi() const{
  if(!c_pf_mus_phi_ && b_pf_mus_phi_){
    b_pf_mus_phi_->GetEntry(entry_);
    c_pf_mus_phi_ = true;
  }
  return pf_mus_phi_;
}

std::vector<float>* const & cfa_8::pf_mus_photonIso() const{
  if(!c_pf_mus_photonIso_ && b_pf_mus_photonIso_){
    b_pf_mus_photonIso_->GetEntry(entry_);
    c_pf_mus_photonIso_ = true;
  }
  return pf_mus_photonIso_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_ExpectedHitsInner() const{
  if(!c_pf_mus_picky_ExpectedHitsInner_ && b_pf_mus_picky_ExpectedHitsInner_){
    b_pf_mus_picky_ExpectedHitsInner_->GetEntry(entry_);
    c_pf_mus_picky_ExpectedHitsInner_ = true;
  }
  return pf_mus_picky_ExpectedHitsInner_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_ExpectedHitsOuter() const{
  if(!c_pf_mus_picky_ExpectedHitsOuter_ && b_pf_mus_picky_ExpectedHitsOuter_){
    b_pf_mus_picky_ExpectedHitsOuter_->GetEntry(entry_);
    c_pf_mus_picky_ExpectedHitsOuter_ = true;
  }
  return pf_mus_picky_ExpectedHitsOuter_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_LayersWithMeasurement() const{
  if(!c_pf_mus_picky_LayersWithMeasurement_ && b_pf_mus_picky_LayersWithMeasurement_){
    b_pf_mus_picky_LayersWithMeasurement_->GetEntry(entry_);
    c_pf_mus_picky_LayersWithMeasurement_ = true;
  }
  return pf_mus_picky_LayersWithMeasurement_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_LayersWithoutMeasurement() const{
  if(!c_pf_mus_picky_LayersWithoutMeasurement_ && b_pf_mus_picky_LayersWithoutMeasurement_){
    b_pf_mus_picky_LayersWithoutMeasurement_->GetEntry(entry_);
    c_pf_mus_picky_LayersWithoutMeasurement_ = true;
  }
  return pf_mus_picky_LayersWithoutMeasurement_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_PixelLayersWithMeasurement() const{
  if(!c_pf_mus_picky_PixelLayersWithMeasurement_ && b_pf_mus_picky_PixelLayersWithMeasurement_){
    b_pf_mus_picky_PixelLayersWithMeasurement_->GetEntry(entry_);
    c_pf_mus_picky_PixelLayersWithMeasurement_ = true;
  }
  return pf_mus_picky_PixelLayersWithMeasurement_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_ValidStripLayersWithMonoAndStereoHit() const{
  if(!c_pf_mus_picky_ValidStripLayersWithMonoAndStereoHit_ && b_pf_mus_picky_ValidStripLayersWithMonoAndStereoHit_){
    b_pf_mus_picky_ValidStripLayersWithMonoAndStereoHit_->GetEntry(entry_);
    c_pf_mus_picky_ValidStripLayersWithMonoAndStereoHit_ = true;
  }
  return pf_mus_picky_ValidStripLayersWithMonoAndStereoHit_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_chg() const{
  if(!c_pf_mus_picky_chg_ && b_pf_mus_picky_chg_){
    b_pf_mus_picky_chg_->GetEntry(entry_);
    c_pf_mus_picky_chg_ = true;
  }
  return pf_mus_picky_chg_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_chi2() const{
  if(!c_pf_mus_picky_chi2_ && b_pf_mus_picky_chi2_){
    b_pf_mus_picky_chi2_->GetEntry(entry_);
    c_pf_mus_picky_chi2_ = true;
  }
  return pf_mus_picky_chi2_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_d0dum() const{
  if(!c_pf_mus_picky_d0dum_ && b_pf_mus_picky_d0dum_){
    b_pf_mus_picky_d0dum_->GetEntry(entry_);
    c_pf_mus_picky_d0dum_ = true;
  }
  return pf_mus_picky_d0dum_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_d0dumErr() const{
  if(!c_pf_mus_picky_d0dumErr_ && b_pf_mus_picky_d0dumErr_){
    b_pf_mus_picky_d0dumErr_->GetEntry(entry_);
    c_pf_mus_picky_d0dumErr_ = true;
  }
  return pf_mus_picky_d0dumErr_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_dz() const{
  if(!c_pf_mus_picky_dz_ && b_pf_mus_picky_dz_){
    b_pf_mus_picky_dz_->GetEntry(entry_);
    c_pf_mus_picky_dz_ = true;
  }
  return pf_mus_picky_dz_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_dzErr() const{
  if(!c_pf_mus_picky_dzErr_ && b_pf_mus_picky_dzErr_){
    b_pf_mus_picky_dzErr_->GetEntry(entry_);
    c_pf_mus_picky_dzErr_ = true;
  }
  return pf_mus_picky_dzErr_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_eta() const{
  if(!c_pf_mus_picky_eta_ && b_pf_mus_picky_eta_){
    b_pf_mus_picky_eta_->GetEntry(entry_);
    c_pf_mus_picky_eta_ = true;
  }
  return pf_mus_picky_eta_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_etaErr() const{
  if(!c_pf_mus_picky_etaErr_ && b_pf_mus_picky_etaErr_){
    b_pf_mus_picky_etaErr_->GetEntry(entry_);
    c_pf_mus_picky_etaErr_ = true;
  }
  return pf_mus_picky_etaErr_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_id() const{
  if(!c_pf_mus_picky_id_ && b_pf_mus_picky_id_){
    b_pf_mus_picky_id_->GetEntry(entry_);
    c_pf_mus_picky_id_ = true;
  }
  return pf_mus_picky_id_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_ndof() const{
  if(!c_pf_mus_picky_ndof_ && b_pf_mus_picky_ndof_){
    b_pf_mus_picky_ndof_->GetEntry(entry_);
    c_pf_mus_picky_ndof_ = true;
  }
  return pf_mus_picky_ndof_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_numlosthits() const{
  if(!c_pf_mus_picky_numlosthits_ && b_pf_mus_picky_numlosthits_){
    b_pf_mus_picky_numlosthits_->GetEntry(entry_);
    c_pf_mus_picky_numlosthits_ = true;
  }
  return pf_mus_picky_numlosthits_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_numvalPixelhits() const{
  if(!c_pf_mus_picky_numvalPixelhits_ && b_pf_mus_picky_numvalPixelhits_){
    b_pf_mus_picky_numvalPixelhits_->GetEntry(entry_);
    c_pf_mus_picky_numvalPixelhits_ = true;
  }
  return pf_mus_picky_numvalPixelhits_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_numvalhits() const{
  if(!c_pf_mus_picky_numvalhits_ && b_pf_mus_picky_numvalhits_){
    b_pf_mus_picky_numvalhits_->GetEntry(entry_);
    c_pf_mus_picky_numvalhits_ = true;
  }
  return pf_mus_picky_numvalhits_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_phi() const{
  if(!c_pf_mus_picky_phi_ && b_pf_mus_picky_phi_){
    b_pf_mus_picky_phi_->GetEntry(entry_);
    c_pf_mus_picky_phi_ = true;
  }
  return pf_mus_picky_phi_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_phiErr() const{
  if(!c_pf_mus_picky_phiErr_ && b_pf_mus_picky_phiErr_){
    b_pf_mus_picky_phiErr_->GetEntry(entry_);
    c_pf_mus_picky_phiErr_ = true;
  }
  return pf_mus_picky_phiErr_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_pt() const{
  if(!c_pf_mus_picky_pt_ && b_pf_mus_picky_pt_){
    b_pf_mus_picky_pt_->GetEntry(entry_);
    c_pf_mus_picky_pt_ = true;
  }
  return pf_mus_picky_pt_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_ptErr() const{
  if(!c_pf_mus_picky_ptErr_ && b_pf_mus_picky_ptErr_){
    b_pf_mus_picky_ptErr_->GetEntry(entry_);
    c_pf_mus_picky_ptErr_ = true;
  }
  return pf_mus_picky_ptErr_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_px() const{
  if(!c_pf_mus_picky_px_ && b_pf_mus_picky_px_){
    b_pf_mus_picky_px_->GetEntry(entry_);
    c_pf_mus_picky_px_ = true;
  }
  return pf_mus_picky_px_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_py() const{
  if(!c_pf_mus_picky_py_ && b_pf_mus_picky_py_){
    b_pf_mus_picky_py_->GetEntry(entry_);
    c_pf_mus_picky_py_ = true;
  }
  return pf_mus_picky_py_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_pz() const{
  if(!c_pf_mus_picky_pz_ && b_pf_mus_picky_pz_){
    b_pf_mus_picky_pz_->GetEntry(entry_);
    c_pf_mus_picky_pz_ = true;
  }
  return pf_mus_picky_pz_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_theta() const{
  if(!c_pf_mus_picky_theta_ && b_pf_mus_picky_theta_){
    b_pf_mus_picky_theta_->GetEntry(entry_);
    c_pf_mus_picky_theta_ = true;
  }
  return pf_mus_picky_theta_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_vx() const{
  if(!c_pf_mus_picky_vx_ && b_pf_mus_picky_vx_){
    b_pf_mus_picky_vx_->GetEntry(entry_);
    c_pf_mus_picky_vx_ = true;
  }
  return pf_mus_picky_vx_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_vy() const{
  if(!c_pf_mus_picky_vy_ && b_pf_mus_picky_vy_){
    b_pf_mus_picky_vy_->GetEntry(entry_);
    c_pf_mus_picky_vy_ = true;
  }
  return pf_mus_picky_vy_;
}

std::vector<float>* const & cfa_8::pf_mus_picky_vz() const{
  if(!c_pf_mus_picky_vz_ && b_pf_mus_picky_vz_){
    b_pf_mus_picky_vz_->GetEntry(entry_);
    c_pf_mus_picky_vz_ = true;
  }
  return pf_mus_picky_vz_;
}

std::vector<float>* const & cfa_8::pf_mus_pt() const{
  if(!c_pf_mus_pt_ && b_pf_mus_pt_){
    b_pf_mus_pt_->GetEntry(entry_);
    c_pf_mus_pt_ = true;
  }
  return pf_mus_pt_;
}

std::vector<float>* const & cfa_8::pf_mus_px() const{
  if(!c_pf_mus_px_ && b_pf_mus_px_){
    b_pf_mus_px_->GetEntry(entry_);
    c_pf_mus_px_ = true;
  }
  return pf_mus_px_;
}

std::vector<float>* const & cfa_8::pf_mus_py() const{
  if(!c_pf_mus_py_ && b_pf_mus_py_){
    b_pf_mus_py_->GetEntry(entry_);
    c_pf_mus_py_ = true;
  }
  return pf_mus_py_;
}

std::vector<float>* const & cfa_8::pf_mus_pz() const{
  if(!c_pf_mus_pz_ && b_pf_mus_pz_){
    b_pf_mus_pz_->GetEntry(entry_);
    c_pf_mus_pz_ = true;
  }
  return pf_mus_pz_;
}

std::vector<float>* const & cfa_8::pf_mus_stamu_chg() const{
  if(!c_pf_mus_stamu_chg_ && b_pf_mus_stamu_chg_){
    b_pf_mus_stamu_chg_->GetEntry(entry_);
    c_pf_mus_stamu_chg_ = true;
  }
  return pf_mus_stamu_chg_;
}

std::vector<float>* const & cfa_8::pf_mus_stamu_chi2() const{
  if(!c_pf_mus_stamu_chi2_ && b_pf_mus_stamu_chi2_){
    b_pf_mus_stamu_chi2_->GetEntry(entry_);
    c_pf_mus_stamu_chi2_ = true;
  }
  return pf_mus_stamu_chi2_;
}

std::vector<float>* const & cfa_8::pf_mus_stamu_d0dum() const{
  if(!c_pf_mus_stamu_d0dum_ && b_pf_mus_stamu_d0dum_){
    b_pf_mus_stamu_d0dum_->GetEntry(entry_);
    c_pf_mus_stamu_d0dum_ = true;
  }
  return pf_mus_stamu_d0dum_;
}

std::vector<float>* const & cfa_8::pf_mus_stamu_d0dumErr() const{
  if(!c_pf_mus_stamu_d0dumErr_ && b_pf_mus_stamu_d0dumErr_){
    b_pf_mus_stamu_d0dumErr_->GetEntry(entry_);
    c_pf_mus_stamu_d0dumErr_ = true;
  }
  return pf_mus_stamu_d0dumErr_;
}

std::vector<float>* const & cfa_8::pf_mus_stamu_dz() const{
  if(!c_pf_mus_stamu_dz_ && b_pf_mus_stamu_dz_){
    b_pf_mus_stamu_dz_->GetEntry(entry_);
    c_pf_mus_stamu_dz_ = true;
  }
  return pf_mus_stamu_dz_;
}

std::vector<float>* const & cfa_8::pf_mus_stamu_dzErr() const{
  if(!c_pf_mus_stamu_dzErr_ && b_pf_mus_stamu_dzErr_){
    b_pf_mus_stamu_dzErr_->GetEntry(entry_);
    c_pf_mus_stamu_dzErr_ = true;
  }
  return pf_mus_stamu_dzErr_;
}

std::vector<float>* const & cfa_8::pf_mus_stamu_eta() const{
  if(!c_pf_mus_stamu_eta_ && b_pf_mus_stamu_eta_){
    b_pf_mus_stamu_eta_->GetEntry(entry_);
    c_pf_mus_stamu_eta_ = true;
  }
  return pf_mus_stamu_eta_;
}

std::vector<float>* const & cfa_8::pf_mus_stamu_etaErr() const{
  if(!c_pf_mus_stamu_etaErr_ && b_pf_mus_stamu_etaErr_){
    b_pf_mus_stamu_etaErr_->GetEntry(entry_);
    c_pf_mus_stamu_etaErr_ = true;
  }
  return pf_mus_stamu_etaErr_;
}

std::vector<float>* const & cfa_8::pf_mus_stamu_ndof() const{
  if(!c_pf_mus_stamu_ndof_ && b_pf_mus_stamu_ndof_){
    b_pf_mus_stamu_ndof_->GetEntry(entry_);
    c_pf_mus_stamu_ndof_ = true;
  }
  return pf_mus_stamu_ndof_;
}

std::vector<float>* const & cfa_8::pf_mus_stamu_numlosthits() const{
  if(!c_pf_mus_stamu_numlosthits_ && b_pf_mus_stamu_numlosthits_){
    b_pf_mus_stamu_numlosthits_->GetEntry(entry_);
    c_pf_mus_stamu_numlosthits_ = true;
  }
  return pf_mus_stamu_numlosthits_;
}

std::vector<float>* const & cfa_8::pf_mus_stamu_numvalhits() const{
  if(!c_pf_mus_stamu_numvalhits_ && b_pf_mus_stamu_numvalhits_){
    b_pf_mus_stamu_numvalhits_->GetEntry(entry_);
    c_pf_mus_stamu_numvalhits_ = true;
  }
  return pf_mus_stamu_numvalhits_;
}

std::vector<float>* const & cfa_8::pf_mus_stamu_phi() const{
  if(!c_pf_mus_stamu_phi_ && b_pf_mus_stamu_phi_){
    b_pf_mus_stamu_phi_->GetEntry(entry_);
    c_pf_mus_stamu_phi_ = true;
  }
  return pf_mus_stamu_phi_;
}

std::vector<float>* const & cfa_8::pf_mus_stamu_phiErr() const{
  if(!c_pf_mus_stamu_phiErr_ && b_pf_mus_stamu_phiErr_){
    b_pf_mus_stamu_phiErr_->GetEntry(entry_);
    c_pf_mus_stamu_phiErr_ = true;
  }
  return pf_mus_stamu_phiErr_;
}

std::vector<float>* const & cfa_8::pf_mus_stamu_pt() const{
  if(!c_pf_mus_stamu_pt_ && b_pf_mus_stamu_pt_){
    b_pf_mus_stamu_pt_->GetEntry(entry_);
    c_pf_mus_stamu_pt_ = true;
  }
  return pf_mus_stamu_pt_;
}

std::vector<float>* const & cfa_8::pf_mus_stamu_ptErr() const{
  if(!c_pf_mus_stamu_ptErr_ && b_pf_mus_stamu_ptErr_){
    b_pf_mus_stamu_ptErr_->GetEntry(entry_);
    c_pf_mus_stamu_ptErr_ = true;
  }
  return pf_mus_stamu_ptErr_;
}

std::vector<float>* const & cfa_8::pf_mus_stamu_px() const{
  if(!c_pf_mus_stamu_px_ && b_pf_mus_stamu_px_){
    b_pf_mus_stamu_px_->GetEntry(entry_);
    c_pf_mus_stamu_px_ = true;
  }
  return pf_mus_stamu_px_;
}

std::vector<float>* const & cfa_8::pf_mus_stamu_py() const{
  if(!c_pf_mus_stamu_py_ && b_pf_mus_stamu_py_){
    b_pf_mus_stamu_py_->GetEntry(entry_);
    c_pf_mus_stamu_py_ = true;
  }
  return pf_mus_stamu_py_;
}

std::vector<float>* const & cfa_8::pf_mus_stamu_pz() const{
  if(!c_pf_mus_stamu_pz_ && b_pf_mus_stamu_pz_){
    b_pf_mus_stamu_pz_->GetEntry(entry_);
    c_pf_mus_stamu_pz_ = true;
  }
  return pf_mus_stamu_pz_;
}

std::vector<float>* const & cfa_8::pf_mus_stamu_theta() const{
  if(!c_pf_mus_stamu_theta_ && b_pf_mus_stamu_theta_){
    b_pf_mus_stamu_theta_->GetEntry(entry_);
    c_pf_mus_stamu_theta_ = true;
  }
  return pf_mus_stamu_theta_;
}

std::vector<float>* const & cfa_8::pf_mus_stamu_vx() const{
  if(!c_pf_mus_stamu_vx_ && b_pf_mus_stamu_vx_){
    b_pf_mus_stamu_vx_->GetEntry(entry_);
    c_pf_mus_stamu_vx_ = true;
  }
  return pf_mus_stamu_vx_;
}

std::vector<float>* const & cfa_8::pf_mus_stamu_vy() const{
  if(!c_pf_mus_stamu_vy_ && b_pf_mus_stamu_vy_){
    b_pf_mus_stamu_vy_->GetEntry(entry_);
    c_pf_mus_stamu_vy_ = true;
  }
  return pf_mus_stamu_vy_;
}

std::vector<float>* const & cfa_8::pf_mus_stamu_vz() const{
  if(!c_pf_mus_stamu_vz_ && b_pf_mus_stamu_vz_){
    b_pf_mus_stamu_vz_->GetEntry(entry_);
    c_pf_mus_stamu_vz_ = true;
  }
  return pf_mus_stamu_vz_;
}

std::vector<float>* const & cfa_8::pf_mus_status() const{
  if(!c_pf_mus_status_ && b_pf_mus_status_){
    b_pf_mus_status_->GetEntry(entry_);
    c_pf_mus_status_ = true;
  }
  return pf_mus_status_;
}

std::vector<float>* const & cfa_8::pf_mus_tIso() const{
  if(!c_pf_mus_tIso_ && b_pf_mus_tIso_){
    b_pf_mus_tIso_->GetEntry(entry_);
    c_pf_mus_tIso_ = true;
  }
  return pf_mus_tIso_;
}

std::vector<float>* const & cfa_8::pf_mus_theta() const{
  if(!c_pf_mus_theta_ && b_pf_mus_theta_){
    b_pf_mus_theta_->GetEntry(entry_);
    c_pf_mus_theta_ = true;
  }
  return pf_mus_theta_;
}

std::vector<float>* const & cfa_8::pf_mus_tkHits() const{
  if(!c_pf_mus_tkHits_ && b_pf_mus_tkHits_){
    b_pf_mus_tkHits_->GetEntry(entry_);
    c_pf_mus_tkHits_ = true;
  }
  return pf_mus_tkHits_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_ExpectedHitsInner() const{
  if(!c_pf_mus_tk_ExpectedHitsInner_ && b_pf_mus_tk_ExpectedHitsInner_){
    b_pf_mus_tk_ExpectedHitsInner_->GetEntry(entry_);
    c_pf_mus_tk_ExpectedHitsInner_ = true;
  }
  return pf_mus_tk_ExpectedHitsInner_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_ExpectedHitsOuter() const{
  if(!c_pf_mus_tk_ExpectedHitsOuter_ && b_pf_mus_tk_ExpectedHitsOuter_){
    b_pf_mus_tk_ExpectedHitsOuter_->GetEntry(entry_);
    c_pf_mus_tk_ExpectedHitsOuter_ = true;
  }
  return pf_mus_tk_ExpectedHitsOuter_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_LayersWithMeasurement() const{
  if(!c_pf_mus_tk_LayersWithMeasurement_ && b_pf_mus_tk_LayersWithMeasurement_){
    b_pf_mus_tk_LayersWithMeasurement_->GetEntry(entry_);
    c_pf_mus_tk_LayersWithMeasurement_ = true;
  }
  return pf_mus_tk_LayersWithMeasurement_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_LayersWithoutMeasurement() const{
  if(!c_pf_mus_tk_LayersWithoutMeasurement_ && b_pf_mus_tk_LayersWithoutMeasurement_){
    b_pf_mus_tk_LayersWithoutMeasurement_->GetEntry(entry_);
    c_pf_mus_tk_LayersWithoutMeasurement_ = true;
  }
  return pf_mus_tk_LayersWithoutMeasurement_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_PixelLayersWithMeasurement() const{
  if(!c_pf_mus_tk_PixelLayersWithMeasurement_ && b_pf_mus_tk_PixelLayersWithMeasurement_){
    b_pf_mus_tk_PixelLayersWithMeasurement_->GetEntry(entry_);
    c_pf_mus_tk_PixelLayersWithMeasurement_ = true;
  }
  return pf_mus_tk_PixelLayersWithMeasurement_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_ValidStripLayersWithMonoAndStereoHit() const{
  if(!c_pf_mus_tk_ValidStripLayersWithMonoAndStereoHit_ && b_pf_mus_tk_ValidStripLayersWithMonoAndStereoHit_){
    b_pf_mus_tk_ValidStripLayersWithMonoAndStereoHit_->GetEntry(entry_);
    c_pf_mus_tk_ValidStripLayersWithMonoAndStereoHit_ = true;
  }
  return pf_mus_tk_ValidStripLayersWithMonoAndStereoHit_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_chg() const{
  if(!c_pf_mus_tk_chg_ && b_pf_mus_tk_chg_){
    b_pf_mus_tk_chg_->GetEntry(entry_);
    c_pf_mus_tk_chg_ = true;
  }
  return pf_mus_tk_chg_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_chi2() const{
  if(!c_pf_mus_tk_chi2_ && b_pf_mus_tk_chi2_){
    b_pf_mus_tk_chi2_->GetEntry(entry_);
    c_pf_mus_tk_chi2_ = true;
  }
  return pf_mus_tk_chi2_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_d0dum() const{
  if(!c_pf_mus_tk_d0dum_ && b_pf_mus_tk_d0dum_){
    b_pf_mus_tk_d0dum_->GetEntry(entry_);
    c_pf_mus_tk_d0dum_ = true;
  }
  return pf_mus_tk_d0dum_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_d0dumErr() const{
  if(!c_pf_mus_tk_d0dumErr_ && b_pf_mus_tk_d0dumErr_){
    b_pf_mus_tk_d0dumErr_->GetEntry(entry_);
    c_pf_mus_tk_d0dumErr_ = true;
  }
  return pf_mus_tk_d0dumErr_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_dz() const{
  if(!c_pf_mus_tk_dz_ && b_pf_mus_tk_dz_){
    b_pf_mus_tk_dz_->GetEntry(entry_);
    c_pf_mus_tk_dz_ = true;
  }
  return pf_mus_tk_dz_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_dzErr() const{
  if(!c_pf_mus_tk_dzErr_ && b_pf_mus_tk_dzErr_){
    b_pf_mus_tk_dzErr_->GetEntry(entry_);
    c_pf_mus_tk_dzErr_ = true;
  }
  return pf_mus_tk_dzErr_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_eta() const{
  if(!c_pf_mus_tk_eta_ && b_pf_mus_tk_eta_){
    b_pf_mus_tk_eta_->GetEntry(entry_);
    c_pf_mus_tk_eta_ = true;
  }
  return pf_mus_tk_eta_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_etaErr() const{
  if(!c_pf_mus_tk_etaErr_ && b_pf_mus_tk_etaErr_){
    b_pf_mus_tk_etaErr_->GetEntry(entry_);
    c_pf_mus_tk_etaErr_ = true;
  }
  return pf_mus_tk_etaErr_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_id() const{
  if(!c_pf_mus_tk_id_ && b_pf_mus_tk_id_){
    b_pf_mus_tk_id_->GetEntry(entry_);
    c_pf_mus_tk_id_ = true;
  }
  return pf_mus_tk_id_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_ndof() const{
  if(!c_pf_mus_tk_ndof_ && b_pf_mus_tk_ndof_){
    b_pf_mus_tk_ndof_->GetEntry(entry_);
    c_pf_mus_tk_ndof_ = true;
  }
  return pf_mus_tk_ndof_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_numlosthits() const{
  if(!c_pf_mus_tk_numlosthits_ && b_pf_mus_tk_numlosthits_){
    b_pf_mus_tk_numlosthits_->GetEntry(entry_);
    c_pf_mus_tk_numlosthits_ = true;
  }
  return pf_mus_tk_numlosthits_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_numpixelWthMeasr() const{
  if(!c_pf_mus_tk_numpixelWthMeasr_ && b_pf_mus_tk_numpixelWthMeasr_){
    b_pf_mus_tk_numpixelWthMeasr_->GetEntry(entry_);
    c_pf_mus_tk_numpixelWthMeasr_ = true;
  }
  return pf_mus_tk_numpixelWthMeasr_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_numvalPixelhits() const{
  if(!c_pf_mus_tk_numvalPixelhits_ && b_pf_mus_tk_numvalPixelhits_){
    b_pf_mus_tk_numvalPixelhits_->GetEntry(entry_);
    c_pf_mus_tk_numvalPixelhits_ = true;
  }
  return pf_mus_tk_numvalPixelhits_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_numvalhits() const{
  if(!c_pf_mus_tk_numvalhits_ && b_pf_mus_tk_numvalhits_){
    b_pf_mus_tk_numvalhits_->GetEntry(entry_);
    c_pf_mus_tk_numvalhits_ = true;
  }
  return pf_mus_tk_numvalhits_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_phi() const{
  if(!c_pf_mus_tk_phi_ && b_pf_mus_tk_phi_){
    b_pf_mus_tk_phi_->GetEntry(entry_);
    c_pf_mus_tk_phi_ = true;
  }
  return pf_mus_tk_phi_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_phiErr() const{
  if(!c_pf_mus_tk_phiErr_ && b_pf_mus_tk_phiErr_){
    b_pf_mus_tk_phiErr_->GetEntry(entry_);
    c_pf_mus_tk_phiErr_ = true;
  }
  return pf_mus_tk_phiErr_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_pt() const{
  if(!c_pf_mus_tk_pt_ && b_pf_mus_tk_pt_){
    b_pf_mus_tk_pt_->GetEntry(entry_);
    c_pf_mus_tk_pt_ = true;
  }
  return pf_mus_tk_pt_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_ptErr() const{
  if(!c_pf_mus_tk_ptErr_ && b_pf_mus_tk_ptErr_){
    b_pf_mus_tk_ptErr_->GetEntry(entry_);
    c_pf_mus_tk_ptErr_ = true;
  }
  return pf_mus_tk_ptErr_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_px() const{
  if(!c_pf_mus_tk_px_ && b_pf_mus_tk_px_){
    b_pf_mus_tk_px_->GetEntry(entry_);
    c_pf_mus_tk_px_ = true;
  }
  return pf_mus_tk_px_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_py() const{
  if(!c_pf_mus_tk_py_ && b_pf_mus_tk_py_){
    b_pf_mus_tk_py_->GetEntry(entry_);
    c_pf_mus_tk_py_ = true;
  }
  return pf_mus_tk_py_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_pz() const{
  if(!c_pf_mus_tk_pz_ && b_pf_mus_tk_pz_){
    b_pf_mus_tk_pz_->GetEntry(entry_);
    c_pf_mus_tk_pz_ = true;
  }
  return pf_mus_tk_pz_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_theta() const{
  if(!c_pf_mus_tk_theta_ && b_pf_mus_tk_theta_){
    b_pf_mus_tk_theta_->GetEntry(entry_);
    c_pf_mus_tk_theta_ = true;
  }
  return pf_mus_tk_theta_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_vx() const{
  if(!c_pf_mus_tk_vx_ && b_pf_mus_tk_vx_){
    b_pf_mus_tk_vx_->GetEntry(entry_);
    c_pf_mus_tk_vx_ = true;
  }
  return pf_mus_tk_vx_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_vy() const{
  if(!c_pf_mus_tk_vy_ && b_pf_mus_tk_vy_){
    b_pf_mus_tk_vy_->GetEntry(entry_);
    c_pf_mus_tk_vy_ = true;
  }
  return pf_mus_tk_vy_;
}

std::vector<float>* const & cfa_8::pf_mus_tk_vz() const{
  if(!c_pf_mus_tk_vz_ && b_pf_mus_tk_vz_){
    b_pf_mus_tk_vz_->GetEntry(entry_);
    c_pf_mus_tk_vz_ = true;
  }
  return pf_mus_tk_vz_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_ExpectedHitsInner() const{
  if(!c_pf_mus_tpfms_ExpectedHitsInner_ && b_pf_mus_tpfms_ExpectedHitsInner_){
    b_pf_mus_tpfms_ExpectedHitsInner_->GetEntry(entry_);
    c_pf_mus_tpfms_ExpectedHitsInner_ = true;
  }
  return pf_mus_tpfms_ExpectedHitsInner_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_ExpectedHitsOuter() const{
  if(!c_pf_mus_tpfms_ExpectedHitsOuter_ && b_pf_mus_tpfms_ExpectedHitsOuter_){
    b_pf_mus_tpfms_ExpectedHitsOuter_->GetEntry(entry_);
    c_pf_mus_tpfms_ExpectedHitsOuter_ = true;
  }
  return pf_mus_tpfms_ExpectedHitsOuter_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_LayersWithMeasurement() const{
  if(!c_pf_mus_tpfms_LayersWithMeasurement_ && b_pf_mus_tpfms_LayersWithMeasurement_){
    b_pf_mus_tpfms_LayersWithMeasurement_->GetEntry(entry_);
    c_pf_mus_tpfms_LayersWithMeasurement_ = true;
  }
  return pf_mus_tpfms_LayersWithMeasurement_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_LayersWithoutMeasurement() const{
  if(!c_pf_mus_tpfms_LayersWithoutMeasurement_ && b_pf_mus_tpfms_LayersWithoutMeasurement_){
    b_pf_mus_tpfms_LayersWithoutMeasurement_->GetEntry(entry_);
    c_pf_mus_tpfms_LayersWithoutMeasurement_ = true;
  }
  return pf_mus_tpfms_LayersWithoutMeasurement_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_PixelLayersWithMeasurement() const{
  if(!c_pf_mus_tpfms_PixelLayersWithMeasurement_ && b_pf_mus_tpfms_PixelLayersWithMeasurement_){
    b_pf_mus_tpfms_PixelLayersWithMeasurement_->GetEntry(entry_);
    c_pf_mus_tpfms_PixelLayersWithMeasurement_ = true;
  }
  return pf_mus_tpfms_PixelLayersWithMeasurement_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_ValidStripLayersWithMonoAndStereoHit() const{
  if(!c_pf_mus_tpfms_ValidStripLayersWithMonoAndStereoHit_ && b_pf_mus_tpfms_ValidStripLayersWithMonoAndStereoHit_){
    b_pf_mus_tpfms_ValidStripLayersWithMonoAndStereoHit_->GetEntry(entry_);
    c_pf_mus_tpfms_ValidStripLayersWithMonoAndStereoHit_ = true;
  }
  return pf_mus_tpfms_ValidStripLayersWithMonoAndStereoHit_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_chg() const{
  if(!c_pf_mus_tpfms_chg_ && b_pf_mus_tpfms_chg_){
    b_pf_mus_tpfms_chg_->GetEntry(entry_);
    c_pf_mus_tpfms_chg_ = true;
  }
  return pf_mus_tpfms_chg_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_chi2() const{
  if(!c_pf_mus_tpfms_chi2_ && b_pf_mus_tpfms_chi2_){
    b_pf_mus_tpfms_chi2_->GetEntry(entry_);
    c_pf_mus_tpfms_chi2_ = true;
  }
  return pf_mus_tpfms_chi2_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_d0dum() const{
  if(!c_pf_mus_tpfms_d0dum_ && b_pf_mus_tpfms_d0dum_){
    b_pf_mus_tpfms_d0dum_->GetEntry(entry_);
    c_pf_mus_tpfms_d0dum_ = true;
  }
  return pf_mus_tpfms_d0dum_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_d0dumErr() const{
  if(!c_pf_mus_tpfms_d0dumErr_ && b_pf_mus_tpfms_d0dumErr_){
    b_pf_mus_tpfms_d0dumErr_->GetEntry(entry_);
    c_pf_mus_tpfms_d0dumErr_ = true;
  }
  return pf_mus_tpfms_d0dumErr_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_dz() const{
  if(!c_pf_mus_tpfms_dz_ && b_pf_mus_tpfms_dz_){
    b_pf_mus_tpfms_dz_->GetEntry(entry_);
    c_pf_mus_tpfms_dz_ = true;
  }
  return pf_mus_tpfms_dz_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_dzErr() const{
  if(!c_pf_mus_tpfms_dzErr_ && b_pf_mus_tpfms_dzErr_){
    b_pf_mus_tpfms_dzErr_->GetEntry(entry_);
    c_pf_mus_tpfms_dzErr_ = true;
  }
  return pf_mus_tpfms_dzErr_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_eta() const{
  if(!c_pf_mus_tpfms_eta_ && b_pf_mus_tpfms_eta_){
    b_pf_mus_tpfms_eta_->GetEntry(entry_);
    c_pf_mus_tpfms_eta_ = true;
  }
  return pf_mus_tpfms_eta_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_etaErr() const{
  if(!c_pf_mus_tpfms_etaErr_ && b_pf_mus_tpfms_etaErr_){
    b_pf_mus_tpfms_etaErr_->GetEntry(entry_);
    c_pf_mus_tpfms_etaErr_ = true;
  }
  return pf_mus_tpfms_etaErr_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_id() const{
  if(!c_pf_mus_tpfms_id_ && b_pf_mus_tpfms_id_){
    b_pf_mus_tpfms_id_->GetEntry(entry_);
    c_pf_mus_tpfms_id_ = true;
  }
  return pf_mus_tpfms_id_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_ndof() const{
  if(!c_pf_mus_tpfms_ndof_ && b_pf_mus_tpfms_ndof_){
    b_pf_mus_tpfms_ndof_->GetEntry(entry_);
    c_pf_mus_tpfms_ndof_ = true;
  }
  return pf_mus_tpfms_ndof_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_numlosthits() const{
  if(!c_pf_mus_tpfms_numlosthits_ && b_pf_mus_tpfms_numlosthits_){
    b_pf_mus_tpfms_numlosthits_->GetEntry(entry_);
    c_pf_mus_tpfms_numlosthits_ = true;
  }
  return pf_mus_tpfms_numlosthits_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_numvalPixelhits() const{
  if(!c_pf_mus_tpfms_numvalPixelhits_ && b_pf_mus_tpfms_numvalPixelhits_){
    b_pf_mus_tpfms_numvalPixelhits_->GetEntry(entry_);
    c_pf_mus_tpfms_numvalPixelhits_ = true;
  }
  return pf_mus_tpfms_numvalPixelhits_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_numvalhits() const{
  if(!c_pf_mus_tpfms_numvalhits_ && b_pf_mus_tpfms_numvalhits_){
    b_pf_mus_tpfms_numvalhits_->GetEntry(entry_);
    c_pf_mus_tpfms_numvalhits_ = true;
  }
  return pf_mus_tpfms_numvalhits_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_phi() const{
  if(!c_pf_mus_tpfms_phi_ && b_pf_mus_tpfms_phi_){
    b_pf_mus_tpfms_phi_->GetEntry(entry_);
    c_pf_mus_tpfms_phi_ = true;
  }
  return pf_mus_tpfms_phi_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_phiErr() const{
  if(!c_pf_mus_tpfms_phiErr_ && b_pf_mus_tpfms_phiErr_){
    b_pf_mus_tpfms_phiErr_->GetEntry(entry_);
    c_pf_mus_tpfms_phiErr_ = true;
  }
  return pf_mus_tpfms_phiErr_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_pt() const{
  if(!c_pf_mus_tpfms_pt_ && b_pf_mus_tpfms_pt_){
    b_pf_mus_tpfms_pt_->GetEntry(entry_);
    c_pf_mus_tpfms_pt_ = true;
  }
  return pf_mus_tpfms_pt_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_ptErr() const{
  if(!c_pf_mus_tpfms_ptErr_ && b_pf_mus_tpfms_ptErr_){
    b_pf_mus_tpfms_ptErr_->GetEntry(entry_);
    c_pf_mus_tpfms_ptErr_ = true;
  }
  return pf_mus_tpfms_ptErr_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_px() const{
  if(!c_pf_mus_tpfms_px_ && b_pf_mus_tpfms_px_){
    b_pf_mus_tpfms_px_->GetEntry(entry_);
    c_pf_mus_tpfms_px_ = true;
  }
  return pf_mus_tpfms_px_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_py() const{
  if(!c_pf_mus_tpfms_py_ && b_pf_mus_tpfms_py_){
    b_pf_mus_tpfms_py_->GetEntry(entry_);
    c_pf_mus_tpfms_py_ = true;
  }
  return pf_mus_tpfms_py_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_pz() const{
  if(!c_pf_mus_tpfms_pz_ && b_pf_mus_tpfms_pz_){
    b_pf_mus_tpfms_pz_->GetEntry(entry_);
    c_pf_mus_tpfms_pz_ = true;
  }
  return pf_mus_tpfms_pz_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_theta() const{
  if(!c_pf_mus_tpfms_theta_ && b_pf_mus_tpfms_theta_){
    b_pf_mus_tpfms_theta_->GetEntry(entry_);
    c_pf_mus_tpfms_theta_ = true;
  }
  return pf_mus_tpfms_theta_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_vx() const{
  if(!c_pf_mus_tpfms_vx_ && b_pf_mus_tpfms_vx_){
    b_pf_mus_tpfms_vx_->GetEntry(entry_);
    c_pf_mus_tpfms_vx_ = true;
  }
  return pf_mus_tpfms_vx_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_vy() const{
  if(!c_pf_mus_tpfms_vy_ && b_pf_mus_tpfms_vy_){
    b_pf_mus_tpfms_vy_->GetEntry(entry_);
    c_pf_mus_tpfms_vy_ = true;
  }
  return pf_mus_tpfms_vy_;
}

std::vector<float>* const & cfa_8::pf_mus_tpfms_vz() const{
  if(!c_pf_mus_tpfms_vz_ && b_pf_mus_tpfms_vz_){
    b_pf_mus_tpfms_vz_->GetEntry(entry_);
    c_pf_mus_tpfms_vz_ = true;
  }
  return pf_mus_tpfms_vz_;
}

std::vector<float>* const & cfa_8::pf_photons_chIso() const{
  if(!c_pf_photons_chIso_ && b_pf_photons_chIso_){
    b_pf_photons_chIso_->GetEntry(entry_);
    c_pf_photons_chIso_ = true;
  }
  return pf_photons_chIso_;
}

std::vector<float>* const & cfa_8::pf_photons_e1x5() const{
  if(!c_pf_photons_e1x5_ && b_pf_photons_e1x5_){
    b_pf_photons_e1x5_->GetEntry(entry_);
    c_pf_photons_e1x5_ = true;
  }
  return pf_photons_e1x5_;
}

std::vector<float>* const & cfa_8::pf_photons_e2x5() const{
  if(!c_pf_photons_e2x5_ && b_pf_photons_e2x5_){
    b_pf_photons_e2x5_->GetEntry(entry_);
    c_pf_photons_e2x5_ = true;
  }
  return pf_photons_e2x5_;
}

std::vector<float>* const & cfa_8::pf_photons_e3x3() const{
  if(!c_pf_photons_e3x3_ && b_pf_photons_e3x3_){
    b_pf_photons_e3x3_->GetEntry(entry_);
    c_pf_photons_e3x3_ = true;
  }
  return pf_photons_e3x3_;
}

std::vector<float>* const & cfa_8::pf_photons_e5x5() const{
  if(!c_pf_photons_e5x5_ && b_pf_photons_e5x5_){
    b_pf_photons_e5x5_->GetEntry(entry_);
    c_pf_photons_e5x5_ = true;
  }
  return pf_photons_e5x5_;
}

std::vector<float>* const & cfa_8::pf_photons_energy() const{
  if(!c_pf_photons_energy_ && b_pf_photons_energy_){
    b_pf_photons_energy_->GetEntry(entry_);
    c_pf_photons_energy_ = true;
  }
  return pf_photons_energy_;
}

std::vector<float>* const & cfa_8::pf_photons_et() const{
  if(!c_pf_photons_et_ && b_pf_photons_et_){
    b_pf_photons_et_->GetEntry(entry_);
    c_pf_photons_et_ = true;
  }
  return pf_photons_et_;
}

std::vector<float>* const & cfa_8::pf_photons_eta() const{
  if(!c_pf_photons_eta_ && b_pf_photons_eta_){
    b_pf_photons_eta_->GetEntry(entry_);
    c_pf_photons_eta_ = true;
  }
  return pf_photons_eta_;
}

std::vector<float>* const & cfa_8::pf_photons_hadOverEM() const{
  if(!c_pf_photons_hadOverEM_ && b_pf_photons_hadOverEM_){
    b_pf_photons_hadOverEM_->GetEntry(entry_);
    c_pf_photons_hadOverEM_ = true;
  }
  return pf_photons_hadOverEM_;
}

std::vector<float>* const & cfa_8::pf_photons_hadTowOverEM() const{
  if(!c_pf_photons_hadTowOverEM_ && b_pf_photons_hadTowOverEM_){
    b_pf_photons_hadTowOverEM_->GetEntry(entry_);
    c_pf_photons_hadTowOverEM_ = true;
  }
  return pf_photons_hadTowOverEM_;
}

std::vector<float>* const & cfa_8::pf_photons_hasPixelSeed() const{
  if(!c_pf_photons_hasPixelSeed_ && b_pf_photons_hasPixelSeed_){
    b_pf_photons_hasPixelSeed_->GetEntry(entry_);
    c_pf_photons_hasPixelSeed_ = true;
  }
  return pf_photons_hasPixelSeed_;
}

std::vector<float>* const & cfa_8::pf_photons_isAlsoElectron() const{
  if(!c_pf_photons_isAlsoElectron_ && b_pf_photons_isAlsoElectron_){
    b_pf_photons_isAlsoElectron_->GetEntry(entry_);
    c_pf_photons_isAlsoElectron_ = true;
  }
  return pf_photons_isAlsoElectron_;
}

std::vector<float>* const & cfa_8::pf_photons_isConverted() const{
  if(!c_pf_photons_isConverted_ && b_pf_photons_isConverted_){
    b_pf_photons_isConverted_->GetEntry(entry_);
    c_pf_photons_isConverted_ = true;
  }
  return pf_photons_isConverted_;
}

std::vector<float>* const & cfa_8::pf_photons_isEBEEGap() const{
  if(!c_pf_photons_isEBEEGap_ && b_pf_photons_isEBEEGap_){
    b_pf_photons_isEBEEGap_->GetEntry(entry_);
    c_pf_photons_isEBEEGap_ = true;
  }
  return pf_photons_isEBEEGap_;
}

std::vector<float>* const & cfa_8::pf_photons_isEBGap() const{
  if(!c_pf_photons_isEBGap_ && b_pf_photons_isEBGap_){
    b_pf_photons_isEBGap_->GetEntry(entry_);
    c_pf_photons_isEBGap_ = true;
  }
  return pf_photons_isEBGap_;
}

std::vector<float>* const & cfa_8::pf_photons_isEBPho() const{
  if(!c_pf_photons_isEBPho_ && b_pf_photons_isEBPho_){
    b_pf_photons_isEBPho_->GetEntry(entry_);
    c_pf_photons_isEBPho_ = true;
  }
  return pf_photons_isEBPho_;
}

std::vector<float>* const & cfa_8::pf_photons_isEEGap() const{
  if(!c_pf_photons_isEEGap_ && b_pf_photons_isEEGap_){
    b_pf_photons_isEEGap_->GetEntry(entry_);
    c_pf_photons_isEEGap_ = true;
  }
  return pf_photons_isEEGap_;
}

std::vector<float>* const & cfa_8::pf_photons_isEEPho() const{
  if(!c_pf_photons_isEEPho_ && b_pf_photons_isEEPho_){
    b_pf_photons_isEEPho_->GetEntry(entry_);
    c_pf_photons_isEEPho_ = true;
  }
  return pf_photons_isEEPho_;
}

std::vector<float>* const & cfa_8::pf_photons_maxEnergyXtal() const{
  if(!c_pf_photons_maxEnergyXtal_ && b_pf_photons_maxEnergyXtal_){
    b_pf_photons_maxEnergyXtal_->GetEntry(entry_);
    c_pf_photons_maxEnergyXtal_ = true;
  }
  return pf_photons_maxEnergyXtal_;
}

std::vector<float>* const & cfa_8::pf_photons_nhIso() const{
  if(!c_pf_photons_nhIso_ && b_pf_photons_nhIso_){
    b_pf_photons_nhIso_->GetEntry(entry_);
    c_pf_photons_nhIso_ = true;
  }
  return pf_photons_nhIso_;
}

std::vector<float>* const & cfa_8::pf_photons_phIso() const{
  if(!c_pf_photons_phIso_ && b_pf_photons_phIso_){
    b_pf_photons_phIso_->GetEntry(entry_);
    c_pf_photons_phIso_ = true;
  }
  return pf_photons_phIso_;
}

std::vector<float>* const & cfa_8::pf_photons_phi() const{
  if(!c_pf_photons_phi_ && b_pf_photons_phi_){
    b_pf_photons_phi_->GetEntry(entry_);
    c_pf_photons_phi_ = true;
  }
  return pf_photons_phi_;
}

std::vector<float>* const & cfa_8::pf_photons_pt() const{
  if(!c_pf_photons_pt_ && b_pf_photons_pt_){
    b_pf_photons_pt_->GetEntry(entry_);
    c_pf_photons_pt_ = true;
  }
  return pf_photons_pt_;
}

std::vector<float>* const & cfa_8::pf_photons_px() const{
  if(!c_pf_photons_px_ && b_pf_photons_px_){
    b_pf_photons_px_->GetEntry(entry_);
    c_pf_photons_px_ = true;
  }
  return pf_photons_px_;
}

std::vector<float>* const & cfa_8::pf_photons_py() const{
  if(!c_pf_photons_py_ && b_pf_photons_py_){
    b_pf_photons_py_->GetEntry(entry_);
    c_pf_photons_py_ = true;
  }
  return pf_photons_py_;
}

std::vector<float>* const & cfa_8::pf_photons_pz() const{
  if(!c_pf_photons_pz_ && b_pf_photons_pz_){
    b_pf_photons_pz_->GetEntry(entry_);
    c_pf_photons_pz_ = true;
  }
  return pf_photons_pz_;
}

std::vector<float>* const & cfa_8::pf_photons_r9() const{
  if(!c_pf_photons_r9_ && b_pf_photons_r9_){
    b_pf_photons_r9_->GetEntry(entry_);
    c_pf_photons_r9_ = true;
  }
  return pf_photons_r9_;
}

std::vector<float>* const & cfa_8::pf_photons_scEnergy() const{
  if(!c_pf_photons_scEnergy_ && b_pf_photons_scEnergy_){
    b_pf_photons_scEnergy_->GetEntry(entry_);
    c_pf_photons_scEnergy_ = true;
  }
  return pf_photons_scEnergy_;
}

std::vector<float>* const & cfa_8::pf_photons_scEta() const{
  if(!c_pf_photons_scEta_ && b_pf_photons_scEta_){
    b_pf_photons_scEta_->GetEntry(entry_);
    c_pf_photons_scEta_ = true;
  }
  return pf_photons_scEta_;
}

std::vector<float>* const & cfa_8::pf_photons_scEtaWidth() const{
  if(!c_pf_photons_scEtaWidth_ && b_pf_photons_scEtaWidth_){
    b_pf_photons_scEtaWidth_->GetEntry(entry_);
    c_pf_photons_scEtaWidth_ = true;
  }
  return pf_photons_scEtaWidth_;
}

std::vector<float>* const & cfa_8::pf_photons_scPhi() const{
  if(!c_pf_photons_scPhi_ && b_pf_photons_scPhi_){
    b_pf_photons_scPhi_->GetEntry(entry_);
    c_pf_photons_scPhi_ = true;
  }
  return pf_photons_scPhi_;
}

std::vector<float>* const & cfa_8::pf_photons_scPhiWidth() const{
  if(!c_pf_photons_scPhiWidth_ && b_pf_photons_scPhiWidth_){
    b_pf_photons_scPhiWidth_->GetEntry(entry_);
    c_pf_photons_scPhiWidth_ = true;
  }
  return pf_photons_scPhiWidth_;
}

std::vector<float>* const & cfa_8::pf_photons_scRawEnergy() const{
  if(!c_pf_photons_scRawEnergy_ && b_pf_photons_scRawEnergy_){
    b_pf_photons_scRawEnergy_->GetEntry(entry_);
    c_pf_photons_scRawEnergy_ = true;
  }
  return pf_photons_scRawEnergy_;
}

std::vector<float>* const & cfa_8::pf_photons_sigmaEtaEta() const{
  if(!c_pf_photons_sigmaEtaEta_ && b_pf_photons_sigmaEtaEta_){
    b_pf_photons_sigmaEtaEta_->GetEntry(entry_);
    c_pf_photons_sigmaEtaEta_ = true;
  }
  return pf_photons_sigmaEtaEta_;
}

std::vector<float>* const & cfa_8::pf_photons_sigmaIetaIeta() const{
  if(!c_pf_photons_sigmaIetaIeta_ && b_pf_photons_sigmaIetaIeta_){
    b_pf_photons_sigmaIetaIeta_->GetEntry(entry_);
    c_pf_photons_sigmaIetaIeta_ = true;
  }
  return pf_photons_sigmaIetaIeta_;
}

std::vector<float>* const & cfa_8::pf_photons_status() const{
  if(!c_pf_photons_status_ && b_pf_photons_status_){
    b_pf_photons_status_->GetEntry(entry_);
    c_pf_photons_status_ = true;
  }
  return pf_photons_status_;
}

std::vector<float>* const & cfa_8::pf_photons_theta() const{
  if(!c_pf_photons_theta_ && b_pf_photons_theta_){
    b_pf_photons_theta_->GetEntry(entry_);
    c_pf_photons_theta_ = true;
  }
  return pf_photons_theta_;
}

std::vector<float>* const & cfa_8::pfcand_charge() const{
  if(!c_pfcand_charge_ && b_pfcand_charge_){
    b_pfcand_charge_->GetEntry(entry_);
    c_pfcand_charge_ = true;
  }
  return pfcand_charge_;
}

std::vector<float>* const & cfa_8::pfcand_energy() const{
  if(!c_pfcand_energy_ && b_pfcand_energy_){
    b_pfcand_energy_->GetEntry(entry_);
    c_pfcand_energy_ = true;
  }
  return pfcand_energy_;
}

std::vector<float>* const & cfa_8::pfcand_eta() const{
  if(!c_pfcand_eta_ && b_pfcand_eta_){
    b_pfcand_eta_->GetEntry(entry_);
    c_pfcand_eta_ = true;
  }
  return pfcand_eta_;
}

std::vector<float>* const & cfa_8::pfcand_particleId() const{
  if(!c_pfcand_particleId_ && b_pfcand_particleId_){
    b_pfcand_particleId_->GetEntry(entry_);
    c_pfcand_particleId_ = true;
  }
  return pfcand_particleId_;
}

std::vector<float>* const & cfa_8::pfcand_pdgId() const{
  if(!c_pfcand_pdgId_ && b_pfcand_pdgId_){
    b_pfcand_pdgId_->GetEntry(entry_);
    c_pfcand_pdgId_ = true;
  }
  return pfcand_pdgId_;
}

std::vector<float>* const & cfa_8::pfcand_phi() const{
  if(!c_pfcand_phi_ && b_pfcand_phi_){
    b_pfcand_phi_->GetEntry(entry_);
    c_pfcand_phi_ = true;
  }
  return pfcand_phi_;
}

std::vector<float>* const & cfa_8::pfcand_pt() const{
  if(!c_pfcand_pt_ && b_pfcand_pt_){
    b_pfcand_pt_->GetEntry(entry_);
    c_pfcand_pt_ = true;
  }
  return pfcand_pt_;
}

std::vector<float>* const & cfa_8::pfcand_px() const{
  if(!c_pfcand_px_ && b_pfcand_px_){
    b_pfcand_px_->GetEntry(entry_);
    c_pfcand_px_ = true;
  }
  return pfcand_px_;
}

std::vector<float>* const & cfa_8::pfcand_py() const{
  if(!c_pfcand_py_ && b_pfcand_py_){
    b_pfcand_py_->GetEntry(entry_);
    c_pfcand_py_ = true;
  }
  return pfcand_py_;
}

std::vector<float>* const & cfa_8::pfcand_pz() const{
  if(!c_pfcand_pz_ && b_pfcand_pz_){
    b_pfcand_pz_->GetEntry(entry_);
    c_pfcand_pz_ = true;
  }
  return pfcand_pz_;
}

std::vector<float>* const & cfa_8::pfcand_theta() const{
  if(!c_pfcand_theta_ && b_pfcand_theta_){
    b_pfcand_theta_->GetEntry(entry_);
    c_pfcand_theta_ = true;
  }
  return pfcand_theta_;
}

std::vector<float>* const & cfa_8::pfmets_et() const{
  if(!c_pfmets_et_ && b_pfmets_et_){
    b_pfmets_et_->GetEntry(entry_);
    c_pfmets_et_ = true;
  }
  return pfmets_et_;
}

std::vector<float>* const & cfa_8::pfmets_ex() const{
  if(!c_pfmets_ex_ && b_pfmets_ex_){
    b_pfmets_ex_->GetEntry(entry_);
    c_pfmets_ex_ = true;
  }
  return pfmets_ex_;
}

std::vector<float>* const & cfa_8::pfmets_ey() const{
  if(!c_pfmets_ey_ && b_pfmets_ey_){
    b_pfmets_ey_->GetEntry(entry_);
    c_pfmets_ey_ = true;
  }
  return pfmets_ey_;
}

Float_t const & cfa_8::pfmets_fullSignif() const{
  if(!c_pfmets_fullSignif_ && b_pfmets_fullSignif_){
    b_pfmets_fullSignif_->GetEntry(entry_);
    c_pfmets_fullSignif_ = true;
  }
  return pfmets_fullSignif_;
}

Float_t const & cfa_8::pfmets_fullSignifCov00() const{
  if(!c_pfmets_fullSignifCov00_ && b_pfmets_fullSignifCov00_){
    b_pfmets_fullSignifCov00_->GetEntry(entry_);
    c_pfmets_fullSignifCov00_ = true;
  }
  return pfmets_fullSignifCov00_;
}

Float_t const & cfa_8::pfmets_fullSignifCov00_2012() const{
  if(!c_pfmets_fullSignifCov00_2012_ && b_pfmets_fullSignifCov00_2012_){
    b_pfmets_fullSignifCov00_2012_->GetEntry(entry_);
    c_pfmets_fullSignifCov00_2012_ = true;
  }
  return pfmets_fullSignifCov00_2012_;
}

Float_t const & cfa_8::pfmets_fullSignifCov00_2012_dataRes() const{
  if(!c_pfmets_fullSignifCov00_2012_dataRes_ && b_pfmets_fullSignifCov00_2012_dataRes_){
    b_pfmets_fullSignifCov00_2012_dataRes_->GetEntry(entry_);
    c_pfmets_fullSignifCov00_2012_dataRes_ = true;
  }
  return pfmets_fullSignifCov00_2012_dataRes_;
}

Float_t const & cfa_8::pfmets_fullSignifCov10() const{
  if(!c_pfmets_fullSignifCov10_ && b_pfmets_fullSignifCov10_){
    b_pfmets_fullSignifCov10_->GetEntry(entry_);
    c_pfmets_fullSignifCov10_ = true;
  }
  return pfmets_fullSignifCov10_;
}

Float_t const & cfa_8::pfmets_fullSignifCov10_2012() const{
  if(!c_pfmets_fullSignifCov10_2012_ && b_pfmets_fullSignifCov10_2012_){
    b_pfmets_fullSignifCov10_2012_->GetEntry(entry_);
    c_pfmets_fullSignifCov10_2012_ = true;
  }
  return pfmets_fullSignifCov10_2012_;
}

Float_t const & cfa_8::pfmets_fullSignifCov10_2012_dataRes() const{
  if(!c_pfmets_fullSignifCov10_2012_dataRes_ && b_pfmets_fullSignifCov10_2012_dataRes_){
    b_pfmets_fullSignifCov10_2012_dataRes_->GetEntry(entry_);
    c_pfmets_fullSignifCov10_2012_dataRes_ = true;
  }
  return pfmets_fullSignifCov10_2012_dataRes_;
}

Float_t const & cfa_8::pfmets_fullSignifCov11() const{
  if(!c_pfmets_fullSignifCov11_ && b_pfmets_fullSignifCov11_){
    b_pfmets_fullSignifCov11_->GetEntry(entry_);
    c_pfmets_fullSignifCov11_ = true;
  }
  return pfmets_fullSignifCov11_;
}

Float_t const & cfa_8::pfmets_fullSignifCov11_2012() const{
  if(!c_pfmets_fullSignifCov11_2012_ && b_pfmets_fullSignifCov11_2012_){
    b_pfmets_fullSignifCov11_2012_->GetEntry(entry_);
    c_pfmets_fullSignifCov11_2012_ = true;
  }
  return pfmets_fullSignifCov11_2012_;
}

Float_t const & cfa_8::pfmets_fullSignifCov11_2012_dataRes() const{
  if(!c_pfmets_fullSignifCov11_2012_dataRes_ && b_pfmets_fullSignifCov11_2012_dataRes_){
    b_pfmets_fullSignifCov11_2012_dataRes_->GetEntry(entry_);
    c_pfmets_fullSignifCov11_2012_dataRes_ = true;
  }
  return pfmets_fullSignifCov11_2012_dataRes_;
}

Float_t const & cfa_8::pfmets_fullSignif_2012() const{
  if(!c_pfmets_fullSignif_2012_ && b_pfmets_fullSignif_2012_){
    b_pfmets_fullSignif_2012_->GetEntry(entry_);
    c_pfmets_fullSignif_2012_ = true;
  }
  return pfmets_fullSignif_2012_;
}

Float_t const & cfa_8::pfmets_fullSignif_2012_dataRes() const{
  if(!c_pfmets_fullSignif_2012_dataRes_ && b_pfmets_fullSignif_2012_dataRes_){
    b_pfmets_fullSignif_2012_dataRes_->GetEntry(entry_);
    c_pfmets_fullSignif_2012_dataRes_ = true;
  }
  return pfmets_fullSignif_2012_dataRes_;
}

std::vector<float>* const & cfa_8::pfmets_gen_et() const{
  if(!c_pfmets_gen_et_ && b_pfmets_gen_et_){
    b_pfmets_gen_et_->GetEntry(entry_);
    c_pfmets_gen_et_ = true;
  }
  return pfmets_gen_et_;
}

std::vector<float>* const & cfa_8::pfmets_gen_phi() const{
  if(!c_pfmets_gen_phi_ && b_pfmets_gen_phi_){
    b_pfmets_gen_phi_->GetEntry(entry_);
    c_pfmets_gen_phi_ = true;
  }
  return pfmets_gen_phi_;
}

std::vector<float>* const & cfa_8::pfmets_phi() const{
  if(!c_pfmets_phi_ && b_pfmets_phi_){
    b_pfmets_phi_->GetEntry(entry_);
    c_pfmets_phi_ = true;
  }
  return pfmets_phi_;
}

std::vector<float>* const & cfa_8::pfmets_sign() const{
  if(!c_pfmets_sign_ && b_pfmets_sign_){
    b_pfmets_sign_->GetEntry(entry_);
    c_pfmets_sign_ = true;
  }
  return pfmets_sign_;
}

std::vector<float>* const & cfa_8::pfmets_sumEt() const{
  if(!c_pfmets_sumEt_ && b_pfmets_sumEt_){
    b_pfmets_sumEt_->GetEntry(entry_);
    c_pfmets_sumEt_ = true;
  }
  return pfmets_sumEt_;
}

std::vector<float>* const & cfa_8::pfmets_unCPhi() const{
  if(!c_pfmets_unCPhi_ && b_pfmets_unCPhi_){
    b_pfmets_unCPhi_->GetEntry(entry_);
    c_pfmets_unCPhi_ = true;
  }
  return pfmets_unCPhi_;
}

std::vector<float>* const & cfa_8::pfmets_unCPt() const{
  if(!c_pfmets_unCPt_ && b_pfmets_unCPt_){
    b_pfmets_unCPt_->GetEntry(entry_);
    c_pfmets_unCPt_ = true;
  }
  return pfmets_unCPt_;
}

std::vector<float>* const & cfa_8::photon_chIsoValues() const{
  if(!c_photon_chIsoValues_ && b_photon_chIsoValues_){
    b_photon_chIsoValues_->GetEntry(entry_);
    c_photon_chIsoValues_ = true;
  }
  return photon_chIsoValues_;
}

std::vector<float>* const & cfa_8::photon_nhIsoValues() const{
  if(!c_photon_nhIsoValues_ && b_photon_nhIsoValues_){
    b_photon_nhIsoValues_->GetEntry(entry_);
    c_photon_nhIsoValues_ = true;
  }
  return photon_nhIsoValues_;
}

std::vector<bool>* const & cfa_8::photon_passElectronVeto() const{
  if(!c_photon_passElectronVeto_ && b_photon_passElectronVeto_){
    b_photon_passElectronVeto_->GetEntry(entry_);
    c_photon_passElectronVeto_ = true;
  }
  return photon_passElectronVeto_;
}

std::vector<float>* const & cfa_8::photon_phIsoValues() const{
  if(!c_photon_phIsoValues_ && b_photon_phIsoValues_){
    b_photon_phIsoValues_->GetEntry(entry_);
    c_photon_phIsoValues_ = true;
  }
  return photon_phIsoValues_;
}

std::vector<float>* const & cfa_8::photons_e1x5() const{
  if(!c_photons_e1x5_ && b_photons_e1x5_){
    b_photons_e1x5_->GetEntry(entry_);
    c_photons_e1x5_ = true;
  }
  return photons_e1x5_;
}

std::vector<float>* const & cfa_8::photons_e2x5() const{
  if(!c_photons_e2x5_ && b_photons_e2x5_){
    b_photons_e2x5_->GetEntry(entry_);
    c_photons_e2x5_ = true;
  }
  return photons_e2x5_;
}

std::vector<float>* const & cfa_8::photons_e3x3() const{
  if(!c_photons_e3x3_ && b_photons_e3x3_){
    b_photons_e3x3_->GetEntry(entry_);
    c_photons_e3x3_ = true;
  }
  return photons_e3x3_;
}

std::vector<float>* const & cfa_8::photons_e5x5() const{
  if(!c_photons_e5x5_ && b_photons_e5x5_){
    b_photons_e5x5_->GetEntry(entry_);
    c_photons_e5x5_ = true;
  }
  return photons_e5x5_;
}

std::vector<float>* const & cfa_8::photons_ecalIso() const{
  if(!c_photons_ecalIso_ && b_photons_ecalIso_){
    b_photons_ecalIso_->GetEntry(entry_);
    c_photons_ecalIso_ = true;
  }
  return photons_ecalIso_;
}

std::vector<float>* const & cfa_8::photons_energy() const{
  if(!c_photons_energy_ && b_photons_energy_){
    b_photons_energy_->GetEntry(entry_);
    c_photons_energy_ = true;
  }
  return photons_energy_;
}

std::vector<float>* const & cfa_8::photons_et() const{
  if(!c_photons_et_ && b_photons_et_){
    b_photons_et_->GetEntry(entry_);
    c_photons_et_ = true;
  }
  return photons_et_;
}

std::vector<float>* const & cfa_8::photons_eta() const{
  if(!c_photons_eta_ && b_photons_eta_){
    b_photons_eta_->GetEntry(entry_);
    c_photons_eta_ = true;
  }
  return photons_eta_;
}

std::vector<float>* const & cfa_8::photons_gen_et() const{
  if(!c_photons_gen_et_ && b_photons_gen_et_){
    b_photons_gen_et_->GetEntry(entry_);
    c_photons_gen_et_ = true;
  }
  return photons_gen_et_;
}

std::vector<float>* const & cfa_8::photons_gen_eta() const{
  if(!c_photons_gen_eta_ && b_photons_gen_eta_){
    b_photons_gen_eta_->GetEntry(entry_);
    c_photons_gen_eta_ = true;
  }
  return photons_gen_eta_;
}

std::vector<float>* const & cfa_8::photons_gen_id() const{
  if(!c_photons_gen_id_ && b_photons_gen_id_){
    b_photons_gen_id_->GetEntry(entry_);
    c_photons_gen_id_ = true;
  }
  return photons_gen_id_;
}

std::vector<float>* const & cfa_8::photons_gen_phi() const{
  if(!c_photons_gen_phi_ && b_photons_gen_phi_){
    b_photons_gen_phi_->GetEntry(entry_);
    c_photons_gen_phi_ = true;
  }
  return photons_gen_phi_;
}

std::vector<float>* const & cfa_8::photons_hadOverEM() const{
  if(!c_photons_hadOverEM_ && b_photons_hadOverEM_){
    b_photons_hadOverEM_->GetEntry(entry_);
    c_photons_hadOverEM_ = true;
  }
  return photons_hadOverEM_;
}

std::vector<float>* const & cfa_8::photons_hadTowOverEM() const{
  if(!c_photons_hadTowOverEM_ && b_photons_hadTowOverEM_){
    b_photons_hadTowOverEM_->GetEntry(entry_);
    c_photons_hadTowOverEM_ = true;
  }
  return photons_hadTowOverEM_;
}

std::vector<float>* const & cfa_8::photons_hasPixelSeed() const{
  if(!c_photons_hasPixelSeed_ && b_photons_hasPixelSeed_){
    b_photons_hasPixelSeed_->GetEntry(entry_);
    c_photons_hasPixelSeed_ = true;
  }
  return photons_hasPixelSeed_;
}

std::vector<float>* const & cfa_8::photons_hcalIso() const{
  if(!c_photons_hcalIso_ && b_photons_hcalIso_){
    b_photons_hcalIso_->GetEntry(entry_);
    c_photons_hcalIso_ = true;
  }
  return photons_hcalIso_;
}

std::vector<float>* const & cfa_8::photons_isAlsoElectron() const{
  if(!c_photons_isAlsoElectron_ && b_photons_isAlsoElectron_){
    b_photons_isAlsoElectron_->GetEntry(entry_);
    c_photons_isAlsoElectron_ = true;
  }
  return photons_isAlsoElectron_;
}

std::vector<float>* const & cfa_8::photons_isConverted() const{
  if(!c_photons_isConverted_ && b_photons_isConverted_){
    b_photons_isConverted_->GetEntry(entry_);
    c_photons_isConverted_ = true;
  }
  return photons_isConverted_;
}

std::vector<float>* const & cfa_8::photons_isEBEEGap() const{
  if(!c_photons_isEBEEGap_ && b_photons_isEBEEGap_){
    b_photons_isEBEEGap_->GetEntry(entry_);
    c_photons_isEBEEGap_ = true;
  }
  return photons_isEBEEGap_;
}

std::vector<float>* const & cfa_8::photons_isEBGap() const{
  if(!c_photons_isEBGap_ && b_photons_isEBGap_){
    b_photons_isEBGap_->GetEntry(entry_);
    c_photons_isEBGap_ = true;
  }
  return photons_isEBGap_;
}

std::vector<float>* const & cfa_8::photons_isEBPho() const{
  if(!c_photons_isEBPho_ && b_photons_isEBPho_){
    b_photons_isEBPho_->GetEntry(entry_);
    c_photons_isEBPho_ = true;
  }
  return photons_isEBPho_;
}

std::vector<float>* const & cfa_8::photons_isEEGap() const{
  if(!c_photons_isEEGap_ && b_photons_isEEGap_){
    b_photons_isEEGap_->GetEntry(entry_);
    c_photons_isEEGap_ = true;
  }
  return photons_isEEGap_;
}

std::vector<float>* const & cfa_8::photons_isEEPho() const{
  if(!c_photons_isEEPho_ && b_photons_isEEPho_){
    b_photons_isEEPho_->GetEntry(entry_);
    c_photons_isEEPho_ = true;
  }
  return photons_isEEPho_;
}

std::vector<float>* const & cfa_8::photons_isLoosePhoton() const{
  if(!c_photons_isLoosePhoton_ && b_photons_isLoosePhoton_){
    b_photons_isLoosePhoton_->GetEntry(entry_);
    c_photons_isLoosePhoton_ = true;
  }
  return photons_isLoosePhoton_;
}

std::vector<float>* const & cfa_8::photons_isTightPhoton() const{
  if(!c_photons_isTightPhoton_ && b_photons_isTightPhoton_){
    b_photons_isTightPhoton_->GetEntry(entry_);
    c_photons_isTightPhoton_ = true;
  }
  return photons_isTightPhoton_;
}

std::vector<float>* const & cfa_8::photons_isoEcalRecHitDR03() const{
  if(!c_photons_isoEcalRecHitDR03_ && b_photons_isoEcalRecHitDR03_){
    b_photons_isoEcalRecHitDR03_->GetEntry(entry_);
    c_photons_isoEcalRecHitDR03_ = true;
  }
  return photons_isoEcalRecHitDR03_;
}

std::vector<float>* const & cfa_8::photons_isoEcalRecHitDR04() const{
  if(!c_photons_isoEcalRecHitDR04_ && b_photons_isoEcalRecHitDR04_){
    b_photons_isoEcalRecHitDR04_->GetEntry(entry_);
    c_photons_isoEcalRecHitDR04_ = true;
  }
  return photons_isoEcalRecHitDR04_;
}

std::vector<float>* const & cfa_8::photons_isoHcalRecHitDR03() const{
  if(!c_photons_isoHcalRecHitDR03_ && b_photons_isoHcalRecHitDR03_){
    b_photons_isoHcalRecHitDR03_->GetEntry(entry_);
    c_photons_isoHcalRecHitDR03_ = true;
  }
  return photons_isoHcalRecHitDR03_;
}

std::vector<float>* const & cfa_8::photons_isoHcalRecHitDR04() const{
  if(!c_photons_isoHcalRecHitDR04_ && b_photons_isoHcalRecHitDR04_){
    b_photons_isoHcalRecHitDR04_->GetEntry(entry_);
    c_photons_isoHcalRecHitDR04_ = true;
  }
  return photons_isoHcalRecHitDR04_;
}

std::vector<float>* const & cfa_8::photons_isoHollowTrkConeDR03() const{
  if(!c_photons_isoHollowTrkConeDR03_ && b_photons_isoHollowTrkConeDR03_){
    b_photons_isoHollowTrkConeDR03_->GetEntry(entry_);
    c_photons_isoHollowTrkConeDR03_ = true;
  }
  return photons_isoHollowTrkConeDR03_;
}

std::vector<float>* const & cfa_8::photons_isoHollowTrkConeDR04() const{
  if(!c_photons_isoHollowTrkConeDR04_ && b_photons_isoHollowTrkConeDR04_){
    b_photons_isoHollowTrkConeDR04_->GetEntry(entry_);
    c_photons_isoHollowTrkConeDR04_ = true;
  }
  return photons_isoHollowTrkConeDR04_;
}

std::vector<float>* const & cfa_8::photons_isoSolidTrkConeDR03() const{
  if(!c_photons_isoSolidTrkConeDR03_ && b_photons_isoSolidTrkConeDR03_){
    b_photons_isoSolidTrkConeDR03_->GetEntry(entry_);
    c_photons_isoSolidTrkConeDR03_ = true;
  }
  return photons_isoSolidTrkConeDR03_;
}

std::vector<float>* const & cfa_8::photons_isoSolidTrkConeDR04() const{
  if(!c_photons_isoSolidTrkConeDR04_ && b_photons_isoSolidTrkConeDR04_){
    b_photons_isoSolidTrkConeDR04_->GetEntry(entry_);
    c_photons_isoSolidTrkConeDR04_ = true;
  }
  return photons_isoSolidTrkConeDR04_;
}

std::vector<float>* const & cfa_8::photons_maxEnergyXtal() const{
  if(!c_photons_maxEnergyXtal_ && b_photons_maxEnergyXtal_){
    b_photons_maxEnergyXtal_->GetEntry(entry_);
    c_photons_maxEnergyXtal_ = true;
  }
  return photons_maxEnergyXtal_;
}

std::vector<float>* const & cfa_8::photons_nTrkHollowConeDR03() const{
  if(!c_photons_nTrkHollowConeDR03_ && b_photons_nTrkHollowConeDR03_){
    b_photons_nTrkHollowConeDR03_->GetEntry(entry_);
    c_photons_nTrkHollowConeDR03_ = true;
  }
  return photons_nTrkHollowConeDR03_;
}

std::vector<float>* const & cfa_8::photons_nTrkHollowConeDR04() const{
  if(!c_photons_nTrkHollowConeDR04_ && b_photons_nTrkHollowConeDR04_){
    b_photons_nTrkHollowConeDR04_->GetEntry(entry_);
    c_photons_nTrkHollowConeDR04_ = true;
  }
  return photons_nTrkHollowConeDR04_;
}

std::vector<float>* const & cfa_8::photons_nTrkSolidConeDR03() const{
  if(!c_photons_nTrkSolidConeDR03_ && b_photons_nTrkSolidConeDR03_){
    b_photons_nTrkSolidConeDR03_->GetEntry(entry_);
    c_photons_nTrkSolidConeDR03_ = true;
  }
  return photons_nTrkSolidConeDR03_;
}

std::vector<float>* const & cfa_8::photons_nTrkSolidConeDR04() const{
  if(!c_photons_nTrkSolidConeDR04_ && b_photons_nTrkSolidConeDR04_){
    b_photons_nTrkSolidConeDR04_->GetEntry(entry_);
    c_photons_nTrkSolidConeDR04_ = true;
  }
  return photons_nTrkSolidConeDR04_;
}

std::vector<float>* const & cfa_8::photons_phi() const{
  if(!c_photons_phi_ && b_photons_phi_){
    b_photons_phi_->GetEntry(entry_);
    c_photons_phi_ = true;
  }
  return photons_phi_;
}

std::vector<float>* const & cfa_8::photons_pt() const{
  if(!c_photons_pt_ && b_photons_pt_){
    b_photons_pt_->GetEntry(entry_);
    c_photons_pt_ = true;
  }
  return photons_pt_;
}

std::vector<float>* const & cfa_8::photons_px() const{
  if(!c_photons_px_ && b_photons_px_){
    b_photons_px_->GetEntry(entry_);
    c_photons_px_ = true;
  }
  return photons_px_;
}

std::vector<float>* const & cfa_8::photons_py() const{
  if(!c_photons_py_ && b_photons_py_){
    b_photons_py_->GetEntry(entry_);
    c_photons_py_ = true;
  }
  return photons_py_;
}

std::vector<float>* const & cfa_8::photons_pz() const{
  if(!c_photons_pz_ && b_photons_pz_){
    b_photons_pz_->GetEntry(entry_);
    c_photons_pz_ = true;
  }
  return photons_pz_;
}

std::vector<float>* const & cfa_8::photons_r9() const{
  if(!c_photons_r9_ && b_photons_r9_){
    b_photons_r9_->GetEntry(entry_);
    c_photons_r9_ = true;
  }
  return photons_r9_;
}

std::vector<float>* const & cfa_8::photons_scEnergy() const{
  if(!c_photons_scEnergy_ && b_photons_scEnergy_){
    b_photons_scEnergy_->GetEntry(entry_);
    c_photons_scEnergy_ = true;
  }
  return photons_scEnergy_;
}

std::vector<float>* const & cfa_8::photons_scEta() const{
  if(!c_photons_scEta_ && b_photons_scEta_){
    b_photons_scEta_->GetEntry(entry_);
    c_photons_scEta_ = true;
  }
  return photons_scEta_;
}

std::vector<float>* const & cfa_8::photons_scEtaWidth() const{
  if(!c_photons_scEtaWidth_ && b_photons_scEtaWidth_){
    b_photons_scEtaWidth_->GetEntry(entry_);
    c_photons_scEtaWidth_ = true;
  }
  return photons_scEtaWidth_;
}

std::vector<float>* const & cfa_8::photons_scPhi() const{
  if(!c_photons_scPhi_ && b_photons_scPhi_){
    b_photons_scPhi_->GetEntry(entry_);
    c_photons_scPhi_ = true;
  }
  return photons_scPhi_;
}

std::vector<float>* const & cfa_8::photons_scPhiWidth() const{
  if(!c_photons_scPhiWidth_ && b_photons_scPhiWidth_){
    b_photons_scPhiWidth_->GetEntry(entry_);
    c_photons_scPhiWidth_ = true;
  }
  return photons_scPhiWidth_;
}

std::vector<float>* const & cfa_8::photons_scRawEnergy() const{
  if(!c_photons_scRawEnergy_ && b_photons_scRawEnergy_){
    b_photons_scRawEnergy_->GetEntry(entry_);
    c_photons_scRawEnergy_ = true;
  }
  return photons_scRawEnergy_;
}

std::vector<float>* const & cfa_8::photons_sigmaEtaEta() const{
  if(!c_photons_sigmaEtaEta_ && b_photons_sigmaEtaEta_){
    b_photons_sigmaEtaEta_->GetEntry(entry_);
    c_photons_sigmaEtaEta_ = true;
  }
  return photons_sigmaEtaEta_;
}

std::vector<float>* const & cfa_8::photons_sigmaIetaIeta() const{
  if(!c_photons_sigmaIetaIeta_ && b_photons_sigmaIetaIeta_){
    b_photons_sigmaIetaIeta_->GetEntry(entry_);
    c_photons_sigmaIetaIeta_ = true;
  }
  return photons_sigmaIetaIeta_;
}

std::vector<float>* const & cfa_8::photons_status() const{
  if(!c_photons_status_ && b_photons_status_){
    b_photons_status_->GetEntry(entry_);
    c_photons_status_ = true;
  }
  return photons_status_;
}

std::vector<float>* const & cfa_8::photons_tIso() const{
  if(!c_photons_tIso_ && b_photons_tIso_){
    b_photons_tIso_->GetEntry(entry_);
    c_photons_tIso_ = true;
  }
  return photons_tIso_;
}

std::vector<float>* const & cfa_8::photons_theta() const{
  if(!c_photons_theta_ && b_photons_theta_){
    b_photons_theta_->GetEntry(entry_);
    c_photons_theta_ = true;
  }
  return photons_theta_;
}

std::vector<std::vector<float> >* const & cfa_8::puJet_rejectionBeta() const{
  if(!c_puJet_rejectionBeta_ && b_puJet_rejectionBeta_){
    b_puJet_rejectionBeta_->GetEntry(entry_);
    c_puJet_rejectionBeta_ = true;
  }
  return puJet_rejectionBeta_;
}

std::vector<std::vector<float> >* const & cfa_8::puJet_rejectionMVA() const{
  if(!c_puJet_rejectionMVA_ && b_puJet_rejectionMVA_){
    b_puJet_rejectionMVA_->GetEntry(entry_);
    c_puJet_rejectionMVA_ = true;
  }
  return puJet_rejectionMVA_;
}

std::vector<float>* const & cfa_8::pv_chi2() const{
  if(!c_pv_chi2_ && b_pv_chi2_){
    b_pv_chi2_->GetEntry(entry_);
    c_pv_chi2_ = true;
  }
  return pv_chi2_;
}

std::vector<float>* const & cfa_8::pv_isFake() const{
  if(!c_pv_isFake_ && b_pv_isFake_){
    b_pv_isFake_->GetEntry(entry_);
    c_pv_isFake_ = true;
  }
  return pv_isFake_;
}

std::vector<float>* const & cfa_8::pv_isValid() const{
  if(!c_pv_isValid_ && b_pv_isValid_){
    b_pv_isValid_->GetEntry(entry_);
    c_pv_isValid_ = true;
  }
  return pv_isValid_;
}

std::vector<float>* const & cfa_8::pv_ndof() const{
  if(!c_pv_ndof_ && b_pv_ndof_){
    b_pv_ndof_->GetEntry(entry_);
    c_pv_ndof_ = true;
  }
  return pv_ndof_;
}

std::vector<float>* const & cfa_8::pv_tracksSize() const{
  if(!c_pv_tracksSize_ && b_pv_tracksSize_){
    b_pv_tracksSize_->GetEntry(entry_);
    c_pv_tracksSize_ = true;
  }
  return pv_tracksSize_;
}

std::vector<float>* const & cfa_8::pv_x() const{
  if(!c_pv_x_ && b_pv_x_){
    b_pv_x_->GetEntry(entry_);
    c_pv_x_ = true;
  }
  return pv_x_;
}

std::vector<float>* const & cfa_8::pv_xErr() const{
  if(!c_pv_xErr_ && b_pv_xErr_){
    b_pv_xErr_->GetEntry(entry_);
    c_pv_xErr_ = true;
  }
  return pv_xErr_;
}

std::vector<float>* const & cfa_8::pv_y() const{
  if(!c_pv_y_ && b_pv_y_){
    b_pv_y_->GetEntry(entry_);
    c_pv_y_ = true;
  }
  return pv_y_;
}

std::vector<float>* const & cfa_8::pv_yErr() const{
  if(!c_pv_yErr_ && b_pv_yErr_){
    b_pv_yErr_->GetEntry(entry_);
    c_pv_yErr_ = true;
  }
  return pv_yErr_;
}

std::vector<float>* const & cfa_8::pv_z() const{
  if(!c_pv_z_ && b_pv_z_){
    b_pv_z_->GetEntry(entry_);
    c_pv_z_ = true;
  }
  return pv_z_;
}

std::vector<float>* const & cfa_8::pv_zErr() const{
  if(!c_pv_zErr_ && b_pv_zErr_){
    b_pv_zErr_->GetEntry(entry_);
    c_pv_zErr_ = true;
  }
  return pv_zErr_;
}

Float_t const & cfa_8::rho_kt6PFJetsForIsolation2011() const{
  if(!c_rho_kt6PFJetsForIsolation2011_ && b_rho_kt6PFJetsForIsolation2011_){
    b_rho_kt6PFJetsForIsolation2011_->GetEntry(entry_);
    c_rho_kt6PFJetsForIsolation2011_ = true;
  }
  return rho_kt6PFJetsForIsolation2011_;
}

Float_t const & cfa_8::rho_kt6PFJetsForIsolation2012() const{
  if(!c_rho_kt6PFJetsForIsolation2012_ && b_rho_kt6PFJetsForIsolation2012_){
    b_rho_kt6PFJetsForIsolation2012_->GetEntry(entry_);
    c_rho_kt6PFJetsForIsolation2012_ = true;
  }
  return rho_kt6PFJetsForIsolation2012_;
}

UInt_t const & cfa_8::run() const{
  if(!c_run_ && b_run_){
    b_run_->GetEntry(entry_);
    c_run_ = true;
  }
  return run_;
}

Int_t const & cfa_8::scrapingVeto_decision() const{
  if(!c_scrapingVeto_decision_ && b_scrapingVeto_decision_){
    b_scrapingVeto_decision_->GetEntry(entry_);
    c_scrapingVeto_decision_ = true;
  }
  return scrapingVeto_decision_;
}

Float_t const & cfa_8::softjetUp_dMEx() const{
  if(!c_softjetUp_dMEx_ && b_softjetUp_dMEx_){
    b_softjetUp_dMEx_->GetEntry(entry_);
    c_softjetUp_dMEx_ = true;
  }
  return softjetUp_dMEx_;
}

Float_t const & cfa_8::softjetUp_dMEy() const{
  if(!c_softjetUp_dMEy_ && b_softjetUp_dMEy_){
    b_softjetUp_dMEy_->GetEntry(entry_);
    c_softjetUp_dMEy_ = true;
  }
  return softjetUp_dMEy_;
}

std::vector<std::string>* const & cfa_8::standalone_triggerobject_collectionname() const{
  if(!c_standalone_triggerobject_collectionname_ && b_standalone_triggerobject_collectionname_){
    b_standalone_triggerobject_collectionname_->GetEntry(entry_);
    c_standalone_triggerobject_collectionname_ = true;
  }
  return standalone_triggerobject_collectionname_;
}

std::vector<float>* const & cfa_8::standalone_triggerobject_energy() const{
  if(!c_standalone_triggerobject_energy_ && b_standalone_triggerobject_energy_){
    b_standalone_triggerobject_energy_->GetEntry(entry_);
    c_standalone_triggerobject_energy_ = true;
  }
  return standalone_triggerobject_energy_;
}

std::vector<float>* const & cfa_8::standalone_triggerobject_et() const{
  if(!c_standalone_triggerobject_et_ && b_standalone_triggerobject_et_){
    b_standalone_triggerobject_et_->GetEntry(entry_);
    c_standalone_triggerobject_et_ = true;
  }
  return standalone_triggerobject_et_;
}

std::vector<float>* const & cfa_8::standalone_triggerobject_eta() const{
  if(!c_standalone_triggerobject_eta_ && b_standalone_triggerobject_eta_){
    b_standalone_triggerobject_eta_->GetEntry(entry_);
    c_standalone_triggerobject_eta_ = true;
  }
  return standalone_triggerobject_eta_;
}

std::vector<float>* const & cfa_8::standalone_triggerobject_phi() const{
  if(!c_standalone_triggerobject_phi_ && b_standalone_triggerobject_phi_){
    b_standalone_triggerobject_phi_->GetEntry(entry_);
    c_standalone_triggerobject_phi_ = true;
  }
  return standalone_triggerobject_phi_;
}

std::vector<float>* const & cfa_8::standalone_triggerobject_pt() const{
  if(!c_standalone_triggerobject_pt_ && b_standalone_triggerobject_pt_){
    b_standalone_triggerobject_pt_->GetEntry(entry_);
    c_standalone_triggerobject_pt_ = true;
  }
  return standalone_triggerobject_pt_;
}

std::vector<float>* const & cfa_8::standalone_triggerobject_px() const{
  if(!c_standalone_triggerobject_px_ && b_standalone_triggerobject_px_){
    b_standalone_triggerobject_px_->GetEntry(entry_);
    c_standalone_triggerobject_px_ = true;
  }
  return standalone_triggerobject_px_;
}

std::vector<float>* const & cfa_8::standalone_triggerobject_py() const{
  if(!c_standalone_triggerobject_py_ && b_standalone_triggerobject_py_){
    b_standalone_triggerobject_py_->GetEntry(entry_);
    c_standalone_triggerobject_py_ = true;
  }
  return standalone_triggerobject_py_;
}

std::vector<float>* const & cfa_8::standalone_triggerobject_pz() const{
  if(!c_standalone_triggerobject_pz_ && b_standalone_triggerobject_pz_){
    b_standalone_triggerobject_pz_->GetEntry(entry_);
    c_standalone_triggerobject_pz_ = true;
  }
  return standalone_triggerobject_pz_;
}

std::vector<float>* const & cfa_8::taus_Nprongs() const{
  if(!c_taus_Nprongs_ && b_taus_Nprongs_){
    b_taus_Nprongs_->GetEntry(entry_);
    c_taus_Nprongs_ = true;
  }
  return taus_Nprongs_;
}

std::vector<float>* const & cfa_8::taus_againstElectron() const{
  if(!c_taus_againstElectron_ && b_taus_againstElectron_){
    b_taus_againstElectron_->GetEntry(entry_);
    c_taus_againstElectron_ = true;
  }
  return taus_againstElectron_;
}

std::vector<float>* const & cfa_8::taus_againstElectronLoose() const{
  if(!c_taus_againstElectronLoose_ && b_taus_againstElectronLoose_){
    b_taus_againstElectronLoose_->GetEntry(entry_);
    c_taus_againstElectronLoose_ = true;
  }
  return taus_againstElectronLoose_;
}

std::vector<float>* const & cfa_8::taus_againstElectronMVA() const{
  if(!c_taus_againstElectronMVA_ && b_taus_againstElectronMVA_){
    b_taus_againstElectronMVA_->GetEntry(entry_);
    c_taus_againstElectronMVA_ = true;
  }
  return taus_againstElectronMVA_;
}

std::vector<float>* const & cfa_8::taus_againstElectronMedium() const{
  if(!c_taus_againstElectronMedium_ && b_taus_againstElectronMedium_){
    b_taus_againstElectronMedium_->GetEntry(entry_);
    c_taus_againstElectronMedium_ = true;
  }
  return taus_againstElectronMedium_;
}

std::vector<float>* const & cfa_8::taus_againstElectronTight() const{
  if(!c_taus_againstElectronTight_ && b_taus_againstElectronTight_){
    b_taus_againstElectronTight_->GetEntry(entry_);
    c_taus_againstElectronTight_ = true;
  }
  return taus_againstElectronTight_;
}

std::vector<float>* const & cfa_8::taus_againstMuon() const{
  if(!c_taus_againstMuon_ && b_taus_againstMuon_){
    b_taus_againstMuon_->GetEntry(entry_);
    c_taus_againstMuon_ = true;
  }
  return taus_againstMuon_;
}

std::vector<float>* const & cfa_8::taus_againstMuonLoose() const{
  if(!c_taus_againstMuonLoose_ && b_taus_againstMuonLoose_){
    b_taus_againstMuonLoose_->GetEntry(entry_);
    c_taus_againstMuonLoose_ = true;
  }
  return taus_againstMuonLoose_;
}

std::vector<float>* const & cfa_8::taus_againstMuonMedium() const{
  if(!c_taus_againstMuonMedium_ && b_taus_againstMuonMedium_){
    b_taus_againstMuonMedium_->GetEntry(entry_);
    c_taus_againstMuonMedium_ = true;
  }
  return taus_againstMuonMedium_;
}

std::vector<float>* const & cfa_8::taus_againstMuonTight() const{
  if(!c_taus_againstMuonTight_ && b_taus_againstMuonTight_){
    b_taus_againstMuonTight_->GetEntry(entry_);
    c_taus_againstMuonTight_ = true;
  }
  return taus_againstMuonTight_;
}

std::vector<float>* const & cfa_8::taus_byIsoUsingLeadingPi() const{
  if(!c_taus_byIsoUsingLeadingPi_ && b_taus_byIsoUsingLeadingPi_){
    b_taus_byIsoUsingLeadingPi_->GetEntry(entry_);
    c_taus_byIsoUsingLeadingPi_ = true;
  }
  return taus_byIsoUsingLeadingPi_;
}

std::vector<float>* const & cfa_8::taus_byIsolation() const{
  if(!c_taus_byIsolation_ && b_taus_byIsolation_){
    b_taus_byIsolation_->GetEntry(entry_);
    c_taus_byIsolation_ = true;
  }
  return taus_byIsolation_;
}

std::vector<float>* const & cfa_8::taus_byLooseIsolation() const{
  if(!c_taus_byLooseIsolation_ && b_taus_byLooseIsolation_){
    b_taus_byLooseIsolation_->GetEntry(entry_);
    c_taus_byLooseIsolation_ = true;
  }
  return taus_byLooseIsolation_;
}

std::vector<float>* const & cfa_8::taus_byLooseIsolationDeltaBetaCorr() const{
  if(!c_taus_byLooseIsolationDeltaBetaCorr_ && b_taus_byLooseIsolationDeltaBetaCorr_){
    b_taus_byLooseIsolationDeltaBetaCorr_->GetEntry(entry_);
    c_taus_byLooseIsolationDeltaBetaCorr_ = true;
  }
  return taus_byLooseIsolationDeltaBetaCorr_;
}

std::vector<float>* const & cfa_8::taus_byMediumIsolation() const{
  if(!c_taus_byMediumIsolation_ && b_taus_byMediumIsolation_){
    b_taus_byMediumIsolation_->GetEntry(entry_);
    c_taus_byMediumIsolation_ = true;
  }
  return taus_byMediumIsolation_;
}

std::vector<float>* const & cfa_8::taus_byMediumIsolationDeltaBetaCorr() const{
  if(!c_taus_byMediumIsolationDeltaBetaCorr_ && b_taus_byMediumIsolationDeltaBetaCorr_){
    b_taus_byMediumIsolationDeltaBetaCorr_->GetEntry(entry_);
    c_taus_byMediumIsolationDeltaBetaCorr_ = true;
  }
  return taus_byMediumIsolationDeltaBetaCorr_;
}

std::vector<float>* const & cfa_8::taus_byTightIsolation() const{
  if(!c_taus_byTightIsolation_ && b_taus_byTightIsolation_){
    b_taus_byTightIsolation_->GetEntry(entry_);
    c_taus_byTightIsolation_ = true;
  }
  return taus_byTightIsolation_;
}

std::vector<float>* const & cfa_8::taus_byTightIsolationDeltaBetaCorr() const{
  if(!c_taus_byTightIsolationDeltaBetaCorr_ && b_taus_byTightIsolationDeltaBetaCorr_){
    b_taus_byTightIsolationDeltaBetaCorr_->GetEntry(entry_);
    c_taus_byTightIsolationDeltaBetaCorr_ = true;
  }
  return taus_byTightIsolationDeltaBetaCorr_;
}

std::vector<float>* const & cfa_8::taus_byVLooseIsolation() const{
  if(!c_taus_byVLooseIsolation_ && b_taus_byVLooseIsolation_){
    b_taus_byVLooseIsolation_->GetEntry(entry_);
    c_taus_byVLooseIsolation_ = true;
  }
  return taus_byVLooseIsolation_;
}

std::vector<float>* const & cfa_8::taus_byVLooseIsolationDeltaBetaCorr() const{
  if(!c_taus_byVLooseIsolationDeltaBetaCorr_ && b_taus_byVLooseIsolationDeltaBetaCorr_){
    b_taus_byVLooseIsolationDeltaBetaCorr_->GetEntry(entry_);
    c_taus_byVLooseIsolationDeltaBetaCorr_ = true;
  }
  return taus_byVLooseIsolationDeltaBetaCorr_;
}

std::vector<float>* const & cfa_8::taus_charge() const{
  if(!c_taus_charge_ && b_taus_charge_){
    b_taus_charge_->GetEntry(entry_);
    c_taus_charge_ = true;
  }
  return taus_charge_;
}

std::vector<float>* const & cfa_8::taus_decayModeFinding() const{
  if(!c_taus_decayModeFinding_ && b_taus_decayModeFinding_){
    b_taus_decayModeFinding_->GetEntry(entry_);
    c_taus_decayModeFinding_ = true;
  }
  return taus_decayModeFinding_;
}

std::vector<float>* const & cfa_8::taus_ecalIsoUsingLeadingPi() const{
  if(!c_taus_ecalIsoUsingLeadingPi_ && b_taus_ecalIsoUsingLeadingPi_){
    b_taus_ecalIsoUsingLeadingPi_->GetEntry(entry_);
    c_taus_ecalIsoUsingLeadingPi_ = true;
  }
  return taus_ecalIsoUsingLeadingPi_;
}

std::vector<float>* const & cfa_8::taus_ecalIsolation() const{
  if(!c_taus_ecalIsolation_ && b_taus_ecalIsolation_){
    b_taus_ecalIsolation_->GetEntry(entry_);
    c_taus_ecalIsolation_ = true;
  }
  return taus_ecalIsolation_;
}

std::vector<float>* const & cfa_8::taus_ecalStripSumEOverPLead() const{
  if(!c_taus_ecalStripSumEOverPLead_ && b_taus_ecalStripSumEOverPLead_){
    b_taus_ecalStripSumEOverPLead_->GetEntry(entry_);
    c_taus_ecalStripSumEOverPLead_ = true;
  }
  return taus_ecalStripSumEOverPLead_;
}

std::vector<float>* const & cfa_8::taus_elecPreIdDecision() const{
  if(!c_taus_elecPreIdDecision_ && b_taus_elecPreIdDecision_){
    b_taus_elecPreIdDecision_->GetEntry(entry_);
    c_taus_elecPreIdDecision_ = true;
  }
  return taus_elecPreIdDecision_;
}

std::vector<float>* const & cfa_8::taus_elecPreIdOutput() const{
  if(!c_taus_elecPreIdOutput_ && b_taus_elecPreIdOutput_){
    b_taus_elecPreIdOutput_->GetEntry(entry_);
    c_taus_elecPreIdOutput_ = true;
  }
  return taus_elecPreIdOutput_;
}

std::vector<float>* const & cfa_8::taus_emf() const{
  if(!c_taus_emf_ && b_taus_emf_){
    b_taus_emf_->GetEntry(entry_);
    c_taus_emf_ = true;
  }
  return taus_emf_;
}

std::vector<float>* const & cfa_8::taus_energy() const{
  if(!c_taus_energy_ && b_taus_energy_){
    b_taus_energy_->GetEntry(entry_);
    c_taus_energy_ = true;
  }
  return taus_energy_;
}

std::vector<float>* const & cfa_8::taus_et() const{
  if(!c_taus_et_ && b_taus_et_){
    b_taus_et_->GetEntry(entry_);
    c_taus_et_ = true;
  }
  return taus_et_;
}

std::vector<float>* const & cfa_8::taus_eta() const{
  if(!c_taus_eta_ && b_taus_eta_){
    b_taus_eta_->GetEntry(entry_);
    c_taus_eta_ = true;
  }
  return taus_eta_;
}

std::vector<float>* const & cfa_8::taus_hcal3x3OverPLead() const{
  if(!c_taus_hcal3x3OverPLead_ && b_taus_hcal3x3OverPLead_){
    b_taus_hcal3x3OverPLead_->GetEntry(entry_);
    c_taus_hcal3x3OverPLead_ = true;
  }
  return taus_hcal3x3OverPLead_;
}

std::vector<float>* const & cfa_8::taus_hcalMaxOverPLead() const{
  if(!c_taus_hcalMaxOverPLead_ && b_taus_hcalMaxOverPLead_){
    b_taus_hcalMaxOverPLead_->GetEntry(entry_);
    c_taus_hcalMaxOverPLead_ = true;
  }
  return taus_hcalMaxOverPLead_;
}

std::vector<float>* const & cfa_8::taus_hcalTotOverPLead() const{
  if(!c_taus_hcalTotOverPLead_ && b_taus_hcalTotOverPLead_){
    b_taus_hcalTotOverPLead_->GetEntry(entry_);
    c_taus_hcalTotOverPLead_ = true;
  }
  return taus_hcalTotOverPLead_;
}

std::vector<float>* const & cfa_8::taus_isoPFChargedHadrCandsPtSum() const{
  if(!c_taus_isoPFChargedHadrCandsPtSum_ && b_taus_isoPFChargedHadrCandsPtSum_){
    b_taus_isoPFChargedHadrCandsPtSum_->GetEntry(entry_);
    c_taus_isoPFChargedHadrCandsPtSum_ = true;
  }
  return taus_isoPFChargedHadrCandsPtSum_;
}

std::vector<float>* const & cfa_8::taus_isoPFGammaCandsEtSum() const{
  if(!c_taus_isoPFGammaCandsEtSum_ && b_taus_isoPFGammaCandsEtSum_){
    b_taus_isoPFGammaCandsEtSum_->GetEntry(entry_);
    c_taus_isoPFGammaCandsEtSum_ = true;
  }
  return taus_isoPFGammaCandsEtSum_;
}

std::vector<float>* const & cfa_8::taus_leadPFChargedHadrCand_ECAL_eta() const{
  if(!c_taus_leadPFChargedHadrCand_ECAL_eta_ && b_taus_leadPFChargedHadrCand_ECAL_eta_){
    b_taus_leadPFChargedHadrCand_ECAL_eta_->GetEntry(entry_);
    c_taus_leadPFChargedHadrCand_ECAL_eta_ = true;
  }
  return taus_leadPFChargedHadrCand_ECAL_eta_;
}

std::vector<float>* const & cfa_8::taus_leadPFChargedHadrCand_charge() const{
  if(!c_taus_leadPFChargedHadrCand_charge_ && b_taus_leadPFChargedHadrCand_charge_){
    b_taus_leadPFChargedHadrCand_charge_->GetEntry(entry_);
    c_taus_leadPFChargedHadrCand_charge_ = true;
  }
  return taus_leadPFChargedHadrCand_charge_;
}

std::vector<float>* const & cfa_8::taus_leadPFChargedHadrCand_eta() const{
  if(!c_taus_leadPFChargedHadrCand_eta_ && b_taus_leadPFChargedHadrCand_eta_){
    b_taus_leadPFChargedHadrCand_eta_->GetEntry(entry_);
    c_taus_leadPFChargedHadrCand_eta_ = true;
  }
  return taus_leadPFChargedHadrCand_eta_;
}

std::vector<float>* const & cfa_8::taus_leadPFChargedHadrCand_phi() const{
  if(!c_taus_leadPFChargedHadrCand_phi_ && b_taus_leadPFChargedHadrCand_phi_){
    b_taus_leadPFChargedHadrCand_phi_->GetEntry(entry_);
    c_taus_leadPFChargedHadrCand_phi_ = true;
  }
  return taus_leadPFChargedHadrCand_phi_;
}

std::vector<float>* const & cfa_8::taus_leadPFChargedHadrCand_pt() const{
  if(!c_taus_leadPFChargedHadrCand_pt_ && b_taus_leadPFChargedHadrCand_pt_){
    b_taus_leadPFChargedHadrCand_pt_->GetEntry(entry_);
    c_taus_leadPFChargedHadrCand_pt_ = true;
  }
  return taus_leadPFChargedHadrCand_pt_;
}

std::vector<float>* const & cfa_8::taus_leadingTrackFinding() const{
  if(!c_taus_leadingTrackFinding_ && b_taus_leadingTrackFinding_){
    b_taus_leadingTrackFinding_->GetEntry(entry_);
    c_taus_leadingTrackFinding_ = true;
  }
  return taus_leadingTrackFinding_;
}

std::vector<float>* const & cfa_8::taus_leadingTrackPtCut() const{
  if(!c_taus_leadingTrackPtCut_ && b_taus_leadingTrackPtCut_){
    b_taus_leadingTrackPtCut_->GetEntry(entry_);
    c_taus_leadingTrackPtCut_ = true;
  }
  return taus_leadingTrackPtCut_;
}

std::vector<float>* const & cfa_8::taus_muDecision() const{
  if(!c_taus_muDecision_ && b_taus_muDecision_){
    b_taus_muDecision_->GetEntry(entry_);
    c_taus_muDecision_ = true;
  }
  return taus_muDecision_;
}

std::vector<float>* const & cfa_8::taus_phi() const{
  if(!c_taus_phi_ && b_taus_phi_){
    b_taus_phi_->GetEntry(entry_);
    c_taus_phi_ = true;
  }
  return taus_phi_;
}

std::vector<float>* const & cfa_8::taus_pt() const{
  if(!c_taus_pt_ && b_taus_pt_){
    b_taus_pt_->GetEntry(entry_);
    c_taus_pt_ = true;
  }
  return taus_pt_;
}

std::vector<float>* const & cfa_8::taus_px() const{
  if(!c_taus_px_ && b_taus_px_){
    b_taus_px_->GetEntry(entry_);
    c_taus_px_ = true;
  }
  return taus_px_;
}

std::vector<float>* const & cfa_8::taus_py() const{
  if(!c_taus_py_ && b_taus_py_){
    b_taus_py_->GetEntry(entry_);
    c_taus_py_ = true;
  }
  return taus_py_;
}

std::vector<float>* const & cfa_8::taus_pz() const{
  if(!c_taus_pz_ && b_taus_pz_){
    b_taus_pz_->GetEntry(entry_);
    c_taus_pz_ = true;
  }
  return taus_pz_;
}

std::vector<float>* const & cfa_8::taus_signalPFChargedHadrCandsSize() const{
  if(!c_taus_signalPFChargedHadrCandsSize_ && b_taus_signalPFChargedHadrCandsSize_){
    b_taus_signalPFChargedHadrCandsSize_->GetEntry(entry_);
    c_taus_signalPFChargedHadrCandsSize_ = true;
  }
  return taus_signalPFChargedHadrCandsSize_;
}

std::vector<float>* const & cfa_8::taus_status() const{
  if(!c_taus_status_ && b_taus_status_){
    b_taus_status_->GetEntry(entry_);
    c_taus_status_ = true;
  }
  return taus_status_;
}

std::vector<float>* const & cfa_8::taus_taNC() const{
  if(!c_taus_taNC_ && b_taus_taNC_){
    b_taus_taNC_->GetEntry(entry_);
    c_taus_taNC_ = true;
  }
  return taus_taNC_;
}

std::vector<float>* const & cfa_8::taus_taNC_half() const{
  if(!c_taus_taNC_half_ && b_taus_taNC_half_){
    b_taus_taNC_half_->GetEntry(entry_);
    c_taus_taNC_half_ = true;
  }
  return taus_taNC_half_;
}

std::vector<float>* const & cfa_8::taus_taNC_one() const{
  if(!c_taus_taNC_one_ && b_taus_taNC_one_){
    b_taus_taNC_one_->GetEntry(entry_);
    c_taus_taNC_one_ = true;
  }
  return taus_taNC_one_;
}

std::vector<float>* const & cfa_8::taus_taNC_quarter() const{
  if(!c_taus_taNC_quarter_ && b_taus_taNC_quarter_){
    b_taus_taNC_quarter_->GetEntry(entry_);
    c_taus_taNC_quarter_ = true;
  }
  return taus_taNC_quarter_;
}

std::vector<float>* const & cfa_8::taus_taNC_tenth() const{
  if(!c_taus_taNC_tenth_ && b_taus_taNC_tenth_){
    b_taus_taNC_tenth_->GetEntry(entry_);
    c_taus_taNC_tenth_ = true;
  }
  return taus_taNC_tenth_;
}

std::vector<float>* const & cfa_8::taus_theta() const{
  if(!c_taus_theta_ && b_taus_theta_){
    b_taus_theta_->GetEntry(entry_);
    c_taus_theta_ = true;
  }
  return taus_theta_;
}

std::vector<float>* const & cfa_8::taus_tkIsoUsingLeadingPi() const{
  if(!c_taus_tkIsoUsingLeadingPi_ && b_taus_tkIsoUsingLeadingPi_){
    b_taus_tkIsoUsingLeadingPi_->GetEntry(entry_);
    c_taus_tkIsoUsingLeadingPi_ = true;
  }
  return taus_tkIsoUsingLeadingPi_;
}

std::vector<float>* const & cfa_8::taus_trackIsolation() const{
  if(!c_taus_trackIsolation_ && b_taus_trackIsolation_){
    b_taus_trackIsolation_->GetEntry(entry_);
    c_taus_trackIsolation_ = true;
  }
  return taus_trackIsolation_;
}

std::vector<float>* const & cfa_8::tcmets_et() const{
  if(!c_tcmets_et_ && b_tcmets_et_){
    b_tcmets_et_->GetEntry(entry_);
    c_tcmets_et_ = true;
  }
  return tcmets_et_;
}

std::vector<float>* const & cfa_8::tcmets_ex() const{
  if(!c_tcmets_ex_ && b_tcmets_ex_){
    b_tcmets_ex_->GetEntry(entry_);
    c_tcmets_ex_ = true;
  }
  return tcmets_ex_;
}

std::vector<float>* const & cfa_8::tcmets_ey() const{
  if(!c_tcmets_ey_ && b_tcmets_ey_){
    b_tcmets_ey_->GetEntry(entry_);
    c_tcmets_ey_ = true;
  }
  return tcmets_ey_;
}

std::vector<float>* const & cfa_8::tcmets_phi() const{
  if(!c_tcmets_phi_ && b_tcmets_phi_){
    b_tcmets_phi_->GetEntry(entry_);
    c_tcmets_phi_ = true;
  }
  return tcmets_phi_;
}

std::vector<float>* const & cfa_8::tcmets_sumEt() const{
  if(!c_tcmets_sumEt_ && b_tcmets_sumEt_){
    b_tcmets_sumEt_->GetEntry(entry_);
    c_tcmets_sumEt_ = true;
  }
  return tcmets_sumEt_;
}

Int_t const & cfa_8::trackercoherentnoisefilter1_decision() const{
  if(!c_trackercoherentnoisefilter1_decision_ && b_trackercoherentnoisefilter1_decision_){
    b_trackercoherentnoisefilter1_decision_->GetEntry(entry_);
    c_trackercoherentnoisefilter1_decision_ = true;
  }
  return trackercoherentnoisefilter1_decision_;
}

Int_t const & cfa_8::trackercoherentnoisefilter2_decision() const{
  if(!c_trackercoherentnoisefilter2_decision_ && b_trackercoherentnoisefilter2_decision_){
    b_trackercoherentnoisefilter2_decision_->GetEntry(entry_);
    c_trackercoherentnoisefilter2_decision_ = true;
  }
  return trackercoherentnoisefilter2_decision_;
}

Int_t const & cfa_8::trackertoomanyclustersfilter_decision() const{
  if(!c_trackertoomanyclustersfilter_decision_ && b_trackertoomanyclustersfilter_decision_){
    b_trackertoomanyclustersfilter_decision_->GetEntry(entry_);
    c_trackertoomanyclustersfilter_decision_ = true;
  }
  return trackertoomanyclustersfilter_decision_;
}

Int_t const & cfa_8::trackertoomanyseedsfilter_decision() const{
  if(!c_trackertoomanyseedsfilter_decision_ && b_trackertoomanyseedsfilter_decision_){
    b_trackertoomanyseedsfilter_decision_->GetEntry(entry_);
    c_trackertoomanyseedsfilter_decision_ = true;
  }
  return trackertoomanyseedsfilter_decision_;
}

Int_t const & cfa_8::trackertoomanytripletsfilter_decision() const{
  if(!c_trackertoomanytripletsfilter_decision_ && b_trackertoomanytripletsfilter_decision_){
    b_trackertoomanytripletsfilter_decision_->GetEntry(entry_);
    c_trackertoomanytripletsfilter_decision_ = true;
  }
  return trackertoomanytripletsfilter_decision_;
}

Int_t const & cfa_8::trackingfailurefilter_decision() const{
  if(!c_trackingfailurefilter_decision_ && b_trackingfailurefilter_decision_){
    b_trackingfailurefilter_decision_->GetEntry(entry_);
    c_trackingfailurefilter_decision_ = true;
  }
  return trackingfailurefilter_decision_;
}

std::vector<float>* const & cfa_8::tracks_chg() const{
  if(!c_tracks_chg_ && b_tracks_chg_){
    b_tracks_chg_->GetEntry(entry_);
    c_tracks_chg_ = true;
  }
  return tracks_chg_;
}

std::vector<float>* const & cfa_8::tracks_chi2() const{
  if(!c_tracks_chi2_ && b_tracks_chi2_){
    b_tracks_chi2_->GetEntry(entry_);
    c_tracks_chi2_ = true;
  }
  return tracks_chi2_;
}

std::vector<float>* const & cfa_8::tracks_d0dum() const{
  if(!c_tracks_d0dum_ && b_tracks_d0dum_){
    b_tracks_d0dum_->GetEntry(entry_);
    c_tracks_d0dum_ = true;
  }
  return tracks_d0dum_;
}

std::vector<float>* const & cfa_8::tracks_d0dumErr() const{
  if(!c_tracks_d0dumErr_ && b_tracks_d0dumErr_){
    b_tracks_d0dumErr_->GetEntry(entry_);
    c_tracks_d0dumErr_ = true;
  }
  return tracks_d0dumErr_;
}

std::vector<float>* const & cfa_8::tracks_dz() const{
  if(!c_tracks_dz_ && b_tracks_dz_){
    b_tracks_dz_->GetEntry(entry_);
    c_tracks_dz_ = true;
  }
  return tracks_dz_;
}

std::vector<float>* const & cfa_8::tracks_dzErr() const{
  if(!c_tracks_dzErr_ && b_tracks_dzErr_){
    b_tracks_dzErr_->GetEntry(entry_);
    c_tracks_dzErr_ = true;
  }
  return tracks_dzErr_;
}

std::vector<float>* const & cfa_8::tracks_eta() const{
  if(!c_tracks_eta_ && b_tracks_eta_){
    b_tracks_eta_->GetEntry(entry_);
    c_tracks_eta_ = true;
  }
  return tracks_eta_;
}

std::vector<float>* const & cfa_8::tracks_etaErr() const{
  if(!c_tracks_etaErr_ && b_tracks_etaErr_){
    b_tracks_etaErr_->GetEntry(entry_);
    c_tracks_etaErr_ = true;
  }
  return tracks_etaErr_;
}

std::vector<float>* const & cfa_8::tracks_highPurity() const{
  if(!c_tracks_highPurity_ && b_tracks_highPurity_){
    b_tracks_highPurity_->GetEntry(entry_);
    c_tracks_highPurity_ = true;
  }
  return tracks_highPurity_;
}

std::vector<float>* const & cfa_8::tracks_ndof() const{
  if(!c_tracks_ndof_ && b_tracks_ndof_){
    b_tracks_ndof_->GetEntry(entry_);
    c_tracks_ndof_ = true;
  }
  return tracks_ndof_;
}

std::vector<float>* const & cfa_8::tracks_numlosthits() const{
  if(!c_tracks_numlosthits_ && b_tracks_numlosthits_){
    b_tracks_numlosthits_->GetEntry(entry_);
    c_tracks_numlosthits_ = true;
  }
  return tracks_numlosthits_;
}

std::vector<float>* const & cfa_8::tracks_numvalhits() const{
  if(!c_tracks_numvalhits_ && b_tracks_numvalhits_){
    b_tracks_numvalhits_->GetEntry(entry_);
    c_tracks_numvalhits_ = true;
  }
  return tracks_numvalhits_;
}

std::vector<float>* const & cfa_8::tracks_phi() const{
  if(!c_tracks_phi_ && b_tracks_phi_){
    b_tracks_phi_->GetEntry(entry_);
    c_tracks_phi_ = true;
  }
  return tracks_phi_;
}

std::vector<float>* const & cfa_8::tracks_phiErr() const{
  if(!c_tracks_phiErr_ && b_tracks_phiErr_){
    b_tracks_phiErr_->GetEntry(entry_);
    c_tracks_phiErr_ = true;
  }
  return tracks_phiErr_;
}

std::vector<float>* const & cfa_8::tracks_pt() const{
  if(!c_tracks_pt_ && b_tracks_pt_){
    b_tracks_pt_->GetEntry(entry_);
    c_tracks_pt_ = true;
  }
  return tracks_pt_;
}

std::vector<float>* const & cfa_8::tracks_ptErr() const{
  if(!c_tracks_ptErr_ && b_tracks_ptErr_){
    b_tracks_ptErr_->GetEntry(entry_);
    c_tracks_ptErr_ = true;
  }
  return tracks_ptErr_;
}

std::vector<float>* const & cfa_8::tracks_px() const{
  if(!c_tracks_px_ && b_tracks_px_){
    b_tracks_px_->GetEntry(entry_);
    c_tracks_px_ = true;
  }
  return tracks_px_;
}

std::vector<float>* const & cfa_8::tracks_py() const{
  if(!c_tracks_py_ && b_tracks_py_){
    b_tracks_py_->GetEntry(entry_);
    c_tracks_py_ = true;
  }
  return tracks_py_;
}

std::vector<float>* const & cfa_8::tracks_pz() const{
  if(!c_tracks_pz_ && b_tracks_pz_){
    b_tracks_pz_->GetEntry(entry_);
    c_tracks_pz_ = true;
  }
  return tracks_pz_;
}

std::vector<float>* const & cfa_8::tracks_vx() const{
  if(!c_tracks_vx_ && b_tracks_vx_){
    b_tracks_vx_->GetEntry(entry_);
    c_tracks_vx_ = true;
  }
  return tracks_vx_;
}

std::vector<float>* const & cfa_8::tracks_vy() const{
  if(!c_tracks_vy_ && b_tracks_vy_){
    b_tracks_vy_->GetEntry(entry_);
    c_tracks_vy_ = true;
  }
  return tracks_vy_;
}

std::vector<float>* const & cfa_8::tracks_vz() const{
  if(!c_tracks_vz_ && b_tracks_vz_){
    b_tracks_vz_->GetEntry(entry_);
    c_tracks_vz_ = true;
  }
  return tracks_vz_;
}

std::vector<bool>* const & cfa_8::trigger_decision() const{
  if(!c_trigger_decision_ && b_trigger_decision_){
    b_trigger_decision_->GetEntry(entry_);
    trigger_decision_->resize(v_trigger_decision_->size());
    for(unsigned i = 0; i < trigger_decision_->size(); ++i){
      trigger_decision_->at(i) = static_cast<bool>(v_trigger_decision_->at(i));
    }
    c_trigger_decision_ = true;
  }
  return trigger_decision_;
}

std::vector<std::string>* const & cfa_8::trigger_lastfiltername() const{
  if(!c_trigger_lastfiltername_ && b_trigger_lastfiltername_){
    b_trigger_lastfiltername_->GetEntry(entry_);
    c_trigger_lastfiltername_ = true;
  }
  return trigger_lastfiltername_;
}

std::vector<std::string>* const & cfa_8::trigger_name() const{
  if(!c_trigger_name_ && b_trigger_name_){
    b_trigger_name_->GetEntry(entry_);
    c_trigger_name_ = true;
  }
  return trigger_name_;
}

std::vector<float>* const & cfa_8::trigger_prescalevalue() const{
  if(!c_trigger_prescalevalue_ && b_trigger_prescalevalue_){
    b_trigger_prescalevalue_->GetEntry(entry_);
    c_trigger_prescalevalue_ = true;
  }
  return trigger_prescalevalue_;
}

std::vector<std::vector<std::string> >* const & cfa_8::triggerobject_collectionname() const{
  if(!c_triggerobject_collectionname_ && b_triggerobject_collectionname_){
    b_triggerobject_collectionname_->GetEntry(entry_);
    c_triggerobject_collectionname_ = true;
  }
  return triggerobject_collectionname_;
}

std::vector<std::vector<float> >* const & cfa_8::triggerobject_energy() const{
  if(!c_triggerobject_energy_ && b_triggerobject_energy_){
    b_triggerobject_energy_->GetEntry(entry_);
    c_triggerobject_energy_ = true;
  }
  return triggerobject_energy_;
}

std::vector<std::vector<float> >* const & cfa_8::triggerobject_et() const{
  if(!c_triggerobject_et_ && b_triggerobject_et_){
    b_triggerobject_et_->GetEntry(entry_);
    c_triggerobject_et_ = true;
  }
  return triggerobject_et_;
}

std::vector<std::vector<float> >* const & cfa_8::triggerobject_eta() const{
  if(!c_triggerobject_eta_ && b_triggerobject_eta_){
    b_triggerobject_eta_->GetEntry(entry_);
    c_triggerobject_eta_ = true;
  }
  return triggerobject_eta_;
}

std::vector<std::vector<float> >* const & cfa_8::triggerobject_phi() const{
  if(!c_triggerobject_phi_ && b_triggerobject_phi_){
    b_triggerobject_phi_->GetEntry(entry_);
    c_triggerobject_phi_ = true;
  }
  return triggerobject_phi_;
}

std::vector<std::vector<float> >* const & cfa_8::triggerobject_pt() const{
  if(!c_triggerobject_pt_ && b_triggerobject_pt_){
    b_triggerobject_pt_->GetEntry(entry_);
    c_triggerobject_pt_ = true;
  }
  return triggerobject_pt_;
}

std::vector<std::vector<float> >* const & cfa_8::triggerobject_px() const{
  if(!c_triggerobject_px_ && b_triggerobject_px_){
    b_triggerobject_px_->GetEntry(entry_);
    c_triggerobject_px_ = true;
  }
  return triggerobject_px_;
}

std::vector<std::vector<float> >* const & cfa_8::triggerobject_py() const{
  if(!c_triggerobject_py_ && b_triggerobject_py_){
    b_triggerobject_py_->GetEntry(entry_);
    c_triggerobject_py_ = true;
  }
  return triggerobject_py_;
}

std::vector<std::vector<float> >* const & cfa_8::triggerobject_pz() const{
  if(!c_triggerobject_pz_ && b_triggerobject_pz_){
    b_triggerobject_pz_->GetEntry(entry_);
    c_triggerobject_pz_ = true;
  }
  return triggerobject_pz_;
}

Int_t const & cfa_8::trk_nTOBTEC() const{
  if(!c_trk_nTOBTEC_ && b_trk_nTOBTEC_){
    b_trk_nTOBTEC_->GetEntry(entry_);
    c_trk_nTOBTEC_ = true;
  }
  return trk_nTOBTEC_;
}

Float_t const & cfa_8::trk_ratioAllTOBTEC() const{
  if(!c_trk_ratioAllTOBTEC_ && b_trk_ratioAllTOBTEC_){
    b_trk_ratioAllTOBTEC_->GetEntry(entry_);
    c_trk_ratioAllTOBTEC_ = true;
  }
  return trk_ratioAllTOBTEC_;
}

Float_t const & cfa_8::trk_ratioJetTOBTEC() const{
  if(!c_trk_ratioJetTOBTEC_ && b_trk_ratioJetTOBTEC_){
    b_trk_ratioJetTOBTEC_->GetEntry(entry_);
    c_trk_ratioJetTOBTEC_ = true;
  }
  return trk_ratioJetTOBTEC_;
}

Float_t const & cfa_8::weight() const{
  if(!c_weight_ && b_weight_){
    b_weight_->GetEntry(entry_);
    c_weight_ = true;
  }
  return weight_;
}

