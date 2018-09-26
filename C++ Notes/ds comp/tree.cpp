#include <iostream>
#define SIZE 100

using namespace std;
/*
Tree
-----
A tree is a homogenous collection of
information arranged in a non-linear pattern.

A tree stores its data in nodes.
A node is a composite type that contains
1) value
2) references to zero to many child nodes.

A tree connects its nodes in such a fashion
that there is one starting node called as
"root" node.
It contains a value and references to zero
to many child nodes.
The child nodes also contain values and 
references to zero to many further child 
nodes each.

Same pattern is followed upto n levels.

While forming a tree it must be
confirmed that every node has a 
single parent (predessor) node.

Tree Traversal
----------------
To traverse a tree means to visit
all of its nodes.
Tree traversal always begins with
the root node.

A tree can be traversed in 3 ways

1) preorder
Beginning with the root visit all 
the nodes with a policy of processing
data, left childs and right childs.

2) inorder
Beginning with the root visit all 
the nodes with a policy of processing
left childs, data and right childs.

3) postorder
Beginning with the root visit all 
the nodes with a policy of processing
left childs, right childs and data.


Binary Tree
-------------

A binary tree is a tree in which the 
nodes may have 0 to 2 child nodes.

*/


//Create binary tree and perform recursive and non-recursive traversals

class node;

class Stack
{
	node* data[SIZE];
	int top;
	public:
		Stack();
		int isFull();
		int isEmpty();
		void push(node *);
		node *pop();
};

Stack :: Stack()
{
	top = -1;//init
}

int Stack :: isEmpty()
{
	if(top == -1)
		return 1; //true
	else
		return 0;//false
}

int Stack :: isFull()
{
	if(top == SIZE -1)
		return 1; //true
	else
		return 0;//false
}

//add a value into the stack
void Stack :: push(node * x)
{
	if(! isFull())
	{
		top++;
		data[top] = x;
	}
	//else
	//	cout<<"\n Stack is full ";
}

//remove a value from the stack
node * Stack :: pop()
{
	node * temp= NULL;
	if(! isEmpty())
	{
		temp = data[top];
		top--;
	}
	//else
  //	cout<<"\n Stack is empty";
  return temp;
}


//a node is a composite type that a 
//tree uses for storage of data and 
//for connections

class tree;//a forward declaration

class node
{
	private :
	//to store information
	int data;

	//to refer to 0 to 2 child nodes
	node *left; //ref to left child if any
	node *right; //ref to right child if any
	
	public:
	
	node();//default constructor
	node(int);//parameterized constructor

	friend class tree;
};

node ::node()
{
	data = 0;
	left = NULL;
	right = NULL;
}

node ::node(int q)
{
	data = q;
	left = NULL;
	right = NULL;
}

class tree //a collection of dynamicall created nodes
{
	private:
	node * root;		
	
	public:
	tree();
	void create();

	//fns that invoke recursive methods
	void rec_inorder();
	void rec_preorder();
	void rec_postorder();
	

	//recursive traversal methods
	void rInorder(node *);
	void rPreorder(node *);
	void rPostorder(node *);

	
	//non recursive traversal methods
	void inorder();
	void preorder();
	void postorder();
	
};

tree :: tree()
{
	root = NULL;
}

//create a binary tree
void tree :: create()
{
	char ch, ch1;
	node *n, *p;
	int x;

  root = NULL; //imp initialization	

	do
	{
		//create a node and init it
		cout<<"\n enter data for node ";
		cin >>x;
		n = new node(x);
		
		//connection
		if(root == NULL)
		{//for first cycle
			root = n;
		}
		else
		{//for rest of the cycles
			p = root;
			int flag;
			flag = 1;
			
			while(flag == 1)
			{
				cout<<"\n l. add to left of "<<p->data;
				cout<<"\n r. add to right of "<<p->data;
				cout<<"\n enter choice ";
				cin>>ch1;
				
				if(ch1 == 'l')
				{//add to left of p

					if(p->left == NULL)
					{//left of p is free
						p->left = n;	
						flag = 0;//loop stop
					}
					else
					{//left of p is occupied
						p = p->left;
					}
				}
				else if(ch1 == 'r')
				{//add to right of p

					if(p->right == NULL)
					{//right of p is free
						p->right = n;	
						flag = 0;//loop stop
					}
					else
					{//right of p is occupied
						p = p->right;
					}
					
				}
				else
				{
					cout<<"\n invalid choice";
				}
			}//while
			
		}//else
		
		//cycle
		cout<<"\n Add More Nodes ";
		cin>>ch;
	}while(ch == 'y');
}//create


//fns that invoke recursive functions

void tree :: rec_inorder()
{
	cout<<"\n Recursive Inorder ";
	rInorder(root);
}

void tree :: rec_preorder()
{
	cout<<"\n Recursive Preorder ";
	rPreorder(root);
}

void tree :: rec_postorder()
{
	cout<<"\n Recursive Postorder ";
	rPostorder(root);
}

//recursive traversals

void tree :: rInorder(node * root)
{
	if(root != NULL)
	{
		rInorder(root->left); //L
		cout<<" "<<root->data;//D
		rInorder(root->right);//R
	}
}//rInorder

void tree :: rPreorder(node * root)
{
	if(root != NULL)
	{
		cout<<" "<<root->data;//D
		rPreorder(root->left); //L
		rPreorder(root->right);//R
	}
}//rPreorder


void tree :: rPostorder(node * root)
{
	if(root != NULL)
	{
		rPostorder(root->left); //L
		rPostorder(root->right);//R
		cout<<" "<<root->data;//D
	}
}//rPostorder


//non recursive traversals

void tree :: inorder()
{//LDR
	Stack s;
	node *p;
	
	if(root == NULL)
	{
		cout<<"\n Tree Not created ";
		return; //terminate the fn
	}
	
	cout<<"\n inorder : ";
	p = root;
	
	do
	{
		while(p != NULL)
		{
			s.push(p);
			p = p->left; //Move to the Left child
		}
		
		p = s.pop();
		
		cout<<" "<<p->data; //print/process data

		p = p->right;//Move to the Right child
		
	}while(p!= NULL || !s.isEmpty());

}//inorder

void tree :: preorder()
{//DLR
	Stack s;
	node *p;
	
	if(root == NULL)
	{
		cout<<"\n Tree Not created ";
		return; //terminate the fn
	}
	
	p = root;
	cout<<"\n preorder : ";
	
	do
	{
		while(p != NULL)
		{
			cout<<" "<<p->data; //print/process data
			s.push(p);
			p = p->left; //Move to the Left child
		}
		
		p = s.pop();
		p = p->right;//Move to the Right child
		
	}while(p!= NULL || !s.isEmpty());
	
}//preorder


void tree :: postorder()
{//LRD
	Stack s;
	node *p, *processed;
	
	
	if(root == NULL)
	{
		cout<<"\n Tree Not created ";
		return; //terminate the fn
	}
	
	cout<<"\n postorder : ";
	
	p = root; //imp init
	processed = NULL;//imp init
	
	do
	{
		while(p != NULL)
		{
			s.push(p);//preserve address for backtracking
			p = p->left;//left
		}
		p = s.pop(); //backtrack
		
		if(p->right != NULL && p->right != processed)
		{
			s.push(p);//preserve address for backtracking
			p = p->right;//right
		}
		else
		{
			cout<<" "<<p->data; //print/process data
			processed = p;
			p = NULL;
		}
		
	}while(p!= NULL || !s.isEmpty());

}//postorder

int main()//prg starts here
{
	tree t;
	t.create();
	
	t.inorder();
	t.rec_inorder();
	
	t.preorder();
	t.rec_preorder();
	
	t.postorder();
	t.rec_postorder();
	return 0;
}