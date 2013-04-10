//#!/usr/bin/tcc -run
/*
 * Permute Array
 *
 *
 *
 */

//#include <time.h>
#include <stdlib.h>
//#include <stdio.h>

//void permute(int*, int);

/*int main(){
  int A[4] = {9,8,7,6};
  int n = 4;
  int i;
  srand(time(NULL));
  permute(A,n);
  for (i = 0; i < n; i++){
    printf("%d ",A[i]);
  }
  printf("\n");
}
*/

void permute(int *A, int n) {
  int i,r,temp;
  for (i = n-1; i > 0; i--) {
    r = rand() % i;
    temp = A[i];
    A[i] = A[r];
    A[r] = temp;
  }
}
