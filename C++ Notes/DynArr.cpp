#include <iostream>
using namespace std;

/*
Dynamic Array

*/

class DynArr
{
	private:
		
		int size;  //mem var
		int *data; //mem pointer
		
	public:
		DynArr();//default constructor
		DynArr(int);//parameterized constructor
		DynArr(DynArr &);//copy constructor
		~DynArr();//destructor
		
		void set();//mem fn
		void disp();//mem fn
		
		friend void increment(DynArr obj);

};//DynArr

DynArr :: DynArr()//default constructor
{
	size = 5;
	
	//here constructor is allocating
	//memory block (array) and making
	//mem pointer "data" to refer to it.
	
	data = new int[size];
	set();
}

DynArr :: DynArr(int q)//parameterized constructor
{
	size = q;
	
	//here constructor is allocating
	//memory block (array) and making
	//mem pointer "data" to refer to it.
	
	data = new int[size];
	set();
}

DynArr :: DynArr(DynArr &r)//copy constructor
{
	
	size = r.size;
	data = new int[size];
	
	int i;
	for(i =0; i< size; i++)
		data[i] = r.data[i];
	
}


DynArr ::~DynArr()//destructor
{
	//here destructor is used to
	//deallocate the memory block
	//(array) allocted by the constructor.
	
	cout<<"\n Destructing "<<data;
	delete data;
}

void DynArr :: set()
{
	int i;
	cout<<"\n enter "<<size<<" numbers ";
	for(i =0; i< size; i++)
		cin>>data[i];	
}

void DynArr :: disp()
{
	int i;
	cout<<"\n data is at location : "<<data;
	cout<<"\n ";
	for(i =0; i< size; i++)
		cout<<data[i]<<" ";	
}

void increment(DynArr obj)//non member function receives object of class DynArr as a formal parameter
{
	int i;
	for(i =0; i< obj.size; i++)
		obj.data[i]++;
		
	obj.disp();
}

int main()//prg starts here
{
	DynArr d;
	d.disp();
	cout<<"\n=================";
	increment(d);//call to non member fn with object d as actual parameter
	cout<<"\n=================";
	d.disp();
	return 0;
}