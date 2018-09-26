#include <iostream>

using namespace std;
//SLL using C++


/*
Linked List

A linked list is a homogenous collection 
of sequentially connected nodes.

A node is a custom datatype formed by
combining a data unit and a pointer.

Being a sequential data structure, it
resembles an array and most of the 
algorithms that act on arrays also 
act on linked lists.

Advantages of a linked list over an array
1) A linked list can dynamically grow/shrink,
whereas array has a fixed size.
2) Linked list supports insertion or
deletion of nodes at all locations. 

Advantages of an Array over a  linked list
1) Array supports direct access of any element,
whereas in a linked list it requires n-1 jumps
to reach nth element.

*/
class SLL;

class node
{
	int data;
	node * next;

	public:
		node(int val);
		friend class SLL;
};
node :: node(int val)
{
	data = val;
	next = NULL;
}

class SLL
{
	private:
		node * head; //to refer to the first node of the linked list
	public:
		SLL();
		void create();
		void display();
		int count();
		void insertNode(int );
		void deleteNode(int );
};

SLL :: SLL()
{
	head = NULL;
}

//to create a linked list
void SLL :: create()
{
	char ch;
	node *n, *p;
	int x;
	
	do
	{
		//create a node
		cout<<"\n enter data for node "	;
		cin>>x;
		n = new node(x);
		
		//connect the node 
		if(head == NULL)//first node
		{
			head = n;
			p = n;
		}
		else
		{
			p->next = n;
			p = n;	
		}
		
		cout<<"\n add more nodes? ";
		cin>>ch;
	}while(ch == 'y');
		
}//create

void SLL :: display()
{
	node *p;
	cout<<"\n";
	
	for(p=head; p!=NULL; p=p->next)
	{
		cout<<" "<<p->data;
	}
}

int SLL :: count()
{
	node *p;
	int tot = 0;
	
	for(p=head; p!=NULL; p=p->next)
	{
		tot++;
	}
	return tot;
}

//add a new node in the linked list at specific position

void SLL::insertNode(int pos)
{
	node *n, *p, *q;
	int tot, x, i;
	
	tot = count();
	if(pos < 1 || pos > (tot+1))
	{
		cout<<"\n Invalid Position ";
		return;//terminate the fn
	}
	
	cout<<"\n enter data for new node ";
	cin>>x;
	n = new node(x);
	
	if(pos == 1)
	{//new node will be the head node
		n->next = head;		
		head = n;
	}
	else//pos > 1
	{
		p = head;
		for(i = 1; i<pos; i++)
		{
			q = p;// shadow pointer
			p = p->next;
		}
		//now p is at node : pos
		//and q is at node : pos -1
		
		q->next = n;
		n->next = p;
	}
}

void SLL :: deleteNode(int pos)
{
	int tot, i;
	node *p, *q, *r;
	
	
	tot = count();
	if(pos < 1 || pos > tot)
	{
		cout<<"\n invalid position of node to be deleted ";
		return;//terminate the fn		
	}	
	
	if(pos == 1)
	{
		p = head;
		head = p->next;
		delete p;
	}
	else
	{
		p = head;
		for(i = 1; i<pos; i++)
		{
			q = p;
			p = p->next;
		}
		//now p is at node : pos
		//and q is at node : pos -1		
		r = p->next;
		//and r is at node : pos +1
		
		q->next = r;
		delete p;
	}
}

int main()
{
	SLL sll;	
	int ch, pos;
	
	do
	{
		cout<<"\n 1. create ";
		cout<<"\n 2. display ";
		cout<<"\n 3. insert node ";
		cout<<"\n 4. delete node ";
		cout<<"\n 5. exit ";
		cout<<"\n enter choice ";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				sll.create();
				break;
			case 2:
				sll.display();
				break;
			case 3:
				cout<<"\n enter pos. for new node ";
				cin>>pos;
				sll.insertNode(pos);
				break;
			case 4:
				cout<<"\n enter pos. of node to delete ";
				cin>>pos;
				sll.deleteNode(pos);
				break;
		}//switch	
		
	}while(ch != 5);


	return 0;
}

