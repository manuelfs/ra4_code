#include <vector>

#include "TH2D.h"
#include "TCanvas.h"
#include "TChain.h"

#include "styles.hpp"

using namespace std;

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

void DrawScat(TChain &chain,
	      const string &var_x, size_t nbins_x, double low_x, double high_x,
	      const string &var_y, size_t nbins_y, double low_y, double high_y,
	      const string &cut, int pt_bin,
	      const string &out_file){
  string lep = (var_x.find("mus")==std::string::npos)?"el":"mu";
  TCanvas c;
  string pt_title, pt_cut, pt_file;
  switch(pt_bin){
  default:
  case 0:
    pt_cut = lep+"s_pt>20";
    pt_title = "p_{T}^{"+lep+"}>20";
    pt_file = "20_inf";
    break;
  case 1:
    pt_cut = lep+"s_pt>20&&"+lep+"s_pt<50";
    pt_title = "20<p_{T}^{"+lep+"}<50";
    pt_file = "20_50";
    break;
  case 2:
    pt_cut = lep+"s_pt>50&&"+lep+"s_pt<100";
    pt_title = "50<p_{T}^{"+lep+"}<100";
    pt_file = "50_100";
    break;
  case 3:
    pt_cut = lep+"s_pt>100&&"+lep+"s_pt<200";
    pt_title = "100<p_{T}^{"+lep+"}<200";
    pt_file = "100_200";
    break;
  case 4:
    pt_cut = lep+"s_pt>200";
    pt_title = "p_{T}^{"+lep+"}>200";
    pt_file = "200_inf";
    break;
  case 5:
    pt_cut = lep+"s_pt>100";
    pt_title = "p_{T}^{"+lep+"}>100";
    pt_file = "100_inf";
    break;
  }

  TH2D h("out",(pt_title+";"+var_x+";"+var_y).c_str(),
	 nbins_x, low_x, high_x,
	 nbins_y, low_y, high_y);
  
  chain.Project("out",
		(var_y+":"+var_x).c_str(),
		("("+cut+")&&("+pt_cut+")").c_str());

  h.Draw("scat");
  c.Print((out_file+"_"+pt_file+"_scat.eps").c_str());
  h.Draw("colz");
  c.Print((out_file+"_"+pt_file+"_colz.eps").c_str());
}

int main(){
  styles style("Standard");
  style.setDefaultStyle();

  TChain chain("tree");
  chain.Add("archive/ra4skim/*TT_*.root");

  for(int ptbin = 0; ptbin <= 5; ++ptbin){
    DrawScat(chain,
	     "mus_reliso", 20, 0.0, 1.0,
	     "mus_ptrel", 25, 0.0, 50.0,
	     "mus_ptrel>=0.0&&mus_tru_tm", ptbin,
	     "eps/scat_mus_ptrel_mus_reliso_tm");
    DrawScat(chain,
	     "mus_reliso", 20, 0.0, 1.0,
	     "mus_ptrel", 25, 0.0, 50.0,
	     "mus_ptrel>=0.0&&!mus_tru_tm", ptbin,
	     "eps/scat_mus_ptrel_mus_reliso_nottm");
    DrawScat(chain,
	     "mus_reliso", 20, 0.0, 1.0,
	     "mus_ptrel_25", 25, 0.0, 50.0,
	     "mus_ptrel_25>=0.0&&mus_tru_tm", ptbin,
	     "eps/scat_mus_ptrel_25_mus_reliso_tm");
    DrawScat(chain,
	     "mus_reliso", 20, 0.0, 1.0,
	     "mus_ptrel_25", 25, 0.0, 50.0,
	     "mus_ptrel_25>=0.0&&!mus_tru_tm", ptbin,
	     "eps/scat_mus_ptrel_25_mus_reliso_nottm");
    DrawScat(chain,
	     "mus_reliso", 20, 0.0, 1.0,
	     "mus_miniso/mus_pt", 20, 0.0, 1.0,
	     "mus_tru_tm", ptbin,
	     "eps/scat_mus_miniso_mus_reliso_tm");
    DrawScat(chain,
	     "mus_reliso", 20, 0.0, 1.0,
	     "mus_miniso/mus_pt", 20, 0.0, 1.0,
	     "!mus_tru_tm", ptbin,
	     "eps/scat_mus_miniso_mus_reliso_nottm");
    DrawScat(chain,
	     "mus_reliso", 20, 0.0, 1.0,
	     "mus_miniso_ch/mus_pt", 20, 0.0, 1.0,
	     "mus_tru_tm", ptbin,
	     "eps/scat_mus_miniso_ch_mus_reliso_tm");
    DrawScat(chain,
	     "mus_reliso", 20, 0.0, 1.0,
	     "mus_miniso_ch/mus_pt", 20, 0.0, 1.0,
	     "!mus_tru_tm", ptbin,
	     "eps/scat_mus_miniso_ch_mus_reliso_nottm");
    DrawScat(chain,
	     "els_reliso", 20, 0.0, 1.0,
	     "els_ptrel", 25, 0.0, 50.0,
	     "els_ptrel>=0.0&&els_tru_tm", ptbin,
	     "eps/scat_els_ptrel_els_reliso_tm");
    DrawScat(chain,
	     "els_reliso", 20, 0.0, 1.0,
	     "els_ptrel", 25, 0.0, 50.0,
	     "els_ptrel>=0.0&&!els_tru_tm", ptbin,
	     "eps/scat_els_ptrel_els_reliso_nottm");
    DrawScat(chain,
	     "els_reliso", 20, 0.0, 1.0,
	     "els_ptrel_25", 25, 0.0, 50.0,
	     "els_ptrel_25>=0.0&&els_tru_tm", ptbin,
	     "eps/scat_els_ptrel_25_els_reliso_tm");
    DrawScat(chain,
	     "els_reliso", 20, 0.0, 1.0,
	     "els_ptrel_25", 25, 0.0, 50.0,
	     "els_ptrel_25>=0.0&&!els_tru_tm", ptbin,
	     "eps/scat_els_ptrel_25_els_reliso_nottm");
    DrawScat(chain,
	     "els_reliso", 20, 0.0, 1.0,
	     "els_miniso/els_pt", 20, 0.0, 1.0,
	     "els_tru_tm", ptbin,
	     "eps/scat_els_miniso_els_reliso_tm");
    DrawScat(chain,
	     "els_reliso", 20, 0.0, 1.0,
	     "els_miniso/els_pt", 20, 0.0, 1.0,
	     "!els_tru_tm", ptbin,
	     "eps/scat_els_miniso_els_reliso_nottm");
    DrawScat(chain,
	     "els_reliso", 20, 0.0, 1.0,
	     "els_miniso_ch/els_pt", 20, 0.0, 1.0,
	     "els_tru_tm", ptbin,
	     "eps/scat_els_miniso_ch_els_reliso_tm");
    DrawScat(chain,
	     "els_reliso", 20, 0.0, 1.0,
	     "els_miniso_ch/els_pt", 20, 0.0, 1.0,
	     "!els_tru_tm", ptbin,
	     "eps/scat_els_miniso_ch_els_reliso_nottm");
  }  
}
