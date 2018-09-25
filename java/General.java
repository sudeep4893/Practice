/*
General Java Program
*/

public class General
{
 public static void main(String args[])
 {
  int i; //local variable
  i = 1;
  while(i < 11)
  {
   if(i % 2 == 0)
   {
    //printf("Hello Java\n");
    System.out.println("Hello Java");//System.out represents std output stream (a connection between CPU and Monitor).
   }
   else
   {
    System.err.println("Hello Student");
   }
   i++;
  }//while

 }//main
}//General


/*
In Java, Do the variables contain garbage data?
In Java, the variables may be
1) Member variables (declared in the class)
2) Local variables(declared in a method) 

The Member variables are auto initalized by the System
So they dont have garbage data.
It is a rule to initialize the local variable before use.
So they dont have garbage data.

If a local variable is not initialized
before use then it is a compile error.
-----------------------------------------------------
In Java, Is is necessary to have the same name for source file and the class?
Ans> Yes if the class is public, otherwise no.
Compilation uses source file name.
Compilation generates bytecode with class name.
Execution uses bytecode name.
Hence recommended that source file and class name must match.

*/