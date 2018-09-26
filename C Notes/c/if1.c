#include<stdio.h>


//program to compare 2 numbers

int main()
{
/*    
    double f;
    f = 1.6789;
    printf("\n Number test starts");
    if(f == 1.6789)
    {//true
        printf("\n double is a double precision number");
    }
    else
    {//false
        printf("\n float is a single precision number");
    }
    
    printf("\n Number test complete");
    
 */
    float f;
    f = 1.6789;
    printf("\n Number test starts");
    if(f == 1.6789F)
    {//true
        printf("\n var f and 1.6789F both are floats");
    }
    else
    {//false
        printf("\n 1.6789 is a double value");
    }
    
    printf("\n Number test complete");
    return 0;
}
