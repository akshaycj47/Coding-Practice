#include <cassert>
#include <iostream>

/**
 * Function which finds the maximum element in an array which is first
 * increasing and then decreasing
 * @params {array} arr - Given array
 * @params {int} lo - Lower index of the array
 * @params {int} hi - Higher index of the array
 * @return {int} Maximum element
 */
int maxElement(int* arr, int lo, int hi) {

	// Only one element left
	if (lo == hi) {
		return arr[lo];
	}

	// Two elements left
	if ((hi == lo + 1) && (arr[lo] > arr[hi])) {
		return arr[lo];
	}
	if ((hi == lo + 1) && (arr[lo] < arr[hi])) {
		return arr[hi];
	}

	// More than two elements
	int mid = lo + (hi - lo) / 2;
	if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
		return arr[mid];
	}
	if (arr[mid] > arr[mid - 1] && arr[mid + 1] > arr[mid]) {
		return maxElement(arr, mid + 1, hi);
	}
	if (arr[mid] < arr[mid - 1] && arr[mid + 1] < arr[mid]) {
		return maxElement(arr, lo, mid - 1);
	}
	return -1;
}

/**
 * Starting point of the program
 */
int main() {

	int arr[] = {8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1};
	int n = sizeof(arr) / sizeof(arr[0]);
	assert(maxElement(arr, 0, n - 1) == 500);

	int arr2[] = {1, 3, 50, 10, 9, 7, 6};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	assert(maxElement(arr2, 0, n2 - 1) == 50);

	int arr3[] = {10, 20, 30, 40, 50};
	int n3 = sizeof(arr3) / sizeof(arr3[0]);
	assert(maxElement(arr3, 0, n3 - 1) == 50);

	int arr4[] = {120, 100, 80, 20, 0};
	int n4 = sizeof(arr4) / sizeof(arr4[0]);
	assert(maxElement(arr4, 0, n4 - 1) == 120);
}