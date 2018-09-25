/*
Copy A File 

Steps
-----
* open a file for reading and another for writing.
* fetch data from source file until EOF
  - write the fetched data into target file
*close both the files

*/

import java.io.*;

class FCopy1
{
 public static void main(String args[])
 {
  try
  {
   String sfname = args[0];
   String tfname = args[1];

   //open the files
   FileInputStream fin = new FileInputStream(sfname);//file must exist   
   FileOutputStream fout = new FileOutputStream(tfname);//file will be created/overwritten

   //read file data   
   byte data[] = new byte[512];
   int n;
   int cnt = 0;
  
   while( (n = fin.read(data)) != -1)//-1 means EOF
   {
     fout.write(data, 0,n);
     cnt++;
   } 
   fout.flush();//ensure buffered data is transmitted to fout

   //close the files
   fin.close();
   fout.close();

   System.out.println("\n File Copied in "+ cnt + " cycles ");
  }
  catch(ArrayIndexOutOfBoundsException ex)
  {
   System.out.println("Usage : java FRead <srcFileName> <trgtFileName>");
  }
  catch(IOException ex)
  {
   System.out.println(ex);
  }

 }//main
}//FRead