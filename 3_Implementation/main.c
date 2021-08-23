#include <header.h>
#include <unistd.h>

int main(){
    int sm1 = 14, sm2 = 28; //sma 14 sma 28
    
    printf("\n\t\t\t* Please use the .csv files in \"3_Implementation\" folder *\n");
    printf("\t\t\t\t\t\tOR\n");
    printf("* Download .csv file of any share of your choice from \"nseindia.com\" in \"3_Implementation\" folder *\n\n");
    printf("Write the name of file as \"File Name\".csv : ");

    /* SHOULD BE USED WHILE USING scanf*/
    char *filePath;
    filePath = malloc(256);
    filePath[255] = '\0';
    scanf("%255s", filePath);//take input of file name
    //check it valid file name is given 
    while(access(filePath,R_OK) != 0){
        printf("\nUnable to open the file !!!!\nPlease check the file name !!!!!\n");
        printf("Write the name of file as \"File Name\".csv : ");
        scanf("%255s", filePath);
    }
    
    //char *filePath = "LTTS.csv";//to store file path, comment this while using scanf
    //printf("%s\n\n",filePath);//comment this while using scanf

    FILE *file = fopen(filePath,"r");

    int strategyChoice; // this selects a particular strategy from a given list to be processed
    printf("\nSelect a strategy from the given options\n\n1.Simple Moving Average\n2.Bollinger Bands\n3.MFI\n\nEnter your choice: "); // update your strategy in the menu
    scanf("%d",&strategyChoice);
    while(strategyChoice!=1 && strategyChoice!=2&& strategyChoice!=3) // update your respective strategy choice here as well
    {
        printf("\nInvalid choice!\nPlease Enter a valid choice from the above given options only : ");
        scanf("%d",&strategyChoice);
    }

    switch(strategyChoice)
    {
        case 1: smaStrategy(filePath);
                break;
        case 2: boilingerStrategy(filePath); // add further cases in your switch statement for respective strategies
                break;
        case 3: mfi(filePath);
                break;
        
    }
    

    printf("\nThe Performance of the strategies on historical data is just a probable indication but final decision of Trade is subject to personal discretion!!");
   
    return 0;
}