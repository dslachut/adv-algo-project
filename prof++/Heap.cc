/*
 * Heap.cc
 *
 *  Created on: Apr 9, 2013
 *      Author: david
 */

#include "Quicksort.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void Max_Heapify(int* A, int i, int n){
  int largest, tmp;
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
    Max_Heapify(A,largest,n);
  }
}

void Build_Max_Heap(int* A, int n){
  int i;
  for (i = ((n-1) / 2); i >= 0; i--){
    Max_Heapify(A,i,n);
  }
}

void heapsort(int* A, int n){
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

void timeHeapsort(){
	FILE *fp;
	fp = fopen("heapsortResult.csv","w");
	clock_t start,end;
	for (int i = 1; i <= 268435456; i *= 2){
	for (int t = 0; t < 10; t++) {
		int* A = new int[i];
		for (int j = 0; j < i; j++){
			A[j] = rand() % i;
		}
		start = clock();
		heapsort(A,i);
		end = clock();
		//cleanArray(A,i);
		delete[] A;
		A = 0;
		fprintf(fp,"%d,%f\n",i,(double)(end-start)/CLOCKS_PER_SEC);
	}}
	fclose(fp);
}
