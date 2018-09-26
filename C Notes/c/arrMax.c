#include <stdio.h>
/*
To find max number of an Array
*/ 
int main() 
{
    int arr[6];//declares array of 6 elements
    int i;
    int max;
    
    //scan data
    printf("\n enter 6 numbers ");
    for(i =0 ; i< 6; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    //print data
    printf("\n");
    for(i =0 ; i< 6; i++)
    {
        printf(" %d ", arr[i]);
    }
    
    //find the maximum value
    max = arr[0];//assumption
    for(i =1; i< 6; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }//for, runs 1 to 5 
    
    printf("\n Max : %d", max);
    
    return 0;
}

