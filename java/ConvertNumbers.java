import java.awt.event.*;
import javax.swing.*;

class ConvertNumbers extends JFrame implements ActionListener
{
    JLabel lblDec, lblBinary, lblOct, lblHex;
    JTextField txtDec, txtBinary, txtOct, txtHex;
    JButton bttnCalculate;

    ConvertNumbers()
    {
        initComponents();
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setSize(350, 300);
        setVisible(true);

    }
    void initComponents()
    {
        lblDec = new JLabel("Decimal Number");
        lblBinary = new JLabel("Binary Number");
        lblOct = new JLabel("Octal Number");
        lblHex = new JLabel("Hex Number");

        txtDec = new JTextField();
        txtBinary = new JTextField();
        txtOct = new JTextField();
        txtHex = new JTextField();

        txtBinary.setEditable(false);
        txtOct.setEditable(false);
        txtHex.setEditable(false);

        bttnCalculate = new JButton("Calculate");
        bttnCalculate.addActionListener(this);

        setLayout(null);
        add(lblDec);
        add(lblBinary);
        add(lblOct);
        add(lblHex);

        add(txtDec);
        add(txtBinary);
        add(txtOct);
        add(txtHex);

        add(bttnCalculate);

        lblDec.setBounds(20, 20, 100, 30);
        txtDec.setBounds(140, 20 , 140, 30);
        lblBinary.setBounds(20, 70, 100, 30);
        txtBinary.setBounds(140, 70 , 140, 30);
        lblOct.setBounds(20, 120, 100, 30);
        txtOct.setBounds(140, 120 , 140, 30);
        lblHex.setBounds(20, 170, 100, 30);
        txtHex.setBounds(140, 170 , 140, 30);

        bttnCalculate.setBounds(20, 220, 100, 30);
    }

    public void actionPerformed(ActionEvent e)
    {
        try
        {
            String s = txtDec.getText().trim();
            int num = Integer.parseInt(s);
            convertBinary(num);
            convertHex(num);
            convertOct(num);
        }
        catch(Exception ex)
        {
            txtBinary.setText("");
            txtHex.setText("");
            txtOct.setText("");

            //JOptionPane.showMessageDialog(parent,message);
            //JOptionPane.showMessageDialog(this,"Invalid Input");

            //JOptionPane.showMessageDialog(parent,message, title, image);
           JOptionPane.showMessageDialog(this,"Invalid Input", "Number Converter", JOptionPane.ERROR_MESSAGE);
        }
    }

    void convertBinary(int n)
    {
        String temp = "";
        while(n > 0) 
        {	        	
            temp = n %2 + temp;
            n = n/2;
        }
        txtBinary.setText(temp);
    }

    void convertHex(int n)
    {
        String temp = "";
        int x;
        while(n > 0)
        {
            x = n %16;
            if(x <= 9)
                temp = x + temp;
            else if(x == 10)
                temp = "A" + temp ;
            else if(x == 11)
                temp = "B" + temp;
            else if(x == 12)
                temp = "C"+ temp ;
            else if(x == 13)
                temp =  "D" + temp ;
            else if(x == 14)
                temp = "E" + temp ;
            else if(x == 15)
                temp =  "F" + temp ;

            n = n/16;
        }
        txtHex.setText(temp);
    }

    void convertOct(int n)
    {
        String temp = "";
        while(n > 0)
        {
            temp = n %8 + temp;
            n = n/8;
        }
        txtOct.setText(temp);
    }

    public static void main(String args[])
    {
	new ConvertNumbers();
    }	
}
