#ifndef H_ROC_SORB_PLOTS
#define H_ROC_SORB_PLOTS

#include <vector>
#include <string>
#include <utility>

#include "TH1D.h"
#include "TGraph.h"
#include "TChain.h"

#include "dataset.hpp"
#include "selection.hpp"

typedef std::pair<std::string, std::vector<float> > ROCdef;

std::vector<float> lin_bins(const unsigned bins, double low, double high);

void GetROCHistos(const Dataset &dataset,
                  const Selection &selection,
                  const std::vector<ROCdef> &roc_defs,
                  std::vector<std::pair<TH1D, std::vector<TH1D> > > &roc_histos);
void GetHisto(const std::string &var_name,
              const std::string &cut,
              const std::vector<float> &bins,
              TChain &chain,
              TH1D &histo,
              const std::string &append = "");
void GetROCs(const std::vector<std::pair<TH1D, std::vector<TH1D> > > &roc_histos,
             std::vector<std::vector<TGraph> > &rocs);
void GetSORBs(const std::vector<std::pair<TH1D, std::vector<TH1D> > > &roc_histos,
              std::vector<std::vector<TH1D> > &sobs);
void GetPoints(const TH1D &hist, std::vector<double> &pts, const bool use_rejection = false);

void DrawROCs(const Dataset& dataset,
	      const std::vector<ROCdef> &defs,
              std::vector<std::vector<TGraph> > &rocs,
              const std::vector<unsigned> &indices,
              const std::string &out_file);
void DrawSORBs(const Dataset& dataset,
	       const std::vector<ROCdef> &defs,
               std::vector<std::vector<TH1D> > &sorbs,
               const std::vector<unsigned> &indices,
               const std::string &out_file,
	       const std::string &xtitle);

int GetColor(const unsigned col);
int GetLineStyle(const unsigned i);

#endif
