#include <iostream>
using namespace std;

/*
Type Compatibility
-------------------
Inheritance creates "type compatibility"
between the base and the derived class.

Type compatibility allows a base class
reference/pointer to refer to an object
of derived class.
Reverse is not true.

A pointer/reference of base class that
refers to an object of derived class
can be used to access
1) inherited members
2) overridden members

Members newly defined by the derived
class are not accessible using base
class pointer/reference.

*/

class A
{
	public:
		void f1();
		void f2();
};

void A :: f1()
{
	cout<<"\n A f1()";
}

void A :: f2()
{
	cout<<"\n A f2()";
}

class B : public A
{
	public:
		void f2();
		void f3();
};

void B :: f2()
{
	cout<<"\n B f2()";
}

void B :: f3()
{
	cout<<"\n B f3()";
}

int main()
{
	A *ptrA;//pointer A
	B objB;//object of B;
	
	ptrA = &objB;//type compatibility
	
	ptrA->f1();//inherited member
	ptrA->f2();//overridden member
	//ptrA->f3();//new member of derived class
	
	return 0;
}