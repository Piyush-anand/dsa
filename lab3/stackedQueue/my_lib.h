#ifndef pops
#define pops
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <glib.h>




void push(GSList **ps, int data);
int pop(GSList **ps);
void enqueue(GSList **ps1);
void dequeue(GSList **ps1,GSList **ps2);
void display(GSList **ps1,GSList **ps2);

#endif 