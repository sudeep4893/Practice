#include <iostream>
#include <fstream>
using namespace std;

/*

more about files

Read/Write/Both

	To read from a file use ifstream object and fns
	To write into a file use ofstream object and fns
	To read and write a file use fstream object and fns
	(fstream class is a class derived from ifstream and ofstream)
	

Seek
-----
As a file is opened its get and put
pointers are at BOF by default.
So read/write operations begin from BOF
by default.

A programmer uses seekg/seekp to position 
the files get/put pointers at a target
location.
This helps in performing read/write 
operations at target location.


	ifstream
		get pointer
		movable : seekg(offset, whence)
			offset  : int val
			whence  : ios::beg, ios::cur, ios::end
	
	ofstream
		put pointer
		movable : seekp(offset, whence)
			offset : int val
			whence : ios::beg, ios::cur, ios::end
	
	fstream
		get pointer
		put pointer
		supports seekg() and seekp()

*/
int main()
{
	fstream fio; //a child class of ifstream and ofstream
	fio.open("d:/temp.txt", ios::in|ios::out);//open the file for reading and writing	
	
	if(! fio)
	{
		cout<<"\n file open failed";
	}	

	int i, x, data;
	x = fio.tellg();//get the position of get pointer
	cout<<"\n get pointer is at pos : "<<x;		

	data = fio.get();//fetch one byte of data
	cout<<(char)data;
	
	
	fio.seekp(10, ios::beg);
	x = fio.tellp();//get the position of put pointer
	cout<<"\n pet pointer is at pos : "<<x;		
	fio.put('Q');//write one char into the file	
	
	//read the file in reverse
	
	fio.seekg(0, ios::end);//position get pointer at EOF
	x = fio.tellg();//read the EOF position (not the data)
	cout<<"\n get pointer is at pos : "<<x <<"\n";		

	
	for(i = x-1; i>=0; i--)
	{
		fio.seekg(i, ios::beg);
		data = fio.get();
		cout<<(char)data;	
	}
	
	fio.close();
	return 0;
}

