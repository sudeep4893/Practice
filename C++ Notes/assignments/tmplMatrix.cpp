/*
Write a program in C++ using function 
template to read two matrices of
different data types such as 
integers and floating point values 
and perform simple arithmetic 
operations on these matrices 
separately and display it.
*/

#include<iostream>
#define SIZE 10

using namespace std;

//template matrix

template <class X> class Matrix
{
	X data[SIZE][SIZE];
	int r, c;
	
	public:
	Matrix();
	void scan();
	void disp();
	Matrix<X> add(Matrix<X> &);
	Matrix<X> mul(Matrix<X> &);
};

template<class X> Matrix<X> ::Matrix()
{
	int i, j;
	r = SIZE;
	c = SIZE;

	for(i =0; i< r; i++)
	{
		for(j= 0 ;j< c; j++)
		{
			data[i][j] = 0;
		}
	}
}

template<class X> void Matrix<X> ::scan()
{
	int i, j;

	cout<<"\n enter row count : ";
	cin>>r;
	cout<<"\n enter col count : ";
	cin>>c;

	for(i =0; i< r; i++)
	{
		for(j =0; j< c; j++)
		{
			cout<<"\n enter val for mat["<<i<<"]["<<j<<"] ";
			cin>>data[i][j];
		}
	}//for(i
}


template <class X> void Matrix<X> :: disp()
{
	int i, j;

	for(i =0; i< r; i++)
	{
		cout<<endl;
		for(j =0; j< c; j++)
		{
			cout.width(10);
			cout<<data[i][j];
		}
	}//for(i
	cout<<endl;
}


template<class X> Matrix<X> Matrix<X> :: add(Matrix<X> & mat)
{
	Matrix<X> temp;
	temp.r = r;
	temp.c = c;

	if(mat.r != r || mat.c != c)
	{
		cout<<"\n Addition not possible ";
		return temp;
	}

	int i, j;
	for(i =0; i< r; i++)
	{
		for(j =0; j< c; j++)
		{
			temp.data[i][j] = data[i][j] + mat.data[i][j];
		}
	}
	return temp;
}

template<class X> Matrix<X> Matrix<X> :: mul(Matrix<X> & mat)
{
	Matrix<X> temp;

	temp.r = r;
	temp.c = mat.c;

	int i, j, k;
	X sum;

	if(c != mat.r)
	{
		cout<<"\n multiplication not possible ";
		return temp;
	}

	for(i =0; i< r; i++)
	{
		for(j =0; j< mat.c; j++)
		{
			sum =0 ;
			for(k =0; k < c; k++)
			{
				sum = sum + data[i][k]* mat.data[k][j];
			}
			temp.data[i][j] = sum;
		}
	}//for(i

	return temp;
}


template<class Y> void menu(Y var)
{
	Matrix<Y> m1;
	Matrix<Y> m2;
	Matrix<Y> m3;

	int ch;
	do
	{
		cout<<"\n 1. scan mat1 ";
		cout<<"\n 2. scan mat2 ";
		cout<<"\n 3. disp mat1 ";
		cout<<"\n 4. disp mat2 ";
		cout<<"\n 5. matrix addition ";
		cout<<"\n 6. matrix multiplication ";
		cout<<"\n 7. exit ";
		cout<<"\n enter choice ";
		cin>>ch;

		switch(ch)
		{
			case 1:
				m1.scan();
				break;
			case 2:
				m2.scan();
				break;
			case 3:
				m1.disp();
				break;
			case 4:
				m2.disp();
				break;
			case 5:
				m3 = m1.add(m2);
				m3.disp();
				break;
			case 6:
				m3 = m1.mul(m2);
				m3.disp();
				break;
		}
	}while(ch != 7);
	
	var = var;//to clear the warning that specifies var is never used
}//menu

int main()
{
	int a;
	float b;
	int ch;
	
	cout<<"\n 1. int matrix ";
	cout<<"\n 2. float matrix ";
	cout<<"\n enter choice ";
	cin>>ch;
	
	if(ch == 1)
		menu(a);
	else if(ch == 2)
		menu(b);
	else
		cout<<"\n invalid choice ";

  return 0;
}