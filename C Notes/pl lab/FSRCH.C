#include<stdio.h>
#include<conio.h>

//0,1,1,2,3,5,8,13,21,...

int fib(int x)
{
	if(x == 0 || x == 1)
		return x;
	else
		return fib(x-2) + fib(x-1);
}

int fsearch(int arr[], int n , int val)
{
	int j, f1, f2, temp;
	int mid;

	//find jth element in fibo series that is greater than array size
	j = 1;
	while(fib(j) < n)
	{
		j++;
	}

	//cal point f1 and f2
	f1 = fib(j-2);
	f2 = fib(j-3);

	mid = n - f1 + 1;

	while(val != arr[mid])
	{
		if(mid < 0 || val > arr[mid])
		{
			if(f1 == 1)
				return -1;
			mid = mid + f2;
			f1 = f1 - f2;
			f2 = f2 - f1;
		}
		else
		{
			if(f2 == 0)
				return -1;
			mid = mid - f2;
			temp = f1-f2;
			f1 = f2;
			f2 = temp;
		}
	}//while
	return mid;
}

void main()
{
	int x;
	int arr[15] = {1, 3, 5, 7, 10, 12, 15,18, 20, 22, 24, 30, 40, 45, 50};
	clrscr();
	x = fsearch(arr, 15, 30);
	printf("\n x : %d ", x);
}