all: portsetter testport

portsetter: portsetter.cpp
	g++ portsetter.cpp -o bin/portsetter
	
testport: test.cpp
	g++ test.cpp -o bin/testport
	
clean:
	rm -rf bin
	sudo rm /usr/local/bin/setport 