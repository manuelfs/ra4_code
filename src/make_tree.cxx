// make_tree: Generates the reduced trees

#include <ctime>

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <string>

#include "TString.h"
#include "TChain.h"

#include "utilities.hpp"
#include "event_handler.hpp"
#include "small_tree.hpp"

using namespace std;

void ParseDatasets(TString inFilename, int nfiles, int nbatch, vector<TString> &yes_trig, vector<TString> &no_trig,
		   vector<TString> &files, TString &outname);

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

  TString inFilename_s(inFilename);
  int len(inFilename_s.Length());
  if(inFilename_s[len-2] == '/') inFilename_s.Remove(len-2, len-1);
  inFilename = inFilename_s;
  TString outFilename(inFilename_s), folder(inFilename_s);
  TString outfolder("out/");
  TString prefix = "small_"+type+"_";

  vector<TString> files, yes_trig, no_trig;
  int ini(nfiles*(nbatch-1)), end(nfiles*nbatch), ntotfiles(-1), Ntotentries(-1);

  //outFilename.ReplaceAll("/cfA",""); // line needed when running directly on the output of CfANtupler
  // which produces files named cfA_XX.root

  outFilename.Remove(0,outFilename.Last('/')+1);
  enum Mode{dir_full, dir_part, one_file, txt_part, unknown};
  Mode mode = unknown;
  std::string all_sample_files = inFilename + "/*.root";
  if(Contains(inFilename, ".txt")){
    if(nfiles < 0 ) cout<<"Txt file input method in one go not implemented yet. Try with -f -b"<<endl;
    else {
      mode = txt_part;
      TString outname;
      ParseDatasets(inFilename, nfiles, nbatch, yes_trig, no_trig, files, outname); 
      if(files.size()==0){
	cout<<"No files for file "<<inFilename<<". Exiting"<<endl<<endl;
	return 1;
      }
      cout<<"Sending job with "<<files.size()<<" files. First is "<<files[0]<<" with "<<files.size()<<" files, "
	  <<yes_trig.size()<<" yes_trig, and "<<no_trig.size()<<" no_trig"<<endl;
      for(unsigned ind(0); ind<yes_trig.size(); ind++)
	cout<<"Yes: "<<yes_trig[ind]<<endl;
      for(unsigned ind(0); ind<no_trig.size(); ind++)
	cout<<"No: "<<no_trig[ind]<<endl;
      
      inFilename = files[0];
      outFilename = outfolder+prefix+outname+"_files"; outFilename += nfiles;
      outFilename += "_batch"; outFilename += nbatch; outFilename += ".root";
    }
  } else if(!Contains(inFilename, ".root")){
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
    break;
  case txt_part: // It doesn't matter
    chain.Add(files[0]);
    break;
  case dir_full:
  case one_file:
  case unknown:
  default:
    chain.Add(inFilename.c_str());
    break;
  }

  event_handler tHandler(inFilename, type);
  tHandler.ehb->yes_trig = yes_trig; tHandler.ehb->no_trig = no_trig; 
  if(mode==dir_part){
    cout<<endl<<"Doing files "<<ini+1<<" to "<<end<<" from a total of "<<ntotfiles<<" files."<<endl;
    for(int ifile(ini+1); ifile < end; ifile++){
      tHandler.AddFiles((folder + "/" + files[ifile]).Data());
    }
  }
  if(mode==txt_part){
    for(unsigned ifile(1); ifile < files.size(); ifile++){
      tHandler.AddFiles(files[ifile].Data());
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


void ParseDatasets(TString inFilename, int nfiles, int nbatch, vector<TString> &yes_trig, vector<TString> &no_trig, 
		   vector<TString> &files, TString &outname){

  ifstream file(inFilename);
  TString dataset, filename;
  int ifile(1);
  yes_trig.clear(); no_trig.clear();
  files.clear();
  file >> dataset;
  outname = "Run2015B_";
  while(file){
    if(!dataset.Contains("MINIAOD")) continue;
    TString name(dataset);
    int len(name.Length());
    if(name[len-2] == '/') name.Remove(len-2, len-1);
    name.Remove(0,name.Last('/')+1);
    name.Remove(name.First('_'), len);
    outname += ("_"+name);
    vector<TString> setfiles = dirlist(dataset, ".root");
   
    // For some reason, files can't be read some times
    if(setfiles.size()==0) {
      int maxretry(5);
      for(int ind(0); ind<maxretry; ind++){
	cout<<"No root files found at "<<dataset<<". Retrying "<<ind+1<<"/"<<maxretry<<endl;
	setfiles = dirlist(dataset, ".root");
	if(setfiles.size()>0) break;
      }
      if(setfiles.size()==0) {
	cout<<"Giving up. No root files found at "<<dataset<<endl;
	return;
      }
    }
    int nfilesdir(static_cast<int>(setfiles.size())), ibatch(-1);
    int njobs(nfilesdir/nfiles+1);
    bool sendjob(nbatch>=ifile && nbatch<(ifile+njobs));
    if(sendjob) ibatch = nbatch - ifile;
    int ini(nfiles*ibatch), end(nfiles*(ibatch+1));
    cout<<"Adding "<<dataset<<". nbatch "<<nbatch<<", ifile "<<ifile<<", njobs "<<njobs<<", sendjob "<<sendjob
	<<", nfilesdir "<<nfilesdir<<", ini "<<ini<<", end "<<end;

    for(int fil(0); fil < nfilesdir; fil++){
      filename = dataset+"/"+setfiles[fil];
      if(fil>=ini && fil<end && sendjob) files.push_back(filename);
    }
    ifile += njobs;
    file >> dataset;
    while(!dataset.Contains("MINIAOD") && file){
      if(dataset.Contains("_v")){
	if(sendjob) yes_trig.push_back(dataset);
	else if(files.size()==0) no_trig.push_back(dataset);
      }
      file >> dataset;
    } // Looping over the input file for triggers
    cout<<". It has "<<yes_trig.size()<<" yes_trig and "<<no_trig.size()<<" no_trig"<<endl;
  } // Looping over the input file for datasets
  if(files.size()==0){
    cout<<"No files for file "<<inFilename<<" and batch job "<<nbatch<<". Max batch number "<<ifile-1<<endl;
  }
}

