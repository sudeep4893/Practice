#include <iostream>
using namespace std;

/*

By default the private/protected 
members of a class are not accessible 
to non-member functions.

But if a non-member function is
declared as a "friend" function
then it gets the permission to
access all (private/protected/public)
members of a class using object of
the class.


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
 	
	 //declare as friend to grant access of all members
	friend void add();	
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


void add()//a non member function
{
	Myclass obj;
	obj.disp();
	int q;
	q = obj.x + obj.y;//reading (using) private member variables
	cout<<"\n Addition : "<<q;
	
}

int main()
{
	add();//call to non member function

	return 0;	
}//main
