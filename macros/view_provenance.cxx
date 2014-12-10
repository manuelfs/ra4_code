#include <iostream>

#include "TFile.h"
#include "TTree.h"
#include "TString.h"

#include "utilities.hpp"

using namespace std;

int main(int argc, char *argv[]){
  for(int arg = 1; arg < argc; ++arg){
    TFile file(argv[arg],"read");
    if(file.IsZombie() || !file.IsOpen()){
      cerr << "Could not open " << argv[arg] << '\n' << endl;
      continue;
    }

    TTree *tree = NULL;
    file.GetObject("treeglobal", tree);
    if(!tree){
      cerr << "Could not find \"treeglobal\" in " << argv[arg] << '\n' << endl;
      continue;
    }

    TString *model = NULL;
    TString *commit = NULL;
    int nev_file = -1;
    int nev_sample = -1;

    tree->SetBranchAddress("model", &model);
    tree->SetBranchAddress("nev_file", &nev_file);
    tree->SetBranchAddress("nev_sample", &nev_sample);
    tree->SetBranchAddress("commit", &commit);

    const int num_entries = tree->GetEntries();
    if(num_entries <= 0){
      cerr << "\"treeglobal\" has no entries in " << argv[arg] << '\n' << endl;
      continue;
    }else if(num_entries > 1){
      cerr << "\"treeglobal has multiple entries in " << argv[arg] << '\n' << endl;
      continue; 
    }

    const int bytes_read = tree->GetEntry(0);
    if(bytes_read <= 0){
      cerr << "\"Could not get entry 0 from \"treeglobal\" in " << argv[arg] << '\n' << endl;
      continue;
    }

    if(!model){
      cerr << "Read a null pointer for model string in " << argv[arg] << '\n' << endl;
      continue;
    }

    if(!commit){
      cerr << "Read a null pointer for commit string in " << argv[arg] << '\n' << endl;
      continue;
    }

    cout << "          File: " << argv[arg] << endl;
    cout << "         Model: " << RemoveTrailingNewlines(model->Data()) << endl;
    cout << "  File Entries: " << nev_file << endl;
    cout << "Sample Entries: " << nev_sample << endl;
    cout << "    Git Commit: " << RemoveTrailingNewlines(commit->Data()) << '\n' << endl;

    file.Close();
  }
}
