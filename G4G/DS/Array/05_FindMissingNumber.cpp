#include <cassert>

/**
 * Function which finds the missing number in an array of n numbers,
 * starting from 1..n
 * @params {array} arr - Given array
 * @params {int} n - Size of the array
 * @return {int} Missing number in an array
 */
int findMissingNumber(int* arr, int n) {

	int total = (n + 1) * (n + 2) / 2;
	for (int i = 0; i < n; i++) {
		total -= arr[i];
	}
	return total;
}

/**
 * Starting point of the program
 */
int main() {

	int arr[] = {1, 2, 4, 6, 3, 7, 8};
	int n = sizeof(arr) / sizeof(arr[0]);
	assert(findMissingNumber(arr, n) == 5);
}