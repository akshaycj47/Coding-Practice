// Find maximum sum subarray in a given array
// CLRS page 74

#include <iostream>
#include <climits>
#include <cassert>

struct rangeTuple {
	int leftIndex;
	int rightIndex;
	int sum;
};

/**
 * Function which finds the subarray that crosses over the midpoint
 * @params {array} arr - The array for which we have to find the maximum subarray
 * @params {int} low - The lower index of the array
 * @params {int} mid - The midpoint of the array
 * @params {int} high - The higher index of the array
 * @return {struct rangeTuple} cross - Tuple consisting of low index, high index and sum
 */
rangeTuple findMaximumCrossingSubarray(int* arr, int low, int mid, int high) {

	int leftSum = INT_MIN;
	int leftIndex = -1;
	int sum = 0;
	for (int i = mid; i >= 0; i--) {
		sum += arr[i];
		if (leftSum < sum) {
			leftSum = sum;
			leftIndex = i;
		}
	}

	int rightSum = INT_MIN;
	int rightIndex = -1;
	sum = 0;
	for (int i = mid + 1; i <= high; i++) {
		sum += arr[i];
		if (rightSum < sum) {
			rightSum = sum;
			rightIndex = i;
		}
	}
	rangeTuple crossSubarray;
	crossSubarray.leftIndex = leftIndex;
	crossSubarray.rightIndex = rightIndex;
	crossSubarray.sum = leftSum + rightSum;
	return crossSubarray;
}

/**
 * Function which finds the maximum subarray using recursion
 * @params {array} arr - The array for which we have to find the maximum subarray
 * @params {int} low - The lower index of the array
 * @params {int} high - The higher index of the array
 */
rangeTuple findMaximumSubarray(int* arr, int low, int high) {

	if (low == high) {
		rangeTuple subarray;
		subarray.leftIndex = low;
		subarray.rightIndex = high;
		subarray.sum = arr[low];
		return subarray;
	}
	else {
		int mid = low + (high - low) / 2;
		rangeTuple leftSubarray = findMaximumSubarray(arr, low, mid);
		rangeTuple rightSubarray = findMaximumSubarray(arr, mid + 1, high);
		rangeTuple crossSubarray = findMaximumCrossingSubarray(arr, low, mid, high);

		if (leftSubarray.sum >= rightSubarray.sum && leftSubarray.sum >= crossSubarray.sum) {
			return leftSubarray;
		}
		else if (rightSubarray.sum >= leftSubarray.sum && rightSubarray.sum >= crossSubarray.sum) {
			return rightSubarray;
		}
		else {
			return crossSubarray;
		}
	}
}

/**
 * Function which finds the maximum subarray using brute force approach
 * @params {array} arr - The array for which we have to find the maximum subarray
 * @params {int} n - The size of the array for which we have to find the maximum subarray
 */
rangeTuple findMaximumSubarrayBruteForce(int* arr, int n) {

	int maxSum = INT_MIN;
	int leftIndex = -1;
	int rightIndex = -1;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = i; j < n; j++) {
			sum += arr[j];
			if (maxSum < sum) {
				maxSum = sum;
				leftIndex = i;
				rightIndex = j;
			}
		}
	}
	rangeTuple subarray;
	subarray.leftIndex = leftIndex;
	subarray.rightIndex = rightIndex;
	subarray.sum = maxSum;
	return subarray;
}

/**
 * Starting point of the program
 */
int main() {

	int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	int n = sizeof(arr) / sizeof(arr[0]);
	rangeTuple subarray1 = findMaximumSubarray(arr, 0, n - 1);
	std::cout << subarray1.leftIndex << std::endl;
	std::cout << subarray1.rightIndex << std::endl;
	std::cout << subarray1.sum << std::endl;

	int arr2[] = {-2, -3, -4, -1, -2, -1, -5, -3};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	rangeTuple subarray2 = findMaximumSubarray(arr2, 0, n2 - 1);
	std::cout << subarray2.leftIndex << std::endl;
	std::cout << subarray2.rightIndex << std::endl;
	std::cout << subarray2.sum << std::endl;	

	int arr3[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	int n3 = sizeof(arr3) / sizeof(arr3[0]);
	rangeTuple subarray3 = findMaximumSubarrayBruteForce(arr3, n3);
	std::cout << subarray3.leftIndex << std::endl;
	std::cout << subarray3.rightIndex << std::endl;
	std::cout << subarray3.sum << std::endl;

	int arr4[] = {-2, -3, -4, -1, -2, -1, -5, -3};
	int n4 = sizeof(arr4) / sizeof(arr4[0]);
	rangeTuple subarray4 = findMaximumSubarrayBruteForce(arr4, n4);
	std::cout << subarray4.leftIndex << std::endl;
	std::cout << subarray4.rightIndex << std::endl;
	std::cout << subarray4.sum << std::endl;
}