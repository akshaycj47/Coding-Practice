#include <cassert>

/**
* Function which counts number of inversions in an array (how far
* or how close the array is from being sorted). If an array is already
* sorted, inversion count is 0. If an array is sorted in reverse order,
* that inversion count is maximum
* @params {array} arr - Given array
* @params {int} n - Number of elements in array
* @return {int} Number of inversions in given array
*/
int countInversions(int* arr, int n) {

	int count = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[i]) {
				count++;
			}
		}
	}
	return count;
}

/**
* Starting point of the program
*/
int main() {

	int arr[] = { 2, 4, 1, 3, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	assert(countInversions(arr, n) == 3);
	
	int arr2[] = { 1, 20, 6, 4, 5 };
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	assert(countInversions(arr2, n2) == 5);
}