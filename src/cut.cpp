#include "cut.hpp"

class small_tree;

CutBase::CutBase():
  tree_(NULL),
  compare_(kGreaterEqual){
}

CutBase::CutBase(small_tree const * tree,
                 InequalityType greater):
  tree_(tree),
  compare_(greater){
  }

bool CutBase::Pass() const{
  return false;
}

CutBase::operator bool(){
  return Pass();
}

CutBase::~CutBase(){
}
