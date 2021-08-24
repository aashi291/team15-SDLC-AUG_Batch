#include <header.h>
#include <unistd.h>

void rsiStrategy(char *filePath){

    int choice;
    int rs1 = 14; //put the inputs u want for your indicator

    printf("\nTwo different number of days are required for relative strength index calculations. \n\n1.Default Values\n2.External Input\nPlease enter a choice :");
    scanf("%d",&choice);
    while (choice!=1 && choice!=2)
    {
        printf("\nPlease Enter a valid choice from the given list of options :");
        scanf("%d",&choice);
    }
    if(choice==2)
    {
        printf("\nEnter two different number of days for relative strength index :");
        scanf("%d",&rs1);

    }

    FILE *file = fopen(filePath,"r");
    float *close = readColumn(file,7);
    //float *HIGH = readColumn(file,3); // Accessing HIGH column from .csv file
    //float *LOW = readColumn(file,4); // Accessing LOW column from .csv file
    FILE *file_pointer1 = fopen(filePath,"r");
       //FILE *file_pointer2 = fopen(filePath,"r");
       float *HIGH = readColumn(file_pointer1,3);
    FILE *file_pointer2 = fopen(filePath,"r");
       //FILE *file_pointer2 = fopen(filePath,"r");
       float *LOW = readColumn(file_pointer2,4);



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
    for (int i=(close[0]-rs1); i>0; i--)
    {

        if (rsiCrossover(rs1, i, HIGH, LOW) && !intrade ){
            char *date = readDate(filePath,i+1);
            buyp=close[i];

            tradeNo++;
            printf("%d\tBUY\t\t%s\t\t%0.2f\n", tradeNo, date, buyp);

            intrade = true;
        }
        else if (!rsiCrossover(rs1, i, HIGH, LOW) && intrade){
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
    printf("\n|| Total Trades: %d ||\t|| Profitable Trades percentage: %0.2f ||\t|| Total P/L: %0.2f ||\t|| Profit Factor: %0.3f ||\n\n", (tradeNo), profitblprcnt, totalpl, profitFactor);

}

//takes the coloumn from where rsi is to be calculated and the prices
//check crossover of 14 rs1 and external input
//returns true if rsi<30 which is oversell and return false if rsi>70 which is overbought 
_Bool rsiCrossover( int rs1, int crtday, float *HIGH, float *LOW){
    if ((rsi(rs1,(crtday), HIGH, LOW )>70)){        
        return false;
    }
    else if ((rsi(rs1,(crtday), HIGH, LOW )<30)){
        return true;
    }
}
