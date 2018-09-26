#include<stdio.h>
#include<stdlib.h>

// cal file length

int main()
{
    FILE *fp;
    char str[30];
    int x;
    
    printf("\n enter file name ");
    gets(str);
    
    //open file for reading
    fp = fopen(str, "r");

    //test file open status
    if(fp == NULL)
    {
        printf("\n file does not exist");
        exit(0);//terminate the program
    }

    //cal file length
    //seek 0 offset from end of file
    fseek(fp, 0, SEEK_END);
    
    //find the file pointer position
    x = ftell(fp);
    
    printf("\n File is %d bytes in length ", x);
    //close the file
    fclose(fp);
    return 0;
}