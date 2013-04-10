#!/usr/bin/tcc -run
/*
 ============================================================================
 Name        : Algorithms.c
 Author      : David Lachut
 Version     :
 Copyright   : Copyleft David Lachut GPLv3
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Binarysearch.c"
#include "Heap.c"
#include "Insertionsort.c"
#include "Permute.c"
#include "Quicksort.c"

void fillArray(int* A, int n) {
	int i;
	for (i = 0; i < n; i++) {
		A[i] = i;
	}
}

void timePermute() {
	int A[2], B[4], C[8], D[16], E[32], F[64], G[128];
	int H[256], I[512], J[1024], K[2048], L[4096];
	int M[8192], N[16384], O[32768];
	clock_t start,end;
	FILE *fp;
	fp = fopen("permuteResult.csv","w");

	fillArray(A,2);
	start = clock();
	permute(A,2);
	end = clock();
	fprintf(fp,"%d,%f\n",2,((double)(end-start))/((double)CLOCKS_PER_SEC));

	fillArray(B,4);
	start = clock();
	permute(B,4);
	end = clock();
	fprintf(fp,"%d,%f\n",4,((double)(end-start))/((double)CLOCKS_PER_SEC));

	fillArray(C,8);
	start = clock();
	permute(C,8);
	end = clock();
	fprintf(fp,"%d,%f\n",8,((double)(end-start))/((double)CLOCKS_PER_SEC));

	fillArray(D,16);
	start = clock();
	permute(D,16);
	end = clock();
	fprintf(fp,"%d,%f\n",16,((double)(end-start))/((double)CLOCKS_PER_SEC));

	fillArray(E,32);
	start = clock();
	permute(E,32);
	end = clock();
	fprintf(fp,"%d,%f\n",32,((double)(end-start))/((double)CLOCKS_PER_SEC));

	fillArray(F,64);
	start = clock();
	permute(F,64);
	end = clock();
	fprintf(fp,"%d,%f\n",64,((double)(end-start))/((double)CLOCKS_PER_SEC));

	fillArray(G,128);
	start = clock();
	permute(G,128);
	end = clock();
	fprintf(fp,"%d,%f\n",128,((double)(end-start))/((double)CLOCKS_PER_SEC));

	fillArray(H,256);
	start = clock();
	permute(H,256);
	end = clock();
	fprintf(fp,"%d,%f\n",256,((double)(end-start))/((double)CLOCKS_PER_SEC));

	fillArray(I,512);
	start = clock();
	permute(I,512);
	end = clock();
	fprintf(fp,"%d,%f\n",512,((double)(end-start))/((double)CLOCKS_PER_SEC));

	fillArray(J,1024);
	start = clock();
	permute(J,1024);
	end = clock();
	fprintf(fp,"%d,%f\n",1024,((double)(end-start))/((double)CLOCKS_PER_SEC));

	fillArray(K,2048);
	start = clock();
	permute(K,2048);
	end = clock();
	fprintf(fp,"%d,%f\n",2048,((double)(end-start))/((double)CLOCKS_PER_SEC));

	fillArray(L,4096);
	start = clock();
	permute(L,4096);
	end = clock();
	fprintf(fp,"%d,%f\n",4096,((double)(end-start))/((double)CLOCKS_PER_SEC));

	fillArray(M,8192);
	start = clock();
	permute(M,8192);
	end = clock();
	fprintf(fp,"%d,%f\n",8192,((double)(end-start))/((double)CLOCKS_PER_SEC));

	fillArray(N,16384);
	start = clock();
	permute(N,16384);
	end = clock();
	fprintf(fp,"%d,%f\n",16384,((double)(end-start))/((double)CLOCKS_PER_SEC));

	fillArray(O,32768);
	start = clock();
	permute(O,32768);
	end = clock();
	fprintf(fp,"%d,%f\n",32768,((double)(end-start))/((double)CLOCKS_PER_SEC));

	fclose(fp);
}

int main(void) {
	srand(time(NULL));
	timePermute();
}
