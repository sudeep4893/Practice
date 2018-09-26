#include<stdio.h>

//more about printf
/*
 
 printf puts program data into stdout 
 (stream that connects CPU and Monitor)
 and it returns the number of characters
 transmitted.
  
 */
int main()
{
    int x;
    x = printf("Hello All");
    printf("\n x : %d", x);
    printf("\n----------------\n");
    x = 123;
    //printf("%5d", x);//print x like a 5 digit number
    //printf("%05d", x);//print x like a 5 digit number with leading zeros
    printf("%+d", x);//print x with a sign
    return 0;
}
