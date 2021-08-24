/**
 * @file WillR.h
 * @author Alna Satheesh(alna.satheesh@ltts.com)
 * @brief headerfile for the williams%R strategy
 * @version 0.1
 * @date 2021-08-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef __WILLR_H
#define __WILLR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "header.h"
/**
 * @brief function to check if the strategy asks to buy or sell stocks according to data provided from NSE
 * 
 * @return true 
 * @return false 
 */
bool buyCondition(int , int , float *, int );
/**
 * @brief function to find the value of DMA (displaced moving average) that is used as an indicator for the strategy used.
 * found using the closing prices for a period of time (default-100/100DMA).
 * 
 * @return float 
 */
float findDMA(int , int , float *, int);
/**
 * @brief function to find the value of Williams%R variable which is used as an indicator for the Williams%R strategy
 * calculated using the highest high of the previous (14)days and lowest low of the previous (14) days and closing price
 * 
 * @return int 
 */
float findWillR(int,int ,int, int, float* ,float *, float *);
/**
 * @brief used to find the length of the .csv file so that navigation from the furthest date is possible
 * 
 * @return int 
 */
int findLength(char *);   //to find the number of rows in file
float highHigh(int ,int);
float lowLow(int,int );

#endif