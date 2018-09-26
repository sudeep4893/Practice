#include<stdio.h>
/*
 Introduction to scanf
 
scanf is a ready made function
It comes from the header file stdio.h
It is used to fetch data from standard 
input stream (stdin) that connects 
keyboard and CPU. Further the same data
is transferred into our program variables. 
 
scanf is an input blocking method. 
 
scanf blocks for keyboard input only when  
stdin is empty.
In case that stdin already has data then  
scanf will fetch the same and continue, 
without waiting for keyboard input.
 
In order to use scanf we must provide
2 things 
* Data type of variable (using format character)  
* Variable 
 
 
 
 */

int main()
{
    int i, j;
    printf("Enter a Number ");
    scanf("%i", &i);
    
    printf("Enter another Number ");
    
    fflush(stdin);//clear the stdin
    scanf("%d", &j);
    
    printf("\n i : %d ", i);
    printf("\n j : %d ", j);
    return 0;
}

