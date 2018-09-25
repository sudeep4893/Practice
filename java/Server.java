import java.net.*;
import java.io.*;

class Server implements Runnable
{
 ServerSocket svrSkt;

 Thread connThread;
 boolean connFlag;

 Server(int portNo) throws IOException
 {
  //open a port or raise IOException (Socket Bind Failure)
  svrSkt = new ServerSocket(portNo);

  //create a new thread to accept connections
  connFlag = true; 
  connThread = new Thread(this);
  connThread.start();

 }//Server

 public void run()
 {
  while(connFlag)
  {
   acceptConnection();
  }
  //close the  port
  try
  {
   svrSkt.close();
  }
  catch(IOException ex)
  {}
 }
 
 void acceptConnection()
 {
  try
  {
   System.out.println("Waiting For A Connection");

   //wait, listen and accept client connections
   Socket s = svrSkt.accept(); 

   System.out.println("Got A Connection");
   new Processor(s);
  }
  catch(Exception ex)
  {}
 }//acceptConnection


 public static void main(String args[]) 
 {
  try
  {
   Server svr = new Server(8900);
   //...
  }
  catch(IOException ex)
  {}
 }
}

class Processor extends Thread
{
 Socket clnt;

 Processor(Socket s)
 {
   clnt = s;
   start();
 }

 public void run()
 {
  try
  {
   InputStream in = clnt.getInputStream();
   OutputStream out = clnt.getOutputStream();

   DataInputStream din = new DataInputStream(in);
   DataOutputStream dout = new DataOutputStream(out);

   String s, ch;
  
   do
   {
     //get data from client
     s = din.readUTF();
     //process
     s = echo(s);
     //write results to client
     dout.writeUTF(s);

     //cycle
     ch = din.readUTF();
  
   }while(ch.equalsIgnoreCase("yes"));
  
   clnt.close();

  }
  catch(Exception ex)
  {}
 }//run 

 String echo(String s)
 {
  String reply;
  reply = "{ " + s.toUpperCase() + " }";
  return reply;
 }
}