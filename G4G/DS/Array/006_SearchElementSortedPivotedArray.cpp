// Search an element in a sorted and rotated array
// http://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/

#include <iostream>
using namespace std;

/**
 * Function to find the pivot index (index from which the array is rotated)
 * @params arr {array} Array from which we have to find the pivot element
 * @params n {int} Size of the array
 * @return {int} Return the index of the pivot element. Return '-1' if pivot element is not found
 */
int findPivot(int* arr, int n) {
	int lo = 0;
	int hi = n - 1;

	while(lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if(arr[mid] < arr[mid - 1]) {
			return mid;
		}
		else if(arr[mid + 1] < arr[mid]) {
			return mid + 1;
		}
		else if(arr[mid] > arr[0]) {
			lo = mid + 1;
		}
		else {
			hi = mid - 1;
		}
	}
	return -1;
}

/**
 * Function which returns the index of the search element from the sorted and rotated array
 * @params arr {array} Array from which we have to find the index of the search element
 * @params n {int} Size of the array
 * @params search {int} Element that we have to search
 * @return index {int} Index of the search element. Return '-1' if the element is not found
 */
int sortedRotatedSearch(int* arr, int n, int search) {
	int pivot = findPivot(arr, n);
	int lo = 0;
	int hi = n - 1;

	if(arr[pivot] == search) {
		return pivot;
	}
	if(search > arr[0]) {
		hi = pivot - 1;
	}
	else {
		lo = pivot + 1;
	}

	while(lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if(arr[mid] == search) {
			return mid;
		}
		else if(arr[mid] < search) {
			lo = mid + 1;
		}
		else {
			hi = mid - 1;
		}
	}
	return -1;
}

/**
 * Starting point of the program
 */
int main() {
	int arr[] = {3, 4, 5, 1, 2};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << sortedRotatedSearch(arr, n, 4) << endl;

	int arr2[] = {3, 4, 5, 6, 7, 8, 9, 1, 2};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	cout << sortedRotatedSearch(arr2, n2, 6) << endl;

	int arr3[] = {9, 1, 2, 3, 4, 5, 6, 7, 8};
	int n3 = sizeof(arr3) / sizeof(arr3[0]);
	cout << sortedRotatedSearch(arr3, n3, 1) << endl;
	cout << sortedRotatedSearch(arr3, n3, 12) << endl;
}