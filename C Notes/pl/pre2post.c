#include<stdio.h>
#include<string.h>
#include<math.h>

#define SIZE 100

struct Stack
{
    char data[SIZE][SIZE];
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

void push(Stack *p, char val[])
{
    if(!isFULL(p))
    {
        p->top++;
        strcpy(p->data[p->top],val);
    }
}//push

char * pop(Stack *p)
{
    char x[SIZE] = "";//default value for x
    if( ! isEMPTY(p))
    {
        strcpy(x ,p->data[p->top]);
        p->top--;
    }
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

void pre2post(char postfix[], char prefix[])
{
    int i, iep;
    char s1[SIZE], s2[SIZE], s3[SIZE];
    Stack opndStack;
    
    init(&opndStack);

    for(i =strlen(prefix)-1; i>=0; i--)
    {
        iep = getPriority(prefix[i]);
        if(iep == 0)
        {//operand, push in opndStack
            sprintf(s1, "%c", prefix[i]);
            push(&opndStack, s1);
        }
        else
        {//operator
            
            strcpy(s1 , pop(&opndStack));
            strcpy(s2 , pop(&opndStack));
            sprintf(s3,"%s%s%c", s1,s2, prefix[i]);
            push(&opndStack, s3);
        }
    
    }//for
    //expression traversal complete
    
    strcpy(postfix, pop(&opndStack));
}//pre2post

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
    
    for(i = strlen(prefix)-1; i>=0; i--)
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
    char prefix[SIZE];
    char postfix[SIZE];
    float ans;
    
    printf("\n enter expression in prefix form ");
    scanf("%s", prefix);
    
    pre2post(postfix, prefix);
    
    printf("\n prefix form : %s" , prefix);
    printf("\n postfix form : %s ", postfix);
    
    ans = evaluate(prefix);
    printf("\n Ans : %f", ans);
    
    return 0;
}