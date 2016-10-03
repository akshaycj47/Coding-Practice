#include <algorithm>
#include <climits>
#include <cassert>

/**
* Function which calculates the maximum sum increasing subsequence
* (MSIS) in recursive manner
* @params {array} arr - Array for which we want to calculate MSIS
* @params {int} i - MSIS at a particular index in array
* @return {int} MSIS at given index
*/
int maxSumIncreasingSubsequence(int* arr, int i) {

	// Base condition
	if (i == 0) {
		return arr[0];
	}

	// For all MSIS values less than i, find maximum and add 
	// it to current value
	int maxPrevious = 0;
	for (int j = 0; j < i; j++) {
		if (arr[j] < arr[i]) {
			maxPrevious = std::max(maxPrevious, maxSumIncreasingSubsequence(arr, j));
		}
	}
	return maxPrevious + arr[i];
}

/**
* Wrapper function to calculate the MSIS in recursive manner
* @params {array} arr - Array for which we want to calculate MSIS
* @params {int} n - Size of the array
* @return {int} Maximum MSIS for given array
*/
int maxSumIncreasingSubsequenceWrapper(int* arr, int n) {

	// Base condition
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return arr[0];
	}

	// Else, compute the maximum MSIS recursively
	else {

		int maxMSIS = INT_MIN;
		for (int i = 0; i < n; i++) {
			int currMSIS = maxSumIncreasingSubsequence(arr, i);
			maxMSIS = std::max(maxMSIS, currMSIS);
		}
		return maxMSIS;
	}
}

/**
* Starting point of the program
*/
int main() {
	
	int arr[] = { 1, 101, 2, 3, 100, 4, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	assert(maxSumIncreasingSubsequenceWrapper(arr, n) == 106);

	int arr2[] = { 3, 4, 5, 10 };
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	assert(maxSumIncreasingSubsequenceWrapper(arr2, n2) == 22);

	int arr3[] = { 10, 5, 4, 3 };
	int n3 = sizeof(arr3) / sizeof(arr3[0]);
	assert(maxSumIncreasingSubsequenceWrapper(arr3, n3) == 10);
}