#ifndef H_SELECTION
#define H_SELECTION

#include <vector>
#include <string>

#include "cut.hpp"

class Selection{
public:
  enum CutSet{
    kStandard
  };

  Selection();
  explicit Selection(const CutSet selection);

  const std::vector<Cut>& GetBaselineCuts() const;
  const std::vector<std::vector<Cut> >& GetBinningCuts() const;

  const CutSet& Sel() const;
  const CutSet& Sel(const CutSet& selection);

  Cut BaselineCut() const;
  Cut BaselineMinusOneCut(const std::vector<Cut>::const_iterator& minus) const;
  Cut IndependentBaselineCut(const std::string &cut) const;

  Cut ProgressiveCut(const std::vector<Cut>::const_iterator& end_cut) const;
  Cut ProgressiveCut(const std::vector<std::vector<Cut> >::const_iterator& end_cut) const;

private:
  std::vector<Cut> baseline_cuts_;
  std::vector<std::vector<Cut> > binning_cuts_;
  mutable Cut baseline_cut_;
  CutSet cut_set_;
  mutable bool cached_baseline_cut_;

  void SetCutSets();

  void LoadStandardBaselineCuts();
  void LoadStandardBinningCuts();
};

#endif
