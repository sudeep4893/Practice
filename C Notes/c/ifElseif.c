#include<stdio.h>
/*
"if" - "else if" - "else"
 
It is possible to have secondary conditions 
connected to the false state of a primary
condition, using "if" - "else if" - "else". 
  
An "else if" statement can optionally follow 
an "if" statement.
When present "else if" is connected to the
false state of "if". 

"else if" has its own condition and a block
of code which executes when its condition 
evaluates to true, otherwise not. 

When condition of "else if" evaluates to 
false then system considers next "else if"
or "else". 
 
 */

// prg to find greater of 3 numbers

int main()
{
    int a, b, c;
    a = 10;
    b = 10;
    c = 10;
    
    if(a == b && a == c)
    {
        printf("\n All nos are %d", a);
    }
    else if(a > b && a > c)
    {
        printf("\n %d is greatest ", a);
    }
    else if(b > c)
    {
        printf("\n %d is greatest ", b);
    }
    else
    {
        printf("\n %d is greatest ", c);
    }
    
    return 0;
}

