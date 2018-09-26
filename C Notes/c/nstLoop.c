#include <stdio.h>
/*
Nested Loops
 
 C allows writing loops inside loops.
 In such a case for one cycle of the
 outer loop, the inner loop runs full.
 
 
 
 */

int main() 
{
    int i, j;
    /*
    for(i =1 ; i< 5; i++)
    {
        printf("\n A : ");
        for(j = 1; j< 4; j++)
        {
            printf(" B ");
        }//for(j
    }//for(i
    */
    for(i = 1; i<=5; i++)
    {
        printf("\n");
        for(j =1; j<= i; j++)
        {
                printf(" * ");
        }//for(j
    }//for(i
    return 0;
}