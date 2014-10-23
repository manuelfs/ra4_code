#include "dataset.hpp"

#include <vector>
#include "sample.hpp"

Dataset::Dataset(const SampleSet dataset):
  background_samples_(),
  signal_samples_(),
  data_samples_(),
  sample_set_(dataset){
  SetSampleSets();
}

const std::vector<Sample*>& Dataset::GetBackgroundSamples() const{
  return background_samples_;
}

const std::vector<Sample*>& Dataset::GetSignalSamples() const{
  return signal_samples_;
}

const std::vector<Sample*>& Dataset::GetDataSamples() const{
  return data_samples_;
}

const Dataset::SampleSet& Dataset::Samples() const{
  return sample_set_;
}

const Dataset::SampleSet& Dataset::Samples(const SampleSet& sample_set){
  if(sample_set_!=sample_set){
    sample_set_=sample_set;
    SetSampleSets();
  }
  return sample_set_;
}

Dataset::~Dataset(){
  ClearSampleVectors();
}

void Dataset::SetSampleSets(){
  ClearSampleVectors();
  switch(sample_set_){
  default: //intentional fall-through
  case kStandard:
    LoadStandardBackgroundSamples();
    LoadStandardSignalSamples();
    LoadStandardDataSamples();
    break;
  case kSignalBackground:
    LoadSignalBackgroundBackgroundSamples();
    LoadSignalBackgroundSignalSamples();
    LoadSignalBackgroundDataSamples();
    break;
  }
}

void Dataset::ClearSampleVectors(){
  ClearSampleVector(background_samples_);
  ClearSampleVector(signal_samples_);
  ClearSampleVector(data_samples_);
}

void Dataset::ClearSampleVector(std::vector<Sample*>& vec){
  for(std::vector<Sample*>::iterator it(vec.begin());
      it!=vec.end();
      ++it){
    delete *it;
  }
  std::vector<Sample*>().swap(vec);
}

void Dataset::LoadStandardBackgroundSamples(){
  background_samples_.push_back(new Sample("ttbar"));
  background_samples_.back()->chain().Add("archive/14-10-18/ra4skim/*TTJets*.root/tree");

  background_samples_.push_back(new Sample("QCD"));
  background_samples_.back()->chain().Add("archive/14-10-18/ra4skim/*QCD*.root/tree");

  background_samples_.push_back(new Sample("Single top"));
  background_samples_.back()->chain().Add("archive/14-10-18/ra4skim/*s-channel*.root/tree");
  background_samples_.back()->chain().Add("archive/14-10-18/ra4skim/*t-channel*.root/tree");
  background_samples_.back()->chain().Add("archive/14-10-18/ra4skim/*tW-channel*.root/tree");

  background_samples_.push_back(new Sample("Drell-Yan"));
  background_samples_.back()->chain().Add("archive/14-10-18/ra4skim/*DYJets*.root/tree");

  background_samples_.push_back(new Sample("W+Jets"));
  background_samples_.back()->chain().Add("archive/14-10-18/ra4skim/*WJets*.root/tree");
}

void Dataset::LoadStandardSignalSamples(){
  signal_samples_.push_back(new Sample("T1tttt (1500, 100)", Cut("")));
  signal_samples_.back()->chain().Add("archive/14-10-18/ra4skim/*T1tttt_2J_mGl-1500_mLSP-100*.root/tree");

  signal_samples_.push_back(new Sample("T1tttt (1200, 800)", Cut("")));
  signal_samples_.back()->chain().Add("archive/14-10-18/ra4skim/*SMS-T1tttt_2J_mGl-1200_mLSP-800*.root/tree");
}

void Dataset::LoadStandardDataSamples(){
  //No data yet
}

void Dataset::LoadSignalBackgroundBackgroundSamples(){
  background_samples_.push_back(new Sample("SM Background"));
  background_samples_.back()->chain().Add("archive/14-10-18/ra4skim/*TTJets*.root/tree");
  background_samples_.back()->chain().Add("archive/14-10-18/ra4skim/*QCD*.root/tree");
  background_samples_.back()->chain().Add("archive/14-10-18/ra4skim/*s-channel*.root/tree");
  background_samples_.back()->chain().Add("archive/14-10-18/ra4skim/*t-channel*.root/tree");
  background_samples_.back()->chain().Add("archive/14-10-18/ra4skim/*tW-channel*.root/tree");
  background_samples_.back()->chain().Add("archive/14-10-18/ra4skim/*DYJets*.root/tree");
  background_samples_.back()->chain().Add("archive/14-10-18/ra4skim/*WJets*.root/tree");
}

void Dataset::LoadSignalBackgroundSignalSamples(){
  LoadStandardSignalSamples();
}

void Dataset::LoadSignalBackgroundDataSamples(){
  //No data yet
}
