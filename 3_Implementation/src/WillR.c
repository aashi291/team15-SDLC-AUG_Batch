/**
 * @file WillR.c
 * @author Alna Satheesh (alna.satheesh@ltts.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

char *filePath = "LTTS.csv";
   // sm1=14;
    int dm=100;
    float DMA100;
    float WillR;
    int will = 14;


#include "WillR.h"


void WilliamR()
{
 FILE *file = fopen(filePath,"r");
    float *close = readColumn(file,7);
    int length = findLength();
    /*
    tradeNo = number of trades, buyp = buying price, sellp = selling price,
    pl = profit or loss in that trade, totalpl = total profit or loss at the end
    */
    int tradeNo = 1;
    float buyp = 0, sellp = 0, pl = 0, totalpl = 0;
    /*
    totalP = total profit made in profitable trades
    totalL = total loss made in loss making trades
    profitFactor = ratio of profit form profitable trades and loss from loss making trades
    profitbl = number of profitable trades
    profitblprcnt = percentage of profitable trades out of total trades
    */
    float totalP = 0, totalL = 0, profitFactor = 0, profitbl = 0, profitblprcnt = 0;

    _Bool intrade = false;
    //printf("Trade\tStatus\t\tDate\t\t\tPrice\t\tP/L\n\n");
    for (int today=(length-dm); today>0; today--)
    {
        DMA100 = findDMA(dm , today , close,length);
        WillR = findWillR(dm, close, today , will,length);

        if (buyCondition(DMA100,WillR,close,today) && !intrade ){
            char *date = readDate(filePath,today+1);
            buyp=close[today];

            //printf("%d\tBUY\t\t%s\t\t%0.2f\n", tradeNo, date, buyp);
            tradeNo++;
            intrade = true;
        }
        else if (!buyCondition(DMA100, WillR,close,today) && intrade){
            char *date = readDate(filePath,today+1);
            sellp=close[today];

            pl = sellp-buyp;
            totalpl += pl;

            totalP += ((pl>0)?pl:0);
            totalL += abs((pl<0)?pl:0);
            profitbl += ((pl>0)?1:0);
            
            //printf("\tSELL\t\t%s\t\t%0.2f\t\t%0.2f\n\n", date, sellp, pl);
            
            intrade = false;
        }
    }

    totalL = (totalL==0)?1:totalL;
    profitFactor = totalP/totalL;
    profitblprcnt = (profitbl/(tradeNo-2))*100;
    //printf("\n|| Total Trades: %d ||\t|| Profitable Trades percentage: %0.2f %% ||\t|| Total P/L: %0.2f ||\t|| Profit Factor: %0.3f ||\n\n", (tradeNo-2), profitblprcnt, totalpl, profitFactor);

}


int findWillR(int dm,float *close,int today, int will,int length)
{
    
    float highestHigh, lowestLow ; 
    FILE *fileptr = fopen(filePath,"r");
    float *high = readColumn(fileptr,4);
    float *low = readColumn(fileptr,5);
     //float sum = 0; // sum of all days price
    if(today<=(length-dm)){
       // printf("\nwillr");
        highestHigh=high[today];
       // printf("hightoday %f " , high[today]);
        lowestLow=low[today];
        //printf("lowtoday %f " , low[today]);
        for (int i = today; i<(today+will); i++){
            if(high[i]>highestHigh)
                highestHigh=high[i];
            if(low[i]<lowestLow)
                lowestLow=low[i];
        }
   // printf("highest %f " ,highestHigh);
   // printf("lowest %f " ,lowestLow);
  //  printf("close %f\n " ,close);
    fclose(fileptr);

WillR = ((highestHigh-close[today-1] )/(highestHigh-lowestLow));
//printf("\nwilliam\%R %f" , WillR);
return WillR;
    } 
}

float findDMA(int dm , int today , float *close,int length)
{
    
     float sum = 0; // sum of all days price
    if(today<=(length-dm)){
       // printf("\ndma entered");
        for (int i = today; i<(today+dm); i++){
            sum += close[i];
        }
    }
    else{
        return -1;
    }
    //printf("%f Dma" , sum/dm);
    return (sum/dm); //returning Simple moving average
    
}

bool buyCondition(int DMA100, int WillR, float *close, int i)
{

    if(WillR>50 && close[i]>DMA100)
    return true;
    if(WillR<50 || close[i]<DMA100)
    return false;
}

int findLength()
{
    FILE *fp;
    int count = 0;  // Line counter (result)
    
    char c;  // To store a character read from file
  
    // Open the file
    fp = fopen(filePath, "r");
  
    // Check if file exists
    if (fp == NULL)
    {
        printf("Could not open file %s", filePath );
        return 0;
    }
  
    // Extract characters from file and store in character c
    for (c = getc(fp); c != EOF; c = getc(fp))
        if (c == '\n') // Increment count if this character is newline
            count = count + 1;
  
    // Close the file
    fclose(fp);
  
  
    return count-1;
}
