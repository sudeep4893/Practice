import javax.swing.*;
import java.awt.*;

class BLDemo extends JFrame
{
 JButton bttn1, bttn2, bttn3, bttn4, bttn5;
 BLDemo()
 {
   bttn1  = new JButton("East");
   bttn2  = new JButton("West");
   bttn3  = new JButton("North");
   bttn4  = new JButton("South");
   bttn5  = new JButton("Center");

   //layout manager will size and pos the components automatically
   setLayout(new BorderLayout());

   add(bttn1, BorderLayout.EAST);
   add(bttn2, BorderLayout.WEST);
   add(bttn3, BorderLayout.NORTH);
   add(bttn4, BorderLayout.SOUTH);
   add(bttn5, BorderLayout.CENTER); 

   setSize(500, 300);
   setVisible(true);
   setDefaultCloseOperation(EXIT_ON_CLOSE);
 }//BLDemo

 public static void main(String args[])
 {
   new BLDemo();
 }
}