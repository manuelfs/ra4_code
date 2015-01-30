#! /bin/bash

maxfiles=10
if (( "$#" >= 1 ))
then
    maxfiles=$1
fi

## Signal
./run/send_small_tree.sh /cms2r0/cfA/SMS-T1bbbb_2J_mGl-1000_mLSP-900_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1_MINIAODSIM_UCSB2288_v77	 $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/SMS-T1bbbb_2J_mGl-1500_mLSP-100_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1_MINIAODSIM_UCSB2300_v77	 $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/SMS-T1qqqq_2J_mGl-1000_mLSP-800_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1_MINIAODSIM_UCSB2303_v77	 $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/SMS-T1qqqq_2J_mGl-1400_mLSP-100_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1_MINIAODSIM_UCSB2302_v77	 $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/SMS-T1tttt_2J_mGl-1200_mLSP-800_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1_MINIAODSIM_UCSB2301_v77	 $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/SMS-T1tttt_2J_mGl-1500_mLSP-100_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1_MINIAODSIM_UCSB2299_v77	 $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/SMS-T2tt_2J_mStop-850_mLSP-100_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1_MINIAODSIM_UCSB2289_v77	 $maxfiles
## QCD: 2,004,219 + 3,214,312 + 1,130,720 events
./run/send_small_tree.sh /cms2r0/cfA/QCD_HT_1000ToInf_13TeV-madgraph_Phys14DR-PU20bx25_PHYS14_25_V1_ext1-v1_MINIAODSIM_UCSB2297_v77                              $maxfiles 1464453
./run/send_small_tree.sh /cms2r0/cfA/QCD_HT_1000ToInf_13TeV-madgraph_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2296_v77					 $maxfiles 1464453
#./run/send_small_tree.sh /cms2r0/cfA/QCD_HT-100To250_13TeV-madgraph_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2292_v77					 $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/QCD_HT-100To250_13TeV-madgraph_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2295_v77					 $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/QCD_HT_250To500_13TeV-madgraph_Phys14DR-PU20bx25_PHYS14_25_V1_ext1-v2_MINIAODSIM_UCSB2309_v77				 $maxfiles 2668172
./run/send_small_tree.sh /cms2r0/cfA/QCD_HT_250To500_13TeV-madgraph_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2308_v77					 $maxfiles 2668172
./run/send_small_tree.sh /cms2r0/cfA/QCD_HT-500To1000_13TeV-madgraph_Phys14DR-PU20bx25_PHYS14_25_V1_ext1-v1_MINIAODSIM_UCSB2294_v77				 $maxfiles 4063345
./run/send_small_tree.sh /cms2r0/cfA/QCD_HT-500To1000_13TeV-madgraph_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2293_v77					 $maxfiles 4063345
## ttbar
./run/send_small_tree.sh /cms2r0/cfA/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2290_v77		 $maxfiles
## WJets
./run/send_small_tree.sh /cms2r0/cfA/WJetsToLNu_HT-100to200_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2298_v77		 $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/WJetsToLNu_HT-200to400_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2304_v77		 $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/WJetsToLNu_HT-400to600_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2305_v77		 $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/WJetsToLNu_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2306_v77               $maxfiles

## ZJets
./run/send_small_tree.sh /cms2r0/cfA/ZJetsToNuNu_HT-100to200_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2332_v77         $maxfiles 
./run/send_small_tree.sh /cms2r0/cfA/ZJetsToNuNu_HT-200to400_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2333_v77	    $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/ZJetsToNuNu_HT-400to600_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v2_MINIAODSIM+_UCSB2344_v77	    $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/ZJetsToNuNu_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM+_UCSB2346_v77	    $maxfiles

## Drell-Yan
./run/send_small_tree.sh /cms2r0/cfA/DYJetsToLL_M-50_HT-100to200_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2337_v77	    $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/DYJetsToLL_M-50_HT-200to400_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2336_v77	    $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/DYJetsToLL_M-50_HT-400to600_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2335_v77	    $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/DYJetsToLL_M-50_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2334_v77	    $maxfiles

## Single top
./run/send_small_tree.sh /cms2r0/cfA/TBarToLeptons_s-channel-CSA14_Tune4C_13TeV-aMCatNLO-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2343_v77   $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/TBarToLeptons_t-channel_Tune4C_CSA14_13TeV-aMCatNLO-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2342_v77   $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/Tbar_tW-channel-DR_Tune4C_13TeV-CSA14-powheg-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2339_v77	    $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/TTbarH_M-125_13TeV_amcatnlo-pythia8-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v2_MINIAODSIM_UCSB2349_v77		    $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/TToLeptons_s-channel-CSA14_Tune4C_13TeV-aMCatNLO-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2340_v77	    $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/TToLeptons_t-channel-CSA14_Tune4C_13TeV-aMCatNLO-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2341_v77	    $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/T_tW-channel-DR_Tune4C_13TeV-CSA14-powheg-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2338_v77		    $maxfiles

./run/send_small_tree.sh /cms2r0/cfA/TTWJets_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2347_v77			    $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/TTZJets_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2348_v77                         $maxfiles 
./run/send_small_tree.sh /cms2r0/cfA/WH_HToBB_WToLNu_M-125_13TeV_powheg-herwigpp_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1_MINIAODSIM_UCSB2350_v77      $maxfiles 
./run/send_small_tree.sh /cms2r0/cfA/ZH_HToBB_ZToNuNu_M-125_13TeV_powheg-herwigpp_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1_MINIAODSIM_UCSB2351_v77     $maxfiles 

## Pt-binned QCD
./run/send_small_tree.sh /cms2r0/cfA/QCD_Pt-1000to1400_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v1_MINIAODSIM_UCSB2322_v77    $maxfiles 
./run/send_small_tree.sh /cms2r0/cfA/QCD_Pt-120to170_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v2_MINIAODSIM_UCSB2326_v77      $maxfiles 
./run/send_small_tree.sh /cms2r0/cfA/QCD_Pt-1400to1800_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v1_MINIAODSIM_UCSB2315_v77    $maxfiles 
./run/send_small_tree.sh /cms2r0/cfA/QCD_Pt-1800to2400_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_PHYS14_25_V1-v2_MINIAODSIM_UCSB2312_v77	        $maxfiles 
./run/send_small_tree.sh /cms2r0/cfA/QCD_Pt-2400to3200_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_PHYS14_25_V1-v1_MINIAODSIM_UCSB2314_v77	        $maxfiles 
./run/send_small_tree.sh /cms2r0/cfA/QCD_Pt-300to470_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v2_MINIAODSIM_UCSB2325_v77      $maxfiles 
./run/send_small_tree.sh /cms2r0/cfA/QCD_Pt-30to50_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v1_MINIAODSIM_UCSB2329_v77        $maxfiles 
./run/send_small_tree.sh /cms2r0/cfA/QCD_Pt-3200_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_PHYS14_25_V1-v1_MINIAODSIM_UCSB2317_v77		        $maxfiles 
./run/send_small_tree.sh /cms2r0/cfA/QCD_Pt-470to600_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v2_MINIAODSIM_UCSB2324_v77      $maxfiles 
./run/send_small_tree.sh /cms2r0/cfA/QCD_Pt-50to80_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v2_MINIAODSIM_UCSB2328_v77        $maxfiles 
./run/send_small_tree.sh /cms2r0/cfA/QCD_Pt-600to800_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v1_MINIAODSIM_UCSB2318_v77      $maxfiles 
./run/send_small_tree.sh /cms2r0/cfA/QCD_Pt-800to1000_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v2_MINIAODSIM_UCSB2316_v77     $maxfiles 
./run/send_small_tree.sh /cms2r0/cfA/QCD_Pt-80to120_Tune4C_13TeV_pythia8_Phys14DR-PU20bx25_trkalmb_castor_PHYS14_25_V1-v2_MINIAODSIM_UCSB2327_v77       $maxfiles 


exit 0;
