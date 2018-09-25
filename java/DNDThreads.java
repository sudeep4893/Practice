/*
Threads can be categorized as
1) Non Daemon Threads
2) Daemon Threads

Every thread (including main) is non-
daemon thread by default.
A non daemon thread will performs its
task completly (if not terminated due
to any exception).

A daemon thread will performs its
task either completly or as long as
any other non-daemon thread is
running, whichever first.

On completion of all other non-daemon
threads, a daemon thread terminates
prematurely.

We make threads daemon to perform
background operations of the application.

How to make a thread daemon/non-daemon?
---------------------------------------
All the threads are by deafult non-daemon
in Java.
Still this attribute can be changed by 
the method "setDaemon(boolean)" before
the thread is started.

*/

class DNDThreads extends Thread
{
 DNDThreads(String s)
 {
   setName(s); //set s as the name of the current thread
   if(s.equals("B"))
     setDaemon(true); //set th2 as a daemon thread
   start();
 }

 void f1()
 {
  System.out.println("\n f1 starts");
  int i;
  for(i =0 ; i< 100; i++)
   System.out.print(" - ");

  System.out.println("\n f1 ends");
 }

 void f2()
 {
  System.out.println("\n f2 starts");
  int i;
  for(i =0 ; i< 1000; i++)
   System.out.print(" | ");

  System.out.println("\n f2 ends");
 }

 public void run()
 {
  String nm = getName();//fetch the name of the current thread
  if(nm.equals("A"))
   f1();
  else if(nm.equals("B"))
   f2();
 }

 public static void main(String args[])
 {
  System.out.println("\n main starts");

  DNDThreads th1 = new DNDThreads("A");
  DNDThreads th2 = new DNDThreads("B");
  
  int i;
  for(i =0 ; i< 100; i++)
   System.out.print(" + ");

  System.out.println("\n main ends");
 }//main
}//DNDThreads	


/*
A Java Application Ends due to
1) End of life of all non-daemon threads
2) Call to System.exit();
3) Exception that causes termination of JVM.
*/