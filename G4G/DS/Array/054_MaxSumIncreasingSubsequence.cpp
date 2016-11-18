#include <climits>
#include <algorithm>
#include <cassert>

/**
 * Function which finds maximum sum increasing subsequence
 * in a given array
 * @params {array} arr - Given array
 * @params {int} n - Size of the array
 * @return {int} Maximum sum increasing subsequence
 */
int maxSumIncreasingSubsequence(int* arr, int n) {

	// Create an array to store MSIS values
	int* M = new int[n];

	// Initialize MSIS array
	for (int i = 0; i < n; i++) {
		M[i] = arr[i];
	}

	// Start calculating DP
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (M[j] < M[i] && M[j] + arr[i] > M[i]) {
				M[i] = M[j] + arr[i];
			}
		}
	}

	// Find the maximum sum 
	int maxSum = INT_MIN;
	for (int i = 0; i < n; i++) {
		maxSum = std::max(maxSum, M[i]);
	}
	return maxSum;
}

/**
 * Starting point of the program
 */
int main() {

	int arr[] = {1, 101, 2, 3, 100, 4, 5};
	int n = sizeof(arr) / sizeof(arr[0]);
	assert(maxSumIncreasingSubsequence(arr, n) == 106);

	int arr2[] = {3, 4, 5, 10};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	assert(maxSumIncreasingSubsequence(arr2, n2) == 22);

	int arr3[] = {10, 5, 4, 3};
	int n3 = sizeof(arr3) / sizeof(arr3[0]);
	assert(maxSumIncreasingSubsequence(arr3, n3) == 10);
}