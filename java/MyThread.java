/*
An application performs a task or a 
series of tasks.
And a task is a collection of multiple 
sub-tasks.

For an application a method or a group
of methods represent a sub-task.

If the application executes all of its 
tasks "sequentially" then it is a single
threaded application.

If the application executes its tasks
concurrently then it is a multithreaded
application.

Every application is single threaded by
default. To enable multithreading the
application must create custom threads.

A thread is a parallel running program
control that allows concurrent execution
of sub tasks of the application.

To implement multithreading, Java provides 2 ways
1) Through use of a class that extends Thread.
2) Through use of a class that implements Runnable and uses Thread object.

==============================================
Implementing multithreading by inheriting Thread class.

* Define a class that extends Thread
* Every object of such a class will be a user defined thread.
* Every user defined thread is in "inactive state" by default.
* It must be explicitly actived (only once) by calling "start()" on it.
* An active thread begins parallel execution of "run()" method.
* run() is the life cycle method for all the user defined threads.
* A sub-class of Thread inherits an empty definition of run().
Hence it must be overridden so that the user defined thread 
has specific task to perform.

*/

class MyThread extends Thread
{
 public void run()
 {
  int i;
  for(i =0 ; i< 100; i++)
   System.out.print(" R ");
 }

 public static void main(String args[])
 {
  MyThread mt = new MyThread();//a user defined inactive thread
  mt.start(); //activate the thread
  System.out.println("Active Thread Count : " + Thread.activeCount());

  int i;
  for(i =0 ; i< 100; i++)
   System.out.print(" M ");

 }//main
}//MyThread


/*
Thread.activeCount()
-------------------
activeCount() is a public and static
method of class Thread.
It returns the number of currently
active threads for an application.

*/