/* #include "header.h"
 
 void mfi(char * filePathMFI)
 {
     int i;
     FILE *file_pointer = fopen(filePathMFI,"r"); // This is to open the .csv file path and assign it to pointer for the further processing

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

  // /* for(i=0;i<382;i++) 
    // printf("%f\n",closeP[i]);
    //

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
            char *date = readDate(filePathMFI,i);// storing the date 
            printf("\t%s\t\n", date);//displaying the date
        }

      }

    printf("\n\n\nThe days in which the stock were over sold are (MFI<50): SELL \n");
    for(i=0;i<382;i++) //displaying the dates in which the stocks were over sold
      {
          //printf("%f\n",mfi[i]);
        if(mfi[i]<75.00)
        {
            char *date = readDate(filePathMFI,i);//storing the date 
            printf("\t%s\t\n", date);// displaying the date
        }

      }



 }   



------------------------------------------------current mfi*/


 #include "header.h"
 
 void mfi(char * filePathMFI)
 {
     int i;
     FILE *file_pointer = fopen(filePathMFI,"r"); // This is to open the .csv file path and assign it to pointer for the further processing
    

    float *closePriceValues = readColumn(file_pointer,7); // Here is 3 is the close price column in the .csv file which is required for 
    //float *highPrice = readColumn(file_pointer1,3);
    //float *lowPrice = readColumn(file_pointer2,4);
    
    float highRate=0.7;
    //float typicalPrice[383],rawMoney[383];

    //float mfi[382]; //an array for calculating and storing the mfi
    
    float closeP[382];// an array for storing the close price
    float lowP[382];
    float highP[382];
    float volumeP[382];
    float typicalPrice[382];
    float rawMoney[382];
    float up_down[381];
    float positive14[367];
    float negetive14[367];
    float mfr[367];
    float mfi[367];

    char buyDate[382][10];// an array to store the dates of the sales
    int countB=0;// count the buy price

    for(i=1;i<383;i++) // loop to extract the data
    {
        closeP[382-i]=closePriceValues[i];// extracting data from file   i-1
        //highP[i-1]=highPrice[i];
        //lowP[i-1]=lowPrice[i];
        //printf("%f\n",closePriceValues[i]);
        
    }
    //free(filePath);

     /* for(i=0;i<382;i++) // loop to extract the data
    {
        printf("%f\n",closeP[i]);
    }*/

    
   
     /*   fake mfi
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
            char *date = readDate(filePathMFI,i);// storing the date 
            printf("\t%s\t\n", date);//displaying the date
        }

      }

    printf("\n\n\nThe days in which the stock were over sold are (MFI<50): SELL \n");
    for(i=0;i<382;i++) //displaying the dates in which the stocks were over sold
      {
          //printf("%f\n",mfi[i]);
        if(mfi[i]<75.00)
        {
            char *date = readDate(filePathMFI,i);//storing the date 
            printf("\t%s\t\n", date);// displaying the date
        }

      }
       edn of mfi */ 


      /*
        
      // reading 2nd col
      FILE *file_pointer1 = fopen(filePathMFI,"r"); // This is to open the .csv file path and assign it to pointer for the further processing
 
    float *lowPrice = readColumn(file_pointer1,7);
      //float *lowPrice = readColumn(filePathMFI,4);

      for(i=1;i<383;i++) // loop to extract the data
    {
        lowP[i-1]=lowPrice[i];// extracting data from file
        
        //printf("%f\n",closePriceValues[i]);  
    }
    
    for(i=0;i<382;i++) 
      printf("%f\n",lowP[i]);
      */

       FILE *file_pointer1 = fopen(filePathMFI,"r");
       //FILE *file_pointer2 = fopen(filePathMFI,"r");
       float *highPrice = readColumn(file_pointer1,3);

       for(i=1;i<383;i++) // loop to extract the data
    {
        //closeP[i-1]=closePriceValues[i];// extracting data from file
        highP[382-i]=highPrice[i];
        //lowP[i-1]=lowPrice[i];
        //printf("%f\n",closePriceValues[i]);
        
    }
    //free(filePath);
    
     printf("\n\n\n");
      //FILE *file_pointer1 = fopen(filePathMFI,"r");
       FILE *file_pointer2 = fopen(filePathMFI,"r");
       float *lowPrice = readColumn(file_pointer2,4);

       for(i=1;i<383;i++) // loop to extract the data
    {
        //closeP[i-1]=closePriceValues[i];// extracting data from file
        //highP[i-1]=highPrice[i];
        lowP[382-i]=lowPrice[i];
        //printf("%f\n",closePriceValues[i]);
        
    }
    //free(filePath);

    

       FILE *file_pointer3 = fopen(filePathMFI,"r");
       float *volume = readColumn(file_pointer3,11);

       for(i=1;i<383;i++) // loop to extract the data
    {
        //closeP[i-1]=closePriceValues[i];// extracting data from file
        //highP[i-1]=highPrice[i];
        volumeP[382-i]=volume[i];
        //printf("%f\n",closePriceValues[i]);
        
    }



     for(i=0;i<382;i++)
     {
        typicalPrice[i]=(highP[i]+lowP[i]+closeP[i])/3.0;
     }

       
     for(i=0;i<382;i++)
     {
        rawMoney[i]=typicalPrice[i]*volumeP[i];

     } 

     


      for(i=1;i<382;i++)
      {
        if(typicalPrice[i]>typicalPrice[i-1])
            up_down[i-1]=1;
        else 
            up_down[i-1]=0;    
      }


      //for(i=0;i<381;i++) 
        // printf("%f\n",up_down[i]);

       int count=0;
       float sum=0; 
      for(i=14;i<382;i++)
      {
        for(int j=i-13;j<i+1;j++)
        {
          if(up_down[j-1]==1)
          {
              sum=sum+rawMoney[j];
          }
        }
        positive14[count]=sum;
        sum=0;
        count++;
      }
   

       count=0;
        sum=0; 
      for(i=14;i<382;i++)
      {
        for(int j=i-13;j<i+1;j++)
        {
          if(up_down[j-1]==0)
          {
              sum=sum+rawMoney[j];
          }
        }
        negetive14[count]=sum;
        sum=0;
        count++;
      }



    //for(i=0;i<367;i++) 
      //   printf("%f\n",negetive14[i]);


     for(i=0;i<367;i++)
     {
       mfr[i]=positive14[i]/negetive14[i];
     } 

      //for(i=0;i<367;i++) 
        // printf("%f\n",mfr[i]);

     for(i=0;i<367;i++)
     {
       mfi[i]=(100-(100/1+mfr[i]))*-1;
     } 

     //for(i=0;i<367;i++) 
       // printf("%f\n",mfi[i]);

     printf("The days in which the stock were over sold are (MFI<20): SELL\n"); 
     for(i=0;i<367;i++)
     {
       if(mfi[i]>7.00)
        {
            char *date = readDate(filePathMFI,i+14);// storing the date 
            printf("\t%s\t\tSELL\t\tProfit: %f %% \n", date,((highP[i+14]-lowP[i+14])/lowP[i+14])*100);//displaying the date
        }
     }   

      printf("\n\n\n");

      printf("The days in which the stock were over bought are (MFI>80): BUY\n");
      for(i=0;i<367;i++)
     {
       if(mfi[i]<0.20)
        {
            char *date = readDate(filePathMFI,i+14);// storing the date 
            printf("\t%s\t\tBUY\t\tProfit: %f %% \n", date,((highP[i+14]-lowP[i+14])/lowP[i+14])*100);
        }
     }
 }
