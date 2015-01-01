//Utility for finding optimal value of various isolation cuts (maximizing Z_{Bi})
//Isolation cut definitions should look like StandardCut below
//To add new definitions, add a new case in LookUpCuts and add one to cut_types
//For now, m_T cuts are included inside the isolation cut definitions

#include "iso_optimize.hpp"

#include <cstddef>
#include <cmath>

#include <iostream>
#include <iomanip>
#include <vector>

#include "RooStats/NumberCountingUtils.h"

#include "small_tree.hpp"
#include "utilities.hpp"
#include "timer.hpp"

using namespace std;

int main(){
  const size_t cut_types = 13;
  const double lumi = 5.0;

  vector<small_tree*> signals, backgrounds;
  signals.push_back(new small_tree("archive/ra4skim/small_SMS-T1tttt_*-1500_*-100_*PU20bx25*.root"));
  backgrounds.push_back(new small_tree("archive/ra4skim/small_TTJets_*.root"));
  backgrounds.push_back(new small_tree("archive/ra4skim/small_QCD_*.root"));

  vector<vector<double> > sig_counts(cut_types), back_counts(cut_types);

  GetCounts(backgrounds, lumi, cut_types, back_counts);
  GetCounts(signals, lumi, cut_types, sig_counts);

  Delete(signals);
  Delete(backgrounds);

  cout << setw(16) << "Cut Type"
       << " " << setw(16) << "Cut Value"
       << " " << setw(16) << "Signal"
       << " " << setw(16) << "Background"
       << " " << setw(16) << "S/sqrt(B)"
       << " " << setw(16) << "Z_{Bi}"
       << endl;
  for(int i=0; i<101; ++i) cout << '-';
  cout << endl;
  for(size_t itype = 0; itype < sig_counts.size(); ++itype){
    Cut cut;
    std::vector<double> cut_vals;
    LookUpCuts(itype, cut, cut_vals);
    for(size_t ival = 0; ival < sig_counts.at(itype).size(); ++ival){
      const double S = sig_counts.at(itype).at(ival);
      const double B = back_counts.at(itype).at(ival);
      cout << setw(16) << itype
           << " " << fixed << setprecision(3) << setw(16) << cut_vals.at(ival)
           << " " << setprecision(2) << setw(16) << S
           << " " << setw(16) << B
           << " " << setprecision(4) << setw(16) << S/sqrt(B)
           << " " << setw(16) << RooStats::NumberCountingUtils::BinomialWithTauExpZ(S, B, 1.0)
           << endl;
    }
    for(int i=0; i<101; ++i) cout << '-';
    cout << endl;
  }
}

bool StandardCut(const small_tree &tree, double /*cut_val*/){
  size_t num_sig = 0, num_veto = 0;
  int the_mu = GetStandardMuons(tree, num_sig, num_veto);
  int the_el = GetStandardElectrons(tree, num_sig, num_veto);

  return num_sig==1 && num_veto==1 && GetMT(tree, the_mu, the_el)>100.0;
}

bool MuonMini02(const small_tree &tree, double cut_val){
  size_t num_sig = 0, num_veto = 0;
  int the_mu = -1;
  for(size_t imu = 0; imu < tree.mus_miniso_tr15().size(); ++imu){
    if(tree.mus_miniso_tr15().at(imu)<=cut_val || tree.mus_reliso_r02().at(imu)<=cut_val){
      ++num_veto;
      if(tree.mus_sigid().at(imu)){
        ++num_sig;
        the_mu = imu;
      }
    }
  }

  int the_el = GetStandardElectrons(tree, num_sig, num_veto);  

  return num_sig==1 && num_veto==1 && GetMT(tree, the_mu, the_el)>100.0;
}

bool ElectronMini02(const small_tree &tree, double cut_val){
  size_t num_sig = 0, num_veto = 0;
  int the_mu = GetStandardMuons(tree, num_sig, num_veto);

  int the_el = -1;  
  for(size_t iel = 0; iel < tree.els_miniso_tr15().size(); ++iel){
    if(tree.els_miniso_tr15().at(iel)<=cut_val || tree.els_reliso_r02().at(iel)<=cut_val){
      ++num_veto;
      if(tree.els_sigid().at(iel)){
        ++num_sig;
        the_el = iel;
      }
    }
  }

  return num_sig==1 && num_veto==1 && GetMT(tree, the_mu, the_el)>100.0;
}

bool MuonMini0201Ptrel(const small_tree &tree, double cut_val){
  size_t num_sig = 0, num_veto = 0;
  int the_mu = -1;
  for(size_t imu = 0; imu < tree.mus_miniso_tr15().size(); ++imu){
    if(tree.mus_miniso_tr15().at(imu)<0.1
       || tree.mus_reliso_r02().at(imu)<0.1
       || tree.mus_ptrel_0().at(imu)>=cut_val){
      ++num_veto;
      if(tree.mus_sigid().at(imu)){
        ++num_sig;
        the_mu = imu;
      }
    }
  }

  int the_el = GetStandardElectrons(tree, num_sig, num_veto);  

  return num_sig==1 && num_veto==1 && GetMT(tree, the_mu, the_el)>100.0;
}

bool ElectronMini0201Ptrel(const small_tree &tree, double cut_val){
  size_t num_sig = 0, num_veto = 0;
  int the_mu = GetStandardMuons(tree, num_sig, num_veto);

  int the_el = -1;  
  for(size_t iel = 0; iel < tree.els_miniso_tr15().size(); ++iel){
    if(tree.els_miniso_tr15().at(iel)<0.1
       || tree.els_reliso_r02().at(iel)<0.1
       || tree.els_ptrel_0().at(iel)>=cut_val){
      ++num_veto;
      if(tree.els_sigid().at(iel)){
        ++num_sig;
        the_el = iel;
      }
    }
  }

  return num_sig==1 && num_veto==1 && GetMT(tree, the_mu, the_el)>100.0;
}

bool MuonR02(const small_tree &tree, double cut_val){
  size_t num_sig = 0, num_veto = 0;
  int the_mu = -1;
  for(size_t imu = 0; imu < tree.mus_reliso_r02().size(); ++imu){
    if(tree.mus_reliso_r02().at(imu)<=cut_val){
      ++num_veto;
      if(tree.mus_sigid().at(imu)){
        ++num_sig;
        the_mu = imu;
      }
    }
  }

  int the_el = GetStandardElectrons(tree, num_sig, num_veto);  

  return num_sig==1 && num_veto==1 && GetMT(tree, the_mu, the_el)>100.0;
}

bool ElectronR02(const small_tree &tree, double cut_val){
  size_t num_sig = 0, num_veto = 0;
  int the_mu = GetStandardMuons(tree, num_sig, num_veto);

  int the_el = -1;  
  for(size_t iel = 0; iel < tree.els_reliso_r02().size(); ++iel){
    if(tree.els_reliso_r02().at(iel)<=cut_val){
      ++num_veto;
      if(tree.els_sigid().at(iel)){
        ++num_sig;
        the_el = iel;
      }
    }
  }

  return num_sig==1 && num_veto==1 && GetMT(tree, the_mu, the_el)>100.0;
}

bool MuonR0201Ptrel(const small_tree &tree, double cut_val){
  size_t num_sig = 0, num_veto = 0;
  int the_mu = -1;
  for(size_t imu = 0; imu < tree.mus_reliso_r02().size(); ++imu){
    if(tree.mus_reliso_r02().at(imu)<=0.1
       || tree.mus_ptrel_0().at(imu)>=cut_val){
      ++num_veto;
      if(tree.mus_sigid().at(imu)){
        ++num_sig;
        the_mu = imu;
      }
    }
  }

  int the_el = GetStandardElectrons(tree, num_sig, num_veto);  

  return num_sig==1 && num_veto==1 && GetMT(tree, the_mu, the_el)>100.0;
}

bool ElectronR0201Ptrel(const small_tree &tree, double cut_val){
  size_t num_sig = 0, num_veto = 0;
  int the_mu = GetStandardMuons(tree, num_sig, num_veto);

  int the_el = -1;  
  for(size_t iel = 0; iel < tree.els_reliso_r02().size(); ++iel){
    if(tree.els_reliso_r02().at(iel)<=0.1
       || tree.els_ptrel_0().at(iel)>=cut_val){
      ++num_veto;
      if(tree.els_sigid().at(iel)){
        ++num_sig;
        the_el = iel;
      }
    }
  }

  return num_sig==1 && num_veto==1 && GetMT(tree, the_mu, the_el)>100.0;
}

bool MuonR03(const small_tree &tree, double cut_val){
  size_t num_sig = 0, num_veto = 0;
  int the_mu = -1;
  for(size_t imu = 0; imu < tree.mus_reliso_r03().size(); ++imu){
    if(tree.mus_reliso_r03().at(imu)<=cut_val){
      ++num_veto;
      if(tree.mus_sigid().at(imu)){
        ++num_sig;
        the_mu = imu;
      }
    }
  }

  int the_el = GetStandardElectrons(tree, num_sig, num_veto);  

  return num_sig==1 && num_veto==1 && GetMT(tree, the_mu, the_el)>100.0;
}

bool ElectronR03(const small_tree &tree, double cut_val){
  size_t num_sig = 0, num_veto = 0;
  int the_mu = GetStandardMuons(tree, num_sig, num_veto);

  int the_el = -1;  
  for(size_t iel = 0; iel < tree.els_reliso_r03().size(); ++iel){
    if(tree.els_reliso_r03().at(iel)<=cut_val){
      ++num_veto;
      if(tree.els_sigid().at(iel)){
        ++num_sig;
        the_el = iel;
      }
    }
  }

  return num_sig==1 && num_veto==1 && GetMT(tree, the_mu, the_el)>100.0;
}

bool MuonR0301Ptrel(const small_tree &tree, double cut_val){
  size_t num_sig = 0, num_veto = 0;
  int the_mu = -1;
  for(size_t imu = 0; imu < tree.mus_reliso_r03().size(); ++imu){
    if(tree.mus_reliso_r03().at(imu)<=0.1
       || tree.mus_ptrel_0().at(imu)>=cut_val){
      ++num_veto;
      if(tree.mus_sigid().at(imu)){
        ++num_sig;
        the_mu = imu;
      }
    }
  }

  int the_el = GetStandardElectrons(tree, num_sig, num_veto);  

  return num_sig==1 && num_veto==1 && GetMT(tree, the_mu, the_el)>100.0;
}

bool ElectronR0301Ptrel(const small_tree &tree, double cut_val){
  size_t num_sig = 0, num_veto = 0;
  int the_mu = GetStandardMuons(tree, num_sig, num_veto);

  int the_el = -1;  
  for(size_t iel = 0; iel < tree.els_reliso_r03().size(); ++iel){
    if(tree.els_reliso_r03().at(iel)<=0.1
       || tree.els_ptrel_0().at(iel)>=cut_val){
      ++num_veto;
      if(tree.els_sigid().at(iel)){
        ++num_sig;
        the_el = iel;
      }
    }
  }

  return num_sig==1 && num_veto==1 && GetMT(tree, the_mu, the_el)>100.0;
}

double GetMT(const small_tree &tree,
             long mu, long el){
  if(mu>=0){
    return GetMT(0.0,
                 tree.mus_pt().at(mu)*cos(tree.mus_phi().at(mu)),
                 tree.mus_pt().at(mu)*sin(tree.mus_phi().at(mu)),
                 0.0,
                 tree.met()*cos(tree.met_phi()),
                 tree.met()*sin(tree.met_phi()));
  }else{
    return GetMT(0.0,
                 tree.els_pt().at(el)*cos(tree.els_phi().at(el)),
                 tree.els_pt().at(el)*sin(tree.els_phi().at(el)),
                 0.0,
                 tree.met()*cos(tree.met_phi()),
                 tree.met()*sin(tree.met_phi()));
  }
}

bool PassBaseline(const small_tree &tree){
  return tree.nbl()>=2
    && tree.njets()>=6
    && tree.ht()>750.0
    && tree.met()>250.0;
}

int GetStandardMuons(const small_tree &tree, size_t &num_sig, size_t &num_veto){
  int the_mu = -1;
  for(size_t imu = 0; imu < tree.mus_reliso().size(); ++imu){
    if(tree.mus_reliso().at(imu)<0.2){
      ++num_veto;
      if(tree.mus_sigid().at(imu) && tree.mus_reliso().at(imu)<0.12){
        ++num_sig;
        the_mu = imu;
      }
    }
  }
  return the_mu;
}

int GetStandardElectrons(const small_tree &tree, size_t &num_sig, size_t &num_veto){
  int the_el = -1;
  for(size_t iel = 0; iel < tree.els_reliso().size(); ++iel){
    if((tree.els_eta().at(iel)<=1.479 && tree.els_reliso().at(iel)<0.3313)
       || (tree.els_eta().at(iel)>1.479 && tree.els_reliso().at(iel)<0.3816)){
      ++num_veto;
      if(tree.els_sigid().at(iel) &&
         ((tree.els_eta().at(iel)<=1.479 && tree.els_reliso().at(iel)<0.2179)
          || (tree.els_eta().at(iel)>1.479 && tree.els_reliso().at(iel)<0.254))){
        ++num_sig;
        the_el = iel;
      }
    }
  }
  return the_el;
}

void LookUpCuts(size_t iso_type,
                Cut &iso_cut,
                vector<double> &cut_vals){
  switch(iso_type){
  default:
  case 0:
    iso_cut = StandardCut;
    cut_vals = LinearSpacing(1, 0., 0.);
    break;
  case 1:
    iso_cut = MuonMini02;
    cut_vals = LinearSpacing(11, 0., 0.5);
    break;
  case 2:
    iso_cut = ElectronMini02;
    cut_vals = LinearSpacing(11, 0., 0.5);
    break;
  case 3:
    iso_cut = MuonMini0201Ptrel;
    cut_vals = LinearSpacing(11, 0., 50.);
    break;
  case 4:
    iso_cut = ElectronMini0201Ptrel;
    cut_vals = LinearSpacing(11, 0., 50.);
    break;
  case 5:
    iso_cut = MuonR02;
    cut_vals = LinearSpacing(11, 0., 0.5);
    break;
  case 6:
    iso_cut = ElectronR02;
    cut_vals = LinearSpacing(11, 0., 0.5);
    break;
  case 7:
    iso_cut = MuonR0201Ptrel;
    cut_vals = LinearSpacing(11, 0., 50.);
    break;
  case 8:
    iso_cut = ElectronR0201Ptrel;
    cut_vals = LinearSpacing(11, 0., 50.);
    break;
  case 9:
    iso_cut = MuonR03;
    cut_vals = LinearSpacing(11, 0., 0.5);
    break;
  case 10:
    iso_cut = ElectronR03;
    cut_vals = LinearSpacing(11, 0., 0.5);
    break;
  case 11:
    iso_cut = MuonR0301Ptrel;
    cut_vals = LinearSpacing(11, 0., 50.);
    break;
  case 12:
    iso_cut = ElectronR0301Ptrel;
    cut_vals = LinearSpacing(11, 0., 50.);
    break;
  }
}

void GetCounts(vector<small_tree*> &samples,
               double lumi,
               size_t cut_types,
               vector<vector<double> > &counts){
  for(size_t iso_type = 0; iso_type < cut_types; ++iso_type){
    Cut iso_cut = NULL;
    vector<double> cut_vals;
    LookUpCuts(iso_type, iso_cut, cut_vals);
    counts.at(iso_type) = vector<double>(cut_vals.size(), 0.0);
  }
  for(size_t isample = 0; isample < samples.size(); ++isample){
    cout << "Processing sample " << (isample+1) << " of " << samples.size() << '.' << endl;
    small_tree &tree = *(samples.at(isample));
    long nentries = tree.GetEntries();
    Timer timer(nentries);
    timer.Start();
    for(long entry = 0; entry < nentries; ++entry){
      tree.GetEntry(entry);
      if(entry%1000000==0 && entry!=0){
        timer.PrintRemainingTime();
      }
      timer.Iterate();
      if(!PassBaseline(tree)) continue;
      for(size_t iso_type = 0; iso_type < cut_types; ++iso_type){
        Cut iso_cut = NULL;
        vector<double> cut_vals;
        LookUpCuts(iso_type, iso_cut, cut_vals);
        
        for(size_t icut = 0; icut < cut_vals.size(); ++icut){
          if(iso_cut(tree, cut_vals.at(icut))){
            counts.at(iso_type).at(icut)+=lumi*tree.weight();
          }
        }
      }
    }
  }
}

void Delete(vector<small_tree*> &trees){
  for(vector<small_tree*>::iterator it = trees.begin();
      it != trees.end();
      ++it){
    if(*it){
      delete *it;
      *it = NULL;
    }
  }
  trees.clear();
}
