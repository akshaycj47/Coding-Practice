#include <iostream>

/**
 * Function which find a continous subarray which adds to a given number,
 * given an unsorted array of nonnegative integers
 * @params {array} arr - Given array
 * @params {int} n - Size of the array
 * @return {int} Majority element in an array
 */
void findSubarrayGivenSum(int* arr, int n, int sum) {
	
	int currSum = arr[0];
	int start = 0;
	for (int i = 1; i <= n; i++) {
		while (currSum > sum && start < i - 1) {
			currSum -= arr[start];
			start++;
		}

		if (currSum == sum) {
			std::cout << "Found subarray from index " << start << " to " << i - 1 << std::endl;
			return;
		}

		if (i < n) {
			currSum += arr[i];
		}
	}

	std::cout << "Subarray equal to the given sum not found" << std::endl;
}

/**
 * Starting point of the program
 */
int main() {

	int arr[] = {1, 4, 20, 3, 10, 5};
	int n = sizeof(arr) / sizeof(arr[0]);
	findSubarrayGivenSum(arr, n, 33);

	int arr2[] = {1, 4, 0, 0, 3, 10, 5};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	findSubarrayGivenSum(arr2, n2, 7);

	int arr3[] = {1, 4};
	int n3 = sizeof(arr3) / sizeof(arr3[0]);
	findSubarrayGivenSum(arr3, n3, 0);
}