/*
Consider a case that a thread inside
a critical section realizes that its next
action is possible only after another
thread completes its execution.

In such a scenario the thread that owns
the critical section (and hence the shared
resource) must suspend ownself and leave 
the resource ownership.
Thus giving other threads a chance to execute
the critical section and use the shared
resource.

*/

import java.util.Random;

class DataHolder
{
  int number;
  boolean isDataSet;//by default false 

  synchronized void setNumber(int x)
  {
     Thread t = Thread.currentThread();
     System.out.println(t.getName() + " in for setting number " + x);
     if(isDataSet == true)
     {//data is already set and is not consumed
      //suspend ownself 
      try
      {
       wait();//infinite suspension
      }
      catch(InterruptedException ex)
      {}
     }//if
     number = x;
     isDataSet = true;
     System.out.println(t.getName() + " has set the number ");
     notify(); //to bring a waiting thread out of suspension
     //notifyAll(); //to bring all waiting threads out of suspension
  }

  synchronized void displayNumber()
  {
     Thread t = Thread.currentThread();
     System.out.println(t.getName() + " in for getting a number ");
     if(isDataSet == false)
     {//data not set yet, better suspend ownself
      try
      { 
       wait();
      }
      catch(InterruptedException ex)
      {}
     }//if
     System.out.println("GOT A VALUE : " + number);
     isDataSet = false;
     notify(); //to bring a waiting thread out of suspension
     //notifyAll(); //to bring all waiting threads out of suspension
  }  
}//DataHolder


class Reader extends Thread
{
 DataHolder ref;
 int times; 
 Reader(DataHolder dh , String name, int x)
 {
  ref = dh;
  setName(name);
  times = x;
  start();
 }

 public void run()
 {
  int i, val;
  for(i =0; i< times; i++)
  {
   ref.displayNumber();
  }  
 }//run

}


class Writer extends Thread
{
 DataHolder ref;
 int times; 
 Writer(DataHolder dh , String name, int x)
 {
  ref = dh;
  setName(name);
  times = x;
  start();
 }

 public void run()
 {
  int i, val;
  Random r = new Random();
  for(i =0; i< times; i++)
  {
   val = r.nextInt(100);//generate any random int value in range 0-99
   ref.setNumber(val);
  }  
 }//run

}


class ReaderWriter
{
 public static void main(String args[])
 {
  DataHolder dh = new DataHolder();
  Writer w = new Writer(dh, "writer", 10);
  Reader r = new Reader(dh, "reader", 10);
 }
}