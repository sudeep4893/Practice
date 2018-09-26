#include <stdio.h>

void change(int q[], int w)
{
    q[1] = 99;//pass by reference
    w = 99;//pass by value
}
int main() 
{
    int a = 10;
    int arr[3] = {10,10,10};
    
    printf("\n a : %d ", a);//10
    printf("\n arr : %d %d %d ", arr[0], arr[1], arr[2]);//10 10 10

    change(arr, a);
    
    printf("\n a : %d ", a);//10
    printf("\n arr : %d %d %d ", arr[0], arr[1], arr[2]);//10 99 10

    return 0;
}