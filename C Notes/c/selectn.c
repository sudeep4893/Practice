#include <stdio.h>
/*
Selection Sort 
*/

void scanArray(int a[], int s)
{
    int i;
    printf("\n enter %d values ",s);
    for(i =0 ; i< s; i++)
    {
        scanf("%d", &a[i]);
    }
}//scanArray

void printArray(int a[], int s)
{
    int i;
    printf("\n ");
    for(i =0 ; i< s; i++)
    {
        printf(" %d", a[i]);
    }
}//printArray

void selection(int a[], int s)
{
    int i, j, min; //indices
    int temp; //swapping
                        
    for(i =0 ; i< s; i++)
    {
        min = i; //assumption
        for(j = i+1; j< s; j++)
        {
            if(a[j] < a[min])
            {
                min = j;//selection
            }
        }//for(j
        if(i != min)
        {//swap
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }//for(i
    
}

int main() 
{
    int arr[6];
    
    scanArray(arr, 6);
    printArray(arr, 6);
    
    selection(arr, 6);
 
    printArray(arr, 6);
 
    return 0;
}