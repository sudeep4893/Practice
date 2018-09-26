#include <iostream>
using namespace std;

/*
Generic Class

A generic class is a collection of generic code 
and generic or non generic data.

Representation
-----------------
class{code, data};
genericClass{generic code, generic data, data};

*/

#define SIZE 10

template <class X> class Stack
{
		X data[SIZE];//generic data
		int top;//non generic data
	public:
	//fns must be generic functions
		Stack();
		void push(X);
		X pop();
		void disp();
};

template<class X> Stack<X> :: Stack()
{
	top = -1;
}

//void push(int val) //normal fn
//template<class X> void push(X val) //generic fn
template<class X> void Stack<X> :: push(X val) //generic mem fn
{
	if(top != SIZE -1)
	{
		top++;
		data[top]= val;
	}
	else
		cout<<"\n Stack Is FULL";
}

template<class X> X Stack<X> ::pop()
{
	int val = 0;
	if(top != -1)
	{
		val = data[top];
		top--;
	}
	else
		cout<<"\n Stack is EMPTY";
		
	return val;
}

template<class X> void Stack<X> ::disp()
{
	if(top != -1)
	{
		int i;
		for(i = top; i>=0; i--)
			cout<<"\n"<<data[i];
	}
	else
		cout<<"\n Stack is EMPTY";
}

int main()
{
	Stack <int> s;
	s.push(10);		
	s.push(20);
	s.push(30);
	s.push(40);
	
	s.disp();
	
	cout<<"\n"<<s.pop()<<" removed from stack";

	Stack <char> s1;
	s1.push('q');		
	s1.push('w');
	s1.push('e');
	s1.push('r');
	s1.push('t');
	
	s1.disp();
	
	cout<<"\n"<<s1.pop()<<" removed from stack";

	return 0;
}

