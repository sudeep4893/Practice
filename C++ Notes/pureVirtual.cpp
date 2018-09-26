#include <iostream>
using namespace std;

/*

Introduction
---------------

A system may be implemented using a 
family of classes (multiple classes
inherit a common base class).

Example
	  	Vehicle
		 |     |    |
 		Car  Bike Truck	
 		
			Animal
		|    |     |	
	Fish	Snake	Dog									 		

In such a case the role of base class is
1) to form a family
2) to hold common code and data
3) to enforce certain method definitions.

It can be understood that certain operations
are valid but cannot be defined at base
class level.

Example :
	start(), stop(), ... operations for Vehicle
	eat(), move(), ... operations for Animal

In such a case the base class needs
an operation declaration and skip its
definition.

C++ supports declaration of such base class
level operations by providing "pure virtual functions".

Definition
------------
A pure virtual function is a function
with declaration (signature) only and
no definition (body).

Syntax
virtual fn signature = 0;

Example
virtual float area() = 0;

---------------------------------------------------

Abstract Class
-----------------

A class that contains a pure virtual
function becomes an "abstract class".

It is a class that cannot be instantiated.
i.e. its objects cannot be created.

Known that a class is used through its objects.
Hence an abstract class cannot be directly
used. It is designed to be inherited and used.


Inheritance of Abstract Class
-------------------------------
When a class inherits an abstract class
then along with code and data it also gets
pure virtual function from the base abstract 
class.

So a derived class contains a pure virtual
function due to inheritance.

Known that a class that contains a pure
virtual function becomes an abstract class.
So the derived class becomes an abstract 
class due to inheritance.

To become a normal class again the derived
class must override the inherited pure
virtual function.


Conclusion
--------------
A pure virtual function declared by a
base class represents a valid base class
opertion.
It is to be compulsorily overridden by
the derived class.

*/

class Shape //an abstract class
{
	protected:
		float x;//dimension
	public:
		Shape();
		Shape(float);
		virtual void disp();
		virtual float area()=0;//a valid operation for Shape but cannot be defined by Shape, hence declared as pure virtual function
};

Shape ::Shape()
{
	cout<<"\n Shape()";
	x = 10;
}

Shape ::Shape(float q)
{
	cout<<"\n Shape(float)";
	x = q;
}

void Shape :: disp()
{
	cout<<"\n Dimension 1 : "<<x;
}

class Rect: public Shape
{
	protected:	
		float y;//another dimension
	public:
		Rect();
		Rect(float, float);
		void disp();
		float area();//overriding the inherited pure virtual function
};

Rect :: Rect()
{
	cout<<"\n Rect()";
	y = 20;
}

Rect :: Rect(float q, float w): Shape(q)
{
	cout<<"\n Rect(float, float)";
	y = w;
}

void Rect :: disp()
{
	cout<<"\n Rect( " << x << "," << y << " )";
}

float Rect :: area()
{
	return x*y;
}

class Circle: public Shape
{
	public:
		Circle();
		Circle(float);
		void disp();
		float area();//overriding the inherited pure virtual function
};

Circle:: Circle()
{
	cout<<"\n Circle()";
}

Circle :: Circle(float q): Shape(q)
{
	cout<<"\n Circle(float)";
}

void Circle:: disp()
{
	cout<<"\n Circle ( " << x << " )";
}

float Circle :: area()
{
	return 3.14 * x*x;
}


int main()
{
	int ch;
	Shape *p;
	cout<<"\n 1. circle ";
	cout<<"\n 2. rectangle ";
	cout<<"\n enter choice ";
	cin>>ch;
	
	if(ch == 1)
	{
		p=  new Circle();
	}
	else if(ch == 2)
	{
		p=  new Rect();
	}
	else
	{
		cout<<"\n invalid choice ";
		return 0;//terminate main
	}
	
	p->disp();
	float a;
	a = p->area();
	cout<<"\n area : "<<a;
	
	delete p;
		
	return 0;
}

