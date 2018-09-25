/*
Custom Exceptions
------------------
Custom Exceptions are user defined
exceptions, designed by defining classes
that extends java.lang.Exception

Why Custom Exceptions?
-----------------------
Custom exceptions are designed to deal
with logical issues.
Examples:
1) Negative amout inputted for deposit()
2) Digit/Symbol found in a name
3) Student with per > 100
4) >n attempts for login

When does a custom exception get raised?
---------------------------------------
A custom exception must be explicitly
raised as some logical issue is detected.

How to raise a custom exception?
------------------------------
To explicitly raise an exception
1) Create object of the respective exception class.
2) throw object.

Observe the use of "throw" statement
in the point above.

Java provides "throw" statement to
explicitly raise an exception.
It requires object of respective exception
class to be associated with it.

*/

class DataException extends Exception
{
  String msg;
  DataException(String s)
  {
   msg = s;
  }

  void display()
  {
   System.out.println("Data Exception : " + msg);
  }

  //recommended overrides
  public String toString() //generally used by generic handlers
  {
   return "DataException : " + msg;
  }
  public String getMessage() //generally used by generic handlers
  {
   return msg;
  }

}//DataException

class Myself
{
 String name;
 int age;
 
 Myself(String n, int a) throws DataException
 {
   setName(n);
   setAge(a);
 }

 void setName(String s) throws DataException
 {
   int i;
   char temp;
   for(i =0; i< s.length(); i++)
   {
    temp = s.charAt(i);

    if(! ((temp >=65 && temp <=90) || (temp >=97 && temp <=122)) )
    {
      //logical issue detected
      //raise an exception
      DataException de = new DataException("Non Alphabet, " + temp + ", found in name");
      throw de;
    }
   }//for
   name = s;
 }

 void setAge(int x) throws DataException
 {
  if(x < 0 || x > 100)
  {
    //logical issue detected
    //raise an exception
     DataException de = new DataException("Age value, " + x + ", found out of range");
     throw de;
  }
  age = x;
 }//setAge

 void display()
 {
  System.out.println(name +" " + age);
 }

 public static void main(String args[]) 
 {
  try
  {
   String q = args[0];
   int w = Integer.parseInt(args[1]);
   Myself m = new Myself(q, w);
   m.display();
  }
  catch(ArrayIndexOutOfBoundsException ex)
  {
   System.out.println("Insufficient Values");
  }
  catch(NumberFormatException ex)
  {
   System.out.println("Invalid Value For Age");
  }
  catch(DataException ex)
  {
   ex.display();
  }
  catch(Exception ex)//Generic Exception Handler that can handle almost all types of exceptions.
  {
   System.out.println("Error : "+ ex); //ex == ex.toString() call
  }

 }//main
}

/*
Checked and UnChecked Exceptions
-------------------------------
With respect to compilation exceptions
are categorized into
1) Checked Exceptions
2) UnChecked Exceptions

For a checked execption, the compiler
ensures handling.
i.e. It ensures that all possible checked
exceptions are either caught or declared
to be thrown.

For a unchecked execption, the compiler
doesnt raise any issue.
i.e. It wont bother about the handling
or delegation of unchecked exceptions.

------------------------------------
Exception 
----------
Known that Exception class is the widely
used super class for Exceptions in Java.
Also known that inheritance creates
type compatibility.

Hence a catch block that uses an 
Exception reference can handle almost 
all types of exceptions.

Such a catch block is refered as 
"Generic Exception Handler".

For a try every exception must be
handled maximum once.
i.e. for a try there should not be 
multiple catch blocks that handle the 
same exception.

Since the generic execption handler
(the catch with Exception reference)
can handle all the exceptions, so all
the catch blocks that follow the generic
exception handler, become duplicate
handlers, hence become illegal.

Hence the specific exception handling
catch blocks must be defined first
and the generic exception handling catch
block must be defined as last exception
handler to handler all unseen exceptions.

*/