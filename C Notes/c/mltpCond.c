#include<stdio.h>
/*
 It is possible to have multiple conditions
 for decision making.
 Multiple conditions result in multiple
 boolean results.
 In such cases the multiple conditions must
 be merged so that one final boolean result
 is obtained.
 
 C allows merging of multiple conditions
 using 
 * Logical And (&&) 
 * Logical Or (||)
 
 For merging their individual results system
 uses following truth tables. 
 
 Truth Table for Logical And 
 T && T = T 
 T && F = F 
 F && T = F 
 F && F = F 
 
 Truth Table for Logical Or 
 T || T = T 
 T || F = T 
 F || T = T 
 F || F = F 
 
 -----------------------------------------
 In case multiple conditions are merged
 using a combination of Logical And and
 Logical Or.
 Then system first evaluates all the 
 conditions then merging of results is 
 done as follows
 1) Logical And first.
 2) Logical Or next.
 
 */

int main()
{
    int a, b, c;
    a = 10;
    b = 20;
    c = 30;
    
    //   T   ||  F    &&   F 
    if(a > 5 || b < 7 && c == 23)
    {
        printf("\n Logical And is evaluated first");
    }
    else
    {
        printf("\n Logical Or is evaluated first");    
    }
    return 0;
}
