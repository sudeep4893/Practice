#include <stdio.h>
/*
 Pointer to a Pointer
 
 C allows declaration of a pointer to a 
 pointer.
 A pointer to a pointer is used to store
 address of a pointer (and not of normal
 variables). Further it supports double
 dereferencing.
 
 */ 

int main() 
{
    int i; //declare a variable
    int *p; //declare a pointer
    int **q; //declare a pointer to a pointer
    
    
    i = 10;
    p = &i; //referencing
    q = &p; //referencing
    
    printf("\n i : %d ", i); //access var by name
    printf("\n i : %d ", *p);//access var by dereferencing
    printf("\n i : %d ", **q);//access var by double dereferencing
    
    return 0;
}
