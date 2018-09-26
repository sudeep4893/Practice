#include <iostream>
using namespace std;

/*
Function Overloading
----------------------
Is the mechanism that allows a class/program
to define multiple functions of same name
but with different set of parameters.

Parameters may differ in
1) datatype
2) count
3) sequence

When an overloaded function is called then
compiler matches the signature of the call
with the signature of the definition and
then binds the call with the function body.

Functions are overloaded to represent a
scenario of doing one operation in
multiple ways.

Example
payment(cash)
{ 
	logic to pay by cash 
}
	
payment(cheque)
{ 
	logic to pay by cheque 
}

payment(debitcard)
{ 
	logic to pay by debitcard 
}

*/

void add(int a, int b)
{
	int res;
	res = a + b;
	cout<<"\n "<<res;
	
}

void add(int a, const char str[])
{
	cout<<"\n "<<a<<str;
}


void add(int a, int b, int c)
{
	int res;
	res = a + b + c;
	cout<<"\n "<<res;
	
}

int main()
{
	add(1,2);
	add(1,2,3);
	add(10, "Hello");
	return 0;
}

