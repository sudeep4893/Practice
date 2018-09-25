//single dimensional arrays

class SDim
{
 public static void main(String args[])
 {
  //C code : int arr[4]; 
  //Java code
  int arr[] = new int[4];

  int i;
  //set data
  for(i =0 ; i< arr.length; i++)
    arr[i] = i + 10;

  //another int array reference
  int q[];
  q = arr;

  //display data
  System.out.println();//start a new line
  for(i =0 ; i< q.length; i++)
    System.out.print( q[i] + "  ");


 }//main
}//SDim

/*
Consider the statement : int arr[] = new int[4];

int arr[] : declares an integer array reference.
new int[4] : allocates memory for an int array of size 4.
= : transfers the initial address of the array into the reference.
---------------------------------------
Array reference can be declared in 2 ways
1) dataType refName[];
2) dataType []refName;

In both cases they mean the same.
But consider the different through an example.

int arr[], a, b;
declares arr as int array reference and a,b as int variables

int []arr, a, b;
declares arr,a,b as int array references

---------------------------------------
Reference : A reference is an entity
that can store address and is dereferencable.
*/