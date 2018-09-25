//Two Dimensional Arrays

class TDim
{
 public static void main(String args[])
 {
  //C : int mat[3][4];
  //Java :
  int mat[][] = new int[3][4];
  int i, j;

  //set data
  for(i =0 ; i< mat.length; i++)
  {
   for(j =0 ; j<mat[i].length; j++)
   {
    mat[i][j] = i+j+10;	
   }//for(j
  }//for(i

  //display data
  System.out.println();//skip a line
  for(i =0 ; i< mat.length; i++)
  {
   System.out.println();//skip a line
   for(j =0 ; j<mat[i].length; j++)
   {
    System.out.print(mat[i][j] + "  ");	
   }//for(j
  }//for(i

//swap row 2 and row 3
  int temp[];
  temp = mat[1];
  mat[1] = mat[2];
  mat[2] = temp;

  //display data
  System.out.println();//skip a line
  for(i =0 ; i< mat.length; i++)
  {
   System.out.println();//skip a line
   for(j =0 ; j<mat[i].length; j++)
   {
    System.out.print(mat[i][j] + "  ");	
   }//for(j
  }//for(i

 }//main
}//TDim

/*
Consider the statement
  int mat[][] = new int[3][4];

int mat[][] : Declares a reference to an array of integer array references.
new int[3][4] : Declares a two dimensional int array of size 3 rows with 4 cols each.
= : assigns the address of two dimensional array to the reference.
*/
