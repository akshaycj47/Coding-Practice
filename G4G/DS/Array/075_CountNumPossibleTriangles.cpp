#include <cstdlib>
#include <cassert>

/**
 * Comparison function for qsort
 * @params {void*} a - First element
 * @params {void*} b - Second element
 * @return {int} Comparison value; if a < b, return -1;
 * if a == b, return 0; if a > b, return 1
 */
int comparison(const void* a, const void* b) {

	return *(int*)a - *(int*)b;
}

/**
 * Function which counts number of possible triangles from an 
 * array with side length as elements
 * @params {array} arr - Given array
 * @params {int} n - Number of side lengths
 * @return {int} Number of possible triangles
 */
int numPossibleTriangles(int* arr, int n) {

	// First sort the given array
	qsort(arr, n, sizeof(int), comparison);

	// Start counting
	int count = 0;
	for (int i = 0; i < n - 2; i++) {
		int k = i + 2;
		for (int j = i + 1; j < n - 1; j++) {

			// Find rightmost element which is smaller that the 
			// sum of two fixed elements
			while (k < n && arr[i] + arr[j] > arr[k]) {
				k++;
			}

			// Update count
			count = count + k - j - 1;
		}
	}
	return count;
}

/**
 * Starting point of the program
 */
int main() {

	int arr[] = {4, 6, 3, 7};
	int n = sizeof(arr) / sizeof(arr[0]);
	assert(numPossibleTriangles(arr, n) == 3);

	int arr2[] = {10, 21, 22, 100, 101, 200, 300};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	assert(numPossibleTriangles(arr2, n2) == 6);
}