//Utility for finding optimal value of various isolation cuts (maximizing Z_{Bi})
//Isolation cut definitions should look like StandardCut below
//To add new definitions, add a new case in LookUpCuts and add one to cut_types
//For now, m_T cuts are included inside the isolation cut definitions

#include <cstddef>
#include <cmath>

#include <iostream>
#include <iomanip>
#include <vector>

#include "small_tree.hpp"
#include "iso_optimize.hpp"

using namespace std;

int main(){
  const size_t cut_types = 1;
  const double lumi = 5.0;

  vector<small_tree*> signals, backgrounds;
  signals.push_back(new small_tree("archive/manuel/small_SMS-T1tttt_2J_mGl-1500_mLSP-100_Tune4C_13TeV-madgraph-tauola__Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1__MINIAODSIM_v77.root"));
  backgrounds.push_back(new small_tree("archive/manuel/small_TT_Tune4C_13TeV-pythia8-tauola__Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1__MINIAODSIM_v77_files5_batch*.root"));

  vector<vector<double> > sig_counts(cut_types), back_counts(cut_types);

  GetCounts(backgrounds, lumi, cut_types, back_counts);
  GetCounts(signals, lumi, cut_types, sig_counts);

  Delete(signals);
  Delete(backgrounds);

  for(size_t itype = 0; itype < sig_counts.size(); ++itype){
    for(size_t ival = 0; ival < sig_counts.at(itype).size(); ++ival){
      const double S = sig_counts.at(itype).at(ival);
      const double B = back_counts.at(itype).at(ival);
      cout << setw(16) << itype
	   << " " << setw(16) << ival
	   << " " << setw(16) << S
	   << " " << setw(16) << B
	   << " " << setw(16) << S/sqrt(B)
	   << endl;
    }
  }
}

bool StandardCut(small_tree &tree, double /*cut_val*/){
  size_t num_sig(0), num_veto(0);
  for(size_t imu = 0; imu < tree.mus_reliso().size(); ++imu){
    if(tree.mus_reliso().at(imu)<0.2){
      ++num_veto;
      if(tree.mus_sigid().at(imu) && tree.mus_reliso().at(imu)<0.12){
        ++num_sig;
      }
    }
  }
  
  for(size_t iel = 0; iel < tree.els_reliso().size(); ++iel){
    if((tree.els_eta().at(iel)<=1.479 && tree.els_reliso().at(iel)<0.3313)
       || (tree.els_eta().at(iel)>1.479 && tree.els_reliso().at(iel)<0.3816)){
      ++num_veto;
      if(tree.els_sigid().at(iel) &&
	 ((tree.els_eta().at(iel)<=1.479 && tree.els_reliso().at(iel)<0.2179)
	  || (tree.els_eta().at(iel)>1.479 && tree.els_reliso().at(iel)<0.254))){
	++num_sig;
      }
    }
  }
  return num_sig==1 && num_veto==1;
}

bool PassBaseline(const small_tree &tree){
  return tree.nbl()>=2
    && tree.njets()>=6
    && tree.ht()>750.0
    && tree.met()>250.0;
}

void LookUpCuts(size_t iso_type,
		Cut &iso_cut,
		vector<double> &cut_vals){
  switch(iso_type){
  default:
  case 0:
    iso_cut = StandardCut;
    cut_vals = vector<double>(1, 0.0);
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
    small_tree &tree = *(samples.at(isample));
    for(long entry = 0; entry < tree.GetEntries(); ++entry){
      tree.GetEntry(entry);
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
