#include "header.h"

float roc(int n, int todaysClosingprice, float *coloumnArray)
{

   float value; 
   int i;
    if(todaysClosingprice<=(coloumnArray[0]-n)){
        
        value = (coloumnArray[i] - coloumnArray[i+n])/coloumnArray[i+n];
        
    }
    else{
        return -1;
    }
    return value*100;
}    