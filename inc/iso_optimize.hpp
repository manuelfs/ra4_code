#ifndef H_ISO_OPTIMIZE
#define H_ISO_OPTIMIZE

#include <cstddef>

#include <vector>

#include "small_tree.hpp"

//List of isolation cuts to test
bool StandardCut(const small_tree &tree, double /*cut_val*/);
bool MuonMini02(const small_tree &tree, double cut_val);
bool ElectronMini02(const small_tree &tree, double cut_val);
bool MuonMini0201Ptrel(const small_tree &tree, double cut_val);
bool ElectronMini0201Ptrel(const small_tree &tree, double cut_val);
bool MuonR02(const small_tree &tre, double cut_val);
bool ElectronR02(const small_tree &tre, double cut_val);
bool MuonR0201Ptrel(const small_tree &tre, double cut_val);
bool ElectronR0201Ptrel(const small_tree &tre, double cut_val);
bool MuonR03(const small_tree &tre, double cut_val);
bool ElectronR03(const small_tree &tre, double cut_val);
bool MuonR0301Ptrel(const small_tree &tre, double cut_val);
bool ElectronR0301Ptrel(const small_tree &tre, double cut_val);

typedef bool (*Cut)(const small_tree&, double);
std::vector<size_t> GetBestCuts(const std::vector<std::vector<double> > &sig_counts,
				const std::vector<std::vector<double> > &back_counts);
void PrintHeader();
void PrintLine(size_t itype, double cut_val, double S, double B, bool best = false);
void PrintDivider();
double GetMT(const small_tree &tree,
             long mu, long el);
bool PassBaseline(const small_tree &tree);
int GetStandardMuons(const small_tree &tree, size_t &num_sig, size_t &num_veto);
int GetStandardElectrons(const small_tree &tree, size_t &num_sig, size_t &num_veto);
void LookUpCuts(size_t iso_type,
                Cut &iso_cut,
                std::vector<double> &cut_vals);
void GetCounts(std::vector<small_tree*> &samples,
               double lumi,
               size_t cut_types,
               std::vector<std::vector<double> > &counts);
void Delete(std::vector<small_tree*> &trees);

#endif
