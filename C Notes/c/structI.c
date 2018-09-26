#include <stdio.h>

/*
 struct initializer 
 
 A struct initializer can be used to assign
 default values to a struct variable while
 declaration.
 
 syntax
   dataType structVar = {valMem1, valMem2, ...};
 
 example
   Demo d = {10, 3.57, 'q'};
 
 Take care to assign values in the same order
 as of member declaration in the struct definition.
 
 If data is not given for any/all of the 
 members then they take their default values
 (zero, blank, null, ...) and are garbage free.
 
 */
struct Demo
{
    int a;
    float b;
    char c;
};

typedef struct Demo Demo;

int main() 
{
    Demo d = {10, 3.57, 'q'};
    //Demo d = {10};
    //Demo d = {};
    Demo d1;
    
    printf("\n d( %d %f %c )", d.a, d.b , d.c);
    d1 = d; //copy data of all members of d into corresponding members of d1
    printf("\n d1( %d %f %c )", d1.a, d1.b , d1.c);

    return 0;
}
