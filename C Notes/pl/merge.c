#include<stdio.h>
#define SIZE 20


void merge(int arr[], int s)
{
    int i, j, k, temp;
    int arr1[SIZE], arr2[SIZE];
    int s1, s2;

    if(s % 2 == 0)
    {
        s1 = s/2;
        s2 = s/2;
    }
    else
    {
        s1 = s/2 +1;
        s2 = s/2;
    }

    //copy s1 elements of arr into arr1
    for(i=0; i< s1; i++)
        arr1[i] = arr[i];

    //copy s1 onward elements of arr into arr2
    for(i=0; i< s2; i++)
        arr2[i] = arr[i + s1];


    if(s1 > 2)
        merge(arr1,s1);
    else if(s1 == 2)
    {
        if(arr1[0] > arr1[1])
        {
            temp = arr1[0];
            arr1[0] = arr1[1];
            arr1[1] = temp;
        }
    }


    if(s2 > 2)
        merge(arr2,s2);
    else if(s2 == 2)
    {
        if(arr2[0] > arr2[1])
        {
            temp = arr2[0];
            arr2[0] = arr2[1];
            arr2[1] = temp;
        }
    }

    //merge
    i = 0;
    j = 0;
    k = 0;

    while(i < s1 && j < s2)
    {
        if(arr1[i] < arr2[j])
        {
            arr[k] = arr1[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = arr2[j];
            j++;
            k++;
        }

    }//while
    //for remaining elements of a1
    while(i < s1)
    {
        arr[k] = arr1[i];
        i++;
        k++;
    }
    //for remaining elements of a2
    while(j < s2)
    {
        arr[k] = arr2[j];
        j++;
        k++;
    }
}//merge


void scanArr(int arr[], int s)
{
    int i;
    printf("\n enter %d values ",s );
    for(i =0; i< s; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void dispArr(int arr[], int s)
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
    int arr[SIZE];
    int x;
    printf("\n enter size of arr (MAX 20) ");
    scanf("%d", &x);

    scanArr(arr,x);
    dispArr(arr,x);
    merge(arr,x);
    dispArr(arr,x);
    return 0;
}
