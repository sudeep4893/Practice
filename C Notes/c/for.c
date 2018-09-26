#include<stdio.h>

/*
for loop 
is used to repeat set of statements multiple 
times as long as the loop governing condition 
remains true. 
 
syntax 
      1     2,5,8  4,7 
for(init; condn; reinit)
{ 
 3,6  
 c statements to repeat
} 
9 out of loop (on false of 8)  
 */
int main()
{
    int i;
    
    for(i = 1; i<=5; i++)
    {
        printf("*");
    }
    return 0;
}