/*
Inheritance is the mechanism that 
allows a sub-class to get code and data 
(member methods and member variables) 
from an existing super-class.

--------------------------------------
Inheritance of non static member variables
--------------------------------------
System applies inheritance of data as
object of the sub-class is created.

Evey object of the sub-class has a 
nested object of the super-class.

Known that objects contain non-static
member variables only.

(see the daigram)

------------------------------------ 
Inheritance of static member variables
------------------------------------ 
A static member variable is declared
only once for a class and for its sub-classes.

If the variable is not private then the 
entire hierarchy of classes will directly 
access the same variable.

----------------------------
Loading of hierarchy of classes
----------------------------
A class gets loaded into memory on
its first use.

But if the first use of super-class is 
due to the first use of sub-class then 
system loads the classes in order 
super-class first and sub-class next.

-------------------------------
Execution of static initializer blocks
-------------------------------
Known that static initializer blocks get
executed the moment class gets loaded
in memory.
The same behaviour continues for inheritance.

----------------------------------
Execution of non static initializer blocks
----------------------------------
Known that
1) Non-static initializer blocks get executed
for every new object of the class.
2) Every object of the sub-class has a 
nested object of the super-class.

So on creation of object of super class
the non static initializer of super class 
executes.

And on creation of object of sub class
the non static initializers of super-class
and sub-class, both get executed.
Sequence of execution is super-class
non-static initializer first and the sub-
class non-static initializer next.

------------------------
Execution of constructors
------------------------
Known that
1) Constructor gets executed for every 
new object of the class.
2) Every object of the sub-class has a 
nested object of the super-class.

So on creation of object of super-class
the constructor of super-class executes.

And on creation of object of sub-class
the constructors of super-class and sub-class, 
both get executed.

Sequence of execution is super-class
constructor first and the sub-class 
constructor next.


On creation of object of sub-class by
default system executes the parameter 
matching constructor of the sub-class 
and the default constructor of the 
super-class.
Inorder to execute the parameter matching
constructor of super-class, the sub-class
constructor must pass parameters to the
super-class constructor.
This is done using "super(params)" as
the first statement of the sub-class
constructor.
*/

class A //super class
{
 int x; // a non static member variable
 static int y; // a static member variable 

 static
 {
  System.out.println("A : static initializer block");
  A.y = 1; //or y = 1;
 }

 {
  System.out.println("A : non-static initializer block");
  x= 0;
 }

 A()
 {
  System.out.println("A()");
  x = 10;
 }

 A(int i)
 {
  System.out.println("A(int)");
  x = i;
 }

}//A

class B extends A // sub class
{
 //int x;
 int p; // a non static member variable
 static int q; // a static member variable 

 static
 {
  System.out.println("B : static initializer block");
  A.y++; //or y++;
  B.q = 100;//or q = 100;
 }

 {
  System.out.println("B : non-static initializer block");
  p= 0;
 }

 B()
 {
  System.out.println("B()");
  p = 20;
 }

 B(int i,int j)
 {
  super(i);//passing i as parameter to A(int)
  System.out.println("B(int,int)");
  p = j;
 }

 void display()
 {
  System.out.println("x :  " + x);
  System.out.println("y :  " + y);
  System.out.println("p :  " + p);
  System.out.println("q :  " + q);
 }
}//B

class InheritData
{
 public static void main(String args[])
 {
/*
  System.out.println("==========");
  A obj = new A();
*/
  System.out.println("==========");
  B objB1 = new B();
  objB1.display();
  System.out.println("==========");
  B objB2 = new B(50,60);
  objB2.display();
  System.out.println("==========");


 }//main
}//InheritData