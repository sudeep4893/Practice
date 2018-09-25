package p1;

public class Base
{
 private int i;
 int j;
 protected int k;
 public int l;

 public Base()
 {
  System.out.println("p1 Base Base()");
  i = 10;//initialize == write == use
  j = 20;//  ---"---
  k = 30;//  ---"---
  l = 40;//  ---"---
 }

 public void display()
 {
  System.out.println("p1 Base display()");
  System.out.println("i : " + i);//fetch == read == use
  System.out.println("j : " + j);//fetch == read == use
  System.out.println("k : " + k);//fetch == read == use
  System.out.println("l : " + l);//fetch == read == use
 }
}//Base