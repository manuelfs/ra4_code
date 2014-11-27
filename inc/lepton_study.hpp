#ifndef H_LEPTON_ISO_STUDY
#define H_LEPTON_ISO_STUDY

#include <string>

#include "TH1D.h"
#include "TGraph.h"
#include "TChain.h"

void DrawROC(TChain &ttbar, TChain &susy, const std::string &lep);
TGraph MakeROC(TH1D &good, TH1D &bad, const bool less_is_better);
void DrawScat(TChain &chain, const std::string &sample,
	      const std::string &lep, const bool truth_match);

#endif
