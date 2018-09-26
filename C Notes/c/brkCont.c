#include<stdio.h>

/*
 Loop controlling statements
 
 * break : used to terminate(stop) the current loop
 * continue : used to skip current loop cycle and resume with next loop cycle
 
Always enclose break/continue in if statement.
 
 */
int main()
{
    int i;
/*    
    for(i =1; i<=10; i++)
    {
        printf("\n %d ", i);
        if(i == 5)
        {
            break;//terminate the loop
        }
    }//for
*/
/*    
    i = 1;
    while(i <=10)
    {
        printf("\n %d ", i);
        if(i == 5)
        {
            break;//terminate the loop
        }
        i++;
    }//while   
    
*/
/*    
    for(i = 1; i<=10; i++)
    {
        if(i == 5)
        {
            continue; //skip this cycle, resume with next cycle
        }
        printf("\n %d ", i);
    }//for
*/
/*    
    i = 1;
    while(i<=10)
    {
        if(i == 5)
        {
            i++; //to avoid skip of reinit
            continue; //skip this cycle, resume with next cycle
        }
        printf("\n %d ", i);
        i++;
    }//while    
*/
/*    
    i = 1;
    do
    {
        if(i == 5)
        {
            break;//to stop the loop
        }
        printf(" \n %d", i);
        i++;
    }while(i<=10);
  */  
    
    i = 1;
    do
    {
        if(i == 5)
        {
            i++;//reinit again here
            continue;//to skip this loop cycle
        }
        printf(" \n %d", i);
        i++;
    }while(i<=10);
    return 0;
}