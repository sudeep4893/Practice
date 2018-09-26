#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

/*
Merge 2 lists

tasks :
1st list : sort while creation
2nd list : sort after creation
merge 1st and 2nd and form a final list that is sorted

*/

struct node
{
	int data;//to hold information
	struct node * next;//to hold address of sequentially next node
};

typedef struct node node;

node * screate()//sort and create a linked list
{
	node *n, *h, *p, *q;
	int flag;
	char ch;

	h = NULL;

	do
	{
		//make a node
		n = (node*) malloc(sizeof(node));

		//init the node
		printf("\n enter data for node ");
		scanf("%d", &n->data);
		n->next = NULL;

		//connect the node
		if(h == NULL)
		{
			h = n;//connect as head node
		}
		else
		{//sort and connect
			p = h; //begins with h
			flag = 0;//connection not done

			while(p != NULL)//go upto tail node
			{
				if(n->data < p->data)
				{
					//n will be connected before p
					if(p == h)
					{//i.e n->data < head->data

					 n->next = h;//connect before h
					 h = n;//set n as new head node

					 flag = 1;//connection done
					 break;//stop loop
					}
					else
					{ //n to be connnected between q and p
						q->next = n;
						n->next = p;

						flag = 1;
						break;
					}
				}
				else
				{//n->data >= p->data
					q = p;
					p = p->next;
				}
			}//while

			if(flag == 0)
			{//connection not done yet
			 //this is the case : tail node
				q->next = n;//attach as tail
			}

		}//else

		//cycle
		printf("\n Continue ? ");
		flushall();
		scanf("%c", &ch);
	}while(ch == 'y' || ch == 'Y');
	return h;

}

node * create()//create a linked list
{
	node *h, *p, *n;
	char ch;

	h = NULL;//no address

	do
	{
		//allocate memory for a node

		n = (node*) malloc(sizeof(node));

		//initialize the node
		printf("\n enter data for node ");
		scanf("%d", &n->data);
		n->next = NULL;

		//connect
		if(h == NULL)
		{//true for 1st execution
			h = n;
			p = n;
		}
		else
		{//true for rest of the executions
			p->next = n;
			p = n;
		}

		printf("\n continue ? ");
		fflush(stdin);
		scanf("%c", &ch);

	}while(ch == 'y');

	return h;
}

void disp(node *h)
{
	node *p;

	printf("\n");

	p = h;
	while(p != NULL)
	{
		printf("  %d", p->data);
		p = p->next;
	}//while
}

int count(node *h)
{
	int c = 0;
	node *p;
	p = h;

	while(p != NULL)
	{
		c++;
		p = p->next;
	}

	return c;
}

node * getNodeByPos(node *h, int pos)
{
	node *p;
	int i, tot;

	tot = count(h);
	if(pos < 0 || pos >= tot)
	{	//invalid pos
		return NULL;
	}
	else
	{ //valid pos
		p = h;
		for(i=0; i<pos ; i++)
		{
			p = p->next;
		}
		return p;
	}
}

node * bubble(node *h)
{//treat the linked list like an array
	int i, j;
	int size;
	node *p1, *p2;
	node *q1;

	size = count(h);

	for(i =size-1 ;i > 0; i--)
	{
		for(j =0 ; j< i; j++)
		{
			p1 = getNodeByPos(h, j);
			p2 = getNodeByPos(h, j+1);

			if(p1->data > p2->data)
			{//swap
				if(p1 == h)
				{//head
					p1->next = p2->next;
					p2->next = p1;
					h = p2;
				}
				else
				{//not head
					q1 =getNodeByPos(h, j-1);

					q1->next = p2;
					p1->next = p2->next;
					p2->next = p1;
				}
			}//if
		}//for(j
	}//for(i

	return h;
}

node* merge(node *h1, node *h2)
{
	node *p1, *p2;
	node *q1, *q2;
	node *h3;

	if(h1 != NULL && h2 == NULL)
		return h1;
	else if(h1 == NULL && h2 != NULL)
		return h2;
	else if(h1 == NULL && h2 == NULL)
		return NULL;

	//merge logic
	//h2 will get merged into h1
	h3 = NULL;
	p1 = h1;
	p2 = h2;

	while(p1 != NULL && p2 != NULL)
	{
		if(p1->data < p2->data)
		{
			if(p1 == h1 && h3 == NULL)
			{
				h3 = h1;
				q1 = p1;
				p1 = p1->next;
				q2 = q1;
			}
			else
			{
				q2->next = p1;
				q1 = p1;
				p1 = p1->next;
				q2 = q1;
			}
		}
		else
		{//p2->data >= p1->data
			if(p2 == h2 && h3 == NULL)
			{
				h3 = h2;
				q2 = p2;
				p2 = p2->next;
				q1 = q2;
			}
			else
			{
				q1->next = p2;
				q2 = p2;
				p2 = p2->next;
				q1 = q2;
			}

		}//else
	}//while

	if(p1 !=NULL && p2 == NULL)
	{
		q2->next = p1;
	}
	if(p1 ==NULL && p2 != NULL)
	{
		q1->next = p2;
	}

	return h3;
}//merge

void main()
{
	node *head1, *head2;
	node *head3;

	printf("\n Create first list \n");
	head1 = screate();

	printf("\n Create second list \n");
	head2 = create();
	head2 = bubble(head2);

	disp(head1);
	disp(head2);

	//merge
	printf("\n Merged list ");
	head3 = merge(head1, head2);
	disp(head3);

}//main