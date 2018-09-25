/*
Nested Class 
------------
A nested class is a class inside a class.
It acts as a member of the enclosing class.
Being a member of a class, a nested class
can be static/non-static.

All access rules same as rules of members.

* A non static member of the class can
access all the non-static and static members
of the class.

* A static member of the class can access 
only the static members of the class.

IMPORTANT
A non static nested class can have
non static members only.

A static nested class can have
non static and static members.


*/
class Outer
{
 int x, y; //non static member variables
 static int z= 10;//static member variable

 Outer()
 {
    x = 1;
    y = 2;

 } 

 void displayAll() //non static member function
 {
   System.out.println(x + "  " + y + "  " +z);
   Nested1 n1 =new Nested1();
   n1.display();
   Nested2 n2 =new Nested2();
   n2.display();
 }

 static void displayStatic() //static member function
 {//can access static members of the class
   System.out.println(" z : " +z );
   Nested2 n2 =new Nested2();
   n2.display();
 }

 class Nested1 //non static nested class (inner class)
 {
   int ans;
   Nested1()
   {
     ans = x+y+z; 
   }

   void display()
   {
    System.out.println("ans : " + ans);
   }
 }

 static class Nested2//static nested class
 {
   int ans;
   Nested2()
   {
     ans = z * z; 
   }

   void display()
   {
    System.out.println("ans : " + ans);
   }

  }//Nested2

  public static void main(String args[])
  {
   Outer o = new Outer();
   o.displayAll();
   o.displayStatic();
  }//main
}//Outer