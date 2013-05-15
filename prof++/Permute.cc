#include "Permute.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>


void permute(int *A, int n) {
  int i,r,temp;
  for (i = n-1; i > 0; i--) {
    r = rand() % i;
    temp = A[i];
    A[i] = A[r];
    A[r] = temp;
  }
}

void timePermute(){
	FILE *fp;
	fp = fopen("permuteResult.csv","w");
	//clock_t start,end;
	struct timeval s,e;
	for (int i = 1; i <= 268435456; i *= 2){
	for (int t = 0; t < 10; t++) {
		int* A = new int[i];
		for (int j = 0; j < i; j++){
			A[j] = j;
		}
		//start = clock();
		gettimeofday(&s, NULL);
		permute(A,i);
		gettimeofday(&e, NULL);
		//end = clock();
		//cleanArray(A,i);
		delete[] A;
		A = 0;
		//fprintf(fp,"%d,%f\n",i,(double)(end-start)/CLOCKS_PER_SEC);
		fprintf(fp,"%d,%ld\n",i,(e.tv_sec*1000000 + e.tv_usec)-(s.tv_sec*1000000 + s.tv_usec));
	}}
	fclose(fp);
}
