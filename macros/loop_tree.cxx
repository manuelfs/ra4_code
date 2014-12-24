#include "loop_tree.hpp"

#include <iostream>
#include <cmath>
#include <stdexcept>

#include "TH1D.h"
#include "TFile.h"
#include "TString.h"

#include "small_tree.hpp"

using namespace std;

bool msgdbg = true;

int main(int argc, char* argv[]){

  TString infile;
  int opt(0); long max_entries(-1);
  while((opt=getopt(argc, argv, "i:n:"))!=-1){
    switch(opt){ 
    case 'i': infile=optarg; break;
    case 'n': max_entries=atoi(optarg); break;
    default: break;
    }
  }

  vector<string> isos;
  isos.push_back("reliso");
  isos.push_back("reliso_r02");
  isos.push_back("miniso");
  isos.push_back("ptrel");

  small_tree tree(infile.Data());

  TString outfile;
  if (infile.Contains("TT_")) outfile = "hist_ttbar.root";
  else if (infile.Contains("T1tttt") && infile.Contains("PU20")) outfile = "hist_T1tttt_pu20.root";
  else if (infile.Contains("T1tttt") && infile.Contains("PU40")) outfile = "hist_T1tttt_pu40.root";
  else if (infile.Contains("T2tt") && infile.Contains("850")) outfile = "hist_T2tt_stop850.root";
  else if (infile.Contains("T2tt") && infile.Contains("650")) outfile = "hist_T2tt_stop650.root";
  else if (infile.Contains("QCD")) outfile = "hist_QCD.root";

  cout<<"Writing output to "<<outfile<<endl;
  TFile fout(outfile,"RECREATE");
                   
	const long nent = tree.GetEntries();
  cout<<"Number of events to run over: "<<nent<<endl;

  TH1D h_cflow[2][4];
  for (unsigned i=0; i<isos.size(); i++){
    h_cflow[0][i] = TH1D(("h_"+isos[i]+"_el").c_str(), (isos[i] + " e channel").c_str(), 6, 0.5, 6.5);
    h_cflow[1][i] = TH1D(("h_"+isos[i]+"_mu").c_str(), (isos[i] + " #mu channel").c_str(), 6, 0.5, 6.5);
  }

  if (max_entries==-1) max_entries = nent;
  for (long ientry=0; ientry<max_entries; ientry++){
    tree.GetEntry(ientry);

    // if ((tree.mc_type()&0xF00)/0x100!=1) continue;

    double weight = tree.weight()*5;

    if (ientry%(nent/10)==0) cout<<"Processed events: "<<ientry<<endl;

    bool pass_ht = tree.ht() > 750.;
    bool pass_met = tree.met() > 250.;
    bool pass_njets = tree.njets() > 5;
    bool pass_btag = tree.nbl() > 1;

    for (unsigned i=0; i<isos.size(); i++){
      unsigned nveto_mus(0), nveto_els(0);
      vector<int> sigels_index;
      vector<int> sigmus_index;

        
 
      //---------- ELECTRONS ----------------      
      for (unsigned iel=0; iel<tree.els_pt().size(); iel++){
        if (!tree.els_ispf()[iel]) continue;
        if (tree.els_pt()[iel]<15.) continue;

        if (isos[i]=="reliso" && tree.els_reliso()[iel]<GetIsolationCut(true, isos[i], true, tree.els_eta()[iel])) nveto_els++;
        else if (isos[i]=="reliso_r02" && tree.els_reliso_r02()[iel]<GetIsolationCut(true, isos[i], true, tree.els_eta()[iel])) nveto_els++;
        else if (isos[i]=="miniso" && tree.els_miniso_tr15()[iel]<GetIsolationCut(true, isos[i], true, tree.els_eta()[iel])) nveto_els++;
        else if (isos[i]=="ptrel"){
          bool passRelIso = tree.els_reliso_r02()[iel]<GetIsolationCut(true, isos[i], true, tree.els_eta()[iel]);
          bool passPtrel = tree.els_ptrel_0()[iel]>GetIsolationCut(true, isos[i], true, tree.els_eta()[iel]);
          if (passRelIso || passPtrel) nveto_els++;
        }

        if (!(tree.els_sigid()[iel])) continue;
        if (tree.els_pt()[iel]<20.) continue;
        if (isos[i]=="reliso" && tree.els_reliso()[iel]<GetIsolationCut(true, isos[i], false, tree.els_eta()[iel])) sigels_index.push_back(iel);
        else if (isos[i]=="reliso_r02" && tree.els_reliso_r02()[iel]<GetIsolationCut(true, isos[i], false, tree.els_eta()[iel])) sigels_index.push_back(iel);
        else if (isos[i]=="miniso" && tree.els_miniso_tr15()[iel]<GetIsolationCut(true, isos[i], false, tree.els_eta()[iel])) sigels_index.push_back(iel);
        else if (isos[i]=="ptrel"){
          bool passRelIso = tree.els_reliso_r02()[iel]<GetIsolationCut(true, isos[i], false, tree.els_eta()[iel]);
          bool passPtrel = tree.els_ptrel_0()[iel]>GetIsolationCut(true, isos[i], false, tree.els_eta()[iel]);
          if (passRelIso || passPtrel) sigels_index.push_back(iel);
        }
      }
      
      //---------- MUONS ----------------
      for (unsigned imu=0; imu<tree.mus_pt().size(); imu++){
        if (tree.mus_pt()[imu]<15.) continue;
        if (isos[i]=="reliso" && tree.mus_reliso()[imu]<GetIsolationCut(false, isos[i], true, tree.mus_eta()[imu])) nveto_mus++;
        else if (isos[i]=="reliso_r02" && tree.mus_reliso_r02()[imu]<GetIsolationCut(false, isos[i], true, tree.mus_eta()[imu])) nveto_mus++;
        else if (isos[i]=="miniso" && tree.mus_miniso_tr15()[imu]<GetIsolationCut(false, isos[i], true, tree.mus_eta()[imu])) nveto_mus++;
        else if (isos[i]=="ptrel"){
          bool passRelIso = tree.mus_reliso_r02()[imu]<GetIsolationCut(false, isos[i], true, tree.mus_eta()[imu]);
          bool passPtrel = tree.mus_ptrel_0()[imu]>GetIsolationCut(false, isos[i], true, tree.mus_eta()[imu]);
          if (passRelIso || passPtrel) nveto_mus++;
        }

        if (!(tree.mus_sigid()[imu])) continue;
        if (tree.mus_pt()[imu]<20.) continue;
        if (isos[i]=="reliso" && tree.mus_reliso()[imu]<GetIsolationCut(false, isos[i], false, tree.mus_eta()[imu])) sigmus_index.push_back(imu);
        else if (isos[i]=="reliso_r02" && tree.mus_reliso_r02()[imu]<GetIsolationCut(false, isos[i], false, tree.mus_eta()[imu])) sigmus_index.push_back(imu);
        else if (isos[i]=="miniso" && tree.mus_miniso_tr15()[imu]<GetIsolationCut(false, isos[i], false, tree.mus_eta()[imu])) sigmus_index.push_back(imu);
        else if (isos[i]=="ptrel"){
          bool passRelIso = tree.mus_reliso_r02()[imu]<GetIsolationCut(false, isos[i], false, tree.mus_eta()[imu]);
          bool passPtrel = tree.mus_ptrel_0()[imu]>GetIsolationCut(false, isos[i], false, tree.mus_eta()[imu]);
          if (passRelIso || passPtrel) sigmus_index.push_back(imu);
        }
      }

      // if (nveto_els+nveto_mus!=1 || siglep_index==-1) continue;
      if ((sigels_index.size()+sigmus_index.size())!=1 || (nveto_els+nveto_mus)!=1) continue;

      int channel = 0;
      if (sigmus_index.size()==1) channel = 1;
      h_cflow[channel][i].Fill(1,weight);

      if (!pass_ht) continue;
      h_cflow[channel][i].Fill(2,weight);

      if (!pass_met) continue;
      h_cflow[channel][i].Fill(3,weight);

      if (!pass_njets) continue;
      h_cflow[channel][i].Fill(4,weight);

      if (!pass_btag) continue;
      h_cflow[channel][i].Fill(5,weight);

      double mt = 0;
      if (sigels_index.size()>0) {
        mt = sqrt(2*tree.els_pt()[sigels_index[0]]*tree.met()*(1-cos(tree.met_phi()-tree.els_phi()[sigels_index[0]])));
        // if (isos[i]=="reliso") cout<<"tree.mt = "<<tree.mt()<<" calc = "<<mt<<endl;
      } else {
        mt = sqrt(2*tree.mus_pt()[sigmus_index[0]]*tree.met()*(1-cos(tree.met_phi()-tree.mus_phi()[sigmus_index[0]])));
      }
      // if (mt<=100. || tree.mt()<0) continue;
      if (mt<=100.) continue;
      // if (isos[i]=="reliso") cout<<"tree.mt = "<<tree.mt()<<" calc = "<<mt<<endl;
      h_cflow[channel][i].Fill(6,weight); 
    }

  }

  for (unsigned channel=0; channel<2; channel++)
    for (unsigned i=0; i<isos.size(); i++)
      h_cflow[channel][i].Write();
  fout.Close();


  return 0;
}


double GetIsolationCut(bool isElectron, string isotype, bool isveto, const double eta){

  if (isotype=="reliso"){ 
    if (isElectron){
      if (fabs(eta) <= 1.479) return isveto ? 0.3313 : 0.2179;
      else return isveto ? 0.3816 : 0.254;
    } else {
      return isveto ? 0.2 : 0.12;
    }
  } else if (isotype=="reliso_r02") {
    return 0.1;
  } else if (isotype=="miniso") {
    return 0.1;
  } else if (isotype=="ptrel") {
    return 10;
  } else {
    throw logic_error("Isolation cut not defined for isolation type"+isotype);
  }
  return 0;
}

