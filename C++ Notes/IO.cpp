#include<iostream>
using namespace std;

/*
IO Manipulators

Manipulators are special functions that
work on IO streams.
Their main purpose is to make IO operations
more presentable.

There are 2 types of manipulators
1) input manipulators
2) output manipulators
They work on IO streams respectively.

Manipulators have special signatures.

Input Manipulator:
	istream & iManip(istream &in)
	{
	  ....
	  return in;
	}

Output Manipulator:
	ostream & oManip(ostream &out)
	{
	  ....
	  return out;
	}

*/

ostream & msgManip(ostream & out)
{
	out<<"\n";
	out.width(15);
	out.unsetf(ios::right);
	out.setf(ios::left);
	//out.fill('.');
	return out;
}

ostream& outManip(ostream & out)
{
	out.unsetf(ios::left);
	out.setf(ios::right);//data alignment
	out.width(15);//output width
	//out.fill('.');//filler for blanks
	return out;
}

int main()
{
/*	
	int rno;
	char name[20];
	cout<<msgManip<<"enter rno ";
	cin>>rno;
	
	cout<<msgManip<<"enter name ";
	cin>>name;

	cout<<msgManip<<"Rno"<<outManip<<rno;
	cout<<msgManip<<"Name"<<outManip<<name;
	
*/
	
	//float f;
	//f = 456.789;
	//cout.setf(ios::scientific);//show number  in scientic format
	//cout.setf(ios::showpos);//show sign for positive numbers as well
	//cout<<"\n"<<f;
	
	int x = 10;
	
	cout.setf(ios::hex|ios::uppercase);
	cout<<"\n"<<x;//A HEX
	
	cout.unsetf(ios::uppercase);
	cout<<"\n"<<x;//a  hex
	
	cout.unsetf(ios::hex);
	cout.setf(ios::oct);
	cout<<"\n"<<x;//12 oct
	
	cout.unsetf(ios::oct);
	cout<<"\n"<<x;//10 decimal
			
	return 0;
}