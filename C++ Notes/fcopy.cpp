#include <iostream>
#include <fstream>

using namespace std;

//Copy A File

int main()
{
	char src[20], trgt[20];
	
	cout<<"\n enter src file name ";
	cin>>src;
	
	cout<<"\n enter trgt file name ";
	cin>>trgt;
	
	//1. create objects 
	ifstream fin;
	ofstream fout;
	
	//2. open the files in binary mode
	fin.open(src, ios::binary);//file must exist
	fout.open(trgt, ios::binary);//file will be created or overwritten
	
	//3. test open status
	if(fin && fout)
	{
		//4. copy
		int data;
		
		while((data = fin.get()) != EOF)
		{
			fout.put(data);
		}
		
		//5. close
		fin.close();		
		fout.close();
		
		cout<<"\n File copied";
	}	
	else
		cout<<"\n File Open Failed";
		
	return 0;
}

/*
ofstream : a class in fstream.h that support file writing
open : a function of ofstream class that is used to open a file.
put(int) : a function of ofstream class that is used to write one byte of data into the file.
close : a function of ofstream class that is used to close a file.
*/