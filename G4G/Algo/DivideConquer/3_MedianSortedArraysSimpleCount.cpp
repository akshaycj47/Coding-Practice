#include <cassert>

/**
* Function which computes median of two sorted arrays
* in O(n) time complexity. This function can work even
* when number of elements in arrays are unequal
* @params {array} arr1 - First array
* @params {int} n1 - Number of elements in first array
* @params {array} arr2 - Second array
* @params {int} n2 - Number of elements in second array
* @return {int} Median of two sorted arrays
*/
int median(int* arr1, int n1, int* arr2, int n2) {

	int n = n1 + n2;
	int i = 0;				// Current index of first array
	int j = 0;				// Current index of second array
	int k = 0;				// Current index of resultant array
	int* arr3 = new int[n / 2 + 1];

	// Begin the merging process
	while (k <= n / 2) {

		if (arr1[i] <= arr2[j]) {
			arr3[k] = arr1[i];
			i++;
		}
		else if (arr1[i] > arr2[j]) {
			arr3[k] = arr2[j];
			j++;
		}
		k++;
	}

	if (n % 2 == 0) {
		return (arr3[n / 2 - 1] + arr3[n / 2]) / 2;
	}
	else {
		return arr3[n / 2];
	}
}

/**
* Starting point of the program
*/
int main() {

	int arr1[] = { 1, 12, 15, 26, 38 };
	int arr2[] = { 2, 13, 17, 30, 45 };
	int n1 = sizeof(arr1) / sizeof(arr1[0]);
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	assert(median(arr1, n1, arr2, n2) == 16);

	int arr3[] = { 1, 2, 3, 6 };
	int arr4[] = { 4, 6, 8, 10 };
	int n3 = sizeof(arr3) / sizeof(arr3[0]);
	int n4 = sizeof(arr4) / sizeof(arr4[0]);
	assert(median(arr3, n3, arr4, n4) == 5);
}