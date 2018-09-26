#include <iostream>
using namespace std;

/*
Dynamic Memory Management

Memory management includes
1) Memory Allocation
2) Memory Usage
3) Memory Deallocation

Memory can be managed by
1) System
2) Program (Code)

System managed memory includes
all variable/array/etc declarations.
Examples
	int i;
	Myclass m;
	double arr[3];
	etc

Program managed memory includes the
memory blocks (arrays/objects) that
are dynamically (at execution time)
allocated using "new" operator.

Such memory blocks are created in
the heap segment of RAM.

These can be used through their address.

As their usage is complete code must
dynamically deallocate them using
"delete" operator.

*/

class Myclass
{
private:
	int a, b;
public:
	Myclass();//default constructor
	Myclass(int,int);//parameterized constructor
	~Myclass();//destructor
	void disp();//member function
};

//this pointer contains address of the
//caller object of the member function

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

void Myclass :: disp()
{
	cout<<"\n"<<a<<"  "<<b;
}


Myclass :: ~Myclass()
{
	cout<<"\n Destructing "<<this;
}


int main()//prg starts here
{
	Myclass m(1,2);//Myclass object (system managed memory block)
	Myclass *p;//Myclass pointer, can be used to store address of object of Myclass
	//p = new Myclass();//dynamically created Myclass Object (program managed memory block)	
	p = new Myclass(11,22);//dynamically created Myclass Object (program managed memory block)

	m.disp();//caller obj is m
	p->disp();//caller obj is the one adderss of which is stored in p	
	
	delete p;//deallocate dynamically created object
	return 0;
}