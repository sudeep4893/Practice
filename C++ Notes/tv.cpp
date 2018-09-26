#include<iostream>

using namespace std;

/*
Create a class named Television that has 
data members 
	model number 
	screen size 
	price
Member functions
	overloaded insertion operators.
	overloaded extraction operators.
	
If more than four digits are entered 
for the model,if the screen size is 
smaller than 12 or greater than 70 
inches, or if the price is negative 
or over $5000 
then throw an integer.

Write a main() function that instantiates 
a television object,allows user to enter 
data and displays the data members .

If an exception is caught, replace all 
the data member values with zero values.
*/

class Television
{
	int model_number;
	int screen_size; 
	int price;
	
	public:
		friend istream& operator >> (istream & in, Television &t);
		friend ostream& operator << (ostream & out, Television &t);
		void reset();	
};

istream & operator >> (istream & in, Television &t)
{
	cout<<"\n Enter model number ";
	in >> t.model_number;
	if(t.model_number > 9999)
	{
		throw -1; //rasing an int exception
	}
	
	cout<<"\n Enter screen size ";
	in >> t.screen_size; 
	if(t.screen_size < 12 || t.screen_size > 70)
	{
		throw -2; //rasing an int exception
	}
	
	cout<<"\n Enter price ";
	in >> t.price;
	if(t.price < 0 || t.price > 5000)
	{
		throw -3; //rasing an int exception
	}
	return in;
}

ostream& operator << (ostream & out, Television &t)
{
	out<<"\n model number "<< t.model_number;
	out<<"\n screen size "<< t.screen_size; 
	out<<"\n price "<< t.price;
	return out;
}

void Television :: reset()
{
	model_number = 0;
	screen_size = 0; 
	price = 0;
}


int main()
{
	Television tv;
	try
	{
		cin>>tv;	
	}
	catch(int errId)//a catch to handle int exceptions
	{
		switch(errId)
		{
			case -1:
				cout<<"\n invalid model number ";
				break;
			case -2:
				cout<<"\n invalid screen size ";
				break;
			case -3:
				cout<<"\n invalid price ";
				break;
		}//switch
		
		tv.reset();		
	}
	
	cout<<tv;
	
	return 0;
}
