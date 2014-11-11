// event_handler: Defines reduced tree with RA4 variables

#include "event_handler.hpp"

#include <cfloat>
#include <ctime>
#include <cmath>
#include <cstdio>

#include <utility>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <limits>

#include "TMath.h"
#include "TFile.h"
#include "TTree.h"
#include "TLorentzVector.h"

#include "small_tree.hpp"
#include "utilities.hpp"
#include "timer.hpp"
#include "mt2_bisect.hpp"
#include "mt2w_bisect.hpp"
#include "cfa_8.hpp"
#include "cfa_13.hpp"

using namespace std;
const double CSVCuts[] = {0.244, 0.679, 0.898};

event_handler::event_handler(const std::string &fileName):
  ra4_objects(fileName){
}

void event_handler::ReduceTree(int Nentries, TString outFilename, int Ntotentries){
  // for(int entry(0); entry < Nentries; entry++){
  //   GetEntry(entry);

  //   cout<<"========== Event "<<entry+1<<" ============"<<endl;
  //   for(size_t imc = 0; imc < mc_doc_id()->size(); imc++){
  //     if(abs(mc_doc_id()->at(imc))==15){// && mc_doc_status()->at(imc)==23){
  //     cout<<imc<<": ID "<<mc_doc_id()->at(imc)<<",   \tMom ID "<<mc_doc_mother_id()->at(imc)
  //      <<", \tGMom ID "<<mc_doc_grandmother_id()->at(imc)
  //      <<", \tGGMom ID "<<mc_doc_ggrandmother_id()->at(imc)
  //      <<", \tN daughters "<<mc_doc_numOfDaughters()->at(imc)
  //      <<",   \tN moms "<<mc_doc_numOfMothers()->at(imc)
  //      <<",   \tstatus "<<mc_doc_status()->at(imc)
  //      <<",   \tpT "<<mc_doc_pt()->at(imc)
  //      <<",   \teta "<<mc_doc_eta()->at(imc)
  //      <<",   \tphi "<<mc_doc_phi()->at(imc)<<endl;
  //     }
  //   }
  //   cout<<endl<<endl;
  // }

  const float bad_val = -999.;

  TFile outFile(outFilename, "recreate");
  outFile.cd();

  // Reduced tree
  small_tree tree;
  float xsec(cross_section(outFilename));
  const float luminosity = 1000; // 1 fb^-1
  const float jet_ptThresh = 40;

  double deltaR, lepmax_pt, lepmax_energy, lepmax_px, lepmax_py, lepmax_pz;
  TLorentzVector lepmax_p4;
  int mcID, mcmomID;
  bool fromW;
  float spher[2][2], spher_jets[2][2], spher_nolin[2][2];
  float pt(bad_val), px(bad_val), py(bad_val), eig1(bad_val), eig2(bad_val);

  const float W_mass(80.385);

  mt2_bisect::mt2 mt2_calc;
  mt2_calc.set_mn(W_mass);
  mt2w_bisect::mt2w mt2w_calc(1.0e5, -1.0);
  vector<int_double> csv_sorted;
  Timer timer(Nentries);
  timer.Start();
  for(int entry(0); entry < Nentries; entry++){
    if(entry%1000==0 && entry!=0){
      timer.PrintRemainingTime();
    }
    timer.Iterate();
    GetEntry(entry);
    ////////////////   Leptons   ////////////////
    vector<int> signal_electrons = GetElectrons();
    vector<int> veto_electrons = GetElectrons(false);
    vector<int> signal_muons = GetMuons();
    vector<int> veto_muons = GetMuons(false);
    vector<int> good_jets = GetJets(signal_electrons, signal_muons, veto_electrons, veto_muons, 20.0, 2.4, tree.ht);
    tree.nels  = signal_electrons.size();
    tree.nvels = veto_electrons.size();
    tree.nmus  = signal_muons.size();
    tree.nvmus = veto_muons.size();
    if(tree.nels+tree.nmus == tree.nvels+tree.nvmus) tree.nleps = tree.nels+tree.nmus;
    else tree.nleps = static_cast<int>(bad_val);

    ////////////////  Tracks  ////////////////
    if(Type()==typeid(cfa_8)){ //This should be changed when isotk becomes available in cfa_13!
      tree.nisotrks = 0;
      for(size_t i = 0; i < isotk_pt()->size(); ++i){
	if(IsGoodIsoTrack(i)) ++tree.nisotrks;
      }
    }else{
      tree.nisotrks = -1;
    }

    ////////////////   Jets   ////////////////
    tree.v_jets_pt.resize(0);
    tree.v_jets_eta.resize(0);
    tree.v_jets_phi.resize(0);
    tree.v_jets_csv.resize(0);
    csv_sorted.resize(0);
    spher[0][0] = 0; spher[0][1] = 0; spher[1][0] = 0; spher[1][1] = 0; 
    spher_nolin[0][0] = 0; spher_nolin[0][1] = 0; spher_nolin[1][0] = 0; spher_nolin[1][1] = 0; 
    spher_jets[0][0] = 0; spher_jets[0][1] = 0; spher_jets[1][0] = 0; spher_jets[1][1] = 0; 
    tree.njets = 0;
    tree.nbl = 0; tree.nbm = 0; tree.nbt = 0;

    tree.ht=0.0;
    tree.mindphin_metjet = getMinDeltaPhiMETN(3, 50.0, 2.4, 30.0, 2.4, true);
    for(size_t i = 0; i<good_jets.size(); ++i){
      const size_t ijet = good_jets.at(i);
      if(ijet>=jets_pt()->size()) continue;
      pt = jets_pt()->at(ijet);
      px = jets_px()->at(ijet);
      py = jets_py()->at(ijet);
      tree.v_jets_pt.push_back(pt);
      tree.v_jets_eta.push_back(jets_eta()->at(ijet));
      tree.v_jets_phi.push_back(jets_phi()->at(ijet));
      double csv = jets_btag_secVertexCombined()->at(ijet);
      tree.v_jets_csv.push_back(csv);
      csv_sorted.push_back(make_pair(tree.v_jets_csv.size()-1, csv));
      // Transverse sphericity matrix (not including 1/sum(pt), which cancels in the ratio of eig)
      spher_nolin[0][0] += px*px; spher_nolin[0][1] += px*py; 
      spher_nolin[1][0] += px*py; spher_nolin[1][1] += py*py; 
      // Linearized transverse sphericity matrix
      spher[0][0] += px*px/pt; spher[0][1] += px*py/pt; 
      spher[1][0] += px*py/pt; spher[1][1] += py*py/pt; 
      // Linearized transverse sphericity matrix with only jets
      spher_jets[0][0] += px*px/pt; spher_jets[0][1] += px*py/pt; 
      spher_jets[1][0] += px*py/pt; spher_jets[1][1] += py*py/pt; 

      //       cout<<ijet<<": csv "<<csv<<", eta "<<jets_eta()->at(ijet)<<", phi "<<jets_phi()->at(ijet)<<endl;
      if(jets_pt()->at(ijet) >= jet_ptThresh) {
        tree.njets++;
	tree.ht+=jets_pt()->at(ijet);
        if(csv >= CSVCuts[0]) tree.nbl++;
        if(csv >= CSVCuts[1]) tree.nbm++;
        if(csv >= CSVCuts[2]) tree.nbt++;
      }
    } // Loop over all jets

    if(eigen2x2(spher_jets, eig1, eig2)) tree.spher_jets = 2*eig2/(eig1+eig2);
    else tree.spher_jets = bad_val;
    
    if(tree.v_jets_csv.size() >= 2){
      sort(csv_sorted.begin(), csv_sorted.end(), id_big2small);
      tree.dr_bb = dR(tree.v_jets_eta[csv_sorted[0].first], tree.v_jets_eta[csv_sorted[1].first], 
                      tree.v_jets_phi[csv_sorted[0].first], tree.v_jets_phi[csv_sorted[1].first]);
    } else tree.dr_bb = bad_val;
    
    ////////////////   Fat Jets   ////////////////
    tree.nfjets = 0;
    tree.mj = 0;
    csv_sorted.resize(0);
    tree.v_fjets_pt.resize(0); tree.v_fjets_mj.resize(0); 
    tree.v_fjets_eta.resize(0); tree.v_fjets_phi.resize(0); 
    for(size_t ijet(0); ijet<fastjets_AK4_R1p2_R0p5pT30_px()->size(); ++ijet){
      pt = sqrt(pow(fastjets_AK4_R1p2_R0p5pT30_px()->at(ijet),2)+pow(fastjets_AK4_R1p2_R0p5pT30_py()->at(ijet),2));
      csv_sorted.push_back(make_pair(ijet, pt));
    }
    if(csv_sorted.size() >= 2)
      sort(csv_sorted.begin(), csv_sorted.end(), id_big2small);
    for(size_t iijet(0); iijet<fastjets_AK4_R1p2_R0p5pT30_px()->size(); ++iijet){
      size_t ijet(csv_sorted[iijet].first);
      pt = sqrt(pow(fastjets_AK4_R1p2_R0p5pT30_px()->at(ijet),2)+pow(fastjets_AK4_R1p2_R0p5pT30_py()->at(ijet),2));
      tree.v_fjets_pt.push_back(pt);
      tree.v_fjets_eta.push_back(fastjets_AK4_R1p2_R0p5pT30_eta()->at(ijet));
      tree.v_fjets_phi.push_back(fastjets_AK4_R1p2_R0p5pT30_phi()->at(ijet));
      float mj = sqrt(pow(fastjets_AK4_R1p2_R0p5pT30_energy()->at(ijet),2)
                      -pow(fastjets_AK4_R1p2_R0p5pT30_px()->at(ijet),2)
                      -pow(fastjets_AK4_R1p2_R0p5pT30_py()->at(ijet),2)
                      -pow(fastjets_AK4_R1p2_R0p5pT30_pz()->at(ijet),2));
      tree.v_fjets_mj.push_back(mj);
      if(pt>50){
        tree.mj += mj;
        tree.nfjets++;
      }
    }

    ////////////////  Clean Fat Jets ////////////
    tree.ncfjets = 0;
    tree.cmj = 0.;
    tree.v_cfjets_mj.resize(0);
    tree.v_cfjets_pt.resize(0);
    tree.v_cfjets_eta.resize(0);
    tree.v_cfjets_phi.resize(0);
    for(size_t ijet = 0; ijet<tree.v_fjets_pt.size(); ++ijet){
      TLorentzVector p4jet;
      p4jet.SetPtEtaPhiM(tree.v_fjets_pt.at(ijet), tree.v_fjets_eta.at(ijet),
			 tree.v_fjets_phi.at(ijet), tree.v_fjets_mj.at(ijet));

      //Keep the original 4-vector to check DeltaR
      //(otherwise which leptons are cleaned depends on the order they're checked)
      const TLorentzVector p4jet_original(p4jet);

      for(size_t i = 0; i<veto_electrons.size(); ++i){
	const size_t iel = veto_electrons.at(i);
	const size_t ijetel(els_jet_ind()->at(iel));
	if(ijetel>=jets_pt()->size()) continue;
	const TLorentzVector p4el(els_px()->at(iel), els_py()->at(iel),
				  els_pz()->at(iel), els_energy()->at(iel));
	const TLorentzVector p4jetel(jets_px()->at(ijetel), jets_py()->at(ijetel),
				     jets_pz()->at(ijetel), jets_energy()->at(ijetel));
			     
	if(p4jetel.DeltaR(p4jet_original)<1.0
	   && p4jetel.Pt()>30.0
	   && p4jetel.DeltaR(p4el)<0.3){
	  p4jet-=p4jetel;
	}
      }
      for(size_t i = 0; i<veto_muons; ++i){
	const size_t imu = veto_muons.at(i);
	if(!IsVetoMuon(imu)) continue;
	const size_t ijetmu(mus_jet_ind()->at(imu));
	if(ijetmu>=jets_pt()->size()) continue;
	const TLorentzVector p4mu(mus_px()->at(imu), mus_py()->at(imu),
				  mus_pz()->at(imu), mus_energy()->at(imu));
	const TLorentzVector p4jetmu(jets_px()->at(ijetmu), jets_py()->at(ijetmu),
				     jets_pz()->at(ijetmu), jets_energy()->at(ijetmu));

	if(p4jetmu.DeltaR(p4jet_original)<1.0
	   && p4jetmu.Pt()>30.0
	   && p4jetmu.DeltaR(p4mu)<0.3){
	  p4jet-=p4jetmu;
	}
      }

      tree.v_cfjets_mj.push_back(p4jet.M());
      tree.v_cfjets_pt.push_back(p4jet.Pt());
      tree.v_cfjets_eta.push_back(p4jet.Eta());
      tree.v_cfjets_phi.push_back(p4jet.Phi());
      if(p4jet.Pt()>50.0){
	tree.cmj+=p4jet.M();
	++tree.ncfjets;
      }
    }

    ////////////////   Leptons   ////////////////
    lepmax_energy=0; lepmax_pt=0; lepmax_px=0; lepmax_py=0; lepmax_pz=0;
    tree.v_els_pt.resize(0);
    tree.v_els_gen_pt.resize(0);
    tree.v_els_eta.resize(0);
    tree.v_els_phi.resize(0);
    tree.v_els_charge.resize(0);
    tree.v_els_reliso.resize(0);
    tree.v_els_sigid.resize(0);
    tree.v_els_tru_id.resize(0);
    tree.v_els_tru_momid.resize(0);
    tree.v_els_tru_tm.resize(0);
    tree.v_els_tru_dr.resize(0);
    for(uint index=0; index<els_pt()->size(); ++index){
      if(!IsVetoIdElectron(index) || els_pt()->at(index)<10.0) continue;

      pt = els_pt()->at(index);
      px = els_px()->at(index);
      py = els_py()->at(index);
      mcID = GetTrueElectron(static_cast<int>(index), mcmomID, fromW, deltaR);
      tree.v_els_pt.push_back(pt);
      tree.v_els_gen_pt.push_back(els_gen_pt()->at(index));
      tree.v_els_eta.push_back(els_eta()->at(index));
      tree.v_els_phi.push_back(els_phi()->at(index));
      tree.v_els_charge.push_back(els_charge()->at(index));
      tree.v_els_reliso.push_back(GetElectronIsolation(index));
      tree.v_els_sigid.push_back(IsSignalIdElectron(index));
      tree.v_els_tru_id.push_back(mcID);
      tree.v_els_tru_momid.push_back(mcmomID);
      tree.v_els_tru_tm.push_back(abs(mcID)==11 && fromW);
      tree.v_els_tru_dr.push_back(deltaR);

      if(els_pt()->at(index) > lepmax_pt){
        lepmax_energy=els_energy()->at(index);
        lepmax_pt=els_pt()->at(index); 
        lepmax_px=els_px()->at(index); 
        lepmax_py=els_py()->at(index);
        lepmax_pz=els_pz()->at(index);
        lepmax_p4 = TLorentzVector(els_px()->at(index),
                                   els_py()->at(index),
                                   els_pz()->at(index),
                                   els_energy()->at(index));
      }
      // Transverse sphericity matrix (not including 1/sum(pt), which cancels in the ratio of eig)
      spher_nolin[0][0] += px*px; spher_nolin[0][1] += px*py; 
      spher_nolin[1][0] += px*py; spher_nolin[1][1] += py*py; 
      // Linearized transverse sphericity matrix
      spher[0][0] += px*px/pt; spher[0][1] += px*py/pt; 
      spher[1][0] += px*py/pt; spher[1][1] += py*py/pt; 
      //       cout<<"Rec el eta "<<tree.v_els_eta[tree.v_els_pt.size()-1]<<", phi "<<tree.v_els_phi[tree.v_els_pt.size()-1]
      //          <<", tru id "<<tree.v_els_tru_id[tree.v_els_pt.size()-1]<<", tru momid "<<tree.v_els_tru_momid[tree.v_els_pt.size()-1]
      //          <<", dR "<<deltaR<<endl;
    }
    tree.v_mus_pt.resize(0);
    tree.v_mus_gen_pt.resize(0);
    tree.v_mus_eta.resize(0);
    tree.v_mus_phi.resize(0);
    tree.v_mus_charge.resize(0);
    tree.v_mus_reliso.resize(0);
    tree.v_mus_sigid.resize(0);
    tree.v_mus_tru_id.resize(0);
    tree.v_mus_tru_momid.resize(0);
    tree.v_mus_tru_tm.resize(0);
    tree.v_mus_tru_dr.resize(0);
    for(uint index=0; index<mus_pt()->size(); ++index){
      if(!IsVetoIdMuon(index) || mus_pt()->at(index)<10.0) continue;

      mcID = GetTrueMuon(static_cast<int>(index), mcmomID, fromW, deltaR);
      tree.v_mus_pt.push_back(mus_pt()->at(index));
      tree.v_mus_pt.push_back(mus_gen_pt()->at(index));
      tree.v_mus_eta.push_back(mus_eta()->at(index));
      tree.v_mus_phi.push_back(mus_phi()->at(index));
      tree.v_mus_charge.push_back(mus_charge()->at(index));
      tree.v_mus_reliso.push_back(GetMuonIsolation(index));
      tree.v_mus_sigid.push_back(IsSignalIdMuon(index));
      tree.v_mus_tru_id.push_back(mcID);
      tree.v_mus_tru_momid.push_back(mcmomID);
      tree.v_mus_tru_tm.push_back(abs(mcID)==13 && fromW);
      tree.v_mus_tru_dr.push_back(deltaR);

      if(mus_pt()->at(index) > lepmax_pt){
        lepmax_energy=mus_energy()->at(index);
        lepmax_pt=mus_pt()->at(index); 
        lepmax_px=mus_px()->at(index); 
        lepmax_py=mus_py()->at(index);
        lepmax_pz=mus_pz()->at(index);
        lepmax_p4 = TLorentzVector(mus_px()->at(index),
                                   mus_py()->at(index),
                                   mus_pz()->at(index),
                                   mus_energy()->at(index));
      }
      // Transverse sphericity matrix (not including 1/sum(pt), which cancels in the ratio of eig)
      spher_nolin[0][0] += px*px; spher_nolin[0][1] += px*py; 
      spher_nolin[1][0] += px*py; spher_nolin[1][1] += py*py; 
      // Linearized transverse sphericity matrix
      spher[0][0] += px*px/pt; spher[0][1] += px*py/pt; 
      spher[1][0] += px*py/pt; spher[1][1] += py*py/pt; 
    }
    if(eigen2x2(spher, eig1, eig2)) tree.spher = 2*eig2/(eig1+eig2);
    else tree.spher = bad_val;
    if(eigen2x2(spher_nolin, eig1, eig2)) tree.spher_nolin = 2*eig2/(eig1+eig2);
    else tree.spher_nolin = bad_val;

    ////////////////   METS   ////////////////
    tree.met = mets_et()->at(0);
    tree.met_phi = mets_phi()->at(0);
    tree.met_unc_pt = mets_unCPt()->at(0);
    tree.met_unc_phi = mets_unCPhi()->at(0);

    ////////////////   TRUTH   ////////////////
    // True MET and HT
    float metx(0), mety(0);
    for(size_t imc = 0; imc < mc_final_id()->size(); imc++){
      int id = static_cast<int>(abs(mc_final_id()->at(imc)));
      if(id==12 || id==14 || id==16 || id==39 || (id>1e6 && mc_final_charge()->at(imc)==0)) {
        metx += mc_final_px()->at(imc);
        mety += mc_final_py()->at(imc);
      }
    }
    tree.genmet = sqrt(pow(metx,2)+pow(mety,2));
    tree.genht = 0;
    for(size_t imc = 0; imc < mc_jets_pt()->size(); imc++)
      if(mc_jets_pt()->at(imc)>40 && mc_jets_eta()->at(imc)<3) tree.genht += mc_jets_pt()->at(imc);

    // True particles
    tree.mc_pt->resize(0);  tree.mc_id->resize(0);  
    tree.mc_eta->resize(0); tree.mc_momid->resize(0);  
    tree.mc_phi->resize(0); 
    for(size_t imc = 0; imc < mc_doc_id()->size(); imc++){
      int id = static_cast<int>(mc_doc_id()->at(imc));
      int momid = GetMom(mc_doc_id()->at(imc), mc_doc_mother_id()->at(imc),
			 mc_doc_grandmother_id()->at(imc), mc_doc_ggrandmother_id()->at(imc),
			 fromW);
      pt = mc_doc_pt()->at(imc);
      if((abs(momid) == 24 || (abs(momid) == 15 && abs(id) != 15))
	 && abs(id) != 12 && abs(id) != 14 && abs(id) != 16
         && abs(id) != 22  && abs(id) != 24){
        tree.mc_pt->push_back(pt);
        tree.mc_eta->push_back(mc_doc_eta()->at(imc));
        tree.mc_phi->push_back(mc_doc_phi()->at(imc));
        tree.mc_id->push_back(id);
        tree.mc_momid->push_back(momid);
      }
    }
   
    // Finding mT and deltaPhi with respect to highest pT lepton
    tree.mt = bad_val; tree.dphi_wlep = bad_val;
    if(lepmax_pt > 0){
      double lepmax_phi = atan2(lepmax_py, lepmax_px);
      double Wx = mets_ex()->at(0) + lepmax_px;
      double Wy = mets_ey()->at(0) + lepmax_py;
      tree.dphi_wlep = abs(atan2(Wy,Wx)-lepmax_phi);
      if(tree.dphi_wlep > PI) tree.dphi_wlep = 2*PI-tree.dphi_wlep;
      tree.mt = sqrt(2*lepmax_pt* tree.met*(1-cos(tree.met_phi-lepmax_phi)));
    }

    // mT2 with respect to highest pT lepton
    tree.mt2w_max = bad_val;
    tree.mt2w_min = bad_val;
    tree.mt2w_ref_max = bad_val;
    tree.mt2w_ref_min = bad_val;
    tree.mt2w_high_pt = bad_val;
    tree.mt2w_high_csv = bad_val;
    tree.mt2_max = bad_val;
    tree.mt2_min = bad_val;
    tree.mt2_ref_max = bad_val;
    tree.mt2_ref_min = bad_val;
    tree.mt2_high_pt = bad_val;
    tree.mt2_high_csv = bad_val;
    tree.mbl_max = bad_val;
    tree.mbl_subleading = bad_val;
    tree.mbl_min = bad_val;
    tree.mbl_high_pt = bad_val;
    tree.mbl_high_csv = bad_val;
    tree.mblnu_max = bad_val;
    tree.mblnu_subleading = bad_val;
    tree.mblnu_min = bad_val;
    tree.mblnu_high_pt = bad_val;
    tree.mblnu_high_csv = bad_val;
    double momentum_W[3] = {W_mass, mets_ex()->at(0)+lepmax_px, mets_ey()->at(0)+lepmax_py};
    double momentum_met[3] = {W_mass, mets_ex()->at(0), mets_ey()->at(0)};
    double momentum_lep_4[4] = {lepmax_energy, lepmax_px, lepmax_py, lepmax_pz};

    TLorentzVector met_p4(mets_ex()->at(0), mets_ey()->at(0), 0.0, mets_et()->at(0));
    if(lepmax_pt > 0.0){
      vector<pair<float, unsigned> > jet_sorter(0);
      unsigned num_tags = 0;
      vector<float> v_mt2(0), v_mt2w(0), v_mbl(0), v_mblnu(0);
      float pt1=bad_val, pt2=bad_val, csv1=bad_val, csv2=bad_val;
      int pti1=-1, pti2=-1, csvi1=-1, csvi2=-1;
      for(size_t jet1 = 0; jet1 < jets_pt()->size(); ++jet1) {
        if(!IsBasicJet(jet1)) continue;

        jet_sorter.push_back(std::make_pair(-jets_pt()->at(jet1), jet1));
        const float this_pt = jets_pt()->at(jet1);
        const float this_csv = jets_btag_secVertexCombined()->at(jet1);

        if(this_pt>pt1){
          pt2=pt1;
          pt1=this_pt;
          pti2=pti1;
          pti1=jet1;
        }else if(this_pt>pt2){
          pt2=this_pt;
          pti2=jet1;
        }
        if(this_csv>csv1){
          csv2=csv1;
          csv1=this_csv;
          csvi2=csvi1;
          csvi1=jet1;
        }else if(this_csv>csv2){
          csv2=this_csv;
          csvi2=jet1;
        }

        if(jets_btag_secVertexCombined()->at(jet1) > CSVCuts[1]){
          ++num_tags;
        }

        double momentum_1[3] = {0.0, jets_px()->at(jet1), jets_py()->at(jet1)};
        double momentum_1_4[4] = {jets_energy()->at(jet1),
                                  jets_px()->at(jet1),
                                  jets_py()->at(jet1),
                                  jets_pz()->at(jet1)};

        if(jets_btag_secVertexCombined()->at(jet1) > CSVCuts[1]){
          TLorentzVector jet_p4 = TLorentzVector(jets_px()->at(jet1),
                                                 jets_py()->at(jet1),
                                                 jets_pz()->at(jet1),
                                                 jets_energy()->at(jet1));
          v_mbl.push_back((lepmax_p4 + jet_p4).M());
          v_mblnu.push_back((lepmax_p4 + jet_p4 + met_p4).M());
        }

        for(size_t jet2 = jet1+1; jet2 < jets_pt()->size(); ++jet2){
          if(!IsBasicJet(jet2)) continue;
          double momentum_2[3] = {0.0, jets_px()->at(jet2), jets_py()->at(jet2)};
          double momentum_2_4[4] = {jets_energy()->at(jet2),
                                    jets_px()->at(jet2),
                                    jets_py()->at(jet2),
                                    jets_pz()->at(jet2)};

          if(jets_btag_secVertexCombined()->at(jet1) > CSVCuts[1]
             && jets_btag_secVertexCombined()->at(jet1) > CSVCuts[1]){
            mt2_calc.set_momenta(momentum_1, momentum_2, momentum_W);
            mt2w_calc.set_momenta(momentum_lep_4, momentum_1_4, momentum_2_4, momentum_met);
            v_mt2.push_back(mt2_calc.get_mt2());
            v_mt2w.push_back(mt2w_calc.get_mt2w());
          }
        }
      }
      std::sort(v_mt2.begin(), v_mt2.end(), std::greater<float>());
      std::sort(v_mt2w.begin(), v_mt2w.end(), std::greater<float>());
      std::sort(v_mbl.begin(), v_mbl.end(), std::greater<float>());
      std::sort(v_mblnu.begin(), v_mblnu.end(), std::greater<float>());
      std::sort(jet_sorter.begin(), jet_sorter.begin(), std::greater<std::pair<float, unsigned> >());
      
      if(num_tags==2){
        double momentum_csvi1_3[3] = {0.0, jets_px()->at(csvi1), jets_py()->at(csvi1)};
        double momentum_csvi1_4[4] = {jets_energy()->at(csvi1),
                                      jets_px()->at(csvi1),
                                      jets_py()->at(csvi1),
                                      jets_pz()->at(csvi1)};
        double momentum_csvi2_3[3] = {0.0, jets_px()->at(csvi2), jets_py()->at(csvi2)};
        double momentum_csvi2_4[4] = {jets_energy()->at(csvi2),
                                      jets_px()->at(csvi2),
                                      jets_py()->at(csvi2),
                                      jets_pz()->at(csvi2)};
        mt2_calc.set_momenta(momentum_csvi1_3, momentum_csvi2_3, momentum_W);
        mt2w_calc.set_momenta(momentum_lep_4, momentum_csvi1_4, momentum_csvi2_4, momentum_met);
        tree.mt2_ref_min = mt2_calc.get_mt2();
        tree.mt2_ref_max = mt2_calc.get_mt2();
        tree.mt2w_ref_min = mt2w_calc.get_mt2w();
        tree.mt2w_ref_max = mt2w_calc.get_mt2w();
      }else if(num_tags==1){
        double momentum_csv_3[3] = {0.0, jets_px()->at(csvi1), jets_py()->at(csvi1)};
        double momentum_csv_4[4] = {jets_energy()->at(csvi1),
                                    jets_px()->at(csvi1),
                                    jets_py()->at(csvi1),
                                    jets_pz()->at(csvi1)};

        std::vector<double> v_mt2_temp(0), v_mt2w_temp(0);
        bool found_tag = false;
        for(size_t i = 0; i < jet_sorter.size() && (i < 2 || (found_tag && i < 3)); ++i){
          const size_t jet = jet_sorter.at(i).second;
          if(num_tags == 1 && jets_btag_secVertexCombined()->at(jet) > CSVCuts[1]){
            found_tag = true;
            continue;
          }
          double momentum_3[3] = {0.0, jets_px()->at(jet), jets_py()->at(jet)};
          double momentum_4[4] = {jets_energy()->at(jet),
                                  jets_px()->at(jet),
                                  jets_py()->at(jet),
                                  jets_pz()->at(jet)};
          mt2_calc.set_momenta(momentum_csv_3, momentum_3, momentum_W);
          mt2w_calc.set_momenta(momentum_lep_4, momentum_csv_4, momentum_4, momentum_met);
          v_mt2_temp.push_back(mt2_calc.get_mt2());
          v_mt2w_temp.push_back(mt2w_calc.get_mt2w());
        }
        std::sort(v_mt2_temp.begin(), v_mt2_temp.end(), std::greater<float>());
        std::sort(v_mt2w_temp.begin(), v_mt2w_temp.end(), std::greater<float>());
        if(v_mt2_temp.size() > 0){
          tree.mt2_ref_max = v_mt2_temp.at(0);
          tree.mt2_ref_min = v_mt2_temp.at(v_mt2_temp.size()-1);
        }
        if(v_mt2w_temp.size() > 0){
          tree.mt2w_ref_max = v_mt2w_temp.at(0);
          tree.mt2w_ref_min = v_mt2w_temp.at(v_mt2w_temp.size()-1);
        }
      }else{
        std::vector<double> v_mt2_temp(0), v_mt2w_temp(0);
        for(size_t i = 0; i < 3 && i < jet_sorter.size(); ++i){
          const size_t jeta = jet_sorter.at(i).second;
          double momentum_1_3[3] = {0.0, jets_px()->at(jeta), jets_py()->at(jeta)};
          double momentum_1_4[4] = {jets_energy()->at(jeta),
                                    jets_px()->at(jeta),
                                    jets_py()->at(jeta),
                                    jets_pz()->at(jeta)};
          for(size_t j = i + 1; j < 3 && j < jet_sorter.size(); ++j){
            const size_t jetb = jet_sorter.at(j).second;
            double momentum_2_3[3] = {0.0, jets_px()->at(jetb), jets_py()->at(jetb)};
            double momentum_2_4[4] = {jets_energy()->at(jetb),
                                      jets_px()->at(jetb),
                                      jets_py()->at(jetb),
                                      jets_pz()->at(jetb)};

            mt2_calc.set_momenta(momentum_1_3, momentum_2_3, momentum_W);
            mt2w_calc.set_momenta(momentum_lep_4, momentum_1_4, momentum_2_4, momentum_met);
            v_mt2_temp.push_back(mt2_calc.get_mt2());
            v_mt2w_temp.push_back(mt2w_calc.get_mt2w());
          }
        }
        std::sort(v_mt2_temp.begin(), v_mt2_temp.end(), std::greater<float>());
        std::sort(v_mt2w_temp.begin(), v_mt2w_temp.end(), std::greater<float>());
        if(v_mt2_temp.size() > 0){
          tree.mt2_ref_max = v_mt2_temp.at(0);
          tree.mt2_ref_min = v_mt2_temp.at(v_mt2_temp.size()-1);
        }
        if(v_mt2w_temp.size() > 0){
          tree.mt2w_ref_max = v_mt2w_temp.at(0);
          tree.mt2w_ref_min = v_mt2w_temp.at(v_mt2w_temp.size()-1);
        }
      }

      if(v_mt2.size()>0){
        tree.mt2_max = v_mt2.at(0);
        tree.mt2_min = v_mt2.at(v_mt2.size()-1);
      }
      if(v_mt2w.size()>0){
        tree.mt2w_max = v_mt2w.at(0);
        tree.mt2w_min = v_mt2w.at(v_mt2w.size()-1);
      }
      if(v_mbl.size()>0){
        tree.mbl_max = v_mbl.at(0);
        tree.mbl_min = v_mbl.at(v_mbl.size()-1);
        if(v_mbl.size()>1){
          tree.mbl_subleading = v_mbl.at(1);
        }
      }
      if(v_mblnu.size()>0){
        tree.mblnu_max = v_mblnu.at(0);
        tree.mblnu_min = v_mblnu.at(v_mblnu.size()-1);
        if(v_mblnu.size()>1){
          tree.mblnu_subleading = v_mblnu.at(1);
        }
      }

      if(pti1>=0){
        TLorentzVector jet_p4 = TLorentzVector(jets_px()->at(pti1),
                                               jets_py()->at(pti1),
                                               jets_pz()->at(pti1),
                                               jets_energy()->at(pti1));
        tree.mbl_high_pt = (lepmax_p4+jet_p4).M();
        tree.mblnu_high_pt = (lepmax_p4+jet_p4+met_p4).M();
        if(pti2>=0){
          double momentum_1[3] = {0.0, jets_px()->at(pti1), jets_py()->at(pti1)};
          double momentum_1_4[4] = {jets_energy()->at(pti1),
                                    jets_px()->at(pti1),
                                    jets_py()->at(pti1),
                                    jets_pz()->at(pti1)};
          double momentum_2[3] = {0.0, jets_px()->at(pti2), jets_py()->at(pti2)};
          double momentum_2_4[4] = {jets_energy()->at(pti2),
                                    jets_px()->at(pti2),
                                    jets_py()->at(pti2),
                                    jets_pz()->at(pti2)};
          mt2_calc.set_momenta(momentum_1, momentum_2, momentum_W);
          mt2w_calc.set_momenta(momentum_lep_4, momentum_1_4, momentum_2_4, momentum_met);
          tree.mt2_high_pt = mt2_calc.get_mt2();
          tree.mt2w_high_pt = mt2w_calc.get_mt2w();
        }
      }
      
      if(csvi1>=0){
        TLorentzVector jet_p4 = TLorentzVector(jets_px()->at(csvi1),
                                               jets_py()->at(csvi1),
                                               jets_pz()->at(csvi1),
                                               jets_energy()->at(csvi1));
        tree.mbl_high_csv = (lepmax_p4+jet_p4).M();
        tree.mblnu_high_csv = (lepmax_p4+jet_p4+met_p4).M();
        if(csvi2>=0){
          double momentum_1[3] = {0.0, jets_px()->at(csvi1), jets_py()->at(csvi1)};
          double momentum_1_4[4] = {jets_energy()->at(csvi1),
                                    jets_px()->at(csvi1),
                                    jets_py()->at(csvi1),
                                    jets_pz()->at(csvi1)};
          double momentum_2[3] = {0.0, jets_px()->at(csvi2), jets_py()->at(csvi2)};
          double momentum_2_4[4] = {jets_energy()->at(csvi2),
                                    jets_px()->at(csvi2),
                                    jets_py()->at(csvi2),
                                    jets_pz()->at(csvi2)};
          mt2_calc.set_momenta(momentum_1, momentum_2, momentum_W);
          mt2w_calc.set_momenta(momentum_lep_4, momentum_1_4, momentum_2_4, momentum_met);
          tree.mt2_high_csv = mt2_calc.get_mt2();
          tree.mt2w_high_csv = mt2w_calc.get_mt2w();
        }
      }
    }

    ////////////////   Pile-up   ////////////////
    for(size_t bc(0); bc<PU_bunchCrossing()->size(); ++bc){
      if(PU_bunchCrossing()->at(bc)==0){
        tree.ntrupv = PU_NumInteractions()->at(bc);
        tree.ntrupv_mean = PU_TrueNumInteractions()->at(bc);
        break;
      }
    }
    tree.npv = Npv();
    ////////////////   Weights   ////////////////
    tree.wl1 = (0.5*TMath::Erf((1.35121e-02)*(tree.genht-(3.02695e+02)))+0.5);
    tree.wlumi = xsec*luminosity / static_cast<double>(Ntotentries);
    tree.weight = tree.wlumi;
    
    tree.mc_type = TypeCode();

    tree.Fill();
  }
  cout<<"xsec is "<<xsec<<" and wlumi "<<tree.wlumi<<" for a total of "<<Ntotentries<<" entries"<<endl;
  tree.Write();

  // Global tree
  GetEntry(0);
  TString model = model_params()->c_str(), commit;
  int sys_stat = system("git rev-parse HEAD > hash.txt");
  ifstream hashfile("hash.txt");
  hashfile >> commit;
  sys_stat = system("rm hash.txt");
  if(sys_stat!=0){/*something went wrong...*/}

  TTree treeglobal("treeglobal", "treeglobal");
  treeglobal.Branch("noriginal", &Nentries);
  treeglobal.Branch("commit", &commit);
  treeglobal.Branch("model", &model);

  treeglobal.Fill();
  treeglobal.Write();

  outFile.Close();
  cout<<"Reduced tree in "<<outFilename<<endl;
}

unsigned event_handler::TypeCode() const{
  const std::string sample_name = SampleName();
  unsigned sample_code = 0xF;
  if(Contains(sample_name, "SMS")){
    sample_code = 0x0;
  }else if(Contains(sample_name, "TTJets")
           || Contains(sample_name, "TT_CT10")){
    sample_code = 0x1;
  }else if(Contains(sample_name, "WJets")){
    sample_code = 0x2;
  }else if(Contains(sample_name, "T_s-channel")
           || Contains(sample_name, "T_tW-channel")
           || Contains(sample_name, "T_t-channel")
           || Contains(sample_name, "Tbar_s-channel")
           || Contains(sample_name, "Tbar_tW-channel")
           || Contains(sample_name, "Tbar_t-channel")){
    sample_code = 0x3;
  }else if(Contains(sample_name, "QCD")){
    sample_code = 0x4;
  }else if(Contains(sample_name, "DY")){
    sample_code = 0x5;
  }else{
    sample_code = 0xF;
  }

  unsigned num_leps = 0, num_tau_to_lep = 0, num_taus = 0, num_conversions = 0;
  bool counting = false;

  for(size_t i = 0; i < mc_doc_id()->size(); ++i){
    const int id = static_cast<int>(floor(fabs(mc_doc_id()->at(i))+0.5));
    const int mom = static_cast<int>(floor(fabs(mc_doc_mother_id()->at(i))+0.5));
    const int gmom = static_cast<int>(floor(fabs(mc_doc_grandmother_id()->at(i))+0.5));
    const int ggmom = static_cast<int>(floor(fabs(mc_doc_ggrandmother_id()->at(i))+0.5));
    
    if(mom != 15) counting=false;

    if((id == 11 || id == 13) && (mom == 24 || (mom == 15 && (gmom == 24 || (gmom == 15 && ggmom == 24))))){
      ++num_leps;
      if(mom == 15){
        ++num_tau_to_lep;
        if(counting){
          ++num_conversions;
          counting = false;
        }else{
          counting = true;
        }
      }
    }else if(id == 15 && mom == 24){
      ++num_taus;
    }
  }

  num_leps -= 2*num_conversions;
  num_tau_to_lep -= 2*num_conversions;

  if(sample_code > 0xF) sample_code = 0xF;
  if(num_leps > 0xF) num_leps = 0xF;
  if(num_tau_to_lep > 0xF) num_tau_to_lep = 0xF;
  if(num_taus > 0xF) num_taus = 0xF;

  return (sample_code << 12) | (num_leps << 8) | (num_tau_to_lep << 4) | num_taus;
}
