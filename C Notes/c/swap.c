#include<stdio.h>

//prg to swap (interchange the values) 2 numbers

int main()
{
    int a,b; 
    int x;
    
    a = 10;
    b = 20;
    
    printf("\n %d %d",a,b);
    
    //swap1
    //x = a;
    //a = b;
    //b = x;
    
    //swap2 (good for numbers only)
    a = a + b; 
    b = a - b;
    a = a - b;
    
    printf("\n %d %d",a,b);
    return 0;
}
