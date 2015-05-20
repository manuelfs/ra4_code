// phys_objects: Class with the standard physics objects that inherits from the cfa class.
//              Reduced tree makers should inherit from this class

#ifndef H_PHYS_OBJECTS
#define H_PHYS_OBJECTS

#include <cstdlib>

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <map>

#include "TLorentzVector.h"
#include "TMath.h"

#include "cfa.hpp"
#include "pdtlund.hpp"

struct Jet{
  TLorentzVector p4;
  float csv;
  int id;
  int nleps;
  TLorentzVector p4sub;
  float mindr;
};

namespace particleId {
  enum leptonType {
    X=0,
    electron=2,
    muon=3,
    electronVeto=4,
    muonVeto=5
  };
}

struct mc_particle{
  mc_particle(const TLorentzVector &momentum,
              float charge,
              int id, int mom, int gmom, int ggmom,
              int status):
    momentum_(momentum),
    charge_(TMath::Nint(3.*charge)),
    id_(id),
    mom_(mom),
    gmom_(gmom),
    ggmom_(ggmom),
    status_(status){
  }

  TLorentzVector momentum_;
  float charge_;
  int id_, mom_, gmom_, ggmom_;
  int status_;
};

class FactorizedJetCorrector;

class phys_objects : public cfa{
public:
  explicit phys_objects(const std::string &filename, bool is_8TeV=false);
  virtual ~phys_objects();

  enum CutLevel{kVeto, kLoose, kMedium, kTight};

  virtual void GetEntry(const long entry);

  // Muons
  std::vector<int> GetMuons(bool doSignal = true, bool mini = true) const;

  bool IsSignalMuon(unsigned imu, bool mini = true) const;
  bool IsVetoMuon(unsigned imu, bool mini = true) const;
  bool IsSignalIdMuon(unsigned iel) const;
  bool IsVetoIdMuon(unsigned iel) const;

  bool IsIdMuon(unsigned imu, CutLevel threshold) const;

  float GetMuonIsolation(unsigned imu, bool mini=true) const;

  // Electrons
  std::vector<int> GetElectrons(bool doSignal = true, bool mini = true) const;

  bool IsSignalElectron(unsigned iel, bool mini = true) const;
  bool IsVetoElectron(unsigned iel, bool mini = true) const;
  bool IsSignalIdElectron(unsigned iel, bool do_iso=false) const;
  bool IsVetoIdElectron(unsigned iel, bool do_iso=false) const;

  bool IsIdElectron(unsigned iel, CutLevel threshold, bool do_iso=false) const;

  float GetElectronIsolation(unsigned iel, bool mini=true) const;
  float GetEffectiveArea(float SCEta, bool isMC) const;

  // Leptons
  static int GetMom(float id, float mom, float gmom, float ggmom,
                    bool &fromW);
  void GetBestLepton(bool &is_muon, size_t &index);
  double GetMiniIsolation(int particle_type, int ilep, double riso_min = 0.05, double riso_max = 0.2,
                          bool add_ph = true, bool add_nh = true, bool add_ch = true,
                          bool use_pf_weight = false, double kt_scale = 10.) const;

  // Taus
  bool PassPhys14TauID(const int itau, const bool againstEMu, const bool mt_cut) const;
  // Tracks
  bool IsGoodIsoTrack(unsigned itrk, bool mt_cut) const;

  // MET
  float met_corr() const;
  float met_phi_corr() const;

  // Jets
  std::vector<int> GetJets(const std::vector<int> &VetoEl, const std::vector<int> &VetoMu,
                           double pt_thresh, double eta_thresh) const;
  void GetMatchedLeptons(const std::vector<int> &veto_mu,
                         const std::vector<int> &veto_el,
                         std::map<size_t,std::vector<size_t> > &mu_matches,
                         std::map<size_t,std::vector<size_t> > &el_matches) const;

  std::vector<Jet> GetSubtractedJets(const std::vector<int> &veto_el, const std::vector<int> &veto_mu,
                                     double pt_thresh, double eta_thresh) const;
  bool IsGoodJet(unsigned ijet, double ptThresh, double etaThresh) const;
  bool IsBasicJet(unsigned ijet) const;
  const std::vector<TLorentzVector> & jets_corr_p4() const;
  std::vector<TLorentzVector> & jets_corr_p4();

  // Truth matching
  int GetTrueElectron(int index, int &momID, bool &fromW, float &closest_dR) const;
  int GetTrueMuon(int index, int &momID, bool &fromW, float &closest_dR) const;
  int GetTrueParticle(float RecPt, float RecEta, float RecPhi, float &closest_dR, int ID) const;
  std::vector<mc_particle> GetMCParticles() const;
  size_t MatchCandToStatus1(size_t icand,
                            const std::vector<mc_particle> &parts) const;
  static size_t GetMom(size_t index, const std::vector<mc_particle> &parts);
  static std::vector<size_t> GetMoms(const std::vector<mc_particle> &parts);
  static bool IsBrem(size_t index,
                     const std::vector<mc_particle> &parts,
                     const std::vector<size_t> &moms);
  static bool FromStatus23(size_t index,
                           const std::vector<mc_particle> &parts,
                           const std::vector<size_t> &moms);
  static bool FromTop(size_t index,
                      const std::vector<mc_particle> &parts,
                      const std::vector<size_t> &moms);
  static bool FromW(size_t index,
                    const std::vector<mc_particle> &parts,
                    const std::vector<size_t> &moms);
  static bool FromTau(size_t index,
                      const std::vector<mc_particle> &parts,
                      const std::vector<size_t> &moms);
  static bool FromTauLep(size_t index,
                         const std::vector<mc_particle> &parts,
                         const std::vector<size_t> &moms);
  static unsigned NumChildren(size_t index,
                              const std::vector<mc_particle> &parts,
                              const std::vector<size_t> &moms,
                              bool req_chg=false);
  static unsigned NumDescendants(size_t index,
                                 const std::vector<mc_particle> &parts,
                                 const std::vector<size_t> &moms,
                                 bool req_chg=false);
  static bool IsDescendantOf(size_t descendant, size_t ancestor,
                             const std::vector<size_t> &moms);
  static unsigned ParentTauDescendants(size_t index,
                                       const std::vector<mc_particle> &parts,
                                       const std::vector<size_t> &moms);
  static size_t ParentW(size_t index,
                        const std::vector<mc_particle> &parts,
                        const std::vector<size_t> &moms);
  static size_t ParentTau(size_t index,
                          const std::vector<mc_particle> &parts,
                          const std::vector<size_t> &moms);
  static void CountLeptons(const std::vector<mc_particle> &parts,
                           const std::vector<size_t> &moms,
                           unsigned &nleps,
                           unsigned &ntaus,
                           unsigned &ntauleps);

  // Event cleaning
  bool PassesMETCleaningCut() const;
  bool PassesPVCut() const;
  double getDZ(double vx, double vy, double vz, double px, double py, double pz, int firstGoodVertex) const;

  // Event variables
  long double SumDeltaPhi(long double phi_x, long double phi_a, long double phi_b);
  double GetDeltaPhiMETN(unsigned goodJetI, float otherpt, float othereta, bool useArcsin) const;
  double GetDeltaPhiMETN_deltaT(unsigned goodJetI, float otherpt, float othereta) const;
  double GetMinDeltaPhiMETN(unsigned maxjets, float mainpt, float maineta,
                            float otherpt, float othereta, bool useArcsin) const;
  double GetHT(const std::vector<int> &good_jets, double pt_cut=0.0) const;
  double GetMHT(const std::vector<int> &good_jets, double pt_cut) const;
  size_t GetNumJets(const std::vector<int> &good_jets,
                    double pt_cut=0.0,
                    double csv_cut=-std::numeric_limits<float>::max()) const;
  static double GetSphericity(const std::vector<TLorentzVector> &vs);

  // Utilities
  bool IsMC() const;
  bool hasPFMatch(int index, particleId::leptonType type, int &pfIdx) const;

  void GetLeadingBJets(const std::vector<int> &good_jets,
                       double pt_cut, double csv_cut,
                       size_t &lead, size_t &sub);

  static float MinJetPt, MinRA2bJetPt, MinSignalLeptonPt, MinVetoLeptonPt, MinTrackPt;
  static float bad_val;

  template<class T>
  T chooseVal(CutLevel threshold, T valVeto, T valLoose, T valMedium, T valTight) const{
   switch(threshold){
   default:
   case kVeto:
     return valVeto;
   case kLoose:
     return valLoose;
   case kMedium:
     return valMedium;
   case kTight:
     return valTight;
   }
   return valVeto;
 }


private:
  FactorizedJetCorrector *jet_corrector_;
  mutable std::vector<TLorentzVector> jets_corr_p4_;
  mutable bool set_jets_;
  mutable float met_corr_, met_phi_corr_;

  void CorrectJets() const;
};

#endif
