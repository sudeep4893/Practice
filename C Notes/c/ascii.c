#include<stdio.h>
//ALL ASCII VALUES AND THEIR CHAR EQUIVALENTS

int main()
{
    int i;
    printf("\n ALL ASCII VALUES \n");
    for(i =0 ; i<256; i++)
    {
        printf("( %c %d )", i, i);
    }
    return 0;
}