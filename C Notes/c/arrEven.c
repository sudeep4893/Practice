#include <stdio.h>
/*
To print even numbers of an array
*/ 

int main() 
{
    int arr[6];//declares array of 6 elements
    int i;
    
    //scan data
    printf("\n enter 6 numbers ");
    for(i =0 ; i< 6; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    //print data
    printf("\n Even Nos : ");
    for(i =0 ; i< 6; i++)
    {
        if(arr[i]%2 == 0)
        {
                printf(" %d ", arr[i]);
        }
    }
    
    return 0;
}