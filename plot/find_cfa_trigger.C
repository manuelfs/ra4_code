// find_cfa_trigger


#include <iostream>
#include <string>
#include <vector>

#include "TChain.h"
#include "TString.h"

using namespace std;

void find_cfa_trigger(TString filename, TString trigger, int entry=0){
  TChain chain("cfA/eventA");
  chain.Add(filename);
  if(entry >= chain.GetEntries()) {
    cout<<"Entry "<<entry<<" is beyond the number of entries "<<chain.GetEntries()<<endl;
    return;
  }

  vector<string>* trig_name(0);
  chain.SetBranchAddress("trigger_name", &trig_name);
  chain.GetEntry(entry);
  TString trigname;
  for(int unsigned itrig=0; itrig<trig_name->size();itrig++){
    trigname = trig_name->at(itrig);
    if(trigname.Contains(trigger)) {
      cout<<trigger<<" is index "<<itrig<<endl;
      break;
    }
  }
  

}
