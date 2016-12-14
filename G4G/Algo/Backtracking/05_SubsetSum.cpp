#include <cstdio>

void printSolution(int* arr, int* sol, int n) {

	printf("Subset: ");
	for (int i = 0; i < n; i++) {
		if (sol[i] == 1) {
			printf("%d ", arr[i]);
		}
	}
	printf("\n");
}

bool isValidMove(int* arr, int idx, int k) {
	
	if (k - arr[idx] < 0) {
		return false;
	}
	return true;
}

bool solveSubsetSumUtil(int* arr, int* sol, int start, int n, int k) {

	// This means that the subset with given sum is found
	if (k == 0) {
		return true;
	}

	// Try out all the combinations
	for (int i = start + 1; i < n; i++) {

		if (isValidMove(arr, i, k)) {
			k = k - arr[i];
			sol[i] = 1;
			if (solveSubsetSumUtil(arr, sol, i, n, k)) {
				return true;
			}
			else {
				k = k + arr[i];								// Backtracking
				sol[i] = 0;
			}
		}
	}
	return false;
}

void solveSubsetSum(int* arr, int n, int k) {
	
	// Create solution array and initialize it
	int* sol = new int[n];
	for (int i = 0; i < n; i++) {
		sol[i] = 0;
	}

	// Try to find the subset that is equal to given sum
	// Start from the first element
	if (solveSubsetSumUtil(arr, sol, 0, n, k)) {
		printSolution(arr, sol, n);
	}
	else {
		printf("No subset with given sum\n");
	}
}

int main() {

	int arr[] = { 10, 7, 5, 18, 12, 20, 15 };
	int n = sizeof(arr) / sizeof(arr[0]);
	solveSubsetSum(arr, n, 35);

	int arr2[] = { 15, 22, 14, 26, 32, 9, 16, 8 };
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	solveSubsetSum(arr2, n2, 53);
}