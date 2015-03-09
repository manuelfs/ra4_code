#ifndef H_EVENT_HANDLER_QUICK
#define H_EVENT_HANDLER_QUICK

#include <string>
#include <vector>

#include "TString.h"

#include "fastjet/ClusterSequence.hh"

#include "event_handler_base.hpp"
#include "small_tree_quick.hpp"

class event_handler_quick : public event_handler_base{
public:
  event_handler_quick(const std::string &file_name);

  virtual void ReduceTree(int num_entries,
                          const TString &out_file_name,
                          int num_total_entries);

  virtual ~event_handler_quick();

  void SetMiniIso(small_tree_quick &tree, int ilep, int ParticleType);
  void WriteFatJets(small_tree_quick &tree);
  void WriteTks(small_tree_quick &tree,
                const std::vector<mc_particle> &parts,
                const std::vector<size_t> &moms,
                short lepmax_chg = 0,
                short lepmax_chg_reliso = 0);
  unsigned TypeCode(const std::vector<mc_particle> &parts,
                    const std::vector<size_t> &moms);
  float GetMinMTWb(const std::vector<int> &good_jets,
                   const double pt_cut,
                   const double bTag_req,
                   const bool use_W_mass) const;

};

// Class to organize the parameters of each iso calculation
typedef std::vector<float> & (small_tree_quick::*st_branch)();
class iso_class {
public:
  explicit iso_class(small_tree_quick *itree, st_branch ibranch=NULL, double iR=0.3,
                     bool iaddPH=true, bool iaddNH=true, bool iaddCH=true, bool iusePFweight=false);
  small_tree_quick *tree;
  st_branch branch;
  double R;
  bool addPH, addNH, addCH, usePFweight;
  float iso_ch, iso_ph, iso_nh, iso_pu;
  void SetIso(float lep_pt=1.);
};

bool greater_m(const fastjet::PseudoJet &a, const fastjet::PseudoJet &b);
std::vector<fastjet::PseudoJet> sorted_by_m(std::vector<fastjet::PseudoJet> pjs);

#endif
