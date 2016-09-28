#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <sys/resource.h>
#include <math.h>
clock_t begin,end;	


int main(int argc, char const *argv[])
{
	struct rusage r_usage;
	printf("Please enter the value of N: ");
	int N;
	scanf("%d",&N);

	printf("Please enter the value of beta (Fixed) : ");
	int beta;
	scanf("%d",&beta);

	float a[N],b[N],d[N],r[N],deltaX,theta[N],thetaExact[N],error[N];
	//deltaX = (float)1/(N-1);
	

	printf("Writing the output in the result files..\n");
	begin =clock();

/*----------------------------------------------------------------------*/
	int i,j;
	for ( i = 1; i < N-1; ++i)
	{
		a[i] = pow(N-1,2);
		d[i] = -1*2*pow(N-1,2) - beta ;
		b[i] = pow(N-1,2);
		r[i] = 0;
	}
	a[0] = 0;
	a[N-1]=INT_MAX;
	b[0]= (float)INT_MAX ;
	b[N-1] = -1;
	d[0] = 1;
	d[N-1] = 1;
	r[0] = 1;
	r[N-1] = 0;

	
	// printf(" a[]    b[]   d[]   r[]\n");
	// for ( i = 0; i < N; ++i)
	// 	printf("%4d   %4d   %4d   %4d\n",(int)a[i],(int)b[i],(int)d[i],(int)r[i] );
	

	float ** array;
	array = (float **)malloc(N*sizeof(float *));

	for ( i = 0; i < N; ++i)
		array[i] = (float *)malloc(N*sizeof(float));

	for ( i = 0; i < N; ++i)
		for ( j = 0; j < N; ++j)
		{
			if(i == j)
			{
				array[i][j] = d[i] ;
			}
			

			else if(j == i-1 )
			{
				array[i][j] = b[i];
			}

			else if(j == i+1 )
			{
				array[i][j] = a[i];
			}

			else array[i][j] = 0;

		}

	// printf("\n\n");
	// for (i = 0; i < N; ++i)
	// {
	// 	for (j = 0; j < N; ++j)
	// 	{
	// 		printf("%4d ",(int)array[i][j]);
	// 	}
	// 	printf("\n");
	// }



	for ( i = 1; i < N; ++i)
	{
		d[i] = d[i] - a[i-1]*b[i]/d[i-1];
		r[i] = r[i] - r[i-1]*b[i]/d[i-1] ;
	}

	theta[N-1] = r[N-1]/d[N-1] ;
	
	for ( i = N-2; i >= 0; i--)
	{
		theta[i] = (r[i] - a[i]*theta[i+1])/d[i] ;
	}

	
	for ( i = 0; i < N; ++i)
	{
		thetaExact[i] = cosh(sqrt(beta)*(1-(float)(i+1)/N))/cosh(sqrt(beta));
		
	}

	for ( i = 0; i < N; ++i)
	{
		float sum = 0;
		for ( j = 0; j <= i; ++j)
		{
			sum += (thetaExact[j]-theta[j])*(thetaExact[j]-theta[j]);
		}
		error[i] = sqrt(sum/(i+1));
	}

	FILE* fp;
	fp = fopen("result.dat","w");
	for ( i = 0; i < N; ++i)
	{
		fprintf(fp, "%d\t%f\t%f\t%f\t%f\n",i+1,(float)(i+1)/N,theta[i],thetaExact[i],error[i]);
	}
	fclose(fp);
	
	// for (i = 0; i < N; ++i)
	// 	free(array[i]);

/*----------------------------------------------------------------------*/

	end=clock();
	double ThresholdingTime = ((end-begin)*1000)/CLOCKS_PER_SEC;
	printf("Time taken is %lf ms\n",(double)ThresholdingTime);


	getrusage(RUSAGE_SELF,&r_usage);
  	printf("Memory usage: %ld bytes\n",r_usage.ru_maxrss);

	char* commandsForGnuplot1[]={"set term x11","set title \"x* vs theta\"","set key outside","plot 'result.dat' using 2:3 with line"};
 	FILE *gnuplotPipeo1=popen("gnuplot -persistant","w");
 	int indo;
 	for (indo=0;indo<4;indo++)
	fprintf(gnuplotPipeo1, "%s \n", commandsForGnuplot1[indo]);
	pclose(gnuplotPipeo1);

	char* commandsForGnuplot2[]={"set term x11","set title \"x* vs thetaExact\"","set key outside","plot 'result.dat' using 2:4 with line"};
 	FILE *gnuplotPipeo2=popen("gnuplot -persistant","w");
 	for (indo=0;indo<4;indo++)
	fprintf(gnuplotPipeo2, "%s \n", commandsForGnuplot2[indo]);
	pclose(gnuplotPipeo2);
	
	char* commandsForGnuplot3[]={"set term x11","set title \"N vs Error\"","set key outside","plot 'result.dat' using 1:5 with line"};
 	FILE *gnuplotPipeo3=popen("gnuplot -persistant","w");
 	for (indo=0;indo<4;indo++)
	fprintf(gnuplotPipeo3, "%s \n", commandsForGnuplot3[indo]);
	pclose(gnuplotPipeo3);

	


	return 0;
}