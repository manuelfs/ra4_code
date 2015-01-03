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


  vector<TString> v_t1;
  v_t1.push_back("/cms5r0/ald77/archive/20141216/*T1tttt*1500_*PU20*");
  vector<TString> v_t1pu40;
  v_t1pu40.push_back("/cms5r0/ald77/archive/20141216/*T1tttt*1500_*PU40*");
  vector<TString> v_tt;
  v_tt.push_back("/cms5r0/ald77/archive/20141216/*TT*");

  // Muon isolation ROC
  vector<sample_class> mus_tt_t1; 
  mus_tt_t1.push_back(sample_class("T1tttt(1500,100) truth-matched prompt #mu", v_t1, "mus_tru_tm&&mus_sigid"));
  mus_tt_t1.push_back(sample_class("tt non-truth-matched #mu", v_tt, "!mus_tru_tm&&mus_sigid"));

  vector<sample_class> mus_t1pu20; 
  mus_t1pu20.push_back(sample_class("T1tttt(1500,100) PU20 truth-matched prompt #mu", v_t1, "mus_tru_tm&&mus_sigid"));
  mus_t1pu20.push_back(sample_class("T1tttt(1500,100) PU20 non-TM #mu", v_t1, "!mus_tru_tm&&mus_sigid"));

  vector<sample_class> mus_t1pu40; 
  mus_t1pu40.push_back(sample_class("T1tttt(1500,100) PU40 truth-matched prompt #mu", v_t1pu40, "mus_tru_tm&&mus_sigid"));
  mus_t1pu40.push_back(sample_class("T1tttt(1500,100) PU40 non-TM #mu", v_t1pu40, "!mus_tru_tm&&mus_sigid"));

  vector<var_class> vars;
  vars.push_back(var_class("mus_reliso",0,10,"Rel. Iso.",1,1));
  vars.push_back(var_class("mus_reliso_r02",0,10,"Rel. Iso. #DeltaR=0.2",1,2));
  vars.push_back(var_class("mus_miniso_tr15",0,10,"Mini Iso. Tr., kt = 15 GeV",4));
  vars.push_back(var_class("mus_miniso_tr15_ch",0,10,"Mini Iso. Tr., kt = 15 GeV (ch. only)",4,2));
  vars.push_back(var_class("mus_ptrel_0+(mus_reliso_r02<0.2)*9999.",100,0,
			   "p_{T}^{rel} || Rel Iso #DeltaR=0.2 < 0.2",2));
  vars.push_back(var_class("mus_ptrel_0+(mus_reliso_r02<0.1)*9999.",100,0,
			   "p_{T}^{rel} || Rel Iso #DeltaR=0.2 < 0.1",3));

  DrawROC(mus_tt_t1, vars, "mus_pt>20&&ht>750&&met>250&&npv<20", "mus_isott");
  DrawROC(mus_t1pu20, vars, "mus_pt>20&&ht>750&&met>250&&npv<20", "mus_isopu20");
  DrawROC(mus_t1pu40, vars, "mus_pt>20&&ht>750&&met>250&&npv>30", "mus_isopu40");

  // ELECTRONS
  vector<sample_class> els_tt_t1; 
  els_tt_t1.push_back(sample_class("T1tttt(1500,100) truth-matched prompt #mu", v_t1, "els_tru_tm&&els_sigid&&els_ispf"));
  els_tt_t1.push_back(sample_class("tt non-truth-matched #mu", v_tt, "!els_tru_tm&&els_sigid&&els_ispf"));

  vector<sample_class> els_t1pu20; 
  els_t1pu20.push_back(sample_class("T1tttt(1500,100) PU20 truth-matched prompt e", v_t1, "els_tru_tm&&els_sigid&&els_ispf"));
  els_t1pu20.push_back(sample_class("T1tttt(1500,100) PU20 non-TM e", v_t1, "!els_tru_tm&&els_sigid&&els_ispf"));

  vector<sample_class> els_t1pu40; 
  els_t1pu40.push_back(sample_class("T1tttt(1500,100) PU40 truth-matched prompt e", v_t1pu40, "els_tru_tm&&els_sigid&&els_ispf"));
  els_t1pu40.push_back(sample_class("T1tttt(1500,100) PU40 non-TM e", v_t1pu40, "!els_tru_tm&&els_sigid&&els_ispf"));

  vector<var_class> els_vars;
  els_vars.push_back(var_class("els_reliso",0,10,"Rel. Iso.",1,1));
  els_vars.push_back(var_class("els_reliso_r02",0,10,"Rel. Iso. #DeltaR=0.2",1,2));
  els_vars.push_back(var_class("els_miniso_tr15",0,10,"Mini Iso. Tr., kt = 15 GeV",4));
  els_vars.push_back(var_class("els_miniso_tr15_ch",0,10,"Mini Iso. Tr., kt = 15 GeV (ch. only)",4,2));
  els_vars.push_back(var_class("els_ptrel_0+(els_reliso_r02<0.2)*9999.",100,0,
			   "p_{T}^{rel} || Rel Iso #DeltaR=0.2 < 0.2",2));
  els_vars.push_back(var_class("els_ptrel_0+(els_reliso_r02<0.1)*9999.",100,0,
			   "p_{T}^{rel} || Rel Iso #DeltaR=0.2 < 0.1",3));

  DrawROC(els_tt_t1, els_vars, "els_pt>20&&ht>750&&met>250&&npv<20", "els_isott");
  DrawROC(els_t1pu20, els_vars, "els_pt>20&&ht>750&&met>250&&npv<20", "els_isopu20");
  DrawROC(els_t1pu40, els_vars, "els_pt>20&&ht>750&&met>250&&npv>30", "els_isopu40");

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
  title.ReplaceAll("met", "MET"); title.ReplaceAll("ht", "H_{T}");  title.ReplaceAll("mt", "m_{T}"); 
  title.ReplaceAll("nleps==1", "1 lepton");  title.ReplaceAll("npv","n_{PV}");
  title.ReplaceAll("njets30","n_{jets}^{30}"); title.ReplaceAll("nbm30","n_{b}^{30}");
  title.ReplaceAll("njets","n_{jets}"); title.ReplaceAll("nbm","n_{b}");
  title.ReplaceAll("mindphin_metje","min#Delta#phi_{N}");
  title.ReplaceAll("nbl","n_{b,l}");
  TH1D base_histo("base",title,1,0,1.0);
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

