/*
A stream is a software entity that allows
data transfer across applications/devices.

A stream may be unidirectional or bidirectional
and accordingly it will allow one way or two way
data transfer.

A stream must be
* Opened
* Read/Written
* Closed

A stream may be opened in 
* Text Mode : To support transmission of ASCII values in range 0-255.
* Binary Mode : To support transmission of all ASCII values.

There are 3 streams that are managed by the OS.
An application must only read/write those streams.
And the streams are :

1) Standard Input Stream
Is the stream between keyboard and application.
It is a binary stream represented by
System.in
System.in is a final, public and static data member 
that belongs to class System.
It is an object of class InputStream.

2) Standard Output Stream
Is the stream between the application and monitor.
It is a binary stream represented by
System.out
System.out is a final, public and static data member 
that belongs to class System.
It is an object of class PrintStream.


3) Standard Error Stream
Is the stream between the application and monitor.
It is a binary stream represented by
System.err
System.err is a final, public and static data member 
that belongs to class System.
It is an object of class PrintStream.

Important Methods of InputStream
--------------------------------
int read() :
Fetches one byte of data from the input stream.
Advances read pointer to next position.
Blocks execution if stream is empty.
Returns ASCII value of the fetched byte.
Returns -1 if it encounters EOF, EOS.
May raise IOException that the caller must handle.

int read(byte[]) :
Fetches n bytes of data from the input stream.
Where 
  n = size of byte array.
or
  n = number of bytes available in the stream.
whichever is less.
Advances read pointer n positions ahead.
Blocks execution if stream is empty.
Returns n.
Returns -1 if it encounters EOF, EOS.
May raise IOException that the caller must handle.

int available() :
Returns the number of bytes available
in the input stream.

skip(long n) :
Advance the file read pointer by n
positions ahead.
Doesnt fetch the bytes.

Important Methods of PrintStream
--------------------------------
write(int) :
Writes one byte of data into the stream.
The ASCII value of the byte is provided 
as a parameter to the method.

write(byte[], indxFrom, indxTo) :
Writes n bytes of data into the stream.
n = the range between indxFrom and indxTo.
indxFrom  is inclusive.
indxTo is exclusive.
The ASCII values in the byte array are written.

flush() :
Force transmit the internally buffered
data into the stream.

print() :
Used to print values of primary datatypes.
Overloaded to handle all java primary datatypes.

println() :
Used to print values of primary datatypes,
followed by a newline.
Overloaded to handle all java primary datatypes.

printf() :
for C like output.
*/

import java.io.IOException;

class IO
{
 static void writeDemo()
 {
  int data = 65;
  System.out.write(data);//ASCII val of 'A'
  System.out.flush();
 }

 static void writeDemo1()
 {
  byte arr[] = {65,66,67,68,69};
  System.out.write(arr, 0, 5);
  System.out.flush();
 }

 static void printfDemo()
 {
  char a = 'z';
  int b = -10;
  float c = 4.56F;
  System.out.printf("\n %c %d %f", a, b, c);
 } 

 static void printDemo()
 {
  int data = 65;
  System.out.println(data);//data is treated as an int, hence output = 65
 }
 
 static String getString() throws IOException
 {
  String temp= "";
  int data;
  do
  {
    data = System.in.read();  
    temp = temp + (char)data;
  }while(System.in.available() > 2);
  System.in.skip(2);
  //2 = 2 bytes (13 and 10) of enter, that user has pressed after input
  return temp;
 }

 static String getString1() throws IOException
 {
  byte data[] = new byte[100];
  int n;
  n = System.in.read(data);  
  String s = new String(data, 0, n-2);
  //0 to n-2 : is data
  //0 to n : is data followed by enter

  //in case data > 100 bytes, skip it.
  System.in.skip(System.in.available());
  return s;
 }

 public static void main(String args[])
 {
  //methods of PrintStream
  //writeDemo(); 
  //writeDemo1(); 
  //printfDemo();
  //printDemo();

  try
  { 
   //methods of InputStream
   String s;
   System.out.println("Enter a string ");
   //s = getString();
   s = getString1();
   System.out.println("String : " + s );
  }
  catch(IOException ex)
  {}
 }
}

