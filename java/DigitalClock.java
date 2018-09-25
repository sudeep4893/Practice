//Digital Clock
import java.applet.*;
import java.awt.*;
import java.util.Calendar;

public class DigitalClock extends Applet implements Runnable
{
 String s;
 Calendar cal;
 Thread t;
 boolean flag;

 public void init()
 {
  cal = Calendar.getInstance();
  setBackground(Color.YELLOW);
  setForeground(Color.RED);
  setFont(new Font("Arial", Font.BOLD, 48));
  setTime();
 }//init
 
 public void start()
 {
  flag = true;
  t = new Thread(this);
  t.start();
 }

 public void stop()
 {
  flag = false;
 }

 public void run()
 {
  while(flag)
  {
    setTime();
    repaint();

    try
    {
      Thread.sleep(995);//sleep accuracy tolerance + processing time
    }
    catch(InterruptedException ex)
    {}
  }
 }//run

 void setTime()
 {
   //apply current time
   cal.setTimeInMillis(System.currentTimeMillis());
   //fetch 
   s = String.valueOf(cal.get(Calendar.DATE));
   s = s + "/" + ( cal.get(Calendar.MONTH) + 1);
   s = s + "/" + cal.get(Calendar.YEAR);
   s = s + "  " + cal.get(Calendar.HOUR);
   s = s + ":" + cal.get(Calendar.MINUTE);
   s = s + ":" + cal.get(Calendar.SECOND);
   
   if(cal.get(Calendar.AM_PM) == Calendar.AM)
     s = s  + "  am";
   else
     s = s  + "  pm";

 }//setTime

 public void paint(Graphics g)
 {
   g.drawString(s, 30,100);//string, x, y
 }
}
