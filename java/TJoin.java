/*
Thread Join
------------
A thread join causes suspension of the
current thread until a target thread
(one being joined to) gets over (completes
its task).

If the target thread is already complete
then call to join wont cause any suspension.
The current thread will auto resume with
its next activity.

A call to join throws InterruptedException
which the caller must handle.
*/

class TJoin extends Thread
{
 TJoin()
 {
   start();
 }

 void f1()
 {
  System.out.println("\n f1 starts");
  int i;
  for(i =0 ; i< 1000; i++)
   System.out.print(" - ");

  System.out.println("\n f1 ends");
 }

 public void run()
 {
   f1();
 }

 public static void main(String args[])
 {
  System.out.println("\n main starts");

  TJoin tj = new TJoin();
  
  int i;
  for(i =0 ; i< 200; i++)
  {
   System.out.print(" + ");
   if(i == 100)
   {
    System.out.println("Before join, tj is alive : " + tj.isAlive());
    try
    {
     tj.join();//suspend this thread (main) until thread tj gets over.
    }
    catch(InterruptedException ex)
    {}
    System.out.println("After join, tj is alive : " + tj.isAlive());
   }//if

  }//for

  System.out.println("\n main ends");
 }//main
}//TJoin

