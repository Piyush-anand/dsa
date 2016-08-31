#include "my_lib.h"

// int st1[100], st2[100];
// int count = 0;
 
GSList *st1=NULL,*st2=NULL;
void main()
{
    GSList **ps1,**ps2;
    ps1=&st1;
    ps2=&st2;
    int ch;
 
    printf("\n1 - Enqueue element into queue");
    printf("\n2 - Remove element from queue");
    printf("\n3 - Print queue elements");
    printf("\n4 - Exit");
    // create();
    while (1)
    {
        printf("\nEnter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue(ps1);
            break;
        case 2:
            dequeue(ps1,ps2);
            break;
        case 3:
            display(ps1,ps2);
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong choice");
        }
    }
}

