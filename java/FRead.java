/*
Read A File 

Steps
-----
* open the file
* fetch data until EOF
  - print the fetched data
*close the file

*/

import java.io.*;

class FRead
{
 public static void main(String args[])
 {
  try
  {
   String fname = args[0];

   //open the file
   FileInputStream fin = new FileInputStream(fname);//file must exist   

   //read file data   
   int data;
   int cnt = 0;
  
   while( (data = fin.read()) != -1)//-1 means EOF
   {
     System.out.write(data);
     cnt++;
   } 
   System.out.flush();//ensure buffered data is transmitted to System.out

   //close the file
   fin.close();

   System.out.println("\n File Read in "+ cnt + " cycles ");
  }
  catch(ArrayIndexOutOfBoundsException ex)
  {
   System.out.println("Usage : java FRead <fileName>");
  }
  catch(IOException ex)
  {
   System.out.println(ex);
  }

 }//main
}//FRead