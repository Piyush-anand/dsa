#include <stdio.h>
#include <stdlib.h>

void swapPointer(int *a, int *b);
void printPointerValue(int *a);
int compareInts(int *a,int *b);
int compareStrings(char *a, char *b);
void countTillThisNum(int num);

int main()
{
	int a,b;
	int ch;
	printf("1: Swap\n2:Print\n3:Compare Integers\n4:Compare Strings\n5:Print till NUM\n");
	printf("Enter your choice : ");
	scanf("%d",&ch);

	switch(ch)
	{
		case 1: printf("Enter two numbers : \n");
				scanf("%d %d",&a,&b);
				printf("Before swapping :\na=%d\tb=%d\n",a,b);
				swapPointer(&a,&b);
				printf("After swapping :\na=%d\tb=%d\n",a,b);
				break;

		case 2: printf("Enter a no. to be printed : ");
				scanf("%d",&a);
				printPointerValue(&a);
				break;

		case 3: printf("Enter two numbers");
				scanf("%d %d",&a,&b);
				printf("Output = %d\n",compareInts(&a,&b));
				break;

		case 4: 
				printf("enter two strings : \n");
				char *a1,*b1;
				a1=malloc(100);
				b1=malloc(100);
				scanf("%s %s",a1,b1);
				// printf("%s %s",a1,b1);
				printf("output = %d\n",compareStrings(a1,b1));
				break;

		case 5: printf("enter Num :");
				scanf("%d",&a);
				countTillThisNum(a);
				break;

		default: printf("Wrong Input\n");

	}

	return 0;
}

void swapPointer(int *a,int *b)
{
	int c;
	c=*a;
	*a=*b;
	*b=c;
}

void printPointerValue(int *a)
{
	printf("%d\n",*a);
}

int compareInts(int *a,int *b)
{
	if(*a > *b)
		return 1;
	else
		return 0;
}

int compareStrings(char *a,char *b)
{
	int flag=0;
	while(*a!='\0' && *b!='\0')
	{
		// printf("%c %c", *a,*b);
		if(*a>*b)
		{
			flag=1;
			printf("he");
			break;
		}
		else if(*a<*b)
		{
			flag=-1;
			// printf("hey");
			break;
		}
		a++;
		b++;
	}
	// if(*a=='\0' && *b!='\0')
	{
		flag=-1;
		// printf("hea");
	}
	if(*a!='\0' && *b=='\0')
	{
		// printf("heo");
		flag=1;
	}

	return flag;
}

void countTillThisNum(int num)
{
	int *a,b;
	b=1;
	a=&b;
	while((*a)<=num)
	{
		printPointerValue(a);
		// printf("%d ",*a);
		(*a)++;
	}
}
