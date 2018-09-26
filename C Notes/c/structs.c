#include <stdio.h>

/*
struct 
 
A struct is a group of 
variables/arrays/pointers/... 
of different data types. 
 
C treats a struct definition as a secondary
datatype.
 
We know that a datatype is used by 
creating its variables/arrays/pointers/... 

Example to use : int  
We create its variable : int i;
and then we use it : i = 10;
  
Similarly to use the data type defined by
a struct, we create its variables/arrays/... 
 
Example 
Book = (title, author, publication, notes, price)
Now to use Book we can create 
 Its variables : Book b, b1;
 Its array  : Book arr[3];
 Its pointers : Book * bp;  
 
Further apply application logic on real 
life data types and achieve real life
solutions. 
------------------------------------------ 
        More about struct

* syntax 
 struct <structName>
 {
   var1;   
   var2;  
   array;
   pointer;  
 };
 
 * struct members
   The elements that form a struct are 
   called as "members" of the struct.
   
 * To create struct variables
   datatype  varName;
   struct Demo d;
 
 * Memory allocation and size
   As a struct variable is defined a composite
   block of memory is allocated.
   It contains memory for all the members of
   the struct.
   (see the diagram).
 
   Hence said size of a struct variable is 
   equal to the sum of sizes of its members.
 
 * Operations on struct variables
   
   C supports only 3 operations on struct variables 
 
   1) Member access operator : . 
   It is used to access members of a struct 
   using a struct variable.
   syntax
      structVar.structMember 
   example :
      struct Demo d; 
      d.a , d.b, ...
   
   2) Assignment : =
   Assignment operator =, can be used to 
   copy data of all the members of RHS struct
   variable into corresponding members of LHS 
   struct variable.
 
   syntax
     structVar2 = structVar1;   
   
   example
   struct Demo d,d1; 
   d.a = 10; 
   ...
 
   d1 = d;
 
   3) Referencing : &
   Referencing operator & can be applied on 
   a struct variable to fetch its address.
   syntax
      structPtr = &structVar;    
  
   (struct pointers can be dereferenced in
    2 ways. For details refer next example.)
 
 REST OF THE OPERATIONS ARE PERFORMED ON
 STRUCT MEMBERS AND NOT ON THE STRUCT VARIABLE. 
 
 EXAMPLE 
 TO SCAN/PROCESS/PRINT A STRUCT VARIABLE
 MEANS TO DO THE SAME ON ITS MEMBERS.
 */

struct Demo
{
    int a;
    float b;
    char c;
};
int main() 
{
    //create a struct variable
    struct Demo d;
    
    //scan it
    printf("\n enter data for d ");
    printf("\n member a ");
    scanf("%d", &d.a);
    printf("\n member b ");
    scanf("%f", &d.b);
    printf("\n member c ");
    fflush(stdin);
    scanf("%c", &d.c);
    
    //display it
    printf("\n d( %d %f %c )", d.a, d.b, d.c);
    return 0;
}
