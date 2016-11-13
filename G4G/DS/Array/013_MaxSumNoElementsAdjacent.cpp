#include <algorithm>
#include <cassert>

/**
 * Function which finds the maximum sum of subsequence with the 
 * constraint that no two elements in subsequence should be adjacent
 * to each other 
 * @params {array} arr - Given array
 * @params {int} n - Size of the array
 * @return {int} Maximum sum of subsequence
 */
int maxSumNoElementsAdjacent(int* arr, int n) {

	// Base condition
	if (n < 1) {
		return 0;
	}
	return std::max(arr[n - 1] + maxSumNoElementsAdjacent(arr, n - 2),		// Select current element
					maxSumNoElementsAdjacent(arr, n - 1)					// Don't select current element
					);
}

/**
 * Starting point of the program
 */
int main() {

	int arr[] = {3, 2, 7, 10};
	int n = sizeof(arr) / sizeof(arr[0]);
	assert(maxSumNoElementsAdjacent(arr, n) == 13);

	int arr2[] = {3, 2, 5, 10, 7};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	assert(maxSumNoElementsAdjacent(arr2, n2) == 15);
}