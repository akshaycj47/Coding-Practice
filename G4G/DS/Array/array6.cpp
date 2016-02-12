// Product array puzzle
// http://www.geeksforgeeks.org/a-product-array-puzzle/

#include <iostream>
using namespace std;

/**
 * Function which computes the product array. Product array is an array with
 * value at a particular index which is the product of all the indices except itseld
 * @params arr {array} Array for which we have to compute the product array
 * @params n {int} Size of the array
 */
void productArray(int* arr, int n) {
	// Create the result array
	int* result = new int[n];

	// Left swipe
	result[0] = 1;
	for(int i = 1; i < n; i++) {
		result[i] = result[i - 1] * arr[i - 1];
	}

	// Right swipe
	int rightProd = arr[n - 1];
	for(int i = n - 2; i >= 0; i--) {
		result[i] = result[i] * rightProd;
		rightProd *= arr[i];
	}

	// Printing the result array
	for(int i = 0; i < n; i++) {
		cout << result[i] << " ";
	}
	cout << endl;
}

/**
 * Starting point of the program
 */
int main() {
	int arr[] = {10, 3, 5, 6, 2};
	int n = sizeof(arr) / sizeof(arr[0]);
	productArray(arr, n);
}