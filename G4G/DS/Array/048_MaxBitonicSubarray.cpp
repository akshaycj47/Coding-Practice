#include <climits>
#include <algorithm>
#include <cassert>

/**
 * Function which finds the maximum length bitonic subarray in
 * the given array
 * @params {array} arr - Given array
 * @params {int} n - Size of the array
 * @return {int} Length of maximum length bitonic subarray
 */
int maxBitonicSubarray(int* arr, int n) {

	// Constructing dynamic array for 
	// Longest Increasing Subarray (LIS)
	// Longest Decreasing Subarray (LDS)
	int* LIS = new int[n];
	int* LDS = new int[n];

	// Compute LIS array
	LIS[0] = 1;
	for (int i = 1; i < n; i++) {
		if (arr[i] > arr[i - 1]) {
			LIS[i] = LIS[i - 1] + 1;
		}
		else {
			LIS[i] = 1;
		}
	}

	// Compute LDS array
	LDS[n - 1] = 1;
	for (int i = n - 2; i >= 0; i--) {
		if (arr[i] > arr[i + 1]) {
			LDS[i] = LDS[i + 1] + 1;
		}
		else {
			LDS[i] = 1;
		}
	} 

	// Find the maximum
	int maxLength = INT_MIN;
	for (int i = 0; i < n; i++) {
		maxLength = std::max(maxLength, LIS[i] + LDS[i] - 1);
	}
	return maxLength;
}

/**
 * Starting point of the program
 */
int main() {

	int arr[] = {12, 4, 78, 90, 45, 23};
	int n = sizeof(arr) / sizeof(arr[0]);
	assert(maxBitonicSubarray(arr, n) == 5);

	int arr2[] = {20, 4, 1, 2, 3, 4, 2, 10};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	assert(maxBitonicSubarray(arr2, n2) == 5);

	int arr3[] = {10};
	int n3 = sizeof(arr3) / sizeof(arr3[0]);
	assert(maxBitonicSubarray(arr3, n3) == 1);

	int arr4[] = {10, 20, 30, 40};
	int n4 = sizeof(arr4) / sizeof(arr4[0]);
	assert(maxBitonicSubarray(arr4, n4) == 4);

	int arr5[] = {40, 30, 20, 10};
	int n5 = sizeof(arr5) / sizeof(arr5[0]);
	assert(maxBitonicSubarray(arr5, n5) == 4);
}