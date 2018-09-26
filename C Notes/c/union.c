#include<stdio.h>
/*
union 

A union is a group of 
variables/arrays/pointers/... 
of different data types. 
 
C treats a union definition as a secondary
datatype.
 
In all senses a union resembles a struct.
 
But there are following major differences 
between an struct and a union. 
 
1) Memory is allocated of only member of the
   union.
   Where as memory is allocated of all the 
   members of a struct.
 
2) Size of a union variable is equal to its
   largest sized member.
   Where as size of a struct variable is equal
   to the sum of sizes of its members.
 
3) As members of a union share the same memory 
   so only one member of the union can hold  
   data at one time.
   Where as members of a struct have individual
   memory so all the members of the struct can 
   hold data simultaneously.
 */

union UDemo
{
    int a;
    float b;
    char c;
};
typedef union UDemo UDemo;

struct SDemo
{
    int a;
    float b;
    char c;
};
typedef struct SDemo SDemo;

int main()
{
    UDemo u;
    SDemo s;
    
    printf("\n One memory block V/S N memory blocks");
    printf("\n Address of u.a : %u ", &u.a);
    printf("\n Address of u.b : %u ", &u.b);
    printf("\n Address of u.c : %u ", &u.c);
    
    printf("\n\n Address of s.a : %u ", &s.a);
    printf("\n Address of s.b : %u ", &s.b);
    printf("\n Address of s.c : %u ", &s.c);
    
    
    printf("\n\n Size of union var V/S Size of struct var");
    printf("\n Size of u : %d ", sizeof(u));
    printf("\n Size of s : %d ", sizeof(s));
 
    printf("\n\n Data storage of union var V/S Data storage of struct var");
    u.c = 'q';
    u.b = 2.3;
    u.a = 10;
    printf("\n u (%d %f %c)", u.a, u.b, u.c);
    
    s.c = 'q';
    s.b = 2.3;
    s.a = 10;
    printf("\n s (%d %f %c)", s.a, s.b, s.c);
    
    return 0;
}