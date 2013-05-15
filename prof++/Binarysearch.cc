/*
 * Binarysearch.cc
 *
 *  Created on: Apr 9, 2013
 *      Author: david
 */

#include "Binarysearch.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>

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

void timeBinarysearch() {
	FILE *fp;
	fp = fopen("binarysearchResult.csv","w");
	//clock_t start,end;
	struct timeval s,e;
	int toFind,foundAt;
	for (int i = 1; i <= 536870912; i *= 2){
	for (int t = 0; t < 10; t++) {
		int* A = new int[i];
		for (int j = 0; j < i; j++){
			A[j] = j+1;
		}
		toFind = (rand() % ((3 * i)/2)) - (i/3);
		//start = clock();
		gettimeofday(&s, NULL);
		foundAt = binarysearch(A,0,i-1,toFind);
		gettimeofday(&e, NULL);
		//end = clock();
		//cleanArray(A,i);
		delete[] A;
		A = 0;
		//fprintf(fp,"%d,%f,\tfound %d at position %d\n",i,(double)(end-start)/CLOCKS_PER_SEC,toFind,foundAt);
		fprintf(fp,"%d,%ld,\tfound %d at position %d\n",i,(e.tv_sec*1000000 + e.tv_usec)-(s.tv_sec*1000000 + s.tv_usec,toFind,foundAt));
	}}
	fclose(fp);

}
