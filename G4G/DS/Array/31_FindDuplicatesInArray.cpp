#include <iostream>

/**
 * Function which print duplicate elements in an array
 * @params {array} arr - Given array
 * @params {int} n - Size of the array
 */
void printDuplicatesInArray(int* arr, int n) {

	for (int i = 0; i < n; i++) {
		if (arr[abs(arr[i])] > 0) {
			arr[abs(arr[i])] = -1 * arr[abs(arr[i])];
		}
		else {
			std::cout << abs(arr[i]) << " ";
		}
	}
	std::cout << std::endl;
}

/**
 * Starting point of the program
 */
int main() {

	int arr[] = {1, 2, 3, 1, 3, 6, 6};
	int n = sizeof(arr) / sizeof(arr[0]);
	printDuplicatesInArray(arr, n);

	int arr2[] = {1, 2, 3, 1, 3, 6, 6, 3};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	printDuplicatesInArray(arr2, n2);

	int arr3[] = {3, 5, 6, 1, 7, 9, 2, 7};
	int n3 = sizeof(arr3) / sizeof(arr3[0]);
	printDuplicatesInArray(arr3, n3);
}

/**
 * Things learnt:
 * 1. Only works for elements present 0, 1, or 2 times (see arr2 output)
 * 2. Only works for elements from 1..n where n is the size of the array (see arr3 output)
 * 3. Won't work if one of the array element is 0 (there is a simple workaround for this,
 * add 1 to every element in the array)
 */