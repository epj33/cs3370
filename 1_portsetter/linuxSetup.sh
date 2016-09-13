#!/bin/bash
#first run and test
{
    $(mkdir -p bin)
    "$(make)" >/dev/null
    
    DIRE="$PWD/bin"
    EXEC="/portsetter"
    NEWEXEC="setport"
    if [[ -n $(find . -name "setport") ]] 
    then
        : 
    else
        $(mv $DIRE$EXEC $DIRE/$NEWEXEC)
        "$(source PATH=$PATH:$DIRE) >/dev/null"
    fi
} &> /dev/null

"$(echo bin/testport)"
echo "setport ready for use"