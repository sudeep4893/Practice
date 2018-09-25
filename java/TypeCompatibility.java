/*
Type Compatibility

Inheritace creates type compatibility
between the super and the sub class.

Type compatibility allows a super class
reference to refer to object of sub class.
Reverse is not true.

*/

class A
{
 void f1()
 {
  System.out.println("A f1()");
 }
 void f2()
 {
  System.out.println("A f2()");
 }
}//A

class B extends A
{
 void f2() //overrides f2() of A
 {
   //this reference of B refers to object of B (downcast)
  System.out.println("B f2() starts ");
  f3();//this.f3();
  System.out.println("B f2() ends ");
 }
 void f3()
 {
  System.out.println("B f3() starts");
  super.f2(); //f2() of super class
  System.out.println("B f3() ends");
 }
}//B

class TypeCompatibility
{
 public static void main(String args[])
 {
  if(args.length == 0)
  {
   System.out.println("Usage : java TypeCompatibility A");
   System.out.println("Usage : java TypeCompatibility B");
   return ;//terminate main
  }

  A refA = null;// super class reference

  if(args[0].equals("A") )
    refA = new A();
  else if(args[0].equals("B") )
    refA = new B();//upcasting valid due to type compatibility
  else
  {
   System.out.println("Usage : java TypeCompatibility A");
   System.out.println("Usage : java TypeCompatibility B");
   return ;//terminate main
  }

  refA.f1();//compile time bound
  refA.f2();//run time bound
  //refA.f3();//new member of sub class not accessible through reference of super class

 }//main
}//TypeCompatibility

/*
It is the role of the compiler to bind
a method call with the methods definition.

For this compiler matches the signatures
of the method call and the methods definition.

This approach to bind a method call with
a method definition is called as "compile 
time binding" or "early binding".

-----------------------------------

Consider a case
* Code has classes that use inheritance.
* Sub class overrides some super class method(s).
* A super class reference is declared.
* It may refer to object of super class or of sub class.
* It is used to access an overridden method.

For a case as considered above, the
compiler doesnt bind the method call
with any definition, because

1) The reference may refer to object 
of any of the super or sub class.
2) Overridden method has multiple
definitions and same signature across
super and sub class.

On execution,
Java's Runtime Environment will
1) Detect the type of object being
referred by the super class reference.
2) Bind the call to overridden method
with defintion provided by the class 
of the object.

This approach to bind a method call with
a method definition is called as "run  
time binding" or "late binding" or
"dynamic method dispatch".
---------------------------------
super
------
"super" can be used in non static methods
of a sub class to refer to the super class.

It is used :
* to access overridden methods of super class
* to access hidden member variables of super class 
* to invoke the desired constructor of super class


*/