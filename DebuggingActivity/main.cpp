#include "common.h"

#include <iostream>
#include <random> // srand, rand
#include <string> // stoi
#include <time.h> // time

#include "modeHandlers.h"

using namespace std;

UIN getRandomUIN(void){
    UIN uin;
    uin.resize(UIN_LENGTH);
    for(int i = 0; i < UIN_LENGTH; i++){
        if(i == 3 || i == 4){
            uin[i] = '0';
        }
        else{
            uin[i] = (rand() % 10) + '0';
        }
    }
    return uin;
}

//retrun true iff this is a valid uin
bool isValidUIN(const UIN& uin){
    if (uin.length() != UIN_LENGTH)
    {
        return false;
    }

    for(int i = 0; i < UIN_LENGTH; i++){
        if(i == 3 || i == 4){
            if(uin[i] != '0') {
                return false;
            }
        }else{
            int8_t difference = uin[i] - '0';
            if(difference < 0 || difference >= 10){
                return false;
            }
        }
    }

    return true;
}

//prints command line help info and exits
void printHelpAndExit(const int argc, const char* const * const argv){
    cout << "Expects two command line arguments: " << argv[0] << " <mode> <optional : UIN>" << endl;
    cout << "  mode - an integer representing the scenario to run" << endl;
    // cout << "    1 - TODO" << endl;
    cout << "  UIN - a valid Unique Input Notation constructed according to the following regex: ([0-9]{3}00[0-9]{4})" << endl;
    cout << "    Three characters in the range 0-9" << endl;
    cout << "    Two character 0" << endl;
    cout << "    Four characters in the range 0-9" << endl;
    cout << "    If a UIN is not provided, a random one will be generated" << endl;
    exit(0);
}

int main(int argc, char** argv){
    if(argc <= 1 || argc > 3){
        printHelpAndExit(argc, argv);
    }
    srand(time(NULL));
    
    int mode; 
    UIN inputUIN;
    
    try{
        mode = stoi(argv[1]);
    }
    catch (invalid_argument){
        cerr << "Error: Could not convert '" << argv[1] << "' to an int." << endl;
        printHelpAndExit(argc, argv);
    }
    catch (out_of_range){
        cerr << "Error: Integer '" << argv[1] << "' too large for int." << endl;
        printHelpAndExit(argc, argv);
    }

    // if(mode < 0 || mode > MAX_MODE){
    //     cerr << "Error: Illegal value for mode argument: " << mode << endl;
    //     printHelpAndExit(argc, argv);
    // }

    if(argc == 2) {
        inputUIN = getRandomUIN();
    }else{
        inputUIN = UIN(argv[2]);
    }

    if(isValidUIN(inputUIN) == false){
        cerr << "Error invalid UIN: " << inputUIN << endl;
        printHelpAndExit(argc, argv);
    }

    cout << "Arguments processed ok.\n  Mode: " << mode << "\n  UIN: " << inputUIN << endl;


    switch (mode)
    {
    //this macro simply expands the case structure to call the requisite mode handler
    case 0 : mode0(inputUIN); break;
    case 1 : mode1(inputUIN); break;
    case 2 : mode2(inputUIN); break;
    case 3 : mode3(inputUIN); break;
    case 4 : cout << "Does Nothing\n"; break;
    case 5 : cout << "Does Nothing\n"; break;
    case 6 : mode6(inputUIN); break;
    case 7 : mode7(inputUIN); break;
    case 8 : mode8(inputUIN); break;
    case 9 : mode9(inputUIN); break;
    case 10 : mode10(inputUIN); break;
    case 11 : mode11(inputUIN); break;
    
    default:
        cerr << "No mode function found for " << mode << endl;
        printHelpAndExit(argc, argv);
    }

    cout << "Exit without exception." << endl;
}