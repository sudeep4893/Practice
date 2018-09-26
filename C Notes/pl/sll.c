#include <stdio.h>
#include<stdlib.h>

//Singly Linked List

struct node
{
    int data;//for storing information
    struct node * next;
};
//here node is a "referential structure"
//because it has a pointer of its own
//type in its definition.

typedef struct node node;

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

void dispReverse(node *h)
{
    int n, i,j;
    node *p;
    
    n = count(h);//number of nodes
    
    printf("\n ");
    for(i = 1; i<= n; i++)
    {
        p = h;
        for(j = 1; j <= n-i; j++)
        {//for n-i jumps
            p = p->next;
        }//for(j
        printf(" %d", p->data);
    }
}

node * addNodeAtHead(node * h)
{
    node *n;

    //create a new node
    n=(node*) malloc(sizeof(node));
    
    //initialize the node
    printf("\n enter data for node ");
    scanf("%d", &n->data);
    
    n->next = h;//connection
    h = n; //reset the head node
    
    return h;//update the head node in main
}


void addNodeInBetween(node *h)
{
    node *n, *p, *q;
    int pos, size, i;
    
    //fetch position of the node
    printf("\n enter position of new node ");
    scanf("%d", &pos);
    
    //validate the position
    size = count(h);
    
    if(pos >1 && pos <= size )
    {//valid position
        
        //create a node 
        n = (node*) malloc(sizeof(node));
    
        //initialize the node
        printf("\n enter data for new node ");
        scanf("%d", &n->data);
        n->next = NULL;
    
        //traversal
        p = h;
        for(i = 1; i<pos; i++)
        {
            q = p;//maintaining a shadow
            p = p->next;
        }
        //now p is at node : pos
        //and q is at node : pos -1
        
        //connection
        q->next = n;
        n->next = p;
    }
    else
    {
        printf("\n Illegal Position");
    }
}//addNodeInBetweeen



void deleteNodeInBetween(node *h)
{
    int pos, size, i;
    node *p, *q, *r;
    
    printf("\n enter position of node to be deleted ");
    scanf("%d", &pos);
    
    size = count(h);
    if(pos > 1 && pos <size)
    {
        //reach the node to be deleted
        p = h;
        for(i = 1;i<pos; i++)
        {
            q = p;
            p = p->next;
        }
        //now p is at node : pos
        //and q is at node : pos -1
        r = p->next;
        //and r is at node : pos +1
        
        
        //remove node p
        free(p);//dellocate the memory
        
        //connect pos-1 and pos+1 nodes
        q->next = r;
    }
    else
    {
        printf("\n Illegal Position");
    }
}

node * deleteNodeAtHead(node * h)
{
    node *p;
    
    p = h;//catch the head node    
    h = h->next;//reset the head node
    free(p);//delete the old head node
    return h;
}

node * addNodeAtTail(node * h )
{
    node *n, *p;

    //create a node
    n = (node *)malloc(sizeof(node));
    
    //initialization
    printf("\n enter data for new node ");
    scanf("%d", &n->data);
    n->next = NULL; //tail node has NULL in its next

    //connection
    if(h == NULL)//case 1 : no nodes in the linked list
    {
        h = n;
    }
    else//case 2 : linked list has some nodes
    {
        p =h;
        //traverse and stop at the last node
        while(p->next != NULL)
        {
            p = p->next;
        }
        //connect
        p->next = n;
    }
    return h;
}

node * deleteNodeAtTail(node *h)
{
    node * p, *q;
    
    if(h->next == NULL)//case1 : only one node in the linked list
    {
        p = h;
        h = NULL;
        free(p);
    }
    else//case2 : multiple nodes in the linked list
    {
        p = h;
        //traverse and stop at the last node
        while(p->next != NULL)
        {
            q = p;//maintain a shadow to p
            p = p->next;
        }
        //now p is at last node
        //and q is at node : last -1
                
        q->next = NULL;        
        free(p);
    }
    return h;
}
/*
 
 Sequential Search 
is applied on arrays and linked lists
as these are sequential data structures. 
 
It searches for a value in the target 
array/linked list by sequentially 
comparing the value with the element
content.  
 
As value is found 
 * search stops
 * index or address of the element is returned 
 
But if value is not found
 * search stops after comparing with entire array/linked list 
 * -1 or NULL is returned
 */
node * search(node *h, int val)
{//sequential search
    node *p;
    p = h;//begins with the first node
    
    while(p != NULL)//runs until end of the list
    {
        if(p->data == val)
        {
            return p;//found at node having address p
        }
        p = p->next;
    }//while
    return NULL;//not found
}

node * reverseList(node * h)
{
    node *a, *b, *c;
    c = NULL;
    
    a = h;
    while(a != NULL)
    {
        b = a;
        a = a->next;
        b->next = c;
        c = b;
    }
    
    return c;
}

int main()
{
	node *head, *p;
	int x;
	int ch;
	head = NULL;

	do
	{
		printf("\n 1. create list ");
		printf("\n 2. disp list ");
		printf("\n 3. disp list in reverse ");
		printf("\n 4. count nodes in list ");
		printf("\n 5. search a val in list ");
		printf("\n 6. add node at head ");
		printf("\n 7. add node in between ");
		printf("\n 8. add node at tail ");
		printf("\n 9. del node at head ");
		printf("\n 10. del node in between ");
		printf("\n 11. del node at tail ");
		printf("\n 12. reverse linked list");
		printf("\n 13. exit ");
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
				dispReverse(head);
				break;
			case 4:
				x = count(head);
				printf("\n No of nodes : %d ",x);
				break;
			case 5:
				printf("\n enter the value to be searched ");
                                scanf("%d", &x);
                                p = search(head, x);
                                if(p == NULL)
                                    printf("\n %d not found", x);
                                else
                                    printf("\n %d found",x);
				break;

			case 6:
				head = addNodeAtHead(head);
				break;
			case 7:
				addNodeInBetween(head);
				break;
			case 8:
				addNodeAtTail(head);
				break;
			case 9:
				head = deleteNodeAtHead(head);
				break;
			case 10:
				deleteNodeInBetween(head);
				break;
			case 11:
				head = deleteNodeAtTail(head);
				break;
			case 12:
                                head = reverseList(head);
                                break;
		}//switch
	}while(ch != 13);
  	return 0;
}//main
