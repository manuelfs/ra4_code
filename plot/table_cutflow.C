// table_cutflow.C: Generates a LaTeX file with a cutflow table for RA4

#define INT_ROOT
#include "inc/utilities.hpp"
#include "src/utilities.cpp"

#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include "TChain.h"
#include "TFile.h"
#include "TString.h"
#include "TH1F.h"
#include "TMath.h"

using namespace std;
using std::cout;
using std::endl;


class sfeats {
public:
  sfeats(TString ifile, TString ilabel, int icolor=1, int istyle=1, TString icut="1"){
    file = ifile; label = ilabel; cut = icut;
    color = icolor; style = istyle;
  }
  TString file, label, cut;
  int color, style;
};

TString YieldsCut(TString title, TString cuts, vector<TChain*> chain, int nsig);

void table_cutflow(){
  // Reading ntuples
  vector<TChain *> chain;
  vector<sfeats> Samples; 
  Samples.push_back(sfeats("archive/ra4skim/*QCD*", "QCD"));
  Samples.push_back(sfeats("archive/ra4skim/*TT*", "$\\mathbf{t\\bar{t}}$"));
  Samples.push_back(sfeats("archive/ra4skim/*WJets*", "W+jets"));
  Samples.push_back(sfeats("archive/ra4skim/*_T*channel*", "1 top"));
  Samples.push_back(sfeats("archive/ra4skim/*_DY*", "DY"));
  int nsig(2);
  Samples.push_back(sfeats("archive/ra4skim/*T1tttt*1200_*", "T1tttt(1200,800)"));
  Samples.push_back(sfeats("archive/ra4skim/*T1tttt*1500_*", "T1tttt(1500,100)"));
  for(unsigned sam(0); sam < Samples.size(); sam++){
    chain.push_back(new TChain("tree"));
    chain[sam]->Add(Samples[sam].file);
  }
  
  TString name = "txt/ra4_cutflow.tex";
  ofstream file(name);
  
  file << "\n\\begin{tabular}{ l | rrrrr | r | rr | r}\\hline\\hline\n";
  file << " &&&&&&& \\bf{T1tttt} & \\bf{T1tttt} & \\\\"<<endl;
  file << " \\multicolumn{1}{c|}{\\bf{Cut}} ";
  for(unsigned sam(0); sam < Samples.size()-nsig; sam++)
    file << " & \\bf{"<<Samples[sam].label<<"}";
  file<< " & \\multicolumn{1}{c|}{\\bf{SM bkg}} ";
  file << " & \\multicolumn{1}{c}{\\bf{(1200,800)}} ";
  file << " & \\multicolumn{1}{c|}{\\bf{(1500,100)}} & $\\mathbf{S/\\sqrt{B}}$ \\\\ \\hline \n ";

  file << YieldsCut("1 lepton", "nleps==1", chain, nsig);
  file << YieldsCut("$H_{T} > 750$", "nleps==1&&ht>750", chain, nsig);
  file << YieldsCut("MET$ > 250$", "nleps==1&&ht>750&&met>250", chain, nsig);
  file << YieldsCut("$n_\\text{jets}\\geq$6", "nleps==1&&ht>750&&met>250&&njets[1]>=6", chain, nsig);
  file << YieldsCut("$n_\\text{CSVM}\\geq$2", "nleps==1&&ht>750&&met>250&&njets[1]>=6&&nbl[1]>=2", chain, nsig);
  file << "\\hline "<<endl;
  file << YieldsCut("AllMET250 + $M_{T} > 100$", "nleps==1&&ht>750&&met>250&&njets[1]>=6&&nbl[1]>=2&&mt>100", chain, nsig);
  file << YieldsCut("AllMET250 + $\\Delta\\phi(W,\\ell) > 1$", "nleps==1&&ht>750&&met>250&&njets[1]>=6&&nbl[1]>=2&&dphi_wlep>1", chain, nsig);
  file << "\\hline "<<endl;
  file << YieldsCut("AllMET500 + $M_{T} > 100$", "nleps==1&&ht>750&&met>500&&njets[1]>=6&&nbl[1]>=2&&mt>100", chain, nsig);
  file << YieldsCut("AllMET500 + $\\Delta\\phi(W,\\ell) > 1$", "nleps==1&&ht>750&&met>500&&njets[1]>=6&&nbl[1]>=2&&dphi_wlep>1", chain, nsig);

  file<< "\\hline\\hline\n\\end{tabular}"<<endl<<endl;
  file.close();
  cout<<"Written "<<name<<endl;
}

TString YieldsCut(TString title, TString cuts, vector<TChain*> chain, int nsig){
  TString totCut, luminosity="5", Hname = "histo", out;
  vector<float> yield;
  float bkg(0);
  int nsam(chain.size());
  TH1F histo(Hname, "",100, 0, 10000);
  for(int sam(0); sam < nsam; sam++){
    totCut = luminosity+"/19.6*weight*("+cuts+")";
    chain[sam]->Project(Hname, "met", totCut);
    yield.push_back(histo.Integral(0,101));
    if(sam<nsam-nsig) bkg += yield[sam];
    //cout<<sam<<": yield "<<yield[sam]<<" \t "<<totCut<<endl;
  }
  
  out = title;
  for(int sam(0); sam < nsam-nsig; sam++) out += (" & " + RoundNumber(yield[sam],0));
  out += (" & "+RoundNumber(bkg,0));
  for(int sam(nsam-nsig); sam < nsam; sam++) out += (" & " + RoundNumber(yield[sam],1));
  out += (" & "+RoundNumber(yield[nsam-1],2,sqrt(bkg)) + " \\\\ \n");
  cout<<out;
  return out;
}
