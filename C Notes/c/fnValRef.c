#include <stdio.h>
/*
Passing parameters to a function 
 * By value
 * By reference
*/ 

//pass by value
void f1(int x)//rcv data of i in formal parameter x
{
    printf("\n f1 starts : %d ", x);
    x++;
    printf("\n f1 ends : %d ", x);
}

void f2(int *p)//rcv address of i in formal parameter pointer p
{
    printf("\n f2 starts : %d ", *p);
    *p = 99;
    printf("\n f2 ends : %d ", *p);
}

int main() 
{
    int i;//declare a variable
    i = 10;//write into i using its name
    printf("\n A. i : %d", i);
    f1(i);//pass data of i as parameter to f1
    printf("\n B. i : %d", i);
    f2(&i);//pass address of i as parameter to f2
    printf("\n C. i : %d", i);
    return 0;
}
