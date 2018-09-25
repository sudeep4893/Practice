import java.util.Enumeration;
import java.util.Properties;

public class Props
{
    public static void main(String[] args) 
    {
        Properties p = new Properties();
        p.put("a", "one");
        p.put("b", "two");
        p.put("c", "three");

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
