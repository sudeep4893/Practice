#include<stdio.h>
#include<conio.h>
#include<string.h>
#define SIZE 20

struct MobileUser
{
	char mno[11];
	char name[20];
	int billAmt;
};
typedef struct MobileUser MobileUser;


void add(MobileUser arr[], int indx)
{
	printf("\n enter mno ");
	fflush(stdin);
	scanf("%s", arr[indx].mno);

	printf("\n enter name ");
	fflush(stdin);
	gets(arr[indx].name);

	printf("\n enter billAmt ");
	scanf("%d", &arr[indx].billAmt);

}

void selection(MobileUser arr[], int s)
{//namewise ascending
	int i, j, x, mi;
	MobileUser temp;

	for(i =0; i< s-1; i++)
	{
		mi = i	;
		for(j= i+1; j<s; j++)
		{
			x = strcmp(arr[j].name, arr[mi].name);
			if( x < 0 )
			{//arr[j] is smaller
				mi = j;
			}
		}//for(j
		if(mi != i)
		{
			temp = arr[i];
			arr[i] = arr[mi];
			arr[mi] = temp;
		}
	}//for(i

}

void insertion(MobileUser arr[], int s)
{//descending mno wise

	int i,j;
	MobileUser temp;
	for(i = 1; i< s; i++)
	{
		temp = arr[i];

		for(j=i-1; j>=0 && strcmp(arr[j].mno , temp.mno) <0 ; j--)
		{
			arr[j+1] = arr[j];

		}
		//insertion
		arr[j+1] = temp;

	}
}

void dispDMno(MobileUser arr[], int s)
{
	int i;
	insertion(arr, s);
	for(i =0; i< s; i++)
	{
		printf("\n %s %s %d", arr[i].mno, arr[i].name, arr[i].billAmt);
	}
}

void dispAName(MobileUser arr[], int s)
{
	int i;
	selection(arr, s);
	for(i =0; i< s; i++)
	{
		printf("\n %s %s %d", arr[i].mno, arr[i].name, arr[i].billAmt);
	}
}

void disp(MobileUser arr[], int s)
{
	int i;
	printf("\n ");
	for(i =0; i< s; i++)
	{
		printf("\n %s %s %d", arr[i].mno, arr[i].name, arr[i].billAmt);
	}
}

int bSearchR(MobileUser arr[], int x, int y, char mno[])
{
//arr is sorted in descending
	int m,r;

	if(x <=y)
	{
		m = (x+y)/2;
		r =strcmp(mno ,arr[m].mno);
		if(r == 0)
		{
			return m; //indx
		}
		else if(r > 0)
		{//search on lhs
			return bSearchR(arr,x,m-1,mno);
		}
		else if(r < 0)
		{//search on rhs
			return bSearchR(arr,m+1,y,mno);
		}
	}
	return -1; //not found

}


void selection1(MobileUser arr[], int s)
{//mno ascending
	int i, j, x, mi, cnt;
	MobileUser temp;

	cnt = 0;
	printf("\n passes for selection ");
	for(i =0; i< s-1; i++)
	{
		mi = i	;
		for(j= i+1; j<s; j++)
		{
			x = strcmp(arr[j].mno, arr[mi].mno);
			if( x < 0 )
			{
				mi = j;//selection
				cnt++;
			}
		}//for(j

		if(mi != i)
		{//swap
			temp = arr[i];
			arr[i] = arr[mi];
			arr[mi] = temp;
		}
		disp(arr, s);//pass
	}//for(i

	printf("\n tot selections : %d ", cnt);
}

void insertion1(MobileUser arr[], int s)
{//ascending mnowise

	int i,j, cnt;
	MobileUser temp;
	cnt = 0;
	printf("\n passes for insertion ");
	for(i = 1; i< s; i++)
	{
		temp = arr[i];

		for(j=i-1; j>=0 && strcmp(arr[j].mno , temp.mno) >0 ; j--)
		{
			arr[j+1] = arr[j];
			cnt++;//shifts
		}
		//insertion
		arr[j+1] = temp;

		disp(arr, s);//pass
	}//for
	printf("\n tot shifts : %d ", cnt);
}


void main()
{
	int ch, n,x, i;
	char mno[20];
	MobileUser allUsers[SIZE];
	MobileUser arr[SIZE];

	clrscr();
	n =0 ;

	do
	{
		printf("\n 1. add mobile user");
		printf("\n 2. disp mnowise ");
		printf("\n 3. disp namewise");
		printf("\n 4. search mnowise ");
		printf("\n 5. compare efficiency ");
		printf("\n 6. exit");
		printf("\n enter choice ");
		scanf("%d", &ch);


		switch(ch)
		{
			case 1: //add
				if(n < SIZE)
				{
					add(allUsers, n);
					n++;
				}
				else
				{
					printf("\n Arr is full");
				}
				break;
			case 2:
				dispDMno(allUsers, n);
				break;
			case 3:
				dispAName(allUsers, n);
				break;
			case 4:
				insertion(allUsers, n);
				printf("\n enter mno to search ");
				fflush(stdin);
				scanf("%s", mno);
				x = bSearchR(allUsers, 0,n-1, mno);
				if(x == -1)
				{
					printf("\n %s not found ", mno);
				}
				else
				{
					printf("\n %s %s %d", allUsers[x].mno, allUsers[x].name, allUsers[x].billAmt);
				}
				break;
			case 5:
				//copy allUsers in some arr
				for(i =0; i< n; i++)
					arr[i] = allUsers[i];
				insertion1(arr, n);;

				for(i =0; i< n; i++)
					arr[i] = allUsers[i];
				selection1(arr, n);

				break;
		}
	}while(ch != 6);

}