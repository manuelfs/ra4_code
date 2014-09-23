// event_handler: Defines reduced tree with RA4 variables

#include "pdtlund.hpp"
#include "small_tree.hpp"
#include "utilities.hpp"
#include "event_handler.hpp"
#include "timer.hpp"
#include <cfloat>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include "TFile.h"
#include "TTree.h"

using namespace std;
const double CSVCuts[] = {0.244, 0.679, 0.898};

void event_handler::ReduceTree(int Nentries, TString outFilename){
  
  // for(int entry(0); entry < Nentries; entry++){
  //   GetEntry(entry);

  //   cout<<"========== Event "<<entry+1<<" ============"<<endl;
  //   for(unsigned int imc = 0; imc < mc_doc_id->size(); imc++){
  //     if(abs(mc_doc_id->at(imc))==15){// && mc_doc_status->at(imc)==23){
  //     cout<<imc<<": ID "<<mc_doc_id->at(imc)<<",   \tMom ID "<<mc_doc_mother_id->at(imc)
  // 	  <<", \tGMom ID "<<mc_doc_grandmother_id->at(imc)
  // 	  <<", \tGGMom ID "<<mc_doc_ggrandmother_id->at(imc)
  // 	  <<", \tN daughters "<<mc_doc_numOfDaughters->at(imc)
  // 	  <<",   \tN moms "<<mc_doc_numOfMothers->at(imc)
  // 	  <<",   \tstatus "<<mc_doc_status->at(imc)
  // 	  <<",   \tpT "<<mc_doc_pt->at(imc)
  // 	  <<",   \teta "<<mc_doc_eta->at(imc)
  // 	  <<",   \tphi "<<mc_doc_phi->at(imc)<<endl;
  //     }
  //   }
  //   cout<<endl<<endl;
  // }

  TFile outFile(outFilename, "recreate");
  outFile.cd();

  // Reduced tree
  small_tree tree;
  float xsec(cross_section(outFilename));
  const float luminosity = 19600;

  // Pt thresholds for jets
  vector<double> v_pt_threshold;
  vector<double> *pt_thresh(&v_pt_threshold);
  pt_thresh->push_back(20); pt_thresh->push_back(40); 
  pt_thresh->push_back(60); pt_thresh->push_back(80); 
  int nthresh = pt_thresh->size();
  tree.v_njets.resize(nthresh);
  tree.v_nbl.resize(nthresh);tree.v_nbm.resize(nthresh);tree.v_nbt.resize(nthresh);

  double deltaR, lepmax_pt, lepmax_px, lepmax_py;
  int mcID, mcmomID, lepID;
  float spher[2][2], spher_jets[2][2], spher_nolin[2][2];
  float pt(-99.), px(-99.), py(-99.), eig1(-99.), eig2(-99.);

  vector<int_double> csv_sorted;
  Timer timer(Nentries);
  timer.Start();
  for(int entry(0); entry < Nentries; entry++){
    if(entry%5000==0 && entry!=0){
      timer.PrintRemainingTime();
    }
    timer.Iterate();
    GetEntry(entry);

    ////////////////   Leptons   ////////////////
    vector<int> signal_electrons = GetElectrons();
    vector<int> veto_electrons = GetElectrons(false);
    vector<int> signal_muons = GetMuons();
    vector<int> veto_muons = GetMuons(false);
    vector<int> good_jets = GetJets(signal_electrons, signal_muons, veto_electrons, veto_muons, tree.ht);
    tree.nels  = signal_electrons.size();
    tree.nvels = veto_electrons.size();
    tree.nmus  = signal_muons.size();
    tree.nvmus = veto_muons.size();
    if(tree.nels+tree.nmus == tree.nvels+tree.nvmus) tree.nleps = tree.nels+tree.nmus;
    else tree.nleps = -99;

    ////////////////   Jets   ////////////////
    tree.v_jets_pt.resize(0);
    tree.v_jets_eta.resize(0);
    tree.v_jets_phi.resize(0);
    tree.v_jets_csv.resize(0);
    csv_sorted.resize(0);
    spher[0][0] = 0; spher[0][1] = 0; spher[1][0] = 0; spher[1][1] = 0; 
    spher_nolin[0][0] = 0; spher_nolin[0][1] = 0; spher_nolin[1][0] = 0; spher_nolin[1][1] = 0; 
    spher_jets[0][0] = 0; spher_jets[0][1] = 0; spher_jets[1][0] = 0; spher_jets[1][1] = 0; 
    for(int ith(0); ith < nthresh; ith++) {
      tree.v_njets[ith] = 0;
      tree.v_nbl[ith] = 0;
      tree.v_nbm[ith] = 0;
      tree.v_nbt[ith] = 0;
    }
    for(uint ijet = 0; ijet<jets_AK4_pt->size(); ijet++) {
      if(!IsGoodJet(ijet, 20, 2.4)) continue;
      pt = jets_AK4_pt->at(ijet);
      px = jets_AK4_px->at(ijet);
      py = jets_AK4_py->at(ijet);
      tree.v_jets_pt.push_back(pt);
      tree.v_jets_eta.push_back(jets_AK4_eta->at(ijet));
      tree.v_jets_phi.push_back(jets_AK4_phi->at(ijet));
      double csv = jets_AK4_btag_secVertexCombined->at(ijet);
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

//       cout<<ijet<<": csv "<<csv<<", eta "<<jets_AK4_eta->at(ijet)<<", phi "<<jets_AK4_phi->at(ijet)<<endl;
      for(int ith(0); ith < nthresh; ith++) {
	if(jets_AK4_pt->at(ijet) >= pt_thresh->at(ith)) {
	  tree.v_njets[ith]++;
	  if(csv >= CSVCuts[0]) tree.v_nbl[ith]++;
	  if(csv >= CSVCuts[1]) tree.v_nbm[ith]++;
	  if(csv >= CSVCuts[2]) tree.v_nbt[ith]++;
	}

      } // Loop over pT thresholds
    } // Loop over all jets

    if(eigen2x2(spher_jets, eig1, eig2)) tree.spher_jets = 2*eig2/(eig1+eig2);
    else tree.spher_jets = -999.;
    
    if(tree.v_jets_csv.size() >= 2){
      sort(csv_sorted.begin(), csv_sorted.end(), id_big2small);
      tree.dr_bb = dR(tree.v_jets_eta[csv_sorted[0].first], tree.v_jets_eta[csv_sorted[1].first], 
		      tree.v_jets_phi[csv_sorted[0].first], tree.v_jets_phi[csv_sorted[1].first]);
    } else tree.dr_bb = -999.;
    
    
    ////////////////   Leptons   ////////////////
    lepmax_pt=0; lepmax_px=0; lepmax_py=0;
    tree.v_els_pt.resize(0);
    tree.v_els_eta.resize(0);
    tree.v_els_phi.resize(0);
    tree.v_els_reliso.resize(0);
    tree.v_els_tru_id.resize(0);
    tree.v_els_tru_momid.resize(0);
    tree.v_els_tru_dr.resize(0);
    for(uint index=0; index<els_pt->size(); index++){
      if(!IsBasicElectron(index)) continue;

      pt = els_pt->at(index);
      px = els_px->at(index);
      py = els_py->at(index);
      if(els_charge->at(index)>0) lepID = pdtlund::e_minus;
      else lepID = pdtlund::e_plus;
      mcID = GetTrueElectron(static_cast<int>(index), mcmomID, deltaR);
      tree.v_els_pt.push_back(pt);
      tree.v_els_eta.push_back(els_eta->at(index));
      tree.v_els_phi.push_back(els_phi->at(index));
      tree.v_els_reliso.push_back(GetElectronIsolation(index));
      tree.v_els_tru_id.push_back(mcID);
      tree.v_els_tru_momid.push_back(mcmomID);
      tree.v_els_tru_dr.push_back(deltaR);

      if(els_pt->at(index) > lepmax_pt){
	lepmax_pt=els_pt->at(index); 
	lepmax_px=els_px->at(index); 
	lepmax_py=els_py->at(index);
      }
      // Transverse sphericity matrix (not including 1/sum(pt), which cancels in the ratio of eig)
      spher_nolin[0][0] += px*px; spher_nolin[0][1] += px*py; 
      spher_nolin[1][0] += px*py; spher_nolin[1][1] += py*py; 
      // Linearized transverse sphericity matrix
      spher[0][0] += px*px/pt; spher[0][1] += px*py/pt; 
      spher[1][0] += px*py/pt; spher[1][1] += py*py/pt; 
//       cout<<"Rec el eta "<<tree.v_els_eta[tree.v_els_pt.size()-1]<<", phi "<<tree.v_els_phi[tree.v_els_pt.size()-1]
//   	  <<", tru id "<<tree.v_els_tru_id[tree.v_els_pt.size()-1]<<", tru momid "<<tree.v_els_tru_momid[tree.v_els_pt.size()-1]
// 	  <<", dR "<<deltaR<<endl;
    }
    tree.v_mus_pt.resize(0);
    tree.v_mus_eta.resize(0);
    tree.v_mus_phi.resize(0);
    tree.v_mus_reliso.resize(0);
    tree.v_mus_tru_id.resize(0);
    tree.v_mus_tru_momid.resize(0);
    tree.v_mus_tru_dr.resize(0);
    for(uint index=0; index<mus_pt->size(); index++){
      if(!IsBasicMuon(index)) continue;

      if(mus_charge->at(index)>0) lepID = pdtlund::mu_minus;
      else lepID = pdtlund::mu_plus;
      mcID = GetTrueMuon(static_cast<int>(index), mcmomID, deltaR);
      tree.v_mus_pt.push_back(mus_pt->at(index));
      tree.v_mus_eta.push_back(mus_eta->at(index));
      tree.v_mus_phi.push_back(mus_phi->at(index));
      tree.v_mus_reliso.push_back(GetMuonIsolation(index));
      tree.v_mus_tru_id.push_back(mcID);
      tree.v_mus_tru_momid.push_back(mcmomID);
      tree.v_mus_tru_dr.push_back(deltaR);

      if(mus_pt->at(index) > lepmax_pt){
	lepmax_pt=mus_pt->at(index); 
	lepmax_px=mus_px->at(index); 
	lepmax_py=mus_py->at(index);
      }
      // Transverse sphericity matrix (not including 1/sum(pt), which cancels in the ratio of eig)
      spher_nolin[0][0] += px*px; spher_nolin[0][1] += px*py; 
      spher_nolin[1][0] += px*py; spher_nolin[1][1] += py*py; 
      // Linearized transverse sphericity matrix
      spher[0][0] += px*px/pt; spher[0][1] += px*py/pt; 
      spher[1][0] += px*py/pt; spher[1][1] += py*py/pt; 
    }
    if(eigen2x2(spher, eig1, eig2)) tree.spher = 2*eig2/(eig1+eig2);
    else tree.spher = -999.;
    if(eigen2x2(spher_nolin, eig1, eig2)) tree.spher_nolin = 2*eig2/(eig1+eig2);
    else tree.spher_nolin = -999.;


    ////////////////   METS   ////////////////
    tree.met = mets_et->at(0);
    tree.met_phi = mets_phi->at(0);

    ////////////////   TRUTH   ////////////////
    // True MET and HT
    float metx(0), mety(0);
    for(unsigned int imc = 0; imc < mc_final_id->size(); imc++){
      int id = static_cast<int>(abs(mc_final_id->at(imc)));
      if(id==12 || id==14 || id==16 || id==39 || id>1e6&&mc_final_charge->at(imc)==0) {
	metx += mc_final_px->at(imc);
	mety += mc_final_py->at(imc);
      }
    }
    tree.genmet = sqrt(pow(metx,2)+pow(mety,2));
    tree.genht = 0;
    for(unsigned int imc = 0; imc < mc_jets_pt->size(); imc++)
      if(mc_jets_pt->at(imc)>40 && mc_jets_eta->at(imc)<3) tree.genht += mc_jets_pt->at(imc);

    // True particles
    tree.mc_pt->resize(0);  tree.mc_id->resize(0);  
    tree.mc_eta->resize(0); tree.mc_momid->resize(0);  
    tree.mc_phi->resize(0); 
    for(unsigned int imc = 0; imc < mc_doc_id->size(); imc++){
      int id = static_cast<int>(mc_doc_id->at(imc));
      int momid = static_cast<int>(mc_doc_mother_id->at(imc));
      pt = mc_doc_pt->at(imc);
      if(((abs(momid) == 24 && abs(id) != 12 && abs(id) != 14 && abs(id) != 16)
	 || (abs(momid) == 15 && abs(id) != 15))
	 && abs(id) != 22  && abs(id) != 24 ){
	tree.mc_pt->push_back(pt);
	tree.mc_eta->push_back(mc_doc_eta->at(imc));
	tree.mc_phi->push_back(mc_doc_phi->at(imc));
 	tree.mc_id->push_back(id);
 	tree.mc_momid->push_back(momid);
      }
    }
   

    // Finding mT and deltaPhi with respect to highest pT lepton
    tree.mt = -999.; tree.dphi_wlep = -999.;
    if(lepmax_pt > 0){
      double lepmax_phi = atan2(lepmax_py, lepmax_px);
      double Wx = mets_ex->at(0) + lepmax_px;
      double Wy = mets_ey->at(0) + lepmax_py;
      tree.dphi_wlep = abs(atan2(Wy,Wx)-lepmax_phi);
      if(tree.dphi_wlep > PI) tree.dphi_wlep = 2*PI-tree.dphi_wlep;
      tree.mt = sqrt(2*lepmax_pt* tree.met*(1-cos(tree.met_phi-lepmax_phi)));
    }


    ////////////////   Pile-up   ////////////////
    for(unsigned int bc(0); bc<PU_bunchCrossing->size(); ++bc){
      if(PU_bunchCrossing->at(bc)==0){
	tree.ntrupv = PU_NumInteractions->at(bc);
	tree.ntrupv_mean = PU_TrueNumInteractions->at(bc);
	break;
      }
    }
    tree.npv = Npv;
    ////////////////   Weights   ////////////////
    tree.weight = xsec*luminosity / static_cast<double>(Nentries);
    
    tree.Fill();
  }

  tree.Write();

  // Global tree
  GetEntry(0);
  TString model = model_params->c_str(), commit;
  system("git rev-parse HEAD > hash.txt");
  ifstream hashfile("hash.txt");
  hashfile >> commit;
  system("rm hash.txt");

  TTree treeglobal("treeglobal", "treeglobal");
  treeglobal.Branch("noriginal", &Nentries);
  treeglobal.Branch("commit", &commit);
  treeglobal.Branch("model", &model);
  treeglobal.Branch("nthresh", &nthresh);
  treeglobal.Branch("pt_thresh", &pt_thresh);

  treeglobal.Fill();
  treeglobal.Write();

  outFile.Close();
  cout<<"Reduced tree in "<<outFilename<<endl;
}


event_handler::event_handler(const std::string &fileName):
  ra4_objects(fileName){
}
