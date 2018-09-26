#include <iostream>
#include <stdlib.h>
using namespace std;

/*
Inheritance
------------

Definition
-----------
Inheritance is the mechanism by which a class 
gets code (functions) and data (variables, ...) 
from another existing class.

The inherited class is the class that
gives code and data.
It is called as "parent class" or "base class".

The inheriting class is the class that
gets code and data.
It is called as "child class" or "derived class".

Implementation
----------------
: is the operator used for applying inheritance in C++.

syntax
derived class : <access specifier> base class1 , <access specifier> base class2, <access specifier> base class3 , ... 
{
   body of derived class
}

As given in syntax it is clear that 
C++ allows a derived class to have 
multiple base classes.
This is called as "multiple inheritance".

Derived Class Members
-----------------------
It is possible that the derived class defines
its own member variables and functions.

It is also possible for the derived class to
redefine a function that it is inheriting from
a base class. 
Doing so is called as "function overriding".

Definition : Function Overriding
----------------------------------
Function Overriding is redefining a
base class function in the derived class
keeping the functions signature exactly
same.

So derived class has 3 types of member functions
1) inherited member functions (comes from base class)
2) overridden member functions (comes from base class and are redefined by derived class)
3) self defined member functions (new functions of derived class)


And derived class has 2 types of member variables
1) inherited member variables
2) self defined member variables


*/
class A //inherited class / base class / parent class
{
	public:
		void f1();
		void f2();
};

void A :: f1()
{
	cout<<"\n f1 of A ";
}

void A :: f2()
{
	cout<<"\n f2 of A ";
}



class B : public A // inherting class / child class / derived class
{
	public:
	void f2();		
  void f3();
};

void B :: f2() //overridden function
{
	cout<<"\n f2 of B "; 
}

void B :: f3()//new function of class B
{
	cout<<"\n f3 of B "; 
}

int main()
{
	B objB;
	objB.f1();//inherited function : fn defn comes from base class A
	objB.f2();//overridden function : fn redefined by class B
	objB.f3();//self defined function : fn defn comes from class B
	return 0;
}