#include "header.h"
#include "unistd.h"

void emaStrategy(char *filePath){

    int choice;
    int em1 = 14; //put the inputs u want for your indicator
    int em2 = 28; //put the inputs u want for your indicator

    printf("\nTwo different number of days are required for exponential moving average calculations. \n\n1.Default Values\n2.External Input\nPlease enter a choice :");
    scanf("%d",&choice);
    while (choice!=1 && choice!=2)
    {
        printf("\nPlease Enter a valid choice from the given list of options :");
        scanf("%d",&choice);
    }
    if(choice==2)
    {
        printf("\nEnter two different number of days for exponential moving average :");
        scanf("%d%d",&em1,&em2);

        while(em1>em2)
        {
            printf("\nEnter the lower number of days first and then the higher number of days: ");
            scanf("%d%d",&em1,&em2);
        }
    }

    FILE *file = fopen(filePath,"r");
    float *close = readColumn(file,7);
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
    for (int i=(close[0]-em2); i>0; i--)
    {

        if (emaCrossover(em1, em2, i, close) && !intrade ){
            char *date = readDate(filePath,i+1);
            buyp=close[i];

            tradeNo++;
            printf("%d\tBUY\t\t%s\t\t%0.2f\n", tradeNo, date, buyp);

            intrade = true;
        }
        else if (!emaCrossover(em1, em2, i, close) && intrade){
            char *date = readDate(filePath,i+1);
            sellp=close[i];

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

}

//takes the coloumn from where ema is to be calculated and the prices
//check crossover of 14 em1 and 28 em2
//returns true if 14 ema is above 28 ema and return false if vice-versa
_Bool emaCrossover(int em1, int em2, int crtday, float *coloumnArray){
    if ((ema(em1,(crtday), coloumnArray)>ema(em2,(crtday), coloumnArray))){        
        return true;
    }
    else if ((ema(em1,(crtday), coloumnArray)<ema(em2,(crtday), coloumnArray))){
        return false;
    }
}
