#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *ptr;
}node;

typedef struct queue
{
	node *front;
	node *rear;
}queue;

queue q1,q2;

void pop();
void push(int );
void disp();

int main()
{
	int ch,n,i;
	q1.front=q1.rear=q2.front=q2.rear=NULL;

	while(1)
	{
		printf("1: Push\n2: Pop\n3: Display \n4: Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
				case 1:	
						printf("Enter value to be pushed: ");
						scanf("%d",&n);
						push(n);
						break;

				case 2: 
						pop();
						break;

				case 3: 
						disp();
						break;

				case 4: 
						exit(0);
						break;

				default:
						printf("Wrong Choice.... Try Again\n");

		}
	}

	return 0;
}

void push(int n)
{
	node *temp;
	if(q2.front==NULL)
	{
		temp=(struct node *)malloc(1*sizeof(struct node));
		temp->data=n;
		temp->ptr=NULL;
		q2.rear=temp;
		// q2.rear->ptr = NULL;
        // q2.rear->data = n;
        q2.front = q2.rear;
	}

	else
	{
		temp=(struct node *)malloc(1*sizeof(struct node));
        q2.rear->ptr = temp;
        temp->data = n;
       	temp->ptr = NULL;
	    q2.rear = temp;
	}

	while(q1.front!=NULL)
	{
		int k=q1.front->data;
		temp=(struct node *)malloc(1*sizeof(struct node));
        q2.rear->ptr = temp;
        temp->data = k;
       	temp->ptr = NULL;
	    q2.rear = temp;
	    q1.front=q1.front->ptr;
	}
	q1=q2;
	q2.front=q2.rear=NULL;
}

void pop()
{
	int k;
	if(q1.front==NULL)
		printf("empty stack.. \n");
	else
	{	
		k=q1.front->data;
		q1.front=q1.front->ptr;
		printf("Popped Element : %d\n",k);
	}
}

void disp()
{
	queue temp;
	temp.front=q1.front;
	if(temp.front==NULL)
	{
		printf("Empty stack ....\n");
		return;
	}
	printf("Elements of stack are : \n");
	while(temp.front!=NULL)
	{
		printf("%d   ",temp.front->data);
		temp.front=temp.front->ptr;
	}
	printf("\n");
}