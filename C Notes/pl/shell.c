#include<stdio.h>

void shell(int arr[], int s)
{
    int i, temp, incr, curr;
    incr = (s-1)/2;

    while(incr != 0)
    {
        for(curr = incr; curr < s; curr++)
        {
            temp = arr[curr];
            i = curr-incr;
            while(i >=0 && temp < arr[i])
            {
                arr[i+incr] = arr[i];
                i = i - incr;
            }
            arr[i+incr] = temp;
        }//for
        incr = incr/2;
    }//while
}

void disp(int arr[], int s)
{
    int i;
    printf("\n");
    for(i =0; i< s; i++)
    {
        printf(" %d", arr[i]);
    }
}

int main()
{
    int arr[13] = {7,12,9,1,8,15,4,13,20,2,5,10,3};
    //scanArr
    disp(arr,13);
    shell(arr, 13);
    disp(arr,13);
    return 0;
}