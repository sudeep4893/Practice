#include <iostream>
#include <stdlib.h>
using namespace std;

/*
new and delete are operators used for
dynamic memory allocation and deallocation 
respectively.

System has default definitions of 
"operator new" and "operator delete" 
for class objects.

But still we are allowed to overload
these operators for customized memory
management.

These operators take the following signatures :
	
void * operator new (size_t size);
void operator delete(void * p);	

*/

class Memory
{
	private :
	int x, y;
	
	public:
		Memory();//default constructor
		Memory(int,int);//parameterized constructor
		~Memory();//destructor	
		void disp();//member function
		
		//overload new and delete operator
		void * operator new (size_t size);
		void operator delete(void * p);	

};

Memory ::Memory()
{
	cout<<"\n Memory() "<<this;
	x = 10;
	y = 20;
}

Memory ::Memory(int q, int w)
{
	cout<<"\n Memory(int,int) "<<this;
	x = q;
	y = w;
}

Memory ::~Memory()
{
	cout<<"\n Destructing "<<this;
}

void Memory ::disp()
{
	cout<<"\n "<<x<<"  "<<y;
}

void * Memory :: operator new (size_t size)
{
	cout<<"\n memory allocation operation starts ";
	
	void *p;
	p = malloc(size);//allocate a block of size bytes
	
	cout<<"\n memory allocation operation done ";
	
	return p;//return the starting address of the memory block
}

void Memory :: operator delete(void * p)
{
	cout<<"\n memory deallocation operation starts ";
	free(p);
	cout<<"\n memory deallocation operation done ";
}


int main()
{
	Memory *p;//a pointer of class memory
	
	p = new Memory(50,60); //dyn object creation using new
	p->disp();//access members of the class
	delete p;//destructing the dyn created object

	return 0;
}