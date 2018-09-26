#include<stdio.h>
/*
Program to accept age and gender and to
give job 
*/

int main()
{
    int age;
    char gender;
    
    printf("\n enter age ");//msg for user
    scanf("%d", &age);//accept data from keyboard

    if(age >= 18 && age <= 40)
    {
        printf("\n M : Male");
        printf("\n F : Female");
        printf("\n enter gender ");
        fflush(stdin);//to clear input stream so that scanf fetches fresh data from keyboard
        scanf("%c", &gender);
        
        if(gender == 'm' || gender == 'M')
        {
            printf("\n Welcome to Air Force");
        }
        else if(gender == 'f' || gender == 'F')
        {
            printf("\n Welcome to Air India");
        }
        else
        {
            printf("\n Invalid Entry");
        }
        
    }
    else
    {
        printf("\n Age not in range 18-40");
    }
    return 0;
}