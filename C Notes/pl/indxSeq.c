#include<stdio.h>

//indexed seq search
//rqeuires a sorted array
int iseqSrch(int arr[], int s, int val)
{
    int i;
    for(i =0; i< s; i++)
    {
        if(arr[i] == val)
            return i;//index where found
        else if(arr[i] > val)
            return -1;//not found
    }
    return -1; //not found
    
}
int main()
{
    int arr[]= {10,20,30,40,50};
    int x;
    x = iseqSrch(arr, 5, 30);
    if(x != -1)
        printf("\n Found at index %d ", x);
    else
        printf("\n Not found");
    
    x = iseqSrch(arr, 5, 36);
    if(x != -1)
        printf("\n Found at index %d ", x);
    else
        printf("\n Not found");
    
    return 0;
}
