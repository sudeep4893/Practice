#include <iostream>
#define SIZE 50

using namespace std;

/*
A binary tree with n nodes has
n+1 pointers that store NULL.

A threaded binary tree uses these
pointers (that store NULL) to hold
the address of predessor and 
successor nodes.

This helps in quick traversal of
tree nodes.

*/
class thrdtree;

class node
{
	node * left;//a reference to left child or left thread
	char lthrd;//a flag to differentiate between a thread and a left child
	int data;
	char rthrd;//a flag to differentiate between a thread and a right child
	node * right;//a reference to right child or right thread
public:
	node();
	node(int);
	friend class thrdtree;
};
node :: node()
{
	data = 999;
	left = NULL;
	right = NULL;
	lthrd = 't';
	rthrd = 't';
}

node :: node(int x)
{
	data = x;
	left = NULL;
	right = NULL;
	lthrd = 't';
	rthrd = 't';
}

class thrdtree
{
	node * head;
	public:
		thrdtree();
		void create();
		void inorder();
		void preorder();
		void postorder1();
		void postorder();
		int po_isProcessed(node *[], int s, node *);
};

thrdtree :: thrdtree()
{
	head = new node();
	head->left = head;//lthread
	head->right = head;//rthread
}

void thrdtree :: create()
{
	char ch1, ch2;
	node *n, *p;
	int x;
	
	do
	{
		cout<<"\n enter data for node ";
		cin>>x;
		n = new node(x);	
		
		//connection
		if(head->left == head)//first node (root)
		{
			head->left = n;
			//n is the left child of head
			//so its lthrd must be false
			head->lthrd = 'f';
			
			//n	is the only node
			//it has no predessor and no successor
			//so its predessors and successor are : head
			n->left = head;//threading
			n->right = head;//threading
		}
		else//successor node
		{
			p = head->left; //root
			int flag= 1;
			
			while(flag == 1)
			{
				cout<<"\n l. add to left of "<<p->data;
				cout<<"\n r. add to right of "<<p->data;
				cout<<"\n enter choice ";
				cin>>ch2;
				
				if(ch2 == 'l')
				{
					if(p->lthrd == 't')//left is free
					{
						n->left = p->left;//set left thread						
						n->right = p;//set right thread
						
						p->left = n;//connect as left child
						p->lthrd = 'f';								
						flag = 0; //to stop loop
					}
					else//left is occupied
					{
						p = p->left;	
					}
				}
				else if(ch2 == 'r')
				{
					if(p->rthrd == 't')//right is free
					{
						n->right = p->right;//set right thread						
						n->left = p;//set left thread
						
						p->right = n;//connect as left child
						p->rthrd = 'f';								
						flag = 0; //to stop loop
					}
					else//right is occupied
					{
						p = p->right;	
					}
				}
				else
				{
					cout<<"\n invalid choice ";
				}
			}//while
		}
	
		cout<<"\n add more nodes ";
		cin>>ch1;
	}while(ch1 == 'y');
}

void thrdtree ::inorder()//no recursive
{//LDR

	int flag;
	node *p;
	
	if(head->left == NULL)
	{
		cout<<"\n tree not created";
		return;//terminate inorder
	}
	
	cout<<"\n Inorder : ";
	p = head->left;
	flag = 0;
	
	do
	{
		while(p->lthrd == 'f' && flag == 0 )
		{
			p = p->left;//Left
		}	
		//p has no left or processed left
		cout<<" "<<p->data; //Data
		
		if(p->rthrd == 'f' )
		{//right is a child
			flag = 0;
			p = p->right;//move to right child
		}
		else
		{//right is a thread
			flag = 1;
			p = p->right;//move to successor
		}
	}while(p != head);
}//inorder

void thrdtree ::preorder()//no recursive
{//DLR

	int flag;
	node *p;
	
	if(head->left == NULL)
	{
		cout<<"\n tree not created";
		return;//terminate inorder
	}
	
	cout<<"\n PreOrder : ";
	
	p = head->left;
	flag = 0;
	
	do
	{
		while(p->lthrd == 'f' && flag == 0 )
		{
			cout<<" "<<p->data; //Data
			p = p->left;//Left
		}	
		//p has no left or processed left

		if(flag == 0)
		{
			cout<<" "<<p->data; //Data
		}
		
		if(p->rthrd == 'f' )
		{//right is a child
			flag = 0;
			p = p->right;//move to right child
		}
		else
		{//right is a thread
			flag = 1;
			p = p->right;//move to successor, backtracking
		}
	}while(p != head);
}//preorder

void thrdtree ::postorder1()//no recursive
{//LRD == DRL in array and array read in reverse

	int flag;
	node *p;
	int arr[SIZE];
	int i =0 ;
	
	if(head->left == NULL)
	{
		cout<<"\n tree not created";
		return;//terminate inorder
	}
	
	cout<<"\n PostOrder : ";
	
	p = head->left;
	flag = 0;
	
	do
	{
		while(p->rthrd == 'f' && flag == 0 )
		{
			arr[i]= p->data; //Data
			i++;
			
			p = p->right;//right
		}	
		//p has no right or processed right

		if(flag == 0)
		{
			arr[i] = p->data; //Data
			i++;
		}
		
		if(p->lthrd == 'f' )
		{//left is a child
			flag = 0;
			p = p->left;//move to left child
		}
		else
		{//left is a thread
			flag = 1;
			p = p->left;//move to predessor, backtracking
		}
	}while(p != head);
	
	int j;
	for(j = i-1; j>=0; j--)
	{
		cout<<"  "<<arr[j];
	}
	
}//postorder1

int thrdtree :: po_isProcessed(node * arr[], int s, node *n)
{//sequential search

	int i;
	for(i =0; i< s; i++)
	{
		if(arr[i] == n)
			return 1;//true
	}	
	return 0;//false
}

void thrdtree ::postorder()//no recursive
{//LRD

	int flag;
	node *p;
	
	if(head->left == NULL)
	{
		cout<<"\n tree not created";
		return;//terminate inorder
	}
	
	cout<<"\n PostOrder : ";
	
	p = head->left;
	
	node *arr[SIZE];
  int i = 0;//index for arr
		
	do
	{
		while(p->lthrd =='f' && ! po_isProcessed(arr, i, p->left))	
		{//p has a left child
			p = p->left;//L
		}
		//either no left or processed left
	 
		if(p->rthrd == 't' || po_isProcessed(arr, i, p->right))
		{//p has no right child, has a right thread or a processed right
			cout<<" "<<p->data;			
			arr[i] = p;//visited mark
			i++;
			
			do
			{
				p =p->right; //right movement for backtracking
			}while(po_isProcessed(arr,i,p));
			
		}
		else
		{//p has a right child
			p = p->right;//R
		}
	}while( ! po_isProcessed(arr, i, head->left) );
	
}//postorder

int main()//prg starts here
{
	thrdtree tt;
	tt.create();
	tt.inorder();
	tt.preorder();
	tt.postorder();
	tt.postorder1();
	
	return 0;
}