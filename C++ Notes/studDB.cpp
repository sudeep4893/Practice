#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

/*
Design a base class consisting of data members 
name of the student,
roll number 
subject.

The derived class consists of data members 
subject code ,
internal assessment 
university examination marks.

Construct a virtual base class for the 
item name of the student and roll number.

The program should have the facilities.
i) Build a master table 
ii) List a table 
iii) Insert a new entry
iv) Delete old entry 
v) Edit an entry 
vi) Search for a record

*/

class FHandler;

class Student
{
	protected :
		int rno;
		char name[20];
		char subject[20];
};

class StudentMarks : virtual public Student
{
	protected :
		int sid;
		int imarks;		
		int umarks;
	public :
		void set();
		void disp();
		friend class FHandler;
};

void StudentMarks :: set()
{
	cout<<"\n Enter rno ";
	cin>>rno;
	cout<<"\n Enter name ";
	cin>>name;
	cout<<"\n Enter subject ";
	cin>>subject;
	cout<<"\n Enter subject code ";
	cin>>sid;
	cout<<"\n Enter internal marks ";
	cin>>imarks;
	cout<<"\n Enter univ. marks ";
	cin>>umarks;
}

void StudentMarks :: disp()
{
	cout<<"\n"<< rno <<"  "<< name<<" "<< subject;
	cout<<"  "<<sid<<"  "<<imarks<<"  "<<umarks;
}

class FHandler
{
	char fname[20];
	public:
		FHandler(const char[]);
		void build();
		void addRecord();
		void viewAllRecords();
		void searchRecord();
		void deleteRecord();
		void modifyRecord();			
};

FHandler::	FHandler(const char fn[])
{
	strcpy(fname, fn);
}

void FHandler ::build()
{
	//to create a new File (table)
	ofstream obj;
	obj.open(fname, ios::binary|ios::out|ios::trunc);
	if(!obj)
	{
		cout<<"\n Build Failed ";
		return;
	}
	obj.close();
	
	char ch;
	do
	{
		addRecord();
		cout<<"\n add more records ";
		cin>>ch;
	}while(ch == 'y');
	
}
void FHandler ::addRecord()
{
	StudentMarks s;
	s.set();
	
	//open the file
	ofstream fout;
	fout.open(fname, ios::binary|ios::app);
	if(!fout)
	{
		cout<<"\n add record failed";
		return;//terminate the function
	}
	
	fout.write((char*)&s, sizeof(s));
	
	//close the file
	fout.close();
		
}

void FHandler ::viewAllRecords()
{
	StudentMarks s;//to hold the read record
	
	//open the file
	ifstream fin;
	fin.open(fname, ios::binary);
	if(!fin)
	{
		cout<<"\n view all records failed";
		return;//terminate fn
	}

	while(fin.read((char*)&s, sizeof(s)))//read returns NULL @ EOF and NULL means zero means false, so loop stops
	{
		s.disp();
	}
	
	//close the file
	fin.close();
}

void FHandler ::searchRecord()
{
	StudentMarks s;//to hold the read record
	
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

void FHandler ::deleteRecord()
{
	StudentMarks s;//to hold the read record
	
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

void FHandler ::modifyRecord()
{
	fstream fio;
	fio.open(fname, ios::binary|ios::in|ios::out);
	
	if(!fio)
	{
		cout<<"\n modify record failed ";
		return; //terminate the fn
	}
	
	int r, flag, cnt;
	
	StudentMarks s;//obj to hold data coming from file
	
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
	FHandler obj("d:/studentMarks.txt");
	int ch;
	
	do
	{
		cout<<"\n 1. build a master table ";
		cout<<"\n 2. add record ";
		cout<<"\n 3. modify record ";
		cout<<"\n 4. delete record ";
		cout<<"\n 5. search record ";
		cout<<"\n 6. view all records ";
		cout<<"\n 7. exit ";
		cout<<"\n enter choice ";
		cin >> ch;
		
		switch(ch)
		{
			case 1: //add record
				obj.build();
				break;
				
			case 2: //add record
				obj.addRecord();
				break;
				
			case 3: //modify record
				obj.modifyRecord();
				break;		
				
			case 4: //delete record
				obj.deleteRecord();
				break;		
				
			case 5: //search record
				obj.searchRecord();
				break;		
				
			case 6: //view all record
				obj.viewAllRecords();
				break;						
			
		}//switch
		
	}while(ch != 7);
	
	return 0;
}

