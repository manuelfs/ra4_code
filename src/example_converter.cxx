#include <cstdlib>

#include <iostream>
#include <string>

#include "TFile.h"
#include "TDirectory.h"
#include "TTree.h"

using namespace std;

int main(int argc, char *argv[]){
  if(argc != 3){
    cerr << "Error: 2 arguments required." << endl;
    cerr << "Usage: example_converter.exe input_file_name output_file_name" << endl;
    return EXIT_FAILURE;
  }

  if(string(argv[1]) == string(argv[2])){
    cerr << "Input and output file are the same: " << argv[1] << '.' << endl;
    return EXIT_FAILURE;
  }

  TFile in_file(argv[1], "read");
  if(in_file.IsZombie() || !in_file.IsOpen()){
    cerr << "Could not open input file " << argv[1] << '.' << endl;
    return EXIT_FAILURE;
  }

  string cfa = "configurableAnalysis";
  TDirectory *dir = static_cast<TDirectory*>(in_file.Get(cfa.c_str()));
  if(!dir){
    cfa = "cfA";
    dir = static_cast<TDirectory*>(in_file.Get(cfa.c_str()));
    if(!dir){
      cerr << "File " << argv[1] << " has nither a cfA nor a configurableAnalysis TDirectory." << endl;
      return EXIT_FAILURE;
    }
  }

  TTree *event_a = static_cast<TTree*>(dir->Get("eventA"));
  if(!event_a){
    cerr << "Could not find eventA in subdirectory " << cfa << " in file " << argv[1] << '.' << endl;
    return EXIT_FAILURE;
  }

  TTree *event_b = static_cast<TTree*>(dir->Get("eventB"));
  if(!event_b){
    cerr << "Could not find eventB in subdirectory " << cfa << " in file " << argv[1] << '.' << endl;
    return EXIT_FAILURE;
  }

  TTree *event_a_out = event_a->CloneTree(0);
  if(!event_a_out){
    cerr << "Could not clone eventA." << endl;
    return EXIT_FAILURE;
  }

  TTree *event_b_out = event_b->CloneTree(0);
  if(!event_b_out){
    cerr << "Could not clone eventB." << endl;
    return EXIT_FAILURE;
  }

  TFile out_file(argv[2], "recreate");
  if(out_file.IsZombie() || !out_file.IsOpen()){
    cerr << "Could not open output file " << argv[2] << '.' << endl;
    return EXIT_FAILURE;
  }
  if(!out_file.cd()){
    cerr << "Could not cd into " << argv[2] << '.' << endl;
    return EXIT_FAILURE;
  }

  TDirectory *out_dir = out_file.mkdir(cfa.c_str());
  if(!out_dir){
    cerr << "Could not create TDirectory " << cfa << '.' << endl;
    return EXIT_FAILURE;
  }

  if(!out_dir->cd()){
    cerr << "Could not cd into " << cfa << '.' << endl;
    return EXIT_FAILURE;
  }

  if(!event_a_out->Write()){
    cerr << "Could not write eventA." << endl;
    return EXIT_FAILURE;
  }

  if(!event_b_out->Write()){
    cerr << "Could not write eventB." << endl;
    return EXIT_FAILURE;
  }

  out_file.Close();
  in_file.Close();

  return EXIT_SUCCESS;
}
