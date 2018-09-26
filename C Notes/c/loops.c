#include<stdio.h>
/*
Loops
are mechanisms used to repeat a set of 
statements. 
A Loop is always governed using a condition.
 
A loop continues to repeat its set of statements 
as long as the governing condition remains true. 
 
C supports 3 types of loops 
1) while 
2) for 
3) do while 
 
while and for loop can be use interchangably
because they test the condition before execution
of set of statements.  

Hence while and for ensures 0-many cycles
of set of statements.  
     
do while tests the condition after execution
of set of statements.   
 
Hence do while ensures 1-many cycles
of set of statements.   
 
------------------------------------------ 
 Whenever we write a loop we must analyze
 following regarding loop controlling variable.
 
 1) start value (called as initialization)
 2) stop value  (called as condition)
 3) change in value ( called as reinitialization)
 
----------------------------------------------- 
 while loop
 
 initialization (assignment of start value to loop controlling variable)
 while( condition ) (test of stop value of loop controlling variable)
 {  
        statements to repeat
        reinitialization (change in the value of loop controlling variable)
 }
 
 */
//prg to generate multiplication table
int main()
{
    int i, ans;
    int x;
    printf("\n enter a number ");
    scanf("%d", &x);
    
    i = 1;
    while(i <=10)
    {
        ans = x *i;
        printf("\n %d * %d = %d ", x, i, ans);
        i++;
    }
    
    return 0;
}