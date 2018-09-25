/*
RandomAccessFile
----------------
RandomAccessFile allows 
* read/write operations on a file
* seek
* reading and writing java datatypes


*/

import java.io.*;

class RAF
{
 public static void main(String args[])
 {
  try
  {
    String fname = "d:\\q.txt";
    String mode;
    //mode = "r"; //file must exist
    mode = "rw"; //file will be created/opened wont be overwritten   

    //open the file
    RandomAccessFile raf = new RandomAccessFile(fname, mode);

    //seek and write demo
    //raf.seek(10);//position the internal file pointer at offset 10 from BOF, if offset > file size then file size grows to reach the offset
    //raf.write('Q'); //write(int)   

    //read and write java datatypes
    int i1, i2;
    boolean b1,b2;
    double d1,d2;
    char c1,c2;
    String s1, s2;

    i1 = -16;
    b1 = true;
    d1 = 4.5678;
    c1 = 'q';
    s1 = "my computer";

    //write 
    raf.seek(0);//position file pointer at BOF    
    raf.writeInt(i1);
    raf.writeBoolean(b1);
    raf.writeDouble(d1);
    raf.writeChar(c1);
    raf.writeUTF(s1);

    //read back
    raf.seek(0);//position file pointer at BOF
    i2 = raf.readInt();
    b2 = raf.readBoolean();
    d2 = raf.readDouble();
    c2 = raf.readChar();
    s2 = raf.readUTF();

    System.out.println(i2);
    System.out.println(b2);
    System.out.println(d2);
    System.out.println(c2);
    System.out.println(s2);

  
    //close the file
    raf.close(); 
  }
  catch(IOException ex)
  {
   System.out.println("Err : "+ ex);
  }
 }//main
}//RAF

