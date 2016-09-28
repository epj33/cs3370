#setport by Eric Jorgensen

This is program 1 (with change orders applied) for cs3370 fall 2016.
This program sets the port (as of co4, just a cout) based on combinations of cmd line params and env vars.
Tests are included.
This program currently works in linux only.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Prerequisities

* A recent linux distro with g++14 or greater.
* A working knowledge of terminal commands.

### Installing

unzip the deleverable to the desired location.
go to the install location.
run the Linux Setup utility, called linuxSetup.sh

```
$ ./linuxSetup.sh
```

this will "make" the binary file, run the tests, and set up an alias for setport.
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
$ listening on port 4040
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