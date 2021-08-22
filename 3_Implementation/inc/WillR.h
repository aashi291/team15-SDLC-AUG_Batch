#ifndef __WILLR_H
#define __WILLR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "header.h"

bool buyCondition(int , int , float *, int );
float findDMA(int , int , float *, int);
int findWillR(int ,float *,int , int , int);
int findLength();

#endif