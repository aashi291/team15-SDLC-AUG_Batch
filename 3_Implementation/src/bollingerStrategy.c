#include "header.h"

void boilingerStrategy(char * filePath)
{
    int bbChoice; 
    int noOfdaysMA=20;// Default value of 20 day moving average and standard deviation
    int mulFactor=2;// Default value of Multiplication factor of standard deviation in calculating the upper and lower bands 
    printf("\nThe values for moving average of close prices and standard deviation as well as multiplication factor of upper and lower bands are required. \n");
    printf("\n1.Default Values\n2.External Input\nPlease enter a choice :");
    scanf("%d",&bbChoice);
    while (bbChoice!=1 && bbChoice!=2)
    {
        printf("\nPlease Enter a valid choice from the given list of options :");
        scanf("%d",&bbChoice);
    }
    if(bbChoice==2)
    {
        printf("\nEnter the number of days for middle band average and factor for bands calculation(positive whole number): ");
        scanf("%d%d",&noOfdaysMA,&mulFactor);
    }
    
    FILE *file_pointer = fopen(filePath,"r");

    float *closePriceValues = readColumn(file_pointer,7);

    int bbTradeNo = 1, bbBuyp = 0, bbSellp = 0, bbProfitLoss = 0, bbTotalpl = 0;
    float bbTotalProfit = 0, bbTotalLoss = 0, bbProfitFactor = 0, bbProfitableTrades = 0, bbProfitablePercnt = 0;

    _Bool bbIntrade = false; //False means the Trade is in close and allowed to buy the stock

    printf("Trade\tStatus\t\tDate\t\t\tPrice\t\tP/L\n\n");
    for (int i=(closePriceValues[0]-noOfdaysMA); i>0; i--)
    {
        float presentDayClosePrice=closePriceValues[i];

        if (bollingerBandIndicator(mulFactor,noOfdaysMA,i, closePriceValues,presentDayClosePrice) && !bbIntrade ){
            char *date = readDate(filePath,i+1);
            bbBuyp=closePriceValues[i];

            printf("%d\tBUY\t\t%s\t\t%d\n", bbTradeNo, date, bbBuyp);
            bbTradeNo++;
            bbIntrade = true;
        }
        else if (!bollingerBandIndicator(mulFactor,noOfdaysMA,i, closePriceValues,presentDayClosePrice) && bbIntrade){
            char *date = readDate(filePath,i+1);
            bbSellp=closePriceValues[i];

            bbProfitLoss= bbSellp-bbBuyp;
            bbTotalpl += bbProfitLoss;

            bbTotalProfit += ((bbProfitLoss>0)?bbProfitLoss:0);
            bbTotalLoss += abs((bbProfitLoss<0)?bbProfitLoss:0);
            bbProfitableTrades += ((bbProfitLoss>0)?1:0);
            
            printf("\tSELL\t\t%s\t\t%d\t\t%d\n\n", date, bbSellp, bbProfitLoss);
            
            bbIntrade = false;
        }
    }

    bbTotalLoss = (bbTotalLoss==0)?1:bbTotalLoss;
    bbProfitFactor = bbTotalProfit/bbTotalLoss;
    bbProfitablePercnt = (bbProfitableTrades/(bbTradeNo-2))*100;
    printf("\n|| Total Trades: %d ||\t|| Profitable Trades percentage: %0.2f %% ||\t|| Total P/L: %d ||\t|| Profit Factor: %0.3f ||\n\n", (bbTradeNo-1), bbProfitablePercnt,bbTotalpl, bbProfitFactor);

    free(filePath);
    return;

}
