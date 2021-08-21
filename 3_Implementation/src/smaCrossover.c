#include <header.h>

//takes the coloumn from where sma is to be calculated and the prices
//check crossover of 14 sm1 and 28 sm2
//returns true if 14 sma is above 28 sma and return false if vise-versa
_Bool smaCrossover( int sm1, int sm2, int crtday, float *coloumnArray){
    if ((sma(sm1,(crtday), coloumnArray)>sma(sm2,(crtday), coloumnArray))){        
        return true;
    }
    else if ((sma(sm1,(crtday), coloumnArray)<sma(sm2,(crtday), coloumnArray))){
        return false;
    }
}