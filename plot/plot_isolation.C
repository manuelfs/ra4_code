// plot_distribution: Macro that plots variables both lumi weighted and normalized to the same area.

#define INT_ROOT
#include "inc/styles.hpp"
#include "src/styles.cpp"
#include "inc/utilities.hpp"
#include "src/utilities.cpp"

#include "TChain.h"
#include "TH1D.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TLine.h"
#include "TString.h"

using namespace std;
using std::cout;
using std::endl;

class hfeats {
public:
  hfeats(TString ivarname, int inbins, float iminx, float imaxx, vector<int> isamples,
	 TString ititle="", TString icuts="1", float icut=-1){
    varname = ivarname; nbins = inbins; minx = iminx; maxx = imaxx; title = ititle;
    cuts = icuts; cut = icut; samples = isamples;
    tag = ivarname+"_"+cuts; tag.ReplaceAll("_1",""); tag.ReplaceAll(".",""); 
    tag.ReplaceAll("(",""); tag.ReplaceAll("$","");  tag.ReplaceAll(")",""); 
    tag.ReplaceAll("[",""); tag.ReplaceAll("]",""); 
    tag.ReplaceAll("/","_"); tag.ReplaceAll("*",""); tag.ReplaceAll("&&","_");
    tag.ReplaceAll(">",""); tag.ReplaceAll("<",""); tag.ReplaceAll("=","");
    tag.ReplaceAll("+",""); 
    unit = "";
    if(title.Contains("GeV)")) unit = "GeV";
    if(title.Contains("phi")) unit = "rad";
  }
  TString title, varname, tag, cuts, unit;
  int nbins;
  float minx, maxx, cut;
  vector<int> samples;
};

class sfeats {
public:
  sfeats(TString ifile, TString ilabel, int icolor, int istyle=1, TString icut="1"){
    file = ifile; label = ilabel; cut = icut;
    color = icolor; style = istyle;
  }
  TString file, label, cut;
  int color, style;
};

void plot_isolation(bool use_mus=true, TString luminosity="5"){
  styles style("Standard"); style.setDefaultStyle(); gStyle->SetPadTickY(1); 
  vector<hfeats> vars;
  TCanvas can;

  // Reading ntuples
  vector<TChain *> chain;
  vector<sfeats> Samples; 
  Samples.push_back(sfeats("archive/ra4skim/*T1tttt*1500_*", "T1tttt(1500,100), #mu from W", 2, 1, "mus_tru_tm"));
  Samples.push_back(sfeats("archive/ra4skim/*T1tttt*1500_*", "T1tttt(1500,100), #mu not from W", 4, 1, 
			   "!mus_tru_tm&&abs(mus_tru_id)==13"));
  Samples.push_back(sfeats("archive/ra4skim/*T1tttt*1500_*", "T1tttt(1500,100), fake #mu", 28, 1, "abs(mus_tru_id)!=13"));

  Samples.push_back(sfeats("archive/ra4skim/*TT*", "tt, #mu from W", 2, 1, "mus_tru_tm"));
  Samples.push_back(sfeats("archive/ra4skim/*TT*", "tt, #mu not from W", 4, 1, 
			   "!mus_tru_tm&&abs(mus_tru_id)==13"));
  Samples.push_back(sfeats("archive/ra4skim/*TT*", "tt, fake #mu", 28, 1, "abs(mus_tru_id)!=13"));
  Samples.push_back(sfeats("archive/ra4skim/*T1tttt*1500_*", "T1tttt(1500,100), el from W", 2, 1, "els_tru_tm"));
  Samples.push_back(sfeats("archive/ra4skim/*T1tttt*1500_*", "T1tttt(1500,100), el not from W", 4, 1, 
			   "!els_tru_tm&&abs(els_tru_id)==13"));
  Samples.push_back(sfeats("archive/ra4skim/*T1tttt*1500_*", "T1tttt(1500,100), fake el", 28, 1, "abs(els_tru_id)!=13"));

  Samples.push_back(sfeats("archive/ra4skim/*TT*", "tt, el from W", 2, 1, "els_tru_tm"));
  Samples.push_back(sfeats("archive/ra4skim/*TT*", "tt, el not from W", 4, 1, 
			   "!els_tru_tm&&abs(els_tru_id)==13"));
  Samples.push_back(sfeats("archive/ra4skim/*TT*", "tt, fake el", 28, 1, "abs(els_tru_id)!=13"));

  for(unsigned sam(0); sam < Samples.size(); sam++){
    chain.push_back(new TChain("tree"));
    chain[sam]->Add(Samples[sam].file);
  }

  vector<int> allsamples;
  if(use_mus){
    allsamples.push_back(0); //(1500,100) TM mus from W
    allsamples.push_back(2); //(1500,100) TM mus not from W
    allsamples.push_back(1); //(1500,100) non-TM mus
  }else{
    allsamples.push_back(6); //(1500,100) TM els from W
    allsamples.push_back(8); //(1500,100) TM els not from W
    allsamples.push_back(7); //(1500,100) non-TM els
  }

  if(use_mus){
    vars.push_back(hfeats("mus_reliso",50,0,1,allsamples,"Muon relative isolation","mus_pt>20&&mus_pt<50",0.12));
    vars.push_back(hfeats("mus_ptrel",50,0,50,allsamples,"Muon p_{T}^{rel}","mus_pt>20&&mus_pt<50",15.));
    vars.push_back(hfeats("mus_ptrel_25",50,0,50,allsamples,"Muon p_{T}^{rel}(25 GeV jets)","mus_pt>20&&mus_pt<50",25.));
    vars.push_back(hfeats("mus_mindr",50,0,1,allsamples,"Muon Min #Delta R","mus_pt>20&&mus_pt<50",0.4));
    vars.push_back(hfeats("mus_mindr_25",50,0,1,allsamples,"Muon Min #Delta R(25 GeV jets)","mus_pt>20&&mus_pt<50",0.4));
    vars.push_back(hfeats("mus_miniso/mus_pt",50,0,1,allsamples,"Muon mini isolation","mus_pt>20&&mus_pt<50",0.12));
    vars.push_back(hfeats("mus_miniso_ch/mus_pt",50,0,1,allsamples,"Muon mini isolation (charged only)","mus_pt>20&&mus_pt<50",0.12));

    vars.push_back(hfeats("mus_reliso",50,0,1,allsamples,"Muon relative isolation","mus_pt>100",0.12));
    vars.push_back(hfeats("mus_ptrel",50,0,50,allsamples,"Muon p_{T}^{rel}","mus_pt>100",15.));
    vars.push_back(hfeats("mus_ptrel_25",50,0,50,allsamples,"Muon p_{T}^{rel}(25 GeV jets)","mus_pt>100",25.));
    vars.push_back(hfeats("mus_mindr",50,0,1,allsamples,"Muon Min #Delta R","mus_pt>100",0.4));
    vars.push_back(hfeats("mus_mindr_25",50,0,1,allsamples,"Muon Min #Delta R(25 GeV jets)","mus_pt>100",0.4));
    vars.push_back(hfeats("mus_miniso/mus_pt",50,0,1,allsamples,"Muon mini isolation","mus_pt>100",0.12));
    vars.push_back(hfeats("mus_miniso_ch/mus_pt",50,0,1,allsamples,"Muon mini isolation (charged only)","mus_pt>100",0.12));
  }else{
    vars.push_back(hfeats("els_reliso",50,0,1,allsamples,"Electron relative isolation","els_pt>20&&els_pt<50",0.2179));
    vars.push_back(hfeats("els_ptrel",50,0,50,allsamples,"Electron p_{T}^{rel}","els_pt>20&&els_pt<50",15.));
    vars.push_back(hfeats("els_ptrel_25",50,0,50,allsamples,"Electron p_{T}^{rel}(25 GeV jets)","els_pt>20&&els_pt<50",25.));
    vars.push_back(hfeats("els_mindr",50,0,1,allsamples,"Electron Min #Delta R","els_pt>20&&els_pt<50",0.4));
    vars.push_back(hfeats("els_mindr_25",50,0,1,allsamples,"Electron Min #Delta R(25 GeV jets)","els_pt>20&&els_pt<50",0.4));
    vars.push_back(hfeats("els_miniso/els_pt",50,0,1,allsamples,"Electron mini isolation","els_pt>20&&els_pt<50",0.12));
    vars.push_back(hfeats("els_miniso_ch/els_pt",50,0,1,allsamples,"Electron mini isolation (charged only)","els_pt>20&&els_pt<50",0.2179));

    vars.push_back(hfeats("els_reliso",50,0,1,allsamples,"Electron relative isolation","els_pt>100",0.2179));
    vars.push_back(hfeats("els_ptrel",50,0,50,allsamples,"Electron p_{T}^{rel}","els_pt>100",15.));
    vars.push_back(hfeats("els_ptrel_25",50,0,50,allsamples,"Electron p_{T}^{rel}(25 GeV jets)","els_pt>100",25.));
    vars.push_back(hfeats("els_mindr",50,0,1,allsamples,"Electron Min #Delta R","els_pt>100",0.4));
    vars.push_back(hfeats("els_mindr_25",50,0,1,allsamples,"Electron Min #Delta R(25 GeV jets)","els_pt>100",0.4));
    vars.push_back(hfeats("els_miniso/els_pt",50,0,1,allsamples,"Electron mini isolation","els_pt>100",0.2179));
    vars.push_back(hfeats("els_miniso_ch/els_pt",50,0,1,allsamples,"Electron mini isolation (charged only)","els_pt>100",0.2179));
  }

  float minLog = 0.04, maxLog = 10;
  double legX = 0.35, legY = 0.91, legSingle = 0.055;
  double legW = 0.12, legH = legSingle*vars[0].samples.size();
  TLegend leg(legX, legY-legH, legX+legW, legY);
  leg.SetTextSize(0.048); leg.SetFillColor(0); leg.SetFillStyle(0); leg.SetBorderSize(0);
  leg.SetTextFont(132);

  TLine line; line.SetLineColor(28); line.SetLineWidth(4); line.SetLineStyle(2);
  vector< vector<TH1D*> > histo[2];
  vector<TH1D*> varhisto;
  vector<float> nentries;
  TString hname, pname, variable, leghisto, totCut, title, ytitle;
  for(unsigned var(0); var<vars.size(); var++){
    cout<<endl;
    // Generating vector of histograms
    title = vars[var].cuts; if(title=="1") title = "";
    title.ReplaceAll("nvmus==1&&nmus==1&&nvels==0","1 #mu");
    title.ReplaceAll("els_pt","p^{e}_{T}");title.ReplaceAll("mus_pt","p^{#mu}_{T}");
    title.ReplaceAll("njets","n_{jets}");title.ReplaceAll("abs(lep_id)==13&&","");
    title.ReplaceAll(">=", " #geq "); title.ReplaceAll(">", " > "); title.ReplaceAll("&&", ", "); 
    title.ReplaceAll("met", "MET"); title.ReplaceAll("ht", "H_{T}");  title.ReplaceAll("mt", "m_{T}"); 
    title.ReplaceAll("nleps==1", "1 lepton");  title.ReplaceAll("nbm","n_{b}");
    title.ReplaceAll("nbl[1]","n_{b,l}");
    for(unsigned his(0); his < 2; his++){
      varhisto.resize(0);
      for(unsigned sam(0); sam < vars[var].samples.size(); sam++){
	hname = "histo"; hname += var; hname += his; hname += sam;
	varhisto.push_back(new TH1D(hname, title, vars[var].nbins, vars[var].minx, vars[var].maxx));
      }
      histo[his].push_back(varhisto);
    }

    //// Plotting lumi-weighted distributions in histo[0], and then area-normalized in histo[1] ///
    leg.Clear();
    nentries.resize(0);
    variable = vars[var].varname;
    float maxhisto(-999);
    for(unsigned sam(0); sam < vars[var].samples.size(); sam++){
      int isam = vars[var].samples[sam];
      bool isSig = Samples[isam].label.Contains("W");

      totCut = luminosity+"*weight*("+vars[var].cuts+"&&"+Samples[isam].cut+")"; 
      chain[isam]->Project(histo[0][var][sam]->GetName(), variable, totCut);
      histo[0][var][sam]->SetBinContent(vars[var].nbins,
					histo[0][var][sam]->GetBinContent(vars[var].nbins)+
					histo[0][var][sam]->GetBinContent(vars[var].nbins+1));
      nentries.push_back(histo[0][var][sam]->Integral(1,vars[var].nbins));
      histo[0][var][sam]->SetXTitle(vars[var].title);
      ytitle = "Entries for "+luminosity+" fb^{-1}";
      if(vars[var].unit!="") {
	int digits(0);
	float binwidth((vars[var].maxx-vars[var].minx)/static_cast<float>(vars[var].nbins));
	if(binwidth<1) digits = 1;
	ytitle += ("/("+RoundNumber(binwidth,digits) +" "+vars[var].unit+")");
      }
      histo[0][var][sam]->SetYTitle(ytitle);
      // Cloning histos for later
      for(int bin(0); bin<=histo[0][var][sam]->GetNbinsX()+1; bin++)
	histo[1][var][sam]->SetBinContent(bin, histo[0][var][sam]->GetBinContent(bin));

      if(!isSig){ // Adding previous bkg histos
	for(int bsam(sam-1); bsam >= 0; bsam--){
	  if(!Samples[vars[var].samples[bsam]].file.Contains("T1tttt")){
	    histo[0][var][sam]->Add(histo[0][var][bsam]);
	    break;
	  }
	}
	histo[0][var][sam]->SetFillColor(Samples[isam].color);
	histo[0][var][sam]->SetFillStyle(1001);
	histo[0][var][sam]->SetLineColor(1);
	histo[0][var][sam]->SetLineWidth(1);
      } else {
	histo[0][var][sam]->SetLineColor(Samples[isam].color);
	histo[0][var][sam]->SetLineStyle(Samples[isam].style);
	histo[0][var][sam]->SetLineWidth(3);
      }
      if(maxhisto < histo[0][var][sam]->GetMaximum()) maxhisto = histo[0][var][sam]->GetMaximum();
    } // First loop over samples
    int firstplotted(-1);
    for(int sam(vars[var].samples.size()-1); sam >= 0; sam--){
      int isam = vars[var].samples[sam];
      leghisto = Samples[isam].label+" [N = " + RoundNumber(nentries[sam],0) + "]";
      leg.AddEntry(histo[0][var][sam], leghisto);
      bool isSig = Samples[isam].label.Contains("W");
      if(!isSig){
	if(firstplotted < 0) {
	  histo[0][var][sam]->Draw();
	  firstplotted = sam;
	} else histo[0][var][sam]->Draw("same");
      }
    }
    for(int sam(vars[var].samples.size()-1); sam >= 0; sam--){
      int isam = vars[var].samples[sam];
      bool isSig = Samples[isam].label.Contains("W");
      if(isSig) histo[0][var][sam]->Draw("same");
    }
    legH = legSingle*vars[var].samples.size(); leg.SetY1NDC(legY-legH);
    leg.Draw(); 
    if(histo[0][var][firstplotted]->GetMinimum() > minLog) histo[0][var][firstplotted]->SetMinimum(minLog);
    histo[0][var][firstplotted]->SetMinimum(minLog);
    histo[0][var][firstplotted]->SetMaximum(maxhisto*maxLog);
    if(vars[var].cut>0) line.DrawLine(vars[var].cut, 0, vars[var].cut, maxhisto*maxLog);
    can.SetLogy(1);
    pname = "eps/log_lumi_"+vars[var].tag+".eps";
    can.SaveAs(pname);
    histo[0][var][firstplotted]->SetMinimum(0);
    histo[0][var][firstplotted]->SetMaximum(maxhisto*1.1);
    can.SetLogy(0);
    pname = "eps/lumi_"+vars[var].tag+".eps";
    can.SaveAs(pname);

    //////////// Plotting area-normalized distributions ////////////
    leg.Clear(); maxhisto = -999;
    for(unsigned sam(0); sam < vars[var].samples.size(); sam++){
      int isam = vars[var].samples[sam];
      histo[1][var][sam]->SetLineColor(Samples[isam].color);
      histo[1][var][sam]->SetLineStyle(Samples[isam].style);
      histo[1][var][sam]->SetLineWidth(3);
      if(nentries[sam]) histo[1][var][sam]->Scale(100./nentries[sam]);
      if(maxhisto < histo[1][var][sam]->GetMaximum()) maxhisto = histo[1][var][sam]->GetMaximum();
      if(sam==0){
	histo[1][var][sam]->SetXTitle(vars[var].title);
	histo[1][var][sam]->SetYTitle("Entries (%)");
	histo[1][var][sam]->Draw();
      } else histo[1][var][sam]->Draw("same");
      leghisto = Samples[isam].label+" [#mu = ";
      int digits(1);
      leghisto += RoundNumber(histo[1][var][sam]->GetMean(),digits) + "]";
      if(vars[var].cut>0){
	int bincut = histo[1][var][sam]->FindBin(vars[var].cut);
	leghisto = Samples[isam].label+" [keeps ";
	leghisto += RoundNumber(histo[1][var][sam]->Integral(1,bincut-1)*100,digits,
				histo[1][var][sam]->Integral()) + "%]";
	
      } // Legend label for cut
      leg.AddEntry(histo[1][var][sam], leghisto);
    } // Loop over samples
    leg.Draw(); 
    if(vars[var].cut>0) line.DrawLine(vars[var].cut, 0, vars[var].cut, maxhisto*1.1);
    histo[1][var][0]->SetMaximum(maxhisto*1.1);
    can.SetLogy(0);
    pname = "eps/shapes_"+vars[var].tag+".eps";
    can.SaveAs(pname);
    histo[1][var][0]->SetMaximum(maxhisto*maxLog);
    can.SetLogy(1);
    pname = "eps/log_shapes_"+vars[var].tag+".eps";
    can.SaveAs(pname);
  }// Loop over variables

  for(unsigned his(0); his < 2; his++){
    for(unsigned var(0); var<vars.size(); var++){
      for(unsigned sam(0); sam < vars[var].samples.size(); sam++)
	if(histo[his][var][sam]) histo[his][var][sam]->Delete();
    }
  }
}

