#include <iostream>
using namespace std;
/*
A class is a group of variables 
and functions.
It represents a new secondary datatype
in C++.

It can be used by
1) creating objects
      className objName;
      
2) creating pointers
      className *ptrName; 
      
3) creating arrays
      className arrName[arrSize]; 

Further the three (object/pointer/array)
are used to access members (variables
and functions) of the class.

--------------------------------------------------
Array of class type

As we define arrays of primary
datatypes similarly we can define
arrays of class type.

example
	int arr[3];
	Myclass arr[3];

The elements of an array of class type
are objects of the class.

The default constructor is called to 
initialize the array elements (objects).

An "array initializer" can be used to
"call constructors of choice" for
the elements (objects) of the array.


Next the array elements (object) 
can be used to access the members 
of the class.

example
  loop (i = 0 to 2)
	arr[i].x =...
	arr[i].y =... 
	arr[i].disp();	

*/

class Myclass
{
	public://discuss later
	int x, y;

	Myclass()//default constructor
	{
		cout<<"\n Myclass()";
		x = 10;//init x
		y = 20;//init y
	}
	
	Myclass(int q, int w)//parameterized constructor
	{
		cout<<"\n Myclass(int, int)";
		x = q;//init x
		y = w;//init y
	}
	
	void disp()
	{
		cout<<"\n"<<x<<"  "<<y;
	}
};

int main()
{
	//create array of Myclass
	
	//Myclass arr[3];
	Myclass arr[3]= {Myclass(), Myclass(1,2)};//provide calls for same/less number of elements. In case of less calls default constructor executes for remaining elements.
	
	int i;
	for(i =0; i< 3; i++)
		arr[i].disp(); 
		
	return 0;	
}//main

