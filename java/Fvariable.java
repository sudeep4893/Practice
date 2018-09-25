class Fvariable
{
 final int z;//= 99; // a final member variable

 //a non static initializer block 
 {
  //z = 0;
 }

 Fvariable()
 {
  System.out.println("Fvariable()");
  z = 1;
 }

 Fvariable(int i)
 {
  System.out.println("Fvariable(int)");
  z = i;
 }

 void display()
 {
  //z = 5; cann assign a value to a final variable in any method
  System.out.println("for the object z : " + z);
 }

 static void fn(final int y)//final formal parameter
 {
  //y is initialized by the actual parameter
  //y is a copy of actual parameter
  //y is read only
  System.out.println("in fn(), y :  "+ y);
  //y++; illegal to reassign
 }
 
 public static void main(String args[])
 {
  System.out.println("---final local variable ---");
  final int x; //a final local variable
  //....
  x = 10; //must be initialized once before use
  System.out.println("x :  "  + x); //read only use
  //x++; illegal to reassign 

  System.out.println("---final formal parameter ---");

  int q = 50; // a non final local variable
  int w = 60; // a non final local variable
  fn(q);
  fn(w);

  System.out.println("---final member variable ---");
  Fvariable o1 = new Fvariable();
  Fvariable o2 = new Fvariable(100);
  o1.display();
  o2.display();
 }
}
