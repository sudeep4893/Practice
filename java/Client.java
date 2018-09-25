import java.net.*;
import java.io.*;

class Client
{
 Socket s;
 Client(String ip, int port) throws IOException
 {
  //sends a connection request to the server
  s = new Socket(ip, port);
 }

 static String getString() throws IOException
 {
   System.in.skip(System.in.available());

   byte arr[] = new byte[512];
   int x;
   x= System.in.read(arr);
   String temp = new String(arr, 0,x-2);
   return temp;
 }

 void transactAndClose() throws Exception
 {
   InputStream in = s.getInputStream();
   OutputStream out = s.getOutputStream();

   DataInputStream din = new DataInputStream(in);
   DataOutputStream dout = new DataOutputStream(out);

   String str, ch;
   do
   {
    System.out.println("Enter a String ");
    str = getString();
    //send str to server
    dout.writeUTF(str);
    //fetch result
    str = din.readUTF();
    //utilize
    System.out.println("Server Response : " + str);

    System.out.println("Continue (yes/no) ");
    ch = getString();
    //send the choice to server
    dout.writeUTF(ch);
   }while(ch.equalsIgnoreCase("yes"));

   s.close();
 }
 public static void main(String args[])
 {
  try
  {
   String ip = "127.0.0.1";
   int port = 8900;

   Client c = new Client(ip, port);
   c.transactAndClose();
  }
  catch(Exception ex)
  {}
 }
}