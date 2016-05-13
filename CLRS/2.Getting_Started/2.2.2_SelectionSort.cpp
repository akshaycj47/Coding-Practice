// Sort an array of n numbers in the ascending order
// CLRS page 29

#include <iostream>
#include <cassert>
#include <climits>
using namespace std;

/**
 * Function which swaps two numbers
 * params {int} x - First number
 * params {int} y - Second number
 */
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
void selectionSort(int* arr, int n) {

	for (int i = 0; i < n; i++) {
		int min = INT_MAX;
		int minIndex = -1;
		for (int j = i; j < n; j++) {
			if (arr[j] < min) {
				min = arr[j];
				minIndex = j;
			} 
		}
		swap(&arr[i], &arr[minIndex]);
	}
}

/**
 * Starting point of the program
 */
int main() {

	int arr[] = {31, 41, 59, 26, 41, 58};
	int n = sizeof(arr) / sizeof(arr[0]);
	selectionSort(arr, n);
	int res[] = {26, 31, 41, 41, 58, 59};
	for (int i = 0; i < n; i++) {
		assert(arr[i] == res[i]);
	}
}