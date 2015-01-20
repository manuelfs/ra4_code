#include "iso_transfer.hpp"

#include <iostream>
#include <iomanip>
#include <vector>

#include "TH2D.h"
#include "TCanvas.h"
#include "TColor.h"
#include "TStyle.h"
#include "TString.h"
#include "TLine.h"

#include "styles.hpp"
#include "small_tree.hpp"
#include "timer.hpp"
#include "cut.hpp"

using namespace std;

int main(){
  const double lumi = 4.0;

  styles style("Standard"); style.LabelSize = 0.095; style.TitleSize = 0.06;
  style.setDefaultStyle();
  gStyle->SetPaintTextFormat(".1f");

  TH1::SetDefaultSumw2(true);

  int pos_cols[999], sym_cols[999];
  PositiveColors(pos_cols);
  SymmetricColors(sym_cols);

  TString sample;
  small_tree tree("archive/ra4skim/*T1tttt_2J_mGl-1500_mLSP-100*"); sample = "t1tttt1500";
  //small_tree tree("archive/ra4skim/*SMS-T1bbbb_2J_mGl-1500_mLSP-100*"); sample = "t1bbbb1500";
  //small_tree tree("archive/15-01-14/small_TTJet_ht30_500_met200.root"); sample = "ttbar";

  //small_tree tree("archive/ra4skim/*SMS-T1tttt_2J_mGl-1200_mLSP-800_*"); sample = "t1tttt1200";
  //small_tree tree("archive/ra4skim/*TTJet*.root"); sample = "ttbar";
  //small_tree tree("archive/ra4skim/*QCD*.root"); sample = "qcd";

  vector<CutBase*> base_cuts;
  TString cut_string = "UNKNOWN";
  switch(1){//Pick a set of cuts here
  default:
    cut_string = "inclusive";
    break;
  case 0:
    cut_string = "ra4";
    base_cuts.push_back(NewCut(&tree, &small_tree::ht, 750.f, kGreater));
    base_cuts.push_back(NewCut(&tree, &small_tree::met, 200.f, kGreater));
    base_cuts.push_back(NewCut(&tree, &small_tree::njets, 6, kGreaterEqual));
    base_cuts.push_back(NewCut(&tree, &small_tree::nbl, 2, kGreaterEqual));
    break;
  case 1: //RA2b
    cut_string = "ra2b";
    base_cuts.push_back(NewCut(&tree, &small_tree::ht30, 1200.f, kGreater));
    base_cuts.push_back(NewCut(&tree, &small_tree::met, 800.f, kGreater));
    base_cuts.push_back(NewCut(&tree, &small_tree::njets30, 4, kGreaterEqual));
    //base_cuts.push_back(NewCut(&tree, &small_tree::nbm, 2, kGreaterEqual));
    base_cuts.push_back(NewCut(&tree, &small_tree::mindphin_metjet, 4.f, kGreater));
    break;
  }

  vector<pair<IsoCut,TString> > iso_cuts;
  iso_cuts.push_back(pair<IsoCut, TString>(VetoStandardIso, "vetostandard"));
  iso_cuts.push_back(pair<IsoCut, TString>(VetoMiniIso, "vetominiso"));

  //Put cuts only applied for specific number of reco leptons here
  //Outer index is number of leptons
  vector<vector<CutBase*> > lepton_num_cuts;

  vector<TH2D> histos(iso_cuts.size(),
                      TH2D("", ";Num Reco veto e+#mu;Num Gen e+#mu", 6, -1.5, 4.5, 6, -1.5, 4.5));
  TLine hline(-1.5, -0.5, 4.5, -0.5);
  TLine vline(-0.5, -1.5, -0.5, 4.5);
  SetLineStyle(hline);
  SetLineStyle(vline);

  long num_entries = tree.GetEntries();
  Timer timer(num_entries, 1.0);
  timer.Start();
  for(long entry = 0; entry < num_entries; ++entry){
    timer.Iterate();
    tree.GetEntry(entry);

    if(!PassesCuts(base_cuts)) continue;

    for(size_t icut = 0; icut < iso_cuts.size(); ++icut){
      int best_el = -1, best_mu = -1;
      int count = (iso_cuts.at(icut).first)(tree, best_el, best_mu);

      bool pass_lep_cuts;
      if(!lepton_num_cuts.size()){
        pass_lep_cuts = true;
      }else if(static_cast<size_t>(count)>=lepton_num_cuts.size()){
        pass_lep_cuts = PassesCuts(lepton_num_cuts.back());
      }else{
        pass_lep_cuts = PassesCuts(lepton_num_cuts.at(count));
      }
      if(!pass_lep_cuts) continue;

      histos.at(icut).Fill(count, (tree.mc_type() & 0xF00) >> 8, lumi*tree.weight());
    }
  }

  Delete(base_cuts);

  for(size_t ihist = 0; ihist < histos.size(); ++ihist){
    TH2D &hist = histos.at(ihist);
    hist.SetMarkerSize(3.4);
    hist.SetMarkerStyle(20);

    //Sum column
    for(int xbin = 0; xbin <= hist.GetNbinsX()+1; ++xbin){
      double error = 0.;
      double integral = hist.IntegralAndError(xbin, xbin, 2, hist.GetNbinsY()+1, error);
      hist.SetBinContent(xbin, 1, integral);
      hist.SetBinError(xbin, 1, error);
    }

    //Sum row
    for(int ybin = 0; ybin <= hist.GetNbinsY()+1; ++ybin){
      double error = 0.;
      double integral = hist.IntegralAndError(2, hist.GetNbinsX()+1, ybin, ybin, error);
      hist.SetBinContent(1, ybin, integral);
      hist.SetBinError(1, ybin, error);
    }

    hist.GetXaxis()->SetBinLabel(1, "Any");
    for(int i = 2; i <= hist.GetNbinsX(); ++i){
      hist.GetXaxis()->SetBinLabel(i, TString::Itoa(i-2,10));
    }
    hist.GetYaxis()->SetBinLabel(1, "Any");
    for(int i = 2; i <= hist.GetNbinsY(); ++i){
      hist.GetYaxis()->SetBinLabel(i, TString::Itoa(i-2,10));
    }
  }

  for(size_t ihist = 0; ihist < histos.size(); ++ihist){
    gStyle->SetPalette(999, pos_cols);
    TString title = "eps/trans_single_"
      +sample+"_"
      +cut_string+"_"
      +iso_cuts.at(ihist).second+".eps";
    TCanvas c;
    histos.at(ihist).Draw("col");
    //histos.at(ihist).Draw("boxsame");
    histos.at(ihist).Draw("textsame");
    hline.Draw("same");
    vline.Draw("same");
    c.Print(title);
    for(size_t jhist = 0; jhist < histos.size(); ++jhist){
      if(jhist==ihist) continue;
      gStyle->SetPalette(999, sym_cols);
      TH2D delta = histos.at(ihist);
      for(int x = 0; x <= delta.GetNbinsX()+1; ++x){
        for(int y = 0; y <= delta.GetNbinsY()+1; ++y){
          delta.SetBinContent(x, y,
                              histos.at(ihist).GetBinContent(x, y)
                              -histos.at(jhist).GetBinContent(x, y));
        }
      }
      double maxi = fabs(delta.GetBinContent(delta.GetMaximumBin()));
      double mini = fabs(delta.GetBinContent(delta.GetMinimumBin()));
      if(mini>maxi) maxi=mini;
      delta.SetMinimum(-maxi);
      delta.SetMaximum(maxi);
      title = "eps/trans_delta_"
        +sample+"_"
        +cut_string+"_"
        +iso_cuts.at(ihist).second
        +"_minus_"
        +iso_cuts.at(jhist).second+".eps";
      delta.Draw("col");
      delta.Draw("textsame");
      hline.Draw("same");
      vline.Draw("same");
      if(!title.Contains("minus_miniso") && !title.Contains("minus_vetominiso")) c.Print(title);
    }
    for(size_t jhist = 0; jhist < histos.size(); ++jhist){
      if(jhist==ihist) continue;
      gStyle->SetPalette(999, sym_cols);
      TH2D delta = histos.at(ihist);
      for(int x = 0; x <= delta.GetNbinsX()+1; ++x){
        for(int y = 0; y <= delta.GetNbinsY()+1; ++y){
	  float den(histos.at(jhist).GetBinContent(x, y));
	  float z(0);
	  if(den) z = 100*(histos.at(ihist).GetBinContent(x, y)-den)/den;
          delta.SetBinContent(x, y, z);
        }
      }
      double maxi = fabs(delta.GetBinContent(delta.GetMaximumBin()));
      double mini = fabs(delta.GetBinContent(delta.GetMinimumBin()));
      if(mini>maxi) maxi=mini;
      delta.SetMinimum(-maxi);
      delta.SetMaximum(maxi);
      title = "eps/trans_ratio_"
        +sample+"_"
        +cut_string+"_"
        +iso_cuts.at(ihist).second
        +"_over_"
        +iso_cuts.at(jhist).second+".eps";
      delta.Draw("col");
      delta.Draw("textsame");
      hline.Draw("same");
      vline.Draw("same");
      if(!title.Contains("over_miniso") && !title.Contains("over_vetominiso")) c.Print(title);
    }

  }
}

bool PassesCuts(const vector<CutBase*> &cuts){
  for(vector<CutBase*>::const_iterator cut = cuts.begin();
      cut != cuts.end();
      ++cut){
    if(!(*cut)->Pass()) return false;
  }
  return true;
}

int GetLeptons(const small_tree &tree,
               IsoCut cut,
               int &best_el,
               int &best_mu){
  return cut(tree, best_el, best_mu);
}

void Fix(const small_tree &tree,
         int &best_el, int &best_mu){
  if(best_el < 0 || static_cast<unsigned>(best_el) >= tree.els_pt().size()) best_el = -1;
  if(best_mu < 0 || static_cast<unsigned>(best_mu) >= tree.mus_pt().size()) best_mu = -1;
  if(best_el != -1 && best_mu != -1){
    if(tree.els_pt().at(best_el) >= tree.mus_pt().at(best_mu)){
      best_mu = -1;
    }else{
      best_el = -1;
    }
  }
}

int StandardIso(const small_tree &tree,
                int &best_el,
                int &best_mu){
  int leps = StandardEl(tree, best_el);
  leps += StandardMu(tree, best_mu);
  Fix(tree, best_el, best_mu);
  return leps;
}

int StandardEl(const small_tree &tree,
               int &best_el){
  int num_els = 0;
  double max_pt = -1.0;
  best_el = -1;
  for(size_t iel = 0; iel < tree.els_eta().size(); ++iel){
    if((fabs(tree.els_eta().at(iel))<=1.479 && tree.els_reliso_r03().at(iel)<0.2179)
       || (fabs(tree.els_eta().at(iel))>1.479&& fabs(tree.els_eta().at(iel))<2.5
           && tree.els_reliso_r03().at(iel)<0.254)){
      if(!(tree.els_sigid().at(iel) && tree.els_ispf().at(iel) && tree.els_pt().at(iel)>20.)) continue;
      ++num_els;
      if(tree.els_pt().at(iel) > max_pt){
        max_pt = tree.els_pt().at(iel);
        best_el = iel;
      }
    }
  }

  return num_els;
}

int StandardMu(const small_tree &tree,
               int &best_mu){
  int num_mus = 0;
  double max_pt = -1.0;
  best_mu = -1;
  for(size_t imu = 0; imu < tree.mus_reliso_r04().size();  ++imu){
    if(tree.mus_reliso_r04().at(imu) < 0.12){
      if(!(tree.mus_sigid().at(imu) && tree.mus_pt().at(imu)>20.)) continue;
      ++num_mus;
      if(tree.mus_pt().at(imu) > max_pt){
        max_pt = tree.mus_pt().at(imu);
        best_mu = imu;
      }
    }
  }

  return num_mus;
}

int MiniIso(const small_tree &tree,
            int &best_el,
            int &best_mu){
  int leps = MiniEl(tree, best_el);
  leps += MiniMu(tree, best_mu);
  Fix(tree, best_el, best_mu);
  return leps;
}

int MiniEl(const small_tree &tree,
           int &best_el){
  int num_els = 0;
  double max_pt = -1.0;
  best_el = -1;
  for(size_t iel = 0; iel < tree.els_miniso_tr10().size(); ++iel){
    if(min(tree.els_reliso_r02().at(iel),tree.els_miniso_tr10().at(iel)) < 0.1){
      if(!(tree.els_sigid().at(iel) && tree.els_ispf().at(iel) && tree.els_pt().at(iel)>20)) continue;
      ++num_els;
      if(tree.els_pt().at(iel) > max_pt){
        max_pt = tree.els_pt().at(iel);
        best_el = iel;
      }
    }
  }
  return num_els;
}

int MiniMu(const small_tree &tree,
           int &best_mu){
  int num_mus = 0;
  double max_pt = -1.0;
  best_mu = -1;
  for(size_t imu = 0; imu < tree.mus_miniso_tr10().size(); ++imu){
    if(min(tree.mus_reliso_r02().at(imu),tree.mus_miniso_tr10().at(imu)) < 0.4){
      if(!(tree.mus_sigid().at(imu) && tree.mus_pt().at(imu)>20)) continue;
      ++num_mus;
      if(tree.mus_pt().at(imu) > max_pt){
        max_pt = tree.mus_pt().at(imu);
        best_mu = imu;
      }
    }
  }
  return num_mus;
}

int VetoStandardIso(const small_tree &tree,
                int &best_el,
                int &best_mu){
  int leps = VetoStandardEl(tree, best_el);
  leps += VetoStandardMu(tree, best_mu);
  Fix(tree, best_el, best_mu);
  return leps;
}

int VetoStandardEl(const small_tree &tree,
               int &best_el){
  int num_els = 0;
  double max_pt = -1.0;
  best_el = -1;
  for(size_t iel = 0; iel < tree.els_eta().size(); ++iel){
    if((fabs(tree.els_eta().at(iel))<=1.479 && tree.els_reliso_r03().at(iel)<0.3313)
       || (fabs(tree.els_eta().at(iel))>1.479&& fabs(tree.els_eta().at(iel))<2.5
           && tree.els_reliso_r03().at(iel)<0.3816)){
      if(!(tree.els_ispf().at(iel))) continue;
      ++num_els;
      if(tree.els_pt().at(iel) > max_pt){
        max_pt = tree.els_pt().at(iel);
        best_el = iel;
      }
    }
  }

  return num_els;
}

int VetoStandardMu(const small_tree &tree,
               int &best_mu){
  int num_mus = 0;
  double max_pt = -1.0;
  best_mu = -1;
  for(size_t imu = 0; imu < tree.mus_reliso_r04().size();  ++imu){
    if(tree.mus_reliso_r04().at(imu) < 0.2){
      ++num_mus;
      if(tree.mus_pt().at(imu) > max_pt){
        max_pt = tree.mus_pt().at(imu);
        best_mu = imu;
      }
    }
  }

  return num_mus;
}

int VetoMiniIso(const small_tree &tree,
            int &best_el,
            int &best_mu){
  int leps = VetoMiniEl(tree, best_el);
  leps += VetoMiniMu(tree, best_mu);
  Fix(tree, best_el, best_mu);
  return leps;
}

int VetoMiniEl(const small_tree &tree,
           int &best_el){
  int num_els = 0;
  double max_pt = -1.0;
  best_el = -1;
  for(size_t iel = 0; iel < tree.els_miniso_tr10().size(); ++iel){
    if(min(tree.els_reliso_r02().at(iel),tree.els_miniso_tr10().at(iel)) < 0.15){
      if(!(tree.els_ispf().at(iel))) continue;
      ++num_els;
      if(tree.els_pt().at(iel) > max_pt){
        max_pt = tree.els_pt().at(iel);
        best_el = iel;
      }
    }
  }
  return num_els;
}

int VetoMiniMu(const small_tree &tree,
           int &best_mu){
  int num_mus = 0;
  double max_pt = -1.0;
  best_mu = -1;
  for(size_t imu = 0; imu < tree.mus_miniso_tr10().size(); ++imu){
    if(min(tree.mus_reliso_r02().at(imu),tree.mus_miniso_tr10().at(imu)) < 0.4){
      ++num_mus;
      if(tree.mus_pt().at(imu) > max_pt){
        max_pt = tree.mus_pt().at(imu);
        best_mu = imu;
      }
    }
  }
  return num_mus;
}

void PositiveColors(int pos_cols[]){
  const unsigned num_conts = 999;
  const unsigned num_stops = 2;
  double stops[num_stops] = {0., 1.};
  double red[num_stops] = {1., 0.3};
  double green[num_stops] = {1., 0.3};
  double blue[num_stops] = {1., 1.};
  gStyle->SetNumberContours(num_conts);
  int index = TColor::CreateGradientColorTable(num_stops, stops, red, green, blue, num_conts);
  for(int i = 0; i < 999; ++i){
    pos_cols[i] = index+i;
  }
}

void SymmetricColors(int sym_cols[]){
  const unsigned num_conts = 999;
  const unsigned num_stops = 3;
  double stops[num_stops] = {0., 0.5, 1.};
  double red[num_stops] = {1., 1., 0.};
  double green[num_stops] = {0., 1., 1.};
  double blue[num_stops] = {0., 1., 0.};
  gStyle->SetNumberContours(num_conts);
  int index = TColor::CreateGradientColorTable(num_stops, stops, red, green, blue, num_conts);
  for(int i = 0; i < 999; ++i){
    sym_cols[i] = index+i;
  }
}

void SetLineStyle(TLine &line){
  line.SetLineWidth(4);
  line.SetLineColor(1);
  line.SetLineStyle(1);
}
