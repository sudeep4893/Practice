#include <stdio.h>
/*

A pointer is a variable that can store 
address (memory location) and can be 
dereferenced.
   
-------------------------------------------- 
Every variable has a name and a unique address
(memory location). 
It is possible to access a variable 
 * By its name
 * By its address
 
 
 1) Access a variable by its name
 To access a variable by its name simply use
 the name in all expressions.
 Example
        int i;
        i = 10;
        i++;
 
 2) Access a variable by its address.
 To access a variable by its address
 * Fetch its address
   For this apply referencing operator : &
   on the variable name.
   example
        int i;//declare a variable
        &i; //fetches its address
 
 * Store the address in a pointer
   (For this declare a pointer first).
        int *p;//declare a pointer
        p = &i;//fetch address of i and assign it to pointer p
 
 
 * Read/Write into the variable by
   dereferencing the pointer.
        
   *p = 99;//dereference pointer p and access the target variable (i) for writing
   j = *p;// dereference pointer p and access the target variable (i) for reading
 */ 



int main() 
{
    int i;//declare a variable
    int *p;//declare a pointer (a variable that can store address)

    i = 10;//write into i using its name
    printf("\n i : %d", i);
    
    p= &i;//referencing (assign address of i to pointer p)
    *p = 99; //write into i by its address i.e. by dereferencing pointer p
    
    printf("\n i : %d", i);
    
    return 0;
}

/*
 Two basic operations wrt pointers are
 * Referencing : assigning an address to a pointer
 * Dereferencing : Accessing the target memory block (variable) address of which is stored in pointer.
 
 */