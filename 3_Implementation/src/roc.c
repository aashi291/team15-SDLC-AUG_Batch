#include "header.h"

float roc(int n, int todaysClosingprice, float *coloumnArray)
{

   float value=0; 
    if(todaysClosingprice<=(coloumnArray[0]-n)){
        
        value = (coloumnArray[todaysClosingprice] - coloumnArray[todaysClosingprice+n])/coloumnArray[todaysClosingprice+n];
        
    }
    else{
        return -1;
    }
    return value*100;
}    