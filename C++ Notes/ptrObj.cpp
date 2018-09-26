#include <iostream>
using namespace std;
/*
A class is a group of variables 
and functions.
It represents a new secondary datatype
in C++.

It can be used by
1) creating objects
      className objName;
      
2) creating pointers
      className *ptrName; 
      
3) creating arrays
      className arrName[arrSize]; 

Further the three (object/pointer/array)
are used to access members (variables
and functions) of the class.

--------------------------------------------------
Pointer of class type

As we define pointers of primary
datatypes similarly we can define
pointers of class type.

example
	int *p;
	Myclass *p;

A pointer of class type is used to
store address of object of the class.	

example
	Myclass obj;
	Myclass *p;
	p = &obj;
	
Next the pointer to object can be
used to access the members of the
class.

example
	p->x=...
	p->y=...
	p->disp();
	
In such a case the caller object
for the member is the one address
of which is stored in pointer.	

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
	
	void disp()
	{
		cout<<"\n"<<x<<"  "<<y;
	}
};

int main()
{
	//create object of Myclass
	Myclass m;
	
	//create pointer of Myclass
	Myclass *p;
	
	//initialize the pointer with address of the object
	p = &m;	

    //test
    cout<<"\n---------------------";
    cout<<"\n &m : "<<&m;
    cout<<"\n p : "<<p;
    cout<<"\n---------------------";
	
	//access members of Myclass using pointer of Myclass
	p->disp();//same as m.disp();
	
	return 0;	
}//main

