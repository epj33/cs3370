#!/bin/bash
#first run and test
{
    $(mkdir -p bin)
    $(make)
    
    EXEC="bin/portsetter"
    NEWDIR="/usr/local/bin/"
    NEWEXEC="setport"
    if [[ -n $(find $NEWDIR -name $NEWEXEC) ]] 
    then
        : 
    else
        $(sudo cp $EXEC $NEWDIR$NEWEXEC)
    fi
} &> /dev/null

$(echo bin/testport)
echo "setport ready for use"