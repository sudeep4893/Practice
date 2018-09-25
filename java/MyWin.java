import javax.swing.*;

//prg to create 2 windows
//set their title and size
//set their close operation action

class MyWin extends JFrame
{
 MyWin(String s)
 {
  setTitle(s);//set window title
  setSize(500, 300);//width, height
  setVisible(true);//render it 
  //setDefaultCloseOperation(HIDE_ON_CLOSE);//default
  //setDefaultCloseOperation(EXIT_ON_CLOSE);
  setDefaultCloseOperation(DISPOSE_ON_CLOSE);
  //setDefaultCloseOperation(DO_NOTHING_ON_CLOSE);
 }

 public static void main(String args[])
 {
   //a window
   MyWin mw1 = new MyWin("WINDOW-1");
   //another window
   MyWin mw2 = new MyWin("WINDOW-2");

 }
}