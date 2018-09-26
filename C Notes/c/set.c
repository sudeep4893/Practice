#include <stdio.h>
/*
Set Operations 
 
 */ 

void scanArray(int a[], int size)
{
    int i;
    printf("\n Enter %d numbers ", size);
    for(i =0; i< size; i++)
    {
        scanf("%d", &a[i]);
    }
}

void printArray(int a[], int size)
{
    int i;
    printf("\n Array : ");
    for(i =0; i< size; i++)
    {
        printf(" %d", a[i]);
    }
}

int search(int a[], int size, int val)
{
    int i;
    for(i = 0; i< size; i++)
    {
        if(a[i] == val)
        {
          return i;//index of element where match is found  
        }
    }//for
    return -1; //not found
}//search

void unionSets(int set1[], int size1, int set2[], int size2)
{
    int i, x;

    printf("\n Union : ");
    //all elements of set1
    for(i =0; i< size1; i++)
    {
        printf(" %d", set1[i]);
    }
    
    //elements of set2 not present in set1
    for(i =0; i< size2; i++)
    {
        x = search(set1, size1, set2[i]);
        if(x == -1)
        {//not found
            printf(" %d", set2[i]);
        }
    }//for(
    
}//unionSets


void intersectSets(int set1[], int size1, int set2[], int size2)
{
    int i, x;
    printf("\n Intersect : ");
    
    //Elements of set1 present in set2
    for(i =0; i< size1; i++)
    {
        x = search(set2, size2, set1[i]);
        if(x != -1)
        {//found
            printf(" %d", set1[i]);
        }
    }//for
}//intersectSets

void minusSets(int set1[], int size1, int set2[], int size2)
{
    int i, x;
    printf("\n Set1 minus Set2 : ");
    
    //Elements of set1 not present in set2
    for(i =0; i< size1; i++)
    {
        x = search(set2, size2, set1[i]);
        if(x == -1)
        {//not found
            printf(" %d", set1[i]);
        }
    }//for
}//minusSets

int main() 
{
    int set1[6], set2[6];//int arrays
    
    scanArray(set1, 6);
    scanArray(set2, 6);
    
    printArray(set1, 6);
    printArray(set2, 6);
    
    unionSets(set1, 6, set2, 6);
    intersectSets(set1, 6, set2, 6);
    minusSets(set1, 6, set2, 6);
    
    return 0;
}