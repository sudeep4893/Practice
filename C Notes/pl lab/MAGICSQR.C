#include<stdio.h>
#include<conio.h>

void main()
{
	int mat[3][3] = {{1,1,1}, {1,1,1}, {1,1,1}};
	int arr[8];// 2n + 2
	int i, j, sum, x, flag;

	clrscr();

	for(i = 0; i<8; i++)
		arr[i] = 0;

	x = 0;
	//add the rows
	for(i =0; i< 3; i++)
	{
		sum = 0;
		for(j =0; j< 3; j++)
		{
			sum = sum + mat[i][j];
		}
		arr[x] = sum;//sum of row i
		x++;
	}

	//add the cols
	for(i =0; i< 3; i++)
	{
		sum = 0;
		for(j =0; j< 3; j++)
		{
			sum = sum + mat[j][i];
		}
		arr[x] = sum;//sum of col i
		x++;
	}

	//add  diagonal 1
	sum = 0;
	for(i = 0; i< 3; i++)
	{
		sum = sum + mat[i][i];
	}
	arr[x] = sum;
	x++;

	//add  diagonal 2
	sum = 0;
	for(i = 0; i< 3; i++)
	{
		sum = sum + mat[i][2-i];
	}
	arr[x] = sum;
	x++;

	//additions done
	//compare all additions for equality

	flag = 1;
	for(i =1; i< x; i++)
	{
		if(arr[0] != arr[i])
		{
			flag = 0;
			break;
		}
	}

	if(flag == 1)
		printf("\n magic sqr");
	else
		printf("\n not a magic sqr");

}