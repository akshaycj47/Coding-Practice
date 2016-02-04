// Array rotation
// http://www.geeksforgeeks.org/program-for-array-rotation-continued-reversal-algorithm/

#include <iostream>
using namespace std;

void reverseArray(int* arr, int lo, int hi) {
	while(lo < hi) {
		int temp = arr[lo];
		arr[lo] = arr[hi];
		arr[hi] = temp;
		lo++;
		hi--;
	}
}

void arrayRotation(int* arr, int n, int d) {
	reverseArray(arr, 0, d - 1);
	reverseArray(arr, d, n - 1);
	reverseArray(arr, 0, n - 1);

	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int arr[] = {1, 2, 3, 4, 5, 6, 7};
	int n = sizeof(arr) / sizeof(arr[0]);
	int d = 2;
	arrayRotation(arr, n, d);
}