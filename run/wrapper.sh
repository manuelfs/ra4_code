#!/bin/bash 

REV=`cat /etc/redhat-release | sed s/.*release\ // | sed s/\ .*// | cut -d '.' -f 1 ` 
DIST=`echo "slc"$REV`
echo $DIST

echo $@
if [ "$DIST" == 'slc6' ]; then 
    DIRECTORY=`pwd`
    cd CMSSW
    . cmsset_default.sh
    eval `scramv1 runtime -sh`
    cd $DIRECTORY;
fi

./run/$DIST/$@
