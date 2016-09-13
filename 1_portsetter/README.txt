This program may be run in linux currently

To run the first time please run on the linux terminal
    ./linuxSetup.sh
    
This will run "make" for the setport command, as well as "make" for the testport command.
It will set up setport as a command, runnable anywhere.

Subsequent runs of the setport command syntax is
    setport [FLAG] [PORTNUMBER]

For example to listen on port 345:
    setport -p 345
    
Subsequent runs of the testport command syntax is
    testport [VERBOSITY]
    
For example to show verbose output:
    testport 1