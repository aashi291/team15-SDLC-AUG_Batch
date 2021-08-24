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
#include <math.h>

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

/**
 * @brief The function executes the SMA Strategy by considering the user choices
 * 
 * @param file 
 */
void smaStrategy(char *file);

/**
 * @brief This function calculates the middle band moving average for a given trading day based on the closing prices.
 * 
 * @return float 
 */
float movingMiddleBand(int noOfDaysMA, int presentDay,float* closePriceColumn);

/**
 * @brief This function calaculates the standard deviation of a given trading day closing price from the middle band average.
 * 
 * @return float 
 */
float stdDev(int noOfDaysMA, int presentDay,float* closePriceColumn);

/**
 * @brief This function calculates the upper bollinger band of a given trading day.
 *  
 * @return float 
 */
float upperBand(int mulFactor,int noOfDaysMA,int presentDay,float* closPriceColumn);

/**
 * @brief This function calculates the lower bollinger band of a given trading day.
 * 
 * @return float 
 */
float lowerBand(int mulFactor,int noOfDaysMA,int presentDay,float* closPriceColumn);

/**
 * @brief This function indicates the buy or sell signals based on the condition consisting of the upperband value,lowerband value and the closing price value.
 * 
 * @return _Bool 
 */
_Bool bollingerBandIndicator(int mulFactor,int noOfDaysMA,int presentDay,float* closePriceColumn,float closePriceOnThatDay);
/**
 * @brief This function executes the bollinger band strategy on requested .csv file of a stock data and display the respective results 
 * 
 * @param filePath 
 */
void boilingerStrategy(char * filePath);

void mfi(char * filePathMFI);

float ema(int days, int crtday, float *columnArray);

_Bool emaCrossover(int em1, int em2, int crtday, float *coloumnArray);

void emaStrategy(char *filePath);

float macd(int fastLength, int slowLength, int crtday, float *columnArray);

_Bool macdCondition(int fastLength, int slowLength, int crtday, float *columnArray);

void macdStrategy(char *filePath);

float rsi(int days, int crtday, float *high, float *low);

/**
 * @brief tells if the 14 days rsi(relative strength index) is overbought or oversold 
 * 
 * @return _Bool
 */
_Bool rsiCrossover( int rs1, int crtday, float *high ,float *low);

/**
 * @brief The function executes the rsi Strategy by considering the user choices 
 * 
 * @param file 
 */
void rsiStrategy(char *filePath);

int WilliamR(char* filepath);

int findLength(char *);   //to find the number of rows in file


#endif
