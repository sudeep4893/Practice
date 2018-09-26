#include<stdio.h>
#include<stdlib.h>

struct Student
{
    int rno;
    char name[20];
    float per;
};
typedef struct Student Student;

struct node
{
    Student data;
    struct node * next;
};
typedef struct node node;


//create a new linked list and return address of first node of the list
node * create()
{
    node *h, *n, *p;
    char ch;
    float temp;
    
    h = NULL;//pointer initialization
    
    do
    {
        //create a node
        n = (node*) malloc(sizeof(node));
        
        //initialize the node
        printf("\n enter data for Student ");
        printf("\n Rno ");
        scanf("%d", &n->data.rno);
        printf("\n Name ");
        fflush(stdin);
        scanf("%19s", &n->data.name);
        printf("\n Per ");
        //scanf("%f", &n->data.per);
        scanf("%f", &temp);
        n->data.per = temp;
        
        n->next = NULL;
        
        //connect the node
        if(h == NULL)
        {//current node will be the head node
            h = n;
            p = n;
        }
        else
        {//current node will be a successor node
            p->next = n;
            p = n;
        }
        
        // cycle
        printf("\n Continue ? ");
        fflush(stdin);
        scanf("%c", &ch);
    }while(ch == 'y');
    
    return h;//address of first node of list
}

//traverse the list and print node data
void disp(node *h)
{
    node * p;
    
    printf("\n");
    p = h;//address of head node in a
    while(p != NULL)
    {
        printf("( %d %s %f )", p->data.rno, p->data.name, p->data.per);
        p = p->next;
    }
}//disp

//traverse the list and count the nodes
int count(node *h)
{
    node * a;
    int tot = 0;
    
    a = h;//address of head node in a
    while(a != NULL)
    {
        tot++;
        a = a->next;
    }
    return tot;
}//count


node * search(node *h, char val)
{//sequential search
    node *p;
    p = h;//begins with the first node
    
    while(p != NULL)//runs until end of the list
    {
        if(p->data.name[0] == val)
        {
            return p;//found at node having address p
        }
        p = p->next;
    }//while
    return NULL;//not found
}

node * searchByRno(node *h, int val)
{//sequential search
    node *p;
    p = h;//begins with the first node
    
    while(p != NULL)//runs until end of the list
    {
        if(p->data.rno == val)
        {
            return p;//found at node having address p
        }
        p = p->next;
    }//while
    return NULL;//not found
}

node * getNodeByPosition(node *h, int pos)
{//1st node is at pos 0
    int i;
    node *p;
    p = h;
    for(i = 0; i < pos && p != NULL; i++)
    {
        p = p->next;
    }
    return p;
}

node * sort(node * h)
{//treat linked list like an array
 //bubble
    int i, j;
    int size;
    node *p, *p1, *p2, *q;
    
    size = count(h);
    for(i = size -1; i> 0; i--)
    {
        for(j =0; j< i; j++)
        {
            p = getNodeByPosition(h, j);
            p1 = getNodeByPosition(h, j+1);
            if(p->data.name[0] > p1->data.name[0])
            {//swap
                if(p == h)
                {//swapping head node
                  p2 = p1->next;
                  h = p1;
                  p1->next = p;
                  p->next = p2;
                }
                else
                {//swapping successor node
                  p2 = p1->next;
                  q = getNodeByPosition(h, j-1);
                  q->next= p1;
                  p1->next= p;
                  p->next= p2;
                }
            }//if
        }//for(j
    }//for(i
    return h;
}

node * insert(node * h)
{
    node *n, *p, *q;
    int size, pos, i;
    float temp;
    
    size = count(h); //number of nodes in list

    printf("\n enter pos for new Student ");
    scanf("%d", &pos);
    
    if(pos >=1 && pos <= (size+1))
    {
        //create a node
        n = (node *) malloc(sizeof(node));
        
        //initialize the node
        printf("\n enter data for Student ");
        printf("\n Rno ");
        scanf("%d", &n->data.rno);
        printf("\n Name ");
        fflush(stdin);
        scanf("%19s", &n->data.name);
        printf("\n Per ");
        //scanf("%f", &n->data.per);
        scanf("%f", &temp);
        n->data.per = temp;
        
        n->next = NULL;
        
        //connection
        
        
        if(pos == 1)//case 1, new node will be the head node
        {
            n->next = h;
            h = n;
        }
        else if(pos >1 && pos <= size)//case 2, new node will be added in between
        {
            p = h;
            for(i = 1; i<pos; i++)
            {
                q = p;
                p = p->next;
            }
            //now p is at node : pos
            //and q is at node : pos -1
            
            q->next = n;
            n->next = p;
        }
        else if(pos == size +1)//new node will be the tail node
        {
            //move to the last node
            p = h;
            while(p->next != NULL)
            {
                p = p->next;
            }
            //now p is at the last node
            p->next = n;
        }
    }
    else
    {
        printf("\n Value out of range ");
    }
    return h;
}//insert

node *del(node *h)
{
    node *p, *q, *r;
    int size, pos, i;
    size = count(h);
    
    printf("\n enter pos of Student to be deleted ");
    scanf("%d", &pos);
    
    if(pos >=1 && pos <= size)
    {
        if(pos == 1)//head
        {
            p = h;
            h = h->next;
            free(p);
        }
        else if(pos > 1 && pos < size)//intermediate node
        {
            p = h;
            for(i = 1; i<pos; i++)
            {
                q = p;
                p = p->next;
            }
            //now p is at node : pos
            //and q is at node : pos -1
            r = p->next;
            //and r is at node : pos +1
            
            q->next = r;
            free(p);
        }
        else if(pos == size)//tail node
        {
            p = h;
            for(i = 1; i<pos; i++)
            {
                q = p;
                p = p->next;
            }
            //now p is at node : pos
            //and q is at node : pos -1
            
            free(p);
            q->next = NULL;
        }
    }
    else
    {
        printf("\n Value out of range ");
    }
    return h;
}

void modify(node * h)
{
    node * p;
    int r;
    float temp;
    
    printf("\n enter rno to modify ");
    scanf("%d", &r);
    
    p = searchByRno(h, r);
    
    if(p == NULL)
    {
        printf("\n Rno %d Not Found ", r);
    }
    else
    {
        printf("( %d %s %f )", p->data.rno, p->data.name, p->data.per);        
    
        printf("\n Enter new data for Student");
        printf("\n Rno ");
        scanf("%d", &p->data.rno);
        printf("\n Name ");
        fflush(stdin);
        scanf("%19s", &p->data.name);
        printf("\n Per ");
        //scanf("%f", &p->data.per);
        scanf("%f", &temp);
        p->data.per = temp;
    }
}

int main()
{
    node * h = NULL;
    node * flag;
    int ch, x;
    char q;
    
    printf("\n create student database ");
    h = create();
    do
    {
        printf("\n 1. Insert Student ");
        printf("\n 2. Modify Student ");
        printf("\n 3. Delete Student ");
        printf("\n 4. Search Student ");
        printf("\n 5. View Students ");
        printf("\n 6. Sort Students By Name Initials ");
        printf("\n 7. Exit ");
        printf("\n Enter choice ");
        scanf("%d", &ch);
        
        switch(ch)
        {
            case 1://add
                h = insert(h);
                break;
            case 2://modify
                modify(h);
                break;
            case 3://delete
                h = del(h);
                break;

            case 4://search
                printf("\n enter initials of name to search ");
                fflush(stdin);
                scanf("%c", &q);
                flag = search(h, q);
                if(flag == NULL)
                    printf("\n %c not found ", x);
                else
                    printf("( %d %s %f )", flag->data.rno, flag->data.name, flag->data.per);        
    
                break;
                
            case 5://view all
                disp(h);
                break;
            case 6://sort
                h = sort(h);
                break;                
        
        }//switch
        
    }while(ch != 7);
    return 0;
}