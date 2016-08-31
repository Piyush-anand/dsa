#include "my_lib.h"

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
        printf("The person at position %d is removed.\n", p->num);
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