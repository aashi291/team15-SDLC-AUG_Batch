#include "header.h"
/**
 * @brief This is the function that indicates whether we need to buy or sell based on the bollinger bands conditions
 * 
 * @param mulFactor This multiplication factor is required according to the bollinger bands formula
 * @param noOfDaysMA This is the number of days moving average/moving standard deviation(eg. 20 for 20 day moving average or 14 for 14 day moving average)
 * @param presentDay This is particular date on which the buy or sell signal evaulation is required
 * @param closePriceColumn This is the pointer to one dimensional array of close price values
 * @param closePriceOnThatDay This is the closing price on that particular date(here it is mentioned as presentDay)
 * @return _Bool 
 */
_Bool bollingerBandIndicator(int mulFactor,int noOfDaysMA,int presentDay,float* closePriceColumn,float closePriceOnThatDay){
    if (lowerBand(mulFactor,noOfDaysMA,presentDay,closePriceColumn)> closePriceOnThatDay){        
        return true;// This is a BUY indication
    }
    else if (upperBand(mulFactor,noOfDaysMA,presentDay,closePriceColumn)< closePriceOnThatDay){
        return false;// This is a SELL indication
    }
}