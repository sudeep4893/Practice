#include <iostream>
using namespace std;

class Clock
{
 public://discuss later
 
 	//member variables
	int h, m, s;	
	
	//member functions
	void setTime(int x, int y, int z)	
	{
		cout<<"\n in setTime : this "<<this;
		
		h = x;
		m = y;
		s = z;		
	}
	
	void dispTime()
	{
		cout<<"\n"<<h<<":"<<m<<":"<<s;
	}
};


//non member function
int main()//prg starts here
{
	//create object of the class
	Clock c;

	cout<<"\n in main : &c "<<&c;
	
	//An object is used to access
	//member variables and member
	//functions of the class
	
	c.setTime(1,2,3);
	c.dispTime();
	
	return 0;
}

/*
Explain member function calling process.

A non static member function is a function that
belongs to a class.
It can only be called using object
of the class.

As a non static member function is called 
then system internally automatically

1)Passes address of the caller object
as a hidden actual parameter to the
member function.

2)Receives address of the caller object
in a hidden formal parameter called
as "this" pointer.

3)Uses "this" pointer as the caller object
for other members used in the function.

--------------------------------------------------
"this" pointer

"this" pointer is a system defined
formal parameter for member functions
of the class.

It receives address of the caller
object of the function.

It is automatically used as a caller
object for other members in the function.

Its datatype is "current class".

It is a constant pointer and cannot
be modified.
*/