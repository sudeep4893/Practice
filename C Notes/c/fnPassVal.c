#include <stdio.h>
/*
Variables declared in a function are local
to the function.
Such variables can be used in the function 
but cannot be directly accessed in other 
functions.
 
In case variables (data) of a function are
to be used in another function then the same
must be passed as "parameters". 
 
 
Q) What are parameters?
Parameters are variables/arrays/memory blocks
that are declared in one function and shared
with another function, while calling the function.
 
There are two types of parameters:
1) Actual Parameter 
2) Formal Parameter 
 
Actual parameters are the one passed along 
with the function call. 
Formal parameters are the one received by
the called function. 
 
Generally the formal parameters are separate
variables in memory.  
They reflect the same data as of actual parameter, 
but they are copy of actual parameter.
 
Changes made to the formal parameter in the 
called function remain local to the formal 
parameter and never affect the actually passed
parameter. 
 
This concept is called as "PASS BY VALUE".
-------------------------------------------- 
 
Actual and Formal parameters must match in
 * count
 * datatype
 * sequence
 
 
 
 */
void increment(int q)//q is the formal parameter initialized by the actual parameter.
{
    printf("\n in increment");
    printf("\n q : %d", q);
    q++;
    printf("\n q : %d", q);
    printf("\n end of increment");
}

int main() 
{
    int x;//local variable of main()
    x = 10;
    printf("\n in main : %d", x);
    increment(x);//actual parameter, passed along with the function call
    printf("\n in main : %d", x);
    return 0;
}