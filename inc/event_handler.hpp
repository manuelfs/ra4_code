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
  void GetPtRels(std::vector<float> &els_ptrel, std::vector<float> &els_mindr,
		 std::vector<float> &mus_ptrel,
		 std::vector<float> &mus_mindr,
		 float dr_match_thresh = -1.0);

  bool skip_slow;

};

#endif
