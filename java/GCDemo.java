/*
Java allows creation of objects/arrays 
using the operator "new" and ignore their 
destruction.

An object/array is accessed through 
reference(s). If for an object/array
all the references get dropped then
the object/array becomes "unreferenced".

Generally reference to an object/array
gets dropped 
1) due to completion of the method in
which the local reference was declared.
2) due to explicit assignment of "null".

JVM uses a high priority background
thread called as "finalizer", to scan
the heap segment and clear (destroy)
the unreferenced objects/arrays.

This process is performed periodically
or on demand.

This process is known as "garbage collection".

JVM makes the "finalizer" thread
execute a "finalize()" method of the
class before the object of the class
is destroyed.
It can contain code to "clear" the 
resources used by the object.

In Java, the default super class for 
every class is the "Object" class.
The "Object" class defines the "finalize()"
method.
So it is by inheritance available in all
classes.
A class can "override" the "finalize()"
method to have specific object destruction
logic.

See the example.

*/

class GoodClass //extends Object
{
 protected void finalize() //override the Object finalize method
 {
  System.out.println("finalize called for GoodClass");
 } 
}

class SomeClass extends GoodClass
{
 int arr[];
 String name;

 SomeClass(String n, int s)
 {
   name = n;
   arr = new int[s];
 }

 protected void finalize() //override the Object finalize method
 {
  super.finalize();
  System.out.println("finalize called by "+ Thread.currentThread());
  System.out.println("finalize called for "+ name);
  System.out.println("please destroy my array of length : " + arr.length);
 } 

}//SomeClass

class GCDemo
{
 public static void main(String args[])
 {
  SomeClass o1 = new SomeClass("A", 1000);
  SomeClass o2 = new SomeClass("B", 10000);
  SomeClass o3 = new SomeClass("C", 100000);
  SomeClass r2 = o1;
  //...
  //drop the references to objects
  o1 = null; 
  o2 = null;
  o3 = null;
  //...

  //request system to invoke the garbage collector
  System.gc();

  try
  {
   Thread.sleep(5000);//sleep for 5 seconds, to avoid prg getting over
  }
  catch(InterruptedException ex)
  {}
  System.out.println("main complete");
 }//main
}