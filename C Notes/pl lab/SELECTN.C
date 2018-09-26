#include<stdio.h>
#include<conio.h>
#define SIZE 10

void scan(int a[], int s)
{
	int i;

	printf("\n Enter %d values ", s);

	for(i =0; i<s; i++)
	{
		scanf("%d", &a[i]);
	}
}

void disp(int a[], int s)
{
	int i;

	printf("\n");
	for(i =0; i< s; i++)
	{
		printf(" %d", a[i]);
	}
}

void selection(int a[], int s)
{
	int i,j,m,temp;

	for(i =0; i< s-1; i++)
	{
		m = i; //assumtion
		for(j = i+1; j< s; j++)
		{
			if(a[j] < a[m])
			{
				m = j;//selection
			}
		}//for(j

		if(m != i)
		{//swap
			temp = a[i];
			a[i] = a[m];
			a[m] = temp;
		}
	}//for(i

}

void main()
{
	int arr[SIZE];
	clrscr();
	scan(arr, SIZE);
	disp(arr, SIZE);

	selection(arr, SIZE);

	disp(arr, SIZE);

}
