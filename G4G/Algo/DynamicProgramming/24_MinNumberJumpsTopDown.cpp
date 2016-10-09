#include <algorithm>
#include <map>
#include <climits>
#include <cassert>

/**
* Function that computes minimum number of jumps required to reach the 
* end of the array
* @params {array} arr - Array of integers where each element represents
* the max number of steps that can be made forward from that element
* @params {int} n - Number of elements in array
* @params {int} i - Index from which want to calculate min number of jumps
* @params {map} m - Map which stores the results
* @return {int} Minimum number of jumps required to reach the end of the array
*/
int minNumberJumps(int* arr, int n, int i, std::map<int, int>& m) {

	// First check if it is present in the map or not
	if (m.find(i) != m.end()) {
		return m[i];
	}

	// If there are no elements, no jumps can be made
	// If there is a single element, only one jump can be made
	else if (n <= 1) {
		m[n] = n;
		return n;
	}

	// If we can reach the end from current position, we only
	// need one jump
	else if (i + arr[i] >= n - 1) {
		m[i] = 1;
		return 1;
	}

	// Find all possible positions from which we can perform the next jump,
	// and return the minimum one
	else {
		int minJumps = INT_MAX;
		for (int j = 1; j <= arr[i]; j++) {
			minJumps = std::min(minJumps, minNumberJumps(arr, n, i + j, m));
		}
		m[i] = 1 + minJumps;
		return 1 + minJumps;
	}
}

/**
* Wrapper function that computes minimum number of jumps required to reach the 
* end of the array
* @params {array} arr - Array of integers where each element represents
* the max number of steps that can be made forward from that element
* @params {int} n - Number of elements in array
* @return {int} Minimum number of jumps required to reach the end of the array
*/
int minNumberJumpsWrapper(int* arr, int n) {

	// First create a map to store the values that are reused in recursion
	std::map<int, int> m;

	// Start counting minimum number of steps from first element
	return minNumberJumps(arr, n, 0, m);
}

/**
* Starting point of the program
*/
int main() {

	int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
	int n = sizeof(arr) / sizeof(arr[0]);
	assert(minNumberJumpsWrapper(arr, n) == 3);

	int arr2[] = {1, 3, 6, 1, 0, 9};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	assert(minNumberJumpsWrapper(arr2, n2) == 3);
}