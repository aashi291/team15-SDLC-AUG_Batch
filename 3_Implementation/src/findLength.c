#include "header.h"


int findLength(char *filePath)
{
    int count = 0;  // Line counter (result)
    
    char c;  // To store a character read from file
  
    // Open the file
    FILE *fp = fopen(filePath, "r");
  
    // Check if file exists
    if (fp == NULL)
    {
        printf("Could not open file %s", filePath );
        return 0;
    }
  
    // Extract characters from file and store in character c
    for (c = getc(fp); c != EOF; c = getc(fp))
        if (c == '\n') // Increment count if this character is newline
            count = count + 1;
  
    
    fclose(fp);     // Close the file
  
  
    return count-1;
}
