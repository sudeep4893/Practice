#include <iostream>
using namespace std;

/*
Due to hybrid inheritance a derived
class may inherit the same base class
multiple times.

Multiple inheritance of the same base
class can be avoided using virtual base
class.

If virtual is applied during inheritance
then the derived class inherits the base 
class only once and contains its one sub-object.

(see the diagram)

Note : 
constructor of class D can pass parameters 
to constructors of
virtual base class A
real base classes B and C

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

class B : virtual public A
{
	protected:
		int y;
	public:
		B();
		B(int);
		B(int, int);
		~B();
		void disp();
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

class C : virtual public A
{
	protected:
		int z;
	public:
		C();
		C(int);
		C(int, int);
		~C();
		void disp();
};

C :: C()
{
	cout<<"\n C()";
	z = 30;
}

C :: C(int q)
{
	cout<<"\n C(int)";
	z = q;
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
		D(int, int, int);
		~D();
		void disp();
};

D :: D()
{
	cout<<"\n D()";
	m = x + y + z; //no ambiguity
}

D :: D(int p, int q, int r) : A(p),B(q),C(r)
{
	cout<<"\n D(int,int,int)";
	m = x + y + z; //no ambiguity
}

D :: ~D()
{
	cout<<"\n ~D()";
}


void D :: disp()
{
	cout<<"\n "<< x << " + " << y << " + " << z << " = " <<m;//no ambiguity
}


int main()
{
	D objD(1,2,3);
	objD.disp();		
	return 0;
}

