#include <header.h>

float macd(int fastLength, int slowLength, int crtday, float *columnArray)
{
    float macdT = 0; 

    if(crtday<=(columnArray[0]-slowLength)){
            macdT = ema(fastLength, crtday, columnArray) - ema(slowLength, crtday, columnArray);
    }
    else{
        return -1;
    }
    return (macdT); 
}

float macdSignal(int fastLength, int slowLength, int signalLength, int crtday, float *columnArray)
{
    float macdS = 0; 
    int multiplier = 2/(signalLength+1);

    if(crtday<=(columnArray[0]-slowLength)){
            macdS = (macd(fastLength, slowLength, crtday, columnArray))*multiplier + sma(signalLength, crtday+1, columnArray )*(1-multiplier);
    }
    else{
        return -1;
    }
    return (macdS); 
}

float macdHistogram(int fastLength, int slowLength, int signalLength, int crtday, float *columnArray)
{
    float histogram = 0;

    if(crtday<=(columnArray[0]-slowLength)){
            histogram = macd(fastLength, slowLength, crtday, columnArray) - macdSignal(fastLength, slowLength, signalLength, crtday, columnArray);
    }
    else{
        return -1;
    }
    return (histogram);
}