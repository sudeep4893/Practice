#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

/*
	Queue Using Linked List

A queue is a linear data structure
that allows insertion and extraction
of data from two diff ends, called
as "rear" and "front" of queue,
repectively.

As insertion and extraction of
data is from a diff ends and
because of using linear storage
the element that goes in first
comes out first (FIFO).
-------------------------------

Operations on Queue

1) addQ
Add a val into the queue.
The val is added at the rearmost
position.

2) delQ
remove and return the forntmost
val from the queue.

generally return 0 when queue
becomes empty

3) qfront
fetch(donot remove) and return
the front most val from the queue.

generally return 0 when queue
becomes empty

4) qrear
fetch(donot remove) and return
the rear most val from the queue.

generally return 0 when queue
becomes empty

5) disp
print the content of the queue
from front to rear

6) isFull
returns isfull state (true/false)
for the queue

6) isEmpty
returns isempty state (true/false)
for the queue

7) init
clear the garbage value in front
and rear of queue.

this is always done by assigning
NULL to the rear and front

*/

struct node
{
	int data;
	struct node *next;
};
typedef struct node node;

struct Queue
{
	node * front;//for data extraction
	node * rear;//for data insertion
};
typedef struct Queue Queue;

//clear garbage by assigning NULL to top of stack
void init(Queue *p)
{
	p->front = NULL;
	p->rear = NULL;
}

//add a val into q
//as q is made using linked list
//so add a val in linked list
//i.e. add a val in a node

void addQ(Queue *p, int val)
{
	node *n;

	//create a node
	n = (node *) malloc(sizeof(node));

	if(n != NULL)
	{
		//init the node
		n->data = val;
		n->next = NULL;

		//connect
		if(p->front == NULL)
		{//first node
			p->rear = n;
			p->front = n;
		}
		else
		{//rest of the nodes
			p->rear->next = n;
			p->rear = n;
		}
	}
	else
	{
		printf("\n Q Overflow");
	}

}//addQ

void disp(Queue *p)
{
	node *x;
	printf("\n");

	x = p->front;
	while(x != NULL)
	{
		printf(" %d ", x->data);
		x = x->next;
	}
}//disp

//return true/false as per the empty state of the q
int isEmpty(Queue *p)
{
	if(p->front == NULL)
		return 1; //true
	else
		return 0; //false
}

//return the data at front end of q
int qFront(Queue *p)
{
	int val = 0;
	node *x;

	if(! isEmpty(p))
	{
		//grab the node at front end of q
		x = p->front;
		//fetch its data
		val = x->data;
	}
	else
	{
		printf("\n Q Underflow");
	}

	return val;
}//qFront

//return the data at rear end of q
int qRear(Queue *p)
{
	int val = 0;
	node *x;

	if(! isEmpty(p))
	{
		//grab the node at rear end of q
		x = p->rear;
		//fetch its data
		val = x->data;
	}
	else
	{
		printf("\n Q Underflow");
	}

	return val;
}//qRear

//remove a val from q
//i.e. remove a val from linked list
//i.e. remove a node
//node at front end is removed and its val is returned

int delQ(Queue *p)
{
	int val = 0;
	node *x;

	if(! isEmpty(p))
	{
		//grab the node at front
		x = p->front;
		//fetch its val
		val = x->data;
		//reset q front
		p->front = x->next;
		//free the node
		free(x);

	}
	else
	{
		printf("\n Q Underflow");
	}

	return val;
}

void main()
{
	Queue q;
	int ch, x;
	clrscr();

	init(&q);//pass by ref

	do
	{
		printf("\n 1. addQ ");
		printf("\n 2. delQ ");
		printf("\n 3. qFront ");
		printf("\n 4. qRear ");
		printf("\n 5. disp ");
		printf("\n 6. exit ");
		printf("\n enter choice ");
		scanf("%d", &ch);

		switch(ch)
		{
			case 1:
				printf("\n enter val to add in q  ");
				scanf("%d", &x);
				addQ(&q, x);
				break;
			case 2:
				x = delQ(&q);
				printf("\n %d removed ", x);
				break;
			case 3:
				x = qFront(&q);
				printf("\n %d at front of Q ", x);
				break;
			case 4:
				x = qRear(&q);
				printf("\n %d at rear of Q ", x);
				break;
			case 5:
				disp(&q);
				break;
		}
	}while(ch != 6);
}//main

