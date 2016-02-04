// Count the number of occurrences in a sorted array
// http://www.geeksforgeeks.org/count-number-of-occurrences-in-a-sorted-array/

#include <iostream>
using namespace std;

int startIndex(int* arr, int n, int search) {
	int lo = 0;
	int hi = n - 1;

	int result = -1;
	while(lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if(arr[mid] == search) {
			result = mid;
			hi = mid - 1;
		}		
		else if(arr[mid] < search) {
			lo = mid + 1;
		}
		else if(arr[mid] > search) {
			hi = mid - 1;
		}
	}
	return result;
}

int endIndex(int* arr, int n, int search) {
	int lo = 0;
	int hi = n - 1;

	int result = -1;
	while(lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if(arr[mid] == search) {
			result = mid;
			lo = mid + 1;
		}		
		else if(arr[mid] < search) {
			lo = mid + 1;
		}
		else if(arr[mid] > search) {
			hi = mid - 1;
		}
	}
	return result;
}

int countNumOccurrences(int* arr, int n, int search) {
	int start = startIndex(arr, n, search);
	int end = endIndex(arr, n, search);

	if(start == -1 || end == -1) {
		cout << "Element not found" << endl;
		return -1;
	}

	return end - start + 1;
}

int main() {
	int arr[] = {1, 1, 2, 2, 2, 2, 3};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << countNumOccurrences(arr, n, 2) << endl;
}