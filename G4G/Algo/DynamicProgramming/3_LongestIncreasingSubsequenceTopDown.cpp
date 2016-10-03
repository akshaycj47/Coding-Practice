#include <iostream>
#include <climits>
#include <cassert>

#define NIL -1

/**
* Function which initializes the lookup table
* @params {array} lookup - Lookup table to be used in top down approach
* @params {int} n - Size of the lookup table
*/
void initializeLookup(int* lookup, int n) {
	for (int i = 0; i < n; i++) {
		lookup[i] = NIL;
	}
	lookup[0] = 1;
}

/**
* Function which calculates the longest increasing subsequence (LIS)
* in top down manner
* @params {array} arr - Array for which we want to calculate LIS
* @params {array} lookup - Lookup table for LIS
* @params {int} i - LIS at a particular index in array
*/
int lisTopDown(int* arr, int* lookup, int i) {

	// Base condition
	if (lookup[i] != NIL) {
		return lookup[i];
	}

	int max = 0;
	for (int j = 0; j < i; j++) {
		if (arr[j] < arr[i]) {
			if (max < lisTopDown(arr, lookup, j)) {
				max = lisTopDown(arr, lookup, j);
			}
		}
	}
	lookup[i] = max + 1;
	return max + 1;
}

/**
* Utility function to calculate the LIS in top down manner
* @params {array} arr - Array for which we want to calculate LIS
* @params {int} n - Size of the array
*/
int lisTopDownUtil(int* arr, int n) {

	// Base condition
	if (n < 2) {
		return n;
	}

	// Lookup table for top down approach
	int* lookup = new int[n];
	initializeLookup(lookup, n);

	int* L = new int[n];
	for (int i = 0; i < n; i++) {
		L[i] = lisTopDown(arr, lookup, i);
	}

	// Finding max
	int max = INT_MIN;
	for (int i = 0; i < n; i++) {
		if (max < L[i]) {
			max = L[i];
		}
	}
	return max;
}

/**
* Starting point of the program
*/
int main() {

	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60, 80 };
	int n = sizeof(arr) / sizeof(arr[0]);

	int arr2[] = { 20, 15, 10, 5, 4, 3, 2, 1 };
	int n2 = sizeof(arr2) / sizeof(arr2[0]);

	assert(lisTopDownUtil(arr, n) == 6);
	assert(lisTopDownUtil(arr2, n2) == 1);
}