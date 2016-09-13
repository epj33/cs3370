/**********************************************************
cs3370 fall 2016
eric jorgensen
assn1: portsetter
use echo $? to show exit code.
**********************************************************/

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

enum ReturnCodes {SUCCESS, ERR_TOO_MANY, ERR_NO_PORT, ERR_BAD_PORT, ERR_BAD_FLAG};

const string TOOMANY = "too many arguments.";
const string NOPORT  = "portNumber missing.";
const string BADPORT = "invalid port number passed.";
const string BADFLAG = "invalid flag passed.";

void printError(int retCode){
    switch (retCode){
        case 1: cout << TOOMANY << endl;
                break;
        case 2: cout << NOPORT << endl;
                break;
        case 3: cout << BADPORT << endl;
                break;
        case 4: cout << BADFLAG << endl;
                break;
    }
}//end fx pE


void usage(){
    cout << "Usage: portsetter [flag] [portNumber]" << endl;
    cout << "example: portsetter -p 2345" << endl;
    cout << "Shows port number for listening.\n" << endl;
    cout << "Possible flags:" << endl;
    cout << " -h,    --help      shows this help screen and exits" << endl;
    cout << " -p,    --port      shows port for listening (more to come in phase 2?)\n" << endl;
    cout << "Possible portNumbers:" << endl;
    cout << " 1 - 65535 inclusive\n" << endl;
    cout << "Exit code:" << endl;
    cout << " 0 : success." << endl;
    cout << " 1 : " << TOOMANY << endl;
    cout << " 2 : " << NOPORT << endl;
    cout << " 3 : " << BADPORT << endl;
    cout << " 4 : " << BADFLAG << endl;
}//end fx usage


/**********************************************************
 * input params:    -h, --help
 *                  -p <portNumber>, --port <portNumber>
 * 
 * output expected: "listening on port <portFromCmdLine>"
 * 
**********************************************************/
int main(int argc, char *args[]) {
    const int MAXPORT = 65536;
    string theFlag = "";
    
    if (argc == 1){
        usage();
        return SUCCESS;
    }
    if (argc > 3){
        usage();
        printError(ERR_TOO_MANY);
        return ERR_TOO_MANY;
    }
    theFlag = args[1];
    if (theFlag == "-h" || theFlag == "--help"){
        if (argc == 2){
            usage();
            return SUCCESS;
        }else{
            usage();
            printError(ERR_TOO_MANY);
            return ERR_TOO_MANY;
        }
    }else if (theFlag == "-p" || theFlag == "--port"){
        if (argc == 2){
            usage();
            printError(ERR_NO_PORT);
            return ERR_NO_PORT;
        }
        int thePortArgSize = strlen(args[2]);
        int thePort = atoi(args[2]);
        int thePortToUse = atoi(args[2]);
        int thePortSize;
        for (thePortSize=0; thePort > 0; ++thePortSize) thePort /= 10;
        if (thePortToUse > 0 && thePortToUse < MAXPORT && thePortSize == thePortArgSize){
                cout << "listening on port " << thePortToUse << endl;
                return SUCCESS;
        }else{
            usage();
            printError(ERR_BAD_PORT);
            return ERR_BAD_PORT;
        }
    }else{
        usage();
        printError(ERR_BAD_FLAG);
        return ERR_BAD_FLAG;
    }
}//end fx main
