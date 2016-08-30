#include <stdio.h>
#include <stdlib.h>

struct node
{
    int num;
    struct node *next;
};

void printq(struct node *);
int play(struct node **, int);
 
int main()
{
    struct node *queue = NULL,*temp,*rear;
    int live;
    int j,n,i;
 
 	printf("Enter value of n and i : ");
 	scanf("%d",&n);
 	scanf("%d",&i);
    temp = (struct node *)malloc(sizeof(struct node));
 	for(j=1;j<=n;j++)
 	{
    	temp->num = j;
        temp->next = NULL;
        if (queue == NULL)
        {
            queue = temp;
        }
        else
        {
            rear->next = temp;
        }
        rear = temp;
    }
    rear->next=queue;


    //printq(queue);
    live = play(&queue, i);
    printf("The person to survive is : %d\n", live);
    free(queue);
 
    return 0;
}
 
int play(struct node **queue, int k)
{
    struct node *p, *q;
    int i;
 
    q = p = *queue;
    while (p->next != p)
    {
        for (i = 1; i < k; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        printf("%d has been killed.\n", p->num);
        free(p);
        p = q->next;
    }
    *queue = p;
 
    return (p->num);
}
 
void printq(struct node *queue)
{
    struct node *temp;
 
    temp = queue;
    printf("%d   ", temp->num);
    temp = temp->next;
    while (queue != temp)
    {
        printf("%d   ", temp->num);
        temp = temp->next;
    }
    printf("\n");
}