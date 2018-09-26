#include<stdio.h>

/*
Study of unit increment operator : ++

++ is a unary operator (it acts on a single operand).
It increments the value of its operand by one.

say ++ acts on var i, which is 10.
then after ++ i increments and becomes 11.

++ can be applied as 
*  a prefix operator : ++i
*  a postfix operator :  i++

In both cases its action is same.
i.e. It increments the operand by one.

But there is an important difference in both usages.
It is difference in execution priority.

pre increment usage (++i) has highest priority
post increment usage (i++) has lowest priority
------------------------------------------------
 Note that i++ internally expands as 
 i = i+1, hence ++ can act on variables only
 and not on constants.
 i.e. 10++ is illegal 
 because it will expand as 10 = 10 +1
------------------------------------------------
 C also provides unit decrement operator --
 with same conceptual features as ++.
 */

int main()
{
    int i, j; 
    i = 10;
    //printf("\n i : %d ", i);
    //i++;//postfix
    //++i;//prefix
    
    //j = i++ * 4;
    //3 operations : = , ++ , *
    //sequence of execution priority wise
    //1) * ( i * 4 )
    //2) = ( j = answer of multiplication)  
    //3) ++ ( i++ )
    
    //j = ++i * 4;
    //3 operations : = , ++ , *
    //sequence of execution priority wise
    
    //1) ++ ( ++i )
    //2) * ( i * 4 )
    //3) = ( j = answer of multiplication)  
    
    j = i++ * ++i;
    
    printf("\n i : %d ", i);//11, 11, 12
    printf("\n j : %d ", j);//40, 44, 121
    return 0;
}
