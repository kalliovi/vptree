#include <stdio.h>
#include <stdlib.h>
#include "vptree.h"
#include <math.h>
#include <sys/time.h>
#include <time.h>



int main(){
    {
    int n;
    double* X;
    int d;
	int i, j ;
	FILE *fptr;
    fptr = fopen("ndtimes.txt","a");

    if(fptr == NULL) {
        printf("Error!");
        exit(1);
    }

	printf("Enter the point of the matrix: ");
    scanf("%d", &n);
    fprintf(fptr,"%d\n",n);
    printf("Enter the dimension of the matrix: ");
    scanf("%d", &d);
    fprintf(fptr,"%d\n",d);
    X= (double *)malloc(n*d*sizeof(double));
    for(i = 0; i < n;i++) {
    	for(j = 0; j < d;j++) {
			X [i*d+j]=((float)rand()/(float)(RAND_MAX)) * 10000;
     }
   struct timeval start, end;
    gettimeofday(&start, NULL);
    sleep(3);
    gettimeofday(&end, NULL);
			double elapsed = end.tv_sec + end.tv_usec / 1e6 -
                        start.tv_sec - start.tv_usec / 1e6;


                //printf("%d ", rand()%10000);
 printf("time program took %f seconds to execute\n", elapsed);
fprintf(fptr,"%f\n",elapsed);
return 0;
  }
  vptree * buildvp(double *X, int n, int d);
  fclose(fptr);
  return 0;
}
}
