// Perform binary search in an recursive manner
// CLRS page 39

#include <iostream>
#include <cassert>
using namespace std;

/**
 * Function which performs binary search in an recursive manner
 * @params {array} arr - The array in which we have to search
 * @params {int} l - Lower limit of the array to be searched
 * @params {int} h - Higher limit of the array to be searched
 * @params {int} val - Value to be searched
 */
int binarySearchRecursive(int* arr, int l, int h, int val) {

	if (l > h) {
		return -1;
	}
	int mid = l + (h - l) / 2;
	if (arr[mid] == val) {
		return mid;
	}
	else if (val < arr[mid]) {
		return binarySearchRecursive(arr, l, mid - 1, val);
	}
	else {
		return binarySearchRecursive(arr, mid + 1, h, val);
	}
}

/**
 * Starting point of the program
 */
int main() {

	int arr[] = {1, 2, 3, 4, 5, 6};
	int n = sizeof(arr) / sizeof(arr[0]);
	assert(binarySearchRecursive(arr, 0, n - 1, 5) == 4);
	assert(binarySearchRecursive(arr, 0, n - 1, 3) == 2);
	assert(binarySearchRecursive(arr, 0, n - 1, 8) == -1);

	int arr2[] = {3, 11, 23, 42, 61, 62, 842};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	assert(binarySearchRecursive(arr2, 0, n2 - 1, 3) == 0);
	assert(binarySearchRecursive(arr2, 0, n2 - 1, 42) == 3);
	assert(binarySearchRecursive(arr2, 0, n2 - 1, 63) == -1);
}