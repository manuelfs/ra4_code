//----------------------------------------------------------------------------
// utilities - Various functions used accross the code
//----------------------------------------------------------------------------

#ifndef INT_ROOT
#include "utilities.hpp"
#endif

#include <iostream>
#include <string>
#include "TMath.h"
#include "TString.h"
#include "TSystemDirectory.h"
#include "TSystemFile.h"
#include "TSystem.h"
#include "TList.h"
#include "TCollection.h"

using namespace std;

// Returns cross section of sample in pb
float cross_section(TString file){
  float xsec(0.);

  // From https://twiki.cern.ch/twiki/bin/view/LHCPhysics/SUSYCrossSections13TeVgluglu
  if(file.Contains("T1tttt") && file.Contains("825_"))   xsec = 1.2167;
  if(file.Contains("T1tttt") && file.Contains("1025_"))  xsec = 0.272778;
  if(file.Contains("T1tttt") && file.Contains("1150_"))  xsec = 0.117687;
  if(file.Contains("T1tttt") && file.Contains("1200_"))  xsec = 0.0856418;
  if(file.Contains("T1tttt") && file.Contains("1500_"))  xsec = 0.0141903;

  // https://cms-pdmv.cern.ch/mcm/public/restapi/requests/get/TOP-Fall13-00005
  // says that it is 424.5 pb
  if(file.Contains("TT"))  xsec = 806.1;

  // From https://cms-pdmv.cern.ch/mcm
  if(file.Contains("WJetsToLNu_HT-100to200"))  xsec = 1817.0;
  if(file.Contains("WJetsToLNu_HT-200to400"))  xsec = 471.6;
  if(file.Contains("WJetsToLNu_HT-400to600"))  xsec = 55.61;
  if(file.Contains("WJetsToLNu_HT-600toInf"))  xsec = 18.81;

  if(file.Contains("WToENu"))   xsec = 16000.0;
  if(file.Contains("WToMuNu"))  xsec = 16100.0;

  if(file.Contains("QCD_Pt-5to10"))      xsec = 80710000000;
  if(file.Contains("QCD_Pt-10to15"))     xsec = 7528000000;
  if(file.Contains("QCD_Pt-15to30"))     xsec = 2237000000;
  if(file.Contains("QCD_Pt-30to50"))     xsec = 161500000;
  if(file.Contains("QCD_Pt-50to80"))     xsec = 22110000;
  if(file.Contains("QCD_Pt-80to120"))    xsec = 3000114;
  if(file.Contains("QCD_Pt-120to170"))   xsec = 493200;
  if(file.Contains("QCD_Pt-170to300"))   xsec = 120300;
  if(file.Contains("QCD_Pt-300to470"))   xsec = 7475;
  if(file.Contains("QCD_Pt-470to600"))   xsec = 587.1;
  if(file.Contains("QCD_Pt-600to800"))   xsec = 167;
  if(file.Contains("QCD_Pt-800to1000"))  xsec = 28.25;
  if(file.Contains("QCD_Pt-1000to1400")) xsec = 8.195;
  if(file.Contains("QCD_Pt-1400to1800")) xsec = 0.7346;
  if(file.Contains("QCD_Pt-1800to2400")) xsec = 0.102;
  if(file.Contains("QCD_Pt-2400to3200")) xsec = 0.00644;
  if(file.Contains("QCD_Pt-3200"))       xsec = 0.000163;

  if(file.Contains("T_tW-channel-DR"))            xsec = 35.0;
  if(file.Contains("TToLeptons_t-channel"))       xsec = 45.0;
  if(file.Contains("TToLeptons_s-channel"))       xsec = 2.0;
  if(file.Contains("Tbar_tW-channel-DR"))         xsec = 35.0;
  if(file.Contains("TBarToLeptons_t-channel"))    xsec = 16.9;
  if(file.Contains("TBarToLeptons_s-channel"))    xsec = 1.0;

  if(file.Contains("DYJetsToLL_M-50_HT-100to200"))    xsec = 194.3;
  if(file.Contains("DYJetsToLL_M-50_HT-200to400"))    xsec = 52.24;
  if(file.Contains("DYJetsToLL_M-50_HT-400to600"))    xsec = 6.546;
  if(file.Contains("DYJetsToLL_M-50_HT-600toInf"))    xsec = 2.179;

  if(xsec<=0) cout<<"Cross section not found for "<<file<<endl;

  return xsec;
}

// Returns list of directorites or files in folder
vector<TString> dirlist(TString folder, TString inname, TString tag){
  TString pwd(gSystem->pwd());
  vector<TString> v_dirs;
  TSystemDirectory dir(folder, folder);
  TList *files = dir.GetListOfFiles();
  if (files) {
    TSystemFile *file;
    TString fname;
    TIter next(files);
    while ((file=static_cast<TSystemFile*>(next()))) {
      fname = file->GetName();
      if (inname=="dir") {
        if ((file->IsDirectory() && !fname.Contains(".") && fname.EndsWith(tag))) v_dirs.push_back(fname);
      } else  if(fname.Contains(inname)) v_dirs.push_back(fname);
    }
  } // if(files)
  gSystem->cd(pwd); // The TSystemDirectory object seems to change current folder
  return v_dirs;
}

bool eigen2x2(float matrix[2][2], float &eig1, float &eig2){
  float root = pow(matrix[0][0],2) + pow(matrix[1][1],2)-2*matrix[0][0]*matrix[1][1]+4*matrix[0][1]*matrix[1][0];
  if(root<0) return false;
  
  eig1 = (matrix[0][0]+matrix[1][1]+sqrt(root))/2.;
  eig2 = (matrix[0][0]+matrix[1][1]-sqrt(root))/2.;
  return true;
}

bool id_big2small(const int_double& left, const int_double& right){ 
  return left.second > right.second; 
}  

bool dd_small2big(const double_double& left, const double_double& right){ 
  return left.first < right.first; 
}  

bool dd_big2small(const double_double& left, const double_double& right){ 
  return left.first > right.first; 
}  

double deltaphi(double phi1, double phi2){
  double result = fabs(phi1-phi2);
  while (result>TMath::Pi()) result -= 2*TMath::Pi();
  while (result<=-TMath::Pi()) result += 2*TMath::Pi();
  return result;
}

float dR(float eta1, float eta2, float phi1, float phi2) {
  return sqrt(pow(eta1-eta2, 2) + pow(deltaphi(phi1,phi2), 2)) ;
}

TString RoundNumber(double num, int decimals, double denom){
  if(denom==0) return " - ";
  double neg = 1; if(num*denom<0) neg = -1;
  num /= neg*denom; num += 0.5*pow(10.,-decimals);
  long num_int = static_cast<long>(num);
  long num_dec = static_cast<long>((1+num-num_int)*pow(10.,decimals));
  TString s_dec = ""; s_dec += num_dec; s_dec.Remove(0,1);
  TString result=""; 
  if(neg<0) result+="-";
  result+= num_int;
  if(decimals>0) {
    result+="."; result+=s_dec;
  }
  
  TString afterdot = result;
  afterdot.Remove(0,afterdot.First(".")+1);
  for(int i=0; i<decimals-afterdot.Length(); i++)
    result += "0";
  return result;
}

bool Contains(const std::string& text, const std::string& pattern){
  return text.find(pattern) != std::string::npos;
}
