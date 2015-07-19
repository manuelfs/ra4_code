#! /usr/bin python

import sys
import subprocess
import os

if len(sys.argv) < 3:
    filename = 'txt/datasamples/slep_dlep_htmht_ht_met.txt'
else:
    filename = sys.argv[2]
if len(sys.argv) < 2:
    files_job = 50
else:
    files_job = sys.argv[1]

sample_file = open(filename, 'r')


lines = sample_file.readlines()
ifile = 1

for line in lines:
    if line.find('MINIAOD') != -1:
        nfiles = len([f for f in os.listdir(line[:-1]) if f[-5:] == ".root"])
        print line[:-1]+' has '+`nfiles`+' files. Will send '+`nfiles/files_job+1`+' jobs'
        for num in range(0,nfiles/files_job+1):
            command = 'JobSubmit.csh ./run/make_tree.exe -i '+filename+' -n -1 -f '+`files_job`+' -b '+`ifile`+' -t -1 -s quick'
            print command
            #os.system(command)
            ifile += 1
