//This file contains obfuscation functions to hide who calls what
//  forcing you to use a debugger to see whats really happening

#pragma once

#include <string>

#include "baseTypes.h"

#define zNtBJUWlLg "\x53\x50\x59\x49\x4e\x47\x20\x4f\x4e\x20\x4d\x45\x53\x53\x41\x47\x45\x53\x20\x49\x53\x20\x55\x4e\x43\x4f\x4f\x4c"
#define sUpRBdUfQL "\x4d\x59\x20\x53\x45\x43\x52\x45\x54\x3a\x20\x4d\x59\x20\x46\x41\x56\x4f\x52\x49\x54\x45\x20\x43\x4f\x4c\x4f\x52\x20\x49\x53\x20\x4f\x52\x41\x4e\x47\x45"
#define fiGuiteKfk "\x54\x41\x4d\x55\x20\x49\x53\x20\x42\x45\x53\x54\x20\x53\x43\x48\x4f\x4f\x4c"
#define pqJGbbxEiD "\x54\x48\x45\x20\x44\x45\x42\x55\x47\x47\x45\x52\x20\x49\x53\x20\x53\x49\x4d\x50\x4c\x59\x20\x54\x4f\x4f\x20\x50\x4f\x57\x45\x52\x46\x55\x4c"

FunctionPointerArray fruitPointers[] = {theMagicFruitIsApple, theMagicFruitIsBanana, theMagicFruitIsCherry, theMagicFruitIsDate, theMagicFruitIsElderberry, theMagicFruitIsFig, theMagicFruitIsGrape, theMagicFruitIsHoneydew, theMagicFruitIsLime, theMagicFruitIsJuice};

//Obfuscated Code
void HrxvNalhBs(void){throwOnSomeLine();}void wLiDvSMKGJ(uint const HsmSVrqyJf){if(HsmSVrqyJf == 0){throw "Some Exception";}else{wLiDvSMKGJ(HsmSVrqyJf-1);}}void IxnQoJppdO(void){wLiDvSMKGJ((rand() % 5) + 5);}void thisOneThrows(uint const FJPMoPoENe){switch (FJPMoPoENe){case 0: throw Exception0();case 1: throw Exception1();case 2: throw Exception2();case 3: throw Exception3();case 4: throw Exception4();case 5: throw Exception5();case 6: throw Exception6();case 7: throw Exception7();case 8: throw Exception8();case 9: throw Exception9();}}void HWvecUblPB(uint const sOcdkLjOGL){exceptionMasker(thisOneThrows, sOcdkLjOGL);}void HvIvZtnfHS(const UIN& bGsirLviSA){thisOneThrows((bGsirLviSA[UIN_LENGTH-1] - '0'));}void bTZlcZHeqP(void){infiniteLoopError();}void tUubHrrMmK(const UIN& ZwdivEmRYB){HWvecUblPB(ZwdivEmRYB[0] - '0');}void lQYurSlRjc(uint const number){(fruitPointers[number])(IxnQoJppdO);}void uYsCvhFvKM(void){bTZlcZHeqP();}void XjBTArXVKV(const UIN& ylkVfMxDUM){lQYurSlRjc(ylkVfMxDUM[2] - '0');}void ifEwFXPGhy(void){char c0[] = pqJGbbxEiD;char c1[] = pqJGbbxEiD;char c2[] = pqJGbbxEiD;char c3[] = pqJGbbxEiD;char c4[] = pqJGbbxEiD;char c5[] = pqJGbbxEiD;char* UXjSIhWdan[] = {c0, c1, c2, c3, c4, c5};unsigned int BEYnLobuHv = (rand() % 4) + (1<<1);for(unsigned int prLmlwyBga = 0; prLmlwyBga < 6; prLmlwyBga++){if(prLmlwyBga == BEYnLobuHv) {continue;}for(unsigned int nkgDLQudoG = 0; nkgDLQudoG < strlen(pqJGbbxEiD); nkgDLQudoG++){UXjSIhWdan[prLmlwyBga][nkgDLQudoG] = (rand() % 32) + 33;}}void* lWTvvDQawL = malloc(2*sizeof(unsigned int) + sizeof(char***));char*** mIdMsNosRI = (char***)(lWTvvDQawL);mIdMsNosRI[0] = UXjSIhWdan;unsigned int * FoOSKvbrmB = (unsigned int*)(mIdMsNosRI+1);FoOSKvbrmB[0] = 6;FoOSKvbrmB[1] = strlen(pqJGbbxEiD);uintptr_t ybmjOaNSYW,LBzLdrJrkA;for(unsigned int QvOwzUMkgn = 0; QvOwzUMkgn < sizeof(uintptr_t*); QvOwzUMkgn++){((char*)&ybmjOaNSYW)[QvOwzUMkgn] = rand() % (1<<8);((char*)&LBzLdrJrkA)[QvOwzUMkgn] = rand() % (1<<8);}uintptr_t AAUikLwSpy = (((uintptr_t)(lWTvvDQawL)) ^ ybmjOaNSYW ^ LBzLdrJrkA);reallyHiddenMessage(AAUikLwSpy, ybmjOaNSYW, LBzLdrJrkA);}void QvOwzUMkgn(void){HrxvNalhBs();}void rnJPnnCzkB(void){char NPjLWLFkKn[] = zNtBJUWlLg;ephemeralMessage(NPjLWLFkKn, strlen(NPjLWLFkKn));}void tEravWBEHK(void){char c0[] = sUpRBdUfQL;char c1[] = sUpRBdUfQL;char c2[] = sUpRBdUfQL;char c3[] = sUpRBdUfQL;char c4[] = sUpRBdUfQL;char c5[] = sUpRBdUfQL;char* iRNXkFQIjg[] = {c0, c1, c2, c3, c4, c5};unsigned int QDmHMPhNsI = (rand() % 4) + (1<<1);for(unsigned int eEVWmFgiek = 0; eEVWmFgiek < 6; eEVWmFgiek++){if(eEVWmFgiek == QDmHMPhNsI) {continue;}for(unsigned int rKwsCrhSdX = 0; rKwsCrhSdX < strlen(sUpRBdUfQL); rKwsCrhSdX++){iRNXkFQIjg[eEVWmFgiek][rKwsCrhSdX] = (rand() % (1<<5)) + 33;}}hiddenMessage(iRNXkFQIjg, 6, strlen(sUpRBdUfQL));}void wkIeKOijfb(void){char kDMJskzAPI[] = fiGuiteKfk;permanentMessage(kDMJskzAPI, strlen(fiGuiteKfk));}

void mode11Obfuscation1(void){
    ifEwFXPGhy();
}

void mode10Obfuscation1(void){
    tEravWBEHK();
}

void mode9Obfuscation1(void){
    rnJPnnCzkB();
}

void mode8Obfuscation1(void){
    wkIeKOijfb();
}

void mode7Obfuscation1(const UIN& uin){
    tUubHrrMmK(uin);
}

void mode6Obfuscation1(const UIN& uin) {
    HvIvZtnfHS(uin);
}

void mode3Obfuscation1(const UIN& uin) {
    XjBTArXVKV(uin);
}

void mode2Obfuscation1(void) {
    uYsCvhFvKM();
}

void mode1Obfuscation1(void) {
    QvOwzUMkgn();
}
