#ifndef H_GEN_CFA
#define H_GEN_CFA

#include <map>
#include <set>
#include <utility>
#include <string>
#include <vector>

#include "TChain.h"

class Variable{
public:
  Variable(const std::string &name, const bool from_chain_a,
	   const std::string &type, const std::string &to_type);
  Variable(const std::string &name, const bool from_chain_a, const std::string &type);
  Variable();

  const std::string &Name() const;
  Variable &Name(const std::string &name);
 
  const std::string &FromType() const;
  Variable &FromType(const std::string &name);

  const std::string &ToType() const;
  Variable &ToType(const std::string &name);

  const bool &FromChainA() const;
  Variable &FromChainA(const bool from_chain_a);

  bool Converted() const;

private:
  std::string name_, to_type_, from_type_;
  bool from_chain_a_;
};

typedef std::map<std::string, std::vector<std::pair<bool, std::string> > > Dictionary;
//Map of variable names to vector containing is_chain_a, type pair for each file read in

typedef std::set<std::pair<std::string, std::string> > Typelist;
//set of name-type pairs

typedef std::vector<std::pair<std::string, std::vector<std::string> > > RepList;
//vector of pairs of mux output names and vector of mux input names

typedef std::map<std::pair<std::string, std::string>, std::vector<std::string> > RepMap;
//map of name-type pair to vector of mux input names

void GetVariables(TChain &chain, const bool is_chain_a,
		  const size_t file, const size_t num_files,
		  Dictionary &vars);

void ClassifyVariables(const Dictionary &all_var,
		       std::vector<Variable> &base_vars, std::vector<Variable> &virtual_vars,
		       std::vector<std::vector<Variable> > &file_vars);

void WriteBaseHeader(const std::vector<Variable> &base_vars,
		     const std::vector<Variable> &virtual_variables);
void WriteBaseSource(const std::vector<Variable> &base_vars,
		     const std::vector<Variable> &virtual_variables);

void WriteDerivedHeader(const std::string &class_name,
			const std::vector<Variable> &vars);
void WriteDerivedSource(const std::string &class_name,
			const std::vector<Variable> &vars);

void WriteMergedHeader(const Typelist &typelist, const RepMap &overwritten,
		       const RepMap &new_funcs);
void WriteMergedSource(const Typelist &typelist, const RepMap &overwritten,
		       const RepMap &new_funcs, const std::vector<std::string> &class_names);

void AddToTypelist(const std::vector<Variable> &vars,
		   Typelist &typelist);
void PrintAccessor(const Variable &var, std::ofstream &file, const std::string &class_name);

void GetRules(RepList &reps);
void GetReplacements(const Typelist &typelist, const RepList &pats, RepMap &reps);
void GetOverwritten(const Typelist &typelist, const RepMap &replacements,
		    RepMap &overwritten, RepMap &new_funcs);

#endif
