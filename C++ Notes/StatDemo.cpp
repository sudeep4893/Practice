#include<iostream>
using namespace std;

/*
static
--------
C++ allows declaration of member variables
and member functions as "static".
By default the member variables and member
functions are "non static".

non static member variables
------------------------------
Member variables of a class are non static
by default.
It means that the variables will be included
as a member of every object of the class.


static member variables
--------------------------
A member variable may be explicitly declared
as "static".
It means that the variable will not be 
included as a member of objects of the 
class.
Instead it is exist alone (one copy) 
independently (not in any object) for 
the class.

non static member functions
------------------------------
Member functions of a class are non static
by default.
It means that 
1) They require a caller object for invokation.
2) "this" pointer is automatically defined and 
   used in non-static member functions. It helps
   in direct access of other non-static members.


static member functions
--------------------------
A member function may be explicitly declared
as "static".
It means that 
1) It can be invoked without any caller object.
2) "this" pointer is not defined and 
   cannot be used in static member functions. 
	 It blocks direct access of other non-static members.

*/


class StatDemo
{
		int x;//non static mem var
		static int y;//static mem var
	public:	
		StatDemo();
		void disp();
		void increment();
		static void decrement(StatDemo &);
		
};
//memory allocation statement for Static member variables
int StatDemo ::y; 

StatDemo :: StatDemo()
{
	x = 10;//this->x = 10;
	y = 20;//StatDemo::y = 20;	
}

void StatDemo :: disp()
{
	cout<<"\n x : "<<x;//this->x
	cout<<"\n y : "<<y;//StatDemo::y
	
	cout<<"\n &x : "<<&x;//&this->x
	cout<<"\n &y : "<<&y;//&StatDemo::y
}

void StatDemo :: increment()
{
	
	x++;//this->x++;
	y++;//StatDemo::y++;
}

//static fn
//no caller object
//no this pointer
//no direct access of non static members
//either donot use non static members
//or provide an object explicitly

void StatDemo :: decrement(StatDemo &r)
{
	r.x--;//r.x--;
	y--;//StatDemo::y--;
}


int main()
{
	StatDemo obj1;
	StatDemo obj2;
	
	obj1.increment();//called using a caller object
  	StatDemo::decrement(obj2);//called without any caller object
  
	obj1.disp();//called using a caller object
	obj2.disp();
	
  	return 0;
}