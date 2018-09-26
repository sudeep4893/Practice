#include <iostream>
#define SIZE 100

using namespace std;

//Create binary tree. 
//Find height of the tree 
//Print leaf nodes
//Find mirror image,
//Print original and mirror image using level-wise printing

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

class Queue
{
	node* data[SIZE];
	int f, r;
	public:
		Queue();
		int isFull();
		int isEmpty();
		void addQ(node *);
		node *delQ();
};

Queue :: Queue()
{
	f = -1;//init
	r = -1;//init
}

int Queue :: isEmpty()
{
	if(r == f)
		return 1; //true
	else
		return 0;//false
}

int Queue :: isFull()
{
	if(r == SIZE -1)
		return 1; //true
	else
		return 0;//false
}

//add a value into the queue
void Queue :: addQ(node * x)
{
	if(! isFull())
	{
		r++;
		data[r] = x;
	}
	//else
	//	cout<<"\n Queue is full ";
}

//remove a value from the stack
node * Queue :: delQ()
{
	node * temp= NULL;
	if(! isEmpty())
	{
		f++;
		temp = data[f];
	}
	//else
  //	cout<<"\n Queue is empty";
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
	void printLeaf();
	void printNonLeaf();	
	int getHeight();
	void levelwiseDisplay();
	void mirror(tree &t);
	void copy(tree &t);
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

//non recursive print leaf function

//A leaf node is a node with no further child nodes (outdegree : 0)
void tree :: printLeaf()
{//traverses the tree in LDR pattern

	Stack s;
	node *p;
	
	if(root == NULL)
	{
		cout<<"\n Tree Not created ";
		return; //terminate the fn
	}
	
	cout<<"\n Leaf Nodes : ";
	p = root;
	
	do
	{
		while(p != NULL)
		{
			if(p->left == NULL && p->right == NULL)
				cout<<" "<<p->data; //print

			s.push(p);
			p = p->left; //Move to the Left child
		}
		
		p = s.pop();
	
		p = p->right;//Move to the Right child
		
	}while(p!= NULL || !s.isEmpty());

}//printLeaf


//A non leaf node is a node with one/two further child nodess (outdegree : 1 or 2)

void tree :: printNonLeaf()
{//traverses the tree in LDR pattern

	Stack s;
	node *p;
	
	if(root == NULL)
	{
		cout<<"\n Tree Not created ";
		return; //terminate the fn
	}
	
	cout<<"\n Non Leaf Nodes : ";
	p = root;
	
	do
	{
		while(p != NULL)
		{
			if(p->left != NULL || p->right != NULL)
				cout<<" "<<p->data; //print

			s.push(p);
			p = p->left; //Move to the Left child
		}
		
		p = s.pop();
		
		p = p->right;//Move to the Right child
		
	}while(p!= NULL || !s.isEmpty());

}//printNonLeaf


void tree :: mirror(tree &t)
{
	if(t.root == NULL)
	{
		cout<<"\n tree not created ";
		return;//terminate the fn
	}
	char flag;
	Stack s1, s2;
	node *p1, *p2, *n;
	
	p1 = t.root;
	
	do
	{
		while(p1 != NULL)
		{
			//create a node
			n = new node(p1->data);
			//connect
			if(root == NULL)
			{
				root = n;
				p2 = n;
			}
			else
			{
				if(flag == 'l')
				{
					p2->left = n;
					p2 = n;	
				}
				else if(flag == 'r')
				{
					p2->right = n;
					p2 = n;
				}
			}//else
			
			s1.push(p1);//for backtracking support
			s2.push(p2);//for backtracking support
			
			p1 = p1->left;//L
			flag = 'r';
		}//while
		
		p1 = s1.pop();//back track
		p2 = s2.pop();//back track
		
		p1 = p1->right;//R
		
		if(p1 != NULL)
			flag = 'l';
		
	}while(p1 != NULL || !s1.isEmpty());

}//mirror

void tree :: copy(tree &t)
{
	if(t.root == NULL)
	{
		cout<<"\n tree not created ";
		return;//terminate the fn
	}
	char flag;
	Stack s1, s2;
	node *p1, *p2, *n;
	
	p1 = t.root;
	
	do
	{
		while(p1 != NULL)
		{
			//create a node
			n = new node(p1->data);
			//connect
			if(root == NULL)
			{
				root = n;
				p2 = n;
			}
			else
			{
				if(flag == 'l')
				{
					p2->left = n;
					p2 = n;	
				}
				else if(flag == 'r')
				{
					p2->right = n;
					p2 = n;
				}
			}//else
			
			s1.push(p1);//for backtracking support
			s2.push(p2);//for backtracking support
			
			p1 = p1->left;//L
			flag = 'l';
		}//while
		
		p1 = s1.pop();//back track
		p2 = s2.pop();//back track
		
		p1 = p1->right;//R
		
		if(p1 != NULL)
			flag = 'r';
		
	}while(p1 != NULL || !s1.isEmpty());

}//copy


int tree :: getHeight()
{
	//height = noOfLevels + 1
	//height of empty tree : 0
	//height of tree with root only : 1
	//height of tree with root and child nodes : noOfLevels + 1

	int levels = -1;
	
	if(root == NULL)
		return levels + 1;//height

	Queue q;
	node *p;
	
	p = root;//at level 0
	q.addQ(root);//add root in q
	
	while(p != NULL)
	{
		//add child nodes in q
		if(p->left != NULL)//p has left child
			q.addQ(p->left);				
		if(p->right != NULL)//p has right child
			q.addQ(p->right);				
			
		//fetch a node from q
		p = q.delQ();
			
		if(p == root)
		{
			levels++; //change in level
			p = q.delQ();//fetch a node from q
			if(p != NULL)
			{
				q.addQ(root);//add level separator
			}
		}//if
	}//while
	
	return levels +1;
}//getHeight

//levelwise display uses a BFS
//traversal method 
//In BFS traversal policy is to
//process adjacent (sibling) node
//before the child node.


void tree :: levelwiseDisplay()
{
	if(root == NULL)
	{
		cout<<"\n tree not created";
		return ; //terminate the fn
 	}
  
	Queue q;
	node *p;
	
	p = root;//at level 0
	q.addQ(root);//add root in q
	
	cout<<"\n Levelwise Output \n";
	
	while(p != NULL)
	{
		cout<<" "<<p->data;	
		//add child nodes in q
		if(p->left != NULL)//p has left child
			q.addQ(p->left);				
		if(p->right != NULL)//p has right child
			q.addQ(p->right);				
			
		//fetch a node from q
		p = q.delQ();
			
		if(p == root)
		{
			cout<<"\n"; //change in level
			p = q.delQ();//fetch a node from q
			if(p != NULL)
			{
				q.addQ(root);//add level separator
			}
		}//if
	}//while
}

int main()//prg starts here
{
	tree t, t1;
	t.create();
	t.printLeaf();
	t.printNonLeaf();
		
	int h;
	h = t.getHeight();
	cout<<"\n Height of tree : "<<h;
	
	//will create t1 as mirror of t
	t1.mirror(t);
	
	t.levelwiseDisplay();
	t1.levelwiseDisplay();
	
	return 0;
}