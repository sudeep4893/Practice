#include <stdio.h>
/*
 Pointer to an Array

 A pointer can be used to store address of
 first element of an array.
 Further using pointer arithmetic, the entire
 array can be traversed.
 
 */ 

int main() 
{
    int arr[5]= {10,20,30,40,50};
    int *p;
    int i;
    
    //store address of first element of array in a pointer
    //p = &arr[0];
    p = arr; //same as above, see proof below
    
    //array traversal
    printf("\n");
    for(i =0 ; i< 5; i++)
    {
        //printf(" %d ", *(p+i));//apply pointer arithmetic and dereferencing
        //printf(" %d ", *(i+p));//since a+b and b+a mean the same
        //printf(" %d ", *(arr+i));//since p = arr so all occurrences of p can be replaced with arr, infact when we write arr[i] system solves it as *(arr + i)
        //printf(" %d ", *(i+arr));//same as abv
        //printf(" %d ", p[i]);//as arr[i] is valid and as p = arr, so p[i] is also valid
        //printf(" %d ", i[arr]);//arr[i] == *(arr+i) == *(i+arr) == i[arr]
        printf(" %d ", i[p]);//i.e. *(i+p)
    }
    
    return 0;
}
/*
 How arr and &arr[0] mean the same?
 
        arr[0] 
means   *(arr+0)
means   *(arr)  
 
hence arr[0] == *(arr) 
apply  & on both sides
      &arr[0] == &*(arr)
as &* gets cancelled , so         
      &arr[0] == arr    
-------------------------------------------- 
 
Above example proves that a pointer can be 
used like an array and an array can be used
like a pointer. 
 
The only difference between the two is that 
a pointer is a variable and hence can be 
changed. 
i.e. ptr = someOtherAddress; is legal 
 
Whereas name of the array constantly refers 
to the first element of the array cannot 
be changed. 
i.e. arr = someOtherAddress; is illegal 
 

 */
        