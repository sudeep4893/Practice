#include <stdio.h>
/*
 Generic Pointers 
 
 For correct dereferencing and pointer
 arithmetic system requires us to match
 the data type of variable (memory block)
 and of the pointer.
 
 System also supports generic pointers
 that are capable of referring to variables
 (memory blocks) of any data type.
 
 Generic pointers are pointers of void data type.
 
 void is a special data type in C.
 It is used as 
        * A functions return type
        * A Generic Pointer
        
 It cannot be used for variable/array/...
 declaration as its size is unknown to 
 the system or is zero.
 
 A void pointer is a generic pointer that
 can refer to a variable/array/... of any
 data type.
 But as the size of void is unknown to the
 system or is zero, hence its cannot be
 directly
        * dereferenced
        * used in pointer arithmetic
 
 For dereferencing and for pointer arithmetic
 the void pointer must be typecasted (temporarily
 converted) into a pointer of appropriate data type. 
 */ 

int main() 
{
    int i = 10;
    char c = 'z';
    double d = 8.7654;
    
    void *p;
    
    p = &i;//referring to an int
    printf("\n i : %d ", *(int*)p);//dereference p by casting into int pointer
    
    p = &c;//referring to an char
    printf("\n c : %c ", *(char*)p);//dereference p by casting into char pointer
    
    p = &d;//referring to an double
    printf("\n d : %f ", *(double*)p);//dereference p by casting into double pointer
    
    return 0;
}
