import java.util.Arrays;

/*
 Arrays class contains various methods for 
 manipulating  arrays (such as copy, sorting, 
 searching, ...).
*/

public class UArrays
{
    public static void main(String[] args) 
    {
        int arr1[] = {5, 7, 1, 4, 2};
        int arr2[];
        arr2 = Arrays.copyOf(arr1, arr1.length);//to copy an array
        
        System.out.println( Arrays.toString(arr1));//toString() convert array into a String
        System.out.println( Arrays.toString(arr2));
        
        if(Arrays.equals(arr1, arr2))//equals to compare 2 arrays
            System.out.println("Arrays are equal");
        else
            System.out.println("Arrays are not equal");
        
        Arrays.sort(arr1);//sorts an array
        
        System.out.println("After sorting arr1");

        if(Arrays.equals(arr1, arr2))
            System.out.println("Arrays are equal");
        else
            System.out.println("Arrays are not equal");
        
        
        System.out.println( Arrays.toString(arr1));
        System.out.println( Arrays.toString(arr2));
        
        int indx = Arrays.binarySearch(arr1, 4);//search for val 4 in arr1, returns indx or -1
        System.out.println("indx : " + indx);
    }
}