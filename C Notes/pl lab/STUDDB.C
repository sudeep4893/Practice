#include<stdio.h>
#include<conio.h>
#define SIZE 10

struct Student
{
	int rno;
	char name[20];
	float marks;
};
typedef struct Student Student;

void add(Student arr[], int pos)
{
	float temp;
	printf("\n Enter Student data ");
	printf("\n Rno ");
	scanf("%d", &arr[pos].rno);
	printf("\n Name ");
	flushall();
	scanf("%s", arr[pos].name);
	printf("\n Marks ");
	scanf("%f", &temp);
	arr[pos].marks = temp;

}//add

void dispAll(Student arr[], int tot)
{
	int i;

	printf("\n Rno    Name    Marks ");

	for(i =0; i<tot; i++)
	{
		printf("\n %3d %10s %3.2f ", arr[i].rno, arr[i].name, arr[i].marks);
	}
}//dispAll

int search(Student arr[], int tot, int r)
{//linear /sequentail search
	int i;
	for(i =0; i<tot; i++)
	{
		//x = strcmp(arr[i].name, n);
		//if(x == 0)
		//if(arr[i].marks ==m)
		if(arr[i].rno == r)
		{//match
			return i; //index where found
		}
	}//for
	return -1; //not found
}//search


void modify(Student arr[], int tot)
{
	int r, x;
	float temp;

	printf("\n Enter rno of record to modify ");
	scanf("%d", &r);

	//look for the record
	x = search(arr, tot, r);

	if(x != -1)
	{//modify
		printf("\n Existing Data ");
		printf("\n %3d %10s %3.2f ", arr[x].rno, arr[x].name, arr[x].marks);

		printf("\n Enter new data ");

		printf("\n Rno ");
		scanf("%d", &arr[x].rno);
		printf("\n Name ");
		flushall();
		scanf("%s", arr[x].name);
		printf("\n Marks ");
		scanf("%f", &temp);
		arr[x].marks = temp;
	}//if
	else
	{
		printf("\n Record Not found");
	}
}//Modify


int del(Student arr[], int tot)
{
	int r, x, j;

	printf("\n Enter rno of record to delete ");
	scanf("%d", &r);

	//look for the record
	x = search(arr, tot, r);

	if(x != -1)
	{//delete
		printf("\n Deleting ");
		printf("\n %3d %10s %3.2f ", arr[x].rno, arr[x].name, arr[x].marks);

		//slow shift method
		for(j = x +1; j< tot; j++)
		{
			arr[j-1] = arr[j];
		}
		return 1;
	}//if
	else
	{
		printf("\n Record Not found");
		return 0;
	}
}//Modify

void sort(Student arr[], int tot)
{
	Student temp;
	int i, j;
	for(i = tot-1; i >0; i--)
	{
		for(j =0 ; j< i;j++)
		{
			if(arr[j].rno > arr[j+1].rno)
			{ //swap
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}//for(j
	}//for(i
}//sort

void main()
{
	Student sarr[SIZE];
	int ch;
	int indx= 0;
	int r, flag;

	do
	{
		printf("\n 1. Add Student ");
		printf("\n 2. Modify Student ");
		printf("\n 3. Delete Student ");
		printf("\n 4. Search Student ");
		printf("\n 5. Sort Student ");
		printf("\n 6. Display All Students ");
		printf("\n 7. Exit ");
		printf("\n Enter choice ");

		scanf("%d", &ch);

		switch(ch)
		{
			case 1:
				if(indx < SIZE)
				{
					add(sarr,indx);
					indx++;
				}
				else
				{
					printf("\n Student Table Is FULL");
				}
				break;
			case 2:
				modify(sarr, indx);
				break;
			case 3:
				flag = del(sarr, indx);
				if(flag == 1)
				{//deletion success
					indx--;
				}
				break;
			case 4://search
				printf("\n Enter rno to search ");
				scanf("%d", &r);
				flag = search(sarr, indx, r);
				if(flag != -1)
				{
					printf("\n Record found at index %d", flag);
					printf("\n %3d %10s %3.2f ", sarr[flag].rno, sarr[flag].name, sarr[flag].marks);
				}
				else
				{
					printf("\n Record Not Found");
				}
				break;
			case 5:
				sort(sarr, indx);
				break;
			case 6:
				dispAll(sarr, indx);
				break;
		}//switch

	}while(ch != 7);

}