public class SysProp 
{
    public static void main(String[] args) 
    {
        System.out.println("Operating system architecture : " + System.getProperty("os.arch"));
        System.out.println("Operating system name : " + System.getProperty("os.name"));
        System.out.println("Operating system version : " + System.getProperty("os.version"));
    }
}