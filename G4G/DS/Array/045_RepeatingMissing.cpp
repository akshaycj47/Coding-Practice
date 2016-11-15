#include <iostream>

/**
 * Function which calculates factorial of a number
 * @params {int} n - Given number
 * @return {int} Factorial of the number
 */
int factorial(int n) {

	if (n == 0) {
		return 1;
	}
	return n * factorial(n - 1);
}

/**
 * Function which prints missing and repeating elements in an 
 * array with range 1..n
 * @params {array} arr - Given array
 * @params {int} n - Size of the array
 */
void printRepeatingMissing(int* arr, int n) {

	int sum = 0;
	float prod = 1;

	// Calculate actual sum and prod
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		prod *= arr[i];
	}

	// Subtract actual sum from expected sum
	// Divide actual product from expected product
	sum -= (n * (n + 1)) / 2;
	prod /= (float)factorial(n);

	int y = sum / (prod - 1);
	int x = sum + y;
	std::cout << "Missing number: " << y << std::endl;
	std::cout << "Repeating number: " << x << std::endl;
}

int main() {

	int arr[] = {3, 1, 3};
	int n = sizeof(arr) / sizeof(arr[0]);
	printRepeatingMissing(arr, n);

	int arr2[] = {4, 3, 6, 2, 1, 1};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	printRepeatingMissing(arr2, n2);
}