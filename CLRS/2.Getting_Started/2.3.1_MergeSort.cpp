/ Sort an array of n numbers in the ascending order using merge sort
// CLRS page 37

#include <iostream>
#include <cassert>
using namespace std;

/**
 * Function which sorts an array of n numbers in the ascending order
 * @params {array} arr - The array which we have to sort
 * @params {int} n - Size of the array
 */
void mergeSort(int* arr, int n) {

	
}

/**
 * Starting point of the program
 */
int main() {

	int arr[] = {3, 41, 51, 26, 38, 57, 9, 49};
	int n = sizeof(arr) / sizeof(arr[0]);
	mergeSort(arr, n);
	int res[] = {3, 9, 26, 38, 41, 49, 52, 59};
	for (int i = 0; i < n; i++) {
		assert(arr[i] == res[i]);
	}
}