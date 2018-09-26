#include <stdio.h>
#include <stdlib.h>

/*
 Dynamic Memory Allocation
 ------------------------- 
  
C supports allocation of memory in 2 ways 
1) Memory Allocation by variable/array/... declarations. 

   In this case system is aware of memory
requirement of the program.    
   System 
 * allocates the declared memory block 
 * allows usage 
 * deallocates the memory block 
as per the scope of the memory block. 
 
 
2) Dynamic memory allocation.
   In this case memory is allocated at
program run time by calls to malloc(), 
calloc(), realloc() functions.
 
   A call to any of these functions results
in allocation of memory blocks, of specific
sizes, in heap segment of RAM. 
 
   The life of such blocks is not confined 
to any scope, and can be extended across 
the program. 
 
   Such memory blocks get deallocated
when free() is called or when application 
terminates. 
 
   Such blocks are accessed using pointers.
 
   These functions are defined in stdlib.h  

--------------------------------------------- 
About malloc()
A call to malloc allocates a memory block 
of specific size in heap segment.

Data type of such a block is not set by
the system, hence it must be set by us
through type casting.

malloc returns starting address of the 
allocated block which we must receive 
and preserve for further use/deallocation. 
 
memory allocated using malloc has
garbage data by default.
 
--------------------------------------------- 
About calloc()
  
Same as malloc but the memory allocated
is clear (garabage free) by default.  
 
--------------------------------------------- 
About realloc()

realloc is used to further expand/shrink the 
memory block allocated using malloc()/calloc().
 
--------------------------------------------- 
About free()
 
free() is used to clear (deallocate) the
memory allocated using malloc()/calloc(). 
 */ 
//DYNAMIC ARRAY
int main()
{
    int n, i, size;
    int *p;
    
    printf("\n enter size of array ");
    scanf("%d", &n);
    size = n * sizeof(int);
    
    p = (int *) malloc(size);//size bytes of memory will get allocated
    //p = (int *)calloc(n, sizeof(int));

    //now p refers to starting address of the allocated memory block
    
    //we know that a pointer to starting
    //address of an array can be used like an array
    
    //operation 1, scanning
    printf("\n enter %d values ", n);
    for(i =0 ; i< n; i++)
    {
        scanf("%d", &p[i]);
        //scanf("%d", (p+i));
    }
    
    //operation 2, display
    printf("\n");
    for(i =0 ; i< n; i++)
    {
        //printf(" %d", p[i]);
        printf(" %d", *(p+i));
    }
  
    //operation 3, redimension the memory block created using malloc/calloc    
    
    n = n  + 2 ;
    size = n * sizeof(int);
    
    p = (int*) realloc(p, size);//data preserved
    
    //now p is expanded by 2 units
    p[n-1] = 55;//put data int last element
    p[n-2] = 66;//put data int second last element
 
    
    //display
    printf("\n");
    for(i =0 ; i< n; i++)
    {
        //printf(" %d", p[i]);
        printf(" %d", *(p+i));
    }

    //operation 4, deallocation
    free(p);//deallocate the memory allocated using malloc/calloc/realloc
    
    return 0;
}