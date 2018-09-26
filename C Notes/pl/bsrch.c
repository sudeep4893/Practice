#include<stdio.h>

void dispArr(int arr[], int s)
{
	int i;
	printf("\n");
	for(i = 0;i< s; i++ )
	{
		printf(" %d", arr[i]);
	}
}


int bSearch(int arr[], int s, int val)
{
   int x, y,m;

   x = 0; //lower boundary
   y = s -1;//upper boundary

   while(x <=y)
   {
     m = (x+y)/2;
     if(val == arr[m])
     {//found
        return m;//indx where val was found
     }
     else if(val < arr[m])
     {//srch on lhs
         y = m-1;
     }
    else if(val > arr[m])
    {//srch on rhs
        x = m+1;
    }
  }//while
  return -1 ;//not found
}

int bSearchR(int arr[], int x, int y, int val)
{
     int m;
     if(x <=y)
     {
	m = (x+y)/2;
	if(val == arr[m])
	{
  	   return m; //indx
	}
	else if(val < arr[m])
	{//search on lhs
	    return bSearchR(arr,x,m-1,val);
	}
	else if(val > arr[m])
	{//search on rhs
	    return bSearchR(arr,m+1,y,val);
	}
     }
         return -1; //not found
}

int main()
{
   int arr[10]= {1,4,7,10,11,12,15,18,20,21};
   int n, indx;

   //scanArr(arr,10);
   //sortArr(arr,10)
   dispArr(arr, 10);
   printf("\n enter val to search ");
   scanf("%d", &n);
   //indx = bSearch(arr, 10, n);
   indx = bSearchR(arr, 0,9, n);

   if(indx != -1)
   {
	printf("\n %d found at indx %d ", n, indx);
   }
   else
   {
	printf("\n %d not found ", n);
   }
   return 0;
}
