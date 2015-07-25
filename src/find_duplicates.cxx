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

  ////// sample1 is the one with the fewest events

  // TString sample1("archive/15-07-23_test_single/small_quick_MET");
  // TString sample2("archive/15-07-23_test_single/small_quick_Run2015B__HTMHT_MET_files10_batch");

  TString sample1("archive/15-07-23_test_single/small_quick_Run2015B__SingleMuon_DoubleMuon_HTMHT_MET_files5");
  TString sample2("archive/15-07-23_test_single/small_quick_HTMHT");
  int desired_trigger(0);

  int c(0);
  while((c=getopt(argc, argv, "f:"))!=-1){
    switch(c){
    case 'f':
      sample1=optarg;
      break;
    default:
      break;
    }
  }

  vector<bool> *trig(0);
  map<UInt_t, set<UInt_t> > events;
  UInt_t event, run, levent;
  TChain chain("tree"), chain2("tree");
  int files = chain.Add(sample1+"*.root"), nmiss(0), ndup(0);
  chain2.Add(sample2+"*.root");
  if(files<1) return 1;

  cout<<endl<<"Doing "<<sample1<<endl;
  chain.SetBranchAddress("event", &event);
  chain.SetBranchAddress("run", &run);
  chain.SetBranchAddress("trig", &trig);
  long entries(chain.GetEntries());
  //entries = 100;
  for(int entry(0); entry<entries; entry++){
    levent = event;
    chain.GetEntry(entry);
    if(entry%250000==0) {
      cout<<"Doing entry "<<entry<<" of "<<entries<<endl;
      //event = levent;
    }
    if(!trig->at(desired_trigger)) continue; 
    if(events.find(run) == events.end()) events[run] = set<UInt_t>(); // New run
    if(events[run].find(event) == events[run].end()){ // New event
      events[run].insert(event);
    } else {// If event did not exist
      cout<<entry<<": Event "<<event<<" in run "<<run<<" is duplicated"<<endl;
      ndup++;
    }
    //cout<<entry<<": event "<<event<<", run "<<run<<". Total of "<<events[run].size()<<" events in this run"<<endl;
  } // Loop over entries
  

  cout<<endl<<"Doing "<<sample2<<endl;
  chain2.SetBranchAddress("event", &event);
  chain2.SetBranchAddress("run", &run);
  chain2.SetBranchAddress("trig", &trig);
  entries = chain2.GetEntries();
  for(int entry(0); entry<entries; entry++){
    levent = event;
    chain2.GetEntry(entry);
    if(entry%250000==0) {
      cout<<"Doing entry "<<entry<<" of "<<entries<<endl;
    }
    if(!trig->at(desired_trigger)) continue; // MET170 trigger
    if(events.find(run) == events.end()) events[run] = set<UInt_t>(); // New run
    if(events[run].find(event) == events[run].end()){ // New event
      events[run].insert(event);
      cout<<entry<<": Event "<<event<<" in run "<<run<<" is not in "<<sample1<<endl;
      nmiss++;
    } else {// If event did not exist
    }
    //cout<<entry<<": event "<<event<<", run "<<run<<". Total of "<<events[run].size()<<" events in this run"<<endl;
  } // Loop over entries
  

  time(&curTime);
  cout<<"Running over "<<entries<<" events took "<<difftime(curTime,startTime)<<" seconds. There were "
      <<nmiss<<" events missing and "<<ndup<<" duplicate"<<endl<<endl;

  return 0;
}
