#include <stdio.h>
#include<stdlib.h>

//Doubly Linked List
/*
A doubly linked list is all similar to
a singly linked list with an addition of
a previous pointer in every node, it 
refers to the previous node and allows
easy bi-directional traversal.
 
 */

struct node
{
    struct node * prev;
    char data;
    struct node * next;
};
typedef struct node node;

node * create()
{
    node *h, *p, *n;
    int i;
    char str[20];
    printf("\n enter a string ");
    scanf("%19s",str);
    
    h = NULL;//imp initialization
    for(i =0 ; str[i] != '\0'; i++)
    {
        //create node
        n = (node *) malloc(sizeof(node));
        
        //initialize node
        n->data = str[i];
        n->prev = NULL;
        n->next = NULL;
        
        //connection
        if(h == NULL)
        {//for first node
            h = n;
            p = n;
        }
        else
        {//for rest of the nodes
            p->next = n;
            n->prev = p;
            p = n;
        }
        
    }//for
    return h;
}//create

void disp(node * h)
{
    node *p;
    printf("\n");
    p = h;
    while(p != NULL)
    {
        printf("%c  ", p->data);
        p = p->next;
    }//while
    
}//disp

void revDisp(node * h)
{
    node * p;
    printf("\n");
    p = h;
    //move to the last node
    while(p->next != NULL)
    {
        p = p->next;
    }
    
    //disp data and follow prev links
    while(p != NULL)
    {
        printf("%c  ", p->data);
        p = p->prev;
    }
}


int count(node * h)
{
    int x = 0;
    node *p;
    p = h;
    while(p != NULL)
    {
        x++;
        p = p->next;
    }//while
    return x;
}//count

node * insert(node * h)
{

    node *n, *p, *q;
    int size, pos, i;
    size = count(h); //number of nodes in list

    printf("\n enter pos for new node ");
    scanf("%d", &pos);
    
    if(pos >=1 && pos <= (size+1))
    {
        //create a node
        n = (node *) malloc(sizeof(node));
        
        //initialize the node
        printf("\n Enter data for new node ");
        fflush(stdin);
        scanf("%c", &n->data);
        n->prev = NULL;
        n->next = NULL;
        
        //connection
        
        
        if(pos == 1)//case 1, new node will be the head node
        {
            n->next = h;
            h->prev = n;
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
            n->prev = q;
            n->next = p;
            p->prev = n;
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
            n->prev = p;
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
    
    printf("\n enter pos of node to be deleted ");
    scanf("%d", &pos);
    
    if(pos >=1 && pos <= size)
    {
        if(pos == 1)//head
        {
            p = h;
            h = h->next;
            h->prev = NULL;
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
            r->prev = q;
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
int main()
{
	node *head;
	int ch;
	head = NULL;

	do
	{
		printf("\n 1. create list ");
		printf("\n 2. disp list ");
		printf("\n 3. disp list in reverse ");
		printf("\n 4. insert node ");
		printf("\n 5. delete node ");
		printf("\n 6. exit ");
		printf("\n enter choice ");
		scanf("%d", &ch);

		switch(ch)
		{
			case 1:
				head = create();
				break;
			case 2:
				disp(head);
				break;
			case 3:
				revDisp(head);
				break;
			case 4:
				head = insert(head);
				break;
			case 5:
				head = del(head);
				break;
		}//switch
	}while(ch != 6);
        return 0;
}//main