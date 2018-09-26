#include <iostream>
using namespace std;

/*
Compile Time Binding
----------------------
It is the role of compiler to bind a
function call with the functions definition.

For this compiler matches
1) name
2) arguments
used in the function call with those of
functions definition.

If match is not found then compiler raises
errors.
Otherwise it binds the function call with
the functions definition.

As the binding is done by the compiler
so it is referred as "compile time binding"
or "early binding".

Normal function calls, constructor invokations,
function overloading, constructor overloading,
operator overloading, ... are resolved by
compile time binding.

---------------------------------------------

Runtime Binding
-----------------

Consider a case when code uses
1) Inheritance
2) Function overriding with base class function declared as "virtual"
3) Base class reference/pointer used for overridden function calls.

* Function Overriding makes available 
multiple functions of same signature.

* A base class reference/pointer may refer
to an object of base class or to an object
of derived class.

* Referencing may be a runtime process.

Due to above points compiler is not able
to determine the object being refered by
the base class pointer and is not able to
bind the function call with the correct 
function definition.

Hence compiler doesnt bind calls to 
overridden functions using base class
pointers.
It will only authenticate the call.

At program runtime system detects the
"type of object" being referred by the
base class pointer.
And maps the call to overridden function
with the definition provided by the
class of the object.

Such a process of binding a call to 
overridden function with correct definition
is called as "runtime binding" or
"late binding".


Note:
To activate runtime binding for a function
the base class version of that function
must be declared as "virtual".
	
virtual attribute allows a derived class
object to execute its definition of an
overridden function when called using a
base class reference/pointer.
	
*/

class A
{
	public:
		A();
		virtual ~A();
		void f1();
		virtual void f2();
};

A :: A()
{
	cout<<"\n A()";
}

A :: ~A()
{
	cout<<"\n ~A()";
}

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
		B();
		~B();
		void f2();
		void f3();
};

B :: B()
{
	cout<<"\n B()";
}

B :: ~B()
{
	cout<<"\n ~B()";
}

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
	
	cout<<"\n 1. object of base ";
	cout<<"\n 2. object of derived ";
	cout<<"\n enter choice ";
	int ch;
	cin>>ch;
	
	if(ch == 1)
		ptrA = new A();//object and pointer are of same class
	else if(ch == 2)
		ptrA = new B();//object of derived and pointer of base class
	else
	{
		cout<<"\n invalid choice ";
		return 0; //terminate main
	}


	ptrA->f1();//inherited member
	ptrA->f2();//overridden member
	//ptrA->f3();//new member of derived class

	delete ptrA; //destroy the object	
	return 0;
}


/*
virtual destructor
-------------------

A virtual base class destructor ensures 
execution of destructors of derived and
base classes both, when a dynamically
created object of derived class is deleted
using a base class pointer.


*/