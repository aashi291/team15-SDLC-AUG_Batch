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

    smaStrategy(filePath);
}