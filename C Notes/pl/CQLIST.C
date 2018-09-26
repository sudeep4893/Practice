#include<stdio.h>
#include<stdlib.h>

/*
Circular Queue Using Linked List

A queue is a linear data structure
that allows insertion and extraction
of data from two diff ends, called
as "rear" and "front" of queue, repectively.

As insertion and extraction of
data is from a diff ends and
because of using linear storage
the element that goes in first
comes out first (FIFO).
-------------------------------

Operations on Queue

1) addQ
Adds a val into the queue.
The val is added at the rearmost position.

2) delQ
remove and return the frontmost
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

7) isEmpty
returns isempty state (true/false)
for the queue

8) init
clear the garbage value in front
and rear of queue.

this is always done by assigning
NULL to the rear and front

*/

struct node 
{
    int data;
    struct node * next;
};
typedef struct node node;

struct queue
{
    node * front;//holds address of first node
    node * rear;//holds address of last node
};

typedef struct queue queue;

void init(queue * p)
{
    p->front = NULL;
    p->rear = NULL;
}

void addQ(queue * p, int val)
{
//we know this is a queue using linked list
//we know that a linked list stores its data in nodes
    node * n;
    
    //create
    n = (node*) malloc(sizeof(node));
    if(n != NULL)
    {//malloc success
        //init
        n->data = val;
        n->next = NULL; //will be reset while connection

        //connect
        if(p->front == NULL && p->rear == NULL)
        {//first node
            p->rear = n;
            p->front = n;
            n->next = p->front;//make it circular
        }
        else
        {//successor node, to be added at rear
            p->rear->next = n;
            p->rear = n;
            n->next = p->front;//make it circular
        }
    }
    else
        printf("\n Q is FULL");
        
}


int isEMPTY(queue * p)
{
    if(p->front == NULL && p->rear == NULL)
        return 1; //true
    else
        return 0;//false
}

int qFront(queue *p)
{
    int x = 0;
    if(! isEMPTY(p))
        x = p->front->data;
    else
        printf("\n Q IS EMPTY");
    return x;
}

int qRear(queue *p)
{
    int x = 0;
    if(! isEMPTY(p))
        x = p->rear->data;
    else
        printf("\n Q IS EMPTY");
    return x;
}

void disp(queue *p)
{
    node * i;
    
    if(! isEMPTY(p))
    {
        printf("\n");
        i = p->front;
        do
        {
            printf(" %d", i->data);
            i = i->next;
        }while(i != p->front);
    }
    else
        printf("\n Q is EMPTY");
}


int delQ(queue * p)
{
    int x = 0;
    node * n;
    
    if(! isEMPTY(p))
    {
        if(p->front == p->rear)
        {//only one node
            n = p->front;
            p->front = NULL;
            p->rear = NULL;
            
            x = n->data;
            free(n);
            
        }
        else
        {//multiple nodes in q
        
            n = p->front;
            p->front = n->next;
            x = n->data;//fetch its data
            free(n);//remove the node

            p->rear->next = p->front;//to make it circular
        }
    }
    else
        printf("\n Q is EMPTY");
    return x;
}


int main()
{
    queue q;
    int ch, x;
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
    return 0;
}//main

