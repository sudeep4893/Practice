#include <iostream>
using namespace std;
/*
A reference is an alternate name to 
an existing variable or an object.

A reference can be used as
1) parameter reference
2) stand alone reference
3) function return reference

1) parameter reference
In this case the formal parameter of a
function is declared as a reference.

Known that formal parameter is always
initialized by the actual parameter.

So the formal parameter reference becomes 
an alternate name to the existing memory 
block of actual parameter.

2) stand alone refernce
In this case a local reference is declared 
and is initialized with some variable/object 
of same type.

Being a reference it is an alternate
name to the existing memory block of 
the initializing variable/object.

3) function return reference
See next example
---------------------------------------

Rule : A reference once initialized
with a variable/object then cannot be
made to refer to any other variable/object.

*/

void f1(int z)//called by value
{
	cout<<"\n in f1, z : "<<z;	
	cout<<"\n in f1, &z : "<<&z;	
	z++;
	cout<<"\n in f1, z : "<<z;	
}

void f2(int &r)//called by reference
{
	cout<<"\n in f2, r : "<<r;	
	cout<<"\n in f2, &r : "<<&r;	
	r++;
	cout<<"\n in f2, r : "<<r;	
}

int main()
{
	int x;
	x = 10;
	cout<<"\n in main, x : "<<x;
	cout<<"\n in main, &x : "<<&x;
	f1(x);
  	cout<<"\n in main, x : "<<x;

	f2(x);
	cout<<"\n in main, x : "<<x;

	cout<<"\n====================";
	
	int &q = x;	//declaration and compulsory initialization of a local reference
	cout<<"\n in main, q : "<<q;	
	cout<<"\n in main, &q : "<<&q;	
	q++;
	cout<<"\n in main, q : "<<q;	
	cout<<"\n in main, x : "<<x;	
	
	ostream &vout = cout;
	vout<<"\n hello references";
	
	return 0;
}