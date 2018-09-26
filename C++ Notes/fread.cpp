#include <iostream>
#include <fstream>

using namespace std;
/*
File Handling
--------------
File Handling means performing input(read)
and output(write) operations on files that
are stored on disk.

General Steps for File Handling
--------------------------------
1) Open the file
2) Read/Write
3) Close the file


C++ provides numerous classes and function
(through header file fstream.h) that help
in performing file operations.
*/

//Read A File

int main()
{
	//1. create object of ifstream
	ifstream fin;
	
	//2. open the file
	fin.open("d:/a.txt");//file must exist
	
	//3. test open status
	if(fin)
	{
		//4. reading
		int data;
		
		while((data = fin.get()) != EOF)
		{
			cout<<(char)data;
		}
		//5. close
		fin.close();		
	}	
	else
		cout<<"\n File Open Failed";
		
	return 0;
}

/*
ifstream : a class in fstream.h that support file reading
open : a function of ifstream class that is used to open a file.
get() : a function of ifstream class that is used to fetch one byte of data from the file.
close : a function of ifstream class that is used to close a file.
*/