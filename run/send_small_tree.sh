#!/bin/bash

if (( "$#" < 2 ))
then
    echo "Format is: ./run/send_small_tree.sh <dataset> <maxfiles>"
fi

dataset=$1
maxfiles=$2
totentries=-1
if (( "$#" > 2 ))
then
    totentries=$3
fi

nfiles=`ls $dataset/*root | wc -l`
samplename=`basename $dataset`

if (( $nfiles <= $maxfiles )) 
then 
    outfile="out/small_${samplename}.root"
    if [ ! -f $outfile ]; then
	JobSubmit.csh ./run/make_tree.exe -i $dataset -n -1
    else
	echo File $outfile exists. Not sending job
    fi
else
    nfiles=$(($nfiles + $maxfiles - 1))
    njobs=$(($nfiles / $maxfiles))
    for file in `seq 1 $njobs`;
    do
	outfile="out/small_${samplename}_files${maxfiles}_batch${file}.root"
	if [ ! -f $outfile ]; then
	    JobSubmit.csh ./run/make_tree.exe -i $dataset -n -1 -f $maxfiles -b $file -t $totentries
	else
	    echo File $outfile exists. Not sending job
	fi
    done      
fi 
