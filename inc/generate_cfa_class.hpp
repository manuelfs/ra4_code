#ifndef H_GEN_CFA
#define H_GEN_CFA

#include <map>
#include <set>
#include <utility>
#include <string>
#include <vector>

class TChain;

typedef std::map<std::string, std::set<std::string> > VarSet;
//map of variable name to set of all types for that name

typedef std::set<std::pair<std::string, std::string> > Dict;
//set of name-type pairs

typedef std::vector<std::pair<std::string, std::vector<std::string> > > RepList;
//vector of pairs of mux output names and vector of mux input names

typedef std::map<std::pair<std::string, std::string>, std::vector<std::string> > RepMap;
//map of name-type pair to vector of mux input names

std::string AllCaps(std::string str);

void GetTypes(const VarSet &full_varset,
              const VarSet::const_iterator &variable,
              std::string &from_type,
              std::string &to_type,
              std::string &this_type);
std::string GetType(const VarSet::const_iterator &variable);

void GetVariables(TChain *chain, VarSet &vars);
void GetDictionary(const VarSet &varset, Dict &dictionary);
void GetRules(RepList &reps);
void GetReplacements(const Dict &dictionary, const RepList &pats, RepMap &reps);
void GetOverwritten(const Dict &dictionary, const RepMap &replacements,
		    RepMap &overwritten, RepMap &new_funcs);

void WriteBaseHeader(const Dict &full_varset);
void WriteBaseSource(const Dict &full_varset);

void WriteDerivedHeader(const VarSet &full_varset,
                        const std::pair<std::string, VarSet> &individual_varset);
void WriteDerivedSource(const VarSet &full_varset,
                        const std::pair<std::string, VarSet> &individual_varset,
                        const std::pair<std::string, VarSet> &individual_varset_a,
                        const std::pair<std::string, VarSet> &individual_varset_b);

void WriteMergedHeader(const Dict &full_varset, const RepMap &overwritten, const RepMap &new_funcs);
void WriteMergedSource(const Dict &full_varset, const RepMap &overwritten, const RepMap &new_funcs,
		       const std::vector<std::string>& class_names);

#endif
