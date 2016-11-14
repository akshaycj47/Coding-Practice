#include <algorithm>
#include <cassert>
#include <iostream>

/**
 * Function which finds minimum distance between two elements in 
 * an array
 * @params {array} arr - Given array
 * @params {int} n - Size of the array
 * @params {int} a - First element
 * @params {int} b - Second element
 * @return {int} Majority element in an array
 */
int findMinDistTwoNumbers(int* arr, int n, int a, int b) {

	// First find the first instance of a or b
	int prev = -1;
	for (int i = 0; i < n; i++) {
		if (arr[i] == a || arr[i] == b) {
			prev = i;
			break;
		}
	}

	int minDistance = n;
	for (int i = prev + 1; i < n; i++) {
		if (arr[i] == arr[prev]) {
			prev = i;
		}
		if ((arr[i] == a || arr[i] == b) && (arr[i] != arr[prev])) {
			minDistance = std::min(minDistance, i - prev);
		}
	}
	return minDistance;
}

/**
 * Starting point of the program
 */
int main() {

	int arr[] = {3, 5, 4, 2, 6, 5, 6, 6, 5, 4, 8, 3};
	int n = sizeof(arr) / sizeof(arr[0]);
	assert(findMinDistTwoNumbers(arr, n, 3, 6) == 4);

	int arr2[] = {2, 5, 3, 5, 4, 4, 2, 3};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	assert(findMinDistTwoNumbers(arr2, n2, 3, 2) == 1);

	int arr3[] = {3, 4, 5};
	int n3 = sizeof(arr3) / sizeof(arr3[0]);
	assert(findMinDistTwoNumbers(arr3, n3, 3, 5) == 2); 

	int arr4[] = {1, 2};
	int n4 = sizeof(arr4) / sizeof(arr4[0]);
	assert(findMinDistTwoNumbers(arr4, n4, 1, 2) == 1);
}