// phys_objects: Class with the standard physics objects that inherits from the cfa class.
//              Reduced tree makers should inherit from this class

#ifndef H_PHYS_OBJECTS
#define H_PHYS_OBJECTS

#include <iostream>
#include <vector>
#include <string>
#include <limits>

#include "TLorentzVector.h"
#include "TMath.h"

#include "cfa.hpp"
#include "pdtlund.hpp"

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

class phys_objects : public cfa{
public:
  explicit phys_objects(const std::string &filename, bool is_8TeV=false);

  enum CutLevel{kVeto, kLoose, kMedium, kTight};

  // Muons
  std::vector<int> GetMuons(bool doSignal = true) const;

  bool IsSignalMuon(unsigned imu) const;
  bool IsVetoMuon(unsigned imu) const;
  bool IsSignalIdMuon(unsigned iel) const;
  bool IsVetoIdMuon(unsigned iel) const;

  bool IsIdMuon(unsigned imu, CutLevel threshold) const;

  float GetMuonIsolation(unsigned imu) const;

  // Electrons
  std::vector<int> GetElectrons(bool doSignal = true) const;

  bool IsSignalElectron(unsigned iel) const;
  bool IsVetoElectron(unsigned iel) const;
  bool IsSignalIdElectron(unsigned iel, bool do_iso=false) const;
  bool IsVetoIdElectron(unsigned iel, bool do_iso=false) const;

  bool IsIdElectron(unsigned iel, CutLevel threshold, bool do_iso=false) const;

  float GetElectronIsolation(unsigned iel) const;
  float GetEffectiveArea(float SCEta, bool isMC) const;

  // Leptons
  static int GetMom(float id, float mom, float gmom, float ggmom,
                    bool &fromW);
  void GetBestLepton(bool &is_muon, size_t &index);

  // Taus
  bool PassPhys14TauID(const int itau, const bool againstEMu, const bool mt_cut) const;
  // Tracks
  bool IsGoodIsoTrack(unsigned itrk, bool mt_cut) const;

  // Jets
  std::vector<int> GetJets(const std::vector<int> &VetoEl, const std::vector<int> &VetoMu,
                           double pt_thresh, double eta_thresh) const;
  bool IsGoodJet(unsigned ijet, double ptThresh, double etaThresh) const;
  bool IsBasicJet(unsigned ijet) const;

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

  // Utilities
  bool IsMC() const;
  bool hasPFMatch(int index, particleId::leptonType type, int &pfIdx) const;

  static float MinJetPt,MinSignalLeptonPt, MinVetoLeptonPt, MinTrackPt;
  static float bad_val;
};

#endif
