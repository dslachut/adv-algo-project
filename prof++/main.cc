
/*
 ============================================================================
 Name        : main.cc
 Author      : David Lachut
 Version     :
 Copyright   : Copyleft David Lachut GPLv3
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Binarysearch.h"
#include "Heap.h"
#include "Insertionsort.h"
#include "Permute.h"
#include "Quicksort.h"

//using namespace std;

int main(void) {
	srand(time(0));
	timePermute();
	timeQuicksort();
	timeHeapsort();
	timeBinarysearch();
	timeInsertionsort();
	return 0;
}
