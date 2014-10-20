// ra4_objects: Class with the standard RA4 physics objects that inherits from the cfa class. 
//              Reduced tree makers should inherit from this class

#ifndef H_RA4_OBJECTS
#define H_RA4_OBJECTS

#include <iostream>
#include <vector>
#include <string>
#include "cfa.hpp"


class ra4_objects : public cfa{
public:
  explicit ra4_objects(const std::string &filename, const bool is_8TeV=false);

  // Muons
  std::vector<int> GetMuons(bool doSignal = true);
  bool IsSignalMuon(uint imu);
  bool IsVetoMuon(uint imu);
  bool IsBasicMuon(uint iel);
  float GetMuonIsolation(uint imu);

  // Electrons
  std::vector<int> GetElectrons(bool doSignal = true);
  bool IsSignalElectron(uint iel);
  bool IsVetoElectron(uint iel);
  bool IsBasicElectron(uint iel);
  float GetElectronIsolation(uint iel);

  // Jets
  std::vector<int> GetJets(std::vector<int> SigEl, std::vector<int> SigMu, 
                           std::vector<int> VetoEl, std::vector<int> VetoMu, float &HT);
  bool IsGoodJet(const unsigned int ijet, const double ptThresh, const double etaThresh) const;
  bool IsBasicJet(const unsigned int ijet) const;

  // Truth matching
  int GetTrueElectron(int index, int &momID, double &closest_dR);
  int GetTrueMuon(int index, int &momID, double &closest_dR);
  int GetTrueParticle(double RecEta, double RecPhi, double &closest_dR);

  // Event cleaning
  bool PassesMETCleaningCut() const;
  bool PassesPVCut() const;
  double getDZ(double vx, double vy, double vz, double px, double py, double pz, int firstGoodVertex);

  //Event variables
  double getDeltaPhiMETN(unsigned int goodJetI, float otherpt, float othereta, bool useArcsin);
  double getDeltaPhiMETN_deltaT(unsigned int goodJetI, float otherpt, float othereta);
  double getMinDeltaPhiMETN(unsigned int maxjets, float mainpt, float maineta,
                            float otherpt, float othereta, bool useArcsin);
};

#endif
