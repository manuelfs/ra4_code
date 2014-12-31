#ifndef H_ISO_OPTIMIZE
#define H_ISO_OPTIMIZE

#include <cstddef>

#include <vector>

#include "small_tree.hpp"

//List of isolation cuts to test
bool StandardCut(small_tree &tree, double /*cut_val*/);

typedef bool (*Cut)(small_tree&, double);
bool PassBaseline(const small_tree &tree);
void LookUpCuts(size_t iso_type,
		Cut &iso_cut,
		std::vector<double> &cut_vals);
void GetCounts(std::vector<small_tree*> &samples,
	       double lumi,
	       size_t cut_types,
	       std::vector<std::vector<double> > &counts);
void Delete(std::vector<small_tree*> &trees);

#endif
