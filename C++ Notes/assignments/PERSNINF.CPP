/*
Develop an object oriented
program in C++ to create a
database of the personnel
information system containing
the following information:

Name, Date of Birth, Blood group,
Height,Weight, Insurance Policy
number,Contact address,telephone number,driving licence no. etc

Construct the database with
suitable member functions for
initializing and
destroying the data
viz constructor,
default constructor,
copy constructor,
destructor,
static member functions,
friend class,
this pointer,
inline code and
dynamic memory allocation
operators-new and delete.

*/


#include<iostream>
#include<string.h>
#define SIZE 10

using namespace std;

class PersonDB;

class Person
{
	private:
	char name[20];
	char dob[20];
	char bldGrp[4];
	int height, weight;
	char ipNum[20], address[20];
	char teleNum[20], drvLscNum[20];

	public:
	Person();
	Person(Person &);
	void disp();
	void set();

	//inline
	~Person()
	{
		cout<<"\n Object Destroyed ";
	}

	friend class PersonDB;
};


Person :: Person()
{
	cout<<"\n Enter name : ";
	cin>>name;
	cout<<"\n Enter dob : ";
	cin>>dob;
	cout<<"\n Enter blood group : ";
	cin>>bldGrp;

	cout<<"\n Enter Height : ";
	cin>>height;
	cout<<"\n Enter Weight : ";
	cin>>weight;

	cout<<"\n Enter Insurance Pol. Num : ";
	cin>>ipNum;
	cout<<"\n Enter Contact Address : ";
	//cin>>address;
	cin.get(); //to clear enter pressed after prev entry
	cin.getline(address, 19, '\n');

	cout<<"\n Enter telephone number : ";
	cin>>teleNum;
	cout<<"\n Enter driving liscence number : ";
	cin>>drvLscNum;
}

Person :: Person(Person & r)
{
	strcpy(name, r.name);
	strcpy(dob, r.dob);
	strcpy(bldGrp, r.bldGrp);

	height = r.height;
	weight = r.weight;

	strcpy(ipNum, r.ipNum);
	strcpy(address,r.address);
	strcpy(teleNum, r.teleNum);
	strcpy(drvLscNum, r.drvLscNum);
}


void Person :: set()
{
	cout<<"\n Enter name : ";
	cin>>name;
	cout<<"\n Enter dob : ";
	cin>>dob;
	cout<<"\n Enter blood group : ";
	cin>>bldGrp;

	cout<<"\n Enter Height : ";
	cin>>height;
	cout<<"\n Enter Weight : ";
	cin>>weight;

	cout<<"\n Enter Insurance Pol. Num : ";
	cin>>ipNum;
	cout<<"\n Enter Contact Address : ";
	//cin>>address;
	cin.get(); //to clear enter pressed after prev entry
	cin.getline(address, 19, '\n');

	cout<<"\n Enter telephone number : ";
	cin>>teleNum;
	cout<<"\n Enter driving liscence number : ";
	cin>>drvLscNum;
}

void Person ::disp()
{
	cout<<"\n "<<this->name;
	cout<<" "<<this->dob;
	cout<<" "<<this->bldGrp;

	cout<<" "<<this->height;
	cout<<" "<<this->weight;

	cout<<" "<<this->ipNum;
	cout<<" "<<this->address;

	cout<<" "<<this->teleNum;
	cout<<" "<<this->drvLscNum;
}


class PersonDB
{
	Person * tbl[SIZE];
	int n;
	int isBuilt;
	public:
	PersonDB();
	static void build(PersonDB&);
	void add();
	void dispAll();
	void search();
	void modify();
	void del();
	~PersonDB();
};

PersonDB::PersonDB()
{
	isBuilt = 0;//false
}

void PersonDB :: build(PersonDB & r)
{//static fn accessing non static members through explicit caller object
	r.n = 0;
	r.isBuilt = 1;//true
}

void PersonDB :: add()
{
	if(isBuilt == 0)
	{
		cout<<"\n Build the table first ";;
		return;
	}

	if(n < SIZE)
	{
		tbl[n] = new Person();
		n++;
	}
	else
	{
		cout<<"\n Table is FULL ";
	}
}

void PersonDB :: dispAll()
{
	if(isBuilt == 0)
	{
		cout<<"\n Build the table first ";;
		return;
	}

	int i;
	for(i =0; i< n; i++)
	{
		tbl[i]->disp();
	}
}

void PersonDB :: search()
{
	if(isBuilt == 0)
	{
		cout<<"\n Build the table first ";;
		return;
	}

	char x[20];
	int i;
	int flag = 0;

	cout<<"\n enter name to search ";
	cin>>x;

	//sequential search
	for(i =0; i< n; i++)
	{
		if(strcmp(tbl[i]->name, x)==0)
		{
			tbl[i]->disp();
			flag = 1;
			break;
		}
	}
	if(flag == 0)
	{
		cout<<"\n"<<x<<" not found ";
	}
}//search

void PersonDB :: modify()
{
	if(isBuilt == 0)
	{
		cout<<"\n Build the table first ";;
		return;
	}

	char x[20];
	int i;
	int flag = 0;

	cout<<"\n enter name of record to modify ";
	cin>>x;

	//sequential search
	for(i =0; i< n; i++)
	{
		if(strcmp(tbl[i]->name, x)==0)
		{
			tbl[i]->disp();
			cout<<"\n enter new data ";
			tbl[i]->set();
			flag = 1;
			break;
		}
	}
	if(flag == 0)
	{
		cout<<"\n"<<x<<" not found ";
	}
}

void PersonDB :: del()
{
	if(isBuilt == 0)
	{
		cout<<"\n Build the table first ";;
		return;
	}

	char x[20];
	int i;
	int flag = 0;

	cout<<"\n enter name of record to delete ";
	cin>>x;

	//sequential search
	for(i =0; i< n; i++)
	{
		if(strcmp(tbl[i]->name, x)==0)
		{
			tbl[i]->disp();
			delete tbl[i];

			//shift the records one pos left
			int j;
			for(j =i; j<n; j++)
			{
				tbl[j] = tbl[j+1];
			}
			n--; //reduce size

			flag = 1;
			break;
		}
	}
	if(flag == 0)
	{
		cout<<"\n"<<x<<" not found ";
	}
}

PersonDB::~PersonDB()
{
	int i;
	for(i =0; i< n;i++)
	{
		delete tbl[i];
		tbl[i] = NULL;
	}
}

int main()
{
	PersonDB pdb;


	int ch;
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
				PersonDB::build(pdb);
				break;
			case 2:
				pdb.dispAll();
				break;
			case 3:
				pdb.add();
				break;
			case 4:
				pdb.del();
				break;
			case 5:
				pdb.modify();
				break;
			case 6:
				pdb.search();
				break;

		}
	}while(ch != 7);
	
	return 0;
}


