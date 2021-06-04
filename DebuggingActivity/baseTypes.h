//Contains the un-obfuscated base types for the functions to call/throw

#pragma once

#include "common.h"

#include <exception>
#include <iostream>
#include <string.h> // for c-string functions

class Exception0 : std::exception {};
class Exception1 : std::exception {};
class Exception2 : std::exception {};
class Exception3 : std::exception {};
class Exception4 : std::exception {};
class Exception5 : std::exception {};
class Exception6 : std::exception {};
class Exception7 : std::exception {};
class Exception8 : std::exception {};
class Exception9 : std::exception {};

class MaskedException : std::exception {};


//each of these simply call the provided function from the pointer
void theMagicFruitIsApple(ReentryFunctionPointer p) { p(); return;}
void theMagicFruitIsBanana(ReentryFunctionPointer p) { p(); return;}
void theMagicFruitIsCherry(ReentryFunctionPointer p) { p(); return;}
void theMagicFruitIsDate(ReentryFunctionPointer p) { p(); return;}
void theMagicFruitIsElderberry(ReentryFunctionPointer p) { p(); return;}
void theMagicFruitIsFig(ReentryFunctionPointer p) { p(); return;}
void theMagicFruitIsGrape(ReentryFunctionPointer p) { p(); return;}
void theMagicFruitIsHoneydew(ReentryFunctionPointer p) { p(); return;}
void theMagicFruitIsLime(ReentryFunctionPointer p) { p(); return;}
void theMagicFruitIsJuice(ReentryFunctionPointer p) { p(); return;}

//throws a line that reports the error that 
void throwOnSomeLine(void){
    std::cerr << "About to throw an error with the line number of the error " << std::endl;
    throw __LINE__;
}

void infiniteLoopError(void){
    int i = 0;
    int answer = __LINE__ + 1;
    while(true){i += 1;}
    std::cout << i << answer << std::endl;
    return;
}


//masks the actual exception thrown
//  takes a function pointer to allow for insertion 
//  anwhere in the call-stack
template <class FuncPointer>
void exceptionMasker(FuncPointer f, uint const number){
    try{
        f(number);
    }catch(const char* e){
        //generic string exception
        //i.e. throw "some message";
        throw MaskedException();
    }catch(const int e){
        //generic int exception
        //i.e. throw 5;
        throw MaskedException();
    }catch(const Exception0 e){
        throw MaskedException();
    }catch(const Exception1 e){
        throw MaskedException();
    }catch(const Exception2 e){
        throw MaskedException();
    }catch(const Exception3 e){
        throw MaskedException();
    }catch(const Exception4 e){
        throw MaskedException();
    }catch(const Exception5 e){
        throw MaskedException();
    }catch(const Exception6 e){
        throw MaskedException();
    }catch(const Exception7 e){
        throw MaskedException();
    }catch(const Exception8 e){
        throw MaskedException();
    }catch(const Exception9 e){
        throw MaskedException();
    }
}

void permanentMessage(char* myMessage, unsigned int messageLength){
    throw "Dont Read My Messages";
}

//erases the value stored at c before throwing the exception
void ephemeralMessage(char* myMessage, unsigned int messageLength){
    //VVV this line erases the messages
    memset(myMessage, 0, messageLength);
    messageLength = 0;
    throw "Secrets Destroyed";
}

// somewhere in c[0] to c[numMessages-1] there is a hidden message; 
void hiddenMessage(char** messageArray, unsigned int numMessages, unsigned int messageLength){
    //VVV this line erases the messages
    memset(messageArray, 0, sizeof(char*) * numMessages);
    throw "Perfect Encryption";
}

void reallyHiddenMessage(uintptr_t ptr, uintptr_t ptr1, uintptr_t ptr2){
    int sleep_ctr = 0;
    while(sleep_ctr < 256) {
        sleep_ctr *= 2;
    }

    void* truePointer = (void*)(ptr ^ ptr1 ^ ptr2);

    //Some really, really nasty pointer math
    char *** bufferChar = (char***)(truePointer);
    unsigned int* bufferInt = (unsigned int*)(bufferChar+1);

    //call the previous message handler
    hiddenMessage(*bufferChar, bufferInt[0], bufferInt[1]);
}