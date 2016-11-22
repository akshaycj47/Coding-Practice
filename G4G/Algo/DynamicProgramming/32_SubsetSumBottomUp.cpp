#include <cassert>

/**
* Function that determines is there is a subset of the given set with sum
* equal to given sum. Set is of non-negative integers. Dynamic 
* Programming is used in this solution
* @params {array} arr - Given set of non-negative integers
* @params {int} n - Number of elements in given set
* @params {int} sum - Given sum
* @return {bool} If there is a subset, return true; else return false
*/
bool isSubsetSum(int* arr, int n, int sum) {

	// First create a matrix to store DP values
	bool** M = new bool*[n + 1];
	for (int i = 0; i < n + 1; i++) {
		M[i] = new bool[sum + 1];
	}

	// Start the initialization
	// If given sum is 0, no subset is possible
	for (int i = 0; i < n + 1; i++) {
		M[i][0] = false;
	}

	// If number of elements in set is 0, no subset is possible
	for (int i = 0; i < sum + 1; i++) {
		M[0][i] = false;
	}

	// Start computing using Dynamic Programming
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < sum + 1; j++) {

			// If given value is equal to sum, subset is possible
			if (arr[i - 1] == j) {
				M[i][j] = true;
			}

			// If given value is greater than sum, we can only 
			// look at previous results
			else if (arr[i - 1] > j) {
				M[i][j] = M[i - 1][j];
			}

			// Otherwise, look at previous results, or check if it 
			// can contribute through other sums
			else {
				M[i][j] = M[i - 1][j] || M[i - 1][j - arr[i - 1]];
			}
		}
	}

	return M[n][sum];
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