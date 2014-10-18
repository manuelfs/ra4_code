// make_tree: Generates the reduced trees

#include <vector>
#include <iostream>
#include <string>
#include <unistd.h>
#include <ctime>
#include "TString.h"
#include "TChain.h"
#include "utilities.hpp"
#include "event_handler.hpp"

 
using namespace std;

int main(int argc, char *argv[]){
  time_t startTime, curTime;
  time(&startTime);

  std::string inFilename("");
  std::string masspoint("");
  int c(0), Nentries(-1), nfiles(-1), nbatch(-1);
  while((c=getopt(argc, argv, "n:i:m:f:b:"))!=-1){
    switch(c){
    case 'n':
      Nentries=atoi(optarg);
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
    default:
      break;
    }
  }

  size_t pos(inFilename.find(".root"));
  TString outFilename(inFilename), folder(inFilename);

  TString all_sample_files(inFilename);
  
  vector<TString> files;
  int ini(nfiles*(nbatch-1)), end(nfiles*nbatch), ntotfiles(-1), Ntotentries(-1);
  if(pos==std::string::npos){
    if(nfiles>0){ // Doing sample in various parts
      files = dirlist(inFilename, ".root");
      ntotfiles = static_cast<int>(files.size());
      if(ini > ntotfiles) {
	cout<<"Trying to start at file "<<ini<<" but there are only "<<ntotfiles<<". Exiting."<<endl;
	return 1;
      }
      inFilename = folder + "/" + files[ini];
      outFilename = "out/small_"+files[ini];
      if(end > ntotfiles) end = ntotfiles;
      // Finding total number of entries in sample
      all_sample_files += "/*.root";
            
      TChain totsample("configurableAnalysis/eventA");
      totsample.Add(all_sample_files);
      Ntotentries = totsample.GetEntries();
    }else{
      inFilename = inFilename + "/*.root";
      int len(outFilename.Sizeof());
      if(outFilename[len-2] == '/') outFilename.Remove(len-2, len-1);
      outFilename.Remove(0,outFilename.Last('/')+1);
      outFilename = "out/small_"+outFilename+".root";
    }
  } else {
    outFilename.ReplaceAll("/configurableAnalysis","");
    outFilename.Remove(0,outFilename.Last('/')+1);
    outFilename = "out/small_"+outFilename;
  }

  cout<<"Opening "<<inFilename<<endl;
  event_handler tHandler(inFilename); 
  if(nfiles>0){
    cout<<endl<<"Doing files "<<ini+1<<" to "<<end<<" from a total of "<<ntotfiles<<" files."<<endl;
    for(int ifile(ini+1); ifile < end; ifile++)
      tHandler.AddFiles((folder + "/" + files[ifile]).Data());
  }
  if(Nentries > tHandler.TotalEntries() || Nentries < 0) Nentries = tHandler.TotalEntries();

  time(&curTime);
  cout<<"Getting started takes "<<difftime(curTime,startTime)<<" seconds. "
      <<"Making reduced tree with "<<Nentries<<" entries out of "<<tHandler.TotalEntries()<<endl;
  tHandler.ReduceTree(Nentries, outFilename, Ntotentries);

  time(&curTime);
  cout<<Nentries<<" events took "<<difftime(curTime,startTime)<<" seconds"<<endl;

  return 0;
}
