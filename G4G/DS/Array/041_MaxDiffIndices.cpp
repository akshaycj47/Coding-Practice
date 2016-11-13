#include <algorithm>
#include <cassert>
#include <iostream>

int findMaxDiffIndices(int* arr, int n) {

	// First find min and max arrays
	int* lMin = new int[n];
	int* rMax = new int[n];

	lMin[0] = arr[0];
	for (int i = 1; i < n; i++) {
		lMin[i] = std::min(arr[i], lMin[i - 1]);
	}
	rMax[n - 1] = arr[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		rMax[i] = std::max(arr[i], rMax[i + 1]);
	}

	int i = 0;
	int j = 0;
	int maxDiff = -1;
	while (i < n && j < n) {
		if (lMin[i] < rMax[j]) {
			maxDiff = std::max(maxDiff, j - i);
			j++;
		}
		else {
			i++;
		}
	}

	return maxDiff;
}

int main() {

	int arr[] = {34, 8, 10, 3, 2, 80, 30, 33, 1};
	int n = sizeof(arr) / sizeof(arr[0]);
	assert(findMaxDiffIndices(arr, n) == 6);

	int arr2[] = {9, 2, 3, 4, 5, 6, 7, 8, 18, 0};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	assert(findMaxDiffIndices(arr2, n2) == 8);

	int arr3[] = {1, 2, 3, 4, 5, 6};
	int n3 = sizeof(arr3) / sizeof(arr3[0]);
	assert(findMaxDiffIndices(arr3, n3) == 5);

	int arr4[] = {6, 5, 4, 3, 2, 1};
	int n4 = sizeof(arr4) / sizeof(arr4[0]);
	assert(findMaxDiffIndices(arr4, n4) == -1);
}