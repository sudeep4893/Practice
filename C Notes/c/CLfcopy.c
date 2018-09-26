#include<stdio.h>
#include<stdlib.h>

/*
Implement File Copy Using CMD LINE ARGS
*/

int main(int argc, char *argv[])
{
    FILE *fp1, *fp2;
    int data;
    
    if(argc != 3)
    {
        printf("\n Wrong number of arguments");
        exit(0);
    }
    
    fp1 = fopen(argv[1], "rb");
    fp2 = fopen(argv[2], "wb");
    
    if(fp1 == NULL || fp2 == NULL)
    {
        printf("\n FILE ACCESS ERROR");
        exit(0);
    }
    
    while((data = fgetc(fp1)) != EOF)
    {
        fputc(data, fp2);
    }
    printf("\n FILE COPIED");
            
    fclose(fp1);
    fclose(fp2);
    return 0;
}
