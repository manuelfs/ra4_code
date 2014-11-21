//----------------------------------------------------------------------------
// utilities - Various functions used accross the code
//----------------------------------------------------------------------------

#ifndef H_UTILITIES
#define H_UTILITIES

#include <string>
#include <vector>

#include "TString.h"
#include "TTree.h"

typedef std::pair<int,double> int_double;
typedef std::pair<double,double> double_double;
const double PI = 3.14159265;

float cross_section(TString file);
std::vector<TString> dirlist(TString folder, TString inname="dir", TString tag="");
bool eigen2x2(float matrix[2][2], float &eig1, float &eig2);
bool id_big2small(const int_double& left, const int_double& right);
bool dd_big2small(const double_double& left, const double_double& right);
bool dd_small2big(const double_double& left, const double_double& right);
double deltaphi(double phi1, double phi2);
float dR(float eta1, float phi1, float eta2, float phi2);
TString RoundNumber(double num, int decimals, double denom=1.);
long double AddInQuadrature(long double x, long double y);
long double GetMass(long double e, long double px, long double py, long double pz);
long double GetMT(const long double m1, const long double px1, const long double py1,
		  const long double m2, const long double px2, const long double py2);
bool Contains(const std::string& text, const std::string& pattern);

std::vector<std::string> Tokenize(const std::string& input,
                                  const std::string& tokens=" ");
void get_count_and_uncertainty(TTree& tree,
                               const std::string& cut,
                               double& count,
                               double& uncertainty);

template<class T>
bool is_nan(const T &x){return x!=x;}

#endif
