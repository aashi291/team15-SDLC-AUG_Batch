#include "header.h"
#include<math.h>
#include<unistd.h>
/**
 * @brief This function calculates the moving aveage for middle band
 * 
 * @param noOfDaysMA this is the number of days moving average(eg. 20 for 20 day moving average)
 * @param presentDay this is the particular date on which the moving average is calculated by considering the previous 20 days closing prices.
 * @param closePriceColumn this is the pointer one dimensional array consisting of the close price values
 * @return float 
 */

float movingMiddleBand(int noOfDaysMA, int presentDay,float* closePriceColumn)
{
    float movingSum=0;
    if(presentDay<=(closePriceColumn[0]-noOfDaysMA)){
        for (int i = presentDay; i<(presentDay+noOfDaysMA); i++){
            movingSum += closePriceColumn[i];
        }
    }
    else{
        return -1;
    }
    return (movingSum/noOfDaysMA); //returning Simple moving average

}
/**
 * @brief This function calculates the standard deviation from the moving average
 * 
 * @param noOfDaysMA this is the number of days moving average(eg. 20 for 20 day moving average)
 * @param presentDay this is the particular date on which the standard deviation is calculated by considering the previous 20 days closing prices.
 * @param closePriceColumn this is the pointer to an one dimensional array consisting of the close price values
 * @return float 
 */

float stdDev(int noOfDaysMA, int presentDay,float* closePriceColumn)
{
    float mean=movingMiddleBand(noOfDaysMA,presentDay,closePriceColumn);
    float diffMean=0;
    if(mean==-1)
     {
        return -1;
    }
    else
    {
        for (int i = presentDay; i<(presentDay+noOfDaysMA); i++)
        {
            diffMean += pow(mean-closePriceColumn[i],2);
        }
        float variance = diffMean/noOfDaysMA;
	    return sqrt(variance);
    }
}
/**
 * @brief This function calculates the upper band of bollinger bands considering the moving average and moving standard deviation.
 * 
 * @param mulFactor this is the factor to be multiplied with the standard deviation according to upperband formula
 * @param noOfDaysMA this is the number of days moving average(eg. 20 for 20 day moving average)
 * @param presentDay this is the particular date on which the upper band is calculated by considering the previous 20 days closing prices.
 * @param closePriceColumn this is the pointer to an one dimensional array consisting of the close price values
 * @return float 
 */
float upperBand(int mulFactor,int noOfDaysMA,int presentDay,float* closPriceColumn)
{
    float upperBand=0;
    float middleBand=movingMiddleBand(noOfDaysMA,presentDay,closPriceColumn);
    float standardDeviation =stdDev(noOfDaysMA,presentDay,closPriceColumn);
    upperBand = middleBand + mulFactor*standardDeviation;
    return upperBand;
}
/**
 * @brief This function calculates the lower band of bollinger bands considering the moving average and moving standard deviation
 * 
 * @param mulFactor this is the factor to be multiplied with the standard deviation according to lowerband formula
 * @param noOfDaysMA this is the number of days moving average(eg. 20 for 20 day moving average)
 * @param presentDay this is the particular date on which the lower band is calculated by considering the previous 20 days closing prices.
 * @param closePriceColumn this is the pointer to an one dimensional array consisting of the close price values
 * @return float 
 */
float lowerBand(int mulFactor,int noOfDaysMA,int presentDay,float* closPriceColumn)
{
    float lowerBand=0;
    float lmiddleBand=movingMiddleBand(noOfDaysMA,presentDay,closPriceColumn);
    float lstandardDeviation =stdDev(noOfDaysMA,presentDay,closPriceColumn);
    lowerBand = lmiddleBand + mulFactor*lstandardDeviation;
    return lowerBand;
}



