// Sort an array of n numbers in the descending order
// CLRS page 22

#include <iostream>
#include <cassert>
using namespace std;

/**
 * Function which sorts an array of n numbers in the ascending order
 * @params {array} arr - The array which we have to sort
 * @params {int} n - Size of the array
 */
void insertionSort(int* arr, int n) {

	for (int j = 1; j < n; j++) {
		int key = arr[j];
		int i = j - 1;
		while (i >= 0 && arr[i] < key) {
			arr[i + 1] = arr[i];
			i--;
		}
		arr[i + 1] = key;
	}
}

/**
 * Starting point of the program
 */
int main() {

	int arr[] = {5, 2, 4, 6, 1, 3};
	int n = sizeof(arr) / sizeof(arr[0]);
	int res[] = {6, 5, 4, 3, 2, 1};
	insertionSort(arr, n);
	for (int i = 0; i < n; i++) {
		assert(arr[i] == res[i]);
	}

	int arr2[] = {31, 41, 59, 26, 41, 58};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	int res2[] = {59, 58, 41, 41, 31, 26};
	insertionSort(arr2, n2);
	for (int i = 0; i < n2; i++) {
		assert(arr2[i] == res2[i]);
	}
}