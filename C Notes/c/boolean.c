#include<stdio.h>

/*
 Boolean Datatype 
 
 In C there is no boolean datatype.
 int performs the job of boolean as well.
  
 int value zero represents false.
 all non zero int values represent true.
 
 Important to note that when system wishes
 to return true it returns one and when false
 then it returns zero.
 
 */

int main()
{
    int a, b, c;
    a = 10;
    b = 4;
    //c = a > b ;
    c = a > b + 7;
    //note that priority of arithmetic
    //operators is higher than the priority
    //of comparison operators.
    
    printf("\n c : %d", c);
    return 0;
}
