#include <stdio.h>
/*
Passing struct variable as parameter to Function

A struct variable can be passed as a parameter 
to a function in the same way as we pass 
parameters of primitive types.

By default a struct variable is passed by value.

In order to pass a struct variable by reference
one must pass its address and receive the same
in a pointer to a struct variable.
Next the actual struct variable can be accessed 
by dereferencing the pointer.

There are 2 ways to dereference a struct pointer
1) Using prefix dereferencing operator :  *
   Here we apply dereferencing operator  *
   to the struct pointer and this gives access
   to the actual struct variable's memory block.
   Next we apply operator . (dot) to access the
   struct member.
   Only thing we need to take care of is, operator
   priority. Hence we put the dereferencing  operator *
   in brackets so that it gets resolved first.
 
   Example
       (*ptr).member

2) Using infix dereferencing operator :  ->
   Here we apply dereferencing operator  ->
   between the struct pointer and the 
   struct member.
   This gives direct access to the required
   struct member using pointer to struct variable.

   Example
       ptr->member


*/
struct Demo
{
    int a;
    float b;
    char c;
};

void fn1(struct Demo var)//rcv struct var as a parameter
{
    printf("\n var { %d %f %c }", var.a, var.b, var.c);
    var.a++;
    var.b++;
    var.c++;//allowed 
    printf("\n var { %d %f %c }", var.a, var.b, var.c);
}    

void fn2(struct Demo * p)//rcv address of struct var as a parameter
{
    //p has address of struct variable : d
    printf("\n *p { %d %f %c }", (*p).a, (*p).b, (*p).c);
    (*p).a++;//dereference p and access struct member a
    p->b++;//dereference p and access struct member b
    p->c++;//dereference p and access struct member c
    printf("\n *p { %d %f %c }", p->a, p->b, p->c);
}

int main()
{
    struct Demo d;

    //scan a struct variable
    printf("\n Enter data for struct Demo Members ");
    printf("\n a : ");
    scanf("%d", &d.a);
    printf("\n b : ");
    scanf("%f", &d.b);
    printf("\n c : ");
    fflush(stdin);
    scanf("%c", &d.c);
    
    printf("\n ---- DEMO PASS BY VAL ----");
    printf("\n d { %d %f %c }", d.a, d.b, d.c);
    fn1(d);//pass struct var as a parameter to a fn
    printf("\n d { %d %f %c }", d.a, d.b, d.c);

    printf("\n ---- DEMO PASS BY REF ----");
    printf("\n d { %d %f %c }", d.a, d.b, d.c);
    fn2(&d);//pass address of struct var as a parameter to a fn
    printf("\n d { %d %f %c }", d.a, d.b, d.c);

    return 0;
}