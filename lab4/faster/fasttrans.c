#include <stdio.h>
#include <stdlib.h>

int r,c;

void trans(int **b,int **c1);
void disp(int **m,int row,int col);

int main()
{
	int i,j,k=1;
	int **a;
	int **b,**c1;
	printf("Enter no. of rows and columnn : \n");
	scanf("%d%d",&r,&c);

	a=(int **)malloc(r*(sizeof(int*)));
	for(i=0;i<r;i++)
		a[i]=(int *)malloc(c * sizeof(int));

	printf("Enter elements : \n");
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			{
				scanf("%d",&a[i][j]);
				if(a[i][j]!=0)
					k++;
			}

	b=(int **)malloc((k)*sizeof(int *));
	for(i=0;i<k;i++)
		b[i]=(int *)malloc(3*sizeof(int));

	c1=(int **)malloc((k)*sizeof(int *));
	for(i=0;i<k;i++)
		c1[i]=(int *)malloc(3*sizeof(int));


	b[0][0]=r;
	b[0][1]=c;
	b[0][2]=k-1;
	k=1;
	for(i=0;i<r;i++)
	{	
		for(j=0;j<c;j++)
		{
			if(a[i][j]!=0)
			{
				b[k][0]=i;
				b[k][1]=j;
				b[k][2]=a[i][j];
				k++;
			}
		}
	}

	printf("The original matrix : \n");
  	disp(a,r,c);

  	printf("The sparse matrix : \n");
  	disp(b,k,3);

  	printf("Transpose of sparse matrix : \n");
  	trans(b,c1);
  	disp(c1,k,3);

  	return 0;
}

void trans(int **b,int **c1)
{
     int i,j,m,n;
     int *pos,*count;

     pos=(int *)malloc(c*sizeof(int));
     count=(int *)malloc(c*sizeof(int));
     
     for(i=0;i<c;i++)
     {
     	pos[i]=count[i]=0;
     }

     for (i=1;i<=b[0][2];i++)
     {
       		m = b[i][1];
       		count[m]++;
     }

     pos[0] = 1;
     for (i=1;i<b[0][1];i++)
     {
      		pos[i] = pos [i-1] + count[i-1];
     }

     for (i=1;i<=b[0][2];i++)
     {
      		m = b[i][1];
      		n= pos[m];
      		pos[m]++;
      		c1[n][0] = b[i][1];
      		c1[n][1] = b[i][0];
      		c1[n][2] = b[i][2];
     }

    c1[0][1] = b[0][0];
    c1[0][0] = b[0][1];
    c1[0][2] = b[0][2];
}

void disp(int **m,int row,int col)
{
     int i,j;
     for(i=0;i<row;i++){
     for (j=0;j<col;j++){
       printf("%d\t",m[i][j]);
     }
     printf("\n");
     }
}
