#include <stdio.h>
/*
Insertion Sort 
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

void insertion(int a[], int s)
{
    int i, j; //indices
    int temp; //current value
    
    for(i =1 ; i< s; i++)
    {
        temp = a[i]; //current value
        for(j = i-1; j>=0; j--)
        {
            if(temp < a[j])
            {
                a[j+1] = a[j];
            }
            else
            {
                break;//stop the loop
            }
        }//for(j
        a[j+1] = temp; //insertion
    }//for(i
}

int main() 
{
    int arr[6];
    
    scanArray(arr, 6);
    printArray(arr, 6);
    
    insertion(arr, 6);
 
    printArray(arr, 6);
 
    return 0;
}