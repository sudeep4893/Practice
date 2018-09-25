class Time
{
//member variables
 int h, m, s;

//member methods
 void setTime(int a, int b, int c)
 {
  int s;//a local variable with same name as of a member variable
  h = a;  // this.h = a;
  m = b; // this.m = b;
  s = c;  // applies to local var s
  //i.e. use of a local variable with same name as of 
  //the member variable, hides the member variable.
  //this concept is called as "Shadowing"
  //to overcome shadowing explicitly apply "this" to the member variable
  this.s = c;
 }

 void displayTime()
 {
  System.out.println(h + ":" + m + ":" + s);
 }

 void incrementTime()
 {
   h++;
   m++;
   s++;
 }

 public static void main(String args[])
 {
 //To use a class create its objects
 //An object is created as follows
  Time t = new Time();

  t.setTime(1,2,3);//setTime(t,1,2,3);
  t.displayTime();
  t.incrementTime();
  t.displayTime();

 }//main
}//Time