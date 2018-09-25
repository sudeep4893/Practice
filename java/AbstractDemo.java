/*
Certain applications are developed using
a family (hierarchy) of classes.

Examples
=========
* Vehicle
   -- Car
   -- Truck
   -- Train

*Animal
  -- Dog
  -- Snake
  -- Fish

* Shape
  -- Rectangle
  -- Circle 
  -- Triangle

In such cases the general role of the 
super class is
1) To host some common code and data.
2) To be a generic reference for the sub-classes.
3) To enforce definitions of some methods, on sub-classes.

There may be a case where the super-class
predicts the need of an operation (method)
but is not able to define it.

Examples
=========
start(), stop(), generatePower(), ... for a class Vehicle.
move(), eat(), ... for class Animal.
area(), volume(), ... for class Shape.

Hence the super-class only declares
the operation (method) and skips the
definition.
Further seeking it to be defined by
the sub-classes.

Java allows implemenation of such 
cases through abstract classes and
methods.

abstract method
---------------
An abstract method is a method with
declaration only (signature only) and
no definition (no body).
It is a method that makes the class abstract.
It is a method that is compulsorily to be
overridden by the sub-classes.


abstract class
-------------
An abstract class is a class that contains
zero to many abstract methods.
It is a class that cannot be instantiated.
i.e. its objects cannot be created.

Known that a class is used by creating
its objects.
And an abstract class cannot be instantaited,
so by default it cannot be used.

It is meant to be inherited and used.

About inheritance of abstract class
-------------------------------
Known that inheritance allows a sub-class
to get code and data from the super-class.

When a class inherits an abstract class
then along with code and data, the sub
class also gets the abstract methods from 
the super class.

Now the sub-class has some abstract
methods due to inheritance.
Hence the sub-class also becomes an
abstract class.

If the sub-class "overrides" the inherited
abstract methods then it can become
a normal class again.
*/

abstract class A
{
 void f1()
 {
  System.out.println("I am the common code for the sub-classes");
 }

 abstract void f2();
}

class B extends A
{
 void f2()//override
 {
   System.out.println("This is how B performs operation f2()");
 }
}


class C extends A
{
 void f2()//override
 {
   System.out.println("This is how C performs operation f2()");
 }
}

class AbstractDemo
{
 public static void main(String args[])
 {
  //A objA = new A();
  A refA1, refA2;
  refA1 = new B();//type compatibility
  refA2 = new C();//type compatibility
  
  refA1.f1();
  refA1.f2();

  refA2.f1();
  refA2.f2();

 }//main
}//AbstractDemo

/*
Q) Can abstract class have member variables,
constructions, normal member functions?
A) Yes. All the members of the abstract
class are to be used by the sub-classes.

Q) Can a sub-class override limited abstract methods
of the super-class?
A) Yes. But in such a case it will become an abstract
class.
*/