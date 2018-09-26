#include <stdio.h>
/*
 Functions

 A program implements a task by dividing
 it into subtasks.
 These subtasks are modules of a program.
 
 Such modules of a program are implemented
 in functions.
 
 A function is made up of 2 parts
 * Signature
 * Body
 
 Function Signature consists of
 * Return Type
 * Function Name (which must be unique)
 * Function Parameters
 
 Function body is a block of code that
 contains logic to perform the sub task.
 
---------------------------------------------- 
 Function Execution
  
 By default system executes the main() only.
 Other functions require a call for execution.
 
 When a function is called then program control
 is transferred from the line of call to the
 definition of the function.  
 
 Next the code of the function executes.
 
 On completion program control "returns"
 to the line following the call to the 
 function.
 
 */ 


void f()
{
    printf("\n 1");
    printf("\n 2");
    printf("\n 3");
}

int main() 
{
    printf("\n A");
    printf("\n B");
    f();//function call
    printf("\n C");

    return 0;
}