#!/bin/bash
#first run and test
{
    mkdir -p bin
    make
    
    EXEC="bin/portsetter"
    NEWDIR="/usr/local/bin/"
    NEWEXEC="setport"
    if [[ -n $(find $NEWDIR -name $NEWEXEC) ]] 
    then
        : 
    else
        sudo cp $EXEC $NEWDIR$NEWEXEC
    fi
    
    BUILD=$(tail -n 1 setport.build.txt)
    ((BUILD++))
    echo $BUILD >> setport.build.txt
} &> /dev/null

MYLANG=${LANG}
export LANG="es"
bin/testport $1
export LANG=$MYLANG

if [[ $? -eq 0 ]]
then
    echo "setport ready for use"
else
    echo "test(s) failed."
fi