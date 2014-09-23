#!/bin/bash

if (( "$#" < 2 ))
then
    echo "Format is: ./run/send_small_tree.sh <dataset> <maxfiles>"
fi

dataset=$1
maxfiles=$2

nfiles=`ls $dataset/*root | wc -l`

if (( $nfiles <= $maxfiles )) 
then 
    JobSubmit.csh ./run/make_tree.exe -i $dataset -n -1 
else
    nfiles=$(($nfiles + $maxfiles - 1))
    njobs=$(($nfiles / $maxfiles))
    for file in `seq 1 $njobs`;
    do
         JobSubmit.csh ./run/make_tree.exe -i $dataset -n -1 -f $maxfiles -b $file
    done      
fi 
