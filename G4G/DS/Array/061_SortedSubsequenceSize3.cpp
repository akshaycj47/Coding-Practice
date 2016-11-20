#include <iostream>

/**
 * Function which finds 3 elements in the array such that
 * arr[i] < arr[j] < arr[k] and i < j < k
 * @params {array} arr - Given array
 * @params {int} n - Size of the array
 */
void findSortedSubsequenceSize3(int* arr, int n) {

	// First, create smaller and greater auxiliary arrays
	int* smaller = new int[n];
	int* greater = new int[n];

	// Compute smaller and greater auxiliary arrays
	int minElement = arr[0];
	int minIndex = 0;
	smaller[0] = -1;
	for (int i = 1; i < n; i++) {
		if (arr[i] > minElement) {
			smaller[i] = minIndex;
		}
		else {
			smaller[i] = -1;
			minElement = arr[i];
			minIndex = i;
		}
	}

	int maxElement = arr[n - 1];
	int maxIndex = n - 1;
	greater[n - 1] = -1;
	for (int i = n - 2; i >= 0; i--) {
		if (arr[i] < maxElement) {
			greater[i] = maxIndex;
		}
		else {
			greater[i] = -1;
			maxElement = arr[i];
			maxIndex = i;
		}
	}

	// Finally, traverse both smaller[] and greater[] and find the index
	// such that both smaller[i] and greater[i] are not -1
	for (int i = 0; i < n; i++) {
		if (smaller[i] != -1 && greater[i] != -1) {
			std::cout << "Three elements are: " << arr[smaller[i]] << ", " << arr[i] << ", and " << arr[greater[i]] << std::endl; 
			return;
		}
	}
	std::cout << "Sorted subsequence of size 3 could not be found" << std::endl;
}

int main() {

	int arr[] = {12, 11, 10, 5, 6, 2, 30};
	int n = sizeof(arr) / sizeof(arr[0]);
	findSortedSubsequenceSize3(arr, n);

	int arr2[] = {1, 2, 3, 4};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	findSortedSubsequenceSize3(arr2, n2);

	int arr3[] = {4, 3, 2, 1};
	int n3 = sizeof(arr3) / sizeof(arr3[0]);
	findSortedSubsequenceSize3(arr3, n3);
}