#include<stdio.h>
#include<string.h>
#include<math.h>

#define SIZE 100

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
    return x;
}

int peek(Stack *p)
{
    int x = 0;//default value for x
    if( ! isEMPTY(p))
        x = p->data[p->top];
    return x;
}

struct EStack
{
    float data[SIZE];
    int top;
};
typedef struct EStack EStack;

void einit(EStack *p)
{
    p->top = -1; //initialized to empty state
}

int eisFULL(EStack * p)
{
    if(p->top == SIZE -1)
        return 1; //true
    else
        return 0; //false
}

int eisEMPTY(EStack * p)
{
    if(p->top == -1)
        return 1; //true
    else
        return 0; //false
}

void epush(EStack *p, float val)
{
    if(!eisFULL(p))
    {
        p->top++;
        p->data[p->top] = val;
    }
}//epush

float epop(EStack *p)
{
    float x = 0;//default value for x
    if( ! eisEMPTY(p))
    {
        x = p->data[p->top];
        //optionally
        //p->data[p->top] = 0;
        p->top--;
    }
    return x;
}

struct OStack
{
    char data[SIZE][SIZE];
    int top;
};
typedef struct OStack OStack;

void oinit(OStack *p)
{
    p->top = -1; //initialized to empty state
}

int oisFULL(OStack * p)
{
    if(p->top == SIZE -1)
        return 1; //true
    else
        return 0; //false
}

int oisEMPTY(OStack * p)
{
    if(p->top == -1)
        return 1; //true
    else
        return 0; //false
}

void opush(OStack *p, char val[])
{
    if(!oisFULL(p))
    {
        p->top++;
        strcpy(p->data[p->top] ,val);
    }
}//opush

char * opop(OStack *p)
{
    char x[SIZE] = "";//default value for x
    if( ! oisEMPTY(p))
    {
        strcpy(x ,p->data[p->top]);
        p->top--;
    }
    return x;
}


int getPriority(char element)
{
    switch(element)
    {
        case '(':
            return 4;
        case '$':
            return 3;
        case '*':
            return 2;
        case '/':
            return 2;
        case '+':
            return 1;
        case '-':
            return 1;
        case ')':
            return -1;        
        default://operands
            return 0;
    }
}//getPriority

void in2pre(char prefix[], char infix[])
{
    int i, iep, isop;
    char iso;
    Stack s;
    OStack os;
    char s1[SIZE], s2[SIZE], s3[SIZE];
    char op;
    
    //imp initializations
    init(&s);
    oinit(&os);
    
    for(i = 0; infix[i]!= '\0'; i++)
    {
        iep = getPriority(infix[i]);
    
        if(iep == 0)
        {//operand, goes into the operand stack
            sprintf(s1, "%c",infix[i]);
            opush(&os, s1);
        }
        else if(iep < 0)
        {//closing bracket
            
            //pop out all the operators until ( comes out
            
            iso = peek(&s);//gets topmost stack operator
            while(iso != '(')
            {
                op = pop(&s);
                strcpy(s2 ,opop(&os));
                strcpy(s1 ,opop(&os));

                sprintf(s3, "%c%s%s", op, s1,s2);
                opush(&os, s3);
                    
                //fetch new in stack operator
                iso = peek(&s);
            }//while
            pop(&s); //to remove (
        }
        else if(iep > 0)
        {//operator, must be pushed in stack
            
            iso = peek(&s);//gets topmost stack operator
            isop = getPriority(iso);
            
            if(isEMPTY(&s)) //empty stack
                push(&s, infix[i]);
            else if(infix[i] == '$' && iso == '$')
                push(&s, infix[i]); //$ is solved r to l
            else if(iso == '(')//abv opening bracket
                push(&s, infix[i]);
            else if(iep > isop)//abv low prior. in stack operator
                push(&s, infix[i]);
            else if(isop >= iep)//instack operator is more or equal prior
            {
                //a) first pop out all the high/equal priority operators from stack and place them in result
                while(isop >= iep && iso != '(')
                {
                    op = pop(&s);
                    strcpy(s2 ,opop(&os));
                    strcpy(s1 ,opop(&os));
                
                    sprintf(s3, "%c%s%s", op, s1,s2);
                    opush(&os, s3);
                    
                    iso = peek(&s);
                    isop = getPriority(&s);
                }//while
                
                //b) finally push in the incoming opearator
                push(&s, infix[i]);
            }
        }
        
    }//for(i
    //expression traversal complete

    //pop out all the instack operators and place them in result. 

    while(! isEMPTY(&s))
    {
        op = pop(&s);
        strcpy(s2 ,opop(&os));
        strcpy(s1 ,opop(&os));
                
        sprintf(s3, "%c%s%s", op, s1,s2);
        opush(&os, s3);
    }
    
    strcpy(prefix ,opop(&os));
    
}//in2pre

float solve(float opnd1, float opnd2, char op)
{
    switch(op)
    {
        case '*':
            return opnd1 * opnd2;
        case '/':
            return opnd1 / opnd2;
        case '+':
            return opnd1 + opnd2;
        case '-':
            return opnd1 - opnd2;
        case '$':
            return pow(opnd1,opnd2);
        default:
            return 0;            
    }//switch
}//solve

float evaluate(char prefix[])
{
    int i;
    int iep;
    float n1, n2, n3;
    EStack es;
    
    einit(&es);
    
    for(i =strlen(prefix)-1 ; i >=0; i--)
    {
        iep = getPriority(prefix[i]);
        if(iep == 0)
        {//operand
            printf("\n enter val for %c " , prefix[i]);
            scanf("%f", &n1);
            epush(&es, n1);
        }
        else
        {//operator
            n1 = epop(&es);
            n2 = epop(&es);
            n3 = solve(n1, n2, prefix[i]);
            epush(&es, n3);
        }
    }//for
    n3 = epop(&es);
    return n3;
}//evaluate

int main()
{
    char infix[SIZE];
    char prefix[SIZE];
    float ans;
    
    printf("\n enter expression in infix form ");
    scanf("%s", infix);
    
    in2pre(prefix, infix);
    printf("\n infix form : %s" , infix);
    printf("\n prefix form : %s ", prefix);
 
    ans = evaluate(prefix);
    printf("\n Ans : %f", ans);
    
    return 0;
}