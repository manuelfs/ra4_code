#ifndef H_DATASET
#define H_DATASET

#include <vector>

class Sample;

class Dataset{
public:
  enum SampleSet{
    kStandard,
    kSignalBackground
  };

  explicit Dataset(const SampleSet dataset=kStandard);

  const std::vector<Sample*>& GetBackgroundSamples() const;
  const std::vector<Sample*>& GetSignalSamples() const;
  const std::vector<Sample*>& GetDataSamples() const;

  const SampleSet& Samples() const;
  const SampleSet& Samples(const SampleSet& sample_set);

  ~Dataset();//Dangerous if used as base class...

private:
  std::vector<Sample*> background_samples_;
  std::vector<Sample*> signal_samples_;
  std::vector<Sample*> data_samples_;
  SampleSet sample_set_;

  Dataset(const Dataset& dataset);
  Dataset& operator=(const Dataset& dataset);

  void SetSampleSets();

  void ClearSampleVectors();
  void ClearSampleVector(std::vector<Sample*>& vec);

  void LoadStandardBackgroundSamples();
  void LoadStandardSignalSamples();
  void LoadStandardDataSamples();

  void LoadSignalBackgroundBackgroundSamples();
  void LoadSignalBackgroundSignalSamples();
  void LoadSignalBackgroundDataSamples();
};

#endif
