#include <iostream>
using namespace std;

/*
Int Stack
*/

#define SIZE 10
class Stack
{
	int data[SIZE];
	int top;
	
	public:
		Stack();
		void push(int);
		int pop();
		void disp();
};

Stack :: Stack()
{
	top = -1;
}

void Stack :: push(int val)
{
	if(top != SIZE -1)
	{
		top++;
		data[top]= val;
	}
	else
		cout<<"\n Stack Is FULL";
}

int Stack :: pop()
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

void Stack :: disp()
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
	Stack s;
	s.push(10);		
	s.push(20);
	s.push(30);
	s.push(40);
	
	s.disp();
	
	cout<<"\n"<<s.pop()<<" removed from stack";

	return 0;
}

