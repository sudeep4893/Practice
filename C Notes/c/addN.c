#include<stdio.h>

//addtion of n numbers

int main()
{
    int n;
    int i, x, total;
    
    printf("\n How many numbers to add ");
    scanf("%d", &n);
    
    i = 1;
    while(i <= n)        
    {
        printf("\n enter a number ");
        scanf("%d", &x);//we know that x will be overwritten in every loop cycle 

        if(i == 1)
        {
            total = x;
        }
        else
        {
            total = total + x;
        }
        i++;        
    }//while, runs n times
    
    printf("\n Addition : %d", total);
    return 0;
}