class RTime
{
 public static void main(String args[])
 {
  try
  {
    //Get ref to java's runtime env
    Runtime r = Runtime.getRuntime(); 
  
    System.out.println("available processors  " + r.availableProcessors());

    //fork the current process and start a new child process
    Process p  = r.exec("mspaint");
    Thread.sleep(10000);
     p.destroy();//kill processes started by you
 
    //r.exec("notepad");
/*
    Process p = r.exec("javac c:/java/FileCopy.java");
    p.waitFor(); //wait until compilation gets completed
    int x = p.exitValue();
    System.out.println(x); //0 means success, 1 means failure
*/
  }
  catch(Exception e)
  {}
 }
}