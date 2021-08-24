#include <header.h>

float wma(int days, int crtday, float *coloumnArray)// days: avg of last n days, crtday: current day, price: array of coloumnArray till date
{
    float sum = 0;// sum of all days price
    int D;
    
    D = days*(days+1)/2;
    if(crtday<=(coloumnArray[0]-days)){
        for (int i = crtday; i<(crtday+days); i++){
            sum += coloumnArray[i] * days/D;
            days--;
        }
        
    }
    else{
        return -1;
    }
    return (sum); //returning Weighted moving average
}