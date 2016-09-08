#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
	char data;
	struct node *ptr;
}stack;

stack *top=NULL;

void push(char ch);
char pop();

int main()
{
	char ch;

	do
	{
		printf("Please enter the string (or type 0 to exit) :");

		ch=getchar();
		while(ch!='\n')
		{
			if(ch=='0')
				exit(0);

			else if(ch=='(' || ch==')')
					push(ch);

			ch=getchar();
		}

	int flag=0;
	while(1)
	{
		char c=pop();
		if(c==')')
			flag++;
		else if(c=='(')
			flag--;
		else if(c=='e')
			break;

		if(flag<0)
		{
			printf("Unbalanced String\n");
			break;
		}
	}

		if(flag==0)
			printf("Balanced String\n");
		else if(flag>0)
			printf("Unbalanced String\n");

		while(top!=NULL)
			pop();

	}while(1);

	return 0;
}


void push(char ch)
{
	stack *temp;
	if(top==NULL)
	{
		temp=(stack *)malloc(1*sizeof(stack));
		temp->data=ch;
		temp->ptr=NULL;
		top=temp;
	}
	else
	{
		temp=(stack *)malloc(1*sizeof(stack));
		temp->data=ch;
		temp->ptr=top;
		top=temp;
	}
}

char pop()
{
	if(top==NULL)
		return 'e';
	else
	{
		char c=top->data;
		top=top->ptr;
		return c;
	}
}