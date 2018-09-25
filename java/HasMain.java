/*
Inheritance of static methods

static methods of super class, if not
private then are all directly accessible 
to the sub class.

It is important to know that
* static methods cannot be overridden
* static methods cannot be run time bound

If the sub class redefines an inherited
static method then the super class gets
hidden (and not overridden).

In such a case from the child class
the child class method is directly 
accessible and the super class method 
is accessible by explicit use of 
className along with method name.
(see the example).


*/

class HasMain
{
 static void f1()
 {
  System.out.println("static f1 of HasMain");
 }

 public static void main(String args[])
 {
  System.out.println("in main of HasMain");
  f1();//binds with f1() of current class
 }
}//HasMain

class GetsMain extends HasMain
{

 public static void main(String args[])//hides main of super class
 {
  System.out.println("in main of GetsMain");
  f1();//binds with f1() of super class as there is no hiding
  HasMain.main(args); //binds with main of HasMain
 }
}