#include <algorithm>
#include <iostream>

/**
 * Function which finds the minimum length subarray, which when
 * sorted makes the entire array sorted
 * @params {array} arr - Given array
 * @params {int} n - Size of the array
 */
void findMinLengthUnsortedSubarray(int* arr, int n) {

	// First find initial lo and hi indices
	int lo = 0;
	while (lo < n - 1) {
		if (arr[lo] > arr[lo + 1]) {
			break;
		}
		lo++;
	}
	int hi = n - 1;
	while (hi > 0) {
		if (arr[hi] < arr[hi - 1]) {
			break;
		}
		hi--;
	}

	// Find the minimum and maximum elements in the current subarray
	int min = arr[lo];
	int max = arr[hi];
	for (int i = lo; i <= hi; i++) {
		min = std::min(min, arr[i]);
		max = std::max(max, arr[i]);
	}

	// Correct the indices lo and hi
	int i = lo - 1;
	while (i >= 0) {
		if (arr[i] > min) {
			lo = i;
		}
		else {
			break;
		}
		i--;
	}
	int j = hi + 1;
	while (j <= n - 1) {
		if (arr[j] < max) {
			hi = j;
		}
		else {
			break;
		}
		j++;
	}

	std::cout << "Lower index: " << lo << std::endl;
	std::cout << "Higher index: " << hi << std::endl;
}

/**
 * Starting point of the program
 */
int main() {

	int arr[] = {10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};
	int n = sizeof(arr) / sizeof(arr[0]);
	findMinLengthUnsortedSubarray(arr, n);

	int arr2[] = {0, 1, 15, 25, 6, 7, 30, 40, 50};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	findMinLengthUnsortedSubarray(arr2, n2);
}