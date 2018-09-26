#include<stdio.h>

/*
System executes all the program statements.
But sometimes we wish that certain statements
must be executed and some must be skipped.

This conditional branching of program code is
done using "if" or "switch" statement.

About if statement.
An if statement has 
a condition and a block of code 
associated with it.

When system encounters an if statement
then it evaluates the associated condition
and results in a boolean value.

If the boolean value is true then system will
execute the block of code associated with
the if statement, otherwise not. 

An if statement can optionally an else statement
associated with it.

When else is present then it has a block of code
and it is connected with the false state of the
if condition.
i.e. The block of code of else statement executes
only when the if condition evaluates to false,
otherwise not.
*/

//program to check whether a number is an
//even number or an odd number.

int main()
{
    int x;
          
    x = 17;
    printf("\n Even Odd test starts");
    
    if(x %2 == 0)
    {//true
        printf("\n %d is an even no", x);
    }
    else
    {//false
        printf("\n %d is an odd no", x);
    }
    
    printf("\n Even Odd test complete");
    return 0;
}
/*
 comparison operators
  
 <   : less than
 >   : greater than 
 <=  : less than or equal to
 >=  : greater than or equal to
 ==  : equal to
 !=  : not equal to
 
 */