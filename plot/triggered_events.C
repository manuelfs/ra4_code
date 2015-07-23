// find_cfa_trigger


#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "TChain.h"
#include "TString.h"

using namespace std;

void find_cfa_trigger(TString filename = "txt/datasamples/slep_dlep_htmht_ht_met.txt"){
  //void find_cfa_trigger(TString filename = "txt/datasamples/htmht_met.txt"){
  ifstream file(filename);
  ofstream outfile("txt/cfa_triggered_events.txt");
  TString dataset, trigger(""), trigname;
  vector<TString> trignames;

  file >> dataset;
  while(file){
    if(!dataset.Contains("MINIAOD")) continue;
    trignames.clear();
    file >> trigger;
    while(!trigger.Contains("MINIAOD") && file){
      if(trigger.Contains("_v")) trignames.push_back(trigger);
      file >> trigger;
    } // Looping over the input file for triggers
 
    TChain chain("cfA/eventA");
    chain.Add(dataset+"/*.root");
    long entries(chain.GetEntries());
    cout<<endl<<"Triggers for "<<dataset<<" ("<<entries<<" entries)"<<endl;
    outfile<<endl<<"Triggers for "<<dataset<<" ("<<entries<<" entries)"<<endl;

    vector<int> ntriggered(trignames.size(), 0);
    vector<string>* trig_name(0);
    vector<bool>* trig_dec(0);
    chain.SetBranchStatus("*",0);
    chain.SetBranchStatus("trigger_name",1);
    chain.SetBranchStatus("trigger_decision",1);
    chain.SetBranchAddress("trigger_name", &trig_name);
    chain.SetBranchAddress("trigger_decision", &trig_dec);
    for(int entry(0); entry < entries; entry++){
      chain.GetEntry(entry);
      for(unsigned itrig=0; itrig<trig_name->size();itrig++){
	trigname = trig_name->at(itrig);
	for(unsigned itn=0; itn<trignames.size();itn++) {
	  if(trigname.Contains(trignames[itn])) {
	    if(trig_dec->at(itrig)) ntriggered[itn]++;
	    break;
	  }
	} // Loop over desired triggers
      } // Loop over cfA triggers
    } // Loop over dataset entries
    for(unsigned itrig=0; itrig<trignames.size();itrig++){
      cout<<ntriggered[itrig]<<" \t"<<trignames[itrig]<<endl;
      outfile<<ntriggered[itrig]<<" \t"<<trignames[itrig]<<endl;
    }
    dataset = trigger;
  } // Loop over datasets
}

// void triggered_events(TString filename = "out/small_quick_Run2015B__SingleMuon_DoubleMuon_HTMHT_MET_files5_batch*", 
// 		      TString PDs = "SingleMuon_DoubleMuon_HTMHT_MET"){
void triggered_events(TString filename = "out/small_quick_Run2015B__HTMHT_MET_files10_batch*", 
		      TString PDs = "HTMHT_MET"){

  ifstream file("txt/cfa_triggered_events.txt");
  TString dataset, trigname, word1(""), word2("");
  vector<TString> trignames, datasets;
  vector<int> cfaevents;

  while(PDs.Length()>1) {
    if(PDs[0]=='_') PDs.Remove(0,1);
    dataset = PDs;
    if(dataset.First('_')>0) dataset.Remove(dataset.First('_'), dataset.Length());
    datasets.push_back(dataset);
    PDs.ReplaceAll(dataset,"");
  } 
  //for(unsigned ind(0); ind<datasets.size(); ind++) cout<<datasets[ind]<<endl;

  while(file){
    if(!word2.Contains("MINIAOD")) {
      word1 = word2;
      file >> word2;
      continue;;
    }
    bool want_PD(false);
    for(unsigned ind(0); ind<datasets.size(); ind++) 
      if(word2.Contains(datasets[ind])) {want_PD=true; break;}

    do {
      if(word2.Contains("HLT_") && want_PD) {
	trignames.push_back(word2);
	cfaevents.push_back(word1.Atoi());
      }
      word1 = word2;
      file >> word2;
    } while(!word2.Contains("MINIAOD") && file); // Looping over the input file for triggers
  } // Loop over datasets

  if(trignames.size()==0){
    cout<<"No triggers desired. Exiting."<<endl;
    return;
  }
  // for(unsigned ind(0); ind<trignames.size(); ind++) 
  //   cout<<cfaevents[ind]<<" \t"<<trignames[ind]<<endl;

  vector<int> trigind(trignames.size(), -1);
  vector<TString>*trig_name(0);
  TChain treeglobal("treeglobal");
  treeglobal.Add(filename);
  treeglobal.SetBranchAddress("trig_name", &trig_name);
  treeglobal.GetEntry(0);
  for(unsigned itg(0); itg<trig_name->size(); itg++){
    trigname = trig_name->at(itg);
    for(unsigned ind(0); ind<trignames.size(); ind++) 
      if(trigname.Contains(trignames[ind])) trigind[ind] = itg;
  }
  // for(unsigned itn=0; itn<trignames.size();itn++) 
  //   cout<<trigind[itn]<<" \t"<<trignames[itn]<<endl;

  vector<int> ntriggered(trignames.size(), 0);
  vector<bool> *trig(0);
  TChain tree("tree");
  tree.Add(filename);
  tree.SetBranchAddress("trig", &trig);
  long entries(tree.GetEntries());
  //entries=1000;
  cout<<endl<<"Triggers for "<<filename<<" ("<<entries<<" entries)"<<endl;
  for(int entry(0); entry < entries; entry++){
    if(entry%50000==0) cout<<"Doing entry "<<entry<<" of "<<entries<<endl;
    tree.GetEntry(entry);
    for(unsigned itn=0; itn<trignames.size();itn++) 
      if(trigind[itn]>=0 && trig->at(trigind[itn])) ntriggered[itn]++;
  }
  for(unsigned itn=0; itn<trignames.size();itn++) 
    cout<<"ntu-cfa = "<<ntriggered[itn]-cfaevents[itn]<<", \t ntu = "<<ntriggered[itn]<<" \t"<<trignames[itn]<<endl;
}
