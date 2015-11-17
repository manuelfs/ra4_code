#! /usr/bin/env python

### Script to send batch jobs of combinations for data PDs

import sys
import subprocess
import os
from glob import glob

if len(sys.argv) < 2:
    print "\nFormat is: ./run/data_combine.py infolder <outfolder=out> <datasets.txt>\n"
    sys.exit()
else:
    infolder = sys.argv[1]

if len(sys.argv) < 3:
    outfolder = 'out/'
else:
    outfolder  = sys.argv[2]

if len(sys.argv) < 4:
    filename = 'txt/datasamples/singlelep.txt'
else:
    filename = sys.argv[3]

sample_file = open(filename, 'r')


lines = sample_file.readlines()

# We split datasets by run ranges to be able to make the combination in parallel
# Finding unique run ranges
files = infolder+"/*"+lines[0].strip()+"*"
flist = glob(files)
runset = set()
print "Files matching "+files
for file in flist:
    runs = file.split("Run")[1]
    runs = runs.split("_")[0]
    runset.add(runs+"_")

runset = list(runset)  # Converting set to list
for run in runset:
    command = "JobSubmit.csh ./run/wrapper.sh combine_datasets.exe -i "+infolder+" -t "+run+" -f "+filename+" -o "+outfolder
    print command
    os.system(command)
