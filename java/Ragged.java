/*
Ragged Arrays
A Ragged array is a two dimensional
array in which the rows have different
number of columns.

To define a ragged array 
1) Define a multi dimensional array 
with value of last dimension "unset".
2) Explicitly define n arrays of different
sizes and connect with the multi dimensional
array.

Next the ragged array can be used
like any normal multi dimensional array.

*/
class Ragged
{
 public static void main(String args[])
 {
  int ragged[][] = new int[3][];
 
  //n arrays of different sizes, conneted with the multi dimensional array
  ragged[0] = new int[3];
  ragged[1] = new int[4];
  ragged[2] = new int[2];

  //usage 
  int i, j;

  //set data
  for(i =0 ; i< ragged.length; i++)
  {
   for(j =0 ; j<ragged[i].length; j++)
   {
    ragged[i][j] = i+j+10;	
   }//for(j
  }//for(i

  //display data
  System.out.println();//skip a line
  for(i =0 ; i< ragged.length; i++)
  {
   System.out.println();//skip a line
   for(j =0 ; j<ragged[i].length; j++)
   {
    System.out.print(ragged[i][j] + "  ");	
   }//for(j
  }//for(i

//swap row 2 and row 3
  int temp[];
  temp = ragged[1];
  ragged[1] = ragged[2];
  ragged[2] = temp;

  //display data
  System.out.println();//skip a line
  for(i =0 ; i< ragged.length; i++)
  {
   System.out.println();//skip a line
   for(j =0 ; j<ragged[i].length; j++)
   {
    System.out.print(ragged[i][j] + "  ");	
   }//for(j
  }//for(i

 }//main
}//Ragged