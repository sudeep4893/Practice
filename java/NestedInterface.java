/*
Nested Interface

Definition
------------
It is possible to define interfaces inside 
an interface.
Doing so is nesting of interfaces.


Implementing Top Level Interface
-------------------------------

If a class implements a "top level interface"
then 
1) It must override the abstract methods 
of top level interface only and must not 
override any abstract methods of the 
nested interfaces.

2) It becomes type compatible with 
top level interface only and not with 
any of the nested interfaces.


Implementing Nested Interface
-----------------------------
If a class implements a "nested interface"
then 
1) It must override the abstract methods 
of same nested interface only and must 
not override any abstract methods of the 
top level/other nested interfaces.

2) It becomes type compatible with same 
nested interface only and not with the 
top level/other nested interfaces.


Why nested interfaces
-----------------------
Interfaces are nested to form a logical 
grouping of related interfaces.

Example

interface DataStructures
{
  interface Stack{...}
  interface Queue{...}
  ...
}

ByteCode
----------
ByteCode files will be created for all 
the interfaces and for nested interfaces.

Their names will be :
 TopLevelInterface.class
 TopLevelInterface$NestedInterface.class
*/

interface I
{
  void f(); //a member of interface I

  interface I1 //a nested interface
  {
    void f1(); //a member of nested interface I1
  }//I1

  interface I2 //a nested interface
  {
    void f2(); //a member of nested interface I2
  }//I2

}//I


//implementing top level interface
class C implements I
{
  public void f()
  {
    System.out.println("C overrides f() of I");
  }
}//C


//implementing nested interface
class C1 implements I.I1
{
  public void f1()
  {
    System.out.println("C1 overrides f1() of I.I1");
  }
}//C1

class NestedInterface
{
 public static void main(String args[])
 {
   //typecompatiblity of C with I
   I ref = new C();
   ref.f(); 

   //typecompatiblity of C1 with I.I1
   I.I1 ref1 = new C1();
   ref1.f1();
   	
 }//main
}//NestedInterface