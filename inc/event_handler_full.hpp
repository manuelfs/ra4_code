#ifndef H_EVENT_HANDLER_FULL
#define H_EVENT_HANDLER_FULL

#include <string>
#include <vector>

#include "TString.h"

#include "fastjet/ClusterSequence.hh"

#include "event_handler_base.hpp"
#include "small_tree_full.hpp"

class event_handler_full : public event_handler_base{
public:
  event_handler_full(const std::string &file_name);

  virtual void ReduceTree(int num_entries,
                          const TString &out_file_name,
                          int num_total_entries);

  virtual ~event_handler_full();

  void WriteFatJets(int &nfjets,
                    float &mj,
                    std::vector<float> &fjets_pt,
                    std::vector<float> &fjets_eta,
                    std::vector<float> &fjets_phi,
                    std::vector<float> &fjets_m,
                    std::vector<int> &fjets_nconst,
                    std::vector<float> &fjets_sumcsv,
                    std::vector<float> &fjets_poscsv,
                    std::vector<int> &fjets_btags,
                    std::vector<int> &jets_fjet_index,
                    double radius,
                    const std::vector<int> &jets,
                    bool gen = false,
                    bool clean = false,
                    const std::vector<bool> &to_clean = std::vector<bool>(0));

  void SetMiniIso(small_tree_full &tree, int ilep, int ParticleType);

  void WriteTks(small_tree_full &tree,
                const std::vector<mc_particle> &parts,
                const std::vector<size_t> &moms,
                short lepmax_chg,
                short lepmax_chg_reliso,
                const std::vector<size_t> &sigleps,
                size_t primary_lep,
                size_t primary_lep_reliso);
  unsigned TypeCode(const std::vector<mc_particle> &parts,
                    const std::vector<size_t> &moms);
  void GetTrueLeptons(std::vector<int> &true_electrons, std::vector<int> &true_muons,
		      std::vector<int> &true_had_taus, std::vector<int> &true_lep_taus);
  float GetMinMTWb(const std::vector<int> &good_jets,
                   const double pt_cut,
                   const double bTag_req,
                   const bool use_W_mass) const;

};

#endif
