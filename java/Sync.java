/*
Shared Resource
----------------
A shared resource may be an object/connection/device/...
that is used by multiple processes/threads.

A shared resource may or may not support concurrency.

If a shared resource doesnt support concurrency
then all code that use the shared resource must
be declared as a "critical section".

Critical Section
---------------
A critical section is a module or a set of modules
that blocks concurrency.

If multiple processes/threads concurrently attempt 
to use a shared resource through a critical section 
then only one of them gets access to the shared resource.
Rest get suspended, but will be resumed sequentially, 
proiritywise.

synchronized
-------------
To define a critical section declare the code 
(method/block) that uses the shared resource 
as "synchronized".  

How it works?
-------------
Object class is the super class for all classes 
in Java.
The Object class defines a "monitor"
(binary semaphore) that blocks concurrency.

Due to inheritance the same "monitor"
is available in every object of every sub-class.

The "monitor" is inactive by default,
hence doesnt block concurrency.
It gets auto activated for synchronized
blocks/methods.

Once object "monitor" is active then it
will allow only one thread to enter and
execute the synchronized method/block.

Other threads that attempt access of
any of the synchronized methods/blocks
will be suspended until the first thread
(owner) completes execution of synchronized
method/block.

*/


class PrintServer //extends Object
{
 String dataToPrint;
 int times;

 synchronized void print(String s, int n)
 {
  dataToPrint = s.toUpperCase();
  times = n;

  int i;
  Thread t = Thread.currentThread(); //get a handle to the current thread
  for(i =1; i<= times; i++)
  {
   System.out.println(); //skip a line
   System.out.print(t.getName());
   System.out.print(" ");
   System.out.print(i);
   System.out.print(" : ");
   System.out.print(" [ ");
   System.out.print( dataToPrint);
   System.out.print(" ] ");
  }//for
 }//print

 //the method is made a critical section
 //at the place of invokation by use of 
 //synchronized block.

 /*synchronized*/ void print1(String s, int n)
 {
  dataToPrint = s.toLowerCase();
  times = n;

  int i;
  Thread t = Thread.currentThread(); //get a handle to the current thread
  for(i =1; i<= times; i++)
  {
   System.out.println(); //skip a line
   System.out.print(t.getName());
   System.out.print(" ");
   System.out.print(i);
   System.out.print(" : ");
   System.out.print(" { ");
   System.out.print( dataToPrint);
   System.out.print(" } ");
  }//for
 }//print


}//PrintServer

class Client extends Thread
{
 PrintServer svr;
 String msg;
 int count;

 Client(PrintServer ps, String nm, String data, int n)
 {
  svr = ps;
  setName(nm);//set the Thread name
  msg = data;
  count = n;

  start();
 }

 public void run()
 {
   if(getName().equals("C"))
   {
     synchronized(svr)
     {
      svr.print1(msg, count);
     }
   }
   else
     svr.print(msg, count);

 }
}

class Sync
{
 public static void main(String args[])
 {
  PrintServer ps = new PrintServer();

  Client c1 = new Client(ps, "A", "Hello", 5);
  Client c2 = new Client(ps, "B", "Critical", 10);
  Client c3 = new Client(ps, "C", "Sections", 15);
 
 }//main
}