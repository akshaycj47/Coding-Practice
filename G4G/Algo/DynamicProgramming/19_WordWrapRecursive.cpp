#include <cassert>
#include <climits>
#include <cmath>

/**
* Function that finds the minimum cost for word wrapping
* @params {array} arr - Lengths of individual words
* @params {int} n - Number of words
* @params {int} i - Index from which want to calculate min word wrap cost
* @return {int} Minimum cost of word wrapping
*/
int wordWrap(int* arr, int n, int i, int w) {

	if (i >= n) {
		return 0;
	}
	int min = INT_MAX;
	int len = 0;
	while (len + arr[i] <= w && i < n) {
		len += arr[i];
		int cost = pow(w - len, 3) + wordWrap(arr, n, i + 1, w);
		if (min > cost) {
			min = cost;
		}
		i++;
		len++;
	}
	return min;
}

/**
* Starting point of the program
*/
int main() {

	int arr[] = { 5, 3, 5, 8, 4, 4, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);
	assert(wordWrap(arr, n, 0, 15) == 35);

	int arr2[] = { 3, 2, 2, 5 };
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	assert(wordWrap(arr2, n2, 0, 6) == 29);

	int arr3[] = { 5, 3, 5, 8, 4, 4, 7, 8, 9, 2, 3, 4, 5 };
	int n3 = sizeof(arr3) / sizeof(arr3[0]);
	assert(wordWrap(arr3, n3, 0, 16) == 676);
}