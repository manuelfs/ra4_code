#include "roc_sorb_plots.hpp"

#include <ctime>
#include <cstdlib>
#include <cmath>

#include <iostream>
#include <sstream>
#include <vector>
#include <utility>
#include <string>
#include <stdexcept>
#include <unistd.h>

#include "TChain.h"
#include "TH1D.h"
#include "TGraph.h"
#include "TCanvas.h"
#include "TLegend.h"

#include "styles.hpp"
#include "dataset.hpp"
#include "sample.hpp"
#include "selection.hpp"
#include "cut.hpp"
#include "utilities.hpp"

int main(int argc, char* argv[]){
  styles style("Standard"); style.setDefaultStyle();
  int opt(0);
  Dataset::SampleSet dataset_num(Dataset::kSignalBackground);
  Selection::CutSet selection_num(Selection::kStandard);
  Cut weight("weight");

  while((opt=getopt(argc, argv, "d:s:"))!=-1){
    switch(opt){
    case 'd': dataset_num=static_cast<Dataset::SampleSet>(strtoul(optarg, NULL, 0)); break;
    case 's': selection_num=static_cast<Selection::CutSet>(strtoul(optarg, NULL, 0)); break;
    default: break;
    }
  }

  const Dataset dataset(dataset_num);
  const Selection sel(selection_num);

  std::vector<ROCdef> roc_defs(0);
  roc_defs.push_back(ROCdef("mt2_ref_max", lin_bins(100, 0.0, 500.0)));//0
  roc_defs.push_back(ROCdef("mt2_ref_min", lin_bins(100, 0.0, 500.0)));//1
  roc_defs.push_back(ROCdef("mt2_highPt", lin_bins(100, 0.0, 500.0)));//2
  roc_defs.push_back(ROCdef("mt2_highCSV", lin_bins(100, 0.0, 500.0)));//3

  roc_defs.push_back(ROCdef("mt2w_ref_max", lin_bins(100, 0.0, 500.0)));//4
  roc_defs.push_back(ROCdef("mt2w_ref_min", lin_bins(100, 0.0, 500.0)));//5
  roc_defs.push_back(ROCdef("mt2w_highPt", lin_bins(100, 0.0, 500.0)));//6
  roc_defs.push_back(ROCdef("mt2w_highCSV", lin_bins(100, 0.0, 500.0)));//7

  roc_defs.push_back(ROCdef("mbl_max", lin_bins(100, 0.0, 500.0)));//8
  roc_defs.push_back(ROCdef("mbl_subleading", lin_bins(100, 0.0, 500.0)));//9
  roc_defs.push_back(ROCdef("mbl_min", lin_bins(100, 0.0, 500.0)));//10
  roc_defs.push_back(ROCdef("mbl_highPt", lin_bins(100, 0.0, 500.0)));//11
  roc_defs.push_back(ROCdef("mbl_highCSV", lin_bins(100, 0.0, 500.0)));//12

  roc_defs.push_back(ROCdef("nbt", lin_bins(6, -0.5, 5.5)));//13
  roc_defs.push_back(ROCdef("nbm", lin_bins(6, -0.5, 5.5)));//14
  roc_defs.push_back(ROCdef("nbl", lin_bins(6, -0.5, 5.5)));//15

  roc_defs.push_back(ROCdef("ht", lin_bins(100, 0.0, 1000.0)));//16
  roc_defs.push_back(ROCdef("met", lin_bins(100, 0.0, 1000.0)));//17
  roc_defs.push_back(ROCdef("mj", lin_bins(100, 0.0, 1000.0)));//18

  roc_defs.push_back(ROCdef("mt", lin_bins(100, 0.0, 200.0)));//19

  std::vector<std::pair<TH1D, std::vector<TH1D> > > roc_histos(0);
  GetROCHistos(dataset, sel, roc_defs, roc_histos);
  
  std::vector<std::vector<TGraph> > rocs(0);
  GetROCs(roc_histos, rocs);

  std::vector<std::vector<TH1D> > sorbs(0);
  GetSORBs(roc_histos, sorbs);

  std::vector<unsigned> mt2_indices;
  mt2_indices.push_back(0);
  mt2_indices.push_back(1);
  mt2_indices.push_back(2);
  mt2_indices.push_back(3);

  std::vector<unsigned> mt2w_indices;
  mt2w_indices.push_back(4);
  mt2w_indices.push_back(5);
  mt2w_indices.push_back(6);
  mt2w_indices.push_back(7);

  std::vector<unsigned> mbl_indices;
  mbl_indices.push_back(8);
  mbl_indices.push_back(9);
  mbl_indices.push_back(10);
  mbl_indices.push_back(11);
  mbl_indices.push_back(12);

  std::vector<unsigned> mt2_def_indices;
  mt2_def_indices.push_back(0);
  mt2_def_indices.push_back(4);
  mt2_def_indices.push_back(9);

  std::vector<unsigned> btag_indices;
  btag_indices.push_back(13);
  btag_indices.push_back(14);
  btag_indices.push_back(15);

  std::vector<unsigned> ht_indices;
  ht_indices.push_back(16);
  ht_indices.push_back(17);
  ht_indices.push_back(18);

  std::vector<unsigned> mt_indices;
  mt_indices.push_back(19);

  DrawROCs(dataset, roc_defs, rocs, mt2_indices, "mt2");
  DrawROCs(dataset, roc_defs, rocs, mt2w_indices, "mt2w");
  DrawROCs(dataset, roc_defs, rocs, mbl_indices, "mbl_def");
  DrawROCs(dataset, roc_defs, rocs, mt2_def_indices, "mt2_def");
  DrawROCs(dataset, roc_defs, rocs, btag_indices, "btag");
  DrawROCs(dataset, roc_defs, rocs, ht_indices, "ht");
  DrawROCs(dataset, roc_defs, rocs, mt_indices, "mt");

  DrawSORBs(dataset, roc_defs, sorbs, mt2_indices, "mt2", "m_{T2}^{b} cut [GeV]");
  DrawSORBs(dataset, roc_defs, sorbs, mt2w_indices, "mt2w", "m_{T2}^{W} cut [GeV]");
  DrawSORBs(dataset, roc_defs, sorbs, mbl_indices, "mbl", "m_{bl} cut [GeV]");
  DrawSORBs(dataset, roc_defs, sorbs, mt2_def_indices, "mt2_def", "Cut Threshold [GeV]");
  DrawSORBs(dataset, roc_defs, sorbs, btag_indices, "btag", "Num b-tags Cut");
  DrawSORBs(dataset, roc_defs, sorbs, ht_indices, "ht", "Cut Threshold [GeV]");
  DrawSORBs(dataset, roc_defs, sorbs, mt_indices, "mt", "m_{T} cut [GeV]");
}


std::vector<float> lin_bins(const unsigned bins, double low, double high){
  if(high<low){
    double temp=high;
    high=low;
    low=temp;
  }

  if(bins==0){
    std::vector<float> ret_val(2);
    ret_val.at(0)=low;
    ret_val.at(1)=high;
    return ret_val;
  }

  const double spacing = (high-low)/bins;
  std::vector<float> ret_val(bins+1);
  for(unsigned i = 0; i <= bins; ++i){
    ret_val.at(i) = low+i*spacing;
  }

  return ret_val;
}

void GetROCHistos(const Dataset &dataset,
                  const Selection &selection,
                  const std::vector<ROCdef> &roc_defs,
                  std::vector<std::pair<TH1D, std::vector<TH1D> > > &roc_histos){
  TChain &background = dataset.GetBackgroundSamples().at(0)->chain();
  roc_histos.clear();
  roc_histos.resize(roc_defs.size());
  Cut weight("weight");

  for(unsigned plot = 0; plot < roc_defs.size(); ++plot){
    std::cout << "Computing histogram " << plot+1 << " of " << roc_defs.size() << '.' << std::endl;
    const std::string cut = (weight*selection.IndependentBaselineCut(roc_defs.at(plot).first)).CutString();
    const std::string var_name = roc_defs.at(plot).first;
    std::cout << var_name << ": " << cut << std::endl;
    GetHisto(var_name, cut, roc_defs.at(plot).second, background, roc_histos.at(plot).first, "_back");

    roc_histos.at(plot).second.resize(dataset.GetSignalSamples().size());
    for(unsigned n_sig = 0; n_sig<dataset.GetSignalSamples().size(); ++n_sig){
      TChain &signal = dataset.GetSignalSamples().at(n_sig)->chain();
      std::ostringstream oss("");
      oss << '_' << n_sig;
      GetHisto(var_name, cut, roc_defs.at(plot).second, signal, roc_histos.at(plot).second.at(n_sig), oss.str());
    }
  }
}

void GetHisto(const std::string &var_name,
              const std::string &cut,
              const std::vector<float> &bins,
              TChain &chain,
              TH1D &histo,
              const std::string &append){
  histo = TH1D(("h_"+var_name+append).c_str(), cut.c_str(), bins.size()-1, &bins.at(0));
  histo.Sumw2();
  chain.Project(histo.GetName(), var_name.c_str(), cut.c_str());
  for(int bin = 0; bin <= histo.GetNbinsX()+1; ++bin){
    double uncertainty;
    const double content = histo.IntegralAndError(bin, histo.GetNbinsX()+1, uncertainty);
    histo.SetBinContent(bin, content);
    histo.SetBinError(bin, uncertainty);
  }
}

void GetROCs(const std::vector<std::pair<TH1D, std::vector<TH1D> > > &roc_histos,
             std::vector<std::vector<TGraph> > &rocs){
  rocs.resize(roc_histos.size());
  for(unsigned var = 0; var < roc_histos.size(); ++var){
    const TH1D &background = roc_histos.at(var).first;
    rocs.at(var).resize(roc_histos.at(var).second.size());
    const unsigned npts(background.GetNbinsX());
    std::vector<double> background_eff(npts);
    GetPoints(background, background_eff, true);
    for(unsigned sig = 0; sig < roc_histos.at(var).second.size(); ++sig){
      std::vector<double> signal_eff(npts);
      const TH1D &signal = roc_histos.at(var).second.at(sig);
      GetPoints(signal, signal_eff, false);
      rocs.at(var).at(sig) = TGraph(background_eff.size(), &signal_eff.at(0), &background_eff.at(0));
    }
  }
}

void GetSORBs(const std::vector<std::pair<TH1D, std::vector<TH1D> > > &roc_histos,
              std::vector<std::vector<TH1D> > &sobs){
  sobs.resize(roc_histos.size());
  for(unsigned var = 0; var < roc_histos.size(); ++var){
    const TH1D &back = roc_histos.at(var).first;
    sobs.at(var).resize(roc_histos.at(var).second.size());
    for(unsigned sign = 0; sign < roc_histos.at(var).second.size(); ++sign){
      TH1D &out = sobs.at(var).at(sign);
      out = back;
      out.SetStats(false);
      const TH1D &sig = roc_histos.at(var).second.at(sign);
      for(int bin = 0; bin <= out.GetNbinsX()+1; ++bin){
        const double num = sig.GetBinContent(bin);
        const double den = back.GetBinContent(bin);
        const double num_e = sig.GetBinError(bin);
        const double den_e = back.GetBinError(bin);
	if(den>0.0){
	  out.SetBinContent(bin, num/sqrt(den));
	  out.SetBinError(bin, sqrt(num_e*num_e/den + num*num*den_e*den_e/(4.0*den*den*den)));
	}else{
	  out.SetBinContent(bin, 0.0);
	  out.SetBinError(bin, 0.0);
	}
      }
    }
  }
}

void GetPoints(const TH1D &hist, std::vector<double> &pts, const bool use_rejection){
  pts.resize(hist.GetNbinsX()+1);
  for(int bin = 1; bin <= hist.GetNbinsX()+1; ++bin){
    pts.at(bin-1)=hist.GetBinContent(bin)/hist.GetBinContent(0);
    if(use_rejection){
      pts.at(bin-1)=1.0-pts.at(bin-1);
    }
  }
}

void DrawROCs(const Dataset &dataset,
	      const std::vector<ROCdef> &defs,
              std::vector<std::vector<TGraph> > &rocs,
              const std::vector<unsigned> &indices,
              const std::string &out_file){
  TH1D h("dummy_histogram", "", 1, 0.0, 1.0);
  h.SetTitle(";Signal Efficiency;Background Rejection");
  h.SetMinimum(0.0);
  h.SetMaximum(1.0);
  h.SetStats(0);

  const std::string full_file = "eps/roc_"+out_file+".eps";

  TCanvas c;
  c.Range(0.0,0.0,1.0,1.0);
  TLegend l(0.2, 0.2, 0.5, 0.4);
  l.SetFillColor(0);
  l.SetFillStyle(0);
  l.SetBorderSize(0);
  //loop over curves to plot
  for(unsigned meta_index = 0; meta_index < indices.size(); ++meta_index){
    const unsigned i = indices.at(meta_index);
    std::vector<TGraph>& curves = rocs.at(i);
    //loop over signal samples
    for(unsigned curve = 0; curve < curves.size(); ++ curve){
      TGraph &graph = curves.at(curve);
      graph.SetTitle(";Signal Efficiency;Background Rejection");
      graph.SetLineColor(GetColor(meta_index));
      graph.SetMarkerColor(GetColor(meta_index));
      graph.SetLineStyle(GetLineStyle(curve));
      
      if(curve == 0 && meta_index == 0){
	h.Draw("hist");
      }
      graph.Draw("lsame");
      const std::string sig_name = dataset.GetSignalSamples().at(curve)->chain().GetName();
      const std::string entry = defs.at(i).first+", "+sig_name;
      l.AddEntry(&graph, entry.c_str(), "lp");
    }
  }
  l.Draw("same");
  c.Print(full_file.c_str());
}

void DrawSORBs(const Dataset &dataset,
	       const std::vector<ROCdef> &defs,
               std::vector<std::vector<TH1D> > &sorbs,
               const std::vector<unsigned> &indices,
               const std::string &out_file,
	       const std::string &xtitle){
  const std::string full_file = "eps/sorb_"+out_file+".eps";
  TCanvas c;
  TLegend l(0.2, 0.7, 0.5, 0.9);
  l.SetFillColor(0);
  l.SetFillStyle(0);
  l.SetBorderSize(0);
  //loop over curves to plot
  for(unsigned meta_index = 0; meta_index < indices.size(); ++meta_index){
    const unsigned i = indices.at(meta_index);
    std::vector<TH1D>& curves = sorbs.at(i);
    //loop over signal samples
    for(unsigned curve = 0; curve < curves.size(); ++ curve){
      TH1D &hist = curves.at(curve);
      hist.SetTitle((";"+xtitle+";S/#sqrt{B}").c_str());
      hist.SetMinimum(0.0);
      hist.SetMaximum(5.0);
      hist.SetLineColor(GetColor(meta_index));
      hist.SetMarkerColor(GetColor(meta_index));
      hist.SetLineStyle(GetLineStyle(curve));
      
      if(curve == 0 && meta_index == 0){
        hist.Draw("hist");
      }else{
        hist.Draw("histsame");
      }
      const std::string sig_name = dataset.GetSignalSamples().at(curve)->chain().GetName();
      const std::string entry = defs.at(i).first+", "+sig_name;
      l.AddEntry(&hist, entry.c_str(), "lp");
    }
  }
  l.Draw("same");
  c.Print(full_file.c_str());
}

int GetColor(const unsigned col){
  if(col<1){
    return 1;
  }else if(col<4){
    return col+1;
  }else{
    return col+2;
  }
}

int GetLineStyle(const unsigned i){
  return i+1;
}
