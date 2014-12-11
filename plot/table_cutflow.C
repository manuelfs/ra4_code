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
#include "TH1D.h"
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

TString YieldsCut(TString title, TString cuts, vector<TChain*> chain,
		  vector<TString> sam_cuts, int nsig);

void table_cutflow(){
  // Reading ntuples
  vector<TChain *> chain;
  vector<TString> sam_cuts;
  vector<sfeats> Samples;
  //Samples.push_back(sfeats("archive/ra4skim/*QCD*", "QCD"));
  //Samples.push_back(sfeats("archive/ra4skim/*TTJet*", "$\\mathbf{t\\bar{t}}$"));
  //Samples.push_back(sfeats("archive/ra4skim/*WJets*", "W+jets"));
  //Samples.push_back(sfeats("archive/ra4skim/*_T*channel*", "1 top"));
  //Samples.push_back(sfeats("archive/ra4skim/*_DY*", "DY"));
  Samples.push_back(sfeats("archive/ra4skim/*TT_*", "ttbar,reliso", 1, 1, "(Sum$(mus_sigid&&mus_reliso<0.12)+Sum$(els_sigid&&((els_eta<=1.479&&els_reliso<0.2179)||(els_eta>1.479&&els_reliso<0.254))))==1"));
  Samples.push_back(sfeats("archive/ra4skim/*T1tttt*", "T1tttt,reliso", 1, 1, "(Sum$(mus_sigid&&mus_reliso<0.12)+Sum$(els_sigid&&((els_eta<=1.479&&els_reliso<0.2179)||(els_eta>1.479&&els_reliso<0.254))))==1"));
  Samples.push_back(sfeats("archive/ra4skim/*TT_*", "ttbar,ptrel", 1, 1, "(Sum$(mus_sigid&&(mus_ptrel_25<0||mus_ptrel_25>25||mus_mindr>0.4))+Sum$(els_sigid&&(els_ptrel_25<0||els_ptrel_25>25||els_mindr>0.4)))==1"));
  Samples.push_back(sfeats("archive/ra4skim/*T1tttt*", "T1tttt,ptrel", 1, 1, "(Sum$(mus_sigid&&(mus_ptrel_25<0||mus_ptrel_25>25||mus_mindr>0.4))+Sum$(els_sigid&&(els_ptrel_25<0||els_ptrel_25>25||els_mindr>0.4)))==1"));
  Samples.push_back(sfeats("archive/ra4skim/*TT_*", "ttbar,miniso", 1, 1, "(Sum$(mus_sigid&&mus_miniso/mus_pt<0.12)+Sum$(els_sigid&&((els_eta<=1.479&&els_miniso/els_pt<0.2179)||(els_eta>1.479&&els_miniso/els_pt<0.254))))==1"));
  Samples.push_back(sfeats("archive/ra4skim/*T1tttt*", "T1tttt,miniso", 1, 1, "(Sum$(mus_sigid&&mus_miniso/mus_pt<0.12)+Sum$(els_sigid&&((els_eta<=1.479&&els_miniso/els_pt<0.2179)||(els_eta>1.479&&els_miniso/els_pt<0.254))))==1"));
  
  int nsig(0);
  //Samples.push_back(sfeats("archive/ra4skim/*T1tttt*1200_*", "T1tttt(1200,800)"));
  //Samples.push_back(sfeats("archive/ra4skim/*T1tttt*1500_*", "T1tttt(1500,100)"));
  for(unsigned sam(0); sam < Samples.size(); sam++){
    chain.push_back(new TChain("tree"));
    int x=chain[sam]->Add(Samples[sam].file);
    sam_cuts.push_back(Samples[sam].cut);
    cout << x << " " << Samples[sam].file << endl << Samples[sam].cut << endl;
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

  file << YieldsCut("1 lepton", "1", chain, sam_cuts, nsig);
  file << YieldsCut("$H_{T} > 750$", "ht>750", chain, sam_cuts, nsig);
  file << YieldsCut("MET$ > 250$", "ht>750&&met>250", chain, sam_cuts, nsig);
  file << YieldsCut("$n_\\text{jets}\\geq$6", "ht>750&&met>250&&njets[1]>=6", chain, sam_cuts, nsig);
  file << YieldsCut("$n_\\text{CSVM}\\geq$2", "ht>750&&met>250&&njets[1]>=6&&nbl[1]>=2", chain, sam_cuts, nsig);
  file << YieldsCut("AllMET250 + $M_{T} > 100$", "ht>750&&met>250&&njets[1]>=6&&nbl[1]>=2&&mt>100", chain, sam_cuts, nsig);
  file<< "\\hline\\hline\n\\end{tabular}"<<endl<<endl;
  file.close();
  cout<<"Written "<<name<<endl;
}

TString YieldsCut(TString title, TString cuts, vector<TChain*> chain,
		  vector<TString> sam_cuts, int nsig){
  TString totCut, luminosity="5", Hname = "histo", out;
  vector<float> yield;
  float bkg(0);
  int nsam(chain.size());
  TH1D histo(Hname, "",100, 0, 10000);
  for(int sam(0); sam < nsam; sam++){
    totCut = luminosity+"*weight*(("+cuts+")&&("+sam_cuts[sam]+"))";
    //cout << sam << " " << chain[sam]->GetName() << " " << totCut << endl;
    chain[sam]->Project(Hname, "1", totCut);
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
