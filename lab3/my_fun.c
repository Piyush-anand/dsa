#include "my_lib.h"

void create()
{
    top1 = top2 = -1;
}

void push1(int data)
{
    st1[++top1] = data;
}

int pop1()
{
    return(st1[top1--]);
}

void push2(int data)
{
    st2[++top2] = data;
}

int pop2()
{
    return(st2[top2--]);
}

void enqueue()
{
    int data, i;
 
    printf("Enter data to be entered in queue");
    scanf("%d", &data);
    push1(data);
    count++;
}

void dequeue()
{
    int i;
 
 	if(top1==-1 && top2==-1)
 	{
 		printf("error .. queue is empty\n");
 		return;
 	}
 	else
 	{
    	for (i = 0;i <= count;i++)
    	{
        	push2(pop1());
    	}

    	pop2();
    	count--;
    	
    	for (i = 0;i <= count;i++)
    	{
        	push1(pop2());
    	}
	}
}