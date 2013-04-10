//#!/usr/bin/tcc -run
/* 
 * Binary search in sorted array
 * 
 * 
 * 
 */

//#include <stdio.h>

int binarysearch(int* A, int l, int r, int n){
  int m = (r + l) / 2;
  if (((l == r) && (A[m] != n)) || l > r) {
    return -1;
  }
  else if (A[m] == n) {
    return m;
  }
  else if (A[m] < n) {
    return binarysearch(A,m+1,r,n);
  }
  else {
    return binarysearch(A,l,m-1,n);
  }
}

/*
int main() {
  int n = 10;
  int A[10], i;
  for (i = 0; i < n; i++){
    A[i] = i + 1;
    printf("%d ", A[i]);
  }
  printf("\n");
  for (i = 0; i < 12; i++){
    printf("%d at location %d\n",i,binarysearch(A,0,n-1,i));
  }
}*/