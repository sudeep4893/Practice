/*
Object, Object Creation, Object Intialization
*/

class AboutObjects
{
 int x, y; //member variables

 //non static initializer
 {
  System.out.println("in non static initializer1");
  x = 10;//preset value (default value)
  y = 20;//preset value (default value)
 }

 //constructors
 AboutObjects()//default constructor
 {
   System.out.println("AboutObjects()");
   x = 50;//preset data (default value)
   y = 100;//preset data (default value)
 }

 AboutObjects(int q, int w)//parameterized constructor
 {
   System.out.println("AboutObjects(int,int)");
   x = q;//parameter data
   y = w;//parameter data
 }


 //member methods
 void display()
 {
  System.out.println(x +"  " + y);
 }

 void AboutObjects()
 {
  System.out.println("In Java methods can have same name as of the class");
 }

 public static void main(String args[])
 {
  System.out.println("--------------");
  AboutObjects ao = new AboutObjects(1,2); //object of the class AboutObjects
  System.out.println("--------------");

  ao.display();
  ao.AboutObjects();//call to a method that has same name as of the class

 }//main

//non static initializer
 {
  System.out.println("in non static initializer2");
  x++;
  y++;
 }
}//AboutObjects

/*
Object
-------
An object is an instance of a class i.e. its datatype is a class.
An object is an entity that can store and process data.

Object Creation
---------------
An object can be created using the following syntax :
  className refName = new className();
  (see the daigram )

Object Intialization
------------------
As an object is created, system
1) allocates memory of the object in heap segement
2) executes the non static intializer blocks of the class.
3) executes constructor

non static intializer
------------------
A non static intializer is a block of code
(without any signature) that belongs to the class.
* It gets invoked automatiically as object of the class is created.
* It cannot be explicitly called.
* It is used to assign default values to the members of the current object.
* If a class has multiple non static initializers then all get invoked on object creation, 
  in a sequence same as the order of definition from top to bottom.

Constructor
-----------
A constructor is a special member method.
* It has the same name as of the class and no return type specification.
* It is invoked automatically by the system as object of the class is created.
* It cannot be explicitly called.
* It is used to intialize the members of the current object.

Constructors may be classified  as
1) Default Constructor
A default constructor is a constructor of the class that
* is parameterless, hence takes no input.
* assigns preset values to the member variables of the current object. 

2) Parameterized Constructor
A parameterized constructor is a constructor of the class that
* uses formal parameters to take input.
* assigns parameter values to the member variables of the current object. 

If the class doesn't define any constructor then system auto generates 
a public default constructor with empty definition, for the class.

class Q
{
 ...

 public Q()
 {}
 ...
}

Constructor Overloading
----------------------
Constructor overloading is defining multiple
constructors for a class with a different
set of parameters.

Conceptually constructor overloading is 
implementation of OOP concept polymorphism 
that specifies
"Define multiple ways to perform a task"

Here object members are initialized in
different ways.
*/