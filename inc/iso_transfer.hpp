#ifndef H_ISO_TRANSFER
#define H_ISO_TRANSFER

#include <cstddef>

#include <vector>

#include "TLine.h"

#include "small_tree.hpp"

class CutBase;

typedef int (*IsoCut)(const small_tree &, int &, int &);

template<typename T>
void Delete(T& vec){
  for(typename T::iterator it = vec.begin();
      it != vec.end();
      ++it){
    if(*it){
      delete *it;
      *it = NULL;
    }
  }
  vec.clear();
}

bool PassesCuts(const std::vector<CutBase*> &cuts);
int GetLeptons(const small_tree &tree,
               IsoCut cut,
               int &best_el,
               int &best_mu);

void Fix(const small_tree &tree,
         int &best_el, int &best_mu);

int StandardIso(const small_tree &tree,
                int &best_el,
                int &best_mu);
int StandardEl(const small_tree &tree,
               int &best_el);
int StandardMu(const small_tree &tree,
               int &best_mu);

int MiniIso(const small_tree &tree,
            int &best_el,
            int &best_mu);
int MiniEl(const small_tree &tree,
           int &best_el);
int MiniMu(const small_tree &tree,
           int &best_mu);

int VetoStandardIso(const small_tree &tree,
                int &best_el,
                int &best_mu);
int VetoStandardEl(const small_tree &tree,
               int &best_el);
int VetoStandardMu(const small_tree &tree,
               int &best_mu);

int VetoMiniIso(const small_tree &tree,
            int &best_el,
            int &best_mu);
int VetoMiniEl(const small_tree &tree,
           int &best_el);
int VetoMiniMu(const small_tree &tree,
           int &best_mu);

void PositiveColors(int pos_cols[]);
void SymmetricColors(int sym_cols[]);
void SetLineStyle(TLine &line);

#endif
