package p2;

import p1.Base;
public class Derived2 extends Base
{
 public Derived2()
 {
  System.out.println("p2 Derived2 Derived2()");
  //attempt to write : by choice
 }

 public void display()//override
 {
  System.out.println("p2 Derived2 display()");
  System.out.println("i : not accessible " );
  System.out.println("j : not accessible ");
  System.out.println("k : " + k );//fetch == read == use
  System.out.println("l : " + l );//fetch == read == use
  System.out.println("-----------------------");
  super.display();
 }//display
}//Derived2