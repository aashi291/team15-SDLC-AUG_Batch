#include "header.h"
#include<math.h>
#include<unistd.h>


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

float upperBand(int mulFactor,int noOfDaysMA,int presentDay,float* closPriceColumn)
{
    float upperBand=0;
    float middleBand=movingMiddleBand(noOfDaysMA,presentDay,closPriceColumn);
    float standardDeviation =stdDev(noOfDaysMA,presentDay,closPriceColumn);
    upperBand = middleBand + mulFactor*standardDeviation;
    return upperBand;
}

float lowerBand(int mulFactor,int noOfDaysMA,int presentDay,float* closPriceColumn)
{
    float lowerBand=0;
    float lmiddleBand=movingMiddleBand(noOfDaysMA,presentDay,closPriceColumn);
    float lstandardDeviation =stdDev(noOfDaysMA,presentDay,closPriceColumn);
    lowerBand = lmiddleBand + mulFactor*lstandardDeviation;
    return lowerBand;
}



