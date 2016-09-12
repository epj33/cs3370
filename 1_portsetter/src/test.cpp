/**********************************************************
cs3370 fall 2016
eric jorgensen
assn1: portsetter
use echo $? to show exit code.
**********************************************************/

#include <iostream>
#include <cstdlib>
#include <cassert>

using namespace std;
//const string EXECPORT = "./bin/setport";

int runHappyTests(int verbosity = 1){
    //cout << "hello happy tests" << endl;
    //system("export PATH=$PATH:../bin/");
    //cout << "g-bye happy tests" << endl;
    
    
    
    if (verbosity){
        //verbose tests
        if (system("./bin/setport")/256 == 0){
            cout << "happy test only binary name passed." << endl;
        }else{
            cout << "happy test only binary name failed." << endl;
        }
        if (system("./bin/setport -h")/256 == 0){
            cout << "happy test bin -h passed." << endl;
        }else{
            cout << "happy test bin -h failed." << endl;
        }
        if (system("./bin/setport --help")/256 == 0){
            cout << "happy test bin --help passed." << endl;
        }else{
            cout << "happy test bin --help failed." << endl;
        }
        
        if (system("./bin/setport -p 4040")/256 == 0){
            cout << "happy test bin -p num passed." << endl;
        }else{
            cout << "happy test bin -p num failed." << endl;
        }
        if (system("./bin/setport --port 4040")/256 == 0){
            cout << "happy test bin --port num passed." << endl;
        }else{
            cout << "happy test bin --port num failed." << endl;
        }
    }else{
        //quiet tests
        assert (system("./bin/setport > /dev/null")/256 == 0);
        assert (system("./bin/setport -h > /dev/null")/256 == 0);
        assert (system("./bin/setport --help > /dev/null")/256 == 0);
        
        assert (system("./bin/setport -p 4040 > /dev/null")/256 == 0);
        assert (system("./bin/setport --port 4040 > /dev/null")/256 == 0);
    }
    cout << "all happy tests passed" << endl;
}//end fx rHt

int runSadTests(int verbosity = 1){
    if (verbosity){
        //verbose tests
        if (system("./bin/setport help")/256 == 4){
            cout << "sad test bin help passed." << endl;
        }else{
            cout << "sad test bin help failed." << endl;
        }
        if (system("./bin/setport -help")/256 == 4){
            cout << "sad test bin -help passed." << endl;
        }else{
            cout << "sad test bin -help failed." << endl;
        }
        if (system("./bin/setport --h")/256 == 4){
            cout << "sad test bin --h passed." << endl;
        }else{
            cout << "sad test bin --h failed." << endl;
        }
        if (system("./bin/setport -h --help")/256 == 1){
            cout << "sad test bin -h --help passed." << endl;
        }else{
            cout << "sad test bin -h --help failed." << endl;
        }
        if (system("./bin/setport -hs")/256 == 4){
            cout << "sad test bin -hs passed." << endl;
        }else{
            cout << "sad test bin -hs failed." << endl;
        }
        
        if (system("./bin/setport -p --port 9")/256 == 1){
            cout << "sad test bin -p --port num passed." << endl;
        }else{
            cout << "sad test bin -p --port num failed." << endl;
        }
        if (system("./bin/setport -p 77 33")/256 == 1){
            cout << "sad test bin -p num num passed." << endl;
        }else{
            cout << "sad test bin -p num num failed." << endl;
        }
        if (system("./bin/setport -p -21")/256 == 3){
            cout << "sad test bin -p neg num passed." << endl;
        }else{
            cout << "sad test bin -p neg num failed." << endl;
        }
        if (system("./bin/setport -p 0")/256 == 3){
            cout << "sad test bin -p zero passed." << endl;
        }else{
            cout << "sad test bin -p zero failed." << endl;
        }
        if (system("./bin/setport --port")/256 == 2){
            cout << "sad test bin --port no num passed." << endl;
        }else{
            cout << "sad test bin --port no num failed." << endl;
        }
        if (system("./bin/setport -p 90642")/256 == 3){
            cout << "sad test bin -p high num passed." << endl;
        }else{
            cout << "sad test bin -p high num failed." << endl;
        }
        
        if (system("./bin/setport -x")/256 == 4){
            cout << "sad test bin -x passed." << endl;
        }else{
            cout << "sad test bin -x failed." << endl;
        }
        if (system("./bin/setport -P")/256 == 4){
            cout << "sad test bin -P passed." << endl;
        }else{
            cout << "sad test bin -P failed." << endl;
        }
    }else{
        //quiet tests
        assert (system("./bin/setport help > /dev/null")/256 == 4);
        assert (system("./bin/setport -help > /dev/null")/256 == 4);
        assert (system("./bin/setport --h > /dev/null")/256 == 4);
        assert (system("./bin/setport -h --help > /dev/null")/256 == 1);
        assert (system("./bin/setport -hs > /dev/null")/256 == 4);
        
        assert (system("./bin/setport -p --port 9 > /dev/null")/256 == 1);
        assert (system("./bin/setport -p 77 33 > /dev/null")/256 == 1);
        assert (system("./bin/setport -p -21 > /dev/null")/256 == 3);
        assert (system("./bin/setport -p 0 > /dev/null")/256 == 3);
        assert (system("./bin/setport --port > /dev/null")/256 == 2);
        assert (system("./bin/setport -p 90642 > /dev/null")/256 == 3);
        
        assert (system("./bin/setport -x > /dev/null")/256 == 4);
        assert (system("./bin/setport -P > /dev/null")/256 == 4);
    }
    cout << "all sad tests passed" << endl;
}//end fx rSt

/**********************************************************
 * input params:    -h, --help
 *                  -p <portNumber>, --port <portNumber>
 * 
 * output expected: "listening on port <portFromCmdLine>"
 * 
**********************************************************/
int main(int argc, char *args[]) {
    int verboseFlag = 0;
    if (argc > 1){
        verboseFlag = atoi(args[1]);
    }
    //cout << "hello test" << endl;
    //return system("./bin/setport -p > /dev/null")/256;
    //cout << "returnCodeFromSetPort: " << returnCodeFromSetPort << endl;
    //return returnCodeFromSetPort;
    runHappyTests(verboseFlag);
    runSadTests(verboseFlag);
    return 0;
}//end fx main
