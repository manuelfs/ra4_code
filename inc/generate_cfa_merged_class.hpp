#ifndef H_GEN_CFA_MERGED
#define H_GEN_CFA_MERGED

#include <set>
#include <utility>
#include <string>

#include "TChain.h"

typedef std::pair<std::string, std::string> Var;

void GetVariables(TChain *chain, std::set<Var>& vars);

#endif
