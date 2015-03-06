#!/bin/bash

if (( "$#" < 3 ))
then
    echo "Format is: ./run/send_small_tree.sh <dataset> <type> <maxfiles>"
fi

dataset=$1
type=$2
maxfiles=$3
totentries=-1
if (( "$#" > 3 ))
then
    totentries=$4
fi

nfiles=`ls $dataset/*root | wc -l`
samplename=`basename $dataset`

if (( $nfiles <= $maxfiles )) 
then 
    outfile="out/small_${type}_${samplename}.root"
    if [ ! -f $outfile ]; then
	JobSubmit.csh ./run/make_tree.exe -i $dataset -n -1 -s $type
    else
	echo File $outfile exists. Not sending job
    fi
else
    nfiles=$(($nfiles + $maxfiles - 1))
    njobs=$(($nfiles / $maxfiles))
    for file in `seq 1 $njobs`;
    do
	outfile="out/small_${type}_${samplename}_files${maxfiles}_batch${file}.root"
	if [ ! -f $outfile ]; then
	    JobSubmit.csh ./run/make_tree.exe -i $dataset -n -1 -f $maxfiles -b $file -t $totentries -s $type
	else
	    echo File $outfile exists. Not sending job
	fi
    done      
fi 
