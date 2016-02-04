// Sort an array of 0s, 1s, 2s
// http://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/

#include <iostream>
using namespace std;

void swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

void sort012(int* arr, int n) {
	// First sort the array in place
	int lo = 0;
	int mid = 0; 
	int hi = n - 1;

	while(mid <= hi) {
		if(arr[mid] == 0) {
			swap(&arr[lo], &arr[mid]);
			lo++;
			mid++;
		}
		else if(arr[mid] == 1) {
			mid++;
		}
		else if(arr[mid] == 2) {
			swap(&arr[mid], &arr[hi]);
			hi--;
		}
	}

	// Print the resultant array
	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int arr[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
	int n = sizeof(arr) / sizeof(arr[0]);
	sort012(arr, n);
}