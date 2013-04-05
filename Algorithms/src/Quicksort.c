//#!/usr/bin/tcc -run
/*
 * Quicksort Array
 *
 *
 *
 */

//#include <time.h>
#include <stdlib.h>
//#include <stdio.h>

void swap(int* A, int a, int b){
  int tmp = A[a];
  A[a] = A[b];
  A[b] = tmp;
}

int partition(int* A, int l, int r) {
  int i,j,x;
  x = A[r];
  i = l - 1;
  for (j = l; j < r; j++) {
    if (A[j] <= x) {
      i++;
      swap(A,i,j);
    }
  }
  swap(A,i+1,r);
  return i+1;
}

int randPartition(int* A, int l, int r) {
  int i = l + rand() % (r-l);
  swap(A,i,r);
  return partition(A,l,r);
}

void quicksort(int* A, int l, int r) {
  int q;
  if (l < r){
    q = randPartition(A,l,r);
    quicksort(A,l,q-1);
    quicksort(A,q+1,r);
  }
}

/*int main() {
  int n = 10;
  int A[10] = {9,8,7,6,11,33,-1,5,8,12};
  int i;
  srand(time(NULL));
  quicksort(A,0,n-1);
  for (i = 0; i < n; i++){
    printf("%d ",A[i]);
  }
  printf("\n");
}*/