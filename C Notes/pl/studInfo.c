#include<stdio.h>
#define SIZE 10

/*
Accept student information 
(e.g. RollNo, Name, Percentage etc.).

a. Display the data in descending order of Percentage (Bubble Sort)
b. Display data for RollNo specified by user (Linear Search)
c. Display the number of passes and comparisons for different test cases (Worst, Average, Best case).

 
 */

struct Student
{
    int rno;
    char name[20];
    float per;
};
typedef struct Student Student;

void addStudent(Student arr[], int indx)
{
    float temp;
    
    printf("\n Enter rno ");
    scanf("%d", &arr[indx].rno);
    printf("\n Enter name ");
    scanf("%19s", &arr[indx].name);
    printf("\n Enter per ");
    //scanf("%f", &arr[indx].per);
    
    //TC BUG FIX
    scanf("%f", &temp); 
    arr[indx].per= temp;
}

void bsort(Student arr[], int s)
{
    int i, j;
    Student temp;
    
    for(i = s-1; i> 0; i--)
    {
        for(j =0; j< i; j++)
        {
            if(arr[j].per < arr[j+1].per)
            {
                //swap
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        
        }//for(j
    }//for(i

}//bsort

void disp(Student arr[], int s)
{
    int i;
    //to display in descending order of per
    bsort(arr, s);
    //display
    for(i =0 ; i< s; i++)
    {
        printf("\n %d   %s   %f", arr[i].rno, arr[i].name, arr[i].per);
    }
}

int dispRnowise(Student arr[], int s, int rno)
{//linear search
    int i;
    
    for(i =0 ; i< s; i++)
    {
        if(arr[i].rno == rno)
        {
            return i;//indx where found
        }
    }//for
    return -1; //not found
}

void bsortWithPasses(Student arr[], int s)
{
    int i, j, x, y;
    Student temp;
    x= 0;
    int swaps;
    for(i = s-1; i> 0; i--)
    {
        printf("\n Pass%d : ", x);
        for(y =0; y< s; y++)
        {
          printf(" %d ", arr[y].rno);
        }
        swaps = 0;
        
        for(j =0; j< i; j++)
        {
            if(arr[j].rno > arr[j+1].rno)
            {
                swaps++;
                //swap
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        
        }//for(j
        printf("\n Pass%d required %d swaps ",x,  swaps);
        x++;//next pass
        
    }//for(i

}//bsort


int main()
{
    Student arr[SIZE];
    int ch;
    int indx = 0;
    int x, flag;
    
    do
    {
        printf("\n 1. Add student ");
        printf("\n 2. Display data in descending order of Percentage (Bubble Sort) ");
        printf("\n 3. Display data for RollNo specified by user ");
        printf("\n 4. Display the number of passes and comparisons for different test cases (Worst, Average, Best case). ");
        printf("\n 5. Exit ");
        printf("\n Enter Choice ");
        scanf("%d", &ch);
        
        switch(ch)
        {
            case 1:
                if(indx < SIZE)
                {
                    addStudent(arr, indx);
                    indx++;
                }
                else
                    printf("\n TABLE IS FULL");
                break;
                
            case 2:
                disp(arr, indx);
                break;
            case 3:
                printf("\n Enter rno to display ");
                scanf("%d", &x);
                flag = dispRnowise(arr, indx, x);
                if(flag == -1)
                    printf("\n %d not found ", x);
                else
                    printf("\n %d   %s   %f", arr[flag].rno, arr[flag].name, arr[flag].per);

                break;
            case 4:
                bsortWithPasses(arr, indx);
                break;
        }//switch
    }while(ch != 5);
    return 0;
}

