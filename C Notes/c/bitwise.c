#include<stdio.h>
/*
 Bitwise Operators

 C supports 6 bitwise operators that act on
 the binary digits (bits) of a number.

 1) << : Left Shift Operator
 It is a binary operator.
 It acts on the bits of the LHS operand.
 It generates a new number by shifting
 the bits of LHS operand leftwards.
 The amount to shift by is specified by
 the RHS operand.
 
 Due to shift the leftmost bits are lost
 and blanks created at right side are
 auto filled with zeros.
 
 2) >> : Right Shift Operator
 It is a binary operator.
 It acts on the bits of the LHS operand.
 It generates a new number by shifting
 the bits of LHS operand rightwards.
 The amount to shift by is specified by
 the RHS operand.
 
 Due to shift the rightmost bits are lost
 and blanks created at left side are
 auto filled with zeros. 
  
 
 3) ~ : Ones Complement Operator
 It is a unary operator.
 It acts on the bits of the operand.
 It generates a new number by reversing
 the bits of the operand.
 (ZERO bits become ONE and ONE bits 
 become ZERO).
 
 
 4) & : Bitwise And 
 It is a binary operator.
 It acts on the bits of its operands.
 It generates a new number by ANDING
 (applying Bitwise AND) the bits of its 
 operands.
 Resultant bits are generated as follows
 
 1 & 1 = 1
 1 & 0 = 0
 0 & 1 = 0
 0 & 0 = 0
 
 5) | : Bitwise Or
 It is a binary operator.
 It acts on the bits of its operands.
 It generates a new number by ORING
 (applying Bitwise OR) the bits of its 
 operands.
 Resultant bits are generated as follows
 
 1 | 1 = 1
 1 | 0 = 1
 0 | 1 = 1
 0 | 0 = 0
 
 6) ^ : Bitwise XOr
 It is a binary operator.
 It acts on the bits of its operands.
 It generates a new number by XORING
 (applying Bitwise XOR) the bits of its 
 operands.
 Resultant bits are generated as follows
 
 1 ^ 1 = 0
 1 ^ 0 = 1
 0 ^ 1 = 1
 0 ^ 0 = 0 
  
 */

void dispBinary(unsigned int x)
{
  int arr[32] = {}; //all array elements will become zero
  //int arr[16] = {};//for TC 3.0
  int size = 32;
  //int size = 16;//for TC 3.0
  int i;
  
  printf("\n %8u : ", x);
  i = size -1;
  
  while(x > 0)
  {
      arr[i]= x%2;
      x = x/2;
      i--;
  }
  
  for(i =0 ; i< size; i++)
      printf("%d", arr[i]);
}//dispBinary

int main()
{
    unsigned int x, y;
    x = 12;
    //y = x << 2;
    //y = x >> 2;
    //y = ~x;
    //y = x & 10;
    //y = x | 10;
    y = x ^ 10;
    dispBinary(x);
    dispBinary(10);
    dispBinary(y);
    return 0;
}