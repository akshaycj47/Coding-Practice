#include <cassert>
#include <iostream>

int sortedMerge(int* arr, int* left, int* right, int lo, int hi, int mid) {

	int count = 0;
	int i = lo;
	int j = mid;
	int k = lo;
	while (i < mid && j <= hi) {

		if (left[i] <= right[j - mid]) {
			arr[k] = left[i];
			i++;
		}
		else if (left[i] > right[j - mid]) {
			arr[k] = right[j - mid];
			j++;
			count += mid - i;
		}
		k++;
	}
	
	while (i < mid) {
		arr[k] = left[i];
		i++;
		k++;
	}
	while (j <= hi) {
		arr[k] = right[j - mid];
		j++;
		k++;
	}

	return count;
}

int mergeSort(int* arr, int lo, int hi) {

	if (lo == hi) {
		return 0;
	}
	int mid = lo + (hi - lo) / 2 + 1;

	int* left = new int[mid];
	int* right = new int[hi - mid + 1];

	for (int i = lo; i < mid; i++) {
		left[i] = arr[i];
	}
	for (int i = mid; i <= hi; i++) {
		right[i - mid] = arr[i];
	}

	int leftCount = mergeSort(left, lo, mid - 1);
	int rightCount = mergeSort(right, mid, hi);
	int mergeCount = sortedMerge(arr, left, right, lo, hi, mid);

	return leftCount + rightCount + mergeCount;
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

	int count = mergeSort(arr, 0, n - 1);
	return count;
}

/**
* Starting point of the program
*/
int main() {

	int arr[] = { 2, 4, 1, 3, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	std::cout << countInversions(arr, n) << std::endl;
	//assert(countInversions(arr, n) == 3);

	int arr2[] = { 1, 20, 6, 4, 5 };
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	std::cout << countInversions(arr2, n2) << std::endl;
	//assert(countInversions(arr2, n2) == 5);
}