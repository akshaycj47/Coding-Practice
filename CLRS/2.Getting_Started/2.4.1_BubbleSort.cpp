// Sort an array of n numbers in the ascending order using bubble sort
// CLRS page 22

#include <iostream>
#include <cassert>
using namespace std;

void swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * Function which sorts an array of n numbers in the ascending order
 * @params {array} arr - The array which we have to sort
 * @params {int} n - Size of the array
 */
void bubbleSort(int* arr, int n) {

	for (int j = 0; j < n - 1; j++) {
		for (int i = 0; i < n - j - 1; i++) {
			if (arr[i] > arr[i + 1]) {
				swap(&arr[i], &arr[i + 1]);
			}
		}
	}
}

/**
 * Starting point of the program
 */
int main() {

	int arr[] = {5, 2, 4, 6, 1, 3};
	int n = sizeof(arr) / sizeof(arr[0]);
	int res[] = {1, 2, 3, 4, 5, 6};
	bubbleSort(arr, n);
	for (int i = 0; i < n; i++) {
		assert(arr[i] == res[i]);
	}

	int arr2[] = {3, 42, 61, 62, 23, 842, 11};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	int res2[] = {3, 11, 23, 42, 61, 62, 842};
	bubbleSort(arr2, n2);
	for (int i = 0; i < n2; i++) {
		assert(arr2[i] == res2[i]);
	}

	int arr3[] = {76, 32, 21, 19, 17, 11, 9, 3, 1, 0};
	int n3 = sizeof(arr3) / sizeof(arr3[0]);
	int res3[] = {0, 1, 3, 9, 11, 17, 19, 21, 32, 76};
	bubbleSort(arr3, n3);
	for (int i = 0; i < n3; i++) {
		assert(arr3[i] == res3[i]);
	}
}