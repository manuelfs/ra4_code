#ifndef H_CUT
#define H_CUT

#include "small_tree.hpp"

// Allows selection of different cut comparisons
enum InequalityType{
  kNotEqual = -3,
  kLess = -2,
  kLessEqual = -1,
  kEqual = 0,
  kGreater = 1,
  kGreaterEqual = 2
};

// Pointers to the base class can be stored in containers (e.g. vectors). Selection of the template derived class is done automatically by dynamic dispatch
struct CutBase{
  CutBase();
  CutBase(small_tree const * tree,
          InequalityType compare = kGreaterEqual);

  virtual bool Pass() const;
  operator bool();

  small_tree const * tree_;
  InequalityType compare_;

  virtual ~CutBase();
};

// The actual implementation for each type is done in this template class
template<typename T>
struct Cut : public CutBase{
  typedef T ReturnType;
  typedef const ReturnType& (small_tree::* FunctionPtrType)() const;

  Cut();
  Cut(small_tree const * tree,
      FunctionPtrType func,
      const ReturnType &cut_val,
      InequalityType compare = kGreaterEqual);

  bool Pass() const;

  ReturnType cut_val_;
  FunctionPtrType func_;
};

// Some convenience functions for making new cuts without specifying the type
template<typename T>
Cut<T> MakeCut(small_tree const * tree,
               const T& (small_tree::* func)() const,
               const T &cut_val,
               InequalityType compare = kGreaterEqual);

template<typename T>
Cut<T> * NewCut(small_tree const * tree,
                const T& (small_tree::* func)() const,
                const T &cut_val,
                InequalityType compare = kGreaterEqual);

#include "cut_impl.hpp"

#endif
