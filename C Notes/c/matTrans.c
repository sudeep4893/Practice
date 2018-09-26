#include<stdio.h>

//Matrix Transpose Using Functions
//transpose == interchange rows and cols

void scanMat(int m[][3], int r, int c)
{
    int i, j;
    for(i =0; i< r; i++)
    {
        for(j =0; j< c; j++)
        {
            printf("\n enter data for mat[%d][%d] ", i, j);
            scanf("%d", &m[i][j]);
        }
    }
    
}

void dispMat(int m[][3], int r, int c)
{
    int i, j;
    for(i =0; i< r; i++)
    {
        printf("\n");
        for(j =0; j< c; j++)
        {
            printf(" %3d", m[i][j]);
        }
    }
    
}

void transpose(int mat[][3], int r, int c)
{
    int i, j;
    int temp;
    printf("\n");
    for(i =0 ; i< r; i++)
    {
        for(j = i+1; j< c; j++)
        {
            temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }
}

int main()
{
    int mat[3][3];
    scanMat(mat, 3, 3);
    dispMat(mat, 3, 3);
    transpose(mat,3,3);
    dispMat(mat, 3, 3);
    
    return 0;
}
/*
To pass a matrix as a parameter to a function
simply pass its name. 
It is a good practice to pass the number of rows 
and number of cols as extra parameters along with  
the matrix. 
 
To receive a matrix as a formal parameter 
the function must know the datatype and the 
number of cols in the matrix. Row dimension 
is optional. (see the code).
 
Note that name of the matrix represents the
address of first cell (row zero, col zero)  
of the matrix. 
i.e. mat == &mat[0][0] 
Hence know that matrix is passed by reference.
*/