#include <algorithm>
#include <cassert>
#include <iostream>

/**
* Function which computes median of single array
* @params {array} arr - Array for which we have to calculate median
* @params {int} n - Number of elements in the array
* @return {int} Median of single array
*/
int medianSingle(int* arr, int n) {

	if (n % 2 == 0) {
		return (arr[n / 2 - 1] + arr[n / 2]) / 2;
	}
	else {
		return arr[n / 2];
	}
}

/**
* Function which computes median of two sorted arrays
* in O(logn) time complexity. This function can only work
* when number of elements in arrays are equal
* @params {array} arr1 - First array
* @params {int} n1 - Number of elements in first array
* @params {array} arr2 - Second array
* @params {int} n2 - Number of elements in second array
* @return {int} Median of two sorted arrays
*/
int median(int* arr1, int n1, int* arr2, int n2) {

	// First check if number of elements in both arrays are equal
	if (n1 != n2) {
		return -1;
	}
	int n = n1;

	// Base conditions
	if (n == 1) {
		return (arr1[0] + arr2[0]) / 2;
	}
	if (n == 2) {
		return (std::max(arr1[0], arr2[0]) + std::min(arr1[1], arr2[1])) / 2;
	}

	// Calculate the medians (m1 and m2)
	int m1 = medianSingle(arr1, n);
	int m2 = medianSingle(arr2, n);

	// If m1 and m2 are equal, we are done
	if (m1 == m2) {
		return m1;
	}

	// If m1 greater than m2
	else if (m1 < m2) {
		if (n % 2 == 0) {
			return median(arr1 + n / 2 - 1, n - n / 2 + 1, arr2, n - n / 2 + 1);
		}
		return median(arr1 + n / 2, n - n / 2, arr2, n - n / 2);
	}

	// If m2 greater than m1
	else if (m2 < m1) {
		if (n % 2 == 0) {
			return median(arr1, n - n / 2 + 1, arr2 + n / 2 - 1, n - n / 2 + 1);
		}
		return median(arr1, n - n / 2, arr2 + n / 2, n - n / 2);
	}
}

/**
* Starting point of the program
*/
int main() {

	int arr1[] = { 1, 12, 15, 26, 38 };
	int arr2[] = { 2, 13, 17, 30, 45 };
	int n1 = sizeof(arr1) / sizeof(arr1[0]);
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	assert(median(arr1, n1, arr2, n2) == 16);

	int arr3[] = { 1, 2, 3, 6 };
	int arr4[] = { 4, 6, 8, 10 };
	int n3 = sizeof(arr3) / sizeof(arr3[0]);
	int n4 = sizeof(arr4) / sizeof(arr4[0]);
	assert(median(arr3, n3, arr4, n4) == 5);
}