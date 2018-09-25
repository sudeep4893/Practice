final class A
{
 void f()
 {
  System.out.println("A final class cannot be inherited");
 }
}//A

/*
class B extends A
{}
*/

class Fclass
{
 public static void main(String args[])
 {
  A ref = new A();
  ref.f();
 }
}