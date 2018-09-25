/*
Thread Priority
--------------
Thread Priority decides which of the
multiple available threads will access
a resource first.

A high thread priority causes 
* repeated access of resource to the current thread
* starvation of other threads.

So the idea of increasing a threads priority
is against the idea of co-operative multitasking.

In Java, 
All threads have a default normal priority : 5
Minimum thread priority can be : 1
Maximum thread priority can be : 10

Threads priority can be changed using : setPriority(int)
A value beyond the range 1-10 will cause 
IllegalArgumentException.
A threads priority can be set even after it is started.

Threads priority can be fetched using : int getPriority()
*/


class TPrior implements Runnable
{
 Thread t;
 TPrior(int x)
 {
  t = new Thread(this);
  t.setPriority(x);
  t.start();
 } 

 public void run()
 {
  int i;
  for(i =0; i<500; i++)
  {
   System.out.print(" - ");
  }
 }//run

 public static void main(String args[])
 {
  TPrior tp = new TPrior(8);//a priority higher than normal 

  Thread mt = Thread.currentThread(); //a handle to main thread
  mt.setPriority(3);//a priority lower than normal

  int i;
  for(i =0; i<500; i++)
   System.out.print(" | ");  

 }//main

}