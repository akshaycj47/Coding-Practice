#include <algorithm>
#include <cmath>
#include <cassert>
#include <iostream>

/**
 * Function which checks if an array consists of consecutive numbers
 * @params {array} arr - Given array
 * @params {int} n - Size of the array
 * @return {bool} True if array consists of consecutive numbers, else False
 */
bool checkArrayElementsConsecutive(int* arr, int n) {

	// First find min and max value in the array
	int min = arr[0];
	int max = arr[0];
	for (int i = 1; i < n; i++) {
		min = std::min(min, arr[i]);
		max = std::max(max, arr[i]);
	}

	if (max - min + 1 != n) {
		return false;
	}

	// Check if elements are repeating or not
	// First transform array into 1..n
	for (int i = 0; i < n; i++) {
		arr[i] = arr[i] - min + 1;
	}

	// Now check for duplicate elements
	for (int i = 0; i < n; i++) {
		if (arr[abs(arr[i])] < 0) {
			return false;
		}
		arr[abs(arr[i])] = -1 * arr[abs(arr[i])];
	}
	return true;
}

/**
 * Starting point of the program
 */
int main() {

	int arr[] = {5, 2, 3, 1, 4};
	int n = sizeof(arr) / sizeof(arr[0]);
	assert(checkArrayElementsConsecutive(arr, n) == true);

	int arr2[] = {83, 78, 80, 81, 79, 82};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	assert(checkArrayElementsConsecutive(arr2, n2) == true);

	int arr3[] = {34, 23, 52, 12, 3};
	int n3 = sizeof(arr3) / sizeof(arr3[0]);
	assert(checkArrayElementsConsecutive(arr3, n3) == false);

	int arr4[] =  {7, 6, 5, 5, 3, 4};
	int n4 = sizeof(arr4) / sizeof(arr4[0]);
	assert(checkArrayElementsConsecutive(arr4, n4) == false);

	int arr5[] = {80, 78, 80, 80, 70, 82};
	int n5 = sizeof(arr5) / sizeof(arr5[0]);
	assert(checkArrayElementsConsecutive(arr5, n5) == false);
}