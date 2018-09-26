#include <stdio.h>
/*
  PASSING ARRAY AS A PARAMETER TO A FUNCTION
 
To pass an array as a parameter to a function
simply pass its name, without []. 
 
To receive an array as a parameter 
we declare 
 * an array of same datatype 
 * having any name
 * without any size. 
in the functions signature. 

It is important to note that the actual 
parameter array and the formal parameter
array refer to the same location in memory.

i.e. formal parameter array is not a copy 
of actual parameter array, instead it is a
reference to the same memory. 
 
Hence changes made to the formal parameter
array get reflected in the actual parameter
array. 
 
This concept is called as "PASS BY REFERENCE". 
 */

void increment(int a[])
{
    printf("\n in increment");
    a[1] = 99;//changes arr in main
    printf("\n end of increment");
}

int main() 
{
    //int arr[3];//all elements are garbage by default
    int arr[3] = {1,10,100}; //here we are using an array initializer, it sets arr elements to 1, 10 and 100 respectively
    //int arr[3] = {1};//this array initializer will set array elements to 1, 0, 0 respectively
    //int arr[3] = {};//this array initializer will set all array elements to 0
    //int arr[3] = {1,2,3,4};//too many initializers error or will set array elements to 1, 2, 3 respectively
    
    int i;
    
    printf("\n");
    for(i =0; i< 3; i++)//loop == repeat
    {
        printf(" %d", arr[i]);
    }
    
    increment(arr);//passing array as a parameter to increment function 
    
    printf("\n");
    for(i =0; i< 3; i++)//loop == repeat
    {
        printf(" %d", arr[i]);
    }
    
    return 0;
}