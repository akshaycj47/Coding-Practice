#include <cassert>
#include <climits>
#include <algorithm>

/**
* Function that computes the minimum number of multiplications
* needed to multiply the chain
* @params {array} arr - Array containing matrix dimensions
* @params {int} i - Start index
* @params {int} j - End index
* @return {int} minimum number of multiplications needed to 
* multiply the chain
*/
int matrixChangeMultiplication(int* arr, int i, int j) {

	// Base case
	if (i == j) {
		return 0;
	}
	int min = INT_MAX;
	for (int k = i; k < j; k++) {
		int count = matrixChangeMultiplication(arr, i, k) + 
					matrixChangeMultiplication(arr, k + 1, j) + 
					arr[i - 1] * arr[k] * arr[j];
		if (min > count) {
			min = count;
		}
	}
	return min;
}

/**
* Starting point of the program
*/
int main() {

	int arr[] = { 1, 2, 3, 4, 3 };
	int n = sizeof(arr) / sizeof(arr[0]);
	assert(matrixChangeMultiplication(arr, 1, n - 1) == 30);

	int arr2[] = { 10, 30, 5, 60 };
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	assert(matrixChangeMultiplication(arr2, 1, n2 - 1) == 4500);

	int arr3[] = { 40, 20, 30, 10, 30 };
	int n3 = sizeof(arr3) / sizeof(arr3[0]);
	assert(matrixChangeMultiplication(arr3, 1, n3 - 1) == 26000);
}