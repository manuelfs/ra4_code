#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>     /* atoi */
#include "TChain.h"
#include "TFile.h"
#include "TString.h"
#include "TMath.h"
#include "TSystem.h"
#include "TDirectory.h"

using namespace std;
using std::cout;
using std::endl;


void get_pu_weights(){

  

  TString drellyan = "/net/cms29/cms29r0/heller/susy_cfa/out/DY_NLO/";
  TString doublelep = "/net/cms29/cms29r0/heller/susy_cfa/out/DoubleLep/";
  TString folder_ns="/net/cms2/cms2r0/ald77/archive/2015_08_13/";


  TChain dat("tree"); dat.Add(doublelep+"*.root");
  TChain mc("tree");

  mc.Add(drellyan+"*.root");
  mc.Add(folder_ns+"*_TTJet*50ns*");
  mc.Add(folder_ns+"*_ZJet*");
  mc.Add(folder_ns+"*WH_HToBB*");
  mc.Add(folder_ns+"*ST_*");
  mc.Add(folder_ns+"*_WJets*");
  mc.Add(folder_ns+"*QCD_Pt*");

  float bins[] ={0,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,40}; 
  int nbins=24;

  TFile * file = new TFile("pu_weights.root","recreate");
  TH1F * h_mc = new TH1F("h_mc","h_mc",nbins,bins); h_mc->Sumw2();
  TH1F * h_dat = new TH1F("h_dat","h_dat",nbins,bins);  h_dat->Sumw2();


  TString mll("&&(mumuv_m*(mumuv_m>0)+elelv_m*(elelv_m>0))>80&&(mumuv_m*(mumuv_m>0)+elelv_m*(elelv_m>0))<100");

  TString datacut = "(trig[25]||trig[15])&&json_golden&&";
  TString selection = "pass&&(nmus>=2||nels>=2)"+mll;

  mc.Project("h_mc", "npv",selection);
  dat.Project("h_dat", "npv",datacut+selection);

  float norm_mc = h_mc->Integral();
  float norm_dat = h_dat->Integral();
  
  h_mc->Scale(1.0/norm_mc);
  h_dat->Scale(1.0/norm_dat);

  TH1F * h_SF = h_dat->Clone("sf");
  h_SF->Divide(h_mc);

  file->Print();
  file->Write();
  file->Close();
  
  
  

}
