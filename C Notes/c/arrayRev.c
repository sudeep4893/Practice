#include<stdio.h>

/*
 prg to reverse an array
 */
int main()
{
    int arr[6];//declare an array of 5 integers
    int i, j;
    int temp;
    
    //store data in it
    printf("\n enter 6 numbers ");

    for(i =0 ; i<6; i++)
    {
        scanf("%d", &arr[i]);
    }//for, runs 0 to 5 (6 times)
                
    //print it
    printf("\n Array : ");
    for(i =0 ; i<6; i++)
    {
        printf("%d ", arr[i]);
    }//for, runs 0 to 5 (6 times)

    //reverse it
    i = 0;//first element
    j = 5;//last element
    
    while(i<j)
    {
        //swap arr[i] and arr[j]
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
    
    //print it
    printf("\nReversed Array : ");
    for(i =0 ; i<6; i++)
    {
        printf("%d ", arr[i]);
    }//for, runs 0 to 5 (6 times)

    return 0;
}