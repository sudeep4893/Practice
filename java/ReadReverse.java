import java.io.*;

class ReadReverse
{
 public static void main(String args[])
 {
  try
  {
    String fname = args[0];
    String mode = "r"; //read mode, file must exist

    //open the file
    RandomAccessFile raf = new RandomAccessFile(fname, mode);

    long len = raf.length(); //returns file size in bytes
    long i;
    int data;

    for(i = len -1; i>=0 ; i--)
    {
      raf.seek(i);//seek pos i wrt BOF
      data = raf.read();    
      System.out.write(data);
    }//for
    System.out.flush();

    //close the file
    raf.close(); 
  }
  catch(IOException ex)
  {
   System.out.println("Err : "+ ex);
  }
  catch(ArrayIndexOutOfBoundsException ex)
  {
   System.out.println("Usage : java ReadReverse <filename>");
  }
 }//main
}//RAF

