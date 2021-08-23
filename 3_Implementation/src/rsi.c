#include <header.h>

float rsi(int days, int crtday, float *HIGH,float *LOW)// days: avg of last n days, crtday: current day, high=array of high,low=array of low)
{
    float total = 0; // formula
    if(crtday<=(HIGH[0]-days)){
     total = 100 - (100 / ( 1 + sma(days,crtday,HIGH) / sma(days,crtday,LOW) ) );
    }
    return (total); //returning relative strength index
}
