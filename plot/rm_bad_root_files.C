// rm_bad_root_Files: macro that finds root files that are zombies or were not properly closed

#define INT_ROOT
#include "inc/utilities.hpp"
#include "src/utilities.cpp"

#include <fstream>
#include <iostream>
#include "TString.h"
#include "TFile.h"
#include "TSystem.h"
#include "TDirectory.h"
#include "TError.h" // Turns off "not properly closed" warnings

using namespace std;
using std::cout;
using std::endl;

void rm_bad_root_files(TString folder="out/", TString tag=".root"){
  gErrorIgnoreLevel=kError; // Turns off "not properly closed" warnings

  vector<TString> files = dirlist(folder, tag);
  for(unsigned file(0); file < files.size(); file++){
    TFile rootfile(folder+files[file]);
    
    bool badfile(rootfile.IsZombie() || rootfile.TestBit(TFile::kRecovered));
    if(badfile) {
      // We could use gSystem->Exec("rm "+folder+files[file]), but it's scarier
      cout<<"rm "<<(folder+files[file])<<endl;
    }
  }
}
