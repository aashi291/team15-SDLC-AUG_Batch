#include <header.h>

float *readColumn(FILE *file_p, int column){
    
    char line[1024];//to store data read from csv file as a string
    int row_count = 0;//count number of rows
    int col_count = 0;//count number of coloumns
    static float columnArray[1024];//to store the price from required row
    int i = 0;

    //Again check if the file is empty or wrong file name
    if(file_p == NULL){
        perror("Unable to open the file.");
        return 0;
    }

    while(fgets(line, sizeof(line), file_p)){
        col_count = 0;//make coloumn 0 after each loop
        row_count++;//append row

        char* field = strtok(line,"\"");//seperate each coloumn one by one
        //loop until coloumn completes
        while(field != NULL){
        
        //check for element with only a comma ","
        char chkcomma[sizeof(field)];
        strncpy(chkcomma,field,sizeof(field));

        //to ignore element with only a comma ","
        if(chkcomma[0] == ','){
            col_count--;
        }

        //check if coloumn is coloumn of closing price and store it in cls
        if(col_count == column){
            
            //remove comma  "," between the price to change it into integer
            for (int j=0;j<sizeof(field);j++){
               if(chkcomma[j]==','){
                   for (int k=j;k<sizeof(field);k++){
                       chkcomma[k]=chkcomma[k+1];
                   }
               }
           }
            
            columnArray[i] =  atof(chkcomma);//store the price into a seperate array
            col_count++;
            i++;
        }
        field = strtok(NULL,"\"");
        col_count++;
        }
        
    }
    
    columnArray[0] = i;
    fclose(file_p);
    return columnArray;   
}