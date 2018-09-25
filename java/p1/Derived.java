package p1;

public class Derived extends Base
{
 public Derived()
 {
  System.out.println("p1 Derived Derived()");
  //attempt to write : by choice
 }

 public void display()//override
 {
  System.out.println("p1 Derived display()");
  System.out.println("i : not accessible ");
  System.out.println("j : " + j );//fetch == read == use
  System.out.println("k : " + k );//fetch == read == use
  System.out.println("l : " + l );//fetch == read == use
  System.out.println("-----------------------");
  super.display();
 }//display
}//Derived