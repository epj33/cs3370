all: portsetter testport

portsetter: portsetter.cpp
#	g++ portsetter.cpp -o bin/portsetter
	g++ --std=c++11 portsetter.cpp -o bin/portsetter
	
testport: test.cpp
#	g++ test.cpp -o bin/testport
	g++ --std=c++11 test.cpp -o bin/testport
	
clean:
	rm -rf bin
	sudo rm /usr/local/bin/setport 