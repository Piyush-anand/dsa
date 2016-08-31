#ifndef my_fun
#define my_fun
#include "my_lib.h"

int count =0;


void push(GSList **ps, int data)
{
    *ps=g_slist_prepend (*ps,GINT_TO_POINTER(data));
}

int pop(GSList **ps)
{   
    int k;
    k=GPOINTER_TO_INT((*ps)->data);;
    *ps=g_slist_remove(*ps,(*ps)->data);
    return k;
}

void enqueue(GSList **ps1)
{
    int data, i;
 
    printf("Enter data to be entered in queue");
    scanf("%d", &data);
    push(ps1,data);
    count++;
}

void dequeue(GSList **ps1,GSList **ps2)
{
    int i,k;
 
    if((*ps1)==NULL)
    {
        printf("error .. queue is empty\n");
        return;
    }
    else
    {
        for (i = 0;i < count;i++)
        {
            push(ps2,pop(ps1));
        }

        k=pop(ps2);
        printf("Popped element : %d\n ",k);
        count--;
        
        for (i = 0;i <count;i++)
        {
            push(ps1,pop(ps2));
        }
    }
}

void display(GSList **ps1,GSList **ps2)
{
    int i,k;
    if((*ps1)==NULL)
    {
        printf("error .. queue is empty\n");
        return;
    }
    else
    {
        for (i = 0;i < count;i++)
        {
            push(ps2,pop(ps1));
        }

        for (i = 0;i < count;i++)
        {
            k=pop(ps2);
            printf("%d ", k);
            push(ps1,k);
        }
    }
}

#endif