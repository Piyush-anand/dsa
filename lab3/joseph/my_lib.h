#include <stdio.h>
#include <stdlib.h>

struct node
{
    int num;
    struct node *next;
};

void printq(struct node *);
int play(struct node **, int);
