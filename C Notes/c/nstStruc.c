#include<stdio.h>
/*
 Nested struct
 
 C allows declaration of a struct variable
 as a member of another struct definition.
 Doing so is called as "nesting of structs".
 
 (see the diagram).
 */

struct Inner
{
    int a;
    float b;
};
typedef struct Inner Inner;

struct Outer
{
    Inner in;
    char c;
};
typedef struct Outer Outer;

int main()
{
    Outer o;
    
    printf("\n enter data for o ");
    printf("\n o.in.a ");
    scanf("%d", &o.in.a);
    printf("\n o.in.b ");
    scanf("%f", &o.in.b);
    printf("\n o.c ");
    fflush(stdin);
    scanf("%c", &o.c);
    
    printf("\n o : ((%d %f) %c) ", o.in.a, o.in.b, o.c);
    
    return 0;
}