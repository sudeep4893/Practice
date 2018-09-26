#include <iostream>
using namespace std;

/*
Constructor
------------

Object of a class by default has 
garbage data in its member variables.

It is a good programming practice
to initialize the object on creation.

For object initialization purpose 
every OOP language supports definition 
of a special member function called 
as "Constructor".

About Constuctor

1) It is a special member function.
2) It has the same name as of the class
   and no return type specification.
3) It is called automatically as object
   of the class is created.   
4) It is used to initialize the object of
   the class.

-------------------------------------------
Classification
---------------

A constructor can be classified as
1) Default Constructor
2) Parameterized Constructor

Default Constructor
is the one that doesnt take any
data (parameter) from the user
and initalizes object of the class 
with program default values.

2) Parameterized Constructor
is the one that takes data (parameter)
from the user and initalizes object 
of the class with user given values.

Note: A copy constructor is a special
type of parameterized constructor.

-------------------------------------------
Constructor Overloading
means defining mutliple constructors 
for a class with different set of
parameters.

This allows object initalization
in multiple ways.
It is implementation of OOP concept
of Polymorphism.

Polymorphism is define multiple ways
to do a same operation.
-------------------------------------------
System support

If we donot define any constructor
for a class then system auto defines
a default constructor with empty
definition.
Example
CDemo()
{}

Why so?
Because object creation is a 
two step process.
1) memory allocation.
2) execution of constructor.



*/


class CDemo
{
	public: //will be discussed later
	
	//member variables
	int a, b;
	
	//member functions

	CDemo()//default constructor
	{
		cout<<"\n CDemo() COnstructor ";
		a = 10;//init member variable a		
		b = 20;//init member variable b		
	}//CDemo()
	
	CDemo(int q, int w)//parameterized constructor
	{
		cout<<"\n CDemo(int,int) COnstructor ";
		a = q;//init member variable a		
		b = w;//init member variable b		
	}//CDemo(int, int)
		
	void disp()
	{
		cout<<"\n"<<a <<" "<<b;
	}
	
};//class


int main()//prg starts here
{
	//create objects of the class
	CDemo obj1; // user is not providing any data for object initialization
	CDemo obj2(11,22);// user is providing data for object initialization
	CDemo obj3(1,2);// user is providing data for object initialization
	
	obj1.disp();//call disp fn
	obj2.disp();
	obj3.disp();
	
	return 0;
}