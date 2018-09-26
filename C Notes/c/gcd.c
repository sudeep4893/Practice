#include<stdio.h>

/*
 prg to find GCD of 2 numbers.
 */
int main()
{
    int n1, n2;
    int x;
    
    //fetch 2 numbers from user
    printf("\n enter 2 numbers ");
    scanf("%d%d", &n1,&n2);
    
    //assign smaller of 2 numbers to x
    if(n1 < n2)
        x = n1;
    else
        x = n2;
    
    while(x > 0)
    {
        if(n1%x==0  && n2%x==0)
        {   
                printf("\n GCD : %d ", x);
                break;//stop the loop
        }
        x--;
    }
    
    return 0;
}