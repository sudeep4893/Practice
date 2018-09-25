import java.applet.*;
import java.awt.*;

public class MyApplet extends Applet
{
 String s;

 public void init()
 {
   s = "init";

   Font f = new Font("Arial", Font.PLAIN, 40); //name, style, size
   setFont(f); //set applets font 
   setBackground(Color.YELLOW);//to set applets background color
   setForeground(Color.RED);//to set applets foreground color
 }

 public void start()
 {
   s = s  + " start";
 } 

 //override for rendering output
 //Graphics g is a formal parameter to paint
 //It is a handle to the Applets output rendering object.
 //Browser calls paint as required (redraw needs).

 public void paint(Graphics g)
 {
  s = s + " paint";
  g.drawString(s, 100,100); //drawString(msg, x, y) 
 }

}//MyApplet
