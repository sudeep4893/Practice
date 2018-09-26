#include<stdio.h>
#define SIZE 10

void scanMat(int mat[][SIZE], int r, int c)
{
    int i, j;
    printf("\n enter data for ");
    for(i =0; i< r; i++)
    {
        for(j =0; j< c; j++)
        {
            printf("\n mat[%d][%d] ", i, j);
            scanf("%d", &mat[i][j]);
            //scanf("%d", (*(mat+i)+j) );
        }
    }
}

void dispMat(int (*p)[SIZE] , int r, int c )
{
    int i, j;
    printf("\n");
    for(i=0; i< r; i++)
    {
        printf("\n");
        for(j =0; j< c; j++)
        {
            //printf(" %d", p[i][j]);
            printf(" %d", *(*(p+i)+j));
        }
    }
}

//void transpose(int m[SIZE][SIZE], int r, int c)
void transpose(int (*p)[SIZE], int r, int c)
{
    int i, j, temp;
    for(i =0; i< r; i++)
    {
        for(j =i+1; j< c; j++)
        {
            //temp = m[i][j];
            //m[i][j] = m[j][i];
            //m[j][i] = temp;
	temp = *(*(p+i)+j);
               *(*(p+i)+j) = *(*(p+j)+i) ;
	*(*(p+j)+i)  = temp;
        }
    }
}

int add(int m1[SIZE][SIZE], int r1,int c1, int m2[SIZE][SIZE], int r2, int c2, int m3[SIZE][SIZE])
{
    int i, j;
    if(r1 != r2 || c1 != c2)
    {
        printf("\n Matrix Order Mismatch ");
        return 0;//false
    }

    for(i =0; i< r1; i++)
    {
        for(j =0; j< c1; j++)
        {
            //m3[i][j] = m1[i][j] + m2[i][j];
            *(*(m3+i)+j) = *(*(m1+i)+j) + *(*(m2+i)+j);
        }
    }

    return 1;
}


int mul(int m1[SIZE][SIZE], int r1,int c1, int m2[SIZE][SIZE], int r2, int c2, int m3[SIZE][SIZE])
{
    int i, j, k, sum;
    if(c1 != r2)
    {
        printf("\n Matrix Order Mismatch ");
        return 0;//false
    }

    for(i =0 ; i<r1; i++)
    {
        for(j =0;j< c2; j++)
        {
            sum = 0;
            for(k=0; k< c1; k++)
            {
                sum=sum + m1[i][k]*m2[k][j];
            }
            m3[i][j] = sum;
        }
    }   
    return 1;
}

void sdlPnt(int mat[SIZE][SIZE], int r, int c)
{
    int i,j,m;
    int arr1[SIZE], arr2[SIZE];
    int maxArr1, minArr2;

    //find min of rows

    for(i =0; i< r; i++)
    {
        m = 0;
        for(j = 1; j< c; j++)
        {
            if(mat[i][j] < mat[i][m])
            {
                m = j;
            }
        }
        //mat[i][m] represnts min val of row i
        arr1[i] = mat[i][m];
    }

    //find max of cols
    for(i =0; i< c; i++)
    {
        m = 0;
        for(j = 1; j< r; j++)
        {
            if(mat[j][i] > mat[m][i])
            {
                m = j;
            }
        }
        //mat[m][i] represnts max val of col i
        arr2[i] = mat[m][i];
    }

    //now arr1 has min of rows
    //arr2 has max of cols

    //find max of arr1
    //and min of arr2

    m =0;
    for(i =1; i<r; i++)
    {
        if(arr1[i] > arr1[m])
        {
            m = i;
        }
    }
    maxArr1 = arr1[m];

    m =0;
    for(i =1; i<c; i++)
    {
        if(arr2[i] < arr2[m])
        {
            m = i;
        }
    }
    minArr2 = arr2[m];

    if(maxArr1 == minArr2)
    {
        printf("\n Saddle Point Exists at value %d ", maxArr1);
    }
    else
    {
        printf("\n Saddle point doesnt exist ");
    }
}

int main()
{
    int m1[SIZE][SIZE];
    int m2[SIZE][SIZE];
    int m3[SIZE][SIZE];
    int r1,c1,r2,c2,r3,c3;
    int ch, temp;

    do
    {
    printf("\n 1. set mat1 ");
    printf("\n 2. set mat2 ");
    printf("\n 3. transpose mat1 ");
    printf("\n 4. chk for saddle point in mat1 ");
    printf("\n 5. add matrices ");
    printf("\n 6. mul matrices ");
    printf("\n 7. exit ");
    printf("\n enter choice ");
    scanf("%d", &ch);

    switch(ch)
    {
        case 1:
            printf("\n enter order for mat1 ");
            scanf("%d%d", &r1, &c1);
            scanMat(m1, r1,c1);
            dispMat(m1,r1,c1);
            break;
        case 2:
            printf("\n enter order for mat2 ");
            scanf("%d%d", &r2, &c2);
            scanMat(m2, r2,c2);
            dispMat(m2,r2,c2);
            break;
        case 3:
            dispMat(m1, r1, c1);
            transpose(m1, r1, c1);
            temp = r1;
            r1 = c1;
            c1 = temp;
            dispMat(m1, r1,c1);

            break;
        case 4:
            dispMat(m1,r1,c1);
            sdlPnt(m1, r1,c1);
            break;
        case 5:

            temp =add(m1, r1,c1, m2, r2,c2, m3);
            if(temp == 1)
            {
                r3 = r1;
                c3 = c1;

                dispMat(m1, r1,c1);
                dispMat(m2,r2,c2);
                dispMat(m3,r3,c3);
            }
            break;
        case 6:
            temp =mul(m1, r1,c1, m2, r2,c2, m3);
            if(temp == 1)
            {
                r3 = r1;
                c3 = c2;

                dispMat(m1, r1,c1);
                dispMat(m2,r2,c2);
                dispMat(m3,r3,c3);
            }

            break;
        }//switch
    }while(ch != 7);
    return 0;
}//main
