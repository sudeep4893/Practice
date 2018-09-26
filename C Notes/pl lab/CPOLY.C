#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

/*
poly operations using cll
*/

struct node
{
	int c, e;
	struct node * next;
};
typedef struct node node;


node* getlastnode(node *h)
{//returns address of last node

	node * p;

	p = h;
	while(p->next != h)
	{
		p = p->next;
	}
	return p;
}


node * insertnode(node *h, int c, int e)
{
	node *n, *p, *q, *last;
	int flag;

	//dont create a node with 0 coeff
	if(c == 0)
		return h;

	n = (node*) malloc(sizeof(node));

	n->c = c;
	n->e = e;
	//n->next to init later

	if(h == NULL)
	{//first node
		h = n;
		n->next  = n; //points to itself
	}
	else
	{//sort and insert
		flag = 0;
		//traverse node list
		p= h;
		do
		{
			if(n->e > p->e)
			{
				//n expo > p expo
				//attach n before p
				if(p == h)
				{
					//n will be new head
					last = getlastnode(h);
					n->next = h;
					h = n;
					last->next = h;

				}
				else
				{
					//n will be inserted anywhere
					//in between before p
					q->next = n;
					n->next = p;
				}
				flag = 1;
				break;
			}
			else if(n->e == p->e)
			{
				//merge
				//add coeff of p and n
				p->c = p->c + n->c;
				free(n);
				if(p->c == 0)
				{
					//free p also
					if(p == h)
					{//free head node
						if(h->next == h)
						{//only one node
							free(h);
							h = NULL;
						}
						else
						{//multiple nodes in list
							last = getlastnode(h);
							h = h->next;
							last->next = h;
							free(p);
						}
					}
					else
					{//free intermediate node
						q->next = p->next;
						free(p);
					}
				}
				flag = 1;
				break;
			}
			else
			{
				q = p;
				p = p->next;
			}
		}while(p != h);

		if(flag == 0)
		{//attach as tail node
			q->next = n;
			n->next = h;
		}
	}//else

	return h;
}

node * create()
{
	node * h;
	char ch;
	int c, e;

	h = NULL;
	do
	{

		printf("\n enter coeff ");
		scanf("%d", &c);
		printf("\n enter expo ");
		scanf("%d", &e);

		h = insertnode(h, c, e);

		printf("\n continue ? ");
		fflush(stdin);
		scanf("%c", &ch);
	}while(ch == 'y');
	return h;

}

void disp(node * h)
{
	node *p;

	if(h != NULL)
	{
		printf("\n");
		p = h;

		do
		{
			printf(" %dx^%d ", p->c, p->e);
			p = p->next;
		}while(p != h);
	}
}

int count(node *h)
{
	int cnt = 0;
	node *p;
	if(h == NULL)
		return 0;

	p = h;
	do
	{
		cnt++;
		p = p->next;
	}while(p != h);

	return cnt;
}

node * add(node * h1, node *h2)
{
	node * h3;
	int t1, t2, i, j;
	node *p1, *p2;
	int c, e;

	h3 = NULL;

	t1 = count(h1);
	t2 = count(h2);
	i =0;
	j =0 ;

	p1 = h1;
	p2 = h2;

	while(i < t1 && j < t2)
	{
		if(p1->e > p2->e)
		{
			c = p1->c;
			e = p1->e;
			p1 = p1->next;
			i++;
		}
		else if(p1->e < p2->e)
		{
			c = p2->c;
			e = p2->e;
			p2 = p2->next;
			j++;

		}
		else if(p1->e == p2->e)
		{
			c = p1->c + p2->c;
			e = p1->e;
			p1 = p1->next;
			p2 = p2->next;
			i++;
			j++;
		}

		h3=insertnode(h3, c, e);
	}//while

	//there may be remaining elements in p1
	while(i < t1)
	{
		c = p1->c;
		e = p1->e;
		p1 = p1->next;
		i++;
		h3 = insertnode(h3, c, e);
	}

	//there may be remaining elements in p2
	while(j < t2)
	{
		c = p2->c;
		e = p2->e;
		p2 = p2->next;
		j++;
		h3 = insertnode(h3, c, e);
	}

	return h3;
}


node * mul(node * h1, node *h2)
{
	node * h3;
	node *p1, *p2;
	int c, e;
	h3 = NULL;

	p1= h1;
	do
	{
		p2 = h2;
		do
		{
			c = p1->c * p2->c;
			e = p1->e + p2->e;

			h3 = insertnode(h3,c,e);
			p2 = p2->next;
		}while(p2 != h2);

		p1 = p1->next;
	}while(p1 != h1);

	return h3;
}

void eval(node *h)
{
	int x;
	int sum =0 ;
	node * p;

	printf("\n enter val of x ");
	scanf("%d", &x);

	p = h;
	do
	{
		sum = sum + p->c * pow(x, p->e);
		p = p->next;
	}while(p != h);

	printf("\n ans : %d ", sum);
}

void main()
{
	node *p1, *p2, *p3;

	clrscr();
	printf("\n create poly 1");
	p1 = create();

	printf("\n create poly 2");
	p2 = create();

	p3 = add(p1, p2);
	disp(p1);
	disp(p2);
	disp(p3);
	printf("\n eval of p3");
	eval(p3);

	p3 = mul(p1, p2);
	disp(p1);
	disp(p2);
	disp(p3);
	printf("\n eval of p3");
	eval(p3);

}
