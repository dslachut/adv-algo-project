/*
 * Insertionsort.cc
 *
 *  Created on: Apr 9, 2013
 *      Author: david
 */

#include "Insertionsort.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>

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

void timeInsertionsort(){
	FILE *fp;
	fp = fopen("insertionsortResult.csv","w");
	//clock_t start,end;
	struct timeval s,e;
	for (int i = 1; i <= 134217728; i *= 2){
	for (int t = 0; t < 10; t++) {
		int* A = new int[i];
		for (int j = 0; j < i; j++){
			A[j] = rand() % i;
		}
		//start = clock();
		gettimeofday(&s, NULL);
		insertionsort(A,i);
		gettimeofday(&e, NULL);
		//end = clock();
		//cleanArray(A,i);
		delete[] A;
		A = 0;
		//fprintf(fp,"%d,%f\n",i,(double)(end-start)/CLOCKS_PER_SEC);
		fprintf(fp,"%d,%ld\n",i,((long int)e.tv_sec*1000000 + (long int)e.tv_usec)-
				((long int)s.tv_sec*1000000 + (long int)s.tv_usec));
		fclose(fp);
		fp = fopen("insertionsortResult.csv","a");
	}}
	fclose(fp);
}
