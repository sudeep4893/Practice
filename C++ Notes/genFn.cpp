#include <iostream>
using namespace std;

/*
Templates

Templates are mechanisms used to define
Generic classes and Generic functions.

A generic function is a function that
support processing of parameters of 
different datatypes using the same logic.

Example 1: Define n functions to support 
swapping of variables of n datatypes.
	swap(int,int);
	swap(char, char);
	swap(float,float);
	swap(Student,Student);
	
or

Define 1 generic function to support
swapping of variables of n datatypes.

	template<class x> swap(x,x);


Example 2: Define n functions to support
sorting of arrays of n datatypes
	
	bubbleSort(int[]);
	bubbleSort(float[]);
	bubbleSort(char[]);
	bubbleSort(Student[]);
	
or
Define 1 generic function to support
sorting of arrays of n datatypes
	
	template <class x> bubbleSort(x[]);
	
---------------------------------------------
Syntax:
	template <class x>	rtType fnName (x param)
	{
		x variables, pointers, ...
		.....
	}

The above syntax defines a generic datatype x
that can represent any primary or secondary
datatype.
*/

template <class x> void bubble(x arr[], int size)
{
	int i, j;
	x temp;
	
	for(i = size-1; i> 0; i--)
	{
		for(j =0 ; j< i; j++)
		{
			if(arr[j] > arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}//for(j
	}//for(i
	 
}//bubble

template <class x> void disp(x arr[], int size)
{
	int i;
	cout<<"\n";
	for(i =0; i< size; i++)
	{
		cout<<" "<<arr[i];
	}
}


int main()
{
	int arr1[5]= {10, 5, 1, 15, 12};
	char arr2[5] = {'q', 'w', 'e', 'r', 't'};
	double arr3[5] = {4.5, 4.51, 4.11, 4.14, 4.3};	
	
	disp(arr1, 5);
	bubble(arr1, 5);
	disp(arr1, 5);
	
	disp(arr2, 5);
	bubble(arr2, 5);
	disp(arr2, 5);
	
	disp(arr3, 5);
	bubble(arr3, 5);
	disp(arr3, 5);
	
		
	return 0;
}

