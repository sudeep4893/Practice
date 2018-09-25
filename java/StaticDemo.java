/*
Java allows declaration of
   * member variables
   * member methods
   * initializer blocks
   * nested classes
as static.
------------------------------------
Member Variables
A member variable is a variable that belongs
to a class.
A member variable may be
* non static (default)
* static

non static member variables
-------------------------
The member variables of a class are 
non static by default.
Being non static they get allocated as 
a member inside every object of the 
class.
Being inside the object its life is equal to
life of the object.
It is accessible through the object only.
It is intialized by 
 * non static initializer
 * constructor

static member variables
----------------------
The member variables of a class can 
be declared as static.
Being static they get allocated one time
for the class.
Being a class level variable its life is 
equal to life of the class.
It is accessible through the class name.
It is intialized by 
 * static initializer block
------------------------------------
static initializer block

Java allows declaration of initializer blocks
as static.

* static intializer blocks are auto invoked
by the system as class gets loaded in memory.

* static intializer blocks are used 
1) to intialize the static member variables of the class.
2) to perform some one time operation on class initialization.

* If a class contains multiple static intializer
blocks then all get auto executed in the sequence
same as their order of declaration from top to 
bottom.
------------------------------------
Member Methods
A member method is a method that 
belongs to a class.
A member method may be
* non static (default)
* static

non static member methods
------------------------
* A member method is non static by default.
* Being non static
  a) It requires a caller object for invokation. 
  b) It can directly access all static and non static member of the class

static member methods
---------------------
* A member method may be declared as static.
* Being static
  a) It does not require any caller object for invokation.
  b) It can directly access the static members of the class.
  c) It cannot directly access the non static members of the class.

------------------------------------
Nested Class
... will be discussed in a separate example
------------------------------------

*/

class Another
{
 static
 {
  System.out.println("in static intializer block of Another");
 }

 Another()
 {
  System.out.println("Another()");
 }
}//Another

class StaticDemo
{
 int x;//non static member variable
 static int y;//static member variable

 static 
 {
  System.out.println("static intializer block1");
  y = 100;
 }
 
 StaticDemo()
 {
  System.out.println("StaticDemo()");
  x = 10;
 }

 StaticDemo(int q)
 {
  System.out.println("StaticDemo(int)");
  x = q;
 }

 static void increment(StaticDemo ref)
 {
  System.out.println("no caller object reqd");
  ref.x++;
  y++;
 }

 void display()
 {
  System.out.println(x + "  " + y);
 }

 public static void main(String args[])
 {
  System.out.println("main");
  StaticDemo sd1 = new StaticDemo();
  StaticDemo sd2 = new StaticDemo(50);

  increment(sd1);

  sd1.display();
  sd2.display();

  System.out.println("=======================");
  Another a1 = new Another();
  System.out.println("-----------------------");  
  Another a2 = new Another();
  System.out.println("=======================");
 }//main

 static 
 {
  System.out.println("static intializer block2");
  y++;
 }

}


/*
Q) Why is main static in java?
A) In Java, the main method is a 
member method.
Generally a member of a class requires
a caller object for invokation.
"static" allows invokation of main 
(the member of the class) without
any caller object.

*/