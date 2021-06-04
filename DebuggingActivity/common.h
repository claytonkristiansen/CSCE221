#pragma once

//Constants and Type Defs common to all functions

#include <string>

using UIN = std::string;

#define UIN_LENGTH 9

//what is the largest mode allowed
// #define MAX_MODE 1

//this a function pointer, a pointer to a function to call
//  this lets a function call a different function at runtime depending on input
//  very powerful, but also very easy to missuse
//you don't need to understand how it works/what it does for this assignment,
using ReentryFunctionPointer = void (*)(void);
using FunctionPointerArray = void (*)(ReentryFunctionPointer);