#include <iostream>

using namespace std;
/*
DLL using C++
A DLL is all similar to a SLL.
Only difference is that of a 
DLL every node maintains two pointers.

One to refer to the previous node
and second to refer to the next node.

Hence a DLL supports bi-directional
traversal.
*/
class DLL;

class node
{
	node * prev;
	int data;
	node * next;

	public:
		node(int val);
		friend class DLL;
};
node :: node(int val)
{
	prev = NULL;
	data = val;
	next = NULL;
}

class DLL
{
	private:
		node * head; //to refer to the first node of the linked list
	public:
		DLL();
		void create();
		void display();
		void revdisplay();
		int count();
		void insertNode(int );
		void deleteNode(int );
};

DLL :: DLL()
{
	head = NULL;
}

//to create a linked list
void DLL :: create()
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
			n->prev = p;
			p = n;	
		}
		
		cout<<"\n add more nodes? ";
		cin>>ch;
	}while(ch == 'y');
		
}//create

void DLL :: display()
{
	node *p;
	cout<<"\n";
	
	for(p=head; p!=NULL; p=p->next)
	{
		cout<<" "<<p->data;
	}
}

void DLL :: revdisplay()
{
	node *p;

	//move to last node
	p = head;
	while(p->next != NULL)
	{
		p =p->next;
	}
	
	cout<<"\n";
	
	
	while(p != NULL)
	{
		cout<<" "<<p->data;
		p = p->prev;
	}
}


int DLL :: count()
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

void DLL::insertNode(int pos)
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
		head->prev = n;
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
		n->prev = q;
		
		n->next = p;
		if(p != NULL)
			p->prev = n;
	}
}

void DLL :: deleteNode(int pos)
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
		head->prev = NULL;
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
		if(r != NULL)
			r->prev = q;
		
		delete p;
	}
}

int main()
{
	DLL dll;	
	int ch, pos;
	
	do
	{
		cout<<"\n 1. create ";
		cout<<"\n 2. display ";
		cout<<"\n 3. rev display ";
		cout<<"\n 4. insert node ";
		cout<<"\n 5. delete node ";
		cout<<"\n 6. exit ";
		cout<<"\n enter choice ";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				dll.create();
				break;
			case 2:
				dll.display();
				break;
			case 3:
				dll.revdisplay();
				break;
			case 4:
				cout<<"\n enter pos. for new node ";
				cin>>pos;
				dll.insertNode(pos);
				break;
			case 5:
				cout<<"\n enter pos. of node to delete ";
				cin>>pos;
				dll.deleteNode(pos);
				break;
		}//switch	
		
	}while(ch != 6);


	return 0;
}

