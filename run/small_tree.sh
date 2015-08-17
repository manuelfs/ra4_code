#! /bin/bash

type=quick
maxfiles=20
if (( "$#" >= 1 ))
then
    maxfiles=$1
fi

./run/send_small_tree.sh /net/cms2/cms2r0/cfA/HTMHT_Run2015B-17Jul2015-v1_MINIAOD_UCSB2687_v83		    $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/HTMHT_Run2015B-PromptReco-v1_MINIAOD_UCSB2688_v83		    $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/MET_Run2015B-17Jul2015-v1_MINIAOD_UCSB2692_v83		    $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/MET_Run2015B-PromptReco-v1_MINIAOD_UCSB2699_v83		    $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/SingleElectron_Run2015B-17Jul2015-v1_MINIAOD_UCSB2694_v83	    $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/SingleElectron_Run2015B-PromptReco-v1_MINIAOD_UCSB2696_v83    $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/SingleMuon_Run2015B-17Jul2015-v1_MINIAOD_UCSB2695_v83	    $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/SingleMuon_Run2015B-PromptReco-v1_MINIAOD_UCSB2697_v83        $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/JetHT_Run2015B-17Jul2015-v1_MINIAOD_UCSB2700_v83		    $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/JetHT_Run2015B-PromptReco-v1_MINIAOD_UCSB2693_v83		    $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/DoubleEG_Run2015B-17Jul2015-v1_MINIAOD_UCSB2701_v83           $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/DoubleEG_Run2015B-PromptReco-v1_MINIAOD_UCSB2702_v83	    $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/DoubleMuon_Run2015B-17Jul2015-v1_MINIAOD_UCSB2690_v83	    $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/DoubleMuon_Run2015B-PromptReco-v1_MINIAOD_UCSB2691_v83	    $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/MuonEG_Run2015B-17Jul2015-v1_MINIAOD_UCSB2689_v83		    $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/MuonEG_Run2015B-PromptReco-v1_MINIAOD_UCSB2698_v83	    $type $maxfiles

exit 0;


## Data
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/HTMHT_Run2015B-17Jul2015-v1_MINIAOD_UCSB2615_v82          $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/HTMHT_Run2015B-PromptReco-v1_MINIAOD_UCSB2616_v82		$type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/MET_Run2015B-17Jul2015-v1_MINIAOD_UCSB2619_v82            $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/MET_Run2015B-PromptReco-v1_MINIAOD_UCSB2621_v82	        $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/JetHT_Run2015B-17Jul2015-v1_MINIAOD_UCSB2644_v82	        $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/JetHT_Run2015B-PromptReco-v1_MINIAOD_UCSB2642_v82	        $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/DoubleEG_Run2015B-17Jul2015-v1_MINIAOD_UCSB2630_v82       $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/DoubleEG_Run2015B-PromptReco-v1_MINIAOD_UCSB2629_v82      $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/DoubleMuon_Run2015B-17Jul2015-v1_MINIAOD_UCSB2624_v82     $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/DoubleMuon_Run2015B-PromptReco-v1_MINIAOD_UCSB2625_v82    $type $maxfiles
## ttbar
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/TTJets_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v1_MINIAODSIM_UCSB2650_v82			      $type $maxfiles
## WJets
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/WJetsToLNu_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1_MINIAODSIM_UCSB2631_v82             $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/WJetsToLNu_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1_MINIAODSIM_UCSB2628_v82	     $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v3_MINIAODSIM_UCSB2617_v82	     $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/WJetsToLNu_HT-600ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1_MINIAODSIM_UCSB2627_v82	     $type $maxfiles
## QCD
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1_MINIAODSIM_UCSB2599_v82			      $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/QCD_Pt_470to600_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v2_MINIAODSIM_UCSB2620_v82			      $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/QCD_Pt_600to800_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v3_MINIAODSIM_UCSB2652_v82			      $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/QCD_Pt_800to1000_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v2_MINIAODSIM_UCSB2609_v82                        $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/QCD_Pt_1000to1400_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1_MINIAODSIM_UCSB2610_v82			      $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/QCD_Pt_1400to1800_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1_MINIAODSIM_UCSB2603_v82			      $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/QCD_Pt_1800to2400_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1_MINIAODSIM_UCSB2600_v82			      $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/QCD_Pt_2400to3200_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1_MINIAODSIM_UCSB2601_v82			      $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/QCD_Pt_3200toInf_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1_MINIAODSIM_UCSB2602_v82			      $type $maxfiles
## Single top
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/ST_s-channel_4f_leptonDecays_13TeV-amcatnlo-pythia8_TuneCUETP8M1_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1_MINIAODSIM_UCSB2634_v82           $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/ST_t-channel_antitop_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v1_MINIAODSIM_UCSB2648_v82    $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/ST_t-channel_top_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v1_MINIAODSIM_UCSB2647_v82	      $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v2_MINIAODSIM_UCSB2646_v82	      $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v1_MINIAODSIM_UCSB2645_v82	      $type $maxfiles
## Drell-Yan
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/DYJetsToLL_M-50_HT-200to400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v2_MINIAODSIM_UCSB2607_v82	     $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/DYJetsToLL_M-50_HT-400to600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v2_MINIAODSIM_UCSB2606_v82	     $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/DYJetsToLL_M-50_HT-600toInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v2_MINIAODSIM_UCSB2604_v82	     $type $maxfiles
## Other
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/ttHJetTobb_M125_13TeV_amcatnloFXFX_madspin_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9_ext1-v1_MINIAODSIM_UCSB2649_v82                   $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/WWTo2L2Nu_13TeV-powheg_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1_MINIAODSIM_UCSB2638_v82						      $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/WWToLNuQQ_13TeV-powheg_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1_MINIAODSIM_UCSB2639_v82						      $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/ggZH_HToBB_ZToNuNu_M125_13TeV_powheg_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1_MINIAODSIM_UCSB2636_v82                               $type $maxfiles 



exit 0;

# 25ns v82
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/TTJets_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v2_MINIAODSIM_UCSB2598_v82		      $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/ST_t-channel_antitop_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1_MINIAODSIM_UCSB2626_v82     $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/ST_t-channel_top_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1_MINIAODSIM_UCSB2640_v82	      $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1_MINIAODSIM_UCSB2641_v82	      $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1_MINIAODSIM_UCSB2643_v82	      $type $maxfiles
exit 0;


######### v80 cfA

#Data
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/DoubleEG_Run2015B-PromptReco-v1_MINIAOD_UCSB2472_v80  $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/DoubleMuon_Run2015B-PromptReco-v1_MINIAOD_UCSB2467_v80  $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/HTMHT_Run2015B-PromptReco-v1_MINIAOD_UCSB2468_v80  $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/JetHT_Run2015B-PromptReco-v1_MINIAOD_UCSB2473_v80  $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/MET_Run2015B-PromptReco-v1_MINIAOD_UCSB2469_v80  $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/SingleElectron_Run2015B-PromptReco-v1_MINIAOD_UCSB2470_v80  $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/SingleMuon_Run2015B-PromptReco-v1_MINIAOD_UCSB2466_v80  $type $maxfiles
#./run/send_small_tree.sh /net/cms2/cms2r0/cfA/SinglePhoton_Run2015B-PromptReco-v1_MINIAOD_UCSB2471_v80  $type $maxfiles

### Drell-Yan
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v2_MINIAODSIM_UCSB2520_v80       $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/DYJetsToLL_M-10to50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v1_MINIAODSIM_UCSB2519_v80   $type $maxfiles


### QCD_HT
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/QCD_HT1000to1500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v2_MINIAODSIM_UCSB2530_v80  $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/QCD_HT1500to2000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1_MINIAODSIM_UCSB2529_v80  $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/QCD_HT2000toInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1_MINIAODSIM_UCSB2528_v80   $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/QCD_HT200to300_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v2_MINIAODSIM_UCSB2534_v80    $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/QCD_HT300to500_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v2_MINIAODSIM_UCSB2532_v80    $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/QCD_HT500to700_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1_MINIAODSIM_UCSB2533_v80    $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/QCD_HT700to1000_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1_MINIAODSIM_UCSB2531_v80   $type $maxfiles

## QCD
#./run/send_small_tree.sh /net/cms2/cms2r0/cfA/QCD_Pt_1000to1400_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1_MINIAODSIM_UCSB2502_v80  $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/QCD_Pt_1000to1400_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v2_MINIAODSIM_UCSB2490_v80  $type $maxfiles
#./run/send_small_tree.sh /net/cms2/cms2r0/cfA/QCD_Pt_120to170_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1_MINIAODSIM_UCSB2500_v80  $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/QCD_Pt_120to170_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v1_MINIAODSIM_UCSB2479_v80  $type $maxfiles
#./run/send_small_tree.sh /net/cms2/cms2r0/cfA/QCD_Pt_1400to1800_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1_MINIAODSIM_UCSB2503_v80  $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/QCD_Pt_1400to1800_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v1_MINIAODSIM_UCSB2504_v80  $type $maxfiles
#./run/send_small_tree.sh /net/cms2/cms2r0/cfA/QCD_Pt_170to300_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v2_MINIAODSIM_UCSB2492_v80  $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/QCD_Pt_170to300_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v2_MINIAODSIM_UCSB2478_v80  $type $maxfiles
#./run/send_small_tree.sh /net/cms2/cms2r0/cfA/QCD_Pt_1800to2400_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1_MINIAODSIM_UCSB2505_v80  $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/QCD_Pt_1800to2400_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v1_MINIAODSIM_UCSB2506_v80  $type $maxfiles
#./run/send_small_tree.sh /net/cms2/cms2r0/cfA/QCD_Pt_2400to3200_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1_MINIAODSIM_UCSB2508_v80  $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/QCD_Pt_2400to3200_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v1_MINIAODSIM_UCSB2480_v80  $type $maxfiles
#./run/send_small_tree.sh /net/cms2/cms2r0/cfA/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1_MINIAODSIM_UCSB2515_v80  $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v1_MINIAODSIM_UCSB2494_v80  $type $maxfiles
#./run/send_small_tree.sh /net/cms2/cms2r0/cfA/QCD_Pt_3200toInf_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1_MINIAODSIM_UCSB2509_v80  $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/QCD_Pt_3200toInf_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v1_MINIAODSIM_UCSB2481_v80  $type $maxfiles
#./run/send_small_tree.sh /net/cms2/cms2r0/cfA/QCD_Pt_470to600_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v2_MINIAODSIM_UCSB2514_v80  $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/QCD_Pt_470to600_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v2_MINIAODSIM_UCSB2493_v80  $type $maxfiles
#./run/send_small_tree.sh /net/cms2/cms2r0/cfA/QCD_Pt_600to800_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25nsRecodebug_MCRUN2_74_V9-v1_MINIAODSIM_UCSB2501_v80  $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/QCD_Pt_600to800_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v2_MINIAODSIM_UCSB2511_v80  $type $maxfiles
#./run/send_small_tree.sh /net/cms2/cms2r0/cfA/QCD_Pt_800to1000_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v2_MINIAODSIM_UCSB2513_v80  $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/QCD_Pt_800to1000_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v2_MINIAODSIM_UCSB2491_v80  $type $maxfiles
#./run/send_small_tree.sh /net/cms2/cms2r0/cfA/QCD_Pt_80to120_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1_MINIAODSIM_UCSB2487_v80  $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/QCD_Pt_80to120_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v1_MINIAODSIM_UCSB2485_v80  $type $maxfiles

## ttbar
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/TTJets_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v2_MINIAODSIM_UCSB2461_v80  $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/TTJets_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A-v1_MINIAODSIM_UCSB2510_v80  $type $maxfiles

## WJets
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/WJetsToLNu_HT-100To200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1_MINIAODSIM_UCSB2465_v80  $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/WJetsToLNu_HT-200To400_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1_MINIAODSIM_UCSB2464_v80  $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/WJetsToLNu_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v3_MINIAODSIM_UCSB2463_v80  $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/WJetsToLNu_HT-600ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1_MINIAODSIM_UCSB2460_v80  $type $maxfiles

## ZJets
#./run/send_small_tree.sh /net/cms2/cms2r0/cfA/ZJetsToNuNu_HT-400To600_13TeV-madgraph_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1_MINIAODSIM_UCSB2516_v80  $type $maxfiles
  ## v78
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/ZJetsToNuNu_HT-100to200_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2408_v78    $type   $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/ZJetsToNuNu_HT-200to400_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2381_v78    $type   $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/ZJetsToNuNu_HT-400to600_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v2_MINIAODSIM_UCSB2380_v78    $type   $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/ZJetsToNuNu_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2379_v78    $type   $maxfiles
  ##

## Diboson
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/WWTo2L2Nu_13TeV-powheg_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1_MINIAODSIM_UCSB2495_v80  $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/WWToLNuQQ_13TeV-powheg_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1_MINIAODSIM_UCSB2496_v80  $type $maxfiles

## Drell-Yan
  ## v78
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/DYJetsToLL_M-50_HT-100to200_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2413_v78        $type   $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/DYJetsToLL_M-50_HT-200to400_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2417_v78        $type   $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/DYJetsToLL_M-50_HT-400to600_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2418_v78        $type   $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/DYJetsToLL_M-50_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2419_v78        $type   $maxfiles
  ##

## Single top
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/ST_s-channel_4f_leptonDecays_13TeV-amcatnlo-pythia8_TuneCUETP8M1_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1_MINIAODSIM_UCSB2476_v80  $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/ST_t-channel_antitop_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1_MINIAODSIM_UCSB2459_v80  $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/ST_t-channel_top_4f_leptonDecays_13TeV-powheg-pythia8_TuneCUETP8M1_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1_MINIAODSIM_UCSB2462_v80  $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/ST_tW_antitop_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1_MINIAODSIM_UCSB2475_v80  $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/ST_tW_top_5f_inclusiveDecays_13TeV-powheg-pythia8_TuneCUETP8M1_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1_MINIAODSIM_UCSB2477_v80  $type $maxfiles

## TTV, VH
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/ttHJetTobb_M125_13TeV_amcatnloFXFX_madspin_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9_ext1-v1_MINIAODSIM_UCSB2499_v80  $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/ttHJetTobb_M125_13TeV_amcatnloFXFX_madspin_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1_MINIAODSIM_UCSB2498_v80  $type $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/ggZH_HToBB_ZToNuNu_M125_13TeV_powheg_pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1_MINIAODSIM_UCSB2497_v80  $type $maxfiles
  ## v78
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/TTWJets_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2390_v78    $type   $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/TTZJets_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2384_v78    $type   $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/WH_HToBB_WToLNu_M-125_13TeV_powheg-herwigpp_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1_MINIAODSIM_UCSB2382_v78 $type   $maxfiles
  ##

## Signal
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/SMS-T1bbbb_2J_mGl-1000_mLSP-900_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1_MINIAODSIM_UCSB2365_v78	$type	$maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/SMS-T1bbbb_2J_mGl-1500_mLSP-100_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1_MINIAODSIM_UCSB2364_v78	$type	$maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/SMS-T1qqqq_2J_mGl-1000_mLSP-800_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1_MINIAODSIM_UCSB2367_v78	$type	$maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/SMS-T1qqqq_2J_mGl-1400_mLSP-100_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1_MINIAODSIM_UCSB2366_v78	$type	$maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/SMS-T1tttt_2J_mGl-1200_mLSP-800_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1_MINIAODSIM_UCSB2363_v78	$type	$maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/SMS-T1tttt_2J_mGl-1500_mLSP-100_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_tsg_PHYS14_25_V1-v1_MINIAODSIM_UCSB2377_v78	$type	$maxfiles


## GJets
#./run/send_small_tree.sh /net/cms2/cms2r0/cfA/GJets_HT-400To600_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1_MINIAODSIM_UCSB2483_v80  $type $maxfiles
#./run/send_small_tree.sh /net/cms2/cms2r0/cfA/GJets_HT-600ToInf_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1_MINIAODSIM_UCSB2482_v80  $type $maxfiles
 ## v78
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/GJets_HT-100to200_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2360_v78  $type   $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/GJets_HT-200to400_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2359_v78  $type   $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/GJets_HT-400to600_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2358_v78  $type   $maxfiles
./run/send_small_tree.sh /net/cms2/cms2r0/cfA/GJets_HT-600toInf_Tune4C_13TeV-madgraph-tauola_Phys14DR-PU20bx25_PHYS14_25_V1-v1_MINIAODSIM_UCSB2357_v78  $type   $maxfiles
  ##

exit 0;
