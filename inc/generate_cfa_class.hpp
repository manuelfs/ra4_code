#ifndef H_GEN_CFA
#define H_GEN_CFA

#include <map>
#include <set>
#include <utility>
#include <string>

#include "TChain.h"

typedef std::map<std::string, std::set<std::string> > VarSet;

void GetVariables(TChain *chain, VarSet &vars);
std::string AllCaps(std::string str);
void GetTypes(const VarSet &full_varset,
	      const VarSet::const_iterator &variable,
	      std::string &from_type,
	      std::string &to_type);
std::string GetType(const VarSet::const_iterator &variable);

void WriteBaseHeader(const VarSet &full_varset);
void WriteBaseSource(const VarSet &full_varset);

void WriteDerivedHeader(const VarSet &full_varset,
			const std::pair<std::string, VarSet> &individual_varset);
void WriteDerivedSource(const VarSet &full_varset,
			const std::pair<std::string, VarSet> &individual_varset,
			const std::pair<std::string, VarSet> &individual_varset_a,
			const std::pair<std::string, VarSet> &individual_varset_b);

void WriteMergedHeader(const VarSet &full_varset);
void WriteMergedSource(const VarSet &full_varset);

#endif
