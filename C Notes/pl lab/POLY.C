#include<stdio.h>
#include<conio.h>
#include<math.h>
#define MAX 50

//polynomial operations
//using struct array

struct polynomial
{
	int c,e;
};
typedef struct polynomial polynomial;

void sort(polynomial p[], int s)
{
	int i, j;
	polynomial temp;

	//bubble, descending sort
	for(i = s-1; i > 0; i--)
	{
		for(j =0; j< i; j++)
		{
			if(p[j].e < p[j+1].e)
			{
				temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
			}
		}
	}
}

int removeDuplicates(polynomial p[], int s)
{//poly size may change
 //poly should be sorted

	int i, j, k;

	for(i =0; i< s-1; i++)
	{
		if(p[i].e == p[i+1].e)
		{//duplicate found
			//merge p[i+1] into p[i]

			p[i].c = p[i].c + p[i+1].c;

			//---------------------
			//rem p[i+1] (duplicate)
			//shift method
			for(j = i+1; j< s-1; j++)
			{
				p[j] = p[j+1];
			}
			s--;//size reduces due to shift
			//-----------------------

			//due to merge p[i].c may become 0

			if(p[i].c == 0)
			{//rem p[i] ( 0 coeff)

				//shift method
				for(j =i; j< s-1; j++)
				{
					p[j] = p[j+1];
				}
				s--;//size reduces due to shift
			}
			i--;//as elements have reduced, so dont incr i
		}

	}//for

	return s; //new size
}

int scanPoly(polynomial p[])
{
	char ch;
	int i =0;
	do
	{
		printf("\n enter coeff ");
		scanf("%d", &p[i].c);

		if(p[i].c == 0)
		{
			printf("\n 0 coeff not allowed ");
			continue; //re cycle loop
		}

		printf("\n enter expo ");
		scanf("%d", &p[i].e);

		printf("\n add more terms ? ");
		fflush(stdin);
		scanf("%c", &ch);

		i++;
	}while(ch == 'y');

	sort(p, i); //to arrange expression exponentwise
	i = removeDuplicates(p,i);
	return i;//size of poly
}


void dispPoly(polynomial p[], int s)
{
	int i;
	printf("\n");
	for(i =0; i< s; i++)
	{
		if(p[i].c > 0 && i >0  )
		{
			printf(" + ");
		}

		printf(" %dx^%d", p[i].c, p[i].e);
	}
}

int multiply(polynomial p1[], int s1,polynomial p2[], int s2, polynomial p3[] )
{//returns size of p3

	int i, j, k;

	k =0;
	for(i = 0; i< s1; i++)
	{
		for(j =0; j < s2; j++)
		{
			p3[k].c = p1[i].c * p2[j].c;
			p3[k].e = p1[i].e + p2[j].e;

			k++;
		}
	}
	sort(p3, k);
	k =removeDuplicates(p3, k);
	return k;
}

int add(polynomial p1[] ,int s1, polynomial p2[], int s2, polynomial p3[])
{//return the size of p3
	int i, j, k;
	i = j = k = 0;

	while(i < s1 && j < s2)
	{
		if(p1[i].e == p2[j].e)
		{
			if(p1[i].c + p2[j].c != 0 )
			{
				p3[k].c = p1[i].c + p2[j].c;
				p3[k].e = p1[i].e;
				k++;
			}

			i++;
			j++;
		}
		else if(p1[i].e > p2[j].e)
		{
			p3[k] = p1[i];
			i++;
			k++;
		}
		else if(p1[i].e < p2[j].e)
		{
			p3[k] = p2[j];
			j++;
			k++;
		}
	}//while

	//for remaining elements of p1
	while(i < s1)
	{
		p3[k] = p1[i];
		i++;
		k++;
	}

	//for remaining elements of p2
	while(j < s2)
	{
		p3[k] = p2[j];
		j++;
		k++;
	}
	return k;
}

void eval(polynomial p[], int s)
{
	int i;
	int ans= 0;
	int x;

	printf("\n enter val of x ");
	scanf("%d", &x);

	for(i =0; i< s;i++)
	{
		ans=ans + p[i].c * pow(x,p[i].e );
	}

	printf("\n ans : %d ", ans);

}

void main()
{
	polynomial p1[MAX], p2[MAX], p3[MAX];
	int s1,s2,s3;
	int ch;

	clrscr();
	do
	{
		printf("\n 1. set poly1 ");
		printf("\n 2. set poly2 ");
		printf("\n 3. add poly1 and poly2 ");
		printf("\n 4. mul poly1 and poly2 ");
		printf("\n 5. exit ");
		printf("\n enter choice ");
		scanf("%d", &ch);

		switch(ch)
		{
			case 1:
				printf("\n enter poly1 ");
				s1 = scanPoly(p1);
				dispPoly(p1, s1);
				break;
			case 2:
				printf("\n enter poly2 ");
				s2 = scanPoly(p2);
				dispPoly(p2, s2);
				break;
			case 3:
				s3 = add(p1, s1,p2,s2,p3);
				dispPoly(p1, s1);
				dispPoly(p2, s2);
				dispPoly(p3, s3);
				eval(p3,s3);
				break;

			case 4:
				s3 = multiply(p1, s1,p2,s2,p3);
				dispPoly(p1, s1);
				dispPoly(p2, s2);
				dispPoly(p3, s3);
				eval(p3,s3);
				break;
		}
	}while(ch != 5);
}