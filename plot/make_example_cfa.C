// make_example_cfa: Makes the example_cfa_file_13.root files with 0 entries

#define INT_ROOT
#include "inc/utilities.hpp"
#include "src/utilities.cpp"

#include <fstream>
#include <iostream>
#include "TTree.h"
#include "TFile.h"
#include "TString.h"
#include "TSystem.h"
#include "TDirectory.h"

using namespace std;
using std::cout;
using std::endl;

void make_example_cfa(TString file){
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
