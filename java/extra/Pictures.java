import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class Pictures extends JFrame implements ItemListener
{
  JLabel jl;
  ImageIcon i1, i2, i3, i4;
  JComboBox<String> jcmb;
  Pictures()
  {
    setLayout(new BorderLayout());
    i1 = new ImageIcon("images/i1.gif");
    i2 = new ImageIcon("images/i2.gif");
    i3 = new ImageIcon("images/i3.gif");
    i4 = new ImageIcon("images/i4.gif");

    jl = new JLabel(i1);

    String arr[] = {"Cat", "Cab", "Fish", "Moon"};
    jcmb = new JComboBox<String>(arr);

    //jcmb.addItem("Cat");
    //jcmb.addItem("Cab");
    //jcmb.addItem("Fish");
    //jcmb.addItem("Moon");	

    jcmb.addItemListener(this);
    add(jcmb, BorderLayout.NORTH);
    add(jl, BorderLayout.CENTER);

    setSize(400, 300);
    setVisible(true);
    setDefaultCloseOperation(DISPOSE_ON_CLOSE);
  
 }

 public void itemStateChanged(ItemEvent ie)
 {
   int  i =  jcmb.getSelectedIndex();
   String s = jcmb.getSelectedItem().toString();

   if(i == 0)
   {
      jl.setIcon(i1);
      jl.setText(s);
   }
   else if(i == 1)
   {
      jl.setIcon(i2);
      jl.setText(s);
   }
   else if(i == 2)
   {
      jl.setIcon(i3);
      jl.setText(s);
   }
   else if(i == 3)
   {
     jl.setIcon(i4);
     jl.setText(s);
   }
 }
 public static void main(String args[])
 {
   new Pictures();
 }
}	