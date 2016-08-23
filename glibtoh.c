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
#include <glib.h>
 
int no_moves;
GSList *src=NULL,*dest=NULL,*aux=NULL;
void DiskMove(GSList **from,GSList **to, char s,char d);

int main()
{
    // Input: number of disks
    printf("Enter no. of disks : ");
    unsigned int n;
    int i;
    scanf("%u",&n);
    GSList **psrc,**pdest,**paux;
    // Create three stacks of size 'n'
    // to hold the disks
    psrc=&src;
    pdest=&dest;
    paux=&aux;
    no_moves = (int)(pow(2, n)) - 1;

    //Larger disks will be pushed first    
    for (i = n; i >= 1; i--)
        src=g_slist_prepend (src,GINT_TO_POINTER(i));
    
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
          DiskMove(psrc, pdest, s, d);
 
        else if (i % 3 == 2)
          DiskMove(psrc, paux, s, a);
 
        else if (i % 3 == 0)
          DiskMove(paux, pdest, a, d);
    }

    printf("Total no. of steps required : %d\n", no_moves);
    return 0;
}


//To perform movements between the Pegs
void DiskMove(GSList **from,GSList **to, char s, char d)
{
    int disk1,disk2;
 
    // When pole 1 is empty
    if((*from)==NULL)
        disk1=-1;
    else
    {
        disk1=GPOINTER_TO_INT((*from)->data);
            *from=g_slist_remove(*from,(*from)->data);
    }

    if((*to)==NULL)                   
           disk2=-1;
       else{
           disk2=GPOINTER_TO_INT((*to)->data);              //poping out the value in destination
           *to=g_slist_remove(*to,(*to)->data);  
       }


    //when pole 1 is empty
    if (disk1 == -1)
    {
        *from=g_slist_prepend(*from,GINT_TO_POINTER(disk2));
        printf("Move the disk %d from Peg %c -> Peg %c\n",disk2, d, s);
    }
    // When pole2 pole is empty
    else if (disk2 == -1)
    {
        *to=g_slist_prepend(*to,GINT_TO_POINTER(disk1));
        printf("Move the disk %d from Peg %c -> Peg %c\n",disk1, s, d);
    }
 
    // When top disk of pole1 > top disk of pole2
    else if (disk1 > disk2)
    {
        *from=g_slist_prepend(*from,GINT_TO_POINTER(disk1));
        *from=g_slist_prepend(*from,GINT_TO_POINTER(disk2));
        printf("Move the disk %d from Peg %c -> Peg %c\n",disk2, d, s);
    }
    // When top disk of pole1 < top disk of pole2
    else
    {
        *to=g_slist_prepend(*to,GINT_TO_POINTER(disk2));
        *to=g_slist_prepend(*to,GINT_TO_POINTER(disk1));
        printf("Move the disk %d from Peg %c -> Peg %c\n",disk1, s, d);
    }
}
 
