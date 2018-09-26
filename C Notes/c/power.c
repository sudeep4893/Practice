#include<stdio.h>

/*
 cal x raise to y
 */
int main()
{
    int x, y;
    int i;
    int result = 1;//to handle x ^ 0
    
    printf("\n enter val of x ");
    scanf("%d", &x);
    printf("\n enter val of y ");
    scanf("%d", &y);
    
    //cal x raise to y
    for(i = 1; i<=y; i++)
    {
        if(i == 1)
        {
            result = x;
        }
        else
        {
            result = result * x;
        }
    }
    
    printf("\n Ans : %d ", result);
    return 0;
}