#include<stdio.h>
#include<conio.h>
#define SIZE 10

void scan(int a[], int s)
{
	int i;
	printf("\n enter %d values ", s);
	for(i =0; i< s; i++)
	{
		scanf("%d", &a[i]);
	}
}

void disp(int a[], int s)
{
	int i;
	printf("\n ");
	for(i =0; i< s; i++)
	{
		printf(" %d", a[i]);
	}
}

void quick(int a[], int x, int y)
{
	int i, j;
	int key;
	int temp;

	if(x < y)//lower boundary must be less than upper boundary
	{
		i = x; //lower boundary
		j = y; //upper boundary
		key = a[x];

		while(i < j)
		{
			while(key >= a[i] && i < y)
				i++;
			while(key < a[j] && j > x)
				j--;

			if(i < j)
			{//i and j have not crossed yet, swap a[i] and a[j]
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}

		}//while
		//j is the final pos of key in sorted array
		//swap a[x] and a[j]
		temp = a[x];
		a[x] = a[j];
		a[j] = temp;

		//now key is at its correct pos
		//treat j as a pivot point
		//sort its left
		quick(a, x, j-1);
		//sort its right
		quick(a, j+1, y);
	}//if
}

void main()
{
	int arr[SIZE];
	clrscr();
	scan(arr, SIZE);
	disp(arr, SIZE);
	quick(arr, 0, SIZE-1);
	disp(arr, SIZE);
}