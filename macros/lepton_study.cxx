#include "lepton_study.hpp"

#include <vector>
#include <string>
#include <stdexcept>

#include "TH2D.h"
#include "TH1D.h"
#include "TFile.h"
#include "TChain.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TMarker.h"

#include "utilities.hpp"
#include "styles.hpp"

using namespace std;

int main(){
  styles style("Standard");
  style.setDefaultStyle();

  TChain ttbar("tree");
  ttbar.Add("archive/ra4skim/small_TT_*batch1.root");
  TChain t1tttt("tree");
  t1tttt.Add("archive/ra4skim/small*SMS*T1tttt*PU20*.root");

  DrawROC(ttbar, t1tttt, "el");
  DrawROC(ttbar, t1tttt, "mu");

  // DrawROC(ttbar, t1tttt, "el");
  // DrawROC(ttbar, t1tttt, "el",1);
  // DrawROC(ttbar, t1tttt, "el",2);
  // DrawROC(ttbar, t1tttt, "el",3);
  // DrawROC(ttbar, t1tttt, "el",4);
  // DrawROC(ttbar, t1tttt, "mu");
  // DrawROC(ttbar, t1tttt, "mu",1);
  // DrawROC(ttbar, t1tttt, "mu",2);
  // DrawROC(ttbar, t1tttt, "mu",3);
  // DrawROC(ttbar, t1tttt, "mu",4);

  //DrawScat(chain, "ttbar", "el", true);
  //DrawScat(chain, "ttbar", "el", false);
  //DrawScat(chain, "ttbar", "mu", true);
  //DrawScat(chain, "ttbar", "mu", false);
}

void DrawROC(TChain &ttbar, TChain &t1tttt, const string &lep, int pt_bin){
  const unsigned nbins = 1000;
  const double reliso_low = 0.0, reliso_high = 5.0;
  const double ptrel_low = 0.0, ptrel_high = 100.0;
  const double ptrel_25_low = 0.0, ptrel_25_high = 100.0;

  TH1D reliso_good("reliso_good","", nbins, reliso_low, reliso_high);
  TH1D reliso_bad("reliso_bad","", nbins, reliso_low, reliso_high);
  TH1D ptrel_good("ptrel_good","",nbins, ptrel_low, ptrel_high);
  TH1D ptrel_bad("ptrel_bad","",nbins, ptrel_low, ptrel_high);
  TH1D ptrel_25_good("ptrel_25_good","",nbins, ptrel_25_low, ptrel_25_high);
  TH1D ptrel_25_bad("ptrel_25_bad","",nbins, ptrel_25_low, ptrel_25_high);
  TH1D miniso_good("miniso_good","",nbins, reliso_low, reliso_high);
  TH1D miniso_bad("miniso_bad","",nbins, reliso_low, reliso_high);
  TH1D miniso_ch_good("miniso_ch_good","",nbins, reliso_low, reliso_high);
  TH1D miniso_ch_bad("miniso_ch_bad","",nbins, reliso_low, reliso_high);

  string full_lep = "Lepton";
  if(lep=="mu"){
    full_lep = "Muon";
  }else if(lep=="el"){
    full_lep = "Electron";
  }

  string pt_cut, pt_title, pt_file;
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
  }

  string good_denom_cut = lep+"s_tru_tm&&"+lep+"s_sigid&&"+pt_cut;
  string bad_denom_cut = "!"+good_denom_cut;
  t1tttt.Project("reliso_good",
		(lep+"s_reliso").c_str(),
		good_denom_cut.c_str());
  ttbar.Project("reliso_bad",
		(lep+"s_reliso").c_str(),
		bad_denom_cut.c_str());
  t1tttt.Project("ptrel_good",
		(lep+"s_ptrel+("+lep+"s_ptrel<0||"+lep+"s_mindr>0.4)*9999.").c_str(),
		good_denom_cut.c_str());
  ttbar.Project("ptrel_bad",
		(lep+"s_ptrel+("+lep+"s_ptrel<0||"+lep+"s_mindr>0.4)*9999.").c_str(),
		bad_denom_cut.c_str());
  t1tttt.Project("ptrel_25_good",
		(lep+"s_ptrel_25+("+lep+"s_ptrel_25<0||"+lep+"s_mindr_25>0.4)*9999.").c_str(),
		good_denom_cut.c_str());
  ttbar.Project("ptrel_25_bad",
		(lep+"s_ptrel_25+("+lep+"s_ptrel_25<0||"+lep+"s_mindr_25>0.4)*9999.").c_str(),
		bad_denom_cut.c_str());
  t1tttt.Project("miniso_good",
		(lep+"s_miniso_tr15").c_str(),
		good_denom_cut.c_str());
  ttbar.Project("miniso_bad",
		(lep+"s_miniso_tr15").c_str(),
		bad_denom_cut.c_str());
  t1tttt.Project("miniso_ch_good",
		(lep+"s_miniso_tr15_ch").c_str(),
		good_denom_cut.c_str());
  ttbar.Project("miniso_ch_bad",
		(lep+"s_miniso_tr15_ch").c_str(),
		bad_denom_cut.c_str());
		
  double good_count, bad_count ,junk;
  get_count_and_uncertainty(t1tttt, good_denom_cut, good_count, junk);
  get_count_and_uncertainty(ttbar, bad_denom_cut, bad_count, junk);

  double good_num, bad_num;
  if(lep=="el"){
    get_count_and_uncertainty(t1tttt,
			      (good_denom_cut+"&&((els_eta<=1.479&&els_reliso<0.2179)||els_reliso<0.254)"),
			      good_num, junk);
    get_count_and_uncertainty(ttbar,
			      (bad_denom_cut+"&&!((els_eta<=1.479&&els_reliso<0.2179)||els_reliso<0.254)"),
			      bad_num, junk);
  }else{
    get_count_and_uncertainty(t1tttt,
			      (good_denom_cut+"&&(mus_reliso<0.12)"),
			      good_num, junk);
    get_count_and_uncertainty(ttbar,
			      (bad_denom_cut+"&&!(mus_reliso<0.12)"),
			      bad_num, junk);
  }
  TMarker marker(good_num/good_count, bad_num/bad_count, 29);
  marker.SetMarkerSize(5);

  TGraph reliso = MakeROC(reliso_good, reliso_bad, true, good_count, bad_count);
  TGraph ptrel = MakeROC(ptrel_good, ptrel_bad, false, good_count, bad_count);
  TGraph ptrel_25 = MakeROC(ptrel_25_good, ptrel_25_bad, false, good_count, bad_count);
  TGraph miniso = MakeROC(miniso_good, miniso_bad, true, good_count, bad_count);
  TGraph miniso_ch = MakeROC(miniso_ch_good, miniso_ch_bad, true, good_count, bad_count);

  reliso.SetLineColor(1); reliso.SetLineWidth(4);
  ptrel.SetLineColor(2); ptrel.SetLineWidth(4);
  ptrel_25.SetLineColor(3); ptrel_25.SetLineWidth(4);
  miniso.SetLineColor(4); miniso.SetLineWidth(4);
  miniso_ch.SetLineColor(6); miniso_ch.SetLineWidth(4);

  TH1D dumb("","",1,0.5,1.0);
  dumb.SetTitle((pt_title+";Truth Matched Prompt "
		 +full_lep
		 +" Efficiency;Non-Prompt "
		 +full_lep
		 +" Rejection Rate").c_str());
  dumb.SetMinimum(0.0);
  dumb.SetMaximum(1.0);

  TCanvas canvas;
  dumb.Draw();
  reliso.Draw("lsame");
  ptrel.Draw("lsame");
  ptrel_25.Draw("lsame");
  miniso.Draw("lsame");
  miniso_ch.Draw("lsame");
  marker.Draw("same");

  TLegend leg(0.1,0.12,0.25,0.62);
  leg.SetFillStyle(0);
  leg.SetFillColor(0);
  leg.SetBorderSize(0);
  leg.SetTextSize(0.05);
  leg.AddEntry(&reliso, "Rel. Iso.", "l");
  leg.AddEntry(&miniso, "Mini Iso. Tr., kt = 15 GeV", "l");
  leg.AddEntry(&miniso_ch, "Mini Iso. Tr., kt = 15 GeV (ch. only)", "l");
  leg.AddEntry(&ptrel, "p_{T}^{rel} || #Delta R>0.4 || Isolated", "l");
  leg.AddEntry(&ptrel_25, "p_{T}^{rel}(25 GeV jets) || #Delta R>0.4 || Isolated", "l");
  leg.Draw("same");
  canvas.Print(("eps/roc_"+lep+"_"+pt_file+".eps").c_str());
}

TGraph MakeROC(TH1D &good, TH1D &bad, const bool less_is_better,
	       double good_count, double bad_count){
  const int nbins = good.GetNbinsX();
  if(bad.GetNbinsX() != nbins) throw logic_error("Mismatched number of bins");

  TGraph graph(0);
  const double good_tot = (good_count<=0.0)?good.Integral(0, nbins+1):good_count;
  const double bad_tot = (bad_count<=0.0)?bad.Integral(0, nbins+1):bad_count;
  if(less_is_better){
    for(int bin = nbins+1; bin>=0; --bin){
      const double good_pass = good.Integral(0, bin);
      const double bad_pass = bad.Integral(0, bin);
      const double x = good_pass/good_tot;
      const double y = 1.0-bad_pass/bad_tot;
      AddPoint(graph, x, y);
    }
  }else{
    for(int bin = 0; bin<=nbins+1; ++bin){
      const double good_pass = good.Integral(bin,nbins+1);
      const double bad_pass = bad.Integral(bin, nbins+1);
      const double x = good_pass/good_tot;
      const double y = 1.0-bad_pass/bad_tot;
      AddPoint(graph, x, y);
    }
  }

  return graph;
}

void DrawScat(TChain &chain, const string &sample,
	      const string &lep, const bool truth_match){
  const unsigned reliso_nbins = 100, ptrel_nbins = 100;
  const double reliso_low = 0.0, reliso_high = 2.0;
  const double ptrel_low = 0.0, ptrel_high = 50.0;

  string title_samp = "";
  if(sample=="susy") title_samp = "T1tttt(1200,800)";
  else if(sample=="ttbar") title_samp = "ttbar";

  string title_lep = "Lepton";
  if(lep=="mu") title_lep = "Muon";
  else if(lep=="el") title_lep = "Electron";

  string title_truth_match = truth_match?"Truth-Matched":"Anti-Truth-Matched";

  string title = title_samp+" "+title_truth_match+" "+title_lep;

  TH2D scat("scat", (title+";Rel. Iso.;p_{T}^{rel}").c_str(),
	    reliso_nbins, reliso_low, reliso_high,
	    ptrel_nbins, ptrel_low, ptrel_high);

  chain.Project("scat", (lep+"s_ptrel:"+lep+"s_reliso").c_str(),
		((truth_match?"":"!")+lep+"s_tru_tm").c_str());

  TCanvas canvas;
  scat.Draw();
  canvas.Print(("eps/scat_"
		+sample+"_"+lep+"_"+(truth_match?"good":"bad")
		+"_ptrel_vs_reliso.eps").c_str());
}
