import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class NumberGenerator extends JFrame implements ActionListener, Runnable
{
 JButton bttnStart, bttnStop;
 JLabel lblNumbers;
 JTextField txtNumbers;
 int x;
 boolean flag;

 NumberGenerator(String s)
 {
  initComponents();  
  setTitle(s);//set window title
  setSize(500, 300);//width, height
  setResizable(false);
  setVisible(true);//render it 
  setDefaultCloseOperation(EXIT_ON_CLOSE);
 }

 void initComponents()
 {
  //create the components
  lblNumbers = new JLabel("Numbers : ");
  txtNumbers = new JTextField("");
  bttnStart = new JButton("Start");
  bttnStop = new JButton("Stop");

  //set the font
  Font f = new Font("Arial", Font.PLAIN, 30 );
  lblNumbers.setFont(f);
  txtNumbers.setFont(f);
  bttnStart.setFont(f);
  bttnStop.setFont(f);

  //set text field as read only
  //txtNumbers.setEnabled(false);  
  //or
  txtNumbers.setEditable(false);


  //set backColor for the buttons
  bttnStart.setBackground(Color.GREEN);
  bttnStop.setBackground(Color.GRAY);
  bttnStop.setEnabled(false);
 
  //event enable the button
  bttnStart.addActionListener(this);
  bttnStop.addActionListener(this);

  //donot auto manage the component position and size
  setLayout(null);

  //add the components in the Window
  add(lblNumbers);
  add(txtNumbers);
  add(bttnStart);
  add(bttnStop);

  //explicitly manage the component position and size
  lblNumbers.setBounds(50, 70, 150, 50);//x,y,w,h
  txtNumbers.setBounds(230, 70, 150, 50);//x,y,w,h
  bttnStart.setBounds(50, 150, 150, 50);//x,y,w,h
  bttnStop.setBounds(230, 150, 150, 50);//x,y,w,h

 }

 //interface method, called by JButton onClick event
 public void actionPerformed(ActionEvent e)
 {
  //System.out.println(Thread.currentThread());
  Object temp = e.getSource();
  if(temp.equals(bttnStart))
    start();
  else if(temp.equals(bttnStop))
    stop();
 }

 //on start click logic 
 void start()
 {
  flag = true;
  Thread t = new Thread(this);
  t.start();
  bttnStart.setEnabled(false);
  bttnStop.setEnabled(true);
  bttnStart.setBackground(Color.GRAY);
  bttnStop.setBackground(Color.RED);

 }

 //on stop click logic 
 void stop()
 {
  flag = false;
  bttnStop.setEnabled(false);
  bttnStart.setEnabled(true);
  bttnStop.setBackground(Color.GRAY);
  bttnStart.setBackground(Color.GREEN);
 }

 public void run()
 {
  while(flag)
  {
   x++;
   txtNumbers.setText(String.valueOf(x));
   try
   {
    Thread.sleep(200);
   }
   catch(InterruptedException ex)
   {}
  }//while
 }//run

 public static void main(String args[])
 {
   NumberGenerator ng = new NumberGenerator("Numbers");
 }
}