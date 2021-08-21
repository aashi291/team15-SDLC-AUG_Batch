#include <header.h>

float sma(int days, int crtday, float *coloumnArray)// days: avg of last n days, crtday: current day, price: array of coloumnArray till date
{
    float sum = 0; // sum of all days price
    if(crtday<=(coloumnArray[0]-days)){
        for (int i = crtday; i<(crtday+days); i++){
            sum += coloumnArray[i];
        }
    }
    else{
        return -1;
    }
    return (sum/days); //returning Simple moving average
}