#include "header.h"

_Bool bollingerBandIndicator(int mulFactor,int noOfDaysMA,int presentDay,float* closePriceColumn,float closePriceOnThatDay){
    if (lowerBand(mulFactor,noOfDaysMA,presentDay,closePriceColumn)> closePriceOnThatDay){        
        return true;
    }
    else if (upperBand(mulFactor,noOfDaysMA,presentDay,closePriceColumn)< closePriceOnThatDay){
        return false;
    }
}