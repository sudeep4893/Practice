#include <iostream>
#define SIZE 10

using namespace std;

//only a demo of adjMat
//not an assignment
class Graph
{
	int vertex[SIZE];//to hold vertices
	int adjMat[SIZE][SIZE];//to hold edges
	int n;
	
	public:
	Graph();
	void create();
	void disp();
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
		adjMat[i][i]= 0; //no self loop
		
		for(j =i+1; j< n; j++)
		{ 										 
			cout<<"\n Is there an edge between ";
			cout<<vertex[i]<<" and "<< vertex[j];
			cin>>ch;
			if(ch == 'y')
			{
				adjMat[i][j]= 1;//bidirectional
				adjMat[j][i]= 1;
			}			
			else
			{
				adjMat[i][j]= 0;//bidirectional
				adjMat[j][i]= 0;
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

int main()//prg starts here
{
	Graph g;	
	g.create();
	g.disp();
	
	return 0;
}

