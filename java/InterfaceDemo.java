/*
Interface
---------
An interface is a collection of
* static and final variables
* abstract methods
* nested interfaces
* nested classes.

An interface defines a new "reference type"
in Java.
Being a "reference type", it cannot be instantiated.

Access Specifiers
-----------------
All members of an interface are "public"
by default.
"private" and "protected" members are 
not allowed in an interface.

Inheritance
------------
An interface can inherit zero to many other interfaces.
An interface cannot inherit any class.

Implementation
--------------
A class is used to implement zero to many interfaces.
Such a class
* Must override all the methods of all the implemented interfaces. Otherwise must become abstract.
* Becomes "type compatible" with all the implemented interfaces.
* Has direct access to interface members.
* Can have its own members.
*/

interface IFace1
{
 int q = 10;//public, static and final
 void f1();//public and abstract
}

interface IFace2
{
 void f2();//public and abstract
}

interface CIFace extends IFace1, IFace2
{
 void f3();
}

class UseIFace implements CIFace
{
 public void f1()
 {
  System.out.println("UseIFace f1()");
 }
 public void f2()
 {
  System.out.println("UseIFace f2()");
 }
 public void f3()
 {
  System.out.println("UseIFace f3()");
 }
 public void f4()
 {
  System.out.println("UseIFace f4()");
 }
}//UseIFace


class InterfaceDemo
{
 public static void main(String args[])
 {
  System.out.println("==========");
  IFace1 ref1 = new UseIFace();
  ref1.f1();
  System.out.println("==========");
  IFace2 ref2 = new UseIFace();
  ref2.f2();
  System.out.println("==========");
  CIFace ref3 = new UseIFace();
  ref3.f1();
  ref3.f2();
  ref3.f3();
  System.out.println("==========");
  UseIFace ref4 = new UseIFace();
  ref4.f1();
  ref4.f2();
  ref4.f3();
  ref4.f4();


 }
}