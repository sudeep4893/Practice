#include <iostream>
using namespace std;
/*
Destructor

A destructor is a special member
function.

It has 
1) the same name as of the class preceeded by a ~
2) no return type specification
3) no parameters (parameterless and hence cannot be overloaded)

It is called automatically by the system
as life of the object gets over.

It cannot be explicitly called.

It is used to deallocate the resources
(memory, files, connections, ...) opened
and used by the object.

----------------------------------------

If we donot define a destructor
for a class then system auto defines
a default destructor with empty
definition.

~Myclass()
{}

Because a destructor call is 
required before object deallocation.

*/



class Myclass
{
	public://discuss later
	int x, y;

	Myclass()//default constructor
	{
		cout<<"\n Myclass()";
		x = 10;//init x
		y = 20;//init y
	}
	
	Myclass(int q, int w)//parameterized constructor
	{
		cout<<"\n Myclass(int, int)";
		x = q;//init x
		y = w;//init y
	}

	~Myclass()//destructor
	{
		cout<<"\n Destructing ";
	}
	
	void disp()
	{
		cout<<"\n"<<x<<"  "<<y;
	}
};

void f()
{
	Myclass m2(11,22);
	m2.disp();
}

int main()
{
	Myclass m1;
	m1.disp();
	cout<<"\n--------------";
	f();
	cout<<"\n--------------";
	return 0;	
}//main

