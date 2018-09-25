import prglang.*; //get access to all public classes and interface of package prglang

class Learner
{
 public static void main(String args[])
 {
  C objC = new C();
  Cpp objCpp = new Cpp();
  Html objHtml = new Html();
  Java objJava = new Java();

  objC.aboutC();
  objCpp.aboutCpp();
  objHtml.aboutHtml();
  objJava.aboutJava();
 }
}