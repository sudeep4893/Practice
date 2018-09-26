#include <iostream>
using namespace std;

/*
C++ allows implementation of hybrid
inheritance that is a combination of
multiple and multilevel inheritance.

Generally a class cannot inherit the
same base class more than once.

Due to hybrid inheritance a derived
class may inherit the same base class
multiple times.
(As in the diagram the derived class D
inherits class A twice, once through 
class B and next through class C).

The use of multiple times inherited
members causes ambiguity.

It can be resolved in 3 ways
1) By overriding the ambiguous member in the derived class (Example class D overrides ambiguous function void disp())
2) By qualifying the ambiguous member with base class name (Example class D applies base class names to usages of inherited member variables : x)
3) By declaring the multiple times inherited base class as a virtual base class (see virtualBase.cpp)
*/

class A
{
	protected:
		int x;
	public:
		A();
		A(int);
		~A();
		void disp();
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

void A :: disp()
{
	cout<<"\n x "<<x;
}

class B : public A
{
	protected:
		int y;
	public:
		B();
		B(int, int);
		~B();
		void disp();
};

B :: B()
{
	cout<<"\n B()";
	y = 20;
}

B :: B(int q, int w) : A(q)
{
	cout<<"\n B(int, int)";
	y = w;
}

B :: ~B()
{
	cout<<"\n ~B()";
}

void B :: disp()
{
	cout<<"\n x "<<x;
	cout<<"\n y "<<y;
}

class C : public A
{
	protected:
		int z;
	public:
		C();
		C(int, int);
		~C();
		void disp();
};

C :: C()
{
	cout<<"\n C()";
	z = 30;
}

C :: C(int q, int w) : A(q)
{
	cout<<"\n C(int, int)";
	z = w;
}

C :: ~C()
{
	cout<<"\n ~C()";
}

void C :: disp()
{
	cout<<"\n x "<<x;
	cout<<"\n z "<<z;
}

class D : public B , public C
{
	protected:
		int m;
	public:
		D();
		D(int, int, int,int);
		~D();
		void disp();
};

D :: D()
{
	cout<<"\n D()";
	m = B::x + y + C::x + z; //no ambiguity
}

D :: D(int p, int q, int r, int s) : B(p,q),C(r,s)
{
	cout<<"\n D(int,int,int,int)";
	m = B::x + y + C::x + z; //no ambiguity
}

D :: ~D()
{
	cout<<"\n ~D()";
}


void D :: disp()
{
	cout<<"\n "<< B::x << " + " << y << " + " << C::x << " + " << z << " = " <<m;//no ambiguity
}


int main()
{
	D objD(1,2,3,4);
	objD.disp();		
	return 0;
}

