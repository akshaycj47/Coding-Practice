#include <iostream>
#include <cstdlib>
#include <ctime>

/**
 * Function which swaps two numbers
 * @params {int} x - First number
 * @params {int} y - Second number
 */
void swap(int* x, int* y) {

	int temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * Function which prints a given array
 * @params {array} arr - Given array
 * @params {int} n - Size of the array
 */
void printArray(int* arr, int n) {

	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

/**
 * Function which shuffles a given array
 * @params {array} arr - Given array
 * @params {int} n - Size of the array
 */
void shuffle(int* arr, int n) {

	// Print original array
	std::cout << "Original array: ";
	printArray(arr, n);

	// Start shuffling
	srand(time(NULL));
	for (int i = n - 1; i > 0; i--) {
		int j = rand() % (i + 1);
		swap(&arr[i], &arr[j]);
	}

	// Print shuffled array
	std::cout << "Shuffled array: ";
	printArray(arr, n);
}

/**
 * Starting point of the program
 */
int main() {

	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int n = sizeof(arr) / sizeof(arr[0]);
	shuffle(arr, n);

	int arr2[] = {1};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	shuffle(arr2, n2);

	int arr3[] = {1, 2};
	int n3 = sizeof(arr3) / sizeof(arr3[0]);
	shuffle(arr3, n3);
}