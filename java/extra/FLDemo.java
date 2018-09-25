import javax.swing.*;
import java.awt.*;

class FLDemo extends JFrame
{
 JButton bttn1, bttn2, bttn3, bttn4, bttn5;
 FLDemo()
 {
   bttn1  = new JButton("A");
   bttn2  = new JButton("B");
   bttn3  = new JButton("C");
   bttn4  = new JButton("D");
   bttn5  = new JButton("E");

   Dimension d1 = new Dimension(100, 40);	
   Dimension d2 = new Dimension(120, 70);
   bttn1.setPreferredSize(d1);
   bttn3.setPreferredSize(d2);

   //layout manager will size and pos the components automatically
   setLayout(new FlowLayout(FlowLayout.CENTER));
   add(bttn1);
   add(bttn2);
   add(bttn3);
   add(bttn4);
   add(bttn5); 

   setSize(500, 300);
   setVisible(true);
   setDefaultCloseOperation(EXIT_ON_CLOSE);
 }//BLDemo

 public static void main(String args[])
 {
   new FLDemo();
 }
}