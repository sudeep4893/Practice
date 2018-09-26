#include<stdio.h>

/*
 Matrix
 A matrix is a homogenous collection of data
 stored in tabular (row-column) format. 
 
 A multi (generally two) dimensional array is 
 used to represent a matrix in C.
 
 syntax
        datatype matrixName[Rows][Cols];
 example
        int mat[3][4];
 
 A matrix stores data in its cells.
 A matrix cell is identified as
        matrixName[rowIndex][colIndex]
 
 (see the diagram)
 
 Tip : Use nested loops to scan/process/print matrices.

Q) What is the difference between an array and a matrix? 
A) An array and a matrix differ in arrangement of
elements. Array arranges its elements in sequential form.
Whereas matrix arranges its elements in tabular form. 
 
Hence they use different indexing techniques. 
Array use sequential indexing and matrix uses
rowwise-columnwise multi dimensional indexing. 
 
 
*/

//Example to declare, scan and print a matrix
int main()
{
    int mat[3][4];
    int i, j;
    
    for(i =0 ; i< 3; i++)//row representation
    {
        for(j =0 ; j< 4; j++ )//col representation
        {
            printf("\n enter data for mat[%d][%d] ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
    
    printf("\n matrix : \n");
    for(i =0 ; i< 3; i++)
    {
        printf("\n");
        for(j =0 ; j< 4; j++ )
        {
            printf(" %3d", mat[i][j]);
        }
    }
    return 0;
}
