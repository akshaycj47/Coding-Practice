#include <algorithm>
#include <climits>
#include <cassert>

/**
* Function that computes minimum number of jumps required to reach the 
* end of the array
* @params {array} arr - Array of integers where each element represents
* the max number of steps that can be made forward from that element
* @params {int} n - Number of elements in array
* @return {int} Minimum number of jumps required to reach the end of the array
*/
int minNumberJumps(int* arr, int n) {

	// Create an array to store the result of Dynamic Programming
	int* L = new int[n];

	// We need 0 jumps if we are on the last element of array
	L[n - 1] = 0;

	// Start computing using Dynamic Programming
	for (int i = n - 2; i >= 0; i--) {

		// If we can reach the end of array from this position,
		// we only need one jump
		if (i + arr[i] >= n - 1) {
			L[i] = 1;
		}

		// If we cannot jump from this position
		else if (arr[i] == 0) {
			L[i] = INT_MAX;
		}

		// Otherwise, we find all jump combinations from current position,
		// and choose the one with minimum cost
		else {
			int minJumps = INT_MAX;
			for (int j = 1; j <= arr[i]; j++) {

				// Add an extra check to see if the position is jumpable
				if (L[i + j] != INT_MAX) {
					minJumps = std::min(minJumps, 1 + L[i + j]);
				}
			}
			L[i] = minJumps;
		}
	}

	return L[0];
}

/**
* Starting point of the program
*/
int main() {

	int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
	int n = sizeof(arr) / sizeof(arr[0]);
	assert(minNumberJumps(arr, n) == 3);

	int arr2[] = {1, 3, 6, 1, 0, 9};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	assert(minNumberJumps(arr2, n2) == 3);
}