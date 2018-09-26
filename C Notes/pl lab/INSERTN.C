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

void insertion(int a[], int s)
{
	int i,j,temp;

	for(i = 1; i< s; i++)
	{
		temp = a[i];
		for(j=i-1; j>=0 && temp<a[j]; j--)
		{
			a[j+1] = a[j]; //shift
		}//for(j
		a[j+1] = temp; //insertion
	}//for(i
}

void main()
{
	int arr[SIZE];
	clrscr();
	scan(arr, SIZE);
	disp(arr, SIZE);

	insertion(arr, SIZE);

	disp(arr, SIZE);

}
