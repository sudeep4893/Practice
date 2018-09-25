/*
Thread Sleep
------------
Sleep is used by a thread to voluntarily 
suspend itself for a specific time.

The accuracy of sleep time is dependent
on operating systems timers and schedulers.

Thread.sleep(millis) raises InterruptedException
which the caller of the method must handle.

Applying sleep is a way to implement 
a delay in multi-threading.
 
*/
class TSleep implements Runnable
{
 Thread t; //for multithreading

 TSleep()
 {
   t = new Thread(this);//create a new thread
   t.start();//activate it
 } 

 //interface method that is compulsory to override
 public void run()
 {
  int i;
  for(i =1 ; i<= 10; i++)
  {
   System.out.println("* " + System.currentTimeMillis());
   try
   {
    Thread.sleep(1000);//1000 == 1 sec
   }
   catch(InterruptedException ex)
   {}
  }
 }
  
 public static void main(String args[])
 {
  TSleep ts =  new TSleep();
 }//main
}
