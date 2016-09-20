#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int **maker(int n,int m)
{
	int **a;
	a=(int **)malloc(n*sizeof(int *));
	int i,j;
	for(i=0;i<n;i++)
		a[i]=(int *)malloc(m*sizeof(int));

	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			a[i][j]=rand();
	return a;
}

void writer(int **mat,int n,int m,char *filename)
{
	FILE *fp=fopen(filename,"w");
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			fprintf(fp,"%d ",mat[i][j]);
		fprintf(fp,"\n");
	}
	fclose(fp);
}

void printDel(int **mat,int n,int m)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			printf("%d ",mat[i][j]);
		printf("\n");
	}

	for(i=0;i<n;i++)
		free(mat[i]);
	free(mat);
}

int main()
{
	int n,m;
	printf("Enter no. of rows and columns : \n" );
	scanf("%d %d",&n,&m);
	int **mat=maker(n,m);
	char *name;
	name=malloc(100);
	printf("enter the file name : ");
	scanf("%s",name);
	strcat(name,".txt");
	writer(mat,n,m,name);
	printDel(mat,n,m);
	return 0;
}