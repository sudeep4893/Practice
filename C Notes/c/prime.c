#include<stdio.h>

/*
 program to check whether a number is a 
 prime number or not 
 */
int main()
{
    int n, i;
    int x;
    printf("\n enter a number ");
    scanf("%d", &n);
    
    //assign any value of choice to x
    x = 1;
    
    //look for factors
    //if found then number is not prime
    //otherwise it is prime
    for(i = 2; i<= n/2; i++)
    {
        if(n % i == 0)
        {
            x = 0; //change to any other value of choice
            break;//terminate the loop
        }
    }//for, runs from 2 to half of the number

    if(x == 1)
        printf("\n %d is prime", n);
    else
        printf("\n %d is not prime ", n);

    return 0;
}