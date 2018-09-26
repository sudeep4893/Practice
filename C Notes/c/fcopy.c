#include<stdio.h>
#include<stdlib.h>
//Copy a file
//(We use binary mode to allow copying of all file types)

int main()
{
    char str1[30], str2[30];
    FILE *fp1, *fp2;
    int x;
    
    printf("\n enter source file ");
    gets(str1); //used for scanning strings with intermediate spaces
    printf("\n enter target file ");
    fflush(stdin);
    gets(str2); //used for scanning strings with intermediate spaces

    
    //open source file for reading
    fp1 = fopen(str1, "rb");
    //open target file for writing
    fp2 = fopen(str2, "wb");

    //test file open status
    if(fp1 == NULL || fp2 == NULL)
    {
        printf("\n copy failed");
        exit(0);//terminate the program
    }

    //read the src file, write into the target file
    while( (x = fgetc(fp1)) != EOF)
    {
        fputc(x, fp2);
    }
    
    printf("\n Copy Complete");
    
    //copying done, close the files
    fclose(fp1);
    fclose(fp2);
    return 0;
}