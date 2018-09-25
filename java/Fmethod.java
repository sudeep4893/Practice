class A
{
 final void f()
 {
  System.out.println("A final method cannot be overridden");
 }
}//A

class B extends A
{
/*
 void f()//override not allowed
 {
  System.out.println("A new defn from the sub class");
 }
*/
}//B

class Fmethod
{
 public static void main(String args[])
 {
  B ref = new B();
  ref.f();
 }
}