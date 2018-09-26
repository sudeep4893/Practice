#include<iostream.h>
#include<stdio.h>
#include<fstream.h>
#include<string.h>

/*
Design a base class consisting
of the data members such as
name of the student,roll number
and subject.

The derived class consists of
the data members subject code ,
internal assessment and
university examination marks.

Use the concept of friend class
and file handling and perform
following operations

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
	protected:
	int rno;
	char name[20];
	char subject[20];
};

class StudentResult : virtual public Student
{
	protected :
	int imarks, umarks, sid;

	public:
	void set();
	void disp();

	//allow all fns of FHandler
	//to access all members
	//(private, protected) of
	//StudentResult

	friend class FHandler;
};


void StudentResult:: set()
{
	cout<<"\n enter rno ";
	cin>>rno;
	cout<<"\n enter name ";
	cin>>name;
	cout<<"\n enter subject ";
	cin>>subject;

	cout<<"\n enter subject id ";
	cin>>sid;
	cout<<"\n enter imarks ";
	cin>>imarks;
	cout<<"\n enter u marks ";
	cin>>umarks;

}

void StudentResult:: disp()
{
	cout<<"\n "<<rno<<" "<<name <<" "<<subject;
	cout<<" " <<sid<<" "<<imarks<<" "<<umarks;
}

class FHandler
{
	char fname[100];
	public:

	FHandler(char []);
	void add();
	void build();
	void search();
	void modify();
	void del();
	void dispAll();
};

FHandler :: FHandler(char s[])
{
	strcpy(fname, s);
}


void FHandler ::add()
{
 //add a student record
	ofstream fout;
	fout.open(fname, ios::binary|ios::app);

	if(!fout)
	{
		cout<<"\n add record failed ";
		return;//terminate add()
	}
	//add record
	StudentResult s;
	s.set();

	//write object s in the file

	//fns takes 2 params
	//1. address of obj, in char pointer format
	//2. sizeof obj
	fout.write((char*)&s, sizeof(StudentResult));

	//close file
	fout.close();

}

void FHandler :: dispAll()
{
	//read all records from file
	//and display on screen

	ifstream fin;
	fin.open(fname, ios::binary);

	if(!fin)
	{
		cout<<"\n dispAll failed ";
		return;
	}

	StudentResult s;

	while( fin.read((char*)&s, sizeof(StudentResult)))
	{
		s.disp();
	}

	fin.close();
}

void FHandler :: search()
{
	//sequential search

	ifstream fin;
	fin.open(fname, ios::binary);

	if(!fin)
	{
		cout<<"\n search failed ";
		return;
	}
	int r, flag;
	cout<<"\n enter rno to search ";
	cin>>r;

	StudentResult s;
	flag = 0;

	while( fin.read((char*)&s, sizeof(StudentResult)))
	{
		if(s.rno == r)
		{
			s.disp();
			flag = 1;
			break;
		}
	}

	if(flag == 0)
	{
		cout<<"\n "<<r<<" not found";
	}

	fin.close();

}

void FHandler :: modify()
{
	//to support read and writing both
	fstream fio;
	fio.open(fname, ios::in|ios::out|ios::binary);

	if(! fio)
	{
		cout<<"\n modify failed ";
		return;///terminate fn
	}

	int r, flag;
	int cnt;
	StudentResult s;
	cout<<"\n enter rno to modify ";
	cin>>r;

	flag = 0;
	cnt = 0;
	while( fio.read((char*)&s, sizeof(StudentResult)))
	{
		if(s.rno == r)
		{//match found
		 	//modify it
			//accept new data
			s.set();
			//set file write (put) pointer position
			//seekp(offset, from where);
			//cout<<"\n"<<fio.tellp();//read the current put pointer pos
			fio.seekp(cnt * sizeof(StudentResult), ios::beg);
			//cout<<"\n"<<fio.tellp();
			//write the data in file
			fio.write((char*)&s, sizeof(StudentResult));

			flag = 1;
			break;
		}

		cnt++;
	}

	if(flag == 0)
	{
		cout<<"\n rno "<<r<<" not found ";
	}
	fio.close();

}

void FHandler :: del()
{
	ofstream fout;
	ifstream fin;

	fin.open(fname, ios::binary);
	fout.open("d:\\temp.txt", ios::binary|ios::trunc);

	if(! (fin && fout))
	{
		cout<<"\n delete failed ";
		return ;
	}

	int r, flag;
	StudentResult s;

	cout<<"\n enter rno to delete ";
	cin>>r;

	flag = 0;

	while( fin.read((char*)&s, sizeof(StudentResult)))
	{
		if(s.rno != r)
		{ //transfer in temp file
			fout.write((char*)&s, sizeof(StudentResult));
		}
		else
		{
			flag = 1;//found a match that should not be transfered
		}
	}//while
	fin.close();
	fout.close();

	//if flag is 0 then r is not
	//found and fname and temp
	//are the same
	//if flag is 1 then r was
	//found and temp contains
	//lesser records than fname
	if(flag == 0)
	{
		cout<<"\n "<<r<<" not found ";
		remove("d:\\temp.txt");
	}
	else
	{
		remove(fname);
		rename("d:\\temp.txt", fname);
	}

}


void FHandler :: build()
{
	ofstream fout;
	fout.open(fname, ios::binary|ios::out|ios::trunc);
	if(!fout)
	{
		cout<<"\n Build Failed ";
		return;
	}
	fout.close();

	char ch;
	do
	{
		add();
		cout<<"\n continue ? ";
		cin>>ch;
	}while(ch == 'y');

}

int main()
{
	int ch;
	FHandler fh("d:\\student.txt");

	do
	{
		cout<<"\n 1. Build a master table";
		cout<<"\n 2. List a table ";
		cout<<"\n 3. Insert a new entry ";
		cout<<"\n 4. Delete old entry ";
		cout<<"\n 5. Edit an entry";
		cout<<"\n 6. Search for a record ";
		cout<<"\n 7. exit ";
		cout<<"\n enter choice ";
		cin>>ch;

		switch(ch)
		{
			case 1:
				fh.build();
				break;
			case 2:
				fh.dispAll();
				break;
			case 3:
				fh.add();
				break;
			case 4:
				fh.del();
				break;
			case 5:
				fh.modify();
				break;
			case 6:
				fh.search();
				break;

		}
	}while(ch != 7);
	return 0;
}
