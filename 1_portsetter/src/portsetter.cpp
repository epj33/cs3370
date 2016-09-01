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

void usage(){
    cout << "Usage: portsetter <flag> <portnumber>" << endl;
    cout << "Shows port number for listening.\n" << endl;
    cout << "Return codes:" << endl;
    cout << "0 : success." << endl;
    cout << "1 : too many arguments" << endl;
    cout << "2 : invalid port number passed" << endl;
    cout << "3 : invalid flag passed" << endl;
}//end fx usage


/**********************************************************
 * input params:    -h, --h
 *                  -p <portNumber>, --port <portNumber>
 * 
 * output expected: "listening on port <portFromCmdLine>"
 * 
**********************************************************/
int main(int argc, char *args[]) {
    //cout << args[1] << endl;
    if (argc == 1){
        usage();
        return 0;
    }
    if (argc > 3){
        usage();
        return 1;
    }
    string theFlag = args[1];
    if (theFlag == "-h" || theFlag == "--help"){
        usage();
        return 0;
    }else if (theFlag == "-p" || theFlag == "--port"){
        //theFlag = args[1];
        int thePort = atoi(args[2]);
        if (thePort > 0 && thePort < 65537){
            cout << "listening on a port " << args[2] << endl;
            return 0;
        }else{
            usage();
            return 2;
        }
    }else{
        usage();
        return 3;
    }
    
}//end fx main
