#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}stack;

void rev();
void push(int );
void disp();


stack *head=NULL,*prev,*current,*next,*temp;

int main()
{
		int n,k,i;
		printf("enter number of inputs: ");
		scanf("%d",&n);
		printf("Enter elements: \n");
		for(i=0;i<n;i++)
		{
			scanf("%d",&k);
			push(k);
		}
       //pushlist

		printf("In Original Format: \n");
        disp();
        
        printf("\nReversed Linked list \n");
        rev();
        disp();

        getchar();
        
}

void push(int data)
{
    /* allocate node */
    stack *new_node = (struct node*) malloc(sizeof(struct node));

    /* put in the data  */
    new_node->data  = data;

    /* link the old list off the new node */
    new_node->next = NULL;

    /* move the head to point to the new node */
    if(head == NULL)	
    	head = new_node;
    else
    {
    	temp=head;
    	while(temp->next!=NULL)
    	{
    		temp=temp->next;
    	}
    	temp->next=new_node;
    }
}

void rev()
{
    prev   = NULL;
    current = head;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head= prev;
}

void disp()
{
    temp = head;
    while(temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}