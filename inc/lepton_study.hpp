#ifndef H_LEPTON_ISO_STUDY
#define H_LEPTON_ISO_STUDY

#include <string>

#include "TH1D.h"
#include "TGraph.h"
#include "TChain.h"

void DrawROC(TChain &ttbar, TChain &t1tttt, const std::string &lep, int pt_bin = 0);
TGraph MakeROC(TH1D &good, TH1D &bad, const bool less_is_better,
	       double good_count = 0.0, double bad_count = 0.0);
void DrawScat(TChain &chain, const std::string &sample,
	      const std::string &lep, const bool truth_match);

#endif
