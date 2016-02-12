// Segregate even and odd numbers
// http://www.geeksforgeeks.org/segregate-even-and-odd-numbers/

#include <iostream>
using namespace std;

/**
 * Function to segregate even and odd numbers in an array
 * @params arr {array} Array for which we have to segregate even and odd numbers
 * @params n {int} Size of the array
 */
void segregateEvenOdd(int* arr, int n) {
	// Perform segregation
	int l = 0;
	int r = n - 1;

	while(l < r) {
		while(arr[l] % 2 == 0 && l < r) {
			l++;
		}
		while(arr[r] % 2 != 0 && l < r) {
			r--;
		}
		if(l < r) {
			int temp = arr[l];
			arr[l] = arr[r];
			arr[r] = temp;
		}
	}

	// Print the segregated array
	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

/**
 * Starting point of the program
 */
int main() {
	int arr[] = {12, 34, 45, 9, 8, 90, 3};
	int n = sizeof(arr) / sizeof(arr[0]);
	segregateEvenOdd(arr, n);

	int arr2[] = {1, 53, 79, 12, 41, 64, 24, 63, 91};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	segregateEvenOdd(arr2, n2);
}