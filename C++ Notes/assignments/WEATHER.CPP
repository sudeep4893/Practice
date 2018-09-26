/*
Create a class named weather report 
that holds a daily
weather report with data members

day_of_month,
hightemp,
lowtemp,
amount_rain and
amount_snow.

The constructor initializes the
fields with default values:
99 for day_of_month,
999 for hightemp,
-999 for low emp and
0 for amount_rain and amount_snow.

Include a function that prompts
the user and sets values for
each field so that you can
override the default values.

Write a program that creates a
monthly report.

*/

#include<iostream>
#define SIZE 3

using namespace std;

class Weather
{
private:
	int day_of_month;
	int hightemp;
	int lowtemp;
	int amount_rain ;
	int amount_snow;
public:
	Weather();
	void set();
	void disp();
};

Weather :: Weather()
{
	day_of_month = 99;
	hightemp = 999;
	lowtemp = -999;
	amount_rain = 0;
	amount_snow = 0;
}

void Weather::set()
{
	cout<<"\n enter day of month ";
	cin >>day_of_month;

	cout<<"\n enter hig temp ";
	cin >>hightemp;

	cout<<"\n enter low temp ";
	cin >> lowtemp;

	cout<<"\n enter amt of rainfall ";
	cin >>amount_rain;

	cout<<"\n enter amt of snowfall ";
	cin>>amount_snow;
}

void Weather:: disp()
{
	cout<<"\n===========================";
	cout<<"\n day of month : "<< day_of_month ;
	cout<<"\n high temp : " << hightemp;
	cout<<"\n low temp : "<< lowtemp;
	cout<<"\n amt rainfall : "<< amount_rain;
	cout<<"\n amt snowfall : "<< amount_snow;
}

int main()
{
	int i;

	//create a monthly report
	//and set it to default values
	Weather monthly_rep[SIZE];

	//prompt user to provide values
	//that override the default values
	for(i =0; i< SIZE; i++)
	{
		monthly_rep[i].set();
	}

	//display the monthly report
	for(i =0; i< SIZE; i++)
	{
		monthly_rep[i].disp();
	}
	
	return 0;
}