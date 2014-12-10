#include "lepton_study.hpp"

#include <string>
#include <stdexcept>

#include "TH2D.h"
#include "TH1D.h"
#include "TFile.h"
#include "TChain.h"
#include "TCanvas.h"
#include "TLegend.h"

#include "utilities.hpp"
#include "styles.hpp"

int main(){
  styles style("Standard");
  style.setDefaultStyle();

  TChain ttbar("tree"), susy("tree");
  ttbar.Add("archive/20141125/*TTJet*.root/tree");
  susy.Add("archive/20141125/small_SMS-T1tttt_2J_mGl-1200_mLSP-800_Tune4C_13TeV-madgraph-tauola-Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2191_v75.root/tree");

  DrawROC(ttbar, susy, "el");
  DrawROC(ttbar, susy, "mu");

  DrawScat(ttbar, "ttbar", "el", true);
  DrawScat(ttbar, "ttbar", "el", false);
  DrawScat(ttbar, "ttbar", "mu", true);
  DrawScat(ttbar, "ttbar", "mu", false);
  DrawScat(susy, "susy", "el", true);
  DrawScat(susy, "susy", "el", false);
  DrawScat(susy, "susy", "mu", true);
  DrawScat(susy, "susy", "mu", false);
}

void DrawROC(TChain &ttbar, TChain &susy, const std::string &lep){
  const unsigned nbins = 100;
  const double reliso_low = 0.0, reliso_high = 5.0;
  const double ptrel_low = 0.0, ptrel_high = 100.0;
  TH1D ttbar_ptrel_good("ttbar_ptrel_good","",nbins, ptrel_low, ptrel_high);
  TH1D ttbar_ptrel_bad("ttbar_ptrel_bad","",nbins, ptrel_low, ptrel_high);
  TH1D ttbar_reliso_good("ttbar_reliso_good","",nbins, reliso_low, reliso_high);
  TH1D ttbar_reliso_bad("ttbar_reliso_bad","",nbins, reliso_low, reliso_high);
  TH1D susy_ptrel_good("susy_ptrel_good","",nbins, ptrel_low, ptrel_high);
  TH1D susy_ptrel_bad("susy_ptrel_bad","",nbins, ptrel_low, ptrel_high);
  TH1D susy_reliso_good("susy_reliso_good","",nbins, reliso_low, reliso_high);
  TH1D susy_reliso_bad("susy_reliso_bad","",nbins, reliso_low, reliso_high);

  ttbar.Project("ttbar_ptrel_good",(lep+"s_ptrel").c_str(),(lep+"s_tru_tm").c_str());
  ttbar.Project("ttbar_ptrel_bad",(lep+"s_ptrel").c_str(),("!"+lep+"s_tru_tm").c_str());
  ttbar.Project("ttbar_reliso_good",(lep+"s_reliso").c_str(),(lep+"s_tru_tm").c_str());
  ttbar.Project("ttbar_reliso_bad",(lep+"s_reliso").c_str(),("!"+lep+"s_tru_tm").c_str());
  susy.Project("susy_ptrel_good",(lep+"s_ptrel").c_str(),(lep+"s_tru_tm").c_str());
  susy.Project("susy_ptrel_bad",(lep+"s_ptrel").c_str(),("!"+lep+"s_tru_tm").c_str());
  susy.Project("susy_reliso_good",(lep+"s_reliso").c_str(),(lep+"s_tru_tm").c_str());
  susy.Project("susy_reliso_bad",(lep+"s_reliso").c_str(),("!"+lep+"s_tru_tm").c_str());

  TGraph ttbar_ptrel = MakeROC(ttbar_ptrel_good, ttbar_ptrel_bad, false);
  TGraph ttbar_reliso = MakeROC(ttbar_reliso_good, ttbar_reliso_bad, true);
  TGraph susy_ptrel = MakeROC(susy_ptrel_good, susy_ptrel_bad, false);
  TGraph susy_reliso = MakeROC(susy_reliso_good, susy_reliso_bad, true);

  ttbar_ptrel.SetLineColor(2);
  ttbar_reliso.SetLineColor(1);
  susy_ptrel.SetLineColor(2);
  susy_reliso.SetLineColor(1);

  ttbar_ptrel.SetLineStyle(2);
  ttbar_reliso.SetLineStyle(2);
  susy_ptrel.SetLineStyle(1);
  susy_reliso.SetLineStyle(1);

  std::string full_lep = "Lepton";
  if(lep=="mu"){
    full_lep = "Mu";
  }else if(lep=="el"){
    full_lep = "El";
  }
  TH1D dumb("","",1,0.0,1.0);
  dumb.SetTitle((";Truth Matched Prompt "
		 +full_lep
		 +" Efficiency;Non-Prompt "
		 +full_lep
		 +" Rejection Rate").c_str());
  dumb.SetMinimum(0.0);
  dumb.SetMaximum(1.0);

  TCanvas canvas;
  dumb.Draw();
  ttbar_ptrel.Draw("lsame");
  ttbar_reliso.Draw("lsame");
  susy_ptrel.Draw("lsame");
  susy_reliso.Draw("lsame");

  TLegend leg(0.1,0.12,0.4,0.32);
  leg.AddEntry(&ttbar_ptrel, "ptrel, ttbar", "l");
  leg.AddEntry(&ttbar_reliso, "reliso, ttbar", "l");
  leg.AddEntry(&susy_ptrel, "ptrel, T1tttt(1200,800)", "l");
  leg.AddEntry(&susy_reliso, "reliso, T1tttt(1200,800)", "l");
  leg.Draw("same");
  canvas.Print(("eps/roc_"+lep+".eps").c_str());
}

TGraph MakeROC(TH1D &good, TH1D &bad, const bool less_is_better){
  const int nbins = good.GetNbinsX();
  if(bad.GetNbinsX() != nbins) throw std::logic_error("Mismatched number of bins");

  TGraph graph(0);
  const double good_tot = good.Integral(0, nbins+1);
  const double bad_tot = bad.Integral(0, nbins+1);
  AddPoint(graph, 1.0, 0.0);
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
  AddPoint(graph, 0.0, 1.0);

  return graph;
}

void DrawScat(TChain &chain, const std::string &sample,
	      const std::string &lep, const bool truth_match){
  const unsigned reliso_nbins = 100, ptrel_nbins = 100;
  const double reliso_low = 0.0, reliso_high = 2.0;
  const double ptrel_low = 0.0, ptrel_high = 50.0;

  std::string title_samp = "";
  if(sample=="susy") title_samp = "T1tttt(1200,800)";
  else if(sample=="ttbar") title_samp = "ttbar";

  std::string title_lep = "Lepton";
  if(lep=="mu") title_lep = "Muon";
  else if(lep=="el") title_lep = "Electron";

  std::string title_truth_match = truth_match?"Truth-Matched":"Anti-Truth-Matched";

  std::string title = title_samp+" "+title_truth_match+" "+title_lep;

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
