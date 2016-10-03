#include <algorithm>
#include <climits>
#include <cassert>

int longestBitonicSubsequence(int* arr, int n) {

	// Base condition
	if (n < 2) {
		return n;
	}

	// First create and array for Longest Increasing Subsequence (LIS)
	// and Longest Decreasing Subsequence (LDS)
	int* LIS = new int[n];
	int* LDS = new int[n];

	// Initialize both arrays with 1
	for (int i = 0; i < n; i++) {
		LIS[i] = 1;
		LDS[i] = 1;
	}

	// Start computing LIS
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i] && LIS[j] + 1 > LIS[i]) {
				LIS[i] = LIS[j] + 1;
			}
		}
	}

	// Start computing LDS
	for (int i = n - 2; i >= 0; i--) {
		for (int j = n - 1; j > i; j--) {
			if (arr[j] < arr[i] && LDS[j] + 1 > LDS[i]) {
				LDS[i] = LDS[j] + 1;
			}
		}
	}

	// Find maximum bitonic value
	int LBS = INT_MIN;
	for (int i = 0; i < n; i++) {
		LBS = std::max(LBS, LIS[i] + LDS[i] - 1);
	}
	return LBS;
}

int main() {

	int arr[] = { 1, 11, 2, 10, 4, 5, 2, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	assert(longestBitonicSubsequence(arr, n) == 6);

	int arr2[] = { 12, 11, 40, 5, 3, 1 };
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	assert(longestBitonicSubsequence(arr2, n2) == 5);

	int arr3[] = { 80, 60, 30, 40, 20, 10 };
	int n3 = sizeof(arr3) / sizeof(arr3[0]);
	assert(longestBitonicSubsequence(arr3, n3) == 5);

	int arr4[] = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };
	int n4 = sizeof(arr4) / sizeof(arr4[0]);
	assert(longestBitonicSubsequence(arr4, n4) == 7);
}