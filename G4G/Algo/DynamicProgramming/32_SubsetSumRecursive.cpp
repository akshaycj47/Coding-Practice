#include <cassert>

/**
* Function that determines is there is a subset of the given set with sum 
* equal to given sum. Set is of non-negative integers
* @params {array} arr - Given set of non-negative integers
* @params {int} n - Number of elements in given set
* @params {int} sum - Given sum
* @return {bool} If there is a subset, return true; else return false
*/
bool isSubsetSum(int* arr, int n, int sum) {

	// If no elements remaining in the array
	if (n <= 0) {
		return false;
	}

	// If current element is equal to the given sum, subset is possible
	if (arr[n - 1] == sum) {
		return true;
	}

	// If current element is greater than given sum,
	// we have no choice but to ignore this element
	if (arr[n - 1] > sum) {
		return isSubsetSum(arr, n - 1, sum);
	}

	// Otherwise, we can simply try to include that element in the subset,
	// or not include. First instance includes current element in the subset,
	// second instance doesn't
	return isSubsetSum(arr, n - 1, sum - arr[n - 1]) || isSubsetSum(arr, n - 1, sum);
}

/**
* Starting point of the program
*/
int main() {

	int arr[] = { 3, 34, 4, 12, 5, 2 };
	int n = sizeof(arr) / sizeof(arr[0]);
	assert(isSubsetSum(arr, n, 9) == true);

	int arr2[] = { 3, 34, 4, 12, 5, 2 };
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	assert(isSubsetSum(arr2, n2, 33) == false);

	int arr3[] = { 3, 34, 4, 12, 5, 2 };
	int n3 = sizeof(arr3) / sizeof(arr3[0]);
	assert(isSubsetSum(arr3, n3, 7) == true);
}