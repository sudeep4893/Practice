#include<stdio.h>
/*
 Recursion 
 is the mechanism that allows a function 
 to call itself.
 
 Recursive calls to a function must be
 controlled using some condition otherwise
 program (conceptually, may get stuck in 
 infinite recursion ) may get abnormally
 terminated due to stack overflow.
 
 As a function is called its uses memory of
 stack segment and repeated calls increase
 the space complexity of the program. Hence
 if an algorithm can be solved using loops
 then it is recommended to avoid recursion.
 
 Algorithms that are mathematically recursive
 must be implemented using recursion.
 
 Example
        power(5, 9) = 5 * power(5,8)
        power(5, 8) = 5 * power(5,7)
        ...
        power(5, 1) = 5 * power(5,0) 
        power(5, 0) = 1
 
 Every recursive algorithm has a base 
 condition, reaching which recursion must
 stop.
 */ 

int power(int x, int y)
{
    if(y == 0)
        return 1;
    else
        return x * power(x, y-1);    
}
int main()
{
    int x, y;
    int ans;
    x = 5;//scan it
    y = 4;//scan it
    
    ans = power(x, y);
    printf("\n Answer : %d", ans);
    return 0;
}