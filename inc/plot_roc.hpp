// plot_roc: Macro that plots ROC curves
#ifndef H_PLOT_ROC
#define H_PLOT_ROC

#include <vector>
#include "TH1D.h"
#include "TString.h"

class var_class {
public:
  var_class(TString ivarname, float iminx, float imaxx, TString ititle, int icolor, 
	    int istyle=1, std::vector<int> icuts=std::vector<int>());
  TString title, varname;
  float minx, maxx;
  std::vector<int> cuts;
  int color, style;
};

class sample_class {
public:
  sample_class(TString ilabel, std::vector<TString> ifiles, TString icut="1");
  TString label, cut;
  std::vector<TString> files;
};

TGraph MakeROC(TH1D &good, TH1D &bad, const bool less_is_better);
void DrawROC(std::vector<sample_class> samples, std::vector<var_class> vars, TString cuts, TString tag);



#endif
