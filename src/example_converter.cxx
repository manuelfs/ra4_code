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

  TFile in_file(argv[1], "read");
  if(in_file.IsZombie() || !in_file.IsOpen()){
    cerr << "Could not open input file " << argv[1] << '.' << endl;
    return EXIT_FAILURE;
  }

  const string cfa = "configurableAnalysis";
  TTree *event_a = static_cast<TTree*>(in_file.Get((cfa+"/eventA").c_str()));
  if(!event_a){
    cerr << "Could not find " << cfa << "/eventA in " << argv[1] << '.' << endl;
    return EXIT_FAILURE;
  }

  TTree *event_b = static_cast<TTree*>(in_file.Get((cfa+"/eventB").c_str()));
  if(!event_b){
    cerr << "Could not find " << cfa << "/eventB in " << argv[1] << '.' << endl;
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

  TDirectory *out_dir = out_file.mkdir(cfa.c_str());
  if(!out_dir){
    cerr << "Could not create TDirectory " << cfa << '.' << endl;
    return EXIT_FAILURE;
  }

  out_dir->cd();
  event_a_out->Write();
  event_b_out->Write();

  out_file.Close();
  in_file.Close();

  return EXIT_SUCCESS;
}
