#include<stdio.h>
/*
switch selection statement 
 
Is used for conditional branching of 
program code. In this sense it is similar
to "if" statement. 
 
About switch 
 
Only one integer or char value can be 
used in switch statement. 
 
The variable used in switch statement 
is checked (compared) for equality only. 
 
switch requires definition of case statements. 
 
One case statement represents one int or char 
value. 
 
case value must be a constant. 
 
case has code in it. System executes the case 
value of which matches (equals) with the value 
of the variable used in switch statement. 
 
Every case must be terminated using a break 
statement. Otherwise system auto executes 
the case following the matched case, until 
break is encountered. 
 
A default case can be defined to execute when 
non of the case values match to the value of 
the variable used in switch statement. 
 
Any case can be defined in any order. 

Multiple cases cannot represent the same 
value. i.e. case values cannot be duplicated.
 
 */

int main()
{
    int ch;
    float n1, n2, ans;
    
    printf("\n enter 2 nos ");
    scanf("%f%f", &n1, &n2);
    
    printf("\n 1. Addition");
    printf("\n 2. Subtraction");
    printf("\n 3. Multiplication");
    printf("\n 4. Division");
    printf("\n Enter Choice ");
    scanf("%d", &ch);
    
    switch(ch)
    {
        case 3: //when ch == 3   
          ans = n1 * n2;  
          printf("\n %f * %f = %f", n1,n2, ans);
          break;  
        case 1: //when ch == 1
          ans = n1 + n2;  
          printf("\n %f + %f = %f", n1,n2, ans);
          break;  
        default: //when ch != (1,2,3,4)
           printf("\n Invalid Choice"); 
           break;
        case 2: //when ch == 2
          ans = n1 - n2;  
          printf("\n %f - %f = %f", n1,n2, ans);          
          break;  
        case 3+1: //when ch == 4       
          ans = n1 / n2;  
          printf("\n %f / %f = %f", n1,n2, ans);          
          break;
    }//switch
    
    return 0;
}

