#include <iostream>
#include <fstream>
#include <string.h>
#define SIZE 10

using namespace std;

class Student
{
	private :
		int rno;
		char name[20];
		float per;
	public:
		void set();
		void disp();
};

void Student :: set()
{
	cout<<"\n enter rno ";
	cin>>rno;
	cout<<"\n enter name ";
	cin>>name;
	cout<<"\n enter percentage ";
	cin>>per;
}

void Student :: disp()
{
	cout<<"\n"<<rno<<"  "<<name<<"  "<<per;
}

class DAFiles
{
	void addRecord();
	int hash(int);
}

void DAFiles :: addRecord()
{
	//open the file
	fstream fout;//supports reading and writing
	fout.open(fname, ios::binary|ios::out|ios::in);

	if(!fout)
	{
		cout<<"\n add record failed ";
		return;//terminate the fn
	}	

	Student s, temp;
	s.set();

	int pos = hash(s.rno);
	
	//go to that position
	fout.seekg(pos* sizeof(s), ios::beg);
	//fetch the record place there	
	fout.read((char*)&temp, sizeof(s));	
	
	if(temp.rno == -1)
	{//place is empty
		//go to that position
		fout.seekp(pos* sizeof(s), ios::beg);	
		//write the record 
		fout.write((char*)&s, sizeof(s));	
	}		
	else
	{//place is occupied
		int pos1 = hash(temp.rno);	
		if(pos == pos1)
		{//prev rec and this rec are synonyms
		 //prev rec is at correct pos
		 	i = linear probing
		
			
				
		}
		else
		{//prev rec is at wrong pos
			//move prev rec else where
				i = linear probing
		  	fout.seekp(i*sizeof(s), ios::beg);
		 	  fout.write((char*)&temp, sizeof(s));
		 
			//store current rec at corect pos
				fout.seekp(pos*sizeof(s), ios::beg);
				fout.write((char*)&s, sizeof(s));
			
		}
		
	}
}

int DAFiles :: hash(int x)
{
	return x % SIZE; //modulo division hashing method
}

int main()
{
	return 0;
}

