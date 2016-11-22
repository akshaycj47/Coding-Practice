#include <unordered_map>
#include <iostream>

/**
 * Function which finds the maximum subarray in a given array, which 
 * has equal number of 0s and 1s
 * @params {array} arr - Given array
 * @params {int} n - Size of the array
 */
void largestSubarrayEqual01(int* arr, int n) {

	// First modify the current array in such a way that 0 is 
	// replaced by -1. The problem then reduces to finding a subarray
	// where the total sum is 0
	for (int i = 0; i < n; i++) {
		if (arr[i] == 0) {
			arr[i] = -1;
		}
	}

	// Create an array which can store the sum of all the elements 
	// left to the current element with the current element
	int* leftSum = new int[n];
	leftSum[0] = arr[0];
	for (int i = 1; i < n; i++) {
		leftSum[i] = leftSum[i - 1] + arr[i];
	}

	// First consider the case where the start index is from 0
	// We just have to find index where leftsum is 0
	int maxSize = -1;
	int startIndex = 0;
	for (int i = 1; i < n; i++) {
		if (leftSum[i] == 0) {
			maxSize = i + 1;
		}
	}

	// Now, consider the case where start index is anything but 0
	// We will have to find the indices where the left sum is equal
	// To achieve it, we use map
	std::unordered_map<int, int> m;
	for (int i = 0; i < n; i++) {
		if (m.find(leftSum[i]) == m.end()) {
			m[leftSum[i]] = i;
		}
		else {
			if (maxSize < i - m[leftSum[i]]) {
				maxSize = i - m[leftSum[i]];
				startIndex = m[leftSum[i]] + 1;
			}
		}
	}

	// Print the solution
	if (maxSize == -1) {
		std::cout << "No such subarray" << std::endl;
	}
	else {
		std::cout << "Subarray of size " << maxSize << " found between indices " << startIndex << " and " << startIndex + maxSize - 1 << std::endl;
	}
}

/**
 * Starting point of the program
 */
int main() {

	int arr[] = {1, 0, 1, 1, 1, 0, 0};
	int n = sizeof(arr) / sizeof(arr[0]);
	largestSubarrayEqual01(arr, n);

	int arr2[] = {1, 1, 1, 1};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	largestSubarrayEqual01(arr2, n2);

	int arr3[] = {0, 0, 1, 1, 0};
	int n3 = sizeof(arr3) / sizeof(arr3[0]);
	largestSubarrayEqual01(arr3, n3);
}