/**
 * @file WillR.c
 * @author Alna Satheesh (alna.satheesh@ltts.com)
 * @brief fille for the william%R strategy.
 * @version 0.1
 * @date 2021-08-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

char *filePath ;
    float DMA100;
    float WillR;
    

#include "WillR.h"


int WilliamR(char *filePath)
{
    printf("\n %s", filePath);
    int choice, will , dm;
       printf("\nTwo different number of days are required for Williama%%R calculations. \n\n1.Default Values\n2.External Input\nPlease enter a choice :");
    scanf("%d",&choice);
    while ((choice!=1 )&& (choice!=2))
    {
        printf("\nPlease Enter a valid choice from the given list of options :");
        scanf("%d",&choice);
    }
    if(choice==2)
    {
        printf("\nEnter number of days for dma and number of days for william%%R :");
        scanf("%d%d",&dm,&will);
        if((dm<=3 || dm>=500) || WillR<=2 || WillR >=500)
        {
            printf("\nInvalid input. Continuing with default values\n\n");
            will =14;
            dm = 100;
        } 
    }
    if(choice==1)
    {
        will =14;
        dm = 100;
    }

 FILE *file = fopen(filePath,"r");
    if(file == NULL){
            perror("Unable to open the file.");
            return -1;
        }
        float *coloumn1 = readColumn(file,7);

        float *close=NULL,*high= NULL,*low= NULL;

        int length = findLength(filePath);

        close = malloc(length*sizeof(float));
        memcpy(close,coloumn1,length*sizeof(float));

        //printf("close %f" , close[i]);
        
    float *coloumn2 = readColumn(file,3);
        high = malloc(length*sizeof(float));
        memcpy(high,coloumn2,length*sizeof(float));

        
        float *coloumn3 = readColumn(file,4);
        low = malloc(length*sizeof(float));
        memcpy(low,coloumn3,length*sizeof(float));
       
    /*
    tradeNo = number of trades, buyp = buying price, sellp = selling price,
    pl = profit or loss in that trade, totalpl = total profit or loss at the end
    */
    int tradeNo = 0;
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
   printf("Trade\tStatus\t\tDate\t\t\tPrice\t\tP/L\n\n");
    for (int today=(length-dm); today>0; today--)
    {
       
        DMA100 = findDMA(dm , today , close,length);
        WillR = findWillR(dm , will , length,today, close,high ,low);
      
        if (buyCondition(DMA100,WillR,close,today) && !intrade ){
            char *date = readDate(filePath,today+1);
            buyp=close[today];
            tradeNo++;
           printf("%d\tBUY\t\t%s\t\t%0.2f\n", tradeNo, date, buyp);
            
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
            
            printf("\tSELL\t\t%s\t\t%0.2f\t\t%0.2f\n\n", date, sellp, pl);
            
            intrade = false;
          
        }
    }
    
    totalL = (totalL==0)?1:totalL;
    profitFactor = totalP/totalL;
    profitblprcnt = (profitbl/(tradeNo))*100;
    printf("\n|| Total Trades: %d ||\t|| Profitable Trades percentage: %0.2f %% ||\t|| Total P/L: %0.2f ||\t|| Profit Factor: %0.3f ||\n\n", (tradeNo), profitblprcnt, totalpl, profitFactor);
    free(close);
    free(high);
    free(low);
    return 0;
}



float findWillR(int dm, int will,int length ,int today, float *close, float *high , float *low)
{
    
    float highestHigh, lowestLow ; //To store the highest of high for last (14) days and lowest of low for last (14) days

    if(today<=(length-dm)){

     for (int i = today; i<(today+will); i++)
     {
            if(high[i]>highestHigh)
                highestHigh=high[i];
            if(low[i]<lowestLow)
            lowestLow = high[i];
     }
    }
        WillR = ((highestHigh-close[today-1] )/(highestHigh-lowestLow)); //formula for williams%r
  // printf("\nwilliam%%R %f " , WillR*100); 
    return WillR*100;       //return value to be checked for buy or sell

}

float findDMA(int dm , int today , float *close,int length)
{
    
     float sum = 0; // sum of all days price
    if(today<=(length-dm)){
        for (int i = today-5; i<(today+dm+5); i++){
            sum += close[i];
        }
    }
    else{
        return -1;
    }
    //printf(" DMA %f " , sum/dm);
    return (sum/dm); //returning Simple moving average
    
}

bool buyCondition(int DMA100, int WillR, float *close, int i)
{

    if(WillR< 0.5 && close[i]>DMA100)  //conditon to buy 
    return true;
    if(WillR> 0.5|| close[i]<DMA100) //condition to sell
    return false;
return NULL;
}

