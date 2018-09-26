#include <stdio.h>
#define SIZE 10
/*
 A sparse matrix is a matrix with many 
 zero values. In order to save space we
 store only the non-zero values of the
 matrix, in a struct array.
 Further all operations meant to be performed
 on sparse matrix are actually done on
 the struct array.
 */

struct Sparse
{
    int row, col, data;
};
typedef struct Sparse Sparse;

void scanSparse(Sparse s[])
{
    int r, c;
    int i, j, k;
    int temp;
    
    printf("\n Enter the no of rows in sparse matrix ");
    scanf("%d", &r);
    printf("\n Enter the no of cols in sparse matrix ");
    scanf("%d", &c);
    
    k = 1;//0 is header row which will be set at end
    
    for(i= 0; i< r; i++)//all the rows
    {
        for(j =0 ; j< c; j++)//all the cols
        {
            printf("\n enter value for mat[%d][%d] ", i, j);
            scanf("%d", &temp);
            
            if(temp != 0)
            {
                s[k].row = i;
                s[k].col = j;
                s[k].data = temp;
                k++;
            }
        }//for(j
    }//for(i
    //set the header row as well
    s[0].row = r;
    s[0].col = c;
    s[0].data = k-1;//total non zero values in sparse matrix
            
}//scanSparse


void dispSparse(Sparse s[])
{
    int r, c;
    int i, j, k;
    r = s[0].row;
    c = s[0].col;

    printf("\n");
    k = 1;
    for(i =0; i< r; i++)
    {
        printf("\n");
        for(j = 0; j< c; j++)
        {
          if(i == s[k].row && j == s[k].col)  
          {
              printf("%3d", s[k].data);
              k++;
          }
          else
          {
              printf("  0");
          }
        }
    }
    
}//dispSparse

void transpose(Sparse s2[], Sparse s1[])
{
    int i , j, tot;
    Sparse temp;
    //transfer s1 data into s2
    tot = s1[0].data; 
    for(i =0 ; i<= tot; i++)
    {
        s2[i].row = s1[i].col;
        s2[i].col = s1[i].row;
        s2[i].data = s1[i].data;
    }
    
    //bubble sort s2 row wise
    //we take care not to sort header row
    for(i = tot; i>1; i--)
    {
        for(j =1 ; j< i; j++)
        {
            if(s2[j].row > s2[j+1].row)
            {
                //swap
                temp = s2[j];
                s2[j] = s2[j+1];
                s2[j+1] = temp;
            }//if
        }//for(j
    }//for(i
    
}//transpose

void ftranspose(Sparse s2[], Sparse s1[])
{
    int c[SIZE], p[SIZE];
    int i, x, y;
    
    //init array elements to zero
    for(i =0; i< SIZE; i++)
        c[i] = 0;
 
    for(i = 1; i<= s1[0].data; i++)
    {
        x = s1[i].col;
        c[x]++;
    }
    
    //get positions of transposed matrix
    p[0] = 1;//matrix data is stored index 1 onwards
    for(i = 1; i< s1[0].col; i++)
    {
        p[i] = p[i-1] + c[i-1];
    }
    
    //init target matrix
    for(i =1 ;i < SIZE; i++)
        s2[i].row = -1;
    
    //fast transpose
    for(i = 1; i <= s1[0].data; i++)
    {
        x = s1[i].col;
        y = p[x];
        
        //check s2[y] is filled or not
        while(s2[y].row != -1)
        {
            y++;
        }
        //s1[i] goes into s2[y]
        s2[y].row = s1[i].col;
        s2[y].col = s1[i].row;
        s2[y].data = s1[i].data;
    }
    //set header row of target sparse matrix
    s2[0].row  = s1[0].col;
    s2[0].col  = s1[0].row;
    s2[0].data = s1[0].data;      
}

int addition(Sparse s3[], Sparse s1[], Sparse s2[])
{
    int i, j, k;
    
    //order match
    if(s1[0].row != s2[0].row || s1[0].col != s2[0].col )
    {
        printf("\n Matrix Order Mismatch, Addition NOT Possible");
        return 0 ; //terminate fn with failure flag
    }
    
    i = j = k = 1;
    while(i <= s1[0].data && j <= s2[0].data)
    {
        if(s1[i].row == s2[j].row)
        {//row match

            if(s1[i].col == s2[j].col)
            {//col match
                s3[k].row = s1[i].row;
                s3[k].col = s1[i].col;
                s3[k].data = s1[i].data + s2[j].data;
                i++;
                j++;
                k++;
            }
            else if(s1[i].col < s2[j].col)
            {//col less
            //copy s1[i] into s3[k]
                s3[k] = s1[i];
                i++;
                k++;
            }
            else if(s1[i].col > s2[j].col)
            {//col greater
             //copy s2[j] into s3[k]
                s3[k] = s2[j];
                j++;
                k++;
            }
        }//row match
        else if(s1[i].row < s2[j].row)
        {//row less
         //copy s1[i] into s3[k]
            s3[k] = s1[i];
            i++;
            k++;
        }
        else if(s1[i].row > s2[j].row)
        {//row greater
        //copy s2[j] into s3[k]
            s3[k] = s2[j];
            j++;
            k++;
        }
    }//while
    
    //for remaining rows of s1
    while(i <= s1[0].data )
    {
        s3[k] = s1[i];
        i++;
        k++;
    }
    
    //for remaining rows of s2
    while(j <= s2[0].data )
    {
        s3[k] = s2[j];
        j++;
        k++;
    }
    
    //header set
    s3[0].row = s1[0].row;
    s3[0].col = s1[0].col;
    s3[0].data = k-1;

    return 1 ; //return success flag    
}

int main()
{
     int flag;
    Sparse s1[SIZE];
    Sparse s2[SIZE];
    Sparse s3[SIZE];
    
    scanSparse(s1);
    dispSparse(s1);
    //transpose(s2, s1);
    //ftranspose(s2, s1);
    scanSparse(s2);
    dispSparse(s2);
    
    flag = addition(s3, s1, s2);
    if(flag == 1)
       dispSparse(s3);
    return 0;
}
