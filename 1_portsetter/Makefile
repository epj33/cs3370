all: portsetter testport

portsetter: src/portsetter.cpp
	g++-5 --std=c++14 src/portsetter.cpp -o bin/portsetter
	
testport: src/test.cpp
	g++-5 --std=c++14 src/test.cpp -o bin/testport
	
clean:
	rm -rf bin
	sudo rm /usr/local/bin/setport 