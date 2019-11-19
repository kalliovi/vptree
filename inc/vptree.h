#include <stdio.h>
#ifndef VPTREE_H
#define VPTREE_H

//!n = 100000; d = 2; % works for any d
//This is a a two dimensional matrix 100000x2
//!X = rand(n,d);
//! A vantage point is a random point/potition in this matrix above

//! type definition of vptree
typedef struct vptree {
  // Array of size d containing the point's coordinates
  double * vp;
  // Median distance of point from all other points
  double median;
  // Index of point in original n*d matrix
  int index;
  // Inner and outer subtrees
 struct vptree *inner; //pointer inside
 struct vptree *outer; // pointer outside

} vptree ;
// ========== LIST OF ACCESSORS
vptree *vpt(int *index,double *X,int n,int d);

vptree * buildvp(double *X, int n, int d);

double quickselect(int *idx,double* A, int left, int right, int k);

vptree * getInner(vptree * T);

vptree * getOuter(vptree * T);

double getMD(vptree * T);

double * getVP(vptree * T);

int getIDX(vptree * T);
#endif



