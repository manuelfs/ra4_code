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

void plot_distribution(TString luminosity="5") { 
  styles style("Standard"); style.setDefaultStyle();
  vector<hfeats> vars;
  TCanvas can;

  // Reading ntuples
  vector<TChain *> chain;
  vector<sfeats> Samples; 
  Samples.push_back(sfeats("archive/ra4skim/*T1tttt*1200_*", "T1tttt(1200,800)", 28));
  Samples.push_back(sfeats("archive/ra4skim/*T1tttt*1500_*", "T1tttt(1500,100)", kMagenta+3, 2));
  Samples.push_back(sfeats("archive/ra4skim/*QCD*", "QCD", 4));
  Samples.push_back(sfeats("archive/ra4skim/*TTJet*", "t#bar{t}, 1 l", 2,1,"(mc_type&0x0F00)<=0x100"));
  Samples.push_back(sfeats("archive/ra4skim/*WJets*", "W + jets", kYellow));
  Samples.push_back(sfeats("archive/ra4skim/*_T*channel*", "Single top", 8));
  Samples.push_back(sfeats("archive/ra4skim/*_DY*", "Drell-Yan", kCyan+2));
  Samples.push_back(sfeats("archive/ra4skim/*TTJet*", "t#bar{t}, 2 l", kBlue-3,1,"(mc_type&0x0F00)>=0x200"));
  for(unsigned sam(0); sam < Samples.size(); sam++){
    chain.push_back(new TChain("tree"));
    chain[sam]->Add(Samples[sam].file);
  }

  vector<int> allsamples;
  allsamples.push_back(1); //(1500,100)
  allsamples.push_back(0); //(1200,800)
  allsamples.push_back(6); // Drell-Yan
  allsamples.push_back(5); // Single top
  //allsamples.push_back(2); // QCD
  allsamples.push_back(7); // tt, 2l
  allsamples.push_back(3); // tt, 1l
  allsamples.push_back(4); // Wjets

  vector<int> bkgsamples;
  bkgsamples.push_back(6); // Drell-Yan
  bkgsamples.push_back(5); // Single top
  bkgsamples.push_back(2); // QCD
  bkgsamples.push_back(3); // tt
  bkgsamples.push_back(4); // Wjets

  // vars.push_back(hfeats("mt",40,0,800, allsamples, "m_{T} (GeV)",
  // 			"nleps==1&&ht>750&&met>250&&nbm>=2&&njets>=6",100));

  // vars.push_back(hfeats("mt2_max",40,0,1000, allsamples, "m^{b}_{T2} (GeV)",
  // 			"nleps==1&&ht>750&&met>250&&nbm>=2&&njets>=6&&mt>100",200));
  // vars.push_back(hfeats("mt2w_highCSV",41,-25,1000, allsamples, "m^{W, CSV}_{T2} (GeV)",
  // 			"nleps==1&&ht>750&&met>250&&nbm>=2&&njets>=6&&mt>100",200));
  // vars.push_back(hfeats("mbl_subleading",40,0,1000, allsamples, "m_{bl} (GeV)",
  // 			"nleps==1&&ht>750&&met>250&&nbm>=2&&njets>=6&&mt>100",200));

  // vars.push_back(hfeats("njets",16,-0.5,15.5, allsamples, "Number of 40 GeV jets",
  // 			"nleps==1&&ht>750&&met>250&&nbl>=2&&mt>100",5.5));
  vars.push_back(hfeats("met",50,0,1000, allsamples, "MET (GeV)","nleps==1&&ht>750&&njets>=7&&nbl>=2",250));
  vars.push_back(hfeats("met",50,0,1000, allsamples, "MET (GeV)","nleps==1&&ht>750&&njets>=7&&nbl>=2&&mt>100",250));



  // Variables to plot
  // vars.push_back(hfeats("ht",50,0,2500, allsamples, "H_{T} (GeV)","nleps==1",750));
  // vars.push_back(hfeats("met",50,0,750, allsamples, "MET (GeV)","nleps==1",250));
  // vars.push_back(hfeats("ht",50,0,2500, allsamples, "H_{T} (GeV)","nleps==1&&met>250",750));
  // vars.push_back(hfeats("met",50,0,750, allsamples, "MET (GeV)","nleps==1&&ht>750",250));
  // vars.push_back(hfeats("njets",16,-0.5,15.5, allsamples, "Number of 40 GeV jets","nleps==1&&ht>750&&met>250",5.5));
  // vars.push_back(hfeats("nbm",7,-0.5,6.5, allsamples, "Number of 40 GeV b-tags (CSVM)",
  // 			"nleps==1&&ht>750&&met>250",1.5));
  // vars.push_back(hfeats("mt",40,0,800, allsamples, "m_{T} (GeV)",
  // 			"nleps==1&&ht>750&&met>250&&nbm>=2&&njets>=6",100));
  // vars.push_back(hfeats("dphi_wlep",32,0,3.2, allsamples, "#Delta#phi(W,lep) (rad)",
  // 			"nleps==1&&ht>750&&met>250&&nbm>=2&&njets>=6",1));
  // vars.push_back(hfeats("mt",40,0,800, allsamples, "m_{T} (GeV)",
  // 			"nleps==1&&ht>750&&met>500&&nbm>=2&&njets>=6",100));
  // vars.push_back(hfeats("dphi_wlep",32,0,3.2, allsamples, "#Delta#phi(W,lep) (rad)",
  // 			"nleps==1&&ht>750&&met>500&&nbm>=2&&njets>=6",1));

  //////////// Robert Schoefbeck ///////////
  //vars.push_back(hfeats("mt",8,0,800, bkgsamples, "m_{T} (GeV)","nvmus==1&&nmus==1&&nvels==0&&ht>750&&met>250&&nbl==0&&njets>=4"));

  //vars.push_back(hfeats("mt",40,0,400, bkgsamples, "m_{T} (GeV)","nleps==1&&ht>750&&met>350"));
  //vars.push_back(hfeats("mt",40,0,400, bkgsamples, "m_{T} (GeV)","nleps==1&&ht>750&&met>350&&nbl==0&&njets>=4"));

  float minLog = 0.04, maxLog = 10;
  double legX = 0.65, legY = 0.92, legSingle = 0.049;
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
      bool isSig = Samples[isam].file.Contains("T1tttt");

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
      bool isSig = Samples[isam].file.Contains("T1tttt");
      if(!isSig){
	if(firstplotted < 0) {
	  histo[0][var][sam]->Draw();
	  firstplotted = sam;
	} else histo[0][var][sam]->Draw("same");
      }
    }
    for(int sam(vars[var].samples.size()-1); sam >= 0; sam--){
      int isam = vars[var].samples[sam];
      bool isSig = Samples[isam].file.Contains("T1tttt");
      if(isSig) histo[0][var][sam]->Draw("same");
    }
    legH = legSingle*vars[var].samples.size(); leg.SetY1NDC(legY-legH);
    leg.Draw(); 
    if(histo[0][var][firstplotted]->GetMinimum() > minLog) histo[0][var][firstplotted]->SetMinimum(minLog);
    histo[0][var][firstplotted]->SetMinimum(minLog);
    histo[0][var][firstplotted]->SetMaximum(maxhisto*maxLog);
    if(variable=="mt" && var==vars.size()-1) {
      histo[0][var][firstplotted]->SetMinimum(0.2);
      histo[0][var][firstplotted]->SetMaximum(maxhisto*2);
    }
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

