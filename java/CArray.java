/*
 Arrays of class type

As we define arrays of primary datatypes
similarly arrays of class type can also be
defined.

Syntax 
--------
 datatype  ref[] = new datatype[size];

Example
--------
 int arr1[] = new int[3];
 Student arr2[] = new Student[3];

For arrays of primary datatypes the
elements are "variables" of respective
types.
For arrays of class type the elements
are "references" of the class type and
are "null" by default.

Objects of the class type must be explicitly
defined and connected with the reference
array, before usage. 

*/

class CArray
{
 int x, y;
 
 CArray()
 {
  System.out.println("CArray()");
  x = 10;
  y = 20;
 }

 CArray(int q , int w)
 {
  System.out.println("CArray(int,int)");
  x = q;
  y = w;
 }

 void display()
 {
  System.out.println(x + "  " + y);
 }
 
 public static void main(String args[])
 {
  System.out.println("=============");
  CArray arr[] = new CArray[3];
  System.out.println("=============");
  arr[1] = new CArray(1,2);
  arr[2] = new CArray();
  arr[3] = new CArray(100,200);
  System.out.println("=============");

  int i;
  for(i =0 ; i< arr.length; i++)
    arr[i].display();

 }//main
}//CArray
