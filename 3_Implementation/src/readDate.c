#include <header.h>

//fl is the path of csv file and n is the row of which date is required
//returns the requested date
char *readDate(char *fl, int n){

    FILE *file_p = fopen(fl,"r"); // initialize file pointer
    
    static char fc[1024];
    //Again check if the file is empty or wrong file name
    if(file_p == NULL){
            perror("Unable to open the file.");
            return 0;
        }

    char line[1024];//to store data read from csv file as a string
    int row_count = 0;//count number of rows
    int col_count = 0;//count number of coloumns

    while(fgets(line, sizeof(line), file_p)){
        col_count = 0;//make coloumn 0 after each loop
        row_count++;//append row

        //char *l[] = 
        char *field = strtok(line,",\"");//seperate each coloumn one by one
        
        //loop until coloumn completes
        while(field != NULL){
            //check is it a coloumn of date
            if(col_count == 0 && row_count == n){
                fclose(file_p);

                for(int i=0; i<11;i++){
                    fc[i] = field[i];
                }
                return fc;//return date
            }
            field = strtok(NULL,",\"");//mobe to next coloumn
            col_count++;//append coloumn
        }    
    }
    fclose(file_p);//close file
    return "0";   
}