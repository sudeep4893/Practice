//Implementing application with 3 threads

class NThreads extends Thread
{
 int flag;
 NThreads(int x)
 {
  flag = x;
  start();//activate the thread
 }

 void f1()
 {
  System.out.println("f1 starts");
  int i;

  for(i =0; i< 500; i++)
   System.out.print(" F1 ");

  System.out.println("f1 ends");
 }

 void f2()
 {
  System.out.println("f2 starts");
  int i;

  for(i =0; i< 500; i++)
   System.out.print(" F2 ");

  System.out.println("f2 ends");
 }

 public void run()//entry point for a user defined thread
 {
  if(flag == 1)
   f1();
  else if(flag == 2)
   f2();
 }//end of life of the user defined thread

 public static void main(String args[])
 {
  //2 user defined threads
  NThreads n1 = new NThreads(1);
  NThreads n2 = new NThreads(2);

  int i;
  for(i =0; i< 500; i++)
   System.out.print(" M ");

  System.out.println("main ends");
 }
}