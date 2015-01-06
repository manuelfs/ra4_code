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
#include <algorithm>

#include "RooStats/NumberCountingUtils.h"
#include "TString.h"
#include "TH1D.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TLegend.h"
#include "TLine.h"

#include "small_tree.hpp"
#include "utilities.hpp"
#include "timer.hpp"
#include "styles.hpp"

using namespace std;

const double mtcut=100.0;

int main(){
  const size_t cut_types = 20;
  const double lumi = 5.0;

  styles style("Standard");
  style.setDefaultStyle();

  vector<small_tree*> signals, backgrounds;
  signals.push_back(new small_tree("archive/ra4skim/small_SMS-T1tttt_*-1500_*-100_*PU20bx25*.root"));
  backgrounds.push_back(new small_tree("archive/ra4skim/small_TTJets_*.root"));
  backgrounds.push_back(new small_tree("archive/ra4skim/small_QCD_*.root"));

  vector<vector<double> > sig_counts(cut_types), back_counts(cut_types);

  GetCounts(backgrounds, lumi, cut_types, back_counts);
  GetCounts(signals, lumi, cut_types, sig_counts);

  Delete(signals);
  Delete(backgrounds);

  //S and B with standard cuts
  double S = sig_counts.at(0).at(0);
  double B = back_counts.at(0).at(0);

  vector<size_t> best_cuts = GetBestCuts(sig_counts, back_counts);

  PrintDivider();
  PrintHeader();
  PrintDivider();

  for(size_t itype = 0; itype < cut_types; ++itype){
    MakePlot(itype, sig_counts, back_counts, S, B);
  }

  //Print all computed cuts
  for(size_t itype = 0; itype < sig_counts.size(); ++itype){
    Cut cut;
    vector<double> cut_vals;
    LookUpCuts(itype, cut, cut_vals);
    for(size_t ival = 0; ival < sig_counts.at(itype).size(); ++ival){
      PrintLine(itype, cut_vals.at(ival),
                sig_counts.at(itype).at(ival),
                back_counts.at(itype).at(ival),
                ival==best_cuts.at(itype));

    }
    PrintDivider();
  }
  //Print the best cuts
  PrintHeader();
  PrintDivider();
  for(size_t itype = 0; itype < sig_counts.size(); ++itype){
    Cut cut;
    std::vector<double> cut_vals;
    LookUpCuts(itype, cut, cut_vals);
    size_t ival = best_cuts.at(itype);
    PrintLine(itype, cut_vals.at(ival),
              sig_counts.at(itype).at(ival),
              back_counts.at(itype).at(ival));
  }
  PrintDivider();
}

bool StandardCut(const small_tree &tree, double /*cut_val*/){
  size_t num_sig = 0, num_veto = 0;
  int the_mu = GetStandardMuons(tree, num_sig, num_veto);
  int the_el = GetStandardElectrons(tree, num_sig, num_veto);

  return num_sig==1 && num_veto==1 && GetMT(tree, the_mu, the_el)>mtcut;
}

bool StandardPtrel(const small_tree &tree, double cut_val){
  size_t num_sig = 0, num_veto = 0;
  int the_mu = -1;
  for(size_t imu = 0; imu < tree.mus_reliso().size(); ++imu){
    if(tree.mus_reliso().at(imu)<0.2 || tree.mus_ptrel_0().at(imu)>=cut_val){
      ++num_veto;
      if(tree.mus_sigid().at(imu) && (tree.mus_reliso().at(imu)<0.12
                                      || tree.mus_ptrel_0().at(imu)>=cut_val)){
        ++num_sig;
        the_mu = imu;
      }
    }
  }

  int the_el = -1;
  for(size_t iel = 0; iel < tree.els_reliso().size(); ++iel){
    if((fabs(tree.els_eta().at(iel))<=1.479 && tree.els_reliso().at(iel)<0.3313)
       || (fabs(tree.els_eta().at(iel))>1.479 && tree.els_reliso().at(iel)<0.3816)
       || tree.els_ptrel_0().at(iel)>=cut_val){
      ++num_veto;
      if(tree.els_sigid().at(iel) &&
         ((fabs(tree.els_eta().at(iel))<=1.479 && tree.els_reliso().at(iel)<0.2179)
          || (fabs(tree.els_eta().at(iel))>1.479 && tree.els_reliso().at(iel)<0.254)
          || tree.els_ptrel_0().at(iel)>=cut_val)){
        ++num_sig;
        the_el = iel;
      }
    }
  }
  return num_sig==1 && num_veto==1 && GetMT(tree, the_mu, the_el)>mtcut;
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

  return num_sig==1 && num_veto==1 && GetMT(tree, the_mu, the_el)>mtcut;
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

  return num_sig==1 && num_veto==1 && GetMT(tree, the_mu, the_el)>mtcut;
}

bool MuonMini0201Ptrel(const small_tree &tree, double cut_val){
  size_t num_sig = 0, num_veto = 0;
  int the_mu = -1;
  for(size_t imu = 0; imu < tree.mus_miniso_tr15().size(); ++imu){
    if(tree.mus_miniso_tr15().at(imu)<0.3
       || tree.mus_reliso_r02().at(imu)<0.3
       || tree.mus_ptrel_0().at(imu)>=cut_val){
      ++num_veto;
      if(tree.mus_sigid().at(imu)){
        ++num_sig;
        the_mu = imu;
      }
    }
  }

  int the_el = GetStandardElectrons(tree, num_sig, num_veto);

  return num_sig==1 && num_veto==1 && GetMT(tree, the_mu, the_el)>mtcut;
}

bool ElectronMini0201Ptrel(const small_tree &tree, double cut_val){
  size_t num_sig = 0, num_veto = 0;
  int the_mu = GetStandardMuons(tree, num_sig, num_veto);

  int the_el = -1;
  for(size_t iel = 0; iel < tree.els_miniso_tr15().size(); ++iel){
    if(tree.els_miniso_tr15().at(iel)<0.05
       || tree.els_reliso_r02().at(iel)<0.05
       || tree.els_ptrel_0().at(iel)>=cut_val){
      ++num_veto;
      if(tree.els_sigid().at(iel)){
        ++num_sig;
        the_el = iel;
      }
    }
  }

  return num_sig==1 && num_veto==1 && GetMT(tree, the_mu, the_el)>mtcut;
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

  return num_sig==1 && num_veto==1 && GetMT(tree, the_mu, the_el)>mtcut;
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

  return num_sig==1 && num_veto==1 && GetMT(tree, the_mu, the_el)>mtcut;
}

bool MuonR0201Ptrel(const small_tree &tree, double cut_val){
  size_t num_sig = 0, num_veto = 0;
  int the_mu = -1;
  for(size_t imu = 0; imu < tree.mus_reliso_r02().size(); ++imu){
    if(tree.mus_reliso_r02().at(imu)<=0.35
       || tree.mus_ptrel_0().at(imu)>=cut_val){
      ++num_veto;
      if(tree.mus_sigid().at(imu)){
        ++num_sig;
        the_mu = imu;
      }
    }
  }

  int the_el = GetStandardElectrons(tree, num_sig, num_veto);

  return num_sig==1 && num_veto==1 && GetMT(tree, the_mu, the_el)>mtcut;
}

bool ElectronR0201Ptrel(const small_tree &tree, double cut_val){
  size_t num_sig = 0, num_veto = 0;
  int the_mu = GetStandardMuons(tree, num_sig, num_veto);

  int the_el = -1;
  for(size_t iel = 0; iel < tree.els_reliso_r02().size(); ++iel){
    if(tree.els_reliso_r02().at(iel)<=0.05
       || tree.els_ptrel_0().at(iel)>=cut_val){
      ++num_veto;
      if(tree.els_sigid().at(iel)){
        ++num_sig;
        the_el = iel;
      }
    }
  }

  return num_sig==1 && num_veto==1 && GetMT(tree, the_mu, the_el)>mtcut;
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

  return num_sig==1 && num_veto==1 && GetMT(tree, the_mu, the_el)>mtcut;
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

  return num_sig==1 && num_veto==1 && GetMT(tree, the_mu, the_el)>mtcut;
}

bool MuonR0301Ptrel(const small_tree &tree, double cut_val){
  size_t num_sig = 0, num_veto = 0;
  int the_mu = -1;
  for(size_t imu = 0; imu < tree.mus_reliso_r03().size(); ++imu){
    if(tree.mus_reliso_r03().at(imu)<=0.4
       || tree.mus_ptrel_0().at(imu)>=cut_val){
      ++num_veto;
      if(tree.mus_sigid().at(imu)){
        ++num_sig;
        the_mu = imu;
      }
    }
  }

  int the_el = GetStandardElectrons(tree, num_sig, num_veto);

  return num_sig==1 && num_veto==1 && GetMT(tree, the_mu, the_el)>mtcut;
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

  return num_sig==1 && num_veto==1 && GetMT(tree, the_mu, the_el)>mtcut;
}

bool Mini02(const small_tree &tree, double /*cut_val*/){
  size_t num_sig = 0, num_veto = 0;
  int the_mu = -1;
  for(size_t imu = 0; imu < tree.mus_miniso_tr15().size(); ++imu){
    if(tree.mus_miniso_tr15().at(imu)<=0.3 || tree.mus_reliso_r02().at(imu)<=0.3){
      ++num_veto;
      if(tree.mus_sigid().at(imu)){
        ++num_sig;
        the_mu = imu;
      }
    }
  }

  int the_el = -1;
  for(size_t iel = 0; iel < tree.els_miniso_tr15().size(); ++iel){
    if(tree.els_miniso_tr15().at(iel)<=0.05 || tree.els_reliso_r02().at(iel)<=0.05){
      ++num_veto;
      if(tree.els_sigid().at(iel)){
        ++num_sig;
        the_el = iel;
      }
    }
  }

  return num_sig==1 && num_veto==1 && GetMT(tree, the_mu, the_el)>mtcut;
}

bool Mini02Ptrel(const small_tree &tree, double /*cut_val*/){
  size_t num_sig = 0, num_veto = 0;
  int the_mu = -1;
  for(size_t imu = 0; imu < tree.mus_miniso_tr15().size(); ++imu){
    if(tree.mus_miniso_tr15().at(imu)<=0.3
       || tree.mus_reliso_r02().at(imu)<=0.3
       || tree.mus_ptrel_0().at(imu) >= 10.){
      ++num_veto;
      if(tree.mus_sigid().at(imu)){
        ++num_sig;
        the_mu = imu;
      }
    }
  }

  int the_el = -1;
  for(size_t iel = 0; iel < tree.els_miniso_tr15().size(); ++iel){
    if(tree.els_miniso_tr15().at(iel)<=0.05
       || tree.els_reliso_r02().at(iel)<=0.05
       || tree.els_ptrel_0().at(iel)>=50.0){
      ++num_veto;
      if(tree.els_sigid().at(iel)){
        ++num_sig;
        the_el = iel;
      }
    }
  }

  return num_sig==1 && num_veto==1 && GetMT(tree, the_mu, the_el)>mtcut;
}

bool R02(const small_tree &tree, double /*cut_val*/){
  size_t num_sig = 0, num_veto = 0;
  int the_mu = -1;
  for(size_t imu = 0; imu < tree.mus_reliso_r02().size(); ++imu){
    if(tree.mus_reliso_r02().at(imu)<=0.35){
      ++num_veto;
      if(tree.mus_sigid().at(imu)){
        ++num_sig;
        the_mu = imu;
      }
    }
  }

  int the_el = -1;
  for(size_t iel = 0; iel < tree.els_reliso_r02().size(); ++iel){
    if(tree.els_reliso_r02().at(iel)<=0.05){
      ++num_veto;
      if(tree.els_sigid().at(iel)){
        ++num_sig;
        the_el = iel;
      }
    }
  }

  return num_sig==1 && num_veto==1 && GetMT(tree, the_mu, the_el)>mtcut;
}

bool R02Ptrel(const small_tree &tree, double /*cut_val*/){
  size_t num_sig = 0, num_veto = 0;
  int the_mu = -1;
  for(size_t imu = 0; imu < tree.mus_reliso_r02().size(); ++imu){
    if(tree.mus_reliso_r02().at(imu)<=0.35
       || tree.mus_ptrel_0().at(imu) >= 10.){
      ++num_veto;
      if(tree.mus_sigid().at(imu)){
        ++num_sig;
        the_mu = imu;
      }
    }
  }

  int the_el = -1;
  for(size_t iel = 0; iel < tree.els_reliso_r02().size(); ++iel){
    if(tree.els_reliso_r02().at(iel)<=0.05
       || tree.els_ptrel_0().at(iel)>=25.0){
      ++num_veto;
      if(tree.els_sigid().at(iel)){
        ++num_sig;
        the_el = iel;
      }
    }
  }

  return num_sig==1 && num_veto==1 && GetMT(tree, the_mu, the_el)>mtcut;
}

bool R03(const small_tree &tree, double /*cut_val*/){
  size_t num_sig = 0, num_veto = 0;
  int the_mu = -1;
  for(size_t imu = 0; imu < tree.mus_reliso_r03().size(); ++imu){
    if(tree.mus_reliso_r03().at(imu)<=0.4){
      ++num_veto;
      if(tree.mus_sigid().at(imu)){
        ++num_sig;
        the_mu = imu;
      }
    }
  }

  int the_el = -1;
  for(size_t iel = 0; iel < tree.els_reliso_r03().size(); ++iel){
    if(tree.els_reliso_r03().at(iel)<=0.1){
      ++num_veto;
      if(tree.els_sigid().at(iel)){
        ++num_sig;
        the_el = iel;
      }
    }
  }

  return num_sig==1 && num_veto==1 && GetMT(tree, the_mu, the_el)>mtcut;
}

bool R03Ptrel(const small_tree &tree, double /*cut_val*/){
  size_t num_sig = 0, num_veto = 0;
  int the_mu = -1;
  for(size_t imu = 0; imu < tree.mus_reliso_r03().size(); ++imu){
    if(tree.mus_reliso_r03().at(imu)<=0.4
       || tree.mus_ptrel_0().at(imu) >= 8.){
      ++num_veto;
      if(tree.mus_sigid().at(imu)){
        ++num_sig;
        the_mu = imu;
      }
    }
  }

  int the_el = -1;
  for(size_t iel = 0; iel < tree.els_reliso_r03().size(); ++iel){
    if(tree.els_reliso_r03().at(iel)<=0.1
       || tree.els_ptrel_0().at(iel)>=25.0){
      ++num_veto;
      if(tree.els_sigid().at(iel)){
        ++num_sig;
        the_el = iel;
      }
    }
  }

  return num_sig==1 && num_veto==1 && GetMT(tree, the_mu, the_el)>mtcut;
}

vector<size_t> GetBestCuts(const vector<vector<double> > &sig_counts,
                           const vector<vector<double> > &back_counts){
  vector<size_t> best_cuts(sig_counts.size(), 0);
  for(size_t itype = 0; itype < sig_counts.size(); ++itype){
    double best_zbi = 0.0;
    Cut cut;
    vector<double> cut_vals;
    LookUpCuts(itype, cut, cut_vals);
    for(size_t ival = 0; ival < sig_counts.at(itype).size(); ++ival){
      double S = sig_counts.at(itype).at(ival);
      double B = back_counts.at(itype).at(ival);
      double zbi = RooStats::NumberCountingUtils::BinomialWithTauExpZ(S, B, 1000.0);
      if(zbi>best_zbi){
        best_zbi=zbi;
        best_cuts.at(itype)=ival;
      }
    }
  }
  return best_cuts;
}

void PrintHeader(){
  cout << setw(16) << "Cut Type"
       << " " << setw(16) << "Cut Value"
       << " " << setw(16) << "Signal"
       << " " << setw(16) << "Background"
       << " " << setw(16) << "S/sqrt(B)"
       << " " << setw(16) << "ZBi(tau=1)"
       << " " << setw(16) << "ZBi(tau=1000)"
       << endl;
}

void PrintLine(size_t itype, double cut_val, double S, double B, bool best){
  cout << setw(16) << itype
       << " " << fixed << setprecision(3) << setw(16) << cut_val
       << " " << setprecision(2) << setw(16) << S
       << " " << setw(16) << B
       << " " << setprecision(4) << setw(16) << (B>0?S/sqrt(B):0.0)
       << " " << setw(16) << RooStats::NumberCountingUtils::BinomialWithTauExpZ(S, B, 1.0)
       << " " << setw(16) << RooStats::NumberCountingUtils::BinomialWithTauExpZ(S, B, 1000.0);
  if(best) cout << " ***";
  cout << endl;
}

void PrintDivider(){
  for(int i=0; i<118; ++i) cout << '-';
  cout << endl;
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
  return (false || ((tree.mc_type()&0XF000)!=0x0000 || (tree.mc_type()&0xF00)==0x100))
    && tree.nbl()>=2
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
    if((fabs(tree.els_eta().at(iel))<=1.479 && tree.els_reliso().at(iel)<0.3313)
       || (fabs(tree.els_eta().at(iel))>1.479 && tree.els_reliso().at(iel)<0.3816)){
      ++num_veto;
      if(tree.els_sigid().at(iel) &&
         ((fabs(tree.els_eta().at(iel))<=1.479 && tree.els_reliso().at(iel)<0.2179)
          || (fabs(tree.els_eta().at(iel))>1.479 && tree.els_reliso().at(iel)<0.254))){
        ++num_sig;
        the_el = iel;
      }
    }
  }
  return the_el;
}

TString LookUpCuts(size_t iso_type,
                   Cut &iso_cut,
                   vector<double> &cut_vals){
  switch(iso_type){
  default:
  case 0:
    iso_cut = StandardCut;
    cut_vals = LinearSpacing(1, 0., 0.);
    return "Rel. Iso.";
  case 1:
    iso_cut = StandardPtrel;
    cut_vals = LinearSpacing(101, 0., 100.);
    return "Standard Rel. Iso. OR p_{T,rel}";
  case 2:
    iso_cut = MuonMini02;
    cut_vals = LinearSpacing(101, 0., 2.0);
    return "Muon Mini Iso.";
  case 3:
    iso_cut = ElectronMini02;
    cut_vals = LinearSpacing(101, 0., 2.0);
    return "Electron Mini Iso.";
  case 4:
    iso_cut = MuonMini0201Ptrel;
    cut_vals = LinearSpacing(101, 0., 100.);
    return "Muon Mini Iso<0.3 OR p_{T,rel}";
  case 5:
    iso_cut = ElectronMini0201Ptrel;
    cut_vals = LinearSpacing(101, 0., 100.);
    return "Electron Mini Iso<0.05 OR p_{T,rel}";
  case 6:
    iso_cut = MuonR02;
    cut_vals = LinearSpacing(101, 0., 2.0);
    return "Muon Rel. Iso. (R=0.2)";
  case 7:
    iso_cut = ElectronR02;
    cut_vals = LinearSpacing(101, 0., 2.0);
    return "Electron Rel. Iso. (R=0.2)";
  case 8:
    iso_cut = MuonR0201Ptrel;
    cut_vals = LinearSpacing(101, 0., 100.);
    return "Muon Rel. Iso. (R=0.2)<0.35 OR p_{T,rel}";
  case 9:
    iso_cut = ElectronR0201Ptrel;
    cut_vals = LinearSpacing(101, 0., 100.);
    return "Electron Rel. Iso. (R=0.2)<0.05 OR p_{T,rel}";
  case 10:
    iso_cut = MuonR03;
    cut_vals = LinearSpacing(101, 0., 2.0);
    return "Muon Rel. Iso. (R=0.3)";
  case 11:
    iso_cut = ElectronR03;
    cut_vals = LinearSpacing(101, 0., 2.0);
    return "Electron Rel. Iso. (R=0.3)";
  case 12:
    iso_cut = MuonR0301Ptrel;
    cut_vals = LinearSpacing(101, 0., 100.);
    return "Muon Rel. Iso. (R=0.3)<0.4 OR p_{T,rel}";
  case 13:
    iso_cut = ElectronR0301Ptrel;
    cut_vals = LinearSpacing(101, 0., 100.);
    return "Electron Rel. Iso. (R=0.3)<0.1 OR p_{T,rel}";
  case 14:
    iso_cut = Mini02;
    cut_vals = LinearSpacing(1, 0., 0.);
    return "Mini Iso.";
  case 15:
    iso_cut = Mini02Ptrel;
    cut_vals = LinearSpacing(1, 0., 0.);
    return "Mini Iso. OR p_{T,rel}";
  case 16:
    iso_cut = R02;
    cut_vals = LinearSpacing(1, 0., 0.);
    return "Rel. Iso. (R=0.2)";
  case 17:
    iso_cut = R02Ptrel;
    cut_vals = LinearSpacing(1, 0., 0.);
    return "Rel. Iso. (R=0.2) OR p_{T,rel}";
  case 18:
    iso_cut = R03;
    cut_vals = LinearSpacing(1, 0., 0.);
    return "Rel. Iso. (R=0.3)";
  case 19:
    iso_cut = R03Ptrel;
    cut_vals = LinearSpacing(1, 0., 0.);
    return "Rel. Iso. (R=0.3) OR p_{T,rel}";
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

void MakePlot(size_t itype, vector<vector<double> > &sig_counts,
              vector<vector<double> > &back_counts,
              double SS, double BB){
  Cut cut;
  vector<double> cut_vals;
  TString cut_name = LookUpCuts(itype, cut, cut_vals);

  vector<double> zbi1000(cut_vals.size()), zbi1(cut_vals.size()), sb(cut_vals.size());
  for(size_t ival = 0; ival < cut_vals.size(); ++ival){
    double S = sig_counts.at(itype).at(ival);
    double B = back_counts.at(itype).at(ival);
    zbi1000.at(ival) = RooStats::NumberCountingUtils::BinomialWithTauExpZ(S, B, 1000.);
    zbi1.at(ival) = RooStats::NumberCountingUtils::BinomialWithTauExpZ(S, B, 1.);
    sb.at(ival) = B>0?S/sqrt(B):0.;
  }
  double szbi1000 = RooStats::NumberCountingUtils::BinomialWithTauExpZ(SS, BB, 1000.);
  double szbi1 = RooStats::NumberCountingUtils::BinomialWithTauExpZ(SS, BB, 1.);
  double ssb = BB>0?SS/sqrt(BB):0.;

  double left = *min_element(cut_vals.begin(), cut_vals.end());
  double right = *max_element(cut_vals.begin(), cut_vals.end());
  double up = *max_element(zbi1000.begin(), zbi1000.end());
  up = max(up, *max_element(sb.begin(), sb.end()));

  TGraph gzbi1000(cut_vals.size(), &cut_vals.at(0), &zbi1000.at(0));
  TGraph gzbi1(cut_vals.size(), &cut_vals.at(0), &zbi1.at(0));
  TGraph gsb(cut_vals.size(), &cut_vals.at(0), &sb.at(0));

  TLine lzbi1000(left, szbi1000, right, szbi1000);
  TLine lzbi1(left, szbi1, right, szbi1);
  TLine lsb(left, ssb, right, ssb);

  gzbi1000.SetLineStyle(1);
  gzbi1.SetLineStyle(2);
  gsb.SetLineStyle(3);
  lzbi1000.SetLineStyle(1);
  lzbi1.SetLineStyle(2);
  lsb.SetLineStyle(3);

  gzbi1000.SetLineWidth(5);
  gzbi1.SetLineWidth(5);
  gsb.SetLineWidth(5);
  lzbi1000.SetLineWidth(5);
  lzbi1.SetLineWidth(5);
  lsb.SetLineWidth(5);

  gzbi1000.SetLineColor(2);
  gzbi1.SetLineColor(2);
  gsb.SetLineColor(2);
  lzbi1000.SetLineColor(1);
  lzbi1.SetLineColor(1);
  lsb.SetLineColor(1);

  TString title=";";
  title+=cut_name+";Z_{Bi}";
  TH1D h("",title,1,left,right);
  h.SetMinimum(0.);
  h.SetMaximum(up);

  TCanvas c;
  c.SetGrid();
  h.Draw();
  gzbi1000.Draw("samel");
  gzbi1.Draw("samel");
  gsb.Draw("samel");
  lzbi1000.Draw("samel");
  lzbi1.Draw("samel");
  lsb.Draw("samel");
  TLegend l(0.662,0.12,0.962,0.32);
  l.AddEntry(&gzbi1000, "Z_{Bi}(#tau=1000)", "l");
  l.AddEntry(&gzbi1, "Z_{Bi}(#tau=1)", "l");
  l.AddEntry(&gsb, "S/#sqrt{B}", "l");
  l.Draw("same");
  TString out="eps/zbi_"+TString::Itoa(itype,10)+"_baseline.eps";
  c.Print(out);
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
