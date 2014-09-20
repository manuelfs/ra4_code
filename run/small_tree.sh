#! /bin/csh

set Nevents=5000000
if ( "$#" >= 1 ) then
    set Nevents=$1
endif

# T1tttt @ 13 TeV
bsub ./run/make_tree.exe -i /cms2r0/cfA/SMS-T1tttt_2J_mGl-1200_mLSP-800_Tune4C_13TeV-madgraph-tauola-Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2085_v73 -n $Nevents  | tee log/maketree_13TeV_T1tttt_1200.log
bsub ./run/make_tree.exe -i /cms2r0/cfA/SMS-T1tttt_2J_mGl-1500_mLSP-100_Tune4C_13TeV-madgraph-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2120_v73  -n $Nevents  | tee log/maketree_13TeV_T1tttt_1500.log

# tt @ 13 TeV
bsub ./run/make_tree.exe -i /cms2r0/cfA/TTJets_MSDecaysCKM_central_Tune4C_13TeV-madgraph-tauola-Spring14miniaod-PU20bx25_POSTLS170_V5-v2_MINIAODSIM_UCSB2087_v73 -n $Nevents  | tee log/maketree_13TeV_tt.log

# QCD @13TeV
bsub ./run/make_tree.exe -i /cms2r0/cfA/QCD_Pt-3200_Tune4C_13TeV_pythia8_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2136_v73               -n $Nevents  | tee log/maketree_13TeV_QCT_Pt-3200_Tune4.log
bsub ./run/make_tree.exe -i /cms2r0/cfA/QCD_Pt-2400to3200_Tune4C_13TeV_pythia8_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2099_v73         -n $Nevents  | tee log/maketree_13TeV_QCT_Pt-2400to3200.log
bsub ./run/make_tree.exe -i /cms2r0/cfA/QCD_Pt-1800to2400_Tune4C_13TeV_pythia8_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2100_v73         -n $Nevents  | tee log/maketree_13TeV_QCT_Pt-1800to2400.log
bsub ./run/make_tree.exe -i /cms2r0/cfA/QCD_Pt-1400to1800_Tune4C_13TeV_pythia8_Spring14miniaod-castor_PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2101_v73  -n $Nevents  | tee log/maketree_13TeV_QCT_Pt-1400to1800.log
bsub ./run/make_tree.exe -i /cms2r0/cfA/QCD_Pt-1000to1400_Tune4C_13TeV_pythia8_Spring14miniaod-castor_PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2118_v73  -n $Nevents  | tee log/maketree_13TeV_QCT_Pt-1000to1400.log
bsub ./run/make_tree.exe -i /cms2r0/cfA/QCD_Pt-800to1000_Tune4C_13TeV_pythia8_Spring14miniaod-castor_PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2130_v73   -n $Nevents  | tee log/maketree_13TeV_QCT_Pt-800to1000_.log
bsub ./run/make_tree.exe -i /cms2r0/cfA/QCD_Pt-600to800_Tune4C_13TeV_pythia8_Spring14miniaod-castor_PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2138_v73    -n $Nevents  | tee log/maketree_13TeV_QCT_Pt-600to800_T.log
bsub ./run/make_tree.exe -i /cms2r0/cfA/QCD_Pt-470to600_Tune4C_13TeV_pythia8_Spring14miniaod-castor_PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2137_v73    -n $Nevents  | tee log/maketree_13TeV_QCT_Pt-470to600_T.log
bsub ./run/make_tree.exe -i /cms2r0/cfA/QCD_Pt-300to470_Tune4C_13TeV_pythia8_Spring14miniaod-castor_PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2135_v73    -n $Nevents  | tee log/maketree_13TeV_QCT_Pt-300to470_T.log
bsub ./run/make_tree.exe -i /cms2r0/cfA/QCD_Pt-170to300_Tune4C_13TeV_pythia8_Spring14miniaod-castor_PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2098_v73    -n $Nevents  | tee log/maketree_13TeV_QCT_Pt-170to300_T.log
bsub ./run/make_tree.exe -i /cms2r0/cfA/QCD_Pt-120to170_Tune4C_13TeV_pythia8_Spring14miniaod-castor_PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2109_v73    -n $Nevents  | tee log/maketree_13TeV_QCT_Pt-120to170_T.log
bsub ./run/make_tree.exe -i /cms2r0/cfA/QCD_Pt-80to120_Tune4C_13TeV_pythia8_Spring14miniaod-castor_PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2128_v73     -n $Nevents  | tee log/maketree_13TeV_QCT_Pt-80to120_Tu.log
bsub ./run/make_tree.exe -i /cms2r0/cfA/QCD_Pt-50to80_Tune4C_13TeV_pythia8_Spring14miniaod-castor_PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2127_v73      -n $Nevents  | tee log/maketree_13TeV_QCT_Pt-50to80_Tun.log
bsub ./run/make_tree.exe -i /cms2r0/cfA/QCD_Pt-30to50_Tune4C_13TeV_pythia8_Spring14miniaod-castor_PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2126_v73      -n $Nevents  | tee log/maketree_13TeV_QCT_Pt-30to50_Tun.log
bsub ./run/make_tree.exe -i /cms2r0/cfA/QCD_Pt-15to30_Tune4C_13TeV_pythia8_Spring14miniaod-castor_PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2104_v73      -n $Nevents  | tee log/maketree_13TeV_QCT_Pt-15to30_Tun.log
bsub ./run/make_tree.exe -i /cms2r0/cfA/QCD_Pt-10to15_Tune4C_13TeV_pythia8_Spring14miniaod-castor_PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2103_v73      -n $Nevents  | tee log/maketree_13TeV_QCT_Pt-10to15_Tun.log
bsub ./run/make_tree.exe -i /cms2r0/cfA/QCD_Pt-5to10_Tune4C_13TeV_pythia8_Spring14miniaod-castor_PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2125_v73       -n $Nevents  | tee log/maketree_13TeV_QCT_Pt-5to10_Tune.log   

# W + jets @ 13 TeV
bsub ./run/make_tree.exe -i /cms2r0/cfA/WJetsToLNu_HT-100to200_Tune4C_13TeV-madgraph-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v2_MINIAODSIM_UCSB2097_v73 -n $Nevents  | tee log/maketree_13TeV_WJetsToLNu_HT-100to200.log
bsub ./run/make_tree.exe -i /cms2r0/cfA/WJetsToLNu_HT-200to400_Tune4C_13TeV-madgraph-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2096_v73 -n $Nevents  | tee log/maketree_13TeV_WJetsToLNu_HT-200to400.log
bsub ./run/make_tree.exe -i /cms2r0/cfA/WJetsToLNu_HT-400to600_Tune4C_13TeV-madgraph-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2121_v73 -n $Nevents  | tee log/maketree_13TeV_WJetsToLNu_HT-400to600.log
bsub ./run/make_tree.exe -i /cms2r0/cfA/WJetsToLNu_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Spring14miniaod-PU20bx25_POSTLS170_V5-v1_MINIAODSIM_UCSB2122_v73 -n $Nevents  | tee log/maketree_13TeV_WJetsToLNu_HT-600toinf.log   




exit 0;
