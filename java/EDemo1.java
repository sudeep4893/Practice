/*
Exception Handling
-----------------
Exceptions are "runtime errors" that
cause abnormal program termination.

To protect the program from abnormal
termination, the exceptions must be
handled.
And to do so, Java provides 
"try", "catch", "finally", "throws" and "throw"
blocks/statements.


try 
------
A try block contains code that is likely 
to generate exceptions.
System "monitors" the code of try block
for exceptions.
The moment some "exception occurs" in
code of "try block", program control doesnt 
terminate abnormally but is transferred
into a catch block for "exception handling".

But if the try block has no catch block that 
corresponds to the current exception then
program will be terminated abnormally.

As any of the multiple possible exceptions 
may get raised in a try block, so it is
associated with equivalent number of 
catch blocks.

catch 
------
A catch block is associated with a 
try block and it follows the "try block".
It is the exception handler.
It handles one type of exception.
It ensures cancellation of abnormal 
termination of the program and also 
ensures that normal program flow will 
resume with code ahead.
Code of the catch block executes only
if an exception corresponding to the
one that it handles, occurs otherwise not.

finally 
--------
A finally block is also associated with
a try block.
If the try has catch block(s) then the
finally block follows the last catch block.
Otherwise it follows the try block.

System ensures call to finally block
irrespective of occurrence of an 
exception and of its handling.

It is generally used to perform some
resource deallocation operations.
*/

class EDemo1
{
 public static void main(String args[])
 {
  System.out.println("--------------");
  int a, b, c;

  try
  {
  //input  
  a = Integer.parseInt(args[0]);//first command line argument
  b = Integer.parseInt(args[1]);//second command line argument

  c = a/b; //process

  //output
  System.out.println("a :  " +a);
  System.out.println("b :  " +b);
  System.out.println("c :  " +c);
 }//try
 catch(NumberFormatException ex)
 {
  System.out.println("Invalid Data");
 }
 catch(ArrayIndexOutOfBoundsException ex)
 {
  System.out.println("Insufficient Data");
 }
 catch(ArithmeticException ex)
 {
  System.out.println("Infinity");
 }
 finally
 {
  System.out.println("FINALLY");
 }
 
  System.out.println("--------------");
 }//main
}//EDemo1

/*
int Integer.parseInt(String param)
==============================
parseInt is a public static method of
class java.lang.Integer
It accepts a string value as parameter
and attempts to convert it into integer
equivalent.
If conversion succeeds, method completes
normally.
But if conversion fails, then the method
raises "NumberFormatException".
------------------------------------

ArrayIndexOutOfBoundsException
gets raised if there is an attempt to
access a non existing array element.
------------------------------------

ArithmeticException : Divide By Zero
occurs when a whole number is divided
by zero.
*/