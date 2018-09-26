#include<stdio.h>

//Matrix Copy

int main()
{
    int m1[3][4], m2[3][4];
    int i, j;
    
    for(i =0 ; i< 3; i++)//row representation
    {
        for(j =0 ; j< 4; j++ )//col representation
        {
            printf("\n enter data for m1[%d][%d] ", i, j);
            scanf("%d", &m1[i][j]);
        }
    }
    
    //matrix copy
    for(i =0; i< 3; i++)
    {
        for(j =0; j< 4; j++)
        {
            m2[i][j] = m1[i][j];
        }
    }
    
    printf("\n matrix : \n");
    for(i =0 ; i< 3; i++)
    {
        printf("\n");
        for(j =0 ; j< 4; j++ )
        {
            printf(" %3d", m2[i][j]);
        }
    }
    return 0;
}
