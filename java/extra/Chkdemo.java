import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class Chkdemo extends JFrame implements ItemListener
{
 JCheckBox cb1, cb2,cb3;
 JLabel jlbl;
 JPanel jp;

 Chkdemo()
 {
  jp  = new JPanel();
  jp.setLayout(new GridLayout(1,3));
  setLayout(new GridLayout(2,1));

  cb1 = new JCheckBox("C");
  cb2 = new JCheckBox("C++");
  cb3 = new JCheckBox("Java", true);		
	
  cb1.addItemListener(this);
  cb2.addItemListener(this);
  cb3.addItemListener(this);

  jlbl = new JLabel("Languages Known :  Java ");
	
  jp.add(cb1);
  jp.add(cb2);
  jp.add(cb3);
	
  add(jp);
  add(jlbl);

  setSize(300, 200);
  setVisible(true);
  setDefaultCloseOperation(DISPOSE_ON_CLOSE);
  
 }
	
 public void itemStateChanged(ItemEvent ie)
 {
    String s1 = "Languages Known : ";
    if(cb1.isSelected())
       s1 = s1 + cb1.getText() +  "   ";
    if(cb2.isSelected())
       s1 = s1 + cb2.getText() +  "   ";
    if(cb3.isSelected())
       s1 = s1 + cb3.getText() +  "   ";

    jlbl.setText( s1);	
 }

 public static void main(String args[])
 {
   new Chkdemo();
 }
}
	