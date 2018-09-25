/*
Thread Interrupt
----------------
A thread interrupt is used to
* bring a target thread out of sleep.
* bring a target thread out of join. (To avoid deadlocks).
* bring a target thread out of wait. (To avoid deadlocks).
* signal "termination" to a target thread. (Doesnt cause termination).


*/

class TInterrupt implements Runnable
{
 Thread t;
 TInterrupt()
 {
  t = new Thread(this);
  t.start();
 } 

/*
//case : Interrupt used to bring a thread out of sleep
 public void run()
 {
  int i;
  for(i =1; i<= 20; i++)
  {
   System.out.print(" - ");
   if(i == 5)
   {
     try
     {
       System.out.println("I m tired and going to sleep");
       Thread.sleep(10000);//10 seconds delay
       System.out.println("I m feeling better now");
     }
     catch(InterruptedException ex)
     {
       System.out.println("I didnt got a complete sleep");
     } 
   }//if

  }//for
 }//run
*/

//case : Interrupt used to signal termination
 public void run()
 {
  int i;
  for(i =0; i< 500; i++)
  {
   if(Thread.interrupted()) //test for an interrupt signal and reset the signal
   //if(t.isInterrupted()) //test for an interrupt signal but donot reset the signal
   {
    System.out.println("main wants me to terminate");
    //return ;//self termination
   }  
   System.out.print(" - ");
  }//for
 }//run


 public static void main(String args[])
 {
  TInterrupt ti = new TInterrupt();

  int i;
  for(i =0; i<50; i++)
   System.out.print(" | ");  

  ti.t.interrupt();//an interrupt signal

  System.out.println("main ends");
 }//main

}