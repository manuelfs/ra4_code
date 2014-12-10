#! /bin/bash

maxfiles=5
if (( "$#" >= 1 ))
then
    maxfiles=$1
fi

./run/send_small_tree.sh /cms2r0/manuelf/cfa/phys14/TT_Tune4C_13TeV-pythia8-tauola__Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1__MINIAODSIM_v77  $maxfiles
./run/send_small_tree.sh /cms2r0/manuelf/cfa/phys14/SMS-T1tttt_2J_mGl-1500_mLSP-100_Tune4C_13TeV-madgraph-tauola__Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1__MINIAODSIM_v77  $maxfiles
./run/send_small_tree.sh /cms2r0/manuelf/cfa/phys14/SMS-T2tt_2J_mStop-650_mLSP-325_Tune4C_13TeV-madgraph-tauola__Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1__MINIAODSIM_v77  $maxfiles
./run/send_small_tree.sh /cms2r0/manuelf/cfa/phys14/SMS-T2tt_2J_mStop-850_mLSP-100_Tune4C_13TeV-madgraph-tauola__Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1__MINIAODSIM_v77  $maxfiles


exit 0;
