#include <iostream>
using namespace std;

int main() 
{
	int x,y;
	
	cout<<"\n enter a number ";
	cin>>x;
	
	y = x*x;
	
	/*
	cout<<"\n square of ";
	cout<<x;
	cout<<" is ";
	cout<<y;
	*/
	
	//cascaded use of << resulting in same as above
	
	cout<<"\n square of "<<x<<" is "<<y;
		
	return 0;
}

/*
A stream is an entity that allows
data transfer.

The stream that carries data from
the keyboard towards the CPU is 
standard input stream (stdin).

"cin" is a predefined object that
fetches data from stdin and transfers
the same in program variable.

For this purpose cin uses extraction
operator ">>".

"cin" is defined in header file
iostream.h


The stream that carries data from
the CPU towards the monitor is 
standard output stream (stdout).

For this purpose cout uses insertion
operator "<<".

"cout" is a predefined object that
fetches data from program and 
transfers the same into stdout.

"cout" is defined in header file
iostream.h


*/