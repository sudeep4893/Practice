import java.applet.*;
import java.awt.*;
import java.awt.event.*;

public class MouseApp extends Applet implements MouseListener
{
 String msg;
 int x, y;

 public void init()
 {
   Font f = new Font("Arial", Font.BOLD, 30);
   setFont(f);
   //apply mouse listener to the applet
   addMouseListener(this);
 }

 public void mouseClicked( MouseEvent e)
 {
    x = e.getX();
    y = e.getY();

    int b = e.getButton();
    String bname = ""; 
    if(b == MouseEvent.BUTTON1)
       bname = "LEFT";
    else if(b == MouseEvent.BUTTON2)
       bname = "CENTER";
    else if(b == MouseEvent.BUTTON3)
       bname = "RIGHT";

    msg = bname + " Clicked " + e.getClickCount() + " times  at " + x + "," + y;       
    repaint();		
 }

 public void mousePressed(MouseEvent e)
 {}
 public void mouseReleased(MouseEvent e)
 {}

 public void mouseEntered(MouseEvent e)
 {
   x = e.getX();
   y = e.getY();
   msg = "Mouse On Applet at " + x + "," + y;
   setBackground(Color.YELLOW);
   repaint();
 }

 public void mouseExited(MouseEvent e)
 {
   msg = "mouse not on applet";
   setBackground(Color.WHITE);
   repaint();
 }

 public void paint(Graphics g)
 {
   g.drawString(msg, 10,100);
 }
}