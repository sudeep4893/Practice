#include<stdio.h>
/*
C supports 3 types of operators 
1) Unary : That acts on one operand
                ++, --, ~, !, etc
  
2) Binary : That acts on two operands      
                +, - , * , / , etc

3) Ternary : That acts on three operands
            <condition> ? onTrue : onFalse
 This operator allows execution of either
 of two operations based on a condition.
 
 
 */

int main()
{
    int a, b, c;
    a = 30;
    b = 20;
    
    c = a > b ? 100: a-b;
    printf("\n c : %d", c);
    return 0;
}

