// make_tree: Generates the reduced trees

#include <ctime>

#include <vector>
#include <iostream>
#include <string>
#include <unistd.h>
#include <string>

#include "TString.h"
#include "TChain.h"

#include "utilities.hpp"
#include "event_handler.hpp"
#include "small_tree.hpp"

using namespace std;

int main(int argc, char *argv[]){
  time_t startTime, curTime;
  time(&startTime);

  std::string inFilename("");
  std::string masspoint("");
  int c(0), Nentries(-1), nfiles(-1), nbatch(-1), total_entries_override(-1);
  string type = "";
  while((c=getopt(argc, argv, "n:t:i:m:f:b:s:"))!=-1){
    switch(c){
    case 'n':
      Nentries=atoi(optarg);
      break;
    case 't':
      total_entries_override = atoi(optarg);
      break;
    case 'f':
      nfiles=atoi(optarg);
      break;
    case 'b':
      nbatch=atoi(optarg);
      break;
    case 'i':
      inFilename=optarg;
      break;
    case 'm':
      masspoint=optarg;
      break;
    case 's':
      type = optarg;
      break;
    default:
      break;
    }
  }

  TString outFilename(inFilename), folder(inFilename);
  TString outfolder("out/");
  TString prefix = "small_"+type+"_";

  vector<TString> files;
  int ini(nfiles*(nbatch-1)), end(nfiles*nbatch), ntotfiles(-1), Ntotentries(-1);

  //outFilename.ReplaceAll("/cfA",""); // line needed when running directly on the output of CfANtupler
  // which produces files named cfA_XX.root

  int len(outFilename.Length());

  if(outFilename[len-2] == '/') outFilename.Remove(len-2, len-1);
  outFilename.Remove(0,outFilename.Last('/')+1);
  enum Mode{dir_full, dir_part, one_file, unknown};
  Mode mode = unknown;
  std::string all_sample_files = inFilename + "/*.root";
  if(!Contains(inFilename, ".root")){
    if(nfiles>0){ // Doing sample in various parts
      mode = dir_part;
      files = dirlist(inFilename, ".root");
      ntotfiles = static_cast<int>(files.size());
      if(ini > ntotfiles) {
        cout<<"Trying to start at file "<<ini<<" but there are only "<<ntotfiles<<". Exiting."<<endl;
        return 1;
      }
      inFilename = folder + "/" + files[ini];
      outFilename = outfolder+prefix+outFilename+"_files"; outFilename += nfiles;
      outFilename += "_batch"; outFilename += nbatch; outFilename += ".root";

      if(end > ntotfiles) end = ntotfiles;
    }else{
      mode = dir_full;
      inFilename = inFilename + "/*.root";
      outFilename = outfolder+prefix+outFilename+".root";
    }
  } else {
    mode = one_file;
    outFilename = outfolder+prefix+outFilename;
    nfiles = -1;
  }

  cout<<"Opening "<<inFilename<<endl;

  TChain chain("cfA/eventB");
  switch(mode){
  case dir_part:
    chain.Add(all_sample_files.c_str());
    for(int ifile(ini+1); ifile < end; ifile++){
      chain.Add((folder+ "/" + files[ifile]).Data());
    }
    break;
  case dir_full:
  case one_file:
  case unknown:
  default:
    chain.Add(inFilename.c_str());
    break;
  }

  event_handler tHandler(inFilename, type);
  if(mode==dir_part){
    cout<<endl<<"Doing files "<<ini+1<<" to "<<end<<" from a total of "<<ntotfiles<<" files."<<endl;
    for(int ifile(ini+1); ifile < end; ifile++){
      tHandler.AddFiles((folder + "/" + files[ifile]).Data());
    }
  }
  if(Nentries > tHandler.TotalEntries() || Nentries < 0) Nentries = tHandler.TotalEntries();
  if((mode==one_file || mode==dir_full) && Nentries != tHandler.TotalEntries()){
    Ntotentries = Nentries;
  }else{
    Ntotentries = chain.GetEntries("weight>0")-chain.GetEntries("weight<0");
  }
  if(total_entries_override > 0) Ntotentries = total_entries_override;
  time(&curTime);
  cout<<"Getting started takes "<<difftime(curTime,startTime)<<" seconds. "
      <<"Making reduced tree with "<<Nentries<<" entries out of "<<tHandler.TotalEntries()
      <<". "<<Ntotentries<<" entries in the full sample."<<endl;
  tHandler.ReduceTree(Nentries, outFilename, Ntotentries);

  cout<<"Wrote "<<outFilename<<endl<<endl;
  time(&curTime);
  cout<<Nentries<<" events took "<<difftime(curTime,startTime)<<" seconds"<<endl<<endl;

  return 0;
}
