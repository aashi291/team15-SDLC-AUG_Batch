#include "header.h"
#include <stdio.h>

void main()
{
    FILE *file1 = fopen("LTTS.csv","r");
    float *close = readColumn(file1 , 7);
    //printf("%f",close[0]);
     for(int i=1 ;i< 300;i++)
    printf("%f close \n" , close[i]);
    FILE *file2 = fopen("LTTS.csv","r");
    float *high = readColumn(file2 , 4);
    FILE *file3 = fopen("LTTS.csv","r");
    float *low = readColumn(file3 , 5);
    for(int i=1 ;i< close[0];i++)
    {
    printf("%f high " , high[i]);
    printf("%f low \n" , low[i]);
    }
    
}