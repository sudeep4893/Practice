#include <iostream>
#include<fstream>
#include<string.h>
#include<stdio.h>

#define SIZE 10

using namespace std;

/*
Record Management System
allows records (a set of fields) to be
added/modified/searched/viewed/deleted 
from files.

*/

class RMS;//forward declaration

class Student
{
	private:
		int rno;
		char name[20];
		float per;
	
	public:
		void set();
		void disp();
		
	friend class RMS;
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
	cout<<"\n "<<rno<<" "<<name<<" "<<per;
}

class RMS
{
	char fname[20];
	public:
		RMS(char[]);
		void addRecord();
		void viewAllRecords();
		void searchRecord();
		void deleteRecord();
		void modifyRecord();			
};

RMS::	RMS(char fn[])
{
	strcpy(fname, fn);
}

void RMS ::addRecord()
{
	//to add a record (a set of fields) into the file
	Student s;
	s.set();
	//object contains the set of fields
	//i.e. object represents a record
	
	//open the file
	ofstream fout;
	fout.open(fname, ios::binary|ios::app);
	if(!fout)
	{
		cout<<"\n add record failed";
		return;//terminate the function
	}
	
	//write fn of class ofstream is used
	//to write object in a file
	//it requires 2 params
	//1. address of object in char * format
	//2. size of object
	fout.write((char*)&s, sizeof(s));
	
	//close the file
	fout.close();
		
}

void RMS ::viewAllRecords()
{
	Student s;//to hold the read record
	
	//open the file
	ifstream fin;
	fin.open(fname, ios::binary);
	if(!fin)
	{
		cout<<"\n view all records failed";
		return;//terminate fn
	}

	//read fn of class ifstream is used
	//to fetch object data from a file
	//it requires 2 params
	//1. address of object in char * format
	//2. size of object
	
	while(fin.read((char*)&s, sizeof(s)))//read returns NULL @ EOF and NULL means zero means false, so loop stops
	{
		s.disp();
	}
	
	//close the file
	fin.close();
}

void RMS ::searchRecord()
{
	Student s;//to hold the read record
	
	//open the file
	ifstream fin;
	fin.open(fname, ios::binary);
	if(!fin)
	{
		cout<<"\n search records failed";
		return;//terminate fn
	}

	int r, flag;
	cout<<"\n enter rno to search ";
	cin>>r;

	flag =0 ;
	
	while(fin.read((char*)&s, sizeof(s)))
	{
		if(s.rno == r)
		{
			s.disp();
			flag = 1;//found
			break;
		}
	}//while
	
	//close the file
	fin.close();
	
	if(flag == 0)
		cout<<"\n rno "<<r<<" is not found";
}

void RMS ::deleteRecord()
{
//physical record deletion from file

	Student s;//to hold the read record
	
	//open 2 files
	ifstream fin;
	ofstream fout;
	
	fin.open(fname, ios::binary);//read
	fout.open("d:/temp.txt", ios::binary);//write
	
	if(!fin || !fout)
	{
		cout<<"\n delete record failed";
		return;//terminate fn
	}

	int r, flag;
	cout<<"\n enter rno to delete ";
	cin>>r;

	flag =0 ;
	
	while(fin.read((char*)&s, sizeof(s)))
	{
		if(s.rno != r)
		{
			fout.write((char*)&s, sizeof(s));			
		}
		else
		{
			flag = 1;//rec to be deleted is found
		}
	}//while
	
	//close the file
	fin.close();
	fout.close();
	
	if(flag == 0)
	{
		cout<<"\n rno "<<r<<" is not found";
		//discard the copy
		remove("d://temp.txt");
	}
	else if(flag == 1)
	{
		//discard the original
		remove(fname);
		//rename the copy as original
		rename("d:/temp.txt", fname);
	}
}

void RMS ::modifyRecord()
{
	fstream fio;
	fio.open(fname, ios::binary|ios::in|ios::out);
	
	if(!fio)
	{
		cout<<"\n modify record failed ";
		return; //terminate the fn
	}
	
	int r, flag, cnt;
	
	Student s;//obj to hold data coming from file
	
	cout<<"\n enter rno to modify ";
	cin>>r;
	
	flag = 0;
	cnt = 0;
	while(fio.read((char*)&s, sizeof(s)))
	{
		if(s.rno == r)
		{
			s.disp();
			cout<<"\n enter new data ";
			s.set();
			
			//new data is in s (in object, in RAM)
			//write it back into the file
			
			fio.seekp(cnt * sizeof(s), ios::beg);
			fio.write((char*)&s, sizeof(s));
			flag = 1;
			break;
		}
		cnt++;
	}//while
	
	if(flag == 0)
	{
		cout<<"\n rno "<<r<<" not found";
	}
	
	fio.close();

}

		

int main()//prg starts here
{
	RMS rms("d:/studentDB.txt");
	int ch;
	
	do
	{
		cout<<"\n 1. add record ";
		cout<<"\n 2. modify record ";
		cout<<"\n 3. delete record ";
		cout<<"\n 4. search record ";
		cout<<"\n 5. view all records ";
		cout<<"\n 6. exit ";
		cout<<"\n enter choice ";
		cin >> ch;
		
		switch(ch)
		{
			case 1: //add record
				rms.addRecord();
				break;
				
			case 2: //modify record
				rms.modifyRecord();
				break;		
				
			case 3: //delete record
				rms.deleteRecord();
				break;		
				
			case 4: //search record
				rms.searchRecord();
				break;		
				
			case 5: //view all record
				rms.viewAllRecords();
				break;						
			
		}//switch
		
	}while(ch != 6);
	
	return 0;
}

