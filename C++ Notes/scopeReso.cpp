#include <iostream>
using namespace std;
/*
In C++ a class contains declartions of 
the member variables and member functions.
Their definitions must be provided
outside the class.

As a member function is defined outside
the class, so it resembles a non-member
function.

For a differentiation between a
non-member function and a member
function defined outside the class,
the signature of member function
is modified to contain 
1) class name
2) scope resolution operator (::)
between the return type and the
function name.

signature of member function
-----------------------------
returnType className :: fnName(params)
{}


signature of non-member function
-----------------------------
returnType fnName(params)
{}

*/

class Myclass
{
	public://discuss later
	int x, y;//member variables

	Myclass();//default constructor
	Myclass(int q, int w);//parameterized constructor
	~Myclass();//destructor
	void disp();//member function
};

//defintions of members functions

Myclass :: Myclass()//default constructor
{
	cout<<"\n Myclass()";
	x = 1;
	y = 2;
}

Myclass ::Myclass(int q, int w)//parameterized constructor
{
	cout<<"\n Myclass(int,int)";
	x = q;
	y = w;

}

Myclass :: ~Myclass()//destructor
{
	cout<<"\n Destructing Myclass Object";
}

void Myclass :: disp()
{
	cout<<"\n"<<x<<" "<<y;
}

int main()
{
	Myclass m;
	m.disp();
	return 0;	
}//main

