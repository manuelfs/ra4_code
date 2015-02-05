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

  void ReduceTree(int Nentries, const TString &outFilename, int Ntotentries);
  void SetMiniIso(small_tree &tree, int ilep, int ParticleType);
  void WriteFatJets(small_tree &tree);
  void WriteTaus(small_tree &tree);
  void WriteTks(small_tree &tree,
                const std::vector<mc_particle> &parts,
                const std::vector<size_t> &moms);
  void WriteIsoTks(small_tree &tree);
  void GetPtRels(std::vector<float> &els_ptrel, std::vector<float> &els_mindr,
                 std::vector<float> &mus_ptrel,
                 std::vector<float> &mus_mindr,
                 float pt_cut = 0.0,
                 bool remove_isolated = true,
                 float dr_match_thresh = -1.0);
  void SumDeltaPhiVars(small_tree &tree,
                       const std::vector<int> &good_jets);
  unsigned TypeCode(const std::vector<mc_particle> &parts,
                    const std::vector<size_t> &moms);
  void GetTrueLeptons(std::vector<int> &true_electrons, std::vector<int> &true_muons,
                      std::vector<int> &true_had_taus, std::vector<int> &true_lep_taus);

  bool skip_slow;

  float GetMinMTWb(const std::vector<int> &good_jets,
                   const double pt_cut,
                   const double bTag_req,
                   const bool use_W_mass) const;
};

// Class to organize the parameters of each iso calculation
typedef std::vector<float> & (small_tree::*st_branch)();
class iso_class {
public:
  explicit iso_class(small_tree *itree, st_branch ibranch=NULL, double iR=0.3,
                     bool iaddPH=true, bool iaddNH=true, bool iaddCH=true, bool iusePFweight=false);
  small_tree *tree;
  st_branch branch;
  double R;
  bool addPH, addNH, addCH, usePFweight;
  float iso_ch, iso_ph, iso_nh, iso_pu;
  void SetIso(float lep_pt=1.);
};

#endif
