#include "selection.hpp"

#include <vector>
#include <string>

#include "cut.hpp"

Selection::Selection():
  baseline_cuts_(),
  binning_cuts_(),
  baseline_cut_(),
  cut_set_(kStandard),
  cached_baseline_cut_(false){
  SetCutSets();
  }

Selection::Selection(const CutSet selection):
  baseline_cuts_(),
  binning_cuts_(),
  baseline_cut_(),
  cut_set_(selection),
  cached_baseline_cut_(false){
  SetCutSets();
  }

const std::vector<Cut>& Selection::GetBaselineCuts() const{
  return baseline_cuts_;
}

const std::vector<std::vector<Cut> >& Selection::GetBinningCuts() const{
  return binning_cuts_;
}

const Selection::CutSet& Selection::Sel() const{
  return cut_set_;
}

const Selection::CutSet& Selection::Sel(const CutSet& selection){
  if(cut_set_!=selection){
    cut_set_=selection;
    cached_baseline_cut_=false;
    SetCutSets();
  }
  return cut_set_;
}

Cut Selection::BaselineCut() const{
  if(!cached_baseline_cut_){
    baseline_cut_=Cut();
    for(std::vector<Cut>::const_iterator to_add(baseline_cuts_.begin());
	to_add!=baseline_cuts_.end();
	++to_add){
      baseline_cut_&= *to_add;
    }
    cached_baseline_cut_=true;
  }
  return baseline_cut_;
}

Cut Selection::BaselineMinusOneCut(const std::vector<Cut>::const_iterator& minus) const{
  Cut baseline_cut;
  for(std::vector<Cut>::const_iterator to_add(baseline_cuts_.begin());
      to_add!=baseline_cuts_.end();
      ++to_add){
    if(to_add!=minus){
      baseline_cut&= *to_add;
    }
  }
  return baseline_cut;
}

Cut Selection::IndependentBaselineCut(const std::string &cut) const{
  Cut baseline_cut;
  for(std::vector<Cut>::const_iterator to_add(baseline_cuts_.begin());
      to_add!=baseline_cuts_.end();
      ++to_add){
    if(to_add->Dependencies().find(cut) == to_add->Dependencies().end()){
      baseline_cut&= *to_add;
    }
  }
  return baseline_cut;
}

Cut Selection::ProgressiveCut(const std::vector<Cut>::const_iterator& end_cut) const{
  Cut output_cut;
  bool found(false);
  if(end_cut==baseline_cuts_.end()){
    output_cut=BaselineCut();
    found=true;
  }
  for(std::vector<Cut>::const_iterator to_add(baseline_cuts_.begin());
      !found && to_add!=baseline_cuts_.end();
      ++to_add){
    if(to_add==end_cut){
      found=true;
    }else{
      output_cut&= *to_add;
    }
  }

  for(std::vector<std::vector<Cut> >::const_iterator cat(binning_cuts_.begin());
      !found && cat!=binning_cuts_.end();
      ++cat){
    if(cat->end()==end_cut){
      found=true;
    }

    for(std::vector<Cut>::const_iterator cut(cat->begin());
	!found && cut!=cat->end();
	++cut){
      if(cut==end_cut){
	found=true;
      }
    }

    if(found){
      for(std::vector<Cut>::const_iterator cut(cat->begin());
	  cut!=end_cut && cut!=cat->end();
	  ++cut){
	output_cut&= *cut;
      }
    }
  }
  return output_cut;
}

void Selection::SetCutSets(){
  baseline_cuts_.clear();
  binning_cuts_.clear();
  switch(cut_set_){
  case kStandard:
  default:
    LoadStandardBaselineCuts();
    LoadStandardBinningCuts();
    break;
  }
}

void Selection::LoadStandardBaselineCuts(){
  baseline_cuts_.push_back(Cut("nleps==1", "nleps, nmus, nels"));
  baseline_cuts_.push_back(Cut("ht>750", "ht,genht"));
  baseline_cuts_.push_back(Cut("met>250", "met,genmet"));
  baseline_cuts_.push_back(Cut("nbm>=2", "nbm,nbl,nbt"));
  baseline_cuts_.push_back(Cut("njets>=6", "njets"));
}

void Selection::LoadStandardBinningCuts(){
}
