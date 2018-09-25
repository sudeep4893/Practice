package p2;

import p1.Base;
public class NonDerived2
{
 Base ref;

 public NonDerived2()
 {
  System.out.println("p2 NonDerived2 NonDerived2()");
  ref = new Base();
  //attempt to write : by choice
 }

 public void display()
 {
  System.out.println("p2 NonDerived2 display()");
  System.out.println("ref.i : not accessible");
  System.out.println("ref.j : not accessible");
  System.out.println("ref.k : not accessible");
  System.out.println("ref.l : " + ref.l);//fetch == read == use
  System.out.println("----------------------");
  ref.display();
 }//display

}//NonDerived2