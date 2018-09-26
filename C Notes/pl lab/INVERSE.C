#include<stdio.h>
#include<conio.h>
#define SIZE 10

void main()
{
	double mat[SIZE][SIZE] , unitmat[SIZE][SIZE]  ;
	int i,j, k, flag, n, temp;
	double x, y;

	clrscr();
	printf("\n enter SIZE of mat \n ");
	scanf("%d",&n );

	for(i =0 ; i<n; i++)
	{
		for(j = 0; j<n; j++)
		{
			printf("\nenter value for mat[%d][%d] ", i,j );
			scanf("%lf", &mat[i][j]);
		}
	}

	//init the unit matrix
	for(i =0 ; i<n; i++)
	{
		for(j =0 ; j < n; j++)
		{
			if(i == j)
				unitmat[i][j] = 1;
			else
				unitmat[i][j] = 0;
		}
	}

	for(i =0 ; i<n; i++)
	{
		printf("\n");
		for(j =0 ; j<n; j++)
		{
			printf("\t %4.2lf", mat[i][j]);
		}
	}

	//inverse

	for(i= 0; i<n; i++)
	{
		x = mat[i][i];//diagonal element

		//make row i col i = 1
		for(k =0 ; k<n; k++)
		{
			mat[i][k] = mat[i][k] / x;
			unitmat[i][k] = unitmat[i][k] / x;
		}

		//make cells other than diagonal = 0
		for(j =0 ; j<	n; j++)
		{
			if(i != j )
			{
				x = mat[j][i];

				for(k = 0; k<n; k++)
				{
					mat[j][k] = mat[j][k] - mat[i][k] * x;
					unitmat[j][k] = unitmat[j][k] -  unitmat[i][k] * x;
				}
			}
		}
	}

	printf("\n\n");

	for(i =0 ; i<n; i++)
	{
		printf("\n");
		for(j =0 ; j<n; j++)
		{
			printf("\t %4.2lf", mat[i][j]);
		}
	}

	printf("\n\n");
	for(i =0 ; i<n; i++)
	{
		printf("\n");
		for(j =0 ; j<n; j++)
		{
			printf("\t %4.2lf", unitmat[i][j]);
		}
	}
}