#include "my_lib.h"

int main()
{
    struct node *queue = NULL,*temp,*rear;
    int live;
    int j,n,i;
 
 	printf("Enter value of n and i : ");
 	scanf("%d",&n);
 	scanf("%d",&i);
    struct node **ptr;
    ptr=&queue;
    
 	for(j=1;j<=n;j++)
 	{
 		temp = (struct node *)malloc(sizeof(struct node));
    	temp->num = j;
        temp->next = NULL;
        if (*ptr == NULL)
        {
            *ptr = temp;
        }
        else
        {
            rear->next = temp;
        }
        rear = temp;
    }
    rear->next=*ptr;;


    //printq(queue);
    live = play(&queue, i);
    printf("Hence the person at position %d survives. (WINNER) \n", live);
    free(queue);
 
    return 0;
}