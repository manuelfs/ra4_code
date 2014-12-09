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
  explicit event_handler(const std::string &fileName);

  void ReduceTree(int Nentries, TString outFilename, int Ntotentries, bool skip_slow=false);
  void SetMiniIso(small_tree &tree, int ilep, bool isElectron);
  void WriteFatJets(small_tree &tree);
};

#endif
