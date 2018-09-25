package p1;

public class NonDerived
{
 Base ref;

 public NonDerived()
 {
  System.out.println("p1 NonDerived NonDerived()");
  ref = new Base();
  //attempt to write : by choice
 }

 public void display()
 {
  System.out.println("p1 NonDerived display()");
  System.out.println("ref.i : not accessible ");
  ref.j++;//increment
  System.out.println("ref.j : " + ref.j);//fetch == read == use
  System.out.println("ref.k : " + ref.k);//fetch == read == use
  System.out.println("ref.l : " + ref.l);//fetch == read == use
  System.out.println("----------------------");
  ref.display();
 }//display

}//NonDerived