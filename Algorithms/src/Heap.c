//#!/usr/bin/tcc -run
   /*
    * Heap Operations
    * incl. Build Max Heap,
    * Max Heapify, and
    * Heapsort
    */

//#include <stdio.h>

void Max_Heapify(int* A, int i, int n){
  int largest, tmp, j;
  int l = (2 * i) + 1;
  int r = (2 * i) + 2;
  if ((l < n) && (A[l] > A[i])) {
    largest = l;
  }
  else {
    largest = i;
  }
  if ((r < n) && (A[r] > A[largest])) {
    largest = r;
  }
  if (largest != i){
    tmp = A[i];
    A[i] = A[largest];
    A[largest] = tmp;
    /*for (j = 0; i < n; i++){
      printf("%d ",A[i]);
    }
    printf("\n");*/
    Max_Heapify(A,largest,n);
  }
}

void Build_Max_Heap(int* A, int n){
  int i;
  for (i = ((n-1) / 2); i >= 0; i--){
    Max_Heapify(A,i,n);
  }
  /*for (i = 0; i < n; i++){
    printf("%d ",A[i]);
  }
  printf("\n");*/
}

void Heapsort(int* A, int n){
  int i,tmp;
  int hpsize = n;
  Build_Max_Heap(A,n);  
  for (i = n-1; i >= 1; i--){
    tmp = A[i];
    A[i] = A[0];
    A[0] = tmp;
    hpsize--;
    Max_Heapify(A,0,hpsize);
  }
}

/*void main(){
  int i;
  int A[6] = {6,20,1,-1,99,37};
  int n = 6;
  Heapsort(A,n);
  for (i = 0; i < n; i++){
    printf("%d ",A[i]);
  }
  printf("\n");
}*/
