#include <cassert>

/**
 * Function which swaps two numbers
 * @params {int} x - First number
 * @params {int} y - Second number
 */
void swap(int* x, int *y) {

	int temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * Function which segregates positive and non-positive numbers
 * @params {array} arr - Given array
 * @params {int} n - Size of the array
 * @return {int} Number of non-positive numbers
 */
int segregate(int* arr, int n) {

	int lo = 0;
	int hi = n - 1;
	while (lo < hi) {
		while (arr[lo] <= 0) {
			lo++;
		}
		while (arr[hi] > 0) {
			hi--;
		}
		if (lo < hi) {
			swap(&arr[lo], &arr[hi]);
			lo++;
			hi--;
		}
	}
	return lo;
} 

/**
 * Utility function which finds smallest positive number in an array
 * containting only positive numbers
 * @params {array} arr - Given array with only positive numbers
 * @params {int} n - Size of the array with only positive numbers
 * @return {int} Smallest missing positive number
 */
int smallestMissingPositiveNumUtil(int* arr, int n) {

	// Mark arr[i] as visited by making arr[arr[i] - 1] negative. Note that
	// 1 is subtracted since indices start from 0, and positive numbers start 
	// from 1
	for (int i = 0; i < n; i++) {
		if (abs(arr[i]) - 1 < n && arr[abs(arr[i]) - 1] > 0) {
			arr[abs(arr[i]) - 1] = -1 * arr[abs(arr[i]) - 1];
		}
	}

	// Return the first index value at which it is positive
	// 1 is added since indices start from 0
	for (int i = 0; i < n; i++) {
		if (arr[i] > 0) {
			return i + 1;
		}
	}
	return -1;
}

/**
 * Function which finds smallest missing positive number in an 
 * array of positive and non-positive numbers
 * @params {array} arr - Given array
 * @params {int} n - Size of the array
 * @return {int} Smallest missing positive number
 */
int smallestMissingPositiveNum(int* arr, int n) {

	// Segregate positive and non-positive numbers, size is the start
	// index of positive numbers (number of non-positive numbers)
	int size = segregate(arr, n);
	return smallestMissingPositiveNumUtil(arr + size, n - size);
}

/**
 * Starting point of the program
 */
int main() {

	int arr[] = {2, 3, 7, 6, 8, -1, -10, 15};
	int n = sizeof(arr) / sizeof(arr[0]);
	assert(smallestMissingPositiveNum(arr, n) == 1);

	int arr2[] = {2, 3, -7, 6, 8, 1, -10, 15};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	assert(smallestMissingPositiveNum(arr2, n2) == 4);

	int arr3[] = {1, 1, 0, -1, -2};
	int n3 = sizeof(arr3) / sizeof(arr3[0]);
	assert(smallestMissingPositiveNum(arr3, n3) == 2);

	int arr4[] = {-1, -2, -3, -4, 5};
	int n4 = sizeof(arr4) / sizeof(arr4[0]);
	assert(smallestMissingPositiveNum(arr4, n4) == 1);
}