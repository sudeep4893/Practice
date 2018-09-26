/*
Design a base class with
name,date of birth,blood group
and another base class consisting
of the data members such as
height and weight.

Design one more base class
consisting of the
insurance policy number and
contact address.

The derived class contains the
 data members telephone numbers
and driving licence number.

Write a menu driven program to carry out the following things:
i) Build a master table
ii) Display
iii) Insert a new entry
iv) Delete entry
v) Edit
vi) Search for a record

*/

#include<iostream>
#include<string.h>
#define SIZE 10

using namespace std;

class PersonDB;

class Base1
{
	protected:
	char name[20];
	char dob[20];
	char bldGrp[4];
};

class Base2
{
	protected:
	int height, weight;
};

class Base3
{
	protected:
	char ipNum[20], address[20];
};

class Person : public Base1, public Base2, public Base3
{
	protected:
	char teleNum[20], drvLscNum[20];
	public:
	void set();
	void disp();

	friend class PersonDB;
};

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
	cout<<"\n "<<name;
	cout<<" "<<dob;
	cout<<" "<<bldGrp;

	cout<<" "<<height;
	cout<<" "<<weight;

	cout<<" "<<ipNum;
	cout<<" "<<address;

	cout<<" "<<teleNum;
	cout<<" "<<drvLscNum;
}

class PersonDB
{
	Person tbl[SIZE];
	int n;
	int isBuilt;
	public:
	PersonDB();
	void build();
	void add();
	void dispAll();
	void search();
	void modify();
	void del();
};

PersonDB::PersonDB()
{
	isBuilt = 0;//false
}

void PersonDB :: build()
{
	n = 0;
	isBuilt = 1;//true
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
		tbl[n].set();
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
		tbl[i].disp();
	}
}

void PersonDB :: search()
{//seq search

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
		if(strcmp(tbl[i].name, x)==0)
		{
			tbl[i].disp();
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
		if(strcmp(tbl[i].name, x)==0)
		{
			tbl[i].disp();
			cout<<"\n enter new data ";
			tbl[i].set();
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
		if(strcmp(tbl[i].name, x)==0)
		{
			tbl[i].disp();
			cout<<"\n record deleted ";

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
				pdb.build();
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
