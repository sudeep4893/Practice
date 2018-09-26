#include<stdio.h>
#include<conio.h>
#include<math.h>
#define SIZE 100

struct Stack
{
	char data[SIZE]; //hold information
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

void push(Stack *p, char val)
{
	if(! isFull(p))
	{
		p->top++;
		p->data[p->top] = val;
	}
}//push

int isEmpty(Stack *p)
{
	if(p->top == -1)
		return 1; //true
	else
		return 0;//false
}

char pop(Stack *p)//rem and return topmost val
{
	char val = ' ';
	if(! isEmpty(p))
	{
		val = p->data[p->top];
		p->top--;
	}
	return val;
}

char peek(Stack *p)//return topmost val
{
	char val = ' ';
	if(! isEmpty(p))
	{
		val = p->data[p->top];
	}
	return val;
}
//---------------------------
struct EStack
{
	float data[SIZE]; //hold information
	int top; //index upto which array is filled. Also it is the entry and exit point.
};
typedef struct EStack EStack;

void einit(EStack *p)
{
	p->top= -1;
}

int eisFull(EStack *p)
{
	if(p->top == SIZE -1)
		return 1; //true
	else
		return 0;//false
}

void epush(EStack *p, float val)
{
	if(! eisFull(p))
	{
		p->top++;
		p->data[p->top] = val;
	}
}//push

int eisEmpty(EStack *p)
{
	if(p->top == -1)
		return 1; //true
	else
		return 0;//false
}

float epop(EStack *p)//rem and return topmost val
{
	float val = 0;
	if(! eisEmpty(p))
	{
		val = p->data[p->top];
		p->top--;
	}
	return val;
}

//---------------------------
int priority(char c)
{
	switch(c)
	{
	 case '(' :
		return 4;
	 case '^' :
		return 3;
	 case '*' :
	 case '/' :
		return 2;
	 case '+' :
	 case '-' :
		return 1;
	 case ')' :
		return -1;
	 default ://operands
		return 0;
	}
}

void in2post(char postfix[], char infix[] )
{
	int i,j,iep,isop;
	char iso;

	Stack s;
	init(&s);

	j=0;
	//read the infix
	for(i =0; infix[i]!='\0'; i++)
	{
		iep = priority(infix[i]);

		//know about the in stack operator
		iso = peek(&s);
		isop = priority(iso);

		//decide incoming element is operator or operand
		if(iep == -1)
		{//)
			while(iso != '(')
			{
				//remove an operator
				iso = pop(&s);
				//place it in result
				postfix[j] = iso;
				j++;
				//find the next operator
				iso = peek(&s);
			}
			pop(&s);//to remove (

		}
		else if(iep == 0)
		{//operand
		 //put into the result
		 postfix[j] = infix[i];
		 j++;
		}
		else if(iep > 0)
		{//operators
		 //push into the stack

		 if(isEmpty(&s))
		 {
			push(&s, infix[i]);
		 }
		 else if(iep > isop)
		 {
			push(&s, infix[i]);
		 }
		 else if(iso == '(')
		 {
			push(&s, infix[i]);
		 }
		 else if(infix[i] == '^' && iso == '^')
		 {
			push(&s, infix[i]);
		 }
		 else if(iep <= isop)
		 {

			while(iep <= isop && iso != '(' )
			{
				iso = pop(&s);
				postfix[j] = iso;
				j++;
				//find the next operator
				iso = peek(&s);
				isop = priority(iso);
			}//while
			//push in incoming operator
			push(&s, infix[i]);
		 }

		}
	}//for

	//expression traversal is complete
	//pop out all remaining operators
	//and place them in result

	while(!isEmpty(&s))
	{
		iso = pop(&s);
		postfix[j] = iso;
		j++;
	}

	//terminate the resultant string
	postfix[j] = '\0';

}//in2post


float solve(char op, float n1, float n2)
{
	switch(op)
	{
		case '+':
			return n1 + n2;
		case '-':
			return n1 - n2;
		case '*':
			return n1 * n2;
		case '/':
			return n1 / n2;
		case '^':
			return pow(n1, n2);
		default :
			return 0;
	}
}//solve

float eval(char postfix[])
{
	int i;
	int iep;
	float n1, n2, x;

	EStack es;
	einit(&es);

	for(i =0; postfix[i]!='\0'; i++)
	{
		iep = priority(postfix[i]);
		if(iep == 0)
		{//operand
			printf("\n enter value for %c ", postfix[i]);
			scanf("%f", &x);
			epush(&es, x);
		}
		else
		{//operator
			n2 = epop(&es);
			n1 = epop(&es);
			x = solve(postfix[i], n1, n2);
			epush(&es, x);
		}
	}//for
	x = epop(&es);
	return x;
}

void main()
{
	char infix[SIZE], postfix[SIZE];
	float ans;

	clrscr();
	printf("\n enter infix expression ");
	flushall();
	scanf("%s", infix);

	in2post(postfix, infix);

	printf("\n postfix equivalent : %s", postfix);

	ans = eval(postfix);
	printf("\n ans : %f", ans);

}//main