#include <stdio.h>
/*
 Sequential Search 
 
 Sequential search is searching a value
 by sequential comparison.
    
 Sequential search is applied on linear
 data structures like arrays and linked lists.
 
 In sequential search we begin with the
 first element and sequentially compare 
 the value to be searched with all the 
 array or linked list elements.
 
 If value is found
 * we stop the search as match is found
 * we return the index/address of element where value was found
 
 If value is not found
 * we stop after comparing with all array/linked list elements
 * we return -1 or NULL.
 
 */ 
void scanArray(int a[], int size)
{
    int i;
    printf("\n Enter %d numbers ", size);
    for(i =0; i< size; i++)
    {
        scanf("%d", &a[i]);
    }
}

void printArray(int a[], int size)
{
    int i;
    printf("\n Array : ");
    for(i =0; i< size; i++)
    {
        printf(" %d", a[i]);
    }
}

int search(int a[], int size, int val)
{
    int i;
    for(i = 0; i< size; i++)
    {
        if(a[i] == val)
        {
          return i;//index of element where match is found  
        }
    }//for
    return -1; //not found
}

int main() 
{
    int arr[6];
    int x, q;
    scanArray(arr, 6);
    printArray(arr, 6);
    
    printf("\n enter the value to be searched ");
    scanf("%d", &x);
    
    q = search(arr, 6, x);
    
    if(q != -1)
        printf("\n %d found at index %d ", x, q);
    else
        printf("\n %d not found ", x);
    
    return 0;
}