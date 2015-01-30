#include "loop_tree.hpp"

#include <iostream>
#include <fstream>
#include <cmath>
#include <stdexcept>

#include "TH1D.h"
#include "TFile.h"
#include "TString.h"

#include "RooStats/NumberCountingUtils.h"

using namespace std;

bool msgdbg = true;

int main(){

  const double ht_cut = 750.; //greater than
  const double met_cut = 250.; //greater than
  const int njets_cut = 6; //geq
  const int nbl_cut = 2; //geq
  const double mt_cut = 150.; //greater than
  const double mj_cut = 600.; //greater than

  TString cuts = TString::Format("ht%.0f_met%.0f_nj%i_nbl%i_mt%.0f_mj%.0f",ht_cut,met_cut,njets_cut,nbl_cut,mt_cut,mj_cut);
  TString texname = "txt/miniso_rmax02_e005_mu03_"+cuts+".tex";
  string isostr = "miniso"; 
  const double iso_cut[2] = {0.05, 0.3}; //el, mu

  // TString texname = "txt/stdiso_"+cuts+".tex";
  // string isostr = "reliso"; 
  // const double iso_cut[2] = {0., 0.}; //el, mu <--- irrelevant since standard cuts are hard-coded

  string basedir = "/cms2r0/manuelf/root/small/archive/14-12-21/";
  vector<string> samples;
  vector<string> samplestr;
  unsigned nbkgd = 0;
  unsigned nsig = 0;
  // backgrounds must be first and in the same order as to appear in the table
  samplestr.push_back("QCD"); samples.push_back("*_QCD_*"); nbkgd++;
  samplestr.push_back("$t\\bar{t}$ (1l)"); samples.push_back("*_TTJets_*"); nbkgd++;
  samplestr.push_back("$t\\bar{t}$ (2l)"); samples.push_back("*_TTJets_*"); nbkgd++; //just to keep count, will not loop separately
  samplestr.push_back("T1tttt (1200,800)"); samples.push_back("*-T1tttt_2J_mGl-1200_mLSP-800_*PU20*"); nsig++;
  samplestr.push_back("T1tttt (1500,100)"); samples.push_back("*-T1tttt_2J_mGl-1500_mLSP-100_*PU20*"); nsig++;
  // samplestr.push_back("T2tt (650,325)"); samples.push_back("*-T2tt_2J_mStop-650_mLSP-325_*"); nsig++;
  // samplestr.push_back("T2tt (850,100)"); samples.push_back("*-T2tt_2J_mStop-850_mLSP-100_*"); nsig++;

  const size_t nsamples = samples.size();

  vector< vector<TH1D> > h_cflow;
  h_cflow.push_back(vector<TH1D>());
  h_cflow.push_back(vector<TH1D>());
  // TString tempstr;
  for (unsigned i=0; i<nsamples; i++){
    TString istr; istr.Form("%i",i);
    h_cflow[0].push_back(TH1D("h_"+istr+"_el", istr + " e channel", 7, 0.5, 7.5));
    h_cflow[1].push_back(TH1D("h_"+istr+"_mu", istr + " #mu channel", 7, 0.5, 7.5));
  }

  for (uint isample=0; isample<nsamples; isample++) {

    if (samplestr[isample]=="$t\\bar{t}$ (2l)") continue;
    bool isttbar = (samplestr[isample].find("t\\bar{t}") != string::npos);


    small_tree tree(basedir+samples[isample]);

    const long nent = tree.GetEntries();
    cout<<"Number of events to run over: "<<nent<<endl;
    for (long ientry=0; ientry<nent; ientry++){
      tree.GetEntry(ientry);

      int ngenleps = 1;
      if (isttbar) {
        if ((tree.mc_type()&0x0F00)<=0x100) ngenleps = 1;
        if ((tree.mc_type()&0x0F00)>=0x200) ngenleps = 2;
      }

      double weight = tree.weight()*5;

      if (ientry%100000==0) cout<<"Processed events: "<<ientry<<endl;

      unsigned nveto_mus(0), nveto_els(0);
      vector<int> sigels_index;
      vector<int> sigmus_index;

      //---------- ELECTRONS ----------------      
      for (unsigned iel=0; iel<tree.els_pt().size(); iel++){
        if (!tree.els_ispf()[iel]) continue;
        if (tree.els_pt()[iel]<15.) continue;

        if (passIsolationCut(tree, iel, /*isElectron*/ true, /*isveto*/ true, isostr, iso_cut[0])) nveto_els++;
  

        if (!(tree.els_sigid()[iel])) continue;
        if (tree.els_pt()[iel]<20.) continue;
        if (passIsolationCut(tree, iel, /*isElectron*/ true, /*isveto*/ false, isostr, iso_cut[0])) sigels_index.push_back(iel);
      }
      
      //---------- MUONS ----------------
      for (unsigned imu=0; imu<tree.mus_pt().size(); imu++){
        if (tree.mus_pt()[imu]<15.) continue;
        if (passIsolationCut(tree, imu, /*isElectron*/ false, /*isveto*/ true, isostr, iso_cut[1])) nveto_mus++;

        if (!(tree.mus_sigid()[imu])) continue;
        if (tree.mus_pt()[imu]<20.) continue;
        if (passIsolationCut(tree, imu, /*isElectron*/ false, /*isveto*/ false, isostr, iso_cut[1])) sigmus_index.push_back(imu);
      }

      if ((sigels_index.size()+sigmus_index.size())!=1 || (nveto_els+nveto_mus)!=1) continue;

      int channel = 0;
      if (sigmus_index.size()==1) channel = 1;
      unsigned hindex = isample;
      if (ngenleps==2) hindex = isample+1;

      h_cflow[channel][hindex].Fill(1,weight);

      if (tree.ht() <= ht_cut) continue;
      h_cflow[channel][hindex].Fill(2,weight);

      if (tree.met() <= met_cut) continue;
      h_cflow[channel][hindex].Fill(3,weight);

      if (tree.njets() < njets_cut) continue;
      h_cflow[channel][hindex].Fill(4,weight);

      if (tree.nbl() < nbl_cut) continue;
      h_cflow[channel][hindex].Fill(5,weight);

      double mt = 0;
      if (sigels_index.size()>0) mt = sqrt(2*tree.els_pt()[sigels_index[0]]*tree.met()*(1-cos(tree.met_phi()-tree.els_phi()[sigels_index[0]])));
      else mt = sqrt(2*tree.mus_pt()[sigmus_index[0]]*tree.met()*(1-cos(tree.met_phi()-tree.mus_phi()[sigmus_index[0]])));
      if (mt <= mt_cut) continue;
      h_cflow[channel][hindex].Fill(6,weight); 

      if (tree.mj_30() <= mj_cut) continue;
      h_cflow[channel][hindex].Fill(7,weight);    
    }
  }


  ofstream file(texname);
  file<< "\\documentclass[]{article}\n";
  file<< "\\usepackage[landscape]{geometry}\n";
  file<< "\\begin{document}\n";

  enum {EL, MU};
  for (unsigned ichan=0; ichan < 3; ichan++) {

    vector<TString> cutstr;
    if (ichan==EL) cutstr.push_back("1 electron");
    else if (ichan==MU) cutstr.push_back("1 muon");
    else cutstr.push_back("1 lepton");
    cutstr.push_back("$H_{T} > "+TString::Format("%.0f",ht_cut)+"$");
    cutstr.push_back("MET$ > "+TString::Format("%.0f",met_cut)+"$");
    cutstr.push_back("$n_{\\mbox{jets}}\\geq$"+TString::Format("%i",njets_cut));
    cutstr.push_back("$n_{\\mbox{CSVL}}\\geq$"+TString::Format("%i",nbl_cut));
    cutstr.push_back("$m_{T} > "+TString::Format("%.0f",mt_cut)+"$");
    cutstr.push_back("$MJ > "+TString::Format("%.0f",mj_cut)+"$");
    
    file << "\\begin{table}\n";
    file << "\\begin{tabular}{ l ";
    for(unsigned col(0); col < nbkgd; col++) file << "|r ";
    for(unsigned col(nbkgd); col < nsamples; col++) file << "|rrr ";
    file<<"}\\hline\n";

    file << " Cut";
    for(unsigned col(0); col < nbkgd; col++) file << " & \\multicolumn{1}{|c}{\\bf{"<<samplestr[col]<<"}}";
    for(unsigned col(nbkgd); col < nsamples; col++) file << " & \\multicolumn{3}{|c}{\\bf{"<<samplestr[col]<<"}}";
    file << "\\\\ \n";

    for(unsigned col(0); col < nbkgd; col++) file << " &  ";
    for(unsigned col(nbkgd); col < nsamples; col++) file << " & \\multicolumn{1}{|r}{\\bf{S}}  & \\multicolumn{1}{r}{$\\mathbf{Z_{Bi}(\\tau=1)}$}  & \\multicolumn{1}{r}{$\\mathbf{Z_{Bi}(\\tau=1000)}$}";
    file << "\\\\ \\hline \n";

    for (unsigned icut(0); icut<cutstr.size(); icut++){
      file << cutstr[icut];
      double B = 0;
      for(unsigned col(0); col < nbkgd; col++) {
        double bcount(0.);
        if (ichan != MU) bcount += h_cflow[0][col].GetBinContent(icut+1);
        if (ichan != EL) bcount += h_cflow[1][col].GetBinContent(icut+1);
        B += bcount;
        file << " & " << TString::Format("%.1f", bcount); 
      }
      for(unsigned col(nbkgd); col < nbkgd+nsig; col++) {
        double S(0.);
        if (ichan != MU)  S += h_cflow[0][col].GetBinContent(icut+1);
        if (ichan != EL)  S += h_cflow[1][col].GetBinContent(icut+1);
        file << " & " << TString::Format("%.1f", S); 
        file << " & " << TString::Format("%.1f", RooStats::NumberCountingUtils::BinomialWithTauExpZ(S, B, 1.0)); 
        file << " & " << TString::Format("%.1f", RooStats::NumberCountingUtils::BinomialWithTauExpZ(S, B, 1000.0)); 
      }
      file << "\\\\ \n";
    }
    file<< "\\hline\n\\end{tabular}\n";
    TString caption; 
    if (isostr == "reliso") caption = "Standard isolation, ";
    else if (isostr == "miniso") caption = "Optimized mini-isolation, ";
    if (ichan == EL) caption += "$e$+jets channel.";
    else if (ichan == MU) caption += "$\\mu$+jets channel.";
    else caption += "$\\ell$+jets channel.";
    
    file << "\\caption{"+caption+"}\n";
    file << "\\end{table}\n";
  }
  file<< "\\end{document}\n";
  file.close();
  cout<<"Written "<<texname<<endl;

  return 0;
}


double passIsolationCut(const small_tree &tree, int ilep, bool isElectron, bool isveto, string isotype, const double iso_cut){

  if (isotype=="reliso"){ 
    if (isElectron){
      if (fabs(tree.els_eta()[ilep]) <= 1.479) 
        return (tree.els_reliso()[ilep] < (isveto ? 0.3313 : 0.2179));
      else 
        return (tree.els_reliso()[ilep] < (isveto ? 0.3816 : 0.254));
    } else {
      return (tree.mus_reliso()[ilep] < (isveto ? 0.2 : 0.12));
    }
  } else if (isotype=="reliso_r02") {
    if (isElectron) 
      return tree.els_reliso_r02()[ilep] < iso_cut;
    else 
      return tree.mus_reliso_r02()[ilep] < iso_cut;
  } else if (isotype=="miniso") {
    if (isElectron) 
      return ((tree.els_miniso_tr07()[ilep] < iso_cut) 
             || (tree.els_reliso_r02()[ilep] < iso_cut));
    else 
      return ((tree.mus_miniso_tr07()[ilep] < iso_cut) 
             || (tree.mus_reliso_r02()[ilep] < iso_cut));
  } else {
    throw logic_error("Isolation cut not defined for isolation type"+isotype);
  }
  return 0;
}
