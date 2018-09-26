#include<stdio.h>
#include<conio.h>
#define SIZE 5
/*
	Stack Using Array

A stack is a linear data structure
that allows insertion and extraction
of data from one common end, called
as top of stack.

As insertion and extraction of
data is from a common end and
because of using linear storage
the element that goes in last
comes out first (LIFO).
-------------------------------

Operations on Stack

1) push
Add a val into the stack.
The val is added at the topmost position.

2) pop
remove and return the topmost
val from the stack.

generally return 0 when stack
becomes empty

3) peek
fetch(donot remove) and return the topmost
val from the stack.

generally return 0 when stack
becomes empty

4) disp
print the content of the stack
from top to bottom

5) isFull
returns isfull state (true/false)
for the stack

6) isEmpty
returns isempty state (true/false)
for the stack

7) init
clear the garbage value in top of stack

this is always done by assigning
-1 to the top

*/

struct Stack
{
	int data[SIZE]; //hold information
	int top; //index upto which array is filled. Also it is the entry and exit point.
};

typedef struct Stack Stack;


void init(Stack *p)
{
	p->top= -1;
}

int isFull(Stack *p)
{
	if(p->top == SIZE -1)
		return 1; //true
	else
		return 0;//false
}

void push(Stack *p, int val)
{
	if(! isFull(p))
	{
		p->top++;
		p->data[p->top] = val;
	}
	else
	{
		printf("\n Stack Overflow");
	}
}//push

void disp(Stack *p)
{
	int i;
	for(i = p->top; i >=0; i--)
	{
		printf("\n %d", p->data[i]);
	}
}

int isEmpty(Stack *p)
{
	if(p->top == -1)
		return 1; //true
	else
		return 0;//false
}

int pop(Stack *p)//rem and return topmost val
{
	int val = 0;
	if(! isEmpty(p))
	{
		val = p->data[p->top];
		p->top--;
	}
	else
	{
		printf("\n Stack Underflow");
	}
	return val;
}

int peek(Stack *p)//fetch (donot remove) and return topmost val
{
	int val = 0;
	if(! isEmpty(p))
	{
		val = p->data[p->top];
	}
	else
	{
		printf("\n Stack Underflow");
	}
	return val;
}

void main()
{
	Stack s;
	int ch, x;
	clrscr();

	init(&s);//pass by ref

	do
	{
		printf("\n 1. push ");
		printf("\n 2. pop ");
		printf("\n 3. peek ");
		printf("\n 4. disp ");
		printf("\n 5. exit ");
		printf("\n enter choice ");
		scanf("%d", &ch);

		switch(ch)
		{
			case 1:
				printf("\n enter val to push ");
				scanf("%d", &x);
				push(&s, x);
				break;
			case 2:
				x = pop(&s);
				printf("\n %d removed ", x);
				break;
			case 3:
				x = peek(&s);
				printf("\n %d at top of stack ", x);
				break;
			case 4:
				disp(&s);
				break;
		}
	}while(ch != 5);
}//main
