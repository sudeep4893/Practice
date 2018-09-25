/*
java.io.File
-----------
The File class supports operations on  
properties / metadata of files and directories.

LEARN through example.
*/

import java.io.File;
import java.io.IOException;
import java.util.Date;

class AboutFile
{
 static char getChar() throws IOException
 {
  System.in.skip(System.in.available());
  return (char) System.in.read();
 }

 static void showContents(File f)
 {
  String contents[] = f.list(); //returns a String[] that contains names of all contents of this directory
  int i;
  for(i =0 ; i< contents.length; i++)
   System.out.println(contents[i]);

  System.out.println("\n Total content count : " + contents.length);
 }

 static void showProperties(File f)
 {
   System.out.println("Location : "+ f.getAbsolutePath());
   System.out.println("File Length : " + f.length());
   System.out.println("Is Readable : " + f.canRead());
   System.out.println("Is Writable : " + f.canWrite());
   System.out.println("Is Executable : " + f.canExecute());
   System.out.println("Is Hidden : " + f.isHidden());
 
   Date d = new Date(f.lastModified());
   System.out.println("Last Modified : " + d); 
 }

 public static void main(String args[])
 {
  try
  {
   String x = args[0];
   File f = new File(x);//File object that represents x  
   
   if(f.exists()) //to detect whether a file/dir exists or not
   {
     if(f.isDirectory())     
     {
      System.out.println(x + " is a directory");
      showContents(f);
     }
     else if(f.isFile())
     {
      System.out.println(x + " is a file");
      showProperties(f);
     } 
     else
     {
      System.out.println(x + " is neither a file nor a directory");
     }
     //f.delete(); //permanently deletes a file or an empty directory
   }
   else
   {
     System.out.println(x + " does not exist");
     System.out.println("Do you want to create it (y/n) ? ");
     char ch;
     ch = getChar();
     if(ch == 'y' || ch == 'Y')
     {
       System.out.println("F : create as a file ");
       System.out.println("D : create as a directory ");
       System.out.println("enter choice ");
       ch = getChar();

       switch(ch)
       {
         case 'f':
         case 'F':
           f.createNewFile(); //creates a new empty file
           break;
         case 'd':
         case 'D':
           f.mkdirs();//creates a hierarchy of directories
           break;
         default:
           System.out.println("Illegal Choice ");
           break;
       }//switch
     }
   }
  }
  catch(ArrayIndexOutOfBoundsException ex)
  {
   System.out.println("Usage : java AboutFile <file/dir name>");
  }
  catch(IOException ex)
  {
   System.out.println("Err : " + ex);
  }

 }//main
}