/*
Method Overloading
------------------
Method overloading is defining multiple
methods for a class with the same name 
and different set of parameters.

Conceptually method overloading is implementation
of OOP concept polymorphism that specifies
"Define multiple ways to perform a task".


Method / Constructor Delegation  
--------------------------------
Certain times methods / constructors
are overloaded to support different number 
of arguments and the logic of the methods 
/ constructors is almost the same.

In such cases method /constructor calls 
can be delegated.
(see the code)


*/

class Delegation
{
 int x, y;
 Delegation()//default constructor
 {
   this(100,200); //delegation of constructor call 
   //when "this" is used for delegation of 
   //constructor calls then its usage must 
   //be the first statement in the constructor.
  
   System.out.println("Delegation()");
 
 }

 Delegation(int q, int w)//parameterized constructor
 {
  System.out.println("Delegation(int,int)");
  x = q;
  y = w;
 }
 
 void display()
 {
   System.out.println(x + "  "  +y);
 }

 void add(int a, int b, int c)
 {
  int ans;
  ans = a+ b+c;
  System.out.println("addition : " + ans);
 }

 void add(int a, int b)
 {
   add(a,b,0);//delegation of method call
 }

 public static void main(String args[])
 {
  System.out.println("-----Constructor Delegation-----");
  Delegation d1 = new Delegation();
  Delegation d2 = new Delegation(4, 5);
  d1.display();
  d2.display();

  System.out.println("-----Method Delegation-----");
  d1.add(10,20);
  d1.add(1,2,3);
 }//main

}//Delegation