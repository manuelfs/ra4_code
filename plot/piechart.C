// plot_distribution: Macro that plots variables both lumi weighted and normalized to the same area.

#define INT_ROOT
#include "inc/styles.hpp"
#include "src/styles.cpp"
#include "inc/utilities.hpp"
#include "src/utilities.cpp"

#include "TPie.h"
#include "TChain.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TLine.h"
#include "TString.h"

using namespace std;
using std::cout;
using std::endl;

class sfeats {
public:
  sfeats(TString icut, TString iname, int icolor){
    cut = icut; name = iname; color = icolor;
  }
  TString cut, name;
  int color;
};

void piechart() { 
  styles style("Standard"); style.setDefaultStyle();
  gStyle->SetTextSize(0.05);            // Set global text size
  gStyle->SetTitleSize(0.05);     // Set the 2 axes title size
  gStyle->SetLabelSize(0.05);     // Set the 2 axes label size
  gStyle->SetCanvasDefW(1400);

  TCanvas can;
  TString pname, Hname = "histo", totCut, tag, title;
  TH1F histo(Hname, "",100, 0, 10000);

  const char *labels[100];

  TChain chain("tree");
  chain.Add("archive/ra4skim/*TT*");

  vector<TString> cuts;
  cuts.push_back("nleps==1&&ht>750&&met>250&&njets[1]>=6&&nbl[1]>=2");
  cuts.push_back("nleps==1&&ht>750&&met>250&&njets[1]>=6&&nbl[1]>=2&&mt>100");
  cuts.push_back("nleps==1&&ht>750&&met>250&&njets[1]>=6&&nbl[1]>=2&&dphi_wlep>1");
  cuts.push_back("nleps==1&&ht>750&&met>500&&njets[1]>=6&&nbl[1]>=2&&mt>100");
  cuts.push_back("nleps==1&&ht>750&&met>500&&njets[1]>=6&&nbl[1]>=2&&dphi_wlep>1");
  vector<sfeats> comp;
  comp.push_back(sfeats("Sum$(abs(mc_id)==11&&abs(mc_momid)==24||abs(mc_id)==13&&abs(mc_momid)==24||abs(mc_id)==15&&abs(mc_momid)==24)==0","Hadronic",1));
  comp.push_back(sfeats("Sum$(abs(mc_id)==11&&abs(mc_momid)==24||abs(mc_id)==13&&abs(mc_momid)==24)==1&&Sum$(abs(mc_id)==15&&abs(mc_momid)==24)==1","1 lep, 1 #tau",4));
  comp.push_back(sfeats("Sum$(abs(mc_id)==11&&abs(mc_momid)==24||abs(mc_id)==13&&abs(mc_momid)==24)==1&&Sum$(abs(mc_id)==15&&abs(mc_momid)==24)==0","1 lep, hadr",28));
  comp.push_back(sfeats("Sum$(abs(mc_id)==11&&abs(mc_momid)==24||abs(mc_id)==13&&abs(mc_momid)==24)==0&&Sum$(abs(mc_id)==15&&abs(mc_momid)==24)==1","1 #tau, hadr",kYellow));
  comp.push_back(sfeats("Sum$(abs(mc_id)==11&&abs(mc_momid)==24||abs(mc_id)==13&&abs(mc_momid)==24)==2","2 lep",2));
  comp.push_back(sfeats("Sum$(abs(mc_id)==15&&abs(mc_momid)==24)==2","2 #tau",kCyan+2));

  for(unsigned cut(0); cut<cuts.size(); cut++){
    tag = cuts[cut];
    tag.ReplaceAll(".",""); 
    tag.ReplaceAll("(",""); tag.ReplaceAll("$","");  tag.ReplaceAll(")",""); 
    tag.ReplaceAll("[",""); tag.ReplaceAll("]",""); 
    tag.ReplaceAll("/","_"); tag.ReplaceAll("*",""); tag.ReplaceAll("&&","_");
    tag.ReplaceAll(">",""); tag.ReplaceAll("<",""); tag.ReplaceAll("=","");
    tag.ReplaceAll("+",""); 
    title = cuts[cut];
    title.ReplaceAll("njets[1]","n_{jets}");
    title.ReplaceAll(">=", " #geq "); title.ReplaceAll(">", " > "); title.ReplaceAll("&&", ", "); 
    title.ReplaceAll("met", "MET"); title.ReplaceAll("ht", "H_{T}");  title.ReplaceAll("mt", "m_{T}"); 
    title.ReplaceAll("nleps==1", "1 lepton");  title.ReplaceAll("nbm[1]","n_{b}");
    title.ReplaceAll("nbl[1]","n_{b,l}"); title.ReplaceAll("dphi_wlep", "#Delta#phi");
    
    vector<float> yields;
    //vector<string> labels;
    vector<int> colors;
    for(unsigned ind(0); ind<comp.size(); ind++){
      totCut = "weight*("+cuts[cut]+"&&"+comp[ind].cut+")";
      chain.Project(Hname, "met", totCut);
      yields.push_back(histo.Integral(0,101));
      labels[ind] = static_cast<const char*>(comp[ind].name.Data());
      colors.push_back(comp[ind].color);
    }
    TPie pie("pie1", title, yields.size(), &yields[0]);
    pie.SetFillColors(&colors[0]);
    pie.SetLabels(labels);
    pie.SetLabelFormat("%txt (%perc)");
    pie.SetRadius(0.3);
    pie.Draw("3d");
    pname = "eps/ttpiechart_"+tag+".root";
    pie.SaveAs(pname);
    pname = "eps/ttpiechart_"+tag+".eps";
    can.SaveAs(pname);
  }


}

