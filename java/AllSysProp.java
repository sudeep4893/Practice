//fetch all System Properties

import java.util.Enumeration;
import java.util.Properties;

public class AllSysProp
{
    public static void main(String[] args) 
    {
        Properties p = System.getProperties();
        Enumeration key = p.keys();

        String keyName, keyValue; 

        while (key.hasMoreElements()) 
        {
            keyName = (String) key.nextElement();
            keyValue = (String) p.get(keyName);

            System.out.println(keyName + ": " + keyValue);
        }
    }
}
