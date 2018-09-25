class A
{
 static int x;
 static
 { 
  x = 10;
  System.out.println("static block of A");
  System.out.println("x : " + x);
 }
}//A


class Loader
{
 public static void main(String args[])
 {
  System.out.println("main starts");
 
  try
  {
   //load class A in memory
   Class.forName("A");
  }
  catch(ClassNotFoundException ex)
  {}

  System.out.println("main ends");

 }//main
}//Loader
