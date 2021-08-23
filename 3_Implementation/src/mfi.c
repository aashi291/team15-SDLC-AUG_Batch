#include "header.h"
 
 void mfi(char * filePath)
 {
     int i;
     FILE *file_pointer = fopen(filePath,"r"); // This is to open the .csv file path and assign it to pointer for the further processing

    float *closePriceValues = readColumn(file_pointer,3); // Here is 3 is the close price column in the .csv file which is required for 
    //float *highPrice = readColumn(file_pointer,3);
    //float *lowPrice = readColumn(file_pointer,4);
    float highRate=0.7;
    //float typicalPrice[383],rawMoney[383];

    float mfi[382]; //an array for calculating and storing the mfi
    float closeP[382];// an array for storing the close price
    char buyDate[382][10];// an array to store the dates of the sales
    int countB=0;// count the buy price
    for(i=1;i<383;i++) // loop to extract the data
    {
        closeP[i-1]=closePriceValues[i];// extracting data from file
        
        //printf("%f\n",closePriceValues[i]);
        
    }
    //free(filePath);

   /* for(i=0;i<382;i++) 
     printf("%f\n",closeP[i]);
    */

    printf("\n\n\n");
   
     
     for (i = 0; i < 382; i++) //calculating MFI
     {
        mfi[i]=(100-(10/3+(closeP[i]/100*highRate))*1.07);
     }
     
     printf("The days in which the stock were over bought are (MFI>80): BUY\n");
    for(i=0;i<382;i++) //displaying the dates in which the stocks were over bought
      {
          //printf("%f\n",mfi[i]);
        if(mfi[i]>85.00)
        {
            char *date = readDate(filePath,i);// storing the date 
            printf("\t%s\t\n", date);//displaying the date
        }

      }

    printf("\n\n\nThe days in which the stock were over sold are (MFI<50): SELL \n");
    for(i=0;i<382;i++) //displaying the dates in which the stocks were over sold
      {
          //printf("%f\n",mfi[i]);
        if(mfi[i]<75.00)
        {
            char *date = readDate(filePath,i);//storing the date 
            printf("\t%s\t\n", date);// displaying the date
        }

      }



 }