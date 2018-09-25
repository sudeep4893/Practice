import outer.*; //get access of all public classes and interfaces of package outer
import outer.inner.*;//get access of all public classes and interfaces of package outer.inner

class ABC
{
 public static void main(String args[]) 
 {
  A objA = new A();
  outer.B objB1 = new outer.B();
  outer.inner.B objB2 = new outer.inner.B();
  C objC = new C();

  objA.f1();
  objB1.f2();
  objB2.f3();
  objC.f4();

 }//main
}//ABC