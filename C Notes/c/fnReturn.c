#include <stdio.h>
/*
 
As a function is called, program control 
gets transferred from the line of call to 
the definition of the function. 
 
Next the code of the function executes. 
This processing generates some result 
that may be stored in local variable of 
the function.
Such local variables of the called function 
are not accessible to the caller function. 
 
In case the called function wishes to send
back the answer of its processing to the  
caller function, then it can be done when 
program control returns to the caller function. 
  
To send back an answer to the caller function
the called function uses "return" statement
and associates "one value" with it.
 
As return executes 
 * the current function terminates.
 * program control is transferred back to the caller function.
 * if a value is associated with return then the same is carried along and given to the caller function

---------------------------------------------------   
It is important to specify the data type of
the value being returned in the function signature. 
 
If no value is associated with return or
return is not used then a special return type
"void" must be specified in the functions 
signature. 
---------------------------------------
 
It is optional for the caller function to 
receive the value returned by the called 
function. 
 */
int fn()
{
    int a, b;
    a = 10;
    b = a*a;
    return b;//terminate this function and send value of b back to the caller function
}

int main() 
{
    int q;
    printf("\n A");
    printf("\n B");
    printf("\n C");
    q = fn();
    printf("\n D : %d", q);

    return 0;
}