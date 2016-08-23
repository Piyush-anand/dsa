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
void DiscMove(int n, char source, char dest, char spare)
{
    if (n == 0)
    {
        return;
    }
    DiscMove(n-1, source, spare, dest);
    printf(" Move the disk %d from Peg %c -> Peg %c\n", n, source, dest);
    DiscMove(n-1, spare, dest, source);
}

int main()
{
	printf("Enter no. of disks : ");
	int n;
	scanf("%d",&n); // Number of disks
    DiscMove(n, 'A', 'C', 'B');  // A, B and C are names of Pegs

    printf("Total no. of steps required : %d",(int)(pow(2,n))-1);
    return 0;
}
