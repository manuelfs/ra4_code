// plot_roc: Macro that plots ROC curves

#include <stdexcept>
#include <iostream>

#include "TChain.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TLine.h"
#include "TDirectory.h"

#include "styles.hpp"
#include "utilities.hpp"
#include "plot_roc.hpp"

using namespace std;

int main(){
  styles style("1Dtitle"); style.setDefaultStyle();

  vector<TString> v_t1pu20csa;
  v_t1pu20csa.push_back("out/*T1tttt*1500_*PU20*");
  vector<TString> v_ttcsa;
  //v_ttcsa.push_back("out/*TTJet*batch5*");
  v_ttcsa.push_back("out/*TTJet*");
  vector<TString> v_qcdcsa;
  v_qcdcsa.push_back("out/*QCD*");

  vector<TString> v_t1pu20;
  v_t1pu20.push_back("archive/ra4skim/*T1tttt*1500_*PU20*");
  vector<TString> v_tt;
  //v_tt.push_back("archive/14-12-21/*TTJet*batch5*");
  v_tt.push_back("archive/14-12-21/*TTJet*");
  vector<TString> v_ttpyth;
  //v_ttpyth.push_back("archive/ra4skim/*TT_*batch2*");
  v_ttpyth.push_back("archive/ra4skim/*TT_*");
  vector<TString> v_qcd;
  v_qcd.push_back("archive/ra4skim/*QCD*");

  // Muon isolation ROC
  vector<sample_class> samples; 
  samples.push_back(sample_class("PHYS14 T1tttt(1500,100)", v_t1pu20));
  samples.push_back(sample_class("PHYS14 tt", v_tt));

  vector<sample_class> samplespyth; 
  samplespyth.push_back(sample_class("PHYS14 T1tttt(1500,100)", v_t1pu20));
  samplespyth.push_back(sample_class("PHYS14 Pythia8 tt", v_ttpyth));

  vector<sample_class> samplescsa; 
  samplescsa.push_back(sample_class("CSA14 T1tttt(1500,100)", v_t1pu20csa));
  samplescsa.push_back(sample_class("CSA14 tt", v_ttcsa));

  vector<sample_class> qcd; 
  qcd.push_back(sample_class("T1tttt(1500,100)", v_t1pu20));
  qcd.push_back(sample_class("QCD", v_qcd));

  vector<var_class> vars;
  vars.push_back(var_class("ht",4000,0,"H_{T}",1,1));
  vars.push_back(var_class("mj_30",2500,0,"M_{J}",4,1));
  vars.push_back(var_class("mj_0",2500,0,"M_{J}^{10}",2,1));
  vars.push_back(var_class("mj_scln_30",2500,0,"M_{J} no lepton",5,1));
  vars.push_back(var_class("mj_r10",2500,0,"M_{J} #DeltaR = 1.0",6,1));
  vars.push_back(var_class("mj_r15",2500,0,"M_{J} #DeltaR = 1.5",8,1));
  vars.push_back(var_class("mj_cands",2500,0,"M_{J}^{pfcand}",7,2));
  vars.push_back(var_class("mj_cands_trim",2500,0,"M_{J}^{pfcand} trimmed",7,1));
  vars.push_back(var_class("mj_eta25",2500,0,"M_{J} |#eta|<2.5",28,1));
  //vars.push_back(var_class("mindphin_metjet",20,0,"min#Delta#phi_{N}",9,1));


  DrawROC(samplescsa, vars, "nleps==1&&met>250&&njets>=6", "mj_tt_csa");
  DrawROC(samples, vars, "nleps==1&&met>250&&njets>=6", "mj_tt");
  DrawROC(samplespyth, vars, "nleps==1&&met>250&&njets>=6", "mj_tt_pyth");

  DrawROC(samplescsa, vars, "nvmus10==0&&nvels10==0&&met>250&&njets30>=6&&mindphin_metjet>0.4", "mj_tt_csa");
  DrawROC(samples, vars, "nvmus10==0&&nvels10==0&&met>250&&njets30>=6&&mindphin_metjet>0.4", "mj_tt");
  DrawROC(samplespyth, vars, "nvmus10==0&&nvels10==0&&met>250&&njets30>=6&&mindphin_metjet>0.4", "mj_tt_pyth");

  // DrawROC(samplescsa, vars, "nleps==1&&met>400", "mj_tt_csa");
  // DrawROC(samples, vars, "nleps==1&&met>400", "mj_tt");
  // DrawROC(samplespyth, vars, "nleps==1&&met>400", "mj_tt_pyth");



}

void DrawROC(vector<sample_class> samples, vector<var_class> vars, TString cuts, TString tag){
  TCanvas can;
  const int nbins(1000);
  vector<vector<TH1D> > histos;
  TString hname, totcut;
  TChain *chain[2];

  for(unsigned sam(0); sam < samples.size(); sam++){
    // Loading chains
    for(unsigned isam(0); isam < samples[sam].files.size(); isam++){
      chain[sam] = new TChain("tree");
      chain[sam]->Add(samples[sam].files[isam]);
    }
    histos.push_back(vector<TH1D>());

    // Projecting variables
    for(unsigned var(0); var<vars.size(); var++){
      float minh(vars[var].minx), maxh(vars[var].maxx);
      if(minh > maxh){
	minh = maxh;
	maxh = vars[var].minx;
      }
      hname = "histo"; hname += sam; hname += var;
      totcut = "weight*("+cuts+"&&"+samples[sam].cut+")";
      histos[sam].push_back(TH1D(hname,"",nbins,minh,maxh));
      chain[sam]->Project(hname, vars[var].varname, totcut);
    } // Loop over variables
  } // Loop over samples

  TString title(cuts);
  if(title=="1") title = "";
  title.ReplaceAll("nvmus10==0&&nvels10==0", "0 leptons");  
  title.ReplaceAll("els_pt","p^{e}_{T}");title.ReplaceAll("mus_pt","p^{#mu}_{T}");
  title.ReplaceAll(">=", " #geq "); 
  title.ReplaceAll(">", " > "); title.ReplaceAll("<", " < "); title.ReplaceAll("&&", ", "); 
  title.ReplaceAll("mindphin_metjet","min#Delta#phi_{N}");
  title.ReplaceAll("met", "MET"); title.ReplaceAll("ht", "H_{T}");  title.ReplaceAll("mt", "m_{T}"); 
  title.ReplaceAll("nleps==1", "1 lepton");  title.ReplaceAll("npv","n_{PV}");
  title.ReplaceAll("njets30","n_{jets}^{30}"); title.ReplaceAll("nbm30","n_{b}^{30}");
  title.ReplaceAll("njets","n_{jets}"); title.ReplaceAll("nbm","n_{b}");
  title.ReplaceAll("nbl","n_{b,l}");
  TH1D base_histo("base",title,1,0.2,1.0);
  base_histo.SetXTitle(samples[0].label+" efficiency");
  base_histo.SetYTitle(samples[1].label+" rejection rate");
  base_histo.SetMinimum(0.0);
  base_histo.SetMaximum(1.0);
  base_histo.SetDirectory(0);
  base_histo.Draw();

  // Legend
  double legX = 0.13, legY = 0.15, legSingle = 0.059;
  double legW = 0.12, legH = legSingle*vars.size();
  TLegend leg(legX, legY, legX+legW, legY+legH);
  leg.SetTextSize(0.048); leg.SetFillColor(0); leg.SetFillStyle(0); leg.SetBorderSize(0);
  leg.SetTextFont(132);

  // Making individual graphs
  TGraph graphs[100]; // Had to make it an array because a vector<TGraph> kept crashing
  for(unsigned var(0); var<vars.size(); var++){
    graphs[var] = MakeROC(histos[0][var], histos[1][var], vars[var].minx < vars[var].maxx);
    graphs[var].SetLineColor(vars[var].color);
    graphs[var].SetLineStyle(vars[var].style);
    graphs[var].SetLineWidth(3);
    leg.AddEntry(&(graphs[var]), vars[var].title, "l");
    graphs[var].Draw("lsame");
  } // Loop over variables
  leg.Draw();

  cuts.ReplaceAll(".",""); 
  cuts.ReplaceAll("(",""); cuts.ReplaceAll("$","");  cuts.ReplaceAll(")",""); 
  cuts.ReplaceAll("[",""); cuts.ReplaceAll("]",""); 
  cuts.ReplaceAll("/","_"); cuts.ReplaceAll("*",""); cuts.ReplaceAll("&&","_");
  cuts.ReplaceAll(">",""); cuts.ReplaceAll("<",""); cuts.ReplaceAll("=","");
  cuts.ReplaceAll("+",""); 
  TString pname("eps/roc_"+tag+"_"+cuts+".eps");  
  can.Print(pname);

  for(unsigned sam(0); sam < samples.size(); sam++)
    chain[sam]->Delete();
}

TGraph MakeROC(TH1D &good, TH1D &bad, const bool less_is_better){
  const int nbins = good.GetNbinsX();
  if(bad.GetNbinsX() != nbins) throw logic_error("Mismatched number of bins");

  TGraph graph(0);
  const double good_tot = good.Integral(0, nbins+1);
  const double bad_tot = bad.Integral(0, nbins+1);
  if(less_is_better){
    for(int bin = nbins+1; bin>=0; --bin){
      const double good_pass = good.Integral(0, bin);
      const double bad_pass = bad.Integral(0, bin);
      const double x = good_pass/good_tot;
      const double y = 1.0-bad_pass/bad_tot;
      graph.SetPoint(graph.GetN(), x, y);
    }
  }else{
    for(int bin = 0; bin<=nbins+1; ++bin){
      const double good_pass = good.Integral(bin,nbins+1);
      const double bad_pass = bad.Integral(bin, nbins+1);
      const double x = good_pass/good_tot;
      const double y = 1.0-bad_pass/bad_tot;
      graph.SetPoint(graph.GetN(), x, y);
    }
  }
  TString name(good.GetName());
  name += "graph";
  graph.SetName(name);
  graph.SetTitle(name);

  return graph;
}

var_class::var_class(TString ivarname, float iminx, float imaxx, TString ititle, int icolor, 
	    int istyle, vector<int> icuts){
  varname = ivarname; minx = iminx; maxx = imaxx; title = ititle;
  cuts = icuts; 
  color = icolor; style = istyle;
}

sample_class::sample_class(TString ilabel, vector<TString> ifiles, TString icut){
  files = ifiles; label = ilabel; cut = icut;
}

