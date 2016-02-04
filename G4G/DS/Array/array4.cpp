// Program to find the smallest and second smallest element in the array
// http://www.geeksforgeeks.org/to-find-smallest-and-second-smallest-element-in-an-array/

#include <iostream>
#include <climits>
using namespace std;

void smallestSecondSmallest(int* arr, int n) {
	int first = INT_MAX;
	int second = INT_MAX;

	for(int i = 0; i < n; i++) {
		if(arr[i] < first) {
			second = first;
			first = arr[i];
		}
		if(arr[i] < second && arr[i] != first) {
			second = arr[i];
		}
	}
	cout << "Smallest: " << first << endl;
	cout << "Second smallest: " << second << endl;
}

int main() {
	int arr[] = {12, 13, 1, 10, 34, 19};
	int n = sizeof(arr) / sizeof(arr[0]);
	smallestSecondSmallest(arr, n);
}