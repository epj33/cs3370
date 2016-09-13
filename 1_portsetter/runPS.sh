#!/bin/bash
#run the command
DIRE="$PWD/bin"
EXEC="/portsetter"
NEWEXEC="setport"
echo $DIRE
if [[ -n $(find . -name "setport") ]] 
then
    echo "found it"
# use : for do nothing    
else
    echo "not found"
    $(mv $DIRE$EXEC $DIRE/$NEWEXEC)
    $(echo PATH=$PATH:$DIRE >> ~/.bashrc)
    $(source ~/.bashrc)
fi

$DIRE/$NEWEXEC $1 $2 $3
echo 'return code' $?