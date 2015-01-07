//----------------------------------------------------------------------------
// utilities - Various functions used accross the code
//----------------------------------------------------------------------------

#ifndef INT_ROOT
#include "utilities.hpp"
#endif

#include <iostream>
#include <string>
#include <stdexcept>

#include "TMath.h"
#include "TString.h"
#include "TSystemDirectory.h"
#include "TSystemFile.h"
#include "TSystem.h"
#include "TList.h"
#include "TCollection.h"
#include "TH1D.h"
#include "TTree.h"
#include "TGraph.h"

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

  if(file.Contains("T2tt") && file.Contains("650_"))  xsec = 0.107045;
  if(file.Contains("T2tt") && file.Contains("850_"))  xsec = 0.0189612;

  // https://cms-pdmv.cern.ch/mcm/public/restapi/requests/get/TOP-Fall13-00005
  // says that it is 424.5 pb
  if(file.Contains("TTJet") || file.Contains("TT_"))  xsec = 806.1;

  // From https://cms-pdmv.cern.ch/mcm
  if(file.Contains("WJetsToLNu_HT-100to200"))  xsec = 1817.0;
  if(file.Contains("WJetsToLNu_HT-200to400"))  xsec = 471.6;
  if(file.Contains("WJetsToLNu_HT-400to600"))  xsec = 55.61;
  if(file.Contains("WJetsToLNu_HT-600toInf"))  xsec = 18.81;

  if(file.Contains("WToENu"))   xsec = 16000.0;
  if(file.Contains("WToMuNu"))  xsec = 16100.0;

  if(file.Contains("QCD_HT_250To500_13TeV-madgraph"))  xsec = 670500.0;
  if(file.Contains("QCD_HT-500To1000_13TeV-madgraph")) xsec = 26740.0;
  if(file.Contains("QCD_HT_1000ToInf_13TeV-madgraph")) xsec = 769.7;

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

long double DeltaPhi(long double phi1, long double phi2){
  long double dphi = fmod(fabs(phi2-phi1), 2.L*PI);
  return dphi>PI ? 2.L*PI-dphi : dphi;
}

long double SignedDeltaPhi(long double phi1, long double phi2){
  long double dphi = fmod(phi2-phi1, 2.L*PI);
  if(dphi>PI){
    return dphi-2.L*PI;
  }else if(dphi<-PI){
    return dphi+2.L*PI;
  }else{
    return dphi;
  }
}

float dR(float eta1, float eta2, float phi1, float phi2) {
  return AddInQuadrature(eta1-eta2, DeltaPhi(phi1,phi2));
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

long double AddInQuadrature(long double x, long double y){
  if(fabs(y)>fabs(x)){
    const long double temp = y;
    y=x;
    x=temp;
  }
  const long double rat=y/x;
  return fabs(x)*sqrt(1.0L+rat*rat);
}

long double GetMass(long double e, long double px, long double py, long double pz){
  px/=e; py/=e; pz/=e;
  return fabs(e)*sqrt(1.0L-px*px-py*py-pz*pz);
}

long double GetMT(const long double m1, const long double px1, const long double py1,
                  const long double m2, const long double px2, const long double py2){
  const long double pt1 = AddInQuadrature(px1, py1);
  const long double et1 = AddInQuadrature(m1, pt1);
  const long double pt2 = AddInQuadrature(px2, py2);
  const long double et2 = AddInQuadrature(m2, pt2);
  return sqrt(m1*m1+m2*m2+2.0L*(et1*et2-px1*px2-py1*py2));
}

bool Contains(const string& text, const string& pattern){
  return text.find(pattern) != string::npos;
}

vector<string> Tokenize(const string& input,
                        const string& tokens){
  char* ipt(new char[input.size()+1]);
  memcpy(ipt, input.data(), input.size());
  ipt[input.size()]=static_cast<char>(0);
  char* ptr(strtok(ipt, tokens.c_str()));
  vector<string> output(0);
  while(ptr!=NULL){
    output.push_back(ptr);
    ptr=strtok(NULL, tokens.c_str());
  }
  return output;
}

void get_count_and_uncertainty(TTree& tree,
                               const string& cut,
                               double& count,
                               double& uncertainty){
  const string hist_name("temp");
  TH1D temp(hist_name.c_str(), "", 1, -1.0, 1.0);
  tree.Project(hist_name.c_str(), "0.0", cut.c_str());
  count=temp.IntegralAndError(0,2,uncertainty);
}

void AddPoint(TGraph& graph, const double x, const double y){
  graph.SetPoint(graph.GetN(), x, y);
}

string execute(const string &cmd){
  FILE *pipe = popen(cmd.c_str(), "r");
  if(!pipe) throw runtime_error("Could not open pipe.");
  const size_t buffer_size = 128;
  char buffer[buffer_size];
  string result = "";
  while(!feof(pipe)){
    if(fgets(buffer, buffer_size, pipe) != NULL) result += buffer;
  }

  pclose(pipe);
  return result;
}

string RemoveTrailingNewlines(string str){
  while(!str.empty() && str.at(str.length()-1) == '\n'){
    str.erase(str.length()-1);
  }
  return str;
}

vector<double> LinearSpacing(size_t npts, double low, double high){
  vector<double> pts(npts,low+0.5*(high-low));
  if(npts>1){
    double gap = (high-low)/(npts-1.0);
    for(size_t pt = 0; pt < npts; ++pt){
      pts.at(pt) = low+pt*gap;
    }
  }
  return pts;
}
