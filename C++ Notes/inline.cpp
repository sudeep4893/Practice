#include<iostream>

using namespace std;

/*
Inline Functions
------------------

C++ supports declaration of member and
non member functions as "inline".

If a function is "inline" then the compiler
expands the functions code at the place
of function call.
It reduces execution time, but increase
size of code.

In this sense it is like a macro.

"inline" declaration is not a command
but a request to the system.

If granted the function will become inline.
If denied the function will act like a 
normal non-inline function.

C++ provides 2 ways to declare a function
as inline

1) declare and define the function in 
the class itself.
2) apply inline keyword to functions definition.

----------------------------------------------
It is said that fns with lot of code,
loops, recursion are not expanded inline.
*/

class IDemo
{
	public:
		IDemo()
		{
			cout<<"\n Inline IDemo Constrcutor";
		}
		
		void fn();
		void fn1();
};

void IDemo ::fn()
{
	cout<<"\n a normal member fn";
}

inline void IDemo ::fn1()
{
	cout<<"\n an inline member fn";
}

int main()
{
	IDemo obj;
	obj.fn();
	obj.fn1();
	return 0;
}