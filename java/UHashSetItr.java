import java.util.HashMap;
import java.util.Set;
import java.util.Iterator;

/*
 HashMap stores values associated with keys. 
 Even null object can be used as a key or as a value.
 
 A set is a collection of non duplicate elements.

 An iterator helps traverse over a collection.
*/

public class UHashSetItr
{
    public static void main(String[] args) 
    {
        HashMap<String, Integer> cities = new HashMap<String, Integer>();
        
        cities.put("mumbai", 38);
        cities.put("pune", 32);
        cities.put("nasik", 35);
        cities.put("nagpur", 37);
        
        System.out.println("temperature in pune : " + cities.get("pune"));
        
        cities.remove("nasik");
        
        if(cities.containsKey("nasik"))
            System.out.println("temperature of nasik is available");
        else
            System.out.println("temperature of nasik is not available");
        
        Set<String> cityNames = cities.keySet();
        
        Iterator<String> itrCities = cityNames.iterator();
        
        String s;
        while(itrCities.hasNext())
        {
            s = itrCities.next();
            System.out.println("city " + s + "  temperature : " + cities.get(s));
        }   
        
    }
}
