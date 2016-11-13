// Maximum of all subarrays of size k
// http://www.geeksforgeeks.org/maximum-of-all-subarrays-of-size-k/

#include <iostream>
#include <deque>
using namespace std;

/**
 * Function which prints maximum value in subarrays of size 'k'
 * We are using double ended queue (deque) in this function
 * @params arr {array} Input array 
 * @params n {int} Size of the array
 */
void maxSubarraySizeK(int* arr, int n, int k) {
	// Create a deque of maximum size k
	deque<int> d(k);

	// For the initial 'k' elements
	for(int i = 0; i < k; i++) {
		while(!d.empty() && arr[d.back()] < arr[i]) {
			d.pop_back();
		}
		d.push_back(i);
	}

	// For the remaining 'n - k' elements
	for(int i = k; i < n; i++) {
		cout << arr[d.front()] << " ";

		while(!d.empty() && d.front() <= i - k) {
			d.pop_front();
		}
		while(!d.empty() && arr[d.back()] < arr[i]) {
			d.pop_back();
		}
		d.push_back(i);
	}

	// Print the maximum element of the last window
	cout << arr[d.front()] << endl;
}

/**
 * Starting point of the program
 */
int main() {
	int arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6};
	int n = sizeof(arr) / sizeof(arr[0]);
	maxSubarraySizeK(arr, n, 3);
}