#include <cassert>

/**
 * Function which finds equilibrium index. Equilibrium index is an
 * index where the sum of all elements on the left is equal to sum of
 * all elements on the right
 * @params {array} arr - Given array
 * @params {int} n - Size of the array
 * @return {int} Equilibrium index in an array
 */
int equilibriumIndex(int* arr, int n) {
	
	int sum = 0;
	int leftSum = 0;
	int rightSum = 0;

	// Calculate sum
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}
	rightSum = sum;

	// Compare left sum and right sum to find equilibrium index
	for (int i = 0; i < n; i++) {
		rightSum -= arr[i];
		if (rightSum == leftSum) {
			return i;
		}
		leftSum += arr[i];
	}
	return -1;
}

/**
 * Starting point of the program
 */
int main() {

	int arr[] = {-7, 1, 5, 2, -4, 3, 0};
	int n = sizeof(arr) / sizeof(arr[0]);
	assert(equilibriumIndex(arr, n) == 3);
}