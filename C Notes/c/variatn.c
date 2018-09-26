#include<stdio.h>

/*
 variations
  
 */
int main()
{
    int i;

    /*
    i = 2147483647;//max val for int on 32 bit platform
    printf("\n %d", i);
    i++;//val changes to smallest possible int val
    printf("\n %d", i);//min val for int on 32 bit platform
    */
    
/*
    i = 1;
    //if(i--)//true
    if(--i)//false
    {
        printf("\nTRUE but i is %d", i);
    }
    else
    {
        printf("\nFALSE and i is %d", i);
    }
 */ 
    /*    
    i= 1;
    while(i++ <=10)//2 to 11
    {
        printf("\n %d", i);
    }
    printf("\n --------%d--------", i);//12
*/
/*    
    i= 1;
    while(++i <=10)//2 to 10
    {
        printf("\n %d", i);
    }
    printf("\n --------%d--------", i);//11
*/
/*
    i = 10;
    while(i--)//9,8,7,...1,0
    {
        printf("\n %d", i);
    }
    printf("\n ..........%d..........", i);//-1
*/
/*    
    i = 0;
    while(++i)//1,2,3,...2147483647,-2147483648,-2147483647,...,-1
    {
        printf("%d ", i);
    }
    printf("\n ..........%d..........", i);//0
 */
  /*
    for(i = 1; i< 10 ; i++);//due to ; it becomes a body less loop (do nothing loop) which cycles from 1 to 9 and stops as i becomes 10
    {//this is not loop body, it is after the loop
        printf("\n %d", i);//will print 10
    }
  */ 
  /*  
    i = 1;
    while(i++ < 10);//due to ; it becomes a body less loop (do nothing loop) which cycles from 1 to 9 and stops as i becomes 10
    {//this a block of code outside the loop
        printf("\n %d", i);//will print 11
    }
   */
    
    //i = 10;
    //printf("\n %d %d %d", i++, --i, i++);//10  10  10
    //and here i is 11
    
    i = 1;
    printf("\n %d %d %d", ++i, i--, ++i);
    return 0;
}