//This file contains the code for handeling each implemented mode
#pragma once

#include "common.h"

#include <iostream>

#ifdef I_AM_A_TA
//Too bad you don't have this file...
#include "obfuscation-raw.h"
#else
#include "obfuscation.h"
#endif


using namespace std;

//prints the uin
void mode0(const UIN& uin){
    cout << "The mode is 0 and the UIN is " << uin << endl;
    cout << "Thats all this does." << endl;
}

void mode1(const UIN& uin){
    cout << "The mode is 1 and the UIN is " << uin << endl;
    cout << "Simply throws some exception." << endl;
    cout << "What line is the exception thrown on? (try using `where` to see all stack frames`)" << endl;
    mode1Obfuscation1();
}

void mode2(const UIN& uin){
    cout << "The mode is 2 and the UIN is " << uin << endl;
    cout << "What happens and on what line? (try using `list`)" << endl;
    cout << "There is a variable in scope called answer. What is its value? (`print answer`)" << endl;
    cout << "Fun Fact: you can use ctrl-c to stop the program and enter the debugger." << endl;
    mode2Obfuscation1();
}

void mode3(const UIN& uin){
    cout << "The mode is 3 and the UIN is " << uin << endl;
    cout << "Analyze the stack trace for the magic fruit." << endl;
    cout << "What is the magic fruit for input 221002021?" << endl;
    cout << "How does the magic fruit change with UIN changes?" << endl;
    mode3Obfuscation1(uin);
}

void mode6(const UIN& uin){
    cout << "The mode is 6 and the UIN is " << uin << endl;
    cout << "What is the exception for input 221002021?" << endl;
    cout << "How does the exception change as the UIN changes?" << endl;
    cout << "Do you see the pattern?" << endl;
    mode6Obfuscation1(uin);
}

void mode7(const UIN& uin){
    cout << "The mode is 7 and the UIN is " << uin << endl;
    cout << "Use the stack trace to see the unmasked exception." << endl;
    cout << "What is the exception for input 221002021?" << endl;
    cout << "How does the exception change as the UIN changes?" << endl;
    cout << "Do you see the pattern?" << endl;
    mode7Obfuscation1(uin);
}

void mode8(const UIN& uin){
    cout << "The mode is 8 and the UIN is " << uin << endl;
    cout << ">I am creating a secret message " << endl;
    cout << ">Hopefully nobody reads it " << endl;
    cout << "Channel your inner NSA agent: what is the message?" << endl;
    mode8Obfuscation1();
}

void mode9(const UIN& uin){
    cout << "The mode is 9 and the UIN is " << uin << endl;
    cout << ">I am creating a secret message " << endl;
    cout << ">Unfortunately, I will delete it before I throw an exception" << endl;
    cout << "If only you had a tool to stop on a specific line..." << endl;
    cout << "Hint: do you know how to set a breakpoint in GDB? " << endl;
    mode9Obfuscation1();
}

void mode10(const UIN& uin){
    cout << "The mode is 10 and the UIN is " << uin << endl;
    cout << ">I have solved it, I will pack the message into an array of random messages" << endl;
    cout << ">This way someone would have to have access to the raw memory to see my messages" << endl;
    cout << ">This will be truly unbreakable. Now I can send my secrets in peace" << endl;
    cout << "It isnt... What is the message?" << endl; 
    mode10Obfuscation1();
}

void mode11(const UIN& uin){
    cout << "The mode is 11 and the UIN is " << uin << endl;
    cout << ">I will use the previous scheme, but not give the pointer away directly" << endl;
    cout << ">Rather, I will hide the pointer behind alot of math" << endl;
    cout << ">Thus my code must run to recover the base pointer" << endl;
    cout << "Unfortunately, it looks like the implementation is flawed and the loop runs forever" << endl;
    cout << "You know the drill... What is the message?" << endl; 
    mode11Obfuscation1();
}
