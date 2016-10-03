#include <cassert>

/**
* Function that determines if there is a subset which is equal to the given sum
* @params {array} arr - Array which we want to check the subsets
* @params {int} n - Size of array
* @return {bool} Return true if there is a subset which is equal to the given sum,
* otherwise return false
*/
bool partitionProblem(int* arr, int n, int sum) {

	// If sum is negative, there is no subset possible
	if (sum < 0) {
		return false;
	}

	// If there are no elements remaining, there is no subset possible
	if (n == 0) {
		return false;
	}

	// If there are some elements remaining, and sum is 0, it means we
	// have found the subset
	if (n > 0 && sum == 0) {
		return true;
	}

	// Either include the last element or not include (in the subset)
	return partitionProblem(arr, n - 1, sum - arr[n - 1]) || partitionProblem(arr, n - 1, sum);
}

/**
* Wrapper function that determines if a given set can be partitioned into two 
* subsets such that the sum of elements in both subsets is same
* @params {array} arr - Array which we want to check if it can be partitioned or not
* @params {int} n - Size of array
* @return {bool} Return true if set can be partitioned into two subsets such that
* sum of elements in both subsets is same, otherwise return false
*/
bool partitionProblemWrapper(int* arr, int n) {

	// First calculate the total sum of the array
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}

	// If the sum is odd, it cannot be partitioned
	if (sum % 2 != 0) {
		return false;
	}

	// We have to see if there is a subset whose sum will be equal to 
	// total sum of the array
	return partitionProblem(arr, n, sum / 2);
}

/**
* Starting point of the program
*/
int main() {

	int arr[] = { 1, 5, 11, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	assert(partitionProblemWrapper(arr, n) == true);

	int arr2[] = { 1, 5, 3 };
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	assert(partitionProblemWrapper(arr2, n2) == false);

	int arr3[] = { 3, 1, 5, 9, 12 };
	int n3 = sizeof(arr3) / sizeof(arr3[0]);
	assert(partitionProblemWrapper(arr3, n3) == true);

	int arr4[] = { 3, 6, 1, 6 };
	int n4 = sizeof(arr4) / sizeof(arr4[0]);
	assert(partitionProblemWrapper(arr4, n4) == false);
}