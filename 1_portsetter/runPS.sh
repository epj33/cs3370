#!/bin/bash
#run the command
DIRE="$PWD/bin"
EXEC="/portsetter"
NEWEXEC="setport"
#case ":${PATH:=$DIRE}:" in
#    *:$DIRE:*)  ;;
#    *) PATH="$DIRE:$PATH"  ;;
#esac
#echo $PATH | egrep -q "(^|:)$DIRE(:|\$)" || PATH=$PATH:$DIRE
echo $DIRE
#printf '%s' ":${PATH}:" | grep -Fq ":${DIRE}:"
#if ! printf '%s' ":${PATH-}:" | grep -Fq ":${DIRE-}:"
#then
#    PATH="${PATH-}:${DIRE-}"
#fi
if [[ -n $(find . -name "setport") ]] 
then
    echo "found it"
# use : for do nothing    
else
    echo "not found"
    $(mv $DIRE$EXEC $DIRE/$NEWEXEC)
    $(source PATH=$PATH:$DIRE)
fi

$DIRE/$NEWEXEC $1 $2 $3
echo 'return code' $?