/*
Inheritance
is the mechanism that allows a class
(entity) to get code (operations)
and data (characteristics) from an
existing class (entity).

"extends" keyword is use to apply
inheritance in Java.

Java allows a class to extend another
class.
Java allows an interface to extend
one to many interfaces.

The inheriting class/interface is called
as "sub class"/"sub interface".

The inherited class/interface is called
as "super class"/"super interface".

The sub class/interface gets code
and data from the super class/interface.
Reverse is not true.

*/

class A
{
 void f1()
 {
  System.out.println("A f1()");
 }

 void f2() //overridden method
 {
  System.out.println("A f2()");
 }
}//A

class B extends A //class B inherits class A
{
 void f2()//overriding method
 {
  System.out.println("B f2()");
 }

 void f3()
 {
  System.out.println("B f3() starts");
  f2(); //will map with f2() of B
  super.f2();//will map with f2() of A
  System.out.println("B f3() ends");
 }
}//B

class InhertianceDemo
{
 public static void main(String args[]) 
 {
  B objB = new B();
  objB.f1();
  objB.f2();//compile time bound
  objB.f3();
 }//main
}//InheritanceDemo

/*
Method Overriding
Method Overriding is redefining a
super class method in the sub class
keeping the methods signature exactly
same.
-------------------------------
super
------
super keyword is used in non static
methods of the sub class to refer to
the super class.

It provides access to the 
* Constructors
* Hidden members
* Overridden members
of the super class.

*/