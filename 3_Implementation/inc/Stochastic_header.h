#ifndef __STOCHASTIC_H
#define __STOCHASTIC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "header.h"



_Bool Stochastic_crossover( int , int , float* ,float* , float* );

void Stochastic_Strategy(char * filePath);

float funforK(int ,int , float* , float* , float*);

float funforD(int ,int , float* , float* , float*);

int findLengthOfArray(char* );



#endif