import java.util.Arrays;

public class Strings
{
    public static void main(String[] args) 
    {
        String s = "computer";
        System.out.println("String : " + s);
        System.out.println("char at pos(0) " + s.charAt(0));
        System.out.println("length " + s.length());
        System.out.println("Replacing c with C  "  + s.replace('c', 'C'));
        System.out.println("substring(3) " + s.substring(3));
        System.out.println("substring(3, 6) " + s.substring(3,6));
        System.out.println("lowercase " + s.toLowerCase());
        System.out.println("uppercase " + s.toUpperCase());
        System.out.println("concat(programming) " + s.concat("programming"));
        System.out.println("compareTo(apple) " + s.compareTo("apple"));
        System.out.println("compareTo(computer) " + s.compareTo("computer"));
        System.out.println("compareTo(horse) " + s.compareTo("horse"));
        System.out.println("equals(computer) " + s.equals("computer"));
        System.out.println("equalsIgnoreCase(COMPuter) " + s.equalsIgnoreCase("COMPuter"));
        System.out.println("indexOf(o) " + s.indexOf('o'));
        System.out.println("startsWith(com) " +  s.startsWith("com"));
        System.out.println("endsWith(com) " +  s.endsWith("com"));
        
        byte b[] = s.getBytes();
        System.out.println("bytes " + Arrays.toString(b));
        
        s = "this is a sample sentence";
        String words[]  = s.split(" ");
        System.out.println("words " + Arrays.toString(words));
        
        
    }
}
