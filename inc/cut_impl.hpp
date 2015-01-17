//Implementation for template functions needed by cut.hpp

#ifndef H_CUT_IMPL
#define H_CUT_IMPL

#include "cut.hpp"

template<typename T>
Cut<T>::Cut():
  CutBase(),
  func_(NULL){
}

template<typename T>
Cut<T>::Cut(small_tree const * tree,
            FunctionPtrType func,
            const T &cut_val,
            InequalityType compare):
  CutBase(tree, compare),
  cut_val_(cut_val),
  func_(func){
  }

template<typename T>
bool Cut<T>::Pass() const{
  if(!(tree_ && func_)) return false;
  ReturnType val = (tree_->*func_)();
  switch(compare_){
  case kNotEqual:     return val != cut_val_;
  case kLess:         return val <  cut_val_;
  case kLessEqual:    return val <= cut_val_;
  case kEqual:        return val == cut_val_;
  default:
  case kGreaterEqual: return val >= cut_val_;
  case kGreater:      return val >  cut_val_;
  }
}

template<typename T>
Cut<T> MakeCut(small_tree const * tree,
               const T& (small_tree::* func)() const,
               const T &cut_val,
               InequalityType compare){
  return Cut<T>(tree, func, cut_val, compare);
}

template<typename T>
Cut<T> * NewCut(small_tree const * tree,
                const T& (small_tree::* func)() const,
                const T &cut_val,
                InequalityType compare){
  return new Cut<T>(tree, func, cut_val, compare);
}

#endif
