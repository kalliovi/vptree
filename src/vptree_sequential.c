#include <stdio.h>
#include <stdlib.h>
#include "vptree.h"
#include <math.h>


vptree * buildvp(double *X, int n, int d){
  int * index = malloc(n*sizeof(int)); //!Krataw index
  for (int i=0; i<n; i++)
  {
    index[i] = i;
  }
  vptree *tree = vpt(index,X,n,d);
  return tree;
} //!Na thn!!!H synartish toy
vptree *vpt(int *index,double *X,int n,int d){ //!Aftin exei kai ton index mallon gia ayto thn thelw thn evala kai sto .h
    if(n <= 0)
    {
    return NULL;

	}
	if(n==1){
		vptree *tree = (vptree *)malloc(sizeof(vptree));
		tree->median=0; //! den exei median pio katw einai teleutaio simio
		tree->vp=&X[index[n-1]*d];
		tree->index=index[n-1];
		tree->inner=NULL;
		tree->outer=NULL;
		return tree;
	}
    else{
		vptree *tree = (vptree *)malloc(sizeof(vptree));
        double *distance=(double *)malloc((n-1)*sizeof(double)); //!Metraw apostaseis
        for(int i=0;i<n-1;i++){
            double temp=0;
            for(int j=0;j<d;j++){
                temp+=(X[index[n-1]*d+j]-X[index[i]*d+j])*(X[index[n-1]*d+j]-X[index[i]*d+j]);
            }
                distance[i]=sqrt(temp);
        }
        int k=floor((n-1)/2);
        tree->index=index[n-1];
        tree->vp=&X[index[n-1]*d];
        tree->median=quickselect(index,distance,0,n-2,k);
        tree->inner=vpt(index,X,k,d);
        tree->outer=vpt(&index[k],X,n-k-1,d);
	    return tree;
    }

}

void dswap(double *a, double *b){ //!Kanw swap double
    double temp = *a;
    *a = *b;
    *b = temp;
}
void iswap(int *a, int *b){ //!swap tous index
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int * index,double*A, int left, int right){

    double pivot = A[right];
    int  i = left, x;
    for(x = left; x < right; x++){
        if (A[x] <= pivot){
            dswap(&A[i], &A[x]);
            iswap(&index[i],&index[x]);
            i++;
        }
    }
    dswap(&A[i], &A[right]);
    iswap(&index[i],&index[right]);
    return i;
}

double quickselect(int *idx,double* A, int left, int right, int k)
{
    if (k > 0 && k <= right - left + 1)
    {
        int index = partition(idx,A, left, right);

        if (index - left == k - 1)
            return A[index];

        if (index - left > k - 1)
            return quickselect(idx,A, left, index - 1, k);

        return quickselect(idx,A, index + 1, right, k - index + left - 1);
    }

    return 0;
}

vptree * getInner(vptree * T){
return T->inner ;
}
vptree * getOuter(vptree * T){
return T->outer;
}
double getMD(vptree * T){
return T->median;
}
double * getVP(vptree * T){
return T->vp;
}
int getIDX(vptree * T){
return T->index;
}
