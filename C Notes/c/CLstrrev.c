#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
Implement String Reverse Using CMD LINE ARGS
*/

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("\n Wrong number of arguments");
        exit(0);
    }
    strrev(argv[1]);
    printf("\n Reverse : %s ", argv[1]);
    
    return 0;
}
