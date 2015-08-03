#! /usr/bin python

### Script to send batch jobs of combinations for data PDs

import sys
import subprocess
import os

if len(sys.argv) < 2:
    files_job = 10
else:
    files_job = int(sys.argv[1])

basefile = "HTMHT_SingleElectron_SingleMuon_DoubleEG_DoubleMuon_MET_JetHT"
if len(sys.argv) < 3:
    filename = 'txt/datasamples/slep_dlep_htmht_ht_met.txt'
    #filename = 'txt/datasamples/smu_dmu_htmht_met.txt'
    #filename = 'txt/datasamples/dlep_htmht_met.txt'
    #filename = 'txt/datasamples/htmht_met.txt'
else:
    filename = sys.argv[2]

sample_file = open(filename, 'r')


lines = sample_file.readlines()
ifile = 1

for line in lines:
    if line.find('MINIAOD') != -1:
        nfiles = len([f for f in os.listdir(line[:-1]) if f[-5:] == ".root"])
        print line[:-1]+' has '+`nfiles`+' files. Will send '+`nfiles/files_job+1`+' jobs'
        for num in range(0,nfiles/files_job+1):
            outfile = "out/small_quick_Run2015B__"+basefile+"_files"+`files_job`+"_batch"+`ifile`+".root"
            command = 'JobSubmit.csh ./run/wrapper.sh make_tree.exe -i '+filename+' -n -1 -f '+`files_job`+' -b '+`ifile`+' -t -1 -s quick'
            #print command
            if(not os.path.isfile(outfile)): os.system(command)
            ifile += 1
