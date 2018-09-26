#include <stdio.h>
/*
Bubble Sort 
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


void bubble(int a[], int s)
{
    int i, j; //loop  + indices
    int temp; //swapping
    
    for(i = s-1; i > 0; i--)
    {
        for(j =0 ; j< i; j++)
        {
            if(a[j] > a[j+1])
            {
                //swap
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }//if
        }//for(j
    }//for(i

}//bubble

int main() 
{
    int arr[6];
    
    scanArray(arr, 6);
    printArray(arr, 6);
    
    bubble(arr, 6);
 
    printArray(arr, 6);
 
    return 0;
}