#include<stdio.h>

/*
 To find factors of a number
 */
int main()
{
    int n, i;
    printf("\n enter a number ");
    scanf("%d", &n);

    printf("\n Factors : ");
    
    for(i = 1; i<=n; i++)
    {
        //test if i is a factor of n
        if(n % i == 0)
        {//remainder is zero
            printf(" %d", i);
        }
    }//for, run 1 to n (inclusive)
    
    return 0;
}