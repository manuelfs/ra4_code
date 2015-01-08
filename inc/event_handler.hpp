// event_handler: Defines reduced tree with RA4 variables

#ifndef H_EVENT_HANDLER
#define H_EVENT_HANDLER

#include <vector>
#include <string>
#include <utility>
#include <limits>
#include <stdint.h>
#include "phys_objects.hpp"
#include "utilities.hpp"
#include "small_tree.hpp"

class event_handler : public phys_objects{
public:
  explicit event_handler(const std::string &fileName, bool quick_mode=false);

  void ReduceTree(int Nentries, TString outFilename, int Ntotentries);
  void SetMiniIso(small_tree &tree, int ilep, bool isElectron);
  void WriteFatJets(small_tree &tree);
  void WriteTaus(small_tree &tree);
  void WriteIsoTks(small_tree &tree);  
  void GetPtRels(std::vector<float> &els_ptrel, std::vector<float> &els_mindr,
                 std::vector<float> &mus_ptrel,
                 std::vector<float> &mus_mindr,
                 float pt_cut = 0.0,
                 bool remove_isolated = true,
                 float dr_match_thresh = -1.0);
  void SumDeltaPhiVars(small_tree &tree,
                       const std::vector<int> &good_jets);
  unsigned TypeCode() const;

  bool skip_slow;

  float GetMinMTWb(std::vector<int> good_jets, const double pt_cut, const double bTag_req, const bool use_W_mass) const;
  float GetMTWb(const double b_pt, const double MET, const double b_phi, const double MET_phi, const bool use_W_mass) const;
};

#endif
