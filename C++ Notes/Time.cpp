#include <iostream>
using namespace std;

/*
Operator Overloading is defining 
operator functions that contain logic 
to perform operator corresponding 
process on class objects.
*/
class Time
{
	private:
		int h, m, s;//member variables
	public:
		Time();//default constructor
		Time(int,int,int);//parameterized constructor
		
		//operator functions
		Time operator +(Time &x);
		Time operator-(Time &x);
		Time operator +(int x);
		Time operator ++();//pre increment
		Time operator ++(int q);//post increment
		int operator[](int x);
		Time & operator = (Time &x);
		Time & operator = (int x);
		
		//type conversion
		operator int();
		operator double();
		
		//friend operator functions
		friend Time operator +(int x, Time &r);
		friend ostream& operator<<(ostream &o, Time &r);
		friend istream& operator >>(istream &i, Time &r);

		
};

Time :: Time()//default constructor
{
	h = 0;
	m = 0;
	s = 0;	
}

Time :: Time(int q, int w, int e)//parameterized constructor
{
	h = q;
	m = w;
	s = e;	
}


Time Time ::operator +(Time &x)
{
	Time temp;
	temp.h = h + x.h;
	temp.m = m + x.m;
	temp.s = s + x.s;
	return temp;
}

Time Time :: operator-(Time &x)
{
	Time temp;
	temp.h = h - x.h;
	temp.m = m - x.m;
	temp.s = s - x.s;
	return temp;	
}

Time Time :: operator +(int x)
{
	Time temp;
	temp.h = h +x;	
	temp.m = m +x;
	temp.s = s +x;
	return temp;
}

Time operator +(int x, Time &r)
{
	Time temp;
	temp.h = x + r.h;
	temp.m = x + r.m;
	temp.s = x + r.s;
	return temp;
}

Time Time :: operator ++()//pre increment
{
	//increment the caller object
	++h;
	++m;
	++s;	
	
	//create a copy of incremented caller object
	Time temp;
	temp.h = h;
	temp.m = m;
	temp.s = s;
	
	//return the incremented copy
	return temp;
}

Time Time :: operator ++(int q)//post increment
{
	//to remove the warning q is never used
	q = q;
	
	//create a copy of caller object
	Time temp;
	temp.h = h;
	temp.m = m;
	temp.s = s;
	
	//increment the caller object
	h++;
	m++;
	s++;
	
	//return the old value of the caller object
	return temp;
}

int Time :: operator[](int x)
{
	if(x == 0)
		return h;
	else if(x == 1)
		return m;
	else if(x == 2)
		return s;
	else
	{
		cout<<"\n invalid index ";
		return 0;
	}
}

ostream& operator<<(ostream &o, Time &r)
{
	o<<"\n"<<r.h<<":"<<r.m<<":"<<r.s;
	return o; //to serve as first param for cascaded calls
}

istream& operator >>(istream &i, Time &r)
{
	cout<<"\n Enter Hours ";
	i>>r.h;
	cout<<"\n Enter Minutes ";
	i>>r.m;
	cout<<"\n Enter Seconds ";
	i>>r.s;
	
	return i;//to support cascaded calls
}


Time& Time :: operator= (Time &x)
{
	h = x.h;
	m = x.m;
	s = x.s;
	return *this;//return caller object
}

Time& Time :: operator =(int x)
{
	h = x;
	m = x;
	s = x;
	return *this;//return the caller object	
}

Time :: operator int()
{
//logic to convert current object into int
	int q;
	q = h*60*60 + m*60 + s;
	return q;

}

Time :: operator double()
{
	//logic to convert current object into double
	double q;
	q = h + m/60.0 + s/(60.0*60.0);
	return q;
}

int main()//prg starts here
{
	//3 Time objects
	Time t1(10,20,30);
	Time t2(1,2,3);
	Time t3;
	
	t3 = t1;
	
	//t3 = t1 + t2;
	//t3 = t1 - t2;
	//t3 = t1 + 5;
	//t3 = 5 + t1;
	
	//t3 = t1++;//post increment
	//t3 = ++t1;//pre increment
	
	/*
	int q, i;
	for(i =0; i< 4; i++)
	{
		q = t1[i];
		cout<<"\n"<<q;
	}
	*/

	//cin>>t1>>t3;
	
	t1 = t3 = 5;
	cout<<t1<<t3;
	
	int y;
	double z;
	y = t3;
	z = t3;
	
  cout<<"\n y : "<<	y;
  cout<<"\n z : "<<	z;
		
	return 0;
}

/*
System has the default definitions of 
"operator ="
"operator &"
"operator ."
"operator new"
"operator delete"
for class objects.
But doesnt define any more operators
for class objects.

Hence use of other operators on
class objects result in compile errors.

It is possible to define operator functions
that contain logic to perform operator 
corresponding process on class objects

Doing so is called as "operator overloading".

---------------------------------------------
Consider following cases

Case 1: perform addition on two Time objects
i.e. 	t1 + t2


In the above statement
t1 : is the caller object
+  : is the operator function 
t2 : is the parameter object
	
Refer to code above for implementation details.
------------------------------------------------

Case 2: perform subtraction on two Time objects
i.e. 	t1 - t2


In the above statement
t1 : is the caller object
-  : is the operator function 
t2 : is the parameter object
	
Refer to code above for implementation details.

------------------------------------------------

Case 3: perform addition on one Time object and one int
i.e. 	t1 + 5

In the above statement
t1 : is the caller object
+  : is the operator function 
5 : is the int parameter 
	
Refer to code above for implementation details.

------------------------------------------------

Case 4: perform addition on one int and one Time object 
i.e. 	5 + t1

Known that

1) A member function can be called using 
object the class.
And cannot be called directly or with 
object of any other class.

2) A non member function can be called
directly. Caller object cannot be applied 
to it.

In the statement	:	5 + t1

5 is an int, and cannot be the caller
object for function of class Time.

i.e. for the above operator fn call a 
valid caller object is not available.

Hence the above operator fn must be
called without any caller object.

Hence the above operator fn must be
overloaded as a "non member" function.

Finally, for the statement : 5 + t1

+ : non member operator fn
5 : first parameter
t1 : second parameter

Refer to code above for implementation details.

------------------------------------------------
Case 5: Unit increment on Time objects
		t1++; //post increment
		++t1; //pre increment
		
The two operations must have the same
affect on caller object t1.
But to handle priority 
* the post increment must return old value of caller object
* the pre increment must return incremented value of caller object

Case 5.1 : In the call
	t1++ 
t1 : caller object
++ : operator fn
no parameters (as it is a unary operator)

Hence fn signature

Time Time :: operator ++()
{
	...logic
	return Time object
}


Case 5.2 : In the call
	++t1 
t1 : caller object
++ : operator fn
no parameters (as it is a unary operator)

Time Time :: operator ++()
{
	...logic
	return Time object
}

Problem
---------
Case 5.1 and Case 5.2
i.e.
defintions of fns for preincrement ++
and postincrement ++ result in same 
(duplicate) function signature.

Known that in C++ functions signature
must be unique.

Solution offered by C++ :
---------------------------
The post increment operator ++ function
must receive 1 int parameter.
It must not be passed in the call.
It must only be received.

Hence signature for case 5.1
	Time Time :: operator ++(int);//post increment
Hence signature for case 5.2
	Time Time :: operator ++();//pre increment

------------------------------------------------

Case 6: define [] for Time object and int
i.e. 	t1[2]

In the above statement
t1 : is the caller object
[]  : is the operator function 
2 : is the int parameter 
	
Refer to code above for implementation details.

------------------------------------------------
Case 7: define << for cout and Time object
i.e. 	cout << t1;

Known that

1) A member function can be called using 
object the class.
And cannot be called directly or with 
object of any other class.

2) A non member function can be called
directly. Caller object cannot be applied 
to it.

In the statement	:	cout<<t1;

cout is an ostream object, and cannot 
be the caller object for function of 
class Time.

i.e. for the above operator fn call a 
valid caller object is not available.

Hence the above operator fn must be
called without any caller object.

Hence the above operator fn must be
overloaded as a "non member" function.

Finally, for the statement : cout<<t1

<< : non member operator fn
cout : first parameter
t1 : second parameter

Refer to code above for implementation details.

------------------------------------------------
Case 8: define >> for cin and Time object
i.e. 	cin >> t1;

Known that

1) A member function can be called using 
object the class.
And cannot be called directly or with 
object of any other class.

2) A non member function can be called
directly. Caller object cannot be applied 
to it.

In the statement	:	cin>>t1;

cout is an ostream object, and cannot 
be the caller object for function of 
class Time.

i.e. for the above operator fn call a 
valid caller object is not available.

Hence the above operator fn must be
called without any caller object.

Hence the above operator fn must be
overloaded as a "non member" function.

Finally, for the statement : cin>>t1

>> : non member operator fn
cin : first parameter
t1 : second parameter

Refer to code above for implementation details.

------------------------------------------------

Case 9: define = for 2 Time objects
i.e. 	t3 = t1;

Known that system has the default definition
of "operator =" for all primary/secondary
datatypes.
But it is a shallow copy approach.
So it may be overloaded for customized
purposes.

It is a rule that "operator =" must be
overloaded as a member function only.
i.e. it cannot be overloaded as a non-
member function.

In the above statement
t3 : is the caller object
=  : is the operator function 
t1 : is the parameter object
	
Refer to code above for implementation details.

------------------------------------------------
Case 10: define = for 1 Time object and 1 int
i.e. 	t3 = 5;

Known that system has the default definition
of "operator =" for all primary/secondary
datatypes.
But it requires both operands to be of
same/compatible type.

So it may be overloaded for application
on objects of different types.

In the above statement
t3 : is the caller object
=  : is the operator function 
5 : is the int parameter
	
Refer to code above for implementation details.

------------------------------------------------
Case 11: define = for 1 int and 1 Time object 
i.e. 	
int x;
x = t3;


Known that

1) system has the default definition
of "operator =" for all primary/secondary
datatypes. But it requires both operands 
to be of same/compatible type.

2) A member function can be called using 
object the same class.
And cannot be called directly or with 
object of any other class.

3) A non member function can be called
directly. Caller object cannot be applied 
to it.

4) "operator =" cannot be overloaded as
a non member function.

Due to above 4 points, the call
		x = t3
cannot be solved using operator overloading.

Solution is to apply "Type Conversion".

Type Conversion is defining 
operator <datatype> functions 
that contain logic to convert 
current object into its <datatype>
equivalent and return the same.

syntax :
	
className :: operator <datatype>()
{
  logic to convert current object
  into its <datatype> equivalent
  
  return <datatype>
}

Refer to code above for implementation details.

*/
