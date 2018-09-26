#include<stdio.h>

/*
Program to find greatest of n numbers recursively

 greatest(4) = 4thNo > greatest(3);  
 greatest(3) = 3rdNo > greatest(2);
 greatest(2) = 2ndNo > greatest(1);
 greatest(1) = 1stNo itself
 
 */ 


int greatest(int n)
{
    int x, y;
    printf("\n enter a number ");
    scanf("%d", &x);
    if(n == 1)//base condn
        return x; 
    y = greatest(n-1);
    
    if(x > y)
        return x;
    else
        return y;
}

int main()
{
    int n;
    int ans;
    printf("\n How many numbers you want to compare ");
    scanf("%d", &n);
    
    ans = greatest(n);
    printf("\n Greatest : %d", ans);
    return 0;
}