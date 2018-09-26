#include<stdio.h>
#include<stdlib.h>

//File Handling
/*
 
File Handling means input/output (read/write)
operations with files stored on disk.
 
To implement file handling. 
1) open a file 
2) read from it / write into it 
3) close the file  

--------------------------------------------------- 
1) Opening a file 
Creates a stream between program and the disk. 
The stream allows unidirectional or bidirectional
data transfer. 
 
Use the function fopen() to open a file.
It takes 2 parameters 
1) File name  (with complete path).
2) File open mode. 
Possible modes are 

  "r"  : Open the file for reading only. File must exist.
  "w"  : Open the file for writing only. File will be created/overwritten.
  "a"  : Open the file for append (writing at end) only. File will be created/appended.    
The above three operations will be performed in text mode. 
  
  "rb"  : Open the file for reading only. File must exist.
  "wb"  : Open the file for writing only. File will be created/overwritten.
  "ab"  : Open the file for append (writing at end) only. File will be created/appended.    
The above three operations will be performed in binary mode. 
 
  "r+"  : Open the file for reading and writing. File must exist.
  "w+"  : Open the file for writing and reading. File will be created/overwritten.
  "a+"  : Open the file for append (writing at end) and reading. File will be created/appended.    
The above three operations will be performed in text mode. 
  
  "rb+"  : Open the file for reading and writing. File must exist.
  "wb+"  : Open the file for writing and reading. File will be created/overwritten.
  "ab+"  : Open the file for append (writing at end) and reading. File will be created/appended.    
The above three operations will be performed in binary mode. 
 
 
Q) What is text mode and binary mode? 
A) Text mode allows transmission of data 
   in the range that is supported by systems
   ASCII character set.
 
   Binary mode allows transmission of all data values.
   (NO Limitation).

As file open succeeds the fopen() returns
a FILE pointer.
We must receive and preserve it for all
file operations ahead.  
 
But if file open fails the fopen() returns 
NULL. 
--------------------------------------------------- 
2) read from it / write into it 
 
 * Reading a character/byte from a file
 Use fgetc()function and pass the FILE pointer to it. 
 It fetches and returns current character/byte from the file
 and moves one position ahead. 
 It returns -1 or EOF at end of file.


 * Reading a line from a file
 Use fgets()function and pass 3 parameters to it.
 1) String (buffer).
 2) Max no of characters to fetch
 3) File pointer

 It fetches a string from the file and puts it into the buffer.
 and moves to the next line.
 It fetches max specific sized string or upto '\n' whichever comes first.

 It returns NULL at end of file.


 * Writing a character/byte to a file
 Use fputc()function and pass 2 parameters to it
1) char/byte to be written
2) FILE pointer 

 * Writing a line/string into a file
 Use fputs()function and pass 2 parameters to it
1) string to be written
2) FILE pointer 

 
--------------------------------------------------- 

3) close the file  
Use fclose() function and pass the FILE pointer to it.
It closes the stream between the program and the file.
 
--------------------------------------------------- 

 */
int main()
{
    FILE *fp;
    int x;
    
    fp = fopen("d:/a.txt", "r");
    
    if(fp == NULL)
    {
        printf("\n File open failed");
        exit(0);//terminate the program
    }

    //read all the characters, one by one
    while( (x = fgetc(fp)) != EOF)
    {
        printf("%c", (char)x);        
    }
    
    //reading done, close the file
    fclose(fp);
    return 0;
}