#! /bin/bash

maxfiles=20
if (( "$#" >= 1 ))
then
    maxfiles=$1
fi

# T1tttt @ 13 TeV
./run/send_small_tree.sh /cms2r0/cfA/SMS-T1tttt_2J_mGl-1200_mLSP-800_Tune4C_13TeV-madgraph-tauola-Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2191_v75   $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/SMS-T1tttt_2J_mGl-1500_mLSP-100_Tune4C_13TeV-madgraph-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2194_v75   $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/SMS-T2tt_2J_mStop-650_mLSP-325_Tune4C_13TeV-madgraph-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2284_v75   $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/SMS-T2tt_2J_mStop-500_mLSP-325_Tune4C_13TeV-madgraph-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2283_v75   $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/SMS-T2tt_2J_mStop-425_mLSP-325_Tune4C_13TeV-madgraph-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2282_v75   $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/SMS-T1bbbb_2J_mGl-1000_mLSP-900_Tune4C_13TeV-madgraph-tauola-Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2196_v75   $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/SMS-T1bbbb_2J_mGl-1500_mLSP-100_Tune4C_13TeV-madgraph-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v2_MINIAODSIM_UCSB2195_v75   $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/SMS-T1qqqq_2J_mGl-1000_mLSP-800_Tune4C_13TeV-madgraph-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2280_v75   $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/SMS-T1qqqq_2J_mGl-1400_mLSP-100_Tune4C_13TeV-madgraph-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2279_v75   $maxfiles



# tt @ 13 TeV
./run/send_small_tree.sh /cms2r0/cfA/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola-Spring14miniaod-PU20bx25_POSTLS170_V5-v2_MINIAODSIM_UCSB2193_v75 $maxfiles

# QCD @13TeV
./run/send_small_tree.sh /cms2r0/cfA/QCD_Pt-3200_Tune4C_13TeV_pythia8_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2172_v75               $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/QCD_Pt-2400to3200_Tune4C_13TeV_pythia8_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2169_v75         $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/QCD_Pt-1800to2400_Tune4C_13TeV_pythia8_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2175_v75         $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/QCD_Pt-1400to1800_Tune4C_13TeV_pythia8_Spring14miniaod-castor_PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2165_v75  $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/QCD_Pt-1000to1400_Tune4C_13TeV_pythia8_Spring14miniaod-castor_PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2162_v75  $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/QCD_Pt-800to1000_Tune4C_13TeV_pythia8_Spring14miniaod-castor_PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2198_v75   $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/QCD_Pt-600to800_Tune4C_13TeV_pythia8_Spring14miniaod-castor_PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2183_v75    $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/QCD_Pt-470to600_Tune4C_13TeV_pythia8_Spring14miniaod-castor_PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2181_v75    $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/QCD_Pt-300to470_Tune4C_13TeV_pythia8_Spring14miniaod-castor_PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2170_v75    $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/QCD_Pt-170to300_Tune4C_13TeV_pythia8_Spring14miniaod-castor_PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2174_v75    $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/QCD_Pt-120to170_Tune4C_13TeV_pythia8_Spring14miniaod-castor_PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2164_v75    $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/QCD_Pt-80to120_Tune4C_13TeV_pythia8_Spring14miniaod-castor_PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2197_v75     $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/QCD_Pt-50to80_Tune4C_13TeV_pythia8_Spring14miniaod-castor_PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2200_v75      $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/QCD_Pt-30to50_Tune4C_13TeV_pythia8_Spring14miniaod-castor_PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2171_v75      $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/QCD_Pt-15to30_Tune4C_13TeV_pythia8_Spring14miniaod-castor_PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2166_v75      $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/QCD_Pt-10to15_Tune4C_13TeV_pythia8_Spring14miniaod-castor_PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2163_v75      $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/QCD_Pt-5to10_Tune4C_13TeV_pythia8_Spring14miniaod-castor_PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2199_v75       $maxfiles  

# W + jets @ 13 TeV
./run/send_small_tree.sh /cms2r0/cfA/WJetsToLNu_HT-100to200_Tune4C_13TeV-madgraph-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v2_MINIAODSIM_UCSB2192_v75   $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/WJetsToLNu_HT-200to400_Tune4C_13TeV-madgraph-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2190_v75   $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/WJetsToLNu_HT-400to600_Tune4C_13TeV-madgraph-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2189_v75   $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/WJetsToLNu_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2188_v75   $maxfiles  

# Single top
./run/send_small_tree.sh /cms2r0/cfA/T_tW-channel-DR_Tune4C_13TeV-CSA14-powheg-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2142_v75              $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/TToLeptons_t-channel-CSA14_Tune4C_13TeV-aMCatNLO-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v2_MINIAODSIM_UCSB2156_v75       $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/TToLeptons_s-channel-CSA14_Tune4C_13TeV-aMCatNLO-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2154_v75       $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/Tbar_tW-channel-DR_Tune4C_13TeV-CSA14-powheg-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2150_v75           $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/TBarToLeptons_t-channel_Tune4C_CSA14_13TeV-aMCatNLO-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2148_v75    $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/TBarToLeptons_s-channel-CSA14_Tune4C_13TeV-aMCatNLO-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2146_v75    $maxfiles

# Drell-Yan
./run/send_small_tree.sh /cms2r0/cfA/DYJetsToLL_M-50_HT-100to200_Tune4C_13TeV-madgraph-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2160_v75   $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/DYJetsToLL_M-50_HT-200to400_Tune4C_13TeV-madgraph-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2161_v75   $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/DYJetsToLL_M-50_HT-400to600_Tune4C_13TeV-madgraph-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2206_v75   $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/DYJetsToLL_M-50_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2207_v75   $maxfiles

# Z -> nunu
./run/send_small_tree.sh ZJetsToNuNu_HT-100to200_Tune4C_13TeV-madgraph-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2187_v75  $maxfiles
./run/send_small_tree.sh ZJetsToNuNu_HT-200to400_Tune4C_13TeV-madgraph-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2186_v75  $maxfiles
./run/send_small_tree.sh ZJetsToNuNu_HT-400to600_Tune4C_13TeV-madgraph-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2185_v75  $maxfiles
./run/send_small_tree.sh ZJetsToNuNu_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v2_MINIAODSIM_UCSB2184_v75  $maxfiles

exit 0;
