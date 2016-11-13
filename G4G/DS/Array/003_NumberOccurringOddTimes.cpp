#include <cassert>

/**
 * Function which finds the number which occurs odd number of times
 * in an array
 * @params {array} arr - Given array
 * @params {int} n - Size of the array
 * @return {int} Number which occurs odd number of times
 */
int findNumOccurringOddTime(int* arr, int n) {

	int result = 0;
	for (int i = 0; i < n; i++) {
		result ^= arr[i];
	}
	return result;
}

/**
 * Starting point of the program
 */
int main() {

	int arr[] = {1, 2, 3, 2, 3, 1, 3};
	int n = sizeof(arr) / sizeof(arr[0]);
	assert(findNumOccurringOddTime(arr, n) == 3);

	int arr2[] = {1, 2, 3, 2, 3, 1};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	assert(findNumOccurringOddTime(arr2, n2) == 0);
}