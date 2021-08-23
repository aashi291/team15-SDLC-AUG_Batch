#include "Stochastic_header.h"


_Bool Stochastic_crossover( int days,int crtday, float *close,float *HIGH, float *LOW){
    if ((funforK(days, crtday, close, HIGH, LOW) > 80 && funforD(days, crtday, close, HIGH, LOW) > 80 && funforK(days, crtday, close, HIGH, LOW) > funforD(days, crtday, close, HIGH, LOW))){        
        return true;// Indicates SELL
    }
    else if ((funforK(days, crtday, close, HIGH, LOW) < 20 && funforD(days, crtday, close, HIGH, LOW) < 20 && funforK(days, crtday, close, HIGH, LOW) < funforD(days, crtday, close, HIGH, LOW))){
        return false; // Indicates BUY
    }
}

/*compute K and D then 
   If K<20 && D<20 && K<D
    --> BUY
   IF K>80 && D>80 && K>D
    --> SELL */