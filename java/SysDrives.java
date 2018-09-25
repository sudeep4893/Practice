import java.io.File;

class SysDrives
{
 public static void main(String args[])
 {
  File allDrives[] = File.listRoots();//File[] representing root directries of current system

  int i;
  for(i =0 ; i< allDrives.length; i++)
  {
   System.out.println(allDrives[i].getAbsolutePath() + " " + allDrives[i].getUsableSpace() + " bytes available for use " );
  }
 }//main
}