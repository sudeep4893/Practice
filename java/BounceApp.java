import java.applet.*;
import java.awt.*;
import java.util.Random;

public class BounceApp extends Applet implements Runnable
{
 int x, y;
 int chgX, chgY;
 int w, h;
 
 int r, g, b;
 Random rnd;
 boolean bounceFlag;
 Thread bounceThread;

 public void init()
 {
  x = 100;//assumed value
  y = 70;//assumed value
  chgX = 5;//assumed defaults
  chgY = 5;//assumed defaults
  
  w = getWidth();//fetch applet width
  h = getHeight();//fetch applet height

  rnd = new Random();
  setBackground(Color.YELLOW);
  setColor();
 }

 void setColor()
 {
  r = rnd.nextInt(256); //generate a random int in range 0-255
  g = rnd.nextInt(256); //generate a random int in range 0-255
  b = rnd.nextInt(256); //generate a random int in range 0-255
  setForeground(new Color(r, g, b));
 }

 public void start()
 {
  bounceFlag = true;
  bounceThread = new Thread(this);
  bounceThread.start();
 }

 public void stop()
 {
  bounceFlag = false;
 }

 public void run()
 {
  while(bounceFlag == true)
  {
    if(x <= 0 || x >= (w-50) )
    {//change x direction 
	chgX *= -1;
	setColor();
    }
    if(y <= 0 || y >= (h-50) )
    {//change y direction 
	chgY *= -1;
	setColor();
    }
    x = x + chgX;
    y = y + chgY;

    repaint(); //request the web browser to call paint    

    try
    {
     Thread.sleep(100);//100 millis delay
    }
    catch(InterruptedException e)
    {}
  }//while
 }//run


 public void paint(Graphics g)
 {
   g.fillOval(x,y,50,50);//fillOval(x,y,w,h)
 }
}