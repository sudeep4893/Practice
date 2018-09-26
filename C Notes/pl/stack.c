#include <stdio.h>
#define SIZE 5

/*
Stack
A stack is a linear data structure, that  
supports insertion and extraction of data
from one common end. 

Due to one common opening for insertion  
and extraction of data and begin linear,      
the data that goes in last comes out first
(LIFO order).
  
A stack supports following operations

1) Push : Add a value into the stack. The value must be added at topmost position only.
 
2) Pop : Remove a value from the stack. The value must be removed from topmost position only.
 
3) Peek : Fetch the topmost value of the stack. No data to be removed from the stack.
 
4) Display : Display stack content 
 
5) IsFull : Returns a boolean, indicating full state of the stack.
 
6) IsEmpty : Returns a boolean, indicating empty state of the stack.
 
7) Init : Initialize the stack to an empty state.
 
----------------------------------------------------------  
A stack can be implemented using an array or 
a linked list.
 
 
*/

struct Stack
{
    int data[SIZE];
    int top;
};
typedef struct Stack Stack;

void init(Stack *p)
{
    p->top = -1; //initialized to empty state
}

int isFULL(Stack * p)
{
    if(p->top == SIZE -1)
        return 1; //true
    else
        return 0; //false
}

int isEMPTY(Stack * p)
{
    if(p->top == -1)
        return 1; //true
    else
        return 0; //false
}

void push(Stack *p, int val)
{
    if(!isFULL(p))
    {
        p->top++;
        p->data[p->top] = val;
    }
    else
        printf("\n Stack Overflow");
}//push

int pop(Stack *p)
{
    int x = 0;//default value for x
    if( ! isEMPTY(p))
    {
        x = p->data[p->top];
        //optionally
        //p->data[p->top] = 0;
        p->top--;
    }
    else
        printf("\n Stack Underflow ");
    
    return x;
}

int peek(Stack *p)
{
    int x = 0;//default value for x
    if( ! isEMPTY(p))
        x = p->data[p->top];
    else
        printf("\n Stack Underflow ");
    
    return x;
}


void disp(Stack *p)
{
    int i;
    for(i = p->top; i>=0 ; i--)
    {
        printf("\n %d" ,p->data[i]);
    }
}

int main()
{
    int q, ch;
    
    Stack s;
    init(&s);
    
    do
    {
        printf("\n 1. push ");
        printf("\n 2. pop ");
        printf("\n 3. peek ");
        printf("\n 4. disp ");
        printf("\n 5. exit ");
        printf("\n enter choice ");
        scanf("%d", &ch);
        
        switch(ch)
        {
            case 1://push
                printf("\n enter value to push ");
                scanf("%d", &q);
                push(&s, q);
                break;
            case 2://pop
                q = pop(&s);
                printf("\n %d removed ", q);
                break;
            case 3://peek
                q = peek(&s);
                printf("\n %d at top of stack ", q);
                break;
            case 4://disp
                disp(&s);
                break;
        }//switch
    }while(ch != 5);
    return 0;
}
