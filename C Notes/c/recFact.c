#include<stdio.h>
/*
 Cal factorial of a number recursively 
        
 5! = 5*4*3*2*1
 4! = 4*3*2*1
 ....
 0! = 1 
 Hence
 5! = 5 * 4!
 And in generalized terms
 x! = x * (x-1)!
 */ 

int factorial(int x)
{
    if(x == 0)
        return 1;
    else
        return x * factorial(x-1);
}

int main()
{
    int n;
    int ans;
    n = 5;//scan it
    
    ans = factorial(n);
    printf("\n Answer : %d", ans);
    return 0;
}