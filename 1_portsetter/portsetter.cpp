/**********************************************************
cs3370 fall 2016
eric jorgensen
assn1: portsetter
use echo $? to show exit code.
**********************************************************/

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <map>
#include <regex>
#include <vector>

using namespace std;

enum ReturnCodes {SUCCESS, ERR_TOO_MANY, ERR_NO_PORT, ERR_BAD_PORT, ERR_BAD_FLAG, ERR_BAD_ENV};
string localeLang = "en";
map <string, string> localeMessages;
vector <string> langCodesToSkip = {"", "C", "C.UTF-8"};


void loadLocaleMessages(){
    string messageFileToLoad = "setport.messages_" + localeLang + ".txt";
    cout << "messageFileToLoad: " << messageFileToLoad << endl;
   
    string dataToOutput;
    ifstream myFile(messageFileToLoad);
    while (myFile){
        getline(myFile, dataToOutput);
        int eqPos = dataToOutput.find_first_of("=");
        string localeMessageKey = dataToOutput.substr(0, eqPos);
        string localeMessageVal = dataToOutput.substr(eqPos+1);
        localeMessages[localeMessageKey] = localeMessageVal;
    }
    myFile.close();
}//end fx lLm


void printError(int retCode){
    switch (retCode){
        case 1: cout << localeMessages["TOOMANY"] << endl;
                break;
        case 2: cout << localeMessages["NOPORT"] << endl;
                break;
        case 3: cout << localeMessages["BADPORT"] << endl;
                break;
        case 4: cout << localeMessages["BADFLAG"] << endl;
                break;
        case 5: cout << localeMessages["BADENV"] << endl;
                break;
    }
}//end fx pE


string giveLastLineOfFile(char* fileToPrint){
    string tempDataToOutput;
    string finalDataToOuput;
    ifstream myFile(fileToPrint);
    while (myFile){
        getline(myFile, tempDataToOutput);
        if (!tempDataToOutput.empty()) finalDataToOuput = tempDataToOutput;
    }
    myFile.close();
    return finalDataToOuput;
}//end fx gLlOf


void printWholeFile(char* fileToPrint){
    string dataToOutput;
    ifstream myFile(fileToPrint);
    while (myFile){
        getline(myFile, dataToOutput);
        cout << dataToOutput << endl;
    }
    myFile.close();
}//end fx pF


void usage(){
    char myUsage[] = "setport.usage_en.txt";
    printWholeFile(myUsage);
}//end fx usage


void about(){
    char myAbout[] = "setport.about_en.txt";
    printWholeFile(myAbout);
}//end fx about


void version(){
    char myVersion[] = "setport.version.txt";
    string myVers = giveLastLineOfFile(myVersion);
    char myBuild[] = "setport.build.txt";
    string myBld = giveLastLineOfFile(myBuild);
    cout << myVers << "." << myBld << endl;
}//end fx version


int main(int argc, char *args[]) {
    loadLocaleMessages();
    const int MAXPORT = 65536;
    string theFlag = "";
    string thePortFlag ="";
    
    if (argc == 1){
        usage();
        return SUCCESS;
    }
    if (argc > 4){
        usage();
        printError(ERR_TOO_MANY);
        return ERR_TOO_MANY;
    }
    theFlag = args[1];
    if (theFlag == "-?" || theFlag == "-h" || theFlag == "--help"){
        if (argc == 2){
            usage();
            return SUCCESS;
        }
        usage();
        printError(ERR_TOO_MANY);
        return ERR_TOO_MANY;
    }
    if (theFlag == "-!" || theFlag == "--about"){
        if (argc == 2){
            about();
            return SUCCESS;
        }
        usage();
        printError(ERR_TOO_MANY);
        return ERR_TOO_MANY;
    }
    if (theFlag == "-v" || theFlag == "--version"){
        if (argc == 2){
            version();
            return SUCCESS;
        }
        usage();
        printError(ERR_TOO_MANY);
        return ERR_TOO_MANY;
    }
    if (theFlag == "-p" || theFlag == "--port"){
        if (argc == 2){
            usage();
            printError(ERR_NO_PORT);
            return ERR_NO_PORT;
        }
        thePortFlag = args[2];
        string theEnvVar = "";
        int thePortToUse;
        int thePort;
        int thePortSize;
        int thePortArgSize;
        if (thePortFlag == "-e"){
            if (argc > 4){
                usage();
                printError(ERR_TOO_MANY);
                return ERR_TOO_MANY;
            }
            if (argc == 3) theEnvVar = "PORT";
            if (argc == 4) theEnvVar = args[3];
            char* dupedEnvVar = strdup(theEnvVar.c_str());
            char* thePortArg = getenv(dupedEnvVar);
            if (!thePortArg){
                usage();
                printError(ERR_BAD_ENV);
                return ERR_BAD_ENV;
            }
            if (thePortArg){
                thePortArgSize = strlen(getenv(dupedEnvVar));
                thePortToUse = atoi(getenv(dupedEnvVar));
                thePort = atoi(getenv(dupedEnvVar));
            }
        }
        else{
            if (argc > 3){
                usage();
                printError(ERR_TOO_MANY);
                return ERR_TOO_MANY;
            }
            thePortArgSize = strlen(args[2]);
            thePortToUse = atoi(args[2]);
            thePort = atoi(args[2]);
            
        }
        for (thePortSize=0; thePort > 0; ++thePortSize) thePort /= 10;
        if (thePortToUse > 0 && thePortToUse < MAXPORT && thePortSize == thePortArgSize){
                cout << localeMessages["LISTENING"] << " " << thePortToUse << endl;
                return SUCCESS;
        }
        usage();
        printError(ERR_BAD_PORT);
        return ERR_BAD_PORT;
    }
    usage();
    printError(ERR_BAD_FLAG);
    return ERR_BAD_FLAG;
}//end fx main
