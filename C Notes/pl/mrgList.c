#include<stdio.h>
#include<stdlib.h>

/*
Merge 2 lists

tasks :
1st list : sort while creation
2nd list : sort after creation
merge 1st and 2nd and form a final list that is sorted
*/


struct node
{
    int data;
    struct node * next;
};
typedef struct node node;

node * screate() //sort and create
{
    node *h, *n, *p, *q;
    char ch;
    int flag;
    
    h = NULL;//imp initialization
    do
    {
        //create a node
        n = (node*) malloc(sizeof(node));
        
        //initialize the node
        printf("\n enter data for node ");
        scanf("%d", &n->data);
        n->next = NULL;
        
        //connection
        if(h == NULL)
        {//n will be the head node
            h = n;
        }
        else
        {//traverse and compare and connect   
            flag = 0;
            p = h;
            while(p != NULL)
            {
                if(n->data < p->data)
                {
                    if(p == h)
                    {//n will be new head node
                        n->next = h;
                        h = n;
                        flag = 1; //connection done
                        break;//stop traversal
                    }
                    else
                    {//n will be connected between q and p
                        q->next = n;
                        n->next = p;
                        flag = 1; //connection done
                        break;//stop traversal
                    }
                }
                else
                {
                    q = p;//shadow
                    p = p->next;
                }
            }//while
            
            if(flag == 0)
            {//connection not done yet
                q->next = n; //connect as tail node
            }
        }//else
        
        //cycle
        printf("\n Continue ? ");
        fflush(stdin);
        scanf("%c", &ch);
    }while(ch == 'y');
    return h; 
}//screate

//create a new linked list and return address of first node of the list
node * create()
{
    node *h, *n, *p;
    char ch;
    
    h = NULL;//pointer initialization
    
    do
    {
        //create a node
        n = (node*) malloc(sizeof(node));
        
        //initialize the node
        printf("\n enter data for node ");
       
        scanf("%d", &n->data);
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
        printf(" %d", p->data);
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
            if(p->data > p1->data)
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

node * merge(node *h1, node *h2)
{
    //merge (by pointer manipulation) h1 into h2 and form h3
    node * h3;//resultant
    node *p1, *p2;
    node *q;
    
    
    if(h1 == NULL && h2 == NULL)
        return NULL;
    else if(h1 == NULL && h2 != NULL)
        return h2;
    else if(h1 != NULL && h2 == NULL)
        return h1;
    
    //both lists need to be merged
    
    //imp initializations
    p1 = h1;
    p2 = h2;
    h3 = NULL;
    
    while(p1 != NULL && p2 != NULL)
    {
        if(p1->data <= p2->data)
        {
            if(p1 == h1 && h3 == NULL)
            {//first node in merged list
                h3 = h1;
                q = p1;
                p1 = p1->next;
            }
            else
            {//successor node in merged list
                q->next = p1;
                q = p1;
                p1= p1->next;
            }
        }
        else if(p2->data < p1->data)
        {
            if(p2 == h2 && h3 == NULL)
            {//first node in merged list
                h3 = h2;
                q = p2;
                p2 = p2->next;
            }
            else
            {//successor node in merged list
                q->next = p2;
                q = p2;
                p2 = p2->next;
            }
        }
    }//while

    //possibility 1
    if(p1 != NULL && p2 == NULL)
    {
        q->next = p1;
    }
    //possibility 2
    else if(p1 == NULL && p2 != NULL)
    {
        q->next = p2;
    }
    
    return h3;
}
int main()
{
    node *head1, *head2;
    node *merged;
    
    head1 = screate();
    
    head2 = create();
    head2 = sort(head2);
    
    disp(head1);
    disp(head2);
    
    merged = merge(head1, head2);
    disp(merged);
    return 0;
}