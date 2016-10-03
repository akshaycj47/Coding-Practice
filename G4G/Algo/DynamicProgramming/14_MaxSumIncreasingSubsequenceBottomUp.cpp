#include <algorithm>
#include <climits>
#include <cassert>

/**
* Wrapper function to calculate the MSIS using tabulation
* @params {array} arr - Array for which we want to calculate MSIS
* @params {int} n - Size of the array
* @return {int} Maximum MSIS for given array
*/
int maxSumIncreasingSubsequence(int* arr, int n) {

	// Base condition
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}

	// Else, calculate using Dynamic programming
	else {
		// First create an array of size n to store MSIS values
		int* M = new int[n];

		// Initialize the array to array values
		for (int i = 0; i < n; i++) {
			M[i] = arr[i];
		}

		// Start filling out the array
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (arr[j] < arr[i] && M[j] + arr[i] > M[i]) {
					M[i] = M[j] + arr[i];
				}
			}
		}

		// Find out the maximum MSIS from array
		int maxMSIS = INT_MIN;
		for (int i = 0; i < n; i++) {
			maxMSIS = std::max(maxMSIS, M[i]);
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
	assert(maxSumIncreasingSubsequence(arr, n) == 106);

	int arr2[] = { 3, 4, 5, 10 };
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	assert(maxSumIncreasingSubsequence(arr2, n2) == 22);

	int arr3[] = { 10, 5, 4, 3 };
	int n3 = sizeof(arr3) / sizeof(arr3[0]);
	assert(maxSumIncreasingSubsequence(arr3, n3) == 10);
}