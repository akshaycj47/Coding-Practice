// Maximize profit for stock prices over a given range, use maximum subarray
// CLRS page 68

#include <iostream>
#include <climits>
#include <cassert>
using namespace std;

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
	int leftSumIndex = -1;
	int sum = 0;
	for (int i = mid; i >= low; i--) {
		sum = sum + arr[i];
		if (sum > leftSum) {
			leftSum = sum;
			leftSumIndex = i;
		}
	}
	
	int rightSum = INT_MIN;
	int rightSumIndex = -1;
	sum = 0;
	for(int i = mid + 1; i <= high; i++) {
		sum = sum + arr[i];
		if (sum > rightSum) {
			rightSum = sum;
			rightSumIndex = i;
		}
	}

	rangeTuple cross;
	cross.leftIndex = leftSumIndex;
	cross.rightIndex = rightSumIndex;
	cross.sum = leftSum + rightSum;
	return cross;
}

/**
 * Function which finds the maximum subarray
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
 * Starting point of the program
 */
int main() {

	int prices[] = {100, 113, 110, 85, 105, 102, 86, 63, 81, 101, 94, 106, 101, 79, 94, 90, 97};
	int n = sizeof(prices) / sizeof(prices[0]);
	int* change = new int[n];
	change[0] = 0;
	for (int i = 1; i < n; i++) {
		change[i] = prices[i] - prices[ i - 1];
	}

	rangeTuple subarray = findMaximumSubarray(change, 0, n - 1);
	cout << subarray.leftIndex << endl;
	cout << subarray.rightIndex << endl;
	cout << subarray.sum << endl;
}