// Find maximum sum subarray in a given array (non-recursive) (Kadane's algorithm)
// CLRS page 74

#include <iostream>
#include <climits>
#include <cassert>

/**
 * Function which finds the maximum subarray without using recursion
 * @params {array} arr - The array for which we have to find the maximum subarray
 * @params {int} low - The lower index of the array
 * @params {int} high - The higher index of the array
 */
int findMaximumSubarrayNonRecursion(int* arr, int n) {

	bool allNegative = true;
	int maxAllNegative = INT_MIN;
	for (int i = 0; i < n; i++) {
		if (arr[i] > 0) {
			allNegative = false;
			break;
		}
		if (maxAllNegative < arr[i]) {
			maxAllNegative = arr[i];
		}
	}

	if (allNegative) {
		return maxAllNegative;
	}

	else {
		int maxSoFar = 0;
		int maxEndingHere = 0;
		for (int i = 0; i < n; i++) {
			maxEndingHere += arr[i];
			if (maxEndingHere < 0) {
				maxEndingHere = 0;
			}
			else if (maxSoFar < maxEndingHere) {
				maxSoFar = maxEndingHere;
			}
		}
		return maxSoFar;
	}
}

/**
 * Starting point of the program
 */
int main() {

	int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	int n = sizeof(arr) / sizeof(arr[0]);
	assert(findMaximumSubarrayNonRecursion(arr, n) == 7);
	std::cout << findMaximumSubarrayNonRecursion(arr, n) << std::endl;
	
	int arr2[] = {-2, -3, -4, -1, -2, -1, -5, -3};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	assert(findMaximumSubarrayNonRecursion(arr2, n2) == -1);
	std::cout << findMaximumSubarrayNonRecursion(arr2, n) << std::endl;	
}