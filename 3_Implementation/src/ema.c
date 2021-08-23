#include "header.h"

float ema(int days, int crtday, float *columnArray)// days: avg of last n days, crtday: current day, price: array of coloumnArray till date
{
    float total = 0; // total of all days price
    int multiplier = 2/(days+1);

    if(crtday<=(columnArray[0]-days)){
            total = columnArray[crtday]*multiplier + sma(days, crtday+1, columnArray )*(1-multiplier);
    }
    else{
        return -1;
    }
    return (total); //returning Simple moving average
}