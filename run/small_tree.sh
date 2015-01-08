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
./run/send_small_tree.sh /cms2r0/cfA/QCD_HT_1000ToInf_13TeV-madgraph_Phys14DR-PU20bx25_PHYS14_25_V1_ext1-v1_MINIAODSIM_UCSB2297_v77                              $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/QCD_HT_1000ToInf_13TeV-madgraph_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2296_v77					 $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/QCD_HT-100To250_13TeV-madgraph_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2292_v77					 $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/QCD_HT-100To250_13TeV-madgraph_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2295_v77					 $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/QCD_HT_250To500_13TeV-madgraph_Phys14DR-PU20bx25_PHYS14_25_V1_ext1-v2_MINIAODSIM_UCSB2309_v77				 $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/QCD_HT_250To500_13TeV-madgraph_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2308_v77					 $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/QCD_HT-500To1000_13TeV-madgraph_Phys14DR-PU20bx25_PHYS14_25_V1_ext1-v1_MINIAODSIM_UCSB2294_v77				 $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/QCD_HT-500To1000_13TeV-madgraph_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2293_v77					 $maxfiles
## ttbar
./run/send_small_tree.sh /cms2r0/cfA/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2290_v77		 $maxfiles
## WJets
./run/send_small_tree.sh /cms2r0/cfA/WJetsToLNu_HT-100to200_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2298_v77		 $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/WJetsToLNu_HT-200to400_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2304_v77		 $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/WJetsToLNu_HT-400to600_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2305_v77		 $maxfiles
./run/send_small_tree.sh /cms2r0/cfA/WJetsToLNu_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2306_v77               $maxfiles


exit 0;
