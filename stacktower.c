/*

*******************************************************************
    Name : Piyush Anand
    Roll no: B15226
    Purpose: IC250 Assignment 01
    Date: 17/08/2016
*******************************************************************

*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
 
// A structure to represent a stack
struct Stack
{
   unsigned capacity;
   int top;
   int *array;
};
 
// function to create a stack of given capacity.
struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack =
        (struct Stack*) malloc(sizeof(struct Stack));
    stack -> capacity = capacity;
    stack -> top = -1;
    stack -> array =
        (int*) malloc(stack -> capacity * sizeof(int));
    return stack;
}
 
// Stack is full when top is equal to the last index
int isFull(struct Stack* stack)
{
   return (stack->top == stack->capacity - 1);
}
 
// Stack is empty when top is equal to -1
int isEmpty(struct Stack* stack)
{
   if(stack->top == -1)
      return 1;
    else
      return 0;
}
 
// Function to add an item to stack.  It increases
// top by 1
void push(struct Stack *stack, int value)
{
    if (isFull(stack))
        { printf("stack full.. Cant push element \n");
          return;
        }
    stack -> array[++stack -> top] = value;
}
 
// Function to remove an item from stack.  It
// decreases top by 1
int pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return -1;
    return stack -> array[stack -> top--];
}
 
 int no_moves;
struct Stack *src, *dest, *aux;
void DiskMove(struct Stack *from,struct Stack *to, char s,char d);
void tower(int n);

int main()
{
    // Input: number of disks
    printf("Enter no. of disks : ");
    unsigned int n;
    int i;
    scanf("%u",&n);
    // Create three stacks of size 'n'
    // to hold the disks
    src = createStack(n);
    aux = createStack(n);
    dest = createStack(n);
    no_moves = (int)(pow(2, n)) - 1;

    //Larger disks will be pushed first    
    for (i = n; i >= 1; i--)
        push(src, i);
    
    tower(n);

    printf("Total no. of steps required : %d\n", no_moves);
    return 0;
}
//Function to implement TOH puzzle
void tower(int n)
{
    int i;
    char s = 'A', d = 'C', a = 'B';
 
    //If number of disks is even, then interchange
    //destination pole and auxiliary pole
    if (n % 2 == 0)
    {
        char temp = d;
        d = a;
        a  = temp;
    }
     
    for (i = 1; i <= no_moves; i++)
    {
        if (i % 3 == 1)
          DiskMove(src, dest, s, d);
 
        else if (i % 3 == 2)
          DiskMove(src, aux, s, a);
 
        else if (i % 3 == 0)
          DiskMove(aux, dest, a, d);
    }
}

//To perform movements between the Pegs
void DiskMove(struct Stack *from,struct Stack *to, char s, char d)
{
    int disk1 = pop(from);
    int disk2 = pop(to);
 
    // When pole 1 is empty
    if (disk1 == -1)
    {
        push(from, disk2);
        printf("Move the disk %d from Peg %c -> Peg %c\n",disk2, d, s);
    }
 
    // When pole2 pole is empty
    else if (disk2 == -1)
    {
        push(to, disk1);
        printf("Move the disk %d from Peg %c -> Peg %c\n",disk1, s, d);
    }
 
    // When top disk of pole1 > top disk of pole2
    else if (disk1 > disk2)
    {
        push(from, disk1);
        push(from, disk2);
        printf("Move the disk %d from Peg %c -> Peg %c\n",disk2, d, s);
    }
    // When top disk of pole1 < top disk of pole2
    else
    {
        push(to, disk2);
        push(to, disk1);
        printf("Move the disk %d from Peg %c -> Peg %c\n",disk1, s, d);
    }
}
 