import javax.swing.*;
import java.awt.*;

class GLDemo extends JFrame
{
 JButton bttn1, bttn2, bttn3, bttn4, bttn5, bttn6;
 GLDemo()
 {
   bttn1  = new JButton("A");
   bttn2  = new JButton("B");
   bttn3  = new JButton("C");
   bttn4  = new JButton("D");
   bttn5  = new JButton("E");
   bttn6  = new JButton("F");

   //layout manager will size and pos the components automatically
   setLayout(new GridLayout(3, 2));
   add(bttn1);
   add(bttn2);
   add(bttn3);
   add(bttn4);
   add(bttn5); 
   add(bttn6); 

   setSize(500, 300);
   setVisible(true);
   setDefaultCloseOperation(EXIT_ON_CLOSE);
 }//GLDemo

 public static void main(String args[])
 {
   new GLDemo();
 }
}