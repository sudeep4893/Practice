import javax.swing.*;
import java.awt.event.*;

class Buttons extends JFrame implements MouseListener
{
 JButton bttnTest;
 ImageIcon ic1, ic2;

 Buttons()
 {
  initComponent();
  setSize(500, 300);
  setDefaultCloseOperation(EXIT_ON_CLOSE);
  setResizable(false);
  setVisible(true);
 }

 void initComponent()
 {
  ic1 = new ImageIcon("img1.jpg");
  ic2 = new ImageIcon("img2.jpg");

  bttnTest = new JButton(ic1);
  bttnTest.addMouseListener(this);
  
  setLayout(null);
  add(bttnTest);
  bttnTest.setBounds(100,75, 200, 150);
 }

 public void mouseClicked(MouseEvent e) 
 {}

 public void mousePressed(MouseEvent e)
 {}

 public void mouseReleased(MouseEvent e)
 {}

 public void mouseEntered(MouseEvent e)
 {
   bttnTest.setIcon(ic2);
 }

 public void mouseExited(MouseEvent e)
 {
   bttnTest.setIcon(ic1); 
 }

 public static void main(String args[])
 {
  Buttons obj = new Buttons();
 }

}