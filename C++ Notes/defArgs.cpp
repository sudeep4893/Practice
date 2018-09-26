#include <iostream>
using namespace std;

/*
Default Values For Formal Parameters Of Functions

C++ supports assignment of default
values to the formal parameters of
functions.
This allows calls to the function
with less number of actual parameters.

The default values are used only
if the function is called with
less number of actual parameters.

If a formal parameter is assigned
a default value then all the 
following parameters must also be
assigned default values.

One must use default values for
formal parameters of a function 
only when the logic of the function
supports calls with lesser parameters
and the default value assigned doesnt
put any adverse affect on the results.

*/

void add(int a , int b=0, int c=0)
{
	int tot;
	tot = a + b+ c;
	cout<<"\n Addition : "<<tot;
}//add

int main()
{
	add(5);//1 actual parameter
	add(11,22);//2 actual parameters;
	add(10,20,30);//3 actual parameters
	return 0;
}