#include <iostream>
using namespace std;

/*
Multiple Inheritance
---------------------

Definition
------------
C++ allows a derived class to inherit
from more than one base classes.
This feature is called as "multiple inheritance".

In multiple inheritance a derived class
cannot inherit the same base class more 
than once.

Object, Constructors and Destructors
------------------------------------
Due to multiple inheritance the derived 
class gets code and data from all the 
base classes.

For every object of derived class along
with the members of derived class system
will internally automatically define 
nested objects of the base classes.

As object of derived gets created with 
nested objects of base classes, so 
constructors of all base classes and the
derived classe will get invoked.

Sequence will be base class constructors
first and derived class constructor next.

By default the parameter matching constructor
of derived class and the default constructors
of base classes, gets invoked.

To invoke the parameter matching constructors
of the base classes the derived class constructor
must pass parameters to all the base class
constructors.

Syntax
--------
Derived(int q,int w,int e) : Base1(q), Base2(w)
{...}

Destructor Calls For Derived Class Objects
will be derived class destructor
first and base class destructors next.


Ambiguity
-----------
It is possible that the derived class gets
a member (var/function/...) of same signature
from multiple base classes.

Use of such a member causes ambiguity.

Ambiguity caused due to usage of the 
multiple times inherited member of 
same signature can be resolved
in 2 ways.

1) Redefine the ambiguous member in the 
derived class.
Due to this all calls to the ambiguous
member will get mapped with the definition
provided by the derived class.

2) Use the ambiguous member as
	"className::ambiguousMember"

Application of class name makes clear
for the system which defn to use, on call.
*/

class A
{
	protected:
	int x;
	public:
		A();
		A(int);
		~A();
		void f1();
		void f2();
};

A :: A()
{
	cout<<"\n A()";
	x = 10;
}

A :: A(int q)
{
	cout<<"\n A(int)";
	x = q;
}

A :: ~A()
{
	cout<<"\n ~A()";
}

void A :: f1()
{
	cout<<"\n f1() of A";
}

void A :: f2()
{
	cout<<"\n f2() of A";
	cout<<"\n x : "<<x;
}


class B
{
	protected:
	int y;
	public:
		B();
		B(int);
		~B();
		void f2();
		void f3();
};

B :: B()
{
	cout<<"\n B()";
	y = 20;
}

B :: B(int q)
{
	cout<<"\n B(int)";
	y = q;
}

B :: ~B()
{
	cout<<"\n ~B()";
}

void B :: f2()
{
	cout<<"\n f2() of B";
	cout<<"\n y : "<<y;
}

void B :: f3()
{
	cout<<"\n f3() of B";
}

//In code below class C inherits class A and class B both
class C : public A, public B
{
	protected :
		int z;
	public:
		C();
		C(int,int,int);
		~C();
		void f2();//redefine to resolve ambiguity
		void f4();
};

C::C()
{
	cout<<"\n C()";
	z = 30;
}
C::C(int q, int w, int e) : A(q), B(w)
{
	cout<<"\n C(int,int,int)";
	z = e;
}
C :: ~C()
{
	cout<<"\n ~C()";
}

void C :: f2()
{
	cout<<"\n f2() of C";
}

void C :: f4()
{
	cout<<"\n f4() of C starts";
	A::f2();
	B::f2();
	cout<<"\n z : "<<z;	
	cout<<"\n f4() of C ends";
}

int main()
{
	C objC(1,2,3);
	objC.f1();//f1() of A
	objC.f2();//f2() of C
	objC.f3();//f3() of B
	objC.f4();//f4() of C
	
	return 0;
}