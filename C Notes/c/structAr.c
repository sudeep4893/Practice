#include<stdio.h>
/*
  struct array

C allows declaration of struct arrays in the
way as arrays of primitive data types.
 
syntax 
 dataType arrayName[arraySize];
example 
 struct Demo arr[3];
 
(see the diagram) 
 */

struct Demo
{
    int a;
    float b;
    char c;
};
typedef struct Demo Demo;

int main()
{
    Demo arr[3];//declares an array of 3 Demo elements
    int i; //for loop /array index
    //float temp; //for tc 3.0 users
    
    printf("\n enter data for 3 Demo objects ");
    for(i =0 ; i< 3; i++)
    {
        printf("\n arr[%d].a ", i);
        scanf("%d", &arr[i].a);

        printf("\n arr[%d].b ", i);
        scanf("%f", &arr[i].b);
        //scanf("%f", &temp); //TC 3.0 bug fix
        //arr[i].b = temp;
        
        printf("\n arr[%d].c ", i);
        fflush(stdin);
        scanf("%c", &arr[i].c);
    }//for
    
    //disp struct array
    for(i =0 ; i< 3; i++)
    {
        printf("\n arr[%d] : ( %d %f %c ) ", i, arr[i].a, arr[i].b, arr[i].c);
    }
    
    return 0;
}