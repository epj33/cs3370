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
#include <algorithm>

using namespace std;

enum ReturnCodes {SUCCESS, ERR_TOO_MANY, ERR_NO_PORT, ERR_BAD_PORT, ERR_BAD_FLAG, ERR_BAD_ENV, ERR_DO_ENG};
string localeLang = "en";
map <string, string> localeMessages;
vector <string> langCodesToSkip = {"", "C", "C.UTF-8"};



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
        case 6: cout << localeMessages["DOENGLISH"] << endl;
                break;
    }
}//end fx pE


void fillLocaleVector(string theFileToReadFrom){
    string dataToOutput;
    ifstream myFile(theFileToReadFrom);
    while (myFile){
        getline(myFile, dataToOutput);
        int eqPos = dataToOutput.find_first_of("=");
        string localeMessageKey = dataToOutput.substr(0, eqPos);
        string localeMessageVal = dataToOutput.substr(eqPos+1);
        localeMessages[localeMessageKey] = localeMessageVal;
    }
    myFile.close();
}//end fx fLv


int readLocaleFromEnv(){
    string messageFileToLoad = "i18n/messages/setport.messages_";
    vector <string> envVarsToCheck = {"LANGUAGE", "LC_ALL", "LC_MESSAGES", "LANG"};
    regex mySubEnvLangCode ("(^[[:lower:]]{2})(_[[:upper:]]{2})?(\\.UTF-8)?$");
    smatch myLangMatch;
    bool foundValidLang = false;
    
    for (int i=0; i < envVarsToCheck.size(); ++i ){
        string envLang = getenv( envVarsToCheck.at(i).c_str() ) ?: "";
        if(std::find(langCodesToSkip.begin(), langCodesToSkip.end(), envLang) == langCodesToSkip.end()) {
            if(regex_search(envLang, myLangMatch, mySubEnvLangCode)){
                foundValidLang = true;
                string messageFileToLoadLanguage = messageFileToLoad + myLangMatch[1].str() + ".txt";
                ifstream myFile(messageFileToLoadLanguage);
                if (myFile){
                    myFile.close();
                    fillLocaleVector(messageFileToLoadLanguage);
                    localeLang = myLangMatch[1];
                    return 1;
                }
            }
        }
    }
    localeLang = "en";
    string messageFileToLoadLanguage = messageFileToLoad + localeLang + ".txt";
    fillLocaleVector(messageFileToLoadLanguage);
    if (foundValidLang) printError(ERR_DO_ENG);
    return 0;
}//end fx rLfE


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


int printWholeFile(const char* fileToPrint){
    string dataToOutput = "";
    ifstream myFile(fileToPrint);
    if (!myFile) return 1;
    while (myFile){
        getline(myFile, dataToOutput);
        cout << dataToOutput << endl;
    }
    myFile.close();
    return 0;
}//end fx pF


void usage(){
    string usageFileToLoad = "i18n/usages/setport.usage_" + localeLang + ".txt";
    if (printWholeFile(usageFileToLoad.c_str())){
        printError(ERR_DO_ENG);
        printWholeFile("i18n/usages/setport.usage_en.txt");
    }
}//end fx usage


void about(){
    string aboutFileToLoad = "i18n/abouts/setport.about_" + localeLang + ".txt";
    if (printWholeFile(aboutFileToLoad.c_str())){
        printError(ERR_DO_ENG);
        printWholeFile("i18n/abouts/setport.about_en.txt");
    }
}//end fx about


void version(){
    char myVersion[] = "setport.version.txt";
    string myVers = giveLastLineOfFile(myVersion);
    char myBuild[] = "setport.build.txt";
    string myBld = giveLastLineOfFile(myBuild);
    cout << myVers << "." << myBld << endl;
}//end fx version


int main(int argc, char *args[]) {
    readLocaleFromEnv();
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
