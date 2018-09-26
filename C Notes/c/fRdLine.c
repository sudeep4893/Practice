#include<stdio.h>
#include<stdlib.h>
//reading a file line by line
int main()
{
    FILE *fp;
    char line[80];
    int x;
    
    fp = fopen("d:/aaa.txt", "r");
    
    if(fp == NULL)
    {
        printf("\n File open failed");
        exit(0);//terminate the program
    }

    //read the file, line by line
    while( fgets(line, 79, fp))
    {
        printf("%s", line);        
    }
    
    //reading done, close the file
    fclose(fp);
    scanf("%d",&x);
    return 0;
}
