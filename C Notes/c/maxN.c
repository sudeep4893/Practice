#include<stdio.h>

//greater of n numbers

int main()
{
    int n, i;
    int x, max;
    
    printf("\n how many numbers to compare ");
    scanf("%d", &n);
    
    i = 1;
    while(i <= n)
    {
        printf("\n enter a number ");
        scanf("%d", &x);//x will store current input
        
        if(i == 1 || x > max)
        {
            max = x;
        }
        i++;
    }//while, runs n times

    printf("\n Max : %d", max);
    return 0;
}