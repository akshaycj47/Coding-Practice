#include <cassert>

/**
* Merge function of the merge sort process
* @params {array} arr - Given array
* @params {array} l - Left array
* @params {int} lSize - Number of elements in left array
* @params {array} r - Right array
* @params {int} rSize - Number of elements in right array
* @return {int} Number of inversions in merge procedure
*/
int sortedMerge(int* arr, int* l, int lSize, int* r, int rSize) {

	int i = 0;
	int j = 0;
	int k = 0;
	int count = 0;

	while (i < lSize && j < rSize) {
		if (l[i] <= r[j]) {
			arr[k++] = l[i++];
		}
		else if (l[i] > r[j]) {
			arr[k++] = r[j++];
			count += lSize - i;
		}
	}
	while (i < lSize) {
		arr[k++] = l[i++];
	}
	while (j < rSize) {
		arr[k++] = r[j++];
	}

	return count;
}

/**
* Function which perfoms merge sort on a given array. Number of 
* inversions in a given array is the sum of number of inversions in 
* left subarray, number of inversions in right subarray, and the 
* number of inversions in the merge process
* @params {array} arr - Given array
* @params {int} n - Number of elements in array
* @return {int} Number of inversions in given array
*/
int mergeSort(int* arr, int n) {

	if (n < 2) {
		return 0;
	}
	int mid = n / 2;
	int* l = new int[mid];
	int* r = new int[n - mid];

	for (int i = 0; i < mid; i++) {
		l[i] = arr[i];
	}
	for (int i = mid; i < n; i++) {
		r[i - mid] = arr[i];
	}
	int lCount = mergeSort(l, mid);
	int rCount = mergeSort(r, n - mid);
	int mergeCount = sortedMerge(arr, l, mid, r, n - mid);

	return lCount + rCount + mergeCount;
}

/**
* Function which counts number of inversions in an array (how far
* or how close the array is from being sorted). If an array is already
* sorted, inversion count is 0. If an array is sorted in reverse order,
* that inversion count is maximum
* @params {array} arr - Given array
* @params {int} n - Number of elements in array
* @return {int} Number of inversions in given array
*/
int countInversions(int* arr, int n) {

	int count = mergeSort(arr, n);
	return count;
}

/**
* Starting point of the program
*/
int main() {

	int arr[] = { 2, 4, 1, 3, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	assert(countInversions(arr, n) == 3);

	int arr2[] = { 1, 20, 6, 4, 5 };
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	assert(countInversions(arr2, n2) == 5);
}