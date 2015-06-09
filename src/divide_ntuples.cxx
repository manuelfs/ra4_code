// divide_ntuples: Divides each ntuple in infolder into nDiv exclusive subsets

#include <ctime>

#include <vector>
#include <iostream>
#include <string>
#include <unistd.h>
#include <string>

#include "TFile.h"
#include "TSystem.h"
#include "TString.h"
#include "TChain.h"
#include "TDirectory.h"

#include "utilities.hpp"

using namespace std;

int main(int argc, char *argv[]){
  time_t startTime, curTime;
  time(&startTime);

  TString infolder(""), outfolder("");
  int c(0);
  unsigned nDiv(1);
  while((c=getopt(argc, argv, "i:o:n:"))!=-1){
    switch(c){
    case 'n':
      nDiv=atoi(optarg);
      break;
    case 'i':
      infolder=optarg;
      break;
    case 'o':
      outfolder=optarg;
      break;
    default:
      break;
    }
  }
  vector<TString> files = dirlist(infolder, ".root");
  unsigned nFiles(files.size());

  if(nDiv == 1 || nFiles==0){
    cout<<"nDiv = "<<nDiv<<" and nFiles = "<<nFiles<<". Nothing to do, exiting."<<endl<<endl; 
    return 1;
  }

  TString ntuplename, ntupleout, tag;
  gSystem->mkdir(outfolder, kTRUE);
  cout<<"Dividing "<<nFiles<<" files into "<<nDiv<<" divisions. outfolder = "<<outfolder<<endl;
  for(unsigned file(0); file < nFiles; file++){
    files[file] = "/"+files[file];
    ntuplename = infolder+files[file];
    TChain chain("tree");
    chain.Add(ntuplename);
    cout<<file<<": "<<ntuplename<<" has "<<chain.GetEntries()<<" entries"<<endl;
    vector<TChain *> divChains;
    for(unsigned div(0); div < nDiv; div++){
      divChains.push_back(static_cast<TChain *>(chain.CloneTree(0)));
    } // Loop over number of divisions
    for(int entry(0); entry < chain.GetEntries(); entry++){
      chain.GetEntry(entry);
      divChains[entry%nDiv]->Fill();
    } // Loop over chain entries
    for(unsigned div(0); div < nDiv; div++){
      tag = "_"; tag += div+1; tag += "of"; tag += nDiv;
      ntupleout = outfolder+files[file];
      ntupleout.ReplaceAll(".root", tag+".root");
      TFile divFile(ntupleout,"RECREATE");
      divFile.cd();
      divChains[div]->Write();
      divFile.Close();
      //cout<<"Written "<<ntupleout<<endl;
    } // Loop over number of divisions
  } // Loop over files

  time(&curTime);
  cout<<"Dividing ntuples took "<<difftime(curTime,startTime)<<" seconds"<<endl<<endl;

  return 0;
}
