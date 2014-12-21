#! /bin/bash

maxfiles=10
if (( "$#" >= 1 ))
then
    maxfiles=$1
fi

# ## ttbar: 2,991,609 events
# ./run/send_small_tree.sh /cms2r0/manuelf/cfa/phys14/TT_Tune4C_13TeV-pythia8-tauola__Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1__MINIAODSIM_v77  $maxfiles
# 
# ## QCD: 2,004,219 + 3,214,312 + 1,130,720 events
# ./run/send_small_tree.sh /cms2r0/manuelf/cfa/phys14/QCD_HT_250To500_13TeV-madgraph__Phys14DR-PU20bx25_PHYS14_25_V1_ext1-v2__MINIAODSIM_v77  $maxfiles
# ./run/send_small_tree.sh /cms2r0/manuelf/cfa/phys14/QCD_HT-500To1000_13TeV-madgraph__Phys14DR-PU20bx25_PHYS14_25_V1_ext1-v1__MINIAODSIM_v77  $maxfiles
# ./run/send_small_tree.sh /cms2r0/manuelf/cfa/phys14/QCD_HT_1000ToInf_13TeV-madgraph__Phys14DR-PU20bx25_PHYS14_25_V1_ext1-v1__MINIAODSIM_v77  $maxfiles
# 
# ## Signal
# ./run/send_small_tree.sh /cms2r0/manuelf/cfa/phys14/SMS-T1tttt_2J_mGl-1500_mLSP-100_Tune4C_13TeV-madgraph-tauola__Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1__MINIAODSIM_v77  $maxfiles
# ./run/send_small_tree.sh /cms2r0/manuelf/cfa/phys14/SMS-T1tttt_2J_mGl-1500_mLSP-100_Tune4C_13TeV-madgraph-tauola__Phys14DR-PU40bx25_PHYS14_25_V1-v1__MINIAODSIM_v77  $maxfiles
# ./run/send_small_tree.sh /cms2r0/manuelf/cfa/phys14/SMS-T2tt_2J_mStop-650_mLSP-325_Tune4C_13TeV-madgraph-tauola__Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1__MINIAODSIM_v77  $maxfiles
# ./run/send_small_tree.sh /cms2r0/manuelf/cfa/phys14/SMS-T2tt_2J_mStop-850_mLSP-100_Tune4C_13TeV-madgraph-tauola__Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1__MINIAODSIM_v77  $maxfiles



./run/send_small_tree.sh /cms2r0/manuelf/cfa/phys14/SMS-T1bbbb_2J_mGl-1500_mLSP-100_Tune4C_13TeV-madgraph-tauola__Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1__MINIAODSIM_v77   $maxfiles
./run/send_small_tree.sh /cms2r0/manuelf/cfa/phys14/SMS-T1qqqq_2J_mGl-1000_mLSP-800_Tune4C_13TeV-madgraph-tauola__Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1__MINIAODSIM_v77  $maxfiles
./run/send_small_tree.sh /cms2r0/manuelf/cfa/phys14/SMS-T1qqqq_2J_mGl-1400_mLSP-100_Tune4C_13TeV-madgraph-tauola__Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1__MINIAODSIM_v77  $maxfiles
./run/send_small_tree.sh /cms2r0/manuelf/cfa/phys14/SMS-T1tttt_2J_mGl-1200_mLSP-800_Tune4C_13TeV-madgraph-tauola__Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1__MINIAODSIM_v77  $maxfiles
./run/send_small_tree.sh /cms2r0/manuelf/cfa/phys14/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola__Phys14DR-PU20bx25_PHYS14_25_V1-v1__MINIAODSIM_v77           $maxfiles

exit 0;
