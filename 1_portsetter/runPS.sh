#!/bin/bash
#run the command
DIRE="$PWD/bin"
EXEC="/portsetter"
NEWEXEC="setport"
echo $DIRE
if [[ -n $(find . -name "setport") ]] 
then
    : 
else
    echo "not found"
    $(mv $DIRE$EXEC $DIRE/$NEWEXEC)
    $(source PATH=$PATH:$DIRE)
fi

$NEWEXEC $1 $2 $3
echo 'return code' $?