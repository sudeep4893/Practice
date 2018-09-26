#include <iostream>
using namespace std;

/*
Multilevel Inheritance
-------------------------

A hierarchy of classes can be defined
using multilevel inheritance.

Example:

	A {x, f1()}
	|
	B {x, f1(), y, f2()}
	|
	C {x, f1(), y, f2(), z , f3()}

In such a case the class up in hierarchy
gives code and data to its derived class.
The same approach continues upto n levels.

Also due to inheritance, type compatibility
upto n levels gets defined.

i.e. WRT example,  system allows

A *ptrA;
ptrA = &objA; //same class
ptrA = &objB; //A is a direct base class of B
ptrA = &objC; //even though A is not a direct base class of C


B *ptrB;
ptrB = &objB;//same class
ptrB = &objC; //B is a direct base class of C


Object of a class down in hierarchy
-------------------------------------
For every object of a class down in hierarchy
system will create nested objects of all
the classes above it in hierarchy.

Constructor execution
-----------------------
WRT example : A() B() and C()
Constructor of C can pass parameters to 
constructor of B and not to constructor
of A.

Destructor execution
----------------------
WRT example : ~C() ~B() and ~A()


virtual attribute
-------------------

virtual attribute is inherited.

i.e. An override of a virtual function
automatically makes the overriding function
virtual.

And if destructor of a class up in hierarchy
is virtual then destructors of classes under
it are automatically virtual.

*/

class A
{
	protected:
		int x;
	public:
		A();
		A(int );
		virtual ~A();
		virtual void fn();
};

A::A()
{
	cout<<"\n A()";
	x = 10;
}

A::A(int q)
{
	cout<<"\n A(int)";
	x = q;
}

A :: ~A()
{
	cout<<"\n ~A()";
}

void A :: fn()
{
	cout<<"\n x : "<< x;
}

class B : public A
{
	protected:
		int y;
	public:
		B();
		B(int , int);
		~B();//automatically virtual as ~A() is virtual
		void fn();//override, hence virtual by inheritance 
};

B::B()
{
	cout<<"\n B()";
	y = 20;
}

B::B(int q, int w): A(q)//pass q as a parameter to A(int)
{
	cout<<"\n B(int, int)";
	y = w;
}

B :: ~B()
{
	cout<<"\n ~B()";
}

void B :: fn()
{
	cout<<"\n x : "<< x;
	cout<<"\n y : "<< y;
}

class C : public B
{
	protected:
		int z;
	public:
		C();
		C(int , int, int);
		~C();//automatically virtual as ~B() is virtual
		void fn();//override, hence virtual by inheritance
};

C::C()
{
	cout<<"\n C()";
	z = 30;
}

C::C(int q, int w, int e): B(q,w)//pass q and w as parameters to B(int,int)
{
	cout<<"\n C(int,int,int)";
	z = e;
}

C :: ~C()
{
	cout<<"\n ~C()";
}

void C :: fn()
{
	cout<<"\n x : "<< x;//comes from A through B
	cout<<"\n y : "<< y;//directly comes from B
	cout<<"\n z : "<< z;//defined by C
}


int main()
{
	A *ptrA;
	
	ptrA = new C(5,10,15);//type compatibility across n levels
	ptrA->fn();
	
	delete ptrA;
	
	return 0;
}

