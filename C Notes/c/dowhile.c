#include<stdio.h>

/*
 do while loop allows repetition of
 c statement 1 to many times.
  
 syntax
 
 initialization 
 do
 {
    c statements
    reinitialization 
 }while(condition);
 
 */
int main()
{
    int i;
    
    //i = 1; //initialization
    i = 11;
    do
    {
        printf("\n %d", i);
        i++;//reinitialization
    }while(i<=10);//condition
        
    return 0;
}