// Sort an array of n numbers in the ascending order using merge sort
// CLRS page 37

#include <iostream>
#include <cassert>
using namespace std;

/**
 * Function which merges two sorted arrays
 * @params {array} arr - The resultant array
 * @params {array} l - The left sorted array
 * @params {int} leftLength - The length of the left sorted array
 * @params {array} r - The right sorted array
 * @params {int} rightLength - The length of the right sorted array
 */
void merge(int* arr, int* l, int leftLength, int* r, int rightLength) {

	int i = 0;
	int j = 0;
	int k = 0;
	while (i < leftLength && j < rightLength) {
		if (l[i] <= r[j]) {
			arr[k++] = l[i++];
		}
		else {
			arr[k++] = r[j++];
		}
	}
	while (i < leftLength) {
		arr[k++] = l[i++];
	}
	while (j < rightLength) {
		arr[k++] = r[j++];
	}
}

/**
 * Function which sorts an array of n numbers in the ascending order
 * @params {array} arr - The array which we have to sort
 * @params {int} n - Size of the array
 */
void mergeSort(int* arr, int n) {

	if (n < 2) {
		return;
	}
	int mid = n / 2;
	int* l = new int[mid];
	int* r = new int[n - mid];

	for (int i = 0; i < mid; i++) {
		l[i] = arr[i];
	}
	for (int i = mid; i < n; i++) {
		r[i - mid] = arr[i];
	}
	mergeSort(l, mid);
	mergeSort(r, n - mid);
	merge(arr, l, mid, r, n - mid);
}

/**
 * Starting point of the program
 */
int main() {

	int arr[] = {3, 41, 52, 26, 38, 57, 9, 49};
	int n = sizeof(arr) / sizeof(arr[0]);
	mergeSort(arr, n);
	int res[] = {3, 9, 26, 38, 41, 49, 52, 57};
	for (int i = 0; i < n; i++) {
		assert(arr[i] == res[i]);
	}
}