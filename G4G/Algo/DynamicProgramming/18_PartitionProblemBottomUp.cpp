#include <cassert>

bool partitionProblem(int* arr, int n) {

	// First find out the total sum of all elements in array
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}

	// If total sum is odd, then no subset can be found
	if (sum % 2 != 0) {
		return false;
	}

	// Start bottom up approach using DP
	sum = sum / 2;
	bool** M = new bool*[n + 1];
	for (int i = 0; i < n + 1; i++) {
		M[i] = new bool[sum + 1];
	}

	// Initialization, when number of elements is 0, we cannot find subset
	for (int i = 0; i < sum + 1; i++) {
		M[0][i] = false;
	}

	// Start filling out matrix elements
	for (int i = 1; i < n + 1; i++) {
		for (int j = 0; j < sum + 1; j++) {

			if (arr[i - 1] > j) {
				M[i][j] = M[i - 1][j];
			}
			else if (arr[i - 1] == j) {
				M[i][j] = true;
			}
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

	int arr[] = { 1, 5, 11, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	assert(partitionProblem(arr, n) == true);

	int arr2[] = { 1, 5, 3 };
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	assert(partitionProblem(arr2, n2) == false);

	int arr3[] = { 3, 1, 5, 9, 12 };
	int n3 = sizeof(arr3) / sizeof(arr3[0]);
	assert(partitionProblem(arr3, n3) == true);

	int arr4[] = { 3, 6, 1, 6 };
	int n4 = sizeof(arr4) / sizeof(arr4[0]);
	assert(partitionProblem(arr4, n4) == false);
}