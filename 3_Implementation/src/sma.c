#include <header.h>

float sma(int days, int crtday, float *columnArray)// days: avg of last n days, crtday: current day, price: array of coloumnArray till date
{
    float sum = 0; // sum of all days price
    if(crtday<=(columnArray[0]-days)){
        for (int i = crtday; i<(crtday+days); i++){
            sum += columnArray[i];
        }
    }
    else{
        return -1;
    }
    return ((sum)/days); //returning Simple moving average
}