#include <iostream>
using namespace std;

/*
There are cases when system needs to
create a copy of an object of a class.

Example:
	When object is passed by value to a fn
	When object is returned by value from a fn
	
To create copy of an object system
uses "bit by bit copy" method
(also called as "memory copy" method).

In this method system reads the
complete memory block of the source
object and writes the same into the
memory block of the target object.

But this method is a "shallow copy" method.

If systems approach to copy an object
is not appropriate for an application
then the application must have its
own logic to copy its objects.

Such a logic to create copy of an object
is defined in the "Copy Constructor".

---------------------------------------
"Copy Constructor" is a special 
constructor of the class that

1) contains logic to create copy
of an object.
2) takes one parameter that is
object of the same class by reference.

*/

class Myclass
{
private:
	int a, b;
public:
	Myclass();//default constructor
	Myclass(int,int);//parameterized constructor
	Myclass(Myclass &);//copy constructor

	~Myclass();//destructor
	void disp();//member function

};

Myclass :: Myclass()//default constructor
{
	cout<<"\n Myclass() "<<this;
	a = 10;
	b = 20;
}

Myclass :: Myclass(int q, int w)//parameterized constructor
{
	cout<<"\n Myclass(int,int) "<<this;
	a = q;
	b = w;
}

Myclass :: Myclass(Myclass & r)//copy constructor
{//to initailize current object with the parameter object
	cout<<"\n Myclass(Myclass &) "<<this;
	a = r.a ; //+ 5;
	b = r.b ; //+ 5;
}

void Myclass :: disp()
{
	cout<<"\n"<<a<<"  "<<b;
}


Myclass :: ~Myclass()
{
	cout<<"\n Destructing "<<this;
}

void f(Myclass obj)//rcv obj as param (rcv by value)
{
	obj.disp();
}

int main()//prg starts here
{
	Myclass m(8,16);
	cout<<"\n================";
	f(m);//pass obj as param
	cout<<"\n================";
	return 0;
}