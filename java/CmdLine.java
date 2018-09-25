/*
Command Line Arguments
-----------------------
Command Line Arguments are parameters
that are passed from DOS/LINUX shell
to the Java Application.

System gathers the command line arguments
and forms a String array of the same.

On startup, the address of the String array 
is assigned to the formal parameter (String args[])
of main method.

The code of the application may utilize the
String array that contains the command line arguments.

*/
class CmdLine
{
 public static void main(String args[])
 {
  System.out.println("Number of command line arguments : " + args.length);
  int i;
  
  for(i =0; i< args.length; i++)
  {
   System.out.println("args[" + i + "] : " + args[i] );
  }

 }//main
}//CmdLine

