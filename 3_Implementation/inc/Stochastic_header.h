/**
 * @file Stochastic_header.h
 * @author Pushkar Pramod Wani (pushkar.wani@ltts.com)
 * @PS No. 99005816
 * @brief 
 * @version 0.1
 * @date 2021-08-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */







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
