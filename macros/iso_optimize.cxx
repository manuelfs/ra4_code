#include <cmath>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "TFile.h"
#include "TChain.h"
#include "TCanvas.h"
#include "TH1D.h"

#include "utilities.hpp"
#include "styles.hpp"

using namespace std;

class Sample {
public:
  Sample(const TString &ifile, const TString &ilabel, const TString icut="1",
	 int icolor=1, int istyle=1):
    file(ifile),
    label(ilabel),
    cut(icut),
    color(icolor),
    style(istyle){
  }
  
  TString file, label, cut;
  int color, style;
};

string ToString(double x){
  ostringstream oss("");
  oss << x;
  return oss.str();
}

vector<double> MakeSOverSqrtB(TChain &background, TChain &signal, const string &baseline,
			       const string &els_iso, const string &mus_iso,
			       int bins, double low, double high){
  string lep_sig = "(Sum$(els_ispf&&els_sigid&&("+els_iso+"))+Sum$(mus_sigid&&("+mus_iso+")))==1";
  string lep_veto = "(Sum$(els_ispf&&("+els_iso+"))+Sum$("+mus_iso+"))==1";
  string full_cut = "("+baseline+")&&("+lep_sig+")&&("+lep_veto+")";

  vector<double> out(bins);
  
  double increment = (bins==1)?low:(high-low)/(bins-1);
  for(int bin = 0 ; bin < bins; ++bin){
    double cut_val = low + bin*increment;
    string cut_rep = ToString(cut_val);
    TString this_cut = "5*weight*("+full_cut+")";
    this_cut.ReplaceAll("CUT",cut_rep.c_str());
    
    double background_count, background_uncert;
    double signal_count, signal_uncert;
    get_count_and_uncertainty(background, this_cut.Data(),
			      background_count, background_uncert);
    get_count_and_uncertainty(signal, this_cut.Data(),
			      signal_count, signal_uncert);
    out.at(bin) = signal_count/sqrt(background_count);
    cout << this_cut << ": " << signal_count << "/sqrt(" << background_count << ")=" << out.at(bin) << endl;
  }
  return out;
}

int main(){
  vector<Sample> samples;
  samples.push_back(Sample("archive/ra4skim/*TT_*","t#bar{t}"));
  samples.push_back(Sample("archive/ra4skim/*QCD*","QCD"));
  samples.push_back(Sample("archive/ra4skim/*T1tttt*1500*100*PU20*", "T1tttt(1500,100)"));
  samples.push_back(Sample("archive/ra4skim/*T1tttt*1500*100*PU40*", "T1tttt(1500,100), PU40"));
  samples.push_back(Sample("archive/ra4skim/*T2tt*850*100", "T2tt(850,100)"));
  samples.push_back(Sample("archive/ra4skim/*T2tt*650*325", "T2tt(650,325)"));

  vector<size_t> background_idx(0), signal_idx(0);
  background_idx.push_back(0);
  background_idx.push_back(1);
  signal_idx.push_back(2);

  string onesig = "1";//"(Sum$(els_ispf&&els_sigid)+Sum$(mus_sigid))>=1";
  string baseline = "("+onesig+")&&(ht>750&&met>250&&nbl>=2&&njets>=6)";

  TChain background("tree"), signal("tree");
  for(size_t i = 0; i < background_idx.size(); ++i){
    cout << background.Add(samples.at(background_idx.at(i)).file) << endl;
  }
  for(size_t i = 0; i < signal_idx.size(); ++i){
    cout << signal.Add(samples.at(signal_idx.at(i)).file) << endl;
  }

  MakeSOverSqrtB(background, signal, baseline, "1", "1", 1, 0, 1);

  MakeSOverSqrtB(background, signal, baseline, "els_miniso_tr15<CUT", "mus_miniso_tr15<CUT", 8, 0.0, 0.35);
  MakeSOverSqrtB(background, signal, baseline, "els_miniso_tr15<CUT", "mus_miniso_tr15<0.12", 8, 0.0, 0.35);
  MakeSOverSqrtB(background, signal, baseline, "els_miniso_tr15<0.2", "mus_miniso_tr15<CUT", 8, 0.0, 0.35);

  MakeSOverSqrtB(background, signal, baseline, "els_reliso<0.2||els_ptrel_0>CUT", "mus_reliso<0.12||mus_ptrel_0>CUT", 10, 5.0, 50.0);
  MakeSOverSqrtB(background, signal, baseline, "els_reliso<0.2||els_ptrel_0>25.0", "mus_reliso<0.12||mus_ptrel_0>CUT", 10, 5.0, 50.0);
  MakeSOverSqrtB(background, signal, baseline, "els_reliso<0.2||els_ptrel_0>CUT", "mus_reliso<0.12||mus_ptrel_0>25.0", 10, 5.0, 50.0);
}
