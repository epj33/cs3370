# setport by Eric Jorgensen  
jorgensen.eric@gmail.com

This is program 1 (with change orders applied) for cs3370 fall 2016.  
To get to my cloud9 page, please go to [cloud9-epj33-cs3370].  
This program sets the port (as of co4, just a cout) based on combinations of cmd line params and env vars.  
Tests are included.  
This program currently works in **linux only**.

## Getting Started

These instructions will get you a copy of the project up and running.

### Prerequisites

* A recent linux distro with g++14 or greater.
* A working knowledge of terminal commands.

### Installing

Unzip the deliverable to the desired location.  
Go to the install location.  
Check/set the permissions on the Linux Setup utility, called linuxSetup.sh  
```
$ ls -l linuxSetup.sh
-rw-r--r-- 1 ubuntu ubuntu 538 Oct 11 22:42 linuxSetup.sh
```

if needed, add execute permissions to linuxSetup.sh  
```
$ chmod +x linuxSetup.sh                                                                      
$ ls -l linuxSetup.sh 
-rwxr-xr-x 1 ubuntu ubuntu 538 Oct 11 22:42 linuxSetup.sh*
```

Then run linuxSetup.sh

```
$ ./linuxSetup.sh
```

This will "make" the binary file, run the tests, and set up an alias for setport.  
Output from running the above command will look like:

```
all happy tests passed
all sad tests passed
setport ready for use
$
```

setport is now ready for use:
```
$ setport -p 4040
listening on port 4040
$
```

## Environment variables

#####This program (setport) will check for the language to use in the env vars:  

* LANGUAGE
* LC_ALL
* LC_MESSAGES
* LANG

If no valid language and matching message file is found, language will default to english.  
Please check i18n/ for abouts/ messages/ and usages/ for needed language files.

If run with the -e flag, setport will check the given env var for a valid port number.  
PORT will be checked if no env var is given.
```
$ setport -p -e
listening on port 8080
$
```

## Running the tests

The tests can be run in verbose or non-verbose mode.  
To specify verbose add 1 to the end of the Linux Setup Utility command:

```
$ ./linuxSetup.sh 1
```
This will print out the individual test results.  
For a more silent version of the tests, add a 0 (or leave the flag blank):
```
$ ./linuxSetup.sh 0
```
or
```
$ ./linuxSetup.sh
```

## Contributing

Only the author has permission to add to this project, while others may view it.


## Author

* **Eric Jorgensen** - to learn more about Eric, please run:
```
$ setport -!
```

## Acknowledgments

* Jerry Woolf, creator of the whiteboard marker.
* Eric Michelman, creator of the middle-mouse button scroll wheel.
* UBC Pharmaceutical Company, creator of Zyrtec.

[cloud9-epj33-cs3370]: https://ide.c9.io/epj33/cs3370