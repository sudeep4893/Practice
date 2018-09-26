#include <iostream.h>
#define SIZE 50


class Graph;//forward declaration
class vertex;//forward declaration

class Stack
{
	vertex* data[SIZE];
	int top;
	public:
		Stack();
		int isFull();
		int isEmpty();
		void push(vertex *);
		vertex *pop();
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
void Stack :: push(vertex * x)
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
vertex * Stack :: pop()
{
	vertex * temp= NULL;
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
	vertex* data[SIZE];
	int f, r;
	public:
		Queue();
		int isFull();
		int isEmpty();
		void addQ(vertex *);
		vertex *delQ();
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
void Queue :: addQ(vertex * x)
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
vertex * Queue :: delQ()
{
	vertex * temp= NULL;
	if(! isEmpty())
	{
		f++;
		temp = data[f];
	}
	//else
  //	cout<<"\n Queue is empty";
  return temp;
}


class edge
{
	private:
		vertex * vert;
		edge * nextE;	
	public:
		edge(vertex *);
		friend class Graph;
};

edge :: edge(vertex * x)
{
	vert = x;
	nextE = NULL;
}

class vertex
{
	private:
		vertex * nextV;
		int data;
		edge * edgeH;
	
	public:
		vertex(int);
		friend class Graph;
};
vertex :: vertex(int x)
{
	nextV = NULL;
	data = x;
	edgeH = NULL;
}


class Graph
{
	vertex * head;
	public:
		Graph();
		void create();
		void display();
		void dfs();
		void bfs();
};

Graph :: Graph()
{
	head = NULL;
}

void Graph :: create()
{
	char ch;
	int x;
	vertex *n, *p;
	vertex *v1, *v2;
	edge *e1, *e2, *ep;
	
	cout<<"\n creating vertices ";
	do
	{
		//create vertex
		cout<<"\n enter data for vertex ";
		cin >> x;
		n = new vertex(x);
		
		//connect
		if(head == NULL)//first vertex
		{
			head = n;
			p = n;
		}
		else//successor vertices
		{
			p->nextV = n;
			p = n;
		}
		
		cout<<"\n add more vertices ";
		cin>>ch;
	}while(ch == 'y');
	
	
	cout<<"\n creating edges ";
	for(v1=head; v1!=NULL; v1=v1->nextV)
	{
		for(v2=v1->nextV; v2!=NULL; v2=v2->nextV)
		{
			cout<<"\n Is there an egde between "<<v1->data <<" and "<<v2->data <<" ";			
			cin>>ch;
			if(ch == 'y')
			{
				//create an edge with target address of v2
				e1 = new edge(v2);

				//connect it with v1 edge list
				if(v1->edgeH== NULL)
				{
					v1->edgeH = e1;
				}
				else
				{
					//traverse and reach last edge of list
					ep = v1->edgeH;
					while(ep->nextE != NULL)
					{
						ep= ep->nextE; 
					}
					ep->nextE = e1;
										
				}
					
				//bidirectional support
					
				//create an edge with target address of v1
				e2 = new edge(v1);

				//connect it with v2 edge list
				if(v2->edgeH== NULL)
				{
					v2->edgeH = e2;
				}
				else
				{
					//traverse and reach last node of list
					ep = v2->edgeH;
					while(ep->nextE != NULL)
					{
						ep = ep->nextE;
					}
					ep->nextE = e2;
				}

			}//if(ch == 'y')			
		}//for(v2		
	}//for(v1	
	
}//create


void Graph:: display()
{
	vertex * v;
	edge * e;
	
	for(v=head; v!=NULL; v=v->nextV)
	{
		//vertices
		cout<<"\n "<<v->data;
		
		for(e=v->edgeH; e!= NULL; e=e->nextE)
		{
			cout<<"---("<<e->vert->data<<")";
		}//for(e
		
	}//for(v
	
}

void Graph:: dfs()
{
	int x, flag;
	vertex *current;
	edge *e;
	
	vertex * visited[SIZE];
	int v, i;
	Stack s;
	
	cout<<"\n enter a start vertex for DFS ";
	cin>>x;	
	
	flag =0 ;
	for(current=head; current!=NULL; current=current->nextV)
	{
		if(current->data == x)
		{
			flag = 1;
			break;
		}
	}//for
	if(flag == 0)
	{
		cout<<"\n invalid start vertex";
		return;//terminate DFS
	}
	
	//now current refers to the arbitrary start vertex
	//mark it as visited
	v= 0;
	visited[v]= current;
	v++;

	cout<<"\n DFS : ";
	
	do//for all vertices
	{
		cout<<" "<<current->data;
		//push the outdegrees of current
		for(e=current->edgeH; e!=NULL; e=e->nextE)
		{
			//check e->vert is visited or not
			flag =0 ;
			for(i =0; i< v; i++)
			{
				if(visited[i]== e->vert)
				{
					flag = 1;
					break;
				}
			}//for(i
			
			if(flag == 0)//unvisited outdegree
			{
				s.push(e->vert);
				visited[v]= e->vert;
				v++;
			}
		}//for(e = current->edgeH;...
		
		current = s.pop();//next current
		
	}while(current != NULL);
}//dfs

void Graph:: bfs()
{
	int x, flag;
	vertex *current;
	edge *e;
	
	vertex * visited[SIZE];
	int v, i;
	Queue q;
	
	cout<<"\n enter a start vertex for BFS ";
	cin>>x;	
	
	flag =0 ;
	for(current=head; current!=NULL; current=current->nextV)
	{
		if(current->data == x)
		{
			flag = 1;
			break;
		}
	}//for
	if(flag == 0)
	{
		cout<<"\n invalid start vertex";
		return;//terminate BFS
	}
	
	//now current refers to the arbitrary start vertex
	//mark it as visited
	v= 0;
	visited[v]= current;
	v++;

	cout<<"\n BFS : ";
	
	do//for all vertices
	{
		cout<<" "<<current->data;
		//add in Q the outdegrees of current
		for(e=current->edgeH; e!=NULL; e=e->nextE)
		{
			//check e->vert is visited or not
			flag =0 ;
			for(i =0; i< v; i++)
			{
				if(visited[i]== e->vert)
				{
					flag = 1;
					break;
				}
			}//for(i
			
			if(flag == 0)//unvisited outdegree
			{
				q.addQ(e->vert);
				visited[v]= e->vert;
				v++;
			}
		}//for(e = current->edgeH;...
		
		current = q.delQ();//next current
		
	}while(current != NULL);
}//bfs

int main()
{
	Graph g;
	g.create();
	g.display();
	g.dfs();
	g.bfs();
	return 0;
}
