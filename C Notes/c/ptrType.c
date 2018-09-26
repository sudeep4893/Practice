#include <stdio.h>
/*
  Size and Datatype of a pointer

 Every pointer is of same size
 * on 16 bit platform : 2 bytes
 * on 32 bit platform : 4 bytes
 because it has to store address 
 (memory location).
 
 Q) When every pointer has to store address
 and every pointer is of same size then why 
 do we need pointers of multiple different
 data types?
 
 A) We need pointers of multiple different
 data types for
    1) Dereferencing     
    2) Pointer Arithmetic
 
 ---------------------------------------------- 
 Role of Data type of pointer in Dereferencing.
 
 Variables of different data types have 
 different sizes.
 The pointer stores the starting address of
 the variable, it is referring to.
 
 For correct and complete dereferencing      
 system must know
  * Start Point to begin dereferencing from
     (this comes from the pointer).
  * Number of bytes to dereferenced
     (this comes from data type of pointer). 
 
 
 An int pointer dereferences 4 bytes.
 A char pointer dereferences 1 byte.
 A double pointer dereferences 8 bytes.
 And so on every pointer dereferences
 bytes equal to the size of data type 
 of pointer.
 
 Hence we must match the data type of 
 variable (memory block) and the data 
 type of the pointer.
 ---------------------------------------------- 
 
 Role of Data type of pointer in Arithmetic.
 
 Pointer arithmetic allows 
 Addition or Subtraction of an int value 
 with a pointer.
 
 i.e. allows ptr + intValue 
      and ptr - intValue   
 
 Such operations on pointers generates 
 different addresses depending on the 
 data type of the pointer.
 
 Say an int pointer ip, stores starting 
 address 100, and we add 3 to it then 
 resultant address is : 112
                  ip + 3
        becomes : ip + 3 * sizeof(int)
        result  : 112
 
 Say a char pointer cp, stores starting 
 address 100, and we add 3 to it then 
 resultant address is : 103
                  cp + 3
        becomes : cp + 3 * sizeof(char)
        result  : 103
 
 Say a double pointer dp, stores starting 
 address 100, and we add 3 to it then 
 resultant address is : 124
                  dp + 3
        becomes : dp + 3 * sizeof(double)
        result  : 124
 
 And so on on arithmetic operations 
 a pointers results in different addresses
 depending on its data type.
 */ 

int main() 
{
    int *ip;
    char *cp;
    double *dp;
    
    printf("\n-----SIZE OF POINTER-----");
    printf("\n int pointer    : %d ", sizeof(ip));
    printf("\n char pointer   : %d ", sizeof(cp));
    printf("\n double pointer : %d ", sizeof(dp));
    
    printf("\n-----POINTER DEREFERENCING-----");
    printf("\n int pointer    : %d ", sizeof(*ip));
    printf("\n char pointer   : %d ", sizeof(*cp));
    printf("\n double pointer : %d ", sizeof(*dp));

    printf("\n-----POINTER ARITHMETIC-----");    
    
    printf("\n ip : %u", ip);
    printf("\n cp : %u", cp);
    printf("\n dp : %u", dp);
    
    ip = ip + 3;
    cp = cp + 3;
    dp = dp + 3;
    
    printf("\n ip : %u", ip);
    printf("\n cp : %u", cp);
    printf("\n dp : %u", dp);
    
    return 0;
}
