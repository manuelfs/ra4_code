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
  TString all_sample_files(inFilename), outfolder("out/");
  TString prefix = "small_"+type+"_";

  vector<TString> files;
  int ini(nfiles*(nbatch-1)), end(nfiles*nbatch), ntotfiles(-1), Ntotentries(-1);

  //outFilename.ReplaceAll("/cfA",""); // line needed when running directly on the output of CfANtupler
  // which produces files named cfA_XX.root

  int len(outFilename.Length());
  if(outFilename[len-2] == '/') outFilename.Remove(len-2, len-1);
  outFilename.Remove(0,outFilename.Last('/')+1);
  if(inFilename.find(".root")==std::string::npos){
    if(nfiles>0){ // Doing sample in various parts
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
      // Finding total number of entries in sample
      all_sample_files += "/*.root";

      TChain totsample("cfA/eventA");
      totsample.Add(all_sample_files);
      Ntotentries = totsample.GetEntries();
    }else{
      inFilename = inFilename + "/*.root";
      outFilename = outfolder+prefix+outFilename+".root";
    }
  } else {
    outFilename = outfolder+prefix+outFilename;
    nfiles = -1;
  }

  cout<<"Opening "<<inFilename<<endl;

  event_handler tHandler(inFilename, type);
  TChain chain("cfA/eventB");
  chain.Add(inFilename.c_str());
  int corrected_entries =chain.GetEntries("weight>0")-chain.GetEntries("weight<=0");
  if(nfiles>0){
    cout<<endl<<"Doing files "<<ini+1<<" to "<<end<<" from a total of "<<ntotfiles<<" files."<<endl;
    for(int ifile(ini+1); ifile < end; ifile++)
      tHandler.AddFiles((folder + "/" + files[ifile]).Data());
  }
  if(Nentries > corrected_entries || Nentries < 0) Nentries = corrected_entries;
  if(nfiles<=0) Ntotentries = Nentries;
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
