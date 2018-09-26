#include <stdio.h>
/*
 dont swap, a demo of pass by value
 */
void swap(int x, int y)
{
    int temp;
    temp = x;
    x = y;
    y =temp; 
}

int main() 
{
    int x,y;
    x = 10;
    y = 20;
    printf("\n %d %d " , x,y);
    swap(x,y);
    printf("\n %d %d " , x,y);
    return 0;
}