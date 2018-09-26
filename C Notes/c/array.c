#include<stdio.h>

/*
Arrays 
An array is a group of variables of same  
data type. It represents a homogenous 
collection of information.
 
A continuous block of memory is allocated
for an array. It is divided into similar
units called as "array elements". 
 
Array elements are automatically assigned
a zero based index. Individual array element
can be accessed using a combination of
array name and element index.
        arrName[elementIndex];
 
TO declare an array 
        datatype arrayName[arraySize];
example 
        int arr[5];
 
Rules of array declaration
Array can have any datatype and any valid name 
but its size must be
1) a whole number. 
 float arr[5.2] ;// is illegal
 float arr[5] ;// is legal
 
2) a positive value > zero  
 long arr[-4];//is illegal
 long arr[9];//is legal
 
3) a constant value. A variable cannot be 
used to specify array size. 
 int x = 4;
 float arr[x]; //is illegal
 float arr[4]; //is legal
 
--------------------------------------------
Always use loops to scan/process/print arrays 
-------------------------------------------- 
 */
int main()
{
    int arr[5];//declare an array of 5 integers
    int i;
    
    //store data in it
    printf("\n enter 5 numbers ");
    /*
    scanf("%d", &arr[0]);
    scanf("%d", &arr[1]);
    scanf("%d", &arr[2]);
    scanf("%d", &arr[3]);
    scanf("%d", &arr[4]);
    */
    for(i =0 ; i<5; i++)
    {
        scanf("%d", &arr[i]);
    }//for, runs 0 to 4 (5 times)
                
    //print it
    printf("\n Array : ");
    for(i =0 ; i<5; i++)
    {
        printf("%d ", arr[i]);
    }//for, runs 0 to 4 (5 times)
    
    return 0;
}