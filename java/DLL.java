import java.util.LinkedList;

/*
 Doubly-linked list.
*/

public class DLL 
{
    public static void main(String[] args) 
    {
        LinkedList<String> subjects = new LinkedList<String>();
        int i, indx;

        subjects.add("C++");//append an element into the list
        subjects.add("Oracle");
        subjects.add("VB");
        subjects.add("Java");

        subjects.addFirst("C");//add an element at beginning of list
        subjects.add(1, "DS");//add an element at specific index
        subjects.addLast("Enterprise Java");//append an element

        for(i =0; i< subjects.size(); i++) 
            System.out.println(subjects.get(i));//index based element fetching

        indx = subjects.indexOf("Oracle"); //search for an element
        if(indx != -1)
            System.out.println("Oracle found at index : "  + indx);
        else
            System.out.println("Oracle not found");

        //subjects.remove();//remove first elememt

        //subjects.remove(2);//removes element at index 2

        //subjects.remove("VB");//removes specific element

        //subjects.removeLast();//removes last element

        subjects.push("C#.NET");//add element at top (as first element)

        System.out.println("first element " +  subjects.peek());//fetch first element
        System.out.println("last element "  + subjects.peekLast());//fetch last element

        System.out.println("removed first element " +  subjects.poll());//fetch and remove first element
        System.out.println("removed first element " +  subjects.pop());//fetch and remove first element
        System.out.println("removed last element "  +  subjects.pollLast());//fetch and remove last element

        subjects.clear();//remove all elements
        System.out.println("list contains " + subjects.size() + " elements ");
    }
}
