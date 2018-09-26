#include<stdio.h>
#include<conio.h>

void main()
{
	char str1[10]= "Hello";
	char str2[10]= "PL";
	int x = 20;
	char y = 'q';

	char all[30];

	clrscr();
	//printf("%s%d%s%c",str1,x,str2,y);
	sprintf(all,"%s%d%s%c",str1,x,str2,y);

	printf("\n all : %s", all);

}