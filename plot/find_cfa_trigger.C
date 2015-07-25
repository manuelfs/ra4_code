// find_cfa_trigger


#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "TChain.h"
#include "TString.h"

using namespace std;

//void find_cfa_trigger(TString filename = "txt/datasamples/slep_dlep_htmht_ht_met.txt"){
void find_cfa_trigger(TString filename = "txt/datasamples/htmht_met.txt"){
  ifstream file(filename);
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

    vector<int> ntriggered(trignames.size(), 0);
    vector<string>* trig_name(0);
    vector<bool>* trig_dec(0);
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
    for(unsigned itrig=0; itrig<trignames.size();itrig++)
      cout<<ntriggered[itrig]<<" \t"<<trignames[itrig]<<endl;

    dataset = trigger;
  } // Loop over datasets
}

void find_sn_trigger(TString filename = "/cms2r0/ald77/archive/2015_07_22/alldata/*root"){
  vector<TString> *trig_name(0);
  TChain treeglobal("treeglobal");
  treeglobal.Add(filename);
  treeglobal.SetBranchAddress("trig_name", &trig_name);
  treeglobal.GetEntry(0);
  
  vector<int> ntriggered(trig_name.size(), 0);
  vector<bool> *trig;
  TChain tree("treeglobal");
  tree.Add(filename);
  tree.SetBranchAddress("tri", &trig);
  long entries(tree.GetEntries());
  for(int entry(0); entry < entries; entry++){
    tree.GetEntry(entry);
    for(unsigned itn=0; itn<trig_name.size();itn++) 
      if(trig->at[it]) ntriggered++;
  }
  for(unsigned itn=0; itn<trig_name.size();itn++) 
    cout<<ntriggered[itn]<<" \t"<<trig_name->at(itn)<<endl;
}
