#include<stdio.h>
#include<conio.h>
#include<String.h>

void main()
{
	char str1[20]= "computer";
	char str2[20]= "ute";
	char str3[20]= "pte";

	clrscr();

	if(strstr(str1,str2)!= NULL)
	{
		printf("\n %s is a substring of %s", str2, str1);
	}
	else
	{
		printf("\n %s is a not substring of %s", str2, str1);
	}

	if(strstr(str1,str3)!= NULL)
	{
		printf("\n %s is a substring of %s", str3, str1);
	}
	else
	{
		printf("\n %s is a not substring of %s", str3, str1);
	}

}