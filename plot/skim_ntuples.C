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
#include "TDirectory.h"

using namespace std;
using std::cout;
using std::endl;

void skim_ntuples(){
  TString outfolder="archive/ra4skim/", infolder = "archive/14-10-18/";
  gSystem->mkdir(outfolder, kTRUE);
  TString cuts = "nleps==1";

  vector<TString> files = dirlist(infolder, ".root");

  for(unsigned file(0); file < files.size(); file++){
    TFile out_file(outfolder+files[file], "RECREATE");
    out_file.cd();
    TChain tree("tree"); 
    tree.Add(infolder+files[file]); 

    TTree *ctree = tree.CopyTree(cuts);
    ctree->Write();
    out_file.Close();
    cout<<"Written "<<outfolder+files[file]<<endl;
  }

}

void skim_one(TString file){
  TFile fin(file);
  fin.cd("cfA");
  TTree *eventA = (TTree*)gDirectory->Get("eventA");
  TTree *eventB = (TTree*)gDirectory->Get("eventB");
  TTree *eA(eventA->CloneTree(0));
  TTree *eB(eventB->CloneTree(0));

  TString outname="cfa_one.root";
  TFile fout(outname, "RECREATE");
  fout.mkdir("cfA");
  fout.cd("cfA");
  eA->Write();
  eB->Write();
  fout.Close();
  cout<<endl<<"Written "<<outname<<" with the tree structure of the cfA file."<<endl<<endl;
}
