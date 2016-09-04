#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char info;
	struct node *ptr;
}stack;

stack *head=NULL,*temp,*top1;
int count=0;

int isempty();
char pop();
void push(char ch);

int main()
{
	int l,i;
	char str[100];

	do
	{
		printf("Please enter the string (or type 0 to exit) :");
		scanf("%s",str);
		
		if(str[0]=='0')
			exit(0);

		l=strlen(str);
			
		for(i=0;i<l;i++)
			push(str[i]);

		int flag=1;

		for(i=0;i<l;i++)
		{	
			if(!isempty())
			{
				if(pop()!=str[i])
				{
					flag=0;
					break;
				}
			}
		}

			if(flag)
			printf("Palindrome\n");
		else
			printf("Not Palindrome\n");

		
	}while(1);
}

int isempty()
{
	if (head == NULL)
    {
        printf("Stack is empty");
        return 1;
    }
    return 0;
}

void push(char data)
{
    if (head == NULL)
    {
        head =(struct node *)malloc(1*sizeof(struct node));
        head->ptr = NULL;
        head->info = data;
    }
    else
    {
        temp =(struct node *)malloc(1*sizeof(struct node));
        temp->ptr = head;
        temp->info = data;
        head = temp;
    }
}

char pop()
{
    top1 = head;
    top1 = top1->ptr;
    char c=head->info;
    free(head);
    head = top1;
    return c;
}