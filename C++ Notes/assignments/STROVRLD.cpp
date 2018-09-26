/*
Write a C++ program to perform String operations
i. = Equality
ii. == String Copy
iii. + Concatenation
iv. << To display a string
v. >> To reverse a string
vi. Function to determine whether a string is a palindrome
vii. To find occurrence of a sub-string. 

Use Operator Overloading
*/
#include<iostream>
#include<string.h>

#define SIZE 30

using namespace std;

class String
{
	char data[SIZE];
	public:
		void set();
		void operator ==(String & r);
		int operator = (String &r);
		void operator + (String &r);
		void operator >>(String & r);
		int palindrome();
		int subString(String &ref);
		
		
		friend ostream & operator <<(ostream &out, String &s);
		
};

void String :: set()
{
	cout<<"\n enter a string ";
	cin>>data;
}

int String :: operator = (String &r)
{
	int x;
	x = strcmp(data, r.data);
	if(x == 0)
		return 1;//true
	else
		return 0;//false
}

void String :: operator ==(String & r)
{
	strcpy(data, r.data);
}

void String :: operator + (String &r)
{
	strcat(data, r.data);
}

ostream & operator <<(ostream &out, String &s)
{
	out<<"\n"<<s.data;
	return out;
}

void String :: operator >>(String & r)
{
	strcpy(r.data, data);
	strrev(r.data);
}

int String :: palindrome()
{
	int x = 0;
	int y = strlen(data)-1;
	
	while(x < y)
	{
		if(data[x] != data[y])
			return 0;
		x++;
		y--;
	}
	return 1;
}

int String :: subString(String &ref)
{
	char *p;

	p = data;

	p = strstr(p, ref.data);
	if(p != NULL)
		return 1;
	else
		return 0;
	
}


int main()
{
	int ch;
	String s1, s2;
	do
	{
				
		cout<<"\n 1 = Equality ";
		cout<<"\n 2 == String Copy ";
		cout<<"\n 3 + Concatenation ";
		cout<<"\n 4 << To display a string ";
		cout<<"\n 5 >> To reverse a string ";
		cout<<"\n 6 Determine palindrome ";
		cout<<"\n 7 Find occurrence of a sub-string";
		cout<<"\n 8 exit";
		cout<<"\n enter choice ";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				s1.set();
				s2.set();
				if(s1 = s2)
					cout<<"\n strings are equal";
				else
					cout<<"\n strings are not equal";
				break;

			case 2:
				s1.set();
				s2 == s1;
				cout<<s1;
				cout<<s2;
				break;
				
			case 3:
				s1.set();
				s2.set();
				s1+s2;
				cout<<s1;
				cout<<s2;
				break;
				
			case 4:
				s1.set();
				cout<<s1;				
				break;
				
			case 5:
				s1.set();
				s1>>s2;
				cout<<s1;
				cout<<s2;
				break;
			case 6:
				s1.set();
				if(s1.palindrome())
					cout<<s1<< " is Palindrome";
				else
					cout<<s1<< " is not a Palindrome";
				break;

			case 7:
				s1.set();
				s2.set();
				if(s1.subString(s2))				
					cout<<s2<< " is SubString";
				else
					cout<<s2<< " is not a SubString";
					
				break;
			
		}//switch	
	}while(ch != 8);
	 
	return 0;
}