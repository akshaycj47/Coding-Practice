#include <iostream>
#include <climits>
#include <cassert>

/**
* Function which calculates the longest increasing subsequence (LIS)
* in bottom up manner
* @params {array} arr - Array for which we want to calculate LIS
* @params {int} n - Size of the array
*/
int longestIncreasingSubsequence(int* arr, int n) {

	if (n < 2) {
		return n;
	}

	// Create a dynamic array to calculate the LIS and initialize it to 1
	int* L = new int[n];
	for (int i = 0; i < n; i++) {
		L[i] = 1;
	}

	// Start calculating the LIS
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i] && L[j] + 1 > L[i]) {
				L[i] = L[j] + 1;
			}
		}
	}

	// Find the maximum LIS
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
	assert(longestIncreasingSubsequence(arr, n) == 6);

	int arr2[] = { 20, 15, 10, 5, 4, 3, 2, 1 };
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	assert(longestIncreasingSubsequence(arr2, n2) == 1);
}