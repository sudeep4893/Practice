#include<stdio.h>

/*
Study of Division Operators

 C provides 2 division operators
 1) /  (Divide)
 It gives the quotient of division 
  
 2) %  (Modulus)
 It gives the remainder of division.
 It works on whole numbers only.
  
 
 */

int main()
{
    int q, r;
    q = 15/7;
    r = 15%7;
    printf("15 divided by 7");
    printf("\n quotient : %d ", q);
    printf("\n remainder : %d ", r);
    
    return 0;
}
