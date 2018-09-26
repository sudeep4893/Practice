#include<stdio.h>
#define SIZE 10

//Database operations using struct array
//(add, modify, delete, search, view and sort)

struct Student
{
    int rno;
    char name[20];
    float per;
};
typedef struct Student Student;

void addStudent(Student dBase[], int pos)
{
    float temp;
    
    printf("\n Enter Rno ");
    scanf("%d", &dBase[pos].rno);
    printf("\n Enter Name ");
    fflush(stdin);
    scanf("%19s", dBase[pos].name);
    printf("\n Enter Percentage ");
    //scanf("%f", & dBase[pos].per);
    //or to fix TC bug
    scanf("%f", &temp);
    dBase[pos].per  = temp;
    
    printf("\n Student Added");
}


void dispAll(Student dBase[], int max)
{
    int i;
    printf("\n Student List \n");
    printf("\n  Rno   Name     Percentage");
    
    for(i =0; i< max; i++)
    {
       printf("\n %4d  %s %5.2f", dBase[i].rno, dBase[i].name, dBase[i].per);
    }
}//dispAll

void sort(Student dBase[], int max)
{//bubble
    int i, j;
    Student temp;
    
    
    //bubble
    for(i = max -1; i > 0 ; i--)
    {
        for(j =0 ; j< i; j++)
        {
            if(dBase[j].rno > dBase[j+1].rno)
            //if(dBase[j].per > dBase[j+1].per)
            //if( strcmp(dBase[j].name, dBase[j+1].name) >0)
            {//swap
                temp = dBase[j];
                dBase[j] = dBase[j+1];
                dBase[j+1] = temp;
            }
        }//for
    }//for
    
    printf("\n Database sorted rnowise");
}//sort

int search(Student dBase[], int max, int rno)
{//seq search
    
    int i;
    for(i =0 ; i< max; i++)
    {
        if(dBase[i].rno == rno)
        {
            return i; //index where rno is found
        }
    }//for
    return -1; //not found
}//search

void modify(Student dBase[], int max)
{
    int rno;
    int pos;
    float temp;
    
    printf("\n enter rno to be modified ");
    scanf("%d", &rno);
    
    pos = search(dBase,max, rno);
    
    if(pos == -1)
    {
        printf("\n Rno %d not found ", rno);
    }
    else
    {//found

        printf("\n %4d  %s %5.2f", dBase[pos].rno, dBase[pos].name, dBase[pos].per);
        printf("\n enter new data ");
        printf("\n Rno ");
        scanf("%d", &dBase[pos].rno);
        printf("\n Name ");
        fflush(stdin);
        scanf("%19s", dBase[pos].name);
        printf("\n Percentage ");
        //scanf("%f", & dBase[pos].per);
        //or to fix TC bug
        scanf("%f", &temp);
        dBase[pos].per  = temp;
    
        printf("\n Student Modified");        
    }
}//modify

int del(Student dBase[], int max)
{
    int rno;
    int pos;
    int j;
    
    printf("\n enter rno to be deleted ");
    scanf("%d", &rno);
    
    pos = search(dBase,max, rno);
    
    if(pos == -1)
    {
        printf("\n Rno %d not found ", rno);
    }
    else
    {//found

        printf("\n %4d  %s %5.2f", dBase[pos].rno, dBase[pos].name, dBase[pos].per);
        for(j = pos; j < max; j++)
        {
            dBase[j] = dBase[j+1];
        }
        
        printf("\n Student Deleted");        
    }
    return pos; //indx where deletion occurred
}//delete

int main()
{
    Student dBase[SIZE];
    int indx;
    int ch, x, flag;
    
    indx = 0;//imp initialization
    do
    {
        printf("\n 1. Add Student ");
        printf("\n 2. Modify Student ");
        printf("\n 3. Delete Student ");
        printf("\n 4. Search Student ");
        printf("\n 5. View Students ");
        printf("\n 6. Sort Students By Rno ");
        printf("\n 7. Exit ");
        printf("\n Enter choice ");
        scanf("%d", &ch);
        
        switch(ch)
        {
            case 1://add
                if(indx < SIZE)
                {
                    addStudent(dBase, indx);
                    indx++;
                }
                else
                    printf("\n TABLE is FULL");
                break;
            case 2://modify
                modify(dBase, indx);
                break;
            case 3://delete
                flag = del(dBase, indx);
                if(flag != -1)//deletion success
                   indx--;
                break;

            case 4://search
                printf("\n enter rno to search ");
                scanf("%d", &x);
                flag = search(dBase, indx, x);
                if(flag == -1)
                    printf("\n %d not found ", x);
                else
                    printf("\n %4d  %s %5.2f", dBase[flag].rno, dBase[flag].name, dBase[flag].per);
                break;
                
            case 5://view all
                dispAll(dBase, indx);
                break;
            case 6://sort
                sort(dBase, indx);
                break;                
        
        }//switch
        
    }while(ch != 7);
    return 0;
}