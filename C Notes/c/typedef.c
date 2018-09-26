#include <stdio.h>

/*
typedef statement 
Is used to assign an alternate name to
an existing datatype. 
 
syntax 
 typedef dataType alternateName;
 
example  
 typedef int integer; 

Hereafter integer will be an alternte name 
for int datatype. 
And both can be used interchangeably. 
 */

typedef int integer;
int main() 
{
    int i;
    integer j;
    
    i = 10;
    j = i;
    
    printf("\n i : %d ", i);
    printf("\n j : %d ", j);
    
    return 0;
}
