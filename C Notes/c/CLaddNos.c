#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

/*
Implement Addition of 2 numbers Using CMD LINE ARGS
*/

int main(int argc, char *argv[])
{
    int a, b, c;
    
    if(argc != 3)
    {
        printf("\n Wrong number of arguments");
        exit(0);
    }
    a = atoi(argv[1]);
    b = atoi(argv[2]);
    
    c = a+ b;
    printf("\n Addition : %d", c);
    return 0;
}
