// Count the number of occurrences in a sorted array
// http://www.geeksforgeeks.org/count-number-of-occurrences-in-a-sorted-array/

#include <iostream>
using namespace std;

/**
 * Find the start index of the number in the array which occurs multiple times
 * @params arr {array} Array for which we have to find the start index
 * @params n {int} n Size of the array
 * @params search {int} Number of which we have to find the start index
 * @return index {int} Start index of the number. Returns '-1' if the number is not found
 */
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

/**
 * Find the end index of the number in the array which occurs multiple times
 * @params arr {array} Array for which we have to find the end index
 * @params n {int} n Size of the array
 * @params search {int} Number of which we have to find the end index
 * @return index {int} End index of the number. Returns '-1' if the number is not found
 */
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

/**
 * Find the number of occurences of a number in an array
 * @params arr {array} Array for which we have to find the number of occurences
 * @params n {int} n Size of the array
 * @params search {int} Number of which we have to find the number of occurences
 * @return index {int} Returns number of occurences of the number. Returns '-1' if the number is not found
 */
int countNumOccurrences(int* arr, int n, int search) {
	int start = startIndex(arr, n, search);
	int end = endIndex(arr, n, search);

	if(start == -1 || end == -1) {
		cout << "Element not found" << endl;
		return -1;
	}

	return end - start + 1;
}

/**
 * Starting point of the program
 */
int main() {
	int arr[] = {1, 1, 2, 2, 2, 2, 3};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << countNumOccurrences(arr, n, 2) << endl;
	cout << countNumOccurrences(arr, n, 3) << endl;
	cout << countNumOccurrences(arr, n, 1) << endl;
	cout << countNumOccurrences(arr, n, 4) << endl;
}