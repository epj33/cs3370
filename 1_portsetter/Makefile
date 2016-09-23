all: portsetter testport

portsetter: src/portsetter.cpp
#	g++ portsetter.cpp -o bin/portsetter
	g++-5 --std=c++14 src/portsetter.cpp -o bin/portsetter
	
testport: src/test.cpp
#	g++ test.cpp -o bin/testport
	g++-5 --std=c++14 src/test.cpp -o bin/testport
	
clean:
	rm -rf bin
	sudo rm /usr/local/bin/setport 