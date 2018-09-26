#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
Use STL for Sorting and searching 
with user-defined records such as 
item record (item code, item name, 
quantity and cost
*/
class ItemDB;

class Item
{
	int icode;
	char iname[20];
	int icost;
	int iqty;
	
	public:
		void set();
		void disp();
		friend class ItemDB;
		friend bool compareCost(const Item &i1, const Item &i2);
};

void Item :: set()
{
	cout<<"\n enter item code ";
	cin>>icode;
	cout<<"\n enter item name ";
	cin>>iname;
	cout<<"\n enter item cost ";
	cin>>icost;
	cout<<"\n enter item qty ";
	cin>>iqty;
}

void Item :: disp()
{
	cout<<"\n "<<icode<<"  "<<iname<<"  "<<icost<<"  "<<iqty;
}

bool compareCost(const Item &i1, const Item &i2)
{
	return i1.icost < i2.icost;
}

class ItemDB
{
	//STL Container
	//an array, of Item objects, that can dynamically grow/shrink
	vector<Item> allItems;
	
	//STL Iterator	
	vector<Item>::iterator vit;//to traverse through the container
	
	public:
		void addRecord();
		void modifyRecord();
		void deleteRecord();
		void searchRecord();
		void viewAllRecords();
		void sortRecords();
};

void ItemDB :: addRecord()
{
	Item obj;
	obj.set();
	
	allItems.push_back(obj);//vector expands
}

void ItemDB :: modifyRecord()
{
	int ic;
	int flag =0 ;
	
	cout<<"\n enter item code to modify ";
	cin>>ic;

	vit = allItems.begin();//points to first element of container

	while(vit != allItems.end())
	{
		if(vit->icode == ic)
		{
			cout<<"\n Existing Data ";
			vit->disp();//a mem fn of Item
			cout<<"\n Enter New Data ";
			vit->set();
			flag = 1;
			break;
		}
		vit++; //move next
	}//while
	
	if(flag == 0)
		cout<<"\n "<<ic<<" not found ";	
}

void ItemDB :: deleteRecord()
{
	int ic;
	int flag =0 ;
	
	cout<<"\n enter item code to delete ";
	cin>>ic;

	vit = allItems.begin();//points to first element of container

	while(vit != allItems.end())
	{
		if(vit->icode == ic)
		{
			cout<<"\n Deleting ";
			vit->disp();//a mem fn of Item
			
			allItems.erase(vit);//vector shrinks
			
			flag = 1;
			break;
		}
		vit++; //move next
	}//while
	
	if(flag == 0)
		cout<<"\n "<<ic<<" not found ";	
}

void ItemDB :: searchRecord()
{
	int ic;
	int flag =0 ;
	
	cout<<"\n enter item code to search ";
	cin>>ic;

	vit = allItems.begin();//points to first element of container

	while(vit != allItems.end())
	{
		if(vit->icode == ic)
		{
			vit->disp();//a mem fn of Item
			flag = 1;
			break;
		}
		vit++; //move next
	}//while
	
	if(flag == 0)
		cout<<"\n "<<ic<<" not found ";
}

void ItemDB :: viewAllRecords()
{
/*
	vit = allItems.begin();//points to first element of container

	while(vit != allItems.end())
	{
		vit->disp();//a mem fn of Item
		vit++; //move next
	}
*/
	int i, s;
	s = allItems.size();
	for(i =0; i< s; i++)
	{
		allItems[i].disp();
	}
}

void ItemDB :: sortRecords()
{
	//ready algorithm to sort any container
	sort(allItems.begin(), allItems.end(), compareCost);	
}


int main()
{
	int ch;
	ItemDB idb;
	
	do
	{
		cout<<"\n 1. Add Item ";
		cout<<"\n 2. Modify Item ";
		cout<<"\n 3. Delete Item ";
		cout<<"\n 4. Search Item ";
		cout<<"\n 5. View All Items ";
		cout<<"\n 6. Sort Items ";
		cout<<"\n 7. Exit ";
		cout<<"\n Enter Choice ";
		cin>>ch;
	
		switch(ch)
		{
			case 1://add 
				idb.addRecord();
				break;
			case 2://modify
				idb.modifyRecord();
				break;
			case 3://delete
				idb.deleteRecord();
				break;				
			case 4://search
				idb.searchRecord();
				break;
			case 5://view all
				idb.viewAllRecords();
				break;
			case 6://sort
				idb.sortRecords();
				break;
		}//switch	
		
	}while(ch != 7);
	
	return 0;
}
