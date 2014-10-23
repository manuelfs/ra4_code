#include "sample.hpp"

#include <string>
#include "cut.hpp"

Sample::Sample(const std::string& name,
	       const Cut& cut_in):
  chain_(name.c_str(), name.c_str()),
  cut_(cut_in){
}

TChain& Sample::chain(){
  return chain_;
}

const TChain& Sample::chain() const{
  return chain_;
}

Cut& Sample::cut(){
  return cut_;
}

const Cut& Sample::cut() const{
  return cut_;
}
