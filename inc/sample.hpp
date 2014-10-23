#ifndef H_SAMPLE
#define H_SAMPLE

#include <string>
#include "TChain.h"
#include "cut.hpp"

class Sample{
public:
  explicit Sample(const std::string& name="anonymous",
		  const Cut& cut_in=Cut());

  TChain& chain();
  const TChain& chain() const;

  Cut& cut();
  const Cut& cut() const;

private:
  TChain chain_;
  Cut cut_;

  Sample(const Sample& sample);
  Sample& operator=(const Sample& sample);
};

#endif
