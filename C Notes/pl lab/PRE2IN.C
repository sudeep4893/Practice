#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#define SIZE 100

struct OStack
{
	char data[SIZE][SIZE]; //hold information (strings)
	int top; //index upto which array is filled. Also it is the entry and exit point.
};
typedef struct OStack OStack;

void oinit(OStack *p)
{
	p->top= -1;
}

int oisFull(OStack *p)
{
	if(p->top == SIZE -1)
		return 1; //true
	else
		return 0;//false
}

void opush(OStack *p, char val[])
{
	if(! oisFull(p))
	{
		p->top++;
		//p->data[p->top] = val;
		strcpy(p->data[p->top],val);
	}
}//push

int oisEmpty(OStack *p)
{
	if(p->top == -1)
		return 1; //true
	else
		return 0;//false
}

char* opop(OStack *p)//rem and return topmost val
{
	char val[SIZE] = " ";
	if(! oisEmpty(p))
	{
		//val = p->data[p->top];
		strcpy(val, p->data[p->top]);
		p->top--;
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

//--------------------------

int priority(char c)
{
	switch(c)
	{
	 case '^' :
		return 3;
	 case '*' :
	 case '/' :
		return 2;
	 case '+' :
	 case '-' :
		return 1;
	 default ://operands
		return 0;
	}
}

void pre2in(char infix[], char prefix[])
{
	int iep;
	int i;
	char result[SIZE];
	char opnd1[SIZE];
	char opnd2[SIZE];

	OStack os;
	oinit(&os);

	for(i =strlen(prefix)-1; i >=0; i--)
	{
		iep = priority(prefix[i]);

		if(iep == 0)
		{//operand
			sprintf(result, "%c", prefix[i]);
			opush(&os, result);
		}
		else
		{//operator
			//opnd1 = opop(&os);
			strcpy(opnd1,opop(&os));

			//opnd2 = opop(&os);
			strcpy(opnd2,opop(&os));

			sprintf(result, "( %s%c%s )", opnd1,prefix[i], opnd2);

			opush(&os, result);
		}
	}//for

	//infix = opop(&os);
	strcpy(infix,opop(&os));
}//pre2in

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

float eval(char prefix[])
{
	int i;
	int iep;
	float n1, n2, x;

	EStack es;
	einit(&es);

	//for(i =0; postfix[i]!='\0'; i++)
	for(i = strlen(prefix)-1; i>=0; i--)
	{
		iep = priority(prefix[i]);
		if(iep == 0)
		{//operand
			printf("\n enter value for %c ", prefix[i]);
			scanf("%f", &x);
			epush(&es, x);
		}
		else
		{//operator
			n1 = epop(&es);
			n2 = epop(&es);
			x = solve(prefix[i], n1, n2);
			epush(&es, x);
		}
	}//for
	x = epop(&es);
	return x;
}

void main()
{
	char infix[SIZE], prefix[SIZE];
	float ans;

	clrscr();
	printf("\n enter prefix expression ");
	flushall();
	scanf("%s", prefix);

	pre2in(infix, prefix);

	printf("\n infix equivalent : %s", infix);

	ans = eval(prefix);
	printf("\n ans : %f", ans);

}//main