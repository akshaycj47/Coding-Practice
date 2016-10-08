#include <algorithm>
#include <climits>
#include <cassert>

/**
* Function that computes minimum number of jumps required to reach the 
* end of the array
* @params {array} arr - Array of integers where each element represents
* the max number of steps that can be made forward from that element
* @params {int} n - Number of elements in array
* @params {int} i - Index from which want to calculate min number of jumps
* @return {int} Minimum number of jumps required to reach the end of the array
*/
int minNumberJumps(int* arr, int n, int i) {

	// If there are no elements, no jumps can be made
	// If there is a single element, only one jump can be made
	if (n <= 1) {
		return n;
	}

	// If we can reach the end from current position, then we only need
	// one jump
	else if (i + arr[i] >= n - 1) {
		return 1;
	}

	// If nothing is reachable from this position, return INT_MAX
	else if (arr[i] == 0) {
		return INT_MAX;
	}

	// Find all possible positions from which we can perform the next jump,
	// and return the minimum one
	else {
		int minJumps = INT_MAX;
		for (int j = 1; j <= arr[i]; j++) {
			minJumps = std::min(minJumps, minNumberJumps(arr, n, i + j));
		}
		return 1 + minJumps;
	}
}

/**
* Starting point of the program
*/
int main() {

	int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
	int n = sizeof(arr) / sizeof(arr[0]);
	assert(minNumberJumps(arr, n, 0) == 3);
}