#include <iostream>
using namespace std;
/*
------------------------------------------
Return By Value

When a function is designed to return a 
local object/variable then it has to 
return an object/variable that is marked 
for destruction.

So system 
1) makes a copy of the local object/variable
2) destroys the local object/variable
3) returns the copy
4) after return is received at place of call, destroys the copy.

This approach to returning object/variable 
is called as "return by value".
------------------------------------------

Return By Reference

A function may be designed to return a 
reference to a non local object/variable.
Such a case is of "Return By Reference". 

In such as case system has to return 
the original object/variable and not 
its copy as in case of "Return By Value".

*/

class Myclass
{
	int x, y;
	public:
		Myclass();
		Myclass(Myclass &);
		~Myclass();
		void increment();
		void disp();
};

Myclass :: Myclass()
{
	x = 10;
	y = 20;
}

Myclass :: Myclass(Myclass & r)//copy constructor
{
	cout<<"\n Myclass(Myclass &) ";
	cout<<"\n source object "<<&r;
	cout<<"\n new object "<<this;
		
	x = r.x;
	y = r.y;
}

Myclass :: ~Myclass()
{
	cout<<"\n Destructing "<< this;
}

void Myclass :: increment()
{
	x++;
	y++;
}

void Myclass :: disp()
{
	cout<<"\n"<<x<<"  "<<y;
}

Myclass f1() //return by value
{
	Myclass obj;
	cout<<"\n in f1 &obj : "<<&obj;
	obj.increment();
	obj.increment();
	obj.increment();
	obj.disp();
	return obj;
}


Myclass & f2(Myclass &r)//return by reference
{
	cout<<"\n in f2 &r : "<<&r;
	r.increment();
	r.increment();
	r.increment();
	r.disp();
	return r;
}

int main()
{
	Myclass m1;
	Myclass m2;
	
	cout<<"\n in main &m1 : "<<&m1;
	cout<<"\n in main &m2 : "<<&m2;

	cout<<"\n ------ Return By Value ------";
	m1.disp();
	m1 = f1();
	m1.disp();

	cout<<"\n ------ Return By Reference ------";
	m2.disp();
	m2 = f2(m1);
	m2.disp();
	cout<<"\n ---------------------------------";
	return 0;
}