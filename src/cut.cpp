#include "cut.hpp"
#include <cstring>
#include <set>
#include <string>
#include "utilities.hpp"

Cut::Cut(const std::string& cut_string):
  dependencies_(),
  cut_string_(cut_string){
  }

Cut::Cut(const std::string& cut_string,
         const std::set<std::string>& dependencies):
  dependencies_(dependencies),
  cut_string_(cut_string){
  }

Cut::Cut(const std::string& cut_string,
         const std::string& dependencies):
  dependencies_(),
  cut_string_(cut_string){
  const std::vector<std::string> dependency_vector(Tokenize(dependencies, ", "));
  dependencies_=std::set<std::string>(dependency_vector.begin(), dependency_vector.end());
  }

const std::set<std::string>& Cut::Dependencies() const{
  return dependencies_;
}

std::set<std::string>& Cut::Dependencies(){
  return dependencies_;
}

const std::string& Cut::CutString() const{
  return cut_string_;
}

std::string& Cut::CutString(){
  return cut_string_;
}

bool Cut::operator<(const Cut& cut) const{
  return cut_string_<cut.cut_string_;
}

Cut& Cut::operator&=(const Cut& cut){
  if(cut_string_.size()!=0 && cut.cut_string_.size()!=0){
    cut_string_="("+cut_string_+")&&("+cut.cut_string_+")";
  }else if(cut.cut_string_.size()!=0){
    cut_string_=cut.cut_string_;
  }
  dependencies_.insert(cut.dependencies_.begin(), cut.dependencies_.end());
  return *this;
}

Cut& Cut::operator|=(const Cut& cut){
  if(cut_string_.size()!=0 && cut.cut_string_.size()!=0){
    cut_string_="("+cut_string_+")||("+cut.cut_string_+")";
  }else if(cut.cut_string_.size()!=0){
    cut_string_=cut.cut_string_;
  }
  dependencies_.insert(cut.dependencies_.begin(), cut.dependencies_.end());
  return *this;
}

Cut& Cut::operator*=(const Cut& cut){
  if(cut_string_.size()!=0 && cut.cut_string_.size()!=0){
    cut_string_="("+cut_string_+")*("+cut.cut_string_+")";
  }else if(cut.cut_string_.size()!=0){
    cut_string_=cut.cut_string_;
  }
  dependencies_.insert(cut.dependencies_.begin(), cut.dependencies_.end());
  return *this;
}

Cut operator&&(const Cut& x, const Cut& y){
  return Cut(x)&=y;
}

Cut operator||(const Cut& x, const Cut& y){
  return Cut(x)|=y;
}

Cut operator*(const Cut& x, const Cut& y){
  return Cut(x)*=y;
}
