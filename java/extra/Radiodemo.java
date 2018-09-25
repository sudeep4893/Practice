import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class Radiodemo extends JFrame implements ActionListener
{
 JLabel jlbl;
 JRadioButton rb1, rb2, rb3;
 ButtonGroup bg1;
 JPanel p;
	
 Radiodemo()
 {
   jlbl = new JLabel("Graduate");
   rb1 = new JRadioButton("Under Graduate");
   rb2 = new JRadioButton("Graduate", true);
   rb3 = new JRadioButton("Post Graduate");		

   bg1 = new ButtonGroup();
   bg1.add(rb1);		
   bg1.add(rb2);
   bg1.add(rb3);
		
   rb1.addActionListener(this);
   rb2.addActionListener(this);
   rb3.addActionListener(this);

   setLayout(new GridLayout(2,1));
   p = new JPanel(new GridLayout(1,3));
   p.add(rb1);
   p.add(rb2);
   p.add(rb3);

   add(p);
   add(jlbl);
   
   setSize(400, 300);
   setVisible(true);
   setDefaultCloseOperation(DISPOSE_ON_CLOSE);
  
 }

 public void actionPerformed(ActionEvent ae)
 {
   if(rb1.isSelected())
       jlbl.setText("UnderGraduate");
   else if(rb2.isSelected())
       jlbl.setText("Graduate");
   else if(rb3.isSelected())
       jlbl.setText("PostGraduate");

   //same as above code
   //jlbl.setText(ae.getActionCommand());
 }
  
 public static void main(String args[])
 {
   new Radiodemo();
 }
}