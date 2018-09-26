#include <iostream>
using namespace std;

/*
Create a class named Television 
that has data members 
	model number 
	screen size 
	price.
	
Member functions
	overloaded insertion operator
	overloaded extraction operator.
	
If more than four digits are entered for the model number
If the screen size is smaller than 12 or greater than 70 
If the price is negative or over $5000 

Then throw an integer.

Write a main() function that 
1) instantiates a television object
2) allows user to enter data 
3) displays the data members.

If an exception is caught ,
replace all the data member 
values with zero values.

*/

class Television 
{
	int model_number; 
	int screen_size;
	int price;	
	
	public:
		void reset();
		friend ostream & operator <<(ostream &out, Television &t);
		friend istream & operator >>(istream &in, Television &t);
};

void Television :: reset()
{
	model_number = 0; 
	screen_size = 0;
	price= 0;	
}

ostream & operator <<(ostream &out, Television &t)
{
	out<<"\n Model Number : "<< t.model_number; 
	out<<"\n Screen Size : "<< t.screen_size;
	out<<"\n Price : "<< t.price;	
	return out;
}

istream & operator >>(istream &in, Television &t)
{
	cout<<"\n Enter Model Number : ";
	in>> t.model_number; 
	if(t.model_number > 9999)
	{
		throw -1; //raise an int exception
	}
	
	cout<<"\n Enter Screen Size : ";
	in>> t.screen_size;
	if(t.screen_size < 12 || t.screen_size > 70)
	{
		throw -2; //raise an int exception
	}
	
	cout<<"\n Enter Price : ";
	in>> t.price;	
	if(t.price < 0 || t.price > 5000)
	{
		throw -3; //raise an int exception
	}

	return in;
}


int main()
{
	Television tv;
	try
	{
		cin>>tv;
  }
  catch(int errId)
  {
  	switch(errId)
  	{
  		case -1:
				cout<<"\n Invalid Model Number ";
				break;	
  		case -2:
				cout<<"\n Invalid Screen Size ";
				break;	
  		case -3:
				cout<<"\n Invalid Price ";
				break;	
  	}//switch
  	
  	tv.reset();
  }
	cout<<tv;
	return 0;
}