#include <stdio.h>
#include<arith.h>

/*
 Storage class specifiers
 tell the system where(in which segment)
 to allocate memory for the variables/arrays/...
 
 There are 4 storage class specifiers.
 
 1) auto (default)
 It is the default storage class specifier. 
 It can be applied to local variables only.
 It makes the variable reside in stack segment of RAM.
 The variable gets local scope and life.
   
 2) static
 It can be applied to local/global variables.
 It makes the variable reside in data segment of RAM.
 It makes the variable garbage free by default. 
 The variable gets declaration corresponding scope 
 and life equal to life of program.

 3) register
 It can be applied to local variables only.
 It recommends the system that the variable must reside in CPU registers, to speed up access.
 If accepted the variable gets declared in CPU register otherwise the variable gets storage class "auto".
 The variable gets local scope and life.
 
 4) extern
 extern tells the system that the variable being
 declared is defined by some other module.
 */ 


void f()
{
    int x= 10;//means auto int x
    static int y= 10;
    
    printf("\n %d  %d", x, y);
    x++;
    y++;
}

int main()
{
    int ans;
    extern int myData; //this is declaration of a variable that is defined in another module

    //uncomment for static demo
    //f();
    //f();
    //f();
    
    printf("\n MY DATA : %d ", myData);
    ans = add(3, 7);
    printf("\n ANS : %d", ans);
    
    ans = sub(3, 7);
    printf("\n ANS : %d", ans);

    return 0;
}
