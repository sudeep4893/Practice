#include <iostream>
#define SIZE 10

using namespace std;

class MST //Minimum Spanning Tree
{
	int from;
	int to;
	int minwt;
	
	public:
		void set(int a, int b, int c);
		void disp();
};

void MST :: set(int a, int b, int c)
{
	from = a;
	to = b;
	minwt = c;
}

void MST :: disp()
{
	cout<<"\n"<<from<< "<--(" << minwt << ")-->" <<to;
}


class Graph
{
	int vertex[SIZE];//to hold vertices
	int adjMat[SIZE][SIZE];//to hold edges
	int n;
			
	public:
	Graph();
	void create();
	void disp();
	void prims();
};

Graph :: Graph()
{
	n = 0;//graph is not created
}

void Graph :: create()
{
	char ch;
	int i, j;
	
	n =0 ;//imp initialization
	
	cout<<"\n creating vertices ";
	do
	{
		cout<<"\n enter data for vertex ";
		cin>>vertex[n];
		n++;
		
		cout<<"\n create more vertices ";
		cin>>ch;
	}while(n < SIZE && ch == 'y');
	
	
	cout<<"\n creating edges ";
	for(i =0; i< n; i++)
	{
		adjMat[i][i]= 999; //infinite distance / no egde
		
		for(j =i+1; j< n; j++)
		{ 										 
			cout<<"\n Is there an edge between ";
			cout<<vertex[i]<<" and "<< vertex[j];
			cin>>ch;
			if(ch == 'y')
			{
				cout<<"\n enter distance : ";
				cin>> adjMat[i][j];
				adjMat[j][i]= adjMat[i][j]; //bidirectional
			}			
			else
			{
				adjMat[i][j]= 999; //infinite distance / no egde
				adjMat[j][i]= 999;
			}
			
		}//for(j
	}//for(i
	
}//create


void Graph :: disp()
{
	int i, j;
	
	for(i =0; i< n; i++)
	{
		cout<<"\n "<<vertex[i]<<"   ";	//printing vertices
		
		for(j =0; j< n; j++)
		{
			cout<<" "<<adjMat[i][j];
		}//for(j
	}//for(i
	
}

void Graph :: prims()//MST
{
	int x, i, j,k,l,current;
	int flag;//search results
	int visited[SIZE], v;
	int min;
	int to, from, wt;
	MST primsMST[SIZE];
	int mstIndx = 0;
	
	//1 SELECT AN ARBITRARY START VERTEX, TO ACT AS ROOT OF MST
	
	cout<<"\n enter the start vertex for generating MST ";
	cin>>x;	
	
	//search whether graph contains x
	flag = 0;
	for(i =0; i< n; i++)
	{
		if(vertex[i] == x)
		{
			flag = 1;
			break;
		}
	}//for
	
	if(flag == 0)
	{
		cout<<"\n Invalid start vertex ";
		return;//terminate the fn
	}
	
	//i contains index of start vertex
	//mark i as visited, representing that i is a node of tree
	v = 0;
	visited[v] = i;
	v++;
	
	//MST MUST HAVE ALL VERTICES OF GRAPH
	for(i =0; i< n-1; i++)
	{
		min = 999;//infinite
		
		for(j = 0; j < v; j++)//from the visited list i.e. from the tree
		{
			//FETCH A CURRENT VERTEX FROM MST	
			current = visited[j];
			
			//FOR THE CURRENT VERTEX FIND UNVISITED EDGE WITH MINIMUM WEIGHT
			for(k = 0; k< n; k++)
			{
				if(adjMat[current][k] != 999)
				{//an edge exists
					
					//if k is not visited
					
					flag =0; //not found
					for(l =0 ; l< v; l++)
					{
						if(visited[l]== k)
						{
							flag = 1;//found
							break;
						}
					}
					
					if(flag == 0)//unvisited k
					{
						wt= adjMat[current][k];	
						if(wt < min)
						{
							min =wt;
							from = current;
							to = k;
						}
					}//if flag == 0 
				}//if adjMat[current][k] != 999
			}//for k		
		}//for j

		//ADD IT AS A NODE IN TREE
		primsMST[mstIndx].set(vertex[from], vertex[to], min);
		mstIndx++;
		
		//mark to as visited, representing that to is a node of tree
		visited[v] = to;
		v++;
		
	}	//for i
	
	//disp
	for(i =0; i< mstIndx; i++)
		primsMST[i].disp();
		
}//prims

int main()//prg starts here
{
	Graph g;	
	g.create();
	g.disp();
	g.prims();
	
	return 0;
}

