#include <algorithm>
#include <climits>
#include <vector>
#include <iostream>

/**
 * Function which finds the majority element in an array. A majority element
 * is an element in an array that occurs more than n / 2 times
 * @params {array} arr - Given array
 * @params {int} n - Size of the array
 * @return {int} Majority element in an array
 */
void printTwoElementsSumsClosestZero(int* arr, int n) {

	std::vector<int> v(arr, arr + n);
	std::sort(v.begin(), v.end());

	int minSum = INT_MAX;
	int elementL = -1;
	int elementR = -1;
	int l = 0;
	int r = n - 1;
	while (l < r) {
		int sum = v[l] + v[r];

		if (abs(sum) < abs(minSum)) {
			minSum = sum;
			elementL = v[l];
			elementR = v[r];
		}
		if (sum < 0) {
			l++;
		}
		if (sum > 0) {
			r--;
		}
	}

	std::cout << "Minimum sum: " << minSum << std::endl;
	std::cout << "Element 1: " << elementL << std::endl;
	std::cout << "Element 2: " << elementR << std::endl;
}

/**
 * Starting point of the program
 */
int main() {

	int arr[] = {1, 60, -10, 70, -80, 85};
	int n = sizeof(arr) / sizeof(arr[0]);
	printTwoElementsSumsClosestZero(arr, n);
}