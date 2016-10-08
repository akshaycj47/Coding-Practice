#include <algorithm>
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

}

/**
* Starting point of the program
*/
int main() {

	int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
	int n = sizeof(arr) / sizeof(arr[0]);
	assert(minNumberJumps(arr, n, 0) == 3);
}