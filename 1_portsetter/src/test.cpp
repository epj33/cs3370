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

int runHappyTests(int verbosity = 1){
    if (verbosity){
        //verbose tests
        if (system("setport")/256 != 0){
            cout << "happy test only binary name failed." << endl;
            return 1;
        }
        cout << "happy test only binary name passed." << endl;
        
        
        if (system("setport -!")/256 != 0){
            cout << "happy test bin -! failed." << endl;
            return 1;
        }
        cout << "happy test bin -! passed." << endl;
        
        if (system("setport --about")/256 != 0){
            cout << "happy test bin --about failed." << endl;
            return 1;
        }
        cout << "happy test bin --about passed." << endl;
        
        
        if (system("setport -h")/256 != 0){
            cout << "happy test bin -h failed." << endl;
            return 1;
        }
        cout << "happy test bin -h passed." << endl;
        
        if (system("setport -?")/256 != 0){
            cout << "happy test bin -? failed." << endl;
            return 1;
        }
        cout << "happy test bin -? passed." << endl;
        
        if (system("setport --help")/256 != 0){
            cout << "happy test bin --help failed." << endl;
            return 1;
        }
        cout << "happy test bin --help passed." << endl;
        
        
        if (system("setport -v")/256 != 0){
            cout << "happy test bin -v failed." << endl;
            return 1;
        }
        cout << "happy test bin -v passed." << endl;
        
        if (system("setport --version")/256 != 0){
            cout << "happy test bin --version failed." << endl;
            return 1;
        }
        cout << "happy test bin --version passed." << endl;
        
        
        if (system("setport -p 4040")/256 != 0){
            cout << "happy test bin -p num failed." << endl;
            return 1;
        }
        cout << "happy test bin -p num passed." << endl;
        
        if (system("setport -p -e")/256 != 0){
            cout << "happy test bin -p -e failed." << endl;
            return 1;
        }
        cout << "happy test bin -p -e passed." << endl;
        
        if (system("setport -p -e PORT")/256 != 0){
            cout << "happy test bin -p -e envVar failed." << endl;
            return 1;
        }
        cout << "happy test bin -p -e envVar passed." << endl;
        
        if (system("setport --port 4040")/256 != 0){
            cout << "happy test bin --port num failed." << endl;
            return 1;
        }
        cout << "happy test bin --port num passed." << endl;
        
        
        int spanishSysReturn = system("setport -! > testEs1.txt | echo >> testEs1.txt")/256;
        system("printf %s \"$(cat testEs1.txt)\" > out1.txt"); //removes all /ns
        system("echo >> out1.txt");
        int spanishCmpReturn = system("cmp -s i18n/abouts/setport.about_es.txt out1.txt")/256;
        if (spanishSysReturn != 0 || spanishCmpReturn != 0){
            cout << "happy test -! es failed." << endl;
            return 1;
        }
        system("rm testEs1.txt out.txt");
        cout << "happy test -! es passed." << endl;
        return 1;


    
    }else{
        //quiet tests
        assert (system("setport > /dev/null")/256 == 0);
        assert (system("setport -h > /dev/null")/256 == 0);
        assert (system("setport -? > /dev/null")/256 == 0);
        assert (system("setport --help > /dev/null")/256 == 0);
        
        assert (system("setport -! > /dev/null")/256 == 0);
        assert (system("setport --about > /dev/null")/256 == 0);
        
        assert (system("setport -v > /dev/null")/256 == 0);
        assert (system("setport --version > /dev/null")/256 == 0);
        
        assert (system("setport -p 4040 > /dev/null")/256 == 0);
        assert (system("setport -p -e > /dev/null")/256 == 0);
        assert (system("setport -p -e PORT > /dev/null")/256 == 0);
        assert (system("setport --port 4040 > /dev/null")/256 == 0);
        assert (system("setport --port -e > /dev/null")/256 == 0);
        assert (system("setport --port -e PORT > /dev/null")/256 == 0);
        
        int spanishSysReturn = system("setport -! > testEs.txt | echo >> testEs.txt")/256;
        system("printf %s \"$(cat testEs.txt)\" > out.txt"); //removes all /ns
        system("echo >> out.txt");
        int spanishCmpReturn = system("cmp -s i18n/abouts/setport.about_es.txt out.txt")/256;
        system("rm testEs.txt out.txt");
        assert (spanishSysReturn == 0 && spanishCmpReturn == 0);

    }
    cout << "all happy tests passed" << endl;
    return 0;
}//end fx rHt

int runSadTests(int verbosity = 1){
    if (verbosity){
        //verbose tests
        if (system("setport help")/256 != 4){
            cout << "sad test bin help failed." << endl;
            return 1;
        }
        cout << "sad test bin help passed." << endl;    
        if (system("setport ?")/256 != 4){
            cout << "sad test bin ? failed." << endl;
            return 1;
        }
        cout << "sad test bin ? passed." << endl;
        
        if (system("setport -help")/256 != 4){
            cout << "sad test bin -help failed." << endl;
            return 1;
        }
        cout << "sad test bin -help passed." << endl;
        
        if (system("setport --h")/256 != 4){
            cout << "sad test bin --h failed." << endl;
            return 1;
        }
        cout << "sad test bin --h passed." << endl;
        
        if (system("setport --?")/256 != 4){
            cout << "sad test bin --? failed." << endl;
            return 1;
        }
        cout << "sad test bin --? passed." << endl;
        
        if (system("setport -h --help")/256 != 1){
            cout << "sad test bin -h --help failed." << endl;
            return 1;
        }
        cout << "sad test bin -h --help passed." << endl;
        
        if (system("setport -h -? --help")/256 != 1){
            cout << "sad test bin -h -? --help failed." << endl;
            return 1;
        }
        cout << "sad test bin -h -? --help passed." << endl;
        
        if (system("setport -hs")/256 != 4){
            cout << "sad test bin -hs failed." << endl;
            return 1;
        }
        cout << "sad test bin -hs passed." << endl;
        
        
        if (system("setport --!")/256 != 4){
            cout << "sad test bin --! failed." << endl;
            return 1;
        }
        cout << "sad test bin --! passed." << endl;
        
        if (system("setport -about")/256 != 4){
            cout << "sad test bin -about failed." << endl;
            return 1;
        }
        cout << "sad test bin -about passed." << endl;
        
        if (system("setport -! --about")/256 != 1){
            cout << "sad test bin -! --about failed." << endl;
            return 1;
        }
        cout << "sad test bin -! --about passed." << endl;
        
        
        if (system("setport --v")/256 != 4){
            cout << "sad test bin --v failed." << endl;
            return 1;
        }
        cout << "sad test bin --v passed." << endl;
        
        if (system("setport -version")/256 != 4){
            cout << "sad test bin -version failed." << endl;
            return 1;
        }
        cout << "sad test bin -version passed." << endl;
        
        if (system("setport -v --version")/256 != 1){
            cout << "sad test bin -v --version failed." << endl;
            return 1;
        }
        cout << "sad test bin -v --version passed." << endl;
        
        
        if (system("setport -p --port 9")/256 != 1){
            cout << "sad test bin -p --port num failed." << endl;
            return 1;
        }
        cout << "sad test bin -p --port num passed." << endl;
        
        if (system("setport -p 77 33")/256 != 1){
            cout << "sad test bin -p num num failed." << endl;
            return 1;
        }
        cout << "sad test bin -p num num passed." << endl;
        
        if (system("setport -p -21")/256 != 3){
            cout << "sad test bin -p neg num failed." << endl;
            return 1;
        }
        cout << "sad test bin -p neg num passed." << endl;
        
        if (system("setport -p 0")/256 != 3){
            cout << "sad test bin -p zero failed." << endl;
            return 1;
        }
        cout << "sad test bin -p zero passed." << endl;
        
        if (system("setport --port")/256 != 2){
            cout << "sad test bin --port no num failed." << endl;
            return 1;
        }
        cout << "sad test bin --port no num passed." << endl;
        
        if (system("setport -p 90642")/256 != 3){
            cout << "sad test bin -p high num failed." << endl;
            return 1;
        }
        cout << "sad test bin -p high num passed." << endl;
        
        
        if (system("setport -x")/256 != 4){
            cout << "sad test bin -x failed." << endl;
            return 1;
        }
        cout << "sad test bin -x passed." << endl;
        
        if (system("setport -P")/256 != 4){
            cout << "sad test bin -P failed." << endl;
            return 1;
        }
        cout << "sad test bin -P passed." << endl;
        
        int spanishSysReturn = system("setport -! > testEs.txt | echo >> testEs.txt")/256;
        system("printf %s \"$(cat testEs.txt)\" > out.txt"); //removes all /ns
        system("echo >> out.txt");
        int spanishCmpReturn = system("cmp -s i18n/abouts/setport.about_BADLANG.txt out.txt")/256;
        if (spanishSysReturn == 0 && spanishCmpReturn == 0){
            cout << "sad test -! es failed." << endl;
            return 1;
        }
        system("rm testEs.txt out.txt");
        cout << "sad test -! es passed." << endl;
        
    }else{
        //quiet tests
        assert (system("setport help > /dev/null")/256 == 4);
        assert (system("setport ? > /dev/null")/256 == 4);
        assert (system("setport -help > /dev/null")/256 == 4);
        assert (system("setport --h > /dev/null")/256 == 4);
        assert (system("setport --? > /dev/null")/256 == 4);
        assert (system("setport -h --help > /dev/null")/256 == 1);
        assert (system("setport -h -? --help > /dev/null")/256 == 1);
        assert (system("setport -hs > /dev/null")/256 == 4);
        
        assert (system("setport -about > /dev/null")/256 == 4);
        assert (system("setport --! > /dev/null")/256 == 4);
        assert (system("setport -! --about > /dev/null")/256 == 1);
        
        assert (system("setport -version > /dev/null")/256 == 4);
        assert (system("setport --v > /dev/null")/256 == 4);
        assert (system("setport -v --version > /dev/null")/256 == 1);
        
        assert (system("setport -p --port 9 > /dev/null")/256 == 1);
        assert (system("setport -p -e --port 9 > /dev/null")/256 == 1);
        assert (system("setport -p 77 33 > /dev/null")/256 == 1);
        assert (system("setport -p -e 9 > /dev/null")/256 == 5);
        assert (system("setport -p -e OI098DGFKJLHERT78YERTJ5NDFGS2HGUY8ZPPPPP0P > /dev/null")/256 == 5);
        assert (system("setport -p -21 > /dev/null")/256 == 3);
        assert (system("setport -p 0 > /dev/null")/256 == 3);
        assert (system("setport --port > /dev/null")/256 == 2);
        assert (system("setport -p 90642 > /dev/null")/256 == 3);
        
        assert (system("setport -x > /dev/null")/256 == 4);
        assert (system("setport -P > /dev/null")/256 == 4);
        
        int spanishSysReturn = system("setport -! > testEs.txt | echo >> testEs.txt")/256;
        system("printf %s \"$(cat testEs.txt)\" > out.txt"); //removes all /ns
        int spanishCmpReturn = system("cmp -s i18n/abouts/setport.about_es.txt out.txt")/256;
        system("rm testEs.txt out.txt");
        assert (spanishCmpReturn == 1);

        
    }
    cout << "all sad tests passed" << endl;
    return 0;
}//end fx rSt


int main(int argc, char *args[]) {
    int verboseFlag = 0;
    if (argc > 1){
        verboseFlag = atoi(args[1]);
    }
    int happyRet = runHappyTests(verboseFlag);
    int sadRet   = runSadTests(verboseFlag);
    return (happyRet + sadRet);
}//end fx main
