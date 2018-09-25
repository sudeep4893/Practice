//Access Specifiers

//import p1.Base;
//import p1.Derived;
//import p1.NonDerived;
//import p2.Derived2;
import p2.NonDerived2;

class AccessSpecifiers
{
 public static void main(String args[])
 {
  //case 1 : attempt to use members, with all access specifiers, in the same class
  //Base b1 = new Base();
  //b1.display();

  //case 2 : attempt to use members, with all access specifiers, in the derived class of same package
  //Derived d1 = new Derived();
  //d1.display();

  //case 3 : attempt to use members, with all access specifiers, in the non derived class of same package
  //NonDerived nd1 = new NonDerived();
  //nd1.display();

  //case 4 : attempt to use members, with all access specifiers, in the derived class of other package
  //Derived2 d2 = new Derived2();
  //d2.display();

  //case 5 : attempt to use members, with all access specifiers, in the non derived class of other package
  NonDerived2 nd2 = new NonDerived2();
  nd2.display();

 }
}

/*
Access Specifiers, when applied to
members of a class, limit the usability
of the members.
For a class Java support 4 different 
types of access specifiers:
1) private 
2) no access specifier <default>
3) protected
4) public

Study
--------

Case 1 : attempt to use members, with all access specifiers, in the same class
--All the members were directly accessible within the same class.

Case 2 : attempt to use members, with all access specifiers, in the derived class of same package
--All the members other than private members were directly accessible within the derived class of same package.

Case 3 : attempt to use members, with all access specifiers, in the non derived class of same package
--All the members other than private members were accessible (through object) within the non derived class of same package.

Case 4 : attempt to use members, with all access specifiers, in the derived class of other package
--private and no access specified members were not accessible within the derived class of other package.
--protected and public members were directly accessible within the derived class of other package.

Case 5 : attempt to use members, with all access specifiers, in the non derived class of other package
--private, no access specified and protected members were not accessible within the non derived class of other package.
--public members were accessible (through object) within the non derived class of other package.

*/


