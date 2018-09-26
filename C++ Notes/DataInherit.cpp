#include <iostream>
using namespace std;

/*
Data Inheritance
-----------------
Known that by inheritance the derived
class gets code and data from the base
class.
System implements inheritance of data
as object of derived class is created.

For every object of derived class along
with the members of derived class system
will internally automatically define 
nested object of the base class.


Constructor Calls For Derived Class Objects
---------------------------------------------

As object of derived is created with a
nested object of base, so constructors
of both (base and derived) the classes 
will get invoked.

Sequence will be base class constructor
first and derived class constructor next.

By default the parameter matching constructor
of derived class and the default constructor
of base class, gets called.
To invoke the parameter matching constructor
of the base class the derived class constrcutor
must pass parameters to the base class
constructor.

Syntax
--------
Derived(int q,int w,int e) : Base(q,w)
{}

Destructor Calls For Derived Class Objects
--------------------------------------------

As object of derived is created with a
nested object of base, so destructors
of both (base and derived) the classes 
will get invoked.

Sequence will be derived class destructor
first and base class destructor next.

*/

class A
{
	protected:
		int x,y; //member variables of A
	public:
		A();
		A(int,int);
		~A();
		void f1();
};

A :: A()
{
	cout<<"\n A()";
	x = 10;
	y = 20;
}

A :: A(int q ,int w)
{
	cout<<"\n A(int,int)";
	x = q;
	y = w;
}

A :: ~A()
{
	cout<<"\n ~A()";
}

void A :: f1()
{
	cout<<"\n A f1() ";
	cout<<"\n "<<x <<"  "<<y;
}


class B : public A
{
	int z; //a member variable of B	
	public:
		B();
		B(int,int,int);
		~B();
		void f2();
};

B :: B()
{
	cout<<"\n B()";
	z = 30;
}

//passing 2 params from B(int,int,int) to A(int,int)
B :: B(int q ,int w, int e): A(q,w)
{
	cout<<"\n B(int,int, int)";
	z = e;
}

B :: ~B()
{
	cout<<"\n ~B()";
}

void B :: f2()
{
	cout<<"\n B f2() ";
	cout<<"\n "<<x <<"  "<<y<<"  "<<z;
}

int main()
{
	//object of derived class
	B objB(1,2,3);
	objB.f2();	
	return 0;
}