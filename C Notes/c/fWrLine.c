#include<stdio.h>
#include<stdlib.h>

// Write data (in append mode) into the file.

int main()
{
    FILE *fp;
    char data[80];
    int flag;
    
    //open file for writing in append mode
    fp = fopen("d:/a.txt", "a");

    //test file open status
    if(fp == NULL)
    {
        printf("\n file open failed");
        exit(0);//terminate the program
    }

    printf("\n write data into file ");
    printf("\n write stop to save and exit \n");
    
    flag = 1;
    do
    {
        gets(data);
        if(strcmp(data, "stop") == 0)
          flag = 0;
        else
        {
          fputs(data, fp);
          fputs("\n", fp);
        }
    }while(flag == 1);
    
    //writing done, close the file
    fclose(fp);
    return 0;
}