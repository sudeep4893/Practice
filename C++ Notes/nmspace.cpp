#include<iostream>

/*
namespace
-----------
A namespace defines a declarative region
that may contain variables, functions,
classes, etc.
A namespace localizes its contents and
prevents name conflicts.

To define a namespace
------------------------
namespace <AName>
{
	vars
	fns
	classes
}

To access the members of a namespace
---------------------------------------
syntax :	nmspc::member

example		AName::f()
		AName::Myclass
		AName::x

--------------------------------------------
C++ defines its library (all classes /functions /etc)
in a namespace named as "std".

So after including the C++ library we can
access the members as
		std::SomeClass
		std::SomeFn
		std::SomeVar
			
If members of a namespace are frequently
used then we can make that namespace as
the default namespace through the statement
"using".

Example
		using namespace std;

Now all use of classes/fns/vars/etc
we default map with namespace std.

*/
using namespace std;

namespace my
{
	int x = 1000;
	
	void f()
	{
		cout<<"\n f() that belongs to namespace my";
	}
}

int x = 100; //global var

void f()
{
	cout<<"\n global fn f()";
}

int main()
{
	f();//maps with global f that belongs to systems global namespace
	my::f();//maps with f that belongs to namespace my	

	int x = 10;

	cout<<"\n"<<x;//maps with local x
	cout<<"\n"<<::x;//maps with global x that belongs to systems global namespace
	cout<<"\n"<<my::x;//maps with x that belongs to namespace my	
	
	return 0;
}