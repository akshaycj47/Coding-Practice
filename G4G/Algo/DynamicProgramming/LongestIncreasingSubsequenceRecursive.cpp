#include <iostream>
#include <climits>
#include <cassert>

/**
* Function which calculates the longest increasing subsequence (LIS)
* in recursive manner
* @params {array} arr - Array for which we want to calculate LIS
* @params {int} i - LIS at a particular index in array
*/
int lisRecursive(int* arr, int i) {

	// Base case
	if (i == 0) {
		return 1;
	}

	int max = 0;
	for (int j = 0; j < i; j++) {
		if (arr[j] < arr[i]) {
			if (max < lisRecursive(arr, j)) {
				max = lisRecursive(arr, j);
			}
		}
	}
	return 1 + max;
}

/**
* Utility function to calculate the LIS in recursive manner
* @params {array} arr - Array for which we want to calculate LIS
* @params {int} n - Size of the array
*/
int lisRecursiveUtil(int* arr, int n) {

	// Base condition
	if (n < 2) {
		return n;
	}

	// Compute the maximum LIS
	int max = INT_MIN;
	for (int i = 0; i < n; i++) {
		int currLis = lisRecursive(arr, i);
		if (max < currLis) {
			max = currLis;
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

	assert(lisRecursiveUtil(arr, n) == 6);
	assert(lisRecursiveUtil(arr2, n2) == 1);
}