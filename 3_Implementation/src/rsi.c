#include <header.h>

float rsi(int days, int crtday, float *high,float *low)// days: avg of last n days, crtday: current day, high=array of high,low=array of low)
{
    float total = 0; // formula
    if(crtday<=(high[0]-days)){
     total=100 – [100 / ( 1 + sma(days,crtday,high) / sma(days,crtday,low) ) ) ]
    }
    return (total); //returning relative strength index
}