#include <iostream>

/**
 * Function which finds the numbers which occur in an array odd 
 * number of times
 * @params {array} arr - Given array
 * @params {int} n - Size of the array
 */
void twoNumsOddOccurrences(int* arr, int n) {

	// Find XOR of all numbers, resultant will be XOR or 
	// two numbers with odd occurrences
	int xor2 = 0;
	for (int i = 0; i < n; i++) {
		xor2 = xor2 ^ arr[i];
	}

	// Find the rightmost set bit of the XOR
	int rightmostSetBit = xor2 & ~(xor2 - 1);

	// If we XOR all the elements of the array which have corresponding
	// bit set, we will get the first number. If we XOR all the elements 
	// of the array which have corresponding bit not set, we will have 
	// the second number
	int x = 0;
	int y = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] & rightmostSetBit) {
			x = x ^ arr[i];
		}
		else {
			y = y ^ arr[i];
		}
	}

	std::cout << "The two numbers are: " << x << " and " << y << std::endl;
}

/**
 * Starting point of the program
 */
int main() {

	int arr[] = {12, 23, 34, 12, 12, 23, 12, 45};
	int n = sizeof(arr) / sizeof(arr[0]);
	twoNumsOddOccurrences(arr, n);

	int arr2[] = {4, 4, 100, 5000, 4, 4, 4, 4, 100, 100};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	twoNumsOddOccurrences(arr2, n2);

	int arr3[] = {10, 20};
	int n3 = sizeof(arr3) / sizeof(arr3[0]);
	twoNumsOddOccurrences(arr3, n3);
}