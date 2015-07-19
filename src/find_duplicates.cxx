// find_duplicates: Finds all unique events in a list of cfA files

#include <ctime>

#include <vector>
#include <fstream>
#include <iostream>
#include <set>
#include <map>

#include "TString.h"
#include "TChain.h"

#include "utilities.hpp"

using namespace std;

int main(int argc, char *argv[]){
  time_t startTime, curTime;
  time(&startTime);

  TString filename("txt/datasamples/slep_dlep_htmht.txt");
  int c(0);
  while((c=getopt(argc, argv, "f:"))!=-1){
    switch(c){
    case 'f':
      filename=optarg;
      break;
    default:
      break;
    }
  }

  map<UInt_t, set<UInt_t> > events;
  UInt_t event, run;
  ifstream file(filename);
  TString dataset;
  while(file) {
    file >> dataset;
    TChain chain("cfA/eventB");
    int files = chain.Add(dataset+"/*.root");
    if(files<1) continue;

    chain.SetBranchAddress("event", &event);
    chain.SetBranchAddress("run", &run);
    for(int entry(0); entry<3; entry++){
      chain.GetEntry(entry);
      if(events.find(run) == events.end()) events[run] = set<UInt_t>(); // New run
      if(events[run].find(event) == events[run].end()){ // New event
	events[run].insert(event);
      } // If even did not exist


    cout<<dataset<<endl;
      //cout<<entry<<": event "<<event<<", run "<<run<<endl;
    } // Loop over entries
  }

  time(&curTime);
  cout<<" events took "<<difftime(curTime,startTime)<<" seconds"<<endl<<endl;

  return 0;
}
