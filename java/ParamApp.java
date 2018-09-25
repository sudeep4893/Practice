//READING HTML PARAMETERS IN APPLET

import java.awt.*;
import java.applet.*;

public class ParamApp extends Applet
{
 String s1,s2;

 public void init()
 {
   setFont(new Font("Arial", Font.PLAIN, 48));

   //fetch html parameter named p1 or become null
   s1 = getParameter("p1");
   //fetch html parameter named p2 or become null
   s2 = getParameter("p2");

   if(s1 == null)
    s1 = "Hello";
   if(s2 == null)
    s2 = "Java";
  
 }//init

 public void paint(Graphics g)
 {
  g.drawString(s1, 50, 100);//string,x,y 
  g.drawString(s2, 50, 200);//string,x,y 
 }
}
