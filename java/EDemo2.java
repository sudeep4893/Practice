/*
throws
-------
throws statement is used by method
to transfer a local exception on the
caller of the method.

By declaring an exception to be thrown
the method becomes free from handling 
of the exception and the responsibility to 
handle it is delegated on the caller of 
the function.

----------------------------------
Observe the use of nested try blocks
----------------------------------
*/

class EDemo2
{
 int a, b, c;

 void set(String arr[]) throws NumberFormatException, ArrayIndexOutOfBoundsException
 {
   a = Integer.parseInt(arr[0]);
   b = Integer.parseInt(arr[1]);
 }//set

 void divide() throws ArithmeticException
 {
  c = a/b; //process
 }

 void display()
 {
  System.out.println("a :  " +a);
  System.out.println("b :  " +b);
  System.out.println("c :  " +c);
 }

 public static void main(String args[]) 
 {
  System.out.println("--------------");
  try
  {
   EDemo2 ed2 = new EDemo2();  
   //int x = 10/0;
   try
   {
    ed2.set(args);
   }
   catch(ArrayIndexOutOfBoundsException ex)
   {
    System.out.println("Insufficient Data");
    System.out.println("Applying Default Values : 10, 2");
    ed2.a = 10;
    ed2.b = 2;
   }
   /*finally
   {
     System.out.println("finally of inner try");
   }*/
   ed2.divide();//dependent fn
   ed2.display();//dependent fn
  }//try
  catch(NumberFormatException ex)
  {
   System.out.println("Invalid Data");
  }
  catch(ArithmeticException ex)
  {
   System.out.println("Infinity");
  }
  finally
  {
   System.out.println("FINALLY");
  }
 
  System.out.println("--------------");
 }//main
}//EDemo1
