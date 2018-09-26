#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
	int rno;
	char name[20];
	int age;
	char address[20];
	char phoneno[20];
	char dob[20];

	struct node *next;
};
typedef struct node node;


node * create()
{
	node *h, *p, *n;
	char ch;

	h = NULL;

	do
	{
		//create a node
		n = (node*) malloc(sizeof(node));

		//initialize the node
		printf("\n enter data for node ");
		printf("\n rno ");
		scanf("%d", &n->rno);
		printf("\n name ");
		fflush(stdin);
		scanf("%s", &n->name);
		printf("\n age ");
		scanf("%d", &n->age);
		printf("\n address ");
		fflush(stdin);
		scanf("%s", &n->address);
		printf("\n phone no ");
		fflush(stdin);
		scanf("%s", &n->phoneno);
		printf("\n dob ");
		fflush(stdin);
		scanf("%s", &n->dob);


		n->next = NULL;

		//connect the node
		if(h == NULL)
		{//first node
			h = n;
			p = n;
		}
		else
		{//successor nodes
			p->next = n;
			p = n;
		}

		printf("\n Continue ? ");
		fflush(stdin);
		scanf("%c", &ch);
	}while(ch == 'y');

	return h; //address of first node
}

int count(node *h)
{
	node *p;
	int tot;

	tot = 0;
	p= h;

	while(p != NULL)
	{
		tot++;//1,2,3,4,5
		p = p->next;
	}
	return tot;
}

void disp(node *h)
{
	node *p;

	printf("\n");
	p = h;
	printf("\n %3s %15s %3s %15s %15s %15s", "Rno", "Name", "Age", "Address", "Phoneno", "DOB");
	while(p != NULL)
	{
		printf("\n %3d %15s %3d %15s %15s %15s", p->rno, p->name,p->age, p->address, p->phoneno, p->dob);
		p = p->next;
	}

}

node* getNodeByPosition(node *h, int pos)
{
	int i;
	node *p;
	p = h;
	for(i=0; i<pos && p != NULL; i++)
	{
		p = p->next;
	}
	return p;
}


node * sortRnoWise(node * h)
{
	int i, j, tot;
	node *p1, *p2, *pp1;

	tot = count(h); //get no of nodes
	for(i = tot-1; i> 0; i--)
	{
		for(j =0; j< i; j++)
		{
			//if(arr[j] > arr[j+1])
					//swap
			p1 = getNodeByPosition(h,j);
			p2 = getNodeByPosition(h,j+1);

			if(p1->rno > p2->rno)
			{//swap links
				if(p1 == h)
				{ //p2 will be new head
					p1->next = p2->next;
					p2->next = p1;
					h = p2;
				}
				else
				{
					pp1 = getNodeByPosition(h, j-1);
					p1->next = p2->next;
					p2->next = p1;
					pp1->next = p2;
				}
			}
		}//for(j
	}//for(i
	return h;

}

node * insert(node * h)
{
	int pos, tot, i;
	node *n, *p, *q;
	printf("\n enter pos of new node ");
	scanf("%d", &pos);

	tot = count(h);

	if(pos < 1 || pos > tot +1)
	{
		printf("\n Invalid position");
		return h;
	}

	//create a node
	n = (node *)malloc(sizeof(node));

	//init
	printf("\n enter data for node ");
	printf("\n rno ");
	scanf("%d", &n->rno);
	printf("\n name ");
	fflush(stdin);
	scanf("%s", &n->name);
	printf("\n age ");
	scanf("%d", &n->age);
	printf("\n address ");
	fflush(stdin);
	scanf("%s", &n->address);
	printf("\n phone no ");
	fflush(stdin);
	scanf("%s", &n->phoneno);
	printf("\n dob ");
	fflush(stdin);
	scanf("%d", &n->dob);		

	n->next = NULL;

	//connect
	if(pos == 1)
	{
		n->next = h;
		h = n;
	}
	else
	{
		p = h;
		for(i = 1; i<pos; i++)
		{
			q = p;
			p = p->next;
		}

		//now p is at node : pos
		//and q is at node : pos -1
		q->next = n;
		n->next= p;
	}//else

	return h;
}//insert

node *del(node *h)
{
	int pos, tot, i;
	node *p, *q, *r;

	printf("\n enter pos for node to delete ");
	scanf("%d", &pos);
	tot = count(h);

	if(pos < 1 || pos > tot)
	{
		printf("\n Invalid pos");
	}
	else
	{//we have a valid pos
		if(pos == 1)
		{//del head node
			if(tot == 1)
			{
				p = h;
				h = NULL;
				free(p);
			}
			else
			{
				//grab current head node
				p = h;
				//set next node as head
				h = h->next;
				//fix the old head
				free(p);
			}
		}
		else if(pos >1 && pos < tot)
		{//del in between
			p = h;

			for(i = 1; i< pos; i++)
			{
				q = p;
				p = p->next;
			}

			r = p->next;

			q->next = r;

			//free the node
			free(p);

		}
		else if(pos == tot )
		{//del tail
			p = h;

			while(p->next != NULL)
			{
				q = p;
				p = p->next;
			}
			//p is at last node
			//q is at second last node

			q->next = NULL;
			free(p);

		}
	}//else
	return h;//as h can change due to pos == 1
}//del


node * searchRnoWise(node *h, int val)
{//sequential search
	node *p;

	p = h;
	while(p != NULL)
	{
		if(p->rno == val)
		{//found
			return p;//address of matching node
		}
		p = p->next;
	}
	return NULL;//not found
}

void modify(node *h)
{
	node *p;
	int r;

	printf("\n enter rno to modify ");
	scanf("%d", &r);

	p = searchRnoWise(h, r);

	if(p != NULL)
	{
		printf("\n enter new data for node ");
		printf("\n rno ");
		scanf("%d", &p->rno);
		printf("\n name ");
		fflush(stdin);
		gets(p->name);
		printf("\n age ");
		scanf("%d", &p->age);
		printf("\n address ");
		fflush(stdin);
		gets(p->address);
		printf("\n phone no ");
		fflush(stdin);
		gets(p->phoneno);
		printf("\n dob ");
		fflush(stdin);
		gets(p->dob );

	}
	else
	{
		printf("\n rno %d not found ",r);
	}
}

void main()
{
	node * head = NULL;
	int ch;
	int x;
	node * temp;

	clrscr();

	do
	{
		printf("\n 1. create student database ");
		printf("\n 2. insert a new student ");
		printf("\n 3. delete student ");
		printf("\n 4. modify student ");
		printf("\n 5. search student ");
		printf("\n 6. sort students rno wise ");
		printf("\n 7. disp all students ");
		printf("\n 8. exit ");
		printf("\n enter choice ");
		scanf("%d", &ch);

		switch(ch)
		{
			case 1:
				head = create();
				break;
			case 2:
				head = insert(head);
				break;
			case 3:
				head = del(head);
				break;
			case 4:
				modify(head);
				break;
			case 5:
				printf("\n enter rno to search ");
				scanf("%d", &x);
				temp = searchRnoWise(head, x);
				if(temp == NULL)
				{
					printf("\n %d not found ",x);
				}
				else
				{
					printf("\n %d  found ",x);
				}
				break;
			case 6:
				head = sortRnoWise(head);
				break;
			case 7:
				disp(head);
				break;
		}
	}while(ch != 8);
}//main