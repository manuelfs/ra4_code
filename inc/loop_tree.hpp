#ifndef H_LOOP_TREE
#define H_LOOP_TREE

#include "small_tree.hpp"
#include <string>

double passIsolationCut(const small_tree &tree, int ilep, bool isElectron, bool isveto, std::string isotype, const double coneiso_cut);

#endif
