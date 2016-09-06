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
    cout << "Usage: portsetter [flag] [portNumber]" << endl;
    cout << "example: portsetter -p 2345" << endl;
    cout << "Shows port number for listening.\n" << endl;
    cout << "Possible flags:" << endl;
    cout << " -h,    --help      shows this help screen and exits" << endl;
    cout << " -p,    --port      shows port for listening (more to come in phase 2?)\n" << endl;
    cout << "Possible portNumbers:" << endl;
    cout << " 1 - 65536 inclusive\n" << endl;
    cout << "Exit code:" << endl;
    cout << " 0 : success." << endl;
    cout << " 1 : too many arguments." << endl;
    cout << " 2 : invalid portNumber passed / portNumber missing." << endl;
    cout << " 3 : invalid flag passed." << endl;
}//end fx usage


/**********************************************************
 * input params:    -h, --help
 *                  -p <portNumber>, --port <portNumber>
 * 
 * output expected: "listening on port <portFromCmdLine>"
 * 
**********************************************************/
int main(int argc, char *args[]) {
    if (argc == 1){
        usage();
        return 0;
    }
    if (argc > 3){
        usage();
        return 1;
    }
    string theFlag = args[1];
    if (theFlag.compare("-h") == 0 || theFlag.compare("--help") == 0){
        usage();
        return 0;
    }else if (theFlag.compare("-p") == 0 || theFlag.compare("--port") == 0){
        if (argc == 2){
            usage();
            return 2;
        }
        int thePort = atoi(args[2]);
        if (thePort > 0 && thePort < 65537){
            cout << "listening on port " << thePort << endl;
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
