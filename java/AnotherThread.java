/*
Implementing multithreading by defining
a class that implements Runnable and
uses Thread object.
*/

class AnotherThread implements Runnable
{
 Thread t; //for multithreading

 AnotherThread()
 {
   t = new Thread(this);//create a new thread
   t.start();//activate it
 } 

 //interface method that is compulsory to override
 public void run()
 {
  int i;
  for(i =0 ; i< 500; i++)
   System.out.print(" | ");
 }
  
 public static void main(String args[])
 {
  AnotherThread at =  new AnotherThread();

  int i;
  for(i =0; i< 500; i++)
   System.out.print(" - ");
 }//main
}


/*
public class Thread implements Runnable
{
 Runnable X;
 ...

 Thread()
 {
   ....
   X = this;
 }

 Thread(Runnable r)
 {
   ...
   X = r;
 }


 void start()
 {
   ....
   X.run();
 }

 public void run()
 {}
}


*/