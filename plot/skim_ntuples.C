// skim_ntuples.C: Skims reduced trees

#define INT_ROOT
#include "inc/utilities.hpp"
#include "src/utilities.cpp"

#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include "TChain.h"
#include "TFile.h"
#include "TString.h"
#include "TMath.h"
#include "TSystem.h"

using namespace std;
using std::cout;
using std::endl;

void skim_ntuples(){
  TString outfolder="archive/ra4skim2/", infolder = "archive/";
  gSystem->mkdir(outfolder, kTRUE);
  TString cuts = "nleps==1";

  vector<TString> files = dirlist(infolder, ".root");

  for(unsigned file(0); file < files.size(); file++){
    TChain tree("tree"); 
    tree.Add(infolder+files[file]); 

    TTree *ctree = tree.CopyTree(cuts);
    ctree->SaveAs(outfolder+files[file]);
    delete ctree;
  }


}

