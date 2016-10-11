email to jorgensen.eric@gmail.com for questions/comments.

This program may be run in linux currently

To run the first time please run on the linux terminal
    ./linuxSetup.sh
    
This will run "make" for the setport command, as well as "make" for the testport command.
It will set up setport as a command, runnable anywhere.
It will also run all the tests in non-verbose mode.

This program (setport) will check for the language to use in the env vars:
    LANGUAGE, LC_ALL, LC_MESSAGES, LANG
If no valid language and matching message file is found, language will default to english.
Please check i18n/ for abouts/ messages/ and usages/ for needed language files.

Subsequent runs of the setport command syntax is
    setport [FLAG] [PORTNUMBER]

For example to listen on port 345:
    setport -p 345
    
Subsequent runs of the testport command syntax is
    bin/testport [VERBOSITY]
    
For example to show verbose output:
    bin/testport 1