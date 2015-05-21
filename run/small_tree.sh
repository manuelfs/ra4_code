#! /bin/bash

type=quick
maxfiles=50
if (( "$#" >= 1 ))
then
    maxfiles=$1
fi

## Signal
./run/send_small_tree.sh /cms2r0/cfA/SMS-T1bbbb_2J_mGl-1000_mLSP-900_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1_MINIAODSIM_UCSB2365_v78	$type	$maxfiles
./run/send_small_tree.sh /cms2r0/cfA/SMS-T1bbbb_2J_mGl-1500_mLSP-100_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1_MINIAODSIM_UCSB2364_v78	$type	$maxfiles
./run/send_small_tree.sh /cms2r0/cfA/SMS-T1qqqq_2J_mGl-1000_mLSP-800_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1_MINIAODSIM_UCSB2367_v78	$type	$maxfiles
./run/send_small_tree.sh /cms2r0/cfA/SMS-T1qqqq_2J_mGl-1400_mLSP-100_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1_MINIAODSIM_UCSB2366_v78	$type	$maxfiles
./run/send_small_tree.sh /cms2r0/cfA/SMS-T1tttt_2J_mGl-1200_mLSP-800_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1_MINIAODSIM_UCSB2363_v78	$type	$maxfiles
./run/send_small_tree.sh /cms2r0/cfA/SMS-T1tttt_2J_mGl-1500_mLSP-100_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1_MINIAODSIM_UCSB2377_v78	$type	$maxfiles

## QCD
./run/send_small_tree.sh /cms2r0/cfA/QCD_Pt-1000to1400_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v1_MINIAODSIM_UCSB2372_v78	$type	$maxfiles
./run/send_small_tree.sh /cms2r0/cfA/QCD_Pt-1400to1800_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v1_MINIAODSIM_UCSB2371_v78	$type	$maxfiles
./run/send_small_tree.sh /cms2r0/cfA/QCD_Pt-1800to2400_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_PHYS14_25_V1-v2_MINIAODSIM_UCSB2370_v78	$type	$maxfiles
./run/send_small_tree.sh /cms2r0/cfA/QCD_Pt-2400to3200_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_PHYS14_25_V1-v1_MINIAODSIM_UCSB2369_v78	$type	$maxfiles
./run/send_small_tree.sh /cms2r0/cfA/QCD_Pt-300to470_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v2_MINIAODSIM_UCSB2376_v78	$type	$maxfiles
./run/send_small_tree.sh /cms2r0/cfA/QCD_Pt-3200_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_PHYS14_25_V1-v1_MINIAODSIM_UCSB2368_v78	$type	$maxfiles
./run/send_small_tree.sh /cms2r0/cfA/QCD_Pt-470to600_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v2_MINIAODSIM_UCSB2375_v78	$type	$maxfiles
./run/send_small_tree.sh /cms2r0/cfA/QCD_Pt-600to800_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v1_MINIAODSIM_UCSB2374_v78	$type	$maxfiles
./run/send_small_tree.sh /cms2r0/cfA/QCD_Pt-800to1000_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v2_MINIAODSIM_UCSB2373_v78	$type	$maxfiles

## ttbar
./run/send_small_tree.sh /cms2r0/cfA/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2406_v78	$type	$maxfiles

## WJets
./run/send_small_tree.sh /cms2r0/cfA/WJetsToLNu_HT-100to200_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2407_v78	$type	$maxfiles
./run/send_small_tree.sh /cms2r0/cfA/WJetsToLNu_HT-200to400_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2405_v78	$type	$maxfiles
./run/send_small_tree.sh /cms2r0/cfA/WJetsToLNu_HT-400to600_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2398_v78	$type	$maxfiles
./run/send_small_tree.sh /cms2r0/cfA/WJetsToLNu_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2397_v78	$type	$maxfiles

## ZJets
./run/send_small_tree.sh /cms2r0/cfA/ZJetsToNuNu_HT-100to200_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2408_v78	$type	$maxfiles
./run/send_small_tree.sh /cms2r0/cfA/ZJetsToNuNu_HT-200to400_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2381_v78	$type	$maxfiles
./run/send_small_tree.sh /cms2r0/cfA/ZJetsToNuNu_HT-400to600_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v2_MINIAODSIM_UCSB2380_v78	$type	$maxfiles
./run/send_small_tree.sh /cms2r0/cfA/ZJetsToNuNu_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2379_v78	$type	$maxfiles

## Drell-Yan
./run/send_small_tree.sh /cms2r0/cfA/DYJetsToLL_M-50_HT-100to200_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2413_v78	$type	$maxfiles
./run/send_small_tree.sh /cms2r0/cfA/DYJetsToLL_M-50_HT-200to400_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2417_v78	$type	$maxfiles
./run/send_small_tree.sh /cms2r0/cfA/DYJetsToLL_M-50_HT-400to600_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2418_v78	$type	$maxfiles
./run/send_small_tree.sh /cms2r0/cfA/DYJetsToLL_M-50_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2419_v78	$type	$maxfiles

## Single top
./run/send_small_tree.sh /cms2r0/cfA/TBarToLeptons_s-channel-CSA14_Tune4C_13TeV-aMCatNLO-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2411_v78	$type	$maxfiles
./run/send_small_tree.sh /cms2r0/cfA/TBarToLeptons_t-channel_Tune4C_CSA14_13TeV-aMCatNLO-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2412_v78	$type	$maxfiles
./run/send_small_tree.sh /cms2r0/cfA/Tbar_tW-channel-DR_Tune4C_13TeV-CSA14-powheg-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2395_v78	$type	$maxfiles
./run/send_small_tree.sh /cms2r0/cfA/TToLeptons_s-channel-CSA14_Tune4C_13TeV-aMCatNLO-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2410_v78	$type	$maxfiles
./run/send_small_tree.sh /cms2r0/cfA/TToLeptons_t-channel-CSA14_Tune4C_13TeV-aMCatNLO-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2409_v78	$type	$maxfiles
./run/send_small_tree.sh /cms2r0/cfA/T_tW-channel-DR_Tune4C_13TeV-CSA14-powheg-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2393_v78	$type	$maxfiles

## TTV, VH
./run/send_small_tree.sh /cms2r0/cfA/TTbarH_M-125_13TeV_amcatnlo-pythia8-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v2_MINIAODSIM_UCSB2391_v78	$type	$maxfiles
./run/send_small_tree.sh /cms2r0/cfA/TTWJets_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2390_v78	$type	$maxfiles
./run/send_small_tree.sh /cms2r0/cfA/TTZJets_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2384_v78	$type	$maxfiles
./run/send_small_tree.sh /cms2r0/cfA/WH_HToBB_WToLNu_M-125_13TeV_powheg-herwigpp_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1_MINIAODSIM_UCSB2382_v78	$type	$maxfiles
./run/send_small_tree.sh /cms2r0/cfA/ZH_HToBB_ZToNuNu_M-125_13TeV_powheg-herwigpp_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1_MINIAODSIM_UCSB2392_v78	$type	$maxfiles

## GJets
./run/send_small_tree.sh /cms2r0/cfA/GJets_HT-100to200_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2360_v78	$type	$maxfiles
./run/send_small_tree.sh /cms2r0/cfA/GJets_HT-200to400_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2359_v78	$type	$maxfiles
./run/send_small_tree.sh /cms2r0/cfA/GJets_HT-400to600_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2358_v78	$type	$maxfiles
./run/send_small_tree.sh /cms2r0/cfA/GJets_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2357_v78	$type	$maxfiles

exit 0;
