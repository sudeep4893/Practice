#include <iostream>
using namespace std;
/*
Access Specifiers
are used in classes/structs to
control the accessibility of member
variables and member functions.

C++ supports 3 access specifiers
1) private (default for a class)
2) protected
3) public (default for a struct)

"private" means the member (variable or function)
will be only usable to the members 
of the class.
And will not be accessible to 
1) members of derived class
2) non-members.

"protected" means the member (variable or function)
will be usable to 
1) members of the class. 
2) members of the derived class.

And will not be accessible to non-members.

"public" means the member (variable or function)
will be globally usable by

1) members of the class
2) members of the derived class
3) non-members

With proper use of access specifiers
one can hide crutial data/code
from non members.

----------------------------------
Note
In C++ a struct and a class, both
are group of member variables and
member functions.
Both support OOP.
Both are all similar in their features.
Both can used interchangably.

Only one difference between the
two is in their default access 
specifier.
For a struct it is public.
For a class it is private.


----------------------------------

*/

class Myclass
{
	private: //following members can only be used by other members of the class
	int x, y;//member variables
	
	public: //following members are globally accessible

	Myclass();//default constructor
	Myclass(int q, int w);//parameterized constructor
	~Myclass();//destructor
	void disp();//member function
	
};

//defintions of members functions

Myclass :: Myclass()//default constructor
{
	cout<<"\n Myclass()";
	x = 1; //initializing (using) x
	y = 2; //initializing (using) y
}

Myclass ::Myclass(int q, int w)//parameterized constructor
{
	cout<<"\n Myclass(int,int)";
	x = q;//initializing (using) x
	y = w;//initializing (using) y

}

Myclass :: ~Myclass()//destructor
{
	cout<<"\n Destructing Myclass Object";
}

void Myclass :: disp()
{
	//reading(using) x and y
	cout<<"\n"<<x<<" "<<y;
}

int main()
{
	Myclass m;//invoking (using) public constructor
	m.disp();//invoking (using) public member functhon

	//cannot access private members x and y
	
	//int q;
	//q = m.x + m.y;//reading (using) private member variables
	//cout<<"\n"<<q;
	
	return 0;	
}//main

