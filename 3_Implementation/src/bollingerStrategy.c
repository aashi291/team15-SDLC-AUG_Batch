#include "header.h"

void boilingerStrategy(char * filePath)
{
    int bbChoice; // Put a different name for your choice
    int noOfdaysMA=20;// Default value of 20 day moving average and standard deviation
    int mulFactor=2;// Default value of Multiplication factor of standard deviation in calculating the upper and lower bands 
    printf("\nThe values for moving average of close prices and standard deviation as well as multiplication factor of upper and lower bands are required. \n");
    printf("\n1.Default Values\n2.External Input\nPlease enter a choice :");
    scanf("%d",&bbChoice);// asking the user whether to go with default values or will user input the values(eg: 14 for 14 day moving average or 50 for 50 day moving average)
    while (bbChoice!=1 && bbChoice!=2) // checks is the user has inputted any values other than the given menu
    {
        printf("\nPlease Enter a valid choice from the given list of options :");
        scanf("%d",&bbChoice);
    }
    if(bbChoice==2)
    {
        printf("\nEnter the number of days for middle band average and factor for bands calculation(positive whole number): "); 
        scanf("%d%d",&noOfdaysMA,&mulFactor);// you can input different values in here according to your strategy
    }
    
    FILE *file_pointer = fopen(filePath,"r"); // This is to open the .csv file path and assign it to pointer for the further processing

    float *closePriceValues = readColumn(file_pointer,7); // Here is 7 is the close price column in the .csv file which is required for my strategy .. this can be changed according to your strategies

    //bb is prefix for the common variables to differentiate it is for bollinger band strategy.[for other strategies change it according]
    int bbTradeNo = 1;// This indicates the total number of trades that can happen. [eg for wma strategy make as wmaTradeNo]
    float bbBuyp = 0; // This is the price at which the trade can be bought. [follow the above example for your strategies]
    float bbSellp = 0; //This is the price at which the trade can be sold.
    float bbProfitLoss = 0; //This is the profit or loss for a single trade.
    float bbTotalpl = 0;//This the total profit or loss for all trades in a given time period
    float bbTotalProfit = 0;//This the total profit from the all trades in a given time period.
    float bbTotalLoss = 0;//This is the total loss from  the all trades in a given time period.
    float bbProfitFactor = 0;//This is the profit factor using bollinger bands strategy.
    float bbProfitableTrades = 0; //This is the total number of trades which gave profit in a given time period. 
    float bbProfitablePercnt = 0;// This is the percent of trades which gave profit in a given time period.

    _Bool bbIntrade = false; //False means the Trade is in and allowed to buy the stock

    printf("Trade\tStatus\t\tDate\t\t\tPrice\t\tP/L\n\n");
    for (int i=(closePriceValues[0]-noOfdaysMA); i>0; i--)
    {
        float presentDayClosePrice=closePriceValues[i];

        if (bollingerBandIndicator(mulFactor,noOfdaysMA,i, closePriceValues,presentDayClosePrice) && !bbIntrade ){
            char *date = readDate(filePath,i+1);
            bbBuyp=closePriceValues[i];

            printf("%d\tBUY\t\t%s\t\t%0.2f\n", bbTradeNo, date, bbBuyp);
            bbTradeNo++;
            bbIntrade = true;// True means the trade is open and allowed to sell the stock 
        }
        else if (!bollingerBandIndicator(mulFactor,noOfdaysMA,i, closePriceValues,presentDayClosePrice) && bbIntrade){
            char *date = readDate(filePath,i+1);
            bbSellp=closePriceValues[i];

            bbProfitLoss= bbSellp-bbBuyp;
            bbTotalpl += bbProfitLoss;

            bbTotalProfit += ((bbProfitLoss>0)?bbProfitLoss:0);
            bbTotalLoss += abs((bbProfitLoss<0)?bbProfitLoss:0);
            bbProfitableTrades += ((bbProfitLoss>0)?1:0);
            
            printf("\tSELL\t\t%s\t\t%0.2f\t\t%0.2f\n\n", date, bbSellp, bbProfitLoss);
            
            bbIntrade = false;
        }
    }

    bbTotalLoss = (bbTotalLoss==0)?1:bbTotalLoss;
    bbProfitFactor = bbTotalProfit/bbTotalLoss;
    bbProfitablePercnt = (bbProfitableTrades/(bbTradeNo-2))*100;
    printf("\n|| Total Trades: %d ||\t|| Profitable Trades percentage: %0.2f %% ||\t|| Total P/L: %0.2f ||\t|| Profit Factor: %0.3f ||\n\n", (bbTradeNo-2), bbProfitablePercnt,bbTotalpl, bbProfitFactor);

    free(filePath);
    return;

}
