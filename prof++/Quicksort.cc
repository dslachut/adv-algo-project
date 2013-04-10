/*
 * Quicksort.cc
 *
 *  Created on: Apr 9, 2013
 *      Author: david
 */

#include "Quicksort.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

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

void timeQuicksort(){
	FILE *fp;
	fp = fopen("quicksortResult.csv","w");
	clock_t start,end;
	for (int i = 1; i <= 268435456; i *= 2){
	for (int t = 0; t < 10; t++) {
		int* A = new int[i];
		for (int j = 0; j < i; j++){
			A[j] = rand() % i;
		}
		start = clock();
		quicksort(A,0,i-1);
		end = clock();
		//cleanArray(A,i);
		delete[] A;
		A = 0;
		fprintf(fp,"%d,%f\n",i,(double)(end-start)/CLOCKS_PER_SEC);
	}}
	fclose(fp);
}
