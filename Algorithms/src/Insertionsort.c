//#!/usr/bin/tcc -run
/*
 * Insertionsort Array
 *
 *
 *
 */

//#include <time.h>
//#include <stdlib.h>
//#include <stdio.h>



void insertionsort(int* A, int n) {
  int i,j,k;
  for (i = 1; i < n; i++) {
    k = A[i];
    j = i - 1;
    while ((j >= 0) && (A[j] > k)) {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = k;
  }
}

/*int main() {
  int n = 10;
  int A[10] = {9,8,7,6,11,33,-1,5,8,12};
  int i;
  srand(time(NULL));
  insertionsort(A,n);
  for (i = 0; i < n; i++){
    printf("%d ",A[i]);
  }
  printf("\n");
}*/