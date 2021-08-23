#include "Stochastic_header.h"



float Stochastic(int days, int crtday, float *close,float *HIGH, float *LOW)// days: avg of last n days, crtday: current day, price: array of coloumnArray till date
{
   /* 
    float sum1 = 0,sum2 = 0,sum3 = 0; // sum of all days price
    if(crtday<=(close[0]-days)){
        for (int i = crtday; i<(crtday+days); i++){
            sum1 += close[i];
            sum2 += HIGH[i];
            sum3 += LOW[i];
        }
    
    */
   float kv,dv;
    kv=funforK(days, crtday, close, HIGH,  LOW);
    dv=funforD(days, crtday, close, HIGH,  LOW);
   
}
    
        




float funforK(int days,int crtday, float *close, float *HIGH, float *LOW)
{
    float K;
    float sum1 = 0,sum2 = 0,sum3 = 0; // sum of all days price
    if(crtday<=(close[0]-days)){
        for (int i = crtday; i<(crtday+days); i++){
            sum1 += close[i];
            sum2 += HIGH[i];
            sum3 += LOW[i];
        }
    }
    K = ((sum1-sum3)/(sum2-sum3))*100;
    return K;

}
 float funforD(int days,int crtday, float *close, float *HIGH, float *LOW)
 {
     float Kval;
     float D;
     
     Kval = funforK(days,crtday, close, HIGH,  LOW);
     D = 3 - Kval;

     return D;

 }
 
 /*

 K =((close(14 days) - Low(14 days)) / (HIGH(14 days) - LOW(14 days)))*100

 D = 3-K
 
 
 
  compute K and D then 
   If K<20 && D<20 && K<D
    --> BUY
   IF K>80 && D>80 && K>D
    --> SELL

    */
 
 
 
 
 
 
 
 
 
 
 
 
 
