#! /bin/bash

maxfiles=100
if (( "$#" >= 1 ))
then
    maxfiles=$1
fi

# T1tttt @ 13 TeV
./run/send_small_tree.sh /cms2r0/cfA/SMS-T1tttt_2J_mGl-1200_mLSP-800_Tune4C_13TeV-madgraph-tauola-Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2085_v73   $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/SMS-T1tttt_2J_mGl-1500_mLSP-100_Tune4C_13TeV-madgraph-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2120_v73   $maxfiles

# tt @ 13 TeV
./run/send_small_tree.sh /cms2r0/cfA/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola-Spring14miniaod-PU20bx25_POSTLS170_V5-v2_MINIAODSIM_UCSB2087_v73 $maxfiles

# QCD @13TeV
./run/send_small_tree.sh /cms2r0/cfA/QCD_Pt-3200_Tune4C_13TeV_pythia8_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2136_v73               $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/QCD_Pt-2400to3200_Tune4C_13TeV_pythia8_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2099_v73         $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/QCD_Pt-1800to2400_Tune4C_13TeV_pythia8_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2100_v73         $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/QCD_Pt-1400to1800_Tune4C_13TeV_pythia8_Spring14miniaod-castor_PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2101_v73  $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/QCD_Pt-1000to1400_Tune4C_13TeV_pythia8_Spring14miniaod-castor_PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2118_v73  $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/QCD_Pt-800to1000_Tune4C_13TeV_pythia8_Spring14miniaod-castor_PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2130_v73   $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/QCD_Pt-600to800_Tune4C_13TeV_pythia8_Spring14miniaod-castor_PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2138_v73    $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/QCD_Pt-470to600_Tune4C_13TeV_pythia8_Spring14miniaod-castor_PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2137_v73    $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/QCD_Pt-300to470_Tune4C_13TeV_pythia8_Spring14miniaod-castor_PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2135_v73    $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/QCD_Pt-170to300_Tune4C_13TeV_pythia8_Spring14miniaod-castor_PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2098_v73    $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/QCD_Pt-120to170_Tune4C_13TeV_pythia8_Spring14miniaod-castor_PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2109_v73    $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/QCD_Pt-80to120_Tune4C_13TeV_pythia8_Spring14miniaod-castor_PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2128_v73     $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/QCD_Pt-50to80_Tune4C_13TeV_pythia8_Spring14miniaod-castor_PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2127_v73      $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/QCD_Pt-30to50_Tune4C_13TeV_pythia8_Spring14miniaod-castor_PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2126_v73      $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/QCD_Pt-15to30_Tune4C_13TeV_pythia8_Spring14miniaod-castor_PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2104_v73      $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/QCD_Pt-10to15_Tune4C_13TeV_pythia8_Spring14miniaod-castor_PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2103_v73      $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/QCD_Pt-5to10_Tune4C_13TeV_pythia8_Spring14miniaod-castor_PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2125_v73       $maxfiles  

# W + jets @ 13 TeV
./run/send_small_tree.sh /cms2r0/cfA/WJetsToLNu_HT-100to200_Tune4C_13TeV-madgraph-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v2_MINIAODSIM_UCSB2097_v73   $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/WJetsToLNu_HT-200to400_Tune4C_13TeV-madgraph-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2096_v73   $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/WJetsToLNu_HT-400to600_Tune4C_13TeV-madgraph-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2121_v73   $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/WJetsToLNu_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2122_v73   $maxfiles  

# Single top
./run/send_small_tree.sh /cms2r0/cfA/T_tW-channel-DR_Tune4C_13TeV-CSA14-powheg-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2093_v73              $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/TToLeptons_t-channel-CSA14_Tune4C_13TeV-aMCatNLO-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v2_MINIAODSIM_UCSB2107_v73       $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/TToLeptons_s-channel-CSA14_Tune4C_13TeV-aMCatNLO-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2091_v73       $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/Tbar_tW-channel-DR_Tune4C_13TeV-CSA14-powheg-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2094_v73           $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/TBarToLeptons_t-channel_Tune4C_CSA14_13TeV-aMCatNLO-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2092_v73    $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/TBarToLeptons_s-channel-CSA14_Tune4C_13TeV-aMCatNLO-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2090_v73    $maxfiles

# Drell-Yan
./run/send_small_tree.sh /cms2r0/cfA/DYJetsToLL_M-50_HT-100to200_Tune4C_13TeV-madgraph-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2113_v73   $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/DYJetsToLL_M-50_HT-200to400_Tune4C_13TeV-madgraph-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2114_v73   $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/DYJetsToLL_M-50_HT-400to600_Tune4C_13TeV-madgraph-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2117_v73   $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/DYJetsToLL_M-50_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2115_v73   $maxfiles

exit 0;
