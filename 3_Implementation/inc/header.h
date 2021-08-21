/**
 * @file header.h
 * @author Abhay Sahu
 * @brief declaration of gettng Vwap and Date from .csv file, simple moving average, and check sma crossover 
 * @version 0.1
 * @date 2021-07-11
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/* Header Guard */
#ifndef __READCSV_H
#define __READCSV_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * @brief read everyday closing price of shares from csv files downloaded for nseindia.com
 * 
 * @return int *array
 */
float *readColumn(FILE *file_p,int column);

/**
 * @brief read date of BUY and SELL calls from csv files downloaded for nseindia.com
 * 
 * @return char *
 */
char *readDate(char *fl, int n);

/**
 * @brief calculates simple moving average of last 14 days and 28 days
 * 
 * @return int
 */
float sma(int days, int crtday, float *coloumnArray);

/**
 * @brief tells if the 14 days sma is above or below the 28 days sma
 * 
 * @return _Bool
 */
_Bool smaCrossover( int sm1, int sm2, int crtday, float *coloumnArray);

void smaStrategy(char *file);

#endif
